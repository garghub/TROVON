static void __init hi3620_map_io(void)
{
debug_ll_io_init();
iotable_init(hi3620_io_desc, ARRAY_SIZE(hi3620_io_desc));
}
static void hi3xxx_restart(enum reboot_mode mode, const char *cmd)
{
struct device_node *np;
void __iomem *base;
int offset;
np = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
if (!np) {
pr_err("failed to find hisilicon,sysctrl node\n");
return;
}
base = of_iomap(np, 0);
if (!base) {
pr_err("failed to map address in hisilicon,sysctrl node\n");
return;
}
if (of_property_read_u32(np, "reboot-offset", &offset) < 0) {
pr_err("failed to find reboot-offset property\n");
return;
}
writel_relaxed(0xdeadbeef, base + offset);
while (1)
cpu_do_idle();
}
