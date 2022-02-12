static void write_sa2400(struct ieee80211_hw *dev, u8 addr, u32 data)
{
struct rtl8180_priv *priv = dev->priv;
u32 phy_config;
phy_config = 0xb0000000;
phy_config |= ((u32)(addr & 0xf)) << 24;
phy_config |= data & 0xffffff;
rtl818x_iowrite32(priv,
(__le32 __iomem *) &priv->map->RFPinsOutput, phy_config);
msleep(3);
}
static void sa2400_write_phy_antenna(struct ieee80211_hw *dev, short chan)
{
struct rtl8180_priv *priv = dev->priv;
u8 ant = SA2400_ANTENNA;
if (priv->rfparam & RF_PARAM_ANTBDEFAULT)
ant |= BB_ANTENNA_B;
if (chan == 14)
ant |= BB_ANTATTEN_CHAN14;
rtl8180_write_phy(dev, 0x10, ant);
}
static u8 sa2400_rf_calc_rssi(u8 agc, u8 sq)
{
if (sq == 0x80)
return 1;
if (sq > 78)
return 32;
return 65 * sa2400_rf_rssi_map[sq] / 100;
}
static void sa2400_rf_set_channel(struct ieee80211_hw *dev,
struct ieee80211_conf *conf)
{
struct rtl8180_priv *priv = dev->priv;
int channel = ieee80211_frequency_to_channel(conf->channel->center_freq);
u32 txpw = priv->channels[channel - 1].hw_value & 0xFF;
u32 chan = sa2400_chan[channel - 1];
write_sa2400(dev, 7, txpw);
sa2400_write_phy_antenna(dev, channel);
write_sa2400(dev, 0, chan);
write_sa2400(dev, 1, 0xbb50);
write_sa2400(dev, 2, 0x80);
write_sa2400(dev, 3, 0);
}
static void sa2400_rf_stop(struct ieee80211_hw *dev)
{
write_sa2400(dev, 4, 0);
}
static void sa2400_rf_init(struct ieee80211_hw *dev)
{
struct rtl8180_priv *priv = dev->priv;
u32 anaparam, txconf;
u8 firdac;
int analogphy = priv->rfparam & RF_PARAM_ANALOGPHY;
anaparam = priv->anaparam;
anaparam &= ~(1 << ANAPARAM_TXDACOFF_SHIFT);
anaparam &= ~ANAPARAM_PWR1_MASK;
anaparam &= ~ANAPARAM_PWR0_MASK;
if (analogphy) {
anaparam |= SA2400_ANA_ANAPARAM_PWR1_ON << ANAPARAM_PWR1_SHIFT;
firdac = 0;
} else {
anaparam |= (SA2400_DIG_ANAPARAM_PWR1_ON << ANAPARAM_PWR1_SHIFT);
anaparam |= (SA2400_ANAPARAM_PWR0_ON << ANAPARAM_PWR0_SHIFT);
firdac = 1 << SA2400_REG4_FIRDAC_SHIFT;
}
rtl8180_set_anaparam(priv, anaparam);
write_sa2400(dev, 0, sa2400_chan[0]);
write_sa2400(dev, 1, 0xbb50);
write_sa2400(dev, 2, 0x80);
write_sa2400(dev, 3, 0);
write_sa2400(dev, 4, 0x19340 | firdac);
write_sa2400(dev, 5, 0x1dfb | (SA2400_MAX_SENS - 54) << 15);
write_sa2400(dev, 4, 0x19348 | firdac);
if (!analogphy)
write_sa2400(dev, 4, 0x1938c);
write_sa2400(dev, 4, 0x19340 | firdac);
write_sa2400(dev, 0, sa2400_chan[0]);
write_sa2400(dev, 1, 0xbb50);
write_sa2400(dev, 2, 0x80);
write_sa2400(dev, 3, 0);
write_sa2400(dev, 4, 0x19344 | firdac);
write_sa2400(dev, 6, 0x13ff | (1 << 23));
write_sa2400(dev, 8, 0);
if (analogphy) {
rtl8180_set_anaparam(priv, anaparam |
(1 << ANAPARAM_TXDACOFF_SHIFT));
txconf = rtl818x_ioread32(priv, &priv->map->TX_CONF);
rtl818x_iowrite32(priv, &priv->map->TX_CONF,
txconf | RTL818X_TX_CONF_LOOPBACK_CONT);
write_sa2400(dev, 4, 0x19341);
write_sa2400(dev, 4, 0x19345);
rtl818x_iowrite32(priv, &priv->map->TX_CONF, txconf);
rtl8180_set_anaparam(priv, anaparam);
}
write_sa2400(dev, 4, 0x19341 | firdac);
rtl8180_write_phy(dev, 0, 0x98);
rtl8180_write_phy(dev, 3, 0x38);
rtl8180_write_phy(dev, 4, 0xe0);
rtl8180_write_phy(dev, 5, 0x90);
rtl8180_write_phy(dev, 6, 0x1a);
rtl8180_write_phy(dev, 7, 0x64);
sa2400_write_phy_antenna(dev, 1);
rtl8180_write_phy(dev, 0x11, 0x80);
if (rtl818x_ioread8(priv, &priv->map->CONFIG2) &
RTL818X_CONFIG2_ANTENNA_DIV)
rtl8180_write_phy(dev, 0x12, 0xc7);
else
rtl8180_write_phy(dev, 0x12, 0x47);
rtl8180_write_phy(dev, 0x13, 0x90 | priv->csthreshold);
rtl8180_write_phy(dev, 0x19, 0x0);
rtl8180_write_phy(dev, 0x1a, 0xa0);
}
