static int snd_aw2_dev_free(struct snd_device *device)
{
struct aw2 *chip = device->device_data;
snd_aw2_saa7146_free(&chip->saa7146);
if (chip->irq >= 0)
free_irq(chip->irq, (void *)chip);
if (chip->iobase_virt)
iounmap(chip->iobase_virt);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_aw2_create(struct snd_card *card,
struct pci_dev *pci, struct aw2 **rchip)
{
struct aw2 *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_aw2_dev_free,
};
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
pci_set_master(pci);
if ((pci_set_dma_mask(pci, DMA_BIT_MASK(32)) < 0) ||
(pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(32)) < 0)) {
dev_err(card->dev, "Impossible to set 32bit mask DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->card = card;
chip->pci = pci;
chip->irq = -1;
err = pci_request_regions(pci, "Audiowerk2");
if (err < 0) {
pci_disable_device(pci);
kfree(chip);
return err;
}
chip->iobase_phys = pci_resource_start(pci, 0);
chip->iobase_virt =
ioremap_nocache(chip->iobase_phys,
pci_resource_len(pci, 0));
if (chip->iobase_virt == NULL) {
dev_err(card->dev, "unable to remap memory region");
pci_release_regions(pci);
pci_disable_device(pci);
kfree(chip);
return -ENOMEM;
}
snd_aw2_saa7146_setup(&chip->saa7146, chip->iobase_virt);
if (request_irq(pci->irq, snd_aw2_saa7146_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
dev_err(card->dev, "Cannot grab irq %d\n", pci->irq);
iounmap(chip->iobase_virt);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return -EBUSY;
}
chip->irq = pci->irq;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
free_irq(chip->irq, (void *)chip);
iounmap(chip->iobase_virt);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return err;
}
*rchip = chip;
dev_info(card->dev,
"Audiowerk 2 sound card (saa7146 chipset) detected and managed\n");
return 0;
}
static int snd_aw2_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct aw2 *chip;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
err = snd_aw2_create(card, pci, &chip);
if (err < 0) {
snd_card_free(card);
return err;
}
mutex_init(&chip->mtx);
spin_lock_init(&chip->reg_lock);
strcpy(card->driver, "aw2");
strcpy(card->shortname, "Audiowerk2");
sprintf(card->longname, "%s with SAA7146 irq %i",
card->shortname, chip->irq);
snd_aw2_new_pcm(chip);
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_aw2_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static int snd_aw2_pcm_playback_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
dev_dbg(substream->pcm->card->dev, "Playback_open\n");
runtime->hw = snd_aw2_playback_hw;
return 0;
}
static int snd_aw2_pcm_playback_close(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_aw2_pcm_capture_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
dev_dbg(substream->pcm->card->dev, "Capture_open\n");
runtime->hw = snd_aw2_capture_hw;
return 0;
}
static int snd_aw2_pcm_capture_close(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_aw2_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_aw2_pcm_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_aw2_pcm_prepare_playback(struct snd_pcm_substream *substream)
{
struct aw2_pcm_device *pcm_device = snd_pcm_substream_chip(substream);
struct aw2 *chip = pcm_device->chip;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long period_size, buffer_size;
mutex_lock(&chip->mtx);
period_size = snd_pcm_lib_period_bytes(substream);
buffer_size = snd_pcm_lib_buffer_bytes(substream);
snd_aw2_saa7146_pcm_init_playback(&chip->saa7146,
pcm_device->stream_number,
runtime->dma_addr, period_size,
buffer_size);
snd_aw2_saa7146_define_it_playback_callback(pcm_device->stream_number,
(snd_aw2_saa7146_it_cb)
snd_pcm_period_elapsed,
(void *)substream);
mutex_unlock(&chip->mtx);
return 0;
}
static int snd_aw2_pcm_prepare_capture(struct snd_pcm_substream *substream)
{
struct aw2_pcm_device *pcm_device = snd_pcm_substream_chip(substream);
struct aw2 *chip = pcm_device->chip;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long period_size, buffer_size;
mutex_lock(&chip->mtx);
period_size = snd_pcm_lib_period_bytes(substream);
buffer_size = snd_pcm_lib_buffer_bytes(substream);
snd_aw2_saa7146_pcm_init_capture(&chip->saa7146,
pcm_device->stream_number,
runtime->dma_addr, period_size,
buffer_size);
snd_aw2_saa7146_define_it_capture_callback(pcm_device->stream_number,
(snd_aw2_saa7146_it_cb)
snd_pcm_period_elapsed,
(void *)substream);
mutex_unlock(&chip->mtx);
return 0;
}
static int snd_aw2_pcm_trigger_playback(struct snd_pcm_substream *substream,
int cmd)
{
int status = 0;
struct aw2_pcm_device *pcm_device = snd_pcm_substream_chip(substream);
struct aw2 *chip = pcm_device->chip;
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
snd_aw2_saa7146_pcm_trigger_start_playback(&chip->saa7146,
pcm_device->
stream_number);
break;
case SNDRV_PCM_TRIGGER_STOP:
snd_aw2_saa7146_pcm_trigger_stop_playback(&chip->saa7146,
pcm_device->
stream_number);
break;
default:
status = -EINVAL;
}
spin_unlock(&chip->reg_lock);
return status;
}
static int snd_aw2_pcm_trigger_capture(struct snd_pcm_substream *substream,
int cmd)
{
int status = 0;
struct aw2_pcm_device *pcm_device = snd_pcm_substream_chip(substream);
struct aw2 *chip = pcm_device->chip;
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
snd_aw2_saa7146_pcm_trigger_start_capture(&chip->saa7146,
pcm_device->
stream_number);
break;
case SNDRV_PCM_TRIGGER_STOP:
snd_aw2_saa7146_pcm_trigger_stop_capture(&chip->saa7146,
pcm_device->
stream_number);
break;
default:
status = -EINVAL;
}
spin_unlock(&chip->reg_lock);
return status;
}
static snd_pcm_uframes_t snd_aw2_pcm_pointer_playback(struct snd_pcm_substream
*substream)
{
struct aw2_pcm_device *pcm_device = snd_pcm_substream_chip(substream);
struct aw2 *chip = pcm_device->chip;
unsigned int current_ptr;
struct snd_pcm_runtime *runtime = substream->runtime;
current_ptr =
snd_aw2_saa7146_get_hw_ptr_playback(&chip->saa7146,
pcm_device->stream_number,
runtime->dma_area,
runtime->buffer_size);
return bytes_to_frames(substream->runtime, current_ptr);
}
static snd_pcm_uframes_t snd_aw2_pcm_pointer_capture(struct snd_pcm_substream
*substream)
{
struct aw2_pcm_device *pcm_device = snd_pcm_substream_chip(substream);
struct aw2 *chip = pcm_device->chip;
unsigned int current_ptr;
struct snd_pcm_runtime *runtime = substream->runtime;
current_ptr =
snd_aw2_saa7146_get_hw_ptr_capture(&chip->saa7146,
pcm_device->stream_number,
runtime->dma_area,
runtime->buffer_size);
return bytes_to_frames(substream->runtime, current_ptr);
}
static int snd_aw2_new_pcm(struct aw2 *chip)
{
struct snd_pcm *pcm_playback_ana;
struct snd_pcm *pcm_playback_num;
struct snd_pcm *pcm_capture;
struct aw2_pcm_device *pcm_device;
int err = 0;
err = snd_pcm_new(chip->card, "Audiowerk2 analog playback", 0, 1, 0,
&pcm_playback_ana);
if (err < 0) {
dev_err(chip->card->dev, "snd_pcm_new error (0x%X)\n", err);
return err;
}
pcm_device = &chip->device_playback[NUM_STREAM_PLAYBACK_ANA];
strcpy(pcm_playback_ana->name, "Analog playback");
pcm_playback_ana->private_data = pcm_device;
snd_pcm_set_ops(pcm_playback_ana, SNDRV_PCM_STREAM_PLAYBACK,
&snd_aw2_playback_ops);
pcm_device->pcm = pcm_playback_ana;
pcm_device->chip = chip;
pcm_device->stream_number = NUM_STREAM_PLAYBACK_ANA;
err = snd_pcm_lib_preallocate_pages_for_all(pcm_playback_ana,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data
(chip->pci),
64 * 1024, 64 * 1024);
if (err)
dev_err(chip->card->dev,
"snd_pcm_lib_preallocate_pages_for_all error (0x%X)\n",
err);
err = snd_pcm_new(chip->card, "Audiowerk2 digital playback", 1, 1, 0,
&pcm_playback_num);
if (err < 0) {
dev_err(chip->card->dev, "snd_pcm_new error (0x%X)\n", err);
return err;
}
pcm_device = &chip->device_playback[NUM_STREAM_PLAYBACK_DIG];
strcpy(pcm_playback_num->name, "Digital playback");
pcm_playback_num->private_data = pcm_device;
snd_pcm_set_ops(pcm_playback_num, SNDRV_PCM_STREAM_PLAYBACK,
&snd_aw2_playback_ops);
pcm_device->pcm = pcm_playback_num;
pcm_device->chip = chip;
pcm_device->stream_number = NUM_STREAM_PLAYBACK_DIG;
err = snd_pcm_lib_preallocate_pages_for_all(pcm_playback_num,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data
(chip->pci),
64 * 1024, 64 * 1024);
if (err)
dev_err(chip->card->dev,
"snd_pcm_lib_preallocate_pages_for_all error (0x%X)\n",
err);
err = snd_pcm_new(chip->card, "Audiowerk2 capture", 2, 0, 1,
&pcm_capture);
if (err < 0) {
dev_err(chip->card->dev, "snd_pcm_new error (0x%X)\n", err);
return err;
}
pcm_device = &chip->device_capture[NUM_STREAM_CAPTURE_ANA];
strcpy(pcm_capture->name, "Capture");
pcm_capture->private_data = pcm_device;
snd_pcm_set_ops(pcm_capture, SNDRV_PCM_STREAM_CAPTURE,
&snd_aw2_capture_ops);
pcm_device->pcm = pcm_capture;
pcm_device->chip = chip;
pcm_device->stream_number = NUM_STREAM_CAPTURE_ANA;
err = snd_pcm_lib_preallocate_pages_for_all(pcm_capture,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data
(chip->pci),
64 * 1024, 64 * 1024);
if (err)
dev_err(chip->card->dev,
"snd_pcm_lib_preallocate_pages_for_all error (0x%X)\n",
err);
err = snd_ctl_add(chip->card, snd_ctl_new1(&aw2_control, chip));
if (err < 0) {
dev_err(chip->card->dev, "snd_ctl_add error (0x%X)\n", err);
return err;
}
return 0;
}
static int snd_aw2_control_switch_capture_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[2] = {
"Analog", "Digital"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items) {
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
}
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_aw2_control_switch_capture_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value
*ucontrol)
{
struct aw2 *chip = snd_kcontrol_chip(kcontrol);
if (snd_aw2_saa7146_is_using_digital_input(&chip->saa7146))
ucontrol->value.enumerated.item[0] = CTL_ROUTE_DIGITAL;
else
ucontrol->value.enumerated.item[0] = CTL_ROUTE_ANALOG;
return 0;
}
static int snd_aw2_control_switch_capture_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value
*ucontrol)
{
struct aw2 *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
int is_disgital =
snd_aw2_saa7146_is_using_digital_input(&chip->saa7146);
if (((ucontrol->value.integer.value[0] == CTL_ROUTE_DIGITAL)
&& !is_disgital)
|| ((ucontrol->value.integer.value[0] == CTL_ROUTE_ANALOG)
&& is_disgital)) {
snd_aw2_saa7146_use_digital_input(&chip->saa7146, !is_disgital);
changed = 1;
}
return changed;
}
