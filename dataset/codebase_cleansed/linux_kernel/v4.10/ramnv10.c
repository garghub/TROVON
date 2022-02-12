int
nv10_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 size = nvkm_rd32(device, 0x10020c) & 0xff000000;
u32 cfg0 = nvkm_rd32(device, 0x100200);
enum nvkm_ram_type type;
if (cfg0 & 0x00000001)
type = NVKM_RAM_TYPE_DDR1;
else
type = NVKM_RAM_TYPE_SDRAM;
return nvkm_ram_new_(&nv04_ram_func, fb, type, size, 0, pram);
}
