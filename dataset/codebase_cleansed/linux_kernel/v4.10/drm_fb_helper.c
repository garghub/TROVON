int drm_fb_helper_single_add_all_connectors(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_connector *connector;
int i, ret;
if (!drm_fbdev_emulation)
return 0;
mutex_lock(&dev->mode_config.mutex);
drm_for_each_connector(connector, dev) {
ret = drm_fb_helper_add_one_connector(fb_helper, connector);
if (ret)
goto fail;
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
fail:
drm_fb_helper_for_each_connector(fb_helper, i) {
struct drm_fb_helper_connector *fb_helper_connector =
fb_helper->connector_info[i];
drm_connector_unreference(fb_helper_connector->connector);
kfree(fb_helper_connector);
fb_helper->connector_info[i] = NULL;
}
fb_helper->connector_count = 0;
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
int drm_fb_helper_add_one_connector(struct drm_fb_helper *fb_helper, struct drm_connector *connector)
{
struct drm_fb_helper_connector **temp;
struct drm_fb_helper_connector *fb_helper_connector;
if (!drm_fbdev_emulation)
return 0;
WARN_ON(!mutex_is_locked(&fb_helper->dev->mode_config.mutex));
if (fb_helper->connector_count + 1 > fb_helper->connector_info_alloc_count) {
temp = krealloc(fb_helper->connector_info, sizeof(struct drm_fb_helper_connector *) * (fb_helper->connector_count + 1), GFP_KERNEL);
if (!temp)
return -ENOMEM;
fb_helper->connector_info_alloc_count = fb_helper->connector_count + 1;
fb_helper->connector_info = temp;
}
fb_helper_connector = kzalloc(sizeof(struct drm_fb_helper_connector), GFP_KERNEL);
if (!fb_helper_connector)
return -ENOMEM;
drm_connector_reference(connector);
fb_helper_connector->connector = connector;
fb_helper->connector_info[fb_helper->connector_count++] = fb_helper_connector;
return 0;
}
int drm_fb_helper_remove_one_connector(struct drm_fb_helper *fb_helper,
struct drm_connector *connector)
{
struct drm_fb_helper_connector *fb_helper_connector;
int i, j;
if (!drm_fbdev_emulation)
return 0;
WARN_ON(!mutex_is_locked(&fb_helper->dev->mode_config.mutex));
for (i = 0; i < fb_helper->connector_count; i++) {
if (fb_helper->connector_info[i]->connector == connector)
break;
}
if (i == fb_helper->connector_count)
return -EINVAL;
fb_helper_connector = fb_helper->connector_info[i];
drm_connector_unreference(fb_helper_connector->connector);
for (j = i + 1; j < fb_helper->connector_count; j++) {
fb_helper->connector_info[j - 1] = fb_helper->connector_info[j];
}
fb_helper->connector_count--;
kfree(fb_helper_connector);
return 0;
}
static void drm_fb_helper_save_lut_atomic(struct drm_crtc *crtc, struct drm_fb_helper *helper)
{
uint16_t *r_base, *g_base, *b_base;
int i;
if (helper->funcs->gamma_get == NULL)
return;
r_base = crtc->gamma_store;
g_base = r_base + crtc->gamma_size;
b_base = g_base + crtc->gamma_size;
for (i = 0; i < crtc->gamma_size; i++)
helper->funcs->gamma_get(crtc, &r_base[i], &g_base[i], &b_base[i], i);
}
static void drm_fb_helper_restore_lut_atomic(struct drm_crtc *crtc)
{
uint16_t *r_base, *g_base, *b_base;
if (crtc->funcs->gamma_set == NULL)
return;
r_base = crtc->gamma_store;
g_base = r_base + crtc->gamma_size;
b_base = g_base + crtc->gamma_size;
crtc->funcs->gamma_set(crtc, r_base, g_base, b_base, crtc->gamma_size);
}
int drm_fb_helper_debug_enter(struct fb_info *info)
{
struct drm_fb_helper *helper = info->par;
const struct drm_crtc_helper_funcs *funcs;
int i;
list_for_each_entry(helper, &kernel_fb_helper_list, kernel_fb_list) {
for (i = 0; i < helper->crtc_count; i++) {
struct drm_mode_set *mode_set =
&helper->crtc_info[i].mode_set;
if (!mode_set->crtc->enabled)
continue;
funcs = mode_set->crtc->helper_private;
if (funcs->mode_set_base_atomic == NULL)
continue;
drm_fb_helper_save_lut_atomic(mode_set->crtc, helper);
funcs->mode_set_base_atomic(mode_set->crtc,
mode_set->fb,
mode_set->x,
mode_set->y,
ENTER_ATOMIC_MODE_SET);
}
}
return 0;
}
static struct drm_framebuffer *drm_mode_config_fb(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_crtc *c;
drm_for_each_crtc(c, dev) {
if (crtc->base.id == c->base.id)
return c->primary->fb;
}
return NULL;
}
int drm_fb_helper_debug_leave(struct fb_info *info)
{
struct drm_fb_helper *helper = info->par;
struct drm_crtc *crtc;
const struct drm_crtc_helper_funcs *funcs;
struct drm_framebuffer *fb;
int i;
for (i = 0; i < helper->crtc_count; i++) {
struct drm_mode_set *mode_set = &helper->crtc_info[i].mode_set;
crtc = mode_set->crtc;
funcs = crtc->helper_private;
fb = drm_mode_config_fb(crtc);
if (!crtc->enabled)
continue;
if (!fb) {
DRM_ERROR("no fb to restore??\n");
continue;
}
if (funcs->mode_set_base_atomic == NULL)
continue;
drm_fb_helper_restore_lut_atomic(mode_set->crtc);
funcs->mode_set_base_atomic(mode_set->crtc, fb, crtc->x,
crtc->y, LEAVE_ATOMIC_MODE_SET);
}
return 0;
}
static int restore_fbdev_mode_atomic(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_plane *plane;
struct drm_atomic_state *state;
int i, ret;
unsigned plane_mask;
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = dev->mode_config.acquire_ctx;
retry:
plane_mask = 0;
drm_for_each_plane(plane, dev) {
struct drm_plane_state *plane_state;
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto fail;
}
plane_state->rotation = DRM_ROTATE_0;
plane->old_fb = plane->fb;
plane_mask |= 1 << drm_plane_index(plane);
if (plane->type == DRM_PLANE_TYPE_PRIMARY)
continue;
ret = __drm_atomic_helper_disable_plane(plane, plane_state);
if (ret != 0)
goto fail;
}
for(i = 0; i < fb_helper->crtc_count; i++) {
struct drm_mode_set *mode_set = &fb_helper->crtc_info[i].mode_set;
ret = __drm_atomic_helper_set_config(mode_set, state);
if (ret != 0)
goto fail;
}
ret = drm_atomic_commit(state);
fail:
drm_atomic_clean_old_fb(dev, plane_mask, ret);
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
static int restore_fbdev_mode(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_plane *plane;
int i;
drm_warn_on_modeset_not_all_locked(dev);
if (dev->mode_config.funcs->atomic_commit)
return restore_fbdev_mode_atomic(fb_helper);
drm_for_each_plane(plane, dev) {
if (plane->type != DRM_PLANE_TYPE_PRIMARY)
drm_plane_force_disable(plane);
if (plane->rotation_property)
drm_mode_plane_set_obj_prop(plane,
plane->rotation_property,
DRM_ROTATE_0);
}
for (i = 0; i < fb_helper->crtc_count; i++) {
struct drm_mode_set *mode_set = &fb_helper->crtc_info[i].mode_set;
struct drm_crtc *crtc = mode_set->crtc;
int ret;
if (crtc->funcs->cursor_set2) {
ret = crtc->funcs->cursor_set2(crtc, NULL, 0, 0, 0, 0, 0);
if (ret)
return ret;
} else if (crtc->funcs->cursor_set) {
ret = crtc->funcs->cursor_set(crtc, NULL, 0, 0, 0);
if (ret)
return ret;
}
ret = drm_mode_set_config_internal(mode_set);
if (ret)
return ret;
}
return 0;
}
int drm_fb_helper_restore_fbdev_mode_unlocked(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
bool do_delayed;
int ret;
if (!drm_fbdev_emulation)
return -ENODEV;
drm_modeset_lock_all(dev);
ret = restore_fbdev_mode(fb_helper);
do_delayed = fb_helper->delayed_hotplug;
if (do_delayed)
fb_helper->delayed_hotplug = false;
drm_modeset_unlock_all(dev);
if (do_delayed)
drm_fb_helper_hotplug_event(fb_helper);
return ret;
}
static bool drm_fb_helper_is_bound(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_crtc *crtc;
int bound = 0, crtcs_bound = 0;
if (READ_ONCE(dev->master))
return false;
drm_for_each_crtc(crtc, dev) {
if (crtc->primary->fb)
crtcs_bound++;
if (crtc->primary->fb == fb_helper->fb)
bound++;
}
if (bound < crtcs_bound)
return false;
return true;
}
static bool drm_fb_helper_force_kernel_mode(void)
{
bool ret, error = false;
struct drm_fb_helper *helper;
if (list_empty(&kernel_fb_helper_list))
return false;
list_for_each_entry(helper, &kernel_fb_helper_list, kernel_fb_list) {
struct drm_device *dev = helper->dev;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
continue;
drm_modeset_lock_all(dev);
ret = restore_fbdev_mode(helper);
if (ret)
error = true;
drm_modeset_unlock_all(dev);
}
return error;
}
static void drm_fb_helper_restore_work_fn(struct work_struct *ignored)
{
bool ret;
ret = drm_fb_helper_force_kernel_mode();
if (ret == true)
DRM_ERROR("Failed to restore crtc configuration\n");
}
static void drm_fb_helper_sysrq(int dummy1)
{
schedule_work(&drm_fb_helper_restore_work);
}
static void drm_fb_helper_dpms(struct fb_info *info, int dpms_mode)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_device *dev = fb_helper->dev;
struct drm_crtc *crtc;
struct drm_connector *connector;
int i, j;
drm_modeset_lock_all(dev);
if (!drm_fb_helper_is_bound(fb_helper)) {
drm_modeset_unlock_all(dev);
return;
}
for (i = 0; i < fb_helper->crtc_count; i++) {
crtc = fb_helper->crtc_info[i].mode_set.crtc;
if (!crtc->enabled)
continue;
drm_fb_helper_for_each_connector(fb_helper, j) {
connector = fb_helper->connector_info[j]->connector;
connector->funcs->dpms(connector, dpms_mode);
drm_object_property_set_value(&connector->base,
dev->mode_config.dpms_property, dpms_mode);
}
}
drm_modeset_unlock_all(dev);
}
int drm_fb_helper_blank(int blank, struct fb_info *info)
{
if (oops_in_progress)
return -EBUSY;
switch (blank) {
case FB_BLANK_UNBLANK:
drm_fb_helper_dpms(info, DRM_MODE_DPMS_ON);
break;
case FB_BLANK_NORMAL:
drm_fb_helper_dpms(info, DRM_MODE_DPMS_STANDBY);
break;
case FB_BLANK_HSYNC_SUSPEND:
drm_fb_helper_dpms(info, DRM_MODE_DPMS_STANDBY);
break;
case FB_BLANK_VSYNC_SUSPEND:
drm_fb_helper_dpms(info, DRM_MODE_DPMS_SUSPEND);
break;
case FB_BLANK_POWERDOWN:
drm_fb_helper_dpms(info, DRM_MODE_DPMS_OFF);
break;
}
return 0;
}
static void drm_fb_helper_modeset_release(struct drm_fb_helper *helper,
struct drm_mode_set *modeset)
{
int i;
for (i = 0; i < modeset->num_connectors; i++) {
drm_connector_unreference(modeset->connectors[i]);
modeset->connectors[i] = NULL;
}
modeset->num_connectors = 0;
drm_mode_destroy(helper->dev, modeset->mode);
modeset->mode = NULL;
modeset->fb = NULL;
}
static void drm_fb_helper_crtc_free(struct drm_fb_helper *helper)
{
int i;
for (i = 0; i < helper->connector_count; i++) {
drm_connector_unreference(helper->connector_info[i]->connector);
kfree(helper->connector_info[i]);
}
kfree(helper->connector_info);
for (i = 0; i < helper->crtc_count; i++) {
struct drm_mode_set *modeset = &helper->crtc_info[i].mode_set;
drm_fb_helper_modeset_release(helper, modeset);
kfree(modeset->connectors);
}
kfree(helper->crtc_info);
}
static void drm_fb_helper_resume_worker(struct work_struct *work)
{
struct drm_fb_helper *helper = container_of(work, struct drm_fb_helper,
resume_work);
console_lock();
fb_set_suspend(helper->fbdev, 0);
console_unlock();
}
static void drm_fb_helper_dirty_work(struct work_struct *work)
{
struct drm_fb_helper *helper = container_of(work, struct drm_fb_helper,
dirty_work);
struct drm_clip_rect *clip = &helper->dirty_clip;
struct drm_clip_rect clip_copy;
unsigned long flags;
spin_lock_irqsave(&helper->dirty_lock, flags);
clip_copy = *clip;
clip->x1 = clip->y1 = ~0;
clip->x2 = clip->y2 = 0;
spin_unlock_irqrestore(&helper->dirty_lock, flags);
if (clip_copy.x1 < clip_copy.x2 && clip_copy.y1 < clip_copy.y2)
helper->fb->funcs->dirty(helper->fb, NULL, 0, 0, &clip_copy, 1);
}
void drm_fb_helper_prepare(struct drm_device *dev, struct drm_fb_helper *helper,
const struct drm_fb_helper_funcs *funcs)
{
INIT_LIST_HEAD(&helper->kernel_fb_list);
spin_lock_init(&helper->dirty_lock);
INIT_WORK(&helper->resume_work, drm_fb_helper_resume_worker);
INIT_WORK(&helper->dirty_work, drm_fb_helper_dirty_work);
helper->dirty_clip.x1 = helper->dirty_clip.y1 = ~0;
helper->funcs = funcs;
helper->dev = dev;
}
int drm_fb_helper_init(struct drm_device *dev,
struct drm_fb_helper *fb_helper,
int crtc_count, int max_conn_count)
{
struct drm_crtc *crtc;
int i;
if (!drm_fbdev_emulation)
return 0;
if (!max_conn_count)
return -EINVAL;
fb_helper->crtc_info = kcalloc(crtc_count, sizeof(struct drm_fb_helper_crtc), GFP_KERNEL);
if (!fb_helper->crtc_info)
return -ENOMEM;
fb_helper->crtc_count = crtc_count;
fb_helper->connector_info = kcalloc(dev->mode_config.num_connector, sizeof(struct drm_fb_helper_connector *), GFP_KERNEL);
if (!fb_helper->connector_info) {
kfree(fb_helper->crtc_info);
return -ENOMEM;
}
fb_helper->connector_info_alloc_count = dev->mode_config.num_connector;
fb_helper->connector_count = 0;
for (i = 0; i < crtc_count; i++) {
fb_helper->crtc_info[i].mode_set.connectors =
kcalloc(max_conn_count,
sizeof(struct drm_connector *),
GFP_KERNEL);
if (!fb_helper->crtc_info[i].mode_set.connectors)
goto out_free;
fb_helper->crtc_info[i].mode_set.num_connectors = 0;
}
i = 0;
drm_for_each_crtc(crtc, dev) {
fb_helper->crtc_info[i].mode_set.crtc = crtc;
i++;
}
return 0;
out_free:
drm_fb_helper_crtc_free(fb_helper);
return -ENOMEM;
}
struct fb_info *drm_fb_helper_alloc_fbi(struct drm_fb_helper *fb_helper)
{
struct device *dev = fb_helper->dev->dev;
struct fb_info *info;
int ret;
info = framebuffer_alloc(0, dev);
if (!info)
return ERR_PTR(-ENOMEM);
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret)
goto err_release;
info->apertures = alloc_apertures(1);
if (!info->apertures) {
ret = -ENOMEM;
goto err_free_cmap;
}
fb_helper->fbdev = info;
return info;
err_free_cmap:
fb_dealloc_cmap(&info->cmap);
err_release:
framebuffer_release(info);
return ERR_PTR(ret);
}
void drm_fb_helper_unregister_fbi(struct drm_fb_helper *fb_helper)
{
if (fb_helper && fb_helper->fbdev)
unregister_framebuffer(fb_helper->fbdev);
}
void drm_fb_helper_release_fbi(struct drm_fb_helper *fb_helper)
{
if (fb_helper) {
struct fb_info *info = fb_helper->fbdev;
if (info) {
if (info->cmap.len)
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
fb_helper->fbdev = NULL;
}
}
void drm_fb_helper_fini(struct drm_fb_helper *fb_helper)
{
if (!drm_fbdev_emulation)
return;
mutex_lock(&kernel_fb_helper_lock);
if (!list_empty(&fb_helper->kernel_fb_list)) {
list_del(&fb_helper->kernel_fb_list);
if (list_empty(&kernel_fb_helper_list)) {
unregister_sysrq_key('v', &sysrq_drm_fb_helper_restore_op);
}
}
mutex_unlock(&kernel_fb_helper_lock);
drm_fb_helper_crtc_free(fb_helper);
}
void drm_fb_helper_unlink_fbi(struct drm_fb_helper *fb_helper)
{
if (fb_helper && fb_helper->fbdev)
unlink_framebuffer(fb_helper->fbdev);
}
static void drm_fb_helper_dirty(struct fb_info *info, u32 x, u32 y,
u32 width, u32 height)
{
struct drm_fb_helper *helper = info->par;
struct drm_clip_rect *clip = &helper->dirty_clip;
unsigned long flags;
if (!helper->fb->funcs->dirty)
return;
spin_lock_irqsave(&helper->dirty_lock, flags);
clip->x1 = min_t(u32, clip->x1, x);
clip->y1 = min_t(u32, clip->y1, y);
clip->x2 = max_t(u32, clip->x2, x + width);
clip->y2 = max_t(u32, clip->y2, y + height);
spin_unlock_irqrestore(&helper->dirty_lock, flags);
schedule_work(&helper->dirty_work);
}
void drm_fb_helper_deferred_io(struct fb_info *info,
struct list_head *pagelist)
{
unsigned long start, end, min, max;
struct page *page;
u32 y1, y2;
min = ULONG_MAX;
max = 0;
list_for_each_entry(page, pagelist, lru) {
start = page->index << PAGE_SHIFT;
end = start + PAGE_SIZE - 1;
min = min(min, start);
max = max(max, end);
}
if (min < max) {
y1 = min / info->fix.line_length;
y2 = min_t(u32, DIV_ROUND_UP(max, info->fix.line_length),
info->var.yres);
drm_fb_helper_dirty(info, 0, y1, info->var.xres, y2 - y1);
}
}
ssize_t drm_fb_helper_sys_read(struct fb_info *info, char __user *buf,
size_t count, loff_t *ppos)
{
return fb_sys_read(info, buf, count, ppos);
}
ssize_t drm_fb_helper_sys_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
ssize_t ret;
ret = fb_sys_write(info, buf, count, ppos);
if (ret > 0)
drm_fb_helper_dirty(info, 0, 0, info->var.xres,
info->var.yres);
return ret;
}
void drm_fb_helper_sys_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
sys_fillrect(info, rect);
drm_fb_helper_dirty(info, rect->dx, rect->dy,
rect->width, rect->height);
}
void drm_fb_helper_sys_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
sys_copyarea(info, area);
drm_fb_helper_dirty(info, area->dx, area->dy,
area->width, area->height);
}
void drm_fb_helper_sys_imageblit(struct fb_info *info,
const struct fb_image *image)
{
sys_imageblit(info, image);
drm_fb_helper_dirty(info, image->dx, image->dy,
image->width, image->height);
}
void drm_fb_helper_cfb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
cfb_fillrect(info, rect);
drm_fb_helper_dirty(info, rect->dx, rect->dy,
rect->width, rect->height);
}
void drm_fb_helper_cfb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
cfb_copyarea(info, area);
drm_fb_helper_dirty(info, area->dx, area->dy,
area->width, area->height);
}
void drm_fb_helper_cfb_imageblit(struct fb_info *info,
const struct fb_image *image)
{
cfb_imageblit(info, image);
drm_fb_helper_dirty(info, image->dx, image->dy,
image->width, image->height);
}
void drm_fb_helper_set_suspend(struct drm_fb_helper *fb_helper, bool suspend)
{
if (fb_helper && fb_helper->fbdev)
fb_set_suspend(fb_helper->fbdev, suspend);
}
void drm_fb_helper_set_suspend_unlocked(struct drm_fb_helper *fb_helper,
bool suspend)
{
if (!fb_helper || !fb_helper->fbdev)
return;
flush_work(&fb_helper->resume_work);
if (suspend) {
if (fb_helper->fbdev->state != FBINFO_STATE_RUNNING)
return;
console_lock();
} else {
if (fb_helper->fbdev->state == FBINFO_STATE_RUNNING)
return;
if (!console_trylock()) {
schedule_work(&fb_helper->resume_work);
return;
}
}
fb_set_suspend(fb_helper->fbdev, suspend);
console_unlock();
}
static int setcolreg(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, u16 regno, struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_framebuffer *fb = fb_helper->fb;
if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
u32 *palette;
u32 value;
if (regno > 16)
return -EINVAL;
palette = (u32 *)info->pseudo_palette;
red >>= (16 - info->var.red.length);
green >>= (16 - info->var.green.length);
blue >>= (16 - info->var.blue.length);
value = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset);
if (info->var.transp.length > 0) {
u32 mask = (1 << info->var.transp.length) - 1;
mask <<= info->var.transp.offset;
value |= mask;
}
palette[regno] = value;
return 0;
}
if (WARN_ON(!fb_helper->funcs->gamma_set ||
!fb_helper->funcs->gamma_get))
return -EINVAL;
WARN_ON(fb->bits_per_pixel != 8);
fb_helper->funcs->gamma_set(crtc, red, green, blue, regno);
return 0;
}
int drm_fb_helper_setcmap(struct fb_cmap *cmap, struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_device *dev = fb_helper->dev;
const struct drm_crtc_helper_funcs *crtc_funcs;
u16 *red, *green, *blue, *transp;
struct drm_crtc *crtc;
int i, j, rc = 0;
int start;
if (oops_in_progress)
return -EBUSY;
drm_modeset_lock_all(dev);
if (!drm_fb_helper_is_bound(fb_helper)) {
drm_modeset_unlock_all(dev);
return -EBUSY;
}
for (i = 0; i < fb_helper->crtc_count; i++) {
crtc = fb_helper->crtc_info[i].mode_set.crtc;
crtc_funcs = crtc->helper_private;
red = cmap->red;
green = cmap->green;
blue = cmap->blue;
transp = cmap->transp;
start = cmap->start;
for (j = 0; j < cmap->len; j++) {
u16 hred, hgreen, hblue, htransp = 0xffff;
hred = *red++;
hgreen = *green++;
hblue = *blue++;
if (transp)
htransp = *transp++;
rc = setcolreg(crtc, hred, hgreen, hblue, start++, info);
if (rc)
goto out;
}
if (crtc_funcs->load_lut)
crtc_funcs->load_lut(crtc);
}
out:
drm_modeset_unlock_all(dev);
return rc;
}
int drm_fb_helper_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_framebuffer *fb = fb_helper->fb;
int depth;
if (var->pixclock != 0 || in_dbg_master())
return -EINVAL;
if (var->bits_per_pixel != fb->bits_per_pixel ||
var->xres != fb->width || var->yres != fb->height ||
var->xres_virtual != fb->width || var->yres_virtual != fb->height) {
DRM_DEBUG("fb userspace requested width/height/bpp different than current fb "
"request %dx%d-%d (virtual %dx%d) > %dx%d-%d\n",
var->xres, var->yres, var->bits_per_pixel,
var->xres_virtual, var->yres_virtual,
fb->width, fb->height, fb->bits_per_pixel);
return -EINVAL;
}
switch (var->bits_per_pixel) {
case 16:
depth = (var->green.length == 6) ? 16 : 15;
break;
case 32:
depth = (var->transp.length > 0) ? 32 : 24;
break;
default:
depth = var->bits_per_pixel;
break;
}
switch (depth) {
case 8:
var->red.offset = 0;
var->green.offset = 0;
var->blue.offset = 0;
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
var->transp.length = 0;
var->transp.offset = 0;
break;
case 15:
var->red.offset = 10;
var->green.offset = 5;
var->blue.offset = 0;
var->red.length = 5;
var->green.length = 5;
var->blue.length = 5;
var->transp.length = 1;
var->transp.offset = 15;
break;
case 16:
var->red.offset = 11;
var->green.offset = 5;
var->blue.offset = 0;
var->red.length = 5;
var->green.length = 6;
var->blue.length = 5;
var->transp.length = 0;
var->transp.offset = 0;
break;
case 24:
var->red.offset = 16;
var->green.offset = 8;
var->blue.offset = 0;
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
var->transp.length = 0;
var->transp.offset = 0;
break;
case 32:
var->red.offset = 16;
var->green.offset = 8;
var->blue.offset = 0;
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
var->transp.length = 8;
var->transp.offset = 24;
break;
default:
return -EINVAL;
}
return 0;
}
int drm_fb_helper_set_par(struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct fb_var_screeninfo *var = &info->var;
if (oops_in_progress)
return -EBUSY;
if (var->pixclock != 0) {
DRM_ERROR("PIXEL CLOCK SET\n");
return -EINVAL;
}
drm_fb_helper_restore_fbdev_mode_unlocked(fb_helper);
return 0;
}
static int pan_display_atomic(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_device *dev = fb_helper->dev;
struct drm_atomic_state *state;
struct drm_plane *plane;
int i, ret;
unsigned plane_mask;
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = dev->mode_config.acquire_ctx;
retry:
plane_mask = 0;
for(i = 0; i < fb_helper->crtc_count; i++) {
struct drm_mode_set *mode_set;
mode_set = &fb_helper->crtc_info[i].mode_set;
mode_set->x = var->xoffset;
mode_set->y = var->yoffset;
ret = __drm_atomic_helper_set_config(mode_set, state);
if (ret != 0)
goto fail;
plane = mode_set->crtc->primary;
plane_mask |= (1 << drm_plane_index(plane));
plane->old_fb = plane->fb;
}
ret = drm_atomic_commit(state);
if (ret != 0)
goto fail;
info->var.xoffset = var->xoffset;
info->var.yoffset = var->yoffset;
fail:
drm_atomic_clean_old_fb(dev, plane_mask, ret);
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
int drm_fb_helper_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_device *dev = fb_helper->dev;
struct drm_mode_set *modeset;
int ret = 0;
int i;
if (oops_in_progress)
return -EBUSY;
drm_modeset_lock_all(dev);
if (!drm_fb_helper_is_bound(fb_helper)) {
drm_modeset_unlock_all(dev);
return -EBUSY;
}
if (dev->mode_config.funcs->atomic_commit) {
ret = pan_display_atomic(var, info);
goto unlock;
}
for (i = 0; i < fb_helper->crtc_count; i++) {
modeset = &fb_helper->crtc_info[i].mode_set;
modeset->x = var->xoffset;
modeset->y = var->yoffset;
if (modeset->num_connectors) {
ret = drm_mode_set_config_internal(modeset);
if (!ret) {
info->var.xoffset = var->xoffset;
info->var.yoffset = var->yoffset;
}
}
}
unlock:
drm_modeset_unlock_all(dev);
return ret;
}
static int drm_fb_helper_single_fb_probe(struct drm_fb_helper *fb_helper,
int preferred_bpp)
{
int ret = 0;
int crtc_count = 0;
int i;
struct drm_fb_helper_surface_size sizes;
int gamma_size = 0;
memset(&sizes, 0, sizeof(struct drm_fb_helper_surface_size));
sizes.surface_depth = 24;
sizes.surface_bpp = 32;
sizes.fb_width = (unsigned)-1;
sizes.fb_height = (unsigned)-1;
if (preferred_bpp != sizes.surface_bpp)
sizes.surface_depth = sizes.surface_bpp = preferred_bpp;
drm_fb_helper_for_each_connector(fb_helper, i) {
struct drm_fb_helper_connector *fb_helper_conn = fb_helper->connector_info[i];
struct drm_cmdline_mode *cmdline_mode;
cmdline_mode = &fb_helper_conn->connector->cmdline_mode;
if (cmdline_mode->bpp_specified) {
switch (cmdline_mode->bpp) {
case 8:
sizes.surface_depth = sizes.surface_bpp = 8;
break;
case 15:
sizes.surface_depth = 15;
sizes.surface_bpp = 16;
break;
case 16:
sizes.surface_depth = sizes.surface_bpp = 16;
break;
case 24:
sizes.surface_depth = sizes.surface_bpp = 24;
break;
case 32:
sizes.surface_depth = 24;
sizes.surface_bpp = 32;
break;
}
break;
}
}
crtc_count = 0;
for (i = 0; i < fb_helper->crtc_count; i++) {
struct drm_display_mode *desired_mode;
struct drm_mode_set *mode_set;
int x, y, j;
bool lastv = true, lasth = true;
desired_mode = fb_helper->crtc_info[i].desired_mode;
mode_set = &fb_helper->crtc_info[i].mode_set;
if (!desired_mode)
continue;
crtc_count++;
x = fb_helper->crtc_info[i].x;
y = fb_helper->crtc_info[i].y;
if (gamma_size == 0)
gamma_size = fb_helper->crtc_info[i].mode_set.crtc->gamma_size;
sizes.surface_width = max_t(u32, desired_mode->hdisplay + x, sizes.surface_width);
sizes.surface_height = max_t(u32, desired_mode->vdisplay + y, sizes.surface_height);
for (j = 0; j < mode_set->num_connectors; j++) {
struct drm_connector *connector = mode_set->connectors[j];
if (connector->has_tile) {
lasth = (connector->tile_h_loc == (connector->num_h_tile - 1));
lastv = (connector->tile_v_loc == (connector->num_v_tile - 1));
break;
}
}
if (lasth)
sizes.fb_width = min_t(u32, desired_mode->hdisplay + x, sizes.fb_width);
if (lastv)
sizes.fb_height = min_t(u32, desired_mode->vdisplay + y, sizes.fb_height);
}
if (crtc_count == 0 || sizes.fb_width == -1 || sizes.fb_height == -1) {
DRM_INFO("Cannot find any crtc or sizes - going 1024x768\n");
sizes.fb_width = sizes.surface_width = 1024;
sizes.fb_height = sizes.surface_height = 768;
}
ret = (*fb_helper->funcs->fb_probe)(fb_helper, &sizes);
if (ret < 0)
return ret;
for (i = 0; i < fb_helper->crtc_count; i++)
if (fb_helper->crtc_info[i].mode_set.num_connectors)
fb_helper->crtc_info[i].mode_set.fb = fb_helper->fb;
return 0;
}
void drm_fb_helper_fill_fix(struct fb_info *info, uint32_t pitch,
uint32_t depth)
{
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = depth == 8 ? FB_VISUAL_PSEUDOCOLOR :
FB_VISUAL_TRUECOLOR;
info->fix.mmio_start = 0;
info->fix.mmio_len = 0;
info->fix.type_aux = 0;
info->fix.xpanstep = 1;
info->fix.ypanstep = 1;
info->fix.ywrapstep = 0;
info->fix.accel = FB_ACCEL_NONE;
info->fix.line_length = pitch;
return;
}
void drm_fb_helper_fill_var(struct fb_info *info, struct drm_fb_helper *fb_helper,
uint32_t fb_width, uint32_t fb_height)
{
struct drm_framebuffer *fb = fb_helper->fb;
info->pseudo_palette = fb_helper->pseudo_palette;
info->var.xres_virtual = fb->width;
info->var.yres_virtual = fb->height;
info->var.bits_per_pixel = fb->bits_per_pixel;
info->var.accel_flags = FB_ACCELF_TEXT;
info->var.xoffset = 0;
info->var.yoffset = 0;
info->var.activate = FB_ACTIVATE_NOW;
info->var.height = -1;
info->var.width = -1;
switch (fb->depth) {
case 8:
info->var.red.offset = 0;
info->var.green.offset = 0;
info->var.blue.offset = 0;
info->var.red.length = 8;
info->var.green.length = 8;
info->var.blue.length = 8;
info->var.transp.offset = 0;
info->var.transp.length = 0;
break;
case 15:
info->var.red.offset = 10;
info->var.green.offset = 5;
info->var.blue.offset = 0;
info->var.red.length = 5;
info->var.green.length = 5;
info->var.blue.length = 5;
info->var.transp.offset = 15;
info->var.transp.length = 1;
break;
case 16:
info->var.red.offset = 11;
info->var.green.offset = 5;
info->var.blue.offset = 0;
info->var.red.length = 5;
info->var.green.length = 6;
info->var.blue.length = 5;
info->var.transp.offset = 0;
break;
case 24:
info->var.red.offset = 16;
info->var.green.offset = 8;
info->var.blue.offset = 0;
info->var.red.length = 8;
info->var.green.length = 8;
info->var.blue.length = 8;
info->var.transp.offset = 0;
info->var.transp.length = 0;
break;
case 32:
info->var.red.offset = 16;
info->var.green.offset = 8;
info->var.blue.offset = 0;
info->var.red.length = 8;
info->var.green.length = 8;
info->var.blue.length = 8;
info->var.transp.offset = 24;
info->var.transp.length = 8;
break;
default:
break;
}
info->var.xres = fb_width;
info->var.yres = fb_height;
}
static int drm_fb_helper_probe_connector_modes(struct drm_fb_helper *fb_helper,
uint32_t maxX,
uint32_t maxY)
{
struct drm_connector *connector;
int count = 0;
int i;
drm_fb_helper_for_each_connector(fb_helper, i) {
connector = fb_helper->connector_info[i]->connector;
count += connector->funcs->fill_modes(connector, maxX, maxY);
}
return count;
}
struct drm_display_mode *drm_has_preferred_mode(struct drm_fb_helper_connector *fb_connector, int width, int height)
{
struct drm_display_mode *mode;
list_for_each_entry(mode, &fb_connector->connector->modes, head) {
if (mode->hdisplay > width ||
mode->vdisplay > height)
continue;
if (mode->type & DRM_MODE_TYPE_PREFERRED)
return mode;
}
return NULL;
}
static bool drm_has_cmdline_mode(struct drm_fb_helper_connector *fb_connector)
{
return fb_connector->connector->cmdline_mode.specified;
}
struct drm_display_mode *drm_pick_cmdline_mode(struct drm_fb_helper_connector *fb_helper_conn,
int width, int height)
{
struct drm_cmdline_mode *cmdline_mode;
struct drm_display_mode *mode;
bool prefer_non_interlace;
cmdline_mode = &fb_helper_conn->connector->cmdline_mode;
if (cmdline_mode->specified == false)
return NULL;
if (cmdline_mode->rb || cmdline_mode->margins)
goto create_mode;
prefer_non_interlace = !cmdline_mode->interlace;
again:
list_for_each_entry(mode, &fb_helper_conn->connector->modes, head) {
if (mode->hdisplay != cmdline_mode->xres ||
mode->vdisplay != cmdline_mode->yres)
continue;
if (cmdline_mode->refresh_specified) {
if (mode->vrefresh != cmdline_mode->refresh)
continue;
}
if (cmdline_mode->interlace) {
if (!(mode->flags & DRM_MODE_FLAG_INTERLACE))
continue;
} else if (prefer_non_interlace) {
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
continue;
}
return mode;
}
if (prefer_non_interlace) {
prefer_non_interlace = false;
goto again;
}
create_mode:
mode = drm_mode_create_from_cmdline_mode(fb_helper_conn->connector->dev,
cmdline_mode);
list_add(&mode->head, &fb_helper_conn->connector->modes);
return mode;
}
static bool drm_connector_enabled(struct drm_connector *connector, bool strict)
{
bool enable;
if (strict)
enable = connector->status == connector_status_connected;
else
enable = connector->status != connector_status_disconnected;
return enable;
}
static void drm_enable_connectors(struct drm_fb_helper *fb_helper,
bool *enabled)
{
bool any_enabled = false;
struct drm_connector *connector;
int i = 0;
drm_fb_helper_for_each_connector(fb_helper, i) {
connector = fb_helper->connector_info[i]->connector;
enabled[i] = drm_connector_enabled(connector, true);
DRM_DEBUG_KMS("connector %d enabled? %s\n", connector->base.id,
enabled[i] ? "yes" : "no");
any_enabled |= enabled[i];
}
if (any_enabled)
return;
drm_fb_helper_for_each_connector(fb_helper, i) {
connector = fb_helper->connector_info[i]->connector;
enabled[i] = drm_connector_enabled(connector, false);
}
}
static bool drm_target_cloned(struct drm_fb_helper *fb_helper,
struct drm_display_mode **modes,
struct drm_fb_offset *offsets,
bool *enabled, int width, int height)
{
int count, i, j;
bool can_clone = false;
struct drm_fb_helper_connector *fb_helper_conn;
struct drm_display_mode *dmt_mode, *mode;
if (fb_helper->crtc_count > 1)
return false;
count = 0;
drm_fb_helper_for_each_connector(fb_helper, i) {
if (enabled[i])
count++;
}
if (count <= 1)
return false;
can_clone = true;
drm_fb_helper_for_each_connector(fb_helper, i) {
if (!enabled[i])
continue;
fb_helper_conn = fb_helper->connector_info[i];
modes[i] = drm_pick_cmdline_mode(fb_helper_conn, width, height);
if (!modes[i]) {
can_clone = false;
break;
}
for (j = 0; j < i; j++) {
if (!enabled[j])
continue;
if (!drm_mode_equal(modes[j], modes[i]))
can_clone = false;
}
}
if (can_clone) {
DRM_DEBUG_KMS("can clone using command line\n");
return true;
}
can_clone = true;
dmt_mode = drm_mode_find_dmt(fb_helper->dev, 1024, 768, 60, false);
drm_fb_helper_for_each_connector(fb_helper, i) {
if (!enabled[i])
continue;
fb_helper_conn = fb_helper->connector_info[i];
list_for_each_entry(mode, &fb_helper_conn->connector->modes, head) {
if (drm_mode_equal(mode, dmt_mode))
modes[i] = mode;
}
if (!modes[i])
can_clone = false;
}
if (can_clone) {
DRM_DEBUG_KMS("can clone using 1024x768\n");
return true;
}
DRM_INFO("kms: can't enable cloning when we probably wanted to.\n");
return false;
}
static int drm_get_tile_offsets(struct drm_fb_helper *fb_helper,
struct drm_display_mode **modes,
struct drm_fb_offset *offsets,
int idx,
int h_idx, int v_idx)
{
struct drm_fb_helper_connector *fb_helper_conn;
int i;
int hoffset = 0, voffset = 0;
drm_fb_helper_for_each_connector(fb_helper, i) {
fb_helper_conn = fb_helper->connector_info[i];
if (!fb_helper_conn->connector->has_tile)
continue;
if (!modes[i] && (h_idx || v_idx)) {
DRM_DEBUG_KMS("no modes for connector tiled %d %d\n", i,
fb_helper_conn->connector->base.id);
continue;
}
if (fb_helper_conn->connector->tile_h_loc < h_idx)
hoffset += modes[i]->hdisplay;
if (fb_helper_conn->connector->tile_v_loc < v_idx)
voffset += modes[i]->vdisplay;
}
offsets[idx].x = hoffset;
offsets[idx].y = voffset;
DRM_DEBUG_KMS("returned %d %d for %d %d\n", hoffset, voffset, h_idx, v_idx);
return 0;
}
static bool drm_target_preferred(struct drm_fb_helper *fb_helper,
struct drm_display_mode **modes,
struct drm_fb_offset *offsets,
bool *enabled, int width, int height)
{
struct drm_fb_helper_connector *fb_helper_conn;
const u64 mask = BIT_ULL(fb_helper->connector_count) - 1;
u64 conn_configured = 0;
int tile_pass = 0;
int i;
retry:
drm_fb_helper_for_each_connector(fb_helper, i) {
fb_helper_conn = fb_helper->connector_info[i];
if (conn_configured & BIT_ULL(i))
continue;
if (enabled[i] == false) {
conn_configured |= BIT_ULL(i);
continue;
}
if (tile_pass == 0 && fb_helper_conn->connector->has_tile)
continue;
if (tile_pass == 1) {
if (fb_helper_conn->connector->tile_h_loc != 0 ||
fb_helper_conn->connector->tile_v_loc != 0)
continue;
} else {
if (fb_helper_conn->connector->tile_h_loc != tile_pass -1 &&
fb_helper_conn->connector->tile_v_loc != tile_pass - 1)
continue;
drm_get_tile_offsets(fb_helper, modes, offsets,
i, fb_helper_conn->connector->tile_h_loc, fb_helper_conn->connector->tile_v_loc);
}
DRM_DEBUG_KMS("looking for cmdline mode on connector %d\n",
fb_helper_conn->connector->base.id);
modes[i] = drm_pick_cmdline_mode(fb_helper_conn, width, height);
if (!modes[i]) {
DRM_DEBUG_KMS("looking for preferred mode on connector %d %d\n",
fb_helper_conn->connector->base.id, fb_helper_conn->connector->tile_group ? fb_helper_conn->connector->tile_group->id : 0);
modes[i] = drm_has_preferred_mode(fb_helper_conn, width, height);
}
if (!modes[i] && !list_empty(&fb_helper_conn->connector->modes)) {
list_for_each_entry(modes[i], &fb_helper_conn->connector->modes, head)
break;
}
DRM_DEBUG_KMS("found mode %s\n", modes[i] ? modes[i]->name :
"none");
conn_configured |= BIT_ULL(i);
}
if ((conn_configured & mask) != mask) {
tile_pass++;
goto retry;
}
return true;
}
static int drm_pick_crtcs(struct drm_fb_helper *fb_helper,
struct drm_fb_helper_crtc **best_crtcs,
struct drm_display_mode **modes,
int n, int width, int height)
{
int c, o;
struct drm_connector *connector;
const struct drm_connector_helper_funcs *connector_funcs;
struct drm_encoder *encoder;
int my_score, best_score, score;
struct drm_fb_helper_crtc **crtcs, *crtc;
struct drm_fb_helper_connector *fb_helper_conn;
if (n == fb_helper->connector_count)
return 0;
fb_helper_conn = fb_helper->connector_info[n];
connector = fb_helper_conn->connector;
best_crtcs[n] = NULL;
best_score = drm_pick_crtcs(fb_helper, best_crtcs, modes, n+1, width, height);
if (modes[n] == NULL)
return best_score;
crtcs = kzalloc(fb_helper->connector_count *
sizeof(struct drm_fb_helper_crtc *), GFP_KERNEL);
if (!crtcs)
return best_score;
my_score = 1;
if (connector->status == connector_status_connected)
my_score++;
if (drm_has_cmdline_mode(fb_helper_conn))
my_score++;
if (drm_has_preferred_mode(fb_helper_conn, width, height))
my_score++;
connector_funcs = connector->helper_private;
if (fb_helper->dev->mode_config.funcs->atomic_commit &&
!connector_funcs->best_encoder)
encoder = drm_atomic_helper_best_encoder(connector);
else
encoder = connector_funcs->best_encoder(connector);
if (!encoder)
goto out;
for (c = 0; c < fb_helper->crtc_count; c++) {
crtc = &fb_helper->crtc_info[c];
if ((encoder->possible_crtcs & (1 << c)) == 0)
continue;
for (o = 0; o < n; o++)
if (best_crtcs[o] == crtc)
break;
if (o < n) {
if (fb_helper->crtc_count > 1)
continue;
if (!drm_mode_equal(modes[o], modes[n]))
continue;
}
crtcs[n] = crtc;
memcpy(crtcs, best_crtcs, n * sizeof(struct drm_fb_helper_crtc *));
score = my_score + drm_pick_crtcs(fb_helper, crtcs, modes, n + 1,
width, height);
if (score > best_score) {
best_score = score;
memcpy(best_crtcs, crtcs,
fb_helper->connector_count *
sizeof(struct drm_fb_helper_crtc *));
}
}
out:
kfree(crtcs);
return best_score;
}
static void drm_setup_crtcs(struct drm_fb_helper *fb_helper,
u32 width, u32 height)
{
struct drm_device *dev = fb_helper->dev;
struct drm_fb_helper_crtc **crtcs;
struct drm_display_mode **modes;
struct drm_fb_offset *offsets;
bool *enabled;
int i;
DRM_DEBUG_KMS("\n");
if (drm_fb_helper_probe_connector_modes(fb_helper, width, height) == 0)
DRM_DEBUG_KMS("No connectors reported connected with modes\n");
lockdep_assert_held(&fb_helper->dev->mode_config.mutex);
crtcs = kcalloc(fb_helper->connector_count,
sizeof(struct drm_fb_helper_crtc *), GFP_KERNEL);
modes = kcalloc(fb_helper->connector_count,
sizeof(struct drm_display_mode *), GFP_KERNEL);
offsets = kcalloc(fb_helper->connector_count,
sizeof(struct drm_fb_offset), GFP_KERNEL);
enabled = kcalloc(fb_helper->connector_count,
sizeof(bool), GFP_KERNEL);
if (!crtcs || !modes || !enabled || !offsets) {
DRM_ERROR("Memory allocation failed\n");
goto out;
}
drm_enable_connectors(fb_helper, enabled);
if (!(fb_helper->funcs->initial_config &&
fb_helper->funcs->initial_config(fb_helper, crtcs, modes,
offsets,
enabled, width, height))) {
memset(modes, 0, fb_helper->connector_count*sizeof(modes[0]));
memset(crtcs, 0, fb_helper->connector_count*sizeof(crtcs[0]));
memset(offsets, 0, fb_helper->connector_count*sizeof(offsets[0]));
if (!drm_target_cloned(fb_helper, modes, offsets,
enabled, width, height) &&
!drm_target_preferred(fb_helper, modes, offsets,
enabled, width, height))
DRM_ERROR("Unable to find initial modes\n");
DRM_DEBUG_KMS("picking CRTCs for %dx%d config\n",
width, height);
drm_pick_crtcs(fb_helper, crtcs, modes, 0, width, height);
}
for (i = 0; i < fb_helper->crtc_count; i++)
drm_fb_helper_modeset_release(fb_helper,
&fb_helper->crtc_info[i].mode_set);
drm_fb_helper_for_each_connector(fb_helper, i) {
struct drm_display_mode *mode = modes[i];
struct drm_fb_helper_crtc *fb_crtc = crtcs[i];
struct drm_fb_offset *offset = &offsets[i];
struct drm_mode_set *modeset = &fb_crtc->mode_set;
if (mode && fb_crtc) {
struct drm_connector *connector =
fb_helper->connector_info[i]->connector;
DRM_DEBUG_KMS("desired mode %s set on crtc %d (%d,%d)\n",
mode->name, fb_crtc->mode_set.crtc->base.id, offset->x, offset->y);
fb_crtc->desired_mode = mode;
fb_crtc->x = offset->x;
fb_crtc->y = offset->y;
modeset->mode = drm_mode_duplicate(dev,
fb_crtc->desired_mode);
drm_connector_reference(connector);
modeset->connectors[modeset->num_connectors++] = connector;
modeset->fb = fb_helper->fb;
modeset->x = offset->x;
modeset->y = offset->y;
}
}
out:
kfree(crtcs);
kfree(modes);
kfree(offsets);
kfree(enabled);
}
int drm_fb_helper_initial_config(struct drm_fb_helper *fb_helper, int bpp_sel)
{
struct drm_device *dev = fb_helper->dev;
struct fb_info *info;
int ret;
if (!drm_fbdev_emulation)
return 0;
mutex_lock(&dev->mode_config.mutex);
drm_setup_crtcs(fb_helper,
dev->mode_config.max_width,
dev->mode_config.max_height);
ret = drm_fb_helper_single_fb_probe(fb_helper, bpp_sel);
mutex_unlock(&dev->mode_config.mutex);
if (ret)
return ret;
info = fb_helper->fbdev;
info->var.pixclock = 0;
ret = register_framebuffer(info);
if (ret < 0)
return ret;
dev_info(dev->dev, "fb%d: %s frame buffer device\n",
info->node, info->fix.id);
mutex_lock(&kernel_fb_helper_lock);
if (list_empty(&kernel_fb_helper_list))
register_sysrq_key('v', &sysrq_drm_fb_helper_restore_op);
list_add(&fb_helper->kernel_fb_list, &kernel_fb_helper_list);
mutex_unlock(&kernel_fb_helper_lock);
return 0;
}
int drm_fb_helper_hotplug_event(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
if (!drm_fbdev_emulation)
return 0;
mutex_lock(&dev->mode_config.mutex);
if (!fb_helper->fb || !drm_fb_helper_is_bound(fb_helper)) {
fb_helper->delayed_hotplug = true;
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
DRM_DEBUG_KMS("\n");
drm_setup_crtcs(fb_helper, fb_helper->fb->width, fb_helper->fb->height);
mutex_unlock(&dev->mode_config.mutex);
drm_fb_helper_set_par(fb_helper->fbdev);
return 0;
}
int __init drm_fb_helper_modinit(void)
{
#if defined(CONFIG_FRAMEBUFFER_CONSOLE_MODULE) && !defined(CONFIG_EXPERT)
const char *name = "fbcon";
struct module *fbcon;
mutex_lock(&module_mutex);
fbcon = find_module(name);
mutex_unlock(&module_mutex);
if (!fbcon)
request_module_nowait(name);
#endif
return 0;
}
