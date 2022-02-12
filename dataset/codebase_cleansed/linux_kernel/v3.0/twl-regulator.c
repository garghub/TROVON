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
static int twl6030reg_is_enabled(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp = 0, val;
if (!(twl_class_is_6030() && (info->features & TWL6025_SUBCLASS)))
grp = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_GRP);
if (grp < 0)
return grp;
if (!(twl_class_is_6030() && (info->features & TWL6025_SUBCLASS)))
grp &= P1_GRP_6030;
else
grp = 1;
val = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_STATE);
val = TWL6030_CFG_STATE_APP(val);
return grp && (val == TWL6030_CFG_STATE_ON);
}
static int twl4030reg_enable(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp;
int ret;
grp = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_GRP);
if (grp < 0)
return grp;
grp |= P1_GRP_4030;
ret = twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_GRP, grp);
udelay(info->delay);
return ret;
}
static int twl6030reg_enable(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp = 0;
int ret;
if (!(twl_class_is_6030() && (info->features & TWL6025_SUBCLASS)))
grp = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_GRP);
if (grp < 0)
return grp;
ret = twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_STATE,
grp << TWL6030_CFG_STATE_GRP_SHIFT |
TWL6030_CFG_STATE_ON);
udelay(info->delay);
return ret;
}
static int twl4030reg_disable(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp;
int ret;
grp = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_GRP);
if (grp < 0)
return grp;
grp &= ~(P1_GRP_4030 | P2_GRP_4030 | P3_GRP_4030);
ret = twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_GRP, grp);
return ret;
}
static int twl6030reg_disable(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp = 0;
int ret;
if (!(twl_class_is_6030() && (info->features & TWL6025_SUBCLASS)))
grp = P1_GRP_6030 | P2_GRP_6030 | P3_GRP_6030;
ret = twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_STATE,
(grp) << TWL6030_CFG_STATE_GRP_SHIFT |
TWL6030_CFG_STATE_OFF);
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
static int twl6030reg_get_status(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int val;
val = twlreg_grp(rdev);
if (val < 0)
return val;
val = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_STATE);
switch (TWL6030_CFG_STATE_APP(val)) {
case TWL6030_CFG_STATE_ON:
return REGULATOR_STATUS_NORMAL;
case TWL6030_CFG_STATE_SLEEP:
return REGULATOR_STATUS_STANDBY;
case TWL6030_CFG_STATE_OFF:
case TWL6030_CFG_STATE_OFF2:
default:
break;
}
return REGULATOR_STATUS_OFF;
}
static int twl4030reg_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
unsigned message;
int status;
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
status = twlreg_grp(rdev);
if (status < 0)
return status;
if (!(status & (P3_GRP_4030 | P2_GRP_4030 | P1_GRP_4030)))
return -EACCES;
status = twl_i2c_write_u8(TWL_MODULE_PM_MASTER,
message >> 8, TWL4030_PM_MASTER_PB_WORD_MSB);
if (status < 0)
return status;
return twl_i2c_write_u8(TWL_MODULE_PM_MASTER,
message & 0xff, TWL4030_PM_MASTER_PB_WORD_LSB);
}
static int twl6030reg_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int grp = 0;
int val;
if (!(twl_class_is_6030() && (info->features & TWL6025_SUBCLASS)))
grp = twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_GRP);
if (grp < 0)
return grp;
val = grp << TWL6030_CFG_STATE_GRP_SHIFT;
switch (mode) {
case REGULATOR_MODE_NORMAL:
val |= TWL6030_CFG_STATE_ON;
break;
case REGULATOR_MODE_STANDBY:
val |= TWL6030_CFG_STATE_SLEEP;
break;
default:
return -EINVAL;
}
return twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_STATE, val);
}
static int twl4030ldo_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int mV = info->table[index];
return IS_UNSUP(mV) ? 0 : (LDO_MV(mV) * 1000);
}
static int
twl4030ldo_set_voltage(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned *selector)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel;
for (vsel = 0; vsel < info->table_len; vsel++) {
int mV = info->table[vsel];
int uV;
if (IS_UNSUP(mV))
continue;
uV = LDO_MV(mV) * 1000;
if (min_uV <= uV && uV <= max_uV) {
*selector = vsel;
return twlreg_write(info, TWL_MODULE_PM_RECEIVER,
VREG_VOLTAGE, vsel);
}
}
return -EDOM;
}
static int twl4030ldo_get_voltage(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel = twlreg_read(info, TWL_MODULE_PM_RECEIVER,
VREG_VOLTAGE);
if (vsel < 0)
return vsel;
vsel &= info->table_len - 1;
return LDO_MV(info->table[vsel]) * 1000;
}
static int twl6030ldo_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
return ((info->min_mV + (index * 100)) * 1000);
}
static int
twl6030ldo_set_voltage(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned *selector)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel;
if ((min_uV/1000 < info->min_mV) || (max_uV/1000 > info->max_mV))
return -EDOM;
vsel = (min_uV/1000 - 1000)/100 + 1;
*selector = vsel;
return twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_VOLTAGE, vsel);
}
static int twl6030ldo_get_voltage(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel = twlreg_read(info, TWL_MODULE_PM_RECEIVER,
VREG_VOLTAGE);
if (vsel < 0)
return vsel;
return (1000 + (100 * (vsel - 1))) * 1000;
}
static int twlfixed_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
return info->min_mV * 1000;
}
static int twlfixed_get_voltage(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
return info->min_mV * 1000;
}
static int twl6030smps_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int voltage = 0;
switch (info->flags) {
case SMPS_OFFSET_EN:
voltage = 100000;
case 0:
switch (index) {
case 0:
voltage = 0;
break;
case 58:
voltage = 1350 * 1000;
break;
case 59:
voltage = 1500 * 1000;
break;
case 60:
voltage = 1800 * 1000;
break;
case 61:
voltage = 1900 * 1000;
break;
case 62:
voltage = 2100 * 1000;
break;
default:
voltage += (600000 + (12500 * (index - 1)));
}
break;
case SMPS_EXTENDED_EN:
switch (index) {
case 0:
voltage = 0;
break;
case 58:
voltage = 2084 * 1000;
break;
case 59:
voltage = 2315 * 1000;
break;
case 60:
voltage = 2778 * 1000;
break;
case 61:
voltage = 2932 * 1000;
break;
case 62:
voltage = 3241 * 1000;
break;
default:
voltage = (1852000 + (38600 * (index - 1)));
}
break;
case SMPS_OFFSET_EN | SMPS_EXTENDED_EN:
switch (index) {
case 0:
voltage = 0;
break;
case 58:
voltage = 4167 * 1000;
break;
case 59:
voltage = 2315 * 1000;
break;
case 60:
voltage = 2778 * 1000;
break;
case 61:
voltage = 2932 * 1000;
break;
case 62:
voltage = 3241 * 1000;
break;
default:
voltage = (2161000 + (38600 * (index - 1)));
}
break;
}
return voltage;
}
static int
twl6030smps_set_voltage(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned int *selector)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
int vsel = 0;
switch (info->flags) {
case 0:
if (min_uV == 0)
vsel = 0;
else if ((min_uV >= 600000) && (max_uV <= 1300000)) {
vsel = (min_uV - 600000) / 125;
if (vsel % 100)
vsel += 100;
vsel /= 100;
vsel++;
}
else if ((min_uV > 1900000) && (max_uV >= 2100000))
vsel = 62;
else if ((min_uV > 1800000) && (max_uV >= 1900000))
vsel = 61;
else if ((min_uV > 1500000) && (max_uV >= 1800000))
vsel = 60;
else if ((min_uV > 1350000) && (max_uV >= 1500000))
vsel = 59;
else if ((min_uV > 1300000) && (max_uV >= 1350000))
vsel = 58;
else
return -EINVAL;
break;
case SMPS_OFFSET_EN:
if (min_uV == 0)
vsel = 0;
else if ((min_uV >= 700000) && (max_uV <= 1420000)) {
vsel = (min_uV - 700000) / 125;
if (vsel % 100)
vsel += 100;
vsel /= 100;
vsel++;
}
else if ((min_uV > 1900000) && (max_uV >= 2100000))
vsel = 62;
else if ((min_uV > 1800000) && (max_uV >= 1900000))
vsel = 61;
else if ((min_uV > 1350000) && (max_uV >= 1800000))
vsel = 60;
else if ((min_uV > 1350000) && (max_uV >= 1500000))
vsel = 59;
else if ((min_uV > 1300000) && (max_uV >= 1350000))
vsel = 58;
else
return -EINVAL;
break;
case SMPS_EXTENDED_EN:
if (min_uV == 0)
vsel = 0;
else if ((min_uV >= 1852000) && (max_uV <= 4013600)) {
vsel = (min_uV - 1852000) / 386;
if (vsel % 100)
vsel += 100;
vsel /= 100;
vsel++;
}
break;
case SMPS_OFFSET_EN|SMPS_EXTENDED_EN:
if (min_uV == 0)
vsel = 0;
else if ((min_uV >= 2161000) && (max_uV <= 4321000)) {
vsel = (min_uV - 1852000) / 386;
if (vsel % 100)
vsel += 100;
vsel /= 100;
vsel++;
}
break;
}
*selector = vsel;
return twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_VOLTAGE_SMPS,
vsel);
}
static int twl6030smps_get_voltage_sel(struct regulator_dev *rdev)
{
struct twlreg_info *info = rdev_get_drvdata(rdev);
return twlreg_read(info, TWL_MODULE_PM_RECEIVER, VREG_VOLTAGE_SMPS);
}
static u8 twl_get_smps_offset(void)
{
u8 value;
twl_i2c_read_u8(TWL_MODULE_PM_RECEIVER, &value,
TWL6030_SMPS_OFFSET);
return value;
}
static u8 twl_get_smps_mult(void)
{
u8 value;
twl_i2c_read_u8(TWL_MODULE_PM_RECEIVER, &value,
TWL6030_SMPS_MULT);
return value;
}
static int __devinit twlreg_probe(struct platform_device *pdev)
{
int i;
struct twlreg_info *info;
struct regulator_init_data *initdata;
struct regulation_constraints *c;
struct regulator_dev *rdev;
for (i = 0, info = NULL; i < ARRAY_SIZE(twl_regs); i++) {
if (twl_regs[i].desc.id != pdev->id)
continue;
info = twl_regs + i;
break;
}
if (!info)
return -ENODEV;
initdata = pdev->dev.platform_data;
if (!initdata)
return -EINVAL;
info->features = (unsigned long)initdata->driver_data;
c = &initdata->constraints;
c->valid_modes_mask &= REGULATOR_MODE_NORMAL | REGULATOR_MODE_STANDBY;
c->valid_ops_mask &= REGULATOR_CHANGE_VOLTAGE
| REGULATOR_CHANGE_MODE
| REGULATOR_CHANGE_STATUS;
switch (pdev->id) {
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
switch (pdev->id) {
case TWL6025_REG_SMPS3:
if (twl_get_smps_mult() & SMPS_MULTOFFSET_SMPS3)
info->flags |= SMPS_EXTENDED_EN;
if (twl_get_smps_offset() & SMPS_MULTOFFSET_SMPS3)
info->flags |= SMPS_OFFSET_EN;
break;
case TWL6025_REG_SMPS4:
if (twl_get_smps_mult() & SMPS_MULTOFFSET_SMPS4)
info->flags |= SMPS_EXTENDED_EN;
if (twl_get_smps_offset() & SMPS_MULTOFFSET_SMPS4)
info->flags |= SMPS_OFFSET_EN;
break;
case TWL6025_REG_VIO:
if (twl_get_smps_mult() & SMPS_MULTOFFSET_VIO)
info->flags |= SMPS_EXTENDED_EN;
if (twl_get_smps_offset() & SMPS_MULTOFFSET_VIO)
info->flags |= SMPS_OFFSET_EN;
break;
}
rdev = regulator_register(&info->desc, &pdev->dev, initdata, info);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "can't register %s, %ld\n",
info->desc.name, PTR_ERR(rdev));
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
if (twl_class_is_4030())
twlreg_write(info, TWL_MODULE_PM_RECEIVER, VREG_REMAP,
info->remap);
return 0;
}
static int __devexit twlreg_remove(struct platform_device *pdev)
{
regulator_unregister(platform_get_drvdata(pdev));
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
