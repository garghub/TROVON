static int m41t80_get_datetime(struct i2c_client *client,
struct rtc_time *tm)
{
u8 buf[M41T80_DATETIME_REG_SIZE], dt_addr[1] = { M41T80_REG_SEC };
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = dt_addr,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = M41T80_DATETIME_REG_SIZE - M41T80_REG_SEC,
.buf = buf + M41T80_REG_SEC,
},
};
if (i2c_transfer(client->adapter, msgs, 2) < 0) {
dev_err(&client->dev, "read error\n");
return -EIO;
}
tm->tm_sec = bcd2bin(buf[M41T80_REG_SEC] & 0x7f);
tm->tm_min = bcd2bin(buf[M41T80_REG_MIN] & 0x7f);
tm->tm_hour = bcd2bin(buf[M41T80_REG_HOUR] & 0x3f);
tm->tm_mday = bcd2bin(buf[M41T80_REG_DAY] & 0x3f);
tm->tm_wday = buf[M41T80_REG_WDAY] & 0x07;
tm->tm_mon = bcd2bin(buf[M41T80_REG_MON] & 0x1f) - 1;
tm->tm_year = bcd2bin(buf[M41T80_REG_YEAR]) + 100;
return rtc_valid_tm(tm);
}
static int m41t80_set_datetime(struct i2c_client *client, struct rtc_time *tm)
{
u8 wbuf[1 + M41T80_DATETIME_REG_SIZE];
u8 *buf = &wbuf[1];
u8 dt_addr[1] = { M41T80_REG_SEC };
struct i2c_msg msgs_in[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = dt_addr,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = M41T80_DATETIME_REG_SIZE - M41T80_REG_SEC,
.buf = buf + M41T80_REG_SEC,
},
};
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1 + M41T80_DATETIME_REG_SIZE,
.buf = wbuf,
},
};
if (i2c_transfer(client->adapter, msgs_in, 2) < 0) {
dev_err(&client->dev, "read error\n");
return -EIO;
}
wbuf[0] = 0;
buf[M41T80_REG_SSEC] = 0;
buf[M41T80_REG_SEC] =
bin2bcd(tm->tm_sec) | (buf[M41T80_REG_SEC] & ~0x7f);
buf[M41T80_REG_MIN] =
bin2bcd(tm->tm_min) | (buf[M41T80_REG_MIN] & ~0x7f);
buf[M41T80_REG_HOUR] =
bin2bcd(tm->tm_hour) | (buf[M41T80_REG_HOUR] & ~0x3f) ;
buf[M41T80_REG_WDAY] =
(tm->tm_wday & 0x07) | (buf[M41T80_REG_WDAY] & ~0x07);
buf[M41T80_REG_DAY] =
bin2bcd(tm->tm_mday) | (buf[M41T80_REG_DAY] & ~0x3f);
buf[M41T80_REG_MON] =
bin2bcd(tm->tm_mon + 1) | (buf[M41T80_REG_MON] & ~0x1f);
buf[M41T80_REG_YEAR] = bin2bcd(tm->tm_year % 100);
if (i2c_transfer(client->adapter, msgs, 1) != 1) {
dev_err(&client->dev, "write error\n");
return -EIO;
}
return 0;
}
static int m41t80_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct i2c_client *client = to_i2c_client(dev);
struct m41t80_data *clientdata = i2c_get_clientdata(client);
u8 reg;
if (clientdata->features & M41T80_FEATURE_BL) {
reg = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
seq_printf(seq, "battery\t\t: %s\n",
(reg & M41T80_FLAGS_BATT_LOW) ? "exhausted" : "ok");
}
return 0;
}
static int m41t80_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return m41t80_get_datetime(to_i2c_client(dev), tm);
}
static int m41t80_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return m41t80_set_datetime(to_i2c_client(dev), tm);
}
static int m41t80_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct i2c_client *client = to_i2c_client(dev);
int rc;
rc = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (rc < 0)
goto err;
if (enabled)
rc |= M41T80_ALMON_AFE;
else
rc &= ~M41T80_ALMON_AFE;
if (i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON, rc) < 0)
goto err;
return 0;
err:
return -EIO;
}
static int m41t80_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
u8 wbuf[1 + M41T80_ALARM_REG_SIZE];
u8 *buf = &wbuf[1];
u8 *reg = buf - M41T80_REG_ALARM_MON;
u8 dt_addr[1] = { M41T80_REG_ALARM_MON };
struct i2c_msg msgs_in[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = dt_addr,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = M41T80_ALARM_REG_SIZE,
.buf = buf,
},
};
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1 + M41T80_ALARM_REG_SIZE,
.buf = wbuf,
},
};
if (i2c_transfer(client->adapter, msgs_in, 2) < 0) {
dev_err(&client->dev, "read error\n");
return -EIO;
}
reg[M41T80_REG_ALARM_MON] &= ~(0x1f | M41T80_ALMON_AFE);
reg[M41T80_REG_ALARM_DAY] = 0;
reg[M41T80_REG_ALARM_HOUR] &= ~(0x3f | 0x80);
reg[M41T80_REG_ALARM_MIN] = 0;
reg[M41T80_REG_ALARM_SEC] = 0;
wbuf[0] = M41T80_REG_ALARM_MON;
reg[M41T80_REG_ALARM_SEC] |= t->time.tm_sec >= 0 ?
bin2bcd(t->time.tm_sec) : 0x80;
reg[M41T80_REG_ALARM_MIN] |= t->time.tm_min >= 0 ?
bin2bcd(t->time.tm_min) : 0x80;
reg[M41T80_REG_ALARM_HOUR] |= t->time.tm_hour >= 0 ?
bin2bcd(t->time.tm_hour) : 0x80;
reg[M41T80_REG_ALARM_DAY] |= t->time.tm_mday >= 0 ?
bin2bcd(t->time.tm_mday) : 0x80;
if (t->time.tm_mon >= 0)
reg[M41T80_REG_ALARM_MON] |= bin2bcd(t->time.tm_mon + 1);
else
reg[M41T80_REG_ALARM_DAY] |= 0x40;
if (i2c_transfer(client->adapter, msgs, 1) != 1) {
dev_err(&client->dev, "write error\n");
return -EIO;
}
if (t->enabled) {
reg[M41T80_REG_ALARM_MON] |= M41T80_ALMON_AFE;
if (i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
reg[M41T80_REG_ALARM_MON]) < 0) {
dev_err(&client->dev, "write error\n");
return -EIO;
}
}
return 0;
}
static int m41t80_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
u8 buf[M41T80_ALARM_REG_SIZE + 1];
u8 dt_addr[1] = { M41T80_REG_ALARM_MON };
u8 *reg = buf - M41T80_REG_ALARM_MON;
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = dt_addr,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = M41T80_ALARM_REG_SIZE + 1,
.buf = buf,
},
};
if (i2c_transfer(client->adapter, msgs, 2) < 0) {
dev_err(&client->dev, "read error\n");
return -EIO;
}
t->time.tm_sec = -1;
t->time.tm_min = -1;
t->time.tm_hour = -1;
t->time.tm_mday = -1;
t->time.tm_mon = -1;
if (!(reg[M41T80_REG_ALARM_SEC] & 0x80))
t->time.tm_sec = bcd2bin(reg[M41T80_REG_ALARM_SEC] & 0x7f);
if (!(reg[M41T80_REG_ALARM_MIN] & 0x80))
t->time.tm_min = bcd2bin(reg[M41T80_REG_ALARM_MIN] & 0x7f);
if (!(reg[M41T80_REG_ALARM_HOUR] & 0x80))
t->time.tm_hour = bcd2bin(reg[M41T80_REG_ALARM_HOUR] & 0x3f);
if (!(reg[M41T80_REG_ALARM_DAY] & 0x80))
t->time.tm_mday = bcd2bin(reg[M41T80_REG_ALARM_DAY] & 0x3f);
if (!(reg[M41T80_REG_ALARM_DAY] & 0x40))
t->time.tm_mon = bcd2bin(reg[M41T80_REG_ALARM_MON] & 0x1f) - 1;
t->time.tm_year = -1;
t->time.tm_wday = -1;
t->time.tm_yday = -1;
t->time.tm_isdst = -1;
t->enabled = !!(reg[M41T80_REG_ALARM_MON] & M41T80_ALMON_AFE);
t->pending = !!(reg[M41T80_REG_FLAGS] & M41T80_FLAGS_AF);
return 0;
}
static ssize_t m41t80_sysfs_show_flags(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int val;
val = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
if (val < 0)
return -EIO;
return sprintf(buf, "%#x\n", val);
}
static ssize_t m41t80_sysfs_show_sqwfreq(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct m41t80_data *clientdata = i2c_get_clientdata(client);
int val, reg_sqw;
if (!(clientdata->features & M41T80_FEATURE_SQ))
return -EINVAL;
reg_sqw = M41T80_REG_SQW;
if (clientdata->features & M41T80_FEATURE_SQ_ALT)
reg_sqw = M41T80_REG_WDAY;
val = i2c_smbus_read_byte_data(client, reg_sqw);
if (val < 0)
return -EIO;
val = (val >> 4) & 0xf;
switch (val) {
case 0:
break;
case 1:
val = 32768;
break;
default:
val = 32768 >> val;
}
return sprintf(buf, "%d\n", val);
}
static ssize_t m41t80_sysfs_set_sqwfreq(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct m41t80_data *clientdata = i2c_get_clientdata(client);
int almon, sqw, reg_sqw;
int val = simple_strtoul(buf, NULL, 0);
if (!(clientdata->features & M41T80_FEATURE_SQ))
return -EINVAL;
if (val) {
if (!is_power_of_2(val))
return -EINVAL;
val = ilog2(val);
if (val == 15)
val = 1;
else if (val < 14)
val = 15 - val;
else
return -EINVAL;
}
almon = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (almon < 0)
return -EIO;
reg_sqw = M41T80_REG_SQW;
if (clientdata->features & M41T80_FEATURE_SQ_ALT)
reg_sqw = M41T80_REG_WDAY;
sqw = i2c_smbus_read_byte_data(client, reg_sqw);
if (sqw < 0)
return -EIO;
sqw = (sqw & 0x0f) | (val << 4);
if (i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
almon & ~M41T80_ALMON_SQWE) < 0 ||
i2c_smbus_write_byte_data(client, reg_sqw, sqw) < 0)
return -EIO;
if (val && i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
almon | M41T80_ALMON_SQWE) < 0)
return -EIO;
return count;
}
static int m41t80_sysfs_register(struct device *dev)
{
return sysfs_create_group(&dev->kobj, &attr_group);
}
static int m41t80_sysfs_register(struct device *dev)
{
return 0;
}
static void wdt_ping(void)
{
unsigned char i2c_data[2];
struct i2c_msg msgs1[1] = {
{
.addr = save_client->addr,
.flags = 0,
.len = 2,
.buf = i2c_data,
},
};
struct m41t80_data *clientdata = i2c_get_clientdata(save_client);
i2c_data[0] = 0x09;
if (wdt_margin > 31)
i2c_data[1] = (wdt_margin & 0xFC) | 0x83;
else
i2c_data[1] = wdt_margin<<2 | 0x82;
if (clientdata->features & M41T80_FEATURE_WD)
i2c_data[1] &= ~M41T80_WATCHDOG_RB2;
i2c_transfer(save_client->adapter, msgs1, 1);
}
static void wdt_disable(void)
{
unsigned char i2c_data[2], i2c_buf[0x10];
struct i2c_msg msgs0[2] = {
{
.addr = save_client->addr,
.flags = 0,
.len = 1,
.buf = i2c_data,
},
{
.addr = save_client->addr,
.flags = I2C_M_RD,
.len = 1,
.buf = i2c_buf,
},
};
struct i2c_msg msgs1[1] = {
{
.addr = save_client->addr,
.flags = 0,
.len = 2,
.buf = i2c_data,
},
};
i2c_data[0] = 0x09;
i2c_transfer(save_client->adapter, msgs0, 2);
i2c_data[0] = 0x09;
i2c_data[1] = 0x00;
i2c_transfer(save_client->adapter, msgs1, 1);
}
static ssize_t wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
wdt_ping();
return 1;
}
return 0;
}
static ssize_t wdt_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
return 0;
}
static int wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int new_margin, rv;
static struct watchdog_info ident = {
.options = WDIOF_POWERUNDER | WDIOF_KEEPALIVEPING |
WDIOF_SETTIMEOUT,
.firmware_version = 1,
.identity = "M41T80 WTD"
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user((struct watchdog_info __user *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(boot_flag, (int __user *)arg);
case WDIOC_KEEPALIVE:
wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, (int __user *)arg))
return -EFAULT;
if (new_margin < 1 || new_margin > 124)
return -EINVAL;
wdt_margin = new_margin;
wdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(wdt_margin, (int __user *)arg);
case WDIOC_SETOPTIONS:
if (copy_from_user(&rv, (int __user *)arg, sizeof(int)))
return -EFAULT;
if (rv & WDIOS_DISABLECARD) {
pr_info("rtc-m41t80: disable watchdog\n");
wdt_disable();
}
if (rv & WDIOS_ENABLECARD) {
pr_info("rtc-m41t80: enable watchdog\n");
wdt_ping();
}
return -EINVAL;
}
return -ENOTTY;
}
static long wdt_unlocked_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret;
mutex_lock(&m41t80_rtc_mutex);
ret = wdt_ioctl(file, cmd, arg);
mutex_unlock(&m41t80_rtc_mutex);
return ret;
}
static int wdt_open(struct inode *inode, struct file *file)
{
if (MINOR(inode->i_rdev) == WATCHDOG_MINOR) {
mutex_lock(&m41t80_rtc_mutex);
if (test_and_set_bit(0, &wdt_is_open)) {
mutex_unlock(&m41t80_rtc_mutex);
return -EBUSY;
}
wdt_is_open = 1;
mutex_unlock(&m41t80_rtc_mutex);
return nonseekable_open(inode, file);
}
return -ENODEV;
}
static int wdt_release(struct inode *inode, struct file *file)
{
if (MINOR(inode->i_rdev) == WATCHDOG_MINOR)
clear_bit(0, &wdt_is_open);
return 0;
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_disable();
return NOTIFY_DONE;
}
static int m41t80_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int rc = 0;
struct rtc_device *rtc = NULL;
struct rtc_time tm;
struct m41t80_data *clientdata = NULL;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C
| I2C_FUNC_SMBUS_BYTE_DATA)) {
rc = -ENODEV;
goto exit;
}
dev_info(&client->dev,
"chip found, driver version " DRV_VERSION "\n");
clientdata = kzalloc(sizeof(*clientdata), GFP_KERNEL);
if (!clientdata) {
rc = -ENOMEM;
goto exit;
}
clientdata->features = id->driver_data;
i2c_set_clientdata(client, clientdata);
rtc = rtc_device_register(client->name, &client->dev,
&m41t80_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
rc = PTR_ERR(rtc);
rtc = NULL;
goto exit;
}
clientdata->rtc = rtc;
rc = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_HOUR);
if (rc < 0)
goto ht_err;
if (rc & M41T80_ALHOUR_HT) {
if (clientdata->features & M41T80_FEATURE_HT) {
m41t80_get_datetime(client, &tm);
dev_info(&client->dev, "HT bit was set!\n");
dev_info(&client->dev,
"Power Down at "
"%04i-%02i-%02i %02i:%02i:%02i\n",
tm.tm_year + 1900,
tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
tm.tm_min, tm.tm_sec);
}
if (i2c_smbus_write_byte_data(client,
M41T80_REG_ALARM_HOUR,
rc & ~M41T80_ALHOUR_HT) < 0)
goto ht_err;
}
rc = i2c_smbus_read_byte_data(client, M41T80_REG_SEC);
if (rc < 0)
goto st_err;
if (rc & M41T80_SEC_ST) {
if (i2c_smbus_write_byte_data(client, M41T80_REG_SEC,
rc & ~M41T80_SEC_ST) < 0)
goto st_err;
}
rc = m41t80_sysfs_register(&client->dev);
if (rc)
goto exit;
#ifdef CONFIG_RTC_DRV_M41T80_WDT
if (clientdata->features & M41T80_FEATURE_HT) {
save_client = client;
rc = misc_register(&wdt_dev);
if (rc)
goto exit;
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
misc_deregister(&wdt_dev);
goto exit;
}
}
#endif
return 0;
st_err:
rc = -EIO;
dev_err(&client->dev, "Can't clear ST bit\n");
goto exit;
ht_err:
rc = -EIO;
dev_err(&client->dev, "Can't clear HT bit\n");
goto exit;
exit:
if (rtc)
rtc_device_unregister(rtc);
kfree(clientdata);
return rc;
}
static int m41t80_remove(struct i2c_client *client)
{
struct m41t80_data *clientdata = i2c_get_clientdata(client);
struct rtc_device *rtc = clientdata->rtc;
#ifdef CONFIG_RTC_DRV_M41T80_WDT
if (clientdata->features & M41T80_FEATURE_HT) {
misc_deregister(&wdt_dev);
unregister_reboot_notifier(&wdt_notifier);
}
#endif
if (rtc)
rtc_device_unregister(rtc);
kfree(clientdata);
return 0;
}
