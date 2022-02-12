int
nv04_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 boot0 = nvkm_rd32(device, NV04_PFB_BOOT_0);
u64 size;
enum nvkm_ram_type type;
if (boot0 & 0x00000100) {
size = ((boot0 >> 12) & 0xf) * 2 + 2;
size *= 1024 * 1024;
} else {
switch (boot0 & NV04_PFB_BOOT_0_RAM_AMOUNT) {
case NV04_PFB_BOOT_0_RAM_AMOUNT_32MB:
size = 32 * 1024 * 1024;
break;
case NV04_PFB_BOOT_0_RAM_AMOUNT_16MB:
size = 16 * 1024 * 1024;
break;
case NV04_PFB_BOOT_0_RAM_AMOUNT_8MB:
size = 8 * 1024 * 1024;
break;
case NV04_PFB_BOOT_0_RAM_AMOUNT_4MB:
size = 4 * 1024 * 1024;
break;
}
}
if ((boot0 & 0x00000038) <= 0x10)
type = NVKM_RAM_TYPE_SGRAM;
else
type = NVKM_RAM_TYPE_SDRAM;
return nvkm_ram_new_(&nv04_ram_func, fb, type, size, 0, pram);
}
