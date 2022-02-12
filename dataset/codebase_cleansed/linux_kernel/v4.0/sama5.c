static int ksz8081_phy_fixup(struct phy_device *phy)
{
int value;
value = phy_read(phy, 0x16);
value &= ~0x20;
phy_write(phy, 0x16, value);
return 0;
}
static void __init sama5_dt_device_init(void)
{
if (of_machine_is_compatible("atmel,sama5d4ek") &&
IS_ENABLED(CONFIG_PHYLIB)) {
phy_register_fixup_for_id("fc028000.etherne:00",
ksz8081_phy_fixup);
}
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
at91sam9x5_pm_init();
}
static void __init sama5_alt_map_io(void)
{
at91_alt_map_io();
iotable_init(at91_io_desc, ARRAY_SIZE(at91_io_desc));
}
