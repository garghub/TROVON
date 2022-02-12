void __init ltq_soc_setup(void)
{
ltq_register_asc(0);
ltq_register_asc(1);
ltq_register_gpio();
ltq_register_wdt();
}
