void
gf100_mspdec_init(struct nvkm_falcon *mspdec)
{
struct nvkm_device *device = mspdec->engine.subdev.device;
nvkm_wr32(device, 0x085010, 0x0000fff2);
nvkm_wr32(device, 0x08501c, 0x0000fff2);
}
int
gf100_mspdec_new(struct nvkm_device *device, int index,
struct nvkm_engine **pengine)
{
return nvkm_mspdec_new_(&gf100_mspdec, device, index, pengine);
}
