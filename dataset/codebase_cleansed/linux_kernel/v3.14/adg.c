static int rsnd_adg_set_convert_clk_gen1(struct rsnd_priv *priv,
struct rsnd_mod *mod,
unsigned int src_rate,
unsigned int dst_rate)
{
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
int idx, sel, div, shift;
u32 mask, val;
int id = rsnd_mod_id(mod);
unsigned int sel_rate [] = {
clk_get_rate(adg->clk[CLKA]),
clk_get_rate(adg->clk[CLKB]),
clk_get_rate(adg->clk[CLKC]),
0,
adg->rbga_rate_for_441khz_div_6,
adg->rbgb_rate_for_48khz_div_6,
};
for (sel = 0; sel < ARRAY_SIZE(sel_rate); sel++) {
for (div = 128, idx = 0;
div <= 2048;
div *= 2, idx++) {
if (src_rate == sel_rate[sel] / div) {
val = (idx << 4) | sel;
goto find_rate;
}
}
}
dev_err(dev, "can't find convert src clk\n");
return -EINVAL;
find_rate:
shift = (id % 4) * 8;
mask = 0xFF << shift;
val = val << shift;
dev_dbg(dev, "adg convert src clk = %02x\n", val);
switch (id / 4) {
case 0:
rsnd_mod_bset(mod, AUDIO_CLK_SEL3, mask, val);
break;
case 1:
rsnd_mod_bset(mod, AUDIO_CLK_SEL4, mask, val);
break;
case 2:
rsnd_mod_bset(mod, AUDIO_CLK_SEL5, mask, val);
break;
}
return 0;
}
int rsnd_adg_set_convert_clk(struct rsnd_priv *priv,
struct rsnd_mod *mod,
unsigned int src_rate,
unsigned int dst_rate)
{
if (rsnd_is_gen1(priv))
return rsnd_adg_set_convert_clk_gen1(priv, mod,
src_rate, dst_rate);
return -EINVAL;
}
static void rsnd_adg_set_ssi_clk(struct rsnd_mod *mod, u32 val)
{
int id = rsnd_mod_id(mod);
int shift = (id % 4) * 8;
u32 mask = 0xFF << shift;
val = val << shift;
if (id == 8)
return;
switch (id / 4) {
case 0:
rsnd_mod_bset(mod, AUDIO_CLK_SEL0, mask, val);
break;
case 1:
rsnd_mod_bset(mod, AUDIO_CLK_SEL1, mask, val);
break;
case 2:
rsnd_mod_bset(mod, AUDIO_CLK_SEL2, mask, val);
break;
}
}
int rsnd_adg_ssi_clk_stop(struct rsnd_mod *mod)
{
rsnd_adg_set_ssi_clk(mod, 0);
return 0;
}
int rsnd_adg_ssi_clk_try_start(struct rsnd_mod *mod, unsigned int rate)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct clk *clk;
int i;
u32 data;
int sel_table[] = {
[CLKA] = 0x1,
[CLKB] = 0x2,
[CLKC] = 0x3,
[CLKI] = 0x0,
};
dev_dbg(dev, "request clock = %d\n", rate);
data = 0;
for_each_rsnd_clk(clk, adg, i) {
if (rate == clk_get_rate(clk)) {
data = sel_table[i];
goto found_clock;
}
}
if (rate == adg->rbga_rate_for_441khz_div_6) {
data = 0x10;
goto found_clock;
}
if (rate == adg->rbgb_rate_for_48khz_div_6) {
data = 0x20;
goto found_clock;
}
return -EIO;
found_clock:
rsnd_mod_bset(mod, SSICKR, 0x00FF0000, adg->ckr);
rsnd_mod_write(mod, BRRA, 0x00000002);
rsnd_mod_write(mod, BRRB, 0x00000002);
rsnd_adg_set_ssi_clk(mod, data);
dev_dbg(dev, "ADG: ssi%d selects clk%d = %d",
rsnd_mod_id(mod), i, rate);
return 0;
}
static void rsnd_adg_ssi_clk_init(struct rsnd_priv *priv, struct rsnd_adg *adg)
{
struct clk *clk;
unsigned long rate;
u32 ckr;
int i;
int brg_table[] = {
[CLKA] = 0x0,
[CLKB] = 0x1,
[CLKC] = 0x4,
[CLKI] = 0x2,
};
ckr = 0;
adg->rbga_rate_for_441khz_div_6 = 0;
adg->rbgb_rate_for_48khz_div_6 = 0;
for_each_rsnd_clk(clk, adg, i) {
rate = clk_get_rate(clk);
if (0 == rate)
continue;
if (!adg->rbga_rate_for_441khz_div_6 && (0 == rate % 44100)) {
adg->rbga_rate_for_441khz_div_6 = rate / 6;
ckr |= brg_table[i] << 20;
}
if (!adg->rbgb_rate_for_48khz_div_6 && (0 == rate % 48000)) {
adg->rbgb_rate_for_48khz_div_6 = rate / 6;
ckr |= brg_table[i] << 16;
}
}
adg->ckr = ckr;
}
int rsnd_adg_probe(struct platform_device *pdev,
struct rcar_snd_info *info,
struct rsnd_priv *priv)
{
struct rsnd_adg *adg;
struct device *dev = rsnd_priv_to_dev(priv);
struct clk *clk;
int i;
adg = devm_kzalloc(dev, sizeof(*adg), GFP_KERNEL);
if (!adg) {
dev_err(dev, "ADG allocate failed\n");
return -ENOMEM;
}
adg->clk[CLKA] = clk_get(NULL, "audio_clk_a");
adg->clk[CLKB] = clk_get(NULL, "audio_clk_b");
adg->clk[CLKC] = clk_get(NULL, "audio_clk_c");
adg->clk[CLKI] = clk_get(NULL, "audio_clk_internal");
for_each_rsnd_clk(clk, adg, i) {
if (IS_ERR(clk)) {
dev_err(dev, "Audio clock failed\n");
return -EIO;
}
}
rsnd_adg_ssi_clk_init(priv, adg);
priv->adg = adg;
dev_dbg(dev, "adg probed\n");
return 0;
}
void rsnd_adg_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct rsnd_adg *adg = priv->adg;
struct clk *clk;
int i;
for_each_rsnd_clk(clk, adg, i)
clk_put(clk);
}
