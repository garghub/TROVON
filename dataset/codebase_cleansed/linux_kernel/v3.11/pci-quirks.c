void sb800_prefetch(struct device *dev, int on)
{
u16 misc;
struct pci_dev *pdev = to_pci_dev(dev);
pci_read_config_word(pdev, 0x50, &misc);
if (on == 0)
pci_write_config_word(pdev, 0x50, misc & 0xfcff);
else
pci_write_config_word(pdev, 0x50, misc | 0x0300);
}
int usb_amd_find_chipset_info(void)
{
u8 rev = 0;
unsigned long flags;
struct amd_chipset_info info;
int ret;
spin_lock_irqsave(&amd_lock, flags);
if (amd_chipset.probe_count > 0) {
amd_chipset.probe_count++;
spin_unlock_irqrestore(&amd_lock, flags);
return amd_chipset.probe_result;
}
memset(&info, 0, sizeof(info));
spin_unlock_irqrestore(&amd_lock, flags);
info.smbus_dev = pci_get_device(PCI_VENDOR_ID_ATI, 0x4385, NULL);
if (info.smbus_dev) {
rev = info.smbus_dev->revision;
if (rev >= 0x40)
info.sb_type = 1;
else if (rev >= 0x30 && rev <= 0x3b)
info.sb_type = 3;
} else {
info.smbus_dev = pci_get_device(PCI_VENDOR_ID_AMD,
0x780b, NULL);
if (!info.smbus_dev) {
ret = 0;
goto commit;
}
rev = info.smbus_dev->revision;
if (rev >= 0x11 && rev <= 0x18)
info.sb_type = 2;
}
if (info.sb_type == 0) {
if (info.smbus_dev) {
pci_dev_put(info.smbus_dev);
info.smbus_dev = NULL;
}
ret = 0;
goto commit;
}
info.nb_dev = pci_get_device(PCI_VENDOR_ID_AMD, 0x9601, NULL);
if (info.nb_dev) {
info.nb_type = 1;
} else {
info.nb_dev = pci_get_device(PCI_VENDOR_ID_AMD, 0x1510, NULL);
if (info.nb_dev) {
info.nb_type = 2;
} else {
info.nb_dev = pci_get_device(PCI_VENDOR_ID_AMD,
0x9600, NULL);
if (info.nb_dev)
info.nb_type = 3;
}
}
ret = info.probe_result = 1;
printk(KERN_DEBUG "QUIRK: Enable AMD PLL fix\n");
commit:
spin_lock_irqsave(&amd_lock, flags);
if (amd_chipset.probe_count > 0) {
amd_chipset.probe_count++;
ret = amd_chipset.probe_result;
spin_unlock_irqrestore(&amd_lock, flags);
if (info.nb_dev)
pci_dev_put(info.nb_dev);
if (info.smbus_dev)
pci_dev_put(info.smbus_dev);
} else {
info.probe_count++;
amd_chipset = info;
spin_unlock_irqrestore(&amd_lock, flags);
}
return ret;
}
static void usb_amd_quirk_pll(int disable)
{
u32 addr, addr_low, addr_high, val;
u32 bit = disable ? 0 : 1;
unsigned long flags;
spin_lock_irqsave(&amd_lock, flags);
if (disable) {
amd_chipset.isoc_reqs++;
if (amd_chipset.isoc_reqs > 1) {
spin_unlock_irqrestore(&amd_lock, flags);
return;
}
} else {
amd_chipset.isoc_reqs--;
if (amd_chipset.isoc_reqs > 0) {
spin_unlock_irqrestore(&amd_lock, flags);
return;
}
}
if (amd_chipset.sb_type == 1 || amd_chipset.sb_type == 2) {
outb_p(AB_REG_BAR_LOW, 0xcd6);
addr_low = inb_p(0xcd7);
outb_p(AB_REG_BAR_HIGH, 0xcd6);
addr_high = inb_p(0xcd7);
addr = addr_high << 8 | addr_low;
outl_p(0x30, AB_INDX(addr));
outl_p(0x40, AB_DATA(addr));
outl_p(0x34, AB_INDX(addr));
val = inl_p(AB_DATA(addr));
} else if (amd_chipset.sb_type == 3) {
pci_read_config_dword(amd_chipset.smbus_dev,
AB_REG_BAR_SB700, &addr);
outl(AX_INDXC, AB_INDX(addr));
outl(0x40, AB_DATA(addr));
outl(AX_DATAC, AB_INDX(addr));
val = inl(AB_DATA(addr));
} else {
spin_unlock_irqrestore(&amd_lock, flags);
return;
}
if (disable) {
val &= ~0x08;
val |= (1 << 4) | (1 << 9);
} else {
val |= 0x08;
val &= ~((1 << 4) | (1 << 9));
}
outl_p(val, AB_DATA(addr));
if (!amd_chipset.nb_dev) {
spin_unlock_irqrestore(&amd_lock, flags);
return;
}
if (amd_chipset.nb_type == 1 || amd_chipset.nb_type == 3) {
addr = PCIE_P_CNTL;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_ADDR, addr);
pci_read_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, &val);
val &= ~(1 | (1 << 3) | (1 << 4) | (1 << 9) | (1 << 12));
val |= bit | (bit << 3) | (bit << 12);
val |= ((!bit) << 4) | ((!bit) << 9);
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, val);
addr = BIF_NB;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_ADDR, addr);
pci_read_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, &val);
val &= ~(1 << 8);
val |= bit << 8;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, val);
} else if (amd_chipset.nb_type == 2) {
addr = NB_PIF0_PWRDOWN_0;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_ADDR, addr);
pci_read_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, &val);
if (disable)
val &= ~(0x3f << 7);
else
val |= 0x3f << 7;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, val);
addr = NB_PIF0_PWRDOWN_1;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_ADDR, addr);
pci_read_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, &val);
if (disable)
val &= ~(0x3f << 7);
else
val |= 0x3f << 7;
pci_write_config_dword(amd_chipset.nb_dev,
NB_PCIE_INDX_DATA, val);
}
spin_unlock_irqrestore(&amd_lock, flags);
return;
}
void usb_amd_quirk_pll_disable(void)
{
usb_amd_quirk_pll(1);
}
void usb_amd_quirk_pll_enable(void)
{
usb_amd_quirk_pll(0);
}
void usb_amd_dev_put(void)
{
struct pci_dev *nb, *smbus;
unsigned long flags;
spin_lock_irqsave(&amd_lock, flags);
amd_chipset.probe_count--;
if (amd_chipset.probe_count > 0) {
spin_unlock_irqrestore(&amd_lock, flags);
return;
}
nb = amd_chipset.nb_dev;
smbus = amd_chipset.smbus_dev;
amd_chipset.nb_dev = NULL;
amd_chipset.smbus_dev = NULL;
amd_chipset.nb_type = 0;
amd_chipset.sb_type = 0;
amd_chipset.isoc_reqs = 0;
amd_chipset.probe_result = 0;
spin_unlock_irqrestore(&amd_lock, flags);
if (nb)
pci_dev_put(nb);
if (smbus)
pci_dev_put(smbus);
}
void uhci_reset_hc(struct pci_dev *pdev, unsigned long base)
{
pci_write_config_word(pdev, UHCI_USBLEGSUP, UHCI_USBLEGSUP_RWC);
outw(UHCI_USBCMD_HCRESET, base + UHCI_USBCMD);
mb();
udelay(5);
if (inw(base + UHCI_USBCMD) & UHCI_USBCMD_HCRESET)
dev_warn(&pdev->dev, "HCRESET not completed yet!\n");
outw(0, base + UHCI_USBINTR);
outw(0, base + UHCI_USBCMD);
}
int uhci_check_and_reset_hc(struct pci_dev *pdev, unsigned long base)
{
u16 legsup;
unsigned int cmd, intr;
pci_read_config_word(pdev, UHCI_USBLEGSUP, &legsup);
if (legsup & ~(UHCI_USBLEGSUP_RO | UHCI_USBLEGSUP_RWC)) {
dev_dbg(&pdev->dev, "%s: legsup = 0x%04x\n",
__func__, legsup);
goto reset_needed;
}
cmd = inw(base + UHCI_USBCMD);
if ((cmd & UHCI_USBCMD_RUN) || !(cmd & UHCI_USBCMD_CONFIGURE) ||
!(cmd & UHCI_USBCMD_EGSM)) {
dev_dbg(&pdev->dev, "%s: cmd = 0x%04x\n",
__func__, cmd);
goto reset_needed;
}
intr = inw(base + UHCI_USBINTR);
if (intr & (~UHCI_USBINTR_RESUME)) {
dev_dbg(&pdev->dev, "%s: intr = 0x%04x\n",
__func__, intr);
goto reset_needed;
}
return 0;
reset_needed:
dev_dbg(&pdev->dev, "Performing full reset\n");
uhci_reset_hc(pdev, base);
return 1;
}
static inline int io_type_enabled(struct pci_dev *pdev, unsigned int mask)
{
u16 cmd;
return !pci_read_config_word(pdev, PCI_COMMAND, &cmd) && (cmd & mask);
}
static void quirk_usb_handoff_uhci(struct pci_dev *pdev)
{
unsigned long base = 0;
int i;
if (!pio_enabled(pdev))
return;
for (i = 0; i < PCI_ROM_RESOURCE; i++)
if ((pci_resource_flags(pdev, i) & IORESOURCE_IO)) {
base = pci_resource_start(pdev, i);
break;
}
if (base)
uhci_check_and_reset_hc(pdev, base);
}
static int mmio_resource_enabled(struct pci_dev *pdev, int idx)
{
return pci_resource_start(pdev, idx) && mmio_enabled(pdev);
}
static void quirk_usb_handoff_ohci(struct pci_dev *pdev)
{
void __iomem *base;
u32 control;
u32 fminterval;
int cnt;
if (!mmio_resource_enabled(pdev, 0))
return;
base = pci_ioremap_bar(pdev, 0);
if (base == NULL)
return;
control = readl(base + OHCI_CONTROL);
#ifdef __hppa__
#define OHCI_CTRL_MASK (OHCI_CTRL_RWC | OHCI_CTRL_IR)
#else
#define OHCI_CTRL_MASK OHCI_CTRL_RWC
if (control & OHCI_CTRL_IR) {
int wait_time = 500;
writel(OHCI_INTR_OC, base + OHCI_INTRENABLE);
writel(OHCI_OCR, base + OHCI_CMDSTATUS);
while (wait_time > 0 &&
readl(base + OHCI_CONTROL) & OHCI_CTRL_IR) {
wait_time -= 10;
msleep(10);
}
if (wait_time <= 0)
dev_warn(&pdev->dev, "OHCI: BIOS handoff failed"
" (BIOS bug?) %08x\n",
readl(base + OHCI_CONTROL));
}
#endif
writel((u32) ~0, base + OHCI_INTRDISABLE);
if (control & OHCI_HCFS) {
writel(control & OHCI_CTRL_MASK, base + OHCI_CONTROL);
readl(base + OHCI_CONTROL);
msleep(50);
}
fminterval = readl(base + OHCI_FMINTERVAL);
writel(OHCI_HCR, base + OHCI_CMDSTATUS);
for (cnt = 30; cnt > 0; --cnt) {
if ((readl(base + OHCI_CMDSTATUS) & OHCI_HCR) == 0)
break;
udelay(1);
}
writel(fminterval, base + OHCI_FMINTERVAL);
iounmap(base);
}
static void ehci_bios_handoff(struct pci_dev *pdev,
void __iomem *op_reg_base,
u32 cap, u8 offset)
{
int try_handoff = 1, tried_handoff = 0;
if (pdev->vendor == 0x8086 && pdev->device == 0x283a) {
if (dmi_check_system(ehci_dmi_nohandoff_table))
try_handoff = 0;
}
if (try_handoff && (cap & EHCI_USBLEGSUP_BIOS)) {
dev_dbg(&pdev->dev, "EHCI: BIOS handoff\n");
#if 0
pci_read_config_dword(pdev, offset + EHCI_USBLEGCTLSTS, &val);
pci_write_config_dword(pdev, offset + EHCI_USBLEGCTLSTS,
val | EHCI_USBLEGCTLSTS_SOOE);
#endif
pci_write_config_byte(pdev, offset + 3, 1);
}
if (try_handoff) {
int msec = 1000;
while ((cap & EHCI_USBLEGSUP_BIOS) && (msec > 0)) {
tried_handoff = 1;
msleep(10);
msec -= 10;
pci_read_config_dword(pdev, offset, &cap);
}
}
if (cap & EHCI_USBLEGSUP_BIOS) {
if (try_handoff)
dev_warn(&pdev->dev, "EHCI: BIOS handoff failed"
" (BIOS bug?) %08x\n", cap);
pci_write_config_byte(pdev, offset + 2, 0);
}
pci_write_config_dword(pdev, offset + EHCI_USBLEGCTLSTS, 0);
if (tried_handoff)
writel(0, op_reg_base + EHCI_CONFIGFLAG);
}
static void quirk_usb_disable_ehci(struct pci_dev *pdev)
{
void __iomem *base, *op_reg_base;
u32 hcc_params, cap, val;
u8 offset, cap_length;
int wait_time, count = 256/4;
if (!mmio_resource_enabled(pdev, 0))
return;
base = pci_ioremap_bar(pdev, 0);
if (base == NULL)
return;
cap_length = readb(base);
op_reg_base = base + cap_length;
hcc_params = readl(base + EHCI_HCC_PARAMS);
offset = (hcc_params >> 8) & 0xff;
while (offset && --count) {
pci_read_config_dword(pdev, offset, &cap);
switch (cap & 0xff) {
case 1:
ehci_bios_handoff(pdev, op_reg_base, cap, offset);
break;
case 0:
cap = 0;
default:
dev_warn(&pdev->dev, "EHCI: unrecognized capability "
"%02x\n", cap & 0xff);
}
offset = (cap >> 8) & 0xff;
}
if (!count)
dev_printk(KERN_DEBUG, &pdev->dev, "EHCI: capability loop?\n");
val = readl(op_reg_base + EHCI_USBSTS);
if ((val & EHCI_USBSTS_HALTED) == 0) {
val = readl(op_reg_base + EHCI_USBCMD);
val &= ~EHCI_USBCMD_RUN;
writel(val, op_reg_base + EHCI_USBCMD);
wait_time = 2000;
do {
writel(0x3f, op_reg_base + EHCI_USBSTS);
udelay(100);
wait_time -= 100;
val = readl(op_reg_base + EHCI_USBSTS);
if ((val == ~(u32)0) || (val & EHCI_USBSTS_HALTED)) {
break;
}
} while (wait_time > 0);
}
writel(0, op_reg_base + EHCI_USBINTR);
writel(0x3f, op_reg_base + EHCI_USBSTS);
iounmap(base);
}
static int handshake(void __iomem *ptr, u32 mask, u32 done,
int wait_usec, int delay_usec)
{
u32 result;
do {
result = readl(ptr);
result &= mask;
if (result == done)
return 0;
udelay(delay_usec);
wait_usec -= delay_usec;
} while (wait_usec > 0);
return -ETIMEDOUT;
}
bool usb_is_intel_ppt_switchable_xhci(struct pci_dev *pdev)
{
return pdev->class == PCI_CLASS_SERIAL_USB_XHCI &&
pdev->vendor == PCI_VENDOR_ID_INTEL &&
pdev->device == PCI_DEVICE_ID_INTEL_PANTHERPOINT_XHCI;
}
bool usb_is_intel_lpt_switchable_xhci(struct pci_dev *pdev)
{
return pdev->class == PCI_CLASS_SERIAL_USB_XHCI &&
pdev->vendor == PCI_VENDOR_ID_INTEL &&
(pdev->device == PCI_DEVICE_ID_INTEL_LYNX_POINT_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_LYNX_POINT_LP_XHCI);
}
bool usb_is_intel_switchable_xhci(struct pci_dev *pdev)
{
return usb_is_intel_ppt_switchable_xhci(pdev) ||
usb_is_intel_lpt_switchable_xhci(pdev);
}
void usb_enable_xhci_ports(struct pci_dev *xhci_pdev)
{
u32 ports_available;
if (!IS_ENABLED(CONFIG_USB_XHCI_HCD)) {
dev_warn(&xhci_pdev->dev,
"CONFIG_USB_XHCI_HCD is turned off, "
"defaulting to EHCI.\n");
dev_warn(&xhci_pdev->dev,
"USB 3.0 devices will work at USB 2.0 speeds.\n");
usb_disable_xhci_ports(xhci_pdev);
return;
}
pci_read_config_dword(xhci_pdev, USB_INTEL_USB3PRM,
&ports_available);
dev_dbg(&xhci_pdev->dev, "Configurable ports to enable SuperSpeed: 0x%x\n",
ports_available);
pci_write_config_dword(xhci_pdev, USB_INTEL_USB3_PSSEN,
cpu_to_le32(ports_available));
pci_read_config_dword(xhci_pdev, USB_INTEL_USB3_PSSEN,
&ports_available);
dev_dbg(&xhci_pdev->dev, "USB 3.0 ports that are now enabled "
"under xHCI: 0x%x\n", ports_available);
pci_read_config_dword(xhci_pdev, USB_INTEL_USB2PRM,
&ports_available);
dev_dbg(&xhci_pdev->dev, "Configurable USB 2.0 ports to hand over to xCHI: 0x%x\n",
ports_available);
pci_write_config_dword(xhci_pdev, USB_INTEL_XUSB2PR,
cpu_to_le32(ports_available));
pci_read_config_dword(xhci_pdev, USB_INTEL_XUSB2PR,
&ports_available);
dev_dbg(&xhci_pdev->dev, "USB 2.0 ports that are now switched over "
"to xHCI: 0x%x\n", ports_available);
}
void usb_disable_xhci_ports(struct pci_dev *xhci_pdev)
{
pci_write_config_dword(xhci_pdev, USB_INTEL_USB3_PSSEN, 0x0);
pci_write_config_dword(xhci_pdev, USB_INTEL_XUSB2PR, 0x0);
}
static void quirk_usb_handoff_xhci(struct pci_dev *pdev)
{
void __iomem *base;
int ext_cap_offset;
void __iomem *op_reg_base;
u32 val;
int timeout;
int len = pci_resource_len(pdev, 0);
if (!mmio_resource_enabled(pdev, 0))
return;
base = ioremap_nocache(pci_resource_start(pdev, 0), len);
if (base == NULL)
return;
ext_cap_offset = xhci_find_next_cap_offset(base, XHCI_HCC_PARAMS_OFFSET);
do {
if ((ext_cap_offset + sizeof(val)) > len) {
dev_warn(&pdev->dev,
"xHCI controller failing to respond");
return;
}
if (!ext_cap_offset)
goto hc_init;
val = readl(base + ext_cap_offset);
if (XHCI_EXT_CAPS_ID(val) == XHCI_EXT_CAPS_LEGACY)
break;
ext_cap_offset = xhci_find_next_cap_offset(base, ext_cap_offset);
} while (1);
if (val & XHCI_HC_BIOS_OWNED) {
writel(val | XHCI_HC_OS_OWNED, base + ext_cap_offset);
timeout = handshake(base + ext_cap_offset, XHCI_HC_BIOS_OWNED,
0, 5000, 10);
if (timeout) {
dev_warn(&pdev->dev, "xHCI BIOS handoff failed"
" (BIOS bug ?) %08x\n", val);
writel(val & ~XHCI_HC_BIOS_OWNED, base + ext_cap_offset);
}
}
val = readl(base + ext_cap_offset + XHCI_LEGACY_CONTROL_OFFSET);
val &= XHCI_LEGACY_DISABLE_SMI;
val |= XHCI_LEGACY_SMI_EVENTS;
writel(val, base + ext_cap_offset + XHCI_LEGACY_CONTROL_OFFSET);
hc_init:
if (usb_is_intel_switchable_xhci(pdev))
usb_enable_xhci_ports(pdev);
op_reg_base = base + XHCI_HC_LENGTH(readl(base));
timeout = handshake(op_reg_base + XHCI_STS_OFFSET, XHCI_STS_CNR, 0,
5000, 10);
if (timeout) {
val = readl(op_reg_base + XHCI_STS_OFFSET);
dev_warn(&pdev->dev,
"xHCI HW not ready after 5 sec (HC bug?) "
"status = 0x%x\n", val);
}
val = readl(op_reg_base + XHCI_CMD_OFFSET);
val &= ~(XHCI_CMD_RUN | XHCI_IRQS);
writel(val, op_reg_base + XHCI_CMD_OFFSET);
timeout = handshake(op_reg_base + XHCI_STS_OFFSET, XHCI_STS_HALT, 1,
XHCI_MAX_HALT_USEC, 125);
if (timeout) {
val = readl(op_reg_base + XHCI_STS_OFFSET);
dev_warn(&pdev->dev,
"xHCI HW did not halt within %d usec "
"status = 0x%x\n", XHCI_MAX_HALT_USEC, val);
}
iounmap(base);
}
static void quirk_usb_early_handoff(struct pci_dev *pdev)
{
if (pdev->vendor == 0x184e)
return;
if (pdev->class != PCI_CLASS_SERIAL_USB_UHCI &&
pdev->class != PCI_CLASS_SERIAL_USB_OHCI &&
pdev->class != PCI_CLASS_SERIAL_USB_EHCI &&
pdev->class != PCI_CLASS_SERIAL_USB_XHCI)
return;
if (pci_enable_device(pdev) < 0) {
dev_warn(&pdev->dev, "Can't enable PCI device, "
"BIOS handoff failed.\n");
return;
}
if (pdev->class == PCI_CLASS_SERIAL_USB_UHCI)
quirk_usb_handoff_uhci(pdev);
else if (pdev->class == PCI_CLASS_SERIAL_USB_OHCI)
quirk_usb_handoff_ohci(pdev);
else if (pdev->class == PCI_CLASS_SERIAL_USB_EHCI)
quirk_usb_disable_ehci(pdev);
else if (pdev->class == PCI_CLASS_SERIAL_USB_XHCI)
quirk_usb_handoff_xhci(pdev);
pci_disable_device(pdev);
}
