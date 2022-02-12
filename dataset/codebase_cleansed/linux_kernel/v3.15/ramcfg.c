static u8
nvbios_ramcfg_strap(struct nouveau_subdev *subdev)
{
return (nv_rd32(subdev, 0x101000) & 0x0000003c) >> 2;
}
u8
nvbios_ramcfg_count(struct nouveau_bios *bios)
{
struct bit_entry bit_M;
if (!bit_entry(bios, 'M', &bit_M)) {
if (bit_M.version == 1 && bit_M.length >= 5)
return nv_ro08(bios, bit_M.offset + 2);
if (bit_M.version == 2 && bit_M.length >= 3)
return nv_ro08(bios, bit_M.offset + 0);
}
return 0x00;
}
u8
nvbios_ramcfg_index(struct nouveau_subdev *subdev)
{
struct nouveau_bios *bios = nouveau_bios(subdev);
u8 strap = nvbios_ramcfg_strap(subdev);
u32 xlat = 0x00000000;
struct bit_entry bit_M;
if (!bit_entry(bios, 'M', &bit_M)) {
if (bit_M.version == 1 && bit_M.length >= 5)
xlat = nv_ro16(bios, bit_M.offset + 3);
if (bit_M.version == 2 && bit_M.length >= 3)
xlat = nv_ro16(bios, bit_M.offset + 1);
}
if (xlat)
strap = nv_ro08(bios, xlat + strap);
return strap;
}
