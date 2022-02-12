static int
nouveau_debugfs_vbios_image(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct nouveau_drm *drm = nouveau_drm(node->minor->dev);
int i;
for (i = 0; i < drm->vbios.length; i++)
seq_printf(m, "%c", drm->vbios.data[i]);
return 0;
}
int
nouveau_debugfs_init(struct drm_minor *minor)
{
drm_debugfs_create_files(nouveau_debugfs_list, NOUVEAU_DEBUGFS_ENTRIES,
minor->debugfs_root, minor);
return 0;
}
void
nouveau_debugfs_takedown(struct drm_minor *minor)
{
drm_debugfs_remove_files(nouveau_debugfs_list, NOUVEAU_DEBUGFS_ENTRIES,
minor);
}
