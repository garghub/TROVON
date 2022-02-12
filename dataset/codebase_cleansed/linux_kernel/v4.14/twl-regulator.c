static inline int
twlreg_read(struct twlreg_info *info, unsigned slave_subgp, unsigned offset)
{
u8 value;
int status;
status = twl_i2c_read_u8(slave_subgp,
&value, info->base + offset);
return (status < 0) ? status : value;
}
static inline int
twlreg_write(struct twlreg_info *info, unsigned slave_subgp, unsigned offset,
u8 value)
{
return twl_i2c_write_u8(slave_subgp,
value, info->base + offset);
}
static int twlreg_grp(struct regulator_dev *rdev)
{
return twlreg_read(rdev_get_drvdata(rdev), TWL_MODULE_PM_RECEIVER,
VREG_GRP);
}
static int twl4030reg_is_enabled(struct regulator_dev *rdev)
{
int state = twlreg_grp(rdev);
if (state < 0)
return state;
return state & P1_GRP_4030;
}
static int twl4030_wait_pb_ready(void)
{
int ret;
int timeout = 10;
u8 val;
do {
ret = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &val,
TWL4030_PM_MASTER_PB_CFG);
if (ret < 0)
return ret;
if (!(val & PB_I2C_BUSY))
return 0;
mdelay(1);
timeout--;
} while (timeout);
return -ETIMEDOUT;
}
static int twl4030_send_pb_msg(unsigned msg)
{
u8 val;
int ret;
ret = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &val,
TWL4030_PM_MASTER_PB_CFG);
if (ret < 0)
return ret;
ret = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, val | PB_I2C_BWEN,
TWL4030_PM_MASTER_PB_CFG);
if (ret < 0)
return ret;
ret = twl4030_wait_pb_ready();
if (ret < 0)
return ret;
ret = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, msg >> 8,
TWL4030_PM_MASTER_PB_WORD_MSB);
if (ret < 0)
return ret;
ret = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, msg & 0xff,
TWL4030_PM_MASTER_PB_WORD_LSB);
if (ret < 0)
return ret;
ret = twl4030_wait_pb_ready();
if (ret < 0)
return ret;
return twl_i2c_write_u8(TWL_MODULE_PM_MASTER, val,
TWL4030_PM_MASTER_PB_CFG);
}
static int twl4030reg_enable(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp;
int ret;
grp = twlreg_grp(rdev);
if (grp < 0)
return grp;
grp |= P1_GRP_4030;
ret = twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_GRP, grp);
return ret;
}
static int twl4030reg_disable(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp;
int ret;
grp = twlreg_grp(rdev);
if (grp < 0)
return grp;
grp &= ~(P1_GRP_4030 | P2_GRP_4030 | P3_GRP_4030);
ret = twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_GRP, grp);
return ret;
}
static int twl4030reg_get_status(struct regulator_dev *rdev)
{
int state = twlreg_grp(rdev);
if (state < 0)
return state;
state &= 0x0f;
if (!state)
return REGULATOR_STATUS_OFF;
return (state & BIT(3))
? REGULATOR_STATUS_NORMAL
: REGULATOR_STATUS_STANDBY;
}
static int twl4030reg_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
unsigned message;
switch (mode) {
case REGULATOR_MODE_NORMAL:
message = MSG_SINGULAR(DEV_GRP_P1, info->id, RES_STATE_ACTIVE);
break;
case REGULATOR_MODE_STANDBY:
message = MSG_SINGULAR(DEV_GRP_P1, info->id, RES_STATE_SLEEP);
break;
default:
return -EINVAL;
}
return twl4030_send_pb_msg(message);
}
static inline unsigned int twl4030reg_map_mode(unsigned int mode)
{
switch (mode) {
case RES_STATE_ACTIVE:
return REGULATOR_MODE_NORMAL;
case RES_STATE_SLEEP:
return REGULATOR_MODE_STANDBY;
default:
return -EINVAL;
}
}
static int twl4030ldo_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int mV = info->table[index];
return IS_UNSUP(info, mV) ? 0 : (LDO_MV(mV) * 1000);
}
static int
twl4030ldo_set_voltage_sel(struct regulator_dev *rdev, unsigned selector)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
return twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_VOLTAGE,
selector);
}
static int twl4030ldo_get_voltage_sel(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_VOLTAGE);
if (vsel < 0)
return vsel;
vsel &= info->table_len - 1;
return vsel;
}
static int
twl4030smps_set_voltage(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned *selector)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel = DIV_ROUND_UP(min_uV - 600000, 12500);
twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_VOLTAGE_SMPS_4030, vsel);
return 0;
}
static int twl4030smps_get_voltage(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel;
vsel = twlreg_read(info, TWL_MODULE_PM_RECEIVER,
VREG_VOLTAGE_SMPS_4030);
return vsel * 12500 + 600000;
}
static int twlreg_probe(struct platform_device *pdev)
{
int id;
struct twlreg_info *info;
const struct twlreg_info *template;
struct regulator_init_data *initdata;
struct regulation_constraints *c;
struct regulator_dev *rdev;
const struct of_device_id *match;
struct regulator_config config = { };
match = of_match_device(twl_of_match, &pdev->dev);
if (!match)
return -ENODEV;
template = match->data;
if (!template)
return -ENODEV;
id = template->desc.id;
initdata = of_get_regulator_init_data(&pdev->dev, pdev->dev.of_node,
&template->desc);
if (!initdata)
return -EINVAL;
info = devm_kmemdup(&pdev->dev, template, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
c = &initdata->constraints;
c->valid_modes_mask &= REGULATOR_MODE_NORMAL | REGULATOR_MODE_STANDBY;
c->valid_ops_mask &= REGULATOR_CHANGE_VOLTAGE
| REGULATOR_CHANGE_MODE
| REGULATOR_CHANGE_STATUS;
switch (id) {
case TWL4030_REG_VIO:
case TWL4030_REG_VDD1:
case TWL4030_REG_VDD2:
case TWL4030_REG_VPLL1:
case TWL4030_REG_VINTANA1:
case TWL4030_REG_VINTANA2:
case TWL4030_REG_VINTDIG:
c->always_on = true;
break;
default:
break;
}
config.dev = &pdev->dev;
config.init_data = initdata;
config.driver_data = info;
config.of_node = pdev->dev.of_node;
rdev = devm_regulator_register(&pdev->dev, &info->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "can't register %s, %ld\n",
info->desc.name, PTR_ERR(rdev));
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_REMAP, info->remap);
return 0;
}
static int __init twlreg_init(void)
{
return platform_driver_register(&twlreg_driver);
}
static void __exit twlreg_exit(void)
{
platform_driver_unregister(&twlreg_driver);
}
