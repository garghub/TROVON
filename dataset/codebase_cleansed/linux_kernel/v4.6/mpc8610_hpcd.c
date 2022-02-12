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
mpc86xx_common_publish_devices();
of_platform_bus_probe(NULL, mpc8610_ids, NULL);
return 0;
}
u32 mpc8610hpcd_get_pixel_format(enum fsl_diu_monitor_port port,
unsigned int bits_per_pixel)
{
static const u32 pixelformat[][3] = {
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
arch_monitor =
((*pixis_arch == 0x01) && (port == FSL_DIU_PORT_DVI)) ? 0 : 1;
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
void mpc8610hpcd_set_gamma_table(enum fsl_diu_monitor_port port,
char *gamma_table_base)
{
int i;
if (port == FSL_DIU_PORT_DLVDS) {
for (i = 0; i < 256*3; i++)
gamma_table_base[i] = (gamma_table_base[i] << 2) |
((gamma_table_base[i] >> 6) & 0x03);
}
}
void mpc8610hpcd_set_monitor_port(enum fsl_diu_monitor_port port)
{
switch (port) {
case FSL_DIU_PORT_DVI:
clrsetbits_8(pixis_bdcfg0, PX_BRDCFG0_DIU_MASK,
PX_BRDCFG0_DVISEL | PX_BRDCFG0_DLINK);
break;
case FSL_DIU_PORT_LVDS:
clrsetbits_8(pixis_bdcfg0, PX_BRDCFG0_DIU_MASK,
PX_BRDCFG0_DLINK);
break;
case FSL_DIU_PORT_DLVDS:
clrbits8(pixis_bdcfg0, PX_BRDCFG0_DIU_MASK);
break;
}
}
void mpc8610hpcd_set_pixel_clock(unsigned int pixclock)
{
struct device_node *guts_np = NULL;
struct ccsr_guts __iomem *guts;
unsigned long freq;
u64 temp;
u32 pxclk;
guts_np = of_find_compatible_node(NULL, NULL, "fsl,mpc8610-guts");
if (!guts_np) {
pr_err("mpc8610hpcd: missing global utilities device node\n");
return;
}
guts = of_iomap(guts_np, 0);
of_node_put(guts_np);
if (!guts) {
pr_err("mpc8610hpcd: could not map global utilities device\n");
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
enum fsl_diu_monitor_port
mpc8610hpcd_valid_monitor_port(enum fsl_diu_monitor_port port)
{
return port;
}
static void __init mpc86xx_hpcd_setup_arch(void)
{
struct resource r;
unsigned char *pixis;
if (ppc_md.progress)
ppc_md.progress("mpc86xx_hpcd_setup_arch()", 0);
fsl_pci_assign_primary();
#if defined(CONFIG_FB_FSL_DIU) || defined(CONFIG_FB_FSL_DIU_MODULE)
diu_ops.get_pixel_format = mpc8610hpcd_get_pixel_format;
diu_ops.set_gamma_table = mpc8610hpcd_set_gamma_table;
diu_ops.set_monitor_port = mpc8610hpcd_set_monitor_port;
diu_ops.set_pixel_clock = mpc8610hpcd_set_pixel_clock;
diu_ops.valid_monitor_port = mpc8610hpcd_valid_monitor_port;
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
