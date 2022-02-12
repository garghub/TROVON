static void
gf119_disp_chan_uevent_fini(struct nvkm_event *event, int type, int index)
{
struct nv50_disp *disp = container_of(event, typeof(*disp), uevent);
struct nvkm_device *device = disp->base.engine.subdev.device;
nvkm_mask(device, 0x610090, 0x00000001 << index, 0x00000000 << index);
nvkm_wr32(device, 0x61008c, 0x00000001 << index);
}
static void
gf119_disp_chan_uevent_init(struct nvkm_event *event, int types, int index)
{
struct nv50_disp *disp = container_of(event, typeof(*disp), uevent);
struct nvkm_device *device = disp->base.engine.subdev.device;
nvkm_wr32(device, 0x61008c, 0x00000001 << index);
nvkm_mask(device, 0x610090, 0x00000001 << index, 0x00000001 << index);
}
