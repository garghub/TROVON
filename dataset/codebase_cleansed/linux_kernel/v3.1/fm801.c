static int snd_fm801_update_bits(struct fm801 *chip, unsigned short reg,
unsigned short mask, unsigned short value)
{
int change;
unsigned long flags;
unsigned short old, new;
spin_lock_irqsave(&chip->reg_lock, flags);
old = inw(chip->port + reg);
new = (old & ~mask) | value;
change = old != new;
if (change)
outw(new, chip->port + reg);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static void snd_fm801_codec_write(struct snd_ac97 *ac97,
unsigned short reg,
unsigned short val)
{
struct fm801 *chip = ac97->private_data;
int idx;
for (idx = 0; idx < 100; idx++) {
if (!(inw(FM801_REG(chip, AC97_CMD)) & FM801_AC97_BUSY))
goto ok1;
udelay(10);
}
snd_printk(KERN_ERR "AC'97 interface is busy (1)\n");
return;
ok1:
outw(val, FM801_REG(chip, AC97_DATA));
outw(reg | (ac97->addr << FM801_AC97_ADDR_SHIFT), FM801_REG(chip, AC97_CMD));
for (idx = 0; idx < 1000; idx++) {
if (!(inw(FM801_REG(chip, AC97_CMD)) & FM801_AC97_BUSY))
return;
udelay(10);
}
snd_printk(KERN_ERR "AC'97 interface #%d is busy (2)\n", ac97->num);
}
static unsigned short snd_fm801_codec_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct fm801 *chip = ac97->private_data;
int idx;
for (idx = 0; idx < 100; idx++) {
if (!(inw(FM801_REG(chip, AC97_CMD)) & FM801_AC97_BUSY))
goto ok1;
udelay(10);
}
snd_printk(KERN_ERR "AC'97 interface is busy (1)\n");
return 0;
ok1:
outw(reg | (ac97->addr << FM801_AC97_ADDR_SHIFT) | FM801_AC97_READ,
FM801_REG(chip, AC97_CMD));
for (idx = 0; idx < 100; idx++) {
if (!(inw(FM801_REG(chip, AC97_CMD)) & FM801_AC97_BUSY))
goto ok2;
udelay(10);
}
snd_printk(KERN_ERR "AC'97 interface #%d is busy (2)\n", ac97->num);
return 0;
ok2:
for (idx = 0; idx < 1000; idx++) {
if (inw(FM801_REG(chip, AC97_CMD)) & FM801_AC97_VALID)
goto ok3;
udelay(10);
}
snd_printk(KERN_ERR "AC'97 interface #%d is not valid (2)\n", ac97->num);
return 0;
ok3:
return inw(FM801_REG(chip, AC97_DATA));
}
static unsigned short snd_fm801_rate_bits(unsigned int rate)
{
unsigned int idx;
for (idx = 0; idx < ARRAY_SIZE(rates); idx++)
if (rates[idx] == rate)
return idx;
snd_BUG();
return ARRAY_SIZE(rates) - 1;
}
static int snd_fm801_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
chip->ply_ctrl &= ~(FM801_BUF1_LAST |
FM801_BUF2_LAST |
FM801_PAUSE);
chip->ply_ctrl |= FM801_START |
FM801_IMMED_STOP;
break;
case SNDRV_PCM_TRIGGER_STOP:
chip->ply_ctrl &= ~(FM801_START | FM801_PAUSE);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
chip->ply_ctrl |= FM801_PAUSE;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
chip->ply_ctrl &= ~FM801_PAUSE;
break;
default:
spin_unlock(&chip->reg_lock);
snd_BUG();
return -EINVAL;
}
outw(chip->ply_ctrl, FM801_REG(chip, PLY_CTRL));
spin_unlock(&chip->reg_lock);
return 0;
}
static int snd_fm801_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
chip->cap_ctrl &= ~(FM801_BUF1_LAST |
FM801_BUF2_LAST |
FM801_PAUSE);
chip->cap_ctrl |= FM801_START |
FM801_IMMED_STOP;
break;
case SNDRV_PCM_TRIGGER_STOP:
chip->cap_ctrl &= ~(FM801_START | FM801_PAUSE);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
chip->cap_ctrl |= FM801_PAUSE;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
chip->cap_ctrl &= ~FM801_PAUSE;
break;
default:
spin_unlock(&chip->reg_lock);
snd_BUG();
return -EINVAL;
}
outw(chip->cap_ctrl, FM801_REG(chip, CAP_CTRL));
spin_unlock(&chip->reg_lock);
return 0;
}
static int snd_fm801_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_fm801_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_fm801_playback_prepare(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
chip->ply_size = snd_pcm_lib_buffer_bytes(substream);
chip->ply_count = snd_pcm_lib_period_bytes(substream);
spin_lock_irq(&chip->reg_lock);
chip->ply_ctrl &= ~(FM801_START | FM801_16BIT |
FM801_STEREO | FM801_RATE_MASK |
FM801_CHANNELS_MASK);
if (snd_pcm_format_width(runtime->format) == 16)
chip->ply_ctrl |= FM801_16BIT;
if (runtime->channels > 1) {
chip->ply_ctrl |= FM801_STEREO;
if (runtime->channels == 4)
chip->ply_ctrl |= FM801_CHANNELS_4;
else if (runtime->channels == 6)
chip->ply_ctrl |= FM801_CHANNELS_6;
}
chip->ply_ctrl |= snd_fm801_rate_bits(runtime->rate) << FM801_RATE_SHIFT;
chip->ply_buf = 0;
outw(chip->ply_ctrl, FM801_REG(chip, PLY_CTRL));
outw(chip->ply_count - 1, FM801_REG(chip, PLY_COUNT));
chip->ply_buffer = runtime->dma_addr;
chip->ply_pos = 0;
outl(chip->ply_buffer, FM801_REG(chip, PLY_BUF1));
outl(chip->ply_buffer + (chip->ply_count % chip->ply_size), FM801_REG(chip, PLY_BUF2));
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_fm801_capture_prepare(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
chip->cap_size = snd_pcm_lib_buffer_bytes(substream);
chip->cap_count = snd_pcm_lib_period_bytes(substream);
spin_lock_irq(&chip->reg_lock);
chip->cap_ctrl &= ~(FM801_START | FM801_16BIT |
FM801_STEREO | FM801_RATE_MASK);
if (snd_pcm_format_width(runtime->format) == 16)
chip->cap_ctrl |= FM801_16BIT;
if (runtime->channels > 1)
chip->cap_ctrl |= FM801_STEREO;
chip->cap_ctrl |= snd_fm801_rate_bits(runtime->rate) << FM801_RATE_SHIFT;
chip->cap_buf = 0;
outw(chip->cap_ctrl, FM801_REG(chip, CAP_CTRL));
outw(chip->cap_count - 1, FM801_REG(chip, CAP_COUNT));
chip->cap_buffer = runtime->dma_addr;
chip->cap_pos = 0;
outl(chip->cap_buffer, FM801_REG(chip, CAP_BUF1));
outl(chip->cap_buffer + (chip->cap_count % chip->cap_size), FM801_REG(chip, CAP_BUF2));
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static snd_pcm_uframes_t snd_fm801_playback_pointer(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(chip->ply_ctrl & FM801_START))
return 0;
spin_lock(&chip->reg_lock);
ptr = chip->ply_pos + (chip->ply_count - 1) - inw(FM801_REG(chip, PLY_COUNT));
if (inw(FM801_REG(chip, IRQ_STATUS)) & FM801_IRQ_PLAYBACK) {
ptr += chip->ply_count;
ptr %= chip->ply_size;
}
spin_unlock(&chip->reg_lock);
return bytes_to_frames(substream->runtime, ptr);
}
static snd_pcm_uframes_t snd_fm801_capture_pointer(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(chip->cap_ctrl & FM801_START))
return 0;
spin_lock(&chip->reg_lock);
ptr = chip->cap_pos + (chip->cap_count - 1) - inw(FM801_REG(chip, CAP_COUNT));
if (inw(FM801_REG(chip, IRQ_STATUS)) & FM801_IRQ_CAPTURE) {
ptr += chip->cap_count;
ptr %= chip->cap_size;
}
spin_unlock(&chip->reg_lock);
return bytes_to_frames(substream->runtime, ptr);
}
static irqreturn_t snd_fm801_interrupt(int irq, void *dev_id)
{
struct fm801 *chip = dev_id;
unsigned short status;
unsigned int tmp;
status = inw(FM801_REG(chip, IRQ_STATUS));
status &= FM801_IRQ_PLAYBACK|FM801_IRQ_CAPTURE|FM801_IRQ_MPU|FM801_IRQ_VOLUME;
if (! status)
return IRQ_NONE;
outw(status, FM801_REG(chip, IRQ_STATUS));
if (chip->pcm && (status & FM801_IRQ_PLAYBACK) && chip->playback_substream) {
spin_lock(&chip->reg_lock);
chip->ply_buf++;
chip->ply_pos += chip->ply_count;
chip->ply_pos %= chip->ply_size;
tmp = chip->ply_pos + chip->ply_count;
tmp %= chip->ply_size;
outl(chip->ply_buffer + tmp,
(chip->ply_buf & 1) ?
FM801_REG(chip, PLY_BUF1) :
FM801_REG(chip, PLY_BUF2));
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(chip->playback_substream);
}
if (chip->pcm && (status & FM801_IRQ_CAPTURE) && chip->capture_substream) {
spin_lock(&chip->reg_lock);
chip->cap_buf++;
chip->cap_pos += chip->cap_count;
chip->cap_pos %= chip->cap_size;
tmp = chip->cap_pos + chip->cap_count;
tmp %= chip->cap_size;
outl(chip->cap_buffer + tmp,
(chip->cap_buf & 1) ?
FM801_REG(chip, CAP_BUF1) :
FM801_REG(chip, CAP_BUF2));
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(chip->capture_substream);
}
if (chip->rmidi && (status & FM801_IRQ_MPU))
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
if (status & FM801_IRQ_VOLUME)
;
return IRQ_HANDLED;
}
static int snd_fm801_playback_open(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
chip->playback_substream = substream;
runtime->hw = snd_fm801_playback;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates);
if (chip->multichannel) {
runtime->hw.channels_max = 6;
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
&hw_constraints_channels);
}
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
return 0;
}
static int snd_fm801_capture_open(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
chip->capture_substream = substream;
runtime->hw = snd_fm801_capture;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates);
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
return 0;
}
static int snd_fm801_playback_close(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
chip->playback_substream = NULL;
return 0;
}
static int snd_fm801_capture_close(struct snd_pcm_substream *substream)
{
struct fm801 *chip = snd_pcm_substream_chip(substream);
chip->capture_substream = NULL;
return 0;
}
static int __devinit snd_fm801_pcm(struct fm801 *chip, int device, struct snd_pcm ** rpcm)
{
struct snd_pcm *pcm;
int err;
if (rpcm)
*rpcm = NULL;
if ((err = snd_pcm_new(chip->card, "FM801", device, 1, 1, &pcm)) < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_fm801_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_fm801_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, "FM801");
chip->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
chip->multichannel ? 128*1024 : 64*1024, 128*1024);
if (rpcm)
*rpcm = pcm;
return 0;
}
static void snd_fm801_tea575x_set_pins(struct snd_tea575x *tea, u8 pins)
{
struct fm801 *chip = tea->private_data;
unsigned short reg = inw(FM801_REG(chip, GPIO_CTRL));
struct snd_fm801_tea575x_gpio gpio = snd_fm801_tea575x_gpios[(chip->tea575x_tuner & TUNER_TYPE_MASK) - 1];
reg &= ~(FM801_GPIO_GP(gpio.data) |
FM801_GPIO_GP(gpio.clk) |
FM801_GPIO_GP(gpio.wren));
reg |= (pins & TEA575X_DATA) ? FM801_GPIO_GP(gpio.data) : 0;
reg |= (pins & TEA575X_CLK) ? FM801_GPIO_GP(gpio.clk) : 0;
reg |= (pins & TEA575X_WREN) ? 0 : FM801_GPIO_GP(gpio.wren);
outw(reg, FM801_REG(chip, GPIO_CTRL));
}
static u8 snd_fm801_tea575x_get_pins(struct snd_tea575x *tea)
{
struct fm801 *chip = tea->private_data;
unsigned short reg = inw(FM801_REG(chip, GPIO_CTRL));
struct snd_fm801_tea575x_gpio gpio = snd_fm801_tea575x_gpios[(chip->tea575x_tuner & TUNER_TYPE_MASK) - 1];
return (reg & FM801_GPIO_GP(gpio.data)) ? TEA575X_DATA : 0 |
(reg & FM801_GPIO_GP(gpio.most)) ? TEA575X_MOST : 0;
}
static void snd_fm801_tea575x_set_direction(struct snd_tea575x *tea, bool output)
{
struct fm801 *chip = tea->private_data;
unsigned short reg = inw(FM801_REG(chip, GPIO_CTRL));
struct snd_fm801_tea575x_gpio gpio = snd_fm801_tea575x_gpios[(chip->tea575x_tuner & TUNER_TYPE_MASK) - 1];
reg |= FM801_GPIO_GS(gpio.data) |
FM801_GPIO_GS(gpio.wren) |
FM801_GPIO_GS(gpio.clk) |
FM801_GPIO_GS(gpio.most);
if (output) {
reg &= ~(FM801_GPIO_GD(gpio.data) |
FM801_GPIO_GD(gpio.wren) |
FM801_GPIO_GD(gpio.clk) |
FM801_GPIO_GP(gpio.data) |
FM801_GPIO_GP(gpio.clk) |
FM801_GPIO_GP(gpio.wren));
} else {
reg |= FM801_GPIO_GD(gpio.data) |
FM801_GPIO_GD(gpio.most) |
FM801_GPIO_GP(gpio.data) |
FM801_GPIO_GP(gpio.most) |
FM801_GPIO_GP(gpio.wren);
reg &= ~(FM801_GPIO_GD(gpio.wren) |
FM801_GPIO_GD(gpio.clk) |
FM801_GPIO_GP(gpio.clk));
}
outw(reg, FM801_REG(chip, GPIO_CTRL));
}
static int snd_fm801_info_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_fm801_get_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct fm801 *chip = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
ucontrol->value.integer.value[0] = (inw(chip->port + reg) >> shift) & mask;
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_fm801_put_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct fm801 *chip = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
unsigned short val;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
return snd_fm801_update_bits(chip, reg, mask << shift, val << shift);
}
static int snd_fm801_info_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_fm801_get_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct fm801 *chip = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift_left = (kcontrol->private_value >> 8) & 0x0f;
int shift_right = (kcontrol->private_value >> 12) & 0x0f;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irq(&chip->reg_lock);
ucontrol->value.integer.value[0] = (inw(chip->port + reg) >> shift_left) & mask;
ucontrol->value.integer.value[1] = (inw(chip->port + reg) >> shift_right) & mask;
spin_unlock_irq(&chip->reg_lock);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_fm801_put_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct fm801 *chip = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift_left = (kcontrol->private_value >> 8) & 0x0f;
int shift_right = (kcontrol->private_value >> 12) & 0x0f;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
unsigned short val1, val2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
return snd_fm801_update_bits(chip, reg,
(mask << shift_left) | (mask << shift_right),
(val1 << shift_left ) | (val2 << shift_right));
}
static int snd_fm801_info_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[5] = {
"AC97 Primary", "FM", "I2S", "PCM", "AC97 Secondary"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 5;
if (uinfo->value.enumerated.item > 4)
uinfo->value.enumerated.item = 4;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_fm801_get_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct fm801 *chip = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = inw(FM801_REG(chip, REC_SRC)) & 7;
if (val > 4)
val = 4;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int snd_fm801_put_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct fm801 *chip = snd_kcontrol_chip(kcontrol);
unsigned short val;
if ((val = ucontrol->value.enumerated.item[0]) > 4)
return -EINVAL;
return snd_fm801_update_bits(chip, FM801_REC_SRC, 7, val);
}
static void snd_fm801_mixer_free_ac97_bus(struct snd_ac97_bus *bus)
{
struct fm801 *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void snd_fm801_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct fm801 *chip = ac97->private_data;
if (ac97->num == 0) {
chip->ac97 = NULL;
} else {
chip->ac97_sec = NULL;
}
}
static int __devinit snd_fm801_mixer(struct fm801 *chip)
{
struct snd_ac97_template ac97;
unsigned int i;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_fm801_codec_write,
.read = snd_fm801_codec_read,
};
if ((err = snd_ac97_bus(chip->card, 0, &ops, chip, &chip->ac97_bus)) < 0)
return err;
chip->ac97_bus->private_free = snd_fm801_mixer_free_ac97_bus;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_fm801_mixer_free_ac97;
if ((err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97)) < 0)
return err;
if (chip->secondary) {
ac97.num = 1;
ac97.addr = chip->secondary_addr;
if ((err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97_sec)) < 0)
return err;
}
for (i = 0; i < FM801_CONTROLS; i++)
snd_ctl_add(chip->card, snd_ctl_new1(&snd_fm801_controls[i], chip));
if (chip->multichannel) {
for (i = 0; i < FM801_CONTROLS_MULTI; i++)
snd_ctl_add(chip->card, snd_ctl_new1(&snd_fm801_controls_multi[i], chip));
}
return 0;
}
static int wait_for_codec(struct fm801 *chip, unsigned int codec_id,
unsigned short reg, unsigned long waits)
{
unsigned long timeout = jiffies + waits;
outw(FM801_AC97_READ | (codec_id << FM801_AC97_ADDR_SHIFT) | reg,
FM801_REG(chip, AC97_CMD));
udelay(5);
do {
if ((inw(FM801_REG(chip, AC97_CMD)) & (FM801_AC97_VALID|FM801_AC97_BUSY))
== FM801_AC97_VALID)
return 0;
schedule_timeout_uninterruptible(1);
} while (time_after(timeout, jiffies));
return -EIO;
}
static int snd_fm801_chip_init(struct fm801 *chip, int resume)
{
unsigned short cmdw;
if (chip->tea575x_tuner & TUNER_ONLY)
goto __ac97_ok;
outw((1<<5) | (1<<6), FM801_REG(chip, CODEC_CTRL));
inw(FM801_REG(chip, CODEC_CTRL));
udelay(100);
outw(0, FM801_REG(chip, CODEC_CTRL));
if (wait_for_codec(chip, 0, AC97_RESET, msecs_to_jiffies(750)) < 0)
if (!resume) {
snd_printk(KERN_INFO "Primary AC'97 codec not found, "
"assume SF64-PCR (tuner-only)\n");
chip->tea575x_tuner = 3 | TUNER_ONLY;
goto __ac97_ok;
}
if (chip->multichannel) {
if (chip->secondary_addr) {
wait_for_codec(chip, chip->secondary_addr,
AC97_VENDOR_ID1, msecs_to_jiffies(50));
} else {
int i;
for (i = 3; i > 0; i--) {
if (!wait_for_codec(chip, i, AC97_VENDOR_ID1,
msecs_to_jiffies(50))) {
cmdw = inw(FM801_REG(chip, AC97_DATA));
if (cmdw != 0xffff && cmdw != 0) {
chip->secondary = 1;
chip->secondary_addr = i;
break;
}
}
}
}
wait_for_codec(chip, 0, AC97_VENDOR_ID1, msecs_to_jiffies(750));
}
__ac97_ok:
outw(0x0808, FM801_REG(chip, PCM_VOL));
outw(0x9f1f, FM801_REG(chip, FM_VOL));
outw(0x8808, FM801_REG(chip, I2S_VOL));
outw(0x0003, FM801_REG(chip, I2S_MODE));
cmdw = inw(FM801_REG(chip, IRQ_MASK));
if (chip->irq < 0)
cmdw |= 0x00c3;
else
cmdw &= ~0x0083;
outw(cmdw, FM801_REG(chip, IRQ_MASK));
outw(FM801_IRQ_PLAYBACK|FM801_IRQ_CAPTURE|FM801_IRQ_MPU, FM801_REG(chip, IRQ_STATUS));
return 0;
}
static int snd_fm801_free(struct fm801 *chip)
{
unsigned short cmdw;
if (chip->irq < 0)
goto __end_hw;
cmdw = inw(FM801_REG(chip, IRQ_MASK));
cmdw |= 0x00c3;
outw(cmdw, FM801_REG(chip, IRQ_MASK));
__end_hw:
#ifdef CONFIG_SND_FM801_TEA575X_BOOL
if (!(chip->tea575x_tuner & TUNER_DISABLED))
snd_tea575x_exit(&chip->tea);
#endif
if (chip->irq >= 0)
free_irq(chip->irq, chip);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_fm801_dev_free(struct snd_device *device)
{
struct fm801 *chip = device->device_data;
return snd_fm801_free(chip);
}
static int __devinit snd_fm801_create(struct snd_card *card,
struct pci_dev * pci,
int tea575x_tuner,
struct fm801 ** rchip)
{
struct fm801 *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_fm801_dev_free,
};
*rchip = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
chip->tea575x_tuner = tea575x_tuner;
if ((err = pci_request_regions(pci, "FM801")) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->port = pci_resource_start(pci, 0);
if ((tea575x_tuner & TUNER_ONLY) == 0) {
if (request_irq(pci->irq, snd_fm801_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", chip->irq);
snd_fm801_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
pci_set_master(pci);
}
if (pci->revision >= 0xb1)
chip->multichannel = 1;
snd_fm801_chip_init(chip, 0);
tea575x_tuner = chip->tea575x_tuner;
if (chip->irq >= 0 && (tea575x_tuner & TUNER_ONLY)) {
pci_clear_master(pci);
free_irq(chip->irq, chip);
chip->irq = -1;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_fm801_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
#ifdef CONFIG_SND_FM801_TEA575X_BOOL
chip->tea.private_data = chip;
chip->tea.ops = &snd_fm801_tea_ops;
sprintf(chip->tea.bus_info, "PCI:%s", pci_name(pci));
if ((tea575x_tuner & TUNER_TYPE_MASK) > 0 &&
(tea575x_tuner & TUNER_TYPE_MASK) < 4) {
if (snd_tea575x_init(&chip->tea)) {
snd_printk(KERN_ERR "TEA575x radio not found\n");
return -ENODEV;
}
} else if ((tea575x_tuner & TUNER_TYPE_MASK) == 0) {
for (tea575x_tuner = 1; tea575x_tuner <= 3; tea575x_tuner++) {
chip->tea575x_tuner = tea575x_tuner;
if (!snd_tea575x_init(&chip->tea)) {
snd_printk(KERN_INFO "detected TEA575x radio type %s\n",
snd_fm801_tea575x_gpios[tea575x_tuner - 1].name);
break;
}
}
if (tea575x_tuner == 4) {
snd_printk(KERN_ERR "TEA575x radio not found\n");
chip->tea575x_tuner = TUNER_DISABLED;
}
}
if (!(chip->tea575x_tuner & TUNER_DISABLED)) {
strlcpy(chip->tea.card,
snd_fm801_tea575x_gpios[(tea575x_tuner &
TUNER_TYPE_MASK) - 1].name,
sizeof(chip->tea.card));
}
#endif
*rchip = chip;
return 0;
}
static int __devinit snd_card_fm801_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct fm801 *chip;
struct snd_opl3 *opl3;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
if ((err = snd_fm801_create(card, pci, tea575x_tuner[dev], &chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
strcpy(card->driver, "FM801");
strcpy(card->shortname, "ForteMedia FM801-");
strcat(card->shortname, chip->multichannel ? "AU" : "AS");
sprintf(card->longname, "%s at 0x%lx, irq %i",
card->shortname, chip->port, chip->irq);
if (chip->tea575x_tuner & TUNER_ONLY)
goto __fm801_tuner_only;
if ((err = snd_fm801_pcm(chip, 0, NULL)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_fm801_mixer(chip)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_mpu401_uart_new(card, 0, MPU401_HW_FM801,
FM801_REG(chip, MPU401_DATA),
MPU401_INFO_INTEGRATED,
chip->irq, 0, &chip->rmidi)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_opl3_create(card, FM801_REG(chip, OPL3_BANK0),
FM801_REG(chip, OPL3_BANK1),
OPL3_HW_OPL3_FM801, 1, &opl3)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0) {
snd_card_free(card);
return err;
}
__fm801_tuner_only:
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_card_fm801_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int snd_fm801_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct fm801 *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
snd_ac97_suspend(chip->ac97_sec);
for (i = 0; i < ARRAY_SIZE(saved_regs); i++)
chip->saved_regs[i] = inw(chip->port + saved_regs[i]);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int snd_fm801_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct fm801 *chip = card->private_data;
int i;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "fm801: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_fm801_chip_init(chip, 1);
snd_ac97_resume(chip->ac97);
snd_ac97_resume(chip->ac97_sec);
for (i = 0; i < ARRAY_SIZE(saved_regs); i++)
outw(chip->saved_regs[i], chip->port + saved_regs[i]);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int __init alsa_card_fm801_init(void)
{
return pci_register_driver(&driver);
}
static void __exit alsa_card_fm801_exit(void)
{
pci_unregister_driver(&driver);
}
