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
struct rsnd_mod *ssi_mod = rsnd_io_to_mod_ssi(io);
int id = rsnd_mod_id(ssi_mod);
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
static void __rsnd_adg_get_timesel_ratio(struct rsnd_priv *priv,
struct rsnd_dai_stream *io,
unsigned int target_rate,
unsigned int *target_val,
unsigned int *target_en)
{
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
int idx, sel, div, step;
unsigned int val, en;
unsigned int min, diff;
unsigned int sel_rate[] = {
clk_get_rate(adg->clk[CLKA]),
clk_get_rate(adg->clk[CLKB]),
clk_get_rate(adg->clk[CLKC]),
adg->rbga_rate_for_441khz,
adg->rbgb_rate_for_48khz,
};
min = ~0;
val = 0;
en = 0;
for (sel = 0; sel < ARRAY_SIZE(sel_rate); sel++) {
idx = 0;
step = 2;
if (!sel_rate[sel])
continue;
for (div = 2; div <= 98304; div += step) {
diff = abs(target_rate - sel_rate[sel] / div);
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
return;
}
*target_val = val;
if (target_en)
*target_en = en;
}
static void rsnd_adg_get_timesel_ratio(struct rsnd_priv *priv,
struct rsnd_dai_stream *io,
unsigned int in_rate,
unsigned int out_rate,
u32 *in, u32 *out, u32 *en)
{
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
unsigned int target_rate;
u32 *target_val;
u32 _in;
u32 _out;
u32 _en;
_in =
_out = rsnd_adg_ssi_ws_timing_gen2(io);
target_rate = 0;
target_val = NULL;
_en = 0;
if (runtime->rate != in_rate) {
target_rate = out_rate;
target_val = &_out;
} else if (runtime->rate != out_rate) {
target_rate = in_rate;
target_val = &_in;
}
if (target_rate)
__rsnd_adg_get_timesel_ratio(priv, io,
target_rate,
target_val, &_en);
if (in)
*in = _in;
if (out)
*out = _out;
if (en)
*en = _en;
}
int rsnd_adg_set_cmd_timsel_gen2(struct rsnd_mod *cmd_mod,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(cmd_mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
int id = rsnd_mod_id(cmd_mod);
int shift = (id % 2) ? 16 : 0;
u32 mask, val;
rsnd_adg_get_timesel_ratio(priv, io,
rsnd_src_get_in_rate(priv, io),
rsnd_src_get_out_rate(priv, io),
NULL, &val, NULL);
val = val << shift;
mask = 0xffff << shift;
rsnd_mod_bset(adg_mod, CMDOUT_TIMSEL, mask, val);
return 0;
}
int rsnd_adg_set_src_timesel_gen2(struct rsnd_mod *src_mod,
struct rsnd_dai_stream *io,
unsigned int in_rate,
unsigned int out_rate)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(src_mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
u32 in, out;
u32 mask, en;
int id = rsnd_mod_id(src_mod);
int shift = (id % 2) ? 16 : 0;
rsnd_mod_confirm_src(src_mod);
rsnd_adg_get_timesel_ratio(priv, io,
in_rate, out_rate,
&in, &out, &en);
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
if (en)
rsnd_mod_bset(adg_mod, DIV_EN, en, en);
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
int rsnd_adg_clk_query(struct rsnd_priv *priv, unsigned int rate)
{
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct clk *clk;
int i;
int sel_table[] = {
[CLKA] = 0x1,
[CLKB] = 0x2,
[CLKC] = 0x3,
[CLKI] = 0x0,
};
dev_dbg(dev, "request clock = %d\n", rate);
for_each_rsnd_clk(clk, adg, i) {
if (rate == clk_get_rate(clk))
return sel_table[i];
}
if (rate == adg->rbga_rate_for_441khz)
return 0x10;
if (rate == adg->rbgb_rate_for_48khz)
return 0x20;
return -EIO;
}
int rsnd_adg_ssi_clk_stop(struct rsnd_mod *ssi_mod)
{
rsnd_adg_set_ssi_clk(ssi_mod, 0);
return 0;
}
int rsnd_adg_ssi_clk_try_start(struct rsnd_mod *ssi_mod, unsigned int rate)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(ssi_mod);
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_mod *adg_mod = rsnd_mod_get(adg);
int data;
u32 ckr = 0;
data = rsnd_adg_clk_query(priv, rate);
if (data < 0)
return data;
rsnd_adg_set_ssi_clk(ssi_mod, data);
if (adg_mode_flags(adg) & LRCLK_ASYNC) {
if (adg_mode_flags(adg) & AUDIO_OUT_48)
ckr = 0x80000000;
} else {
if (0 == (rate % 8000))
ckr = 0x80000000;
}
rsnd_mod_bset(adg_mod, BRGCKR, 0x80FF0000, adg->ckr | ckr);
rsnd_mod_write(adg_mod, BRRA, adg->rbga);
rsnd_mod_write(adg_mod, BRRB, adg->rbgb);
dev_dbg(dev, "ADG: %s[%d] selects 0x%x for %d\n",
rsnd_mod_name(ssi_mod), rsnd_mod_id(ssi_mod),
data, rate);
return 0;
}
void rsnd_adg_clk_control(struct rsnd_priv *priv, int enable)
{
struct rsnd_adg *adg = rsnd_priv_to_adg(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct clk *clk;
int i, ret;
for_each_rsnd_clk(clk, adg, i) {
ret = 0;
if (enable)
ret = clk_prepare_enable(clk);
else
clk_disable_unprepare(clk);
if (ret < 0)
dev_warn(dev, "can't use clk %d\n", i);
}
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
struct device *dev = rsnd_priv_to_dev(priv);
struct device_node *np = dev->of_node;
struct property *prop;
u32 ckr, rbgx, rbga, rbgb;
u32 rate, div;
#define REQ_SIZE 2
u32 req_rate[REQ_SIZE] = {};
uint32_t count = 0;
unsigned long req_48kHz_rate, req_441kHz_rate;
int i, req_size;
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
ckr = 0;
rbga = 2;
rbgb = 2;
prop = of_find_property(np, "clock-frequency", NULL);
if (!prop)
goto rsnd_adg_get_clkout_end;
req_size = prop->length / sizeof(u32);
of_property_read_u32_array(np, "clock-frequency", req_rate, req_size);
req_48kHz_rate = 0;
req_441kHz_rate = 0;
for (i = 0; i < req_size; i++) {
if (0 == (req_rate[i] % 44100))
req_441kHz_rate = req_rate[i];
if (0 == (req_rate[i] % 48000))
req_48kHz_rate = req_rate[i];
}
if (req_rate[0] % 48000 == 0)
adg->flags = AUDIO_OUT_48;
if (of_get_property(np, "clkout-lr-asynchronous", NULL))
adg->flags = LRCLK_ASYNC;
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
if (req_441kHz_rate &&
!(adg_mode_flags(adg) & AUDIO_OUT_48))
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
if (req_48kHz_rate &&
(adg_mode_flags(adg) & AUDIO_OUT_48))
parent_clk_name = __clk_get_name(clk);
}
}
}
of_property_read_u32(np, "#clock-cells", &count);
if (!count) {
clk = clk_register_fixed_rate(dev, clkout_name[CLKOUT],
parent_clk_name, 0, req_rate[0]);
if (!IS_ERR(clk)) {
adg->clkout[CLKOUT] = clk;
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
}
else {
for (i = 0; i < CLKOUTMAX; i++) {
clk = clk_register_fixed_rate(dev, clkout_name[i],
parent_clk_name, 0,
req_rate[0]);
if (!IS_ERR(clk))
adg->clkout[i] = clk;
}
adg->onecell.clks = adg->clkout;
adg->onecell.clk_num = CLKOUTMAX;
of_clk_add_provider(np, of_clk_src_onecell_get,
&adg->onecell);
}
rsnd_adg_get_clkout_end:
adg->ckr = ckr;
adg->rbga = rbga;
adg->rbgb = rbgb;
for_each_rsnd_clkout(clk, adg, i)
dev_dbg(dev, "clkout %d : %p : %ld\n", i, clk, clk_get_rate(clk));
dev_dbg(dev, "BRGCKR = 0x%08x, BRRA/BRRB = 0x%x/0x%x\n",
ckr, rbga, rbgb);
}
int rsnd_adg_probe(struct rsnd_priv *priv)
{
struct rsnd_adg *adg;
struct device *dev = rsnd_priv_to_dev(priv);
int ret;
adg = devm_kzalloc(dev, sizeof(*adg), GFP_KERNEL);
if (!adg) {
dev_err(dev, "ADG allocate failed\n");
return -ENOMEM;
}
ret = rsnd_mod_init(priv, &adg->mod, &adg_ops,
NULL, NULL, 0, 0);
if (ret)
return ret;
rsnd_adg_get_clkin(priv, adg);
rsnd_adg_get_clkout(priv, adg);
priv->adg = adg;
rsnd_adg_clk_enable(priv);
return 0;
}
void rsnd_adg_remove(struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct device_node *np = dev->of_node;
of_clk_del_provider(np);
rsnd_adg_clk_disable(priv);
}
