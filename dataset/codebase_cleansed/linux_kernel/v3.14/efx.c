static int efx_check_disabled(struct efx_nic *efx)
{
if (efx->state == STATE_DISABLED || efx->state == STATE_RECOVERY) {
netif_err(efx, drv, efx->net_dev,
"device is disabled due to earlier errors\n");
return -EIO;
}
return 0;
}
static int efx_process_channel(struct efx_channel *channel, int budget)
{
int spent;
if (unlikely(!channel->enabled))
return 0;
spent = efx_nic_process_eventq(channel, budget);
if (spent && efx_channel_has_rx_queue(channel)) {
struct efx_rx_queue *rx_queue =
efx_channel_get_rx_queue(channel);
efx_rx_flush_packet(channel);
efx_fast_push_rx_descriptors(rx_queue, true);
}
return spent;
}
static int efx_poll(struct napi_struct *napi, int budget)
{
struct efx_channel *channel =
container_of(napi, struct efx_channel, napi_str);
struct efx_nic *efx = channel->efx;
int spent;
netif_vdbg(efx, intr, efx->net_dev,
"channel %d NAPI poll executing on CPU %d\n",
channel->channel, raw_smp_processor_id());
spent = efx_process_channel(channel, budget);
if (spent < budget) {
if (efx_channel_has_rx_queue(channel) &&
efx->irq_rx_adaptive &&
unlikely(++channel->irq_count == 1000)) {
if (unlikely(channel->irq_mod_score <
irq_adapt_low_thresh)) {
if (channel->irq_moderation > 1) {
channel->irq_moderation -= 1;
efx->type->push_irq_moderation(channel);
}
} else if (unlikely(channel->irq_mod_score >
irq_adapt_high_thresh)) {
if (channel->irq_moderation <
efx->irq_rx_moderation) {
channel->irq_moderation += 1;
efx->type->push_irq_moderation(channel);
}
}
channel->irq_count = 0;
channel->irq_mod_score = 0;
}
efx_filter_rfs_expire(channel);
napi_complete(napi);
efx_nic_eventq_read_ack(channel);
}
return spent;
}
static int efx_probe_eventq(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
unsigned long entries;
netif_dbg(efx, probe, efx->net_dev,
"chan %d create event queue\n", channel->channel);
entries = roundup_pow_of_two(efx->rxq_entries + efx->txq_entries + 128);
EFX_BUG_ON_PARANOID(entries > EFX_MAX_EVQ_SIZE);
channel->eventq_mask = max(entries, EFX_MIN_EVQ_SIZE) - 1;
return efx_nic_probe_eventq(channel);
}
static int efx_init_eventq(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
int rc;
EFX_WARN_ON_PARANOID(channel->eventq_init);
netif_dbg(efx, drv, efx->net_dev,
"chan %d init event queue\n", channel->channel);
rc = efx_nic_init_eventq(channel);
if (rc == 0) {
efx->type->push_irq_moderation(channel);
channel->eventq_read_ptr = 0;
channel->eventq_init = true;
}
return rc;
}
static void efx_start_eventq(struct efx_channel *channel)
{
netif_dbg(channel->efx, ifup, channel->efx->net_dev,
"chan %d start event queue\n", channel->channel);
channel->enabled = true;
smp_wmb();
napi_enable(&channel->napi_str);
efx_nic_eventq_read_ack(channel);
}
static void efx_stop_eventq(struct efx_channel *channel)
{
if (!channel->enabled)
return;
napi_disable(&channel->napi_str);
channel->enabled = false;
}
static void efx_fini_eventq(struct efx_channel *channel)
{
if (!channel->eventq_init)
return;
netif_dbg(channel->efx, drv, channel->efx->net_dev,
"chan %d fini event queue\n", channel->channel);
efx_nic_fini_eventq(channel);
channel->eventq_init = false;
}
static void efx_remove_eventq(struct efx_channel *channel)
{
netif_dbg(channel->efx, drv, channel->efx->net_dev,
"chan %d remove event queue\n", channel->channel);
efx_nic_remove_eventq(channel);
}
static struct efx_channel *
efx_alloc_channel(struct efx_nic *efx, int i, struct efx_channel *old_channel)
{
struct efx_channel *channel;
struct efx_rx_queue *rx_queue;
struct efx_tx_queue *tx_queue;
int j;
channel = kzalloc(sizeof(*channel), GFP_KERNEL);
if (!channel)
return NULL;
channel->efx = efx;
channel->channel = i;
channel->type = &efx_default_channel_type;
for (j = 0; j < EFX_TXQ_TYPES; j++) {
tx_queue = &channel->tx_queue[j];
tx_queue->efx = efx;
tx_queue->queue = i * EFX_TXQ_TYPES + j;
tx_queue->channel = channel;
}
rx_queue = &channel->rx_queue;
rx_queue->efx = efx;
setup_timer(&rx_queue->slow_fill, efx_rx_slow_fill,
(unsigned long)rx_queue);
return channel;
}
static struct efx_channel *
efx_copy_channel(const struct efx_channel *old_channel)
{
struct efx_channel *channel;
struct efx_rx_queue *rx_queue;
struct efx_tx_queue *tx_queue;
int j;
channel = kmalloc(sizeof(*channel), GFP_KERNEL);
if (!channel)
return NULL;
*channel = *old_channel;
channel->napi_dev = NULL;
memset(&channel->eventq, 0, sizeof(channel->eventq));
for (j = 0; j < EFX_TXQ_TYPES; j++) {
tx_queue = &channel->tx_queue[j];
if (tx_queue->channel)
tx_queue->channel = channel;
tx_queue->buffer = NULL;
memset(&tx_queue->txd, 0, sizeof(tx_queue->txd));
}
rx_queue = &channel->rx_queue;
rx_queue->buffer = NULL;
memset(&rx_queue->rxd, 0, sizeof(rx_queue->rxd));
setup_timer(&rx_queue->slow_fill, efx_rx_slow_fill,
(unsigned long)rx_queue);
return channel;
}
static int efx_probe_channel(struct efx_channel *channel)
{
struct efx_tx_queue *tx_queue;
struct efx_rx_queue *rx_queue;
int rc;
netif_dbg(channel->efx, probe, channel->efx->net_dev,
"creating channel %d\n", channel->channel);
rc = channel->type->pre_probe(channel);
if (rc)
goto fail;
rc = efx_probe_eventq(channel);
if (rc)
goto fail;
efx_for_each_channel_tx_queue(tx_queue, channel) {
rc = efx_probe_tx_queue(tx_queue);
if (rc)
goto fail;
}
efx_for_each_channel_rx_queue(rx_queue, channel) {
rc = efx_probe_rx_queue(rx_queue);
if (rc)
goto fail;
}
channel->n_rx_frm_trunc = 0;
return 0;
fail:
efx_remove_channel(channel);
return rc;
}
static void
efx_get_channel_name(struct efx_channel *channel, char *buf, size_t len)
{
struct efx_nic *efx = channel->efx;
const char *type;
int number;
number = channel->channel;
if (efx->tx_channel_offset == 0) {
type = "";
} else if (channel->channel < efx->tx_channel_offset) {
type = "-rx";
} else {
type = "-tx";
number -= efx->tx_channel_offset;
}
snprintf(buf, len, "%s%s-%d", efx->name, type, number);
}
static void efx_set_channel_names(struct efx_nic *efx)
{
struct efx_channel *channel;
efx_for_each_channel(channel, efx)
channel->type->get_name(channel,
efx->msi_context[channel->channel].name,
sizeof(efx->msi_context[0].name));
}
static int efx_probe_channels(struct efx_nic *efx)
{
struct efx_channel *channel;
int rc;
efx->next_buffer_table = 0;
efx_for_each_channel_rev(channel, efx) {
rc = efx_probe_channel(channel);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"failed to create channel %d\n",
channel->channel);
goto fail;
}
}
efx_set_channel_names(efx);
return 0;
fail:
efx_remove_channels(efx);
return rc;
}
static void efx_start_datapath(struct efx_nic *efx)
{
bool old_rx_scatter = efx->rx_scatter;
struct efx_tx_queue *tx_queue;
struct efx_rx_queue *rx_queue;
struct efx_channel *channel;
size_t rx_buf_len;
efx->rx_dma_len = (efx->rx_prefix_size +
EFX_MAX_FRAME_LEN(efx->net_dev->mtu) +
efx->type->rx_buffer_padding);
rx_buf_len = (sizeof(struct efx_rx_page_state) +
efx->rx_ip_align + efx->rx_dma_len);
if (rx_buf_len <= PAGE_SIZE) {
efx->rx_scatter = efx->type->always_rx_scatter;
efx->rx_buffer_order = 0;
} else if (efx->type->can_rx_scatter) {
BUILD_BUG_ON(EFX_RX_USR_BUF_SIZE % L1_CACHE_BYTES);
BUILD_BUG_ON(sizeof(struct efx_rx_page_state) +
2 * ALIGN(NET_IP_ALIGN + EFX_RX_USR_BUF_SIZE,
EFX_RX_BUF_ALIGNMENT) >
PAGE_SIZE);
efx->rx_scatter = true;
efx->rx_dma_len = EFX_RX_USR_BUF_SIZE;
efx->rx_buffer_order = 0;
} else {
efx->rx_scatter = false;
efx->rx_buffer_order = get_order(rx_buf_len);
}
efx_rx_config_page_split(efx);
if (efx->rx_buffer_order)
netif_dbg(efx, drv, efx->net_dev,
"RX buf len=%u; page order=%u batch=%u\n",
efx->rx_dma_len, efx->rx_buffer_order,
efx->rx_pages_per_batch);
else
netif_dbg(efx, drv, efx->net_dev,
"RX buf len=%u step=%u bpp=%u; page batch=%u\n",
efx->rx_dma_len, efx->rx_page_buf_step,
efx->rx_bufs_per_page, efx->rx_pages_per_batch);
if (efx->rx_scatter != old_rx_scatter)
efx->type->filter_update_rx_scatter(efx);
efx->txq_stop_thresh = efx->txq_entries - efx_tx_max_skb_descs(efx);
efx->txq_wake_thresh = efx->txq_stop_thresh / 2;
efx_for_each_channel(channel, efx) {
efx_for_each_channel_tx_queue(tx_queue, channel) {
efx_init_tx_queue(tx_queue);
atomic_inc(&efx->active_queues);
}
efx_for_each_channel_rx_queue(rx_queue, channel) {
efx_init_rx_queue(rx_queue);
atomic_inc(&efx->active_queues);
efx_stop_eventq(channel);
efx_fast_push_rx_descriptors(rx_queue, false);
efx_start_eventq(channel);
}
WARN_ON(channel->rx_pkt_n_frags);
}
efx_ptp_start_datapath(efx);
if (netif_device_present(efx->net_dev))
netif_tx_wake_all_queues(efx->net_dev);
}
static void efx_stop_datapath(struct efx_nic *efx)
{
struct efx_channel *channel;
struct efx_tx_queue *tx_queue;
struct efx_rx_queue *rx_queue;
int rc;
EFX_ASSERT_RESET_SERIALISED(efx);
BUG_ON(efx->port_enabled);
efx_ptp_stop_datapath(efx);
efx_for_each_channel(channel, efx) {
efx_for_each_channel_rx_queue(rx_queue, channel)
rx_queue->refill_enabled = false;
}
efx_for_each_channel(channel, efx) {
if (efx_channel_has_rx_queue(channel)) {
efx_stop_eventq(channel);
efx_start_eventq(channel);
}
}
rc = efx->type->fini_dmaq(efx);
if (rc && EFX_WORKAROUND_7803(efx)) {
netif_err(efx, drv, efx->net_dev,
"Resetting to recover from flush failure\n");
efx_schedule_reset(efx, RESET_TYPE_ALL);
} else if (rc) {
netif_err(efx, drv, efx->net_dev, "failed to flush queues\n");
} else {
netif_dbg(efx, drv, efx->net_dev,
"successfully flushed all queues\n");
}
efx_for_each_channel(channel, efx) {
efx_for_each_channel_rx_queue(rx_queue, channel)
efx_fini_rx_queue(rx_queue);
efx_for_each_possible_channel_tx_queue(tx_queue, channel)
efx_fini_tx_queue(tx_queue);
}
}
static void efx_remove_channel(struct efx_channel *channel)
{
struct efx_tx_queue *tx_queue;
struct efx_rx_queue *rx_queue;
netif_dbg(channel->efx, drv, channel->efx->net_dev,
"destroy chan %d\n", channel->channel);
efx_for_each_channel_rx_queue(rx_queue, channel)
efx_remove_rx_queue(rx_queue);
efx_for_each_possible_channel_tx_queue(tx_queue, channel)
efx_remove_tx_queue(tx_queue);
efx_remove_eventq(channel);
channel->type->post_remove(channel);
}
static void efx_remove_channels(struct efx_nic *efx)
{
struct efx_channel *channel;
efx_for_each_channel(channel, efx)
efx_remove_channel(channel);
}
int
efx_realloc_channels(struct efx_nic *efx, u32 rxq_entries, u32 txq_entries)
{
struct efx_channel *other_channel[EFX_MAX_CHANNELS], *channel;
u32 old_rxq_entries, old_txq_entries;
unsigned i, next_buffer_table = 0;
int rc, rc2;
rc = efx_check_disabled(efx);
if (rc)
return rc;
efx_for_each_channel(channel, efx) {
struct efx_rx_queue *rx_queue;
struct efx_tx_queue *tx_queue;
if (channel->type->copy)
continue;
next_buffer_table = max(next_buffer_table,
channel->eventq.index +
channel->eventq.entries);
efx_for_each_channel_rx_queue(rx_queue, channel)
next_buffer_table = max(next_buffer_table,
rx_queue->rxd.index +
rx_queue->rxd.entries);
efx_for_each_channel_tx_queue(tx_queue, channel)
next_buffer_table = max(next_buffer_table,
tx_queue->txd.index +
tx_queue->txd.entries);
}
efx_device_detach_sync(efx);
efx_stop_all(efx);
efx_soft_disable_interrupts(efx);
memset(other_channel, 0, sizeof(other_channel));
for (i = 0; i < efx->n_channels; i++) {
channel = efx->channel[i];
if (channel->type->copy)
channel = channel->type->copy(channel);
if (!channel) {
rc = -ENOMEM;
goto out;
}
other_channel[i] = channel;
}
old_rxq_entries = efx->rxq_entries;
old_txq_entries = efx->txq_entries;
efx->rxq_entries = rxq_entries;
efx->txq_entries = txq_entries;
for (i = 0; i < efx->n_channels; i++) {
channel = efx->channel[i];
efx->channel[i] = other_channel[i];
other_channel[i] = channel;
}
efx->next_buffer_table = next_buffer_table;
for (i = 0; i < efx->n_channels; i++) {
channel = efx->channel[i];
if (!channel->type->copy)
continue;
rc = efx_probe_channel(channel);
if (rc)
goto rollback;
efx_init_napi_channel(efx->channel[i]);
}
out:
for (i = 0; i < efx->n_channels; i++) {
channel = other_channel[i];
if (channel && channel->type->copy) {
efx_fini_napi_channel(channel);
efx_remove_channel(channel);
kfree(channel);
}
}
rc2 = efx_soft_enable_interrupts(efx);
if (rc2) {
rc = rc ? rc : rc2;
netif_err(efx, drv, efx->net_dev,
"unable to restart interrupts on channel reallocation\n");
efx_schedule_reset(efx, RESET_TYPE_DISABLE);
} else {
efx_start_all(efx);
netif_device_attach(efx->net_dev);
}
return rc;
rollback:
efx->rxq_entries = old_rxq_entries;
efx->txq_entries = old_txq_entries;
for (i = 0; i < efx->n_channels; i++) {
channel = efx->channel[i];
efx->channel[i] = other_channel[i];
other_channel[i] = channel;
}
goto out;
}
void efx_schedule_slow_fill(struct efx_rx_queue *rx_queue)
{
mod_timer(&rx_queue->slow_fill, jiffies + msecs_to_jiffies(100));
}
int efx_channel_dummy_op_int(struct efx_channel *channel)
{
return 0;
}
void efx_channel_dummy_op_void(struct efx_channel *channel)
{
}
void efx_link_status_changed(struct efx_nic *efx)
{
struct efx_link_state *link_state = &efx->link_state;
if (!netif_running(efx->net_dev))
return;
if (link_state->up != netif_carrier_ok(efx->net_dev)) {
efx->n_link_state_changes++;
if (link_state->up)
netif_carrier_on(efx->net_dev);
else
netif_carrier_off(efx->net_dev);
}
if (link_state->up)
netif_info(efx, link, efx->net_dev,
"link up at %uMbps %s-duplex (MTU %d)\n",
link_state->speed, link_state->fd ? "full" : "half",
efx->net_dev->mtu);
else
netif_info(efx, link, efx->net_dev, "link down\n");
}
void efx_link_set_advertising(struct efx_nic *efx, u32 advertising)
{
efx->link_advertising = advertising;
if (advertising) {
if (advertising & ADVERTISED_Pause)
efx->wanted_fc |= (EFX_FC_TX | EFX_FC_RX);
else
efx->wanted_fc &= ~(EFX_FC_TX | EFX_FC_RX);
if (advertising & ADVERTISED_Asym_Pause)
efx->wanted_fc ^= EFX_FC_TX;
}
}
void efx_link_set_wanted_fc(struct efx_nic *efx, u8 wanted_fc)
{
efx->wanted_fc = wanted_fc;
if (efx->link_advertising) {
if (wanted_fc & EFX_FC_RX)
efx->link_advertising |= (ADVERTISED_Pause |
ADVERTISED_Asym_Pause);
else
efx->link_advertising &= ~(ADVERTISED_Pause |
ADVERTISED_Asym_Pause);
if (wanted_fc & EFX_FC_TX)
efx->link_advertising ^= ADVERTISED_Asym_Pause;
}
}
int __efx_reconfigure_port(struct efx_nic *efx)
{
enum efx_phy_mode phy_mode;
int rc;
WARN_ON(!mutex_is_locked(&efx->mac_lock));
phy_mode = efx->phy_mode;
if (LOOPBACK_INTERNAL(efx))
efx->phy_mode |= PHY_MODE_TX_DISABLED;
else
efx->phy_mode &= ~PHY_MODE_TX_DISABLED;
rc = efx->type->reconfigure_port(efx);
if (rc)
efx->phy_mode = phy_mode;
return rc;
}
int efx_reconfigure_port(struct efx_nic *efx)
{
int rc;
EFX_ASSERT_RESET_SERIALISED(efx);
mutex_lock(&efx->mac_lock);
rc = __efx_reconfigure_port(efx);
mutex_unlock(&efx->mac_lock);
return rc;
}
static void efx_mac_work(struct work_struct *data)
{
struct efx_nic *efx = container_of(data, struct efx_nic, mac_work);
mutex_lock(&efx->mac_lock);
if (efx->port_enabled)
efx->type->reconfigure_mac(efx);
mutex_unlock(&efx->mac_lock);
}
static int efx_probe_port(struct efx_nic *efx)
{
int rc;
netif_dbg(efx, probe, efx->net_dev, "create port\n");
if (phy_flash_cfg)
efx->phy_mode = PHY_MODE_SPECIAL;
rc = efx->type->probe_port(efx);
if (rc)
return rc;
memcpy(efx->net_dev->dev_addr, efx->net_dev->perm_addr, ETH_ALEN);
return 0;
}
static int efx_init_port(struct efx_nic *efx)
{
int rc;
netif_dbg(efx, drv, efx->net_dev, "init port\n");
mutex_lock(&efx->mac_lock);
rc = efx->phy_op->init(efx);
if (rc)
goto fail1;
efx->port_initialized = true;
efx->type->reconfigure_mac(efx);
rc = efx->phy_op->reconfigure(efx);
if (rc)
goto fail2;
mutex_unlock(&efx->mac_lock);
return 0;
fail2:
efx->phy_op->fini(efx);
fail1:
mutex_unlock(&efx->mac_lock);
return rc;
}
static void efx_start_port(struct efx_nic *efx)
{
netif_dbg(efx, ifup, efx->net_dev, "start port\n");
BUG_ON(efx->port_enabled);
mutex_lock(&efx->mac_lock);
efx->port_enabled = true;
efx->type->reconfigure_mac(efx);
mutex_unlock(&efx->mac_lock);
}
static void efx_stop_port(struct efx_nic *efx)
{
netif_dbg(efx, ifdown, efx->net_dev, "stop port\n");
EFX_ASSERT_RESET_SERIALISED(efx);
mutex_lock(&efx->mac_lock);
efx->port_enabled = false;
mutex_unlock(&efx->mac_lock);
netif_addr_lock_bh(efx->net_dev);
netif_addr_unlock_bh(efx->net_dev);
cancel_delayed_work_sync(&efx->monitor_work);
efx_selftest_async_cancel(efx);
cancel_work_sync(&efx->mac_work);
}
static void efx_fini_port(struct efx_nic *efx)
{
netif_dbg(efx, drv, efx->net_dev, "shut down port\n");
if (!efx->port_initialized)
return;
efx->phy_op->fini(efx);
efx->port_initialized = false;
efx->link_state.up = false;
efx_link_status_changed(efx);
}
static void efx_remove_port(struct efx_nic *efx)
{
netif_dbg(efx, drv, efx->net_dev, "destroying port\n");
efx->type->remove_port(efx);
}
static bool efx_same_controller(struct efx_nic *left, struct efx_nic *right)
{
return left->type == right->type &&
left->vpd_sn && right->vpd_sn &&
!strcmp(left->vpd_sn, right->vpd_sn);
}
static void efx_associate(struct efx_nic *efx)
{
struct efx_nic *other, *next;
if (efx->primary == efx) {
netif_dbg(efx, probe, efx->net_dev, "adding to primary list\n");
list_add_tail(&efx->node, &efx_primary_list);
list_for_each_entry_safe(other, next, &efx_unassociated_list,
node) {
if (efx_same_controller(efx, other)) {
list_del(&other->node);
netif_dbg(other, probe, other->net_dev,
"moving to secondary list of %s %s\n",
pci_name(efx->pci_dev),
efx->net_dev->name);
list_add_tail(&other->node,
&efx->secondary_list);
other->primary = efx;
}
}
} else {
list_for_each_entry(other, &efx_primary_list, node) {
if (efx_same_controller(efx, other)) {
netif_dbg(efx, probe, efx->net_dev,
"adding to secondary list of %s %s\n",
pci_name(other->pci_dev),
other->net_dev->name);
list_add_tail(&efx->node,
&other->secondary_list);
efx->primary = other;
return;
}
}
netif_dbg(efx, probe, efx->net_dev,
"adding to unassociated list\n");
list_add_tail(&efx->node, &efx_unassociated_list);
}
}
static void efx_dissociate(struct efx_nic *efx)
{
struct efx_nic *other, *next;
list_del(&efx->node);
efx->primary = NULL;
list_for_each_entry_safe(other, next, &efx->secondary_list, node) {
list_del(&other->node);
netif_dbg(other, probe, other->net_dev,
"moving to unassociated list\n");
list_add_tail(&other->node, &efx_unassociated_list);
other->primary = NULL;
}
}
static int efx_init_io(struct efx_nic *efx)
{
struct pci_dev *pci_dev = efx->pci_dev;
dma_addr_t dma_mask = efx->type->max_dma_mask;
unsigned int mem_map_size = efx->type->mem_map_size(efx);
int rc;
netif_dbg(efx, probe, efx->net_dev, "initialising I/O\n");
rc = pci_enable_device(pci_dev);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"failed to enable PCI device\n");
goto fail1;
}
pci_set_master(pci_dev);
while (dma_mask > 0x7fffffffUL) {
if (dma_supported(&pci_dev->dev, dma_mask)) {
rc = dma_set_mask_and_coherent(&pci_dev->dev, dma_mask);
if (rc == 0)
break;
}
dma_mask >>= 1;
}
if (rc) {
netif_err(efx, probe, efx->net_dev,
"could not find a suitable DMA mask\n");
goto fail2;
}
netif_dbg(efx, probe, efx->net_dev,
"using DMA mask %llx\n", (unsigned long long) dma_mask);
efx->membase_phys = pci_resource_start(efx->pci_dev, EFX_MEM_BAR);
rc = pci_request_region(pci_dev, EFX_MEM_BAR, "sfc");
if (rc) {
netif_err(efx, probe, efx->net_dev,
"request for memory BAR failed\n");
rc = -EIO;
goto fail3;
}
efx->membase = ioremap_nocache(efx->membase_phys, mem_map_size);
if (!efx->membase) {
netif_err(efx, probe, efx->net_dev,
"could not map memory BAR at %llx+%x\n",
(unsigned long long)efx->membase_phys, mem_map_size);
rc = -ENOMEM;
goto fail4;
}
netif_dbg(efx, probe, efx->net_dev,
"memory BAR at %llx+%x (virtual %p)\n",
(unsigned long long)efx->membase_phys, mem_map_size,
efx->membase);
return 0;
fail4:
pci_release_region(efx->pci_dev, EFX_MEM_BAR);
fail3:
efx->membase_phys = 0;
fail2:
pci_disable_device(efx->pci_dev);
fail1:
return rc;
}
static void efx_fini_io(struct efx_nic *efx)
{
netif_dbg(efx, drv, efx->net_dev, "shutting down I/O\n");
if (efx->membase) {
iounmap(efx->membase);
efx->membase = NULL;
}
if (efx->membase_phys) {
pci_release_region(efx->pci_dev, EFX_MEM_BAR);
efx->membase_phys = 0;
}
pci_disable_device(efx->pci_dev);
}
static unsigned int efx_wanted_parallelism(struct efx_nic *efx)
{
cpumask_var_t thread_mask;
unsigned int count;
int cpu;
if (rss_cpus) {
count = rss_cpus;
} else {
if (unlikely(!zalloc_cpumask_var(&thread_mask, GFP_KERNEL))) {
netif_warn(efx, probe, efx->net_dev,
"RSS disabled due to allocation failure\n");
return 1;
}
count = 0;
for_each_online_cpu(cpu) {
if (!cpumask_test_cpu(cpu, thread_mask)) {
++count;
cpumask_or(thread_mask, thread_mask,
topology_thread_cpumask(cpu));
}
}
free_cpumask_var(thread_mask);
}
if (efx_sriov_wanted(efx) && efx_vf_size(efx) > 1 &&
count > efx_vf_size(efx)) {
netif_warn(efx, probe, efx->net_dev,
"Reducing number of RSS channels from %u to %u for "
"VF support. Increase vf-msix-limit to use more "
"channels on the PF.\n",
count, efx_vf_size(efx));
count = efx_vf_size(efx);
}
return count;
}
static int efx_probe_interrupts(struct efx_nic *efx)
{
unsigned int extra_channels = 0;
unsigned int i, j;
int rc;
for (i = 0; i < EFX_MAX_EXTRA_CHANNELS; i++)
if (efx->extra_channel_type[i])
++extra_channels;
if (efx->interrupt_mode == EFX_INT_MODE_MSIX) {
struct msix_entry xentries[EFX_MAX_CHANNELS];
unsigned int n_channels;
n_channels = efx_wanted_parallelism(efx);
if (separate_tx_channels)
n_channels *= 2;
n_channels += extra_channels;
n_channels = min(n_channels, efx->max_channels);
for (i = 0; i < n_channels; i++)
xentries[i].entry = i;
rc = pci_enable_msix(efx->pci_dev, xentries, n_channels);
if (rc > 0) {
netif_err(efx, drv, efx->net_dev,
"WARNING: Insufficient MSI-X vectors"
" available (%d < %u).\n", rc, n_channels);
netif_err(efx, drv, efx->net_dev,
"WARNING: Performance may be reduced.\n");
EFX_BUG_ON_PARANOID(rc >= n_channels);
n_channels = rc;
rc = pci_enable_msix(efx->pci_dev, xentries,
n_channels);
}
if (rc == 0) {
efx->n_channels = n_channels;
if (n_channels > extra_channels)
n_channels -= extra_channels;
if (separate_tx_channels) {
efx->n_tx_channels = max(n_channels / 2, 1U);
efx->n_rx_channels = max(n_channels -
efx->n_tx_channels,
1U);
} else {
efx->n_tx_channels = n_channels;
efx->n_rx_channels = n_channels;
}
for (i = 0; i < efx->n_channels; i++)
efx_get_channel(efx, i)->irq =
xentries[i].vector;
} else {
efx->interrupt_mode = EFX_INT_MODE_MSI;
netif_err(efx, drv, efx->net_dev,
"could not enable MSI-X\n");
}
}
if (efx->interrupt_mode == EFX_INT_MODE_MSI) {
efx->n_channels = 1;
efx->n_rx_channels = 1;
efx->n_tx_channels = 1;
rc = pci_enable_msi(efx->pci_dev);
if (rc == 0) {
efx_get_channel(efx, 0)->irq = efx->pci_dev->irq;
} else {
netif_err(efx, drv, efx->net_dev,
"could not enable MSI\n");
efx->interrupt_mode = EFX_INT_MODE_LEGACY;
}
}
if (efx->interrupt_mode == EFX_INT_MODE_LEGACY) {
efx->n_channels = 1 + (separate_tx_channels ? 1 : 0);
efx->n_rx_channels = 1;
efx->n_tx_channels = 1;
efx->legacy_irq = efx->pci_dev->irq;
}
j = efx->n_channels;
for (i = 0; i < EFX_MAX_EXTRA_CHANNELS; i++) {
if (!efx->extra_channel_type[i])
continue;
if (efx->interrupt_mode != EFX_INT_MODE_MSIX ||
efx->n_channels <= extra_channels) {
efx->extra_channel_type[i]->handle_no_channel(efx);
} else {
--j;
efx_get_channel(efx, j)->type =
efx->extra_channel_type[i];
}
}
efx->rss_spread = ((efx->n_rx_channels > 1 || !efx_sriov_wanted(efx)) ?
efx->n_rx_channels : efx_vf_size(efx));
return 0;
}
static int efx_soft_enable_interrupts(struct efx_nic *efx)
{
struct efx_channel *channel, *end_channel;
int rc;
BUG_ON(efx->state == STATE_DISABLED);
efx->irq_soft_enabled = true;
smp_wmb();
efx_for_each_channel(channel, efx) {
if (!channel->type->keep_eventq) {
rc = efx_init_eventq(channel);
if (rc)
goto fail;
}
efx_start_eventq(channel);
}
efx_mcdi_mode_event(efx);
return 0;
fail:
end_channel = channel;
efx_for_each_channel(channel, efx) {
if (channel == end_channel)
break;
efx_stop_eventq(channel);
if (!channel->type->keep_eventq)
efx_fini_eventq(channel);
}
return rc;
}
static void efx_soft_disable_interrupts(struct efx_nic *efx)
{
struct efx_channel *channel;
if (efx->state == STATE_DISABLED)
return;
efx_mcdi_mode_poll(efx);
efx->irq_soft_enabled = false;
smp_wmb();
if (efx->legacy_irq)
synchronize_irq(efx->legacy_irq);
efx_for_each_channel(channel, efx) {
if (channel->irq)
synchronize_irq(channel->irq);
efx_stop_eventq(channel);
if (!channel->type->keep_eventq)
efx_fini_eventq(channel);
}
efx_mcdi_flush_async(efx);
}
static int efx_enable_interrupts(struct efx_nic *efx)
{
struct efx_channel *channel, *end_channel;
int rc;
BUG_ON(efx->state == STATE_DISABLED);
if (efx->eeh_disabled_legacy_irq) {
enable_irq(efx->legacy_irq);
efx->eeh_disabled_legacy_irq = false;
}
efx->type->irq_enable_master(efx);
efx_for_each_channel(channel, efx) {
if (channel->type->keep_eventq) {
rc = efx_init_eventq(channel);
if (rc)
goto fail;
}
}
rc = efx_soft_enable_interrupts(efx);
if (rc)
goto fail;
return 0;
fail:
end_channel = channel;
efx_for_each_channel(channel, efx) {
if (channel == end_channel)
break;
if (channel->type->keep_eventq)
efx_fini_eventq(channel);
}
efx->type->irq_disable_non_ev(efx);
return rc;
}
static void efx_disable_interrupts(struct efx_nic *efx)
{
struct efx_channel *channel;
efx_soft_disable_interrupts(efx);
efx_for_each_channel(channel, efx) {
if (channel->type->keep_eventq)
efx_fini_eventq(channel);
}
efx->type->irq_disable_non_ev(efx);
}
static void efx_remove_interrupts(struct efx_nic *efx)
{
struct efx_channel *channel;
efx_for_each_channel(channel, efx)
channel->irq = 0;
pci_disable_msi(efx->pci_dev);
pci_disable_msix(efx->pci_dev);
efx->legacy_irq = 0;
}
static void efx_set_channels(struct efx_nic *efx)
{
struct efx_channel *channel;
struct efx_tx_queue *tx_queue;
efx->tx_channel_offset =
separate_tx_channels ? efx->n_channels - efx->n_tx_channels : 0;
efx_for_each_channel(channel, efx) {
if (channel->channel < efx->n_rx_channels)
channel->rx_queue.core_index = channel->channel;
else
channel->rx_queue.core_index = -1;
efx_for_each_channel_tx_queue(tx_queue, channel)
tx_queue->queue -= (efx->tx_channel_offset *
EFX_TXQ_TYPES);
}
}
static int efx_probe_nic(struct efx_nic *efx)
{
size_t i;
int rc;
netif_dbg(efx, probe, efx->net_dev, "creating NIC\n");
rc = efx->type->probe(efx);
if (rc)
return rc;
rc = efx_probe_interrupts(efx);
if (rc)
goto fail1;
rc = efx->type->dimension_resources(efx);
if (rc)
goto fail2;
if (efx->n_channels > 1)
get_random_bytes(&efx->rx_hash_key, sizeof(efx->rx_hash_key));
for (i = 0; i < ARRAY_SIZE(efx->rx_indir_table); i++)
efx->rx_indir_table[i] =
ethtool_rxfh_indir_default(i, efx->rss_spread);
efx_set_channels(efx);
netif_set_real_num_tx_queues(efx->net_dev, efx->n_tx_channels);
netif_set_real_num_rx_queues(efx->net_dev, efx->n_rx_channels);
efx_init_irq_moderation(efx, tx_irq_mod_usec, rx_irq_mod_usec, true,
true);
return 0;
fail2:
efx_remove_interrupts(efx);
fail1:
efx->type->remove(efx);
return rc;
}
static void efx_remove_nic(struct efx_nic *efx)
{
netif_dbg(efx, drv, efx->net_dev, "destroying NIC\n");
efx_remove_interrupts(efx);
efx->type->remove(efx);
}
static int efx_probe_filters(struct efx_nic *efx)
{
int rc;
spin_lock_init(&efx->filter_lock);
rc = efx->type->filter_table_probe(efx);
if (rc)
return rc;
#ifdef CONFIG_RFS_ACCEL
if (efx->type->offload_features & NETIF_F_NTUPLE) {
efx->rps_flow_id = kcalloc(efx->type->max_rx_ip_filters,
sizeof(*efx->rps_flow_id),
GFP_KERNEL);
if (!efx->rps_flow_id) {
efx->type->filter_table_remove(efx);
return -ENOMEM;
}
}
#endif
return 0;
}
static void efx_remove_filters(struct efx_nic *efx)
{
#ifdef CONFIG_RFS_ACCEL
kfree(efx->rps_flow_id);
#endif
efx->type->filter_table_remove(efx);
}
static void efx_restore_filters(struct efx_nic *efx)
{
efx->type->filter_table_restore(efx);
}
static int efx_probe_all(struct efx_nic *efx)
{
int rc;
rc = efx_probe_nic(efx);
if (rc) {
netif_err(efx, probe, efx->net_dev, "failed to create NIC\n");
goto fail1;
}
rc = efx_probe_port(efx);
if (rc) {
netif_err(efx, probe, efx->net_dev, "failed to create port\n");
goto fail2;
}
BUILD_BUG_ON(EFX_DEFAULT_DMAQ_SIZE < EFX_RXQ_MIN_ENT);
if (WARN_ON(EFX_DEFAULT_DMAQ_SIZE < EFX_TXQ_MIN_ENT(efx))) {
rc = -EINVAL;
goto fail3;
}
efx->rxq_entries = efx->txq_entries = EFX_DEFAULT_DMAQ_SIZE;
rc = efx_probe_filters(efx);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"failed to create filter tables\n");
goto fail3;
}
rc = efx_probe_channels(efx);
if (rc)
goto fail4;
return 0;
fail4:
efx_remove_filters(efx);
fail3:
efx_remove_port(efx);
fail2:
efx_remove_nic(efx);
fail1:
return rc;
}
static void efx_start_all(struct efx_nic *efx)
{
EFX_ASSERT_RESET_SERIALISED(efx);
BUG_ON(efx->state == STATE_DISABLED);
if (efx->port_enabled || !netif_running(efx->net_dev))
return;
efx_start_port(efx);
efx_start_datapath(efx);
if (efx->type->monitor != NULL)
queue_delayed_work(efx->workqueue, &efx->monitor_work,
efx_monitor_interval);
if (efx_nic_rev(efx) >= EFX_REV_SIENA_A0) {
mutex_lock(&efx->mac_lock);
if (efx->phy_op->poll(efx))
efx_link_status_changed(efx);
mutex_unlock(&efx->mac_lock);
}
efx->type->start_stats(efx);
efx->type->pull_stats(efx);
spin_lock_bh(&efx->stats_lock);
efx->type->update_stats(efx, NULL, NULL);
spin_unlock_bh(&efx->stats_lock);
}
static void efx_stop_all(struct efx_nic *efx)
{
EFX_ASSERT_RESET_SERIALISED(efx);
if (!efx->port_enabled)
return;
efx->type->pull_stats(efx);
spin_lock_bh(&efx->stats_lock);
efx->type->update_stats(efx, NULL, NULL);
spin_unlock_bh(&efx->stats_lock);
efx->type->stop_stats(efx);
efx_stop_port(efx);
WARN_ON(netif_running(efx->net_dev) &&
netif_device_present(efx->net_dev));
netif_tx_disable(efx->net_dev);
efx_stop_datapath(efx);
}
static void efx_remove_all(struct efx_nic *efx)
{
efx_remove_channels(efx);
efx_remove_filters(efx);
efx_remove_port(efx);
efx_remove_nic(efx);
}
static unsigned int irq_mod_ticks(unsigned int usecs, unsigned int quantum_ns)
{
if (usecs == 0)
return 0;
if (usecs * 1000 < quantum_ns)
return 1;
return usecs * 1000 / quantum_ns;
}
int efx_init_irq_moderation(struct efx_nic *efx, unsigned int tx_usecs,
unsigned int rx_usecs, bool rx_adaptive,
bool rx_may_override_tx)
{
struct efx_channel *channel;
unsigned int irq_mod_max = DIV_ROUND_UP(efx->type->timer_period_max *
efx->timer_quantum_ns,
1000);
unsigned int tx_ticks;
unsigned int rx_ticks;
EFX_ASSERT_RESET_SERIALISED(efx);
if (tx_usecs > irq_mod_max || rx_usecs > irq_mod_max)
return -EINVAL;
tx_ticks = irq_mod_ticks(tx_usecs, efx->timer_quantum_ns);
rx_ticks = irq_mod_ticks(rx_usecs, efx->timer_quantum_ns);
if (tx_ticks != rx_ticks && efx->tx_channel_offset == 0 &&
!rx_may_override_tx) {
netif_err(efx, drv, efx->net_dev, "Channels are shared. "
"RX and TX IRQ moderation must be equal\n");
return -EINVAL;
}
efx->irq_rx_adaptive = rx_adaptive;
efx->irq_rx_moderation = rx_ticks;
efx_for_each_channel(channel, efx) {
if (efx_channel_has_rx_queue(channel))
channel->irq_moderation = rx_ticks;
else if (efx_channel_has_tx_queues(channel))
channel->irq_moderation = tx_ticks;
}
return 0;
}
void efx_get_irq_moderation(struct efx_nic *efx, unsigned int *tx_usecs,
unsigned int *rx_usecs, bool *rx_adaptive)
{
*rx_adaptive = efx->irq_rx_adaptive;
*rx_usecs = DIV_ROUND_UP(efx->irq_rx_moderation *
efx->timer_quantum_ns,
1000);
if (efx->tx_channel_offset == 0)
*tx_usecs = *rx_usecs;
else
*tx_usecs = DIV_ROUND_UP(
efx->channel[efx->tx_channel_offset]->irq_moderation *
efx->timer_quantum_ns,
1000);
}
static void efx_monitor(struct work_struct *data)
{
struct efx_nic *efx = container_of(data, struct efx_nic,
monitor_work.work);
netif_vdbg(efx, timer, efx->net_dev,
"hardware monitor executing on CPU %d\n",
raw_smp_processor_id());
BUG_ON(efx->type->monitor == NULL);
if (mutex_trylock(&efx->mac_lock)) {
if (efx->port_enabled)
efx->type->monitor(efx);
mutex_unlock(&efx->mac_lock);
}
queue_delayed_work(efx->workqueue, &efx->monitor_work,
efx_monitor_interval);
}
static int efx_ioctl(struct net_device *net_dev, struct ifreq *ifr, int cmd)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct mii_ioctl_data *data = if_mii(ifr);
if (cmd == SIOCSHWTSTAMP)
return efx_ptp_set_ts_config(efx, ifr);
if (cmd == SIOCGHWTSTAMP)
return efx_ptp_get_ts_config(efx, ifr);
if ((cmd == SIOCGMIIREG || cmd == SIOCSMIIREG) &&
(data->phy_id & 0xfc00) == 0x0400)
data->phy_id ^= MDIO_PHY_ID_C45 | 0x0400;
return mdio_mii_ioctl(&efx->mdio, data, cmd);
}
static void efx_init_napi_channel(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
channel->napi_dev = efx->net_dev;
netif_napi_add(channel->napi_dev, &channel->napi_str,
efx_poll, napi_weight);
}
static void efx_init_napi(struct efx_nic *efx)
{
struct efx_channel *channel;
efx_for_each_channel(channel, efx)
efx_init_napi_channel(channel);
}
static void efx_fini_napi_channel(struct efx_channel *channel)
{
if (channel->napi_dev)
netif_napi_del(&channel->napi_str);
channel->napi_dev = NULL;
}
static void efx_fini_napi(struct efx_nic *efx)
{
struct efx_channel *channel;
efx_for_each_channel(channel, efx)
efx_fini_napi_channel(channel);
}
static void efx_netpoll(struct net_device *net_dev)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct efx_channel *channel;
efx_for_each_channel(channel, efx)
efx_schedule_channel(channel);
}
static int efx_net_open(struct net_device *net_dev)
{
struct efx_nic *efx = netdev_priv(net_dev);
int rc;
netif_dbg(efx, ifup, efx->net_dev, "opening device on CPU %d\n",
raw_smp_processor_id());
rc = efx_check_disabled(efx);
if (rc)
return rc;
if (efx->phy_mode & PHY_MODE_SPECIAL)
return -EBUSY;
if (efx_mcdi_poll_reboot(efx) && efx_reset(efx, RESET_TYPE_ALL))
return -EIO;
efx_link_status_changed(efx);
efx_start_all(efx);
efx_selftest_async_start(efx);
return 0;
}
static int efx_net_stop(struct net_device *net_dev)
{
struct efx_nic *efx = netdev_priv(net_dev);
netif_dbg(efx, ifdown, efx->net_dev, "closing on CPU %d\n",
raw_smp_processor_id());
efx_stop_all(efx);
return 0;
}
static struct rtnl_link_stats64 *efx_net_stats(struct net_device *net_dev,
struct rtnl_link_stats64 *stats)
{
struct efx_nic *efx = netdev_priv(net_dev);
spin_lock_bh(&efx->stats_lock);
efx->type->update_stats(efx, NULL, stats);
spin_unlock_bh(&efx->stats_lock);
return stats;
}
static void efx_watchdog(struct net_device *net_dev)
{
struct efx_nic *efx = netdev_priv(net_dev);
netif_err(efx, tx_err, efx->net_dev,
"TX stuck with port_enabled=%d: resetting channels\n",
efx->port_enabled);
efx_schedule_reset(efx, RESET_TYPE_TX_WATCHDOG);
}
static int efx_change_mtu(struct net_device *net_dev, int new_mtu)
{
struct efx_nic *efx = netdev_priv(net_dev);
int rc;
rc = efx_check_disabled(efx);
if (rc)
return rc;
if (new_mtu > EFX_MAX_MTU)
return -EINVAL;
netif_dbg(efx, drv, efx->net_dev, "changing MTU to %d\n", new_mtu);
efx_device_detach_sync(efx);
efx_stop_all(efx);
mutex_lock(&efx->mac_lock);
net_dev->mtu = new_mtu;
efx->type->reconfigure_mac(efx);
mutex_unlock(&efx->mac_lock);
efx_start_all(efx);
netif_device_attach(efx->net_dev);
return 0;
}
static int efx_set_mac_address(struct net_device *net_dev, void *data)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct sockaddr *addr = data;
char *new_addr = addr->sa_data;
if (!is_valid_ether_addr(new_addr)) {
netif_err(efx, drv, efx->net_dev,
"invalid ethernet MAC address requested: %pM\n",
new_addr);
return -EADDRNOTAVAIL;
}
memcpy(net_dev->dev_addr, new_addr, net_dev->addr_len);
efx_sriov_mac_address_changed(efx);
mutex_lock(&efx->mac_lock);
efx->type->reconfigure_mac(efx);
mutex_unlock(&efx->mac_lock);
return 0;
}
static void efx_set_rx_mode(struct net_device *net_dev)
{
struct efx_nic *efx = netdev_priv(net_dev);
if (efx->port_enabled)
queue_work(efx->workqueue, &efx->mac_work);
}
static int efx_set_features(struct net_device *net_dev, netdev_features_t data)
{
struct efx_nic *efx = netdev_priv(net_dev);
if (net_dev->features & ~data & NETIF_F_NTUPLE)
return efx->type->filter_clear_rx(efx, EFX_FILTER_PRI_MANUAL);
return 0;
}
static void efx_update_name(struct efx_nic *efx)
{
strcpy(efx->name, efx->net_dev->name);
efx_mtd_rename(efx);
efx_set_channel_names(efx);
}
static int efx_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *net_dev = netdev_notifier_info_to_dev(ptr);
if ((net_dev->netdev_ops == &efx_farch_netdev_ops ||
net_dev->netdev_ops == &efx_ef10_netdev_ops) &&
event == NETDEV_CHANGENAME)
efx_update_name(netdev_priv(net_dev));
return NOTIFY_DONE;
}
static ssize_t
show_phy_type(struct device *dev, struct device_attribute *attr, char *buf)
{
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
return sprintf(buf, "%d\n", efx->phy_type);
}
static int efx_register_netdev(struct efx_nic *efx)
{
struct net_device *net_dev = efx->net_dev;
struct efx_channel *channel;
int rc;
net_dev->watchdog_timeo = 5 * HZ;
net_dev->irq = efx->pci_dev->irq;
if (efx_nic_rev(efx) >= EFX_REV_HUNT_A0) {
net_dev->netdev_ops = &efx_ef10_netdev_ops;
net_dev->priv_flags |= IFF_UNICAST_FLT;
} else {
net_dev->netdev_ops = &efx_farch_netdev_ops;
}
SET_ETHTOOL_OPS(net_dev, &efx_ethtool_ops);
net_dev->gso_max_segs = EFX_TSO_MAX_SEGS;
rtnl_lock();
efx->state = STATE_READY;
smp_mb();
if (efx->reset_pending) {
netif_err(efx, probe, efx->net_dev,
"aborting probe due to scheduled reset\n");
rc = -EIO;
goto fail_locked;
}
rc = dev_alloc_name(net_dev, net_dev->name);
if (rc < 0)
goto fail_locked;
efx_update_name(efx);
netif_carrier_off(net_dev);
rc = register_netdevice(net_dev);
if (rc)
goto fail_locked;
efx_for_each_channel(channel, efx) {
struct efx_tx_queue *tx_queue;
efx_for_each_channel_tx_queue(tx_queue, channel)
efx_init_tx_queue_core_txq(tx_queue);
}
efx_associate(efx);
rtnl_unlock();
rc = device_create_file(&efx->pci_dev->dev, &dev_attr_phy_type);
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to init net dev attributes\n");
goto fail_registered;
}
return 0;
fail_registered:
rtnl_lock();
efx_dissociate(efx);
unregister_netdevice(net_dev);
fail_locked:
efx->state = STATE_UNINIT;
rtnl_unlock();
netif_err(efx, drv, efx->net_dev, "could not register net dev\n");
return rc;
}
static void efx_unregister_netdev(struct efx_nic *efx)
{
if (!efx->net_dev)
return;
BUG_ON(netdev_priv(efx->net_dev) != efx);
strlcpy(efx->name, pci_name(efx->pci_dev), sizeof(efx->name));
device_remove_file(&efx->pci_dev->dev, &dev_attr_phy_type);
rtnl_lock();
unregister_netdevice(efx->net_dev);
efx->state = STATE_UNINIT;
rtnl_unlock();
}
void efx_reset_down(struct efx_nic *efx, enum reset_type method)
{
EFX_ASSERT_RESET_SERIALISED(efx);
efx_stop_all(efx);
efx_disable_interrupts(efx);
mutex_lock(&efx->mac_lock);
if (efx->port_initialized && method != RESET_TYPE_INVISIBLE)
efx->phy_op->fini(efx);
efx->type->fini(efx);
}
int efx_reset_up(struct efx_nic *efx, enum reset_type method, bool ok)
{
int rc;
EFX_ASSERT_RESET_SERIALISED(efx);
rc = efx->type->init(efx);
if (rc) {
netif_err(efx, drv, efx->net_dev, "failed to initialise NIC\n");
goto fail;
}
if (!ok)
goto fail;
if (efx->port_initialized && method != RESET_TYPE_INVISIBLE) {
rc = efx->phy_op->init(efx);
if (rc)
goto fail;
if (efx->phy_op->reconfigure(efx))
netif_err(efx, drv, efx->net_dev,
"could not restore PHY settings\n");
}
rc = efx_enable_interrupts(efx);
if (rc)
goto fail;
efx_restore_filters(efx);
efx_sriov_reset(efx);
mutex_unlock(&efx->mac_lock);
efx_start_all(efx);
return 0;
fail:
efx->port_initialized = false;
mutex_unlock(&efx->mac_lock);
return rc;
}
int efx_reset(struct efx_nic *efx, enum reset_type method)
{
int rc, rc2;
bool disabled;
netif_info(efx, drv, efx->net_dev, "resetting (%s)\n",
RESET_TYPE(method));
efx_device_detach_sync(efx);
efx_reset_down(efx, method);
rc = efx->type->reset(efx, method);
if (rc) {
netif_err(efx, drv, efx->net_dev, "failed to reset hardware\n");
goto out;
}
efx->reset_pending &= -(1 << (method + 1));
pci_set_master(efx->pci_dev);
out:
disabled = rc ||
method == RESET_TYPE_DISABLE ||
method == RESET_TYPE_RECOVER_OR_DISABLE;
rc2 = efx_reset_up(efx, method, !disabled);
if (rc2) {
disabled = true;
if (!rc)
rc = rc2;
}
if (disabled) {
dev_close(efx->net_dev);
netif_err(efx, drv, efx->net_dev, "has been disabled\n");
efx->state = STATE_DISABLED;
} else {
netif_dbg(efx, drv, efx->net_dev, "reset complete\n");
netif_device_attach(efx->net_dev);
}
return rc;
}
int efx_try_recovery(struct efx_nic *efx)
{
#ifdef CONFIG_EEH
struct eeh_dev *eehdev =
of_node_to_eeh_dev(pci_device_to_OF_node(efx->pci_dev));
if (eeh_dev_check_failure(eehdev)) {
return 1;
}
#endif
return 0;
}
static void efx_wait_for_bist_end(struct efx_nic *efx)
{
int i;
for (i = 0; i < BIST_WAIT_DELAY_COUNT; ++i) {
if (efx_mcdi_poll_reboot(efx))
goto out;
msleep(BIST_WAIT_DELAY_MS);
}
netif_err(efx, drv, efx->net_dev, "Warning: No MC reboot after BIST mode\n");
out:
efx->mc_bist_for_other_fn = false;
}
static void efx_reset_work(struct work_struct *data)
{
struct efx_nic *efx = container_of(data, struct efx_nic, reset_work);
unsigned long pending;
enum reset_type method;
pending = ACCESS_ONCE(efx->reset_pending);
method = fls(pending) - 1;
if (method == RESET_TYPE_MC_BIST)
efx_wait_for_bist_end(efx);
if ((method == RESET_TYPE_RECOVER_OR_DISABLE ||
method == RESET_TYPE_RECOVER_OR_ALL) &&
efx_try_recovery(efx))
return;
if (!pending)
return;
rtnl_lock();
if (efx->state == STATE_READY)
(void)efx_reset(efx, method);
rtnl_unlock();
}
void efx_schedule_reset(struct efx_nic *efx, enum reset_type type)
{
enum reset_type method;
if (efx->state == STATE_RECOVERY) {
netif_dbg(efx, drv, efx->net_dev,
"recovering: skip scheduling %s reset\n",
RESET_TYPE(type));
return;
}
switch (type) {
case RESET_TYPE_INVISIBLE:
case RESET_TYPE_ALL:
case RESET_TYPE_RECOVER_OR_ALL:
case RESET_TYPE_WORLD:
case RESET_TYPE_DISABLE:
case RESET_TYPE_RECOVER_OR_DISABLE:
case RESET_TYPE_MC_BIST:
method = type;
netif_dbg(efx, drv, efx->net_dev, "scheduling %s reset\n",
RESET_TYPE(method));
break;
default:
method = efx->type->map_reset_reason(type);
netif_dbg(efx, drv, efx->net_dev,
"scheduling %s reset for %s\n",
RESET_TYPE(method), RESET_TYPE(type));
break;
}
set_bit(method, &efx->reset_pending);
smp_mb();
if (ACCESS_ONCE(efx->state) != STATE_READY)
return;
efx_mcdi_mode_poll(efx);
queue_work(reset_workqueue, &efx->reset_work);
}
int efx_port_dummy_op_int(struct efx_nic *efx)
{
return 0;
}
void efx_port_dummy_op_void(struct efx_nic *efx) {}
static bool efx_port_dummy_op_poll(struct efx_nic *efx)
{
return false;
}
static int efx_init_struct(struct efx_nic *efx,
struct pci_dev *pci_dev, struct net_device *net_dev)
{
int i;
INIT_LIST_HEAD(&efx->node);
INIT_LIST_HEAD(&efx->secondary_list);
spin_lock_init(&efx->biu_lock);
#ifdef CONFIG_SFC_MTD
INIT_LIST_HEAD(&efx->mtd_list);
#endif
INIT_WORK(&efx->reset_work, efx_reset_work);
INIT_DELAYED_WORK(&efx->monitor_work, efx_monitor);
INIT_DELAYED_WORK(&efx->selftest_work, efx_selftest_async_work);
efx->pci_dev = pci_dev;
efx->msg_enable = debug;
efx->state = STATE_UNINIT;
strlcpy(efx->name, pci_name(pci_dev), sizeof(efx->name));
efx->net_dev = net_dev;
efx->rx_prefix_size = efx->type->rx_prefix_size;
efx->rx_ip_align =
NET_IP_ALIGN ? (efx->rx_prefix_size + NET_IP_ALIGN) % 4 : 0;
efx->rx_packet_hash_offset =
efx->type->rx_hash_offset - efx->type->rx_prefix_size;
efx->rx_packet_ts_offset =
efx->type->rx_ts_offset - efx->type->rx_prefix_size;
spin_lock_init(&efx->stats_lock);
mutex_init(&efx->mac_lock);
efx->phy_op = &efx_dummy_phy_operations;
efx->mdio.dev = net_dev;
INIT_WORK(&efx->mac_work, efx_mac_work);
init_waitqueue_head(&efx->flush_wq);
for (i = 0; i < EFX_MAX_CHANNELS; i++) {
efx->channel[i] = efx_alloc_channel(efx, i, NULL);
if (!efx->channel[i])
goto fail;
efx->msi_context[i].efx = efx;
efx->msi_context[i].index = i;
}
efx->interrupt_mode = max(efx->type->max_interrupt_mode,
interrupt_mode);
snprintf(efx->workqueue_name, sizeof(efx->workqueue_name), "sfc%s",
pci_name(pci_dev));
efx->workqueue = create_singlethread_workqueue(efx->workqueue_name);
if (!efx->workqueue)
goto fail;
return 0;
fail:
efx_fini_struct(efx);
return -ENOMEM;
}
static void efx_fini_struct(struct efx_nic *efx)
{
int i;
for (i = 0; i < EFX_MAX_CHANNELS; i++)
kfree(efx->channel[i]);
kfree(efx->vpd_sn);
if (efx->workqueue) {
destroy_workqueue(efx->workqueue);
efx->workqueue = NULL;
}
}
static void efx_pci_remove_main(struct efx_nic *efx)
{
BUG_ON(efx->state == STATE_READY);
cancel_work_sync(&efx->reset_work);
efx_disable_interrupts(efx);
efx_nic_fini_interrupt(efx);
efx_fini_port(efx);
efx->type->fini(efx);
efx_fini_napi(efx);
efx_remove_all(efx);
}
static void efx_pci_remove(struct pci_dev *pci_dev)
{
struct efx_nic *efx;
efx = pci_get_drvdata(pci_dev);
if (!efx)
return;
rtnl_lock();
efx_dissociate(efx);
dev_close(efx->net_dev);
efx_disable_interrupts(efx);
rtnl_unlock();
efx_sriov_fini(efx);
efx_unregister_netdev(efx);
efx_mtd_remove(efx);
efx_pci_remove_main(efx);
efx_fini_io(efx);
netif_dbg(efx, drv, efx->net_dev, "shutdown successful\n");
efx_fini_struct(efx);
free_netdev(efx->net_dev);
pci_disable_pcie_error_reporting(pci_dev);
}
static void efx_probe_vpd_strings(struct efx_nic *efx)
{
struct pci_dev *dev = efx->pci_dev;
char vpd_data[SFC_VPD_LEN];
ssize_t vpd_size;
int ro_start, ro_size, i, j;
vpd_size = pci_read_vpd(dev, 0, sizeof(vpd_data), vpd_data);
if (vpd_size <= 0) {
netif_err(efx, drv, efx->net_dev, "Unable to read VPD\n");
return;
}
ro_start = pci_vpd_find_tag(vpd_data, 0, vpd_size, PCI_VPD_LRDT_RO_DATA);
if (ro_start < 0) {
netif_err(efx, drv, efx->net_dev, "VPD Read-only not found\n");
return;
}
ro_size = pci_vpd_lrdt_size(&vpd_data[ro_start]);
j = ro_size;
i = ro_start + PCI_VPD_LRDT_TAG_SIZE;
if (i + j > vpd_size)
j = vpd_size - i;
i = pci_vpd_find_info_keyword(vpd_data, i, j, "PN");
if (i < 0) {
netif_err(efx, drv, efx->net_dev, "Part number not found\n");
return;
}
j = pci_vpd_info_field_size(&vpd_data[i]);
i += PCI_VPD_INFO_FLD_HDR_SIZE;
if (i + j > vpd_size) {
netif_err(efx, drv, efx->net_dev, "Incomplete part number\n");
return;
}
netif_info(efx, drv, efx->net_dev,
"Part Number : %.*s\n", j, &vpd_data[i]);
i = ro_start + PCI_VPD_LRDT_TAG_SIZE;
j = ro_size;
i = pci_vpd_find_info_keyword(vpd_data, i, j, "SN");
if (i < 0) {
netif_err(efx, drv, efx->net_dev, "Serial number not found\n");
return;
}
j = pci_vpd_info_field_size(&vpd_data[i]);
i += PCI_VPD_INFO_FLD_HDR_SIZE;
if (i + j > vpd_size) {
netif_err(efx, drv, efx->net_dev, "Incomplete serial number\n");
return;
}
efx->vpd_sn = kmalloc(j + 1, GFP_KERNEL);
if (!efx->vpd_sn)
return;
snprintf(efx->vpd_sn, j + 1, "%s", &vpd_data[i]);
}
static int efx_pci_probe_main(struct efx_nic *efx)
{
int rc;
rc = efx_probe_all(efx);
if (rc)
goto fail1;
efx_init_napi(efx);
rc = efx->type->init(efx);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"failed to initialise NIC\n");
goto fail3;
}
rc = efx_init_port(efx);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"failed to initialise port\n");
goto fail4;
}
rc = efx_nic_init_interrupt(efx);
if (rc)
goto fail5;
rc = efx_enable_interrupts(efx);
if (rc)
goto fail6;
return 0;
fail6:
efx_nic_fini_interrupt(efx);
fail5:
efx_fini_port(efx);
fail4:
efx->type->fini(efx);
fail3:
efx_fini_napi(efx);
efx_remove_all(efx);
fail1:
return rc;
}
static int efx_pci_probe(struct pci_dev *pci_dev,
const struct pci_device_id *entry)
{
struct net_device *net_dev;
struct efx_nic *efx;
int rc;
net_dev = alloc_etherdev_mqs(sizeof(*efx), EFX_MAX_CORE_TX_QUEUES,
EFX_MAX_RX_QUEUES);
if (!net_dev)
return -ENOMEM;
efx = netdev_priv(net_dev);
efx->type = (const struct efx_nic_type *) entry->driver_data;
net_dev->features |= (efx->type->offload_features | NETIF_F_SG |
NETIF_F_HIGHDMA | NETIF_F_TSO |
NETIF_F_RXCSUM);
if (efx->type->offload_features & NETIF_F_V6_CSUM)
net_dev->features |= NETIF_F_TSO6;
net_dev->vlan_features |= (NETIF_F_ALL_CSUM | NETIF_F_SG |
NETIF_F_HIGHDMA | NETIF_F_ALL_TSO |
NETIF_F_RXCSUM);
net_dev->hw_features = net_dev->features & ~NETIF_F_HIGHDMA;
pci_set_drvdata(pci_dev, efx);
SET_NETDEV_DEV(net_dev, &pci_dev->dev);
rc = efx_init_struct(efx, pci_dev, net_dev);
if (rc)
goto fail1;
netif_info(efx, probe, efx->net_dev,
"Solarflare NIC detected\n");
efx_probe_vpd_strings(efx);
rc = efx_init_io(efx);
if (rc)
goto fail2;
rc = efx_pci_probe_main(efx);
if (rc)
goto fail3;
rc = efx_register_netdev(efx);
if (rc)
goto fail4;
rc = efx_sriov_init(efx);
if (rc)
netif_err(efx, probe, efx->net_dev,
"SR-IOV can't be enabled rc %d\n", rc);
netif_dbg(efx, probe, efx->net_dev, "initialisation successful\n");
rtnl_lock();
rc = efx_mtd_probe(efx);
rtnl_unlock();
if (rc)
netif_warn(efx, probe, efx->net_dev,
"failed to create MTDs (%d)\n", rc);
rc = pci_enable_pcie_error_reporting(pci_dev);
if (rc && rc != -EINVAL)
netif_warn(efx, probe, efx->net_dev,
"pci_enable_pcie_error_reporting failed (%d)\n", rc);
return 0;
fail4:
efx_pci_remove_main(efx);
fail3:
efx_fini_io(efx);
fail2:
efx_fini_struct(efx);
fail1:
WARN_ON(rc > 0);
netif_dbg(efx, drv, efx->net_dev, "initialisation failed. rc=%d\n", rc);
free_netdev(net_dev);
return rc;
}
static int efx_pm_freeze(struct device *dev)
{
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
rtnl_lock();
if (efx->state != STATE_DISABLED) {
efx->state = STATE_UNINIT;
efx_device_detach_sync(efx);
efx_stop_all(efx);
efx_disable_interrupts(efx);
}
rtnl_unlock();
return 0;
}
static int efx_pm_thaw(struct device *dev)
{
int rc;
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
rtnl_lock();
if (efx->state != STATE_DISABLED) {
rc = efx_enable_interrupts(efx);
if (rc)
goto fail;
mutex_lock(&efx->mac_lock);
efx->phy_op->reconfigure(efx);
mutex_unlock(&efx->mac_lock);
efx_start_all(efx);
netif_device_attach(efx->net_dev);
efx->state = STATE_READY;
efx->type->resume_wol(efx);
}
rtnl_unlock();
queue_work(reset_workqueue, &efx->reset_work);
return 0;
fail:
rtnl_unlock();
return rc;
}
static int efx_pm_poweroff(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct efx_nic *efx = pci_get_drvdata(pci_dev);
efx->type->fini(efx);
efx->reset_pending = 0;
pci_save_state(pci_dev);
return pci_set_power_state(pci_dev, PCI_D3hot);
}
static int efx_pm_resume(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct efx_nic *efx = pci_get_drvdata(pci_dev);
int rc;
rc = pci_set_power_state(pci_dev, PCI_D0);
if (rc)
return rc;
pci_restore_state(pci_dev);
rc = pci_enable_device(pci_dev);
if (rc)
return rc;
pci_set_master(efx->pci_dev);
rc = efx->type->reset(efx, RESET_TYPE_ALL);
if (rc)
return rc;
rc = efx->type->init(efx);
if (rc)
return rc;
rc = efx_pm_thaw(dev);
return rc;
}
static int efx_pm_suspend(struct device *dev)
{
int rc;
efx_pm_freeze(dev);
rc = efx_pm_poweroff(dev);
if (rc)
efx_pm_resume(dev);
return rc;
}
static pci_ers_result_t efx_io_error_detected(struct pci_dev *pdev,
enum pci_channel_state state)
{
pci_ers_result_t status = PCI_ERS_RESULT_RECOVERED;
struct efx_nic *efx = pci_get_drvdata(pdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
rtnl_lock();
if (efx->state != STATE_DISABLED) {
efx->state = STATE_RECOVERY;
efx->reset_pending = 0;
efx_device_detach_sync(efx);
efx_stop_all(efx);
efx_disable_interrupts(efx);
status = PCI_ERS_RESULT_NEED_RESET;
} else {
status = PCI_ERS_RESULT_RECOVERED;
}
rtnl_unlock();
pci_disable_device(pdev);
return status;
}
static pci_ers_result_t efx_io_slot_reset(struct pci_dev *pdev)
{
struct efx_nic *efx = pci_get_drvdata(pdev);
pci_ers_result_t status = PCI_ERS_RESULT_RECOVERED;
int rc;
if (pci_enable_device(pdev)) {
netif_err(efx, hw, efx->net_dev,
"Cannot re-enable PCI device after reset.\n");
status = PCI_ERS_RESULT_DISCONNECT;
}
rc = pci_cleanup_aer_uncorrect_error_status(pdev);
if (rc) {
netif_err(efx, hw, efx->net_dev,
"pci_cleanup_aer_uncorrect_error_status failed (%d)\n", rc);
}
return status;
}
static void efx_io_resume(struct pci_dev *pdev)
{
struct efx_nic *efx = pci_get_drvdata(pdev);
int rc;
rtnl_lock();
if (efx->state == STATE_DISABLED)
goto out;
rc = efx_reset(efx, RESET_TYPE_ALL);
if (rc) {
netif_err(efx, hw, efx->net_dev,
"efx_reset failed after PCI error (%d)\n", rc);
} else {
efx->state = STATE_READY;
netif_dbg(efx, hw, efx->net_dev,
"Done resetting and resuming IO after PCI error.\n");
}
out:
rtnl_unlock();
}
static int __init efx_init_module(void)
{
int rc;
printk(KERN_INFO "Solarflare NET driver v" EFX_DRIVER_VERSION "\n");
rc = register_netdevice_notifier(&efx_netdev_notifier);
if (rc)
goto err_notifier;
rc = efx_init_sriov();
if (rc)
goto err_sriov;
reset_workqueue = create_singlethread_workqueue("sfc_reset");
if (!reset_workqueue) {
rc = -ENOMEM;
goto err_reset;
}
rc = pci_register_driver(&efx_pci_driver);
if (rc < 0)
goto err_pci;
return 0;
err_pci:
destroy_workqueue(reset_workqueue);
err_reset:
efx_fini_sriov();
err_sriov:
unregister_netdevice_notifier(&efx_netdev_notifier);
err_notifier:
return rc;
}
static void __exit efx_exit_module(void)
{
printk(KERN_INFO "Solarflare NET driver unloading\n");
pci_unregister_driver(&efx_pci_driver);
destroy_workqueue(reset_workqueue);
efx_fini_sriov();
unregister_netdevice_notifier(&efx_netdev_notifier);
}
