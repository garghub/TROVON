static u16
dcb_xpiod_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
u16 data = dcb_gpio_table(bios, ver, hdr, cnt, len);
if (data && *ver >= 0x40 && *hdr >= 0x06) {
u16 xpio = nvbios_rd16(bios, data + 0x04);
if (xpio) {
*ver = nvbios_rd08(bios, data + 0x00);
*hdr = nvbios_rd08(bios, data + 0x01);
*cnt = nvbios_rd08(bios, data + 0x02);
*len = nvbios_rd08(bios, data + 0x03);
return xpio;
}
}
return 0x0000;
}
u16
dcb_xpio_table(struct nvkm_bios *bios, u8 idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
u16 data = dcb_xpiod_table(bios, ver, hdr, cnt, len);
if (data && idx < *cnt) {
u16 xpio = nvbios_rd16(bios, data + *hdr + (idx * *len));
if (xpio) {
*ver = nvbios_rd08(bios, data + 0x00);
*hdr = nvbios_rd08(bios, data + 0x01);
*cnt = nvbios_rd08(bios, data + 0x02);
*len = nvbios_rd08(bios, data + 0x03);
return xpio;
}
}
return 0x0000;
}
u16
dcb_xpio_parse(struct nvkm_bios *bios, u8 idx,
u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_xpio *info)
{
u16 data = dcb_xpio_table(bios, idx, ver, hdr, cnt, len);
if (data && *len >= 6) {
info->type = nvbios_rd08(bios, data + 0x04);
info->addr = nvbios_rd08(bios, data + 0x05);
info->flags = nvbios_rd08(bios, data + 0x06);
}
return 0x0000;
}
