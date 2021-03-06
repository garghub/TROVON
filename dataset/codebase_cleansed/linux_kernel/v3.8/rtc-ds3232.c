static int ds3232_check_rtc_status(struct i2c_client *client)
{
int ret = 0;
int control, stat;
stat = i2c_smbus_read_byte_data(client, DS3232_REG_SR);
if (stat < 0)
return stat;
if (stat & DS3232_REG_SR_OSF)
dev_warn(&client->dev,
"oscillator discontinuity flagged, "
"time unreliable\n");
stat &= ~(DS3232_REG_SR_OSF | DS3232_REG_SR_A1F | DS3232_REG_SR_A2F);
ret = i2c_smbus_write_byte_data(client, DS3232_REG_SR, stat);
if (ret < 0)
return ret;
control = i2c_smbus_read_byte_data(client, DS3232_REG_CR);
if (control < 0)
return control;
control &= ~(DS3232_REG_CR_A1IE | DS3232_REG_CR_A2IE);
control |= DS3232_REG_CR_INTCN;
return i2c_smbus_write_byte_data(client, DS3232_REG_CR, control);
}
static int ds3232_read_time(struct device *dev, struct rtc_time *time)
{
struct i2c_client *client = to_i2c_client(dev);
int ret;
u8 buf[7];
unsigned int year, month, day, hour, minute, second;
unsigned int week, twelve_hr, am_pm;
unsigned int century, add_century = 0;
ret = i2c_smbus_read_i2c_block_data(client, DS3232_REG_SECONDS, 7, buf);
if (ret < 0)
return ret;
if (ret < 7)
return -EIO;
second = buf[0];
minute = buf[1];
hour = buf[2];
week = buf[3];
day = buf[4];
month = buf[5];
year = buf[6];
twelve_hr = hour & 0x40;
am_pm = hour & 0x20;
century = month & 0x80;
time->tm_sec = bcd2bin(second);
time->tm_min = bcd2bin(minute);
if (twelve_hr) {
if (am_pm)
time->tm_hour = bcd2bin(hour & 0x1F) + 12;
else
time->tm_hour = bcd2bin(hour & 0x1F);
} else {
time->tm_hour = bcd2bin(hour);
}
time->tm_wday = bcd2bin(week) - 1;
time->tm_mday = bcd2bin(day);
time->tm_mon = bcd2bin(month & 0x7F) - 1;
if (century)
add_century = 100;
time->tm_year = bcd2bin(year) + add_century;
return rtc_valid_tm(time);
}
static int ds3232_set_time(struct device *dev, struct rtc_time *time)
{
struct i2c_client *client = to_i2c_client(dev);
u8 buf[7];
buf[0] = bin2bcd(time->tm_sec);
buf[1] = bin2bcd(time->tm_min);
buf[2] = bin2bcd(time->tm_hour);
buf[3] = bin2bcd(time->tm_wday + 1);
buf[4] = bin2bcd(time->tm_mday);
buf[5] = bin2bcd(time->tm_mon + 1);
if (time->tm_year >= 100) {
buf[5] |= 0x80;
buf[6] = bin2bcd(time->tm_year - 100);
} else {
buf[6] = bin2bcd(time->tm_year);
}
return i2c_smbus_write_i2c_block_data(client,
DS3232_REG_SECONDS, 7, buf);
}
static int ds3232_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds3232 *ds3232 = i2c_get_clientdata(client);
int control, stat;
int ret;
u8 buf[4];
mutex_lock(&ds3232->mutex);
ret = i2c_smbus_read_byte_data(client, DS3232_REG_SR);
if (ret < 0)
goto out;
stat = ret;
ret = i2c_smbus_read_byte_data(client, DS3232_REG_CR);
if (ret < 0)
goto out;
control = ret;
ret = i2c_smbus_read_i2c_block_data(client, DS3232_REG_ALARM1, 4, buf);
if (ret < 0)
goto out;
alarm->time.tm_sec = bcd2bin(buf[0] & 0x7F);
alarm->time.tm_min = bcd2bin(buf[1] & 0x7F);
alarm->time.tm_hour = bcd2bin(buf[2] & 0x7F);
alarm->time.tm_mday = bcd2bin(buf[3] & 0x7F);
alarm->time.tm_mon = -1;
alarm->time.tm_year = -1;
alarm->time.tm_wday = -1;
alarm->time.tm_yday = -1;
alarm->time.tm_isdst = -1;
alarm->enabled = !!(control & DS3232_REG_CR_A1IE);
alarm->pending = !!(stat & DS3232_REG_SR_A1F);
ret = 0;
out:
mutex_unlock(&ds3232->mutex);
return ret;
}
static int ds3232_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds3232 *ds3232 = i2c_get_clientdata(client);
int control, stat;
int ret;
u8 buf[4];
if (client->irq <= 0)
return -EINVAL;
mutex_lock(&ds3232->mutex);
buf[0] = bin2bcd(alarm->time.tm_sec);
buf[1] = bin2bcd(alarm->time.tm_min);
buf[2] = bin2bcd(alarm->time.tm_hour);
buf[3] = bin2bcd(alarm->time.tm_mday);
ret = i2c_smbus_read_byte_data(client, DS3232_REG_CR);
if (ret < 0)
goto out;
control = ret;
control &= ~(DS3232_REG_CR_A1IE | DS3232_REG_CR_A2IE);
ret = i2c_smbus_write_byte_data(client, DS3232_REG_CR, control);
if (ret < 0)
goto out;
ret = i2c_smbus_read_byte_data(client, DS3232_REG_SR);
if (ret < 0)
goto out;
stat = ret;
stat &= ~(DS3232_REG_SR_A1F | DS3232_REG_SR_A2F);
ret = i2c_smbus_write_byte_data(client, DS3232_REG_SR, stat);
if (ret < 0)
goto out;
ret = i2c_smbus_write_i2c_block_data(client, DS3232_REG_ALARM1, 4, buf);
if (alarm->enabled) {
control |= DS3232_REG_CR_A1IE;
ret = i2c_smbus_write_byte_data(client, DS3232_REG_CR, control);
}
out:
mutex_unlock(&ds3232->mutex);
return ret;
}
static void ds3232_update_alarm(struct i2c_client *client)
{
struct ds3232 *ds3232 = i2c_get_clientdata(client);
int control;
int ret;
u8 buf[4];
mutex_lock(&ds3232->mutex);
ret = i2c_smbus_read_i2c_block_data(client, DS3232_REG_ALARM1, 4, buf);
if (ret < 0)
goto unlock;
buf[0] = bcd2bin(buf[0]) < 0 || (ds3232->rtc->irq_data & RTC_UF) ?
0x80 : buf[0];
buf[1] = bcd2bin(buf[1]) < 0 || (ds3232->rtc->irq_data & RTC_UF) ?
0x80 : buf[1];
buf[2] = bcd2bin(buf[2]) < 0 || (ds3232->rtc->irq_data & RTC_UF) ?
0x80 : buf[2];
buf[3] = bcd2bin(buf[3]) < 0 || (ds3232->rtc->irq_data & RTC_UF) ?
0x80 : buf[3];
ret = i2c_smbus_write_i2c_block_data(client, DS3232_REG_ALARM1, 4, buf);
if (ret < 0)
goto unlock;
control = i2c_smbus_read_byte_data(client, DS3232_REG_CR);
if (control < 0)
goto unlock;
if (ds3232->rtc->irq_data & (RTC_AF | RTC_UF))
control |= DS3232_REG_CR_A1IE;
else
control &= ~(DS3232_REG_CR_A1IE);
i2c_smbus_write_byte_data(client, DS3232_REG_CR, control);
unlock:
mutex_unlock(&ds3232->mutex);
}
static int ds3232_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds3232 *ds3232 = i2c_get_clientdata(client);
if (client->irq <= 0)
return -EINVAL;
if (enabled)
ds3232->rtc->irq_data |= RTC_AF;
else
ds3232->rtc->irq_data &= ~RTC_AF;
ds3232_update_alarm(client);
return 0;
}
static irqreturn_t ds3232_irq(int irq, void *dev_id)
{
struct i2c_client *client = dev_id;
struct ds3232 *ds3232 = i2c_get_clientdata(client);
disable_irq_nosync(irq);
schedule_work(&ds3232->work);
return IRQ_HANDLED;
}
static void ds3232_work(struct work_struct *work)
{
struct ds3232 *ds3232 = container_of(work, struct ds3232, work);
struct i2c_client *client = ds3232->client;
int stat, control;
mutex_lock(&ds3232->mutex);
stat = i2c_smbus_read_byte_data(client, DS3232_REG_SR);
if (stat < 0)
goto unlock;
if (stat & DS3232_REG_SR_A1F) {
control = i2c_smbus_read_byte_data(client, DS3232_REG_CR);
if (control < 0)
goto out;
control &= ~(DS3232_REG_CR_A1IE);
i2c_smbus_write_byte_data(client, DS3232_REG_CR, control);
stat &= ~DS3232_REG_SR_A1F;
i2c_smbus_write_byte_data(client, DS3232_REG_SR, stat);
rtc_update_irq(ds3232->rtc, 1, RTC_AF | RTC_IRQF);
}
out:
if (!ds3232->exiting)
enable_irq(client->irq);
unlock:
mutex_unlock(&ds3232->mutex);
}
static int ds3232_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds3232 *ds3232;
int ret;
ds3232 = kzalloc(sizeof(struct ds3232), GFP_KERNEL);
if (!ds3232)
return -ENOMEM;
ds3232->client = client;
i2c_set_clientdata(client, ds3232);
INIT_WORK(&ds3232->work, ds3232_work);
mutex_init(&ds3232->mutex);
ret = ds3232_check_rtc_status(client);
if (ret)
goto out_free;
ds3232->rtc = rtc_device_register(client->name, &client->dev,
&ds3232_rtc_ops, THIS_MODULE);
if (IS_ERR(ds3232->rtc)) {
ret = PTR_ERR(ds3232->rtc);
dev_err(&client->dev, "unable to register the class device\n");
goto out_irq;
}
if (client->irq >= 0) {
ret = request_irq(client->irq, ds3232_irq, 0,
"ds3232", client);
if (ret) {
dev_err(&client->dev, "unable to request IRQ\n");
goto out_free;
}
}
return 0;
out_irq:
if (client->irq >= 0)
free_irq(client->irq, client);
out_free:
kfree(ds3232);
return ret;
}
static int ds3232_remove(struct i2c_client *client)
{
struct ds3232 *ds3232 = i2c_get_clientdata(client);
if (client->irq >= 0) {
mutex_lock(&ds3232->mutex);
ds3232->exiting = 1;
mutex_unlock(&ds3232->mutex);
free_irq(client->irq, client);
cancel_work_sync(&ds3232->work);
}
rtc_device_unregister(ds3232->rtc);
kfree(ds3232);
return 0;
}
