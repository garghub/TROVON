int snd_midi_event_new(int bufsize, struct snd_midi_event **rdev)
{
struct snd_midi_event *dev;
*rdev = NULL;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL)
return -ENOMEM;
if (bufsize > 0) {
dev->buf = kmalloc(bufsize, GFP_KERNEL);
if (dev->buf == NULL) {
kfree(dev);
return -ENOMEM;
}
}
dev->bufsize = bufsize;
dev->lastcmd = 0xff;
dev->type = ST_INVALID;
spin_lock_init(&dev->lock);
*rdev = dev;
return 0;
}
void snd_midi_event_free(struct snd_midi_event *dev)
{
if (dev != NULL) {
kfree(dev->buf);
kfree(dev);
}
}
static inline void reset_encode(struct snd_midi_event *dev)
{
dev->read = 0;
dev->qlen = 0;
dev->type = ST_INVALID;
}
void snd_midi_event_reset_encode(struct snd_midi_event *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
reset_encode(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
void snd_midi_event_reset_decode(struct snd_midi_event *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
dev->lastcmd = 0xff;
spin_unlock_irqrestore(&dev->lock, flags);
}
void snd_midi_event_no_status(struct snd_midi_event *dev, int on)
{
dev->nostat = on ? 1 : 0;
}
long snd_midi_event_encode(struct snd_midi_event *dev, unsigned char *buf, long count,
struct snd_seq_event *ev)
{
long result = 0;
int rc;
ev->type = SNDRV_SEQ_EVENT_NONE;
while (count-- > 0) {
rc = snd_midi_event_encode_byte(dev, *buf++, ev);
result++;
if (rc < 0)
return rc;
else if (rc > 0)
return result;
}
return result;
}
int snd_midi_event_encode_byte(struct snd_midi_event *dev, int c,
struct snd_seq_event *ev)
{
int rc = 0;
unsigned long flags;
c &= 0xff;
if (c >= MIDI_CMD_COMMON_CLOCK) {
ev->type = status_event[ST_SPECIAL + c - 0xf0].event;
ev->flags &= ~SNDRV_SEQ_EVENT_LENGTH_MASK;
ev->flags |= SNDRV_SEQ_EVENT_LENGTH_FIXED;
return ev->type != SNDRV_SEQ_EVENT_NONE;
}
spin_lock_irqsave(&dev->lock, flags);
if ((c & 0x80) &&
(c != MIDI_CMD_COMMON_SYSEX_END || dev->type != ST_SYSEX)) {
dev->buf[0] = c;
if ((c & 0xf0) == 0xf0)
dev->type = (c & 0x0f) + ST_SPECIAL;
else
dev->type = (c >> 4) & 0x07;
dev->read = 1;
dev->qlen = status_event[dev->type].qlen;
} else {
if (dev->qlen > 0) {
dev->buf[dev->read++] = c;
if (dev->type != ST_SYSEX)
dev->qlen--;
} else {
dev->buf[1] = c;
dev->qlen = status_event[dev->type].qlen - 1;
dev->read = 2;
}
}
if (dev->qlen == 0) {
ev->type = status_event[dev->type].event;
ev->flags &= ~SNDRV_SEQ_EVENT_LENGTH_MASK;
ev->flags |= SNDRV_SEQ_EVENT_LENGTH_FIXED;
if (status_event[dev->type].encode)
status_event[dev->type].encode(dev, ev);
if (dev->type >= ST_SPECIAL)
dev->type = ST_INVALID;
rc = 1;
} else if (dev->type == ST_SYSEX) {
if (c == MIDI_CMD_COMMON_SYSEX_END ||
dev->read >= dev->bufsize) {
ev->flags &= ~SNDRV_SEQ_EVENT_LENGTH_MASK;
ev->flags |= SNDRV_SEQ_EVENT_LENGTH_VARIABLE;
ev->type = SNDRV_SEQ_EVENT_SYSEX;
ev->data.ext.len = dev->read;
ev->data.ext.ptr = dev->buf;
if (c != MIDI_CMD_COMMON_SYSEX_END)
dev->read = 0;
else
reset_encode(dev);
rc = 1;
}
}
spin_unlock_irqrestore(&dev->lock, flags);
return rc;
}
static void note_event(struct snd_midi_event *dev, struct snd_seq_event *ev)
{
ev->data.note.channel = dev->buf[0] & 0x0f;
ev->data.note.note = dev->buf[1];
ev->data.note.velocity = dev->buf[2];
}
static void one_param_ctrl_event(struct snd_midi_event *dev, struct snd_seq_event *ev)
{
ev->data.control.channel = dev->buf[0] & 0x0f;
ev->data.control.value = dev->buf[1];
}
static void pitchbend_ctrl_event(struct snd_midi_event *dev, struct snd_seq_event *ev)
{
ev->data.control.channel = dev->buf[0] & 0x0f;
ev->data.control.value = (int)dev->buf[2] * 128 + (int)dev->buf[1] - 8192;
}
static void two_param_ctrl_event(struct snd_midi_event *dev, struct snd_seq_event *ev)
{
ev->data.control.channel = dev->buf[0] & 0x0f;
ev->data.control.param = dev->buf[1];
ev->data.control.value = dev->buf[2];
}
static void one_param_event(struct snd_midi_event *dev, struct snd_seq_event *ev)
{
ev->data.control.value = dev->buf[1];
}
static void songpos_event(struct snd_midi_event *dev, struct snd_seq_event *ev)
{
ev->data.control.value = (int)dev->buf[2] * 128 + (int)dev->buf[1];
}
long snd_midi_event_decode(struct snd_midi_event *dev, unsigned char *buf, long count,
struct snd_seq_event *ev)
{
unsigned int cmd, type;
if (ev->type == SNDRV_SEQ_EVENT_NONE)
return -ENOENT;
for (type = 0; type < ARRAY_SIZE(status_event); type++) {
if (ev->type == status_event[type].event)
goto __found;
}
for (type = 0; type < ARRAY_SIZE(extra_event); type++) {
if (ev->type == extra_event[type].event)
return extra_event[type].decode(dev, buf, count, ev);
}
return -ENOENT;
__found:
if (type >= ST_SPECIAL)
cmd = 0xf0 + (type - ST_SPECIAL);
else
cmd = 0x80 | (type << 4) | (ev->data.note.channel & 0x0f);
if (cmd == MIDI_CMD_COMMON_SYSEX) {
snd_midi_event_reset_decode(dev);
return snd_seq_expand_var_event(ev, count, buf, 1, 0);
} else {
int qlen;
unsigned char xbuf[4];
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
if ((cmd & 0xf0) == 0xf0 || dev->lastcmd != cmd || dev->nostat) {
dev->lastcmd = cmd;
spin_unlock_irqrestore(&dev->lock, flags);
xbuf[0] = cmd;
if (status_event[type].decode)
status_event[type].decode(ev, xbuf + 1);
qlen = status_event[type].qlen + 1;
} else {
spin_unlock_irqrestore(&dev->lock, flags);
if (status_event[type].decode)
status_event[type].decode(ev, xbuf + 0);
qlen = status_event[type].qlen;
}
if (count < qlen)
return -ENOMEM;
memcpy(buf, xbuf, qlen);
return qlen;
}
}
static void note_decode(struct snd_seq_event *ev, unsigned char *buf)
{
buf[0] = ev->data.note.note & 0x7f;
buf[1] = ev->data.note.velocity & 0x7f;
}
static void one_param_decode(struct snd_seq_event *ev, unsigned char *buf)
{
buf[0] = ev->data.control.value & 0x7f;
}
static void pitchbend_decode(struct snd_seq_event *ev, unsigned char *buf)
{
int value = ev->data.control.value + 8192;
buf[0] = value & 0x7f;
buf[1] = (value >> 7) & 0x7f;
}
static void two_param_decode(struct snd_seq_event *ev, unsigned char *buf)
{
buf[0] = ev->data.control.param & 0x7f;
buf[1] = ev->data.control.value & 0x7f;
}
static void songpos_decode(struct snd_seq_event *ev, unsigned char *buf)
{
buf[0] = ev->data.control.value & 0x7f;
buf[1] = (ev->data.control.value >> 7) & 0x7f;
}
static int extra_decode_ctrl14(struct snd_midi_event *dev, unsigned char *buf,
int count, struct snd_seq_event *ev)
{
unsigned char cmd;
int idx = 0;
cmd = MIDI_CMD_CONTROL|(ev->data.control.channel & 0x0f);
if (ev->data.control.param < 0x20) {
if (count < 4)
return -ENOMEM;
if (dev->nostat && count < 6)
return -ENOMEM;
if (cmd != dev->lastcmd || dev->nostat) {
if (count < 5)
return -ENOMEM;
buf[idx++] = dev->lastcmd = cmd;
}
buf[idx++] = ev->data.control.param;
buf[idx++] = (ev->data.control.value >> 7) & 0x7f;
if (dev->nostat)
buf[idx++] = cmd;
buf[idx++] = ev->data.control.param + 0x20;
buf[idx++] = ev->data.control.value & 0x7f;
} else {
if (count < 2)
return -ENOMEM;
if (cmd != dev->lastcmd || dev->nostat) {
if (count < 3)
return -ENOMEM;
buf[idx++] = dev->lastcmd = cmd;
}
buf[idx++] = ev->data.control.param & 0x7f;
buf[idx++] = ev->data.control.value & 0x7f;
}
return idx;
}
static int extra_decode_xrpn(struct snd_midi_event *dev, unsigned char *buf,
int count, struct snd_seq_event *ev)
{
unsigned char cmd;
char *cbytes;
static char cbytes_nrpn[4] = { MIDI_CTL_NONREG_PARM_NUM_MSB,
MIDI_CTL_NONREG_PARM_NUM_LSB,
MIDI_CTL_MSB_DATA_ENTRY,
MIDI_CTL_LSB_DATA_ENTRY };
static char cbytes_rpn[4] = { MIDI_CTL_REGIST_PARM_NUM_MSB,
MIDI_CTL_REGIST_PARM_NUM_LSB,
MIDI_CTL_MSB_DATA_ENTRY,
MIDI_CTL_LSB_DATA_ENTRY };
unsigned char bytes[4];
int idx = 0, i;
if (count < 8)
return -ENOMEM;
if (dev->nostat && count < 12)
return -ENOMEM;
cmd = MIDI_CMD_CONTROL|(ev->data.control.channel & 0x0f);
bytes[0] = (ev->data.control.param & 0x3f80) >> 7;
bytes[1] = ev->data.control.param & 0x007f;
bytes[2] = (ev->data.control.value & 0x3f80) >> 7;
bytes[3] = ev->data.control.value & 0x007f;
if (cmd != dev->lastcmd && !dev->nostat) {
if (count < 9)
return -ENOMEM;
buf[idx++] = dev->lastcmd = cmd;
}
cbytes = ev->type == SNDRV_SEQ_EVENT_NONREGPARAM ? cbytes_nrpn : cbytes_rpn;
for (i = 0; i < 4; i++) {
if (dev->nostat)
buf[idx++] = dev->lastcmd = cmd;
buf[idx++] = cbytes[i];
buf[idx++] = bytes[i];
}
return idx;
}
static int __init alsa_seq_midi_event_init(void)
{
return 0;
}
static void __exit alsa_seq_midi_event_exit(void)
{
}
