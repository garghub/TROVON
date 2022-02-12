static enum drm_mode_status
drm_mode_validate_flag(const struct drm_display_mode *mode,
int flags)
{
if ((mode->flags & DRM_MODE_FLAG_INTERLACE) &&
!(flags & DRM_MODE_FLAG_INTERLACE))
return MODE_NO_INTERLACE;
if ((mode->flags & DRM_MODE_FLAG_DBLSCAN) &&
!(flags & DRM_MODE_FLAG_DBLSCAN))
return MODE_NO_DBLESCAN;
if ((mode->flags & DRM_MODE_FLAG_3D_MASK) &&
!(flags & DRM_MODE_FLAG_3D_MASK))
return MODE_NO_STEREO;
return MODE_OK;
}
static int drm_helper_probe_add_cmdline_mode(struct drm_connector *connector)
{
struct drm_cmdline_mode *cmdline_mode;
struct drm_display_mode *mode;
cmdline_mode = &connector->cmdline_mode;
if (!cmdline_mode->specified)
return 0;
list_for_each_entry(mode, &connector->probed_modes, head) {
if (mode->hdisplay != cmdline_mode->xres ||
mode->vdisplay != cmdline_mode->yres)
continue;
if (cmdline_mode->refresh_specified) {
if (drm_mode_vrefresh(mode) != cmdline_mode->refresh)
continue;
}
return 0;
}
mode = drm_mode_create_from_cmdline_mode(connector->dev,
cmdline_mode);
if (mode == NULL)
return 0;
drm_mode_probed_add(connector, mode);
return 1;
}
void drm_kms_helper_poll_enable_locked(struct drm_device *dev)
{
bool poll = false;
struct drm_connector *connector;
WARN_ON(!mutex_is_locked(&dev->mode_config.mutex));
if (!dev->mode_config.poll_enabled || !drm_kms_helper_poll)
return;
drm_for_each_connector(connector, dev) {
if (connector->polled & (DRM_CONNECTOR_POLL_CONNECT |
DRM_CONNECTOR_POLL_DISCONNECT))
poll = true;
}
if (poll)
schedule_delayed_work(&dev->mode_config.output_poll_work, DRM_OUTPUT_POLL_PERIOD);
}
int drm_helper_probe_single_connector_modes(struct drm_connector *connector,
uint32_t maxX, uint32_t maxY)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode;
const struct drm_connector_helper_funcs *connector_funcs =
connector->helper_private;
int count = 0;
int mode_flags = 0;
bool verbose_prune = true;
enum drm_connector_status old_status;
WARN_ON(!mutex_is_locked(&dev->mode_config.mutex));
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n", connector->base.id,
connector->name);
list_for_each_entry(mode, &connector->modes, head)
mode->status = MODE_STALE;
old_status = connector->status;
if (connector->force) {
if (connector->force == DRM_FORCE_ON ||
connector->force == DRM_FORCE_ON_DIGITAL)
connector->status = connector_status_connected;
else
connector->status = connector_status_disconnected;
if (connector->funcs->force)
connector->funcs->force(connector);
} else {
connector->status = connector->funcs->detect(connector, true);
}
if (old_status != connector->status) {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] status updated from %s to %s\n",
connector->base.id,
connector->name,
drm_get_connector_status_name(old_status),
drm_get_connector_status_name(connector->status));
dev->mode_config.delayed_event = true;
if (dev->mode_config.poll_enabled)
schedule_delayed_work(&dev->mode_config.output_poll_work,
0);
}
if (drm_kms_helper_poll != dev->mode_config.poll_running)
drm_kms_helper_poll_enable_locked(dev);
dev->mode_config.poll_running = drm_kms_helper_poll;
if (connector->status == connector_status_disconnected) {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] disconnected\n",
connector->base.id, connector->name);
drm_mode_connector_update_edid_property(connector, NULL);
verbose_prune = false;
goto prune;
}
if (connector->override_edid) {
struct edid *edid = (struct edid *) connector->edid_blob_ptr->data;
count = drm_add_edid_modes(connector, edid);
drm_edid_to_eld(connector, edid);
} else {
count = drm_load_edid_firmware(connector);
if (count == 0)
count = (*connector_funcs->get_modes)(connector);
}
if (count == 0 && connector->status == connector_status_connected)
count = drm_add_modes_noedid(connector, 1024, 768);
count += drm_helper_probe_add_cmdline_mode(connector);
if (count == 0)
goto prune;
drm_mode_connector_list_update(connector);
if (connector->interlace_allowed)
mode_flags |= DRM_MODE_FLAG_INTERLACE;
if (connector->doublescan_allowed)
mode_flags |= DRM_MODE_FLAG_DBLSCAN;
if (connector->stereo_allowed)
mode_flags |= DRM_MODE_FLAG_3D_MASK;
list_for_each_entry(mode, &connector->modes, head) {
if (mode->status == MODE_OK)
mode->status = drm_mode_validate_basic(mode);
if (mode->status == MODE_OK)
mode->status = drm_mode_validate_size(mode, maxX, maxY);
if (mode->status == MODE_OK)
mode->status = drm_mode_validate_flag(mode, mode_flags);
if (mode->status == MODE_OK && connector_funcs->mode_valid)
mode->status = connector_funcs->mode_valid(connector,
mode);
}
prune:
drm_mode_prune_invalid(dev, &connector->modes, verbose_prune);
if (list_empty(&connector->modes))
return 0;
list_for_each_entry(mode, &connector->modes, head)
mode->vrefresh = drm_mode_vrefresh(mode);
drm_mode_sort(&connector->modes);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] probed modes :\n", connector->base.id,
connector->name);
list_for_each_entry(mode, &connector->modes, head) {
drm_mode_set_crtcinfo(mode, CRTC_INTERLACE_HALVE_V);
drm_mode_debug_printmodeline(mode);
}
return count;
}
void drm_kms_helper_hotplug_event(struct drm_device *dev)
{
drm_sysfs_hotplug_event(dev);
if (dev->mode_config.funcs->output_poll_changed)
dev->mode_config.funcs->output_poll_changed(dev);
}
static void output_poll_execute(struct work_struct *work)
{
struct delayed_work *delayed_work = to_delayed_work(work);
struct drm_device *dev = container_of(delayed_work, struct drm_device, mode_config.output_poll_work);
struct drm_connector *connector;
enum drm_connector_status old_status;
bool repoll = false, changed;
changed = dev->mode_config.delayed_event;
dev->mode_config.delayed_event = false;
if (!drm_kms_helper_poll)
goto out;
mutex_lock(&dev->mode_config.mutex);
drm_for_each_connector(connector, dev) {
if (connector->force)
continue;
if (!connector->polled || connector->polled == DRM_CONNECTOR_POLL_HPD)
continue;
old_status = connector->status;
if (old_status == connector_status_connected &&
!(connector->polled & DRM_CONNECTOR_POLL_DISCONNECT))
continue;
repoll = true;
connector->status = connector->funcs->detect(connector, false);
if (old_status != connector->status) {
const char *old, *new;
if (connector->status == connector_status_unknown) {
connector->status = old_status;
continue;
}
old = drm_get_connector_status_name(old_status);
new = drm_get_connector_status_name(connector->status);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] "
"status updated from %s to %s\n",
connector->base.id,
connector->name,
old, new);
changed = true;
}
}
mutex_unlock(&dev->mode_config.mutex);
out:
if (changed)
drm_kms_helper_hotplug_event(dev);
if (repoll)
schedule_delayed_work(delayed_work, DRM_OUTPUT_POLL_PERIOD);
}
void drm_kms_helper_poll_disable(struct drm_device *dev)
{
if (!dev->mode_config.poll_enabled)
return;
cancel_delayed_work_sync(&dev->mode_config.output_poll_work);
}
void drm_kms_helper_poll_enable(struct drm_device *dev)
{
mutex_lock(&dev->mode_config.mutex);
drm_kms_helper_poll_enable_locked(dev);
mutex_unlock(&dev->mode_config.mutex);
}
void drm_kms_helper_poll_init(struct drm_device *dev)
{
INIT_DELAYED_WORK(&dev->mode_config.output_poll_work, output_poll_execute);
dev->mode_config.poll_enabled = true;
drm_kms_helper_poll_enable(dev);
}
void drm_kms_helper_poll_fini(struct drm_device *dev)
{
drm_kms_helper_poll_disable(dev);
}
bool drm_helper_hpd_irq_event(struct drm_device *dev)
{
struct drm_connector *connector;
enum drm_connector_status old_status;
bool changed = false;
if (!dev->mode_config.poll_enabled)
return false;
mutex_lock(&dev->mode_config.mutex);
drm_for_each_connector(connector, dev) {
if (!(connector->polled & DRM_CONNECTOR_POLL_HPD))
continue;
old_status = connector->status;
connector->status = connector->funcs->detect(connector, false);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] status updated from %s to %s\n",
connector->base.id,
connector->name,
drm_get_connector_status_name(old_status),
drm_get_connector_status_name(connector->status));
if (old_status != connector->status)
changed = true;
}
mutex_unlock(&dev->mode_config.mutex);
if (changed)
drm_kms_helper_hotplug_event(dev);
return changed;
}
