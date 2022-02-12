void snd_opl4_synth_reset(struct snd_opl4 *opl4)
{
unsigned long flags;
int i;
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < OPL4_MAX_VOICES; i++)
snd_opl4_write(opl4, OPL4_REG_MISC + i, OPL4_DAMP_BIT);
spin_unlock_irqrestore(&opl4->reg_lock, flags);
INIT_LIST_HEAD(&opl4->off_voices);
INIT_LIST_HEAD(&opl4->on_voices);
memset(opl4->voices, 0, sizeof(opl4->voices));
for (i = 0; i < OPL4_MAX_VOICES; i++) {
opl4->voices[i].number = i;
list_add_tail(&opl4->voices[i].list, &opl4->off_voices);
}
snd_midi_channel_set_clear(opl4->chset);
}
void snd_opl4_synth_shutdown(struct snd_opl4 *opl4)
{
unsigned long flags;
int i;
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < OPL4_MAX_VOICES; i++)
snd_opl4_write(opl4, OPL4_REG_MISC + i,
opl4->voices[i].reg_misc & ~OPL4_KEY_ON_BIT);
spin_unlock_irqrestore(&opl4->reg_lock, flags);
}
static void snd_opl4_do_for_note(struct snd_opl4 *opl4, int note, struct snd_midi_channel *chan,
void (*func)(struct snd_opl4 *opl4, struct opl4_voice *voice))
{
int i;
unsigned long flags;
struct opl4_voice *voice;
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < OPL4_MAX_VOICES; i++) {
voice = &opl4->voices[i];
if (voice->chan == chan && voice->note == note) {
func(opl4, voice);
}
}
spin_unlock_irqrestore(&opl4->reg_lock, flags);
}
static void snd_opl4_do_for_channel(struct snd_opl4 *opl4,
struct snd_midi_channel *chan,
void (*func)(struct snd_opl4 *opl4, struct opl4_voice *voice))
{
int i;
unsigned long flags;
struct opl4_voice *voice;
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < OPL4_MAX_VOICES; i++) {
voice = &opl4->voices[i];
if (voice->chan == chan) {
func(opl4, voice);
}
}
spin_unlock_irqrestore(&opl4->reg_lock, flags);
}
static void snd_opl4_do_for_all(struct snd_opl4 *opl4,
void (*func)(struct snd_opl4 *opl4, struct opl4_voice *voice))
{
int i;
unsigned long flags;
struct opl4_voice *voice;
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < OPL4_MAX_VOICES; i++) {
voice = &opl4->voices[i];
if (voice->chan)
func(opl4, voice);
}
spin_unlock_irqrestore(&opl4->reg_lock, flags);
}
static void snd_opl4_update_volume(struct snd_opl4 *opl4, struct opl4_voice *voice)
{
int att;
att = voice->sound->tone_attenuate;
att += snd_opl4_volume_table[opl4->chset->gs_master_volume & 0x7f];
att += snd_opl4_volume_table[voice->chan->gm_volume & 0x7f];
att += snd_opl4_volume_table[voice->chan->gm_expression & 0x7f];
att += snd_opl4_volume_table[voice->velocity];
att = 0x7f - (0x7f - att) * (voice->sound->volume_factor) / 0xfe - volume_boost;
if (att < 0)
att = 0;
else if (att > 0x7e)
att = 0x7e;
snd_opl4_write(opl4, OPL4_REG_LEVEL + voice->number,
(att << 1) | voice->level_direct);
voice->level_direct = 0;
}
static void snd_opl4_update_pan(struct snd_opl4 *opl4, struct opl4_voice *voice)
{
int pan = voice->sound->panpot;
if (!voice->chan->drum_channel)
pan += (voice->chan->control[MIDI_CTL_MSB_PAN] - 0x40) >> 3;
if (pan < -7)
pan = -7;
else if (pan > 7)
pan = 7;
voice->reg_misc = (voice->reg_misc & ~OPL4_PAN_POT_MASK)
| (pan & OPL4_PAN_POT_MASK);
snd_opl4_write(opl4, OPL4_REG_MISC + voice->number, voice->reg_misc);
}
static void snd_opl4_update_vibrato_depth(struct snd_opl4 *opl4,
struct opl4_voice *voice)
{
int depth;
if (voice->chan->drum_channel)
return;
depth = (7 - voice->sound->vibrato)
* (voice->chan->control[MIDI_CTL_VIBRATO_DEPTH] & 0x7f);
depth = (depth >> 7) + voice->sound->vibrato;
voice->reg_lfo_vibrato &= ~OPL4_VIBRATO_DEPTH_MASK;
voice->reg_lfo_vibrato |= depth & OPL4_VIBRATO_DEPTH_MASK;
snd_opl4_write(opl4, OPL4_REG_LFO_VIBRATO + voice->number,
voice->reg_lfo_vibrato);
}
static void snd_opl4_update_pitch(struct snd_opl4 *opl4,
struct opl4_voice *voice)
{
struct snd_midi_channel *chan = voice->chan;
int note, pitch, octave;
note = chan->drum_channel ? 60 : voice->note;
pitch = ((note - 60) << 7) * voice->sound->key_scaling / 100 + (60 << 7);
pitch += voice->sound->pitch_offset;
if (!chan->drum_channel)
pitch += chan->gm_rpn_coarse_tuning;
pitch += chan->gm_rpn_fine_tuning >> 7;
pitch += chan->midi_pitchbend * chan->gm_rpn_pitch_bend_range / 0x2000;
if (pitch < 0)
pitch = 0;
else if (pitch >= 0x6000)
pitch = 0x5fff;
octave = pitch / 0x600 - 8;
pitch = snd_opl4_pitch_map[pitch % 0x600];
snd_opl4_write(opl4, OPL4_REG_OCTAVE + voice->number,
(octave << 4) | ((pitch >> 7) & OPL4_F_NUMBER_HIGH_MASK));
voice->reg_f_number = (voice->reg_f_number & OPL4_TONE_NUMBER_BIT8)
| ((pitch << 1) & OPL4_F_NUMBER_LOW_MASK);
snd_opl4_write(opl4, OPL4_REG_F_NUMBER + voice->number, voice->reg_f_number);
}
static void snd_opl4_update_tone_parameters(struct snd_opl4 *opl4,
struct opl4_voice *voice)
{
snd_opl4_write(opl4, OPL4_REG_ATTACK_DECAY1 + voice->number,
voice->sound->reg_attack_decay1);
snd_opl4_write(opl4, OPL4_REG_LEVEL_DECAY2 + voice->number,
voice->sound->reg_level_decay2);
snd_opl4_write(opl4, OPL4_REG_RELEASE_CORRECTION + voice->number,
voice->sound->reg_release_correction);
snd_opl4_write(opl4, OPL4_REG_TREMOLO + voice->number,
voice->sound->reg_tremolo);
}
static struct opl4_voice *snd_opl4_get_voice(struct snd_opl4 *opl4)
{
if (!list_empty(&opl4->off_voices))
return list_entry(opl4->off_voices.next, struct opl4_voice, list);
snd_BUG_ON(list_empty(&opl4->on_voices));
return list_entry(opl4->on_voices.next, struct opl4_voice, list);
}
static void snd_opl4_wait_for_wave_headers(struct snd_opl4 *opl4)
{
int timeout = 200;
while ((inb(opl4->fm_port) & OPL4_STATUS_LOAD) && --timeout > 0)
udelay(10);
}
void snd_opl4_note_on(void *private_data, int note, int vel, struct snd_midi_channel *chan)
{
struct snd_opl4 *opl4 = private_data;
const struct opl4_region_ptr *regions;
struct opl4_voice *voice[2];
const struct opl4_sound *sound[2];
int voices = 0, i;
unsigned long flags;
i = chan->drum_channel ? 0x80 : (chan->midi_program & 0x7f);
regions = &snd_yrw801_regions[i];
for (i = 0; i < regions->count; i++) {
if (note >= regions->regions[i].key_min &&
note <= regions->regions[i].key_max) {
sound[voices] = &regions->regions[i].sound;
if (++voices >= 2)
break;
}
}
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < voices; i++) {
voice[i] = snd_opl4_get_voice(opl4);
list_move_tail(&voice[i]->list, &opl4->on_voices);
voice[i]->chan = chan;
voice[i]->note = note;
voice[i]->velocity = vel & 0x7f;
voice[i]->sound = sound[i];
}
for (i = 0; i < voices; i++) {
voice[i]->reg_f_number =
(sound[i]->tone >> 8) & OPL4_TONE_NUMBER_BIT8;
snd_opl4_write(opl4, OPL4_REG_F_NUMBER + voice[i]->number,
voice[i]->reg_f_number);
snd_opl4_write(opl4, OPL4_REG_TONE_NUMBER + voice[i]->number,
sound[i]->tone & 0xff);
}
for (i = 0; i < voices; i++) {
voice[i]->reg_misc = OPL4_LFO_RESET_BIT;
snd_opl4_update_pan(opl4, voice[i]);
snd_opl4_update_pitch(opl4, voice[i]);
voice[i]->level_direct = OPL4_LEVEL_DIRECT_BIT;
snd_opl4_update_volume(opl4, voice[i]);
}
spin_unlock_irqrestore(&opl4->reg_lock, flags);
snd_opl4_wait_for_wave_headers(opl4);
spin_lock_irqsave(&opl4->reg_lock, flags);
for (i = 0; i < voices; i++) {
snd_opl4_update_tone_parameters(opl4, voice[i]);
voice[i]->reg_lfo_vibrato = voice[i]->sound->reg_lfo_vibrato;
snd_opl4_update_vibrato_depth(opl4, voice[i]);
}
for (i = 0; i < voices; i++) {
voice[i]->reg_misc =
(voice[i]->reg_misc & 0x1f) | OPL4_KEY_ON_BIT;
snd_opl4_write(opl4, OPL4_REG_MISC + voice[i]->number,
voice[i]->reg_misc);
}
spin_unlock_irqrestore(&opl4->reg_lock, flags);
}
static void snd_opl4_voice_off(struct snd_opl4 *opl4, struct opl4_voice *voice)
{
list_move_tail(&voice->list, &opl4->off_voices);
voice->reg_misc &= ~OPL4_KEY_ON_BIT;
snd_opl4_write(opl4, OPL4_REG_MISC + voice->number, voice->reg_misc);
}
void snd_opl4_note_off(void *private_data, int note, int vel, struct snd_midi_channel *chan)
{
struct snd_opl4 *opl4 = private_data;
snd_opl4_do_for_note(opl4, note, chan, snd_opl4_voice_off);
}
static void snd_opl4_terminate_voice(struct snd_opl4 *opl4, struct opl4_voice *voice)
{
list_move_tail(&voice->list, &opl4->off_voices);
voice->reg_misc = (voice->reg_misc & ~OPL4_KEY_ON_BIT) | OPL4_DAMP_BIT;
snd_opl4_write(opl4, OPL4_REG_MISC + voice->number, voice->reg_misc);
}
void snd_opl4_terminate_note(void *private_data, int note, struct snd_midi_channel *chan)
{
struct snd_opl4 *opl4 = private_data;
snd_opl4_do_for_note(opl4, note, chan, snd_opl4_terminate_voice);
}
void snd_opl4_control(void *private_data, int type, struct snd_midi_channel *chan)
{
struct snd_opl4 *opl4 = private_data;
switch (type) {
case MIDI_CTL_MSB_MODWHEEL:
chan->control[MIDI_CTL_VIBRATO_DEPTH] = chan->control[MIDI_CTL_MSB_MODWHEEL];
snd_opl4_do_for_channel(opl4, chan, snd_opl4_update_vibrato_depth);
break;
case MIDI_CTL_MSB_MAIN_VOLUME:
snd_opl4_do_for_channel(opl4, chan, snd_opl4_update_volume);
break;
case MIDI_CTL_MSB_PAN:
snd_opl4_do_for_channel(opl4, chan, snd_opl4_update_pan);
break;
case MIDI_CTL_MSB_EXPRESSION:
snd_opl4_do_for_channel(opl4, chan, snd_opl4_update_volume);
break;
case MIDI_CTL_VIBRATO_RATE:
break;
case MIDI_CTL_VIBRATO_DEPTH:
snd_opl4_do_for_channel(opl4, chan, snd_opl4_update_vibrato_depth);
break;
case MIDI_CTL_VIBRATO_DELAY:
break;
case MIDI_CTL_E1_REVERB_DEPTH:
break;
case MIDI_CTL_PITCHBEND:
snd_opl4_do_for_channel(opl4, chan, snd_opl4_update_pitch);
break;
}
}
void snd_opl4_sysex(void *private_data, unsigned char *buf, int len,
int parsed, struct snd_midi_channel_set *chset)
{
struct snd_opl4 *opl4 = private_data;
if (parsed == SNDRV_MIDI_SYSEX_GS_MASTER_VOLUME)
snd_opl4_do_for_all(opl4, snd_opl4_update_volume);
}
