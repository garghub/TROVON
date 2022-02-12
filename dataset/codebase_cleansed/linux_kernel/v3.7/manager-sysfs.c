static ssize_t manager_name_show(struct omap_overlay_manager *mgr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", mgr->name);
}
static ssize_t manager_display_show(struct omap_overlay_manager *mgr, char *buf)
{
struct omap_dss_device *dssdev = mgr->get_device(mgr);
return snprintf(buf, PAGE_SIZE, "%s\n", dssdev ?
dssdev->name : "<none>");
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
int dss_manager_kobj_init(struct omap_overlay_manager *mgr,
struct platform_device *pdev)
{
return kobject_init_and_add(&mgr->kobj, &manager_ktype,
&pdev->dev.kobj, "manager%d", mgr->id);
}
void dss_manager_kobj_uninit(struct omap_overlay_manager *mgr)
{
kobject_del(&mgr->kobj);
kobject_put(&mgr->kobj);
}
