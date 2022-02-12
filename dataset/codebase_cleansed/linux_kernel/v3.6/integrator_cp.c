static void __init intcp_map_io(void)
{
iotable_init(intcp_io_desc, ARRAY_SIZE(intcp_io_desc));
}
static void __init intcp_init_irq(void)
{
u32 pic_mask, cic_mask, sic_mask;
pic_mask = ~((~0u) << (11 - IRQ_PIC_START));
pic_mask |= (~((~0u) << (29 - 22))) << 22;
cic_mask = ~((~0u) << (1 + IRQ_CIC_END - IRQ_CIC_START));
sic_mask = ~((~0u) << (1 + IRQ_SIC_END - IRQ_SIC_START));
writel(0xffffffff, INTCP_VA_PIC_BASE + IRQ_ENABLE_CLEAR);
writel(0xffffffff, INTCP_VA_PIC_BASE + FIQ_ENABLE_CLEAR);
writel(0xffffffff, INTCP_VA_CIC_BASE + IRQ_ENABLE_CLEAR);
writel(0xffffffff, INTCP_VA_CIC_BASE + FIQ_ENABLE_CLEAR);
writel(sic_mask, INTCP_VA_SIC_BASE + IRQ_ENABLE_CLEAR);
writel(sic_mask, INTCP_VA_SIC_BASE + FIQ_ENABLE_CLEAR);
fpga_irq_init(INTCP_VA_PIC_BASE, "PIC", IRQ_PIC_START,
-1, pic_mask, NULL);
fpga_irq_init(INTCP_VA_CIC_BASE, "CIC", IRQ_CIC_START,
-1, cic_mask, NULL);
fpga_irq_init(INTCP_VA_SIC_BASE, "SIC", IRQ_SIC_START,
IRQ_CP_CPPLDINT, sic_mask, NULL);
integrator_clk_init(true);
}
static int intcp_flash_init(struct platform_device *dev)
{
u32 val;
val = readl(INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
val |= CINTEGRATOR_FLASHPROG_FLWREN;
writel(val, INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
return 0;
}
static void intcp_flash_exit(struct platform_device *dev)
{
u32 val;
val = readl(INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
val &= ~(CINTEGRATOR_FLASHPROG_FLVPPEN|CINTEGRATOR_FLASHPROG_FLWREN);
writel(val, INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
}
static void intcp_flash_set_vpp(struct platform_device *pdev, int on)
{
u32 val;
val = readl(INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
if (on)
val |= CINTEGRATOR_FLASHPROG_FLVPPEN;
else
val &= ~CINTEGRATOR_FLASHPROG_FLVPPEN;
writel(val, INTCP_VA_CTRL_BASE + INTCP_FLASHPROG);
}
static unsigned int mmc_status(struct device *dev)
{
unsigned int status = readl(IO_ADDRESS(0xca000000 + 4));
writel(8, IO_ADDRESS(INTEGRATOR_CP_CTL_BASE + 8));
return status & 8;
}
static void cp_clcd_enable(struct clcd_fb *fb)
{
struct fb_var_screeninfo *var = &fb->fb.var;
u32 val = CM_CTRL_STATIC1 | CM_CTRL_STATIC2;
if (var->bits_per_pixel <= 8 ||
(var->bits_per_pixel == 16 && var->green.length == 5))
val |= CM_CTRL_LCDMUXSEL_VGA555_TFT555;
else if (fb->fb.var.bits_per_pixel <= 16)
val |= CM_CTRL_LCDMUXSEL_VGA565_TFT555;
else
val = 0;
cm_control(CM_CTRL_LCDMUXSEL_MASK|
CM_CTRL_LCDEN0|
CM_CTRL_LCDEN1|
CM_CTRL_STATIC1|
CM_CTRL_STATIC2|
CM_CTRL_STATIC|
CM_CTRL_n24BITEN, val);
}
static int cp_clcd_setup(struct clcd_fb *fb)
{
fb->panel = versatile_clcd_get_panel("VGA");
if (!fb->panel)
return -EINVAL;
return versatile_clcd_setup_dma(fb, SZ_1M);
}
static void __init intcp_init_early(void)
{
#ifdef CONFIG_PLAT_VERSATILE_SCHED_CLOCK
versatile_sched_clock_init(REFCOUNTER, 24000000);
#endif
}
static void __init intcp_init(void)
{
int i;
platform_add_devices(intcp_devs, ARRAY_SIZE(intcp_devs));
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
}
static void __init intcp_timer_init(void)
{
writel(0, TIMER0_VA_BASE + TIMER_CTRL);
writel(0, TIMER1_VA_BASE + TIMER_CTRL);
writel(0, TIMER2_VA_BASE + TIMER_CTRL);
sp804_clocksource_init(TIMER2_VA_BASE, "timer2");
sp804_clockevents_init(TIMER1_VA_BASE, IRQ_TIMERINT1, "timer1");
}
