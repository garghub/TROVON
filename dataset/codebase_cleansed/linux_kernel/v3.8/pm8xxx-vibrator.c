static int pm8xxx_vib_read_u8(struct pm8xxx_vib *vib,
u8 *data, u16 reg)
{
int rc;
rc = pm8xxx_readb(vib->dev->parent, reg, data);
if (rc < 0)
dev_warn(vib->dev, "Error reading pm8xxx reg 0x%x(0x%x)\n",
reg, rc);
return rc;
}
static int pm8xxx_vib_write_u8(struct pm8xxx_vib *vib,
u8 data, u16 reg)
{
int rc;
rc = pm8xxx_writeb(vib->dev->parent, reg, data);
if (rc < 0)
dev_warn(vib->dev, "Error writing pm8xxx reg 0x%x(0x%x)\n",
reg, rc);
return rc;
}
static int pm8xxx_vib_set(struct pm8xxx_vib *vib, bool on)
{
int rc;
u8 val = vib->reg_vib_drv;
if (on)
val |= ((vib->level << VIB_DRV_SEL_SHIFT) & VIB_DRV_SEL_MASK);
else
val &= ~VIB_DRV_SEL_MASK;
rc = pm8xxx_vib_write_u8(vib, val, VIB_DRV);
if (rc < 0)
return rc;
vib->reg_vib_drv = val;
return 0;
}
static void pm8xxx_work_handler(struct work_struct *work)
{
struct pm8xxx_vib *vib = container_of(work, struct pm8xxx_vib, work);
int rc;
u8 val;
rc = pm8xxx_vib_read_u8(vib, &val, VIB_DRV);
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
u8 val;
vib = kzalloc(sizeof(*vib), GFP_KERNEL);
input_dev = input_allocate_device();
if (!vib || !input_dev) {
dev_err(&pdev->dev, "couldn't allocate memory\n");
error = -ENOMEM;
goto err_free_mem;
}
INIT_WORK(&vib->work, pm8xxx_work_handler);
vib->dev = &pdev->dev;
vib->vib_input_dev = input_dev;
error = pm8xxx_vib_read_u8(vib, &val, VIB_DRV);
if (error < 0)
goto err_free_mem;
val &= ~VIB_DRV_EN_MANUAL_MASK;
error = pm8xxx_vib_write_u8(vib, val, VIB_DRV);
if (error < 0)
goto err_free_mem;
vib->reg_vib_drv = val;
input_dev->name = "pm8xxx_vib_ffmemless";
input_dev->id.version = 1;
input_dev->dev.parent = &pdev->dev;
input_dev->close = pm8xxx_vib_close;
input_set_drvdata(input_dev, vib);
input_set_capability(vib->vib_input_dev, EV_FF, FF_RUMBLE);
error = input_ff_create_memless(input_dev, NULL,
pm8xxx_vib_play_effect);
if (error) {
dev_err(&pdev->dev,
"couldn't register vibrator as FF device\n");
goto err_free_mem;
}
error = input_register_device(input_dev);
if (error) {
dev_err(&pdev->dev, "couldn't register input device\n");
goto err_destroy_memless;
}
platform_set_drvdata(pdev, vib);
return 0;
err_destroy_memless:
input_ff_destroy(input_dev);
err_free_mem:
input_free_device(input_dev);
kfree(vib);
return error;
}
static int pm8xxx_vib_remove(struct platform_device *pdev)
{
struct pm8xxx_vib *vib = platform_get_drvdata(pdev);
input_unregister_device(vib->vib_input_dev);
kfree(vib);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int pm8xxx_vib_suspend(struct device *dev)
{
struct pm8xxx_vib *vib = dev_get_drvdata(dev);
pm8xxx_vib_set(vib, false);
return 0;
}
