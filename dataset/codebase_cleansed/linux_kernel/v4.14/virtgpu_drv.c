static int virtio_gpu_probe(struct virtio_device *vdev)
{
if (vgacon_text_force() && virtio_gpu_modeset == -1)
return -EINVAL;
if (virtio_gpu_modeset == 0)
return -EINVAL;
return drm_virtio_init(&driver, vdev);
}
static void virtio_gpu_remove(struct virtio_device *vdev)
{
struct drm_device *dev = vdev->priv;
drm_put_dev(dev);
}
static void virtio_gpu_config_changed(struct virtio_device *vdev)
{
struct drm_device *dev = vdev->priv;
struct virtio_gpu_device *vgdev = dev->dev_private;
schedule_work(&vgdev->config_changed_work);
}
