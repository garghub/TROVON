static int snd_wss_xrate(struct snd_pcm_runtime *runtime)
{
return snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates);
}
static inline void wss_outb(struct snd_wss *chip, u8 offset, u8 val)
{
outb(val, chip->port + offset);
}
static inline u8 wss_inb(struct snd_wss *chip, u8 offset)
{
return inb(chip->port + offset);
}
static void snd_wss_wait(struct snd_wss *chip)
{
int timeout;
for (timeout = 250;
timeout > 0 && (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT);
timeout--)
udelay(100);
}
static void snd_wss_dout(struct snd_wss *chip, unsigned char reg,
unsigned char value)
{
int timeout;
for (timeout = 250;
timeout > 0 && (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT);
timeout--)
udelay(10);
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | reg);
wss_outb(chip, CS4231P(REG), value);
mb();
}
void snd_wss_out(struct snd_wss *chip, unsigned char reg, unsigned char value)
{
snd_wss_wait(chip);
#ifdef CONFIG_SND_DEBUG
if (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT)
snd_printk(KERN_DEBUG "out: auto calibration time out "
"- reg = 0x%x, value = 0x%x\n", reg, value);
#endif
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | reg);
wss_outb(chip, CS4231P(REG), value);
chip->image[reg] = value;
mb();
snd_printdd("codec out - reg 0x%x = 0x%x\n",
chip->mce_bit | reg, value);
}
unsigned char snd_wss_in(struct snd_wss *chip, unsigned char reg)
{
snd_wss_wait(chip);
#ifdef CONFIG_SND_DEBUG
if (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT)
snd_printk(KERN_DEBUG "in: auto calibration time out "
"- reg = 0x%x\n", reg);
#endif
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | reg);
mb();
return wss_inb(chip, CS4231P(REG));
}
void snd_cs4236_ext_out(struct snd_wss *chip, unsigned char reg,
unsigned char val)
{
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | 0x17);
wss_outb(chip, CS4231P(REG),
reg | (chip->image[CS4236_EXT_REG] & 0x01));
wss_outb(chip, CS4231P(REG), val);
chip->eimage[CS4236_REG(reg)] = val;
#if 0
printk(KERN_DEBUG "ext out : reg = 0x%x, val = 0x%x\n", reg, val);
#endif
}
unsigned char snd_cs4236_ext_in(struct snd_wss *chip, unsigned char reg)
{
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | 0x17);
wss_outb(chip, CS4231P(REG),
reg | (chip->image[CS4236_EXT_REG] & 0x01));
#if 1
return wss_inb(chip, CS4231P(REG));
#else
{
unsigned char res;
res = wss_inb(chip, CS4231P(REG));
printk(KERN_DEBUG "ext in : reg = 0x%x, val = 0x%x\n",
reg, res);
return res;
}
#endif
}
static void snd_wss_busy_wait(struct snd_wss *chip)
{
int timeout;
for (timeout = 5; timeout > 0; timeout--)
wss_inb(chip, CS4231P(REGSEL));
for (timeout = 25000;
timeout > 0 && (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT);
timeout--)
udelay(10);
}
void snd_wss_mce_up(struct snd_wss *chip)
{
unsigned long flags;
int timeout;
snd_wss_wait(chip);
#ifdef CONFIG_SND_DEBUG
if (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT)
snd_printk(KERN_DEBUG
"mce_up - auto calibration time out (0)\n");
#endif
spin_lock_irqsave(&chip->reg_lock, flags);
chip->mce_bit |= CS4231_MCE;
timeout = wss_inb(chip, CS4231P(REGSEL));
if (timeout == 0x80)
snd_printk(KERN_DEBUG "mce_up [0x%lx]: "
"serious init problem - codec still busy\n",
chip->port);
if (!(timeout & CS4231_MCE))
wss_outb(chip, CS4231P(REGSEL),
chip->mce_bit | (timeout & 0x1f));
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
void snd_wss_mce_down(struct snd_wss *chip)
{
unsigned long flags;
unsigned long end_time;
int timeout;
int hw_mask = WSS_HW_CS4231_MASK | WSS_HW_CS4232_MASK | WSS_HW_AD1848;
snd_wss_busy_wait(chip);
#ifdef CONFIG_SND_DEBUG
if (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT)
snd_printk(KERN_DEBUG "mce_down [0x%lx] - "
"auto calibration time out (0)\n",
(long)CS4231P(REGSEL));
#endif
spin_lock_irqsave(&chip->reg_lock, flags);
chip->mce_bit &= ~CS4231_MCE;
timeout = wss_inb(chip, CS4231P(REGSEL));
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | (timeout & 0x1f));
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (timeout == 0x80)
snd_printk(KERN_DEBUG "mce_down [0x%lx]: "
"serious init problem - codec still busy\n",
chip->port);
if ((timeout & CS4231_MCE) == 0 || !(chip->hardware & hw_mask))
return;
msleep(1);
snd_printdd("(1) jiffies = %lu\n", jiffies);
end_time = jiffies + msecs_to_jiffies(250);
while (snd_wss_in(chip, CS4231_TEST_INIT) &
CS4231_CALIB_IN_PROGRESS) {
if (time_after(jiffies, end_time)) {
snd_printk(KERN_ERR "mce_down - "
"auto calibration time out (2)\n");
return;
}
msleep(1);
}
snd_printdd("(2) jiffies = %lu\n", jiffies);
end_time = jiffies + msecs_to_jiffies(100);
while (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT) {
if (time_after(jiffies, end_time)) {
snd_printk(KERN_ERR "mce_down - auto calibration time out (3)\n");
return;
}
msleep(1);
}
snd_printdd("(3) jiffies = %lu\n", jiffies);
snd_printd("mce_down - exit = 0x%x\n", wss_inb(chip, CS4231P(REGSEL)));
}
static unsigned int snd_wss_get_count(unsigned char format, unsigned int size)
{
switch (format & 0xe0) {
case CS4231_LINEAR_16:
case CS4231_LINEAR_16_BIG:
size >>= 1;
break;
case CS4231_ADPCM_16:
return size >> 2;
}
if (format & CS4231_STEREO)
size >>= 1;
return size;
}
static int snd_wss_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
int result = 0;
unsigned int what;
struct snd_pcm_substream *s;
int do_start;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
do_start = 1; break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
do_start = 0; break;
default:
return -EINVAL;
}
what = 0;
snd_pcm_group_for_each_entry(s, substream) {
if (s == chip->playback_substream) {
what |= CS4231_PLAYBACK_ENABLE;
snd_pcm_trigger_done(s, substream);
} else if (s == chip->capture_substream) {
what |= CS4231_RECORD_ENABLE;
snd_pcm_trigger_done(s, substream);
}
}
spin_lock(&chip->reg_lock);
if (do_start) {
chip->image[CS4231_IFACE_CTRL] |= what;
if (chip->trigger)
chip->trigger(chip, what, 1);
} else {
chip->image[CS4231_IFACE_CTRL] &= ~what;
if (chip->trigger)
chip->trigger(chip, what, 0);
}
snd_wss_out(chip, CS4231_IFACE_CTRL, chip->image[CS4231_IFACE_CTRL]);
spin_unlock(&chip->reg_lock);
#if 0
snd_wss_debug(chip);
#endif
return result;
}
static unsigned char snd_wss_get_rate(unsigned int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(rates); i++)
if (rate == rates[i])
return freq_bits[i];
return freq_bits[ARRAY_SIZE(rates) - 1];
}
static unsigned char snd_wss_get_format(struct snd_wss *chip,
int format,
int channels)
{
unsigned char rformat;
rformat = CS4231_LINEAR_8;
switch (format) {
case SNDRV_PCM_FORMAT_MU_LAW: rformat = CS4231_ULAW_8; break;
case SNDRV_PCM_FORMAT_A_LAW: rformat = CS4231_ALAW_8; break;
case SNDRV_PCM_FORMAT_S16_LE: rformat = CS4231_LINEAR_16; break;
case SNDRV_PCM_FORMAT_S16_BE: rformat = CS4231_LINEAR_16_BIG; break;
case SNDRV_PCM_FORMAT_IMA_ADPCM: rformat = CS4231_ADPCM_16; break;
}
if (channels > 1)
rformat |= CS4231_STEREO;
#if 0
snd_printk(KERN_DEBUG "get_format: 0x%x (mode=0x%x)\n", format, mode);
#endif
return rformat;
}
static void snd_wss_calibrate_mute(struct snd_wss *chip, int mute)
{
unsigned long flags;
mute = mute ? 0x80 : 0;
spin_lock_irqsave(&chip->reg_lock, flags);
if (chip->calibrate_mute == mute) {
spin_unlock_irqrestore(&chip->reg_lock, flags);
return;
}
if (!mute) {
snd_wss_dout(chip, CS4231_LEFT_INPUT,
chip->image[CS4231_LEFT_INPUT]);
snd_wss_dout(chip, CS4231_RIGHT_INPUT,
chip->image[CS4231_RIGHT_INPUT]);
snd_wss_dout(chip, CS4231_LOOPBACK,
chip->image[CS4231_LOOPBACK]);
} else {
snd_wss_dout(chip, CS4231_LEFT_INPUT,
0);
snd_wss_dout(chip, CS4231_RIGHT_INPUT,
0);
snd_wss_dout(chip, CS4231_LOOPBACK,
0xfd);
}
snd_wss_dout(chip, CS4231_AUX1_LEFT_INPUT,
mute | chip->image[CS4231_AUX1_LEFT_INPUT]);
snd_wss_dout(chip, CS4231_AUX1_RIGHT_INPUT,
mute | chip->image[CS4231_AUX1_RIGHT_INPUT]);
snd_wss_dout(chip, CS4231_AUX2_LEFT_INPUT,
mute | chip->image[CS4231_AUX2_LEFT_INPUT]);
snd_wss_dout(chip, CS4231_AUX2_RIGHT_INPUT,
mute | chip->image[CS4231_AUX2_RIGHT_INPUT]);
snd_wss_dout(chip, CS4231_LEFT_OUTPUT,
mute | chip->image[CS4231_LEFT_OUTPUT]);
snd_wss_dout(chip, CS4231_RIGHT_OUTPUT,
mute | chip->image[CS4231_RIGHT_OUTPUT]);
if (!(chip->hardware & WSS_HW_AD1848_MASK)) {
snd_wss_dout(chip, CS4231_LEFT_LINE_IN,
mute | chip->image[CS4231_LEFT_LINE_IN]);
snd_wss_dout(chip, CS4231_RIGHT_LINE_IN,
mute | chip->image[CS4231_RIGHT_LINE_IN]);
snd_wss_dout(chip, CS4231_MONO_CTRL,
mute ? 0xc0 : chip->image[CS4231_MONO_CTRL]);
}
if (chip->hardware == WSS_HW_INTERWAVE) {
snd_wss_dout(chip, CS4231_LEFT_MIC_INPUT,
mute | chip->image[CS4231_LEFT_MIC_INPUT]);
snd_wss_dout(chip, CS4231_RIGHT_MIC_INPUT,
mute | chip->image[CS4231_RIGHT_MIC_INPUT]);
snd_wss_dout(chip, CS4231_LINE_LEFT_OUTPUT,
mute | chip->image[CS4231_LINE_LEFT_OUTPUT]);
snd_wss_dout(chip, CS4231_LINE_RIGHT_OUTPUT,
mute | chip->image[CS4231_LINE_RIGHT_OUTPUT]);
}
chip->calibrate_mute = mute;
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static void snd_wss_playback_format(struct snd_wss *chip,
struct snd_pcm_hw_params *params,
unsigned char pdfr)
{
unsigned long flags;
int full_calib = 1;
mutex_lock(&chip->mce_mutex);
if (chip->hardware == WSS_HW_CS4231A ||
(chip->hardware & WSS_HW_CS4232_MASK)) {
spin_lock_irqsave(&chip->reg_lock, flags);
if ((chip->image[CS4231_PLAYBK_FORMAT] & 0x0f) == (pdfr & 0x0f)) {
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] | 0x10);
chip->image[CS4231_PLAYBK_FORMAT] = pdfr;
snd_wss_out(chip, CS4231_PLAYBK_FORMAT,
chip->image[CS4231_PLAYBK_FORMAT]);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] &= ~0x10);
udelay(100);
full_calib = 0;
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
} else if (chip->hardware == WSS_HW_AD1845) {
unsigned rate = params_rate(params);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_PLAYBK_FORMAT, (pdfr & 0xf0));
snd_wss_out(chip, AD1845_UPR_FREQ_SEL, (rate >> 8) & 0xff);
snd_wss_out(chip, AD1845_LWR_FREQ_SEL, rate & 0xff);
full_calib = 0;
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
if (full_calib) {
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
if (chip->hardware != WSS_HW_INTERWAVE && !chip->single_dma) {
if (chip->image[CS4231_IFACE_CTRL] & CS4231_RECORD_ENABLE)
pdfr = (pdfr & 0xf0) |
(chip->image[CS4231_REC_FORMAT] & 0x0f);
} else {
chip->image[CS4231_PLAYBK_FORMAT] = pdfr;
}
snd_wss_out(chip, CS4231_PLAYBK_FORMAT, pdfr);
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (chip->hardware == WSS_HW_OPL3SA2)
udelay(100);
snd_wss_mce_down(chip);
}
mutex_unlock(&chip->mce_mutex);
}
static void snd_wss_capture_format(struct snd_wss *chip,
struct snd_pcm_hw_params *params,
unsigned char cdfr)
{
unsigned long flags;
int full_calib = 1;
mutex_lock(&chip->mce_mutex);
if (chip->hardware == WSS_HW_CS4231A ||
(chip->hardware & WSS_HW_CS4232_MASK)) {
spin_lock_irqsave(&chip->reg_lock, flags);
if ((chip->image[CS4231_PLAYBK_FORMAT] & 0x0f) == (cdfr & 0x0f) ||
(chip->image[CS4231_IFACE_CTRL] & CS4231_PLAYBACK_ENABLE)) {
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] | 0x20);
snd_wss_out(chip, CS4231_REC_FORMAT,
chip->image[CS4231_REC_FORMAT] = cdfr);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] &= ~0x20);
full_calib = 0;
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
} else if (chip->hardware == WSS_HW_AD1845) {
unsigned rate = params_rate(params);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_REC_FORMAT, (cdfr & 0xf0));
snd_wss_out(chip, AD1845_UPR_FREQ_SEL, (rate >> 8) & 0xff);
snd_wss_out(chip, AD1845_LWR_FREQ_SEL, rate & 0xff);
full_calib = 0;
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
if (full_calib) {
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
if (chip->hardware != WSS_HW_INTERWAVE &&
!(chip->image[CS4231_IFACE_CTRL] & CS4231_PLAYBACK_ENABLE)) {
if (chip->single_dma)
snd_wss_out(chip, CS4231_PLAYBK_FORMAT, cdfr);
else
snd_wss_out(chip, CS4231_PLAYBK_FORMAT,
(chip->image[CS4231_PLAYBK_FORMAT] & 0xf0) |
(cdfr & 0x0f));
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
}
if (chip->hardware & WSS_HW_AD1848_MASK)
snd_wss_out(chip, CS4231_PLAYBK_FORMAT, cdfr);
else
snd_wss_out(chip, CS4231_REC_FORMAT, cdfr);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
}
mutex_unlock(&chip->mce_mutex);
}
static unsigned long snd_wss_timer_resolution(struct snd_timer *timer)
{
struct snd_wss *chip = snd_timer_chip(timer);
if (chip->hardware & WSS_HW_CS4236B_MASK)
return 14467;
else
return chip->image[CS4231_PLAYBK_FORMAT] & 1 ? 9969 : 9920;
}
static int snd_wss_timer_start(struct snd_timer *timer)
{
unsigned long flags;
unsigned int ticks;
struct snd_wss *chip = snd_timer_chip(timer);
spin_lock_irqsave(&chip->reg_lock, flags);
ticks = timer->sticks;
if ((chip->image[CS4231_ALT_FEATURE_1] & CS4231_TIMER_ENABLE) == 0 ||
(unsigned char)(ticks >> 8) != chip->image[CS4231_TIMER_HIGH] ||
(unsigned char)ticks != chip->image[CS4231_TIMER_LOW]) {
chip->image[CS4231_TIMER_HIGH] = (unsigned char) (ticks >> 8);
snd_wss_out(chip, CS4231_TIMER_HIGH,
chip->image[CS4231_TIMER_HIGH]);
chip->image[CS4231_TIMER_LOW] = (unsigned char) ticks;
snd_wss_out(chip, CS4231_TIMER_LOW,
chip->image[CS4231_TIMER_LOW]);
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1] |
CS4231_TIMER_ENABLE);
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int snd_wss_timer_stop(struct snd_timer *timer)
{
unsigned long flags;
struct snd_wss *chip = snd_timer_chip(timer);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->image[CS4231_ALT_FEATURE_1] &= ~CS4231_TIMER_ENABLE;
snd_wss_out(chip, CS4231_ALT_FEATURE_1,
chip->image[CS4231_ALT_FEATURE_1]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static void snd_wss_init(struct snd_wss *chip)
{
unsigned long flags;
snd_wss_calibrate_mute(chip, 1);
snd_wss_mce_down(chip);
#ifdef SNDRV_DEBUG_MCE
snd_printk(KERN_DEBUG "init: (1)\n");
#endif
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->image[CS4231_IFACE_CTRL] &= ~(CS4231_PLAYBACK_ENABLE |
CS4231_PLAYBACK_PIO |
CS4231_RECORD_ENABLE |
CS4231_RECORD_PIO |
CS4231_CALIB_MODE);
chip->image[CS4231_IFACE_CTRL] |= CS4231_AUTOCALIB;
snd_wss_out(chip, CS4231_IFACE_CTRL, chip->image[CS4231_IFACE_CTRL]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
#ifdef SNDRV_DEBUG_MCE
snd_printk(KERN_DEBUG "init: (2)\n");
#endif
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->image[CS4231_IFACE_CTRL] &= ~CS4231_AUTOCALIB;
snd_wss_out(chip, CS4231_IFACE_CTRL, chip->image[CS4231_IFACE_CTRL]);
snd_wss_out(chip,
CS4231_ALT_FEATURE_1, chip->image[CS4231_ALT_FEATURE_1]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
#ifdef SNDRV_DEBUG_MCE
snd_printk(KERN_DEBUG "init: (3) - afei = 0x%x\n",
chip->image[CS4231_ALT_FEATURE_1]);
#endif
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_ALT_FEATURE_2,
chip->image[CS4231_ALT_FEATURE_2]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_PLAYBK_FORMAT,
chip->image[CS4231_PLAYBK_FORMAT]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
#ifdef SNDRV_DEBUG_MCE
snd_printk(KERN_DEBUG "init: (4)\n");
#endif
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
if (!(chip->hardware & WSS_HW_AD1848_MASK))
snd_wss_out(chip, CS4231_REC_FORMAT,
chip->image[CS4231_REC_FORMAT]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
snd_wss_calibrate_mute(chip, 0);
#ifdef SNDRV_DEBUG_MCE
snd_printk(KERN_DEBUG "init: (5)\n");
#endif
}
static int snd_wss_open(struct snd_wss *chip, unsigned int mode)
{
unsigned long flags;
mutex_lock(&chip->open_mutex);
if ((chip->mode & mode) ||
((chip->mode & WSS_MODE_OPEN) && chip->single_dma)) {
mutex_unlock(&chip->open_mutex);
return -EAGAIN;
}
if (chip->mode & WSS_MODE_OPEN) {
chip->mode |= mode;
mutex_unlock(&chip->open_mutex);
return 0;
}
spin_lock_irqsave(&chip->reg_lock, flags);
if (!(chip->hardware & WSS_HW_AD1848_MASK)) {
snd_wss_out(chip, CS4231_IRQ_STATUS,
CS4231_PLAYBACK_IRQ |
CS4231_RECORD_IRQ |
CS4231_TIMER_IRQ);
snd_wss_out(chip, CS4231_IRQ_STATUS, 0);
}
wss_outb(chip, CS4231P(STATUS), 0);
wss_outb(chip, CS4231P(STATUS), 0);
chip->image[CS4231_PIN_CTRL] |= CS4231_IRQ_ENABLE;
snd_wss_out(chip, CS4231_PIN_CTRL, chip->image[CS4231_PIN_CTRL]);
if (!(chip->hardware & WSS_HW_AD1848_MASK)) {
snd_wss_out(chip, CS4231_IRQ_STATUS,
CS4231_PLAYBACK_IRQ |
CS4231_RECORD_IRQ |
CS4231_TIMER_IRQ);
snd_wss_out(chip, CS4231_IRQ_STATUS, 0);
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
chip->mode = mode;
mutex_unlock(&chip->open_mutex);
return 0;
}
static void snd_wss_close(struct snd_wss *chip, unsigned int mode)
{
unsigned long flags;
mutex_lock(&chip->open_mutex);
chip->mode &= ~mode;
if (chip->mode & WSS_MODE_OPEN) {
mutex_unlock(&chip->open_mutex);
return;
}
spin_lock_irqsave(&chip->reg_lock, flags);
if (!(chip->hardware & WSS_HW_AD1848_MASK))
snd_wss_out(chip, CS4231_IRQ_STATUS, 0);
wss_outb(chip, CS4231P(STATUS), 0);
wss_outb(chip, CS4231P(STATUS), 0);
chip->image[CS4231_PIN_CTRL] &= ~CS4231_IRQ_ENABLE;
snd_wss_out(chip, CS4231_PIN_CTRL, chip->image[CS4231_PIN_CTRL]);
if (chip->image[CS4231_IFACE_CTRL] & (CS4231_PLAYBACK_ENABLE | CS4231_PLAYBACK_PIO |
CS4231_RECORD_ENABLE | CS4231_RECORD_PIO)) {
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->image[CS4231_IFACE_CTRL] &= ~(CS4231_PLAYBACK_ENABLE | CS4231_PLAYBACK_PIO |
CS4231_RECORD_ENABLE | CS4231_RECORD_PIO);
snd_wss_out(chip, CS4231_IFACE_CTRL,
chip->image[CS4231_IFACE_CTRL]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
}
if (!(chip->hardware & WSS_HW_AD1848_MASK))
snd_wss_out(chip, CS4231_IRQ_STATUS, 0);
wss_outb(chip, CS4231P(STATUS), 0);
wss_outb(chip, CS4231P(STATUS), 0);
spin_unlock_irqrestore(&chip->reg_lock, flags);
chip->mode = 0;
mutex_unlock(&chip->open_mutex);
}
static int snd_wss_timer_open(struct snd_timer *timer)
{
struct snd_wss *chip = snd_timer_chip(timer);
snd_wss_open(chip, WSS_MODE_TIMER);
return 0;
}
static int snd_wss_timer_close(struct snd_timer *timer)
{
struct snd_wss *chip = snd_timer_chip(timer);
snd_wss_close(chip, WSS_MODE_TIMER);
return 0;
}
static int snd_wss_playback_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
unsigned char new_pdfr;
int err;
if ((err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params))) < 0)
return err;
new_pdfr = snd_wss_get_format(chip, params_format(hw_params),
params_channels(hw_params)) |
snd_wss_get_rate(params_rate(hw_params));
chip->set_playback_format(chip, hw_params, new_pdfr);
return 0;
}
static int snd_wss_playback_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_wss_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long flags;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->p_dma_size = size;
chip->image[CS4231_IFACE_CTRL] &= ~(CS4231_PLAYBACK_ENABLE | CS4231_PLAYBACK_PIO);
snd_dma_program(chip->dma1, runtime->dma_addr, size, DMA_MODE_WRITE | DMA_AUTOINIT);
count = snd_wss_get_count(chip->image[CS4231_PLAYBK_FORMAT], count) - 1;
snd_wss_out(chip, CS4231_PLY_LWR_CNT, (unsigned char) count);
snd_wss_out(chip, CS4231_PLY_UPR_CNT, (unsigned char) (count >> 8));
spin_unlock_irqrestore(&chip->reg_lock, flags);
#if 0
snd_wss_debug(chip);
#endif
return 0;
}
static int snd_wss_capture_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
unsigned char new_cdfr;
int err;
if ((err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params))) < 0)
return err;
new_cdfr = snd_wss_get_format(chip, params_format(hw_params),
params_channels(hw_params)) |
snd_wss_get_rate(params_rate(hw_params));
chip->set_capture_format(chip, hw_params, new_cdfr);
return 0;
}
static int snd_wss_capture_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_wss_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long flags;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->c_dma_size = size;
chip->image[CS4231_IFACE_CTRL] &= ~(CS4231_RECORD_ENABLE | CS4231_RECORD_PIO);
snd_dma_program(chip->dma2, runtime->dma_addr, size, DMA_MODE_READ | DMA_AUTOINIT);
if (chip->hardware & WSS_HW_AD1848_MASK)
count = snd_wss_get_count(chip->image[CS4231_PLAYBK_FORMAT],
count);
else
count = snd_wss_get_count(chip->image[CS4231_REC_FORMAT],
count);
count--;
if (chip->single_dma && chip->hardware != WSS_HW_INTERWAVE) {
snd_wss_out(chip, CS4231_PLY_LWR_CNT, (unsigned char) count);
snd_wss_out(chip, CS4231_PLY_UPR_CNT,
(unsigned char) (count >> 8));
} else {
snd_wss_out(chip, CS4231_REC_LWR_CNT, (unsigned char) count);
snd_wss_out(chip, CS4231_REC_UPR_CNT,
(unsigned char) (count >> 8));
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
void snd_wss_overrange(struct snd_wss *chip)
{
unsigned long flags;
unsigned char res;
spin_lock_irqsave(&chip->reg_lock, flags);
res = snd_wss_in(chip, CS4231_TEST_INIT);
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (res & (0x08 | 0x02))
chip->capture_substream->runtime->overrange++;
}
irqreturn_t snd_wss_interrupt(int irq, void *dev_id)
{
struct snd_wss *chip = dev_id;
unsigned char status;
if (chip->hardware & WSS_HW_AD1848_MASK)
status = CS4231_PLAYBACK_IRQ;
else
status = snd_wss_in(chip, CS4231_IRQ_STATUS);
if (status & CS4231_TIMER_IRQ) {
if (chip->timer)
snd_timer_interrupt(chip->timer, chip->timer->sticks);
}
if (chip->single_dma && chip->hardware != WSS_HW_INTERWAVE) {
if (status & CS4231_PLAYBACK_IRQ) {
if (chip->mode & WSS_MODE_PLAY) {
if (chip->playback_substream)
snd_pcm_period_elapsed(chip->playback_substream);
}
if (chip->mode & WSS_MODE_RECORD) {
if (chip->capture_substream) {
snd_wss_overrange(chip);
snd_pcm_period_elapsed(chip->capture_substream);
}
}
}
} else {
if (status & CS4231_PLAYBACK_IRQ) {
if (chip->playback_substream)
snd_pcm_period_elapsed(chip->playback_substream);
}
if (status & CS4231_RECORD_IRQ) {
if (chip->capture_substream) {
snd_wss_overrange(chip);
snd_pcm_period_elapsed(chip->capture_substream);
}
}
}
spin_lock(&chip->reg_lock);
status = ~CS4231_ALL_IRQS | ~status;
if (chip->hardware & WSS_HW_AD1848_MASK)
wss_outb(chip, CS4231P(STATUS), 0);
else
snd_wss_out(chip, CS4231_IRQ_STATUS, status);
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static snd_pcm_uframes_t snd_wss_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(chip->image[CS4231_IFACE_CTRL] & CS4231_PLAYBACK_ENABLE))
return 0;
ptr = snd_dma_pointer(chip->dma1, chip->p_dma_size);
return bytes_to_frames(substream->runtime, ptr);
}
static snd_pcm_uframes_t snd_wss_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(chip->image[CS4231_IFACE_CTRL] & CS4231_RECORD_ENABLE))
return 0;
ptr = snd_dma_pointer(chip->dma2, chip->c_dma_size);
return bytes_to_frames(substream->runtime, ptr);
}
static int snd_ad1848_probe(struct snd_wss *chip)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
unsigned long flags;
unsigned char r;
unsigned short hardware = 0;
int err = 0;
int i;
while (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT) {
if (time_after(jiffies, timeout))
return -ENODEV;
cond_resched();
}
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_dout(chip, CS4231_MISC_INFO, 0);
snd_wss_dout(chip, CS4231_RIGHT_INPUT, 0x45);
r = snd_wss_in(chip, CS4231_RIGHT_INPUT);
if (r != 0x45) {
if ((r & ~CS4231_ENABLE_MIC_GAIN) != 0x45) {
err = -ENODEV;
goto out;
}
hardware = WSS_HW_AD1847;
} else {
snd_wss_dout(chip, CS4231_LEFT_INPUT, 0xaa);
r = snd_wss_in(chip, CS4231_LEFT_INPUT);
if ((r | CS4231_ENABLE_MIC_GAIN) != 0xaa) {
err = -ENODEV;
goto out;
}
}
wss_inb(chip, CS4231P(STATUS));
wss_outb(chip, CS4231P(STATUS), 0);
mb();
if ((chip->hardware & WSS_HW_TYPE_MASK) != WSS_HW_DETECT)
goto out;
if (hardware) {
chip->hardware = hardware;
goto out;
}
r = snd_wss_in(chip, CS4231_MISC_INFO);
snd_wss_dout(chip, CS4231_MISC_INFO, CS4231_MODE2);
for (i = 0; i < 16; i++) {
if (snd_wss_in(chip, i) != snd_wss_in(chip, 16 + i)) {
if ((r & 0xf) != 0xa)
goto out_mode;
snd_wss_dout(chip, CS4231_VERSION, 0);
r = snd_wss_in(chip, CS4231_VERSION) & 0xe7;
if (!r)
chip->hardware = WSS_HW_CMI8330;
goto out_mode;
}
}
if (r & 0x80)
chip->hardware = WSS_HW_CS4248;
else
chip->hardware = WSS_HW_AD1848;
out_mode:
snd_wss_dout(chip, CS4231_MISC_INFO, 0);
out:
spin_unlock_irqrestore(&chip->reg_lock, flags);
return err;
}
static int snd_wss_probe(struct snd_wss *chip)
{
unsigned long flags;
int i, id, rev, regnum;
unsigned char *ptr;
unsigned int hw;
id = snd_ad1848_probe(chip);
if (id < 0)
return id;
hw = chip->hardware;
if ((hw & WSS_HW_TYPE_MASK) == WSS_HW_DETECT) {
for (i = 0; i < 50; i++) {
mb();
if (wss_inb(chip, CS4231P(REGSEL)) & CS4231_INIT)
msleep(2);
else {
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, CS4231_MISC_INFO,
CS4231_MODE2);
id = snd_wss_in(chip, CS4231_MISC_INFO) & 0x0f;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (id == 0x0a)
break;
}
}
snd_printdd("wss: port = 0x%lx, id = 0x%x\n", chip->port, id);
if (id != 0x0a)
return -ENODEV;
rev = snd_wss_in(chip, CS4231_VERSION) & 0xe7;
snd_printdd("CS4231: VERSION (I25) = 0x%x\n", rev);
if (rev == 0x80) {
unsigned char tmp = snd_wss_in(chip, 23);
snd_wss_out(chip, 23, ~tmp);
if (snd_wss_in(chip, 23) != tmp)
chip->hardware = WSS_HW_AD1845;
else
chip->hardware = WSS_HW_CS4231;
} else if (rev == 0xa0) {
chip->hardware = WSS_HW_CS4231A;
} else if (rev == 0xa2) {
chip->hardware = WSS_HW_CS4232;
} else if (rev == 0xb2) {
chip->hardware = WSS_HW_CS4232A;
} else if (rev == 0x83) {
chip->hardware = WSS_HW_CS4236;
} else if (rev == 0x03) {
chip->hardware = WSS_HW_CS4236B;
} else {
snd_printk(KERN_ERR
"unknown CS chip with version 0x%x\n", rev);
return -ENODEV;
}
}
spin_lock_irqsave(&chip->reg_lock, flags);
wss_inb(chip, CS4231P(STATUS));
wss_outb(chip, CS4231P(STATUS), 0);
mb();
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (!(chip->hardware & WSS_HW_AD1848_MASK))
chip->image[CS4231_MISC_INFO] = CS4231_MODE2;
switch (chip->hardware) {
case WSS_HW_INTERWAVE:
chip->image[CS4231_MISC_INFO] = CS4231_IW_MODE3;
break;
case WSS_HW_CS4235:
case WSS_HW_CS4236B:
case WSS_HW_CS4237B:
case WSS_HW_CS4238B:
case WSS_HW_CS4239:
if (hw == WSS_HW_DETECT3)
chip->image[CS4231_MISC_INFO] = CS4231_4236_MODE3;
else
chip->hardware = WSS_HW_CS4236;
break;
}
chip->image[CS4231_IFACE_CTRL] =
(chip->image[CS4231_IFACE_CTRL] & ~CS4231_SINGLE_DMA) |
(chip->single_dma ? CS4231_SINGLE_DMA : 0);
if (chip->hardware != WSS_HW_OPTI93X) {
chip->image[CS4231_ALT_FEATURE_1] = 0x80;
chip->image[CS4231_ALT_FEATURE_2] =
chip->hardware == WSS_HW_INTERWAVE ? 0xc2 : 0x01;
}
if (chip->hardware == WSS_HW_AD1845)
chip->image[AD1845_PWR_DOWN] = 8;
ptr = (unsigned char *) &chip->image;
regnum = (chip->hardware & WSS_HW_AD1848_MASK) ? 16 : 32;
snd_wss_mce_down(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
for (i = 0; i < regnum; i++)
snd_wss_out(chip, i, *ptr++);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_up(chip);
snd_wss_mce_down(chip);
mdelay(2);
if ((hw & WSS_HW_TYPE_MASK) == WSS_HW_DETECT) {
if (chip->hardware == WSS_HW_CS4236B) {
rev = snd_cs4236_ext_in(chip, CS4236_VERSION);
snd_cs4236_ext_out(chip, CS4236_VERSION, 0xff);
id = snd_cs4236_ext_in(chip, CS4236_VERSION);
snd_cs4236_ext_out(chip, CS4236_VERSION, rev);
snd_printdd("CS4231: ext version; rev = 0x%x, id = 0x%x\n", rev, id);
if ((id & 0x1f) == 0x1d) {
chip->hardware = WSS_HW_CS4235;
switch (id >> 5) {
case 4:
case 5:
case 6:
break;
default:
snd_printk(KERN_WARNING
"unknown CS4235 chip "
"(enhanced version = 0x%x)\n",
id);
}
} else if ((id & 0x1f) == 0x0b) {
switch (id >> 5) {
case 4:
case 5:
case 6:
case 7:
chip->hardware = WSS_HW_CS4236B;
break;
default:
snd_printk(KERN_WARNING
"unknown CS4236 chip "
"(enhanced version = 0x%x)\n",
id);
}
} else if ((id & 0x1f) == 0x08) {
chip->hardware = WSS_HW_CS4237B;
switch (id >> 5) {
case 4:
case 5:
case 6:
case 7:
break;
default:
snd_printk(KERN_WARNING
"unknown CS4237B chip "
"(enhanced version = 0x%x)\n",
id);
}
} else if ((id & 0x1f) == 0x09) {
chip->hardware = WSS_HW_CS4238B;
switch (id >> 5) {
case 5:
case 6:
case 7:
break;
default:
snd_printk(KERN_WARNING
"unknown CS4238B chip "
"(enhanced version = 0x%x)\n",
id);
}
} else if ((id & 0x1f) == 0x1e) {
chip->hardware = WSS_HW_CS4239;
switch (id >> 5) {
case 4:
case 5:
case 6:
break;
default:
snd_printk(KERN_WARNING
"unknown CS4239 chip "
"(enhanced version = 0x%x)\n",
id);
}
} else {
snd_printk(KERN_WARNING
"unknown CS4236/CS423xB chip "
"(enhanced version = 0x%x)\n", id);
}
}
}
return 0;
}
static int snd_wss_playback_open(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
runtime->hw = snd_wss_playback;
if (chip->hardware & WSS_HW_AD1848_MASK)
runtime->hw.formats &= ~(SNDRV_PCM_FMTBIT_IMA_ADPCM |
SNDRV_PCM_FMTBIT_S16_BE);
if (chip->hardware == WSS_HW_INTERWAVE && chip->dma1 > 3)
runtime->hw.formats &= ~SNDRV_PCM_FMTBIT_MU_LAW;
if (chip->hardware == WSS_HW_CS4235 ||
chip->hardware == WSS_HW_CS4239)
runtime->hw.formats = SNDRV_PCM_FMTBIT_U8 | SNDRV_PCM_FMTBIT_S16_LE;
snd_pcm_limit_isa_dma_size(chip->dma1, &runtime->hw.buffer_bytes_max);
snd_pcm_limit_isa_dma_size(chip->dma1, &runtime->hw.period_bytes_max);
if (chip->claim_dma) {
if ((err = chip->claim_dma(chip, chip->dma_private_data, chip->dma1)) < 0)
return err;
}
err = snd_wss_open(chip, WSS_MODE_PLAY);
if (err < 0) {
if (chip->release_dma)
chip->release_dma(chip, chip->dma_private_data, chip->dma1);
snd_free_pages(runtime->dma_area, runtime->dma_bytes);
return err;
}
chip->playback_substream = substream;
snd_pcm_set_sync(substream);
chip->rate_constraint(runtime);
return 0;
}
static int snd_wss_capture_open(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
runtime->hw = snd_wss_capture;
if (chip->hardware & WSS_HW_AD1848_MASK)
runtime->hw.formats &= ~(SNDRV_PCM_FMTBIT_IMA_ADPCM |
SNDRV_PCM_FMTBIT_S16_BE);
if (chip->hardware == WSS_HW_CS4235 ||
chip->hardware == WSS_HW_CS4239 ||
chip->hardware == WSS_HW_OPTI93X)
runtime->hw.formats = SNDRV_PCM_FMTBIT_U8 |
SNDRV_PCM_FMTBIT_S16_LE;
snd_pcm_limit_isa_dma_size(chip->dma2, &runtime->hw.buffer_bytes_max);
snd_pcm_limit_isa_dma_size(chip->dma2, &runtime->hw.period_bytes_max);
if (chip->claim_dma) {
if ((err = chip->claim_dma(chip, chip->dma_private_data, chip->dma2)) < 0)
return err;
}
err = snd_wss_open(chip, WSS_MODE_RECORD);
if (err < 0) {
if (chip->release_dma)
chip->release_dma(chip, chip->dma_private_data, chip->dma2);
snd_free_pages(runtime->dma_area, runtime->dma_bytes);
return err;
}
chip->capture_substream = substream;
snd_pcm_set_sync(substream);
chip->rate_constraint(runtime);
return 0;
}
static int snd_wss_playback_close(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
chip->playback_substream = NULL;
snd_wss_close(chip, WSS_MODE_PLAY);
return 0;
}
static int snd_wss_capture_close(struct snd_pcm_substream *substream)
{
struct snd_wss *chip = snd_pcm_substream_chip(substream);
chip->capture_substream = NULL;
snd_wss_close(chip, WSS_MODE_RECORD);
return 0;
}
static void snd_wss_thinkpad_twiddle(struct snd_wss *chip, int on)
{
int tmp;
if (!chip->thinkpad_flag)
return;
outb(0x1c, AD1848_THINKPAD_CTL_PORT1);
tmp = inb(AD1848_THINKPAD_CTL_PORT2);
if (on)
tmp |= AD1848_THINKPAD_CS4248_ENABLE_BIT;
else
tmp &= ~AD1848_THINKPAD_CS4248_ENABLE_BIT;
outb(tmp, AD1848_THINKPAD_CTL_PORT2);
}
static void snd_wss_suspend(struct snd_wss *chip)
{
int reg;
unsigned long flags;
snd_pcm_suspend_all(chip->pcm);
spin_lock_irqsave(&chip->reg_lock, flags);
for (reg = 0; reg < 32; reg++)
chip->image[reg] = snd_wss_in(chip, reg);
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (chip->thinkpad_flag)
snd_wss_thinkpad_twiddle(chip, 0);
}
static void snd_wss_resume(struct snd_wss *chip)
{
int reg;
unsigned long flags;
if (chip->thinkpad_flag)
snd_wss_thinkpad_twiddle(chip, 1);
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
for (reg = 0; reg < 32; reg++) {
switch (reg) {
case CS4231_VERSION:
break;
default:
snd_wss_out(chip, reg, chip->image[reg]);
break;
}
}
if (chip->hardware == WSS_HW_OPL3SA2)
snd_wss_out(chip, CS4231_PLAYBK_FORMAT,
chip->image[CS4231_PLAYBK_FORMAT]);
spin_unlock_irqrestore(&chip->reg_lock, flags);
#if 1
snd_wss_mce_down(chip);
#else
snd_wss_busy_wait(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
chip->mce_bit &= ~CS4231_MCE;
timeout = wss_inb(chip, CS4231P(REGSEL));
wss_outb(chip, CS4231P(REGSEL), chip->mce_bit | (timeout & 0x1f));
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (timeout == 0x80)
snd_printk(KERN_ERR "down [0x%lx]: serious init problem "
"- codec still busy\n", chip->port);
if ((timeout & CS4231_MCE) == 0 ||
!(chip->hardware & (WSS_HW_CS4231_MASK | WSS_HW_CS4232_MASK))) {
return;
}
snd_wss_busy_wait(chip);
#endif
}
static int snd_wss_free(struct snd_wss *chip)
{
release_and_free_resource(chip->res_port);
release_and_free_resource(chip->res_cport);
if (chip->irq >= 0) {
disable_irq(chip->irq);
if (!(chip->hwshare & WSS_HWSHARE_IRQ))
free_irq(chip->irq, (void *) chip);
}
if (!(chip->hwshare & WSS_HWSHARE_DMA1) && chip->dma1 >= 0) {
snd_dma_disable(chip->dma1);
free_dma(chip->dma1);
}
if (!(chip->hwshare & WSS_HWSHARE_DMA2) &&
chip->dma2 >= 0 && chip->dma2 != chip->dma1) {
snd_dma_disable(chip->dma2);
free_dma(chip->dma2);
}
if (chip->timer)
snd_device_free(chip->card, chip->timer);
kfree(chip);
return 0;
}
static int snd_wss_dev_free(struct snd_device *device)
{
struct snd_wss *chip = device->device_data;
return snd_wss_free(chip);
}
const char *snd_wss_chip_id(struct snd_wss *chip)
{
switch (chip->hardware) {
case WSS_HW_CS4231:
return "CS4231";
case WSS_HW_CS4231A:
return "CS4231A";
case WSS_HW_CS4232:
return "CS4232";
case WSS_HW_CS4232A:
return "CS4232A";
case WSS_HW_CS4235:
return "CS4235";
case WSS_HW_CS4236:
return "CS4236";
case WSS_HW_CS4236B:
return "CS4236B";
case WSS_HW_CS4237B:
return "CS4237B";
case WSS_HW_CS4238B:
return "CS4238B";
case WSS_HW_CS4239:
return "CS4239";
case WSS_HW_INTERWAVE:
return "AMD InterWave";
case WSS_HW_OPL3SA2:
return chip->card->shortname;
case WSS_HW_AD1845:
return "AD1845";
case WSS_HW_OPTI93X:
return "OPTi 93x";
case WSS_HW_AD1847:
return "AD1847";
case WSS_HW_AD1848:
return "AD1848";
case WSS_HW_CS4248:
return "CS4248";
case WSS_HW_CMI8330:
return "CMI8330/C3D";
default:
return "???";
}
}
static int snd_wss_new(struct snd_card *card,
unsigned short hardware,
unsigned short hwshare,
struct snd_wss **rchip)
{
struct snd_wss *chip;
*rchip = NULL;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->hardware = hardware;
chip->hwshare = hwshare;
spin_lock_init(&chip->reg_lock);
mutex_init(&chip->mce_mutex);
mutex_init(&chip->open_mutex);
chip->card = card;
chip->rate_constraint = snd_wss_xrate;
chip->set_playback_format = snd_wss_playback_format;
chip->set_capture_format = snd_wss_capture_format;
if (chip->hardware == WSS_HW_OPTI93X)
memcpy(&chip->image, &snd_opti93x_original_image,
sizeof(snd_opti93x_original_image));
else
memcpy(&chip->image, &snd_wss_original_image,
sizeof(snd_wss_original_image));
if (chip->hardware & WSS_HW_AD1848_MASK) {
chip->image[CS4231_PIN_CTRL] = 0;
chip->image[CS4231_TEST_INIT] = 0;
}
*rchip = chip;
return 0;
}
int snd_wss_create(struct snd_card *card,
unsigned long port,
unsigned long cport,
int irq, int dma1, int dma2,
unsigned short hardware,
unsigned short hwshare,
struct snd_wss **rchip)
{
static struct snd_device_ops ops = {
.dev_free = snd_wss_dev_free,
};
struct snd_wss *chip;
int err;
err = snd_wss_new(card, hardware, hwshare, &chip);
if (err < 0)
return err;
chip->irq = -1;
chip->dma1 = -1;
chip->dma2 = -1;
chip->res_port = request_region(port, 4, "WSS");
if (!chip->res_port) {
snd_printk(KERN_ERR "wss: can't grab port 0x%lx\n", port);
snd_wss_free(chip);
return -EBUSY;
}
chip->port = port;
if ((long)cport >= 0) {
chip->res_cport = request_region(cport, 8, "CS4232 Control");
if (!chip->res_cport) {
snd_printk(KERN_ERR
"wss: can't grab control port 0x%lx\n", cport);
snd_wss_free(chip);
return -ENODEV;
}
}
chip->cport = cport;
if (!(hwshare & WSS_HWSHARE_IRQ))
if (request_irq(irq, snd_wss_interrupt, 0,
"WSS", (void *) chip)) {
snd_printk(KERN_ERR "wss: can't grab IRQ %d\n", irq);
snd_wss_free(chip);
return -EBUSY;
}
chip->irq = irq;
if (!(hwshare & WSS_HWSHARE_DMA1) && request_dma(dma1, "WSS - 1")) {
snd_printk(KERN_ERR "wss: can't grab DMA1 %d\n", dma1);
snd_wss_free(chip);
return -EBUSY;
}
chip->dma1 = dma1;
if (!(hwshare & WSS_HWSHARE_DMA2) && dma1 != dma2 &&
dma2 >= 0 && request_dma(dma2, "WSS - 2")) {
snd_printk(KERN_ERR "wss: can't grab DMA2 %d\n", dma2);
snd_wss_free(chip);
return -EBUSY;
}
if (dma1 == dma2 || dma2 < 0) {
chip->single_dma = 1;
chip->dma2 = chip->dma1;
} else
chip->dma2 = dma2;
if (hardware == WSS_HW_THINKPAD) {
chip->thinkpad_flag = 1;
chip->hardware = WSS_HW_DETECT;
snd_wss_thinkpad_twiddle(chip, 1);
}
if (snd_wss_probe(chip) < 0) {
snd_wss_free(chip);
return -ENODEV;
}
snd_wss_init(chip);
#if 0
if (chip->hardware & WSS_HW_CS4232_MASK) {
if (chip->res_cport == NULL)
snd_printk(KERN_ERR "CS4232 control port features are "
"not accessible\n");
}
#endif
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
snd_wss_free(chip);
return err;
}
#ifdef CONFIG_PM
chip->suspend = snd_wss_suspend;
chip->resume = snd_wss_resume;
#endif
*rchip = chip;
return 0;
}
int snd_wss_pcm(struct snd_wss *chip, int device, struct snd_pcm **rpcm)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(chip->card, "WSS", device, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_wss_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_wss_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
if (chip->single_dma)
pcm->info_flags |= SNDRV_PCM_INFO_HALF_DUPLEX;
if (chip->hardware != WSS_HW_INTERWAVE)
pcm->info_flags |= SNDRV_PCM_INFO_JOINT_DUPLEX;
strcpy(pcm->name, snd_wss_chip_id(chip));
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_isa_data(),
64*1024, chip->dma1 > 3 || chip->dma2 > 3 ? 128*1024 : 64*1024);
chip->pcm = pcm;
if (rpcm)
*rpcm = pcm;
return 0;
}
static void snd_wss_timer_free(struct snd_timer *timer)
{
struct snd_wss *chip = timer->private_data;
chip->timer = NULL;
}
int snd_wss_timer(struct snd_wss *chip, int device, struct snd_timer **rtimer)
{
struct snd_timer *timer;
struct snd_timer_id tid;
int err;
tid.dev_class = SNDRV_TIMER_CLASS_CARD;
tid.dev_sclass = SNDRV_TIMER_SCLASS_NONE;
tid.card = chip->card->number;
tid.device = device;
tid.subdevice = 0;
if ((err = snd_timer_new(chip->card, "CS4231", &tid, &timer)) < 0)
return err;
strcpy(timer->name, snd_wss_chip_id(chip));
timer->private_data = chip;
timer->private_free = snd_wss_timer_free;
timer->hw = snd_wss_timer_table;
chip->timer = timer;
if (rtimer)
*rtimer = timer;
return 0;
}
static int snd_wss_info_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[4] = {
"Line", "Aux", "Mic", "Mix"
};
static char *opl3sa_texts[4] = {
"Line", "CD", "Mic", "Mix"
};
static char *gusmax_texts[4] = {
"Line", "Synth", "Mic", "Mix"
};
char **ptexts = texts;
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
if (snd_BUG_ON(!chip->card))
return -EINVAL;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 2;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item > 3)
uinfo->value.enumerated.item = 3;
if (!strcmp(chip->card->driver, "GUS MAX"))
ptexts = gusmax_texts;
switch (chip->hardware) {
case WSS_HW_INTERWAVE:
ptexts = gusmax_texts;
break;
case WSS_HW_OPTI93X:
case WSS_HW_OPL3SA2:
ptexts = opl3sa_texts;
break;
}
strcpy(uinfo->value.enumerated.name, ptexts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_wss_get_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.enumerated.item[0] = (chip->image[CS4231_LEFT_INPUT] & CS4231_MIXS_ALL) >> 6;
ucontrol->value.enumerated.item[1] = (chip->image[CS4231_RIGHT_INPUT] & CS4231_MIXS_ALL) >> 6;
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int snd_wss_put_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
unsigned short left, right;
int change;
if (ucontrol->value.enumerated.item[0] > 3 ||
ucontrol->value.enumerated.item[1] > 3)
return -EINVAL;
left = ucontrol->value.enumerated.item[0] << 6;
right = ucontrol->value.enumerated.item[1] << 6;
spin_lock_irqsave(&chip->reg_lock, flags);
left = (chip->image[CS4231_LEFT_INPUT] & ~CS4231_MIXS_ALL) | left;
right = (chip->image[CS4231_RIGHT_INPUT] & ~CS4231_MIXS_ALL) | right;
change = left != chip->image[CS4231_LEFT_INPUT] ||
right != chip->image[CS4231_RIGHT_INPUT];
snd_wss_out(chip, CS4231_LEFT_INPUT, left);
snd_wss_out(chip, CS4231_RIGHT_INPUT, right);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
int snd_wss_info_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
int snd_wss_get_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->image[reg] >> shift) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
int snd_wss_put_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int change;
unsigned short val;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
val <<= shift;
spin_lock_irqsave(&chip->reg_lock, flags);
val = (chip->image[reg] & ~(mask << shift)) | val;
change = val != chip->image[reg];
snd_wss_out(chip, reg, val);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
int snd_wss_info_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 24) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
int snd_wss_get_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->image[left_reg] >> shift_left) & mask;
ucontrol->value.integer.value[1] = (chip->image[right_reg] >> shift_right) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
int snd_wss_put_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wss *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
int change;
unsigned short val1, val2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
val1 <<= shift_left;
val2 <<= shift_right;
spin_lock_irqsave(&chip->reg_lock, flags);
if (left_reg != right_reg) {
val1 = (chip->image[left_reg] & ~(mask << shift_left)) | val1;
val2 = (chip->image[right_reg] & ~(mask << shift_right)) | val2;
change = val1 != chip->image[left_reg] ||
val2 != chip->image[right_reg];
snd_wss_out(chip, left_reg, val1);
snd_wss_out(chip, right_reg, val2);
} else {
mask = (mask << shift_left) | (mask << shift_right);
val1 = (chip->image[left_reg] & ~mask) | val1 | val2;
change = val1 != chip->image[left_reg];
snd_wss_out(chip, left_reg, val1);
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
int snd_wss_mixer(struct snd_wss *chip)
{
struct snd_card *card;
unsigned int idx;
int err;
int count = ARRAY_SIZE(snd_wss_controls);
if (snd_BUG_ON(!chip || !chip->pcm))
return -EINVAL;
card = chip->card;
strcpy(card->mixername, chip->pcm->name);
if (chip->hardware & WSS_HW_AD1848_MASK)
count = 11;
else if (chip->hardware == WSS_HW_OPTI93X)
count = 9;
for (idx = 0; idx < count; idx++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_wss_controls[idx],
chip));
if (err < 0)
return err;
}
return 0;
}
const struct snd_pcm_ops *snd_wss_get_pcm_ops(int direction)
{
return direction == SNDRV_PCM_STREAM_PLAYBACK ?
&snd_wss_playback_ops : &snd_wss_capture_ops;
}
static int __init alsa_wss_init(void)
{
return 0;
}
static void __exit alsa_wss_exit(void)
{
}
