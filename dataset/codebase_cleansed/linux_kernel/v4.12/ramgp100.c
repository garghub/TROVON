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
static u32
gp100_ram_probe_fbpa(struct nvkm_device *device, int fbpa)
{
return nvkm_rd32(device, 0x90020c + (fbpa * 0x4000));
}
int
gp100_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_ram *ram;
if (!(ram = *pram = kzalloc(sizeof(*ram), GFP_KERNEL)))
return -ENOMEM;
return gf100_ram_ctor(&gp100_ram, fb, ram);
}
