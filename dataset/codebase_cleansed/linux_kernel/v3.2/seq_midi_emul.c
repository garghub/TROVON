void
snd_midi_process_event(struct snd_midi_op *ops,
struct snd_seq_event *ev,
struct snd_midi_channel_set *chanset)
{
struct snd_midi_channel *chan;
void *drv;
int dest_channel = 0;
if (ev == NULL || chanset == NULL) {
snd_printd("ev or chanbase NULL (snd_midi_process_event)\n");
return;
}
if (chanset->channels == NULL)
return;
if (snd_seq_ev_is_channel_type(ev)) {
dest_channel = ev->data.note.channel;
if (dest_channel >= chanset->max_channels) {
snd_printd("dest channel is %d, max is %d\n",
dest_channel, chanset->max_channels);
return;
}
}
chan = chanset->channels + dest_channel;
drv = chanset->private_data;
if (ev->type == SNDRV_SEQ_EVENT_NOTE)
return;
if (ev->type == SNDRV_SEQ_EVENT_NOTEON && ev->data.note.velocity == 0)
ev->type = SNDRV_SEQ_EVENT_NOTEOFF;
if (ev->type == SNDRV_SEQ_EVENT_NOTEON ||
ev->type == SNDRV_SEQ_EVENT_NOTEOFF ||
ev->type == SNDRV_SEQ_EVENT_KEYPRESS) {
if (ev->data.note.note >= 128)
return;
}
switch (ev->type) {
case SNDRV_SEQ_EVENT_NOTEON:
if (chan->note[ev->data.note.note] & SNDRV_MIDI_NOTE_ON) {
if (ops->note_off)
ops->note_off(drv, ev->data.note.note, 0, chan);
}
chan->note[ev->data.note.note] = SNDRV_MIDI_NOTE_ON;
if (ops->note_on)
ops->note_on(drv, ev->data.note.note, ev->data.note.velocity, chan);
break;
case SNDRV_SEQ_EVENT_NOTEOFF:
if (! (chan->note[ev->data.note.note] & SNDRV_MIDI_NOTE_ON))
break;
if (ops->note_off)
note_off(ops, drv, chan, ev->data.note.note, ev->data.note.velocity);
break;
case SNDRV_SEQ_EVENT_KEYPRESS:
if (ops->key_press)
ops->key_press(drv, ev->data.note.note, ev->data.note.velocity, chan);
break;
case SNDRV_SEQ_EVENT_CONTROLLER:
do_control(ops, drv, chanset, chan,
ev->data.control.param, ev->data.control.value);
break;
case SNDRV_SEQ_EVENT_PGMCHANGE:
chan->midi_program = ev->data.control.value;
break;
case SNDRV_SEQ_EVENT_PITCHBEND:
chan->midi_pitchbend = ev->data.control.value;
if (ops->control)
ops->control(drv, MIDI_CTL_PITCHBEND, chan);
break;
case SNDRV_SEQ_EVENT_CHANPRESS:
chan->midi_pressure = ev->data.control.value;
if (ops->control)
ops->control(drv, MIDI_CTL_CHAN_PRESSURE, chan);
break;
case SNDRV_SEQ_EVENT_CONTROL14:
if (ev->data.control.param < 32) {
chan->control[ev->data.control.param + 32] =
ev->data.control.value & 0x7f;
do_control(ops, drv, chanset, chan,
ev->data.control.param,
((ev->data.control.value>>7) & 0x7f));
} else
do_control(ops, drv, chanset, chan,
ev->data.control.param,
ev->data.control.value);
break;
case SNDRV_SEQ_EVENT_NONREGPARAM:
chan->param_type = SNDRV_MIDI_PARAM_TYPE_NONREGISTERED;
chan->control[MIDI_CTL_MSB_DATA_ENTRY]
= (ev->data.control.value >> 7) & 0x7f;
chan->control[MIDI_CTL_LSB_DATA_ENTRY]
= ev->data.control.value & 0x7f;
chan->control[MIDI_CTL_NONREG_PARM_NUM_MSB]
= (ev->data.control.param >> 7) & 0x7f;
chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB]
= ev->data.control.param & 0x7f;
nrpn(ops, drv, chan, chanset);
break;
case SNDRV_SEQ_EVENT_REGPARAM:
chan->param_type = SNDRV_MIDI_PARAM_TYPE_REGISTERED;
chan->control[MIDI_CTL_MSB_DATA_ENTRY]
= (ev->data.control.value >> 7) & 0x7f;
chan->control[MIDI_CTL_LSB_DATA_ENTRY]
= ev->data.control.value & 0x7f;
chan->control[MIDI_CTL_REGIST_PARM_NUM_MSB]
= (ev->data.control.param >> 7) & 0x7f;
chan->control[MIDI_CTL_REGIST_PARM_NUM_LSB]
= ev->data.control.param & 0x7f;
rpn(ops, drv, chan, chanset);
break;
case SNDRV_SEQ_EVENT_SYSEX:
if ((ev->flags & SNDRV_SEQ_EVENT_LENGTH_MASK) == SNDRV_SEQ_EVENT_LENGTH_VARIABLE) {
unsigned char sysexbuf[64];
int len;
len = snd_seq_expand_var_event(ev, sizeof(sysexbuf), sysexbuf, 1, 0);
if (len > 0)
sysex(ops, drv, sysexbuf, len, chanset);
}
break;
case SNDRV_SEQ_EVENT_SONGPOS:
case SNDRV_SEQ_EVENT_SONGSEL:
case SNDRV_SEQ_EVENT_CLOCK:
case SNDRV_SEQ_EVENT_START:
case SNDRV_SEQ_EVENT_CONTINUE:
case SNDRV_SEQ_EVENT_STOP:
case SNDRV_SEQ_EVENT_QFRAME:
case SNDRV_SEQ_EVENT_TEMPO:
case SNDRV_SEQ_EVENT_TIMESIGN:
case SNDRV_SEQ_EVENT_KEYSIGN:
goto not_yet;
case SNDRV_SEQ_EVENT_SENSING:
break;
case SNDRV_SEQ_EVENT_CLIENT_START:
case SNDRV_SEQ_EVENT_CLIENT_EXIT:
case SNDRV_SEQ_EVENT_CLIENT_CHANGE:
case SNDRV_SEQ_EVENT_PORT_START:
case SNDRV_SEQ_EVENT_PORT_EXIT:
case SNDRV_SEQ_EVENT_PORT_CHANGE:
case SNDRV_SEQ_EVENT_ECHO:
not_yet:
default:
break;
}
}
static void
note_off(struct snd_midi_op *ops, void *drv, struct snd_midi_channel *chan,
int note, int vel)
{
if (chan->gm_hold) {
chan->note[note] |= SNDRV_MIDI_NOTE_RELEASED;
} else if (chan->note[note] & SNDRV_MIDI_NOTE_SOSTENUTO) {
chan->note[note] |= SNDRV_MIDI_NOTE_RELEASED;
} else {
chan->note[note] = 0;
if (ops->note_off)
ops->note_off(drv, note, vel, chan);
}
}
static void
do_control(struct snd_midi_op *ops, void *drv, struct snd_midi_channel_set *chset,
struct snd_midi_channel *chan, int control, int value)
{
int i;
if ((control >=64 && control <=69) || (control >= 80 && control <= 83)) {
value = (value >= 64)? 127: 0;
}
chan->control[control] = value;
switch (control) {
case MIDI_CTL_SUSTAIN:
if (value == 0) {
for (i = 0; i < 128; i++) {
if (chan->note[i] & SNDRV_MIDI_NOTE_RELEASED) {
chan->note[i] = SNDRV_MIDI_NOTE_OFF;
if (ops->note_off)
ops->note_off(drv, i, 0, chan);
}
}
}
break;
case MIDI_CTL_PORTAMENTO:
break;
case MIDI_CTL_SOSTENUTO:
if (value) {
for (i = 0; i < 128; i++) {
if (chan->note[i] & SNDRV_MIDI_NOTE_ON)
chan->note[i] |= SNDRV_MIDI_NOTE_SOSTENUTO;
}
} else {
for (i = 0; i < 128; i++) {
if (chan->note[i] & SNDRV_MIDI_NOTE_SOSTENUTO) {
chan->note[i] &= ~SNDRV_MIDI_NOTE_SOSTENUTO;
if (chan->note[i] & SNDRV_MIDI_NOTE_RELEASED) {
chan->note[i] = SNDRV_MIDI_NOTE_OFF;
if (ops->note_off)
ops->note_off(drv, i, 0, chan);
}
}
}
}
break;
case MIDI_CTL_MSB_DATA_ENTRY:
chan->control[MIDI_CTL_LSB_DATA_ENTRY] = 0;
case MIDI_CTL_LSB_DATA_ENTRY:
if (chan->param_type == SNDRV_MIDI_PARAM_TYPE_REGISTERED)
rpn(ops, drv, chan, chset);
else
nrpn(ops, drv, chan, chset);
break;
case MIDI_CTL_REGIST_PARM_NUM_LSB:
case MIDI_CTL_REGIST_PARM_NUM_MSB:
chan->param_type = SNDRV_MIDI_PARAM_TYPE_REGISTERED;
break;
case MIDI_CTL_NONREG_PARM_NUM_LSB:
case MIDI_CTL_NONREG_PARM_NUM_MSB:
chan->param_type = SNDRV_MIDI_PARAM_TYPE_NONREGISTERED;
break;
case MIDI_CTL_ALL_SOUNDS_OFF:
all_sounds_off(ops, drv, chan);
break;
case MIDI_CTL_ALL_NOTES_OFF:
all_notes_off(ops, drv, chan);
break;
case MIDI_CTL_MSB_BANK:
if (chset->midi_mode == SNDRV_MIDI_MODE_XG) {
if (value == 127)
chan->drum_channel = 1;
else
chan->drum_channel = 0;
}
break;
case MIDI_CTL_LSB_BANK:
break;
case MIDI_CTL_RESET_CONTROLLERS:
snd_midi_reset_controllers(chan);
break;
case MIDI_CTL_SOFT_PEDAL:
case MIDI_CTL_LEGATO_FOOTSWITCH:
case MIDI_CTL_HOLD2:
case MIDI_CTL_SC1_SOUND_VARIATION:
case MIDI_CTL_SC2_TIMBRE:
case MIDI_CTL_SC3_RELEASE_TIME:
case MIDI_CTL_SC4_ATTACK_TIME:
case MIDI_CTL_SC5_BRIGHTNESS:
case MIDI_CTL_E1_REVERB_DEPTH:
case MIDI_CTL_E2_TREMOLO_DEPTH:
case MIDI_CTL_E3_CHORUS_DEPTH:
case MIDI_CTL_E4_DETUNE_DEPTH:
case MIDI_CTL_E5_PHASER_DEPTH:
goto notyet;
notyet:
default:
if (ops->control)
ops->control(drv, control, chan);
break;
}
}
void
snd_midi_channel_set_clear(struct snd_midi_channel_set *chset)
{
int i;
chset->midi_mode = SNDRV_MIDI_MODE_GM;
chset->gs_master_volume = 127;
for (i = 0; i < chset->max_channels; i++) {
struct snd_midi_channel *chan = chset->channels + i;
memset(chan->note, 0, sizeof(chan->note));
chan->midi_aftertouch = 0;
chan->midi_pressure = 0;
chan->midi_program = 0;
chan->midi_pitchbend = 0;
snd_midi_reset_controllers(chan);
chan->gm_rpn_pitch_bend_range = 256;
chan->gm_rpn_fine_tuning = 0;
chan->gm_rpn_coarse_tuning = 0;
if (i == 9)
chan->drum_channel = 1;
else
chan->drum_channel = 0;
}
}
static void
rpn(struct snd_midi_op *ops, void *drv, struct snd_midi_channel *chan,
struct snd_midi_channel_set *chset)
{
int type;
int val;
if (chset->midi_mode != SNDRV_MIDI_MODE_NONE) {
type = (chan->control[MIDI_CTL_REGIST_PARM_NUM_MSB] << 8) |
chan->control[MIDI_CTL_REGIST_PARM_NUM_LSB];
val = (chan->control[MIDI_CTL_MSB_DATA_ENTRY] << 7) |
chan->control[MIDI_CTL_LSB_DATA_ENTRY];
switch (type) {
case 0x0000:
chan->gm_rpn_pitch_bend_range = val;
break;
case 0x0001:
chan->gm_rpn_fine_tuning = val - 8192;
break;
case 0x0002:
chan->gm_rpn_coarse_tuning = val - 8192;
break;
case 0x7F7F:
break;
}
}
}
static void
nrpn(struct snd_midi_op *ops, void *drv, struct snd_midi_channel *chan,
struct snd_midi_channel_set *chset)
{
if (ops->nrpn)
ops->nrpn(drv, chan, chset);
}
static int
get_channel(unsigned char cmd)
{
int p = cmd & 0x0f;
if (p == 0)
p = 9;
else if (p < 10)
p--;
return p;
}
static void
sysex(struct snd_midi_op *ops, void *private, unsigned char *buf, int len,
struct snd_midi_channel_set *chset)
{
static unsigned char gm_on_macro[] = {
0x7e,0x7f,0x09,0x01,
};
static unsigned char xg_on_macro[] = {
0x43,0x10,0x4c,0x00,0x00,0x7e,0x00,
};
static unsigned char gs_pfx_macro[] = {
0x41,0x10,0x42,0x12,0x40,
};
int parsed = SNDRV_MIDI_SYSEX_NOT_PARSED;
if (len <= 0 || buf[0] != 0xf0)
return;
buf++;
len--;
if (len >= (int)sizeof(gm_on_macro) &&
memcmp(buf, gm_on_macro, sizeof(gm_on_macro)) == 0) {
if (chset->midi_mode != SNDRV_MIDI_MODE_GS &&
chset->midi_mode != SNDRV_MIDI_MODE_XG) {
chset->midi_mode = SNDRV_MIDI_MODE_GM;
reset_all_channels(chset);
parsed = SNDRV_MIDI_SYSEX_GM_ON;
}
}
else if (len >= 8 &&
memcmp(buf, gs_pfx_macro, sizeof(gs_pfx_macro)) == 0) {
if (chset->midi_mode != SNDRV_MIDI_MODE_GS &&
chset->midi_mode != SNDRV_MIDI_MODE_XG)
chset->midi_mode = SNDRV_MIDI_MODE_GS;
if (buf[5] == 0x00 && buf[6] == 0x7f && buf[7] == 0x00) {
parsed = SNDRV_MIDI_SYSEX_GS_RESET;
reset_all_channels(chset);
}
else if ((buf[5] & 0xf0) == 0x10 && buf[6] == 0x15) {
int p = get_channel(buf[5]);
if (p < chset->max_channels) {
parsed = SNDRV_MIDI_SYSEX_GS_DRUM_CHANNEL;
if (buf[7])
chset->channels[p].drum_channel = 1;
else
chset->channels[p].drum_channel = 0;
}
} else if ((buf[5] & 0xf0) == 0x10 && buf[6] == 0x21) {
int p = get_channel(buf[5]);
if (p < chset->max_channels &&
! chset->channels[p].drum_channel) {
parsed = SNDRV_MIDI_SYSEX_GS_DRUM_CHANNEL;
chset->channels[p].midi_program = buf[7];
}
} else if (buf[5] == 0x01 && buf[6] == 0x30) {
parsed = SNDRV_MIDI_SYSEX_GS_REVERB_MODE;
chset->gs_reverb_mode = buf[7];
} else if (buf[5] == 0x01 && buf[6] == 0x38) {
parsed = SNDRV_MIDI_SYSEX_GS_CHORUS_MODE;
chset->gs_chorus_mode = buf[7];
} else if (buf[5] == 0x00 && buf[6] == 0x04) {
parsed = SNDRV_MIDI_SYSEX_GS_MASTER_VOLUME;
chset->gs_master_volume = buf[7];
}
}
else if (len >= (int)sizeof(xg_on_macro) &&
memcmp(buf, xg_on_macro, sizeof(xg_on_macro)) == 0) {
int i;
chset->midi_mode = SNDRV_MIDI_MODE_XG;
parsed = SNDRV_MIDI_SYSEX_XG_ON;
for (i = 0; i < chset->max_channels; i++) {
if (chset->channels[i].drum_channel)
chset->channels[i].control[MIDI_CTL_MSB_BANK] = 127;
else
chset->channels[i].control[MIDI_CTL_MSB_BANK] = 0;
}
}
if (ops->sysex)
ops->sysex(private, buf - 1, len + 1, parsed, chset);
}
static void
all_sounds_off(struct snd_midi_op *ops, void *drv, struct snd_midi_channel *chan)
{
int n;
if (! ops->note_terminate)
return;
for (n = 0; n < 128; n++) {
if (chan->note[n]) {
ops->note_terminate(drv, n, chan);
chan->note[n] = 0;
}
}
}
static void
all_notes_off(struct snd_midi_op *ops, void *drv, struct snd_midi_channel *chan)
{
int n;
if (! ops->note_off)
return;
for (n = 0; n < 128; n++) {
if (chan->note[n] == SNDRV_MIDI_NOTE_ON)
note_off(ops, drv, chan, n, 0);
}
}
static void snd_midi_channel_init(struct snd_midi_channel *p, int n)
{
if (p == NULL)
return;
memset(p, 0, sizeof(struct snd_midi_channel));
p->private = NULL;
p->number = n;
snd_midi_reset_controllers(p);
p->gm_rpn_pitch_bend_range = 256;
p->gm_rpn_fine_tuning = 0;
p->gm_rpn_coarse_tuning = 0;
if (n == 9)
p->drum_channel = 1;
}
static struct snd_midi_channel *snd_midi_channel_init_set(int n)
{
struct snd_midi_channel *chan;
int i;
chan = kmalloc(n * sizeof(struct snd_midi_channel), GFP_KERNEL);
if (chan) {
for (i = 0; i < n; i++)
snd_midi_channel_init(chan+i, i);
}
return chan;
}
static void
reset_all_channels(struct snd_midi_channel_set *chset)
{
int ch;
for (ch = 0; ch < chset->max_channels; ch++) {
struct snd_midi_channel *chan = chset->channels + ch;
snd_midi_reset_controllers(chan);
chan->gm_rpn_pitch_bend_range = 256;
chan->gm_rpn_fine_tuning = 0;
chan->gm_rpn_coarse_tuning = 0;
if (ch == 9)
chan->drum_channel = 1;
else
chan->drum_channel = 0;
}
}
struct snd_midi_channel_set *snd_midi_channel_alloc_set(int n)
{
struct snd_midi_channel_set *chset;
chset = kmalloc(sizeof(*chset), GFP_KERNEL);
if (chset) {
chset->channels = snd_midi_channel_init_set(n);
chset->private_data = NULL;
chset->max_channels = n;
}
return chset;
}
static void snd_midi_reset_controllers(struct snd_midi_channel *chan)
{
memset(chan->control, 0, sizeof(chan->control));
chan->gm_volume = 127;
chan->gm_expression = 127;
chan->gm_pan = 64;
}
void snd_midi_channel_free_set(struct snd_midi_channel_set *chset)
{
if (chset == NULL)
return;
kfree(chset->channels);
kfree(chset);
}
static int __init alsa_seq_midi_emul_init(void)
{
return 0;
}
static void __exit alsa_seq_midi_emul_exit(void)
{
}
