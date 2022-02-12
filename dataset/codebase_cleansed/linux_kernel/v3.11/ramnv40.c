static int
nv40_ram_create(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_ram *ram;
u32 pbus1218 = nv_rd32(pfb, 0x001218);
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
switch (pbus1218 & 0x00000300) {
case 0x00000000: ram->type = NV_MEM_TYPE_SDRAM; break;
case 0x00000100: ram->type = NV_MEM_TYPE_DDR1; break;
case 0x00000200: ram->type = NV_MEM_TYPE_GDDR3; break;
case 0x00000300: ram->type = NV_MEM_TYPE_DDR2; break;
}
ram->size = nv_rd32(pfb, 0x10020c) & 0xff000000;
ram->parts = (nv_rd32(pfb, 0x100200) & 0x00000003) + 1;
ram->tags = nv_rd32(pfb, 0x100320);
return 0;
}
