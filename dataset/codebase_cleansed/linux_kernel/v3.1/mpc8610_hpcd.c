static irqreturn_t mpc8610_sw9_irq(int irq, void *data)
{
pr_debug("%s: PIXIS' event (sw9/wakeup) IRQ handled\n", __func__);
return IRQ_HANDLED;
}
static void __init mpc8610_suspend_init(void)
{
int irq;
int ret;
if (!pixis_node)
return;
irq = irq_of_parse_and_map(pixis_node, 0);
if (!irq) {
pr_err("%s: can't map pixis event IRQ.\n", __func__);
return;
}
ret = request_irq(irq, mpc8610_sw9_irq, 0, "sw9:wakeup", NULL);
if (ret) {
pr_err("%s: can't request pixis event IRQ: %d\n",
__func__, ret);
irq_dispose_mapping(irq);
}
enable_irq_wake(irq);
}
static inline void mpc8610_suspend_init(void) { }
static int __init mpc8610_declare_of_platform_devices(void)
{
simple_gpiochip_init("fsl,fpga-pixis-gpio-bank");
mpc8610_suspend_init();
of_platform_bus_probe(NULL, mpc8610_ids, NULL);
return 0;
}
unsigned int mpc8610hpcd_get_pixel_format(unsigned int bits_per_pixel,
int monitor_port)
{
static const unsigned long pixelformat[][3] = {
{
MAKE_AD(3, 0, 2, 1, 3, 8, 8, 8, 8),
MAKE_AD(4, 2, 0, 1, 2, 8, 8, 8, 0),
MAKE_AD(4, 0, 2, 1, 1, 5, 6, 5, 0)
},
{
MAKE_AD(3, 2, 0, 1, 3, 8, 8, 8, 8),
MAKE_AD(4, 0, 2, 1, 2, 8, 8, 8, 0),
MAKE_AD(4, 2, 0, 1, 1, 5, 6, 5, 0)
},
};
unsigned int arch_monitor;
arch_monitor = ((*pixis_arch == 0x01) && (monitor_port == 0))? 0 : 1;
switch (bits_per_pixel) {
case 32:
return pixelformat[arch_monitor][0];
case 24:
return pixelformat[arch_monitor][1];
case 16:
return pixelformat[arch_monitor][2];
default:
pr_err("fsl-diu: unsupported pixel depth %u\n", bits_per_pixel);
return 0;
}
}
void mpc8610hpcd_set_gamma_table(int monitor_port, char *gamma_table_base)
{
int i;
if (monitor_port == 2) {
for (i = 0; i < 256*3; i++)
gamma_table_base[i] = (gamma_table_base[i] << 2) |
((gamma_table_base[i] >> 6) & 0x03);
}
}
void mpc8610hpcd_set_monitor_port(int monitor_port)
{
static const u8 bdcfg[] = {
PX_BRDCFG0_DVISEL | PX_BRDCFG0_DLINK,
PX_BRDCFG0_DLINK,
0,
};
if (monitor_port < 3)
clrsetbits_8(pixis_bdcfg0, PX_BRDCFG0_DIU_MASK,
bdcfg[monitor_port]);
}
void mpc8610hpcd_set_pixel_clock(unsigned int pixclock)
{
struct device_node *guts_np = NULL;
struct ccsr_guts_86xx __iomem *guts;
unsigned long freq;
u64 temp;
u32 pxclk;
guts_np = of_find_compatible_node(NULL, NULL, "fsl,mpc8610-guts");
if (!guts_np) {
pr_err("mpc8610hpcd: missing global utilties device node\n");
return;
}
guts = of_iomap(guts_np, 0);
of_node_put(guts_np);
if (!guts) {
pr_err("mpc8610hpcd: could not map global utilties device\n");
return;
}
temp = 1000000000000ULL;
do_div(temp, pixclock);
freq = temp;
pxclk = DIV_ROUND_CLOSEST(fsl_get_sys_freq(), freq) - 1;
pxclk = clamp_t(u32, pxclk, 2, 31);
clrbits32(&guts->clkdvdr,
CLKDVDR_PXCKEN | CLKDVDR_PXCKDLY | CLKDVDR_PXCLK_MASK);
setbits32(&guts->clkdvdr, CLKDVDR_PXCKEN | (pxclk << 16));
iounmap(guts);
}
ssize_t mpc8610hpcd_show_monitor_port(int monitor_port, char *buf)
{
return snprintf(buf, PAGE_SIZE,
"%c0 - DVI\n"
"%c1 - Single link LVDS\n"
"%c2 - Dual link LVDS\n",
monitor_port == 0 ? '*' : ' ',
monitor_port == 1 ? '*' : ' ',
monitor_port == 2 ? '*' : ' ');
}
int mpc8610hpcd_set_sysfs_monitor_port(int val)
{
return val < 3 ? val : 0;
}
static void __init mpc86xx_hpcd_setup_arch(void)
{
struct resource r;
struct device_node *np;
unsigned char *pixis;
if (ppc_md.progress)
ppc_md.progress("mpc86xx_hpcd_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8610-pci")
|| of_device_is_compatible(np, "fsl,mpc8641-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0xa000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
}
}
#endif
#if defined(CONFIG_FB_FSL_DIU) || defined(CONFIG_FB_FSL_DIU_MODULE)
diu_ops.get_pixel_format = mpc8610hpcd_get_pixel_format;
diu_ops.set_gamma_table = mpc8610hpcd_set_gamma_table;
diu_ops.set_monitor_port = mpc8610hpcd_set_monitor_port;
diu_ops.set_pixel_clock = mpc8610hpcd_set_pixel_clock;
diu_ops.show_monitor_port = mpc8610hpcd_show_monitor_port;
diu_ops.set_sysfs_monitor_port = mpc8610hpcd_set_sysfs_monitor_port;
#endif
pixis_node = of_find_compatible_node(NULL, NULL, "fsl,fpga-pixis");
if (pixis_node) {
of_address_to_resource(pixis_node, 0, &r);
of_node_put(pixis_node);
pixis = ioremap(r.start, 32);
if (!pixis) {
printk(KERN_ERR "Err: can't map FPGA cfg register!\n");
return;
}
pixis_bdcfg0 = pixis + 8;
pixis_arch = pixis + 1;
} else
printk(KERN_ERR "Err: "
"can't find device node 'fsl,fpga-pixis'\n");
printk("MPC86xx HPCD board from Freescale Semiconductor\n");
}
static int __init mpc86xx_hpcd_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,MPC8610HPCD"))
return 1;
return 0;
}
static long __init mpc86xx_time_init(void)
{
unsigned int temp;
mtspr(SPRN_TBWL, 0);
mtspr(SPRN_TBWU, 0);
temp = mfspr(SPRN_HID0);
temp |= HID0_TBEN;
mtspr(SPRN_HID0, temp);
asm volatile("isync");
return 0;
}
