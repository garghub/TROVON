void
nv10_fb_tile_init(struct nvkm_fb *pfb, int i, u32 addr, u32 size, u32 pitch,
u32 flags, struct nvkm_fb_tile *tile)
{
tile->addr = 0x80000000 | addr;
tile->limit = max(1u, addr + size) - 1;
tile->pitch = pitch;
}
void
nv10_fb_tile_fini(struct nvkm_fb *pfb, int i, struct nvkm_fb_tile *tile)
{
tile->addr = 0;
tile->limit = 0;
tile->pitch = 0;
tile->zcomp = 0;
}
void
nv10_fb_tile_prog(struct nvkm_fb *pfb, int i, struct nvkm_fb_tile *tile)
{
nv_wr32(pfb, 0x100244 + (i * 0x10), tile->limit);
nv_wr32(pfb, 0x100248 + (i * 0x10), tile->pitch);
nv_wr32(pfb, 0x100240 + (i * 0x10), tile->addr);
nv_rd32(pfb, 0x100240 + (i * 0x10));
}
