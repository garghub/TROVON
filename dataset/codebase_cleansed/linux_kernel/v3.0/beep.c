void snd_pmac_beep_stop(struct snd_pmac *chip)
{
struct pmac_beep *beep = chip->beep;
if (beep && beep->running) {
beep->running = 0;
snd_pmac_beep_dma_stop(chip);
}
}
static int snd_pmac_beep_event(struct input_dev *dev, unsigned int type,
unsigned int code, int hz)
{
struct snd_pmac *chip;
struct pmac_beep *beep;
unsigned long flags;
int beep_speed = 0;
int srate;
int period, ncycles, nsamples;
int i, j, f;
short *p;
if (type != EV_SND)
return -1;
switch (code) {
case SND_BELL: if (hz) hz = 1000;
case SND_TONE: break;
default: return -1;
}
chip = input_get_drvdata(dev);
if (! chip || (beep = chip->beep) == NULL)
return -1;
if (! hz) {
spin_lock_irqsave(&chip->reg_lock, flags);
if (beep->running)
snd_pmac_beep_stop(chip);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
beep_speed = snd_pmac_rate_index(chip, &chip->playback, BEEP_SRATE);
srate = chip->freq_table[beep_speed];
if (hz <= srate / BEEP_BUFLEN || hz > srate / 2)
hz = 1000;
spin_lock_irqsave(&chip->reg_lock, flags);
if (chip->playback.running || chip->capture.running || beep->running) {
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
beep->running = 1;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (hz == beep->hz && beep->volume == beep->volume_play) {
nsamples = beep->nsamples;
} else {
period = srate * 256 / hz;
ncycles = BEEP_BUFLEN * 256 / period;
nsamples = (period * ncycles) >> 8;
f = ncycles * 65536 / nsamples;
j = 0;
p = beep->buf;
for (i = 0; i < nsamples; ++i, p += 2) {
p[0] = p[1] = beep_wform[j >> 8] * beep->volume;
j = (j + f) & 0xffff;
}
beep->hz = hz;
beep->volume_play = beep->volume;
beep->nsamples = nsamples;
}
spin_lock_irqsave(&chip->reg_lock, flags);
snd_pmac_beep_dma_start(chip, beep->nsamples * 4, beep->addr, beep_speed);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int snd_pmac_info_beep(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 100;
return 0;
}
static int snd_pmac_get_beep(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
if (snd_BUG_ON(!chip->beep))
return -ENXIO;
ucontrol->value.integer.value[0] = chip->beep->volume;
return 0;
}
static int snd_pmac_put_beep(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int oval, nval;
if (snd_BUG_ON(!chip->beep))
return -ENXIO;
oval = chip->beep->volume;
nval = ucontrol->value.integer.value[0];
if (nval > 100)
return -EINVAL;
chip->beep->volume = nval;
return oval != chip->beep->volume;
}
int __devinit snd_pmac_attach_beep(struct snd_pmac *chip)
{
struct pmac_beep *beep;
struct input_dev *input_dev;
struct snd_kcontrol *beep_ctl;
void *dmabuf;
int err = -ENOMEM;
beep = kzalloc(sizeof(*beep), GFP_KERNEL);
if (! beep)
return -ENOMEM;
dmabuf = dma_alloc_coherent(&chip->pdev->dev, BEEP_BUFLEN * 4,
&beep->addr, GFP_KERNEL);
input_dev = input_allocate_device();
if (! dmabuf || ! input_dev)
goto fail1;
input_dev->name = "PowerMac Beep";
input_dev->phys = "powermac/beep";
input_dev->id.bustype = BUS_ADB;
input_dev->id.vendor = 0x001f;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->evbit[0] = BIT_MASK(EV_SND);
input_dev->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
input_dev->event = snd_pmac_beep_event;
input_dev->dev.parent = &chip->pdev->dev;
input_set_drvdata(input_dev, chip);
beep->dev = input_dev;
beep->buf = dmabuf;
beep->volume = BEEP_VOLUME;
beep->running = 0;
beep_ctl = snd_ctl_new1(&snd_pmac_beep_mixer, chip);
err = snd_ctl_add(chip->card, beep_ctl);
if (err < 0)
goto fail1;
chip->beep = beep;
err = input_register_device(beep->dev);
if (err)
goto fail2;
return 0;
fail2: snd_ctl_remove(chip->card, beep_ctl);
fail1: input_free_device(input_dev);
if (dmabuf)
dma_free_coherent(&chip->pdev->dev, BEEP_BUFLEN * 4,
dmabuf, beep->addr);
kfree(beep);
return err;
}
void snd_pmac_detach_beep(struct snd_pmac *chip)
{
if (chip->beep) {
input_unregister_device(chip->beep->dev);
dma_free_coherent(&chip->pdev->dev, BEEP_BUFLEN * 4,
chip->beep->buf, chip->beep->addr);
kfree(chip->beep);
chip->beep = NULL;
}
}
