static int
nv4e_ram_create(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_fb *pfb = nvkm_fb(parent);
struct nvkm_ram *ram;
int ret;
ret = nvkm_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
ram->size = nv_rd32(pfb, 0x10020c) & 0xff000000;
ram->type = NV_MEM_TYPE_STOLEN;
return 0;
}
