static void _add_clkdev(struct omap_device *od, const char *clk_alias,
const char *clk_name)
{
struct clk *r;
struct clk_lookup *l;
if (!clk_alias || !clk_name)
return;
dev_dbg(&od->pdev->dev, "Creating %s -> %s\n", clk_alias, clk_name);
r = clk_get_sys(dev_name(&od->pdev->dev), clk_alias);
if (!IS_ERR(r)) {
dev_warn(&od->pdev->dev,
"alias %s already exists\n", clk_alias);
clk_put(r);
return;
}
r = clk_get(NULL, clk_name);
if (IS_ERR(r)) {
dev_err(&od->pdev->dev,
"clk_get for %s failed\n", clk_name);
return;
}
l = clkdev_alloc(r, clk_alias, dev_name(&od->pdev->dev));
if (!l) {
dev_err(&od->pdev->dev,
"clkdev_alloc for %s failed\n", clk_alias);
return;
}
clkdev_add(l);
}
static void _add_hwmod_clocks_clkdev(struct omap_device *od,
struct omap_hwmod *oh)
{
int i;
_add_clkdev(od, "fck", oh->main_clk);
for (i = 0; i < oh->opt_clks_cnt; i++)
_add_clkdev(od, oh->opt_clks[i].role, oh->opt_clks[i].clk);
}
static int omap_device_build_from_dt(struct platform_device *pdev)
{
struct omap_hwmod **hwmods;
struct omap_device *od;
struct omap_hwmod *oh;
struct device_node *node = pdev->dev.of_node;
const char *oh_name;
int oh_cnt, i, ret = 0;
bool device_active = false;
oh_cnt = of_property_count_strings(node, "ti,hwmods");
if (oh_cnt <= 0) {
dev_dbg(&pdev->dev, "No 'hwmods' to build omap_device\n");
return -ENODEV;
}
hwmods = kzalloc(sizeof(struct omap_hwmod *) * oh_cnt, GFP_KERNEL);
if (!hwmods) {
ret = -ENOMEM;
goto odbfd_exit;
}
for (i = 0; i < oh_cnt; i++) {
of_property_read_string_index(node, "ti,hwmods", i, &oh_name);
oh = omap_hwmod_lookup(oh_name);
if (!oh) {
dev_err(&pdev->dev, "Cannot lookup hwmod '%s'\n",
oh_name);
ret = -EINVAL;
goto odbfd_exit1;
}
hwmods[i] = oh;
if (oh->flags & HWMOD_INIT_NO_IDLE)
device_active = true;
}
od = omap_device_alloc(pdev, hwmods, oh_cnt);
if (!od) {
dev_err(&pdev->dev, "Cannot allocate omap_device for :%s\n",
oh_name);
ret = PTR_ERR(od);
goto odbfd_exit1;
}
for (i = 0; i < pdev->num_resources; i++) {
struct resource *r = &pdev->resource[i];
if (r->name == NULL)
r->name = dev_name(&pdev->dev);
}
pdev->dev.pm_domain = &omap_device_pm_domain;
if (device_active) {
omap_device_enable(pdev);
pm_runtime_set_active(&pdev->dev);
}
odbfd_exit1:
kfree(hwmods);
odbfd_exit:
return ret;
}
static int _omap_device_notifier_call(struct notifier_block *nb,
unsigned long event, void *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_device *od;
switch (event) {
case BUS_NOTIFY_DEL_DEVICE:
if (pdev->archdata.od)
omap_device_delete(pdev->archdata.od);
break;
case BUS_NOTIFY_ADD_DEVICE:
if (pdev->dev.of_node)
omap_device_build_from_dt(pdev);
default:
od = to_omap_device(pdev);
if (od)
od->_driver_status = event;
}
return NOTIFY_DONE;
}
static int _omap_device_enable_hwmods(struct omap_device *od)
{
int i;
for (i = 0; i < od->hwmods_cnt; i++)
omap_hwmod_enable(od->hwmods[i]);
return 0;
}
static int _omap_device_idle_hwmods(struct omap_device *od)
{
int i;
for (i = 0; i < od->hwmods_cnt; i++)
omap_hwmod_idle(od->hwmods[i]);
return 0;
}
int omap_device_get_context_loss_count(struct platform_device *pdev)
{
struct omap_device *od;
u32 ret = 0;
od = to_omap_device(pdev);
if (od->hwmods_cnt)
ret = omap_hwmod_get_context_loss_count(od->hwmods[0]);
return ret;
}
static int omap_device_count_resources(struct omap_device *od,
unsigned long flags)
{
int c = 0;
int i;
for (i = 0; i < od->hwmods_cnt; i++)
c += omap_hwmod_count_resources(od->hwmods[i], flags);
pr_debug("omap_device: %s: counted %d total resources across %d hwmods\n",
od->pdev->name, c, od->hwmods_cnt);
return c;
}
static int omap_device_fill_resources(struct omap_device *od,
struct resource *res)
{
int i, r;
for (i = 0; i < od->hwmods_cnt; i++) {
r = omap_hwmod_fill_resources(od->hwmods[i], res);
res += r;
}
return 0;
}
static int _od_fill_dma_resources(struct omap_device *od,
struct resource *res)
{
int i, r;
for (i = 0; i < od->hwmods_cnt; i++) {
r = omap_hwmod_fill_dma_resources(od->hwmods[i], res);
res += r;
}
return 0;
}
struct omap_device *omap_device_alloc(struct platform_device *pdev,
struct omap_hwmod **ohs, int oh_cnt)
{
int ret = -ENOMEM;
struct omap_device *od;
struct resource *res = NULL;
int i, res_count;
struct omap_hwmod **hwmods;
od = kzalloc(sizeof(struct omap_device), GFP_KERNEL);
if (!od) {
ret = -ENOMEM;
goto oda_exit1;
}
od->hwmods_cnt = oh_cnt;
hwmods = kmemdup(ohs, sizeof(struct omap_hwmod *) * oh_cnt, GFP_KERNEL);
if (!hwmods)
goto oda_exit2;
od->hwmods = hwmods;
od->pdev = pdev;
if (!pdev->num_resources) {
res_count = omap_device_count_resources(od, IORESOURCE_IRQ |
IORESOURCE_DMA |
IORESOURCE_MEM);
} else {
for (i = 0; i < pdev->num_resources; i++) {
struct resource *r = &pdev->resource[i];
if (r->flags == IORESOURCE_DMA)
goto have_everything;
}
res_count = omap_device_count_resources(od, IORESOURCE_DMA);
if (!res_count)
goto have_everything;
res_count += pdev->num_resources;
}
res = kzalloc(sizeof(struct resource) * res_count, GFP_KERNEL);
if (!res)
goto oda_exit3;
if (!pdev->num_resources) {
dev_dbg(&pdev->dev, "%s: using %d resources from hwmod\n",
__func__, res_count);
omap_device_fill_resources(od, res);
} else {
dev_dbg(&pdev->dev,
"%s: appending %d DMA resources from hwmod\n",
__func__, res_count - pdev->num_resources);
memcpy(res, pdev->resource,
sizeof(struct resource) * pdev->num_resources);
_od_fill_dma_resources(od, &res[pdev->num_resources]);
}
ret = platform_device_add_resources(pdev, res, res_count);
kfree(res);
if (ret)
goto oda_exit3;
have_everything:
pdev->archdata.od = od;
for (i = 0; i < oh_cnt; i++) {
hwmods[i]->od = od;
_add_hwmod_clocks_clkdev(od, hwmods[i]);
}
return od;
oda_exit3:
kfree(hwmods);
oda_exit2:
kfree(od);
oda_exit1:
dev_err(&pdev->dev, "omap_device: build failed (%d)\n", ret);
return ERR_PTR(ret);
}
void omap_device_delete(struct omap_device *od)
{
if (!od)
return;
od->pdev->archdata.od = NULL;
kfree(od->hwmods);
kfree(od);
}
struct platform_device __init *omap_device_build(const char *pdev_name,
int pdev_id,
struct omap_hwmod *oh,
void *pdata, int pdata_len)
{
struct omap_hwmod *ohs[] = { oh };
if (!oh)
return ERR_PTR(-EINVAL);
return omap_device_build_ss(pdev_name, pdev_id, ohs, 1, pdata,
pdata_len);
}
struct platform_device __init *omap_device_build_ss(const char *pdev_name,
int pdev_id,
struct omap_hwmod **ohs,
int oh_cnt, void *pdata,
int pdata_len)
{
int ret = -ENOMEM;
struct platform_device *pdev;
struct omap_device *od;
if (!ohs || oh_cnt == 0 || !pdev_name)
return ERR_PTR(-EINVAL);
if (!pdata && pdata_len > 0)
return ERR_PTR(-EINVAL);
pdev = platform_device_alloc(pdev_name, pdev_id);
if (!pdev) {
ret = -ENOMEM;
goto odbs_exit;
}
if (pdev->id != -1)
dev_set_name(&pdev->dev, "%s.%d", pdev->name, pdev->id);
else
dev_set_name(&pdev->dev, "%s", pdev->name);
od = omap_device_alloc(pdev, ohs, oh_cnt);
if (IS_ERR(od))
goto odbs_exit1;
ret = platform_device_add_data(pdev, pdata, pdata_len);
if (ret)
goto odbs_exit2;
ret = omap_device_register(pdev);
if (ret)
goto odbs_exit2;
return pdev;
odbs_exit2:
omap_device_delete(od);
odbs_exit1:
platform_device_put(pdev);
odbs_exit:
pr_err("omap_device: %s: build failed (%d)\n", pdev_name, ret);
return ERR_PTR(ret);
}
static int _od_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
int ret;
ret = pm_generic_runtime_suspend(dev);
if (!ret)
omap_device_idle(pdev);
return ret;
}
static int _od_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
omap_device_enable(pdev);
return pm_generic_runtime_resume(dev);
}
static int _od_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_device *od = to_omap_device(pdev);
int ret;
if (od->_driver_status != BUS_NOTIFY_BOUND_DRIVER)
return 0;
ret = pm_generic_suspend_noirq(dev);
if (!ret && !pm_runtime_status_suspended(dev)) {
if (pm_generic_runtime_suspend(dev) == 0) {
omap_device_idle(pdev);
od->flags |= OMAP_DEVICE_SUSPENDED;
}
}
return ret;
}
static int _od_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_device *od = to_omap_device(pdev);
if ((od->flags & OMAP_DEVICE_SUSPENDED) &&
!pm_runtime_status_suspended(dev)) {
od->flags &= ~OMAP_DEVICE_SUSPENDED;
omap_device_enable(pdev);
pm_generic_runtime_resume(dev);
}
return pm_generic_resume_noirq(dev);
}
int omap_device_register(struct platform_device *pdev)
{
pr_debug("omap_device: %s: registering\n", pdev->name);
pdev->dev.pm_domain = &omap_device_pm_domain;
return platform_device_add(pdev);
}
int omap_device_enable(struct platform_device *pdev)
{
int ret;
struct omap_device *od;
od = to_omap_device(pdev);
if (od->_state == OMAP_DEVICE_STATE_ENABLED) {
dev_warn(&pdev->dev,
"omap_device: %s() called from invalid state %d\n",
__func__, od->_state);
return -EINVAL;
}
ret = _omap_device_enable_hwmods(od);
od->_state = OMAP_DEVICE_STATE_ENABLED;
return ret;
}
int omap_device_idle(struct platform_device *pdev)
{
int ret;
struct omap_device *od;
od = to_omap_device(pdev);
if (od->_state != OMAP_DEVICE_STATE_ENABLED) {
dev_warn(&pdev->dev,
"omap_device: %s() called from invalid state %d\n",
__func__, od->_state);
return -EINVAL;
}
ret = _omap_device_idle_hwmods(od);
od->_state = OMAP_DEVICE_STATE_IDLE;
return ret;
}
int omap_device_assert_hardreset(struct platform_device *pdev, const char *name)
{
struct omap_device *od = to_omap_device(pdev);
int ret = 0;
int i;
for (i = 0; i < od->hwmods_cnt; i++) {
ret = omap_hwmod_assert_hardreset(od->hwmods[i], name);
if (ret)
break;
}
return ret;
}
int omap_device_deassert_hardreset(struct platform_device *pdev,
const char *name)
{
struct omap_device *od = to_omap_device(pdev);
int ret = 0;
int i;
for (i = 0; i < od->hwmods_cnt; i++) {
ret = omap_hwmod_deassert_hardreset(od->hwmods[i], name);
if (ret)
break;
}
return ret;
}
struct device *omap_device_get_by_hwmod_name(const char *oh_name)
{
struct omap_hwmod *oh;
if (!oh_name) {
WARN(1, "%s: no hwmod name!\n", __func__);
return ERR_PTR(-EINVAL);
}
oh = omap_hwmod_lookup(oh_name);
if (!oh) {
WARN(1, "%s: no hwmod for %s\n", __func__,
oh_name);
return ERR_PTR(-ENODEV);
}
if (!oh->od) {
WARN(1, "%s: no omap_device for %s\n", __func__,
oh_name);
return ERR_PTR(-ENODEV);
}
return &oh->od->pdev->dev;
}
static int __init omap_device_init(void)
{
bus_register_notifier(&platform_bus_type, &platform_nb);
return 0;
}
static int __init omap_device_late_idle(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_device *od = to_omap_device(pdev);
int i;
if (!od)
return 0;
for (i = 0; i < od->hwmods_cnt; i++)
if (od->hwmods[i]->flags & HWMOD_INIT_NO_IDLE)
return 0;
if (od->_driver_status != BUS_NOTIFY_BOUND_DRIVER) {
if (od->_state == OMAP_DEVICE_STATE_ENABLED) {
dev_warn(dev, "%s: enabled but no driver. Idling\n",
__func__);
omap_device_idle(pdev);
}
}
return 0;
}
static int __init omap_device_late_init(void)
{
bus_for_each_dev(&platform_bus_type, NULL, NULL, omap_device_late_idle);
return 0;
}
