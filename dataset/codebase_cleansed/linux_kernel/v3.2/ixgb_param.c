static int __devinit
ixgb_validate_option(unsigned int *value, const struct ixgb_option *opt)
{
if (*value == OPTION_UNSET) {
*value = opt->def;
return 0;
}
switch (opt->type) {
case enable_option:
switch (*value) {
case OPTION_ENABLED:
pr_info("%s Enabled\n", opt->name);
return 0;
case OPTION_DISABLED:
pr_info("%s Disabled\n", opt->name);
return 0;
}
break;
case range_option:
if (*value >= opt->arg.r.min && *value <= opt->arg.r.max) {
pr_info("%s set to %i\n", opt->name, *value);
return 0;
}
break;
case list_option: {
int i;
const struct ixgb_opt_list *ent;
for (i = 0; i < opt->arg.l.nr; i++) {
ent = &opt->arg.l.p[i];
if (*value == ent->i) {
if (ent->str[0] != '\0')
pr_info("%s\n", ent->str);
return 0;
}
}
}
break;
default:
BUG();
}
pr_info("Invalid %s specified (%i) %s\n", opt->name, *value, opt->err);
*value = opt->def;
return -1;
}
void __devinit
ixgb_check_options(struct ixgb_adapter *adapter)
{
int bd = adapter->bd_number;
if (bd >= IXGB_MAX_NIC) {
pr_notice("Warning: no configuration for board #%i\n", bd);
pr_notice("Using defaults for all values\n");
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Transmit Descriptors",
.err = "using default of " __MODULE_STRING(DEFAULT_TXD),
.def = DEFAULT_TXD,
.arg = { .r = { .min = MIN_TXD,
.max = MAX_TXD}}
};
struct ixgb_desc_ring *tx_ring = &adapter->tx_ring;
if (num_TxDescriptors > bd) {
tx_ring->count = TxDescriptors[bd];
ixgb_validate_option(&tx_ring->count, &opt);
} else {
tx_ring->count = opt.def;
}
tx_ring->count = ALIGN(tx_ring->count, IXGB_REQ_TX_DESCRIPTOR_MULTIPLE);
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Receive Descriptors",
.err = "using default of " __MODULE_STRING(DEFAULT_RXD),
.def = DEFAULT_RXD,
.arg = { .r = { .min = MIN_RXD,
.max = MAX_RXD}}
};
struct ixgb_desc_ring *rx_ring = &adapter->rx_ring;
if (num_RxDescriptors > bd) {
rx_ring->count = RxDescriptors[bd];
ixgb_validate_option(&rx_ring->count, &opt);
} else {
rx_ring->count = opt.def;
}
rx_ring->count = ALIGN(rx_ring->count, IXGB_REQ_RX_DESCRIPTOR_MULTIPLE);
}
{
static const struct ixgb_option opt = {
.type = enable_option,
.name = "Receive Checksum Offload",
.err = "defaulting to Enabled",
.def = OPTION_ENABLED
};
if (num_XsumRX > bd) {
unsigned int rx_csum = XsumRX[bd];
ixgb_validate_option(&rx_csum, &opt);
adapter->rx_csum = rx_csum;
} else {
adapter->rx_csum = opt.def;
}
}
{
static const struct ixgb_opt_list fc_list[] = {
{ ixgb_fc_none, "Flow Control Disabled" },
{ ixgb_fc_rx_pause, "Flow Control Receive Only" },
{ ixgb_fc_tx_pause, "Flow Control Transmit Only" },
{ ixgb_fc_full, "Flow Control Enabled" },
{ ixgb_fc_default, "Flow Control Hardware Default" }
};
static const struct ixgb_option opt = {
.type = list_option,
.name = "Flow Control",
.err = "reading default settings from EEPROM",
.def = ixgb_fc_tx_pause,
.arg = { .l = { .nr = ARRAY_SIZE(fc_list),
.p = fc_list }}
};
if (num_FlowControl > bd) {
unsigned int fc = FlowControl[bd];
ixgb_validate_option(&fc, &opt);
adapter->hw.fc.type = fc;
} else {
adapter->hw.fc.type = opt.def;
}
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Rx Flow Control High Threshold",
.err = "using default of " __MODULE_STRING(DEFAULT_FCRTH),
.def = DEFAULT_FCRTH,
.arg = { .r = { .min = MIN_FCRTH,
.max = MAX_FCRTH}}
};
if (num_RxFCHighThresh > bd) {
adapter->hw.fc.high_water = RxFCHighThresh[bd];
ixgb_validate_option(&adapter->hw.fc.high_water, &opt);
} else {
adapter->hw.fc.high_water = opt.def;
}
if (!(adapter->hw.fc.type & ixgb_fc_tx_pause) )
pr_info("Ignoring RxFCHighThresh when no RxFC\n");
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Rx Flow Control Low Threshold",
.err = "using default of " __MODULE_STRING(DEFAULT_FCRTL),
.def = DEFAULT_FCRTL,
.arg = { .r = { .min = MIN_FCRTL,
.max = MAX_FCRTL}}
};
if (num_RxFCLowThresh > bd) {
adapter->hw.fc.low_water = RxFCLowThresh[bd];
ixgb_validate_option(&adapter->hw.fc.low_water, &opt);
} else {
adapter->hw.fc.low_water = opt.def;
}
if (!(adapter->hw.fc.type & ixgb_fc_tx_pause) )
pr_info("Ignoring RxFCLowThresh when no RxFC\n");
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Flow Control Pause Time Request",
.err = "using default of "__MODULE_STRING(DEFAULT_FCPAUSE),
.def = DEFAULT_FCPAUSE,
.arg = { .r = { .min = MIN_FCPAUSE,
.max = MAX_FCPAUSE}}
};
if (num_FCReqTimeout > bd) {
unsigned int pause_time = FCReqTimeout[bd];
ixgb_validate_option(&pause_time, &opt);
adapter->hw.fc.pause_time = pause_time;
} else {
adapter->hw.fc.pause_time = opt.def;
}
if (!(adapter->hw.fc.type & ixgb_fc_tx_pause) )
pr_info("Ignoring FCReqTimeout when no RxFC\n");
}
if (adapter->hw.fc.type & ixgb_fc_tx_pause) {
if (adapter->hw.fc.high_water < (adapter->hw.fc.low_water + 8)) {
pr_info("RxFCHighThresh must be >= (RxFCLowThresh + 8), Using Defaults\n");
adapter->hw.fc.high_water = DEFAULT_FCRTH;
adapter->hw.fc.low_water = DEFAULT_FCRTL;
}
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Receive Interrupt Delay",
.err = "using default of " __MODULE_STRING(DEFAULT_RDTR),
.def = DEFAULT_RDTR,
.arg = { .r = { .min = MIN_RDTR,
.max = MAX_RDTR}}
};
if (num_RxIntDelay > bd) {
adapter->rx_int_delay = RxIntDelay[bd];
ixgb_validate_option(&adapter->rx_int_delay, &opt);
} else {
adapter->rx_int_delay = opt.def;
}
}
{
static const struct ixgb_option opt = {
.type = range_option,
.name = "Transmit Interrupt Delay",
.err = "using default of " __MODULE_STRING(DEFAULT_TIDV),
.def = DEFAULT_TIDV,
.arg = { .r = { .min = MIN_TIDV,
.max = MAX_TIDV}}
};
if (num_TxIntDelay > bd) {
adapter->tx_int_delay = TxIntDelay[bd];
ixgb_validate_option(&adapter->tx_int_delay, &opt);
} else {
adapter->tx_int_delay = opt.def;
}
}
{
static const struct ixgb_option opt = {
.type = enable_option,
.name = "Tx Interrupt Delay Enable",
.err = "defaulting to Enabled",
.def = OPTION_ENABLED
};
if (num_IntDelayEnable > bd) {
unsigned int ide = IntDelayEnable[bd];
ixgb_validate_option(&ide, &opt);
adapter->tx_int_delay_enable = ide;
} else {
adapter->tx_int_delay_enable = opt.def;
}
}
}
