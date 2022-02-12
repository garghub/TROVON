void p1022rdk_set_pixel_clock(unsigned int pixclock)
{
struct device_node *guts_np = NULL;
struct ccsr_guts __iomem *guts;
unsigned long freq;
u64 temp;
u32 pxclk;
guts_np = of_find_compatible_node(NULL, NULL, "fsl,p1022-guts");
if (!guts_np) {
pr_err("p1022rdk: missing global utilties device node\n");
return;
}
guts = of_iomap(guts_np, 0);
of_node_put(guts_np);
if (!guts) {
pr_err("p1022rdk: could not map global utilties device\n");
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
p1022rdk_valid_monitor_port(enum fsl_diu_monitor_port port)
{
return FSL_DIU_PORT_DVI;
}
void __init p1022_rdk_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init p1022_rdk_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("p1022_rdk_setup_arch()", 0);
#if defined(CONFIG_FB_FSL_DIU) || defined(CONFIG_FB_FSL_DIU_MODULE)
diu_ops.set_pixel_clock = p1022rdk_set_pixel_clock;
diu_ops.valid_monitor_port = p1022rdk_valid_monitor_port;
#endif
mpc85xx_smp_init();
fsl_pci_assign_primary();
swiotlb_detect_4g();
pr_info("Freescale / iVeia P1022 RDK reference board\n");
}
static int __init p1022_rdk_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,p1022rdk");
}
