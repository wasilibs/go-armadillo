FROM ghcr.io/webassembly/wasi-sdk:wasi-sdk-21

RUN apt-get update && apt-get install -y curl 

WORKDIR /armadillo
RUN curl -L https://github.com/jsherman212/armadillo/archive/cc616ff65b5093b56d88f841b017f1406b8e9997.tar.gz | tar -xz --strip-components=1 -C /armadillo
ADD buildtools/wasm/main_decode.c .

RUN $CC $CFLAGS -O3 -o decoder.wasm main_decode.c source/*.c

CMD ["cp", "decoder.wasm", "/out/"]
