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
if (virtqueue_add_buf(vq, &sg, 0, 1, buf, GFP_KERNEL) < 0)
BUG();
virtqueue_kick(vq);
}
static int virtio_read(struct hwrng *rng, void *buf, size_t size, bool wait)
{
if (!busy) {
busy = true;
init_completion(&have_data);
register_buffer(buf, size);
}
if (!wait)
return 0;
wait_for_completion(&have_data);
busy = false;
return data_avail;
}
static void virtio_cleanup(struct hwrng *rng)
{
if (busy)
wait_for_completion(&have_data);
}
static int virtrng_probe(struct virtio_device *vdev)
{
int err;
vq = virtio_find_single_vq(vdev, random_recv_done, "input");
if (IS_ERR(vq))
return PTR_ERR(vq);
err = hwrng_register(&virtio_hwrng);
if (err) {
vdev->config->del_vqs(vdev);
return err;
}
return 0;
}
static void __devexit virtrng_remove(struct virtio_device *vdev)
{
vdev->config->reset(vdev);
hwrng_unregister(&virtio_hwrng);
vdev->config->del_vqs(vdev);
}
static int __init init(void)
{
return register_virtio_driver(&virtio_rng_driver);
}
static void __exit fini(void)
{
unregister_virtio_driver(&virtio_rng_driver);
}
