static void __init mpc8272_ads_pic_init(void)
{
struct device_node *np = of_find_compatible_node(NULL, NULL,
"fsl,cpm2-pic");
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
for (i = 0; i < ARRAY_SIZE(mpc8272_ads_pins); i++) {
struct cpm_pin *pin = &mpc8272_ads_pins[i];
cpm2_set_pin(pin->port, pin->pin, pin->flags);
}
cpm2_clk_setup(CPM_CLK_SCC1, CPM_BRG1, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC1, CPM_BRG1, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_SCC3, CPM_CLK8, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC3, CPM_CLK8, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_SCC4, CPM_BRG4, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC4, CPM_BRG4, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC1, CPM_CLK11, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC1, CPM_CLK10, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC2, CPM_CLK15, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC2, CPM_CLK16, CPM_CLK_TX);
}
static void __init mpc8272_ads_setup_arch(void)
{
struct device_node *np;
__be32 __iomem *bcsr;
if (ppc_md.progress)
ppc_md.progress("mpc8272_ads_setup_arch()", 0);
cpm2_reset();
np = of_find_compatible_node(NULL, NULL, "fsl,mpc8272ads-bcsr");
if (!np) {
printk(KERN_ERR "No bcsr in device tree\n");
return;
}
bcsr = of_iomap(np, 0);
of_node_put(np);
if (!bcsr) {
printk(KERN_ERR "Cannot map BCSR registers\n");
return;
}
#define BCSR1_FETHIEN 0x08000000
#define BCSR1_FETH_RST 0x04000000
#define BCSR1_RS232_EN1 0x02000000
#define BCSR1_RS232_EN2 0x01000000
#define BCSR3_USB_nEN 0x80000000
#define BCSR3_FETHIEN2 0x10000000
#define BCSR3_FETH2_RST 0x08000000
clrbits32(&bcsr[1], BCSR1_RS232_EN1 | BCSR1_RS232_EN2 | BCSR1_FETHIEN);
setbits32(&bcsr[1], BCSR1_FETH_RST);
clrbits32(&bcsr[3], BCSR3_FETHIEN2);
setbits32(&bcsr[3], BCSR3_FETH2_RST);
clrbits32(&bcsr[3], BCSR3_USB_nEN);
iounmap(bcsr);
init_ioports();
pq2_init_pci();
if (ppc_md.progress)
ppc_md.progress("mpc8272_ads_setup_arch(), finish", 0);
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init mpc8272_ads_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,mpc8272ads");
}
