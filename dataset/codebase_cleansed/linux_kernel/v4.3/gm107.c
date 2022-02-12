u64
gm107_devinit_disable(struct nvkm_devinit *init)
{
struct nvkm_device *device = init->subdev.device;
u32 r021c00 = nvkm_rd32(device, 0x021c00);
u32 r021c04 = nvkm_rd32(device, 0x021c04);
u64 disable = 0ULL;
if (r021c00 & 0x00000001)
disable |= (1ULL << NVKM_ENGINE_CE0);
if (r021c00 & 0x00000004)
disable |= (1ULL << NVKM_ENGINE_CE2);
if (r021c04 & 0x00000001)
disable |= (1ULL << NVKM_ENGINE_DISP);
return disable;
}
int
gm107_devinit_new(struct nvkm_device *device, int index,
struct nvkm_devinit **pinit)
{
return nv50_devinit_new_(&gm107_devinit, device, index, pinit);
}
