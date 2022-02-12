int
gm204_ibus_new(struct nvkm_device *device, int index,
struct nvkm_subdev **pibus)
{
struct nvkm_subdev *ibus;
if (!(ibus = *pibus = kzalloc(sizeof(*ibus), GFP_KERNEL)))
return -ENOMEM;
nvkm_subdev_ctor(&gm204_ibus, device, index, 0, ibus);
return 0;
}
