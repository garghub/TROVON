static int drm_debugfs_open(struct inode *inode, struct file *file)
{
struct drm_info_node *node = inode->i_private;
return single_open(file, node->info_ent->show, node);
}
int drm_debugfs_create_files(const struct drm_info_list *files, int count,
struct dentry *root, struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
struct dentry *ent;
struct drm_info_node *tmp;
int i, ret;
for (i = 0; i < count; i++) {
u32 features = files[i].driver_features;
if (features != 0 &&
(dev->driver->driver_features & features) != features)
continue;
tmp = kmalloc(sizeof(struct drm_info_node), GFP_KERNEL);
if (tmp == NULL) {
ret = -1;
goto fail;
}
ent = debugfs_create_file(files[i].name, S_IFREG | S_IRUGO,
root, tmp, &drm_debugfs_fops);
if (!ent) {
DRM_ERROR("Cannot create /sys/kernel/debug/dri/%pd/%s\n",
root, files[i].name);
kfree(tmp);
ret = -1;
goto fail;
}
tmp->minor = minor;
tmp->dent = ent;
tmp->info_ent = &files[i];
mutex_lock(&minor->debugfs_lock);
list_add(&tmp->list, &minor->debugfs_list);
mutex_unlock(&minor->debugfs_lock);
}
return 0;
fail:
drm_debugfs_remove_files(files, count, minor);
return ret;
}
int drm_debugfs_init(struct drm_minor *minor, int minor_id,
struct dentry *root)
{
struct drm_device *dev = minor->dev;
char name[64];
int ret;
INIT_LIST_HEAD(&minor->debugfs_list);
mutex_init(&minor->debugfs_lock);
sprintf(name, "%d", minor_id);
minor->debugfs_root = debugfs_create_dir(name, root);
if (!minor->debugfs_root) {
DRM_ERROR("Cannot create /sys/kernel/debug/dri/%s\n", name);
return -1;
}
ret = drm_debugfs_create_files(drm_debugfs_list, DRM_DEBUGFS_ENTRIES,
minor->debugfs_root, minor);
if (ret) {
debugfs_remove(minor->debugfs_root);
minor->debugfs_root = NULL;
DRM_ERROR("Failed to create core drm debugfs files\n");
return ret;
}
if (drm_core_check_feature(dev, DRIVER_ATOMIC)) {
ret = drm_atomic_debugfs_init(minor);
if (ret) {
DRM_ERROR("Failed to create atomic debugfs files\n");
return ret;
}
}
if (dev->driver->debugfs_init) {
ret = dev->driver->debugfs_init(minor);
if (ret) {
DRM_ERROR("DRM: Driver failed to initialize "
"/sys/kernel/debug/dri.\n");
return ret;
}
}
return 0;
}
int drm_debugfs_remove_files(const struct drm_info_list *files, int count,
struct drm_minor *minor)
{
struct list_head *pos, *q;
struct drm_info_node *tmp;
int i;
mutex_lock(&minor->debugfs_lock);
for (i = 0; i < count; i++) {
list_for_each_safe(pos, q, &minor->debugfs_list) {
tmp = list_entry(pos, struct drm_info_node, list);
if (tmp->info_ent == &files[i]) {
debugfs_remove(tmp->dent);
list_del(pos);
kfree(tmp);
}
}
}
mutex_unlock(&minor->debugfs_lock);
return 0;
}
int drm_debugfs_cleanup(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
int ret;
if (!minor->debugfs_root)
return 0;
if (dev->driver->debugfs_cleanup)
dev->driver->debugfs_cleanup(minor);
if (drm_core_check_feature(dev, DRIVER_ATOMIC)) {
ret = drm_atomic_debugfs_cleanup(minor);
if (ret) {
DRM_ERROR("DRM: Failed to remove atomic debugfs entries\n");
return ret;
}
}
drm_debugfs_remove_files(drm_debugfs_list, DRM_DEBUGFS_ENTRIES, minor);
debugfs_remove(minor->debugfs_root);
minor->debugfs_root = NULL;
return 0;
}
static int connector_show(struct seq_file *m, void *data)
{
struct drm_connector *connector = m->private;
const char *status;
switch (connector->force) {
case DRM_FORCE_ON:
status = "on\n";
break;
case DRM_FORCE_ON_DIGITAL:
status = "digital\n";
break;
case DRM_FORCE_OFF:
status = "off\n";
break;
case DRM_FORCE_UNSPECIFIED:
status = "unspecified\n";
break;
default:
return 0;
}
seq_puts(m, status);
return 0;
}
static int connector_open(struct inode *inode, struct file *file)
{
struct drm_connector *dev = inode->i_private;
return single_open(file, connector_show, dev);
}
static ssize_t connector_write(struct file *file, const char __user *ubuf,
size_t len, loff_t *offp)
{
struct seq_file *m = file->private_data;
struct drm_connector *connector = m->private;
char buf[12];
if (len > sizeof(buf) - 1)
return -EINVAL;
if (copy_from_user(buf, ubuf, len))
return -EFAULT;
buf[len] = '\0';
if (!strcmp(buf, "on"))
connector->force = DRM_FORCE_ON;
else if (!strcmp(buf, "digital"))
connector->force = DRM_FORCE_ON_DIGITAL;
else if (!strcmp(buf, "off"))
connector->force = DRM_FORCE_OFF;
else if (!strcmp(buf, "unspecified"))
connector->force = DRM_FORCE_UNSPECIFIED;
else
return -EINVAL;
return len;
}
static int edid_show(struct seq_file *m, void *data)
{
struct drm_connector *connector = m->private;
struct drm_property_blob *edid = connector->edid_blob_ptr;
if (connector->override_edid && edid)
seq_write(m, edid->data, edid->length);
return 0;
}
static int edid_open(struct inode *inode, struct file *file)
{
struct drm_connector *dev = inode->i_private;
return single_open(file, edid_show, dev);
}
static ssize_t edid_write(struct file *file, const char __user *ubuf,
size_t len, loff_t *offp)
{
struct seq_file *m = file->private_data;
struct drm_connector *connector = m->private;
char *buf;
struct edid *edid;
int ret;
buf = memdup_user(ubuf, len);
if (IS_ERR(buf))
return PTR_ERR(buf);
edid = (struct edid *) buf;
if (len == 5 && !strncmp(buf, "reset", 5)) {
connector->override_edid = false;
ret = drm_mode_connector_update_edid_property(connector, NULL);
} else if (len < EDID_LENGTH ||
EDID_LENGTH * (1 + edid->extensions) > len)
ret = -EINVAL;
else {
connector->override_edid = false;
ret = drm_mode_connector_update_edid_property(connector, edid);
if (!ret)
connector->override_edid = true;
}
kfree(buf);
return (ret) ? ret : len;
}
int drm_debugfs_connector_add(struct drm_connector *connector)
{
struct drm_minor *minor = connector->dev->primary;
struct dentry *root, *ent;
if (!minor->debugfs_root)
return -1;
root = debugfs_create_dir(connector->name, minor->debugfs_root);
if (!root)
return -ENOMEM;
connector->debugfs_entry = root;
ent = debugfs_create_file("force", S_IRUGO | S_IWUSR, root, connector,
&drm_connector_fops);
if (!ent)
goto error;
ent = debugfs_create_file("edid_override", S_IRUGO | S_IWUSR, root,
connector, &drm_edid_fops);
if (!ent)
goto error;
return 0;
error:
debugfs_remove_recursive(connector->debugfs_entry);
connector->debugfs_entry = NULL;
return -ENOMEM;
}
void drm_debugfs_connector_remove(struct drm_connector *connector)
{
if (!connector->debugfs_entry)
return;
debugfs_remove_recursive(connector->debugfs_entry);
connector->debugfs_entry = NULL;
}
int drm_debugfs_crtc_add(struct drm_crtc *crtc)
{
struct drm_minor *minor = crtc->dev->primary;
struct dentry *root;
char *name;
name = kasprintf(GFP_KERNEL, "crtc-%d", crtc->index);
if (!name)
return -ENOMEM;
root = debugfs_create_dir(name, minor->debugfs_root);
kfree(name);
if (!root)
return -ENOMEM;
crtc->debugfs_entry = root;
if (drm_debugfs_crtc_crc_add(crtc))
goto error;
return 0;
error:
drm_debugfs_crtc_remove(crtc);
return -ENOMEM;
}
void drm_debugfs_crtc_remove(struct drm_crtc *crtc)
{
debugfs_remove_recursive(crtc->debugfs_entry);
crtc->debugfs_entry = NULL;
}
