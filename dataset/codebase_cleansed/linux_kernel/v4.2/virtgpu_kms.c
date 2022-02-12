static void virtio_gpu_config_changed_work_func(struct work_struct *work)
{
struct virtio_gpu_device *vgdev =
container_of(work, struct virtio_gpu_device,
config_changed_work);
u32 events_read, events_clear = 0;
virtio_cread(vgdev->vdev, struct virtio_gpu_config,
events_read, &events_read);
if (events_read & VIRTIO_GPU_EVENT_DISPLAY) {
virtio_gpu_cmd_get_display_info(vgdev);
drm_helper_hpd_irq_event(vgdev->ddev);
events_clear |= VIRTIO_GPU_EVENT_DISPLAY;
}
virtio_cwrite(vgdev->vdev, struct virtio_gpu_config,
events_clear, &events_clear);
}
static void virtio_gpu_init_vq(struct virtio_gpu_queue *vgvq,
void (*work_func)(struct work_struct *work))
{
spin_lock_init(&vgvq->qlock);
init_waitqueue_head(&vgvq->ack_queue);
INIT_WORK(&vgvq->dequeue_work, work_func);
}
int virtio_gpu_driver_load(struct drm_device *dev, unsigned long flags)
{
static vq_callback_t *callbacks[] = {
virtio_gpu_ctrl_ack, virtio_gpu_cursor_ack
};
static const char *names[] = { "control", "cursor" };
struct virtio_gpu_device *vgdev;
struct virtqueue *vqs[2];
u32 num_scanouts;
int ret;
if (!virtio_has_feature(dev->virtdev, VIRTIO_F_VERSION_1))
return -ENODEV;
vgdev = kzalloc(sizeof(struct virtio_gpu_device), GFP_KERNEL);
if (!vgdev)
return -ENOMEM;
vgdev->ddev = dev;
dev->dev_private = vgdev;
vgdev->vdev = dev->virtdev;
vgdev->dev = dev->dev;
spin_lock_init(&vgdev->display_info_lock);
spin_lock_init(&vgdev->ctx_id_idr_lock);
idr_init(&vgdev->ctx_id_idr);
spin_lock_init(&vgdev->resource_idr_lock);
idr_init(&vgdev->resource_idr);
init_waitqueue_head(&vgdev->resp_wq);
virtio_gpu_init_vq(&vgdev->ctrlq, virtio_gpu_dequeue_ctrl_func);
virtio_gpu_init_vq(&vgdev->cursorq, virtio_gpu_dequeue_cursor_func);
spin_lock_init(&vgdev->fence_drv.lock);
INIT_LIST_HEAD(&vgdev->fence_drv.fences);
INIT_WORK(&vgdev->config_changed_work,
virtio_gpu_config_changed_work_func);
ret = vgdev->vdev->config->find_vqs(vgdev->vdev, 2, vqs,
callbacks, names);
if (ret) {
DRM_ERROR("failed to find virt queues\n");
goto err_vqs;
}
vgdev->ctrlq.vq = vqs[0];
vgdev->cursorq.vq = vqs[1];
ret = virtio_gpu_alloc_vbufs(vgdev);
if (ret) {
DRM_ERROR("failed to alloc vbufs\n");
goto err_vbufs;
}
ret = virtio_gpu_ttm_init(vgdev);
if (ret) {
DRM_ERROR("failed to init ttm %d\n", ret);
goto err_ttm;
}
virtio_cread(vgdev->vdev, struct virtio_gpu_config,
num_scanouts, &num_scanouts);
vgdev->num_scanouts = min_t(uint32_t, num_scanouts,
VIRTIO_GPU_MAX_SCANOUTS);
if (!vgdev->num_scanouts) {
DRM_ERROR("num_scanouts is zero\n");
ret = -EINVAL;
goto err_scanouts;
}
ret = virtio_gpu_modeset_init(vgdev);
if (ret)
goto err_modeset;
virtio_device_ready(vgdev->vdev);
vgdev->vqs_ready = true;
virtio_gpu_cmd_get_display_info(vgdev);
wait_event_timeout(vgdev->resp_wq, !vgdev->display_info_pending,
5 * HZ);
if (virtio_gpu_fbdev)
virtio_gpu_fbdev_init(vgdev);
return 0;
err_modeset:
err_scanouts:
virtio_gpu_ttm_fini(vgdev);
err_ttm:
virtio_gpu_free_vbufs(vgdev);
err_vbufs:
vgdev->vdev->config->del_vqs(vgdev->vdev);
err_vqs:
kfree(vgdev);
return ret;
}
int virtio_gpu_driver_unload(struct drm_device *dev)
{
struct virtio_gpu_device *vgdev = dev->dev_private;
vgdev->vqs_ready = false;
flush_work(&vgdev->ctrlq.dequeue_work);
flush_work(&vgdev->cursorq.dequeue_work);
flush_work(&vgdev->config_changed_work);
vgdev->vdev->config->del_vqs(vgdev->vdev);
virtio_gpu_modeset_fini(vgdev);
virtio_gpu_ttm_fini(vgdev);
virtio_gpu_free_vbufs(vgdev);
kfree(vgdev);
return 0;
}
