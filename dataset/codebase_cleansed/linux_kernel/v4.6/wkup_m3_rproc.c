static int wkup_m3_rproc_start(struct rproc *rproc)
{
struct wkup_m3_rproc *wkupm3 = rproc->priv;
struct platform_device *pdev = wkupm3->pdev;
struct device *dev = &pdev->dev;
struct wkup_m3_platform_data *pdata = dev_get_platdata(dev);
if (pdata->deassert_reset(pdev, pdata->reset_name)) {
dev_err(dev, "Unable to reset wkup_m3!\n");
return -ENODEV;
}
return 0;
}
static int wkup_m3_rproc_stop(struct rproc *rproc)
{
struct wkup_m3_rproc *wkupm3 = rproc->priv;
struct platform_device *pdev = wkupm3->pdev;
struct device *dev = &pdev->dev;
struct wkup_m3_platform_data *pdata = dev_get_platdata(dev);
if (pdata->assert_reset(pdev, pdata->reset_name)) {
dev_err(dev, "Unable to assert reset of wkup_m3!\n");
return -ENODEV;
}
return 0;
}
static void *wkup_m3_rproc_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct wkup_m3_rproc *wkupm3 = rproc->priv;
void *va = NULL;
int i;
u32 offset;
if (len <= 0)
return NULL;
for (i = 0; i < WKUPM3_MEM_MAX; i++) {
if (da >= wkupm3->mem[i].dev_addr && da + len <=
wkupm3->mem[i].dev_addr + wkupm3->mem[i].size) {
offset = da - wkupm3->mem[i].dev_addr;
va = (__force void *)(wkupm3->mem[i].cpu_addr + offset);
break;
}
}
return va;
}
static int wkup_m3_rproc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct wkup_m3_platform_data *pdata = dev->platform_data;
const char *mem_names[WKUPM3_MEM_MAX] = { "umem", "dmem" };
struct wkup_m3_rproc *wkupm3;
const char *fw_name;
struct rproc *rproc;
struct resource *res;
const __be32 *addrp;
u32 l4_offset = 0;
u64 size;
int ret;
int i;
if (!(pdata && pdata->deassert_reset && pdata->assert_reset &&
pdata->reset_name)) {
dev_err(dev, "Platform data missing!\n");
return -ENODEV;
}
ret = of_property_read_string(dev->of_node, "ti,pm-firmware",
&fw_name);
if (ret) {
dev_err(dev, "No firmware filename given\n");
return -ENODEV;
}
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "pm_runtime_get_sync() failed\n");
goto err;
}
rproc = rproc_alloc(dev, "wkup_m3", &wkup_m3_rproc_ops,
fw_name, sizeof(*wkupm3));
if (!rproc) {
ret = -ENOMEM;
goto err;
}
wkupm3 = rproc->priv;
wkupm3->rproc = rproc;
wkupm3->pdev = pdev;
for (i = 0; i < ARRAY_SIZE(mem_names); i++) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
mem_names[i]);
wkupm3->mem[i].cpu_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(wkupm3->mem[i].cpu_addr)) {
dev_err(&pdev->dev, "devm_ioremap_resource failed for resource %d\n",
i);
ret = PTR_ERR(wkupm3->mem[i].cpu_addr);
goto err;
}
wkupm3->mem[i].bus_addr = res->start;
wkupm3->mem[i].size = resource_size(res);
addrp = of_get_address(dev->of_node, i, &size, NULL);
if (!strcmp(mem_names[i], "umem"))
l4_offset = be32_to_cpu(*addrp);
wkupm3->mem[i].dev_addr = be32_to_cpu(*addrp) - l4_offset;
}
dev_set_drvdata(dev, rproc);
ret = rproc_add(rproc);
if (ret) {
dev_err(dev, "rproc_add failed\n");
goto err_put_rproc;
}
return 0;
err_put_rproc:
rproc_put(rproc);
err:
pm_runtime_put_noidle(dev);
pm_runtime_disable(dev);
return ret;
}
static int wkup_m3_rproc_remove(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
rproc_del(rproc);
rproc_put(rproc);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int wkup_m3_rpm_suspend(struct device *dev)
{
return -EBUSY;
}
static int wkup_m3_rpm_resume(struct device *dev)
{
return 0;
}
