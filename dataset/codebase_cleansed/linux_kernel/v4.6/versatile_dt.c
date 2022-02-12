static void versatile_flash_set_vpp(struct platform_device *pdev, int on)
{
u32 val;
val = readl(versatile_sys_base + VERSATILE_SYS_FLASH_OFFSET);
if (on)
val |= VERSATILE_FLASHPROG_FLVPPEN;
else
val &= ~VERSATILE_FLASHPROG_FLVPPEN;
writel(val, versatile_sys_base + VERSATILE_SYS_FLASH_OFFSET);
}
unsigned int mmc_status(struct device *dev)
{
struct amba_device *adev = container_of(dev, struct amba_device, dev);
u32 mask;
if (adev->res.start == VERSATILE_MMCI0_BASE)
mask = 1;
else
mask = 2;
return readl(versatile_sys_base + VERSATILE_SYS_MCI_OFFSET) & mask;
}
static void versatile_clcd_disable(struct clcd_fb *fb)
{
void __iomem *sys_clcd = versatile_sys_base + VERSATILE_SYS_CLCD_OFFSET;
u32 val;
val = readl(sys_clcd);
val &= ~SYS_CLCD_NLCDIOON | SYS_CLCD_PWR3V5SWITCH;
writel(val, sys_clcd);
if (of_machine_is_compatible("arm,versatile-ab") && is_sanyo_2_5_lcd) {
unsigned long ctrl;
ctrl = readl(versatile_ib2_ctrl);
ctrl &= ~0x01;
writel(ctrl, versatile_ib2_ctrl);
}
}
static void versatile_clcd_enable(struct clcd_fb *fb)
{
struct fb_var_screeninfo *var = &fb->fb.var;
void __iomem *sys_clcd = versatile_sys_base + VERSATILE_SYS_CLCD_OFFSET;
u32 val;
val = readl(sys_clcd);
val &= ~SYS_CLCD_MODE_MASK;
switch (var->green.length) {
case 5:
val |= SYS_CLCD_MODE_5551;
break;
case 6:
if (var->red.offset == 0)
val |= SYS_CLCD_MODE_565_RLSB;
else
val |= SYS_CLCD_MODE_565_BLSB;
break;
case 8:
val |= SYS_CLCD_MODE_888;
break;
}
writel(val, sys_clcd);
val |= SYS_CLCD_NLCDIOON | SYS_CLCD_PWR3V5SWITCH;
writel(val, sys_clcd);
if (of_machine_is_compatible("arm,versatile-ab") && is_sanyo_2_5_lcd) {
unsigned long ctrl;
ctrl = readl(versatile_ib2_ctrl);
ctrl |= 0x01;
writel(ctrl, versatile_ib2_ctrl);
}
}
static int versatile_clcd_setup(struct clcd_fb *fb)
{
void __iomem *sys_clcd = versatile_sys_base + VERSATILE_SYS_CLCD_OFFSET;
const char *panel_name;
u32 val;
is_sanyo_2_5_lcd = false;
val = readl(sys_clcd) & SYS_CLCD_ID_MASK;
if (val == SYS_CLCD_ID_SANYO_3_8)
panel_name = "Sanyo TM38QV67A02A";
else if (val == SYS_CLCD_ID_SANYO_2_5) {
panel_name = "Sanyo QVGA Portrait";
is_sanyo_2_5_lcd = true;
} else if (val == SYS_CLCD_ID_EPSON_2_2)
panel_name = "Epson L2F50113T00";
else if (val == SYS_CLCD_ID_VGA)
panel_name = "VGA";
else {
printk(KERN_ERR "CLCD: unknown LCD panel ID 0x%08x, using VGA\n",
val);
panel_name = "VGA";
}
fb->panel = versatile_clcd_get_panel(panel_name);
if (!fb->panel)
return -EINVAL;
return versatile_clcd_setup_dma(fb, SZ_1M);
}
static void versatile_clcd_decode(struct clcd_fb *fb, struct clcd_regs *regs)
{
clcdfb_decode(fb, regs);
if (fb->fb.var.green.length == 6)
regs->cntl &= ~CNTL_BGR;
}
static void __init versatile_map_io(void)
{
debug_ll_io_init();
iotable_init(versatile_io_desc, ARRAY_SIZE(versatile_io_desc));
}
static void __init versatile_init_early(void)
{
u32 val;
val = readl(__io_address(VERSATILE_SCTL_BASE));
writel((VERSATILE_TIMCLK << VERSATILE_TIMER1_EnSel) |
(VERSATILE_TIMCLK << VERSATILE_TIMER2_EnSel) |
(VERSATILE_TIMCLK << VERSATILE_TIMER3_EnSel) |
(VERSATILE_TIMCLK << VERSATILE_TIMER4_EnSel) | val,
__io_address(VERSATILE_SCTL_BASE));
}
static void __init versatile_dt_pci_init(void)
{
u32 val;
struct device_node *np;
struct property *newprop;
np = of_find_compatible_node(NULL, NULL, "arm,versatile-pci");
if (!np)
return;
val = readl(versatile_sys_base + VERSATILE_SYS_PCICTL_OFFSET);
if (val & 1) {
writel(1, versatile_sys_base + VERSATILE_SYS_PCICTL_OFFSET);
return;
}
newprop = kzalloc(sizeof(*newprop), GFP_KERNEL);
if (!newprop)
return;
newprop->name = kstrdup("status", GFP_KERNEL);
newprop->value = kstrdup("disabled", GFP_KERNEL);
newprop->length = sizeof("disabled");
of_update_property(np, newprop);
pr_info("Not plugged into PCI backplane!\n");
}
static void __init versatile_dt_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "arm,core-module-versatile");
if (np)
versatile_sys_base = of_iomap(np, 0);
WARN_ON(!versatile_sys_base);
versatile_ib2_ctrl = ioremap(VERSATILE_IB2_CTL_BASE, SZ_4K);
versatile_dt_pci_init();
platform_device_register(&versatile_flash_device);
of_platform_populate(NULL, of_default_bus_match_table,
versatile_auxdata_lookup, NULL);
}
