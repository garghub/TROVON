u16
mxm_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr)
{
struct nvkm_subdev *subdev = &bios->subdev;
struct bit_entry x;
if (bit_entry(bios, 'x', &x)) {
nvkm_debug(subdev, "BIT 'x' table not present\n");
return 0x0000;
}
*ver = x.version;
*hdr = x.length;
if (*ver != 1 || *hdr < 3) {
nvkm_warn(subdev, "BIT 'x' table %d/%d unknown\n", *ver, *hdr);
return 0x0000;
}
return x.offset;
}
u8
mxm_sor_map(struct nvkm_bios *bios, u8 conn)
{
struct nvkm_subdev *subdev = &bios->subdev;
u8 ver, hdr;
u16 mxm = mxm_table(bios, &ver, &hdr);
if (mxm && hdr >= 6) {
u16 map = nvbios_rd16(bios, mxm + 4);
if (map) {
ver = nvbios_rd08(bios, map);
if (ver == 0x10 || ver == 0x11) {
if (conn < nvbios_rd08(bios, map + 3)) {
map += nvbios_rd08(bios, map + 1);
map += conn;
return nvbios_rd08(bios, map);
}
return 0x00;
}
nvkm_warn(subdev, "unknown sor map v%02x\n", ver);
}
}
if (bios->version.chip == 0x84 || bios->version.chip == 0x86)
return g84_sor_map[conn];
if (bios->version.chip == 0x92)
return g92_sor_map[conn];
if (bios->version.chip == 0x94 || bios->version.chip == 0x96)
return g94_sor_map[conn];
if (bios->version.chip == 0x98)
return g98_sor_map[conn];
nvkm_warn(subdev, "missing sor map\n");
return 0x00;
}
u8
mxm_ddc_map(struct nvkm_bios *bios, u8 port)
{
struct nvkm_subdev *subdev = &bios->subdev;
u8 ver, hdr;
u16 mxm = mxm_table(bios, &ver, &hdr);
if (mxm && hdr >= 8) {
u16 map = nvbios_rd16(bios, mxm + 6);
if (map) {
ver = nvbios_rd08(bios, map);
if (ver == 0x10) {
if (port < nvbios_rd08(bios, map + 3)) {
map += nvbios_rd08(bios, map + 1);
map += port;
return nvbios_rd08(bios, map);
}
return 0x00;
}
nvkm_warn(subdev, "unknown ddc map v%02x\n", ver);
}
}
return (port << 4) | port;
}
