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
if (regs.minutes & BQ32K_OF)
return -EINVAL;
tm->tm_sec = bcd2bin(regs.seconds & BQ32K_SECONDS_MASK);
tm->tm_min = bcd2bin(regs.minutes & BQ32K_MINUTES_MASK);
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
static int trickle_charger_of_init(struct device *dev, struct device_node *node)
{
unsigned char reg;
int error;
u32 ohms = 0;
if (of_property_read_u32(node, "trickle-resistor-ohms" , &ohms))
return 0;
switch (ohms) {
case 180+940:
if (of_property_read_bool(node, "trickle-diode-disable")) {
dev_err(dev, "diode and resistor mismatch\n");
return -EINVAL;
}
reg = 0x05;
break;
case 180+20000:
if (!of_property_read_bool(node, "trickle-diode-disable")) {
dev_err(dev, "bq32k: diode and resistor mismatch\n");
return -EINVAL;
}
reg = 0x45;
break;
default:
dev_err(dev, "invalid resistor value (%d)\n", ohms);
return -EINVAL;
}
error = bq32k_write(dev, &reg, BQ32K_CFG2, 1);
if (error)
return error;
reg = 0x20;
error = bq32k_write(dev, &reg, BQ32K_TCH2, 1);
if (error)
return error;
dev_info(dev, "Enabled trickle RTC battery charge.\n");
return 0;
}
static ssize_t bq32k_sysfs_show_tricklecharge_bypass(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int reg, error;
error = bq32k_read(dev, &reg, BQ32K_CFG2, 1);
if (error)
return error;
return sprintf(buf, "%d\n", (reg & BQ32K_TCFE) ? 1 : 0);
}
static ssize_t bq32k_sysfs_store_tricklecharge_bypass(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int reg, enable, error;
if (kstrtoint(buf, 0, &enable))
return -EINVAL;
error = bq32k_read(dev, &reg, BQ32K_CFG2, 1);
if (error)
return error;
if (enable) {
reg |= BQ32K_TCFE;
error = bq32k_write(dev, &reg, BQ32K_CFG2, 1);
if (error)
return error;
dev_info(dev, "Enabled trickle charge FET bypass.\n");
} else {
reg &= ~BQ32K_TCFE;
error = bq32k_write(dev, &reg, BQ32K_CFG2, 1);
if (error)
return error;
dev_info(dev, "Disabled trickle charge FET bypass.\n");
}
return count;
}
static int bq32k_sysfs_register(struct device *dev)
{
return device_create_file(dev, &dev_attr_trickle_charge_bypass);
}
static void bq32k_sysfs_unregister(struct device *dev)
{
device_remove_file(dev, &dev_attr_trickle_charge_bypass);
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
if (error)
return error;
if (reg & BQ32K_OF)
dev_warn(dev, "Oscillator Failure. Check RTC battery.\n");
if (client->dev.of_node)
trickle_charger_of_init(dev, client->dev.of_node);
rtc = devm_rtc_device_register(&client->dev, bq32k_driver.driver.name,
&bq32k_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
error = bq32k_sysfs_register(&client->dev);
if (error) {
dev_err(&client->dev,
"Unable to create sysfs entries for rtc bq32000\n");
return error;
}
i2c_set_clientdata(client, rtc);
return 0;
}
static int bq32k_remove(struct i2c_client *client)
{
bq32k_sysfs_unregister(&client->dev);
return 0;
}
