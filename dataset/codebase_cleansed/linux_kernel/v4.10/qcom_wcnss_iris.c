int qcom_iris_enable(struct qcom_iris *iris)
{
int ret;
ret = regulator_bulk_enable(iris->num_vregs, iris->vregs);
if (ret)
return ret;
ret = clk_prepare_enable(iris->xo_clk);
if (ret) {
dev_err(iris->dev, "failed to enable xo clk\n");
goto disable_regulators;
}
return 0;
disable_regulators:
regulator_bulk_disable(iris->num_vregs, iris->vregs);
return ret;
}
void qcom_iris_disable(struct qcom_iris *iris)
{
clk_disable_unprepare(iris->xo_clk);
regulator_bulk_disable(iris->num_vregs, iris->vregs);
}
static int qcom_iris_probe(struct platform_device *pdev)
{
const struct iris_data *data;
struct qcom_wcnss *wcnss;
struct qcom_iris *iris;
int ret;
int i;
iris = devm_kzalloc(&pdev->dev, sizeof(struct qcom_iris), GFP_KERNEL);
if (!iris)
return -ENOMEM;
data = of_device_get_match_data(&pdev->dev);
wcnss = dev_get_drvdata(pdev->dev.parent);
iris->xo_clk = devm_clk_get(&pdev->dev, "xo");
if (IS_ERR(iris->xo_clk)) {
if (PTR_ERR(iris->xo_clk) != -EPROBE_DEFER)
dev_err(&pdev->dev, "failed to acquire xo clk\n");
return PTR_ERR(iris->xo_clk);
}
iris->num_vregs = data->num_vregs;
iris->vregs = devm_kcalloc(&pdev->dev,
iris->num_vregs,
sizeof(struct regulator_bulk_data),
GFP_KERNEL);
if (!iris->vregs)
return -ENOMEM;
for (i = 0; i < iris->num_vregs; i++)
iris->vregs[i].supply = data->vregs[i].name;
ret = devm_regulator_bulk_get(&pdev->dev, iris->num_vregs, iris->vregs);
if (ret) {
dev_err(&pdev->dev, "failed to get regulators\n");
return ret;
}
for (i = 0; i < iris->num_vregs; i++) {
if (data->vregs[i].max_voltage)
regulator_set_voltage(iris->vregs[i].consumer,
data->vregs[i].min_voltage,
data->vregs[i].max_voltage);
if (data->vregs[i].load_uA)
regulator_set_load(iris->vregs[i].consumer,
data->vregs[i].load_uA);
}
qcom_wcnss_assign_iris(wcnss, iris, data->use_48mhz_xo);
return 0;
}
static int qcom_iris_remove(struct platform_device *pdev)
{
struct qcom_wcnss *wcnss = dev_get_drvdata(pdev->dev.parent);
qcom_wcnss_assign_iris(wcnss, NULL, false);
return 0;
}
