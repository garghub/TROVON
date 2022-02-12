void iwl_free_isr_ict(struct iwl_priv *priv)
{
if (priv->_agn.ict_tbl_vir) {
dma_free_coherent(&priv->pci_dev->dev,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE,
priv->_agn.ict_tbl_vir,
priv->_agn.ict_tbl_dma);
priv->_agn.ict_tbl_vir = NULL;
}
}
int iwl_alloc_isr_ict(struct iwl_priv *priv)
{
priv->_agn.ict_tbl_vir =
dma_alloc_coherent(&priv->pci_dev->dev,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE,
&priv->_agn.ict_tbl_dma, GFP_KERNEL);
if (!priv->_agn.ict_tbl_vir)
return -ENOMEM;
priv->_agn.aligned_ict_tbl_dma = ALIGN(priv->_agn.ict_tbl_dma, PAGE_SIZE);
IWL_DEBUG_ISR(priv, "ict dma addr %Lx dma aligned %Lx diff %d\n",
(unsigned long long)priv->_agn.ict_tbl_dma,
(unsigned long long)priv->_agn.aligned_ict_tbl_dma,
(int)(priv->_agn.aligned_ict_tbl_dma - priv->_agn.ict_tbl_dma));
priv->_agn.ict_tbl = priv->_agn.ict_tbl_vir +
(priv->_agn.aligned_ict_tbl_dma - priv->_agn.ict_tbl_dma);
IWL_DEBUG_ISR(priv, "ict vir addr %p vir aligned %p diff %d\n",
priv->_agn.ict_tbl, priv->_agn.ict_tbl_vir,
(int)(priv->_agn.aligned_ict_tbl_dma - priv->_agn.ict_tbl_dma));
memset(priv->_agn.ict_tbl_vir,0, (sizeof(u32) * ICT_COUNT) + PAGE_SIZE);
priv->_agn.ict_index = 0;
priv->inta_mask |= CSR_INT_BIT_RX_PERIODIC;
return 0;
}
int iwl_reset_ict(struct iwl_priv *priv)
{
u32 val;
unsigned long flags;
if (!priv->_agn.ict_tbl_vir)
return 0;
spin_lock_irqsave(&priv->lock, flags);
iwl_disable_interrupts(priv);
memset(&priv->_agn.ict_tbl[0], 0, sizeof(u32) * ICT_COUNT);
val = priv->_agn.aligned_ict_tbl_dma >> PAGE_SHIFT;
val |= CSR_DRAM_INT_TBL_ENABLE;
val |= CSR_DRAM_INIT_TBL_WRAP_CHECK;
IWL_DEBUG_ISR(priv, "CSR_DRAM_INT_TBL_REG =0x%X "
"aligned dma address %Lx\n",
val, (unsigned long long)priv->_agn.aligned_ict_tbl_dma);
iwl_write32(priv, CSR_DRAM_INT_TBL_REG, val);
priv->_agn.use_ict = true;
priv->_agn.ict_index = 0;
iwl_write32(priv, CSR_INT, priv->inta_mask);
iwl_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
void iwl_disable_ict(struct iwl_priv *priv)
{
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
priv->_agn.use_ict = false;
spin_unlock_irqrestore(&priv->lock, flags);
}
static irqreturn_t iwl_isr(int irq, void *data)
{
struct iwl_priv *priv = data;
u32 inta, inta_mask;
unsigned long flags;
#ifdef CONFIG_IWLWIFI_DEBUG
u32 inta_fh;
#endif
if (!priv)
return IRQ_NONE;
spin_lock_irqsave(&priv->lock, flags);
inta_mask = iwl_read32(priv, CSR_INT_MASK);
iwl_write32(priv, CSR_INT_MASK, 0x00000000);
inta = iwl_read32(priv, CSR_INT);
if (!inta) {
IWL_DEBUG_ISR(priv, "Ignore interrupt, inta == 0\n");
goto none;
}
if ((inta == 0xFFFFFFFF) || ((inta & 0xFFFFFFF0) == 0xa5a5a5a0)) {
IWL_WARN(priv, "HARDWARE GONE?? INTA == 0x%08x\n", inta);
goto unplugged;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(priv) & (IWL_DL_ISR)) {
inta_fh = iwl_read32(priv, CSR_FH_INT_STATUS);
IWL_DEBUG_ISR(priv, "ISR inta 0x%08x, enabled 0x%08x, "
"fh 0x%08x\n", inta, inta_mask, inta_fh);
}
#endif
priv->_agn.inta |= inta;
if (likely(inta))
tasklet_schedule(&priv->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &priv->status) && !priv->_agn.inta)
iwl_enable_interrupts(priv);
unplugged:
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &priv->status) && !priv->_agn.inta)
iwl_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_NONE;
}
irqreturn_t iwl_isr_ict(int irq, void *data)
{
struct iwl_priv *priv = data;
u32 inta, inta_mask;
u32 val = 0;
unsigned long flags;
if (!priv)
return IRQ_NONE;
if (!priv->_agn.use_ict)
return iwl_isr(irq, data);
spin_lock_irqsave(&priv->lock, flags);
inta_mask = iwl_read32(priv, CSR_INT_MASK);
iwl_write32(priv, CSR_INT_MASK, 0x00000000);
if (!priv->_agn.ict_tbl[priv->_agn.ict_index]) {
IWL_DEBUG_ISR(priv, "Ignore interrupt, inta == 0\n");
goto none;
}
while (priv->_agn.ict_tbl[priv->_agn.ict_index]) {
val |= le32_to_cpu(priv->_agn.ict_tbl[priv->_agn.ict_index]);
IWL_DEBUG_ISR(priv, "ICT index %d value 0x%08X\n",
priv->_agn.ict_index,
le32_to_cpu(priv->_agn.ict_tbl[priv->_agn.ict_index]));
priv->_agn.ict_tbl[priv->_agn.ict_index] = 0;
priv->_agn.ict_index = iwl_queue_inc_wrap(priv->_agn.ict_index,
ICT_COUNT);
}
if (val == 0xffffffff)
val = 0;
if (val & 0xC0000)
val |= 0x8000;
inta = (0xff & val) | ((0xff00 & val) << 16);
IWL_DEBUG_ISR(priv, "ISR inta 0x%08x, enabled 0x%08x ict 0x%08x\n",
inta, inta_mask, val);
inta &= priv->inta_mask;
priv->_agn.inta |= inta;
if (likely(inta))
tasklet_schedule(&priv->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &priv->status) && !priv->_agn.inta) {
iwl_enable_interrupts(priv);
}
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &priv->status) && !priv->_agn.inta)
iwl_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_NONE;
}
