static int
gm107_ram_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct gm107_ram *ram;
int ret;
ret = gf100_ram_create(parent, engine, oclass, 0x021c14, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
return 0;
}
