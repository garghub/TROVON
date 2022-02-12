static int
virtio_gpu_debugfs_irq_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct virtio_gpu_device *vgdev = node->minor->dev->dev_private;
seq_printf(m, "fence %llu %lld\n",
(u64)atomic64_read(&vgdev->fence_drv.last_seq),
vgdev->fence_drv.sync_seq);
return 0;
}
int
virtio_gpu_debugfs_init(struct drm_minor *minor)
{
drm_debugfs_create_files(virtio_gpu_debugfs_list,
VIRTIO_GPU_DEBUGFS_ENTRIES,
minor->debugfs_root, minor);
return 0;
}
void
virtio_gpu_debugfs_takedown(struct drm_minor *minor)
{
drm_debugfs_remove_files(virtio_gpu_debugfs_list,
VIRTIO_GPU_DEBUGFS_ENTRIES,
minor);
}
