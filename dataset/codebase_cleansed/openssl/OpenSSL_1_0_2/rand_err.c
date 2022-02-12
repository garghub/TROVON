void ERR_load_RAND_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(RAND_str_functs[0].error) == NULL) {
ERR_load_strings(0, RAND_str_functs);
ERR_load_strings(0, RAND_str_reasons);
}
#endif
}
