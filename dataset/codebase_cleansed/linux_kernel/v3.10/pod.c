static char *pod_alloc_sysex_buffer(struct usb_line6_pod *pod, int code,
int size)
{
return line6_alloc_sysex_buffer(&pod->line6, POD_SYSEX_CODE, code,
size);
}
void line6_pod_process_message(struct usb_line6_pod *pod)
{
const unsigned char *buf = pod->line6.buffer_message;
if (memcmp(buf, pod_version_header, sizeof(pod_version_header)) == 0) {
pod->firmware_version = buf[13] * 100 + buf[14] * 10 + buf[15];
pod->device_id = ((int)buf[8] << 16) | ((int)buf[9] << 8) |
(int) buf[10];
pod_startup3(pod);
return;
}
if (buf[0] != (LINE6_SYSEX_BEGIN | LINE6_CHANNEL_DEVICE) &&
buf[0] != (LINE6_SYSEX_BEGIN | LINE6_CHANNEL_UNKNOWN)) {
return;
}
if (memcmp(buf + 1, line6_midi_id, sizeof(line6_midi_id)) != 0)
return;
if (buf[5] == POD_SYSEX_SYSTEM && buf[6] == POD_MONITOR_LEVEL) {
short value = ((int)buf[7] << 12) | ((int)buf[8] << 8) |
((int)buf[9] << 4) | (int)buf[10];
pod->monitor_level = value;
}
}
void line6_pod_transmit_parameter(struct usb_line6_pod *pod, int param,
u8 value)
{
line6_transmit_parameter(&pod->line6, param, value);
}
static int pod_set_system_param_int(struct usb_line6_pod *pod, int value,
int code)
{
char *sysex;
static const int size = 5;
sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_SYSTEM, size);
if (!sysex)
return -ENOMEM;
sysex[SYSEX_DATA_OFS] = code;
sysex[SYSEX_DATA_OFS + 1] = (value >> 12) & 0x0f;
sysex[SYSEX_DATA_OFS + 2] = (value >> 8) & 0x0f;
sysex[SYSEX_DATA_OFS + 3] = (value >> 4) & 0x0f;
sysex[SYSEX_DATA_OFS + 4] = (value) & 0x0f;
line6_send_sysex_message(&pod->line6, sysex, size);
kfree(sysex);
return 0;
}
static ssize_t pod_get_serial_number(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return sprintf(buf, "%d\n", pod->serial_number);
}
static ssize_t pod_get_firmware_version(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return sprintf(buf, "%d.%02d\n", pod->firmware_version / 100,
pod->firmware_version % 100);
}
static ssize_t pod_get_device_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return sprintf(buf, "%d\n", pod->device_id);
}
static void pod_startup1(struct usb_line6_pod *pod)
{
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_INIT);
line6_start_timer(&pod->startup_timer, POD_STARTUP_DELAY, pod_startup2,
(unsigned long)pod);
}
static void pod_startup2(unsigned long data)
{
struct usb_line6_pod *pod = (struct usb_line6_pod *)data;
struct usb_line6 *line6 = &pod->line6;
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_VERSIONREQ);
line6_version_request_async(line6);
}
static void pod_startup3(struct usb_line6_pod *pod)
{
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_WORKQUEUE);
schedule_work(&pod->startup_work);
}
static void pod_startup4(struct work_struct *work)
{
struct usb_line6_pod *pod =
container_of(work, struct usb_line6_pod, startup_work);
struct usb_line6 *line6 = &pod->line6;
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_SETUP);
line6_read_serial_number(&pod->line6, &pod->serial_number);
line6_register_audio(line6);
}
static int snd_pod_control_monitor_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 65535;
return 0;
}
static int snd_pod_control_monitor_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
struct usb_line6_pod *pod = (struct usb_line6_pod *)line6pcm->line6;
ucontrol->value.integer.value[0] = pod->monitor_level;
return 0;
}
static int snd_pod_control_monitor_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
struct usb_line6_pod *pod = (struct usb_line6_pod *)line6pcm->line6;
if (ucontrol->value.integer.value[0] == pod->monitor_level)
return 0;
pod->monitor_level = ucontrol->value.integer.value[0];
pod_set_system_param_int(pod, ucontrol->value.integer.value[0],
POD_MONITOR_LEVEL);
return 1;
}
static void pod_destruct(struct usb_interface *interface)
{
struct usb_line6_pod *pod = usb_get_intfdata(interface);
if (pod == NULL)
return;
line6_cleanup_audio(&pod->line6);
del_timer(&pod->startup_timer);
cancel_work_sync(&pod->startup_work);
}
static int pod_create_files2(struct device *dev)
{
int err;
CHECK_RETURN(device_create_file(dev, &dev_attr_device_id));
CHECK_RETURN(device_create_file(dev, &dev_attr_firmware_version));
CHECK_RETURN(device_create_file(dev, &dev_attr_serial_number));
return 0;
}
static int pod_try_init(struct usb_interface *interface,
struct usb_line6_pod *pod)
{
int err;
struct usb_line6 *line6 = &pod->line6;
init_timer(&pod->startup_timer);
INIT_WORK(&pod->startup_work, pod_startup4);
if ((interface == NULL) || (pod == NULL))
return -ENODEV;
err = pod_create_files2(&interface->dev);
if (err < 0)
return err;
err = line6_init_audio(line6);
if (err < 0)
return err;
err = line6_init_midi(line6);
if (err < 0)
return err;
err = line6_init_pcm(line6, &pod_pcm_properties);
if (err < 0)
return err;
err = snd_ctl_add(line6->card,
snd_ctl_new1(&pod_control_monitor, line6->line6pcm));
if (err < 0)
return err;
if (pod->line6.properties->capabilities & LINE6_BIT_CONTROL) {
pod->monitor_level = POD_SYSTEM_INVALID;
pod_startup1(pod);
}
return 0;
}
int line6_pod_init(struct usb_interface *interface, struct usb_line6_pod *pod)
{
int err = pod_try_init(interface, pod);
if (err < 0)
pod_destruct(interface);
return err;
}
void line6_pod_disconnect(struct usb_interface *interface)
{
struct usb_line6_pod *pod;
if (interface == NULL)
return;
pod = usb_get_intfdata(interface);
if (pod != NULL) {
struct snd_line6_pcm *line6pcm = pod->line6.line6pcm;
struct device *dev = &interface->dev;
if (line6pcm != NULL)
line6_pcm_disconnect(line6pcm);
if (dev != NULL) {
device_remove_file(dev, &dev_attr_device_id);
device_remove_file(dev, &dev_attr_firmware_version);
device_remove_file(dev, &dev_attr_serial_number);
}
}
pod_destruct(interface);
}
