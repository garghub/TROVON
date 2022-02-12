static int
gp100_ram_init(struct nvkm_ram *ram)
{
struct nvkm_subdev *subdev = &ram->fb->subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_bios *bios = device->bios;
u8 ver, hdr, cnt, len, snr, ssz;
u32 data;
int i;
data = nvbios_rammapTe(bios, &ver, &hdr, &cnt, &len, &snr, &ssz);
if (!data || hdr < 0x15)
return -EINVAL;
cnt = nvbios_rd08(bios, data + 0x14);
data = nvbios_rd32(bios, data + 0x10);
if (cnt) {
u32 save = nvkm_rd32(device, 0x9a065c) & 0x000000f0;
for (i = 0; i < cnt; i++, data += 4) {
if (i != save >> 4) {
nvkm_mask(device, 0x9a065c, 0x000000f0, i << 4);
nvbios_exec(&(struct nvbios_init) {
.subdev = subdev,
.bios = bios,
.offset = nvbios_rd32(bios, data),
.execute = 1,
});
}
}
nvkm_mask(device, 0x9a065c, 0x000000f0, save);
}
nvkm_mask(device, 0x9a0584, 0x11000000, 0x00000000);
nvkm_wr32(device, 0x10ecc0, 0xffffffff);
nvkm_mask(device, 0x9a0160, 0x00000010, 0x00000010);
return 0;
}
int
gp100_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_ram *ram;
struct nvkm_subdev *subdev = &fb->subdev;
struct nvkm_device *device = subdev->device;
enum nvkm_ram_type type = nvkm_fb_bios_memtype(device->bios);
const u32 rsvd_head = ( 256 * 1024);
const u32 rsvd_tail = (1024 * 1024);
u32 fbpa_num = nvkm_rd32(device, 0x02243c), fbpa;
u32 fbio_opt = nvkm_rd32(device, 0x021c14);
u64 part, size = 0, comm = ~0ULL;
bool mixed = false;
int ret;
nvkm_debug(subdev, "02243c: %08x\n", fbpa_num);
nvkm_debug(subdev, "021c14: %08x\n", fbio_opt);
for (fbpa = 0; fbpa < fbpa_num; fbpa++) {
if (!(fbio_opt & (1 << fbpa))) {
part = nvkm_rd32(device, 0x90020c + (fbpa * 0x4000));
nvkm_debug(subdev, "fbpa %02x: %lld MiB\n", fbpa, part);
part = part << 20;
if (part != comm) {
if (comm != ~0ULL)
mixed = true;
comm = min(comm, part);
}
size = size + part;
}
}
ret = nvkm_ram_new_(&gp100_ram_func, fb, type, size, 0, &ram);
*pram = ram;
if (ret)
return ret;
nvkm_mm_fini(&ram->vram);
if (mixed) {
ret = nvkm_mm_init(&ram->vram, rsvd_head >> NVKM_RAM_MM_SHIFT,
((comm * fbpa_num) - rsvd_head) >>
NVKM_RAM_MM_SHIFT, 1);
if (ret)
return ret;
ret = nvkm_mm_init(&ram->vram, (0x1000000000ULL + comm) >>
NVKM_RAM_MM_SHIFT,
(size - (comm * fbpa_num) - rsvd_tail) >>
NVKM_RAM_MM_SHIFT, 1);
if (ret)
return ret;
} else {
ret = nvkm_mm_init(&ram->vram, rsvd_head >> NVKM_RAM_MM_SHIFT,
(size - rsvd_head - rsvd_tail) >>
NVKM_RAM_MM_SHIFT, 1);
if (ret)
return ret;
}
return 0;
}
