static u32 rsnd_adg_calculate_rbgx(unsigned long div)
{
int i, ratio;
if (!div)
return 0;
for (i = 3; i >= 0; i--) {
ratio = 2 << (i * 2);
if (0 == (div % ratio))
return (u32)((i << 8) | ((div / ratio) - 1));
}
return ~0;
}
static u32 rsnd_adg_ssi_ws_timing_gen2(struct rsnd_dai_stream *io)
{
struct rsnd_mod *mod = rsnd_io_to_mod_ssi(io);
int id = rsnd_mod_id(mod);
int ws = id;
if (rsnd_ssi_is_pin_sharing(io)) {
switch (id) {
case 1:
case 2:
ws = 0;
break;
case 4:
ws = 3;
break;
case 8:
ws = 7;
break;
}
}
return (0x6 + ws) << 8;
}
int rsnd_adg_set_cmd_timsel_gen2(struct rsnd_mod *mod,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
int id = rsnd_mod_id(mod);
int shift = (id % 2) ? 16 : 0;
u32 mask, val;
val = rsnd_adg_ssi_ws_timing_gen2(io);
val = val << shift;
mask = 0xffff << shift;
rsnd_mod_bset(adg_mod, CMDOUT_TIMSEL, mask, val);
return 0;
}
static int rsnd_adg_set_src_timsel_gen2(struct rsnd_mod *src_mod,
struct rsnd_dai_stream *io,
u32 timsel)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(src_mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
int is_play = rsnd_io_is_play(io);
int id = rsnd_mod_id(src_mod);
int shift = (id % 2) ? 16 : 0;
u32 mask, ws;
u32 in, out;
rsnd_mod_confirm_src(src_mod);
ws = rsnd_adg_ssi_ws_timing_gen2(io);
in = (is_play) ? timsel : ws;
out = (is_play) ? ws : timsel;
in = in << shift;
out = out << shift;
mask = 0xffff << shift;
switch (id / 2) {
case 0:
rsnd_mod_bset(adg_mod, SRCIN_TIMSEL0, mask, in);
rsnd_mod_bset(adg_mod, SRCOUT_TIMSEL0, mask, out);
break;
case 1:
rsnd_mod_bset(adg_mod, SRCIN_TIMSEL1, mask, in);
rsnd_mod_bset(adg_mod, SRCOUT_TIMSEL1, mask, out);
break;
case 2:
rsnd_mod_bset(adg_mod, SRCIN_TIMSEL2, mask, in);
rsnd_mod_bset(adg_mod, SRCOUT_TIMSEL2, mask, out);
break;
case 3:
rsnd_mod_bset(adg_mod, SRCIN_TIMSEL3, mask, in);
rsnd_mod_bset(adg_mod, SRCOUT_TIMSEL3, mask, out);
break;
case 4:
rsnd_mod_bset(adg_mod, SRCIN_TIMSEL4, mask, in);
rsnd_mod_bset(adg_mod, SRCOUT_TIMSEL4, mask, out);
break;
}
return 0;
}
int rsnd_adg_set_convert_clk_gen2(struct rsnd_mod *src_mod,
struct rsnd_dai_stream *io,
unsigned int src_rate,
unsigned int dst_rate)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(src_mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
struct device *dev = rsnd_priv_to_dev(priv);
int idx, sel, div, step, ret;
u32 val, en;
unsigned int min, diff;
unsigned int sel_rate [] = {
clk_get_rate(adg->clk[CLKA]),
clk_get_rate(adg->clk[CLKB]),
clk_get_rate(adg->clk[CLKC]),
adg->rbga_rate_for_441khz,
adg->rbgb_rate_for_48khz,
};
rsnd_mod_confirm_src(src_mod);
min = ~0;
val = 0;
en = 0;
for (sel = 0; sel < ARRAY_SIZE(sel_rate); sel++) {
idx = 0;
step = 2;
if (!sel_rate[sel])
continue;
for (div = 2; div <= 98304; div += step) {
diff = abs(src_rate - sel_rate[sel] / div);
if (min > diff) {
val = (sel << 8) | idx;
min = diff;
en = 1 << (sel + 1);
}
if ((idx > 2) && (idx % 2))
step *= 2;
if (idx == 0x1c) {
div += step;
step *= 2;
}
idx++;
}
}
if (min == ~0) {
dev_err(dev, "no Input clock\n");
return -EIO;
}
ret = rsnd_adg_set_src_timsel_gen2(src_mod, io, val);
if (ret < 0) {
dev_err(dev, "timsel error\n");
return ret;
}
rsnd_mod_bset(adg_mod, DIV_EN, en, en);
dev_dbg(dev, "convert rate %d <-> %d\n", src_rate, dst_rate);
return 0;
}
int rsnd_adg_set_convert_timing_gen2(struct rsnd_mod *src_mod,
struct rsnd_dai_stream *io)
{
u32 val = rsnd_adg_ssi_ws_timing_gen2(io);
rsnd_mod_confirm_src(src_mod);
return rsnd_adg_set_src_timsel_gen2(src_mod, io, val);
}
int rsnd_adg_set_convert_clk_gen1(struct rsnd_priv *priv,
struct rsnd_mod *mod,
unsigned int src_rate,
unsigned int dst_rate)
{
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
struct device *dev = rsnd_priv_to_dev(priv);
int idx, sel, div, shift;
u32 mask, val;
int id = rsnd_mod_id(mod);
unsigned int sel_rate [] = {
clk_get_rate(adg->clk[CLKA]),
clk_get_rate(adg->clk[CLKB]),
clk_get_rate(adg->clk[CLKC]),
0,
adg->rbga_rate_for_441khz,
adg->rbgb_rate_for_48khz,
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
rsnd_mod_bset(adg_mod, AUDIO_CLK_SEL3, mask, val);
break;
case 1:
rsnd_mod_bset(adg_mod, AUDIO_CLK_SEL4, mask, val);
break;
case 2:
rsnd_mod_bset(adg_mod, AUDIO_CLK_SEL5, mask, val);
break;
}
return 0;
}
static void rsnd_adg_set_ssi_clk(struct rsnd_mod *ssi_mod, u32 val)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(ssi_mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
int id = rsnd_mod_id(ssi_mod);
int shift = (id % 4) * 8;
u32 mask = 0xFF << shift;
rsnd_mod_confirm_ssi(ssi_mod);
val = val << shift;
if (id == 8)
return;
switch (id / 4) {
case 0:
rsnd_mod_bset(adg_mod, AUDIO_CLK_SEL0, mask, val);
break;
case 1:
rsnd_mod_bset(adg_mod, AUDIO_CLK_SEL1, mask, val);
break;
case 2:
rsnd_mod_bset(adg_mod, AUDIO_CLK_SEL2, mask, val);
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
if (rate == adg->rbga_rate_for_441khz) {
data = 0x10;
goto found_clock;
}
if (rate == adg->rbgb_rate_for_48khz) {
data = 0x20;
goto found_clock;
}
return -EIO;
found_clock:
rsnd_adg_set_ssi_clk(mod, data);
dev_dbg(dev, "ADG: %s[%d] selects 0x%x for %d\n",
rsnd_mod_name(mod), rsnd_mod_id(mod),
data, rate);
return 0;
}
static void rsnd_adg_get_clkin(struct rsnd_priv *priv,
struct rsnd_adg *adg)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct clk *clk;
static const char * const clk_name[] = {
[CLKA] = "clk_a",
[CLKB] = "clk_b",
[CLKC] = "clk_c",
[CLKI] = "clk_i",
};
int i;
for (i = 0; i < CLKMAX; i++) {
clk = devm_clk_get(dev, clk_name[i]);
adg->clk[i] = IS_ERR(clk) ? NULL : clk;
}
for_each_rsnd_clk(clk, adg, i)
dev_dbg(dev, "clk %d : %p : %ld\n", i, clk, clk_get_rate(clk));
}
static void rsnd_adg_get_clkout(struct rsnd_priv *priv,
struct rsnd_adg *adg)
{
struct clk *clk;
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
struct device *dev = rsnd_priv_to_dev(priv);
struct device_node *np = dev->of_node;
u32 ckr, rbgx, rbga, rbgb;
u32 rate, req_rate, div;
uint32_t count = 0;
unsigned long req_48kHz_rate, req_441kHz_rate;
int i;
const char *parent_clk_name = NULL;
static const char * const clkout_name[] = {
[CLKOUT] = "audio_clkout",
[CLKOUT1] = "audio_clkout1",
[CLKOUT2] = "audio_clkout2",
[CLKOUT3] = "audio_clkout3",
};
int brg_table[] = {
[CLKA] = 0x0,
[CLKB] = 0x1,
[CLKC] = 0x4,
[CLKI] = 0x2,
};
of_property_read_u32(np, "#clock-cells", &count);
of_property_read_u32(np, "clock-frequency", &req_rate);
req_48kHz_rate = 0;
req_441kHz_rate = 0;
if (0 == (req_rate % 44100))
req_441kHz_rate = req_rate;
if (0 == (req_rate % 48000))
req_48kHz_rate = req_rate;
ckr = 0;
rbga = 2;
rbgb = 2;
adg->rbga_rate_for_441khz = 0;
adg->rbgb_rate_for_48khz = 0;
for_each_rsnd_clk(clk, adg, i) {
rate = clk_get_rate(clk);
if (0 == rate)
continue;
if (!adg->rbga_rate_for_441khz && (0 == rate % 44100)) {
div = 6;
if (req_441kHz_rate)
div = rate / req_441kHz_rate;
rbgx = rsnd_adg_calculate_rbgx(div);
if (BRRx_MASK(rbgx) == rbgx) {
rbga = rbgx;
adg->rbga_rate_for_441khz = rate / div;
ckr |= brg_table[i] << 20;
if (req_441kHz_rate)
parent_clk_name = __clk_get_name(clk);
}
}
if (!adg->rbgb_rate_for_48khz && (0 == rate % 48000)) {
div = 6;
if (req_48kHz_rate)
div = rate / req_48kHz_rate;
rbgx = rsnd_adg_calculate_rbgx(div);
if (BRRx_MASK(rbgx) == rbgx) {
rbgb = rbgx;
adg->rbgb_rate_for_48khz = rate / div;
ckr |= brg_table[i] << 16;
if (req_48kHz_rate) {
parent_clk_name = __clk_get_name(clk);
ckr |= 0x80000000;
}
}
}
}
if (!count) {
clk = clk_register_fixed_rate(dev, clkout_name[CLKOUT],
parent_clk_name,
(parent_clk_name) ?
0 : CLK_IS_ROOT, req_rate);
if (!IS_ERR(clk)) {
adg->clkout[CLKOUT] = clk;
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
}
else {
for (i = 0; i < CLKOUTMAX; i++) {
clk = clk_register_fixed_rate(dev, clkout_name[i],
parent_clk_name,
(parent_clk_name) ?
0 : CLK_IS_ROOT,
req_rate);
if (!IS_ERR(clk)) {
adg->onecell.clks = adg->clkout;
adg->onecell.clk_num = CLKOUTMAX;
adg->clkout[i] = clk;
of_clk_add_provider(np, of_clk_src_onecell_get,
&adg->onecell);
}
}
}
rsnd_mod_bset(adg_mod, SSICKR, 0x00FF0000, ckr);
rsnd_mod_write(adg_mod, BRRA, rbga);
rsnd_mod_write(adg_mod, BRRB, rbgb);
for_each_rsnd_clkout(clk, adg, i)
dev_dbg(dev, "clkout %d : %p : %ld\n", i, clk, clk_get_rate(clk));
dev_dbg(dev, "SSICKR = 0x%08x, BRRA/BRRB = 0x%x/0x%x\n",
ckr, rbga, rbgb);
}
int rsnd_adg_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct rsnd_adg *adg;
struct device *dev = rsnd_priv_to_dev(priv);
adg = devm_kzalloc(dev, sizeof(*adg), GFP_KERNEL);
if (!adg) {
dev_err(dev, "ADG allocate failed\n");
return -ENOMEM;
}
adg->mod.ops = &adg_ops;
adg->mod.priv = priv;
rsnd_adg_get_clkin(priv, adg);
rsnd_adg_get_clkout(priv, adg);
priv->adg = adg;
return 0;
}
