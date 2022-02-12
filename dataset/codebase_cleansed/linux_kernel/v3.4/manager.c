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
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
return snprintf(buf, PAGE_SIZE, "%#x\n", info.default_color);
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
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
key_type = info.trans_key_type;
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
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
return snprintf(buf, PAGE_SIZE, "%#x\n", info.trans_key);
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
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
return snprintf(buf, PAGE_SIZE, "%d\n", info.trans_enabled);
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
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
WARN_ON(!dss_has_feature(FEAT_ALPHA_FIXED_ZORDER));
return snprintf(buf, PAGE_SIZE, "%d\n",
info.partial_alpha_enabled);
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
struct omap_overlay_manager_info info;
mgr->get_manager_info(mgr, &info);
return snprintf(buf, PAGE_SIZE, "%d\n", info.cpr_enable);
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
static int dss_mgr_wait_for_vsync(struct omap_overlay_manager *mgr)
{
unsigned long timeout = msecs_to_jiffies(500);
u32 irq;
int r;
r = dispc_runtime_get();
if (r)
return r;
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
r = omap_dispc_wait_for_irq_interruptible_timeout(irq, timeout);
dispc_runtime_put();
return r;
}
int dss_init_overlay_managers(struct platform_device *pdev)
{
int i, r;
num_managers = dss_feat_get_num_mgrs();
managers = kzalloc(sizeof(struct omap_overlay_manager) * num_managers,
GFP_KERNEL);
BUG_ON(managers == NULL);
for (i = 0; i < num_managers; ++i) {
struct omap_overlay_manager *mgr = &managers[i];
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
mgr->set_device = &dss_mgr_set_device;
mgr->unset_device = &dss_mgr_unset_device;
mgr->apply = &omap_dss_mgr_apply;
mgr->set_manager_info = &dss_mgr_set_info;
mgr->get_manager_info = &dss_mgr_get_info;
mgr->wait_for_go = &dss_mgr_wait_for_go;
mgr->wait_for_vsync = &dss_mgr_wait_for_vsync;
mgr->caps = 0;
mgr->supported_displays =
dss_feat_get_supported_displays(mgr->id);
INIT_LIST_HEAD(&mgr->overlays);
r = kobject_init_and_add(&mgr->kobj, &manager_ktype,
&pdev->dev.kobj, "manager%d", i);
if (r)
DSSERR("failed to create sysfs file\n");
}
return 0;
}
void dss_uninit_overlay_managers(struct platform_device *pdev)
{
int i;
for (i = 0; i < num_managers; ++i) {
struct omap_overlay_manager *mgr = &managers[i];
kobject_del(&mgr->kobj);
kobject_put(&mgr->kobj);
}
kfree(managers);
managers = NULL;
num_managers = 0;
}
int omap_dss_get_num_overlay_managers(void)
{
return num_managers;
}
struct omap_overlay_manager *omap_dss_get_overlay_manager(int num)
{
if (num >= num_managers)
return NULL;
return &managers[num];
}
int dss_mgr_simple_check(struct omap_overlay_manager *mgr,
const struct omap_overlay_manager_info *info)
{
if (dss_has_feature(FEAT_ALPHA_FIXED_ZORDER)) {
if (info->partial_alpha_enabled && info->trans_enabled
&& info->trans_key_type != OMAP_DSS_COLOR_KEY_GFX_DST) {
DSSERR("check_manager: illegal transparency key\n");
return -EINVAL;
}
}
return 0;
}
static int dss_mgr_check_zorder(struct omap_overlay_manager *mgr,
struct omap_overlay_info **overlay_infos)
{
struct omap_overlay *ovl1, *ovl2;
struct omap_overlay_info *info1, *info2;
list_for_each_entry(ovl1, &mgr->overlays, list) {
info1 = overlay_infos[ovl1->id];
if (info1 == NULL)
continue;
list_for_each_entry(ovl2, &mgr->overlays, list) {
if (ovl1 == ovl2)
continue;
info2 = overlay_infos[ovl2->id];
if (info2 == NULL)
continue;
if (info1->zorder == info2->zorder) {
DSSERR("overlays %d and %d have the same "
"zorder %d\n",
ovl1->id, ovl2->id, info1->zorder);
return -EINVAL;
}
}
}
return 0;
}
int dss_mgr_check(struct omap_overlay_manager *mgr,
struct omap_dss_device *dssdev,
struct omap_overlay_manager_info *info,
struct omap_overlay_info **overlay_infos)
{
struct omap_overlay *ovl;
int r;
if (dss_has_feature(FEAT_ALPHA_FREE_ZORDER)) {
r = dss_mgr_check_zorder(mgr, overlay_infos);
if (r)
return r;
}
list_for_each_entry(ovl, &mgr->overlays, list) {
struct omap_overlay_info *oi;
int r;
oi = overlay_infos[ovl->id];
if (oi == NULL)
continue;
r = dss_ovl_check(ovl, oi, dssdev);
if (r)
return r;
}
return 0;
}
