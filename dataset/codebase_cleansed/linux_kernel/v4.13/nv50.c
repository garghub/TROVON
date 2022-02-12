static u32
read_div(struct nv50_clk *clk)
{
struct nvkm_device *device = clk->base.subdev.device;
switch (device->chipset) {
case 0x50:
case 0x84:
case 0x86:
case 0x98:
case 0xa0:
return nvkm_rd32(device, 0x004700);
case 0x92:
case 0x94:
case 0x96:
return nvkm_rd32(device, 0x004800);
default:
return 0x00000000;
}
}
static u32
read_pll_src(struct nv50_clk *clk, u32 base)
{
struct nvkm_subdev *subdev = &clk->base.subdev;
struct nvkm_device *device = subdev->device;
u32 coef, ref = nvkm_clk_read(&clk->base, nv_clk_src_crystal);
u32 rsel = nvkm_rd32(device, 0x00e18c);
int P, N, M, id;
switch (device->chipset) {
case 0x50:
case 0xa0:
switch (base) {
case 0x4020:
case 0x4028: id = !!(rsel & 0x00000004); break;
case 0x4008: id = !!(rsel & 0x00000008); break;
case 0x4030: id = 0; break;
default:
nvkm_error(subdev, "ref: bad pll %06x\n", base);
return 0;
}
coef = nvkm_rd32(device, 0x00e81c + (id * 0x0c));
ref *= (coef & 0x01000000) ? 2 : 4;
P = (coef & 0x00070000) >> 16;
N = ((coef & 0x0000ff00) >> 8) + 1;
M = ((coef & 0x000000ff) >> 0) + 1;
break;
case 0x84:
case 0x86:
case 0x92:
coef = nvkm_rd32(device, 0x00e81c);
P = (coef & 0x00070000) >> 16;
N = (coef & 0x0000ff00) >> 8;
M = (coef & 0x000000ff) >> 0;
break;
case 0x94:
case 0x96:
case 0x98:
rsel = nvkm_rd32(device, 0x00c050);
switch (base) {
case 0x4020: rsel = (rsel & 0x00000003) >> 0; break;
case 0x4008: rsel = (rsel & 0x0000000c) >> 2; break;
case 0x4028: rsel = (rsel & 0x00001800) >> 11; break;
case 0x4030: rsel = 3; break;
default:
nvkm_error(subdev, "ref: bad pll %06x\n", base);
return 0;
}
switch (rsel) {
case 0: id = 1; break;
case 1: return nvkm_clk_read(&clk->base, nv_clk_src_crystal);
case 2: return nvkm_clk_read(&clk->base, nv_clk_src_href);
case 3: id = 0; break;
}
coef = nvkm_rd32(device, 0x00e81c + (id * 0x28));
P = (nvkm_rd32(device, 0x00e824 + (id * 0x28)) >> 16) & 7;
P += (coef & 0x00070000) >> 16;
N = (coef & 0x0000ff00) >> 8;
M = (coef & 0x000000ff) >> 0;
break;
default:
BUG();
}
if (M)
return (ref * N / M) >> P;
return 0;
}
static u32
read_pll_ref(struct nv50_clk *clk, u32 base)
{
struct nvkm_subdev *subdev = &clk->base.subdev;
struct nvkm_device *device = subdev->device;
u32 src, mast = nvkm_rd32(device, 0x00c040);
switch (base) {
case 0x004028:
src = !!(mast & 0x00200000);
break;
case 0x004020:
src = !!(mast & 0x00400000);
break;
case 0x004008:
src = !!(mast & 0x00010000);
break;
case 0x004030:
src = !!(mast & 0x02000000);
break;
case 0x00e810:
return nvkm_clk_read(&clk->base, nv_clk_src_crystal);
default:
nvkm_error(subdev, "bad pll %06x\n", base);
return 0;
}
if (src)
return nvkm_clk_read(&clk->base, nv_clk_src_href);
return read_pll_src(clk, base);
}
static u32
read_pll(struct nv50_clk *clk, u32 base)
{
struct nvkm_device *device = clk->base.subdev.device;
u32 mast = nvkm_rd32(device, 0x00c040);
u32 ctrl = nvkm_rd32(device, base + 0);
u32 coef = nvkm_rd32(device, base + 4);
u32 ref = read_pll_ref(clk, base);
u32 freq = 0;
int N1, N2, M1, M2;
if (base == 0x004028 && (mast & 0x00100000)) {
if (device->chipset != 0xa0)
return nvkm_clk_read(&clk->base, nv_clk_src_dom6);
}
N2 = (coef & 0xff000000) >> 24;
M2 = (coef & 0x00ff0000) >> 16;
N1 = (coef & 0x0000ff00) >> 8;
M1 = (coef & 0x000000ff);
if ((ctrl & 0x80000000) && M1) {
freq = ref * N1 / M1;
if ((ctrl & 0x40000100) == 0x40000000) {
if (M2)
freq = freq * N2 / M2;
else
freq = 0;
}
}
return freq;
}
int
nv50_clk_read(struct nvkm_clk *base, enum nv_clk_src src)
{
struct nv50_clk *clk = nv50_clk(base);
struct nvkm_subdev *subdev = &clk->base.subdev;
struct nvkm_device *device = subdev->device;
u32 mast = nvkm_rd32(device, 0x00c040);
u32 P = 0;
switch (src) {
case nv_clk_src_crystal:
return device->crystal;
case nv_clk_src_href:
return 100000;
case nv_clk_src_hclk:
return div_u64((u64)nvkm_clk_read(&clk->base, nv_clk_src_href) * 27778, 10000);
case nv_clk_src_hclkm3:
return nvkm_clk_read(&clk->base, nv_clk_src_hclk) * 3;
case nv_clk_src_hclkm3d2:
return nvkm_clk_read(&clk->base, nv_clk_src_hclk) * 3 / 2;
case nv_clk_src_host:
switch (mast & 0x30000000) {
case 0x00000000: return nvkm_clk_read(&clk->base, nv_clk_src_href);
case 0x10000000: break;
case 0x20000000:
case 0x30000000: return nvkm_clk_read(&clk->base, nv_clk_src_hclk);
}
break;
case nv_clk_src_core:
if (!(mast & 0x00100000))
P = (nvkm_rd32(device, 0x004028) & 0x00070000) >> 16;
switch (mast & 0x00000003) {
case 0x00000000: return nvkm_clk_read(&clk->base, nv_clk_src_crystal) >> P;
case 0x00000001: return nvkm_clk_read(&clk->base, nv_clk_src_dom6);
case 0x00000002: return read_pll(clk, 0x004020) >> P;
case 0x00000003: return read_pll(clk, 0x004028) >> P;
}
break;
case nv_clk_src_shader:
P = (nvkm_rd32(device, 0x004020) & 0x00070000) >> 16;
switch (mast & 0x00000030) {
case 0x00000000:
if (mast & 0x00000080)
return nvkm_clk_read(&clk->base, nv_clk_src_host) >> P;
return nvkm_clk_read(&clk->base, nv_clk_src_crystal) >> P;
case 0x00000010: break;
case 0x00000020: return read_pll(clk, 0x004028) >> P;
case 0x00000030: return read_pll(clk, 0x004020) >> P;
}
break;
case nv_clk_src_mem:
P = (nvkm_rd32(device, 0x004008) & 0x00070000) >> 16;
if (nvkm_rd32(device, 0x004008) & 0x00000200) {
switch (mast & 0x0000c000) {
case 0x00000000:
return nvkm_clk_read(&clk->base, nv_clk_src_crystal) >> P;
case 0x00008000:
case 0x0000c000:
return nvkm_clk_read(&clk->base, nv_clk_src_href) >> P;
}
} else {
return read_pll(clk, 0x004008) >> P;
}
break;
case nv_clk_src_vdec:
P = (read_div(clk) & 0x00000700) >> 8;
switch (device->chipset) {
case 0x84:
case 0x86:
case 0x92:
case 0x94:
case 0x96:
case 0xa0:
switch (mast & 0x00000c00) {
case 0x00000000:
if (device->chipset == 0xa0)
return nvkm_clk_read(&clk->base, nv_clk_src_core) >> P;
return nvkm_clk_read(&clk->base, nv_clk_src_crystal) >> P;
case 0x00000400:
return 0;
case 0x00000800:
if (mast & 0x01000000)
return read_pll(clk, 0x004028) >> P;
return read_pll(clk, 0x004030) >> P;
case 0x00000c00:
return nvkm_clk_read(&clk->base, nv_clk_src_core) >> P;
}
break;
case 0x98:
switch (mast & 0x00000c00) {
case 0x00000000:
return nvkm_clk_read(&clk->base, nv_clk_src_core) >> P;
case 0x00000400:
return 0;
case 0x00000800:
return nvkm_clk_read(&clk->base, nv_clk_src_hclkm3d2) >> P;
case 0x00000c00:
return nvkm_clk_read(&clk->base, nv_clk_src_mem) >> P;
}
break;
}
break;
case nv_clk_src_dom6:
switch (device->chipset) {
case 0x50:
case 0xa0:
return read_pll(clk, 0x00e810) >> 2;
case 0x84:
case 0x86:
case 0x92:
case 0x94:
case 0x96:
case 0x98:
P = (read_div(clk) & 0x00000007) >> 0;
switch (mast & 0x0c000000) {
case 0x00000000: return nvkm_clk_read(&clk->base, nv_clk_src_href);
case 0x04000000: break;
case 0x08000000: return nvkm_clk_read(&clk->base, nv_clk_src_hclk);
case 0x0c000000:
return nvkm_clk_read(&clk->base, nv_clk_src_hclkm3) >> P;
}
break;
default:
break;
}
default:
break;
}
nvkm_debug(subdev, "unknown clock source %d %08x\n", src, mast);
return -EINVAL;
}
static u32
calc_pll(struct nv50_clk *clk, u32 reg, u32 idx, int *N, int *M, int *P)
{
struct nvkm_subdev *subdev = &clk->base.subdev;
struct nvbios_pll pll;
int ret;
ret = nvbios_pll_parse(subdev->device->bios, reg, &pll);
if (ret)
return 0;
pll.vco2.max_freq = 0;
pll.refclk = read_pll_ref(clk, reg);
if (!pll.refclk)
return 0;
return nv04_pll_calc(subdev, &pll, idx, N, M, NULL, NULL, P);
}
static inline u32
calc_div(u32 src, u32 target, int *div)
{
u32 clk0 = src, clk1 = src;
for (*div = 0; *div <= 7; (*div)++) {
if (clk0 <= target) {
clk1 = clk0 << (*div ? 1 : 0);
break;
}
clk0 >>= 1;
}
if (target - clk0 <= clk1 - target)
return clk0;
(*div)--;
return clk1;
}
static inline u32
clk_same(u32 a, u32 b)
{
return ((a / 1000) == (b / 1000));
}
int
nv50_clk_calc(struct nvkm_clk *base, struct nvkm_cstate *cstate)
{
struct nv50_clk *clk = nv50_clk(base);
struct nv50_clk_hwsq *hwsq = &clk->hwsq;
struct nvkm_subdev *subdev = &clk->base.subdev;
struct nvkm_device *device = subdev->device;
const int shader = cstate->domain[nv_clk_src_shader];
const int core = cstate->domain[nv_clk_src_core];
const int vdec = cstate->domain[nv_clk_src_vdec];
const int dom6 = cstate->domain[nv_clk_src_dom6];
u32 mastm = 0, mastv = 0;
u32 divsm = 0, divsv = 0;
int N, M, P1, P2;
int freq, out;
out = clk_init(hwsq, subdev);
if (out)
return out;
clk_wr32(hwsq, fifo, 0x00000001);
clk_nsec(hwsq, 8000);
clk_setf(hwsq, 0x10, 0x00);
clk_wait(hwsq, 0x00, 0x01);
if (vdec) {
freq = calc_div(core, vdec, &P1);
if (device->chipset != 0x98)
out = read_pll(clk, 0x004030);
else
out = nvkm_clk_read(&clk->base, nv_clk_src_hclkm3d2);
out = calc_div(out, vdec, &P2);
if (abs(vdec - freq) <= abs(vdec - out)) {
if (device->chipset != 0x98)
mastv |= 0x00000c00;
divsv |= P1 << 8;
} else {
mastv |= 0x00000800;
divsv |= P2 << 8;
}
mastm |= 0x00000c00;
divsm |= 0x00000700;
}
if (dom6) {
if (clk_same(dom6, nvkm_clk_read(&clk->base, nv_clk_src_href))) {
mastv |= 0x00000000;
} else
if (clk_same(dom6, nvkm_clk_read(&clk->base, nv_clk_src_hclk))) {
mastv |= 0x08000000;
} else {
freq = nvkm_clk_read(&clk->base, nv_clk_src_hclk) * 3;
calc_div(freq, dom6, &P1);
mastv |= 0x0c000000;
divsv |= P1;
}
mastm |= 0x0c000000;
divsm |= 0x00000007;
}
clk_mask(hwsq, mast, mastm, 0x00000000);
clk_mask(hwsq, divs, divsm, divsv);
clk_mask(hwsq, mast, mastm, mastv);
if (device->chipset < 0x92)
clk_mask(hwsq, mast, 0x001000b0, 0x00100080);
else
clk_mask(hwsq, mast, 0x000000b3, 0x00000081);
freq = calc_pll(clk, 0x4028, core, &N, &M, &P1);
if (freq == 0)
return -ERANGE;
clk_mask(hwsq, nvpll[0], 0xc03f0100,
0x80000000 | (P1 << 19) | (P1 << 16));
clk_mask(hwsq, nvpll[1], 0x0000ffff, (N << 8) | M);
if (P1-- && shader == (core << 1)) {
clk_mask(hwsq, spll[0], 0xc03f0100, (P1 << 19) | (P1 << 16));
clk_mask(hwsq, mast, 0x00100033, 0x00000023);
} else {
freq = calc_pll(clk, 0x4020, shader, &N, &M, &P1);
if (freq == 0)
return -ERANGE;
clk_mask(hwsq, spll[0], 0xc03f0100,
0x80000000 | (P1 << 19) | (P1 << 16));
clk_mask(hwsq, spll[1], 0x0000ffff, (N << 8) | M);
clk_mask(hwsq, mast, 0x00100033, 0x00000033);
}
clk_setf(hwsq, 0x10, 0x01);
clk_wait(hwsq, 0x00, 0x00);
clk_wr32(hwsq, fifo, 0x00000000);
return 0;
}
int
nv50_clk_prog(struct nvkm_clk *base)
{
struct nv50_clk *clk = nv50_clk(base);
return clk_exec(&clk->hwsq, true);
}
void
nv50_clk_tidy(struct nvkm_clk *base)
{
struct nv50_clk *clk = nv50_clk(base);
clk_exec(&clk->hwsq, false);
}
int
nv50_clk_new_(const struct nvkm_clk_func *func, struct nvkm_device *device,
int index, bool allow_reclock, struct nvkm_clk **pclk)
{
struct nv50_clk *clk;
int ret;
if (!(clk = kzalloc(sizeof(*clk), GFP_KERNEL)))
return -ENOMEM;
ret = nvkm_clk_ctor(func, device, index, allow_reclock, &clk->base);
*pclk = &clk->base;
if (ret)
return ret;
clk->hwsq.r_fifo = hwsq_reg(0x002504);
clk->hwsq.r_spll[0] = hwsq_reg(0x004020);
clk->hwsq.r_spll[1] = hwsq_reg(0x004024);
clk->hwsq.r_nvpll[0] = hwsq_reg(0x004028);
clk->hwsq.r_nvpll[1] = hwsq_reg(0x00402c);
switch (device->chipset) {
case 0x92:
case 0x94:
case 0x96:
clk->hwsq.r_divs = hwsq_reg(0x004800);
break;
default:
clk->hwsq.r_divs = hwsq_reg(0x004700);
break;
}
clk->hwsq.r_mast = hwsq_reg(0x00c040);
return 0;
}
int
nv50_clk_new(struct nvkm_device *device, int index, struct nvkm_clk **pclk)
{
return nv50_clk_new_(&nv50_clk, device, index, false, pclk);
}
