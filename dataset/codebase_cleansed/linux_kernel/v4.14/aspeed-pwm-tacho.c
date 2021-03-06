static int regmap_aspeed_pwm_tacho_reg_write(void *context, unsigned int reg,
unsigned int val)
{
void __iomem *regs = (void __iomem *)context;
writel(val, regs + reg);
return 0;
}
static int regmap_aspeed_pwm_tacho_reg_read(void *context, unsigned int reg,
unsigned int *val)
{
void __iomem *regs = (void __iomem *)context;
*val = readl(regs + reg);
return 0;
}
static void aspeed_set_clock_enable(struct regmap *regmap, bool val)
{
regmap_update_bits(regmap, ASPEED_PTCR_CTRL,
ASPEED_PTCR_CTRL_CLK_EN,
val ? ASPEED_PTCR_CTRL_CLK_EN : 0);
}
static void aspeed_set_clock_source(struct regmap *regmap, int val)
{
regmap_update_bits(regmap, ASPEED_PTCR_CTRL,
ASPEED_PTCR_CTRL_CLK_SRC,
val ? ASPEED_PTCR_CTRL_CLK_SRC : 0);
}
static void aspeed_set_pwm_clock_values(struct regmap *regmap, u8 type,
u8 div_high, u8 div_low, u8 unit)
{
u32 reg_value = ((div_high << type_params[type].h_value) |
(div_low << type_params[type].l_value) |
(unit << type_params[type].unit_value));
regmap_update_bits(regmap, type_params[type].clk_ctrl_reg,
type_params[type].clk_ctrl_mask, reg_value);
}
static void aspeed_set_pwm_port_enable(struct regmap *regmap, u8 pwm_port,
bool enable)
{
regmap_update_bits(regmap, pwm_port_params[pwm_port].ctrl_reg,
pwm_port_params[pwm_port].pwm_en,
enable ? pwm_port_params[pwm_port].pwm_en : 0);
}
static void aspeed_set_pwm_port_type(struct regmap *regmap,
u8 pwm_port, u8 type)
{
u32 reg_value = (type & 0x1) << pwm_port_params[pwm_port].type_part1;
reg_value |= (type & 0x2) << pwm_port_params[pwm_port].type_part2;
regmap_update_bits(regmap, pwm_port_params[pwm_port].ctrl_reg,
pwm_port_params[pwm_port].type_mask, reg_value);
}
static void aspeed_set_pwm_port_duty_rising_falling(struct regmap *regmap,
u8 pwm_port, u8 rising,
u8 falling)
{
u32 reg_value = (rising <<
pwm_port_params[pwm_port].duty_ctrl_rise_point);
reg_value |= (falling <<
pwm_port_params[pwm_port].duty_ctrl_fall_point);
regmap_update_bits(regmap, pwm_port_params[pwm_port].duty_ctrl_reg,
pwm_port_params[pwm_port].duty_ctrl_rise_fall_mask,
reg_value);
}
static void aspeed_set_tacho_type_enable(struct regmap *regmap, u8 type,
bool enable)
{
regmap_update_bits(regmap, type_params[type].ctrl_reg,
TYPE_CTRL_FAN_TYPE_EN,
enable ? TYPE_CTRL_FAN_TYPE_EN : 0);
}
static void aspeed_set_tacho_type_values(struct regmap *regmap, u8 type,
u8 mode, u16 unit, u8 division)
{
u32 reg_value = ((mode << TYPE_CTRL_FAN_MODE) |
(unit << TYPE_CTRL_FAN_PERIOD) |
(division << TYPE_CTRL_FAN_DIVISION));
regmap_update_bits(regmap, type_params[type].ctrl_reg,
TYPE_CTRL_FAN_MASK, reg_value);
regmap_update_bits(regmap, type_params[type].ctrl_reg1,
TYPE_CTRL_FAN1_MASK, unit << 16);
}
static void aspeed_set_fan_tach_ch_enable(struct regmap *regmap, u8 fan_tach_ch,
bool enable)
{
regmap_update_bits(regmap, ASPEED_PTCR_CTRL,
ASPEED_PTCR_CTRL_FAN_NUM_EN(fan_tach_ch),
enable ?
ASPEED_PTCR_CTRL_FAN_NUM_EN(fan_tach_ch) : 0);
}
static void aspeed_set_fan_tach_ch_source(struct regmap *regmap, u8 fan_tach_ch,
u8 fan_tach_ch_source)
{
u32 reg_value1 = ((fan_tach_ch_source & 0x3) <<
TACH_PWM_SOURCE_BIT01(fan_tach_ch));
u32 reg_value2 = (((fan_tach_ch_source & 0x4) >> 2) <<
TACH_PWM_SOURCE_BIT2(fan_tach_ch));
regmap_update_bits(regmap, ASPEED_PTCR_TACH_SOURCE,
TACH_PWM_SOURCE_MASK_BIT01(fan_tach_ch),
reg_value1);
regmap_update_bits(regmap, ASPEED_PTCR_TACH_SOURCE_EXT,
TACH_PWM_SOURCE_MASK_BIT2(fan_tach_ch),
reg_value2);
}
static void aspeed_set_pwm_port_fan_ctrl(struct aspeed_pwm_tacho_data *priv,
u8 index, u8 fan_ctrl)
{
u16 period, dc_time_on;
period = priv->type_pwm_clock_unit[priv->pwm_port_type[index]];
period += 1;
dc_time_on = (fan_ctrl * period) / PWM_MAX;
if (dc_time_on == 0) {
aspeed_set_pwm_port_enable(priv->regmap, index, false);
} else {
if (dc_time_on == period)
dc_time_on = 0;
aspeed_set_pwm_port_duty_rising_falling(priv->regmap, index, 0,
dc_time_on);
aspeed_set_pwm_port_enable(priv->regmap, index, true);
}
}
static u32 aspeed_get_fan_tach_ch_measure_period(struct aspeed_pwm_tacho_data
*priv, u8 type)
{
u32 clk;
u16 tacho_unit;
u8 clk_unit, div_h, div_l, tacho_div;
clk = priv->clk_freq;
clk_unit = priv->type_pwm_clock_unit[type];
div_h = priv->type_pwm_clock_division_h[type];
div_h = 0x1 << div_h;
div_l = priv->type_pwm_clock_division_l[type];
if (div_l == 0)
div_l = 1;
else
div_l = div_l * 2;
tacho_unit = priv->type_fan_tach_unit[type];
tacho_div = priv->type_fan_tach_clock_division[type];
tacho_div = 0x4 << (tacho_div * 2);
return clk / (clk_unit * div_h * div_l * tacho_div * tacho_unit);
}
static int aspeed_get_fan_tach_ch_rpm(struct aspeed_pwm_tacho_data *priv,
u8 fan_tach_ch)
{
u32 raw_data, tach_div, clk_source, msec, usec, val;
u8 fan_tach_ch_source, type, mode, both;
int ret;
regmap_write(priv->regmap, ASPEED_PTCR_TRIGGER, 0);
regmap_write(priv->regmap, ASPEED_PTCR_TRIGGER, 0x1 << fan_tach_ch);
fan_tach_ch_source = priv->fan_tach_ch_source[fan_tach_ch];
type = priv->pwm_port_type[fan_tach_ch_source];
msec = (1000 / aspeed_get_fan_tach_ch_measure_period(priv, type));
usec = msec * 1000;
ret = regmap_read_poll_timeout(
priv->regmap,
ASPEED_PTCR_RESULT,
val,
(val & RESULT_STATUS_MASK),
ASPEED_RPM_STATUS_SLEEP_USEC,
usec);
if (ret)
return ret;
raw_data = val & RESULT_VALUE_MASK;
tach_div = priv->type_fan_tach_clock_division[type];
mode = priv->type_fan_tach_mode[type];
both = (mode & BOTH_EDGES) ? 1 : 0;
tach_div = (0x4 << both) << (tach_div * 2);
clk_source = priv->clk_freq;
if (raw_data == 0)
return 0;
return (clk_source * 60) / (2 * raw_data * tach_div);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int index = sensor_attr->index;
int ret;
struct aspeed_pwm_tacho_data *priv = dev_get_drvdata(dev);
long fan_ctrl;
ret = kstrtol(buf, 10, &fan_ctrl);
if (ret != 0)
return ret;
if (fan_ctrl < 0 || fan_ctrl > PWM_MAX)
return -EINVAL;
if (priv->pwm_port_fan_ctrl[index] == fan_ctrl)
return count;
priv->pwm_port_fan_ctrl[index] = fan_ctrl;
aspeed_set_pwm_port_fan_ctrl(priv, index, fan_ctrl);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int index = sensor_attr->index;
struct aspeed_pwm_tacho_data *priv = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", priv->pwm_port_fan_ctrl[index]);
}
static ssize_t show_rpm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int index = sensor_attr->index;
int rpm;
struct aspeed_pwm_tacho_data *priv = dev_get_drvdata(dev);
rpm = aspeed_get_fan_tach_ch_rpm(priv, index);
if (rpm < 0)
return rpm;
return sprintf(buf, "%d\n", rpm);
}
static umode_t pwm_is_visible(struct kobject *kobj,
struct attribute *a, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct aspeed_pwm_tacho_data *priv = dev_get_drvdata(dev);
if (!priv->pwm_present[index])
return 0;
return a->mode;
}
static umode_t fan_dev_is_visible(struct kobject *kobj,
struct attribute *a, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct aspeed_pwm_tacho_data *priv = dev_get_drvdata(dev);
if (!priv->fan_tach_present[index])
return 0;
return a->mode;
}
static void aspeed_create_type(struct aspeed_pwm_tacho_data *priv)
{
priv->type_pwm_clock_division_h[TYPEM] = M_PWM_DIV_H;
priv->type_pwm_clock_division_l[TYPEM] = M_PWM_DIV_L;
priv->type_pwm_clock_unit[TYPEM] = M_PWM_PERIOD;
aspeed_set_pwm_clock_values(priv->regmap, TYPEM, M_PWM_DIV_H,
M_PWM_DIV_L, M_PWM_PERIOD);
aspeed_set_tacho_type_enable(priv->regmap, TYPEM, true);
priv->type_fan_tach_clock_division[TYPEM] = M_TACH_CLK_DIV;
priv->type_fan_tach_unit[TYPEM] = M_TACH_UNIT;
priv->type_fan_tach_mode[TYPEM] = M_TACH_MODE;
aspeed_set_tacho_type_values(priv->regmap, TYPEM, M_TACH_MODE,
M_TACH_UNIT, M_TACH_CLK_DIV);
}
static void aspeed_create_pwm_port(struct aspeed_pwm_tacho_data *priv,
u8 pwm_port)
{
aspeed_set_pwm_port_enable(priv->regmap, pwm_port, true);
priv->pwm_present[pwm_port] = true;
priv->pwm_port_type[pwm_port] = TYPEM;
aspeed_set_pwm_port_type(priv->regmap, pwm_port, TYPEM);
priv->pwm_port_fan_ctrl[pwm_port] = INIT_FAN_CTRL;
aspeed_set_pwm_port_fan_ctrl(priv, pwm_port, INIT_FAN_CTRL);
}
static void aspeed_create_fan_tach_channel(struct aspeed_pwm_tacho_data *priv,
u8 *fan_tach_ch,
int count,
u8 pwm_source)
{
u8 val, index;
for (val = 0; val < count; val++) {
index = fan_tach_ch[val];
aspeed_set_fan_tach_ch_enable(priv->regmap, index, true);
priv->fan_tach_present[index] = true;
priv->fan_tach_ch_source[index] = pwm_source;
aspeed_set_fan_tach_ch_source(priv->regmap, index, pwm_source);
}
}
static int
aspeed_pwm_cz_get_max_state(struct thermal_cooling_device *tcdev,
unsigned long *state)
{
struct aspeed_cooling_device *cdev = tcdev->devdata;
*state = cdev->max_state;
return 0;
}
static int
aspeed_pwm_cz_get_cur_state(struct thermal_cooling_device *tcdev,
unsigned long *state)
{
struct aspeed_cooling_device *cdev = tcdev->devdata;
*state = cdev->cur_state;
return 0;
}
static int
aspeed_pwm_cz_set_cur_state(struct thermal_cooling_device *tcdev,
unsigned long state)
{
struct aspeed_cooling_device *cdev = tcdev->devdata;
if (state > cdev->max_state)
return -EINVAL;
cdev->cur_state = state;
cdev->priv->pwm_port_fan_ctrl[cdev->pwm_port] =
cdev->cooling_levels[cdev->cur_state];
aspeed_set_pwm_port_fan_ctrl(cdev->priv, cdev->pwm_port,
cdev->cooling_levels[cdev->cur_state]);
return 0;
}
static int aspeed_create_pwm_cooling(struct device *dev,
struct device_node *child,
struct aspeed_pwm_tacho_data *priv,
u32 pwm_port, u8 num_levels)
{
int ret;
struct aspeed_cooling_device *cdev;
cdev = devm_kzalloc(dev, sizeof(*cdev), GFP_KERNEL);
if (!cdev)
return -ENOMEM;
cdev->cooling_levels = devm_kzalloc(dev, num_levels, GFP_KERNEL);
if (!cdev->cooling_levels)
return -ENOMEM;
cdev->max_state = num_levels - 1;
ret = of_property_read_u8_array(child, "cooling-levels",
cdev->cooling_levels,
num_levels);
if (ret) {
dev_err(dev, "Property 'cooling-levels' cannot be read.\n");
return ret;
}
snprintf(cdev->name, MAX_CDEV_NAME_LEN, "%s%d", child->name, pwm_port);
cdev->tcdev = thermal_of_cooling_device_register(child,
cdev->name,
cdev,
&aspeed_pwm_cool_ops);
if (IS_ERR(cdev->tcdev))
return PTR_ERR(cdev->tcdev);
cdev->priv = priv;
cdev->pwm_port = pwm_port;
priv->cdev[pwm_port] = cdev;
return 0;
}
static int aspeed_create_fan(struct device *dev,
struct device_node *child,
struct aspeed_pwm_tacho_data *priv)
{
u8 *fan_tach_ch;
u32 pwm_port;
int ret, count;
ret = of_property_read_u32(child, "reg", &pwm_port);
if (ret)
return ret;
aspeed_create_pwm_port(priv, (u8)pwm_port);
ret = of_property_count_u8_elems(child, "cooling-levels");
if (ret > 0) {
ret = aspeed_create_pwm_cooling(dev, child, priv, pwm_port,
ret);
if (ret)
return ret;
}
count = of_property_count_u8_elems(child, "aspeed,fan-tach-ch");
if (count < 1)
return -EINVAL;
fan_tach_ch = devm_kzalloc(dev, sizeof(*fan_tach_ch) * count,
GFP_KERNEL);
if (!fan_tach_ch)
return -ENOMEM;
ret = of_property_read_u8_array(child, "aspeed,fan-tach-ch",
fan_tach_ch, count);
if (ret)
return ret;
aspeed_create_fan_tach_channel(priv, fan_tach_ch, count, pwm_port);
return 0;
}
static int aspeed_pwm_tacho_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np, *child;
struct aspeed_pwm_tacho_data *priv;
void __iomem *regs;
struct resource *res;
struct device *hwmon;
struct clk *clk;
int ret;
np = dev->of_node;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init(dev, NULL, (__force void *)regs,
&aspeed_pwm_tacho_regmap_config);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
regmap_write(priv->regmap, ASPEED_PTCR_TACH_SOURCE, 0);
regmap_write(priv->regmap, ASPEED_PTCR_TACH_SOURCE_EXT, 0);
clk = devm_clk_get(dev, NULL);
if (IS_ERR(clk))
return -ENODEV;
priv->clk_freq = clk_get_rate(clk);
aspeed_set_clock_enable(priv->regmap, true);
aspeed_set_clock_source(priv->regmap, 0);
aspeed_create_type(priv);
for_each_child_of_node(np, child) {
ret = aspeed_create_fan(dev, child, priv);
if (ret) {
of_node_put(child);
return ret;
}
}
priv->groups[0] = &pwm_dev_group;
priv->groups[1] = &fan_dev_group;
priv->groups[2] = NULL;
hwmon = devm_hwmon_device_register_with_groups(dev,
"aspeed_pwm_tacho",
priv, priv->groups);
return PTR_ERR_OR_ZERO(hwmon);
}
