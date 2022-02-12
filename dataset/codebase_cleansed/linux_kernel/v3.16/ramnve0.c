static void
nve0_ram_train(struct nve0_ramfuc *fuc, u32 mask, u32 data)
{
struct nve0_ram *ram = container_of(fuc, typeof(*ram), fuc);
u32 addr = 0x110974, i;
ram_mask(fuc, 0x10f910, mask, data);
ram_mask(fuc, 0x10f914, mask, data);
for (i = 0; (data & 0x80000000) && i < ram->parts; addr += 0x1000, i++) {
if (ram->pmask & (1 << i))
continue;
ram_wait(fuc, addr, 0x0000000f, 0x00000000, 500000);
}
}
static void
r1373f4_init(struct nve0_ramfuc *fuc)
{
struct nve0_ram *ram = container_of(fuc, typeof(*ram), fuc);
const u32 mcoef = ((--ram->P2 << 28) | (ram->N2 << 8) | ram->M2);
const u32 rcoef = (( ram->P1 << 16) | (ram->N1 << 8) | ram->M1);
const u32 runk0 = ram->fN1 << 16;
const u32 runk1 = ram->fN1;
if (ram->from == 2) {
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00001100);
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00000010);
} else {
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00010010);
}
ram_mask(fuc, 0x1373f4, 0x00000003, 0x00000000);
ram_mask(fuc, 0x1373f4, 0x00000010, 0x00000000);
if ((ram_rd32(fuc, 0x132024) & 0xffffffff) != rcoef ||
(ram_rd32(fuc, 0x132034) & 0x0000ffff) != runk1) {
ram_mask(fuc, 0x132000, 0x00000001, 0x00000000);
ram_mask(fuc, 0x132020, 0x00000001, 0x00000000);
ram_wr32(fuc, 0x137320, 0x00000000);
ram_mask(fuc, 0x132030, 0xffff0000, runk0);
ram_mask(fuc, 0x132034, 0x0000ffff, runk1);
ram_wr32(fuc, 0x132024, rcoef);
ram_mask(fuc, 0x132028, 0x00080000, 0x00080000);
ram_mask(fuc, 0x132020, 0x00000001, 0x00000001);
ram_wait(fuc, 0x137390, 0x00020000, 0x00020000, 64000);
ram_mask(fuc, 0x132028, 0x00080000, 0x00000000);
}
if (ram->mode == 2) {
ram_mask(fuc, 0x1373f4, 0x00010000, 0x00000000);
ram_mask(fuc, 0x132000, 0x80000000, 0x80000000);
ram_mask(fuc, 0x132000, 0x00000001, 0x00000000);
ram_mask(fuc, 0x132004, 0x103fffff, mcoef);
ram_mask(fuc, 0x132000, 0x00000001, 0x00000001);
ram_wait(fuc, 0x137390, 0x00000002, 0x00000002, 64000);
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00001100);
} else {
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00010100);
}
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00000010);
}
static void
r1373f4_fini(struct nve0_ramfuc *fuc)
{
struct nve0_ram *ram = container_of(fuc, typeof(*ram), fuc);
struct nouveau_ram_data *next = ram->base.next;
u8 v0 = next->bios.ramcfg_11_03_c0;
u8 v1 = next->bios.ramcfg_11_03_30;
u32 tmp;
tmp = ram_rd32(fuc, 0x1373ec) & ~0x00030000;
ram_wr32(fuc, 0x1373ec, tmp | (v1 << 16));
ram_mask(fuc, 0x1373f0, (~ram->mode & 3), 0x00000000);
if (ram->mode == 2) {
ram_mask(fuc, 0x1373f4, 0x00000003, 0x000000002);
ram_mask(fuc, 0x1373f4, 0x00001100, 0x000000000);
} else {
ram_mask(fuc, 0x1373f4, 0x00000003, 0x000000001);
ram_mask(fuc, 0x1373f4, 0x00010000, 0x000000000);
}
ram_mask(fuc, 0x10f800, 0x00000030, (v0 ^ v1) << 4);
}
static void
nve0_ram_nuts(struct nve0_ram *ram, struct ramfuc_reg *reg,
u32 _mask, u32 _data, u32 _copy)
{
struct nve0_fb_priv *priv = (void *)nouveau_fb(ram);
struct ramfuc *fuc = &ram->fuc.base;
u32 addr = 0x110000 + (reg->addr[0] & 0xfff);
u32 mask = _mask | _copy;
u32 data = (_data & _mask) | (reg->data & _copy);
u32 i;
for (i = 0; i < 16; i++, addr += 0x1000) {
if (ram->pnuts & (1 << i)) {
u32 prev = nv_rd32(priv, addr);
u32 next = (prev & ~mask) | data;
nouveau_memx_wr32(fuc->memx, addr, next);
}
}
}
static int
nve0_ram_calc_gddr5(struct nouveau_fb *pfb, u32 freq)
{
struct nve0_ram *ram = (void *)pfb->ram;
struct nve0_ramfuc *fuc = &ram->fuc;
struct nouveau_ram_data *next = ram->base.next;
int vc = !next->bios.ramcfg_11_02_08;
int mv = !next->bios.ramcfg_11_02_04;
u32 mask, data;
ram_mask(fuc, 0x10f808, 0x40000000, 0x40000000);
ram_wr32(fuc, 0x62c000, 0x0f0f0000);
if ((ram->base.mr[1] & 0x03c) != 0x030) {
ram_mask(fuc, mr[1], 0x03c, ram->base.mr[1] & 0x03c);
ram_nuts(ram, mr[1], 0x03c, ram->base.mr1_nuts & 0x03c, 0x000);
}
if (vc == 1 && ram_have(fuc, gpio2E)) {
u32 temp = ram_mask(fuc, gpio2E, 0x3000, fuc->r_func2E[1]);
if (temp != ram_rd32(fuc, gpio2E)) {
ram_wr32(fuc, gpiotrig, 1);
ram_nsec(fuc, 20000);
}
}
ram_mask(fuc, 0x10f200, 0x00000800, 0x00000000);
nve0_ram_train(fuc, 0x01020000, 0x000c0000);
ram_wr32(fuc, 0x10f210, 0x00000000);
ram_nsec(fuc, 1000);
ram_wr32(fuc, 0x10f310, 0x00000001);
ram_nsec(fuc, 1000);
ram_mask(fuc, 0x10f200, 0x80000000, 0x80000000);
ram_wr32(fuc, 0x10f314, 0x00000001);
ram_mask(fuc, 0x10f200, 0x80000000, 0x00000000);
ram_wr32(fuc, 0x10f090, 0x00000061);
ram_wr32(fuc, 0x10f090, 0xc000007f);
ram_nsec(fuc, 1000);
ram_wr32(fuc, 0x10f698, 0x00000000);
ram_wr32(fuc, 0x10f69c, 0x00000000);
mask = 0x800f07e0;
data = 0x00030000;
if (ram_rd32(fuc, 0x10f978) & 0x00800000)
data |= 0x00040000;
if (1) {
data |= 0x800807e0;
switch (next->bios.ramcfg_11_03_c0) {
case 3: data &= ~0x00000040; break;
case 2: data &= ~0x00000100; break;
case 1: data &= ~0x80000000; break;
case 0: data &= ~0x00000400; break;
}
switch (next->bios.ramcfg_11_03_30) {
case 3: data &= ~0x00000020; break;
case 2: data &= ~0x00000080; break;
case 1: data &= ~0x00080000; break;
case 0: data &= ~0x00000200; break;
}
}
if (next->bios.ramcfg_11_02_80)
mask |= 0x03000000;
if (next->bios.ramcfg_11_02_40)
mask |= 0x00002000;
if (next->bios.ramcfg_11_07_10)
mask |= 0x00004000;
if (next->bios.ramcfg_11_07_08)
mask |= 0x00000003;
else {
mask |= 0x34000000;
if (ram_rd32(fuc, 0x10f978) & 0x00800000)
mask |= 0x40000000;
}
ram_mask(fuc, 0x10f824, mask, data);
ram_mask(fuc, 0x132040, 0x00010000, 0x00000000);
if (ram->from == 2 && ram->mode != 2) {
ram_mask(fuc, 0x10f808, 0x00080000, 0x00000000);
ram_mask(fuc, 0x10f200, 0x18008000, 0x00008000);
ram_mask(fuc, 0x10f800, 0x00000000, 0x00000004);
ram_mask(fuc, 0x10f830, 0x00008000, 0x01040010);
ram_mask(fuc, 0x10f830, 0x01000000, 0x00000000);
r1373f4_init(fuc);
ram_mask(fuc, 0x1373f0, 0x00000002, 0x00000001);
r1373f4_fini(fuc);
ram_mask(fuc, 0x10f830, 0x00c00000, 0x00240001);
} else
if (ram->from != 2 && ram->mode != 2) {
r1373f4_init(fuc);
r1373f4_fini(fuc);
}
if (ram_have(fuc, gpioMV)) {
u32 temp = ram_mask(fuc, gpioMV, 0x3000, fuc->r_funcMV[mv]);
if (temp != ram_rd32(fuc, gpioMV)) {
ram_wr32(fuc, gpiotrig, 1);
ram_nsec(fuc, 64000);
}
}
if (next->bios.ramcfg_11_02_40 ||
next->bios.ramcfg_11_07_10) {
ram_mask(fuc, 0x132040, 0x00010000, 0x00010000);
ram_nsec(fuc, 20000);
}
if (ram->from != 2 && ram->mode == 2) {
if (0 )
ram_mask(fuc, 0x10f200, 0x18000000, 0x18000000);
ram_mask(fuc, 0x10f800, 0x00000004, 0x00000000);
ram_mask(fuc, 0x1373f0, 0x00000000, 0x00000002);
ram_mask(fuc, 0x10f830, 0x00800001, 0x00408010);
r1373f4_init(fuc);
r1373f4_fini(fuc);
ram_mask(fuc, 0x10f808, 0x00000000, 0x00080000);
ram_mask(fuc, 0x10f200, 0x00808000, 0x00800000);
} else
if (ram->from == 2 && ram->mode == 2) {
ram_mask(fuc, 0x10f800, 0x00000004, 0x00000000);
r1373f4_init(fuc);
r1373f4_fini(fuc);
}
if (ram->mode != 2) {
if (next->bios.ramcfg_11_07_40)
ram_mask(fuc, 0x10f670, 0x80000000, 0x80000000);
}
ram_wr32(fuc, 0x10f65c, 0x00000011 * next->bios.rammap_11_11_0c);
ram_wr32(fuc, 0x10f6b8, 0x01010101 * next->bios.ramcfg_11_09);
ram_wr32(fuc, 0x10f6bc, 0x01010101 * next->bios.ramcfg_11_09);
if (!next->bios.ramcfg_11_07_08 && !next->bios.ramcfg_11_07_04) {
ram_wr32(fuc, 0x10f698, 0x01010101 * next->bios.ramcfg_11_04);
ram_wr32(fuc, 0x10f69c, 0x01010101 * next->bios.ramcfg_11_04);
} else
if (!next->bios.ramcfg_11_07_08) {
ram_wr32(fuc, 0x10f698, 0x00000000);
ram_wr32(fuc, 0x10f69c, 0x00000000);
}
if (ram->mode != 2) {
u32 data = 0x01000100 * next->bios.ramcfg_11_04;
ram_nuke(fuc, 0x10f694);
ram_mask(fuc, 0x10f694, 0xff00ff00, data);
}
if (ram->mode == 2 && next->bios.ramcfg_11_08_10)
data = 0x00000080;
else
data = 0x00000000;
ram_mask(fuc, 0x10f60c, 0x00000080, data);
mask = 0x00070000;
data = 0x00000000;
if (!next->bios.ramcfg_11_02_80)
data |= 0x03000000;
if (!next->bios.ramcfg_11_02_40)
data |= 0x00002000;
if (!next->bios.ramcfg_11_07_10)
data |= 0x00004000;
if (!next->bios.ramcfg_11_07_08)
data |= 0x00000003;
else
data |= 0x74000000;
ram_mask(fuc, 0x10f824, mask, data);
if (next->bios.ramcfg_11_01_08)
data = 0x00000000;
else
data = 0x00001000;
ram_mask(fuc, 0x10f200, 0x00001000, data);
if (ram_rd32(fuc, 0x10f670) & 0x80000000) {
ram_nsec(fuc, 10000);
ram_mask(fuc, 0x10f670, 0x80000000, 0x00000000);
}
if (next->bios.ramcfg_11_08_01)
data = 0x00100000;
else
data = 0x00000000;
ram_mask(fuc, 0x10f82c, 0x00100000, data);
data = 0x00000000;
if (next->bios.ramcfg_11_08_08)
data |= 0x00002000;
if (next->bios.ramcfg_11_08_04)
data |= 0x00001000;
if (next->bios.ramcfg_11_08_02)
data |= 0x00004000;
ram_mask(fuc, 0x10f830, 0x00007000, data);
ram_mask(fuc, 0x10f248, 0xffffffff, next->bios.timing[10]);
ram_mask(fuc, 0x10f290, 0xffffffff, next->bios.timing[0]);
ram_mask(fuc, 0x10f294, 0xffffffff, next->bios.timing[1]);
ram_mask(fuc, 0x10f298, 0xffffffff, next->bios.timing[2]);
ram_mask(fuc, 0x10f29c, 0xffffffff, next->bios.timing[3]);
ram_mask(fuc, 0x10f2a0, 0xffffffff, next->bios.timing[4]);
ram_mask(fuc, 0x10f2a4, 0xffffffff, next->bios.timing[5]);
ram_mask(fuc, 0x10f2a8, 0xffffffff, next->bios.timing[6]);
ram_mask(fuc, 0x10f2ac, 0xffffffff, next->bios.timing[7]);
ram_mask(fuc, 0x10f2cc, 0xffffffff, next->bios.timing[8]);
ram_mask(fuc, 0x10f2e8, 0xffffffff, next->bios.timing[9]);
data = mask = 0x00000000;
if (NOTE00(ramcfg_08_20)) {
if (next->bios.ramcfg_11_08_20)
data |= 0x01000000;
mask |= 0x01000000;
}
ram_mask(fuc, 0x10f200, mask, data);
data = mask = 0x00000000;
if (NOTE00(ramcfg_02_03 != 0)) {
data |= next->bios.ramcfg_11_02_03 << 8;
mask |= 0x00000300;
}
if (NOTE00(ramcfg_01_10)) {
if (next->bios.ramcfg_11_01_10)
data |= 0x70000000;
mask |= 0x70000000;
}
ram_mask(fuc, 0x10f604, mask, data);
data = mask = 0x00000000;
if (NOTE00(timing_30_07 != 0)) {
data |= next->bios.timing_20_30_07 << 28;
mask |= 0x70000000;
}
if (NOTE00(ramcfg_01_01)) {
if (next->bios.ramcfg_11_01_01)
data |= 0x00000100;
mask |= 0x00000100;
}
ram_mask(fuc, 0x10f614, mask, data);
data = mask = 0x00000000;
if (NOTE00(timing_30_07 != 0)) {
data |= next->bios.timing_20_30_07 << 28;
mask |= 0x70000000;
}
if (NOTE00(ramcfg_01_02)) {
if (next->bios.ramcfg_11_01_02)
data |= 0x00000100;
mask |= 0x00000100;
}
ram_mask(fuc, 0x10f610, mask, data);
mask = 0x33f00000;
data = 0x00000000;
if (!next->bios.ramcfg_11_01_04)
data |= 0x20200000;
if (!next->bios.ramcfg_11_07_80)
data |= 0x12800000;
if (next->bios.ramcfg_11_03_f0) {
if (next->bios.rammap_11_08_0c) {
if (!next->bios.ramcfg_11_07_80)
mask |= 0x00000020;
else
data |= 0x00000020;
mask |= 0x00000004;
}
} else {
mask |= 0x40000020;
data |= 0x00000004;
}
ram_mask(fuc, 0x10f808, mask, data);
ram_wr32(fuc, 0x10f870, 0x11111111 * next->bios.ramcfg_11_03_0f);
data = mask = 0x00000000;
if (NOTE00(ramcfg_02_03 != 0)) {
data |= next->bios.ramcfg_11_02_03;
mask |= 0x00000003;
}
if (NOTE00(ramcfg_01_10)) {
if (next->bios.ramcfg_11_01_10)
data |= 0x00000004;
mask |= 0x00000004;
}
if ((ram_mask(fuc, 0x100770, mask, data) & mask & 4) != (data & 4)) {
ram_mask(fuc, 0x100750, 0x00000008, 0x00000008);
ram_wr32(fuc, 0x100710, 0x00000000);
ram_wait(fuc, 0x100710, 0x80000000, 0x80000000, 200000);
}
data = next->bios.timing_20_30_07 << 8;
if (next->bios.ramcfg_11_01_01)
data |= 0x80000000;
ram_mask(fuc, 0x100778, 0x00000700, data);
ram_mask(fuc, 0x10f250, 0x000003f0, next->bios.timing_20_2c_003f << 4);
data = (next->bios.timing[10] & 0x7f000000) >> 24;
if (data < next->bios.timing_20_2c_1fc0)
data = next->bios.timing_20_2c_1fc0;
ram_mask(fuc, 0x10f24c, 0x7f000000, data << 24);
ram_mask(fuc, 0x10f224, 0x001f0000, next->bios.timing_20_30_f8 << 16);
ram_mask(fuc, 0x10fec4, 0x041e0f07, next->bios.timing_20_31_0800 << 26 |
next->bios.timing_20_31_0780 << 17 |
next->bios.timing_20_31_0078 << 8 |
next->bios.timing_20_31_0007);
ram_mask(fuc, 0x10fec8, 0x00000027, next->bios.timing_20_31_8000 << 5 |
next->bios.timing_20_31_7000);
ram_wr32(fuc, 0x10f090, 0x4000007e);
ram_nsec(fuc, 2000);
ram_wr32(fuc, 0x10f314, 0x00000001);
ram_wr32(fuc, 0x10f310, 0x00000001);
ram_wr32(fuc, 0x10f210, 0x80000000);
if (next->bios.ramcfg_11_08_10 && (ram->mode == 2) ) {
u32 temp = ram_mask(fuc, 0x10f294, 0xff000000, 0x24000000);
nve0_ram_train(fuc, 0xbc0e0000, 0xa4010000);
ram_nsec(fuc, 1000);
ram_wr32(fuc, 0x10f294, temp);
}
ram_mask(fuc, mr[3], 0xfff, ram->base.mr[3]);
ram_wr32(fuc, mr[0], ram->base.mr[0]);
ram_mask(fuc, mr[8], 0xfff, ram->base.mr[8]);
ram_nsec(fuc, 1000);
ram_mask(fuc, mr[1], 0xfff, ram->base.mr[1]);
ram_mask(fuc, mr[5], 0xfff, ram->base.mr[5] & ~0x004);
ram_mask(fuc, mr[6], 0xfff, ram->base.mr[6]);
ram_mask(fuc, mr[7], 0xfff, ram->base.mr[7]);
if (vc == 0 && ram_have(fuc, gpio2E)) {
u32 temp = ram_mask(fuc, gpio2E, 0x3000, fuc->r_func2E[0]);
if (temp != ram_rd32(fuc, gpio2E)) {
ram_wr32(fuc, gpiotrig, 1);
ram_nsec(fuc, 20000);
}
}
ram_mask(fuc, 0x10f200, 0x80000000, 0x80000000);
ram_wr32(fuc, 0x10f318, 0x00000001);
ram_mask(fuc, 0x10f200, 0x80000000, 0x00000000);
ram_nsec(fuc, 1000);
ram_nuts(ram, 0x10f200, 0x18808800, 0x00000000, 0x18808800);
data = ram_rd32(fuc, 0x10f978);
data &= ~0x00046144;
data |= 0x0000000b;
if (!next->bios.ramcfg_11_07_08) {
if (!next->bios.ramcfg_11_07_04)
data |= 0x0000200c;
else
data |= 0x00000000;
} else {
data |= 0x00040044;
}
ram_wr32(fuc, 0x10f978, data);
if (ram->mode == 1) {
data = ram_rd32(fuc, 0x10f830) | 0x00000001;
ram_wr32(fuc, 0x10f830, data);
}
if (!next->bios.ramcfg_11_07_08) {
data = 0x88020000;
if ( next->bios.ramcfg_11_07_04)
data |= 0x10000000;
if (!next->bios.rammap_11_08_10)
data |= 0x00080000;
} else {
data = 0xa40e0000;
}
nve0_ram_train(fuc, 0xbc0f0000, data);
if (1)
ram_nsec(fuc, 1000);
if (ram->mode == 2) {
ram_mask(fuc, 0x10f800, 0x00000004, 0x00000004);
}
if (ram_mask(fuc, mr[5], 0x004, ram->base.mr[5]) != ram->base.mr[5])
ram_nsec(fuc, 1000);
if (ram->mode != 2) {
ram_mask(fuc, 0x10f830, 0x01000000, 0x01000000);
ram_mask(fuc, 0x10f830, 0x01000000, 0x00000000);
}
if (next->bios.ramcfg_11_07_02)
nve0_ram_train(fuc, 0x80020000, 0x01000000);
ram_wr32(fuc, 0x62c000, 0x0f0f0f00);
if (next->bios.rammap_11_08_01)
data = 0x00000800;
else
data = 0x00000000;
ram_mask(fuc, 0x10f200, 0x00000800, data);
ram_nuts(ram, 0x10f200, 0x18808800, data, 0x18808800);
return 0;
}
static int
nve0_ram_calc_sddr3(struct nouveau_fb *pfb, u32 freq)
{
struct nve0_ram *ram = (void *)pfb->ram;
struct nve0_ramfuc *fuc = &ram->fuc;
const u32 rcoef = (( ram->P1 << 16) | (ram->N1 << 8) | ram->M1);
const u32 runk0 = ram->fN1 << 16;
const u32 runk1 = ram->fN1;
struct nouveau_ram_data *next = ram->base.next;
int vc = !next->bios.ramcfg_11_02_08;
int mv = !next->bios.ramcfg_11_02_04;
u32 mask, data;
ram_mask(fuc, 0x10f808, 0x40000000, 0x40000000);
ram_wr32(fuc, 0x62c000, 0x0f0f0000);
if (vc == 1 && ram_have(fuc, gpio2E)) {
u32 temp = ram_mask(fuc, gpio2E, 0x3000, fuc->r_func2E[1]);
if (temp != ram_rd32(fuc, gpio2E)) {
ram_wr32(fuc, gpiotrig, 1);
ram_nsec(fuc, 20000);
}
}
ram_mask(fuc, 0x10f200, 0x00000800, 0x00000000);
if (next->bios.ramcfg_11_03_f0)
ram_mask(fuc, 0x10f808, 0x04000000, 0x04000000);
ram_wr32(fuc, 0x10f314, 0x00000001);
ram_wr32(fuc, 0x10f210, 0x00000000);
ram_wr32(fuc, 0x10f310, 0x00000001);
ram_mask(fuc, 0x10f200, 0x80000000, 0x80000000);
ram_wr32(fuc, 0x10f310, 0x00000001);
ram_mask(fuc, 0x10f200, 0x80000000, 0x00000000);
ram_nsec(fuc, 1000);
ram_wr32(fuc, 0x10f090, 0x00000060);
ram_wr32(fuc, 0x10f090, 0xc000007e);
mask = 0x00010000;
data = 0x00010000;
if (1) {
mask |= 0x800807e0;
data |= 0x800807e0;
switch (next->bios.ramcfg_11_03_c0) {
case 3: data &= ~0x00000040; break;
case 2: data &= ~0x00000100; break;
case 1: data &= ~0x80000000; break;
case 0: data &= ~0x00000400; break;
}
switch (next->bios.ramcfg_11_03_30) {
case 3: data &= ~0x00000020; break;
case 2: data &= ~0x00000080; break;
case 1: data &= ~0x00080000; break;
case 0: data &= ~0x00000200; break;
}
}
if (next->bios.ramcfg_11_02_80)
mask |= 0x03000000;
if (next->bios.ramcfg_11_02_40)
mask |= 0x00002000;
if (next->bios.ramcfg_11_07_10)
mask |= 0x00004000;
if (next->bios.ramcfg_11_07_08)
mask |= 0x00000003;
else
mask |= 0x14000000;
ram_mask(fuc, 0x10f824, mask, data);
ram_mask(fuc, 0x132040, 0x00010000, 0x00000000);
ram_mask(fuc, 0x1373f4, 0x00000000, 0x00010010);
data = ram_rd32(fuc, 0x1373ec) & ~0x00030000;
data |= next->bios.ramcfg_11_03_30 << 16;
ram_wr32(fuc, 0x1373ec, data);
ram_mask(fuc, 0x1373f4, 0x00000003, 0x00000000);
ram_mask(fuc, 0x1373f4, 0x00000010, 0x00000000);
if ((ram_rd32(fuc, 0x132024) & 0xffffffff) != rcoef ||
(ram_rd32(fuc, 0x132034) & 0x0000ffff) != runk1) {
ram_mask(fuc, 0x132000, 0x00000001, 0x00000000);
ram_mask(fuc, 0x132020, 0x00000001, 0x00000000);
ram_wr32(fuc, 0x137320, 0x00000000);
ram_mask(fuc, 0x132030, 0xffff0000, runk0);
ram_mask(fuc, 0x132034, 0x0000ffff, runk1);
ram_wr32(fuc, 0x132024, rcoef);
ram_mask(fuc, 0x132028, 0x00080000, 0x00080000);
ram_mask(fuc, 0x132020, 0x00000001, 0x00000001);
ram_wait(fuc, 0x137390, 0x00020000, 0x00020000, 64000);
ram_mask(fuc, 0x132028, 0x00080000, 0x00000000);
}
ram_mask(fuc, 0x1373f4, 0x00000010, 0x00000010);
ram_mask(fuc, 0x1373f4, 0x00000003, 0x00000001);
ram_mask(fuc, 0x1373f4, 0x00010000, 0x00000000);
if (ram_have(fuc, gpioMV)) {
u32 temp = ram_mask(fuc, gpioMV, 0x3000, fuc->r_funcMV[mv]);
if (temp != ram_rd32(fuc, gpioMV)) {
ram_wr32(fuc, gpiotrig, 1);
ram_nsec(fuc, 64000);
}
}
if (next->bios.ramcfg_11_02_40 ||
next->bios.ramcfg_11_07_10) {
ram_mask(fuc, 0x132040, 0x00010000, 0x00010000);
ram_nsec(fuc, 20000);
}
if (ram->mode != 2) {
if (next->bios.ramcfg_11_07_40)
ram_mask(fuc, 0x10f670, 0x80000000, 0x80000000);
}
ram_wr32(fuc, 0x10f65c, 0x00000011 * next->bios.rammap_11_11_0c);
ram_wr32(fuc, 0x10f6b8, 0x01010101 * next->bios.ramcfg_11_09);
ram_wr32(fuc, 0x10f6bc, 0x01010101 * next->bios.ramcfg_11_09);
mask = 0x00010000;
data = 0x00000000;
if (!next->bios.ramcfg_11_02_80)
data |= 0x03000000;
if (!next->bios.ramcfg_11_02_40)
data |= 0x00002000;
if (!next->bios.ramcfg_11_07_10)
data |= 0x00004000;
if (!next->bios.ramcfg_11_07_08)
data |= 0x00000003;
else
data |= 0x14000000;
ram_mask(fuc, 0x10f824, mask, data);
ram_nsec(fuc, 1000);
if (next->bios.ramcfg_11_08_01)
data = 0x00100000;
else
data = 0x00000000;
ram_mask(fuc, 0x10f82c, 0x00100000, data);
ram_mask(fuc, 0x10f248, 0xffffffff, next->bios.timing[10]);
ram_mask(fuc, 0x10f290, 0xffffffff, next->bios.timing[0]);
ram_mask(fuc, 0x10f294, 0xffffffff, next->bios.timing[1]);
ram_mask(fuc, 0x10f298, 0xffffffff, next->bios.timing[2]);
ram_mask(fuc, 0x10f29c, 0xffffffff, next->bios.timing[3]);
ram_mask(fuc, 0x10f2a0, 0xffffffff, next->bios.timing[4]);
ram_mask(fuc, 0x10f2a4, 0xffffffff, next->bios.timing[5]);
ram_mask(fuc, 0x10f2a8, 0xffffffff, next->bios.timing[6]);
ram_mask(fuc, 0x10f2ac, 0xffffffff, next->bios.timing[7]);
ram_mask(fuc, 0x10f2cc, 0xffffffff, next->bios.timing[8]);
ram_mask(fuc, 0x10f2e8, 0xffffffff, next->bios.timing[9]);
mask = 0x33f00000;
data = 0x00000000;
if (!next->bios.ramcfg_11_01_04)
data |= 0x20200000;
if (!next->bios.ramcfg_11_07_80)
data |= 0x12800000;
if (next->bios.ramcfg_11_03_f0) {
if (next->bios.rammap_11_08_0c) {
if (!next->bios.ramcfg_11_07_80)
mask |= 0x00000020;
else
data |= 0x00000020;
mask |= 0x08000004;
}
data |= 0x04000000;
} else {
mask |= 0x44000020;
data |= 0x08000004;
}
ram_mask(fuc, 0x10f808, mask, data);
ram_wr32(fuc, 0x10f870, 0x11111111 * next->bios.ramcfg_11_03_0f);
ram_mask(fuc, 0x10f250, 0x000003f0, next->bios.timing_20_2c_003f << 4);
data = (next->bios.timing[10] & 0x7f000000) >> 24;
if (data < next->bios.timing_20_2c_1fc0)
data = next->bios.timing_20_2c_1fc0;
ram_mask(fuc, 0x10f24c, 0x7f000000, data << 24);
ram_mask(fuc, 0x10f224, 0x001f0000, next->bios.timing_20_30_f8 << 16);
ram_wr32(fuc, 0x10f090, 0x4000007f);
ram_nsec(fuc, 1000);
ram_wr32(fuc, 0x10f314, 0x00000001);
ram_wr32(fuc, 0x10f310, 0x00000001);
ram_wr32(fuc, 0x10f210, 0x80000000);
ram_nsec(fuc, 1000);
ram_nuke(fuc, mr[0]);
ram_mask(fuc, mr[0], 0x100, 0x100);
ram_mask(fuc, mr[0], 0x100, 0x000);
ram_mask(fuc, mr[2], 0xfff, ram->base.mr[2]);
ram_wr32(fuc, mr[0], ram->base.mr[0]);
ram_nsec(fuc, 1000);
ram_nuke(fuc, mr[0]);
ram_mask(fuc, mr[0], 0x100, 0x100);
ram_mask(fuc, mr[0], 0x100, 0x000);
if (vc == 0 && ram_have(fuc, gpio2E)) {
u32 temp = ram_mask(fuc, gpio2E, 0x3000, fuc->r_func2E[0]);
if (temp != ram_rd32(fuc, gpio2E)) {
ram_wr32(fuc, gpiotrig, 1);
ram_nsec(fuc, 20000);
}
}
if (ram->mode != 2) {
ram_mask(fuc, 0x10f830, 0x01000000, 0x01000000);
ram_mask(fuc, 0x10f830, 0x01000000, 0x00000000);
}
ram_mask(fuc, 0x10f200, 0x80000000, 0x80000000);
ram_wr32(fuc, 0x10f318, 0x00000001);
ram_mask(fuc, 0x10f200, 0x80000000, 0x00000000);
ram_nsec(fuc, 1000);
ram_wr32(fuc, 0x62c000, 0x0f0f0f00);
if (next->bios.rammap_11_08_01)
data = 0x00000800;
else
data = 0x00000000;
ram_mask(fuc, 0x10f200, 0x00000800, data);
return 0;
}
static int
nve0_ram_calc_data(struct nouveau_fb *pfb, u32 freq,
struct nouveau_ram_data *data)
{
struct nouveau_bios *bios = nouveau_bios(pfb);
struct nve0_ram *ram = (void *)pfb->ram;
u8 strap, cnt, len;
ram->base.rammap.data = nvbios_rammapEp(bios, freq / 1000,
&ram->base.rammap.version,
&ram->base.rammap.size,
&cnt, &len, &data->bios);
if (!ram->base.rammap.data || ram->base.rammap.version != 0x11 ||
ram->base.rammap.size < 0x09) {
nv_error(pfb, "invalid/missing rammap entry\n");
return -EINVAL;
}
strap = nvbios_ramcfg_index(nv_subdev(pfb));
ram->base.ramcfg.data = nvbios_rammapSp(bios, ram->base.rammap.data,
ram->base.rammap.version,
ram->base.rammap.size,
cnt, len, strap,
&ram->base.ramcfg.version,
&ram->base.ramcfg.size,
&data->bios);
if (!ram->base.ramcfg.data || ram->base.ramcfg.version != 0x11 ||
ram->base.ramcfg.size < 0x08) {
nv_error(pfb, "invalid/missing ramcfg entry\n");
return -EINVAL;
}
strap = nv_ro08(bios, ram->base.ramcfg.data + 0x00);
if (strap != 0xff) {
ram->base.timing.data =
nvbios_timingEp(bios, strap, &ram->base.timing.version,
&ram->base.timing.size, &cnt, &len,
&data->bios);
if (!ram->base.timing.data ||
ram->base.timing.version != 0x20 ||
ram->base.timing.size < 0x33) {
nv_error(pfb, "invalid/missing timing entry\n");
return -EINVAL;
}
} else {
ram->base.timing.data = 0;
}
data->freq = freq;
return 0;
}
static int
nve0_ram_calc_xits(struct nouveau_fb *pfb, struct nouveau_ram_data *next)
{
struct nve0_ram *ram = (void *)pfb->ram;
struct nve0_ramfuc *fuc = &ram->fuc;
int refclk, i;
int ret;
ret = ram_init(fuc, pfb);
if (ret)
return ret;
ram->mode = (next->freq > fuc->refpll.vco1.max_freq) ? 2 : 1;
ram->from = ram_rd32(fuc, 0x1373f4) & 0x0000000f;
refclk = next->freq;
if (ram->mode == 2)
refclk = fuc->mempll.refclk;
ret = nva3_pll_calc(nv_subdev(pfb), &fuc->refpll, refclk, &ram->N1,
&ram->fN1, &ram->M1, &ram->P1);
fuc->mempll.refclk = ret;
if (ret <= 0) {
nv_error(pfb, "unable to calc refpll\n");
return -EINVAL;
}
if (ram->mode == 2) {
fuc->mempll.min_p = 1;
fuc->mempll.max_p = 2;
ret = nva3_pll_calc(nv_subdev(pfb), &fuc->mempll, next->freq,
&ram->N2, NULL, &ram->M2, &ram->P2);
if (ret <= 0) {
nv_error(pfb, "unable to calc mempll\n");
return -EINVAL;
}
}
for (i = 0; i < ARRAY_SIZE(fuc->r_mr); i++) {
if (ram_have(fuc, mr[i]))
ram->base.mr[i] = ram_rd32(fuc, mr[i]);
}
ram->base.freq = next->freq;
switch (ram->base.type) {
case NV_MEM_TYPE_DDR3:
ret = nouveau_sddr3_calc(&ram->base);
if (ret == 0)
ret = nve0_ram_calc_sddr3(pfb, next->freq);
break;
case NV_MEM_TYPE_GDDR5:
ret = nouveau_gddr5_calc(&ram->base, ram->pnuts != 0);
if (ret == 0)
ret = nve0_ram_calc_gddr5(pfb, next->freq);
break;
default:
ret = -ENOSYS;
break;
}
return ret;
}
static int
nve0_ram_calc(struct nouveau_fb *pfb, u32 freq)
{
struct nouveau_clock *clk = nouveau_clock(pfb);
struct nve0_ram *ram = (void *)pfb->ram;
struct nouveau_ram_data *xits = &ram->base.xition;
struct nouveau_ram_data *copy;
int ret;
if (ram->base.next == NULL) {
ret = nve0_ram_calc_data(pfb, clk->read(clk, nv_clk_src_mem),
&ram->base.former);
if (ret)
return ret;
ret = nve0_ram_calc_data(pfb, freq, &ram->base.target);
if (ret)
return ret;
if (ram->base.target.freq < ram->base.former.freq) {
*xits = ram->base.target;
copy = &ram->base.former;
} else {
*xits = ram->base.former;
copy = &ram->base.target;
}
xits->bios.ramcfg_11_02_04 = copy->bios.ramcfg_11_02_04;
xits->bios.ramcfg_11_02_03 = copy->bios.ramcfg_11_02_03;
xits->bios.timing_20_30_07 = copy->bios.timing_20_30_07;
ram->base.next = &ram->base.target;
if (memcmp(xits, &ram->base.former, sizeof(xits->bios)))
ram->base.next = &ram->base.xition;
} else {
BUG_ON(ram->base.next != &ram->base.xition);
ram->base.next = &ram->base.target;
}
return nve0_ram_calc_xits(pfb, ram->base.next);
}
static int
nve0_ram_prog(struct nouveau_fb *pfb)
{
struct nouveau_device *device = nv_device(pfb);
struct nve0_ram *ram = (void *)pfb->ram;
struct nve0_ramfuc *fuc = &ram->fuc;
ram_exec(fuc, nouveau_boolopt(device->cfgopt, "NvMemExec", true));
return (ram->base.next == &ram->base.xition);
}
static void
nve0_ram_tidy(struct nouveau_fb *pfb)
{
struct nve0_ram *ram = (void *)pfb->ram;
struct nve0_ramfuc *fuc = &ram->fuc;
ram->base.next = NULL;
ram_exec(fuc, false);
}
int
nve0_ram_init(struct nouveau_object *object)
{
struct nouveau_fb *pfb = (void *)object->parent;
struct nve0_ram *ram = (void *)object;
struct nouveau_bios *bios = nouveau_bios(pfb);
static const u8 train0[] = {
0x00, 0xff, 0xff, 0x00, 0xff, 0x00,
0x00, 0xff, 0xff, 0x00, 0xff, 0x00,
};
static const u32 train1[] = {
0x00000000, 0xffffffff,
0x55555555, 0xaaaaaaaa,
0x33333333, 0xcccccccc,
0xf0f0f0f0, 0x0f0f0f0f,
0x00ff00ff, 0xff00ff00,
0x0000ffff, 0xffff0000,
};
u8 ver, hdr, cnt, len, snr, ssz;
u32 data, save;
int ret, i;
ret = nouveau_ram_init(&ram->base);
if (ret)
return ret;
data = nvbios_rammapTe(bios, &ver, &hdr, &cnt, &len, &snr, &ssz);
if (!data || hdr < 0x15)
return -EINVAL;
cnt = nv_ro08(bios, data + 0x14);
data = nv_ro32(bios, data + 0x10);
save = nv_rd32(pfb, 0x10f65c);
for (i = 0; i < cnt; i++) {
nv_mask(pfb, 0x10f65c, 0x000000f0, i << 4);
nvbios_exec(&(struct nvbios_init) {
.subdev = nv_subdev(pfb),
.bios = bios,
.offset = nv_ro32(bios, data),
.execute = 1,
});
data += 4;
}
nv_wr32(pfb, 0x10f65c, save);
nv_mask(pfb, 0x10f584, 0x11000000, 0x00000000);
switch (ram->base.type) {
case NV_MEM_TYPE_GDDR5:
for (i = 0; i < 0x30; i++) {
nv_wr32(pfb, 0x10f968, 0x00000000 | (i << 8));
nv_wr32(pfb, 0x10f920, 0x00000000 | train0[i % 12]);
nv_wr32(pfb, 0x10f918, train1[i % 12]);
nv_wr32(pfb, 0x10f920, 0x00000100 | train0[i % 12]);
nv_wr32(pfb, 0x10f918, train1[i % 12]);
nv_wr32(pfb, 0x10f96c, 0x00000000 | (i << 8));
nv_wr32(pfb, 0x10f924, 0x00000000 | train0[i % 12]);
nv_wr32(pfb, 0x10f91c, train1[i % 12]);
nv_wr32(pfb, 0x10f924, 0x00000100 | train0[i % 12]);
nv_wr32(pfb, 0x10f91c, train1[i % 12]);
}
for (i = 0; i < 0x100; i++) {
nv_wr32(pfb, 0x10f968, i);
nv_wr32(pfb, 0x10f900, train1[2 + (i & 1)]);
}
for (i = 0; i < 0x100; i++) {
nv_wr32(pfb, 0x10f96c, i);
nv_wr32(pfb, 0x10f900, train1[2 + (i & 1)]);
}
break;
default:
break;
}
return 0;
}
static int
nve0_ram_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fb *pfb = nouveau_fb(parent);
struct nouveau_bios *bios = nouveau_bios(pfb);
struct nouveau_gpio *gpio = nouveau_gpio(pfb);
struct dcb_gpio_func func;
struct nve0_ram *ram;
int ret, i;
u32 tmp;
ret = nvc0_ram_create(parent, engine, oclass, 0x022554, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
switch (ram->base.type) {
case NV_MEM_TYPE_DDR3:
case NV_MEM_TYPE_GDDR5:
ram->base.calc = nve0_ram_calc;
ram->base.prog = nve0_ram_prog;
ram->base.tidy = nve0_ram_tidy;
break;
default:
nv_warn(pfb, "reclocking of this RAM type is unsupported\n");
break;
}
ram->parts = nv_rd32(pfb, 0x022438);
ram->pmask = nv_rd32(pfb, 0x022554);
ram->pnuts = 0;
for (i = 0, tmp = 0; i < ram->parts; i++) {
if (!(ram->pmask & (1 << i))) {
u32 cfg1 = nv_rd32(pfb, 0x110204 + (i * 0x1000));
if (tmp && tmp != cfg1) {
ram->pnuts |= (1 << i);
continue;
}
tmp = cfg1;
}
}
ret = nvbios_pll_parse(bios, 0x0c, &ram->fuc.refpll);
if (ret) {
nv_error(pfb, "mclk refpll data not found\n");
return ret;
}
ret = nvbios_pll_parse(bios, 0x04, &ram->fuc.mempll);
if (ret) {
nv_error(pfb, "mclk pll data not found\n");
return ret;
}
ret = gpio->find(gpio, 0, 0x18, DCB_GPIO_UNUSED, &func);
if (ret == 0) {
ram->fuc.r_gpioMV = ramfuc_reg(0x00d610 + (func.line * 0x04));
ram->fuc.r_funcMV[0] = (func.log[0] ^ 2) << 12;
ram->fuc.r_funcMV[1] = (func.log[1] ^ 2) << 12;
}
ret = gpio->find(gpio, 0, 0x2e, DCB_GPIO_UNUSED, &func);
if (ret == 0) {
ram->fuc.r_gpio2E = ramfuc_reg(0x00d610 + (func.line * 0x04));
ram->fuc.r_func2E[0] = (func.log[0] ^ 2) << 12;
ram->fuc.r_func2E[1] = (func.log[1] ^ 2) << 12;
}
ram->fuc.r_gpiotrig = ramfuc_reg(0x00d604);
ram->fuc.r_0x132020 = ramfuc_reg(0x132020);
ram->fuc.r_0x132028 = ramfuc_reg(0x132028);
ram->fuc.r_0x132024 = ramfuc_reg(0x132024);
ram->fuc.r_0x132030 = ramfuc_reg(0x132030);
ram->fuc.r_0x132034 = ramfuc_reg(0x132034);
ram->fuc.r_0x132000 = ramfuc_reg(0x132000);
ram->fuc.r_0x132004 = ramfuc_reg(0x132004);
ram->fuc.r_0x132040 = ramfuc_reg(0x132040);
ram->fuc.r_0x10f248 = ramfuc_reg(0x10f248);
ram->fuc.r_0x10f290 = ramfuc_reg(0x10f290);
ram->fuc.r_0x10f294 = ramfuc_reg(0x10f294);
ram->fuc.r_0x10f298 = ramfuc_reg(0x10f298);
ram->fuc.r_0x10f29c = ramfuc_reg(0x10f29c);
ram->fuc.r_0x10f2a0 = ramfuc_reg(0x10f2a0);
ram->fuc.r_0x10f2a4 = ramfuc_reg(0x10f2a4);
ram->fuc.r_0x10f2a8 = ramfuc_reg(0x10f2a8);
ram->fuc.r_0x10f2ac = ramfuc_reg(0x10f2ac);
ram->fuc.r_0x10f2cc = ramfuc_reg(0x10f2cc);
ram->fuc.r_0x10f2e8 = ramfuc_reg(0x10f2e8);
ram->fuc.r_0x10f250 = ramfuc_reg(0x10f250);
ram->fuc.r_0x10f24c = ramfuc_reg(0x10f24c);
ram->fuc.r_0x10fec4 = ramfuc_reg(0x10fec4);
ram->fuc.r_0x10fec8 = ramfuc_reg(0x10fec8);
ram->fuc.r_0x10f604 = ramfuc_reg(0x10f604);
ram->fuc.r_0x10f614 = ramfuc_reg(0x10f614);
ram->fuc.r_0x10f610 = ramfuc_reg(0x10f610);
ram->fuc.r_0x100770 = ramfuc_reg(0x100770);
ram->fuc.r_0x100778 = ramfuc_reg(0x100778);
ram->fuc.r_0x10f224 = ramfuc_reg(0x10f224);
ram->fuc.r_0x10f870 = ramfuc_reg(0x10f870);
ram->fuc.r_0x10f698 = ramfuc_reg(0x10f698);
ram->fuc.r_0x10f694 = ramfuc_reg(0x10f694);
ram->fuc.r_0x10f6b8 = ramfuc_reg(0x10f6b8);
ram->fuc.r_0x10f808 = ramfuc_reg(0x10f808);
ram->fuc.r_0x10f670 = ramfuc_reg(0x10f670);
ram->fuc.r_0x10f60c = ramfuc_reg(0x10f60c);
ram->fuc.r_0x10f830 = ramfuc_reg(0x10f830);
ram->fuc.r_0x1373ec = ramfuc_reg(0x1373ec);
ram->fuc.r_0x10f800 = ramfuc_reg(0x10f800);
ram->fuc.r_0x10f82c = ramfuc_reg(0x10f82c);
ram->fuc.r_0x10f978 = ramfuc_reg(0x10f978);
ram->fuc.r_0x10f910 = ramfuc_reg(0x10f910);
ram->fuc.r_0x10f914 = ramfuc_reg(0x10f914);
switch (ram->base.type) {
case NV_MEM_TYPE_GDDR5:
ram->fuc.r_mr[0] = ramfuc_reg(0x10f300);
ram->fuc.r_mr[1] = ramfuc_reg(0x10f330);
ram->fuc.r_mr[2] = ramfuc_reg(0x10f334);
ram->fuc.r_mr[3] = ramfuc_reg(0x10f338);
ram->fuc.r_mr[4] = ramfuc_reg(0x10f33c);
ram->fuc.r_mr[5] = ramfuc_reg(0x10f340);
ram->fuc.r_mr[6] = ramfuc_reg(0x10f344);
ram->fuc.r_mr[7] = ramfuc_reg(0x10f348);
ram->fuc.r_mr[8] = ramfuc_reg(0x10f354);
ram->fuc.r_mr[15] = ramfuc_reg(0x10f34c);
break;
case NV_MEM_TYPE_DDR3:
ram->fuc.r_mr[0] = ramfuc_reg(0x10f300);
ram->fuc.r_mr[2] = ramfuc_reg(0x10f320);
break;
default:
break;
}
ram->fuc.r_0x62c000 = ramfuc_reg(0x62c000);
ram->fuc.r_0x10f200 = ramfuc_reg(0x10f200);
ram->fuc.r_0x10f210 = ramfuc_reg(0x10f210);
ram->fuc.r_0x10f310 = ramfuc_reg(0x10f310);
ram->fuc.r_0x10f314 = ramfuc_reg(0x10f314);
ram->fuc.r_0x10f318 = ramfuc_reg(0x10f318);
ram->fuc.r_0x10f090 = ramfuc_reg(0x10f090);
ram->fuc.r_0x10f69c = ramfuc_reg(0x10f69c);
ram->fuc.r_0x10f824 = ramfuc_reg(0x10f824);
ram->fuc.r_0x1373f0 = ramfuc_reg(0x1373f0);
ram->fuc.r_0x1373f4 = ramfuc_reg(0x1373f4);
ram->fuc.r_0x137320 = ramfuc_reg(0x137320);
ram->fuc.r_0x10f65c = ramfuc_reg(0x10f65c);
ram->fuc.r_0x10f6bc = ramfuc_reg(0x10f6bc);
ram->fuc.r_0x100710 = ramfuc_reg(0x100710);
ram->fuc.r_0x100750 = ramfuc_reg(0x100750);
return 0;
}
