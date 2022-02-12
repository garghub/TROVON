static void ERR_load_CAPI_strings(void)
{
if (CAPI_lib_error_code == 0)
CAPI_lib_error_code = ERR_get_next_error_library();
if (CAPI_error_init) {
CAPI_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(CAPI_lib_error_code, CAPI_str_functs);
ERR_load_strings(CAPI_lib_error_code, CAPI_str_reasons);
#endif
#ifdef CAPI_LIB_NAME
CAPI_lib_name->error = ERR_PACK(CAPI_lib_error_code, 0, 0);
ERR_load_strings(0, CAPI_lib_name);
#endif
}
}
static void ERR_unload_CAPI_strings(void)
{
if (CAPI_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(CAPI_lib_error_code, CAPI_str_functs);
ERR_unload_strings(CAPI_lib_error_code, CAPI_str_reasons);
#endif
#ifdef CAPI_LIB_NAME
ERR_unload_strings(0, CAPI_lib_name);
#endif
CAPI_error_init = 1;
}
}
static void ERR_CAPI_error(int function, int reason, char *file, int line)
{
if (CAPI_lib_error_code == 0)
CAPI_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(CAPI_lib_error_code, function, reason, file, line);
}
