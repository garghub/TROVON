static struct resource *get_platform_resource(struct vfio_platform_device *vdev,
int num)
{
struct platform_device *dev = (struct platform_device *) vdev->opaque;
int i;
for (i = 0; i < dev->num_resources; i++) {
struct resource *r = &dev->resource[i];
if (resource_type(r) & (IORESOURCE_MEM|IORESOURCE_IO)) {
if (!num)
return r;
num--;
}
}
return NULL;
}
static int get_platform_irq(struct vfio_platform_device *vdev, int i)
{
struct platform_device *pdev = (struct platform_device *) vdev->opaque;
return platform_get_irq(pdev, i);
}
static int vfio_platform_probe(struct platform_device *pdev)
{
struct vfio_platform_device *vdev;
int ret;
vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
if (!vdev)
return -ENOMEM;
vdev->opaque = (void *) pdev;
vdev->name = pdev->name;
vdev->flags = VFIO_DEVICE_FLAGS_PLATFORM;
vdev->get_resource = get_platform_resource;
vdev->get_irq = get_platform_irq;
vdev->parent_module = THIS_MODULE;
vdev->reset_required = reset_required;
ret = vfio_platform_probe_common(vdev, &pdev->dev);
if (ret)
kfree(vdev);
return ret;
}
static int vfio_platform_remove(struct platform_device *pdev)
{
struct vfio_platform_device *vdev;
vdev = vfio_platform_remove_common(&pdev->dev);
if (vdev) {
kfree(vdev);
return 0;
}
return -EINVAL;
}
