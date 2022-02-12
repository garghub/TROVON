static int
nvaa_ram_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 datasize,
struct nouveau_object **pobject)
{
const u32 rsvd_head = ( 256 * 1024) >> 12;
const u32 rsvd_tail = (1024 * 1024) >> 12;
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_ram *ram;
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
ram->size = nv_rd32(pfb, 0x10020c);
ram->size = (ram->size & 0xffffff00) | ((ram->size & 0x000000ff) << 32);
ret = nouveau_mm_init(&pfb->vram, rsvd_head, (ram->size >> 12) -
(rsvd_head + rsvd_tail), 1);
if (ret)
return ret;
ram->type = NV_MEM_TYPE_STOLEN;
ram->stolen = (u64)nv_rd32(pfb, 0x100e10) << 12;
ram->get = nv50_ram_get;
ram->put = nv50_ram_put;
return 0;
}
