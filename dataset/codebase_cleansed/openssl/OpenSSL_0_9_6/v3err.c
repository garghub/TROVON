void ERR_load_X509V3_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef NO_ERR
ERR_load_strings(ERR_LIB_X509V3,X509V3_str_functs);
ERR_load_strings(ERR_LIB_X509V3,X509V3_str_reasons);
#endif
}
}
