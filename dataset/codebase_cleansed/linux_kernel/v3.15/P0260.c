u32
nvbios_P0260Te(struct nouveau_bios *bios,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *xnr, u8 *xsz)
{
struct bit_entry bit_P;
u32 data = 0x00000000;
if (!bit_entry(bios, 'P', &bit_P)) {
if (bit_P.version == 2 && bit_P.length > 0x63)
data = nv_ro32(bios, bit_P.offset + 0x60);
if (data) {
*ver = nv_ro08(bios, data + 0);
switch (*ver) {
case 0x10:
*hdr = nv_ro08(bios, data + 1);
*cnt = nv_ro08(bios, data + 2);
*len = 4;
*xnr = nv_ro08(bios, data + 3);
*xsz = 4;
return data;
default:
break;
}
}
}
return 0x00000000;
}
u32
nvbios_P0260Ee(struct nouveau_bios *bios, int idx, u8 *ver, u8 *len)
{
u8 hdr, cnt, xnr, xsz;
u32 data = nvbios_P0260Te(bios, ver, &hdr, &cnt, len, &xnr, &xsz);
if (data && idx < cnt)
return data + hdr + (idx * *len);
return 0x00000000;
}
u32
nvbios_P0260Ep(struct nouveau_bios *bios, int idx, u8 *ver, u8 *len,
struct nvbios_P0260E *info)
{
u32 data = nvbios_P0260Ee(bios, idx, ver, len);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
info->data = nv_ro32(bios, data);
return data;
default:
break;
}
return 0x00000000;
}
u32
nvbios_P0260Xe(struct nouveau_bios *bios, int idx, u8 *ver, u8 *xsz)
{
u8 hdr, cnt, len, xnr;
u32 data = nvbios_P0260Te(bios, ver, &hdr, &cnt, &len, &xnr, xsz);
if (data && idx < xnr)
return data + hdr + (cnt * len) + (idx * *xsz);
return 0x00000000;
}
u32
nvbios_P0260Xp(struct nouveau_bios *bios, int idx, u8 *ver, u8 *hdr,
struct nvbios_P0260X *info)
{
u32 data = nvbios_P0260Xe(bios, idx, ver, hdr);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
info->data = nv_ro32(bios, data);
return data;
default:
break;
}
return 0x00000000;
}
