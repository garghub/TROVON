static int
mcp77_ram_init(struct nvkm_ram *base)
{
struct mcp77_ram *ram = mcp77_ram(base);
struct nvkm_device *device = ram->base.fb->subdev.device;
u32 dniso = ((ram->base.size - (ram->poller_base + 0x00)) >> 5) - 1;
u32 hostnb = ((ram->base.size - (ram->poller_base + 0x20)) >> 5) - 1;
u32 flush = ((ram->base.size - (ram->poller_base + 0x40)) >> 5) - 1;
nvkm_wr32(device, 0x100c18, dniso);
nvkm_mask(device, 0x100c14, 0x00000000, 0x00000001);
nvkm_wr32(device, 0x100c1c, hostnb);
nvkm_mask(device, 0x100c14, 0x00000000, 0x00000002);
nvkm_wr32(device, 0x100c24, flush);
nvkm_mask(device, 0x100c14, 0x00000000, 0x00010000);
return 0;
}
int
mcp77_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_device *device = fb->subdev.device;
u32 rsvd_head = ( 256 * 1024);
u32 rsvd_tail = (1024 * 1024) + 0x1000;
u64 base = (u64)nvkm_rd32(device, 0x100e10) << 12;
u64 size = (u64)nvkm_rd32(device, 0x100e14) << 12;
struct mcp77_ram *ram;
int ret;
if (!(ram = kzalloc(sizeof(*ram), GFP_KERNEL)))
return -ENOMEM;
*pram = &ram->base;
ret = nvkm_ram_ctor(&mcp77_ram_func, fb, NVKM_RAM_TYPE_STOLEN,
size, 0, &ram->base);
if (ret)
return ret;
ram->poller_base = size - rsvd_tail;
ram->base.stolen = base;
nvkm_mm_fini(&ram->base.vram);
return nvkm_mm_init(&ram->base.vram, rsvd_head >> NVKM_RAM_MM_SHIFT,
(size - rsvd_head - rsvd_tail) >>
NVKM_RAM_MM_SHIFT, 1);
}
