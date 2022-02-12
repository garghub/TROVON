static s32 ds1307_read_block_data_once(const struct i2c_client *client,
u8 command, u8 length, u8 *values)
{
s32 i, data;
for (i = 0; i < length; i++) {
data = i2c_smbus_read_byte_data(client, command + i);
if (data < 0)
return data;
values[i] = data;
}
return i;
}
static s32 ds1307_read_block_data(const struct i2c_client *client, u8 command,
u8 length, u8 *values)
{
u8 oldvalues[255];
s32 ret;
int tries = 0;
dev_dbg(&client->dev, "ds1307_read_block_data (length=%d)\n", length);
ret = ds1307_read_block_data_once(client, command, length, values);
if (ret < 0)
return ret;
do {
if (++tries > BLOCK_DATA_MAX_TRIES) {
dev_err(&client->dev,
"ds1307_read_block_data failed\n");
return -EIO;
}
memcpy(oldvalues, values, length);
ret = ds1307_read_block_data_once(client, command, length,
values);
if (ret < 0)
return ret;
} while (memcmp(oldvalues, values, length));
return length;
}
static s32 ds1307_write_block_data(const struct i2c_client *client, u8 command,
u8 length, const u8 *values)
{
u8 currvalues[255];
int tries = 0;
dev_dbg(&client->dev, "ds1307_write_block_data (length=%d)\n", length);
do {
s32 i, ret;
if (++tries > BLOCK_DATA_MAX_TRIES) {
dev_err(&client->dev,
"ds1307_write_block_data failed\n");
return -EIO;
}
for (i = 0; i < length; i++) {
ret = i2c_smbus_write_byte_data(client, command + i,
values[i]);
if (ret < 0)
return ret;
}
ret = ds1307_read_block_data_once(client, command, length,
currvalues);
if (ret < 0)
return ret;
} while (memcmp(currvalues, values, length));
return length;
}
static s32 ds1307_native_smbus_write_block_data(const struct i2c_client *client,
u8 command, u8 length, const u8 *values)
{
u8 suboffset = 0;
if (length <= I2C_SMBUS_BLOCK_MAX)
return i2c_smbus_write_i2c_block_data(client,
command, length, values);
while (suboffset < length) {
s32 retval = i2c_smbus_write_i2c_block_data(client,
command + suboffset,
min(I2C_SMBUS_BLOCK_MAX, length - suboffset),
values + suboffset);
if (retval < 0)
return retval;
suboffset += I2C_SMBUS_BLOCK_MAX;
}
return length;
}
static s32 ds1307_native_smbus_read_block_data(const struct i2c_client *client,
u8 command, u8 length, u8 *values)
{
u8 suboffset = 0;
if (length <= I2C_SMBUS_BLOCK_MAX)
return i2c_smbus_read_i2c_block_data(client,
command, length, values);
while (suboffset < length) {
s32 retval = i2c_smbus_read_i2c_block_data(client,
command + suboffset,
min(I2C_SMBUS_BLOCK_MAX, length - suboffset),
values + suboffset);
if (retval < 0)
return retval;
suboffset += I2C_SMBUS_BLOCK_MAX;
}
return length;
}
static void ds1307_work(struct work_struct *work)
{
struct ds1307 *ds1307;
struct i2c_client *client;
struct mutex *lock;
int stat, control;
ds1307 = container_of(work, struct ds1307, work);
client = ds1307->client;
lock = &ds1307->rtc->ops_lock;
mutex_lock(lock);
stat = i2c_smbus_read_byte_data(client, DS1337_REG_STATUS);
if (stat < 0)
goto out;
if (stat & DS1337_BIT_A1I) {
stat &= ~DS1337_BIT_A1I;
i2c_smbus_write_byte_data(client, DS1337_REG_STATUS, stat);
control = i2c_smbus_read_byte_data(client, DS1337_REG_CONTROL);
if (control < 0)
goto out;
control &= ~DS1337_BIT_A1IE;
i2c_smbus_write_byte_data(client, DS1337_REG_CONTROL, control);
rtc_update_irq(ds1307->rtc, 1, RTC_AF | RTC_IRQF);
}
out:
if (test_bit(HAS_ALARM, &ds1307->flags))
enable_irq(client->irq);
mutex_unlock(lock);
}
static irqreturn_t ds1307_irq(int irq, void *dev_id)
{
struct i2c_client *client = dev_id;
struct ds1307 *ds1307 = i2c_get_clientdata(client);
disable_irq_nosync(irq);
schedule_work(&ds1307->work);
return IRQ_HANDLED;
}
static int ds1307_get_time(struct device *dev, struct rtc_time *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
int tmp;
tmp = ds1307->read_block_data(ds1307->client,
ds1307->offset, 7, ds1307->regs);
if (tmp != 7) {
dev_err(dev, "%s error %d\n", "read", tmp);
return -EIO;
}
dev_dbg(dev, "%s: %7ph\n", "read", ds1307->regs);
t->tm_sec = bcd2bin(ds1307->regs[DS1307_REG_SECS] & 0x7f);
t->tm_min = bcd2bin(ds1307->regs[DS1307_REG_MIN] & 0x7f);
tmp = ds1307->regs[DS1307_REG_HOUR] & 0x3f;
t->tm_hour = bcd2bin(tmp);
t->tm_wday = bcd2bin(ds1307->regs[DS1307_REG_WDAY] & 0x07) - 1;
t->tm_mday = bcd2bin(ds1307->regs[DS1307_REG_MDAY] & 0x3f);
tmp = ds1307->regs[DS1307_REG_MONTH] & 0x1f;
t->tm_mon = bcd2bin(tmp) - 1;
t->tm_year = bcd2bin(ds1307->regs[DS1307_REG_YEAR]) + 100;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"read", t->tm_sec, t->tm_min,
t->tm_hour, t->tm_mday,
t->tm_mon, t->tm_year, t->tm_wday);
return rtc_valid_tm(t);
}
static int ds1307_set_time(struct device *dev, struct rtc_time *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
int result;
int tmp;
u8 *buf = ds1307->regs;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"write", t->tm_sec, t->tm_min,
t->tm_hour, t->tm_mday,
t->tm_mon, t->tm_year, t->tm_wday);
buf[DS1307_REG_SECS] = bin2bcd(t->tm_sec);
buf[DS1307_REG_MIN] = bin2bcd(t->tm_min);
buf[DS1307_REG_HOUR] = bin2bcd(t->tm_hour);
buf[DS1307_REG_WDAY] = bin2bcd(t->tm_wday + 1);
buf[DS1307_REG_MDAY] = bin2bcd(t->tm_mday);
buf[DS1307_REG_MONTH] = bin2bcd(t->tm_mon + 1);
tmp = t->tm_year - 100;
buf[DS1307_REG_YEAR] = bin2bcd(tmp);
switch (ds1307->type) {
case ds_1337:
case ds_1339:
case ds_3231:
buf[DS1307_REG_MONTH] |= DS1337_BIT_CENTURY;
break;
case ds_1340:
buf[DS1307_REG_HOUR] |= DS1340_BIT_CENTURY_EN
| DS1340_BIT_CENTURY;
break;
case mcp7941x:
buf[DS1307_REG_SECS] |= MCP7941X_BIT_ST;
buf[DS1307_REG_WDAY] |= MCP7941X_BIT_VBATEN;
break;
default:
break;
}
dev_dbg(dev, "%s: %7ph\n", "write", buf);
result = ds1307->write_block_data(ds1307->client,
ds1307->offset, 7, buf);
if (result < 0) {
dev_err(dev, "%s error %d\n", "write", result);
return result;
}
return 0;
}
static int ds1337_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1307 *ds1307 = i2c_get_clientdata(client);
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
ret = ds1307->read_block_data(client,
DS1339_REG_ALARM1_SECS, 9, ds1307->regs);
if (ret != 9) {
dev_err(dev, "%s error %d\n", "alarm read", ret);
return -EIO;
}
dev_dbg(dev, "%s: %02x %02x %02x %02x, %02x %02x %02x, %02x %02x\n",
"alarm read",
ds1307->regs[0], ds1307->regs[1],
ds1307->regs[2], ds1307->regs[3],
ds1307->regs[4], ds1307->regs[5],
ds1307->regs[6], ds1307->regs[7],
ds1307->regs[8]);
t->time.tm_sec = bcd2bin(ds1307->regs[0] & 0x7f);
t->time.tm_min = bcd2bin(ds1307->regs[1] & 0x7f);
t->time.tm_hour = bcd2bin(ds1307->regs[2] & 0x3f);
t->time.tm_mday = bcd2bin(ds1307->regs[3] & 0x3f);
t->time.tm_mon = -1;
t->time.tm_year = -1;
t->time.tm_wday = -1;
t->time.tm_yday = -1;
t->time.tm_isdst = -1;
t->enabled = !!(ds1307->regs[7] & DS1337_BIT_A1IE);
t->pending = !!(ds1307->regs[8] & DS1337_BIT_A1I);
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, enabled=%d, pending=%d\n",
"alarm read", t->time.tm_sec, t->time.tm_min,
t->time.tm_hour, t->time.tm_mday,
t->enabled, t->pending);
return 0;
}
static int ds1337_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1307 *ds1307 = i2c_get_clientdata(client);
unsigned char *buf = ds1307->regs;
u8 control, status;
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, enabled=%d, pending=%d\n",
"alarm set", t->time.tm_sec, t->time.tm_min,
t->time.tm_hour, t->time.tm_mday,
t->enabled, t->pending);
ret = ds1307->read_block_data(client,
DS1339_REG_ALARM1_SECS, 9, buf);
if (ret != 9) {
dev_err(dev, "%s error %d\n", "alarm write", ret);
return -EIO;
}
control = ds1307->regs[7];
status = ds1307->regs[8];
dev_dbg(dev, "%s: %02x %02x %02x %02x, %02x %02x %02x, %02x %02x\n",
"alarm set (old status)",
ds1307->regs[0], ds1307->regs[1],
ds1307->regs[2], ds1307->regs[3],
ds1307->regs[4], ds1307->regs[5],
ds1307->regs[6], control, status);
buf[0] = bin2bcd(t->time.tm_sec);
buf[1] = bin2bcd(t->time.tm_min);
buf[2] = bin2bcd(t->time.tm_hour);
buf[3] = bin2bcd(t->time.tm_mday);
buf[4] = 0;
buf[5] = 0;
buf[6] = 0;
buf[7] = control & ~(DS1337_BIT_A1IE | DS1337_BIT_A2IE);
if (t->enabled) {
dev_dbg(dev, "alarm IRQ armed\n");
buf[7] |= DS1337_BIT_A1IE;
}
buf[8] = status & ~(DS1337_BIT_A1I | DS1337_BIT_A2I);
ret = ds1307->write_block_data(client,
DS1339_REG_ALARM1_SECS, 9, buf);
if (ret < 0) {
dev_err(dev, "can't set alarm time\n");
return ret;
}
return 0;
}
static int ds1307_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1307 *ds1307 = i2c_get_clientdata(client);
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -ENOTTY;
ret = i2c_smbus_read_byte_data(client, DS1337_REG_CONTROL);
if (ret < 0)
return ret;
if (enabled)
ret |= DS1337_BIT_A1IE;
else
ret &= ~DS1337_BIT_A1IE;
ret = i2c_smbus_write_byte_data(client, DS1337_REG_CONTROL, ret);
if (ret < 0)
return ret;
return 0;
}
static ssize_t
ds1307_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct i2c_client *client;
struct ds1307 *ds1307;
int result;
client = kobj_to_i2c_client(kobj);
ds1307 = i2c_get_clientdata(client);
if (unlikely(off >= ds1307->nvram->size))
return 0;
if ((off + count) > ds1307->nvram->size)
count = ds1307->nvram->size - off;
if (unlikely(!count))
return count;
result = ds1307->read_block_data(client, ds1307->nvram_offset + off,
count, buf);
if (result < 0)
dev_err(&client->dev, "%s error %d\n", "nvram read", result);
return result;
}
static ssize_t
ds1307_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct i2c_client *client;
struct ds1307 *ds1307;
int result;
client = kobj_to_i2c_client(kobj);
ds1307 = i2c_get_clientdata(client);
if (unlikely(off >= ds1307->nvram->size))
return -EFBIG;
if ((off + count) > ds1307->nvram->size)
count = ds1307->nvram->size - off;
if (unlikely(!count))
return count;
result = ds1307->write_block_data(client, ds1307->nvram_offset + off,
count, buf);
if (result < 0) {
dev_err(&client->dev, "%s error %d\n", "nvram write", result);
return result;
}
return count;
}
static int ds1307_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds1307 *ds1307;
int err = -ENODEV;
int tmp;
const struct chip_desc *chip = &chips[id->driver_data];
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int want_irq = false;
unsigned char *buf;
struct ds1307_platform_data *pdata = client->dev.platform_data;
static const int bbsqi_bitpos[] = {
[ds_1337] = 0,
[ds_1339] = DS1339_BIT_BBSQI,
[ds_3231] = DS3231_BIT_BBSQW,
};
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)
&& !i2c_check_functionality(adapter, I2C_FUNC_SMBUS_I2C_BLOCK))
return -EIO;
ds1307 = kzalloc(sizeof(struct ds1307), GFP_KERNEL);
if (!ds1307)
return -ENOMEM;
i2c_set_clientdata(client, ds1307);
ds1307->client = client;
ds1307->type = id->driver_data;
if (pdata && pdata->trickle_charger_setup && chip->trickle_charger_reg)
i2c_smbus_write_byte_data(client, chip->trickle_charger_reg,
DS13XX_TRICKLE_CHARGER_MAGIC | pdata->trickle_charger_setup);
buf = ds1307->regs;
if (i2c_check_functionality(adapter, I2C_FUNC_SMBUS_I2C_BLOCK)) {
ds1307->read_block_data = ds1307_native_smbus_read_block_data;
ds1307->write_block_data = ds1307_native_smbus_write_block_data;
} else {
ds1307->read_block_data = ds1307_read_block_data;
ds1307->write_block_data = ds1307_write_block_data;
}
switch (ds1307->type) {
case ds_1337:
case ds_1339:
case ds_3231:
tmp = ds1307->read_block_data(ds1307->client,
DS1337_REG_CONTROL, 2, buf);
if (tmp != 2) {
dev_dbg(&client->dev, "read error %d\n", tmp);
err = -EIO;
goto exit_free;
}
if (ds1307->regs[0] & DS1337_BIT_nEOSC)
ds1307->regs[0] &= ~DS1337_BIT_nEOSC;
if (ds1307->client->irq > 0 && chip->alarm) {
INIT_WORK(&ds1307->work, ds1307_work);
ds1307->regs[0] |= DS1337_BIT_INTCN
| bbsqi_bitpos[ds1307->type];
ds1307->regs[0] &= ~(DS1337_BIT_A2IE | DS1337_BIT_A1IE);
want_irq = true;
}
i2c_smbus_write_byte_data(client, DS1337_REG_CONTROL,
ds1307->regs[0]);
if (ds1307->regs[1] & DS1337_BIT_OSF) {
i2c_smbus_write_byte_data(client, DS1337_REG_STATUS,
ds1307->regs[1] & ~DS1337_BIT_OSF);
dev_warn(&client->dev, "SET TIME!\n");
}
break;
case rx_8025:
tmp = i2c_smbus_read_i2c_block_data(ds1307->client,
RX8025_REG_CTRL1 << 4 | 0x08, 2, buf);
if (tmp != 2) {
dev_dbg(&client->dev, "read error %d\n", tmp);
err = -EIO;
goto exit_free;
}
if (!(ds1307->regs[1] & RX8025_BIT_XST)) {
ds1307->regs[1] |= RX8025_BIT_XST;
i2c_smbus_write_byte_data(client,
RX8025_REG_CTRL2 << 4 | 0x08,
ds1307->regs[1]);
dev_warn(&client->dev,
"oscillator stop detected - SET TIME!\n");
}
if (ds1307->regs[1] & RX8025_BIT_PON) {
ds1307->regs[1] &= ~RX8025_BIT_PON;
i2c_smbus_write_byte_data(client,
RX8025_REG_CTRL2 << 4 | 0x08,
ds1307->regs[1]);
dev_warn(&client->dev, "power-on detected\n");
}
if (ds1307->regs[1] & RX8025_BIT_VDET) {
ds1307->regs[1] &= ~RX8025_BIT_VDET;
i2c_smbus_write_byte_data(client,
RX8025_REG_CTRL2 << 4 | 0x08,
ds1307->regs[1]);
dev_warn(&client->dev, "voltage drop detected\n");
}
if (!(ds1307->regs[0] & RX8025_BIT_2412)) {
u8 hour;
i2c_smbus_write_byte_data(client,
RX8025_REG_CTRL1 << 4 | 0x08,
ds1307->regs[0] |
RX8025_BIT_2412);
tmp = i2c_smbus_read_i2c_block_data(ds1307->client,
RX8025_REG_CTRL1 << 4 | 0x08, 2, buf);
if (tmp != 2) {
dev_dbg(&client->dev, "read error %d\n", tmp);
err = -EIO;
goto exit_free;
}
hour = bcd2bin(ds1307->regs[DS1307_REG_HOUR]);
if (hour == 12)
hour = 0;
if (ds1307->regs[DS1307_REG_HOUR] & DS1307_BIT_PM)
hour += 12;
i2c_smbus_write_byte_data(client,
DS1307_REG_HOUR << 4 | 0x08,
hour);
}
break;
case ds_1388:
ds1307->offset = 1;
break;
default:
break;
}
read_rtc:
tmp = ds1307->read_block_data(ds1307->client, ds1307->offset, 8, buf);
if (tmp != 8) {
dev_dbg(&client->dev, "read error %d\n", tmp);
err = -EIO;
goto exit_free;
}
tmp = ds1307->regs[DS1307_REG_SECS];
switch (ds1307->type) {
case ds_1307:
case m41t00:
if (tmp & DS1307_BIT_CH) {
i2c_smbus_write_byte_data(client, DS1307_REG_SECS, 0);
dev_warn(&client->dev, "SET TIME!\n");
goto read_rtc;
}
break;
case ds_1338:
if (tmp & DS1307_BIT_CH)
i2c_smbus_write_byte_data(client, DS1307_REG_SECS, 0);
if (ds1307->regs[DS1307_REG_CONTROL] & DS1338_BIT_OSF) {
i2c_smbus_write_byte_data(client, DS1307_REG_CONTROL,
ds1307->regs[DS1307_REG_CONTROL]
& ~DS1338_BIT_OSF);
dev_warn(&client->dev, "SET TIME!\n");
goto read_rtc;
}
break;
case ds_1340:
if (tmp & DS1340_BIT_nEOSC)
i2c_smbus_write_byte_data(client, DS1307_REG_SECS, 0);
tmp = i2c_smbus_read_byte_data(client, DS1340_REG_FLAG);
if (tmp < 0) {
dev_dbg(&client->dev, "read error %d\n", tmp);
err = -EIO;
goto exit_free;
}
if (tmp & DS1340_BIT_OSF) {
i2c_smbus_write_byte_data(client, DS1340_REG_FLAG, 0);
dev_warn(&client->dev, "SET TIME!\n");
}
break;
case mcp7941x:
if (!(ds1307->regs[DS1307_REG_WDAY] & MCP7941X_BIT_VBATEN)) {
i2c_smbus_write_byte_data(client, DS1307_REG_WDAY,
ds1307->regs[DS1307_REG_WDAY]
| MCP7941X_BIT_VBATEN);
}
if (!(tmp & MCP7941X_BIT_ST)) {
i2c_smbus_write_byte_data(client, DS1307_REG_SECS,
MCP7941X_BIT_ST);
dev_warn(&client->dev, "SET TIME!\n");
goto read_rtc;
}
break;
default:
break;
}
tmp = ds1307->regs[DS1307_REG_HOUR];
switch (ds1307->type) {
case ds_1340:
case m41t00:
break;
case rx_8025:
break;
default:
if (!(tmp & DS1307_BIT_12HR))
break;
tmp = bcd2bin(tmp & 0x1f);
if (tmp == 12)
tmp = 0;
if (ds1307->regs[DS1307_REG_HOUR] & DS1307_BIT_PM)
tmp += 12;
i2c_smbus_write_byte_data(client,
ds1307->offset + DS1307_REG_HOUR,
bin2bcd(tmp));
}
ds1307->rtc = rtc_device_register(client->name, &client->dev,
&ds13xx_rtc_ops, THIS_MODULE);
if (IS_ERR(ds1307->rtc)) {
err = PTR_ERR(ds1307->rtc);
dev_err(&client->dev,
"unable to register the class device\n");
goto exit_free;
}
if (want_irq) {
err = request_irq(client->irq, ds1307_irq, IRQF_SHARED,
ds1307->rtc->name, client);
if (err) {
dev_err(&client->dev,
"unable to request IRQ!\n");
goto exit_irq;
}
device_set_wakeup_capable(&client->dev, 1);
set_bit(HAS_ALARM, &ds1307->flags);
dev_dbg(&client->dev, "got IRQ %d\n", client->irq);
}
if (chip->nvram_size) {
ds1307->nvram = kzalloc(sizeof(struct bin_attribute),
GFP_KERNEL);
if (!ds1307->nvram) {
err = -ENOMEM;
goto exit_nvram;
}
ds1307->nvram->attr.name = "nvram";
ds1307->nvram->attr.mode = S_IRUGO | S_IWUSR;
sysfs_bin_attr_init(ds1307->nvram);
ds1307->nvram->read = ds1307_nvram_read;
ds1307->nvram->write = ds1307_nvram_write;
ds1307->nvram->size = chip->nvram_size;
ds1307->nvram_offset = chip->nvram_offset;
err = sysfs_create_bin_file(&client->dev.kobj, ds1307->nvram);
if (err) {
kfree(ds1307->nvram);
goto exit_nvram;
}
set_bit(HAS_NVRAM, &ds1307->flags);
dev_info(&client->dev, "%zu bytes nvram\n", ds1307->nvram->size);
}
return 0;
exit_nvram:
exit_irq:
rtc_device_unregister(ds1307->rtc);
exit_free:
kfree(ds1307);
return err;
}
static int ds1307_remove(struct i2c_client *client)
{
struct ds1307 *ds1307 = i2c_get_clientdata(client);
if (test_and_clear_bit(HAS_ALARM, &ds1307->flags)) {
free_irq(client->irq, client);
cancel_work_sync(&ds1307->work);
}
if (test_and_clear_bit(HAS_NVRAM, &ds1307->flags)) {
sysfs_remove_bin_file(&client->dev.kobj, ds1307->nvram);
kfree(ds1307->nvram);
}
rtc_device_unregister(ds1307->rtc);
kfree(ds1307);
return 0;
}
