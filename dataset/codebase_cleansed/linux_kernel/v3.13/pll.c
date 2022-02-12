static u16
pll_limits_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
struct bit_entry bit_C;
if (!bit_entry(bios, 'C', &bit_C) && bit_C.length >= 10) {
u16 data = nv_ro16(bios, bit_C.offset + 8);
if (data) {
*ver = nv_ro08(bios, data + 0);
*hdr = nv_ro08(bios, data + 1);
*len = nv_ro08(bios, data + 2);
*cnt = nv_ro08(bios, data + 3);
return data;
}
}
if (bmp_version(bios) >= 0x0524) {
u16 data = nv_ro16(bios, bios->bmp_offset + 142);
if (data) {
*ver = nv_ro08(bios, data + 0);
*hdr = 1;
*cnt = 1;
*len = 0x18;
return data;
}
}
*ver = 0x00;
return 0x0000;
}
static struct pll_mapping *
pll_map(struct nouveau_bios *bios)
{
switch (nv_device(bios)->card_type) {
case NV_04:
case NV_10:
case NV_11:
case NV_20:
case NV_30:
return nv04_pll_mapping;
break;
case NV_40:
return nv40_pll_mapping;
case NV_50:
if (nv_device(bios)->chipset == 0x50)
return nv50_pll_mapping;
else
if (nv_device(bios)->chipset < 0xa3 ||
nv_device(bios)->chipset == 0xaa ||
nv_device(bios)->chipset == 0xac)
return nv84_pll_mapping;
default:
return NULL;
}
}
static u16
pll_map_reg(struct nouveau_bios *bios, u32 reg, u32 *type, u8 *ver, u8 *len)
{
struct pll_mapping *map;
u8 hdr, cnt;
u16 data;
data = pll_limits_table(bios, ver, &hdr, &cnt, len);
if (data && *ver >= 0x30) {
data += hdr;
while (cnt--) {
if (nv_ro32(bios, data + 3) == reg) {
*type = nv_ro08(bios, data + 0);
return data;
}
data += *len;
}
return 0x0000;
}
map = pll_map(bios);
while (map->reg) {
if (map->reg == reg && *ver >= 0x20) {
u16 addr = (data += hdr);
*type = map->type;
while (cnt--) {
if (nv_ro32(bios, data) == map->reg)
return data;
data += *len;
}
return addr;
} else
if (map->reg == reg) {
*type = map->type;
return data + 1;
}
map++;
}
return 0x0000;
}
static u16
pll_map_type(struct nouveau_bios *bios, u8 type, u32 *reg, u8 *ver, u8 *len)
{
struct pll_mapping *map;
u8 hdr, cnt;
u16 data;
data = pll_limits_table(bios, ver, &hdr, &cnt, len);
if (data && *ver >= 0x30) {
data += hdr;
while (cnt--) {
if (nv_ro08(bios, data + 0) == type) {
*reg = nv_ro32(bios, data + 3);
return data;
}
data += *len;
}
return 0x0000;
}
map = pll_map(bios);
while (map->reg) {
if (map->type == type && *ver >= 0x20) {
u16 addr = (data += hdr);
*reg = map->reg;
while (cnt--) {
if (nv_ro32(bios, data) == map->reg)
return data;
data += *len;
}
return addr;
} else
if (map->type == type) {
*reg = map->reg;
return data + 1;
}
map++;
}
return 0x0000;
}
int
nvbios_pll_parse(struct nouveau_bios *bios, u32 type, struct nvbios_pll *info)
{
u8 ver, len;
u32 reg = type;
u16 data;
if (type > PLL_MAX) {
reg = type;
data = pll_map_reg(bios, reg, &type, &ver, &len);
} else {
data = pll_map_type(bios, type, &reg, &ver, &len);
}
if (ver && !data)
return -ENOENT;
memset(info, 0, sizeof(*info));
info->type = type;
info->reg = reg;
switch (ver) {
case 0x00:
break;
case 0x10:
case 0x11:
info->vco1.min_freq = nv_ro32(bios, data + 0);
info->vco1.max_freq = nv_ro32(bios, data + 4);
info->vco2.min_freq = nv_ro32(bios, data + 8);
info->vco2.max_freq = nv_ro32(bios, data + 12);
info->vco1.min_inputfreq = nv_ro32(bios, data + 16);
info->vco2.min_inputfreq = nv_ro32(bios, data + 20);
info->vco1.max_inputfreq = INT_MAX;
info->vco2.max_inputfreq = INT_MAX;
info->max_p = 0x7;
info->max_p_usable = 0x6;
switch (bios->version.chip) {
case 0x36:
info->vco1.min_n = 0x5;
break;
default:
info->vco1.min_n = 0x1;
break;
}
info->vco1.max_n = 0xff;
info->vco1.min_m = 0x1;
info->vco1.max_m = 0xd;
info->vco2.min_n = 0x4;
switch (bios->version.chip) {
case 0x30:
case 0x35:
info->vco2.max_n = 0x1f;
break;
default:
info->vco2.max_n = 0x28;
break;
}
info->vco2.min_m = 0x1;
info->vco2.max_m = 0x4;
break;
case 0x20:
case 0x21:
info->vco1.min_freq = nv_ro16(bios, data + 4) * 1000;
info->vco1.max_freq = nv_ro16(bios, data + 6) * 1000;
info->vco2.min_freq = nv_ro16(bios, data + 8) * 1000;
info->vco2.max_freq = nv_ro16(bios, data + 10) * 1000;
info->vco1.min_inputfreq = nv_ro16(bios, data + 12) * 1000;
info->vco2.min_inputfreq = nv_ro16(bios, data + 14) * 1000;
info->vco1.max_inputfreq = nv_ro16(bios, data + 16) * 1000;
info->vco2.max_inputfreq = nv_ro16(bios, data + 18) * 1000;
info->vco1.min_n = nv_ro08(bios, data + 20);
info->vco1.max_n = nv_ro08(bios, data + 21);
info->vco1.min_m = nv_ro08(bios, data + 22);
info->vco1.max_m = nv_ro08(bios, data + 23);
info->vco2.min_n = nv_ro08(bios, data + 24);
info->vco2.max_n = nv_ro08(bios, data + 25);
info->vco2.min_m = nv_ro08(bios, data + 26);
info->vco2.max_m = nv_ro08(bios, data + 27);
info->max_p = nv_ro08(bios, data + 29);
info->max_p_usable = info->max_p;
if (bios->version.chip < 0x60)
info->max_p_usable = 0x6;
info->bias_p = nv_ro08(bios, data + 30);
if (len > 0x22)
info->refclk = nv_ro32(bios, data + 31);
break;
case 0x30:
data = nv_ro16(bios, data + 1);
info->vco1.min_freq = nv_ro16(bios, data + 0) * 1000;
info->vco1.max_freq = nv_ro16(bios, data + 2) * 1000;
info->vco2.min_freq = nv_ro16(bios, data + 4) * 1000;
info->vco2.max_freq = nv_ro16(bios, data + 6) * 1000;
info->vco1.min_inputfreq = nv_ro16(bios, data + 8) * 1000;
info->vco2.min_inputfreq = nv_ro16(bios, data + 10) * 1000;
info->vco1.max_inputfreq = nv_ro16(bios, data + 12) * 1000;
info->vco2.max_inputfreq = nv_ro16(bios, data + 14) * 1000;
info->vco1.min_n = nv_ro08(bios, data + 16);
info->vco1.max_n = nv_ro08(bios, data + 17);
info->vco1.min_m = nv_ro08(bios, data + 18);
info->vco1.max_m = nv_ro08(bios, data + 19);
info->vco2.min_n = nv_ro08(bios, data + 20);
info->vco2.max_n = nv_ro08(bios, data + 21);
info->vco2.min_m = nv_ro08(bios, data + 22);
info->vco2.max_m = nv_ro08(bios, data + 23);
info->max_p_usable = info->max_p = nv_ro08(bios, data + 25);
info->bias_p = nv_ro08(bios, data + 27);
info->refclk = nv_ro32(bios, data + 28);
break;
case 0x40:
info->refclk = nv_ro16(bios, data + 9) * 1000;
data = nv_ro16(bios, data + 1);
info->vco1.min_freq = nv_ro16(bios, data + 0) * 1000;
info->vco1.max_freq = nv_ro16(bios, data + 2) * 1000;
info->vco1.min_inputfreq = nv_ro16(bios, data + 4) * 1000;
info->vco1.max_inputfreq = nv_ro16(bios, data + 6) * 1000;
info->vco1.min_m = nv_ro08(bios, data + 8);
info->vco1.max_m = nv_ro08(bios, data + 9);
info->vco1.min_n = nv_ro08(bios, data + 10);
info->vco1.max_n = nv_ro08(bios, data + 11);
info->min_p = nv_ro08(bios, data + 12);
info->max_p = nv_ro08(bios, data + 13);
break;
default:
nv_error(bios, "unknown pll limits version 0x%02x\n", ver);
return -EINVAL;
}
if (!info->refclk) {
info->refclk = nv_device(bios)->crystal;
if (bios->version.chip == 0x51) {
u32 sel_clk = nv_rd32(bios, 0x680524);
if ((info->reg == 0x680508 && sel_clk & 0x20) ||
(info->reg == 0x680520 && sel_clk & 0x80)) {
if (nv_rdvgac(bios, 0, 0x27) < 0xa3)
info->refclk = 200000;
else
info->refclk = 25000;
}
}
}
if (!info->vco1.max_freq) {
info->vco1.max_freq = nv_ro32(bios, bios->bmp_offset + 67);
info->vco1.min_freq = nv_ro32(bios, bios->bmp_offset + 71);
if (bmp_version(bios) < 0x0506) {
info->vco1.max_freq = 256000;
info->vco1.min_freq = 128000;
}
info->vco1.min_inputfreq = 0;
info->vco1.max_inputfreq = INT_MAX;
info->vco1.min_n = 0x1;
info->vco1.max_n = 0xff;
info->vco1.min_m = 0x1;
if (nv_device(bios)->crystal == 13500) {
if (bios->version.chip < 0x11)
info->vco1.min_m = 0x7;
info->vco1.max_m = 0xd;
} else {
if (bios->version.chip < 0x11)
info->vco1.min_m = 0x8;
info->vco1.max_m = 0xe;
}
if (bios->version.chip < 0x17 ||
bios->version.chip == 0x1a ||
bios->version.chip == 0x20)
info->max_p = 4;
else
info->max_p = 5;
info->max_p_usable = info->max_p;
}
return 0;
}
