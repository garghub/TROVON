static int zx_restart_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
writel_relaxed(1, base + 0xb0);
writel_relaxed(1, pcu_base + 0x34);
mdelay(50);
pr_emerg("Unable to restart system\n");
return NOTIFY_DONE;
}
static int zx_reboot_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int err;
base = of_iomap(np, 0);
if (!base) {
WARN(1, "failed to map base address");
return -ENODEV;
}
np = of_find_compatible_node(NULL, NULL, "zte,zx296702-pcu");
pcu_base = of_iomap(np, 0);
if (!pcu_base) {
iounmap(base);
WARN(1, "failed to map pcu_base address");
return -ENODEV;
}
err = register_restart_handler(&zx_restart_nb);
if (err)
dev_err(&pdev->dev, "Register restart handler failed(err=%d)\n",
err);
return err;
}
