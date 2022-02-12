static int
gf117_ibus_init(struct nvkm_subdev *ibus)
{
struct nvkm_device *device = ibus->device;
nvkm_mask(device, 0x122310, 0x0003ffff, 0x00000800);
nvkm_mask(device, 0x122348, 0x0003ffff, 0x00000100);
nvkm_mask(device, 0x1223b0, 0x0003ffff, 0x00000fff);
return 0;
}
int
gf117_ibus_new(struct nvkm_device *device, int index,
struct nvkm_subdev **pibus)
{
struct nvkm_subdev *ibus;
if (!(ibus = *pibus = kzalloc(sizeof(*ibus), GFP_KERNEL)))
return -ENOMEM;
nvkm_subdev_ctor(&gf117_ibus, device, index, ibus);
return 0;
}
