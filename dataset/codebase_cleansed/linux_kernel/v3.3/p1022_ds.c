static u32 p1022ds_get_pixel_format(enum fsl_diu_monitor_port port,
unsigned int bits_per_pixel)
{
switch (bits_per_pixel) {
case 32:
return MAKE_AD(3, 2, 0, 1, 3, 8, 8, 8, 8);
case 24:
return MAKE_AD(4, 0, 1, 2, 2, 0, 8, 8, 8);
case 16:
return MAKE_AD(4, 2, 1, 0, 1, 5, 6, 5, 0);
default:
pr_err("fsl-diu: unsupported pixel depth %u\n", bits_per_pixel);
return 0;
}
}
static void p1022ds_set_gamma_table(enum fsl_diu_monitor_port port,
char *gamma_table_base)
{
}
static void p1022ds_set_monitor_port(enum fsl_diu_monitor_port port)
{
struct device_node *np;
void __iomem *pixis;
u8 __iomem *brdcfg1;
np = of_find_compatible_node(NULL, NULL, "fsl,p1022ds-fpga");
if (!np)
np = of_find_compatible_node(NULL, NULL, "fsl,p1022ds-pixis");
if (!np) {
pr_err("p1022ds: missing ngPIXIS node\n");
return;
}
pixis = of_iomap(np, 0);
if (!pixis) {
pr_err("p1022ds: could not map ngPIXIS registers\n");
return;
}
brdcfg1 = pixis + 9;
switch (port) {
case FSL_DIU_PORT_DVI:
printk(KERN_INFO "%s:%u\n", __func__, __LINE__);
clrsetbits_8(brdcfg1, PX_BRDCFG1_DFPEN | PX_BRDCFG1_BACKLIGHT,
PX_BRDCFG1_DVIEN);
break;
case FSL_DIU_PORT_LVDS:
printk(KERN_INFO "%s:%u\n", __func__, __LINE__);
clrsetbits_8(brdcfg1, PX_BRDCFG1_DVIEN | PX_BRDCFG1_BACKLIGHT,
PX_BRDCFG1_DFPEN);
break;
default:
pr_err("p1022ds: unsupported monitor port %i\n", port);
}
iounmap(pixis);
}
void p1022ds_set_pixel_clock(unsigned int pixclock)
{
struct device_node *guts_np = NULL;
struct ccsr_guts_85xx __iomem *guts;
unsigned long freq;
u64 temp;
u32 pxclk;
guts_np = of_find_compatible_node(NULL, NULL, "fsl,p1022-guts");
if (!guts_np) {
pr_err("p1022ds: missing global utilties device node\n");
return;
}
guts = of_iomap(guts_np, 0);
of_node_put(guts_np);
if (!guts) {
pr_err("p1022ds: could not map global utilties device\n");
return;
}
temp = 1000000000000ULL;
do_div(temp, pixclock);
freq = temp;
pxclk = DIV_ROUND_CLOSEST(fsl_get_sys_freq(), freq);
pxclk = clamp_t(u32, pxclk, 2, 255);
clrbits32(&guts->clkdvdr,
CLKDVDR_PXCKEN | CLKDVDR_PXCKDLY | CLKDVDR_PXCLK_MASK);
setbits32(&guts->clkdvdr, CLKDVDR_PXCKEN | (pxclk << 16));
iounmap(guts);
}
enum fsl_diu_monitor_port
p1022ds_valid_monitor_port(enum fsl_diu_monitor_port port)
{
switch (port) {
case FSL_DIU_PORT_DVI:
case FSL_DIU_PORT_LVDS:
return port;
default:
return FSL_DIU_PORT_DVI;
}
}
void __init p1022_ds_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0,
MPIC_WANTS_RESET |
MPIC_BIG_ENDIAN | MPIC_BROKEN_FRR_NIRQS |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init p1022_ds_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
dma_addr_t max = 0xffffffff;
if (ppc_md.progress)
ppc_md.progress("p1022_ds_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,p1022-pcie") {
struct resource rsrc;
struct pci_controller *hose;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0x8000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
hose = pci_find_hose_for_OF_device(np);
max = min(max, hose->dma_window_base_cur +
hose->dma_window_size);
}
#endif
#if defined(CONFIG_FB_FSL_DIU) || defined(CONFIG_FB_FSL_DIU_MODULE)
diu_ops.get_pixel_format = p1022ds_get_pixel_format;
diu_ops.set_gamma_table = p1022ds_set_gamma_table;
diu_ops.set_monitor_port = p1022ds_set_monitor_port;
diu_ops.set_pixel_clock = p1022ds_set_pixel_clock;
diu_ops.valid_monitor_port = p1022ds_valid_monitor_port;
#endif
mpc85xx_smp_init();
#ifdef CONFIG_SWIOTLB
if (memblock_end_of_DRAM() > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
pr_info("Freescale P1022 DS reference board\n");
}
static int __init p1022_ds_publish_devices(void)
{
mpc85xx_common_publish_devices();
return of_platform_bus_probe(NULL, p1022_ds_ids, NULL);
}
static int __init p1022_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,p1022ds");
}
