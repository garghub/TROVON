static int
nv44_ram_create(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_fb *pfb = nvkm_fb(parent);
struct nv40_ram *ram;
u32 pfb474 = nv_rd32(pfb, 0x100474);
int ret;
ret = nvkm_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
if (pfb474 & 0x00000004)
ram->base.type = NV_MEM_TYPE_GDDR3;
if (pfb474 & 0x00000002)
ram->base.type = NV_MEM_TYPE_DDR2;
if (pfb474 & 0x00000001)
ram->base.type = NV_MEM_TYPE_DDR1;
ram->base.size = nv_rd32(pfb, 0x10020c) & 0xff000000;
ram->base.calc = nv40_ram_calc;
ram->base.prog = nv40_ram_prog;
ram->base.tidy = nv40_ram_tidy;
return 0;
}
