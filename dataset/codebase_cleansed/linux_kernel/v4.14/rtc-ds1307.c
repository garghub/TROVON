static irqreturn_t ds1307_irq(int irq, void *dev_id)
{
struct ds1307 *ds1307 = dev_id;
struct mutex *lock = &ds1307->rtc->ops_lock;
int stat, ret;
mutex_lock(lock);
ret = regmap_read(ds1307->regmap, DS1337_REG_STATUS, &stat);
if (ret)
goto out;
if (stat & DS1337_BIT_A1I) {
stat &= ~DS1337_BIT_A1I;
regmap_write(ds1307->regmap, DS1337_REG_STATUS, stat);
ret = regmap_update_bits(ds1307->regmap, DS1337_REG_CONTROL,
DS1337_BIT_A1IE, 0);
if (ret)
goto out;
rtc_update_irq(ds1307->rtc, 1, RTC_AF | RTC_IRQF);
}
out:
mutex_unlock(lock);
return IRQ_HANDLED;
}
static int ds1307_get_time(struct device *dev, struct rtc_time *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
int tmp, ret;
const struct chip_desc *chip = &chips[ds1307->type];
u8 regs[7];
ret = regmap_bulk_read(ds1307->regmap, chip->offset, regs,
sizeof(regs));
if (ret) {
dev_err(dev, "%s error %d\n", "read", ret);
return ret;
}
dev_dbg(dev, "%s: %7ph\n", "read", regs);
if (ds1307->type == m41t0 &&
regs[DS1307_REG_MIN] & M41T0_BIT_OF) {
dev_warn_once(dev, "oscillator failed, set time!\n");
return -EINVAL;
}
t->tm_sec = bcd2bin(regs[DS1307_REG_SECS] & 0x7f);
t->tm_min = bcd2bin(regs[DS1307_REG_MIN] & 0x7f);
tmp = regs[DS1307_REG_HOUR] & 0x3f;
t->tm_hour = bcd2bin(tmp);
t->tm_wday = bcd2bin(regs[DS1307_REG_WDAY] & 0x07) - 1;
t->tm_mday = bcd2bin(regs[DS1307_REG_MDAY] & 0x3f);
tmp = regs[DS1307_REG_MONTH] & 0x1f;
t->tm_mon = bcd2bin(tmp) - 1;
t->tm_year = bcd2bin(regs[DS1307_REG_YEAR]) + 100;
if (regs[chip->century_reg] & chip->century_bit &&
IS_ENABLED(CONFIG_RTC_DRV_DS1307_CENTURY))
t->tm_year += 100;
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
const struct chip_desc *chip = &chips[ds1307->type];
int result;
int tmp;
u8 regs[7];
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"write", t->tm_sec, t->tm_min,
t->tm_hour, t->tm_mday,
t->tm_mon, t->tm_year, t->tm_wday);
if (t->tm_year < 100)
return -EINVAL;
#ifdef CONFIG_RTC_DRV_DS1307_CENTURY
if (t->tm_year > (chip->century_bit ? 299 : 199))
return -EINVAL;
#else
if (t->tm_year > 199)
return -EINVAL;
#endif
regs[DS1307_REG_SECS] = bin2bcd(t->tm_sec);
regs[DS1307_REG_MIN] = bin2bcd(t->tm_min);
regs[DS1307_REG_HOUR] = bin2bcd(t->tm_hour);
regs[DS1307_REG_WDAY] = bin2bcd(t->tm_wday + 1);
regs[DS1307_REG_MDAY] = bin2bcd(t->tm_mday);
regs[DS1307_REG_MONTH] = bin2bcd(t->tm_mon + 1);
tmp = t->tm_year - 100;
regs[DS1307_REG_YEAR] = bin2bcd(tmp);
if (chip->century_enable_bit)
regs[chip->century_reg] |= chip->century_enable_bit;
if (t->tm_year > 199 && chip->century_bit)
regs[chip->century_reg] |= chip->century_bit;
if (ds1307->type == mcp794xx) {
regs[DS1307_REG_SECS] |= MCP794XX_BIT_ST;
regs[DS1307_REG_WDAY] |= MCP794XX_BIT_VBATEN;
}
dev_dbg(dev, "%s: %7ph\n", "write", regs);
result = regmap_bulk_write(ds1307->regmap, chip->offset, regs,
sizeof(regs));
if (result) {
dev_err(dev, "%s error %d\n", "write", result);
return result;
}
return 0;
}
static int ds1337_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
int ret;
u8 regs[9];
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
ret = regmap_bulk_read(ds1307->regmap, DS1339_REG_ALARM1_SECS,
regs, sizeof(regs));
if (ret) {
dev_err(dev, "%s error %d\n", "alarm read", ret);
return ret;
}
dev_dbg(dev, "%s: %4ph, %3ph, %2ph\n", "alarm read",
&regs[0], &regs[4], &regs[7]);
t->time.tm_sec = bcd2bin(regs[0] & 0x7f);
t->time.tm_min = bcd2bin(regs[1] & 0x7f);
t->time.tm_hour = bcd2bin(regs[2] & 0x3f);
t->time.tm_mday = bcd2bin(regs[3] & 0x3f);
t->enabled = !!(regs[7] & DS1337_BIT_A1IE);
t->pending = !!(regs[8] & DS1337_BIT_A1I);
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, enabled=%d, pending=%d\n",
"alarm read", t->time.tm_sec, t->time.tm_min,
t->time.tm_hour, t->time.tm_mday,
t->enabled, t->pending);
return 0;
}
static int ds1337_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
unsigned char regs[9];
u8 control, status;
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, enabled=%d, pending=%d\n",
"alarm set", t->time.tm_sec, t->time.tm_min,
t->time.tm_hour, t->time.tm_mday,
t->enabled, t->pending);
ret = regmap_bulk_read(ds1307->regmap, DS1339_REG_ALARM1_SECS, regs,
sizeof(regs));
if (ret) {
dev_err(dev, "%s error %d\n", "alarm write", ret);
return ret;
}
control = regs[7];
status = regs[8];
dev_dbg(dev, "%s: %4ph, %3ph, %02x %02x\n", "alarm set (old status)",
&regs[0], &regs[4], control, status);
regs[0] = bin2bcd(t->time.tm_sec);
regs[1] = bin2bcd(t->time.tm_min);
regs[2] = bin2bcd(t->time.tm_hour);
regs[3] = bin2bcd(t->time.tm_mday);
regs[4] = 0;
regs[5] = 0;
regs[6] = 0;
regs[7] = control & ~(DS1337_BIT_A1IE | DS1337_BIT_A2IE);
regs[8] = status & ~(DS1337_BIT_A1I | DS1337_BIT_A2I);
ret = regmap_bulk_write(ds1307->regmap, DS1339_REG_ALARM1_SECS, regs,
sizeof(regs));
if (ret) {
dev_err(dev, "can't set alarm time\n");
return ret;
}
if (t->enabled) {
dev_dbg(dev, "alarm IRQ armed\n");
regs[7] |= DS1337_BIT_A1IE;
regmap_write(ds1307->regmap, DS1337_REG_CONTROL, regs[7]);
}
return 0;
}
static int ds1307_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -ENOTTY;
return regmap_update_bits(ds1307->regmap, DS1337_REG_CONTROL,
DS1337_BIT_A1IE,
enabled ? DS1337_BIT_A1IE : 0);
}
static irqreturn_t rx8130_irq(int irq, void *dev_id)
{
struct ds1307 *ds1307 = dev_id;
struct mutex *lock = &ds1307->rtc->ops_lock;
u8 ctl[3];
int ret;
mutex_lock(lock);
ret = regmap_bulk_read(ds1307->regmap, RX8130_REG_EXTENSION, ctl,
sizeof(ctl));
if (ret < 0)
goto out;
if (!(ctl[1] & RX8130_REG_FLAG_AF))
goto out;
ctl[1] &= ~RX8130_REG_FLAG_AF;
ctl[2] &= ~RX8130_REG_CONTROL0_AIE;
ret = regmap_bulk_write(ds1307->regmap, RX8130_REG_EXTENSION, ctl,
sizeof(ctl));
if (ret < 0)
goto out;
rtc_update_irq(ds1307->rtc, 1, RTC_AF | RTC_IRQF);
out:
mutex_unlock(lock);
return IRQ_HANDLED;
}
static int rx8130_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
u8 ald[3], ctl[3];
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
ret = regmap_bulk_read(ds1307->regmap, RX8130_REG_ALARM_MIN, ald,
sizeof(ald));
if (ret < 0)
return ret;
ret = regmap_bulk_read(ds1307->regmap, RX8130_REG_EXTENSION, ctl,
sizeof(ctl));
if (ret < 0)
return ret;
t->enabled = !!(ctl[2] & RX8130_REG_CONTROL0_AIE);
t->pending = !!(ctl[1] & RX8130_REG_FLAG_AF);
t->time.tm_sec = -1;
t->time.tm_min = bcd2bin(ald[0] & 0x7f);
t->time.tm_hour = bcd2bin(ald[1] & 0x7f);
t->time.tm_wday = -1;
t->time.tm_mday = bcd2bin(ald[2] & 0x7f);
t->time.tm_mon = -1;
t->time.tm_year = -1;
t->time.tm_yday = -1;
t->time.tm_isdst = -1;
dev_dbg(dev, "%s, sec=%d min=%d hour=%d wday=%d mday=%d mon=%d enabled=%d\n",
__func__, t->time.tm_sec, t->time.tm_min, t->time.tm_hour,
t->time.tm_wday, t->time.tm_mday, t->time.tm_mon, t->enabled);
return 0;
}
static int rx8130_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
u8 ald[3], ctl[3];
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
dev_dbg(dev, "%s, sec=%d min=%d hour=%d wday=%d mday=%d mon=%d "
"enabled=%d pending=%d\n", __func__,
t->time.tm_sec, t->time.tm_min, t->time.tm_hour,
t->time.tm_wday, t->time.tm_mday, t->time.tm_mon,
t->enabled, t->pending);
ret = regmap_bulk_read(ds1307->regmap, RX8130_REG_EXTENSION, ctl,
sizeof(ctl));
if (ret < 0)
return ret;
ctl[0] &= ~RX8130_REG_EXTENSION_WADA;
ctl[1] |= RX8130_REG_FLAG_AF;
ctl[2] &= ~RX8130_REG_CONTROL0_AIE;
ret = regmap_bulk_write(ds1307->regmap, RX8130_REG_EXTENSION, ctl,
sizeof(ctl));
if (ret < 0)
return ret;
ald[0] = bin2bcd(t->time.tm_min);
ald[1] = bin2bcd(t->time.tm_hour);
ald[2] = bin2bcd(t->time.tm_mday);
ret = regmap_bulk_write(ds1307->regmap, RX8130_REG_ALARM_MIN, ald,
sizeof(ald));
if (ret < 0)
return ret;
if (!t->enabled)
return 0;
ctl[2] |= RX8130_REG_CONTROL0_AIE;
return regmap_bulk_write(ds1307->regmap, RX8130_REG_EXTENSION, ctl,
sizeof(ctl));
}
static int rx8130_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
int ret, reg;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
ret = regmap_read(ds1307->regmap, RX8130_REG_CONTROL0, &reg);
if (ret < 0)
return ret;
if (enabled)
reg |= RX8130_REG_CONTROL0_AIE;
else
reg &= ~RX8130_REG_CONTROL0_AIE;
return regmap_write(ds1307->regmap, RX8130_REG_CONTROL0, reg);
}
static irqreturn_t mcp794xx_irq(int irq, void *dev_id)
{
struct ds1307 *ds1307 = dev_id;
struct mutex *lock = &ds1307->rtc->ops_lock;
int reg, ret;
mutex_lock(lock);
ret = regmap_read(ds1307->regmap, MCP794XX_REG_ALARM0_CTRL, &reg);
if (ret)
goto out;
if (!(reg & MCP794XX_BIT_ALMX_IF))
goto out;
reg &= ~MCP794XX_BIT_ALMX_IF;
ret = regmap_write(ds1307->regmap, MCP794XX_REG_ALARM0_CTRL, reg);
if (ret)
goto out;
ret = regmap_update_bits(ds1307->regmap, MCP794XX_REG_CONTROL,
MCP794XX_BIT_ALM0_EN, 0);
if (ret)
goto out;
rtc_update_irq(ds1307->rtc, 1, RTC_AF | RTC_IRQF);
out:
mutex_unlock(lock);
return IRQ_HANDLED;
}
static int mcp794xx_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
u8 regs[10];
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
ret = regmap_bulk_read(ds1307->regmap, MCP794XX_REG_CONTROL, regs,
sizeof(regs));
if (ret)
return ret;
t->enabled = !!(regs[0] & MCP794XX_BIT_ALM0_EN);
t->time.tm_sec = bcd2bin(regs[3] & 0x7f);
t->time.tm_min = bcd2bin(regs[4] & 0x7f);
t->time.tm_hour = bcd2bin(regs[5] & 0x3f);
t->time.tm_wday = bcd2bin(regs[6] & 0x7) - 1;
t->time.tm_mday = bcd2bin(regs[7] & 0x3f);
t->time.tm_mon = bcd2bin(regs[8] & 0x1f) - 1;
t->time.tm_year = -1;
t->time.tm_yday = -1;
t->time.tm_isdst = -1;
dev_dbg(dev, "%s, sec=%d min=%d hour=%d wday=%d mday=%d mon=%d "
"enabled=%d polarity=%d irq=%d match=%lu\n", __func__,
t->time.tm_sec, t->time.tm_min, t->time.tm_hour,
t->time.tm_wday, t->time.tm_mday, t->time.tm_mon, t->enabled,
!!(regs[6] & MCP794XX_BIT_ALMX_POL),
!!(regs[6] & MCP794XX_BIT_ALMX_IF),
(regs[6] & MCP794XX_MSK_ALMX_MATCH) >> 4);
return 0;
}
static int mcp794xx_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
unsigned char regs[10];
int ret;
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
dev_dbg(dev, "%s, sec=%d min=%d hour=%d wday=%d mday=%d mon=%d "
"enabled=%d pending=%d\n", __func__,
t->time.tm_sec, t->time.tm_min, t->time.tm_hour,
t->time.tm_wday, t->time.tm_mday, t->time.tm_mon,
t->enabled, t->pending);
ret = regmap_bulk_read(ds1307->regmap, MCP794XX_REG_CONTROL, regs,
sizeof(regs));
if (ret)
return ret;
regs[3] = bin2bcd(t->time.tm_sec);
regs[4] = bin2bcd(t->time.tm_min);
regs[5] = bin2bcd(t->time.tm_hour);
regs[6] = bin2bcd(t->time.tm_wday + 1);
regs[7] = bin2bcd(t->time.tm_mday);
regs[8] = bin2bcd(t->time.tm_mon + 1);
regs[6] &= ~MCP794XX_BIT_ALMX_IF;
regs[6] |= MCP794XX_MSK_ALMX_MATCH;
regs[0] &= ~MCP794XX_BIT_ALM0_EN;
ret = regmap_bulk_write(ds1307->regmap, MCP794XX_REG_CONTROL, regs,
sizeof(regs));
if (ret)
return ret;
if (!t->enabled)
return 0;
regs[0] |= MCP794XX_BIT_ALM0_EN;
return regmap_write(ds1307->regmap, MCP794XX_REG_CONTROL, regs[0]);
}
static int mcp794xx_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
if (!test_bit(HAS_ALARM, &ds1307->flags))
return -EINVAL;
return regmap_update_bits(ds1307->regmap, MCP794XX_REG_CONTROL,
MCP794XX_BIT_ALM0_EN,
enabled ? MCP794XX_BIT_ALM0_EN : 0);
}
static int ds1307_nvram_read(void *priv, unsigned int offset, void *val,
size_t bytes)
{
struct ds1307 *ds1307 = priv;
const struct chip_desc *chip = &chips[ds1307->type];
return regmap_bulk_read(ds1307->regmap, chip->nvram_offset + offset,
val, bytes);
}
static int ds1307_nvram_write(void *priv, unsigned int offset, void *val,
size_t bytes)
{
struct ds1307 *ds1307 = priv;
const struct chip_desc *chip = &chips[ds1307->type];
return regmap_bulk_write(ds1307->regmap, chip->nvram_offset + offset,
val, bytes);
}
static u8 do_trickle_setup_ds1339(struct ds1307 *ds1307,
u32 ohms, bool diode)
{
u8 setup = (diode) ? DS1307_TRICKLE_CHARGER_DIODE :
DS1307_TRICKLE_CHARGER_NO_DIODE;
switch (ohms) {
case 250:
setup |= DS1307_TRICKLE_CHARGER_250_OHM;
break;
case 2000:
setup |= DS1307_TRICKLE_CHARGER_2K_OHM;
break;
case 4000:
setup |= DS1307_TRICKLE_CHARGER_4K_OHM;
break;
default:
dev_warn(ds1307->dev,
"Unsupported ohm value %u in dt\n", ohms);
return 0;
}
return setup;
}
static u8 ds1307_trickle_init(struct ds1307 *ds1307,
const struct chip_desc *chip)
{
u32 ohms;
bool diode = true;
if (!chip->do_trickle_setup)
return 0;
if (device_property_read_u32(ds1307->dev, "trickle-resistor-ohms",
&ohms))
return 0;
if (device_property_read_bool(ds1307->dev, "trickle-diode-disable"))
diode = false;
return chip->do_trickle_setup(ds1307, ohms, diode);
}
static int ds3231_hwmon_read_temp(struct device *dev, s32 *mC)
{
struct ds1307 *ds1307 = dev_get_drvdata(dev);
u8 temp_buf[2];
s16 temp;
int ret;
ret = regmap_bulk_read(ds1307->regmap, DS3231_REG_TEMPERATURE,
temp_buf, sizeof(temp_buf));
if (ret)
return ret;
temp = (temp_buf[0] << 8) | temp_buf[1];
temp >>= 6;
*mC = temp * 250;
return 0;
}
static ssize_t ds3231_hwmon_show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
s32 temp;
ret = ds3231_hwmon_read_temp(dev, &temp);
if (ret)
return ret;
return sprintf(buf, "%d\n", temp);
}
static void ds1307_hwmon_register(struct ds1307 *ds1307)
{
struct device *dev;
if (ds1307->type != ds_3231)
return;
dev = devm_hwmon_device_register_with_groups(ds1307->dev, ds1307->name,
ds1307,
ds3231_hwmon_groups);
if (IS_ERR(dev)) {
dev_warn(ds1307->dev, "unable to register hwmon device %ld\n",
PTR_ERR(dev));
}
}
static void ds1307_hwmon_register(struct ds1307 *ds1307)
{
}
static int ds1337_write_control(struct ds1307 *ds1307, u8 mask, u8 value)
{
struct mutex *lock = &ds1307->rtc->ops_lock;
int ret;
mutex_lock(lock);
ret = regmap_update_bits(ds1307->regmap, DS1337_REG_CONTROL,
mask, value);
mutex_unlock(lock);
return ret;
}
static unsigned long ds3231_clk_sqw_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ds1307 *ds1307 = clk_sqw_to_ds1307(hw);
int control, ret;
int rate_sel = 0;
ret = regmap_read(ds1307->regmap, DS1337_REG_CONTROL, &control);
if (ret)
return ret;
if (control & DS1337_BIT_RS1)
rate_sel += 1;
if (control & DS1337_BIT_RS2)
rate_sel += 2;
return ds3231_clk_sqw_rates[rate_sel];
}
static long ds3231_clk_sqw_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int i;
for (i = ARRAY_SIZE(ds3231_clk_sqw_rates) - 1; i >= 0; i--) {
if (ds3231_clk_sqw_rates[i] <= rate)
return ds3231_clk_sqw_rates[i];
}
return 0;
}
static int ds3231_clk_sqw_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct ds1307 *ds1307 = clk_sqw_to_ds1307(hw);
int control = 0;
int rate_sel;
for (rate_sel = 0; rate_sel < ARRAY_SIZE(ds3231_clk_sqw_rates);
rate_sel++) {
if (ds3231_clk_sqw_rates[rate_sel] == rate)
break;
}
if (rate_sel == ARRAY_SIZE(ds3231_clk_sqw_rates))
return -EINVAL;
if (rate_sel & 1)
control |= DS1337_BIT_RS1;
if (rate_sel & 2)
control |= DS1337_BIT_RS2;
return ds1337_write_control(ds1307, DS1337_BIT_RS1 | DS1337_BIT_RS2,
control);
}
static int ds3231_clk_sqw_prepare(struct clk_hw *hw)
{
struct ds1307 *ds1307 = clk_sqw_to_ds1307(hw);
return ds1337_write_control(ds1307, DS1337_BIT_INTCN, 0);
}
static void ds3231_clk_sqw_unprepare(struct clk_hw *hw)
{
struct ds1307 *ds1307 = clk_sqw_to_ds1307(hw);
ds1337_write_control(ds1307, DS1337_BIT_INTCN, DS1337_BIT_INTCN);
}
static int ds3231_clk_sqw_is_prepared(struct clk_hw *hw)
{
struct ds1307 *ds1307 = clk_sqw_to_ds1307(hw);
int control, ret;
ret = regmap_read(ds1307->regmap, DS1337_REG_CONTROL, &control);
if (ret)
return ret;
return !(control & DS1337_BIT_INTCN);
}
static unsigned long ds3231_clk_32khz_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 32768;
}
static int ds3231_clk_32khz_control(struct ds1307 *ds1307, bool enable)
{
struct mutex *lock = &ds1307->rtc->ops_lock;
int ret;
mutex_lock(lock);
ret = regmap_update_bits(ds1307->regmap, DS1337_REG_STATUS,
DS3231_BIT_EN32KHZ,
enable ? DS3231_BIT_EN32KHZ : 0);
mutex_unlock(lock);
return ret;
}
static int ds3231_clk_32khz_prepare(struct clk_hw *hw)
{
struct ds1307 *ds1307 = clk_32khz_to_ds1307(hw);
return ds3231_clk_32khz_control(ds1307, true);
}
static void ds3231_clk_32khz_unprepare(struct clk_hw *hw)
{
struct ds1307 *ds1307 = clk_32khz_to_ds1307(hw);
ds3231_clk_32khz_control(ds1307, false);
}
static int ds3231_clk_32khz_is_prepared(struct clk_hw *hw)
{
struct ds1307 *ds1307 = clk_32khz_to_ds1307(hw);
int status, ret;
ret = regmap_read(ds1307->regmap, DS1337_REG_STATUS, &status);
if (ret)
return ret;
return !!(status & DS3231_BIT_EN32KHZ);
}
static int ds3231_clks_register(struct ds1307 *ds1307)
{
struct device_node *node = ds1307->dev->of_node;
struct clk_onecell_data *onecell;
int i;
onecell = devm_kzalloc(ds1307->dev, sizeof(*onecell), GFP_KERNEL);
if (!onecell)
return -ENOMEM;
onecell->clk_num = ARRAY_SIZE(ds3231_clks_init);
onecell->clks = devm_kcalloc(ds1307->dev, onecell->clk_num,
sizeof(onecell->clks[0]), GFP_KERNEL);
if (!onecell->clks)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(ds3231_clks_init); i++) {
struct clk_init_data init = ds3231_clks_init[i];
if (i == DS3231_CLK_SQW && test_bit(HAS_ALARM, &ds1307->flags))
continue;
of_property_read_string_index(node, "clock-output-names", i,
&init.name);
ds1307->clks[i].init = &init;
onecell->clks[i] = devm_clk_register(ds1307->dev,
&ds1307->clks[i]);
if (IS_ERR(onecell->clks[i]))
return PTR_ERR(onecell->clks[i]);
}
if (!node)
return 0;
of_clk_add_provider(node, of_clk_src_onecell_get, onecell);
return 0;
}
static void ds1307_clks_register(struct ds1307 *ds1307)
{
int ret;
if (ds1307->type != ds_3231)
return;
ret = ds3231_clks_register(ds1307);
if (ret) {
dev_warn(ds1307->dev, "unable to register clock device %d\n",
ret);
}
}
static void ds1307_clks_register(struct ds1307 *ds1307)
{
}
static int ds1307_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds1307 *ds1307;
int err = -ENODEV;
int tmp, wday;
const struct chip_desc *chip;
bool want_irq;
bool ds1307_can_wakeup_device = false;
unsigned char regs[8];
struct ds1307_platform_data *pdata = dev_get_platdata(&client->dev);
struct rtc_time tm;
unsigned long timestamp;
u8 trickle_charger_setup = 0;
ds1307 = devm_kzalloc(&client->dev, sizeof(struct ds1307), GFP_KERNEL);
if (!ds1307)
return -ENOMEM;
dev_set_drvdata(&client->dev, ds1307);
ds1307->dev = &client->dev;
ds1307->name = client->name;
ds1307->regmap = devm_regmap_init_i2c(client, &regmap_config);
if (IS_ERR(ds1307->regmap)) {
dev_err(ds1307->dev, "regmap allocation failed\n");
return PTR_ERR(ds1307->regmap);
}
i2c_set_clientdata(client, ds1307);
if (client->dev.of_node) {
ds1307->type = (enum ds_type)
of_device_get_match_data(&client->dev);
chip = &chips[ds1307->type];
} else if (id) {
chip = &chips[id->driver_data];
ds1307->type = id->driver_data;
} else {
const struct acpi_device_id *acpi_id;
acpi_id = acpi_match_device(ACPI_PTR(ds1307_acpi_ids),
ds1307->dev);
if (!acpi_id)
return -ENODEV;
chip = &chips[acpi_id->driver_data];
ds1307->type = acpi_id->driver_data;
}
want_irq = client->irq > 0 && chip->alarm;
if (!pdata)
trickle_charger_setup = ds1307_trickle_init(ds1307, chip);
else if (pdata->trickle_charger_setup)
trickle_charger_setup = pdata->trickle_charger_setup;
if (trickle_charger_setup && chip->trickle_charger_reg) {
trickle_charger_setup |= DS13XX_TRICKLE_CHARGER_MAGIC;
dev_dbg(ds1307->dev,
"writing trickle charger info 0x%x to 0x%x\n",
trickle_charger_setup, chip->trickle_charger_reg);
regmap_write(ds1307->regmap, chip->trickle_charger_reg,
trickle_charger_setup);
}
#ifdef CONFIG_OF
if (chip->alarm && of_property_read_bool(client->dev.of_node,
"wakeup-source"))
ds1307_can_wakeup_device = true;
#endif
switch (ds1307->type) {
case ds_1337:
case ds_1339:
case ds_1341:
case ds_3231:
err = regmap_bulk_read(ds1307->regmap, DS1337_REG_CONTROL,
regs, 2);
if (err) {
dev_dbg(ds1307->dev, "read error %d\n", err);
goto exit;
}
if (regs[0] & DS1337_BIT_nEOSC)
regs[0] &= ~DS1337_BIT_nEOSC;
if (want_irq || ds1307_can_wakeup_device) {
regs[0] |= DS1337_BIT_INTCN | chip->bbsqi_bit;
regs[0] &= ~(DS1337_BIT_A2IE | DS1337_BIT_A1IE);
}
regmap_write(ds1307->regmap, DS1337_REG_CONTROL,
regs[0]);
if (regs[1] & DS1337_BIT_OSF) {
regmap_write(ds1307->regmap, DS1337_REG_STATUS,
regs[1] & ~DS1337_BIT_OSF);
dev_warn(ds1307->dev, "SET TIME!\n");
}
break;
case rx_8025:
err = regmap_bulk_read(ds1307->regmap,
RX8025_REG_CTRL1 << 4 | 0x08, regs, 2);
if (err) {
dev_dbg(ds1307->dev, "read error %d\n", err);
goto exit;
}
if (!(regs[1] & RX8025_BIT_XST)) {
regs[1] |= RX8025_BIT_XST;
regmap_write(ds1307->regmap,
RX8025_REG_CTRL2 << 4 | 0x08,
regs[1]);
dev_warn(ds1307->dev,
"oscillator stop detected - SET TIME!\n");
}
if (regs[1] & RX8025_BIT_PON) {
regs[1] &= ~RX8025_BIT_PON;
regmap_write(ds1307->regmap,
RX8025_REG_CTRL2 << 4 | 0x08,
regs[1]);
dev_warn(ds1307->dev, "power-on detected\n");
}
if (regs[1] & RX8025_BIT_VDET) {
regs[1] &= ~RX8025_BIT_VDET;
regmap_write(ds1307->regmap,
RX8025_REG_CTRL2 << 4 | 0x08,
regs[1]);
dev_warn(ds1307->dev, "voltage drop detected\n");
}
if (!(regs[0] & RX8025_BIT_2412)) {
u8 hour;
regmap_write(ds1307->regmap,
RX8025_REG_CTRL1 << 4 | 0x08,
regs[0] | RX8025_BIT_2412);
err = regmap_bulk_read(ds1307->regmap,
RX8025_REG_CTRL1 << 4 | 0x08,
regs, 2);
if (err) {
dev_dbg(ds1307->dev, "read error %d\n", err);
goto exit;
}
hour = bcd2bin(regs[DS1307_REG_HOUR]);
if (hour == 12)
hour = 0;
if (regs[DS1307_REG_HOUR] & DS1307_BIT_PM)
hour += 12;
regmap_write(ds1307->regmap,
DS1307_REG_HOUR << 4 | 0x08, hour);
}
break;
default:
break;
}
read_rtc:
err = regmap_bulk_read(ds1307->regmap, chip->offset, regs,
sizeof(regs));
if (err) {
dev_dbg(ds1307->dev, "read error %d\n", err);
goto exit;
}
tmp = regs[DS1307_REG_SECS];
switch (ds1307->type) {
case ds_1307:
case m41t0:
case m41t00:
if (tmp & DS1307_BIT_CH) {
regmap_write(ds1307->regmap, DS1307_REG_SECS, 0);
dev_warn(ds1307->dev, "SET TIME!\n");
goto read_rtc;
}
break;
case ds_1308:
case ds_1338:
if (tmp & DS1307_BIT_CH)
regmap_write(ds1307->regmap, DS1307_REG_SECS, 0);
if (regs[DS1307_REG_CONTROL] & DS1338_BIT_OSF) {
regmap_write(ds1307->regmap, DS1307_REG_CONTROL,
regs[DS1307_REG_CONTROL] &
~DS1338_BIT_OSF);
dev_warn(ds1307->dev, "SET TIME!\n");
goto read_rtc;
}
break;
case ds_1340:
if (tmp & DS1340_BIT_nEOSC)
regmap_write(ds1307->regmap, DS1307_REG_SECS, 0);
err = regmap_read(ds1307->regmap, DS1340_REG_FLAG, &tmp);
if (err) {
dev_dbg(ds1307->dev, "read error %d\n", err);
goto exit;
}
if (tmp & DS1340_BIT_OSF) {
regmap_write(ds1307->regmap, DS1340_REG_FLAG, 0);
dev_warn(ds1307->dev, "SET TIME!\n");
}
break;
case mcp794xx:
if (!(regs[DS1307_REG_WDAY] & MCP794XX_BIT_VBATEN)) {
regmap_write(ds1307->regmap, DS1307_REG_WDAY,
regs[DS1307_REG_WDAY] |
MCP794XX_BIT_VBATEN);
}
if (!(tmp & MCP794XX_BIT_ST)) {
regmap_write(ds1307->regmap, DS1307_REG_SECS,
MCP794XX_BIT_ST);
dev_warn(ds1307->dev, "SET TIME!\n");
goto read_rtc;
}
break;
default:
break;
}
tmp = regs[DS1307_REG_HOUR];
switch (ds1307->type) {
case ds_1340:
case m41t0:
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
if (regs[DS1307_REG_HOUR] & DS1307_BIT_PM)
tmp += 12;
regmap_write(ds1307->regmap, chip->offset + DS1307_REG_HOUR,
bin2bcd(tmp));
}
ds1307_get_time(ds1307->dev, &tm);
wday = tm.tm_wday;
timestamp = rtc_tm_to_time64(&tm);
rtc_time64_to_tm(timestamp, &tm);
if (wday != tm.tm_wday)
regmap_update_bits(ds1307->regmap, MCP794XX_REG_WEEKDAY,
MCP794XX_REG_WEEKDAY_WDAY_MASK,
tm.tm_wday + 1);
if (want_irq || ds1307_can_wakeup_device) {
device_set_wakeup_capable(ds1307->dev, true);
set_bit(HAS_ALARM, &ds1307->flags);
}
ds1307->rtc = devm_rtc_allocate_device(ds1307->dev);
if (IS_ERR(ds1307->rtc))
return PTR_ERR(ds1307->rtc);
if (ds1307_can_wakeup_device && !want_irq) {
dev_info(ds1307->dev,
"'wakeup-source' is set, request for an IRQ is disabled!\n");
ds1307->rtc->uie_unsupported = 1;
}
if (want_irq) {
err = devm_request_threaded_irq(ds1307->dev, client->irq, NULL,
chip->irq_handler ?: ds1307_irq,
IRQF_SHARED | IRQF_ONESHOT,
ds1307->name, ds1307);
if (err) {
client->irq = 0;
device_set_wakeup_capable(ds1307->dev, false);
clear_bit(HAS_ALARM, &ds1307->flags);
dev_err(ds1307->dev, "unable to request IRQ!\n");
} else {
dev_dbg(ds1307->dev, "got IRQ %d\n", client->irq);
}
}
if (chip->nvram_size) {
ds1307->nvmem_cfg.name = "ds1307_nvram";
ds1307->nvmem_cfg.word_size = 1;
ds1307->nvmem_cfg.stride = 1;
ds1307->nvmem_cfg.size = chip->nvram_size;
ds1307->nvmem_cfg.reg_read = ds1307_nvram_read;
ds1307->nvmem_cfg.reg_write = ds1307_nvram_write;
ds1307->nvmem_cfg.priv = ds1307;
ds1307->rtc->nvmem_config = &ds1307->nvmem_cfg;
ds1307->rtc->nvram_old_abi = true;
}
ds1307->rtc->ops = chip->rtc_ops ?: &ds13xx_rtc_ops;
err = rtc_register_device(ds1307->rtc);
if (err)
return err;
ds1307_hwmon_register(ds1307);
ds1307_clks_register(ds1307);
return 0;
exit:
return err;
}
