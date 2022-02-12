struct msm_ringbuffer *msm_ringbuffer_new(struct msm_gpu *gpu, int size)
{
struct msm_ringbuffer *ring;
int ret;
size = ALIGN(size, 4);
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring) {
ret = -ENOMEM;
goto fail;
}
ring->gpu = gpu;
ring->bo = msm_gem_new(gpu->dev, size, MSM_BO_WC);
if (IS_ERR(ring->bo)) {
ret = PTR_ERR(ring->bo);
ring->bo = NULL;
goto fail;
}
ring->start = msm_gem_vaddr_locked(ring->bo);
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
if (ring->bo)
drm_gem_object_unreference(ring->bo);
kfree(ring);
}
