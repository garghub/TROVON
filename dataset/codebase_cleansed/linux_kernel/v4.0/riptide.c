static u32 atoh(const unsigned char *in, unsigned int len)
{
u32 sum = 0;
unsigned int mult = 1;
unsigned char c;
while (len) {
int value;
c = in[len - 1];
value = hex_to_bin(c);
if (value >= 0)
sum += mult * value;
mult *= 16;
--len;
}
return sum;
}
static int senddata(struct cmdif *cif, const unsigned char *in, u32 offset)
{
u32 addr;
u32 data;
u32 i;
const unsigned char *p;
i = atoh(&in[1], 2);
addr = offset + atoh(&in[3], 4);
if (SEND_SMEM(cif, 0, addr) != 0)
return -EACCES;
p = in + 9;
while (i) {
data = atoh(p, 8);
if (SEND_WMEM(cif, 2,
((data & 0x0f0f0f0f) << 4) | ((data & 0xf0f0f0f0)
>> 4)))
return -EACCES;
i -= 4;
p += 8;
}
return 0;
}
static int loadfirmware(struct cmdif *cif, const unsigned char *img,
unsigned int size)
{
const unsigned char *in;
u32 laddr, saddr, t, val;
int err = 0;
laddr = saddr = 0;
while (size > 0 && err == 0) {
in = img;
if (in[0] == ':') {
t = atoh(&in[7], 2);
switch (t) {
case DATA_REC:
err = senddata(cif, in, laddr + saddr);
break;
case EXT_SEG_ADDR_REC:
saddr = atoh(&in[9], 4) << 4;
break;
case EXT_LIN_ADDR_REC:
laddr = atoh(&in[9], 4) << 16;
break;
case EXT_GOTO_CMD_REC:
val = atoh(&in[9], 8);
if (SEND_GOTO(cif, val) != 0)
err = -EACCES;
break;
case EXT_END_OF_FILE:
size = 0;
break;
default:
break;
}
while (size > 0) {
size--;
if (*img++ == '\n')
break;
}
}
}
snd_printdd("load firmware return %d\n", err);
return err;
}
static void
alloclbuspath(struct cmdif *cif, unsigned char source,
unsigned char *path, unsigned char *mixer, unsigned char *s)
{
while (*path != 0xff) {
unsigned char sink, type;
sink = *path & (~SPLIT_PATH);
if (sink != E2SINK_MAX) {
snd_printdd("alloc path 0x%x->0x%x\n", source, sink);
SEND_PSEL(cif, source, sink);
source = lbusin2out[sink][0];
type = lbusin2out[sink][1];
if (type == LS_MIXER_IN) {
if (mixer)
*mixer = sink - DIGITAL_MIXER_IN0;
}
if (type == LS_SRC_DECIMATORM ||
type == LS_SRC_DECIMATOR ||
type == LS_SRC_INTERPOLATORM ||
type == LS_SRC_INTERPOLATOR) {
if (s) {
if (s[0] != 0xff)
s[1] = sink;
else
s[0] = sink;
}
}
}
if (*path++ & SPLIT_PATH) {
unsigned char *npath = path;
while (*npath != 0xff)
npath++;
alloclbuspath(cif, source + 1, ++npath, mixer, s);
}
}
}
static void
freelbuspath(struct cmdif *cif, unsigned char source, unsigned char *path)
{
while (*path != 0xff) {
unsigned char sink;
sink = *path & (~SPLIT_PATH);
if (sink != E2SINK_MAX) {
snd_printdd("free path 0x%x->0x%x\n", source, sink);
SEND_PCLR(cif, source, sink);
source = lbusin2out[sink][0];
}
if (*path++ & SPLIT_PATH) {
unsigned char *npath = path;
while (*npath != 0xff)
npath++;
freelbuspath(cif, source + 1, ++npath);
}
}
}
static int writearm(struct cmdif *cif, u32 addr, u32 data, u32 mask)
{
union cmdret rptr = CMDRET_ZERO;
unsigned int i = MAX_WRITE_RETRY;
int flag = 1;
SEND_RMEM(cif, 0x02, addr, &rptr);
rptr.retlongs[0] &= (~mask);
while (--i) {
SEND_SMEM(cif, 0x01, addr);
SEND_WMEM(cif, 0x02, (rptr.retlongs[0] | data));
SEND_RMEM(cif, 0x02, addr, &rptr);
if ((rptr.retlongs[0] & data) == data) {
flag = 0;
break;
} else
rptr.retlongs[0] &= ~mask;
}
snd_printdd("send arm 0x%x 0x%x 0x%x return %d\n", addr, data, mask,
flag);
return flag;
}
static int sendcmd(struct cmdif *cif, u32 flags, u32 cmd, u32 parm,
union cmdret *ret)
{
int i, j;
int err;
unsigned int time = 0;
unsigned long irqflags;
struct riptideport *hwport;
struct cmdport *cmdport = NULL;
if (snd_BUG_ON(!cif))
return -EINVAL;
hwport = cif->hwport;
if (cif->errcnt > MAX_ERROR_COUNT) {
if (cif->is_reset) {
snd_printk(KERN_ERR
"Riptide: Too many failed cmds, reinitializing\n");
if (riptide_reset(cif, NULL) == 0) {
cif->errcnt = 0;
return -EIO;
}
}
snd_printk(KERN_ERR "Riptide: Initialization failed.\n");
return -EINVAL;
}
if (ret) {
ret->retlongs[0] = 0;
ret->retlongs[1] = 0;
}
i = 0;
spin_lock_irqsave(&cif->lock, irqflags);
while (i++ < CMDIF_TIMEOUT && !IS_READY(cif->hwport))
udelay(10);
if (i > CMDIF_TIMEOUT) {
err = -EBUSY;
goto errout;
}
err = 0;
for (j = 0, time = 0; time < CMDIF_TIMEOUT; j++, time += 2) {
cmdport = &(hwport->port[j % 2]);
if (IS_DATF(cmdport)) {
READ_PORT_ULONG(cmdport->data1);
READ_PORT_ULONG(cmdport->data2);
}
if (IS_CMDE(cmdport)) {
if (flags & PARM)
WRITE_PORT_ULONG(cmdport->data2, parm);
WRITE_PORT_ULONG(cmdport->data1, cmd);
if ((flags & RESP) && ret) {
while (!IS_DATF(cmdport) &&
time < CMDIF_TIMEOUT) {
udelay(10);
time++;
}
if (time < CMDIF_TIMEOUT) {
ret->retlongs[0] =
READ_PORT_ULONG(cmdport->data1);
ret->retlongs[1] =
READ_PORT_ULONG(cmdport->data2);
} else {
err = -ENOSYS;
goto errout;
}
}
break;
}
udelay(20);
}
if (time == CMDIF_TIMEOUT) {
err = -ENODATA;
goto errout;
}
spin_unlock_irqrestore(&cif->lock, irqflags);
cif->cmdcnt++;
cif->cmdtime += time;
if (time > cif->cmdtimemax)
cif->cmdtimemax = time;
if (time < cif->cmdtimemin)
cif->cmdtimemin = time;
if ((cif->cmdcnt) % 1000 == 0)
snd_printdd
("send cmd %d time: %d mintime: %d maxtime %d err: %d\n",
cif->cmdcnt, cif->cmdtime, cif->cmdtimemin,
cif->cmdtimemax, cif->errcnt);
return 0;
errout:
cif->errcnt++;
spin_unlock_irqrestore(&cif->lock, irqflags);
snd_printdd
("send cmd %d hw: 0x%x flag: 0x%x cmd: 0x%x parm: 0x%x ret: 0x%x 0x%x CMDE: %d DATF: %d failed %d\n",
cif->cmdcnt, (int)((void *)&(cmdport->stat) - (void *)hwport),
flags, cmd, parm, ret ? ret->retlongs[0] : 0,
ret ? ret->retlongs[1] : 0, IS_CMDE(cmdport), IS_DATF(cmdport),
err);
return err;
}
static int
setmixer(struct cmdif *cif, short num, unsigned short rval, unsigned short lval)
{
union cmdret rptr = CMDRET_ZERO;
int i = 0;
snd_printdd("sent mixer %d: 0x%x 0x%x\n", num, rval, lval);
do {
SEND_SDGV(cif, num, num, rval, lval);
SEND_RDGV(cif, num, num, &rptr);
if (rptr.retwords[0] == lval && rptr.retwords[1] == rval)
return 0;
} while (i++ < MAX_WRITE_RETRY);
snd_printdd("sent mixer failed\n");
return -EIO;
}
static int getpaths(struct cmdif *cif, unsigned char *o)
{
unsigned char src[E2SINK_MAX];
unsigned char sink[E2SINK_MAX];
int i, j = 0;
for (i = 0; i < E2SINK_MAX; i++) {
getsourcesink(cif, i, i, &src[i], &sink[i]);
if (sink[i] < E2SINK_MAX) {
o[j++] = sink[i];
o[j++] = i;
}
}
return j;
}
static int
getsourcesink(struct cmdif *cif, unsigned char source, unsigned char sink,
unsigned char *a, unsigned char *b)
{
union cmdret rptr = CMDRET_ZERO;
if (SEND_RSSV(cif, source, sink, &rptr) &&
SEND_RSSV(cif, source, sink, &rptr))
return -EIO;
*a = rptr.retbytes[0];
*b = rptr.retbytes[1];
snd_printdd("getsourcesink 0x%x 0x%x\n", *a, *b);
return 0;
}
static int
getsamplerate(struct cmdif *cif, unsigned char *intdec, unsigned int *rate)
{
unsigned char *s;
unsigned int p[2] = { 0, 0 };
int i;
union cmdret rptr = CMDRET_ZERO;
s = intdec;
for (i = 0; i < 2; i++) {
if (*s != 0xff) {
if (SEND_RSRC(cif, *s, &rptr) &&
SEND_RSRC(cif, *s, &rptr))
return -EIO;
p[i] += rptr.retwords[1];
p[i] *= rptr.retwords[2];
p[i] += rptr.retwords[3];
p[i] /= 65536;
}
s++;
}
if (p[0]) {
if (p[1] != p[0])
snd_printdd("rates differ %d %d\n", p[0], p[1]);
*rate = (unsigned int)p[0];
} else
*rate = (unsigned int)p[1];
snd_printdd("getsampleformat %d %d %d\n", intdec[0], intdec[1], *rate);
return 0;
}
static int
setsampleformat(struct cmdif *cif,
unsigned char mixer, unsigned char id,
unsigned char channels, unsigned char format)
{
unsigned char w, ch, sig, order;
snd_printdd
("setsampleformat mixer: %d id: %d channels: %d format: %d\n",
mixer, id, channels, format);
ch = channels == 1;
w = snd_pcm_format_width(format) == 8;
sig = snd_pcm_format_unsigned(format) != 0;
order = snd_pcm_format_big_endian(format) != 0;
if (SEND_SETF(cif, mixer, w, ch, order, sig, id) &&
SEND_SETF(cif, mixer, w, ch, order, sig, id)) {
snd_printdd("setsampleformat failed\n");
return -EIO;
}
return 0;
}
static int
setsamplerate(struct cmdif *cif, unsigned char *intdec, unsigned int rate)
{
u32 D, M, N;
union cmdret rptr = CMDRET_ZERO;
int i;
snd_printdd("setsamplerate intdec: %d,%d rate: %d\n", intdec[0],
intdec[1], rate);
D = 48000;
M = ((rate == 48000) ? 47999 : rate) * 65536;
N = M % D;
M /= D;
for (i = 0; i < 2; i++) {
if (*intdec != 0xff) {
do {
SEND_SSRC(cif, *intdec, D, M, N);
SEND_RSRC(cif, *intdec, &rptr);
} while (rptr.retwords[1] != D &&
rptr.retwords[2] != M &&
rptr.retwords[3] != N &&
i++ < MAX_WRITE_RETRY);
if (i > MAX_WRITE_RETRY) {
snd_printdd("sent samplerate %d: %d failed\n",
*intdec, rate);
return -EIO;
}
}
intdec++;
}
return 0;
}
static int
getmixer(struct cmdif *cif, short num, unsigned short *rval,
unsigned short *lval)
{
union cmdret rptr = CMDRET_ZERO;
if (SEND_RDGV(cif, num, num, &rptr) && SEND_RDGV(cif, num, num, &rptr))
return -EIO;
*rval = rptr.retwords[0];
*lval = rptr.retwords[1];
snd_printdd("got mixer %d: 0x%x 0x%x\n", num, *rval, *lval);
return 0;
}
static void riptide_handleirq(unsigned long dev_id)
{
struct snd_riptide *chip = (void *)dev_id;
struct cmdif *cif = chip->cif;
struct snd_pcm_substream *substream[PLAYBACK_SUBSTREAMS + 1];
struct snd_pcm_runtime *runtime;
struct pcmhw *data = NULL;
unsigned int pos, period_bytes;
struct sgd *c;
int i, j;
unsigned int flag;
if (!cif)
return;
for (i = 0; i < PLAYBACK_SUBSTREAMS; i++)
substream[i] = chip->playback_substream[i];
substream[i] = chip->capture_substream;
for (i = 0; i < PLAYBACK_SUBSTREAMS + 1; i++) {
if (substream[i] &&
(runtime = substream[i]->runtime) &&
(data = runtime->private_data) && data->state != ST_STOP) {
pos = 0;
for (j = 0; j < data->pages; j++) {
c = &data->sgdbuf[j];
flag = le32_to_cpu(c->dwStat_Ctl);
if (flag & EOB_STATUS)
pos += le32_to_cpu(c->dwSegLen);
if (flag & EOC_STATUS)
pos += le32_to_cpu(c->dwSegLen);
if ((flag & EOS_STATUS)
&& (data->state == ST_PLAY)) {
data->state = ST_STOP;
snd_printk(KERN_ERR
"Riptide: DMA stopped unexpectedly\n");
}
c->dwStat_Ctl =
cpu_to_le32(flag &
~(EOS_STATUS | EOB_STATUS |
EOC_STATUS));
}
data->pointer += pos;
pos += data->oldpos;
if (data->state != ST_STOP) {
period_bytes =
frames_to_bytes(runtime,
runtime->period_size);
snd_printdd
("interrupt 0x%x after 0x%lx of 0x%lx frames in period\n",
READ_AUDIO_STATUS(cif->hwport),
bytes_to_frames(runtime, pos),
runtime->period_size);
j = 0;
if (pos >= period_bytes) {
j++;
while (pos >= period_bytes)
pos -= period_bytes;
}
data->oldpos = pos;
if (j > 0)
snd_pcm_period_elapsed(substream[i]);
}
}
}
}
static int riptide_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_riptide *chip = card->private_data;
chip->in_suspend = 1;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
return 0;
}
static int riptide_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_riptide *chip = card->private_data;
snd_riptide_initialize(chip);
snd_ac97_resume(chip->ac97);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
chip->in_suspend = 0;
return 0;
}
static int try_to_load_firmware(struct cmdif *cif, struct snd_riptide *chip)
{
union firmware_version firmware = { .ret = CMDRET_ZERO };
int i, timeout, err;
for (i = 0; i < 2; i++) {
WRITE_PORT_ULONG(cif->hwport->port[i].data1, 0);
WRITE_PORT_ULONG(cif->hwport->port[i].data2, 0);
}
SET_GRESET(cif->hwport);
udelay(100);
UNSET_GRESET(cif->hwport);
udelay(100);
for (timeout = 100000; --timeout; udelay(10)) {
if (IS_READY(cif->hwport) && !IS_GERR(cif->hwport))
break;
}
if (!timeout) {
snd_printk(KERN_ERR
"Riptide: device not ready, audio status: 0x%x "
"ready: %d gerr: %d\n",
READ_AUDIO_STATUS(cif->hwport),
IS_READY(cif->hwport), IS_GERR(cif->hwport));
return -EIO;
} else {
snd_printdd
("Riptide: audio status: 0x%x ready: %d gerr: %d\n",
READ_AUDIO_STATUS(cif->hwport),
IS_READY(cif->hwport), IS_GERR(cif->hwport));
}
SEND_GETV(cif, &firmware.ret);
snd_printdd("Firmware version: ASIC: %d CODEC %d AUXDSP %d PROG %d\n",
firmware.firmware.ASIC, firmware.firmware.CODEC,
firmware.firmware.AUXDSP, firmware.firmware.PROG);
if (!chip)
return 1;
for (i = 0; i < FIRMWARE_VERSIONS; i++) {
if (!memcmp(&firmware_versions[i], &firmware, sizeof(firmware)))
return 1;
}
snd_printdd("Writing Firmware\n");
if (!chip->fw_entry) {
err = request_firmware(&chip->fw_entry, "riptide.hex",
&chip->pci->dev);
if (err) {
snd_printk(KERN_ERR
"Riptide: Firmware not available %d\n", err);
return -EIO;
}
}
err = loadfirmware(cif, chip->fw_entry->data, chip->fw_entry->size);
if (err) {
snd_printk(KERN_ERR
"Riptide: Could not load firmware %d\n", err);
return err;
}
chip->firmware = firmware;
return 1;
}
static int riptide_reset(struct cmdif *cif, struct snd_riptide *chip)
{
union cmdret rptr = CMDRET_ZERO;
int err, tries;
if (!cif)
return -EINVAL;
cif->cmdcnt = 0;
cif->cmdtime = 0;
cif->cmdtimemax = 0;
cif->cmdtimemin = 0xffffffff;
cif->errcnt = 0;
cif->is_reset = 0;
tries = RESET_TRIES;
do {
err = try_to_load_firmware(cif, chip);
if (err < 0)
return err;
} while (!err && --tries);
SEND_SACR(cif, 0, AC97_RESET);
SEND_RACR(cif, AC97_RESET, &rptr);
snd_printdd("AC97: 0x%x 0x%x\n", rptr.retlongs[0], rptr.retlongs[1]);
SEND_PLST(cif, 0);
SEND_SLST(cif, 0);
SEND_DLST(cif, 0);
SEND_ALST(cif, 0);
SEND_KDMA(cif);
writearm(cif, 0x301F8, 1, 1);
writearm(cif, 0x301F4, 1, 1);
SEND_LSEL(cif, MODEM_CMD, 0, 0, MODEM_INTDEC, MODEM_MERGER,
MODEM_SPLITTER, MODEM_MIXER);
setmixer(cif, MODEM_MIXER, 0x7fff, 0x7fff);
alloclbuspath(cif, ARM2LBUS_FIFO13, lbus_play_modem, NULL, NULL);
SEND_LSEL(cif, FM_CMD, 0, 0, FM_INTDEC, FM_MERGER, FM_SPLITTER,
FM_MIXER);
setmixer(cif, FM_MIXER, 0x7fff, 0x7fff);
writearm(cif, 0x30648 + FM_MIXER * 4, 0x01, 0x00000005);
writearm(cif, 0x301A8, 0x02, 0x00000002);
writearm(cif, 0x30264, 0x08, 0xffffffff);
alloclbuspath(cif, OPL3_SAMPLE, lbus_play_opl3, NULL, NULL);
SEND_SSRC(cif, I2S_INTDEC, 48000,
((u32) I2S_RATE * 65536) / 48000,
((u32) I2S_RATE * 65536) % 48000);
SEND_LSEL(cif, I2S_CMD0, 0, 0, I2S_INTDEC, I2S_MERGER, I2S_SPLITTER,
I2S_MIXER);
SEND_SI2S(cif, 1);
alloclbuspath(cif, ARM2LBUS_FIFO0, lbus_play_i2s, NULL, NULL);
alloclbuspath(cif, DIGITAL_MIXER_OUT0, lbus_play_out, NULL, NULL);
alloclbuspath(cif, DIGITAL_MIXER_OUT0, lbus_play_outhp, NULL, NULL);
SET_AIACK(cif->hwport);
SET_AIE(cif->hwport);
SET_AIACK(cif->hwport);
cif->is_reset = 1;
return 0;
}
static snd_pcm_uframes_t snd_riptide_pointer(struct snd_pcm_substream
*substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct pcmhw *data = get_pcmhwdev(substream);
struct cmdif *cif = chip->cif;
union cmdret rptr = CMDRET_ZERO;
snd_pcm_uframes_t ret;
SEND_GPOS(cif, 0, data->id, &rptr);
if (data->size && runtime->period_size) {
snd_printdd
("pointer stream %d position 0x%x(0x%x in buffer) bytes 0x%lx(0x%lx in period) frames\n",
data->id, rptr.retlongs[1], rptr.retlongs[1] % data->size,
bytes_to_frames(runtime, rptr.retlongs[1]),
bytes_to_frames(runtime,
rptr.retlongs[1]) % runtime->period_size);
if (rptr.retlongs[1] > data->pointer)
ret =
bytes_to_frames(runtime,
rptr.retlongs[1] % data->size);
else
ret =
bytes_to_frames(runtime,
data->pointer % data->size);
} else {
snd_printdd("stream not started or strange parms (%d %ld)\n",
data->size, runtime->period_size);
ret = bytes_to_frames(runtime, 0);
}
return ret;
}
static int snd_riptide_trigger(struct snd_pcm_substream *substream, int cmd)
{
int i, j;
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct pcmhw *data = get_pcmhwdev(substream);
struct cmdif *cif = chip->cif;
union cmdret rptr = CMDRET_ZERO;
spin_lock(&chip->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
if (!(data->state & ST_PLAY)) {
SEND_SSTR(cif, data->id, data->sgdlist.addr);
SET_AIE(cif->hwport);
data->state = ST_PLAY;
if (data->mixer != 0xff)
setmixer(cif, data->mixer, 0x7fff, 0x7fff);
chip->openstreams++;
data->oldpos = 0;
data->pointer = 0;
}
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (data->mixer != 0xff)
setmixer(cif, data->mixer, 0, 0);
setmixer(cif, data->mixer, 0, 0);
SEND_KSTR(cif, data->id);
data->state = ST_STOP;
chip->openstreams--;
j = 0;
do {
i = rptr.retlongs[1];
SEND_GPOS(cif, 0, data->id, &rptr);
udelay(1);
} while (i != rptr.retlongs[1] && j++ < MAX_WRITE_RETRY);
if (j > MAX_WRITE_RETRY)
snd_printk(KERN_ERR "Riptide: Could not stop stream!");
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (!(data->state & ST_PAUSE)) {
SEND_PSTR(cif, data->id);
data->state |= ST_PAUSE;
chip->openstreams--;
}
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (data->state & ST_PAUSE) {
SEND_SSTR(cif, data->id, data->sgdlist.addr);
data->state &= ~ST_PAUSE;
chip->openstreams++;
}
break;
default:
spin_unlock(&chip->lock);
return -EINVAL;
}
spin_unlock(&chip->lock);
return 0;
}
static int snd_riptide_prepare(struct snd_pcm_substream *substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct pcmhw *data = get_pcmhwdev(substream);
struct cmdif *cif = chip->cif;
unsigned char *lbuspath = NULL;
unsigned int rate, channels;
int err = 0;
snd_pcm_format_t format;
if (snd_BUG_ON(!cif || !data))
return -EINVAL;
snd_printdd("prepare id %d ch: %d f:0x%x r:%d\n", data->id,
runtime->channels, runtime->format, runtime->rate);
spin_lock_irq(&chip->lock);
channels = runtime->channels;
format = runtime->format;
rate = runtime->rate;
switch (channels) {
case 1:
if (rate == 48000 && format == SNDRV_PCM_FORMAT_S16_LE)
lbuspath = data->paths.noconv;
else
lbuspath = data->paths.mono;
break;
case 2:
if (rate == 48000 && format == SNDRV_PCM_FORMAT_S16_LE)
lbuspath = data->paths.noconv;
else
lbuspath = data->paths.stereo;
break;
}
snd_printdd("use sgdlist at 0x%p\n",
data->sgdlist.area);
if (data->sgdlist.area) {
unsigned int i, j, size, pages, f, pt, period;
struct sgd *c, *p = NULL;
size = frames_to_bytes(runtime, runtime->buffer_size);
period = frames_to_bytes(runtime, runtime->period_size);
f = PAGE_SIZE;
while ((size + (f >> 1) - 1) <= (f << 7) && (f << 1) > period)
f = f >> 1;
pages = (size + f - 1) / f;
data->size = size;
data->pages = pages;
snd_printdd
("create sgd size: 0x%x pages %d of size 0x%x for period 0x%x\n",
size, pages, f, period);
pt = 0;
j = 0;
for (i = 0; i < pages; i++) {
unsigned int ofs, addr;
c = &data->sgdbuf[i];
if (p)
p->dwNextLink = cpu_to_le32(data->sgdlist.addr +
(i *
sizeof(struct
sgd)));
c->dwNextLink = cpu_to_le32(data->sgdlist.addr);
ofs = j << PAGE_SHIFT;
addr = snd_pcm_sgbuf_get_addr(substream, ofs) + pt;
c->dwSegPtrPhys = cpu_to_le32(addr);
pt = (pt + f) % PAGE_SIZE;
if (pt == 0)
j++;
c->dwSegLen = cpu_to_le32(f);
c->dwStat_Ctl =
cpu_to_le32(IEOB_ENABLE | IEOS_ENABLE |
IEOC_ENABLE);
p = c;
size -= f;
}
data->sgdbuf[i].dwSegLen = cpu_to_le32(size);
}
if (lbuspath && lbuspath != data->lbuspath) {
if (data->lbuspath)
freelbuspath(cif, data->source, data->lbuspath);
alloclbuspath(cif, data->source, lbuspath,
&data->mixer, data->intdec);
data->lbuspath = lbuspath;
data->rate = 0;
}
if (data->rate != rate || data->format != format ||
data->channels != channels) {
data->rate = rate;
data->format = format;
data->channels = channels;
if (setsampleformat
(cif, data->mixer, data->id, channels, format)
|| setsamplerate(cif, data->intdec, rate))
err = -EIO;
}
spin_unlock_irq(&chip->lock);
return err;
}
static int
snd_riptide_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct pcmhw *data = get_pcmhwdev(substream);
struct snd_dma_buffer *sgdlist = &data->sgdlist;
int err;
snd_printdd("hw params id %d (sgdlist: 0x%p 0x%lx %d)\n", data->id,
sgdlist->area, (unsigned long)sgdlist->addr,
(int)sgdlist->bytes);
if (sgdlist->area)
snd_dma_free_pages(sgdlist);
if ((err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
sizeof(struct sgd) * (DESC_MAX_MASK + 1),
sgdlist)) < 0) {
snd_printk(KERN_ERR "Riptide: failed to alloc %d dma bytes\n",
(int)sizeof(struct sgd) * (DESC_MAX_MASK + 1));
return err;
}
data->sgdbuf = (struct sgd *)sgdlist->area;
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_riptide_hw_free(struct snd_pcm_substream *substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct pcmhw *data = get_pcmhwdev(substream);
struct cmdif *cif = chip->cif;
if (cif && data) {
if (data->lbuspath)
freelbuspath(cif, data->source, data->lbuspath);
data->lbuspath = NULL;
data->source = 0xff;
data->intdec[0] = 0xff;
data->intdec[1] = 0xff;
if (data->sgdlist.area) {
snd_dma_free_pages(&data->sgdlist);
data->sgdlist.area = NULL;
}
}
return snd_pcm_lib_free_pages(substream);
}
static int snd_riptide_playback_open(struct snd_pcm_substream *substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct pcmhw *data;
int sub_num = substream->number;
chip->playback_substream[sub_num] = substream;
runtime->hw = snd_riptide_playback;
data = kzalloc(sizeof(struct pcmhw), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
data->paths = lbus_play_paths[sub_num];
data->id = play_ids[sub_num];
data->source = play_sources[sub_num];
data->intdec[0] = 0xff;
data->intdec[1] = 0xff;
data->state = ST_STOP;
runtime->private_data = data;
return snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
}
static int snd_riptide_capture_open(struct snd_pcm_substream *substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct pcmhw *data;
chip->capture_substream = substream;
runtime->hw = snd_riptide_capture;
data = kzalloc(sizeof(struct pcmhw), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
data->paths = lbus_rec_path;
data->id = PADC;
data->source = ACLNK2PADC;
data->intdec[0] = 0xff;
data->intdec[1] = 0xff;
data->state = ST_STOP;
runtime->private_data = data;
return snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
}
static int snd_riptide_playback_close(struct snd_pcm_substream *substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct pcmhw *data = get_pcmhwdev(substream);
int sub_num = substream->number;
substream->runtime->private_data = NULL;
chip->playback_substream[sub_num] = NULL;
kfree(data);
return 0;
}
static int snd_riptide_capture_close(struct snd_pcm_substream *substream)
{
struct snd_riptide *chip = snd_pcm_substream_chip(substream);
struct pcmhw *data = get_pcmhwdev(substream);
substream->runtime->private_data = NULL;
chip->capture_substream = NULL;
kfree(data);
return 0;
}
static int snd_riptide_pcm(struct snd_riptide *chip, int device)
{
struct snd_pcm *pcm;
int err;
if ((err =
snd_pcm_new(chip->card, "RIPTIDE", device, PLAYBACK_SUBSTREAMS, 1,
&pcm)) < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_riptide_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_riptide_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, "RIPTIDE");
chip->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64 * 1024, 128 * 1024);
return 0;
}
static irqreturn_t
snd_riptide_interrupt(int irq, void *dev_id)
{
struct snd_riptide *chip = dev_id;
struct cmdif *cif = chip->cif;
if (cif) {
chip->received_irqs++;
if (IS_EOBIRQ(cif->hwport) || IS_EOSIRQ(cif->hwport) ||
IS_EOCIRQ(cif->hwport)) {
chip->handled_irqs++;
tasklet_schedule(&chip->riptide_tq);
}
if (chip->rmidi && IS_MPUIRQ(cif->hwport)) {
chip->handled_irqs++;
snd_mpu401_uart_interrupt(irq,
chip->rmidi->private_data);
}
SET_AIACK(cif->hwport);
}
return IRQ_HANDLED;
}
static void
snd_riptide_codec_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct snd_riptide *chip = ac97->private_data;
struct cmdif *cif = chip->cif;
union cmdret rptr = CMDRET_ZERO;
int i = 0;
if (snd_BUG_ON(!cif))
return;
snd_printdd("Write AC97 reg 0x%x 0x%x\n", reg, val);
do {
SEND_SACR(cif, val, reg);
SEND_RACR(cif, reg, &rptr);
} while (rptr.retwords[1] != val && i++ < MAX_WRITE_RETRY);
if (i > MAX_WRITE_RETRY)
snd_printdd("Write AC97 reg failed\n");
}
static unsigned short snd_riptide_codec_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct snd_riptide *chip = ac97->private_data;
struct cmdif *cif = chip->cif;
union cmdret rptr = CMDRET_ZERO;
if (snd_BUG_ON(!cif))
return 0;
if (SEND_RACR(cif, reg, &rptr) != 0)
SEND_RACR(cif, reg, &rptr);
snd_printdd("Read AC97 reg 0x%x got 0x%x\n", reg, rptr.retwords[1]);
return rptr.retwords[1];
}
static int snd_riptide_initialize(struct snd_riptide *chip)
{
struct cmdif *cif;
unsigned int device_id;
int err;
if (snd_BUG_ON(!chip))
return -EINVAL;
cif = chip->cif;
if (!cif) {
if ((cif = kzalloc(sizeof(struct cmdif), GFP_KERNEL)) == NULL)
return -ENOMEM;
cif->hwport = (struct riptideport *)chip->port;
spin_lock_init(&cif->lock);
chip->cif = cif;
}
cif->is_reset = 0;
if ((err = riptide_reset(cif, chip)) != 0)
return err;
device_id = chip->device_id;
switch (device_id) {
case 0x4310:
case 0x4320:
case 0x4330:
snd_printdd("Modem enable?\n");
SEND_SETDPLL(cif);
break;
}
snd_printdd("Enabling MPU IRQs\n");
if (chip->rmidi)
SET_EMPUIRQ(cif->hwport);
return err;
}
static int snd_riptide_free(struct snd_riptide *chip)
{
struct cmdif *cif;
if (!chip)
return 0;
if ((cif = chip->cif)) {
SET_GRESET(cif->hwport);
udelay(100);
UNSET_GRESET(cif->hwport);
kfree(chip->cif);
}
if (chip->irq >= 0)
free_irq(chip->irq, chip);
release_firmware(chip->fw_entry);
release_and_free_resource(chip->res_port);
kfree(chip);
return 0;
}
static int snd_riptide_dev_free(struct snd_device *device)
{
struct snd_riptide *chip = device->device_data;
return snd_riptide_free(chip);
}
static int
snd_riptide_create(struct snd_card *card, struct pci_dev *pci,
struct snd_riptide **rchip)
{
struct snd_riptide *chip;
struct riptideport *hwport;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_riptide_dev_free,
};
*rchip = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
if (!(chip = kzalloc(sizeof(struct snd_riptide), GFP_KERNEL)))
return -ENOMEM;
spin_lock_init(&chip->lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
chip->openstreams = 0;
chip->port = pci_resource_start(pci, 0);
chip->received_irqs = 0;
chip->handled_irqs = 0;
chip->cif = NULL;
tasklet_init(&chip->riptide_tq, riptide_handleirq, (unsigned long)chip);
if ((chip->res_port =
request_region(chip->port, 64, "RIPTIDE")) == NULL) {
snd_printk(KERN_ERR
"Riptide: unable to grab region 0x%lx-0x%lx\n",
chip->port, chip->port + 64 - 1);
snd_riptide_free(chip);
return -EBUSY;
}
hwport = (struct riptideport *)chip->port;
UNSET_AIE(hwport);
if (request_irq(pci->irq, snd_riptide_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "Riptide: unable to grab IRQ %d\n",
pci->irq);
snd_riptide_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
chip->device_id = pci->device;
pci_set_master(pci);
if ((err = snd_riptide_initialize(chip)) < 0) {
snd_riptide_free(chip);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_riptide_free(chip);
return err;
}
*rchip = chip;
return 0;
}
static void
snd_riptide_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_riptide *chip = entry->private_data;
struct pcmhw *data;
int i;
struct cmdif *cif = NULL;
unsigned char p[256];
unsigned short rval = 0, lval = 0;
unsigned int rate;
if (!chip)
return;
snd_iprintf(buffer, "%s\n\n", chip->card->longname);
snd_iprintf(buffer, "Device ID: 0x%x\nReceived IRQs: (%ld)%ld\nPorts:",
chip->device_id, chip->handled_irqs, chip->received_irqs);
for (i = 0; i < 64; i += 4)
snd_iprintf(buffer, "%c%02x: %08x",
(i % 16) ? ' ' : '\n', i, inl(chip->port + i));
if ((cif = chip->cif)) {
snd_iprintf(buffer,
"\nVersion: ASIC: %d CODEC: %d AUXDSP: %d PROG: %d",
chip->firmware.firmware.ASIC,
chip->firmware.firmware.CODEC,
chip->firmware.firmware.AUXDSP,
chip->firmware.firmware.PROG);
snd_iprintf(buffer, "\nDigital mixer:");
for (i = 0; i < 12; i++) {
getmixer(cif, i, &rval, &lval);
snd_iprintf(buffer, "\n %d: %d %d", i, rval, lval);
}
snd_iprintf(buffer,
"\nARM Commands num: %d failed: %d time: %d max: %d min: %d",
cif->cmdcnt, cif->errcnt,
cif->cmdtime, cif->cmdtimemax, cif->cmdtimemin);
}
snd_iprintf(buffer, "\nOpen streams %d:\n", chip->openstreams);
for (i = 0; i < PLAYBACK_SUBSTREAMS; i++) {
if (chip->playback_substream[i]
&& chip->playback_substream[i]->runtime
&& (data =
chip->playback_substream[i]->runtime->private_data)) {
snd_iprintf(buffer,
"stream: %d mixer: %d source: %d (%d,%d)\n",
data->id, data->mixer, data->source,
data->intdec[0], data->intdec[1]);
if (!(getsamplerate(cif, data->intdec, &rate)))
snd_iprintf(buffer, "rate: %d\n", rate);
}
}
if (chip->capture_substream
&& chip->capture_substream->runtime
&& (data = chip->capture_substream->runtime->private_data)) {
snd_iprintf(buffer,
"stream: %d mixer: %d source: %d (%d,%d)\n",
data->id, data->mixer,
data->source, data->intdec[0], data->intdec[1]);
if (!(getsamplerate(cif, data->intdec, &rate)))
snd_iprintf(buffer, "rate: %d\n", rate);
}
snd_iprintf(buffer, "Paths:\n");
i = getpaths(cif, p);
while (i >= 2) {
i -= 2;
snd_iprintf(buffer, "%x->%x ", p[i], p[i + 1]);
}
snd_iprintf(buffer, "\n");
}
static void snd_riptide_proc_init(struct snd_riptide *chip)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(chip->card, "riptide", &entry))
snd_info_set_text_ops(entry, chip, snd_riptide_proc_read);
}
static int snd_riptide_mixer(struct snd_riptide *chip)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
int err = 0;
static struct snd_ac97_bus_ops ops = {
.write = snd_riptide_codec_write,
.read = snd_riptide_codec_read,
};
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.scaps = AC97_SCAP_SKIP_MODEM;
if ((err = snd_ac97_bus(chip->card, 0, &ops, chip, &pbus)) < 0)
return err;
chip->ac97_bus = pbus;
ac97.pci = chip->pci;
if ((err = snd_ac97_mixer(pbus, &ac97, &chip->ac97)) < 0)
return err;
return err;
}
static int
snd_riptide_joystick_probe(struct pci_dev *pci, const struct pci_device_id *id)
{
static int dev;
struct gameport *gameport;
int ret;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
ret = -ENOENT;
goto inc_dev;
}
if (!joystick_port[dev]) {
ret = 0;
goto inc_dev;
}
gameport = gameport_allocate_port();
if (!gameport) {
ret = -ENOMEM;
goto inc_dev;
}
if (!request_region(joystick_port[dev], 8, "Riptide gameport")) {
snd_printk(KERN_WARNING
"Riptide: cannot grab gameport 0x%x\n",
joystick_port[dev]);
gameport_free_port(gameport);
ret = -EBUSY;
goto inc_dev;
}
gameport->io = joystick_port[dev];
gameport_register_port(gameport);
pci_set_drvdata(pci, gameport);
ret = 0;
inc_dev:
dev++;
return ret;
}
static void snd_riptide_joystick_remove(struct pci_dev *pci)
{
struct gameport *gameport = pci_get_drvdata(pci);
if (gameport) {
release_region(gameport->io, 8);
gameport_unregister_port(gameport);
}
}
static int
snd_card_riptide_probe(struct pci_dev *pci, const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_riptide *chip;
unsigned short val;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
err = snd_riptide_create(card, pci, &chip);
if (err < 0)
goto error;
card->private_data = chip;
err = snd_riptide_pcm(chip, 0);
if (err < 0)
goto error;
err = snd_riptide_mixer(chip);
if (err < 0)
goto error;
val = LEGACY_ENABLE_ALL;
if (opl3_port[dev])
val |= LEGACY_ENABLE_FM;
#ifdef SUPPORT_JOYSTICK
if (joystick_port[dev])
val |= LEGACY_ENABLE_GAMEPORT;
#endif
if (mpu_port[dev])
val |= LEGACY_ENABLE_MPU_INT | LEGACY_ENABLE_MPU;
val |= (chip->irq << 4) & 0xf0;
pci_write_config_word(chip->pci, PCI_EXT_Legacy_Mask, val);
if (mpu_port[dev]) {
val = mpu_port[dev];
pci_write_config_word(chip->pci, PCI_EXT_MPU_Base, val);
err = snd_mpu401_uart_new(card, 0, MPU401_HW_RIPTIDE,
val, MPU401_INFO_IRQ_HOOK, -1,
&chip->rmidi);
if (err < 0)
snd_printk(KERN_WARNING
"Riptide: Can't Allocate MPU at 0x%x\n",
val);
else
chip->mpuaddr = val;
}
if (opl3_port[dev]) {
val = opl3_port[dev];
pci_write_config_word(chip->pci, PCI_EXT_FM_Base, val);
err = snd_opl3_create(card, val, val + 2,
OPL3_HW_RIPTIDE, 0, &chip->opl3);
if (err < 0)
snd_printk(KERN_WARNING
"Riptide: Can't Allocate OPL3 at 0x%x\n",
val);
else {
chip->opladdr = val;
err = snd_opl3_hwdep_new(chip->opl3, 0, 1, NULL);
if (err < 0)
snd_printk(KERN_WARNING
"Riptide: Can't Allocate OPL3-HWDEP\n");
}
}
#ifdef SUPPORT_JOYSTICK
if (joystick_port[dev]) {
val = joystick_port[dev];
pci_write_config_word(chip->pci, PCI_EXT_Game_Base, val);
chip->gameaddr = val;
}
#endif
strcpy(card->driver, "RIPTIDE");
strcpy(card->shortname, "Riptide");
#ifdef SUPPORT_JOYSTICK
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx, irq %i mpu 0x%x opl3 0x%x gameport 0x%x",
card->shortname, chip->port, chip->irq, chip->mpuaddr,
chip->opladdr, chip->gameaddr);
#else
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx, irq %i mpu 0x%x opl3 0x%x",
card->shortname, chip->port, chip->irq, chip->mpuaddr,
chip->opladdr);
#endif
snd_riptide_proc_init(chip);
err = snd_card_register(card);
if (err < 0)
goto error;
pci_set_drvdata(pci, card);
dev++;
return 0;
error:
snd_card_free(card);
return err;
}
static void snd_card_riptide_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static int __init alsa_card_riptide_init(void)
{
int err;
err = pci_register_driver(&driver);
if (err < 0)
return err;
#if defined(SUPPORT_JOYSTICK)
err = pci_register_driver(&joystick_driver);
if (err < 0)
pci_unregister_driver(&driver);
#endif
return err;
}
static void __exit alsa_card_riptide_exit(void)
{
pci_unregister_driver(&driver);
#if defined(SUPPORT_JOYSTICK)
pci_unregister_driver(&joystick_driver);
#endif
}
