int
nv40_ram_calc(struct nvkm_fb *pfb, u32 freq)
{
struct nvkm_bios *bios = nvkm_bios(pfb);
struct nv40_ram *ram = (void *)pfb->ram;
struct nvbios_pll pll;
int N1, M1, N2, M2;
int log2P, ret;
ret = nvbios_pll_parse(bios, 0x04, &pll);
if (ret) {
nv_error(pfb, "mclk pll data not found\n");
return ret;
}
ret = nv04_pll_calc(nv_subdev(pfb), &pll, freq,
&N1, &M1, &N2, &M2, &log2P);
if (ret < 0)
return ret;
ram->ctrl = 0x80000000 | (log2P << 16);
ram->ctrl |= min(pll.bias_p + log2P, (int)pll.max_p) << 20;
if (N2 == M2) {
ram->ctrl |= 0x00000100;
ram->coef = (N1 << 8) | M1;
} else {
ram->ctrl |= 0x40000000;
ram->coef = (N2 << 24) | (M2 << 16) | (N1 << 8) | M1;
}
return 0;
}
int
nv40_ram_prog(struct nvkm_fb *pfb)
{
struct nvkm_bios *bios = nvkm_bios(pfb);
struct nv40_ram *ram = (void *)pfb->ram;
struct bit_entry M;
u32 crtc_mask = 0;
u8 sr1[2];
int i;
for (i = 0; i < 2; i++) {
u32 vbl = nv_rd32(pfb, 0x600808 + (i * 0x2000));
u32 cnt = 0;
do {
if (vbl != nv_rd32(pfb, 0x600808 + (i * 0x2000))) {
nv_wr08(pfb, 0x0c03c4 + (i * 0x2000), 0x01);
sr1[i] = nv_rd08(pfb, 0x0c03c5 + (i * 0x2000));
if (!(sr1[i] & 0x20))
crtc_mask |= (1 << i);
break;
}
udelay(1);
} while (cnt++ < 32);
}
for (i = 0; i < 2; i++) {
if (!(crtc_mask & (1 << i)))
continue;
nv_wait(pfb, 0x600808 + (i * 0x2000), 0x00010000, 0x00000000);
nv_wait(pfb, 0x600808 + (i * 0x2000), 0x00010000, 0x00010000);
nv_wr08(pfb, 0x0c03c4 + (i * 0x2000), 0x01);
nv_wr08(pfb, 0x0c03c5 + (i * 0x2000), sr1[i] | 0x20);
}
nv_wr32(pfb, 0x1002d4, 0x00000001);
nv_wr32(pfb, 0x1002d0, 0x00000001);
nv_wr32(pfb, 0x1002d0, 0x00000001);
nv_mask(pfb, 0x100210, 0x80000000, 0x00000000);
nv_wr32(pfb, 0x1002dc, 0x00000001);
nv_mask(pfb, 0x00c040, 0x0000c000, 0x00000000);
switch (nv_device(pfb)->chipset) {
case 0x40:
case 0x45:
case 0x41:
case 0x42:
case 0x47:
nv_mask(pfb, 0x004044, 0xc0771100, ram->ctrl);
nv_mask(pfb, 0x00402c, 0xc0771100, ram->ctrl);
nv_wr32(pfb, 0x004048, ram->coef);
nv_wr32(pfb, 0x004030, ram->coef);
case 0x43:
case 0x49:
case 0x4b:
nv_mask(pfb, 0x004038, 0xc0771100, ram->ctrl);
nv_wr32(pfb, 0x00403c, ram->coef);
default:
nv_mask(pfb, 0x004020, 0xc0771100, ram->ctrl);
nv_wr32(pfb, 0x004024, ram->coef);
break;
}
udelay(100);
nv_mask(pfb, 0x00c040, 0x0000c000, 0x0000c000);
nv_wr32(pfb, 0x1002dc, 0x00000000);
nv_mask(pfb, 0x100210, 0x80000000, 0x80000000);
udelay(100);
if (!bit_entry(bios, 'M', &M)) {
struct nvbios_init init = {
.subdev = nv_subdev(pfb),
.bios = bios,
.offset = nv_ro16(bios, M.offset + 0x00),
.execute = 1,
};
nvbios_exec(&init);
}
for (i = 0; i < 2; i++) {
if (!(crtc_mask & (1 << i)))
continue;
nv_wait(pfb, 0x600808 + (i * 0x2000), 0x00010000, 0x00010000);
nv_wr08(pfb, 0x0c03c4 + (i * 0x2000), 0x01);
nv_wr08(pfb, 0x0c03c5 + (i * 0x2000), sr1[i]);
}
return 0;
}
void
nv40_ram_tidy(struct nvkm_fb *pfb)
{
}
static int
nv40_ram_create(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 size,
struct nvkm_object **pobject)
{
struct nvkm_fb *pfb = nvkm_fb(parent);
struct nv40_ram *ram;
u32 pbus1218 = nv_rd32(pfb, 0x001218);
int ret;
ret = nvkm_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
switch (pbus1218 & 0x00000300) {
case 0x00000000: ram->base.type = NV_MEM_TYPE_SDRAM; break;
case 0x00000100: ram->base.type = NV_MEM_TYPE_DDR1; break;
case 0x00000200: ram->base.type = NV_MEM_TYPE_GDDR3; break;
case 0x00000300: ram->base.type = NV_MEM_TYPE_DDR2; break;
}
ram->base.size = nv_rd32(pfb, 0x10020c) & 0xff000000;
ram->base.parts = (nv_rd32(pfb, 0x100200) & 0x00000003) + 1;
ram->base.tags = nv_rd32(pfb, 0x100320);
ram->base.calc = nv40_ram_calc;
ram->base.prog = nv40_ram_prog;
ram->base.tidy = nv40_ram_tidy;
return 0;
}
