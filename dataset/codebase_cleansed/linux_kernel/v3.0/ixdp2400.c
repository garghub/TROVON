static void __init ixdp2400_timer_init(void)
{
int numerator, denominator;
int denom_array[] = {2, 4, 8, 16, 1, 2, 4, 8};
numerator = (*(IXDP2400_CPLD_SYS_CLK_M) & 0xFF) *2;
denominator = denom_array[(*(IXDP2400_CPLD_SYS_CLK_N) & 0x7)];
ixp2000_init_time(((3125000 * numerator) / (denominator)) / 2);
}
void __init ixdp2400_pci_preinit(void)
{
ixp2000_reg_write(IXP2000_PCI_ADDR_EXT, 0x00100000);
ixp2000_pci_preinit();
pcibios_setup("firmware");
}
int ixdp2400_pci_setup(int nr, struct pci_sys_data *sys)
{
sys->mem_offset = 0xe0000000;
ixp2000_pci_setup(nr, sys);
return 1;
}
static int __init ixdp2400_pci_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
if (ixdp2x00_master_npu()) {
if(!dev->bus->self) {
if(dev->devfn == IXDP2X00_SLAVE_NPU_DEVFN )
return IRQ_IXDP2400_INGRESS_NPU;
return -1;
}
if(dev->bus->self->devfn == IXDP2X00_PMC_DEVFN &&
dev->bus->parent->self->devfn == IXDP2X00_P2P_DEVFN &&
!dev->bus->parent->self->bus->parent)
return IRQ_IXDP2400_PMC;
if(dev->bus->self->devfn == IXDP2X00_P2P_DEVFN) {
switch(dev->devfn) {
case IXDP2400_MASTER_ENET_DEVFN:
return IRQ_IXDP2400_ENET;
case IXDP2400_MEDIA_DEVFN:
return IRQ_IXDP2400_MEDIA_PCI;
case IXDP2400_SWITCH_FABRIC_DEVFN:
return IRQ_IXDP2400_SF_PCI;
case IXDP2X00_PMC_DEVFN:
return IRQ_IXDP2400_PMC;
}
}
return -1;
} else return IRQ_IXP2000_PCIB;
}
static void ixdp2400_pci_postinit(void)
{
struct pci_dev *dev;
if (ixdp2x00_master_npu()) {
dev = pci_get_bus_and_slot(1, IXDP2400_SLAVE_ENET_DEVFN);
pci_remove_bus_device(dev);
pci_dev_put(dev);
} else {
dev = pci_get_bus_and_slot(1, IXDP2400_MASTER_ENET_DEVFN);
pci_remove_bus_device(dev);
pci_dev_put(dev);
ixdp2x00_slave_pci_postinit();
}
}
int __init ixdp2400_pci_init(void)
{
if (machine_is_ixdp2400())
pci_common_init(&ixdp2400_pci);
return 0;
}
void __init ixdp2400_init_irq(void)
{
ixdp2x00_init_irq(IXDP2400_CPLD_INT_STAT, IXDP2400_CPLD_INT_MASK, IXDP2400_NR_IRQS);
}
