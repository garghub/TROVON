static int xgene_restart_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
struct xgene_reboot_context *ctx =
container_of(this, struct xgene_reboot_context,
restart_handler);
writel(ctx->mask, ctx->csr);
mdelay(1000);
dev_emerg(ctx->dev, "Unable to restart system\n");
return NOTIFY_DONE;
}
static int xgene_reboot_probe(struct platform_device *pdev)
{
struct xgene_reboot_context *ctx;
struct device *dev = &pdev->dev;
int err;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->csr = of_iomap(dev->of_node, 0);
if (!ctx->csr) {
dev_err(dev, "can not map resource\n");
return -ENODEV;
}
if (of_property_read_u32(dev->of_node, "mask", &ctx->mask))
ctx->mask = 0xFFFFFFFF;
ctx->dev = dev;
ctx->restart_handler.notifier_call = xgene_restart_handler;
ctx->restart_handler.priority = 128;
err = register_restart_handler(&ctx->restart_handler);
if (err)
dev_err(dev, "cannot register restart handler (err=%d)\n", err);
return err;
}
static int __init xgene_reboot_init(void)
{
return platform_driver_register(&xgene_reboot_driver);
}
