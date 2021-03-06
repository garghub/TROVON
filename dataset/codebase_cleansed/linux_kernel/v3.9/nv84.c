static int
nv84_fifo_context_attach(struct nouveau_object *parent,
struct nouveau_object *object)
{
struct nouveau_bar *bar = nouveau_bar(parent);
struct nv50_fifo_base *base = (void *)parent->parent;
struct nouveau_gpuobj *ectx = (void *)object;
u64 limit = ectx->addr + ectx->size - 1;
u64 start = ectx->addr;
u32 addr;
switch (nv_engidx(object->engine)) {
case NVDEV_ENGINE_SW : return 0;
case NVDEV_ENGINE_GR : addr = 0x0020; break;
case NVDEV_ENGINE_MPEG : addr = 0x0060; break;
case NVDEV_ENGINE_CRYPT: addr = 0x00a0; break;
case NVDEV_ENGINE_COPY0: addr = 0x00c0; break;
default:
return -EINVAL;
}
nv_engctx(ectx)->addr = nv_gpuobj(base)->addr >> 12;
nv_wo32(base->eng, addr + 0x00, 0x00190000);
nv_wo32(base->eng, addr + 0x04, lower_32_bits(limit));
nv_wo32(base->eng, addr + 0x08, lower_32_bits(start));
nv_wo32(base->eng, addr + 0x0c, upper_32_bits(limit) << 24 |
upper_32_bits(start));
nv_wo32(base->eng, addr + 0x10, 0x00000000);
nv_wo32(base->eng, addr + 0x14, 0x00000000);
bar->flush(bar);
return 0;
}
static int
nv84_fifo_context_detach(struct nouveau_object *parent, bool suspend,
struct nouveau_object *object)
{
struct nouveau_bar *bar = nouveau_bar(parent);
struct nv50_fifo_priv *priv = (void *)parent->engine;
struct nv50_fifo_base *base = (void *)parent->parent;
struct nv50_fifo_chan *chan = (void *)parent;
u32 addr, save, engn;
bool done;
switch (nv_engidx(object->engine)) {
case NVDEV_ENGINE_SW : return 0;
case NVDEV_ENGINE_GR : engn = 0; addr = 0x0020; break;
case NVDEV_ENGINE_MPEG : engn = 1; addr = 0x0060; break;
case NVDEV_ENGINE_CRYPT: engn = 4; addr = 0x00a0; break;
case NVDEV_ENGINE_COPY0: engn = 2; addr = 0x00c0; break;
default:
return -EINVAL;
}
save = nv_mask(priv, 0x002520, 0x0000003f, 1 << engn);
nv_wr32(priv, 0x0032fc, nv_gpuobj(base)->addr >> 12);
done = nv_wait_ne(priv, 0x0032fc, 0xffffffff, 0xffffffff);
nv_wr32(priv, 0x002520, save);
if (!done) {
nv_error(priv, "channel %d [%s] unload timeout\n",
chan->base.chid, nouveau_client_name(chan));
if (suspend)
return -EBUSY;
}
nv_wo32(base->eng, addr + 0x00, 0x00000000);
nv_wo32(base->eng, addr + 0x04, 0x00000000);
nv_wo32(base->eng, addr + 0x08, 0x00000000);
nv_wo32(base->eng, addr + 0x0c, 0x00000000);
nv_wo32(base->eng, addr + 0x10, 0x00000000);
nv_wo32(base->eng, addr + 0x14, 0x00000000);
bar->flush(bar);
return 0;
}
static int
nv84_fifo_object_attach(struct nouveau_object *parent,
struct nouveau_object *object, u32 handle)
{
struct nv50_fifo_chan *chan = (void *)parent;
u32 context;
if (nv_iclass(object, NV_GPUOBJ_CLASS))
context = nv_gpuobj(object)->node->offset >> 4;
else
context = 0x00000004;
switch (nv_engidx(object->engine)) {
case NVDEV_ENGINE_DMAOBJ:
case NVDEV_ENGINE_SW : context |= 0x00000000; break;
case NVDEV_ENGINE_GR : context |= 0x00100000; break;
case NVDEV_ENGINE_MPEG :
case NVDEV_ENGINE_PPP : context |= 0x00200000; break;
case NVDEV_ENGINE_ME :
case NVDEV_ENGINE_COPY0 : context |= 0x00300000; break;
case NVDEV_ENGINE_VP : context |= 0x00400000; break;
case NVDEV_ENGINE_CRYPT :
case NVDEV_ENGINE_UNK1C1: context |= 0x00500000; break;
case NVDEV_ENGINE_BSP : context |= 0x00600000; break;
default:
return -EINVAL;
}
return nouveau_ramht_insert(chan->ramht, 0, handle, context);
}
static int
nv84_fifo_chan_ctor_dma(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_bar *bar = nouveau_bar(parent);
struct nv50_fifo_base *base = (void *)parent;
struct nv50_fifo_chan *chan;
struct nv03_channel_dma_class *args = data;
int ret;
if (size < sizeof(*args))
return -EINVAL;
ret = nouveau_fifo_channel_create(parent, engine, oclass, 0, 0xc00000,
0x2000, args->pushbuf,
(1ULL << NVDEV_ENGINE_DMAOBJ) |
(1ULL << NVDEV_ENGINE_SW) |
(1ULL << NVDEV_ENGINE_GR) |
(1ULL << NVDEV_ENGINE_MPEG) |
(1ULL << NVDEV_ENGINE_ME) |
(1ULL << NVDEV_ENGINE_VP) |
(1ULL << NVDEV_ENGINE_CRYPT) |
(1ULL << NVDEV_ENGINE_BSP) |
(1ULL << NVDEV_ENGINE_PPP) |
(1ULL << NVDEV_ENGINE_COPY0) |
(1ULL << NVDEV_ENGINE_UNK1C1), &chan);
*pobject = nv_object(chan);
if (ret)
return ret;
ret = nouveau_ramht_new(parent, parent, 0x8000, 16, &chan->ramht);
if (ret)
return ret;
nv_parent(chan)->context_attach = nv84_fifo_context_attach;
nv_parent(chan)->context_detach = nv84_fifo_context_detach;
nv_parent(chan)->object_attach = nv84_fifo_object_attach;
nv_parent(chan)->object_detach = nv50_fifo_object_detach;
nv_wo32(base->ramfc, 0x08, lower_32_bits(args->offset));
nv_wo32(base->ramfc, 0x0c, upper_32_bits(args->offset));
nv_wo32(base->ramfc, 0x10, lower_32_bits(args->offset));
nv_wo32(base->ramfc, 0x14, upper_32_bits(args->offset));
nv_wo32(base->ramfc, 0x3c, 0x003f6078);
nv_wo32(base->ramfc, 0x44, 0x01003fff);
nv_wo32(base->ramfc, 0x48, chan->base.pushgpu->node->offset >> 4);
nv_wo32(base->ramfc, 0x4c, 0xffffffff);
nv_wo32(base->ramfc, 0x60, 0x7fffffff);
nv_wo32(base->ramfc, 0x78, 0x00000000);
nv_wo32(base->ramfc, 0x7c, 0x30000001);
nv_wo32(base->ramfc, 0x80, ((chan->ramht->bits - 9) << 27) |
(4 << 24) |
(chan->ramht->base.node->offset >> 4));
nv_wo32(base->ramfc, 0x88, base->cache->addr >> 10);
nv_wo32(base->ramfc, 0x98, nv_gpuobj(base)->addr >> 12);
bar->flush(bar);
return 0;
}
static int
nv84_fifo_chan_ctor_ind(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_bar *bar = nouveau_bar(parent);
struct nv50_fifo_base *base = (void *)parent;
struct nv50_fifo_chan *chan;
struct nv50_channel_ind_class *args = data;
u64 ioffset, ilength;
int ret;
if (size < sizeof(*args))
return -EINVAL;
ret = nouveau_fifo_channel_create(parent, engine, oclass, 0, 0xc00000,
0x2000, args->pushbuf,
(1ULL << NVDEV_ENGINE_DMAOBJ) |
(1ULL << NVDEV_ENGINE_SW) |
(1ULL << NVDEV_ENGINE_GR) |
(1ULL << NVDEV_ENGINE_MPEG) |
(1ULL << NVDEV_ENGINE_ME) |
(1ULL << NVDEV_ENGINE_VP) |
(1ULL << NVDEV_ENGINE_CRYPT) |
(1ULL << NVDEV_ENGINE_BSP) |
(1ULL << NVDEV_ENGINE_PPP) |
(1ULL << NVDEV_ENGINE_COPY0) |
(1ULL << NVDEV_ENGINE_UNK1C1), &chan);
*pobject = nv_object(chan);
if (ret)
return ret;
ret = nouveau_ramht_new(parent, parent, 0x8000, 16, &chan->ramht);
if (ret)
return ret;
nv_parent(chan)->context_attach = nv84_fifo_context_attach;
nv_parent(chan)->context_detach = nv84_fifo_context_detach;
nv_parent(chan)->object_attach = nv84_fifo_object_attach;
nv_parent(chan)->object_detach = nv50_fifo_object_detach;
ioffset = args->ioffset;
ilength = log2i(args->ilength / 8);
nv_wo32(base->ramfc, 0x3c, 0x403f6078);
nv_wo32(base->ramfc, 0x44, 0x01003fff);
nv_wo32(base->ramfc, 0x48, chan->base.pushgpu->node->offset >> 4);
nv_wo32(base->ramfc, 0x50, lower_32_bits(ioffset));
nv_wo32(base->ramfc, 0x54, upper_32_bits(ioffset) | (ilength << 16));
nv_wo32(base->ramfc, 0x60, 0x7fffffff);
nv_wo32(base->ramfc, 0x78, 0x00000000);
nv_wo32(base->ramfc, 0x7c, 0x30000001);
nv_wo32(base->ramfc, 0x80, ((chan->ramht->bits - 9) << 27) |
(4 << 24) |
(chan->ramht->base.node->offset >> 4));
nv_wo32(base->ramfc, 0x88, base->cache->addr >> 10);
nv_wo32(base->ramfc, 0x98, nv_gpuobj(base)->addr >> 12);
bar->flush(bar);
return 0;
}
static int
nv84_fifo_chan_init(struct nouveau_object *object)
{
struct nv50_fifo_priv *priv = (void *)object->engine;
struct nv50_fifo_base *base = (void *)object->parent;
struct nv50_fifo_chan *chan = (void *)object;
struct nouveau_gpuobj *ramfc = base->ramfc;
u32 chid = chan->base.chid;
int ret;
ret = nouveau_fifo_channel_init(&chan->base);
if (ret)
return ret;
nv_wr32(priv, 0x002600 + (chid * 4), 0x80000000 | ramfc->addr >> 8);
nv50_fifo_playlist_update(priv);
return 0;
}
static int
nv84_fifo_context_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_fifo_base *base;
int ret;
ret = nouveau_fifo_context_create(parent, engine, oclass, NULL, 0x10000,
0x1000, NVOBJ_FLAG_HEAP, &base);
*pobject = nv_object(base);
if (ret)
return ret;
ret = nouveau_gpuobj_new(parent, nv_object(base), 0x0200, 0,
NVOBJ_FLAG_ZERO_ALLOC, &base->eng);
if (ret)
return ret;
ret = nouveau_gpuobj_new(parent, nv_object(base), 0x4000, 0,
0, &base->pgd);
if (ret)
return ret;
ret = nouveau_vm_ref(nouveau_client(parent)->vm, &base->vm, base->pgd);
if (ret)
return ret;
ret = nouveau_gpuobj_new(parent, nv_object(base), 0x1000, 0x400,
NVOBJ_FLAG_ZERO_ALLOC, &base->cache);
if (ret)
return ret;
ret = nouveau_gpuobj_new(parent, nv_object(base), 0x0100, 0x100,
NVOBJ_FLAG_ZERO_ALLOC, &base->ramfc);
if (ret)
return ret;
return 0;
}
static void
nv84_fifo_uevent_enable(struct nouveau_event *event, int index)
{
struct nv84_fifo_priv *priv = event->priv;
nv_mask(priv, 0x002140, 0x40000000, 0x40000000);
}
static void
nv84_fifo_uevent_disable(struct nouveau_event *event, int index)
{
struct nv84_fifo_priv *priv = event->priv;
nv_mask(priv, 0x002140, 0x40000000, 0x00000000);
}
static int
nv84_fifo_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv50_fifo_priv *priv;
int ret;
ret = nouveau_fifo_create(parent, engine, oclass, 1, 127, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
ret = nouveau_gpuobj_new(parent, NULL, 128 * 4, 0x1000, 0,
&priv->playlist[0]);
if (ret)
return ret;
ret = nouveau_gpuobj_new(parent, NULL, 128 * 4, 0x1000, 0,
&priv->playlist[1]);
if (ret)
return ret;
priv->base.uevent->enable = nv84_fifo_uevent_enable;
priv->base.uevent->disable = nv84_fifo_uevent_disable;
priv->base.uevent->priv = priv;
nv_subdev(priv)->unit = 0x00000100;
nv_subdev(priv)->intr = nv04_fifo_intr;
nv_engine(priv)->cclass = &nv84_fifo_cclass;
nv_engine(priv)->sclass = nv84_fifo_sclass;
return 0;
}
