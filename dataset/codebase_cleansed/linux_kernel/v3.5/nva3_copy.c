static int
nva3_copy_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_gpuobj *ramin = chan->ramin;
struct nouveau_gpuobj *ctx = NULL;
int ret;
NV_DEBUG(dev, "ch%d\n", chan->id);
ret = nouveau_gpuobj_new(dev, chan, 256, 0, NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &ctx);
if (ret)
return ret;
nv_wo32(ramin, 0xc0, 0x00190000);
nv_wo32(ramin, 0xc4, ctx->vinst + ctx->size - 1);
nv_wo32(ramin, 0xc8, ctx->vinst);
nv_wo32(ramin, 0xcc, 0x00000000);
nv_wo32(ramin, 0xd0, 0x00000000);
nv_wo32(ramin, 0xd4, 0x00000000);
dev_priv->engine.instmem.flush(dev);
atomic_inc(&chan->vm->engref[engine]);
chan->engctx[engine] = ctx;
return 0;
}
static int
nva3_copy_object_new(struct nouveau_channel *chan, int engine,
u32 handle, u16 class)
{
struct nouveau_gpuobj *ctx = chan->engctx[engine];
ctx->engine = 3;
ctx->class = class;
return nouveau_ramht_insert(chan, handle, ctx);
}
static void
nva3_copy_context_del(struct nouveau_channel *chan, int engine)
{
struct nouveau_gpuobj *ctx = chan->engctx[engine];
int i;
for (i = 0xc0; i <= 0xd4; i += 4)
nv_wo32(chan->ramin, i, 0x00000000);
atomic_dec(&chan->vm->engref[engine]);
nouveau_gpuobj_ref(NULL, &ctx);
chan->engctx[engine] = ctx;
}
static void
nva3_copy_tlb_flush(struct drm_device *dev, int engine)
{
nv50_vm_flush_engine(dev, 0x0d);
}
static int
nva3_copy_init(struct drm_device *dev, int engine)
{
int i;
nv_mask(dev, 0x000200, 0x00002000, 0x00000000);
nv_mask(dev, 0x000200, 0x00002000, 0x00002000);
nv_wr32(dev, 0x104014, 0xffffffff);
nv_wr32(dev, 0x1041c0, 0x01000000);
for (i = 0; i < sizeof(nva3_pcopy_data) / 4; i++)
nv_wr32(dev, 0x1041c4, nva3_pcopy_data[i]);
nv_wr32(dev, 0x104180, 0x01000000);
for (i = 0; i < sizeof(nva3_pcopy_code) / 4; i++) {
if ((i & 0x3f) == 0)
nv_wr32(dev, 0x104188, i >> 6);
nv_wr32(dev, 0x104184, nva3_pcopy_code[i]);
}
nv_wr32(dev, 0x10410c, 0x00000000);
nv_wr32(dev, 0x104104, 0x00000000);
nv_wr32(dev, 0x104100, 0x00000002);
return 0;
}
static int
nva3_copy_fini(struct drm_device *dev, int engine, bool suspend)
{
nv_mask(dev, 0x104048, 0x00000003, 0x00000000);
nv_wr32(dev, 0x104014, 0xffffffff);
return 0;
}
static void
nva3_copy_isr(struct drm_device *dev)
{
u32 dispatch = nv_rd32(dev, 0x10401c);
u32 stat = nv_rd32(dev, 0x104008) & dispatch & ~(dispatch >> 16);
u32 inst = nv_rd32(dev, 0x104050) & 0x3fffffff;
u32 ssta = nv_rd32(dev, 0x104040) & 0x0000ffff;
u32 addr = nv_rd32(dev, 0x104040) >> 16;
u32 mthd = (addr & 0x07ff) << 2;
u32 subc = (addr & 0x3800) >> 11;
u32 data = nv_rd32(dev, 0x104044);
int chid = nv50_graph_isr_chid(dev, inst);
if (stat & 0x00000040) {
NV_INFO(dev, "PCOPY: DISPATCH_ERROR [");
nouveau_enum_print(nva3_copy_isr_error_name, ssta);
printk("] ch %d [0x%08x] subc %d mthd 0x%04x data 0x%08x\n",
chid, inst, subc, mthd, data);
nv_wr32(dev, 0x104004, 0x00000040);
stat &= ~0x00000040;
}
if (stat) {
NV_INFO(dev, "PCOPY: unhandled intr 0x%08x\n", stat);
nv_wr32(dev, 0x104004, stat);
}
nv50_fb_vm_trap(dev, 1);
}
static void
nva3_copy_destroy(struct drm_device *dev, int engine)
{
struct nva3_copy_engine *pcopy = nv_engine(dev, engine);
nouveau_irq_unregister(dev, 22);
NVOBJ_ENGINE_DEL(dev, COPY0);
kfree(pcopy);
}
int
nva3_copy_create(struct drm_device *dev)
{
struct nva3_copy_engine *pcopy;
pcopy = kzalloc(sizeof(*pcopy), GFP_KERNEL);
if (!pcopy)
return -ENOMEM;
pcopy->base.destroy = nva3_copy_destroy;
pcopy->base.init = nva3_copy_init;
pcopy->base.fini = nva3_copy_fini;
pcopy->base.context_new = nva3_copy_context_new;
pcopy->base.context_del = nva3_copy_context_del;
pcopy->base.object_new = nva3_copy_object_new;
pcopy->base.tlb_flush = nva3_copy_tlb_flush;
nouveau_irq_register(dev, 22, nva3_copy_isr);
NVOBJ_ENGINE_ADD(dev, COPY0, &pcopy->base);
NVOBJ_CLASS(dev, 0x85b5, COPY0);
return 0;
}
