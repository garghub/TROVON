static int drm_proc_open(struct inode *inode, struct file *file)
{
struct drm_info_node* node = PDE_DATA(inode);
return single_open(file, node->info_ent->show, node);
}
static int drm_proc_create_files(const struct drm_info_list *files, int count,
struct proc_dir_entry *root, struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
struct proc_dir_entry *ent;
struct drm_info_node *tmp;
int i;
for (i = 0; i < count; i++) {
u32 features = files[i].driver_features;
if (features != 0 &&
(dev->driver->driver_features & features) != features)
continue;
tmp = kmalloc(sizeof(struct drm_info_node), GFP_KERNEL);
if (!tmp)
return -1;
tmp->minor = minor;
tmp->info_ent = &files[i];
list_add(&tmp->list, &minor->proc_nodes.list);
ent = proc_create_data(files[i].name, S_IRUGO, root,
&drm_proc_fops, tmp);
if (!ent) {
DRM_ERROR("Cannot create /proc/dri/%u/%s\n",
minor->index, files[i].name);
list_del(&tmp->list);
kfree(tmp);
return -1;
}
}
return 0;
}
int drm_proc_init(struct drm_minor *minor, struct proc_dir_entry *root)
{
char name[12];
int ret;
INIT_LIST_HEAD(&minor->proc_nodes.list);
sprintf(name, "%u", minor->index);
minor->proc_root = proc_mkdir(name, root);
if (!minor->proc_root) {
DRM_ERROR("Cannot create /proc/dri/%s\n", name);
return -1;
}
ret = drm_proc_create_files(drm_proc_list, DRM_PROC_ENTRIES,
minor->proc_root, minor);
if (ret) {
remove_proc_subtree(name, root);
minor->proc_root = NULL;
DRM_ERROR("Failed to create core drm proc files\n");
return ret;
}
return 0;
}
static int drm_proc_remove_files(const struct drm_info_list *files, int count,
struct drm_minor *minor)
{
struct list_head *pos, *q;
struct drm_info_node *tmp;
int i;
for (i = 0; i < count; i++) {
list_for_each_safe(pos, q, &minor->proc_nodes.list) {
tmp = list_entry(pos, struct drm_info_node, list);
if (tmp->info_ent == &files[i]) {
remove_proc_entry(files[i].name,
minor->proc_root);
list_del(pos);
kfree(tmp);
}
}
}
return 0;
}
int drm_proc_cleanup(struct drm_minor *minor, struct proc_dir_entry *root)
{
char name[64];
if (!root || !minor->proc_root)
return 0;
drm_proc_remove_files(drm_proc_list, DRM_PROC_ENTRIES, minor);
sprintf(name, "%d", minor->index);
remove_proc_subtree(name, root);
return 0;
}
