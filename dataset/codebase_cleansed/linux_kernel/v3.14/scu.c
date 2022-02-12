static int rsnd_src_set_route_if_gen1(struct rsnd_priv *priv,
struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct scu_route_config {
u32 mask;
int shift;
} routes[] = {
{ 0xF, 0, },
{ 0xF, 4, },
{ 0xF, 8, },
{ 0x7, 12, },
{ 0x7, 16, },
{ 0x7, 20, },
{ 0x7, 24, },
{ 0x3, 28, },
{ 0x3, 30, },
};
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
u32 mask;
u32 val;
int shift;
int id;
if (!rsnd_is_gen1(priv))
return 0;
id = rsnd_mod_id(mod);
if (id < 0 || id >= ARRAY_SIZE(routes))
return -EIO;
val = rsnd_dai_is_play(rdai, io) ? 0x1 : 0x2;
val = val << routes[id].shift;
mask = routes[id].mask << routes[id].shift;
rsnd_mod_bset(mod, SRC_ROUTE_SEL, mask, val);
shift = (id % 4) * 8;
mask = 0x1F << shift;
if (rsnd_scu_convert_rate(scu))
val = 0;
else if (8 == id)
val = id << shift;
else
val = (id + 1) << shift;
switch (id / 4) {
case 0:
rsnd_mod_bset(mod, SRC_TMG_SEL0, mask, val);
break;
case 1:
rsnd_mod_bset(mod, SRC_TMG_SEL1, mask, val);
break;
case 2:
rsnd_mod_bset(mod, SRC_TMG_SEL2, mask, val);
break;
}
return 0;
}
unsigned int rsnd_scu_get_ssi_rate(struct rsnd_priv *priv,
struct rsnd_mod *ssi_mod,
struct snd_pcm_runtime *runtime)
{
struct rsnd_scu *scu;
unsigned int rate;
scu = rsnd_mod_to_scu(rsnd_scu_mod_get(priv, rsnd_mod_id(ssi_mod)));
rate = rsnd_scu_convert_rate(scu);
if (!rate)
rate = runtime->rate;
return rate;
}
static int rsnd_scu_convert_rate_ctrl(struct rsnd_priv *priv,
struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
u32 convert_rate = rsnd_scu_convert_rate(scu);
u32 adinr = runtime->channels;
rsnd_mod_write(mod, SRC_SWRSR, 0);
rsnd_mod_write(mod, SRC_SWRSR, 1);
rsnd_mod_write(mod, SRC_SRCIR, 1);
switch (runtime->sample_bits) {
case 16:
adinr |= OTBL_16;
break;
case 32:
adinr |= OTBL_24;
break;
default:
return -EIO;
}
rsnd_mod_write(mod, SRC_ADINR, adinr);
if (convert_rate) {
u32 fsrate = 0x0400000 / convert_rate * runtime->rate;
int ret;
rsnd_mod_write(mod, SRC_IFSCR, 1);
rsnd_mod_write(mod, SRC_IFSVR, fsrate);
rsnd_mod_write(mod, SRC_SRCCR, 0x00010110);
rsnd_mod_write(mod, SRC_MNFSR, fsrate / 100 * 98);
if (rsnd_is_gen1(priv)) {
}
ret = rsnd_adg_set_convert_clk(priv, mod,
runtime->rate,
convert_rate);
if (ret < 0)
return ret;
}
rsnd_mod_write(mod, SRC_SRCIR, 0);
rsnd_mod_write(mod, BUSIF_MODE, 1);
return 0;
}
static int rsnd_scu_transfer_start(struct rsnd_priv *priv,
struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
int id = rsnd_mod_id(mod);
u32 val;
if (rsnd_is_gen1(priv)) {
val = (1 << id);
rsnd_mod_bset(mod, SRC_ROUTE_CTRL, val, val);
}
if (rsnd_scu_convert_rate(scu))
rsnd_mod_write(mod, SRC_ROUTE_MODE0, 1);
return 0;
}
static int rsnd_scu_transfer_stop(struct rsnd_priv *priv,
struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
int id = rsnd_mod_id(mod);
u32 mask;
if (rsnd_is_gen1(priv)) {
mask = (1 << id);
rsnd_mod_bset(mod, SRC_ROUTE_CTRL, mask, 0);
}
if (rsnd_scu_convert_rate(scu))
rsnd_mod_write(mod, SRC_ROUTE_MODE0, 0);
return 0;
}
bool rsnd_scu_hpbif_is_enable(struct rsnd_mod *mod)
{
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
u32 flags = rsnd_scu_mode_flags(scu);
return !!(flags & RSND_SCU_USE_HPBIF);
}
static int rsnd_scu_start(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
struct device *dev = rsnd_priv_to_dev(priv);
int ret;
if (!rsnd_scu_hpbif_is_enable(mod)) {
dev_dbg(dev, "%s%d is not used\n",
rsnd_mod_name(mod), rsnd_mod_id(mod));
return 0;
}
clk_enable(scu->clk);
ret = rsnd_src_set_route_if_gen1(priv, mod, rdai, io);
if (ret < 0)
return ret;
ret = rsnd_scu_convert_rate_ctrl(priv, mod, rdai, io);
if (ret < 0)
return ret;
ret = rsnd_scu_transfer_start(priv, mod, rdai, io);
if (ret < 0)
return ret;
dev_dbg(dev, "%s%d start\n", rsnd_mod_name(mod), rsnd_mod_id(mod));
return 0;
}
static int rsnd_scu_stop(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_scu *scu = rsnd_mod_to_scu(mod);
if (!rsnd_scu_hpbif_is_enable(mod))
return 0;
rsnd_scu_transfer_stop(priv, mod, rdai, io);
clk_disable(scu->clk);
return 0;
}
struct rsnd_mod *rsnd_scu_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_scu_nr(priv)))
id = 0;
return &((struct rsnd_scu *)(priv->scu) + id)->mod;
}
int rsnd_scu_probe(struct platform_device *pdev,
struct rcar_snd_info *info,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_scu *scu;
struct clk *clk;
char name[RSND_SCU_NAME_SIZE];
int i, nr;
nr = info->scu_info_nr;
scu = devm_kzalloc(dev, sizeof(*scu) * nr, GFP_KERNEL);
if (!scu) {
dev_err(dev, "SCU allocate failed\n");
return -ENOMEM;
}
priv->scu_nr = nr;
priv->scu = scu;
for_each_rsnd_scu(scu, priv, i) {
snprintf(name, RSND_SCU_NAME_SIZE, "scu.%d", i);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk))
return PTR_ERR(clk);
rsnd_mod_init(priv, &scu->mod,
&rsnd_scu_ops, i);
scu->info = &info->scu_info[i];
scu->clk = clk;
dev_dbg(dev, "SCU%d probed\n", i);
}
dev_dbg(dev, "scu probed\n");
return 0;
}
void rsnd_scu_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
}
