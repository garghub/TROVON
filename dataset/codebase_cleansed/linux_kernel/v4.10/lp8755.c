static int lp8755_read(struct lp8755_chip *pchip, unsigned int reg,
unsigned int *val)
{
return regmap_read(pchip->regmap, reg, val);
}
static int lp8755_write(struct lp8755_chip *pchip, unsigned int reg,
unsigned int val)
{
return regmap_write(pchip->regmap, reg, val);
}
static int lp8755_update_bits(struct lp8755_chip *pchip, unsigned int reg,
unsigned int mask, unsigned int val)
{
return regmap_update_bits(pchip->regmap, reg, mask, val);
}
static int lp8755_buck_enable_time(struct regulator_dev *rdev)
{
int ret;
unsigned int regval;
enum lp8755_bucks id = rdev_get_id(rdev);
struct lp8755_chip *pchip = rdev_get_drvdata(rdev);
ret = lp8755_read(pchip, 0x12 + id, &regval);
if (ret < 0) {
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return ret;
}
return (regval & 0xff) * 100;
}
static int lp8755_buck_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
int ret;
unsigned int regbval = 0x0;
enum lp8755_bucks id = rdev_get_id(rdev);
struct lp8755_chip *pchip = rdev_get_drvdata(rdev);
switch (mode) {
case REGULATOR_MODE_FAST:
regbval = (0x01 << id);
break;
case REGULATOR_MODE_NORMAL:
ret = lp8755_update_bits(pchip, 0x08 + id, 0x20, 0x00);
if (ret < 0)
goto err_i2c;
break;
case REGULATOR_MODE_IDLE:
ret = lp8755_update_bits(pchip, 0x08 + id, 0x20, 0x20);
if (ret < 0)
goto err_i2c;
ret = lp8755_update_bits(pchip, 0x10, 0x01, 0x01);
if (ret < 0)
goto err_i2c;
break;
default:
dev_err(pchip->dev, "Not supported buck mode %s\n", __func__);
regbval = (0x01 << id);
}
ret = lp8755_update_bits(pchip, 0x06, 0x01 << id, regbval);
if (ret < 0)
goto err_i2c;
return ret;
err_i2c:
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return ret;
}
static unsigned int lp8755_buck_get_mode(struct regulator_dev *rdev)
{
int ret;
unsigned int regval;
enum lp8755_bucks id = rdev_get_id(rdev);
struct lp8755_chip *pchip = rdev_get_drvdata(rdev);
ret = lp8755_read(pchip, 0x06, &regval);
if (ret < 0)
goto err_i2c;
if (regval & (0x01 << id))
return REGULATOR_MODE_FAST;
ret = lp8755_read(pchip, 0x08 + id, &regval);
if (ret < 0)
goto err_i2c;
if (regval & 0x20)
return REGULATOR_MODE_IDLE;
return REGULATOR_MODE_NORMAL;
err_i2c:
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return 0;
}
static int lp8755_buck_set_ramp(struct regulator_dev *rdev, int ramp)
{
int ret;
unsigned int regval = 0x00;
enum lp8755_bucks id = rdev_get_id(rdev);
struct lp8755_chip *pchip = rdev_get_drvdata(rdev);
switch (ramp) {
case 0 ... 230:
regval = 0x07;
break;
case 231 ... 470:
regval = 0x06;
break;
case 471 ... 940:
regval = 0x05;
break;
case 941 ... 1900:
regval = 0x04;
break;
case 1901 ... 3800:
regval = 0x03;
break;
case 3801 ... 7500:
regval = 0x02;
break;
case 7501 ... 15000:
regval = 0x01;
break;
case 15001 ... 30000:
regval = 0x00;
break;
default:
dev_err(pchip->dev,
"Not supported ramp value %d %s\n", ramp, __func__);
return -EINVAL;
}
ret = lp8755_update_bits(pchip, 0x07 + id, 0x07, regval);
if (ret < 0)
goto err_i2c;
return ret;
err_i2c:
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return ret;
}
static int lp8755_init_data(struct lp8755_chip *pchip)
{
unsigned int regval;
int ret, icnt, buck_num;
struct lp8755_platform_data *pdata = pchip->pdata;
ret = lp8755_read(pchip, 0x3D, &regval);
if (ret < 0)
goto out_i2c_error;
pchip->mphase = regval & 0x0F;
for (icnt = 0; icnt < mphase_buck[pchip->mphase].nreg; icnt++) {
buck_num = mphase_buck[pchip->mphase].buck_num[icnt];
pdata->buck_data[buck_num] = &lp8755_reg_default[buck_num];
}
return ret;
out_i2c_error:
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return ret;
}
static int lp8755_regulator_init(struct lp8755_chip *pchip)
{
int ret, icnt, buck_num;
struct lp8755_platform_data *pdata = pchip->pdata;
struct regulator_config rconfig = { };
rconfig.regmap = pchip->regmap;
rconfig.dev = pchip->dev;
rconfig.driver_data = pchip;
for (icnt = 0; icnt < mphase_buck[pchip->mphase].nreg; icnt++) {
buck_num = mphase_buck[pchip->mphase].buck_num[icnt];
rconfig.init_data = pdata->buck_data[buck_num];
rconfig.of_node = pchip->dev->of_node;
pchip->rdev[buck_num] =
devm_regulator_register(pchip->dev,
&lp8755_regulators[buck_num], &rconfig);
if (IS_ERR(pchip->rdev[buck_num])) {
ret = PTR_ERR(pchip->rdev[buck_num]);
pchip->rdev[buck_num] = NULL;
dev_err(pchip->dev, "regulator init failed: buck %d\n",
buck_num);
return ret;
}
}
return 0;
}
static irqreturn_t lp8755_irq_handler(int irq, void *data)
{
int ret, icnt;
unsigned int flag0, flag1;
struct lp8755_chip *pchip = data;
ret = lp8755_read(pchip, 0x0D, &flag0);
if (ret < 0)
goto err_i2c;
ret = lp8755_write(pchip, 0x0D, 0x00);
if (ret < 0)
goto err_i2c;
for (icnt = 0; icnt < LP8755_BUCK_MAX; icnt++)
if ((flag0 & (0x4 << icnt))
&& (pchip->irqmask & (0x04 << icnt))
&& (pchip->rdev[icnt] != NULL))
regulator_notifier_call_chain(pchip->rdev[icnt],
LP8755_EVENT_PWR_FAULT,
NULL);
ret = lp8755_read(pchip, 0x0E, &flag1);
if (ret < 0)
goto err_i2c;
ret = lp8755_write(pchip, 0x0E, 0x00);
if (ret < 0)
goto err_i2c;
if ((flag1 & 0x01) && (pchip->irqmask & 0x01))
for (icnt = 0; icnt < LP8755_BUCK_MAX; icnt++)
if (pchip->rdev[icnt] != NULL)
regulator_notifier_call_chain(pchip->rdev[icnt],
LP8755_EVENT_OCP,
NULL);
if ((flag1 & 0x02) && (pchip->irqmask & 0x02))
for (icnt = 0; icnt < LP8755_BUCK_MAX; icnt++)
if (pchip->rdev[icnt] != NULL)
regulator_notifier_call_chain(pchip->rdev[icnt],
LP8755_EVENT_OVP,
NULL);
return IRQ_HANDLED;
err_i2c:
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return IRQ_NONE;
}
static int lp8755_int_config(struct lp8755_chip *pchip)
{
int ret;
unsigned int regval;
if (pchip->irq == 0) {
dev_warn(pchip->dev, "not use interrupt : %s\n", __func__);
return 0;
}
ret = lp8755_read(pchip, 0x0F, &regval);
if (ret < 0) {
dev_err(pchip->dev, "i2c acceess error %s\n", __func__);
return ret;
}
pchip->irqmask = regval;
return devm_request_threaded_irq(pchip->dev, pchip->irq, NULL,
lp8755_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"lp8755-irq", pchip);
}
static int lp8755_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret, icnt;
struct lp8755_chip *pchip;
struct lp8755_platform_data *pdata = dev_get_platdata(&client->dev);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "i2c functionality check fail.\n");
return -EOPNOTSUPP;
}
pchip = devm_kzalloc(&client->dev,
sizeof(struct lp8755_chip), GFP_KERNEL);
if (!pchip)
return -ENOMEM;
pchip->dev = &client->dev;
pchip->regmap = devm_regmap_init_i2c(client, &lp8755_regmap);
if (IS_ERR(pchip->regmap)) {
ret = PTR_ERR(pchip->regmap);
dev_err(&client->dev, "fail to allocate regmap %d\n", ret);
return ret;
}
i2c_set_clientdata(client, pchip);
if (pdata != NULL) {
pchip->pdata = pdata;
pchip->mphase = pdata->mphase;
} else {
pchip->pdata = devm_kzalloc(pchip->dev,
sizeof(struct lp8755_platform_data),
GFP_KERNEL);
if (!pchip->pdata)
return -ENOMEM;
ret = lp8755_init_data(pchip);
if (ret < 0) {
dev_err(&client->dev, "fail to initialize chip\n");
return ret;
}
}
ret = lp8755_regulator_init(pchip);
if (ret < 0) {
dev_err(&client->dev, "fail to initialize regulators\n");
goto err;
}
pchip->irq = client->irq;
ret = lp8755_int_config(pchip);
if (ret < 0) {
dev_err(&client->dev, "fail to irq config\n");
goto err;
}
return ret;
err:
for (icnt = 0; icnt < LP8755_BUCK_MAX; icnt++)
lp8755_write(pchip, icnt, 0x00);
return ret;
}
static int lp8755_remove(struct i2c_client *client)
{
int icnt;
struct lp8755_chip *pchip = i2c_get_clientdata(client);
for (icnt = 0; icnt < LP8755_BUCK_MAX; icnt++)
lp8755_write(pchip, icnt, 0x00);
return 0;
}
static int __init lp8755_init(void)
{
return i2c_add_driver(&lp8755_i2c_driver);
}
static void __exit lp8755_exit(void)
{
i2c_del_driver(&lp8755_i2c_driver);
}
