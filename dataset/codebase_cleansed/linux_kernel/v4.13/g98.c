void
g98_msvld_init(struct nvkm_falcon *msvld)
{
struct nvkm_device *device = msvld->engine.subdev.device;
nvkm_wr32(device, 0x084010, 0x0000ffd2);
nvkm_wr32(device, 0x08401c, 0x0000fff2);
}
int
g98_msvld_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_msvld_new_(&g98_msvld, device, index, pengine);
}
