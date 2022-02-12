static void
g98_sec_intr(struct nvkm_falcon *sec, struct nvkm_fifo_chan *chan)
{
struct nvkm_subdev *subdev = &sec->engine.subdev;
struct nvkm_device *device = subdev->device;
u32 ssta = nvkm_rd32(device, 0x087040) & 0x0000ffff;
u32 addr = nvkm_rd32(device, 0x087040) >> 16;
u32 mthd = (addr & 0x07ff) << 2;
u32 subc = (addr & 0x3800) >> 11;
u32 data = nvkm_rd32(device, 0x087044);
const struct nvkm_enum *en =
nvkm_enum_find(g98_sec_isr_error_name, ssta);
nvkm_error(subdev, "DISPATCH_ERROR %04x [%s] ch %d [%010llx %s] "
"subc %d mthd %04x data %08x\n", ssta,
en ? en->name : "UNKNOWN", chan ? chan->chid : -1,
chan ? chan->inst->addr : 0,
chan ? chan->object.client->name : "unknown",
subc, mthd, data);
}
int
g98_sec_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_falcon_new_(&g98_sec, device, index,
true, 0x087000, pengine);
}
