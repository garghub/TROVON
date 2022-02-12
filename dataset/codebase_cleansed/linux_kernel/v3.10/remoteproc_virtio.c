static void rproc_virtio_notify(struct virtqueue *vq)
{
struct rproc_vring *rvring = vq->priv;
struct rproc *rproc = rvring->rvdev->rproc;
int notifyid = rvring->notifyid;
dev_dbg(&rproc->dev, "kicking vq index: %d\n", notifyid);
rproc->ops->kick(rproc, notifyid);
}
irqreturn_t rproc_vq_interrupt(struct rproc *rproc, int notifyid)
{
struct rproc_vring *rvring;
dev_dbg(&rproc->dev, "vq index %d is interrupted\n", notifyid);
rvring = idr_find(&rproc->notifyids, notifyid);
if (!rvring || !rvring->vq)
return IRQ_NONE;
return vring_interrupt(0, rvring->vq);
}
static struct virtqueue *rp_find_vq(struct virtio_device *vdev,
unsigned id,
void (*callback)(struct virtqueue *vq),
const char *name)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct rproc *rproc = vdev_to_rproc(vdev);
struct device *dev = &rproc->dev;
struct rproc_vring *rvring;
struct virtqueue *vq;
void *addr;
int len, size, ret;
if (id >= ARRAY_SIZE(rvdev->vring))
return ERR_PTR(-EINVAL);
if (!name)
return NULL;
ret = rproc_alloc_vring(rvdev, id);
if (ret)
return ERR_PTR(ret);
rvring = &rvdev->vring[id];
addr = rvring->va;
len = rvring->len;
size = vring_size(len, rvring->align);
memset(addr, 0, size);
dev_dbg(dev, "vring%d: va %p qsz %d notifyid %d\n",
id, addr, len, rvring->notifyid);
vq = vring_new_virtqueue(id, len, rvring->align, vdev, false, addr,
rproc_virtio_notify, callback, name);
if (!vq) {
dev_err(dev, "vring_new_virtqueue %s failed\n", name);
rproc_free_vring(rvring);
return ERR_PTR(-ENOMEM);
}
rvring->vq = vq;
vq->priv = rvring;
return vq;
}
static void __rproc_virtio_del_vqs(struct virtio_device *vdev)
{
struct virtqueue *vq, *n;
struct rproc_vring *rvring;
list_for_each_entry_safe(vq, n, &vdev->vqs, list) {
rvring = vq->priv;
rvring->vq = NULL;
vring_del_virtqueue(vq);
rproc_free_vring(rvring);
}
}
static void rproc_virtio_del_vqs(struct virtio_device *vdev)
{
struct rproc *rproc = vdev_to_rproc(vdev);
rproc_shutdown(rproc);
__rproc_virtio_del_vqs(vdev);
}
static int rproc_virtio_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char *names[])
{
struct rproc *rproc = vdev_to_rproc(vdev);
int i, ret;
for (i = 0; i < nvqs; ++i) {
vqs[i] = rp_find_vq(vdev, i, callbacks[i], names[i]);
if (IS_ERR(vqs[i])) {
ret = PTR_ERR(vqs[i]);
goto error;
}
}
ret = rproc_boot(rproc);
if (ret) {
dev_err(&rproc->dev, "rproc_boot() failed %d\n", ret);
goto error;
}
return 0;
error:
__rproc_virtio_del_vqs(vdev);
return ret;
}
static u8 rproc_virtio_get_status(struct virtio_device *vdev)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
return rsc->status;
}
static void rproc_virtio_set_status(struct virtio_device *vdev, u8 status)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
rsc->status = status;
dev_dbg(&vdev->dev, "status: %d\n", status);
}
static void rproc_virtio_reset(struct virtio_device *vdev)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
rsc->status = 0;
dev_dbg(&vdev->dev, "reset !\n");
}
static u32 rproc_virtio_get_features(struct virtio_device *vdev)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
return rsc->dfeatures;
}
static void rproc_virtio_finalize_features(struct virtio_device *vdev)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
vring_transport_features(vdev);
rsc->gfeatures = vdev->features[0];
}
static void rproc_virtio_get(struct virtio_device *vdev, unsigned offset,
void *buf, unsigned len)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
void *cfg;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
cfg = &rsc->vring[rsc->num_of_vrings];
if (offset + len > rsc->config_len || offset + len < len) {
dev_err(&vdev->dev, "rproc_virtio_get: access out of bounds\n");
return;
}
memcpy(buf, cfg + offset, len);
}
static void rproc_virtio_set(struct virtio_device *vdev, unsigned offset,
const void *buf, unsigned len)
{
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct fw_rsc_vdev *rsc;
void *cfg;
rsc = (void *)rvdev->rproc->table_ptr + rvdev->rsc_offset;
cfg = &rsc->vring[rsc->num_of_vrings];
if (offset + len > rsc->config_len || offset + len < len) {
dev_err(&vdev->dev, "rproc_virtio_set: access out of bounds\n");
return;
}
memcpy(cfg + offset, buf, len);
}
static void rproc_vdev_release(struct device *dev)
{
struct virtio_device *vdev = dev_to_virtio(dev);
struct rproc_vdev *rvdev = vdev_to_rvdev(vdev);
struct rproc *rproc = vdev_to_rproc(vdev);
list_del(&rvdev->node);
kfree(rvdev);
put_device(&rproc->dev);
}
int rproc_add_virtio_dev(struct rproc_vdev *rvdev, int id)
{
struct rproc *rproc = rvdev->rproc;
struct device *dev = &rproc->dev;
struct virtio_device *vdev = &rvdev->vdev;
int ret;
vdev->id.device = id,
vdev->config = &rproc_virtio_config_ops,
vdev->dev.parent = dev;
vdev->dev.release = rproc_vdev_release;
get_device(&rproc->dev);
ret = register_virtio_device(vdev);
if (ret) {
put_device(&rproc->dev);
dev_err(dev, "failed to register vdev: %d\n", ret);
goto out;
}
dev_info(dev, "registered %s (type %d)\n", dev_name(&vdev->dev), id);
out:
return ret;
}
void rproc_remove_virtio_dev(struct rproc_vdev *rvdev)
{
unregister_virtio_device(&rvdev->vdev);
}
