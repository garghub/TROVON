u32
nvbios_M0209Te(struct nouveau_bios *bios,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
struct bit_entry bit_M;
u32 data = 0x00000000;
if (!bit_entry(bios, 'M', &bit_M)) {
if (bit_M.version == 2 && bit_M.length > 0x0c)
data = nv_ro32(bios, bit_M.offset + 0x09);
if (data) {
*ver = nv_ro08(bios, data + 0x00);
switch (*ver) {
case 0x10:
*hdr = nv_ro08(bios, data + 0x01);
*len = nv_ro08(bios, data + 0x02);
*ssz = nv_ro08(bios, data + 0x03);
*snr = 1;
*cnt = nv_ro08(bios, data + 0x04);
return data;
default:
break;
}
}
}
return 0x00000000;
}
u32
nvbios_M0209Ee(struct nouveau_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
u8 snr, ssz;
u32 data = nvbios_M0209Te(bios, ver, hdr, cnt, len, &snr, &ssz);
if (data && idx < *cnt) {
data = data + *hdr + idx * (*len + (snr * ssz));
*hdr = *len;
*cnt = snr;
*len = ssz;
return data;
}
return 0x00000000;
}
u32
nvbios_M0209Ep(struct nouveau_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len,
struct nvbios_M0209E *info)
{
u32 data = nvbios_M0209Ee(bios, idx, ver, hdr, cnt, len);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
info->v00_40 = (nv_ro08(bios, data + 0x00) & 0x40) >> 6;
info->bits = nv_ro08(bios, data + 0x00) & 0x3f;
info->modulo = nv_ro08(bios, data + 0x01);
info->v02_40 = (nv_ro08(bios, data + 0x02) & 0x40) >> 6;
info->v02_07 = nv_ro08(bios, data + 0x02) & 0x07;
info->v03 = nv_ro08(bios, data + 0x03);
return data;
default:
break;
}
return 0x00000000;
}
u32
nvbios_M0209Se(struct nouveau_bios *bios, int ent, int idx, u8 *ver, u8 *hdr)
{
u8 cnt, len;
u32 data = nvbios_M0209Ee(bios, ent, ver, hdr, &cnt, &len);
if (data && idx < cnt) {
data = data + *hdr + idx * len;
*hdr = len;
return data;
}
return 0x00000000;
}
u32
nvbios_M0209Sp(struct nouveau_bios *bios, int ent, int idx, u8 *ver, u8 *hdr,
struct nvbios_M0209S *info)
{
struct nvbios_M0209E M0209E;
u8 cnt, len;
u32 data = nvbios_M0209Ep(bios, ent, ver, hdr, &cnt, &len, &M0209E);
if (data) {
u32 i, data = nvbios_M0209Se(bios, ent, idx, ver, hdr);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
for (i = 0; i < ARRAY_SIZE(info->data); i++) {
u32 bits = (i % M0209E.modulo) * M0209E.bits;
u32 mask = (1ULL << M0209E.bits) - 1;
u16 off = bits / 8;
u8 mod = bits % 8;
info->data[i] = nv_ro32(bios, data + off);
info->data[i] = info->data[i] >> mod;
info->data[i] = info->data[i] & mask;
}
return data;
default:
break;
}
}
return 0x00000000;
}
