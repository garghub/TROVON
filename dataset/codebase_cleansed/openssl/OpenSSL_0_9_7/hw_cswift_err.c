static void ERR_load_CSWIFT_strings(void)
{
if (CSWIFT_lib_error_code == 0)
CSWIFT_lib_error_code=ERR_get_next_error_library();
if (CSWIFT_error_init)
{
CSWIFT_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(CSWIFT_lib_error_code,CSWIFT_str_functs);
ERR_load_strings(CSWIFT_lib_error_code,CSWIFT_str_reasons);
#endif
#ifdef CSWIFT_LIB_NAME
CSWIFT_lib_name->error = ERR_PACK(CSWIFT_lib_error_code,0,0);
ERR_load_strings(0,CSWIFT_lib_name);
#endif
}
}
static void ERR_unload_CSWIFT_strings(void)
{
if (CSWIFT_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(CSWIFT_lib_error_code,CSWIFT_str_functs);
ERR_unload_strings(CSWIFT_lib_error_code,CSWIFT_str_reasons);
#endif
#ifdef CSWIFT_LIB_NAME
ERR_unload_strings(0,CSWIFT_lib_name);
#endif
CSWIFT_error_init=1;
}
}
static void ERR_CSWIFT_error(int function, int reason, char *file, int line)
{
if (CSWIFT_lib_error_code == 0)
CSWIFT_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(CSWIFT_lib_error_code,function,reason,file,line);
}
