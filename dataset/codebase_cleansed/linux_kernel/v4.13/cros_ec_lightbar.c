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
static struct cros_ec_command *alloc_lightbar_cmd_msg(struct cros_ec_dev *ec)
{
struct cros_ec_command *msg;
int len;
len = max(sizeof(struct ec_params_lightbar),
sizeof(struct ec_response_lightbar));
msg = kmalloc(sizeof(*msg) + len, GFP_KERNEL);
if (!msg)
return NULL;
msg->version = 0;
msg->command = EC_CMD_LIGHTBAR_CMD + ec->cmd_offset;
msg->outsize = sizeof(struct ec_params_lightbar);
msg->insize = sizeof(struct ec_response_lightbar);
return msg;
}
static int get_lightbar_version(struct cros_ec_dev *ec,
uint32_t *ver_ptr, uint32_t *flg_ptr)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command *msg;
int ret;
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return 0;
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_VERSION;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0) {
ret = 0;
goto exit;
}
switch (msg->result) {
case EC_RES_INVALID_PARAM:
if (ver_ptr)
*ver_ptr = 0;
if (flg_ptr)
*flg_ptr = 0;
ret = 1;
goto exit;
case EC_RES_SUCCESS:
resp = (struct ec_response_lightbar *)msg->data;
if (ver_ptr)
*ver_ptr = resp->version.num;
if (flg_ptr)
*flg_ptr = resp->version.flags;
ret = 1;
goto exit;
}
ret = 0;
exit:
kfree(msg);
return ret;
}
static ssize_t version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
uint32_t version = 0, flags = 0;
struct cros_ec_dev *ec = container_of(dev,
struct cros_ec_dev, class_dev);
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
struct cros_ec_command *msg;
int ret;
unsigned int val;
struct cros_ec_dev *ec = container_of(dev,
struct cros_ec_dev, class_dev);
if (kstrtouint(buf, 0, &val))
return -EINVAL;
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_SET_BRIGHTNESS;
param->set_brightness.num = val;
ret = lb_throttle();
if (ret)
goto exit;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto exit;
if (msg->result != EC_RES_SUCCESS) {
ret = -EINVAL;
goto exit;
}
ret = count;
exit:
kfree(msg);
return ret;
}
static ssize_t led_rgb_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ec_params_lightbar *param;
struct cros_ec_command *msg;
struct cros_ec_dev *ec = container_of(dev,
struct cros_ec_dev, class_dev);
unsigned int val[4];
int ret, i = 0, j = 0, ok = 0;
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
do {
while (*buf && isspace(*buf))
buf++;
if (!*buf)
break;
ret = sscanf(buf, "%i", &val[i++]);
if (ret == 0)
goto exit;
if (i == 4) {
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_SET_RGB;
param->set_rgb.led = val[0];
param->set_rgb.red = val[1];
param->set_rgb.green = val[2];
param->set_rgb.blue = val[3];
if ((j++ % 4) == 0) {
ret = lb_throttle();
if (ret)
goto exit;
}
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto exit;
if (msg->result != EC_RES_SUCCESS)
goto exit;
i = 0;
ok = 1;
}
while (*buf && !isspace(*buf))
buf++;
} while (*buf);
exit:
kfree(msg);
return (ok && i == 0) ? count : -EINVAL;
}
static ssize_t sequence_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ec_params_lightbar *param;
struct ec_response_lightbar *resp;
struct cros_ec_command *msg;
int ret;
struct cros_ec_dev *ec = container_of(dev,
struct cros_ec_dev, class_dev);
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_GET_SEQ;
ret = lb_throttle();
if (ret)
goto exit;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto exit;
if (msg->result != EC_RES_SUCCESS) {
ret = scnprintf(buf, PAGE_SIZE,
"ERROR: EC returned %d\n", msg->result);
goto exit;
}
resp = (struct ec_response_lightbar *)msg->data;
if (resp->get_seq.num >= ARRAY_SIZE(seqname))
ret = scnprintf(buf, PAGE_SIZE, "%d\n", resp->get_seq.num);
else
ret = scnprintf(buf, PAGE_SIZE, "%s\n",
seqname[resp->get_seq.num]);
exit:
kfree(msg);
return ret;
}
static int lb_send_empty_cmd(struct cros_ec_dev *ec, uint8_t cmd)
{
struct ec_params_lightbar *param;
struct cros_ec_command *msg;
int ret;
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
param = (struct ec_params_lightbar *)msg->data;
param->cmd = cmd;
ret = lb_throttle();
if (ret)
goto error;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto error;
if (msg->result != EC_RES_SUCCESS) {
ret = -EINVAL;
goto error;
}
ret = 0;
error:
kfree(msg);
return ret;
}
int lb_manual_suspend_ctrl(struct cros_ec_dev *ec, uint8_t enable)
{
struct ec_params_lightbar *param;
struct cros_ec_command *msg;
int ret;
if (ec != ec_with_lightbar)
return 0;
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_MANUAL_SUSPEND_CTRL;
param->manual_suspend_ctrl.enable = enable;
ret = lb_throttle();
if (ret)
goto error;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto error;
if (msg->result != EC_RES_SUCCESS) {
ret = -EINVAL;
goto error;
}
ret = 0;
error:
kfree(msg);
return ret;
}
int lb_suspend(struct cros_ec_dev *ec)
{
if (userspace_control || ec != ec_with_lightbar)
return 0;
return lb_send_empty_cmd(ec, LIGHTBAR_CMD_SUSPEND);
}
int lb_resume(struct cros_ec_dev *ec)
{
if (userspace_control || ec != ec_with_lightbar)
return 0;
return lb_send_empty_cmd(ec, LIGHTBAR_CMD_RESUME);
}
static ssize_t sequence_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ec_params_lightbar *param;
struct cros_ec_command *msg;
unsigned int num;
int ret, len;
struct cros_ec_dev *ec = container_of(dev,
struct cros_ec_dev, class_dev);
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
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_SEQ;
param->seq.num = num;
ret = lb_throttle();
if (ret)
goto exit;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto exit;
if (msg->result != EC_RES_SUCCESS) {
ret = -EINVAL;
goto exit;
}
ret = count;
exit:
kfree(msg);
return ret;
}
static ssize_t program_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int extra_bytes, max_size, ret;
struct ec_params_lightbar *param;
struct cros_ec_command *msg;
struct cros_ec_dev *ec = container_of(dev, struct cros_ec_dev,
class_dev);
extra_bytes = sizeof(*param) - sizeof(param->set_program.data);
max_size = min(EC_LB_PROG_LEN, ec->ec_dev->max_request - extra_bytes);
if (count > max_size) {
dev_err(dev, "Program is %u bytes, too long to send (max: %u)",
(unsigned int)count, max_size);
return -EINVAL;
}
msg = alloc_lightbar_cmd_msg(ec);
if (!msg)
return -ENOMEM;
ret = lb_throttle();
if (ret)
goto exit;
dev_info(dev, "Copying %zu byte program to EC", count);
param = (struct ec_params_lightbar *)msg->data;
param->cmd = LIGHTBAR_CMD_SET_PROGRAM;
param->set_program.size = count;
memcpy(param->set_program.data, buf, count);
msg->outsize = count + extra_bytes;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto exit;
if (msg->result != EC_RES_SUCCESS) {
ret = -EINVAL;
goto exit;
}
ret = count;
exit:
kfree(msg);
return ret;
}
static ssize_t userspace_control_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", userspace_control);
}
static ssize_t userspace_control_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
bool enable;
int ret;
ret = strtobool(buf, &enable);
if (ret < 0)
return ret;
userspace_control = enable;
return count;
}
bool ec_has_lightbar(struct cros_ec_dev *ec)
{
return !!get_lightbar_version(ec, NULL, NULL);
}
static umode_t cros_ec_lightbar_attrs_are_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct cros_ec_dev *ec = container_of(dev,
struct cros_ec_dev, class_dev);
struct platform_device *pdev = to_platform_device(ec->dev);
struct cros_ec_platform *pdata = pdev->dev.platform_data;
int is_cros_ec;
is_cros_ec = strcmp(pdata->ec_name, CROS_EC_DEV_NAME);
if (is_cros_ec != 0)
return 0;
if (ec_has_lightbar(ec)) {
ec_with_lightbar = ec;
return a->mode;
}
return 0;
}
