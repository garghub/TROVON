static void s5p64x0_idle(void)
{
unsigned long val;
if (!need_resched()) {
val = __raw_readl(S5P64X0_PWR_CFG);
val &= ~(0x3 << 5);
val |= (0x1 << 5);
__raw_writel(val, S5P64X0_PWR_CFG);
cpu_do_idle();
}
local_irq_enable();
}
void __init s5p6440_map_io(void)
{
s3c_adc_setname("s3c64xx-adc");
s3c_fb_setname("s5p64x0-fb");
iotable_init(s5p64x0_iodesc, ARRAY_SIZE(s5p64x0_iodesc));
iotable_init(s5p6440_iodesc, ARRAY_SIZE(s5p6440_iodesc));
init_consistent_dma_size(SZ_8M);
}
void __init s5p6450_map_io(void)
{
s3c_adc_setname("s3c64xx-adc");
s3c_fb_setname("s5p64x0-fb");
iotable_init(s5p64x0_iodesc, ARRAY_SIZE(s5p64x0_iodesc));
iotable_init(s5p6450_iodesc, ARRAY_SIZE(s5p6450_iodesc));
init_consistent_dma_size(SZ_8M);
}
void __init s5p6440_init_clocks(int xtal)
{
printk(KERN_DEBUG "%s: initializing clocks\n", __func__);
s3c24xx_register_baseclocks(xtal);
s5p_register_clocks(xtal);
s5p6440_register_clocks();
s5p6440_setup_clocks();
}
void __init s5p6450_init_clocks(int xtal)
{
printk(KERN_DEBUG "%s: initializing clocks\n", __func__);
s3c24xx_register_baseclocks(xtal);
s5p_register_clocks(xtal);
s5p6450_register_clocks();
s5p6450_setup_clocks();
}
void __init s5p6440_init_irq(void)
{
u32 vic[2];
vic[0] = 0xff800ae7;
vic[1] = 0xffbf23e5;
s5p_init_irq(vic, ARRAY_SIZE(vic));
}
void __init s5p6450_init_irq(void)
{
u32 vic[2];
vic[0] = 0xff9f1fff;
vic[1] = 0xff7fafff;
s5p_init_irq(vic, ARRAY_SIZE(vic));
}
static int __init s5p64x0_core_init(void)
{
return sysdev_class_register(&s5p64x0_sysclass);
}
int __init s5p64x0_init(void)
{
printk(KERN_INFO "S5P64X0(S5P6440/S5P6450): Initializing architecture\n");
pm_idle = s5p64x0_idle;
return sysdev_register(&s5p64x0_sysdev);
}
