static unsigned int titsc_readl(struct titsc *ts, unsigned int reg)
{
return readl(ts->mfd_tscadc->tscadc_base + reg);
}
static void titsc_writel(struct titsc *tsc, unsigned int reg,
unsigned int val)
{
writel(val, tsc->mfd_tscadc->tscadc_base + reg);
}
static void titsc_step_config(struct titsc *ts_dev)
{
unsigned int config;
int i, total_steps;
total_steps = 2 * ts_dev->steps_to_configure;
config = STEPCONFIG_MODE_HWSYNC |
STEPCONFIG_AVG_16 | STEPCONFIG_XPP;
switch (ts_dev->wires) {
case 4:
config |= STEPCONFIG_INP_AN2 | STEPCONFIG_XNN;
break;
case 5:
config |= STEPCONFIG_YNN |
STEPCONFIG_INP_AN4 | STEPCONFIG_XNN |
STEPCONFIG_YPP;
break;
case 8:
config |= STEPCONFIG_INP_AN2 | STEPCONFIG_XNN;
break;
}
for (i = 1; i <= ts_dev->steps_to_configure; i++) {
titsc_writel(ts_dev, REG_STEPCONFIG(i), config);
titsc_writel(ts_dev, REG_STEPDELAY(i), STEPCONFIG_OPENDLY);
}
config = 0;
config = STEPCONFIG_MODE_HWSYNC |
STEPCONFIG_AVG_16 | STEPCONFIG_YNN |
STEPCONFIG_INM_ADCREFM | STEPCONFIG_FIFO1;
switch (ts_dev->wires) {
case 4:
config |= STEPCONFIG_YPP;
break;
case 5:
config |= STEPCONFIG_XPP | STEPCONFIG_INP_AN4 |
STEPCONFIG_XNP | STEPCONFIG_YPN;
break;
case 8:
config |= STEPCONFIG_YPP;
break;
}
for (i = (ts_dev->steps_to_configure + 1); i <= total_steps; i++) {
titsc_writel(ts_dev, REG_STEPCONFIG(i), config);
titsc_writel(ts_dev, REG_STEPDELAY(i), STEPCONFIG_OPENDLY);
}
config = 0;
config = STEPCONFIG_XPP | STEPCONFIG_YNN |
STEPCHARGE_RFP_XPUL | STEPCHARGE_RFM_XNUR |
STEPCHARGE_INM_AN1 | STEPCHARGE_INP_AN1;
titsc_writel(ts_dev, REG_CHARGECONFIG, config);
titsc_writel(ts_dev, REG_CHARGEDELAY, CHARGEDLY_OPENDLY);
config = 0;
config = STEPCONFIG_MODE_HWSYNC |
STEPCONFIG_AVG_16 | STEPCONFIG_YPP |
STEPCONFIG_XNN | STEPCONFIG_INM_ADCREFM;
titsc_writel(ts_dev, REG_STEPCONFIG(total_steps + 1), config);
titsc_writel(ts_dev, REG_STEPDELAY(total_steps + 1),
STEPCONFIG_OPENDLY);
config |= STEPCONFIG_INP_AN3 | STEPCONFIG_FIFO1;
titsc_writel(ts_dev, REG_STEPCONFIG(total_steps + 2), config);
titsc_writel(ts_dev, REG_STEPDELAY(total_steps + 2),
STEPCONFIG_OPENDLY);
titsc_writel(ts_dev, REG_SE, STPENB_STEPENB_TC);
}
static void titsc_read_coordinates(struct titsc *ts_dev,
unsigned int *x, unsigned int *y)
{
unsigned int fifocount = titsc_readl(ts_dev, REG_FIFO0CNT);
unsigned int prev_val_x = ~0, prev_val_y = ~0;
unsigned int prev_diff_x = ~0, prev_diff_y = ~0;
unsigned int read, diff;
unsigned int i, channel;
for (i = 0; i < fifocount - 1; i++) {
read = titsc_readl(ts_dev, REG_FIFO0);
channel = read & 0xf0000;
channel = channel >> 0x10;
if ((channel >= 0) && (channel < ts_dev->steps_to_configure)) {
read &= 0xfff;
diff = abs(read - prev_val_x);
if (diff < prev_diff_x) {
prev_diff_x = diff;
*x = read;
}
prev_val_x = read;
}
read = titsc_readl(ts_dev, REG_FIFO1);
channel = read & 0xf0000;
channel = channel >> 0x10;
if ((channel >= ts_dev->steps_to_configure) &&
(channel < (2 * ts_dev->steps_to_configure - 1))) {
read &= 0xfff;
diff = abs(read - prev_val_y);
if (diff < prev_diff_y) {
prev_diff_y = diff;
*y = read;
}
prev_val_y = read;
}
}
}
static irqreturn_t titsc_irq(int irq, void *dev)
{
struct titsc *ts_dev = dev;
struct input_dev *input_dev = ts_dev->input;
unsigned int status, irqclr = 0;
unsigned int x = 0, y = 0;
unsigned int z1, z2, z;
unsigned int fsm;
unsigned int fifo1count, fifo0count;
int i;
status = titsc_readl(ts_dev, REG_IRQSTATUS);
if (status & IRQENB_FIFO0THRES) {
titsc_read_coordinates(ts_dev, &x, &y);
z1 = titsc_readl(ts_dev, REG_FIFO0) & 0xfff;
z2 = titsc_readl(ts_dev, REG_FIFO1) & 0xfff;
fifo1count = titsc_readl(ts_dev, REG_FIFO1CNT);
for (i = 0; i < fifo1count; i++)
titsc_readl(ts_dev, REG_FIFO1);
fifo0count = titsc_readl(ts_dev, REG_FIFO0CNT);
for (i = 0; i < fifo0count; i++)
titsc_readl(ts_dev, REG_FIFO0);
if (ts_dev->pen_down && z1 != 0 && z2 != 0) {
z = z2 - z1;
z *= x;
z *= ts_dev->x_plate_resistance;
z /= z1;
z = (z + 2047) >> 12;
if (z <= MAX_12BIT) {
input_report_abs(input_dev, ABS_X, x);
input_report_abs(input_dev, ABS_Y, y);
input_report_abs(input_dev, ABS_PRESSURE, z);
input_report_key(input_dev, BTN_TOUCH, 1);
input_sync(input_dev);
}
}
irqclr |= IRQENB_FIFO0THRES;
}
udelay(SEQ_SETTLE);
status = titsc_readl(ts_dev, REG_RAWIRQSTATUS);
if (status & IRQENB_PENUP) {
fsm = titsc_readl(ts_dev, REG_ADCFSM);
if (fsm == ADCFSM_STEPID) {
ts_dev->pen_down = false;
input_report_key(input_dev, BTN_TOUCH, 0);
input_report_abs(input_dev, ABS_PRESSURE, 0);
input_sync(input_dev);
} else {
ts_dev->pen_down = true;
}
irqclr |= IRQENB_PENUP;
}
titsc_writel(ts_dev, REG_IRQSTATUS, irqclr);
titsc_writel(ts_dev, REG_SE, STPENB_STEPENB_TC);
return IRQ_HANDLED;
}
static int titsc_probe(struct platform_device *pdev)
{
struct titsc *ts_dev;
struct input_dev *input_dev;
struct ti_tscadc_dev *tscadc_dev = pdev->dev.platform_data;
struct mfd_tscadc_board *pdata;
int err;
pdata = tscadc_dev->dev->platform_data;
if (!pdata) {
dev_err(&pdev->dev, "Could not find platform data\n");
return -EINVAL;
}
ts_dev = kzalloc(sizeof(struct titsc), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ts_dev || !input_dev) {
dev_err(&pdev->dev, "failed to allocate memory.\n");
err = -ENOMEM;
goto err_free_mem;
}
tscadc_dev->tsc = ts_dev;
ts_dev->mfd_tscadc = tscadc_dev;
ts_dev->input = input_dev;
ts_dev->irq = tscadc_dev->irq;
ts_dev->wires = pdata->tsc_init->wires;
ts_dev->x_plate_resistance = pdata->tsc_init->x_plate_resistance;
ts_dev->steps_to_configure = pdata->tsc_init->steps_to_configure;
err = request_irq(ts_dev->irq, titsc_irq,
0, pdev->dev.driver->name, ts_dev);
if (err) {
dev_err(&pdev->dev, "failed to allocate irq.\n");
goto err_free_mem;
}
titsc_writel(ts_dev, REG_IRQENABLE, IRQENB_FIFO0THRES);
titsc_step_config(ts_dev);
titsc_writel(ts_dev, REG_FIFO0THR, ts_dev->steps_to_configure);
input_dev->name = "ti-tsc";
input_dev->dev.parent = &pdev->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, MAX_12BIT, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, MAX_12BIT, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, MAX_12BIT, 0, 0);
err = input_register_device(input_dev);
if (err)
goto err_free_irq;
platform_set_drvdata(pdev, ts_dev);
return 0;
err_free_irq:
free_irq(ts_dev->irq, ts_dev);
err_free_mem:
input_free_device(input_dev);
kfree(ts_dev);
return err;
}
static int titsc_remove(struct platform_device *pdev)
{
struct ti_tscadc_dev *tscadc_dev = pdev->dev.platform_data;
struct titsc *ts_dev = tscadc_dev->tsc;
free_irq(ts_dev->irq, ts_dev);
input_unregister_device(ts_dev->input);
platform_set_drvdata(pdev, NULL);
kfree(ts_dev);
return 0;
}
static int titsc_suspend(struct device *dev)
{
struct ti_tscadc_dev *tscadc_dev = dev->platform_data;
struct titsc *ts_dev = tscadc_dev->tsc;
unsigned int idle;
if (device_may_wakeup(tscadc_dev->dev)) {
idle = titsc_readl(ts_dev, REG_IRQENABLE);
titsc_writel(ts_dev, REG_IRQENABLE,
(idle | IRQENB_HW_PEN));
titsc_writel(ts_dev, REG_IRQWAKEUP, IRQWKUP_ENB);
}
return 0;
}
static int titsc_resume(struct device *dev)
{
struct ti_tscadc_dev *tscadc_dev = dev->platform_data;
struct titsc *ts_dev = tscadc_dev->tsc;
if (device_may_wakeup(tscadc_dev->dev)) {
titsc_writel(ts_dev, REG_IRQWAKEUP,
0x00);
titsc_writel(ts_dev, REG_IRQCLR, IRQENB_HW_PEN);
}
titsc_step_config(ts_dev);
titsc_writel(ts_dev, REG_FIFO0THR,
ts_dev->steps_to_configure);
return 0;
}
