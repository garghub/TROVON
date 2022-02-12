static void xgene_restart(enum reboot_mode mode, const char *cmd)
{
struct xgene_reboot_context *ctx = xgene_restart_ctx;
unsigned long timeout;
if (ctx)
writel(ctx->mask, ctx->csr);
timeout = jiffies + HZ;
while (time_before(jiffies, timeout))
cpu_relax();
dev_emerg(&ctx->pdev->dev, "Unable to restart system\n");
}
static int xgene_reboot_probe(struct platform_device *pdev)
{
struct xgene_reboot_context *ctx;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
dev_err(&pdev->dev, "out of memory for context\n");
return -ENODEV;
}
ctx->csr = of_iomap(pdev->dev.of_node, 0);
if (!ctx->csr) {
devm_kfree(&pdev->dev, ctx);
dev_err(&pdev->dev, "can not map resource\n");
return -ENODEV;
}
if (of_property_read_u32(pdev->dev.of_node, "mask", &ctx->mask))
ctx->mask = 0xFFFFFFFF;
ctx->pdev = pdev;
arm_pm_restart = xgene_restart;
xgene_restart_ctx = ctx;
return 0;
}
static int __init xgene_reboot_init(void)
{
return platform_driver_register(&xgene_reboot_driver);
}
