static inline unsigned int rpm_from_cnt(u8 cnt, u32 clk_freq, u16 p,
u8 clk_div, u8 gear_mult)
{
if (cnt == 0xff)
return 0;
return (clk_freq * 30 * gear_mult) / ((cnt ? cnt : 1) * p * clk_div);
}
static inline unsigned char cnt_from_rpm(unsigned long rpm, u32 clk_freq, u16 p,
u8 clk_div, u8 gear_mult)
{
unsigned long f1 = clk_freq * 30 * gear_mult;
unsigned long f2 = p * clk_div;
if (!rpm)
return 0xff;
rpm = clamp_val(rpm, f1 / (255 * f2), ULONG_MAX / f2);
return DIV_ROUND_CLOSEST(f1, rpm * f2);
}
static struct g762_data *g762_update_client(struct device *dev)
{
struct g762_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int ret = 0;
mutex_lock(&data->update_lock);
if (time_before(jiffies, data->last_updated + G762_UPDATE_INTERVAL) &&
likely(data->valid))
goto out;
ret = i2c_smbus_read_byte_data(client, G762_REG_SET_CNT);
if (ret < 0)
goto out;
data->set_cnt = ret;
ret = i2c_smbus_read_byte_data(client, G762_REG_ACT_CNT);
if (ret < 0)
goto out;
data->act_cnt = ret;
ret = i2c_smbus_read_byte_data(client, G762_REG_FAN_STA);
if (ret < 0)
goto out;
data->fan_sta = ret;
ret = i2c_smbus_read_byte_data(client, G762_REG_SET_OUT);
if (ret < 0)
goto out;
data->set_out = ret;
ret = i2c_smbus_read_byte_data(client, G762_REG_FAN_CMD1);
if (ret < 0)
goto out;
data->fan_cmd1 = ret;
ret = i2c_smbus_read_byte_data(client, G762_REG_FAN_CMD2);
if (ret < 0)
goto out;
data->fan_cmd2 = ret;
data->last_updated = jiffies;
data->valid = true;
out:
mutex_unlock(&data->update_lock);
if (ret < 0)
data = ERR_PTR(ret);
return data;
}
static int do_set_clk_freq(struct device *dev, unsigned long val)
{
struct g762_data *data = dev_get_drvdata(dev);
if (val > 0xffffff)
return -EINVAL;
if (!val)
val = 32768;
data->clk_freq = val;
return 0;
}
static int do_set_pwm_mode(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case G762_OUT_MODE_PWM:
data->fan_cmd1 |= G762_REG_FAN_CMD1_OUT_MODE;
break;
case G762_OUT_MODE_DC:
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_OUT_MODE;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
data->fan_cmd1);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_fan_div(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case 1:
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID0;
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID1;
break;
case 2:
data->fan_cmd1 |= G762_REG_FAN_CMD1_CLK_DIV_ID0;
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID1;
break;
case 4:
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_CLK_DIV_ID0;
data->fan_cmd1 |= G762_REG_FAN_CMD1_CLK_DIV_ID1;
break;
case 8:
data->fan_cmd1 |= G762_REG_FAN_CMD1_CLK_DIV_ID0;
data->fan_cmd1 |= G762_REG_FAN_CMD1_CLK_DIV_ID1;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
data->fan_cmd1);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_fan_gear_mode(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case 0:
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_0;
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_1;
break;
case 1:
data->fan_cmd2 |= G762_REG_FAN_CMD2_GEAR_MODE_0;
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_1;
break;
case 2:
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_GEAR_MODE_0;
data->fan_cmd2 |= G762_REG_FAN_CMD2_GEAR_MODE_1;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD2,
data->fan_cmd2);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_fan_pulses(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case 2:
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_PULSE_PER_REV;
break;
case 4:
data->fan_cmd1 |= G762_REG_FAN_CMD1_PULSE_PER_REV;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
data->fan_cmd1);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_pwm_enable(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case G762_FAN_MODE_CLOSED_LOOP:
data->fan_cmd1 |= G762_REG_FAN_CMD1_FAN_MODE;
break;
case G762_FAN_MODE_OPEN_LOOP:
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_FAN_MODE;
if (data->set_cnt == 0xff)
i2c_smbus_write_byte_data(data->client,
G762_REG_SET_CNT, 254);
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
data->fan_cmd1);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_pwm_polarity(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case G762_PWM_POLARITY_POSITIVE:
data->fan_cmd1 &= ~G762_REG_FAN_CMD1_PWM_POLARITY;
break;
case G762_PWM_POLARITY_NEGATIVE:
data->fan_cmd1 |= G762_REG_FAN_CMD1_PWM_POLARITY;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
data->fan_cmd1);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_pwm(struct device *dev, unsigned long val)
{
struct g762_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int ret;
if (val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
ret = i2c_smbus_write_byte_data(client, G762_REG_SET_OUT, val);
data->valid = false;
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_fan_target(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
data->set_cnt = cnt_from_rpm(val, data->clk_freq,
G762_PULSE_FROM_REG(data->fan_cmd1),
G762_CLKDIV_FROM_REG(data->fan_cmd1),
G762_GEARMULT_FROM_REG(data->fan_cmd2));
ret = i2c_smbus_write_byte_data(data->client, G762_REG_SET_CNT,
data->set_cnt);
data->valid = false;
mutex_unlock(&data->update_lock);
return ret;
}
static int do_set_fan_startv(struct device *dev, unsigned long val)
{
struct g762_data *data = g762_update_client(dev);
int ret;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
switch (val) {
case 0:
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_0;
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_1;
break;
case 1:
data->fan_cmd2 |= G762_REG_FAN_CMD2_FAN_STARTV_0;
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_1;
break;
case 2:
data->fan_cmd2 &= ~G762_REG_FAN_CMD2_FAN_STARTV_0;
data->fan_cmd2 |= G762_REG_FAN_CMD2_FAN_STARTV_1;
break;
case 3:
data->fan_cmd2 |= G762_REG_FAN_CMD2_FAN_STARTV_0;
data->fan_cmd2 |= G762_REG_FAN_CMD2_FAN_STARTV_1;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD2,
data->fan_cmd2);
data->valid = false;
out:
mutex_unlock(&data->update_lock);
return ret;
}
static int g762_of_clock_enable(struct i2c_client *client)
{
struct g762_data *data;
unsigned long clk_freq;
struct clk *clk;
int ret;
if (!client->dev.of_node)
return 0;
clk = of_clk_get(client->dev.of_node, 0);
if (IS_ERR(clk)) {
dev_err(&client->dev, "failed to get clock\n");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&client->dev, "failed to enable clock\n");
goto clk_put;
}
clk_freq = clk_get_rate(clk);
ret = do_set_clk_freq(&client->dev, clk_freq);
if (ret) {
dev_err(&client->dev, "invalid clock freq %lu\n", clk_freq);
goto clk_unprep;
}
data = i2c_get_clientdata(client);
data->clk = clk;
return 0;
clk_unprep:
clk_disable_unprepare(clk);
clk_put:
clk_put(clk);
return ret;
}
static void g762_of_clock_disable(struct i2c_client *client)
{
struct g762_data *data = i2c_get_clientdata(client);
if (!data->clk)
return;
clk_disable_unprepare(data->clk);
clk_put(data->clk);
}
static int g762_of_prop_import_one(struct i2c_client *client,
const char *pname,
int (*psetter)(struct device *dev,
unsigned long val))
{
int ret;
u32 pval;
if (of_property_read_u32(client->dev.of_node, pname, &pval))
return 0;
dev_dbg(&client->dev, "found %s (%d)\n", pname, pval);
ret = (*psetter)(&client->dev, pval);
if (ret)
dev_err(&client->dev, "unable to set %s (%d)\n", pname, pval);
return ret;
}
static int g762_of_prop_import(struct i2c_client *client)
{
int ret;
if (!client->dev.of_node)
return 0;
ret = g762_of_prop_import_one(client, "fan_gear_mode",
do_set_fan_gear_mode);
if (ret)
return ret;
ret = g762_of_prop_import_one(client, "pwm_polarity",
do_set_pwm_polarity);
if (ret)
return ret;
return g762_of_prop_import_one(client, "fan_startv",
do_set_fan_startv);
}
static int g762_of_prop_import(struct i2c_client *client)
{
return 0;
}
static int g762_of_clock_enable(struct i2c_client *client)
{
return 0;
}
static void g762_of_clock_disable(struct i2c_client *client) { }
static int g762_pdata_prop_import(struct i2c_client *client)
{
struct g762_platform_data *pdata = dev_get_platdata(&client->dev);
int ret;
if (!pdata)
return 0;
ret = do_set_fan_gear_mode(&client->dev, pdata->fan_gear_mode);
if (ret)
return ret;
ret = do_set_pwm_polarity(&client->dev, pdata->pwm_polarity);
if (ret)
return ret;
ret = do_set_fan_startv(&client->dev, pdata->fan_startv);
if (ret)
return ret;
return do_set_clk_freq(&client->dev, pdata->clk_freq);
}
static ssize_t get_fan_rpm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g762_data *data = g762_update_client(dev);
unsigned int rpm = 0;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
if (data->fan_sta & G762_REG_FAN_STA_OOC) {
rpm = rpm_from_cnt(data->act_cnt, data->clk_freq,
G762_PULSE_FROM_REG(data->fan_cmd1),
G762_CLKDIV_FROM_REG(data->fan_cmd1),
G762_GEARMULT_FROM_REG(data->fan_cmd2));
}
mutex_unlock(&data->update_lock);
return sprintf(buf, "%u\n", rpm);
}
static ssize_t get_pwm_mode(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n",
!!(data->fan_cmd1 & G762_REG_FAN_CMD1_OUT_MODE));
}
static ssize_t set_pwm_mode(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
ret = do_set_pwm_mode(dev, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t get_fan_div(struct device *dev,
struct device_attribute *da, char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", G762_CLKDIV_FROM_REG(data->fan_cmd1));
}
static ssize_t set_fan_div(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
ret = do_set_fan_div(dev, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t get_fan_pulses(struct device *dev,
struct device_attribute *da, char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", G762_PULSE_FROM_REG(data->fan_cmd1));
}
static ssize_t set_fan_pulses(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
ret = do_set_fan_pulses(dev, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t get_pwm_enable(struct device *dev,
struct device_attribute *da, char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n",
(!!(data->fan_cmd1 & G762_REG_FAN_CMD1_FAN_MODE)) + 1);
}
static ssize_t set_pwm_enable(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
ret = do_set_pwm_enable(dev, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t get_pwm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->set_out);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
ret = do_set_pwm(dev, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t get_fan_target(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g762_data *data = g762_update_client(dev);
unsigned int rpm;
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
rpm = rpm_from_cnt(data->set_cnt, data->clk_freq,
G762_PULSE_FROM_REG(data->fan_cmd1),
G762_CLKDIV_FROM_REG(data->fan_cmd1),
G762_GEARMULT_FROM_REG(data->fan_cmd2));
mutex_unlock(&data->update_lock);
return sprintf(buf, "%u\n", rpm);
}
static ssize_t set_fan_target(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
ret = do_set_fan_target(dev, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t get_fan_failure(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%u\n", !!(data->fan_sta & G762_REG_FAN_STA_FAIL));
}
static ssize_t get_fan_ooc(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%u\n", !(data->fan_sta & G762_REG_FAN_STA_OOC));
}
static inline int g762_fan_init(struct device *dev)
{
struct g762_data *data = g762_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
data->fan_cmd1 |= G762_REG_FAN_CMD1_DET_FAN_FAIL;
data->fan_cmd1 |= G762_REG_FAN_CMD1_DET_FAN_OOC;
data->valid = false;
return i2c_smbus_write_byte_data(data->client, G762_REG_FAN_CMD1,
data->fan_cmd1);
}
static int g762_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct g762_data *data;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(struct g762_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->client = client;
mutex_init(&data->update_lock);
ret = g762_fan_init(dev);
if (ret)
return ret;
ret = g762_of_clock_enable(client);
if (ret)
return ret;
ret = g762_of_prop_import(client);
if (ret)
goto clock_dis;
ret = g762_pdata_prop_import(client);
if (ret)
goto clock_dis;
data->hwmon_dev = hwmon_device_register_with_groups(dev, client->name,
data, g762_groups);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto clock_dis;
}
return 0;
clock_dis:
g762_of_clock_disable(client);
return ret;
}
static int g762_remove(struct i2c_client *client)
{
struct g762_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
g762_of_clock_disable(client);
return 0;
}
