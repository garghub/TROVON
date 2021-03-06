static inline u32 read_reg(unsigned int reg)
{
return in_be32(the_card.mapped_mmio_vaddr + reg);
}
static inline void write_reg(unsigned int reg, u32 val)
{
out_be32(the_card.mapped_mmio_vaddr + reg, val);
}
static inline void update_reg(unsigned int reg, u32 or_val)
{
u32 newval = read_reg(reg) | or_val;
write_reg(reg, newval);
}
static inline void update_mask_reg(unsigned int reg, u32 mask, u32 or_val)
{
u32 newval = (read_reg(reg) & mask) | or_val;
write_reg(reg, newval);
}
static int snd_ps3_verify_dma_stop(struct snd_ps3_card_info *card,
int count, int force_stop)
{
int dma_ch, done, retries, stop_forced = 0;
uint32_t status;
for (dma_ch = 0; dma_ch < 8; dma_ch++) {
retries = count;
do {
status = read_reg(PS3_AUDIO_KICK(dma_ch)) &
PS3_AUDIO_KICK_STATUS_MASK;
switch (status) {
case PS3_AUDIO_KICK_STATUS_DONE:
case PS3_AUDIO_KICK_STATUS_NOTIFY:
case PS3_AUDIO_KICK_STATUS_CLEAR:
case PS3_AUDIO_KICK_STATUS_ERROR:
done = 1;
break;
default:
done = 0;
udelay(10);
}
} while (!done && --retries);
if (!retries && force_stop) {
pr_info("%s: DMA ch %d is not stopped.",
__func__, dma_ch);
update_reg(PS3_AUDIO_CONFIG, PS3_AUDIO_CONFIG_CLEAR);
stop_forced = 1;
}
}
return stop_forced;
}
static void snd_ps3_wait_for_dma_stop(struct snd_ps3_card_info *card)
{
int stop_forced;
stop_forced = snd_ps3_verify_dma_stop(card, 700, 1);
update_reg(PS3_AUDIO_INTR_0, 0);
update_reg(PS3_AUDIO_AX_IS, 0);
if (stop_forced)
update_mask_reg(PS3_AUDIO_CONFIG, ~PS3_AUDIO_CONFIG_CLEAR, 0);
wmb();
}
static void snd_ps3_kick_dma(struct snd_ps3_card_info *card)
{
update_reg(PS3_AUDIO_KICK(0), PS3_AUDIO_KICK_REQUEST);
wmb();
}
static dma_addr_t v_to_bus(struct snd_ps3_card_info *card, void *paddr, int ch)
{
return card->dma_start_bus_addr[ch] +
(paddr - card->dma_start_vaddr[ch]);
}
static void snd_ps3_bump_buffer(struct snd_ps3_card_info *card,
enum snd_ps3_ch ch, size_t byte_count,
int stage)
{
if (!stage)
card->dma_last_transfer_vaddr[ch] =
card->dma_next_transfer_vaddr[ch];
card->dma_next_transfer_vaddr[ch] += byte_count;
if ((card->dma_start_vaddr[ch] + (card->dma_buffer_size / 2)) <=
card->dma_next_transfer_vaddr[ch]) {
card->dma_next_transfer_vaddr[ch] = card->dma_start_vaddr[ch];
}
}
static int snd_ps3_program_dma(struct snd_ps3_card_info *card,
enum snd_ps3_dma_filltype filltype)
{
uint32_t dma_addr;
int fill_stages, dma_ch, stage;
enum snd_ps3_ch ch;
uint32_t ch0_kick_event = 0;
void *start_vaddr;
unsigned long irqsave;
int silent = 0;
switch (filltype) {
case SND_PS3_DMA_FILLTYPE_SILENT_FIRSTFILL:
silent = 1;
case SND_PS3_DMA_FILLTYPE_FIRSTFILL:
ch0_kick_event = PS3_AUDIO_KICK_EVENT_ALWAYS;
break;
case SND_PS3_DMA_FILLTYPE_SILENT_RUNNING:
silent = 1;
case SND_PS3_DMA_FILLTYPE_RUNNING:
ch0_kick_event = PS3_AUDIO_KICK_EVENT_SERIALOUT0_EMPTY;
break;
}
snd_ps3_verify_dma_stop(card, 700, 0);
fill_stages = 4;
spin_lock_irqsave(&card->dma_lock, irqsave);
for (ch = 0; ch < 2; ch++) {
start_vaddr = card->dma_next_transfer_vaddr[0];
for (stage = 0; stage < fill_stages; stage++) {
dma_ch = stage * 2 + ch;
if (silent)
dma_addr = card->null_buffer_start_dma_addr;
else
dma_addr =
v_to_bus(card,
card->dma_next_transfer_vaddr[ch],
ch);
write_reg(PS3_AUDIO_SOURCE(dma_ch),
(PS3_AUDIO_SOURCE_TARGET_SYSTEM_MEMORY |
dma_addr));
if (ch == 0)
write_reg(PS3_AUDIO_DEST(dma_ch),
(PS3_AUDIO_DEST_TARGET_AUDIOFIFO |
PS3_AUDIO_AO_3W_LDATA(0)));
else
write_reg(PS3_AUDIO_DEST(dma_ch),
(PS3_AUDIO_DEST_TARGET_AUDIOFIFO |
PS3_AUDIO_AO_3W_RDATA(0)));
write_reg(PS3_AUDIO_DMASIZE(dma_ch), 0);
if (!silent)
snd_ps3_bump_buffer(card, ch,
PS3_AUDIO_DMAC_BLOCK_SIZE,
stage);
if (dma_ch == 0)
write_reg(PS3_AUDIO_KICK(dma_ch),
ch0_kick_event);
else
write_reg(PS3_AUDIO_KICK(dma_ch),
PS3_AUDIO_KICK_EVENT_AUDIO_DMA(dma_ch
- 1) |
PS3_AUDIO_KICK_REQUEST);
}
}
wmb();
spin_unlock_irqrestore(&card->dma_lock, irqsave);
return 0;
}
static irqreturn_t snd_ps3_interrupt(int irq, void *dev_id)
{
uint32_t port_intr;
int underflow_occured = 0;
struct snd_ps3_card_info *card = dev_id;
if (!card->running) {
update_reg(PS3_AUDIO_AX_IS, 0);
update_reg(PS3_AUDIO_INTR_0, 0);
return IRQ_HANDLED;
}
port_intr = read_reg(PS3_AUDIO_AX_IS);
if (port_intr & PS3_AUDIO_AX_IE_ASOBEIE(0)) {
write_reg(PS3_AUDIO_AX_IS, PS3_AUDIO_AX_IE_ASOBEIE(0));
if (port_intr & PS3_AUDIO_AX_IE_ASOBUIE(0)) {
write_reg(PS3_AUDIO_AX_IS, port_intr);
underflow_occured = 1;
}
if (card->silent) {
snd_ps3_program_dma(card,
(underflow_occured) ?
SND_PS3_DMA_FILLTYPE_SILENT_FIRSTFILL :
SND_PS3_DMA_FILLTYPE_SILENT_RUNNING);
snd_ps3_kick_dma(card);
card->silent--;
} else {
snd_ps3_program_dma(card,
(underflow_occured) ?
SND_PS3_DMA_FILLTYPE_FIRSTFILL :
SND_PS3_DMA_FILLTYPE_RUNNING);
snd_ps3_kick_dma(card);
snd_pcm_period_elapsed(card->substream);
}
} else if (port_intr & PS3_AUDIO_AX_IE_ASOBUIE(0)) {
write_reg(PS3_AUDIO_AX_IS, PS3_AUDIO_AX_IE_ASOBUIE(0));
snd_ps3_program_dma(card,
SND_PS3_DMA_FILLTYPE_SILENT_FIRSTFILL);
snd_ps3_kick_dma(card);
snd_ps3_program_dma(card,
SND_PS3_DMA_FILLTYPE_SILENT_FIRSTFILL);
snd_ps3_kick_dma(card);
}
return IRQ_HANDLED;
}
static int snd_ps3_mute(int mute_on)
{
return ps3av_audio_mute(mute_on);
}
static int snd_ps3_change_avsetting(struct snd_ps3_card_info *card)
{
int ret, retries, i;
pr_debug("%s: start\n", __func__);
ret = ps3av_set_audio_mode(card->avs.avs_audio_ch,
card->avs.avs_audio_rate,
card->avs.avs_audio_width,
card->avs.avs_audio_format,
card->avs.avs_audio_source);
update_mask_reg(PS3_AUDIO_AO_3WMCTRL,
~(PS3_AUDIO_AO_3WMCTRL_ASOEN(0) |
PS3_AUDIO_AO_3WMCTRL_ASOEN(1) |
PS3_AUDIO_AO_3WMCTRL_ASOEN(2) |
PS3_AUDIO_AO_3WMCTRL_ASOEN(3)),
0);
wmb();
retries = 1000;
while ((read_reg(PS3_AUDIO_AO_3WMCTRL) &
(PS3_AUDIO_AO_3WMCTRL_ASORUN(0) |
PS3_AUDIO_AO_3WMCTRL_ASORUN(1) |
PS3_AUDIO_AO_3WMCTRL_ASORUN(2) |
PS3_AUDIO_AO_3WMCTRL_ASORUN(3))) &&
--retries) {
udelay(1);
}
for (i = 0; i < 4; i++) {
update_reg(PS3_AUDIO_AO_3WCTRL(i),
PS3_AUDIO_AO_3WCTRL_ASOBRST_RESET);
udelay(10);
}
wmb();
update_reg(PS3_AUDIO_AO_3WMCTRL, PS3_AUDIO_AO_3WMCTRL_ASOEN(0));
update_mask_reg(PS3_AUDIO_AO_3WCTRL(0),
~PS3_AUDIO_AO_3WCTRL_ASODF,
PS3_AUDIO_AO_3WCTRL_ASODF_LSB);
update_mask_reg(PS3_AUDIO_AO_SPDCTRL(0),
~PS3_AUDIO_AO_SPDCTRL_SPODF,
PS3_AUDIO_AO_SPDCTRL_SPODF_LSB);
wmb();
pr_debug("%s: end\n", __func__);
return ret;
}
static int snd_ps3_set_avsetting(struct snd_pcm_substream *substream)
{
struct snd_ps3_card_info *card = snd_pcm_substream_chip(substream);
struct snd_ps3_avsetting_info avs;
int ret;
avs = card->avs;
pr_debug("%s: called freq=%d width=%d\n", __func__,
substream->runtime->rate,
snd_pcm_format_width(substream->runtime->format));
pr_debug("%s: before freq=%d width=%d\n", __func__,
card->avs.avs_audio_rate, card->avs.avs_audio_width);
switch (substream->runtime->rate) {
case 44100:
avs.avs_audio_rate = PS3AV_CMD_AUDIO_FS_44K;
break;
case 48000:
avs.avs_audio_rate = PS3AV_CMD_AUDIO_FS_48K;
break;
case 88200:
avs.avs_audio_rate = PS3AV_CMD_AUDIO_FS_88K;
break;
case 96000:
avs.avs_audio_rate = PS3AV_CMD_AUDIO_FS_96K;
break;
default:
pr_info("%s: invalid rate %d\n", __func__,
substream->runtime->rate);
return 1;
}
switch (snd_pcm_format_width(substream->runtime->format)) {
case 16:
avs.avs_audio_width = PS3AV_CMD_AUDIO_WORD_BITS_16;
break;
case 24:
avs.avs_audio_width = PS3AV_CMD_AUDIO_WORD_BITS_24;
break;
default:
pr_info("%s: invalid width %d\n", __func__,
snd_pcm_format_width(substream->runtime->format));
return 1;
}
memcpy(avs.avs_cs_info, ps3av_mode_cs_info, 8);
if (memcmp(&card->avs, &avs, sizeof(avs))) {
pr_debug("%s: after freq=%d width=%d\n", __func__,
card->avs.avs_audio_rate, card->avs.avs_audio_width);
card->avs = avs;
snd_ps3_change_avsetting(card);
ret = 0;
} else
ret = 1;
if (avs.avs_cs_info[0] & 0x02)
ps3av_audio_mute_analog(1);
else
ps3av_audio_mute_analog(0);
return ret;
}
static int snd_ps3_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ps3_card_info *card = snd_pcm_substream_chip(substream);
int pcm_index;
pcm_index = substream->pcm->device;
card->substream = substream;
runtime->hw = snd_ps3_pcm_hw;
card->start_delay = snd_ps3_start_delay;
snd_ps3_mute(0);
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
PS3_AUDIO_FIFO_STAGE_SIZE * 4 * 2);
return 0;
}
static int snd_ps3_pcm_close(struct snd_pcm_substream *substream)
{
snd_ps3_mute(1);
return 0;
}
static int snd_ps3_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
size_t size;
size = params_buffer_bytes(hw_params);
snd_pcm_lib_malloc_pages(substream, size);
return 0;
}
static int snd_ps3_pcm_hw_free(struct snd_pcm_substream *substream)
{
int ret;
ret = snd_pcm_lib_free_pages(substream);
return ret;
}
static int snd_ps3_delay_to_bytes(struct snd_pcm_substream *substream,
unsigned int delay_ms)
{
int ret;
int rate ;
rate = substream->runtime->rate;
ret = snd_pcm_format_size(substream->runtime->format,
rate * delay_ms / 1000)
* substream->runtime->channels;
pr_debug("%s: time=%d rate=%d bytes=%ld, frames=%d, ret=%d\n",
__func__,
delay_ms,
rate,
snd_pcm_format_size(substream->runtime->format, rate),
rate * delay_ms / 1000,
ret);
return ret;
}
static int snd_ps3_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ps3_card_info *card = snd_pcm_substream_chip(substream);
unsigned long irqsave;
if (!snd_ps3_set_avsetting(substream)) {
write_reg(PS3_AUDIO_AX_IE,
PS3_AUDIO_AX_IE_ASOBEIE(0) |
PS3_AUDIO_AX_IE_ASOBUIE(0));
card->silent = snd_ps3_delay_to_bytes(substream,
card->start_delay) /
(PS3_AUDIO_FIFO_STAGE_SIZE * 4);
}
spin_lock_irqsave(&card->dma_lock, irqsave);
{
card->dma_buffer_size = runtime->dma_bytes;
card->dma_last_transfer_vaddr[SND_PS3_CH_L] =
card->dma_next_transfer_vaddr[SND_PS3_CH_L] =
card->dma_start_vaddr[SND_PS3_CH_L] =
runtime->dma_area;
card->dma_start_bus_addr[SND_PS3_CH_L] = runtime->dma_addr;
card->dma_last_transfer_vaddr[SND_PS3_CH_R] =
card->dma_next_transfer_vaddr[SND_PS3_CH_R] =
card->dma_start_vaddr[SND_PS3_CH_R] =
runtime->dma_area + (runtime->dma_bytes / 2);
card->dma_start_bus_addr[SND_PS3_CH_R] =
runtime->dma_addr + (runtime->dma_bytes / 2);
pr_debug("%s: vaddr=%p bus=%#llx\n", __func__,
card->dma_start_vaddr[SND_PS3_CH_L],
card->dma_start_bus_addr[SND_PS3_CH_L]);
}
spin_unlock_irqrestore(&card->dma_lock, irqsave);
mb();
return 0;
}
static int snd_ps3_pcm_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_ps3_card_info *card = snd_pcm_substream_chip(substream);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
update_reg(PS3_AUDIO_AX_IS, 0);
spin_lock(&card->dma_lock);
{
card->running = 1;
}
spin_unlock(&card->dma_lock);
snd_ps3_program_dma(card,
SND_PS3_DMA_FILLTYPE_SILENT_FIRSTFILL);
snd_ps3_kick_dma(card);
while (read_reg(PS3_AUDIO_KICK(7)) &
PS3_AUDIO_KICK_STATUS_MASK) {
udelay(1);
}
snd_ps3_program_dma(card, SND_PS3_DMA_FILLTYPE_SILENT_RUNNING);
snd_ps3_kick_dma(card);
break;
case SNDRV_PCM_TRIGGER_STOP:
spin_lock(&card->dma_lock);
{
card->running = 0;
}
spin_unlock(&card->dma_lock);
snd_ps3_wait_for_dma_stop(card);
break;
default:
break;
}
return ret;
}
static snd_pcm_uframes_t snd_ps3_pcm_pointer(
struct snd_pcm_substream *substream)
{
struct snd_ps3_card_info *card = snd_pcm_substream_chip(substream);
size_t bytes;
snd_pcm_uframes_t ret;
spin_lock(&card->dma_lock);
{
bytes = (size_t)(card->dma_last_transfer_vaddr[SND_PS3_CH_L] -
card->dma_start_vaddr[SND_PS3_CH_L]);
}
spin_unlock(&card->dma_lock);
ret = bytes_to_frames(substream->runtime, bytes * 2);
return ret;
}
static int snd_ps3_spdif_mask_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_ps3_spdif_cmask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
memset(ucontrol->value.iec958.status, 0xff, 8);
return 0;
}
static int snd_ps3_spdif_pmask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return 0;
}
static int snd_ps3_spdif_default_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
memcpy(ucontrol->value.iec958.status, ps3av_mode_cs_info, 8);
return 0;
}
static int snd_ps3_spdif_default_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
if (memcmp(ps3av_mode_cs_info, ucontrol->value.iec958.status, 8)) {
memcpy(ps3av_mode_cs_info, ucontrol->value.iec958.status, 8);
return 1;
}
return 0;
}
static int snd_ps3_map_mmio(void)
{
the_card.mapped_mmio_vaddr =
ioremap(the_card.ps3_dev->m_region->bus_addr,
the_card.ps3_dev->m_region->len);
if (!the_card.mapped_mmio_vaddr) {
pr_info("%s: ioremap 0 failed p=%#lx l=%#lx \n",
__func__, the_card.ps3_dev->m_region->lpar_addr,
the_card.ps3_dev->m_region->len);
return -ENXIO;
}
return 0;
}
static void snd_ps3_unmap_mmio(void)
{
iounmap(the_card.mapped_mmio_vaddr);
the_card.mapped_mmio_vaddr = NULL;
}
static int snd_ps3_allocate_irq(void)
{
int ret;
u64 lpar_addr, lpar_size;
u64 __iomem *mapped;
ret = lv1_gpu_device_map(1, &lpar_addr, &lpar_size);
if (ret) {
pr_info("%s: device map 1 failed %d\n", __func__,
ret);
return -ENXIO;
}
mapped = ioremap(lpar_addr, lpar_size);
if (!mapped) {
pr_info("%s: ioremap 1 failed \n", __func__);
return -ENXIO;
}
the_card.audio_irq_outlet = in_be64(mapped);
iounmap(mapped);
ret = lv1_gpu_device_unmap(1);
if (ret)
pr_info("%s: unmap 1 failed\n", __func__);
ret = ps3_irq_plug_setup(PS3_BINDING_CPU_ANY,
the_card.audio_irq_outlet,
&the_card.irq_no);
if (ret) {
pr_info("%s:ps3_alloc_irq failed (%d)\n", __func__, ret);
return ret;
}
ret = request_irq(the_card.irq_no, snd_ps3_interrupt, 0,
SND_PS3_DRIVER_NAME, &the_card);
if (ret) {
pr_info("%s: request_irq failed (%d)\n", __func__, ret);
goto cleanup_irq;
}
return 0;
cleanup_irq:
ps3_irq_plug_destroy(the_card.irq_no);
return ret;
}
static void snd_ps3_free_irq(void)
{
free_irq(the_card.irq_no, &the_card);
ps3_irq_plug_destroy(the_card.irq_no);
}
static void snd_ps3_audio_set_base_addr(uint64_t ioaddr_start)
{
uint64_t val;
int ret;
val = (ioaddr_start & (0x0fUL << 32)) >> (32 - 20) |
(0x03UL << 24) |
(0x0fUL << 12) |
(PS3_AUDIO_IOID);
ret = lv1_gpu_attribute(0x100, 0x007, val);
if (ret)
pr_info("%s: gpu_attribute failed %d\n", __func__,
ret);
}
static void snd_ps3_audio_fixup(struct snd_ps3_card_info *card)
{
write_reg(PS3_AUDIO_INTR_EN_0, 0);
update_mask_reg(PS3_AUDIO_AX_IC,
PS3_AUDIO_AX_IC_AASOIMD_MASK,
PS3_AUDIO_AX_IC_AASOIMD_EVERY4);
update_mask_reg(PS3_AUDIO_AO_3WMCTRL,
~(PS3_AUDIO_AO_3WMCTRL_ASOBCLKD_DISABLED |
PS3_AUDIO_AO_3WMCTRL_ASOLRCKD_DISABLED),
0);
update_reg(PS3_AUDIO_AO_3WMCTRL,
PS3_AUDIO_AO_3WMCTRL_ASOPLRCK_DEFAULT);
}
static int snd_ps3_init_avsetting(struct snd_ps3_card_info *card)
{
int ret;
pr_debug("%s: start\n", __func__);
card->avs.avs_audio_ch = PS3AV_CMD_AUDIO_NUM_OF_CH_2;
card->avs.avs_audio_rate = PS3AV_CMD_AUDIO_FS_48K;
card->avs.avs_audio_width = PS3AV_CMD_AUDIO_WORD_BITS_16;
card->avs.avs_audio_format = PS3AV_CMD_AUDIO_FORMAT_PCM;
card->avs.avs_audio_source = PS3AV_CMD_AUDIO_SOURCE_SERIAL;
memcpy(card->avs.avs_cs_info, ps3av_mode_cs_info, 8);
ret = snd_ps3_change_avsetting(card);
snd_ps3_audio_fixup(card);
snd_ps3_program_dma(card, SND_PS3_DMA_FILLTYPE_SILENT_FIRSTFILL);
snd_ps3_kick_dma(card);
pr_debug("%s: end\n", __func__);
return ret;
}
static int snd_ps3_driver_probe(struct ps3_system_bus_device *dev)
{
int i, ret;
u64 lpar_addr, lpar_size;
BUG_ON(!firmware_has_feature(FW_FEATURE_PS3_LV1));
BUG_ON(dev->match_id != PS3_MATCH_ID_SOUND);
the_card.ps3_dev = dev;
ret = ps3_open_hv_device(dev);
if (ret)
return -ENXIO;
ret = lv1_gpu_device_map(2, &lpar_addr, &lpar_size);
if (ret) {
pr_info("%s: device map 2 failed %d\n", __func__, ret);
goto clean_open;
}
ps3_mmio_region_init(dev, dev->m_region, lpar_addr, lpar_size,
PAGE_SHIFT);
ret = snd_ps3_map_mmio();
if (ret)
goto clean_dev_map;
ps3_dma_region_init(dev, dev->d_region,
PAGE_SHIFT,
0,
NULL,
_ALIGN_UP(SND_PS3_DMA_REGION_SIZE, PAGE_SIZE));
dev->d_region->ioid = PS3_AUDIO_IOID;
ret = ps3_dma_region_create(dev->d_region);
if (ret) {
pr_info("%s: region_create\n", __func__);
goto clean_mmio;
}
snd_ps3_audio_set_base_addr(dev->d_region->bus_addr);
the_card.start_delay = snd_ps3_start_delay;
if (snd_ps3_allocate_irq()) {
ret = -ENXIO;
goto clean_dma_region;
}
ret = snd_card_create(index, id, THIS_MODULE, 0, &the_card.card);
if (ret < 0)
goto clean_irq;
strcpy(the_card.card->driver, "PS3");
strcpy(the_card.card->shortname, "PS3");
strcpy(the_card.card->longname, "PS3 sound");
for (i = 0; i < ARRAY_SIZE(spdif_ctls); i++) {
ret = snd_ctl_add(the_card.card,
snd_ctl_new1(&spdif_ctls[i], &the_card));
if (ret < 0)
goto clean_card;
}
ret = snd_pcm_new(the_card.card,
"SPDIF",
0,
1,
0,
&(the_card.pcm));
if (ret)
goto clean_card;
the_card.pcm->private_data = &the_card;
strcpy(the_card.pcm->name, "SPDIF");
snd_pcm_set_ops(the_card.pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_ps3_pcm_spdif_ops);
the_card.pcm->info_flags = SNDRV_PCM_INFO_NONINTERLEAVED;
ret = snd_pcm_lib_preallocate_pages_for_all(the_card.pcm,
SNDRV_DMA_TYPE_DEV,
&dev->core,
SND_PS3_PCM_PREALLOC_SIZE,
SND_PS3_PCM_PREALLOC_SIZE);
if (ret < 0) {
pr_info("%s: prealloc failed\n", __func__);
goto clean_card;
}
the_card.null_buffer_start_vaddr =
dma_alloc_coherent(&the_card.ps3_dev->core,
PAGE_SIZE,
&the_card.null_buffer_start_dma_addr,
GFP_KERNEL);
if (!the_card.null_buffer_start_vaddr) {
pr_info("%s: nullbuffer alloc failed\n", __func__);
ret = -ENOMEM;
goto clean_preallocate;
}
pr_debug("%s: null vaddr=%p dma=%#llx\n", __func__,
the_card.null_buffer_start_vaddr,
the_card.null_buffer_start_dma_addr);
snd_ps3_init_avsetting(&the_card);
snd_card_set_dev(the_card.card, &dev->core);
ret = snd_card_register(the_card.card);
if (ret < 0)
goto clean_dma_map;
pr_info("%s started. start_delay=%dms\n",
the_card.card->longname, the_card.start_delay);
return 0;
clean_dma_map:
dma_free_coherent(&the_card.ps3_dev->core,
PAGE_SIZE,
the_card.null_buffer_start_vaddr,
the_card.null_buffer_start_dma_addr);
clean_preallocate:
snd_pcm_lib_preallocate_free_for_all(the_card.pcm);
clean_card:
snd_card_free(the_card.card);
clean_irq:
snd_ps3_free_irq();
clean_dma_region:
ps3_dma_region_free(dev->d_region);
clean_mmio:
snd_ps3_unmap_mmio();
clean_dev_map:
lv1_gpu_device_unmap(2);
clean_open:
ps3_close_hv_device(dev);
return ret;
}
static int snd_ps3_driver_remove(struct ps3_system_bus_device *dev)
{
int ret;
pr_info("%s:start id=%d\n", __func__, dev->match_id);
if (dev->match_id != PS3_MATCH_ID_SOUND)
return -ENXIO;
ret = snd_card_free(the_card.card);
if (ret)
pr_info("%s: ctl freecard=%d\n", __func__, ret);
dma_free_coherent(&dev->core,
PAGE_SIZE,
the_card.null_buffer_start_vaddr,
the_card.null_buffer_start_dma_addr);
ps3_dma_region_free(dev->d_region);
snd_ps3_free_irq();
snd_ps3_unmap_mmio();
lv1_gpu_device_unmap(2);
ps3_close_hv_device(dev);
pr_info("%s:end id=%d\n", __func__, dev->match_id);
return 0;
}
static int __init snd_ps3_init(void)
{
int ret;
if (!firmware_has_feature(FW_FEATURE_PS3_LV1))
return -ENXIO;
memset(&the_card, 0, sizeof(the_card));
spin_lock_init(&the_card.dma_lock);
ret = ps3_system_bus_driver_register(&snd_ps3_bus_driver_info);
return ret;
}
static void __exit snd_ps3_exit(void)
{
ps3_system_bus_driver_unregister(&snd_ps3_bus_driver_info);
}
