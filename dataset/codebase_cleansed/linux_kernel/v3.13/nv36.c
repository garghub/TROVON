static void
nv36_fb_tile_comp(struct nouveau_fb *pfb, int i, u32 size, u32 flags,
struct nouveau_fb_tile *tile)
{
u32 tiles = DIV_ROUND_UP(size, 0x40);
u32 tags = round_up(tiles / pfb->ram->parts, 0x40);
if (!nouveau_mm_head(&pfb->tags, 1, tags, tags, 1, &tile->tag)) {
if (flags & 2) tile->zcomp |= 0x10000000;
else tile->zcomp |= 0x20000000;
tile->zcomp |= ((tile->tag->offset ) >> 6);
tile->zcomp |= ((tile->tag->offset + tags - 1) >> 6) << 14;
#ifdef __BIG_ENDIAN
tile->zcomp |= 0x80000000;
#endif
}
}
