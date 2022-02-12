int
nv44_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 size = nvkm_rd32(device, 0x10020c) & 0xff000000;
u32 fb474 = nvkm_rd32(device, 0x100474);
enum nvkm_ram_type type = NVKM_RAM_TYPE_UNKNOWN;
if (fb474 & 0x00000004)
type = NVKM_RAM_TYPE_GDDR3;
if (fb474 & 0x00000002)
type = NVKM_RAM_TYPE_DDR2;
if (fb474 & 0x00000001)
type = NVKM_RAM_TYPE_DDR1;
return nv40_ram_new_(fb, type, size, 0, pram);
}
