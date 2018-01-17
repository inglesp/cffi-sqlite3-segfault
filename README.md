This repo contains code to reproduce a segfault in CFFI, described in [issue 356](https://bitbucket.org/cffi/cffi/issues/356/).

To reproduce, run the following in a virtualenv.

```
$ pip install cffi
$ python build.py
$ export PYTHONPATH=/path/to/site-packages
$ ./sqlite3
sqlite> .load test_plugin
Hello from C!
pApi 0x1098bf880
pApi->value_type 0x1098049c0
sqlite> select rot13("hi");
Hello from Python!
['rot13', 'sqlite3_api']
<cdata 'struct sqlite3_api_routines *' 0x1098bf880>
Segmentation fault: 11 (core dumped)
```

You may need to build `sqlite3` yourself.  In particular, on OSX, it is built with `SQLITE_OMIT_LOAD_EXTENSION` by default.
