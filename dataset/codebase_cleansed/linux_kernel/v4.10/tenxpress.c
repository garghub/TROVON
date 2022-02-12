static int tenxpress_init(struct ef4_nic *efx)
{
ef4_mdio_write(efx, MDIO_MMD_PCS, PCS_TEST_SELECT_REG,
1 << CLK312_EN_LBN);
ef4_mdio_set_flag(efx, MDIO_MMD_PMAPMD, PMA_PMD_LED_CTRL_REG,
1 << PMA_PMA_LED_ACTIVITY_LBN, true);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD, PMA_PMD_LED_OVERR_REG,
SFX7101_PMA_PMD_LED_DEFAULT);
return 0;
}
static int tenxpress_phy_probe(struct ef4_nic *efx)
{
struct tenxpress_phy_data *phy_data;
phy_data = kzalloc(sizeof(*phy_data), GFP_KERNEL);
if (!phy_data)
return -ENOMEM;
efx->phy_data = phy_data;
phy_data->phy_mode = efx->phy_mode;
efx->mdio.mmds = TENXPRESS_REQUIRED_DEVS;
efx->mdio.mode_support = MDIO_SUPPORTS_C45;
efx->loopback_modes = SFX7101_LOOPBACKS | FALCON_XMAC_LOOPBACKS;
efx->link_advertising = (ADVERTISED_TP | ADVERTISED_Autoneg |
ADVERTISED_10000baseT_Full);
return 0;
}
static int tenxpress_phy_init(struct ef4_nic *efx)
{
int rc;
falcon_board(efx)->type->init_phy(efx);
if (!(efx->phy_mode & PHY_MODE_SPECIAL)) {
rc = ef4_mdio_wait_reset_mmds(efx, TENXPRESS_REQUIRED_DEVS);
if (rc < 0)
return rc;
rc = ef4_mdio_check_mmds(efx, TENXPRESS_REQUIRED_DEVS);
if (rc < 0)
return rc;
}
rc = tenxpress_init(efx);
if (rc < 0)
return rc;
ef4_link_set_wanted_fc(efx, efx->wanted_fc);
ef4_mdio_an_reconfigure(efx);
schedule_timeout_uninterruptible(HZ / 5);
falcon_reset_xaui(efx);
return 0;
}
static int tenxpress_special_reset(struct ef4_nic *efx)
{
int rc, reg;
falcon_stop_nic_stats(efx);
reg = ef4_mdio_read(efx, MDIO_MMD_PMAPMD, PMA_PMD_XCONTROL_REG);
reg |= (1 << PMA_PMD_EXT_SSR_LBN);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD, PMA_PMD_XCONTROL_REG, reg);
mdelay(200);
rc = ef4_mdio_wait_reset_mmds(efx, TENXPRESS_REQUIRED_DEVS);
if (rc < 0)
goto out;
rc = tenxpress_init(efx);
if (rc < 0)
goto out;
mdelay(10);
out:
falcon_start_nic_stats(efx);
return rc;
}
static void sfx7101_check_bad_lp(struct ef4_nic *efx, bool link_ok)
{
struct tenxpress_phy_data *pd = efx->phy_data;
bool bad_lp;
int reg;
if (link_ok) {
bad_lp = false;
} else {
reg = ef4_mdio_read(efx, MDIO_MMD_AN, MDIO_STAT1);
if (!(reg & MDIO_AN_STAT1_LPABLE))
return;
bad_lp = !(reg & MDIO_AN_STAT1_COMPLETE);
if (bad_lp)
pd->bad_lp_tries++;
}
if (!pd->bad_lp_tries)
return;
if (!bad_lp || pd->bad_lp_tries == MAX_BAD_LP_TRIES) {
reg = ef4_mdio_read(efx, MDIO_MMD_PMAPMD,
PMA_PMD_LED_OVERR_REG);
reg &= ~(PMA_PMD_LED_MASK << PMA_PMD_LED_RX_LBN);
if (!bad_lp) {
reg |= PMA_PMD_LED_OFF << PMA_PMD_LED_RX_LBN;
} else {
reg |= PMA_PMD_LED_FLASH << PMA_PMD_LED_RX_LBN;
netif_err(efx, link, efx->net_dev,
"appears to be plugged into a port"
" that is not 10GBASE-T capable. The PHY"
" supports 10GBASE-T ONLY, so no link can"
" be established\n");
}
ef4_mdio_write(efx, MDIO_MMD_PMAPMD,
PMA_PMD_LED_OVERR_REG, reg);
pd->bad_lp_tries = bad_lp;
}
}
static bool sfx7101_link_ok(struct ef4_nic *efx)
{
return ef4_mdio_links_ok(efx,
MDIO_DEVS_PMAPMD |
MDIO_DEVS_PCS |
MDIO_DEVS_PHYXS);
}
static void tenxpress_ext_loopback(struct ef4_nic *efx)
{
ef4_mdio_set_flag(efx, MDIO_MMD_PHYXS, PHYXS_TEST1,
1 << LOOPBACK_NEAR_LBN,
efx->loopback_mode == LOOPBACK_PHYXS);
}
static void tenxpress_low_power(struct ef4_nic *efx)
{
ef4_mdio_set_mmds_lpower(
efx, !!(efx->phy_mode & PHY_MODE_LOW_POWER),
TENXPRESS_REQUIRED_DEVS);
}
static int tenxpress_phy_reconfigure(struct ef4_nic *efx)
{
struct tenxpress_phy_data *phy_data = efx->phy_data;
bool phy_mode_change, loop_reset;
if (efx->phy_mode & (PHY_MODE_OFF | PHY_MODE_SPECIAL)) {
phy_data->phy_mode = efx->phy_mode;
return 0;
}
phy_mode_change = (efx->phy_mode == PHY_MODE_NORMAL &&
phy_data->phy_mode != PHY_MODE_NORMAL);
loop_reset = (LOOPBACK_OUT_OF(phy_data, efx, LOOPBACKS_EXTERNAL(efx)) ||
LOOPBACK_CHANGED(phy_data, efx, 1 << LOOPBACK_GPHY));
if (loop_reset || phy_mode_change) {
tenxpress_special_reset(efx);
falcon_reset_xaui(efx);
}
tenxpress_low_power(efx);
ef4_mdio_transmit_disable(efx);
ef4_mdio_phy_reconfigure(efx);
tenxpress_ext_loopback(efx);
ef4_mdio_an_reconfigure(efx);
phy_data->loopback_mode = efx->loopback_mode;
phy_data->phy_mode = efx->phy_mode;
return 0;
}
static bool tenxpress_phy_poll(struct ef4_nic *efx)
{
struct ef4_link_state old_state = efx->link_state;
efx->link_state.up = sfx7101_link_ok(efx);
efx->link_state.speed = 10000;
efx->link_state.fd = true;
efx->link_state.fc = ef4_mdio_get_pause(efx);
sfx7101_check_bad_lp(efx, efx->link_state.up);
return !ef4_link_state_equal(&efx->link_state, &old_state);
}
static void sfx7101_phy_fini(struct ef4_nic *efx)
{
int reg;
reg = (1 << PMA_PMD_LNPGA_POWERDOWN_LBN);
ef4_mdio_write(efx, MDIO_MMD_PMAPMD, PMA_PMD_XCONTROL_REG, reg);
schedule_timeout_uninterruptible(LNPGA_PDOWN_WAIT);
}
static void tenxpress_phy_remove(struct ef4_nic *efx)
{
kfree(efx->phy_data);
efx->phy_data = NULL;
}
void tenxpress_set_id_led(struct ef4_nic *efx, enum ef4_led_mode mode)
{
int reg;
switch (mode) {
case EF4_LED_OFF:
reg = (PMA_PMD_LED_OFF << PMA_PMD_LED_TX_LBN) |
(PMA_PMD_LED_OFF << PMA_PMD_LED_RX_LBN) |
(PMA_PMD_LED_OFF << PMA_PMD_LED_LINK_LBN);
break;
case EF4_LED_ON:
reg = (PMA_PMD_LED_ON << PMA_PMD_LED_TX_LBN) |
(PMA_PMD_LED_ON << PMA_PMD_LED_RX_LBN) |
(PMA_PMD_LED_ON << PMA_PMD_LED_LINK_LBN);
break;
default:
reg = SFX7101_PMA_PMD_LED_DEFAULT;
break;
}
ef4_mdio_write(efx, MDIO_MMD_PMAPMD, PMA_PMD_LED_OVERR_REG, reg);
}
static const char *sfx7101_test_name(struct ef4_nic *efx, unsigned int index)
{
if (index < ARRAY_SIZE(sfx7101_test_names))
return sfx7101_test_names[index];
return NULL;
}
static int
sfx7101_run_tests(struct ef4_nic *efx, int *results, unsigned flags)
{
int rc;
if (!(flags & ETH_TEST_FL_OFFLINE))
return 0;
rc = tenxpress_special_reset(efx);
results[0] = rc ? -1 : 1;
ef4_mdio_an_reconfigure(efx);
return rc;
}
static void
tenxpress_get_settings(struct ef4_nic *efx, struct ethtool_cmd *ecmd)
{
u32 adv = 0, lpa = 0;
int reg;
reg = ef4_mdio_read(efx, MDIO_MMD_AN, MDIO_AN_10GBT_CTRL);
if (reg & MDIO_AN_10GBT_CTRL_ADV10G)
adv |= ADVERTISED_10000baseT_Full;
reg = ef4_mdio_read(efx, MDIO_MMD_AN, MDIO_AN_10GBT_STAT);
if (reg & MDIO_AN_10GBT_STAT_LP10G)
lpa |= ADVERTISED_10000baseT_Full;
mdio45_ethtool_gset_npage(&efx->mdio, ecmd, adv, lpa);
if (LOOPBACK_EXTERNAL(efx))
ethtool_cmd_speed_set(ecmd, SPEED_10000);
}
static int tenxpress_set_settings(struct ef4_nic *efx, struct ethtool_cmd *ecmd)
{
if (!ecmd->autoneg)
return -EINVAL;
return ef4_mdio_set_settings(efx, ecmd);
}
static void sfx7101_set_npage_adv(struct ef4_nic *efx, u32 advertising)
{
ef4_mdio_set_flag(efx, MDIO_MMD_AN, MDIO_AN_10GBT_CTRL,
MDIO_AN_10GBT_CTRL_ADV10G,
advertising & ADVERTISED_10000baseT_Full);
}
