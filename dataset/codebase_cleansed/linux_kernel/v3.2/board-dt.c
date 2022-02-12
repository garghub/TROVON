static void __init ek_init_early(void)
{
at91_initialize(12000000);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static void __init ek_add_device_nand(void)
{
ek_nand_data.bus_width_16 = board_have_nand_16bit();
if (ek_nand_data.bus_width_16)
ek_nand_smc_config.mode |= AT91_SMC_DBW_16;
else
ek_nand_smc_config.mode |= AT91_SMC_DBW_8;
sam9_smc_configure(3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void __init at91_dt_init_irq(void)
{
irq_domain_generate_simple(aic_of_match, 0xfffff000, 0);
at91_init_irq_default();
}
static void __init at91_dt_device_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
ek_add_device_nand();
}
