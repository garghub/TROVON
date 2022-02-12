static void __init da850_init_machine(void)
{
of_platform_default_populate(NULL, da850_auxdata_lookup, NULL);
}
