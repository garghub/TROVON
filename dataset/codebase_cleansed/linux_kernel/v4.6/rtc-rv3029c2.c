static int
rv3029_i2c_read_regs(struct i2c_client *client, u8 reg, u8 *buf,
unsigned len)
{
int ret;
if ((reg > RV3029_USR1_RAM_PAGE + 7) ||
(reg + len > RV3029_USR1_RAM_PAGE + 8))
return -EINVAL;
ret = i2c_smbus_read_i2c_block_data(client, reg, len, buf);
if (ret < 0)
return ret;
if (ret < len)
return -EIO;
return 0;
}
static int
rv3029_i2c_write_regs(struct i2c_client *client, u8 reg, u8 const buf[],
unsigned len)
{
if ((reg > RV3029_USR1_RAM_PAGE + 7) ||
(reg + len > RV3029_USR1_RAM_PAGE + 8))
return -EINVAL;
return i2c_smbus_write_i2c_block_data(client, reg, len, buf);
}
static int
rv3029_i2c_update_bits(struct i2c_client *client, u8 reg, u8 mask, u8 set)
{
u8 buf;
int ret;
ret = rv3029_i2c_read_regs(client, reg, &buf, 1);
if (ret < 0)
return ret;
buf &= ~mask;
buf |= set & mask;
ret = rv3029_i2c_write_regs(client, reg, &buf, 1);
if (ret < 0)
return ret;
return 0;
}
static int
rv3029_i2c_get_sr(struct i2c_client *client, u8 *buf)
{
int ret = rv3029_i2c_read_regs(client, RV3029_STATUS, buf, 1);
if (ret < 0)
return -EIO;
dev_dbg(&client->dev, "status = 0x%.2x (%d)\n", buf[0], buf[0]);
return 0;
}
static int
rv3029_i2c_set_sr(struct i2c_client *client, u8 val)
{
u8 buf[1];
int sr;
buf[0] = val;
sr = rv3029_i2c_write_regs(client, RV3029_STATUS, buf, 1);
dev_dbg(&client->dev, "status = 0x%.2x (%d)\n", buf[0], buf[0]);
if (sr < 0)
return -EIO;
return 0;
}
static int rv3029_eeprom_busywait(struct i2c_client *client)
{
int i, ret;
u8 sr;
for (i = 100; i > 0; i--) {
ret = rv3029_i2c_get_sr(client, &sr);
if (ret < 0)
break;
if (!(sr & RV3029_STATUS_EEBUSY))
break;
usleep_range(1000, 10000);
}
if (i <= 0) {
dev_err(&client->dev, "EEPROM busy wait timeout.\n");
return -ETIMEDOUT;
}
return ret;
}
static int rv3029_eeprom_exit(struct i2c_client *client)
{
return rv3029_i2c_update_bits(client, RV3029_ONOFF_CTRL,
RV3029_ONOFF_CTRL_EERE,
RV3029_ONOFF_CTRL_EERE);
}
static int rv3029_eeprom_enter(struct i2c_client *client)
{
int ret;
u8 sr;
ret = rv3029_i2c_get_sr(client, &sr);
if (ret < 0)
return ret;
if (sr & (RV3029_STATUS_VLOW1 | RV3029_STATUS_VLOW2)) {
sr &= ~RV3029_STATUS_VLOW1;
sr &= ~RV3029_STATUS_VLOW2;
ret = rv3029_i2c_set_sr(client, sr);
if (ret < 0)
return ret;
usleep_range(1000, 10000);
ret = rv3029_i2c_get_sr(client, &sr);
if (ret < 0)
return ret;
if (sr & (RV3029_STATUS_VLOW1 | RV3029_STATUS_VLOW2)) {
dev_err(&client->dev,
"Supply voltage is too low to safely access the EEPROM.\n");
return -ENODEV;
}
}
ret = rv3029_i2c_update_bits(client, RV3029_ONOFF_CTRL,
RV3029_ONOFF_CTRL_EERE, 0);
if (ret < 0)
return ret;
ret = rv3029_eeprom_busywait(client);
if (ret < 0)
rv3029_eeprom_exit(client);
return ret;
}
static int rv3029_eeprom_read(struct i2c_client *client, u8 reg,
u8 buf[], size_t len)
{
int ret, err;
err = rv3029_eeprom_enter(client);
if (err < 0)
return err;
ret = rv3029_i2c_read_regs(client, reg, buf, len);
err = rv3029_eeprom_exit(client);
if (err < 0)
return err;
return ret;
}
static int rv3029_eeprom_write(struct i2c_client *client, u8 reg,
u8 const buf[], size_t len)
{
int ret, err;
size_t i;
u8 tmp;
err = rv3029_eeprom_enter(client);
if (err < 0)
return err;
for (i = 0; i < len; i++, reg++) {
ret = rv3029_i2c_read_regs(client, reg, &tmp, 1);
if (ret < 0)
break;
if (tmp != buf[i]) {
ret = rv3029_i2c_write_regs(client, reg, &buf[i], 1);
if (ret < 0)
break;
}
ret = rv3029_eeprom_busywait(client);
if (ret < 0)
break;
}
err = rv3029_eeprom_exit(client);
if (err < 0)
return err;
return ret;
}
static int rv3029_eeprom_update_bits(struct i2c_client *client,
u8 reg, u8 mask, u8 set)
{
u8 buf;
int ret;
ret = rv3029_eeprom_read(client, reg, &buf, 1);
if (ret < 0)
return ret;
buf &= ~mask;
buf |= set & mask;
ret = rv3029_eeprom_write(client, reg, &buf, 1);
if (ret < 0)
return ret;
return 0;
}
static int
rv3029_i2c_read_time(struct i2c_client *client, struct rtc_time *tm)
{
u8 buf[1];
int ret;
u8 regs[RV3029_WATCH_SECTION_LEN] = { 0, };
ret = rv3029_i2c_get_sr(client, buf);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return -EIO;
}
ret = rv3029_i2c_read_regs(client, RV3029_W_SEC, regs,
RV3029_WATCH_SECTION_LEN);
if (ret < 0) {
dev_err(&client->dev, "%s: reading RTC section failed\n",
__func__);
return ret;
}
tm->tm_sec = bcd2bin(regs[RV3029_W_SEC-RV3029_W_SEC]);
tm->tm_min = bcd2bin(regs[RV3029_W_MINUTES-RV3029_W_SEC]);
{
const u8 _hr = regs[RV3029_W_HOURS-RV3029_W_SEC];
if (_hr & RV3029_REG_HR_12_24) {
tm->tm_hour = bcd2bin(_hr & 0x1f);
if (_hr & RV3029_REG_HR_PM)
tm->tm_hour += 12;
} else
tm->tm_hour = bcd2bin(_hr & 0x3f);
}
tm->tm_mday = bcd2bin(regs[RV3029_W_DATE-RV3029_W_SEC]);
tm->tm_mon = bcd2bin(regs[RV3029_W_MONTHS-RV3029_W_SEC]) - 1;
tm->tm_year = bcd2bin(regs[RV3029_W_YEARS-RV3029_W_SEC]) + 100;
tm->tm_wday = bcd2bin(regs[RV3029_W_DAYS-RV3029_W_SEC]) - 1;
return 0;
}
static int rv3029_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return rv3029_i2c_read_time(to_i2c_client(dev), tm);
}
static int
rv3029_i2c_read_alarm(struct i2c_client *client, struct rtc_wkalrm *alarm)
{
struct rtc_time *const tm = &alarm->time;
int ret;
u8 regs[8];
ret = rv3029_i2c_get_sr(client, regs);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return -EIO;
}
ret = rv3029_i2c_read_regs(client, RV3029_A_SC, regs,
RV3029_ALARM_SECTION_LEN);
if (ret < 0) {
dev_err(&client->dev, "%s: reading alarm section failed\n",
__func__);
return ret;
}
tm->tm_sec = bcd2bin(regs[RV3029_A_SC-RV3029_A_SC] & 0x7f);
tm->tm_min = bcd2bin(regs[RV3029_A_MN-RV3029_A_SC] & 0x7f);
tm->tm_hour = bcd2bin(regs[RV3029_A_HR-RV3029_A_SC] & 0x3f);
tm->tm_mday = bcd2bin(regs[RV3029_A_DT-RV3029_A_SC] & 0x3f);
tm->tm_mon = bcd2bin(regs[RV3029_A_MO-RV3029_A_SC] & 0x1f) - 1;
tm->tm_year = bcd2bin(regs[RV3029_A_YR-RV3029_A_SC] & 0x7f) + 100;
tm->tm_wday = bcd2bin(regs[RV3029_A_DW-RV3029_A_SC] & 0x07) - 1;
return 0;
}
static int
rv3029_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
return rv3029_i2c_read_alarm(to_i2c_client(dev), alarm);
}
static int rv3029_rtc_i2c_alarm_set_irq(struct i2c_client *client,
int enable)
{
int ret;
ret = rv3029_i2c_update_bits(client, RV3029_IRQ_CTRL,
RV3029_IRQ_CTRL_AIE,
(enable ? RV3029_IRQ_CTRL_AIE : 0));
if (ret < 0) {
dev_err(&client->dev, "can't update INT reg\n");
return ret;
}
return 0;
}
static int rv3029_rtc_i2c_set_alarm(struct i2c_client *client,
struct rtc_wkalrm *alarm)
{
struct rtc_time *const tm = &alarm->time;
int ret;
u8 regs[8];
if (tm->tm_year < 100)
return -EINVAL;
ret = rv3029_i2c_get_sr(client, regs);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return -EIO;
}
regs[RV3029_A_SC-RV3029_A_SC] = bin2bcd(tm->tm_sec & 0x7f);
regs[RV3029_A_MN-RV3029_A_SC] = bin2bcd(tm->tm_min & 0x7f);
regs[RV3029_A_HR-RV3029_A_SC] = bin2bcd(tm->tm_hour & 0x3f);
regs[RV3029_A_DT-RV3029_A_SC] = bin2bcd(tm->tm_mday & 0x3f);
regs[RV3029_A_MO-RV3029_A_SC] = bin2bcd((tm->tm_mon & 0x1f) - 1);
regs[RV3029_A_DW-RV3029_A_SC] = bin2bcd((tm->tm_wday & 7) - 1);
regs[RV3029_A_YR-RV3029_A_SC] = bin2bcd((tm->tm_year & 0x7f) - 100);
ret = rv3029_i2c_write_regs(client, RV3029_A_SC, regs,
RV3029_ALARM_SECTION_LEN);
if (ret < 0)
return ret;
if (alarm->enabled) {
ret = rv3029_i2c_update_bits(client, RV3029_IRQ_FLAGS,
RV3029_IRQ_FLAGS_AF, 0);
if (ret < 0) {
dev_err(&client->dev, "can't clear alarm flag\n");
return ret;
}
ret = rv3029_rtc_i2c_alarm_set_irq(client, 1);
if (ret)
return ret;
dev_dbg(&client->dev, "alarm IRQ armed\n");
} else {
ret = rv3029_rtc_i2c_alarm_set_irq(client, 0);
if (ret)
return ret;
dev_dbg(&client->dev, "alarm IRQ disabled\n");
}
return 0;
}
static int rv3029_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
return rv3029_rtc_i2c_set_alarm(to_i2c_client(dev), alarm);
}
static int
rv3029_i2c_set_time(struct i2c_client *client, struct rtc_time const *tm)
{
u8 regs[8];
int ret;
if (tm->tm_year < 100)
return -EINVAL;
regs[RV3029_W_SEC-RV3029_W_SEC] = bin2bcd(tm->tm_sec);
regs[RV3029_W_MINUTES-RV3029_W_SEC] = bin2bcd(tm->tm_min);
regs[RV3029_W_HOURS-RV3029_W_SEC] = bin2bcd(tm->tm_hour);
regs[RV3029_W_DATE-RV3029_W_SEC] = bin2bcd(tm->tm_mday);
regs[RV3029_W_MONTHS-RV3029_W_SEC] = bin2bcd(tm->tm_mon+1);
regs[RV3029_W_DAYS-RV3029_W_SEC] = bin2bcd((tm->tm_wday & 7)+1);
regs[RV3029_W_YEARS-RV3029_W_SEC] = bin2bcd(tm->tm_year - 100);
ret = rv3029_i2c_write_regs(client, RV3029_W_SEC, regs,
RV3029_WATCH_SECTION_LEN);
if (ret < 0)
return ret;
ret = rv3029_i2c_get_sr(client, regs);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return ret;
}
ret = rv3029_i2c_set_sr(client, (regs[0] & ~RV3029_STATUS_PON));
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return ret;
}
return 0;
}
static int rv3029_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return rv3029_i2c_set_time(to_i2c_client(dev), tm);
}
static void rv3029_trickle_config(struct i2c_client *client)
{
struct device_node *of_node = client->dev.of_node;
const struct rv3029_trickle_tab_elem *elem;
int i, err;
u32 ohms;
u8 trickle_set_bits;
if (!of_node)
return;
err = of_property_read_u32(of_node, "trickle-resistor-ohms", &ohms);
if (err) {
trickle_set_bits = 0;
} else {
for (i = 0; i < ARRAY_SIZE(rv3029_trickle_tab); i++) {
elem = &rv3029_trickle_tab[i];
if (elem->r >= ohms)
break;
}
trickle_set_bits = elem->conf;
dev_info(&client->dev,
"Trickle charger enabled at %d ohms resistance.\n",
elem->r);
}
err = rv3029_eeprom_update_bits(client, RV3029_CONTROL_E2P_EECTRL,
RV3029_TRICKLE_MASK,
trickle_set_bits);
if (err < 0) {
dev_err(&client->dev,
"Failed to update trickle charger config\n");
}
}
static int rv3029_read_temp(struct i2c_client *client, int *temp_mC)
{
int ret;
u8 temp;
ret = rv3029_i2c_read_regs(client, RV3029_TEMP_PAGE, &temp, 1);
if (ret < 0)
return ret;
*temp_mC = ((int)temp - 60) * 1000;
return 0;
}
static ssize_t rv3029_hwmon_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = dev_get_drvdata(dev);
int ret, temp_mC;
ret = rv3029_read_temp(client, &temp_mC);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", temp_mC);
}
static ssize_t rv3029_hwmon_set_update_interval(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct i2c_client *client = dev_get_drvdata(dev);
unsigned long interval_ms;
int ret;
u8 th_set_bits = 0;
ret = kstrtoul(buf, 10, &interval_ms);
if (ret < 0)
return ret;
if (interval_ms != 0) {
th_set_bits |= RV3029_EECTRL_THE;
if (interval_ms >= 16000)
th_set_bits |= RV3029_EECTRL_THP;
}
ret = rv3029_eeprom_update_bits(client, RV3029_CONTROL_E2P_EECTRL,
RV3029_EECTRL_THE | RV3029_EECTRL_THP,
th_set_bits);
if (ret < 0)
return ret;
return count;
}
static ssize_t rv3029_hwmon_show_update_interval(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = dev_get_drvdata(dev);
int ret, interval_ms;
u8 eectrl;
ret = rv3029_eeprom_read(client, RV3029_CONTROL_E2P_EECTRL,
&eectrl, 1);
if (ret < 0)
return ret;
if (eectrl & RV3029_EECTRL_THE) {
if (eectrl & RV3029_EECTRL_THP)
interval_ms = 16000;
else
interval_ms = 1000;
} else {
interval_ms = 0;
}
return sprintf(buf, "%d\n", interval_ms);
}
static void rv3029_hwmon_register(struct i2c_client *client)
{
struct device *hwmon_dev;
hwmon_dev = devm_hwmon_device_register_with_groups(
&client->dev, client->name, client, rv3029_hwmon_groups);
if (IS_ERR(hwmon_dev)) {
dev_warn(&client->dev,
"unable to register hwmon device %ld\n",
PTR_ERR(hwmon_dev));
}
}
static void rv3029_hwmon_register(struct i2c_client *client)
{
}
static int rv3029_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rtc_device *rtc;
int rc = 0;
u8 buf[1];
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_EMUL))
return -ENODEV;
rc = rv3029_i2c_get_sr(client, buf);
if (rc < 0) {
dev_err(&client->dev, "reading status failed\n");
return rc;
}
rv3029_trickle_config(client);
rv3029_hwmon_register(client);
rtc = devm_rtc_device_register(&client->dev, client->name,
&rv3029_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
return 0;
}
