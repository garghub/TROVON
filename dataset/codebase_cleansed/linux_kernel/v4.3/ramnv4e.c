int
nv4e_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 size = nvkm_rd32(device, 0x10020c) & 0xff000000;
return nvkm_ram_new_(&nv04_ram_func, fb, NVKM_RAM_TYPE_UNKNOWN,
size, 0, pram);
}
