void ERR_load_OCSP_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(OCSP_str_functs[0].error) == NULL)
{
ERR_load_strings(0,OCSP_str_functs);
ERR_load_strings(0,OCSP_str_reasons);
}
#endif
}
