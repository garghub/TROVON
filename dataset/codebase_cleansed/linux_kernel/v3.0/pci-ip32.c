static irqreturn_t macepci_error(int irq, void *dev)
{
char s;
unsigned int flags = mace->pci.error;
unsigned int addr = mace->pci.error_addr;
if (flags & MACEPCI_ERROR_MEMORY_ADDR)
s = 'M';
else if (flags & MACEPCI_ERROR_CONFIG_ADDR)
s = 'C';
else
s = 'X';
if (flags & MACEPCI_ERROR_MASTER_ABORT) {
printk("MACEPCI: Master abort at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_MASTER_ABORT;
}
if (flags & MACEPCI_ERROR_TARGET_ABORT) {
printk("MACEPCI: Target abort at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_TARGET_ABORT;
}
if (flags & MACEPCI_ERROR_DATA_PARITY_ERR) {
printk("MACEPCI: Data parity error at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_DATA_PARITY_ERR;
}
if (flags & MACEPCI_ERROR_RETRY_ERR) {
printk("MACEPCI: Retry error at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_RETRY_ERR;
}
if (flags & MACEPCI_ERROR_ILLEGAL_CMD) {
printk("MACEPCI: Illegal command at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_ILLEGAL_CMD;
}
if (flags & MACEPCI_ERROR_SYSTEM_ERR) {
printk("MACEPCI: System error at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_SYSTEM_ERR;
}
if (flags & MACEPCI_ERROR_PARITY_ERR) {
printk("MACEPCI: Parity error at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_PARITY_ERR;
}
if (flags & MACEPCI_ERROR_OVERRUN) {
printk("MACEPCI: Overrun error at 0x%08x (%c)\n", addr, s);
flags &= ~MACEPCI_ERROR_OVERRUN;
}
if (flags & MACEPCI_ERROR_SIG_TABORT) {
printk("MACEPCI: Signaled target abort (clearing)\n");
flags &= ~MACEPCI_ERROR_SIG_TABORT;
}
if (flags & MACEPCI_ERROR_INTERRUPT_TEST) {
printk("MACEPCI: Interrupt test triggered (clearing)\n");
flags &= ~MACEPCI_ERROR_INTERRUPT_TEST;
}
mace->pci.error = flags;
return IRQ_HANDLED;
}
static int __init mace_init(void)
{
PCIBIOS_MIN_IO = 0x1000;
mace->pci.error_addr = 0;
mace->pci.error = 0;
mace->pci.control = 0xff008500;
printk("MACE PCI rev %d\n", mace->pci.rev);
BUG_ON(request_irq(MACE_PCI_BRIDGE_IRQ, macepci_error, 0,
"MACE PCI error", NULL));
iomem_resource.end = mace_pci_mem_resource.end;
ioport_resource = mace_pci_io_resource;
register_pci_controller(&mace_pci_controller);
return 0;
}
