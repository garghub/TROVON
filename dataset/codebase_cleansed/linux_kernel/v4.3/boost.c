u16
nvbios_boostTe(struct nvkm_bios *bios,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
struct bit_entry bit_P;
u16 boost = 0x0000;
if (!bit_entry(bios, 'P', &bit_P)) {
if (bit_P.version == 2)
boost = nvbios_rd16(bios, bit_P.offset + 0x30);
if (boost) {
*ver = nvbios_rd08(bios, boost + 0);
switch (*ver) {
case 0x11:
*hdr = nvbios_rd08(bios, boost + 1);
*cnt = nvbios_rd08(bios, boost + 5);
*len = nvbios_rd08(bios, boost + 2);
*snr = nvbios_rd08(bios, boost + 4);
*ssz = nvbios_rd08(bios, boost + 3);
return boost;
default:
break;
}
}
}
return 0x0000;
}
u16
nvbios_boostEe(struct nvkm_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
u8 snr, ssz;
u16 data = nvbios_boostTe(bios, ver, hdr, cnt, len, &snr, &ssz);
if (data && idx < *cnt) {
data = data + *hdr + (idx * (*len + (snr * ssz)));
*hdr = *len;
*cnt = snr;
*len = ssz;
return data;
}
return 0x0000;
}
u16
nvbios_boostEp(struct nvkm_bios *bios, int idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_boostE *info)
{
u16 data = nvbios_boostEe(bios, idx, ver, hdr, cnt, len);
memset(info, 0x00, sizeof(*info));
if (data) {
info->pstate = (nvbios_rd16(bios, data + 0x00) & 0x01e0) >> 5;
info->min = nvbios_rd16(bios, data + 0x02) * 1000;
info->max = nvbios_rd16(bios, data + 0x04) * 1000;
}
return data;
}
u16
nvbios_boostEm(struct nvkm_bios *bios, u8 pstate,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_boostE *info)
{
u32 data, idx = 0;
while ((data = nvbios_boostEp(bios, idx++, ver, hdr, cnt, len, info))) {
if (info->pstate == pstate)
break;
}
return data;
}
u16
nvbios_boostSe(struct nvkm_bios *bios, int idx,
u16 data, u8 *ver, u8 *hdr, u8 cnt, u8 len)
{
if (data && idx < cnt) {
data = data + *hdr + (idx * len);
*hdr = len;
return data;
}
return 0x0000;
}
u16
nvbios_boostSp(struct nvkm_bios *bios, int idx,
u16 data, u8 *ver, u8 *hdr, u8 cnt, u8 len,
struct nvbios_boostS *info)
{
data = nvbios_boostSe(bios, idx, data, ver, hdr, cnt, len);
memset(info, 0x00, sizeof(*info));
if (data) {
info->domain = nvbios_rd08(bios, data + 0x00);
info->percent = nvbios_rd08(bios, data + 0x01);
info->min = nvbios_rd16(bios, data + 0x02) * 1000;
info->max = nvbios_rd16(bios, data + 0x04) * 1000;
}
return data;
}
