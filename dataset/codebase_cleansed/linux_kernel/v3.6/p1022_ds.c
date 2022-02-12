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
static phys_addr_t lbc_br_to_phys(const void *ecm, unsigned int count, u32 br)
{
#ifndef CONFIG_PHYS_64BIT
return br & BR_BA;
#else
const struct fsl_law *law = ecm + 0xc08;
unsigned int i;
for (i = 0; i < count; i++) {
u64 lawbar = in_be32(&law[i].lawbar);
u32 lawar = in_be32(&law[i].lawar);
if ((lawar & LAWAR_MASK) == LAWAR_MATCH)
return (br & BR_BA) | ((lawbar & LAWBAR_MASK) << 12);
}
return 0;
#endif
}
static void p1022ds_set_monitor_port(enum fsl_diu_monitor_port port)
{
struct device_node *guts_node;
struct device_node *lbc_node = NULL;
struct device_node *law_node = NULL;
struct ccsr_guts __iomem *guts;
struct fsl_lbc_regs *lbc = NULL;
void *ecm = NULL;
u8 __iomem *lbc_lcs0_ba = NULL;
u8 __iomem *lbc_lcs1_ba = NULL;
phys_addr_t cs0_addr, cs1_addr;
u32 br0, or0, br1, or1;
const __be32 *iprop;
unsigned int num_laws;
u8 b;
guts_node = of_find_compatible_node(NULL, NULL, "fsl,p1022-guts");
if (!guts_node) {
pr_err("p1022ds: missing global utilties device node\n");
return;
}
guts = of_iomap(guts_node, 0);
if (!guts) {
pr_err("p1022ds: could not map global utilties device\n");
goto exit;
}
lbc_node = of_find_compatible_node(NULL, NULL, "fsl,p1022-elbc");
if (!lbc_node) {
pr_err("p1022ds: missing localbus node\n");
goto exit;
}
lbc = of_iomap(lbc_node, 0);
if (!lbc) {
pr_err("p1022ds: could not map localbus node\n");
goto exit;
}
law_node = of_find_compatible_node(NULL, NULL, "fsl,ecm-law");
if (!law_node) {
pr_err("p1022ds: missing local access window node\n");
goto exit;
}
ecm = of_iomap(law_node, 0);
if (!ecm) {
pr_err("p1022ds: could not map local access window node\n");
goto exit;
}
iprop = of_get_property(law_node, "fsl,num-laws", 0);
if (!iprop) {
pr_err("p1022ds: LAW node is missing fsl,num-laws property\n");
goto exit;
}
num_laws = be32_to_cpup(iprop);
br0 = in_be32(&lbc->bank[0].br);
br1 = in_be32(&lbc->bank[1].br);
or0 = in_be32(&lbc->bank[0].or);
or1 = in_be32(&lbc->bank[1].or);
if (!(br0 & BR_V) || !(br1 & BR_V)) {
pr_err("p1022ds: CS0 and/or CS1 is not programmed\n");
goto exit;
}
if ((br0 & BR_MSEL) != BR_MS_GPCM) {
br0 = (br0 & BR_BA) | BR_V;
or0 = 0xFFFF8000 | 0xFF7;
out_be32(&lbc->bank[0].br, br0);
out_be32(&lbc->bank[0].or, or0);
}
if ((br1 & BR_MSEL) != BR_MS_GPCM) {
br1 = (br1 & BR_BA) | BR_V;
or1 = 0xFFFF8000 | 0xFF7;
out_be32(&lbc->bank[1].br, br1);
out_be32(&lbc->bank[1].or, or1);
}
cs0_addr = lbc_br_to_phys(ecm, num_laws, br0);
if (!cs0_addr) {
pr_err("p1022ds: could not determine physical address for CS0"
" (BR0=%08x)\n", br0);
goto exit;
}
cs1_addr = lbc_br_to_phys(ecm, num_laws, br1);
if (!cs0_addr) {
pr_err("p1022ds: could not determine physical address for CS1"
" (BR1=%08x)\n", br1);
goto exit;
}
lbc_lcs0_ba = ioremap(cs0_addr, 1);
if (!lbc_lcs0_ba) {
pr_err("p1022ds: could not ioremap CS0 address %llx\n",
(unsigned long long)cs0_addr);
goto exit;
}
lbc_lcs1_ba = ioremap(cs1_addr, 1);
if (!lbc_lcs1_ba) {
pr_err("p1022ds: could not ioremap CS1 address %llx\n",
(unsigned long long)cs1_addr);
goto exit;
}
if ((in_be32(&guts->pmuxcr) & PMUXCR_ELBCDIU_MASK) !=
PMUXCR_ELBCDIU_DIU) {
struct device_node *pixis_node;
void __iomem *pixis;
pixis_node =
of_find_compatible_node(NULL, NULL, "fsl,p1022ds-fpga");
if (!pixis_node) {
pr_err("p1022ds: missing pixis node\n");
goto exit;
}
pixis = of_iomap(pixis_node, 0);
of_node_put(pixis_node);
if (!pixis) {
pr_err("p1022ds: could not map pixis registers\n");
goto exit;
}
setbits8(pixis + PX_CTL, PX_CTL_ALTACC);
iounmap(pixis);
out_8(lbc_lcs0_ba, PX_BRDCFG0);
b = in_8(lbc_lcs1_ba);
b |= PX_BRDCFG0_ELBC_DIU;
out_8(lbc_lcs1_ba, b);
clrsetbits_be32(&guts->pmuxcr, PMUXCR_ELBCDIU_MASK,
PMUXCR_ELBCDIU_DIU);
in_be32(&guts->pmuxcr);
}
switch (port) {
case FSL_DIU_PORT_DVI:
out_8(lbc_lcs0_ba, PX_BRDCFG1);
b = in_8(lbc_lcs1_ba);
b &= ~(PX_BRDCFG1_DFPEN | PX_BRDCFG1_BACKLIGHT);
b |= PX_BRDCFG1_DVIEN;
out_8(lbc_lcs1_ba, b);
break;
case FSL_DIU_PORT_LVDS:
out_8(lbc_lcs0_ba, PX_BRDCFG1);
b = in_8(lbc_lcs1_ba);
b &= ~PX_BRDCFG1_DVIEN;
b |= PX_BRDCFG1_DFPEN | PX_BRDCFG1_BACKLIGHT;
out_8(lbc_lcs1_ba, b);
break;
default:
pr_err("p1022ds: unsupported monitor port %i\n", port);
}
exit:
if (lbc_lcs1_ba)
iounmap(lbc_lcs1_ba);
if (lbc_lcs0_ba)
iounmap(lbc_lcs0_ba);
if (lbc)
iounmap(lbc);
if (ecm)
iounmap(ecm);
if (guts)
iounmap(guts);
of_node_put(law_node);
of_node_put(lbc_node);
of_node_put(guts_node);
}
void p1022ds_set_pixel_clock(unsigned int pixclock)
{
struct device_node *guts_np = NULL;
struct ccsr_guts __iomem *guts;
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
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static int __init early_video_setup(char *options)
{
fslfb = (strncmp(options, "fslfb:", 6) == 0);
return 0;
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
if (fslfb) {
struct device_node *np =
of_find_compatible_node(NULL, NULL, "fsl,p1022-elbc");
if (np) {
struct device_node *np2;
of_node_get(np);
np2 = of_find_compatible_node(np, NULL, "cfi-flash");
if (np2) {
static struct property nor_status = {
.name = "status",
.value = "disabled",
.length = sizeof("disabled"),
};
pr_info("p1022ds: disabling %s node",
np2->full_name);
prom_update_property(np2, &nor_status);
of_node_put(np2);
}
of_node_get(np);
np2 = of_find_compatible_node(np, NULL,
"fsl,elbc-fcm-nand");
if (np2) {
static struct property nand_status = {
.name = "status",
.value = "disabled",
.length = sizeof("disabled"),
};
pr_info("p1022ds: disabling %s node",
np2->full_name);
prom_update_property(np2, &nand_status);
of_node_put(np2);
}
of_node_put(np);
}
}
#endif
mpc85xx_smp_init();
#ifdef CONFIG_SWIOTLB
if ((memblock_end_of_DRAM() - 1) > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
pr_info("Freescale P1022 DS reference board\n");
}
static int __init p1022_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,p1022ds");
}
