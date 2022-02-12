static void ERR_load_ZENCOD_strings(void)
{
if (ZENCOD_lib_error_code == 0)
ZENCOD_lib_error_code = ERR_get_next_error_library();
if (ZENCOD_error_init) {
ZENCOD_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(ZENCOD_lib_error_code, ZENCOD_str_functs);
ERR_load_strings(ZENCOD_lib_error_code, ZENCOD_str_reasons);
#endif
#ifdef ZENCOD_LIB_NAME
ZENCOD_lib_name->error = ERR_PACK(ZENCOD_lib_error_code, 0, 0);
ERR_load_strings(0, ZENCOD_lib_name);
#endif
}
}
static void ERR_unload_ZENCOD_strings(void)
{
if (ZENCOD_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(ZENCOD_lib_error_code, ZENCOD_str_functs);
ERR_unload_strings(ZENCOD_lib_error_code, ZENCOD_str_reasons);
#endif
#ifdef ZENCOD_LIB_NAME
ERR_unload_strings(0, ZENCOD_lib_name);
#endif
ZENCOD_error_init = 1;
}
}
static void ERR_ZENCOD_error(int function, int reason, char *file, int line)
{
if (ZENCOD_lib_error_code == 0)
ZENCOD_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(ZENCOD_lib_error_code, function, reason, file, line);
}
