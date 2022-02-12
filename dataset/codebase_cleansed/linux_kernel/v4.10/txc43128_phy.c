void falcon_txc_set_gpio_val(struct ef4_nic *efx, int pin, int on)
{
ef4_mdio_set_flag(efx, MDIO_MMD_PHYXS, TXC_GPIO_OUTPUT, 1 << pin, on);
}
void falcon_txc_set_gpio_dir(struct ef4_nic *efx, int pin, int dir)
{
ef4_mdio_set_flag(efx, MDIO_MMD_PHYXS, TXC_GPIO_DIR, 1 << pin, dir);
}
static int txc_reset_phy(struct ef4_nic *efx)
{
int rc = ef4_mdio_reset_mmd(efx, MDIO_MMD_PMAPMD,
TXC_MAX_RESET_TIME / TXC_RESET_WAIT,
TXC_RESET_WAIT);
if (rc < 0)
goto fail;
rc = ef4_mdio_check_mmds(efx, TXC_REQUIRED_DEVS);
if (rc < 0)
goto fail;
return 0;
fail:
netif_err(efx, hw, efx->net_dev, TXCNAME ": reset timed out!\n");
return rc;
}
static int txc_bist_one(struct ef4_nic *efx, int mmd, int test)
{
int ctrl, bctl;
int lane;
int rc = 0;
ctrl = ef4_mdio_read(efx, MDIO_MMD_PCS, TXC_MTDIABLO_CTRL);
ctrl |= (1 << TXC_MTDIABLO_CTRL_PMA_LOOP_LBN);
ef4_mdio_write(efx, MDIO_MMD_PCS, TXC_MTDIABLO_CTRL, ctrl);
bctl = (test << TXC_BIST_CTRL_TYPE_LBN);
ef4_mdio_write(efx, mmd, TXC_BIST_CTL, bctl);
bctl |= (1 << TXC_BIST_CTRL_ENAB_LBN);
ef4_mdio_write(efx, mmd, TXC_BIST_CTL, bctl);
ef4_mdio_write(efx, mmd, TXC_BIST_CTL,
bctl | (1 << TXC_BIST_CTRL_STRT_LBN));
udelay(TXC_BIST_DURATION);
bctl |= (1 << TXC_BIST_CTRL_STOP_LBN);
ef4_mdio_write(efx, mmd, TXC_BIST_CTL, bctl);
while (bctl & (1 << TXC_BIST_CTRL_STOP_LBN))
bctl = ef4_mdio_read(efx, mmd, TXC_BIST_CTL);
for (lane = 0; lane < 4; lane++) {
int count = ef4_mdio_read(efx, mmd, TXC_BIST_RX0ERRCNT + lane);
if (count != 0) {
netif_err(efx, hw, efx->net_dev, TXCNAME": BIST error. "
"Lane %d had %d errs\n", lane, count);
rc = -EIO;
}
count = ef4_mdio_read(efx, mmd, TXC_BIST_RX0FRMCNT + lane);
if (count == 0) {
netif_err(efx, hw, efx->net_dev, TXCNAME": BIST error. "
"Lane %d got 0 frames\n", lane);
rc = -EIO;
}
}
if (rc == 0)
netif_info(efx, hw, efx->net_dev, TXCNAME": BIST pass\n");
ef4_mdio_write(efx, mmd, TXC_BIST_CTL, 0);
ctrl &= ~(1 << TXC_MTDIABLO_CTRL_PMA_LOOP_LBN);
ef4_mdio_write(efx, MDIO_MMD_PCS, TXC_MTDIABLO_CTRL, ctrl);
return rc;
}
static int txc_bist(struct ef4_nic *efx)
{
return txc_bist_one(efx, MDIO_MMD_PCS, TXC_BIST_CTRL_TYPE_TSD);
}
static void txc_apply_defaults(struct ef4_nic *efx)
{
int mctrl;
ef4_mdio_write(efx, MDIO_MMD_PHYXS, TXC_ALRGS_ATXPRE0, TXC_ATXPRE_NONE);
ef4_mdio_write(efx, MDIO_MMD_PHYXS, TXC_ALRGS_ATXPRE1, TXC_ATXPRE_NONE);
ef4_mdio_write(efx, MDIO_MMD_PHYXS,
TXC_ALRGS_ATXAMP0, TXC_ATXAMP_0820_BOTH);
ef4_mdio_write(efx, MDIO_MMD_PHYXS,
TXC_ALRGS_ATXAMP1, TXC_ATXAMP_0820_BOTH);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD,
TXC_ALRGS_ATXPRE0, TXC_ATXPRE_DEFAULT);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD,
TXC_ALRGS_ATXPRE1, TXC_ATXPRE_DEFAULT);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD,
TXC_ALRGS_ATXAMP0, TXC_ATXAMP_DEFAULT);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD,
TXC_ALRGS_ATXAMP1, TXC_ATXAMP_DEFAULT);
mctrl = ef4_mdio_read(efx, MDIO_MMD_PHYXS, TXC_MRGS_CTL);
mctrl &= ~((1 << TXC_MCTL_TXLED_LBN) | (1 << TXC_MCTL_RXLED_LBN));
ef4_mdio_write(efx, MDIO_MMD_PHYXS, TXC_MRGS_CTL, mctrl);
txc_reset_logic(efx);
falcon_board(efx)->type->init_phy(efx);
}
static int txc43128_phy_probe(struct ef4_nic *efx)
{
struct txc43128_data *phy_data;
phy_data = kzalloc(sizeof(*phy_data), GFP_KERNEL);
if (!phy_data)
return -ENOMEM;
efx->phy_data = phy_data;
phy_data->phy_mode = efx->phy_mode;
efx->mdio.mmds = TXC_REQUIRED_DEVS;
efx->mdio.mode_support = MDIO_SUPPORTS_C45 | MDIO_EMULATE_C22;
efx->loopback_modes = TXC_LOOPBACKS | FALCON_XMAC_LOOPBACKS;
return 0;
}
static int txc43128_phy_init(struct ef4_nic *efx)
{
int rc;
rc = txc_reset_phy(efx);
if (rc < 0)
return rc;
rc = txc_bist(efx);
if (rc < 0)
return rc;
txc_apply_defaults(efx);
return 0;
}
static void txc_glrgs_lane_power(struct ef4_nic *efx, int mmd)
{
int pd = (1 << TXC_GLCMD_L01PD_LBN) | (1 << TXC_GLCMD_L23PD_LBN);
int ctl = ef4_mdio_read(efx, mmd, TXC_GLRGS_GLCMD);
if (!(efx->phy_mode & PHY_MODE_LOW_POWER))
ctl &= ~pd;
else
ctl |= pd;
ef4_mdio_write(efx, mmd, TXC_GLRGS_GLCMD, ctl);
}
static void txc_analog_lane_power(struct ef4_nic *efx, int mmd)
{
int txpd = (1 << TXC_ATXCTL_TXPD3_LBN) | (1 << TXC_ATXCTL_TXPD2_LBN)
| (1 << TXC_ATXCTL_TXPD1_LBN) | (1 << TXC_ATXCTL_TXPD0_LBN);
int rxpd = (1 << TXC_ARXCTL_RXPD3_LBN) | (1 << TXC_ARXCTL_RXPD2_LBN)
| (1 << TXC_ARXCTL_RXPD1_LBN) | (1 << TXC_ARXCTL_RXPD0_LBN);
int txctl = ef4_mdio_read(efx, mmd, TXC_ALRGS_ATXCTL);
int rxctl = ef4_mdio_read(efx, mmd, TXC_ALRGS_ARXCTL);
if (!(efx->phy_mode & PHY_MODE_LOW_POWER)) {
txctl &= ~txpd;
rxctl &= ~rxpd;
} else {
txctl |= txpd;
rxctl |= rxpd;
}
ef4_mdio_write(efx, mmd, TXC_ALRGS_ATXCTL, txctl);
ef4_mdio_write(efx, mmd, TXC_ALRGS_ARXCTL, rxctl);
}
static void txc_set_power(struct ef4_nic *efx)
{
ef4_mdio_set_mmds_lpower(efx,
!!(efx->phy_mode & PHY_MODE_LOW_POWER),
TXC_REQUIRED_DEVS);
txc_glrgs_lane_power(efx, MDIO_MMD_PCS);
txc_glrgs_lane_power(efx, MDIO_MMD_PHYXS);
txc_analog_lane_power(efx, MDIO_MMD_PMAPMD);
txc_analog_lane_power(efx, MDIO_MMD_PHYXS);
}
static void txc_reset_logic_mmd(struct ef4_nic *efx, int mmd)
{
int val = ef4_mdio_read(efx, mmd, TXC_GLRGS_GLCMD);
int tries = 50;
val |= (1 << TXC_GLCMD_LMTSWRST_LBN);
ef4_mdio_write(efx, mmd, TXC_GLRGS_GLCMD, val);
while (--tries) {
val = ef4_mdio_read(efx, mmd, TXC_GLRGS_GLCMD);
if (!(val & (1 << TXC_GLCMD_LMTSWRST_LBN)))
break;
udelay(1);
}
if (!tries)
netif_info(efx, hw, efx->net_dev,
TXCNAME " Logic reset timed out!\n");
}
static void txc_reset_logic(struct ef4_nic *efx)
{
txc_reset_logic_mmd(efx, MDIO_MMD_PCS);
}
static bool txc43128_phy_read_link(struct ef4_nic *efx)
{
return ef4_mdio_links_ok(efx, TXC_REQUIRED_DEVS);
}
static int txc43128_phy_reconfigure(struct ef4_nic *efx)
{
struct txc43128_data *phy_data = efx->phy_data;
enum ef4_phy_mode mode_change = efx->phy_mode ^ phy_data->phy_mode;
bool loop_change = LOOPBACK_CHANGED(phy_data, efx, TXC_LOOPBACKS);
if (efx->phy_mode & mode_change & PHY_MODE_TX_DISABLED) {
txc_reset_phy(efx);
txc_apply_defaults(efx);
falcon_reset_xaui(efx);
mode_change &= ~PHY_MODE_TX_DISABLED;
}
ef4_mdio_transmit_disable(efx);
ef4_mdio_phy_reconfigure(efx);
if (mode_change & PHY_MODE_LOW_POWER)
txc_set_power(efx);
if (loop_change || mode_change)
txc_reset_logic(efx);
phy_data->phy_mode = efx->phy_mode;
phy_data->loopback_mode = efx->loopback_mode;
return 0;
}
static void txc43128_phy_fini(struct ef4_nic *efx)
{
ef4_mdio_write(efx, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL, 0);
}
static void txc43128_phy_remove(struct ef4_nic *efx)
{
kfree(efx->phy_data);
efx->phy_data = NULL;
}
static bool txc43128_phy_poll(struct ef4_nic *efx)
{
struct txc43128_data *data = efx->phy_data;
bool was_up = efx->link_state.up;
efx->link_state.up = txc43128_phy_read_link(efx);
efx->link_state.speed = 10000;
efx->link_state.fd = true;
efx->link_state.fc = efx->wanted_fc;
if (efx->link_state.up || (efx->loopback_mode != LOOPBACK_NONE)) {
data->bug10934_timer = jiffies;
} else {
if (time_after_eq(jiffies, (data->bug10934_timer +
BUG10934_RESET_INTERVAL))) {
data->bug10934_timer = jiffies;
txc_reset_logic(efx);
}
}
return efx->link_state.up != was_up;
}
static const char *txc43128_test_name(struct ef4_nic *efx, unsigned int index)
{
if (index < ARRAY_SIZE(txc43128_test_names))
return txc43128_test_names[index];
return NULL;
}
static int txc43128_run_tests(struct ef4_nic *efx, int *results, unsigned flags)
{
int rc;
if (!(flags & ETH_TEST_FL_OFFLINE))
return 0;
rc = txc_reset_phy(efx);
if (rc < 0)
return rc;
rc = txc_bist(efx);
txc_apply_defaults(efx);
results[0] = rc ? -1 : 1;
return rc;
}
static void txc43128_get_settings(struct ef4_nic *efx, struct ethtool_cmd *ecmd)
{
mdio45_ethtool_gset(&efx->mdio, ecmd);
}
