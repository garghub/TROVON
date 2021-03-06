int mx25_initialize_usb_hw(int port, unsigned int flags)
{
unsigned int v;
v = readl(MX25_IO_ADDRESS(MX25_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));
switch (port) {
case 0:
v &= ~(MX25_OTG_SIC_MASK | MX25_OTG_PM_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX25_OTG_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX25_OTG_PM_BIT;
break;
case 1:
v &= ~(MX25_H1_SIC_MASK | MX25_H1_PM_BIT | MX25_H1_TLL_BIT |
MX25_H1_USBTE_BIT | MX25_H1_IPPUE_DOWN_BIT | MX25_H1_IPPUE_UP_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX25_H1_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX25_H1_PM_BIT;
if (!(flags & MXC_EHCI_TTL_ENABLED))
v |= MX25_H1_TLL_BIT;
if (flags & MXC_EHCI_INTERNAL_PHY)
v |= MX25_H1_USBTE_BIT;
if (flags & MXC_EHCI_IPPUE_DOWN)
v |= MX25_H1_IPPUE_DOWN_BIT;
if (flags & MXC_EHCI_IPPUE_UP)
v |= MX25_H1_IPPUE_UP_BIT;
break;
default:
return -EINVAL;
}
writel(v, MX25_IO_ADDRESS(MX25_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));
return 0;
}
