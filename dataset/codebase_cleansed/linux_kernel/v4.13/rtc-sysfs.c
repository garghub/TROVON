static ssize_t
name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s %s\n", dev_driver_string(dev->parent),
dev_name(dev->parent));
}
static ssize_t
date_show(struct device *dev, struct device_attribute *attr, char *buf)
{
ssize_t retval;
struct rtc_time tm;
retval = rtc_read_time(to_rtc_device(dev), &tm);
if (retval == 0) {
retval = sprintf(buf, "%04d-%02d-%02d\n",
tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}
return retval;
}
static ssize_t
time_show(struct device *dev, struct device_attribute *attr, char *buf)
{
ssize_t retval;
struct rtc_time tm;
retval = rtc_read_time(to_rtc_device(dev), &tm);
if (retval == 0) {
retval = sprintf(buf, "%02d:%02d:%02d\n",
tm.tm_hour, tm.tm_min, tm.tm_sec);
}
return retval;
}
static ssize_t
since_epoch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
ssize_t retval;
struct rtc_time tm;
retval = rtc_read_time(to_rtc_device(dev), &tm);
if (retval == 0) {
unsigned long time;
rtc_tm_to_time(&tm, &time);
retval = sprintf(buf, "%lu\n", time);
}
return retval;
}
static ssize_t
max_user_freq_show(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", to_rtc_device(dev)->max_user_freq);
}
static ssize_t
max_user_freq_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t n)
{
struct rtc_device *rtc = to_rtc_device(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 0, &val);
if (err)
return err;
if (val >= 4096 || val == 0)
return -EINVAL;
rtc->max_user_freq = (int)val;
return n;
}
static ssize_t
hctosys_show(struct device *dev, struct device_attribute *attr, char *buf)
{
#ifdef CONFIG_RTC_HCTOSYS_DEVICE
if (rtc_hctosys_ret == 0 &&
strcmp(dev_name(&to_rtc_device(dev)->dev),
CONFIG_RTC_HCTOSYS_DEVICE) == 0)
return sprintf(buf, "1\n");
else
#endif
return sprintf(buf, "0\n");
}
static ssize_t
wakealarm_show(struct device *dev, struct device_attribute *attr, char *buf)
{
ssize_t retval;
unsigned long alarm;
struct rtc_wkalrm alm;
retval = rtc_read_alarm(to_rtc_device(dev), &alm);
if (retval == 0 && alm.enabled) {
rtc_tm_to_time(&alm.time, &alarm);
retval = sprintf(buf, "%lu\n", alarm);
}
return retval;
}
static ssize_t
wakealarm_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t n)
{
ssize_t retval;
unsigned long now, alarm;
unsigned long push = 0;
struct rtc_wkalrm alm;
struct rtc_device *rtc = to_rtc_device(dev);
const char *buf_ptr;
int adjust = 0;
retval = rtc_read_time(rtc, &alm.time);
if (retval < 0)
return retval;
rtc_tm_to_time(&alm.time, &now);
buf_ptr = buf;
if (*buf_ptr == '+') {
buf_ptr++;
if (*buf_ptr == '=') {
buf_ptr++;
push = 1;
} else
adjust = 1;
}
retval = kstrtoul(buf_ptr, 0, &alarm);
if (retval)
return retval;
if (adjust) {
alarm += now;
}
if (alarm > now || push) {
retval = rtc_read_alarm(rtc, &alm);
if (retval < 0)
return retval;
if (alm.enabled) {
if (push) {
rtc_tm_to_time(&alm.time, &push);
alarm += push;
} else
return -EBUSY;
} else if (push)
return -EINVAL;
alm.enabled = 1;
} else {
alm.enabled = 0;
alarm = now + 300;
}
rtc_time_to_tm(alarm, &alm.time);
retval = rtc_set_alarm(rtc, &alm);
return (retval < 0) ? retval : n;
}
static ssize_t
offset_show(struct device *dev, struct device_attribute *attr, char *buf)
{
ssize_t retval;
long offset;
retval = rtc_read_offset(to_rtc_device(dev), &offset);
if (retval == 0)
retval = sprintf(buf, "%ld\n", offset);
return retval;
}
static ssize_t
offset_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t n)
{
ssize_t retval;
long offset;
retval = kstrtol(buf, 10, &offset);
if (retval == 0)
retval = rtc_set_offset(to_rtc_device(dev), offset);
return (retval < 0) ? retval : n;
}
static bool rtc_does_wakealarm(struct rtc_device *rtc)
{
if (!device_can_wakeup(rtc->dev.parent))
return false;
return rtc->ops->set_alarm != NULL;
}
static umode_t rtc_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct rtc_device *rtc = to_rtc_device(dev);
umode_t mode = attr->mode;
if (attr == &dev_attr_wakealarm.attr) {
if (!rtc_does_wakealarm(rtc))
mode = 0;
} else if (attr == &dev_attr_offset.attr) {
if (!rtc->ops->set_offset)
mode = 0;
}
return mode;
}
const struct attribute_group **rtc_get_dev_attribute_groups(void)
{
return rtc_attr_groups;
}
