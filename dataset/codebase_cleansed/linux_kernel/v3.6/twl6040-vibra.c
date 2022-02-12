static irqreturn_t twl6040_vib_irq_handler(int irq, void *data)
{
struct vibra_info *info = data;
struct twl6040 *twl6040 = info->twl6040;
u8 status;
status = twl6040_reg_read(twl6040, TWL6040_REG_STATUS);
if (status & TWL6040_VIBLOCDET) {
dev_warn(info->dev, "Left Vibrator overcurrent detected\n");
twl6040_clear_bits(twl6040, TWL6040_REG_VIBCTLL,
TWL6040_VIBENA);
}
if (status & TWL6040_VIBROCDET) {
dev_warn(info->dev, "Right Vibrator overcurrent detected\n");
twl6040_clear_bits(twl6040, TWL6040_REG_VIBCTLR,
TWL6040_VIBENA);
}
return IRQ_HANDLED;
}
static void twl6040_vibra_enable(struct vibra_info *info)
{
struct twl6040 *twl6040 = info->twl6040;
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(info->supplies), info->supplies);
if (ret) {
dev_err(info->dev, "failed to enable regulators %d\n", ret);
return;
}
twl6040_power(info->twl6040, 1);
if (twl6040_get_revid(twl6040) <= TWL6040_REV_ES1_1) {
twl6040_reg_write(twl6040, TWL6040_REG_VIBCTLL,
TWL6040_VIBENA | TWL6040_VIBCTRL);
twl6040_reg_write(twl6040, TWL6040_REG_VIBCTLR,
TWL6040_VIBENA | TWL6040_VIBCTRL);
usleep_range(3000, 3500);
}
twl6040_reg_write(twl6040, TWL6040_REG_VIBCTLL,
TWL6040_VIBENA);
twl6040_reg_write(twl6040, TWL6040_REG_VIBCTLR,
TWL6040_VIBENA);
info->enabled = true;
}
static void twl6040_vibra_disable(struct vibra_info *info)
{
struct twl6040 *twl6040 = info->twl6040;
twl6040_reg_write(twl6040, TWL6040_REG_VIBCTLL, 0x00);
twl6040_reg_write(twl6040, TWL6040_REG_VIBCTLR, 0x00);
twl6040_power(info->twl6040, 0);
regulator_bulk_disable(ARRAY_SIZE(info->supplies), info->supplies);
info->enabled = false;
}
static u8 twl6040_vibra_code(int vddvib, int vibdrv_res, int motor_res,
int speed, int direction)
{
int vpk, max_code;
u8 vibdat;
vpk = (vddvib * motor_res * TWL6040_VIBRA_MOD) /
(100 * (vibdrv_res + motor_res));
max_code = vpk / 50;
if (max_code > TWL6040_VIBDAT_MAX)
max_code = TWL6040_VIBDAT_MAX;
vibdat = (u8)((speed * max_code) / USHRT_MAX);
vibdat *= direction;
return vibdat;
}
static void twl6040_vibra_set_effect(struct vibra_info *info)
{
struct twl6040 *twl6040 = info->twl6040;
u8 vibdatl, vibdatr;
int volt;
volt = regulator_get_voltage(info->supplies[0].consumer) / 1000;
vibdatl = twl6040_vibra_code(volt, info->vibldrv_res,
info->viblmotor_res,
info->weak_speed, info->direction);
volt = regulator_get_voltage(info->supplies[1].consumer) / 1000;
vibdatr = twl6040_vibra_code(volt, info->vibrdrv_res,
info->vibrmotor_res,
info->strong_speed, info->direction);
twl6040_reg_write(twl6040, TWL6040_REG_VIBDATL, vibdatl);
twl6040_reg_write(twl6040, TWL6040_REG_VIBDATR, vibdatr);
}
static void vibra_play_work(struct work_struct *work)
{
struct vibra_info *info = container_of(work,
struct vibra_info, play_work);
mutex_lock(&info->mutex);
if (info->weak_speed || info->strong_speed) {
if (!info->enabled)
twl6040_vibra_enable(info);
twl6040_vibra_set_effect(info);
} else if (info->enabled)
twl6040_vibra_disable(info);
mutex_unlock(&info->mutex);
}
static int vibra_play(struct input_dev *input, void *data,
struct ff_effect *effect)
{
struct vibra_info *info = input_get_drvdata(input);
int ret;
ret = twl6040_get_vibralr_status(info->twl6040);
if (ret & TWL6040_VIBSEL) {
dev_info(&input->dev, "Vibra is configured for audio\n");
return -EBUSY;
}
info->weak_speed = effect->u.rumble.weak_magnitude;
info->strong_speed = effect->u.rumble.strong_magnitude;
info->direction = effect->direction < EFFECT_DIR_180_DEG ? 1 : -1;
ret = queue_work(info->workqueue, &info->play_work);
if (!ret) {
dev_info(&input->dev, "work is already on queue\n");
return ret;
}
return 0;
}
static void twl6040_vibra_close(struct input_dev *input)
{
struct vibra_info *info = input_get_drvdata(input);
cancel_work_sync(&info->play_work);
mutex_lock(&info->mutex);
if (info->enabled)
twl6040_vibra_disable(info);
mutex_unlock(&info->mutex);
}
static int twl6040_vibra_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct vibra_info *info = platform_get_drvdata(pdev);
mutex_lock(&info->mutex);
if (info->enabled)
twl6040_vibra_disable(info);
mutex_unlock(&info->mutex);
return 0;
}
static int __devinit twl6040_vibra_probe(struct platform_device *pdev)
{
struct twl6040_vibra_data *pdata = pdev->dev.platform_data;
struct device *twl6040_core_dev = pdev->dev.parent;
struct device_node *twl6040_core_node = NULL;
struct vibra_info *info;
int vddvibl_uV = 0;
int vddvibr_uV = 0;
int ret;
#ifdef CONFIG_OF
twl6040_core_node = of_find_node_by_name(twl6040_core_dev->of_node,
"vibra");
#endif
if (!pdata && !twl6040_core_node) {
dev_err(&pdev->dev, "platform_data not available\n");
return -EINVAL;
}
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
dev_err(&pdev->dev, "couldn't allocate memory\n");
return -ENOMEM;
}
info->dev = &pdev->dev;
info->twl6040 = dev_get_drvdata(pdev->dev.parent);
if (pdata) {
info->vibldrv_res = pdata->vibldrv_res;
info->vibrdrv_res = pdata->vibrdrv_res;
info->viblmotor_res = pdata->viblmotor_res;
info->vibrmotor_res = pdata->vibrmotor_res;
vddvibl_uV = pdata->vddvibl_uV;
vddvibr_uV = pdata->vddvibr_uV;
} else {
of_property_read_u32(twl6040_core_node, "ti,vibldrv-res",
&info->vibldrv_res);
of_property_read_u32(twl6040_core_node, "ti,vibrdrv-res",
&info->vibrdrv_res);
of_property_read_u32(twl6040_core_node, "ti,viblmotor-res",
&info->viblmotor_res);
of_property_read_u32(twl6040_core_node, "ti,vibrmotor-res",
&info->vibrmotor_res);
of_property_read_u32(twl6040_core_node, "ti,vddvibl-uV",
&vddvibl_uV);
of_property_read_u32(twl6040_core_node, "ti,vddvibr-uV",
&vddvibr_uV);
}
if ((!info->vibldrv_res && !info->viblmotor_res) ||
(!info->vibrdrv_res && !info->vibrmotor_res)) {
dev_err(info->dev, "invalid vibra driver/motor resistance\n");
ret = -EINVAL;
goto err_kzalloc;
}
info->irq = platform_get_irq(pdev, 0);
if (info->irq < 0) {
dev_err(info->dev, "invalid irq\n");
ret = -EINVAL;
goto err_kzalloc;
}
mutex_init(&info->mutex);
info->input_dev = input_allocate_device();
if (info->input_dev == NULL) {
dev_err(info->dev, "couldn't allocate input device\n");
ret = -ENOMEM;
goto err_kzalloc;
}
input_set_drvdata(info->input_dev, info);
info->input_dev->name = "twl6040:vibrator";
info->input_dev->id.version = 1;
info->input_dev->dev.parent = pdev->dev.parent;
info->input_dev->close = twl6040_vibra_close;
__set_bit(FF_RUMBLE, info->input_dev->ffbit);
ret = input_ff_create_memless(info->input_dev, NULL, vibra_play);
if (ret < 0) {
dev_err(info->dev, "couldn't register vibrator to FF\n");
goto err_ialloc;
}
ret = input_register_device(info->input_dev);
if (ret < 0) {
dev_err(info->dev, "couldn't register input device\n");
goto err_iff;
}
platform_set_drvdata(pdev, info);
ret = request_threaded_irq(info->irq, NULL, twl6040_vib_irq_handler, 0,
"twl6040_irq_vib", info);
if (ret) {
dev_err(info->dev, "VIB IRQ request failed: %d\n", ret);
goto err_irq;
}
info->supplies[0].supply = "vddvibl";
info->supplies[1].supply = "vddvibr";
ret = regulator_bulk_get(pdata ? info->dev : twl6040_core_dev,
ARRAY_SIZE(info->supplies), info->supplies);
if (ret) {
dev_err(info->dev, "couldn't get regulators %d\n", ret);
goto err_regulator;
}
if (vddvibl_uV) {
ret = regulator_set_voltage(info->supplies[0].consumer,
vddvibl_uV, vddvibl_uV);
if (ret) {
dev_err(info->dev, "failed to set VDDVIBL volt %d\n",
ret);
goto err_voltage;
}
}
if (vddvibr_uV) {
ret = regulator_set_voltage(info->supplies[1].consumer,
vddvibr_uV, vddvibr_uV);
if (ret) {
dev_err(info->dev, "failed to set VDDVIBR volt %d\n",
ret);
goto err_voltage;
}
}
info->workqueue = alloc_workqueue("twl6040-vibra", 0, 0);
if (info->workqueue == NULL) {
dev_err(info->dev, "couldn't create workqueue\n");
ret = -ENOMEM;
goto err_voltage;
}
INIT_WORK(&info->play_work, vibra_play_work);
return 0;
err_voltage:
regulator_bulk_free(ARRAY_SIZE(info->supplies), info->supplies);
err_regulator:
free_irq(info->irq, info);
err_irq:
input_unregister_device(info->input_dev);
info->input_dev = NULL;
err_iff:
if (info->input_dev)
input_ff_destroy(info->input_dev);
err_ialloc:
input_free_device(info->input_dev);
err_kzalloc:
kfree(info);
return ret;
}
static int __devexit twl6040_vibra_remove(struct platform_device *pdev)
{
struct vibra_info *info = platform_get_drvdata(pdev);
input_unregister_device(info->input_dev);
free_irq(info->irq, info);
regulator_bulk_free(ARRAY_SIZE(info->supplies), info->supplies);
destroy_workqueue(info->workqueue);
kfree(info);
return 0;
}
