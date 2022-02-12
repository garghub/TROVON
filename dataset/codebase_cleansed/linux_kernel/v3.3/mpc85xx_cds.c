static int mpc85xx_exclude_device(struct pci_controller *hose,
u_char bus, u_char devfn)
{
if ((bus == 1) && (PCI_SLOT(devfn) == ARCADIA_2ND_BRIDGE_IDSEL))
return PCIBIOS_DEVICE_NOT_FOUND;
if ((bus == 0) && (PCI_SLOT(devfn) == ARCADIA_2ND_BRIDGE_IDSEL))
return PCIBIOS_DEVICE_NOT_FOUND;
else
return PCIBIOS_SUCCESSFUL;
}
static void mpc85xx_cds_restart(char *cmd)
{
struct pci_dev *dev;
u_char tmp;
if ((dev = pci_get_device(PCI_VENDOR_ID_VIA, PCI_DEVICE_ID_VIA_82C686,
NULL))) {
pci_read_config_byte(dev, 0x47, &tmp);
pci_write_config_byte(dev, 0x47, tmp | 1);
pci_read_config_byte(dev, 0x47, &tmp);
pci_dev_put(dev);
}
fsl_rstcr_restart(NULL);
}
static void __init mpc85xx_cds_pci_irq_fixup(struct pci_dev *dev)
{
u_char c;
if (dev->vendor == PCI_VENDOR_ID_VIA) {
switch (dev->device) {
case PCI_DEVICE_ID_VIA_82C586_1:
pci_read_config_byte(dev, 0x40, &c);
c |= 0x03;
pci_write_config_byte(dev, 0x40, c);
dev->irq = 14;
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, dev->irq);
break;
case PCI_DEVICE_ID_VIA_82C586_2:
if (PCI_FUNC(dev->devfn) == 3)
dev->irq = 11;
else
dev->irq = 10;
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, dev->irq);
default:
break;
}
}
}
static void __devinit skip_fake_bridge(struct pci_dev *dev)
{
dev->hdr_type = 0x7f;
}
static void mpc85xx_8259_cascade_handler(unsigned int irq,
struct irq_desc *desc)
{
unsigned int cascade_irq = i8259_irq();
if (cascade_irq != NO_IRQ)
generic_handle_irq(cascade_irq);
handle_fasteoi_irq(irq, desc);
}
static irqreturn_t mpc85xx_8259_cascade_action(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static void __init mpc85xx_cds_pic_init(void)
{
struct mpic *mpic;
mpic = mpic_alloc(NULL, 0,
MPIC_WANTS_RESET | MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static int mpc85xx_cds_8259_attach(void)
{
int ret;
struct device_node *np = NULL;
struct device_node *cascade_node = NULL;
int cascade_irq;
for_each_node_by_type(np, "interrupt-controller")
if (of_device_is_compatible(np, "chrp,iic")) {
cascade_node = np;
break;
}
if (cascade_node == NULL) {
printk(KERN_DEBUG "Could not find i8259 PIC\n");
return -ENODEV;
}
cascade_irq = irq_of_parse_and_map(cascade_node, 0);
if (cascade_irq == NO_IRQ) {
printk(KERN_ERR "Failed to map cascade interrupt\n");
return -ENXIO;
}
i8259_init(cascade_node, 0);
of_node_put(cascade_node);
if ((ret = setup_irq(cascade_irq, &mpc85xxcds_8259_irqaction))) {
printk(KERN_ERR "Failed to setup cascade interrupt\n");
return ret;
}
irq_set_handler(cascade_irq, mpc85xx_8259_cascade_handler);
return 0;
}
static void __init mpc85xx_cds_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc85xx_cds_setup_arch()", 0);
cadmus = ioremap(CADMUS_BASE, CADMUS_SIZE);
cds_pci_slot = ((cadmus[CM_CSR] >> 6) & 0x3) + 1;
if (ppc_md.progress) {
char buf[40];
snprintf(buf, 40, "CDS Version = 0x%x in slot %d\n",
cadmus[CM_VER], cds_pci_slot);
ppc_md.progress(buf, 0);
}
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0x8000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
}
}
ppc_md.pci_irq_fixup = mpc85xx_cds_pci_irq_fixup;
ppc_md.pci_exclude_device = mpc85xx_exclude_device;
#endif
}
static void mpc85xx_cds_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Freescale Semiconductor\n");
seq_printf(m, "Machine\t\t: MPC85xx CDS (0x%x)\n", cadmus[CM_VER]);
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init mpc85xx_cds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC85xxCDS");
}
