static void shark_write_val(struct snd_tea575x *tea, u32 val)
{
struct shark_device *shark = tea->private_data;
int i, res, actual_len;
if (shark->last_val == val)
return;
memset(shark->transfer_buffer, 0, TB_LEN);
shark->transfer_buffer[0] = 0xc0;
for (i = 0; i < 4; i++)
shark->transfer_buffer[i] |= (val >> (24 - i * 8)) & 0xff;
res = usb_interrupt_msg(shark->usbdev,
usb_sndintpipe(shark->usbdev, SHARK_OUT_EP),
shark->transfer_buffer, TB_LEN,
&actual_len, 1000);
if (res >= 0)
shark->last_val = val;
else
v4l2_err(&shark->v4l2_dev, "set-freq error: %d\n", res);
}
static u32 shark_read_val(struct snd_tea575x *tea)
{
struct shark_device *shark = tea->private_data;
int i, res, actual_len;
u32 val = 0;
memset(shark->transfer_buffer, 0, TB_LEN);
shark->transfer_buffer[0] = 0x80;
res = usb_interrupt_msg(shark->usbdev,
usb_sndintpipe(shark->usbdev, SHARK_OUT_EP),
shark->transfer_buffer, TB_LEN,
&actual_len, 1000);
if (res < 0) {
v4l2_err(&shark->v4l2_dev, "request-status error: %d\n", res);
return shark->last_val;
}
res = usb_interrupt_msg(shark->usbdev,
usb_rcvintpipe(shark->usbdev, SHARK_IN_EP),
shark->transfer_buffer, TB_LEN,
&actual_len, 1000);
if (res < 0) {
v4l2_err(&shark->v4l2_dev, "get-status error: %d\n", res);
return shark->last_val;
}
for (i = 0; i < 4; i++)
val |= shark->transfer_buffer[i] << (24 - i * 8);
shark->last_val = val;
if (((val & TEA575X_BIT_BAND_MASK) == TEA575X_BIT_BAND_FM) &&
!(val & TEA575X_BIT_MONO))
shark->tea.stereo = true;
else
shark->tea.stereo = false;
return val;
}
static void shark_led_work(struct work_struct *work)
{
struct shark_device *shark =
container_of(work, struct shark_device, led_work);
int i, res, brightness, actual_len;
for (i = 0; i < 3; i++) {
if (!test_and_clear_bit(i, &shark->brightness_new))
continue;
brightness = atomic_read(&shark->brightness[i]);
memset(shark->transfer_buffer, 0, TB_LEN);
if (i != RED_LED) {
shark->transfer_buffer[0] = 0xA0 + i;
shark->transfer_buffer[1] = brightness;
} else
shark->transfer_buffer[0] = brightness ? 0xA9 : 0xA8;
res = usb_interrupt_msg(shark->usbdev,
usb_sndintpipe(shark->usbdev, 0x05),
shark->transfer_buffer, TB_LEN,
&actual_len, 1000);
if (res < 0)
v4l2_err(&shark->v4l2_dev, "set LED %s error: %d\n",
shark->led_names[i], res);
}
}
static void shark_led_set_blue(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct shark_device *shark =
container_of(led_cdev, struct shark_device, leds[BLUE_LED]);
atomic_set(&shark->brightness[BLUE_LED], value);
set_bit(BLUE_LED, &shark->brightness_new);
clear_bit(BLUE_IS_PULSE, &shark->brightness_new);
schedule_work(&shark->led_work);
}
static void shark_led_set_blue_pulse(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct shark_device *shark = container_of(led_cdev,
struct shark_device, leds[BLUE_PULSE_LED]);
atomic_set(&shark->brightness[BLUE_PULSE_LED], 256 - value);
set_bit(BLUE_PULSE_LED, &shark->brightness_new);
set_bit(BLUE_IS_PULSE, &shark->brightness_new);
schedule_work(&shark->led_work);
}
static void shark_led_set_red(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct shark_device *shark =
container_of(led_cdev, struct shark_device, leds[RED_LED]);
atomic_set(&shark->brightness[RED_LED], value);
set_bit(RED_LED, &shark->brightness_new);
schedule_work(&shark->led_work);
}
static int shark_register_leds(struct shark_device *shark, struct device *dev)
{
int i, retval;
atomic_set(&shark->brightness[BLUE_LED], 127);
INIT_WORK(&shark->led_work, shark_led_work);
for (i = 0; i < NO_LEDS; i++) {
shark->leds[i] = shark_led_templates[i];
snprintf(shark->led_names[i], sizeof(shark->led_names[0]),
shark->leds[i].name, shark->v4l2_dev.name);
shark->leds[i].name = shark->led_names[i];
retval = led_classdev_register(dev, &shark->leds[i]);
if (retval) {
v4l2_err(&shark->v4l2_dev,
"couldn't register led: %s\n",
shark->led_names[i]);
return retval;
}
}
return 0;
}
static void shark_unregister_leds(struct shark_device *shark)
{
int i;
for (i = 0; i < NO_LEDS; i++)
led_classdev_unregister(&shark->leds[i]);
cancel_work_sync(&shark->led_work);
}
static void shark_resume_leds(struct shark_device *shark)
{
if (test_bit(BLUE_IS_PULSE, &shark->brightness_new))
set_bit(BLUE_PULSE_LED, &shark->brightness_new);
else
set_bit(BLUE_LED, &shark->brightness_new);
set_bit(RED_LED, &shark->brightness_new);
schedule_work(&shark->led_work);
}
static int shark_register_leds(struct shark_device *shark, struct device *dev)
{
v4l2_warn(&shark->v4l2_dev,
"CONFIG_LEDS_CLASS not enabled, LED support disabled\n");
return 0;
}
static inline void shark_unregister_leds(struct shark_device *shark) { }
static inline void shark_resume_leds(struct shark_device *shark) { }
static void usb_shark_disconnect(struct usb_interface *intf)
{
struct v4l2_device *v4l2_dev = usb_get_intfdata(intf);
struct shark_device *shark = v4l2_dev_to_shark(v4l2_dev);
mutex_lock(&shark->tea.mutex);
v4l2_device_disconnect(&shark->v4l2_dev);
snd_tea575x_exit(&shark->tea);
mutex_unlock(&shark->tea.mutex);
shark_unregister_leds(shark);
v4l2_device_put(&shark->v4l2_dev);
}
static void usb_shark_release(struct v4l2_device *v4l2_dev)
{
struct shark_device *shark = v4l2_dev_to_shark(v4l2_dev);
v4l2_device_unregister(&shark->v4l2_dev);
kfree(shark->transfer_buffer);
kfree(shark);
}
static int usb_shark_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct shark_device *shark;
int retval = -ENOMEM;
shark = kzalloc(sizeof(struct shark_device), GFP_KERNEL);
if (!shark)
return retval;
shark->transfer_buffer = kmalloc(TB_LEN, GFP_KERNEL);
if (!shark->transfer_buffer)
goto err_alloc_buffer;
v4l2_device_set_name(&shark->v4l2_dev, DRV_NAME, &shark_instance);
retval = shark_register_leds(shark, &intf->dev);
if (retval)
goto err_reg_leds;
shark->v4l2_dev.release = usb_shark_release;
retval = v4l2_device_register(&intf->dev, &shark->v4l2_dev);
if (retval) {
v4l2_err(&shark->v4l2_dev, "couldn't register v4l2_device\n");
goto err_reg_dev;
}
shark->usbdev = interface_to_usbdev(intf);
shark->tea.v4l2_dev = &shark->v4l2_dev;
shark->tea.private_data = shark;
shark->tea.radio_nr = -1;
shark->tea.ops = &shark_tea_ops;
shark->tea.cannot_mute = true;
shark->tea.has_am = true;
strlcpy(shark->tea.card, "Griffin radioSHARK",
sizeof(shark->tea.card));
usb_make_path(shark->usbdev, shark->tea.bus_info,
sizeof(shark->tea.bus_info));
retval = snd_tea575x_init(&shark->tea, THIS_MODULE);
if (retval) {
v4l2_err(&shark->v4l2_dev, "couldn't init tea5757\n");
goto err_init_tea;
}
return 0;
err_init_tea:
v4l2_device_unregister(&shark->v4l2_dev);
err_reg_dev:
shark_unregister_leds(shark);
err_reg_leds:
kfree(shark->transfer_buffer);
err_alloc_buffer:
kfree(shark);
return retval;
}
static int usb_shark_suspend(struct usb_interface *intf, pm_message_t message)
{
return 0;
}
static int usb_shark_resume(struct usb_interface *intf)
{
struct v4l2_device *v4l2_dev = usb_get_intfdata(intf);
struct shark_device *shark = v4l2_dev_to_shark(v4l2_dev);
mutex_lock(&shark->tea.mutex);
snd_tea575x_set_freq(&shark->tea);
mutex_unlock(&shark->tea.mutex);
shark_resume_leds(shark);
return 0;
}
