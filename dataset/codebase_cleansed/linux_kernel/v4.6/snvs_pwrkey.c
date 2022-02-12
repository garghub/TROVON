static void imx_imx_snvs_check_for_events(unsigned long data)
{
struct pwrkey_drv_data *pdata = (struct pwrkey_drv_data *) data;
struct input_dev *input = pdata->input;
u32 state;
regmap_read(pdata->snvs, SNVS_HPSR_REG, &state);
state = state & SNVS_HPSR_BTN ? 1 : 0;
if (state ^ pdata->keystate) {
pdata->keystate = state;
input_event(input, EV_KEY, pdata->keycode, state);
input_sync(input);
pm_relax(pdata->input->dev.parent);
}
if (state) {
mod_timer(&pdata->check_timer,
jiffies + msecs_to_jiffies(REPEAT_INTERVAL));
}
}
static irqreturn_t imx_snvs_pwrkey_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct pwrkey_drv_data *pdata = platform_get_drvdata(pdev);
u32 lp_status;
pm_wakeup_event(pdata->input->dev.parent, 0);
regmap_read(pdata->snvs, SNVS_LPSR_REG, &lp_status);
if (lp_status & SNVS_LPSR_SPO)
mod_timer(&pdata->check_timer, jiffies + msecs_to_jiffies(DEBOUNCE_TIME));
regmap_write(pdata->snvs, SNVS_LPSR_REG, SNVS_LPSR_SPO);
return IRQ_HANDLED;
}
static void imx_snvs_pwrkey_act(void *pdata)
{
struct pwrkey_drv_data *pd = pdata;
del_timer_sync(&pd->check_timer);
}
static int imx_snvs_pwrkey_probe(struct platform_device *pdev)
{
struct pwrkey_drv_data *pdata = NULL;
struct input_dev *input = NULL;
struct device_node *np;
int error;
np = pdev->dev.of_node;
if (!np)
return -ENODEV;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->snvs = syscon_regmap_lookup_by_phandle(np, "regmap");
if (IS_ERR(pdata->snvs)) {
dev_err(&pdev->dev, "Can't get snvs syscon\n");
return PTR_ERR(pdata->snvs);
}
if (of_property_read_u32(np, "linux,keycode", &pdata->keycode)) {
pdata->keycode = KEY_POWER;
dev_warn(&pdev->dev, "KEY_POWER without setting in dts\n");
}
pdata->wakeup = of_property_read_bool(np, "wakeup-source");
pdata->irq = platform_get_irq(pdev, 0);
if (pdata->irq < 0) {
dev_err(&pdev->dev, "no irq defined in platform data\n");
return -EINVAL;
}
regmap_update_bits(pdata->snvs, SNVS_LPCR_REG, SNVS_LPCR_DEP_EN, SNVS_LPCR_DEP_EN);
regmap_write(pdata->snvs, SNVS_LPSR_REG, SNVS_LPSR_SPO);
setup_timer(&pdata->check_timer,
imx_imx_snvs_check_for_events, (unsigned long) pdata);
input = devm_input_allocate_device(&pdev->dev);
if (!input) {
dev_err(&pdev->dev, "failed to allocate the input device\n");
return -ENOMEM;
}
input->name = pdev->name;
input->phys = "snvs-pwrkey/input0";
input->id.bustype = BUS_HOST;
input_set_capability(input, EV_KEY, pdata->keycode);
error = devm_add_action(&pdev->dev, imx_snvs_pwrkey_act, pdata);
if (error) {
dev_err(&pdev->dev, "failed to register remove action\n");
return error;
}
error = devm_request_irq(&pdev->dev, pdata->irq,
imx_snvs_pwrkey_interrupt,
0, pdev->name, pdev);
if (error) {
dev_err(&pdev->dev, "interrupt not available.\n");
return error;
}
error = input_register_device(input);
if (error < 0) {
dev_err(&pdev->dev, "failed to register input device\n");
input_free_device(input);
return error;
}
pdata->input = input;
platform_set_drvdata(pdev, pdata);
device_init_wakeup(&pdev->dev, pdata->wakeup);
return 0;
}
static int __maybe_unused imx_snvs_pwrkey_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pwrkey_drv_data *pdata = platform_get_drvdata(pdev);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(pdata->irq);
return 0;
}
static int __maybe_unused imx_snvs_pwrkey_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pwrkey_drv_data *pdata = platform_get_drvdata(pdev);
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(pdata->irq);
return 0;
}
