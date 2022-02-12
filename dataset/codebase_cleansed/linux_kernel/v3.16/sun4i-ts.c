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
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sun4i_ts_data *ts = dev_get_drvdata(dev);
if (ts->temp_data == -1)
return -EAGAIN;
return sprintf(buf, "%d\n", (ts->temp_data - 1447) * 100);
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
bool ts_attached;
ts = devm_kzalloc(dev, sizeof(struct sun4i_ts_data), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->dev = dev;
ts->ignore_fifo_data = true;
ts->temp_data = -1;
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
writel(TP_SENSITIVE_ADJUST(15) | TP_MODE_SELECT(0),
ts->base + TP_CTRL2);
writel(FILTER_EN(1) | FILTER_TYPE(1), ts->base + TP_CTRL3);
writel(TEMP_ENABLE(1) | TEMP_PERIOD(1953), ts->base + TP_TPR);
writel(STYLUS_UP_DEBOUN(5) | STYLUS_UP_DEBOUN_EN(1) | TP_MODE_EN(1),
ts->base + TP_CTRL1);
hwmon = devm_hwmon_device_register_with_groups(ts->dev, "sun4i_ts",
ts, sun4i_ts_groups);
if (IS_ERR(hwmon))
return PTR_ERR(hwmon);
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
