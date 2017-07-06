cmake_minimum_required(VERSION 2.8.9)

if (NOT DEFINED ENV{INCLUDEOS_PREFIX})
  set(ENV{INCLUDEOS_PREFIX} /usr/local)
endif()
include($ENV{INCLUDEOS_PREFIX}/includeos/pre.service.cmake)

project(demo_service)

set(SERVICE_NAME "hello world example")

set(BINARY_NAME "hello_world")

set(SOURCE
  service.cpp
  )

set(DRIVERS
  # silent_start
  # virtionet
  )

set(PLUGINS
  )

include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)
