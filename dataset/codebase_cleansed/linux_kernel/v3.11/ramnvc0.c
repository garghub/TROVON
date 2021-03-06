void
nvc0_ram_put(struct nouveau_fb *pfb, struct nouveau_mem **pmem)
{
struct nouveau_ltcg *ltcg = nouveau_ltcg(pfb);
struct nouveau_mem *mem = *pmem;
*pmem = NULL;
if (unlikely(mem == NULL))
return;
mutex_lock(&pfb->base.mutex);
if (mem->tag)
ltcg->tags_free(ltcg, &mem->tag);
__nv50_ram_put(pfb, mem);
mutex_unlock(&pfb->base.mutex);
kfree(mem);
}
int
nvc0_ram_get(struct nouveau_fb *pfb, u64 size, u32 align, u32 ncmin,
u32 memtype, struct nouveau_mem **pmem)
{
struct nouveau_mm *mm = &pfb->vram;
struct nouveau_mm_node *r;
struct nouveau_mem *mem;
int type = (memtype & 0x0ff);
int back = (memtype & 0x800);
const bool comp = nvc0_pte_storage_type_map[type] != type;
int ret;
size >>= 12;
align >>= 12;
ncmin >>= 12;
if (!ncmin)
ncmin = size;
mem = kzalloc(sizeof(*mem), GFP_KERNEL);
if (!mem)
return -ENOMEM;
INIT_LIST_HEAD(&mem->regions);
mem->size = size;
mutex_lock(&pfb->base.mutex);
if (comp) {
struct nouveau_ltcg *ltcg = nouveau_ltcg(pfb);
if (align == (1 << (17 - 12))) {
int n = size >> 5;
ltcg->tags_alloc(ltcg, n, &mem->tag);
}
if (unlikely(!mem->tag))
type = nvc0_pte_storage_type_map[type];
}
mem->memtype = type;
do {
if (back)
ret = nouveau_mm_tail(mm, 1, size, ncmin, align, &r);
else
ret = nouveau_mm_head(mm, 1, size, ncmin, align, &r);
if (ret) {
mutex_unlock(&pfb->base.mutex);
pfb->ram->put(pfb, &mem);
return ret;
}
list_add_tail(&r->rl_entry, &mem->regions);
size -= r->length;
} while (size);
mutex_unlock(&pfb->base.mutex);
r = list_first_entry(&mem->regions, struct nouveau_mm_node, rl_entry);
mem->offset = (u64)r->offset << 12;
*pmem = mem;
return 0;
}
static int
nvc0_ram_create(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_bios *bios = nouveau_bios(pfb);
struct nouveau_ram *ram;
const u32 rsvd_head = ( 256 * 1024) >> 12;
const u32 rsvd_tail = (1024 * 1024) >> 12;
u32 parts = nv_rd32(pfb, 0x022438);
u32 pmask = nv_rd32(pfb, 0x022554);
u32 bsize = nv_rd32(pfb, 0x10f20c);
u32 offset, length;
bool uniform = true;
int ret, part;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
nv_debug(pfb, "0x100800: 0x%08x\n", nv_rd32(pfb, 0x100800));
nv_debug(pfb, "parts 0x%08x mask 0x%08x\n", parts, pmask);
ram->type = nouveau_fb_bios_memtype(bios);
ram->ranks = (nv_rd32(pfb, 0x10f200) & 0x00000004) ? 2 : 1;
for (part = 0; part < parts; part++) {
if (!(pmask & (1 << part))) {
u32 psize = nv_rd32(pfb, 0x11020c + (part * 0x1000));
if (psize != bsize) {
if (psize < bsize)
bsize = psize;
uniform = false;
}
nv_debug(pfb, "%d: mem_amount 0x%08x\n", part, psize);
ram->size += (u64)psize << 20;
}
}
if (uniform) {
offset = rsvd_head;
length = (ram->size >> 12) - rsvd_head - rsvd_tail;
ret = nouveau_mm_init(&pfb->vram, offset, length, 1);
} else {
ret = nouveau_mm_init(&pfb->vram, rsvd_head,
(bsize << 8) * parts, 1);
if (ret)
return ret;
offset = (0x0200000000ULL >> 12) + (bsize << 8);
length = (ram->size >> 12) - (bsize << 8) - rsvd_tail;
ret = nouveau_mm_init(&pfb->vram, offset, length, 0);
if (ret)
nouveau_mm_fini(&pfb->vram);
}
if (ret)
return ret;
ram->get = nvc0_ram_get;
ram->put = nvc0_ram_put;
return 0;
}
