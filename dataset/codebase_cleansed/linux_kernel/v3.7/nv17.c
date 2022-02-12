static int
nv17_fifo_chan_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv04_fifo_priv *priv = (void *)engine;
struct nv04_fifo_chan *chan;
struct nv03_channel_dma_class *args = data;
int ret;
if (size < sizeof(*args))
return -EINVAL;
ret = nouveau_fifo_channel_create(parent, engine, oclass, 0, 0x800000,
0x10000, args->pushbuf,
(1 << NVDEV_ENGINE_DMAOBJ) |
(1 << NVDEV_ENGINE_SW) |
(1 << NVDEV_ENGINE_GR) |
(1 << NVDEV_ENGINE_MPEG),
&chan);
*pobject = nv_object(chan);
if (ret)
return ret;
nv_parent(chan)->object_attach = nv04_fifo_object_attach;
nv_parent(chan)->object_detach = nv04_fifo_object_detach;
nv_parent(chan)->context_attach = nv04_fifo_context_attach;
chan->ramfc = chan->base.chid * 64;
nv_wo32(priv->ramfc, chan->ramfc + 0x00, args->offset);
nv_wo32(priv->ramfc, chan->ramfc + 0x04, args->offset);
nv_wo32(priv->ramfc, chan->ramfc + 0x0c, chan->base.pushgpu->addr >> 4);
nv_wo32(priv->ramfc, chan->ramfc + 0x14,
NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8);
return 0;
}
static int
nv17_fifo_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv04_instmem_priv *imem = nv04_instmem(parent);
struct nv04_fifo_priv *priv;
int ret;
ret = nouveau_fifo_create(parent, engine, oclass, 0, 31, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nouveau_ramht_ref(imem->ramht, &priv->ramht);
nouveau_gpuobj_ref(imem->ramro, &priv->ramro);
nouveau_gpuobj_ref(imem->ramfc, &priv->ramfc);
nv_subdev(priv)->unit = 0x00000100;
nv_subdev(priv)->intr = nv04_fifo_intr;
nv_engine(priv)->cclass = &nv17_fifo_cclass;
nv_engine(priv)->sclass = nv17_fifo_sclass;
priv->base.pause = nv04_fifo_pause;
priv->base.start = nv04_fifo_start;
priv->ramfc_desc = nv17_ramfc;
return 0;
}
static int
nv17_fifo_init(struct nouveau_object *object)
{
struct nv04_fifo_priv *priv = (void *)object;
int ret;
ret = nouveau_fifo_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, NV04_PFIFO_DELAY_0, 0x000000ff);
nv_wr32(priv, NV04_PFIFO_DMA_TIMESLICE, 0x0101ffff);
nv_wr32(priv, NV03_PFIFO_RAMHT, (0x03 << 24) |
((priv->ramht->bits - 9) << 16) |
(priv->ramht->base.addr >> 8));
nv_wr32(priv, NV03_PFIFO_RAMRO, priv->ramro->addr >> 8);
nv_wr32(priv, NV03_PFIFO_RAMFC, priv->ramfc->addr >> 8 | 0x00010000);
nv_wr32(priv, NV03_PFIFO_CACHE1_PUSH1, priv->base.max);
nv_wr32(priv, NV03_PFIFO_INTR_0, 0xffffffff);
nv_wr32(priv, NV03_PFIFO_INTR_EN_0, 0xffffffff);
nv_wr32(priv, NV03_PFIFO_CACHE1_PUSH0, 1);
nv_wr32(priv, NV04_PFIFO_CACHE1_PULL0, 1);
nv_wr32(priv, NV03_PFIFO_CACHES, 1);
return 0;
}
