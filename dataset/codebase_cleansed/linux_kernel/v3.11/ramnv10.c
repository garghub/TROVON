static int
nv10_ram_create(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_ram *ram;
u32 cfg0 = nv_rd32(pfb, 0x100200);
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
if (cfg0 & 0x00000001)
ram->type = NV_MEM_TYPE_DDR1;
else
ram->type = NV_MEM_TYPE_SDRAM;
ram->size = nv_rd32(pfb, 0x10020c) & 0xff000000;
return 0;
}
