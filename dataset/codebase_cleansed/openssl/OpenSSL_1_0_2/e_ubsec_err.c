static void ERR_load_UBSEC_strings(void)
{
if (UBSEC_lib_error_code == 0)
UBSEC_lib_error_code = ERR_get_next_error_library();
if (UBSEC_error_init) {
UBSEC_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(UBSEC_lib_error_code, UBSEC_str_functs);
ERR_load_strings(UBSEC_lib_error_code, UBSEC_str_reasons);
#endif
#ifdef UBSEC_LIB_NAME
UBSEC_lib_name->error = ERR_PACK(UBSEC_lib_error_code, 0, 0);
ERR_load_strings(0, UBSEC_lib_name);
#endif
}
}
static void ERR_unload_UBSEC_strings(void)
{
if (UBSEC_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(UBSEC_lib_error_code, UBSEC_str_functs);
ERR_unload_strings(UBSEC_lib_error_code, UBSEC_str_reasons);
#endif
#ifdef UBSEC_LIB_NAME
ERR_unload_strings(0, UBSEC_lib_name);
#endif
UBSEC_error_init = 1;
}
}
static void ERR_UBSEC_error(int function, int reason, char *file, int line)
{
if (UBSEC_lib_error_code == 0)
UBSEC_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(UBSEC_lib_error_code, function, reason, file, line);
}
