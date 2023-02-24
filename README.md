`pthread_create()` with a valid stack size of 64k fails if
`avdevice_register_all()` is called beforehand.

Build:

```
meson setup x
ninja -Cx
```

Execute:

```
x/sample
```

On my machine:

```console
$ x/sample
Could not create thread
```

If I remove the call to `avdevice_register_all()`:

```console
$ x/sample
OK
```

Refs:
 - <https://github.com/libsdl-org/SDL/issues/7367>
 - <https://github.com/rom1v/stacksize_fail>
