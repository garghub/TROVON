static int abx80x_enable_trickle_charger(struct i2c_client *client,
u8 trickle_cfg)
{
int err;
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_CFG_KEY,
ABX8XX_CFG_KEY_MISC);
if (err < 0) {
dev_err(&client->dev, "Unable to write configuration key\n");
return -EIO;
}
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_TRICKLE,
ABX8XX_TRICKLE_CHARGE_ENABLE |
trickle_cfg);
if (err < 0) {
dev_err(&client->dev, "Unable to write trickle register\n");
return -EIO;
}
return 0;
}
static int abx80x_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[8];
int err;
err = i2c_smbus_read_i2c_block_data(client, ABX8XX_REG_HTH,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to read date\n");
return -EIO;
}
tm->tm_sec = bcd2bin(buf[ABX8XX_REG_SC] & 0x7F);
tm->tm_min = bcd2bin(buf[ABX8XX_REG_MN] & 0x7F);
tm->tm_hour = bcd2bin(buf[ABX8XX_REG_HR] & 0x3F);
tm->tm_wday = buf[ABX8XX_REG_WD] & 0x7;
tm->tm_mday = bcd2bin(buf[ABX8XX_REG_DA] & 0x3F);
tm->tm_mon = bcd2bin(buf[ABX8XX_REG_MO] & 0x1F) - 1;
tm->tm_year = bcd2bin(buf[ABX8XX_REG_YR]) + 100;
err = rtc_valid_tm(tm);
if (err < 0)
dev_err(&client->dev, "retrieved date/time is not valid.\n");
return err;
}
static int abx80x_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[8];
int err;
if (tm->tm_year < 100)
return -EINVAL;
buf[ABX8XX_REG_HTH] = 0;
buf[ABX8XX_REG_SC] = bin2bcd(tm->tm_sec);
buf[ABX8XX_REG_MN] = bin2bcd(tm->tm_min);
buf[ABX8XX_REG_HR] = bin2bcd(tm->tm_hour);
buf[ABX8XX_REG_DA] = bin2bcd(tm->tm_mday);
buf[ABX8XX_REG_MO] = bin2bcd(tm->tm_mon + 1);
buf[ABX8XX_REG_YR] = bin2bcd(tm->tm_year - 100);
buf[ABX8XX_REG_WD] = tm->tm_wday;
err = i2c_smbus_write_i2c_block_data(client, ABX8XX_REG_HTH,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to write to date registers\n");
return -EIO;
}
return 0;
}
static int abx80x_dt_trickle_cfg(struct device_node *np)
{
const char *diode;
int trickle_cfg = 0;
int i, ret;
u32 tmp;
ret = of_property_read_string(np, "abracon,tc-diode", &diode);
if (ret)
return ret;
if (!strcmp(diode, "standard"))
trickle_cfg |= ABX8XX_TRICKLE_STANDARD_DIODE;
else if (!strcmp(diode, "schottky"))
trickle_cfg |= ABX8XX_TRICKLE_SCHOTTKY_DIODE;
else
return -EINVAL;
ret = of_property_read_u32(np, "abracon,tc-resistor", &tmp);
if (ret)
return ret;
for (i = 0; i < sizeof(trickle_resistors); i++)
if (trickle_resistors[i] == tmp)
break;
if (i == sizeof(trickle_resistors))
return -EINVAL;
return (trickle_cfg | i);
}
static int abx80x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node;
struct rtc_device *rtc;
int i, data, err, trickle_cfg = -EINVAL;
char buf[7];
unsigned int part = id->driver_data;
unsigned int partnumber;
unsigned int majrev, minrev;
unsigned int lot;
unsigned int wafer;
unsigned int uid;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
err = i2c_smbus_read_i2c_block_data(client, ABX8XX_REG_ID0,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to read partnumber\n");
return -EIO;
}
partnumber = (buf[0] << 8) | buf[1];
majrev = buf[2] >> 3;
minrev = buf[2] & 0x7;
lot = ((buf[4] & 0x80) << 2) | ((buf[6] & 0x80) << 1) | buf[3];
uid = ((buf[4] & 0x7f) << 8) | buf[5];
wafer = (buf[6] & 0x7c) >> 2;
dev_info(&client->dev, "model %04x, revision %u.%u, lot %x, wafer %x, uid %x\n",
partnumber, majrev, minrev, lot, wafer, uid);
data = i2c_smbus_read_byte_data(client, ABX8XX_REG_CTRL1);
if (data < 0) {
dev_err(&client->dev, "Unable to read control register\n");
return -EIO;
}
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_CTRL1,
((data & ~ABX8XX_CTRL_12_24) |
ABX8XX_CTRL_WRITE));
if (err < 0) {
dev_err(&client->dev, "Unable to write control register\n");
return -EIO;
}
if (part == ABX80X) {
for (i = 0; abx80x_caps[i].pn; i++)
if (partnumber == abx80x_caps[i].pn)
break;
if (abx80x_caps[i].pn == 0) {
dev_err(&client->dev, "Unknown part: %04x\n",
partnumber);
return -EINVAL;
}
part = i;
}
if (partnumber != abx80x_caps[part].pn) {
dev_err(&client->dev, "partnumber mismatch %04x != %04x\n",
partnumber, abx80x_caps[part].pn);
return -EINVAL;
}
if (np && abx80x_caps[part].has_tc)
trickle_cfg = abx80x_dt_trickle_cfg(np);
if (trickle_cfg > 0) {
dev_info(&client->dev, "Enabling trickle charger: %02x\n",
trickle_cfg);
abx80x_enable_trickle_charger(client, trickle_cfg);
}
rtc = devm_rtc_device_register(&client->dev, abx80x_driver.driver.name,
&abx80x_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
return 0;
}
static int abx80x_remove(struct i2c_client *client)
{
return 0;
}
