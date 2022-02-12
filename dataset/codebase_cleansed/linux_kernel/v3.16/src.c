int rsnd_src_ssi_mode_init(struct rsnd_mod *ssi_mod,
struct rsnd_dai *rdai)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(ssi_mod);
struct rsnd_mod *src_mod = rsnd_io_to_mod_src(io);
int ssi_id = rsnd_mod_id(ssi_mod);
rsnd_mod_bset(ssi_mod, SSI_MODE0, (1 << ssi_id),
src_mod ? 0 : (1 << ssi_id));
if (rsnd_ssi_is_pin_sharing(ssi_mod)) {
int shift = -1;
switch (ssi_id) {
case 1:
shift = 0;
break;
case 2:
shift = 2;
break;
case 4:
shift = 16;
break;
}
if (shift >= 0)
rsnd_mod_bset(ssi_mod, SSI_MODE1,
0x3 << shift,
rsnd_dai_is_clk_master(rdai) ?
0x2 << shift : 0x1 << shift);
}
return 0;
}
int rsnd_src_enable_ssi_irq(struct rsnd_mod *ssi_mod,
struct rsnd_dai *rdai)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(ssi_mod);
if (rsnd_is_gen2(priv))
rsnd_mod_write(ssi_mod, INT_ENABLE, 0x0f000000);
return 0;
}
unsigned int rsnd_src_get_ssi_rate(struct rsnd_priv *priv,
struct rsnd_dai_stream *io,
struct snd_pcm_runtime *runtime)
{
struct rsnd_mod *src_mod = rsnd_io_to_mod_src(io);
struct rsnd_src *src;
unsigned int rate = 0;
if (src_mod) {
src = rsnd_mod_to_src(src_mod);
rate = rsnd_src_convert_rate(src);
}
if (!rate)
rate = runtime->rate;
return rate;
}
static int rsnd_src_set_convert_rate(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 convert_rate = rsnd_src_convert_rate(src);
u32 fsrate = 0;
if (convert_rate)
fsrate = 0x0400000 / convert_rate * runtime->rate;
rsnd_mod_write(mod, SRC_SWRSR, 0);
rsnd_mod_write(mod, SRC_SWRSR, 1);
rsnd_mod_write(mod, SRC_SRCIR, 1);
rsnd_mod_write(mod, SRC_ADINR, rsnd_get_adinr(mod));
if (fsrate) {
rsnd_mod_write(mod, SRC_IFSCR, 1);
rsnd_mod_write(mod, SRC_IFSVR, fsrate);
}
rsnd_mod_write(mod, SRC_BUSIF_MODE, 1);
return 0;
}
static int rsnd_src_init(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
clk_prepare_enable(src->clk);
return 0;
}
static int rsnd_src_quit(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
clk_disable_unprepare(src->clk);
return 0;
}
static int rsnd_src_start(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
rsnd_mod_write(mod, SRC_SRCIR, 0);
if (rsnd_src_convert_rate(src))
rsnd_mod_write(mod, SRC_ROUTE_MODE0, 1);
return 0;
}
static int rsnd_src_stop(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
if (rsnd_src_convert_rate(src))
rsnd_mod_write(mod, SRC_ROUTE_MODE0, 0);
return 0;
}
static int rsnd_src_set_route_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct src_route_config {
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
u32 mask;
u32 val;
int id;
id = rsnd_mod_id(mod);
if (id < 0 || id >= ARRAY_SIZE(routes))
return -EIO;
val = rsnd_dai_is_play(rdai, io) ? 0x1 : 0x2;
val = val << routes[id].shift;
mask = routes[id].mask << routes[id].shift;
rsnd_mod_bset(mod, SRC_ROUTE_SEL, mask, val);
return 0;
}
static int rsnd_src_set_convert_timing_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_src *src = rsnd_mod_to_src(mod);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
u32 convert_rate = rsnd_src_convert_rate(src);
u32 mask;
u32 val;
int shift;
int id = rsnd_mod_id(mod);
int ret;
shift = (id % 4) * 8;
mask = 0x1F << shift;
ret = 0;
if (convert_rate) {
val = 0;
ret = rsnd_adg_set_convert_clk_gen1(priv, mod,
runtime->rate,
convert_rate);
} else if (8 == id) {
val = id << shift;
} else {
val = (id + 1) << shift;
}
if (ret < 0)
return ret;
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
static int rsnd_src_set_convert_rate_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
int ret;
ret = rsnd_src_set_convert_rate(mod, rdai);
if (ret < 0)
return ret;
rsnd_mod_write(mod, SRC_SRCCR, 0x00010110);
rsnd_mod_write(mod, SRC_MNFSR,
rsnd_mod_read(mod, SRC_IFSVR) / 100 * 98);
return 0;
}
static int rsnd_src_probe_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
dev_dbg(dev, "%s (Gen1) is probed\n", rsnd_mod_name(mod));
return 0;
}
static int rsnd_src_init_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
int ret;
ret = rsnd_src_init(mod, rdai);
if (ret < 0)
return ret;
ret = rsnd_src_set_route_gen1(mod, rdai);
if (ret < 0)
return ret;
ret = rsnd_src_set_convert_rate_gen1(mod, rdai);
if (ret < 0)
return ret;
ret = rsnd_src_set_convert_timing_gen1(mod, rdai);
if (ret < 0)
return ret;
return 0;
}
static int rsnd_src_start_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
int id = rsnd_mod_id(mod);
rsnd_mod_bset(mod, SRC_ROUTE_CTRL, (1 << id), (1 << id));
return rsnd_src_start(mod, rdai);
}
static int rsnd_src_stop_gen1(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
int id = rsnd_mod_id(mod);
rsnd_mod_bset(mod, SRC_ROUTE_CTRL, (1 << id), 0);
return rsnd_src_stop(mod, rdai);
}
static int rsnd_src_set_convert_rate_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
int ret;
ret = rsnd_src_set_convert_rate(mod, rdai);
if (ret < 0)
return ret;
rsnd_mod_write(mod, SSI_BUSIF_ADINR, rsnd_get_adinr(mod));
rsnd_mod_write(mod, SSI_BUSIF_MODE, 1);
rsnd_mod_write(mod, SRC_SRCCR, 0x00011110);
rsnd_mod_write(mod, SRC_BSDSR, 0x01800000);
rsnd_mod_write(mod, SRC_BSISR, 0x00100060);
return 0;
}
static int rsnd_src_set_convert_timing_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 convert_rate = rsnd_src_convert_rate(src);
int ret;
if (convert_rate)
ret = rsnd_adg_set_convert_clk_gen2(mod, rdai, io,
runtime->rate,
convert_rate);
else
ret = rsnd_adg_set_convert_timing_gen2(mod, rdai, io);
return ret;
}
static int rsnd_src_probe_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_src *src = rsnd_mod_to_src(mod);
struct device *dev = rsnd_priv_to_dev(priv);
int ret;
ret = rsnd_dma_init(priv,
rsnd_mod_to_dma(mod),
rsnd_info_is_playback(priv, src),
src->info->dma_id);
if (ret < 0)
dev_err(dev, "SRC DMA failed\n");
dev_dbg(dev, "%s (Gen2) is probed\n", rsnd_mod_name(mod));
return ret;
}
static int rsnd_src_remove_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
rsnd_dma_quit(rsnd_mod_to_priv(mod), rsnd_mod_to_dma(mod));
return 0;
}
static int rsnd_src_init_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
int ret;
ret = rsnd_src_init(mod, rdai);
if (ret < 0)
return ret;
ret = rsnd_src_set_convert_rate_gen2(mod, rdai);
if (ret < 0)
return ret;
ret = rsnd_src_set_convert_timing_gen2(mod, rdai);
if (ret < 0)
return ret;
return 0;
}
static int rsnd_src_start_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 val = rsnd_io_to_mod_dvc(io) ? 0x01 : 0x11;
rsnd_dma_start(rsnd_mod_to_dma(&src->mod));
rsnd_mod_write(mod, SSI_CTRL, 0x1);
rsnd_mod_write(mod, SRC_CTRL, val);
return rsnd_src_start(mod, rdai);
}
static int rsnd_src_stop_gen2(struct rsnd_mod *mod,
struct rsnd_dai *rdai)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
rsnd_mod_write(mod, SSI_CTRL, 0);
rsnd_mod_write(mod, SRC_CTRL, 0);
rsnd_dma_stop(rsnd_mod_to_dma(&src->mod));
return rsnd_src_stop(mod, rdai);
}
struct rsnd_mod *rsnd_src_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_src_nr(priv)))
id = 0;
return &((struct rsnd_src *)(priv->src) + id)->mod;
}
static void rsnd_of_parse_src(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct device_node *src_node;
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct rsnd_src_platform_info *src_info;
struct device *dev = &pdev->dev;
int nr;
if (!of_data)
return;
src_node = of_get_child_by_name(dev->of_node, "rcar_sound,src");
if (!src_node)
return;
nr = of_get_child_count(src_node);
if (!nr)
goto rsnd_of_parse_src_end;
src_info = devm_kzalloc(dev,
sizeof(struct rsnd_src_platform_info) * nr,
GFP_KERNEL);
if (!src_info) {
dev_err(dev, "src info allocation error\n");
goto rsnd_of_parse_src_end;
}
info->src_info = src_info;
info->src_info_nr = nr;
rsnd_of_parse_src_end:
of_node_put(src_node);
}
int rsnd_src_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_src *src;
struct rsnd_mod_ops *ops;
struct clk *clk;
char name[RSND_SRC_NAME_SIZE];
int i, nr;
ops = NULL;
if (rsnd_is_gen1(priv))
ops = &rsnd_src_gen1_ops;
if (rsnd_is_gen2(priv))
ops = &rsnd_src_gen2_ops;
if (!ops) {
dev_err(dev, "unknown Generation\n");
return -EIO;
}
rsnd_of_parse_src(pdev, of_data, priv);
nr = info->src_info_nr;
if (!nr)
return 0;
src = devm_kzalloc(dev, sizeof(*src) * nr, GFP_KERNEL);
if (!src) {
dev_err(dev, "SRC allocate failed\n");
return -ENOMEM;
}
priv->src_nr = nr;
priv->src = src;
for_each_rsnd_src(src, priv, i) {
snprintf(name, RSND_SRC_NAME_SIZE, "%s.%d",
SRC_NAME, i);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk))
return PTR_ERR(clk);
src->info = &info->src_info[i];
src->clk = clk;
rsnd_mod_init(priv, &src->mod, ops, RSND_MOD_SRC, i);
dev_dbg(dev, "SRC%d probed\n", i);
}
return 0;
}
