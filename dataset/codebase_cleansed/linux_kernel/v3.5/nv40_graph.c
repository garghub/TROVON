static int
nv40_graph_context_new(struct nouveau_channel *chan, int engine)
{
struct nv40_graph_engine *pgraph = nv_engine(chan->dev, engine);
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_gpuobj *grctx = NULL;
unsigned long flags;
int ret;
ret = nouveau_gpuobj_new(dev, NULL, pgraph->grctx_size, 16,
NVOBJ_FLAG_ZERO_ALLOC, &grctx);
if (ret)
return ret;
nv40_grctx_fill(dev, grctx);
nv_wo32(grctx, 0, grctx->vinst);
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_wo32(chan->ramfc, 0x38, grctx->vinst >> 4);
nv_mask(dev, 0x002500, 0x00000001, 0x00000000);
if ((nv_rd32(dev, 0x003204) & 0x0000001f) == chan->id)
nv_wr32(dev, 0x0032e0, grctx->vinst >> 4);
nv_mask(dev, 0x002500, 0x00000001, 0x00000001);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
chan->engctx[engine] = grctx;
return 0;
}
static void
nv40_graph_context_del(struct nouveau_channel *chan, int engine)
{
struct nouveau_gpuobj *grctx = chan->engctx[engine];
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
u32 inst = 0x01000000 | (grctx->pinst >> 4);
unsigned long flags;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_mask(dev, 0x400720, 0x00000000, 0x00000001);
if (nv_rd32(dev, 0x40032c) == inst)
nv_mask(dev, 0x40032c, 0x01000000, 0x00000000);
if (nv_rd32(dev, 0x400330) == inst)
nv_mask(dev, 0x400330, 0x01000000, 0x00000000);
nv_mask(dev, 0x400720, 0x00000001, 0x00000001);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
nouveau_gpuobj_ref(NULL, &grctx);
chan->engctx[engine] = NULL;
}
int
nv40_graph_object_new(struct nouveau_channel *chan, int engine,
u32 handle, u16 class)
{
struct drm_device *dev = chan->dev;
struct nouveau_gpuobj *obj = NULL;
int ret;
ret = nouveau_gpuobj_new(dev, chan, 20, 16, NVOBJ_FLAG_ZERO_FREE, &obj);
if (ret)
return ret;
obj->engine = 1;
obj->class = class;
nv_wo32(obj, 0x00, class);
nv_wo32(obj, 0x04, 0x00000000);
#ifndef __BIG_ENDIAN
nv_wo32(obj, 0x08, 0x00000000);
#else
nv_wo32(obj, 0x08, 0x01000000);
#endif
nv_wo32(obj, 0x0c, 0x00000000);
nv_wo32(obj, 0x10, 0x00000000);
ret = nouveau_ramht_insert(chan, handle, obj);
nouveau_gpuobj_ref(NULL, &obj);
return ret;
}
static void
nv40_graph_set_tile_region(struct drm_device *dev, int i)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_tile_reg *tile = &dev_priv->tile.reg[i];
switch (dev_priv->chipset) {
case 0x40:
case 0x41:
case 0x42:
case 0x43:
case 0x45:
case 0x4e:
nv_wr32(dev, NV20_PGRAPH_TSIZE(i), tile->pitch);
nv_wr32(dev, NV20_PGRAPH_TLIMIT(i), tile->limit);
nv_wr32(dev, NV20_PGRAPH_TILE(i), tile->addr);
nv_wr32(dev, NV40_PGRAPH_TSIZE1(i), tile->pitch);
nv_wr32(dev, NV40_PGRAPH_TLIMIT1(i), tile->limit);
nv_wr32(dev, NV40_PGRAPH_TILE1(i), tile->addr);
break;
case 0x44:
case 0x4a:
nv_wr32(dev, NV20_PGRAPH_TSIZE(i), tile->pitch);
nv_wr32(dev, NV20_PGRAPH_TLIMIT(i), tile->limit);
nv_wr32(dev, NV20_PGRAPH_TILE(i), tile->addr);
break;
case 0x46:
case 0x47:
case 0x49:
case 0x4b:
case 0x4c:
case 0x67:
default:
nv_wr32(dev, NV47_PGRAPH_TSIZE(i), tile->pitch);
nv_wr32(dev, NV47_PGRAPH_TLIMIT(i), tile->limit);
nv_wr32(dev, NV47_PGRAPH_TILE(i), tile->addr);
nv_wr32(dev, NV40_PGRAPH_TSIZE1(i), tile->pitch);
nv_wr32(dev, NV40_PGRAPH_TLIMIT1(i), tile->limit);
nv_wr32(dev, NV40_PGRAPH_TILE1(i), tile->addr);
break;
}
}
int
nv40_graph_init(struct drm_device *dev, int engine)
{
struct nv40_graph_engine *pgraph = nv_engine(dev, engine);
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
uint32_t vramsz;
int i, j;
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) &
~NV_PMC_ENABLE_PGRAPH);
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) |
NV_PMC_ENABLE_PGRAPH);
nv40_grctx_init(dev, &pgraph->grctx_size);
nv_wr32(dev, NV40_PGRAPH_CTXCTL_CUR, 0x00000000);
nv_wr32(dev, NV03_PGRAPH_INTR , 0xFFFFFFFF);
nv_wr32(dev, NV40_PGRAPH_INTR_EN, 0xFFFFFFFF);
nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0xFFFFFFFF);
nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0x00000000);
nv_wr32(dev, NV04_PGRAPH_DEBUG_1, 0x401287c0);
nv_wr32(dev, NV04_PGRAPH_DEBUG_3, 0xe0de8055);
nv_wr32(dev, NV10_PGRAPH_DEBUG_4, 0x00008000);
nv_wr32(dev, NV04_PGRAPH_LIMIT_VIOL_PIX, 0x00be3c5f);
nv_wr32(dev, NV10_PGRAPH_CTX_CONTROL, 0x10010100);
nv_wr32(dev, NV10_PGRAPH_STATE , 0xFFFFFFFF);
j = nv_rd32(dev, 0x1540) & 0xff;
if (j) {
for (i = 0; !(j & 1); j >>= 1, i++)
;
nv_wr32(dev, 0x405000, i);
}
if (dev_priv->chipset == 0x40) {
nv_wr32(dev, 0x4009b0, 0x83280fff);
nv_wr32(dev, 0x4009b4, 0x000000a0);
} else {
nv_wr32(dev, 0x400820, 0x83280eff);
nv_wr32(dev, 0x400824, 0x000000a0);
}
switch (dev_priv->chipset) {
case 0x40:
case 0x45:
nv_wr32(dev, 0x4009b8, 0x0078e366);
nv_wr32(dev, 0x4009bc, 0x0000014c);
break;
case 0x41:
case 0x42:
nv_wr32(dev, 0x400828, 0x007596ff);
nv_wr32(dev, 0x40082c, 0x00000108);
break;
case 0x43:
nv_wr32(dev, 0x400828, 0x0072cb77);
nv_wr32(dev, 0x40082c, 0x00000108);
break;
case 0x44:
case 0x46:
case 0x4a:
case 0x4c:
case 0x4e:
nv_wr32(dev, 0x400860, 0);
nv_wr32(dev, 0x400864, 0);
break;
case 0x47:
case 0x49:
case 0x4b:
nv_wr32(dev, 0x400828, 0x07830610);
nv_wr32(dev, 0x40082c, 0x0000016A);
break;
default:
break;
}
nv_wr32(dev, 0x400b38, 0x2ffff800);
nv_wr32(dev, 0x400b3c, 0x00006000);
switch (dev_priv->chipset) {
case 0x44:
case 0x4a:
nv_wr32(dev, 0x400bc4, 0x1003d888);
nv_wr32(dev, 0x400bbc, 0xb7a7b500);
break;
case 0x46:
nv_wr32(dev, 0x400bc4, 0x0000e024);
nv_wr32(dev, 0x400bbc, 0xb7a7b520);
break;
case 0x4c:
case 0x4e:
case 0x67:
nv_wr32(dev, 0x400bc4, 0x1003d888);
nv_wr32(dev, 0x400bbc, 0xb7a7b540);
break;
default:
break;
}
for (i = 0; i < pfb->num_tiles; i++)
nv40_graph_set_tile_region(dev, i);
vramsz = pci_resource_len(dev->pdev, 0) - 1;
switch (dev_priv->chipset) {
case 0x40:
nv_wr32(dev, 0x4009A4, nv_rd32(dev, NV04_PFB_CFG0));
nv_wr32(dev, 0x4009A8, nv_rd32(dev, NV04_PFB_CFG1));
nv_wr32(dev, 0x4069A4, nv_rd32(dev, NV04_PFB_CFG0));
nv_wr32(dev, 0x4069A8, nv_rd32(dev, NV04_PFB_CFG1));
nv_wr32(dev, 0x400820, 0);
nv_wr32(dev, 0x400824, 0);
nv_wr32(dev, 0x400864, vramsz);
nv_wr32(dev, 0x400868, vramsz);
break;
default:
switch (dev_priv->chipset) {
case 0x41:
case 0x42:
case 0x43:
case 0x45:
case 0x4e:
case 0x44:
case 0x4a:
nv_wr32(dev, 0x4009F0, nv_rd32(dev, NV04_PFB_CFG0));
nv_wr32(dev, 0x4009F4, nv_rd32(dev, NV04_PFB_CFG1));
break;
default:
nv_wr32(dev, 0x400DF0, nv_rd32(dev, NV04_PFB_CFG0));
nv_wr32(dev, 0x400DF4, nv_rd32(dev, NV04_PFB_CFG1));
break;
}
nv_wr32(dev, 0x4069F0, nv_rd32(dev, NV04_PFB_CFG0));
nv_wr32(dev, 0x4069F4, nv_rd32(dev, NV04_PFB_CFG1));
nv_wr32(dev, 0x400840, 0);
nv_wr32(dev, 0x400844, 0);
nv_wr32(dev, 0x4008A0, vramsz);
nv_wr32(dev, 0x4008A4, vramsz);
break;
}
return 0;
}
static int
nv40_graph_fini(struct drm_device *dev, int engine, bool suspend)
{
u32 inst = nv_rd32(dev, 0x40032c);
if (inst & 0x01000000) {
nv_wr32(dev, 0x400720, 0x00000000);
nv_wr32(dev, 0x400784, inst);
nv_mask(dev, 0x400310, 0x00000020, 0x00000020);
nv_mask(dev, 0x400304, 0x00000001, 0x00000001);
if (!nv_wait(dev, 0x400300, 0x00000001, 0x00000000)) {
u32 insn = nv_rd32(dev, 0x400308);
NV_ERROR(dev, "PGRAPH: ctxprog timeout 0x%08x\n", insn);
}
nv_mask(dev, 0x40032c, 0x01000000, 0x00000000);
}
return 0;
}
static int
nv40_graph_isr_chid(struct drm_device *dev, u32 inst)
{
struct nouveau_fifo_priv *pfifo = nv_engine(dev, NVOBJ_ENGINE_FIFO);
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_gpuobj *grctx;
unsigned long flags;
int i;
spin_lock_irqsave(&dev_priv->channels.lock, flags);
for (i = 0; i < pfifo->channels; i++) {
if (!dev_priv->channels.ptr[i])
continue;
grctx = dev_priv->channels.ptr[i]->engctx[NVOBJ_ENGINE_GR];
if (grctx && grctx->pinst == inst)
break;
}
spin_unlock_irqrestore(&dev_priv->channels.lock, flags);
return i;
}
static void
nv40_graph_isr(struct drm_device *dev)
{
u32 stat;
while ((stat = nv_rd32(dev, NV03_PGRAPH_INTR))) {
u32 nsource = nv_rd32(dev, NV03_PGRAPH_NSOURCE);
u32 nstatus = nv_rd32(dev, NV03_PGRAPH_NSTATUS);
u32 inst = (nv_rd32(dev, 0x40032c) & 0x000fffff) << 4;
u32 chid = nv40_graph_isr_chid(dev, inst);
u32 addr = nv_rd32(dev, NV04_PGRAPH_TRAPPED_ADDR);
u32 subc = (addr & 0x00070000) >> 16;
u32 mthd = (addr & 0x00001ffc);
u32 data = nv_rd32(dev, NV04_PGRAPH_TRAPPED_DATA);
u32 class = nv_rd32(dev, 0x400160 + subc * 4) & 0xffff;
u32 show = stat;
if (stat & NV_PGRAPH_INTR_ERROR) {
if (nsource & NV03_PGRAPH_NSOURCE_ILLEGAL_MTHD) {
if (!nouveau_gpuobj_mthd_call2(dev, chid, class, mthd, data))
show &= ~NV_PGRAPH_INTR_ERROR;
} else
if (nsource & NV03_PGRAPH_NSOURCE_DMA_VTX_PROTECTION) {
nv_mask(dev, 0x402000, 0, 0);
}
}
nv_wr32(dev, NV03_PGRAPH_INTR, stat);
nv_wr32(dev, NV04_PGRAPH_FIFO, 0x00000001);
if (show && nouveau_ratelimit()) {
NV_INFO(dev, "PGRAPH -");
nouveau_bitfield_print(nv10_graph_intr, show);
printk(" nsource:");
nouveau_bitfield_print(nv04_graph_nsource, nsource);
printk(" nstatus:");
nouveau_bitfield_print(nv10_graph_nstatus, nstatus);
printk("\n");
NV_INFO(dev, "PGRAPH - ch %d (0x%08x) subc %d "
"class 0x%04x mthd 0x%04x data 0x%08x\n",
chid, inst, subc, class, mthd, data);
}
}
}
static void
nv40_graph_destroy(struct drm_device *dev, int engine)
{
struct nv40_graph_engine *pgraph = nv_engine(dev, engine);
nouveau_irq_unregister(dev, 12);
NVOBJ_ENGINE_DEL(dev, GR);
kfree(pgraph);
}
int
nv40_graph_create(struct drm_device *dev)
{
struct nv40_graph_engine *pgraph;
pgraph = kzalloc(sizeof(*pgraph), GFP_KERNEL);
if (!pgraph)
return -ENOMEM;
pgraph->base.destroy = nv40_graph_destroy;
pgraph->base.init = nv40_graph_init;
pgraph->base.fini = nv40_graph_fini;
pgraph->base.context_new = nv40_graph_context_new;
pgraph->base.context_del = nv40_graph_context_del;
pgraph->base.object_new = nv40_graph_object_new;
pgraph->base.set_tile_region = nv40_graph_set_tile_region;
NVOBJ_ENGINE_ADD(dev, GR, &pgraph->base);
nouveau_irq_register(dev, 12, nv40_graph_isr);
NVOBJ_CLASS(dev, 0x0030, GR);
NVOBJ_CLASS(dev, 0x0039, GR);
NVOBJ_CLASS(dev, 0x004a, GR);
NVOBJ_CLASS(dev, 0x009f, GR);
NVOBJ_CLASS(dev, 0x008a, GR);
NVOBJ_CLASS(dev, 0x0089, GR);
NVOBJ_CLASS(dev, 0x3089, GR);
NVOBJ_CLASS(dev, 0x0062, GR);
NVOBJ_CLASS(dev, 0x3062, GR);
NVOBJ_CLASS(dev, 0x0043, GR);
NVOBJ_CLASS(dev, 0x0012, GR);
NVOBJ_CLASS(dev, 0x0072, GR);
NVOBJ_CLASS(dev, 0x0019, GR);
NVOBJ_CLASS(dev, 0x0044, GR);
NVOBJ_CLASS(dev, 0x309e, GR);
if (nv44_graph_class(dev))
NVOBJ_CLASS(dev, 0x4497, GR);
else
NVOBJ_CLASS(dev, 0x4097, GR);
return 0;
}
