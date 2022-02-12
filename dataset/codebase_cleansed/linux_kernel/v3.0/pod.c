static void pod_mark_batch_all_dirty(struct usb_line6_pod *pod)
{
int i;
for (i = 0; i < POD_CONTROL_SIZE; i++)
set_bit(i, pod->param_dirty);
}
static char *pod_alloc_sysex_buffer(struct usb_line6_pod *pod, int code,
int size)
{
return line6_alloc_sysex_buffer(&pod->line6, POD_SYSEX_CODE, code,
size);
}
static void pod_dump(struct usb_line6_pod *pod, const unsigned char *data)
{
int size = 1 + sizeof(pod->prog_data);
char *sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_DUMP, size);
if (!sysex)
return;
sysex[SYSEX_DATA_OFS] = 5;
memcpy(sysex + SYSEX_DATA_OFS + 1, data, sizeof(pod->prog_data));
line6_send_sysex_message(&pod->line6, sysex, size);
memcpy(&pod->prog_data, data, sizeof(pod->prog_data));
pod_mark_batch_all_dirty(pod);
kfree(sysex);
}
static void pod_store_parameter(struct usb_line6_pod *pod, int param, int value)
{
pod->prog_data.control[param] = value;
set_bit(param, pod->param_dirty);
pod->dirty = 1;
}
static void pod_save_button_pressed(struct usb_line6_pod *pod, int type,
int index)
{
pod->dirty = 0;
set_bit(POD_SAVE_PRESSED, &pod->atomic_flags);
}
void line6_pod_process_message(struct usb_line6_pod *pod)
{
const unsigned char *buf = pod->line6.buffer_message;
switch (buf[0] & 0xf0) {
case LINE6_PARAM_CHANGE:
case LINE6_PROGRAM_CHANGE:
case LINE6_SYSEX_BEGIN:
break;
default:
return;
}
switch (buf[0]) {
case LINE6_PARAM_CHANGE | LINE6_CHANNEL_DEVICE:
pod_store_parameter(pod, buf[1], buf[2]);
case LINE6_PARAM_CHANGE | LINE6_CHANNEL_HOST:
if ((buf[1] == POD_amp_model_setup) ||
(buf[1] == POD_effect_setup))
line6_dump_request_async(&pod->dumpreq, &pod->line6, 0,
LINE6_DUMP_CURRENT);
break;
case LINE6_PROGRAM_CHANGE | LINE6_CHANNEL_DEVICE:
case LINE6_PROGRAM_CHANGE | LINE6_CHANNEL_HOST:
pod->channel_num = buf[1];
pod->dirty = 0;
set_bit(POD_CHANNEL_DIRTY, &pod->atomic_flags);
line6_dump_request_async(&pod->dumpreq, &pod->line6, 0,
LINE6_DUMP_CURRENT);
break;
case LINE6_SYSEX_BEGIN | LINE6_CHANNEL_DEVICE:
case LINE6_SYSEX_BEGIN | LINE6_CHANNEL_UNKNOWN:
if (memcmp(buf + 1, line6_midi_id, sizeof(line6_midi_id)) == 0) {
switch (buf[5]) {
case POD_SYSEX_DUMP:
if (pod->line6.message_length ==
sizeof(pod->prog_data) + 7) {
switch (pod->dumpreq.in_progress) {
case LINE6_DUMP_CURRENT:
memcpy(&pod->prog_data, buf + 7,
sizeof(pod->prog_data));
pod_mark_batch_all_dirty(pod);
break;
case POD_DUMP_MEMORY:
memcpy(&pod->prog_data_buf,
buf + 7,
sizeof
(pod->prog_data_buf));
break;
default:
DEBUG_MESSAGES(dev_err
(pod->
line6.ifcdev,
"unknown dump code %02X\n",
pod->
dumpreq.in_progress));
}
line6_dump_finished(&pod->dumpreq);
pod_startup3(pod);
} else
DEBUG_MESSAGES(dev_err
(pod->line6.ifcdev,
"wrong size of channel dump message (%d instead of %d)\n",
pod->
line6.message_length,
(int)
sizeof(pod->prog_data) +
7));
break;
case POD_SYSEX_SYSTEM:{
short value =
((int)buf[7] << 12) | ((int)buf[8]
<< 8) |
((int)buf[9] << 4) | (int)buf[10];
#define PROCESS_SYSTEM_PARAM(x) \
case POD_ ## x: \
pod->x.value = value; \
wake_up(&pod->x.wait); \
break;
switch (buf[6]) {
PROCESS_SYSTEM_PARAM
(monitor_level);
PROCESS_SYSTEM_PARAM(routing);
PROCESS_SYSTEM_PARAM
(tuner_mute);
PROCESS_SYSTEM_PARAM
(tuner_freq);
PROCESS_SYSTEM_PARAM
(tuner_note);
PROCESS_SYSTEM_PARAM
(tuner_pitch);
#undef PROCESS_SYSTEM_PARAM
default:
DEBUG_MESSAGES(dev_err
(pod->
line6.ifcdev,
"unknown tuner/system response %02X\n",
buf[6]));
}
break;
}
case POD_SYSEX_FINISH:
break;
case POD_SYSEX_SAVE:
pod_save_button_pressed(pod, buf[6], buf[7]);
break;
case POD_SYSEX_CLIP:
DEBUG_MESSAGES(dev_err
(pod->line6.ifcdev,
"audio clipped\n"));
pod->clipping.value = 1;
wake_up(&pod->clipping.wait);
break;
case POD_SYSEX_STORE:
DEBUG_MESSAGES(dev_err
(pod->line6.ifcdev,
"message %02X not yet implemented\n",
buf[5]));
break;
default:
DEBUG_MESSAGES(dev_err
(pod->line6.ifcdev,
"unknown sysex message %02X\n",
buf[5]));
}
} else
if (memcmp
(buf, pod_version_header,
sizeof(pod_version_header)) == 0) {
pod->firmware_version =
buf[13] * 100 + buf[14] * 10 + buf[15];
pod->device_id =
((int)buf[8] << 16) | ((int)buf[9] << 8) | (int)
buf[10];
pod_startup4(pod);
} else
DEBUG_MESSAGES(dev_err
(pod->line6.ifcdev,
"unknown sysex header\n"));
break;
case LINE6_SYSEX_END:
break;
default:
DEBUG_MESSAGES(dev_err
(pod->line6.ifcdev,
"POD: unknown message %02X\n", buf[0]));
}
}
void line6_pod_midi_postprocess(struct usb_line6_pod *pod, unsigned char *data,
int length)
{
int i;
if (!pod->midi_postprocess)
return;
for (i = 0; i < length; ++i) {
if (data[i] == (LINE6_PROGRAM_CHANGE | LINE6_CHANNEL_HOST)) {
line6_invalidate_current(&pod->dumpreq);
break;
} else
if ((data[i] == (LINE6_PARAM_CHANGE | LINE6_CHANNEL_HOST))
&& (i < length - 1))
if ((data[i + 1] == POD_amp_model_setup)
|| (data[i + 1] == POD_effect_setup)) {
line6_invalidate_current(&pod->dumpreq);
break;
}
}
}
static void pod_send_channel(struct usb_line6_pod *pod, int value)
{
line6_invalidate_current(&pod->dumpreq);
if (line6_send_program(&pod->line6, value) == 0)
pod->channel_num = value;
else
line6_dump_finished(&pod->dumpreq);
}
void line6_pod_transmit_parameter(struct usb_line6_pod *pod, int param,
int value)
{
if (line6_transmit_parameter(&pod->line6, param, value) == 0)
pod_store_parameter(pod, param, value);
if ((param == POD_amp_model_setup) || (param == POD_effect_setup))
line6_invalidate_current(&pod->dumpreq);
}
static int pod_resolve(const char *buf, short block0, short block1,
unsigned char *location)
{
unsigned long value;
short block;
int ret;
ret = strict_strtoul(buf, 10, &value);
if (ret)
return ret;
block = (value < 0x40) ? block0 : block1;
value &= 0x3f;
location[0] = block >> 7;
location[1] = value | (block & 0x7f);
return 0;
}
static ssize_t pod_send_store_command(struct device *dev, const char *buf,
size_t count, short block0, short block1)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
int ret;
int size = 3 + sizeof(pod->prog_data_buf);
char *sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_STORE, size);
if (!sysex)
return 0;
sysex[SYSEX_DATA_OFS] = 5;
ret = pod_resolve(buf, block0, block1, sysex + SYSEX_DATA_OFS + 1);
if (ret) {
kfree(sysex);
return ret;
}
memcpy(sysex + SYSEX_DATA_OFS + 3, &pod->prog_data_buf,
sizeof(pod->prog_data_buf));
line6_send_sysex_message(&pod->line6, sysex, size);
kfree(sysex);
return count;
}
static ssize_t pod_send_retrieve_command(struct device *dev, const char *buf,
size_t count, short block0,
short block1)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
int ret;
int size = 4;
char *sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_DUMPMEM, size);
if (!sysex)
return 0;
ret = pod_resolve(buf, block0, block1, sysex + SYSEX_DATA_OFS);
if (ret) {
kfree(sysex);
return ret;
}
sysex[SYSEX_DATA_OFS + 2] = 0;
sysex[SYSEX_DATA_OFS + 3] = 0;
line6_dump_started(&pod->dumpreq, POD_DUMP_MEMORY);
if (line6_send_sysex_message(&pod->line6, sysex, size) < size)
line6_dump_finished(&pod->dumpreq);
kfree(sysex);
return count;
}
static ssize_t get_name_generic(struct usb_line6_pod *pod, const char *str,
char *buf)
{
int length = 0;
const char *p1;
char *p2;
char *last_non_space = buf;
int retval = line6_dump_wait_interruptible(&pod->dumpreq);
if (retval < 0)
return retval;
for (p1 = str, p2 = buf; *p1; ++p1, ++p2) {
*p2 = *p1;
if (*p2 != ' ')
last_non_space = p2;
if (++length == POD_NAME_LENGTH)
break;
}
*(last_non_space + 1) = '\n';
return last_non_space - buf + 2;
}
static ssize_t pod_get_channel(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return sprintf(buf, "%d\n", pod->channel_num);
}
static ssize_t pod_set_channel(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
unsigned long value;
int ret;
ret = strict_strtoul(buf, 10, &value);
if (ret)
return ret;
pod_send_channel(pod, value);
return count;
}
static ssize_t pod_get_name(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return get_name_generic(pod, pod->prog_data.header + POD_NAME_OFFSET,
buf);
}
static ssize_t pod_get_name_buf(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return get_name_generic(pod,
pod->prog_data_buf.header + POD_NAME_OFFSET,
buf);
}
static ssize_t pod_get_dump(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
int retval = line6_dump_wait_interruptible(&pod->dumpreq);
if (retval < 0)
return retval;
memcpy(buf, &pod->prog_data, sizeof(pod->prog_data));
return sizeof(pod->prog_data);
}
static ssize_t pod_set_dump(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
if (count != sizeof(pod->prog_data)) {
dev_err(pod->line6.ifcdev,
"data block must be exactly %d bytes\n",
(int)sizeof(pod->prog_data));
return -EINVAL;
}
pod_dump(pod, buf);
return sizeof(pod->prog_data);
}
static bool pod_is_tuner(int code)
{
return
(code == POD_tuner_mute) ||
(code == POD_tuner_freq) ||
(code == POD_tuner_note) || (code == POD_tuner_pitch);
}
static int pod_get_system_param_int(struct usb_line6_pod *pod, int *value,
int code, struct ValueWait *param, int sign)
{
char *sysex;
static const int size = 1;
int retval = 0;
if (((pod->prog_data.control[POD_tuner] & 0x40) == 0)
&& pod_is_tuner(code))
return -ENODEV;
param->value = POD_system_invalid;
sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_SYSTEMREQ, size);
if (!sysex)
return -ENOMEM;
sysex[SYSEX_DATA_OFS] = code;
line6_send_sysex_message(&pod->line6, sysex, size);
kfree(sysex);
retval =
wait_event_interruptible(param->wait,
param->value != POD_system_invalid);
if (retval < 0)
return retval;
*value = sign ? (int)(signed short)param->value : (int)(unsigned short)
param->value;
if (*value == POD_system_invalid)
*value = 0;
return 0;
}
static ssize_t pod_get_system_param_string(struct usb_line6_pod *pod, char *buf,
int code, struct ValueWait *param,
int sign)
{
int retval, value = 0;
retval = pod_get_system_param_int(pod, &value, code, param, sign);
if (retval < 0)
return retval;
return sprintf(buf, "%d\n", value);
}
static int pod_set_system_param_int(struct usb_line6_pod *pod, int value,
int code)
{
char *sysex;
static const int size = 5;
if (((pod->prog_data.control[POD_tuner] & 0x40) == 0)
&& pod_is_tuner(code))
return -EINVAL;
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
static ssize_t pod_set_system_param_string(struct usb_line6_pod *pod,
const char *buf, int count, int code,
unsigned short mask)
{
int retval;
unsigned short value = simple_strtoul(buf, NULL, 10) & mask;
retval = pod_set_system_param_int(pod, value, code);
return (retval < 0) ? retval : count;
}
static ssize_t pod_get_dump_buf(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
int retval = line6_dump_wait_interruptible(&pod->dumpreq);
if (retval < 0)
return retval;
memcpy(buf, &pod->prog_data_buf, sizeof(pod->prog_data_buf));
return sizeof(pod->prog_data_buf);
}
static ssize_t pod_set_dump_buf(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
if (count != sizeof(pod->prog_data)) {
dev_err(pod->line6.ifcdev,
"data block must be exactly %d bytes\n",
(int)sizeof(pod->prog_data));
return -EINVAL;
}
memcpy(&pod->prog_data_buf, buf, sizeof(pod->prog_data));
return sizeof(pod->prog_data);
}
static ssize_t pod_set_finish(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
int size = 0;
char *sysex = pod_alloc_sysex_buffer(pod, POD_SYSEX_FINISH, size);
if (!sysex)
return 0;
line6_send_sysex_message(&pod->line6, sysex, size);
kfree(sysex);
return count;
}
static ssize_t pod_set_store_channel(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return pod_send_store_command(dev, buf, count, 0x0000, 0x00c0);
}
static ssize_t pod_set_store_effects_setup(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return pod_send_store_command(dev, buf, count, 0x0080, 0x0080);
}
static ssize_t pod_set_store_amp_setup(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return pod_send_store_command(dev, buf, count, 0x0040, 0x0100);
}
static ssize_t pod_set_retrieve_channel(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return pod_send_retrieve_command(dev, buf, count, 0x0000, 0x00c0);
}
static ssize_t pod_set_retrieve_effects_setup(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return pod_send_retrieve_command(dev, buf, count, 0x0080, 0x0080);
}
static ssize_t pod_set_retrieve_amp_setup(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return pod_send_retrieve_command(dev, buf, count, 0x0040, 0x0100);
}
static ssize_t pod_get_dirty(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
buf[0] = pod->dirty ? '1' : '0';
buf[1] = '\n';
return 2;
}
static ssize_t pod_get_midi_postprocess(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return sprintf(buf, "%d\n", pod->midi_postprocess);
}
static ssize_t pod_set_midi_postprocess(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
unsigned long value;
int ret;
ret = strict_strtoul(buf, 10, &value);
if (ret)
return ret;
pod->midi_postprocess = value ? 1 : 0;
return count;
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
static ssize_t pod_wait_for_clip(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *interface = to_usb_interface(dev);
struct usb_line6_pod *pod = usb_get_intfdata(interface);
return wait_event_interruptible(pod->clipping.wait,
pod->clipping.value != 0);
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
if (pod->startup_progress >= POD_STARTUP_LAST)
return;
pod->startup_progress = POD_STARTUP_DUMPREQ;
line6_start_timer(&pod->startup_timer, POD_STARTUP_DELAY, pod_startup2,
(unsigned long)pod);
line6_dump_request_async(&pod->dumpreq, &pod->line6, 0,
LINE6_DUMP_CURRENT);
}
static void pod_startup3(struct usb_line6_pod *pod)
{
struct usb_line6 *line6 = &pod->line6;
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_VERSIONREQ);
line6_version_request_async(line6);
}
static void pod_startup4(struct usb_line6_pod *pod)
{
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_WORKQUEUE);
schedule_work(&pod->startup_work);
}
static void pod_startup5(struct work_struct *work)
{
struct usb_line6_pod *pod =
container_of(work, struct usb_line6_pod, startup_work);
struct usb_line6 *line6 = &pod->line6;
CHECK_STARTUP_PROGRESS(pod->startup_progress, POD_STARTUP_SETUP);
line6_read_serial_number(&pod->line6, &pod->serial_number);
line6_register_audio(line6);
line6_pod_create_files(pod->firmware_version,
line6->properties->device_bit, line6->ifcdev);
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
ucontrol->value.integer.value[0] = pod->monitor_level.value;
return 0;
}
static int snd_pod_control_monitor_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_line6_pcm *line6pcm = snd_kcontrol_chip(kcontrol);
struct usb_line6_pod *pod = (struct usb_line6_pod *)line6pcm->line6;
if (ucontrol->value.integer.value[0] == pod->monitor_level.value)
return 0;
pod->monitor_level.value = ucontrol->value.integer.value[0];
pod_set_system_param_int(pod, ucontrol->value.integer.value[0],
POD_monitor_level);
return 1;
}
static void pod_destruct(struct usb_interface *interface)
{
struct usb_line6_pod *pod = usb_get_intfdata(interface);
struct usb_line6 *line6;
if (pod == NULL)
return;
line6 = &pod->line6;
if (line6 == NULL)
return;
line6_cleanup_audio(line6);
del_timer(&pod->startup_timer);
cancel_work_sync(&pod->startup_work);
line6_dumpreq_destruct(&pod->dumpreq);
}
static int pod_create_files2(struct device *dev)
{
int err;
CHECK_RETURN(device_create_file(dev, &dev_attr_channel));
CHECK_RETURN(device_create_file(dev, &dev_attr_clip));
CHECK_RETURN(device_create_file(dev, &dev_attr_device_id));
CHECK_RETURN(device_create_file(dev, &dev_attr_dirty));
CHECK_RETURN(device_create_file(dev, &dev_attr_dump));
CHECK_RETURN(device_create_file(dev, &dev_attr_dump_buf));
CHECK_RETURN(device_create_file(dev, &dev_attr_finish));
CHECK_RETURN(device_create_file(dev, &dev_attr_firmware_version));
CHECK_RETURN(device_create_file(dev, &dev_attr_midi_postprocess));
CHECK_RETURN(device_create_file(dev, &dev_attr_monitor_level));
CHECK_RETURN(device_create_file(dev, &dev_attr_name));
CHECK_RETURN(device_create_file(dev, &dev_attr_name_buf));
CHECK_RETURN(device_create_file(dev, &dev_attr_retrieve_amp_setup));
CHECK_RETURN(device_create_file(dev, &dev_attr_retrieve_channel));
CHECK_RETURN(device_create_file(dev, &dev_attr_retrieve_effects_setup));
CHECK_RETURN(device_create_file(dev, &dev_attr_routing));
CHECK_RETURN(device_create_file(dev, &dev_attr_serial_number));
CHECK_RETURN(device_create_file(dev, &dev_attr_store_amp_setup));
CHECK_RETURN(device_create_file(dev, &dev_attr_store_channel));
CHECK_RETURN(device_create_file(dev, &dev_attr_store_effects_setup));
CHECK_RETURN(device_create_file(dev, &dev_attr_tuner_freq));
CHECK_RETURN(device_create_file(dev, &dev_attr_tuner_mute));
CHECK_RETURN(device_create_file(dev, &dev_attr_tuner_note));
CHECK_RETURN(device_create_file(dev, &dev_attr_tuner_pitch));
#ifdef CONFIG_LINE6_USB_RAW
CHECK_RETURN(device_create_file(dev, &dev_attr_raw));
#endif
return 0;
}
static int pod_try_init(struct usb_interface *interface,
struct usb_line6_pod *pod)
{
int err;
struct usb_line6 *line6 = &pod->line6;
init_timer(&pod->startup_timer);
INIT_WORK(&pod->startup_work, pod_startup5);
if ((interface == NULL) || (pod == NULL))
return -ENODEV;
pod->channel_num = 255;
init_waitqueue_head(&pod->monitor_level.wait);
init_waitqueue_head(&pod->routing.wait);
init_waitqueue_head(&pod->tuner_mute.wait);
init_waitqueue_head(&pod->tuner_freq.wait);
init_waitqueue_head(&pod->tuner_note.wait);
init_waitqueue_head(&pod->tuner_pitch.wait);
init_waitqueue_head(&pod->clipping.wait);
memset(pod->param_dirty, 0xff, sizeof(pod->param_dirty));
err = line6_dumpreq_init(&pod->dumpreq, pod_request_channel,
sizeof(pod_request_channel));
if (err < 0) {
dev_err(&interface->dev, "Out of memory\n");
return -ENOMEM;
}
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
pod->monitor_level.value = POD_system_invalid;
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
line6_pod_remove_files(pod->firmware_version,
pod->line6.
properties->device_bit, dev);
device_remove_file(dev, &dev_attr_channel);
device_remove_file(dev, &dev_attr_clip);
device_remove_file(dev, &dev_attr_device_id);
device_remove_file(dev, &dev_attr_dirty);
device_remove_file(dev, &dev_attr_dump);
device_remove_file(dev, &dev_attr_dump_buf);
device_remove_file(dev, &dev_attr_finish);
device_remove_file(dev, &dev_attr_firmware_version);
device_remove_file(dev, &dev_attr_midi_postprocess);
device_remove_file(dev, &dev_attr_monitor_level);
device_remove_file(dev, &dev_attr_name);
device_remove_file(dev, &dev_attr_name_buf);
device_remove_file(dev, &dev_attr_retrieve_amp_setup);
device_remove_file(dev, &dev_attr_retrieve_channel);
device_remove_file(dev,
&dev_attr_retrieve_effects_setup);
device_remove_file(dev, &dev_attr_routing);
device_remove_file(dev, &dev_attr_serial_number);
device_remove_file(dev, &dev_attr_store_amp_setup);
device_remove_file(dev, &dev_attr_store_channel);
device_remove_file(dev, &dev_attr_store_effects_setup);
device_remove_file(dev, &dev_attr_tuner_freq);
device_remove_file(dev, &dev_attr_tuner_mute);
device_remove_file(dev, &dev_attr_tuner_note);
device_remove_file(dev, &dev_attr_tuner_pitch);
#ifdef CONFIG_LINE6_USB_RAW
device_remove_file(dev, &dev_attr_raw);
#endif
}
}
pod_destruct(interface);
}
