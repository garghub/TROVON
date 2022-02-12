static int sirfsoc_reset_module(struct reset_controller_dev *rcdev,
unsigned long sw_reset_idx)
{
u32 reset_bit = sw_reset_idx;
if (reset_bit >= SIRFSOC_RSTBIT_NUM)
return -EINVAL;
mutex_lock(&rstc_lock);
if (of_device_is_compatible(rcdev->of_node, "sirf,prima2-rstc")) {
writel(readl(sirfsoc_rstc_base +
(reset_bit / 32) * 4) | (1 << reset_bit),
sirfsoc_rstc_base + (reset_bit / 32) * 4);
msleep(20);
writel(readl(sirfsoc_rstc_base +
(reset_bit / 32) * 4) & ~(1 << reset_bit),
sirfsoc_rstc_base + (reset_bit / 32) * 4);
} else {
writel(1 << reset_bit,
sirfsoc_rstc_base + (reset_bit / 32) * 8);
msleep(20);
writel(1 << reset_bit,
sirfsoc_rstc_base + (reset_bit / 32) * 8 + 4);
}
mutex_unlock(&rstc_lock);
return 0;
}
static void sirfsoc_restart(enum reboot_mode mode, const char *cmd)
{
writel(SIRFSOC_SYS_RST_BIT, sirfsoc_rstc_base);
}
static int sirfsoc_rstc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
sirfsoc_rstc_base = of_iomap(np, 0);
if (!sirfsoc_rstc_base) {
dev_err(&pdev->dev, "unable to map rstc cpu registers\n");
return -ENOMEM;
}
sirfsoc_reset_controller.of_node = np;
arm_pm_restart = sirfsoc_restart;
if (IS_ENABLED(CONFIG_RESET_CONTROLLER))
reset_controller_register(&sirfsoc_reset_controller);
return 0;
}
static int __init sirfsoc_rstc_init(void)
{
return platform_driver_register(&sirfsoc_rstc_driver);
}
