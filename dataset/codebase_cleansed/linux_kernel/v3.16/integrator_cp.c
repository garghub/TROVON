static void __init intcp_map_io(void)
{
iotable_init(intcp_io_desc, ARRAY_SIZE(intcp_io_desc));
}
static int intcp_flash_init(struct platform_device *dev)
{
u32 val;
val = readl(intcp_con_base + INTCP_FLASHPROG);
val |= CINTEGRATOR_FLASHPROG_FLWREN;
writel(val, intcp_con_base + INTCP_FLASHPROG);
return 0;
}
static void intcp_flash_exit(struct platform_device *dev)
{
u32 val;
val = readl(intcp_con_base + INTCP_FLASHPROG);
val &= ~(CINTEGRATOR_FLASHPROG_FLVPPEN|CINTEGRATOR_FLASHPROG_FLWREN);
writel(val, intcp_con_base + INTCP_FLASHPROG);
}
static void intcp_flash_set_vpp(struct platform_device *pdev, int on)
{
u32 val;
val = readl(intcp_con_base + INTCP_FLASHPROG);
if (on)
val |= CINTEGRATOR_FLASHPROG_FLVPPEN;
else
val &= ~CINTEGRATOR_FLASHPROG_FLVPPEN;
writel(val, intcp_con_base + INTCP_FLASHPROG);
}
static unsigned int mmc_status(struct device *dev)
{
unsigned int status = readl(__io_address(0xca000000 + 4));
writel(8, intcp_con_base + 8);
return status & 8;
}
static void cp_clcd_enable(struct clcd_fb *fb)
{
struct fb_var_screeninfo *var = &fb->fb.var;
u32 val = CM_CTRL_STATIC1 | CM_CTRL_STATIC2
| CM_CTRL_LCDEN0 | CM_CTRL_LCDEN1;
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
static u64 notrace intcp_read_sched_clock(void)
{
return readl(REFCOUNTER);
}
static void __init intcp_init_early(void)
{
sched_clock_register(intcp_read_sched_clock, 32, 24000000);
}
static void __init intcp_init_irq_of(void)
{
cm_init();
of_irq_init(fpga_irq_of_match);
}
static void __init intcp_init_of(void)
{
struct device_node *cpcon;
struct device *parent;
struct soc_device *soc_dev;
struct soc_device_attribute *soc_dev_attr;
u32 intcp_sc_id;
cpcon = of_find_matching_node(NULL, intcp_syscon_match);
if (!cpcon)
return;
intcp_con_base = of_iomap(cpcon, 0);
if (!intcp_con_base)
return;
of_platform_populate(NULL, of_default_bus_match_table,
intcp_auxdata_lookup, NULL);
intcp_sc_id = readl(intcp_con_base);
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
return;
soc_dev_attr->soc_id = "XCV";
soc_dev_attr->machine = "Integrator/CP";
soc_dev_attr->family = "Integrator";
soc_dev_attr->revision = kasprintf(GFP_KERNEL, "%c",
'A' + (intcp_sc_id & 0x0f));
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr->revision);
kfree(soc_dev_attr);
return;
}
parent = soc_device_to_device(soc_dev);
integrator_init_sysfs(parent, intcp_sc_id);
}
