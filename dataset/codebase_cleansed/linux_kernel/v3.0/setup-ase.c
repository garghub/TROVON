void __init ltq_soc_setup(void)
{
ltq_register_ase_asc();
ltq_register_gpio();
ltq_register_wdt();
}
