static inline void udc_device_init(struct omap_usb_config *pdata)
{
pdata->udc_device = &udc_device;
}
static inline void udc_device_init(struct omap_usb_config *pdata)
{
}
static inline void ohci_device_init(struct omap_usb_config *pdata)
{
pdata->ohci_device = &ohci_device;
}
static inline void ohci_device_init(struct omap_usb_config *pdata)
{
}
static inline void otg_device_init(struct omap_usb_config *pdata)
{
pdata->otg_device = &otg_device;
}
static inline void otg_device_init(struct omap_usb_config *pdata)
{
}
static void omap2_usb_devconf_clear(u8 port, u32 mask)
{
u32 r;
r = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
r &= ~USBTXWRMODEI(port, mask);
omap_ctrl_writel(r, OMAP2_CONTROL_DEVCONF0);
}
static void omap2_usb_devconf_set(u8 port, u32 mask)
{
u32 r;
r = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
r |= USBTXWRMODEI(port, mask);
omap_ctrl_writel(r, OMAP2_CONTROL_DEVCONF0);
}
static void omap2_usb2_disable_5pinbitll(void)
{
u32 r;
r = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
r &= ~(USBTXWRMODEI(2, USB_BIDIR_TLL) | USBT2TLL5PI);
omap_ctrl_writel(r, OMAP2_CONTROL_DEVCONF0);
}
static void omap2_usb2_enable_5pinunitll(void)
{
u32 r;
r = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
r |= USBTXWRMODEI(2, USB_UNIDIR_TLL) | USBT2TLL5PI;
omap_ctrl_writel(r, OMAP2_CONTROL_DEVCONF0);
}
static u32 __init omap2_usb0_init(unsigned nwires, unsigned is_device)
{
u32 syscon1 = 0;
omap2_usb_devconf_clear(0, USB_BIDIR_TLL);
if (nwires == 0)
return 0;
if (is_device)
omap_mux_init_signal("usb0_puen", 0);
omap_mux_init_signal("usb0_dat", 0);
omap_mux_init_signal("usb0_txen", 0);
omap_mux_init_signal("usb0_se0", 0);
if (nwires != 3)
omap_mux_init_signal("usb0_rcv", 0);
switch (nwires) {
case 3:
syscon1 = 2;
omap2_usb_devconf_set(0, USB_BIDIR);
break;
case 4:
syscon1 = 1;
omap2_usb_devconf_set(0, USB_BIDIR);
break;
case 6:
syscon1 = 3;
omap_mux_init_signal("usb0_vp", 0);
omap_mux_init_signal("usb0_vm", 0);
omap2_usb_devconf_set(0, USB_UNIDIR);
break;
default:
printk(KERN_ERR "illegal usb%d %d-wire transceiver\n",
0, nwires);
}
return syscon1 << 16;
}
static u32 __init omap2_usb1_init(unsigned nwires)
{
u32 syscon1 = 0;
omap2_usb_devconf_clear(1, USB_BIDIR_TLL);
if (nwires == 0)
return 0;
switch (nwires) {
case 2:
syscon1 = 1;
omap2_usb_devconf_set(1, USB_BIDIR_TLL);
break;
case 3:
syscon1 = 2;
omap2_usb_devconf_set(1, USB_BIDIR);
break;
case 4:
syscon1 = 1;
omap2_usb_devconf_set(1, USB_BIDIR);
break;
case 6:
default:
printk(KERN_ERR "illegal usb%d %d-wire transceiver\n",
1, nwires);
}
return syscon1 << 20;
}
static u32 __init omap2_usb2_init(unsigned nwires, unsigned alt_pingroup)
{
u32 syscon1 = 0;
omap2_usb2_disable_5pinbitll();
alt_pingroup = 0;
if (alt_pingroup || nwires == 0)
return 0;
omap_mux_init_signal("usb2_dat", 0);
omap_mux_init_signal("usb2_se0", 0);
if (nwires > 2)
omap_mux_init_signal("usb2_txen", 0);
if (nwires > 3)
omap_mux_init_signal("usb2_rcv", 0);
switch (nwires) {
case 2:
syscon1 = 1;
omap2_usb_devconf_set(2, USB_BIDIR_TLL);
break;
case 3:
syscon1 = 2;
omap2_usb_devconf_set(2, USB_BIDIR);
break;
case 4:
syscon1 = 1;
omap2_usb_devconf_set(2, USB_BIDIR);
break;
case 5:
syscon1 = 3;
omap2_usb2_enable_5pinunitll();
break;
case 6:
default:
printk(KERN_ERR "illegal usb%d %d-wire transceiver\n",
2, nwires);
}
return syscon1 << 24;
}
void __init omap2_usbfs_init(struct omap_usb_config *pdata)
{
struct clk *ick;
if (!cpu_is_omap24xx())
return;
ick = clk_get(NULL, "usb_l4_ick");
if (IS_ERR(ick))
return;
clk_enable(ick);
pdata->usb0_init = omap2_usb0_init;
pdata->usb1_init = omap2_usb1_init;
pdata->usb2_init = omap2_usb2_init;
udc_device_init(pdata);
ohci_device_init(pdata);
otg_device_init(pdata);
omap_otg_init(pdata);
clk_disable(ick);
clk_put(ick);
}
