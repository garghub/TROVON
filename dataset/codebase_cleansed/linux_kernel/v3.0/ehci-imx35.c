int mx35_initialize_usb_hw(int port, unsigned int flags)
{
unsigned int v;
v = readl(MX35_IO_ADDRESS(MX35_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));
switch (port) {
case 0:
v &= ~(MX35_OTG_SIC_MASK | MX35_OTG_PM_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX35_OTG_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX35_OTG_PM_BIT;
break;
case 1:
v &= ~(MX35_H1_SIC_MASK | MX35_H1_PM_BIT | MX35_H1_TLL_BIT |
MX35_H1_USBTE_BIT | MX35_H1_IPPUE_DOWN_BIT | MX35_H1_IPPUE_UP_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX35_H1_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX35_H1_PM_BIT;
if (!(flags & MXC_EHCI_TTL_ENABLED))
v |= MX35_H1_TLL_BIT;
if (flags & MXC_EHCI_INTERNAL_PHY)
v |= MX35_H1_USBTE_BIT;
if (flags & MXC_EHCI_IPPUE_DOWN)
v |= MX35_H1_IPPUE_DOWN_BIT;
if (flags & MXC_EHCI_IPPUE_UP)
v |= MX35_H1_IPPUE_UP_BIT;
break;
default:
return -EINVAL;
}
writel(v, MX35_IO_ADDRESS(MX35_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));
return 0;
}
