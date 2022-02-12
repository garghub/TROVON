bool
nvc0_vram_flags_valid(struct drm_device *dev, u32 tile_flags)
{
u8 memtype = (tile_flags & NOUVEAU_GEM_TILE_LAYOUT_MASK) >> 8;
return likely((types[memtype] == 1));
}
int
nvc0_vram_new(struct drm_device *dev, u64 size, u32 align, u32 ncmin,
u32 type, struct nouveau_mem **pmem)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_mm *mm = &dev_priv->engine.vram.mm;
struct nouveau_mm_node *r;
struct nouveau_mem *mem;
int ret;
size >>= 12;
align >>= 12;
ncmin >>= 12;
mem = kzalloc(sizeof(*mem), GFP_KERNEL);
if (!mem)
return -ENOMEM;
INIT_LIST_HEAD(&mem->regions);
mem->dev = dev_priv->dev;
mem->memtype = (type & 0xff);
mem->size = size;
mutex_lock(&mm->mutex);
do {
ret = nouveau_mm_get(mm, 1, size, ncmin, align, &r);
if (ret) {
mutex_unlock(&mm->mutex);
nv50_vram_del(dev, &mem);
return ret;
}
list_add_tail(&r->rl_entry, &mem->regions);
size -= r->length;
} while (size);
mutex_unlock(&mm->mutex);
r = list_first_entry(&mem->regions, struct nouveau_mm_node, rl_entry);
mem->offset = (u64)r->offset << 12;
*pmem = mem;
return 0;
}
int
nvc0_vram_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_vram_engine *vram = &dev_priv->engine.vram;
const u32 rsvd_head = ( 256 * 1024) >> 12;
const u32 rsvd_tail = (1024 * 1024) >> 12;
u32 parts = nv_rd32(dev, 0x022438);
u32 pmask = nv_rd32(dev, 0x022554);
u32 bsize = nv_rd32(dev, 0x10f20c);
u32 offset, length;
bool uniform = true;
int ret, part;
NV_DEBUG(dev, "0x100800: 0x%08x\n", nv_rd32(dev, 0x100800));
NV_DEBUG(dev, "parts 0x%08x mask 0x%08x\n", parts, pmask);
dev_priv->vram_type = nouveau_mem_vbios_type(dev);
dev_priv->vram_rank_B = !!(nv_rd32(dev, 0x10f200) & 0x00000004);
for (part = 0; part < parts; part++) {
if (!(pmask & (1 << part))) {
u32 psize = nv_rd32(dev, 0x11020c + (part * 0x1000));
if (psize != bsize) {
if (psize < bsize)
bsize = psize;
uniform = false;
}
NV_DEBUG(dev, "%d: mem_amount 0x%08x\n", part, psize);
dev_priv->vram_size += (u64)psize << 20;
}
}
if (uniform) {
offset = rsvd_head;
length = (dev_priv->vram_size >> 12) - rsvd_head - rsvd_tail;
return nouveau_mm_init(&vram->mm, offset, length, 1);
}
ret = nouveau_mm_init(&vram->mm, rsvd_head, (bsize << 8) * parts, 1);
if (ret)
return ret;
offset = (0x0200000000ULL >> 12) + (bsize << 8);
length = (dev_priv->vram_size >> 12) - (bsize << 8) - rsvd_tail;
ret = nouveau_mm_init(&vram->mm, offset, length, 0);
if (ret) {
nouveau_mm_fini(&vram->mm);
return ret;
}
return 0;
}
