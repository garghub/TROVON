void ERR_load_X509_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(X509_str_functs[0].error) == NULL)
{
ERR_load_strings(0,X509_str_functs);
ERR_load_strings(0,X509_str_reasons);
}
#endif
}
