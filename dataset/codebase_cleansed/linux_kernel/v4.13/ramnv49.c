int
nv49_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 size = nvkm_rd32(device, 0x10020c) & 0xff000000;
u32 tags = nvkm_rd32(device, 0x100320);
u32 fb914 = nvkm_rd32(device, 0x100914);
enum nvkm_ram_type type = NVKM_RAM_TYPE_UNKNOWN;
int ret;
switch (fb914 & 0x00000003) {
case 0x00000000: type = NVKM_RAM_TYPE_DDR1 ; break;
case 0x00000001: type = NVKM_RAM_TYPE_DDR2 ; break;
case 0x00000002: type = NVKM_RAM_TYPE_GDDR3; break;
case 0x00000003: break;
}
ret = nv40_ram_new_(fb, type, size, tags, pram);
if (ret)
return ret;
(*pram)->parts = (nvkm_rd32(device, 0x100200) & 0x00000003) + 1;
return 0;
}
