void ERR_load_UI_strings(void)
{
#ifndef OPENSSL_NO_ERR
if (ERR_func_error_string(UI_str_functs[0].error) == NULL) {
ERR_load_strings(0, UI_str_functs);
ERR_load_strings(0, UI_str_reasons);
}
#endif
}
