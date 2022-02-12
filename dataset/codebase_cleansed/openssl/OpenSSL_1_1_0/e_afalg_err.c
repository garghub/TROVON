void ERR_load_AFALG_strings(void)
{
if (AFALG_lib_error_code == 0)
AFALG_lib_error_code = ERR_get_next_error_library();
if (AFALG_error_init) {
AFALG_error_init = 0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(AFALG_lib_error_code, AFALG_str_functs);
ERR_load_strings(AFALG_lib_error_code, AFALG_str_reasons);
#endif
#ifdef AFALG_LIB_NAME
AFALG_lib_name->error = ERR_PACK(AFALG_lib_error_code, 0, 0);
ERR_load_strings(0, AFALG_lib_name);
#endif
}
}
void ERR_unload_AFALG_strings(void)
{
if (AFALG_error_init == 0) {
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(AFALG_lib_error_code, AFALG_str_functs);
ERR_unload_strings(AFALG_lib_error_code, AFALG_str_reasons);
#endif
#ifdef AFALG_LIB_NAME
ERR_unload_strings(0, AFALG_lib_name);
#endif
AFALG_error_init = 1;
}
}
void ERR_AFALG_error(int function, int reason, char *file, int line)
{
if (AFALG_lib_error_code == 0)
AFALG_lib_error_code = ERR_get_next_error_library();
ERR_PUT_error(AFALG_lib_error_code, function, reason, file, line);
}
