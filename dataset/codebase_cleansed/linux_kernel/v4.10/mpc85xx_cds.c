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
static int mpc85xx_cds_restart(struct notifier_block *this,
unsigned long mode, void *cmd)
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
return NOTIFY_DONE;
}
static int mpc85xx_cds_restart_register(void)
{
static struct notifier_block restart_handler;
restart_handler.notifier_call = mpc85xx_cds_restart;
restart_handler.priority = 192;
return register_restart_handler(&restart_handler);
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
static void skip_fake_bridge(struct pci_dev *dev)
{
dev->hdr_type = 0x7f;
}
void mpc85xx_cds_fixup_bus(struct pci_bus *bus)
{
struct pci_dev *dev = bus->self;
struct resource *res = bus->resource[0];
if (dev != NULL &&
dev->vendor == PCI_VENDOR_ID_IBM &&
dev->device == PCI_DEVICE_ID_IDT_TSI310) {
if (res) {
res->start = 0;
res->end = 0x1fff;
res->flags = IORESOURCE_IO;
pr_info("mpc85xx_cds: PCI bridge resource fixup applied\n");
pr_info("mpc85xx_cds: %pR\n", res);
}
}
fsl_pcibios_fixup_bus(bus);
}
static void mpc85xx_8259_cascade_handler(struct irq_desc *desc)
{
unsigned int cascade_irq = i8259_irq();
if (cascade_irq)
generic_handle_irq(cascade_irq);
handle_fasteoi_irq(desc);
}
static irqreturn_t mpc85xx_8259_cascade_action(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static void __init mpc85xx_cds_pic_init(void)
{
struct mpic *mpic;
mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
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
if (!cascade_irq) {
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
static void mpc85xx_cds_pci_assign_primary(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
if (fsl_pci_primary)
return;
np = of_find_node_by_name(NULL, "i8259");
while ((fsl_pci_primary = of_get_parent(np))) {
of_node_put(np);
np = fsl_pci_primary;
if ((of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie")) &&
of_device_is_available(np))
return;
}
#endif
}
static void __init mpc85xx_cds_setup_arch(void)
{
struct device_node *np;
int cds_pci_slot;
if (ppc_md.progress)
ppc_md.progress("mpc85xx_cds_setup_arch()", 0);
np = of_find_compatible_node(NULL, NULL, "fsl,mpc8548cds-fpga");
if (!np) {
pr_err("Could not find FPGA node.\n");
return;
}
cadmus = of_iomap(np, 0);
of_node_put(np);
if (!cadmus) {
pr_err("Fail to map FPGA area.\n");
return;
}
if (ppc_md.progress) {
char buf[40];
cds_pci_slot = ((in_8(&cadmus->cm_csr) >> 6) & 0x3) + 1;
snprintf(buf, 40, "CDS Version = 0x%x in slot %d\n",
in_8(&cadmus->cm_ver), cds_pci_slot);
ppc_md.progress(buf, 0);
}
#ifdef CONFIG_PCI
ppc_md.pci_irq_fixup = mpc85xx_cds_pci_irq_fixup;
ppc_md.pci_exclude_device = mpc85xx_exclude_device;
#endif
mpc85xx_cds_pci_assign_primary();
fsl_pci_assign_primary();
}
static void mpc85xx_cds_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Freescale Semiconductor\n");
seq_printf(m, "Machine\t\t: MPC85xx CDS (0x%x)\n",
in_8(&cadmus->cm_ver));
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init mpc85xx_cds_probe(void)
{
return of_machine_is_compatible("MPC85xxCDS");
}
