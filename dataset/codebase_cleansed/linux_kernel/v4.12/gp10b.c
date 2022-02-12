void
gp10b_mc_init(struct nvkm_mc *mc)
{
struct nvkm_device *device = mc->subdev.device;
nvkm_wr32(device, 0x000200, 0xffffffff);
nvkm_wr32(device, 0x00020c, 0xffffffff);
}
int
gp10b_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
return gp100_mc_new_(&gp10b_mc, device, index, pmc);
}
