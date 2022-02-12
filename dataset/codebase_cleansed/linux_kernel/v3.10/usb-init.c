static void nlm_usb_intr_en(int node, int port)
{
uint32_t val;
uint64_t port_addr;
port_addr = nlm_get_usb_regbase(node, port);
val = nlm_read_usb_reg(port_addr, USB_INT_EN);
val = USB_CTRL_INTERRUPT_EN | USB_OHCI_INTERRUPT_EN |
USB_OHCI_INTERRUPT1_EN | USB_CTRL_INTERRUPT_EN |
USB_OHCI_INTERRUPT_EN | USB_OHCI_INTERRUPT2_EN;
nlm_write_usb_reg(port_addr, USB_INT_EN, val);
}
static void nlm_usb_hw_reset(int node, int port)
{
uint64_t port_addr;
uint32_t val;
port_addr = nlm_get_usb_regbase(node, port);
val = nlm_read_usb_reg(port_addr, USB_PHY_0);
val &= ~(USB_PHY_RESET | USB_PHY_PORT_RESET_0 | USB_PHY_PORT_RESET_1);
nlm_write_usb_reg(port_addr, USB_PHY_0, val);
mdelay(100);
val = nlm_read_usb_reg(port_addr, USB_CTL_0);
val &= ~(USB_CONTROLLER_RESET);
val |= 0x4;
nlm_write_usb_reg(port_addr, USB_CTL_0, val);
}
static int __init nlm_platform_usb_init(void)
{
pr_info("Initializing USB Interface\n");
nlm_usb_hw_reset(0, 0);
nlm_usb_hw_reset(0, 3);
nlm_usb_intr_en(0, 0);
nlm_usb_intr_en(0, 3);
return 0;
}
static void nlm_usb_fixup_final(struct pci_dev *dev)
{
dev->dev.dma_mask = &xlp_usb_dmamask;
dev->dev.coherent_dma_mask = DMA_BIT_MASK(64);
switch (dev->devfn) {
case 0x10:
dev->irq = PIC_EHCI_0_IRQ;
break;
case 0x11:
dev->irq = PIC_OHCI_0_IRQ;
break;
case 0x12:
dev->irq = PIC_OHCI_1_IRQ;
break;
case 0x13:
dev->irq = PIC_EHCI_1_IRQ;
break;
case 0x14:
dev->irq = PIC_OHCI_2_IRQ;
break;
case 0x15:
dev->irq = PIC_OHCI_3_IRQ;
break;
}
}
