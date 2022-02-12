static int syscon_restart_handle(struct notifier_block *this,
unsigned long mode, void *cmd)
{
struct syscon_reboot_context *ctx =
container_of(this, struct syscon_reboot_context,
restart_handler);
regmap_write(ctx->map, ctx->offset, ctx->mask);
mdelay(1000);
pr_emerg("Unable to restart system\n");
return NOTIFY_DONE;
}
static int syscon_reboot_probe(struct platform_device *pdev)
{
struct syscon_reboot_context *ctx;
struct device *dev = &pdev->dev;
int err;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->map = syscon_regmap_lookup_by_phandle(dev->of_node, "regmap");
if (IS_ERR(ctx->map))
return PTR_ERR(ctx->map);
if (of_property_read_u32(pdev->dev.of_node, "offset", &ctx->offset))
return -EINVAL;
if (of_property_read_u32(pdev->dev.of_node, "mask", &ctx->mask))
return -EINVAL;
ctx->restart_handler.notifier_call = syscon_restart_handle;
ctx->restart_handler.priority = 128;
err = register_restart_handler(&ctx->restart_handler);
if (err)
dev_err(dev, "can't register restart notifier (err=%d)\n", err);
return err;
}
