static void ts_reg_dump(struct iproc_ts_priv *priv)
{
struct device *dev = &priv->pdev->dev;
dbg_reg(dev, priv, REGCTL1);
dbg_reg(dev, priv, REGCTL2);
dbg_reg(dev, priv, INTERRUPT_THRES);
dbg_reg(dev, priv, INTERRUPT_MASK);
dbg_reg(dev, priv, INTERRUPT_STATUS);
dbg_reg(dev, priv, CONTROLLER_STATUS);
dbg_reg(dev, priv, FIFO_DATA);
dbg_reg(dev, priv, ANALOG_CONTROL);
dbg_reg(dev, priv, AUX_DATA);
dbg_reg(dev, priv, DEBOUNCE_CNTR_STAT);
dbg_reg(dev, priv, SCAN_CNTR_STAT);
dbg_reg(dev, priv, REM_CNTR_STAT);
dbg_reg(dev, priv, SETTLING_TIMER_STAT);
dbg_reg(dev, priv, SPARE_REG);
dbg_reg(dev, priv, SOFT_BYPASS_CONTROL);
dbg_reg(dev, priv, SOFT_BYPASS_DATA);
}
static irqreturn_t iproc_touchscreen_interrupt(int irq, void *data)
{
struct platform_device *pdev = data;
struct iproc_ts_priv *priv = platform_get_drvdata(pdev);
u32 intr_status;
u32 raw_coordinate;
u16 x;
u16 y;
int i;
bool needs_sync = false;
intr_status = readl(priv->regs + INTERRUPT_STATUS);
intr_status &= TS_PEN_INTR_MASK | TS_FIFO_INTR_MASK;
if (intr_status == 0)
return IRQ_NONE;
writel(intr_status, priv->regs + INTERRUPT_STATUS);
if (intr_status & TS_PEN_INTR_MASK) {
if (readl(priv->regs + CONTROLLER_STATUS) & TS_PEN_DOWN)
priv->pen_status = PEN_DOWN_STATUS;
else
priv->pen_status = PEN_UP_STATUS;
input_report_key(priv->idev, BTN_TOUCH, priv->pen_status);
needs_sync = true;
dev_dbg(&priv->pdev->dev,
"pen up-down (%d)\n", priv->pen_status);
}
if (intr_status & TS_FIFO_INTR_MASK) {
for (i = 0; i < priv->cfg_params.fifo_threshold; i++) {
raw_coordinate = readl(priv->regs + FIFO_DATA);
if (raw_coordinate == INVALID_COORD)
continue;
x = (raw_coordinate >> X_COORD_SHIFT) &
FIFO_DATA_X_Y_MASK;
y = (raw_coordinate >> Y_COORD_SHIFT) &
FIFO_DATA_X_Y_MASK;
x = (x >> 4) & 0x0FFF;
y = (y >> 4) & 0x0FFF;
if (priv->cfg_params.invert_x)
x = priv->cfg_params.max_x - x;
if (priv->cfg_params.invert_y)
y = priv->cfg_params.max_y - y;
input_report_abs(priv->idev, ABS_X, x);
input_report_abs(priv->idev, ABS_Y, y);
needs_sync = true;
dev_dbg(&priv->pdev->dev, "xy (0x%x 0x%x)\n", x, y);
}
}
if (needs_sync)
input_sync(priv->idev);
return IRQ_HANDLED;
}
static int iproc_ts_start(struct input_dev *idev)
{
struct iproc_ts_priv *priv = input_get_drvdata(idev);
u32 val;
int error;
error = clk_prepare_enable(priv->tsc_clk);
if (error) {
dev_err(&priv->pdev->dev, "%s clk_prepare_enable failed %d\n",
__func__, error);
return error;
}
val = TS_PEN_INTR_MASK | TS_FIFO_INTR_MASK;
writel(val, priv->regs + INTERRUPT_MASK);
writel(priv->cfg_params.fifo_threshold, priv->regs + INTERRUPT_THRES);
val = 0;
val |= priv->cfg_params.scanning_period << SCANNING_PERIOD_SHIFT;
val |= priv->cfg_params.debounce_timeout << DEBOUNCE_TIMEOUT_SHIFT;
val |= priv->cfg_params.settling_timeout << SETTLING_TIMEOUT_SHIFT;
val |= priv->cfg_params.touch_timeout << TOUCH_TIMEOUT_SHIFT;
writel(val, priv->regs + REGCTL1);
val = readl(priv->regs + INTERRUPT_STATUS);
val |= TS_FIFO_INTR_MASK | TS_PEN_INTR_MASK;
writel(val, priv->regs + INTERRUPT_STATUS);
val = readl(priv->regs + REGCTL2);
val |= TS_CONTROLLER_EN_BIT | TS_WIRE_MODE_BIT;
val &= ~TS_CONTROLLER_AVGDATA_MASK;
val |= priv->cfg_params.average_data << TS_CONTROLLER_AVGDATA_SHIFT;
val &= ~(TS_CONTROLLER_PWR_LDO |
TS_CONTROLLER_PWR_ADC |
TS_CONTROLLER_PWR_BGP |
TS_CONTROLLER_PWR_TS);
writel(val, priv->regs + REGCTL2);
ts_reg_dump(priv);
return 0;
}
static void iproc_ts_stop(struct input_dev *dev)
{
u32 val;
struct iproc_ts_priv *priv = input_get_drvdata(dev);
writel(0, priv->regs + INTERRUPT_MASK);
val = readl(priv->regs + REGCTL2);
val |= TS_CONTROLLER_PWR_TS;
writel(val, priv->regs + REGCTL2);
clk_disable(priv->tsc_clk);
}
static int iproc_get_tsc_config(struct device *dev, struct iproc_ts_priv *priv)
{
struct device_node *np = dev->of_node;
u32 val;
priv->cfg_params = iproc_default_config;
if (!np)
return 0;
if (of_property_read_u32(np, "scanning_period", &val) >= 0) {
if (val < 1 || val > 256) {
dev_err(dev, "scanning_period (%u) must be [1-256]\n",
val);
return -EINVAL;
}
priv->cfg_params.scanning_period = val;
}
if (of_property_read_u32(np, "debounce_timeout", &val) >= 0) {
if (val > 255) {
dev_err(dev, "debounce_timeout (%u) must be [0-255]\n",
val);
return -EINVAL;
}
priv->cfg_params.debounce_timeout = val;
}
if (of_property_read_u32(np, "settling_timeout", &val) >= 0) {
if (val > 11) {
dev_err(dev, "settling_timeout (%u) must be [0-11]\n",
val);
return -EINVAL;
}
priv->cfg_params.settling_timeout = val;
}
if (of_property_read_u32(np, "touch_timeout", &val) >= 0) {
if (val > 255) {
dev_err(dev, "touch_timeout (%u) must be [0-255]\n",
val);
return -EINVAL;
}
priv->cfg_params.touch_timeout = val;
}
if (of_property_read_u32(np, "average_data", &val) >= 0) {
if (val > 8) {
dev_err(dev, "average_data (%u) must be [0-8]\n", val);
return -EINVAL;
}
priv->cfg_params.average_data = val;
}
if (of_property_read_u32(np, "fifo_threshold", &val) >= 0) {
if (val > 31) {
dev_err(dev, "fifo_threshold (%u)) must be [0-31]\n",
val);
return -EINVAL;
}
priv->cfg_params.fifo_threshold = val;
}
of_property_read_u32(np, "touchscreen-size-x", &priv->cfg_params.max_x);
of_property_read_u32(np, "touchscreen-size-y", &priv->cfg_params.max_y);
of_property_read_u32(np, "touchscreen-fuzz-x",
&priv->cfg_params.fuzz_x);
of_property_read_u32(np, "touchscreen-fuzz-y",
&priv->cfg_params.fuzz_y);
priv->cfg_params.invert_x =
of_property_read_bool(np, "touchscreen-inverted-x");
priv->cfg_params.invert_y =
of_property_read_bool(np, "touchscreen-inverted-y");
return 0;
}
static int iproc_ts_probe(struct platform_device *pdev)
{
struct iproc_ts_priv *priv;
struct input_dev *idev;
struct resource *res;
int irq;
int error;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->regs)) {
error = PTR_ERR(priv->regs);
dev_err(&pdev->dev, "unable to map I/O memory: %d\n", error);
return error;
}
priv->tsc_clk = devm_clk_get(&pdev->dev, "tsc_clk");
if (IS_ERR(priv->tsc_clk)) {
error = PTR_ERR(priv->tsc_clk);
dev_err(&pdev->dev,
"failed getting clock tsc_clk: %d\n", error);
return error;
}
priv->pdev = pdev;
error = iproc_get_tsc_config(&pdev->dev, priv);
if (error) {
dev_err(&pdev->dev, "get_tsc_config failed: %d\n", error);
return error;
}
idev = devm_input_allocate_device(&pdev->dev);
if (!idev) {
dev_err(&pdev->dev, "failed to allocate input device\n");
return -ENOMEM;
}
priv->idev = idev;
priv->pen_status = PEN_UP_STATUS;
idev->name = IPROC_TS_NAME;
idev->dev.parent = &pdev->dev;
idev->id.bustype = BUS_HOST;
idev->id.vendor = SERIO_UNKNOWN;
idev->id.product = 0;
idev->id.version = 0;
idev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
__set_bit(BTN_TOUCH, idev->keybit);
input_set_abs_params(idev, ABS_X, X_MIN, priv->cfg_params.max_x,
priv->cfg_params.fuzz_x, 0);
input_set_abs_params(idev, ABS_Y, Y_MIN, priv->cfg_params.max_y,
priv->cfg_params.fuzz_y, 0);
idev->open = iproc_ts_start;
idev->close = iproc_ts_stop;
input_set_drvdata(idev, priv);
platform_set_drvdata(pdev, priv);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "platform_get_irq failed: %d\n", irq);
return irq;
}
error = devm_request_irq(&pdev->dev, irq,
iproc_touchscreen_interrupt,
IRQF_SHARED, IPROC_TS_NAME, pdev);
if (error)
return error;
error = input_register_device(priv->idev);
if (error) {
dev_err(&pdev->dev,
"failed to register input device: %d\n", error);
return error;
}
return 0;
}
