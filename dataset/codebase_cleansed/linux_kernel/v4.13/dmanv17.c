static int
nv17_fifo_dma_new(struct nvkm_fifo *base, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
struct nvkm_object *parent = oclass->parent;
union {
struct nv03_channel_dma_v0 v0;
} *args = data;
struct nv04_fifo *fifo = nv04_fifo(base);
struct nv04_fifo_chan *chan = NULL;
struct nvkm_device *device = fifo->base.engine.subdev.device;
struct nvkm_instmem *imem = device->imem;
int ret = -ENOSYS;
nvif_ioctl(parent, "create channel dma size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent, "create channel dma vers %d pushbuf %llx "
"offset %08x\n", args->v0.version,
args->v0.pushbuf, args->v0.offset);
if (!args->v0.pushbuf)
return -EINVAL;
} else
return ret;
if (!(chan = kzalloc(sizeof(*chan), GFP_KERNEL)))
return -ENOMEM;
*pobject = &chan->base.object;
ret = nvkm_fifo_chan_ctor(&nv04_fifo_dma_func, &fifo->base,
0x1000, 0x1000, false, 0, args->v0.pushbuf,
(1ULL << NVKM_ENGINE_DMAOBJ) |
(1ULL << NVKM_ENGINE_GR) |
(1ULL << NVKM_ENGINE_MPEG) |
(1ULL << NVKM_ENGINE_SW),
0, 0x800000, 0x10000, oclass, &chan->base);
chan->fifo = fifo;
if (ret)
return ret;
args->v0.chid = chan->base.chid;
chan->ramfc = chan->base.chid * 64;
nvkm_kmap(imem->ramfc);
nvkm_wo32(imem->ramfc, chan->ramfc + 0x00, args->v0.offset);
nvkm_wo32(imem->ramfc, chan->ramfc + 0x04, args->v0.offset);
nvkm_wo32(imem->ramfc, chan->ramfc + 0x0c, chan->base.push->addr >> 4);
nvkm_wo32(imem->ramfc, chan->ramfc + 0x14,
NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8);
nvkm_done(imem->ramfc);
return 0;
}
