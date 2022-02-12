static inline void snd_cs4281_pokeBA0(struct cs4281 *chip, unsigned long offset,
unsigned int val)
{
writel(val, chip->ba0 + offset);
}
static inline unsigned int snd_cs4281_peekBA0(struct cs4281 *chip, unsigned long offset)
{
return readl(chip->ba0 + offset);
}
static void snd_cs4281_ac97_write(struct snd_ac97 *ac97,
unsigned short reg, unsigned short val)
{
struct cs4281 *chip = ac97->private_data;
int count;
snd_cs4281_pokeBA0(chip, BA0_ACCAD, reg);
snd_cs4281_pokeBA0(chip, BA0_ACCDA, val);
snd_cs4281_pokeBA0(chip, BA0_ACCTL, BA0_ACCTL_DCV | BA0_ACCTL_VFRM |
BA0_ACCTL_ESYN | (ac97->num ? BA0_ACCTL_TC : 0));
for (count = 0; count < 2000; count++) {
udelay(10);
if (!(snd_cs4281_peekBA0(chip, BA0_ACCTL) & BA0_ACCTL_DCV)) {
return;
}
}
snd_printk(KERN_ERR "AC'97 write problem, reg = 0x%x, val = 0x%x\n", reg, val);
}
static unsigned short snd_cs4281_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct cs4281 *chip = ac97->private_data;
int count;
unsigned short result;
volatile int ac97_num = ((volatile struct snd_ac97 *)ac97)->num;
snd_cs4281_peekBA0(chip, ac97_num ? BA0_ACSDA2 : BA0_ACSDA);
snd_cs4281_pokeBA0(chip, BA0_ACCAD, reg);
snd_cs4281_pokeBA0(chip, BA0_ACCDA, 0);
snd_cs4281_pokeBA0(chip, BA0_ACCTL, BA0_ACCTL_DCV | BA0_ACCTL_CRW |
BA0_ACCTL_VFRM | BA0_ACCTL_ESYN |
(ac97_num ? BA0_ACCTL_TC : 0));
for (count = 0; count < 500; count++) {
udelay(10);
if (!(snd_cs4281_peekBA0(chip, BA0_ACCTL) & BA0_ACCTL_DCV))
goto __ok1;
}
snd_printk(KERN_ERR "AC'97 read problem (ACCTL_DCV), reg = 0x%x\n", reg);
result = 0xffff;
goto __end;
__ok1:
for (count = 0; count < 100; count++) {
if (snd_cs4281_peekBA0(chip, ac97_num ? BA0_ACSTS2 : BA0_ACSTS) & BA0_ACSTS_VSTS)
goto __ok2;
udelay(10);
}
snd_printk(KERN_ERR "AC'97 read problem (ACSTS_VSTS), reg = 0x%x\n", reg);
result = 0xffff;
goto __end;
__ok2:
result = snd_cs4281_peekBA0(chip, ac97_num ? BA0_ACSDA2 : BA0_ACSDA);
__end:
return result;
}
static int snd_cs4281_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct cs4281_dma *dma = substream->runtime->private_data;
struct cs4281 *chip = snd_pcm_substream_chip(substream);
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
dma->valDCR |= BA0_DCR_MSK;
dma->valFCR |= BA0_FCR_FEN;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dma->valDCR &= ~BA0_DCR_MSK;
dma->valFCR &= ~BA0_FCR_FEN;
break;
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
snd_cs4281_pokeBA0(chip, dma->regDMR, dma->valDMR & ~BA0_DMR_DMA);
dma->valDMR |= BA0_DMR_DMA;
dma->valDCR &= ~BA0_DCR_MSK;
dma->valFCR |= BA0_FCR_FEN;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
dma->valDMR &= ~(BA0_DMR_DMA|BA0_DMR_POLL);
dma->valDCR |= BA0_DCR_MSK;
dma->valFCR &= ~BA0_FCR_FEN;
if (dma->regFCR != BA0_FCR0)
dma->valFCR &= ~BA0_FCR_FEN;
break;
default:
spin_unlock(&chip->reg_lock);
return -EINVAL;
}
snd_cs4281_pokeBA0(chip, dma->regDMR, dma->valDMR);
snd_cs4281_pokeBA0(chip, dma->regFCR, dma->valFCR);
snd_cs4281_pokeBA0(chip, dma->regDCR, dma->valDCR);
spin_unlock(&chip->reg_lock);
return 0;
}
static unsigned int snd_cs4281_rate(unsigned int rate, unsigned int *real_rate)
{
unsigned int val = ~0;
if (real_rate)
*real_rate = rate;
switch (rate) {
case 8000: return 5;
case 11025: return 4;
case 16000: return 3;
case 22050: return 2;
case 44100: return 1;
case 48000: return 0;
default:
goto __variable;
}
__variable:
val = 1536000 / rate;
if (real_rate)
*real_rate = 1536000 / val;
return val;
}
static void snd_cs4281_mode(struct cs4281 *chip, struct cs4281_dma *dma,
struct snd_pcm_runtime *runtime,
int capture, int src)
{
int rec_mono;
dma->valDMR = BA0_DMR_TYPE_SINGLE | BA0_DMR_AUTO |
(capture ? BA0_DMR_TR_WRITE : BA0_DMR_TR_READ);
if (runtime->channels == 1)
dma->valDMR |= BA0_DMR_MONO;
if (snd_pcm_format_unsigned(runtime->format) > 0)
dma->valDMR |= BA0_DMR_USIGN;
if (snd_pcm_format_big_endian(runtime->format) > 0)
dma->valDMR |= BA0_DMR_BEND;
switch (snd_pcm_format_width(runtime->format)) {
case 8: dma->valDMR |= BA0_DMR_SIZE8;
if (runtime->channels == 1)
dma->valDMR |= BA0_DMR_SWAPC;
break;
case 32: dma->valDMR |= BA0_DMR_SIZE20; break;
}
dma->frag = 0;
dma->valDCR = BA0_DCR_TCIE | BA0_DCR_MSK;
if (runtime->buffer_size != runtime->period_size)
dma->valDCR |= BA0_DCR_HTCIE;
snd_cs4281_pokeBA0(chip, dma->regDBA, runtime->dma_addr);
snd_cs4281_pokeBA0(chip, dma->regDBC, runtime->buffer_size - 1);
rec_mono = (chip->dma[1].valDMR & BA0_DMR_MONO) == BA0_DMR_MONO;
snd_cs4281_pokeBA0(chip, BA0_SRCSA, (chip->src_left_play_slot << 0) |
(chip->src_right_play_slot << 8) |
(chip->src_left_rec_slot << 16) |
((rec_mono ? 31 : chip->src_right_rec_slot) << 24));
if (!src)
goto __skip_src;
if (!capture) {
if (dma->left_slot == chip->src_left_play_slot) {
unsigned int val = snd_cs4281_rate(runtime->rate, NULL);
snd_BUG_ON(dma->right_slot != chip->src_right_play_slot);
snd_cs4281_pokeBA0(chip, BA0_DACSR, val);
}
} else {
if (dma->left_slot == chip->src_left_rec_slot) {
unsigned int val = snd_cs4281_rate(runtime->rate, NULL);
snd_BUG_ON(dma->right_slot != chip->src_right_rec_slot);
snd_cs4281_pokeBA0(chip, BA0_ADCSR, val);
}
}
__skip_src:
if (dma->regFCR == BA0_FCR0)
snd_cs4281_pokeBA0(chip, dma->regFCR, snd_cs4281_peekBA0(chip, dma->regFCR) & ~BA0_FCR_FEN);
dma->valFCR = BA0_FCR_LS(dma->left_slot) |
BA0_FCR_RS(capture && (dma->valDMR & BA0_DMR_MONO) ? 31 : dma->right_slot) |
BA0_FCR_SZ(CS4281_FIFO_SIZE) |
BA0_FCR_OF(dma->fifo_offset);
snd_cs4281_pokeBA0(chip, dma->regFCR, dma->valFCR | (capture ? BA0_FCR_PSH : 0));
if (dma->regFCR == BA0_FCR0)
snd_cs4281_pokeBA0(chip, dma->regFCR, dma->valFCR | BA0_FCR_FEN);
snd_cs4281_pokeBA0(chip, dma->regFSIC, 0);
}
static int snd_cs4281_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_cs4281_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_cs4281_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct cs4281_dma *dma = runtime->private_data;
struct cs4281 *chip = snd_pcm_substream_chip(substream);
spin_lock_irq(&chip->reg_lock);
snd_cs4281_mode(chip, dma, runtime, 0, 1);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_cs4281_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct cs4281_dma *dma = runtime->private_data;
struct cs4281 *chip = snd_pcm_substream_chip(substream);
spin_lock_irq(&chip->reg_lock);
snd_cs4281_mode(chip, dma, runtime, 1, 1);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static snd_pcm_uframes_t snd_cs4281_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct cs4281_dma *dma = runtime->private_data;
struct cs4281 *chip = snd_pcm_substream_chip(substream);
return runtime->buffer_size -
snd_cs4281_peekBA0(chip, dma->regDCC) - 1;
}
static int snd_cs4281_playback_open(struct snd_pcm_substream *substream)
{
struct cs4281 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct cs4281_dma *dma;
dma = &chip->dma[0];
dma->substream = substream;
dma->left_slot = 0;
dma->right_slot = 1;
runtime->private_data = dma;
runtime->hw = snd_cs4281_playback;
snd_pcm_hw_constraint_msbits(runtime, 0, 32, 20);
return 0;
}
static int snd_cs4281_capture_open(struct snd_pcm_substream *substream)
{
struct cs4281 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct cs4281_dma *dma;
dma = &chip->dma[1];
dma->substream = substream;
dma->left_slot = 10;
dma->right_slot = 11;
runtime->private_data = dma;
runtime->hw = snd_cs4281_capture;
snd_pcm_hw_constraint_msbits(runtime, 0, 32, 20);
return 0;
}
static int snd_cs4281_playback_close(struct snd_pcm_substream *substream)
{
struct cs4281_dma *dma = substream->runtime->private_data;
dma->substream = NULL;
return 0;
}
static int snd_cs4281_capture_close(struct snd_pcm_substream *substream)
{
struct cs4281_dma *dma = substream->runtime->private_data;
dma->substream = NULL;
return 0;
}
static int snd_cs4281_pcm(struct cs4281 *chip, int device,
struct snd_pcm **rpcm)
{
struct snd_pcm *pcm;
int err;
if (rpcm)
*rpcm = NULL;
err = snd_pcm_new(chip->card, "CS4281", device, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_cs4281_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_cs4281_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, "CS4281");
chip->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci), 64*1024, 512*1024);
if (rpcm)
*rpcm = pcm;
return 0;
}
static int snd_cs4281_info_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = CS_VOL_MASK;
return 0;
}
static int snd_cs4281_get_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cs4281 *chip = snd_kcontrol_chip(kcontrol);
int regL = (kcontrol->private_value >> 16) & 0xffff;
int regR = kcontrol->private_value & 0xffff;
int volL, volR;
volL = CS_VOL_MASK - (snd_cs4281_peekBA0(chip, regL) & CS_VOL_MASK);
volR = CS_VOL_MASK - (snd_cs4281_peekBA0(chip, regR) & CS_VOL_MASK);
ucontrol->value.integer.value[0] = volL;
ucontrol->value.integer.value[1] = volR;
return 0;
}
static int snd_cs4281_put_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cs4281 *chip = snd_kcontrol_chip(kcontrol);
int change = 0;
int regL = (kcontrol->private_value >> 16) & 0xffff;
int regR = kcontrol->private_value & 0xffff;
int volL, volR;
volL = CS_VOL_MASK - (snd_cs4281_peekBA0(chip, regL) & CS_VOL_MASK);
volR = CS_VOL_MASK - (snd_cs4281_peekBA0(chip, regR) & CS_VOL_MASK);
if (ucontrol->value.integer.value[0] != volL) {
volL = CS_VOL_MASK - (ucontrol->value.integer.value[0] & CS_VOL_MASK);
snd_cs4281_pokeBA0(chip, regL, volL);
change = 1;
}
if (ucontrol->value.integer.value[1] != volR) {
volR = CS_VOL_MASK - (ucontrol->value.integer.value[1] & CS_VOL_MASK);
snd_cs4281_pokeBA0(chip, regR, volR);
change = 1;
}
return change;
}
static void snd_cs4281_mixer_free_ac97_bus(struct snd_ac97_bus *bus)
{
struct cs4281 *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void snd_cs4281_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct cs4281 *chip = ac97->private_data;
if (ac97->num)
chip->ac97_secondary = NULL;
else
chip->ac97 = NULL;
}
static int snd_cs4281_mixer(struct cs4281 *chip)
{
struct snd_card *card = chip->card;
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_cs4281_ac97_write,
.read = snd_cs4281_ac97_read,
};
if ((err = snd_ac97_bus(card, 0, &ops, chip, &chip->ac97_bus)) < 0)
return err;
chip->ac97_bus->private_free = snd_cs4281_mixer_free_ac97_bus;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_cs4281_mixer_free_ac97;
if ((err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97)) < 0)
return err;
if (chip->dual_codec) {
ac97.num = 1;
if ((err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97_secondary)) < 0)
return err;
}
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_cs4281_fm_vol, chip))) < 0)
return err;
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_cs4281_pcm_vol, chip))) < 0)
return err;
return 0;
}
static void snd_cs4281_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct cs4281 *chip = entry->private_data;
snd_iprintf(buffer, "Cirrus Logic CS4281\n\n");
snd_iprintf(buffer, "Spurious half IRQs : %u\n", chip->spurious_dhtc_irq);
snd_iprintf(buffer, "Spurious end IRQs : %u\n", chip->spurious_dtc_irq);
}
static ssize_t snd_cs4281_BA0_read(struct snd_info_entry *entry,
void *file_private_data,
struct file *file, char __user *buf,
size_t count, loff_t pos)
{
struct cs4281 *chip = entry->private_data;
if (copy_to_user_fromio(buf, chip->ba0 + pos, count))
return -EFAULT;
return count;
}
static ssize_t snd_cs4281_BA1_read(struct snd_info_entry *entry,
void *file_private_data,
struct file *file, char __user *buf,
size_t count, loff_t pos)
{
struct cs4281 *chip = entry->private_data;
if (copy_to_user_fromio(buf, chip->ba1 + pos, count))
return -EFAULT;
return count;
}
static void snd_cs4281_proc_init(struct cs4281 *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "cs4281", &entry))
snd_info_set_text_ops(entry, chip, snd_cs4281_proc_read);
if (! snd_card_proc_new(chip->card, "cs4281_BA0", &entry)) {
entry->content = SNDRV_INFO_CONTENT_DATA;
entry->private_data = chip;
entry->c.ops = &snd_cs4281_proc_ops_BA0;
entry->size = CS4281_BA0_SIZE;
}
if (! snd_card_proc_new(chip->card, "cs4281_BA1", &entry)) {
entry->content = SNDRV_INFO_CONTENT_DATA;
entry->private_data = chip;
entry->c.ops = &snd_cs4281_proc_ops_BA1;
entry->size = CS4281_BA1_SIZE;
}
}
static void snd_cs4281_gameport_trigger(struct gameport *gameport)
{
struct cs4281 *chip = gameport_get_port_data(gameport);
if (snd_BUG_ON(!chip))
return;
snd_cs4281_pokeBA0(chip, BA0_JSPT, 0xff);
}
static unsigned char snd_cs4281_gameport_read(struct gameport *gameport)
{
struct cs4281 *chip = gameport_get_port_data(gameport);
if (snd_BUG_ON(!chip))
return 0;
return snd_cs4281_peekBA0(chip, BA0_JSPT);
}
static int snd_cs4281_gameport_cooked_read(struct gameport *gameport,
int *axes, int *buttons)
{
struct cs4281 *chip = gameport_get_port_data(gameport);
unsigned js1, js2, jst;
if (snd_BUG_ON(!chip))
return 0;
js1 = snd_cs4281_peekBA0(chip, BA0_JSC1);
js2 = snd_cs4281_peekBA0(chip, BA0_JSC2);
jst = snd_cs4281_peekBA0(chip, BA0_JSPT);
*buttons = (~jst >> 4) & 0x0F;
axes[0] = ((js1 & JSC1_Y1V_MASK) >> JSC1_Y1V_SHIFT) & 0xFFFF;
axes[1] = ((js1 & JSC1_X1V_MASK) >> JSC1_X1V_SHIFT) & 0xFFFF;
axes[2] = ((js2 & JSC2_Y2V_MASK) >> JSC2_Y2V_SHIFT) & 0xFFFF;
axes[3] = ((js2 & JSC2_X2V_MASK) >> JSC2_X2V_SHIFT) & 0xFFFF;
for (jst = 0; jst < 4; ++jst)
if (axes[jst] == 0xFFFF) axes[jst] = -1;
return 0;
}
static int snd_cs4281_gameport_open(struct gameport *gameport, int mode)
{
switch (mode) {
#ifdef COOKED_MODE
case GAMEPORT_MODE_COOKED:
return 0;
#endif
case GAMEPORT_MODE_RAW:
return 0;
default:
return -1;
}
return 0;
}
static int snd_cs4281_create_gameport(struct cs4281 *chip)
{
struct gameport *gp;
chip->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "cs4281: cannot allocate memory for gameport\n");
return -ENOMEM;
}
gameport_set_name(gp, "CS4281 Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(chip->pci));
gameport_set_dev_parent(gp, &chip->pci->dev);
gp->open = snd_cs4281_gameport_open;
gp->read = snd_cs4281_gameport_read;
gp->trigger = snd_cs4281_gameport_trigger;
gp->cooked_read = snd_cs4281_gameport_cooked_read;
gameport_set_port_data(gp, chip);
snd_cs4281_pokeBA0(chip, BA0_JSIO, 0xFF);
snd_cs4281_pokeBA0(chip, BA0_JSCTL, JSCTL_SP_MEDIUM_SLOW);
gameport_register_port(gp);
return 0;
}
static void snd_cs4281_free_gameport(struct cs4281 *chip)
{
if (chip->gameport) {
gameport_unregister_port(chip->gameport);
chip->gameport = NULL;
}
}
static inline int snd_cs4281_create_gameport(struct cs4281 *chip) { return -ENOSYS; }
static inline void snd_cs4281_free_gameport(struct cs4281 *chip) { }
static int snd_cs4281_free(struct cs4281 *chip)
{
snd_cs4281_free_gameport(chip);
if (chip->irq >= 0)
synchronize_irq(chip->irq);
snd_cs4281_pokeBA0(chip, BA0_HIMR, 0x7fffffff);
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, 0);
snd_cs4281_pokeBA0(chip, BA0_SSPM, 0);
pci_set_power_state(chip->pci, 3);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->ba0)
iounmap(chip->ba0);
if (chip->ba1)
iounmap(chip->ba1);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_cs4281_dev_free(struct snd_device *device)
{
struct cs4281 *chip = device->device_data;
return snd_cs4281_free(chip);
}
static int snd_cs4281_create(struct snd_card *card,
struct pci_dev *pci,
struct cs4281 **rchip,
int dual_codec)
{
struct cs4281 *chip;
unsigned int tmp;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_cs4281_dev_free,
};
*rchip = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
pci_set_master(pci);
if (dual_codec < 0 || dual_codec > 3) {
snd_printk(KERN_ERR "invalid dual_codec option %d\n", dual_codec);
dual_codec = 0;
}
chip->dual_codec = dual_codec;
if ((err = pci_request_regions(pci, "CS4281")) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->ba0_addr = pci_resource_start(pci, 0);
chip->ba1_addr = pci_resource_start(pci, 1);
chip->ba0 = pci_ioremap_bar(pci, 0);
chip->ba1 = pci_ioremap_bar(pci, 1);
if (!chip->ba0 || !chip->ba1) {
snd_cs4281_free(chip);
return -ENOMEM;
}
if (request_irq(pci->irq, snd_cs4281_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_cs4281_free(chip);
return -ENOMEM;
}
chip->irq = pci->irq;
tmp = snd_cs4281_chip_init(chip);
if (tmp) {
snd_cs4281_free(chip);
return tmp;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_cs4281_free(chip);
return err;
}
snd_cs4281_proc_init(chip);
snd_card_set_dev(card, &pci->dev);
*rchip = chip;
return 0;
}
static int snd_cs4281_chip_init(struct cs4281 *chip)
{
unsigned int tmp;
unsigned long end_time;
int retry_count = 2;
tmp = snd_cs4281_peekBA0(chip, BA0_EPPMC);
if (tmp & BA0_EPPMC_FPDN)
snd_cs4281_pokeBA0(chip, BA0_EPPMC, tmp & ~BA0_EPPMC_FPDN);
__retry:
tmp = snd_cs4281_peekBA0(chip, BA0_CFLR);
if (tmp != BA0_CFLR_DEFAULT) {
snd_cs4281_pokeBA0(chip, BA0_CFLR, BA0_CFLR_DEFAULT);
tmp = snd_cs4281_peekBA0(chip, BA0_CFLR);
if (tmp != BA0_CFLR_DEFAULT) {
snd_printk(KERN_ERR "CFLR setup failed (0x%x)\n", tmp);
return -EIO;
}
}
snd_cs4281_pokeBA0(chip, BA0_CWPR, 0x4281);
if ((tmp = snd_cs4281_peekBA0(chip, BA0_SERC1)) != (BA0_SERC1_SO1EN | BA0_SERC1_AC97)) {
snd_printk(KERN_ERR "SERC1 AC'97 check failed (0x%x)\n", tmp);
return -EIO;
}
if ((tmp = snd_cs4281_peekBA0(chip, BA0_SERC2)) != (BA0_SERC2_SI1EN | BA0_SERC2_AC97)) {
snd_printk(KERN_ERR "SERC2 AC'97 check failed (0x%x)\n", tmp);
return -EIO;
}
snd_cs4281_pokeBA0(chip, BA0_SSPM, BA0_SSPM_MIXEN | BA0_SSPM_CSRCEN |
BA0_SSPM_PSRCEN | BA0_SSPM_JSEN |
BA0_SSPM_ACLEN | BA0_SSPM_FMEN);
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, 0);
snd_cs4281_pokeBA0(chip, BA0_SERMC, 0);
snd_cs4281_pokeBA0(chip, BA0_ACCTL, 0);
udelay(50);
snd_cs4281_pokeBA0(chip, BA0_SPMC, 0);
udelay(50);
snd_cs4281_pokeBA0(chip, BA0_SPMC, BA0_SPMC_RSTN);
msleep(50);
if (chip->dual_codec)
snd_cs4281_pokeBA0(chip, BA0_SPMC, BA0_SPMC_RSTN | BA0_SPMC_ASDI2E);
snd_cs4281_pokeBA0(chip, BA0_SERMC,
(chip->dual_codec ? BA0_SERMC_TCID(chip->dual_codec) : BA0_SERMC_TCID(1)) |
BA0_SERMC_PTC_AC97 | BA0_SERMC_MSPE);
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, BA0_CLKCR1_DLLP);
msleep(50);
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, BA0_CLKCR1_SWCE | BA0_CLKCR1_DLLP);
end_time = jiffies + HZ;
do {
if (snd_cs4281_peekBA0(chip, BA0_CLKCR1) & BA0_CLKCR1_DLLRDY)
goto __ok0;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
snd_printk(KERN_ERR "DLLRDY not seen\n");
return -EIO;
__ok0:
snd_cs4281_pokeBA0(chip, BA0_ACCTL, BA0_ACCTL_ESYN);
end_time = jiffies + HZ;
do {
if (snd_cs4281_peekBA0(chip, BA0_ACSTS) & BA0_ACSTS_CRDY)
goto __ok1;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
snd_printk(KERN_ERR "never read codec ready from AC'97 (0x%x)\n", snd_cs4281_peekBA0(chip, BA0_ACSTS));
return -EIO;
__ok1:
if (chip->dual_codec) {
end_time = jiffies + HZ;
do {
if (snd_cs4281_peekBA0(chip, BA0_ACSTS2) & BA0_ACSTS_CRDY)
goto __codec2_ok;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
snd_printk(KERN_INFO "secondary codec doesn't respond. disable it...\n");
chip->dual_codec = 0;
__codec2_ok: ;
}
snd_cs4281_pokeBA0(chip, BA0_ACCTL, BA0_ACCTL_VFRM | BA0_ACCTL_ESYN);
end_time = jiffies + HZ;
do {
if ((snd_cs4281_peekBA0(chip, BA0_ACISV) & (BA0_ACISV_SLV(3) | BA0_ACISV_SLV(4))) == (BA0_ACISV_SLV(3) | BA0_ACISV_SLV(4)))
goto __ok2;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
if (--retry_count > 0)
goto __retry;
snd_printk(KERN_ERR "never read ISV3 and ISV4 from AC'97\n");
return -EIO;
__ok2:
snd_cs4281_pokeBA0(chip, BA0_ACOSV, BA0_ACOSV_SLV(3) | BA0_ACOSV_SLV(4));
for (tmp = 0; tmp < 4; tmp++) {
struct cs4281_dma *dma = &chip->dma[tmp];
dma->regDBA = BA0_DBA0 + (tmp * 0x10);
dma->regDCA = BA0_DCA0 + (tmp * 0x10);
dma->regDBC = BA0_DBC0 + (tmp * 0x10);
dma->regDCC = BA0_DCC0 + (tmp * 0x10);
dma->regDMR = BA0_DMR0 + (tmp * 8);
dma->regDCR = BA0_DCR0 + (tmp * 8);
dma->regHDSR = BA0_HDSR0 + (tmp * 4);
dma->regFCR = BA0_FCR0 + (tmp * 4);
dma->regFSIC = BA0_FSIC0 + (tmp * 4);
dma->fifo_offset = tmp * CS4281_FIFO_SIZE;
snd_cs4281_pokeBA0(chip, dma->regFCR,
BA0_FCR_LS(31) |
BA0_FCR_RS(31) |
BA0_FCR_SZ(CS4281_FIFO_SIZE) |
BA0_FCR_OF(dma->fifo_offset));
}
chip->src_left_play_slot = 0;
chip->src_right_play_slot = 1;
chip->src_left_rec_slot = 10;
chip->src_right_rec_slot = 11;
chip->dma[0].valFCR = BA0_FCR_FEN | BA0_FCR_LS(0) |
BA0_FCR_RS(1) |
BA0_FCR_SZ(CS4281_FIFO_SIZE) |
BA0_FCR_OF(chip->dma[0].fifo_offset);
snd_cs4281_pokeBA0(chip, chip->dma[0].regFCR, chip->dma[0].valFCR);
snd_cs4281_pokeBA0(chip, BA0_SRCSA, (chip->src_left_play_slot << 0) |
(chip->src_right_play_slot << 8) |
(chip->src_left_rec_slot << 16) |
(chip->src_right_rec_slot << 24));
snd_cs4281_pokeBA0(chip, BA0_PPLVC, 0);
snd_cs4281_pokeBA0(chip, BA0_PPRVC, 0);
snd_cs4281_pokeBA0(chip, BA0_HICR, BA0_HICR_EOI);
snd_cs4281_pokeBA0(chip, BA0_HIMR, 0x7fffffff & ~(
BA0_HISR_MIDI |
BA0_HISR_DMAI |
BA0_HISR_DMA(0) |
BA0_HISR_DMA(1) |
BA0_HISR_DMA(2) |
BA0_HISR_DMA(3)));
synchronize_irq(chip->irq);
return 0;
}
static void snd_cs4281_midi_reset(struct cs4281 *chip)
{
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr | BA0_MIDCR_MRST);
udelay(100);
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
static int snd_cs4281_midi_input_open(struct snd_rawmidi_substream *substream)
{
struct cs4281 *chip = substream->rmidi->private_data;
spin_lock_irq(&chip->reg_lock);
chip->midcr |= BA0_MIDCR_RXE;
chip->midi_input = substream;
if (!(chip->uartm & CS4281_MODE_OUTPUT)) {
snd_cs4281_midi_reset(chip);
} else {
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_cs4281_midi_input_close(struct snd_rawmidi_substream *substream)
{
struct cs4281 *chip = substream->rmidi->private_data;
spin_lock_irq(&chip->reg_lock);
chip->midcr &= ~(BA0_MIDCR_RXE | BA0_MIDCR_RIE);
chip->midi_input = NULL;
if (!(chip->uartm & CS4281_MODE_OUTPUT)) {
snd_cs4281_midi_reset(chip);
} else {
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
chip->uartm &= ~CS4281_MODE_INPUT;
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_cs4281_midi_output_open(struct snd_rawmidi_substream *substream)
{
struct cs4281 *chip = substream->rmidi->private_data;
spin_lock_irq(&chip->reg_lock);
chip->uartm |= CS4281_MODE_OUTPUT;
chip->midcr |= BA0_MIDCR_TXE;
chip->midi_output = substream;
if (!(chip->uartm & CS4281_MODE_INPUT)) {
snd_cs4281_midi_reset(chip);
} else {
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_cs4281_midi_output_close(struct snd_rawmidi_substream *substream)
{
struct cs4281 *chip = substream->rmidi->private_data;
spin_lock_irq(&chip->reg_lock);
chip->midcr &= ~(BA0_MIDCR_TXE | BA0_MIDCR_TIE);
chip->midi_output = NULL;
if (!(chip->uartm & CS4281_MODE_INPUT)) {
snd_cs4281_midi_reset(chip);
} else {
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
chip->uartm &= ~CS4281_MODE_OUTPUT;
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static void snd_cs4281_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
unsigned long flags;
struct cs4281 *chip = substream->rmidi->private_data;
spin_lock_irqsave(&chip->reg_lock, flags);
if (up) {
if ((chip->midcr & BA0_MIDCR_RIE) == 0) {
chip->midcr |= BA0_MIDCR_RIE;
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
} else {
if (chip->midcr & BA0_MIDCR_RIE) {
chip->midcr &= ~BA0_MIDCR_RIE;
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static void snd_cs4281_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
unsigned long flags;
struct cs4281 *chip = substream->rmidi->private_data;
unsigned char byte;
spin_lock_irqsave(&chip->reg_lock, flags);
if (up) {
if ((chip->midcr & BA0_MIDCR_TIE) == 0) {
chip->midcr |= BA0_MIDCR_TIE;
while ((chip->midcr & BA0_MIDCR_TIE) &&
(snd_cs4281_peekBA0(chip, BA0_MIDSR) & BA0_MIDSR_TBF) == 0) {
if (snd_rawmidi_transmit(substream, &byte, 1) != 1) {
chip->midcr &= ~BA0_MIDCR_TIE;
} else {
snd_cs4281_pokeBA0(chip, BA0_MIDWP, byte);
}
}
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
} else {
if (chip->midcr & BA0_MIDCR_TIE) {
chip->midcr &= ~BA0_MIDCR_TIE;
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static int snd_cs4281_midi(struct cs4281 *chip, int device,
struct snd_rawmidi **rrawmidi)
{
struct snd_rawmidi *rmidi;
int err;
if (rrawmidi)
*rrawmidi = NULL;
if ((err = snd_rawmidi_new(chip->card, "CS4281", device, 1, 1, &rmidi)) < 0)
return err;
strcpy(rmidi->name, "CS4281");
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &snd_cs4281_midi_output);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &snd_cs4281_midi_input);
rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT | SNDRV_RAWMIDI_INFO_INPUT | SNDRV_RAWMIDI_INFO_DUPLEX;
rmidi->private_data = chip;
chip->rmidi = rmidi;
if (rrawmidi)
*rrawmidi = rmidi;
return 0;
}
static irqreturn_t snd_cs4281_interrupt(int irq, void *dev_id)
{
struct cs4281 *chip = dev_id;
unsigned int status, dma, val;
struct cs4281_dma *cdma;
if (chip == NULL)
return IRQ_NONE;
status = snd_cs4281_peekBA0(chip, BA0_HISR);
if ((status & 0x7fffffff) == 0) {
snd_cs4281_pokeBA0(chip, BA0_HICR, BA0_HICR_EOI);
return IRQ_NONE;
}
if (status & (BA0_HISR_DMA(0)|BA0_HISR_DMA(1)|BA0_HISR_DMA(2)|BA0_HISR_DMA(3))) {
for (dma = 0; dma < 4; dma++)
if (status & BA0_HISR_DMA(dma)) {
cdma = &chip->dma[dma];
spin_lock(&chip->reg_lock);
val = snd_cs4281_peekBA0(chip, cdma->regHDSR);
cdma->frag++;
if ((val & BA0_HDSR_DHTC) && !(cdma->frag & 1)) {
cdma->frag--;
chip->spurious_dhtc_irq++;
spin_unlock(&chip->reg_lock);
continue;
}
if ((val & BA0_HDSR_DTC) && (cdma->frag & 1)) {
cdma->frag--;
chip->spurious_dtc_irq++;
spin_unlock(&chip->reg_lock);
continue;
}
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(cdma->substream);
}
}
if ((status & BA0_HISR_MIDI) && chip->rmidi) {
unsigned char c;
spin_lock(&chip->reg_lock);
while ((snd_cs4281_peekBA0(chip, BA0_MIDSR) & BA0_MIDSR_RBE) == 0) {
c = snd_cs4281_peekBA0(chip, BA0_MIDRP);
if ((chip->midcr & BA0_MIDCR_RIE) == 0)
continue;
snd_rawmidi_receive(chip->midi_input, &c, 1);
}
while ((snd_cs4281_peekBA0(chip, BA0_MIDSR) & BA0_MIDSR_TBF) == 0) {
if ((chip->midcr & BA0_MIDCR_TIE) == 0)
break;
if (snd_rawmidi_transmit(chip->midi_output, &c, 1) != 1) {
chip->midcr &= ~BA0_MIDCR_TIE;
snd_cs4281_pokeBA0(chip, BA0_MIDCR, chip->midcr);
break;
}
snd_cs4281_pokeBA0(chip, BA0_MIDWP, c);
}
spin_unlock(&chip->reg_lock);
}
snd_cs4281_pokeBA0(chip, BA0_HICR, BA0_HICR_EOI);
return IRQ_HANDLED;
}
static void snd_cs4281_opl3_command(struct snd_opl3 *opl3, unsigned short cmd,
unsigned char val)
{
unsigned long flags;
struct cs4281 *chip = opl3->private_data;
void __iomem *port;
if (cmd & OPL3_RIGHT)
port = chip->ba0 + BA0_B1AP;
else
port = chip->ba0 + BA0_B0AP;
spin_lock_irqsave(&opl3->reg_lock, flags);
writel((unsigned int)cmd, port);
udelay(10);
writel((unsigned int)val, port + 4);
udelay(30);
spin_unlock_irqrestore(&opl3->reg_lock, flags);
}
static int snd_cs4281_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct cs4281 *chip;
struct snd_opl3 *opl3;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
if ((err = snd_cs4281_create(card, pci, &chip, dual_codec[dev])) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
if ((err = snd_cs4281_mixer(chip)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_cs4281_pcm(chip, 0, NULL)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_cs4281_midi(chip, 0, NULL)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_opl3_new(card, OPL3_HW_OPL3_CS4281, &opl3)) < 0) {
snd_card_free(card);
return err;
}
opl3->private_data = chip;
opl3->command = snd_cs4281_opl3_command;
snd_opl3_init(opl3);
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0) {
snd_card_free(card);
return err;
}
snd_cs4281_create_gameport(chip);
strcpy(card->driver, "CS4281");
strcpy(card->shortname, "Cirrus Logic CS4281");
sprintf(card->longname, "%s at 0x%lx, irq %d",
card->shortname,
chip->ba0_addr,
chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_cs4281_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int cs4281_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct cs4281 *chip = card->private_data;
u32 ulCLK;
unsigned int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
snd_ac97_suspend(chip->ac97_secondary);
ulCLK = snd_cs4281_peekBA0(chip, BA0_CLKCR1);
ulCLK |= CLKCR1_CKRA;
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, ulCLK);
snd_cs4281_pokeBA0(chip, BA0_HICR, BA0_HICR_CHGM);
for (i = 0; i < ARRAY_SIZE(saved_regs); i++)
if (saved_regs[i])
chip->suspend_regs[i] = snd_cs4281_peekBA0(chip, saved_regs[i]);
snd_cs4281_pokeBA0(chip, BA0_SERMC, 0);
snd_cs4281_pokeBA0(chip, BA0_SSPM, 0);
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, 0);
snd_cs4281_pokeBA0(chip, BA0_SPMC, 0);
ulCLK = snd_cs4281_peekBA0(chip, BA0_CLKCR1);
ulCLK &= ~CLKCR1_CKRA;
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, ulCLK);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int cs4281_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct cs4281 *chip = card->private_data;
unsigned int i;
u32 ulCLK;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "cs4281: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
ulCLK = snd_cs4281_peekBA0(chip, BA0_CLKCR1);
ulCLK |= CLKCR1_CKRA;
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, ulCLK);
snd_cs4281_chip_init(chip);
for (i = 0; i < ARRAY_SIZE(saved_regs); i++)
if (saved_regs[i])
snd_cs4281_pokeBA0(chip, saved_regs[i], chip->suspend_regs[i]);
snd_ac97_resume(chip->ac97);
snd_ac97_resume(chip->ac97_secondary);
ulCLK = snd_cs4281_peekBA0(chip, BA0_CLKCR1);
ulCLK &= ~CLKCR1_CKRA;
snd_cs4281_pokeBA0(chip, BA0_CLKCR1, ulCLK);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
