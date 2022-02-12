void
nv46_fb_tile_init(struct nouveau_fb *pfb, int i, u32 addr, u32 size, u32 pitch,
u32 flags, struct nouveau_fb_tile *tile)
{
if (!(flags & 4)) tile->addr = (0 << 3);
else tile->addr = (1 << 3);
tile->addr |= 0x00000001;
tile->addr |= addr;
tile->limit = max(1u, addr + size) - 1;
tile->pitch = pitch;
}
