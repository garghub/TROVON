void ERR_load_TS_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(TS_str_functs[0].error) == NULL)
{
ERR_load_strings(0,TS_str_functs);
ERR_load_strings(0,TS_str_reasons);
}
#endif
}
