static bool toneport_has_led(short product)
{
return
(product == LINE6_DEVID_GUITARPORT) ||
(product == LINE6_DEVID_TONEPORT_GX);
}
static void toneport_update_led(struct device *dev)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_toneport *tp = usb_get_intfdata(interface);
struct usb_line6 *line6;
if (!tp)
return;
line6 = &tp->line6;
if (line6)
toneport_send_cmd(line6->usbdev, (led_red << 8) | 0x0002,
led_green);
}
static ssize_t toneport_set_led_red(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int retval;
long value;
retval = strict_strtol(buf, 10, &value);
if (retval)
return retval;
led_red = value;
toneport_update_led(dev);
return count;
}
static ssize_t toneport_set_led_green(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int retval;
long value;
retval = strict_strtol(buf, 10, &value);
if (retval)
return retval;
led_green = value;
toneport_update_led(dev);
return count;
}
static int toneport_send_cmd(struct usb_device *usbdev, int cmd1, int cmd2)
{
int ret;
ret = usb_control_msg(usbdev, usb_sndctrlpipe(usbdev, 0), 0x67,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
cmd1, cmd2, NULL, 0, LINE6_TIMEOUT * HZ);
if (ret < 0) {
err("send failed (error %d)\n", ret);
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
if (ucontrol->value.integer.value[0] == line6pcm->volume_monitor)
return 0;
line6pcm->volume_monitor = ucontrol->value.integer.value[0];
if (line6pcm->volume_monitor > 0)
line6_pcm_start(line6pcm, MASK_PCM_MONITOR);
else
line6_pcm_stop(line6pcm, MASK_PCM_MONITOR);
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
if (ucontrol->value.enumerated.item[0] == toneport->source)
return 0;
toneport->source = ucontrol->value.enumerated.item[0];
toneport_send_cmd(toneport->line6.usbdev,
toneport_source_info[toneport->source].code, 0x0000);
return 1;
}
static void toneport_start_pcm(unsigned long arg)
{
struct usb_line6_toneport *toneport = (struct usb_line6_toneport *)arg;
struct usb_line6 *line6 = &toneport->line6;
line6_pcm_start(line6->line6pcm, MASK_PCM_MONITOR);
}
static void toneport_destruct(struct usb_interface *interface)
{
struct usb_line6_toneport *toneport = usb_get_intfdata(interface);
struct usb_line6 *line6;
if (toneport == NULL)
return;
line6 = &toneport->line6;
if (line6 == NULL)
return;
line6_cleanup_audio(line6);
}
static void toneport_setup(struct usb_line6_toneport *toneport)
{
int ticks;
struct usb_line6 *line6 = &toneport->line6;
struct usb_device *usbdev = line6->usbdev;
ticks = (int)get_seconds();
line6_write_data(line6, 0x80c6, &ticks, 4);
toneport_send_cmd(usbdev, 0x0301, 0x0000);
switch (usbdev->descriptor.idProduct) {
case LINE6_DEVID_TONEPORT_UX1:
case LINE6_DEVID_PODSTUDIO_UX1:
toneport_send_cmd(usbdev,
toneport_source_info[toneport->source].code,
0x0000);
}
if (toneport_has_led(usbdev->descriptor.idProduct))
toneport_update_led(&usbdev->dev);
}
static int toneport_try_init(struct usb_interface *interface,
struct usb_line6_toneport *toneport)
{
int err;
struct usb_line6 *line6 = &toneport->line6;
struct usb_device *usbdev = line6->usbdev;
if ((interface == NULL) || (toneport == NULL))
return -ENODEV;
err = line6_init_audio(line6);
if (err < 0)
return err;
err = line6_init_pcm(line6, &toneport_pcm_properties);
if (err < 0)
return err;
err = snd_ctl_add(line6->card,
snd_ctl_new1(&toneport_control_monitor,
line6->line6pcm));
if (err < 0)
return err;
switch (usbdev->descriptor.idProduct) {
case LINE6_DEVID_TONEPORT_UX1:
case LINE6_DEVID_PODSTUDIO_UX1:
err =
snd_ctl_add(line6->card,
snd_ctl_new1(&toneport_control_source,
line6->line6pcm));
if (err < 0)
return err;
}
err = line6_register_audio(line6);
if (err < 0)
return err;
line6_read_serial_number(line6, &toneport->serial_number);
line6_read_data(line6, 0x80c2, &toneport->firmware_version, 1);
if (toneport_has_led(usbdev->descriptor.idProduct)) {
CHECK_RETURN(device_create_file
(&interface->dev, &dev_attr_led_red));
CHECK_RETURN(device_create_file
(&interface->dev, &dev_attr_led_green));
}
toneport_setup(toneport);
init_timer(&toneport->timer);
toneport->timer.expires = jiffies + TONEPORT_PCM_DELAY * HZ;
toneport->timer.function = toneport_start_pcm;
toneport->timer.data = (unsigned long)toneport;
add_timer(&toneport->timer);
return 0;
}
int line6_toneport_init(struct usb_interface *interface,
struct usb_line6_toneport *toneport)
{
int err = toneport_try_init(interface, toneport);
if (err < 0)
toneport_destruct(interface);
return err;
}
void line6_toneport_reset_resume(struct usb_line6_toneport *toneport)
{
toneport_setup(toneport);
}
void line6_toneport_disconnect(struct usb_interface *interface)
{
struct usb_line6_toneport *toneport;
if (interface == NULL)
return;
toneport = usb_get_intfdata(interface);
del_timer_sync(&toneport->timer);
if (toneport_has_led(toneport->line6.usbdev->descriptor.idProduct)) {
device_remove_file(&interface->dev, &dev_attr_led_red);
device_remove_file(&interface->dev, &dev_attr_led_green);
}
if (toneport != NULL) {
struct snd_line6_pcm *line6pcm = toneport->line6.line6pcm;
if (line6pcm != NULL) {
line6_pcm_stop(line6pcm, MASK_PCM_MONITOR);
line6_pcm_disconnect(line6pcm);
}
}
toneport_destruct(interface);
}
