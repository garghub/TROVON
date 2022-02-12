static void random_recv_done(struct virtqueue *vq)
{
if (!virtqueue_get_buf(vq, &data_avail))
return;
complete(&have_data);
}
static void register_buffer(u8 *buf, size_t size)
{
struct scatterlist sg;
sg_init_one(&sg, buf, size);
if (virtqueue_add_inbuf(vq, &sg, 1, buf, GFP_KERNEL) < 0)
BUG();
virtqueue_kick(vq);
}
static int virtio_read(struct hwrng *rng, void *buf, size_t size, bool wait)
{
int ret;
if (!busy) {
busy = true;
init_completion(&have_data);
register_buffer(buf, size);
}
if (!wait)
return 0;
ret = wait_for_completion_killable(&have_data);
if (ret < 0)
return ret;
busy = false;
return data_avail;
}
static void virtio_cleanup(struct hwrng *rng)
{
if (busy)
wait_for_completion(&have_data);
}
static int probe_common(struct virtio_device *vdev)
{
int err;
if (vq) {
return -EBUSY;
}
vq = virtio_find_single_vq(vdev, random_recv_done, "input");
if (IS_ERR(vq)) {
err = PTR_ERR(vq);
vq = NULL;
return err;
}
err = hwrng_register(&virtio_hwrng);
if (err) {
vdev->config->del_vqs(vdev);
vq = NULL;
return err;
}
return 0;
}
static void remove_common(struct virtio_device *vdev)
{
vdev->config->reset(vdev);
busy = false;
hwrng_unregister(&virtio_hwrng);
vdev->config->del_vqs(vdev);
vq = NULL;
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
