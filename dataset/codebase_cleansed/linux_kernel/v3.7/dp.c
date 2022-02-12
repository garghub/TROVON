u16
dp_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
struct bit_entry bit_d;
if (!bit_entry(bios, 'd', &bit_d)) {
if (bit_d.version == 1) {
u16 data = nv_ro16(bios, bit_d.offset);
if (data) {
*ver = nv_ro08(bios, data + 0);
*hdr = nv_ro08(bios, data + 1);
*len = nv_ro08(bios, data + 2);
*cnt = nv_ro08(bios, data + 3);
return data;
}
}
}
return 0x0000;
}
u16
dp_outp(struct nouveau_bios *bios, u8 idx, u8 *ver, u8 *len)
{
u8 hdr, cnt;
u16 table = dp_table(bios, ver, &hdr, &cnt, len);
if (table && idx < cnt)
return nv_ro16(bios, table + hdr + (idx * *len));
return 0xffff;
}
u16
dp_outp_match(struct nouveau_bios *bios, struct dcb_output *outp,
u8 *ver, u8 *len)
{
u8 idx = 0;
u16 data;
while ((data = dp_outp(bios, idx++, ver, len)) != 0xffff) {
if (data) {
u32 hash = nv_ro32(bios, data);
if (dcb_hash_match(outp, hash))
return data;
}
}
return 0x0000;
}
