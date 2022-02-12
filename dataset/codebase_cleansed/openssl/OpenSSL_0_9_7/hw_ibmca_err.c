static void ERR_load_IBMCA_strings(void)
{
if (IBMCA_lib_error_code == 0)
IBMCA_lib_error_code=ERR_get_next_error_library();
if (IBMCA_error_init)
{
IBMCA_error_init=0;
#ifndef OPENSSL_NO_ERR
ERR_load_strings(IBMCA_lib_error_code,IBMCA_str_functs);
ERR_load_strings(IBMCA_lib_error_code,IBMCA_str_reasons);
#endif
#ifdef IBMCA_LIB_NAME
IBMCA_lib_name->error = ERR_PACK(IBMCA_lib_error_code,0,0);
ERR_load_strings(0,IBMCA_lib_name);
#endif
}
}
static void ERR_unload_IBMCA_strings(void)
{
if (IBMCA_error_init == 0)
{
#ifndef OPENSSL_NO_ERR
ERR_unload_strings(IBMCA_lib_error_code,IBMCA_str_functs);
ERR_unload_strings(IBMCA_lib_error_code,IBMCA_str_reasons);
#endif
#ifdef IBMCA_LIB_NAME
ERR_unload_strings(0,IBMCA_lib_name);
#endif
IBMCA_error_init=1;
}
}
static void ERR_IBMCA_error(int function, int reason, char *file, int line)
{
if (IBMCA_lib_error_code == 0)
IBMCA_lib_error_code=ERR_get_next_error_library();
ERR_PUT_error(IBMCA_lib_error_code,function,reason,file,line);
}
