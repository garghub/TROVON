struct msm_ringbuffer *msm_ringbuffer_new(struct msm_gpu *gpu, int size)
{
struct msm_ringbuffer *ring;
int ret;
if (WARN_ON(!is_power_of_2(size)))
return ERR_PTR(-EINVAL);
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring) {
ret = -ENOMEM;
goto fail;
}
ring->gpu = gpu;
ring->start = msm_gem_kernel_new(gpu->dev, size, MSM_BO_WC,
gpu->aspace, &ring->bo, NULL);
if (IS_ERR(ring->start)) {
ret = PTR_ERR(ring->start);
ring->start = 0;
goto fail;
}
ring->end = ring->start + (size / 4);
ring->cur = ring->start;
ring->size = size;
return ring;
fail:
if (ring)
msm_ringbuffer_destroy(ring);
return ERR_PTR(ret);
}
void msm_ringbuffer_destroy(struct msm_ringbuffer *ring)
{
if (ring->bo) {
msm_gem_put_vaddr(ring->bo);
drm_gem_object_unreference_unlocked(ring->bo);
}
kfree(ring);
}
