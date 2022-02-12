static void __init pq2fads_pic_init(void)
{
struct device_node *np = of_find_compatible_node(NULL, NULL, "fsl,cpm2-pic");
if (!np) {
printk(KERN_ERR "PIC init: can not find fsl,cpm2-pic node\n");
return;
}
cpm2_pic_init(np);
of_node_put(np);
pq2ads_pci_init_irq();
}
static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(pq2fads_pins); i++) {
struct cpm_pin *pin = &pq2fads_pins[i];
cpm2_set_pin(pin->port, pin->pin, pin->flags);
}
cpm2_clk_setup(CPM_CLK_SCC1, CPM_BRG1, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC1, CPM_BRG1, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_SCC2, CPM_BRG2, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC2, CPM_BRG2, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC2, CPM_CLK13, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC2, CPM_CLK14, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC3, CPM_CLK15, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC3, CPM_CLK16, CPM_CLK_TX);
}
static void __init pq2fads_setup_arch(void)
{
struct device_node *np;
__be32 __iomem *bcsr;
if (ppc_md.progress)
ppc_md.progress("pq2fads_setup_arch()", 0);
cpm2_reset();
np = of_find_compatible_node(NULL, NULL, "fsl,pq2fads-bcsr");
if (!np) {
printk(KERN_ERR "No fsl,pq2fads-bcsr in device tree\n");
return;
}
bcsr = of_iomap(np, 0);
of_node_put(np);
if (!bcsr) {
printk(KERN_ERR "Cannot map BCSR registers\n");
return;
}
clrbits32(&bcsr[1], BCSR1_RS232_EN1 | BCSR1_RS232_EN2 | BCSR1_FETHIEN);
setbits32(&bcsr[1], BCSR1_FETH_RST);
clrbits32(&bcsr[3], BCSR3_FETHIEN2);
setbits32(&bcsr[3], BCSR3_FETH2_RST);
iounmap(bcsr);
init_ioports();
clrbits32(&cpm2_immr->im_siu_conf.siu_82xx.sc_siumcr, 0x0c000000);
pq2_init_pci();
if (ppc_md.progress)
ppc_md.progress("pq2fads_setup_arch(), finish", 0);
}
static int __init pq2fads_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,pq2fads");
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
