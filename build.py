import cffi
ffibuilder = cffi.FFI()

ffibuilder.embedding_api(open('plugin_api.h').read())
ffibuilder.embedding_init_code(open('plugin.py').read())
ffibuilder.set_source('test_plugin', open('plugin.c').read())
ffibuilder.compile(verbose=True)
