static void devm_phy_release(struct device *dev, void *res)
{
struct phy *phy = *(struct phy **)res;
phy_put(phy);
}
static void devm_phy_provider_release(struct device *dev, void *res)
{
struct phy_provider *phy_provider = *(struct phy_provider **)res;
of_phy_provider_unregister(phy_provider);
}
static void devm_phy_consume(struct device *dev, void *res)
{
struct phy *phy = *(struct phy **)res;
phy_destroy(phy);
}
static int devm_phy_match(struct device *dev, void *res, void *match_data)
{
return res == match_data;
}
static struct phy *phy_lookup(struct device *device, const char *port)
{
unsigned int count;
struct phy *phy;
struct device *dev;
struct phy_consumer *consumers;
struct class_dev_iter iter;
class_dev_iter_init(&iter, phy_class, NULL, NULL);
while ((dev = class_dev_iter_next(&iter))) {
phy = to_phy(dev);
count = phy->init_data->num_consumers;
consumers = phy->init_data->consumers;
while (count--) {
if (!strcmp(consumers->dev_name, dev_name(device)) &&
!strcmp(consumers->port, port)) {
class_dev_iter_exit(&iter);
return phy;
}
consumers++;
}
}
class_dev_iter_exit(&iter);
return ERR_PTR(-ENODEV);
}
static struct phy_provider *of_phy_provider_lookup(struct device_node *node)
{
struct phy_provider *phy_provider;
list_for_each_entry(phy_provider, &phy_provider_list, list) {
if (phy_provider->dev->of_node == node)
return phy_provider;
}
return ERR_PTR(-EPROBE_DEFER);
}
int phy_pm_runtime_get(struct phy *phy)
{
if (!pm_runtime_enabled(&phy->dev))
return -ENOTSUPP;
return pm_runtime_get(&phy->dev);
}
int phy_pm_runtime_get_sync(struct phy *phy)
{
if (!pm_runtime_enabled(&phy->dev))
return -ENOTSUPP;
return pm_runtime_get_sync(&phy->dev);
}
int phy_pm_runtime_put(struct phy *phy)
{
if (!pm_runtime_enabled(&phy->dev))
return -ENOTSUPP;
return pm_runtime_put(&phy->dev);
}
int phy_pm_runtime_put_sync(struct phy *phy)
{
if (!pm_runtime_enabled(&phy->dev))
return -ENOTSUPP;
return pm_runtime_put_sync(&phy->dev);
}
void phy_pm_runtime_allow(struct phy *phy)
{
if (!pm_runtime_enabled(&phy->dev))
return;
pm_runtime_allow(&phy->dev);
}
void phy_pm_runtime_forbid(struct phy *phy)
{
if (!pm_runtime_enabled(&phy->dev))
return;
pm_runtime_forbid(&phy->dev);
}
int phy_init(struct phy *phy)
{
int ret;
ret = phy_pm_runtime_get_sync(phy);
if (ret < 0 && ret != -ENOTSUPP)
return ret;
mutex_lock(&phy->mutex);
if (phy->init_count++ == 0 && phy->ops->init) {
ret = phy->ops->init(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy init failed --> %d\n", ret);
goto out;
}
}
out:
mutex_unlock(&phy->mutex);
phy_pm_runtime_put(phy);
return ret;
}
int phy_exit(struct phy *phy)
{
int ret;
ret = phy_pm_runtime_get_sync(phy);
if (ret < 0 && ret != -ENOTSUPP)
return ret;
mutex_lock(&phy->mutex);
if (--phy->init_count == 0 && phy->ops->exit) {
ret = phy->ops->exit(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy exit failed --> %d\n", ret);
goto out;
}
}
out:
mutex_unlock(&phy->mutex);
phy_pm_runtime_put(phy);
return ret;
}
int phy_power_on(struct phy *phy)
{
int ret = -ENOTSUPP;
ret = phy_pm_runtime_get_sync(phy);
if (ret < 0 && ret != -ENOTSUPP)
return ret;
mutex_lock(&phy->mutex);
if (phy->power_count++ == 0 && phy->ops->power_on) {
ret = phy->ops->power_on(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy poweron failed --> %d\n", ret);
goto out;
}
}
out:
mutex_unlock(&phy->mutex);
return ret;
}
int phy_power_off(struct phy *phy)
{
int ret = -ENOTSUPP;
mutex_lock(&phy->mutex);
if (--phy->power_count == 0 && phy->ops->power_off) {
ret = phy->ops->power_off(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy poweroff failed --> %d\n", ret);
goto out;
}
}
out:
mutex_unlock(&phy->mutex);
phy_pm_runtime_put(phy);
return ret;
}
static struct phy *of_phy_get(struct device *dev, int index)
{
int ret;
struct phy_provider *phy_provider;
struct phy *phy = NULL;
struct of_phandle_args args;
ret = of_parse_phandle_with_args(dev->of_node, "phys", "#phy-cells",
index, &args);
if (ret) {
dev_dbg(dev, "failed to get phy in %s node\n",
dev->of_node->full_name);
return ERR_PTR(-ENODEV);
}
mutex_lock(&phy_provider_mutex);
phy_provider = of_phy_provider_lookup(args.np);
if (IS_ERR(phy_provider) || !try_module_get(phy_provider->owner)) {
phy = ERR_PTR(-EPROBE_DEFER);
goto err0;
}
phy = phy_provider->of_xlate(phy_provider->dev, &args);
module_put(phy_provider->owner);
err0:
mutex_unlock(&phy_provider_mutex);
of_node_put(args.np);
return phy;
}
void phy_put(struct phy *phy)
{
if (IS_ERR(phy))
return;
module_put(phy->ops->owner);
put_device(&phy->dev);
}
void devm_phy_put(struct device *dev, struct phy *phy)
{
int r;
r = devres_destroy(dev, devm_phy_release, devm_phy_match, phy);
dev_WARN_ONCE(dev, r, "couldn't find PHY resource\n");
}
struct phy *of_phy_simple_xlate(struct device *dev, struct of_phandle_args
*args)
{
struct phy *phy;
struct class_dev_iter iter;
struct device_node *node = dev->of_node;
class_dev_iter_init(&iter, phy_class, NULL, NULL);
while ((dev = class_dev_iter_next(&iter))) {
phy = to_phy(dev);
if (node != phy->dev.of_node)
continue;
class_dev_iter_exit(&iter);
return phy;
}
class_dev_iter_exit(&iter);
return ERR_PTR(-ENODEV);
}
struct phy *phy_get(struct device *dev, const char *string)
{
int index = 0;
struct phy *phy = NULL;
if (string == NULL) {
dev_WARN(dev, "missing string\n");
return ERR_PTR(-EINVAL);
}
if (dev->of_node) {
index = of_property_match_string(dev->of_node, "phy-names",
string);
phy = of_phy_get(dev, index);
if (IS_ERR(phy)) {
dev_err(dev, "unable to find phy\n");
return phy;
}
} else {
phy = phy_lookup(dev, string);
if (IS_ERR(phy)) {
dev_err(dev, "unable to find phy\n");
return phy;
}
}
if (!try_module_get(phy->ops->owner))
return ERR_PTR(-EPROBE_DEFER);
get_device(&phy->dev);
return phy;
}
struct phy *devm_phy_get(struct device *dev, const char *string)
{
struct phy **ptr, *phy;
ptr = devres_alloc(devm_phy_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
phy = phy_get(dev, string);
if (!IS_ERR(phy)) {
*ptr = phy;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return phy;
}
struct phy *phy_create(struct device *dev, const struct phy_ops *ops,
struct phy_init_data *init_data)
{
int ret;
int id;
struct phy *phy;
if (WARN_ON(!dev))
return ERR_PTR(-EINVAL);
phy = kzalloc(sizeof(*phy), GFP_KERNEL);
if (!phy)
return ERR_PTR(-ENOMEM);
id = ida_simple_get(&phy_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
dev_err(dev, "unable to get id\n");
ret = id;
goto free_phy;
}
device_initialize(&phy->dev);
mutex_init(&phy->mutex);
phy->dev.class = phy_class;
phy->dev.parent = dev;
phy->dev.of_node = dev->of_node;
phy->id = id;
phy->ops = ops;
phy->init_data = init_data;
ret = dev_set_name(&phy->dev, "phy-%s.%d", dev_name(dev), id);
if (ret)
goto put_dev;
ret = device_add(&phy->dev);
if (ret)
goto put_dev;
if (pm_runtime_enabled(dev)) {
pm_runtime_enable(&phy->dev);
pm_runtime_no_callbacks(&phy->dev);
}
return phy;
put_dev:
put_device(&phy->dev);
ida_remove(&phy_ida, phy->id);
free_phy:
kfree(phy);
return ERR_PTR(ret);
}
struct phy *devm_phy_create(struct device *dev, const struct phy_ops *ops,
struct phy_init_data *init_data)
{
struct phy **ptr, *phy;
ptr = devres_alloc(devm_phy_consume, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
phy = phy_create(dev, ops, init_data);
if (!IS_ERR(phy)) {
*ptr = phy;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return phy;
}
void phy_destroy(struct phy *phy)
{
pm_runtime_disable(&phy->dev);
device_unregister(&phy->dev);
}
void devm_phy_destroy(struct device *dev, struct phy *phy)
{
int r;
r = devres_destroy(dev, devm_phy_consume, devm_phy_match, phy);
dev_WARN_ONCE(dev, r, "couldn't find PHY resource\n");
}
void of_phy_provider_unregister(struct phy_provider *phy_provider)
{
if (IS_ERR(phy_provider))
return;
mutex_lock(&phy_provider_mutex);
list_del(&phy_provider->list);
kfree(phy_provider);
mutex_unlock(&phy_provider_mutex);
}
void devm_of_phy_provider_unregister(struct device *dev,
struct phy_provider *phy_provider) {
int r;
r = devres_destroy(dev, devm_phy_provider_release, devm_phy_match,
phy_provider);
dev_WARN_ONCE(dev, r, "couldn't find PHY provider device resource\n");
}
static void phy_release(struct device *dev)
{
struct phy *phy;
phy = to_phy(dev);
dev_vdbg(dev, "releasing '%s'\n", dev_name(dev));
ida_remove(&phy_ida, phy->id);
kfree(phy);
}
static int __init phy_core_init(void)
{
phy_class = class_create(THIS_MODULE, "phy");
if (IS_ERR(phy_class)) {
pr_err("failed to create phy class --> %ld\n",
PTR_ERR(phy_class));
return PTR_ERR(phy_class);
}
phy_class->dev_release = phy_release;
return 0;
}
static void __exit phy_core_exit(void)
{
class_destroy(phy_class);
}
