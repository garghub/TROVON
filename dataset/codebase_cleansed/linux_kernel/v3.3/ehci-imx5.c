int mx51_initialize_usb_hw(int port, unsigned int flags)
{
unsigned int v;
void __iomem *usb_base;
void __iomem *usbotg_base;
void __iomem *usbother_base;
int ret = 0;
usb_base = ioremap(MX51_USB_OTG_BASE_ADDR, SZ_4K);
if (!usb_base) {
printk(KERN_ERR "%s(): ioremap failed\n", __func__);
return -ENOMEM;
}
switch (port) {
case 0:
usbotg_base = usb_base + MXC_OTG_OFFSET;
break;
case 1:
usbotg_base = usb_base + MXC_H1_OFFSET;
break;
case 2:
usbotg_base = usb_base + MXC_H2_OFFSET;
break;
default:
printk(KERN_ERR"%s no such port %d\n", __func__, port);
ret = -ENOENT;
goto error;
}
usbother_base = usb_base + MX5_USBOTHER_REGS_OFFSET;
switch (port) {
case 0:
if (flags & MXC_EHCI_INTERNAL_PHY) {
v = __raw_readl(usbother_base + MXC_USB_PHY_CTR_FUNC_OFFSET);
if (flags & MXC_EHCI_POWER_PINS_ENABLED) {
v |= MXC_OTG_PHYCTRL_OC_DIS_BIT;
} else {
v &= ~MXC_OTG_PHYCTRL_OC_DIS_BIT;
}
__raw_writel(v, usbother_base + MXC_USB_PHY_CTR_FUNC_OFFSET);
v = __raw_readl(usbother_base + MXC_USBCTRL_OFFSET);
if (flags & MXC_EHCI_WAKEUP_ENABLED)
v |= MXC_OTG_UCTRL_OWIE_BIT;
else
v &= ~MXC_OTG_UCTRL_OWIE_BIT;
if (flags & MXC_EHCI_POWER_PINS_ENABLED)
v |= MXC_OTG_UCTRL_OPM_BIT;
else
v &= ~MXC_OTG_UCTRL_OPM_BIT;
__raw_writel(v, usbother_base + MXC_USBCTRL_OFFSET);
}
break;
case 1:
v = __raw_readl(usbother_base + MXC_USBCTRL_OFFSET);
if (flags & MXC_EHCI_WAKEUP_ENABLED) {
v |= (MXC_H1_UCTRL_H1WIE_BIT | MXC_H1_UCTRL_H1UIE_BIT);
} else {
v &= ~(MXC_H1_UCTRL_H1WIE_BIT | MXC_H1_UCTRL_H1UIE_BIT);
}
if (flags & MXC_EHCI_POWER_PINS_ENABLED)
v &= ~MXC_H1_UCTRL_H1PM_BIT;
else
v |= MXC_H1_UCTRL_H1PM_BIT;
__raw_writel(v, usbother_base + MXC_USBCTRL_OFFSET);
v = __raw_readl(usbother_base + MXC_USB_PHY_CTR_FUNC_OFFSET);
if (flags & MXC_EHCI_POWER_PINS_ENABLED)
v &= ~MXC_H1_OC_DIS_BIT;
else
v |= MXC_H1_OC_DIS_BIT;
__raw_writel(v, usbother_base + MXC_USB_PHY_CTR_FUNC_OFFSET);
v = __raw_readl(usbotg_base + MXC_USBCMD_OFFSET);
if (flags & MXC_EHCI_ITC_NO_THRESHOLD)
v &= MXC_UCMD_ITC_NO_THRESHOLD_MASK;
__raw_writel(v, usbotg_base + MXC_USBCMD_OFFSET);
break;
case 2:
v = __raw_readl(usbother_base + MXC_USBH2CTRL_OFFSET);
if (flags & MXC_EHCI_WAKEUP_ENABLED) {
v |= (MXC_H2_UCTRL_H2WIE_BIT | MXC_H2_UCTRL_H2UIE_BIT);
} else {
v &= ~(MXC_H2_UCTRL_H2WIE_BIT | MXC_H2_UCTRL_H2UIE_BIT);
}
if (flags & MXC_EHCI_POWER_PINS_ENABLED)
v &= ~MXC_H2_UCTRL_H2PM_BIT;
else
v |= MXC_H2_UCTRL_H2PM_BIT;
__raw_writel(v, usbother_base + MXC_USBH2CTRL_OFFSET);
break;
}
error:
iounmap(usb_base);
return ret;
}
