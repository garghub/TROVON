static int
nv04_ram_create(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_ram *ram;
u32 boot0 = nv_rd32(pfb, NV04_PFB_BOOT_0);
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
if (boot0 & 0x00000100) {
ram->size = ((boot0 >> 12) & 0xf) * 2 + 2;
ram->size *= 1024 * 1024;
} else {
switch (boot0 & NV04_PFB_BOOT_0_RAM_AMOUNT) {
case NV04_PFB_BOOT_0_RAM_AMOUNT_32MB:
ram->size = 32 * 1024 * 1024;
break;
case NV04_PFB_BOOT_0_RAM_AMOUNT_16MB:
ram->size = 16 * 1024 * 1024;
break;
case NV04_PFB_BOOT_0_RAM_AMOUNT_8MB:
ram->size = 8 * 1024 * 1024;
break;
case NV04_PFB_BOOT_0_RAM_AMOUNT_4MB:
ram->size = 4 * 1024 * 1024;
break;
}
}
if ((boot0 & 0x00000038) <= 0x10)
ram->type = NV_MEM_TYPE_SGRAM;
else
ram->type = NV_MEM_TYPE_SDRAM;
return 0;
}
