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
static void ipu_dmfc_wait_fifos(struct ipu_dmfc_priv *priv)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
while ((readl(priv->base + DMFC_STAT) & 0x02fff000) != 0x02fff000) {
if (time_after(jiffies, timeout)) {
dev_warn(priv->dev,
"Timeout waiting for DMFC FIFOs to clear\n");
break;
}
cpu_relax();
}
}
void ipu_dmfc_disable_channel(struct dmfc_channel *dmfc)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
mutex_lock(&priv->mutex);
priv->use_count--;
if (!priv->use_count) {
ipu_dmfc_wait_fifos(priv);
ipu_module_disable(priv->ipu, IPU_CONF_DMFC_EN);
}
if (priv->use_count < 0)
priv->use_count = 0;
mutex_unlock(&priv->mutex);
}
static int ipu_dmfc_setup_channel(struct dmfc_channel *dmfc, int slots,
int segment, int burstsize)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
u32 val, field;
dev_dbg(priv->dev,
"dmfc: using %d slots starting from segment %d for IPU channel %d\n",
slots, segment, dmfc->data->ipu_channel);
switch (slots) {
case 1:
field = DMFC_FIFO_SIZE_64;
break;
case 2:
field = DMFC_FIFO_SIZE_128;
break;
case 4:
field = DMFC_FIFO_SIZE_256;
break;
case 8:
field = DMFC_FIFO_SIZE_512;
break;
default:
return -EINVAL;
}
switch (burstsize) {
case 16:
field |= DMFC_BURSTSIZE_16;
break;
case 32:
field |= DMFC_BURSTSIZE_32;
break;
case 64:
field |= DMFC_BURSTSIZE_64;
break;
case 128:
field |= DMFC_BURSTSIZE_128;
break;
}
field |= DMFC_SEGMENT(segment);
val = readl(priv->base + dmfc->data->channel_reg);
val &= ~(0xff << dmfc->data->shift);
val |= field << dmfc->data->shift;
writel(val, priv->base + dmfc->data->channel_reg);
dmfc->slots = slots;
dmfc->segment = segment;
dmfc->burstsize = burstsize;
dmfc->slotmask = ((1 << slots) - 1) << segment;
return 0;
}
static int dmfc_bandwidth_to_slots(struct ipu_dmfc_priv *priv,
unsigned long bandwidth)
{
int slots = 1;
while (slots * priv->bandwidth_per_slot < bandwidth)
slots *= 2;
return slots;
}
static int dmfc_find_slots(struct ipu_dmfc_priv *priv, int slots)
{
unsigned slotmask_need, slotmask_used = 0;
int i, segment = 0;
slotmask_need = (1 << slots) - 1;
for (i = 0; i < DMFC_NUM_CHANNELS; i++)
slotmask_used |= priv->channels[i].slotmask;
while (slotmask_need <= 0xff) {
if (!(slotmask_used & slotmask_need))
return segment;
slotmask_need <<= 1;
segment++;
}
return -EBUSY;
}
void ipu_dmfc_free_bandwidth(struct dmfc_channel *dmfc)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
int i;
dev_dbg(priv->dev, "dmfc: freeing %d slots starting from segment %d\n",
dmfc->slots, dmfc->segment);
mutex_lock(&priv->mutex);
if (!dmfc->slots)
goto out;
dmfc->slotmask = 0;
dmfc->slots = 0;
dmfc->segment = 0;
for (i = 0; i < DMFC_NUM_CHANNELS; i++)
priv->channels[i].slotmask = 0;
for (i = 0; i < DMFC_NUM_CHANNELS; i++) {
if (priv->channels[i].slots > 0) {
priv->channels[i].segment =
dmfc_find_slots(priv, priv->channels[i].slots);
priv->channels[i].slotmask =
((1 << priv->channels[i].slots) - 1) <<
priv->channels[i].segment;
}
}
for (i = 0; i < DMFC_NUM_CHANNELS; i++) {
if (priv->channels[i].slots > 0)
ipu_dmfc_setup_channel(&priv->channels[i],
priv->channels[i].slots,
priv->channels[i].segment,
priv->channels[i].burstsize);
}
out:
mutex_unlock(&priv->mutex);
}
int ipu_dmfc_alloc_bandwidth(struct dmfc_channel *dmfc,
unsigned long bandwidth_pixel_per_second, int burstsize)
{
struct ipu_dmfc_priv *priv = dmfc->priv;
int slots = dmfc_bandwidth_to_slots(priv, bandwidth_pixel_per_second);
int segment = -1, ret = 0;
dev_dbg(priv->dev, "dmfc: trying to allocate %ldMpixel/s for IPU channel %d\n",
bandwidth_pixel_per_second / 1000000,
dmfc->data->ipu_channel);
ipu_dmfc_free_bandwidth(dmfc);
mutex_lock(&priv->mutex);
if (slots > 8) {
ret = -EBUSY;
goto out;
}
if (dmfc->data->ipu_channel == IPUV3_CHANNEL_MEM_BG_SYNC)
segment = dmfc_find_slots(priv, slots * 2);
else if (slots < 2)
slots = 2;
if (segment >= 0)
slots *= 2;
else
segment = dmfc_find_slots(priv, slots);
if (segment < 0) {
ret = -EBUSY;
goto out;
}
ipu_dmfc_setup_channel(dmfc, slots, segment, burstsize);
out:
mutex_unlock(&priv->mutex);
return ret;
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
ipu_dmfc_free_bandwidth(dmfc);
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
}
writel(0x0, priv->base + DMFC_WR_CHAN);
writel(0x0, priv->base + DMFC_DP_CHAN);
priv->bandwidth_per_slot = clk_get_rate(ipu_clk) * 4 / 8;
dev_dbg(dev, "dmfc: 8 slots with %ldMpixel/s bandwidth each\n",
priv->bandwidth_per_slot / 1000000);
writel(0x202020f6, priv->base + DMFC_WR_CHAN_DEF);
writel(0x2020f6f6, priv->base + DMFC_DP_CHAN_DEF);
writel(0x00000003, priv->base + DMFC_GENERAL1);
return 0;
}
void ipu_dmfc_exit(struct ipu_soc *ipu)
{
}
