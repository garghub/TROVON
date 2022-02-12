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
struct phy **phy = res;
return *phy == match_data;
}
int phy_create_lookup(struct phy *phy, const char *con_id, const char *dev_id)
{
struct phy_lookup *pl;
if (!phy || !dev_id || !con_id)
return -EINVAL;
pl = kzalloc(sizeof(*pl), GFP_KERNEL);
if (!pl)
return -ENOMEM;
pl->dev_id = dev_id;
pl->con_id = con_id;
pl->phy = phy;
mutex_lock(&phy_provider_mutex);
list_add_tail(&pl->node, &phys);
mutex_unlock(&phy_provider_mutex);
return 0;
}
void phy_remove_lookup(struct phy *phy, const char *con_id, const char *dev_id)
{
struct phy_lookup *pl;
if (!phy || !dev_id || !con_id)
return;
mutex_lock(&phy_provider_mutex);
list_for_each_entry(pl, &phys, node)
if (pl->phy == phy && !strcmp(pl->dev_id, dev_id) &&
!strcmp(pl->con_id, con_id)) {
list_del(&pl->node);
kfree(pl);
break;
}
mutex_unlock(&phy_provider_mutex);
}
static struct phy *phy_find(struct device *dev, const char *con_id)
{
const char *dev_id = dev_name(dev);
struct phy_lookup *p, *pl = NULL;
mutex_lock(&phy_provider_mutex);
list_for_each_entry(p, &phys, node)
if (!strcmp(p->dev_id, dev_id) && !strcmp(p->con_id, con_id)) {
pl = p;
break;
}
mutex_unlock(&phy_provider_mutex);
return pl ? pl->phy : ERR_PTR(-ENODEV);
}
static struct phy_provider *of_phy_provider_lookup(struct device_node *node)
{
struct phy_provider *phy_provider;
struct device_node *child;
list_for_each_entry(phy_provider, &phy_provider_list, list) {
if (phy_provider->dev->of_node == node)
return phy_provider;
for_each_child_of_node(phy_provider->dev->of_node, child)
if (child == node)
return phy_provider;
}
return ERR_PTR(-EPROBE_DEFER);
}
int phy_pm_runtime_get(struct phy *phy)
{
int ret;
if (!pm_runtime_enabled(&phy->dev))
return -ENOTSUPP;
ret = pm_runtime_get(&phy->dev);
if (ret < 0 && ret != -EINPROGRESS)
pm_runtime_put_noidle(&phy->dev);
return ret;
}
int phy_pm_runtime_get_sync(struct phy *phy)
{
int ret;
if (!pm_runtime_enabled(&phy->dev))
return -ENOTSUPP;
ret = pm_runtime_get_sync(&phy->dev);
if (ret < 0)
pm_runtime_put_sync(&phy->dev);
return ret;
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
if (!phy)
return 0;
ret = phy_pm_runtime_get_sync(phy);
if (ret < 0 && ret != -ENOTSUPP)
return ret;
ret = 0;
mutex_lock(&phy->mutex);
if (phy->init_count == 0 && phy->ops->init) {
ret = phy->ops->init(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy init failed --> %d\n", ret);
goto out;
}
}
++phy->init_count;
out:
mutex_unlock(&phy->mutex);
phy_pm_runtime_put(phy);
return ret;
}
int phy_exit(struct phy *phy)
{
int ret;
if (!phy)
return 0;
ret = phy_pm_runtime_get_sync(phy);
if (ret < 0 && ret != -ENOTSUPP)
return ret;
ret = 0;
mutex_lock(&phy->mutex);
if (phy->init_count == 1 && phy->ops->exit) {
ret = phy->ops->exit(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy exit failed --> %d\n", ret);
goto out;
}
}
--phy->init_count;
out:
mutex_unlock(&phy->mutex);
phy_pm_runtime_put(phy);
return ret;
}
int phy_power_on(struct phy *phy)
{
int ret;
if (!phy)
return 0;
if (phy->pwr) {
ret = regulator_enable(phy->pwr);
if (ret)
return ret;
}
ret = phy_pm_runtime_get_sync(phy);
if (ret < 0 && ret != -ENOTSUPP)
return ret;
ret = 0;
mutex_lock(&phy->mutex);
if (phy->power_count == 0 && phy->ops->power_on) {
ret = phy->ops->power_on(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy poweron failed --> %d\n", ret);
goto out;
}
}
++phy->power_count;
mutex_unlock(&phy->mutex);
return 0;
out:
mutex_unlock(&phy->mutex);
phy_pm_runtime_put_sync(phy);
if (phy->pwr)
regulator_disable(phy->pwr);
return ret;
}
int phy_power_off(struct phy *phy)
{
int ret;
if (!phy)
return 0;
mutex_lock(&phy->mutex);
if (phy->power_count == 1 && phy->ops->power_off) {
ret = phy->ops->power_off(phy);
if (ret < 0) {
dev_err(&phy->dev, "phy poweroff failed --> %d\n", ret);
mutex_unlock(&phy->mutex);
return ret;
}
}
--phy->power_count;
mutex_unlock(&phy->mutex);
phy_pm_runtime_put(phy);
if (phy->pwr)
regulator_disable(phy->pwr);
return 0;
}
static struct phy *_of_phy_get(struct device_node *np, int index)
{
int ret;
struct phy_provider *phy_provider;
struct phy *phy = NULL;
struct of_phandle_args args;
ret = of_parse_phandle_with_args(np, "phys", "#phy-cells",
index, &args);
if (ret)
return ERR_PTR(-ENODEV);
mutex_lock(&phy_provider_mutex);
phy_provider = of_phy_provider_lookup(args.np);
if (IS_ERR(phy_provider) || !try_module_get(phy_provider->owner)) {
phy = ERR_PTR(-EPROBE_DEFER);
goto out_unlock;
}
if (!of_device_is_available(args.np)) {
dev_warn(phy_provider->dev, "Requested PHY is disabled\n");
phy = ERR_PTR(-ENODEV);
goto out_put_module;
}
phy = phy_provider->of_xlate(phy_provider->dev, &args);
out_put_module:
module_put(phy_provider->owner);
out_unlock:
mutex_unlock(&phy_provider_mutex);
of_node_put(args.np);
return phy;
}
struct phy *of_phy_get(struct device_node *np, const char *con_id)
{
struct phy *phy = NULL;
int index = 0;
if (con_id)
index = of_property_match_string(np, "phy-names", con_id);
phy = _of_phy_get(np, index);
if (IS_ERR(phy))
return phy;
if (!try_module_get(phy->ops->owner))
return ERR_PTR(-EPROBE_DEFER);
get_device(&phy->dev);
return phy;
}
void phy_put(struct phy *phy)
{
if (!phy || IS_ERR(phy))
return;
module_put(phy->ops->owner);
put_device(&phy->dev);
}
void devm_phy_put(struct device *dev, struct phy *phy)
{
int r;
if (!phy)
return;
r = devres_destroy(dev, devm_phy_release, devm_phy_match, phy);
dev_WARN_ONCE(dev, r, "couldn't find PHY resource\n");
}
struct phy *of_phy_simple_xlate(struct device *dev, struct of_phandle_args
*args)
{
struct phy *phy;
struct class_dev_iter iter;
class_dev_iter_init(&iter, phy_class, NULL, NULL);
while ((dev = class_dev_iter_next(&iter))) {
phy = to_phy(dev);
if (args->np != phy->dev.of_node)
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
struct phy *phy;
if (string == NULL) {
dev_WARN(dev, "missing string\n");
return ERR_PTR(-EINVAL);
}
if (dev->of_node) {
index = of_property_match_string(dev->of_node, "phy-names",
string);
phy = _of_phy_get(dev->of_node, index);
} else {
phy = phy_find(dev, string);
}
if (IS_ERR(phy))
return phy;
if (!try_module_get(phy->ops->owner))
return ERR_PTR(-EPROBE_DEFER);
get_device(&phy->dev);
return phy;
}
struct phy *phy_optional_get(struct device *dev, const char *string)
{
struct phy *phy = phy_get(dev, string);
if (IS_ERR(phy) && (PTR_ERR(phy) == -ENODEV))
phy = NULL;
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
struct phy *devm_phy_optional_get(struct device *dev, const char *string)
{
struct phy *phy = devm_phy_get(dev, string);
if (IS_ERR(phy) && (PTR_ERR(phy) == -ENODEV))
phy = NULL;
return phy;
}
struct phy *devm_of_phy_get(struct device *dev, struct device_node *np,
const char *con_id)
{
struct phy **ptr, *phy;
ptr = devres_alloc(devm_phy_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
phy = of_phy_get(np, con_id);
if (!IS_ERR(phy)) {
*ptr = phy;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return phy;
}
struct phy *devm_of_phy_get_by_index(struct device *dev, struct device_node *np,
int index)
{
struct phy **ptr, *phy;
ptr = devres_alloc(devm_phy_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
phy = _of_phy_get(np, index);
if (IS_ERR(phy)) {
devres_free(ptr);
return phy;
}
if (!try_module_get(phy->ops->owner)) {
devres_free(ptr);
return ERR_PTR(-EPROBE_DEFER);
}
get_device(&phy->dev);
*ptr = phy;
devres_add(dev, ptr);
return phy;
}
struct phy *phy_create(struct device *dev, struct device_node *node,
const struct phy_ops *ops)
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
phy->dev.of_node = node ?: dev->of_node;
phy->id = id;
phy->ops = ops;
ret = dev_set_name(&phy->dev, "phy-%s.%d", dev_name(dev), id);
if (ret)
goto put_dev;
phy->pwr = regulator_get_optional(&phy->dev, "phy");
if (IS_ERR(phy->pwr)) {
ret = PTR_ERR(phy->pwr);
if (ret == -EPROBE_DEFER)
goto put_dev;
phy->pwr = NULL;
}
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
return ERR_PTR(ret);
free_phy:
kfree(phy);
return ERR_PTR(ret);
}
struct phy *devm_phy_create(struct device *dev, struct device_node *node,
const struct phy_ops *ops)
{
struct phy **ptr, *phy;
ptr = devres_alloc(devm_phy_consume, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
phy = phy_create(dev, node, ops);
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
regulator_put(phy->pwr);
ida_simple_remove(&phy_ida, phy->id);
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
