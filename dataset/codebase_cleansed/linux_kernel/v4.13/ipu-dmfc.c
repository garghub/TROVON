int ipu_dmfc_enable_channel(struct dmfc_channel *dmfc)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
mutex_lock(&priv->mutex);
if (!priv->use_count)
ipu_module_enable(priv->ipu, IPU_CONF_DMFC_EN);
priv->use_count++;
mutex_unlock(&priv->mutex);
return 0;
}
void ipu_dmfc_disable_channel(struct dmfc_channel *dmfc)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
mutex_lock(&priv->mutex);
priv->use_count--;
if (!priv->use_count)
ipu_module_disable(priv->ipu, IPU_CONF_DMFC_EN);
if (priv->use_count < 0)
priv->use_count = 0;
mutex_unlock(&priv->mutex);
}
void ipu_dmfc_config_wait4eot(struct dmfc_channel *dmfc, int width)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
u32 dmfc_gen1;
mutex_lock(&priv->mutex);
dmfc_gen1 = readl(priv->base + DMFC_GENERAL1);
if ((dmfc->slots * 64 * 4) / width > dmfc->data->max_fifo_lines)
dmfc_gen1 |= 1 << dmfc->data->eot_shift;
else
dmfc_gen1 &= ~(1 << dmfc->data->eot_shift);
writel(dmfc_gen1, priv->base + DMFC_GENERAL1);
mutex_unlock(&priv->mutex);
}
struct dmfc_channel *ipu_dmfc_get(struct ipu_soc *ipu, int ipu_channel)
{
struct ipu_dmfc_priv *priv = ipu->dmfc_priv;
int i;
for (i = 0; i < DMFC_NUM_CHANNELS; i++)
if (dmfcdata[i].ipu_channel == ipu_channel)
return &priv->channels[i];
return ERR_PTR(-ENODEV);
}
void ipu_dmfc_put(struct dmfc_channel *dmfc)
{
}
int ipu_dmfc_init(struct ipu_soc *ipu, struct device *dev, unsigned long base,
struct clk *ipu_clk)
{
struct ipu_dmfc_priv *priv;
int i;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base = devm_ioremap(dev, base, PAGE_SIZE);
if (!priv->base)
return -ENOMEM;
priv->dev = dev;
priv->ipu = ipu;
mutex_init(&priv->mutex);
ipu->dmfc_priv = priv;
for (i = 0; i < DMFC_NUM_CHANNELS; i++) {
priv->channels[i].priv = priv;
priv->channels[i].ipu = ipu;
priv->channels[i].data = &dmfcdata[i];
if (dmfcdata[i].ipu_channel == IPUV3_CHANNEL_MEM_BG_SYNC ||
dmfcdata[i].ipu_channel == IPUV3_CHANNEL_MEM_FG_SYNC ||
dmfcdata[i].ipu_channel == IPUV3_CHANNEL_MEM_DC_SYNC)
priv->channels[i].slots = 2;
}
writel(0x00000050, priv->base + DMFC_WR_CHAN);
writel(0x00005654, priv->base + DMFC_DP_CHAN);
writel(0x202020f6, priv->base + DMFC_WR_CHAN_DEF);
writel(0x2020f6f6, priv->base + DMFC_DP_CHAN_DEF);
writel(0x00000003, priv->base + DMFC_GENERAL1);
return 0;
}
void ipu_dmfc_exit(struct ipu_soc *ipu)
{
}
