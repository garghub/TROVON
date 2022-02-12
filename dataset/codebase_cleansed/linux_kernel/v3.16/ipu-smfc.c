int ipu_smfc_set_burstsize(struct ipu_soc *ipu, int channel, int burstsize)
{
struct ipu_smfc_priv *smfc = ipu->smfc_priv;
unsigned long flags;
u32 val, shift;
spin_lock_irqsave(&smfc->lock, flags);
shift = channel * 4;
val = readl(smfc->base + SMFC_BS);
val &= ~(0xf << shift);
val |= burstsize << shift;
writel(val, smfc->base + SMFC_BS);
spin_unlock_irqrestore(&smfc->lock, flags);
return 0;
}
int ipu_smfc_map_channel(struct ipu_soc *ipu, int channel, int csi_id, int mipi_id)
{
struct ipu_smfc_priv *smfc = ipu->smfc_priv;
unsigned long flags;
u32 val, shift;
spin_lock_irqsave(&smfc->lock, flags);
shift = channel * 3;
val = readl(smfc->base + SMFC_MAP);
val &= ~(0x7 << shift);
val |= ((csi_id << 2) | mipi_id) << shift;
writel(val, smfc->base + SMFC_MAP);
spin_unlock_irqrestore(&smfc->lock, flags);
return 0;
}
int ipu_smfc_init(struct ipu_soc *ipu, struct device *dev,
unsigned long base)
{
struct ipu_smfc_priv *smfc;
smfc = devm_kzalloc(dev, sizeof(*smfc), GFP_KERNEL);
if (!smfc)
return -ENOMEM;
ipu->smfc_priv = smfc;
spin_lock_init(&smfc->lock);
smfc->base = devm_ioremap(dev, base, PAGE_SIZE);
if (!smfc->base)
return -ENOMEM;
pr_debug("%s: ioremap 0x%08lx -> %p\n", __func__, base, smfc->base);
return 0;
}
void ipu_smfc_exit(struct ipu_soc *ipu)
{
}
