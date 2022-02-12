static void ixgbe_set_pcie_completion_timeout(struct ixgbe_hw *hw)
{
u32 gcr = IXGBE_READ_REG(hw, IXGBE_GCR);
u16 pcie_devctl2;
if (ixgbe_removed(hw->hw_addr))
return;
if (gcr & IXGBE_GCR_CMPL_TMOUT_MASK)
goto out;
if (!(gcr & IXGBE_GCR_CAP_VER2)) {
gcr |= IXGBE_GCR_CMPL_TMOUT_10ms;
goto out;
}
pcie_devctl2 = ixgbe_read_pci_cfg_word(hw, IXGBE_PCI_DEVICE_CONTROL2);
pcie_devctl2 |= IXGBE_PCI_DEVICE_CONTROL2_16ms;
ixgbe_write_pci_cfg_word(hw, IXGBE_PCI_DEVICE_CONTROL2, pcie_devctl2);
out:
gcr &= ~IXGBE_GCR_CMPL_TMOUT_RESEND;
IXGBE_WRITE_REG(hw, IXGBE_GCR, gcr);
}
static s32 ixgbe_get_invariants_82598(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
ixgbe_identify_phy_generic(hw);
mac->mcft_size = IXGBE_82598_MC_TBL_SIZE;
mac->vft_size = IXGBE_82598_VFT_TBL_SIZE;
mac->num_rar_entries = IXGBE_82598_RAR_ENTRIES;
mac->rx_pb_size = IXGBE_82598_RX_PB_SIZE;
mac->max_rx_queues = IXGBE_82598_MAX_RX_QUEUES;
mac->max_tx_queues = IXGBE_82598_MAX_TX_QUEUES;
mac->max_msix_vectors = ixgbe_get_pcie_msix_count_generic(hw);
return 0;
}
static s32 ixgbe_init_phy_ops_82598(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
struct ixgbe_phy_info *phy = &hw->phy;
s32 ret_val;
u16 list_offset, data_offset;
phy->ops.identify(hw);
if (mac->ops.get_media_type(hw) == ixgbe_media_type_copper) {
mac->ops.setup_link = &ixgbe_setup_copper_link_82598;
mac->ops.get_link_capabilities =
&ixgbe_get_copper_link_capabilities_generic;
}
switch (hw->phy.type) {
case ixgbe_phy_tn:
phy->ops.setup_link = &ixgbe_setup_phy_link_tnx;
phy->ops.check_link = &ixgbe_check_phy_link_tnx;
phy->ops.get_firmware_version =
&ixgbe_get_phy_firmware_version_tnx;
break;
case ixgbe_phy_nl:
phy->ops.reset = &ixgbe_reset_phy_nl;
ret_val = phy->ops.identify_sfp(hw);
if (ret_val)
return ret_val;
if (hw->phy.sfp_type == ixgbe_sfp_type_unknown)
return IXGBE_ERR_SFP_NOT_SUPPORTED;
ret_val = ixgbe_get_sfp_init_sequence_offsets(hw,
&list_offset,
&data_offset);
if (ret_val)
return IXGBE_ERR_SFP_NOT_SUPPORTED;
break;
default:
break;
}
return 0;
}
static s32 ixgbe_start_hw_82598(struct ixgbe_hw *hw)
{
#ifndef CONFIG_SPARC
u32 regval;
u32 i;
#endif
s32 ret_val;
ret_val = ixgbe_start_hw_generic(hw);
#ifndef CONFIG_SPARC
for (i = 0; ((i < hw->mac.max_tx_queues) &&
(i < IXGBE_DCA_MAX_QUEUES_82598)); i++) {
regval = IXGBE_READ_REG(hw, IXGBE_DCA_TXCTRL(i));
regval &= ~IXGBE_DCA_TXCTRL_DESC_WRO_EN;
IXGBE_WRITE_REG(hw, IXGBE_DCA_TXCTRL(i), regval);
}
for (i = 0; ((i < hw->mac.max_rx_queues) &&
(i < IXGBE_DCA_MAX_QUEUES_82598)); i++) {
regval = IXGBE_READ_REG(hw, IXGBE_DCA_RXCTRL(i));
regval &= ~(IXGBE_DCA_RXCTRL_DATA_WRO_EN |
IXGBE_DCA_RXCTRL_HEAD_WRO_EN);
IXGBE_WRITE_REG(hw, IXGBE_DCA_RXCTRL(i), regval);
}
#endif
if (ret_val)
return ret_val;
ixgbe_set_pcie_completion_timeout(hw);
return 0;
}
static s32 ixgbe_get_link_capabilities_82598(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *autoneg)
{
u32 autoc = 0;
if (hw->mac.orig_link_settings_stored)
autoc = hw->mac.orig_autoc;
else
autoc = IXGBE_READ_REG(hw, IXGBE_AUTOC);
switch (autoc & IXGBE_AUTOC_LMS_MASK) {
case IXGBE_AUTOC_LMS_1G_LINK_NO_AN:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = false;
break;
case IXGBE_AUTOC_LMS_10G_LINK_NO_AN:
*speed = IXGBE_LINK_SPEED_10GB_FULL;
*autoneg = false;
break;
case IXGBE_AUTOC_LMS_1G_AN:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
break;
case IXGBE_AUTOC_LMS_KX4_AN:
case IXGBE_AUTOC_LMS_KX4_AN_1G_AN:
*speed = IXGBE_LINK_SPEED_UNKNOWN;
if (autoc & IXGBE_AUTOC_KX4_SUPP)
*speed |= IXGBE_LINK_SPEED_10GB_FULL;
if (autoc & IXGBE_AUTOC_KX_SUPP)
*speed |= IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
break;
default:
return IXGBE_ERR_LINK_SETUP;
}
return 0;
}
static enum ixgbe_media_type ixgbe_get_media_type_82598(struct ixgbe_hw *hw)
{
switch (hw->phy.type) {
case ixgbe_phy_cu_unknown:
case ixgbe_phy_tn:
return ixgbe_media_type_copper;
default:
break;
}
switch (hw->device_id) {
case IXGBE_DEV_ID_82598:
case IXGBE_DEV_ID_82598_BX:
return ixgbe_media_type_backplane;
case IXGBE_DEV_ID_82598AF_DUAL_PORT:
case IXGBE_DEV_ID_82598AF_SINGLE_PORT:
case IXGBE_DEV_ID_82598_DA_DUAL_PORT:
case IXGBE_DEV_ID_82598_SR_DUAL_PORT_EM:
case IXGBE_DEV_ID_82598EB_XF_LR:
case IXGBE_DEV_ID_82598EB_SFP_LOM:
return ixgbe_media_type_fiber;
case IXGBE_DEV_ID_82598EB_CX4:
case IXGBE_DEV_ID_82598_CX4_DUAL_PORT:
return ixgbe_media_type_cx4;
case IXGBE_DEV_ID_82598AT:
case IXGBE_DEV_ID_82598AT2:
return ixgbe_media_type_copper;
default:
return ixgbe_media_type_unknown;
}
}
static s32 ixgbe_fc_enable_82598(struct ixgbe_hw *hw)
{
u32 fctrl_reg;
u32 rmcs_reg;
u32 reg;
u32 fcrtl, fcrth;
u32 link_speed = 0;
int i;
bool link_up;
if (!hw->fc.pause_time)
return IXGBE_ERR_INVALID_LINK_SETTINGS;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
if ((hw->fc.current_mode & ixgbe_fc_tx_pause) &&
hw->fc.high_water[i]) {
if (!hw->fc.low_water[i] ||
hw->fc.low_water[i] >= hw->fc.high_water[i]) {
hw_dbg(hw, "Invalid water mark configuration\n");
return IXGBE_ERR_INVALID_LINK_SETTINGS;
}
}
}
hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
if (link_up && link_speed == IXGBE_LINK_SPEED_1GB_FULL) {
switch (hw->fc.requested_mode) {
case ixgbe_fc_full:
hw->fc.requested_mode = ixgbe_fc_tx_pause;
break;
case ixgbe_fc_rx_pause:
hw->fc.requested_mode = ixgbe_fc_none;
break;
default:
break;
}
}
ixgbe_fc_autoneg(hw);
fctrl_reg = IXGBE_READ_REG(hw, IXGBE_FCTRL);
fctrl_reg &= ~(IXGBE_FCTRL_RFCE | IXGBE_FCTRL_RPFCE);
rmcs_reg = IXGBE_READ_REG(hw, IXGBE_RMCS);
rmcs_reg &= ~(IXGBE_RMCS_TFCE_PRIORITY | IXGBE_RMCS_TFCE_802_3X);
switch (hw->fc.current_mode) {
case ixgbe_fc_none:
break;
case ixgbe_fc_rx_pause:
fctrl_reg |= IXGBE_FCTRL_RFCE;
break;
case ixgbe_fc_tx_pause:
rmcs_reg |= IXGBE_RMCS_TFCE_802_3X;
break;
case ixgbe_fc_full:
fctrl_reg |= IXGBE_FCTRL_RFCE;
rmcs_reg |= IXGBE_RMCS_TFCE_802_3X;
break;
default:
hw_dbg(hw, "Flow control param set incorrectly\n");
return IXGBE_ERR_CONFIG;
}
fctrl_reg |= IXGBE_FCTRL_DPF;
IXGBE_WRITE_REG(hw, IXGBE_FCTRL, fctrl_reg);
IXGBE_WRITE_REG(hw, IXGBE_RMCS, rmcs_reg);
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
if ((hw->fc.current_mode & ixgbe_fc_tx_pause) &&
hw->fc.high_water[i]) {
fcrtl = (hw->fc.low_water[i] << 10) | IXGBE_FCRTL_XONE;
fcrth = (hw->fc.high_water[i] << 10) | IXGBE_FCRTH_FCEN;
IXGBE_WRITE_REG(hw, IXGBE_FCRTL(i), fcrtl);
IXGBE_WRITE_REG(hw, IXGBE_FCRTH(i), fcrth);
} else {
IXGBE_WRITE_REG(hw, IXGBE_FCRTL(i), 0);
IXGBE_WRITE_REG(hw, IXGBE_FCRTH(i), 0);
}
}
reg = hw->fc.pause_time * 0x00010001;
for (i = 0; i < (MAX_TRAFFIC_CLASS / 2); i++)
IXGBE_WRITE_REG(hw, IXGBE_FCTTV(i), reg);
IXGBE_WRITE_REG(hw, IXGBE_FCRTV, hw->fc.pause_time / 2);
return 0;
}
static s32 ixgbe_start_mac_link_82598(struct ixgbe_hw *hw,
bool autoneg_wait_to_complete)
{
u32 autoc_reg;
u32 links_reg;
u32 i;
s32 status = 0;
autoc_reg = IXGBE_READ_REG(hw, IXGBE_AUTOC);
autoc_reg |= IXGBE_AUTOC_AN_RESTART;
IXGBE_WRITE_REG(hw, IXGBE_AUTOC, autoc_reg);
if (autoneg_wait_to_complete) {
if ((autoc_reg & IXGBE_AUTOC_LMS_MASK) ==
IXGBE_AUTOC_LMS_KX4_AN ||
(autoc_reg & IXGBE_AUTOC_LMS_MASK) ==
IXGBE_AUTOC_LMS_KX4_AN_1G_AN) {
links_reg = 0;
for (i = 0; i < IXGBE_AUTO_NEG_TIME; i++) {
links_reg = IXGBE_READ_REG(hw, IXGBE_LINKS);
if (links_reg & IXGBE_LINKS_KX_AN_COMP)
break;
msleep(100);
}
if (!(links_reg & IXGBE_LINKS_KX_AN_COMP)) {
status = IXGBE_ERR_AUTONEG_NOT_COMPLETE;
hw_dbg(hw, "Autonegotiation did not complete.\n");
}
}
}
msleep(50);
return status;
}
static s32 ixgbe_validate_link_ready(struct ixgbe_hw *hw)
{
u32 timeout;
u16 an_reg;
if (hw->device_id != IXGBE_DEV_ID_82598AT2)
return 0;
for (timeout = 0;
timeout < IXGBE_VALIDATE_LINK_READY_TIMEOUT; timeout++) {
hw->phy.ops.read_reg(hw, MDIO_STAT1, MDIO_MMD_AN, &an_reg);
if ((an_reg & MDIO_AN_STAT1_COMPLETE) &&
(an_reg & MDIO_STAT1_LSTATUS))
break;
msleep(100);
}
if (timeout == IXGBE_VALIDATE_LINK_READY_TIMEOUT) {
hw_dbg(hw, "Link was indicated but link is down\n");
return IXGBE_ERR_LINK_SETUP;
}
return 0;
}
static s32 ixgbe_check_mac_link_82598(struct ixgbe_hw *hw,
ixgbe_link_speed *speed, bool *link_up,
bool link_up_wait_to_complete)
{
u32 links_reg;
u32 i;
u16 link_reg, adapt_comp_reg;
if (hw->phy.type == ixgbe_phy_nl) {
hw->phy.ops.read_reg(hw, 0xC79F, MDIO_MMD_PMAPMD, &link_reg);
hw->phy.ops.read_reg(hw, 0xC79F, MDIO_MMD_PMAPMD, &link_reg);
hw->phy.ops.read_reg(hw, 0xC00C, MDIO_MMD_PMAPMD,
&adapt_comp_reg);
if (link_up_wait_to_complete) {
for (i = 0; i < IXGBE_LINK_UP_TIME; i++) {
if ((link_reg & 1) &&
((adapt_comp_reg & 1) == 0)) {
*link_up = true;
break;
} else {
*link_up = false;
}
msleep(100);
hw->phy.ops.read_reg(hw, 0xC79F,
MDIO_MMD_PMAPMD,
&link_reg);
hw->phy.ops.read_reg(hw, 0xC00C,
MDIO_MMD_PMAPMD,
&adapt_comp_reg);
}
} else {
if ((link_reg & 1) && ((adapt_comp_reg & 1) == 0))
*link_up = true;
else
*link_up = false;
}
if (!*link_up)
return 0;
}
links_reg = IXGBE_READ_REG(hw, IXGBE_LINKS);
if (link_up_wait_to_complete) {
for (i = 0; i < IXGBE_LINK_UP_TIME; i++) {
if (links_reg & IXGBE_LINKS_UP) {
*link_up = true;
break;
} else {
*link_up = false;
}
msleep(100);
links_reg = IXGBE_READ_REG(hw, IXGBE_LINKS);
}
} else {
if (links_reg & IXGBE_LINKS_UP)
*link_up = true;
else
*link_up = false;
}
if (links_reg & IXGBE_LINKS_SPEED)
*speed = IXGBE_LINK_SPEED_10GB_FULL;
else
*speed = IXGBE_LINK_SPEED_1GB_FULL;
if ((hw->device_id == IXGBE_DEV_ID_82598AT2) && *link_up &&
(ixgbe_validate_link_ready(hw) != 0))
*link_up = false;
return 0;
}
static s32 ixgbe_setup_mac_link_82598(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
bool autoneg = false;
ixgbe_link_speed link_capabilities = IXGBE_LINK_SPEED_UNKNOWN;
u32 curr_autoc = IXGBE_READ_REG(hw, IXGBE_AUTOC);
u32 autoc = curr_autoc;
u32 link_mode = autoc & IXGBE_AUTOC_LMS_MASK;
ixgbe_get_link_capabilities_82598(hw, &link_capabilities, &autoneg);
speed &= link_capabilities;
if (speed == IXGBE_LINK_SPEED_UNKNOWN)
return IXGBE_ERR_LINK_SETUP;
else if (link_mode == IXGBE_AUTOC_LMS_KX4_AN ||
link_mode == IXGBE_AUTOC_LMS_KX4_AN_1G_AN) {
autoc &= ~IXGBE_AUTOC_KX4_KX_SUPP_MASK;
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
autoc |= IXGBE_AUTOC_KX4_SUPP;
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
autoc |= IXGBE_AUTOC_KX_SUPP;
if (autoc != curr_autoc)
IXGBE_WRITE_REG(hw, IXGBE_AUTOC, autoc);
}
return ixgbe_start_mac_link_82598(hw, autoneg_wait_to_complete);
}
static s32 ixgbe_setup_copper_link_82598(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
s32 status;
status = hw->phy.ops.setup_link_speed(hw, speed,
autoneg_wait_to_complete);
ixgbe_start_mac_link_82598(hw, autoneg_wait_to_complete);
return status;
}
static s32 ixgbe_reset_hw_82598(struct ixgbe_hw *hw)
{
s32 status;
s32 phy_status = 0;
u32 ctrl;
u32 gheccr;
u32 i;
u32 autoc;
u8 analog_val;
status = hw->mac.ops.stop_adapter(hw);
if (status)
return status;
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_LPBK, &analog_val);
if (analog_val & IXGBE_ATLAS_PDN_TX_REG_EN) {
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_LPBK,
&analog_val);
analog_val &= ~IXGBE_ATLAS_PDN_TX_REG_EN;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_LPBK,
analog_val);
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_10G,
&analog_val);
analog_val &= ~IXGBE_ATLAS_PDN_TX_10G_QL_ALL;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_10G,
analog_val);
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_1G,
&analog_val);
analog_val &= ~IXGBE_ATLAS_PDN_TX_1G_QL_ALL;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_1G,
analog_val);
hw->mac.ops.read_analog_reg8(hw, IXGBE_ATLAS_PDN_AN,
&analog_val);
analog_val &= ~IXGBE_ATLAS_PDN_TX_AN_QL_ALL;
hw->mac.ops.write_analog_reg8(hw, IXGBE_ATLAS_PDN_AN,
analog_val);
}
if (hw->phy.reset_disable == false) {
phy_status = hw->phy.ops.init(hw);
if (phy_status == IXGBE_ERR_SFP_NOT_SUPPORTED)
return phy_status;
if (phy_status == IXGBE_ERR_SFP_NOT_PRESENT)
goto mac_reset_top;
hw->phy.ops.reset(hw);
}
mac_reset_top:
ctrl = IXGBE_READ_REG(hw, IXGBE_CTRL) | IXGBE_CTRL_RST;
IXGBE_WRITE_REG(hw, IXGBE_CTRL, ctrl);
IXGBE_WRITE_FLUSH(hw);
usleep_range(1000, 1200);
for (i = 0; i < 10; i++) {
ctrl = IXGBE_READ_REG(hw, IXGBE_CTRL);
if (!(ctrl & IXGBE_CTRL_RST))
break;
udelay(1);
}
if (ctrl & IXGBE_CTRL_RST) {
status = IXGBE_ERR_RESET_FAILED;
hw_dbg(hw, "Reset polling failed to complete.\n");
}
msleep(50);
if (hw->mac.flags & IXGBE_FLAGS_DOUBLE_RESET_REQUIRED) {
hw->mac.flags &= ~IXGBE_FLAGS_DOUBLE_RESET_REQUIRED;
goto mac_reset_top;
}
gheccr = IXGBE_READ_REG(hw, IXGBE_GHECCR);
gheccr &= ~(BIT(21) | BIT(18) | BIT(9) | BIT(6));
IXGBE_WRITE_REG(hw, IXGBE_GHECCR, gheccr);
autoc = IXGBE_READ_REG(hw, IXGBE_AUTOC);
if (hw->mac.orig_link_settings_stored == false) {
hw->mac.orig_autoc = autoc;
hw->mac.orig_link_settings_stored = true;
} else if (autoc != hw->mac.orig_autoc) {
IXGBE_WRITE_REG(hw, IXGBE_AUTOC, hw->mac.orig_autoc);
}
hw->mac.ops.get_mac_addr(hw, hw->mac.perm_addr);
hw->mac.ops.init_rx_addrs(hw);
if (phy_status)
status = phy_status;
return status;
}
static s32 ixgbe_set_vmdq_82598(struct ixgbe_hw *hw, u32 rar, u32 vmdq)
{
u32 rar_high;
u32 rar_entries = hw->mac.num_rar_entries;
if (rar >= rar_entries) {
hw_dbg(hw, "RAR index %d is out of range.\n", rar);
return IXGBE_ERR_INVALID_ARGUMENT;
}
rar_high = IXGBE_READ_REG(hw, IXGBE_RAH(rar));
rar_high &= ~IXGBE_RAH_VIND_MASK;
rar_high |= ((vmdq << IXGBE_RAH_VIND_SHIFT) & IXGBE_RAH_VIND_MASK);
IXGBE_WRITE_REG(hw, IXGBE_RAH(rar), rar_high);
return 0;
}
static s32 ixgbe_clear_vmdq_82598(struct ixgbe_hw *hw, u32 rar, u32 vmdq)
{
u32 rar_high;
u32 rar_entries = hw->mac.num_rar_entries;
if (rar >= rar_entries) {
hw_dbg(hw, "RAR index %d is out of range.\n", rar);
return IXGBE_ERR_INVALID_ARGUMENT;
}
rar_high = IXGBE_READ_REG(hw, IXGBE_RAH(rar));
if (rar_high & IXGBE_RAH_VIND_MASK) {
rar_high &= ~IXGBE_RAH_VIND_MASK;
IXGBE_WRITE_REG(hw, IXGBE_RAH(rar), rar_high);
}
return 0;
}
static s32 ixgbe_set_vfta_82598(struct ixgbe_hw *hw, u32 vlan, u32 vind,
bool vlan_on, bool vlvf_bypass)
{
u32 regindex;
u32 bitindex;
u32 bits;
u32 vftabyte;
if (vlan > 4095)
return IXGBE_ERR_PARAM;
regindex = (vlan >> 5) & 0x7F;
vftabyte = ((vlan >> 3) & 0x03);
bitindex = (vlan & 0x7) << 2;
bits = IXGBE_READ_REG(hw, IXGBE_VFTAVIND(vftabyte, regindex));
bits &= (~(0x0F << bitindex));
bits |= (vind << bitindex);
IXGBE_WRITE_REG(hw, IXGBE_VFTAVIND(vftabyte, regindex), bits);
bitindex = vlan & 0x1F;
bits = IXGBE_READ_REG(hw, IXGBE_VFTA(regindex));
if (vlan_on)
bits |= BIT(bitindex);
else
bits &= ~BIT(bitindex);
IXGBE_WRITE_REG(hw, IXGBE_VFTA(regindex), bits);
return 0;
}
static s32 ixgbe_clear_vfta_82598(struct ixgbe_hw *hw)
{
u32 offset;
u32 vlanbyte;
for (offset = 0; offset < hw->mac.vft_size; offset++)
IXGBE_WRITE_REG(hw, IXGBE_VFTA(offset), 0);
for (vlanbyte = 0; vlanbyte < 4; vlanbyte++)
for (offset = 0; offset < hw->mac.vft_size; offset++)
IXGBE_WRITE_REG(hw, IXGBE_VFTAVIND(vlanbyte, offset),
0);
return 0;
}
static s32 ixgbe_read_analog_reg8_82598(struct ixgbe_hw *hw, u32 reg, u8 *val)
{
u32 atlas_ctl;
IXGBE_WRITE_REG(hw, IXGBE_ATLASCTL,
IXGBE_ATLASCTL_WRITE_CMD | (reg << 8));
IXGBE_WRITE_FLUSH(hw);
udelay(10);
atlas_ctl = IXGBE_READ_REG(hw, IXGBE_ATLASCTL);
*val = (u8)atlas_ctl;
return 0;
}
static s32 ixgbe_write_analog_reg8_82598(struct ixgbe_hw *hw, u32 reg, u8 val)
{
u32 atlas_ctl;
atlas_ctl = (reg << 8) | val;
IXGBE_WRITE_REG(hw, IXGBE_ATLASCTL, atlas_ctl);
IXGBE_WRITE_FLUSH(hw);
udelay(10);
return 0;
}
static s32 ixgbe_read_i2c_phy_82598(struct ixgbe_hw *hw, u8 dev_addr,
u8 byte_offset, u8 *eeprom_data)
{
s32 status = 0;
u16 sfp_addr = 0;
u16 sfp_data = 0;
u16 sfp_stat = 0;
u16 gssr;
u32 i;
if (IXGBE_READ_REG(hw, IXGBE_STATUS) & IXGBE_STATUS_LAN_ID_1)
gssr = IXGBE_GSSR_PHY1_SM;
else
gssr = IXGBE_GSSR_PHY0_SM;
if (hw->mac.ops.acquire_swfw_sync(hw, gssr) != 0)
return IXGBE_ERR_SWFW_SYNC;
if (hw->phy.type == ixgbe_phy_nl) {
sfp_addr = (dev_addr << 8) + byte_offset;
sfp_addr = (sfp_addr | IXGBE_I2C_EEPROM_READ_MASK);
hw->phy.ops.write_reg_mdi(hw,
IXGBE_MDIO_PMA_PMD_SDA_SCL_ADDR,
MDIO_MMD_PMAPMD,
sfp_addr);
for (i = 0; i < 100; i++) {
hw->phy.ops.read_reg_mdi(hw,
IXGBE_MDIO_PMA_PMD_SDA_SCL_STAT,
MDIO_MMD_PMAPMD,
&sfp_stat);
sfp_stat = sfp_stat & IXGBE_I2C_EEPROM_STATUS_MASK;
if (sfp_stat != IXGBE_I2C_EEPROM_STATUS_IN_PROGRESS)
break;
usleep_range(10000, 20000);
}
if (sfp_stat != IXGBE_I2C_EEPROM_STATUS_PASS) {
hw_dbg(hw, "EEPROM read did not pass.\n");
status = IXGBE_ERR_SFP_NOT_PRESENT;
goto out;
}
hw->phy.ops.read_reg_mdi(hw, IXGBE_MDIO_PMA_PMD_SDA_SCL_DATA,
MDIO_MMD_PMAPMD, &sfp_data);
*eeprom_data = (u8)(sfp_data >> 8);
} else {
status = IXGBE_ERR_PHY;
}
out:
hw->mac.ops.release_swfw_sync(hw, gssr);
return status;
}
static s32 ixgbe_read_i2c_eeprom_82598(struct ixgbe_hw *hw, u8 byte_offset,
u8 *eeprom_data)
{
return ixgbe_read_i2c_phy_82598(hw, IXGBE_I2C_EEPROM_DEV_ADDR,
byte_offset, eeprom_data);
}
static s32 ixgbe_read_i2c_sff8472_82598(struct ixgbe_hw *hw, u8 byte_offset,
u8 *sff8472_data)
{
return ixgbe_read_i2c_phy_82598(hw, IXGBE_I2C_EEPROM_DEV_ADDR2,
byte_offset, sff8472_data);
}
static void ixgbe_set_lan_id_multi_port_pcie_82598(struct ixgbe_hw *hw)
{
struct ixgbe_bus_info *bus = &hw->bus;
u16 pci_gen = 0;
u16 pci_ctrl2 = 0;
ixgbe_set_lan_id_multi_port_pcie(hw);
hw->eeprom.ops.read(hw, IXGBE_PCIE_GENERAL_PTR, &pci_gen);
if ((pci_gen != 0) && (pci_gen != 0xFFFF)) {
hw->eeprom.ops.read(hw, pci_gen + IXGBE_PCIE_CTRL2, &pci_ctrl2);
if ((pci_ctrl2 & IXGBE_PCIE_CTRL2_LAN_DISABLE) &&
!(pci_ctrl2 & IXGBE_PCIE_CTRL2_DISABLE_SELECT) &&
!(pci_ctrl2 & IXGBE_PCIE_CTRL2_DUMMY_ENABLE)) {
bus->func = 0;
}
}
}
static void ixgbe_set_rxpba_82598(struct ixgbe_hw *hw, int num_pb,
u32 headroom, int strategy)
{
u32 rxpktsize = IXGBE_RXPBSIZE_64KB;
u8 i = 0;
if (!num_pb)
return;
switch (strategy) {
case PBA_STRATEGY_WEIGHTED:
rxpktsize = IXGBE_RXPBSIZE_80KB;
for (; i < 4; i++)
IXGBE_WRITE_REG(hw, IXGBE_RXPBSIZE(i), rxpktsize);
rxpktsize = IXGBE_RXPBSIZE_48KB;
case PBA_STRATEGY_EQUAL:
default:
for (; i < IXGBE_MAX_PACKET_BUFFERS; i++)
IXGBE_WRITE_REG(hw, IXGBE_RXPBSIZE(i), rxpktsize);
break;
}
for (i = 0; i < IXGBE_MAX_PACKET_BUFFERS; i++)
IXGBE_WRITE_REG(hw, IXGBE_TXPBSIZE(i), IXGBE_TXPBSIZE_40KB);
}
