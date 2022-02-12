u32
nvbios_pcirTe(struct nouveau_bios *bios, u32 base, u8 *ver, u16 *hdr)
{
u32 data = nv_ro16(bios, base + 0x18);
if (data) {
data += base;
switch (nv_ro32(bios, data + 0x00)) {
case 0x52494350:
case 0x53494752:
case 0x5344504e:
*hdr = nv_ro16(bios, data + 0x0a);
*ver = nv_ro08(bios, data + 0x0c);
break;
default:
nv_debug(bios, "%08x: PCIR signature (%08x) unknown\n",
data, nv_ro32(bios, data + 0x00));
data = 0;
break;
}
}
return data;
}
u32
nvbios_pcirTp(struct nouveau_bios *bios, u32 base, u8 *ver, u16 *hdr,
struct nvbios_pcirT *info)
{
u32 data = nvbios_pcirTe(bios, base, ver, hdr);
memset(info, 0x00, sizeof(*info));
if (data) {
info->vendor_id = nv_ro16(bios, data + 0x04);
info->device_id = nv_ro16(bios, data + 0x06);
info->class_code[0] = nv_ro08(bios, data + 0x0d);
info->class_code[1] = nv_ro08(bios, data + 0x0e);
info->class_code[2] = nv_ro08(bios, data + 0x0f);
info->image_size = nv_ro16(bios, data + 0x10) * 512;
info->image_rev = nv_ro16(bios, data + 0x12);
info->image_type = nv_ro08(bios, data + 0x14);
info->last = nv_ro08(bios, data + 0x15) & 0x80;
}
return data;
}
