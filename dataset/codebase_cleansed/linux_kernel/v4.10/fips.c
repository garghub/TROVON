static int fips_enable(char *str)
{
fips_enabled = !!simple_strtol(str, NULL, 0);
printk(KERN_INFO "fips mode: %s\n",
fips_enabled ? "enabled" : "disabled");
return 1;
}
static void crypto_proc_fips_init(void)
{
crypto_sysctls = register_sysctl_table(crypto_dir_table);
}
static void crypto_proc_fips_exit(void)
{
unregister_sysctl_table(crypto_sysctls);
}
static int __init fips_init(void)
{
crypto_proc_fips_init();
return 0;
}
static void __exit fips_exit(void)
{
crypto_proc_fips_exit();
}
