static int fpga_region_of_node_match(struct device *dev, const void *data)
{
return dev->of_node == data;
}
static struct fpga_region *fpga_region_find(struct device_node *np)
{
struct device *dev;
dev = class_find_device(fpga_region_class, NULL, np,
fpga_region_of_node_match);
if (!dev)
return NULL;
return to_fpga_region(dev);
}
static struct fpga_region *fpga_region_get(struct fpga_region *region)
{
struct device *dev = &region->dev;
if (!mutex_trylock(&region->mutex)) {
dev_dbg(dev, "%s: FPGA Region already in use\n", __func__);
return ERR_PTR(-EBUSY);
}
get_device(dev);
of_node_get(dev->of_node);
if (!try_module_get(dev->parent->driver->owner)) {
of_node_put(dev->of_node);
put_device(dev);
mutex_unlock(&region->mutex);
return ERR_PTR(-ENODEV);
}
dev_dbg(&region->dev, "get\n");
return region;
}
static void fpga_region_put(struct fpga_region *region)
{
struct device *dev = &region->dev;
dev_dbg(&region->dev, "put\n");
module_put(dev->parent->driver->owner);
of_node_put(dev->of_node);
put_device(dev);
mutex_unlock(&region->mutex);
}
static struct fpga_manager *fpga_region_get_manager(struct fpga_region *region)
{
struct device *dev = &region->dev;
struct device_node *np = dev->of_node;
struct device_node *mgr_node;
struct fpga_manager *mgr;
of_node_get(np);
while (np) {
if (of_device_is_compatible(np, "fpga-region")) {
mgr_node = of_parse_phandle(np, "fpga-mgr", 0);
if (mgr_node) {
mgr = of_fpga_mgr_get(mgr_node);
of_node_put(np);
return mgr;
}
}
np = of_get_next_parent(np);
}
of_node_put(np);
return ERR_PTR(-EINVAL);
}
static int fpga_region_get_bridges(struct fpga_region *region,
struct device_node *overlay)
{
struct device *dev = &region->dev;
struct device_node *region_np = dev->of_node;
struct device_node *br, *np, *parent_br = NULL;
int i, ret;
ret = fpga_bridge_get_to_list(region_np->parent, region->info,
&region->bridge_list);
if (ret == -EBUSY)
return ret;
if (!ret)
parent_br = region_np->parent;
if (of_parse_phandle(overlay, "fpga-bridges", 0))
np = overlay;
else
np = region_np;
for (i = 0; ; i++) {
br = of_parse_phandle(np, "fpga-bridges", i);
if (!br)
break;
if (br == parent_br)
continue;
ret = fpga_bridge_get_to_list(br, region->info,
&region->bridge_list);
if (ret == -EBUSY) {
fpga_bridges_put(&region->bridge_list);
return -EBUSY;
}
}
return 0;
}
static int fpga_region_program_fpga(struct fpga_region *region,
const char *firmware_name,
struct device_node *overlay)
{
struct fpga_manager *mgr;
int ret;
region = fpga_region_get(region);
if (IS_ERR(region)) {
pr_err("failed to get fpga region\n");
return PTR_ERR(region);
}
mgr = fpga_region_get_manager(region);
if (IS_ERR(mgr)) {
pr_err("failed to get fpga region manager\n");
return PTR_ERR(mgr);
}
ret = fpga_region_get_bridges(region, overlay);
if (ret) {
pr_err("failed to get fpga region bridges\n");
goto err_put_mgr;
}
ret = fpga_bridges_disable(&region->bridge_list);
if (ret) {
pr_err("failed to disable region bridges\n");
goto err_put_br;
}
ret = fpga_mgr_firmware_load(mgr, region->info, firmware_name);
if (ret) {
pr_err("failed to load fpga image\n");
goto err_put_br;
}
ret = fpga_bridges_enable(&region->bridge_list);
if (ret) {
pr_err("failed to enable region bridges\n");
goto err_put_br;
}
fpga_mgr_put(mgr);
fpga_region_put(region);
return 0;
err_put_br:
fpga_bridges_put(&region->bridge_list);
err_put_mgr:
fpga_mgr_put(mgr);
fpga_region_put(region);
return ret;
}
static int child_regions_with_firmware(struct device_node *overlay)
{
struct device_node *child_region;
const char *child_firmware_name;
int ret = 0;
of_node_get(overlay);
child_region = of_find_matching_node(overlay, fpga_region_of_match);
while (child_region) {
if (!of_property_read_string(child_region, "firmware-name",
&child_firmware_name)) {
ret = -EINVAL;
break;
}
child_region = of_find_matching_node(child_region,
fpga_region_of_match);
}
of_node_put(child_region);
if (ret)
pr_err("firmware-name not allowed in child FPGA region: %s",
child_region->full_name);
return ret;
}
static int fpga_region_notify_pre_apply(struct fpga_region *region,
struct of_overlay_notify_data *nd)
{
const char *firmware_name = NULL;
struct fpga_image_info *info;
int ret;
info = devm_kzalloc(&region->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
region->info = info;
ret = child_regions_with_firmware(nd->overlay);
if (ret)
return ret;
if (of_property_read_bool(nd->overlay, "partial-fpga-config"))
info->flags |= FPGA_MGR_PARTIAL_RECONFIG;
if (of_property_read_bool(nd->overlay, "external-fpga-config"))
info->flags |= FPGA_MGR_EXTERNAL_CONFIG;
of_property_read_string(nd->overlay, "firmware-name", &firmware_name);
of_property_read_u32(nd->overlay, "region-unfreeze-timeout-us",
&info->enable_timeout_us);
of_property_read_u32(nd->overlay, "region-freeze-timeout-us",
&info->disable_timeout_us);
if ((info->flags & FPGA_MGR_EXTERNAL_CONFIG) && firmware_name) {
pr_err("error: specified firmware and external-fpga-config");
return -EINVAL;
}
if (info->flags & FPGA_MGR_EXTERNAL_CONFIG)
return 0;
if (!firmware_name) {
pr_err("should specify firmware-name or external-fpga-config\n");
return -EINVAL;
}
return fpga_region_program_fpga(region, firmware_name, nd->overlay);
}
static void fpga_region_notify_post_remove(struct fpga_region *region,
struct of_overlay_notify_data *nd)
{
fpga_bridges_disable(&region->bridge_list);
fpga_bridges_put(&region->bridge_list);
devm_kfree(&region->dev, region->info);
region->info = NULL;
}
static int of_fpga_region_notify(struct notifier_block *nb,
unsigned long action, void *arg)
{
struct of_overlay_notify_data *nd = arg;
struct fpga_region *region;
int ret;
switch (action) {
case OF_OVERLAY_PRE_APPLY:
pr_debug("%s OF_OVERLAY_PRE_APPLY\n", __func__);
break;
case OF_OVERLAY_POST_APPLY:
pr_debug("%s OF_OVERLAY_POST_APPLY\n", __func__);
return NOTIFY_OK;
case OF_OVERLAY_PRE_REMOVE:
pr_debug("%s OF_OVERLAY_PRE_REMOVE\n", __func__);
return NOTIFY_OK;
case OF_OVERLAY_POST_REMOVE:
pr_debug("%s OF_OVERLAY_POST_REMOVE\n", __func__);
break;
default:
return NOTIFY_OK;
}
region = fpga_region_find(nd->target);
if (!region)
return NOTIFY_OK;
ret = 0;
switch (action) {
case OF_OVERLAY_PRE_APPLY:
ret = fpga_region_notify_pre_apply(region, nd);
break;
case OF_OVERLAY_POST_REMOVE:
fpga_region_notify_post_remove(region, nd);
break;
}
put_device(&region->dev);
if (ret)
return notifier_from_errno(ret);
return NOTIFY_OK;
}
static int fpga_region_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct fpga_region *region;
int id, ret = 0;
region = kzalloc(sizeof(*region), GFP_KERNEL);
if (!region)
return -ENOMEM;
id = ida_simple_get(&fpga_region_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
ret = id;
goto err_kfree;
}
mutex_init(&region->mutex);
INIT_LIST_HEAD(&region->bridge_list);
device_initialize(&region->dev);
region->dev.class = fpga_region_class;
region->dev.parent = dev;
region->dev.of_node = np;
region->dev.id = id;
dev_set_drvdata(dev, region);
ret = dev_set_name(&region->dev, "region%d", id);
if (ret)
goto err_remove;
ret = device_add(&region->dev);
if (ret)
goto err_remove;
of_platform_populate(np, fpga_region_of_match, NULL, &region->dev);
dev_info(dev, "FPGA Region probed\n");
return 0;
err_remove:
ida_simple_remove(&fpga_region_ida, id);
err_kfree:
kfree(region);
return ret;
}
static int fpga_region_remove(struct platform_device *pdev)
{
struct fpga_region *region = platform_get_drvdata(pdev);
device_unregister(&region->dev);
return 0;
}
static void fpga_region_dev_release(struct device *dev)
{
struct fpga_region *region = to_fpga_region(dev);
ida_simple_remove(&fpga_region_ida, region->dev.id);
kfree(region);
}
static int __init fpga_region_init(void)
{
int ret;
fpga_region_class = class_create(THIS_MODULE, "fpga_region");
if (IS_ERR(fpga_region_class))
return PTR_ERR(fpga_region_class);
fpga_region_class->dev_release = fpga_region_dev_release;
ret = of_overlay_notifier_register(&fpga_region_of_nb);
if (ret)
goto err_class;
ret = platform_driver_register(&fpga_region_driver);
if (ret)
goto err_plat;
return 0;
err_plat:
of_overlay_notifier_unregister(&fpga_region_of_nb);
err_class:
class_destroy(fpga_region_class);
ida_destroy(&fpga_region_ida);
return ret;
}
static void __exit fpga_region_exit(void)
{
platform_driver_unregister(&fpga_region_driver);
of_overlay_notifier_unregister(&fpga_region_of_nb);
class_destroy(fpga_region_class);
ida_destroy(&fpga_region_ida);
}
