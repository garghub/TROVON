static irqreturn_t m41t80_handle_irq(int irq, void *dev_id)
{
struct i2c_client *client = dev_id;
struct m41t80_data *m41t80 = i2c_get_clientdata(client);
struct mutex *lock = &m41t80->rtc->ops_lock;
unsigned long events = 0;
int flags, flags_afe;
mutex_lock(lock);
flags_afe = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (flags_afe < 0) {
mutex_unlock(lock);
return IRQ_NONE;
}
flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
if (flags <= 0) {
mutex_unlock(lock);
return IRQ_NONE;
}
if (flags & M41T80_FLAGS_AF) {
flags &= ~M41T80_FLAGS_AF;
flags_afe &= ~M41T80_ALMON_AFE;
events |= RTC_AF;
}
if (events) {
rtc_update_irq(m41t80->rtc, 1, events);
i2c_smbus_write_byte_data(client, M41T80_REG_FLAGS, flags);
i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
flags_afe);
}
mutex_unlock(lock);
return IRQ_HANDLED;
}
static int m41t80_get_datetime(struct i2c_client *client,
struct rtc_time *tm)
{
unsigned char buf[8];
int err, flags;
flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
if (flags < 0)
return flags;
if (flags & M41T80_FLAGS_OF) {
dev_err(&client->dev, "Oscillator failure, data is invalid.\n");
return -EINVAL;
}
err = i2c_smbus_read_i2c_block_data(client, M41T80_REG_SSEC,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to read date\n");
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
struct m41t80_data *clientdata = i2c_get_clientdata(client);
unsigned char buf[8];
int err, flags;
if (tm->tm_year < 100 || tm->tm_year > 199)
return -EINVAL;
buf[M41T80_REG_SSEC] = 0;
buf[M41T80_REG_SEC] = bin2bcd(tm->tm_sec);
buf[M41T80_REG_MIN] = bin2bcd(tm->tm_min);
buf[M41T80_REG_HOUR] = bin2bcd(tm->tm_hour);
buf[M41T80_REG_DAY] = bin2bcd(tm->tm_mday);
buf[M41T80_REG_MON] = bin2bcd(tm->tm_mon + 1);
buf[M41T80_REG_YEAR] = bin2bcd(tm->tm_year - 100);
buf[M41T80_REG_WDAY] = tm->tm_wday;
if (clientdata->features & M41T80_FEATURE_SQ_ALT) {
int val;
val = i2c_smbus_read_byte_data(client, M41T80_REG_WDAY);
if (val < 0)
return val;
buf[M41T80_REG_WDAY] |= (val & 0xf0);
}
err = i2c_smbus_write_i2c_block_data(client, M41T80_REG_SSEC,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to write to date registers\n");
return err;
}
flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
if (flags < 0)
return flags;
if (i2c_smbus_write_byte_data(client, M41T80_REG_FLAGS,
flags & ~M41T80_FLAGS_OF)) {
dev_err(&client->dev, "Unable to write flags register\n");
return -EIO;
}
return err;
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
static int m41t80_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct i2c_client *client = to_i2c_client(dev);
int flags, retval;
flags = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (flags < 0)
return flags;
if (enabled)
flags |= M41T80_ALMON_AFE;
else
flags &= ~M41T80_ALMON_AFE;
retval = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON, flags);
if (retval < 0) {
dev_err(dev, "Unable to enable alarm IRQ %d\n", retval);
return retval;
}
return 0;
}
static int m41t80_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct i2c_client *client = to_i2c_client(dev);
u8 alarmvals[5];
int ret, err;
alarmvals[0] = bin2bcd(alrm->time.tm_mon + 1);
alarmvals[1] = bin2bcd(alrm->time.tm_mday);
alarmvals[2] = bin2bcd(alrm->time.tm_hour);
alarmvals[3] = bin2bcd(alrm->time.tm_min);
alarmvals[4] = bin2bcd(alrm->time.tm_sec);
ret = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (ret < 0)
return ret;
err = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
ret & ~(M41T80_ALMON_AFE));
if (err < 0) {
dev_err(dev, "Unable to clear AFE bit\n");
return err;
}
alarmvals[0] |= (ret & M41T80_ALMON_SQWE);
ret = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
if (ret < 0)
return ret;
err = i2c_smbus_write_byte_data(client, M41T80_REG_FLAGS,
ret & ~(M41T80_FLAGS_AF));
if (err < 0) {
dev_err(dev, "Unable to clear AF bit\n");
return err;
}
err = i2c_smbus_write_i2c_block_data(client, M41T80_REG_ALARM_MON,
5, alarmvals);
if (err)
return err;
if (alrm->enabled) {
alarmvals[0] |= M41T80_ALMON_AFE;
err = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
alarmvals[0]);
if (err)
return err;
}
return 0;
}
static int m41t80_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct i2c_client *client = to_i2c_client(dev);
u8 alarmvals[5];
int flags, ret;
ret = i2c_smbus_read_i2c_block_data(client, M41T80_REG_ALARM_MON,
5, alarmvals);
if (ret != 5)
return ret < 0 ? ret : -EIO;
flags = i2c_smbus_read_byte_data(client, M41T80_REG_FLAGS);
if (flags < 0)
return flags;
alrm->time.tm_sec = bcd2bin(alarmvals[4] & 0x7f);
alrm->time.tm_min = bcd2bin(alarmvals[3] & 0x7f);
alrm->time.tm_hour = bcd2bin(alarmvals[2] & 0x3f);
alrm->time.tm_mday = bcd2bin(alarmvals[1] & 0x3f);
alrm->time.tm_mon = bcd2bin(alarmvals[0] & 0x3f);
alrm->enabled = !!(alarmvals[0] & M41T80_ALMON_AFE);
alrm->pending = (flags & M41T80_FLAGS_AF) && alrm->enabled;
return 0;
}
static int m41t80_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (client->irq >= 0 && device_may_wakeup(dev))
enable_irq_wake(client->irq);
return 0;
}
static int m41t80_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (client->irq >= 0 && device_may_wakeup(dev))
disable_irq_wake(client->irq);
return 0;
}
static unsigned long m41t80_sqw_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct m41t80_data *m41t80 = sqw_to_m41t80_data(hw);
struct i2c_client *client = m41t80->client;
int reg_sqw = (m41t80->features & M41T80_FEATURE_SQ_ALT) ?
M41T80_REG_WDAY : M41T80_REG_SQW;
int ret = i2c_smbus_read_byte_data(client, reg_sqw);
unsigned long val = M41T80_SQW_MAX_FREQ;
if (ret < 0)
return 0;
ret >>= 4;
if (ret == 0)
val = 0;
else if (ret > 1)
val = val / (1 << ret);
return val;
}
static long m41t80_sqw_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int i, freq = M41T80_SQW_MAX_FREQ;
if (freq <= rate)
return freq;
for (i = 2; i <= ilog2(M41T80_SQW_MAX_FREQ); i++) {
freq /= 1 << i;
if (freq <= rate)
return freq;
}
return 0;
}
static int m41t80_sqw_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct m41t80_data *m41t80 = sqw_to_m41t80_data(hw);
struct i2c_client *client = m41t80->client;
int reg_sqw = (m41t80->features & M41T80_FEATURE_SQ_ALT) ?
M41T80_REG_WDAY : M41T80_REG_SQW;
int reg, ret, val = 0;
if (rate) {
if (!is_power_of_2(rate))
return -EINVAL;
val = ilog2(rate);
if (val == ilog2(M41T80_SQW_MAX_FREQ))
val = 1;
else if (val < (ilog2(M41T80_SQW_MAX_FREQ) - 1))
val = ilog2(M41T80_SQW_MAX_FREQ) - val;
else
return -EINVAL;
}
reg = i2c_smbus_read_byte_data(client, reg_sqw);
if (reg < 0)
return reg;
reg = (reg & 0x0f) | (val << 4);
ret = i2c_smbus_write_byte_data(client, reg_sqw, reg);
if (ret < 0)
return ret;
return -EINVAL;
}
static int m41t80_sqw_control(struct clk_hw *hw, bool enable)
{
struct m41t80_data *m41t80 = sqw_to_m41t80_data(hw);
struct i2c_client *client = m41t80->client;
int ret = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (ret < 0)
return ret;
if (enable)
ret |= M41T80_ALMON_SQWE;
else
ret &= ~M41T80_ALMON_SQWE;
return i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON, ret);
}
static int m41t80_sqw_prepare(struct clk_hw *hw)
{
return m41t80_sqw_control(hw, 1);
}
static void m41t80_sqw_unprepare(struct clk_hw *hw)
{
m41t80_sqw_control(hw, 0);
}
static int m41t80_sqw_is_prepared(struct clk_hw *hw)
{
struct m41t80_data *m41t80 = sqw_to_m41t80_data(hw);
struct i2c_client *client = m41t80->client;
int ret = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (ret < 0)
return ret;
return !!(ret & M41T80_ALMON_SQWE);
}
static struct clk *m41t80_sqw_register_clk(struct m41t80_data *m41t80)
{
struct i2c_client *client = m41t80->client;
struct device_node *node = client->dev.of_node;
struct clk *clk;
struct clk_init_data init;
int ret;
ret = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_MON);
if (ret < 0)
return ERR_PTR(ret);
ret = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_MON,
ret & ~(M41T80_ALMON_SQWE));
if (ret < 0)
return ERR_PTR(ret);
init.name = "m41t80-sqw";
init.ops = &m41t80_sqw_ops;
init.flags = 0;
init.parent_names = NULL;
init.num_parents = 0;
m41t80->sqw.init = &init;
of_property_read_string(node, "clock-output-names", &init.name);
clk = clk_register(&client->dev, &m41t80->sqw);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
return clk;
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
i2c_data[1] = wdt_margin << 2 | 0x82;
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
pr_info("disable watchdog\n");
wdt_disable();
}
if (rv & WDIOS_ENABLECARD) {
pr_info("enable watchdog\n");
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
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
int rc = 0;
struct rtc_device *rtc = NULL;
struct rtc_time tm;
struct m41t80_data *m41t80_data = NULL;
bool wakeup_source = false;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_I2C_BLOCK |
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&adapter->dev, "doesn't support I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_I2C_BLOCK\n");
return -ENODEV;
}
m41t80_data = devm_kzalloc(&client->dev, sizeof(*m41t80_data),
GFP_KERNEL);
if (!m41t80_data)
return -ENOMEM;
m41t80_data->client = client;
if (client->dev.of_node)
m41t80_data->features = (unsigned long)
of_device_get_match_data(&client->dev);
else
m41t80_data->features = id->driver_data;
i2c_set_clientdata(client, m41t80_data);
#ifdef CONFIG_OF
wakeup_source = of_property_read_bool(client->dev.of_node,
"wakeup-source");
#endif
if (client->irq > 0) {
rc = devm_request_threaded_irq(&client->dev, client->irq,
NULL, m41t80_handle_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"m41t80", client);
if (rc) {
dev_warn(&client->dev, "unable to request IRQ, alarms disabled\n");
client->irq = 0;
wakeup_source = false;
}
}
if (client->irq > 0 || wakeup_source) {
m41t80_rtc_ops.read_alarm = m41t80_read_alarm;
m41t80_rtc_ops.set_alarm = m41t80_set_alarm;
m41t80_rtc_ops.alarm_irq_enable = m41t80_alarm_irq_enable;
device_init_wakeup(&client->dev, true);
}
rtc = devm_rtc_device_register(&client->dev, client->name,
&m41t80_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
m41t80_data->rtc = rtc;
if (client->irq <= 0) {
rtc->uie_unsupported = 1;
}
rc = i2c_smbus_read_byte_data(client, M41T80_REG_ALARM_HOUR);
if (rc >= 0 && rc & M41T80_ALHOUR_HT) {
if (m41t80_data->features & M41T80_FEATURE_HT) {
m41t80_get_datetime(client, &tm);
dev_info(&client->dev, "HT bit was set!\n");
dev_info(&client->dev,
"Power Down at %04i-%02i-%02i %02i:%02i:%02i\n",
tm.tm_year + 1900,
tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
tm.tm_min, tm.tm_sec);
}
rc = i2c_smbus_write_byte_data(client, M41T80_REG_ALARM_HOUR,
rc & ~M41T80_ALHOUR_HT);
}
if (rc < 0) {
dev_err(&client->dev, "Can't clear HT bit\n");
return rc;
}
rc = i2c_smbus_read_byte_data(client, M41T80_REG_SEC);
if (rc >= 0 && rc & M41T80_SEC_ST)
rc = i2c_smbus_write_byte_data(client, M41T80_REG_SEC,
rc & ~M41T80_SEC_ST);
if (rc < 0) {
dev_err(&client->dev, "Can't clear ST bit\n");
return rc;
}
#ifdef CONFIG_RTC_DRV_M41T80_WDT
if (m41t80_data->features & M41T80_FEATURE_HT) {
save_client = client;
rc = misc_register(&wdt_dev);
if (rc)
return rc;
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
misc_deregister(&wdt_dev);
return rc;
}
}
#endif
#ifdef CONFIG_COMMON_CLK
if (m41t80_data->features & M41T80_FEATURE_SQ)
m41t80_sqw_register_clk(m41t80_data);
#endif
return 0;
}
static int m41t80_remove(struct i2c_client *client)
{
#ifdef CONFIG_RTC_DRV_M41T80_WDT
struct m41t80_data *clientdata = i2c_get_clientdata(client);
if (clientdata->features & M41T80_FEATURE_HT) {
misc_deregister(&wdt_dev);
unregister_reboot_notifier(&wdt_notifier);
}
#endif
return 0;
}
