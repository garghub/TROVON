static int uw2453_synth_set_channel(struct zd_chip *chip, int channel,
bool autocal)
{
int r;
int idx = channel - 1;
u32 val;
if (autocal)
val = UW2453_REGWRITE(1, uw2453_autocal_synth[idx]);
else
val = UW2453_REGWRITE(1, uw2453_std_synth[idx]);
r = zd_rfwrite_locked(chip, val, RF_RV_BITS);
if (r)
return r;
return zd_rfwrite_locked(chip,
UW2453_REGWRITE(2, uw2453_synth_divide[idx]), RF_RV_BITS);
}
static int uw2453_write_vco_cfg(struct zd_chip *chip, u16 value)
{
u32 val = 0x40000 | value;
return zd_rfwrite_locked(chip, UW2453_REGWRITE(3, val), RF_RV_BITS);
}
static int uw2453_init_mode(struct zd_chip *chip)
{
static const u32 rv[] = {
UW2453_REGWRITE(0, 0x25f98),
UW2453_REGWRITE(0, 0x25f9a),
UW2453_REGWRITE(0, 0x25f94),
UW2453_REGWRITE(0, 0x27fd4),
};
return zd_rfwritev_locked(chip, rv, ARRAY_SIZE(rv), RF_RV_BITS);
}
static int uw2453_set_tx_gain_level(struct zd_chip *chip, int channel)
{
u8 int_value = chip->pwr_int_values[channel - 1];
if (int_value >= ARRAY_SIZE(uw2453_txgain)) {
dev_dbg_f(zd_chip_dev(chip), "can't configure TX gain for "
"int value %x on channel %d\n", int_value, channel);
return 0;
}
return zd_rfwrite_locked(chip,
UW2453_REGWRITE(7, uw2453_txgain[int_value]), RF_RV_BITS);
}
static int uw2453_init_hw(struct zd_rf *rf)
{
int i, r;
int found_config = -1;
u16 intr_status;
struct zd_chip *chip = zd_rf_to_chip(rf);
static const struct zd_ioreq16 ioreqs[] = {
{ ZD_CR10, 0x89 }, { ZD_CR15, 0x20 },
{ ZD_CR17, 0x28 },
{ ZD_CR23, 0x38 }, { ZD_CR24, 0x20 }, { ZD_CR26, 0x93 },
{ ZD_CR27, 0x15 }, { ZD_CR28, 0x3e }, { ZD_CR29, 0x00 },
{ ZD_CR33, 0x28 }, { ZD_CR34, 0x30 },
{ ZD_CR35, 0x43 },
{ ZD_CR41, 0x24 }, { ZD_CR44, 0x32 },
{ ZD_CR46, 0x92 },
{ ZD_CR47, 0x1e },
{ ZD_CR48, 0x04 },
{ ZD_CR49, 0xfa }, { ZD_CR79, 0x58 }, { ZD_CR80, 0x30 },
{ ZD_CR81, 0x30 }, { ZD_CR87, 0x0a }, { ZD_CR89, 0x04 },
{ ZD_CR91, 0x00 }, { ZD_CR92, 0x0a }, { ZD_CR98, 0x8d },
{ ZD_CR99, 0x28 }, { ZD_CR100, 0x02 },
{ ZD_CR101, 0x09 },
{ ZD_CR102, 0x27 },
{ ZD_CR106, 0x1c },
{ ZD_CR107, 0x1c },
{ ZD_CR109, 0x13 },
{ ZD_CR110, 0x1f },
{ ZD_CR111, 0x13 }, { ZD_CR112, 0x1f }, { ZD_CR113, 0x27 },
{ ZD_CR114, 0x23 },
{ ZD_CR115, 0x24 },
{ ZD_CR116, 0x24 },
{ ZD_CR117, 0xfa },
{ ZD_CR118, 0xf0 },
{ ZD_CR119, 0x1a },
{ ZD_CR120, 0x4f },
{ ZD_CR121, 0x1f },
{ ZD_CR122, 0xf0 }, { ZD_CR123, 0x57 }, { ZD_CR125, 0xad },
{ ZD_CR126, 0x6c }, { ZD_CR127, 0x03 },
{ ZD_CR128, 0x14 },
{ ZD_CR129, 0x12 },
{ ZD_CR130, 0x10 }, { ZD_CR137, 0x50 }, { ZD_CR138, 0xa8 },
{ ZD_CR144, 0xac }, { ZD_CR146, 0x20 }, { ZD_CR252, 0xff },
{ ZD_CR253, 0xff },
};
static const u32 rv[] = {
UW2453_REGWRITE(4, 0x2b),
UW2453_REGWRITE(5, 0x19e4f),
UW2453_REGWRITE(6, 0xf81ad),
UW2453_REGWRITE(7, 0x3fffe),
UW2453_REGWRITE(0, 0x25f9c),
UW2453_REGWRITE(1, 0x47),
UW2453_REGWRITE(2, 0x999),
UW2453_REGWRITE(3, 0x7602),
UW2453_REGWRITE(3, 0x46063),
};
r = zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
if (r)
return r;
r = zd_rfwritev_locked(chip, rv, ARRAY_SIZE(rv), RF_RV_BITS);
if (r)
return r;
r = uw2453_init_mode(chip);
if (r)
return r;
for (i = 0; i < ARRAY_SIZE(uw2453_std_vco_cfg) - 1; i++) {
r = uw2453_synth_set_channel(chip, 1, false);
if (r)
return r;
r = uw2453_write_vco_cfg(chip, uw2453_std_vco_cfg[i][0]);
if (r)
return r;
r = zd_iowrite16_locked(chip, 0x0f, UW2453_INTR_REG);
if (r)
return r;
r = zd_ioread16_locked(chip, &intr_status, UW2453_INTR_REG);
if (r)
return r;
if (!(intr_status & 0xf)) {
dev_dbg_f(zd_chip_dev(chip),
"PLL locked on configuration %d\n", i);
found_config = i;
break;
}
}
if (found_config == -1) {
dev_dbg_f(zd_chip_dev(chip),
"PLL did not lock, using autocal\n");
r = uw2453_synth_set_channel(chip, 1, true);
if (r)
return r;
r = uw2453_write_vco_cfg(chip, UW2453_AUTOCAL_VCO_CFG);
if (r)
return r;
}
UW2453_PRIV(rf)->config = found_config + 1;
return zd_iowrite16_locked(chip, 0x06, ZD_CR203);
}
static int uw2453_set_channel(struct zd_rf *rf, u8 channel)
{
int r;
u16 vco_cfg;
int config = UW2453_PRIV(rf)->config;
bool autocal = (config == -1);
struct zd_chip *chip = zd_rf_to_chip(rf);
static const struct zd_ioreq16 ioreqs[] = {
{ ZD_CR80, 0x30 }, { ZD_CR81, 0x30 }, { ZD_CR79, 0x58 },
{ ZD_CR12, 0xf0 }, { ZD_CR77, 0x1b }, { ZD_CR78, 0x58 },
};
r = uw2453_synth_set_channel(chip, channel, autocal);
if (r)
return r;
if (autocal)
vco_cfg = UW2453_AUTOCAL_VCO_CFG;
else
vco_cfg = uw2453_std_vco_cfg[config][CHAN_TO_PAIRIDX(channel)];
r = uw2453_write_vco_cfg(chip, vco_cfg);
if (r)
return r;
r = uw2453_init_mode(chip);
if (r)
return r;
r = zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
if (r)
return r;
r = uw2453_set_tx_gain_level(chip, channel);
if (r)
return r;
return zd_iowrite16_locked(chip, 0x06, ZD_CR203);
}
static int uw2453_switch_radio_on(struct zd_rf *rf)
{
int r;
struct zd_chip *chip = zd_rf_to_chip(rf);
struct zd_ioreq16 ioreqs[] = {
{ ZD_CR11, 0x00 }, { ZD_CR251, 0x3f },
};
r = zd_rfwrite_locked(chip, UW2453_REGWRITE(0, 0x25f94), RF_RV_BITS);
if (r)
return r;
if (zd_chip_is_zd1211b(chip))
ioreqs[1].value = 0x7f;
return zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
}
static int uw2453_switch_radio_off(struct zd_rf *rf)
{
int r;
struct zd_chip *chip = zd_rf_to_chip(rf);
static const struct zd_ioreq16 ioreqs[] = {
{ ZD_CR11, 0x04 }, { ZD_CR251, 0x2f },
};
r = zd_rfwrite_locked(chip, UW2453_REGWRITE(0, 0x25f90), RF_RV_BITS);
if (r)
return r;
return zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
}
static void uw2453_clear(struct zd_rf *rf)
{
kfree(rf->priv);
}
int zd_rf_init_uw2453(struct zd_rf *rf)
{
rf->init_hw = uw2453_init_hw;
rf->set_channel = uw2453_set_channel;
rf->switch_radio_on = uw2453_switch_radio_on;
rf->switch_radio_off = uw2453_switch_radio_off;
rf->patch_6m_band_edge = zd_rf_generic_patch_6m;
rf->clear = uw2453_clear;
rf->update_channel_int = 0;
rf->priv = kmalloc(sizeof(struct uw2453_priv), GFP_KERNEL);
if (rf->priv == NULL)
return -ENOMEM;
return 0;
}
