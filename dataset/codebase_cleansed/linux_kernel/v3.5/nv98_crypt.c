static int
nv98_crypt_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv98_crypt_priv *priv = nv_engine(dev, engine);
struct nv98_crypt_chan *cctx;
int ret;
cctx = chan->engctx[engine] = kzalloc(sizeof(*cctx), GFP_KERNEL);
if (!cctx)
return -ENOMEM;
atomic_inc(&chan->vm->engref[engine]);
ret = nouveau_gpuobj_new(dev, chan, 256, 0, NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &cctx->mem);
if (ret)
goto error;
nv_wo32(chan->ramin, 0xa0, 0x00190000);
nv_wo32(chan->ramin, 0xa4, cctx->mem->vinst + cctx->mem->size - 1);
nv_wo32(chan->ramin, 0xa8, cctx->mem->vinst);
nv_wo32(chan->ramin, 0xac, 0x00000000);
nv_wo32(chan->ramin, 0xb0, 0x00000000);
nv_wo32(chan->ramin, 0xb4, 0x00000000);
dev_priv->engine.instmem.flush(dev);
error:
if (ret)
priv->base.context_del(chan, engine);
return ret;
}
static void
nv98_crypt_context_del(struct nouveau_channel *chan, int engine)
{
struct nv98_crypt_chan *cctx = chan->engctx[engine];
int i;
for (i = 0xa0; i < 0xb4; i += 4)
nv_wo32(chan->ramin, i, 0x00000000);
nouveau_gpuobj_ref(NULL, &cctx->mem);
atomic_dec(&chan->vm->engref[engine]);
chan->engctx[engine] = NULL;
kfree(cctx);
}
static int
nv98_crypt_object_new(struct nouveau_channel *chan, int engine,
u32 handle, u16 class)
{
struct nv98_crypt_chan *cctx = chan->engctx[engine];
cctx->mem->engine = 5;
cctx->mem->class = class;
return nouveau_ramht_insert(chan, handle, cctx->mem);
}
static void
nv98_crypt_tlb_flush(struct drm_device *dev, int engine)
{
nv50_vm_flush_engine(dev, 0x0a);
}
static int
nv98_crypt_fini(struct drm_device *dev, int engine, bool suspend)
{
nv_mask(dev, 0x000200, 0x00004000, 0x00000000);
return 0;
}
static int
nv98_crypt_init(struct drm_device *dev, int engine)
{
int i;
nv_mask(dev, 0x000200, 0x00004000, 0x00000000);
nv_mask(dev, 0x000200, 0x00004000, 0x00004000);
nv_wait(dev, 0x087008, 0x00000010, 0x00000010);
nv_wr32(dev, 0x087004, 0x00000010);
nv_wr32(dev, 0x087ff8, 0x00100000);
for (i = 0; i < ARRAY_SIZE(nv98_pcrypt_code); i++)
nv_wr32(dev, 0x087ff4, nv98_pcrypt_code[i]);
nv_wr32(dev, 0x087ff8, 0x00000000);
for (i = 0; i < ARRAY_SIZE(nv98_pcrypt_data); i++)
nv_wr32(dev, 0x087ff4, nv98_pcrypt_data[i]);
nv_wr32(dev, 0x08710c, 0x00000000);
nv_wr32(dev, 0x087104, 0x00000000);
nv_wr32(dev, 0x087100, 0x00000002);
return 0;
}
static void
nv98_crypt_isr(struct drm_device *dev)
{
u32 disp = nv_rd32(dev, 0x08701c);
u32 stat = nv_rd32(dev, 0x087008) & disp & ~(disp >> 16);
u32 inst = nv_rd32(dev, 0x087050) & 0x3fffffff;
u32 ssta = nv_rd32(dev, 0x087040) & 0x0000ffff;
u32 addr = nv_rd32(dev, 0x087040) >> 16;
u32 mthd = (addr & 0x07ff) << 2;
u32 subc = (addr & 0x3800) >> 11;
u32 data = nv_rd32(dev, 0x087044);
int chid = nv50_graph_isr_chid(dev, inst);
if (stat & 0x00000040) {
NV_INFO(dev, "PCRYPT: DISPATCH_ERROR [");
nouveau_enum_print(nv98_crypt_isr_error_name, ssta);
printk("] ch %d [0x%08x] subc %d mthd 0x%04x data 0x%08x\n",
chid, inst, subc, mthd, data);
nv_wr32(dev, 0x087004, 0x00000040);
stat &= ~0x00000040;
}
if (stat) {
NV_INFO(dev, "PCRYPT: unhandled intr 0x%08x\n", stat);
nv_wr32(dev, 0x087004, stat);
}
nv50_fb_vm_trap(dev, 1);
}
static void
nv98_crypt_destroy(struct drm_device *dev, int engine)
{
struct nv98_crypt_priv *priv = nv_engine(dev, engine);
nouveau_irq_unregister(dev, 14);
NVOBJ_ENGINE_DEL(dev, CRYPT);
kfree(priv);
}
int
nv98_crypt_create(struct drm_device *dev)
{
struct nv98_crypt_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.destroy = nv98_crypt_destroy;
priv->base.init = nv98_crypt_init;
priv->base.fini = nv98_crypt_fini;
priv->base.context_new = nv98_crypt_context_new;
priv->base.context_del = nv98_crypt_context_del;
priv->base.object_new = nv98_crypt_object_new;
priv->base.tlb_flush = nv98_crypt_tlb_flush;
nouveau_irq_register(dev, 14, nv98_crypt_isr);
NVOBJ_ENGINE_ADD(dev, CRYPT, &priv->base);
NVOBJ_CLASS(dev, 0x88b4, CRYPT);
return 0;
}
