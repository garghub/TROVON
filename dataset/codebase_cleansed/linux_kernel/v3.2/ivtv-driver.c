void ivtv_clear_irq_mask(struct ivtv *itv, u32 mask)
{
itv->irqmask &= ~mask;
write_reg_sync(itv->irqmask, IVTV_REG_IRQMASK);
}
void ivtv_set_irq_mask(struct ivtv *itv, u32 mask)
{
itv->irqmask |= mask;
write_reg_sync(itv->irqmask, IVTV_REG_IRQMASK);
}
int ivtv_set_output_mode(struct ivtv *itv, int mode)
{
int old_mode;
spin_lock(&itv->lock);
old_mode = itv->output_mode;
if (old_mode == 0)
itv->output_mode = old_mode = mode;
spin_unlock(&itv->lock);
return old_mode;
}
struct ivtv_stream *ivtv_get_output_stream(struct ivtv *itv)
{
switch (itv->output_mode) {
case OUT_MPG:
return &itv->streams[IVTV_DEC_STREAM_TYPE_MPG];
case OUT_YUV:
return &itv->streams[IVTV_DEC_STREAM_TYPE_YUV];
default:
return NULL;
}
}
int ivtv_waitq(wait_queue_head_t *waitq)
{
DEFINE_WAIT(wait);
prepare_to_wait(waitq, &wait, TASK_INTERRUPTIBLE);
schedule();
finish_wait(waitq, &wait);
return signal_pending(current) ? -EINTR : 0;
}
int ivtv_msleep_timeout(unsigned int msecs, int intr)
{
int timeout = msecs_to_jiffies(msecs);
do {
set_current_state(intr ? TASK_INTERRUPTIBLE : TASK_UNINTERRUPTIBLE);
timeout = schedule_timeout(timeout);
if (intr) {
int ret = signal_pending(current);
if (ret)
return ret;
}
} while (timeout);
return 0;
}
static void ivtv_iounmap(struct ivtv *itv)
{
if (itv == NULL)
return;
if (itv->reg_mem != NULL) {
IVTV_DEBUG_INFO("releasing reg_mem\n");
iounmap(itv->reg_mem);
itv->reg_mem = NULL;
}
if (itv->has_cx23415 && itv->dec_mem != NULL) {
IVTV_DEBUG_INFO("releasing dec_mem\n");
iounmap(itv->dec_mem);
}
itv->dec_mem = NULL;
if (itv->enc_mem != NULL) {
IVTV_DEBUG_INFO("releasing enc_mem\n");
iounmap(itv->enc_mem);
itv->enc_mem = NULL;
}
}
void ivtv_read_eeprom(struct ivtv *itv, struct tveeprom *tv)
{
u8 eedata[256];
itv->i2c_client.addr = 0xA0 >> 1;
tveeprom_read(&itv->i2c_client, eedata, sizeof(eedata));
tveeprom_hauppauge_analog(&itv->i2c_client, tv, eedata);
}
static void ivtv_process_eeprom(struct ivtv *itv)
{
struct tveeprom tv;
int pci_slot = PCI_SLOT(itv->pdev->devfn);
ivtv_read_eeprom(itv, &tv);
switch (tv.model) {
case 30012 ... 30039:
case 32000 ... 32999:
case 48000 ... 48099:
case 48400 ... 48599:
itv->card = ivtv_get_card(IVTV_CARD_PVR_250);
break;
case 48100 ... 48399:
case 48600 ... 48999:
itv->card = ivtv_get_card(IVTV_CARD_PVR_350);
break;
case 23000 ... 23999:
case 25000 ... 25999:
case 26000 ... 26999:
itv->card = ivtv_get_card(IVTV_CARD_PVR_150);
break;
case 0:
IVTV_ERR("Invalid EEPROM\n");
return;
default:
IVTV_ERR("Unknown model %d, defaulting to PVR-150\n", tv.model);
itv->card = ivtv_get_card(IVTV_CARD_PVR_150);
break;
}
switch (tv.model) {
case 48254:
itv->card = ivtv_get_card(IVTV_CARD_PVR_350_V1);
break;
default:
break;
}
itv->v4l2_cap = itv->card->v4l2_capabilities;
itv->card_name = itv->card->name;
itv->card_i2c = itv->card->i2c;
if (tv.model / 1000 == 23) {
static const struct ivtv_card_tuner_i2c ivtv_i2c_radio = {
.radio = { 0x60, I2C_CLIENT_END },
.demod = { 0x43, I2C_CLIENT_END },
.tv = { 0x61, I2C_CLIENT_END },
};
itv->card_name = "WinTV PVR 500";
itv->card_i2c = &ivtv_i2c_radio;
if (pci_slot == 8 || pci_slot == 9) {
int is_first = (pci_slot & 1) == 0;
itv->card_name = is_first ? "WinTV PVR 500 (unit #1)" :
"WinTV PVR 500 (unit #2)";
if (!is_first) {
IVTV_INFO("Correcting tveeprom data: no radio present on second unit\n");
tv.has_radio = 0;
}
}
}
IVTV_INFO("Autodetected %s\n", itv->card_name);
switch (tv.tuner_hauppauge_model) {
case 85:
case 99:
case 112:
itv->pvr150_workaround = 1;
break;
default:
break;
}
if (tv.tuner_type == TUNER_ABSENT)
IVTV_ERR("tveeprom cannot autodetect tuner!\n");
if (itv->options.tuner == -1)
itv->options.tuner = tv.tuner_type;
if (itv->options.radio == -1)
itv->options.radio = (tv.has_radio != 0);
if (itv->options.newi2c == -1 && tv.has_ir) {
itv->options.newi2c = (tv.has_ir & 4) ? 1 : 0;
if (itv->options.newi2c) {
IVTV_INFO("Reopen i2c bus for IR-blaster support\n");
exit_ivtv_i2c(itv);
init_ivtv_i2c(itv);
}
}
if (itv->std != 0)
return;
if (tv.tuner_formats & V4L2_STD_PAL) {
IVTV_DEBUG_INFO("PAL tuner detected\n");
itv->std |= V4L2_STD_PAL_BG | V4L2_STD_PAL_H;
} else if (tv.tuner_formats & V4L2_STD_NTSC) {
IVTV_DEBUG_INFO("NTSC tuner detected\n");
itv->std |= V4L2_STD_NTSC_M;
} else if (tv.tuner_formats & V4L2_STD_SECAM) {
IVTV_DEBUG_INFO("SECAM tuner detected\n");
itv->std |= V4L2_STD_SECAM_L;
} else {
IVTV_INFO("No tuner detected, default to NTSC-M\n");
itv->std |= V4L2_STD_NTSC_M;
}
}
static v4l2_std_id ivtv_parse_std(struct ivtv *itv)
{
switch (pal[0]) {
case '6':
tunertype = 0;
return V4L2_STD_PAL_60;
case 'b':
case 'B':
case 'g':
case 'G':
case 'h':
case 'H':
tunertype = 0;
return V4L2_STD_PAL_BG | V4L2_STD_PAL_H;
case 'n':
case 'N':
tunertype = 1;
if (pal[1] == 'c' || pal[1] == 'C')
return V4L2_STD_PAL_Nc;
return V4L2_STD_PAL_N;
case 'i':
case 'I':
tunertype = 0;
return V4L2_STD_PAL_I;
case 'd':
case 'D':
case 'k':
case 'K':
tunertype = 0;
return V4L2_STD_PAL_DK;
case 'M':
case 'm':
tunertype = 1;
return V4L2_STD_PAL_M;
case '-':
break;
default:
IVTV_WARN("pal= argument not recognised\n");
return 0;
}
switch (secam[0]) {
case 'b':
case 'B':
case 'g':
case 'G':
case 'h':
case 'H':
tunertype = 0;
return V4L2_STD_SECAM_B | V4L2_STD_SECAM_G | V4L2_STD_SECAM_H;
case 'd':
case 'D':
case 'k':
case 'K':
tunertype = 0;
return V4L2_STD_SECAM_DK;
case 'l':
case 'L':
tunertype = 0;
if (secam[1] == 'C' || secam[1] == 'c')
return V4L2_STD_SECAM_LC;
return V4L2_STD_SECAM_L;
case '-':
break;
default:
IVTV_WARN("secam= argument not recognised\n");
return 0;
}
switch (ntsc[0]) {
case 'm':
case 'M':
tunertype = 1;
return V4L2_STD_NTSC_M;
case 'j':
case 'J':
tunertype = 1;
return V4L2_STD_NTSC_M_JP;
case 'k':
case 'K':
tunertype = 1;
return V4L2_STD_NTSC_M_KR;
case '-':
break;
default:
IVTV_WARN("ntsc= argument not recognised\n");
return 0;
}
return 0;
}
static void ivtv_process_options(struct ivtv *itv)
{
const char *chipname;
int i, j;
itv->options.kilobytes[IVTV_ENC_STREAM_TYPE_MPG] = enc_mpg_buffers * 1024;
itv->options.kilobytes[IVTV_ENC_STREAM_TYPE_YUV] = enc_yuv_buffers * 1024;
itv->options.kilobytes[IVTV_ENC_STREAM_TYPE_VBI] = enc_vbi_buffers * 1024;
itv->options.kilobytes[IVTV_ENC_STREAM_TYPE_PCM] = enc_pcm_buffers;
itv->options.kilobytes[IVTV_DEC_STREAM_TYPE_MPG] = dec_mpg_buffers * 1024;
itv->options.kilobytes[IVTV_DEC_STREAM_TYPE_YUV] = dec_yuv_buffers * 1024;
itv->options.kilobytes[IVTV_DEC_STREAM_TYPE_VBI] = dec_vbi_buffers;
itv->options.cardtype = cardtype[itv->instance];
itv->options.tuner = tuner[itv->instance];
itv->options.radio = radio[itv->instance];
itv->options.i2c_clock_period = i2c_clock_period[itv->instance];
if (itv->options.i2c_clock_period == -1)
itv->options.i2c_clock_period = IVTV_DEFAULT_I2C_CLOCK_PERIOD;
else if (itv->options.i2c_clock_period < 10)
itv->options.i2c_clock_period = 10;
else if (itv->options.i2c_clock_period > 4500)
itv->options.i2c_clock_period = 4500;
itv->options.newi2c = newi2c;
if (tunertype < -1 || tunertype > 1) {
IVTV_WARN("Invalid tunertype argument, will autodetect instead\n");
tunertype = -1;
}
itv->std = ivtv_parse_std(itv);
if (itv->std == 0 && tunertype >= 0)
itv->std = tunertype ? V4L2_STD_MN : (V4L2_STD_ALL & ~V4L2_STD_MN);
itv->has_cx23415 = (itv->pdev->device == PCI_DEVICE_ID_IVTV15);
chipname = itv->has_cx23415 ? "cx23415" : "cx23416";
if (itv->options.cardtype == -1) {
IVTV_INFO("Ignore card (detected %s based chip)\n", chipname);
return;
}
if ((itv->card = ivtv_get_card(itv->options.cardtype - 1))) {
IVTV_INFO("User specified %s card (detected %s based chip)\n",
itv->card->name, chipname);
} else if (itv->options.cardtype != 0) {
IVTV_ERR("Unknown user specified type, trying to autodetect card\n");
}
if (itv->card == NULL) {
if (itv->pdev->subsystem_vendor == IVTV_PCI_ID_HAUPPAUGE ||
itv->pdev->subsystem_vendor == IVTV_PCI_ID_HAUPPAUGE_ALT1 ||
itv->pdev->subsystem_vendor == IVTV_PCI_ID_HAUPPAUGE_ALT2) {
itv->card = ivtv_get_card(itv->has_cx23415 ? IVTV_CARD_PVR_350 : IVTV_CARD_PVR_150);
IVTV_INFO("Autodetected Hauppauge card (%s based)\n",
chipname);
}
}
if (itv->card == NULL) {
for (i = 0; (itv->card = ivtv_get_card(i)); i++) {
if (itv->card->pci_list == NULL)
continue;
for (j = 0; itv->card->pci_list[j].device; j++) {
if (itv->pdev->device !=
itv->card->pci_list[j].device)
continue;
if (itv->pdev->subsystem_vendor !=
itv->card->pci_list[j].subsystem_vendor)
continue;
if (itv->pdev->subsystem_device !=
itv->card->pci_list[j].subsystem_device)
continue;
IVTV_INFO("Autodetected %s card (%s based)\n",
itv->card->name, chipname);
goto done;
}
}
}
done:
if (itv->card == NULL) {
itv->card = ivtv_get_card(IVTV_CARD_PVR_150);
IVTV_ERR("Unknown card: vendor/device: [%04x:%04x]\n",
itv->pdev->vendor, itv->pdev->device);
IVTV_ERR(" subsystem vendor/device: [%04x:%04x]\n",
itv->pdev->subsystem_vendor, itv->pdev->subsystem_device);
IVTV_ERR(" %s based\n", chipname);
IVTV_ERR("Defaulting to %s card\n", itv->card->name);
IVTV_ERR("Please mail the vendor/device and subsystem vendor/device IDs and what kind of\n");
IVTV_ERR("card you have to the ivtv-devel mailinglist (www.ivtvdriver.org)\n");
IVTV_ERR("Prefix your subject line with [UNKNOWN IVTV CARD].\n");
}
itv->v4l2_cap = itv->card->v4l2_capabilities;
itv->card_name = itv->card->name;
itv->card_i2c = itv->card->i2c;
}
static int __devinit ivtv_init_struct1(struct ivtv *itv)
{
struct sched_param param = { .sched_priority = 99 };
itv->base_addr = pci_resource_start(itv->pdev, 0);
itv->enc_mbox.max_mbox = 2;
itv->dec_mbox.max_mbox = 1;
mutex_init(&itv->serialize_lock);
mutex_init(&itv->i2c_bus_lock);
mutex_init(&itv->udma.lock);
spin_lock_init(&itv->lock);
spin_lock_init(&itv->dma_reg_lock);
init_kthread_worker(&itv->irq_worker);
itv->irq_worker_task = kthread_run(kthread_worker_fn, &itv->irq_worker,
itv->v4l2_dev.name);
if (IS_ERR(itv->irq_worker_task)) {
IVTV_ERR("Could not create ivtv task\n");
return -1;
}
sched_setscheduler(itv->irq_worker_task, SCHED_FIFO, &param);
init_kthread_work(&itv->irq_work, ivtv_irq_work_handler);
itv->open_id = 1;
itv->cxhdl.port = CX2341X_PORT_MEMORY;
itv->cxhdl.capabilities = CX2341X_CAP_HAS_SLICED_VBI;
init_waitqueue_head(&itv->eos_waitq);
init_waitqueue_head(&itv->event_waitq);
init_waitqueue_head(&itv->vsync_waitq);
init_waitqueue_head(&itv->dma_waitq);
init_timer(&itv->dma_timer);
itv->dma_timer.function = ivtv_unfinished_dma;
itv->dma_timer.data = (unsigned long)itv;
itv->cur_dma_stream = -1;
itv->cur_pio_stream = -1;
itv->audio_stereo_mode = AUDIO_STEREO;
itv->audio_bilingual_mode = AUDIO_MONO_LEFT;
itv->speed = 1000;
itv->vbi.in.type = V4L2_BUF_TYPE_VBI_CAPTURE;
itv->vbi.sliced_in = &itv->vbi.in.fmt.sliced;
sg_init_table(itv->udma.SGlist, IVTV_DMA_SG_OSD_ENT);
itv->osd_global_alpha_state = 1;
itv->osd_global_alpha = 255;
atomic_set(&itv->yuv_info.next_dma_frame, -1);
itv->yuv_info.lace_mode = ivtv_yuv_mode;
itv->yuv_info.lace_threshold = ivtv_yuv_threshold;
itv->yuv_info.max_frames_buffered = 3;
itv->yuv_info.track_osd = 1;
return 0;
}
static void __devinit ivtv_init_struct2(struct ivtv *itv)
{
int i;
for (i = 0; i < IVTV_CARD_MAX_VIDEO_INPUTS; i++)
if (itv->card->video_inputs[i].video_type == 0)
break;
itv->nof_inputs = i;
for (i = 0; i < IVTV_CARD_MAX_AUDIO_INPUTS; i++)
if (itv->card->audio_inputs[i].audio_type == 0)
break;
itv->nof_audio_inputs = i;
if (itv->card->hw_all & IVTV_HW_CX25840) {
itv->vbi.sliced_size = 288;
} else {
itv->vbi.sliced_size = 64;
}
for (i = 0; i < itv->nof_inputs; i++) {
if (itv->card->video_inputs[i].video_type ==
IVTV_CARD_INPUT_VID_TUNER)
break;
}
if (i == itv->nof_inputs)
i = 0;
itv->active_input = i;
itv->audio_input = itv->card->video_inputs[i].audio_index;
}
static int ivtv_setup_pci(struct ivtv *itv, struct pci_dev *pdev,
const struct pci_device_id *pci_id)
{
u16 cmd;
unsigned char pci_latency;
IVTV_DEBUG_INFO("Enabling pci device\n");
if (pci_enable_device(pdev)) {
IVTV_ERR("Can't enable device!\n");
return -EIO;
}
if (pci_set_dma_mask(pdev, 0xffffffff)) {
IVTV_ERR("No suitable DMA available.\n");
return -EIO;
}
if (!request_mem_region(itv->base_addr, IVTV_ENCODER_SIZE, "ivtv encoder")) {
IVTV_ERR("Cannot request encoder memory region.\n");
return -EIO;
}
if (!request_mem_region(itv->base_addr + IVTV_REG_OFFSET,
IVTV_REG_SIZE, "ivtv registers")) {
IVTV_ERR("Cannot request register memory region.\n");
release_mem_region(itv->base_addr, IVTV_ENCODER_SIZE);
return -EIO;
}
if (itv->has_cx23415 &&
!request_mem_region(itv->base_addr + IVTV_DECODER_OFFSET,
IVTV_DECODER_SIZE, "ivtv decoder")) {
IVTV_ERR("Cannot request decoder memory region.\n");
release_mem_region(itv->base_addr, IVTV_ENCODER_SIZE);
release_mem_region(itv->base_addr + IVTV_REG_OFFSET, IVTV_REG_SIZE);
return -EIO;
}
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if (!(cmd & PCI_COMMAND_MASTER)) {
IVTV_DEBUG_INFO("Attempting to enable Bus Mastering\n");
pci_set_master(pdev);
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if (!(cmd & PCI_COMMAND_MASTER)) {
IVTV_ERR("Bus Mastering is not enabled\n");
return -ENXIO;
}
}
IVTV_DEBUG_INFO("Bus Mastering Enabled.\n");
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &pci_latency);
if (pci_latency < 64 && ivtv_pci_latency) {
IVTV_INFO("Unreasonably low latency timer, "
"setting to 64 (was %d)\n", pci_latency);
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 64);
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &pci_latency);
}
pci_write_config_dword(pdev, 0x40, 0xffff);
IVTV_DEBUG_INFO("%d (rev %d) at %02x:%02x.%x, "
"irq: %d, latency: %d, memory: 0x%lx\n",
pdev->device, pdev->revision, pdev->bus->number,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
pdev->irq, pci_latency, (unsigned long)itv->base_addr);
return 0;
}
static void ivtv_load_and_init_modules(struct ivtv *itv)
{
u32 hw = itv->card->hw_all;
unsigned i;
for (i = 0; i < 32; i++) {
u32 device = 1 << i;
if (!(device & hw))
continue;
if (device == IVTV_HW_GPIO || device == IVTV_HW_TVEEPROM) {
itv->hw_flags |= device;
continue;
}
if (ivtv_i2c_register(itv, i) == 0)
itv->hw_flags |= device;
}
if ((itv->hw_flags & IVTV_HW_IR_ANY) == 0)
ivtv_i2c_new_ir_legacy(itv);
if (itv->card->hw_all & IVTV_HW_CX25840)
itv->sd_video = ivtv_find_hw(itv, IVTV_HW_CX25840);
else if (itv->card->hw_all & IVTV_HW_SAA717X)
itv->sd_video = ivtv_find_hw(itv, IVTV_HW_SAA717X);
else if (itv->card->hw_all & IVTV_HW_SAA7114)
itv->sd_video = ivtv_find_hw(itv, IVTV_HW_SAA7114);
else
itv->sd_video = ivtv_find_hw(itv, IVTV_HW_SAA7115);
itv->sd_audio = ivtv_find_hw(itv, itv->card->hw_audio_ctrl);
itv->sd_muxer = ivtv_find_hw(itv, itv->card->hw_muxer);
hw = itv->hw_flags;
if (itv->card->type == IVTV_CARD_CX23416GYC) {
if ((hw & (IVTV_HW_UPD64031A | IVTV_HW_UPD6408X)) == 0)
itv->card = ivtv_get_card(IVTV_CARD_CX23416GYC_NOGRYCS);
else if ((hw & IVTV_HW_UPD64031A) == 0)
itv->card = ivtv_get_card(IVTV_CARD_CX23416GYC_NOGR);
}
else if (itv->card->type == IVTV_CARD_GV_MVPRX ||
itv->card->type == IVTV_CARD_GV_MVPRX2E) {
v4l2_subdev_call(itv->sd_video, video, s_crystal_freq,
SAA7115_FREQ_24_576_MHZ, SAA7115_FREQ_FL_UCGC);
}
if (hw & IVTV_HW_CX25840) {
itv->vbi.raw_decoder_line_size = 1444;
itv->vbi.raw_decoder_sav_odd_field = 0x20;
itv->vbi.raw_decoder_sav_even_field = 0x60;
itv->vbi.sliced_decoder_line_size = 272;
itv->vbi.sliced_decoder_sav_odd_field = 0xB0;
itv->vbi.sliced_decoder_sav_even_field = 0xF0;
}
if (hw & IVTV_HW_SAA711X) {
struct v4l2_dbg_chip_ident v;
itv->hw_flags &= ~IVTV_HW_SAA711X;
v.match.type = V4L2_CHIP_MATCH_I2C_DRIVER;
strlcpy(v.match.name, "saa7115", sizeof(v.match.name));
ivtv_call_hw(itv, IVTV_HW_SAA711X, core, g_chip_ident, &v);
if (v.ident == V4L2_IDENT_SAA7114) {
itv->hw_flags |= IVTV_HW_SAA7114;
itv->v4l2_cap &= ~(V4L2_CAP_SLICED_VBI_CAPTURE|V4L2_CAP_VBI_CAPTURE);
} else {
itv->hw_flags |= IVTV_HW_SAA7115;
}
itv->vbi.raw_decoder_line_size = 1443;
itv->vbi.raw_decoder_sav_odd_field = 0x25;
itv->vbi.raw_decoder_sav_even_field = 0x62;
itv->vbi.sliced_decoder_line_size = 51;
itv->vbi.sliced_decoder_sav_odd_field = 0xAB;
itv->vbi.sliced_decoder_sav_even_field = 0xEC;
}
if (hw & IVTV_HW_SAA717X) {
itv->vbi.raw_decoder_line_size = 1443;
itv->vbi.raw_decoder_sav_odd_field = 0x25;
itv->vbi.raw_decoder_sav_even_field = 0x62;
itv->vbi.sliced_decoder_line_size = 51;
itv->vbi.sliced_decoder_sav_odd_field = 0xAB;
itv->vbi.sliced_decoder_sav_even_field = 0xEC;
}
}
static int __devinit ivtv_probe(struct pci_dev *pdev,
const struct pci_device_id *pci_id)
{
int retval = 0;
int vbi_buf_size;
struct ivtv *itv;
itv = kzalloc(sizeof(struct ivtv), GFP_ATOMIC);
if (itv == NULL)
return -ENOMEM;
itv->pdev = pdev;
itv->instance = v4l2_device_set_name(&itv->v4l2_dev, "ivtv",
&ivtv_instance);
retval = v4l2_device_register(&pdev->dev, &itv->v4l2_dev);
if (retval) {
kfree(itv);
return retval;
}
IVTV_INFO("Initializing card %d\n", itv->instance);
ivtv_process_options(itv);
if (itv->options.cardtype == -1) {
retval = -ENODEV;
goto err;
}
if (ivtv_init_struct1(itv)) {
retval = -ENOMEM;
goto err;
}
retval = cx2341x_handler_init(&itv->cxhdl, 50);
if (retval)
goto err;
itv->v4l2_dev.ctrl_handler = &itv->cxhdl.hdl;
itv->cxhdl.ops = &ivtv_cxhdl_ops;
itv->cxhdl.priv = itv;
itv->cxhdl.func = ivtv_api_func;
IVTV_DEBUG_INFO("base addr: 0x%08x\n", itv->base_addr);
retval = ivtv_setup_pci(itv, pdev, pci_id);
if (retval == -EIO)
goto free_worker;
if (retval == -ENXIO)
goto free_mem;
IVTV_DEBUG_INFO("attempting ioremap at 0x%08x len 0x%08x\n",
itv->base_addr + IVTV_ENCODER_OFFSET, IVTV_ENCODER_SIZE);
itv->enc_mem = ioremap_nocache(itv->base_addr + IVTV_ENCODER_OFFSET,
IVTV_ENCODER_SIZE);
if (!itv->enc_mem) {
IVTV_ERR("ioremap failed. Can't get a window into CX23415/6 "
"encoder memory\n");
IVTV_ERR("Each capture card with a CX23415/6 needs 8 MB of "
"vmalloc address space for this window\n");
IVTV_ERR("Check the output of 'grep Vmalloc /proc/meminfo'\n");
IVTV_ERR("Use the vmalloc= kernel command line option to set "
"VmallocTotal to a larger value\n");
retval = -ENOMEM;
goto free_mem;
}
if (itv->has_cx23415) {
IVTV_DEBUG_INFO("attempting ioremap at 0x%08x len 0x%08x\n",
itv->base_addr + IVTV_DECODER_OFFSET, IVTV_DECODER_SIZE);
itv->dec_mem = ioremap_nocache(itv->base_addr + IVTV_DECODER_OFFSET,
IVTV_DECODER_SIZE);
if (!itv->dec_mem) {
IVTV_ERR("ioremap failed. Can't get a window into "
"CX23415 decoder memory\n");
IVTV_ERR("Each capture card with a CX23415 needs 8 MB "
"of vmalloc address space for this window\n");
IVTV_ERR("Check the output of 'grep Vmalloc "
"/proc/meminfo'\n");
IVTV_ERR("Use the vmalloc= kernel command line option "
"to set VmallocTotal to a larger value\n");
retval = -ENOMEM;
goto free_mem;
}
}
else {
itv->dec_mem = itv->enc_mem;
}
IVTV_DEBUG_INFO("attempting ioremap at 0x%08x len 0x%08x\n",
itv->base_addr + IVTV_REG_OFFSET, IVTV_REG_SIZE);
itv->reg_mem =
ioremap_nocache(itv->base_addr + IVTV_REG_OFFSET, IVTV_REG_SIZE);
if (!itv->reg_mem) {
IVTV_ERR("ioremap failed. Can't get a window into CX23415/6 "
"register space\n");
IVTV_ERR("Each capture card with a CX23415/6 needs 64 kB of "
"vmalloc address space for this window\n");
IVTV_ERR("Check the output of 'grep Vmalloc /proc/meminfo'\n");
IVTV_ERR("Use the vmalloc= kernel command line option to set "
"VmallocTotal to a larger value\n");
retval = -ENOMEM;
goto free_io;
}
retval = ivtv_gpio_init(itv);
if (retval)
goto free_io;
IVTV_DEBUG_INFO("activating i2c...\n");
if (init_ivtv_i2c(itv)) {
IVTV_ERR("Could not initialize i2c\n");
goto free_io;
}
if (itv->card->hw_all & IVTV_HW_TVEEPROM) {
ivtv_process_eeprom(itv);
}
if (itv->card->comment)
IVTV_INFO("%s", itv->card->comment);
if (itv->card->v4l2_capabilities == 0) {
retval = -ENODEV;
goto free_i2c;
}
if (itv->std == 0) {
itv->std = V4L2_STD_NTSC_M;
}
if (itv->options.tuner == -1) {
int i;
for (i = 0; i < IVTV_CARD_MAX_TUNERS; i++) {
if ((itv->std & itv->card->tuners[i].std) == 0)
continue;
itv->options.tuner = itv->card->tuners[i].tuner;
break;
}
}
if (itv->options.tuner == -1 && itv->card->tuners[0].std) {
itv->std = itv->card->tuners[0].std;
if (itv->std & V4L2_STD_PAL)
itv->std = V4L2_STD_PAL_BG | V4L2_STD_PAL_H;
else if (itv->std & V4L2_STD_NTSC)
itv->std = V4L2_STD_NTSC_M;
else if (itv->std & V4L2_STD_SECAM)
itv->std = V4L2_STD_SECAM_L;
itv->options.tuner = itv->card->tuners[0].tuner;
}
if (itv->options.radio == -1)
itv->options.radio = (itv->card->radio_input.audio_type != 0);
ivtv_init_struct2(itv);
ivtv_load_and_init_modules(itv);
if (itv->std & V4L2_STD_525_60) {
itv->is_60hz = 1;
itv->is_out_60hz = 1;
} else {
itv->is_50hz = 1;
itv->is_out_50hz = 1;
}
itv->yuv_info.osd_full_w = 720;
itv->yuv_info.osd_full_h = itv->is_out_50hz ? 576 : 480;
itv->yuv_info.v4l2_src_w = itv->yuv_info.osd_full_w;
itv->yuv_info.v4l2_src_h = itv->yuv_info.osd_full_h;
cx2341x_handler_set_50hz(&itv->cxhdl, itv->is_50hz);
itv->stream_buf_size[IVTV_ENC_STREAM_TYPE_MPG] = 0x08000;
itv->stream_buf_size[IVTV_ENC_STREAM_TYPE_PCM] = 0x01200;
itv->stream_buf_size[IVTV_DEC_STREAM_TYPE_MPG] = 0x10000;
itv->stream_buf_size[IVTV_DEC_STREAM_TYPE_YUV] = 0x10000;
itv->stream_buf_size[IVTV_ENC_STREAM_TYPE_YUV] = 0x08000;
itv->vbi.raw_size = 1456;
vbi_buf_size = itv->vbi.raw_size * (itv->is_60hz ? 24 : 36) / 2;
itv->stream_buf_size[IVTV_ENC_STREAM_TYPE_VBI] = vbi_buf_size;
itv->stream_buf_size[IVTV_DEC_STREAM_TYPE_VBI] = sizeof(struct v4l2_sliced_vbi_data) * 36;
if (itv->options.radio > 0)
itv->v4l2_cap |= V4L2_CAP_RADIO;
if (itv->options.tuner > -1) {
struct tuner_setup setup;
setup.addr = ADDR_UNSET;
setup.type = itv->options.tuner;
setup.mode_mask = T_ANALOG_TV;
if (itv->options.radio > 0)
setup.mode_mask |= T_RADIO;
setup.tuner_callback = (setup.type == TUNER_XC2028) ?
ivtv_reset_tuner_gpio : NULL;
ivtv_call_all(itv, tuner, s_type_addr, &setup);
if (setup.type == TUNER_XC2028) {
static struct xc2028_ctrl ctrl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
};
struct v4l2_priv_tun_config cfg = {
.tuner = itv->options.tuner,
.priv = &ctrl,
};
ivtv_call_all(itv, tuner, s_config, &cfg);
}
}
itv->tuner_std = itv->std;
if (itv->v4l2_cap & V4L2_CAP_VIDEO_OUTPUT) {
ivtv_call_all(itv, video, s_std_output, itv->std);
ivtv_call_hw(itv, IVTV_HW_SAA7127, video, s_stream, 0);
}
ivtv_set_irq_mask(itv, 0xffffffff);
retval = request_irq(itv->pdev->irq, ivtv_irq_handler,
IRQF_SHARED | IRQF_DISABLED, itv->v4l2_dev.name, (void *)itv);
if (retval) {
IVTV_ERR("Failed to register irq %d\n", retval);
goto free_i2c;
}
retval = ivtv_streams_setup(itv);
if (retval) {
IVTV_ERR("Error %d setting up streams\n", retval);
goto free_irq;
}
retval = ivtv_streams_register(itv);
if (retval) {
IVTV_ERR("Error %d registering devices\n", retval);
goto free_streams;
}
IVTV_INFO("Initialized card: %s\n", itv->card_name);
return 0;
free_streams:
ivtv_streams_cleanup(itv, 1);
free_irq:
free_irq(itv->pdev->irq, (void *)itv);
free_i2c:
exit_ivtv_i2c(itv);
free_io:
ivtv_iounmap(itv);
free_mem:
release_mem_region(itv->base_addr, IVTV_ENCODER_SIZE);
release_mem_region(itv->base_addr + IVTV_REG_OFFSET, IVTV_REG_SIZE);
if (itv->has_cx23415)
release_mem_region(itv->base_addr + IVTV_DECODER_OFFSET, IVTV_DECODER_SIZE);
free_worker:
kthread_stop(itv->irq_worker_task);
err:
if (retval == 0)
retval = -ENODEV;
IVTV_ERR("Error %d on initialization\n", retval);
v4l2_device_unregister(&itv->v4l2_dev);
kfree(itv);
return retval;
}
int ivtv_init_on_first_open(struct ivtv *itv)
{
struct v4l2_frequency vf;
struct ivtv_open_id fh;
int fw_retry_count = 3;
int video_input;
fh.itv = itv;
if (test_bit(IVTV_F_I_FAILED, &itv->i_flags))
return -ENXIO;
if (test_and_set_bit(IVTV_F_I_INITED, &itv->i_flags))
return 0;
while (--fw_retry_count > 0) {
if (ivtv_firmware_init(itv) == 0)
break;
if (fw_retry_count > 1)
IVTV_WARN("Retry loading firmware\n");
}
if (fw_retry_count == 0) {
set_bit(IVTV_F_I_FAILED, &itv->i_flags);
return -ENXIO;
}
IVTV_DEBUG_INFO("Getting firmware version..\n");
ivtv_firmware_versions(itv);
if (itv->card->hw_all & IVTV_HW_CX25840)
v4l2_subdev_call(itv->sd_video, core, load_fw);
vf.tuner = 0;
vf.type = V4L2_TUNER_ANALOG_TV;
vf.frequency = 6400;
if (itv->std == V4L2_STD_NTSC_M_JP) {
vf.frequency = 1460;
}
else if (itv->std & V4L2_STD_NTSC_M) {
vf.frequency = 1076;
}
video_input = itv->active_input;
itv->active_input++;
ivtv_s_input(NULL, &fh, video_input);
itv->std++;
itv->std_out = itv->std;
ivtv_s_frequency(NULL, &fh, &vf);
if (itv->card->v4l2_capabilities & V4L2_CAP_VIDEO_OUTPUT) {
ivtv_call_hw(itv, IVTV_HW_SAA7127, video, s_stream, 1);
ivtv_init_mpeg_decoder(itv);
}
if (!itv->has_cx23415)
write_reg_sync(0x03, IVTV_REG_DMACONTROL);
ivtv_s_std_enc(itv, &itv->tuner_std);
if (itv->v4l2_cap & V4L2_CAP_VIDEO_OUTPUT) {
ivtv_clear_irq_mask(itv, IVTV_IRQ_MASK_INIT | IVTV_IRQ_DEC_VSYNC);
ivtv_set_osd_alpha(itv);
ivtv_s_std_dec(itv, &itv->tuner_std);
} else {
ivtv_clear_irq_mask(itv, IVTV_IRQ_MASK_INIT);
}
cx2341x_handler_setup(&itv->cxhdl);
return 0;
}
static void ivtv_remove(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct ivtv *itv = to_ivtv(v4l2_dev);
int i;
IVTV_DEBUG_INFO("Removing card\n");
if (test_bit(IVTV_F_I_INITED, &itv->i_flags)) {
IVTV_DEBUG_INFO("Stopping all streams\n");
if (atomic_read(&itv->capturing) > 0)
ivtv_stop_all_captures(itv);
IVTV_DEBUG_INFO("Stopping decoding\n");
if (itv->v4l2_cap & V4L2_CAP_VIDEO_OUTPUT)
ivtv_call_hw(itv, IVTV_HW_SAA7127, video, s_stream, 0);
if (atomic_read(&itv->decoding) > 0) {
int type;
if (test_bit(IVTV_F_I_DEC_YUV, &itv->i_flags))
type = IVTV_DEC_STREAM_TYPE_YUV;
else
type = IVTV_DEC_STREAM_TYPE_MPG;
ivtv_stop_v4l2_decode_stream(&itv->streams[type],
VIDEO_CMD_STOP_TO_BLACK | VIDEO_CMD_STOP_IMMEDIATELY, 0);
}
ivtv_halt_firmware(itv);
}
ivtv_set_irq_mask(itv, 0xffffffff);
del_timer_sync(&itv->dma_timer);
flush_kthread_worker(&itv->irq_worker);
kthread_stop(itv->irq_worker_task);
ivtv_streams_cleanup(itv, 1);
ivtv_udma_free(itv);
exit_ivtv_i2c(itv);
free_irq(itv->pdev->irq, (void *)itv);
ivtv_iounmap(itv);
release_mem_region(itv->base_addr, IVTV_ENCODER_SIZE);
release_mem_region(itv->base_addr + IVTV_REG_OFFSET, IVTV_REG_SIZE);
if (itv->has_cx23415)
release_mem_region(itv->base_addr + IVTV_DECODER_OFFSET, IVTV_DECODER_SIZE);
pci_disable_device(itv->pdev);
for (i = 0; i < IVTV_VBI_FRAMES; i++)
kfree(itv->vbi.sliced_mpeg_data[i]);
printk(KERN_INFO "ivtv: Removed %s\n", itv->card_name);
v4l2_device_unregister(&itv->v4l2_dev);
kfree(itv);
}
static int __init module_start(void)
{
printk(KERN_INFO "ivtv: Start initialization, version %s\n", IVTV_VERSION);
if (ivtv_first_minor < 0 || ivtv_first_minor >= IVTV_MAX_CARDS) {
printk(KERN_ERR "ivtv: Exiting, ivtv_first_minor must be between 0 and %d\n",
IVTV_MAX_CARDS - 1);
return -1;
}
if (ivtv_debug < 0 || ivtv_debug > 2047) {
ivtv_debug = 0;
printk(KERN_INFO "ivtv: Debug value must be >= 0 and <= 2047\n");
}
if (pci_register_driver(&ivtv_pci_driver)) {
printk(KERN_ERR "ivtv: Error detecting PCI card\n");
return -ENODEV;
}
printk(KERN_INFO "ivtv: End initialization\n");
return 0;
}
static void __exit module_cleanup(void)
{
pci_unregister_driver(&ivtv_pci_driver);
}
