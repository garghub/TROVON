static int
nv4e_ram_create(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_ram *ram;
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
ram->size = nv_rd32(pfb, 0x10020c) & 0xff000000;
ram->type = NV_MEM_TYPE_STOLEN;
return 0;
}
