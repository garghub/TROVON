static int i40e_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_link_status *hw_link_info = &hw->phy.link_info;
bool link_up = hw_link_info->link_info & I40E_AQ_LINK_UP;
u32 link_speed = hw_link_info->link_speed;
if (!link_up) {
switch (hw->device_id) {
case I40E_DEV_ID_QSFP_A:
case I40E_DEV_ID_QSFP_B:
case I40E_DEV_ID_QSFP_C:
ecmd->supported = SUPPORTED_40000baseSR4_Full |
SUPPORTED_40000baseCR4_Full |
SUPPORTED_40000baseLR4_Full;
ecmd->advertising = ADVERTISED_40000baseSR4_Full |
ADVERTISED_40000baseCR4_Full |
ADVERTISED_40000baseLR4_Full;
break;
case I40E_DEV_ID_KX_B:
ecmd->supported = SUPPORTED_40000baseKR4_Full;
ecmd->advertising = ADVERTISED_40000baseKR4_Full;
break;
case I40E_DEV_ID_KX_C:
ecmd->supported = SUPPORTED_10000baseKR_Full;
ecmd->advertising = ADVERTISED_10000baseKR_Full;
break;
default:
ecmd->supported = SUPPORTED_10000baseT_Full |
SUPPORTED_1000baseT_Full;
ecmd->advertising = ADVERTISED_10000baseT_Full |
ADVERTISED_1000baseT_Full;
break;
}
goto no_valid_phy_type;
}
switch (hw_link_info->phy_type) {
case I40E_PHY_TYPE_40GBASE_CR4:
case I40E_PHY_TYPE_40GBASE_CR4_CU:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_40000baseCR4_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_40000baseCR4_Full;
break;
case I40E_PHY_TYPE_40GBASE_KR4:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_40000baseKR4_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_40000baseKR4_Full;
break;
case I40E_PHY_TYPE_40GBASE_SR4:
case I40E_PHY_TYPE_XLPPI:
case I40E_PHY_TYPE_XLAUI:
ecmd->supported = SUPPORTED_40000baseSR4_Full;
break;
case I40E_PHY_TYPE_40GBASE_LR4:
ecmd->supported = SUPPORTED_40000baseLR4_Full;
break;
case I40E_PHY_TYPE_10GBASE_KX4:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_10000baseKX4_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_10000baseKX4_Full;
break;
case I40E_PHY_TYPE_10GBASE_KR:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_10000baseKR_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_10000baseKR_Full;
break;
case I40E_PHY_TYPE_10GBASE_SR:
case I40E_PHY_TYPE_10GBASE_LR:
case I40E_PHY_TYPE_1000BASE_SX:
case I40E_PHY_TYPE_1000BASE_LX:
ecmd->supported = SUPPORTED_10000baseT_Full;
ecmd->supported |= SUPPORTED_1000baseT_Full;
break;
case I40E_PHY_TYPE_10GBASE_CR1_CU:
case I40E_PHY_TYPE_10GBASE_CR1:
case I40E_PHY_TYPE_10GBASE_T:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_10000baseT_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_10000baseT_Full;
break;
case I40E_PHY_TYPE_XAUI:
case I40E_PHY_TYPE_XFI:
case I40E_PHY_TYPE_SFI:
case I40E_PHY_TYPE_10GBASE_SFPP_CU:
ecmd->supported = SUPPORTED_10000baseT_Full;
break;
case I40E_PHY_TYPE_1000BASE_KX:
case I40E_PHY_TYPE_1000BASE_T:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_1000baseT_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_1000baseT_Full;
break;
case I40E_PHY_TYPE_100BASE_TX:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_100baseT_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_100baseT_Full;
break;
case I40E_PHY_TYPE_SGMII:
ecmd->supported = SUPPORTED_Autoneg |
SUPPORTED_1000baseT_Full |
SUPPORTED_100baseT_Full;
ecmd->advertising = ADVERTISED_Autoneg |
ADVERTISED_1000baseT_Full |
ADVERTISED_100baseT_Full;
break;
default:
netdev_info(netdev, "WARNING: Link is up but PHY type 0x%x is not recognized.\n",
hw_link_info->phy_type);
}
no_valid_phy_type:
ecmd->autoneg = ((hw_link_info->an_info & I40E_AQ_AN_COMPLETED) ?
AUTONEG_ENABLE : AUTONEG_DISABLE);
switch (hw->phy.media_type) {
case I40E_MEDIA_TYPE_BACKPLANE:
ecmd->supported |= SUPPORTED_Autoneg |
SUPPORTED_Backplane;
ecmd->advertising |= ADVERTISED_Autoneg |
ADVERTISED_Backplane;
ecmd->port = PORT_NONE;
break;
case I40E_MEDIA_TYPE_BASET:
ecmd->supported |= SUPPORTED_TP;
ecmd->advertising |= ADVERTISED_TP;
ecmd->port = PORT_TP;
break;
case I40E_MEDIA_TYPE_DA:
case I40E_MEDIA_TYPE_CX4:
ecmd->supported |= SUPPORTED_FIBRE;
ecmd->advertising |= ADVERTISED_FIBRE;
ecmd->port = PORT_DA;
break;
case I40E_MEDIA_TYPE_FIBER:
ecmd->supported |= SUPPORTED_FIBRE;
ecmd->port = PORT_FIBRE;
break;
case I40E_MEDIA_TYPE_UNKNOWN:
default:
ecmd->port = PORT_OTHER;
break;
}
ecmd->transceiver = XCVR_EXTERNAL;
ecmd->supported |= SUPPORTED_Pause;
switch (hw->fc.current_mode) {
case I40E_FC_FULL:
ecmd->advertising |= ADVERTISED_Pause;
break;
case I40E_FC_TX_PAUSE:
ecmd->advertising |= ADVERTISED_Asym_Pause;
break;
case I40E_FC_RX_PAUSE:
ecmd->advertising |= (ADVERTISED_Pause |
ADVERTISED_Asym_Pause);
break;
default:
ecmd->advertising &= ~(ADVERTISED_Pause |
ADVERTISED_Asym_Pause);
break;
}
if (link_up) {
switch (link_speed) {
case I40E_LINK_SPEED_40GB:
ethtool_cmd_speed_set(ecmd, 40000);
break;
case I40E_LINK_SPEED_10GB:
ethtool_cmd_speed_set(ecmd, SPEED_10000);
break;
case I40E_LINK_SPEED_1GB:
ethtool_cmd_speed_set(ecmd, SPEED_1000);
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
static int i40e_set_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_aq_get_phy_abilities_resp abilities;
struct i40e_aq_set_phy_config config;
struct i40e_pf *pf = np->vsi->back;
struct i40e_vsi *vsi = np->vsi;
struct i40e_hw *hw = &pf->hw;
struct ethtool_cmd safe_ecmd;
i40e_status status = 0;
bool change = false;
int err = 0;
u8 autoneg;
u32 advertise;
if (vsi != pf->vsi[pf->lan_vsi])
return -EOPNOTSUPP;
if (hw->phy.media_type != I40E_MEDIA_TYPE_BASET &&
hw->phy.media_type != I40E_MEDIA_TYPE_FIBER &&
hw->phy.media_type != I40E_MEDIA_TYPE_BACKPLANE &&
hw->phy.link_info.link_info & I40E_AQ_LINK_UP)
return -EOPNOTSUPP;
memset(&safe_ecmd, 0, sizeof(struct ethtool_cmd));
i40e_get_settings(netdev, &safe_ecmd);
autoneg = ecmd->autoneg;
advertise = ecmd->advertising;
ecmd->autoneg = safe_ecmd.autoneg;
ecmd->advertising = safe_ecmd.advertising;
ecmd->cmd = safe_ecmd.cmd;
if (memcmp(ecmd, &safe_ecmd, sizeof(struct ethtool_cmd)))
return -EOPNOTSUPP;
while (test_bit(__I40E_CONFIG_BUSY, &vsi->state))
usleep_range(1000, 2000);
status = i40e_aq_get_phy_capabilities(hw, false, false, &abilities,
NULL);
if (status)
return -EAGAIN;
memset(&config, 0, sizeof(struct i40e_aq_set_phy_config));
config.abilities = abilities.abilities;
if (autoneg == AUTONEG_ENABLE) {
if (!(safe_ecmd.supported & SUPPORTED_Autoneg)) {
netdev_info(netdev, "Autoneg not supported on this phy\n");
return -EINVAL;
}
if (!(hw->phy.link_info.an_info & I40E_AQ_AN_COMPLETED)) {
config.abilities = abilities.abilities |
I40E_AQ_PHY_ENABLE_AN;
change = true;
}
} else {
if (safe_ecmd.supported & SUPPORTED_Autoneg &&
hw->phy.link_info.phy_type != I40E_PHY_TYPE_10GBASE_T) {
netdev_info(netdev, "Autoneg cannot be disabled on this phy\n");
return -EINVAL;
}
if (hw->phy.link_info.an_info & I40E_AQ_AN_COMPLETED) {
config.abilities = abilities.abilities |
~I40E_AQ_PHY_ENABLE_AN;
change = true;
}
}
if (advertise & ~safe_ecmd.supported)
return -EINVAL;
if (advertise & ADVERTISED_100baseT_Full)
config.link_speed |= I40E_LINK_SPEED_100MB;
if (advertise & ADVERTISED_1000baseT_Full ||
advertise & ADVERTISED_1000baseKX_Full)
config.link_speed |= I40E_LINK_SPEED_1GB;
if (advertise & ADVERTISED_10000baseT_Full ||
advertise & ADVERTISED_10000baseKX4_Full ||
advertise & ADVERTISED_10000baseKR_Full)
config.link_speed |= I40E_LINK_SPEED_10GB;
if (advertise & ADVERTISED_40000baseKR4_Full ||
advertise & ADVERTISED_40000baseCR4_Full ||
advertise & ADVERTISED_40000baseSR4_Full ||
advertise & ADVERTISED_40000baseLR4_Full)
config.link_speed |= I40E_LINK_SPEED_40GB;
if (change || (abilities.link_speed != config.link_speed)) {
config.phy_type = abilities.phy_type;
config.eee_capability = abilities.eee_capability;
config.eeer = abilities.eeer_val;
config.low_power_ctrl = abilities.d3_lpan;
config.abilities |= I40E_AQ_PHY_ENABLE_ATOMIC_LINK;
if (hw->phy.link_info.link_info & I40E_AQ_LINK_UP) {
netdev_info(netdev, "PHY settings change requested, NIC Link is going down.\n");
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
}
status = i40e_aq_set_phy_config(hw, &config, NULL);
if (status) {
netdev_info(netdev, "Set phy config failed with error %d.\n",
status);
return -EAGAIN;
}
status = i40e_update_link_info(hw, true);
if (status)
netdev_info(netdev, "Updating link info failed with error %d\n",
status);
} else {
netdev_info(netdev, "Nothing changed, exiting without setting anything.\n");
}
return err;
}
static int i40e_nway_reset(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
bool link_up = hw->phy.link_info.link_info & I40E_AQ_LINK_UP;
i40e_status ret = 0;
ret = i40e_aq_set_link_restart_an(hw, link_up, NULL);
if (ret) {
netdev_info(netdev, "link restart failed, aq_err=%d\n",
pf->hw.aq.asq_last_status);
return -EIO;
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
if (hw->fc.current_mode == I40E_FC_RX_PAUSE) {
pause->rx_pause = 1;
} else if (hw->fc.current_mode == I40E_FC_TX_PAUSE) {
pause->tx_pause = 1;
} else if (hw->fc.current_mode == I40E_FC_FULL) {
pause->rx_pause = 1;
pause->tx_pause = 1;
}
}
static int i40e_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_vsi *vsi = np->vsi;
struct i40e_hw *hw = &pf->hw;
struct i40e_link_status *hw_link_info = &hw->phy.link_info;
bool link_up = hw_link_info->link_info & I40E_AQ_LINK_UP;
i40e_status status;
u8 aq_failures;
int err = 0;
if (vsi != pf->vsi[pf->lan_vsi])
return -EOPNOTSUPP;
if (pause->autoneg != ((hw_link_info->an_info & I40E_AQ_AN_COMPLETED) ?
AUTONEG_ENABLE : AUTONEG_DISABLE)) {
netdev_info(netdev, "To change autoneg please use: ethtool -s <dev> autoneg <on|off>\n");
return -EOPNOTSUPP;
}
if (!test_bit(__I40E_DOWN, &pf->state) &&
!(hw_link_info->an_info & I40E_AQ_AN_COMPLETED)) {
netdev_info(netdev, "Autoneg did not complete so changing settings may not result in an actual change.\n");
}
if (hw->fc.current_mode == I40E_FC_PFC) {
netdev_info(netdev, "Priority flow control enabled. Cannot set link flow control.\n");
return -EOPNOTSUPP;
}
if (pause->rx_pause && pause->tx_pause)
hw->fc.requested_mode = I40E_FC_FULL;
else if (pause->rx_pause && !pause->tx_pause)
hw->fc.requested_mode = I40E_FC_RX_PAUSE;
else if (!pause->rx_pause && pause->tx_pause)
hw->fc.requested_mode = I40E_FC_TX_PAUSE;
else if (!pause->rx_pause && !pause->tx_pause)
hw->fc.requested_mode = I40E_FC_NONE;
else
return -EINVAL;
netdev_info(netdev, "Flow control settings change requested, NIC Link is going down.\n");
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
status = i40e_set_fc(hw, &aq_failures, link_up);
if (aq_failures & I40E_SET_FC_AQ_FAIL_GET) {
netdev_info(netdev, "Set fc failed on the get_phy_capabilities call with error %d and status %d\n",
status, hw->aq.asq_last_status);
err = -EAGAIN;
}
if (aq_failures & I40E_SET_FC_AQ_FAIL_SET) {
netdev_info(netdev, "Set fc failed on the set_phy_config call with error %d and status %d\n",
status, hw->aq.asq_last_status);
err = -EAGAIN;
}
if (aq_failures & I40E_SET_FC_AQ_FAIL_UPDATE) {
netdev_info(netdev, "Set fc failed on the update_link_info call with error %d and status %d\n",
status, hw->aq.asq_last_status);
err = -EAGAIN;
}
if (!test_bit(__I40E_DOWN, &pf->state)) {
msleep(75);
if (!test_bit(__I40E_DOWN, &pf->state))
return i40e_nway_reset(netdev);
}
return err;
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
struct i40e_pf *pf = np->vsi->back;
int ret_val = 0, len;
u8 *eeprom_buff;
u16 i, sectors;
bool last;
u32 magic;
#define I40E_NVM_SECTOR_SIZE 4096
if (eeprom->len == 0)
return -EINVAL;
magic = hw->vendor_id | (hw->device_id << 16);
if (eeprom->magic && eeprom->magic != magic) {
int errno;
if ((eeprom->magic >> 16) != hw->device_id)
return -EINVAL;
ret_val = i40e_nvmupd_command(hw,
(struct i40e_nvm_access *)eeprom,
bytes, &errno);
if (ret_val)
dev_info(&pf->pdev->dev,
"NVMUpdate read failed err=%d status=0x%x\n",
ret_val, hw->aq.asq_last_status);
return errno;
}
eeprom->magic = hw->vendor_id | (hw->device_id << 16);
eeprom_buff = kzalloc(eeprom->len, GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
ret_val = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (ret_val) {
dev_info(&pf->pdev->dev,
"Failed Acquiring NVM resource for read err=%d status=0x%x\n",
ret_val, hw->aq.asq_last_status);
goto free_buff;
}
sectors = eeprom->len / I40E_NVM_SECTOR_SIZE;
sectors += (eeprom->len % I40E_NVM_SECTOR_SIZE) ? 1 : 0;
len = I40E_NVM_SECTOR_SIZE;
last = false;
for (i = 0; i < sectors; i++) {
if (i == (sectors - 1)) {
len = eeprom->len - (I40E_NVM_SECTOR_SIZE * i);
last = true;
}
ret_val = i40e_aq_read_nvm(hw, 0x0,
eeprom->offset + (I40E_NVM_SECTOR_SIZE * i),
len,
(u8 *)eeprom_buff + (I40E_NVM_SECTOR_SIZE * i),
last, NULL);
if (ret_val) {
dev_info(&pf->pdev->dev,
"read NVM failed err=%d status=0x%x\n",
ret_val, hw->aq.asq_last_status);
goto release_nvm;
}
}
release_nvm:
i40e_release_nvm(hw);
memcpy(bytes, (u8 *)eeprom_buff, eeprom->len);
free_buff:
kfree(eeprom_buff);
return ret_val;
}
static int i40e_get_eeprom_len(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_hw *hw = &np->vsi->back->hw;
u32 val;
val = (rd32(hw, I40E_GLPCI_LBARCTRL)
& I40E_GLPCI_LBARCTRL_FL_SIZE_MASK)
>> I40E_GLPCI_LBARCTRL_FL_SIZE_SHIFT;
val = (64 * 1024) * (1 << val);
return val;
}
static int i40e_set_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_hw *hw = &np->vsi->back->hw;
struct i40e_pf *pf = np->vsi->back;
int ret_val = 0;
int errno;
u32 magic;
magic = hw->vendor_id | (hw->device_id << 16);
if (eeprom->magic == magic)
return -EOPNOTSUPP;
if (!eeprom->magic || (eeprom->magic >> 16) != hw->device_id)
return -EINVAL;
if (test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state) ||
test_bit(__I40E_RESET_INTR_RECEIVED, &pf->state))
return -EBUSY;
ret_val = i40e_nvmupd_command(hw, (struct i40e_nvm_access *)eeprom,
bytes, &errno);
if (ret_val)
dev_info(&pf->pdev->dev,
"NVMUpdate write failed err=%d status=0x%x\n",
ret_val, hw->aq.asq_last_status);
return errno;
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
ring->rx_pending = vsi->rx_rings[0]->count;
ring->tx_pending = vsi->tx_rings[0]->count;
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
if (ring->tx_pending > I40E_MAX_NUM_DESCRIPTORS ||
ring->tx_pending < I40E_MIN_NUM_DESCRIPTORS ||
ring->rx_pending > I40E_MAX_NUM_DESCRIPTORS ||
ring->rx_pending < I40E_MIN_NUM_DESCRIPTORS) {
netdev_info(netdev,
"Descriptors requested (Tx: %d / Rx: %d) out of range [%d-%d]\n",
ring->tx_pending, ring->rx_pending,
I40E_MIN_NUM_DESCRIPTORS, I40E_MAX_NUM_DESCRIPTORS);
return -EINVAL;
}
new_tx_count = ALIGN(ring->tx_pending, I40E_REQ_DESCRIPTOR_MULTIPLE);
new_rx_count = ALIGN(ring->rx_pending, I40E_REQ_DESCRIPTOR_MULTIPLE);
if ((new_tx_count == vsi->tx_rings[0]->count) &&
(new_rx_count == vsi->rx_rings[0]->count))
return 0;
while (test_and_set_bit(__I40E_CONFIG_BUSY, &pf->state))
usleep_range(1000, 2000);
if (!netif_running(vsi->netdev)) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
vsi->tx_rings[i]->count = new_tx_count;
vsi->rx_rings[i]->count = new_rx_count;
}
goto done;
}
if (new_tx_count != vsi->tx_rings[0]->count) {
netdev_info(netdev,
"Changing Tx descriptor count from %d to %d.\n",
vsi->tx_rings[0]->count, new_tx_count);
tx_rings = kcalloc(vsi->alloc_queue_pairs,
sizeof(struct i40e_ring), GFP_KERNEL);
if (!tx_rings) {
err = -ENOMEM;
goto done;
}
for (i = 0; i < vsi->num_queue_pairs; i++) {
tx_rings[i] = *vsi->tx_rings[i];
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
if (new_rx_count != vsi->rx_rings[0]->count) {
netdev_info(netdev,
"Changing Rx descriptor count from %d to %d\n",
vsi->rx_rings[0]->count, new_rx_count);
rx_rings = kcalloc(vsi->alloc_queue_pairs,
sizeof(struct i40e_ring), GFP_KERNEL);
if (!rx_rings) {
err = -ENOMEM;
goto free_tx;
}
for (i = 0; i < vsi->num_queue_pairs; i++) {
rx_rings[i] = *vsi->rx_rings[i];
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
i40e_free_tx_resources(vsi->tx_rings[i]);
*vsi->tx_rings[i] = tx_rings[i];
}
kfree(tx_rings);
tx_rings = NULL;
}
if (rx_rings) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
i40e_free_rx_resources(vsi->rx_rings[i]);
*vsi->rx_rings[i] = rx_rings[i];
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
if (vsi == pf->vsi[pf->lan_vsi]) {
int len = I40E_PF_STATS_LEN(netdev);
if (pf->lan_veb != I40E_NO_VEB)
len += I40E_VEB_STATS_LEN;
return len;
} else {
return I40E_VSI_STATS_LEN(netdev);
}
default:
return -EOPNOTSUPP;
}
}
static void i40e_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_ring *tx_ring, *rx_ring;
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int i = 0;
char *p;
int j;
struct rtnl_link_stats64 *net_stats = i40e_get_vsi_stats_struct(vsi);
unsigned int start;
i40e_update_stats(vsi);
for (j = 0; j < I40E_NETDEV_STATS_LEN; j++) {
p = (char *)net_stats + i40e_gstrings_net_stats[j].stat_offset;
data[i++] = (i40e_gstrings_net_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
for (j = 0; j < I40E_MISC_STATS_LEN; j++) {
p = (char *)vsi + i40e_gstrings_misc_stats[j].stat_offset;
data[i++] = (i40e_gstrings_misc_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
#ifdef I40E_FCOE
for (j = 0; j < I40E_FCOE_STATS_LEN; j++) {
p = (char *)vsi + i40e_gstrings_fcoe_stats[j].stat_offset;
data[i++] = (i40e_gstrings_fcoe_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
#endif
rcu_read_lock();
for (j = 0; j < vsi->num_queue_pairs; j++) {
tx_ring = ACCESS_ONCE(vsi->tx_rings[j]);
if (!tx_ring)
continue;
do {
start = u64_stats_fetch_begin_irq(&tx_ring->syncp);
data[i] = tx_ring->stats.packets;
data[i + 1] = tx_ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&tx_ring->syncp, start));
i += 2;
rx_ring = &tx_ring[1];
do {
start = u64_stats_fetch_begin_irq(&rx_ring->syncp);
data[i] = rx_ring->stats.packets;
data[i + 1] = rx_ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&rx_ring->syncp, start));
i += 2;
}
rcu_read_unlock();
if (vsi != pf->vsi[pf->lan_vsi])
return;
if (pf->lan_veb != I40E_NO_VEB) {
struct i40e_veb *veb = pf->veb[pf->lan_veb];
for (j = 0; j < I40E_VEB_STATS_LEN; j++) {
p = (char *)veb;
p += i40e_gstrings_veb_stats[j].stat_offset;
data[i++] = (i40e_gstrings_veb_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
}
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
for (i = 0; i < I40E_MISC_STATS_LEN; i++) {
snprintf(p, ETH_GSTRING_LEN, "%s",
i40e_gstrings_misc_stats[i].stat_string);
p += ETH_GSTRING_LEN;
}
#ifdef I40E_FCOE
for (i = 0; i < I40E_FCOE_STATS_LEN; i++) {
snprintf(p, ETH_GSTRING_LEN, "%s",
i40e_gstrings_fcoe_stats[i].stat_string);
p += ETH_GSTRING_LEN;
}
#endif
for (i = 0; i < vsi->num_queue_pairs; i++) {
snprintf(p, ETH_GSTRING_LEN, "tx-%u.tx_packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "tx-%u.tx_bytes", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx-%u.rx_packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx-%u.rx_bytes", i);
p += ETH_GSTRING_LEN;
}
if (vsi != pf->vsi[pf->lan_vsi])
return;
if (pf->lan_veb != I40E_NO_VEB) {
for (i = 0; i < I40E_VEB_STATS_LEN; i++) {
snprintf(p, ETH_GSTRING_LEN, "veb.%s",
i40e_gstrings_veb_stats[i].stat_string);
p += ETH_GSTRING_LEN;
}
}
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
break;
}
}
static int i40e_get_ts_info(struct net_device *dev,
struct ethtool_ts_info *info)
{
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
if (pf->ptp_clock)
info->phc_index = ptp_clock_index(pf->ptp_clock);
else
info->phc_index = -1;
info->tx_types = (1 << HWTSTAMP_TX_OFF) | (1 << HWTSTAMP_TX_ON);
info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_L2_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_L2_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ);
return 0;
}
static int i40e_link_test(struct net_device *netdev, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
netif_info(pf, hw, netdev, "link test\n");
if (i40e_get_link_status(&pf->hw))
*data = 0;
else
*data = 1;
return *data;
}
static int i40e_reg_test(struct net_device *netdev, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
netif_info(pf, hw, netdev, "register test\n");
*data = i40e_diag_reg_test(&pf->hw);
return *data;
}
static int i40e_eeprom_test(struct net_device *netdev, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
netif_info(pf, hw, netdev, "eeprom test\n");
*data = i40e_diag_eeprom_test(&pf->hw);
return *data;
}
static int i40e_intr_test(struct net_device *netdev, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
u16 swc_old = pf->sw_int_count;
netif_info(pf, hw, netdev, "interrupt test\n");
wr32(&pf->hw, I40E_PFINT_DYN_CTL0,
(I40E_PFINT_DYN_CTL0_INTENA_MASK |
I40E_PFINT_DYN_CTL0_SWINT_TRIG_MASK));
usleep_range(1000, 2000);
*data = (swc_old == pf->sw_int_count);
return *data;
}
static int i40e_loopback_test(struct net_device *netdev, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
netif_info(pf, hw, netdev, "loopback test not implemented\n");
*data = 0;
return *data;
}
static void i40e_diag_test(struct net_device *netdev,
struct ethtool_test *eth_test, u64 *data)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
if (eth_test->flags == ETH_TEST_FL_OFFLINE) {
netif_info(pf, drv, netdev, "offline testing starting\n");
set_bit(__I40E_TESTING, &pf->state);
if (i40e_link_test(netdev, &data[I40E_ETH_TEST_LINK]))
eth_test->flags |= ETH_TEST_FL_FAILED;
if (i40e_eeprom_test(netdev, &data[I40E_ETH_TEST_EEPROM]))
eth_test->flags |= ETH_TEST_FL_FAILED;
if (i40e_intr_test(netdev, &data[I40E_ETH_TEST_INTR]))
eth_test->flags |= ETH_TEST_FL_FAILED;
if (i40e_loopback_test(netdev, &data[I40E_ETH_TEST_LOOPBACK]))
eth_test->flags |= ETH_TEST_FL_FAILED;
if (i40e_reg_test(netdev, &data[I40E_ETH_TEST_REG]))
eth_test->flags |= ETH_TEST_FL_FAILED;
clear_bit(__I40E_TESTING, &pf->state);
i40e_do_reset(pf, (1 << __I40E_PF_RESET_REQUESTED));
} else {
netif_info(pf, drv, netdev, "online testing starting\n");
if (i40e_link_test(netdev, &data[I40E_ETH_TEST_LINK]))
eth_test->flags |= ETH_TEST_FL_FAILED;
data[I40E_ETH_TEST_REG] = 0;
data[I40E_ETH_TEST_EEPROM] = 0;
data[I40E_ETH_TEST_INTR] = 0;
data[I40E_ETH_TEST_LOOPBACK] = 0;
}
netif_info(pf, drv, netdev, "testing finished\n");
}
static void i40e_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 wol_nvm_bits;
i40e_read_nvm_word(hw, I40E_SR_NVM_WAKE_ON_LAN, &wol_nvm_bits);
if ((1 << hw->port) & wol_nvm_bits) {
wol->supported = 0;
wol->wolopts = 0;
} else {
wol->supported = WAKE_MAGIC;
wol->wolopts = (pf->wol_en ? WAKE_MAGIC : 0);
}
}
static int i40e_set_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 wol_nvm_bits;
i40e_read_nvm_word(hw, I40E_SR_NVM_WAKE_ON_LAN, &wol_nvm_bits);
if (((1 << hw->port) & wol_nvm_bits))
return -EOPNOTSUPP;
if (wol->wolopts && (wol->wolopts != WAKE_MAGIC))
return -EOPNOTSUPP;
if (pf->wol_en != !!wol->wolopts) {
pf->wol_en = !!wol->wolopts;
device_set_wakeup_enable(&pf->pdev->dev, pf->wol_en);
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
i40e_led_set(hw, 0xF, false);
break;
case ETHTOOL_ID_OFF:
i40e_led_set(hw, 0x0, false);
break;
case ETHTOOL_ID_INACTIVE:
i40e_led_set(hw, pf->led_status, false);
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
ec->use_adaptive_rx_coalesce = 1;
if (ITR_IS_DYNAMIC(vsi->tx_itr_setting))
ec->use_adaptive_tx_coalesce = 1;
ec->rx_coalesce_usecs = vsi->rx_itr_setting & ~I40E_ITR_DYNAMIC;
ec->tx_coalesce_usecs = vsi->tx_itr_setting & ~I40E_ITR_DYNAMIC;
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
vector = vsi->base_vector;
if ((ec->rx_coalesce_usecs >= (I40E_MIN_ITR << 1)) &&
(ec->rx_coalesce_usecs <= (I40E_MAX_ITR << 1))) {
vsi->rx_itr_setting = ec->rx_coalesce_usecs;
} else if (ec->rx_coalesce_usecs == 0) {
vsi->rx_itr_setting = ec->rx_coalesce_usecs;
i40e_irq_dynamic_disable(vsi, vector);
if (ec->use_adaptive_rx_coalesce)
netif_info(pf, drv, netdev,
"Rx-secs=0, need to disable adaptive-Rx for a complete disable\n");
} else {
netif_info(pf, drv, netdev,
"Invalid value, Rx-usecs range is 0, 8-8160\n");
return -EINVAL;
}
if ((ec->tx_coalesce_usecs >= (I40E_MIN_ITR << 1)) &&
(ec->tx_coalesce_usecs <= (I40E_MAX_ITR << 1))) {
vsi->tx_itr_setting = ec->tx_coalesce_usecs;
} else if (ec->tx_coalesce_usecs == 0) {
vsi->tx_itr_setting = ec->tx_coalesce_usecs;
i40e_irq_dynamic_disable(vsi, vector);
if (ec->use_adaptive_tx_coalesce)
netif_info(pf, drv, netdev,
"Tx-secs=0, need to disable adaptive-Tx for a complete disable\n");
} else {
netif_info(pf, drv, netdev,
"Invalid value, Tx-usecs range is 0, 8-8160\n");
return -EINVAL;
}
if (ec->use_adaptive_rx_coalesce)
vsi->rx_itr_setting |= I40E_ITR_DYNAMIC;
else
vsi->rx_itr_setting &= ~I40E_ITR_DYNAMIC;
if (ec->use_adaptive_tx_coalesce)
vsi->tx_itr_setting |= I40E_ITR_DYNAMIC;
else
vsi->tx_itr_setting &= ~I40E_ITR_DYNAMIC;
for (i = 0; i < vsi->num_q_vectors; i++, vector++) {
q_vector = vsi->q_vectors[i];
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
static int i40e_get_ethtool_fdir_all(struct i40e_pf *pf,
struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct i40e_fdir_filter *rule;
struct hlist_node *node2;
int cnt = 0;
cmd->data = i40e_get_fd_cnt_all(pf);
hlist_for_each_entry_safe(rule, node2,
&pf->fdir_filter_list, fdir_node) {
if (cnt == cmd->rule_cnt)
return -EMSGSIZE;
rule_locs[cnt] = rule->fd_id;
cnt++;
}
cmd->rule_cnt = cnt;
return 0;
}
static int i40e_get_ethtool_fdir_entry(struct i40e_pf *pf,
struct ethtool_rxnfc *cmd)
{
struct ethtool_rx_flow_spec *fsp =
(struct ethtool_rx_flow_spec *)&cmd->fs;
struct i40e_fdir_filter *rule = NULL;
struct hlist_node *node2;
hlist_for_each_entry_safe(rule, node2,
&pf->fdir_filter_list, fdir_node) {
if (fsp->location <= rule->fd_id)
break;
}
if (!rule || fsp->location != rule->fd_id)
return -EINVAL;
fsp->flow_type = rule->flow_type;
if (fsp->flow_type == IP_USER_FLOW) {
fsp->h_u.usr_ip4_spec.ip_ver = ETH_RX_NFC_IP4;
fsp->h_u.usr_ip4_spec.proto = 0;
fsp->m_u.usr_ip4_spec.proto = 0;
}
fsp->h_u.tcp_ip4_spec.psrc = rule->dst_port;
fsp->h_u.tcp_ip4_spec.pdst = rule->src_port;
fsp->h_u.tcp_ip4_spec.ip4src = rule->dst_ip[0];
fsp->h_u.tcp_ip4_spec.ip4dst = rule->src_ip[0];
if (rule->dest_ctl == I40E_FILTER_PROGRAM_DESC_DEST_DROP_PACKET)
fsp->ring_cookie = RX_CLS_FLOW_DISC;
else
fsp->ring_cookie = rule->q_index;
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
cmd->rule_cnt = pf->fdir_pf_active_filters;
cmd->data = i40e_get_fd_cnt_all(pf);
ret = 0;
break;
case ETHTOOL_GRXCLSRULE:
ret = i40e_get_ethtool_fdir_entry(pf, cmd);
break;
case ETHTOOL_GRXCLSRLALL:
ret = i40e_get_ethtool_fdir_all(pf, cmd, rule_locs);
break;
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
hena &= ~(((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV4_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV4));
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
hena |= (((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV4_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV4));
break;
default:
return -EINVAL;
}
break;
case UDP_V6_FLOW:
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
hena &= ~(((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV6_UDP) |
((u64)1 << I40E_FILTER_PCTYPE_FRAG_IPV6));
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
hena |= (((u64)1 << I40E_FILTER_PCTYPE_NONF_IPV6_UDP) |
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
static bool i40e_match_fdir_input_set(struct i40e_fdir_filter *rule,
struct i40e_fdir_filter *input)
{
if ((rule->dst_ip[0] != input->dst_ip[0]) ||
(rule->src_ip[0] != input->src_ip[0]) ||
(rule->dst_port != input->dst_port) ||
(rule->src_port != input->src_port))
return false;
return true;
}
static int i40e_update_ethtool_fdir_entry(struct i40e_vsi *vsi,
struct i40e_fdir_filter *input,
u16 sw_idx,
struct ethtool_rxnfc *cmd)
{
struct i40e_fdir_filter *rule, *parent;
struct i40e_pf *pf = vsi->back;
struct hlist_node *node2;
int err = -EINVAL;
parent = NULL;
rule = NULL;
hlist_for_each_entry_safe(rule, node2,
&pf->fdir_filter_list, fdir_node) {
if (rule->fd_id >= sw_idx)
break;
parent = rule;
}
if (rule && (rule->fd_id == sw_idx)) {
if (input && !i40e_match_fdir_input_set(rule, input))
err = i40e_add_del_fdir(vsi, rule, false);
else if (!input)
err = i40e_add_del_fdir(vsi, rule, false);
hlist_del(&rule->fdir_node);
kfree(rule);
pf->fdir_pf_active_filters--;
}
if (!input)
return err;
INIT_HLIST_NODE(&input->fdir_node);
if (parent)
hlist_add_behind(&input->fdir_node, &parent->fdir_node);
else
hlist_add_head(&input->fdir_node,
&pf->fdir_filter_list);
pf->fdir_pf_active_filters++;
return 0;
}
static int i40e_del_fdir_entry(struct i40e_vsi *vsi,
struct ethtool_rxnfc *cmd)
{
struct ethtool_rx_flow_spec *fsp =
(struct ethtool_rx_flow_spec *)&cmd->fs;
struct i40e_pf *pf = vsi->back;
int ret = 0;
if (test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state) ||
test_bit(__I40E_RESET_INTR_RECEIVED, &pf->state))
return -EBUSY;
if (test_bit(__I40E_FD_FLUSH_REQUESTED, &pf->state))
return -EBUSY;
ret = i40e_update_ethtool_fdir_entry(vsi, NULL, fsp->location, cmd);
i40e_fdir_check_and_reenable(pf);
return ret;
}
static int i40e_add_fdir_ethtool(struct i40e_vsi *vsi,
struct ethtool_rxnfc *cmd)
{
struct ethtool_rx_flow_spec *fsp;
struct i40e_fdir_filter *input;
struct i40e_pf *pf;
int ret = -EINVAL;
if (!vsi)
return -EINVAL;
pf = vsi->back;
if (!(pf->flags & I40E_FLAG_FD_SB_ENABLED))
return -EOPNOTSUPP;
if (pf->auto_disable_flags & I40E_FLAG_FD_SB_ENABLED)
return -ENOSPC;
if (test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state) ||
test_bit(__I40E_RESET_INTR_RECEIVED, &pf->state))
return -EBUSY;
if (test_bit(__I40E_FD_FLUSH_REQUESTED, &pf->state))
return -EBUSY;
fsp = (struct ethtool_rx_flow_spec *)&cmd->fs;
if (fsp->location >= (pf->hw.func_caps.fd_filters_best_effort +
pf->hw.func_caps.fd_filters_guaranteed)) {
return -EINVAL;
}
if ((fsp->ring_cookie != RX_CLS_FLOW_DISC) &&
(fsp->ring_cookie >= vsi->num_queue_pairs))
return -EINVAL;
input = kzalloc(sizeof(*input), GFP_KERNEL);
if (!input)
return -ENOMEM;
input->fd_id = fsp->location;
if (fsp->ring_cookie == RX_CLS_FLOW_DISC)
input->dest_ctl = I40E_FILTER_PROGRAM_DESC_DEST_DROP_PACKET;
else
input->dest_ctl =
I40E_FILTER_PROGRAM_DESC_DEST_DIRECT_PACKET_QINDEX;
input->q_index = fsp->ring_cookie;
input->flex_off = 0;
input->pctype = 0;
input->dest_vsi = vsi->id;
input->fd_status = I40E_FILTER_PROGRAM_DESC_FD_STATUS_FD_ID;
input->cnt_index = pf->fd_sb_cnt_idx;
input->flow_type = fsp->flow_type;
input->ip4_proto = fsp->h_u.usr_ip4_spec.proto;
input->dst_port = fsp->h_u.tcp_ip4_spec.psrc;
input->src_port = fsp->h_u.tcp_ip4_spec.pdst;
input->dst_ip[0] = fsp->h_u.tcp_ip4_spec.ip4src;
input->src_ip[0] = fsp->h_u.tcp_ip4_spec.ip4dst;
ret = i40e_add_del_fdir(vsi, input, true);
if (ret)
kfree(input);
else
i40e_update_ethtool_fdir_entry(vsi, input, fsp->location, NULL);
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
ret = i40e_add_fdir_ethtool(vsi, cmd);
break;
case ETHTOOL_SRXCLSRLDEL:
ret = i40e_del_fdir_entry(vsi, cmd);
break;
default:
break;
}
return ret;
}
static unsigned int i40e_max_channels(struct i40e_vsi *vsi)
{
return vsi->alloc_queue_pairs;
}
static void i40e_get_channels(struct net_device *dev,
struct ethtool_channels *ch)
{
struct i40e_netdev_priv *np = netdev_priv(dev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
ch->max_combined = i40e_max_channels(vsi);
ch->other_count = (pf->flags & I40E_FLAG_FD_SB_ENABLED) ? 1 : 0;
ch->max_other = ch->other_count;
ch->combined_count = vsi->num_queue_pairs;
}
static int i40e_set_channels(struct net_device *dev,
struct ethtool_channels *ch)
{
struct i40e_netdev_priv *np = netdev_priv(dev);
unsigned int count = ch->combined_count;
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int new_count;
if (vsi->type != I40E_VSI_MAIN)
return -EINVAL;
if (!count || ch->rx_count || ch->tx_count)
return -EINVAL;
if (ch->other_count != ((pf->flags & I40E_FLAG_FD_SB_ENABLED) ? 1 : 0))
return -EINVAL;
if (count > i40e_max_channels(vsi))
return -EINVAL;
if (count > pf->rss_size_max)
count = pf->rss_size_max;
new_count = i40e_reconfig_rss_queues(pf, count);
if (new_count > 0)
return 0;
else
return -EINVAL;
}
void i40e_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &i40e_ethtool_ops;
}
