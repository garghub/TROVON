static inline void
waveartist_set_ctlr(struct address_info *hw, unsigned char clear, unsigned char set)
{
unsigned int ctlr_port = hw->io_base + CTLR;
clear = ~clear & inb(ctlr_port);
outb(clear | set, ctlr_port);
}
static inline void
waveartist_iack(struct wavnc_info *devc)
{
unsigned int ctlr_port = devc->hw.io_base + CTLR;
int old_ctlr;
old_ctlr = inb(ctlr_port) & ~IRQ_ACK;
outb(old_ctlr | IRQ_ACK, ctlr_port);
outb(old_ctlr, ctlr_port);
}
static inline int
waveartist_sleep(int timeout_ms)
{
unsigned int timeout = msecs_to_jiffies(timeout_ms*100);
return schedule_timeout_interruptible(timeout);
}
static int
waveartist_reset(struct wavnc_info *devc)
{
struct address_info *hw = &devc->hw;
unsigned int timeout, res = -1;
waveartist_set_ctlr(hw, -1, RESET);
waveartist_sleep(2);
waveartist_set_ctlr(hw, RESET, 0);
timeout = 500;
do {
mdelay(2);
if (inb(hw->io_base + STATR) & CMD_RF) {
res = inw(hw->io_base + CMDR);
if (res == 0x55aa)
break;
}
} while (--timeout);
if (timeout == 0) {
printk(KERN_WARNING "WaveArtist: reset timeout ");
if (res != (unsigned int)-1)
printk("(res=%04X)", res);
printk("\n");
return 1;
}
return 0;
}
static int
waveartist_cmd(struct wavnc_info *devc,
int nr_cmd, unsigned int *cmd,
int nr_resp, unsigned int *resp)
{
unsigned int io_base = devc->hw.io_base;
unsigned int timed_out = 0;
unsigned int i;
if (debug_flg & DEBUG_CMD) {
printk("waveartist_cmd: cmd=");
for (i = 0; i < nr_cmd; i++)
printk("%04X ", cmd[i]);
printk("\n");
}
if (inb(io_base + STATR) & CMD_RF) {
int old_data;
old_data = inw(io_base + CMDR);
if (debug_flg & DEBUG_CMD)
printk("flushed %04X...", old_data);
udelay(10);
}
for (i = 0; !timed_out && i < nr_cmd; i++) {
int count;
for (count = 5000; count; count--)
if (inb(io_base + STATR) & CMD_WE)
break;
if (!count)
timed_out = 1;
else
outw(cmd[i], io_base + CMDR);
}
for (i = 0; !timed_out && i < nr_resp; i++) {
int count;
for (count = 5000; count; count--)
if (inb(io_base + STATR) & CMD_RF)
break;
if (!count)
timed_out = 1;
else
resp[i] = inw(io_base + CMDR);
}
if (debug_flg & DEBUG_CMD) {
if (!timed_out) {
printk("waveartist_cmd: resp=");
for (i = 0; i < nr_resp; i++)
printk("%04X ", resp[i]);
printk("\n");
} else
printk("waveartist_cmd: timed out\n");
}
return timed_out ? 1 : 0;
}
static inline int
waveartist_cmd1(struct wavnc_info *devc, unsigned int cmd)
{
return waveartist_cmd(devc, 1, &cmd, 0, NULL);
}
static inline unsigned int
waveartist_cmd1_r(struct wavnc_info *devc, unsigned int cmd)
{
unsigned int ret;
waveartist_cmd(devc, 1, &cmd, 1, &ret);
return ret;
}
static inline int
waveartist_cmd2(struct wavnc_info *devc, unsigned int cmd, unsigned int arg)
{
unsigned int vals[2];
vals[0] = cmd;
vals[1] = arg;
return waveartist_cmd(devc, 2, vals, 1, vals);
}
static inline int
waveartist_cmd3(struct wavnc_info *devc, unsigned int cmd,
unsigned int arg1, unsigned int arg2)
{
unsigned int vals[3];
vals[0] = cmd;
vals[1] = arg1;
vals[2] = arg2;
return waveartist_cmd(devc, 3, vals, 0, NULL);
}
static int
waveartist_getrev(struct wavnc_info *devc, char *rev)
{
unsigned int temp[2];
unsigned int cmd = WACMD_GETREV;
waveartist_cmd(devc, 1, &cmd, 2, temp);
rev[0] = temp[0] >> 8;
rev[1] = temp[0] & 255;
rev[2] = '\0';
return temp[0];
}
static int
waveartist_open(int dev, int mode)
{
struct wavnc_info *devc;
struct wavnc_port_info *portc;
unsigned long flags;
if (dev < 0 || dev >= num_audiodevs)
return -ENXIO;
devc = (struct wavnc_info *) audio_devs[dev]->devc;
portc = (struct wavnc_port_info *) audio_devs[dev]->portc;
spin_lock_irqsave(&waveartist_lock, flags);
if (portc->open_mode || (devc->open_mode & mode)) {
spin_unlock_irqrestore(&waveartist_lock, flags);
return -EBUSY;
}
devc->audio_mode = 0;
devc->open_mode |= mode;
portc->open_mode = mode;
waveartist_trigger(dev, 0);
if (mode & OPEN_READ)
devc->record_dev = dev;
if (mode & OPEN_WRITE)
devc->playback_dev = dev;
spin_unlock_irqrestore(&waveartist_lock, flags);
return 0;
}
static void
waveartist_close(int dev)
{
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
unsigned long flags;
spin_lock_irqsave(&waveartist_lock, flags);
waveartist_halt(dev);
devc->audio_mode = 0;
devc->open_mode &= ~portc->open_mode;
portc->open_mode = 0;
spin_unlock_irqrestore(&waveartist_lock, flags);
}
static void
waveartist_output_block(int dev, unsigned long buf, int __count, int intrflag)
{
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
unsigned long flags;
unsigned int count = __count;
if (debug_flg & DEBUG_OUT)
printk("waveartist: output block, buf=0x%lx, count=0x%x...\n",
buf, count);
if (portc->audio_format & (AFMT_S16_LE | AFMT_S16_BE))
count >>= 1;
if (portc->channels > 1)
count >>= 1;
count -= 1;
if (devc->audio_mode & PCM_ENABLE_OUTPUT &&
audio_devs[dev]->flags & DMA_AUTOMODE &&
intrflag &&
count == devc->xfer_count) {
devc->audio_mode |= PCM_ENABLE_OUTPUT;
return;
}
spin_lock_irqsave(&waveartist_lock, flags);
waveartist_cmd2(devc, WACMD_OUTPUTSIZE, count);
devc->xfer_count = count;
devc->audio_mode |= PCM_ENABLE_OUTPUT;
spin_unlock_irqrestore(&waveartist_lock, flags);
}
static void
waveartist_start_input(int dev, unsigned long buf, int __count, int intrflag)
{
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
unsigned long flags;
unsigned int count = __count;
if (debug_flg & DEBUG_IN)
printk("waveartist: start input, buf=0x%lx, count=0x%x...\n",
buf, count);
if (portc->audio_format & (AFMT_S16_LE | AFMT_S16_BE))
count >>= 1;
if (portc->channels > 1)
count >>= 1;
count -= 1;
if (devc->audio_mode & PCM_ENABLE_INPUT &&
audio_devs[dev]->flags & DMA_AUTOMODE &&
intrflag &&
count == devc->xfer_count) {
devc->audio_mode |= PCM_ENABLE_INPUT;
return;
}
spin_lock_irqsave(&waveartist_lock, flags);
waveartist_cmd2(devc, WACMD_INPUTSIZE, count);
devc->xfer_count = count;
devc->audio_mode |= PCM_ENABLE_INPUT;
spin_unlock_irqrestore(&waveartist_lock, flags);
}
static int
waveartist_ioctl(int dev, unsigned int cmd, void __user * arg)
{
return -EINVAL;
}
static unsigned int
waveartist_get_speed(struct wavnc_port_info *portc)
{
unsigned int speed;
if (portc->speed == 8000)
speed = 0x2E71;
else if (portc->speed == 11025)
speed = 0x4000;
else if (portc->speed == 22050)
speed = 0x8000;
else if (portc->speed == 44100)
speed = 0x0;
else {
speed = portc->speed << 16;
speed = (speed / 44100) & 65535;
}
return speed;
}
static unsigned int
waveartist_get_bits(struct wavnc_port_info *portc)
{
unsigned int bits;
if (portc->audio_format == AFMT_S16_LE)
bits = 1;
else if (portc->audio_format == AFMT_S8)
bits = 0;
else
bits = 2;
return bits;
}
static int
waveartist_prepare_for_input(int dev, int bsize, int bcount)
{
unsigned long flags;
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
unsigned int speed, bits;
if (devc->audio_mode)
return 0;
speed = waveartist_get_speed(portc);
bits = waveartist_get_bits(portc);
spin_lock_irqsave(&waveartist_lock, flags);
if (waveartist_cmd2(devc, WACMD_INPUTFORMAT, bits))
printk(KERN_WARNING "waveartist: error setting the "
"record format to %d\n", portc->audio_format);
if (waveartist_cmd2(devc, WACMD_INPUTCHANNELS, portc->channels))
printk(KERN_WARNING "waveartist: error setting record "
"to %d channels\n", portc->channels);
if (waveartist_cmd2(devc, WACMD_INPUTSPEED, speed))
printk(KERN_WARNING "waveartist: error setting the record "
"speed to %dHz.\n", portc->speed);
if (waveartist_cmd2(devc, WACMD_INPUTDMA, 1))
printk(KERN_WARNING "waveartist: error setting the record "
"data path to 0x%X\n", 1);
if (waveartist_cmd2(devc, WACMD_INPUTFORMAT, bits))
printk(KERN_WARNING "waveartist: error setting the record "
"format to %d\n", portc->audio_format);
devc->xfer_count = 0;
spin_unlock_irqrestore(&waveartist_lock, flags);
waveartist_halt_input(dev);
if (debug_flg & DEBUG_INTR) {
printk("WA CTLR reg: 0x%02X.\n",
inb(devc->hw.io_base + CTLR));
printk("WA STAT reg: 0x%02X.\n",
inb(devc->hw.io_base + STATR));
printk("WA IRQS reg: 0x%02X.\n",
inb(devc->hw.io_base + IRQSTAT));
}
return 0;
}
static int
waveartist_prepare_for_output(int dev, int bsize, int bcount)
{
unsigned long flags;
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
unsigned int speed, bits;
speed = waveartist_get_speed(portc);
bits = waveartist_get_bits(portc);
spin_lock_irqsave(&waveartist_lock, flags);
if (waveartist_cmd2(devc, WACMD_OUTPUTSPEED, speed) &&
waveartist_cmd2(devc, WACMD_OUTPUTSPEED, speed))
printk(KERN_WARNING "waveartist: error setting the playback "
"speed to %dHz.\n", portc->speed);
if (waveartist_cmd2(devc, WACMD_OUTPUTCHANNELS, portc->channels))
printk(KERN_WARNING "waveartist: error setting the playback "
"to %d channels\n", portc->channels);
if (waveartist_cmd2(devc, WACMD_OUTPUTDMA, 0))
printk(KERN_WARNING "waveartist: error setting the playback "
"data path to 0x%X\n", 0);
if (waveartist_cmd2(devc, WACMD_OUTPUTFORMAT, bits))
printk(KERN_WARNING "waveartist: error setting the playback "
"format to %d\n", portc->audio_format);
devc->xfer_count = 0;
spin_unlock_irqrestore(&waveartist_lock, flags);
waveartist_halt_output(dev);
if (debug_flg & DEBUG_INTR) {
printk("WA CTLR reg: 0x%02X.\n",inb(devc->hw.io_base + CTLR));
printk("WA STAT reg: 0x%02X.\n",inb(devc->hw.io_base + STATR));
printk("WA IRQS reg: 0x%02X.\n",inb(devc->hw.io_base + IRQSTAT));
}
return 0;
}
static void
waveartist_halt(int dev)
{
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
struct wavnc_info *devc;
if (portc->open_mode & OPEN_WRITE)
waveartist_halt_output(dev);
if (portc->open_mode & OPEN_READ)
waveartist_halt_input(dev);
devc = (struct wavnc_info *) audio_devs[dev]->devc;
devc->audio_mode = 0;
}
static void
waveartist_halt_input(int dev)
{
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
unsigned long flags;
spin_lock_irqsave(&waveartist_lock, flags);
waveartist_cmd1(devc, WACMD_INPUTSTOP);
devc->audio_mode &= ~PCM_ENABLE_INPUT;
if (inb(devc->hw.io_base + STATR) & IRQ_REQ)
waveartist_iack(devc);
spin_unlock_irqrestore(&waveartist_lock, flags);
}
static void
waveartist_halt_output(int dev)
{
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
unsigned long flags;
spin_lock_irqsave(&waveartist_lock, flags);
waveartist_cmd1(devc, WACMD_OUTPUTSTOP);
devc->audio_mode &= ~PCM_ENABLE_OUTPUT;
if (inb(devc->hw.io_base + STATR) & IRQ_REQ)
waveartist_iack(devc);
spin_unlock_irqrestore(&waveartist_lock, flags);
}
static void
waveartist_trigger(int dev, int state)
{
struct wavnc_info *devc = (struct wavnc_info *)
audio_devs[dev]->devc;
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
unsigned long flags;
if (debug_flg & DEBUG_TRIGGER) {
printk("wavnc: audio trigger ");
if (state & PCM_ENABLE_INPUT)
printk("in ");
if (state & PCM_ENABLE_OUTPUT)
printk("out");
printk("\n");
}
spin_lock_irqsave(&waveartist_lock, flags);
state &= devc->audio_mode;
if (portc->open_mode & OPEN_READ &&
state & PCM_ENABLE_INPUT)
waveartist_cmd1(devc, WACMD_INPUTSTART);
if (portc->open_mode & OPEN_WRITE &&
state & PCM_ENABLE_OUTPUT)
waveartist_cmd1(devc, WACMD_OUTPUTSTART);
spin_unlock_irqrestore(&waveartist_lock, flags);
}
static int
waveartist_set_speed(int dev, int arg)
{
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
if (arg <= 0)
return portc->speed;
if (arg < 5000)
arg = 5000;
if (arg > 44100)
arg = 44100;
portc->speed = arg;
return portc->speed;
}
static short
waveartist_set_channels(int dev, short arg)
{
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
if (arg != 1 && arg != 2)
return portc->channels;
portc->channels = arg;
return arg;
}
static unsigned int
waveartist_set_bits(int dev, unsigned int arg)
{
struct wavnc_port_info *portc = (struct wavnc_port_info *)
audio_devs[dev]->portc;
if (arg == 0)
return portc->audio_format;
if ((arg != AFMT_U8) && (arg != AFMT_S16_LE) && (arg != AFMT_S8))
arg = AFMT_U8;
portc->audio_format = arg;
return arg;
}
static irqreturn_t
waveartist_intr(int irq, void *dev_id)
{
struct wavnc_info *devc = dev_id;
int irqstatus, status;
spin_lock(&waveartist_lock);
irqstatus = inb(devc->hw.io_base + IRQSTAT);
status = inb(devc->hw.io_base + STATR);
if (debug_flg & DEBUG_INTR)
printk("waveartist_intr: stat=%02x, irqstat=%02x\n",
status, irqstatus);
if (status & IRQ_REQ)
waveartist_iack(devc);
else
printk(KERN_WARNING "waveartist: unexpected interrupt\n");
if (irqstatus & 0x01) {
int temp = 1;
if ((status & DMA0) && (devc->audio_mode & PCM_ENABLE_OUTPUT)) {
DMAbuf_outputintr(devc->playback_dev, 1);
temp = 0;
}
if ((status & DMA1) && (devc->audio_mode & PCM_ENABLE_INPUT)) {
DMAbuf_inputintr(devc->record_dev);
temp = 0;
}
if (temp)
printk(KERN_WARNING "waveartist: Unknown interrupt\n");
}
if (irqstatus & 0x2)
printk(KERN_WARNING "waveartist: Unexpected SB interrupt...\n");
spin_unlock(&waveartist_lock);
return IRQ_HANDLED;
}
static void
waveartist_mixer_update(struct wavnc_info *devc, int whichDev)
{
unsigned int lev_left, lev_right;
lev_left = devc->levels[whichDev] & 0xff;
lev_right = devc->levels[whichDev] >> 8;
if (lev_left > 100)
lev_left = 100;
if (lev_right > 100)
lev_right = 100;
#define SCALE(lev,max) ((lev) * (max) / 100)
if (machine_is_netwinder() && whichDev == SOUND_MIXER_PHONEOUT)
whichDev = SOUND_MIXER_VOLUME;
if (mix_devs[whichDev].reg_l || mix_devs[whichDev].reg_r) {
const struct mix_ent *mix = mix_devs + whichDev;
unsigned int mask, left, right;
mask = mix->max << mix->shift;
lev_left = SCALE(lev_left, mix->max) << mix->shift;
lev_right = SCALE(lev_right, mix->max) << mix->shift;
left = waveartist_cmd1_r(devc, WACMD_GET_LEVEL |
mix->reg_l << 8);
right = waveartist_cmd1_r(devc, WACMD_GET_LEVEL |
mix->reg_r << 8);
left = (left & ~mask) | (lev_left & mask);
right = (right & ~mask) | (lev_right & mask);
waveartist_cmd3(devc, WACMD_SET_MIXER, left, right);
} else {
switch(whichDev) {
case SOUND_MIXER_PCM:
waveartist_cmd3(devc, WACMD_SET_LEVEL,
SCALE(lev_left, 32767),
SCALE(lev_right, 32767));
break;
case SOUND_MIXER_SYNTH:
waveartist_cmd3(devc, 0x0100 | WACMD_SET_LEVEL,
SCALE(lev_left, 32767),
SCALE(lev_right, 32767));
break;
}
}
}
static void
waveartist_set_adc_mux(struct wavnc_info *devc, char left_dev,
char right_dev)
{
unsigned int reg_08, reg_09;
reg_08 = waveartist_cmd1_r(devc, WACMD_GET_LEVEL | 0x0800);
reg_09 = waveartist_cmd1_r(devc, WACMD_GET_LEVEL | 0x0900);
reg_08 = (reg_08 & ~0x3f) | right_dev << 3 | left_dev;
waveartist_cmd3(devc, WACMD_SET_MIXER, reg_08, reg_09);
}
static unsigned int
waveartist_select_input(struct wavnc_info *devc, unsigned int recmask,
unsigned char *dev_l, unsigned char *dev_r)
{
unsigned int recdev = ADC_MUX_NONE;
if (recmask & SOUND_MASK_IMIX) {
recmask = SOUND_MASK_IMIX;
recdev = ADC_MUX_MIXER;
} else if (recmask & SOUND_MASK_LINE2) {
recmask = SOUND_MASK_LINE2;
recdev = ADC_MUX_AUX2;
} else if (recmask & SOUND_MASK_LINE1) {
recmask = SOUND_MASK_LINE1;
recdev = ADC_MUX_AUX1;
} else if (recmask & SOUND_MASK_LINE) {
recmask = SOUND_MASK_LINE;
recdev = ADC_MUX_LINE;
} else if (recmask & SOUND_MASK_MIC) {
recmask = SOUND_MASK_MIC;
recdev = ADC_MUX_MIC;
}
*dev_l = *dev_r = recdev;
return recmask;
}
static int
waveartist_decode_mixer(struct wavnc_info *devc, int dev,
unsigned char lev_l,
unsigned char lev_r)
{
switch (dev) {
case SOUND_MIXER_VOLUME:
case SOUND_MIXER_SYNTH:
case SOUND_MIXER_PCM:
case SOUND_MIXER_LINE:
case SOUND_MIXER_MIC:
case SOUND_MIXER_IGAIN:
case SOUND_MIXER_LINE1:
case SOUND_MIXER_LINE2:
devc->levels[dev] = lev_l | lev_r << 8;
break;
case SOUND_MIXER_IMIX:
break;
default:
dev = -EINVAL;
break;
}
return dev;
}
static int waveartist_get_mixer(struct wavnc_info *devc, int dev)
{
return devc->levels[dev];
}
static void
waveartist_set_recmask(struct wavnc_info *devc, unsigned int recmask)
{
unsigned char dev_l, dev_r;
recmask &= devc->mix->recording_devs;
if (hweight32(recmask) > 1)
recmask &= ~devc->recmask;
devc->recmask = devc->mix->select_input(devc, recmask,
&dev_l, &dev_r);
waveartist_set_adc_mux(devc, dev_l, dev_r);
}
static int
waveartist_set_mixer(struct wavnc_info *devc, int dev, unsigned int level)
{
unsigned int lev_left = level & 0x00ff;
unsigned int lev_right = (level & 0xff00) >> 8;
if (lev_left > 100)
lev_left = 100;
if (lev_right > 100)
lev_right = 100;
if (!(devc->mix->stereo_devs & (1 << dev)))
lev_right = lev_left;
dev = devc->mix->decode_mixer(devc, dev, lev_left, lev_right);
if (dev >= 0)
waveartist_mixer_update(devc, dev);
return dev < 0 ? dev : 0;
}
static int
waveartist_mixer_ioctl(int dev, unsigned int cmd, void __user * arg)
{
struct wavnc_info *devc = (struct wavnc_info *)audio_devs[dev]->devc;
int ret = 0, val, nr;
if (((cmd >> 8) & 255) != 'M')
return -ENOIOCTLCMD;
#ifdef CONFIG_ARCH_NETWINDER
if (machine_is_netwinder()) {
ret = vnc_private_ioctl(dev, cmd, arg);
if (ret != -ENOIOCTLCMD)
return ret;
else
ret = 0;
}
#endif
nr = cmd & 0xff;
if (_SIOC_DIR(cmd) & _SIOC_WRITE) {
if (get_user(val, (int __user *)arg))
return -EFAULT;
switch (nr) {
case SOUND_MIXER_RECSRC:
waveartist_set_recmask(devc, val);
break;
default:
ret = -EINVAL;
if (nr < SOUND_MIXER_NRDEVICES &&
devc->mix->supported_devs & (1 << nr))
ret = waveartist_set_mixer(devc, nr, val);
}
}
if (ret == 0 && _SIOC_DIR(cmd) & _SIOC_READ) {
ret = -EINVAL;
switch (nr) {
case SOUND_MIXER_RECSRC:
ret = devc->recmask;
break;
case SOUND_MIXER_DEVMASK:
ret = devc->mix->supported_devs;
break;
case SOUND_MIXER_STEREODEVS:
ret = devc->mix->stereo_devs;
break;
case SOUND_MIXER_RECMASK:
ret = devc->mix->recording_devs;
break;
case SOUND_MIXER_CAPS:
ret = SOUND_CAP_EXCL_INPUT;
break;
default:
if (nr < SOUND_MIXER_NRDEVICES)
ret = devc->mix->get_mixer(devc, nr);
break;
}
if (ret >= 0)
ret = put_user(ret, (int __user *)arg) ? -EFAULT : 0;
}
return ret;
}
static void
waveartist_mixer_reset(struct wavnc_info *devc)
{
int i;
if (debug_flg & DEBUG_MIXER)
printk("%s: mixer_reset\n", devc->hw.name);
waveartist_cmd1(devc, WACMD_RST_MIXER);
waveartist_cmd3(devc, WACMD_SET_MIXER, 0x9800, 0xa836);
waveartist_cmd3(devc, WACMD_SET_MIXER, 0x4c00, 0x8c00);
waveartist_cmd3(devc, WACMD_SET_MIXER, 0x2801, 0x6800);
waveartist_set_recmask(devc, 0);
for (i = 0; i < SOUND_MIXER_NRDEVICES; i++)
waveartist_mixer_update(devc, i);
}
static int __init waveartist_init(struct wavnc_info *devc)
{
struct wavnc_port_info *portc;
char rev[3], dev_name[64];
int my_dev;
if (waveartist_reset(devc))
return -ENODEV;
sprintf(dev_name, "%s (%s", devc->hw.name, devc->chip_name);
if (waveartist_getrev(devc, rev)) {
strcat(dev_name, " rev. ");
strcat(dev_name, rev);
}
strcat(dev_name, ")");
conf_printf2(dev_name, devc->hw.io_base, devc->hw.irq,
devc->hw.dma, devc->hw.dma2);
portc = kzalloc(sizeof(struct wavnc_port_info), GFP_KERNEL);
if (portc == NULL)
goto nomem;
my_dev = sound_install_audiodrv(AUDIO_DRIVER_VERSION, dev_name,
&waveartist_audio_driver, sizeof(struct audio_driver),
devc->audio_flags, AFMT_U8 | AFMT_S16_LE | AFMT_S8,
devc, devc->hw.dma, devc->hw.dma2);
if (my_dev < 0)
goto free;
audio_devs[my_dev]->portc = portc;
waveartist_mixer_reset(devc);
waveartist_iack(devc);
if (request_irq(devc->hw.irq, waveartist_intr, 0, devc->hw.name, devc) < 0) {
printk(KERN_ERR "%s: IRQ %d in use\n",
devc->hw.name, devc->hw.irq);
goto uninstall;
}
if (sound_alloc_dma(devc->hw.dma, devc->hw.name)) {
printk(KERN_ERR "%s: Can't allocate DMA%d\n",
devc->hw.name, devc->hw.dma);
goto uninstall_irq;
}
if (devc->hw.dma != devc->hw.dma2 && devc->hw.dma2 != NO_DMA)
if (sound_alloc_dma(devc->hw.dma2, devc->hw.name)) {
printk(KERN_ERR "%s: can't allocate DMA%d\n",
devc->hw.name, devc->hw.dma2);
goto uninstall_dma;
}
waveartist_set_ctlr(&devc->hw, 0, DMA1_IE | DMA0_IE);
audio_devs[my_dev]->mixer_dev =
sound_install_mixer(MIXER_DRIVER_VERSION,
dev_name,
&waveartist_mixer_operations,
sizeof(struct mixer_operations),
devc);
return my_dev;
uninstall_dma:
sound_free_dma(devc->hw.dma);
uninstall_irq:
free_irq(devc->hw.irq, devc);
uninstall:
sound_unload_audiodev(my_dev);
free:
kfree(portc);
nomem:
return -1;
}
static int __init probe_waveartist(struct address_info *hw_config)
{
struct wavnc_info *devc = &adev_info[nr_waveartist_devs];
if (nr_waveartist_devs >= MAX_AUDIO_DEV) {
printk(KERN_WARNING "waveartist: too many audio devices\n");
return 0;
}
if (!request_region(hw_config->io_base, 15, hw_config->name)) {
printk(KERN_WARNING "WaveArtist: I/O port conflict\n");
return 0;
}
if (hw_config->irq > 15 || hw_config->irq < 0) {
release_region(hw_config->io_base, 15);
printk(KERN_WARNING "WaveArtist: Bad IRQ %d\n",
hw_config->irq);
return 0;
}
if (hw_config->dma != 3) {
release_region(hw_config->io_base, 15);
printk(KERN_WARNING "WaveArtist: Bad DMA %d\n",
hw_config->dma);
return 0;
}
hw_config->name = "WaveArtist";
devc->hw = *hw_config;
devc->open_mode = 0;
devc->chip_name = "RWA-010";
return 1;
}
static void __init
attach_waveartist(struct address_info *hw, const struct waveartist_mixer_info *mix)
{
struct wavnc_info *devc = &adev_info[nr_waveartist_devs];
devc->hw = *hw;
devc->hw.irq = (hw->irq > 0) ? hw->irq : 0;
devc->open_mode = 0;
devc->playback_dev = 0;
devc->record_dev = 0;
devc->audio_flags = DMA_AUTOMODE;
devc->levels = levels;
if (hw->dma != hw->dma2 && hw->dma2 != NO_DMA)
devc->audio_flags |= DMA_DUPLEX;
devc->mix = mix;
devc->dev_no = waveartist_init(devc);
if (devc->dev_no < 0)
release_region(hw->io_base, 15);
else {
#ifdef CONFIG_ARCH_NETWINDER
if (machine_is_netwinder()) {
setup_timer(&vnc_timer, vnc_slider_tick,
nr_waveartist_devs);
mod_timer(&vnc_timer, jiffies);
vnc_configure_mixer(devc, 0);
devc->no_autoselect = 1;
}
#endif
nr_waveartist_devs += 1;
}
}
static void __exit unload_waveartist(struct address_info *hw)
{
struct wavnc_info *devc = NULL;
int i;
for (i = 0; i < nr_waveartist_devs; i++)
if (hw->io_base == adev_info[i].hw.io_base) {
devc = adev_info + i;
break;
}
if (devc != NULL) {
int mixer;
#ifdef CONFIG_ARCH_NETWINDER
if (machine_is_netwinder())
del_timer(&vnc_timer);
#endif
release_region(devc->hw.io_base, 15);
waveartist_set_ctlr(&devc->hw, DMA1_IE|DMA0_IE, 0);
if (devc->hw.irq >= 0)
free_irq(devc->hw.irq, devc);
sound_free_dma(devc->hw.dma);
if (devc->hw.dma != devc->hw.dma2 &&
devc->hw.dma2 != NO_DMA)
sound_free_dma(devc->hw.dma2);
mixer = audio_devs[devc->dev_no]->mixer_dev;
if (mixer >= 0)
sound_unload_mixerdev(mixer);
if (devc->dev_no >= 0)
sound_unload_audiodev(devc->dev_no);
nr_waveartist_devs -= 1;
for (; i < nr_waveartist_devs; i++)
adev_info[i] = adev_info[i + 1];
} else
printk(KERN_WARNING "waveartist: can't find device "
"to unload\n");
}
static inline void
vnc_mute_spkr(struct wavnc_info *devc)
{
unsigned long flags;
raw_spin_lock_irqsave(&nw_gpio_lock, flags);
nw_cpld_modify(CPLD_UNMUTE, devc->spkr_mute_state ? 0 : CPLD_UNMUTE);
raw_spin_unlock_irqrestore(&nw_gpio_lock, flags);
}
static void
vnc_mute_lout(struct wavnc_info *devc)
{
unsigned int left, right;
left = waveartist_cmd1_r(devc, WACMD_GET_LEVEL);
right = waveartist_cmd1_r(devc, WACMD_GET_LEVEL | 0x400);
if (devc->line_mute_state) {
left &= ~1;
right &= ~1;
} else {
left |= 1;
right |= 1;
}
waveartist_cmd3(devc, WACMD_SET_MIXER, left, right);
}
static int
vnc_volume_slider(struct wavnc_info *devc)
{
static signed int old_slider_volume;
unsigned long flags;
signed int volume = 255;
*CSR_TIMER1_LOAD = 0x00ffffff;
spin_lock_irqsave(&waveartist_lock, flags);
outb(0xFF, 0x201);
*CSR_TIMER1_CNTL = TIMER_CNTL_ENABLE | TIMER_CNTL_DIV1;
while (volume && (inb(0x201) & 0x01))
volume--;
*CSR_TIMER1_CNTL = 0;
spin_unlock_irqrestore(&waveartist_lock,flags);
volume = 0x00ffffff - *CSR_TIMER1_VALUE;
#ifndef REVERSE
volume = 150 - (volume >> 5);
#else
volume = (volume >> 6) - 25;
#endif
if (volume < 0)
volume = 0;
if (volume > 100)
volume = 100;
if (abs(volume - old_slider_volume) > 7) {
old_slider_volume = volume;
if (debug_flg & DEBUG_MIXER)
printk(KERN_DEBUG "Slider volume: %d.\n", volume);
}
return old_slider_volume;
}
static unsigned int
netwinder_select_input(struct wavnc_info *devc, unsigned int recmask,
unsigned char *dev_l, unsigned char *dev_r)
{
unsigned int recdev_l = ADC_MUX_NONE, recdev_r = ADC_MUX_NONE;
if (recmask & SOUND_MASK_IMIX) {
recmask = SOUND_MASK_IMIX;
recdev_l = ADC_MUX_MIXER;
recdev_r = ADC_MUX_MIXER;
} else if (recmask & SOUND_MASK_LINE) {
recmask = SOUND_MASK_LINE;
recdev_l = ADC_MUX_LINE;
recdev_r = ADC_MUX_LINE;
} else if (recmask & SOUND_MASK_LINE1) {
recmask = SOUND_MASK_LINE1;
waveartist_cmd1(devc, WACMD_SET_MONO);
recdev_l = ADC_MUX_MIC;
recdev_r = ADC_MUX_NONE;
} else if (recmask & SOUND_MASK_PHONEIN) {
recmask = SOUND_MASK_PHONEIN;
waveartist_cmd1(devc, WACMD_SET_MONO);
recdev_l = ADC_MUX_AUX1;
recdev_r = ADC_MUX_NONE;
} else if (recmask & SOUND_MASK_MIC) {
recmask = SOUND_MASK_MIC;
waveartist_cmd1(devc, WACMD_SET_MONO | 0x100);
recdev_l = ADC_MUX_NONE;
recdev_r = ADC_MUX_MIC;
}
*dev_l = recdev_l;
*dev_r = recdev_r;
return recmask;
}
static int
netwinder_decode_mixer(struct wavnc_info *devc, int dev, unsigned char lev_l,
unsigned char lev_r)
{
switch (dev) {
case SOUND_MIXER_VOLUME:
case SOUND_MIXER_SYNTH:
case SOUND_MIXER_PCM:
case SOUND_MIXER_LINE:
case SOUND_MIXER_IGAIN:
devc->levels[dev] = lev_l | lev_r << 8;
break;
case SOUND_MIXER_MIC:
devc->levels[SOUND_MIXER_MIC] &= 0xff;
devc->levels[SOUND_MIXER_MIC] |= lev_l << 8;
break;
case SOUND_MIXER_LINE1:
devc->levels[SOUND_MIXER_MIC] &= 0xff00;
devc->levels[SOUND_MIXER_MIC] |= lev_l;
dev = SOUND_MIXER_MIC;
break;
case SOUND_MIXER_PHONEIN:
devc->levels[SOUND_MIXER_LINE1] = lev_l;
dev = SOUND_MIXER_LINE1;
break;
case SOUND_MIXER_IMIX:
case SOUND_MIXER_PHONEOUT:
break;
default:
dev = -EINVAL;
break;
}
return dev;
}
static int netwinder_get_mixer(struct wavnc_info *devc, int dev)
{
int levels;
switch (dev) {
case SOUND_MIXER_VOLUME:
case SOUND_MIXER_SYNTH:
case SOUND_MIXER_PCM:
case SOUND_MIXER_LINE:
case SOUND_MIXER_IGAIN:
levels = devc->levels[dev];
break;
case SOUND_MIXER_MIC:
levels = devc->levels[SOUND_MIXER_MIC] >> 8;
levels |= levels << 8;
break;
case SOUND_MIXER_LINE1:
levels = devc->levels[SOUND_MIXER_MIC] & 0xff;
levels |= levels << 8;
break;
case SOUND_MIXER_PHONEIN:
levels = devc->levels[SOUND_MIXER_LINE1] & 0xff;
levels |= levels << 8;
break;
default:
levels = 0;
}
return levels;
}
static void
vnc_configure_mixer(struct wavnc_info *devc, unsigned int recmask)
{
if (!devc->no_autoselect) {
if (devc->handset_detect) {
recmask = SOUND_MASK_LINE1;
devc->spkr_mute_state = devc->line_mute_state = 1;
} else if (devc->telephone_detect) {
recmask = SOUND_MASK_PHONEIN;
devc->spkr_mute_state = devc->line_mute_state = 1;
} else {
if ((devc->recmask & SOUND_MASK_LINE) == 0)
devc->recmask = SOUND_MASK_MIC;
devc->spkr_mute_state = devc->line_mute_state = 0;
}
vnc_mute_spkr(devc);
vnc_mute_lout(devc);
if (recmask != devc->recmask)
waveartist_set_recmask(devc, recmask);
}
}
static int
vnc_slider(struct wavnc_info *devc)
{
signed int slider_volume;
unsigned int temp, old_hs, old_td;
temp = inb(0x201);
old_hs = devc->handset_detect;
old_td = devc->telephone_detect;
devc->handset_detect = !(temp & 0x10);
devc->telephone_detect = !!(temp & 0x20);
if (!devc->no_autoselect &&
(old_hs != devc->handset_detect ||
old_td != devc->telephone_detect))
vnc_configure_mixer(devc, devc->recmask);
slider_volume = vnc_volume_slider(devc);
if (abs(devc->slider_vol - slider_volume) > 20)
devc->use_slider = 1;
temp = levels[SOUND_MIXER_VOLUME] & 0xFF;
if (slider_volume != temp && devc->use_slider) {
devc->slider_vol = slider_volume;
waveartist_set_mixer(devc, SOUND_MIXER_VOLUME,
slider_volume | slider_volume << 8);
return 1;
}
return 0;
}
static void
vnc_slider_tick(unsigned long data)
{
int next_timeout;
if (vnc_slider(adev_info + data))
next_timeout = 5;
else
next_timeout = VNC_TIMER_PERIOD;
mod_timer(&vnc_timer, jiffies + next_timeout);
}
static int
vnc_private_ioctl(int dev, unsigned int cmd, int __user * arg)
{
struct wavnc_info *devc = (struct wavnc_info *)audio_devs[dev]->devc;
int val;
switch (cmd) {
case SOUND_MIXER_PRIVATE1:
{
u_int prev_spkr_mute, prev_line_mute, prev_auto_state;
int val;
if (get_user(val, arg))
return -EFAULT;
if (val & ~(VNC_MUTE_INTERNAL_SPKR |
VNC_MUTE_LINE_OUT |
VNC_DISABLE_AUTOSWITCH))
return -EINVAL;
prev_auto_state = devc->no_autoselect;
prev_spkr_mute = devc->spkr_mute_state;
prev_line_mute = devc->line_mute_state;
devc->no_autoselect = (val & VNC_DISABLE_AUTOSWITCH) ? 1 : 0;
devc->spkr_mute_state = (val & VNC_MUTE_INTERNAL_SPKR) ? 1 : 0;
devc->line_mute_state = (val & VNC_MUTE_LINE_OUT) ? 1 : 0;
if (prev_spkr_mute != devc->spkr_mute_state)
vnc_mute_spkr(devc);
if (prev_line_mute != devc->line_mute_state)
vnc_mute_lout(devc);
if (prev_auto_state != devc->no_autoselect)
vnc_configure_mixer(devc, devc->recmask);
return 0;
}
case SOUND_MIXER_PRIVATE2:
if (get_user(val, arg))
return -EFAULT;
switch (val) {
#define VNC_SOUND_PAUSE 0x53
#define VNC_SOUND_RESUME 0x57
case VNC_SOUND_PAUSE:
waveartist_cmd1(devc, 0x16);
break;
case VNC_SOUND_RESUME:
waveartist_cmd1(devc, 0x18);
break;
default:
return -EINVAL;
}
return 0;
case SOUND_MIXER_PRIVATE3:
{
unsigned long flags;
int mixer_reg[15], i, val;
if (get_user(val, arg))
return -EFAULT;
if (copy_from_user(mixer_reg, (void *)val, sizeof(mixer_reg)))
return -EFAULT;
switch (mixer_reg[14]) {
case MIXER_PRIVATE3_RESET:
waveartist_mixer_reset(devc);
break;
case MIXER_PRIVATE3_WRITE:
waveartist_cmd3(devc, WACMD_SET_MIXER, mixer_reg[0], mixer_reg[4]);
waveartist_cmd3(devc, WACMD_SET_MIXER, mixer_reg[1], mixer_reg[5]);
waveartist_cmd3(devc, WACMD_SET_MIXER, mixer_reg[2], mixer_reg[6]);
waveartist_cmd3(devc, WACMD_SET_MIXER, mixer_reg[3], mixer_reg[7]);
waveartist_cmd3(devc, WACMD_SET_MIXER, mixer_reg[8], mixer_reg[9]);
waveartist_cmd3(devc, WACMD_SET_LEVEL, mixer_reg[10], mixer_reg[11]);
waveartist_cmd3(devc, WACMD_SET_LEVEL, mixer_reg[12], mixer_reg[13]);
break;
case MIXER_PRIVATE3_READ:
spin_lock_irqsave(&waveartist_lock, flags);
for (i = 0x30; i < 14 << 8; i += 1 << 8)
waveartist_cmd(devc, 1, &i, 1, mixer_reg + (i >> 8));
spin_unlock_irqrestore(&waveartist_lock, flags);
if (copy_to_user((void *)val, mixer_reg, sizeof(mixer_reg)))
return -EFAULT;
break;
default:
return -EINVAL;
}
return 0;
}
case SOUND_MIXER_PRIVATE4:
val = (devc->spkr_mute_state ? VNC_MUTE_INTERNAL_SPKR : 0) |
(devc->line_mute_state ? VNC_MUTE_LINE_OUT : 0) |
(devc->handset_detect ? VNC_HANDSET_DETECT : 0) |
(devc->telephone_detect ? VNC_PHONE_DETECT : 0) |
(devc->no_autoselect ? VNC_DISABLE_AUTOSWITCH : 0);
return put_user(val, arg) ? -EFAULT : 0;
}
if (_SIOC_DIR(cmd) & _SIOC_WRITE) {
if ((cmd & 0xff) == SOUND_MIXER_VOLUME)
devc->use_slider = 0;
if ((cmd & 0xff) == SOUND_MIXER_SPEAKER) {
unsigned int val, l, r;
if (get_user(val, arg))
return -EFAULT;
l = val & 0x7f;
r = (val & 0x7f00) >> 8;
val = (l + r) / 2;
devc->levels[SOUND_MIXER_SPEAKER] = val | (val << 8);
devc->spkr_mute_state = (val <= 50);
vnc_mute_spkr(devc);
return 0;
}
}
return -ENOIOCTLCMD;
}
static int __init init_waveartist(void)
{
const struct waveartist_mixer_info *mix;
if (!io && machine_is_netwinder()) {
io = 0x250;
irq = 12;
dma = 3;
dma2 = 7;
}
mix = &waveartist_mixer;
#ifdef CONFIG_ARCH_NETWINDER
if (machine_is_netwinder())
mix = &netwinder_mixer;
#endif
cfg.io_base = io;
cfg.irq = irq;
cfg.dma = dma;
cfg.dma2 = dma2;
if (!probe_waveartist(&cfg))
return -ENODEV;
attach_waveartist(&cfg, mix);
attached = 1;
return 0;
}
static void __exit cleanup_waveartist(void)
{
if (attached)
unload_waveartist(&cfg);
}
static int __init setup_waveartist(char *str)
{
int ints[5];
str = get_options(str, ARRAY_SIZE(ints), ints);
io = ints[1];
irq = ints[2];
dma = ints[3];
dma2 = ints[4];
return 1;
}
