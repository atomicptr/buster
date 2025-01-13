test: build
    cd build && meson test --verbose

build:
    meson setup build --reconfigure
    cd build && meson compile
