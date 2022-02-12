static int pm8xxx_vib_set(struct pm8xxx_vib *vib, bool on)
{
int rc;
unsigned int val = vib->reg_vib_drv;
if (on)
val |= ((vib->level << VIB_DRV_SEL_SHIFT) & VIB_DRV_SEL_MASK);
else
val &= ~VIB_DRV_SEL_MASK;
rc = regmap_write(vib->regmap, VIB_DRV, val);
if (rc < 0)
return rc;
vib->reg_vib_drv = val;
return 0;
}
static void pm8xxx_work_handler(struct work_struct *work)
{
struct pm8xxx_vib *vib = container_of(work, struct pm8xxx_vib, work);
int rc;
unsigned int val;
rc = regmap_read(vib->regmap, VIB_DRV, &val);
if (rc < 0)
return;
if (vib->speed) {
vib->active = true;
vib->level = ((VIB_MAX_LEVELS * vib->speed) / MAX_FF_SPEED) +
VIB_MIN_LEVEL_mV;
vib->level /= 100;
} else {
vib->active = false;
vib->level = VIB_MIN_LEVEL_mV / 100;
}
pm8xxx_vib_set(vib, vib->active);
}
static void pm8xxx_vib_close(struct input_dev *dev)
{
struct pm8xxx_vib *vib = input_get_drvdata(dev);
cancel_work_sync(&vib->work);
if (vib->active)
pm8xxx_vib_set(vib, false);
}
static int pm8xxx_vib_play_effect(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
struct pm8xxx_vib *vib = input_get_drvdata(dev);
vib->speed = effect->u.rumble.strong_magnitude >> 8;
if (!vib->speed)
vib->speed = effect->u.rumble.weak_magnitude >> 9;
schedule_work(&vib->work);
return 0;
}
static int pm8xxx_vib_probe(struct platform_device *pdev)
{
struct pm8xxx_vib *vib;
struct input_dev *input_dev;
int error;
unsigned int val;
vib = devm_kzalloc(&pdev->dev, sizeof(*vib), GFP_KERNEL);
if (!vib)
return -ENOMEM;
vib->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!vib->regmap)
return -ENODEV;
input_dev = devm_input_allocate_device(&pdev->dev);
if (!input_dev)
return -ENOMEM;
INIT_WORK(&vib->work, pm8xxx_work_handler);
vib->vib_input_dev = input_dev;
error = regmap_read(vib->regmap, VIB_DRV, &val);
if (error < 0)
return error;
val &= ~VIB_DRV_EN_MANUAL_MASK;
error = regmap_write(vib->regmap, VIB_DRV, val);
if (error < 0)
return error;
vib->reg_vib_drv = val;
input_dev->name = "pm8xxx_vib_ffmemless";
input_dev->id.version = 1;
input_dev->close = pm8xxx_vib_close;
input_set_drvdata(input_dev, vib);
input_set_capability(vib->vib_input_dev, EV_FF, FF_RUMBLE);
error = input_ff_create_memless(input_dev, NULL,
pm8xxx_vib_play_effect);
if (error) {
dev_err(&pdev->dev,
"couldn't register vibrator as FF device\n");
return error;
}
error = input_register_device(input_dev);
if (error) {
dev_err(&pdev->dev, "couldn't register input device\n");
return error;
}
platform_set_drvdata(pdev, vib);
return 0;
}
static int pm8xxx_vib_suspend(struct device *dev)
{
struct pm8xxx_vib *vib = dev_get_drvdata(dev);
pm8xxx_vib_set(vib, false);
return 0;
}
