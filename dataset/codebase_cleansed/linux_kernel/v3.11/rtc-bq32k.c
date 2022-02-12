static int bq32k_read(struct device *dev, void *data, uint8_t off, uint8_t len)
{
struct i2c_client *client = to_i2c_client(dev);
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &off,
}, {
.addr = client->addr,
.flags = I2C_M_RD,
.len = len,
.buf = data,
}
};
if (i2c_transfer(client->adapter, msgs, 2) == 2)
return 0;
return -EIO;
}
static int bq32k_write(struct device *dev, void *data, uint8_t off, uint8_t len)
{
struct i2c_client *client = to_i2c_client(dev);
uint8_t buffer[len + 1];
buffer[0] = off;
memcpy(&buffer[1], data, len);
if (i2c_master_send(client, buffer, len + 1) == len + 1)
return 0;
return -EIO;
}
static int bq32k_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct bq32k_regs regs;
int error;
error = bq32k_read(dev, &regs, 0, sizeof(regs));
if (error)
return error;
tm->tm_sec = bcd2bin(regs.seconds & BQ32K_SECONDS_MASK);
tm->tm_min = bcd2bin(regs.minutes & BQ32K_SECONDS_MASK);
tm->tm_hour = bcd2bin(regs.cent_hours & BQ32K_HOURS_MASK);
tm->tm_mday = bcd2bin(regs.date);
tm->tm_wday = bcd2bin(regs.day) - 1;
tm->tm_mon = bcd2bin(regs.month) - 1;
tm->tm_year = bcd2bin(regs.years) +
((regs.cent_hours & BQ32K_CENT) ? 100 : 0);
return rtc_valid_tm(tm);
}
static int bq32k_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct bq32k_regs regs;
regs.seconds = bin2bcd(tm->tm_sec);
regs.minutes = bin2bcd(tm->tm_min);
regs.cent_hours = bin2bcd(tm->tm_hour) | BQ32K_CENT_EN;
regs.day = bin2bcd(tm->tm_wday + 1);
regs.date = bin2bcd(tm->tm_mday);
regs.month = bin2bcd(tm->tm_mon + 1);
if (tm->tm_year >= 100) {
regs.cent_hours |= BQ32K_CENT;
regs.years = bin2bcd(tm->tm_year - 100);
} else
regs.years = bin2bcd(tm->tm_year);
return bq32k_write(dev, &regs, 0, sizeof(regs));
}
static int bq32k_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct rtc_device *rtc;
uint8_t reg;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
error = bq32k_read(dev, &reg, BQ32K_SECONDS, 1);
if (!error && (reg & BQ32K_STOP)) {
dev_warn(dev, "Oscillator was halted. Restarting...\n");
reg &= ~BQ32K_STOP;
error = bq32k_write(dev, &reg, BQ32K_SECONDS, 1);
}
if (error)
return error;
error = bq32k_read(dev, &reg, BQ32K_MINUTES, 1);
if (!error && (reg & BQ32K_OF)) {
dev_warn(dev, "Oscillator Failure. Check RTC battery.\n");
reg &= ~BQ32K_OF;
error = bq32k_write(dev, &reg, BQ32K_MINUTES, 1);
}
if (error)
return error;
rtc = devm_rtc_device_register(&client->dev, bq32k_driver.driver.name,
&bq32k_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
return 0;
}
