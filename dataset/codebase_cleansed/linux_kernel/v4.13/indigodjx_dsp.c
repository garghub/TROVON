static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
int err;
if (snd_BUG_ON((subdevice_id & 0xfff0) != INDIGO_DJX))
return -ENODEV;
err = init_dsp_comm_page(chip);
if (err < 0) {
dev_err(chip->card->dev,
"init_hw - could not initialize DSP comm page\n");
return err;
}
chip->device_id = device_id;
chip->subdevice_id = subdevice_id;
chip->bad_board = true;
chip->dsp_code_to_load = FW_INDIGO_DJX_DSP;
chip->asic_loaded = true;
chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL;
err = load_firmware(chip);
if (err < 0)
return err;
chip->bad_board = false;
return err;
}
static int set_mixer_defaults(struct echoaudio *chip)
{
return init_line_levels(chip);
}
