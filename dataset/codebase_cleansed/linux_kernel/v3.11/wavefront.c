static int
snd_wavefront_pnp (int dev, snd_wavefront_card_t *acard, struct pnp_card_link *card,
const struct pnp_card_device_id *id)
{
struct pnp_dev *pdev;
int err;
acard->wss = pnp_request_card_device(card, id->devs[0].id, NULL);
if (acard->wss == NULL)
return -EBUSY;
if (use_cs4232_midi[dev]) {
acard->mpu = pnp_request_card_device(card, id->devs[2].id, NULL);
if (acard->mpu == NULL)
return -EBUSY;
}
acard->synth = pnp_request_card_device(card, id->devs[3].id, NULL);
if (acard->synth == NULL)
return -EBUSY;
pdev = acard->wss;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "PnP WSS pnp configure failure\n");
return err;
}
cs4232_pcm_port[dev] = pnp_port_start(pdev, 0);
fm_port[dev] = pnp_port_start(pdev, 1);
dma1[dev] = pnp_dma(pdev, 0);
dma2[dev] = pnp_dma(pdev, 1);
cs4232_pcm_irq[dev] = pnp_irq(pdev, 0);
pdev = acard->synth;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "PnP ICS2115 pnp configure failure\n");
return err;
}
ics2115_port[dev] = pnp_port_start(pdev, 0);
ics2115_irq[dev] = pnp_irq(pdev, 0);
if (use_cs4232_midi[dev]) {
pdev = acard->mpu;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "PnP MPU401 pnp configure failure\n");
cs4232_mpu_port[dev] = SNDRV_AUTO_PORT;
} else {
cs4232_mpu_port[dev] = pnp_port_start(pdev, 0);
cs4232_mpu_irq[dev] = pnp_irq(pdev, 0);
}
snd_printk (KERN_INFO "CS4232 MPU: port=0x%lx, irq=%i\n",
cs4232_mpu_port[dev],
cs4232_mpu_irq[dev]);
}
snd_printdd ("CS4232: pcm port=0x%lx, fm port=0x%lx, dma1=%i, dma2=%i, irq=%i\nICS2115: port=0x%lx, irq=%i\n",
cs4232_pcm_port[dev],
fm_port[dev],
dma1[dev],
dma2[dev],
cs4232_pcm_irq[dev],
ics2115_port[dev],
ics2115_irq[dev]);
return 0;
}
static irqreturn_t snd_wavefront_ics2115_interrupt(int irq, void *dev_id)
{
snd_wavefront_card_t *acard;
acard = (snd_wavefront_card_t *) dev_id;
if (acard == NULL)
return IRQ_NONE;
if (acard->wavefront.interrupts_are_midi) {
snd_wavefront_midi_interrupt (acard);
} else {
snd_wavefront_internal_interrupt (acard);
}
return IRQ_HANDLED;
}
static struct snd_hwdep *snd_wavefront_new_synth(struct snd_card *card,
int hw_dev,
snd_wavefront_card_t *acard)
{
struct snd_hwdep *wavefront_synth;
if (snd_wavefront_detect (acard) < 0) {
return NULL;
}
if (snd_wavefront_start (&acard->wavefront) < 0) {
return NULL;
}
if (snd_hwdep_new(card, "WaveFront", hw_dev, &wavefront_synth) < 0)
return NULL;
strcpy (wavefront_synth->name,
"WaveFront (ICS2115) wavetable synthesizer");
wavefront_synth->ops.open = snd_wavefront_synth_open;
wavefront_synth->ops.release = snd_wavefront_synth_release;
wavefront_synth->ops.ioctl = snd_wavefront_synth_ioctl;
return wavefront_synth;
}
static struct snd_hwdep *snd_wavefront_new_fx(struct snd_card *card,
int hw_dev,
snd_wavefront_card_t *acard,
unsigned long port)
{
struct snd_hwdep *fx_processor;
if (snd_wavefront_fx_start (&acard->wavefront)) {
snd_printk (KERN_ERR "cannot initialize YSS225 FX processor");
return NULL;
}
if (snd_hwdep_new (card, "YSS225", hw_dev, &fx_processor) < 0)
return NULL;
sprintf (fx_processor->name, "YSS225 FX Processor at 0x%lx", port);
fx_processor->ops.open = snd_wavefront_fx_open;
fx_processor->ops.release = snd_wavefront_fx_release;
fx_processor->ops.ioctl = snd_wavefront_fx_ioctl;
return fx_processor;
}
static struct snd_rawmidi *snd_wavefront_new_midi(struct snd_card *card,
int midi_dev,
snd_wavefront_card_t *acard,
unsigned long port,
snd_wavefront_mpu_id mpu)
{
struct snd_rawmidi *rmidi;
static int first = 1;
if (first) {
first = 0;
acard->wavefront.midi.base = port;
if (snd_wavefront_midi_start (acard)) {
snd_printk (KERN_ERR "cannot initialize MIDI interface\n");
return NULL;
}
}
if (snd_rawmidi_new (card, "WaveFront MIDI", midi_dev, 1, 1, &rmidi) < 0)
return NULL;
if (mpu == internal_mpu) {
strcpy(rmidi->name, "WaveFront MIDI (Internal)");
rmidi->private_data = &internal_id;
} else {
strcpy(rmidi->name, "WaveFront MIDI (External)");
rmidi->private_data = &external_id;
}
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &snd_wavefront_midi_output);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &snd_wavefront_midi_input);
rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT |
SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
return rmidi;
}
static void
snd_wavefront_free(struct snd_card *card)
{
snd_wavefront_card_t *acard = (snd_wavefront_card_t *)card->private_data;
if (acard) {
release_and_free_resource(acard->wavefront.res_base);
if (acard->wavefront.irq > 0)
free_irq(acard->wavefront.irq, (void *)acard);
}
}
static int snd_wavefront_card_new(int dev, struct snd_card **cardp)
{
struct snd_card *card;
snd_wavefront_card_t *acard;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(snd_wavefront_card_t), &card);
if (err < 0)
return err;
acard = card->private_data;
acard->wavefront.irq = -1;
spin_lock_init(&acard->wavefront.irq_lock);
init_waitqueue_head(&acard->wavefront.interrupt_sleeper);
spin_lock_init(&acard->wavefront.midi.open);
spin_lock_init(&acard->wavefront.midi.virtual);
acard->wavefront.card = card;
card->private_free = snd_wavefront_free;
*cardp = card;
return 0;
}
static int
snd_wavefront_probe (struct snd_card *card, int dev)
{
snd_wavefront_card_t *acard = card->private_data;
struct snd_wss *chip;
struct snd_hwdep *wavefront_synth;
struct snd_rawmidi *ics2115_internal_rmidi = NULL;
struct snd_rawmidi *ics2115_external_rmidi = NULL;
struct snd_hwdep *fx_processor;
int hw_dev = 0, midi_dev = 0, err;
err = snd_wss_create(card, cs4232_pcm_port[dev], -1,
cs4232_pcm_irq[dev], dma1[dev], dma2[dev],
WSS_HW_DETECT, 0, &chip);
if (err < 0) {
snd_printk(KERN_ERR "can't allocate WSS device\n");
return err;
}
err = snd_wss_pcm(chip, 0, NULL);
if (err < 0)
return err;
err = snd_wss_timer(chip, 0, NULL);
if (err < 0)
return err;
if (fm_port[dev] > 0 && fm_port[dev] != SNDRV_AUTO_PORT) {
struct snd_opl3 *opl3;
err = snd_opl3_create(card, fm_port[dev], fm_port[dev] + 2,
OPL3_HW_OPL3_CS, 0, &opl3);
if (err < 0) {
snd_printk (KERN_ERR "can't allocate or detect OPL3 synth\n");
return err;
}
err = snd_opl3_hwdep_new(opl3, hw_dev, 1, NULL);
if (err < 0)
return err;
hw_dev++;
}
acard->wavefront.res_base = request_region(ics2115_port[dev], 16,
"ICS2115");
if (acard->wavefront.res_base == NULL) {
snd_printk(KERN_ERR "unable to grab ICS2115 i/o region 0x%lx-0x%lx\n",
ics2115_port[dev], ics2115_port[dev] + 16 - 1);
return -EBUSY;
}
if (request_irq(ics2115_irq[dev], snd_wavefront_ics2115_interrupt,
0, "ICS2115", acard)) {
snd_printk(KERN_ERR "unable to use ICS2115 IRQ %d\n", ics2115_irq[dev]);
return -EBUSY;
}
acard->wavefront.irq = ics2115_irq[dev];
acard->wavefront.base = ics2115_port[dev];
wavefront_synth = snd_wavefront_new_synth(card, hw_dev, acard);
if (wavefront_synth == NULL) {
snd_printk (KERN_ERR "can't create WaveFront synth device\n");
return -ENOMEM;
}
strcpy (wavefront_synth->name, "ICS2115 Wavetable MIDI Synthesizer");
wavefront_synth->iface = SNDRV_HWDEP_IFACE_ICS2115;
hw_dev++;
err = snd_wss_mixer(chip);
if (err < 0) {
snd_printk (KERN_ERR "can't allocate mixer device\n");
return err;
}
if (cs4232_mpu_port[dev] > 0 && cs4232_mpu_port[dev] != SNDRV_AUTO_PORT) {
err = snd_mpu401_uart_new(card, midi_dev, MPU401_HW_CS4232,
cs4232_mpu_port[dev], 0,
cs4232_mpu_irq[dev], NULL);
if (err < 0) {
snd_printk (KERN_ERR "can't allocate CS4232 MPU-401 device\n");
return err;
}
midi_dev++;
}
if (ics2115_port[dev] > 0 && ics2115_port[dev] != SNDRV_AUTO_PORT) {
ics2115_internal_rmidi =
snd_wavefront_new_midi (card,
midi_dev,
acard,
ics2115_port[dev],
internal_mpu);
if (ics2115_internal_rmidi == NULL) {
snd_printk (KERN_ERR "can't setup ICS2115 internal MIDI device\n");
return -ENOMEM;
}
midi_dev++;
}
if (ics2115_port[dev] > 0 && ics2115_port[dev] != SNDRV_AUTO_PORT) {
ics2115_external_rmidi =
snd_wavefront_new_midi (card,
midi_dev,
acard,
ics2115_port[dev],
external_mpu);
if (ics2115_external_rmidi == NULL) {
snd_printk (KERN_ERR "can't setup ICS2115 external MIDI device\n");
return -ENOMEM;
}
midi_dev++;
}
if (acard->wavefront.has_fx) {
fx_processor = snd_wavefront_new_fx (card,
hw_dev,
acard,
ics2115_port[dev]);
if (fx_processor == NULL) {
snd_printk (KERN_ERR "can't setup FX device\n");
return -ENOMEM;
}
hw_dev++;
strcpy(card->driver, "Tropez+");
strcpy(card->shortname, "Turtle Beach Tropez+");
} else {
strcpy(card->driver, "WaveFront");
strcpy(card->shortname, "Turtle Beach WaveFront");
}
sprintf(card->longname, "%s PCM 0x%lx irq %d dma %d",
card->driver,
chip->port,
cs4232_pcm_irq[dev],
dma1[dev]);
if (dma2[dev] >= 0 && dma2[dev] < 8)
sprintf(card->longname + strlen(card->longname), "&%d", dma2[dev]);
if (cs4232_mpu_port[dev] > 0 && cs4232_mpu_port[dev] != SNDRV_AUTO_PORT) {
sprintf (card->longname + strlen (card->longname),
" MPU-401 0x%lx irq %d",
cs4232_mpu_port[dev],
cs4232_mpu_irq[dev]);
}
sprintf (card->longname + strlen (card->longname),
" SYNTH 0x%lx irq %d",
ics2115_port[dev],
ics2115_irq[dev]);
return snd_card_register(card);
}
static int snd_wavefront_isa_match(struct device *pdev,
unsigned int dev)
{
if (!enable[dev])
return 0;
#ifdef CONFIG_PNP
if (isapnp[dev])
return 0;
#endif
if (cs4232_pcm_port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR "specify CS4232 port\n");
return 0;
}
if (ics2115_port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR "specify ICS2115 port\n");
return 0;
}
return 1;
}
static int snd_wavefront_isa_probe(struct device *pdev,
unsigned int dev)
{
struct snd_card *card;
int err;
err = snd_wavefront_card_new(dev, &card);
if (err < 0)
return err;
snd_card_set_dev(card, pdev);
if ((err = snd_wavefront_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
dev_set_drvdata(pdev, card);
return 0;
}
static int snd_wavefront_isa_remove(struct device *devptr,
unsigned int dev)
{
snd_card_free(dev_get_drvdata(devptr));
return 0;
}
static int snd_wavefront_pnp_detect(struct pnp_card_link *pcard,
const struct pnp_card_device_id *pid)
{
static int dev;
struct snd_card *card;
int res;
for ( ; dev < SNDRV_CARDS; dev++) {
if (enable[dev] && isapnp[dev])
break;
}
if (dev >= SNDRV_CARDS)
return -ENODEV;
res = snd_wavefront_card_new(dev, &card);
if (res < 0)
return res;
if (snd_wavefront_pnp (dev, card->private_data, pcard, pid) < 0) {
if (cs4232_pcm_port[dev] == SNDRV_AUTO_PORT) {
snd_printk (KERN_ERR "isapnp detection failed\n");
snd_card_free (card);
return -ENODEV;
}
}
snd_card_set_dev(card, &pcard->card->dev);
if ((res = snd_wavefront_probe(card, dev)) < 0)
return res;
pnp_set_card_drvdata(pcard, card);
dev++;
return 0;
}
static void snd_wavefront_pnp_remove(struct pnp_card_link *pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int __init alsa_card_wavefront_init(void)
{
int err;
err = isa_register_driver(&snd_wavefront_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_card_driver(&wavefront_pnpc_driver);
if (!err)
pnp_registered = 1;
if (isa_registered)
err = 0;
#endif
return err;
}
static void __exit alsa_card_wavefront_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_card_driver(&wavefront_pnpc_driver);
if (isa_registered)
#endif
isa_unregister_driver(&snd_wavefront_driver);
}
