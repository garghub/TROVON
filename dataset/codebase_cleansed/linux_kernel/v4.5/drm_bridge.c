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
int drm_bridge_attach(struct drm_device *dev, struct drm_bridge *bridge)
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
bool drm_bridge_mode_fixup(struct drm_bridge *bridge,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
bool ret = true;
if (!bridge)
return true;
if (bridge->funcs->mode_fixup)
ret = bridge->funcs->mode_fixup(bridge, mode, adjusted_mode);
ret = ret && drm_bridge_mode_fixup(bridge->next, mode, adjusted_mode);
return ret;
}
void drm_bridge_disable(struct drm_bridge *bridge)
{
if (!bridge)
return;
drm_bridge_disable(bridge->next);
bridge->funcs->disable(bridge);
}
void drm_bridge_post_disable(struct drm_bridge *bridge)
{
if (!bridge)
return;
bridge->funcs->post_disable(bridge);
drm_bridge_post_disable(bridge->next);
}
void drm_bridge_mode_set(struct drm_bridge *bridge,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
if (!bridge)
return;
if (bridge->funcs->mode_set)
bridge->funcs->mode_set(bridge, mode, adjusted_mode);
drm_bridge_mode_set(bridge->next, mode, adjusted_mode);
}
void drm_bridge_pre_enable(struct drm_bridge *bridge)
{
if (!bridge)
return;
drm_bridge_pre_enable(bridge->next);
bridge->funcs->pre_enable(bridge);
}
void drm_bridge_enable(struct drm_bridge *bridge)
{
if (!bridge)
return;
bridge->funcs->enable(bridge);
drm_bridge_enable(bridge->next);
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
