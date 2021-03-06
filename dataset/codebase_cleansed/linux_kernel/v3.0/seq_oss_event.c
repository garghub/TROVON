int
snd_seq_oss_process_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
switch (q->s.code) {
case SEQ_EXTENDED:
return extended_event(dp, q, ev);
case EV_CHN_VOICE:
return chn_voice_event(dp, q, ev);
case EV_CHN_COMMON:
return chn_common_event(dp, q, ev);
case EV_TIMING:
return timing_event(dp, q, ev);
case EV_SEQ_LOCAL:
return local_event(dp, q, ev);
case EV_SYSEX:
return snd_seq_oss_synth_sysex(dp, q->x.dev, q->x.buf, ev);
case SEQ_MIDIPUTC:
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
return -EINVAL;
if (! is_write_mode(dp->file_mode))
break;
if (snd_seq_oss_midi_open(dp, q->s.dev, SNDRV_SEQ_OSS_FILE_WRITE))
break;
if (snd_seq_oss_midi_filemode(dp, q->s.dev) & SNDRV_SEQ_OSS_FILE_WRITE)
return snd_seq_oss_midi_putc(dp, q->s.dev, q->s.parm1, ev);
break;
case SEQ_ECHO:
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
return -EINVAL;
return set_echo_event(dp, q, ev);
case SEQ_PRIVATE:
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
return -EINVAL;
return snd_seq_oss_synth_raw_event(dp, q->c[1], q->c, ev);
default:
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
return -EINVAL;
return old_event(dp, q, ev);
}
return -EINVAL;
}
static int
old_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
switch (q->s.code) {
case SEQ_NOTEOFF:
return note_off_event(dp, 0, q->n.chn, q->n.note, q->n.vel, ev);
case SEQ_NOTEON:
return note_on_event(dp, 0, q->n.chn, q->n.note, q->n.vel, ev);
case SEQ_WAIT:
break;
case SEQ_PGMCHANGE:
return set_control_event(dp, 0, SNDRV_SEQ_EVENT_PGMCHANGE,
q->n.chn, 0, q->n.note, ev);
case SEQ_SYNCTIMER:
return snd_seq_oss_timer_reset(dp->timer);
}
return -EINVAL;
}
static int
extended_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
int val;
switch (q->e.cmd) {
case SEQ_NOTEOFF:
return note_off_event(dp, q->e.dev, q->e.chn, q->e.p1, q->e.p2, ev);
case SEQ_NOTEON:
return note_on_event(dp, q->e.dev, q->e.chn, q->e.p1, q->e.p2, ev);
case SEQ_PGMCHANGE:
return set_control_event(dp, q->e.dev, SNDRV_SEQ_EVENT_PGMCHANGE,
q->e.chn, 0, q->e.p1, ev);
case SEQ_AFTERTOUCH:
return set_control_event(dp, q->e.dev, SNDRV_SEQ_EVENT_CHANPRESS,
q->e.chn, 0, q->e.p1, ev);
case SEQ_BALANCE:
val = (char)q->e.p1;
val = (val + 128) / 2;
return set_control_event(dp, q->e.dev, SNDRV_SEQ_EVENT_CONTROLLER,
q->e.chn, CTL_PAN, val, ev);
case SEQ_CONTROLLER:
val = ((short)q->e.p3 << 8) | (short)q->e.p2;
switch (q->e.p1) {
case CTRL_PITCH_BENDER:
return set_control_event(dp, q->e.dev,
SNDRV_SEQ_EVENT_PITCHBEND,
q->e.chn, 0, val, ev);
case CTRL_PITCH_BENDER_RANGE:
return set_control_event(dp, q->e.dev,
SNDRV_SEQ_EVENT_REGPARAM,
q->e.chn, 0, val*128/100, ev);
default:
return set_control_event(dp, q->e.dev,
SNDRV_SEQ_EVENT_CONTROL14,
q->e.chn, q->e.p1, val, ev);
}
case SEQ_VOLMODE:
return snd_seq_oss_synth_raw_event(dp, q->e.dev, q->c, ev);
}
return -EINVAL;
}
static int
chn_voice_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
if (q->v.chn >= 32)
return -EINVAL;
switch (q->v.cmd) {
case MIDI_NOTEON:
return note_on_event(dp, q->v.dev, q->v.chn, q->v.note, q->v.parm, ev);
case MIDI_NOTEOFF:
return note_off_event(dp, q->v.dev, q->v.chn, q->v.note, q->v.parm, ev);
case MIDI_KEY_PRESSURE:
return set_note_event(dp, q->v.dev, SNDRV_SEQ_EVENT_KEYPRESS,
q->v.chn, q->v.note, q->v.parm, ev);
}
return -EINVAL;
}
static int
chn_common_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
if (q->l.chn >= 32)
return -EINVAL;
switch (q->l.cmd) {
case MIDI_PGM_CHANGE:
return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_PGMCHANGE,
q->l.chn, 0, q->l.p1, ev);
case MIDI_CTL_CHANGE:
return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_CONTROLLER,
q->l.chn, q->l.p1, q->l.val, ev);
case MIDI_PITCH_BEND:
return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_PITCHBEND,
q->l.chn, 0, q->l.val - 8192, ev);
case MIDI_CHN_PRESSURE:
return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_CHANPRESS,
q->l.chn, 0, q->l.val, ev);
}
return -EINVAL;
}
static int
timing_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
switch (q->t.cmd) {
case TMR_ECHO:
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
return set_echo_event(dp, q, ev);
else {
union evrec tmp;
memset(&tmp, 0, sizeof(tmp));
tmp.echo = (q->t.time << 8) | SEQ_ECHO;
return set_echo_event(dp, &tmp, ev);
}
case TMR_STOP:
if (dp->seq_mode)
return snd_seq_oss_timer_stop(dp->timer);
return 0;
case TMR_CONTINUE:
if (dp->seq_mode)
return snd_seq_oss_timer_continue(dp->timer);
return 0;
case TMR_TEMPO:
if (dp->seq_mode)
return snd_seq_oss_timer_tempo(dp->timer, q->t.time);
return 0;
}
return -EINVAL;
}
static int
local_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
return -EINVAL;
}
static int
note_on_event(struct seq_oss_devinfo *dp, int dev, int ch, int note, int vel, struct snd_seq_event *ev)
{
struct seq_oss_synthinfo *info = &dp->synths[dev];
switch (info->arg.event_passing) {
case SNDRV_SEQ_OSS_PROCESS_EVENTS:
if (! info->ch || ch < 0 || ch >= info->nr_voices) {
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
}
if (note == 255 && info->ch[ch].note >= 0) {
int type;
if (info->ch[ch].vel)
type = SNDRV_SEQ_EVENT_KEYPRESS;
else
type = SNDRV_SEQ_EVENT_NOTEON;
info->ch[ch].vel = vel;
return set_note_event(dp, dev, type, ch, info->ch[ch].note, vel, ev);
} else if (note >= 128)
return -EINVAL;
if (note != info->ch[ch].note && info->ch[ch].note >= 0)
set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEOFF, ch, info->ch[ch].note, 0, ev);
info->ch[ch].note = note;
info->ch[ch].vel = vel;
if (vel)
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
return -EINVAL;
case SNDRV_SEQ_OSS_PASS_EVENTS:
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
case SNDRV_SEQ_OSS_PROCESS_KEYPRESS:
if (note >= 128)
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_KEYPRESS, ch, note - 128, vel, ev);
else
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
}
return -EINVAL;
}
static int
note_off_event(struct seq_oss_devinfo *dp, int dev, int ch, int note, int vel, struct snd_seq_event *ev)
{
struct seq_oss_synthinfo *info = &dp->synths[dev];
switch (info->arg.event_passing) {
case SNDRV_SEQ_OSS_PROCESS_EVENTS:
if (! info->ch || ch < 0 || ch >= info->nr_voices) {
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
}
if (info->ch[ch].note >= 0) {
note = info->ch[ch].note;
info->ch[ch].vel = 0;
info->ch[ch].note = -1;
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEOFF, ch, note, vel, ev);
}
return -EINVAL;
case SNDRV_SEQ_OSS_PASS_EVENTS:
case SNDRV_SEQ_OSS_PROCESS_KEYPRESS:
return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEOFF, ch, note, vel, ev);
}
return -EINVAL;
}
static int
set_note_event(struct seq_oss_devinfo *dp, int dev, int type, int ch, int note, int vel, struct snd_seq_event *ev)
{
if (! snd_seq_oss_synth_is_valid(dp, dev))
return -ENXIO;
ev->type = type;
snd_seq_oss_synth_addr(dp, dev, ev);
ev->data.note.channel = ch;
ev->data.note.note = note;
ev->data.note.velocity = vel;
return 0;
}
static int
set_control_event(struct seq_oss_devinfo *dp, int dev, int type, int ch, int param, int val, struct snd_seq_event *ev)
{
if (! snd_seq_oss_synth_is_valid(dp, dev))
return -ENXIO;
ev->type = type;
snd_seq_oss_synth_addr(dp, dev, ev);
ev->data.control.channel = ch;
ev->data.control.param = param;
ev->data.control.value = val;
return 0;
}
static int
set_echo_event(struct seq_oss_devinfo *dp, union evrec *rec, struct snd_seq_event *ev)
{
ev->type = SNDRV_SEQ_EVENT_ECHO;
snd_seq_oss_fill_addr(dp, ev, dp->addr.client, dp->addr.port);
memcpy(&ev->data, rec, LONG_EVENT_SIZE);
return 0;
}
int
snd_seq_oss_event_input(struct snd_seq_event *ev, int direct, void *private_data,
int atomic, int hop)
{
struct seq_oss_devinfo *dp = (struct seq_oss_devinfo *)private_data;
union evrec *rec;
if (ev->type != SNDRV_SEQ_EVENT_ECHO)
return snd_seq_oss_midi_input(ev, direct, private_data);
if (ev->source.client != dp->cseq)
return 0;
rec = (union evrec*)&ev->data;
if (rec->s.code == SEQ_SYNCTIMER) {
snd_seq_oss_writeq_wakeup(dp->writeq, rec->t.time);
} else {
if (dp->readq == NULL)
return 0;
snd_seq_oss_readq_put_event(dp->readq, rec);
}
return 0;
}
