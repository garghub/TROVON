static int
g84_cipher_oclass_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
int ret = nvkm_gpuobj_new(object->engine->subdev.device, 16,
align, false, parent, pgpuobj);
if (ret == 0) {
nvkm_kmap(*pgpuobj);
nvkm_wo32(*pgpuobj, 0x00, object->oclass);
nvkm_wo32(*pgpuobj, 0x04, 0x00000000);
nvkm_wo32(*pgpuobj, 0x08, 0x00000000);
nvkm_wo32(*pgpuobj, 0x0c, 0x00000000);
nvkm_done(*pgpuobj);
}
return ret;
}
static int
g84_cipher_cclass_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
int align, struct nvkm_gpuobj **pgpuobj)
{
return nvkm_gpuobj_new(object->engine->subdev.device, 256,
align, true, parent, pgpuobj);
}
static void
g84_cipher_intr(struct nvkm_engine *cipher)
{
struct nvkm_subdev *subdev = &cipher->subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_fifo *fifo = device->fifo;
struct nvkm_fifo_chan *chan;
u32 stat = nvkm_rd32(device, 0x102130);
u32 mthd = nvkm_rd32(device, 0x102190);
u32 data = nvkm_rd32(device, 0x102194);
u32 inst = nvkm_rd32(device, 0x102188) & 0x7fffffff;
unsigned long flags;
char msg[128];
chan = nvkm_fifo_chan_inst(fifo, (u64)inst << 12, &flags);
if (stat) {
nvkm_snprintbf(msg, sizeof(msg), g84_cipher_intr_mask, stat);
nvkm_error(subdev, "%08x [%s] ch %d [%010llx %s] "
"mthd %04x data %08x\n", stat, msg,
chan ? chan->chid : -1, (u64)inst << 12,
chan ? chan->object.client->name : "unknown",
mthd, data);
}
nvkm_fifo_chan_put(fifo, flags, &chan);
nvkm_wr32(device, 0x102130, stat);
nvkm_wr32(device, 0x10200c, 0x10);
}
static int
g84_cipher_init(struct nvkm_engine *cipher)
{
struct nvkm_device *device = cipher->subdev.device;
nvkm_wr32(device, 0x102130, 0xffffffff);
nvkm_wr32(device, 0x102140, 0xffffffbf);
nvkm_wr32(device, 0x10200c, 0x00000010);
return 0;
}
int
g84_cipher_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_engine_new_(&g84_cipher, device, index,
0x00004000, true, pengine);
}
