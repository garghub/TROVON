static ssize_t display_enabled_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
bool enabled = dssdev->state != OMAP_DSS_DISPLAY_DISABLED;
return snprintf(buf, PAGE_SIZE, "%d\n", enabled);
}
static ssize_t display_enabled_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
int r;
bool enabled;
r = strtobool(buf, &enabled);
if (r)
return r;
if (enabled != (dssdev->state != OMAP_DSS_DISPLAY_DISABLED)) {
if (enabled) {
r = dssdev->driver->enable(dssdev);
if (r)
return r;
} else {
dssdev->driver->disable(dssdev);
}
}
return size;
}
static ssize_t display_tear_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
return snprintf(buf, PAGE_SIZE, "%d\n",
dssdev->driver->get_te ?
dssdev->driver->get_te(dssdev) : 0);
}
static ssize_t display_tear_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
int r;
bool te;
if (!dssdev->driver->enable_te || !dssdev->driver->get_te)
return -ENOENT;
r = strtobool(buf, &te);
if (r)
return r;
r = dssdev->driver->enable_te(dssdev, te);
if (r)
return r;
return size;
}
static ssize_t display_timings_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct omap_video_timings t;
if (!dssdev->driver->get_timings)
return -ENOENT;
dssdev->driver->get_timings(dssdev, &t);
return snprintf(buf, PAGE_SIZE, "%u,%u/%u/%u/%u,%u/%u/%u/%u\n",
t.pixel_clock,
t.x_res, t.hfp, t.hbp, t.hsw,
t.y_res, t.vfp, t.vbp, t.vsw);
}
static ssize_t display_timings_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct omap_video_timings t = dssdev->panel.timings;
int r, found;
if (!dssdev->driver->set_timings || !dssdev->driver->check_timings)
return -ENOENT;
found = 0;
#ifdef CONFIG_OMAP2_DSS_VENC
if (strncmp("pal", buf, 3) == 0) {
t = omap_dss_pal_timings;
found = 1;
} else if (strncmp("ntsc", buf, 4) == 0) {
t = omap_dss_ntsc_timings;
found = 1;
}
#endif
if (!found && sscanf(buf, "%u,%hu/%hu/%hu/%hu,%hu/%hu/%hu/%hu",
&t.pixel_clock,
&t.x_res, &t.hfp, &t.hbp, &t.hsw,
&t.y_res, &t.vfp, &t.vbp, &t.vsw) != 9)
return -EINVAL;
r = dssdev->driver->check_timings(dssdev, &t);
if (r)
return r;
dssdev->driver->disable(dssdev);
dssdev->driver->set_timings(dssdev, &t);
r = dssdev->driver->enable(dssdev);
if (r)
return r;
return size;
}
static ssize_t display_rotate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
int rotate;
if (!dssdev->driver->get_rotate)
return -ENOENT;
rotate = dssdev->driver->get_rotate(dssdev);
return snprintf(buf, PAGE_SIZE, "%u\n", rotate);
}
static ssize_t display_rotate_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
int rot, r;
if (!dssdev->driver->set_rotate || !dssdev->driver->get_rotate)
return -ENOENT;
r = kstrtoint(buf, 0, &rot);
if (r)
return r;
r = dssdev->driver->set_rotate(dssdev, rot);
if (r)
return r;
return size;
}
static ssize_t display_mirror_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
int mirror;
if (!dssdev->driver->get_mirror)
return -ENOENT;
mirror = dssdev->driver->get_mirror(dssdev);
return snprintf(buf, PAGE_SIZE, "%u\n", mirror);
}
static ssize_t display_mirror_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
int r;
bool mirror;
if (!dssdev->driver->set_mirror || !dssdev->driver->get_mirror)
return -ENOENT;
r = strtobool(buf, &mirror);
if (r)
return r;
r = dssdev->driver->set_mirror(dssdev, mirror);
if (r)
return r;
return size;
}
static ssize_t display_wss_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
unsigned int wss;
if (!dssdev->driver->get_wss)
return -ENOENT;
wss = dssdev->driver->get_wss(dssdev);
return snprintf(buf, PAGE_SIZE, "0x%05x\n", wss);
}
static ssize_t display_wss_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
u32 wss;
int r;
if (!dssdev->driver->get_wss || !dssdev->driver->set_wss)
return -ENOENT;
r = kstrtou32(buf, 0, &wss);
if (r)
return r;
if (wss > 0xfffff)
return -EINVAL;
r = dssdev->driver->set_wss(dssdev, wss);
if (r)
return r;
return size;
}
int display_init_sysfs(struct platform_device *pdev,
struct omap_dss_device *dssdev)
{
struct device_attribute *attr;
int i, r;
i = 0;
while ((attr = display_sysfs_attrs[i++]) != NULL) {
r = device_create_file(&dssdev->dev, attr);
if (r) {
for (i = i - 2; i >= 0; i--) {
attr = display_sysfs_attrs[i];
device_remove_file(&dssdev->dev, attr);
}
DSSERR("failed to create sysfs file\n");
return r;
}
}
r = sysfs_create_link(&pdev->dev.kobj, &dssdev->dev.kobj,
dev_name(&dssdev->dev));
if (r) {
while ((attr = display_sysfs_attrs[i++]) != NULL)
device_remove_file(&dssdev->dev, attr);
DSSERR("failed to create sysfs display link\n");
return r;
}
return 0;
}
void display_uninit_sysfs(struct platform_device *pdev,
struct omap_dss_device *dssdev)
{
struct device_attribute *attr;
int i = 0;
sysfs_remove_link(&pdev->dev.kobj, dev_name(&dssdev->dev));
while ((attr = display_sysfs_attrs[i++]) != NULL)
device_remove_file(&dssdev->dev, attr);
}
