static void xhci_rcar_start_gen2(struct usb_hcd *hcd)
{
writel(RCAR_USB3_LCLK_ENA_VAL, hcd->regs + RCAR_USB3_LCLK);
writel(RCAR_USB3_CONF1_VAL, hcd->regs + RCAR_USB3_CONF1);
writel(RCAR_USB3_CONF2_VAL, hcd->regs + RCAR_USB3_CONF2);
writel(RCAR_USB3_CONF3_VAL, hcd->regs + RCAR_USB3_CONF3);
writel(RCAR_USB3_RX_POL_VAL, hcd->regs + RCAR_USB3_RX_POL);
writel(RCAR_USB3_TX_POL_VAL, hcd->regs + RCAR_USB3_TX_POL);
}
void xhci_rcar_start(struct usb_hcd *hcd)
{
u32 temp;
if (hcd->regs != NULL) {
temp = readl(hcd->regs + RCAR_USB3_INT_ENA);
temp |= RCAR_USB3_INT_ENA_VAL;
writel(temp, hcd->regs + RCAR_USB3_INT_ENA);
if (xhci_plat_type_is(hcd, XHCI_PLAT_TYPE_RENESAS_RCAR_GEN2))
xhci_rcar_start_gen2(hcd);
}
}
static int xhci_rcar_download_firmware(struct usb_hcd *hcd)
{
struct device *dev = hcd->self.controller;
void __iomem *regs = hcd->regs;
struct xhci_plat_priv *priv = hcd_to_xhci_priv(hcd);
const struct firmware *fw;
int retval, index, j, time;
int timeout = 10000;
u32 data, val, temp;
retval = request_firmware(&fw, priv->firmware_name, dev);
if (retval)
return retval;
temp = readl(regs + RCAR_USB3_DL_CTRL);
temp |= RCAR_USB3_DL_CTRL_ENABLE;
writel(temp, regs + RCAR_USB3_DL_CTRL);
for (index = 0; index < fw->size; index += 4) {
for (data = 0, j = 3; j >= 0; j--) {
if ((j + index) < fw->size)
data |= fw->data[index + j] << (8 * j);
}
writel(data, regs + RCAR_USB3_FW_DATA0);
temp = readl(regs + RCAR_USB3_DL_CTRL);
temp |= RCAR_USB3_DL_CTRL_FW_SET_DATA0;
writel(temp, regs + RCAR_USB3_DL_CTRL);
for (time = 0; time < timeout; time++) {
val = readl(regs + RCAR_USB3_DL_CTRL);
if ((val & RCAR_USB3_DL_CTRL_FW_SET_DATA0) == 0)
break;
udelay(1);
}
if (time == timeout) {
retval = -ETIMEDOUT;
break;
}
}
temp = readl(regs + RCAR_USB3_DL_CTRL);
temp &= ~RCAR_USB3_DL_CTRL_ENABLE;
writel(temp, regs + RCAR_USB3_DL_CTRL);
for (time = 0; time < timeout; time++) {
val = readl(regs + RCAR_USB3_DL_CTRL);
if (val & RCAR_USB3_DL_CTRL_FW_SUCCESS) {
retval = 0;
break;
}
udelay(1);
}
if (time == timeout)
retval = -ETIMEDOUT;
release_firmware(fw);
return retval;
}
int xhci_rcar_init_quirk(struct usb_hcd *hcd)
{
if (!hcd->regs)
return 0;
return xhci_rcar_download_firmware(hcd);
}
