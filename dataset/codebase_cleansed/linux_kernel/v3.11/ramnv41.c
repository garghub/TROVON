static int
nv41_ram_create(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_ram *ram;
u32 pfb474 = nv_rd32(pfb, 0x100474);
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
if (pfb474 & 0x00000004)
ram->type = NV_MEM_TYPE_GDDR3;
if (pfb474 & 0x00000002)
ram->type = NV_MEM_TYPE_DDR2;
if (pfb474 & 0x00000001)
ram->type = NV_MEM_TYPE_DDR1;
ram->size = nv_rd32(pfb, 0x10020c) & 0xff000000;
ram->parts = (nv_rd32(pfb, 0x100200) & 0x00000003) + 1;
ram->tags = nv_rd32(pfb, 0x100320);
return 0;
}
