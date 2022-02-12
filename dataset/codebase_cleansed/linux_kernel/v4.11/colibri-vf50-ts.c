static int adc_ts_measure(struct iio_channel *channel,
struct gpio_desc *plate_p, struct gpio_desc *plate_m)
{
int i, value = 0, val = 0;
int error;
gpiod_set_value(plate_p, 1);
gpiod_set_value(plate_m, 1);
usleep_range(COLI_TOUCH_MIN_DELAY_US, COLI_TOUCH_MAX_DELAY_US);
for (i = 0; i < COLI_TOUCH_NO_OF_AVGS; i++) {
error = iio_read_channel_raw(channel, &val);
if (error < 0) {
value = error;
goto error_iio_read;
}
value += val;
}
value /= COLI_TOUCH_NO_OF_AVGS;
error_iio_read:
gpiod_set_value(plate_p, 0);
gpiod_set_value(plate_m, 0);
return value;
}
static void vf50_ts_enable_touch_detection(struct vf50_touch_device *vf50_ts)
{
gpiod_set_value(vf50_ts->gpio_ym, 1);
pinctrl_pm_select_idle_state(&vf50_ts->pdev->dev);
usleep_range(COLI_PULLUP_MIN_DELAY_US, COLI_PULLUP_MAX_DELAY_US);
}
static irqreturn_t vf50_ts_irq_bh(int irq, void *private)
{
struct vf50_touch_device *vf50_ts = private;
struct device *dev = &vf50_ts->pdev->dev;
int val_x, val_y, val_z1, val_z2, val_p = 0;
bool discard_val_on_start = true;
gpiod_set_value(vf50_ts->gpio_ym, 0);
pinctrl_pm_select_default_state(dev);
while (!vf50_ts->stop_touchscreen) {
val_x = adc_ts_measure(&vf50_ts->channels[0],
vf50_ts->gpio_xp, vf50_ts->gpio_xm);
if (val_x < 0)
break;
val_y = adc_ts_measure(&vf50_ts->channels[1],
vf50_ts->gpio_yp, vf50_ts->gpio_ym);
if (val_y < 0)
break;
val_z1 = adc_ts_measure(&vf50_ts->channels[2],
vf50_ts->gpio_yp, vf50_ts->gpio_xm);
if (val_z1 < 0)
break;
val_z2 = adc_ts_measure(&vf50_ts->channels[3],
vf50_ts->gpio_yp, vf50_ts->gpio_xm);
if (val_z2 < 0)
break;
if (val_z1 > 64 && val_x > 64) {
int r_x = (1000 * val_x) / VF_ADC_MAX;
val_p = (r_x * val_z2) / val_z1 - r_x;
} else {
val_p = 2000;
}
val_p = 2000 - val_p;
dev_dbg(dev,
"Measured values: x: %d, y: %d, z1: %d, z2: %d, p: %d\n",
val_x, val_y, val_z1, val_z2, val_p);
if (val_p < vf50_ts->min_pressure || val_p > 2000)
break;
if (discard_val_on_start) {
discard_val_on_start = false;
} else {
input_report_abs(vf50_ts->ts_input,
ABS_X, VF_ADC_MAX - val_x);
input_report_abs(vf50_ts->ts_input,
ABS_Y, VF_ADC_MAX - val_y);
input_report_abs(vf50_ts->ts_input,
ABS_PRESSURE, val_p);
input_report_key(vf50_ts->ts_input, BTN_TOUCH, 1);
input_sync(vf50_ts->ts_input);
}
usleep_range(COLI_PULLUP_MIN_DELAY_US,
COLI_PULLUP_MAX_DELAY_US);
}
input_report_abs(vf50_ts->ts_input, ABS_PRESSURE, 0);
input_report_key(vf50_ts->ts_input, BTN_TOUCH, 0);
input_sync(vf50_ts->ts_input);
vf50_ts_enable_touch_detection(vf50_ts);
return IRQ_HANDLED;
}
static int vf50_ts_open(struct input_dev *dev_input)
{
struct vf50_touch_device *touchdev = input_get_drvdata(dev_input);
struct device *dev = &touchdev->pdev->dev;
dev_dbg(dev, "Input device %s opened, starting touch detection\n",
dev_input->name);
touchdev->stop_touchscreen = false;
vf50_ts_enable_touch_detection(touchdev);
return 0;
}
static void vf50_ts_close(struct input_dev *dev_input)
{
struct vf50_touch_device *touchdev = input_get_drvdata(dev_input);
struct device *dev = &touchdev->pdev->dev;
touchdev->stop_touchscreen = true;
mb();
synchronize_irq(touchdev->pen_irq);
gpiod_set_value(touchdev->gpio_ym, 0);
pinctrl_pm_select_default_state(dev);
dev_dbg(dev, "Input device %s closed, disable touch detection\n",
dev_input->name);
}
static int vf50_ts_get_gpiod(struct device *dev, struct gpio_desc **gpio_d,
const char *con_id, enum gpiod_flags flags)
{
int error;
*gpio_d = devm_gpiod_get(dev, con_id, flags);
if (IS_ERR(*gpio_d)) {
error = PTR_ERR(*gpio_d);
dev_err(dev, "Could not get gpio_%s %d\n", con_id, error);
return error;
}
return 0;
}
static void vf50_ts_channel_release(void *data)
{
struct iio_channel *channels = data;
iio_channel_release_all(channels);
}
static int vf50_ts_probe(struct platform_device *pdev)
{
struct input_dev *input;
struct iio_channel *channels;
struct device *dev = &pdev->dev;
struct vf50_touch_device *touchdev;
int num_adc_channels;
int error;
channels = iio_channel_get_all(dev);
if (IS_ERR(channels))
return PTR_ERR(channels);
error = devm_add_action(dev, vf50_ts_channel_release, channels);
if (error) {
iio_channel_release_all(channels);
dev_err(dev, "Failed to register iio channel release action");
return error;
}
num_adc_channels = 0;
while (channels[num_adc_channels].indio_dev)
num_adc_channels++;
if (num_adc_channels != COLI_TOUCH_REQ_ADC_CHAN) {
dev_err(dev, "Inadequate ADC channels specified\n");
return -EINVAL;
}
touchdev = devm_kzalloc(dev, sizeof(*touchdev), GFP_KERNEL);
if (!touchdev)
return -ENOMEM;
touchdev->pdev = pdev;
touchdev->channels = channels;
error = of_property_read_u32(dev->of_node, "vf50-ts-min-pressure",
&touchdev->min_pressure);
if (error)
return error;
input = devm_input_allocate_device(dev);
if (!input) {
dev_err(dev, "Failed to allocate TS input device\n");
return -ENOMEM;
}
input->name = DRIVER_NAME;
input->id.bustype = BUS_HOST;
input->dev.parent = dev;
input->open = vf50_ts_open;
input->close = vf50_ts_close;
input_set_capability(input, EV_KEY, BTN_TOUCH);
input_set_abs_params(input, ABS_X, 0, VF_ADC_MAX, 0, 0);
input_set_abs_params(input, ABS_Y, 0, VF_ADC_MAX, 0, 0);
input_set_abs_params(input, ABS_PRESSURE, 0, VF_ADC_MAX, 0, 0);
touchdev->ts_input = input;
input_set_drvdata(input, touchdev);
error = input_register_device(input);
if (error) {
dev_err(dev, "Failed to register input device\n");
return error;
}
error = vf50_ts_get_gpiod(dev, &touchdev->gpio_xp, "xp", GPIOD_OUT_LOW);
if (error)
return error;
error = vf50_ts_get_gpiod(dev, &touchdev->gpio_xm,
"xm", GPIOD_OUT_LOW);
if (error)
return error;
error = vf50_ts_get_gpiod(dev, &touchdev->gpio_yp, "yp", GPIOD_OUT_LOW);
if (error)
return error;
error = vf50_ts_get_gpiod(dev, &touchdev->gpio_ym, "ym", GPIOD_OUT_LOW);
if (error)
return error;
touchdev->pen_irq = platform_get_irq(pdev, 0);
if (touchdev->pen_irq < 0)
return touchdev->pen_irq;
error = devm_request_threaded_irq(dev, touchdev->pen_irq,
NULL, vf50_ts_irq_bh, IRQF_ONESHOT,
"vf50 touch", touchdev);
if (error) {
dev_err(dev, "Failed to request IRQ %d: %d\n",
touchdev->pen_irq, error);
return error;
}
return 0;
}
