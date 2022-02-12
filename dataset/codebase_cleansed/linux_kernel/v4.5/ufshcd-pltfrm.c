static int ufshcd_parse_clock_info(struct ufs_hba *hba)
{
int ret = 0;
int cnt;
int i;
struct device *dev = hba->dev;
struct device_node *np = dev->of_node;
char *name;
u32 *clkfreq = NULL;
struct ufs_clk_info *clki;
int len = 0;
size_t sz = 0;
if (!np)
goto out;
INIT_LIST_HEAD(&hba->clk_list_head);
cnt = of_property_count_strings(np, "clock-names");
if (!cnt || (cnt == -EINVAL)) {
dev_info(dev, "%s: Unable to find clocks, assuming enabled\n",
__func__);
} else if (cnt < 0) {
dev_err(dev, "%s: count clock strings failed, err %d\n",
__func__, cnt);
ret = cnt;
}
if (cnt <= 0)
goto out;
if (!of_get_property(np, "freq-table-hz", &len)) {
dev_info(dev, "freq-table-hz property not specified\n");
goto out;
}
if (len <= 0)
goto out;
sz = len / sizeof(*clkfreq);
if (sz != 2 * cnt) {
dev_err(dev, "%s len mismatch\n", "freq-table-hz");
ret = -EINVAL;
goto out;
}
clkfreq = devm_kzalloc(dev, sz * sizeof(*clkfreq),
GFP_KERNEL);
if (!clkfreq) {
ret = -ENOMEM;
goto out;
}
ret = of_property_read_u32_array(np, "freq-table-hz",
clkfreq, sz);
if (ret && (ret != -EINVAL)) {
dev_err(dev, "%s: error reading array %d\n",
"freq-table-hz", ret);
return ret;
}
for (i = 0; i < sz; i += 2) {
ret = of_property_read_string_index(np,
"clock-names", i/2, (const char **)&name);
if (ret)
goto out;
clki = devm_kzalloc(dev, sizeof(*clki), GFP_KERNEL);
if (!clki) {
ret = -ENOMEM;
goto out;
}
clki->min_freq = clkfreq[i];
clki->max_freq = clkfreq[i+1];
clki->name = kstrdup(name, GFP_KERNEL);
dev_dbg(dev, "%s: min %u max %u name %s\n", "freq-table-hz",
clki->min_freq, clki->max_freq, clki->name);
list_add_tail(&clki->list, &hba->clk_list_head);
}
out:
return ret;
}
static int ufshcd_populate_vreg(struct device *dev, const char *name,
struct ufs_vreg **out_vreg)
{
int ret = 0;
char prop_name[MAX_PROP_SIZE];
struct ufs_vreg *vreg = NULL;
struct device_node *np = dev->of_node;
if (!np) {
dev_err(dev, "%s: non DT initialization\n", __func__);
goto out;
}
snprintf(prop_name, MAX_PROP_SIZE, "%s-supply", name);
if (!of_parse_phandle(np, prop_name, 0)) {
dev_info(dev, "%s: Unable to find %s regulator, assuming enabled\n",
__func__, prop_name);
goto out;
}
vreg = devm_kzalloc(dev, sizeof(*vreg), GFP_KERNEL);
if (!vreg)
return -ENOMEM;
vreg->name = kstrdup(name, GFP_KERNEL);
snprintf(prop_name, MAX_PROP_SIZE, "%s-fixed-regulator", name);
if (of_property_read_bool(np, prop_name))
goto out;
snprintf(prop_name, MAX_PROP_SIZE, "%s-max-microamp", name);
ret = of_property_read_u32(np, prop_name, &vreg->max_uA);
if (ret) {
dev_err(dev, "%s: unable to find %s err %d\n",
__func__, prop_name, ret);
goto out_free;
}
vreg->min_uA = 0;
if (!strcmp(name, "vcc")) {
if (of_property_read_bool(np, "vcc-supply-1p8")) {
vreg->min_uV = UFS_VREG_VCC_1P8_MIN_UV;
vreg->max_uV = UFS_VREG_VCC_1P8_MAX_UV;
} else {
vreg->min_uV = UFS_VREG_VCC_MIN_UV;
vreg->max_uV = UFS_VREG_VCC_MAX_UV;
}
} else if (!strcmp(name, "vccq")) {
vreg->min_uV = UFS_VREG_VCCQ_MIN_UV;
vreg->max_uV = UFS_VREG_VCCQ_MAX_UV;
} else if (!strcmp(name, "vccq2")) {
vreg->min_uV = UFS_VREG_VCCQ2_MIN_UV;
vreg->max_uV = UFS_VREG_VCCQ2_MAX_UV;
}
goto out;
out_free:
devm_kfree(dev, vreg);
vreg = NULL;
out:
if (!ret)
*out_vreg = vreg;
return ret;
}
static int ufshcd_parse_regulator_info(struct ufs_hba *hba)
{
int err;
struct device *dev = hba->dev;
struct ufs_vreg_info *info = &hba->vreg_info;
err = ufshcd_populate_vreg(dev, "vdd-hba", &info->vdd_hba);
if (err)
goto out;
err = ufshcd_populate_vreg(dev, "vcc", &info->vcc);
if (err)
goto out;
err = ufshcd_populate_vreg(dev, "vccq", &info->vccq);
if (err)
goto out;
err = ufshcd_populate_vreg(dev, "vccq2", &info->vccq2);
out:
return err;
}
int ufshcd_pltfrm_suspend(struct device *dev)
{
return ufshcd_system_suspend(dev_get_drvdata(dev));
}
int ufshcd_pltfrm_resume(struct device *dev)
{
return ufshcd_system_resume(dev_get_drvdata(dev));
}
int ufshcd_pltfrm_runtime_suspend(struct device *dev)
{
return ufshcd_runtime_suspend(dev_get_drvdata(dev));
}
int ufshcd_pltfrm_runtime_resume(struct device *dev)
{
return ufshcd_runtime_resume(dev_get_drvdata(dev));
}
int ufshcd_pltfrm_runtime_idle(struct device *dev)
{
return ufshcd_runtime_idle(dev_get_drvdata(dev));
}
void ufshcd_pltfrm_shutdown(struct platform_device *pdev)
{
ufshcd_shutdown((struct ufs_hba *)platform_get_drvdata(pdev));
}
int ufshcd_pltfrm_init(struct platform_device *pdev,
struct ufs_hba_variant_ops *vops)
{
struct ufs_hba *hba;
void __iomem *mmio_base;
struct resource *mem_res;
int irq, err;
struct device *dev = &pdev->dev;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmio_base = devm_ioremap_resource(dev, mem_res);
if (IS_ERR(*(void **)&mmio_base)) {
err = PTR_ERR(*(void **)&mmio_base);
goto out;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "IRQ resource not available\n");
err = -ENODEV;
goto out;
}
err = ufshcd_alloc_host(dev, &hba);
if (err) {
dev_err(&pdev->dev, "Allocation failed\n");
goto out;
}
hba->vops = vops;
err = ufshcd_parse_clock_info(hba);
if (err) {
dev_err(&pdev->dev, "%s: clock parse failed %d\n",
__func__, err);
goto dealloc_host;
}
err = ufshcd_parse_regulator_info(hba);
if (err) {
dev_err(&pdev->dev, "%s: regulator init failed %d\n",
__func__, err);
goto dealloc_host;
}
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
err = ufshcd_init(hba, mmio_base, irq);
if (err) {
dev_err(dev, "Initialization failed\n");
goto out_disable_rpm;
}
platform_set_drvdata(pdev, hba);
return 0;
out_disable_rpm:
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
dealloc_host:
ufshcd_dealloc_host(hba);
out:
return err;
}
