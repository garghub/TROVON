static ssize_t manager_name_show(struct omap_overlay_manager *mgr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", mgr->name);
}
static ssize_t manager_display_show(struct omap_overlay_manager *mgr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n",
mgr->device ? mgr->device->name : "<none>");
}
int match(struct omap_dss_device *dssdev, void *data)
{
const char *str = data;
return sysfs_streq(dssdev->name, str);
}
static ssize_t manager_default_color_show(struct omap_overlay_manager *mgr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", mgr->info.default_color);
}
static ssize_t manager_default_color_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
u32 color;
int r;
if (sscanf(buf, "%d", &color) != 1)
return -EINVAL;
mgr->get_manager_info(mgr, &info);
info.default_color = color;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_trans_key_type_show(struct omap_overlay_manager *mgr,
char *buf)
{
enum omap_dss_trans_key_type key_type;
key_type = mgr->info.trans_key_type;
BUG_ON(key_type >= ARRAY_SIZE(trans_key_type_str));
return snprintf(buf, PAGE_SIZE, "%s\n", trans_key_type_str[key_type]);
}
static ssize_t manager_trans_key_type_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
enum omap_dss_trans_key_type key_type;
struct omap_overlay_manager_info info;
int r;
for (key_type = OMAP_DSS_COLOR_KEY_GFX_DST;
key_type < ARRAY_SIZE(trans_key_type_str); key_type++) {
if (sysfs_streq(buf, trans_key_type_str[key_type]))
break;
}
if (key_type == ARRAY_SIZE(trans_key_type_str))
return -EINVAL;
mgr->get_manager_info(mgr, &info);
info.trans_key_type = key_type;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_trans_key_value_show(struct omap_overlay_manager *mgr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", mgr->info.trans_key);
}
static ssize_t manager_trans_key_value_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
u32 key_value;
int r;
if (sscanf(buf, "%d", &key_value) != 1)
return -EINVAL;
mgr->get_manager_info(mgr, &info);
info.trans_key = key_value;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_trans_key_enabled_show(struct omap_overlay_manager *mgr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", mgr->info.trans_enabled);
}
static ssize_t manager_trans_key_enabled_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
int enable;
int r;
if (sscanf(buf, "%d", &enable) != 1)
return -EINVAL;
mgr->get_manager_info(mgr, &info);
info.trans_enabled = enable ? true : false;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_alpha_blending_enabled_show(
struct omap_overlay_manager *mgr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", mgr->info.alpha_enabled);
}
static ssize_t manager_alpha_blending_enabled_store(
struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
int enable;
int r;
if (sscanf(buf, "%d", &enable) != 1)
return -EINVAL;
mgr->get_manager_info(mgr, &info);
info.alpha_enabled = enable ? true : false;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct omap_overlay_manager *manager;
struct manager_attribute *manager_attr;
manager = container_of(kobj, struct omap_overlay_manager, kobj);
manager_attr = container_of(attr, struct manager_attribute, attr);
if (!manager_attr->show)
return -ENOENT;
return manager_attr->show(manager, buf);
}
static ssize_t manager_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t size)
{
struct omap_overlay_manager *manager;
struct manager_attribute *manager_attr;
manager = container_of(kobj, struct omap_overlay_manager, kobj);
manager_attr = container_of(attr, struct manager_attribute, attr);
if (!manager_attr->store)
return -ENOENT;
return manager_attr->store(manager, buf, size);
}
static int omap_dss_set_device(struct omap_overlay_manager *mgr,
struct omap_dss_device *dssdev)
{
int i;
int r;
if (dssdev->manager) {
DSSERR("display '%s' already has a manager '%s'\n",
dssdev->name, dssdev->manager->name);
return -EINVAL;
}
if ((mgr->supported_displays & dssdev->type) == 0) {
DSSERR("display '%s' does not support manager '%s'\n",
dssdev->name, mgr->name);
return -EINVAL;
}
for (i = 0; i < mgr->num_overlays; i++) {
struct omap_overlay *ovl = mgr->overlays[i];
if (ovl->manager != mgr || !ovl->info.enabled)
continue;
r = dss_check_overlay(ovl, dssdev);
if (r)
return r;
}
dssdev->manager = mgr;
mgr->device = dssdev;
mgr->device_changed = true;
return 0;
}
static int omap_dss_unset_device(struct omap_overlay_manager *mgr)
{
if (!mgr->device) {
DSSERR("failed to unset display, display not set.\n");
return -EINVAL;
}
mgr->device->manager = NULL;
mgr->device = NULL;
mgr->device_changed = true;
return 0;
}
static int dss_mgr_wait_for_vsync(struct omap_overlay_manager *mgr)
{
unsigned long timeout = msecs_to_jiffies(500);
u32 irq;
if (mgr->device->type == OMAP_DISPLAY_TYPE_VENC) {
irq = DISPC_IRQ_EVSYNC_ODD;
} else if (mgr->device->type == OMAP_DISPLAY_TYPE_HDMI) {
irq = DISPC_IRQ_EVSYNC_EVEN;
} else {
if (mgr->id == OMAP_DSS_CHANNEL_LCD)
irq = DISPC_IRQ_VSYNC;
else
irq = DISPC_IRQ_VSYNC2;
}
return omap_dispc_wait_for_irq_interruptible_timeout(irq, timeout);
}
static int dss_mgr_wait_for_go(struct omap_overlay_manager *mgr)
{
unsigned long timeout = msecs_to_jiffies(500);
struct manager_cache_data *mc;
u32 irq;
int r;
int i;
struct omap_dss_device *dssdev = mgr->device;
if (!dssdev || dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return 0;
if (dssdev->type == OMAP_DISPLAY_TYPE_VENC
|| dssdev->type == OMAP_DISPLAY_TYPE_HDMI) {
irq = DISPC_IRQ_EVSYNC_ODD | DISPC_IRQ_EVSYNC_EVEN;
} else {
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE) {
enum omap_dss_update_mode mode;
mode = dssdev->driver->get_update_mode(dssdev);
if (mode != OMAP_DSS_UPDATE_AUTO)
return 0;
irq = (dssdev->manager->id == OMAP_DSS_CHANNEL_LCD) ?
DISPC_IRQ_FRAMEDONE
: DISPC_IRQ_FRAMEDONE2;
} else {
irq = (dssdev->manager->id == OMAP_DSS_CHANNEL_LCD) ?
DISPC_IRQ_VSYNC
: DISPC_IRQ_VSYNC2;
}
}
mc = &dss_cache.manager_cache[mgr->id];
i = 0;
while (1) {
unsigned long flags;
bool shadow_dirty, dirty;
spin_lock_irqsave(&dss_cache.lock, flags);
dirty = mc->dirty;
shadow_dirty = mc->shadow_dirty;
spin_unlock_irqrestore(&dss_cache.lock, flags);
if (!dirty && !shadow_dirty) {
r = 0;
break;
}
if (i++ == 3) {
DSSERR("mgr(%d)->wait_for_go() not finishing\n",
mgr->id);
r = 0;
break;
}
r = omap_dispc_wait_for_irq_interruptible_timeout(irq, timeout);
if (r == -ERESTARTSYS)
break;
if (r) {
DSSERR("mgr(%d)->wait_for_go() timeout\n", mgr->id);
break;
}
}
return r;
}
int dss_mgr_wait_for_go_ovl(struct omap_overlay *ovl)
{
unsigned long timeout = msecs_to_jiffies(500);
struct overlay_cache_data *oc;
struct omap_dss_device *dssdev;
u32 irq;
int r;
int i;
if (!ovl->manager)
return 0;
dssdev = ovl->manager->device;
if (!dssdev || dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return 0;
if (dssdev->type == OMAP_DISPLAY_TYPE_VENC
|| dssdev->type == OMAP_DISPLAY_TYPE_HDMI) {
irq = DISPC_IRQ_EVSYNC_ODD | DISPC_IRQ_EVSYNC_EVEN;
} else {
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE) {
enum omap_dss_update_mode mode;
mode = dssdev->driver->get_update_mode(dssdev);
if (mode != OMAP_DSS_UPDATE_AUTO)
return 0;
irq = (dssdev->manager->id == OMAP_DSS_CHANNEL_LCD) ?
DISPC_IRQ_FRAMEDONE
: DISPC_IRQ_FRAMEDONE2;
} else {
irq = (dssdev->manager->id == OMAP_DSS_CHANNEL_LCD) ?
DISPC_IRQ_VSYNC
: DISPC_IRQ_VSYNC2;
}
}
oc = &dss_cache.overlay_cache[ovl->id];
i = 0;
while (1) {
unsigned long flags;
bool shadow_dirty, dirty;
spin_lock_irqsave(&dss_cache.lock, flags);
dirty = oc->dirty;
shadow_dirty = oc->shadow_dirty;
spin_unlock_irqrestore(&dss_cache.lock, flags);
if (!dirty && !shadow_dirty) {
r = 0;
break;
}
if (i++ == 3) {
DSSERR("ovl(%d)->wait_for_go() not finishing\n",
ovl->id);
r = 0;
break;
}
r = omap_dispc_wait_for_irq_interruptible_timeout(irq, timeout);
if (r == -ERESTARTSYS)
break;
if (r) {
DSSERR("ovl(%d)->wait_for_go() timeout\n", ovl->id);
break;
}
}
return r;
}
static int overlay_enabled(struct omap_overlay *ovl)
{
return ovl->info.enabled && ovl->manager && ovl->manager->device;
}
static bool rectangle_subset(int x1, int y1, int w1, int h1,
int x2, int y2, int w2, int h2)
{
if (x1 < x2 || y1 < y2)
return false;
if (x1 + w1 > x2 + w2)
return false;
if (y1 + h1 > y2 + h2)
return false;
return true;
}
static bool rectangle_intersects(int x1, int y1, int w1, int h1,
int x2, int y2, int w2, int h2)
{
if (x1 >= x2 + w2)
return false;
if (x2 >= x1 + w1)
return false;
if (y1 >= y2 + h2)
return false;
if (y2 >= y1 + h1)
return false;
return true;
}
static bool dispc_is_overlay_scaled(struct overlay_cache_data *oc)
{
if (oc->out_width != 0 && oc->width != oc->out_width)
return true;
if (oc->out_height != 0 && oc->height != oc->out_height)
return true;
return false;
}
static int configure_overlay(enum omap_plane plane)
{
struct overlay_cache_data *c;
struct manager_cache_data *mc;
u16 outw, outh;
u16 x, y, w, h;
u32 paddr;
int r;
u16 orig_w, orig_h, orig_outw, orig_outh;
DSSDBGF("%d", plane);
c = &dss_cache.overlay_cache[plane];
if (!c->enabled) {
dispc_enable_plane(plane, 0);
return 0;
}
mc = &dss_cache.manager_cache[c->channel];
x = c->pos_x;
y = c->pos_y;
w = c->width;
h = c->height;
outw = c->out_width == 0 ? c->width : c->out_width;
outh = c->out_height == 0 ? c->height : c->out_height;
paddr = c->paddr;
orig_w = w;
orig_h = h;
orig_outw = outw;
orig_outh = outh;
if (c->manual_update && mc->do_manual_update) {
unsigned bpp;
unsigned scale_x_m = w, scale_x_d = outw;
unsigned scale_y_m = h, scale_y_d = outh;
if (!rectangle_intersects(mc->x, mc->y, mc->w, mc->h,
x, y, outw, outh)) {
dispc_enable_plane(plane, 0);
return 0;
}
switch (c->color_mode) {
case OMAP_DSS_COLOR_NV12:
bpp = 8;
break;
case OMAP_DSS_COLOR_RGB16:
case OMAP_DSS_COLOR_ARGB16:
case OMAP_DSS_COLOR_YUV2:
case OMAP_DSS_COLOR_UYVY:
case OMAP_DSS_COLOR_RGBA16:
case OMAP_DSS_COLOR_RGBX16:
case OMAP_DSS_COLOR_ARGB16_1555:
case OMAP_DSS_COLOR_XRGB16_1555:
bpp = 16;
break;
case OMAP_DSS_COLOR_RGB24P:
bpp = 24;
break;
case OMAP_DSS_COLOR_RGB24U:
case OMAP_DSS_COLOR_ARGB32:
case OMAP_DSS_COLOR_RGBA32:
case OMAP_DSS_COLOR_RGBX32:
bpp = 32;
break;
default:
BUG();
}
if (mc->x > c->pos_x) {
x = 0;
outw -= (mc->x - c->pos_x);
paddr += (mc->x - c->pos_x) *
scale_x_m / scale_x_d * bpp / 8;
} else {
x = c->pos_x - mc->x;
}
if (mc->y > c->pos_y) {
y = 0;
outh -= (mc->y - c->pos_y);
paddr += (mc->y - c->pos_y) *
scale_y_m / scale_y_d *
c->screen_width * bpp / 8;
} else {
y = c->pos_y - mc->y;
}
if (mc->w < (x + outw))
outw -= (x + outw) - (mc->w);
if (mc->h < (y + outh))
outh -= (y + outh) - (mc->h);
w = w * outw / orig_outw;
h = h * outh / orig_outh;
if ((w & 1) &&
(c->color_mode == OMAP_DSS_COLOR_YUV2 ||
c->color_mode == OMAP_DSS_COLOR_UYVY)) {
if (orig_w > w)
w += 1;
else
w -= 1;
}
}
r = dispc_setup_plane(plane,
paddr,
c->screen_width,
x, y,
w, h,
outw, outh,
c->color_mode,
c->ilace,
c->rotation_type,
c->rotation,
c->mirror,
c->global_alpha,
c->pre_mult_alpha,
c->channel,
c->p_uv_addr);
if (r) {
DSSERR("dispc_setup_plane failed for ovl %d\n", plane);
dispc_enable_plane(plane, 0);
return r;
}
dispc_enable_replication(plane, c->replication);
dispc_set_burst_size(plane, c->burst_size);
dispc_setup_plane_fifo(plane, c->fifo_low, c->fifo_high);
dispc_enable_plane(plane, 1);
return 0;
}
static void configure_manager(enum omap_channel channel)
{
struct manager_cache_data *c;
DSSDBGF("%d", channel);
c = &dss_cache.manager_cache[channel];
dispc_set_default_color(channel, c->default_color);
dispc_set_trans_key(channel, c->trans_key_type, c->trans_key);
dispc_enable_trans_key(channel, c->trans_enabled);
dispc_enable_alpha_blending(channel, c->alpha_enabled);
}
static int configure_dispc(void)
{
struct overlay_cache_data *oc;
struct manager_cache_data *mc;
const int num_ovls = dss_feat_get_num_ovls();
const int num_mgrs = dss_feat_get_num_mgrs();
int i;
int r;
bool mgr_busy[MAX_DSS_MANAGERS];
bool mgr_go[MAX_DSS_MANAGERS];
bool busy;
r = 0;
busy = false;
for (i = 0; i < num_mgrs; i++) {
mgr_busy[i] = dispc_go_busy(i);
mgr_go[i] = false;
}
for (i = 0; i < num_ovls; ++i) {
oc = &dss_cache.overlay_cache[i];
mc = &dss_cache.manager_cache[oc->channel];
if (!oc->dirty)
continue;
if (oc->manual_update && !mc->do_manual_update)
continue;
if (mgr_busy[oc->channel]) {
busy = true;
continue;
}
r = configure_overlay(i);
if (r)
DSSERR("configure_overlay %d failed\n", i);
oc->dirty = false;
oc->shadow_dirty = true;
mgr_go[oc->channel] = true;
}
for (i = 0; i < num_mgrs; ++i) {
mc = &dss_cache.manager_cache[i];
if (!mc->dirty)
continue;
if (mc->manual_update && !mc->do_manual_update)
continue;
if (mgr_busy[i]) {
busy = true;
continue;
}
configure_manager(i);
mc->dirty = false;
mc->shadow_dirty = true;
mgr_go[i] = true;
}
for (i = 0; i < num_mgrs; ++i) {
mc = &dss_cache.manager_cache[i];
if (!mgr_go[i])
continue;
if (!mc->manual_upd_display)
dispc_go(i);
}
if (busy)
r = 1;
else
r = 0;
return r;
}
static void make_even(u16 *x, u16 *w)
{
u16 x1, x2;
x1 = *x;
x2 = *x + *w;
x1 &= ~1;
x2 = ALIGN(x2, 2);
*x = x1;
*w = x2 - x1;
}
void dss_setup_partial_planes(struct omap_dss_device *dssdev,
u16 *xi, u16 *yi, u16 *wi, u16 *hi, bool enlarge_update_area)
{
struct overlay_cache_data *oc;
struct manager_cache_data *mc;
const int num_ovls = dss_feat_get_num_ovls();
struct omap_overlay_manager *mgr;
int i;
u16 x, y, w, h;
unsigned long flags;
bool area_changed;
x = *xi;
y = *yi;
w = *wi;
h = *hi;
DSSDBG("dispc_setup_partial_planes %d,%d %dx%d\n",
*xi, *yi, *wi, *hi);
mgr = dssdev->manager;
if (!mgr) {
DSSDBG("no manager\n");
return;
}
make_even(&x, &w);
spin_lock_irqsave(&dss_cache.lock, flags);
do {
area_changed = false;
for (i = 0; i < num_ovls; ++i) {
unsigned x1, y1, x2, y2;
unsigned outw, outh;
oc = &dss_cache.overlay_cache[i];
if (oc->channel != mgr->id)
continue;
oc->dirty = true;
if (!enlarge_update_area)
continue;
if (!oc->enabled)
continue;
if (!dispc_is_overlay_scaled(oc))
continue;
outw = oc->out_width == 0 ?
oc->width : oc->out_width;
outh = oc->out_height == 0 ?
oc->height : oc->out_height;
if (!rectangle_intersects(x, y, w, h,
oc->pos_x, oc->pos_y,
outw, outh))
continue;
if (rectangle_subset(oc->pos_x, oc->pos_y, outw, outh,
x, y, w, h))
continue;
if (x > oc->pos_x)
x1 = oc->pos_x;
else
x1 = x;
if (y > oc->pos_y)
y1 = oc->pos_y;
else
y1 = y;
if ((x + w) < (oc->pos_x + outw))
x2 = oc->pos_x + outw;
else
x2 = x + w;
if ((y + h) < (oc->pos_y + outh))
y2 = oc->pos_y + outh;
else
y2 = y + h;
x = x1;
y = y1;
w = x2 - x1;
h = y2 - y1;
make_even(&x, &w);
DSSDBG("changing upd area due to ovl(%d) "
"scaling %d,%d %dx%d\n",
i, x, y, w, h);
area_changed = true;
}
} while (area_changed);
mc = &dss_cache.manager_cache[mgr->id];
mc->do_manual_update = true;
mc->enlarge_update_area = enlarge_update_area;
mc->x = x;
mc->y = y;
mc->w = w;
mc->h = h;
configure_dispc();
mc->do_manual_update = false;
spin_unlock_irqrestore(&dss_cache.lock, flags);
*xi = x;
*yi = y;
*wi = w;
*hi = h;
}
void dss_start_update(struct omap_dss_device *dssdev)
{
struct manager_cache_data *mc;
struct overlay_cache_data *oc;
const int num_ovls = dss_feat_get_num_ovls();
const int num_mgrs = dss_feat_get_num_mgrs();
struct omap_overlay_manager *mgr;
int i;
mgr = dssdev->manager;
for (i = 0; i < num_ovls; ++i) {
oc = &dss_cache.overlay_cache[i];
if (oc->channel != mgr->id)
continue;
oc->shadow_dirty = false;
}
for (i = 0; i < num_mgrs; ++i) {
mc = &dss_cache.manager_cache[i];
if (mgr->id != i)
continue;
mc->shadow_dirty = false;
}
dssdev->manager->enable(dssdev->manager);
}
static void dss_apply_irq_handler(void *data, u32 mask)
{
struct manager_cache_data *mc;
struct overlay_cache_data *oc;
const int num_ovls = dss_feat_get_num_ovls();
const int num_mgrs = dss_feat_get_num_mgrs();
int i, r;
bool mgr_busy[MAX_DSS_MANAGERS];
u32 irq_mask;
for (i = 0; i < num_mgrs; i++)
mgr_busy[i] = dispc_go_busy(i);
spin_lock(&dss_cache.lock);
for (i = 0; i < num_ovls; ++i) {
oc = &dss_cache.overlay_cache[i];
if (!mgr_busy[oc->channel])
oc->shadow_dirty = false;
}
for (i = 0; i < num_mgrs; ++i) {
mc = &dss_cache.manager_cache[i];
if (!mgr_busy[i])
mc->shadow_dirty = false;
}
r = configure_dispc();
if (r == 1)
goto end;
for (i = 0; i < num_mgrs; i++)
mgr_busy[i] = dispc_go_busy(i);
for (i = 0; i < num_mgrs; ++i) {
if (mgr_busy[i])
goto end;
}
irq_mask = DISPC_IRQ_VSYNC | DISPC_IRQ_EVSYNC_ODD |
DISPC_IRQ_EVSYNC_EVEN;
if (dss_has_feature(FEAT_MGR_LCD2))
irq_mask |= DISPC_IRQ_VSYNC2;
omap_dispc_unregister_isr(dss_apply_irq_handler, NULL, irq_mask);
dss_cache.irq_enabled = false;
end:
spin_unlock(&dss_cache.lock);
}
static int omap_dss_mgr_apply(struct omap_overlay_manager *mgr)
{
struct overlay_cache_data *oc;
struct manager_cache_data *mc;
int i;
struct omap_overlay *ovl;
int num_planes_enabled = 0;
bool use_fifomerge;
unsigned long flags;
int r;
DSSDBG("omap_dss_mgr_apply(%s)\n", mgr->name);
spin_lock_irqsave(&dss_cache.lock, flags);
for (i = 0; i < omap_dss_get_num_overlays(); ++i) {
struct omap_dss_device *dssdev;
ovl = omap_dss_get_overlay(i);
if (!(ovl->caps & OMAP_DSS_OVL_CAP_DISPC))
continue;
oc = &dss_cache.overlay_cache[ovl->id];
if (!overlay_enabled(ovl)) {
if (oc->enabled) {
oc->enabled = false;
oc->dirty = true;
}
continue;
}
if (!ovl->info_dirty) {
if (oc->enabled)
++num_planes_enabled;
continue;
}
dssdev = ovl->manager->device;
if (dss_check_overlay(ovl, dssdev)) {
if (oc->enabled) {
oc->enabled = false;
oc->dirty = true;
}
continue;
}
ovl->info_dirty = false;
oc->dirty = true;
oc->paddr = ovl->info.paddr;
oc->vaddr = ovl->info.vaddr;
oc->p_uv_addr = ovl->info.p_uv_addr;
oc->screen_width = ovl->info.screen_width;
oc->width = ovl->info.width;
oc->height = ovl->info.height;
oc->color_mode = ovl->info.color_mode;
oc->rotation = ovl->info.rotation;
oc->rotation_type = ovl->info.rotation_type;
oc->mirror = ovl->info.mirror;
oc->pos_x = ovl->info.pos_x;
oc->pos_y = ovl->info.pos_y;
oc->out_width = ovl->info.out_width;
oc->out_height = ovl->info.out_height;
oc->global_alpha = ovl->info.global_alpha;
oc->pre_mult_alpha = ovl->info.pre_mult_alpha;
oc->replication =
dss_use_replication(dssdev, ovl->info.color_mode);
oc->ilace = dssdev->type == OMAP_DISPLAY_TYPE_VENC;
oc->channel = ovl->manager->id;
oc->enabled = true;
oc->manual_update =
dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE &&
dssdev->driver->get_update_mode(dssdev) !=
OMAP_DSS_UPDATE_AUTO;
++num_planes_enabled;
}
list_for_each_entry(mgr, &manager_list, list) {
struct omap_dss_device *dssdev;
if (!(mgr->caps & OMAP_DSS_OVL_MGR_CAP_DISPC))
continue;
mc = &dss_cache.manager_cache[mgr->id];
if (mgr->device_changed) {
mgr->device_changed = false;
mgr->info_dirty = true;
}
if (!mgr->info_dirty)
continue;
if (!mgr->device)
continue;
dssdev = mgr->device;
mgr->info_dirty = false;
mc->dirty = true;
mc->default_color = mgr->info.default_color;
mc->trans_key_type = mgr->info.trans_key_type;
mc->trans_key = mgr->info.trans_key;
mc->trans_enabled = mgr->info.trans_enabled;
mc->alpha_enabled = mgr->info.alpha_enabled;
mc->manual_upd_display =
dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE;
mc->manual_update =
dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE &&
dssdev->driver->get_update_mode(dssdev) !=
OMAP_DSS_UPDATE_AUTO;
}
use_fifomerge = false;
for (i = 0; i < omap_dss_get_num_overlays(); ++i) {
struct omap_dss_device *dssdev;
u32 size;
ovl = omap_dss_get_overlay(i);
if (!(ovl->caps & OMAP_DSS_OVL_CAP_DISPC))
continue;
oc = &dss_cache.overlay_cache[ovl->id];
if (!oc->enabled)
continue;
dssdev = ovl->manager->device;
size = dispc_get_plane_fifo_size(ovl->id);
if (use_fifomerge)
size *= 3;
switch (dssdev->type) {
case OMAP_DISPLAY_TYPE_DPI:
case OMAP_DISPLAY_TYPE_DBI:
case OMAP_DISPLAY_TYPE_SDI:
case OMAP_DISPLAY_TYPE_VENC:
case OMAP_DISPLAY_TYPE_HDMI:
default_get_overlay_fifo_thresholds(ovl->id, size,
&oc->burst_size, &oc->fifo_low,
&oc->fifo_high);
break;
#ifdef CONFIG_OMAP2_DSS_DSI
case OMAP_DISPLAY_TYPE_DSI:
dsi_get_overlay_fifo_thresholds(ovl->id, size,
&oc->burst_size, &oc->fifo_low,
&oc->fifo_high);
break;
#endif
default:
BUG();
}
}
r = 0;
dss_clk_enable(DSS_CLK_ICK | DSS_CLK_FCK);
if (!dss_cache.irq_enabled) {
u32 mask;
mask = DISPC_IRQ_VSYNC | DISPC_IRQ_EVSYNC_ODD |
DISPC_IRQ_EVSYNC_EVEN;
if (dss_has_feature(FEAT_MGR_LCD2))
mask |= DISPC_IRQ_VSYNC2;
r = omap_dispc_register_isr(dss_apply_irq_handler, NULL, mask);
dss_cache.irq_enabled = true;
}
configure_dispc();
dss_clk_disable(DSS_CLK_ICK | DSS_CLK_FCK);
spin_unlock_irqrestore(&dss_cache.lock, flags);
return r;
}
static int dss_check_manager(struct omap_overlay_manager *mgr)
{
if (mgr->info.alpha_enabled && mgr->info.trans_enabled &&
mgr->info.trans_key_type != OMAP_DSS_COLOR_KEY_GFX_DST)
return -EINVAL;
return 0;
}
static int omap_dss_mgr_set_info(struct omap_overlay_manager *mgr,
struct omap_overlay_manager_info *info)
{
int r;
struct omap_overlay_manager_info old_info;
old_info = mgr->info;
mgr->info = *info;
r = dss_check_manager(mgr);
if (r) {
mgr->info = old_info;
return r;
}
mgr->info_dirty = true;
return 0;
}
static void omap_dss_mgr_get_info(struct omap_overlay_manager *mgr,
struct omap_overlay_manager_info *info)
{
*info = mgr->info;
}
static int dss_mgr_enable(struct omap_overlay_manager *mgr)
{
dispc_enable_channel(mgr->id, 1);
return 0;
}
static int dss_mgr_disable(struct omap_overlay_manager *mgr)
{
dispc_enable_channel(mgr->id, 0);
return 0;
}
static void omap_dss_add_overlay_manager(struct omap_overlay_manager *manager)
{
++num_managers;
list_add_tail(&manager->list, &manager_list);
}
int omap_dss_mgr_apply_l4(struct omap_overlay_manager *mgr)
{
DSSDBG("omap_dss_mgr_apply_l4(%s)\n", mgr->name);
return 0;
}
void dss_uninit_overlay_managers(struct platform_device *pdev)
{
struct omap_overlay_manager *mgr;
while (!list_empty(&manager_list)) {
mgr = list_first_entry(&manager_list,
struct omap_overlay_manager, list);
list_del(&mgr->list);
kobject_del(&mgr->kobj);
kobject_put(&mgr->kobj);
kfree(mgr);
}
num_managers = 0;
}
int omap_dss_get_num_overlay_managers(void)
{
return num_managers;
}
struct omap_overlay_manager *omap_dss_get_overlay_manager(int num)
{
int i = 0;
struct omap_overlay_manager *mgr;
list_for_each_entry(mgr, &manager_list, list) {
if (i++ == num)
return mgr;
}
return NULL;
}
