int drm_name_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_minor *minor = node->minor;
struct drm_device *dev = minor->dev;
struct drm_master *master = minor->master;
if (!master)
return 0;
if (master->unique) {
seq_printf(m, "%s %s %s\n",
dev->driver->name,
dev_name(dev->dev), master->unique);
} else {
seq_printf(m, "%s %s\n",
dev->driver->name, dev_name(dev->dev));
}
return 0;
}
int drm_vm_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct drm_local_map *map;
struct drm_map_list *r_list;
const char *types[] = { "FB", "REG", "SHM", "AGP", "SG", "PCI" };
const char *type;
int i;
mutex_lock(&dev->struct_mutex);
seq_printf(m, "slot offset size type flags address mtrr\n\n");
i = 0;
list_for_each_entry(r_list, &dev->maplist, head) {
map = r_list->map;
if (!map)
continue;
if (map->type < 0 || map->type > 5)
type = "??";
else
type = types[map->type];
seq_printf(m, "%4d 0x%016llx 0x%08lx %4.4s 0x%02x 0x%08lx ",
i,
(unsigned long long)map->offset,
map->size, type, map->flags,
(unsigned long) r_list->user_token);
if (map->mtrr < 0)
seq_printf(m, "none\n");
else
seq_printf(m, "%4d\n", map->mtrr);
i++;
}
mutex_unlock(&dev->struct_mutex);
return 0;
}
int drm_bufs_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct drm_device_dma *dma;
int i, seg_pages;
mutex_lock(&dev->struct_mutex);
dma = dev->dma;
if (!dma) {
mutex_unlock(&dev->struct_mutex);
return 0;
}
seq_printf(m, " o size count free segs pages kB\n\n");
for (i = 0; i <= DRM_MAX_ORDER; i++) {
if (dma->bufs[i].buf_count) {
seg_pages = dma->bufs[i].seg_count * (1 << dma->bufs[i].page_order);
seq_printf(m, "%2d %8d %5d %5d %5d %5d %5ld\n",
i,
dma->bufs[i].buf_size,
dma->bufs[i].buf_count,
0,
dma->bufs[i].seg_count,
seg_pages,
seg_pages * PAGE_SIZE / 1024);
}
}
seq_printf(m, "\n");
for (i = 0; i < dma->buf_count; i++) {
if (i && !(i % 32))
seq_printf(m, "\n");
seq_printf(m, " %d", dma->buflist[i]->list);
}
seq_printf(m, "\n");
mutex_unlock(&dev->struct_mutex);
return 0;
}
int drm_vblank_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
int crtc;
mutex_lock(&dev->struct_mutex);
for (crtc = 0; crtc < dev->num_crtcs; crtc++) {
seq_printf(m, "CRTC %d enable: %d\n",
crtc, atomic_read(&dev->vblank[crtc].refcount));
seq_printf(m, "CRTC %d counter: %d\n",
crtc, drm_vblank_count(dev, crtc));
seq_printf(m, "CRTC %d last wait: %d\n",
crtc, dev->vblank[crtc].last_wait);
seq_printf(m, "CRTC %d in modeset: %d\n",
crtc, dev->vblank[crtc].inmodeset);
}
mutex_unlock(&dev->struct_mutex);
return 0;
}
int drm_clients_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct drm_file *priv;
seq_printf(m,
"%20s %5s %3s master a %5s %10s\n",
"command",
"pid",
"dev",
"uid",
"magic");
mutex_lock(&dev->struct_mutex);
list_for_each_entry_reverse(priv, &dev->filelist, lhead) {
struct task_struct *task;
rcu_read_lock();
task = pid_task(priv->pid, PIDTYPE_PID);
seq_printf(m, "%20s %5d %3d %c %c %5d %10u\n",
task ? task->comm : "<unknown>",
pid_vnr(priv->pid),
priv->minor->index,
priv->is_master ? 'y' : 'n',
priv->authenticated ? 'y' : 'n',
from_kuid_munged(seq_user_ns(m), priv->uid),
priv->magic);
rcu_read_unlock();
}
mutex_unlock(&dev->struct_mutex);
return 0;
}
static int drm_gem_one_name_info(int id, void *ptr, void *data)
{
struct drm_gem_object *obj = ptr;
struct seq_file *m = data;
seq_printf(m, "%6d %8zd %7d %8d\n",
obj->name, obj->size,
obj->handle_count,
atomic_read(&obj->refcount.refcount));
return 0;
}
int drm_gem_name_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
seq_printf(m, " name size handles refcount\n");
mutex_lock(&dev->object_name_lock);
idr_for_each(&dev->object_name_idr, drm_gem_one_name_info, m);
mutex_unlock(&dev->object_name_lock);
return 0;
}
