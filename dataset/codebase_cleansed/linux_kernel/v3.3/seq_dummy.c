static int
dummy_unuse(void *private_data, struct snd_seq_port_subscribe *info)
{
struct snd_seq_dummy_port *p;
int i;
struct snd_seq_event ev;
p = private_data;
memset(&ev, 0, sizeof(ev));
if (p->duplex)
ev.source.port = p->connect;
else
ev.source.port = p->port;
ev.dest.client = SNDRV_SEQ_ADDRESS_SUBSCRIBERS;
ev.type = SNDRV_SEQ_EVENT_CONTROLLER;
for (i = 0; i < 16; i++) {
ev.data.control.channel = i;
ev.data.control.param = MIDI_CTL_ALL_SOUNDS_OFF;
snd_seq_kernel_client_dispatch(p->client, &ev, 0, 0);
ev.data.control.param = MIDI_CTL_RESET_CONTROLLERS;
snd_seq_kernel_client_dispatch(p->client, &ev, 0, 0);
}
return 0;
}
static int
dummy_input(struct snd_seq_event *ev, int direct, void *private_data,
int atomic, int hop)
{
struct snd_seq_dummy_port *p;
struct snd_seq_event tmpev;
p = private_data;
if (ev->source.client == SNDRV_SEQ_CLIENT_SYSTEM ||
ev->type == SNDRV_SEQ_EVENT_KERNEL_ERROR)
return 0;
tmpev = *ev;
if (p->duplex)
tmpev.source.port = p->connect;
else
tmpev.source.port = p->port;
tmpev.dest.client = SNDRV_SEQ_ADDRESS_SUBSCRIBERS;
return snd_seq_kernel_client_dispatch(p->client, &tmpev, atomic, hop);
}
static void
dummy_free(void *private_data)
{
kfree(private_data);
}
static struct snd_seq_dummy_port __init *
create_port(int idx, int type)
{
struct snd_seq_port_info pinfo;
struct snd_seq_port_callback pcb;
struct snd_seq_dummy_port *rec;
if ((rec = kzalloc(sizeof(*rec), GFP_KERNEL)) == NULL)
return NULL;
rec->client = my_client;
rec->duplex = duplex;
rec->connect = 0;
memset(&pinfo, 0, sizeof(pinfo));
pinfo.addr.client = my_client;
if (duplex)
sprintf(pinfo.name, "Midi Through Port-%d:%c", idx,
(type ? 'B' : 'A'));
else
sprintf(pinfo.name, "Midi Through Port-%d", idx);
pinfo.capability = SNDRV_SEQ_PORT_CAP_READ | SNDRV_SEQ_PORT_CAP_SUBS_READ;
pinfo.capability |= SNDRV_SEQ_PORT_CAP_WRITE | SNDRV_SEQ_PORT_CAP_SUBS_WRITE;
if (duplex)
pinfo.capability |= SNDRV_SEQ_PORT_CAP_DUPLEX;
pinfo.type = SNDRV_SEQ_PORT_TYPE_MIDI_GENERIC
| SNDRV_SEQ_PORT_TYPE_SOFTWARE
| SNDRV_SEQ_PORT_TYPE_PORT;
memset(&pcb, 0, sizeof(pcb));
pcb.owner = THIS_MODULE;
pcb.unuse = dummy_unuse;
pcb.event_input = dummy_input;
pcb.private_free = dummy_free;
pcb.private_data = rec;
pinfo.kernel = &pcb;
if (snd_seq_kernel_client_ctl(my_client, SNDRV_SEQ_IOCTL_CREATE_PORT, &pinfo) < 0) {
kfree(rec);
return NULL;
}
rec->port = pinfo.addr.port;
return rec;
}
static int __init
register_client(void)
{
struct snd_seq_dummy_port *rec1, *rec2;
int i;
if (ports < 1) {
snd_printk(KERN_ERR "invalid number of ports %d\n", ports);
return -EINVAL;
}
my_client = snd_seq_create_kernel_client(NULL, SNDRV_SEQ_CLIENT_DUMMY,
"Midi Through");
if (my_client < 0)
return my_client;
for (i = 0; i < ports; i++) {
rec1 = create_port(i, 0);
if (rec1 == NULL) {
snd_seq_delete_kernel_client(my_client);
return -ENOMEM;
}
if (duplex) {
rec2 = create_port(i, 1);
if (rec2 == NULL) {
snd_seq_delete_kernel_client(my_client);
return -ENOMEM;
}
rec1->connect = rec2->port;
rec2->connect = rec1->port;
}
}
return 0;
}
static void __exit
delete_client(void)
{
if (my_client >= 0)
snd_seq_delete_kernel_client(my_client);
}
static int __init alsa_seq_dummy_init(void)
{
int err;
snd_seq_autoload_lock();
err = register_client();
snd_seq_autoload_unlock();
return err;
}
static void __exit alsa_seq_dummy_exit(void)
{
delete_client();
}
