static int sata_miphy_init(struct device *dev, void __iomem *addr)
{
writel(SPEAR1340_SATA_CFG_VAL, SPEAR1340_PCIE_SATA_CFG);
writel(SPEAR1340_PCIE_SATA_MIPHY_CFG_SATA_25M_CRYSTAL_CLK,
SPEAR1340_PCIE_MIPHY_CFG);
writel((readl(SPEAR1340_PCM_CFG) | (0x800)), SPEAR1340_PCM_CFG);
msleep(20);
writel((readl(SPEAR1340_PERIP1_SW_RST) & (~0x1000)),
SPEAR1340_PERIP1_SW_RST);
msleep(20);
return 0;
}
void sata_miphy_exit(struct device *dev)
{
writel(0, SPEAR1340_PCIE_SATA_CFG);
writel(0, SPEAR1340_PCIE_MIPHY_CFG);
writel((readl(SPEAR1340_PERIP1_SW_RST) | (0x1000)),
SPEAR1340_PERIP1_SW_RST);
msleep(20);
writel((readl(SPEAR1340_PCM_CFG) & (~0x800)), SPEAR1340_PCM_CFG);
msleep(20);
}
int sata_suspend(struct device *dev)
{
if (dev->power.power_state.event == PM_EVENT_FREEZE)
return 0;
sata_miphy_exit(dev);
return 0;
}
int sata_resume(struct device *dev)
{
if (dev->power.power_state.event == PM_EVENT_THAW)
return 0;
return sata_miphy_init(dev, NULL);
}
static void __init spear1340_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
spear1340_auxdata_lookup, NULL);
platform_device_register_simple("spear-cpufreq", -1, NULL, 0);
}
