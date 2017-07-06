#include <os>
#include <mana/server.hpp>
#include <net/inet4>
#include <syslog.h>

extern "C" int main();

std::unique_ptr<mana::Server> server;

void Service::start(const std::string&) {

  auto& inet = net::Inet4::ifconfig(10.0);

  net::Inet4::ifconfig({10, 0, 0, 45},
                       {255, 255, 0, 0},
                       {10, 0, 0, 1},
                       {10, 0, 0, 1});

  printf("Service IP address: %s\n", inet.ip_addr().str().c_str());

  syslog(LOG_ERR, "(Err) test log entry");

  mana::Router router;
  router.on_get("/", [] (auto, auto res) {
      res->source().add_body("Hello world");
      res->send();
    });
  server = std::make_unique<mana::Server>(inet.tcp());
  server->set_routes(router).listen(80);
}
