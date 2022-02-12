u16
nvbios_rammap_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr,
u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
struct bit_entry bit_P;
u16 rammap = 0x0000;
if (!bit_entry(bios, 'P', &bit_P)) {
if (bit_P.version == 2)
rammap = nv_ro16(bios, bit_P.offset + 4);
if (rammap) {
*ver = nv_ro08(bios, rammap + 0);
switch (*ver) {
case 0x10:
case 0x11:
*hdr = nv_ro08(bios, rammap + 1);
*cnt = nv_ro08(bios, rammap + 5);
*len = nv_ro08(bios, rammap + 2);
*snr = nv_ro08(bios, rammap + 4);
*ssz = nv_ro08(bios, rammap + 3);
return rammap;
default:
break;
}
}
}
return 0x0000;
}
u16
nvbios_rammap_entry(struct nouveau_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
u8 snr, ssz;
u16 rammap = nvbios_rammap_table(bios, ver, hdr, cnt, len, &snr, &ssz);
if (rammap && idx < *cnt) {
rammap = rammap + *hdr + (idx * (*len + (snr * ssz)));
*hdr = *len;
*cnt = snr;
*len = ssz;
return rammap;
}
return 0x0000;
}
u16
nvbios_rammap_match(struct nouveau_bios *bios, u16 khz,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
int idx = 0;
u32 data;
while ((data = nvbios_rammap_entry(bios, idx++, ver, hdr, cnt, len))) {
if (khz >= nv_ro16(bios, data + 0x00) &&
khz <= nv_ro16(bios, data + 0x02))
break;
}
return data;
}
