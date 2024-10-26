# Build your own Lisp and Learn C

## Testing the Compiler

```shell
cc --version
```

## Clone with submodules

```
git clone --recurse-submodules <repo-url>
```

## Compiling

```shell
make build file=REPL.c
```

## Compile and Run

```
make run
```

## Debugger

- The `gdb` tool is useful to debug C programs, albeit complicated.
- On OSX can use `lldb` to debug C programs, part of the XCode command line tools.
- On Linux `valgrind` is available, not as complicated as other tools.

