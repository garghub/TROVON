int __init
snd_seq_oss_midi_lookup_ports(int client)
{
struct snd_seq_client_info *clinfo;
struct snd_seq_port_info *pinfo;
clinfo = kzalloc(sizeof(*clinfo), GFP_KERNEL);
pinfo = kzalloc(sizeof(*pinfo), GFP_KERNEL);
if (! clinfo || ! pinfo) {
kfree(clinfo);
kfree(pinfo);
return -ENOMEM;
}
clinfo->client = -1;
while (snd_seq_kernel_client_ctl(client, SNDRV_SEQ_IOCTL_QUERY_NEXT_CLIENT, clinfo) == 0) {
if (clinfo->client == client)
continue;
pinfo->addr.client = clinfo->client;
pinfo->addr.port = -1;
while (snd_seq_kernel_client_ctl(client, SNDRV_SEQ_IOCTL_QUERY_NEXT_PORT, pinfo) == 0)
snd_seq_oss_midi_check_new_port(pinfo);
}
kfree(clinfo);
kfree(pinfo);
return 0;
}
static struct seq_oss_midi *
get_mdev(int dev)
{
struct seq_oss_midi *mdev;
unsigned long flags;
spin_lock_irqsave(&register_lock, flags);
mdev = midi_devs[dev];
if (mdev)
snd_use_lock_use(&mdev->use_lock);
spin_unlock_irqrestore(&register_lock, flags);
return mdev;
}
static struct seq_oss_midi *
find_slot(int client, int port)
{
int i;
struct seq_oss_midi *mdev;
unsigned long flags;
spin_lock_irqsave(&register_lock, flags);
for (i = 0; i < max_midi_devs; i++) {
mdev = midi_devs[i];
if (mdev && mdev->client == client && mdev->port == port) {
snd_use_lock_use(&mdev->use_lock);
spin_unlock_irqrestore(&register_lock, flags);
return mdev;
}
}
spin_unlock_irqrestore(&register_lock, flags);
return NULL;
}
int
snd_seq_oss_midi_check_new_port(struct snd_seq_port_info *pinfo)
{
int i;
struct seq_oss_midi *mdev;
unsigned long flags;
debug_printk(("check for MIDI client %d port %d\n", pinfo->addr.client, pinfo->addr.port));
if (! (pinfo->type & SNDRV_SEQ_PORT_TYPE_MIDI_GENERIC))
return 0;
if ((pinfo->capability & PERM_WRITE) != PERM_WRITE &&
(pinfo->capability & PERM_READ) != PERM_READ)
return 0;
if ((mdev = find_slot(pinfo->addr.client, pinfo->addr.port)) != NULL) {
snd_use_lock_free(&mdev->use_lock);
return 0;
}
if ((mdev = kzalloc(sizeof(*mdev), GFP_KERNEL)) == NULL) {
snd_printk(KERN_ERR "can't malloc midi info\n");
return -ENOMEM;
}
mdev->client = pinfo->addr.client;
mdev->port = pinfo->addr.port;
mdev->flags = pinfo->capability;
mdev->opened = 0;
snd_use_lock_init(&mdev->use_lock);
strlcpy(mdev->name, pinfo->name, sizeof(mdev->name));
if (snd_midi_event_new(MAX_MIDI_EVENT_BUF, &mdev->coder) < 0) {
snd_printk(KERN_ERR "can't malloc midi coder\n");
kfree(mdev);
return -ENOMEM;
}
snd_midi_event_no_status(mdev->coder, 1);
spin_lock_irqsave(&register_lock, flags);
for (i = 0; i < max_midi_devs; i++) {
if (midi_devs[i] == NULL)
break;
}
if (i >= max_midi_devs) {
if (max_midi_devs >= SNDRV_SEQ_OSS_MAX_MIDI_DEVS) {
spin_unlock_irqrestore(&register_lock, flags);
snd_midi_event_free(mdev->coder);
kfree(mdev);
return -ENOMEM;
}
max_midi_devs++;
}
mdev->seq_device = i;
midi_devs[mdev->seq_device] = mdev;
spin_unlock_irqrestore(&register_lock, flags);
return 0;
}
int
snd_seq_oss_midi_check_exit_port(int client, int port)
{
struct seq_oss_midi *mdev;
unsigned long flags;
int index;
if ((mdev = find_slot(client, port)) != NULL) {
spin_lock_irqsave(&register_lock, flags);
midi_devs[mdev->seq_device] = NULL;
spin_unlock_irqrestore(&register_lock, flags);
snd_use_lock_free(&mdev->use_lock);
snd_use_lock_sync(&mdev->use_lock);
if (mdev->coder)
snd_midi_event_free(mdev->coder);
kfree(mdev);
}
spin_lock_irqsave(&register_lock, flags);
for (index = max_midi_devs - 1; index >= 0; index--) {
if (midi_devs[index])
break;
}
max_midi_devs = index + 1;
spin_unlock_irqrestore(&register_lock, flags);
return 0;
}
void
snd_seq_oss_midi_clear_all(void)
{
int i;
struct seq_oss_midi *mdev;
unsigned long flags;
spin_lock_irqsave(&register_lock, flags);
for (i = 0; i < max_midi_devs; i++) {
if ((mdev = midi_devs[i]) != NULL) {
if (mdev->coder)
snd_midi_event_free(mdev->coder);
kfree(mdev);
midi_devs[i] = NULL;
}
}
max_midi_devs = 0;
spin_unlock_irqrestore(&register_lock, flags);
}
void
snd_seq_oss_midi_setup(struct seq_oss_devinfo *dp)
{
dp->max_mididev = max_midi_devs;
}
void
snd_seq_oss_midi_cleanup(struct seq_oss_devinfo *dp)
{
int i;
for (i = 0; i < dp->max_mididev; i++)
snd_seq_oss_midi_close(dp, i);
dp->max_mididev = 0;
}
void
snd_seq_oss_midi_open_all(struct seq_oss_devinfo *dp, int file_mode)
{
int i;
for (i = 0; i < dp->max_mididev; i++)
snd_seq_oss_midi_open(dp, i, file_mode);
}
static struct seq_oss_midi *
get_mididev(struct seq_oss_devinfo *dp, int dev)
{
if (dev < 0 || dev >= dp->max_mididev)
return NULL;
return get_mdev(dev);
}
int
snd_seq_oss_midi_open(struct seq_oss_devinfo *dp, int dev, int fmode)
{
int perm;
struct seq_oss_midi *mdev;
struct snd_seq_port_subscribe subs;
if ((mdev = get_mididev(dp, dev)) == NULL)
return -ENODEV;
if (mdev->opened && mdev->devinfo != dp) {
snd_use_lock_free(&mdev->use_lock);
return -EBUSY;
}
perm = 0;
if (is_write_mode(fmode))
perm |= PERM_WRITE;
if (is_read_mode(fmode))
perm |= PERM_READ;
perm &= mdev->flags;
if (perm == 0) {
snd_use_lock_free(&mdev->use_lock);
return -ENXIO;
}
if ((mdev->opened & perm) == perm) {
snd_use_lock_free(&mdev->use_lock);
return 0;
}
perm &= ~mdev->opened;
memset(&subs, 0, sizeof(subs));
if (perm & PERM_WRITE) {
subs.sender = dp->addr;
subs.dest.client = mdev->client;
subs.dest.port = mdev->port;
if (snd_seq_kernel_client_ctl(dp->cseq, SNDRV_SEQ_IOCTL_SUBSCRIBE_PORT, &subs) >= 0)
mdev->opened |= PERM_WRITE;
}
if (perm & PERM_READ) {
subs.sender.client = mdev->client;
subs.sender.port = mdev->port;
subs.dest = dp->addr;
subs.flags = SNDRV_SEQ_PORT_SUBS_TIMESTAMP;
subs.queue = dp->queue;
if (snd_seq_kernel_client_ctl(dp->cseq, SNDRV_SEQ_IOCTL_SUBSCRIBE_PORT, &subs) >= 0)
mdev->opened |= PERM_READ;
}
if (! mdev->opened) {
snd_use_lock_free(&mdev->use_lock);
return -ENXIO;
}
mdev->devinfo = dp;
snd_use_lock_free(&mdev->use_lock);
return 0;
}
int
snd_seq_oss_midi_close(struct seq_oss_devinfo *dp, int dev)
{
struct seq_oss_midi *mdev;
struct snd_seq_port_subscribe subs;
if ((mdev = get_mididev(dp, dev)) == NULL)
return -ENODEV;
if (! mdev->opened || mdev->devinfo != dp) {
snd_use_lock_free(&mdev->use_lock);
return 0;
}
debug_printk(("closing client %d port %d mode %d\n", mdev->client, mdev->port, mdev->opened));
memset(&subs, 0, sizeof(subs));
if (mdev->opened & PERM_WRITE) {
subs.sender = dp->addr;
subs.dest.client = mdev->client;
subs.dest.port = mdev->port;
snd_seq_kernel_client_ctl(dp->cseq, SNDRV_SEQ_IOCTL_UNSUBSCRIBE_PORT, &subs);
}
if (mdev->opened & PERM_READ) {
subs.sender.client = mdev->client;
subs.sender.port = mdev->port;
subs.dest = dp->addr;
snd_seq_kernel_client_ctl(dp->cseq, SNDRV_SEQ_IOCTL_UNSUBSCRIBE_PORT, &subs);
}
mdev->opened = 0;
mdev->devinfo = NULL;
snd_use_lock_free(&mdev->use_lock);
return 0;
}
int
snd_seq_oss_midi_filemode(struct seq_oss_devinfo *dp, int dev)
{
struct seq_oss_midi *mdev;
int mode;
if ((mdev = get_mididev(dp, dev)) == NULL)
return 0;
mode = 0;
if (mdev->opened & PERM_WRITE)
mode |= SNDRV_SEQ_OSS_FILE_WRITE;
if (mdev->opened & PERM_READ)
mode |= SNDRV_SEQ_OSS_FILE_READ;
snd_use_lock_free(&mdev->use_lock);
return mode;
}
void
snd_seq_oss_midi_reset(struct seq_oss_devinfo *dp, int dev)
{
struct seq_oss_midi *mdev;
if ((mdev = get_mididev(dp, dev)) == NULL)
return;
if (! mdev->opened) {
snd_use_lock_free(&mdev->use_lock);
return;
}
if (mdev->opened & PERM_WRITE) {
struct snd_seq_event ev;
int c;
debug_printk(("resetting client %d port %d\n", mdev->client, mdev->port));
memset(&ev, 0, sizeof(ev));
ev.dest.client = mdev->client;
ev.dest.port = mdev->port;
ev.queue = dp->queue;
ev.source.port = dp->port;
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_SYNTH) {
ev.type = SNDRV_SEQ_EVENT_SENSING;
snd_seq_oss_dispatch(dp, &ev, 0, 0);
}
for (c = 0; c < 16; c++) {
ev.type = SNDRV_SEQ_EVENT_CONTROLLER;
ev.data.control.channel = c;
ev.data.control.param = MIDI_CTL_ALL_NOTES_OFF;
snd_seq_oss_dispatch(dp, &ev, 0, 0);
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC) {
ev.data.control.param =
MIDI_CTL_RESET_CONTROLLERS;
snd_seq_oss_dispatch(dp, &ev, 0, 0);
ev.type = SNDRV_SEQ_EVENT_PITCHBEND;
ev.data.control.value = 0;
snd_seq_oss_dispatch(dp, &ev, 0, 0);
}
}
}
snd_use_lock_free(&mdev->use_lock);
}
void
snd_seq_oss_midi_get_addr(struct seq_oss_devinfo *dp, int dev, struct snd_seq_addr *addr)
{
struct seq_oss_midi *mdev;
if ((mdev = get_mididev(dp, dev)) == NULL)
return;
addr->client = mdev->client;
addr->port = mdev->port;
snd_use_lock_free(&mdev->use_lock);
}
int
snd_seq_oss_midi_input(struct snd_seq_event *ev, int direct, void *private_data)
{
struct seq_oss_devinfo *dp = (struct seq_oss_devinfo *)private_data;
struct seq_oss_midi *mdev;
int rc;
if (dp->readq == NULL)
return 0;
if ((mdev = find_slot(ev->source.client, ev->source.port)) == NULL)
return 0;
if (! (mdev->opened & PERM_READ)) {
snd_use_lock_free(&mdev->use_lock);
return 0;
}
if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
rc = send_synth_event(dp, ev, mdev->seq_device);
else
rc = send_midi_event(dp, ev, mdev);
snd_use_lock_free(&mdev->use_lock);
return rc;
}
static int
send_synth_event(struct seq_oss_devinfo *dp, struct snd_seq_event *ev, int dev)
{
union evrec ossev;
memset(&ossev, 0, sizeof(ossev));
switch (ev->type) {
case SNDRV_SEQ_EVENT_NOTEON:
ossev.v.cmd = MIDI_NOTEON; break;
case SNDRV_SEQ_EVENT_NOTEOFF:
ossev.v.cmd = MIDI_NOTEOFF; break;
case SNDRV_SEQ_EVENT_KEYPRESS:
ossev.v.cmd = MIDI_KEY_PRESSURE; break;
case SNDRV_SEQ_EVENT_CONTROLLER:
ossev.l.cmd = MIDI_CTL_CHANGE; break;
case SNDRV_SEQ_EVENT_PGMCHANGE:
ossev.l.cmd = MIDI_PGM_CHANGE; break;
case SNDRV_SEQ_EVENT_CHANPRESS:
ossev.l.cmd = MIDI_CHN_PRESSURE; break;
case SNDRV_SEQ_EVENT_PITCHBEND:
ossev.l.cmd = MIDI_PITCH_BEND; break;
default:
return 0;
}
ossev.v.dev = dev;
switch (ev->type) {
case SNDRV_SEQ_EVENT_NOTEON:
case SNDRV_SEQ_EVENT_NOTEOFF:
case SNDRV_SEQ_EVENT_KEYPRESS:
ossev.v.code = EV_CHN_VOICE;
ossev.v.note = ev->data.note.note;
ossev.v.parm = ev->data.note.velocity;
ossev.v.chn = ev->data.note.channel;
break;
case SNDRV_SEQ_EVENT_CONTROLLER:
case SNDRV_SEQ_EVENT_PGMCHANGE:
case SNDRV_SEQ_EVENT_CHANPRESS:
ossev.l.code = EV_CHN_COMMON;
ossev.l.p1 = ev->data.control.param;
ossev.l.val = ev->data.control.value;
ossev.l.chn = ev->data.control.channel;
break;
case SNDRV_SEQ_EVENT_PITCHBEND:
ossev.l.code = EV_CHN_COMMON;
ossev.l.val = ev->data.control.value + 8192;
ossev.l.chn = ev->data.control.channel;
break;
}
snd_seq_oss_readq_put_timestamp(dp->readq, ev->time.tick, dp->seq_mode);
snd_seq_oss_readq_put_event(dp->readq, &ossev);
return 0;
}
static int
send_midi_event(struct seq_oss_devinfo *dp, struct snd_seq_event *ev, struct seq_oss_midi *mdev)
{
char msg[32];
int len;
snd_seq_oss_readq_put_timestamp(dp->readq, ev->time.tick, dp->seq_mode);
if (!dp->timer->running)
len = snd_seq_oss_timer_start(dp->timer);
if (ev->type == SNDRV_SEQ_EVENT_SYSEX) {
if ((ev->flags & SNDRV_SEQ_EVENT_LENGTH_MASK) == SNDRV_SEQ_EVENT_LENGTH_VARIABLE)
snd_seq_oss_readq_puts(dp->readq, mdev->seq_device,
ev->data.ext.ptr, ev->data.ext.len);
} else {
len = snd_midi_event_decode(mdev->coder, msg, sizeof(msg), ev);
if (len > 0)
snd_seq_oss_readq_puts(dp->readq, mdev->seq_device, msg, len);
}
return 0;
}
int
snd_seq_oss_midi_putc(struct seq_oss_devinfo *dp, int dev, unsigned char c, struct snd_seq_event *ev)
{
struct seq_oss_midi *mdev;
if ((mdev = get_mididev(dp, dev)) == NULL)
return -ENODEV;
if (snd_midi_event_encode_byte(mdev->coder, c, ev) > 0) {
snd_seq_oss_fill_addr(dp, ev, mdev->client, mdev->port);
snd_use_lock_free(&mdev->use_lock);
return 0;
}
snd_use_lock_free(&mdev->use_lock);
return -EINVAL;
}
int
snd_seq_oss_midi_make_info(struct seq_oss_devinfo *dp, int dev, struct midi_info *inf)
{
struct seq_oss_midi *mdev;
if ((mdev = get_mididev(dp, dev)) == NULL)
return -ENXIO;
inf->device = dev;
inf->dev_type = 0;
inf->capabilities = 0;
strlcpy(inf->name, mdev->name, sizeof(inf->name));
snd_use_lock_free(&mdev->use_lock);
return 0;
}
static char *
capmode_str(int val)
{
val &= PERM_READ|PERM_WRITE;
if (val == (PERM_READ|PERM_WRITE))
return "read/write";
else if (val == PERM_READ)
return "read";
else if (val == PERM_WRITE)
return "write";
else
return "none";
}
void
snd_seq_oss_midi_info_read(struct snd_info_buffer *buf)
{
int i;
struct seq_oss_midi *mdev;
snd_iprintf(buf, "\nNumber of MIDI devices: %d\n", max_midi_devs);
for (i = 0; i < max_midi_devs; i++) {
snd_iprintf(buf, "\nmidi %d: ", i);
mdev = get_mdev(i);
if (mdev == NULL) {
snd_iprintf(buf, "*empty*\n");
continue;
}
snd_iprintf(buf, "[%s] ALSA port %d:%d\n", mdev->name,
mdev->client, mdev->port);
snd_iprintf(buf, " capability %s / opened %s\n",
capmode_str(mdev->flags),
capmode_str(mdev->opened));
snd_use_lock_free(&mdev->use_lock);
}
}
