static void hisi_restart(enum reboot_mode mode, const char *cmd)
{
writel_relaxed(0xdeadbeef, base + reboot_offset);
while (1)
cpu_do_idle();
}
static int hisi_reboot_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
base = of_iomap(np, 0);
if (!base) {
WARN(1, "failed to map base address");
return -ENODEV;
}
if (of_property_read_u32(np, "reboot-offset", &reboot_offset) < 0) {
pr_err("failed to find reboot-offset property\n");
return -EINVAL;
}
arm_pm_restart = hisi_restart;
return 0;
}
