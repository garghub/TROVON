static int wait_read(void)
{
u8 status;
int us;
for (us = APPLESMC_MIN_WAIT; us < APPLESMC_MAX_WAIT; us <<= 1) {
udelay(us);
status = inb(APPLESMC_CMD_PORT);
if (status & 0x01)
return 0;
}
pr_warn("wait_read() fail: 0x%02x\n", status);
return -EIO;
}
static int send_byte(u8 cmd, u16 port)
{
u8 status;
int us;
outb(cmd, port);
for (us = APPLESMC_MIN_WAIT; us < APPLESMC_MAX_WAIT; us <<= 1) {
udelay(us);
status = inb(APPLESMC_CMD_PORT);
if (status & 0x02)
continue;
if (status & 0x04)
return 0;
if (us << 1 == APPLESMC_MAX_WAIT)
break;
udelay(APPLESMC_RETRY_WAIT);
outb(cmd, port);
}
pr_warn("send_byte(0x%02x, 0x%04x) fail: 0x%02x\n", cmd, port, status);
return -EIO;
}
static int send_command(u8 cmd)
{
return send_byte(cmd, APPLESMC_CMD_PORT);
}
static int send_argument(const char *key)
{
int i;
for (i = 0; i < 4; i++)
if (send_byte(key[i], APPLESMC_DATA_PORT))
return -EIO;
return 0;
}
static int read_smc(u8 cmd, const char *key, u8 *buffer, u8 len)
{
u8 status, data = 0;
int i;
if (send_command(cmd) || send_argument(key)) {
pr_warn("%.4s: read arg fail\n", key);
return -EIO;
}
if (send_byte(len, APPLESMC_DATA_PORT)) {
pr_warn("%.4s: read len fail\n", key);
return -EIO;
}
for (i = 0; i < len; i++) {
if (wait_read()) {
pr_warn("%.4s: read data[%d] fail\n", key, i);
return -EIO;
}
buffer[i] = inb(APPLESMC_DATA_PORT);
}
for (i = 0; i < 16; i++) {
udelay(APPLESMC_MIN_WAIT);
status = inb(APPLESMC_CMD_PORT);
if (!(status & 0x01))
break;
data = inb(APPLESMC_DATA_PORT);
}
if (i)
pr_warn("flushed %d bytes, last value is: %d\n", i, data);
return 0;
}
static int write_smc(u8 cmd, const char *key, const u8 *buffer, u8 len)
{
int i;
if (send_command(cmd) || send_argument(key)) {
pr_warn("%s: write arg fail\n", key);
return -EIO;
}
if (send_byte(len, APPLESMC_DATA_PORT)) {
pr_warn("%.4s: write len fail\n", key);
return -EIO;
}
for (i = 0; i < len; i++) {
if (send_byte(buffer[i], APPLESMC_DATA_PORT)) {
pr_warn("%s: write data fail\n", key);
return -EIO;
}
}
return 0;
}
static int read_register_count(unsigned int *count)
{
__be32 be;
int ret;
ret = read_smc(APPLESMC_READ_CMD, KEY_COUNT_KEY, (u8 *)&be, 4);
if (ret)
return ret;
*count = be32_to_cpu(be);
return 0;
}
static int applesmc_read_entry(const struct applesmc_entry *entry,
u8 *buf, u8 len)
{
int ret;
if (entry->len != len)
return -EINVAL;
mutex_lock(&smcreg.mutex);
ret = read_smc(APPLESMC_READ_CMD, entry->key, buf, len);
mutex_unlock(&smcreg.mutex);
return ret;
}
static int applesmc_write_entry(const struct applesmc_entry *entry,
const u8 *buf, u8 len)
{
int ret;
if (entry->len != len)
return -EINVAL;
mutex_lock(&smcreg.mutex);
ret = write_smc(APPLESMC_WRITE_CMD, entry->key, buf, len);
mutex_unlock(&smcreg.mutex);
return ret;
}
static const struct applesmc_entry *applesmc_get_entry_by_index(int index)
{
struct applesmc_entry *cache = &smcreg.cache[index];
u8 key[4], info[6];
__be32 be;
int ret = 0;
if (cache->valid)
return cache;
mutex_lock(&smcreg.mutex);
if (cache->valid)
goto out;
be = cpu_to_be32(index);
ret = read_smc(APPLESMC_GET_KEY_BY_INDEX_CMD, (u8 *)&be, key, 4);
if (ret)
goto out;
ret = read_smc(APPLESMC_GET_KEY_TYPE_CMD, key, info, 6);
if (ret)
goto out;
memcpy(cache->key, key, 4);
cache->len = info[0];
memcpy(cache->type, &info[1], 4);
cache->flags = info[5];
cache->valid = 1;
out:
mutex_unlock(&smcreg.mutex);
if (ret)
return ERR_PTR(ret);
return cache;
}
static int applesmc_get_lower_bound(unsigned int *lo, const char *key)
{
int begin = 0, end = smcreg.key_count;
const struct applesmc_entry *entry;
while (begin != end) {
int middle = begin + (end - begin) / 2;
entry = applesmc_get_entry_by_index(middle);
if (IS_ERR(entry)) {
*lo = 0;
return PTR_ERR(entry);
}
if (strcmp(entry->key, key) < 0)
begin = middle + 1;
else
end = middle;
}
*lo = begin;
return 0;
}
static int applesmc_get_upper_bound(unsigned int *hi, const char *key)
{
int begin = 0, end = smcreg.key_count;
const struct applesmc_entry *entry;
while (begin != end) {
int middle = begin + (end - begin) / 2;
entry = applesmc_get_entry_by_index(middle);
if (IS_ERR(entry)) {
*hi = smcreg.key_count;
return PTR_ERR(entry);
}
if (strcmp(key, entry->key) < 0)
end = middle;
else
begin = middle + 1;
}
*hi = begin;
return 0;
}
static const struct applesmc_entry *applesmc_get_entry_by_key(const char *key)
{
int begin, end;
int ret;
ret = applesmc_get_lower_bound(&begin, key);
if (ret)
return ERR_PTR(ret);
ret = applesmc_get_upper_bound(&end, key);
if (ret)
return ERR_PTR(ret);
if (end - begin != 1)
return ERR_PTR(-EINVAL);
return applesmc_get_entry_by_index(begin);
}
static int applesmc_read_key(const char *key, u8 *buffer, u8 len)
{
const struct applesmc_entry *entry;
entry = applesmc_get_entry_by_key(key);
if (IS_ERR(entry))
return PTR_ERR(entry);
return applesmc_read_entry(entry, buffer, len);
}
static int applesmc_write_key(const char *key, const u8 *buffer, u8 len)
{
const struct applesmc_entry *entry;
entry = applesmc_get_entry_by_key(key);
if (IS_ERR(entry))
return PTR_ERR(entry);
return applesmc_write_entry(entry, buffer, len);
}
static int applesmc_has_key(const char *key, bool *value)
{
const struct applesmc_entry *entry;
entry = applesmc_get_entry_by_key(key);
if (IS_ERR(entry) && PTR_ERR(entry) != -EINVAL)
return PTR_ERR(entry);
*value = !IS_ERR(entry);
return 0;
}
static int applesmc_read_s16(const char *key, s16 *value)
{
u8 buffer[2];
int ret;
ret = applesmc_read_key(key, buffer, 2);
if (ret)
return ret;
*value = ((s16)buffer[0] << 8) | buffer[1];
return 0;
}
static void applesmc_device_init(void)
{
int total;
u8 buffer[2];
if (!smcreg.has_accelerometer)
return;
for (total = INIT_TIMEOUT_MSECS; total > 0; total -= INIT_WAIT_MSECS) {
if (!applesmc_read_key(MOTION_SENSOR_KEY, buffer, 2) &&
(buffer[0] != 0x00 || buffer[1] != 0x00))
return;
buffer[0] = 0xe0;
buffer[1] = 0x00;
applesmc_write_key(MOTION_SENSOR_KEY, buffer, 2);
msleep(INIT_WAIT_MSECS);
}
pr_warn("failed to init the device\n");
}
static int applesmc_init_index(struct applesmc_registers *s)
{
const struct applesmc_entry *entry;
unsigned int i;
if (s->index)
return 0;
s->index = kcalloc(s->temp_count, sizeof(s->index[0]), GFP_KERNEL);
if (!s->index)
return -ENOMEM;
for (i = s->temp_begin; i < s->temp_end; i++) {
entry = applesmc_get_entry_by_index(i);
if (IS_ERR(entry))
continue;
if (strcmp(entry->type, TEMP_SENSOR_TYPE))
continue;
s->index[s->index_count++] = entry->key;
}
return 0;
}
static int applesmc_init_smcreg_try(void)
{
struct applesmc_registers *s = &smcreg;
bool left_light_sensor, right_light_sensor;
unsigned int count;
u8 tmp[1];
int ret;
if (s->init_complete)
return 0;
ret = read_register_count(&count);
if (ret)
return ret;
if (s->cache && s->key_count != count) {
pr_warn("key count changed from %d to %d\n",
s->key_count, count);
kfree(s->cache);
s->cache = NULL;
}
s->key_count = count;
if (!s->cache)
s->cache = kcalloc(s->key_count, sizeof(*s->cache), GFP_KERNEL);
if (!s->cache)
return -ENOMEM;
ret = applesmc_read_key(FANS_COUNT, tmp, 1);
if (ret)
return ret;
s->fan_count = tmp[0];
ret = applesmc_get_lower_bound(&s->temp_begin, "T");
if (ret)
return ret;
ret = applesmc_get_lower_bound(&s->temp_end, "U");
if (ret)
return ret;
s->temp_count = s->temp_end - s->temp_begin;
ret = applesmc_init_index(s);
if (ret)
return ret;
ret = applesmc_has_key(LIGHT_SENSOR_LEFT_KEY, &left_light_sensor);
if (ret)
return ret;
ret = applesmc_has_key(LIGHT_SENSOR_RIGHT_KEY, &right_light_sensor);
if (ret)
return ret;
ret = applesmc_has_key(MOTION_SENSOR_KEY, &s->has_accelerometer);
if (ret)
return ret;
ret = applesmc_has_key(BACKLIGHT_KEY, &s->has_key_backlight);
if (ret)
return ret;
s->num_light_sensors = left_light_sensor + right_light_sensor;
s->init_complete = true;
pr_info("key=%d fan=%d temp=%d index=%d acc=%d lux=%d kbd=%d\n",
s->key_count, s->fan_count, s->temp_count, s->index_count,
s->has_accelerometer,
s->num_light_sensors,
s->has_key_backlight);
return 0;
}
static void applesmc_destroy_smcreg(void)
{
kfree(smcreg.index);
smcreg.index = NULL;
kfree(smcreg.cache);
smcreg.cache = NULL;
smcreg.init_complete = false;
}
static int applesmc_init_smcreg(void)
{
int ms, ret;
for (ms = 0; ms < INIT_TIMEOUT_MSECS; ms += INIT_WAIT_MSECS) {
ret = applesmc_init_smcreg_try();
if (!ret) {
if (ms)
pr_info("init_smcreg() took %d ms\n", ms);
return 0;
}
msleep(INIT_WAIT_MSECS);
}
applesmc_destroy_smcreg();
return ret;
}
static int applesmc_probe(struct platform_device *dev)
{
int ret;
ret = applesmc_init_smcreg();
if (ret)
return ret;
applesmc_device_init();
return 0;
}
static int applesmc_pm_resume(struct device *dev)
{
if (smcreg.has_key_backlight)
applesmc_write_key(BACKLIGHT_KEY, backlight_state, 2);
return 0;
}
static int applesmc_pm_restore(struct device *dev)
{
applesmc_device_init();
return applesmc_pm_resume(dev);
}
static void applesmc_calibrate(void)
{
applesmc_read_s16(MOTION_SENSOR_X_KEY, &rest_x);
applesmc_read_s16(MOTION_SENSOR_Y_KEY, &rest_y);
rest_x = -rest_x;
}
static void applesmc_idev_poll(struct input_polled_dev *dev)
{
struct input_dev *idev = dev->input;
s16 x, y;
if (applesmc_read_s16(MOTION_SENSOR_X_KEY, &x))
return;
if (applesmc_read_s16(MOTION_SENSOR_Y_KEY, &y))
return;
x = -x;
input_report_abs(idev, ABS_X, x - rest_x);
input_report_abs(idev, ABS_Y, y - rest_y);
input_sync(idev);
}
static ssize_t applesmc_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "applesmc\n");
}
static ssize_t applesmc_position_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
s16 x, y, z;
ret = applesmc_read_s16(MOTION_SENSOR_X_KEY, &x);
if (ret)
goto out;
ret = applesmc_read_s16(MOTION_SENSOR_Y_KEY, &y);
if (ret)
goto out;
ret = applesmc_read_s16(MOTION_SENSOR_Z_KEY, &z);
if (ret)
goto out;
out:
if (ret)
return ret;
else
return snprintf(buf, PAGE_SIZE, "(%d,%d,%d)\n", x, y, z);
}
static ssize_t applesmc_light_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
const struct applesmc_entry *entry;
static int data_length;
int ret;
u8 left = 0, right = 0;
u8 buffer[10];
if (!data_length) {
entry = applesmc_get_entry_by_key(LIGHT_SENSOR_LEFT_KEY);
if (IS_ERR(entry))
return PTR_ERR(entry);
if (entry->len > 10)
return -ENXIO;
data_length = entry->len;
pr_info("light sensor data length set to %d\n", data_length);
}
ret = applesmc_read_key(LIGHT_SENSOR_LEFT_KEY, buffer, data_length);
if (data_length == 10) {
left = be16_to_cpu(*(__be16 *)(buffer + 6)) >> 2;
goto out;
}
left = buffer[2];
if (ret)
goto out;
ret = applesmc_read_key(LIGHT_SENSOR_RIGHT_KEY, buffer, data_length);
right = buffer[2];
out:
if (ret)
return ret;
else
return snprintf(sysfsbuf, PAGE_SIZE, "(%d,%d)\n", left, right);
}
static ssize_t applesmc_show_sensor_label(struct device *dev,
struct device_attribute *devattr, char *sysfsbuf)
{
const char *key = smcreg.index[to_index(devattr)];
return snprintf(sysfsbuf, PAGE_SIZE, "%s\n", key);
}
static ssize_t applesmc_show_temperature(struct device *dev,
struct device_attribute *devattr, char *sysfsbuf)
{
const char *key = smcreg.index[to_index(devattr)];
int ret;
s16 value;
int temp;
ret = applesmc_read_s16(key, &value);
if (ret)
return ret;
temp = 250 * (value >> 6);
return snprintf(sysfsbuf, PAGE_SIZE, "%d\n", temp);
}
static ssize_t applesmc_show_fan_speed(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
int ret;
unsigned int speed = 0;
char newkey[5];
u8 buffer[2];
sprintf(newkey, fan_speed_fmt[to_option(attr)], to_index(attr));
ret = applesmc_read_key(newkey, buffer, 2);
speed = ((buffer[0] << 8 | buffer[1]) >> 2);
if (ret)
return ret;
else
return snprintf(sysfsbuf, PAGE_SIZE, "%u\n", speed);
}
static ssize_t applesmc_store_fan_speed(struct device *dev,
struct device_attribute *attr,
const char *sysfsbuf, size_t count)
{
int ret;
unsigned long speed;
char newkey[5];
u8 buffer[2];
if (kstrtoul(sysfsbuf, 10, &speed) < 0 || speed >= 0x4000)
return -EINVAL;
sprintf(newkey, fan_speed_fmt[to_option(attr)], to_index(attr));
buffer[0] = (speed >> 6) & 0xff;
buffer[1] = (speed << 2) & 0xff;
ret = applesmc_write_key(newkey, buffer, 2);
if (ret)
return ret;
else
return count;
}
static ssize_t applesmc_show_fan_manual(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
int ret;
u16 manual = 0;
u8 buffer[2];
ret = applesmc_read_key(FANS_MANUAL, buffer, 2);
manual = ((buffer[0] << 8 | buffer[1]) >> to_index(attr)) & 0x01;
if (ret)
return ret;
else
return snprintf(sysfsbuf, PAGE_SIZE, "%d\n", manual);
}
static ssize_t applesmc_store_fan_manual(struct device *dev,
struct device_attribute *attr,
const char *sysfsbuf, size_t count)
{
int ret;
u8 buffer[2];
unsigned long input;
u16 val;
if (kstrtoul(sysfsbuf, 10, &input) < 0)
return -EINVAL;
ret = applesmc_read_key(FANS_MANUAL, buffer, 2);
val = (buffer[0] << 8 | buffer[1]);
if (ret)
goto out;
if (input)
val = val | (0x01 << to_index(attr));
else
val = val & ~(0x01 << to_index(attr));
buffer[0] = (val >> 8) & 0xFF;
buffer[1] = val & 0xFF;
ret = applesmc_write_key(FANS_MANUAL, buffer, 2);
out:
if (ret)
return ret;
else
return count;
}
static ssize_t applesmc_show_fan_position(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
int ret;
char newkey[5];
u8 buffer[17];
sprintf(newkey, FAN_ID_FMT, to_index(attr));
ret = applesmc_read_key(newkey, buffer, 16);
buffer[16] = 0;
if (ret)
return ret;
else
return snprintf(sysfsbuf, PAGE_SIZE, "%s\n", buffer+4);
}
static ssize_t applesmc_calibrate_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
return snprintf(sysfsbuf, PAGE_SIZE, "(%d,%d)\n", rest_x, rest_y);
}
static ssize_t applesmc_calibrate_store(struct device *dev,
struct device_attribute *attr, const char *sysfsbuf, size_t count)
{
applesmc_calibrate();
return count;
}
static void applesmc_backlight_set(struct work_struct *work)
{
applesmc_write_key(BACKLIGHT_KEY, backlight_state, 2);
}
static void applesmc_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
int ret;
backlight_state[0] = value;
ret = queue_work(applesmc_led_wq, &backlight_work);
if (debug && (!ret))
dev_dbg(led_cdev->dev, "work was already on the queue.\n");
}
static ssize_t applesmc_key_count_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
int ret;
u8 buffer[4];
u32 count;
ret = applesmc_read_key(KEY_COUNT_KEY, buffer, 4);
count = ((u32)buffer[0]<<24) + ((u32)buffer[1]<<16) +
((u32)buffer[2]<<8) + buffer[3];
if (ret)
return ret;
else
return snprintf(sysfsbuf, PAGE_SIZE, "%d\n", count);
}
static ssize_t applesmc_key_at_index_read_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
const struct applesmc_entry *entry;
int ret;
entry = applesmc_get_entry_by_index(key_at_index);
if (IS_ERR(entry))
return PTR_ERR(entry);
ret = applesmc_read_entry(entry, sysfsbuf, entry->len);
if (ret)
return ret;
return entry->len;
}
static ssize_t applesmc_key_at_index_data_length_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
const struct applesmc_entry *entry;
entry = applesmc_get_entry_by_index(key_at_index);
if (IS_ERR(entry))
return PTR_ERR(entry);
return snprintf(sysfsbuf, PAGE_SIZE, "%d\n", entry->len);
}
static ssize_t applesmc_key_at_index_type_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
const struct applesmc_entry *entry;
entry = applesmc_get_entry_by_index(key_at_index);
if (IS_ERR(entry))
return PTR_ERR(entry);
return snprintf(sysfsbuf, PAGE_SIZE, "%s\n", entry->type);
}
static ssize_t applesmc_key_at_index_name_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
const struct applesmc_entry *entry;
entry = applesmc_get_entry_by_index(key_at_index);
if (IS_ERR(entry))
return PTR_ERR(entry);
return snprintf(sysfsbuf, PAGE_SIZE, "%s\n", entry->key);
}
static ssize_t applesmc_key_at_index_show(struct device *dev,
struct device_attribute *attr, char *sysfsbuf)
{
return snprintf(sysfsbuf, PAGE_SIZE, "%d\n", key_at_index);
}
static ssize_t applesmc_key_at_index_store(struct device *dev,
struct device_attribute *attr, const char *sysfsbuf, size_t count)
{
unsigned long newkey;
if (kstrtoul(sysfsbuf, 10, &newkey) < 0
|| newkey >= smcreg.key_count)
return -EINVAL;
key_at_index = newkey;
return count;
}
static void applesmc_destroy_nodes(struct applesmc_node_group *groups)
{
struct applesmc_node_group *grp;
struct applesmc_dev_attr *node;
for (grp = groups; grp->nodes; grp++) {
for (node = grp->nodes; node->sda.dev_attr.attr.name; node++)
sysfs_remove_file(&pdev->dev.kobj,
&node->sda.dev_attr.attr);
kfree(grp->nodes);
grp->nodes = NULL;
}
}
static int applesmc_create_nodes(struct applesmc_node_group *groups, int num)
{
struct applesmc_node_group *grp;
struct applesmc_dev_attr *node;
struct attribute *attr;
int ret, i;
for (grp = groups; grp->format; grp++) {
grp->nodes = kcalloc(num + 1, sizeof(*node), GFP_KERNEL);
if (!grp->nodes) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < num; i++) {
node = &grp->nodes[i];
sprintf(node->name, grp->format, i + 1);
node->sda.index = (grp->option << 16) | (i & 0xffff);
node->sda.dev_attr.show = grp->show;
node->sda.dev_attr.store = grp->store;
attr = &node->sda.dev_attr.attr;
sysfs_attr_init(attr);
attr->name = node->name;
attr->mode = S_IRUGO | (grp->store ? S_IWUSR : 0);
ret = sysfs_create_file(&pdev->dev.kobj, attr);
if (ret) {
attr->name = NULL;
goto out;
}
}
}
return 0;
out:
applesmc_destroy_nodes(groups);
return ret;
}
static int applesmc_create_accelerometer(void)
{
struct input_dev *idev;
int ret;
if (!smcreg.has_accelerometer)
return 0;
ret = applesmc_create_nodes(accelerometer_group, 1);
if (ret)
goto out;
applesmc_idev = input_allocate_polled_device();
if (!applesmc_idev) {
ret = -ENOMEM;
goto out_sysfs;
}
applesmc_idev->poll = applesmc_idev_poll;
applesmc_idev->poll_interval = APPLESMC_POLL_INTERVAL;
applesmc_calibrate();
idev = applesmc_idev->input;
idev->name = "applesmc";
idev->id.bustype = BUS_HOST;
idev->dev.parent = &pdev->dev;
idev->evbit[0] = BIT_MASK(EV_ABS);
input_set_abs_params(idev, ABS_X,
-256, 256, APPLESMC_INPUT_FUZZ, APPLESMC_INPUT_FLAT);
input_set_abs_params(idev, ABS_Y,
-256, 256, APPLESMC_INPUT_FUZZ, APPLESMC_INPUT_FLAT);
ret = input_register_polled_device(applesmc_idev);
if (ret)
goto out_idev;
return 0;
out_idev:
input_free_polled_device(applesmc_idev);
out_sysfs:
applesmc_destroy_nodes(accelerometer_group);
out:
pr_warn("driver init failed (ret=%d)!\n", ret);
return ret;
}
static void applesmc_release_accelerometer(void)
{
if (!smcreg.has_accelerometer)
return;
input_unregister_polled_device(applesmc_idev);
input_free_polled_device(applesmc_idev);
applesmc_destroy_nodes(accelerometer_group);
}
static int applesmc_create_light_sensor(void)
{
if (!smcreg.num_light_sensors)
return 0;
return applesmc_create_nodes(light_sensor_group, 1);
}
static void applesmc_release_light_sensor(void)
{
if (!smcreg.num_light_sensors)
return;
applesmc_destroy_nodes(light_sensor_group);
}
static int applesmc_create_key_backlight(void)
{
if (!smcreg.has_key_backlight)
return 0;
applesmc_led_wq = create_singlethread_workqueue("applesmc-led");
if (!applesmc_led_wq)
return -ENOMEM;
return led_classdev_register(&pdev->dev, &applesmc_backlight);
}
static void applesmc_release_key_backlight(void)
{
if (!smcreg.has_key_backlight)
return;
led_classdev_unregister(&applesmc_backlight);
destroy_workqueue(applesmc_led_wq);
}
static int applesmc_dmi_match(const struct dmi_system_id *id)
{
return 1;
}
static int __init applesmc_init(void)
{
int ret;
if (!dmi_check_system(applesmc_whitelist)) {
pr_warn("supported laptop not found!\n");
ret = -ENODEV;
goto out;
}
if (!request_region(APPLESMC_DATA_PORT, APPLESMC_NR_PORTS,
"applesmc")) {
ret = -ENXIO;
goto out;
}
ret = platform_driver_register(&applesmc_driver);
if (ret)
goto out_region;
pdev = platform_device_register_simple("applesmc", APPLESMC_DATA_PORT,
NULL, 0);
if (IS_ERR(pdev)) {
ret = PTR_ERR(pdev);
goto out_driver;
}
ret = applesmc_init_smcreg();
if (ret)
goto out_device;
ret = applesmc_create_nodes(info_group, 1);
if (ret)
goto out_smcreg;
ret = applesmc_create_nodes(fan_group, smcreg.fan_count);
if (ret)
goto out_info;
ret = applesmc_create_nodes(temp_group, smcreg.index_count);
if (ret)
goto out_fans;
ret = applesmc_create_accelerometer();
if (ret)
goto out_temperature;
ret = applesmc_create_light_sensor();
if (ret)
goto out_accelerometer;
ret = applesmc_create_key_backlight();
if (ret)
goto out_light_sysfs;
hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(hwmon_dev)) {
ret = PTR_ERR(hwmon_dev);
goto out_light_ledclass;
}
return 0;
out_light_ledclass:
applesmc_release_key_backlight();
out_light_sysfs:
applesmc_release_light_sensor();
out_accelerometer:
applesmc_release_accelerometer();
out_temperature:
applesmc_destroy_nodes(temp_group);
out_fans:
applesmc_destroy_nodes(fan_group);
out_info:
applesmc_destroy_nodes(info_group);
out_smcreg:
applesmc_destroy_smcreg();
out_device:
platform_device_unregister(pdev);
out_driver:
platform_driver_unregister(&applesmc_driver);
out_region:
release_region(APPLESMC_DATA_PORT, APPLESMC_NR_PORTS);
out:
pr_warn("driver init failed (ret=%d)!\n", ret);
return ret;
}
static void __exit applesmc_exit(void)
{
hwmon_device_unregister(hwmon_dev);
applesmc_release_key_backlight();
applesmc_release_light_sensor();
applesmc_release_accelerometer();
applesmc_destroy_nodes(temp_group);
applesmc_destroy_nodes(fan_group);
applesmc_destroy_nodes(info_group);
applesmc_destroy_smcreg();
platform_device_unregister(pdev);
platform_driver_unregister(&applesmc_driver);
release_region(APPLESMC_DATA_PORT, APPLESMC_NR_PORTS);
}
