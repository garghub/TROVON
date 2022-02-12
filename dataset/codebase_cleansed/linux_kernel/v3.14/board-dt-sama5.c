static void __init sama5_dt_timer_init(void)
{
#if defined(CONFIG_COMMON_CLK)
of_clk_init(NULL);
#endif
at91sam926x_pit_init();
}
static void __init at91_dt_init_irq(void)
{
of_irq_init(irq_of_match);
}
static int ksz9021rn_phy_fixup(struct phy_device *phy)
{
int value;
value = MICREL_KSZ9021_RGMII_CLK_CTRL_PAD_SCEW | 0x8000;
phy_write(phy, MICREL_KSZ9021_EXTREG_CTRL, value);
value = 0xF2F4;
phy_write(phy, MICREL_KSZ9021_EXTREG_DATA_WRITE, value);
value = MICREL_KSZ9021_RGMII_RX_DATA_PAD_SCEW | 0x8000;
phy_write(phy, MICREL_KSZ9021_EXTREG_CTRL, value);
value = 0x2222;
phy_write(phy, MICREL_KSZ9021_EXTREG_DATA_WRITE, value);
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
