int ERR_load_DSA_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(DSA_str_functs[0].error) == NULL) {
ERR_load_strings(0, DSA_str_functs);
ERR_load_strings(0, DSA_str_reasons);
}
#endif
return 1;
}
