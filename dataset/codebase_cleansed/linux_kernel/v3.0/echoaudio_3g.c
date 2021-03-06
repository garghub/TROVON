static int check_asic_status(struct echoaudio *chip)
{
u32 box_status;
if (wait_handshake(chip))
return -EIO;
chip->comm_page->ext_box_status = cpu_to_le32(E3G_ASIC_NOT_LOADED);
chip->asic_loaded = FALSE;
clear_handshake(chip);
send_vector(chip, DSP_VC_TEST_ASIC);
if (wait_handshake(chip)) {
chip->dsp_code = NULL;
return -EIO;
}
box_status = le32_to_cpu(chip->comm_page->ext_box_status);
DE_INIT(("box_status=%x\n", box_status));
if (box_status == E3G_ASIC_NOT_LOADED)
return -ENODEV;
chip->asic_loaded = TRUE;
return box_status & E3G_BOX_TYPE_MASK;
}
static inline u32 get_frq_reg(struct echoaudio *chip)
{
return le32_to_cpu(chip->comm_page->e3g_frq_register);
}
static int write_control_reg(struct echoaudio *chip, u32 ctl, u32 frq,
char force)
{
if (wait_handshake(chip))
return -EIO;
DE_ACT(("WriteControlReg: Setting 0x%x, 0x%x\n", ctl, frq));
ctl = cpu_to_le32(ctl);
frq = cpu_to_le32(frq);
if (ctl != chip->comm_page->control_register ||
frq != chip->comm_page->e3g_frq_register || force) {
chip->comm_page->e3g_frq_register = frq;
chip->comm_page->control_register = ctl;
clear_handshake(chip);
return send_vector(chip, DSP_VC_WRITE_CONTROL_REG);
}
DE_ACT(("WriteControlReg: not written, no change\n"));
return 0;
}
static int set_digital_mode(struct echoaudio *chip, u8 mode)
{
u8 previous_mode;
int err, i, o;
if (snd_BUG_ON(chip->pipe_alloc_mask))
return -EAGAIN;
if (snd_BUG_ON(!(chip->digital_modes & (1 << mode))))
return -EINVAL;
previous_mode = chip->digital_mode;
err = dsp_set_digital_mode(chip, mode);
if (err >= 0 && previous_mode != mode &&
(previous_mode == DIGITAL_MODE_ADAT || mode == DIGITAL_MODE_ADAT)) {
spin_lock_irq(&chip->lock);
for (o = 0; o < num_busses_out(chip); o++)
for (i = 0; i < num_busses_in(chip); i++)
set_monitor_gain(chip, o, i,
chip->monitor_gain[o][i]);
#ifdef ECHOCARD_HAS_INPUT_GAIN
for (i = 0; i < num_busses_in(chip); i++)
set_input_gain(chip, i, chip->input_gain[i]);
update_input_line_level(chip);
#endif
for (o = 0; o < num_busses_out(chip); o++)
set_output_gain(chip, o, chip->output_gain[o]);
update_output_line_level(chip);
spin_unlock_irq(&chip->lock);
}
return err;
}
static u32 set_spdif_bits(struct echoaudio *chip, u32 control_reg, u32 rate)
{
control_reg &= E3G_SPDIF_FORMAT_CLEAR_MASK;
switch (rate) {
case 32000 :
control_reg |= E3G_SPDIF_SAMPLE_RATE0 | E3G_SPDIF_SAMPLE_RATE1;
break;
case 44100 :
if (chip->professional_spdif)
control_reg |= E3G_SPDIF_SAMPLE_RATE0;
break;
case 48000 :
control_reg |= E3G_SPDIF_SAMPLE_RATE1;
break;
}
if (chip->professional_spdif)
control_reg |= E3G_SPDIF_PRO_MODE;
if (chip->non_audio_spdif)
control_reg |= E3G_SPDIF_NOT_AUDIO;
control_reg |= E3G_SPDIF_24_BIT | E3G_SPDIF_TWO_CHANNEL |
E3G_SPDIF_COPY_PERMIT;
return control_reg;
}
static int set_professional_spdif(struct echoaudio *chip, char prof)
{
u32 control_reg;
control_reg = le32_to_cpu(chip->comm_page->control_register);
chip->professional_spdif = prof;
control_reg = set_spdif_bits(chip, control_reg, chip->sample_rate);
return write_control_reg(chip, control_reg, get_frq_reg(chip), 0);
}
static u32 detect_input_clocks(const struct echoaudio *chip)
{
u32 clocks_from_dsp, clock_bits;
clocks_from_dsp = le32_to_cpu(chip->comm_page->status_clocks);
clock_bits = ECHO_CLOCK_BIT_INTERNAL;
if (clocks_from_dsp & E3G_CLOCK_DETECT_BIT_WORD)
clock_bits |= ECHO_CLOCK_BIT_WORD;
switch(chip->digital_mode) {
case DIGITAL_MODE_SPDIF_RCA:
case DIGITAL_MODE_SPDIF_OPTICAL:
if (clocks_from_dsp & E3G_CLOCK_DETECT_BIT_SPDIF)
clock_bits |= ECHO_CLOCK_BIT_SPDIF;
break;
case DIGITAL_MODE_ADAT:
if (clocks_from_dsp & E3G_CLOCK_DETECT_BIT_ADAT)
clock_bits |= ECHO_CLOCK_BIT_ADAT;
break;
}
return clock_bits;
}
static int load_asic(struct echoaudio *chip)
{
int box_type, err;
if (chip->asic_loaded)
return 0;
mdelay(2);
err = load_asic_generic(chip, DSP_FNC_LOAD_3G_ASIC, FW_3G_ASIC);
if (err < 0)
return err;
chip->asic_code = FW_3G_ASIC;
msleep(1000);
box_type = check_asic_status(chip);
if (box_type >= 0) {
err = write_control_reg(chip, E3G_48KHZ,
E3G_FREQ_REG_DEFAULT, TRUE);
if (err < 0)
return err;
}
return box_type;
}
static int set_sample_rate(struct echoaudio *chip, u32 rate)
{
u32 control_reg, clock, base_rate, frq_reg;
if (chip->input_clock != ECHO_CLOCK_INTERNAL) {
DE_ACT(("set_sample_rate: Cannot set sample rate - "
"clock not set to CLK_CLOCKININTERNAL\n"));
chip->comm_page->sample_rate = cpu_to_le32(rate);
chip->sample_rate = rate;
set_input_clock(chip, chip->input_clock);
return 0;
}
if (snd_BUG_ON(rate >= 50000 &&
chip->digital_mode == DIGITAL_MODE_ADAT))
return -EINVAL;
clock = 0;
control_reg = le32_to_cpu(chip->comm_page->control_register);
control_reg &= E3G_CLOCK_CLEAR_MASK;
switch (rate) {
case 96000:
clock = E3G_96KHZ;
break;
case 88200:
clock = E3G_88KHZ;
break;
case 48000:
clock = E3G_48KHZ;
break;
case 44100:
clock = E3G_44KHZ;
break;
case 32000:
clock = E3G_32KHZ;
break;
default:
clock = E3G_CONTINUOUS_CLOCK;
if (rate > 50000)
clock |= E3G_DOUBLE_SPEED_MODE;
break;
}
control_reg |= clock;
control_reg = set_spdif_bits(chip, control_reg, rate);
base_rate = rate;
if (base_rate > 50000)
base_rate /= 2;
if (base_rate < 32000)
base_rate = 32000;
frq_reg = E3G_MAGIC_NUMBER / base_rate - 2;
if (frq_reg > E3G_FREQ_REG_MAX)
frq_reg = E3G_FREQ_REG_MAX;
chip->comm_page->sample_rate = cpu_to_le32(rate);
chip->sample_rate = rate;
DE_ACT(("SetSampleRate: %d clock %x\n", rate, control_reg));
return write_control_reg(chip, control_reg, frq_reg, 0);
}
static int set_input_clock(struct echoaudio *chip, u16 clock)
{
u32 control_reg, clocks_from_dsp;
DE_ACT(("set_input_clock:\n"));
control_reg = le32_to_cpu(chip->comm_page->control_register) &
E3G_CLOCK_CLEAR_MASK;
clocks_from_dsp = le32_to_cpu(chip->comm_page->status_clocks);
switch (clock) {
case ECHO_CLOCK_INTERNAL:
DE_ACT(("Set Echo3G clock to INTERNAL\n"));
chip->input_clock = ECHO_CLOCK_INTERNAL;
return set_sample_rate(chip, chip->sample_rate);
case ECHO_CLOCK_SPDIF:
if (chip->digital_mode == DIGITAL_MODE_ADAT)
return -EAGAIN;
DE_ACT(("Set Echo3G clock to SPDIF\n"));
control_reg |= E3G_SPDIF_CLOCK;
if (clocks_from_dsp & E3G_CLOCK_DETECT_BIT_SPDIF96)
control_reg |= E3G_DOUBLE_SPEED_MODE;
else
control_reg &= ~E3G_DOUBLE_SPEED_MODE;
break;
case ECHO_CLOCK_ADAT:
if (chip->digital_mode != DIGITAL_MODE_ADAT)
return -EAGAIN;
DE_ACT(("Set Echo3G clock to ADAT\n"));
control_reg |= E3G_ADAT_CLOCK;
control_reg &= ~E3G_DOUBLE_SPEED_MODE;
break;
case ECHO_CLOCK_WORD:
DE_ACT(("Set Echo3G clock to WORD\n"));
control_reg |= E3G_WORD_CLOCK;
if (clocks_from_dsp & E3G_CLOCK_DETECT_BIT_WORD96)
control_reg |= E3G_DOUBLE_SPEED_MODE;
else
control_reg &= ~E3G_DOUBLE_SPEED_MODE;
break;
default:
DE_ACT(("Input clock 0x%x not supported for Echo3G\n", clock));
return -EINVAL;
}
chip->input_clock = clock;
return write_control_reg(chip, control_reg, get_frq_reg(chip), 1);
}
static int dsp_set_digital_mode(struct echoaudio *chip, u8 mode)
{
u32 control_reg;
int err, incompatible_clock;
incompatible_clock = FALSE;
switch (mode) {
case DIGITAL_MODE_SPDIF_OPTICAL:
case DIGITAL_MODE_SPDIF_RCA:
if (chip->input_clock == ECHO_CLOCK_ADAT)
incompatible_clock = TRUE;
break;
case DIGITAL_MODE_ADAT:
if (chip->input_clock == ECHO_CLOCK_SPDIF)
incompatible_clock = TRUE;
break;
default:
DE_ACT(("Digital mode not supported: %d\n", mode));
return -EINVAL;
}
spin_lock_irq(&chip->lock);
if (incompatible_clock) {
chip->sample_rate = 48000;
set_input_clock(chip, ECHO_CLOCK_INTERNAL);
}
control_reg = le32_to_cpu(chip->comm_page->control_register);
control_reg &= E3G_DIGITAL_MODE_CLEAR_MASK;
switch (mode) {
case DIGITAL_MODE_SPDIF_OPTICAL:
control_reg |= E3G_SPDIF_OPTICAL_MODE;
break;
case DIGITAL_MODE_SPDIF_RCA:
break;
case DIGITAL_MODE_ADAT:
control_reg |= E3G_ADAT_MODE;
control_reg &= ~E3G_DOUBLE_SPEED_MODE;
break;
}
err = write_control_reg(chip, control_reg, get_frq_reg(chip), 1);
spin_unlock_irq(&chip->lock);
if (err < 0)
return err;
chip->digital_mode = mode;
DE_ACT(("set_digital_mode(%d)\n", chip->digital_mode));
return incompatible_clock;
}
