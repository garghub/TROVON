static int portman_free(struct portman *pm)
{
kfree(pm);
return 0;
}
static int portman_create(struct snd_card *card,
struct pardevice *pardev,
struct portman **rchip)
{
struct portman *pm;
*rchip = NULL;
pm = kzalloc(sizeof(struct portman), GFP_KERNEL);
if (pm == NULL)
return -ENOMEM;
spin_lock_init(&pm->reg_lock);
pm->card = card;
pm->pardev = pardev;
*rchip = pm;
return 0;
}
static inline void portman_write_command(struct portman *pm, u8 value)
{
parport_write_control(pm->pardev->port, value);
}
static inline u8 portman_read_command(struct portman *pm)
{
return parport_read_control(pm->pardev->port);
}
static inline u8 portman_read_status(struct portman *pm)
{
return parport_read_status(pm->pardev->port);
}
static inline u8 portman_read_data(struct portman *pm)
{
return parport_read_data(pm->pardev->port);
}
static inline void portman_write_data(struct portman *pm, u8 value)
{
parport_write_data(pm->pardev->port, value);
}
static void portman_write_midi(struct portman *pm,
int port, u8 mididata)
{
int command = ((port + 4) << 1);
command |= INT_EN;
do {
portman_write_command(pm, command);
portman_write_data(pm, mididata);
} while ((portman_read_status(pm) & TXEMPTY) != TXEMPTY);
portman_write_command(pm, command | STROBE);
while ((portman_read_status(pm) & ESTB) == 0)
cpu_relax();
portman_write_command(pm, command);
while ((portman_read_status(pm) & ESTB) == ESTB)
cpu_relax();
while ((portman_read_status(pm) & BUSY) == BUSY)
cpu_relax();
}
static int portman_read_midi(struct portman *pm, int port)
{
unsigned char midi_data = 0;
unsigned char cmdout;
portman_write_data(pm, 0);
cmdout = (port << 1) | INT_EN;
portman_write_command(pm, cmdout);
while ((portman_read_status(pm) & ESTB) == ESTB)
cpu_relax();
if ((portman_read_status(pm) & RXAVAIL) == 0)
return -1;
portman_write_command(pm, cmdout | STROBE);
while ((portman_read_status(pm) & ESTB) == 0)
cpu_relax();
midi_data = (portman_read_status(pm) & 128);
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 1) & 64;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 2) & 32;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 3) & 16;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 4) & 8;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 5) & 4;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 6) & 2;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
midi_data |= (portman_read_status(pm) >> 7) & 1;
portman_write_data(pm, 1);
portman_write_data(pm, 0);
portman_write_command(pm, cmdout);
while ((portman_read_status(pm) & ESTB) == ESTB)
cpu_relax();
return (midi_data & 255);
}
static int portman_data_avail(struct portman *pm, int channel)
{
int command = INT_EN;
switch (channel) {
case 0:
command |= RXDATA0;
break;
case 1:
command |= RXDATA1;
break;
}
portman_write_command(pm, command);
if ((portman_read_status(pm) & RXAVAIL) == RXAVAIL)
return 1;
return 0;
}
static void portman_flush_input(struct portman *pm, unsigned char port)
{
unsigned int i = 0;
unsigned char command = 0;
switch (port) {
case 0:
command = RXDATA0;
break;
case 1:
command = RXDATA1;
break;
default:
snd_printk(KERN_WARNING
"portman_flush_input() Won't flush port %i\n",
port);
return;
}
portman_write_command(pm, command);
portman_write_command(pm, command | STROBE);
while ((portman_read_status(pm) & ESTB) == 0)
cpu_relax();
portman_write_data(pm, 0);
for (i = 0; i < 250; i++) {
portman_write_data(pm, 1);
portman_write_data(pm, 0);
}
portman_write_command(pm, command | INT_EN);
while ((portman_read_status(pm) & ESTB) == ESTB)
cpu_relax();
}
static int portman_probe(struct parport *p)
{
parport_write_data(p, 0);
parport_write_control(p, 0);
parport_write_control(p, RXDATA0);
if ((parport_read_status(p) & ESTB) == ESTB)
return 1;
parport_write_control(p, RXDATA0 + STROBE);
if ((parport_read_status(p) & ESTB) != ESTB)
return 1;
parport_write_control(p, 0);
parport_write_control(p, TXDATA0);
if ((parport_read_status(p) & TXEMPTY) == 0)
return 2;
return 0;
}
static int portman_device_init(struct portman *pm)
{
portman_flush_input(pm, 0);
portman_flush_input(pm, 1);
return 0;
}
static int snd_portman_midi_open(struct snd_rawmidi_substream *substream)
{
return 0;
}
static int snd_portman_midi_close(struct snd_rawmidi_substream *substream)
{
return 0;
}
static void snd_portman_midi_input_trigger(struct snd_rawmidi_substream *substream,
int up)
{
struct portman *pm = substream->rmidi->private_data;
unsigned long flags;
spin_lock_irqsave(&pm->reg_lock, flags);
if (up)
pm->mode[substream->number] |= PORTMAN2X4_MODE_INPUT_TRIGGERED;
else
pm->mode[substream->number] &= ~PORTMAN2X4_MODE_INPUT_TRIGGERED;
spin_unlock_irqrestore(&pm->reg_lock, flags);
}
static void snd_portman_midi_output_trigger(struct snd_rawmidi_substream *substream,
int up)
{
struct portman *pm = substream->rmidi->private_data;
unsigned long flags;
unsigned char byte;
spin_lock_irqsave(&pm->reg_lock, flags);
if (up) {
while ((snd_rawmidi_transmit(substream, &byte, 1) == 1))
portman_write_midi(pm, substream->number, byte);
}
spin_unlock_irqrestore(&pm->reg_lock, flags);
}
static int snd_portman_rawmidi_create(struct snd_card *card)
{
struct portman *pm = card->private_data;
struct snd_rawmidi *rmidi;
struct snd_rawmidi_substream *substream;
int err;
err = snd_rawmidi_new(card, CARD_NAME, 0,
PORTMAN_NUM_OUTPUT_PORTS,
PORTMAN_NUM_INPUT_PORTS,
&rmidi);
if (err < 0)
return err;
rmidi->private_data = pm;
strcpy(rmidi->name, CARD_NAME);
rmidi->info_flags = SNDRV_RAWMIDI_INFO_OUTPUT |
SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
pm->rmidi = rmidi;
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT,
&snd_portman_midi_output);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT,
&snd_portman_midi_input);
list_for_each_entry(substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams,
list) {
sprintf(substream->name,
"Portman2x4 %d", substream->number+1);
}
list_for_each_entry(substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams,
list) {
pm->midi_input[substream->number] = substream;
sprintf(substream->name,
"Portman2x4 %d", substream->number+1);
}
return err;
}
static void snd_portman_interrupt(void *userdata)
{
unsigned char midivalue = 0;
struct portman *pm = ((struct snd_card*)userdata)->private_data;
spin_lock(&pm->reg_lock);
while ((portman_read_status(pm) & INT_REQ) == INT_REQ) {
if (portman_data_avail(pm, 0)) {
midivalue = portman_read_midi(pm, 0);
if (pm->mode[0] & PORTMAN2X4_MODE_INPUT_TRIGGERED)
snd_rawmidi_receive(pm->midi_input[0],
&midivalue, 1);
}
if (portman_data_avail(pm, 1)) {
midivalue = portman_read_midi(pm, 1);
if (pm->mode[1] & PORTMAN2X4_MODE_INPUT_TRIGGERED)
snd_rawmidi_receive(pm->midi_input[1],
&midivalue, 1);
}
}
spin_unlock(&pm->reg_lock);
}
static int snd_portman_probe_port(struct parport *p)
{
struct pardevice *pardev;
int res;
pardev = parport_register_device(p, DRIVER_NAME,
NULL, NULL, NULL,
0, NULL);
if (!pardev)
return -EIO;
if (parport_claim(pardev)) {
parport_unregister_device(pardev);
return -EIO;
}
res = portman_probe(p);
parport_release(pardev);
parport_unregister_device(pardev);
return res ? -EIO : 0;
}
static void snd_portman_attach(struct parport *p)
{
struct platform_device *device;
device = platform_device_alloc(PLATFORM_DRIVER, device_count);
if (!device)
return;
platform_set_drvdata(device, p);
if (platform_device_add(device) < 0) {
platform_device_put(device);
return;
}
if (!platform_get_drvdata(device)) {
platform_device_unregister(device);
return;
}
platform_devices[device_count] = device;
device_count++;
}
static void snd_portman_detach(struct parport *p)
{
}
static void snd_portman_card_private_free(struct snd_card *card)
{
struct portman *pm = card->private_data;
struct pardevice *pardev = pm->pardev;
if (pardev) {
if (pm->pardev_claimed)
parport_release(pardev);
parport_unregister_device(pardev);
}
portman_free(pm);
}
static int snd_portman_probe(struct platform_device *pdev)
{
struct pardevice *pardev;
struct parport *p;
int dev = pdev->id;
struct snd_card *card = NULL;
struct portman *pm = NULL;
int err;
p = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev])
return -ENOENT;
if ((err = snd_portman_probe_port(p)) < 0)
return err;
err = snd_card_new(&pdev->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0) {
snd_printd("Cannot create card\n");
return err;
}
strcpy(card->driver, DRIVER_NAME);
strcpy(card->shortname, CARD_NAME);
sprintf(card->longname, "%s at 0x%lx, irq %i",
card->shortname, p->base, p->irq);
pardev = parport_register_device(p,
DRIVER_NAME,
NULL,
NULL,
snd_portman_interrupt,
PARPORT_DEV_EXCL,
(void *)card);
if (pardev == NULL) {
snd_printd("Cannot register pardevice\n");
err = -EIO;
goto __err;
}
if ((err = portman_create(card, pardev, &pm)) < 0) {
snd_printd("Cannot create main component\n");
parport_unregister_device(pardev);
goto __err;
}
card->private_data = pm;
card->private_free = snd_portman_card_private_free;
if ((err = snd_portman_rawmidi_create(card)) < 0) {
snd_printd("Creating Rawmidi component failed\n");
goto __err;
}
if (parport_claim(pardev)) {
snd_printd("Cannot claim parport 0x%lx\n", pardev->port->base);
err = -EIO;
goto __err;
}
pm->pardev_claimed = 1;
if ((err = portman_device_init(pm)) < 0)
goto __err;
platform_set_drvdata(pdev, card);
if ((err = snd_card_register(card)) < 0) {
snd_printd("Cannot register card\n");
goto __err;
}
snd_printk(KERN_INFO "Portman 2x4 on 0x%lx\n", p->base);
return 0;
__err:
snd_card_free(card);
return err;
}
static int snd_portman_remove(struct platform_device *pdev)
{
struct snd_card *card = platform_get_drvdata(pdev);
if (card)
snd_card_free(card);
return 0;
}
static void snd_portman_unregister_all(void)
{
int i;
for (i = 0; i < SNDRV_CARDS; ++i) {
if (platform_devices[i]) {
platform_device_unregister(platform_devices[i]);
platform_devices[i] = NULL;
}
}
platform_driver_unregister(&snd_portman_driver);
parport_unregister_driver(&portman_parport_driver);
}
static int __init snd_portman_module_init(void)
{
int err;
if ((err = platform_driver_register(&snd_portman_driver)) < 0)
return err;
if (parport_register_driver(&portman_parport_driver) != 0) {
platform_driver_unregister(&snd_portman_driver);
return -EIO;
}
if (device_count == 0) {
snd_portman_unregister_all();
return -ENODEV;
}
return 0;
}
static void __exit snd_portman_module_exit(void)
{
snd_portman_unregister_all();
}
