static void cpm2_cascade(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
int cascade_irq;
while ((cascade_irq = cpm2_get_irq()) >= 0)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
static void __init sbc8560_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np = NULL;
#ifdef CONFIG_CPM2
int irq;
#endif
np = of_find_node_by_type(np, "open-pic");
if (!np) {
printk(KERN_ERR "Could not find open-pic node\n");
return;
}
if (of_address_to_resource(np, 0, &r)) {
printk(KERN_ERR "Could not map mpic register space\n");
of_node_put(np);
return;
}
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY | MPIC_WANTS_RESET | MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_init(mpic);
#ifdef CONFIG_CPM2
np = of_find_compatible_node(NULL, NULL, "fsl,cpm2-pic");
if (np == NULL) {
printk(KERN_ERR "PIC init: can not find fsl,cpm2-pic node\n");
return;
}
irq = irq_of_parse_and_map(np, 0);
cpm2_pic_init(np);
of_node_put(np);
irq_set_chained_handler(irq, cpm2_cascade);
#endif
}
static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(sbc8560_pins); i++) {
const struct cpm_pin *pin = &sbc8560_pins[i];
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
static void __init sbc8560_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("sbc8560_setup_arch()", 0);
#ifdef CONFIG_CPM2
cpm2_reset();
init_ioports();
#endif
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8540-pci")
fsl_add_bridge(np, 1);
#endif
}
static void sbc8560_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Wind River\n");
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init sbc8560_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "SBC8560");
}
static int __init sbc8560_rtc_init(void)
{
struct device_node *np;
struct resource res;
struct platform_device *rtc_dev;
np = of_find_compatible_node(NULL, NULL, "m48t59");
if (np == NULL) {
printk("No RTC in DTB. Has it been eaten by wild dogs?\n");
return -ENODEV;
}
of_address_to_resource(np, 0, &res);
of_node_put(np);
printk("Found RTC (m48t59) at i/o 0x%x\n", res.start);
rtc_dev = platform_device_register_simple("rtc-m48t59", 0, &res, 1);
if (IS_ERR(rtc_dev)) {
printk("Registering sbc8560 RTC device failed\n");
return PTR_ERR(rtc_dev);
}
return 0;
}
static int __init sbc8560_bdrstcr_init(void)
{
struct device_node *np;
struct resource res;
np = of_find_compatible_node(NULL, NULL, "wrs,sbc8560-brstcr");
if (np == NULL) {
printk(KERN_WARNING "sbc8560: No board specific RSTCR in DTB.\n");
return -ENODEV;
}
of_address_to_resource(np, 0, &res);
printk(KERN_INFO "sbc8560: Found BRSTCR at %pR\n", &res);
brstcr = ioremap(res.start, resource_size(&res));
if(!brstcr)
printk(KERN_WARNING "sbc8560: ioremap of brstcr failed.\n");
of_node_put(np);
return 0;
}
void sbc8560_rstcr_restart(char * cmd)
{
local_irq_disable();
if(brstcr)
clrbits8(brstcr, 0x80);
while(1);
}
