static int
nv20_ram_create(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_fb *pfb = nvkm_fb(parent);
struct nvkm_ram *ram;
u32 pbus1218 = nv_rd32(pfb, 0x001218);
int ret;
ret = nvkm_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
switch (pbus1218 & 0x00000300) {
case 0x00000000: ram->type = NV_MEM_TYPE_SDRAM; break;
case 0x00000100: ram->type = NV_MEM_TYPE_DDR1; break;
case 0x00000200: ram->type = NV_MEM_TYPE_GDDR3; break;
case 0x00000300: ram->type = NV_MEM_TYPE_GDDR2; break;
}
ram->size = (nv_rd32(pfb, 0x10020c) & 0xff000000);
ram->parts = (nv_rd32(pfb, 0x100200) & 0x00000003) + 1;
ram->tags = nv_rd32(pfb, 0x100320);
return 0;
}
