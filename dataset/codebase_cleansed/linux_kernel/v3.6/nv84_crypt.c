static int
nv84_crypt_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_gpuobj *ramin = chan->ramin;
struct nouveau_gpuobj *ctx;
int ret;
NV_DEBUG(dev, "ch%d\n", chan->id);
ret = nouveau_gpuobj_new(dev, chan, 256, 0, NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &ctx);
if (ret)
return ret;
nv_wo32(ramin, 0xa0, 0x00190000);
nv_wo32(ramin, 0xa4, ctx->vinst + ctx->size - 1);
nv_wo32(ramin, 0xa8, ctx->vinst);
nv_wo32(ramin, 0xac, 0);
nv_wo32(ramin, 0xb0, 0);
nv_wo32(ramin, 0xb4, 0);
dev_priv->engine.instmem.flush(dev);
atomic_inc(&chan->vm->engref[engine]);
chan->engctx[engine] = ctx;
return 0;
}
static void
nv84_crypt_context_del(struct nouveau_channel *chan, int engine)
{
struct nouveau_gpuobj *ctx = chan->engctx[engine];
struct drm_device *dev = chan->dev;
u32 inst;
inst = (chan->ramin->vinst >> 12);
inst |= 0x80000000;
nv_wr32(dev, 0x10200c, 0x00000000);
if (nv_rd32(dev, 0x102188) == inst)
nv_mask(dev, 0x102188, 0x80000000, 0x00000000);
if (nv_rd32(dev, 0x10218c) == inst)
nv_mask(dev, 0x10218c, 0x80000000, 0x00000000);
nv_wr32(dev, 0x10200c, 0x00000010);
nouveau_gpuobj_ref(NULL, &ctx);
atomic_dec(&chan->vm->engref[engine]);
chan->engctx[engine] = NULL;
}
static int
nv84_crypt_object_new(struct nouveau_channel *chan, int engine,
u32 handle, u16 class)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_gpuobj *obj = NULL;
int ret;
ret = nouveau_gpuobj_new(dev, chan, 16, 16, NVOBJ_FLAG_ZERO_FREE, &obj);
if (ret)
return ret;
obj->engine = 5;
obj->class = class;
nv_wo32(obj, 0x00, class);
dev_priv->engine.instmem.flush(dev);
ret = nouveau_ramht_insert(chan, handle, obj);
nouveau_gpuobj_ref(NULL, &obj);
return ret;
}
static void
nv84_crypt_tlb_flush(struct drm_device *dev, int engine)
{
nv50_vm_flush_engine(dev, 0x0a);
}
static void
nv84_crypt_isr(struct drm_device *dev)
{
u32 stat = nv_rd32(dev, 0x102130);
u32 mthd = nv_rd32(dev, 0x102190);
u32 data = nv_rd32(dev, 0x102194);
u64 inst = (u64)(nv_rd32(dev, 0x102188) & 0x7fffffff) << 12;
int show = nouveau_ratelimit();
int chid = nv50_graph_isr_chid(dev, inst);
if (show) {
NV_INFO(dev, "PCRYPT:");
nouveau_bitfield_print(nv84_crypt_intr, stat);
printk(KERN_CONT " ch %d (0x%010llx) mthd 0x%04x data 0x%08x\n",
chid, inst, mthd, data);
}
nv_wr32(dev, 0x102130, stat);
nv_wr32(dev, 0x10200c, 0x10);
nv50_fb_vm_trap(dev, show);
}
static int
nv84_crypt_fini(struct drm_device *dev, int engine, bool suspend)
{
nv_wr32(dev, 0x102140, 0x00000000);
return 0;
}
static int
nv84_crypt_init(struct drm_device *dev, int engine)
{
nv_mask(dev, 0x000200, 0x00004000, 0x00000000);
nv_mask(dev, 0x000200, 0x00004000, 0x00004000);
nv_wr32(dev, 0x102130, 0xffffffff);
nv_wr32(dev, 0x102140, 0xffffffbf);
nv_wr32(dev, 0x10200c, 0x00000010);
return 0;
}
static void
nv84_crypt_destroy(struct drm_device *dev, int engine)
{
struct nv84_crypt_engine *pcrypt = nv_engine(dev, engine);
NVOBJ_ENGINE_DEL(dev, CRYPT);
nouveau_irq_unregister(dev, 14);
kfree(pcrypt);
}
int
nv84_crypt_create(struct drm_device *dev)
{
struct nv84_crypt_engine *pcrypt;
pcrypt = kzalloc(sizeof(*pcrypt), GFP_KERNEL);
if (!pcrypt)
return -ENOMEM;
pcrypt->base.destroy = nv84_crypt_destroy;
pcrypt->base.init = nv84_crypt_init;
pcrypt->base.fini = nv84_crypt_fini;
pcrypt->base.context_new = nv84_crypt_context_new;
pcrypt->base.context_del = nv84_crypt_context_del;
pcrypt->base.object_new = nv84_crypt_object_new;
pcrypt->base.tlb_flush = nv84_crypt_tlb_flush;
nouveau_irq_register(dev, 14, nv84_crypt_isr);
NVOBJ_ENGINE_ADD(dev, CRYPT, &pcrypt->base);
NVOBJ_CLASS (dev, 0x74c1, CRYPT);
return 0;
}
