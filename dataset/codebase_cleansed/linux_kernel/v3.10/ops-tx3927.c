static int mkaddr(struct pci_bus *bus, unsigned char devfn, unsigned char where)
{
if (bus->parent == NULL &&
devfn >= PCI_DEVFN(TX3927_PCIC_MAX_DEVNU, 0))
return -1;
tx3927_pcicptr->ica =
((bus->number & 0xff) << 0x10) |
((devfn & 0xff) << 0x08) |
(where & 0xfc) | (bus->parent ? 1 : 0);
tx3927_pcicptr->pcistat |= PCI_STATUS_REC_MASTER_ABORT;
tx3927_pcicptr->pcistatim &= ~PCI_STATUS_REC_MASTER_ABORT;
return 0;
}
static inline int check_abort(void)
{
if (tx3927_pcicptr->pcistat & PCI_STATUS_REC_MASTER_ABORT) {
tx3927_pcicptr->pcistat |= PCI_STATUS_REC_MASTER_ABORT;
tx3927_pcicptr->pcistatim |= PCI_STATUS_REC_MASTER_ABORT;
iob();
return PCIBIOS_DEVICE_NOT_FOUND;
}
return PCIBIOS_SUCCESSFUL;
}
static int tx3927_pci_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 * val)
{
if (mkaddr(bus, devfn, where)) {
*val = 0xffffffff;
return PCIBIOS_DEVICE_NOT_FOUND;
}
switch (size) {
case 1:
*val = *(volatile u8 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 3));
break;
case 2:
*val = le16_to_cpu(*(volatile u16 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 3)));
break;
case 4:
*val = le32_to_cpu(tx3927_pcicptr->icd);
break;
}
return check_abort();
}
static int tx3927_pci_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
if (mkaddr(bus, devfn, where))
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1:
*(volatile u8 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 3)) = val;
break;
case 2:
*(volatile u16 *) ((unsigned long) & tx3927_pcicptr->icd | (where & 2)) =
cpu_to_le16(val);
break;
case 4:
tx3927_pcicptr->icd = cpu_to_le32(val);
}
return check_abort();
}
void __init tx3927_pcic_setup(struct pci_controller *channel,
unsigned long sdram_size, int extarb)
{
unsigned long flags;
unsigned long io_base =
channel->io_resource->start + mips_io_port_base - IO_BASE;
unsigned long io_size =
channel->io_resource->end - channel->io_resource->start;
unsigned long io_pciaddr =
channel->io_resource->start - channel->io_offset;
unsigned long mem_base =
channel->mem_resource->start;
unsigned long mem_size =
channel->mem_resource->end - channel->mem_resource->start;
unsigned long mem_pciaddr =
channel->mem_resource->start - channel->mem_offset;
printk(KERN_INFO "TX3927 PCIC -- DID:%04x VID:%04x RID:%02x Arbiter:%s",
tx3927_pcicptr->did, tx3927_pcicptr->vid,
tx3927_pcicptr->rid,
extarb ? "External" : "Internal");
channel->pci_ops = &tx3927_pci_ops;
local_irq_save(flags);
tx3927_pcicptr->lbc = TX3927_PCIC_LBC_EPCAD;
#ifdef __BIG_ENDIAN
tx3927_pcicptr->lbc |= TX3927_PCIC_LBC_IBSE |
TX3927_PCIC_LBC_TIBSE |
TX3927_PCIC_LBC_TMFBSE | TX3927_PCIC_LBC_MSDSE;
#endif
tx3927_pcicptr->iomas = ~(io_size - 1);
tx3927_pcicptr->ilbioma = io_base;
tx3927_pcicptr->ipbioma = io_pciaddr;
tx3927_pcicptr->mmas = ~(mem_size - 1);
tx3927_pcicptr->ilbmma = mem_base;
tx3927_pcicptr->ipbmma = mem_pciaddr;
tx3927_pcicptr->iobas = 0xffffffff;
tx3927_pcicptr->ioba = 0;
tx3927_pcicptr->tlbioma = 0;
tx3927_pcicptr->mbas = ~(sdram_size - 1);
tx3927_pcicptr->mba = 0;
tx3927_pcicptr->tlbmma = 0;
tx3927_pcicptr->lbc |= TX3927_PCIC_LBC_ILMDE | TX3927_PCIC_LBC_ILIDE;
tx3927_pcicptr->lbstat = TX3927_PCIC_LBIM_ALL;
tx3927_pcicptr->lbim = TX3927_PCIC_LBIM_ALL;
tx3927_pcicptr->pcistat = TX3927_PCIC_PCISTATIM_ALL;
tx3927_pcicptr->pcistatim = TX3927_PCIC_PCISTATIM_ALL;
tx3927_pcicptr->il = TX3927_IR_PCI;
tx3927_pcicptr->tc = TX3927_PCIC_TC_OF8E | TX3927_PCIC_TC_IF8E;
if (!extarb)
tx3927_pcicptr->pbapmc = TX3927_PCIC_PBAPMC_PBAEN;
tx3927_pcicptr->pcicmd = PCI_COMMAND_MASTER |
PCI_COMMAND_MEMORY |
PCI_COMMAND_IO |
PCI_COMMAND_PARITY | PCI_COMMAND_SERR;
local_irq_restore(flags);
}
static irqreturn_t tx3927_pcierr_interrupt(int irq, void *dev_id)
{
struct pt_regs *regs = get_irq_regs();
if (txx9_pci_err_action != TXX9_PCI_ERR_IGNORE) {
printk(KERN_WARNING "PCI error interrupt at 0x%08lx.\n",
regs->cp0_epc);
printk(KERN_WARNING "pcistat:%02x, lbstat:%04lx\n",
tx3927_pcicptr->pcistat, tx3927_pcicptr->lbstat);
}
if (txx9_pci_err_action != TXX9_PCI_ERR_PANIC) {
tx3927_pcicptr->pcistat |= TX3927_PCIC_PCISTATIM_ALL;
tx3927_pcicptr->istat = TX3927_PCIC_IIM_ALL;
tx3927_pcicptr->tstat = TX3927_PCIC_TIM_ALL;
tx3927_pcicptr->lbstat = TX3927_PCIC_LBIM_ALL;
return IRQ_HANDLED;
}
console_verbose();
panic("PCI error.");
}
void __init tx3927_setup_pcierr_irq(void)
{
if (request_irq(TXX9_IRQ_BASE + TX3927_IR_PCI,
tx3927_pcierr_interrupt,
0, "PCI error",
(void *)TX3927_PCIC_REG))
printk(KERN_WARNING "Failed to request irq for PCIERR\n");
}
