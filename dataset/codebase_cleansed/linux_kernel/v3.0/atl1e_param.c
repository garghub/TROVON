static int __devinit atl1e_validate_option(int *value, struct atl1e_option *opt, struct atl1e_adapter *adapter)
{
if (*value == OPTION_UNSET) {
*value = opt->def;
return 0;
}
switch (opt->type) {
case enable_option:
switch (*value) {
case OPTION_ENABLED:
netdev_info(adapter->netdev,
"%s Enabled\n", opt->name);
return 0;
case OPTION_DISABLED:
netdev_info(adapter->netdev,
"%s Disabled\n", opt->name);
return 0;
}
break;
case range_option:
if (*value >= opt->arg.r.min && *value <= opt->arg.r.max) {
netdev_info(adapter->netdev, "%s set to %i\n",
opt->name, *value);
return 0;
}
break;
case list_option:{
int i;
struct atl1e_opt_list *ent;
for (i = 0; i < opt->arg.l.nr; i++) {
ent = &opt->arg.l.p[i];
if (*value == ent->i) {
if (ent->str[0] != '\0')
netdev_info(adapter->netdev,
"%s\n", ent->str);
return 0;
}
}
break;
}
default:
BUG();
}
netdev_info(adapter->netdev, "Invalid %s specified (%i) %s\n",
opt->name, *value, opt->err);
*value = opt->def;
return -1;
}
void __devinit atl1e_check_options(struct atl1e_adapter *adapter)
{
int bd = adapter->bd_number;
if (bd >= ATL1E_MAX_NIC) {
netdev_notice(adapter->netdev,
"no configuration for board #%i\n", bd);
netdev_notice(adapter->netdev,
"Using defaults for all values\n");
}
{
struct atl1e_option opt = {
.type = range_option,
.name = "Transmit Ddescription Count",
.err = "using default of "
__MODULE_STRING(ATL1E_DEFAULT_TX_DESC_CNT),
.def = ATL1E_DEFAULT_TX_DESC_CNT,
.arg = { .r = { .min = ATL1E_MIN_TX_DESC_CNT,
.max = ATL1E_MAX_TX_DESC_CNT} }
};
int val;
if (num_tx_desc_cnt > bd) {
val = tx_desc_cnt[bd];
atl1e_validate_option(&val, &opt, adapter);
adapter->tx_ring.count = (u16) val & 0xFFFC;
} else
adapter->tx_ring.count = (u16)opt.def;
}
{
struct atl1e_option opt = {
.type = range_option,
.name = "Memory size of rx buffer(KB)",
.err = "using default of "
__MODULE_STRING(ATL1E_DEFAULT_RX_MEM_SIZE),
.def = ATL1E_DEFAULT_RX_MEM_SIZE,
.arg = { .r = { .min = ATL1E_MIN_RX_MEM_SIZE,
.max = ATL1E_MAX_RX_MEM_SIZE} }
};
int val;
if (num_rx_mem_size > bd) {
val = rx_mem_size[bd];
atl1e_validate_option(&val, &opt, adapter);
adapter->rx_ring.page_size = (u32)val * 1024;
} else {
adapter->rx_ring.page_size = (u32)opt.def * 1024;
}
}
{
struct atl1e_option opt = {
.type = range_option,
.name = "Interrupt Moderate Timer",
.err = "using default of "
__MODULE_STRING(INT_MOD_DEFAULT_CNT),
.def = INT_MOD_DEFAULT_CNT,
.arg = { .r = { .min = INT_MOD_MIN_CNT,
.max = INT_MOD_MAX_CNT} }
} ;
int val;
if (num_int_mod_timer > bd) {
val = int_mod_timer[bd];
atl1e_validate_option(&val, &opt, adapter);
adapter->hw.imt = (u16) val;
} else
adapter->hw.imt = (u16)(opt.def);
}
{
struct atl1e_option opt = {
.type = range_option,
.name = "Speed/Duplex Selection",
.err = "using default of "
__MODULE_STRING(MEDIA_TYPE_AUTO_SENSOR),
.def = MEDIA_TYPE_AUTO_SENSOR,
.arg = { .r = { .min = MEDIA_TYPE_AUTO_SENSOR,
.max = MEDIA_TYPE_10M_HALF} }
} ;
int val;
if (num_media_type > bd) {
val = media_type[bd];
atl1e_validate_option(&val, &opt, adapter);
adapter->hw.media_type = (u16) val;
} else
adapter->hw.media_type = (u16)(opt.def);
}
}
