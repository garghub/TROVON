static int pbias_regulator_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct pbias_regulator_data *drvdata;
struct resource *res;
struct regulator_config cfg = { };
struct regmap *syscon;
const struct pbias_reg_info *info;
int ret = 0;
int count, idx, data_idx = 0;
const struct of_device_id *match;
const struct pbias_of_data *data;
unsigned int offset;
count = of_regulator_match(&pdev->dev, np, pbias_matches,
PBIAS_NUM_REGS);
if (count < 0)
return count;
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct pbias_regulator_data)
* count, GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
syscon = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(syscon))
return PTR_ERR(syscon);
match = of_match_device(of_match_ptr(pbias_of_match), &pdev->dev);
if (match && match->data) {
data = match->data;
offset = data->offset;
} else {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
offset = res->start;
dev_WARN(&pdev->dev,
"using legacy dt data for pbias offset\n");
}
cfg.regmap = syscon;
cfg.dev = &pdev->dev;
for (idx = 0; idx < PBIAS_NUM_REGS && data_idx < count; idx++) {
if (!pbias_matches[idx].init_data ||
!pbias_matches[idx].of_node)
continue;
info = pbias_matches[idx].driver_data;
if (!info)
return -ENODEV;
drvdata[data_idx].syscon = syscon;
drvdata[data_idx].info = info;
drvdata[data_idx].desc.name = info->name;
drvdata[data_idx].desc.owner = THIS_MODULE;
drvdata[data_idx].desc.type = REGULATOR_VOLTAGE;
drvdata[data_idx].desc.ops = &pbias_regulator_voltage_ops;
drvdata[data_idx].desc.volt_table = pbias_volt_table;
drvdata[data_idx].desc.n_voltages = 2;
drvdata[data_idx].desc.enable_time = info->enable_time;
drvdata[data_idx].desc.vsel_reg = offset;
drvdata[data_idx].desc.vsel_mask = info->vmode;
drvdata[data_idx].desc.enable_reg = offset;
drvdata[data_idx].desc.enable_mask = info->enable_mask;
drvdata[data_idx].desc.enable_val = info->enable;
drvdata[data_idx].desc.disable_val = info->disable_val;
cfg.init_data = pbias_matches[idx].init_data;
cfg.driver_data = &drvdata[data_idx];
cfg.of_node = pbias_matches[idx].of_node;
drvdata[data_idx].dev = devm_regulator_register(&pdev->dev,
&drvdata[data_idx].desc, &cfg);
if (IS_ERR(drvdata[data_idx].dev)) {
ret = PTR_ERR(drvdata[data_idx].dev);
dev_err(&pdev->dev,
"Failed to register regulator: %d\n", ret);
goto err_regulator;
}
data_idx++;
}
platform_set_drvdata(pdev, drvdata);
err_regulator:
return ret;
}
