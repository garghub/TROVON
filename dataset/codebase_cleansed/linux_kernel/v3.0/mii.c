static u32 mii_get_an(struct mii_if_info *mii, u16 addr)
{
u32 result = 0;
int advert;
advert = mii->mdio_read(mii->dev, mii->phy_id, addr);
if (advert & LPA_LPACK)
result |= ADVERTISED_Autoneg;
if (advert & ADVERTISE_10HALF)
result |= ADVERTISED_10baseT_Half;
if (advert & ADVERTISE_10FULL)
result |= ADVERTISED_10baseT_Full;
if (advert & ADVERTISE_100HALF)
result |= ADVERTISED_100baseT_Half;
if (advert & ADVERTISE_100FULL)
result |= ADVERTISED_100baseT_Full;
if (advert & ADVERTISE_PAUSE_CAP)
result |= ADVERTISED_Pause;
if (advert & ADVERTISE_PAUSE_ASYM)
result |= ADVERTISED_Asym_Pause;
return result;
}
int mii_ethtool_gset(struct mii_if_info *mii, struct ethtool_cmd *ecmd)
{
struct net_device *dev = mii->dev;
u16 bmcr, bmsr, ctrl1000 = 0, stat1000 = 0;
u32 nego;
ecmd->supported =
(SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg | SUPPORTED_TP | SUPPORTED_MII);
if (mii->supports_gmii)
ecmd->supported |= SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full;
ecmd->port = PORT_MII;
ecmd->transceiver = XCVR_INTERNAL;
ecmd->phy_address = mii->phy_id;
ecmd->mdio_support = MDIO_SUPPORTS_C22;
ecmd->advertising = ADVERTISED_TP | ADVERTISED_MII;
bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
bmsr = mii->mdio_read(dev, mii->phy_id, MII_BMSR);
if (mii->supports_gmii) {
ctrl1000 = mii->mdio_read(dev, mii->phy_id, MII_CTRL1000);
stat1000 = mii->mdio_read(dev, mii->phy_id, MII_STAT1000);
}
if (bmcr & BMCR_ANENABLE) {
ecmd->advertising |= ADVERTISED_Autoneg;
ecmd->autoneg = AUTONEG_ENABLE;
ecmd->advertising |= mii_get_an(mii, MII_ADVERTISE);
if (ctrl1000 & ADVERTISE_1000HALF)
ecmd->advertising |= ADVERTISED_1000baseT_Half;
if (ctrl1000 & ADVERTISE_1000FULL)
ecmd->advertising |= ADVERTISED_1000baseT_Full;
if (bmsr & BMSR_ANEGCOMPLETE) {
ecmd->lp_advertising = mii_get_an(mii, MII_LPA);
if (stat1000 & LPA_1000HALF)
ecmd->lp_advertising |=
ADVERTISED_1000baseT_Half;
if (stat1000 & LPA_1000FULL)
ecmd->lp_advertising |=
ADVERTISED_1000baseT_Full;
} else {
ecmd->lp_advertising = 0;
}
nego = ecmd->advertising & ecmd->lp_advertising;
if (nego & (ADVERTISED_1000baseT_Full |
ADVERTISED_1000baseT_Half)) {
ethtool_cmd_speed_set(ecmd, SPEED_1000);
ecmd->duplex = !!(nego & ADVERTISED_1000baseT_Full);
} else if (nego & (ADVERTISED_100baseT_Full |
ADVERTISED_100baseT_Half)) {
ethtool_cmd_speed_set(ecmd, SPEED_100);
ecmd->duplex = !!(nego & ADVERTISED_100baseT_Full);
} else {
ethtool_cmd_speed_set(ecmd, SPEED_10);
ecmd->duplex = !!(nego & ADVERTISED_10baseT_Full);
}
} else {
ecmd->autoneg = AUTONEG_DISABLE;
ethtool_cmd_speed_set(ecmd,
((bmcr & BMCR_SPEED1000 &&
(bmcr & BMCR_SPEED100) == 0) ?
SPEED_1000 :
((bmcr & BMCR_SPEED100) ?
SPEED_100 : SPEED_10)));
ecmd->duplex = (bmcr & BMCR_FULLDPLX) ? DUPLEX_FULL : DUPLEX_HALF;
}
mii->full_duplex = ecmd->duplex;
return 0;
}
int mii_ethtool_sset(struct mii_if_info *mii, struct ethtool_cmd *ecmd)
{
struct net_device *dev = mii->dev;
u32 speed = ethtool_cmd_speed(ecmd);
if (speed != SPEED_10 &&
speed != SPEED_100 &&
speed != SPEED_1000)
return -EINVAL;
if (ecmd->duplex != DUPLEX_HALF && ecmd->duplex != DUPLEX_FULL)
return -EINVAL;
if (ecmd->port != PORT_MII)
return -EINVAL;
if (ecmd->transceiver != XCVR_INTERNAL)
return -EINVAL;
if (ecmd->phy_address != mii->phy_id)
return -EINVAL;
if (ecmd->autoneg != AUTONEG_DISABLE && ecmd->autoneg != AUTONEG_ENABLE)
return -EINVAL;
if ((speed == SPEED_1000) && (!mii->supports_gmii))
return -EINVAL;
if (ecmd->autoneg == AUTONEG_ENABLE) {
u32 bmcr, advert, tmp;
u32 advert2 = 0, tmp2 = 0;
if ((ecmd->advertising & (ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full |
ADVERTISED_1000baseT_Half |
ADVERTISED_1000baseT_Full)) == 0)
return -EINVAL;
advert = mii->mdio_read(dev, mii->phy_id, MII_ADVERTISE);
tmp = advert & ~(ADVERTISE_ALL | ADVERTISE_100BASE4);
if (mii->supports_gmii) {
advert2 = mii->mdio_read(dev, mii->phy_id, MII_CTRL1000);
tmp2 = advert2 & ~(ADVERTISE_1000HALF | ADVERTISE_1000FULL);
}
if (ecmd->advertising & ADVERTISED_10baseT_Half)
tmp |= ADVERTISE_10HALF;
if (ecmd->advertising & ADVERTISED_10baseT_Full)
tmp |= ADVERTISE_10FULL;
if (ecmd->advertising & ADVERTISED_100baseT_Half)
tmp |= ADVERTISE_100HALF;
if (ecmd->advertising & ADVERTISED_100baseT_Full)
tmp |= ADVERTISE_100FULL;
if (mii->supports_gmii) {
if (ecmd->advertising & ADVERTISED_1000baseT_Half)
tmp2 |= ADVERTISE_1000HALF;
if (ecmd->advertising & ADVERTISED_1000baseT_Full)
tmp2 |= ADVERTISE_1000FULL;
}
if (advert != tmp) {
mii->mdio_write(dev, mii->phy_id, MII_ADVERTISE, tmp);
mii->advertising = tmp;
}
if ((mii->supports_gmii) && (advert2 != tmp2))
mii->mdio_write(dev, mii->phy_id, MII_CTRL1000, tmp2);
bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
mii->mdio_write(dev, mii->phy_id, MII_BMCR, bmcr);
mii->force_media = 0;
} else {
u32 bmcr, tmp;
bmcr = mii->mdio_read(dev, mii->phy_id, MII_BMCR);
tmp = bmcr & ~(BMCR_ANENABLE | BMCR_SPEED100 |
BMCR_SPEED1000 | BMCR_FULLDPLX);
if (speed == SPEED_1000)
tmp |= BMCR_SPEED1000;
else if (speed == SPEED_100)
tmp |= BMCR_SPEED100;
if (ecmd->duplex == DUPLEX_FULL) {
tmp |= BMCR_FULLDPLX;
mii->full_duplex = 1;
} else
mii->full_duplex = 0;
if (bmcr != tmp)
mii->mdio_write(dev, mii->phy_id, MII_BMCR, tmp);
mii->force_media = 1;
}
return 0;
}
int mii_check_gmii_support(struct mii_if_info *mii)
{
int reg;
reg = mii->mdio_read(mii->dev, mii->phy_id, MII_BMSR);
if (reg & BMSR_ESTATEN) {
reg = mii->mdio_read(mii->dev, mii->phy_id, MII_ESTATUS);
if (reg & (ESTATUS_1000_TFULL | ESTATUS_1000_THALF))
return 1;
}
return 0;
}
int mii_link_ok (struct mii_if_info *mii)
{
mii->mdio_read(mii->dev, mii->phy_id, MII_BMSR);
if (mii->mdio_read(mii->dev, mii->phy_id, MII_BMSR) & BMSR_LSTATUS)
return 1;
return 0;
}
int mii_nway_restart (struct mii_if_info *mii)
{
int bmcr;
int r = -EINVAL;
bmcr = mii->mdio_read(mii->dev, mii->phy_id, MII_BMCR);
if (bmcr & BMCR_ANENABLE) {
bmcr |= BMCR_ANRESTART;
mii->mdio_write(mii->dev, mii->phy_id, MII_BMCR, bmcr);
r = 0;
}
return r;
}
void mii_check_link (struct mii_if_info *mii)
{
int cur_link = mii_link_ok(mii);
int prev_link = netif_carrier_ok(mii->dev);
if (cur_link && !prev_link)
netif_carrier_on(mii->dev);
else if (prev_link && !cur_link)
netif_carrier_off(mii->dev);
}
unsigned int mii_check_media (struct mii_if_info *mii,
unsigned int ok_to_print,
unsigned int init_media)
{
unsigned int old_carrier, new_carrier;
int advertise, lpa, media, duplex;
int lpa2 = 0;
if (mii->force_media)
return 0;
old_carrier = netif_carrier_ok(mii->dev) ? 1 : 0;
new_carrier = (unsigned int) mii_link_ok(mii);
if ((!init_media) && (old_carrier == new_carrier))
return 0;
if (!new_carrier) {
netif_carrier_off(mii->dev);
if (ok_to_print)
netdev_info(mii->dev, "link down\n");
return 0;
}
netif_carrier_on(mii->dev);
if ((!init_media) && (mii->advertising))
advertise = mii->advertising;
else {
advertise = mii->mdio_read(mii->dev, mii->phy_id, MII_ADVERTISE);
mii->advertising = advertise;
}
lpa = mii->mdio_read(mii->dev, mii->phy_id, MII_LPA);
if (mii->supports_gmii)
lpa2 = mii->mdio_read(mii->dev, mii->phy_id, MII_STAT1000);
media = mii_nway_result(lpa & advertise);
duplex = (media & ADVERTISE_FULL) ? 1 : 0;
if (lpa2 & LPA_1000FULL)
duplex = 1;
if (ok_to_print)
netdev_info(mii->dev, "link up, %uMbps, %s-duplex, lpa 0x%04X\n",
lpa2 & (LPA_1000FULL | LPA_1000HALF) ? 1000 :
media & (ADVERTISE_100FULL | ADVERTISE_100HALF) ?
100 : 10,
duplex ? "full" : "half",
lpa);
if ((init_media) || (mii->full_duplex != duplex)) {
mii->full_duplex = duplex;
return 1;
}
return 0;
}
int generic_mii_ioctl(struct mii_if_info *mii_if,
struct mii_ioctl_data *mii_data, int cmd,
unsigned int *duplex_chg_out)
{
int rc = 0;
unsigned int duplex_changed = 0;
if (duplex_chg_out)
*duplex_chg_out = 0;
mii_data->phy_id &= mii_if->phy_id_mask;
mii_data->reg_num &= mii_if->reg_num_mask;
switch(cmd) {
case SIOCGMIIPHY:
mii_data->phy_id = mii_if->phy_id;
case SIOCGMIIREG:
mii_data->val_out =
mii_if->mdio_read(mii_if->dev, mii_data->phy_id,
mii_data->reg_num);
break;
case SIOCSMIIREG: {
u16 val = mii_data->val_in;
if (mii_data->phy_id == mii_if->phy_id) {
switch(mii_data->reg_num) {
case MII_BMCR: {
unsigned int new_duplex = 0;
if (val & (BMCR_RESET|BMCR_ANENABLE))
mii_if->force_media = 0;
else
mii_if->force_media = 1;
if (mii_if->force_media &&
(val & BMCR_FULLDPLX))
new_duplex = 1;
if (mii_if->full_duplex != new_duplex) {
duplex_changed = 1;
mii_if->full_duplex = new_duplex;
}
break;
}
case MII_ADVERTISE:
mii_if->advertising = val;
break;
default:
break;
}
}
mii_if->mdio_write(mii_if->dev, mii_data->phy_id,
mii_data->reg_num, val);
break;
}
default:
rc = -EOPNOTSUPP;
break;
}
if ((rc == 0) && (duplex_chg_out) && (duplex_changed))
*duplex_chg_out = 1;
return rc;
}
