static int
nva3_pm_pll_offset(u32 id)
{
static const u32 pll_map[] = {
0x00, PLL_CORE,
0x01, PLL_SHADER,
0x02, PLL_MEMORY,
0x00, 0x00
};
const u32 *map = pll_map;
while (map[1]) {
if (id == map[1])
return map[0];
map += 2;
}
return -ENOENT;
}
int
nva3_pm_clock_get(struct drm_device *dev, u32 id)
{
u32 src0, src1, ctrl, coef;
struct pll_lims pll;
int ret, off;
int P, N, M;
ret = get_pll_limits(dev, id, &pll);
if (ret)
return ret;
off = nva3_pm_pll_offset(id);
if (off < 0)
return off;
src0 = nv_rd32(dev, 0x4120 + (off * 4));
src1 = nv_rd32(dev, 0x4160 + (off * 4));
ctrl = nv_rd32(dev, pll.reg + 0);
coef = nv_rd32(dev, pll.reg + 4);
NV_DEBUG(dev, "PLL %02x: 0x%08x 0x%08x 0x%08x 0x%08x\n",
id, src0, src1, ctrl, coef);
if (ctrl & 0x00000008) {
u32 div = ((src1 & 0x003c0000) >> 18) + 1;
return (pll.refclk * 2) / div;
}
P = (coef & 0x003f0000) >> 16;
N = (coef & 0x0000ff00) >> 8;
M = (coef & 0x000000ff);
return pll.refclk * N / M / P;
}
void *
nva3_pm_clock_pre(struct drm_device *dev, struct nouveau_pm_level *perflvl,
u32 id, int khz)
{
struct nva3_pm_state *pll;
struct pll_lims limits;
int N, M, P, diff;
int ret, off;
ret = get_pll_limits(dev, id, &limits);
if (ret < 0)
return (ret == -ENOENT) ? NULL : ERR_PTR(ret);
off = nva3_pm_pll_offset(id);
if (id < 0)
return ERR_PTR(-EINVAL);
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
pll->type = id;
pll->src0 = 0x004120 + (off * 4);
pll->src1 = 0x004160 + (off * 4);
pll->ctrl = limits.reg + 0;
pll->coef = limits.reg + 4;
pll->new_div = min((limits.refclk * 2) / (khz - 2999), 16);
if (pll->new_div) {
diff = khz - ((limits.refclk * 2) / pll->new_div);
if (diff < -2000 || diff >= 3000)
pll->new_div = 0;
}
if (!pll->new_div) {
ret = nva3_calc_pll(dev, &limits, khz, &N, NULL, &M, &P);
if (ret < 0)
return ERR_PTR(ret);
pll->new_pnm = (P << 16) | (N << 8) | M;
pll->new_div = 2 - 1;
} else {
pll->new_pnm = 0;
pll->new_div--;
}
if ((nv_rd32(dev, pll->src1) & 0x00000101) != 0x00000101)
pll->old_pnm = nv_rd32(dev, pll->coef);
return pll;
}
void
nva3_pm_clock_set(struct drm_device *dev, void *pre_state)
{
struct nva3_pm_state *pll = pre_state;
u32 ctrl = 0;
if (pll->type == PLL_MEMORY) {
nv_wr32(dev, 0x100210, 0);
nv_wr32(dev, 0x1002dc, 1);
nv_wr32(dev, 0x004018, 0x00001000);
ctrl = 0x18000100;
}
if (pll->old_pnm || !pll->new_pnm) {
nv_mask(dev, pll->src1, 0x003c0101, 0x00000101 |
(pll->new_div << 18));
nv_wr32(dev, pll->ctrl, 0x0001001d | ctrl);
nv_mask(dev, pll->ctrl, 0x00000001, 0x00000000);
}
if (pll->new_pnm) {
nv_mask(dev, pll->src0, 0x00000101, 0x00000101);
nv_wr32(dev, pll->coef, pll->new_pnm);
nv_wr32(dev, pll->ctrl, 0x0001001d | ctrl);
nv_mask(dev, pll->ctrl, 0x00000010, 0x00000000);
nv_mask(dev, pll->ctrl, 0x00020010, 0x00020010);
nv_wr32(dev, pll->ctrl, 0x00010015 | ctrl);
nv_mask(dev, pll->src1, 0x00000100, 0x00000000);
nv_mask(dev, pll->src1, 0x00000001, 0x00000000);
if (pll->type == PLL_MEMORY)
nv_wr32(dev, 0x4018, 0x10005000);
} else {
nv_mask(dev, pll->ctrl, 0x00000001, 0x00000000);
nv_mask(dev, pll->src0, 0x00000100, 0x00000000);
nv_mask(dev, pll->src0, 0x00000001, 0x00000000);
if (pll->type == PLL_MEMORY)
nv_wr32(dev, 0x4018, 0x1000d000);
}
if (pll->type == PLL_MEMORY) {
nv_wr32(dev, 0x1002dc, 0);
nv_wr32(dev, 0x100210, 0x80000000);
}
kfree(pll);
}
