cmake_minimum_required(VERSION 2.8.9)

if (NOT DEFINED ENV{INCLUDEOS_PREFIX})
  set(ENV{INCLUDEOS_PREFIX} /usr/local)
endif()
include($ENV{INCLUDEOS_PREFIX}/includeos/pre.service.cmake)

project(demo_service)

set(SERVICE_NAME "hello world example")

set(BINARY "hello_world")

set(SOURCES
  service.cpp
  )

set(LIBRARIES
  "libmana.a"
  )

set(DRIVERS
  # silent_start
  virtionet
  )

set(PLUGINS
  syslogd
  )

include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)
