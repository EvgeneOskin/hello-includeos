# Hello IncludeOS

This project is a `hello world`-like Project for 
[IncludeOS](https://github.com/hioa-cs/IncludeOS/).

## Features 

This project provides the next features:

- Hello world message;

  ```bash
  $ curl 10.0.0.45
  # Hello world
  ```

- Welcome message.

  ```bash
  $ curl 10.0.0.45/welcome/Johnny/
  # {"name":"Johnny","title":"Welcome Johnny"}
  ```

## Components

This project contains the next components:

- REST service `service.cpp`;
- Person Model `models.hpp`.

## Installation

To build this project I use 
[IncludeOS](https://github.com/hioa-cs/IncludeOS/) and
[CMake](https://cmake.org/). 

To run this project I use
[IncludeOS](https://github.com/hioa-cs/IncludeOS/) and 
[Qemu](http://www.qemu.org/).

Make sure you install all this requirements before running the next commands.

```bash
$ make build
# Compile the project
$ make up
# Run the project in Qemu and create a bridge for VM.
# ...
# Service IP address: 10.0.0.45
# [ HTTP Server ] Listening on port 80
#      [ DHCPv4 ] Negotiation timed out (eth0)
$ curl 10.0.0.45
# Hello world
$ curl 10.0.0.45/welcome/Johnny/
# {"name":"Johnny","title":"Welcome Johnny"}
```
