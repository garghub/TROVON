void ERR_load_ECDSA_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(ECDSA_str_functs[0].error) == NULL) {
ERR_load_strings(0, ECDSA_str_functs);
ERR_load_strings(0, ECDSA_str_reasons);
}
#endif
}
