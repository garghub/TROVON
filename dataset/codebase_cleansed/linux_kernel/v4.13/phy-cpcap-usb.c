static bool cpcap_usb_vbus_valid(struct cpcap_phy_ddata *ddata)
{
int error, value = 0;
error = iio_read_channel_processed(ddata->vbus, &value);
if (error >= 0)
return value > 3900 ? true : false;
dev_err(ddata->dev, "error reading VBUS: %i\n", error);
return false;
}
static int cpcap_usb_phy_set_host(struct usb_otg *otg, struct usb_bus *host)
{
otg->host = host;
if (!host)
otg->state = OTG_STATE_UNDEFINED;
return 0;
}
static int cpcap_usb_phy_set_peripheral(struct usb_otg *otg,
struct usb_gadget *gadget)
{
otg->gadget = gadget;
if (!gadget)
otg->state = OTG_STATE_UNDEFINED;
return 0;
}
static int cpcap_phy_get_ints_state(struct cpcap_phy_ddata *ddata,
struct cpcap_usb_ints_state *s)
{
int val, error;
error = regmap_read(ddata->reg, CPCAP_REG_INTS1, &val);
if (error)
return error;
s->id_ground = val & BIT(15);
s->id_float = val & BIT(14);
s->vbusov = val & BIT(11);
error = regmap_read(ddata->reg, CPCAP_REG_INTS2, &val);
if (error)
return error;
s->vbusvld = val & BIT(3);
s->sessvld = val & BIT(2);
s->sessend = val & BIT(1);
s->se1 = val & BIT(0);
error = regmap_read(ddata->reg, CPCAP_REG_INTS4, &val);
if (error)
return error;
s->dm = val & BIT(1);
s->dp = val & BIT(0);
return 0;
}
static void cpcap_usb_detect(struct work_struct *work)
{
struct cpcap_phy_ddata *ddata;
struct cpcap_usb_ints_state s;
bool vbus = false;
int error;
ddata = container_of(work, struct cpcap_phy_ddata, detect_work.work);
error = cpcap_phy_get_ints_state(ddata, &s);
if (error)
return;
if (s.id_ground) {
dev_dbg(ddata->dev, "id ground, USB host mode\n");
error = cpcap_usb_set_usb_mode(ddata);
if (error)
goto out_err;
error = musb_mailbox(MUSB_ID_GROUND);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC3,
CPCAP_BIT_VBUSSTBY_EN,
CPCAP_BIT_VBUSSTBY_EN);
if (error)
goto out_err;
return;
}
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC3,
CPCAP_BIT_VBUSSTBY_EN, 0);
if (error)
goto out_err;
vbus = cpcap_usb_vbus_valid(ddata);
if (vbus) {
if (s.id_ground) {
dev_dbg(ddata->dev, "connected to a dock\n");
error = cpcap_usb_set_usb_mode(ddata);
if (error)
goto out_err;
error = musb_mailbox(MUSB_ID_GROUND);
if (error)
goto out_err;
return;
}
dev_dbg(ddata->dev, "connected to USB host\n");
error = cpcap_usb_set_usb_mode(ddata);
if (error)
goto out_err;
error = musb_mailbox(MUSB_VBUS_VALID);
if (error)
goto out_err;
return;
}
error = cpcap_usb_set_uart_mode(ddata);
if (error)
goto out_err;
error = musb_mailbox(MUSB_VBUS_OFF);
if (error)
goto out_err;
dev_dbg(ddata->dev, "set UART mode\n");
return;
out_err:
dev_err(ddata->dev, "error setting cable state: %i\n", error);
}
static irqreturn_t cpcap_phy_irq_thread(int irq, void *data)
{
struct cpcap_phy_ddata *ddata = data;
if (!atomic_read(&ddata->active))
return IRQ_NONE;
schedule_delayed_work(&ddata->detect_work, msecs_to_jiffies(1));
return IRQ_HANDLED;
}
static int cpcap_usb_init_irq(struct platform_device *pdev,
struct cpcap_phy_ddata *ddata,
const char *name)
{
int irq, error;
irq = platform_get_irq_byname(pdev, name);
if (!irq)
return -ENODEV;
error = devm_request_threaded_irq(ddata->dev, irq, NULL,
cpcap_phy_irq_thread,
IRQF_SHARED,
name, ddata);
if (error) {
dev_err(ddata->dev, "could not get irq %s: %i\n",
name, error);
return error;
}
return 0;
}
static int cpcap_usb_init_interrupts(struct platform_device *pdev,
struct cpcap_phy_ddata *ddata)
{
int i, error;
for (i = 0; i < ARRAY_SIZE(cpcap_phy_irqs); i++) {
error = cpcap_usb_init_irq(pdev, ddata, cpcap_phy_irqs[i]);
if (error)
return error;
}
return 0;
}
static int cpcap_usb_gpio_set_mode(struct cpcap_phy_ddata *ddata,
enum cpcap_gpio_mode mode)
{
if (!ddata->gpio[0] || !ddata->gpio[1])
return 0;
gpiod_set_value(ddata->gpio[0], mode & 1);
gpiod_set_value(ddata->gpio[1], mode >> 1);
return 0;
}
static int cpcap_usb_set_uart_mode(struct cpcap_phy_ddata *ddata)
{
int error;
error = cpcap_usb_gpio_set_mode(ddata, CPCAP_DM_DP);
if (error)
goto out_err;
if (ddata->pins_uart) {
error = pinctrl_select_state(ddata->pins, ddata->pins_uart);
if (error)
goto out_err;
}
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC1,
CPCAP_BIT_VBUSPD,
CPCAP_BIT_VBUSPD);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC2,
0xffff, CPCAP_BIT_UARTMUX0 |
CPCAP_BIT_EMUMODE0);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC3, 0x7fff,
CPCAP_BIT_IDPU_SPI);
if (error)
goto out_err;
return 0;
out_err:
dev_err(ddata->dev, "%s failed with %i\n", __func__, error);
return error;
}
static int cpcap_usb_set_usb_mode(struct cpcap_phy_ddata *ddata)
{
int error;
error = cpcap_usb_gpio_set_mode(ddata, CPCAP_OTG_DM_DP);
if (error)
return error;
if (ddata->pins_utmi) {
error = pinctrl_select_state(ddata->pins, ddata->pins_utmi);
if (error) {
dev_err(ddata->dev, "could not set usb mode: %i\n",
error);
return error;
}
}
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC1,
CPCAP_BIT_VBUSPD, 0);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC2,
CPCAP_BIT_USBXCVREN,
CPCAP_BIT_USBXCVREN);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC3,
CPCAP_BIT_PU_SPI |
CPCAP_BIT_DMPD_SPI |
CPCAP_BIT_DPPD_SPI |
CPCAP_BIT_SUSPEND_SPI |
CPCAP_BIT_ULPI_SPI_SEL, 0);
if (error)
goto out_err;
error = regmap_update_bits(ddata->reg, CPCAP_REG_USBC2,
CPCAP_BIT_USBXCVREN,
CPCAP_BIT_USBXCVREN);
if (error)
goto out_err;
return 0;
out_err:
dev_err(ddata->dev, "%s failed with %i\n", __func__, error);
return error;
}
static int cpcap_usb_init_optional_pins(struct cpcap_phy_ddata *ddata)
{
ddata->pins = devm_pinctrl_get(ddata->dev);
if (IS_ERR(ddata->pins)) {
dev_info(ddata->dev, "default pins not configured: %ld\n",
PTR_ERR(ddata->pins));
ddata->pins = NULL;
return 0;
}
ddata->pins_ulpi = pinctrl_lookup_state(ddata->pins, "ulpi");
if (IS_ERR(ddata->pins_ulpi)) {
dev_info(ddata->dev, "ulpi pins not configured\n");
ddata->pins_ulpi = NULL;
}
ddata->pins_utmi = pinctrl_lookup_state(ddata->pins, "utmi");
if (IS_ERR(ddata->pins_utmi)) {
dev_info(ddata->dev, "utmi pins not configured\n");
ddata->pins_utmi = NULL;
}
ddata->pins_uart = pinctrl_lookup_state(ddata->pins, "uart");
if (IS_ERR(ddata->pins_uart)) {
dev_info(ddata->dev, "uart pins not configured\n");
ddata->pins_uart = NULL;
}
if (ddata->pins_uart)
return pinctrl_select_state(ddata->pins, ddata->pins_uart);
return 0;
}
static void cpcap_usb_init_optional_gpios(struct cpcap_phy_ddata *ddata)
{
int i;
for (i = 0; i < 2; i++) {
ddata->gpio[i] = devm_gpiod_get_index(ddata->dev, "mode",
i, GPIOD_OUT_HIGH);
if (IS_ERR(ddata->gpio[i])) {
dev_info(ddata->dev, "no mode change GPIO%i: %li\n",
i, PTR_ERR(ddata->gpio[i]));
ddata->gpio[i] = NULL;
}
}
}
static int cpcap_usb_init_iio(struct cpcap_phy_ddata *ddata)
{
enum iio_chan_type type;
int error;
ddata->vbus = devm_iio_channel_get(ddata->dev, "vbus");
if (IS_ERR(ddata->vbus)) {
error = PTR_ERR(ddata->vbus);
goto out_err;
}
if (!ddata->vbus->indio_dev) {
error = -ENXIO;
goto out_err;
}
error = iio_get_channel_type(ddata->vbus, &type);
if (error < 0)
goto out_err;
if (type != IIO_VOLTAGE) {
error = -EINVAL;
goto out_err;
}
return 0;
out_err:
dev_err(ddata->dev, "could not initialize VBUS or ID IIO: %i\n",
error);
return error;
}
static int cpcap_usb_phy_probe(struct platform_device *pdev)
{
struct cpcap_phy_ddata *ddata;
struct phy *generic_phy;
struct phy_provider *phy_provider;
struct usb_otg *otg;
const struct of_device_id *of_id;
int error;
of_id = of_match_device(of_match_ptr(cpcap_usb_phy_id_table),
&pdev->dev);
if (!of_id)
return -EINVAL;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
ddata->reg = dev_get_regmap(pdev->dev.parent, NULL);
if (!ddata->reg)
return -ENODEV;
otg = devm_kzalloc(&pdev->dev, sizeof(*otg), GFP_KERNEL);
if (!otg)
return -ENOMEM;
ddata->dev = &pdev->dev;
ddata->phy.dev = ddata->dev;
ddata->phy.label = "cpcap_usb_phy";
ddata->phy.otg = otg;
ddata->phy.type = USB_PHY_TYPE_USB2;
otg->set_host = cpcap_usb_phy_set_host;
otg->set_peripheral = cpcap_usb_phy_set_peripheral;
otg->usb_phy = &ddata->phy;
INIT_DELAYED_WORK(&ddata->detect_work, cpcap_usb_detect);
platform_set_drvdata(pdev, ddata);
ddata->vusb = devm_regulator_get(&pdev->dev, "vusb");
if (IS_ERR(ddata->vusb))
return PTR_ERR(ddata->vusb);
error = regulator_enable(ddata->vusb);
if (error)
return error;
generic_phy = devm_phy_create(ddata->dev, NULL, &ops);
if (IS_ERR(generic_phy)) {
error = PTR_ERR(generic_phy);
return PTR_ERR(generic_phy);
}
phy_set_drvdata(generic_phy, ddata);
phy_provider = devm_of_phy_provider_register(ddata->dev,
of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
error = cpcap_usb_init_optional_pins(ddata);
if (error)
return error;
cpcap_usb_init_optional_gpios(ddata);
error = cpcap_usb_init_iio(ddata);
if (error)
return error;
error = cpcap_usb_init_interrupts(pdev, ddata);
if (error)
return error;
usb_add_phy_dev(&ddata->phy);
atomic_set(&ddata->active, 1);
schedule_delayed_work(&ddata->detect_work, msecs_to_jiffies(1));
return 0;
}
static int cpcap_usb_phy_remove(struct platform_device *pdev)
{
struct cpcap_phy_ddata *ddata = platform_get_drvdata(pdev);
int error;
atomic_set(&ddata->active, 0);
error = cpcap_usb_set_uart_mode(ddata);
if (error)
dev_err(ddata->dev, "could not set UART mode\n");
error = musb_mailbox(MUSB_VBUS_OFF);
if (error)
dev_err(ddata->dev, "could not set mailbox\n");
usb_remove_phy(&ddata->phy);
cancel_delayed_work_sync(&ddata->detect_work);
clk_unprepare(ddata->refclk);
regulator_disable(ddata->vusb);
return 0;
}
