void
snd_emux_note_on(void *p, int note, int vel, struct snd_midi_channel *chan)
{
struct snd_emux *emu;
int i, key, nvoices;
struct snd_emux_voice *vp;
struct snd_sf_zone *table[SNDRV_EMUX_MAX_MULTI_VOICES];
unsigned long flags;
struct snd_emux_port *port;
port = p;
if (snd_BUG_ON(!port || !chan))
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.get_voice || !emu->ops.trigger))
return;
key = note;
nvoices = get_zone(emu, port, &note, vel, chan, table);
if (! nvoices)
return;
for (i = 0; i < nvoices; i++) {
struct snd_sf_zone *zp = table[i];
if (zp && zp->v.exclusiveClass)
exclusive_note_off(emu, port, zp->v.exclusiveClass);
}
#if 0
terminate_note1(emu, key, chan, 0);
#endif
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < nvoices; i++) {
if (table[i] == NULL)
continue;
vp = emu->ops.get_voice(emu, port);
if (vp == NULL || vp->ch < 0)
continue;
if (STATE_IS_PLAYING(vp->state))
emu->ops.terminate(vp);
vp->time = emu->use_time++;
vp->chan = chan;
vp->port = port;
vp->key = key;
vp->note = note;
vp->velocity = vel;
vp->zone = table[i];
if (vp->zone->sample)
vp->block = vp->zone->sample->block;
else
vp->block = NULL;
setup_voice(vp);
vp->state = SNDRV_EMUX_ST_STANDBY;
if (emu->ops.prepare) {
vp->state = SNDRV_EMUX_ST_OFF;
if (emu->ops.prepare(vp) >= 0)
vp->state = SNDRV_EMUX_ST_STANDBY;
}
}
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (vp->state == SNDRV_EMUX_ST_STANDBY &&
vp->chan == chan) {
emu->ops.trigger(vp);
vp->state = SNDRV_EMUX_ST_ON;
vp->ontime = jiffies;
}
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
if (port->port_mode == SNDRV_EMUX_PORT_MODE_OSS_SYNTH) {
struct snd_emux_effect_table *fx = chan->private;
if (fx) {
fx->flag[EMUX_FX_SAMPLE_START] = 0;
fx->flag[EMUX_FX_COARSE_SAMPLE_START] = 0;
}
}
#endif
}
void
snd_emux_note_off(void *p, int note, int vel, struct snd_midi_channel *chan)
{
int ch;
struct snd_emux *emu;
struct snd_emux_voice *vp;
unsigned long flags;
struct snd_emux_port *port;
port = p;
if (snd_BUG_ON(!port || !chan))
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.release))
return;
spin_lock_irqsave(&emu->voice_lock, flags);
for (ch = 0; ch < emu->max_voices; ch++) {
vp = &emu->voices[ch];
if (STATE_IS_PLAYING(vp->state) &&
vp->chan == chan && vp->key == note) {
vp->state = SNDRV_EMUX_ST_RELEASED;
if (vp->ontime == jiffies) {
vp->state = SNDRV_EMUX_ST_PENDING;
if (! emu->timer_active) {
mod_timer(&emu->tlist, jiffies + 1);
emu->timer_active = 1;
}
} else
emu->ops.release(vp);
}
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void snd_emux_timer_callback(unsigned long data)
{
struct snd_emux *emu = (struct snd_emux *) data;
struct snd_emux_voice *vp;
unsigned long flags;
int ch, do_again = 0;
spin_lock_irqsave(&emu->voice_lock, flags);
for (ch = 0; ch < emu->max_voices; ch++) {
vp = &emu->voices[ch];
if (vp->state == SNDRV_EMUX_ST_PENDING) {
if (vp->ontime == jiffies)
do_again++;
else {
emu->ops.release(vp);
vp->state = SNDRV_EMUX_ST_RELEASED;
}
}
}
if (do_again) {
mod_timer(&emu->tlist, jiffies + 1);
emu->timer_active = 1;
} else
emu->timer_active = 0;
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void
snd_emux_key_press(void *p, int note, int vel, struct snd_midi_channel *chan)
{
int ch;
struct snd_emux *emu;
struct snd_emux_voice *vp;
unsigned long flags;
struct snd_emux_port *port;
port = p;
if (snd_BUG_ON(!port || !chan))
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.update))
return;
spin_lock_irqsave(&emu->voice_lock, flags);
for (ch = 0; ch < emu->max_voices; ch++) {
vp = &emu->voices[ch];
if (vp->state == SNDRV_EMUX_ST_ON &&
vp->chan == chan && vp->key == note) {
vp->velocity = vel;
update_voice(emu, vp, SNDRV_EMUX_UPDATE_VOLUME);
}
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void
snd_emux_update_channel(struct snd_emux_port *port, struct snd_midi_channel *chan, int update)
{
struct snd_emux *emu;
struct snd_emux_voice *vp;
int i;
unsigned long flags;
if (! update)
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.update))
return;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (vp->chan == chan)
update_voice(emu, vp, update);
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void
snd_emux_update_port(struct snd_emux_port *port, int update)
{
struct snd_emux *emu;
struct snd_emux_voice *vp;
int i;
unsigned long flags;
if (! update)
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.update))
return;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (vp->port == port)
update_voice(emu, vp, update);
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void
snd_emux_control(void *p, int type, struct snd_midi_channel *chan)
{
struct snd_emux_port *port;
port = p;
if (snd_BUG_ON(!port || !chan))
return;
switch (type) {
case MIDI_CTL_MSB_MAIN_VOLUME:
case MIDI_CTL_MSB_EXPRESSION:
snd_emux_update_channel(port, chan, SNDRV_EMUX_UPDATE_VOLUME);
break;
case MIDI_CTL_MSB_PAN:
snd_emux_update_channel(port, chan, SNDRV_EMUX_UPDATE_PAN);
break;
case MIDI_CTL_SOFT_PEDAL:
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
if (chan->control[type] >= 64)
snd_emux_send_effect(port, chan, EMUX_FX_CUTOFF, -160,
EMUX_FX_FLAG_ADD);
else
snd_emux_send_effect(port, chan, EMUX_FX_CUTOFF, 0,
EMUX_FX_FLAG_OFF);
#endif
break;
case MIDI_CTL_PITCHBEND:
snd_emux_update_channel(port, chan, SNDRV_EMUX_UPDATE_PITCH);
break;
case MIDI_CTL_MSB_MODWHEEL:
case MIDI_CTL_CHAN_PRESSURE:
snd_emux_update_channel(port, chan,
SNDRV_EMUX_UPDATE_FMMOD |
SNDRV_EMUX_UPDATE_FM2FRQ2);
break;
}
if (port->chset.midi_mode == SNDRV_MIDI_MODE_XG) {
snd_emux_xg_control(port, chan, type);
}
}
static void
terminate_note1(struct snd_emux *emu, int note, struct snd_midi_channel *chan, int free)
{
int i;
struct snd_emux_voice *vp;
unsigned long flags;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (STATE_IS_PLAYING(vp->state) && vp->chan == chan &&
vp->key == note)
terminate_voice(emu, vp, free);
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void
snd_emux_terminate_note(void *p, int note, struct snd_midi_channel *chan)
{
struct snd_emux *emu;
struct snd_emux_port *port;
port = p;
if (snd_BUG_ON(!port || !chan))
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.terminate))
return;
terminate_note1(emu, note, chan, 1);
}
void
snd_emux_terminate_all(struct snd_emux *emu)
{
int i;
struct snd_emux_voice *vp;
unsigned long flags;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (STATE_IS_PLAYING(vp->state))
terminate_voice(emu, vp, 0);
if (vp->state == SNDRV_EMUX_ST_OFF) {
if (emu->ops.free_voice)
emu->ops.free_voice(vp);
if (emu->ops.reset)
emu->ops.reset(emu, i);
}
vp->time = 0;
}
emu->use_time = 0;
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void
snd_emux_sounds_off_all(struct snd_emux_port *port)
{
int i;
struct snd_emux *emu;
struct snd_emux_voice *vp;
unsigned long flags;
if (snd_BUG_ON(!port))
return;
emu = port->emu;
if (snd_BUG_ON(!emu || !emu->ops.terminate))
return;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (STATE_IS_PLAYING(vp->state) &&
vp->port == port)
terminate_voice(emu, vp, 0);
if (vp->state == SNDRV_EMUX_ST_OFF) {
if (emu->ops.free_voice)
emu->ops.free_voice(vp);
if (emu->ops.reset)
emu->ops.reset(emu, i);
}
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
static void
exclusive_note_off(struct snd_emux *emu, struct snd_emux_port *port, int exclass)
{
struct snd_emux_voice *vp;
int i;
unsigned long flags;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
if (STATE_IS_PLAYING(vp->state) && vp->port == port &&
vp->reg.exclusiveClass == exclass) {
terminate_voice(emu, vp, 0);
}
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
static void
terminate_voice(struct snd_emux *emu, struct snd_emux_voice *vp, int free)
{
emu->ops.terminate(vp);
vp->time = emu->use_time++;
vp->chan = NULL;
vp->port = NULL;
vp->zone = NULL;
vp->block = NULL;
vp->state = SNDRV_EMUX_ST_OFF;
if (free && emu->ops.free_voice)
emu->ops.free_voice(vp);
}
static void
update_voice(struct snd_emux *emu, struct snd_emux_voice *vp, int update)
{
if (!STATE_IS_PLAYING(vp->state))
return;
if (vp->chan == NULL || vp->port == NULL)
return;
if (update & SNDRV_EMUX_UPDATE_VOLUME)
calc_volume(vp);
if (update & SNDRV_EMUX_UPDATE_PITCH)
calc_pitch(vp);
if (update & SNDRV_EMUX_UPDATE_PAN) {
if (! calc_pan(vp) && (update == SNDRV_EMUX_UPDATE_PAN))
return;
}
emu->ops.update(vp, update);
}
static void
setup_voice(struct snd_emux_voice *vp)
{
struct soundfont_voice_parm *parm;
int pitch;
vp->reg = vp->zone->v;
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
snd_emux_setup_effect(vp);
#endif
vp->apan = -1;
vp->avol = -1;
vp->apitch = -1;
calc_volume(vp);
calc_pitch(vp);
calc_pan(vp);
parm = &vp->reg.parm;
if (LO_BYTE(parm->modatkhld) >= 0x80 && parm->moddelay >= 0x8000) {
parm->moddelay = 0xbfff;
pitch = (HI_BYTE(parm->pefe) << 4) + vp->apitch;
if (pitch > 0xffff)
pitch = 0xffff;
vp->ftarget = parm->cutoff + LO_BYTE(parm->pefe);
LIMITVALUE(vp->ftarget, 0, 255);
vp->ftarget <<= 8;
} else {
vp->ftarget = parm->cutoff;
vp->ftarget <<= 8;
pitch = vp->apitch;
}
if (pitch != 0xffff) {
vp->ptarget = 1 << (pitch >> 12);
if (pitch & 0x800) vp->ptarget += (vp->ptarget*0x102e)/0x2710;
if (pitch & 0x400) vp->ptarget += (vp->ptarget*0x764)/0x2710;
if (pitch & 0x200) vp->ptarget += (vp->ptarget*0x389)/0x2710;
vp->ptarget += (vp->ptarget >> 1);
if (vp->ptarget > 0xffff) vp->ptarget = 0xffff;
} else
vp->ptarget = 0xffff;
if (LO_BYTE(parm->modatkhld) >= 0x80) {
parm->modatkhld &= ~0xff;
parm->modatkhld |= 0x7f;
}
vp->vtarget = 0;
#if 0
if (LO_BYTE(parm->volatkhld) >= 0x80 && parm->voldelay >= 0x8000) {
parm->voldelay = 0xbfff;
vp->vtarget = voltarget[vp->avol % 0x10] >> (vp->avol >> 4);
}
#endif
if (LO_BYTE(parm->volatkhld) >= 0x80) {
parm->volatkhld &= ~0xff;
parm->volatkhld |= 0x7f;
}
}
static int
calc_pan(struct snd_emux_voice *vp)
{
struct snd_midi_channel *chan = vp->chan;
int pan;
if (vp->reg.fixpan > 0)
pan = 255 - (int)vp->reg.fixpan * 2;
else {
pan = chan->control[MIDI_CTL_MSB_PAN] - 64;
if (vp->reg.pan >= 0)
pan += vp->reg.pan - 64;
pan = 127 - (int)pan * 2;
}
LIMITVALUE(pan, 0, 255);
if (vp->emu->linear_panning) {
if (pan != vp->apan) {
vp->apan = pan;
if (pan == 0)
vp->aaux = 0xff;
else
vp->aaux = (-pan) & 0xff;
return 1;
} else
return 0;
} else {
if (vp->apan != (int)pan_volumes[pan]) {
vp->apan = pan_volumes[pan];
vp->aaux = pan_volumes[255 - pan];
return 1;
}
return 0;
}
}
static int
calc_volume(struct snd_emux_voice *vp)
{
int vol;
int main_vol, expression_vol, master_vol;
struct snd_midi_channel *chan = vp->chan;
struct snd_emux_port *port = vp->port;
expression_vol = chan->control[MIDI_CTL_MSB_EXPRESSION];
LIMITMAX(vp->velocity, 127);
LIMITVALUE(expression_vol, 0, 127);
if (port->port_mode == SNDRV_EMUX_PORT_MODE_OSS_SYNTH) {
main_vol = chan->control[MIDI_CTL_MSB_MAIN_VOLUME];
vol = (vp->velocity * main_vol * expression_vol) / (127*127);
vol = vol * vp->reg.amplitude / 127;
LIMITVALUE(vol, 0, 127);
vol = snd_sf_vol_table[vol];
} else {
main_vol = chan->control[MIDI_CTL_MSB_MAIN_VOLUME] * vp->reg.amplitude / 127;
LIMITVALUE(main_vol, 0, 127);
vol = voltab1[main_vol] + voltab2[vp->velocity];
vol = (vol * 8) / 3;
vol += vp->reg.attenuation;
vol += ((0x100 - vol) * expressiontab[expression_vol])/128;
}
master_vol = port->chset.gs_master_volume;
LIMITVALUE(master_vol, 0, 127);
vol += snd_sf_vol_table[master_vol];
vol += port->volume_atten;
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
if (chan->private) {
struct snd_emux_effect_table *fx = chan->private;
vol += fx->val[EMUX_FX_ATTEN];
}
#endif
LIMITVALUE(vol, 0, 255);
if (vp->avol == vol)
return 0;
vp->avol = vol;
if (!SF_IS_DRUM_BANK(get_bank(port, chan))
&& LO_BYTE(vp->reg.parm.volatkhld) < 0x7d) {
int atten;
if (vp->velocity < 70)
atten = 70;
else
atten = vp->velocity;
vp->acutoff = (atten * vp->reg.parm.cutoff + 0xa0) >> 7;
} else {
vp->acutoff = vp->reg.parm.cutoff;
}
return 1;
}
static int
calc_pitch(struct snd_emux_voice *vp)
{
struct snd_midi_channel *chan = vp->chan;
int offset;
if (vp->reg.fixkey >= 0) {
offset = (vp->reg.fixkey - vp->reg.root) * 4096 / 12;
} else {
offset = (vp->note - vp->reg.root) * 4096 / 12;
}
offset = (offset * vp->reg.scaleTuning) / 100;
offset += vp->reg.tune * 4096 / 1200;
if (chan->midi_pitchbend != 0) {
offset += chan->midi_pitchbend * chan->gm_rpn_pitch_bend_range / 3072;
}
offset += chan->gm_rpn_coarse_tuning * 4096 / (12 * 128);
offset += chan->gm_rpn_fine_tuning / 24;
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
if (chan->private) {
struct snd_emux_effect_table *fx = chan->private;
if (fx->flag[EMUX_FX_INIT_PITCH])
offset += fx->val[EMUX_FX_INIT_PITCH];
}
#endif
offset += 0xe000 + vp->reg.rate_offset;
offset += vp->emu->pitch_shift;
LIMITVALUE(offset, 0, 0xffff);
if (offset == vp->apitch)
return 0;
vp->apitch = offset;
return 1;
}
static int
get_bank(struct snd_emux_port *port, struct snd_midi_channel *chan)
{
int val;
switch (port->chset.midi_mode) {
case SNDRV_MIDI_MODE_XG:
val = chan->control[MIDI_CTL_MSB_BANK];
if (val == 127)
return 128;
return chan->control[MIDI_CTL_LSB_BANK];
case SNDRV_MIDI_MODE_GS:
if (chan->drum_channel)
return 128;
return chan->control[MIDI_CTL_MSB_BANK];
default:
if (chan->drum_channel)
return 128;
return chan->control[MIDI_CTL_MSB_BANK];
}
}
static int
get_zone(struct snd_emux *emu, struct snd_emux_port *port,
int *notep, int vel, struct snd_midi_channel *chan,
struct snd_sf_zone **table)
{
int preset, bank, def_preset, def_bank;
bank = get_bank(port, chan);
preset = chan->midi_program;
if (SF_IS_DRUM_BANK(bank)) {
def_preset = port->ctrls[EMUX_MD_DEF_DRUM];
def_bank = bank;
} else {
def_preset = preset;
def_bank = port->ctrls[EMUX_MD_DEF_BANK];
}
return snd_soundfont_search_zone(emu->sflist, notep, vel, preset, bank,
def_preset, def_bank,
table, SNDRV_EMUX_MAX_MULTI_VOICES);
}
void
snd_emux_init_voices(struct snd_emux *emu)
{
struct snd_emux_voice *vp;
int i;
unsigned long flags;
spin_lock_irqsave(&emu->voice_lock, flags);
for (i = 0; i < emu->max_voices; i++) {
vp = &emu->voices[i];
vp->ch = -1;
vp->state = SNDRV_EMUX_ST_OFF;
vp->chan = NULL;
vp->port = NULL;
vp->time = 0;
vp->emu = emu;
vp->hw = emu->hw;
}
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void snd_emux_lock_voice(struct snd_emux *emu, int voice)
{
unsigned long flags;
spin_lock_irqsave(&emu->voice_lock, flags);
if (emu->voices[voice].state == SNDRV_EMUX_ST_OFF)
emu->voices[voice].state = SNDRV_EMUX_ST_LOCKED;
else
snd_printk(KERN_WARNING
"invalid voice for lock %d (state = %x)\n",
voice, emu->voices[voice].state);
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
void snd_emux_unlock_voice(struct snd_emux *emu, int voice)
{
unsigned long flags;
spin_lock_irqsave(&emu->voice_lock, flags);
if (emu->voices[voice].state == SNDRV_EMUX_ST_LOCKED)
emu->voices[voice].state = SNDRV_EMUX_ST_OFF;
else
snd_printk(KERN_WARNING
"invalid voice for unlock %d (state = %x)\n",
voice, emu->voices[voice].state);
spin_unlock_irqrestore(&emu->voice_lock, flags);
}
