static void siena_push_irq_moderation(struct efx_channel *channel)
{
efx_dword_t timer_cmd;
if (channel->irq_moderation)
EFX_POPULATE_DWORD_2(timer_cmd,
FRF_CZ_TC_TIMER_MODE,
FFE_CZ_TIMER_MODE_INT_HLDOFF,
FRF_CZ_TC_TIMER_VAL,
channel->irq_moderation - 1);
else
EFX_POPULATE_DWORD_2(timer_cmd,
FRF_CZ_TC_TIMER_MODE,
FFE_CZ_TIMER_MODE_DIS,
FRF_CZ_TC_TIMER_VAL, 0);
efx_writed_page_locked(channel->efx, &timer_cmd, FR_BZ_TIMER_COMMAND_P0,
channel->channel);
}
static int siena_mdio_write(struct net_device *net_dev,
int prtad, int devad, u16 addr, u16 value)
{
struct efx_nic *efx = netdev_priv(net_dev);
uint32_t status;
int rc;
rc = efx_mcdi_mdio_write(efx, efx->mdio_bus, prtad, devad,
addr, value, &status);
if (rc)
return rc;
if (status != MC_CMD_MDIO_STATUS_GOOD)
return -EIO;
return 0;
}
static int siena_mdio_read(struct net_device *net_dev,
int prtad, int devad, u16 addr)
{
struct efx_nic *efx = netdev_priv(net_dev);
uint16_t value;
uint32_t status;
int rc;
rc = efx_mcdi_mdio_read(efx, efx->mdio_bus, prtad, devad,
addr, &value, &status);
if (rc)
return rc;
if (status != MC_CMD_MDIO_STATUS_GOOD)
return -EIO;
return (int)value;
}
static int siena_probe_port(struct efx_nic *efx)
{
int rc;
efx->phy_op = &efx_mcdi_phy_ops;
efx->mdio.mode_support = MDIO_SUPPORTS_C45 | MDIO_EMULATE_C22;
efx->mdio.mdio_read = siena_mdio_read;
efx->mdio.mdio_write = siena_mdio_write;
rc = efx->phy_op->probe(efx);
if (rc != 0)
return rc;
rc = efx_nic_alloc_buffer(efx, &efx->stats_buffer,
MC_CMD_MAC_NSTATS * sizeof(u64));
if (rc)
return rc;
netif_dbg(efx, probe, efx->net_dev,
"stats buffer at %llx (virt %p phys %llx)\n",
(u64)efx->stats_buffer.dma_addr,
efx->stats_buffer.addr,
(u64)virt_to_phys(efx->stats_buffer.addr));
efx_mcdi_mac_stats(efx, efx->stats_buffer.dma_addr, 0, 0, 1);
return 0;
}
static void siena_remove_port(struct efx_nic *efx)
{
efx->phy_op->remove(efx);
efx_nic_free_buffer(efx, &efx->stats_buffer);
}
static int siena_test_chip(struct efx_nic *efx, struct efx_self_tests *tests)
{
enum reset_type reset_method = reset_method;
int rc, rc2;
efx_reset_down(efx, reset_method);
rc = siena_reset_hw(efx, reset_method);
if (rc)
goto out;
tests->registers =
efx_nic_test_registers(efx, siena_register_tests,
ARRAY_SIZE(siena_register_tests))
? -1 : 1;
rc = siena_reset_hw(efx, reset_method);
out:
rc2 = efx_reset_up(efx, reset_method, rc == 0);
return rc ? rc : rc2;
}
static enum reset_type siena_map_reset_reason(enum reset_type reason)
{
return RESET_TYPE_ALL;
}
static int siena_map_reset_flags(u32 *flags)
{
enum {
SIENA_RESET_PORT = (ETH_RESET_DMA | ETH_RESET_FILTER |
ETH_RESET_OFFLOAD | ETH_RESET_MAC |
ETH_RESET_PHY),
SIENA_RESET_MC = (SIENA_RESET_PORT |
ETH_RESET_MGMT << ETH_RESET_SHARED_SHIFT),
};
if ((*flags & SIENA_RESET_MC) == SIENA_RESET_MC) {
*flags &= ~SIENA_RESET_MC;
return RESET_TYPE_WORLD;
}
if ((*flags & SIENA_RESET_PORT) == SIENA_RESET_PORT) {
*flags &= ~SIENA_RESET_PORT;
return RESET_TYPE_ALL;
}
return -EINVAL;
}
static int siena_reset_hw(struct efx_nic *efx, enum reset_type method)
{
int rc;
rc = efx_mcdi_handle_assertion(efx);
if (rc)
return rc;
if (method == RESET_TYPE_WORLD)
return efx_mcdi_reset_mc(efx);
else
return efx_mcdi_reset_port(efx);
}
static int siena_probe_nvconfig(struct efx_nic *efx)
{
u32 caps = 0;
int rc;
rc = efx_mcdi_get_board_cfg(efx, efx->net_dev->perm_addr, NULL, &caps);
efx->timer_quantum_ns =
(caps & (1 << MC_CMD_CAPABILITIES_TURBO_ACTIVE_LBN)) ?
3072 : 6144;
return rc;
}
static void siena_dimension_resources(struct efx_nic *efx)
{
efx_nic_dimension_resources(efx, FR_CZ_BUF_FULL_TBL_ROWS / 2);
}
static int siena_probe_nic(struct efx_nic *efx)
{
struct siena_nic_data *nic_data;
bool already_attached = false;
efx_oword_t reg;
int rc;
nic_data = kzalloc(sizeof(struct siena_nic_data), GFP_KERNEL);
if (!nic_data)
return -ENOMEM;
efx->nic_data = nic_data;
if (efx_nic_fpga_ver(efx) != 0) {
netif_err(efx, probe, efx->net_dev,
"Siena FPGA not supported\n");
rc = -ENODEV;
goto fail1;
}
efx_reado(efx, &reg, FR_AZ_CS_DEBUG);
efx->net_dev->dev_id = EFX_OWORD_FIELD(reg, FRF_CZ_CS_PORT_NUM) - 1;
efx_mcdi_init(efx);
rc = efx_mcdi_handle_assertion(efx);
if (rc)
goto fail1;
rc = efx_mcdi_drv_attach(efx, true, &already_attached);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"Unable to register driver with MCPU\n");
goto fail2;
}
if (already_attached)
netif_err(efx, probe, efx->net_dev,
"Host already registered with MCPU\n");
rc = siena_reset_hw(efx, RESET_TYPE_ALL);
if (rc) {
netif_err(efx, probe, efx->net_dev, "failed to reset NIC\n");
goto fail3;
}
siena_init_wol(efx);
rc = efx_nic_alloc_buffer(efx, &efx->irq_status, sizeof(efx_oword_t));
if (rc)
goto fail4;
BUG_ON(efx->irq_status.dma_addr & 0x0f);
netif_dbg(efx, probe, efx->net_dev,
"INT_KER at %llx (virt %p phys %llx)\n",
(unsigned long long)efx->irq_status.dma_addr,
efx->irq_status.addr,
(unsigned long long)virt_to_phys(efx->irq_status.addr));
rc = siena_probe_nvconfig(efx);
if (rc == -EINVAL) {
netif_err(efx, probe, efx->net_dev,
"NVRAM is invalid therefore using defaults\n");
efx->phy_type = PHY_TYPE_NONE;
efx->mdio.prtad = MDIO_PRTAD_NONE;
} else if (rc) {
goto fail5;
}
rc = efx_mcdi_mon_probe(efx);
if (rc)
goto fail5;
efx_sriov_probe(efx);
return 0;
fail5:
efx_nic_free_buffer(efx, &efx->irq_status);
fail4:
fail3:
efx_mcdi_drv_attach(efx, false, NULL);
fail2:
fail1:
kfree(efx->nic_data);
return rc;
}
static int siena_init_nic(struct efx_nic *efx)
{
efx_oword_t temp;
int rc;
rc = efx_mcdi_handle_assertion(efx);
if (rc)
return rc;
efx_reado(efx, &temp, FR_AZ_TX_RESERVED);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_TX_FLUSH_MIN_LEN_EN, 1);
efx_writeo(efx, &temp, FR_AZ_TX_RESERVED);
efx_reado(efx, &temp, FR_AZ_TX_CFG);
EFX_SET_OWORD_FIELD(temp, FRF_AZ_TX_NO_EOP_DISC_EN, 0);
EFX_SET_OWORD_FIELD(temp, FRF_CZ_TX_FILTER_EN_BIT, 1);
efx_writeo(efx, &temp, FR_AZ_TX_CFG);
efx_reado(efx, &temp, FR_AZ_RX_CFG);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_RX_DESC_PUSH_EN, 0);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_RX_INGR_EN, 1);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_RX_HASH_INSRT_HDR, 1);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_RX_HASH_ALG, 1);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_RX_IP_HASH, 1);
efx_writeo(efx, &temp, FR_AZ_RX_CFG);
memcpy(&temp, efx->rx_hash_key, sizeof(temp));
efx_writeo(efx, &temp, FR_BZ_RX_RSS_TKEY);
BUILD_BUG_ON(sizeof(efx->rx_hash_key) <
2 * sizeof(temp) + FRF_CZ_RX_RSS_IPV6_TKEY_HI_WIDTH / 8 ||
FRF_CZ_RX_RSS_IPV6_TKEY_HI_LBN != 0);
memcpy(&temp, efx->rx_hash_key, sizeof(temp));
efx_writeo(efx, &temp, FR_CZ_RX_RSS_IPV6_REG1);
memcpy(&temp, efx->rx_hash_key + sizeof(temp), sizeof(temp));
efx_writeo(efx, &temp, FR_CZ_RX_RSS_IPV6_REG2);
EFX_POPULATE_OWORD_2(temp, FRF_CZ_RX_RSS_IPV6_THASH_ENABLE, 1,
FRF_CZ_RX_RSS_IPV6_IP_THASH_ENABLE, 1);
memcpy(&temp, efx->rx_hash_key + 2 * sizeof(temp),
FRF_CZ_RX_RSS_IPV6_TKEY_HI_WIDTH / 8);
efx_writeo(efx, &temp, FR_CZ_RX_RSS_IPV6_REG3);
rc = efx_mcdi_log_ctrl(efx, true, false, 0);
if (rc)
return rc;
EFX_POPULATE_OWORD_1(temp, FRF_BZ_FLS_EVQ_ID, 0);
efx_writeo(efx, &temp, FR_BZ_DP_CTRL);
EFX_POPULATE_OWORD_1(temp, FRF_CZ_USREV_DIS, 1);
efx_writeo(efx, &temp, FR_CZ_USR_EV_CFG);
efx_nic_init_common(efx);
return 0;
}
static void siena_remove_nic(struct efx_nic *efx)
{
efx_mcdi_mon_remove(efx);
efx_nic_free_buffer(efx, &efx->irq_status);
siena_reset_hw(efx, RESET_TYPE_ALL);
efx_mcdi_drv_attach(efx, false, NULL);
kfree(efx->nic_data);
efx->nic_data = NULL;
}
static int siena_try_update_nic_stats(struct efx_nic *efx)
{
__le64 *dma_stats;
struct efx_mac_stats *mac_stats;
__le64 generation_start, generation_end;
mac_stats = &efx->mac_stats;
dma_stats = efx->stats_buffer.addr;
generation_end = dma_stats[MC_CMD_MAC_GENERATION_END];
if (generation_end == STATS_GENERATION_INVALID)
return 0;
rmb();
#define MAC_STAT(M, D) \
mac_stats->M = le64_to_cpu(dma_stats[MC_CMD_MAC_ ## D])
MAC_STAT(tx_bytes, TX_BYTES);
MAC_STAT(tx_bad_bytes, TX_BAD_BYTES);
efx_update_diff_stat(&mac_stats->tx_good_bytes,
mac_stats->tx_bytes - mac_stats->tx_bad_bytes);
MAC_STAT(tx_packets, TX_PKTS);
MAC_STAT(tx_bad, TX_BAD_FCS_PKTS);
MAC_STAT(tx_pause, TX_PAUSE_PKTS);
MAC_STAT(tx_control, TX_CONTROL_PKTS);
MAC_STAT(tx_unicast, TX_UNICAST_PKTS);
MAC_STAT(tx_multicast, TX_MULTICAST_PKTS);
MAC_STAT(tx_broadcast, TX_BROADCAST_PKTS);
MAC_STAT(tx_lt64, TX_LT64_PKTS);
MAC_STAT(tx_64, TX_64_PKTS);
MAC_STAT(tx_65_to_127, TX_65_TO_127_PKTS);
MAC_STAT(tx_128_to_255, TX_128_TO_255_PKTS);
MAC_STAT(tx_256_to_511, TX_256_TO_511_PKTS);
MAC_STAT(tx_512_to_1023, TX_512_TO_1023_PKTS);
MAC_STAT(tx_1024_to_15xx, TX_1024_TO_15XX_PKTS);
MAC_STAT(tx_15xx_to_jumbo, TX_15XX_TO_JUMBO_PKTS);
MAC_STAT(tx_gtjumbo, TX_GTJUMBO_PKTS);
mac_stats->tx_collision = 0;
MAC_STAT(tx_single_collision, TX_SINGLE_COLLISION_PKTS);
MAC_STAT(tx_multiple_collision, TX_MULTIPLE_COLLISION_PKTS);
MAC_STAT(tx_excessive_collision, TX_EXCESSIVE_COLLISION_PKTS);
MAC_STAT(tx_deferred, TX_DEFERRED_PKTS);
MAC_STAT(tx_late_collision, TX_LATE_COLLISION_PKTS);
mac_stats->tx_collision = (mac_stats->tx_single_collision +
mac_stats->tx_multiple_collision +
mac_stats->tx_excessive_collision +
mac_stats->tx_late_collision);
MAC_STAT(tx_excessive_deferred, TX_EXCESSIVE_DEFERRED_PKTS);
MAC_STAT(tx_non_tcpudp, TX_NON_TCPUDP_PKTS);
MAC_STAT(tx_mac_src_error, TX_MAC_SRC_ERR_PKTS);
MAC_STAT(tx_ip_src_error, TX_IP_SRC_ERR_PKTS);
MAC_STAT(rx_bytes, RX_BYTES);
MAC_STAT(rx_bad_bytes, RX_BAD_BYTES);
efx_update_diff_stat(&mac_stats->rx_good_bytes,
mac_stats->rx_bytes - mac_stats->rx_bad_bytes);
MAC_STAT(rx_packets, RX_PKTS);
MAC_STAT(rx_good, RX_GOOD_PKTS);
MAC_STAT(rx_bad, RX_BAD_FCS_PKTS);
MAC_STAT(rx_pause, RX_PAUSE_PKTS);
MAC_STAT(rx_control, RX_CONTROL_PKTS);
MAC_STAT(rx_unicast, RX_UNICAST_PKTS);
MAC_STAT(rx_multicast, RX_MULTICAST_PKTS);
MAC_STAT(rx_broadcast, RX_BROADCAST_PKTS);
MAC_STAT(rx_lt64, RX_UNDERSIZE_PKTS);
MAC_STAT(rx_64, RX_64_PKTS);
MAC_STAT(rx_65_to_127, RX_65_TO_127_PKTS);
MAC_STAT(rx_128_to_255, RX_128_TO_255_PKTS);
MAC_STAT(rx_256_to_511, RX_256_TO_511_PKTS);
MAC_STAT(rx_512_to_1023, RX_512_TO_1023_PKTS);
MAC_STAT(rx_1024_to_15xx, RX_1024_TO_15XX_PKTS);
MAC_STAT(rx_15xx_to_jumbo, RX_15XX_TO_JUMBO_PKTS);
MAC_STAT(rx_gtjumbo, RX_GTJUMBO_PKTS);
mac_stats->rx_bad_lt64 = 0;
mac_stats->rx_bad_64_to_15xx = 0;
mac_stats->rx_bad_15xx_to_jumbo = 0;
MAC_STAT(rx_bad_gtjumbo, RX_JABBER_PKTS);
MAC_STAT(rx_overflow, RX_OVERFLOW_PKTS);
mac_stats->rx_missed = 0;
MAC_STAT(rx_false_carrier, RX_FALSE_CARRIER_PKTS);
MAC_STAT(rx_symbol_error, RX_SYMBOL_ERROR_PKTS);
MAC_STAT(rx_align_error, RX_ALIGN_ERROR_PKTS);
MAC_STAT(rx_length_error, RX_LENGTH_ERROR_PKTS);
MAC_STAT(rx_internal_error, RX_INTERNAL_ERROR_PKTS);
mac_stats->rx_good_lt64 = 0;
efx->n_rx_nodesc_drop_cnt =
le64_to_cpu(dma_stats[MC_CMD_MAC_RX_NODESC_DROPS]);
#undef MAC_STAT
rmb();
generation_start = dma_stats[MC_CMD_MAC_GENERATION_START];
if (generation_end != generation_start)
return -EAGAIN;
return 0;
}
static void siena_update_nic_stats(struct efx_nic *efx)
{
int retry;
for (retry = 0; retry < 100; ++retry) {
if (siena_try_update_nic_stats(efx) == 0)
return;
udelay(100);
}
}
static void siena_start_nic_stats(struct efx_nic *efx)
{
__le64 *dma_stats = efx->stats_buffer.addr;
dma_stats[MC_CMD_MAC_GENERATION_END] = STATS_GENERATION_INVALID;
efx_mcdi_mac_stats(efx, efx->stats_buffer.dma_addr,
MC_CMD_MAC_NSTATS * sizeof(u64), 1, 0);
}
static void siena_stop_nic_stats(struct efx_nic *efx)
{
efx_mcdi_mac_stats(efx, efx->stats_buffer.dma_addr, 0, 0, 0);
}
static void siena_get_wol(struct efx_nic *efx, struct ethtool_wolinfo *wol)
{
struct siena_nic_data *nic_data = efx->nic_data;
wol->supported = WAKE_MAGIC;
if (nic_data->wol_filter_id != -1)
wol->wolopts = WAKE_MAGIC;
else
wol->wolopts = 0;
memset(&wol->sopass, 0, sizeof(wol->sopass));
}
static int siena_set_wol(struct efx_nic *efx, u32 type)
{
struct siena_nic_data *nic_data = efx->nic_data;
int rc;
if (type & ~WAKE_MAGIC)
return -EINVAL;
if (type & WAKE_MAGIC) {
if (nic_data->wol_filter_id != -1)
efx_mcdi_wol_filter_remove(efx,
nic_data->wol_filter_id);
rc = efx_mcdi_wol_filter_set_magic(efx, efx->net_dev->dev_addr,
&nic_data->wol_filter_id);
if (rc)
goto fail;
pci_wake_from_d3(efx->pci_dev, true);
} else {
rc = efx_mcdi_wol_filter_reset(efx);
nic_data->wol_filter_id = -1;
pci_wake_from_d3(efx->pci_dev, false);
if (rc)
goto fail;
}
return 0;
fail:
netif_err(efx, hw, efx->net_dev, "%s failed: type=%d rc=%d\n",
__func__, type, rc);
return rc;
}
static void siena_init_wol(struct efx_nic *efx)
{
struct siena_nic_data *nic_data = efx->nic_data;
int rc;
rc = efx_mcdi_wol_filter_get_magic(efx, &nic_data->wol_filter_id);
if (rc != 0) {
efx_mcdi_wol_filter_reset(efx);
nic_data->wol_filter_id = -1;
} else if (nic_data->wol_filter_id != -1) {
pci_wake_from_d3(efx->pci_dev, true);
}
}
