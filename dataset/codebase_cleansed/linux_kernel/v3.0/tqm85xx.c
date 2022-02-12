static void cpm2_cascade(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
int cascade_irq;
while ((cascade_irq = cpm2_get_irq()) >= 0)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
static void __init tqm85xx_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np;
#ifdef CONFIG_CPM2
int irq;
#endif
np = of_find_node_by_type(NULL, "open-pic");
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
if (irq == NO_IRQ) {
of_node_put(np);
printk(KERN_ERR "PIC init: got no IRQ for cpm cascade\n");
return;
}
cpm2_pic_init(np);
of_node_put(np);
irq_set_chained_handler(irq, cpm2_cascade);
#endif
}
static void __init tqm85xx_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("tqm85xx_setup_arch()", 0);
#ifdef CONFIG_CPM2
cpm2_reset();
#endif
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie")) {
struct resource rsrc;
if (!of_address_to_resource(np, 0, &rsrc)) {
if ((rsrc.start & 0xfffff) == 0x8000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
}
}
}
#endif
}
static void tqm85xx_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: TQ Components\n");
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static void __init tqm85xx_ti1520_fixup(struct pci_dev *pdev)
{
unsigned int val;
if (!machine_is(tqm85xx))
return;
dev_info(&pdev->dev, "Using TI 1520 fixup on TQM85xx\n");
pci_read_config_dword(pdev, 0x80, &val);
pci_write_config_dword(pdev, 0x80, val | (1 << 27));
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init tqm85xx_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
