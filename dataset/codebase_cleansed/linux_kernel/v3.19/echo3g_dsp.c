static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
int err;
local_irq_enable();
if (snd_BUG_ON((subdevice_id & 0xfff0) != ECHO3G))
return -ENODEV;
if ((err = init_dsp_comm_page(chip))) {
dev_err(chip->card->dev,
"init_hw - could not initialize DSP comm page\n");
return err;
}
chip->comm_page->e3g_frq_register =
cpu_to_le32((E3G_MAGIC_NUMBER / 48000) - 2);
chip->device_id = device_id;
chip->subdevice_id = subdevice_id;
chip->bad_board = TRUE;
chip->has_midi = TRUE;
chip->dsp_code_to_load = FW_ECHO3G_DSP;
err = load_firmware(chip);
if (err < 0) {
return err;
} else if (err == E3G_GINA3G_BOX_TYPE) {
chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL |
ECHO_CLOCK_BIT_SPDIF |
ECHO_CLOCK_BIT_ADAT;
chip->card_name = "Gina3G";
chip->px_digital_out = chip->bx_digital_out = 6;
chip->px_analog_in = chip->bx_analog_in = 14;
chip->px_digital_in = chip->bx_digital_in = 16;
chip->px_num = chip->bx_num = 24;
chip->has_phantom_power = TRUE;
chip->hasnt_input_nominal_level = TRUE;
} else if (err == E3G_LAYLA3G_BOX_TYPE) {
chip->input_clock_types = ECHO_CLOCK_BIT_INTERNAL |
ECHO_CLOCK_BIT_SPDIF |
ECHO_CLOCK_BIT_ADAT |
ECHO_CLOCK_BIT_WORD;
chip->card_name = "Layla3G";
chip->px_digital_out = chip->bx_digital_out = 8;
chip->px_analog_in = chip->bx_analog_in = 16;
chip->px_digital_in = chip->bx_digital_in = 24;
chip->px_num = chip->bx_num = 32;
} else {
return -ENODEV;
}
chip->digital_modes = ECHOCAPS_HAS_DIGITAL_MODE_SPDIF_RCA |
ECHOCAPS_HAS_DIGITAL_MODE_SPDIF_OPTICAL |
ECHOCAPS_HAS_DIGITAL_MODE_ADAT;
return err;
}
static int set_mixer_defaults(struct echoaudio *chip)
{
chip->digital_mode = DIGITAL_MODE_SPDIF_RCA;
chip->professional_spdif = FALSE;
chip->non_audio_spdif = FALSE;
chip->bad_board = FALSE;
chip->phantom_power = FALSE;
return init_line_levels(chip);
}
static int set_phantom_power(struct echoaudio *chip, char on)
{
u32 control_reg = le32_to_cpu(chip->comm_page->control_register);
if (on)
control_reg |= E3G_PHANTOM_POWER;
else
control_reg &= ~E3G_PHANTOM_POWER;
chip->phantom_power = on;
return write_control_reg(chip, control_reg,
le32_to_cpu(chip->comm_page->e3g_frq_register),
0);
}
