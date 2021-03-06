int
snd_emux_init_seq(struct snd_emux *emu, struct snd_card *card, int index)
{
int i;
struct snd_seq_port_callback pinfo;
char tmpname[64];
emu->client = snd_seq_create_kernel_client(card, index,
"%s WaveTable", emu->name);
if (emu->client < 0) {
snd_printk(KERN_ERR "can't create client\n");
return -ENODEV;
}
if (emu->num_ports < 0) {
snd_printk(KERN_WARNING "seqports must be greater than zero\n");
emu->num_ports = 1;
} else if (emu->num_ports >= SNDRV_EMUX_MAX_PORTS) {
snd_printk(KERN_WARNING "too many ports."
"limited max. ports %d\n", SNDRV_EMUX_MAX_PORTS);
emu->num_ports = SNDRV_EMUX_MAX_PORTS;
}
memset(&pinfo, 0, sizeof(pinfo));
pinfo.owner = THIS_MODULE;
pinfo.use = snd_emux_use;
pinfo.unuse = snd_emux_unuse;
pinfo.event_input = snd_emux_event_input;
for (i = 0; i < emu->num_ports; i++) {
struct snd_emux_port *p;
sprintf(tmpname, "%s Port %d", emu->name, i);
p = snd_emux_create_port(emu, tmpname, MIDI_CHANNELS,
0, &pinfo);
if (p == NULL) {
snd_printk(KERN_ERR "can't create port\n");
return -ENOMEM;
}
p->port_mode = SNDRV_EMUX_PORT_MODE_MIDI;
snd_emux_init_port(p);
emu->ports[i] = p->chset.port;
emu->portptrs[i] = p;
}
return 0;
}
void
snd_emux_detach_seq(struct snd_emux *emu)
{
if (emu->voices)
snd_emux_terminate_all(emu);
mutex_lock(&emu->register_mutex);
if (emu->client >= 0) {
snd_seq_delete_kernel_client(emu->client);
emu->client = -1;
}
mutex_unlock(&emu->register_mutex);
}
struct snd_emux_port *
snd_emux_create_port(struct snd_emux *emu, char *name,
int max_channels, int oss_port,
struct snd_seq_port_callback *callback)
{
struct snd_emux_port *p;
int i, type, cap;
if ((p = kzalloc(sizeof(*p), GFP_KERNEL)) == NULL) {
snd_printk(KERN_ERR "no memory\n");
return NULL;
}
p->chset.channels = kcalloc(max_channels, sizeof(struct snd_midi_channel), GFP_KERNEL);
if (p->chset.channels == NULL) {
snd_printk(KERN_ERR "no memory\n");
kfree(p);
return NULL;
}
for (i = 0; i < max_channels; i++)
p->chset.channels[i].number = i;
p->chset.private_data = p;
p->chset.max_channels = max_channels;
p->emu = emu;
p->chset.client = emu->client;
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
snd_emux_create_effect(p);
#endif
callback->private_free = free_port;
callback->private_data = p;
cap = SNDRV_SEQ_PORT_CAP_WRITE;
if (oss_port) {
type = SNDRV_SEQ_PORT_TYPE_SPECIFIC;
} else {
type = DEFAULT_MIDI_TYPE;
cap |= SNDRV_SEQ_PORT_CAP_SUBS_WRITE;
}
p->chset.port = snd_seq_event_port_attach(emu->client, callback,
cap, type, max_channels,
emu->max_voices, name);
return p;
}
static void
free_port(void *private_data)
{
struct snd_emux_port *p;
p = private_data;
if (p) {
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
snd_emux_delete_effect(p);
#endif
kfree(p->chset.channels);
kfree(p);
}
}
static void
snd_emux_init_port(struct snd_emux_port *p)
{
p->drum_flags = DEFAULT_DRUM_FLAGS;
p->volume_atten = 0;
snd_emux_reset_port(p);
}
void
snd_emux_reset_port(struct snd_emux_port *port)
{
int i;
snd_emux_sounds_off_all(port);
snd_midi_channel_set_clear(&port->chset);
#ifdef SNDRV_EMUX_USE_RAW_EFFECT
snd_emux_clear_effect(port);
#endif
port->ctrls[EMUX_MD_DEF_BANK] = 0;
port->ctrls[EMUX_MD_DEF_DRUM] = 0;
port->ctrls[EMUX_MD_REALTIME_PAN] = 1;
for (i = 0; i < port->chset.max_channels; i++) {
struct snd_midi_channel *chan = port->chset.channels + i;
chan->drum_channel = ((port->drum_flags >> i) & 1) ? 1 : 0;
}
}
int
snd_emux_event_input(struct snd_seq_event *ev, int direct, void *private_data,
int atomic, int hop)
{
struct snd_emux_port *port;
port = private_data;
if (snd_BUG_ON(!port || !ev))
return -EINVAL;
snd_midi_process_event(&emux_ops, ev, &port->chset);
return 0;
}
int
snd_emux_inc_count(struct snd_emux *emu)
{
emu->used++;
if (!try_module_get(emu->ops.owner))
goto __error;
if (!try_module_get(emu->card->module)) {
module_put(emu->ops.owner);
__error:
emu->used--;
return 0;
}
return 1;
}
void
snd_emux_dec_count(struct snd_emux *emu)
{
module_put(emu->card->module);
emu->used--;
if (emu->used <= 0)
snd_emux_terminate_all(emu);
module_put(emu->ops.owner);
}
static int
snd_emux_use(void *private_data, struct snd_seq_port_subscribe *info)
{
struct snd_emux_port *p;
struct snd_emux *emu;
p = private_data;
if (snd_BUG_ON(!p))
return -EINVAL;
emu = p->emu;
if (snd_BUG_ON(!emu))
return -EINVAL;
mutex_lock(&emu->register_mutex);
snd_emux_init_port(p);
snd_emux_inc_count(emu);
mutex_unlock(&emu->register_mutex);
return 0;
}
static int
snd_emux_unuse(void *private_data, struct snd_seq_port_subscribe *info)
{
struct snd_emux_port *p;
struct snd_emux *emu;
p = private_data;
if (snd_BUG_ON(!p))
return -EINVAL;
emu = p->emu;
if (snd_BUG_ON(!emu))
return -EINVAL;
mutex_lock(&emu->register_mutex);
snd_emux_sounds_off_all(p);
snd_emux_dec_count(emu);
mutex_unlock(&emu->register_mutex);
return 0;
}
int snd_emux_init_virmidi(struct snd_emux *emu, struct snd_card *card)
{
int i;
emu->vmidi = NULL;
if (emu->midi_ports <= 0)
return 0;
emu->vmidi = kcalloc(emu->midi_ports, sizeof(struct snd_rawmidi *), GFP_KERNEL);
if (emu->vmidi == NULL)
return -ENOMEM;
for (i = 0; i < emu->midi_ports; i++) {
struct snd_rawmidi *rmidi;
struct snd_virmidi_dev *rdev;
if (snd_virmidi_new(card, emu->midi_devidx + i, &rmidi) < 0)
goto __error;
rdev = rmidi->private_data;
sprintf(rmidi->name, "%s Synth MIDI", emu->name);
rdev->seq_mode = SNDRV_VIRMIDI_SEQ_ATTACH;
rdev->client = emu->client;
rdev->port = emu->ports[i];
if (snd_device_register(card, rmidi) < 0) {
snd_device_free(card, rmidi);
goto __error;
}
emu->vmidi[i] = rmidi;
}
return 0;
__error:
snd_emux_delete_virmidi(emu);
return -ENOMEM;
}
int snd_emux_delete_virmidi(struct snd_emux *emu)
{
int i;
if (emu->vmidi == NULL)
return 0;
for (i = 0; i < emu->midi_ports; i++) {
if (emu->vmidi[i])
snd_device_free(emu->card, emu->vmidi[i]);
}
kfree(emu->vmidi);
emu->vmidi = NULL;
return 0;
}
