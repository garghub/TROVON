static u8
nvbios_ramcfg_strap(struct nvkm_subdev *subdev)
{
return (nvkm_rd32(subdev->device, 0x101000) & 0x0000003c) >> 2;
}
u8
nvbios_ramcfg_count(struct nvkm_bios *bios)
{
struct bit_entry bit_M;
if (!bit_entry(bios, 'M', &bit_M)) {
if (bit_M.version == 1 && bit_M.length >= 5)
return nvbios_rd08(bios, bit_M.offset + 2);
if (bit_M.version == 2 && bit_M.length >= 3)
return nvbios_rd08(bios, bit_M.offset + 0);
}
return 0x00;
}
u8
nvbios_ramcfg_index(struct nvkm_subdev *subdev)
{
struct nvkm_bios *bios = subdev->device->bios;
u8 strap = nvbios_ramcfg_strap(subdev);
u32 xlat = 0x00000000;
struct bit_entry bit_M;
struct nvbios_M0203E M0203E;
u8 ver, hdr;
if (!bit_entry(bios, 'M', &bit_M)) {
if (bit_M.version == 1 && bit_M.length >= 5)
xlat = nvbios_rd16(bios, bit_M.offset + 3);
if (bit_M.version == 2 && bit_M.length >= 3) {
if (bit_M.length >= 7 &&
nvbios_M0203Em(bios, strap, &ver, &hdr, &M0203E))
return M0203E.group;
xlat = nvbios_rd16(bios, bit_M.offset + 1);
}
}
if (xlat)
strap = nvbios_rd08(bios, xlat + strap);
return strap;
}
