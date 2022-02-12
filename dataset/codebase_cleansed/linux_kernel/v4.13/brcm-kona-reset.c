static int kona_reset_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
writel((RSTMGR_WR_PASSWORD << RSTMGR_WR_PASSWORD_SHIFT) |
RSTMGR_WR_ACCESS_ENABLE,
kona_reset_base + RSTMGR_REG_WR_ACCESS_OFFSET);
writel(0, kona_reset_base + RSTMGR_REG_CHIP_SOFT_RST_OFFSET);
return NOTIFY_DONE;
}
static int kona_reset_probe(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
kona_reset_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(kona_reset_base))
return PTR_ERR(kona_reset_base);
return register_restart_handler(&kona_reset_nb);
}
