static int hisi_restart_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
writel_relaxed(0xdeadbeef, base + reboot_offset);
while (1)
cpu_do_idle();
return NOTIFY_DONE;
}
static int hisi_reboot_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int err;
base = of_iomap(np, 0);
if (!base) {
WARN(1, "failed to map base address");
return -ENODEV;
}
if (of_property_read_u32(np, "reboot-offset", &reboot_offset) < 0) {
pr_err("failed to find reboot-offset property\n");
return -EINVAL;
}
err = register_restart_handler(&hisi_restart_nb);
if (err)
dev_err(&pdev->dev, "cannot register restart handler (err=%d)\n",
err);
return err;
}
