int
nv50_pm_clock_get(struct drm_device *dev, u32 id)
{
struct pll_lims pll;
int P, N, M, ret;
u32 reg0, reg1;
ret = get_pll_limits(dev, id, &pll);
if (ret)
return ret;
reg0 = nv_rd32(dev, pll.reg + 0);
reg1 = nv_rd32(dev, pll.reg + 4);
if ((reg0 & 0x80000000) == 0) {
if (id == PLL_SHADER) {
NV_DEBUG(dev, "Shader PLL is disabled. "
"Shader clock is twice the core\n");
ret = nv50_pm_clock_get(dev, PLL_CORE);
if (ret > 0)
return ret << 1;
} else if (id == PLL_MEMORY) {
NV_DEBUG(dev, "Memory PLL is disabled. "
"Memory clock is equal to the ref_clk\n");
return pll.refclk;
}
}
P = (reg0 & 0x00070000) >> 16;
N = (reg1 & 0x0000ff00) >> 8;
M = (reg1 & 0x000000ff);
return ((pll.refclk * N / M) >> P);
}
void *
nv50_pm_clock_pre(struct drm_device *dev, struct nouveau_pm_level *perflvl,
u32 id, int khz)
{
struct nv50_pm_state *state;
int dummy, ret;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return ERR_PTR(-ENOMEM);
state->type = id;
state->perflvl = perflvl;
ret = get_pll_limits(dev, id, &state->pll);
if (ret < 0) {
kfree(state);
return (ret == -ENOENT) ? NULL : ERR_PTR(ret);
}
ret = nv50_calc_pll(dev, &state->pll, khz, &state->N, &state->M,
&dummy, &dummy, &state->P);
if (ret < 0) {
kfree(state);
return ERR_PTR(ret);
}
return state;
}
void
nv50_pm_clock_set(struct drm_device *dev, void *pre_state)
{
struct nv50_pm_state *state = pre_state;
struct nouveau_pm_level *perflvl = state->perflvl;
u32 reg = state->pll.reg, tmp;
struct bit_entry BIT_M;
u16 script;
int N = state->N;
int M = state->M;
int P = state->P;
if (state->type == PLL_MEMORY && perflvl->memscript &&
bit_table(dev, 'M', &BIT_M) == 0 &&
BIT_M.version == 1 && BIT_M.length >= 0x0b) {
script = ROM16(BIT_M.data[0x05]);
if (script)
nouveau_bios_run_init_table(dev, script, NULL);
script = ROM16(BIT_M.data[0x07]);
if (script)
nouveau_bios_run_init_table(dev, script, NULL);
script = ROM16(BIT_M.data[0x09]);
if (script)
nouveau_bios_run_init_table(dev, script, NULL);
nouveau_bios_run_init_table(dev, perflvl->memscript, NULL);
}
if (state->type == PLL_MEMORY) {
nv_wr32(dev, 0x100210, 0);
nv_wr32(dev, 0x1002dc, 1);
}
tmp = nv_rd32(dev, reg + 0) & 0xfff8ffff;
tmp |= 0x80000000 | (P << 16);
nv_wr32(dev, reg + 0, tmp);
nv_wr32(dev, reg + 4, (N << 8) | M);
if (state->type == PLL_MEMORY) {
nv_wr32(dev, 0x1002dc, 0);
nv_wr32(dev, 0x100210, 0x80000000);
}
kfree(state);
}
