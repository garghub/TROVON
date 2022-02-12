int
tsi108_direct_write_config(struct pci_bus *bus, unsigned int devfunc,
int offset, int len, u32 val)
{
volatile unsigned char *cfg_addr;
struct pci_controller *hose = pci_bus_to_host(bus);
if (ppc_md.pci_exclude_device)
if (ppc_md.pci_exclude_device(hose, bus->number, devfunc))
return PCIBIOS_DEVICE_NOT_FOUND;
cfg_addr = (unsigned char *)(tsi_mk_config_addr(bus->number,
devfunc, offset) |
(offset & 0x03));
#ifdef DEBUG
printk("PCI CFG write : ");
printk("%d:0x%x:0x%x ", bus->number, devfunc, offset);
printk("%d ADDR=0x%08x ", len, (uint) cfg_addr);
printk("data = 0x%08x\n", val);
#endif
switch (len) {
case 1:
out_8((u8 *) cfg_addr, val);
break;
case 2:
out_le16((u16 *) cfg_addr, val);
break;
default:
out_le32((u32 *) cfg_addr, val);
break;
}
return PCIBIOS_SUCCESSFUL;
}
void tsi108_clear_pci_error(u32 pci_cfg_base)
{
u32 err_stat, err_addr, pci_stat;
err_stat = tsi108_read_reg(TSI108_PB_OFFSET + TSI108_PB_ERRCS);
err_addr = tsi108_read_reg(TSI108_PB_OFFSET + TSI108_PB_AERR);
if (err_stat & TSI108_PB_ERRCS_ES) {
tsi108_write_reg(TSI108_PB_OFFSET + TSI108_PB_ERRCS,
TSI108_PB_ERRCS_ES);
tsi108_write_reg(TSI108_PB_OFFSET + TSI108_PB_ISR,
TSI108_PB_ISR_PBS_RD_ERR);
if ((err_addr & 0xFF000000) == pci_cfg_base) {
pci_stat =
tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_CSR);
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_CSR,
pci_stat);
}
}
return;
}
int
tsi108_direct_read_config(struct pci_bus *bus, unsigned int devfn, int offset,
int len, u32 * val)
{
volatile unsigned char *cfg_addr;
struct pci_controller *hose = pci_bus_to_host(bus);
u32 temp;
if (ppc_md.pci_exclude_device)
if (ppc_md.pci_exclude_device(hose, bus->number, devfn))
return PCIBIOS_DEVICE_NOT_FOUND;
cfg_addr = (unsigned char *)(tsi_mk_config_addr(bus->number,
devfn,
offset) | (offset &
0x03));
switch (len) {
case 1:
__tsi108_read_pci_config(temp, cfg_addr, "lbzx");
break;
case 2:
__tsi108_read_pci_config(temp, cfg_addr, "lhbrx");
break;
default:
__tsi108_read_pci_config(temp, cfg_addr, "lwbrx");
break;
}
*val = temp;
#ifdef DEBUG
if ((0xFFFFFFFF != temp) && (0xFFFF != temp) && (0xFF != temp)) {
printk("PCI CFG read : ");
printk("%d:0x%x:0x%x ", bus->number, devfn, offset);
printk("%d ADDR=0x%08x ", len, (uint) cfg_addr);
printk("data = 0x%x\n", *val);
}
#endif
return PCIBIOS_SUCCESSFUL;
}
void tsi108_clear_pci_cfg_error(void)
{
tsi108_clear_pci_error(tsi108_pci_cfg_phys);
}
int __init tsi108_setup_pci(struct device_node *dev, u32 cfg_phys, int primary)
{
int len;
struct pci_controller *hose;
struct resource rsrc;
const int *bus_range;
int has_address = 0;
tsi108_pci_cfg_base = (u32)ioremap(cfg_phys, TSI108_PCI_CFG_SIZE);
tsi108_pci_cfg_phys = cfg_phys;
DBG("TSI_PCI: %s tsi108_pci_cfg_base=0x%x\n", __func__,
tsi108_pci_cfg_base);
has_address = (of_address_to_resource(dev, 0, &rsrc) == 0);
bus_range = of_get_property(dev, "bus-range", &len);
if (bus_range == NULL || len < 2 * sizeof(int)) {
printk(KERN_WARNING "Can't get bus-range for %s, assume"
" bus 0\n", dev->full_name);
}
hose = pcibios_alloc_controller(dev);
if (!hose) {
printk("PCI Host bridge init failed\n");
return -ENOMEM;
}
hose->first_busno = bus_range ? bus_range[0] : 0;
hose->last_busno = bus_range ? bus_range[1] : 0xff;
(hose)->ops = &tsi108_direct_pci_ops;
printk(KERN_INFO "Found tsi108 PCI host bridge at 0x%08x. "
"Firmware bus number: %d->%d\n",
rsrc.start, hose->first_busno, hose->last_busno);
pci_process_bridge_OF_ranges(hose, dev, primary);
return 0;
}
static void tsi108_pci_int_mask(u_int irq)
{
u_int irp_cfg;
int int_line = (irq - IRQ_PCI_INTAD_BASE);
irp_cfg = tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL);
mb();
irp_cfg |= (1 << int_line);
irp_cfg &= ~(3 << (8 + (int_line * 2)));
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL, irp_cfg);
mb();
irp_cfg = tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL);
}
static void tsi108_pci_int_unmask(u_int irq)
{
u_int irp_cfg;
int int_line = (irq - IRQ_PCI_INTAD_BASE);
irp_cfg = tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL);
mb();
irp_cfg &= ~(1 << int_line);
irp_cfg |= (3 << (8 + (int_line * 2)));
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL, irp_cfg);
mb();
}
static void init_pci_source(void)
{
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL,
0x0000ff00);
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_ENABLE,
TSI108_PCI_IRP_ENABLE_P_INT);
mb();
}
static inline unsigned int get_pci_source(void)
{
u_int temp = 0;
int irq = -1;
int i;
u_int pci_irp_stat;
static int mask = 0;
pci_irp_stat = tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_STAT);
mb();
if (pci_irp_stat & TSI108_PCI_IRP_STAT_P_INT) {
temp =
tsi108_read_reg(TSI108_PCI_OFFSET +
TSI108_PCI_IRP_INTAD) & 0xf;
mb();
for (i = 0; i < 4; i++, mask++) {
if (temp & (1 << mask % 4)) {
irq = IRQ_PCI_INTA + mask % 4;
mask++;
break;
}
}
temp = tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_ENABLE);
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_ENABLE,
temp & ~TSI108_PCI_IRP_ENABLE_P_INT);
mb();
(void)tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_ENABLE);
mb();
}
#ifdef DEBUG
else {
printk("TSI108_PIC: error in TSI108_PCI_IRP_STAT\n");
pci_irp_stat =
tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_STAT);
temp =
tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_INTAD);
mb();
printk(">> stat=0x%08x intad=0x%08x ", pci_irp_stat, temp);
temp =
tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_CFG_CTL);
mb();
printk("cfg_ctl=0x%08x ", temp);
temp =
tsi108_read_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_ENABLE);
mb();
printk("irp_enable=0x%08x\n", temp);
}
#endif
return irq;
}
static void tsi108_pci_irq_unmask(struct irq_data *d)
{
tsi108_pci_int_unmask(d->irq);
tsi108_write_reg(TSI108_PCI_OFFSET + TSI108_PCI_IRP_ENABLE,
tsi108_read_reg(TSI108_PCI_OFFSET +
TSI108_PCI_IRP_ENABLE) |
TSI108_PCI_IRP_ENABLE_P_INT);
mb();
}
static void tsi108_pci_irq_mask(struct irq_data *d)
{
tsi108_pci_int_mask(d->irq);
}
static void tsi108_pci_irq_ack(struct irq_data *d)
{
tsi108_pci_int_mask(d->irq);
}
static int pci_irq_host_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
*out_hwirq = intspec[0];
*out_flags = IRQ_TYPE_LEVEL_HIGH;
return 0;
}
static int pci_irq_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{ unsigned int irq;
DBG("%s(%d, 0x%lx)\n", __func__, virq, hw);
if ((virq >= 1) && (virq <= 4)){
irq = virq + IRQ_PCI_INTAD_BASE - 1;
irq_set_status_flags(irq, IRQ_LEVEL);
irq_set_chip(irq, &tsi108_pci_irq);
}
return 0;
}
void __init tsi108_pci_int_init(struct device_node *node)
{
DBG("Tsi108_pci_int_init: initializing PCI interrupts\n");
pci_irq_host = irq_domain_add_legacy_isa(node, &pci_irq_domain_ops, NULL);
if (pci_irq_host == NULL) {
printk(KERN_ERR "pci_irq_host: failed to allocate irq domain!\n");
return;
}
init_pci_source();
}
void tsi108_irq_cascade(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int cascade_irq = get_pci_source();
if (cascade_irq != NO_IRQ)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
