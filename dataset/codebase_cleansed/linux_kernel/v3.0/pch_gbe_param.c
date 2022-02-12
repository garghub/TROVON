static int pch_gbe_validate_option(int *value,
const struct pch_gbe_option *opt,
struct pch_gbe_adapter *adapter)
{
if (*value == OPTION_UNSET) {
*value = opt->def;
return 0;
}
switch (opt->type) {
case enable_option:
switch (*value) {
case OPTION_ENABLED:
pr_debug("%s Enabled\n", opt->name);
return 0;
case OPTION_DISABLED:
pr_debug("%s Disabled\n", opt->name);
return 0;
}
break;
case range_option:
if (*value >= opt->arg.r.min && *value <= opt->arg.r.max) {
pr_debug("%s set to %i\n", opt->name, *value);
return 0;
}
break;
case list_option: {
int i;
const struct pch_gbe_opt_list *ent;
for (i = 0; i < opt->arg.l.nr; i++) {
ent = &opt->arg.l.p[i];
if (*value == ent->i) {
if (ent->str[0] != '\0')
pr_debug("%s\n", ent->str);
return 0;
}
}
}
break;
default:
BUG();
}
pr_debug("Invalid %s value specified (%i) %s\n",
opt->name, *value, opt->err);
*value = opt->def;
return -1;
}
static void pch_gbe_check_copper_options(struct pch_gbe_adapter *adapter)
{
struct pch_gbe_hw *hw = &adapter->hw;
int speed, dplx;
{
static const struct pch_gbe_option opt = {
.type = list_option,
.name = "Speed",
.err = "parameter ignored",
.def = 0,
.arg = { .l = { .nr = (int)ARRAY_SIZE(speed_list),
.p = speed_list } }
};
speed = Speed;
pch_gbe_validate_option(&speed, &opt, adapter);
}
{
static const struct pch_gbe_option opt = {
.type = list_option,
.name = "Duplex",
.err = "parameter ignored",
.def = 0,
.arg = { .l = { .nr = (int)ARRAY_SIZE(dplx_list),
.p = dplx_list } }
};
dplx = Duplex;
pch_gbe_validate_option(&dplx, &opt, adapter);
}
{
static const struct pch_gbe_option opt = {
.type = list_option,
.name = "AutoNeg",
.err = "parameter ignored",
.def = PCH_AUTONEG_ADVERTISE_DEFAULT,
.arg = { .l = { .nr = (int)ARRAY_SIZE(an_list),
.p = an_list} }
};
if (speed || dplx) {
pr_debug("AutoNeg specified along with Speed or Duplex, AutoNeg parameter ignored\n");
hw->phy.autoneg_advertised = opt.def;
} else {
hw->phy.autoneg_advertised = AutoNeg;
pch_gbe_validate_option(
(int *)(&hw->phy.autoneg_advertised),
&opt, adapter);
}
}
switch (speed + dplx) {
case 0:
hw->mac.autoneg = hw->mac.fc_autoneg = 1;
if ((speed || dplx))
pr_debug("Speed and duplex autonegotiation enabled\n");
hw->mac.link_speed = SPEED_10;
hw->mac.link_duplex = DUPLEX_HALF;
break;
case HALF_DUPLEX:
pr_debug("Half Duplex specified without Speed\n");
pr_debug("Using Autonegotiation at Half Duplex only\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 1;
hw->phy.autoneg_advertised = PHY_ADVERTISE_10_HALF |
PHY_ADVERTISE_100_HALF;
hw->mac.link_speed = SPEED_10;
hw->mac.link_duplex = DUPLEX_HALF;
break;
case FULL_DUPLEX:
pr_debug("Full Duplex specified without Speed\n");
pr_debug("Using Autonegotiation at Full Duplex only\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 1;
hw->phy.autoneg_advertised = PHY_ADVERTISE_10_FULL |
PHY_ADVERTISE_100_FULL |
PHY_ADVERTISE_1000_FULL;
hw->mac.link_speed = SPEED_10;
hw->mac.link_duplex = DUPLEX_FULL;
break;
case SPEED_10:
pr_debug("10 Mbps Speed specified without Duplex\n");
pr_debug("Using Autonegotiation at 10 Mbps only\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 1;
hw->phy.autoneg_advertised = PHY_ADVERTISE_10_HALF |
PHY_ADVERTISE_10_FULL;
hw->mac.link_speed = SPEED_10;
hw->mac.link_duplex = DUPLEX_HALF;
break;
case SPEED_10 + HALF_DUPLEX:
pr_debug("Forcing to 10 Mbps Half Duplex\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 0;
hw->phy.autoneg_advertised = 0;
hw->mac.link_speed = SPEED_10;
hw->mac.link_duplex = DUPLEX_HALF;
break;
case SPEED_10 + FULL_DUPLEX:
pr_debug("Forcing to 10 Mbps Full Duplex\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 0;
hw->phy.autoneg_advertised = 0;
hw->mac.link_speed = SPEED_10;
hw->mac.link_duplex = DUPLEX_FULL;
break;
case SPEED_100:
pr_debug("100 Mbps Speed specified without Duplex\n");
pr_debug("Using Autonegotiation at 100 Mbps only\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 1;
hw->phy.autoneg_advertised = PHY_ADVERTISE_100_HALF |
PHY_ADVERTISE_100_FULL;
hw->mac.link_speed = SPEED_100;
hw->mac.link_duplex = DUPLEX_HALF;
break;
case SPEED_100 + HALF_DUPLEX:
pr_debug("Forcing to 100 Mbps Half Duplex\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 0;
hw->phy.autoneg_advertised = 0;
hw->mac.link_speed = SPEED_100;
hw->mac.link_duplex = DUPLEX_HALF;
break;
case SPEED_100 + FULL_DUPLEX:
pr_debug("Forcing to 100 Mbps Full Duplex\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 0;
hw->phy.autoneg_advertised = 0;
hw->mac.link_speed = SPEED_100;
hw->mac.link_duplex = DUPLEX_FULL;
break;
case SPEED_1000:
pr_debug("1000 Mbps Speed specified without Duplex\n");
goto full_duplex_only;
case SPEED_1000 + HALF_DUPLEX:
pr_debug("Half Duplex is not supported at 1000 Mbps\n");
case SPEED_1000 + FULL_DUPLEX:
full_duplex_only:
pr_debug("Using Autonegotiation at 1000 Mbps Full Duplex only\n");
hw->mac.autoneg = hw->mac.fc_autoneg = 1;
hw->phy.autoneg_advertised = PHY_ADVERTISE_1000_FULL;
hw->mac.link_speed = SPEED_1000;
hw->mac.link_duplex = DUPLEX_FULL;
break;
default:
BUG();
}
}
void pch_gbe_check_options(struct pch_gbe_adapter *adapter)
{
struct pch_gbe_hw *hw = &adapter->hw;
struct net_device *dev = adapter->netdev;
int val;
{
static const struct pch_gbe_option opt = {
.type = range_option,
.name = "Transmit Descriptors",
.err = "using default of "
__MODULE_STRING(PCH_GBE_DEFAULT_TXD),
.def = PCH_GBE_DEFAULT_TXD,
.arg = { .r = { .min = PCH_GBE_MIN_TXD,
.max = PCH_GBE_MAX_TXD } }
};
struct pch_gbe_tx_ring *tx_ring = adapter->tx_ring;
tx_ring->count = TxDescriptors;
pch_gbe_validate_option(&tx_ring->count, &opt, adapter);
tx_ring->count = roundup(tx_ring->count,
PCH_GBE_TX_DESC_MULTIPLE);
}
{
static const struct pch_gbe_option opt = {
.type = range_option,
.name = "Receive Descriptors",
.err = "using default of "
__MODULE_STRING(PCH_GBE_DEFAULT_RXD),
.def = PCH_GBE_DEFAULT_RXD,
.arg = { .r = { .min = PCH_GBE_MIN_RXD,
.max = PCH_GBE_MAX_RXD } }
};
struct pch_gbe_rx_ring *rx_ring = adapter->rx_ring;
rx_ring->count = RxDescriptors;
pch_gbe_validate_option(&rx_ring->count, &opt, adapter);
rx_ring->count = roundup(rx_ring->count,
PCH_GBE_RX_DESC_MULTIPLE);
}
{
static const struct pch_gbe_option opt = {
.type = enable_option,
.name = "Checksum Offload",
.err = "defaulting to Enabled",
.def = PCH_GBE_DEFAULT_RX_CSUM
};
val = XsumRX;
pch_gbe_validate_option(&val, &opt, adapter);
if (!val)
dev->features &= ~NETIF_F_RXCSUM;
}
{
static const struct pch_gbe_option opt = {
.type = enable_option,
.name = "Checksum Offload",
.err = "defaulting to Enabled",
.def = PCH_GBE_DEFAULT_TX_CSUM
};
val = XsumTX;
pch_gbe_validate_option(&val, &opt, adapter);
if (!val)
dev->features &= ~NETIF_F_ALL_CSUM;
}
{
static const struct pch_gbe_option opt = {
.type = list_option,
.name = "Flow Control",
.err = "reading default settings from EEPROM",
.def = PCH_GBE_FC_DEFAULT,
.arg = { .l = { .nr = (int)ARRAY_SIZE(fc_list),
.p = fc_list } }
};
hw->mac.fc = FlowControl;
pch_gbe_validate_option((int *)(&hw->mac.fc),
&opt, adapter);
}
pch_gbe_check_copper_options(adapter);
}
