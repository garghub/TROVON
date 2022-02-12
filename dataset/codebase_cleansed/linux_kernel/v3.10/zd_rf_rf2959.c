static int rf2959_init_hw(struct zd_rf *rf)
{
int r;
struct zd_chip *chip = zd_rf_to_chip(rf);
static const struct zd_ioreq16 ioreqs[] = {
{ ZD_CR2, 0x1E }, { ZD_CR9, 0x20 }, { ZD_CR10, 0x89 },
{ ZD_CR11, 0x00 }, { ZD_CR15, 0xD0 }, { ZD_CR17, 0x68 },
{ ZD_CR19, 0x4a }, { ZD_CR20, 0x0c }, { ZD_CR21, 0x0E },
{ ZD_CR23, 0x48 },
{ ZD_CR24, 0x14 },
{ ZD_CR26, 0x90 }, { ZD_CR27, 0x30 }, { ZD_CR29, 0x20 },
{ ZD_CR31, 0xb2 }, { ZD_CR32, 0x43 }, { ZD_CR33, 0x28 },
{ ZD_CR38, 0x30 }, { ZD_CR34, 0x0f }, { ZD_CR35, 0xF0 },
{ ZD_CR41, 0x2a }, { ZD_CR46, 0x7F }, { ZD_CR47, 0x1E },
{ ZD_CR51, 0xc5 }, { ZD_CR52, 0xc5 }, { ZD_CR53, 0xc5 },
{ ZD_CR79, 0x58 }, { ZD_CR80, 0x30 }, { ZD_CR81, 0x30 },
{ ZD_CR82, 0x00 }, { ZD_CR83, 0x24 }, { ZD_CR84, 0x04 },
{ ZD_CR85, 0x00 }, { ZD_CR86, 0x10 }, { ZD_CR87, 0x2A },
{ ZD_CR88, 0x10 }, { ZD_CR89, 0x24 }, { ZD_CR90, 0x18 },
{ ZD_CR91, 0x00 },
{ ZD_CR92, 0x0a }, { ZD_CR93, 0x00 }, { ZD_CR94, 0x01 },
{ ZD_CR95, 0x00 }, { ZD_CR96, 0x40 }, { ZD_CR97, 0x37 },
{ ZD_CR98, 0x05 }, { ZD_CR99, 0x28 }, { ZD_CR100, 0x00 },
{ ZD_CR101, 0x13 }, { ZD_CR102, 0x27 }, { ZD_CR103, 0x27 },
{ ZD_CR104, 0x18 }, { ZD_CR105, 0x12 },
{ ZD_CR106, 0x1a },
{ ZD_CR107, 0x24 }, { ZD_CR108, 0x0a }, { ZD_CR109, 0x13 },
{ ZD_CR110, 0x2F }, { ZD_CR111, 0x27 }, { ZD_CR112, 0x27 },
{ ZD_CR113, 0x27 }, { ZD_CR114, 0x27 }, { ZD_CR115, 0x40 },
{ ZD_CR116, 0x40 }, { ZD_CR117, 0xF0 }, { ZD_CR118, 0xF0 },
{ ZD_CR119, 0x16 },
{ ZD_CR122, 0x00 },
{ ZD_CR127, 0x03 }, { ZD_CR131, 0x08 }, { ZD_CR138, 0x28 },
{ ZD_CR148, 0x44 }, { ZD_CR150, 0x10 }, { ZD_CR169, 0xBB },
{ ZD_CR170, 0xBB },
};
static const u32 rv[] = {
0x000007,
0x07dd43,
0x080959,
0x0e6666,
0x116a57,
0x17dd43,
0x1819f9,
0x1e6666,
0x214554,
0x25e7fa,
0x27fffa,
0x294128,
0x2c0000,
0x300000,
0x340000,
0x381e0f,
0x6c180f,
};
r = zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
if (r)
return r;
return zd_rfwritev_locked(chip, rv, ARRAY_SIZE(rv), RF_RV_BITS);
}
static int rf2959_set_channel(struct zd_rf *rf, u8 channel)
{
int i, r;
const u32 *rv = rf2959_table[channel-1];
struct zd_chip *chip = zd_rf_to_chip(rf);
for (i = 0; i < 2; i++) {
r = zd_rfwrite_locked(chip, rv[i], RF_RV_BITS);
if (r)
return r;
}
return 0;
}
static int rf2959_switch_radio_on(struct zd_rf *rf)
{
static const struct zd_ioreq16 ioreqs[] = {
{ ZD_CR10, 0x89 },
{ ZD_CR11, 0x00 },
};
struct zd_chip *chip = zd_rf_to_chip(rf);
return zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
}
static int rf2959_switch_radio_off(struct zd_rf *rf)
{
static const struct zd_ioreq16 ioreqs[] = {
{ ZD_CR10, 0x15 },
{ ZD_CR11, 0x81 },
};
struct zd_chip *chip = zd_rf_to_chip(rf);
return zd_iowrite16a_locked(chip, ioreqs, ARRAY_SIZE(ioreqs));
}
int zd_rf_init_rf2959(struct zd_rf *rf)
{
struct zd_chip *chip = zd_rf_to_chip(rf);
if (zd_chip_is_zd1211b(chip)) {
dev_err(zd_chip_dev(chip),
"RF2959 is currently not supported for ZD1211B"
" devices\n");
return -ENODEV;
}
rf->init_hw = rf2959_init_hw;
rf->set_channel = rf2959_set_channel;
rf->switch_radio_on = rf2959_switch_radio_on;
rf->switch_radio_off = rf2959_switch_radio_off;
return 0;
}
