int efx_nic_alloc_buffer(struct efx_nic *efx, struct efx_buffer *buffer,
unsigned int len, gfp_t gfp_flags)
{
buffer->addr = dma_zalloc_coherent(&efx->pci_dev->dev, len,
&buffer->dma_addr, gfp_flags);
if (!buffer->addr)
return -ENOMEM;
buffer->len = len;
return 0;
}
void efx_nic_free_buffer(struct efx_nic *efx, struct efx_buffer *buffer)
{
if (buffer->addr) {
dma_free_coherent(&efx->pci_dev->dev, buffer->len,
buffer->addr, buffer->dma_addr);
buffer->addr = NULL;
}
}
bool efx_nic_event_present(struct efx_channel *channel)
{
return efx_event_present(efx_event(channel, channel->eventq_read_ptr));
}
void efx_nic_event_test_start(struct efx_channel *channel)
{
channel->event_test_cpu = -1;
smp_wmb();
channel->efx->type->ev_test_generate(channel);
}
void efx_nic_irq_test_start(struct efx_nic *efx)
{
efx->last_irq_cpu = -1;
smp_wmb();
efx->type->irq_test_generate(efx);
}
int efx_nic_init_interrupt(struct efx_nic *efx)
{
struct efx_channel *channel;
unsigned int n_irqs;
int rc;
if (!EFX_INT_MODE_USE_MSI(efx)) {
rc = request_irq(efx->legacy_irq,
efx->type->irq_handle_legacy, IRQF_SHARED,
efx->name, efx);
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to hook legacy IRQ %d\n",
efx->pci_dev->irq);
goto fail1;
}
return 0;
}
#ifdef CONFIG_RFS_ACCEL
if (efx->interrupt_mode == EFX_INT_MODE_MSIX) {
efx->net_dev->rx_cpu_rmap =
alloc_irq_cpu_rmap(efx->n_rx_channels);
if (!efx->net_dev->rx_cpu_rmap) {
rc = -ENOMEM;
goto fail1;
}
}
#endif
n_irqs = 0;
efx_for_each_channel(channel, efx) {
rc = request_irq(channel->irq, efx->type->irq_handle_msi,
IRQF_PROBE_SHARED,
efx->msi_context[channel->channel].name,
&efx->msi_context[channel->channel]);
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to hook IRQ %d\n", channel->irq);
goto fail2;
}
++n_irqs;
#ifdef CONFIG_RFS_ACCEL
if (efx->interrupt_mode == EFX_INT_MODE_MSIX &&
channel->channel < efx->n_rx_channels) {
rc = irq_cpu_rmap_add(efx->net_dev->rx_cpu_rmap,
channel->irq);
if (rc)
goto fail2;
}
#endif
}
return 0;
fail2:
#ifdef CONFIG_RFS_ACCEL
free_irq_cpu_rmap(efx->net_dev->rx_cpu_rmap);
efx->net_dev->rx_cpu_rmap = NULL;
#endif
efx_for_each_channel(channel, efx) {
if (n_irqs-- == 0)
break;
free_irq(channel->irq, &efx->msi_context[channel->channel]);
}
fail1:
return rc;
}
void efx_nic_fini_interrupt(struct efx_nic *efx)
{
struct efx_channel *channel;
#ifdef CONFIG_RFS_ACCEL
free_irq_cpu_rmap(efx->net_dev->rx_cpu_rmap);
efx->net_dev->rx_cpu_rmap = NULL;
#endif
efx_for_each_channel(channel, efx)
free_irq(channel->irq, &efx->msi_context[channel->channel]);
if (efx->legacy_irq)
free_irq(efx->legacy_irq, efx);
}
size_t efx_nic_get_regs_len(struct efx_nic *efx)
{
const struct efx_nic_reg *reg;
const struct efx_nic_reg_table *table;
size_t len = 0;
for (reg = efx_nic_regs;
reg < efx_nic_regs + ARRAY_SIZE(efx_nic_regs);
reg++)
if (efx->type->revision >= reg->min_revision &&
efx->type->revision <= reg->max_revision)
len += sizeof(efx_oword_t);
for (table = efx_nic_reg_tables;
table < efx_nic_reg_tables + ARRAY_SIZE(efx_nic_reg_tables);
table++)
if (efx->type->revision >= table->min_revision &&
efx->type->revision <= table->max_revision)
len += table->rows * min_t(size_t, table->step, 16);
return len;
}
void efx_nic_get_regs(struct efx_nic *efx, void *buf)
{
const struct efx_nic_reg *reg;
const struct efx_nic_reg_table *table;
for (reg = efx_nic_regs;
reg < efx_nic_regs + ARRAY_SIZE(efx_nic_regs);
reg++) {
if (efx->type->revision >= reg->min_revision &&
efx->type->revision <= reg->max_revision) {
efx_reado(efx, (efx_oword_t *)buf, reg->offset);
buf += sizeof(efx_oword_t);
}
}
for (table = efx_nic_reg_tables;
table < efx_nic_reg_tables + ARRAY_SIZE(efx_nic_reg_tables);
table++) {
size_t size, i;
if (!(efx->type->revision >= table->min_revision &&
efx->type->revision <= table->max_revision))
continue;
size = min_t(size_t, table->step, 16);
for (i = 0; i < table->rows; i++) {
switch (table->step) {
case 4:
efx_readd(efx, buf, table->offset + 4 * i);
break;
case 8:
efx_sram_readq(efx,
efx->membase + table->offset,
buf, i);
break;
case 16:
efx_reado_table(efx, buf, table->offset, i);
break;
case 32:
efx_reado_table(efx, buf, table->offset, 2 * i);
break;
default:
WARN_ON(1);
return;
}
buf += size;
}
}
}
size_t efx_nic_describe_stats(const struct efx_hw_stat_desc *desc, size_t count,
const unsigned long *mask, u8 *names)
{
size_t visible = 0;
size_t index;
for_each_set_bit(index, mask, count) {
if (desc[index].name) {
if (names) {
strlcpy(names, desc[index].name,
ETH_GSTRING_LEN);
names += ETH_GSTRING_LEN;
}
++visible;
}
}
return visible;
}
void efx_nic_update_stats(const struct efx_hw_stat_desc *desc, size_t count,
const unsigned long *mask,
u64 *stats, const void *dma_buf, bool accumulate)
{
size_t index;
for_each_set_bit(index, mask, count) {
if (desc[index].dma_width) {
const void *addr = dma_buf + desc[index].offset;
u64 val;
switch (desc[index].dma_width) {
case 16:
val = le16_to_cpup((__le16 *)addr);
break;
case 32:
val = le32_to_cpup((__le32 *)addr);
break;
case 64:
val = le64_to_cpup((__le64 *)addr);
break;
default:
WARN_ON(1);
val = 0;
break;
}
if (accumulate)
stats[index] += val;
else
stats[index] = val;
}
}
}
