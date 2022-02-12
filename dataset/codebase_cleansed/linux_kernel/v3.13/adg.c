static enum rsnd_reg rsnd_adg_ssi_reg_get(int id)
{
enum rsnd_reg reg;
if (id == 8)
return RSND_REG_MAX;
if (0 <= id && id <= 3)
reg = RSND_REG_AUDIO_CLK_SEL0;
else if (4 <= id && id <= 7)
reg = RSND_REG_AUDIO_CLK_SEL1;
else
reg = RSND_REG_AUDIO_CLK_SEL2;
return reg;
}
int rsnd_adg_ssi_clk_stop(struct rsnd_mod *mod)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
enum rsnd_reg reg;
int id;
id = rsnd_mod_id(mod);
reg = rsnd_adg_ssi_reg_get(id);
rsnd_write(priv, mod, reg, 0);
return 0;
}
int rsnd_adg_ssi_clk_try_start(struct rsnd_mod *mod, unsigned int rate)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct clk *clk;
enum rsnd_reg reg;
int id, shift, i;
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
if (rate == adg->rate_of_441khz_div_6) {
data = 0x10;
goto found_clock;
}
if (rate == adg->rate_of_48khz_div_6) {
data = 0x20;
goto found_clock;
}
return -EIO;
found_clock:
rsnd_mod_bset(mod, SSICKR, 0x00FF0000, adg->ckr);
rsnd_mod_write(mod, BRRA, 0x00000002);
rsnd_mod_write(mod, BRRB, 0x00000002);
id = rsnd_mod_id(mod);
reg = rsnd_adg_ssi_reg_get(id);
dev_dbg(dev, "ADG: ssi%d selects clk%d = %d", id, i, rate);
shift = (id % 4) * 8;
rsnd_bset(priv, mod, reg,
0xFF << shift,
data << shift);
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
adg->rate_of_441khz_div_6 = 0;
adg->rate_of_48khz_div_6 = 0;
for_each_rsnd_clk(clk, adg, i) {
rate = clk_get_rate(clk);
if (0 == rate)
continue;
if (!adg->rate_of_441khz_div_6 && (0 == rate % 44100)) {
adg->rate_of_441khz_div_6 = rate / 6;
ckr |= brg_table[i] << 20;
}
if (!adg->rate_of_48khz_div_6 && (0 == rate % 48000)) {
adg->rate_of_48khz_div_6 = rate / 6;
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
