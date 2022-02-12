static int lp872x_read_byte(struct lp872x *lp, u8 addr, u8 *data)
{
int ret;
unsigned int val;
ret = regmap_read(lp->regmap, addr, &val);
if (ret < 0) {
dev_err(lp->dev, "failed to read 0x%.2x\n", addr);
return ret;
}
*data = (u8)val;
return 0;
}
static inline int lp872x_write_byte(struct lp872x *lp, u8 addr, u8 data)
{
return regmap_write(lp->regmap, addr, data);
}
static inline int lp872x_update_bits(struct lp872x *lp, u8 addr,
unsigned int mask, u8 data)
{
return regmap_update_bits(lp->regmap, addr, mask, data);
}
static int _rdev_to_offset(struct regulator_dev *rdev)
{
enum lp872x_regulator_id id = rdev_get_id(rdev);
switch (id) {
case LP8720_ID_LDO1 ... LP8720_ID_BUCK:
return id;
case LP8725_ID_LDO1 ... LP8725_ID_BUCK2:
return id - LP8725_ID_BASE;
default:
return -EINVAL;
}
}
static int lp872x_get_timestep_usec(struct lp872x *lp)
{
enum lp872x_id chip = lp->chipid;
u8 val, mask, shift;
int *time_usec, size, ret;
int lp8720_time_usec[] = { 25, 50 };
int lp8725_time_usec[] = { 32, 64, 128, 256 };
switch (chip) {
case LP8720:
mask = LP8720_TIMESTEP_M;
shift = LP8720_TIMESTEP_S;
time_usec = &lp8720_time_usec[0];
size = ARRAY_SIZE(lp8720_time_usec);
break;
case LP8725:
mask = LP8725_TIMESTEP_M;
shift = LP8725_TIMESTEP_S;
time_usec = &lp8725_time_usec[0];
size = ARRAY_SIZE(lp8725_time_usec);
break;
default:
return -EINVAL;
}
ret = lp872x_read_byte(lp, LP872X_GENERAL_CFG, &val);
if (ret)
return -EINVAL;
val = (val & mask) >> shift;
if (val >= size)
return -EINVAL;
return *(time_usec + val);
}
static int lp872x_regulator_enable_time(struct regulator_dev *rdev)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id regulator = rdev_get_id(rdev);
int time_step_us = lp872x_get_timestep_usec(lp);
int ret, offset;
u8 addr, val;
if (time_step_us < 0)
return -EINVAL;
switch (regulator) {
case LP8720_ID_LDO1 ... LP8720_ID_LDO5:
case LP8725_ID_LDO1 ... LP8725_ID_LILO2:
offset = _rdev_to_offset(rdev);
if (offset < 0)
return -EINVAL;
addr = LP872X_LDO1_VOUT + offset;
break;
case LP8720_ID_BUCK:
addr = LP8720_BUCK_VOUT1;
break;
case LP8725_ID_BUCK1:
addr = LP8725_BUCK1_VOUT1;
break;
case LP8725_ID_BUCK2:
addr = LP8725_BUCK2_VOUT1;
break;
default:
return -EINVAL;
}
ret = lp872x_read_byte(lp, addr, &val);
if (ret)
return ret;
val = (val & LP872X_START_DELAY_M) >> LP872X_START_DELAY_S;
return val > MAX_DELAY ? 0 : val * time_step_us;
}
static void lp872x_set_dvs(struct lp872x *lp, int gpio)
{
enum lp872x_dvs_sel dvs_sel = lp->pdata->dvs->vsel;
enum lp872x_dvs_state state;
state = dvs_sel == SEL_V1 ? DVS_HIGH : DVS_LOW;
gpio_set_value(gpio, state);
lp->dvs_pin = state;
}
static u8 lp872x_select_buck_vout_addr(struct lp872x *lp,
enum lp872x_regulator_id buck)
{
u8 val, addr;
if (lp872x_read_byte(lp, LP872X_GENERAL_CFG, &val))
return 0;
switch (buck) {
case LP8720_ID_BUCK:
if (val & LP8720_EXT_DVS_M) {
addr = (lp->dvs_pin == DVS_HIGH) ?
LP8720_BUCK_VOUT1 : LP8720_BUCK_VOUT2;
} else {
if (lp872x_read_byte(lp, LP8720_ENABLE, &val))
return 0;
addr = val & LP8720_DVS_SEL_M ?
LP8720_BUCK_VOUT1 : LP8720_BUCK_VOUT2;
}
break;
case LP8725_ID_BUCK1:
if (val & LP8725_DVS1_M)
addr = LP8725_BUCK1_VOUT1;
else
addr = (lp->dvs_pin == DVS_HIGH) ?
LP8725_BUCK1_VOUT1 : LP8725_BUCK1_VOUT2;
break;
case LP8725_ID_BUCK2:
addr = val & LP8725_DVS2_M ?
LP8725_BUCK2_VOUT1 : LP8725_BUCK2_VOUT2;
break;
default:
return 0;
}
return addr;
}
static bool lp872x_is_valid_buck_addr(u8 addr)
{
switch (addr) {
case LP8720_BUCK_VOUT1:
case LP8720_BUCK_VOUT2:
case LP8725_BUCK1_VOUT1:
case LP8725_BUCK1_VOUT2:
case LP8725_BUCK2_VOUT1:
case LP8725_BUCK2_VOUT2:
return true;
default:
return false;
}
}
static int lp872x_buck_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id buck = rdev_get_id(rdev);
u8 addr, mask = LP872X_VOUT_M;
struct lp872x_dvs *dvs = lp->pdata->dvs;
if (dvs && gpio_is_valid(dvs->gpio))
lp872x_set_dvs(lp, dvs->gpio);
addr = lp872x_select_buck_vout_addr(lp, buck);
if (!lp872x_is_valid_buck_addr(addr))
return -EINVAL;
return lp872x_update_bits(lp, addr, mask, selector);
}
static int lp872x_buck_get_voltage_sel(struct regulator_dev *rdev)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id buck = rdev_get_id(rdev);
u8 addr, val;
int ret;
addr = lp872x_select_buck_vout_addr(lp, buck);
if (!lp872x_is_valid_buck_addr(addr))
return -EINVAL;
ret = lp872x_read_byte(lp, addr, &val);
if (ret)
return ret;
return val & LP872X_VOUT_M;
}
static int lp8725_buck_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id buck = rdev_get_id(rdev);
int i, max = ARRAY_SIZE(lp8725_buck_uA);
u8 addr, val;
switch (buck) {
case LP8725_ID_BUCK1:
addr = LP8725_BUCK1_VOUT2;
break;
case LP8725_ID_BUCK2:
addr = LP8725_BUCK2_VOUT2;
break;
default:
return -EINVAL;
}
for (i = 0 ; i < max ; i++)
if (lp8725_buck_uA[i] >= min_uA &&
lp8725_buck_uA[i] <= max_uA)
break;
if (i == max)
return -EINVAL;
val = i << LP8725_BUCK_CL_S;
return lp872x_update_bits(lp, addr, LP8725_BUCK_CL_M, val);
}
static int lp8725_buck_get_current_limit(struct regulator_dev *rdev)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id buck = rdev_get_id(rdev);
u8 addr, val;
int ret;
switch (buck) {
case LP8725_ID_BUCK1:
addr = LP8725_BUCK1_VOUT2;
break;
case LP8725_ID_BUCK2:
addr = LP8725_BUCK2_VOUT2;
break;
default:
return -EINVAL;
}
ret = lp872x_read_byte(lp, addr, &val);
if (ret)
return ret;
val = (val & LP8725_BUCK_CL_M) >> LP8725_BUCK_CL_S;
return (val < ARRAY_SIZE(lp8725_buck_uA)) ?
lp8725_buck_uA[val] : -EINVAL;
}
static int lp872x_buck_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id buck = rdev_get_id(rdev);
u8 addr, mask, shift, val;
switch (buck) {
case LP8720_ID_BUCK:
addr = LP8720_BUCK_VOUT2;
mask = LP8720_BUCK_FPWM_M;
shift = LP8720_BUCK_FPWM_S;
break;
case LP8725_ID_BUCK1:
addr = LP8725_BUCK_CTRL;
mask = LP8725_BUCK1_FPWM_M;
shift = LP8725_BUCK1_FPWM_S;
break;
case LP8725_ID_BUCK2:
addr = LP8725_BUCK_CTRL;
mask = LP8725_BUCK2_FPWM_M;
shift = LP8725_BUCK2_FPWM_S;
break;
default:
return -EINVAL;
}
if (mode == REGULATOR_MODE_FAST)
val = LP872X_FORCE_PWM << shift;
else if (mode == REGULATOR_MODE_NORMAL)
val = LP872X_AUTO_PWM << shift;
else
return -EINVAL;
return lp872x_update_bits(lp, addr, mask, val);
}
static unsigned int lp872x_buck_get_mode(struct regulator_dev *rdev)
{
struct lp872x *lp = rdev_get_drvdata(rdev);
enum lp872x_regulator_id buck = rdev_get_id(rdev);
u8 addr, mask, val;
int ret;
switch (buck) {
case LP8720_ID_BUCK:
addr = LP8720_BUCK_VOUT2;
mask = LP8720_BUCK_FPWM_M;
break;
case LP8725_ID_BUCK1:
addr = LP8725_BUCK_CTRL;
mask = LP8725_BUCK1_FPWM_M;
break;
case LP8725_ID_BUCK2:
addr = LP8725_BUCK_CTRL;
mask = LP8725_BUCK2_FPWM_M;
break;
default:
return -EINVAL;
}
ret = lp872x_read_byte(lp, addr, &val);
if (ret)
return ret;
return val & mask ? REGULATOR_MODE_FAST : REGULATOR_MODE_NORMAL;
}
static int lp872x_check_dvs_validity(struct lp872x *lp)
{
struct lp872x_dvs *dvs = lp->pdata->dvs;
u8 val = 0;
int ret;
ret = lp872x_read_byte(lp, LP872X_GENERAL_CFG, &val);
if (ret)
return ret;
ret = 0;
if (lp->chipid == LP8720) {
if (val & LP8720_EXT_DVS_M)
ret = dvs ? 0 : -EINVAL;
} else {
if ((val & LP8725_DVS1_M) == EXTERN_DVS_USED)
ret = dvs ? 0 : -EINVAL;
}
return ret;
}
static int lp872x_init_dvs(struct lp872x *lp)
{
int ret, gpio;
struct lp872x_dvs *dvs = lp->pdata->dvs;
enum lp872x_dvs_state pinstate;
ret = lp872x_check_dvs_validity(lp);
if (ret) {
dev_warn(lp->dev, "invalid dvs data: %d\n", ret);
return ret;
}
gpio = dvs->gpio;
if (!gpio_is_valid(gpio)) {
dev_err(lp->dev, "invalid gpio: %d\n", gpio);
return -EINVAL;
}
pinstate = dvs->init_state;
ret = devm_gpio_request_one(lp->dev, gpio, pinstate, "LP872X DVS");
if (ret) {
dev_err(lp->dev, "gpio request err: %d\n", ret);
return ret;
}
lp->dvs_pin = pinstate;
lp->dvs_gpio = gpio;
return 0;
}
static int lp872x_config(struct lp872x *lp)
{
struct lp872x_platform_data *pdata = lp->pdata;
int ret;
if (!pdata->update_config)
return 0;
ret = lp872x_write_byte(lp, LP872X_GENERAL_CFG, pdata->general_config);
if (ret)
return ret;
return lp872x_init_dvs(lp);
}
static struct regulator_init_data
*lp872x_find_regulator_init_data(int id, struct lp872x *lp)
{
int i;
for (i = 0; i < lp->num_regulators; i++) {
if (lp->pdata->regulator_data[i].id == id)
return lp->pdata->regulator_data[i].init_data;
}
return NULL;
}
static int lp872x_regulator_register(struct lp872x *lp)
{
struct regulator_desc *desc;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
int i, ret;
for (i = 0 ; i < lp->num_regulators ; i++) {
desc = (lp->chipid == LP8720) ? &lp8720_regulator_desc[i] :
&lp8725_regulator_desc[i];
cfg.dev = lp->dev;
cfg.init_data = lp872x_find_regulator_init_data(desc->id, lp);
cfg.driver_data = lp;
cfg.regmap = lp->regmap;
rdev = regulator_register(desc, &cfg);
if (IS_ERR(rdev)) {
dev_err(lp->dev, "regulator register err");
ret = PTR_ERR(rdev);
goto err;
}
*(lp->regulators + i) = rdev;
}
return 0;
err:
while (--i >= 0) {
rdev = *(lp->regulators + i);
regulator_unregister(rdev);
}
return ret;
}
static void lp872x_regulator_unregister(struct lp872x *lp)
{
struct regulator_dev *rdev;
int i;
for (i = 0 ; i < lp->num_regulators ; i++) {
rdev = *(lp->regulators + i);
regulator_unregister(rdev);
}
}
static int lp872x_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct lp872x *lp;
struct lp872x_platform_data *pdata = cl->dev.platform_data;
int ret, size, num_regulators;
const int lp872x_num_regulators[] = {
[LP8720] = LP8720_NUM_REGULATORS,
[LP8725] = LP8725_NUM_REGULATORS,
};
if (!pdata) {
dev_err(&cl->dev, "no platform data\n");
return -EINVAL;
}
lp = devm_kzalloc(&cl->dev, sizeof(struct lp872x), GFP_KERNEL);
if (!lp)
goto err_mem;
num_regulators = lp872x_num_regulators[id->driver_data];
size = sizeof(struct regulator_dev *) * num_regulators;
lp->regulators = devm_kzalloc(&cl->dev, size, GFP_KERNEL);
if (!lp->regulators)
goto err_mem;
lp->regmap = devm_regmap_init_i2c(cl, &lp872x_regmap_config);
if (IS_ERR(lp->regmap)) {
ret = PTR_ERR(lp->regmap);
dev_err(&cl->dev, "regmap init i2c err: %d\n", ret);
goto err_dev;
}
lp->dev = &cl->dev;
lp->pdata = pdata;
lp->chipid = id->driver_data;
lp->num_regulators = num_regulators;
i2c_set_clientdata(cl, lp);
ret = lp872x_config(lp);
if (ret)
goto err_dev;
return lp872x_regulator_register(lp);
err_mem:
return -ENOMEM;
err_dev:
return ret;
}
static int __devexit lp872x_remove(struct i2c_client *cl)
{
struct lp872x *lp = i2c_get_clientdata(cl);
lp872x_regulator_unregister(lp);
return 0;
}
