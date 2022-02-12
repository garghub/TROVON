static void ERR_load_GMP_strings(void)
{
if (GMP_lib_error_code == 0)
GMP_lib_error_code = ERR_get_next_error_library();
if (GMP_error_init) {
GMP_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(GMP_lib_error_code, GMP_str_functs);
ERR_load_strings(GMP_lib_error_code, GMP_str_reasons);
#endif
#ifdef GMP_LIB_NAME
GMP_lib_name->error = ERR_PACK(GMP_lib_error_code, 0, 0);
ERR_load_strings(0, GMP_lib_name);
#endif
}
}
static void ERR_unload_GMP_strings(void)
{
if (GMP_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(GMP_lib_error_code, GMP_str_functs);
ERR_unload_strings(GMP_lib_error_code, GMP_str_reasons);
#endif
#ifdef GMP_LIB_NAME
ERR_unload_strings(0, GMP_lib_name);
#endif
GMP_error_init = 1;
}
}
static void ERR_GMP_error(int function, int reason, char *file, int line)
{
if (GMP_lib_error_code == 0)
GMP_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(GMP_lib_error_code, function, reason, file, line);
}
