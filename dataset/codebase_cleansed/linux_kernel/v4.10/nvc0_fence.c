static int
nvc0_fence_emit32(struct nouveau_channel *chan, u64 virtual, u32 sequence)
{
int ret = RING_SPACE(chan, 6);
if (ret == 0) {
BEGIN_NVC0(chan, 0, NV84_SUBCHAN_SEMAPHORE_ADDRESS_HIGH, 5);
OUT_RING (chan, upper_32_bits(virtual));
OUT_RING (chan, lower_32_bits(virtual));
OUT_RING (chan, sequence);
OUT_RING (chan, NV84_SUBCHAN_SEMAPHORE_TRIGGER_WRITE_LONG);
OUT_RING (chan, 0x00000000);
FIRE_RING (chan);
}
return ret;
}
static int
nvc0_fence_sync32(struct nouveau_channel *chan, u64 virtual, u32 sequence)
{
int ret = RING_SPACE(chan, 5);
if (ret == 0) {
BEGIN_NVC0(chan, 0, NV84_SUBCHAN_SEMAPHORE_ADDRESS_HIGH, 4);
OUT_RING (chan, upper_32_bits(virtual));
OUT_RING (chan, lower_32_bits(virtual));
OUT_RING (chan, sequence);
OUT_RING (chan, NV84_SUBCHAN_SEMAPHORE_TRIGGER_ACQUIRE_GEQUAL |
NVC0_SUBCHAN_SEMAPHORE_TRIGGER_YIELD);
FIRE_RING (chan);
}
return ret;
}
static int
nvc0_fence_context_new(struct nouveau_channel *chan)
{
int ret = nv84_fence_context_new(chan);
if (ret == 0) {
struct nv84_fence_chan *fctx = chan->fence;
fctx->base.emit32 = nvc0_fence_emit32;
fctx->base.sync32 = nvc0_fence_sync32;
}
return ret;
}
int
nvc0_fence_create(struct nouveau_drm *drm)
{
int ret = nv84_fence_create(drm);
if (ret == 0) {
struct nv84_fence_priv *priv = drm->fence;
priv->base.context_new = nvc0_fence_context_new;
}
return ret;
}
