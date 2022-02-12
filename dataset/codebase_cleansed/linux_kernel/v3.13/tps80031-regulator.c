static inline struct device *to_tps80031_dev(struct regulator_dev *rdev)
{
return rdev_get_dev(rdev)->parent->parent;
}
static int tps80031_reg_is_enabled(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
u8 reg_val;
int ret;
if (ri->ext_ctrl_flag & TPS80031_EXT_PWR_REQ)
return true;
ret = tps80031_read(parent, TPS80031_SLAVE_ID1, ri->rinfo->state_reg,
&reg_val);
if (ret < 0) {
dev_err(&rdev->dev, "Reg 0x%02x read failed, err = %d\n",
ri->rinfo->state_reg, ret);
return ret;
}
return ((reg_val & TPS80031_STATE_MASK) == TPS80031_STATE_ON);
}
static int tps80031_reg_enable(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
int ret;
if (ri->ext_ctrl_flag & TPS80031_EXT_PWR_REQ)
return 0;
ret = tps80031_update(parent, TPS80031_SLAVE_ID1, ri->rinfo->state_reg,
TPS80031_STATE_ON, TPS80031_STATE_MASK);
if (ret < 0) {
dev_err(&rdev->dev, "Reg 0x%02x update failed, err = %d\n",
ri->rinfo->state_reg, ret);
return ret;
}
return ret;
}
static int tps80031_reg_disable(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
int ret;
if (ri->ext_ctrl_flag & TPS80031_EXT_PWR_REQ)
return 0;
ret = tps80031_update(parent, TPS80031_SLAVE_ID1, ri->rinfo->state_reg,
TPS80031_STATE_OFF, TPS80031_STATE_MASK);
if (ret < 0)
dev_err(&rdev->dev, "Reg 0x%02x update failed, err = %d\n",
ri->rinfo->state_reg, ret);
return ret;
}
static int tps80031_dcdc_list_voltage(struct regulator_dev *rdev, unsigned sel)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
int volt_index = ri->device_flags & 0x3;
if (sel == 0)
return 0;
else if (sel < 58)
return regulator_list_voltage_linear(rdev, sel - 1);
else
return tps80031_dcdc_voltages[volt_index][sel - 58] * 1000;
}
static int tps80031_dcdc_set_voltage_sel(struct regulator_dev *rdev,
unsigned vsel)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
int ret;
u8 reg_val;
if (ri->rinfo->force_reg) {
ret = tps80031_read(parent, ri->rinfo->volt_id,
ri->rinfo->force_reg, &reg_val);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
ri->rinfo->force_reg, ret);
return ret;
}
if (!(reg_val & SMPS_CMD_MASK)) {
ret = tps80031_update(parent, ri->rinfo->volt_id,
ri->rinfo->force_reg, vsel, SMPS_VSEL_MASK);
if (ret < 0)
dev_err(ri->dev,
"reg 0x%02x update failed, e = %d\n",
ri->rinfo->force_reg, ret);
return ret;
}
}
ret = tps80031_update(parent, ri->rinfo->volt_id,
ri->rinfo->volt_reg, vsel, SMPS_VSEL_MASK);
if (ret < 0)
dev_err(ri->dev, "reg 0x%02x update failed, e = %d\n",
ri->rinfo->volt_reg, ret);
return ret;
}
static int tps80031_dcdc_get_voltage_sel(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
uint8_t vsel = 0;
int ret;
if (ri->rinfo->force_reg) {
ret = tps80031_read(parent, ri->rinfo->volt_id,
ri->rinfo->force_reg, &vsel);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
ri->rinfo->force_reg, ret);
return ret;
}
if (!(vsel & SMPS_CMD_MASK))
return vsel & SMPS_VSEL_MASK;
}
ret = tps80031_read(parent, ri->rinfo->volt_id,
ri->rinfo->volt_reg, &vsel);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
ri->rinfo->volt_reg, ret);
return ret;
}
return vsel & SMPS_VSEL_MASK;
}
static int tps80031_ldo_list_voltage(struct regulator_dev *rdev,
unsigned int sel)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
if ((ri->rinfo->desc.id == TPS80031_REGULATOR_LDO2) &&
(ri->device_flags & TRACK_MODE_ENABLE)) {
unsigned nvsel = (sel) & 0x1F;
if (((tps80031_get_chip_info(parent) == TPS80031) ||
((tps80031_get_chip_info(parent) == TPS80032) &&
(tps80031_get_pmu_version(parent) == 0x0))) &&
((nvsel == 0x0) || (nvsel >= 0x19 && nvsel <= 0x1F))) {
dev_err(ri->dev,
"Invalid sel %d in track mode LDO2\n",
nvsel);
return -EINVAL;
}
}
return regulator_list_voltage_linear(rdev, sel);
}
static int tps80031_ldo_map_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
if ((ri->rinfo->desc.id == TPS80031_REGULATOR_LDO2) &&
(ri->device_flags & TRACK_MODE_ENABLE)) {
if (((tps80031_get_chip_info(parent) == TPS80031) ||
((tps80031_get_chip_info(parent) == TPS80032) &&
(tps80031_get_pmu_version(parent) == 0x0)))) {
return regulator_map_voltage_iterate(rdev, min_uV,
max_uV);
}
}
return regulator_map_voltage_linear(rdev, min_uV, max_uV);
}
static int tps80031_vbus_is_enabled(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
int ret = -EIO;
uint8_t ctrl1 = 0;
uint8_t ctrl3 = 0;
ret = tps80031_read(parent, TPS80031_SLAVE_ID2,
TPS80031_CHARGERUSB_CTRL1, &ctrl1);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
TPS80031_CHARGERUSB_CTRL1, ret);
return ret;
}
ret = tps80031_read(parent, TPS80031_SLAVE_ID2,
TPS80031_CHARGERUSB_CTRL3, &ctrl3);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
TPS80031_CHARGERUSB_CTRL3, ret);
return ret;
}
if ((ctrl1 & OPA_MODE_EN) && (ctrl3 & BOOST_HW_PWR_EN))
return 1;
return ret;
}
static int tps80031_vbus_enable(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
int ret;
ret = tps80031_set_bits(parent, TPS80031_SLAVE_ID2,
TPS80031_CHARGERUSB_CTRL1, OPA_MODE_EN);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
TPS80031_CHARGERUSB_CTRL1, ret);
return ret;
}
ret = tps80031_set_bits(parent, TPS80031_SLAVE_ID2,
TPS80031_CHARGERUSB_CTRL3, BOOST_HW_PWR_EN);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x read failed, e = %d\n",
TPS80031_CHARGERUSB_CTRL3, ret);
return ret;
}
return ret;
}
static int tps80031_vbus_disable(struct regulator_dev *rdev)
{
struct tps80031_regulator *ri = rdev_get_drvdata(rdev);
struct device *parent = to_tps80031_dev(rdev);
int ret = 0;
if (ri->config_flags & TPS80031_VBUS_DISCHRG_EN_PDN) {
ret = tps80031_write(parent, TPS80031_SLAVE_ID2,
USB_VBUS_CTRL_SET, VBUS_DISCHRG);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x write failed, e = %d\n",
USB_VBUS_CTRL_SET, ret);
return ret;
}
}
ret = tps80031_clr_bits(parent, TPS80031_SLAVE_ID2,
TPS80031_CHARGERUSB_CTRL1, OPA_MODE_EN);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x clearbit failed, e = %d\n",
TPS80031_CHARGERUSB_CTRL1, ret);
return ret;
}
ret = tps80031_clr_bits(parent, TPS80031_SLAVE_ID2,
TPS80031_CHARGERUSB_CTRL3, BOOST_HW_PWR_EN);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x clearbit failed, e = %d\n",
TPS80031_CHARGERUSB_CTRL3, ret);
return ret;
}
mdelay(DIV_ROUND_UP(ri->rinfo->desc.enable_time, 1000));
if (ri->config_flags & TPS80031_VBUS_DISCHRG_EN_PDN) {
ret = tps80031_write(parent, TPS80031_SLAVE_ID2,
USB_VBUS_CTRL_CLR, VBUS_DISCHRG);
if (ret < 0) {
dev_err(ri->dev, "reg 0x%02x write failed, e = %d\n",
USB_VBUS_CTRL_CLR, ret);
return ret;
}
}
return ret;
}
static int tps80031_power_req_config(struct device *parent,
struct tps80031_regulator *ri,
struct tps80031_regulator_platform_data *tps80031_pdata)
{
int ret = 0;
if (ri->rinfo->preq_bit < 0)
goto skip_pwr_req_config;
ret = tps80031_ext_power_req_config(parent, ri->ext_ctrl_flag,
ri->rinfo->preq_bit, ri->rinfo->state_reg,
ri->rinfo->trans_reg);
if (ret < 0) {
dev_err(ri->dev, "ext powerreq config failed, err = %d\n", ret);
return ret;
}
skip_pwr_req_config:
if (tps80031_pdata->ext_ctrl_flag & TPS80031_PWR_ON_ON_SLEEP) {
ret = tps80031_update(parent, TPS80031_SLAVE_ID1,
ri->rinfo->trans_reg, TPS80031_TRANS_SLEEP_ON,
TPS80031_TRANS_SLEEP_MASK);
if (ret < 0) {
dev_err(ri->dev, "Reg 0x%02x update failed, e %d\n",
ri->rinfo->trans_reg, ret);
return ret;
}
}
return ret;
}
static int tps80031_regulator_config(struct device *parent,
struct tps80031_regulator *ri,
struct tps80031_regulator_platform_data *tps80031_pdata)
{
int ret = 0;
switch (ri->rinfo->desc.id) {
case TPS80031_REGULATOR_LDOUSB:
if (ri->config_flags & (TPS80031_USBLDO_INPUT_VSYS |
TPS80031_USBLDO_INPUT_PMID)) {
unsigned val = 0;
if (ri->config_flags & TPS80031_USBLDO_INPUT_VSYS)
val = MISC2_LDOUSB_IN_VSYS;
else
val = MISC2_LDOUSB_IN_PMID;
ret = tps80031_update(parent, TPS80031_SLAVE_ID1,
TPS80031_MISC2, val,
MISC2_LDOUSB_IN_MASK);
if (ret < 0) {
dev_err(ri->dev,
"LDOUSB config failed, e= %d\n", ret);
return ret;
}
}
break;
case TPS80031_REGULATOR_LDO3:
if (ri->config_flags & TPS80031_LDO3_OUTPUT_VIB) {
ret = tps80031_update(parent, TPS80031_SLAVE_ID1,
TPS80031_MISC2, MISC2_LDO3_SEL_VIB_VAL,
MISC2_LDO3_SEL_VIB_MASK);
if (ret < 0) {
dev_err(ri->dev,
"LDO3 config failed, e = %d\n", ret);
return ret;
}
}
break;
case TPS80031_REGULATOR_VBUS:
if (!(ri->config_flags & TPS80031_VBUS_SW_ONLY))
ri->rinfo->desc.ops = &tps80031_vbus_sw_ops;
break;
default:
break;
}
ret = tps80031_update(parent, TPS80031_SLAVE_ID1, ri->rinfo->trans_reg,
TPS80031_TRANS_ACTIVE_ON | TPS80031_TRANS_SLEEP_OFF |
TPS80031_TRANS_OFF_OFF, TPS80031_TRANS_ACTIVE_MASK |
TPS80031_TRANS_SLEEP_MASK | TPS80031_TRANS_OFF_MASK);
if (ret < 0) {
dev_err(ri->dev, "trans reg update failed, e %d\n", ret);
return ret;
}
return ret;
}
static int check_smps_mode_mult(struct device *parent,
struct tps80031_regulator *ri)
{
int mult_offset;
int ret;
u8 smps_offset;
u8 smps_mult;
ret = tps80031_read(parent, TPS80031_SLAVE_ID1,
TPS80031_SMPS_OFFSET, &smps_offset);
if (ret < 0) {
dev_err(parent, "Error in reading smps offset register\n");
return ret;
}
ret = tps80031_read(parent, TPS80031_SLAVE_ID1,
TPS80031_SMPS_MULT, &smps_mult);
if (ret < 0) {
dev_err(parent, "Error in reading smps mult register\n");
return ret;
}
switch (ri->rinfo->desc.id) {
case TPS80031_REGULATOR_VIO:
mult_offset = SMPS_MULTOFFSET_VIO;
break;
case TPS80031_REGULATOR_SMPS1:
mult_offset = SMPS_MULTOFFSET_SMPS1;
break;
case TPS80031_REGULATOR_SMPS2:
mult_offset = SMPS_MULTOFFSET_SMPS2;
break;
case TPS80031_REGULATOR_SMPS3:
mult_offset = SMPS_MULTOFFSET_SMPS3;
break;
case TPS80031_REGULATOR_SMPS4:
mult_offset = SMPS_MULTOFFSET_SMPS4;
break;
case TPS80031_REGULATOR_LDO2:
ri->device_flags = smps_mult & BIT(5) ? TRACK_MODE_ENABLE : 0;
if (ri->device_flags & TRACK_MODE_ENABLE) {
ri->rinfo->desc.min_uV = 600000;
ri->rinfo->desc.uV_step = 12500;
ri->rinfo->desc.n_voltages = 57;
ri->rinfo->desc.vsel_mask = LDO_TRACK_VSEL_MASK;
}
return 0;
default:
return 0;
}
ri->device_flags = (smps_offset & mult_offset) ? DCDC_OFFSET_EN : 0;
ri->device_flags |= (smps_mult & mult_offset) ? DCDC_EXTENDED_EN : 0;
switch (ri->device_flags) {
case 0:
ri->rinfo->desc.min_uV = 607700;
ri->rinfo->desc.uV_step = 12660;
break;
case DCDC_OFFSET_EN:
ri->rinfo->desc.min_uV = 700000;
ri->rinfo->desc.uV_step = 12500;
break;
case DCDC_EXTENDED_EN:
ri->rinfo->desc.min_uV = 1852000;
ri->rinfo->desc.uV_step = 38600;
break;
case DCDC_OFFSET_EN | DCDC_EXTENDED_EN:
ri->rinfo->desc.min_uV = 2161000;
ri->rinfo->desc.uV_step = 38600;
break;
}
return 0;
}
static int tps80031_regulator_probe(struct platform_device *pdev)
{
struct tps80031_platform_data *pdata;
struct tps80031_regulator_platform_data *tps_pdata;
struct tps80031_regulator *ri;
struct tps80031_regulator *pmic;
struct regulator_dev *rdev;
struct regulator_config config = { };
struct tps80031 *tps80031_mfd = dev_get_drvdata(pdev->dev.parent);
int ret;
int num;
pdata = dev_get_platdata(pdev->dev.parent);
if (!pdata) {
dev_err(&pdev->dev, "No platform data\n");
return -EINVAL;
}
pmic = devm_kzalloc(&pdev->dev,
TPS80031_REGULATOR_MAX * sizeof(*pmic), GFP_KERNEL);
if (!pmic) {
dev_err(&pdev->dev, "mem alloc for pmic failed\n");
return -ENOMEM;
}
for (num = 0; num < TPS80031_REGULATOR_MAX; ++num) {
tps_pdata = pdata->regulator_pdata[num];
ri = &pmic[num];
ri->rinfo = &tps80031_rinfo[num];
ri->dev = &pdev->dev;
check_smps_mode_mult(pdev->dev.parent, ri);
config.dev = &pdev->dev;
config.init_data = NULL;
config.driver_data = ri;
config.regmap = tps80031_mfd->regmap[ri->rinfo->volt_id];
if (tps_pdata) {
config.init_data = tps_pdata->reg_init_data;
ri->config_flags = tps_pdata->config_flags;
ri->ext_ctrl_flag = tps_pdata->ext_ctrl_flag;
ret = tps80031_regulator_config(pdev->dev.parent,
ri, tps_pdata);
if (ret < 0) {
dev_err(&pdev->dev,
"regulator config failed, e %d\n", ret);
return ret;
}
ret = tps80031_power_req_config(pdev->dev.parent,
ri, tps_pdata);
if (ret < 0) {
dev_err(&pdev->dev,
"pwr_req config failed, err %d\n", ret);
return ret;
}
}
rdev = devm_regulator_register(&pdev->dev, &ri->rinfo->desc,
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"register regulator failed %s\n",
ri->rinfo->desc.name);
return PTR_ERR(rdev);
}
ri->rdev = rdev;
}
platform_set_drvdata(pdev, pmic);
return 0;
}
static int __init tps80031_regulator_init(void)
{
return platform_driver_register(&tps80031_regulator_driver);
}
static void __exit tps80031_regulator_exit(void)
{
platform_driver_unregister(&tps80031_regulator_driver);
}
