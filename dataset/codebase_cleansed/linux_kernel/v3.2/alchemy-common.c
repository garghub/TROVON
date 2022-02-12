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
}
register_syscore_ops(&alchemy_usb_pm_ops);
return 0;
}
