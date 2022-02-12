static int e1000_validate_option(unsigned int *value,
const struct e1000_option *opt,
struct e1000_adapter *adapter)
{
if (*value == OPTION_UNSET) {
*value = opt->def;
return 0;
}
switch (opt->type) {
case enable_option:
switch (*value) {
case OPTION_ENABLED:
dev_info(&adapter->pdev->dev, "%s Enabled\n",
opt->name);
return 0;
case OPTION_DISABLED:
dev_info(&adapter->pdev->dev, "%s Disabled\n",
opt->name);
return 0;
}
break;
case range_option:
if (*value >= opt->arg.r.min && *value <= opt->arg.r.max) {
dev_info(&adapter->pdev->dev, "%s set to %i\n",
opt->name, *value);
return 0;
}
break;
case list_option: {
int i;
struct e1000_opt_list *ent;
for (i = 0; i < opt->arg.l.nr; i++) {
ent = &opt->arg.l.p[i];
if (*value == ent->i) {
if (ent->str[0] != '\0')
dev_info(&adapter->pdev->dev, "%s\n",
ent->str);
return 0;
}
}
}
break;
default:
BUG();
}
dev_info(&adapter->pdev->dev, "Invalid %s value specified (%i) %s\n",
opt->name, *value, opt->err);
*value = opt->def;
return -1;
}
void e1000e_check_options(struct e1000_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
int bd = adapter->bd_number;
if (bd >= E1000_MAX_NIC) {
dev_notice(&adapter->pdev->dev,
"Warning: no configuration for board #%i\n", bd);
dev_notice(&adapter->pdev->dev,
"Using defaults for all values\n");
}
{
static const struct e1000_option opt = {
.type = range_option,
.name = "Transmit Interrupt Delay",
.err = "using default of "
__MODULE_STRING(DEFAULT_TIDV),
.def = DEFAULT_TIDV,
.arg = { .r = { .min = MIN_TXDELAY,
.max = MAX_TXDELAY } }
};
if (num_TxIntDelay > bd) {
adapter->tx_int_delay = TxIntDelay[bd];
e1000_validate_option(&adapter->tx_int_delay, &opt,
adapter);
} else {
adapter->tx_int_delay = opt.def;
}
}
{
static const struct e1000_option opt = {
.type = range_option,
.name = "Transmit Absolute Interrupt Delay",
.err = "using default of "
__MODULE_STRING(DEFAULT_TADV),
.def = DEFAULT_TADV,
.arg = { .r = { .min = MIN_TXABSDELAY,
.max = MAX_TXABSDELAY } }
};
if (num_TxAbsIntDelay > bd) {
adapter->tx_abs_int_delay = TxAbsIntDelay[bd];
e1000_validate_option(&adapter->tx_abs_int_delay, &opt,
adapter);
} else {
adapter->tx_abs_int_delay = opt.def;
}
}
{
static struct e1000_option opt = {
.type = range_option,
.name = "Receive Interrupt Delay",
.err = "using default of "
__MODULE_STRING(DEFAULT_RDTR),
.def = DEFAULT_RDTR,
.arg = { .r = { .min = MIN_RXDELAY,
.max = MAX_RXDELAY } }
};
if (num_RxIntDelay > bd) {
adapter->rx_int_delay = RxIntDelay[bd];
e1000_validate_option(&adapter->rx_int_delay, &opt,
adapter);
} else {
adapter->rx_int_delay = opt.def;
}
}
{
static const struct e1000_option opt = {
.type = range_option,
.name = "Receive Absolute Interrupt Delay",
.err = "using default of "
__MODULE_STRING(DEFAULT_RADV),
.def = DEFAULT_RADV,
.arg = { .r = { .min = MIN_RXABSDELAY,
.max = MAX_RXABSDELAY } }
};
if (num_RxAbsIntDelay > bd) {
adapter->rx_abs_int_delay = RxAbsIntDelay[bd];
e1000_validate_option(&adapter->rx_abs_int_delay, &opt,
adapter);
} else {
adapter->rx_abs_int_delay = opt.def;
}
}
{
static const struct e1000_option opt = {
.type = range_option,
.name = "Interrupt Throttling Rate (ints/sec)",
.err = "using default of "
__MODULE_STRING(DEFAULT_ITR),
.def = DEFAULT_ITR,
.arg = { .r = { .min = MIN_ITR,
.max = MAX_ITR } }
};
if (num_InterruptThrottleRate > bd) {
adapter->itr = InterruptThrottleRate[bd];
if ((adapter->itr > 4) &&
e1000_validate_option(&adapter->itr, &opt, adapter))
adapter->itr = opt.def;
} else {
adapter->itr = opt.def;
if (adapter->itr > 4)
dev_info(&adapter->pdev->dev,
"%s set to default %d\n", opt.name,
adapter->itr);
}
adapter->itr_setting = adapter->itr;
switch (adapter->itr) {
case 0:
dev_info(&adapter->pdev->dev, "%s turned off\n",
opt.name);
break;
case 1:
dev_info(&adapter->pdev->dev,
"%s set to dynamic mode\n", opt.name);
adapter->itr = 20000;
break;
case 3:
dev_info(&adapter->pdev->dev,
"%s set to dynamic conservative mode\n",
opt.name);
adapter->itr = 20000;
break;
case 4:
dev_info(&adapter->pdev->dev,
"%s set to simplified (2000-8000 ints) mode\n",
opt.name);
break;
default:
adapter->itr_setting &= ~3;
break;
}
}
{
static struct e1000_option opt = {
.type = range_option,
.name = "Interrupt Mode",
#ifndef CONFIG_PCI_MSI
.err = "defaulting to 0 (legacy)",
.def = E1000E_INT_MODE_LEGACY,
.arg = { .r = { .min = 0,
.max = 0 } }
#endif
};
#ifdef CONFIG_PCI_MSI
if (adapter->flags & FLAG_HAS_MSIX) {
opt.err = kstrdup("defaulting to 2 (MSI-X)",
GFP_KERNEL);
opt.def = E1000E_INT_MODE_MSIX;
opt.arg.r.max = E1000E_INT_MODE_MSIX;
} else {
opt.err = kstrdup("defaulting to 1 (MSI)", GFP_KERNEL);
opt.def = E1000E_INT_MODE_MSI;
opt.arg.r.max = E1000E_INT_MODE_MSI;
}
if (!opt.err) {
dev_err(&adapter->pdev->dev,
"Failed to allocate memory\n");
return;
}
#endif
if (num_IntMode > bd) {
unsigned int int_mode = IntMode[bd];
e1000_validate_option(&int_mode, &opt, adapter);
adapter->int_mode = int_mode;
} else {
adapter->int_mode = opt.def;
}
#ifdef CONFIG_PCI_MSI
kfree(opt.err);
#endif
}
{
static const struct e1000_option opt = {
.type = enable_option,
.name = "PHY Smart Power Down",
.err = "defaulting to Disabled",
.def = OPTION_DISABLED
};
if (num_SmartPowerDownEnable > bd) {
unsigned int spd = SmartPowerDownEnable[bd];
e1000_validate_option(&spd, &opt, adapter);
if ((adapter->flags & FLAG_HAS_SMART_POWER_DOWN) && spd)
adapter->flags |= FLAG_SMART_POWER_DOWN;
}
}
{
static const struct e1000_option opt = {
.type = enable_option,
.name = "CRC Stripping",
.err = "defaulting to Enabled",
.def = OPTION_ENABLED
};
if (num_CrcStripping > bd) {
unsigned int crc_stripping = CrcStripping[bd];
e1000_validate_option(&crc_stripping, &opt, adapter);
if (crc_stripping == OPTION_ENABLED) {
adapter->flags2 |= FLAG2_CRC_STRIPPING;
adapter->flags2 |= FLAG2_DFLT_CRC_STRIPPING;
}
} else {
adapter->flags2 |= FLAG2_CRC_STRIPPING;
adapter->flags2 |= FLAG2_DFLT_CRC_STRIPPING;
}
}
{
static const struct e1000_option opt = {
.type = enable_option,
.name = "Kumeran Lock Loss Workaround",
.err = "defaulting to Enabled",
.def = OPTION_ENABLED
};
if (num_KumeranLockLoss > bd) {
unsigned int kmrn_lock_loss = KumeranLockLoss[bd];
e1000_validate_option(&kmrn_lock_loss, &opt, adapter);
if (hw->mac.type == e1000_ich8lan)
e1000e_set_kmrn_lock_loss_workaround_ich8lan(hw,
kmrn_lock_loss);
} else {
if (hw->mac.type == e1000_ich8lan)
e1000e_set_kmrn_lock_loss_workaround_ich8lan(hw,
opt.def);
}
}
{
static const struct e1000_option opt = {
.type = enable_option,
.name = "Write-protect NVM",
.err = "defaulting to Enabled",
.def = OPTION_ENABLED
};
if (adapter->flags & FLAG_IS_ICH) {
if (num_WriteProtectNVM > bd) {
unsigned int write_protect_nvm = WriteProtectNVM[bd];
e1000_validate_option(&write_protect_nvm, &opt,
adapter);
if (write_protect_nvm)
adapter->flags |= FLAG_READ_ONLY_NVM;
} else {
if (opt.def)
adapter->flags |= FLAG_READ_ONLY_NVM;
}
}
}
}
