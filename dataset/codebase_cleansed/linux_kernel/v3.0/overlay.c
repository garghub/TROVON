static ssize_t overlay_name_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", ovl->name);
}
static ssize_t overlay_manager_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n",
ovl->manager ? ovl->manager->name : "<none>");
}
static ssize_t overlay_manager_store(struct omap_overlay *ovl, const char *buf,
size_t size)
{
int i, r;
struct omap_overlay_manager *mgr = NULL;
struct omap_overlay_manager *old_mgr;
int len = size;
if (buf[size-1] == '\n')
--len;
if (len > 0) {
for (i = 0; i < omap_dss_get_num_overlay_managers(); ++i) {
mgr = omap_dss_get_overlay_manager(i);
if (sysfs_streq(buf, mgr->name))
break;
mgr = NULL;
}
}
if (len > 0 && mgr == NULL)
return -EINVAL;
if (mgr)
DSSDBG("manager %s found\n", mgr->name);
if (mgr == ovl->manager)
return size;
old_mgr = ovl->manager;
if (old_mgr) {
r = ovl->unset_manager(ovl);
if (r) {
DSSERR("detach failed\n");
return r;
}
r = old_mgr->apply(old_mgr);
if (r)
return r;
}
if (mgr) {
r = ovl->set_manager(ovl, mgr);
if (r) {
DSSERR("Failed to attach overlay\n");
return r;
}
r = mgr->apply(mgr);
if (r)
return r;
}
return size;
}
static ssize_t overlay_input_size_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d,%d\n",
ovl->info.width, ovl->info.height);
}
static ssize_t overlay_screen_width_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ovl->info.screen_width);
}
static ssize_t overlay_position_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d,%d\n",
ovl->info.pos_x, ovl->info.pos_y);
}
static ssize_t overlay_position_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
char *last;
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
info.pos_x = simple_strtoul(buf, &last, 10);
++last;
if (last - buf >= size)
return -EINVAL;
info.pos_y = simple_strtoul(last, &last, 10);
r = ovl->set_overlay_info(ovl, &info);
if (r)
return r;
if (ovl->manager) {
r = ovl->manager->apply(ovl->manager);
if (r)
return r;
}
return size;
}
static ssize_t overlay_output_size_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d,%d\n",
ovl->info.out_width, ovl->info.out_height);
}
static ssize_t overlay_output_size_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
char *last;
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
info.out_width = simple_strtoul(buf, &last, 10);
++last;
if (last - buf >= size)
return -EINVAL;
info.out_height = simple_strtoul(last, &last, 10);
r = ovl->set_overlay_info(ovl, &info);
if (r)
return r;
if (ovl->manager) {
r = ovl->manager->apply(ovl->manager);
if (r)
return r;
}
return size;
}
static ssize_t overlay_enabled_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ovl->info.enabled);
}
static ssize_t overlay_enabled_store(struct omap_overlay *ovl, const char *buf,
size_t size)
{
int r, enable;
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
r = kstrtoint(buf, 0, &enable);
if (r)
return r;
info.enabled = !!enable;
r = ovl->set_overlay_info(ovl, &info);
if (r)
return r;
if (ovl->manager) {
r = ovl->manager->apply(ovl->manager);
if (r)
return r;
}
return size;
}
static ssize_t overlay_global_alpha_show(struct omap_overlay *ovl, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n",
ovl->info.global_alpha);
}
static ssize_t overlay_global_alpha_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
u8 alpha;
struct omap_overlay_info info;
r = kstrtou8(buf, 0, &alpha);
if (r)
return r;
ovl->get_overlay_info(ovl, &info);
if (!dss_has_feature(FEAT_GLOBAL_ALPHA_VID1) &&
ovl->id == OMAP_DSS_VIDEO1)
info.global_alpha = 255;
else
info.global_alpha = alpha;
r = ovl->set_overlay_info(ovl, &info);
if (r)
return r;
if (ovl->manager) {
r = ovl->manager->apply(ovl->manager);
if (r)
return r;
}
return size;
}
static ssize_t overlay_pre_mult_alpha_show(struct omap_overlay *ovl,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n",
ovl->info.pre_mult_alpha);
}
static ssize_t overlay_pre_mult_alpha_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
u8 alpha;
struct omap_overlay_info info;
r = kstrtou8(buf, 0, &alpha);
if (r)
return r;
ovl->get_overlay_info(ovl, &info);
if (!dss_has_feature(FEAT_GLOBAL_ALPHA_VID1) &&
ovl->id == OMAP_DSS_VIDEO1)
info.pre_mult_alpha = 0;
else
info.pre_mult_alpha = alpha;
r = ovl->set_overlay_info(ovl, &info);
if (r)
return r;
if (ovl->manager) {
r = ovl->manager->apply(ovl->manager);
if (r)
return r;
}
return size;
}
static ssize_t overlay_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct omap_overlay *overlay;
struct overlay_attribute *overlay_attr;
overlay = container_of(kobj, struct omap_overlay, kobj);
overlay_attr = container_of(attr, struct overlay_attribute, attr);
if (!overlay_attr->show)
return -ENOENT;
return overlay_attr->show(overlay, buf);
}
static ssize_t overlay_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t size)
{
struct omap_overlay *overlay;
struct overlay_attribute *overlay_attr;
overlay = container_of(kobj, struct omap_overlay, kobj);
overlay_attr = container_of(attr, struct overlay_attribute, attr);
if (!overlay_attr->store)
return -ENOENT;
return overlay_attr->store(overlay, buf, size);
}
int dss_check_overlay(struct omap_overlay *ovl, struct omap_dss_device *dssdev)
{
struct omap_overlay_info *info;
u16 outw, outh;
u16 dw, dh;
if (!dssdev)
return 0;
if (!ovl->info.enabled)
return 0;
info = &ovl->info;
if (info->paddr == 0) {
DSSDBG("check_overlay failed: paddr 0\n");
return -EINVAL;
}
dssdev->driver->get_resolution(dssdev, &dw, &dh);
DSSDBG("check_overlay %d: (%d,%d %dx%d -> %dx%d) disp (%dx%d)\n",
ovl->id,
info->pos_x, info->pos_y,
info->width, info->height,
info->out_width, info->out_height,
dw, dh);
if ((ovl->caps & OMAP_DSS_OVL_CAP_SCALE) == 0) {
outw = info->width;
outh = info->height;
} else {
if (info->out_width == 0)
outw = info->width;
else
outw = info->out_width;
if (info->out_height == 0)
outh = info->height;
else
outh = info->out_height;
}
if (dw < info->pos_x + outw) {
DSSDBG("check_overlay failed 1: %d < %d + %d\n",
dw, info->pos_x, outw);
return -EINVAL;
}
if (dh < info->pos_y + outh) {
DSSDBG("check_overlay failed 2: %d < %d + %d\n",
dh, info->pos_y, outh);
return -EINVAL;
}
if ((ovl->supported_modes & info->color_mode) == 0) {
DSSERR("overlay doesn't support mode %d\n", info->color_mode);
return -EINVAL;
}
return 0;
}
static int dss_ovl_set_overlay_info(struct omap_overlay *ovl,
struct omap_overlay_info *info)
{
int r;
struct omap_overlay_info old_info;
old_info = ovl->info;
ovl->info = *info;
if (ovl->manager) {
r = dss_check_overlay(ovl, ovl->manager->device);
if (r) {
ovl->info = old_info;
return r;
}
}
ovl->info_dirty = true;
return 0;
}
static void dss_ovl_get_overlay_info(struct omap_overlay *ovl,
struct omap_overlay_info *info)
{
*info = ovl->info;
}
static int dss_ovl_wait_for_go(struct omap_overlay *ovl)
{
return dss_mgr_wait_for_go_ovl(ovl);
}
static int omap_dss_set_manager(struct omap_overlay *ovl,
struct omap_overlay_manager *mgr)
{
if (!mgr)
return -EINVAL;
if (ovl->manager) {
DSSERR("overlay '%s' already has a manager '%s'\n",
ovl->name, ovl->manager->name);
return -EINVAL;
}
if (ovl->info.enabled) {
DSSERR("overlay has to be disabled to change the manager\n");
return -EINVAL;
}
ovl->manager = mgr;
dss_clk_enable(DSS_CLK_ICK | DSS_CLK_FCK);
dispc_set_channel_out(ovl->id, mgr->id);
dss_clk_disable(DSS_CLK_ICK | DSS_CLK_FCK);
return 0;
}
static int omap_dss_unset_manager(struct omap_overlay *ovl)
{
int r;
if (!ovl->manager) {
DSSERR("failed to detach overlay: manager not set\n");
return -EINVAL;
}
if (ovl->info.enabled) {
DSSERR("overlay has to be disabled to unset the manager\n");
return -EINVAL;
}
r = ovl->wait_for_go(ovl);
if (r)
return r;
ovl->manager = NULL;
return 0;
}
int omap_dss_get_num_overlays(void)
{
return num_overlays;
}
struct omap_overlay *omap_dss_get_overlay(int num)
{
int i = 0;
struct omap_overlay *ovl;
list_for_each_entry(ovl, &overlay_list, list) {
if (i++ == num)
return ovl;
}
return NULL;
}
static void omap_dss_add_overlay(struct omap_overlay *overlay)
{
++num_overlays;
list_add_tail(&overlay->list, &overlay_list);
}
void dss_overlay_setup_dispc_manager(struct omap_overlay_manager *mgr)
{
mgr->num_overlays = dss_feat_get_num_ovls();
mgr->overlays = dispc_overlays;
}
void dss_overlay_setup_l4_manager(struct omap_overlay_manager *mgr)
{
mgr->num_overlays = 1;
mgr->overlays = l4_overlays;
}
void dss_init_overlays(struct platform_device *pdev)
{
int i, r;
INIT_LIST_HEAD(&overlay_list);
num_overlays = 0;
for (i = 0; i < dss_feat_get_num_ovls(); ++i) {
struct omap_overlay *ovl;
ovl = kzalloc(sizeof(*ovl), GFP_KERNEL);
BUG_ON(ovl == NULL);
switch (i) {
case 0:
ovl->name = "gfx";
ovl->id = OMAP_DSS_GFX;
ovl->caps = OMAP_DSS_OVL_CAP_DISPC;
ovl->info.global_alpha = 255;
break;
case 1:
ovl->name = "vid1";
ovl->id = OMAP_DSS_VIDEO1;
ovl->caps = OMAP_DSS_OVL_CAP_SCALE |
OMAP_DSS_OVL_CAP_DISPC;
ovl->info.global_alpha = 255;
break;
case 2:
ovl->name = "vid2";
ovl->id = OMAP_DSS_VIDEO2;
ovl->caps = OMAP_DSS_OVL_CAP_SCALE |
OMAP_DSS_OVL_CAP_DISPC;
ovl->info.global_alpha = 255;
break;
}
ovl->set_manager = &omap_dss_set_manager;
ovl->unset_manager = &omap_dss_unset_manager;
ovl->set_overlay_info = &dss_ovl_set_overlay_info;
ovl->get_overlay_info = &dss_ovl_get_overlay_info;
ovl->wait_for_go = &dss_ovl_wait_for_go;
ovl->supported_modes =
dss_feat_get_supported_color_modes(ovl->id);
omap_dss_add_overlay(ovl);
r = kobject_init_and_add(&ovl->kobj, &overlay_ktype,
&pdev->dev.kobj, "overlay%d", i);
if (r) {
DSSERR("failed to create sysfs file\n");
continue;
}
dispc_overlays[i] = ovl;
}
#ifdef L4_EXAMPLE
{
struct omap_overlay *ovl;
ovl = kzalloc(sizeof(*ovl), GFP_KERNEL);
BUG_ON(ovl == NULL);
ovl->name = "l4";
ovl->supported_modes = OMAP_DSS_COLOR_RGB24U;
ovl->set_manager = &omap_dss_set_manager;
ovl->unset_manager = &omap_dss_unset_manager;
ovl->set_overlay_info = &dss_ovl_set_overlay_info;
ovl->get_overlay_info = &dss_ovl_get_overlay_info;
omap_dss_add_overlay(ovl);
r = kobject_init_and_add(&ovl->kobj, &overlay_ktype,
&pdev->dev.kobj, "overlayl4");
if (r)
DSSERR("failed to create sysfs file\n");
l4_overlays[0] = ovl;
}
#endif
}
void dss_recheck_connections(struct omap_dss_device *dssdev, bool force)
{
int i;
struct omap_overlay_manager *lcd_mgr;
struct omap_overlay_manager *tv_mgr;
struct omap_overlay_manager *lcd2_mgr = NULL;
struct omap_overlay_manager *mgr = NULL;
lcd_mgr = omap_dss_get_overlay_manager(OMAP_DSS_OVL_MGR_LCD);
tv_mgr = omap_dss_get_overlay_manager(OMAP_DSS_OVL_MGR_TV);
if (dss_has_feature(FEAT_MGR_LCD2))
lcd2_mgr = omap_dss_get_overlay_manager(OMAP_DSS_OVL_MGR_LCD2);
if (dssdev->channel == OMAP_DSS_CHANNEL_LCD2) {
if (!lcd2_mgr->device || force) {
if (lcd2_mgr->device)
lcd2_mgr->unset_device(lcd2_mgr);
lcd2_mgr->set_device(lcd2_mgr, dssdev);
mgr = lcd2_mgr;
}
} else if (dssdev->type != OMAP_DISPLAY_TYPE_VENC
&& dssdev->type != OMAP_DISPLAY_TYPE_HDMI) {
if (!lcd_mgr->device || force) {
if (lcd_mgr->device)
lcd_mgr->unset_device(lcd_mgr);
lcd_mgr->set_device(lcd_mgr, dssdev);
mgr = lcd_mgr;
}
}
if (dssdev->type == OMAP_DISPLAY_TYPE_VENC
|| dssdev->type == OMAP_DISPLAY_TYPE_HDMI) {
if (!tv_mgr->device || force) {
if (tv_mgr->device)
tv_mgr->unset_device(tv_mgr);
tv_mgr->set_device(tv_mgr, dssdev);
mgr = tv_mgr;
}
}
if (mgr) {
for (i = 0; i < dss_feat_get_num_ovls(); i++) {
struct omap_overlay *ovl;
ovl = omap_dss_get_overlay(i);
if (!ovl->manager || force) {
if (ovl->manager)
omap_dss_unset_manager(ovl);
omap_dss_set_manager(ovl, mgr);
}
}
}
}
void dss_uninit_overlays(struct platform_device *pdev)
{
struct omap_overlay *ovl;
while (!list_empty(&overlay_list)) {
ovl = list_first_entry(&overlay_list,
struct omap_overlay, list);
list_del(&ovl->list);
kobject_del(&ovl->kobj);
kobject_put(&ovl->kobj);
kfree(ovl);
}
num_overlays = 0;
}
