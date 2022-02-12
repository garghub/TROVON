static int fips_enable(char *str)
{
fips_enabled = !!simple_strtol(str, NULL, 0);
printk(KERN_INFO "fips mode: %s\n",
fips_enabled ? "enabled" : "disabled");
return 1;
}
