static void rsnd_src_activation(struct rsnd_mod *mod)
{
rsnd_mod_write(mod, SRC_SWRSR, 0);
rsnd_mod_write(mod, SRC_SWRSR, 1);
}
static void rsnd_src_halt(struct rsnd_mod *mod)
{
rsnd_mod_write(mod, SRC_SRCIR, 1);
rsnd_mod_write(mod, SRC_SWRSR, 0);
}
static struct dma_chan *rsnd_src_dma_req(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
int is_play = rsnd_io_is_play(io);
return rsnd_dma_request_channel(rsnd_src_of_node(priv),
mod,
is_play ? "rx" : "tx");
}
static u32 rsnd_src_convert_rate(struct rsnd_dai_stream *io,
struct rsnd_src *src)
{
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
u32 convert_rate;
if (!runtime)
return 0;
if (!rsnd_enable_sync_convert(src))
return src->convert_rate;
convert_rate = src->sync.val;
if (!convert_rate)
convert_rate = src->convert_rate;
if (!convert_rate)
convert_rate = runtime->rate;
return convert_rate;
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
rate = rsnd_src_convert_rate(io, src);
}
if (!rate)
rate = runtime->rate;
return rate;
}
static int rsnd_src_hw_params(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *fe_params)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
struct snd_soc_pcm_runtime *fe = substream->private_data;
if (fe->dai_link->dynamic) {
int stream = substream->stream;
struct snd_soc_dpcm *dpcm;
struct snd_pcm_hw_params *be_params;
list_for_each_entry(dpcm, &fe->dpcm[stream].be_clients, list_be) {
be_params = &dpcm->hw_params;
if (params_rate(fe_params) != params_rate(be_params))
src->convert_rate = params_rate(be_params);
}
}
return 0;
}
static void rsnd_src_set_convert_rate(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 convert_rate = rsnd_src_convert_rate(io, src);
u32 ifscr, fsrate, adinr;
u32 cr, route;
u32 bsdsr, bsisr;
uint ratio;
if (!runtime)
return;
if (!convert_rate)
ratio = 0;
else if (convert_rate > runtime->rate)
ratio = 100 * convert_rate / runtime->rate;
else
ratio = 100 * runtime->rate / convert_rate;
if (ratio > 600) {
dev_err(dev, "FSO/FSI ratio error\n");
return;
}
adinr = rsnd_get_adinr_bit(mod, io) |
rsnd_get_adinr_chan(mod, io);
ifscr = 0;
fsrate = 0;
if (convert_rate) {
ifscr = 1;
fsrate = 0x0400000 / convert_rate * runtime->rate;
}
cr = 0x00011110;
route = 0x0;
if (convert_rate) {
route = 0x1;
if (rsnd_enable_sync_convert(src)) {
cr |= 0x1;
route |= rsnd_io_is_play(io) ?
(0x1 << 24) : (0x1 << 25);
}
}
switch (rsnd_mod_id(mod)) {
case 5:
case 6:
case 7:
case 8:
bsdsr = 0x02400000;
bsisr = 0x00100060;
break;
default:
bsdsr = 0x01800000;
bsisr = 0x00100060 ;
break;
}
rsnd_mod_write(mod, SRC_SRCIR, 1);
rsnd_mod_write(mod, SRC_ADINR, adinr);
rsnd_mod_write(mod, SRC_IFSCR, ifscr);
rsnd_mod_write(mod, SRC_IFSVR, fsrate);
rsnd_mod_write(mod, SRC_SRCCR, cr);
rsnd_mod_write(mod, SRC_BSDSR, bsdsr);
rsnd_mod_write(mod, SRC_BSISR, bsisr);
rsnd_mod_write(mod, SRC_SRCIR, 0);
rsnd_mod_write(mod, SRC_ROUTE_MODE0, route);
rsnd_mod_write(mod, SRC_I_BUSIF_MODE, 1);
rsnd_mod_write(mod, SRC_O_BUSIF_MODE, 1);
rsnd_mod_write(mod, SRC_BUSIF_DALIGN, rsnd_get_dalign(mod, io));
if (convert_rate)
rsnd_adg_set_convert_clk_gen2(mod, io,
runtime->rate,
convert_rate);
else
rsnd_adg_set_convert_timing_gen2(mod, io);
}
static void rsnd_src_irq_ctrol(struct rsnd_mod *mod, int enable)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 sys_int_val, int_val, sys_int_mask;
int irq = src->irq;
int id = rsnd_mod_id(mod);
sys_int_val =
sys_int_mask = OUF_SRC(id);
int_val = 0x3300;
if ((irq <= 0) || !enable) {
sys_int_val = 0;
int_val = 0;
}
if (rsnd_enable_sync_convert(src))
sys_int_val = sys_int_val & 0xffff;
rsnd_mod_write(mod, SRC_INT_ENABLE0, int_val);
rsnd_mod_bset(mod, SCU_SYS_INT_EN0, sys_int_mask, sys_int_val);
rsnd_mod_bset(mod, SCU_SYS_INT_EN1, sys_int_mask, sys_int_val);
}
static void rsnd_src_status_clear(struct rsnd_mod *mod)
{
u32 val = OUF_SRC(rsnd_mod_id(mod));
rsnd_mod_bset(mod, SCU_SYS_STATUS0, val, val);
rsnd_mod_bset(mod, SCU_SYS_STATUS1, val, val);
}
static bool rsnd_src_record_error(struct rsnd_mod *mod)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 val0, val1;
bool ret = false;
val0 = val1 = OUF_SRC(rsnd_mod_id(mod));
if (rsnd_enable_sync_convert(src))
val0 = val0 & 0xffff;
if ((rsnd_mod_read(mod, SCU_SYS_STATUS0) & val0) ||
(rsnd_mod_read(mod, SCU_SYS_STATUS1) & val1)) {
struct rsnd_src *src = rsnd_mod_to_src(mod);
src->err++;
ret = true;
}
return ret;
}
static int rsnd_src_start(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
u32 val;
val = (rsnd_io_to_mod_dvc(io) && !rsnd_enable_sync_convert(src)) ?
0x01 : 0x11;
rsnd_mod_write(mod, SRC_CTRL, val);
return 0;
}
static int rsnd_src_stop(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
rsnd_mod_write(mod, SRC_CTRL, 0x01);
return 0;
}
static int rsnd_src_init(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
rsnd_mod_power_on(mod);
rsnd_src_activation(mod);
rsnd_src_set_convert_rate(io, mod);
rsnd_src_status_clear(mod);
rsnd_src_irq_enable(mod);
src->err = 0;
src->sync.val = 0;
return 0;
}
static int rsnd_src_quit(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
struct device *dev = rsnd_priv_to_dev(priv);
rsnd_src_irq_disable(mod);
rsnd_mod_write(mod, SRC_CTRL, 0);
rsnd_src_halt(mod);
rsnd_mod_power_off(mod);
if (src->err)
dev_warn(dev, "%s[%d] under/over flow err = %d\n",
rsnd_mod_name(mod), rsnd_mod_id(mod), src->err);
src->convert_rate = 0;
src->sync.val = 0;
return 0;
}
static void __rsnd_src_interrupt(struct rsnd_mod *mod,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_src *src = rsnd_mod_to_src(mod);
struct device *dev = rsnd_priv_to_dev(priv);
spin_lock(&priv->lock);
if (!rsnd_io_is_working(io))
goto rsnd_src_interrupt_out;
if (rsnd_src_record_error(mod)) {
dev_dbg(dev, "%s[%d] restart\n",
rsnd_mod_name(mod), rsnd_mod_id(mod));
rsnd_src_stop(mod, io, priv);
rsnd_src_start(mod, io, priv);
}
if (src->err > 1024) {
rsnd_src_irq_disable(mod);
dev_warn(dev, "no more %s[%d] restart\n",
rsnd_mod_name(mod), rsnd_mod_id(mod));
}
rsnd_src_status_clear(mod);
rsnd_src_interrupt_out:
spin_unlock(&priv->lock);
}
static irqreturn_t rsnd_src_interrupt(int irq, void *data)
{
struct rsnd_mod *mod = data;
rsnd_mod_interrupt(mod, __rsnd_src_interrupt);
return IRQ_HANDLED;
}
static int rsnd_src_probe_(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_src *src = rsnd_mod_to_src(mod);
struct device *dev = rsnd_priv_to_dev(priv);
int irq = src->irq;
int ret;
if (irq > 0) {
ret = devm_request_irq(dev, irq,
rsnd_src_interrupt,
IRQF_SHARED,
dev_name(dev), mod);
if (ret)
return ret;
}
src->dma = rsnd_dma_attach(io, mod, 0);
if (IS_ERR(src->dma))
return PTR_ERR(src->dma);
return ret;
}
static int rsnd_src_pcm_new(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct snd_soc_pcm_runtime *rtd)
{
struct rsnd_dai *rdai = rsnd_io_to_rdai(io);
struct rsnd_mod *dvc = rsnd_io_to_mod_dvc(io);
struct rsnd_src *src = rsnd_mod_to_src(mod);
int ret;
if (!rsnd_rdai_is_clk_master(rdai))
return 0;
if (dvc && !rsnd_io_is_play(io))
return 0;
ret = rsnd_kctrl_new_s(mod, io, rtd,
rsnd_io_is_play(io) ?
"SRC Out Rate Switch" :
"SRC In Rate Switch",
rsnd_src_set_convert_rate,
&src->sen, 1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_s(mod, io, rtd,
rsnd_io_is_play(io) ?
"SRC Out Rate" :
"SRC In Rate",
rsnd_src_set_convert_rate,
&src->sync, 192000);
return ret;
}
struct rsnd_mod *rsnd_src_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_src_nr(priv)))
id = 0;
return rsnd_mod_get(rsnd_src_get(priv, id));
}
int rsnd_src_probe(struct rsnd_priv *priv)
{
struct device_node *node;
struct device_node *np;
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_src *src;
struct clk *clk;
char name[RSND_SRC_NAME_SIZE];
int i, nr, ret;
if (rsnd_is_gen1(priv))
return 0;
node = rsnd_src_of_node(priv);
if (!node)
return 0;
nr = of_get_child_count(node);
if (!nr) {
ret = -EINVAL;
goto rsnd_src_probe_done;
}
src = devm_kzalloc(dev, sizeof(*src) * nr, GFP_KERNEL);
if (!src) {
ret = -ENOMEM;
goto rsnd_src_probe_done;
}
priv->src_nr = nr;
priv->src = src;
i = 0;
for_each_child_of_node(node, np) {
src = rsnd_src_get(priv, i);
snprintf(name, RSND_SRC_NAME_SIZE, "%s.%d",
SRC_NAME, i);
src->irq = irq_of_parse_and_map(np, 0);
if (!src->irq) {
ret = -EINVAL;
goto rsnd_src_probe_done;
}
clk = devm_clk_get(dev, name);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
goto rsnd_src_probe_done;
}
ret = rsnd_mod_init(priv, rsnd_mod_get(src),
&rsnd_src_ops, clk, RSND_MOD_SRC, i);
if (ret)
goto rsnd_src_probe_done;
i++;
}
ret = 0;
rsnd_src_probe_done:
of_node_put(node);
return ret;
}
void rsnd_src_remove(struct rsnd_priv *priv)
{
struct rsnd_src *src;
int i;
for_each_rsnd_src(src, priv, i) {
rsnd_mod_quit(rsnd_mod_get(src));
}
}
