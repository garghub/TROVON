static int usbmisc_imx25_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
unsigned long flags;
u32 val = 0;
if (data->index > 1)
return -EINVAL;
spin_lock_irqsave(&usbmisc->lock, flags);
switch (data->index) {
case 0:
val = readl(usbmisc->base);
val &= ~(MX25_OTG_SIC_MASK | MX25_OTG_PP_BIT);
val |= (MX25_EHCI_INTERFACE_DIFF_UNI & MX25_EHCI_INTERFACE_MASK) << MX25_OTG_SIC_SHIFT;
val |= (MX25_OTG_PM_BIT | MX25_OTG_OCPOL_BIT);
writel(val, usbmisc->base);
break;
case 1:
val = readl(usbmisc->base);
val &= ~(MX25_H1_SIC_MASK | MX25_H1_PP_BIT | MX25_H1_IPPUE_UP_BIT);
val |= (MX25_EHCI_INTERFACE_SINGLE_UNI & MX25_EHCI_INTERFACE_MASK) << MX25_H1_SIC_SHIFT;
val |= (MX25_H1_PM_BIT | MX25_H1_OCPOL_BIT | MX25_H1_TLL_BIT |
MX25_H1_USBTE_BIT | MX25_H1_IPPUE_DOWN_BIT);
writel(val, usbmisc->base);
break;
}
spin_unlock_irqrestore(&usbmisc->lock, flags);
return 0;
}
static int usbmisc_imx25_post(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
void __iomem *reg;
unsigned long flags;
u32 val;
if (data->index > 2)
return -EINVAL;
if (data->evdo) {
spin_lock_irqsave(&usbmisc->lock, flags);
reg = usbmisc->base + MX25_USB_PHY_CTRL_OFFSET;
val = readl(reg);
writel(val | MX25_BM_EXTERNAL_VBUS_DIVIDER, reg);
spin_unlock_irqrestore(&usbmisc->lock, flags);
usleep_range(5000, 10000);
}
return 0;
}
static int usbmisc_imx27_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
unsigned long flags;
u32 val;
switch (data->index) {
case 0:
val = MX27_OTG_PM_BIT;
break;
case 1:
val = MX27_H1_PM_BIT;
break;
case 2:
val = MX27_H2_PM_BIT;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&usbmisc->lock, flags);
if (data->disable_oc)
val = readl(usbmisc->base) | val;
else
val = readl(usbmisc->base) & ~val;
writel(val, usbmisc->base);
spin_unlock_irqrestore(&usbmisc->lock, flags);
return 0;
}
static int usbmisc_imx53_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
void __iomem *reg = NULL;
unsigned long flags;
u32 val = 0;
if (data->index > 3)
return -EINVAL;
val = readl(usbmisc->base + MX53_USB_OTG_PHY_CTRL_1_OFFSET);
val &= ~MX53_USB_PHYCTRL1_PLLDIV_MASK;
val |= MX53_USB_PLL_DIV_24_MHZ;
writel(val, usbmisc->base + MX53_USB_OTG_PHY_CTRL_1_OFFSET);
spin_lock_irqsave(&usbmisc->lock, flags);
switch (data->index) {
case 0:
if (data->disable_oc) {
reg = usbmisc->base + MX53_USB_OTG_PHY_CTRL_0_OFFSET;
val = readl(reg) | MX53_BM_OVER_CUR_DIS_OTG;
writel(val, reg);
}
break;
case 1:
if (data->disable_oc) {
reg = usbmisc->base + MX53_USB_OTG_PHY_CTRL_0_OFFSET;
val = readl(reg) | MX53_BM_OVER_CUR_DIS_H1;
writel(val, reg);
}
break;
case 2:
if (data->ulpi) {
reg = usbmisc->base + MX53_USB_CTRL_1_OFFSET;
val = readl(reg) | MX53_USB_CTRL_1_UH2_ULPI_EN;
val &= ~MX53_USB_CTRL_1_H2_XCVR_CLK_SEL_MASK;
val |= MX53_USB_CTRL_1_H2_XCVR_CLK_SEL_ULPI;
writel(val, reg);
reg = usbmisc->base + MX53_USB_UH2_CTRL_OFFSET;
val = readl(reg) | MX53_USB_UHx_CTRL_WAKE_UP_EN
| MX53_USB_UHx_CTRL_ULPI_INT_EN;
writel(val, reg);
reg = usbmisc->base + MX53_USB_CLKONOFF_CTRL_OFFSET;
val = readl(reg) | MX53_USB_CLKONOFF_CTRL_H2_INT60CKOFF;
writel(val, reg);
}
if (data->disable_oc) {
reg = usbmisc->base + MX53_USB_UH2_CTRL_OFFSET;
val = readl(reg) | MX53_BM_OVER_CUR_DIS_UHx;
writel(val, reg);
}
break;
case 3:
if (data->ulpi) {
reg = usbmisc->base + MX53_USB_CTRL_1_OFFSET;
val = readl(reg) | MX53_USB_CTRL_1_UH3_ULPI_EN;
val &= ~MX53_USB_CTRL_1_H3_XCVR_CLK_SEL_MASK;
val |= MX53_USB_CTRL_1_H3_XCVR_CLK_SEL_ULPI;
writel(val, reg);
reg = usbmisc->base + MX53_USB_UH3_CTRL_OFFSET;
val = readl(reg) | MX53_USB_UHx_CTRL_WAKE_UP_EN
| MX53_USB_UHx_CTRL_ULPI_INT_EN;
writel(val, reg);
reg = usbmisc->base + MX53_USB_CLKONOFF_CTRL_OFFSET;
val = readl(reg) | MX53_USB_CLKONOFF_CTRL_H3_INT60CKOFF;
writel(val, reg);
}
if (data->disable_oc) {
reg = usbmisc->base + MX53_USB_UH3_CTRL_OFFSET;
val = readl(reg) | MX53_BM_OVER_CUR_DIS_UHx;
writel(val, reg);
}
break;
}
spin_unlock_irqrestore(&usbmisc->lock, flags);
return 0;
}
static int usbmisc_imx6q_set_wakeup
(struct imx_usbmisc_data *data, bool enabled)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
unsigned long flags;
u32 val;
u32 wakeup_setting = (MX6_BM_WAKEUP_ENABLE |
MX6_BM_VBUS_WAKEUP | MX6_BM_ID_WAKEUP);
int ret = 0;
if (data->index > 3)
return -EINVAL;
spin_lock_irqsave(&usbmisc->lock, flags);
val = readl(usbmisc->base + data->index * 4);
if (enabled) {
val |= wakeup_setting;
writel(val, usbmisc->base + data->index * 4);
} else {
if (val & MX6_BM_WAKEUP_INTR)
pr_debug("wakeup int at ci_hdrc.%d\n", data->index);
val &= ~wakeup_setting;
writel(val, usbmisc->base + data->index * 4);
}
spin_unlock_irqrestore(&usbmisc->lock, flags);
return ret;
}
static int usbmisc_imx6q_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
unsigned long flags;
u32 reg;
if (data->index > 3)
return -EINVAL;
spin_lock_irqsave(&usbmisc->lock, flags);
reg = readl(usbmisc->base + data->index * 4);
if (data->disable_oc) {
reg |= MX6_BM_OVER_CUR_DIS;
} else if (data->oc_polarity == 1) {
reg &= ~(MX6_BM_OVER_CUR_DIS | MX6_BM_OVER_CUR_POLARITY);
}
writel(reg, usbmisc->base + data->index * 4);
reg = readl(usbmisc->base + data->index * 4);
writel(reg | MX6_BM_NON_BURST_SETTING,
usbmisc->base + data->index * 4);
spin_unlock_irqrestore(&usbmisc->lock, flags);
usbmisc_imx6q_set_wakeup(data, false);
return 0;
}
static int usbmisc_imx6sx_init(struct imx_usbmisc_data *data)
{
void __iomem *reg = NULL;
unsigned long flags;
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
u32 val;
usbmisc_imx6q_init(data);
if (data->index == 0 || data->index == 1) {
reg = usbmisc->base + MX6_USB_OTG1_PHY_CTRL + data->index * 4;
spin_lock_irqsave(&usbmisc->lock, flags);
val = readl(reg);
writel(val | MX6SX_USB_VBUS_WAKEUP_SOURCE_BVALID, reg);
val = readl(usbmisc->base + data->index * 4);
writel(val & ~MX6SX_BM_DPDM_WAKEUP_EN,
usbmisc->base + data->index * 4);
spin_unlock_irqrestore(&usbmisc->lock, flags);
}
return 0;
}
static int usbmisc_vf610_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
u32 reg;
if (data->index >= 1)
return -EINVAL;
if (data->disable_oc) {
reg = readl(usbmisc->base);
writel(reg | VF610_OVER_CUR_DIS, usbmisc->base);
}
return 0;
}
static int usbmisc_imx7d_set_wakeup
(struct imx_usbmisc_data *data, bool enabled)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
unsigned long flags;
u32 val;
u32 wakeup_setting = (MX6_BM_WAKEUP_ENABLE |
MX6_BM_VBUS_WAKEUP | MX6_BM_ID_WAKEUP);
spin_lock_irqsave(&usbmisc->lock, flags);
val = readl(usbmisc->base);
if (enabled) {
writel(val | wakeup_setting, usbmisc->base);
} else {
if (val & MX6_BM_WAKEUP_INTR)
dev_dbg(data->dev, "wakeup int\n");
writel(val & ~wakeup_setting, usbmisc->base);
}
spin_unlock_irqrestore(&usbmisc->lock, flags);
return 0;
}
static int usbmisc_imx7d_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc = dev_get_drvdata(data->dev);
unsigned long flags;
u32 reg;
if (data->index >= 1)
return -EINVAL;
spin_lock_irqsave(&usbmisc->lock, flags);
reg = readl(usbmisc->base);
if (data->disable_oc) {
reg |= MX6_BM_OVER_CUR_DIS;
} else if (data->oc_polarity == 1) {
reg &= ~(MX6_BM_OVER_CUR_DIS | MX6_BM_OVER_CUR_POLARITY);
}
writel(reg, usbmisc->base);
reg = readl(usbmisc->base + MX7D_USBNC_USB_CTRL2);
reg &= ~MX7D_USB_VBUS_WAKEUP_SOURCE_MASK;
writel(reg | MX7D_USB_VBUS_WAKEUP_SOURCE_BVALID,
usbmisc->base + MX7D_USBNC_USB_CTRL2);
spin_unlock_irqrestore(&usbmisc->lock, flags);
usbmisc_imx7d_set_wakeup(data, false);
return 0;
}
int imx_usbmisc_init(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc;
if (!data)
return 0;
usbmisc = dev_get_drvdata(data->dev);
if (!usbmisc->ops->init)
return 0;
return usbmisc->ops->init(data);
}
int imx_usbmisc_init_post(struct imx_usbmisc_data *data)
{
struct imx_usbmisc *usbmisc;
if (!data)
return 0;
usbmisc = dev_get_drvdata(data->dev);
if (!usbmisc->ops->post)
return 0;
return usbmisc->ops->post(data);
}
int imx_usbmisc_set_wakeup(struct imx_usbmisc_data *data, bool enabled)
{
struct imx_usbmisc *usbmisc;
if (!data)
return 0;
usbmisc = dev_get_drvdata(data->dev);
if (!usbmisc->ops->set_wakeup)
return 0;
return usbmisc->ops->set_wakeup(data, enabled);
}
static int usbmisc_imx_probe(struct platform_device *pdev)
{
struct resource *res;
struct imx_usbmisc *data;
const struct of_device_id *of_id;
of_id = of_match_device(usbmisc_imx_dt_ids, &pdev->dev);
if (!of_id)
return -ENODEV;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_init(&data->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
data->ops = (const struct usbmisc_ops *)of_id->data;
platform_set_drvdata(pdev, data);
return 0;
}
static int usbmisc_imx_remove(struct platform_device *pdev)
{
return 0;
}
