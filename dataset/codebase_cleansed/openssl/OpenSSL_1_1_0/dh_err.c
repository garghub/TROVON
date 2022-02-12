int ERR_load_DH_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(DH_str_functs[0].error) == NULL) {
ERR_load_strings(0, DH_str_functs);
ERR_load_strings(0, DH_str_reasons);
}
#endif
return 1;
}
