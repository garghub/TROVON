static int amd_xgbe_an_enable_kr_training(struct phy_device *phydev)
{
int ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL);
if (ret < 0)
return ret;
ret |= 0x02;
phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL, ret);
return 0;
}
static int amd_xgbe_an_disable_kr_training(struct phy_device *phydev)
{
int ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL);
if (ret < 0)
return ret;
ret &= ~0x02;
phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL, ret);
return 0;
}
static int amd_xgbe_phy_pcs_power_cycle(struct phy_device *phydev)
{
int ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
return ret;
ret |= MDIO_CTRL1_LPOWER;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
usleep_range(75, 100);
ret &= ~MDIO_CTRL1_LPOWER;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
return 0;
}
static void amd_xgbe_phy_serdes_start_ratechange(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, RATECHANGE, 1);
}
static void amd_xgbe_phy_serdes_complete_ratechange(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
unsigned int wait;
u16 status;
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, RATECHANGE, 0);
wait = XGBE_PHY_RATECHANGE_COUNT;
while (wait--) {
usleep_range(50, 75);
status = XSIR0_IOREAD(priv, SIR0_STATUS);
if (XSIR_GET_BITS(status, SIR0_STATUS, RX_READY) &&
XSIR_GET_BITS(status, SIR0_STATUS, TX_READY))
return;
}
netdev_dbg(phydev->attached_dev, "SerDes rx/tx not ready (%#hx)\n",
status);
}
static int amd_xgbe_phy_xgmii_mode(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
int ret;
ret = amd_xgbe_an_enable_kr_training(phydev);
if (ret < 0)
return ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2);
if (ret < 0)
return ret;
ret &= ~MDIO_PCS_CTRL2_TYPE;
ret |= MDIO_PCS_CTRL2_10GBR;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
return ret;
ret &= ~MDIO_CTRL1_SPEEDSEL;
ret |= MDIO_CTRL1_SPEED10G;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
ret = amd_xgbe_phy_pcs_power_cycle(phydev);
if (ret < 0)
return ret;
amd_xgbe_phy_serdes_start_ratechange(phydev);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, DATARATE, SPEED_10000_RATE);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, WORDMODE, SPEED_10000_WORD);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, TXAMP, SPEED_10000_TXAMP);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, PLLSEL, SPEED_10000_PLL);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, PI_SPD_SEL, SPEED_10000_CDR);
XRXTX_IOWRITE_BITS(priv, RXTX_REG20, BLWC_ENA, RXTX_10000_BLWC);
XRXTX_IOWRITE_BITS(priv, RXTX_REG114, PQ_REG, RXTX_10000_PQ);
amd_xgbe_phy_serdes_complete_ratechange(phydev);
return 0;
}
static int amd_xgbe_phy_gmii_2500_mode(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
int ret;
ret = amd_xgbe_an_disable_kr_training(phydev);
if (ret < 0)
return ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2);
if (ret < 0)
return ret;
ret &= ~MDIO_PCS_CTRL2_TYPE;
ret |= MDIO_PCS_CTRL2_10GBX;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
return ret;
ret &= ~MDIO_CTRL1_SPEEDSEL;
ret |= MDIO_CTRL1_SPEED1G;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
ret = amd_xgbe_phy_pcs_power_cycle(phydev);
if (ret < 0)
return ret;
amd_xgbe_phy_serdes_start_ratechange(phydev);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, DATARATE, SPEED_2500_RATE);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, WORDMODE, SPEED_2500_WORD);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, TXAMP, SPEED_2500_TXAMP);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, PLLSEL, SPEED_2500_PLL);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, PI_SPD_SEL, SPEED_2500_CDR);
XRXTX_IOWRITE_BITS(priv, RXTX_REG20, BLWC_ENA, RXTX_2500_BLWC);
XRXTX_IOWRITE_BITS(priv, RXTX_REG114, PQ_REG, RXTX_2500_PQ);
amd_xgbe_phy_serdes_complete_ratechange(phydev);
return 0;
}
static int amd_xgbe_phy_gmii_mode(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
int ret;
ret = amd_xgbe_an_disable_kr_training(phydev);
if (ret < 0)
return ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2);
if (ret < 0)
return ret;
ret &= ~MDIO_PCS_CTRL2_TYPE;
ret |= MDIO_PCS_CTRL2_10GBX;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
return ret;
ret &= ~MDIO_CTRL1_SPEEDSEL;
ret |= MDIO_CTRL1_SPEED1G;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
ret = amd_xgbe_phy_pcs_power_cycle(phydev);
if (ret < 0)
return ret;
amd_xgbe_phy_serdes_start_ratechange(phydev);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, DATARATE, SPEED_1000_RATE);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, WORDMODE, SPEED_1000_WORD);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, TXAMP, SPEED_1000_TXAMP);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, PLLSEL, SPEED_1000_PLL);
XSIR1_IOWRITE_BITS(priv, SIR1_SPEED, PI_SPD_SEL, SPEED_1000_CDR);
XRXTX_IOWRITE_BITS(priv, RXTX_REG20, BLWC_ENA, RXTX_1000_BLWC);
XRXTX_IOWRITE_BITS(priv, RXTX_REG114, PQ_REG, RXTX_1000_PQ);
amd_xgbe_phy_serdes_complete_ratechange(phydev);
return 0;
}
static int amd_xgbe_phy_cur_mode(struct phy_device *phydev,
enum amd_xgbe_phy_mode *mode)
{
int ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL2);
if (ret < 0)
return ret;
if ((ret & MDIO_PCS_CTRL2_TYPE) == MDIO_PCS_CTRL2_10GBR)
*mode = AMD_XGBE_MODE_KR;
else
*mode = AMD_XGBE_MODE_KX;
return 0;
}
static bool amd_xgbe_phy_in_kr_mode(struct phy_device *phydev)
{
enum amd_xgbe_phy_mode mode;
if (amd_xgbe_phy_cur_mode(phydev, &mode))
return false;
return (mode == AMD_XGBE_MODE_KR);
}
static int amd_xgbe_phy_switch_mode(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
int ret;
if (amd_xgbe_phy_in_kr_mode(phydev)) {
if (priv->speed_set == AMD_XGBE_PHY_SPEEDSET_1000_10000)
ret = amd_xgbe_phy_gmii_mode(phydev);
else
ret = amd_xgbe_phy_gmii_2500_mode(phydev);
} else {
ret = amd_xgbe_phy_xgmii_mode(phydev);
}
return ret;
}
static int amd_xgbe_phy_set_mode(struct phy_device *phydev,
enum amd_xgbe_phy_mode mode)
{
enum amd_xgbe_phy_mode cur_mode;
int ret;
ret = amd_xgbe_phy_cur_mode(phydev, &cur_mode);
if (ret)
return ret;
if (mode != cur_mode)
ret = amd_xgbe_phy_switch_mode(phydev);
return ret;
}
static enum amd_xgbe_phy_an amd_xgbe_an_tx_training(struct phy_device *phydev,
enum amd_xgbe_phy_rx *state)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
int ad_reg, lp_reg, ret;
*state = AMD_XGBE_RX_COMPLETE;
if (!amd_xgbe_phy_in_kr_mode(phydev))
return AMD_XGBE_AN_EVENT;
ad_reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 2);
if (ad_reg < 0)
return AMD_XGBE_AN_ERROR;
lp_reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA + 2);
if (lp_reg < 0)
return AMD_XGBE_AN_ERROR;
ret = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_FEC_CTRL);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
if ((ad_reg & 0xc000) && (lp_reg & 0xc000))
ret |= 0x01;
else
ret &= ~0x01;
phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_FEC_CTRL, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
XSIR0_IOWRITE_BITS(priv, SIR0_KR_RT_1, RESET, 1);
ret |= 0x01;
phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_10GBR_PMD_CTRL, ret);
XSIR0_IOWRITE_BITS(priv, SIR0_KR_RT_1, RESET, 0);
return AMD_XGBE_AN_EVENT;
}
static enum amd_xgbe_phy_an amd_xgbe_an_tx_xnp(struct phy_device *phydev,
enum amd_xgbe_phy_rx *state)
{
u16 msg;
*state = AMD_XGBE_RX_XNP;
msg = XNP_MCF_NULL_MESSAGE;
msg |= XNP_MP_FORMATTED;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_XNP + 2, 0);
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_XNP + 1, 0);
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_XNP, msg);
return AMD_XGBE_AN_EVENT;
}
static enum amd_xgbe_phy_an amd_xgbe_an_rx_bpa(struct phy_device *phydev,
enum amd_xgbe_phy_rx *state)
{
unsigned int link_support;
int ret, ad_reg, lp_reg;
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA + 1);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
link_support = amd_xgbe_phy_in_kr_mode(phydev) ? 0x80 : 0x20;
if (!(ret & link_support))
return AMD_XGBE_AN_INCOMPAT_LINK;
ad_reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE);
if (ad_reg < 0)
return AMD_XGBE_AN_ERROR;
lp_reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA);
if (lp_reg < 0)
return AMD_XGBE_AN_ERROR;
return ((ad_reg & XNP_NP_EXCHANGE) || (lp_reg & XNP_NP_EXCHANGE)) ?
amd_xgbe_an_tx_xnp(phydev, state) :
amd_xgbe_an_tx_training(phydev, state);
}
static enum amd_xgbe_phy_an amd_xgbe_an_rx_xnp(struct phy_device *phydev,
enum amd_xgbe_phy_rx *state)
{
int ad_reg, lp_reg;
ad_reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE);
if (ad_reg < 0)
return AMD_XGBE_AN_ERROR;
lp_reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA);
if (lp_reg < 0)
return AMD_XGBE_AN_ERROR;
return ((ad_reg & XNP_NP_EXCHANGE) || (lp_reg & XNP_NP_EXCHANGE)) ?
amd_xgbe_an_tx_xnp(phydev, state) :
amd_xgbe_an_tx_training(phydev, state);
}
static enum amd_xgbe_phy_an amd_xgbe_an_start(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
int ret;
if (amd_xgbe_phy_in_kr_mode(phydev)) {
if (priv->kr_state != AMD_XGBE_RX_READY)
return AMD_XGBE_AN_NO_LINK;
priv->kr_state = AMD_XGBE_RX_BPA;
} else {
if (priv->kx_state != AMD_XGBE_RX_READY)
return AMD_XGBE_AN_NO_LINK;
priv->kx_state = AMD_XGBE_RX_BPA;
}
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 2);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
if (phydev->supported & SUPPORTED_10000baseR_FEC)
ret |= 0xc000;
else
ret &= ~0xc000;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 2, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 1);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
if (phydev->supported & SUPPORTED_10000baseKR_Full)
ret |= 0x80;
else
ret &= ~0x80;
if ((phydev->supported & SUPPORTED_1000baseKX_Full) ||
(phydev->supported & SUPPORTED_2500baseX_Full))
ret |= 0x20;
else
ret &= ~0x20;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 1, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
if (phydev->supported & SUPPORTED_Pause)
ret |= 0x400;
else
ret &= ~0x400;
if (phydev->supported & SUPPORTED_Asym_Pause)
ret |= 0x800;
else
ret &= ~0x800;
ret &= ~XNP_NP_EXCHANGE;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE, ret);
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_INT, 0);
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_KR_CTRL);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
ret |= MDIO_KR_CTRL_PDETECT;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_KR_CTRL, ret);
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
ret |= MDIO_AN_CTRL1_ENABLE;
ret |= MDIO_AN_CTRL1_RESTART;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1, ret);
return AMD_XGBE_AN_EVENT;
}
static enum amd_xgbe_phy_an amd_xgbe_an_event(struct phy_device *phydev)
{
enum amd_xgbe_phy_an new_state;
int ret;
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_INT);
if (ret < 0)
return AMD_XGBE_AN_ERROR;
new_state = AMD_XGBE_AN_EVENT;
if (ret & XGBE_AN_PG_RCV)
new_state = AMD_XGBE_AN_PAGE_RECEIVED;
else if (ret & XGBE_AN_INC_LINK)
new_state = AMD_XGBE_AN_INCOMPAT_LINK;
else if (ret & XGBE_AN_INT_CMPLT)
new_state = AMD_XGBE_AN_COMPLETE;
if (new_state != AMD_XGBE_AN_EVENT)
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_INT, 0);
return new_state;
}
static enum amd_xgbe_phy_an amd_xgbe_an_page_received(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
enum amd_xgbe_phy_rx *state;
int ret;
state = amd_xgbe_phy_in_kr_mode(phydev) ? &priv->kr_state
: &priv->kx_state;
switch (*state) {
case AMD_XGBE_RX_BPA:
ret = amd_xgbe_an_rx_bpa(phydev, state);
break;
case AMD_XGBE_RX_XNP:
ret = amd_xgbe_an_rx_xnp(phydev, state);
break;
default:
ret = AMD_XGBE_AN_ERROR;
}
return ret;
}
static enum amd_xgbe_phy_an amd_xgbe_an_incompat_link(struct phy_device *phydev)
{
int ret;
ret = amd_xgbe_phy_switch_mode(phydev);
if (ret)
return AMD_XGBE_AN_ERROR;
return AMD_XGBE_AN_START;
}
static void amd_xgbe_an_state_machine(struct work_struct *work)
{
struct amd_xgbe_phy_priv *priv = container_of(work,
struct amd_xgbe_phy_priv,
an_work);
struct phy_device *phydev = priv->phydev;
enum amd_xgbe_phy_an cur_state;
int sleep;
unsigned int an_supported = 0;
if (amd_xgbe_phy_set_mode(phydev, AMD_XGBE_MODE_KX))
priv->an_state = AMD_XGBE_AN_ERROR;
while (1) {
mutex_lock(&priv->an_mutex);
cur_state = priv->an_state;
switch (priv->an_state) {
case AMD_XGBE_AN_START:
an_supported = 0;
priv->parallel_detect = 0;
priv->an_state = amd_xgbe_an_start(phydev);
break;
case AMD_XGBE_AN_EVENT:
priv->an_state = amd_xgbe_an_event(phydev);
break;
case AMD_XGBE_AN_PAGE_RECEIVED:
priv->an_state = amd_xgbe_an_page_received(phydev);
an_supported++;
break;
case AMD_XGBE_AN_INCOMPAT_LINK:
priv->an_state = amd_xgbe_an_incompat_link(phydev);
break;
case AMD_XGBE_AN_COMPLETE:
priv->parallel_detect = an_supported ? 0 : 1;
netdev_info(phydev->attached_dev, "%s successful\n",
an_supported ? "Auto negotiation"
: "Parallel detection");
case AMD_XGBE_AN_NO_LINK:
case AMD_XGBE_AN_EXIT:
goto exit_unlock;
default:
priv->an_state = AMD_XGBE_AN_ERROR;
}
if (priv->an_state == AMD_XGBE_AN_ERROR) {
netdev_err(phydev->attached_dev,
"error during auto-negotiation, state=%u\n",
cur_state);
goto exit_unlock;
}
sleep = (priv->an_state == AMD_XGBE_AN_EVENT) ? 1 : 0;
mutex_unlock(&priv->an_mutex);
if (sleep)
usleep_range(20, 50);
}
exit_unlock:
priv->an_result = priv->an_state;
priv->an_state = AMD_XGBE_AN_READY;
mutex_unlock(&priv->an_mutex);
}
static int amd_xgbe_phy_soft_reset(struct phy_device *phydev)
{
int count, ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
return ret;
ret |= MDIO_CTRL1_RESET;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
count = 50;
do {
msleep(20);
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
return ret;
} while ((ret & MDIO_CTRL1_RESET) && --count);
if (ret & MDIO_CTRL1_RESET)
return -ETIMEDOUT;
return 0;
}
static int amd_xgbe_phy_config_init(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
phydev->supported = SUPPORTED_Autoneg;
phydev->supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
phydev->supported |= SUPPORTED_Backplane;
phydev->supported |= SUPPORTED_10000baseKR_Full |
SUPPORTED_10000baseR_FEC;
switch (priv->speed_set) {
case AMD_XGBE_PHY_SPEEDSET_1000_10000:
phydev->supported |= SUPPORTED_1000baseKX_Full;
break;
case AMD_XGBE_PHY_SPEEDSET_2500_10000:
phydev->supported |= SUPPORTED_2500baseX_Full;
break;
}
phydev->advertising = phydev->supported;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_INTMASK, 0);
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_INT, 0);
return 0;
}
static int amd_xgbe_phy_setup_forced(struct phy_device *phydev)
{
int ret;
ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1);
if (ret < 0)
return ret;
ret &= ~MDIO_AN_CTRL1_ENABLE;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1, ret);
switch (phydev->speed) {
case SPEED_10000:
ret = amd_xgbe_phy_xgmii_mode(phydev);
break;
case SPEED_2500:
ret = amd_xgbe_phy_gmii_2500_mode(phydev);
break;
case SPEED_1000:
ret = amd_xgbe_phy_gmii_mode(phydev);
break;
default:
ret = -EINVAL;
}
if (ret < 0)
return ret;
if (phydev->duplex != DUPLEX_FULL)
return -EINVAL;
phydev->pause = 0;
phydev->asym_pause = 0;
return 0;
}
static int amd_xgbe_phy_config_aneg(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
u32 mmd_mask = phydev->c45_ids.devices_in_package;
if (phydev->autoneg != AUTONEG_ENABLE)
return amd_xgbe_phy_setup_forced(phydev);
if (!(mmd_mask & MDIO_DEVS_AN))
return -EINVAL;
mutex_lock(&priv->an_mutex);
priv->an_result = AMD_XGBE_AN_READY;
priv->an_state = AMD_XGBE_AN_START;
priv->kr_state = AMD_XGBE_RX_READY;
priv->kx_state = AMD_XGBE_RX_READY;
mutex_unlock(&priv->an_mutex);
queue_work(priv->an_workqueue, &priv->an_work);
return 0;
}
static int amd_xgbe_phy_aneg_done(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
enum amd_xgbe_phy_an state;
mutex_lock(&priv->an_mutex);
state = priv->an_result;
mutex_unlock(&priv->an_mutex);
return (state == AMD_XGBE_AN_COMPLETE);
}
static int amd_xgbe_phy_update_link(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
enum amd_xgbe_phy_an state;
unsigned int check_again, autoneg;
int ret;
mutex_lock(&priv->an_mutex);
state = priv->an_state;
mutex_unlock(&priv->an_mutex);
if (state != AMD_XGBE_AN_READY) {
phydev->link = 1;
return 0;
}
check_again = (phydev->autoneg == AUTONEG_ENABLE) ? 1 : 0;
again:
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_STAT1);
if (ret < 0)
return ret;
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_STAT1);
if (ret < 0)
return ret;
phydev->link = (ret & MDIO_STAT1_LSTATUS) ? 1 : 0;
if (!phydev->link) {
if (check_again) {
ret = amd_xgbe_phy_switch_mode(phydev);
if (ret < 0)
return ret;
check_again = 0;
goto again;
}
}
autoneg = (phydev->link && !priv->link) ? 1 : 0;
priv->link = phydev->link;
if (autoneg) {
ret = amd_xgbe_phy_config_aneg(phydev);
if (ret < 0)
return ret;
}
return 0;
}
static int amd_xgbe_phy_read_status(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
u32 mmd_mask = phydev->c45_ids.devices_in_package;
int ret, ad_ret, lp_ret;
ret = amd_xgbe_phy_update_link(phydev);
if (ret)
return ret;
if ((phydev->autoneg == AUTONEG_ENABLE) &&
!priv->parallel_detect) {
if (!(mmd_mask & MDIO_DEVS_AN))
return -EINVAL;
if (!amd_xgbe_phy_aneg_done(phydev))
return 0;
ad_ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE);
if (ad_ret < 0)
return ad_ret;
lp_ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA);
if (lp_ret < 0)
return lp_ret;
ad_ret &= lp_ret;
phydev->pause = (ad_ret & 0x400) ? 1 : 0;
phydev->asym_pause = (ad_ret & 0x800) ? 1 : 0;
ad_ret = phy_read_mmd(phydev, MDIO_MMD_AN,
MDIO_AN_ADVERTISE + 1);
if (ad_ret < 0)
return ad_ret;
lp_ret = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA + 1);
if (lp_ret < 0)
return lp_ret;
ad_ret &= lp_ret;
if (ad_ret & 0x80) {
phydev->speed = SPEED_10000;
ret = amd_xgbe_phy_set_mode(phydev, AMD_XGBE_MODE_KR);
if (ret)
return ret;
} else {
switch (priv->speed_set) {
case AMD_XGBE_PHY_SPEEDSET_1000_10000:
phydev->speed = SPEED_1000;
break;
case AMD_XGBE_PHY_SPEEDSET_2500_10000:
phydev->speed = SPEED_2500;
break;
}
ret = amd_xgbe_phy_set_mode(phydev, AMD_XGBE_MODE_KX);
if (ret)
return ret;
}
phydev->duplex = DUPLEX_FULL;
} else {
if (amd_xgbe_phy_in_kr_mode(phydev)) {
phydev->speed = SPEED_10000;
} else {
switch (priv->speed_set) {
case AMD_XGBE_PHY_SPEEDSET_1000_10000:
phydev->speed = SPEED_1000;
break;
case AMD_XGBE_PHY_SPEEDSET_2500_10000:
phydev->speed = SPEED_2500;
break;
}
}
phydev->duplex = DUPLEX_FULL;
phydev->pause = 0;
phydev->asym_pause = 0;
}
return 0;
}
static int amd_xgbe_phy_suspend(struct phy_device *phydev)
{
int ret;
mutex_lock(&phydev->lock);
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
goto unlock;
ret |= MDIO_CTRL1_LPOWER;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
ret = 0;
unlock:
mutex_unlock(&phydev->lock);
return ret;
}
static int amd_xgbe_phy_resume(struct phy_device *phydev)
{
int ret;
mutex_lock(&phydev->lock);
ret = phy_read_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1);
if (ret < 0)
goto unlock;
ret &= ~MDIO_CTRL1_LPOWER;
phy_write_mmd(phydev, MDIO_MMD_PCS, MDIO_CTRL1, ret);
ret = 0;
unlock:
mutex_unlock(&phydev->lock);
return ret;
}
static int amd_xgbe_phy_probe(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv;
struct platform_device *pdev;
struct device *dev;
char *wq_name;
const __be32 *property;
unsigned int speed_set;
int ret;
if (!phydev->dev.of_node)
return -EINVAL;
pdev = of_find_device_by_node(phydev->dev.of_node);
if (!pdev)
return -EINVAL;
dev = &pdev->dev;
wq_name = kasprintf(GFP_KERNEL, "%s-amd-xgbe-phy", phydev->bus->name);
if (!wq_name) {
ret = -ENOMEM;
goto err_pdev;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto err_name;
}
priv->pdev = pdev;
priv->dev = dev;
priv->phydev = phydev;
priv->rxtx_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->rxtx_regs = devm_ioremap_resource(dev, priv->rxtx_res);
if (IS_ERR(priv->rxtx_regs)) {
dev_err(dev, "rxtx ioremap failed\n");
ret = PTR_ERR(priv->rxtx_regs);
goto err_priv;
}
priv->sir0_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
priv->sir0_regs = devm_ioremap_resource(dev, priv->sir0_res);
if (IS_ERR(priv->sir0_regs)) {
dev_err(dev, "sir0 ioremap failed\n");
ret = PTR_ERR(priv->sir0_regs);
goto err_rxtx;
}
priv->sir1_res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
priv->sir1_regs = devm_ioremap_resource(dev, priv->sir1_res);
if (IS_ERR(priv->sir1_regs)) {
dev_err(dev, "sir1 ioremap failed\n");
ret = PTR_ERR(priv->sir1_regs);
goto err_sir0;
}
speed_set = 0;
property = of_get_property(dev->of_node, XGBE_PHY_SPEEDSET_PROPERTY,
NULL);
if (property)
speed_set = be32_to_cpu(*property);
switch (speed_set) {
case 0:
priv->speed_set = AMD_XGBE_PHY_SPEEDSET_1000_10000;
break;
case 1:
priv->speed_set = AMD_XGBE_PHY_SPEEDSET_2500_10000;
break;
default:
dev_err(dev, "invalid amd,speed-set property\n");
ret = -EINVAL;
goto err_sir1;
}
priv->link = 1;
mutex_init(&priv->an_mutex);
INIT_WORK(&priv->an_work, amd_xgbe_an_state_machine);
priv->an_workqueue = create_singlethread_workqueue(wq_name);
if (!priv->an_workqueue) {
ret = -ENOMEM;
goto err_sir1;
}
phydev->priv = priv;
kfree(wq_name);
of_dev_put(pdev);
return 0;
err_sir1:
devm_iounmap(dev, priv->sir1_regs);
devm_release_mem_region(dev, priv->sir1_res->start,
resource_size(priv->sir1_res));
err_sir0:
devm_iounmap(dev, priv->sir0_regs);
devm_release_mem_region(dev, priv->sir0_res->start,
resource_size(priv->sir0_res));
err_rxtx:
devm_iounmap(dev, priv->rxtx_regs);
devm_release_mem_region(dev, priv->rxtx_res->start,
resource_size(priv->rxtx_res));
err_priv:
devm_kfree(dev, priv);
err_name:
kfree(wq_name);
err_pdev:
of_dev_put(pdev);
return ret;
}
static void amd_xgbe_phy_remove(struct phy_device *phydev)
{
struct amd_xgbe_phy_priv *priv = phydev->priv;
struct device *dev = priv->dev;
mutex_lock(&priv->an_mutex);
priv->an_state = AMD_XGBE_AN_EXIT;
mutex_unlock(&priv->an_mutex);
flush_workqueue(priv->an_workqueue);
destroy_workqueue(priv->an_workqueue);
devm_iounmap(dev, priv->sir1_regs);
devm_release_mem_region(dev, priv->sir1_res->start,
resource_size(priv->sir1_res));
devm_iounmap(dev, priv->sir0_regs);
devm_release_mem_region(dev, priv->sir0_res->start,
resource_size(priv->sir0_res));
devm_iounmap(dev, priv->rxtx_regs);
devm_release_mem_region(dev, priv->rxtx_res->start,
resource_size(priv->rxtx_res));
devm_kfree(dev, priv);
}
static int amd_xgbe_match_phy_device(struct phy_device *phydev)
{
return phydev->c45_ids.device_ids[MDIO_MMD_PCS] == XGBE_PHY_ID;
}
static int __init amd_xgbe_phy_init(void)
{
return phy_drivers_register(amd_xgbe_phy_driver,
ARRAY_SIZE(amd_xgbe_phy_driver));
}
static void __exit amd_xgbe_phy_exit(void)
{
phy_drivers_unregister(amd_xgbe_phy_driver,
ARRAY_SIZE(amd_xgbe_phy_driver));
}
