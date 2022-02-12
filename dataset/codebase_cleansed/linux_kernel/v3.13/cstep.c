u16
nvbios_cstepTe(struct nouveau_bios *bios,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *xnr, u8 *xsz)
{
struct bit_entry bit_P;
u16 cstep = 0x0000;
if (!bit_entry(bios, 'P', &bit_P)) {
if (bit_P.version == 2)
cstep = nv_ro16(bios, bit_P.offset + 0x34);
if (cstep) {
*ver = nv_ro08(bios, cstep + 0);
switch (*ver) {
case 0x10:
*hdr = nv_ro08(bios, cstep + 1);
*cnt = nv_ro08(bios, cstep + 3);
*len = nv_ro08(bios, cstep + 2);
*xnr = nv_ro08(bios, cstep + 5);
*xsz = nv_ro08(bios, cstep + 4);
return cstep;
default:
break;
}
}
}
return 0x0000;
}
u16
nvbios_cstepEe(struct nouveau_bios *bios, int idx, u8 *ver, u8 *hdr)
{
u8 cnt, len, xnr, xsz;
u16 data = nvbios_cstepTe(bios, ver, hdr, &cnt, &len, &xnr, &xsz);
if (data && idx < cnt) {
data = data + *hdr + (idx * len);
*hdr = len;
return data;
}
return 0x0000;
}
u16
nvbios_cstepEp(struct nouveau_bios *bios, int idx, u8 *ver, u8 *hdr,
struct nvbios_cstepE *info)
{
u16 data = nvbios_cstepEe(bios, idx, ver, hdr);
memset(info, 0x00, sizeof(*info));
if (data) {
info->pstate = (nv_ro16(bios, data + 0x00) & 0x01e0) >> 5;
info->index = nv_ro08(bios, data + 0x03);
}
return data;
}
u16
nvbios_cstepEm(struct nouveau_bios *bios, u8 pstate, u8 *ver, u8 *hdr,
struct nvbios_cstepE *info)
{
u32 data, idx = 0;
while ((data = nvbios_cstepEp(bios, idx++, ver, hdr, info))) {
if (info->pstate == pstate)
break;
}
return data;
}
u16
nvbios_cstepXe(struct nouveau_bios *bios, int idx, u8 *ver, u8 *hdr)
{
u8 cnt, len, xnr, xsz;
u16 data = nvbios_cstepTe(bios, ver, hdr, &cnt, &len, &xnr, &xsz);
if (data && idx < xnr) {
data = data + *hdr + (cnt * len) + (idx * xsz);
*hdr = xsz;
return data;
}
return 0x0000;
}
u16
nvbios_cstepXp(struct nouveau_bios *bios, int idx, u8 *ver, u8 *hdr,
struct nvbios_cstepX *info)
{
u16 data = nvbios_cstepXe(bios, idx, ver, hdr);
memset(info, 0x00, sizeof(*info));
if (data) {
info->freq = nv_ro16(bios, data + 0x00) * 1000;
info->unkn[0] = nv_ro08(bios, data + 0x02);
info->unkn[1] = nv_ro08(bios, data + 0x03);
info->voltage = nv_ro08(bios, data + 0x04);
}
return data;
}
