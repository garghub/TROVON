static void sun4i_ts_irq_handle_input(struct sun4i_ts_data *ts, u32 reg_val)
{
u32 x, y;
if (reg_val & FIFO_DATA_PENDING) {
x = readl(ts->base + TP_DATA);
y = readl(ts->base + TP_DATA);
if (!ts->ignore_fifo_data) {
input_report_abs(ts->input, ABS_X, x);
input_report_abs(ts->input, ABS_Y, y);
input_report_key(ts->input, BTN_TOUCH, 1);
input_sync(ts->input);
} else {
ts->ignore_fifo_data = false;
}
}
if (reg_val & TP_UP_PENDING) {
ts->ignore_fifo_data = true;
input_report_key(ts->input, BTN_TOUCH, 0);
input_sync(ts->input);
}
}
static irqreturn_t sun4i_ts_irq(int irq, void *dev_id)
{
struct sun4i_ts_data *ts = dev_id;
u32 reg_val;
reg_val = readl(ts->base + TP_INT_FIFOS);
if (reg_val & TEMP_DATA_PENDING)
ts->temp_data = readl(ts->base + TEMP_DATA);
if (ts->input)
sun4i_ts_irq_handle_input(ts, reg_val);
writel(reg_val, ts->base + TP_INT_FIFOS);
return IRQ_HANDLED;
}
static int sun4i_ts_open(struct input_dev *dev)
{
struct sun4i_ts_data *ts = input_get_drvdata(dev);
writel(TEMP_IRQ_EN(1) | DATA_IRQ_EN(1) | FIFO_TRIG(1) | FIFO_FLUSH(1) |
TP_UP_IRQ_EN(1), ts->base + TP_INT_FIFOC);
return 0;
}
static void sun4i_ts_close(struct input_dev *dev)
{
struct sun4i_ts_data *ts = input_get_drvdata(dev);
writel(TEMP_IRQ_EN(1), ts->base + TP_INT_FIFOC);
}
static int sun4i_get_temp(const struct sun4i_ts_data *ts, int *temp)
{
if (ts->temp_data == -1)
return -EAGAIN;
*temp = ts->temp_data * ts->temp_step - ts->temp_offset;
return 0;
}
static int sun4i_get_tz_temp(void *data, int *temp)
{
return sun4i_get_temp(data, temp);
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sun4i_ts_data *ts = dev_get_drvdata(dev);
int temp;
int error;
error = sun4i_get_temp(ts, &temp);
if (error)
return error;
return sprintf(buf, "%d\n", temp);
}
static ssize_t show_temp_label(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "SoC temperature\n");
}
static int sun4i_ts_probe(struct platform_device *pdev)
{
struct sun4i_ts_data *ts;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device *hwmon;
int error;
u32 reg;
bool ts_attached;
u32 tp_sensitive_adjust = 15;
u32 filter_type = 1;
ts = devm_kzalloc(dev, sizeof(struct sun4i_ts_data), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->dev = dev;
ts->ignore_fifo_data = true;
ts->temp_data = -1;
if (of_device_is_compatible(np, "allwinner,sun6i-a31-ts")) {
ts->temp_offset = 271000;
ts->temp_step = 167;
} else if (of_device_is_compatible(np, "allwinner,sun4i-a10-ts")) {
ts->temp_offset = 257000;
ts->temp_step = 133;
} else {
ts->temp_offset = 144700;
ts->temp_step = 100;
}
ts_attached = of_property_read_bool(np, "allwinner,ts-attached");
if (ts_attached) {
ts->input = devm_input_allocate_device(dev);
if (!ts->input)
return -ENOMEM;
ts->input->name = pdev->name;
ts->input->phys = "sun4i_ts/input0";
ts->input->open = sun4i_ts_open;
ts->input->close = sun4i_ts_close;
ts->input->id.bustype = BUS_HOST;
ts->input->id.vendor = 0x0001;
ts->input->id.product = 0x0001;
ts->input->id.version = 0x0100;
ts->input->evbit[0] = BIT(EV_SYN) | BIT(EV_KEY) | BIT(EV_ABS);
__set_bit(BTN_TOUCH, ts->input->keybit);
input_set_abs_params(ts->input, ABS_X, 0, 4095, 0, 0);
input_set_abs_params(ts->input, ABS_Y, 0, 4095, 0, 0);
input_set_drvdata(ts->input, ts);
}
ts->base = devm_ioremap_resource(dev,
platform_get_resource(pdev, IORESOURCE_MEM, 0));
if (IS_ERR(ts->base))
return PTR_ERR(ts->base);
ts->irq = platform_get_irq(pdev, 0);
error = devm_request_irq(dev, ts->irq, sun4i_ts_irq, 0, "sun4i-ts", ts);
if (error)
return error;
writel(ADC_CLK_SEL(0) | ADC_CLK_DIV(2) | FS_DIV(7) | T_ACQ(63),
ts->base + TP_CTRL0);
of_property_read_u32(np, "allwinner,tp-sensitive-adjust",
&tp_sensitive_adjust);
writel(TP_SENSITIVE_ADJUST(tp_sensitive_adjust) | TP_MODE_SELECT(0),
ts->base + TP_CTRL2);
of_property_read_u32(np, "allwinner,filter-type", &filter_type);
writel(FILTER_EN(1) | FILTER_TYPE(filter_type), ts->base + TP_CTRL3);
writel(TEMP_ENABLE(1) | TEMP_PERIOD(1953), ts->base + TP_TPR);
reg = STYLUS_UP_DEBOUN(5) | STYLUS_UP_DEBOUN_EN(1);
if (of_device_is_compatible(np, "allwinner,sun6i-a31-ts"))
reg |= SUN6I_TP_MODE_EN(1);
else
reg |= TP_MODE_EN(1);
writel(reg, ts->base + TP_CTRL1);
hwmon = devm_hwmon_device_register_with_groups(ts->dev, "sun4i_ts",
ts, sun4i_ts_groups);
if (IS_ERR(hwmon))
return PTR_ERR(hwmon);
devm_thermal_zone_of_sensor_register(ts->dev, 0, ts, &sun4i_ts_tz_ops);
writel(TEMP_IRQ_EN(1), ts->base + TP_INT_FIFOC);
if (ts_attached) {
error = input_register_device(ts->input);
if (error) {
writel(0, ts->base + TP_INT_FIFOC);
return error;
}
}
platform_set_drvdata(pdev, ts);
return 0;
}
static int sun4i_ts_remove(struct platform_device *pdev)
{
struct sun4i_ts_data *ts = platform_get_drvdata(pdev);
if (ts->input)
input_unregister_device(ts->input);
writel(0, ts->base + TP_INT_FIFOC);
return 0;
}
