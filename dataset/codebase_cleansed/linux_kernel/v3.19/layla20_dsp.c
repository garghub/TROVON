static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
int err;
if (snd_BUG_ON((subdevice_id & 0xfff0) != LAYLA20))
return -ENODEV;
if ((err = init_dsp_comm_page(chip))) {
dev_err(chip->card->dev,
"init_hw - could not initialize DSP comm page\n");
return err;
}
chip->device_id = device_id;
chip->subdevice_id = subdevice_id;
chip->bad_board = TRUE;
chip->has_midi = TRUE;
chip->dsp_code_to_load = FW_LAYLA20_DSP;
chip->input_clock_types =
ECHO_CLOCK_BIT_INTERNAL | ECHO_CLOCK_BIT_SPDIF |
ECHO_CLOCK_BIT_WORD | ECHO_CLOCK_BIT_SUPER;
chip->output_clock_types =
ECHO_CLOCK_BIT_WORD | ECHO_CLOCK_BIT_SUPER;
if ((err = load_firmware(chip)) < 0)
return err;
chip->bad_board = FALSE;
return err;
}
static int set_mixer_defaults(struct echoaudio *chip)
{
chip->professional_spdif = FALSE;
return init_line_levels(chip);
}
static u32 detect_input_clocks(const struct echoaudio *chip)
{
u32 clocks_from_dsp, clock_bits;
clocks_from_dsp = le32_to_cpu(chip->comm_page->status_clocks);
clock_bits = ECHO_CLOCK_BIT_INTERNAL;
if (clocks_from_dsp & GLDM_CLOCK_DETECT_BIT_SPDIF)
clock_bits |= ECHO_CLOCK_BIT_SPDIF;
if (clocks_from_dsp & GLDM_CLOCK_DETECT_BIT_WORD) {
if (clocks_from_dsp & GLDM_CLOCK_DETECT_BIT_SUPER)
clock_bits |= ECHO_CLOCK_BIT_SUPER;
else
clock_bits |= ECHO_CLOCK_BIT_WORD;
}
return clock_bits;
}
static int check_asic_status(struct echoaudio *chip)
{
u32 asic_status;
int goodcnt, i;
chip->asic_loaded = FALSE;
for (i = goodcnt = 0; i < 5; i++) {
send_vector(chip, DSP_VC_TEST_ASIC);
if (read_dsp(chip, &asic_status) < 0) {
dev_err(chip->card->dev,
"check_asic_status: failed on read_dsp\n");
return -EIO;
}
if (asic_status == ASIC_ALREADY_LOADED) {
if (++goodcnt == 3) {
chip->asic_loaded = TRUE;
return 0;
}
}
}
return -EIO;
}
static int load_asic(struct echoaudio *chip)
{
int err;
if (chip->asic_loaded)
return 0;
err = load_asic_generic(chip, DSP_FNC_LOAD_LAYLA_ASIC,
FW_LAYLA20_ASIC);
if (err < 0)
return err;
return check_asic_status(chip);
}
static int set_sample_rate(struct echoaudio *chip, u32 rate)
{
if (snd_BUG_ON(rate < 8000 || rate > 50000))
return -EINVAL;
if (chip->input_clock != ECHO_CLOCK_INTERNAL) {
dev_warn(chip->card->dev,
"Cannot set sample rate - clock not set to CLK_CLOCKININTERNAL\n");
chip->comm_page->sample_rate = cpu_to_le32(rate);
chip->sample_rate = rate;
return 0;
}
if (wait_handshake(chip))
return -EIO;
dev_dbg(chip->card->dev, "set_sample_rate(%d)\n", rate);
chip->sample_rate = rate;
chip->comm_page->sample_rate = cpu_to_le32(rate);
clear_handshake(chip);
return send_vector(chip, DSP_VC_SET_LAYLA_SAMPLE_RATE);
}
static int set_input_clock(struct echoaudio *chip, u16 clock_source)
{
u16 clock;
u32 rate;
rate = 0;
switch (clock_source) {
case ECHO_CLOCK_INTERNAL:
rate = chip->sample_rate;
clock = LAYLA20_CLOCK_INTERNAL;
break;
case ECHO_CLOCK_SPDIF:
clock = LAYLA20_CLOCK_SPDIF;
break;
case ECHO_CLOCK_WORD:
clock = LAYLA20_CLOCK_WORD;
break;
case ECHO_CLOCK_SUPER:
clock = LAYLA20_CLOCK_SUPER;
break;
default:
dev_err(chip->card->dev,
"Input clock 0x%x not supported for Layla24\n",
clock_source);
return -EINVAL;
}
chip->input_clock = clock_source;
chip->comm_page->input_clock = cpu_to_le16(clock);
clear_handshake(chip);
send_vector(chip, DSP_VC_UPDATE_CLOCKS);
if (rate)
set_sample_rate(chip, rate);
return 0;
}
static int set_output_clock(struct echoaudio *chip, u16 clock)
{
switch (clock) {
case ECHO_CLOCK_SUPER:
clock = LAYLA20_OUTPUT_CLOCK_SUPER;
break;
case ECHO_CLOCK_WORD:
clock = LAYLA20_OUTPUT_CLOCK_WORD;
break;
default:
dev_err(chip->card->dev, "set_output_clock wrong clock\n");
return -EINVAL;
}
if (wait_handshake(chip))
return -EIO;
chip->comm_page->output_clock = cpu_to_le16(clock);
chip->output_clock = clock;
clear_handshake(chip);
return send_vector(chip, DSP_VC_UPDATE_CLOCKS);
}
static int set_input_gain(struct echoaudio *chip, u16 input, int gain)
{
if (snd_BUG_ON(input >= num_busses_in(chip)))
return -EINVAL;
if (wait_handshake(chip))
return -EIO;
chip->input_gain[input] = gain;
gain += GL20_INPUT_GAIN_MAGIC_NUMBER;
chip->comm_page->line_in_level[input] = gain;
return 0;
}
static int update_flags(struct echoaudio *chip)
{
if (wait_handshake(chip))
return -EIO;
clear_handshake(chip);
return send_vector(chip, DSP_VC_UPDATE_FLAGS);
}
static int set_professional_spdif(struct echoaudio *chip, char prof)
{
if (prof)
chip->comm_page->flags |=
cpu_to_le32(DSP_FLAG_PROFESSIONAL_SPDIF);
else
chip->comm_page->flags &=
~cpu_to_le32(DSP_FLAG_PROFESSIONAL_SPDIF);
chip->professional_spdif = prof;
return update_flags(chip);
}
