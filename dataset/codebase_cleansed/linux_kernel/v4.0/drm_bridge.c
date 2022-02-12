int drm_bridge_add(struct drm_bridge *bridge)
{
mutex_lock(&bridge_lock);
list_add_tail(&bridge->list, &bridge_list);
mutex_unlock(&bridge_lock);
return 0;
}
void drm_bridge_remove(struct drm_bridge *bridge)
{
mutex_lock(&bridge_lock);
list_del_init(&bridge->list);
mutex_unlock(&bridge_lock);
}
extern int drm_bridge_attach(struct drm_device *dev, struct drm_bridge *bridge)
{
if (!dev || !bridge)
return -EINVAL;
if (bridge->dev)
return -EBUSY;
bridge->dev = dev;
if (bridge->funcs->attach)
return bridge->funcs->attach(bridge);
return 0;
}
struct drm_bridge *of_drm_find_bridge(struct device_node *np)
{
struct drm_bridge *bridge;
mutex_lock(&bridge_lock);
list_for_each_entry(bridge, &bridge_list, list) {
if (bridge->of_node == np) {
mutex_unlock(&bridge_lock);
return bridge;
}
}
mutex_unlock(&bridge_lock);
return NULL;
}
