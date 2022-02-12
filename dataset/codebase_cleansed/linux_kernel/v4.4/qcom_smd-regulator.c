static int rpm_reg_write_active(struct qcom_rpm_reg *vreg,
struct rpm_regulator_req *req,
size_t size)
{
return qcom_rpm_smd_write(vreg->rpm,
QCOM_SMD_RPM_ACTIVE_STATE,
vreg->type,
vreg->id,
req, size);
}
static int rpm_reg_enable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
struct rpm_regulator_req req;
int ret;
req.key = cpu_to_le32(RPM_KEY_SWEN);
req.nbytes = cpu_to_le32(sizeof(u32));
req.value = cpu_to_le32(1);
ret = rpm_reg_write_active(vreg, &req, sizeof(req));
if (!ret)
vreg->is_enabled = 1;
return ret;
}
static int rpm_reg_is_enabled(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
return vreg->is_enabled;
}
static int rpm_reg_disable(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
struct rpm_regulator_req req;
int ret;
req.key = cpu_to_le32(RPM_KEY_SWEN);
req.nbytes = cpu_to_le32(sizeof(u32));
req.value = 0;
ret = rpm_reg_write_active(vreg, &req, sizeof(req));
if (!ret)
vreg->is_enabled = 0;
return ret;
}
static int rpm_reg_get_voltage(struct regulator_dev *rdev)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
return vreg->uV;
}
static int rpm_reg_set_voltage(struct regulator_dev *rdev,
int min_uV,
int max_uV,
unsigned *selector)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
struct rpm_regulator_req req;
int ret = 0;
req.key = cpu_to_le32(RPM_KEY_UV);
req.nbytes = cpu_to_le32(sizeof(u32));
req.value = cpu_to_le32(min_uV);
ret = rpm_reg_write_active(vreg, &req, sizeof(req));
if (!ret)
vreg->uV = min_uV;
return ret;
}
static int rpm_reg_set_load(struct regulator_dev *rdev, int load_uA)
{
struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
struct rpm_regulator_req req;
req.key = cpu_to_le32(RPM_KEY_MA);
req.nbytes = cpu_to_le32(sizeof(u32));
req.value = cpu_to_le32(load_uA / 1000);
return rpm_reg_write_active(vreg, &req, sizeof(req));
}
static int rpm_reg_probe(struct platform_device *pdev)
{
const struct rpm_regulator_data *reg;
const struct of_device_id *match;
struct regulator_config config = { };
struct regulator_dev *rdev;
struct qcom_rpm_reg *vreg;
struct qcom_smd_rpm *rpm;
rpm = dev_get_drvdata(pdev->dev.parent);
if (!rpm) {
dev_err(&pdev->dev, "unable to retrieve handle to rpm\n");
return -ENODEV;
}
match = of_match_device(rpm_of_match, &pdev->dev);
for (reg = match->data; reg->name; reg++) {
vreg = devm_kzalloc(&pdev->dev, sizeof(*vreg), GFP_KERNEL);
if (!vreg)
return -ENOMEM;
vreg->dev = &pdev->dev;
vreg->type = reg->type;
vreg->id = reg->id;
vreg->rpm = rpm;
memcpy(&vreg->desc, reg->desc, sizeof(vreg->desc));
vreg->desc.id = -1;
vreg->desc.owner = THIS_MODULE;
vreg->desc.type = REGULATOR_VOLTAGE;
vreg->desc.name = reg->name;
vreg->desc.supply_name = reg->supply;
vreg->desc.of_match = reg->name;
config.dev = &pdev->dev;
config.driver_data = vreg;
rdev = devm_regulator_register(&pdev->dev, &vreg->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register %s\n", reg->name);
return PTR_ERR(rdev);
}
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
