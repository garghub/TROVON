static void da9052_ts_adc_toggle(struct da9052_tsi *tsi, bool on)
{
da9052_reg_update(tsi->da9052, DA9052_TSI_CONT_A_REG, 1 << 0, on);
tsi->adc_on = on;
}
static irqreturn_t da9052_ts_pendwn_irq(int irq, void *data)
{
struct da9052_tsi *tsi = data;
if (!tsi->stopped) {
disable_irq_nosync(tsi->irq_pendwn);
enable_irq(tsi->irq_datardy);
da9052_ts_adc_toggle(tsi, true);
schedule_delayed_work(&tsi->ts_pen_work, HZ / 50);
}
return IRQ_HANDLED;
}
static void da9052_ts_read(struct da9052_tsi *tsi)
{
struct input_dev *input = tsi->dev;
int ret;
u16 x, y, z;
u8 v;
ret = da9052_reg_read(tsi->da9052, DA9052_TSI_X_MSB_REG);
if (ret < 0)
return;
x = (u16) ret;
ret = da9052_reg_read(tsi->da9052, DA9052_TSI_Y_MSB_REG);
if (ret < 0)
return;
y = (u16) ret;
ret = da9052_reg_read(tsi->da9052, DA9052_TSI_Z_MSB_REG);
if (ret < 0)
return;
z = (u16) ret;
ret = da9052_reg_read(tsi->da9052, DA9052_TSI_LSB_REG);
if (ret < 0)
return;
v = (u8) ret;
x = ((x << 2) & 0x3fc) | (v & 0x3);
y = ((y << 2) & 0x3fc) | ((v & 0xc) >> 2);
z = ((z << 2) & 0x3fc) | ((v & 0x30) >> 4);
input_report_key(input, BTN_TOUCH, 1);
input_report_abs(input, ABS_X, x);
input_report_abs(input, ABS_Y, y);
input_report_abs(input, ABS_PRESSURE, z);
input_sync(input);
}
static irqreturn_t da9052_ts_datardy_irq(int irq, void *data)
{
struct da9052_tsi *tsi = data;
da9052_ts_read(tsi);
return IRQ_HANDLED;
}
static void da9052_ts_pen_work(struct work_struct *work)
{
struct da9052_tsi *tsi = container_of(work, struct da9052_tsi,
ts_pen_work.work);
if (!tsi->stopped) {
int ret = da9052_reg_read(tsi->da9052, DA9052_TSI_LSB_REG);
if (ret < 0 || (ret & TSI_PEN_DOWN_STATUS)) {
schedule_delayed_work(&tsi->ts_pen_work, HZ / 50);
} else {
struct input_dev *input = tsi->dev;
da9052_ts_adc_toggle(tsi, false);
input_report_key(input, BTN_TOUCH, 0);
input_report_abs(input, ABS_PRESSURE, 0);
input_sync(input);
ret = da9052_reg_update(tsi->da9052,
DA9052_EVENT_B_REG, 0xC0, 0xC0);
if (ret < 0)
return;
disable_irq(tsi->irq_datardy);
enable_irq(tsi->irq_pendwn);
}
}
}
static int __devinit da9052_ts_configure_gpio(struct da9052 *da9052)
{
int error;
error = da9052_reg_update(da9052, DA9052_GPIO_2_3_REG, 0x30, 0);
if (error < 0)
return error;
error = da9052_reg_update(da9052, DA9052_GPIO_4_5_REG, 0x33, 0);
if (error < 0)
return error;
error = da9052_reg_update(da9052, DA9052_GPIO_6_7_REG, 0x33, 0);
if (error < 0)
return error;
return 0;
}
static int __devinit da9052_configure_tsi(struct da9052_tsi *tsi)
{
int error;
error = da9052_ts_configure_gpio(tsi->da9052);
if (error)
return error;
error = da9052_reg_update(tsi->da9052, DA9052_ADC_CONT_REG,
1 << 6, 1 << 6);
if (error < 0)
return error;
error = da9052_reg_update(tsi->da9052, DA9052_TSI_CONT_A_REG, 0xFC, 0xC0);
if (error < 0)
return error;
error = da9052_reg_write(tsi->da9052, DA9052_LDO9_REG, 0x59);
if (error < 0)
return error;
return 0;
}
static int da9052_ts_input_open(struct input_dev *input_dev)
{
struct da9052_tsi *tsi = input_get_drvdata(input_dev);
tsi->stopped = false;
mb();
enable_irq(tsi->irq_pendwn);
return da9052_reg_update(tsi->da9052, DA9052_TSI_CONT_A_REG,
1 << 1, 1 << 1);
}
static void da9052_ts_input_close(struct input_dev *input_dev)
{
struct da9052_tsi *tsi = input_get_drvdata(input_dev);
tsi->stopped = true;
mb();
disable_irq(tsi->irq_pendwn);
cancel_delayed_work_sync(&tsi->ts_pen_work);
if (tsi->adc_on) {
disable_irq(tsi->irq_datardy);
da9052_ts_adc_toggle(tsi, false);
enable_irq(tsi->irq_pendwn);
}
da9052_reg_update(tsi->da9052, DA9052_TSI_CONT_A_REG, 1 << 1, 0);
}
static int __devinit da9052_ts_probe(struct platform_device *pdev)
{
struct da9052 *da9052;
struct da9052_tsi *tsi;
struct input_dev *input_dev;
int irq_pendwn;
int irq_datardy;
int error;
da9052 = dev_get_drvdata(pdev->dev.parent);
if (!da9052)
return -EINVAL;
irq_pendwn = platform_get_irq_byname(pdev, "PENDWN");
irq_datardy = platform_get_irq_byname(pdev, "TSIRDY");
if (irq_pendwn < 0 || irq_datardy < 0) {
dev_err(da9052->dev, "Unable to determine device interrupts\n");
return -ENXIO;
}
tsi = kzalloc(sizeof(struct da9052_tsi), GFP_KERNEL);
input_dev = input_allocate_device();
if (!tsi || !input_dev) {
error = -ENOMEM;
goto err_free_mem;
}
tsi->da9052 = da9052;
tsi->dev = input_dev;
tsi->irq_pendwn = da9052->irq_base + irq_pendwn;
tsi->irq_datardy = da9052->irq_base + irq_datardy;
tsi->stopped = true;
INIT_DELAYED_WORK(&tsi->ts_pen_work, da9052_ts_pen_work);
input_dev->id.version = 0x0101;
input_dev->id.vendor = 0x15B6;
input_dev->id.product = 0x9052;
input_dev->name = "Dialog DA9052 TouchScreen Driver";
input_dev->dev.parent = &pdev->dev;
input_dev->open = da9052_ts_input_open;
input_dev->close = da9052_ts_input_close;
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
input_set_abs_params(input_dev, ABS_X, 0, 1023, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, 1023, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, 1023, 0, 0);
input_set_drvdata(input_dev, tsi);
da9052_reg_update(tsi->da9052, DA9052_TSI_CONT_A_REG, 1 << 1, 0);
da9052_ts_adc_toggle(tsi, false);
error = request_threaded_irq(tsi->irq_pendwn,
NULL, da9052_ts_pendwn_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"PENDWN", tsi);
if (error) {
dev_err(tsi->da9052->dev,
"Failed to register PENDWN IRQ %d, error = %d\n",
tsi->irq_pendwn, error);
goto err_free_mem;
}
error = request_threaded_irq(tsi->irq_datardy,
NULL, da9052_ts_datardy_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"TSIRDY", tsi);
if (error) {
dev_err(tsi->da9052->dev,
"Failed to register TSIRDY IRQ %d, error = %d\n",
tsi->irq_datardy, error);
goto err_free_pendwn_irq;
}
disable_irq(tsi->irq_pendwn);
disable_irq(tsi->irq_datardy);
error = da9052_configure_tsi(tsi);
if (error)
goto err_free_datardy_irq;
error = input_register_device(tsi->dev);
if (error)
goto err_free_datardy_irq;
platform_set_drvdata(pdev, tsi);
return 0;
err_free_datardy_irq:
free_irq(tsi->irq_datardy, tsi);
err_free_pendwn_irq:
free_irq(tsi->irq_pendwn, tsi);
err_free_mem:
kfree(tsi);
input_free_device(input_dev);
return error;
}
static int __devexit da9052_ts_remove(struct platform_device *pdev)
{
struct da9052_tsi *tsi = platform_get_drvdata(pdev);
da9052_reg_write(tsi->da9052, DA9052_LDO9_REG, 0x19);
free_irq(tsi->irq_pendwn, tsi);
free_irq(tsi->irq_datardy, tsi);
input_unregister_device(tsi->dev);
kfree(tsi);
platform_set_drvdata(pdev, NULL);
return 0;
}
