static int translate_subdevice_to_hwport(struct mtpav *chip, int subdev)
{
if (subdev < 0)
return 0x01;
else if (subdev < chip->num_ports)
return subdev + 1;
else if (subdev < chip->num_ports * 2)
return subdev - chip->num_ports + 0x09;
else if (subdev == chip->num_ports * 2 + MTPAV_PIDX_COMPUTER)
return 0x11;
else if (subdev == chip->num_ports + MTPAV_PIDX_ADAT)
return 0x63;
return 0;
}
static int translate_hwport_to_subdevice(struct mtpav *chip, int hwport)
{
int p;
if (hwport <= 0x00)
return chip->num_ports + MTPAV_PIDX_BROADCAST;
else if (hwport <= 0x08) {
p = hwport - 1;
if (p >= chip->num_ports)
p = 0;
return p;
} else if (hwport <= 0x10) {
p = hwport - 0x09 + chip->num_ports;
if (p >= chip->num_ports * 2)
p = chip->num_ports;
return p;
} else if (hwport == 0x11)
return chip->num_ports + MTPAV_PIDX_COMPUTER;
else
return chip->num_ports + MTPAV_PIDX_ADAT;
}
static u8 snd_mtpav_getreg(struct mtpav *chip, u16 reg)
{
u8 rval = 0;
if (reg == SREG) {
rval = inb(chip->port + SREG);
rval = (rval & 0xf8);
} else if (reg == CREG) {
rval = inb(chip->port + CREG);
rval = (rval & 0x1c);
}
return rval;
}
static inline void snd_mtpav_mputreg(struct mtpav *chip, u16 reg, u8 val)
{
if (reg == DREG || reg == CREG)
outb(val, chip->port + reg);
}
static void snd_mtpav_wait_rfdhi(struct mtpav *chip)
{
int counts = 10000;
u8 sbyte;
sbyte = snd_mtpav_getreg(chip, SREG);
while (!(sbyte & SIGS_RFD) && counts--) {
sbyte = snd_mtpav_getreg(chip, SREG);
udelay(10);
}
}
static void snd_mtpav_send_byte(struct mtpav *chip, u8 byte)
{
u8 tcbyt;
u8 clrwrite;
u8 setwrite;
snd_mtpav_wait_rfdhi(chip);
tcbyt = snd_mtpav_getreg(chip, CREG);
clrwrite = tcbyt & (SIGC_WRITE ^ 0xff);
setwrite = tcbyt | SIGC_WRITE;
snd_mtpav_mputreg(chip, DREG, byte);
snd_mtpav_mputreg(chip, CREG, clrwrite);
snd_mtpav_mputreg(chip, CREG, setwrite);
}
static void snd_mtpav_output_port_write(struct mtpav *mtp_card,
struct mtpav_port *portp,
struct snd_rawmidi_substream *substream)
{
u8 outbyte;
if (snd_rawmidi_transmit(substream, &outbyte, 1) != 1)
return;
if (portp->hwport != mtp_card->outmidihwport) {
mtp_card->outmidihwport = portp->hwport;
snd_mtpav_send_byte(mtp_card, 0xf5);
snd_mtpav_send_byte(mtp_card, portp->hwport);
if (!(outbyte & 0x80) && portp->running_status)
snd_mtpav_send_byte(mtp_card, portp->running_status);
}
do {
if (outbyte & 0x80)
portp->running_status = outbyte;
snd_mtpav_send_byte(mtp_card, outbyte);
} while (snd_rawmidi_transmit(substream, &outbyte, 1) == 1);
}
static void snd_mtpav_output_write(struct snd_rawmidi_substream *substream)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
snd_mtpav_output_port_write(mtp_card, portp, substream);
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
}
static void snd_mtpav_portscan(struct mtpav *chip)
{
u8 p;
for (p = 0; p < 8; p++) {
snd_mtpav_send_byte(chip, 0xf5);
snd_mtpav_send_byte(chip, p);
snd_mtpav_send_byte(chip, 0xfe);
}
}
static int snd_mtpav_input_open(struct snd_rawmidi_substream *substream)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
portp->mode |= MTPAV_MODE_INPUT_OPENED;
portp->input = substream;
if (mtp_card->share_irq++ == 0)
snd_mtpav_mputreg(mtp_card, CREG, (SIGC_INTEN | SIGC_WRITE));
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
return 0;
}
static int snd_mtpav_input_close(struct snd_rawmidi_substream *substream)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
portp->mode &= ~MTPAV_MODE_INPUT_OPENED;
portp->input = NULL;
if (--mtp_card->share_irq == 0)
snd_mtpav_mputreg(mtp_card, CREG, 0);
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
return 0;
}
static void snd_mtpav_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
if (up)
portp->mode |= MTPAV_MODE_INPUT_TRIGGERED;
else
portp->mode &= ~MTPAV_MODE_INPUT_TRIGGERED;
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
}
static void snd_mtpav_output_timer(unsigned long data)
{
unsigned long flags;
struct mtpav *chip = (struct mtpav *)data;
int p;
spin_lock_irqsave(&chip->spinlock, flags);
chip->timer.expires = 1 + jiffies;
add_timer(&chip->timer);
for (p = 0; p <= chip->num_ports * 2 + MTPAV_PIDX_BROADCAST; p++) {
struct mtpav_port *portp = &chip->ports[p];
if ((portp->mode & MTPAV_MODE_OUTPUT_TRIGGERED) && portp->output)
snd_mtpav_output_port_write(chip, portp, portp->output);
}
spin_unlock_irqrestore(&chip->spinlock, flags);
}
static void snd_mtpav_add_output_timer(struct mtpav *chip)
{
chip->timer.expires = 1 + jiffies;
add_timer(&chip->timer);
}
static void snd_mtpav_remove_output_timer(struct mtpav *chip)
{
del_timer(&chip->timer);
}
static int snd_mtpav_output_open(struct snd_rawmidi_substream *substream)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
portp->mode |= MTPAV_MODE_OUTPUT_OPENED;
portp->output = substream;
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
return 0;
}
static int snd_mtpav_output_close(struct snd_rawmidi_substream *substream)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
portp->mode &= ~MTPAV_MODE_OUTPUT_OPENED;
portp->output = NULL;
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
return 0;
}
static void snd_mtpav_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct mtpav *mtp_card = substream->rmidi->private_data;
struct mtpav_port *portp = &mtp_card->ports[substream->number];
unsigned long flags;
spin_lock_irqsave(&mtp_card->spinlock, flags);
if (up) {
if (! (portp->mode & MTPAV_MODE_OUTPUT_TRIGGERED)) {
if (mtp_card->istimer++ == 0)
snd_mtpav_add_output_timer(mtp_card);
portp->mode |= MTPAV_MODE_OUTPUT_TRIGGERED;
}
} else {
portp->mode &= ~MTPAV_MODE_OUTPUT_TRIGGERED;
if (--mtp_card->istimer == 0)
snd_mtpav_remove_output_timer(mtp_card);
}
spin_unlock_irqrestore(&mtp_card->spinlock, flags);
if (up)
snd_mtpav_output_write(substream);
}
static void snd_mtpav_inmidi_process(struct mtpav *mcrd, u8 inbyte)
{
struct mtpav_port *portp;
if ((int)mcrd->inmidiport > mcrd->num_ports * 2 + MTPAV_PIDX_BROADCAST)
return;
portp = &mcrd->ports[mcrd->inmidiport];
if (portp->mode & MTPAV_MODE_INPUT_TRIGGERED)
snd_rawmidi_receive(portp->input, &inbyte, 1);
}
static void snd_mtpav_inmidi_h(struct mtpav *mcrd, u8 inbyte)
{
if (inbyte >= 0xf8) {
snd_mtpav_inmidi_process(mcrd, inbyte);
return;
}
if (mcrd->inmidistate == 0) {
if (inbyte == 0xf5)
mcrd->inmidistate = 1;
else
snd_mtpav_inmidi_process(mcrd, inbyte);
} else if (mcrd->inmidistate) {
mcrd->inmidiport = translate_hwport_to_subdevice(mcrd, inbyte);
mcrd->inmidistate = 0;
}
}
static void snd_mtpav_read_bytes(struct mtpav *mcrd)
{
u8 clrread, setread;
u8 mtp_read_byte;
u8 sr, cbyt;
int i;
u8 sbyt = snd_mtpav_getreg(mcrd, SREG);
if (!(sbyt & SIGS_BYTE))
return;
cbyt = snd_mtpav_getreg(mcrd, CREG);
clrread = cbyt & (SIGC_READ ^ 0xff);
setread = cbyt | SIGC_READ;
do {
mtp_read_byte = 0;
for (i = 0; i < 4; i++) {
snd_mtpav_mputreg(mcrd, CREG, setread);
sr = snd_mtpav_getreg(mcrd, SREG);
snd_mtpav_mputreg(mcrd, CREG, clrread);
sr &= SIGS_IN0 | SIGS_IN1;
sr >>= 4;
mtp_read_byte |= sr << (i * 2);
}
snd_mtpav_inmidi_h(mcrd, mtp_read_byte);
sbyt = snd_mtpav_getreg(mcrd, SREG);
} while (sbyt & SIGS_BYTE);
}
static irqreturn_t snd_mtpav_irqh(int irq, void *dev_id)
{
struct mtpav *mcard = dev_id;
spin_lock(&mcard->spinlock);
snd_mtpav_read_bytes(mcard);
spin_unlock(&mcard->spinlock);
return IRQ_HANDLED;
}
static int snd_mtpav_get_ISA(struct mtpav *mcard)
{
if ((mcard->res_port = request_region(port, 3, "MotuMTPAV MIDI")) == NULL) {
snd_printk(KERN_ERR "MTVAP port 0x%lx is busy\n", port);
return -EBUSY;
}
mcard->port = port;
if (request_irq(irq, snd_mtpav_irqh, 0, "MOTU MTPAV", mcard)) {
snd_printk(KERN_ERR "MTVAP IRQ %d busy\n", irq);
return -EBUSY;
}
mcard->irq = irq;
return 0;
}
static void snd_mtpav_set_name(struct mtpav *chip,
struct snd_rawmidi_substream *substream)
{
if (substream->number >= 0 && substream->number < chip->num_ports)
sprintf(substream->name, "MTP direct %d", (substream->number % chip->num_ports) + 1);
else if (substream->number >= 8 && substream->number < chip->num_ports * 2)
sprintf(substream->name, "MTP remote %d", (substream->number % chip->num_ports) + 1);
else if (substream->number == chip->num_ports * 2)
strcpy(substream->name, "MTP computer");
else if (substream->number == chip->num_ports * 2 + 1)
strcpy(substream->name, "MTP ADAT");
else
strcpy(substream->name, "MTP broadcast");
}
static int snd_mtpav_get_RAWMIDI(struct mtpav *mcard)
{
int rval;
struct snd_rawmidi *rawmidi;
struct snd_rawmidi_substream *substream;
struct list_head *list;
if (hwports < 1)
hwports = 1;
else if (hwports > 8)
hwports = 8;
mcard->num_ports = hwports;
if ((rval = snd_rawmidi_new(mcard->card, "MotuMIDI", 0,
mcard->num_ports * 2 + MTPAV_PIDX_BROADCAST + 1,
mcard->num_ports * 2 + MTPAV_PIDX_BROADCAST + 1,
&mcard->rmidi)) < 0)
return rval;
rawmidi = mcard->rmidi;
rawmidi->private_data = mcard;
list_for_each(list, &rawmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams) {
substream = list_entry(list, struct snd_rawmidi_substream, list);
snd_mtpav_set_name(mcard, substream);
substream->ops = &snd_mtpav_input;
}
list_for_each(list, &rawmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams) {
substream = list_entry(list, struct snd_rawmidi_substream, list);
snd_mtpav_set_name(mcard, substream);
substream->ops = &snd_mtpav_output;
mcard->ports[substream->number].hwport = translate_subdevice_to_hwport(mcard, substream->number);
}
rawmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT | SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
sprintf(rawmidi->name, "MTP AV MIDI");
return 0;
}
static void snd_mtpav_free(struct snd_card *card)
{
struct mtpav *crd = card->private_data;
unsigned long flags;
spin_lock_irqsave(&crd->spinlock, flags);
if (crd->istimer > 0)
snd_mtpav_remove_output_timer(crd);
spin_unlock_irqrestore(&crd->spinlock, flags);
if (crd->irq >= 0)
free_irq(crd->irq, (void *)crd);
release_and_free_resource(crd->res_port);
}
static int snd_mtpav_probe(struct platform_device *dev)
{
struct snd_card *card;
int err;
struct mtpav *mtp_card;
err = snd_card_create(index, id, THIS_MODULE, sizeof(*mtp_card), &card);
if (err < 0)
return err;
mtp_card = card->private_data;
spin_lock_init(&mtp_card->spinlock);
init_timer(&mtp_card->timer);
mtp_card->card = card;
mtp_card->irq = -1;
mtp_card->share_irq = 0;
mtp_card->inmidistate = 0;
mtp_card->outmidihwport = 0xffffffff;
init_timer(&mtp_card->timer);
mtp_card->timer.function = snd_mtpav_output_timer;
mtp_card->timer.data = (unsigned long) mtp_card;
card->private_free = snd_mtpav_free;
err = snd_mtpav_get_RAWMIDI(mtp_card);
if (err < 0)
goto __error;
mtp_card->inmidiport = mtp_card->num_ports + MTPAV_PIDX_BROADCAST;
err = snd_mtpav_get_ISA(mtp_card);
if (err < 0)
goto __error;
strcpy(card->driver, "MTPAV");
strcpy(card->shortname, "MTPAV on parallel port");
snprintf(card->longname, sizeof(card->longname),
"MTPAV on parallel port at 0x%lx", port);
snd_mtpav_portscan(mtp_card);
snd_card_set_dev(card, &dev->dev);
err = snd_card_register(mtp_card->card);
if (err < 0)
goto __error;
platform_set_drvdata(dev, card);
printk(KERN_INFO "Motu MidiTimePiece on parallel port irq: %d ioport: 0x%lx\n", irq, port);
return 0;
__error:
snd_card_free(card);
return err;
}
static int snd_mtpav_remove(struct platform_device *devptr)
{
snd_card_free(platform_get_drvdata(devptr));
return 0;
}
static int __init alsa_card_mtpav_init(void)
{
int err;
if ((err = platform_driver_register(&snd_mtpav_driver)) < 0)
return err;
device = platform_device_register_simple(SND_MTPAV_DRIVER, -1, NULL, 0);
if (!IS_ERR(device)) {
if (platform_get_drvdata(device))
return 0;
platform_device_unregister(device);
err = -ENODEV;
} else
err = PTR_ERR(device);
platform_driver_unregister(&snd_mtpav_driver);
return err;
}
static void __exit alsa_card_mtpav_exit(void)
{
platform_device_unregister(device);
platform_driver_unregister(&snd_mtpav_driver);
}
