static u8 sht15_reverse(u8 byte)
{
u8 i, c;
for (c = 0, i = 0; i < 8; i++)
c |= (!!(byte & (1 << i))) << (7 - i);
return c;
}
static u8 sht15_crc8(struct sht15_data *data,
const u8 *value,
int len)
{
u8 crc = sht15_reverse(data->val_status & 0x0F);
while (len--) {
crc = sht15_crc8_table[*value ^ crc];
value++;
}
return crc;
}
static void sht15_connection_reset(struct sht15_data *data)
{
int i;
gpio_direction_output(data->pdata->gpio_data, 1);
ndelay(SHT15_TSCKL);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
for (i = 0; i < 9; ++i) {
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
}
}
static inline void sht15_send_bit(struct sht15_data *data, int val)
{
gpio_set_value(data->pdata->gpio_data, val);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
}
static void sht15_transmission_start(struct sht15_data *data)
{
gpio_direction_output(data->pdata->gpio_data, 1);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
gpio_set_value(data->pdata->gpio_data, 0);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
gpio_set_value(data->pdata->gpio_data, 1);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
}
static void sht15_send_byte(struct sht15_data *data, u8 byte)
{
int i;
for (i = 0; i < 8; i++) {
sht15_send_bit(data, !!(byte & 0x80));
byte <<= 1;
}
}
static int sht15_wait_for_response(struct sht15_data *data)
{
gpio_direction_input(data->pdata->gpio_data);
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
if (gpio_get_value(data->pdata->gpio_data)) {
gpio_set_value(data->pdata->gpio_sck, 0);
dev_err(data->dev, "Command not acknowledged\n");
sht15_connection_reset(data);
return -EIO;
}
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
return 0;
}
static int sht15_send_cmd(struct sht15_data *data, u8 cmd)
{
int ret = 0;
sht15_transmission_start(data);
sht15_send_byte(data, cmd);
ret = sht15_wait_for_response(data);
return ret;
}
static int sht15_soft_reset(struct sht15_data *data)
{
int ret;
ret = sht15_send_cmd(data, SHT15_SOFT_RESET);
if (ret)
return ret;
msleep(SHT15_TSRST);
data->val_status = 0;
return ret;
}
static void sht15_ack(struct sht15_data *data)
{
gpio_direction_output(data->pdata->gpio_data, 0);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_data, 1);
gpio_direction_input(data->pdata->gpio_data);
}
static void sht15_end_transmission(struct sht15_data *data)
{
gpio_direction_output(data->pdata->gpio_data, 1);
ndelay(SHT15_TSU);
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
}
static u8 sht15_read_byte(struct sht15_data *data)
{
int i;
u8 byte = 0;
for (i = 0; i < 8; ++i) {
byte <<= 1;
gpio_set_value(data->pdata->gpio_sck, 1);
ndelay(SHT15_TSCKH);
byte |= !!gpio_get_value(data->pdata->gpio_data);
gpio_set_value(data->pdata->gpio_sck, 0);
ndelay(SHT15_TSCKL);
}
return byte;
}
static int sht15_send_status(struct sht15_data *data, u8 status)
{
int ret;
ret = sht15_send_cmd(data, SHT15_WRITE_STATUS);
if (ret)
return ret;
gpio_direction_output(data->pdata->gpio_data, 1);
ndelay(SHT15_TSU);
sht15_send_byte(data, status);
ret = sht15_wait_for_response(data);
if (ret)
return ret;
data->val_status = status;
return 0;
}
static int sht15_update_status(struct sht15_data *data)
{
int ret = 0;
u8 status;
u8 previous_config;
u8 dev_checksum = 0;
u8 checksum_vals[2];
int timeout = HZ;
mutex_lock(&data->read_lock);
if (time_after(jiffies, data->last_status + timeout)
|| !data->status_valid) {
ret = sht15_send_cmd(data, SHT15_READ_STATUS);
if (ret)
goto error_ret;
status = sht15_read_byte(data);
if (data->checksumming) {
sht15_ack(data);
dev_checksum = sht15_reverse(sht15_read_byte(data));
checksum_vals[0] = SHT15_READ_STATUS;
checksum_vals[1] = status;
data->checksum_ok = (sht15_crc8(data, checksum_vals, 2)
== dev_checksum);
}
sht15_end_transmission(data);
if (data->checksumming && !data->checksum_ok) {
previous_config = data->val_status & 0x07;
ret = sht15_soft_reset(data);
if (ret)
goto error_ret;
if (previous_config) {
ret = sht15_send_status(data, previous_config);
if (ret) {
dev_err(data->dev,
"CRC validation failed, unable "
"to restore device settings\n");
goto error_ret;
}
}
ret = -EAGAIN;
goto error_ret;
}
data->val_status = status;
data->status_valid = true;
data->last_status = jiffies;
}
error_ret:
mutex_unlock(&data->read_lock);
return ret;
}
static int sht15_measurement(struct sht15_data *data,
int command,
int timeout_msecs)
{
int ret;
u8 previous_config;
ret = sht15_send_cmd(data, command);
if (ret)
return ret;
gpio_direction_input(data->pdata->gpio_data);
atomic_set(&data->interrupt_handled, 0);
enable_irq(gpio_to_irq(data->pdata->gpio_data));
if (gpio_get_value(data->pdata->gpio_data) == 0) {
disable_irq_nosync(gpio_to_irq(data->pdata->gpio_data));
if (!atomic_read(&data->interrupt_handled))
schedule_work(&data->read_work);
}
ret = wait_event_timeout(data->wait_queue,
(data->state == SHT15_READING_NOTHING),
msecs_to_jiffies(timeout_msecs));
if (ret == 0) {
disable_irq_nosync(gpio_to_irq(data->pdata->gpio_data));
sht15_connection_reset(data);
return -ETIME;
}
if (data->checksumming && !data->checksum_ok) {
previous_config = data->val_status & 0x07;
ret = sht15_soft_reset(data);
if (ret)
return ret;
if (previous_config) {
ret = sht15_send_status(data, previous_config);
if (ret) {
dev_err(data->dev,
"CRC validation failed, unable "
"to restore device settings\n");
return ret;
}
}
return -EAGAIN;
}
return 0;
}
static int sht15_update_measurements(struct sht15_data *data)
{
int ret = 0;
int timeout = HZ;
mutex_lock(&data->read_lock);
if (time_after(jiffies, data->last_measurement + timeout)
|| !data->measurements_valid) {
data->state = SHT15_READING_HUMID;
ret = sht15_measurement(data, SHT15_MEASURE_RH, 160);
if (ret)
goto error_ret;
data->state = SHT15_READING_TEMP;
ret = sht15_measurement(data, SHT15_MEASURE_TEMP, 400);
if (ret)
goto error_ret;
data->measurements_valid = true;
data->last_measurement = jiffies;
}
error_ret:
mutex_unlock(&data->read_lock);
return ret;
}
static inline int sht15_calc_temp(struct sht15_data *data)
{
int d1 = temppoints[0].d1;
int d2 = (data->val_status & SHT15_STATUS_LOW_RESOLUTION) ? 40 : 10;
int i;
for (i = ARRAY_SIZE(temppoints) - 1; i > 0; i--)
if (data->supply_uV > temppoints[i - 1].vdd) {
d1 = (data->supply_uV - temppoints[i - 1].vdd)
* (temppoints[i].d1 - temppoints[i - 1].d1)
/ (temppoints[i].vdd - temppoints[i - 1].vdd)
+ temppoints[i - 1].d1;
break;
}
return data->val_temp * d2 + d1;
}
static inline int sht15_calc_humid(struct sht15_data *data)
{
int rh_linear;
int temp = sht15_calc_temp(data);
int c2, c3;
int t2;
const int c1 = -4;
if (data->val_status & SHT15_STATUS_LOW_RESOLUTION) {
c2 = 648000;
c3 = -7200;
t2 = 1280;
} else {
c2 = 40500;
c3 = -28;
t2 = 80;
}
rh_linear = c1 * 1000
+ c2 * data->val_humid / 1000
+ (data->val_humid * data->val_humid * c3) / 10000;
return (temp - 25000) * (10000 + t2 * data->val_humid)
/ 1000000 + rh_linear;
}
static ssize_t sht15_show_status(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
struct sht15_data *data = dev_get_drvdata(dev);
u8 bit = to_sensor_dev_attr(attr)->index;
ret = sht15_update_status(data);
return ret ? ret : sprintf(buf, "%d\n", !!(data->val_status & bit));
}
static ssize_t sht15_store_heater(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
struct sht15_data *data = dev_get_drvdata(dev);
long value;
u8 status;
if (kstrtol(buf, 10, &value))
return -EINVAL;
mutex_lock(&data->read_lock);
status = data->val_status & 0x07;
if (!!value)
status |= SHT15_STATUS_HEATER;
else
status &= ~SHT15_STATUS_HEATER;
ret = sht15_send_status(data, status);
mutex_unlock(&data->read_lock);
return ret ? ret : count;
}
static ssize_t sht15_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
struct sht15_data *data = dev_get_drvdata(dev);
ret = sht15_update_measurements(data);
return ret ? ret : sprintf(buf, "%d\n",
sht15_calc_temp(data));
}
static ssize_t sht15_show_humidity(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int ret;
struct sht15_data *data = dev_get_drvdata(dev);
ret = sht15_update_measurements(data);
return ret ? ret : sprintf(buf, "%d\n", sht15_calc_humid(data));
}
static ssize_t show_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
return sprintf(buf, "%s\n", pdev->name);
}
static irqreturn_t sht15_interrupt_fired(int irq, void *d)
{
struct sht15_data *data = d;
disable_irq_nosync(irq);
atomic_inc(&data->interrupt_handled);
if (data->state != SHT15_READING_NOTHING)
schedule_work(&data->read_work);
return IRQ_HANDLED;
}
static void sht15_bh_read_data(struct work_struct *work_s)
{
uint16_t val = 0;
u8 dev_checksum = 0;
u8 checksum_vals[3];
struct sht15_data *data
= container_of(work_s, struct sht15_data,
read_work);
if (gpio_get_value(data->pdata->gpio_data)) {
atomic_set(&data->interrupt_handled, 0);
enable_irq(gpio_to_irq(data->pdata->gpio_data));
if (gpio_get_value(data->pdata->gpio_data)
|| atomic_read(&data->interrupt_handled))
return;
}
val = sht15_read_byte(data);
val <<= 8;
sht15_ack(data);
val |= sht15_read_byte(data);
if (data->checksumming) {
sht15_ack(data);
dev_checksum = sht15_reverse(sht15_read_byte(data));
checksum_vals[0] = (data->state == SHT15_READING_TEMP) ?
SHT15_MEASURE_TEMP : SHT15_MEASURE_RH;
checksum_vals[1] = (u8) (val >> 8);
checksum_vals[2] = (u8) val;
data->checksum_ok
= (sht15_crc8(data, checksum_vals, 3) == dev_checksum);
}
sht15_end_transmission(data);
switch (data->state) {
case SHT15_READING_TEMP:
data->val_temp = val;
break;
case SHT15_READING_HUMID:
data->val_humid = val;
break;
default:
break;
}
data->state = SHT15_READING_NOTHING;
wake_up(&data->wait_queue);
}
static void sht15_update_voltage(struct work_struct *work_s)
{
struct sht15_data *data
= container_of(work_s, struct sht15_data,
update_supply_work);
data->supply_uV = regulator_get_voltage(data->reg);
}
static int sht15_invalidate_voltage(struct notifier_block *nb,
unsigned long event,
void *ignored)
{
struct sht15_data *data = container_of(nb, struct sht15_data, nb);
if (event == REGULATOR_EVENT_VOLTAGE_CHANGE)
data->supply_uV_valid = false;
schedule_work(&data->update_supply_work);
return NOTIFY_OK;
}
static int sht15_probe(struct platform_device *pdev)
{
int ret;
struct sht15_data *data;
u8 status = 0;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
INIT_WORK(&data->read_work, sht15_bh_read_data);
INIT_WORK(&data->update_supply_work, sht15_update_voltage);
platform_set_drvdata(pdev, data);
mutex_init(&data->read_lock);
data->dev = &pdev->dev;
init_waitqueue_head(&data->wait_queue);
if (pdev->dev.platform_data == NULL) {
dev_err(&pdev->dev, "no platform data supplied\n");
return -EINVAL;
}
data->pdata = pdev->dev.platform_data;
data->supply_uV = data->pdata->supply_mv * 1000;
if (data->pdata->checksum)
data->checksumming = true;
if (data->pdata->no_otp_reload)
status |= SHT15_STATUS_NO_OTP_RELOAD;
if (data->pdata->low_resolution)
status |= SHT15_STATUS_LOW_RESOLUTION;
data->reg = devm_regulator_get(data->dev, "vcc");
if (!IS_ERR(data->reg)) {
int voltage;
voltage = regulator_get_voltage(data->reg);
if (voltage)
data->supply_uV = voltage;
regulator_enable(data->reg);
data->nb.notifier_call = &sht15_invalidate_voltage;
ret = regulator_register_notifier(data->reg, &data->nb);
if (ret) {
dev_err(&pdev->dev,
"regulator notifier request failed\n");
regulator_disable(data->reg);
return ret;
}
}
ret = devm_gpio_request(&pdev->dev, data->pdata->gpio_sck, "SHT15 sck");
if (ret) {
dev_err(&pdev->dev, "gpio request failed\n");
goto err_release_reg;
}
gpio_direction_output(data->pdata->gpio_sck, 0);
ret = devm_gpio_request(&pdev->dev, data->pdata->gpio_data,
"SHT15 data");
if (ret) {
dev_err(&pdev->dev, "gpio request failed\n");
goto err_release_reg;
}
ret = devm_request_irq(&pdev->dev, gpio_to_irq(data->pdata->gpio_data),
sht15_interrupt_fired,
IRQF_TRIGGER_FALLING,
"sht15 data",
data);
if (ret) {
dev_err(&pdev->dev, "failed to get irq for data line\n");
goto err_release_reg;
}
disable_irq_nosync(gpio_to_irq(data->pdata->gpio_data));
sht15_connection_reset(data);
ret = sht15_soft_reset(data);
if (ret)
goto err_release_reg;
if (status) {
ret = sht15_send_status(data, status);
if (ret)
goto err_release_reg;
}
ret = sysfs_create_group(&pdev->dev.kobj, &sht15_attr_group);
if (ret) {
dev_err(&pdev->dev, "sysfs create failed\n");
goto err_release_reg;
}
data->hwmon_dev = hwmon_device_register(data->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto err_release_sysfs_group;
}
return 0;
err_release_sysfs_group:
sysfs_remove_group(&pdev->dev.kobj, &sht15_attr_group);
err_release_reg:
if (!IS_ERR(data->reg)) {
regulator_unregister_notifier(data->reg, &data->nb);
regulator_disable(data->reg);
}
return ret;
}
static int sht15_remove(struct platform_device *pdev)
{
struct sht15_data *data = platform_get_drvdata(pdev);
mutex_lock(&data->read_lock);
if (sht15_soft_reset(data)) {
mutex_unlock(&data->read_lock);
return -EFAULT;
}
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &sht15_attr_group);
if (!IS_ERR(data->reg)) {
regulator_unregister_notifier(data->reg, &data->nb);
regulator_disable(data->reg);
}
mutex_unlock(&data->read_lock);
return 0;
}
