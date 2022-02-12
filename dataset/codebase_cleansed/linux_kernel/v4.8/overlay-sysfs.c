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
r = dispc_runtime_get();
if (r)
return r;
if (old_mgr) {
r = ovl->unset_manager(ovl);
if (r) {
DSSERR("detach failed\n");
goto err;
}
r = old_mgr->apply(old_mgr);
if (r)
goto err;
}
if (mgr) {
r = ovl->set_manager(ovl, mgr);
if (r) {
DSSERR("Failed to attach overlay\n");
goto err;
}
r = mgr->apply(mgr);
if (r)
goto err;
}
dispc_runtime_put();
return size;
err:
dispc_runtime_put();
return r;
}
static ssize_t overlay_input_size_show(struct omap_overlay *ovl, char *buf)
{
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d,%d\n",
info.width, info.height);
}
static ssize_t overlay_screen_width_show(struct omap_overlay *ovl, char *buf)
{
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d\n", info.screen_width);
}
static ssize_t overlay_position_show(struct omap_overlay *ovl, char *buf)
{
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d,%d\n",
info.pos_x, info.pos_y);
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
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d,%d\n",
info.out_width, info.out_height);
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
return snprintf(buf, PAGE_SIZE, "%d\n", ovl->is_enabled(ovl));
}
static ssize_t overlay_enabled_store(struct omap_overlay *ovl, const char *buf,
size_t size)
{
int r;
bool enable;
r = strtobool(buf, &enable);
if (r)
return r;
if (enable)
r = ovl->enable(ovl);
else
r = ovl->disable(ovl);
if (r)
return r;
return size;
}
static ssize_t overlay_global_alpha_show(struct omap_overlay *ovl, char *buf)
{
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d\n",
info.global_alpha);
}
static ssize_t overlay_global_alpha_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
u8 alpha;
struct omap_overlay_info info;
if ((ovl->caps & OMAP_DSS_OVL_CAP_GLOBAL_ALPHA) == 0)
return -ENODEV;
r = kstrtou8(buf, 0, &alpha);
if (r)
return r;
ovl->get_overlay_info(ovl, &info);
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
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d\n",
info.pre_mult_alpha);
}
static ssize_t overlay_pre_mult_alpha_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
u8 alpha;
struct omap_overlay_info info;
if ((ovl->caps & OMAP_DSS_OVL_CAP_PRE_MULT_ALPHA) == 0)
return -ENODEV;
r = kstrtou8(buf, 0, &alpha);
if (r)
return r;
ovl->get_overlay_info(ovl, &info);
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
static ssize_t overlay_zorder_show(struct omap_overlay *ovl, char *buf)
{
struct omap_overlay_info info;
ovl->get_overlay_info(ovl, &info);
return snprintf(buf, PAGE_SIZE, "%d\n", info.zorder);
}
static ssize_t overlay_zorder_store(struct omap_overlay *ovl,
const char *buf, size_t size)
{
int r;
u8 zorder;
struct omap_overlay_info info;
if ((ovl->caps & OMAP_DSS_OVL_CAP_ZORDER) == 0)
return -ENODEV;
r = kstrtou8(buf, 0, &zorder);
if (r)
return r;
ovl->get_overlay_info(ovl, &info);
info.zorder = zorder;
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
int dss_overlay_kobj_init(struct omap_overlay *ovl,
struct platform_device *pdev)
{
return kobject_init_and_add(&ovl->kobj, &overlay_ktype,
&pdev->dev.kobj, "overlay%d", ovl->id);
}
void dss_overlay_kobj_uninit(struct omap_overlay *ovl)
{
kobject_del(&ovl->kobj);
kobject_put(&ovl->kobj);
}
