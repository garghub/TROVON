static int __init cpi_module_init(void)
{
return sclp_cpi_set_data(system_name, sysplex_name, "LINUX",
LINUX_VERSION_CODE);
}
static void __exit cpi_module_exit(void)
{
}
