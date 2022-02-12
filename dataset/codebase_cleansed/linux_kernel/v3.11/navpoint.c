static void navpoint_packet(struct navpoint *navpoint)
{
int finger;
int gesture;
int x, y, z;
switch (navpoint->data[0]) {
case 0xff:
case 0x00:
break;
case 0x0e:
finger = (navpoint->data[1] & 0x01);
gesture = (navpoint->data[1] & 0x02);
x = ((navpoint->data[2] & 0x1f) << 8) | navpoint->data[3];
y = ((navpoint->data[4] & 0x1f) << 8) | navpoint->data[5];
z = navpoint->data[6];
input_report_key(navpoint->input, BTN_TOUCH, finger);
input_report_abs(navpoint->input, ABS_X, x);
input_report_abs(navpoint->input, ABS_Y, y);
input_report_abs(navpoint->input, ABS_PRESSURE, z);
input_report_key(navpoint->input, BTN_TOOL_FINGER, finger);
input_report_key(navpoint->input, BTN_LEFT, gesture);
input_sync(navpoint->input);
break;
case 0x19:
if ((navpoint->data[1] & 0xf0) == 0x10)
break;
default:
dev_warn(navpoint->dev,
"spurious packet: data=0x%02x,0x%02x,...\n",
navpoint->data[0], navpoint->data[1]);
break;
}
}
static irqreturn_t navpoint_irq(int irq, void *dev_id)
{
struct navpoint *navpoint = dev_id;
struct ssp_device *ssp = navpoint->ssp;
irqreturn_t ret = IRQ_NONE;
u32 status;
status = pxa_ssp_read_reg(ssp, SSSR);
if (status & sssr) {
dev_warn(navpoint->dev,
"unexpected interrupt: status=0x%08x\n", status);
pxa_ssp_write_reg(ssp, SSSR, (status & sssr));
ret = IRQ_HANDLED;
}
while (status & SSSR_RNE) {
u32 data;
data = pxa_ssp_read_reg(ssp, SSDR);
navpoint->data[navpoint->index + 0] = (data >> 8);
navpoint->data[navpoint->index + 1] = data;
navpoint->index += 2;
if (HEADER_LENGTH(navpoint->data[0]) < navpoint->index) {
navpoint_packet(navpoint);
navpoint->index = 0;
}
status = pxa_ssp_read_reg(ssp, SSSR);
ret = IRQ_HANDLED;
}
return ret;
}
static void navpoint_up(struct navpoint *navpoint)
{
struct ssp_device *ssp = navpoint->ssp;
int timeout;
clk_prepare_enable(ssp->clk);
pxa_ssp_write_reg(ssp, SSCR1, sscr1);
pxa_ssp_write_reg(ssp, SSSR, sssr);
pxa_ssp_write_reg(ssp, SSTO, 0);
pxa_ssp_write_reg(ssp, SSCR0, sscr0);
for (timeout = 100; timeout != 0; --timeout) {
if (!(pxa_ssp_read_reg(ssp, SSSR) & SSSR_CSS))
break;
msleep(1);
}
if (timeout == 0)
dev_err(navpoint->dev,
"timeout waiting for SSSR[CSS] to clear\n");
if (gpio_is_valid(navpoint->gpio))
gpio_set_value(navpoint->gpio, 1);
}
static void navpoint_down(struct navpoint *navpoint)
{
struct ssp_device *ssp = navpoint->ssp;
if (gpio_is_valid(navpoint->gpio))
gpio_set_value(navpoint->gpio, 0);
pxa_ssp_write_reg(ssp, SSCR0, 0);
clk_disable_unprepare(ssp->clk);
}
static int navpoint_open(struct input_dev *input)
{
struct navpoint *navpoint = input_get_drvdata(input);
navpoint_up(navpoint);
return 0;
}
static void navpoint_close(struct input_dev *input)
{
struct navpoint *navpoint = input_get_drvdata(input);
navpoint_down(navpoint);
}
static int navpoint_probe(struct platform_device *pdev)
{
const struct navpoint_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct ssp_device *ssp;
struct input_dev *input;
struct navpoint *navpoint;
int error;
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
return -EINVAL;
}
if (gpio_is_valid(pdata->gpio)) {
error = gpio_request_one(pdata->gpio, GPIOF_OUT_INIT_LOW,
"SYNAPTICS_ON");
if (error)
return error;
}
ssp = pxa_ssp_request(pdata->port, pdev->name);
if (!ssp) {
error = -ENODEV;
goto err_free_gpio;
}
if (pxa_ssp_read_reg(ssp, SSCR0) & SSCR0_SSE) {
pxa_ssp_write_reg(ssp, SSCR0, 0);
dev_warn(&pdev->dev, "ssp%d already enabled\n", pdata->port);
}
navpoint = kzalloc(sizeof(*navpoint), GFP_KERNEL);
input = input_allocate_device();
if (!navpoint || !input) {
error = -ENOMEM;
goto err_free_mem;
}
navpoint->ssp = ssp;
navpoint->input = input;
navpoint->dev = &pdev->dev;
navpoint->gpio = pdata->gpio;
input->name = pdev->name;
input->dev.parent = &pdev->dev;
__set_bit(EV_KEY, input->evbit);
__set_bit(EV_ABS, input->evbit);
__set_bit(BTN_LEFT, input->keybit);
__set_bit(BTN_TOUCH, input->keybit);
__set_bit(BTN_TOOL_FINGER, input->keybit);
input_set_abs_params(input, ABS_X,
NAVPOINT_X_MIN, NAVPOINT_X_MAX, 0, 0);
input_set_abs_params(input, ABS_Y,
NAVPOINT_Y_MIN, NAVPOINT_Y_MAX, 0, 0);
input_set_abs_params(input, ABS_PRESSURE,
NAVPOINT_PRESSURE_MIN, NAVPOINT_PRESSURE_MAX,
0, 0);
input->open = navpoint_open;
input->close = navpoint_close;
input_set_drvdata(input, navpoint);
error = request_irq(ssp->irq, navpoint_irq, 0, pdev->name, navpoint);
if (error)
goto err_free_mem;
error = input_register_device(input);
if (error)
goto err_free_irq;
platform_set_drvdata(pdev, navpoint);
dev_dbg(&pdev->dev, "ssp%d, irq %d\n", pdata->port, ssp->irq);
return 0;
err_free_irq:
free_irq(ssp->irq, navpoint);
err_free_mem:
input_free_device(input);
kfree(navpoint);
pxa_ssp_free(ssp);
err_free_gpio:
if (gpio_is_valid(pdata->gpio))
gpio_free(pdata->gpio);
return error;
}
static int navpoint_remove(struct platform_device *pdev)
{
const struct navpoint_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct navpoint *navpoint = platform_get_drvdata(pdev);
struct ssp_device *ssp = navpoint->ssp;
free_irq(ssp->irq, navpoint);
input_unregister_device(navpoint->input);
kfree(navpoint);
pxa_ssp_free(ssp);
if (gpio_is_valid(pdata->gpio))
gpio_free(pdata->gpio);
return 0;
}
static int navpoint_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct navpoint *navpoint = platform_get_drvdata(pdev);
struct input_dev *input = navpoint->input;
mutex_lock(&input->mutex);
if (input->users)
navpoint_down(navpoint);
mutex_unlock(&input->mutex);
return 0;
}
static int navpoint_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct navpoint *navpoint = platform_get_drvdata(pdev);
struct input_dev *input = navpoint->input;
mutex_lock(&input->mutex);
if (input->users)
navpoint_up(navpoint);
mutex_unlock(&input->mutex);
return 0;
}
