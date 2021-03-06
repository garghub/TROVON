static int iforce_playback(struct input_dev *dev, int effect_id, int value)
{
struct iforce *iforce = input_get_drvdata(dev);
struct iforce_core_effect *core_effect = &iforce->core_effects[effect_id];
if (value > 0)
set_bit(FF_CORE_SHOULD_PLAY, core_effect->flags);
else
clear_bit(FF_CORE_SHOULD_PLAY, core_effect->flags);
iforce_control_playback(iforce, effect_id, value);
return 0;
}
static void iforce_set_gain(struct input_dev *dev, u16 gain)
{
struct iforce *iforce = input_get_drvdata(dev);
unsigned char data[3];
data[0] = gain >> 9;
iforce_send_packet(iforce, FF_CMD_GAIN, data);
}
static void iforce_set_autocenter(struct input_dev *dev, u16 magnitude)
{
struct iforce *iforce = input_get_drvdata(dev);
unsigned char data[3];
data[0] = 0x03;
data[1] = magnitude >> 9;
iforce_send_packet(iforce, FF_CMD_AUTOCENTER, data);
data[0] = 0x04;
data[1] = 0x01;
iforce_send_packet(iforce, FF_CMD_AUTOCENTER, data);
}
static int iforce_upload_effect(struct input_dev *dev, struct ff_effect *effect, struct ff_effect *old)
{
struct iforce *iforce = input_get_drvdata(dev);
struct iforce_core_effect *core_effect = &iforce->core_effects[effect->id];
int ret;
if (__test_and_set_bit(FF_CORE_IS_USED, core_effect->flags)) {
if (test_bit(FF_CORE_UPDATE, core_effect->flags))
return -EAGAIN;
}
switch (effect->type) {
case FF_PERIODIC:
ret = iforce_upload_periodic(iforce, effect, old);
break;
case FF_CONSTANT:
ret = iforce_upload_constant(iforce, effect, old);
break;
case FF_SPRING:
case FF_DAMPER:
ret = iforce_upload_condition(iforce, effect, old);
break;
default:
return -EINVAL;
}
if (ret == 0) {
set_bit(FF_CORE_UPDATE, core_effect->flags);
}
return ret;
}
static int iforce_erase_effect(struct input_dev *dev, int effect_id)
{
struct iforce *iforce = input_get_drvdata(dev);
struct iforce_core_effect *core_effect = &iforce->core_effects[effect_id];
int err = 0;
if (test_bit(FF_MOD1_IS_USED, core_effect->flags))
err = release_resource(&core_effect->mod1_chunk);
if (!err && test_bit(FF_MOD2_IS_USED, core_effect->flags))
err = release_resource(&core_effect->mod2_chunk);
core_effect->flags[0] = 0;
return err;
}
static int iforce_open(struct input_dev *dev)
{
struct iforce *iforce = input_get_drvdata(dev);
switch (iforce->bus) {
#ifdef CONFIG_JOYSTICK_IFORCE_USB
case IFORCE_USB:
iforce->irq->dev = iforce->usbdev;
if (usb_submit_urb(iforce->irq, GFP_KERNEL))
return -EIO;
break;
#endif
}
if (test_bit(EV_FF, dev->evbit)) {
iforce_send_packet(iforce, FF_CMD_ENABLE, "\004");
}
return 0;
}
static void iforce_close(struct input_dev *dev)
{
struct iforce *iforce = input_get_drvdata(dev);
int i;
if (test_bit(EV_FF, dev->evbit)) {
for (i = 0; i < dev->ff->max_effects; i++) {
if (test_bit(FF_CORE_IS_USED, iforce->core_effects[i].flags)) {
dev_warn(&dev->dev,
"%s: Device still owns effects\n",
__func__);
break;
}
}
iforce_send_packet(iforce, FF_CMD_ENABLE, "\001");
wait_event_interruptible(iforce->wait,
!test_bit(IFORCE_XMIT_RUNNING, iforce->xmit_flags));
}
switch (iforce->bus) {
#ifdef CONFIG_JOYSTICK_IFORCE_USB
case IFORCE_USB:
usb_kill_urb(iforce->irq);
usb_kill_urb(iforce->out);
usb_kill_urb(iforce->ctrl);
break;
#endif
#ifdef CONFIG_JOYSTICK_IFORCE_232
case IFORCE_232:
break;
#endif
}
}
int iforce_init_device(struct iforce *iforce)
{
struct input_dev *input_dev;
struct ff_device *ff;
unsigned char c[] = "CEOV";
int i, error;
int ff_effects = 0;
input_dev = input_allocate_device();
if (!input_dev)
return -ENOMEM;
init_waitqueue_head(&iforce->wait);
spin_lock_init(&iforce->xmit_lock);
mutex_init(&iforce->mem_mutex);
iforce->xmit.buf = iforce->xmit_data;
iforce->dev = input_dev;
switch (iforce->bus) {
#ifdef CONFIG_JOYSTICK_IFORCE_USB
case IFORCE_USB:
input_dev->id.bustype = BUS_USB;
input_dev->dev.parent = &iforce->usbdev->dev;
break;
#endif
#ifdef CONFIG_JOYSTICK_IFORCE_232
case IFORCE_232:
input_dev->id.bustype = BUS_RS232;
input_dev->dev.parent = &iforce->serio->dev;
break;
#endif
}
input_set_drvdata(input_dev, iforce);
input_dev->name = "Unknown I-Force device";
input_dev->open = iforce_open;
input_dev->close = iforce_close;
iforce->device_memory.name = "I-Force device effect memory";
iforce->device_memory.start = 0;
iforce->device_memory.end = 200;
iforce->device_memory.flags = IORESOURCE_MEM;
iforce->device_memory.parent = NULL;
iforce->device_memory.child = NULL;
iforce->device_memory.sibling = NULL;
for (i = 0; i < 20; i++)
if (!iforce_get_id_packet(iforce, "O"))
break;
if (i == 20) {
err("Timeout waiting for response from device.");
error = -ENODEV;
goto fail;
}
if (!iforce_get_id_packet(iforce, "M"))
input_dev->id.vendor = (iforce->edata[2] << 8) | iforce->edata[1];
else
dev_warn(&iforce->dev->dev, "Device does not respond to id packet M\n");
if (!iforce_get_id_packet(iforce, "P"))
input_dev->id.product = (iforce->edata[2] << 8) | iforce->edata[1];
else
dev_warn(&iforce->dev->dev, "Device does not respond to id packet P\n");
if (!iforce_get_id_packet(iforce, "B"))
iforce->device_memory.end = (iforce->edata[2] << 8) | iforce->edata[1];
else
dev_warn(&iforce->dev->dev, "Device does not respond to id packet B\n");
if (!iforce_get_id_packet(iforce, "N"))
ff_effects = iforce->edata[1];
else
dev_warn(&iforce->dev->dev, "Device does not respond to id packet N\n");
if (ff_effects > IFORCE_EFFECTS_MAX) {
dev_warn(&iforce->dev->dev, "Limiting number of effects to %d (device reports %d)\n",
IFORCE_EFFECTS_MAX, ff_effects);
ff_effects = IFORCE_EFFECTS_MAX;
}
for (i = 0; c[i]; i++)
if (!iforce_get_id_packet(iforce, c + i))
iforce_dump_packet("info", iforce->ecmd, iforce->edata);
iforce_set_autocenter(input_dev, 0);
for (i = 0; iforce_device[i].idvendor; i++)
if (iforce_device[i].idvendor == input_dev->id.vendor &&
iforce_device[i].idproduct == input_dev->id.product)
break;
iforce->type = iforce_device + i;
input_dev->name = iforce->type->name;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS) |
BIT_MASK(EV_FF_STATUS);
for (i = 0; iforce->type->btn[i] >= 0; i++)
set_bit(iforce->type->btn[i], input_dev->keybit);
set_bit(BTN_DEAD, input_dev->keybit);
for (i = 0; iforce->type->abs[i] >= 0; i++) {
signed short t = iforce->type->abs[i];
switch (t) {
case ABS_X:
case ABS_Y:
case ABS_WHEEL:
input_set_abs_params(input_dev, t, -1920, 1920, 16, 128);
set_bit(t, input_dev->ffbit);
break;
case ABS_THROTTLE:
case ABS_GAS:
case ABS_BRAKE:
input_set_abs_params(input_dev, t, 0, 255, 0, 0);
break;
case ABS_RUDDER:
input_set_abs_params(input_dev, t, -128, 127, 0, 0);
break;
case ABS_HAT0X:
case ABS_HAT0Y:
case ABS_HAT1X:
case ABS_HAT1Y:
input_set_abs_params(input_dev, t, -1, 1, 0, 0);
break;
}
}
if (ff_effects) {
for (i = 0; iforce->type->ff[i] >= 0; i++)
set_bit(iforce->type->ff[i], input_dev->ffbit);
error = input_ff_create(input_dev, ff_effects);
if (error)
goto fail;
ff = input_dev->ff;
ff->upload = iforce_upload_effect;
ff->erase = iforce_erase_effect;
ff->set_gain = iforce_set_gain;
ff->set_autocenter = iforce_set_autocenter;
ff->playback = iforce_playback;
}
error = input_register_device(iforce->dev);
if (error)
goto fail;
return 0;
fail: input_free_device(input_dev);
return error;
}
static int __init iforce_init(void)
{
int err = 0;
#ifdef CONFIG_JOYSTICK_IFORCE_USB
err = usb_register(&iforce_usb_driver);
if (err)
return err;
#endif
#ifdef CONFIG_JOYSTICK_IFORCE_232
err = serio_register_driver(&iforce_serio_drv);
#ifdef CONFIG_JOYSTICK_IFORCE_USB
if (err)
usb_deregister(&iforce_usb_driver);
#endif
#endif
return err;
}
static void __exit iforce_exit(void)
{
#ifdef CONFIG_JOYSTICK_IFORCE_USB
usb_deregister(&iforce_usb_driver);
#endif
#ifdef CONFIG_JOYSTICK_IFORCE_232
serio_unregister_driver(&iforce_serio_drv);
#endif
}
