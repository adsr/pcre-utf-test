# pcre-utf-test

```
$ git submodule update --init
$ cd pcre
$ ./autogen.sh && ./configure --enable-utf --enable-unicode-properties && make
$ cd ..
$ gcc pcre-utf-test.c pcre/.libs/libpcre.a -o pcre-utf-test
$ ./pcre-utf-test
```
