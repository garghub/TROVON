static int i40e_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_link_status *hw_link_info = &hw->phy.link_info;
bool link_up = hw_link_info->link_info & I40E_AQ_LINK_UP;
u32 link_speed = hw_link_info->link_speed;
switch (hw_link_info->phy_type) {
case I40E_PHY_TYPE_40GBASE_CR4:
case I40E_PHY_TYPE_40GBASE_CR4_CU:
ecmd->supported = SUPPORTED_40000baseCR4_Full;
ecmd->advertising = ADVERTISED_40000baseCR4_Full;
break;
case I40E_PHY_TYPE_40GBASE_KR4:
ecmd->supported = SUPPORTED_40000baseKR4_Full;
ecmd->advertising = ADVERTISED_40000baseKR4_Full;
break;
case I40E_PHY_TYPE_40GBASE_SR4:
ecmd->supported = SUPPORTED_40000baseSR4_Full;
ecmd->advertising = ADVERTISED_40000baseSR4_Full;
break;
case I40E_PHY_TYPE_40GBASE_LR4:
ecmd->supported = SUPPORTED_40000baseLR4_Full;
ecmd->advertising = ADVERTISED_40000baseLR4_Full;
break;
case I40E_PHY_TYPE_10GBASE_KX4:
ecmd->supported = SUPPORTED_10000baseKX4_Full;
ecmd->advertising = ADVERTISED_10000baseKX4_Full;
break;
case I40E_PHY_TYPE_10GBASE_KR:
ecmd->supported = SUPPORTED_10000baseKR_Full;
ecmd->advertising = ADVERTISED_10000baseKR_Full;
break;
case I40E_PHY_TYPE_10GBASE_T:
default:
ecmd->supported = SUPPORTED_10000baseT_Full;
ecmd->advertising = ADVERTISED_10000baseT_Full;
break;
}
ecmd->supported |= SUPPORTED_Autoneg;
if (hw->phy.media_type == I40E_MEDIA_TYPE_BACKPLANE) {
ecmd->supported |= SUPPORTED_Backplane;
ecmd->advertising |= ADVERTISED_Backplane;
ecmd->port = PORT_NONE;
} else if (hw->phy.media_type == I40E_MEDIA_TYPE_BASET) {
ecmd->supported |= SUPPORTED_TP;
ecmd->advertising |= ADVERTISED_TP;
ecmd->port = PORT_TP;
} else {
ecmd->supported |= SUPPORTED_FIBRE;
ecmd->advertising |= ADVERTISED_FIBRE;
ecmd->port = PORT_FIBRE;
}
ecmd->transceiver = XCVR_EXTERNAL;
if (link_up) {
switch (link_speed) {
case I40E_LINK_SPEED_40GB:
ethtool_cmd_speed_set(ecmd, 40000);
break;
case I40E_LINK_SPEED_10GB:
ethtool_cmd_speed_set(ecmd, SPEED_10000);
break;
default:
break;
}
ecmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(ecmd, SPEED_UNKNOWN);
ecmd->duplex = DUPLEX_UNKNOWN;
}
return 0;
}
static void i40e_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_link_status *hw_link_info = &hw->phy.link_info;
pause->autoneg =
((hw_link_info->an_info & I40E_AQ_AN_COMPLETED) ?
AUTONEG_ENABLE : AUTONEG_DISABLE);
pause->rx_pause = 0;
pause->tx_pause = 0;
if (hw_link_info->an_info & I40E_AQ_LINK_PAUSE_RX)
pause->rx_pause = 1;
if (hw_link_info->an_info & I40E_AQ_LINK_PAUSE_TX)
pause->tx_pause = 1;
}
static u32 i40e_get_msglevel(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
return pf->msg_enable;
}
static void i40e_set_msglevel(struct net_device *netdev, u32 data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
if (I40E_DEBUG_USER & data)
pf->hw.debug_mask = data;
pf->msg_enable = data;
}
static int i40e_get_regs_len(struct net_device *netdev)
{
int reg_count = 0;
int i;
for (i = 0; i40e_reg_list[i].offset != 0; i++)
reg_count += i40e_reg_list[i].elements;
return reg_count * sizeof(u32);
}
static void i40e_get_regs(struct net_device *netdev, struct ethtool_regs *regs,
void *p)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
u32 *reg_buf = p;
int i, j, ri;
u32 reg;
regs->version = 1;
ri = 0;
for (i = 0; i40e_reg_list[i].offset != 0; i++) {
for (j = 0; j < i40e_reg_list[i].elements; j++) {
reg = i40e_reg_list[i].offset
+ (j * i40e_reg_list[i].stride);
reg_buf[ri++] = rd32(hw, reg);
}
}
}
static int i40e_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_hw *hw = &np->vsi->back->hw;
int first_word, last_word;
u16 i, eeprom_len;
u16 *eeprom_buff;
int ret_val = 0;
if (eeprom->len == 0)
return -EINVAL;
eeprom->magic = hw->vendor_id | (hw->device_id << 16);
first_word = eeprom->offset >> 1;
last_word = (eeprom->offset + eeprom->len - 1) >> 1;
eeprom_len = last_word - first_word + 1;
eeprom_buff = kmalloc(sizeof(u16) * eeprom_len, GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
ret_val = i40e_read_nvm_buffer(hw, first_word, &eeprom_len,
eeprom_buff);
if (eeprom_len == 0) {
kfree(eeprom_buff);
return -EACCES;
}
for (i = 0; i < eeprom_len; i++)
le16_to_cpus(&eeprom_buff[i]);
memcpy(bytes, (u8 *)eeprom_buff + (eeprom->offset & 1), eeprom->len);
kfree(eeprom_buff);
return ret_val;
}
static int i40e_get_eeprom_len(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_hw *hw = &np->vsi->back->hw;
return hw->nvm.sr_size * 2;
}
static void i40e_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
strlcpy(drvinfo->driver, i40e_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, i40e_driver_version_str,
sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, i40e_fw_version_str(&pf->hw),
sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, pci_name(pf->pdev),
sizeof(drvinfo->bus_info));
}
static void i40e_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
ring->rx_max_pending = I40E_MAX_NUM_DESCRIPTORS;
ring->tx_max_pending = I40E_MAX_NUM_DESCRIPTORS;
ring->rx_mini_max_pending = 0;
ring->rx_jumbo_max_pending = 0;
ring->rx_pending = vsi->rx_rings[0].count;
ring->tx_pending = vsi->tx_rings[0].count;
ring->rx_mini_pending = 0;
ring->rx_jumbo_pending = 0;
}
static int i40e_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct i40e_ring *tx_rings = NULL, *rx_rings = NULL;
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
u32 new_rx_count, new_tx_count;
int i, err = 0;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
new_tx_count = clamp_t(u32, ring->tx_pending,
I40E_MIN_NUM_DESCRIPTORS,
I40E_MAX_NUM_DESCRIPTORS);
new_tx_count = ALIGN(new_tx_count, I40E_REQ_DESCRIPTOR_MULTIPLE);
new_rx_count = clamp_t(u32, ring->rx_pending,
I40E_MIN_NUM_DESCRIPTORS,
I40E_MAX_NUM_DESCRIPTORS);
new_rx_count = ALIGN(new_rx_count, I40E_REQ_DESCRIPTOR_MULTIPLE);
if ((new_tx_count == vsi->tx_rings[0].count) &&
(new_rx_count == vsi->rx_rings[0].count))
return 0;
while (test_and_set_bit(__I40E_CONFIG_BUSY, &pf->state))
usleep_range(1000, 2000);
if (!netif_running(vsi->netdev)) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
vsi->tx_rings[i].count = new_tx_count;
vsi->rx_rings[i].count = new_rx_count;
}
goto done;
}
if (new_tx_count != vsi->tx_rings[0].count) {
netdev_info(netdev,
"Changing Tx descriptor count from %d to %d.\n",
vsi->tx_rings[0].count, new_tx_count);
tx_rings = kcalloc(vsi->alloc_queue_pairs,
sizeof(struct i40e_ring), GFP_KERNEL);
if (!tx_rings) {
err = -ENOMEM;
goto done;
}
for (i = 0; i < vsi->num_queue_pairs; i++) {
tx_rings[i] = vsi->tx_rings[i];
tx_rings[i].count = new_tx_count;
err = i40e_setup_tx_descriptors(&tx_rings[i]);
if (err) {
while (i) {
i--;
i40e_free_tx_resources(&tx_rings[i]);
}
kfree(tx_rings);
tx_rings = NULL;
goto done;
}
}
}
if (new_rx_count != vsi->rx_rings[0].count) {
netdev_info(netdev,
"Changing Rx descriptor count from %d to %d\n",
vsi->rx_rings[0].count, new_rx_count);
rx_rings = kcalloc(vsi->alloc_queue_pairs,
sizeof(struct i40e_ring), GFP_KERNEL);
if (!rx_rings) {
err = -ENOMEM;
goto free_tx;
}
for (i = 0; i < vsi->num_queue_pairs; i++) {
rx_rings[i] = vsi->rx_rings[i];
rx_rings[i].count = new_rx_count;
err = i40e_setup_rx_descriptors(&rx_rings[i]);
if (err) {
while (i) {
i--;
i40e_free_rx_resources(&rx_rings[i]);
}
kfree(rx_rings);
rx_rings = NULL;
goto free_tx;
}
}
}
i40e_down(vsi);
if (tx_rings) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
i40e_free_tx_resources(&vsi->tx_rings[i]);
vsi->tx_rings[i] = tx_rings[i];
}
kfree(tx_rings);
tx_rings = NULL;
}
if (rx_rings) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
i40e_free_rx_resources(&vsi->rx_rings[i]);
vsi->rx_rings[i] = rx_rings[i];
}
kfree(rx_rings);
rx_rings = NULL;
}
i40e_up(vsi);
free_tx:
if (tx_rings) {
for (i = 0; i < vsi->num_queue_pairs; i++)
i40e_free_tx_resources(&tx_rings[i]);
kfree(tx_rings);
tx_rings = NULL;
}
done:
clear_bit(__I40E_CONFIG_BUSY, &pf->state);
return err;
}
static int i40e_get_sset_count(struct net_device *netdev, int sset)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
switch (sset) {
case ETH_SS_TEST:
return I40E_TEST_LEN;
case ETH_SS_STATS:
if (vsi == pf->vsi[pf->lan_vsi])
return I40E_PF_STATS_LEN(netdev);
else
return I40E_VSI_STATS_LEN(netdev);
default:
return -EOPNOTSUPP;
}
}
static void i40e_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int i = 0;
char *p;
int j;
struct rtnl_link_stats64 *net_stats = i40e_get_vsi_stats_struct(vsi);
i40e_update_stats(vsi);
for (j = 0; j < I40E_NETDEV_STATS_LEN; j++) {
p = (char *)net_stats + i40e_gstrings_net_stats[j].stat_offset;
data[i++] = (i40e_gstrings_net_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
for (j = 0; j < vsi->num_queue_pairs; j++) {
data[i++] = vsi->tx_rings[j].tx_stats.packets;
data[i++] = vsi->tx_rings[j].tx_stats.bytes;
}
for (j = 0; j < vsi->num_queue_pairs; j++) {
data[i++] = vsi->rx_rings[j].rx_stats.packets;
data[i++] = vsi->rx_rings[j].rx_stats.bytes;
}
if (vsi == pf->vsi[pf->lan_vsi]) {
for (j = 0; j < I40E_GLOBAL_STATS_LEN; j++) {
p = (char *)pf + i40e_gstrings_stats[j].stat_offset;
data[i++] = (i40e_gstrings_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
for (j = 0; j < I40E_MAX_USER_PRIORITY; j++) {
data[i++] = pf->stats.priority_xon_tx[j];
data[i++] = pf->stats.priority_xoff_tx[j];
}
for (j = 0; j < I40E_MAX_USER_PRIORITY; j++) {
data[i++] = pf->stats.priority_xon_rx[j];
data[i++] = pf->stats.priority_xoff_rx[j];
}
for (j = 0; j < I40E_MAX_USER_PRIORITY; j++)
data[i++] = pf->stats.priority_xon_2_xoff[j];
}
}
static void i40e_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
char *p = (char *)data;
int i;
switch (stringset) {
case ETH_SS_TEST:
for (i = 0; i < I40E_TEST_LEN; i++) {
memcpy(data, i40e_gstrings_test[i], ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
break;
case ETH_SS_STATS:
for (i = 0; i < I40E_NETDEV_STATS_LEN; i++) {
snprintf(p, ETH_GSTRING_LEN, "%s",
i40e_gstrings_net_stats[i].stat_string);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < vsi->num_queue_pairs; i++) {
snprintf(p, ETH_GSTRING_LEN, "tx-%u.tx_packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "tx-%u.tx_bytes", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < vsi->num_queue_pairs; i++) {
snprintf(p, ETH_GSTRING_LEN, "rx-%u.rx_packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx-%u.rx_bytes", i);
p += ETH_GSTRING_LEN;
}
if (vsi == pf->vsi[pf->lan_vsi]) {
for (i = 0; i < I40E_GLOBAL_STATS_LEN; i++) {
snprintf(p, ETH_GSTRING_LEN, "port.%s",
i40e_gstrings_stats[i].stat_string);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
snprintf(p, ETH_GSTRING_LEN,
"port.tx_priority_%u_xon", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN,
"port.tx_priority_%u_xoff", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
snprintf(p, ETH_GSTRING_LEN,
"port.rx_priority_%u_xon", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN,
"port.rx_priority_%u_xoff", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
snprintf(p, ETH_GSTRING_LEN,
"port.rx_priority_%u_xon_2_xoff", i);
p += ETH_GSTRING_LEN;
}
}
break;
}
}
static int i40e_get_ts_info(struct net_device *dev,
struct ethtool_ts_info *info)
{
return ethtool_op_get_ts_info(dev, info);
}
static int i40e_link_test(struct i40e_pf *pf, u64 *data)
{
if (i40e_get_link_status(&pf->hw))
*data = 0;
else
*data = 1;
return *data;
}
static int i40e_reg_test(struct i40e_pf *pf, u64 *data)
{
i40e_status ret;
ret = i40e_diag_reg_test(&pf->hw);
*data = ret;
return ret;
}
static int i40e_eeprom_test(struct i40e_pf *pf, u64 *data)
{
i40e_status ret;
ret = i40e_diag_eeprom_test(&pf->hw);
*data = ret;
return ret;
}
static int i40e_intr_test(struct i40e_pf *pf, u64 *data)
{
*data = -ENOSYS;
return *data;
}
static int i40e_loopback_test(struct i40e_pf *pf, u64 *data)
{
*data = -ENOSYS;
return *data;
}
static void i40e_diag_test(struct net_device *netdev,
struct ethtool_test *eth_test, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
set_bit(__I40E_TESTING, &pf->state);
if (eth_test->flags == ETH_TEST_FL_OFFLINE) {
netdev_info(netdev, "offline testing starting\n");
netdev_info(netdev, "link test starting\n");
if (i40e_link_test(pf, &data[I40E_ETH_TEST_LINK]))
eth_test->flags |= ETH_TEST_FL_FAILED;
netdev_info(netdev, "register test starting\n");
if (i40e_reg_test(pf, &data[I40E_ETH_TEST_REG]))
eth_test->flags |= ETH_TEST_FL_FAILED;
i40e_do_reset(pf, (1 << __I40E_PF_RESET_REQUESTED));
netdev_info(netdev, "eeprom test starting\n");
if (i40e_eeprom_test(pf, &data[I40E_ETH_TEST_EEPROM]))
eth_test->flags |= ETH_TEST_FL_FAILED;
i40e_do_reset(pf, (1 << __I40E_PF_RESET_REQUESTED));
netdev_info(netdev, "interrupt test starting\n");
if (i40e_intr_test(pf, &data[I40E_ETH_TEST_INTR]))
eth_test->flags |= ETH_TEST_FL_FAILED;
i40e_do_reset(pf, (1 << __I40E_PF_RESET_REQUESTED));
netdev_info(netdev, "loopback test starting\n");
if (i40e_loopback_test(pf, &data[I40E_ETH_TEST_LOOPBACK]))
eth_test->flags |= ETH_TEST_FL_FAILED;
} else {
netdev_info(netdev, "online test starting\n");
if (i40e_link_test(pf, &data[I40E_ETH_TEST_LINK]))
eth_test->flags |= ETH_TEST_FL_FAILED;
data[I40E_ETH_TEST_REG] = 0;
data[I40E_ETH_TEST_EEPROM] = 0;
data[I40E_ETH_TEST_INTR] = 0;
data[I40E_ETH_TEST_LOOPBACK] = 0;
clear_bit(__I40E_TESTING, &pf->state);
}
}
static void i40e_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
wol->supported = 0;
wol->wolopts = 0;
}
static int i40e_nway_reset(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
i40e_status ret = 0;
ret = i40e_aq_set_link_restart_an(hw, NULL);
if (ret) {
netdev_info(netdev, "link restart failed, aq_err=%d\n",
pf->hw.aq.asq_last_status);
return -EIO;
}
return 0;
}
static int i40e_set_phys_id(struct net_device *netdev,
enum ethtool_phys_id_state state)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
int blink_freq = 2;
switch (state) {
case ETHTOOL_ID_ACTIVE:
pf->led_status = i40e_led_get(hw);
return blink_freq;
case ETHTOOL_ID_ON:
i40e_led_set(hw, 0xF);
break;
case ETHTOOL_ID_OFF:
i40e_led_set(hw, 0x0);
break;
case ETHTOOL_ID_INACTIVE:
i40e_led_set(hw, pf->led_status);
break;
}
return 0;
}
static int i40e_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
ec->tx_max_coalesced_frames_irq = vsi->work_limit;
ec->rx_max_coalesced_frames_irq = vsi->work_limit;
if (ITR_IS_DYNAMIC(vsi->rx_itr_setting))
ec->rx_coalesce_usecs = 1;
else
ec->rx_coalesce_usecs = vsi->rx_itr_setting;
if (ITR_IS_DYNAMIC(vsi->tx_itr_setting))
ec->tx_coalesce_usecs = 1;
else
ec->tx_coalesce_usecs = vsi->tx_itr_setting;
return 0;
}
static int i40e_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_q_vector *q_vector;
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 vector;
int i;
if (ec->tx_max_coalesced_frames_irq || ec->rx_max_coalesced_frames_irq)
vsi->work_limit = ec->tx_max_coalesced_frames_irq;
switch (ec->rx_coalesce_usecs) {
case 0:
vsi->rx_itr_setting = 0;
break;
case 1:
vsi->rx_itr_setting = (I40E_ITR_DYNAMIC |
ITR_REG_TO_USEC(I40E_ITR_RX_DEF));
break;
default:
if ((ec->rx_coalesce_usecs < (I40E_MIN_ITR << 1)) ||
(ec->rx_coalesce_usecs > (I40E_MAX_ITR << 1)))
return -EINVAL;
vsi->rx_itr_setting = ec->rx_coalesce_usecs;
break;
}
switch (ec->tx_coalesce_usecs) {
case 0:
vsi->tx_itr_setting = 0;
break;
case 1:
vsi->tx_itr_setting = (I40E_ITR_DYNAMIC |
ITR_REG_TO_USEC(I40E_ITR_TX_DEF));
break;
default:
if ((ec->tx_coalesce_usecs < (I40E_MIN_ITR << 1)) ||
(ec->tx_coalesce_usecs > (I40E_MAX_ITR << 1)))
return -EINVAL;
vsi->tx_itr_setting = ec->tx_coalesce_usecs;
break;
}
vector = vsi->base_vector;
q_vector = vsi->q_vectors;
for (i = 0; i < vsi->num_q_vectors; i++, vector++, q_vector++) {
q_vector->rx.itr = ITR_TO_REG(vsi->rx_itr_setting);
wr32(hw, I40E_PFINT_ITRN(0, vector - 1), q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_itr_setting);
wr32(hw, I40E_PFINT_ITRN(1, vector - 1), q_vector->tx.itr);
i40e_flush(hw);
}
return 0;
}
static int i40e_get_rss_hash_opts(struct i40e_pf *pf, struct ethtool_rxnfc *cmd)
{
cmd->data = 0;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
case UDP_V4_FLOW:
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case IPV4_FLOW:
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
break;
case TCP_V6_FLOW:
case UDP_V6_FLOW:
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case SCTP_V6_FLOW:
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case IPV6_FLOW:
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
break;
default:
return -EINVAL;
}
return 0;
}
static int i40e_get_rxnfc(struct net_device *netdev, struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = vsi->alloc_queue_pairs;
ret = 0;
break;
case ETHTOOL_GRXFH:
ret = i40e_get_rss_hash_opts(pf, cmd);
break;
case ETHTOOL_GRXCLSRLCNT:
ret = 0;
break;
case ETHTOOL_GRXCLSRULE:
ret = 0;
break;
case ETHTOOL_GRXCLSRLALL:
cmd->data = 500;
ret = 0;
default:
break;
}
return ret;
}
static int i40e_set_rss_hash_opt(struct i40e_pf *pf, struct ethtool_rxnfc *nfc)
{
struct i40e_hw *hw = &pf->hw;
u64 hena = (u64)rd32(hw, I40E_PFQF_HENA(0)) |
((u64)rd32(hw, I40E_PFQF_HENA(1)) << 32);
if (nfc->data & ~(RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3))
return -EINVAL;
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST))
return -EINVAL;
switch (nfc->flow_type) {
case TCP_V4_FLOW:
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
hena &= ~((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV4_TCP);
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
hena |= ((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV4_TCP);
break;
default:
return -EINVAL;
}
break;
case TCP_V6_FLOW:
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
hena &= ~((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV6_TCP);
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
hena |= ((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV6_TCP);
break;
default:
return -EINVAL;
}
break;
case UDP_V4_FLOW:
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
hena &=
~(((u64)1 << I40E_FILTER_PCTYPE_NONF_UNICAST_IPV4_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV4_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV4));
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
hena |=
(((u64)1 << I40E_FILTER_PCTYPE_NONF_UNICAST_IPV4_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV4_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV4));
break;
default:
return -EINVAL;
}
break;
case UDP_V6_FLOW:
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
hena &=
~(((u64)1 << I40E_FILTER_PCTYPE_NONF_UNICAST_IPV6_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV6_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV6));
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
hena |=
(((u64)1 << I40E_FILTER_PCTYPE_NONF_UNICAST_IPV6_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV6_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV6));
break;
default:
return -EINVAL;
}
break;
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case SCTP_V4_FLOW:
if ((nfc->data & RXH_L4_B_0_1) ||
(nfc->data & RXH_L4_B_2_3))
return -EINVAL;
hena |= ((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV4_OTHER);
break;
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case SCTP_V6_FLOW:
if ((nfc->data & RXH_L4_B_0_1) ||
(nfc->data & RXH_L4_B_2_3))
return -EINVAL;
hena |= ((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV6_OTHER);
break;
case IPV4_FLOW:
hena |= ((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV4_OTHER) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV4);
break;
case IPV6_FLOW:
hena |= ((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV6_OTHER) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV6);
break;
default:
return -EINVAL;
}
wr32(hw, I40E_PFQF_HENA(0), (u32)hena);
wr32(hw, I40E_PFQF_HENA(1), (u32)(hena >> 32));
i40e_flush(hw);
return 0;
}
static int i40e_add_del_fdir_udpv4(struct i40e_vsi *vsi,
struct i40e_fdir_data *fd_data,
struct ethtool_rx_flow_spec *fsp, bool add)
{
struct i40e_pf *pf = vsi->back;
struct udphdr *udp;
struct iphdr *ip;
bool err = false;
int ret;
int i;
ip = (struct iphdr *)(fd_data->raw_packet + IP_HEADER_OFFSET);
udp = (struct udphdr *)(fd_data->raw_packet + IP_HEADER_OFFSET
+ sizeof(struct iphdr));
ip->saddr = fsp->h_u.tcp_ip4_spec.ip4src;
ip->daddr = fsp->h_u.tcp_ip4_spec.ip4dst;
udp->source = fsp->h_u.tcp_ip4_spec.psrc;
udp->dest = fsp->h_u.tcp_ip4_spec.pdst;
for (i = I40E_FILTER_PCTYPE_NONF_UNICAST_IPV4_UDP;
i <= I40E_FILTER_PCTYPE_NONF_IPV4_UDP; i++) {
fd_data->pctype = i;
ret = i40e_program_fdir_filter(fd_data, pf, add);
if (ret) {
dev_info(&pf->pdev->dev,
"Filter command send failed for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
err = true;
} else {
dev_info(&pf->pdev->dev,
"Filter OK for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
}
}
return err ? -EOPNOTSUPP : 0;
}
static int i40e_add_del_fdir_tcpv4(struct i40e_vsi *vsi,
struct i40e_fdir_data *fd_data,
struct ethtool_rx_flow_spec *fsp, bool add)
{
struct i40e_pf *pf = vsi->back;
struct tcphdr *tcp;
struct iphdr *ip;
bool err = false;
int ret;
ip = (struct iphdr *)(fd_data->raw_packet + IP_HEADER_OFFSET);
tcp = (struct tcphdr *)(fd_data->raw_packet + IP_HEADER_OFFSET
+ sizeof(struct iphdr));
ip->daddr = fsp->h_u.tcp_ip4_spec.ip4dst;
tcp->dest = fsp->h_u.tcp_ip4_spec.pdst;
fd_data->pctype = I40E_FILTER_PCTYPE_NONF_IPV4_TCP_SYN;
ret = i40e_program_fdir_filter(fd_data, pf, add);
if (ret) {
dev_info(&pf->pdev->dev,
"Filter command send failed for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
err = true;
} else {
dev_info(&pf->pdev->dev, "Filter OK for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
}
ip->saddr = fsp->h_u.tcp_ip4_spec.ip4src;
tcp->source = fsp->h_u.tcp_ip4_spec.psrc;
fd_data->pctype = I40E_FILTER_PCTYPE_NONF_IPV4_TCP;
ret = i40e_program_fdir_filter(fd_data, pf, add);
if (ret) {
dev_info(&pf->pdev->dev,
"Filter command send failed for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
err = true;
} else {
dev_info(&pf->pdev->dev, "Filter OK for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
}
return err ? -EOPNOTSUPP : 0;
}
static int i40e_add_del_fdir_sctpv4(struct i40e_vsi *vsi,
struct i40e_fdir_data *fd_data,
struct ethtool_rx_flow_spec *fsp, bool add)
{
return -EOPNOTSUPP;
}
static int i40e_add_del_fdir_ipv4(struct i40e_vsi *vsi,
struct i40e_fdir_data *fd_data,
struct ethtool_rx_flow_spec *fsp, bool add)
{
struct i40e_pf *pf = vsi->back;
struct iphdr *ip;
bool err = false;
int ret;
int i;
ip = (struct iphdr *)(fd_data->raw_packet + IP_HEADER_OFFSET);
ip->saddr = fsp->h_u.usr_ip4_spec.ip4src;
ip->daddr = fsp->h_u.usr_ip4_spec.ip4dst;
ip->protocol = fsp->h_u.usr_ip4_spec.proto;
for (i = I40E_FILTER_PCTYPE_NONF_IPV4_OTHER;
i <= I40E_FILTER_PCTYPE_FRAG_IPV4; i++) {
fd_data->pctype = i;
ret = i40e_program_fdir_filter(fd_data, pf, add);
if (ret) {
dev_info(&pf->pdev->dev,
"Filter command send failed for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
err = true;
} else {
dev_info(&pf->pdev->dev,
"Filter OK for PCTYPE %d (ret = %d)\n",
fd_data->pctype, ret);
}
}
return err ? -EOPNOTSUPP : 0;
}
static int i40e_add_del_fdir_ethtool(struct i40e_vsi *vsi,
struct ethtool_rxnfc *cmd, bool add)
{
struct i40e_fdir_data fd_data;
int ret = -EINVAL;
struct i40e_pf *pf;
struct ethtool_rx_flow_spec *fsp =
(struct ethtool_rx_flow_spec *)&cmd->fs;
if (!vsi)
return -EINVAL;
pf = vsi->back;
if ((fsp->ring_cookie != RX_CLS_FLOW_DISC) &&
(fsp->ring_cookie >= vsi->num_queue_pairs))
return -EINVAL;
fd_data.raw_packet = kzalloc(I40E_FDIR_MAX_RAW_PACKET_LOOKUP,
GFP_KERNEL);
if (!fd_data.raw_packet) {
dev_info(&pf->pdev->dev, "Could not allocate memory\n");
return -ENOMEM;
}
fd_data.q_index = fsp->ring_cookie;
fd_data.flex_off = 0;
fd_data.pctype = 0;
fd_data.dest_vsi = vsi->id;
fd_data.dest_ctl = 0;
fd_data.fd_status = 0;
fd_data.cnt_index = 0;
fd_data.fd_id = 0;
switch (fsp->flow_type & ~FLOW_EXT) {
case TCP_V4_FLOW:
ret = i40e_add_del_fdir_tcpv4(vsi, &fd_data, fsp, add);
break;
case UDP_V4_FLOW:
ret = i40e_add_del_fdir_udpv4(vsi, &fd_data, fsp, add);
break;
case SCTP_V4_FLOW:
ret = i40e_add_del_fdir_sctpv4(vsi, &fd_data, fsp, add);
break;
case IPV4_FLOW:
ret = i40e_add_del_fdir_ipv4(vsi, &fd_data, fsp, add);
break;
case IP_USER_FLOW:
switch (fsp->h_u.usr_ip4_spec.proto) {
case IPPROTO_TCP:
ret = i40e_add_del_fdir_tcpv4(vsi, &fd_data, fsp, add);
break;
case IPPROTO_UDP:
ret = i40e_add_del_fdir_udpv4(vsi, &fd_data, fsp, add);
break;
case IPPROTO_SCTP:
ret = i40e_add_del_fdir_sctpv4(vsi, &fd_data, fsp, add);
break;
default:
ret = i40e_add_del_fdir_ipv4(vsi, &fd_data, fsp, add);
break;
}
break;
default:
dev_info(&pf->pdev->dev, "Could not specify spec type\n");
ret = -EINVAL;
}
kfree(fd_data.raw_packet);
fd_data.raw_packet = NULL;
return ret;
}
static int i40e_set_rxnfc(struct net_device *netdev, struct ethtool_rxnfc *cmd)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_SRXFH:
ret = i40e_set_rss_hash_opt(pf, cmd);
break;
case ETHTOOL_SRXCLSRLINS:
ret = i40e_add_del_fdir_ethtool(vsi, cmd, true);
break;
case ETHTOOL_SRXCLSRLDEL:
ret = i40e_add_del_fdir_ethtool(vsi, cmd, false);
break;
default:
break;
}
return ret;
}
void i40e_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &i40e_ethtool_ops);
}
