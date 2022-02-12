static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
int err;
DE_INIT(("init_hw() - Gina20\n"));
if (snd_BUG_ON((subdevice_id & 0xfff0) != GINA20))
return -ENODEV;
if ((err = init_dsp_comm_page(chip))) {
DE_INIT(("init_hw - could not initialize DSP comm page\n"));
return err;
}
chip->device_id = device_id;
chip->subdevice_id = subdevice_id;
chip->bad_board = TRUE;
chip->dsp_code_to_load = FW_GINA20_DSP;
chip->spdif_status = GD_SPDIF_STATUS_UNDEF;
chip->clock_state = GD_CLOCK_UNDEF;
chip->asic_loaded = TRUE;
chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL |
ECHO_CLOCK_BIT_SPDIF;
if ((err = load_firmware(chip)) < 0)
return err;
chip->bad_board = FALSE;
DE_INIT(("init_hw done\n"));
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
return clock_bits;
}
static int load_asic(struct echoaudio *chip)
{
return 0;
}
static int set_sample_rate(struct echoaudio *chip, u32 rate)
{
u8 clock_state, spdif_status;
if (wait_handshake(chip))
return -EIO;
switch (rate) {
case 44100:
clock_state = GD_CLOCK_44;
spdif_status = GD_SPDIF_STATUS_44;
break;
case 48000:
clock_state = GD_CLOCK_48;
spdif_status = GD_SPDIF_STATUS_48;
break;
default:
clock_state = GD_CLOCK_NOCHANGE;
spdif_status = GD_SPDIF_STATUS_NOCHANGE;
break;
}
if (chip->clock_state == clock_state)
clock_state = GD_CLOCK_NOCHANGE;
if (spdif_status == chip->spdif_status)
spdif_status = GD_SPDIF_STATUS_NOCHANGE;
chip->comm_page->sample_rate = cpu_to_le32(rate);
chip->comm_page->gd_clock_state = clock_state;
chip->comm_page->gd_spdif_status = spdif_status;
chip->comm_page->gd_resampler_state = 3;
if (clock_state != GD_CLOCK_NOCHANGE)
chip->clock_state = clock_state;
if (spdif_status != GD_SPDIF_STATUS_NOCHANGE)
chip->spdif_status = spdif_status;
chip->sample_rate = rate;
clear_handshake(chip);
return send_vector(chip, DSP_VC_SET_GD_AUDIO_STATE);
}
static int set_input_clock(struct echoaudio *chip, u16 clock)
{
DE_ACT(("set_input_clock:\n"));
switch (clock) {
case ECHO_CLOCK_INTERNAL:
chip->clock_state = GD_CLOCK_UNDEF;
chip->spdif_status = GD_SPDIF_STATUS_UNDEF;
set_sample_rate(chip, chip->sample_rate);
chip->input_clock = clock;
DE_ACT(("Set Gina clock to INTERNAL\n"));
break;
case ECHO_CLOCK_SPDIF:
chip->comm_page->gd_clock_state = GD_CLOCK_SPDIFIN;
chip->comm_page->gd_spdif_status = GD_SPDIF_STATUS_NOCHANGE;
clear_handshake(chip);
send_vector(chip, DSP_VC_SET_GD_AUDIO_STATE);
chip->clock_state = GD_CLOCK_SPDIFIN;
DE_ACT(("Set Gina20 clock to SPDIF\n"));
chip->input_clock = clock;
break;
default:
return -EINVAL;
}
return 0;
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
DE_ACT(("set_professional_spdif %d\n", prof));
if (prof)
chip->comm_page->flags |=
cpu_to_le32(DSP_FLAG_PROFESSIONAL_SPDIF);
else
chip->comm_page->flags &=
~cpu_to_le32(DSP_FLAG_PROFESSIONAL_SPDIF);
chip->professional_spdif = prof;
return update_flags(chip);
}
