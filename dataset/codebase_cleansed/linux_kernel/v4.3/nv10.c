void
nv10_fb_tile_init(struct nvkm_fb *fb, int i, u32 addr, u32 size, u32 pitch,
u32 flags, struct nvkm_fb_tile *tile)
{
tile->addr = 0x80000000 | addr;
tile->limit = max(1u, addr + size) - 1;
tile->pitch = pitch;
}
void
nv10_fb_tile_fini(struct nvkm_fb *fb, int i, struct nvkm_fb_tile *tile)
{
tile->addr = 0;
tile->limit = 0;
tile->pitch = 0;
tile->zcomp = 0;
}
void
nv10_fb_tile_prog(struct nvkm_fb *fb, int i, struct nvkm_fb_tile *tile)
{
struct nvkm_device *device = fb->subdev.device;
nvkm_wr32(device, 0x100244 + (i * 0x10), tile->limit);
nvkm_wr32(device, 0x100248 + (i * 0x10), tile->pitch);
nvkm_wr32(device, 0x100240 + (i * 0x10), tile->addr);
nvkm_rd32(device, 0x100240 + (i * 0x10));
}
int
nv10_fb_new(struct nvkm_device *device, int index, struct nvkm_fb **pfb)
{
return nvkm_fb_new_(&nv10_fb, device, index, pfb);
}
