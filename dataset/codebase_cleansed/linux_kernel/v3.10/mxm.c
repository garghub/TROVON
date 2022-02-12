u16
mxm_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr)
{
struct bit_entry x;
if (bit_entry(bios, 'x', &x)) {
nv_debug(bios, "BIT 'x' table not present\n");
return 0x0000;
}
*ver = x.version;
*hdr = x.length;
if (*ver != 1 || *hdr < 3) {
nv_warn(bios, "BIT 'x' table %d/%d unknown\n", *ver, *hdr);
return 0x0000;
}
return x.offset;
}
u8
mxm_sor_map(struct nouveau_bios *bios, u8 conn)
{
u8 ver, hdr;
u16 mxm = mxm_table(bios, &ver, &hdr);
if (mxm && hdr >= 6) {
u16 map = nv_ro16(bios, mxm + 4);
if (map) {
ver = nv_ro08(bios, map);
if (ver == 0x10) {
if (conn < nv_ro08(bios, map + 3)) {
map += nv_ro08(bios, map + 1);
map += conn;
return nv_ro08(bios, map);
}
return 0x00;
}
nv_warn(bios, "unknown sor map v%02x\n", ver);
}
}
if (bios->version.chip == 0x84 || bios->version.chip == 0x86)
return nv84_sor_map[conn];
if (bios->version.chip == 0x92)
return nv92_sor_map[conn];
if (bios->version.chip == 0x94 || bios->version.chip == 0x96)
return nv94_sor_map[conn];
if (bios->version.chip == 0x98)
return nv98_sor_map[conn];
nv_warn(bios, "missing sor map\n");
return 0x00;
}
u8
mxm_ddc_map(struct nouveau_bios *bios, u8 port)
{
u8 ver, hdr;
u16 mxm = mxm_table(bios, &ver, &hdr);
if (mxm && hdr >= 8) {
u16 map = nv_ro16(bios, mxm + 6);
if (map) {
ver = nv_ro08(bios, map);
if (ver == 0x10) {
if (port < nv_ro08(bios, map + 3)) {
map += nv_ro08(bios, map + 1);
map += port;
return nv_ro08(bios, map);
}
return 0x00;
}
nv_warn(bios, "unknown ddc map v%02x\n", ver);
}
}
return (port << 4) | port;
}
