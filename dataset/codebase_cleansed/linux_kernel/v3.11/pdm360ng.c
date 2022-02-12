static int pdm360ng_get_pendown_state(void)
{
u32 reg;
reg = in_be32(pdm360ng_gpio_base + 0xc);
if (reg & 0x40)
setbits32(pdm360ng_gpio_base + 0xc, 0x40);
reg = in_be32(pdm360ng_gpio_base + 0x8);
return (reg & 0x40) == 0;
}
static int __init pdm360ng_penirq_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-gpio");
if (!np) {
pr_err("%s: Can't find 'mpc5121-gpio' node\n", __func__);
return -ENODEV;
}
pdm360ng_gpio_base = of_iomap(np, 0);
of_node_put(np);
if (!pdm360ng_gpio_base) {
pr_err("%s: Can't map gpio regs.\n", __func__);
return -ENODEV;
}
out_be32(pdm360ng_gpio_base + 0xc, 0xffffffff);
setbits32(pdm360ng_gpio_base + 0x18, 0x2000);
setbits32(pdm360ng_gpio_base + 0x10, 0x40);
return 0;
}
static int pdm360ng_touchscreen_notifier_call(struct notifier_block *nb,
unsigned long event, void *__dev)
{
struct device *dev = __dev;
if ((event == BUS_NOTIFY_ADD_DEVICE) &&
of_device_is_compatible(dev->of_node, "ti,ads7846")) {
dev->platform_data = &pdm360ng_ads7846_pdata;
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static void __init pdm360ng_touchscreen_init(void)
{
if (pdm360ng_penirq_init())
return;
bus_register_notifier(&spi_bus_type, &pdm360ng_touchscreen_nb);
}
static inline void __init pdm360ng_touchscreen_init(void)
{
}
void __init pdm360ng_init(void)
{
mpc512x_init();
pdm360ng_touchscreen_init();
}
static int __init pdm360ng_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "ifm,pdm360ng");
}
