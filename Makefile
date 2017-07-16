.PHONY: build
build:
	(mkdir -p build; cd build && cmake .. && make)

.PHONY: up
up:
	(cd build && boot --create-bridge hello_world)
