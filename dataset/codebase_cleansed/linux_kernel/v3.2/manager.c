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
return snprintf(buf, PAGE_SIZE, "%#x\n", mgr->info.default_color);
}
static ssize_t manager_default_color_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
u32 color;
int r;
r = kstrtouint(buf, 0, &color);
if (r)
return r;
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
return snprintf(buf, PAGE_SIZE, "%#x\n", mgr->info.trans_key);
}
static ssize_t manager_trans_key_value_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
u32 key_value;
int r;
r = kstrtouint(buf, 0, &key_value);
if (r)
return r;
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
bool enable;
int r;
r = strtobool(buf, &enable);
if (r)
return r;
mgr->get_manager_info(mgr, &info);
info.trans_enabled = enable;
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
WARN_ON(!dss_has_feature(FEAT_ALPHA_FIXED_ZORDER));
return snprintf(buf, PAGE_SIZE, "%d\n",
mgr->info.partial_alpha_enabled);
}
static ssize_t manager_alpha_blending_enabled_store(
struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
bool enable;
int r;
WARN_ON(!dss_has_feature(FEAT_ALPHA_FIXED_ZORDER));
r = strtobool(buf, &enable);
if (r)
return r;
mgr->get_manager_info(mgr, &info);
info.partial_alpha_enabled = enable;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_cpr_enable_show(struct omap_overlay_manager *mgr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", mgr->info.cpr_enable);
}
static ssize_t manager_cpr_enable_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
int r;
bool enable;
if (!dss_has_feature(FEAT_CPR))
return -ENODEV;
r = strtobool(buf, &enable);
if (r)
return r;
mgr->get_manager_info(mgr, &info);
if (info.cpr_enable == enable)
return size;
info.cpr_enable = enable;
r = mgr->set_manager_info(mgr, &info);
if (r)
return r;
r = mgr->apply(mgr);
if (r)
return r;
return size;
}
static ssize_t manager_cpr_coef_show(struct omap_overlay_manager *mgr,
char *buf)
{
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
return snprintf(buf, PAGE_SIZE,
"%d %d %d %d %d %d %d %d %d\n",
info.cpr_coefs.rr,
info.cpr_coefs.rg,
info.cpr_coefs.rb,
info.cpr_coefs.gr,
info.cpr_coefs.gg,
info.cpr_coefs.gb,
info.cpr_coefs.br,
info.cpr_coefs.bg,
info.cpr_coefs.bb);
}
static ssize_t manager_cpr_coef_store(struct omap_overlay_manager *mgr,
const char *buf, size_t size)
{
struct omap_overlay_manager_info info;
struct omap_dss_cpr_coefs coefs;
int r, i;
s16 *arr;
if (!dss_has_feature(FEAT_CPR))
return -ENODEV;
if (sscanf(buf, "%hd %hd %hd %hd %hd %hd %hd %hd %hd",
&coefs.rr, &coefs.rg, &coefs.rb,
&coefs.gr, &coefs.gg, &coefs.gb,
&coefs.br, &coefs.bg, &coefs.bb) != 9)
return -EINVAL;
arr = (s16[]){ coefs.rr, coefs.rg, coefs.rb,
coefs.gr, coefs.gg, coefs.gb,
coefs.br, coefs.bg, coefs.bb };
for (i = 0; i < 9; ++i) {
if (arr[i] < -512 || arr[i] > 511)
return -EINVAL;
}
mgr->get_manager_info(mgr, &info);
info.cpr_coefs = coefs;
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
if (mgr->device->state != OMAP_DSS_DISPLAY_DISABLED)
return -EINVAL;
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
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE)
return 0;
if (dssdev->type == OMAP_DISPLAY_TYPE_VENC
|| dssdev->type == OMAP_DISPLAY_TYPE_HDMI) {
irq = DISPC_IRQ_EVSYNC_ODD | DISPC_IRQ_EVSYNC_EVEN;
} else {
irq = (dssdev->manager->id == OMAP_DSS_CHANNEL_LCD) ?
DISPC_IRQ_VSYNC : DISPC_IRQ_VSYNC2;
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
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE)
return 0;
if (dssdev->type == OMAP_DISPLAY_TYPE_VENC
|| dssdev->type == OMAP_DISPLAY_TYPE_HDMI) {
irq = DISPC_IRQ_EVSYNC_ODD | DISPC_IRQ_EVSYNC_EVEN;
} else {
irq = (dssdev->manager->id == OMAP_DSS_CHANNEL_LCD) ?
DISPC_IRQ_VSYNC : DISPC_IRQ_VSYNC2;
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
struct omap_overlay_info *oi = &oc->info;
if (oi->out_width != 0 && oi->width != oi->out_width)
return true;
if (oi->out_height != 0 && oi->height != oi->out_height)
return true;
return false;
}
static int configure_overlay(enum omap_plane plane)
{
struct overlay_cache_data *c;
struct manager_cache_data *mc;
struct omap_overlay_info *oi, new_oi;
struct omap_overlay_manager_info *mi;
u16 outw, outh;
u16 x, y, w, h;
u32 paddr;
int r;
u16 orig_w, orig_h, orig_outw, orig_outh;
DSSDBGF("%d", plane);
c = &dss_cache.overlay_cache[plane];
oi = &c->info;
if (!c->enabled) {
dispc_ovl_enable(plane, 0);
return 0;
}
mc = &dss_cache.manager_cache[c->channel];
mi = &mc->info;
x = oi->pos_x;
y = oi->pos_y;
w = oi->width;
h = oi->height;
outw = oi->out_width == 0 ? oi->width : oi->out_width;
outh = oi->out_height == 0 ? oi->height : oi->out_height;
paddr = oi->paddr;
orig_w = w;
orig_h = h;
orig_outw = outw;
orig_outh = outh;
if (mc->manual_update && mc->do_manual_update) {
unsigned bpp;
unsigned scale_x_m = w, scale_x_d = outw;
unsigned scale_y_m = h, scale_y_d = outh;
if (!rectangle_intersects(mc->x, mc->y, mc->w, mc->h,
x, y, outw, outh)) {
dispc_ovl_enable(plane, 0);
return 0;
}
switch (oi->color_mode) {
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
if (mc->x > oi->pos_x) {
x = 0;
outw -= (mc->x - oi->pos_x);
paddr += (mc->x - oi->pos_x) *
scale_x_m / scale_x_d * bpp / 8;
} else {
x = oi->pos_x - mc->x;
}
if (mc->y > oi->pos_y) {
y = 0;
outh -= (mc->y - oi->pos_y);
paddr += (mc->y - oi->pos_y) *
scale_y_m / scale_y_d *
oi->screen_width * bpp / 8;
} else {
y = oi->pos_y - mc->y;
}
if (mc->w < (x + outw))
outw -= (x + outw) - (mc->w);
if (mc->h < (y + outh))
outh -= (y + outh) - (mc->h);
w = w * outw / orig_outw;
h = h * outh / orig_outh;
if ((w & 1) &&
(oi->color_mode == OMAP_DSS_COLOR_YUV2 ||
oi->color_mode == OMAP_DSS_COLOR_UYVY)) {
if (orig_w > w)
w += 1;
else
w -= 1;
}
}
new_oi = *oi;
new_oi.pos_x = x;
new_oi.pos_y = y;
new_oi.width = w;
new_oi.height = h;
new_oi.out_width = outw;
new_oi.out_height = outh;
new_oi.paddr = paddr;
r = dispc_ovl_setup(plane, &new_oi, c->ilace, c->channel,
c->replication, c->fifo_low, c->fifo_high);
if (r) {
DSSERR("dispc_ovl_setup failed for ovl %d\n", plane);
dispc_ovl_enable(plane, 0);
return r;
}
dispc_ovl_enable(plane, 1);
return 0;
}
static void configure_manager(enum omap_channel channel)
{
struct omap_overlay_manager_info *mi;
DSSDBGF("%d", channel);
mi = &dss_cache.manager_cache[channel].info;
dispc_mgr_set_default_color(channel, mi->default_color);
dispc_mgr_set_trans_key(channel, mi->trans_key_type, mi->trans_key);
dispc_mgr_enable_trans_key(channel, mi->trans_enabled);
dispc_mgr_enable_alpha_fixed_zorder(channel, mi->partial_alpha_enabled);
if (dss_has_feature(FEAT_CPR)) {
dispc_mgr_enable_cpr(channel, mi->cpr_enable);
dispc_mgr_set_cpr_coef(channel, &mi->cpr_coefs);
}
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
mgr_busy[i] = dispc_mgr_go_busy(i);
mgr_go[i] = false;
}
for (i = 0; i < num_ovls; ++i) {
oc = &dss_cache.overlay_cache[i];
mc = &dss_cache.manager_cache[oc->channel];
if (!oc->dirty)
continue;
if (mc->manual_update && !mc->do_manual_update)
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
if (!mc->manual_update)
dispc_mgr_go(i);
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
struct omap_overlay_info *oi;
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
oi = &oc->info;
if (oc->channel != mgr->id)
continue;
oc->dirty = true;
if (!enlarge_update_area)
continue;
if (!oc->enabled)
continue;
if (!dispc_is_overlay_scaled(oc))
continue;
outw = oi->out_width == 0 ?
oi->width : oi->out_width;
outh = oi->out_height == 0 ?
oi->height : oi->out_height;
if (!rectangle_intersects(x, y, w, h,
oi->pos_x, oi->pos_y,
outw, outh))
continue;
if (rectangle_subset(oi->pos_x, oi->pos_y, outw, outh,
x, y, w, h))
continue;
if (x > oi->pos_x)
x1 = oi->pos_x;
else
x1 = x;
if (y > oi->pos_y)
y1 = oi->pos_y;
else
y1 = y;
if ((x + w) < (oi->pos_x + outw))
x2 = oi->pos_x + outw;
else
x2 = x + w;
if ((y + h) < (oi->pos_y + outh))
y2 = oi->pos_y + outh;
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
mgr_busy[i] = dispc_mgr_go_busy(i);
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
mgr_busy[i] = dispc_mgr_go_busy(i);
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
r = dispc_runtime_get();
if (r)
return r;
spin_lock_irqsave(&dss_cache.lock, flags);
for (i = 0; i < omap_dss_get_num_overlays(); ++i) {
struct omap_dss_device *dssdev;
ovl = omap_dss_get_overlay(i);
oc = &dss_cache.overlay_cache[ovl->id];
if (ovl->manager_changed) {
ovl->manager_changed = false;
ovl->info_dirty = true;
}
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
oc->info = ovl->info;
oc->replication =
dss_use_replication(dssdev, ovl->info.color_mode);
oc->ilace = dssdev->type == OMAP_DISPLAY_TYPE_VENC;
oc->channel = ovl->manager->id;
oc->enabled = true;
++num_planes_enabled;
}
list_for_each_entry(mgr, &manager_list, list) {
struct omap_dss_device *dssdev;
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
mc->info = mgr->info;
mc->manual_update =
dssdev->caps & OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE;
}
use_fifomerge = false;
for (i = 0; i < omap_dss_get_num_overlays(); ++i) {
struct omap_dss_device *dssdev;
u32 size, burst_size;
ovl = omap_dss_get_overlay(i);
oc = &dss_cache.overlay_cache[ovl->id];
if (!oc->enabled)
continue;
dssdev = ovl->manager->device;
size = dispc_ovl_get_fifo_size(ovl->id);
if (use_fifomerge)
size *= 3;
burst_size = dispc_ovl_get_burst_size(ovl->id);
switch (dssdev->type) {
case OMAP_DISPLAY_TYPE_DPI:
case OMAP_DISPLAY_TYPE_DBI:
case OMAP_DISPLAY_TYPE_SDI:
case OMAP_DISPLAY_TYPE_VENC:
case OMAP_DISPLAY_TYPE_HDMI:
default_get_overlay_fifo_thresholds(ovl->id, size,
burst_size, &oc->fifo_low,
&oc->fifo_high);
break;
#ifdef CONFIG_OMAP2_DSS_DSI
case OMAP_DISPLAY_TYPE_DSI:
dsi_get_overlay_fifo_thresholds(ovl->id, size,
burst_size, &oc->fifo_low,
&oc->fifo_high);
break;
#endif
default:
BUG();
}
}
r = 0;
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
spin_unlock_irqrestore(&dss_cache.lock, flags);
dispc_runtime_put();
return r;
}
static int dss_check_manager(struct omap_overlay_manager *mgr)
{
if (dss_has_feature(FEAT_ALPHA_FIXED_ZORDER)) {
if (mgr->info.partial_alpha_enabled && mgr->info.trans_enabled
&& mgr->info.trans_key_type !=
OMAP_DSS_COLOR_KEY_GFX_DST)
return -EINVAL;
}
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
dispc_mgr_enable(mgr->id, 1);
return 0;
}
static int dss_mgr_disable(struct omap_overlay_manager *mgr)
{
dispc_mgr_enable(mgr->id, 0);
return 0;
}
static void omap_dss_add_overlay_manager(struct omap_overlay_manager *manager)
{
++num_managers;
list_add_tail(&manager->list, &manager_list);
}
int dss_init_overlay_managers(struct platform_device *pdev)
{
int i, r;
spin_lock_init(&dss_cache.lock);
INIT_LIST_HEAD(&manager_list);
num_managers = 0;
for (i = 0; i < dss_feat_get_num_mgrs(); ++i) {
struct omap_overlay_manager *mgr;
mgr = kzalloc(sizeof(*mgr), GFP_KERNEL);
BUG_ON(mgr == NULL);
switch (i) {
case 0:
mgr->name = "lcd";
mgr->id = OMAP_DSS_CHANNEL_LCD;
break;
case 1:
mgr->name = "tv";
mgr->id = OMAP_DSS_CHANNEL_DIGIT;
break;
case 2:
mgr->name = "lcd2";
mgr->id = OMAP_DSS_CHANNEL_LCD2;
break;
}
mgr->set_device = &omap_dss_set_device;
mgr->unset_device = &omap_dss_unset_device;
mgr->apply = &omap_dss_mgr_apply;
mgr->set_manager_info = &omap_dss_mgr_set_info;
mgr->get_manager_info = &omap_dss_mgr_get_info;
mgr->wait_for_go = &dss_mgr_wait_for_go;
mgr->wait_for_vsync = &dss_mgr_wait_for_vsync;
mgr->enable = &dss_mgr_enable;
mgr->disable = &dss_mgr_disable;
mgr->caps = 0;
mgr->supported_displays =
dss_feat_get_supported_displays(mgr->id);
dss_overlay_setup_dispc_manager(mgr);
omap_dss_add_overlay_manager(mgr);
r = kobject_init_and_add(&mgr->kobj, &manager_ktype,
&pdev->dev.kobj, "manager%d", i);
if (r) {
DSSERR("failed to create sysfs file\n");
continue;
}
}
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
