static int
gm107_ram_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct gm107_ram *ram;
int ret;
ret = nvc0_ram_create(parent, engine, oclass, 0x021c14, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
return 0;
}
