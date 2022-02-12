static void xlpii_usb_ack(struct irq_data *data)
{
u64 port_addr;
switch (data->irq) {
case PIC_2XX_XHCI_0_IRQ:
port_addr = nlm_xlpii_get_usb_regbase(0, 1);
break;
case PIC_2XX_XHCI_1_IRQ:
port_addr = nlm_xlpii_get_usb_regbase(0, 2);
break;
case PIC_2XX_XHCI_2_IRQ:
port_addr = nlm_xlpii_get_usb_regbase(0, 3);
break;
default:
pr_err("No matching USB irq!\n");
return;
}
nlm_write_usb_reg(port_addr, XLPII_USB3_INT_REG, 0xffffffff);
}
static void nlm_xlpii_usb_hw_reset(int node, int port)
{
u64 port_addr, xhci_base, pci_base;
void __iomem *corebase;
u32 val;
port_addr = nlm_xlpii_get_usb_regbase(node, port);
val = nlm_read_usb_reg(port_addr, XLPII_USB_PHY_LOS_LV);
val &= ~(0x3f << XLPII_FSEL);
val |= (0x27 << XLPII_FSEL);
nlm_write_usb_reg(port_addr, XLPII_USB_PHY_LOS_LV, val);
val = nlm_read_usb_reg(port_addr, XLPII_USB_RFCLK_REG);
val |= (1 << XLPII_VVLD);
nlm_write_usb_reg(port_addr, XLPII_USB_RFCLK_REG, val);
val = nlm_read_usb_reg(port_addr, XLPII_USB_PHY_TEST);
val &= (XLPII_ATERESET | XLPII_LOOPEN | XLPII_TESTPDHSP
| XLPII_TESTPDSSP | XLPII_TESTBURNIN);
nlm_write_usb_reg(port_addr, XLPII_USB_PHY_TEST, val);
val = XLPII_VAUXRST | XLPII_VCCRST | (1 << XLPII_NUM2PORT)
| (1 << XLPII_NUM3PORT) | XLPII_MS_CSYSREQ | XLPII_XS_CSYSREQ
| XLPII_RETENABLEN | XLPII_XHCIREV;
nlm_write_usb_reg(port_addr, XLPII_USB3_CTL_0, val);
nlm_write_usb_reg(port_addr, XLPII_USB3_INT_MASK, 0x00000001);
nlm_write_usb_reg(port_addr, XLPII_USB3_INT_REG, 0xffffffff);
udelay(2000);
pci_base = nlm_xlpii_get_usb_pcibase(node, port);
xhci_base = nlm_read_usb_reg(pci_base, 0x4) & ~0xf;
corebase = ioremap(xhci_base, 0x10000);
if (!corebase)
return;
writel(0x240002, corebase + 0xc2c0);
val = readl(corebase + 0xc110);
val &= ~(0x3 << 12);
val |= (1 << 12);
writel(val, corebase + 0xc110);
udelay(100);
val = readl(corebase + 0xc200);
val &= ~(1 << 6);
writel(val, corebase + 0xc200);
udelay(100);
val = readl(corebase + 0xc2c0);
val &= ~(1 << 17);
writel(val, corebase + 0xc2c0);
iounmap(corebase);
}
static int __init nlm_platform_xlpii_usb_init(void)
{
if (!cpu_is_xlpii())
return 0;
pr_info("Initializing 2XX USB Interface\n");
nlm_xlpii_usb_hw_reset(0, 1);
nlm_xlpii_usb_hw_reset(0, 2);
nlm_xlpii_usb_hw_reset(0, 3);
nlm_set_pic_extra_ack(0, PIC_2XX_XHCI_0_IRQ, xlpii_usb_ack);
nlm_set_pic_extra_ack(0, PIC_2XX_XHCI_1_IRQ, xlpii_usb_ack);
nlm_set_pic_extra_ack(0, PIC_2XX_XHCI_2_IRQ, xlpii_usb_ack);
return 0;
}
static void nlm_usb_fixup_final(struct pci_dev *dev)
{
dev->dev.dma_mask = &xlp_usb_dmamask;
dev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
switch (dev->devfn) {
case 0x21:
dev->irq = PIC_2XX_XHCI_0_IRQ;
break;
case 0x22:
dev->irq = PIC_2XX_XHCI_1_IRQ;
break;
case 0x23:
dev->irq = PIC_2XX_XHCI_2_IRQ;
break;
}
}
