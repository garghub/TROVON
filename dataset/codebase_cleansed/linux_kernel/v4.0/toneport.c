static int toneport_send_cmd(struct usb_device *usbdev, int cmd1, int cmd2)
{
int ret;
ret = usb_control_msg(usbdev, usb_sndctrlpipe(usbdev, 0), 0x67,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
cmd1, cmd2, NULL, 0, LINE6_TIMEOUT * HZ);
if (ret < 0) {
dev_err(&usbdev->dev, "send failed (error %d)\n", ret);
return ret;
}
return 0;
}
static int snd_toneport_monitor_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 256;
return 0;
}
static int snd_toneport_monitor_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = line6pcm->volume_monitor;
return 0;
}
static int snd_toneport_monitor_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
int err;
if (ucontrol->value.integer.value[0] == line6pcm->volume_monitor)
return 0;
line6pcm->volume_monitor = ucontrol->value.integer.value[0];
if (line6pcm->volume_monitor > 0) {
err = line6_pcm_acquire(line6pcm, LINE6_STREAM_MONITOR);
if (err < 0) {
line6pcm->volume_monitor = 0;
line6_pcm_release(line6pcm, LINE6_STREAM_MONITOR);
return err;
}
} else {
line6_pcm_release(line6pcm, LINE6_STREAM_MONITOR);
}
return 1;
}
static int snd_toneport_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
const int size = ARRAY_SIZE(toneport_source_info);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = size;
if (uinfo->value.enumerated.item >= size)
uinfo->value.enumerated.item = size - 1;
strcpy(uinfo->value.enumerated.name,
toneport_source_info[uinfo->value.enumerated.item].name);
return 0;
}
static int snd_toneport_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
struct usb_line6_toneport *toneport =
(struct usb_line6_toneport *)line6pcm->line6;
ucontrol->value.enumerated.item[0] = toneport->source;
return 0;
}
static int snd_toneport_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
struct usb_line6_toneport *toneport =
(struct usb_line6_toneport *)line6pcm->line6;
unsigned int source;
source = ucontrol->value.enumerated.item[0];
if (source >= ARRAY_SIZE(toneport_source_info))
return -EINVAL;
if (source == toneport->source)
return 0;
toneport->source = source;
toneport_send_cmd(toneport->line6.usbdev,
toneport_source_info[source].code, 0x0000);
return 1;
}
static void toneport_start_pcm(unsigned long arg)
{
struct usb_line6_toneport *toneport = (struct usb_line6_toneport *)arg;
struct usb_line6 *line6 = &toneport->line6;
line6_pcm_acquire(line6->line6pcm, LINE6_STREAM_MONITOR);
}
static bool toneport_has_led(struct usb_line6_toneport *toneport)
{
switch (toneport->type) {
case LINE6_GUITARPORT:
case LINE6_TONEPORT_GX:
return true;
default:
return false;
}
}
static void toneport_update_led(struct usb_line6_toneport *toneport)
{
toneport_send_cmd(toneport->line6.usbdev,
(toneport->leds[0].dev.brightness << 8) | 0x0002,
toneport->leds[1].dev.brightness);
}
static void toneport_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct toneport_led *leds =
container_of(led_cdev, struct toneport_led, dev);
toneport_update_led(leds->toneport);
}
static int toneport_init_leds(struct usb_line6_toneport *toneport)
{
struct device *dev = &toneport->line6.usbdev->dev;
int i, err;
for (i = 0; i < 2; i++) {
struct toneport_led *led = &toneport->leds[i];
struct led_classdev *leddev = &led->dev;
led->toneport = toneport;
snprintf(led->name, sizeof(led->name), "%s::%s",
dev_name(dev), led_colors[i]);
leddev->name = led->name;
leddev->brightness = led_init_vals[i];
leddev->max_brightness = 0x26;
leddev->brightness_set = toneport_led_brightness_set;
err = led_classdev_register(dev, leddev);
if (err)
return err;
led->registered = true;
}
return 0;
}
static void toneport_remove_leds(struct usb_line6_toneport *toneport)
{
struct toneport_led *led;
int i;
for (i = 0; i < 2; i++) {
led = &toneport->leds[i];
if (!led->registered)
break;
led_classdev_unregister(&led->dev);
led->registered = false;
}
}
static bool toneport_has_source_select(struct usb_line6_toneport *toneport)
{
switch (toneport->type) {
case LINE6_TONEPORT_UX1:
case LINE6_TONEPORT_UX2:
case LINE6_PODSTUDIO_UX1:
case LINE6_PODSTUDIO_UX2:
return true;
default:
return false;
}
}
static void toneport_setup(struct usb_line6_toneport *toneport)
{
int ticks;
struct usb_line6 *line6 = &toneport->line6;
struct usb_device *usbdev = line6->usbdev;
ticks = (int)get_seconds();
line6_write_data(line6, 0x80c6, &ticks, 4);
toneport_send_cmd(usbdev, 0x0301, 0x0000);
if (toneport_has_source_select(toneport))
toneport_send_cmd(usbdev,
toneport_source_info[toneport->source].code,
0x0000);
if (toneport_has_led(toneport))
toneport_update_led(toneport);
mod_timer(&toneport->timer, jiffies + TONEPORT_PCM_DELAY * HZ);
}
static void line6_toneport_disconnect(struct usb_line6 *line6)
{
struct usb_line6_toneport *toneport =
(struct usb_line6_toneport *)line6;
del_timer_sync(&toneport->timer);
if (toneport_has_led(toneport))
toneport_remove_leds(toneport);
}
static int toneport_init(struct usb_line6 *line6,
const struct usb_device_id *id)
{
int err;
struct usb_line6_toneport *toneport = (struct usb_line6_toneport *) line6;
toneport->type = id->driver_info;
setup_timer(&toneport->timer, toneport_start_pcm,
(unsigned long)toneport);
line6->disconnect = line6_toneport_disconnect;
err = line6_init_pcm(line6, &toneport_pcm_properties);
if (err < 0)
return err;
err = snd_ctl_add(line6->card,
snd_ctl_new1(&toneport_control_monitor,
line6->line6pcm));
if (err < 0)
return err;
if (toneport_has_source_select(toneport)) {
err =
snd_ctl_add(line6->card,
snd_ctl_new1(&toneport_control_source,
line6->line6pcm));
if (err < 0)
return err;
}
line6_read_serial_number(line6, &toneport->serial_number);
line6_read_data(line6, 0x80c2, &toneport->firmware_version, 1);
if (toneport_has_led(toneport)) {
err = toneport_init_leds(toneport);
if (err < 0)
return err;
}
toneport_setup(toneport);
return snd_card_register(line6->card);
}
static int toneport_reset_resume(struct usb_interface *interface)
{
toneport_setup(usb_get_intfdata(interface));
return line6_resume(interface);
}
static int toneport_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
return line6_probe(interface, id, "Line6-TonePort",
&toneport_properties_table[id->driver_info],
toneport_init, sizeof(struct usb_line6_toneport));
}
