char * __init
prom_getbootargs(void)
{
if (bootstr_info.bootstr_valid)
return bootstr_info.bootstr_buf;
prom_getstring(prom_chosen_node, "bootargs",
bootstr_info.bootstr_buf, BARG_LEN);
bootstr_info.bootstr_valid = 1;
return bootstr_info.bootstr_buf;
}
