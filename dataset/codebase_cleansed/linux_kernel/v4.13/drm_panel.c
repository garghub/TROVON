void drm_panel_init(struct drm_panel *panel)
{
INIT_LIST_HEAD(&panel->list);
}
int drm_panel_add(struct drm_panel *panel)
{
mutex_lock(&panel_lock);
list_add_tail(&panel->list, &panel_list);
mutex_unlock(&panel_lock);
return 0;
}
void drm_panel_remove(struct drm_panel *panel)
{
mutex_lock(&panel_lock);
list_del_init(&panel->list);
mutex_unlock(&panel_lock);
}
int drm_panel_attach(struct drm_panel *panel, struct drm_connector *connector)
{
if (panel->connector)
return -EBUSY;
panel->connector = connector;
panel->drm = connector->dev;
return 0;
}
int drm_panel_detach(struct drm_panel *panel)
{
panel->connector = NULL;
panel->drm = NULL;
return 0;
}
struct drm_panel *of_drm_find_panel(const struct device_node *np)
{
struct drm_panel *panel;
mutex_lock(&panel_lock);
list_for_each_entry(panel, &panel_list, list) {
if (panel->dev->of_node == np) {
mutex_unlock(&panel_lock);
return panel;
}
}
mutex_unlock(&panel_lock);
return NULL;
}
