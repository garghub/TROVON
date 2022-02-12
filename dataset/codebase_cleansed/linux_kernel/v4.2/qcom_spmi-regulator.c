static inline int spmi_vreg_read(struct spmi_regulator *vreg, u16 addr, u8 *buf,
int len)
{
return regmap_bulk_read(vreg->regmap, vreg->base + addr, buf, len);
}
static inline int spmi_vreg_write(struct spmi_regulator *vreg, u16 addr,
u8 *buf, int len)
{
return regmap_bulk_write(vreg->regmap, vreg->base + addr, buf, len);
}
static int spmi_vreg_update_bits(struct spmi_regulator *vreg, u16 addr, u8 val,
u8 mask)
{
return regmap_update_bits(vreg->regmap, vreg->base + addr, mask, val);
}
static int spmi_regulator_common_is_enabled(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
u8 reg;
spmi_vreg_read(vreg, SPMI_COMMON_REG_ENABLE, &reg, 1);
return (reg & SPMI_COMMON_ENABLE_MASK) == SPMI_COMMON_ENABLE;
}
static int spmi_regulator_common_enable(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_ENABLE,
SPMI_COMMON_ENABLE, SPMI_COMMON_ENABLE_MASK);
}
static int spmi_regulator_vs_enable(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
if (vreg->ocp_irq) {
vreg->ocp_count = 0;
vreg->vs_enable_time = ktime_get();
}
return spmi_regulator_common_enable(rdev);
}
static int spmi_regulator_common_disable(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_ENABLE,
SPMI_COMMON_DISABLE, SPMI_COMMON_ENABLE_MASK);
}
static int spmi_regulator_select_voltage(struct spmi_regulator *vreg,
int min_uV, int max_uV, u8 *range_sel, u8 *voltage_sel,
unsigned *selector)
{
const struct spmi_voltage_range *range;
int uV = min_uV;
int lim_min_uV, lim_max_uV, i, range_id, range_max_uV;
lim_min_uV = vreg->set_points->range[0].set_point_min_uV;
lim_max_uV =
vreg->set_points->range[vreg->set_points->count - 1].set_point_max_uV;
if (uV < lim_min_uV && max_uV >= lim_min_uV)
uV = lim_min_uV;
if (uV < lim_min_uV || uV > lim_max_uV) {
dev_err(vreg->dev,
"request v=[%d, %d] is outside possible v=[%d, %d]\n",
min_uV, max_uV, lim_min_uV, lim_max_uV);
return -EINVAL;
}
for (i = vreg->set_points->count - 1; i > 0; i--) {
range_max_uV = vreg->set_points->range[i - 1].set_point_max_uV;
if (uV > range_max_uV && range_max_uV > 0)
break;
}
range_id = i;
range = &vreg->set_points->range[range_id];
*range_sel = range->range_sel;
*voltage_sel = (uV - range->min_uV + range->step_uV - 1)
/ range->step_uV;
uV = *voltage_sel * range->step_uV + range->min_uV;
if (uV > max_uV) {
dev_err(vreg->dev,
"request v=[%d, %d] cannot be met by any set point; "
"next set point: %d\n",
min_uV, max_uV, uV);
return -EINVAL;
}
*selector = 0;
for (i = 0; i < range_id; i++)
*selector += vreg->set_points->range[i].n_voltages;
*selector += (uV - range->set_point_min_uV) / range->step_uV;
return 0;
}
static const struct spmi_voltage_range *
spmi_regulator_find_range(struct spmi_regulator *vreg)
{
u8 range_sel;
const struct spmi_voltage_range *range, *end;
range = vreg->set_points->range;
end = range + vreg->set_points->count;
spmi_vreg_read(vreg, SPMI_COMMON_REG_VOLTAGE_RANGE, &range_sel, 1);
for (; range < end; range++)
if (range->range_sel == range_sel)
return range;
return NULL;
}
static int spmi_regulator_select_voltage_same_range(struct spmi_regulator *vreg,
int min_uV, int max_uV, u8 *range_sel, u8 *voltage_sel,
unsigned *selector)
{
const struct spmi_voltage_range *range;
int uV = min_uV;
int i;
range = spmi_regulator_find_range(vreg);
if (!range)
goto different_range;
if (uV < range->min_uV && max_uV >= range->min_uV)
uV = range->min_uV;
if (uV < range->min_uV || uV > range->max_uV) {
goto different_range;
}
*voltage_sel = DIV_ROUND_UP(uV - range->min_uV, range->step_uV);
uV = *voltage_sel * range->step_uV + range->min_uV;
if (uV > max_uV) {
goto different_range;
}
*selector = 0;
for (i = 0; i < vreg->set_points->count; i++) {
if (uV >= vreg->set_points->range[i].set_point_min_uV
&& uV <= vreg->set_points->range[i].set_point_max_uV) {
*selector +=
(uV - vreg->set_points->range[i].set_point_min_uV)
/ vreg->set_points->range[i].step_uV;
break;
}
*selector += vreg->set_points->range[i].n_voltages;
}
if (*selector >= vreg->set_points->n_voltages)
goto different_range;
return 0;
different_range:
return spmi_regulator_select_voltage(vreg, min_uV, max_uV,
range_sel, voltage_sel, selector);
}
static int spmi_regulator_common_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
int ret;
u8 buf[2];
u8 range_sel, voltage_sel;
ret = spmi_regulator_select_voltage_same_range(vreg, min_uV, max_uV,
&range_sel, &voltage_sel, selector);
if (ret)
return ret;
buf[0] = range_sel;
buf[1] = voltage_sel;
return spmi_vreg_write(vreg, SPMI_COMMON_REG_VOLTAGE_RANGE, buf, 2);
}
static int spmi_regulator_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_selector, unsigned int new_selector)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
const struct spmi_voltage_range *range;
int diff_uV;
range = spmi_regulator_find_range(vreg);
if (!range)
return -EINVAL;
diff_uV = abs(new_selector - old_selector) * range->step_uV;
return DIV_ROUND_UP(diff_uV, vreg->slew_rate);
}
static int spmi_regulator_common_get_voltage(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
const struct spmi_voltage_range *range;
u8 voltage_sel;
spmi_vreg_read(vreg, SPMI_COMMON_REG_VOLTAGE_SET, &voltage_sel, 1);
range = spmi_regulator_find_range(vreg);
if (!range)
return VOLTAGE_UNKNOWN;
return range->step_uV * voltage_sel + range->min_uV;
}
static int spmi_regulator_single_range_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
int ret;
u8 range_sel, sel;
ret = spmi_regulator_select_voltage(vreg, min_uV, max_uV, &range_sel,
&sel, selector);
if (ret) {
dev_err(vreg->dev, "could not set voltage, ret=%d\n", ret);
return ret;
}
return spmi_vreg_write(vreg, SPMI_COMMON_REG_VOLTAGE_SET, &sel, 1);
}
static int spmi_regulator_single_range_get_voltage(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
const struct spmi_voltage_range *range = vreg->set_points->range;
u8 voltage_sel;
spmi_vreg_read(vreg, SPMI_COMMON_REG_VOLTAGE_SET, &voltage_sel, 1);
return range->step_uV * voltage_sel + range->min_uV;
}
static int spmi_regulator_ult_lo_smps_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
int ret;
u8 range_sel, voltage_sel;
ret = spmi_regulator_select_voltage_same_range(vreg, min_uV, max_uV,
&range_sel, &voltage_sel, selector);
if (ret)
return ret;
if (range_sel == 1)
voltage_sel |= ULT_SMPS_RANGE_SPLIT;
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_VOLTAGE_SET,
voltage_sel, 0xff);
}
static int spmi_regulator_ult_lo_smps_get_voltage(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
const struct spmi_voltage_range *range;
u8 voltage_sel;
spmi_vreg_read(vreg, SPMI_COMMON_REG_VOLTAGE_SET, &voltage_sel, 1);
range = spmi_regulator_find_range(vreg);
if (!range)
return VOLTAGE_UNKNOWN;
if (range->range_sel == 1)
voltage_sel &= ~ULT_SMPS_RANGE_SPLIT;
return range->step_uV * voltage_sel + range->min_uV;
}
static int spmi_regulator_common_list_voltage(struct regulator_dev *rdev,
unsigned selector)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
int uV = 0;
int i;
if (selector >= vreg->set_points->n_voltages)
return 0;
for (i = 0; i < vreg->set_points->count; i++) {
if (selector < vreg->set_points->range[i].n_voltages) {
uV = selector * vreg->set_points->range[i].step_uV
+ vreg->set_points->range[i].set_point_min_uV;
break;
}
selector -= vreg->set_points->range[i].n_voltages;
}
return uV;
}
static int
spmi_regulator_common_set_bypass(struct regulator_dev *rdev, bool enable)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
u8 mask = SPMI_COMMON_MODE_BYPASS_MASK;
u8 val = 0;
if (enable)
val = mask;
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_MODE, val, mask);
}
static int
spmi_regulator_common_get_bypass(struct regulator_dev *rdev, bool *enable)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
u8 val;
int ret;
ret = spmi_vreg_read(vreg, SPMI_COMMON_REG_MODE, &val, 1);
*enable = val & SPMI_COMMON_MODE_BYPASS_MASK;
return ret;
}
static unsigned int spmi_regulator_common_get_mode(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
u8 reg;
spmi_vreg_read(vreg, SPMI_COMMON_REG_MODE, &reg, 1);
if (reg & SPMI_COMMON_MODE_HPM_MASK)
return REGULATOR_MODE_NORMAL;
return REGULATOR_MODE_IDLE;
}
static int
spmi_regulator_common_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
u8 mask = SPMI_COMMON_MODE_HPM_MASK;
u8 val = 0;
if (mode == REGULATOR_MODE_NORMAL)
val = mask;
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_MODE, val, mask);
}
static int
spmi_regulator_common_set_load(struct regulator_dev *rdev, int load_uA)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
unsigned int mode;
if (load_uA >= vreg->hpm_min_load)
mode = REGULATOR_MODE_NORMAL;
else
mode = REGULATOR_MODE_IDLE;
return spmi_regulator_common_set_mode(rdev, mode);
}
static int spmi_regulator_common_set_pull_down(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
unsigned int mask = SPMI_COMMON_PULL_DOWN_ENABLE_MASK;
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_PULL_DOWN,
mask, mask);
}
static int spmi_regulator_common_set_soft_start(struct regulator_dev *rdev)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
unsigned int mask = SPMI_LDO_SOFT_START_ENABLE_MASK;
return spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_SOFT_START,
mask, mask);
}
static int spmi_regulator_set_ilim(struct regulator_dev *rdev, int ilim_uA)
{
struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
enum spmi_regulator_logical_type type = vreg->logical_type;
unsigned int current_reg;
u8 reg;
u8 mask = SPMI_BOOST_CURRENT_LIMIT_MASK |
SPMI_BOOST_CURRENT_LIMIT_ENABLE_MASK;
int max = (SPMI_BOOST_CURRENT_LIMIT_MASK + 1) * 500;
if (type == SPMI_REGULATOR_LOGICAL_TYPE_BOOST)
current_reg = SPMI_BOOST_REG_CURRENT_LIMIT;
else
current_reg = SPMI_BOOST_BYP_REG_CURRENT_LIMIT;
if (ilim_uA > max || ilim_uA <= 0)
return -EINVAL;
reg = (ilim_uA - 1) / 500;
reg |= SPMI_BOOST_CURRENT_LIMIT_ENABLE_MASK;
return spmi_vreg_update_bits(vreg, current_reg, reg, mask);
}
static int spmi_regulator_vs_clear_ocp(struct spmi_regulator *vreg)
{
int ret;
ret = spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_ENABLE,
SPMI_COMMON_DISABLE, SPMI_COMMON_ENABLE_MASK);
vreg->vs_enable_time = ktime_get();
ret = spmi_vreg_update_bits(vreg, SPMI_COMMON_REG_ENABLE,
SPMI_COMMON_ENABLE, SPMI_COMMON_ENABLE_MASK);
return ret;
}
static void spmi_regulator_vs_ocp_work(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct spmi_regulator *vreg
= container_of(dwork, struct spmi_regulator, ocp_work);
spmi_regulator_vs_clear_ocp(vreg);
}
static irqreturn_t spmi_regulator_vs_ocp_isr(int irq, void *data)
{
struct spmi_regulator *vreg = data;
ktime_t ocp_irq_time;
s64 ocp_trigger_delay_us;
ocp_irq_time = ktime_get();
ocp_trigger_delay_us = ktime_us_delta(ocp_irq_time,
vreg->vs_enable_time);
if (ocp_trigger_delay_us > SPMI_VS_OCP_FAULT_DELAY_US)
vreg->ocp_count = 0;
udelay(SPMI_VS_OCP_FALL_DELAY_US);
vreg->ocp_count++;
if (vreg->ocp_count == 1) {
spmi_regulator_vs_clear_ocp(vreg);
} else if (vreg->ocp_count <= vreg->ocp_max_retries) {
schedule_delayed_work(&vreg->ocp_work,
msecs_to_jiffies(vreg->ocp_retry_delay_ms) + 1);
} else {
dev_err(vreg->dev,
"OCP triggered %d times; no further retries\n",
vreg->ocp_count);
}
return IRQ_HANDLED;
}
static void spmi_calculate_num_voltages(struct spmi_voltage_set_points *points)
{
unsigned int n;
struct spmi_voltage_range *range = points->range;
for (; range < points->range + points->count; range++) {
n = 0;
if (range->set_point_max_uV) {
n = range->set_point_max_uV - range->set_point_min_uV;
n = (n / range->step_uV) + 1;
}
range->n_voltages = n;
points->n_voltages += n;
}
}
static int spmi_regulator_match(struct spmi_regulator *vreg, u16 force_type)
{
const struct spmi_regulator_mapping *mapping;
int ret, i;
u32 dig_major_rev;
u8 version[SPMI_COMMON_REG_SUBTYPE - SPMI_COMMON_REG_DIG_MAJOR_REV + 1];
u8 type, subtype;
ret = spmi_vreg_read(vreg, SPMI_COMMON_REG_DIG_MAJOR_REV, version,
ARRAY_SIZE(version));
if (ret) {
dev_err(vreg->dev, "could not read version registers\n");
return ret;
}
dig_major_rev = version[SPMI_COMMON_REG_DIG_MAJOR_REV
- SPMI_COMMON_REG_DIG_MAJOR_REV];
if (!force_type) {
type = version[SPMI_COMMON_REG_TYPE -
SPMI_COMMON_REG_DIG_MAJOR_REV];
subtype = version[SPMI_COMMON_REG_SUBTYPE -
SPMI_COMMON_REG_DIG_MAJOR_REV];
} else {
type = force_type >> 8;
subtype = force_type;
}
for (i = 0; i < ARRAY_SIZE(supported_regulators); i++) {
mapping = &supported_regulators[i];
if (mapping->type == type && mapping->subtype == subtype
&& mapping->revision_min <= dig_major_rev
&& mapping->revision_max >= dig_major_rev)
goto found;
}
dev_err(vreg->dev,
"unsupported regulator: name=%s type=0x%02X, subtype=0x%02X, dig major rev=0x%02X\n",
vreg->desc.name, type, subtype, dig_major_rev);
return -ENODEV;
found:
vreg->logical_type = mapping->logical_type;
vreg->set_points = mapping->set_points;
vreg->hpm_min_load = mapping->hpm_min_load;
vreg->desc.ops = mapping->ops;
if (mapping->set_points) {
if (!mapping->set_points->n_voltages)
spmi_calculate_num_voltages(mapping->set_points);
vreg->desc.n_voltages = mapping->set_points->n_voltages;
}
return 0;
}
static int spmi_regulator_ftsmps_init_slew_rate(struct spmi_regulator *vreg)
{
int ret;
u8 reg = 0;
int step, delay, slew_rate;
const struct spmi_voltage_range *range;
ret = spmi_vreg_read(vreg, SPMI_COMMON_REG_STEP_CTRL, &reg, 1);
if (ret) {
dev_err(vreg->dev, "spmi read failed, ret=%d\n", ret);
return ret;
}
range = spmi_regulator_find_range(vreg);
if (!range)
return -EINVAL;
step = reg & SPMI_FTSMPS_STEP_CTRL_STEP_MASK;
step >>= SPMI_FTSMPS_STEP_CTRL_STEP_SHIFT;
delay = reg & SPMI_FTSMPS_STEP_CTRL_DELAY_MASK;
delay >>= SPMI_FTSMPS_STEP_CTRL_DELAY_SHIFT;
slew_rate = SPMI_FTSMPS_CLOCK_RATE * range->step_uV * (1 << step);
slew_rate /= 1000 * (SPMI_FTSMPS_STEP_DELAY << delay);
slew_rate *= SPMI_FTSMPS_STEP_MARGIN_NUM;
slew_rate /= SPMI_FTSMPS_STEP_MARGIN_DEN;
vreg->slew_rate = max(slew_rate, 1);
return ret;
}
static unsigned int spmi_regulator_of_map_mode(unsigned int mode)
{
if (mode)
return REGULATOR_MODE_NORMAL;
return REGULATOR_MODE_IDLE;
}
static int spmi_regulator_of_parse(struct device_node *node,
const struct regulator_desc *desc,
struct regulator_config *config)
{
struct spmi_regulator *vreg = config->driver_data;
struct device *dev = config->dev;
int ret;
vreg->ocp_max_retries = SPMI_VS_OCP_DEFAULT_MAX_RETRIES;
vreg->ocp_retry_delay_ms = SPMI_VS_OCP_DEFAULT_RETRY_DELAY_MS;
if (vreg->logical_type == SPMI_REGULATOR_LOGICAL_TYPE_FTSMPS) {
ret = spmi_regulator_ftsmps_init_slew_rate(vreg);
if (ret)
return ret;
}
if (vreg->logical_type != SPMI_REGULATOR_LOGICAL_TYPE_VS)
vreg->ocp_irq = 0;
if (vreg->ocp_irq) {
ret = devm_request_irq(dev, vreg->ocp_irq,
spmi_regulator_vs_ocp_isr, IRQF_TRIGGER_RISING, "ocp",
vreg);
if (ret < 0) {
dev_err(dev, "failed to request irq %d, ret=%d\n",
vreg->ocp_irq, ret);
return ret;
}
INIT_DELAYED_WORK(&vreg->ocp_work, spmi_regulator_vs_ocp_work);
}
return 0;
}
static int qcom_spmi_regulator_probe(struct platform_device *pdev)
{
const struct spmi_regulator_data *reg;
const struct of_device_id *match;
struct regulator_config config = { };
struct regulator_dev *rdev;
struct spmi_regulator *vreg;
struct regmap *regmap;
const char *name;
struct device *dev = &pdev->dev;
int ret;
struct list_head *vreg_list;
vreg_list = devm_kzalloc(dev, sizeof(*vreg_list), GFP_KERNEL);
if (!vreg_list)
return -ENOMEM;
INIT_LIST_HEAD(vreg_list);
platform_set_drvdata(pdev, vreg_list);
regmap = dev_get_regmap(dev->parent, NULL);
if (!regmap)
return -ENODEV;
match = of_match_device(qcom_spmi_regulator_match, &pdev->dev);
if (!match)
return -ENODEV;
for (reg = match->data; reg->name; reg++) {
vreg = devm_kzalloc(dev, sizeof(*vreg), GFP_KERNEL);
if (!vreg)
return -ENOMEM;
vreg->dev = dev;
vreg->base = reg->base;
vreg->regmap = regmap;
if (reg->ocp) {
vreg->ocp_irq = platform_get_irq_byname(pdev, reg->ocp);
if (vreg->ocp_irq < 0) {
ret = vreg->ocp_irq;
goto err;
}
}
vreg->desc.id = -1;
vreg->desc.owner = THIS_MODULE;
vreg->desc.type = REGULATOR_VOLTAGE;
vreg->desc.name = name = reg->name;
vreg->desc.supply_name = reg->supply;
vreg->desc.of_match = reg->name;
vreg->desc.of_parse_cb = spmi_regulator_of_parse;
vreg->desc.of_map_mode = spmi_regulator_of_map_mode;
ret = spmi_regulator_match(vreg, reg->force_type);
if (ret)
goto err;
config.dev = dev;
config.driver_data = vreg;
rdev = devm_regulator_register(dev, &vreg->desc, &config);
if (IS_ERR(rdev)) {
dev_err(dev, "failed to register %s\n", name);
ret = PTR_ERR(rdev);
goto err;
}
INIT_LIST_HEAD(&vreg->node);
list_add(&vreg->node, vreg_list);
}
return 0;
err:
list_for_each_entry(vreg, vreg_list, node)
if (vreg->ocp_irq)
cancel_delayed_work_sync(&vreg->ocp_work);
return ret;
}
static int qcom_spmi_regulator_remove(struct platform_device *pdev)
{
struct spmi_regulator *vreg;
struct list_head *vreg_list = platform_get_drvdata(pdev);
list_for_each_entry(vreg, vreg_list, node)
if (vreg->ocp_irq)
cancel_delayed_work_sync(&vreg->ocp_work);
return 0;
}
