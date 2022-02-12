static ssize_t interval_msec_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long msec = lb_interval_jiffies * 1000 / HZ;
return scnprintf(buf, PAGE_SIZE, "%lu\n", msec);
}
static ssize_t interval_msec_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long msec;
if (kstrtoul(buf, 0, &msec))
return -EINVAL;
lb_interval_jiffies = msec * HZ / 1000;
return count;
}
static int lb_throttle(void)
{
static unsigned long last_access;
unsigned long now, next_timeslot;
long delay;
int ret = 0;
mutex_lock(&lb_mutex);
now = jiffies;
next_timeslot = last_access + lb_interval_jiffies;
if (time_before(now, next_timeslot)) {
delay = (long)(next_timeslot) - (long)now;
set_current_state(TASK_INTERRUPTIBLE);
if (schedule_timeout(delay) > 0) {
ret = -EINTR;
goto out;
}
now = jiffies;
}
last_access = now;
out:
mutex_unlock(&lb_mutex);
return ret;
}
static int get_lightbar_version(struct cros_ec_device *ec,
uint32_t *ver_ptr, uint32_t *flg_ptr)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command msg = INIT_MSG(param, resp);
int ret;
param = (struct ec_params_lightbar *)msg.outdata;
param->cmd = LIGHTBAR_CMD_VERSION;
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return 0;
switch (msg.result) {
case EC_RES_INVALID_PARAM:
if (ver_ptr)
*ver_ptr = 0;
if (flg_ptr)
*flg_ptr = 0;
return 1;
case EC_RES_SUCCESS:
resp = (struct ec_response_lightbar *)msg.indata;
if (ver_ptr)
*ver_ptr = resp->version.num;
if (flg_ptr)
*flg_ptr = resp->version.flags;
return 1;
}
return 0;
}
static ssize_t version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
uint32_t version, flags;
struct cros_ec_device *ec = dev_get_drvdata(dev);
int ret;
ret = lb_throttle();
if (ret)
return ret;
if (!get_lightbar_version(ec, &version, &flags))
return -EIO;
return scnprintf(buf, PAGE_SIZE, "%d %d\n", version, flags);
}
static ssize_t brightness_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command msg = INIT_MSG(param, resp);
int ret;
unsigned int val;
struct cros_ec_device *ec = dev_get_drvdata(dev);
if (kstrtouint(buf, 0, &val))
return -EINVAL;
param = (struct ec_params_lightbar *)msg.outdata;
param->cmd = LIGHTBAR_CMD_BRIGHTNESS;
param->brightness.num = val;
ret = lb_throttle();
if (ret)
return ret;
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS)
return -EINVAL;
return count;
}
static ssize_t led_rgb_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command msg = INIT_MSG(param, resp);
struct cros_ec_device *ec = dev_get_drvdata(dev);
unsigned int val[4];
int ret, i = 0, j = 0, ok = 0;
do {
while (*buf && isspace(*buf))
buf++;
if (!*buf)
break;
ret = sscanf(buf, "%i", &val[i++]);
if (ret == 0)
return -EINVAL;
if (i == 4) {
param = (struct ec_params_lightbar *)msg.outdata;
param->cmd = LIGHTBAR_CMD_RGB;
param->rgb.led = val[0];
param->rgb.red = val[1];
param->rgb.green = val[2];
param->rgb.blue = val[3];
if ((j++ % 4) == 0) {
ret = lb_throttle();
if (ret)
return ret;
}
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS)
return -EINVAL;
i = 0;
ok = 1;
}
while (*buf && !isspace(*buf))
buf++;
} while (*buf);
return (ok && i == 0) ? count : -EINVAL;
}
static ssize_t sequence_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command msg = INIT_MSG(param, resp);
int ret;
struct cros_ec_device *ec = dev_get_drvdata(dev);
param = (struct ec_params_lightbar *)msg.outdata;
param->cmd = LIGHTBAR_CMD_GET_SEQ;
ret = lb_throttle();
if (ret)
return ret;
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS)
return scnprintf(buf, PAGE_SIZE,
"ERROR: EC returned %d\n", msg.result);
resp = (struct ec_response_lightbar *)msg.indata;
if (resp->get_seq.num >= ARRAY_SIZE(seqname))
return scnprintf(buf, PAGE_SIZE, "%d\n", resp->get_seq.num);
else
return scnprintf(buf, PAGE_SIZE, "%s\n",
seqname[resp->get_seq.num]);
}
static ssize_t sequence_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command msg = INIT_MSG(param, resp);
unsigned int num;
int ret, len;
struct cros_ec_device *ec = dev_get_drvdata(dev);
for (len = 0; len < count; len++)
if (!isalnum(buf[len]))
break;
for (num = 0; num < ARRAY_SIZE(seqname); num++)
if (!strncasecmp(seqname[num], buf, len))
break;
if (num >= ARRAY_SIZE(seqname)) {
ret = kstrtouint(buf, 0, &num);
if (ret)
return ret;
}
param = (struct ec_params_lightbar *)msg.outdata;
param->cmd = LIGHTBAR_CMD_SEQ;
param->seq.num = num;
ret = lb_throttle();
if (ret)
return ret;
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS)
return -EINVAL;
return count;
}
void ec_dev_lightbar_init(struct cros_ec_device *ec)
{
int ret = 0;
if (!get_lightbar_version(ec, NULL, NULL))
return;
ret = sysfs_create_group(&ec->vdev->kobj, &lb_cmds_attr_group);
if (ret)
pr_warn("sysfs_create_group() failed: %d\n", ret);
}
void ec_dev_lightbar_remove(struct cros_ec_device *ec)
{
sysfs_remove_group(&ec->vdev->kobj, &lb_cmds_attr_group);
}
