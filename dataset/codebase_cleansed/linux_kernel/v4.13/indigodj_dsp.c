static int init_hw(struct echoaudio *chip, u16 device_id, u16 subdevice_id)
{
int err;
if (snd_BUG_ON((subdevice_id & 0xfff0) != INDIGO_DJ))
return -ENODEV;
if ((err = init_dsp_comm_page(chip))) {
dev_err(chip->card->dev,
"init_hw - could not initialize DSP comm page\n");
return err;
}
chip->device_id = device_id;
chip->subdevice_id = subdevice_id;
chip->bad_board = true;
chip->dsp_code_to_load = FW_INDIGO_DJ_DSP;
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
u32 control_reg;
switch (rate) {
case 96000:
control_reg = MIA_96000;
break;
case 88200:
control_reg = MIA_88200;
break;
case 48000:
control_reg = MIA_48000;
break;
case 44100:
control_reg = MIA_44100;
break;
case 32000:
control_reg = MIA_32000;
break;
default:
dev_err(chip->card->dev,
"set_sample_rate: %d invalid!\n", rate);
return -EINVAL;
}
if (control_reg != le32_to_cpu(chip->comm_page->control_register)) {
if (wait_handshake(chip))
return -EIO;
chip->comm_page->sample_rate = cpu_to_le32(rate);
chip->comm_page->control_register = cpu_to_le32(control_reg);
chip->sample_rate = rate;
clear_handshake(chip);
return send_vector(chip, DSP_VC_UPDATE_CLOCKS);
}
return 0;
}
static int set_vmixer_gain(struct echoaudio *chip, u16 output, u16 pipe,
int gain)
{
int index;
if (snd_BUG_ON(pipe >= num_pipes_out(chip) ||
output >= num_busses_out(chip)))
return -EINVAL;
if (wait_handshake(chip))
return -EIO;
chip->vmixer_gain[output][pipe] = gain;
index = output * num_pipes_out(chip) + pipe;
chip->comm_page->vmixer[index] = gain;
dev_dbg(chip->card->dev,
"set_vmixer_gain: pipe %d, out %d = %d\n", pipe, output, gain);
return 0;
}
static int update_vmixer_level(struct echoaudio *chip)
{
if (wait_handshake(chip))
return -EIO;
clear_handshake(chip);
return send_vector(chip, DSP_VC_SET_VMIXER_GAIN);
}
