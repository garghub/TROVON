int rsnd_ssi_use_busif(struct rsnd_dai_stream *io, struct rsnd_mod *mod)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
int use_busif = 0;
if (!rsnd_ssi_is_dma_mode(mod))
return 0;
if (!(rsnd_ssi_mode_flags(ssi) & RSND_SSI_NO_BUSIF))
use_busif = 1;
if (rsnd_io_to_mod_src(io))
use_busif = 1;
return use_busif;
}
static void rsnd_ssi_status_check(struct rsnd_mod *mod,
u32 bit)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
u32 status;
int i;
for (i = 0; i < 1024; i++) {
status = rsnd_mod_read(mod, SSISR);
if (status & bit)
return;
udelay(50);
}
dev_warn(dev, "status check failed\n");
}
static int rsnd_ssi_master_clk_start(struct rsnd_ssi *ssi,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_io_to_priv(io);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
struct device *dev = rsnd_priv_to_dev(priv);
int i, j, ret;
int adg_clk_div_table[] = {
1, 6,
};
int ssi_clk_mul_table[] = {
1, 2, 4, 8, 16, 6, 12,
};
unsigned int main_rate;
unsigned int rate = rsnd_src_get_ssi_rate(priv, io, runtime);
for (i = 0; i < ARRAY_SIZE(adg_clk_div_table); i++) {
for (j = 0; j < ARRAY_SIZE(ssi_clk_mul_table); j++) {
main_rate = rate / adg_clk_div_table[i]
* 32 * 2 * ssi_clk_mul_table[j];
ret = rsnd_adg_ssi_clk_try_start(&ssi->mod, main_rate);
if (0 == ret) {
ssi->cr_clk = FORCE | SWL_32 |
SCKD | SWSD | CKDV(j);
dev_dbg(dev, "%s[%d] outputs %u Hz\n",
rsnd_mod_name(&ssi->mod),
rsnd_mod_id(&ssi->mod), rate);
return 0;
}
}
}
dev_err(dev, "unsupported clock rate\n");
return -EIO;
}
static void rsnd_ssi_master_clk_stop(struct rsnd_ssi *ssi)
{
ssi->cr_clk = 0;
rsnd_adg_ssi_clk_stop(&ssi->mod);
}
static void rsnd_ssi_hw_start(struct rsnd_ssi *ssi,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_io_to_priv(io);
struct rsnd_dai *rdai = rsnd_io_to_rdai(io);
struct device *dev = rsnd_priv_to_dev(priv);
u32 cr_mode;
u32 cr;
if (0 == ssi->usrcnt) {
rsnd_mod_hw_start(&ssi->mod);
if (rsnd_rdai_is_clk_master(rdai)) {
struct rsnd_ssi *ssi_parent = rsnd_ssi_parent(ssi);
if (ssi_parent)
rsnd_ssi_hw_start(ssi_parent, io);
else
rsnd_ssi_master_clk_start(ssi, io);
}
}
if (rsnd_ssi_is_dma_mode(&ssi->mod)) {
cr_mode = UIEN | OIEN |
DMEN;
} else {
cr_mode = DIEN;
}
cr = ssi->cr_own |
ssi->cr_clk |
cr_mode |
EN;
rsnd_mod_write(&ssi->mod, SSICR, cr);
if (rsnd_rdai_is_clk_master(rdai))
rsnd_mod_write(&ssi->mod, SSIWSR, CONT);
rsnd_mod_write(&ssi->mod, SSISR, 0);
ssi->usrcnt++;
dev_dbg(dev, "%s[%d] hw started\n",
rsnd_mod_name(&ssi->mod), rsnd_mod_id(&ssi->mod));
}
static void rsnd_ssi_hw_stop(struct rsnd_dai_stream *io, struct rsnd_ssi *ssi)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(&ssi->mod);
struct rsnd_dai *rdai = rsnd_io_to_rdai(io);
struct device *dev = rsnd_priv_to_dev(priv);
u32 cr;
if (0 == ssi->usrcnt) {
dev_err(dev, "%s called without starting\n", __func__);
return;
}
ssi->usrcnt--;
if (0 == ssi->usrcnt) {
cr = ssi->cr_own |
ssi->cr_clk;
rsnd_mod_write(&ssi->mod, SSICR, cr | EN);
rsnd_ssi_status_check(&ssi->mod, DIRQ);
rsnd_mod_write(&ssi->mod, SSICR, cr);
rsnd_ssi_status_check(&ssi->mod, IIRQ);
if (rsnd_rdai_is_clk_master(rdai)) {
struct rsnd_ssi *ssi_parent = rsnd_ssi_parent(ssi);
if (ssi_parent)
rsnd_ssi_hw_stop(io, ssi_parent);
else
rsnd_ssi_master_clk_stop(ssi);
}
rsnd_mod_hw_stop(&ssi->mod);
ssi->chan = 0;
}
dev_dbg(dev, "%s[%d] hw stopped\n",
rsnd_mod_name(&ssi->mod), rsnd_mod_id(&ssi->mod));
}
static int rsnd_ssi_init(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_dai *rdai = rsnd_io_to_rdai(io);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
u32 cr;
cr = FORCE;
cr |= SWL_32;
switch (runtime->sample_bits) {
case 16:
cr |= DWL_16;
break;
case 32:
cr |= DWL_24;
break;
default:
return -EIO;
}
if (rdai->bit_clk_inv)
cr |= SCKP;
if (rdai->frm_clk_inv)
cr |= SWSP;
if (rdai->data_alignment)
cr |= SDTA;
if (rdai->sys_delay)
cr |= DEL;
if (rsnd_io_is_play(io))
cr |= TRMD;
ssi->cr_own = cr;
ssi->err = -1;
return 0;
}
static int rsnd_ssi_quit(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct device *dev = rsnd_priv_to_dev(priv);
if (ssi->err > 0)
dev_warn(dev, "%s[%d] under/over flow err = %d\n",
rsnd_mod_name(mod), rsnd_mod_id(mod), ssi->err);
ssi->cr_own = 0;
ssi->err = 0;
return 0;
}
static int rsnd_ssi_hw_params(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_ssi *ssi_parent = rsnd_ssi_parent(ssi);
int chan = params_channels(params);
if (ssi->usrcnt) {
if (ssi->chan != chan)
return -EIO;
}
ssi->chan = chan;
if (ssi_parent)
return rsnd_ssi_hw_params(&ssi_parent->mod, io,
substream, params);
return 0;
}
static void rsnd_ssi_record_error(struct rsnd_ssi *ssi, u32 status)
{
if (status & (UIRQ | OIRQ)) {
ssi->err++;
rsnd_mod_write(&ssi->mod, SSISR, 0);
}
}
static int rsnd_ssi_start(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
rsnd_src_ssiu_start(mod, io, rsnd_ssi_use_busif(io, mod));
rsnd_ssi_hw_start(ssi, io);
rsnd_src_ssi_irq_enable(mod);
return 0;
}
static int rsnd_ssi_stop(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
rsnd_src_ssi_irq_disable(mod);
rsnd_ssi_record_error(ssi, rsnd_mod_read(mod, SSISR));
rsnd_ssi_hw_stop(io, ssi);
rsnd_src_ssiu_stop(mod, io);
return 0;
}
static void __rsnd_ssi_interrupt(struct rsnd_mod *mod,
struct rsnd_dai_stream *io)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
int is_dma = rsnd_ssi_is_dma_mode(mod);
u32 status;
bool elapsed = false;
spin_lock(&priv->lock);
if (!rsnd_io_is_working(io))
goto rsnd_ssi_interrupt_out;
status = rsnd_mod_read(mod, SSISR);
if (!is_dma && (status & DIRQ)) {
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
u32 *buf = (u32 *)(runtime->dma_area +
rsnd_dai_pointer_offset(io, 0));
if (rsnd_io_is_play(io))
rsnd_mod_write(mod, SSITDR, *buf);
else
*buf = rsnd_mod_read(mod, SSIRDR);
elapsed = rsnd_dai_pointer_update(io, sizeof(*buf));
}
if (is_dma && (status & (UIRQ | OIRQ))) {
struct device *dev = rsnd_priv_to_dev(priv);
dev_dbg(dev, "%s[%d] restart\n",
rsnd_mod_name(mod), rsnd_mod_id(mod));
rsnd_ssi_stop(mod, io, priv);
if (ssi->err < 1024)
rsnd_ssi_start(mod, io, priv);
else
dev_warn(dev, "no more SSI restart\n");
}
rsnd_ssi_record_error(ssi, status);
rsnd_ssi_interrupt_out:
spin_unlock(&priv->lock);
if (elapsed)
rsnd_dai_period_elapsed(io);
}
static irqreturn_t rsnd_ssi_interrupt(int irq, void *data)
{
struct rsnd_mod *mod = data;
rsnd_mod_interrupt(mod, __rsnd_ssi_interrupt);
return IRQ_HANDLED;
}
static int rsnd_ssi_pio_probe(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
int ret;
ret = devm_request_irq(dev, ssi->info->irq,
rsnd_ssi_interrupt,
IRQF_SHARED,
dev_name(dev), mod);
return ret;
}
static int rsnd_ssi_dma_probe(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct device *dev = rsnd_priv_to_dev(priv);
int dma_id = ssi->info->dma_id;
int ret;
ret = devm_request_irq(dev, ssi->info->irq,
rsnd_ssi_interrupt,
IRQF_SHARED,
dev_name(dev), mod);
if (ret)
return ret;
ret = rsnd_dma_init(
io, rsnd_mod_to_dma(mod),
dma_id);
return ret;
}
static int rsnd_ssi_dma_remove(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct device *dev = rsnd_priv_to_dev(priv);
int irq = ssi->info->irq;
rsnd_dma_quit(io, rsnd_mod_to_dma(mod));
devm_free_irq(dev, irq, ssi);
return 0;
}
static int rsnd_ssi_fallback(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
mod->ops = &rsnd_ssi_pio_ops;
dev_info(dev, "%s[%d] fallback to PIO mode\n",
rsnd_mod_name(mod), rsnd_mod_id(mod));
return 0;
}
static int rsnd_ssi_dma_start(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_dma *dma = rsnd_mod_to_dma(mod);
rsnd_dma_start(io, dma);
rsnd_ssi_start(mod, io, priv);
return 0;
}
static int rsnd_ssi_dma_stop(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_dma *dma = rsnd_mod_to_dma(mod);
rsnd_ssi_stop(mod, io, priv);
rsnd_dma_stop(io, dma);
return 0;
}
static struct dma_chan *rsnd_ssi_dma_req(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
int is_play = rsnd_io_is_play(io);
char *name;
if (rsnd_ssi_use_busif(io, mod))
name = is_play ? "rxu" : "txu";
else
name = is_play ? "rx" : "tx";
return rsnd_dma_request_channel(rsnd_ssi_of_node(priv),
mod, name);
}
int rsnd_ssi_is_dma_mode(struct rsnd_mod *mod)
{
return mod->ops == &rsnd_ssi_dma_ops;
}
struct rsnd_mod *rsnd_ssi_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_ssi_nr(priv)))
id = 0;
return &((struct rsnd_ssi *)(priv->ssi) + id)->mod;
}
int rsnd_ssi_is_pin_sharing(struct rsnd_mod *mod)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
return !!(rsnd_ssi_mode_flags(ssi) & RSND_SSI_CLK_PIN_SHARE);
}
static void rsnd_ssi_parent_setup(struct rsnd_priv *priv, struct rsnd_ssi *ssi)
{
if (!rsnd_ssi_is_pin_sharing(&ssi->mod))
return;
switch (rsnd_mod_id(&ssi->mod)) {
case 1:
case 2:
ssi->parent = rsnd_mod_to_ssi(rsnd_ssi_mod_get(priv, 0));
break;
case 4:
ssi->parent = rsnd_mod_to_ssi(rsnd_ssi_mod_get(priv, 3));
break;
case 8:
ssi->parent = rsnd_mod_to_ssi(rsnd_ssi_mod_get(priv, 7));
break;
}
}
static void rsnd_of_parse_ssi(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct device_node *node;
struct device_node *np;
struct rsnd_ssi_platform_info *ssi_info;
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = &pdev->dev;
int nr, i;
if (!of_data)
return;
node = rsnd_ssi_of_node(priv);
if (!node)
return;
nr = of_get_child_count(node);
if (!nr)
goto rsnd_of_parse_ssi_end;
ssi_info = devm_kzalloc(dev,
sizeof(struct rsnd_ssi_platform_info) * nr,
GFP_KERNEL);
if (!ssi_info) {
dev_err(dev, "ssi info allocation error\n");
goto rsnd_of_parse_ssi_end;
}
info->ssi_info = ssi_info;
info->ssi_info_nr = nr;
i = -1;
for_each_child_of_node(node, np) {
i++;
ssi_info = info->ssi_info + i;
if (of_get_property(np, "shared-pin", NULL))
ssi_info->flags |= RSND_SSI_CLK_PIN_SHARE;
ssi_info->irq = irq_of_parse_and_map(np, 0);
ssi_info->dma_id = of_get_property(np, "pio-transfer", NULL) ?
0 : 1;
if (of_get_property(np, "no-busif", NULL))
ssi_info->flags |= RSND_SSI_NO_BUSIF;
}
rsnd_of_parse_ssi_end:
of_node_put(node);
}
int rsnd_ssi_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct rsnd_ssi_platform_info *pinfo;
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_mod_ops *ops;
struct clk *clk;
struct rsnd_ssi *ssi;
char name[RSND_SSI_NAME_SIZE];
int i, nr, ret;
rsnd_of_parse_ssi(pdev, of_data, priv);
nr = info->ssi_info_nr;
ssi = devm_kzalloc(dev, sizeof(*ssi) * nr, GFP_KERNEL);
if (!ssi)
return -ENOMEM;
priv->ssi = ssi;
priv->ssi_nr = nr;
for_each_rsnd_ssi(ssi, priv, i) {
pinfo = &info->ssi_info[i];
snprintf(name, RSND_SSI_NAME_SIZE, "%s.%d",
SSI_NAME, i);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk))
return PTR_ERR(clk);
ssi->info = pinfo;
ops = &rsnd_ssi_non_ops;
if (pinfo->dma_id > 0)
ops = &rsnd_ssi_dma_ops;
else if (rsnd_ssi_pio_available(ssi))
ops = &rsnd_ssi_pio_ops;
ret = rsnd_mod_init(priv, &ssi->mod, ops, clk, RSND_MOD_SSI, i);
if (ret)
return ret;
rsnd_ssi_parent_setup(priv, ssi);
}
return 0;
}
void rsnd_ssi_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi;
int i;
for_each_rsnd_ssi(ssi, priv, i) {
rsnd_mod_quit(&ssi->mod);
}
}
