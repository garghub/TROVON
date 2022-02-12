static int __init sh7785lcr_devices_setup(void)
{
i2c_register_board_info(0, sh7785lcr_i2c_devices,
ARRAY_SIZE(sh7785lcr_i2c_devices));
if (mach_is_sh7785lcr_pt()) {
i2c_device.resource = i2c_proto_resources;
i2c_device.num_resources = ARRAY_SIZE(i2c_proto_resources);
}
return platform_add_devices(sh7785lcr_devices,
ARRAY_SIZE(sh7785lcr_devices));
}
void __init init_sh7785lcr_IRQ(void)
{
plat_irq_setup_pins(IRQ_MODE_IRQ7654);
plat_irq_setup_pins(IRQ_MODE_IRQ3210);
}
static int sh7785lcr_clk_init(void)
{
struct clk *clk;
int ret;
clk = clk_get(NULL, "extal");
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_set_rate(clk, 33333333);
clk_put(clk);
return ret;
}
static void sh7785lcr_power_off(void)
{
unsigned char *p;
p = ioremap(PLD_POFCR, PLD_POFCR + 1);
if (!p) {
printk(KERN_ERR "%s: ioremap error.\n", __func__);
return;
}
*p = 0x01;
iounmap(p);
set_bl_bit();
while (1)
cpu_relax();
}
static void __init sh7785lcr_setup(char **cmdline_p)
{
void __iomem *sm501_reg;
printk(KERN_INFO "Renesas Technology Corp. R0P7785LC0011RL support.\n");
pm_power_off = sh7785lcr_power_off;
sm501_reg = ioremap_nocache(SM107_REG_ADDR, SM501_DRAM_CONTROL);
if (!sm501_reg) {
printk(KERN_ERR "%s: ioremap error.\n", __func__);
return;
}
writel(0x000307c2, sm501_reg + SM501_DRAM_CONTROL);
iounmap(sm501_reg);
}
static int sh7785lcr_mode_pins(void)
{
int value = 0;
value |= MODE_PIN4;
value |= MODE_PIN5;
value |= MODE_PIN6;
value |= MODE_PIN7;
value |= MODE_PIN8;
value |= MODE_PIN9;
value |= MODE_PIN14;
return value;
}
