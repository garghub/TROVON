static int
ixgb_get_settings(struct net_device *netdev, struct ethtool_cmd *ecmd)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
ecmd->supported = (SUPPORTED_10000baseT_Full | SUPPORTED_FIBRE);
ecmd->advertising = (ADVERTISED_10000baseT_Full | ADVERTISED_FIBRE);
ecmd->port = PORT_FIBRE;
ecmd->transceiver = XCVR_EXTERNAL;
if (netif_carrier_ok(adapter->netdev)) {
ethtool_cmd_speed_set(ecmd, SPEED_10000);
ecmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(ecmd, SPEED_UNKNOWN);
ecmd->duplex = DUPLEX_UNKNOWN;
}
ecmd->autoneg = AUTONEG_DISABLE;
return 0;
}
void ixgb_set_speed_duplex(struct net_device *netdev)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
adapter->link_speed = 10000;
adapter->link_duplex = FULL_DUPLEX;
netif_carrier_on(netdev);
netif_wake_queue(netdev);
}
static int
ixgb_set_settings(struct net_device *netdev, struct ethtool_cmd *ecmd)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
u32 speed = ethtool_cmd_speed(ecmd);
if (ecmd->autoneg == AUTONEG_ENABLE ||
(speed + ecmd->duplex != SPEED_10000 + DUPLEX_FULL))
return -EINVAL;
if (netif_running(adapter->netdev)) {
ixgb_down(adapter, true);
ixgb_reset(adapter);
ixgb_up(adapter);
ixgb_set_speed_duplex(netdev);
} else
ixgb_reset(adapter);
return 0;
}
static void
ixgb_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_hw *hw = &adapter->hw;
pause->autoneg = AUTONEG_DISABLE;
if (hw->fc.type == ixgb_fc_rx_pause)
pause->rx_pause = 1;
else if (hw->fc.type == ixgb_fc_tx_pause)
pause->tx_pause = 1;
else if (hw->fc.type == ixgb_fc_full) {
pause->rx_pause = 1;
pause->tx_pause = 1;
}
}
static int
ixgb_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_hw *hw = &adapter->hw;
if (pause->autoneg == AUTONEG_ENABLE)
return -EINVAL;
if (pause->rx_pause && pause->tx_pause)
hw->fc.type = ixgb_fc_full;
else if (pause->rx_pause && !pause->tx_pause)
hw->fc.type = ixgb_fc_rx_pause;
else if (!pause->rx_pause && pause->tx_pause)
hw->fc.type = ixgb_fc_tx_pause;
else if (!pause->rx_pause && !pause->tx_pause)
hw->fc.type = ixgb_fc_none;
if (netif_running(adapter->netdev)) {
ixgb_down(adapter, true);
ixgb_up(adapter);
ixgb_set_speed_duplex(netdev);
} else
ixgb_reset(adapter);
return 0;
}
static u32
ixgb_get_msglevel(struct net_device *netdev)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
return adapter->msg_enable;
}
static void
ixgb_set_msglevel(struct net_device *netdev, u32 data)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
adapter->msg_enable = data;
}
static int
ixgb_get_regs_len(struct net_device *netdev)
{
#define IXGB_REG_DUMP_LEN 136*sizeof(u32)
return IXGB_REG_DUMP_LEN;
}
static void
ixgb_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_hw *hw = &adapter->hw;
u32 *reg = p;
u32 *reg_start = reg;
u8 i;
regs->version = (1<<24) | hw->revision_id << 16 | hw->device_id;
*reg++ = IXGB_READ_REG(hw, CTRL0);
*reg++ = IXGB_READ_REG(hw, CTRL1);
*reg++ = IXGB_READ_REG(hw, STATUS);
*reg++ = IXGB_READ_REG(hw, EECD);
*reg++ = IXGB_READ_REG(hw, MFS);
*reg++ = IXGB_READ_REG(hw, ICR);
*reg++ = IXGB_READ_REG(hw, ICS);
*reg++ = IXGB_READ_REG(hw, IMS);
*reg++ = IXGB_READ_REG(hw, IMC);
*reg++ = IXGB_READ_REG(hw, RCTL);
*reg++ = IXGB_READ_REG(hw, FCRTL);
*reg++ = IXGB_READ_REG(hw, FCRTH);
*reg++ = IXGB_READ_REG(hw, RDBAL);
*reg++ = IXGB_READ_REG(hw, RDBAH);
*reg++ = IXGB_READ_REG(hw, RDLEN);
*reg++ = IXGB_READ_REG(hw, RDH);
*reg++ = IXGB_READ_REG(hw, RDT);
*reg++ = IXGB_READ_REG(hw, RDTR);
*reg++ = IXGB_READ_REG(hw, RXDCTL);
*reg++ = IXGB_READ_REG(hw, RAIDC);
*reg++ = IXGB_READ_REG(hw, RXCSUM);
for (i = 0; i < IXGB_ALL_RAR_ENTRIES; i++) {
*reg++ = IXGB_READ_REG_ARRAY(hw, RAL, (i << 1));
*reg++ = IXGB_READ_REG_ARRAY(hw, RAH, (i << 1));
}
*reg++ = IXGB_READ_REG(hw, TCTL);
*reg++ = IXGB_READ_REG(hw, TDBAL);
*reg++ = IXGB_READ_REG(hw, TDBAH);
*reg++ = IXGB_READ_REG(hw, TDLEN);
*reg++ = IXGB_READ_REG(hw, TDH);
*reg++ = IXGB_READ_REG(hw, TDT);
*reg++ = IXGB_READ_REG(hw, TIDV);
*reg++ = IXGB_READ_REG(hw, TXDCTL);
*reg++ = IXGB_READ_REG(hw, TSPMT);
*reg++ = IXGB_READ_REG(hw, PAP);
*reg++ = IXGB_READ_REG(hw, PCSC1);
*reg++ = IXGB_READ_REG(hw, PCSC2);
*reg++ = IXGB_READ_REG(hw, PCSS1);
*reg++ = IXGB_READ_REG(hw, PCSS2);
*reg++ = IXGB_READ_REG(hw, XPCSS);
*reg++ = IXGB_READ_REG(hw, UCCR);
*reg++ = IXGB_READ_REG(hw, XPCSTC);
*reg++ = IXGB_READ_REG(hw, MACA);
*reg++ = IXGB_READ_REG(hw, APAE);
*reg++ = IXGB_READ_REG(hw, ARD);
*reg++ = IXGB_READ_REG(hw, AIS);
*reg++ = IXGB_READ_REG(hw, MSCA);
*reg++ = IXGB_READ_REG(hw, MSRWD);
*reg++ = IXGB_GET_STAT(adapter, tprl);
*reg++ = IXGB_GET_STAT(adapter, tprh);
*reg++ = IXGB_GET_STAT(adapter, gprcl);
*reg++ = IXGB_GET_STAT(adapter, gprch);
*reg++ = IXGB_GET_STAT(adapter, bprcl);
*reg++ = IXGB_GET_STAT(adapter, bprch);
*reg++ = IXGB_GET_STAT(adapter, mprcl);
*reg++ = IXGB_GET_STAT(adapter, mprch);
*reg++ = IXGB_GET_STAT(adapter, uprcl);
*reg++ = IXGB_GET_STAT(adapter, uprch);
*reg++ = IXGB_GET_STAT(adapter, vprcl);
*reg++ = IXGB_GET_STAT(adapter, vprch);
*reg++ = IXGB_GET_STAT(adapter, jprcl);
*reg++ = IXGB_GET_STAT(adapter, jprch);
*reg++ = IXGB_GET_STAT(adapter, gorcl);
*reg++ = IXGB_GET_STAT(adapter, gorch);
*reg++ = IXGB_GET_STAT(adapter, torl);
*reg++ = IXGB_GET_STAT(adapter, torh);
*reg++ = IXGB_GET_STAT(adapter, rnbc);
*reg++ = IXGB_GET_STAT(adapter, ruc);
*reg++ = IXGB_GET_STAT(adapter, roc);
*reg++ = IXGB_GET_STAT(adapter, rlec);
*reg++ = IXGB_GET_STAT(adapter, crcerrs);
*reg++ = IXGB_GET_STAT(adapter, icbc);
*reg++ = IXGB_GET_STAT(adapter, ecbc);
*reg++ = IXGB_GET_STAT(adapter, mpc);
*reg++ = IXGB_GET_STAT(adapter, tptl);
*reg++ = IXGB_GET_STAT(adapter, tpth);
*reg++ = IXGB_GET_STAT(adapter, gptcl);
*reg++ = IXGB_GET_STAT(adapter, gptch);
*reg++ = IXGB_GET_STAT(adapter, bptcl);
*reg++ = IXGB_GET_STAT(adapter, bptch);
*reg++ = IXGB_GET_STAT(adapter, mptcl);
*reg++ = IXGB_GET_STAT(adapter, mptch);
*reg++ = IXGB_GET_STAT(adapter, uptcl);
*reg++ = IXGB_GET_STAT(adapter, uptch);
*reg++ = IXGB_GET_STAT(adapter, vptcl);
*reg++ = IXGB_GET_STAT(adapter, vptch);
*reg++ = IXGB_GET_STAT(adapter, jptcl);
*reg++ = IXGB_GET_STAT(adapter, jptch);
*reg++ = IXGB_GET_STAT(adapter, gotcl);
*reg++ = IXGB_GET_STAT(adapter, gotch);
*reg++ = IXGB_GET_STAT(adapter, totl);
*reg++ = IXGB_GET_STAT(adapter, toth);
*reg++ = IXGB_GET_STAT(adapter, dc);
*reg++ = IXGB_GET_STAT(adapter, plt64c);
*reg++ = IXGB_GET_STAT(adapter, tsctc);
*reg++ = IXGB_GET_STAT(adapter, tsctfc);
*reg++ = IXGB_GET_STAT(adapter, ibic);
*reg++ = IXGB_GET_STAT(adapter, rfc);
*reg++ = IXGB_GET_STAT(adapter, lfc);
*reg++ = IXGB_GET_STAT(adapter, pfrc);
*reg++ = IXGB_GET_STAT(adapter, pftc);
*reg++ = IXGB_GET_STAT(adapter, mcfrc);
*reg++ = IXGB_GET_STAT(adapter, mcftc);
*reg++ = IXGB_GET_STAT(adapter, xonrxc);
*reg++ = IXGB_GET_STAT(adapter, xontxc);
*reg++ = IXGB_GET_STAT(adapter, xoffrxc);
*reg++ = IXGB_GET_STAT(adapter, xofftxc);
*reg++ = IXGB_GET_STAT(adapter, rjc);
regs->len = (reg - reg_start) * sizeof(u32);
}
static int
ixgb_get_eeprom_len(struct net_device *netdev)
{
return IXGB_EEPROM_SIZE << 1;
}
static int
ixgb_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_hw *hw = &adapter->hw;
__le16 *eeprom_buff;
int i, max_len, first_word, last_word;
int ret_val = 0;
if (eeprom->len == 0) {
ret_val = -EINVAL;
goto geeprom_error;
}
eeprom->magic = hw->vendor_id | (hw->device_id << 16);
max_len = ixgb_get_eeprom_len(netdev);
if (eeprom->offset > eeprom->offset + eeprom->len) {
ret_val = -EINVAL;
goto geeprom_error;
}
if ((eeprom->offset + eeprom->len) > max_len)
eeprom->len = (max_len - eeprom->offset);
first_word = eeprom->offset >> 1;
last_word = (eeprom->offset + eeprom->len - 1) >> 1;
eeprom_buff = kmalloc(sizeof(__le16) *
(last_word - first_word + 1), GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
for (i = 0; i <= (last_word - first_word); i++)
eeprom_buff[i] = ixgb_get_eeprom_word(hw, (first_word + i));
memcpy(bytes, (u8 *)eeprom_buff + (eeprom->offset & 1), eeprom->len);
kfree(eeprom_buff);
geeprom_error:
return ret_val;
}
static int
ixgb_set_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_hw *hw = &adapter->hw;
u16 *eeprom_buff;
void *ptr;
int max_len, first_word, last_word;
u16 i;
if (eeprom->len == 0)
return -EINVAL;
if (eeprom->magic != (hw->vendor_id | (hw->device_id << 16)))
return -EFAULT;
max_len = ixgb_get_eeprom_len(netdev);
if (eeprom->offset > eeprom->offset + eeprom->len)
return -EINVAL;
if ((eeprom->offset + eeprom->len) > max_len)
eeprom->len = (max_len - eeprom->offset);
first_word = eeprom->offset >> 1;
last_word = (eeprom->offset + eeprom->len - 1) >> 1;
eeprom_buff = kmalloc(max_len, GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
ptr = (void *)eeprom_buff;
if (eeprom->offset & 1) {
eeprom_buff[0] = ixgb_read_eeprom(hw, first_word);
ptr++;
}
if ((eeprom->offset + eeprom->len) & 1) {
eeprom_buff[last_word - first_word]
= ixgb_read_eeprom(hw, last_word);
}
memcpy(ptr, bytes, eeprom->len);
for (i = 0; i <= (last_word - first_word); i++)
ixgb_write_eeprom(hw, first_word + i, eeprom_buff[i]);
if (first_word <= EEPROM_CHECKSUM_REG)
ixgb_update_eeprom_checksum(hw);
kfree(eeprom_buff);
return 0;
}
static void
ixgb_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, ixgb_driver_name,
sizeof(drvinfo->driver));
strlcpy(drvinfo->version, ixgb_driver_version,
sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
sizeof(drvinfo->bus_info));
drvinfo->n_stats = IXGB_STATS_LEN;
drvinfo->regdump_len = ixgb_get_regs_len(netdev);
drvinfo->eedump_len = ixgb_get_eeprom_len(netdev);
}
static void
ixgb_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_desc_ring *txdr = &adapter->tx_ring;
struct ixgb_desc_ring *rxdr = &adapter->rx_ring;
ring->rx_max_pending = MAX_RXD;
ring->tx_max_pending = MAX_TXD;
ring->rx_pending = rxdr->count;
ring->tx_pending = txdr->count;
}
static int
ixgb_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
struct ixgb_desc_ring *txdr = &adapter->tx_ring;
struct ixgb_desc_ring *rxdr = &adapter->rx_ring;
struct ixgb_desc_ring tx_old, tx_new, rx_old, rx_new;
int err;
tx_old = adapter->tx_ring;
rx_old = adapter->rx_ring;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
if (netif_running(adapter->netdev))
ixgb_down(adapter, true);
rxdr->count = max(ring->rx_pending,(u32)MIN_RXD);
rxdr->count = min(rxdr->count,(u32)MAX_RXD);
rxdr->count = ALIGN(rxdr->count, IXGB_REQ_RX_DESCRIPTOR_MULTIPLE);
txdr->count = max(ring->tx_pending,(u32)MIN_TXD);
txdr->count = min(txdr->count,(u32)MAX_TXD);
txdr->count = ALIGN(txdr->count, IXGB_REQ_TX_DESCRIPTOR_MULTIPLE);
if (netif_running(adapter->netdev)) {
if ((err = ixgb_setup_rx_resources(adapter)))
goto err_setup_rx;
if ((err = ixgb_setup_tx_resources(adapter)))
goto err_setup_tx;
rx_new = adapter->rx_ring;
tx_new = adapter->tx_ring;
adapter->rx_ring = rx_old;
adapter->tx_ring = tx_old;
ixgb_free_rx_resources(adapter);
ixgb_free_tx_resources(adapter);
adapter->rx_ring = rx_new;
adapter->tx_ring = tx_new;
if ((err = ixgb_up(adapter)))
return err;
ixgb_set_speed_duplex(netdev);
}
return 0;
err_setup_tx:
ixgb_free_rx_resources(adapter);
err_setup_rx:
adapter->rx_ring = rx_old;
adapter->tx_ring = tx_old;
ixgb_up(adapter);
return err;
}
static int
ixgb_set_phys_id(struct net_device *netdev, enum ethtool_phys_id_state state)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
switch (state) {
case ETHTOOL_ID_ACTIVE:
return 2;
case ETHTOOL_ID_ON:
ixgb_led_on(&adapter->hw);
break;
case ETHTOOL_ID_OFF:
case ETHTOOL_ID_INACTIVE:
ixgb_led_off(&adapter->hw);
}
return 0;
}
static int
ixgb_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return IXGB_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void
ixgb_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct ixgb_adapter *adapter = netdev_priv(netdev);
int i;
char *p = NULL;
ixgb_update_stats(adapter);
for (i = 0; i < IXGB_STATS_LEN; i++) {
switch (ixgb_gstrings_stats[i].type) {
case NETDEV_STATS:
p = (char *) netdev +
ixgb_gstrings_stats[i].stat_offset;
break;
case IXGB_STATS:
p = (char *) adapter +
ixgb_gstrings_stats[i].stat_offset;
break;
}
data[i] = (ixgb_gstrings_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
}
static void
ixgb_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
int i;
switch(stringset) {
case ETH_SS_STATS:
for (i = 0; i < IXGB_STATS_LEN; i++) {
memcpy(data + i * ETH_GSTRING_LEN,
ixgb_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
}
break;
}
}
void ixgb_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &ixgb_ethtool_ops;
}
