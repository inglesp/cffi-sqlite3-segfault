from test_plugin import ffi, lib

@ffi.def_extern()
def rot13(ctx, argc, argv):
    print('Hello from Python!')
    print(dir(lib))
    print(lib.sqlite3_api)
    print(lib.sqlite3_api.value_type)  # This segfaults
