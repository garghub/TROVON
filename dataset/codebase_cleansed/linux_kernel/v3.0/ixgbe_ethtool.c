static int ixgbe_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 link_speed = 0;
bool link_up;
ecmd->supported = SUPPORTED_10000baseT_Full;
ecmd->autoneg = AUTONEG_ENABLE;
ecmd->transceiver = XCVR_EXTERNAL;
if ((hw->phy.media_type == ixgbe_media_type_copper) ||
(hw->phy.multispeed_fiber)) {
ecmd->supported |= (SUPPORTED_1000baseT_Full |
SUPPORTED_Autoneg);
switch (hw->mac.type) {
case ixgbe_mac_X540:
ecmd->supported |= SUPPORTED_100baseT_Full;
break;
default:
break;
}
ecmd->advertising = ADVERTISED_Autoneg;
if (hw->phy.autoneg_advertised) {
if (hw->phy.autoneg_advertised &
IXGBE_LINK_SPEED_100_FULL)
ecmd->advertising |= ADVERTISED_100baseT_Full;
if (hw->phy.autoneg_advertised &
IXGBE_LINK_SPEED_10GB_FULL)
ecmd->advertising |= ADVERTISED_10000baseT_Full;
if (hw->phy.autoneg_advertised &
IXGBE_LINK_SPEED_1GB_FULL)
ecmd->advertising |= ADVERTISED_1000baseT_Full;
} else {
ecmd->advertising |= (ADVERTISED_10000baseT_Full |
ADVERTISED_1000baseT_Full);
if (hw->mac.type == ixgbe_mac_X540)
ecmd->advertising |= ADVERTISED_100baseT_Full;
}
if (hw->phy.media_type == ixgbe_media_type_copper) {
ecmd->supported |= SUPPORTED_TP;
ecmd->advertising |= ADVERTISED_TP;
ecmd->port = PORT_TP;
} else {
ecmd->supported |= SUPPORTED_FIBRE;
ecmd->advertising |= ADVERTISED_FIBRE;
ecmd->port = PORT_FIBRE;
}
} else if (hw->phy.media_type == ixgbe_media_type_backplane) {
if (hw->device_id == IXGBE_DEV_ID_82598_BX) {
ecmd->supported = (SUPPORTED_1000baseT_Full |
SUPPORTED_FIBRE);
ecmd->advertising = (ADVERTISED_1000baseT_Full |
ADVERTISED_FIBRE);
ecmd->port = PORT_FIBRE;
ecmd->autoneg = AUTONEG_DISABLE;
} else if ((hw->device_id == IXGBE_DEV_ID_82599_COMBO_BACKPLANE) ||
(hw->device_id == IXGBE_DEV_ID_82599_KX4_MEZZ)) {
ecmd->supported |= (SUPPORTED_1000baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_FIBRE);
ecmd->advertising = (ADVERTISED_10000baseT_Full |
ADVERTISED_1000baseT_Full |
ADVERTISED_Autoneg |
ADVERTISED_FIBRE);
ecmd->port = PORT_FIBRE;
} else {
ecmd->supported |= (SUPPORTED_1000baseT_Full |
SUPPORTED_FIBRE);
ecmd->advertising = (ADVERTISED_10000baseT_Full |
ADVERTISED_1000baseT_Full |
ADVERTISED_FIBRE);
ecmd->port = PORT_FIBRE;
}
} else {
ecmd->supported |= SUPPORTED_FIBRE;
ecmd->advertising = (ADVERTISED_10000baseT_Full |
ADVERTISED_FIBRE);
ecmd->port = PORT_FIBRE;
ecmd->autoneg = AUTONEG_DISABLE;
}
switch (adapter->hw.phy.type) {
case ixgbe_phy_tn:
case ixgbe_phy_aq:
case ixgbe_phy_cu_unknown:
ecmd->port = PORT_TP;
break;
case ixgbe_phy_qt:
ecmd->port = PORT_FIBRE;
break;
case ixgbe_phy_nl:
case ixgbe_phy_sfp_passive_tyco:
case ixgbe_phy_sfp_passive_unknown:
case ixgbe_phy_sfp_ftl:
case ixgbe_phy_sfp_avago:
case ixgbe_phy_sfp_intel:
case ixgbe_phy_sfp_unknown:
switch (adapter->hw.phy.sfp_type) {
case ixgbe_sfp_type_da_cu:
case ixgbe_sfp_type_da_cu_core0:
case ixgbe_sfp_type_da_cu_core1:
ecmd->port = PORT_DA;
break;
case ixgbe_sfp_type_sr:
case ixgbe_sfp_type_lr:
case ixgbe_sfp_type_srlr_core0:
case ixgbe_sfp_type_srlr_core1:
ecmd->port = PORT_FIBRE;
break;
case ixgbe_sfp_type_not_present:
ecmd->port = PORT_NONE;
break;
case ixgbe_sfp_type_1g_cu_core0:
case ixgbe_sfp_type_1g_cu_core1:
ecmd->port = PORT_TP;
ecmd->supported = SUPPORTED_TP;
ecmd->advertising = (ADVERTISED_1000baseT_Full |
ADVERTISED_TP);
break;
case ixgbe_sfp_type_unknown:
default:
ecmd->port = PORT_OTHER;
break;
}
break;
case ixgbe_phy_xaui:
ecmd->port = PORT_NONE;
break;
case ixgbe_phy_unknown:
case ixgbe_phy_generic:
case ixgbe_phy_sfp_unsupported:
default:
ecmd->port = PORT_OTHER;
break;
}
hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
if (link_up) {
switch (link_speed) {
case IXGBE_LINK_SPEED_10GB_FULL:
ethtool_cmd_speed_set(ecmd, SPEED_10000);
break;
case IXGBE_LINK_SPEED_1GB_FULL:
ethtool_cmd_speed_set(ecmd, SPEED_1000);
break;
case IXGBE_LINK_SPEED_100_FULL:
ethtool_cmd_speed_set(ecmd, SPEED_100);
break;
default:
break;
}
ecmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(ecmd, -1);
ecmd->duplex = -1;
}
return 0;
}
static int ixgbe_set_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 advertised, old;
s32 err = 0;
if ((hw->phy.media_type == ixgbe_media_type_copper) ||
(hw->phy.multispeed_fiber)) {
if (ecmd->autoneg == AUTONEG_DISABLE)
return -EINVAL;
old = hw->phy.autoneg_advertised;
advertised = 0;
if (ecmd->advertising & ADVERTISED_10000baseT_Full)
advertised |= IXGBE_LINK_SPEED_10GB_FULL;
if (ecmd->advertising & ADVERTISED_1000baseT_Full)
advertised |= IXGBE_LINK_SPEED_1GB_FULL;
if (ecmd->advertising & ADVERTISED_100baseT_Full)
advertised |= IXGBE_LINK_SPEED_100_FULL;
if (old == advertised)
return err;
hw->mac.autotry_restart = true;
err = hw->mac.ops.setup_link(hw, advertised, true, true);
if (err) {
e_info(probe, "setup link failed with code %d\n", err);
hw->mac.ops.setup_link(hw, old, true, true);
}
} else {
u32 speed = ethtool_cmd_speed(ecmd);
if ((ecmd->autoneg == AUTONEG_ENABLE) ||
(ecmd->advertising != ADVERTISED_10000baseT_Full) ||
(speed + ecmd->duplex != SPEED_10000 + DUPLEX_FULL))
return -EINVAL;
}
return err;
}
static void ixgbe_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
if (hw->fc.disable_fc_autoneg ||
(hw->fc.current_mode == ixgbe_fc_none))
pause->autoneg = 0;
else
pause->autoneg = 1;
if (hw->fc.current_mode == ixgbe_fc_rx_pause) {
pause->rx_pause = 1;
} else if (hw->fc.current_mode == ixgbe_fc_tx_pause) {
pause->tx_pause = 1;
} else if (hw->fc.current_mode == ixgbe_fc_full) {
pause->rx_pause = 1;
pause->tx_pause = 1;
#ifdef CONFIG_DCB
} else if (hw->fc.current_mode == ixgbe_fc_pfc) {
pause->rx_pause = 0;
pause->tx_pause = 0;
#endif
}
}
static int ixgbe_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_fc_info fc;
#ifdef CONFIG_DCB
if (adapter->dcb_cfg.pfc_mode_enable ||
((hw->mac.type == ixgbe_mac_82598EB) &&
(adapter->flags & IXGBE_FLAG_DCB_ENABLED)))
return -EINVAL;
#endif
fc = hw->fc;
if (pause->autoneg != AUTONEG_ENABLE)
fc.disable_fc_autoneg = true;
else
fc.disable_fc_autoneg = false;
if ((pause->rx_pause && pause->tx_pause) || pause->autoneg)
fc.requested_mode = ixgbe_fc_full;
else if (pause->rx_pause && !pause->tx_pause)
fc.requested_mode = ixgbe_fc_rx_pause;
else if (!pause->rx_pause && pause->tx_pause)
fc.requested_mode = ixgbe_fc_tx_pause;
else if (!pause->rx_pause && !pause->tx_pause)
fc.requested_mode = ixgbe_fc_none;
else
return -EINVAL;
#ifdef CONFIG_DCB
adapter->last_lfc_mode = fc.requested_mode;
#endif
if (memcmp(&fc, &hw->fc, sizeof(struct ixgbe_fc_info))) {
hw->fc = fc;
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
else
ixgbe_reset(adapter);
}
return 0;
}
static u32 ixgbe_get_rx_csum(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
return adapter->flags & IXGBE_FLAG_RX_CSUM_ENABLED;
}
static int ixgbe_set_rx_csum(struct net_device *netdev, u32 data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (data)
adapter->flags |= IXGBE_FLAG_RX_CSUM_ENABLED;
else
adapter->flags &= ~IXGBE_FLAG_RX_CSUM_ENABLED;
return 0;
}
static u32 ixgbe_get_tx_csum(struct net_device *netdev)
{
return (netdev->features & NETIF_F_IP_CSUM) != 0;
}
static int ixgbe_set_tx_csum(struct net_device *netdev, u32 data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
u32 feature_list;
feature_list = (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM);
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
feature_list |= NETIF_F_SCTP_CSUM;
break;
default:
break;
}
if (data)
netdev->features |= feature_list;
else
netdev->features &= ~feature_list;
return 0;
}
static int ixgbe_set_tso(struct net_device *netdev, u32 data)
{
if (data) {
netdev->features |= NETIF_F_TSO;
netdev->features |= NETIF_F_TSO6;
} else {
netdev->features &= ~NETIF_F_TSO;
netdev->features &= ~NETIF_F_TSO6;
}
return 0;
}
static u32 ixgbe_get_msglevel(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
return adapter->msg_enable;
}
static void ixgbe_set_msglevel(struct net_device *netdev, u32 data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
adapter->msg_enable = data;
}
static int ixgbe_get_regs_len(struct net_device *netdev)
{
#define IXGBE_REGS_LEN 1128
return IXGBE_REGS_LEN * sizeof(u32);
}
static void ixgbe_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 *regs_buff = p;
u8 i;
memset(p, 0, IXGBE_REGS_LEN * sizeof(u32));
regs->version = (1 << 24) | hw->revision_id << 16 | hw->device_id;
regs_buff[0] = IXGBE_READ_REG(hw, IXGBE_CTRL);
regs_buff[1] = IXGBE_READ_REG(hw, IXGBE_STATUS);
regs_buff[2] = IXGBE_READ_REG(hw, IXGBE_CTRL_EXT);
regs_buff[3] = IXGBE_READ_REG(hw, IXGBE_ESDP);
regs_buff[4] = IXGBE_READ_REG(hw, IXGBE_EODSDP);
regs_buff[5] = IXGBE_READ_REG(hw, IXGBE_LEDCTL);
regs_buff[6] = IXGBE_READ_REG(hw, IXGBE_FRTIMER);
regs_buff[7] = IXGBE_READ_REG(hw, IXGBE_TCPTIMER);
regs_buff[8] = IXGBE_READ_REG(hw, IXGBE_EEC);
regs_buff[9] = IXGBE_READ_REG(hw, IXGBE_EERD);
regs_buff[10] = IXGBE_READ_REG(hw, IXGBE_FLA);
regs_buff[11] = IXGBE_READ_REG(hw, IXGBE_EEMNGCTL);
regs_buff[12] = IXGBE_READ_REG(hw, IXGBE_EEMNGDATA);
regs_buff[13] = IXGBE_READ_REG(hw, IXGBE_FLMNGCTL);
regs_buff[14] = IXGBE_READ_REG(hw, IXGBE_FLMNGDATA);
regs_buff[15] = IXGBE_READ_REG(hw, IXGBE_FLMNGCNT);
regs_buff[16] = IXGBE_READ_REG(hw, IXGBE_FLOP);
regs_buff[17] = IXGBE_READ_REG(hw, IXGBE_GRC);
regs_buff[18] = IXGBE_READ_REG(hw, IXGBE_EICS);
regs_buff[19] = IXGBE_READ_REG(hw, IXGBE_EICS);
regs_buff[20] = IXGBE_READ_REG(hw, IXGBE_EIMS);
regs_buff[21] = IXGBE_READ_REG(hw, IXGBE_EIMC);
regs_buff[22] = IXGBE_READ_REG(hw, IXGBE_EIAC);
regs_buff[23] = IXGBE_READ_REG(hw, IXGBE_EIAM);
regs_buff[24] = IXGBE_READ_REG(hw, IXGBE_EITR(0));
regs_buff[25] = IXGBE_READ_REG(hw, IXGBE_IVAR(0));
regs_buff[26] = IXGBE_READ_REG(hw, IXGBE_MSIXT);
regs_buff[27] = IXGBE_READ_REG(hw, IXGBE_MSIXPBA);
regs_buff[28] = IXGBE_READ_REG(hw, IXGBE_PBACL(0));
regs_buff[29] = IXGBE_READ_REG(hw, IXGBE_GPIE);
regs_buff[30] = IXGBE_READ_REG(hw, IXGBE_PFCTOP);
regs_buff[31] = IXGBE_READ_REG(hw, IXGBE_FCTTV(0));
regs_buff[32] = IXGBE_READ_REG(hw, IXGBE_FCTTV(1));
regs_buff[33] = IXGBE_READ_REG(hw, IXGBE_FCTTV(2));
regs_buff[34] = IXGBE_READ_REG(hw, IXGBE_FCTTV(3));
for (i = 0; i < 8; i++) {
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
regs_buff[35 + i] = IXGBE_READ_REG(hw, IXGBE_FCRTL(i));
regs_buff[43 + i] = IXGBE_READ_REG(hw, IXGBE_FCRTH(i));
break;
case ixgbe_mac_82599EB:
regs_buff[35 + i] = IXGBE_READ_REG(hw, IXGBE_FCRTL_82599(i));
regs_buff[43 + i] = IXGBE_READ_REG(hw, IXGBE_FCRTH_82599(i));
break;
default:
break;
}
}
regs_buff[51] = IXGBE_READ_REG(hw, IXGBE_FCRTV);
regs_buff[52] = IXGBE_READ_REG(hw, IXGBE_TFCS);
for (i = 0; i < 64; i++)
regs_buff[53 + i] = IXGBE_READ_REG(hw, IXGBE_RDBAL(i));
for (i = 0; i < 64; i++)
regs_buff[117 + i] = IXGBE_READ_REG(hw, IXGBE_RDBAH(i));
for (i = 0; i < 64; i++)
regs_buff[181 + i] = IXGBE_READ_REG(hw, IXGBE_RDLEN(i));
for (i = 0; i < 64; i++)
regs_buff[245 + i] = IXGBE_READ_REG(hw, IXGBE_RDH(i));
for (i = 0; i < 64; i++)
regs_buff[309 + i] = IXGBE_READ_REG(hw, IXGBE_RDT(i));
for (i = 0; i < 64; i++)
regs_buff[373 + i] = IXGBE_READ_REG(hw, IXGBE_RXDCTL(i));
for (i = 0; i < 16; i++)
regs_buff[437 + i] = IXGBE_READ_REG(hw, IXGBE_SRRCTL(i));
for (i = 0; i < 16; i++)
regs_buff[453 + i] = IXGBE_READ_REG(hw, IXGBE_DCA_RXCTRL(i));
regs_buff[469] = IXGBE_READ_REG(hw, IXGBE_RDRXCTL);
for (i = 0; i < 8; i++)
regs_buff[470 + i] = IXGBE_READ_REG(hw, IXGBE_RXPBSIZE(i));
regs_buff[478] = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
regs_buff[479] = IXGBE_READ_REG(hw, IXGBE_DROPEN);
regs_buff[480] = IXGBE_READ_REG(hw, IXGBE_RXCSUM);
regs_buff[481] = IXGBE_READ_REG(hw, IXGBE_RFCTL);
for (i = 0; i < 16; i++)
regs_buff[482 + i] = IXGBE_READ_REG(hw, IXGBE_RAL(i));
for (i = 0; i < 16; i++)
regs_buff[498 + i] = IXGBE_READ_REG(hw, IXGBE_RAH(i));
regs_buff[514] = IXGBE_READ_REG(hw, IXGBE_PSRTYPE(0));
regs_buff[515] = IXGBE_READ_REG(hw, IXGBE_FCTRL);
regs_buff[516] = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
regs_buff[517] = IXGBE_READ_REG(hw, IXGBE_MCSTCTRL);
regs_buff[518] = IXGBE_READ_REG(hw, IXGBE_MRQC);
regs_buff[519] = IXGBE_READ_REG(hw, IXGBE_VMD_CTL);
for (i = 0; i < 8; i++)
regs_buff[520 + i] = IXGBE_READ_REG(hw, IXGBE_IMIR(i));
for (i = 0; i < 8; i++)
regs_buff[528 + i] = IXGBE_READ_REG(hw, IXGBE_IMIREXT(i));
regs_buff[536] = IXGBE_READ_REG(hw, IXGBE_IMIRVP);
for (i = 0; i < 32; i++)
regs_buff[537 + i] = IXGBE_READ_REG(hw, IXGBE_TDBAL(i));
for (i = 0; i < 32; i++)
regs_buff[569 + i] = IXGBE_READ_REG(hw, IXGBE_TDBAH(i));
for (i = 0; i < 32; i++)
regs_buff[601 + i] = IXGBE_READ_REG(hw, IXGBE_TDLEN(i));
for (i = 0; i < 32; i++)
regs_buff[633 + i] = IXGBE_READ_REG(hw, IXGBE_TDH(i));
for (i = 0; i < 32; i++)
regs_buff[665 + i] = IXGBE_READ_REG(hw, IXGBE_TDT(i));
for (i = 0; i < 32; i++)
regs_buff[697 + i] = IXGBE_READ_REG(hw, IXGBE_TXDCTL(i));
for (i = 0; i < 32; i++)
regs_buff[729 + i] = IXGBE_READ_REG(hw, IXGBE_TDWBAL(i));
for (i = 0; i < 32; i++)
regs_buff[761 + i] = IXGBE_READ_REG(hw, IXGBE_TDWBAH(i));
regs_buff[793] = IXGBE_READ_REG(hw, IXGBE_DTXCTL);
for (i = 0; i < 16; i++)
regs_buff[794 + i] = IXGBE_READ_REG(hw, IXGBE_DCA_TXCTRL(i));
regs_buff[810] = IXGBE_READ_REG(hw, IXGBE_TIPG);
for (i = 0; i < 8; i++)
regs_buff[811 + i] = IXGBE_READ_REG(hw, IXGBE_TXPBSIZE(i));
regs_buff[819] = IXGBE_READ_REG(hw, IXGBE_MNGTXMAP);
regs_buff[820] = IXGBE_READ_REG(hw, IXGBE_WUC);
regs_buff[821] = IXGBE_READ_REG(hw, IXGBE_WUFC);
regs_buff[822] = IXGBE_READ_REG(hw, IXGBE_WUS);
regs_buff[823] = IXGBE_READ_REG(hw, IXGBE_IPAV);
regs_buff[824] = IXGBE_READ_REG(hw, IXGBE_IP4AT);
regs_buff[825] = IXGBE_READ_REG(hw, IXGBE_IP6AT);
regs_buff[826] = IXGBE_READ_REG(hw, IXGBE_WUPL);
regs_buff[827] = IXGBE_READ_REG(hw, IXGBE_WUPM);
regs_buff[828] = IXGBE_READ_REG(hw, IXGBE_FHFT(0));
regs_buff[829] = IXGBE_READ_REG(hw, IXGBE_RMCS);
regs_buff[830] = IXGBE_READ_REG(hw, IXGBE_DPMCS);
regs_buff[831] = IXGBE_READ_REG(hw, IXGBE_PDPMCS);
regs_buff[832] = IXGBE_READ_REG(hw, IXGBE_RUPPBMR);
for (i = 0; i < 8; i++)
regs_buff[833 + i] = IXGBE_READ_REG(hw, IXGBE_RT2CR(i));
for (i = 0; i < 8; i++)
regs_buff[841 + i] = IXGBE_READ_REG(hw, IXGBE_RT2SR(i));
for (i = 0; i < 8; i++)
regs_buff[849 + i] = IXGBE_READ_REG(hw, IXGBE_TDTQ2TCCR(i));
for (i = 0; i < 8; i++)
regs_buff[857 + i] = IXGBE_READ_REG(hw, IXGBE_TDTQ2TCSR(i));
for (i = 0; i < 8; i++)
regs_buff[865 + i] = IXGBE_READ_REG(hw, IXGBE_TDPT2TCCR(i));
for (i = 0; i < 8; i++)
regs_buff[873 + i] = IXGBE_READ_REG(hw, IXGBE_TDPT2TCSR(i));
regs_buff[881] = IXGBE_GET_STAT(adapter, crcerrs);
regs_buff[882] = IXGBE_GET_STAT(adapter, illerrc);
regs_buff[883] = IXGBE_GET_STAT(adapter, errbc);
regs_buff[884] = IXGBE_GET_STAT(adapter, mspdc);
for (i = 0; i < 8; i++)
regs_buff[885 + i] = IXGBE_GET_STAT(adapter, mpc[i]);
regs_buff[893] = IXGBE_GET_STAT(adapter, mlfc);
regs_buff[894] = IXGBE_GET_STAT(adapter, mrfc);
regs_buff[895] = IXGBE_GET_STAT(adapter, rlec);
regs_buff[896] = IXGBE_GET_STAT(adapter, lxontxc);
regs_buff[897] = IXGBE_GET_STAT(adapter, lxonrxc);
regs_buff[898] = IXGBE_GET_STAT(adapter, lxofftxc);
regs_buff[899] = IXGBE_GET_STAT(adapter, lxoffrxc);
for (i = 0; i < 8; i++)
regs_buff[900 + i] = IXGBE_GET_STAT(adapter, pxontxc[i]);
for (i = 0; i < 8; i++)
regs_buff[908 + i] = IXGBE_GET_STAT(adapter, pxonrxc[i]);
for (i = 0; i < 8; i++)
regs_buff[916 + i] = IXGBE_GET_STAT(adapter, pxofftxc[i]);
for (i = 0; i < 8; i++)
regs_buff[924 + i] = IXGBE_GET_STAT(adapter, pxoffrxc[i]);
regs_buff[932] = IXGBE_GET_STAT(adapter, prc64);
regs_buff[933] = IXGBE_GET_STAT(adapter, prc127);
regs_buff[934] = IXGBE_GET_STAT(adapter, prc255);
regs_buff[935] = IXGBE_GET_STAT(adapter, prc511);
regs_buff[936] = IXGBE_GET_STAT(adapter, prc1023);
regs_buff[937] = IXGBE_GET_STAT(adapter, prc1522);
regs_buff[938] = IXGBE_GET_STAT(adapter, gprc);
regs_buff[939] = IXGBE_GET_STAT(adapter, bprc);
regs_buff[940] = IXGBE_GET_STAT(adapter, mprc);
regs_buff[941] = IXGBE_GET_STAT(adapter, gptc);
regs_buff[942] = IXGBE_GET_STAT(adapter, gorc);
regs_buff[944] = IXGBE_GET_STAT(adapter, gotc);
for (i = 0; i < 8; i++)
regs_buff[946 + i] = IXGBE_GET_STAT(adapter, rnbc[i]);
regs_buff[954] = IXGBE_GET_STAT(adapter, ruc);
regs_buff[955] = IXGBE_GET_STAT(adapter, rfc);
regs_buff[956] = IXGBE_GET_STAT(adapter, roc);
regs_buff[957] = IXGBE_GET_STAT(adapter, rjc);
regs_buff[958] = IXGBE_GET_STAT(adapter, mngprc);
regs_buff[959] = IXGBE_GET_STAT(adapter, mngpdc);
regs_buff[960] = IXGBE_GET_STAT(adapter, mngptc);
regs_buff[961] = IXGBE_GET_STAT(adapter, tor);
regs_buff[963] = IXGBE_GET_STAT(adapter, tpr);
regs_buff[964] = IXGBE_GET_STAT(adapter, tpt);
regs_buff[965] = IXGBE_GET_STAT(adapter, ptc64);
regs_buff[966] = IXGBE_GET_STAT(adapter, ptc127);
regs_buff[967] = IXGBE_GET_STAT(adapter, ptc255);
regs_buff[968] = IXGBE_GET_STAT(adapter, ptc511);
regs_buff[969] = IXGBE_GET_STAT(adapter, ptc1023);
regs_buff[970] = IXGBE_GET_STAT(adapter, ptc1522);
regs_buff[971] = IXGBE_GET_STAT(adapter, mptc);
regs_buff[972] = IXGBE_GET_STAT(adapter, bptc);
regs_buff[973] = IXGBE_GET_STAT(adapter, xec);
for (i = 0; i < 16; i++)
regs_buff[974 + i] = IXGBE_GET_STAT(adapter, qprc[i]);
for (i = 0; i < 16; i++)
regs_buff[990 + i] = IXGBE_GET_STAT(adapter, qptc[i]);
for (i = 0; i < 16; i++)
regs_buff[1006 + i] = IXGBE_GET_STAT(adapter, qbrc[i]);
for (i = 0; i < 16; i++)
regs_buff[1022 + i] = IXGBE_GET_STAT(adapter, qbtc[i]);
regs_buff[1038] = IXGBE_READ_REG(hw, IXGBE_PCS1GCFIG);
regs_buff[1039] = IXGBE_READ_REG(hw, IXGBE_PCS1GLCTL);
regs_buff[1040] = IXGBE_READ_REG(hw, IXGBE_PCS1GLSTA);
regs_buff[1041] = IXGBE_READ_REG(hw, IXGBE_PCS1GDBG0);
regs_buff[1042] = IXGBE_READ_REG(hw, IXGBE_PCS1GDBG1);
regs_buff[1043] = IXGBE_READ_REG(hw, IXGBE_PCS1GANA);
regs_buff[1044] = IXGBE_READ_REG(hw, IXGBE_PCS1GANLP);
regs_buff[1045] = IXGBE_READ_REG(hw, IXGBE_PCS1GANNP);
regs_buff[1046] = IXGBE_READ_REG(hw, IXGBE_PCS1GANLPNP);
regs_buff[1047] = IXGBE_READ_REG(hw, IXGBE_HLREG0);
regs_buff[1048] = IXGBE_READ_REG(hw, IXGBE_HLREG1);
regs_buff[1049] = IXGBE_READ_REG(hw, IXGBE_PAP);
regs_buff[1050] = IXGBE_READ_REG(hw, IXGBE_MACA);
regs_buff[1051] = IXGBE_READ_REG(hw, IXGBE_APAE);
regs_buff[1052] = IXGBE_READ_REG(hw, IXGBE_ARD);
regs_buff[1053] = IXGBE_READ_REG(hw, IXGBE_AIS);
regs_buff[1054] = IXGBE_READ_REG(hw, IXGBE_MSCA);
regs_buff[1055] = IXGBE_READ_REG(hw, IXGBE_MSRWD);
regs_buff[1056] = IXGBE_READ_REG(hw, IXGBE_MLADD);
regs_buff[1057] = IXGBE_READ_REG(hw, IXGBE_MHADD);
regs_buff[1058] = IXGBE_READ_REG(hw, IXGBE_TREG);
regs_buff[1059] = IXGBE_READ_REG(hw, IXGBE_PCSS1);
regs_buff[1060] = IXGBE_READ_REG(hw, IXGBE_PCSS2);
regs_buff[1061] = IXGBE_READ_REG(hw, IXGBE_XPCSS);
regs_buff[1062] = IXGBE_READ_REG(hw, IXGBE_SERDESC);
regs_buff[1063] = IXGBE_READ_REG(hw, IXGBE_MACS);
regs_buff[1064] = IXGBE_READ_REG(hw, IXGBE_AUTOC);
regs_buff[1065] = IXGBE_READ_REG(hw, IXGBE_LINKS);
regs_buff[1066] = IXGBE_READ_REG(hw, IXGBE_AUTOC2);
regs_buff[1067] = IXGBE_READ_REG(hw, IXGBE_AUTOC3);
regs_buff[1068] = IXGBE_READ_REG(hw, IXGBE_ANLP1);
regs_buff[1069] = IXGBE_READ_REG(hw, IXGBE_ANLP2);
regs_buff[1070] = IXGBE_READ_REG(hw, IXGBE_ATLASCTL);
regs_buff[1071] = IXGBE_READ_REG(hw, IXGBE_RDSTATCTL);
for (i = 0; i < 8; i++)
regs_buff[1072 + i] = IXGBE_READ_REG(hw, IXGBE_RDSTAT(i));
regs_buff[1080] = IXGBE_READ_REG(hw, IXGBE_RDHMPN);
for (i = 0; i < 4; i++)
regs_buff[1081 + i] = IXGBE_READ_REG(hw, IXGBE_RIC_DW(i));
regs_buff[1085] = IXGBE_READ_REG(hw, IXGBE_RDPROBE);
regs_buff[1086] = IXGBE_READ_REG(hw, IXGBE_TDSTATCTL);
for (i = 0; i < 8; i++)
regs_buff[1087 + i] = IXGBE_READ_REG(hw, IXGBE_TDSTAT(i));
regs_buff[1095] = IXGBE_READ_REG(hw, IXGBE_TDHMPN);
for (i = 0; i < 4; i++)
regs_buff[1096 + i] = IXGBE_READ_REG(hw, IXGBE_TIC_DW(i));
regs_buff[1100] = IXGBE_READ_REG(hw, IXGBE_TDPROBE);
regs_buff[1101] = IXGBE_READ_REG(hw, IXGBE_TXBUFCTRL);
regs_buff[1102] = IXGBE_READ_REG(hw, IXGBE_TXBUFDATA0);
regs_buff[1103] = IXGBE_READ_REG(hw, IXGBE_TXBUFDATA1);
regs_buff[1104] = IXGBE_READ_REG(hw, IXGBE_TXBUFDATA2);
regs_buff[1105] = IXGBE_READ_REG(hw, IXGBE_TXBUFDATA3);
regs_buff[1106] = IXGBE_READ_REG(hw, IXGBE_RXBUFCTRL);
regs_buff[1107] = IXGBE_READ_REG(hw, IXGBE_RXBUFDATA0);
regs_buff[1108] = IXGBE_READ_REG(hw, IXGBE_RXBUFDATA1);
regs_buff[1109] = IXGBE_READ_REG(hw, IXGBE_RXBUFDATA2);
regs_buff[1110] = IXGBE_READ_REG(hw, IXGBE_RXBUFDATA3);
for (i = 0; i < 8; i++)
regs_buff[1111 + i] = IXGBE_READ_REG(hw, IXGBE_PCIE_DIAG(i));
regs_buff[1119] = IXGBE_READ_REG(hw, IXGBE_RFVAL);
regs_buff[1120] = IXGBE_READ_REG(hw, IXGBE_MDFTC1);
regs_buff[1121] = IXGBE_READ_REG(hw, IXGBE_MDFTC2);
regs_buff[1122] = IXGBE_READ_REG(hw, IXGBE_MDFTFIFO1);
regs_buff[1123] = IXGBE_READ_REG(hw, IXGBE_MDFTFIFO2);
regs_buff[1124] = IXGBE_READ_REG(hw, IXGBE_MDFTS);
regs_buff[1125] = IXGBE_READ_REG(hw, IXGBE_PCIEECCCTL);
regs_buff[1126] = IXGBE_READ_REG(hw, IXGBE_PBTXECC);
regs_buff[1127] = IXGBE_READ_REG(hw, IXGBE_PBRXECC);
}
static int ixgbe_get_eeprom_len(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
return adapter->hw.eeprom.word_size * 2;
}
static int ixgbe_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u16 *eeprom_buff;
int first_word, last_word, eeprom_len;
int ret_val = 0;
u16 i;
if (eeprom->len == 0)
return -EINVAL;
eeprom->magic = hw->vendor_id | (hw->device_id << 16);
first_word = eeprom->offset >> 1;
last_word = (eeprom->offset + eeprom->len - 1) >> 1;
eeprom_len = last_word - first_word + 1;
eeprom_buff = kmalloc(sizeof(u16) * eeprom_len, GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
ret_val = hw->eeprom.ops.read_buffer(hw, first_word, eeprom_len,
eeprom_buff);
for (i = 0; i < eeprom_len; i++)
le16_to_cpus(&eeprom_buff[i]);
memcpy(bytes, (u8 *)eeprom_buff + (eeprom->offset & 1), eeprom->len);
kfree(eeprom_buff);
return ret_val;
}
static void ixgbe_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
char firmware_version[32];
strncpy(drvinfo->driver, ixgbe_driver_name,
sizeof(drvinfo->driver) - 1);
strncpy(drvinfo->version, ixgbe_driver_version,
sizeof(drvinfo->version) - 1);
snprintf(firmware_version, sizeof(firmware_version), "%d.%d-%d",
(adapter->eeprom_version & 0xF000) >> 12,
(adapter->eeprom_version & 0x0FF0) >> 4,
adapter->eeprom_version & 0x000F);
strncpy(drvinfo->fw_version, firmware_version,
sizeof(drvinfo->fw_version));
strncpy(drvinfo->bus_info, pci_name(adapter->pdev),
sizeof(drvinfo->bus_info));
drvinfo->n_stats = IXGBE_STATS_LEN;
drvinfo->testinfo_len = IXGBE_TEST_LEN;
drvinfo->regdump_len = ixgbe_get_regs_len(netdev);
}
static void ixgbe_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_ring *tx_ring = adapter->tx_ring[0];
struct ixgbe_ring *rx_ring = adapter->rx_ring[0];
ring->rx_max_pending = IXGBE_MAX_RXD;
ring->tx_max_pending = IXGBE_MAX_TXD;
ring->rx_mini_max_pending = 0;
ring->rx_jumbo_max_pending = 0;
ring->rx_pending = rx_ring->count;
ring->tx_pending = tx_ring->count;
ring->rx_mini_pending = 0;
ring->rx_jumbo_pending = 0;
}
static int ixgbe_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_ring *temp_tx_ring, *temp_rx_ring;
int i, err = 0;
u32 new_rx_count, new_tx_count;
bool need_update = false;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
new_rx_count = max(ring->rx_pending, (u32)IXGBE_MIN_RXD);
new_rx_count = min(new_rx_count, (u32)IXGBE_MAX_RXD);
new_rx_count = ALIGN(new_rx_count, IXGBE_REQ_RX_DESCRIPTOR_MULTIPLE);
new_tx_count = max(ring->tx_pending, (u32)IXGBE_MIN_TXD);
new_tx_count = min(new_tx_count, (u32)IXGBE_MAX_TXD);
new_tx_count = ALIGN(new_tx_count, IXGBE_REQ_TX_DESCRIPTOR_MULTIPLE);
if ((new_tx_count == adapter->tx_ring[0]->count) &&
(new_rx_count == adapter->rx_ring[0]->count)) {
return 0;
}
while (test_and_set_bit(__IXGBE_RESETTING, &adapter->state))
usleep_range(1000, 2000);
if (!netif_running(adapter->netdev)) {
for (i = 0; i < adapter->num_tx_queues; i++)
adapter->tx_ring[i]->count = new_tx_count;
for (i = 0; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->count = new_rx_count;
adapter->tx_ring_count = new_tx_count;
adapter->rx_ring_count = new_rx_count;
goto clear_reset;
}
temp_tx_ring = vmalloc(adapter->num_tx_queues * sizeof(struct ixgbe_ring));
if (!temp_tx_ring) {
err = -ENOMEM;
goto clear_reset;
}
if (new_tx_count != adapter->tx_ring_count) {
for (i = 0; i < adapter->num_tx_queues; i++) {
memcpy(&temp_tx_ring[i], adapter->tx_ring[i],
sizeof(struct ixgbe_ring));
temp_tx_ring[i].count = new_tx_count;
err = ixgbe_setup_tx_resources(&temp_tx_ring[i]);
if (err) {
while (i) {
i--;
ixgbe_free_tx_resources(&temp_tx_ring[i]);
}
goto clear_reset;
}
}
need_update = true;
}
temp_rx_ring = vmalloc(adapter->num_rx_queues * sizeof(struct ixgbe_ring));
if (!temp_rx_ring) {
err = -ENOMEM;
goto err_setup;
}
if (new_rx_count != adapter->rx_ring_count) {
for (i = 0; i < adapter->num_rx_queues; i++) {
memcpy(&temp_rx_ring[i], adapter->rx_ring[i],
sizeof(struct ixgbe_ring));
temp_rx_ring[i].count = new_rx_count;
err = ixgbe_setup_rx_resources(&temp_rx_ring[i]);
if (err) {
while (i) {
i--;
ixgbe_free_rx_resources(&temp_rx_ring[i]);
}
goto err_setup;
}
}
need_update = true;
}
if (need_update) {
ixgbe_down(adapter);
if (new_tx_count != adapter->tx_ring_count) {
for (i = 0; i < adapter->num_tx_queues; i++) {
ixgbe_free_tx_resources(adapter->tx_ring[i]);
memcpy(adapter->tx_ring[i], &temp_tx_ring[i],
sizeof(struct ixgbe_ring));
}
adapter->tx_ring_count = new_tx_count;
}
if (new_rx_count != adapter->rx_ring_count) {
for (i = 0; i < adapter->num_rx_queues; i++) {
ixgbe_free_rx_resources(adapter->rx_ring[i]);
memcpy(adapter->rx_ring[i], &temp_rx_ring[i],
sizeof(struct ixgbe_ring));
}
adapter->rx_ring_count = new_rx_count;
}
ixgbe_up(adapter);
}
vfree(temp_rx_ring);
err_setup:
vfree(temp_tx_ring);
clear_reset:
clear_bit(__IXGBE_RESETTING, &adapter->state);
return err;
}
static int ixgbe_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_TEST:
return IXGBE_TEST_LEN;
case ETH_SS_STATS:
return IXGBE_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void ixgbe_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct rtnl_link_stats64 temp;
const struct rtnl_link_stats64 *net_stats;
unsigned int start;
struct ixgbe_ring *ring;
int i, j;
char *p = NULL;
ixgbe_update_stats(adapter);
net_stats = dev_get_stats(netdev, &temp);
for (i = 0; i < IXGBE_GLOBAL_STATS_LEN; i++) {
switch (ixgbe_gstrings_stats[i].type) {
case NETDEV_STATS:
p = (char *) net_stats +
ixgbe_gstrings_stats[i].stat_offset;
break;
case IXGBE_STATS:
p = (char *) adapter +
ixgbe_gstrings_stats[i].stat_offset;
break;
}
data[i] = (ixgbe_gstrings_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
for (j = 0; j < adapter->num_tx_queues; j++) {
ring = adapter->tx_ring[j];
do {
start = u64_stats_fetch_begin_bh(&ring->syncp);
data[i] = ring->stats.packets;
data[i+1] = ring->stats.bytes;
} while (u64_stats_fetch_retry_bh(&ring->syncp, start));
i += 2;
}
for (j = 0; j < adapter->num_rx_queues; j++) {
ring = adapter->rx_ring[j];
do {
start = u64_stats_fetch_begin_bh(&ring->syncp);
data[i] = ring->stats.packets;
data[i+1] = ring->stats.bytes;
} while (u64_stats_fetch_retry_bh(&ring->syncp, start));
i += 2;
}
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
for (j = 0; j < MAX_TX_PACKET_BUFFERS; j++) {
data[i++] = adapter->stats.pxontxc[j];
data[i++] = adapter->stats.pxofftxc[j];
}
for (j = 0; j < MAX_RX_PACKET_BUFFERS; j++) {
data[i++] = adapter->stats.pxonrxc[j];
data[i++] = adapter->stats.pxoffrxc[j];
}
}
}
static void ixgbe_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
char *p = (char *)data;
int i;
switch (stringset) {
case ETH_SS_TEST:
memcpy(data, *ixgbe_gstrings_test,
IXGBE_TEST_LEN * ETH_GSTRING_LEN);
break;
case ETH_SS_STATS:
for (i = 0; i < IXGBE_GLOBAL_STATS_LEN; i++) {
memcpy(p, ixgbe_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < adapter->num_tx_queues; i++) {
sprintf(p, "tx_queue_%u_packets", i);
p += ETH_GSTRING_LEN;
sprintf(p, "tx_queue_%u_bytes", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
sprintf(p, "rx_queue_%u_packets", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rx_queue_%u_bytes", i);
p += ETH_GSTRING_LEN;
}
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
for (i = 0; i < MAX_TX_PACKET_BUFFERS; i++) {
sprintf(p, "tx_pb_%u_pxon", i);
p += ETH_GSTRING_LEN;
sprintf(p, "tx_pb_%u_pxoff", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < MAX_RX_PACKET_BUFFERS; i++) {
sprintf(p, "rx_pb_%u_pxon", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rx_pb_%u_pxoff", i);
p += ETH_GSTRING_LEN;
}
}
break;
}
}
static int ixgbe_link_test(struct ixgbe_adapter *adapter, u64 *data)
{
struct ixgbe_hw *hw = &adapter->hw;
bool link_up;
u32 link_speed = 0;
*data = 0;
hw->mac.ops.check_link(hw, &link_speed, &link_up, true);
if (link_up)
return *data;
else
*data = 1;
return *data;
}
static bool reg_pattern_test(struct ixgbe_adapter *adapter, u64 *data, int reg,
u32 mask, u32 write)
{
u32 pat, val, before;
static const u32 test_pattern[] = {
0x5A5A5A5A, 0xA5A5A5A5, 0x00000000, 0xFFFFFFFF};
for (pat = 0; pat < ARRAY_SIZE(test_pattern); pat++) {
before = readl(adapter->hw.hw_addr + reg);
writel((test_pattern[pat] & write),
(adapter->hw.hw_addr + reg));
val = readl(adapter->hw.hw_addr + reg);
if (val != (test_pattern[pat] & write & mask)) {
e_err(drv, "pattern test reg %04X failed: got "
"0x%08X expected 0x%08X\n",
reg, val, (test_pattern[pat] & write & mask));
*data = reg;
writel(before, adapter->hw.hw_addr + reg);
return 1;
}
writel(before, adapter->hw.hw_addr + reg);
}
return 0;
}
static bool reg_set_and_check(struct ixgbe_adapter *adapter, u64 *data, int reg,
u32 mask, u32 write)
{
u32 val, before;
before = readl(adapter->hw.hw_addr + reg);
writel((write & mask), (adapter->hw.hw_addr + reg));
val = readl(adapter->hw.hw_addr + reg);
if ((write & mask) != (val & mask)) {
e_err(drv, "set/check reg %04X test failed: got 0x%08X "
"expected 0x%08X\n", reg, (val & mask), (write & mask));
*data = reg;
writel(before, (adapter->hw.hw_addr + reg));
return 1;
}
writel(before, (adapter->hw.hw_addr + reg));
return 0;
}
static int ixgbe_eeprom_test(struct ixgbe_adapter *adapter, u64 *data)
{
struct ixgbe_hw *hw = &adapter->hw;
if (hw->eeprom.ops.validate_checksum(hw, NULL))
*data = 1;
else
*data = 0;
return *data;
}
static irqreturn_t ixgbe_test_intr(int irq, void *data)
{
struct net_device *netdev = (struct net_device *) data;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
adapter->test_icr |= IXGBE_READ_REG(&adapter->hw, IXGBE_EICR);
return IRQ_HANDLED;
}
static int ixgbe_intr_test(struct ixgbe_adapter *adapter, u64 *data)
{
struct net_device *netdev = adapter->netdev;
u32 mask, i = 0, shared_int = true;
u32 irq = adapter->pdev->irq;
*data = 0;
if (adapter->msix_entries) {
return 0;
} else if (adapter->flags & IXGBE_FLAG_MSI_ENABLED) {
shared_int = false;
if (request_irq(irq, ixgbe_test_intr, 0, netdev->name,
netdev)) {
*data = 1;
return -1;
}
} else if (!request_irq(irq, ixgbe_test_intr, IRQF_PROBE_SHARED,
netdev->name, netdev)) {
shared_int = false;
} else if (request_irq(irq, ixgbe_test_intr, IRQF_SHARED,
netdev->name, netdev)) {
*data = 1;
return -1;
}
e_info(hw, "testing %s interrupt\n", shared_int ?
"shared" : "unshared");
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC, 0xFFFFFFFF);
usleep_range(10000, 20000);
for (; i < 10; i++) {
mask = 1 << i;
if (!shared_int) {
adapter->test_icr = 0;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC,
~mask & 0x00007FFF);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS,
~mask & 0x00007FFF);
usleep_range(10000, 20000);
if (adapter->test_icr & mask) {
*data = 3;
break;
}
}
adapter->test_icr = 0;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMS, mask);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS, mask);
usleep_range(10000, 20000);
if (!(adapter->test_icr &mask)) {
*data = 4;
break;
}
if (!shared_int) {
adapter->test_icr = 0;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC,
~mask & 0x00007FFF);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS,
~mask & 0x00007FFF);
usleep_range(10000, 20000);
if (adapter->test_icr) {
*data = 5;
break;
}
}
}
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC, 0xFFFFFFFF);
usleep_range(10000, 20000);
free_irq(irq, netdev);
return *data;
}
static void ixgbe_free_desc_rings(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring *tx_ring = &adapter->test_tx_ring;
struct ixgbe_ring *rx_ring = &adapter->test_rx_ring;
struct ixgbe_hw *hw = &adapter->hw;
u32 reg_ctl;
reg_ctl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
reg_ctl &= ~IXGBE_RXCTRL_RXEN;
IXGBE_WRITE_REG(hw, IXGBE_RXCTRL, reg_ctl);
ixgbe_disable_rx_queue(adapter, rx_ring);
reg_ctl = IXGBE_READ_REG(hw, IXGBE_TXDCTL(tx_ring->reg_idx));
reg_ctl &= ~IXGBE_TXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(tx_ring->reg_idx), reg_ctl);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
reg_ctl = IXGBE_READ_REG(hw, IXGBE_DMATXCTL);
reg_ctl &= ~IXGBE_DMATXCTL_TE;
IXGBE_WRITE_REG(hw, IXGBE_DMATXCTL, reg_ctl);
break;
default:
break;
}
ixgbe_reset(adapter);
ixgbe_free_tx_resources(&adapter->test_tx_ring);
ixgbe_free_rx_resources(&adapter->test_rx_ring);
}
static int ixgbe_setup_desc_rings(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring *tx_ring = &adapter->test_tx_ring;
struct ixgbe_ring *rx_ring = &adapter->test_rx_ring;
u32 rctl, reg_data;
int ret_val;
int err;
tx_ring->count = IXGBE_DEFAULT_TXD;
tx_ring->queue_index = 0;
tx_ring->dev = &adapter->pdev->dev;
tx_ring->netdev = adapter->netdev;
tx_ring->reg_idx = adapter->tx_ring[0]->reg_idx;
tx_ring->numa_node = adapter->node;
err = ixgbe_setup_tx_resources(tx_ring);
if (err)
return 1;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_DMATXCTL);
reg_data |= IXGBE_DMATXCTL_TE;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DMATXCTL, reg_data);
break;
default:
break;
}
ixgbe_configure_tx_ring(adapter, tx_ring);
rx_ring->count = IXGBE_DEFAULT_RXD;
rx_ring->queue_index = 0;
rx_ring->dev = &adapter->pdev->dev;
rx_ring->netdev = adapter->netdev;
rx_ring->reg_idx = adapter->rx_ring[0]->reg_idx;
rx_ring->rx_buf_len = IXGBE_RXBUFFER_2048;
rx_ring->numa_node = adapter->node;
err = ixgbe_setup_rx_resources(rx_ring);
if (err) {
ret_val = 4;
goto err_nomem;
}
rctl = IXGBE_READ_REG(&adapter->hw, IXGBE_RXCTRL);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCTRL, rctl & ~IXGBE_RXCTRL_RXEN);
ixgbe_configure_rx_ring(adapter, rx_ring);
rctl |= IXGBE_RXCTRL_RXEN | IXGBE_RXCTRL_DMBYPS;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_RXCTRL, rctl);
return 0;
err_nomem:
ixgbe_free_desc_rings(adapter);
return ret_val;
}
static int ixgbe_setup_loopback_test(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 reg_data;
if (adapter->hw.mac.type == ixgbe_mac_X540) {
reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_MACC);
reg_data |= IXGBE_MACC_FLU;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_MACC, reg_data);
}
reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_HLREG0);
reg_data |= IXGBE_HLREG0_LPBK;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_HLREG0, reg_data);
reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_FCTRL);
reg_data |= IXGBE_FCTRL_BAM | IXGBE_FCTRL_SBP | IXGBE_FCTRL_MPE;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_FCTRL, reg_data);
reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_AUTOC);
reg_data &= ~IXGBE_AUTOC_LMS_MASK;
reg_data |= IXGBE_AUTOC_LMS_10G_LINK_NO_AN | IXGBE_AUTOC_FLU;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_AUTOC, reg_data);
IXGBE_WRITE_FLUSH(&adapter->hw);
usleep_range(10000, 20000);
if (hw->mac.type == ixgbe_mac_82598EB) {
u8 atlas;
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_LPBK, &atlas);
atlas |= IXGBE_ATLAS_PDN_TX_REG_EN;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_LPBK, atlas);
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_10G, &atlas);
atlas |= IXGBE_ATLAS_PDN_TX_10G_QL_ALL;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_10G, atlas);
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_1G, &atlas);
atlas |= IXGBE_ATLAS_PDN_TX_1G_QL_ALL;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_1G, atlas);
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_AN, &atlas);
atlas |= IXGBE_ATLAS_PDN_TX_AN_QL_ALL;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_AN, atlas);
}
return 0;
}
static void ixgbe_loopback_cleanup(struct ixgbe_adapter *adapter)
{
u32 reg_data;
reg_data = IXGBE_READ_REG(&adapter->hw, IXGBE_HLREG0);
reg_data &= ~IXGBE_HLREG0_LPBK;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_HLREG0, reg_data);
}
static void ixgbe_create_lbtest_frame(struct sk_buff *skb,
unsigned int frame_size)
{
memset(skb->data, 0xFF, frame_size);
frame_size &= ~1;
memset(&skb->data[frame_size / 2], 0xAA, frame_size / 2 - 1);
memset(&skb->data[frame_size / 2 + 10], 0xBE, 1);
memset(&skb->data[frame_size / 2 + 12], 0xAF, 1);
}
static int ixgbe_check_lbtest_frame(struct sk_buff *skb,
unsigned int frame_size)
{
frame_size &= ~1;
if (*(skb->data + 3) == 0xFF) {
if ((*(skb->data + frame_size / 2 + 10) == 0xBE) &&
(*(skb->data + frame_size / 2 + 12) == 0xAF)) {
return 0;
}
}
return 13;
}
static u16 ixgbe_clean_test_rings(struct ixgbe_ring *rx_ring,
struct ixgbe_ring *tx_ring,
unsigned int size)
{
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *rx_buffer_info;
struct ixgbe_tx_buffer *tx_buffer_info;
const int bufsz = rx_ring->rx_buf_len;
u32 staterr;
u16 rx_ntc, tx_ntc, count = 0;
rx_ntc = rx_ring->next_to_clean;
tx_ntc = tx_ring->next_to_clean;
rx_desc = IXGBE_RX_DESC_ADV(rx_ring, rx_ntc);
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
while (staterr & IXGBE_RXD_STAT_DD) {
rx_buffer_info = &rx_ring->rx_buffer_info[rx_ntc];
dma_unmap_single(rx_ring->dev,
rx_buffer_info->dma,
bufsz,
DMA_FROM_DEVICE);
rx_buffer_info->dma = 0;
if (!ixgbe_check_lbtest_frame(rx_buffer_info->skb, size))
count++;
tx_buffer_info = &tx_ring->tx_buffer_info[tx_ntc];
ixgbe_unmap_and_free_tx_resource(tx_ring, tx_buffer_info);
rx_ntc++;
if (rx_ntc == rx_ring->count)
rx_ntc = 0;
tx_ntc++;
if (tx_ntc == tx_ring->count)
tx_ntc = 0;
rx_desc = IXGBE_RX_DESC_ADV(rx_ring, rx_ntc);
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
}
ixgbe_alloc_rx_buffers(rx_ring, count);
rx_ring->next_to_clean = rx_ntc;
tx_ring->next_to_clean = tx_ntc;
return count;
}
static int ixgbe_run_loopback_test(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring *tx_ring = &adapter->test_tx_ring;
struct ixgbe_ring *rx_ring = &adapter->test_rx_ring;
int i, j, lc, good_cnt, ret_val = 0;
unsigned int size = 1024;
netdev_tx_t tx_ret_val;
struct sk_buff *skb;
skb = alloc_skb(size, GFP_KERNEL);
if (!skb)
return 11;
ixgbe_create_lbtest_frame(skb, size);
skb_put(skb, size);
if (rx_ring->count <= tx_ring->count)
lc = ((tx_ring->count / 64) * 2) + 1;
else
lc = ((rx_ring->count / 64) * 2) + 1;
for (j = 0; j <= lc; j++) {
good_cnt = 0;
for (i = 0; i < 64; i++) {
skb_get(skb);
tx_ret_val = ixgbe_xmit_frame_ring(skb,
adapter,
tx_ring);
if (tx_ret_val == NETDEV_TX_OK)
good_cnt++;
}
if (good_cnt != 64) {
ret_val = 12;
break;
}
msleep(200);
good_cnt = ixgbe_clean_test_rings(rx_ring, tx_ring, size);
if (good_cnt != 64) {
ret_val = 13;
break;
}
}
kfree_skb(skb);
return ret_val;
}
static int ixgbe_loopback_test(struct ixgbe_adapter *adapter, u64 *data)
{
*data = ixgbe_setup_desc_rings(adapter);
if (*data)
goto out;
*data = ixgbe_setup_loopback_test(adapter);
if (*data)
goto err_loopback;
*data = ixgbe_run_loopback_test(adapter);
ixgbe_loopback_cleanup(adapter);
err_loopback:
ixgbe_free_desc_rings(adapter);
out:
return *data;
}
static void ixgbe_diag_test(struct net_device *netdev,
struct ethtool_test *eth_test, u64 *data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
bool if_running = netif_running(netdev);
set_bit(__IXGBE_TESTING, &adapter->state);
if (eth_test->flags == ETH_TEST_FL_OFFLINE) {
e_info(hw, "offline testing starting\n");
if (ixgbe_link_test(adapter, &data[4]))
eth_test->flags |= ETH_TEST_FL_FAILED;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
int i;
for (i = 0; i < adapter->num_vfs; i++) {
if (adapter->vfinfo[i].clear_to_send) {
netdev_warn(netdev, "%s",
"offline diagnostic is not "
"supported when VFs are "
"present\n");
data[0] = 1;
data[1] = 1;
data[2] = 1;
data[3] = 1;
eth_test->flags |= ETH_TEST_FL_FAILED;
clear_bit(__IXGBE_TESTING,
&adapter->state);
goto skip_ol_tests;
}
}
}
if (if_running)
dev_close(netdev);
else
ixgbe_reset(adapter);
e_info(hw, "register testing starting\n");
if (ixgbe_reg_test(adapter, &data[0]))
eth_test->flags |= ETH_TEST_FL_FAILED;
ixgbe_reset(adapter);
e_info(hw, "eeprom testing starting\n");
if (ixgbe_eeprom_test(adapter, &data[1]))
eth_test->flags |= ETH_TEST_FL_FAILED;
ixgbe_reset(adapter);
e_info(hw, "interrupt testing starting\n");
if (ixgbe_intr_test(adapter, &data[2]))
eth_test->flags |= ETH_TEST_FL_FAILED;
if (adapter->flags & (IXGBE_FLAG_SRIOV_ENABLED |
IXGBE_FLAG_VMDQ_ENABLED)) {
e_info(hw, "Skip MAC loopback diagnostic in VT "
"mode\n");
data[3] = 0;
goto skip_loopback;
}
ixgbe_reset(adapter);
e_info(hw, "loopback testing starting\n");
if (ixgbe_loopback_test(adapter, &data[3]))
eth_test->flags |= ETH_TEST_FL_FAILED;
skip_loopback:
ixgbe_reset(adapter);
clear_bit(__IXGBE_TESTING, &adapter->state);
if (if_running)
dev_open(netdev);
} else {
e_info(hw, "online testing starting\n");
if (ixgbe_link_test(adapter, &data[4]))
eth_test->flags |= ETH_TEST_FL_FAILED;
data[0] = 0;
data[1] = 0;
data[2] = 0;
data[3] = 0;
clear_bit(__IXGBE_TESTING, &adapter->state);
}
skip_ol_tests:
msleep_interruptible(4 * 1000);
}
static int ixgbe_wol_exclusion(struct ixgbe_adapter *adapter,
struct ethtool_wolinfo *wol)
{
struct ixgbe_hw *hw = &adapter->hw;
int retval = 1;
switch(hw->device_id) {
case IXGBE_DEV_ID_82599_SFP:
if (hw->subsystem_device_id != IXGBE_SUBDEV_ID_82599_SFP) {
wol->supported = 0;
break;
}
retval = 0;
break;
case IXGBE_DEV_ID_82599_COMBO_BACKPLANE:
if (hw->subsystem_device_id ==
IXGBE_SUBDEV_ID_82599_KX4_KR_MEZZ) {
wol->supported = 0;
break;
}
retval = 0;
break;
case IXGBE_DEV_ID_82599_KX4:
retval = 0;
break;
default:
wol->supported = 0;
}
return retval;
}
static void ixgbe_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
wol->supported = WAKE_UCAST | WAKE_MCAST |
WAKE_BCAST | WAKE_MAGIC;
wol->wolopts = 0;
if (ixgbe_wol_exclusion(adapter, wol) ||
!device_can_wakeup(&adapter->pdev->dev))
return;
if (adapter->wol & IXGBE_WUFC_EX)
wol->wolopts |= WAKE_UCAST;
if (adapter->wol & IXGBE_WUFC_MC)
wol->wolopts |= WAKE_MCAST;
if (adapter->wol & IXGBE_WUFC_BC)
wol->wolopts |= WAKE_BCAST;
if (adapter->wol & IXGBE_WUFC_MAG)
wol->wolopts |= WAKE_MAGIC;
}
static int ixgbe_set_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (wol->wolopts & (WAKE_PHY | WAKE_ARP | WAKE_MAGICSECURE))
return -EOPNOTSUPP;
if (ixgbe_wol_exclusion(adapter, wol))
return wol->wolopts ? -EOPNOTSUPP : 0;
adapter->wol = 0;
if (wol->wolopts & WAKE_UCAST)
adapter->wol |= IXGBE_WUFC_EX;
if (wol->wolopts & WAKE_MCAST)
adapter->wol |= IXGBE_WUFC_MC;
if (wol->wolopts & WAKE_BCAST)
adapter->wol |= IXGBE_WUFC_BC;
if (wol->wolopts & WAKE_MAGIC)
adapter->wol |= IXGBE_WUFC_MAG;
device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);
return 0;
}
static int ixgbe_nway_reset(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
return 0;
}
static int ixgbe_set_phys_id(struct net_device *netdev,
enum ethtool_phys_id_state state)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
switch (state) {
case ETHTOOL_ID_ACTIVE:
adapter->led_reg = IXGBE_READ_REG(hw, IXGBE_LEDCTL);
return 2;
case ETHTOOL_ID_ON:
hw->mac.ops.led_on(hw, IXGBE_LED_ON);
break;
case ETHTOOL_ID_OFF:
hw->mac.ops.led_off(hw, IXGBE_LED_ON);
break;
case ETHTOOL_ID_INACTIVE:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_LEDCTL, adapter->led_reg);
break;
}
return 0;
}
static int ixgbe_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ec->tx_max_coalesced_frames_irq = adapter->tx_ring[0]->work_limit;
switch (adapter->rx_itr_setting) {
case 0:
ec->rx_coalesce_usecs = 0;
break;
case 1:
ec->rx_coalesce_usecs = 1;
break;
default:
ec->rx_coalesce_usecs = 1000000/adapter->rx_eitr_param;
break;
}
if (adapter->q_vector[0]->txr_count && adapter->q_vector[0]->rxr_count)
return 0;
switch (adapter->tx_itr_setting) {
case 0:
ec->tx_coalesce_usecs = 0;
break;
case 1:
ec->tx_coalesce_usecs = 1;
break;
default:
ec->tx_coalesce_usecs = 1000000/adapter->tx_eitr_param;
break;
}
return 0;
}
static bool ixgbe_update_rsc(struct ixgbe_adapter *adapter,
struct ethtool_coalesce *ec)
{
struct net_device *netdev = adapter->netdev;
if (!(adapter->flags2 & IXGBE_FLAG2_RSC_CAPABLE))
return false;
if (ec->rx_coalesce_usecs != 1 &&
ec->rx_coalesce_usecs <= 1000000/IXGBE_MAX_RSC_INT_RATE) {
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED) {
e_info(probe, "rx-usecs set too low, "
"disabling RSC\n");
adapter->flags2 &= ~IXGBE_FLAG2_RSC_ENABLED;
return true;
}
} else {
if ((netdev->features & NETIF_F_LRO) &&
!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)) {
e_info(probe, "rx-usecs set to %d, "
"re-enabling RSC\n",
ec->rx_coalesce_usecs);
adapter->flags2 |= IXGBE_FLAG2_RSC_ENABLED;
return true;
}
}
return false;
}
static int ixgbe_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_q_vector *q_vector;
int i;
bool need_reset = false;
if (adapter->q_vector[0]->txr_count && adapter->q_vector[0]->rxr_count
&& ec->tx_coalesce_usecs)
return -EINVAL;
if (ec->tx_max_coalesced_frames_irq)
adapter->tx_ring[0]->work_limit = ec->tx_max_coalesced_frames_irq;
if (ec->rx_coalesce_usecs > 1) {
if ((1000000/ec->rx_coalesce_usecs > IXGBE_MAX_INT_RATE) ||
(1000000/ec->rx_coalesce_usecs < IXGBE_MIN_INT_RATE))
return -EINVAL;
need_reset = ixgbe_update_rsc(adapter, ec);
adapter->rx_eitr_param = 1000000/ec->rx_coalesce_usecs;
adapter->rx_itr_setting = adapter->rx_eitr_param;
adapter->rx_itr_setting &= ~1;
} else if (ec->rx_coalesce_usecs == 1) {
need_reset = ixgbe_update_rsc(adapter, ec);
adapter->rx_eitr_param = 20000;
adapter->rx_itr_setting = 1;
} else {
need_reset = ixgbe_update_rsc(adapter, ec);
adapter->rx_eitr_param = IXGBE_MAX_INT_RATE;
adapter->rx_itr_setting = 0;
}
if (ec->tx_coalesce_usecs > 1) {
if ((1000000/ec->tx_coalesce_usecs > IXGBE_MAX_INT_RATE) ||
(1000000/ec->tx_coalesce_usecs < IXGBE_MIN_INT_RATE))
return -EINVAL;
adapter->tx_eitr_param = 1000000/ec->tx_coalesce_usecs;
adapter->tx_itr_setting = adapter->tx_eitr_param;
adapter->tx_itr_setting &= ~1;
} else if (ec->tx_coalesce_usecs == 1) {
adapter->tx_eitr_param = 10000;
adapter->tx_itr_setting = 1;
} else {
adapter->tx_eitr_param = IXGBE_MAX_INT_RATE;
adapter->tx_itr_setting = 0;
}
if (adapter->flags &
(IXGBE_FLAG_MSIX_ENABLED | IXGBE_FLAG_MSI_ENABLED)) {
int num_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (i = 0; i < num_vectors; i++) {
q_vector = adapter->q_vector[i];
if (q_vector->txr_count && !q_vector->rxr_count)
q_vector->eitr = adapter->tx_eitr_param;
else
q_vector->eitr = adapter->rx_eitr_param;
ixgbe_write_eitr(q_vector);
}
} else {
q_vector = adapter->q_vector[0];
q_vector->eitr = adapter->rx_eitr_param;
ixgbe_write_eitr(q_vector);
}
if (need_reset) {
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
else
ixgbe_reset(adapter);
}
return 0;
}
static int ixgbe_set_flags(struct net_device *netdev, u32 data)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
bool need_reset = false;
int rc;
#ifdef CONFIG_IXGBE_DCB
if ((adapter->flags & IXGBE_FLAG_DCB_ENABLED) &&
!(data & ETH_FLAG_RXVLAN))
return -EINVAL;
#endif
need_reset = (data & ETH_FLAG_RXVLAN) !=
(netdev->features & NETIF_F_HW_VLAN_RX);
if ((data & ETH_FLAG_RXHASH) &&
!(adapter->flags & IXGBE_FLAG_RSS_ENABLED))
return -EOPNOTSUPP;
rc = ethtool_op_set_flags(netdev, data, ETH_FLAG_LRO | ETH_FLAG_NTUPLE |
ETH_FLAG_RXVLAN | ETH_FLAG_TXVLAN |
ETH_FLAG_RXHASH);
if (rc)
return rc;
if ((adapter->flags2 & IXGBE_FLAG2_RSC_CAPABLE) &&
(!!(data & ETH_FLAG_LRO) !=
!!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED))) {
if ((data & ETH_FLAG_LRO) &&
(!adapter->rx_itr_setting ||
(adapter->rx_itr_setting > IXGBE_MAX_RSC_INT_RATE))) {
e_info(probe, "rx-usecs set too low, "
"not enabling RSC.\n");
} else {
adapter->flags2 ^= IXGBE_FLAG2_RSC_ENABLED;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
need_reset = true;
break;
case ixgbe_mac_X540: {
int i;
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *ring =
adapter->rx_ring[i];
if (adapter->flags2 &
IXGBE_FLAG2_RSC_ENABLED) {
ixgbe_configure_rscctl(adapter,
ring);
} else {
ixgbe_clear_rscctl(adapter,
ring);
}
}
}
break;
default:
break;
}
}
}
if ((adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE) &&
(!(data & ETH_FLAG_NTUPLE))) {
adapter->flags &= ~IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
adapter->flags |= IXGBE_FLAG_FDIR_HASH_CAPABLE;
need_reset = true;
} else if ((!(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)) &&
(data & ETH_FLAG_NTUPLE)) {
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->flags |= IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
need_reset = true;
} else {
}
if (need_reset) {
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
else
ixgbe_reset(adapter);
}
return 0;
}
static int ixgbe_set_rx_ntuple(struct net_device *dev,
struct ethtool_rx_ntuple *cmd)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ethtool_rx_ntuple_flow_spec *fs = &cmd->fs;
union ixgbe_atr_input input_struct;
struct ixgbe_atr_input_masks input_masks;
int target_queue;
int err;
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
return -EOPNOTSUPP;
if ((fs->action >= adapter->num_tx_queues) ||
(fs->action < ETHTOOL_RXNTUPLE_ACTION_DROP))
return -EINVAL;
memset(&input_struct, 0, sizeof(union ixgbe_atr_input));
memset(&input_masks, 0, sizeof(struct ixgbe_atr_input_masks));
switch (fs->flow_type) {
case IPV4_FLOW:
input_struct.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_IPV4;
break;
case TCP_V4_FLOW:
input_struct.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_TCPV4;
break;
case UDP_V4_FLOW:
input_struct.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_UDPV4;
break;
case SCTP_V4_FLOW:
input_struct.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_SCTPV4;
break;
default:
return -1;
}
if ((fs->vlan_tag & 0xEFFF) || (~fs->vlan_tag_mask & 0xEFFF)) {
input_struct.formatted.vlan_id = htons(fs->vlan_tag & 0xEFFF);
if (!fs->vlan_tag_mask) {
input_masks.vlan_id_mask = htons(0xEFFF);
} else {
switch (~fs->vlan_tag_mask & 0xEFFF) {
case 0xEFFF:
case 0xE000:
case 0x0FFF:
case 0x0000:
input_masks.vlan_id_mask =
htons(~fs->vlan_tag_mask);
break;
default:
e_err(drv, "Partial VLAN ID or "
"priority mask in vlan-mask is not "
"supported by hardware\n");
return -1;
}
}
}
if ((fs->data & 0xFFFF) || (~fs->data_mask & 0xFFFF)) {
input_struct.formatted.flex_bytes = htons(fs->data & 0xFFFF);
if (!(fs->data_mask & 0xFFFF)) {
input_masks.flex_mask = 0xFFFF;
} else if (~fs->data_mask & 0xFFFF) {
e_err(drv, "Partial user-def-mask is not "
"supported by hardware\n");
return -1;
}
}
if (fs->h_u.tcp_ip4_spec.ip4src || ~fs->m_u.tcp_ip4_spec.ip4src) {
input_struct.formatted.src_ip[0] = fs->h_u.tcp_ip4_spec.ip4src;
if (!fs->m_u.tcp_ip4_spec.ip4src)
input_masks.src_ip_mask[0] = 0xFFFFFFFF;
else
input_masks.src_ip_mask[0] =
~fs->m_u.tcp_ip4_spec.ip4src;
}
if (fs->h_u.tcp_ip4_spec.ip4dst || ~fs->m_u.tcp_ip4_spec.ip4dst) {
input_struct.formatted.dst_ip[0] = fs->h_u.tcp_ip4_spec.ip4dst;
if (!fs->m_u.tcp_ip4_spec.ip4dst)
input_masks.dst_ip_mask[0] = 0xFFFFFFFF;
else
input_masks.dst_ip_mask[0] =
~fs->m_u.tcp_ip4_spec.ip4dst;
}
if (fs->h_u.tcp_ip4_spec.psrc || ~fs->m_u.tcp_ip4_spec.psrc) {
input_struct.formatted.src_port = fs->h_u.tcp_ip4_spec.psrc;
if (!fs->m_u.tcp_ip4_spec.psrc)
input_masks.src_port_mask = 0xFFFF;
else
input_masks.src_port_mask = ~fs->m_u.tcp_ip4_spec.psrc;
}
if (fs->h_u.tcp_ip4_spec.pdst || ~fs->m_u.tcp_ip4_spec.pdst) {
input_struct.formatted.dst_port = fs->h_u.tcp_ip4_spec.pdst;
if (!fs->m_u.tcp_ip4_spec.pdst)
input_masks.dst_port_mask = 0xFFFF;
else
input_masks.dst_port_mask = ~fs->m_u.tcp_ip4_spec.pdst;
}
if (fs->action == ETHTOOL_RXNTUPLE_ACTION_DROP)
target_queue = MAX_RX_QUEUES - 1;
else
target_queue = fs->action;
spin_lock(&adapter->fdir_perfect_lock);
err = ixgbe_fdir_add_perfect_filter_82599(&adapter->hw,
&input_struct,
&input_masks, 0,
target_queue);
spin_unlock(&adapter->fdir_perfect_lock);
return err ? -1 : 0;
}
void ixgbe_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &ixgbe_ethtool_ops);
}
