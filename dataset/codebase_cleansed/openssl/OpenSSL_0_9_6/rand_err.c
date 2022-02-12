void ERR_load_RAND_strings(void)
{
static int init=1;
if (init)
{
init=0;
#ifndef NO_ERR
ERR_load_strings(ERR_LIB_RAND,RAND_str_functs);
ERR_load_strings(ERR_LIB_RAND,RAND_str_reasons);
#endif
}
}
