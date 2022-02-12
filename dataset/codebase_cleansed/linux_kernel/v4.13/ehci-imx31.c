int mx31_initialize_usb_hw(int port, unsigned int flags)
{
unsigned int v;
v = readl(MX31_IO_ADDRESS(MX31_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));
switch (port) {
case 0:
v &= ~(MX31_OTG_SIC_MASK | MX31_OTG_PM_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX31_OTG_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX31_OTG_PM_BIT;
break;
case 1:
v &= ~(MX31_H1_SIC_MASK | MX31_H1_PM_BIT | MX31_H1_DT_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX31_H1_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX31_H1_PM_BIT;
if (!(flags & MXC_EHCI_TTL_ENABLED))
v |= MX31_H1_DT_BIT;
break;
case 2:
v &= ~(MX31_H2_SIC_MASK | MX31_H2_PM_BIT | MX31_H2_DT_BIT);
v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX31_H2_SIC_SHIFT;
if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
v |= MX31_H2_PM_BIT;
if (!(flags & MXC_EHCI_TTL_ENABLED))
v |= MX31_H2_DT_BIT;
break;
default:
return -EINVAL;
}
writel(v, MX31_IO_ADDRESS(MX31_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));
return 0;
}
