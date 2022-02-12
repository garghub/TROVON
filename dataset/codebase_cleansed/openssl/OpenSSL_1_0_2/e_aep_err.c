static void ERR_load_AEPHK_strings(void)
{
if (AEPHK_lib_error_code == 0)
AEPHK_lib_error_code = ERR_get_next_error_library();
if (AEPHK_error_init) {
AEPHK_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(AEPHK_lib_error_code, AEPHK_str_functs);
ERR_load_strings(AEPHK_lib_error_code, AEPHK_str_reasons);
#endif
#ifdef AEPHK_LIB_NAME
AEPHK_lib_name->error = ERR_PACK(AEPHK_lib_error_code, 0, 0);
ERR_load_strings(0, AEPHK_lib_name);
#endif
}
}
static void ERR_unload_AEPHK_strings(void)
{
if (AEPHK_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(AEPHK_lib_error_code, AEPHK_str_functs);
ERR_unload_strings(AEPHK_lib_error_code, AEPHK_str_reasons);
#endif
#ifdef AEPHK_LIB_NAME
ERR_unload_strings(0, AEPHK_lib_name);
#endif
AEPHK_error_init = 1;
}
}
static void ERR_AEPHK_error(int function, int reason, char *file, int line)
{
if (AEPHK_lib_error_code == 0)
AEPHK_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(AEPHK_lib_error_code, function, reason, file, line);
}
