static int s35390a_set_reg(struct s35390a *s35390a, int reg, char *buf, int len)
{
struct i2c_client *client = s35390a->client[reg];
struct i2c_msg msg[] = {
{
.addr = client->addr,
.len = len,
.buf = buf
},
};
if ((i2c_transfer(client->adapter, msg, 1)) != 1)
return -EIO;
return 0;
}
static int s35390a_get_reg(struct s35390a *s35390a, int reg, char *buf, int len)
{
struct i2c_client *client = s35390a->client[reg];
struct i2c_msg msg[] = {
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = len,
.buf = buf
},
};
if ((i2c_transfer(client->adapter, msg, 1)) != 1)
return -EIO;
return 0;
}
static int s35390a_reset(struct s35390a *s35390a)
{
char buf[1];
if (s35390a_get_reg(s35390a, S35390A_CMD_STATUS1, buf, sizeof(buf)) < 0)
return -EIO;
if (!(buf[0] & (S35390A_FLAG_POC | S35390A_FLAG_BLD)))
return 0;
buf[0] |= (S35390A_FLAG_RESET | S35390A_FLAG_24H);
buf[0] &= 0xf0;
return s35390a_set_reg(s35390a, S35390A_CMD_STATUS1, buf, sizeof(buf));
}
static int s35390a_disable_test_mode(struct s35390a *s35390a)
{
char buf[1];
if (s35390a_get_reg(s35390a, S35390A_CMD_STATUS2, buf, sizeof(buf)) < 0)
return -EIO;
if (!(buf[0] & S35390A_FLAG_TEST))
return 0;
buf[0] &= ~S35390A_FLAG_TEST;
return s35390a_set_reg(s35390a, S35390A_CMD_STATUS2, buf, sizeof(buf));
}
static char s35390a_hr2reg(struct s35390a *s35390a, int hour)
{
if (s35390a->twentyfourhour)
return bin2bcd(hour);
if (hour < 12)
return bin2bcd(hour);
return 0x40 | bin2bcd(hour - 12);
}
static int s35390a_reg2hr(struct s35390a *s35390a, char reg)
{
unsigned hour;
if (s35390a->twentyfourhour)
return bcd2bin(reg & 0x3f);
hour = bcd2bin(reg & 0x3f);
if (reg & 0x40)
hour += 12;
return hour;
}
static int s35390a_set_datetime(struct i2c_client *client, struct rtc_time *tm)
{
struct s35390a *s35390a = i2c_get_clientdata(client);
int i, err;
char buf[7];
dev_dbg(&client->dev, "%s: tm is secs=%d, mins=%d, hours=%d mday=%d, "
"mon=%d, year=%d, wday=%d\n", __func__, tm->tm_sec,
tm->tm_min, tm->tm_hour, tm->tm_mday, tm->tm_mon, tm->tm_year,
tm->tm_wday);
buf[S35390A_BYTE_YEAR] = bin2bcd(tm->tm_year - 100);
buf[S35390A_BYTE_MONTH] = bin2bcd(tm->tm_mon + 1);
buf[S35390A_BYTE_DAY] = bin2bcd(tm->tm_mday);
buf[S35390A_BYTE_WDAY] = bin2bcd(tm->tm_wday);
buf[S35390A_BYTE_HOURS] = s35390a_hr2reg(s35390a, tm->tm_hour);
buf[S35390A_BYTE_MINS] = bin2bcd(tm->tm_min);
buf[S35390A_BYTE_SECS] = bin2bcd(tm->tm_sec);
for (i = 0; i < 7; ++i)
buf[i] = bitrev8(buf[i]);
err = s35390a_set_reg(s35390a, S35390A_CMD_TIME1, buf, sizeof(buf));
return err;
}
static int s35390a_get_datetime(struct i2c_client *client, struct rtc_time *tm)
{
struct s35390a *s35390a = i2c_get_clientdata(client);
char buf[7];
int i, err;
err = s35390a_get_reg(s35390a, S35390A_CMD_TIME1, buf, sizeof(buf));
if (err < 0)
return err;
for (i = 0; i < 7; ++i)
buf[i] = bitrev8(buf[i]);
tm->tm_sec = bcd2bin(buf[S35390A_BYTE_SECS]);
tm->tm_min = bcd2bin(buf[S35390A_BYTE_MINS]);
tm->tm_hour = s35390a_reg2hr(s35390a, buf[S35390A_BYTE_HOURS]);
tm->tm_wday = bcd2bin(buf[S35390A_BYTE_WDAY]);
tm->tm_mday = bcd2bin(buf[S35390A_BYTE_DAY]);
tm->tm_mon = bcd2bin(buf[S35390A_BYTE_MONTH]) - 1;
tm->tm_year = bcd2bin(buf[S35390A_BYTE_YEAR]) + 100;
dev_dbg(&client->dev, "%s: tm is secs=%d, mins=%d, hours=%d, mday=%d, "
"mon=%d, year=%d, wday=%d\n", __func__, tm->tm_sec,
tm->tm_min, tm->tm_hour, tm->tm_mday, tm->tm_mon, tm->tm_year,
tm->tm_wday);
return rtc_valid_tm(tm);
}
static int s35390a_set_alarm(struct i2c_client *client, struct rtc_wkalrm *alm)
{
struct s35390a *s35390a = i2c_get_clientdata(client);
char buf[3], sts = 0;
int err, i;
dev_dbg(&client->dev, "%s: alm is secs=%d, mins=%d, hours=%d mday=%d, "\
"mon=%d, year=%d, wday=%d\n", __func__, alm->time.tm_sec,
alm->time.tm_min, alm->time.tm_hour, alm->time.tm_mday,
alm->time.tm_mon, alm->time.tm_year, alm->time.tm_wday);
err = s35390a_set_reg(s35390a, S35390A_CMD_STATUS2, &sts, sizeof(sts));
if (err < 0)
return err;
err = s35390a_get_reg(s35390a, S35390A_CMD_STATUS1, &sts, sizeof(sts));
if (err < 0)
return err;
if (alm->enabled)
sts = S35390A_INT2_MODE_ALARM;
else
sts = S35390A_INT2_MODE_NOINTR;
sts = bitrev8(sts);
err = s35390a_set_reg(s35390a, S35390A_CMD_STATUS2, &sts, sizeof(sts));
if (err < 0)
return err;
if (alm->time.tm_wday != -1)
buf[S35390A_ALRM_BYTE_WDAY] = bin2bcd(alm->time.tm_wday) | 0x80;
buf[S35390A_ALRM_BYTE_HOURS] = s35390a_hr2reg(s35390a,
alm->time.tm_hour) | 0x80;
buf[S35390A_ALRM_BYTE_MINS] = bin2bcd(alm->time.tm_min) | 0x80;
if (alm->time.tm_hour >= 12)
buf[S35390A_ALRM_BYTE_HOURS] |= 0x40;
for (i = 0; i < 3; ++i)
buf[i] = bitrev8(buf[i]);
err = s35390a_set_reg(s35390a, S35390A_CMD_INT2_REG1, buf,
sizeof(buf));
return err;
}
static int s35390a_read_alarm(struct i2c_client *client, struct rtc_wkalrm *alm)
{
struct s35390a *s35390a = i2c_get_clientdata(client);
char buf[3], sts;
int i, err;
err = s35390a_get_reg(s35390a, S35390A_CMD_STATUS2, &sts, sizeof(sts));
if (err < 0)
return err;
if (bitrev8(sts) != S35390A_INT2_MODE_ALARM)
return -EINVAL;
err = s35390a_get_reg(s35390a, S35390A_CMD_INT2_REG1, buf, sizeof(buf));
if (err < 0)
return err;
for (i = 0; i < 3; ++i) {
buf[i] = bitrev8(buf[i]);
buf[i] &= ~0x80;
}
alm->time.tm_wday = bcd2bin(buf[S35390A_ALRM_BYTE_WDAY]);
alm->time.tm_hour = s35390a_reg2hr(s35390a,
buf[S35390A_ALRM_BYTE_HOURS]);
alm->time.tm_min = bcd2bin(buf[S35390A_ALRM_BYTE_MINS]);
dev_dbg(&client->dev, "%s: alm is mins=%d, hours=%d, wday=%d\n",
__func__, alm->time.tm_min, alm->time.tm_hour,
alm->time.tm_wday);
return 0;
}
static int s35390a_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
return s35390a_read_alarm(to_i2c_client(dev), alm);
}
static int s35390a_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
return s35390a_set_alarm(to_i2c_client(dev), alm);
}
static int s35390a_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return s35390a_get_datetime(to_i2c_client(dev), tm);
}
static int s35390a_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return s35390a_set_datetime(to_i2c_client(dev), tm);
}
static int s35390a_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err;
unsigned int i;
struct s35390a *s35390a;
struct rtc_time tm;
char buf[1];
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
err = -ENODEV;
goto exit;
}
s35390a = kzalloc(sizeof(struct s35390a), GFP_KERNEL);
if (!s35390a) {
err = -ENOMEM;
goto exit;
}
s35390a->client[0] = client;
i2c_set_clientdata(client, s35390a);
for (i = 1; i < 8; ++i) {
s35390a->client[i] = i2c_new_dummy(client->adapter,
client->addr + i);
if (!s35390a->client[i]) {
dev_err(&client->dev, "Address %02x unavailable\n",
client->addr + i);
err = -EBUSY;
goto exit_dummy;
}
}
err = s35390a_reset(s35390a);
if (err < 0) {
dev_err(&client->dev, "error resetting chip\n");
goto exit_dummy;
}
err = s35390a_disable_test_mode(s35390a);
if (err < 0) {
dev_err(&client->dev, "error disabling test mode\n");
goto exit_dummy;
}
err = s35390a_get_reg(s35390a, S35390A_CMD_STATUS1, buf, sizeof(buf));
if (err < 0) {
dev_err(&client->dev, "error checking 12/24 hour mode\n");
goto exit_dummy;
}
if (buf[0] & S35390A_FLAG_24H)
s35390a->twentyfourhour = 1;
else
s35390a->twentyfourhour = 0;
if (s35390a_get_datetime(client, &tm) < 0)
dev_warn(&client->dev, "clock needs to be set\n");
device_set_wakeup_capable(&client->dev, 1);
s35390a->rtc = rtc_device_register(s35390a_driver.driver.name,
&client->dev, &s35390a_rtc_ops, THIS_MODULE);
if (IS_ERR(s35390a->rtc)) {
err = PTR_ERR(s35390a->rtc);
goto exit_dummy;
}
return 0;
exit_dummy:
for (i = 1; i < 8; ++i)
if (s35390a->client[i])
i2c_unregister_device(s35390a->client[i]);
kfree(s35390a);
exit:
return err;
}
static int s35390a_remove(struct i2c_client *client)
{
unsigned int i;
struct s35390a *s35390a = i2c_get_clientdata(client);
for (i = 1; i < 8; ++i)
if (s35390a->client[i])
i2c_unregister_device(s35390a->client[i]);
rtc_device_unregister(s35390a->rtc);
kfree(s35390a);
return 0;
}
