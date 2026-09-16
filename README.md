# tui-portfolio
![](https://cdn.discordapp.com/attachments/692894496597344358/1549908080022524005/image.png?ex=6aac67e2&is=6aab1662&hm=233abd9f55db5d1e8c2044290352f10dd4ce59d38def9199ea98c8f8bf41c389&) 
A terminal UI portfolio, served over SSH from a self-hosted home server.

```bash
ssh elliot-tam.dev
```

---

## Self-hosted

This portfolio runs on a homebuilt server running Arch Linux, connected to the internet from my home network. Incoming SSH connections on port 22 are handled by a custom Go server built with [Wish](https://github.com/charmbracelet/wish) by Charmbracelet, which pipes the compiled C++ binary to whoever connects. Pushes to this repo automatically trigger a rebuild and restart via a GitHub webhook.

---

## Build locally

### Requirements
- C++17 compiler (g++ or clang++)
- CMake 3.15+
- [FTXUI](https://github.com/ArthurSonzogni/FTXUI)
- Git

### Clone
```bash
git clone https://github.com/Eteaisme/tui-portfolio
cd tui-portfolio
```

### Build
```bash
cmake -B build
cmake --build build
```

### Run
```bash
./build/main
```
