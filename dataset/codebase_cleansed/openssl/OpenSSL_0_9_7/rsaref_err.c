static void ERR_load_RSAREF_strings(void)
{
if (RSAREF_lib_error_code == 0)
RSAREF_lib_error_code=ERR_get_next_error_library();
if (RSAREF_error_init)
{
RSAREF_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(RSAREF_lib_error_code,RSAREF_str_functs);
ERR_load_strings(RSAREF_lib_error_code,RSAREF_str_reasons);
#endif
#ifdef RSAREF_LIB_NAME
RSAREF_lib_name->error = ERR_PACK(RSAREF_lib_error_code,0,0);
ERR_load_strings(0,RSAREF_lib_name);
#endif
}
}
static void ERR_unload_RSAREF_strings(void)
{
if (RSAREF_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(RSAREF_lib_error_code,RSAREF_str_functs);
ERR_unload_strings(RSAREF_lib_error_code,RSAREF_str_reasons);
#endif
#ifdef RSAREF_LIB_NAME
ERR_unload_strings(0,RSAREF_lib_name);
#endif
RSAREF_error_init=1;
}
}
static void ERR_RSAREF_error(int function, int reason, char *file, int line)
{
if (RSAREF_lib_error_code == 0)
RSAREF_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(RSAREF_lib_error_code,function,reason,file,line);
}
