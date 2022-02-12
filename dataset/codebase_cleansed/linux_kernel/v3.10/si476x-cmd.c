static int si476x_core_parse_and_nag_about_error(struct si476x_core *core)
{
int err;
char *cause;
u8 buffer[2];
if (core->revision != SI476X_REVISION_A10) {
err = si476x_core_i2c_xfer(core, SI476X_I2C_RECV,
buffer, sizeof(buffer));
if (err == sizeof(buffer)) {
switch (buffer[1]) {
case SI476X_ERR_BAD_COMMAND:
cause = "Bad command";
err = -EINVAL;
break;
case SI476X_ERR_BAD_ARG1:
cause = "Bad argument #1";
err = -EINVAL;
break;
case SI476X_ERR_BAD_ARG2:
cause = "Bad argument #2";
err = -EINVAL;
break;
case SI476X_ERR_BAD_ARG3:
cause = "Bad argument #3";
err = -EINVAL;
break;
case SI476X_ERR_BAD_ARG4:
cause = "Bad argument #4";
err = -EINVAL;
break;
case SI476X_ERR_BUSY:
cause = "Chip is busy";
err = -EBUSY;
break;
case SI476X_ERR_BAD_INTERNAL_MEMORY:
cause = "Bad internal memory";
err = -EIO;
break;
case SI476X_ERR_BAD_PATCH:
cause = "Bad patch";
err = -EINVAL;
break;
case SI476X_ERR_BAD_BOOT_MODE:
cause = "Bad boot mode";
err = -EINVAL;
break;
case SI476X_ERR_BAD_PROPERTY:
cause = "Bad property";
err = -EINVAL;
break;
default:
cause = "Unknown";
err = -EIO;
}
dev_err(&core->client->dev,
"[Chip error status]: %s\n", cause);
} else {
dev_err(&core->client->dev,
"Failed to fetch error code\n");
err = (err >= 0) ? -EIO : err;
}
} else {
err = -EIO;
}
return err;
}
static int si476x_core_send_command(struct si476x_core *core,
const u8 command,
const u8 args[],
const int argn,
u8 resp[],
const int respn,
const int usecs)
{
struct i2c_client *client = core->client;
int err;
u8 data[CMD_MAX_ARGS_COUNT + 1];
if (argn > CMD_MAX_ARGS_COUNT) {
err = -ENOMEM;
goto exit;
}
if (!client->adapter) {
err = -ENODEV;
goto exit;
}
data[0] = command;
memcpy(&data[1], args, argn);
dev_dbg(&client->dev, "Command:\n %*ph\n", argn + 1, data);
err = si476x_core_i2c_xfer(core, SI476X_I2C_SEND,
(char *) data, argn + 1);
if (err != argn + 1) {
dev_err(&core->client->dev,
"Error while sending command 0x%02x\n",
command);
err = (err >= 0) ? -EIO : err;
goto exit;
}
atomic_set(&core->cts, 0);
if (!wait_event_timeout(core->command,
atomic_read(&core->cts),
usecs_to_jiffies(usecs) + 1))
dev_warn(&core->client->dev,
"(%s) [CMD 0x%02x] Answer timeout.\n",
__func__, command);
if (unlikely(!core->client->irq && command == CMD_POWER_UP)) {
if (!wait_event_timeout(core->command,
atomic_read(&core->cts),
usecs_to_jiffies(usecs) + 1))
dev_warn(&core->client->dev,
"(%s) Power up took too much time.\n",
__func__);
}
err = si476x_core_i2c_xfer(core, SI476X_I2C_RECV, resp, respn);
if (err != respn) {
dev_err(&core->client->dev,
"Error while reading response for command 0x%02x\n",
command);
err = (err >= 0) ? -EIO : err;
goto exit;
}
dev_dbg(&client->dev, "Response:\n %*ph\n", respn, resp);
err = 0;
if (resp[0] & SI476X_ERR) {
dev_err(&core->client->dev,
"[CMD 0x%02x] Chip set error flag\n", command);
err = si476x_core_parse_and_nag_about_error(core);
goto exit;
}
if (!(resp[0] & SI476X_CTS))
err = -EBUSY;
exit:
return err;
}
static int si476x_cmd_clear_stc(struct si476x_core *core)
{
int err;
struct si476x_rsq_status_args args = {
.primary = false,
.rsqack = false,
.attune = false,
.cancel = false,
.stcack = true,
};
switch (core->power_up_parameters.func) {
case SI476X_FUNC_FM_RECEIVER:
err = si476x_core_cmd_fm_rsq_status(core, &args, NULL);
break;
case SI476X_FUNC_AM_RECEIVER:
err = si476x_core_cmd_am_rsq_status(core, &args, NULL);
break;
default:
err = -EINVAL;
}
return err;
}
static int si476x_cmd_tune_seek_freq(struct si476x_core *core,
uint8_t cmd,
const uint8_t args[], size_t argn,
uint8_t *resp, size_t respn)
{
int err;
atomic_set(&core->stc, 0);
err = si476x_core_send_command(core, cmd, args, argn, resp, respn,
SI476X_TIMEOUT_TUNE);
if (!err) {
wait_event_killable(core->tuning,
atomic_read(&core->stc));
si476x_cmd_clear_stc(core);
}
return err;
}
int si476x_core_cmd_func_info(struct si476x_core *core,
struct si476x_func_info *info)
{
int err;
u8 resp[CMD_FUNC_INFO_NRESP];
err = si476x_core_send_command(core, CMD_FUNC_INFO,
NULL, 0,
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
info->firmware.major = resp[1];
info->firmware.minor[0] = resp[2];
info->firmware.minor[1] = resp[3];
info->patch_id = ((u16) resp[4] << 8) | resp[5];
info->func = resp[6];
return err;
}
int si476x_core_cmd_set_property(struct si476x_core *core,
u16 property, u16 value)
{
u8 resp[CMD_SET_PROPERTY_NRESP];
const u8 args[CMD_SET_PROPERTY_NARGS] = {
0x00,
msb(property),
lsb(property),
msb(value),
lsb(value),
};
return si476x_core_send_command(core, CMD_SET_PROPERTY,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
int si476x_core_cmd_get_property(struct si476x_core *core, u16 property)
{
int err;
u8 resp[CMD_GET_PROPERTY_NRESP];
const u8 args[CMD_GET_PROPERTY_NARGS] = {
0x00,
msb(property),
lsb(property),
};
err = si476x_core_send_command(core, CMD_GET_PROPERTY,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0)
return err;
else
return get_unaligned_be16(resp + 2);
}
int si476x_core_cmd_dig_audio_pin_cfg(struct si476x_core *core,
enum si476x_dclk_config dclk,
enum si476x_dfs_config dfs,
enum si476x_dout_config dout,
enum si476x_xout_config xout)
{
u8 resp[CMD_DIG_AUDIO_PIN_CFG_NRESP];
const u8 args[CMD_DIG_AUDIO_PIN_CFG_NARGS] = {
PIN_CFG_BYTE(dclk),
PIN_CFG_BYTE(dfs),
PIN_CFG_BYTE(dout),
PIN_CFG_BYTE(xout),
};
return si476x_core_send_command(core, CMD_DIG_AUDIO_PIN_CFG,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
int si476x_core_cmd_zif_pin_cfg(struct si476x_core *core,
enum si476x_iqclk_config iqclk,
enum si476x_iqfs_config iqfs,
enum si476x_iout_config iout,
enum si476x_qout_config qout)
{
u8 resp[CMD_ZIF_PIN_CFG_NRESP];
const u8 args[CMD_ZIF_PIN_CFG_NARGS] = {
PIN_CFG_BYTE(iqclk),
PIN_CFG_BYTE(iqfs),
PIN_CFG_BYTE(iout),
PIN_CFG_BYTE(qout),
};
return si476x_core_send_command(core, CMD_ZIF_PIN_CFG,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
int si476x_core_cmd_ic_link_gpo_ctl_pin_cfg(struct si476x_core *core,
enum si476x_icin_config icin,
enum si476x_icip_config icip,
enum si476x_icon_config icon,
enum si476x_icop_config icop)
{
u8 resp[CMD_IC_LINK_GPO_CTL_PIN_CFG_NRESP];
const u8 args[CMD_IC_LINK_GPO_CTL_PIN_CFG_NARGS] = {
PIN_CFG_BYTE(icin),
PIN_CFG_BYTE(icip),
PIN_CFG_BYTE(icon),
PIN_CFG_BYTE(icop),
};
return si476x_core_send_command(core, CMD_IC_LINK_GPO_CTL_PIN_CFG,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
int si476x_core_cmd_ana_audio_pin_cfg(struct si476x_core *core,
enum si476x_lrout_config lrout)
{
u8 resp[CMD_ANA_AUDIO_PIN_CFG_NRESP];
const u8 args[CMD_ANA_AUDIO_PIN_CFG_NARGS] = {
PIN_CFG_BYTE(lrout),
};
return si476x_core_send_command(core, CMD_ANA_AUDIO_PIN_CFG,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
static int si476x_core_cmd_intb_pin_cfg_a10(struct si476x_core *core,
enum si476x_intb_config intb,
enum si476x_a1_config a1)
{
u8 resp[CMD_INTB_PIN_CFG_A10_NRESP];
const u8 args[CMD_INTB_PIN_CFG_NARGS] = {
PIN_CFG_BYTE(intb),
PIN_CFG_BYTE(a1),
};
return si476x_core_send_command(core, CMD_INTB_PIN_CFG,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
static int si476x_core_cmd_intb_pin_cfg_a20(struct si476x_core *core,
enum si476x_intb_config intb,
enum si476x_a1_config a1)
{
u8 resp[CMD_INTB_PIN_CFG_A20_NRESP];
const u8 args[CMD_INTB_PIN_CFG_NARGS] = {
PIN_CFG_BYTE(intb),
PIN_CFG_BYTE(a1),
};
return si476x_core_send_command(core, CMD_INTB_PIN_CFG,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
int si476x_core_cmd_am_rsq_status(struct si476x_core *core,
struct si476x_rsq_status_args *rsqargs,
struct si476x_rsq_status_report *report)
{
int err;
u8 resp[CMD_AM_RSQ_STATUS_NRESP];
const u8 args[CMD_AM_RSQ_STATUS_NARGS] = {
rsqargs->rsqack << 3 | rsqargs->attune << 2 |
rsqargs->cancel << 1 | rsqargs->stcack,
};
err = si476x_core_send_command(core, CMD_AM_RSQ_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (!report)
return err;
report->snrhint = 0x08 & resp[1];
report->snrlint = 0x04 & resp[1];
report->rssihint = 0x02 & resp[1];
report->rssilint = 0x01 & resp[1];
report->bltf = 0x80 & resp[2];
report->snr_ready = 0x20 & resp[2];
report->rssiready = 0x08 & resp[2];
report->afcrl = 0x02 & resp[2];
report->valid = 0x01 & resp[2];
report->readfreq = get_unaligned_be16(resp + 3);
report->freqoff = resp[5];
report->rssi = resp[6];
report->snr = resp[7];
report->lassi = resp[9];
report->hassi = resp[10];
report->mult = resp[11];
report->dev = resp[12];
return err;
}
int si476x_core_cmd_fm_acf_status(struct si476x_core *core,
struct si476x_acf_status_report *report)
{
int err;
u8 resp[CMD_FM_ACF_STATUS_NRESP];
const u8 args[CMD_FM_ACF_STATUS_NARGS] = {
0x0,
};
if (!report)
return -EINVAL;
err = si476x_core_send_command(core, CMD_FM_ACF_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0)
return err;
report->blend_int = resp[1] & SI476X_ACF_BLEND_INT;
report->hblend_int = resp[1] & SI476X_ACF_HIBLEND_INT;
report->hicut_int = resp[1] & SI476X_ACF_HICUT_INT;
report->chbw_int = resp[1] & SI476X_ACF_CHBW_INT;
report->softmute_int = resp[1] & SI476X_ACF_SOFTMUTE_INT;
report->smute = resp[2] & SI476X_ACF_SMUTE;
report->smattn = resp[3] & SI476X_ACF_SMATTN;
report->chbw = resp[4];
report->hicut = resp[5];
report->hiblend = resp[6];
report->pilot = resp[7] & SI476X_ACF_PILOT;
report->stblend = resp[7] & SI476X_ACF_STBLEND;
return err;
}
int si476x_core_cmd_am_acf_status(struct si476x_core *core,
struct si476x_acf_status_report *report)
{
int err;
u8 resp[CMD_AM_ACF_STATUS_NRESP];
const u8 args[CMD_AM_ACF_STATUS_NARGS] = {
0x0,
};
if (!report)
return -EINVAL;
err = si476x_core_send_command(core, CMD_AM_ACF_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0)
return err;
report->blend_int = resp[1] & SI476X_ACF_BLEND_INT;
report->hblend_int = resp[1] & SI476X_ACF_HIBLEND_INT;
report->hicut_int = resp[1] & SI476X_ACF_HICUT_INT;
report->chbw_int = resp[1] & SI476X_ACF_CHBW_INT;
report->softmute_int = resp[1] & SI476X_ACF_SOFTMUTE_INT;
report->smute = resp[2] & SI476X_ACF_SMUTE;
report->smattn = resp[3] & SI476X_ACF_SMATTN;
report->chbw = resp[4];
report->hicut = resp[5];
return err;
}
int si476x_core_cmd_fm_seek_start(struct si476x_core *core,
bool seekup, bool wrap)
{
u8 resp[CMD_FM_SEEK_START_NRESP];
const u8 args[CMD_FM_SEEK_START_NARGS] = {
seekup << 3 | wrap << 2,
};
return si476x_cmd_tune_seek_freq(core, CMD_FM_SEEK_START,
args, sizeof(args),
resp, sizeof(resp));
}
int si476x_core_cmd_fm_rds_status(struct si476x_core *core,
bool status_only,
bool mtfifo,
bool intack,
struct si476x_rds_status_report *report)
{
int err;
u8 resp[CMD_FM_RDS_STATUS_NRESP];
const u8 args[CMD_FM_RDS_STATUS_NARGS] = {
status_only << 2 | mtfifo << 1 | intack,
};
err = si476x_core_send_command(core, CMD_FM_RDS_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0 || report == NULL)
return err;
report->rdstpptyint = 0x10 & resp[1];
report->rdspiint = 0x08 & resp[1];
report->rdssyncint = 0x02 & resp[1];
report->rdsfifoint = 0x01 & resp[1];
report->tpptyvalid = 0x10 & resp[2];
report->pivalid = 0x08 & resp[2];
report->rdssync = 0x02 & resp[2];
report->rdsfifolost = 0x01 & resp[2];
report->tp = 0x20 & resp[3];
report->pty = 0x1f & resp[3];
report->pi = get_unaligned_be16(resp + 4);
report->rdsfifoused = resp[6];
report->ble[V4L2_RDS_BLOCK_A] = 0xc0 & resp[7];
report->ble[V4L2_RDS_BLOCK_B] = 0x30 & resp[7];
report->ble[V4L2_RDS_BLOCK_C] = 0x0c & resp[7];
report->ble[V4L2_RDS_BLOCK_D] = 0x03 & resp[7];
report->rds[V4L2_RDS_BLOCK_A].block = V4L2_RDS_BLOCK_A;
report->rds[V4L2_RDS_BLOCK_A].msb = resp[8];
report->rds[V4L2_RDS_BLOCK_A].lsb = resp[9];
report->rds[V4L2_RDS_BLOCK_B].block = V4L2_RDS_BLOCK_B;
report->rds[V4L2_RDS_BLOCK_B].msb = resp[10];
report->rds[V4L2_RDS_BLOCK_B].lsb = resp[11];
report->rds[V4L2_RDS_BLOCK_C].block = V4L2_RDS_BLOCK_C;
report->rds[V4L2_RDS_BLOCK_C].msb = resp[12];
report->rds[V4L2_RDS_BLOCK_C].lsb = resp[13];
report->rds[V4L2_RDS_BLOCK_D].block = V4L2_RDS_BLOCK_D;
report->rds[V4L2_RDS_BLOCK_D].msb = resp[14];
report->rds[V4L2_RDS_BLOCK_D].lsb = resp[15];
return err;
}
int si476x_core_cmd_fm_rds_blockcount(struct si476x_core *core,
bool clear,
struct si476x_rds_blockcount_report *report)
{
int err;
u8 resp[CMD_FM_RDS_BLOCKCOUNT_NRESP];
const u8 args[CMD_FM_RDS_BLOCKCOUNT_NARGS] = {
clear,
};
if (!report)
return -EINVAL;
err = si476x_core_send_command(core, CMD_FM_RDS_BLOCKCOUNT,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (!err) {
report->expected = get_unaligned_be16(resp + 2);
report->received = get_unaligned_be16(resp + 4);
report->uncorrectable = get_unaligned_be16(resp + 6);
}
return err;
}
int si476x_core_cmd_fm_phase_diversity(struct si476x_core *core,
enum si476x_phase_diversity_mode mode)
{
u8 resp[CMD_FM_PHASE_DIVERSITY_NRESP];
const u8 args[CMD_FM_PHASE_DIVERSITY_NARGS] = {
mode & 0x07,
};
return si476x_core_send_command(core, CMD_FM_PHASE_DIVERSITY,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
int si476x_core_cmd_fm_phase_div_status(struct si476x_core *core)
{
int err;
u8 resp[CMD_FM_PHASE_DIV_STATUS_NRESP];
err = si476x_core_send_command(core, CMD_FM_PHASE_DIV_STATUS,
NULL, 0,
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
return (err < 0) ? err : resp[1];
}
int si476x_core_cmd_am_seek_start(struct si476x_core *core,
bool seekup, bool wrap)
{
u8 resp[CMD_AM_SEEK_START_NRESP];
const u8 args[CMD_AM_SEEK_START_NARGS] = {
seekup << 3 | wrap << 2,
};
return si476x_cmd_tune_seek_freq(core, CMD_AM_SEEK_START,
args, sizeof(args),
resp, sizeof(resp));
}
static int si476x_core_cmd_power_up_a10(struct si476x_core *core,
struct si476x_power_up_args *puargs)
{
u8 resp[CMD_POWER_UP_A10_NRESP];
const bool intsel = (core->pinmux.a1 == SI476X_A1_IRQ);
const bool ctsen = (core->client->irq != 0);
const u8 args[CMD_POWER_UP_A10_NARGS] = {
0xF7,
0x3F & puargs->xcload,
ctsen << 7 | intsel << 6 | 0x07,
puargs->func << 4 | puargs->freq,
0x11,
};
return si476x_core_send_command(core, CMD_POWER_UP,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_TIMEOUT_POWER_UP);
}
static int si476x_core_cmd_power_up_a20(struct si476x_core *core,
struct si476x_power_up_args *puargs)
{
u8 resp[CMD_POWER_UP_A20_NRESP];
const bool intsel = (core->pinmux.a1 == SI476X_A1_IRQ);
const bool ctsen = (core->client->irq != 0);
const u8 args[CMD_POWER_UP_A20_NARGS] = {
puargs->ibias6x << 7 | puargs->xstart,
0x3F & puargs->xcload,
ctsen << 7 | intsel << 6 | puargs->fastboot << 5 |
puargs->xbiashc << 3 | puargs->xbias,
puargs->func << 4 | puargs->freq,
0x10 | puargs->xmode,
};
return si476x_core_send_command(core, CMD_POWER_UP,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_TIMEOUT_POWER_UP);
}
static int si476x_core_cmd_power_down_a10(struct si476x_core *core,
struct si476x_power_down_args *pdargs)
{
u8 resp[CMD_POWER_DOWN_A10_NRESP];
return si476x_core_send_command(core, CMD_POWER_DOWN,
NULL, 0,
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
static int si476x_core_cmd_power_down_a20(struct si476x_core *core,
struct si476x_power_down_args *pdargs)
{
u8 resp[CMD_POWER_DOWN_A20_NRESP];
const u8 args[CMD_POWER_DOWN_A20_NARGS] = {
pdargs->xosc,
};
return si476x_core_send_command(core, CMD_POWER_DOWN,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
}
static int si476x_core_cmd_am_tune_freq_a10(struct si476x_core *core,
struct si476x_tune_freq_args *tuneargs)
{
const int am_freq = tuneargs->freq;
u8 resp[CMD_AM_TUNE_FREQ_NRESP];
const u8 args[CMD_AM_TUNE_FREQ_NARGS] = {
(tuneargs->hd << 6),
msb(am_freq),
lsb(am_freq),
};
return si476x_cmd_tune_seek_freq(core, CMD_AM_TUNE_FREQ, args,
sizeof(args),
resp, sizeof(resp));
}
static int si476x_core_cmd_am_tune_freq_a20(struct si476x_core *core,
struct si476x_tune_freq_args *tuneargs)
{
const int am_freq = tuneargs->freq;
u8 resp[CMD_AM_TUNE_FREQ_NRESP];
const u8 args[CMD_AM_TUNE_FREQ_NARGS] = {
(tuneargs->zifsr << 6) | (tuneargs->injside & 0x03),
msb(am_freq),
lsb(am_freq),
};
return si476x_cmd_tune_seek_freq(core, CMD_AM_TUNE_FREQ,
args, sizeof(args),
resp, sizeof(resp));
}
static int si476x_core_cmd_fm_rsq_status_a10(struct si476x_core *core,
struct si476x_rsq_status_args *rsqargs,
struct si476x_rsq_status_report *report)
{
int err;
u8 resp[CMD_FM_RSQ_STATUS_A10_NRESP];
const u8 args[CMD_FM_RSQ_STATUS_A10_NARGS] = {
rsqargs->rsqack << 3 | rsqargs->attune << 2 |
rsqargs->cancel << 1 | rsqargs->stcack,
};
err = si476x_core_send_command(core, CMD_FM_RSQ_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0 || report == NULL)
return err;
report->multhint = 0x80 & resp[1];
report->multlint = 0x40 & resp[1];
report->snrhint = 0x08 & resp[1];
report->snrlint = 0x04 & resp[1];
report->rssihint = 0x02 & resp[1];
report->rssilint = 0x01 & resp[1];
report->bltf = 0x80 & resp[2];
report->snr_ready = 0x20 & resp[2];
report->rssiready = 0x08 & resp[2];
report->afcrl = 0x02 & resp[2];
report->valid = 0x01 & resp[2];
report->readfreq = get_unaligned_be16(resp + 3);
report->freqoff = resp[5];
report->rssi = resp[6];
report->snr = resp[7];
report->lassi = resp[9];
report->hassi = resp[10];
report->mult = resp[11];
report->dev = resp[12];
report->readantcap = get_unaligned_be16(resp + 13);
report->assi = resp[15];
report->usn = resp[16];
return err;
}
static int si476x_core_cmd_fm_rsq_status_a20(struct si476x_core *core,
struct si476x_rsq_status_args *rsqargs,
struct si476x_rsq_status_report *report)
{
int err;
u8 resp[CMD_FM_RSQ_STATUS_A10_NRESP];
const u8 args[CMD_FM_RSQ_STATUS_A30_NARGS] = {
rsqargs->primary << 4 | rsqargs->rsqack << 3 |
rsqargs->attune << 2 | rsqargs->cancel << 1 |
rsqargs->stcack,
};
err = si476x_core_send_command(core, CMD_FM_RSQ_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0 || report == NULL)
return err;
report->multhint = 0x80 & resp[1];
report->multlint = 0x40 & resp[1];
report->snrhint = 0x08 & resp[1];
report->snrlint = 0x04 & resp[1];
report->rssihint = 0x02 & resp[1];
report->rssilint = 0x01 & resp[1];
report->bltf = 0x80 & resp[2];
report->snr_ready = 0x20 & resp[2];
report->rssiready = 0x08 & resp[2];
report->afcrl = 0x02 & resp[2];
report->valid = 0x01 & resp[2];
report->readfreq = get_unaligned_be16(resp + 3);
report->freqoff = resp[5];
report->rssi = resp[6];
report->snr = resp[7];
report->lassi = resp[9];
report->hassi = resp[10];
report->mult = resp[11];
report->dev = resp[12];
report->readantcap = get_unaligned_be16(resp + 13);
report->assi = resp[15];
report->usn = resp[16];
return err;
}
static int si476x_core_cmd_fm_rsq_status_a30(struct si476x_core *core,
struct si476x_rsq_status_args *rsqargs,
struct si476x_rsq_status_report *report)
{
int err;
u8 resp[CMD_FM_RSQ_STATUS_A30_NRESP];
const u8 args[CMD_FM_RSQ_STATUS_A30_NARGS] = {
rsqargs->primary << 4 | rsqargs->rsqack << 3 |
rsqargs->attune << 2 | rsqargs->cancel << 1 |
rsqargs->stcack,
};
err = si476x_core_send_command(core, CMD_FM_RSQ_STATUS,
args, ARRAY_SIZE(args),
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0 || report == NULL)
return err;
report->multhint = 0x80 & resp[1];
report->multlint = 0x40 & resp[1];
report->snrhint = 0x08 & resp[1];
report->snrlint = 0x04 & resp[1];
report->rssihint = 0x02 & resp[1];
report->rssilint = 0x01 & resp[1];
report->bltf = 0x80 & resp[2];
report->snr_ready = 0x20 & resp[2];
report->rssiready = 0x08 & resp[2];
report->injside = 0x04 & resp[2];
report->afcrl = 0x02 & resp[2];
report->valid = 0x01 & resp[2];
report->readfreq = get_unaligned_be16(resp + 3);
report->freqoff = resp[5];
report->rssi = resp[6];
report->snr = resp[7];
report->issi = resp[8];
report->lassi = resp[9];
report->hassi = resp[10];
report->mult = resp[11];
report->dev = resp[12];
report->readantcap = get_unaligned_be16(resp + 13);
report->assi = resp[15];
report->usn = resp[16];
report->pilotdev = resp[17];
report->rdsdev = resp[18];
report->assidev = resp[19];
report->strongdev = resp[20];
report->rdspi = get_unaligned_be16(resp + 21);
return err;
}
static int si476x_core_cmd_fm_tune_freq_a10(struct si476x_core *core,
struct si476x_tune_freq_args *tuneargs)
{
u8 resp[CMD_FM_TUNE_FREQ_NRESP];
const u8 args[CMD_FM_TUNE_FREQ_A10_NARGS] = {
(tuneargs->hd << 6) | (tuneargs->tunemode << 4)
| (tuneargs->smoothmetrics << 2),
msb(tuneargs->freq),
lsb(tuneargs->freq),
msb(tuneargs->antcap),
lsb(tuneargs->antcap)
};
return si476x_cmd_tune_seek_freq(core, CMD_FM_TUNE_FREQ,
args, sizeof(args),
resp, sizeof(resp));
}
static int si476x_core_cmd_fm_tune_freq_a20(struct si476x_core *core,
struct si476x_tune_freq_args *tuneargs)
{
u8 resp[CMD_FM_TUNE_FREQ_NRESP];
const u8 args[CMD_FM_TUNE_FREQ_A20_NARGS] = {
(tuneargs->hd << 6) | (tuneargs->tunemode << 4)
| (tuneargs->smoothmetrics << 2) | (tuneargs->injside),
msb(tuneargs->freq),
lsb(tuneargs->freq),
};
return si476x_cmd_tune_seek_freq(core, CMD_FM_TUNE_FREQ,
args, sizeof(args),
resp, sizeof(resp));
}
static int si476x_core_cmd_agc_status_a20(struct si476x_core *core,
struct si476x_agc_status_report *report)
{
int err;
u8 resp[CMD_AGC_STATUS_NRESP_A20];
if (!report)
return -EINVAL;
err = si476x_core_send_command(core, CMD_AGC_STATUS,
NULL, 0,
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0)
return err;
report->mxhi = resp[1] & SI476X_AGC_MXHI;
report->mxlo = resp[1] & SI476X_AGC_MXLO;
report->lnahi = resp[1] & SI476X_AGC_LNAHI;
report->lnalo = resp[1] & SI476X_AGC_LNALO;
report->fmagc1 = resp[2];
report->fmagc2 = resp[3];
report->pgagain = resp[4];
report->fmwblang = resp[5];
return err;
}
static int si476x_core_cmd_agc_status_a10(struct si476x_core *core,
struct si476x_agc_status_report *report)
{
int err;
u8 resp[CMD_AGC_STATUS_NRESP_A10];
if (!report)
return -EINVAL;
err = si476x_core_send_command(core, CMD_AGC_STATUS,
NULL, 0,
resp, ARRAY_SIZE(resp),
SI476X_DEFAULT_TIMEOUT);
if (err < 0)
return err;
report->mxhi = resp[1] & SI476X_AGC_MXHI;
report->mxlo = resp[1] & SI476X_AGC_MXLO;
report->lnahi = resp[1] & SI476X_AGC_LNAHI;
report->lnalo = resp[1] & SI476X_AGC_LNALO;
return err;
}
int si476x_core_cmd_power_up(struct si476x_core *core,
struct si476x_power_up_args *args)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].power_up(core, args);
}
int si476x_core_cmd_power_down(struct si476x_core *core,
struct si476x_power_down_args *args)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].power_down(core, args);
}
int si476x_core_cmd_fm_tune_freq(struct si476x_core *core,
struct si476x_tune_freq_args *args)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].fm_tune_freq(core, args);
}
int si476x_core_cmd_am_tune_freq(struct si476x_core *core,
struct si476x_tune_freq_args *args)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].am_tune_freq(core, args);
}
int si476x_core_cmd_fm_rsq_status(struct si476x_core *core,
struct si476x_rsq_status_args *args,
struct si476x_rsq_status_report *report)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].fm_rsq_status(core, args,
report);
}
int si476x_core_cmd_agc_status(struct si476x_core *core,
struct si476x_agc_status_report *report)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].agc_status(core, report);
}
int si476x_core_cmd_intb_pin_cfg(struct si476x_core *core,
enum si476x_intb_config intb,
enum si476x_a1_config a1)
{
BUG_ON(core->revision > SI476X_REVISION_A30 ||
core->revision == -1);
return si476x_cmds_vtable[core->revision].intb_pin_cfg(core, intb, a1);
}
