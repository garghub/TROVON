static int send_converted_effect(struct nrpn_conv_table *table, int num_tables,
struct snd_emux_port *port,
struct snd_midi_channel *chan,
int type, int val, int mode)
{
int i, cval;
for (i = 0; i < num_tables; i++) {
if (table[i].control == type) {
cval = table[i].convert(val);
snd_emux_send_effect(port, chan, table[i].effect,
cval, mode);
return 1;
}
}
return 0;
}
static int fx_delay(int val)
{
return (unsigned short)snd_sf_calc_parm_delay(val);
}
static int fx_attack(int val)
{
return (unsigned short)snd_sf_calc_parm_attack(val);
}
static int fx_hold(int val)
{
return (unsigned short)snd_sf_calc_parm_hold(val);
}
static int fx_decay(int val)
{
return (unsigned short)snd_sf_calc_parm_decay(val);
}
static int fx_the_value(int val)
{
return (unsigned short)(val & 0xff);
}
static int fx_twice_value(int val)
{
return (unsigned short)((val * 2) & 0xff);
}
static int fx_conv_pitch(int val)
{
return (short)(val * 4096 / 1200);
}
static int fx_conv_Q(int val)
{
return (unsigned short)((val / 8) & 0xff);
}
static int gs_cutoff(int val)
{
return (val - 64) * gs_sense[FX_CUTOFF] / 50;
}
static int gs_filterQ(int val)
{
return (val - 64) * gs_sense[FX_RESONANCE] / 50;
}
static int gs_attack(int val)
{
return -(val - 64) * gs_sense[FX_ATTACK] / 50;
}
static int gs_decay(int val)
{
return -(val - 64) * gs_sense[FX_RELEASE] / 50;
}
static int gs_release(int val)
{
return -(val - 64) * gs_sense[FX_RELEASE] / 50;
}
static int gs_vib_rate(int val)
{
return (val - 64) * gs_sense[FX_VIBRATE] / 50;
}
static int gs_vib_depth(int val)
{
return (val - 64) * gs_sense[FX_VIBDEPTH] / 50;
}
static int gs_vib_delay(int val)
{
return -(val - 64) * gs_sense[FX_VIBDELAY] / 50;
}
void
snd_emux_nrpn(void *p, struct snd_midi_channel *chan,
struct snd_midi_channel_set *chset)
{
struct snd_emux_port *port;
port = p;
if (snd_BUG_ON(!port || !chan))
return;
if (chan->control[MIDI_CTL_NONREG_PARM_NUM_MSB] == 127 &&
chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB] <= 26) {
int val;
val = (chan->control[MIDI_CTL_MSB_DATA_ENTRY] << 7) |
chan->control[MIDI_CTL_LSB_DATA_ENTRY];
val -= 8192;
send_converted_effect
(awe_effects, ARRAY_SIZE(awe_effects),
port, chan, chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB],
val, EMUX_FX_FLAG_SET);
return;
}
if (port->chset.midi_mode == SNDRV_MIDI_MODE_GS &&
chan->control[MIDI_CTL_NONREG_PARM_NUM_MSB] == 1) {
int val;
val = chan->control[MIDI_CTL_MSB_DATA_ENTRY];
send_converted_effect
(gs_effects, ARRAY_SIZE(gs_effects),
port, chan, chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB],
val, EMUX_FX_FLAG_ADD);
return;
}
}
static int xg_cutoff(int val)
{
return (val - 64) * xg_sense[FX_CUTOFF] / 64;
}
static int xg_filterQ(int val)
{
return (val - 64) * xg_sense[FX_RESONANCE] / 64;
}
static int xg_attack(int val)
{
return -(val - 64) * xg_sense[FX_ATTACK] / 64;
}
static int xg_release(int val)
{
return -(val - 64) * xg_sense[FX_RELEASE] / 64;
}
int
snd_emux_xg_control(struct snd_emux_port *port, struct snd_midi_channel *chan,
int param)
{
return send_converted_effect(xg_effects, ARRAY_SIZE(xg_effects),
port, chan, param,
chan->control[param],
EMUX_FX_FLAG_ADD);
}
void
snd_emux_sysex(void *p, unsigned char *buf, int len, int parsed,
struct snd_midi_channel_set *chset)
{
struct snd_emux_port *port;
struct snd_emux *emu;
port = p;
if (snd_BUG_ON(!port || !chset))
return;
emu = port->emu;
switch (parsed) {
case SNDRV_MIDI_SYSEX_GS_MASTER_VOLUME:
snd_emux_update_port(port, SNDRV_EMUX_UPDATE_VOLUME);
break;
default:
if (emu->ops.sysex)
emu->ops.sysex(emu, buf, len, parsed, chset);
break;
}
}
