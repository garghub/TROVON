void ERR_load_ENGINE_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(ENGINE_str_functs[0].error) == NULL)
{
ERR_load_strings(0,ENGINE_str_functs);
ERR_load_strings(0,ENGINE_str_reasons);
}
#endif
}
