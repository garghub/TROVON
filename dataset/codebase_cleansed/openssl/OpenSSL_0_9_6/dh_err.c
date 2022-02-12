void ERR_load_DH_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef NO_ERR
ERR_load_strings(ERR_LIB_DH,DH_str_functs);
ERR_load_strings(ERR_LIB_DH,DH_str_reasons);
#endif
}
}
