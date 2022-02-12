static void __init at91sam9_init(void)
{
of_platform_default_populate(NULL, NULL, NULL);
at91sam9_pm_init();
}
