static int abituguru_wait(struct abituguru_data *data, u8 state)
{
int timeout = ABIT_UGURU_WAIT_TIMEOUT;
while (inb_p(data->addr + ABIT_UGURU_DATA) != state) {
timeout--;
if (timeout == 0)
return -EBUSY;
if (timeout <= ABIT_UGURU_WAIT_TIMEOUT_SLEEP)
msleep(0);
}
return 0;
}
static int abituguru_ready(struct abituguru_data *data)
{
int timeout = ABIT_UGURU_READY_TIMEOUT;
if (data->uguru_ready)
return 0;
outb(0x00, data->addr + ABIT_UGURU_DATA);
if (abituguru_wait(data, ABIT_UGURU_STATUS_READY)) {
ABIT_UGURU_DEBUG(1,
"timeout exceeded waiting for ready state\n");
return -EIO;
}
while (inb_p(data->addr + ABIT_UGURU_CMD) != 0xAC) {
timeout--;
if (timeout == 0) {
ABIT_UGURU_DEBUG(1,
"CMD reg does not hold 0xAC after ready command\n");
return -EIO;
}
msleep(0);
}
timeout = ABIT_UGURU_READY_TIMEOUT;
while (inb_p(data->addr + ABIT_UGURU_DATA) != ABIT_UGURU_STATUS_INPUT) {
timeout--;
if (timeout == 0) {
ABIT_UGURU_DEBUG(1,
"state != more input after ready command\n");
return -EIO;
}
msleep(0);
}
data->uguru_ready = 1;
return 0;
}
static int abituguru_send_address(struct abituguru_data *data,
u8 bank_addr, u8 sensor_addr, int retries)
{
int report_errors = retries;
for (;;) {
if (abituguru_ready(data) != 0)
return -EIO;
outb(bank_addr, data->addr + ABIT_UGURU_DATA);
data->uguru_ready = 0;
if (abituguru_wait(data, ABIT_UGURU_STATUS_INPUT)) {
if (retries) {
ABIT_UGURU_DEBUG(3, "timeout exceeded "
"waiting for more input state, %d "
"tries remaining\n", retries);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(ABIT_UGURU_RETRY_DELAY);
retries--;
continue;
}
if (report_errors)
ABIT_UGURU_DEBUG(1, "timeout exceeded "
"waiting for more input state "
"(bank: %d)\n", (int)bank_addr);
return -EBUSY;
}
outb(sensor_addr, data->addr + ABIT_UGURU_CMD);
return 0;
}
}
static int abituguru_read(struct abituguru_data *data,
u8 bank_addr, u8 sensor_addr, u8 *buf, int count, int retries)
{
int i;
i = abituguru_send_address(data, bank_addr, sensor_addr, retries);
if (i)
return i;
for (i = 0; i < count; i++) {
if (abituguru_wait(data, ABIT_UGURU_STATUS_READ)) {
ABIT_UGURU_DEBUG(retries ? 1 : 3,
"timeout exceeded waiting for "
"read state (bank: %d, sensor: %d)\n",
(int)bank_addr, (int)sensor_addr);
break;
}
buf[i] = inb(data->addr + ABIT_UGURU_CMD);
}
abituguru_ready(data);
return i;
}
static int abituguru_write(struct abituguru_data *data,
u8 bank_addr, u8 sensor_addr, u8 *buf, int count)
{
int i, timeout = ABIT_UGURU_READY_TIMEOUT;
i = abituguru_send_address(data, bank_addr, sensor_addr,
ABIT_UGURU_MAX_RETRIES);
if (i)
return i;
for (i = 0; i < count; i++) {
if (abituguru_wait(data, ABIT_UGURU_STATUS_WRITE)) {
ABIT_UGURU_DEBUG(1, "timeout exceeded waiting for "
"write state (bank: %d, sensor: %d)\n",
(int)bank_addr, (int)sensor_addr);
break;
}
outb(buf[i], data->addr + ABIT_UGURU_CMD);
}
if (abituguru_wait(data, ABIT_UGURU_STATUS_READ)) {
ABIT_UGURU_DEBUG(1, "timeout exceeded waiting for read state "
"after write (bank: %d, sensor: %d)\n", (int)bank_addr,
(int)sensor_addr);
return -EIO;
}
while (inb_p(data->addr + ABIT_UGURU_CMD) != 0xAC) {
timeout--;
if (timeout == 0) {
ABIT_UGURU_DEBUG(1, "CMD reg does not hold 0xAC after "
"write (bank: %d, sensor: %d)\n",
(int)bank_addr, (int)sensor_addr);
return -EIO;
}
msleep(0);
}
abituguru_ready(data);
return i;
}
static int __devinit
abituguru_detect_bank1_sensor_type(struct abituguru_data *data,
u8 sensor_addr)
{
u8 val, test_flag, buf[3];
int i, ret = -ENODEV;
if (bank1_types[sensor_addr] >= ABIT_UGURU_IN_SENSOR &&
bank1_types[sensor_addr] <= ABIT_UGURU_NC) {
ABIT_UGURU_DEBUG(2, "assuming sensor type %d for bank1 sensor "
"%d because of \"bank1_types\" module param\n",
bank1_types[sensor_addr], (int)sensor_addr);
return bank1_types[sensor_addr];
}
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK1, sensor_addr, &val,
1, ABIT_UGURU_MAX_RETRIES) != 1)
return -ENODEV;
if ((val < 10u) || (val > 250u)) {
pr_warn("bank1-sensor: %d reading (%d) too close to limits, "
"unable to determine sensor type, skipping sensor\n",
(int)sensor_addr, (int)val);
return ABIT_UGURU_NC;
}
ABIT_UGURU_DEBUG(2, "testing bank1 sensor %d\n", (int)sensor_addr);
if (val <= 240u) {
buf[0] = ABIT_UGURU_VOLT_LOW_ALARM_ENABLE;
buf[1] = 245;
buf[2] = 250;
test_flag = ABIT_UGURU_VOLT_LOW_ALARM_FLAG;
} else {
buf[0] = ABIT_UGURU_VOLT_HIGH_ALARM_ENABLE;
buf[1] = 5;
buf[2] = 10;
test_flag = ABIT_UGURU_VOLT_HIGH_ALARM_FLAG;
}
if (abituguru_write(data, ABIT_UGURU_SENSOR_BANK1 + 2, sensor_addr,
buf, 3) != 3)
goto abituguru_detect_bank1_sensor_type_exit;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(HZ/50);
if (abituguru_read(data, ABIT_UGURU_ALARM_BANK, 0, buf, 3,
ABIT_UGURU_MAX_RETRIES) != 3)
goto abituguru_detect_bank1_sensor_type_exit;
if (buf[sensor_addr/8] & (0x01 << (sensor_addr % 8))) {
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK1 + 1,
sensor_addr, buf, 3,
ABIT_UGURU_MAX_RETRIES) != 3)
goto abituguru_detect_bank1_sensor_type_exit;
if (buf[0] & test_flag) {
ABIT_UGURU_DEBUG(2, " found volt sensor\n");
ret = ABIT_UGURU_IN_SENSOR;
goto abituguru_detect_bank1_sensor_type_exit;
} else
ABIT_UGURU_DEBUG(2, " alarm raised during volt "
"sensor test, but volt range flag not set\n");
} else
ABIT_UGURU_DEBUG(2, " alarm not raised during volt sensor "
"test\n");
buf[0] = ABIT_UGURU_TEMP_HIGH_ALARM_ENABLE;
buf[1] = 5;
buf[2] = 10;
if (abituguru_write(data, ABIT_UGURU_SENSOR_BANK1 + 2, sensor_addr,
buf, 3) != 3)
goto abituguru_detect_bank1_sensor_type_exit;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(HZ/20);
if (abituguru_read(data, ABIT_UGURU_ALARM_BANK, 0, buf, 3,
ABIT_UGURU_MAX_RETRIES) != 3)
goto abituguru_detect_bank1_sensor_type_exit;
if (buf[sensor_addr/8] & (0x01 << (sensor_addr % 8))) {
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK1 + 1,
sensor_addr, buf, 3,
ABIT_UGURU_MAX_RETRIES) != 3)
goto abituguru_detect_bank1_sensor_type_exit;
if (buf[0] & ABIT_UGURU_TEMP_HIGH_ALARM_FLAG) {
ABIT_UGURU_DEBUG(2, " found temp sensor\n");
ret = ABIT_UGURU_TEMP_SENSOR;
goto abituguru_detect_bank1_sensor_type_exit;
} else
ABIT_UGURU_DEBUG(2, " alarm raised during temp "
"sensor test, but temp high flag not set\n");
} else
ABIT_UGURU_DEBUG(2, " alarm not raised during temp sensor "
"test\n");
ret = ABIT_UGURU_NC;
abituguru_detect_bank1_sensor_type_exit:
for (i = 0; i < 3; i++)
if (abituguru_write(data, ABIT_UGURU_SENSOR_BANK1 + 2,
sensor_addr, data->bank1_settings[sensor_addr],
3) == 3)
break;
if (i == 3) {
pr_err("Fatal error could not restore original settings. %s %s\n",
never_happen, report_this);
return -ENODEV;
}
return ret;
}
static void __devinit
abituguru_detect_no_bank2_sensors(struct abituguru_data *data)
{
int i;
if (fan_sensors > 0 && fan_sensors <= ABIT_UGURU_MAX_BANK2_SENSORS) {
data->bank2_sensors = fan_sensors;
ABIT_UGURU_DEBUG(2, "assuming %d fan sensors because of "
"\"fan_sensors\" module param\n",
(int)data->bank2_sensors);
return;
}
ABIT_UGURU_DEBUG(2, "detecting number of fan sensors\n");
for (i = 0; i < ABIT_UGURU_MAX_BANK2_SENSORS; i++) {
if (data->bank2_settings[i][0] & ~0xC9) {
ABIT_UGURU_DEBUG(2, " bank2 sensor %d does not seem "
"to be a fan sensor: settings[0] = %02X\n",
i, (unsigned int)data->bank2_settings[i][0]);
break;
}
if (data->bank2_settings[i][1] <
abituguru_bank2_min_threshold) {
ABIT_UGURU_DEBUG(2, " bank2 sensor %d does not seem "
"to be a fan sensor: the threshold (%d) is "
"below the minimum (%d)\n", i,
(int)data->bank2_settings[i][1],
(int)abituguru_bank2_min_threshold);
break;
}
if (data->bank2_settings[i][1] >
abituguru_bank2_max_threshold) {
ABIT_UGURU_DEBUG(2, " bank2 sensor %d does not seem "
"to be a fan sensor: the threshold (%d) is "
"above the maximum (%d)\n", i,
(int)data->bank2_settings[i][1],
(int)abituguru_bank2_max_threshold);
break;
}
}
data->bank2_sensors = i;
ABIT_UGURU_DEBUG(2, " found: %d fan sensors\n",
(int)data->bank2_sensors);
}
static void __devinit
abituguru_detect_no_pwms(struct abituguru_data *data)
{
int i, j;
if (pwms > 0 && pwms <= ABIT_UGURU_MAX_PWMS) {
data->pwms = pwms;
ABIT_UGURU_DEBUG(2, "assuming %d PWM outputs because of "
"\"pwms\" module param\n", (int)data->pwms);
return;
}
ABIT_UGURU_DEBUG(2, "detecting number of PWM outputs\n");
for (i = 0; i < ABIT_UGURU_MAX_PWMS; i++) {
if (data->pwm_settings[i][0] & ~0x8F) {
ABIT_UGURU_DEBUG(2, " pwm channel %d does not seem "
"to be a pwm channel: settings[0] = %02X\n",
i, (unsigned int)data->pwm_settings[i][0]);
break;
}
for (j = 0; j < data->bank1_sensors[ABIT_UGURU_TEMP_SENSOR];
j++) {
if (data->bank1_address[ABIT_UGURU_TEMP_SENSOR][j] ==
(data->pwm_settings[i][0] & 0x0F))
break;
}
if (j == data->bank1_sensors[ABIT_UGURU_TEMP_SENSOR]) {
ABIT_UGURU_DEBUG(2, " pwm channel %d does not seem "
"to be a pwm channel: %d is not a valid temp "
"sensor address\n", i,
data->pwm_settings[i][0] & 0x0F);
break;
}
for (j = 1; j < 5; j++) {
u8 min;
if ((i == 0) && ((j == 1) || (j == 2)))
min = 77;
else
min = abituguru_pwm_min[j];
if (data->pwm_settings[i][j] < min) {
ABIT_UGURU_DEBUG(2, " pwm channel %d does "
"not seem to be a pwm channel: "
"setting %d (%d) is below the minimum "
"value (%d)\n", i, j,
(int)data->pwm_settings[i][j],
(int)min);
goto abituguru_detect_no_pwms_exit;
}
if (data->pwm_settings[i][j] > abituguru_pwm_max[j]) {
ABIT_UGURU_DEBUG(2, " pwm channel %d does "
"not seem to be a pwm channel: "
"setting %d (%d) is above the maximum "
"value (%d)\n", i, j,
(int)data->pwm_settings[i][j],
(int)abituguru_pwm_max[j]);
goto abituguru_detect_no_pwms_exit;
}
}
if (data->pwm_settings[i][1] >= data->pwm_settings[i][2]) {
ABIT_UGURU_DEBUG(2, " pwm channel %d does not seem "
"to be a pwm channel: min pwm (%d) >= "
"max pwm (%d)\n", i,
(int)data->pwm_settings[i][1],
(int)data->pwm_settings[i][2]);
break;
}
if (data->pwm_settings[i][3] >= data->pwm_settings[i][4]) {
ABIT_UGURU_DEBUG(2, " pwm channel %d does not seem "
"to be a pwm channel: min temp (%d) >= "
"max temp (%d)\n", i,
(int)data->pwm_settings[i][3],
(int)data->pwm_settings[i][4]);
break;
}
}
abituguru_detect_no_pwms_exit:
data->pwms = i;
ABIT_UGURU_DEBUG(2, " found: %d PWM outputs\n", (int)data->pwms);
}
static ssize_t show_bank1_value(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = abituguru_update_device(dev);
if (!data)
return -EIO;
return sprintf(buf, "%d\n", (data->bank1_value[attr->index] *
data->bank1_max_value[attr->index] + 128) / 255);
}
static ssize_t show_bank1_setting(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n",
(data->bank1_settings[attr->index][attr->nr] *
data->bank1_max_value[attr->index] + 128) / 255);
}
static ssize_t show_bank2_value(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = abituguru_update_device(dev);
if (!data)
return -EIO;
return sprintf(buf, "%d\n", (data->bank2_value[attr->index] *
ABIT_UGURU_FAN_MAX + 128) / 255);
}
static ssize_t show_bank2_setting(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n",
(data->bank2_settings[attr->index][attr->nr] *
ABIT_UGURU_FAN_MAX + 128) / 255);
}
static ssize_t store_bank1_setting(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
u8 val = (simple_strtoul(buf, NULL, 10) * 255 +
data->bank1_max_value[attr->index]/2) /
data->bank1_max_value[attr->index];
ssize_t ret = count;
mutex_lock(&data->update_lock);
if (data->bank1_settings[attr->index][attr->nr] != val) {
u8 orig_val = data->bank1_settings[attr->index][attr->nr];
data->bank1_settings[attr->index][attr->nr] = val;
if (abituguru_write(data, ABIT_UGURU_SENSOR_BANK1 + 2,
attr->index, data->bank1_settings[attr->index],
3) <= attr->nr) {
data->bank1_settings[attr->index][attr->nr] = orig_val;
ret = -EIO;
}
}
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t store_bank2_setting(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
u8 val = (simple_strtoul(buf, NULL, 10)*255 + ABIT_UGURU_FAN_MAX/2) /
ABIT_UGURU_FAN_MAX;
ssize_t ret = count;
if ((val < abituguru_bank2_min_threshold) ||
(val > abituguru_bank2_max_threshold))
return -EINVAL;
mutex_lock(&data->update_lock);
if (data->bank2_settings[attr->index][attr->nr] != val) {
u8 orig_val = data->bank2_settings[attr->index][attr->nr];
data->bank2_settings[attr->index][attr->nr] = val;
if (abituguru_write(data, ABIT_UGURU_SENSOR_BANK2 + 2,
attr->index, data->bank2_settings[attr->index],
2) <= attr->nr) {
data->bank2_settings[attr->index][attr->nr] = orig_val;
ret = -EIO;
}
}
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_bank1_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = abituguru_update_device(dev);
if (!data)
return -EIO;
if ((data->alarms[attr->index / 8] & (0x01 << (attr->index % 8))) &&
(data->bank1_settings[attr->index][0] & attr->nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_bank2_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = abituguru_update_device(dev);
if (!data)
return -EIO;
if (data->alarms[2] & (0x01 << attr->index))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_bank1_mask(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
if (data->bank1_settings[attr->index][0] & attr->nr)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_bank2_mask(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
if (data->bank2_settings[attr->index][0] & attr->nr)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t store_bank1_mask(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
int mask = simple_strtoul(buf, NULL, 10);
ssize_t ret = count;
u8 orig_val;
mutex_lock(&data->update_lock);
orig_val = data->bank1_settings[attr->index][0];
if (mask)
data->bank1_settings[attr->index][0] |= attr->nr;
else
data->bank1_settings[attr->index][0] &= ~attr->nr;
if ((data->bank1_settings[attr->index][0] != orig_val) &&
(abituguru_write(data,
ABIT_UGURU_SENSOR_BANK1 + 2, attr->index,
data->bank1_settings[attr->index], 3) < 1)) {
data->bank1_settings[attr->index][0] = orig_val;
ret = -EIO;
}
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t store_bank2_mask(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
int mask = simple_strtoul(buf, NULL, 10);
ssize_t ret = count;
u8 orig_val;
mutex_lock(&data->update_lock);
orig_val = data->bank2_settings[attr->index][0];
if (mask)
data->bank2_settings[attr->index][0] |= attr->nr;
else
data->bank2_settings[attr->index][0] &= ~attr->nr;
if ((data->bank2_settings[attr->index][0] != orig_val) &&
(abituguru_write(data,
ABIT_UGURU_SENSOR_BANK2 + 2, attr->index,
data->bank2_settings[attr->index], 2) < 1)) {
data->bank2_settings[attr->index][0] = orig_val;
ret = -EIO;
}
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_pwm_setting(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->pwm_settings[attr->index][attr->nr] *
abituguru_pwm_settings_multiplier[attr->nr]);
}
static ssize_t store_pwm_setting(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
u8 min, val = (simple_strtoul(buf, NULL, 10) +
abituguru_pwm_settings_multiplier[attr->nr]/2) /
abituguru_pwm_settings_multiplier[attr->nr];
ssize_t ret = count;
if ((attr->index == 0) && ((attr->nr == 1) || (attr->nr == 2)))
min = 77;
else
min = abituguru_pwm_min[attr->nr];
if ((val < min) || (val > abituguru_pwm_max[attr->nr]))
return -EINVAL;
mutex_lock(&data->update_lock);
if ((attr->nr & 1) &&
(val >= data->pwm_settings[attr->index][attr->nr + 1]))
ret = -EINVAL;
else if (!(attr->nr & 1) &&
(val <= data->pwm_settings[attr->index][attr->nr - 1]))
ret = -EINVAL;
else if (data->pwm_settings[attr->index][attr->nr] != val) {
u8 orig_val = data->pwm_settings[attr->index][attr->nr];
data->pwm_settings[attr->index][attr->nr] = val;
if (abituguru_write(data, ABIT_UGURU_FAN_PWM + 1,
attr->index, data->pwm_settings[attr->index],
5) <= attr->nr) {
data->pwm_settings[attr->index][attr->nr] =
orig_val;
ret = -EIO;
}
}
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_pwm_sensor(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
int i;
for (i = 0; i < data->bank1_sensors[ABIT_UGURU_TEMP_SENSOR]; i++)
if (data->bank1_address[ABIT_UGURU_TEMP_SENSOR][i] ==
(data->pwm_settings[attr->index][0] & 0x0F))
return sprintf(buf, "%d\n", i+1);
return -ENXIO;
}
static ssize_t store_pwm_sensor(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
unsigned long val = simple_strtoul(buf, NULL, 10) - 1;
ssize_t ret = count;
mutex_lock(&data->update_lock);
if (val < data->bank1_sensors[ABIT_UGURU_TEMP_SENSOR]) {
u8 orig_val = data->pwm_settings[attr->index][0];
u8 address = data->bank1_address[ABIT_UGURU_TEMP_SENSOR][val];
data->pwm_settings[attr->index][0] &= 0xF0;
data->pwm_settings[attr->index][0] |= address;
if (data->pwm_settings[attr->index][0] != orig_val) {
if (abituguru_write(data, ABIT_UGURU_FAN_PWM + 1,
attr->index,
data->pwm_settings[attr->index],
5) < 1) {
data->pwm_settings[attr->index][0] = orig_val;
ret = -EIO;
}
}
}
else
ret = -EINVAL;
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
int res = 0;
if (data->pwm_settings[attr->index][0] & ABIT_UGURU_FAN_PWM_ENABLE)
res = 2;
return sprintf(buf, "%d\n", res);
}
static ssize_t store_pwm_enable(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct abituguru_data *data = dev_get_drvdata(dev);
u8 orig_val, user_val = simple_strtoul(buf, NULL, 10);
ssize_t ret = count;
mutex_lock(&data->update_lock);
orig_val = data->pwm_settings[attr->index][0];
switch (user_val) {
case 0:
data->pwm_settings[attr->index][0] &=
~ABIT_UGURU_FAN_PWM_ENABLE;
break;
case 2:
data->pwm_settings[attr->index][0] |=
ABIT_UGURU_FAN_PWM_ENABLE;
break;
default:
ret = -EINVAL;
}
if ((data->pwm_settings[attr->index][0] != orig_val) &&
(abituguru_write(data, ABIT_UGURU_FAN_PWM + 1,
attr->index, data->pwm_settings[attr->index],
5) < 1)) {
data->pwm_settings[attr->index][0] = orig_val;
ret = -EIO;
}
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_name(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "%s\n", ABIT_UGURU_NAME);
}
static int __devinit abituguru_probe(struct platform_device *pdev)
{
struct abituguru_data *data;
int i, j, used, sysfs_names_free, sysfs_attr_i, res = -ENODEV;
char *sysfs_filename;
const u8 probe_order[ABIT_UGURU_MAX_BANK1_SENSORS] = {
0x00, 0x01, 0x03, 0x04, 0x0A, 0x08, 0x0E, 0x02,
0x09, 0x06, 0x05, 0x0B, 0x0F, 0x0D, 0x07, 0x0C };
if (!(data = kzalloc(sizeof(struct abituguru_data), GFP_KERNEL)))
return -ENOMEM;
data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
if (inb_p(data->addr + ABIT_UGURU_DATA) == ABIT_UGURU_STATUS_INPUT)
data->uguru_ready = 1;
if (abituguru_read(data, ABIT_UGURU_ALARM_BANK, 0,
data->alarms, 3, ABIT_UGURU_MAX_RETRIES) != 3)
goto abituguru_probe_error;
for (i = 0; i < ABIT_UGURU_MAX_BANK1_SENSORS; i++) {
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK1, i,
&data->bank1_value[i], 1,
ABIT_UGURU_MAX_RETRIES) != 1)
goto abituguru_probe_error;
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK1+1, i,
data->bank1_settings[i], 3,
ABIT_UGURU_MAX_RETRIES) != 3)
goto abituguru_probe_error;
}
for (i = 0; i < ABIT_UGURU_MAX_BANK2_SENSORS; i++) {
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK2, i,
&data->bank2_value[i], 1,
ABIT_UGURU_MAX_RETRIES) != 1)
goto abituguru_probe_error;
if (abituguru_read(data, ABIT_UGURU_SENSOR_BANK2+1, i,
data->bank2_settings[i], 2,
ABIT_UGURU_MAX_RETRIES) != 2)
goto abituguru_probe_error;
}
for (i = 0; i < ABIT_UGURU_MAX_PWMS; i++) {
if (abituguru_read(data, ABIT_UGURU_FAN_PWM, i,
data->pwm_settings[i], 5,
ABIT_UGURU_MAX_RETRIES) != 5)
goto abituguru_probe_error;
}
data->last_updated = jiffies;
sysfs_attr_i = 0;
sysfs_filename = data->sysfs_names;
sysfs_names_free = ABITUGURU_SYSFS_NAMES_LENGTH;
for (i = 0; i < ABIT_UGURU_MAX_BANK1_SENSORS; i++) {
res = abituguru_detect_bank1_sensor_type(data, probe_order[i]);
if (res < 0)
goto abituguru_probe_error;
if (res == ABIT_UGURU_NC)
continue;
for (j = 0; j < (res ? 7 : 9); j++) {
used = snprintf(sysfs_filename, sysfs_names_free,
abituguru_sysfs_bank1_templ[res][j].dev_attr.
attr.name, data->bank1_sensors[res] + res)
+ 1;
data->sysfs_attr[sysfs_attr_i] =
abituguru_sysfs_bank1_templ[res][j];
data->sysfs_attr[sysfs_attr_i].dev_attr.attr.name =
sysfs_filename;
data->sysfs_attr[sysfs_attr_i].index = probe_order[i];
sysfs_filename += used;
sysfs_names_free -= used;
sysfs_attr_i++;
}
data->bank1_max_value[probe_order[i]] =
abituguru_bank1_max_value[res];
data->bank1_address[res][data->bank1_sensors[res]] =
probe_order[i];
data->bank1_sensors[res]++;
}
abituguru_detect_no_bank2_sensors(data);
for (i = 0; i < data->bank2_sensors; i++) {
for (j = 0; j < ARRAY_SIZE(abituguru_sysfs_fan_templ); j++) {
used = snprintf(sysfs_filename, sysfs_names_free,
abituguru_sysfs_fan_templ[j].dev_attr.attr.name,
i + 1) + 1;
data->sysfs_attr[sysfs_attr_i] =
abituguru_sysfs_fan_templ[j];
data->sysfs_attr[sysfs_attr_i].dev_attr.attr.name =
sysfs_filename;
data->sysfs_attr[sysfs_attr_i].index = i;
sysfs_filename += used;
sysfs_names_free -= used;
sysfs_attr_i++;
}
}
abituguru_detect_no_pwms(data);
for (i = 0; i < data->pwms; i++) {
for (j = 0; j < ARRAY_SIZE(abituguru_sysfs_pwm_templ); j++) {
used = snprintf(sysfs_filename, sysfs_names_free,
abituguru_sysfs_pwm_templ[j].dev_attr.attr.name,
i + 1) + 1;
data->sysfs_attr[sysfs_attr_i] =
abituguru_sysfs_pwm_templ[j];
data->sysfs_attr[sysfs_attr_i].dev_attr.attr.name =
sysfs_filename;
data->sysfs_attr[sysfs_attr_i].index = i;
sysfs_filename += used;
sysfs_names_free -= used;
sysfs_attr_i++;
}
}
if (sysfs_names_free < 0) {
pr_err("Fatal error ran out of space for sysfs attr names. %s %s",
never_happen, report_this);
res = -ENAMETOOLONG;
goto abituguru_probe_error;
}
pr_info("found Abit uGuru\n");
for (i = 0; i < sysfs_attr_i; i++)
if (device_create_file(&pdev->dev,
&data->sysfs_attr[i].dev_attr))
goto abituguru_probe_error;
for (i = 0; i < ARRAY_SIZE(abituguru_sysfs_attr); i++)
if (device_create_file(&pdev->dev,
&abituguru_sysfs_attr[i].dev_attr))
goto abituguru_probe_error;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (!IS_ERR(data->hwmon_dev))
return 0;
res = PTR_ERR(data->hwmon_dev);
abituguru_probe_error:
for (i = 0; data->sysfs_attr[i].dev_attr.attr.name; i++)
device_remove_file(&pdev->dev, &data->sysfs_attr[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(abituguru_sysfs_attr); i++)
device_remove_file(&pdev->dev,
&abituguru_sysfs_attr[i].dev_attr);
platform_set_drvdata(pdev, NULL);
kfree(data);
return res;
}
static int __devexit abituguru_remove(struct platform_device *pdev)
{
int i;
struct abituguru_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
for (i = 0; data->sysfs_attr[i].dev_attr.attr.name; i++)
device_remove_file(&pdev->dev, &data->sysfs_attr[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(abituguru_sysfs_attr); i++)
device_remove_file(&pdev->dev,
&abituguru_sysfs_attr[i].dev_attr);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static struct abituguru_data *abituguru_update_device(struct device *dev)
{
int i, err;
struct abituguru_data *data = dev_get_drvdata(dev);
char success = 1;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ)) {
success = 0;
if ((err = abituguru_read(data, ABIT_UGURU_ALARM_BANK, 0,
data->alarms, 3, 0)) != 3)
goto LEAVE_UPDATE;
for (i = 0; i < ABIT_UGURU_MAX_BANK1_SENSORS; i++) {
if ((err = abituguru_read(data,
ABIT_UGURU_SENSOR_BANK1, i,
&data->bank1_value[i], 1, 0)) != 1)
goto LEAVE_UPDATE;
if ((err = abituguru_read(data,
ABIT_UGURU_SENSOR_BANK1 + 1, i,
data->bank1_settings[i], 3, 0)) != 3)
goto LEAVE_UPDATE;
}
for (i = 0; i < data->bank2_sensors; i++)
if ((err = abituguru_read(data,
ABIT_UGURU_SENSOR_BANK2, i,
&data->bank2_value[i], 1, 0)) != 1)
goto LEAVE_UPDATE;
success = 1;
data->update_timeouts = 0;
LEAVE_UPDATE:
if (!success && (err == -EBUSY || err >= 0)) {
if (data->update_timeouts < 255u)
data->update_timeouts++;
if (data->update_timeouts <= ABIT_UGURU_MAX_TIMEOUTS) {
ABIT_UGURU_DEBUG(3, "timeout exceeded, will "
"try again next update\n");
success = 1;
} else
ABIT_UGURU_DEBUG(1, "timeout exceeded %d "
"times waiting for more input state\n",
(int)data->update_timeouts);
}
if (success)
data->last_updated = jiffies;
}
mutex_unlock(&data->update_lock);
if (success)
return data;
else
return NULL;
}
static int abituguru_suspend(struct platform_device *pdev, pm_message_t state)
{
struct abituguru_data *data = platform_get_drvdata(pdev);
mutex_lock(&data->update_lock);
return 0;
}
static int abituguru_resume(struct platform_device *pdev)
{
struct abituguru_data *data = platform_get_drvdata(pdev);
if (inb_p(data->addr + ABIT_UGURU_DATA) != ABIT_UGURU_STATUS_INPUT)
data->uguru_ready = 0;
mutex_unlock(&data->update_lock);
return 0;
}
static int __init abituguru_detect(void)
{
u8 cmd_val = inb_p(ABIT_UGURU_BASE + ABIT_UGURU_CMD);
u8 data_val = inb_p(ABIT_UGURU_BASE + ABIT_UGURU_DATA);
if (((data_val == 0x00) || (data_val == 0x08)) &&
((cmd_val == 0x00) || (cmd_val == 0xAC)))
return ABIT_UGURU_BASE;
ABIT_UGURU_DEBUG(2, "no Abit uGuru found, data = 0x%02X, cmd = "
"0x%02X\n", (unsigned int)data_val, (unsigned int)cmd_val);
if (force) {
pr_info("Assuming Abit uGuru is present because of \"force\" parameter\n");
return ABIT_UGURU_BASE;
}
return -ENODEV;
}
static int __init abituguru_init(void)
{
int address, err;
struct resource res = { .flags = IORESOURCE_IO };
const char *board_vendor = dmi_get_system_info(DMI_BOARD_VENDOR);
if (!force && (!board_vendor ||
strcmp(board_vendor, "http://www.abit.com.tw/")))
return -ENODEV;
address = abituguru_detect();
if (address < 0)
return address;
err = platform_driver_register(&abituguru_driver);
if (err)
goto exit;
abituguru_pdev = platform_device_alloc(ABIT_UGURU_NAME, address);
if (!abituguru_pdev) {
pr_err("Device allocation failed\n");
err = -ENOMEM;
goto exit_driver_unregister;
}
res.start = address;
res.end = address + ABIT_UGURU_REGION_LENGTH - 1;
res.name = ABIT_UGURU_NAME;
err = platform_device_add_resources(abituguru_pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add(abituguru_pdev);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(abituguru_pdev);
exit_driver_unregister:
platform_driver_unregister(&abituguru_driver);
exit:
return err;
}
static void __exit abituguru_exit(void)
{
platform_device_unregister(abituguru_pdev);
platform_driver_unregister(&abituguru_driver);
}
