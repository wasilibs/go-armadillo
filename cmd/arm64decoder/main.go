package main

import (
	"os"

	"github.com/wasilibs/go-armadillo/internal/runner"
	"github.com/wasilibs/go-armadillo/internal/wasm"
)

func main() {
	os.Exit(runner.Run("arm64decoder", os.Args[1:], wasm.Decoder, os.Stdin, os.Stdout, os.Stderr, "."))
}
