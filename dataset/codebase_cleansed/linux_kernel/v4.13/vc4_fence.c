static const char *vc4_fence_get_driver_name(struct dma_fence *fence)
{
return "vc4";
}
static const char *vc4_fence_get_timeline_name(struct dma_fence *fence)
{
return "vc4-v3d";
}
static bool vc4_fence_enable_signaling(struct dma_fence *fence)
{
return true;
}
static bool vc4_fence_signaled(struct dma_fence *fence)
{
struct vc4_fence *f = to_vc4_fence(fence);
struct vc4_dev *vc4 = to_vc4_dev(f->dev);
return vc4->finished_seqno >= f->seqno;
}
