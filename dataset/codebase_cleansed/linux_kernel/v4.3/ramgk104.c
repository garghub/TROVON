static void
gk104_ram_train(struct gk104_ramfuc *fuc, u32 mask, u32 data)
{
struct gk104_ram *ram = container_of(fuc, typeof(*ram), fuc);
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
r1373f4_init(struct gk104_ramfuc *fuc)
{
struct gk104_ram *ram = container_of(fuc, typeof(*ram), fuc);
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
r1373f4_fini(struct gk104_ramfuc *fuc)
{
struct gk104_ram *ram = container_of(fuc, typeof(*ram), fuc);
struct nvkm_ram_data *next = ram->base.next;
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
gk104_ram_nuts(struct gk104_ram *ram, struct ramfuc_reg *reg,
u32 _mask, u32 _data, u32 _copy)
{
struct nvkm_fb *fb = ram->base.fb;
struct ramfuc *fuc = &ram->fuc.base;
struct nvkm_device *device = fb->subdev.device;
u32 addr = 0x110000 + (reg->addr & 0xfff);
u32 mask = _mask | _copy;
u32 data = (_data & _mask) | (reg->data & _copy);
u32 i;
for (i = 0; i < 16; i++, addr += 0x1000) {
if (ram->pnuts & (1 << i)) {
u32 prev = nvkm_rd32(device, addr);
u32 next = (prev & ~mask) | data;
nvkm_memx_wr32(fuc->memx, addr, next);
}
}
}
static int
gk104_ram_calc_gddr5(struct gk104_ram *ram, u32 freq)
{
struct gk104_ramfuc *fuc = &ram->fuc;
struct nvkm_ram_data *next = ram->base.next;
int vc = !next->bios.ramcfg_11_02_08;
int mv = !next->bios.ramcfg_11_02_04;
u32 mask, data;
ram_mask(fuc, 0x10f808, 0x40000000, 0x40000000);
ram_block(fuc);
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
gk104_ram_train(fuc, 0x01020000, 0x000c0000);
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
if (ram->diff.ramcfg_11_08_20) {
if (next->bios.ramcfg_11_08_20)
data |= 0x01000000;
mask |= 0x01000000;
}
ram_mask(fuc, 0x10f200, mask, data);
data = mask = 0x00000000;
if (ram->diff.ramcfg_11_02_03) {
data |= next->bios.ramcfg_11_02_03 << 8;
mask |= 0x00000300;
}
if (ram->diff.ramcfg_11_01_10) {
if (next->bios.ramcfg_11_01_10)
data |= 0x70000000;
mask |= 0x70000000;
}
ram_mask(fuc, 0x10f604, mask, data);
data = mask = 0x00000000;
if (ram->diff.timing_20_30_07) {
data |= next->bios.timing_20_30_07 << 28;
mask |= 0x70000000;
}
if (ram->diff.ramcfg_11_01_01) {
if (next->bios.ramcfg_11_01_01)
data |= 0x00000100;
mask |= 0x00000100;
}
ram_mask(fuc, 0x10f614, mask, data);
data = mask = 0x00000000;
if (ram->diff.timing_20_30_07) {
data |= next->bios.timing_20_30_07 << 28;
mask |= 0x70000000;
}
if (ram->diff.ramcfg_11_01_02) {
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
if (ram->diff.ramcfg_11_02_03) {
data |= next->bios.ramcfg_11_02_03;
mask |= 0x00000003;
}
if (ram->diff.ramcfg_11_01_10) {
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
gk104_ram_train(fuc, 0xbc0e0000, 0xa4010000);
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
gk104_ram_train(fuc, 0xbc0f0000, data);
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
gk104_ram_train(fuc, 0x80020000, 0x01000000);
ram_unblock(fuc);
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
gk104_ram_calc_sddr3(struct gk104_ram *ram, u32 freq)
{
struct gk104_ramfuc *fuc = &ram->fuc;
const u32 rcoef = (( ram->P1 << 16) | (ram->N1 << 8) | ram->M1);
const u32 runk0 = ram->fN1 << 16;
const u32 runk1 = ram->fN1;
struct nvkm_ram_data *next = ram->base.next;
int vc = !next->bios.ramcfg_11_02_08;
int mv = !next->bios.ramcfg_11_02_04;
u32 mask, data;
ram_mask(fuc, 0x10f808, 0x40000000, 0x40000000);
ram_block(fuc);
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
ram_unblock(fuc);
ram_wr32(fuc, 0x62c000, 0x0f0f0f00);
if (next->bios.rammap_11_08_01)
data = 0x00000800;
else
data = 0x00000000;
ram_mask(fuc, 0x10f200, 0x00000800, data);
return 0;
}
static int
gk104_ram_calc_data(struct gk104_ram *ram, u32 khz, struct nvkm_ram_data *data)
{
struct nvkm_subdev *subdev = &ram->base.fb->subdev;
struct nvkm_ram_data *cfg;
u32 mhz = khz / 1000;
list_for_each_entry(cfg, &ram->cfg, head) {
if (mhz >= cfg->bios.rammap_min &&
mhz <= cfg->bios.rammap_max) {
*data = *cfg;
data->freq = khz;
return 0;
}
}
nvkm_error(subdev, "ramcfg data for %dMHz not found\n", mhz);
return -EINVAL;
}
static int
gk104_ram_calc_xits(struct gk104_ram *ram, struct nvkm_ram_data *next)
{
struct gk104_ramfuc *fuc = &ram->fuc;
struct nvkm_subdev *subdev = &ram->base.fb->subdev;
int refclk, i;
int ret;
ret = ram_init(fuc, ram->base.fb);
if (ret)
return ret;
ram->mode = (next->freq > fuc->refpll.vco1.max_freq) ? 2 : 1;
ram->from = ram_rd32(fuc, 0x1373f4) & 0x0000000f;
refclk = next->freq;
if (ram->mode == 2)
refclk = fuc->mempll.refclk;
ret = gt215_pll_calc(subdev, &fuc->refpll, refclk, &ram->N1,
&ram->fN1, &ram->M1, &ram->P1);
fuc->mempll.refclk = ret;
if (ret <= 0) {
nvkm_error(subdev, "unable to calc refpll\n");
return -EINVAL;
}
if (ram->mode == 2) {
fuc->mempll.min_p = 1;
fuc->mempll.max_p = 2;
ret = gt215_pll_calc(subdev, &fuc->mempll, next->freq,
&ram->N2, NULL, &ram->M2, &ram->P2);
if (ret <= 0) {
nvkm_error(subdev, "unable to calc mempll\n");
return -EINVAL;
}
}
for (i = 0; i < ARRAY_SIZE(fuc->r_mr); i++) {
if (ram_have(fuc, mr[i]))
ram->base.mr[i] = ram_rd32(fuc, mr[i]);
}
ram->base.freq = next->freq;
switch (ram->base.type) {
case NVKM_RAM_TYPE_DDR3:
ret = nvkm_sddr3_calc(&ram->base);
if (ret == 0)
ret = gk104_ram_calc_sddr3(ram, next->freq);
break;
case NVKM_RAM_TYPE_GDDR5:
ret = nvkm_gddr5_calc(&ram->base, ram->pnuts != 0);
if (ret == 0)
ret = gk104_ram_calc_gddr5(ram, next->freq);
break;
default:
ret = -ENOSYS;
break;
}
return ret;
}
static int
gk104_ram_calc(struct nvkm_ram *base, u32 freq)
{
struct gk104_ram *ram = gk104_ram(base);
struct nvkm_clk *clk = ram->base.fb->subdev.device->clk;
struct nvkm_ram_data *xits = &ram->base.xition;
struct nvkm_ram_data *copy;
int ret;
if (ram->base.next == NULL) {
ret = gk104_ram_calc_data(ram,
nvkm_clk_read(clk, nv_clk_src_mem),
&ram->base.former);
if (ret)
return ret;
ret = gk104_ram_calc_data(ram, freq, &ram->base.target);
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
return gk104_ram_calc_xits(ram, ram->base.next);
}
static void
gk104_ram_prog_0(struct gk104_ram *ram, u32 freq)
{
struct nvkm_device *device = ram->base.fb->subdev.device;
struct nvkm_ram_data *cfg;
u32 mhz = freq / 1000;
u32 mask, data;
list_for_each_entry(cfg, &ram->cfg, head) {
if (mhz >= cfg->bios.rammap_min &&
mhz <= cfg->bios.rammap_max)
break;
}
if (&cfg->head == &ram->cfg)
return;
if (mask = 0, data = 0, ram->diff.rammap_11_0a_03fe) {
data |= cfg->bios.rammap_11_0a_03fe << 12;
mask |= 0x001ff000;
}
if (ram->diff.rammap_11_09_01ff) {
data |= cfg->bios.rammap_11_09_01ff;
mask |= 0x000001ff;
}
nvkm_mask(device, 0x10f468, mask, data);
if (mask = 0, data = 0, ram->diff.rammap_11_0a_0400) {
data |= cfg->bios.rammap_11_0a_0400;
mask |= 0x00000001;
}
nvkm_mask(device, 0x10f420, mask, data);
if (mask = 0, data = 0, ram->diff.rammap_11_0a_0800) {
data |= cfg->bios.rammap_11_0a_0800;
mask |= 0x00000001;
}
nvkm_mask(device, 0x10f430, mask, data);
if (mask = 0, data = 0, ram->diff.rammap_11_0b_01f0) {
data |= cfg->bios.rammap_11_0b_01f0;
mask |= 0x0000001f;
}
nvkm_mask(device, 0x10f400, mask, data);
if (mask = 0, data = 0, ram->diff.rammap_11_0b_0200) {
data |= cfg->bios.rammap_11_0b_0200 << 9;
mask |= 0x00000200;
}
nvkm_mask(device, 0x10f410, mask, data);
if (mask = 0, data = 0, ram->diff.rammap_11_0d) {
data |= cfg->bios.rammap_11_0d << 16;
mask |= 0x00ff0000;
}
if (ram->diff.rammap_11_0f) {
data |= cfg->bios.rammap_11_0f << 8;
mask |= 0x0000ff00;
}
nvkm_mask(device, 0x10f440, mask, data);
if (mask = 0, data = 0, ram->diff.rammap_11_0e) {
data |= cfg->bios.rammap_11_0e << 8;
mask |= 0x0000ff00;
}
if (ram->diff.rammap_11_0b_0800) {
data |= cfg->bios.rammap_11_0b_0800 << 7;
mask |= 0x00000080;
}
if (ram->diff.rammap_11_0b_0400) {
data |= cfg->bios.rammap_11_0b_0400 << 5;
mask |= 0x00000020;
}
nvkm_mask(device, 0x10f444, mask, data);
}
static int
gk104_ram_prog(struct nvkm_ram *base)
{
struct gk104_ram *ram = gk104_ram(base);
struct gk104_ramfuc *fuc = &ram->fuc;
struct nvkm_device *device = ram->base.fb->subdev.device;
struct nvkm_ram_data *next = ram->base.next;
if (!nvkm_boolopt(device->cfgopt, "NvMemExec", true)) {
ram_exec(fuc, false);
return (ram->base.next == &ram->base.xition);
}
gk104_ram_prog_0(ram, 1000);
ram_exec(fuc, true);
gk104_ram_prog_0(ram, next->freq);
return (ram->base.next == &ram->base.xition);
}
static void
gk104_ram_tidy(struct nvkm_ram *base)
{
struct gk104_ram *ram = gk104_ram(base);
ram->base.next = NULL;
ram_exec(&ram->fuc, false);
}
static int
gk104_ram_train_type(struct nvkm_ram *ram, int i, u8 ramcfg,
struct gk104_ram_train *train)
{
struct nvkm_bios *bios = ram->fb->subdev.device->bios;
struct nvbios_M0205E M0205E;
struct nvbios_M0205S M0205S;
struct nvbios_M0209E M0209E;
struct nvbios_M0209S *remap = &train->remap;
struct nvbios_M0209S *value;
u8 ver, hdr, cnt, len;
u32 data;
if (!(data = nvbios_M0205Ep(bios, i, &ver, &hdr, &cnt, &len, &M0205E)))
return -ENOENT;
switch (M0205E.type) {
case 0x00: value = &train->type00; break;
case 0x01: value = &train->type01; break;
case 0x04: value = &train->type04; break;
case 0x06: value = &train->type06; break;
case 0x07: value = &train->type07; break;
case 0x08: value = &train->type08; break;
case 0x09: value = &train->type09; break;
default:
return 0;
}
if (!(data = nvbios_M0205Sp(bios, i, ramcfg, &ver, &hdr, &M0205S)))
return -EINVAL;
i = M0205S.data;
if (!(data = nvbios_M0209Ep(bios, i, &ver, &hdr, &cnt, &len, &M0209E)))
return -EINVAL;
if (!(data = nvbios_M0209Sp(bios, i, 0, &ver, &hdr, value)))
return -EINVAL;
if (M0209E.v02_07 == 2) {
if (!(data = nvbios_M0209Sp(bios, M0209E.v03, 0, &ver, &hdr,
remap)))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(value->data); i++)
value->data[i] = remap->data[value->data[i]];
} else
if (M0209E.v02_07 != 1)
return -EINVAL;
train->mask |= 1 << M0205E.type;
return 0;
}
static int
gk104_ram_train_init_0(struct nvkm_ram *ram, struct gk104_ram_train *train)
{
struct nvkm_subdev *subdev = &ram->fb->subdev;
struct nvkm_device *device = subdev->device;
int i, j;
if ((train->mask & 0x03d3) != 0x03d3) {
nvkm_warn(subdev, "missing link training data\n");
return -EINVAL;
}
for (i = 0; i < 0x30; i++) {
for (j = 0; j < 8; j += 4) {
nvkm_wr32(device, 0x10f968 + j, 0x00000000 | (i << 8));
nvkm_wr32(device, 0x10f920 + j, 0x00000000 |
train->type08.data[i] << 4 |
train->type06.data[i]);
nvkm_wr32(device, 0x10f918 + j, train->type00.data[i]);
nvkm_wr32(device, 0x10f920 + j, 0x00000100 |
train->type09.data[i] << 4 |
train->type07.data[i]);
nvkm_wr32(device, 0x10f918 + j, train->type01.data[i]);
}
}
for (j = 0; j < 8; j += 4) {
for (i = 0; i < 0x100; i++) {
nvkm_wr32(device, 0x10f968 + j, i);
nvkm_wr32(device, 0x10f900 + j, train->type04.data[i]);
}
}
return 0;
}
static int
gk104_ram_train_init(struct nvkm_ram *ram)
{
u8 ramcfg = nvbios_ramcfg_index(&ram->fb->subdev);
struct gk104_ram_train *train;
int ret, i;
if (!(train = kzalloc(sizeof(*train), GFP_KERNEL)))
return -ENOMEM;
for (i = 0; i < 0x100; i++) {
ret = gk104_ram_train_type(ram, i, ramcfg, train);
if (ret && ret != -ENOENT)
break;
}
switch (ram->type) {
case NVKM_RAM_TYPE_GDDR5:
ret = gk104_ram_train_init_0(ram, train);
break;
default:
ret = 0;
break;
}
kfree(train);
return ret;
}
int
gk104_ram_init(struct nvkm_ram *ram)
{
struct nvkm_subdev *subdev = &ram->fb->subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_bios *bios = device->bios;
u8 ver, hdr, cnt, len, snr, ssz;
u32 data, save;
int i;
data = nvbios_rammapTe(bios, &ver, &hdr, &cnt, &len, &snr, &ssz);
if (!data || hdr < 0x15)
return -EINVAL;
cnt = nvbios_rd08(bios, data + 0x14);
data = nvbios_rd32(bios, data + 0x10);
save = nvkm_rd32(device, 0x10f65c) & 0x000000f0;
for (i = 0; i < cnt; i++, data += 4) {
if (i != save >> 4) {
nvkm_mask(device, 0x10f65c, 0x000000f0, i << 4);
nvbios_exec(&(struct nvbios_init) {
.subdev = subdev,
.bios = bios,
.offset = nvbios_rd32(bios, data),
.execute = 1,
});
}
}
nvkm_mask(device, 0x10f65c, 0x000000f0, save);
nvkm_mask(device, 0x10f584, 0x11000000, 0x00000000);
nvkm_wr32(device, 0x10ecc0, 0xffffffff);
nvkm_mask(device, 0x10f160, 0x00000010, 0x00000010);
return gk104_ram_train_init(ram);
}
static int
gk104_ram_ctor_data(struct gk104_ram *ram, u8 ramcfg, int i)
{
struct nvkm_bios *bios = ram->base.fb->subdev.device->bios;
struct nvkm_ram_data *cfg;
struct nvbios_ramcfg *d = &ram->diff;
struct nvbios_ramcfg *p, *n;
u8 ver, hdr, cnt, len;
u32 data;
int ret;
if (!(cfg = kmalloc(sizeof(*cfg), GFP_KERNEL)))
return -ENOMEM;
p = &list_last_entry(&ram->cfg, typeof(*cfg), head)->bios;
n = &cfg->bios;
data = nvbios_rammapEp(bios, i, &ver, &hdr, &cnt, &len, &cfg->bios);
if (ret = -ENOENT, !data)
goto done;
if (ret = -ENOSYS, ver != 0x11 || hdr < 0x12)
goto done;
data = nvbios_rammapSp(bios, data, ver, hdr, cnt, len, ramcfg,
&ver, &hdr, &cfg->bios);
if (ret = -EINVAL, !data)
goto done;
if (ret = -ENOSYS, ver != 0x11 || hdr < 0x0a)
goto done;
if (cfg->bios.ramcfg_timing != 0xff) {
data = nvbios_timingEp(bios, cfg->bios.ramcfg_timing,
&ver, &hdr, &cnt, &len,
&cfg->bios);
if (ret = -EINVAL, !data)
goto done;
if (ret = -ENOSYS, ver != 0x20 || hdr < 0x33)
goto done;
}
list_add_tail(&cfg->head, &ram->cfg);
if (ret = 0, i == 0)
goto done;
d->rammap_11_0a_03fe |= p->rammap_11_0a_03fe != n->rammap_11_0a_03fe;
d->rammap_11_09_01ff |= p->rammap_11_09_01ff != n->rammap_11_09_01ff;
d->rammap_11_0a_0400 |= p->rammap_11_0a_0400 != n->rammap_11_0a_0400;
d->rammap_11_0a_0800 |= p->rammap_11_0a_0800 != n->rammap_11_0a_0800;
d->rammap_11_0b_01f0 |= p->rammap_11_0b_01f0 != n->rammap_11_0b_01f0;
d->rammap_11_0b_0200 |= p->rammap_11_0b_0200 != n->rammap_11_0b_0200;
d->rammap_11_0d |= p->rammap_11_0d != n->rammap_11_0d;
d->rammap_11_0f |= p->rammap_11_0f != n->rammap_11_0f;
d->rammap_11_0e |= p->rammap_11_0e != n->rammap_11_0e;
d->rammap_11_0b_0800 |= p->rammap_11_0b_0800 != n->rammap_11_0b_0800;
d->rammap_11_0b_0400 |= p->rammap_11_0b_0400 != n->rammap_11_0b_0400;
d->ramcfg_11_01_01 |= p->ramcfg_11_01_01 != n->ramcfg_11_01_01;
d->ramcfg_11_01_02 |= p->ramcfg_11_01_02 != n->ramcfg_11_01_02;
d->ramcfg_11_01_10 |= p->ramcfg_11_01_10 != n->ramcfg_11_01_10;
d->ramcfg_11_02_03 |= p->ramcfg_11_02_03 != n->ramcfg_11_02_03;
d->ramcfg_11_08_20 |= p->ramcfg_11_08_20 != n->ramcfg_11_08_20;
d->timing_20_30_07 |= p->timing_20_30_07 != n->timing_20_30_07;
done:
if (ret)
kfree(cfg);
return ret;
}
static void *
gk104_ram_dtor(struct nvkm_ram *base)
{
struct gk104_ram *ram = gk104_ram(base);
struct nvkm_ram_data *cfg, *tmp;
list_for_each_entry_safe(cfg, tmp, &ram->cfg, head) {
kfree(cfg);
}
return ram;
}
int
gk104_ram_new(struct nvkm_fb *fb, struct nvkm_ram **pram)
{
struct nvkm_subdev *subdev = &fb->subdev;
struct nvkm_device *device = subdev->device;
struct nvkm_bios *bios = device->bios;
struct nvkm_gpio *gpio = device->gpio;
struct dcb_gpio_func func;
struct gk104_ram *ram;
int ret, i;
u8 ramcfg = nvbios_ramcfg_index(subdev);
u32 tmp;
if (!(ram = kzalloc(sizeof(*ram), GFP_KERNEL)))
return -ENOMEM;
*pram = &ram->base;
ret = gf100_ram_ctor(&gk104_ram_func, fb, 0x022554, &ram->base);
if (ret)
return ret;
INIT_LIST_HEAD(&ram->cfg);
ram->parts = nvkm_rd32(device, 0x022438);
ram->pmask = nvkm_rd32(device, 0x022554);
ram->pnuts = 0;
for (i = 0, tmp = 0; i < ram->parts; i++) {
if (!(ram->pmask & (1 << i))) {
u32 cfg1 = nvkm_rd32(device, 0x110204 + (i * 0x1000));
if (tmp && tmp != cfg1) {
ram->pnuts |= (1 << i);
continue;
}
tmp = cfg1;
}
}
for (i = 0; !ret; i++) {
ret = gk104_ram_ctor_data(ram, ramcfg, i);
if (ret && ret != -ENOENT) {
nvkm_error(subdev, "failed to parse ramcfg data\n");
return ret;
}
}
ret = nvbios_pll_parse(bios, 0x0c, &ram->fuc.refpll);
if (ret) {
nvkm_error(subdev, "mclk refpll data not found\n");
return ret;
}
ret = nvbios_pll_parse(bios, 0x04, &ram->fuc.mempll);
if (ret) {
nvkm_error(subdev, "mclk pll data not found\n");
return ret;
}
ret = nvkm_gpio_find(gpio, 0, 0x18, DCB_GPIO_UNUSED, &func);
if (ret == 0) {
ram->fuc.r_gpioMV = ramfuc_reg(0x00d610 + (func.line * 0x04));
ram->fuc.r_funcMV[0] = (func.log[0] ^ 2) << 12;
ram->fuc.r_funcMV[1] = (func.log[1] ^ 2) << 12;
}
ret = nvkm_gpio_find(gpio, 0, 0x2e, DCB_GPIO_UNUSED, &func);
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
case NVKM_RAM_TYPE_GDDR5:
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
case NVKM_RAM_TYPE_DDR3:
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
