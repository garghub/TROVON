void __init
snd_seq_oss_synth_init(void)
{
snd_use_lock_init(&midi_synth_dev.use_lock);
}
int
snd_seq_oss_synth_register(struct snd_seq_device *dev)
{
int i;
struct seq_oss_synth *rec;
struct snd_seq_oss_reg *reg = SNDRV_SEQ_DEVICE_ARGPTR(dev);
unsigned long flags;
if ((rec = kzalloc(sizeof(*rec), GFP_KERNEL)) == NULL) {
snd_printk(KERN_ERR "can't malloc synth info\n");
return -ENOMEM;
}
rec->seq_device = -1;
rec->synth_type = reg->type;
rec->synth_subtype = reg->subtype;
rec->nr_voices = reg->nvoices;
rec->oper = reg->oper;
rec->private_data = reg->private_data;
rec->opened = 0;
snd_use_lock_init(&rec->use_lock);
strlcpy(rec->name, dev->name, sizeof(rec->name));
spin_lock_irqsave(&register_lock, flags);
for (i = 0; i < max_synth_devs; i++) {
if (synth_devs[i] == NULL)
break;
}
if (i >= max_synth_devs) {
if (max_synth_devs >= SNDRV_SEQ_OSS_MAX_SYNTH_DEVS) {
spin_unlock_irqrestore(&register_lock, flags);
snd_printk(KERN_ERR "no more synth slot\n");
kfree(rec);
return -ENOMEM;
}
max_synth_devs++;
}
rec->seq_device = i;
synth_devs[i] = rec;
debug_printk(("synth %s registered %d\n", rec->name, i));
spin_unlock_irqrestore(&register_lock, flags);
dev->driver_data = rec;
#ifdef SNDRV_OSS_INFO_DEV_SYNTH
if (i < SNDRV_CARDS)
snd_oss_info_register(SNDRV_OSS_INFO_DEV_SYNTH, i, rec->name);
#endif
return 0;
}
int
snd_seq_oss_synth_unregister(struct snd_seq_device *dev)
{
int index;
struct seq_oss_synth *rec = dev->driver_data;
unsigned long flags;
spin_lock_irqsave(&register_lock, flags);
for (index = 0; index < max_synth_devs; index++) {
if (synth_devs[index] == rec)
break;
}
if (index >= max_synth_devs) {
spin_unlock_irqrestore(&register_lock, flags);
snd_printk(KERN_ERR "can't unregister synth\n");
return -EINVAL;
}
synth_devs[index] = NULL;
if (index == max_synth_devs - 1) {
for (index--; index >= 0; index--) {
if (synth_devs[index])
break;
}
max_synth_devs = index + 1;
}
spin_unlock_irqrestore(&register_lock, flags);
#ifdef SNDRV_OSS_INFO_DEV_SYNTH
if (rec->seq_device < SNDRV_CARDS)
snd_oss_info_unregister(SNDRV_OSS_INFO_DEV_SYNTH, rec->seq_device);
#endif
snd_use_lock_sync(&rec->use_lock);
kfree(rec);
return 0;
}
static struct seq_oss_synth *
get_sdev(int dev)
{
struct seq_oss_synth *rec;
unsigned long flags;
spin_lock_irqsave(&register_lock, flags);
rec = synth_devs[dev];
if (rec)
snd_use_lock_use(&rec->use_lock);
spin_unlock_irqrestore(&register_lock, flags);
return rec;
}
void
snd_seq_oss_synth_setup(struct seq_oss_devinfo *dp)
{
int i;
struct seq_oss_synth *rec;
struct seq_oss_synthinfo *info;
dp->max_synthdev = max_synth_devs;
dp->synth_opened = 0;
memset(dp->synths, 0, sizeof(dp->synths));
for (i = 0; i < dp->max_synthdev; i++) {
rec = get_sdev(i);
if (rec == NULL)
continue;
if (rec->oper.open == NULL || rec->oper.close == NULL) {
snd_use_lock_free(&rec->use_lock);
continue;
}
info = &dp->synths[i];
info->arg.app_index = dp->port;
info->arg.file_mode = dp->file_mode;
info->arg.seq_mode = dp->seq_mode;
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_SYNTH)
info->arg.event_passing = SNDRV_SEQ_OSS_PROCESS_EVENTS;
else
info->arg.event_passing = SNDRV_SEQ_OSS_PASS_EVENTS;
info->opened = 0;
if (!try_module_get(rec->oper.owner)) {
snd_use_lock_free(&rec->use_lock);
continue;
}
if (rec->oper.open(&info->arg, rec->private_data) < 0) {
module_put(rec->oper.owner);
snd_use_lock_free(&rec->use_lock);
continue;
}
info->nr_voices = rec->nr_voices;
if (info->nr_voices > 0) {
info->ch = kcalloc(info->nr_voices, sizeof(struct seq_oss_chinfo), GFP_KERNEL);
if (!info->ch) {
snd_printk(KERN_ERR "Cannot malloc\n");
rec->oper.close(&info->arg);
module_put(rec->oper.owner);
snd_use_lock_free(&rec->use_lock);
continue;
}
reset_channels(info);
}
debug_printk(("synth %d assigned\n", i));
info->opened++;
rec->opened++;
dp->synth_opened++;
snd_use_lock_free(&rec->use_lock);
}
}
void
snd_seq_oss_synth_setup_midi(struct seq_oss_devinfo *dp)
{
int i;
if (dp->max_synthdev >= SNDRV_SEQ_OSS_MAX_SYNTH_DEVS)
return;
for (i = 0; i < dp->max_mididev; i++) {
struct seq_oss_synthinfo *info;
info = &dp->synths[dp->max_synthdev];
if (snd_seq_oss_midi_open(dp, i, dp->file_mode) < 0)
continue;
info->arg.app_index = dp->port;
info->arg.file_mode = dp->file_mode;
info->arg.seq_mode = dp->seq_mode;
info->arg.private_data = info;
info->is_midi = 1;
info->midi_mapped = i;
info->arg.event_passing = SNDRV_SEQ_OSS_PASS_EVENTS;
snd_seq_oss_midi_get_addr(dp, i, &info->arg.addr);
info->opened = 1;
midi_synth_dev.opened++;
dp->max_synthdev++;
if (dp->max_synthdev >= SNDRV_SEQ_OSS_MAX_SYNTH_DEVS)
break;
}
}
void
snd_seq_oss_synth_cleanup(struct seq_oss_devinfo *dp)
{
int i;
struct seq_oss_synth *rec;
struct seq_oss_synthinfo *info;
if (snd_BUG_ON(dp->max_synthdev >= SNDRV_SEQ_OSS_MAX_SYNTH_DEVS))
return;
for (i = 0; i < dp->max_synthdev; i++) {
info = &dp->synths[i];
if (! info->opened)
continue;
if (info->is_midi) {
if (midi_synth_dev.opened > 0) {
snd_seq_oss_midi_close(dp, info->midi_mapped);
midi_synth_dev.opened--;
}
} else {
rec = get_sdev(i);
if (rec == NULL)
continue;
if (rec->opened > 0) {
debug_printk(("synth %d closed\n", i));
rec->oper.close(&info->arg);
module_put(rec->oper.owner);
rec->opened = 0;
}
snd_use_lock_free(&rec->use_lock);
}
kfree(info->sysex);
info->sysex = NULL;
kfree(info->ch);
info->ch = NULL;
}
dp->synth_opened = 0;
dp->max_synthdev = 0;
}
static int
is_midi_dev(struct seq_oss_devinfo *dp, int dev)
{
if (dev < 0 || dev >= dp->max_synthdev)
return 0;
if (dp->synths[dev].is_midi)
return 1;
return 0;
}
static struct seq_oss_synth *
get_synthdev(struct seq_oss_devinfo *dp, int dev)
{
struct seq_oss_synth *rec;
if (dev < 0 || dev >= dp->max_synthdev)
return NULL;
if (! dp->synths[dev].opened)
return NULL;
if (dp->synths[dev].is_midi)
return &midi_synth_dev;
if ((rec = get_sdev(dev)) == NULL)
return NULL;
if (! rec->opened) {
snd_use_lock_free(&rec->use_lock);
return NULL;
}
return rec;
}
static void
reset_channels(struct seq_oss_synthinfo *info)
{
int i;
if (info->ch == NULL || ! info->nr_voices)
return;
for (i = 0; i < info->nr_voices; i++) {
info->ch[i].note = -1;
info->ch[i].vel = 0;
}
}
void
snd_seq_oss_synth_reset(struct seq_oss_devinfo *dp, int dev)
{
struct seq_oss_synth *rec;
struct seq_oss_synthinfo *info;
if (snd_BUG_ON(dev < 0 || dev >= dp->max_synthdev))
return;
info = &dp->synths[dev];
if (! info->opened)
return;
if (info->sysex)
info->sysex->len = 0;
reset_channels(info);
if (info->is_midi) {
if (midi_synth_dev.opened <= 0)
return;
snd_seq_oss_midi_reset(dp, info->midi_mapped);
snd_seq_oss_midi_close(dp, dev);
if (snd_seq_oss_midi_open(dp, info->midi_mapped,
dp->file_mode) < 0) {
midi_synth_dev.opened--;
info->opened = 0;
kfree(info->sysex);
info->sysex = NULL;
kfree(info->ch);
info->ch = NULL;
}
return;
}
rec = get_sdev(dev);
if (rec == NULL)
return;
if (rec->oper.reset) {
rec->oper.reset(&info->arg);
} else {
struct snd_seq_event ev;
memset(&ev, 0, sizeof(ev));
snd_seq_oss_fill_addr(dp, &ev, info->arg.addr.client,
info->arg.addr.port);
ev.type = SNDRV_SEQ_EVENT_RESET;
snd_seq_oss_dispatch(dp, &ev, 0, 0);
}
snd_use_lock_free(&rec->use_lock);
}
int
snd_seq_oss_synth_load_patch(struct seq_oss_devinfo *dp, int dev, int fmt,
const char __user *buf, int p, int c)
{
struct seq_oss_synth *rec;
int rc;
if (dev < 0 || dev >= dp->max_synthdev)
return -ENXIO;
if (is_midi_dev(dp, dev))
return 0;
if ((rec = get_synthdev(dp, dev)) == NULL)
return -ENXIO;
if (rec->oper.load_patch == NULL)
rc = -ENXIO;
else
rc = rec->oper.load_patch(&dp->synths[dev].arg, fmt, buf, p, c);
snd_use_lock_free(&rec->use_lock);
return rc;
}
int
snd_seq_oss_synth_is_valid(struct seq_oss_devinfo *dp, int dev)
{
struct seq_oss_synth *rec;
rec = get_synthdev(dp, dev);
if (rec) {
snd_use_lock_free(&rec->use_lock);
return 1;
}
return 0;
}
int
snd_seq_oss_synth_sysex(struct seq_oss_devinfo *dp, int dev, unsigned char *buf, struct snd_seq_event *ev)
{
int i, send;
unsigned char *dest;
struct seq_oss_synth_sysex *sysex;
if (! snd_seq_oss_synth_is_valid(dp, dev))
return -ENXIO;
sysex = dp->synths[dev].sysex;
if (sysex == NULL) {
sysex = kzalloc(sizeof(*sysex), GFP_KERNEL);
if (sysex == NULL)
return -ENOMEM;
dp->synths[dev].sysex = sysex;
}
send = 0;
dest = sysex->buf + sysex->len;
for (i = 0; i < 6; i++) {
if (buf[i] == 0xff) {
send = 1;
break;
}
dest[i] = buf[i];
sysex->len++;
if (sysex->len >= MAX_SYSEX_BUFLEN) {
sysex->len = 0;
sysex->skip = 1;
break;
}
}
if (sysex->len && send) {
if (sysex->skip) {
sysex->skip = 0;
sysex->len = 0;
return -EINVAL;
}
ev->flags = SNDRV_SEQ_EVENT_LENGTH_VARIABLE;
if (snd_seq_oss_synth_addr(dp, dev, ev))
return -EINVAL;
ev->data.ext.len = sysex->len;
ev->data.ext.ptr = sysex->buf;
sysex->len = 0;
return 0;
}
return -EINVAL;
}
int
snd_seq_oss_synth_addr(struct seq_oss_devinfo *dp, int dev, struct snd_seq_event *ev)
{
if (! snd_seq_oss_synth_is_valid(dp, dev))
return -EINVAL;
snd_seq_oss_fill_addr(dp, ev, dp->synths[dev].arg.addr.client,
dp->synths[dev].arg.addr.port);
return 0;
}
int
snd_seq_oss_synth_ioctl(struct seq_oss_devinfo *dp, int dev, unsigned int cmd, unsigned long addr)
{
struct seq_oss_synth *rec;
int rc;
if (is_midi_dev(dp, dev))
return -ENXIO;
if ((rec = get_synthdev(dp, dev)) == NULL)
return -ENXIO;
if (rec->oper.ioctl == NULL)
rc = -ENXIO;
else
rc = rec->oper.ioctl(&dp->synths[dev].arg, cmd, addr);
snd_use_lock_free(&rec->use_lock);
return rc;
}
int
snd_seq_oss_synth_raw_event(struct seq_oss_devinfo *dp, int dev, unsigned char *data, struct snd_seq_event *ev)
{
if (! snd_seq_oss_synth_is_valid(dp, dev) || is_midi_dev(dp, dev))
return -ENXIO;
ev->type = SNDRV_SEQ_EVENT_OSS;
memcpy(ev->data.raw8.d, data, 8);
return snd_seq_oss_synth_addr(dp, dev, ev);
}
int
snd_seq_oss_synth_make_info(struct seq_oss_devinfo *dp, int dev, struct synth_info *inf)
{
struct seq_oss_synth *rec;
if (dev < 0 || dev >= dp->max_synthdev)
return -ENXIO;
if (dp->synths[dev].is_midi) {
struct midi_info minf;
snd_seq_oss_midi_make_info(dp, dp->synths[dev].midi_mapped, &minf);
inf->synth_type = SYNTH_TYPE_MIDI;
inf->synth_subtype = 0;
inf->nr_voices = 16;
inf->device = dev;
strlcpy(inf->name, minf.name, sizeof(inf->name));
} else {
if ((rec = get_synthdev(dp, dev)) == NULL)
return -ENXIO;
inf->synth_type = rec->synth_type;
inf->synth_subtype = rec->synth_subtype;
inf->nr_voices = rec->nr_voices;
inf->device = dev;
strlcpy(inf->name, rec->name, sizeof(inf->name));
snd_use_lock_free(&rec->use_lock);
}
return 0;
}
void
snd_seq_oss_synth_info_read(struct snd_info_buffer *buf)
{
int i;
struct seq_oss_synth *rec;
snd_iprintf(buf, "\nNumber of synth devices: %d\n", max_synth_devs);
for (i = 0; i < max_synth_devs; i++) {
snd_iprintf(buf, "\nsynth %d: ", i);
rec = get_sdev(i);
if (rec == NULL) {
snd_iprintf(buf, "*empty*\n");
continue;
}
snd_iprintf(buf, "[%s]\n", rec->name);
snd_iprintf(buf, " type 0x%x : subtype 0x%x : voices %d\n",
rec->synth_type, rec->synth_subtype,
rec->nr_voices);
snd_iprintf(buf, " capabilities : ioctl %s / load_patch %s\n",
enabled_str((long)rec->oper.ioctl),
enabled_str((long)rec->oper.load_patch));
snd_use_lock_free(&rec->use_lock);
}
}
