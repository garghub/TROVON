int
nv20_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 pbus1218 = nvkm_rd32(device, 0x001218);
u32 size = (nvkm_rd32(device, 0x10020c) & 0xff000000);
u32 tags = nvkm_rd32(device, 0x100320);
enum nvkm_ram_type type = NVKM_RAM_TYPE_UNKNOWN;
int ret;
switch (pbus1218 & 0x00000300) {
case 0x00000000: type = NVKM_RAM_TYPE_SDRAM; break;
case 0x00000100: type = NVKM_RAM_TYPE_DDR1 ; break;
case 0x00000200: type = NVKM_RAM_TYPE_GDDR3; break;
case 0x00000300: type = NVKM_RAM_TYPE_GDDR2; break;
}
ret = nvkm_ram_new_(&nv04_ram_func, fb, type, size, tags, pram);
if (ret)
return ret;
(*pram)->parts = (nvkm_rd32(device, 0x100200) & 0x00000003) + 1;
return 0;
}
