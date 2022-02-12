static void bcm21664_restart(enum reboot_mode mode, const char *cmd)
{
void __iomem *base;
struct device_node *resetmgr;
resetmgr = of_find_compatible_node(NULL, NULL, RSTMGR_DT_STRING);
if (!resetmgr) {
pr_emerg("Couldn't find " RSTMGR_DT_STRING "\n");
return;
}
base = of_iomap(resetmgr, 0);
if (!base) {
pr_emerg("Couldn't map " RSTMGR_DT_STRING "\n");
return;
}
writel((RSTMGR_WR_PASSWORD << RSTMGR_WR_PASSWORD_SHIFT) |
RSTMGR_WR_ACCESS_ENABLE,
base + RSTMGR_REG_WR_ACCESS_OFFSET);
writel(0, base + RSTMGR_REG_CHIP_SOFT_RST_OFFSET);
while (1);
}
static void __init bcm21664_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL,
&platform_bus);
kona_l2_cache_init();
}
