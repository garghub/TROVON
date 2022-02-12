static void vibra_disable_leds(void)
{
u8 reg;
twl_i2c_read_u8(TWL4030_MODULE_LED, &reg, LEDEN);
reg &= ~0x03;
twl_i2c_write_u8(TWL4030_MODULE_LED, LEDEN, reg);
}
static void vibra_enable(struct vibra_info *info)
{
u8 reg;
twl4030_audio_enable_resource(TWL4030_AUDIO_RES_POWER);
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE,
&reg, TWL4030_REG_VIBRA_CTL);
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
(reg | TWL4030_VIBRA_EN), TWL4030_REG_VIBRA_CTL);
twl4030_audio_enable_resource(TWL4030_AUDIO_RES_APLL);
info->enabled = true;
}
static void vibra_disable(struct vibra_info *info)
{
u8 reg;
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE,
&reg, TWL4030_REG_VIBRA_CTL);
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
(reg & ~TWL4030_VIBRA_EN), TWL4030_REG_VIBRA_CTL);
twl4030_audio_disable_resource(TWL4030_AUDIO_RES_APLL);
twl4030_audio_disable_resource(TWL4030_AUDIO_RES_POWER);
info->enabled = false;
}
static void vibra_play_work(struct work_struct *work)
{
struct vibra_info *info = container_of(work,
struct vibra_info, play_work);
int dir;
int pwm;
u8 reg;
dir = info->direction;
pwm = info->speed;
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE,
&reg, TWL4030_REG_VIBRA_CTL);
if (pwm && (!info->coexist || !(reg & TWL4030_VIBRA_SEL))) {
if (!info->enabled)
vibra_enable(info);
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE,
&reg, TWL4030_REG_VIBRA_CTL);
reg = (dir) ? (reg | TWL4030_VIBRA_DIR) :
(reg & ~TWL4030_VIBRA_DIR);
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
reg, TWL4030_REG_VIBRA_CTL);
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
256 - pwm, TWL4030_REG_VIBRA_SET);
} else {
if (info->enabled)
vibra_disable(info);
}
}
static int vibra_play(struct input_dev *input, void *data,
struct ff_effect *effect)
{
struct vibra_info *info = input_get_drvdata(input);
info->speed = effect->u.rumble.strong_magnitude >> 8;
if (!info->speed)
info->speed = effect->u.rumble.weak_magnitude >> 9;
info->direction = effect->direction < EFFECT_DIR_180_DEG ? 0 : 1;
queue_work(info->workqueue, &info->play_work);
return 0;
}
static int twl4030_vibra_open(struct input_dev *input)
{
struct vibra_info *info = input_get_drvdata(input);
info->workqueue = create_singlethread_workqueue("vibra");
if (info->workqueue == NULL) {
dev_err(&input->dev, "couldn't create workqueue\n");
return -ENOMEM;
}
return 0;
}
static void twl4030_vibra_close(struct input_dev *input)
{
struct vibra_info *info = input_get_drvdata(input);
cancel_work_sync(&info->play_work);
INIT_WORK(&info->play_work, vibra_play_work);
destroy_workqueue(info->workqueue);
info->workqueue = NULL;
if (info->enabled)
vibra_disable(info);
}
static int twl4030_vibra_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct vibra_info *info = platform_get_drvdata(pdev);
if (info->enabled)
vibra_disable(info);
return 0;
}
static int twl4030_vibra_resume(struct device *dev)
{
vibra_disable_leds();
return 0;
}
static bool twl4030_vibra_check_coexist(struct twl4030_vibra_data *pdata,
struct device_node *node)
{
if (pdata && pdata->coexist)
return true;
if (of_find_node_by_name(node, "codec"))
return true;
return false;
}
static int twl4030_vibra_probe(struct platform_device *pdev)
{
struct twl4030_vibra_data *pdata = pdev->dev.platform_data;
struct device_node *twl4030_core_node = pdev->dev.parent->of_node;
struct vibra_info *info;
int ret;
if (!pdata && !twl4030_core_node) {
dev_dbg(&pdev->dev, "platform_data not available\n");
return -EINVAL;
}
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = &pdev->dev;
info->coexist = twl4030_vibra_check_coexist(pdata, twl4030_core_node);
INIT_WORK(&info->play_work, vibra_play_work);
info->input_dev = input_allocate_device();
if (info->input_dev == NULL) {
dev_err(&pdev->dev, "couldn't allocate input device\n");
ret = -ENOMEM;
goto err_kzalloc;
}
input_set_drvdata(info->input_dev, info);
info->input_dev->name = "twl4030:vibrator";
info->input_dev->id.version = 1;
info->input_dev->dev.parent = pdev->dev.parent;
info->input_dev->open = twl4030_vibra_open;
info->input_dev->close = twl4030_vibra_close;
__set_bit(FF_RUMBLE, info->input_dev->ffbit);
ret = input_ff_create_memless(info->input_dev, NULL, vibra_play);
if (ret < 0) {
dev_dbg(&pdev->dev, "couldn't register vibrator to FF\n");
goto err_ialloc;
}
ret = input_register_device(info->input_dev);
if (ret < 0) {
dev_dbg(&pdev->dev, "couldn't register input device\n");
goto err_iff;
}
vibra_disable_leds();
platform_set_drvdata(pdev, info);
return 0;
err_iff:
input_ff_destroy(info->input_dev);
err_ialloc:
input_free_device(info->input_dev);
err_kzalloc:
kfree(info);
return ret;
}
static int twl4030_vibra_remove(struct platform_device *pdev)
{
struct vibra_info *info = platform_get_drvdata(pdev);
input_unregister_device(info->input_dev);
kfree(info);
platform_set_drvdata(pdev, NULL);
return 0;
}
