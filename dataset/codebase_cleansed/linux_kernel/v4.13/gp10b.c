static int
gp10b_ibus_init(struct nvkm_subdev *ibus)
{
struct nvkm_device *device = ibus->device;
nvkm_wr32(device, 0x1200a8, 0x0);
nvkm_wr32(device, 0x12004c, 0x4);
nvkm_wr32(device, 0x122204, 0x2);
nvkm_rd32(device, 0x122204);
nvkm_wr32(device, 0x009080, 0x800186a0);
return 0;
}
int
gp10b_ibus_new(struct nvkm_device *device, int index,
struct nvkm_subdev **pibus)
{
struct nvkm_subdev *ibus;
if (!(ibus = *pibus = kzalloc(sizeof(*ibus), GFP_KERNEL)))
return -ENOMEM;
nvkm_subdev_ctor(&gp10b_ibus, device, index, ibus);
return 0;
}
