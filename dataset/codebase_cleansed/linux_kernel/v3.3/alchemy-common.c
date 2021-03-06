static inline void __au1300_usb_phyctl(void __iomem *base, int enable)
{
unsigned long r, s;
r = __raw_readl(base + USB_DWC_CTRL2);
s = __raw_readl(base + USB_DWC_CTRL3);
s &= USB_DWC_CTRL3_OHCI1_CKEN | USB_DWC_CTRL3_OHCI0_CKEN |
USB_DWC_CTRL3_EHCI0_CKEN | USB_DWC_CTRL3_OTG0_CKEN;
if (enable) {
r |= USB_DWC_CTRL2_PHY1RS | USB_DWC_CTRL2_PHY0RS |
USB_DWC_CTRL2_PHYRS;
__raw_writel(r, base + USB_DWC_CTRL2);
wmb();
} else if (!s) {
r &= ~(USB_DWC_CTRL2_PHY1RS | USB_DWC_CTRL2_PHY0RS |
USB_DWC_CTRL2_PHYRS);
__raw_writel(r, base + USB_DWC_CTRL2);
wmb();
}
}
static inline void __au1300_ohci_control(void __iomem *base, int enable, int id)
{
unsigned long r;
if (enable) {
__raw_writel(1, base + USB_DWC_CTRL7);
wmb();
r = __raw_readl(base + USB_DWC_CTRL3);
r |= (id == 0) ? USB_DWC_CTRL3_OHCI0_CKEN
: USB_DWC_CTRL3_OHCI1_CKEN;
__raw_writel(r, base + USB_DWC_CTRL3);
wmb();
__au1300_usb_phyctl(base, enable);
r = __raw_readl(base + USB_INT_ENABLE);
r |= (id == 0) ? USB_INTEN_OHCI0 : USB_INTEN_OHCI1;
__raw_writel(r, base + USB_INT_ENABLE);
wmb();
__raw_writel(0, base + USB_DWC_CTRL7);
wmb();
} else {
r = __raw_readl(base + USB_INT_ENABLE);
r &= ~((id == 0) ? USB_INTEN_OHCI0 : USB_INTEN_OHCI1);
__raw_writel(r, base + USB_INT_ENABLE);
wmb();
r = __raw_readl(base + USB_DWC_CTRL3);
r &= ~((id == 0) ? USB_DWC_CTRL3_OHCI0_CKEN
: USB_DWC_CTRL3_OHCI1_CKEN);
__raw_writel(r, base + USB_DWC_CTRL3);
wmb();
__au1300_usb_phyctl(base, enable);
}
}
static inline void __au1300_ehci_control(void __iomem *base, int enable)
{
unsigned long r;
if (enable) {
r = __raw_readl(base + USB_DWC_CTRL3);
r |= USB_DWC_CTRL3_EHCI0_CKEN;
__raw_writel(r, base + USB_DWC_CTRL3);
wmb();
r = __raw_readl(base + USB_DWC_CTRL1);
r |= USB_DWC_CTRL1_HSTRS;
__raw_writel(r, base + USB_DWC_CTRL1);
wmb();
__au1300_usb_phyctl(base, enable);
r = __raw_readl(base + USB_INT_ENABLE);
r |= USB_INTEN_EHCI;
__raw_writel(r, base + USB_INT_ENABLE);
wmb();
} else {
r = __raw_readl(base + USB_INT_ENABLE);
r &= ~USB_INTEN_EHCI;
__raw_writel(r, base + USB_INT_ENABLE);
wmb();
r = __raw_readl(base + USB_DWC_CTRL1);
r &= ~USB_DWC_CTRL1_HSTRS;
__raw_writel(r, base + USB_DWC_CTRL1);
wmb();
r = __raw_readl(base + USB_DWC_CTRL3);
r &= ~USB_DWC_CTRL3_EHCI0_CKEN;
__raw_writel(r, base + USB_DWC_CTRL3);
wmb();
__au1300_usb_phyctl(base, enable);
}
}
static inline void __au1300_udc_control(void __iomem *base, int enable)
{
unsigned long r;
if (enable) {
r = __raw_readl(base + USB_DWC_CTRL1);
r |= USB_DWC_CTRL1_DCRS;
__raw_writel(r, base + USB_DWC_CTRL1);
wmb();
__au1300_usb_phyctl(base, enable);
r = __raw_readl(base + USB_INT_ENABLE);
r |= USB_INTEN_UDC;
__raw_writel(r, base + USB_INT_ENABLE);
wmb();
} else {
r = __raw_readl(base + USB_INT_ENABLE);
r &= ~USB_INTEN_UDC;
__raw_writel(r, base + USB_INT_ENABLE);
wmb();
r = __raw_readl(base + USB_DWC_CTRL1);
r &= ~USB_DWC_CTRL1_DCRS;
__raw_writel(r, base + USB_DWC_CTRL1);
wmb();
__au1300_usb_phyctl(base, enable);
}
}
static inline void __au1300_otg_control(void __iomem *base, int enable)
{
unsigned long r;
if (enable) {
r = __raw_readl(base + USB_DWC_CTRL3);
r |= USB_DWC_CTRL3_OTG0_CKEN;
__raw_writel(r, base + USB_DWC_CTRL3);
wmb();
r = __raw_readl(base + USB_DWC_CTRL1);
r &= ~USB_DWC_CTRL1_OTGD;
__raw_writel(r, base + USB_DWC_CTRL1);
wmb();
__au1300_usb_phyctl(base, enable);
} else {
r = __raw_readl(base + USB_DWC_CTRL1);
r |= USB_DWC_CTRL1_OTGD;
__raw_writel(r, base + USB_DWC_CTRL1);
wmb();
r = __raw_readl(base + USB_DWC_CTRL3);
r &= ~USB_DWC_CTRL3_OTG0_CKEN;
__raw_writel(r, base + USB_DWC_CTRL3);
wmb();
__au1300_usb_phyctl(base, enable);
}
}
static inline int au1300_usb_control(int block, int enable)
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1300_USB_CTL_PHYS_ADDR);
int ret = 0;
switch (block) {
case ALCHEMY_USB_OHCI0:
__au1300_ohci_control(base, enable, 0);
break;
case ALCHEMY_USB_OHCI1:
__au1300_ohci_control(base, enable, 1);
break;
case ALCHEMY_USB_EHCI0:
__au1300_ehci_control(base, enable);
break;
case ALCHEMY_USB_UDC0:
__au1300_udc_control(base, enable);
break;
case ALCHEMY_USB_OTG0:
__au1300_otg_control(base, enable);
break;
default:
ret = -ENODEV;
}
return ret;
}
static inline void au1300_usb_init(void)
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1300_USB_CTL_PHYS_ADDR);
__raw_writel(0, base + USB_INT_ENABLE);
wmb();
__raw_writel(0, base + USB_DWC_CTRL3);
wmb();
__raw_writel(~0, base + USB_MSR_ERR);
wmb();
__raw_writel(~0, base + USB_INT_STATUS);
wmb();
__raw_writel(USB_SBUS_CTRL_SBCA, base + USB_SBUS_CTRL);
wmb();
}
static inline void __au1200_ohci_control(void __iomem *base, int enable)
{
unsigned long r = __raw_readl(base + AU1200_USBCFG);
if (enable) {
__raw_writel(r | USBCFG_OCE, base + AU1200_USBCFG);
wmb();
udelay(2000);
} else {
__raw_writel(r & ~USBCFG_OCE, base + AU1200_USBCFG);
wmb();
udelay(1000);
}
}
static inline void __au1200_ehci_control(void __iomem *base, int enable)
{
unsigned long r = __raw_readl(base + AU1200_USBCFG);
if (enable) {
__raw_writel(r | USBCFG_ECE | USBCFG_PPE, base + AU1200_USBCFG);
wmb();
udelay(1000);
} else {
if (!(r & USBCFG_UCE))
r &= ~USBCFG_PPE;
__raw_writel(r & ~USBCFG_ECE, base + AU1200_USBCFG);
wmb();
udelay(1000);
}
}
static inline void __au1200_udc_control(void __iomem *base, int enable)
{
unsigned long r = __raw_readl(base + AU1200_USBCFG);
if (enable) {
__raw_writel(r | USBCFG_UCE | USBCFG_PPE, base + AU1200_USBCFG);
wmb();
} else {
if (!(r & USBCFG_ECE))
r &= ~USBCFG_PPE;
__raw_writel(r & ~USBCFG_UCE, base + AU1200_USBCFG);
wmb();
}
}
static inline int au1200_coherency_bug(void)
{
#if defined(CONFIG_DMA_COHERENT)
if (!(read_c0_prid() & 0xff)) {
printk(KERN_INFO "Au1200 USB: this is chip revision AB !!\n");
printk(KERN_INFO "Au1200 USB: update your board or re-configure"
" the kernel\n");
return -ENODEV;
}
#endif
return 0;
}
static inline int au1200_usb_control(int block, int enable)
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1200_USB_CTL_PHYS_ADDR);
int ret = 0;
switch (block) {
case ALCHEMY_USB_OHCI0:
ret = au1200_coherency_bug();
if (ret && enable)
goto out;
__au1200_ohci_control(base, enable);
break;
case ALCHEMY_USB_UDC0:
__au1200_udc_control(base, enable);
break;
case ALCHEMY_USB_EHCI0:
ret = au1200_coherency_bug();
if (ret && enable)
goto out;
__au1200_ehci_control(base, enable);
break;
default:
ret = -ENODEV;
}
out:
return ret;
}
static inline void au1200_usb_init(void)
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1200_USB_CTL_PHYS_ADDR);
__raw_writel(USBCFG_INIT_AU1200, base + AU1200_USBCFG);
wmb();
udelay(1000);
}
static inline void au1000_usb_init(unsigned long rb, int reg)
{
void __iomem *base = (void __iomem *)KSEG1ADDR(rb + reg);
unsigned long r = __raw_readl(base);
#if defined(__BIG_ENDIAN)
r |= USBHEN_BE;
#endif
r |= USBHEN_C;
__raw_writel(r, base);
wmb();
udelay(1000);
}
static inline void __au1xx0_ohci_control(int enable, unsigned long rb, int creg)
{
void __iomem *base = (void __iomem *)KSEG1ADDR(rb);
unsigned long r = __raw_readl(base + creg);
if (enable) {
__raw_writel(r | USBHEN_CE, base + creg);
wmb();
udelay(1000);
__raw_writel(r | USBHEN_CE | USBHEN_E, base + creg);
wmb();
udelay(1000);
while (__raw_readl(base + creg),
!(__raw_readl(base + creg) & USBHEN_RD))
udelay(1000);
} else {
__raw_writel(r & ~(USBHEN_CE | USBHEN_E), base + creg);
wmb();
}
}
static inline int au1000_usb_control(int block, int enable, unsigned long rb,
int creg)
{
int ret = 0;
switch (block) {
case ALCHEMY_USB_OHCI0:
__au1xx0_ohci_control(enable, rb, creg);
break;
default:
ret = -ENODEV;
}
return ret;
}
int alchemy_usb_control(int block, int enable)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&alchemy_usb_lock, flags);
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1000:
case ALCHEMY_CPU_AU1500:
case ALCHEMY_CPU_AU1100:
ret = au1000_usb_control(block, enable,
AU1000_USB_OHCI_PHYS_ADDR, AU1000_OHCICFG);
break;
case ALCHEMY_CPU_AU1550:
ret = au1000_usb_control(block, enable,
AU1550_USB_OHCI_PHYS_ADDR, AU1550_OHCICFG);
break;
case ALCHEMY_CPU_AU1200:
ret = au1200_usb_control(block, enable);
break;
case ALCHEMY_CPU_AU1300:
ret = au1300_usb_control(block, enable);
break;
default:
ret = -ENODEV;
}
spin_unlock_irqrestore(&alchemy_usb_lock, flags);
return ret;
}
static void au1000_usb_pm(unsigned long br, int creg, int susp)
{
void __iomem *base = (void __iomem *)KSEG1ADDR(br);
if (susp) {
alchemy_usb_pmdata[0] = __raw_readl(base + creg);
__raw_writel(0, base + 0x04);
wmb();
__raw_writel(0, base + creg);
wmb();
} else {
__raw_writel(alchemy_usb_pmdata[0], base + creg);
wmb();
}
}
static void au1200_usb_pm(int susp)
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1200_USB_OTG_PHYS_ADDR);
if (susp) {
alchemy_usb_pmdata[0] = __raw_readl(base + 0x00);
alchemy_usb_pmdata[1] = __raw_readl(base + 0x04);
} else {
au1200_usb_init();
__raw_writel(alchemy_usb_pmdata[0], base + 0x00);
__raw_writel(alchemy_usb_pmdata[1], base + 0x04);
wmb();
}
}
static void au1300_usb_pm(int susp)
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1300_USB_CTL_PHYS_ADDR);
if (susp) {
alchemy_usb_pmdata[0] = __raw_readl(base + USB_DWC_CTRL4);
} else {
au1300_usb_init();
__raw_writel(alchemy_usb_pmdata[0], base + USB_DWC_CTRL4);
wmb();
}
}
static void alchemy_usb_pm(int susp)
{
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1000:
case ALCHEMY_CPU_AU1500:
case ALCHEMY_CPU_AU1100:
au1000_usb_pm(AU1000_USB_OHCI_PHYS_ADDR, AU1000_OHCICFG, susp);
break;
case ALCHEMY_CPU_AU1550:
au1000_usb_pm(AU1550_USB_OHCI_PHYS_ADDR, AU1550_OHCICFG, susp);
break;
case ALCHEMY_CPU_AU1200:
au1200_usb_pm(susp);
break;
case ALCHEMY_CPU_AU1300:
au1300_usb_pm(susp);
break;
}
}
static int alchemy_usb_suspend(void)
{
alchemy_usb_pm(1);
return 0;
}
static void alchemy_usb_resume(void)
{
alchemy_usb_pm(0);
}
static int __init alchemy_usb_init(void)
{
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1000:
case ALCHEMY_CPU_AU1500:
case ALCHEMY_CPU_AU1100:
au1000_usb_init(AU1000_USB_OHCI_PHYS_ADDR, AU1000_OHCICFG);
break;
case ALCHEMY_CPU_AU1550:
au1000_usb_init(AU1550_USB_OHCI_PHYS_ADDR, AU1550_OHCICFG);
break;
case ALCHEMY_CPU_AU1200:
au1200_usb_init();
break;
case ALCHEMY_CPU_AU1300:
au1300_usb_init();
break;
}
register_syscore_ops(&alchemy_usb_pm_ops);
return 0;
}
