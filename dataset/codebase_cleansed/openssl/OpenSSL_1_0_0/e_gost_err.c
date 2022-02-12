void ERR_load_GOST_strings(void)
{
if (GOST_lib_error_code == 0)
GOST_lib_error_code=ERR_get_next_error_library();
if (GOST_error_init)
{
GOST_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(GOST_lib_error_code,GOST_str_functs);
ERR_load_strings(GOST_lib_error_code,GOST_str_reasons);
#endif
#ifdef GOST_LIB_NAME
GOST_lib_name->error = ERR_PACK(GOST_lib_error_code,0,0);
ERR_load_strings(0,GOST_lib_name);
#endif
}
}
void ERR_unload_GOST_strings(void)
{
if (GOST_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(GOST_lib_error_code,GOST_str_functs);
ERR_unload_strings(GOST_lib_error_code,GOST_str_reasons);
#endif
#ifdef GOST_LIB_NAME
ERR_unload_strings(0,GOST_lib_name);
#endif
GOST_error_init=1;
}
}
void ERR_GOST_error(int function, int reason, char *file, int line)
{
if (GOST_lib_error_code == 0)
GOST_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(GOST_lib_error_code,function,reason,file,line);
}
