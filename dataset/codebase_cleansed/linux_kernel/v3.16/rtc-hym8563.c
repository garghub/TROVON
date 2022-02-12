static int hym8563_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
struct hym8563 *hym8563 = i2c_get_clientdata(client);
u8 buf[7];
int ret;
if (!hym8563->valid) {
dev_warn(&client->dev, "no valid clock/calendar values available\n");
return -EPERM;
}
ret = i2c_smbus_read_i2c_block_data(client, HYM8563_SEC, 7, buf);
tm->tm_sec = bcd2bin(buf[0] & HYM8563_SEC_MASK);
tm->tm_min = bcd2bin(buf[1] & HYM8563_MIN_MASK);
tm->tm_hour = bcd2bin(buf[2] & HYM8563_HOUR_MASK);
tm->tm_mday = bcd2bin(buf[3] & HYM8563_DAY_MASK);
tm->tm_wday = bcd2bin(buf[4] & HYM8563_WEEKDAY_MASK);
tm->tm_mon = bcd2bin(buf[5] & HYM8563_MONTH_MASK) - 1;
tm->tm_year = bcd2bin(buf[6]) + 100;
return 0;
}
static int hym8563_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
struct hym8563 *hym8563 = i2c_get_clientdata(client);
u8 buf[7];
int ret;
if (tm->tm_year < 100 || tm->tm_year >= 200)
return -EINVAL;
buf[0] = bin2bcd(tm->tm_sec);
buf[1] = bin2bcd(tm->tm_min);
buf[2] = bin2bcd(tm->tm_hour);
buf[3] = bin2bcd(tm->tm_mday);
buf[4] = bin2bcd(tm->tm_wday);
buf[5] = bin2bcd(tm->tm_mon + 1);
buf[6] = tm->tm_year - 100;
ret = i2c_smbus_write_byte_data(client, HYM8563_CTL1,
HYM8563_CTL1_STOP);
if (ret < 0)
return ret;
ret = i2c_smbus_write_i2c_block_data(client, HYM8563_SEC, 7, buf);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, HYM8563_CTL1, 0);
if (ret < 0)
return ret;
hym8563->valid = true;
return 0;
}
static int hym8563_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct i2c_client *client = to_i2c_client(dev);
int data;
data = i2c_smbus_read_byte_data(client, HYM8563_CTL2);
if (data < 0)
return data;
if (enabled)
data |= HYM8563_CTL2_AIE;
else
data &= ~HYM8563_CTL2_AIE;
return i2c_smbus_write_byte_data(client, HYM8563_CTL2, data);
}
static int hym8563_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct i2c_client *client = to_i2c_client(dev);
struct rtc_time *alm_tm = &alm->time;
u8 buf[4];
int ret;
ret = i2c_smbus_read_i2c_block_data(client, HYM8563_ALM_MIN, 4, buf);
if (ret < 0)
return ret;
alm_tm->tm_sec = -1;
alm_tm->tm_min = (buf[0] & HYM8563_ALM_BIT_DISABLE) ?
-1 :
bcd2bin(buf[0] & HYM8563_MIN_MASK);
alm_tm->tm_hour = (buf[1] & HYM8563_ALM_BIT_DISABLE) ?
-1 :
bcd2bin(buf[1] & HYM8563_HOUR_MASK);
alm_tm->tm_mday = (buf[2] & HYM8563_ALM_BIT_DISABLE) ?
-1 :
bcd2bin(buf[2] & HYM8563_DAY_MASK);
alm_tm->tm_wday = (buf[3] & HYM8563_ALM_BIT_DISABLE) ?
-1 :
bcd2bin(buf[3] & HYM8563_WEEKDAY_MASK);
alm_tm->tm_mon = -1;
alm_tm->tm_year = -1;
ret = i2c_smbus_read_byte_data(client, HYM8563_CTL2);
if (ret < 0)
return ret;
if (ret & HYM8563_CTL2_AIE)
alm->enabled = 1;
return 0;
}
static int hym8563_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct i2c_client *client = to_i2c_client(dev);
struct rtc_time *alm_tm = &alm->time;
u8 buf[4];
int ret;
if (alm_tm->tm_sec) {
alm_tm->tm_sec = 0;
alm_tm->tm_min++;
if (alm_tm->tm_min >= 60) {
alm_tm->tm_min = 0;
alm_tm->tm_hour++;
if (alm_tm->tm_hour >= 24) {
alm_tm->tm_hour = 0;
alm_tm->tm_mday++;
if (alm_tm->tm_mday > 31)
alm_tm->tm_mday = 0;
}
}
}
ret = i2c_smbus_read_byte_data(client, HYM8563_CTL2);
if (ret < 0)
return ret;
ret &= ~HYM8563_CTL2_AIE;
ret = i2c_smbus_write_byte_data(client, HYM8563_CTL2, ret);
if (ret < 0)
return ret;
buf[0] = (alm_tm->tm_min < 60 && alm_tm->tm_min >= 0) ?
bin2bcd(alm_tm->tm_min) : HYM8563_ALM_BIT_DISABLE;
buf[1] = (alm_tm->tm_hour < 24 && alm_tm->tm_hour >= 0) ?
bin2bcd(alm_tm->tm_hour) : HYM8563_ALM_BIT_DISABLE;
buf[2] = (alm_tm->tm_mday <= 31 && alm_tm->tm_mday >= 1) ?
bin2bcd(alm_tm->tm_mday) : HYM8563_ALM_BIT_DISABLE;
buf[3] = (alm_tm->tm_wday < 7 && alm_tm->tm_wday >= 0) ?
bin2bcd(alm_tm->tm_wday) : HYM8563_ALM_BIT_DISABLE;
ret = i2c_smbus_write_i2c_block_data(client, HYM8563_ALM_MIN, 4, buf);
if (ret < 0)
return ret;
return hym8563_rtc_alarm_irq_enable(dev, alm->enabled);
}
static unsigned long hym8563_clkout_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct hym8563 *hym8563 = clkout_hw_to_hym8563(hw);
struct i2c_client *client = hym8563->client;
int ret = i2c_smbus_read_byte_data(client, HYM8563_CLKOUT);
if (ret < 0 || ret & HYM8563_CLKOUT_DISABLE)
return 0;
ret &= HYM8563_CLKOUT_MASK;
return clkout_rates[ret];
}
static long hym8563_clkout_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int i;
for (i = 0; i < ARRAY_SIZE(clkout_rates); i++)
if (clkout_rates[i] <= rate)
return clkout_rates[i];
return 0;
}
static int hym8563_clkout_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct hym8563 *hym8563 = clkout_hw_to_hym8563(hw);
struct i2c_client *client = hym8563->client;
int ret = i2c_smbus_read_byte_data(client, HYM8563_CLKOUT);
int i;
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(clkout_rates); i++)
if (clkout_rates[i] == rate) {
ret &= ~HYM8563_CLKOUT_MASK;
ret |= i;
return i2c_smbus_write_byte_data(client,
HYM8563_CLKOUT, ret);
}
return -EINVAL;
}
static int hym8563_clkout_control(struct clk_hw *hw, bool enable)
{
struct hym8563 *hym8563 = clkout_hw_to_hym8563(hw);
struct i2c_client *client = hym8563->client;
int ret = i2c_smbus_read_byte_data(client, HYM8563_CLKOUT);
if (ret < 0)
return ret;
if (enable)
ret &= ~HYM8563_CLKOUT_DISABLE;
else
ret |= HYM8563_CLKOUT_DISABLE;
return i2c_smbus_write_byte_data(client, HYM8563_CLKOUT, ret);
}
static int hym8563_clkout_prepare(struct clk_hw *hw)
{
return hym8563_clkout_control(hw, 1);
}
static void hym8563_clkout_unprepare(struct clk_hw *hw)
{
hym8563_clkout_control(hw, 0);
}
static int hym8563_clkout_is_prepared(struct clk_hw *hw)
{
struct hym8563 *hym8563 = clkout_hw_to_hym8563(hw);
struct i2c_client *client = hym8563->client;
int ret = i2c_smbus_read_byte_data(client, HYM8563_CLKOUT);
if (ret < 0)
return ret;
return !(ret & HYM8563_CLKOUT_DISABLE);
}
static struct clk *hym8563_clkout_register_clk(struct hym8563 *hym8563)
{
struct i2c_client *client = hym8563->client;
struct device_node *node = client->dev.of_node;
struct clk *clk;
struct clk_init_data init;
int ret;
ret = i2c_smbus_write_byte_data(client, HYM8563_CLKOUT,
HYM8563_CLKOUT_DISABLE);
if (ret < 0)
return ERR_PTR(ret);
init.name = "hym8563-clkout";
init.ops = &hym8563_clkout_ops;
init.flags = CLK_IS_ROOT;
init.parent_names = NULL;
init.num_parents = 0;
hym8563->clkout_hw.init = &init;
of_property_read_string(node, "clock-output-names", &init.name);
clk = clk_register(&client->dev, &hym8563->clkout_hw);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
return clk;
}
static irqreturn_t hym8563_irq(int irq, void *dev_id)
{
struct hym8563 *hym8563 = (struct hym8563 *)dev_id;
struct i2c_client *client = hym8563->client;
struct mutex *lock = &hym8563->rtc->ops_lock;
int data, ret;
mutex_lock(lock);
data = i2c_smbus_read_byte_data(client, HYM8563_CTL2);
if (data < 0) {
dev_err(&client->dev, "%s: error reading i2c data %d\n",
__func__, data);
goto out;
}
data &= ~HYM8563_CTL2_AF;
ret = i2c_smbus_write_byte_data(client, HYM8563_CTL2, data);
if (ret < 0) {
dev_err(&client->dev, "%s: error writing i2c data %d\n",
__func__, ret);
}
out:
mutex_unlock(lock);
return IRQ_HANDLED;
}
static int hym8563_init_device(struct i2c_client *client)
{
int ret;
ret = i2c_smbus_write_byte_data(client, HYM8563_CTL1, 0);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(client, HYM8563_CTL2);
if (ret < 0)
return ret;
ret &= ~HYM8563_CTL2_AIE;
ret &= ~HYM8563_CTL2_TIE;
if (ret & HYM8563_CTL2_AF)
ret &= ~HYM8563_CTL2_AF;
if (ret & HYM8563_CTL2_TF)
ret &= ~HYM8563_CTL2_TF;
ret &= ~HYM8563_CTL2_TI_TP;
return i2c_smbus_write_byte_data(client, HYM8563_CTL2, ret);
}
static int hym8563_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int ret;
if (device_may_wakeup(dev)) {
ret = enable_irq_wake(client->irq);
if (ret) {
dev_err(dev, "enable_irq_wake failed, %d\n", ret);
return ret;
}
}
return 0;
}
static int hym8563_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(dev))
disable_irq_wake(client->irq);
return 0;
}
static int hym8563_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct hym8563 *hym8563;
int ret;
hym8563 = devm_kzalloc(&client->dev, sizeof(*hym8563), GFP_KERNEL);
if (!hym8563)
return -ENOMEM;
hym8563->client = client;
i2c_set_clientdata(client, hym8563);
device_set_wakeup_capable(&client->dev, true);
ret = hym8563_init_device(client);
if (ret) {
dev_err(&client->dev, "could not init device, %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, hym8563_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
client->name, hym8563);
if (ret < 0) {
dev_err(&client->dev, "irq %d request failed, %d\n",
client->irq, ret);
return ret;
}
ret = i2c_smbus_read_byte_data(client, HYM8563_SEC);
if (ret < 0)
return ret;
hym8563->valid = !(ret & HYM8563_SEC_VL);
dev_dbg(&client->dev, "rtc information is %s\n",
hym8563->valid ? "valid" : "invalid");
hym8563->rtc = devm_rtc_device_register(&client->dev, client->name,
&hym8563_rtc_ops, THIS_MODULE);
if (IS_ERR(hym8563->rtc))
return PTR_ERR(hym8563->rtc);
hym8563->rtc->uie_unsupported = 1;
#ifdef CONFIG_COMMON_CLK
hym8563_clkout_register_clk(hym8563);
#endif
return 0;
}
