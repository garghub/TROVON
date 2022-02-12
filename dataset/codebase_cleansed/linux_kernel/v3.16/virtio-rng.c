static void random_recv_done(struct virtqueue *vq)
{
struct virtrng_info *vi = vq->vdev->priv;
if (!virtqueue_get_buf(vi->vq, &vi->data_avail))
return;
complete(&vi->have_data);
}
static void register_buffer(struct virtrng_info *vi, u8 *buf, size_t size)
{
struct scatterlist sg;
sg_init_one(&sg, buf, size);
virtqueue_add_inbuf(vi->vq, &sg, 1, buf, GFP_KERNEL);
virtqueue_kick(vi->vq);
}
static int virtio_read(struct hwrng *rng, void *buf, size_t size, bool wait)
{
int ret;
struct virtrng_info *vi = (struct virtrng_info *)rng->priv;
if (unlikely(!probe_done))
return 0;
if (!vi->busy) {
vi->busy = true;
init_completion(&vi->have_data);
register_buffer(vi, buf, size);
}
if (!wait)
return 0;
ret = wait_for_completion_killable(&vi->have_data);
if (ret < 0)
return ret;
vi->busy = false;
return vi->data_avail;
}
static void virtio_cleanup(struct hwrng *rng)
{
struct virtrng_info *vi = (struct virtrng_info *)rng->priv;
if (vi->busy)
wait_for_completion(&vi->have_data);
}
static int probe_common(struct virtio_device *vdev)
{
int err, index;
struct virtrng_info *vi = NULL;
vi = kzalloc(sizeof(struct virtrng_info), GFP_KERNEL);
if (!vi)
return -ENOMEM;
vi->index = index = ida_simple_get(&rng_index_ida, 0, 0, GFP_KERNEL);
if (index < 0) {
kfree(vi);
return index;
}
sprintf(vi->name, "virtio_rng.%d", index);
init_completion(&vi->have_data);
vi->hwrng = (struct hwrng) {
.read = virtio_read,
.cleanup = virtio_cleanup,
.priv = (unsigned long)vi,
.name = vi->name,
};
vdev->priv = vi;
vi->vq = virtio_find_single_vq(vdev, random_recv_done, "input");
if (IS_ERR(vi->vq)) {
err = PTR_ERR(vi->vq);
vi->vq = NULL;
kfree(vi);
ida_simple_remove(&rng_index_ida, index);
return err;
}
err = hwrng_register(&vi->hwrng);
if (err) {
vdev->config->del_vqs(vdev);
vi->vq = NULL;
kfree(vi);
ida_simple_remove(&rng_index_ida, index);
return err;
}
probe_done = true;
return 0;
}
static void remove_common(struct virtio_device *vdev)
{
struct virtrng_info *vi = vdev->priv;
vdev->config->reset(vdev);
vi->busy = false;
hwrng_unregister(&vi->hwrng);
vdev->config->del_vqs(vdev);
ida_simple_remove(&rng_index_ida, vi->index);
kfree(vi);
}
static int virtrng_probe(struct virtio_device *vdev)
{
return probe_common(vdev);
}
static void virtrng_remove(struct virtio_device *vdev)
{
remove_common(vdev);
}
static int virtrng_freeze(struct virtio_device *vdev)
{
remove_common(vdev);
return 0;
}
static int virtrng_restore(struct virtio_device *vdev)
{
return probe_common(vdev);
}
