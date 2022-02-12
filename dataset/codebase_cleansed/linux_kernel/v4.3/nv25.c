static int
nv25_gr_chan_new(struct nvkm_gr *base, struct nvkm_fifo_chan *fifoch,
const struct nvkm_oclass *oclass, struct nvkm_object **pobject)
{
struct nv20_gr *gr = nv20_gr(base);
struct nv20_gr_chan *chan;
int ret, i;
if (!(chan = kzalloc(sizeof(*chan), GFP_KERNEL)))
return -ENOMEM;
nvkm_object_ctor(&nv25_gr_chan, oclass, &chan->object);
chan->gr = gr;
chan->chid = fifoch->chid;
*pobject = &chan->object;
ret = nvkm_memory_new(gr->base.engine.subdev.device,
NVKM_MEM_TARGET_INST, 0x3724, 16, true,
&chan->inst);
if (ret)
return ret;
nvkm_kmap(chan->inst);
nvkm_wo32(chan->inst, 0x0028, 0x00000001 | (chan->chid << 24));
nvkm_wo32(chan->inst, 0x035c, 0xffff0000);
nvkm_wo32(chan->inst, 0x03c0, 0x0fff0000);
nvkm_wo32(chan->inst, 0x03c4, 0x0fff0000);
nvkm_wo32(chan->inst, 0x049c, 0x00000101);
nvkm_wo32(chan->inst, 0x04b0, 0x00000111);
nvkm_wo32(chan->inst, 0x04c8, 0x00000080);
nvkm_wo32(chan->inst, 0x04cc, 0xffff0000);
nvkm_wo32(chan->inst, 0x04d0, 0x00000001);
nvkm_wo32(chan->inst, 0x04e4, 0x44400000);
nvkm_wo32(chan->inst, 0x04fc, 0x4b800000);
for (i = 0x0510; i <= 0x051c; i += 4)
nvkm_wo32(chan->inst, i, 0x00030303);
for (i = 0x0530; i <= 0x053c; i += 4)
nvkm_wo32(chan->inst, i, 0x00080000);
for (i = 0x0548; i <= 0x0554; i += 4)
nvkm_wo32(chan->inst, i, 0x01012000);
for (i = 0x0558; i <= 0x0564; i += 4)
nvkm_wo32(chan->inst, i, 0x000105b8);
for (i = 0x0568; i <= 0x0574; i += 4)
nvkm_wo32(chan->inst, i, 0x00080008);
for (i = 0x0598; i <= 0x05d4; i += 4)
nvkm_wo32(chan->inst, i, 0x07ff0000);
nvkm_wo32(chan->inst, 0x05e0, 0x4b7fffff);
nvkm_wo32(chan->inst, 0x0620, 0x00000080);
nvkm_wo32(chan->inst, 0x0624, 0x30201000);
nvkm_wo32(chan->inst, 0x0628, 0x70605040);
nvkm_wo32(chan->inst, 0x062c, 0xb0a09080);
nvkm_wo32(chan->inst, 0x0630, 0xf0e0d0c0);
nvkm_wo32(chan->inst, 0x0664, 0x00000001);
nvkm_wo32(chan->inst, 0x066c, 0x00004000);
nvkm_wo32(chan->inst, 0x0678, 0x00000001);
nvkm_wo32(chan->inst, 0x0680, 0x00040000);
nvkm_wo32(chan->inst, 0x0684, 0x00010000);
for (i = 0x1b04; i <= 0x2374; i += 16) {
nvkm_wo32(chan->inst, (i + 0), 0x10700ff9);
nvkm_wo32(chan->inst, (i + 4), 0x0436086c);
nvkm_wo32(chan->inst, (i + 8), 0x000c001b);
}
nvkm_wo32(chan->inst, 0x2704, 0x3f800000);
nvkm_wo32(chan->inst, 0x2718, 0x3f800000);
nvkm_wo32(chan->inst, 0x2744, 0x40000000);
nvkm_wo32(chan->inst, 0x2748, 0x3f800000);
nvkm_wo32(chan->inst, 0x274c, 0x3f000000);
nvkm_wo32(chan->inst, 0x2754, 0x40000000);
nvkm_wo32(chan->inst, 0x2758, 0x3f800000);
nvkm_wo32(chan->inst, 0x2760, 0xbf800000);
nvkm_wo32(chan->inst, 0x2768, 0xbf800000);
nvkm_wo32(chan->inst, 0x308c, 0x000fe000);
nvkm_wo32(chan->inst, 0x3108, 0x000003f8);
nvkm_wo32(chan->inst, 0x3468, 0x002fe000);
for (i = 0x3484; i <= 0x34a0; i += 4)
nvkm_wo32(chan->inst, i, 0x001c527c);
nvkm_done(chan->inst);
return 0;
}
int
nv25_gr_new(struct nvkm_device *device, int index, struct nvkm_gr **pgr)
{
return nv20_gr_new_(&nv25_gr, device, index, pgr);
}
