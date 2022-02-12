static int
g84_fifo_dma_new(struct nvkm_fifo *base, const struct nvkm_oclass *oclass,
void *data, u32 size, struct nvkm_object **pobject)
{
struct nvkm_object *parent = oclass->parent;
union {
struct g82_channel_dma_v0 v0;
} *args = data;
struct nv50_fifo *fifo = nv50_fifo(base);
struct nv50_fifo_chan *chan;
int ret = -ENOSYS;
nvif_ioctl(parent, "create channel dma size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(parent, "create channel dma vers %d vm %llx "
"pushbuf %llx offset %016llx\n",
args->v0.version, args->v0.vm, args->v0.pushbuf,
args->v0.offset);
if (!args->v0.pushbuf)
return -EINVAL;
} else
return ret;
if (!(chan = kzalloc(sizeof(*chan), GFP_KERNEL)))
return -ENOMEM;
*pobject = &chan->base.object;
ret = g84_fifo_chan_ctor(fifo, args->v0.vm, args->v0.pushbuf,
oclass, chan);
if (ret)
return ret;
args->v0.chid = chan->base.chid;
nvkm_kmap(chan->ramfc);
nvkm_wo32(chan->ramfc, 0x08, lower_32_bits(args->v0.offset));
nvkm_wo32(chan->ramfc, 0x0c, upper_32_bits(args->v0.offset));
nvkm_wo32(chan->ramfc, 0x10, lower_32_bits(args->v0.offset));
nvkm_wo32(chan->ramfc, 0x14, upper_32_bits(args->v0.offset));
nvkm_wo32(chan->ramfc, 0x3c, 0x003f6078);
nvkm_wo32(chan->ramfc, 0x44, 0x01003fff);
nvkm_wo32(chan->ramfc, 0x48, chan->base.push->node->offset >> 4);
nvkm_wo32(chan->ramfc, 0x4c, 0xffffffff);
nvkm_wo32(chan->ramfc, 0x60, 0x7fffffff);
nvkm_wo32(chan->ramfc, 0x78, 0x00000000);
nvkm_wo32(chan->ramfc, 0x7c, 0x30000001);
nvkm_wo32(chan->ramfc, 0x80, ((chan->ramht->bits - 9) << 27) |
(4 << 24) |
(chan->ramht->gpuobj->node->offset >> 4));
nvkm_wo32(chan->ramfc, 0x88, chan->cache->addr >> 10);
nvkm_wo32(chan->ramfc, 0x98, chan->base.inst->addr >> 12);
nvkm_done(chan->ramfc);
return 0;
}
