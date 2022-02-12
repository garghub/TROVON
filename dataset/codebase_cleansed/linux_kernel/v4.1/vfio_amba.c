static struct resource *get_amba_resource(struct vfio_platform_device *vdev,
int i)
{
struct amba_device *adev = (struct amba_device *) vdev->opaque;
if (i == 0)
return &adev->res;
return NULL;
}
static int get_amba_irq(struct vfio_platform_device *vdev, int i)
{
struct amba_device *adev = (struct amba_device *) vdev->opaque;
int ret = 0;
if (i < AMBA_NR_IRQS)
ret = adev->irq[i];
return ret ? ret : -ENXIO;
}
static int vfio_amba_probe(struct amba_device *adev, const struct amba_id *id)
{
struct vfio_platform_device *vdev;
int ret;
vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
if (!vdev)
return -ENOMEM;
vdev->name = kasprintf(GFP_KERNEL, "vfio-amba-%08x", adev->periphid);
if (!vdev->name) {
kfree(vdev);
return -ENOMEM;
}
vdev->opaque = (void *) adev;
vdev->flags = VFIO_DEVICE_FLAGS_AMBA;
vdev->get_resource = get_amba_resource;
vdev->get_irq = get_amba_irq;
ret = vfio_platform_probe_common(vdev, &adev->dev);
if (ret) {
kfree(vdev->name);
kfree(vdev);
}
return ret;
}
static int vfio_amba_remove(struct amba_device *adev)
{
struct vfio_platform_device *vdev;
vdev = vfio_platform_remove_common(&adev->dev);
if (vdev) {
kfree(vdev->name);
kfree(vdev);
return 0;
}
return -EINVAL;
}
