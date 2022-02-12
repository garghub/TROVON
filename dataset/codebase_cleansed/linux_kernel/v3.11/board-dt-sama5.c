static void __init at91_dt_init_irq(void)
{
of_irq_init(irq_of_match);
}
static int ksz9021rn_phy_fixup(struct phy_device *phy)
{
int value;
#define GMII_RCCPSR 260
#define GMII_RRDPSR 261
#define GMII_ERCR 11
#define GMII_ERDWR 12
value = GMII_RCCPSR | 0x8000;
phy_write(phy, GMII_ERCR, value);
value = 0xF2F4;
phy_write(phy, GMII_ERDWR, value);
value = GMII_RRDPSR | 0x8000;
phy_write(phy, GMII_ERCR, value);
value = 0x2222;
phy_write(phy, GMII_ERDWR, value);
return 0;
}
static void __init sama5_dt_device_init(void)
{
if (of_machine_is_compatible("atmel,sama5d3xcm") &&
IS_ENABLED(CONFIG_PHYLIB))
phy_register_fixup_for_uid(PHY_ID_KSZ9021, MICREL_PHY_ID_MASK,
ksz9021rn_phy_fixup);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
