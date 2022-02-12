int drm_fb_helper_single_add_all_connectors(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_connector *connector;
int i;
mutex_lock(&dev->mode_config.mutex);
drm_for_each_connector(connector, dev) {
struct drm_fb_helper_connector *fb_helper_connector;
fb_helper_connector = kzalloc(sizeof(struct drm_fb_helper_connector), GFP_KERNEL);
if (!fb_helper_connector)
goto fail;
fb_helper_connector->connector = connector;
fb_helper->connector_info[fb_helper->connector_count++] = fb_helper_connector;
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
fail:
for (i = 0; i < fb_helper->connector_count; i++) {
kfree(fb_helper->connector_info[i]);
fb_helper->connector_info[i] = NULL;
}
fb_helper->connector_count = 0;
mutex_unlock(&dev->mode_config.mutex);
return -ENOMEM;
}
int drm_fb_helper_add_one_connector(struct drm_fb_helper *fb_helper, struct drm_connector *connector)
{
struct drm_fb_helper_connector **temp;
struct drm_fb_helper_connector *fb_helper_connector;
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
fb_helper_connector->connector = connector;
fb_helper->connector_info[fb_helper->connector_count++] = fb_helper_connector;
return 0;
}
static void remove_from_modeset(struct drm_mode_set *set,
struct drm_connector *connector)
{
int i, j;
for (i = 0; i < set->num_connectors; i++) {
if (set->connectors[i] == connector)
break;
}
if (i == set->num_connectors)
return;
for (j = i + 1; j < set->num_connectors; j++) {
set->connectors[j - 1] = set->connectors[j];
}
set->num_connectors--;
if (set->num_connectors == 0) {
set->fb = NULL;
drm_mode_destroy(connector->dev, set->mode);
set->mode = NULL;
}
}
int drm_fb_helper_remove_one_connector(struct drm_fb_helper *fb_helper,
struct drm_connector *connector)
{
struct drm_fb_helper_connector *fb_helper_connector;
int i, j;
WARN_ON(!mutex_is_locked(&fb_helper->dev->mode_config.mutex));
for (i = 0; i < fb_helper->connector_count; i++) {
if (fb_helper->connector_info[i]->connector == connector)
break;
}
if (i == fb_helper->connector_count)
return -EINVAL;
fb_helper_connector = fb_helper->connector_info[i];
for (j = i + 1; j < fb_helper->connector_count; j++) {
fb_helper->connector_info[j - 1] = fb_helper->connector_info[j];
}
fb_helper->connector_count--;
kfree(fb_helper_connector);
for (i = 0; i < fb_helper->crtc_count; i++)
remove_from_modeset(&fb_helper->crtc_info[i].mode_set, connector);
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
crtc->funcs->gamma_set(crtc, r_base, g_base, b_base, 0, crtc->gamma_size);
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
drm_fb_helper_restore_lut_atomic(mode_set->crtc);
funcs->mode_set_base_atomic(mode_set->crtc, fb, crtc->x,
crtc->y, LEAVE_ATOMIC_MODE_SET);
}
return 0;
}
static bool restore_fbdev_mode(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_plane *plane;
bool error = false;
int i;
drm_warn_on_modeset_not_all_locked(dev);
drm_for_each_plane(plane, dev) {
if (plane->type != DRM_PLANE_TYPE_PRIMARY)
drm_plane_force_disable(plane);
if (dev->mode_config.rotation_property) {
drm_mode_plane_set_obj_prop(plane,
dev->mode_config.rotation_property,
BIT(DRM_ROTATE_0));
}
}
for (i = 0; i < fb_helper->crtc_count; i++) {
struct drm_mode_set *mode_set = &fb_helper->crtc_info[i].mode_set;
struct drm_crtc *crtc = mode_set->crtc;
int ret;
if (crtc->funcs->cursor_set2) {
ret = crtc->funcs->cursor_set2(crtc, NULL, 0, 0, 0, 0, 0);
if (ret)
error = true;
} else if (crtc->funcs->cursor_set) {
ret = crtc->funcs->cursor_set(crtc, NULL, 0, 0, 0);
if (ret)
error = true;
}
ret = drm_mode_set_config_internal(mode_set);
if (ret)
error = true;
}
return error;
}
bool drm_fb_helper_restore_fbdev_mode_unlocked(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
bool ret;
bool do_delayed = false;
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
if (dev->primary->master)
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
for (j = 0; j < fb_helper->connector_count; j++) {
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
static void drm_fb_helper_crtc_free(struct drm_fb_helper *helper)
{
int i;
for (i = 0; i < helper->connector_count; i++)
kfree(helper->connector_info[i]);
kfree(helper->connector_info);
for (i = 0; i < helper->crtc_count; i++) {
kfree(helper->crtc_info[i].mode_set.connectors);
if (helper->crtc_info[i].mode_set.mode)
drm_mode_destroy(helper->dev, helper->crtc_info[i].mode_set.mode);
}
kfree(helper->crtc_info);
}
void drm_fb_helper_prepare(struct drm_device *dev, struct drm_fb_helper *helper,
const struct drm_fb_helper_funcs *funcs)
{
INIT_LIST_HEAD(&helper->kernel_fb_list);
helper->funcs = funcs;
helper->dev = dev;
}
int drm_fb_helper_init(struct drm_device *dev,
struct drm_fb_helper *fb_helper,
int crtc_count, int max_conn_count)
{
struct drm_crtc *crtc;
int i;
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
if (!list_empty(&fb_helper->kernel_fb_list)) {
list_del(&fb_helper->kernel_fb_list);
if (list_empty(&kernel_fb_helper_list)) {
unregister_sysrq_key('v', &sysrq_drm_fb_helper_restore_op);
}
}
drm_fb_helper_crtc_free(fb_helper);
}
void drm_fb_helper_unlink_fbi(struct drm_fb_helper *fb_helper)
{
if (fb_helper && fb_helper->fbdev)
unlink_framebuffer(fb_helper->fbdev);
}
ssize_t drm_fb_helper_sys_read(struct fb_info *info, char __user *buf,
size_t count, loff_t *ppos)
{
return fb_sys_read(info, buf, count, ppos);
}
ssize_t drm_fb_helper_sys_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
return fb_sys_write(info, buf, count, ppos);
}
void drm_fb_helper_sys_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
sys_fillrect(info, rect);
}
void drm_fb_helper_sys_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
sys_copyarea(info, area);
}
void drm_fb_helper_sys_imageblit(struct fb_info *info,
const struct fb_image *image)
{
sys_imageblit(info, image);
}
void drm_fb_helper_cfb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
cfb_fillrect(info, rect);
}
void drm_fb_helper_cfb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
cfb_copyarea(info, area);
}
void drm_fb_helper_cfb_imageblit(struct fb_info *info,
const struct fb_image *image)
{
cfb_imageblit(info, image);
}
void drm_fb_helper_set_suspend(struct drm_fb_helper *fb_helper, int state)
{
if (fb_helper && fb_helper->fbdev)
fb_set_suspend(fb_helper->fbdev, state);
}
static int setcolreg(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, u16 regno, struct fb_info *info)
{
struct drm_fb_helper *fb_helper = info->par;
struct drm_framebuffer *fb = fb_helper->fb;
int pindex;
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
pindex = regno;
if (fb->bits_per_pixel == 16) {
pindex = regno << 3;
if (fb->depth == 16 && regno > 63)
return -EINVAL;
if (fb->depth == 15 && regno > 31)
return -EINVAL;
if (fb->depth == 16) {
u16 r, g, b;
int i;
if (regno < 32) {
for (i = 0; i < 8; i++)
fb_helper->funcs->gamma_set(crtc, red,
green, blue, pindex + i);
}
fb_helper->funcs->gamma_get(crtc, &r,
&g, &b,
pindex >> 1);
for (i = 0; i < 4; i++)
fb_helper->funcs->gamma_set(crtc, r,
green, b,
(pindex >> 1) + i);
}
}
if (fb->depth != 16)
fb_helper->funcs->gamma_set(crtc, red, green, blue, pindex);
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
if (var->bits_per_pixel > fb->bits_per_pixel ||
var->xres > fb->width || var->yres > fb->height ||
var->xres_virtual > fb->width || var->yres_virtual > fb->height) {
DRM_DEBUG("fb userspace requested width/height/bpp is greater than current fb "
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
drm_modeset_unlock_all(dev);
return ret;
}
static int drm_fb_helper_single_fb_probe(struct drm_fb_helper *fb_helper,
int preferred_bpp)
{
int ret = 0;
int crtc_count = 0;
int i;
struct fb_info *info;
struct drm_fb_helper_surface_size sizes;
int gamma_size = 0;
memset(&sizes, 0, sizeof(struct drm_fb_helper_surface_size));
sizes.surface_depth = 24;
sizes.surface_bpp = 32;
sizes.fb_width = (unsigned)-1;
sizes.fb_height = (unsigned)-1;
if (preferred_bpp != sizes.surface_bpp)
sizes.surface_depth = sizes.surface_bpp = preferred_bpp;
for (i = 0; i < fb_helper->connector_count; i++) {
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
info = fb_helper->fbdev;
for (i = 0; i < fb_helper->crtc_count; i++)
if (fb_helper->crtc_info[i].mode_set.num_connectors)
fb_helper->crtc_info[i].mode_set.fb = fb_helper->fb;
info->var.pixclock = 0;
if (register_framebuffer(info) < 0)
return -EINVAL;
dev_info(fb_helper->dev->dev, "fb%d: %s frame buffer device\n",
info->node, info->fix.id);
if (list_empty(&kernel_fb_helper_list)) {
register_sysrq_key('v', &sysrq_drm_fb_helper_restore_op);
}
list_add(&fb_helper->kernel_fb_list, &kernel_fb_helper_list);
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
for (i = 0; i < fb_helper->connector_count; i++) {
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
for (i = 0; i < fb_helper->connector_count; i++) {
connector = fb_helper->connector_info[i]->connector;
enabled[i] = drm_connector_enabled(connector, true);
DRM_DEBUG_KMS("connector %d enabled? %s\n", connector->base.id,
enabled[i] ? "yes" : "no");
any_enabled |= enabled[i];
}
if (any_enabled)
return;
for (i = 0; i < fb_helper->connector_count; i++) {
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
for (i = 0; i < fb_helper->connector_count; i++) {
if (enabled[i])
count++;
}
if (count <= 1)
return false;
can_clone = true;
for (i = 0; i < fb_helper->connector_count; i++) {
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
for (i = 0; i < fb_helper->connector_count; i++) {
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
for (i = 0; i < fb_helper->connector_count; i++) {
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
int i;
uint64_t conn_configured = 0, mask;
int tile_pass = 0;
mask = (1 << fb_helper->connector_count) - 1;
retry:
for (i = 0; i < fb_helper->connector_count; i++) {
fb_helper_conn = fb_helper->connector_info[i];
if (conn_configured & (1 << i))
continue;
if (enabled[i] == false) {
conn_configured |= (1 << i);
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
conn_configured |= (1 << i);
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
struct drm_device *dev = fb_helper->dev;
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
crtcs = kzalloc(dev->mode_config.num_connector *
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
dev->mode_config.num_connector *
sizeof(struct drm_fb_helper_crtc *));
}
}
out:
kfree(crtcs);
return best_score;
}
static void drm_setup_crtcs(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
struct drm_fb_helper_crtc **crtcs;
struct drm_display_mode **modes;
struct drm_fb_offset *offsets;
struct drm_mode_set *modeset;
bool *enabled;
int width, height;
int i;
DRM_DEBUG_KMS("\n");
width = dev->mode_config.max_width;
height = dev->mode_config.max_height;
crtcs = kcalloc(dev->mode_config.num_connector,
sizeof(struct drm_fb_helper_crtc *), GFP_KERNEL);
modes = kcalloc(dev->mode_config.num_connector,
sizeof(struct drm_display_mode *), GFP_KERNEL);
offsets = kcalloc(dev->mode_config.num_connector,
sizeof(struct drm_fb_offset), GFP_KERNEL);
enabled = kcalloc(dev->mode_config.num_connector,
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
memset(modes, 0, dev->mode_config.num_connector*sizeof(modes[0]));
memset(crtcs, 0, dev->mode_config.num_connector*sizeof(crtcs[0]));
memset(offsets, 0, dev->mode_config.num_connector*sizeof(offsets[0]));
if (!drm_target_cloned(fb_helper, modes, offsets,
enabled, width, height) &&
!drm_target_preferred(fb_helper, modes, offsets,
enabled, width, height))
DRM_ERROR("Unable to find initial modes\n");
DRM_DEBUG_KMS("picking CRTCs for %dx%d config\n",
width, height);
drm_pick_crtcs(fb_helper, crtcs, modes, 0, width, height);
}
for (i = 0; i < fb_helper->crtc_count; i++) {
modeset = &fb_helper->crtc_info[i].mode_set;
modeset->num_connectors = 0;
modeset->fb = NULL;
}
for (i = 0; i < fb_helper->connector_count; i++) {
struct drm_display_mode *mode = modes[i];
struct drm_fb_helper_crtc *fb_crtc = crtcs[i];
struct drm_fb_offset *offset = &offsets[i];
modeset = &fb_crtc->mode_set;
if (mode && fb_crtc) {
DRM_DEBUG_KMS("desired mode %s set on crtc %d (%d,%d)\n",
mode->name, fb_crtc->mode_set.crtc->base.id, offset->x, offset->y);
fb_crtc->desired_mode = mode;
fb_crtc->x = offset->x;
fb_crtc->y = offset->y;
if (modeset->mode)
drm_mode_destroy(dev, modeset->mode);
modeset->mode = drm_mode_duplicate(dev,
fb_crtc->desired_mode);
modeset->connectors[modeset->num_connectors++] = fb_helper->connector_info[i]->connector;
modeset->fb = fb_helper->fb;
modeset->x = offset->x;
modeset->y = offset->y;
}
}
for (i = 0; i < fb_helper->crtc_count; i++) {
modeset = &fb_helper->crtc_info[i].mode_set;
if (modeset->num_connectors == 0) {
BUG_ON(modeset->fb);
if (modeset->mode)
drm_mode_destroy(dev, modeset->mode);
modeset->mode = NULL;
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
int count = 0;
mutex_lock(&dev->mode_config.mutex);
count = drm_fb_helper_probe_connector_modes(fb_helper,
dev->mode_config.max_width,
dev->mode_config.max_height);
mutex_unlock(&dev->mode_config.mutex);
if (count == 0)
dev_info(fb_helper->dev->dev, "No connectors reported connected with modes\n");
drm_setup_crtcs(fb_helper);
return drm_fb_helper_single_fb_probe(fb_helper, bpp_sel);
}
int drm_fb_helper_hotplug_event(struct drm_fb_helper *fb_helper)
{
struct drm_device *dev = fb_helper->dev;
u32 max_width, max_height;
mutex_lock(&fb_helper->dev->mode_config.mutex);
if (!fb_helper->fb || !drm_fb_helper_is_bound(fb_helper)) {
fb_helper->delayed_hotplug = true;
mutex_unlock(&fb_helper->dev->mode_config.mutex);
return 0;
}
DRM_DEBUG_KMS("\n");
max_width = fb_helper->fb->width;
max_height = fb_helper->fb->height;
drm_fb_helper_probe_connector_modes(fb_helper, max_width, max_height);
mutex_unlock(&fb_helper->dev->mode_config.mutex);
drm_modeset_lock_all(dev);
drm_setup_crtcs(fb_helper);
drm_modeset_unlock_all(dev);
drm_fb_helper_set_par(fb_helper->fbdev);
return 0;
}
static int __init drm_fb_helper_modinit(void)
{
const char *name = "fbcon";
struct module *fbcon;
mutex_lock(&module_mutex);
fbcon = find_module(name);
mutex_unlock(&module_mutex);
if (!fbcon)
request_module_nowait(name);
return 0;
}
