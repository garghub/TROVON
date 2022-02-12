static int rockchip_iodomain_write(struct rockchip_iodomain_supply *supply,
int uV)
{
struct rockchip_iodomain *iod = supply->iod;
u32 val;
int ret;
val = (uV > MAX_VOLTAGE_1_8) ? 0 : 1;
val <<= supply->idx;
val |= (BIT(supply->idx) << 16);
ret = regmap_write(iod->grf, iod->soc_data->grf_offset, val);
if (ret)
dev_err(iod->dev, "Couldn't write to GRF\n");
return ret;
}
static int rockchip_iodomain_notify(struct notifier_block *nb,
unsigned long event,
void *data)
{
struct rockchip_iodomain_supply *supply =
container_of(nb, struct rockchip_iodomain_supply, nb);
int uV;
int ret;
if (event & REGULATOR_EVENT_PRE_VOLTAGE_CHANGE) {
struct pre_voltage_change_data *pvc_data = data;
uV = max_t(unsigned long, pvc_data->old_uV, pvc_data->max_uV);
} else if (event & (REGULATOR_EVENT_VOLTAGE_CHANGE |
REGULATOR_EVENT_ABORT_VOLTAGE_CHANGE)) {
uV = (unsigned long)data;
} else {
return NOTIFY_OK;
}
dev_dbg(supply->iod->dev, "Setting to %d\n", uV);
if (uV > MAX_VOLTAGE_3_3) {
dev_err(supply->iod->dev, "Voltage too high: %d\n", uV);
if (event == REGULATOR_EVENT_PRE_VOLTAGE_CHANGE)
return NOTIFY_BAD;
}
ret = rockchip_iodomain_write(supply, uV);
if (ret && event == REGULATOR_EVENT_PRE_VOLTAGE_CHANGE)
return NOTIFY_BAD;
dev_dbg(supply->iod->dev, "Setting to %d done\n", uV);
return NOTIFY_OK;
}
static void rk3288_iodomain_init(struct rockchip_iodomain *iod)
{
int ret;
u32 val;
if (!iod->supplies[RK3288_SOC_FLASH_SUPPLY_NUM].reg)
return;
val = RK3288_SOC_CON2_FLASH0 | (RK3288_SOC_CON2_FLASH0 << 16);
ret = regmap_write(iod->grf, RK3288_SOC_CON2, val);
if (ret < 0)
dev_warn(iod->dev, "couldn't update flash0 ctrl\n");
}
static void rk3368_iodomain_init(struct rockchip_iodomain *iod)
{
int ret;
u32 val;
if (!iod->supplies[RK3368_SOC_FLASH_SUPPLY_NUM].reg)
return;
val = RK3368_SOC_CON15_FLASH0 | (RK3368_SOC_CON15_FLASH0 << 16);
ret = regmap_write(iod->grf, RK3368_SOC_CON15, val);
if (ret < 0)
dev_warn(iod->dev, "couldn't update flash0 ctrl\n");
}
static void rk3399_pmu_iodomain_init(struct rockchip_iodomain *iod)
{
int ret;
u32 val;
if (!iod->supplies[RK3399_PMUGRF_VSEL_SUPPLY_NUM].reg)
return;
val = RK3399_PMUGRF_CON0_VSEL | (RK3399_PMUGRF_CON0_VSEL << 16);
ret = regmap_write(iod->grf, RK3399_PMUGRF_CON0, val);
if (ret < 0)
dev_warn(iod->dev, "couldn't update pmu io iodomain ctrl\n");
}
static int rockchip_iodomain_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct rockchip_iodomain *iod;
struct device *parent;
int i, ret = 0;
if (!np)
return -ENODEV;
iod = devm_kzalloc(&pdev->dev, sizeof(*iod), GFP_KERNEL);
if (!iod)
return -ENOMEM;
iod->dev = &pdev->dev;
platform_set_drvdata(pdev, iod);
match = of_match_node(rockchip_iodomain_match, np);
iod->soc_data = (struct rockchip_iodomain_soc_data *)match->data;
parent = pdev->dev.parent;
if (parent && parent->of_node) {
iod->grf = syscon_node_to_regmap(parent->of_node);
} else {
dev_dbg(&pdev->dev, "falling back to old binding\n");
iod->grf = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
}
if (IS_ERR(iod->grf)) {
dev_err(&pdev->dev, "couldn't find grf regmap\n");
return PTR_ERR(iod->grf);
}
for (i = 0; i < MAX_SUPPLIES; i++) {
const char *supply_name = iod->soc_data->supply_names[i];
struct rockchip_iodomain_supply *supply = &iod->supplies[i];
struct regulator *reg;
int uV;
if (!supply_name)
continue;
reg = devm_regulator_get_optional(iod->dev, supply_name);
if (IS_ERR(reg)) {
ret = PTR_ERR(reg);
if (ret == -ENODEV)
continue;
else if (ret != -EPROBE_DEFER)
dev_err(iod->dev, "couldn't get regulator %s\n",
supply_name);
goto unreg_notify;
}
uV = regulator_get_voltage(reg);
if (uV < 0) {
dev_err(iod->dev, "Can't determine voltage: %s\n",
supply_name);
goto unreg_notify;
}
if (uV > MAX_VOLTAGE_3_3) {
dev_crit(iod->dev,
"%d uV is too high. May damage SoC!\n",
uV);
ret = -EINVAL;
goto unreg_notify;
}
supply->idx = i;
supply->iod = iod;
supply->reg = reg;
supply->nb.notifier_call = rockchip_iodomain_notify;
ret = rockchip_iodomain_write(supply, uV);
if (ret) {
supply->reg = NULL;
goto unreg_notify;
}
ret = regulator_register_notifier(reg, &supply->nb);
if (ret) {
dev_err(&pdev->dev,
"regulator notifier request failed\n");
supply->reg = NULL;
goto unreg_notify;
}
}
if (iod->soc_data->init)
iod->soc_data->init(iod);
return 0;
unreg_notify:
for (i = MAX_SUPPLIES - 1; i >= 0; i--) {
struct rockchip_iodomain_supply *io_supply = &iod->supplies[i];
if (io_supply->reg)
regulator_unregister_notifier(io_supply->reg,
&io_supply->nb);
}
return ret;
}
static int rockchip_iodomain_remove(struct platform_device *pdev)
{
struct rockchip_iodomain *iod = platform_get_drvdata(pdev);
int i;
for (i = MAX_SUPPLIES - 1; i >= 0; i--) {
struct rockchip_iodomain_supply *io_supply = &iod->supplies[i];
if (io_supply->reg)
regulator_unregister_notifier(io_supply->reg,
&io_supply->nb);
}
return 0;
}
