static int rpm_reg_write(struct qcom_rpm_reg *vreg,
const struct request_member *req,
const int value)
{
if (WARN_ON((value << req->shift) & ~req->mask))
return -EINVAL;
vreg->val[req->word] &= ~req->mask;
vreg->val[req->word] |= value << req->shift;
return qcom_rpm_write(vreg->rpm,
vreg->resource,
vreg->val,
vreg->parts->request_len);
}
static int rpm_reg_set_mV_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->mV;
int ret = 0;
int uV;
if (req->mask == 0)
return -EINVAL;
uV = regulator_list_voltage_linear_range(rdev, selector);
if (uV < 0)
return uV;
mutex_lock(&vreg->lock);
vreg->uV = uV;
if (vreg->is_enabled)
ret = rpm_reg_write(vreg, req, vreg->uV / 1000);
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_set_uV_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->uV;
int ret = 0;
int uV;
if (req->mask == 0)
return -EINVAL;
uV = regulator_list_voltage_linear_range(rdev, selector);
if (uV < 0)
return uV;
mutex_lock(&vreg->lock);
vreg->uV = uV;
if (vreg->is_enabled)
ret = rpm_reg_write(vreg, req, vreg->uV);
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_get_voltage(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
return vreg->uV;
}
static int rpm_reg_mV_enable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->mV;
int ret;
if (req->mask == 0)
return -EINVAL;
mutex_lock(&vreg->lock);
ret = rpm_reg_write(vreg, req, vreg->uV / 1000);
if (!ret)
vreg->is_enabled = 1;
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_uV_enable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->uV;
int ret;
if (req->mask == 0)
return -EINVAL;
mutex_lock(&vreg->lock);
ret = rpm_reg_write(vreg, req, vreg->uV);
if (!ret)
vreg->is_enabled = 1;
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_switch_enable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->enable_state;
int ret;
if (req->mask == 0)
return -EINVAL;
mutex_lock(&vreg->lock);
ret = rpm_reg_write(vreg, req, 1);
if (!ret)
vreg->is_enabled = 1;
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_mV_disable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->mV;
int ret;
if (req->mask == 0)
return -EINVAL;
mutex_lock(&vreg->lock);
ret = rpm_reg_write(vreg, req, 0);
if (!ret)
vreg->is_enabled = 0;
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_uV_disable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->uV;
int ret;
if (req->mask == 0)
return -EINVAL;
mutex_lock(&vreg->lock);
ret = rpm_reg_write(vreg, req, 0);
if (!ret)
vreg->is_enabled = 0;
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_switch_disable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
const struct rpm_reg_parts *parts = vreg->parts;
const struct request_member *req = &parts->enable_state;
int ret;
if (req->mask == 0)
return -EINVAL;
mutex_lock(&vreg->lock);
ret = rpm_reg_write(vreg, req, 0);
if (!ret)
vreg->is_enabled = 0;
mutex_unlock(&vreg->lock);
return ret;
}
static int rpm_reg_is_enabled(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
return vreg->is_enabled;
}
static int rpm_reg_set(struct qcom_rpm_reg *vreg,
const struct request_member *req,
const int value)
{
if (req->mask == 0 || (value << req->shift) & ~req->mask)
return -EINVAL;
vreg->val[req->word] &= ~req->mask;
vreg->val[req->word] |= value << req->shift;
return 0;
}
static int rpm_reg_of_parse_freq(struct device *dev, struct qcom_rpm_reg *vreg)
{
static const int freq_table[] = {
19200000, 9600000, 6400000, 4800000, 3840000, 3200000, 2740000,
2400000, 2130000, 1920000, 1750000, 1600000, 1480000, 1370000,
1280000, 1200000,
};
const char *key;
u32 freq;
int ret;
int i;
key = "qcom,switch-mode-frequency";
ret = of_property_read_u32(dev->of_node, key, &freq);
if (ret) {
dev_err(dev, "regulator requires %s property\n", key);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(freq_table); i++) {
if (freq == freq_table[i]) {
rpm_reg_set(vreg, &vreg->parts->freq, i + 1);
return 0;
}
}
dev_err(dev, "invalid frequency %d\n", freq);
return -EINVAL;
}
static int rpm_reg_probe(struct platform_device *pdev)
{
struct regulator_init_data *initdata;
const struct qcom_rpm_reg *template;
const struct of_device_id *match;
struct regulator_config config = { };
struct regulator_dev *rdev;
struct qcom_rpm_reg *vreg;
const char *key;
u32 force_mode;
bool pwm;
u32 val;
int ret;
match = of_match_device(rpm_of_match, &pdev->dev);
template = match->data;
vreg = devm_kmalloc(&pdev->dev, sizeof(*vreg), GFP_KERNEL);
if (!vreg) {
dev_err(&pdev->dev, "failed to allocate vreg\n");
return -ENOMEM;
}
memcpy(vreg, template, sizeof(*vreg));
mutex_init(&vreg->lock);
vreg->dev = &pdev->dev;
vreg->desc.id = -1;
vreg->desc.owner = THIS_MODULE;
vreg->desc.type = REGULATOR_VOLTAGE;
vreg->desc.name = pdev->dev.of_node->name;
vreg->rpm = dev_get_drvdata(pdev->dev.parent);
if (!vreg->rpm) {
dev_err(&pdev->dev, "unable to retrieve handle to rpm\n");
return -ENODEV;
}
initdata = of_get_regulator_init_data(&pdev->dev, pdev->dev.of_node,
&vreg->desc);
if (!initdata)
return -EINVAL;
key = "reg";
ret = of_property_read_u32(pdev->dev.of_node, key, &val);
if (ret) {
dev_err(&pdev->dev, "failed to read %s\n", key);
return ret;
}
vreg->resource = val;
if ((vreg->parts->uV.mask || vreg->parts->mV.mask) &&
(!initdata->constraints.min_uV || !initdata->constraints.max_uV)) {
dev_err(&pdev->dev, "no voltage specified for regulator\n");
return -EINVAL;
}
key = "bias-pull-down";
if (of_property_read_bool(pdev->dev.of_node, key)) {
ret = rpm_reg_set(vreg, &vreg->parts->pd, 1);
if (ret) {
dev_err(&pdev->dev, "%s is invalid", key);
return ret;
}
}
if (vreg->parts->freq.mask) {
ret = rpm_reg_of_parse_freq(&pdev->dev, vreg);
if (ret < 0)
return ret;
}
if (vreg->parts->pm.mask) {
key = "qcom,power-mode-hysteretic";
pwm = !of_property_read_bool(pdev->dev.of_node, key);
ret = rpm_reg_set(vreg, &vreg->parts->pm, pwm);
if (ret) {
dev_err(&pdev->dev, "failed to set power mode\n");
return ret;
}
}
if (vreg->parts->fm.mask) {
force_mode = -1;
key = "qcom,force-mode";
ret = of_property_read_u32(pdev->dev.of_node, key, &val);
if (ret == -EINVAL) {
val = QCOM_RPM_FORCE_MODE_NONE;
} else if (ret < 0) {
dev_err(&pdev->dev, "failed to read %s\n", key);
return ret;
}
switch (val) {
case QCOM_RPM_FORCE_MODE_NONE:
force_mode = 0;
break;
case QCOM_RPM_FORCE_MODE_LPM:
force_mode = 1;
break;
case QCOM_RPM_FORCE_MODE_HPM:
if (FORCE_MODE_IS_2_BITS(vreg))
force_mode = 2;
else
force_mode = 3;
break;
case QCOM_RPM_FORCE_MODE_AUTO:
if (vreg->supports_force_mode_auto)
force_mode = 2;
break;
case QCOM_RPM_FORCE_MODE_BYPASS:
if (vreg->supports_force_mode_bypass)
force_mode = 4;
break;
}
if (force_mode < 0) {
dev_err(&pdev->dev, "invalid force mode\n");
return -EINVAL;
}
ret = rpm_reg_set(vreg, &vreg->parts->fm, force_mode);
if (ret) {
dev_err(&pdev->dev, "failed to set force mode\n");
return ret;
}
}
config.dev = &pdev->dev;
config.init_data = initdata;
config.driver_data = vreg;
config.of_node = pdev->dev.of_node;
rdev = devm_regulator_register(&pdev->dev, &vreg->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "can't register regulator\n");
return PTR_ERR(rdev);
}
return 0;
}
static int __init rpm_reg_init(void)
{
return platform_driver_register(&rpm_reg_driver);
}
static void __exit rpm_reg_exit(void)
{
platform_driver_unregister(&rpm_reg_driver);
}
