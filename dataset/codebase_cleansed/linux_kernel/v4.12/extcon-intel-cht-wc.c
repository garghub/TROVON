static int cht_wc_extcon_get_id(struct cht_wc_extcon_data *ext, int pwrsrc_sts)
{
if (pwrsrc_sts & CHT_WC_PWRSRC_ID_GND)
return USB_ID_GND;
if (pwrsrc_sts & CHT_WC_PWRSRC_ID_FLOAT)
return USB_ID_FLOAT;
return USB_ID_FLOAT;
}
static int cht_wc_extcon_get_charger(struct cht_wc_extcon_data *ext,
bool ignore_errors)
{
int ret, usbsrc, status;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(800);
do {
ret = regmap_read(ext->regmap, CHT_WC_USBSRC, &usbsrc);
if (ret) {
dev_err(ext->dev, "Error reading usbsrc: %d\n", ret);
return ret;
}
status = usbsrc & CHT_WC_USBSRC_STS_MASK;
if (status == CHT_WC_USBSRC_STS_SUCCESS ||
status == CHT_WC_USBSRC_STS_FAIL)
break;
msleep(50);
} while (time_before(jiffies, timeout));
if (status != CHT_WC_USBSRC_STS_SUCCESS) {
if (ignore_errors)
return EXTCON_CHG_USB_SDP;
if (status == CHT_WC_USBSRC_STS_FAIL)
dev_warn(ext->dev, "Could not detect charger type\n");
else
dev_warn(ext->dev, "Timeout detecting charger type\n");
return EXTCON_CHG_USB_SDP;
}
usbsrc = (usbsrc & CHT_WC_USBSRC_TYPE_MASK) >> CHT_WC_USBSRC_TYPE_SHIFT;
switch (usbsrc) {
default:
dev_warn(ext->dev,
"Unhandled charger type %d, defaulting to SDP\n",
ret);
case CHT_WC_USBSRC_TYPE_SDP:
case CHT_WC_USBSRC_TYPE_FLOAT_DP_DN:
case CHT_WC_USBSRC_TYPE_OTHER:
return EXTCON_CHG_USB_SDP;
case CHT_WC_USBSRC_TYPE_CDP:
return EXTCON_CHG_USB_CDP;
case CHT_WC_USBSRC_TYPE_DCP:
case CHT_WC_USBSRC_TYPE_DCP_EXTPHY:
case CHT_WC_USBSRC_TYPE_MHL:
return EXTCON_CHG_USB_DCP;
case CHT_WC_USBSRC_TYPE_ACA:
return EXTCON_CHG_USB_ACA;
}
}
static void cht_wc_extcon_set_phymux(struct cht_wc_extcon_data *ext, u8 state)
{
int ret;
ret = regmap_write(ext->regmap, CHT_WC_PHYCTRL, state);
if (ret)
dev_err(ext->dev, "Error writing phyctrl: %d\n", ret);
}
static void cht_wc_extcon_set_5v_boost(struct cht_wc_extcon_data *ext,
bool enable)
{
int ret, val;
val = enable ? CHT_WC_VBUS_GPIO_CTLO_OUTPUT : 0;
ret = regmap_update_bits(ext->regmap, CHT_WC_VBUS_GPIO_CTLO,
CHT_WC_VBUS_GPIO_CTLO_OUTPUT, val);
if (ret)
dev_err(ext->dev, "Error writing Vbus GPIO CTLO: %d\n", ret);
}
static void cht_wc_extcon_set_state(struct cht_wc_extcon_data *ext,
unsigned int cable, bool state)
{
extcon_set_state_sync(ext->edev, cable, state);
if (cable == EXTCON_CHG_USB_SDP)
extcon_set_state_sync(ext->edev, EXTCON_USB, state);
}
static void cht_wc_extcon_pwrsrc_event(struct cht_wc_extcon_data *ext)
{
int ret, pwrsrc_sts, id;
unsigned int cable = EXTCON_NONE;
bool ignore_get_charger_errors = ext->usb_host;
ret = regmap_read(ext->regmap, CHT_WC_PWRSRC_STS, &pwrsrc_sts);
if (ret) {
dev_err(ext->dev, "Error reading pwrsrc status: %d\n", ret);
return;
}
id = cht_wc_extcon_get_id(ext, pwrsrc_sts);
if (id == USB_ID_GND) {
goto charger_det_done;
}
if (!(pwrsrc_sts & CHT_WC_PWRSRC_VBUS)) {
cht_wc_extcon_set_phymux(ext, MUX_SEL_PMIC);
goto set_state;
}
ret = cht_wc_extcon_get_charger(ext, ignore_get_charger_errors);
if (ret >= 0)
cable = ret;
charger_det_done:
cht_wc_extcon_set_phymux(ext, MUX_SEL_SOC);
set_state:
if (cable != ext->previous_cable) {
cht_wc_extcon_set_state(ext, cable, true);
cht_wc_extcon_set_state(ext, ext->previous_cable, false);
ext->previous_cable = cable;
}
ext->usb_host = ((id == USB_ID_GND) || (id == USB_RID_A));
extcon_set_state_sync(ext->edev, EXTCON_USB_HOST, ext->usb_host);
}
static irqreturn_t cht_wc_extcon_isr(int irq, void *data)
{
struct cht_wc_extcon_data *ext = data;
int ret, irqs;
ret = regmap_read(ext->regmap, CHT_WC_PWRSRC_IRQ, &irqs);
if (ret) {
dev_err(ext->dev, "Error reading irqs: %d\n", ret);
return IRQ_NONE;
}
cht_wc_extcon_pwrsrc_event(ext);
ret = regmap_write(ext->regmap, CHT_WC_PWRSRC_IRQ, irqs);
if (ret) {
dev_err(ext->dev, "Error writing irqs: %d\n", ret);
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int cht_wc_extcon_sw_control(struct cht_wc_extcon_data *ext, bool enable)
{
int ret, mask, val;
mask = CHT_WC_CHGRCTRL0_SWCONTROL | CHT_WC_CHGRCTRL0_CCSM_OFF_MASK;
val = enable ? mask : 0;
ret = regmap_update_bits(ext->regmap, CHT_WC_CHGRCTRL0, mask, val);
if (ret)
dev_err(ext->dev, "Error setting sw control: %d\n", ret);
return ret;
}
static int cht_wc_extcon_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
struct cht_wc_extcon_data *ext;
int irq, ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
ext = devm_kzalloc(&pdev->dev, sizeof(*ext), GFP_KERNEL);
if (!ext)
return -ENOMEM;
ext->dev = &pdev->dev;
ext->regmap = pmic->regmap;
ext->previous_cable = EXTCON_NONE;
ext->edev = devm_extcon_dev_allocate(ext->dev, cht_wc_extcon_cables);
if (IS_ERR(ext->edev))
return PTR_ERR(ext->edev);
cht_wc_extcon_set_5v_boost(ext, false);
ret = cht_wc_extcon_sw_control(ext, true);
if (ret)
return ret;
ret = devm_extcon_dev_register(ext->dev, ext->edev);
if (ret) {
dev_err(ext->dev, "Error registering extcon device: %d\n", ret);
goto disable_sw_control;
}
cht_wc_extcon_set_phymux(ext, MUX_SEL_PMIC);
cht_wc_extcon_pwrsrc_event(ext);
ret = devm_request_threaded_irq(ext->dev, irq, NULL, cht_wc_extcon_isr,
IRQF_ONESHOT, pdev->name, ext);
if (ret) {
dev_err(ext->dev, "Error requesting interrupt: %d\n", ret);
goto disable_sw_control;
}
ret = regmap_write(ext->regmap, CHT_WC_PWRSRC_IRQ_MASK,
(int)~(CHT_WC_PWRSRC_VBUS | CHT_WC_PWRSRC_ID_GND |
CHT_WC_PWRSRC_ID_FLOAT));
if (ret) {
dev_err(ext->dev, "Error writing irq-mask: %d\n", ret);
goto disable_sw_control;
}
platform_set_drvdata(pdev, ext);
return 0;
disable_sw_control:
cht_wc_extcon_sw_control(ext, false);
return ret;
}
static int cht_wc_extcon_remove(struct platform_device *pdev)
{
struct cht_wc_extcon_data *ext = platform_get_drvdata(pdev);
cht_wc_extcon_sw_control(ext, false);
return 0;
}
