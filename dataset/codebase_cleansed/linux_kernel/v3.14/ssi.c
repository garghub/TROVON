static void rsnd_ssi_mode_set(struct rsnd_priv *priv,
struct rsnd_dai *rdai,
struct rsnd_ssi *ssi)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_mod *scu;
struct rsnd_ssiu *ssiu = rsnd_ssi_to_ssiu(ssi);
int id = rsnd_mod_id(&ssi->mod);
u32 flags;
u32 val;
scu = rsnd_scu_mod_get(priv, rsnd_mod_id(&ssi->mod));
if (rsnd_scu_hpbif_is_enable(scu)) {
ssiu->ssi_mode0 &= ~(1 << id);
dev_dbg(dev, "SSI%d uses DEPENDENT mode\n", id);
} else {
ssiu->ssi_mode0 |= (1 << id);
dev_dbg(dev, "SSI%d uses INDEPENDENT mode\n", id);
}
#define ssi_parent_set(p, sync, adg, ext) \
do { \
ssi->parent = ssiu->ssi + p; \
if (rsnd_rdai_is_clk_master(rdai)) \
val = adg; \
else \
val = ext; \
if (flags & RSND_SSI_SYNC) \
val |= sync; \
} while (0)
flags = rsnd_ssi_mode_flags(ssi);
if (flags & RSND_SSI_CLK_PIN_SHARE) {
val = 0;
switch (id) {
case 1:
ssi_parent_set(0, (1 << 4), (0x2 << 0), (0x1 << 0));
break;
case 2:
ssi_parent_set(0, (1 << 4), (0x2 << 2), (0x1 << 2));
break;
case 4:
ssi_parent_set(3, (1 << 20), (0x2 << 16), (0x1 << 16));
break;
case 8:
ssi_parent_set(7, 0, 0, 0);
break;
}
ssiu->ssi_mode1 |= val;
}
rsnd_mod_write(&ssi->mod, SSI_MODE0, ssiu->ssi_mode0);
rsnd_mod_write(&ssi->mod, SSI_MODE1, ssiu->ssi_mode1);
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
struct rsnd_priv *priv = rsnd_mod_to_priv(&ssi->mod);
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
unsigned int rate = rsnd_scu_get_ssi_rate(priv, &ssi->mod, runtime);
for (i = 0; i < ARRAY_SIZE(adg_clk_div_table); i++) {
for (j = 0; j < ARRAY_SIZE(ssi_clk_mul_table); j++) {
main_rate = rate / adg_clk_div_table[i]
* 32 * 2 * ssi_clk_mul_table[j];
ret = rsnd_adg_ssi_clk_try_start(&ssi->mod, main_rate);
if (0 == ret) {
ssi->rate = rate;
ssi->cr_clk = FORCE | SWL_32 |
SCKD | SWSD | CKDV(j);
dev_dbg(dev, "ssi%d outputs %u Hz\n",
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
ssi->rate = 0;
ssi->cr_clk = 0;
rsnd_adg_ssi_clk_stop(&ssi->mod);
}
static void rsnd_ssi_hw_start(struct rsnd_ssi *ssi,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(&ssi->mod);
struct device *dev = rsnd_priv_to_dev(priv);
u32 cr;
if (0 == ssi->usrcnt) {
clk_enable(ssi->clk);
if (rsnd_rdai_is_clk_master(rdai)) {
if (rsnd_ssi_clk_from_parent(ssi))
rsnd_ssi_hw_start(ssi->parent, rdai, io);
else
rsnd_ssi_master_clk_start(ssi, io);
}
}
cr = ssi->cr_own |
ssi->cr_clk |
ssi->cr_etc |
EN;
rsnd_mod_write(&ssi->mod, SSICR, cr);
ssi->usrcnt++;
dev_dbg(dev, "ssi%d hw started\n", rsnd_mod_id(&ssi->mod));
}
static void rsnd_ssi_hw_stop(struct rsnd_ssi *ssi,
struct rsnd_dai *rdai)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(&ssi->mod);
struct device *dev = rsnd_priv_to_dev(priv);
u32 cr;
if (0 == ssi->usrcnt)
return;
ssi->usrcnt--;
if (0 == ssi->usrcnt) {
cr = ssi->cr_own |
ssi->cr_clk;
rsnd_mod_write(&ssi->mod, SSICR, cr | EN);
rsnd_ssi_status_check(&ssi->mod, DIRQ);
rsnd_mod_write(&ssi->mod, SSICR, cr);
rsnd_ssi_status_check(&ssi->mod, IIRQ);
if (rsnd_rdai_is_clk_master(rdai)) {
if (rsnd_ssi_clk_from_parent(ssi))
rsnd_ssi_hw_stop(ssi->parent, rdai);
else
rsnd_ssi_master_clk_stop(ssi);
}
clk_disable(ssi->clk);
}
dev_dbg(dev, "ssi%d hw stopped\n", rsnd_mod_id(&ssi->mod));
}
static int rsnd_ssi_init(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
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
if (rsnd_dai_is_play(rdai, io))
cr |= TRMD;
ssi->rdai = rdai;
ssi->io = io;
ssi->cr_own = cr;
ssi->err = -1;
rsnd_ssi_mode_set(priv, rdai, ssi);
dev_dbg(dev, "%s.%d init\n", rsnd_mod_name(mod), rsnd_mod_id(mod));
return 0;
}
static int rsnd_ssi_quit(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
dev_dbg(dev, "%s.%d quit\n", rsnd_mod_name(mod), rsnd_mod_id(mod));
if (ssi->err > 0)
dev_warn(dev, "ssi under/over flow err = %d\n", ssi->err);
ssi->rdai = NULL;
ssi->io = NULL;
ssi->cr_own = 0;
ssi->err = 0;
return 0;
}
static void rsnd_ssi_record_error(struct rsnd_ssi *ssi, u32 status)
{
if (status & (UIRQ | OIRQ)) {
ssi->err++;
rsnd_mod_write(&ssi->mod, SSISR, 0);
}
}
static irqreturn_t rsnd_ssi_pio_interrupt(int irq, void *data)
{
struct rsnd_ssi *ssi = data;
struct rsnd_dai_stream *io = ssi->io;
u32 status = rsnd_mod_read(&ssi->mod, SSISR);
irqreturn_t ret = IRQ_NONE;
if (io && (status & DIRQ)) {
struct rsnd_dai *rdai = ssi->rdai;
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
u32 *buf = (u32 *)(runtime->dma_area +
rsnd_dai_pointer_offset(io, 0));
rsnd_ssi_record_error(ssi, status);
if (rsnd_dai_is_play(rdai, io))
rsnd_mod_write(&ssi->mod, SSITDR, *buf);
else
*buf = rsnd_mod_read(&ssi->mod, SSIRDR);
rsnd_dai_pointer_update(io, sizeof(*buf));
ret = IRQ_HANDLED;
}
return ret;
}
static int rsnd_ssi_pio_start(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct device *dev = rsnd_priv_to_dev(priv);
ssi->cr_etc = UIEN | OIEN | DIEN;
if (rsnd_is_gen2(priv))
rsnd_mod_write(&ssi->mod, INT_ENABLE, 0x0f000000);
rsnd_ssi_hw_start(ssi, rdai, io);
dev_dbg(dev, "%s.%d start\n", rsnd_mod_name(mod), rsnd_mod_id(mod));
return 0;
}
static int rsnd_ssi_pio_stop(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
dev_dbg(dev, "%s.%d stop\n", rsnd_mod_name(mod), rsnd_mod_id(mod));
ssi->cr_etc = 0;
rsnd_ssi_hw_stop(ssi, rdai);
return 0;
}
static int rsnd_ssi_dma_inquiry(struct rsnd_dma *dma, dma_addr_t *buf, int *len)
{
struct rsnd_ssi *ssi = rsnd_dma_to_ssi(dma);
struct rsnd_dai_stream *io = ssi->io;
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
*len = io->byte_per_period;
*buf = runtime->dma_addr +
rsnd_dai_pointer_offset(io, ssi->dma_offset + *len);
ssi->dma_offset = *len;
return 0;
}
static int rsnd_ssi_dma_complete(struct rsnd_dma *dma)
{
struct rsnd_ssi *ssi = rsnd_dma_to_ssi(dma);
struct rsnd_dai_stream *io = ssi->io;
u32 status = rsnd_mod_read(&ssi->mod, SSISR);
rsnd_ssi_record_error(ssi, status);
rsnd_dai_pointer_update(ssi->io, io->byte_per_period);
return 0;
}
static int rsnd_ssi_dma_start(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_dma *dma = rsnd_mod_to_dma(&ssi->mod);
ssi->cr_etc = DMEN;
ssi->dma_offset = 0;
rsnd_dma_start(dma);
rsnd_ssi_hw_start(ssi, ssi->rdai, io);
if (rsnd_rdai_is_clk_master(rdai))
rsnd_mod_write(&ssi->mod, SSIWSR, CONT);
return 0;
}
static int rsnd_ssi_dma_stop(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_ssi *ssi = rsnd_mod_to_ssi(mod);
struct rsnd_dma *dma = rsnd_mod_to_dma(&ssi->mod);
ssi->cr_etc = 0;
rsnd_ssi_hw_stop(ssi, rdai);
rsnd_dma_stop(dma);
return 0;
}
static int rsnd_ssi_non(struct rsnd_mod *mod,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
dev_dbg(dev, "%s\n", __func__);
return 0;
}
struct rsnd_mod *rsnd_ssi_mod_get_frm_dai(struct rsnd_priv *priv,
int dai_id, int is_play)
{
struct rsnd_ssi *ssi;
int i, has_play;
is_play = !!is_play;
for_each_rsnd_ssi(ssi, priv, i) {
if (rsnd_ssi_dai_id(ssi) != dai_id)
continue;
has_play = !!(rsnd_ssi_mode_flags(ssi) & RSND_SSI_PLAY);
if (is_play == has_play)
return &ssi->mod;
}
return NULL;
}
struct rsnd_mod *rsnd_ssi_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_ssi_nr(priv)))
id = 0;
return &(((struct rsnd_ssiu *)(priv->ssiu))->ssi + id)->mod;
}
int rsnd_ssi_probe(struct platform_device *pdev,
struct rcar_snd_info *info,
struct rsnd_priv *priv)
{
struct rsnd_ssi_platform_info *pinfo;
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_mod_ops *ops;
struct clk *clk;
struct rsnd_ssiu *ssiu;
struct rsnd_ssi *ssi;
char name[RSND_SSI_NAME_SIZE];
int i, nr, ret;
nr = info->ssi_info_nr;
ssiu = devm_kzalloc(dev, sizeof(*ssiu) + (sizeof(*ssi) * nr),
GFP_KERNEL);
if (!ssiu) {
dev_err(dev, "SSI allocate failed\n");
return -ENOMEM;
}
priv->ssiu = ssiu;
ssiu->ssi = (struct rsnd_ssi *)(ssiu + 1);
ssiu->ssi_nr = nr;
for_each_rsnd_ssi(ssi, priv, i) {
pinfo = &info->ssi_info[i];
snprintf(name, RSND_SSI_NAME_SIZE, "ssi.%d", i);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk))
return PTR_ERR(clk);
ssi->info = pinfo;
ssi->clk = clk;
ops = &rsnd_ssi_non_ops;
if (pinfo->dma_id > 0) {
ret = rsnd_dma_init(
priv, rsnd_mod_to_dma(&ssi->mod),
(rsnd_ssi_mode_flags(ssi) & RSND_SSI_PLAY),
pinfo->dma_id,
rsnd_ssi_dma_inquiry,
rsnd_ssi_dma_complete);
if (ret < 0)
dev_info(dev, "SSI DMA failed. try PIO transter\n");
else
ops = &rsnd_ssi_dma_ops;
dev_dbg(dev, "SSI%d use DMA transfer\n", i);
}
if (!rsnd_ssi_dma_available(ssi) &&
rsnd_ssi_pio_available(ssi)) {
ret = devm_request_irq(dev, pinfo->pio_irq,
&rsnd_ssi_pio_interrupt,
IRQF_SHARED,
dev_name(dev), ssi);
if (ret) {
dev_err(dev, "SSI request interrupt failed\n");
return ret;
}
ops = &rsnd_ssi_pio_ops;
dev_dbg(dev, "SSI%d use PIO transfer\n", i);
}
rsnd_mod_init(priv, &ssi->mod, ops, i);
}
dev_dbg(dev, "ssi probed\n");
return 0;
}
void rsnd_ssi_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct rsnd_ssi *ssi;
int i;
for_each_rsnd_ssi(ssi, priv, i) {
if (rsnd_ssi_dma_available(ssi))
rsnd_dma_quit(priv, rsnd_mod_to_dma(&ssi->mod));
}
}
