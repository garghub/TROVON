static void __init highbank_scu_map_io(void)
{
unsigned long base;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
scu_base_addr = ioremap(base, SZ_4K);
}
static void highbank_l2c310_write_sec(unsigned long val, unsigned reg)
{
if (reg == L2X0_CTRL)
highbank_smc1(0x102, val);
else
WARN_ONCE(1, "Highbank L2C310: ignoring write to reg 0x%x\n",
reg);
}
static void __init highbank_init_irq(void)
{
irqchip_init();
if (of_find_compatible_node(NULL, NULL, "arm,cortex-a9"))
highbank_scu_map_io();
}
static void highbank_power_off(void)
{
highbank_set_pwr_shutdown();
while (1)
cpu_do_idle();
}
static int highbank_platform_notifier(struct notifier_block *nb,
unsigned long event, void *__dev)
{
struct resource *res;
int reg = -1;
u32 val;
struct device *dev = __dev;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
if (of_device_is_compatible(dev->of_node, "calxeda,hb-ahci"))
reg = 0xc;
else if (of_device_is_compatible(dev->of_node, "calxeda,hb-sdhci"))
reg = 0x18;
else if (of_device_is_compatible(dev->of_node, "arm,pl330"))
reg = 0x20;
else if (of_device_is_compatible(dev->of_node, "calxeda,hb-xgmac")) {
res = platform_get_resource(to_platform_device(dev),
IORESOURCE_MEM, 0);
if (res) {
if (res->start == 0xfff50000)
reg = 0;
else if (res->start == 0xfff51000)
reg = 4;
}
}
if (reg < 0)
return NOTIFY_DONE;
if (of_property_read_bool(dev->of_node, "dma-coherent")) {
val = readl(sregs_base + reg);
writel(val | 0xff01, sregs_base + reg);
set_dma_ops(dev, &arm_coherent_dma_ops);
}
return NOTIFY_OK;
}
static int hb_keys_notifier(struct notifier_block *nb, unsigned long event, void *data)
{
u32 key = *(u32 *)data;
if (event != 0x1000)
return 0;
if (key == KEY_POWER)
orderly_poweroff(false);
else if (key == 0xffff)
ctrl_alt_del();
return 0;
}
static void __init highbank_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "calxeda,hb-sregs");
sregs_base = of_iomap(np, 0);
WARN_ON(!sregs_base);
pm_power_off = highbank_power_off;
highbank_pm_init();
bus_register_notifier(&platform_bus_type, &highbank_platform_nb);
bus_register_notifier(&amba_bustype, &highbank_amba_nb);
pl320_ipc_register_notifier(&hb_keys_nb);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
if (psci_ops.cpu_suspend)
platform_device_register(&highbank_cpuidle_device);
}
