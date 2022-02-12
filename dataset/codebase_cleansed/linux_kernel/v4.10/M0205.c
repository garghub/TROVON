u32
nvbios_M0205Te(struct nvkm_bios *bios,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
struct bit_entry bit_M;
u32 data = 0x00000000;
if (!bit_entry(bios, 'M', &bit_M)) {
if (bit_M.version == 2 && bit_M.length > 0x08)
data = nvbios_rd32(bios, bit_M.offset + 0x05);
if (data) {
*ver = nvbios_rd08(bios, data + 0x00);
switch (*ver) {
case 0x10:
*hdr = nvbios_rd08(bios, data + 0x01);
*len = nvbios_rd08(bios, data + 0x02);
*ssz = nvbios_rd08(bios, data + 0x03);
*snr = nvbios_rd08(bios, data + 0x04);
*cnt = nvbios_rd08(bios, data + 0x05);
return data;
default:
break;
}
}
}
return 0x00000000;
}
u32
nvbios_M0205Tp(struct nvkm_bios *bios,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *snr, u8 *ssz,
struct nvbios_M0205T *info)
{
u32 data = nvbios_M0205Te(bios, ver, hdr, cnt, len, snr, ssz);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
info->freq = nvbios_rd16(bios, data + 0x06);
break;
default:
break;
}
return data;
}
u32
nvbios_M0205Ee(struct nvkm_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
u8 snr, ssz;
u32 data = nvbios_M0205Te(bios, ver, hdr, cnt, len, &snr, &ssz);
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
nvbios_M0205Ep(struct nvkm_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len,
struct nvbios_M0205E *info)
{
u32 data = nvbios_M0205Ee(bios, idx, ver, hdr, cnt, len);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
info->type = nvbios_rd08(bios, data + 0x00) & 0x0f;
return data;
default:
break;
}
return 0x00000000;
}
u32
nvbios_M0205Se(struct nvkm_bios *bios, int ent, int idx, u8 *ver, u8 *hdr)
{
u8 cnt, len;
u32 data = nvbios_M0205Ee(bios, ent, ver, hdr, &cnt, &len);
if (data && idx < cnt) {
data = data + *hdr + idx * len;
*hdr = len;
return data;
}
return 0x00000000;
}
u32
nvbios_M0205Sp(struct nvkm_bios *bios, int ent, int idx, u8 *ver, u8 *hdr,
struct nvbios_M0205S *info)
{
u32 data = nvbios_M0205Se(bios, ent, idx, ver, hdr);
memset(info, 0x00, sizeof(*info));
switch (!!data * *ver) {
case 0x10:
info->data = nvbios_rd08(bios, data + 0x00);
return data;
default:
break;
}
return 0x00000000;
}
