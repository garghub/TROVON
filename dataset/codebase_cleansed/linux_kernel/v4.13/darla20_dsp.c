static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
int err;
if (snd_BUG_ON((subdevice_id & 0xfff0) != DARLA20))
return -ENODEV;
if ((err = init_dsp_comm_page(chip))) {
dev_err(chip->card->dev,
"init_hw: could not initialize DSP comm page\n");
return err;
}
chip->device_id = device_id;
chip->subdevice_id = subdevice_id;
chip->bad_board = true;
chip->dsp_code_to_load = FW_DARLA20_DSP;
chip->spdif_status = GD_SPDIF_STATUS_UNDEF;
chip->clock_state = GD_CLOCK_UNDEF;
chip->asic_loaded = true;
chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL;
if ((err = load_firmware(chip)) < 0)
return err;
chip->bad_board = false;
return err;
}
static int set_mixer_defaults(struct echoaudio *chip)
{
return init_line_levels(chip);
}
static u32 detect_input_clocks(const struct echoaudio *chip)
{
return ECHO_CLOCK_BIT_INTERNAL;
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
