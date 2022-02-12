static int __init rc32434_pcibridge_init(void)
{
unsigned int pcicvalue, pcicdata = 0;
unsigned int dummyread, pcicntlval;
int loopCount;
unsigned int pci_config_addr;
pcicvalue = rc32434_pci->pcic;
pcicvalue = (pcicvalue >> PCIM_SHFT) & PCIM_BIT_LEN;
if (!((pcicvalue == PCIM_H_EA) ||
(pcicvalue == PCIM_H_IA_FIX) ||
(pcicvalue == PCIM_H_IA_RR))) {
pr_err("PCI init error!!!\n");
return -1;
}
pcicdata |= (PCI_CTL_IGM | PCI_CTL_EAP | PCI_CTL_EN);
rc32434_pci->pcic = pcicdata;
for (;;) {
pcicdata = rc32434_pci->pcis;
if (!(pcicdata & PCI_STAT_RIP))
break;
}
rc32434_pci->pcis = 0;
rc32434_pci->pcism = 0xFFFFFFFF;
rc32434_pci->pcidac = 0;
rc32434_pci->pcidas = 0;
rc32434_pci->pcidasm = 0x0000007F;
rc32434_pci_msg->pciiic = 0;
rc32434_pci_msg->pciiim = 0xFFFFFFFF;
rc32434_pci_msg->pciioic = 0;
rc32434_pci_msg->pciioim = 0;
rc32434_pci->pcilba[0].address = (unsigned int) (PCI_ADDR_START);
rc32434_pci->pcilba[0].mapping = (unsigned int) (PCI_ADDR_START);
rc32434_pci->pcilba[0].control =
(((SIZE_256MB & 0x1f) << PCI_LBAC_SIZE_BIT) | PCI_ENDIAN_FLAG);
dummyread = rc32434_pci->pcilba[0].control;
rc32434_pci->pcilba[1].address = 0x60000000;
rc32434_pci->pcilba[1].mapping = 0x60000000;
rc32434_pci->pcilba[1].control =
(((SIZE_256MB & 0x1f) << PCI_LBAC_SIZE_BIT) | PCI_ENDIAN_FLAG);
dummyread = rc32434_pci->pcilba[1].control;
rc32434_pci->pcilba[2].address = 0x18C00000;
rc32434_pci->pcilba[2].mapping = 0x18FFFFFF;
rc32434_pci->pcilba[2].control =
(((SIZE_4MB & 0x1f) << PCI_LBAC_SIZE_BIT) | PCI_ENDIAN_FLAG);
dummyread = rc32434_pci->pcilba[2].control;
rc32434_pci->pcilba[3].address = 0x18800000;
rc32434_pci->pcilba[3].mapping = 0x18800000;
rc32434_pci->pcilba[3].control =
((((SIZE_1MB & 0x1ff) << PCI_LBAC_SIZE_BIT) | PCI_LBAC_MSI) |
PCI_ENDIAN_FLAG);
dummyread = rc32434_pci->pcilba[3].control;
pci_config_addr = (unsigned int) (0x80000004);
for (loopCount = 0; loopCount < 24; loopCount++) {
rc32434_pci->pcicfga = pci_config_addr;
dummyread = rc32434_pci->pcicfga;
rc32434_pci->pcicfgd = korina_cnfg_regs[loopCount];
dummyread = rc32434_pci->pcicfgd;
pci_config_addr += 4;
}
rc32434_pci->pcitc =
(unsigned int) ((PCITC_RTIMER_VAL & 0xff) << PCI_TC_RTIMER_BIT) |
((PCITC_DTIMER_VAL & 0xff) << PCI_TC_DTIMER_BIT);
pcicntlval = rc32434_pci->pcic;
pcicntlval &= ~PCI_CTL_TNR;
rc32434_pci->pcic = pcicntlval;
pcicntlval = rc32434_pci->pcic;
return 0;
}
static int __init rc32434_pci_init(void)
{
void __iomem *io_map_base;
pr_info("PCI: Initializing PCI\n");
ioport_resource.start = rc32434_res_pci_io1.start;
ioport_resource.end = rc32434_res_pci_io1.end;
rc32434_pcibridge_init();
io_map_base = ioremap(rc32434_res_pci_io1.start,
resource_size(&rc32434_res_pci_io1));
if (!io_map_base)
return -ENOMEM;
rc32434_controller.io_map_base =
(unsigned long)io_map_base - rc32434_res_pci_io1.start;
register_pci_controller(&rc32434_controller);
rc32434_sync();
return 0;
}
