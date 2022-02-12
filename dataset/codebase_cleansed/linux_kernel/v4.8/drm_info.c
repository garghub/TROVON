int drm_name_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_minor *minor = node->minor;
struct drm_device *dev = minor->dev;
struct drm_master *master;
mutex_lock(&dev->master_mutex);
master = dev->master;
if (!master)
goto out_unlock;
seq_printf(m, "%s", dev->driver->name);
if (dev->dev)
seq_printf(m, " dev=%s", dev_name(dev->dev));
if (master && master->unique)
seq_printf(m, " master=%s", master->unique);
if (dev->unique)
seq_printf(m, " unique=%s", dev->unique);
seq_printf(m, "\n");
out_unlock:
mutex_unlock(&dev->master_mutex);
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
mutex_lock(&dev->filelist_mutex);
list_for_each_entry_reverse(priv, &dev->filelist, lhead) {
struct task_struct *task;
rcu_read_lock();
task = pid_task(priv->pid, PIDTYPE_PID);
seq_printf(m, "%20s %5d %3d %c %c %5d %10u\n",
task ? task->comm : "<unknown>",
pid_vnr(priv->pid),
priv->minor->index,
drm_is_current_master(priv) ? 'y' : 'n',
priv->authenticated ? 'y' : 'n',
from_kuid_munged(seq_user_ns(m), priv->uid),
priv->magic);
rcu_read_unlock();
}
mutex_unlock(&dev->filelist_mutex);
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
