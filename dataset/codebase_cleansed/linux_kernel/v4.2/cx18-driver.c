static void request_module_async(struct work_struct *work)
{
struct cx18 *dev = container_of(work, struct cx18, request_module_wk);
request_module("cx18-alsa");
if (cx18_ext_init != NULL)
cx18_ext_init(dev);
}
static void request_modules(struct cx18 *dev)
{
INIT_WORK(&dev->request_module_wk, request_module_async);
schedule_work(&dev->request_module_wk);
}
static void flush_request_modules(struct cx18 *dev)
{
flush_work(&dev->request_module_wk);
}
int cx18_msleep_timeout(unsigned int msecs, int intr)
{
long int timeout = msecs_to_jiffies(msecs);
int sig;
do {
set_current_state(intr ? TASK_INTERRUPTIBLE : TASK_UNINTERRUPTIBLE);
timeout = schedule_timeout(timeout);
sig = intr ? signal_pending(current) : 0;
} while (!sig && timeout);
return sig;
}
static void cx18_iounmap(struct cx18 *cx)
{
if (cx == NULL)
return;
if (cx->enc_mem != NULL) {
CX18_DEBUG_INFO("releasing enc_mem\n");
iounmap(cx->enc_mem);
cx->enc_mem = NULL;
}
}
static void cx18_eeprom_dump(struct cx18 *cx, unsigned char *eedata, int len)
{
int i;
CX18_INFO("eeprom dump:\n");
for (i = 0; i < len; i++) {
if (0 == (i % 16))
CX18_INFO("eeprom %02x:", i);
printk(KERN_CONT " %02x", eedata[i]);
if (15 == (i % 16))
printk(KERN_CONT "\n");
}
}
void cx18_read_eeprom(struct cx18 *cx, struct tveeprom *tv)
{
struct i2c_client *c;
u8 eedata[256];
memset(tv, 0, sizeof(*tv));
c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return;
strlcpy(c->name, "cx18 tveeprom tmp", sizeof(c->name));
c->adapter = &cx->i2c_adap[0];
c->addr = 0xa0 >> 1;
if (tveeprom_read(c, eedata, sizeof(eedata)))
goto ret;
switch (cx->card->type) {
case CX18_CARD_HVR_1600_ESMT:
case CX18_CARD_HVR_1600_SAMSUNG:
case CX18_CARD_HVR_1600_S5H1411:
tveeprom_hauppauge_analog(c, tv, eedata);
break;
case CX18_CARD_YUAN_MPC718:
case CX18_CARD_GOTVIEW_PCI_DVD3:
tv->model = 0x718;
cx18_eeprom_dump(cx, eedata, sizeof(eedata));
CX18_INFO("eeprom PCI ID: %02x%02x:%02x%02x\n",
eedata[2], eedata[1], eedata[4], eedata[3]);
break;
default:
tv->model = 0xffffffff;
cx18_eeprom_dump(cx, eedata, sizeof(eedata));
break;
}
ret:
kfree(c);
}
static void cx18_process_eeprom(struct cx18 *cx)
{
struct tveeprom tv;
cx18_read_eeprom(cx, &tv);
switch (tv.model) {
case 74301:
case 74321:
case 74351:
case 74361:
cx->card = cx18_get_card(CX18_CARD_HVR_1600_S5H1411);
break;
case 74021:
case 74031:
case 74041:
case 74141:
case 74541:
case 74551:
case 74591:
case 74651:
case 74691:
case 74751:
case 74891:
cx->card = cx18_get_card(CX18_CARD_HVR_1600_ESMT);
break;
case 0x718:
return;
case 0xffffffff:
CX18_INFO("Unknown EEPROM encoding\n");
return;
case 0:
CX18_ERR("Invalid EEPROM\n");
return;
default:
CX18_ERR("Unknown model %d, defaulting to original HVR-1600 "
"(cardtype=1)\n", tv.model);
cx->card = cx18_get_card(CX18_CARD_HVR_1600_ESMT);
break;
}
cx->v4l2_cap = cx->card->v4l2_capabilities;
cx->card_name = cx->card->name;
cx->card_i2c = cx->card->i2c;
CX18_INFO("Autodetected %s\n", cx->card_name);
if (tv.tuner_type == TUNER_ABSENT)
CX18_ERR("tveeprom cannot autodetect tuner!\n");
if (cx->options.tuner == -1)
cx->options.tuner = tv.tuner_type;
if (cx->options.radio == -1)
cx->options.radio = (tv.has_radio != 0);
if (cx->std != 0)
return;
#define TVEEPROM_TUNER_FORMAT_ALL (V4L2_STD_B | V4L2_STD_GH | \
V4L2_STD_MN | \
V4L2_STD_PAL_I | \
V4L2_STD_SECAM_L | V4L2_STD_SECAM_LC | \
V4L2_STD_DK)
if ((tv.tuner_formats & TVEEPROM_TUNER_FORMAT_ALL)
== TVEEPROM_TUNER_FORMAT_ALL) {
CX18_DEBUG_INFO("Worldwide tuner detected\n");
cx->std = V4L2_STD_ALL;
} else if (tv.tuner_formats & V4L2_STD_PAL) {
CX18_DEBUG_INFO("PAL tuner detected\n");
cx->std |= V4L2_STD_PAL_BG | V4L2_STD_PAL_H;
} else if (tv.tuner_formats & V4L2_STD_NTSC) {
CX18_DEBUG_INFO("NTSC tuner detected\n");
cx->std |= V4L2_STD_NTSC_M;
} else if (tv.tuner_formats & V4L2_STD_SECAM) {
CX18_DEBUG_INFO("SECAM tuner detected\n");
cx->std |= V4L2_STD_SECAM_L;
} else {
CX18_INFO("No tuner detected, default to NTSC-M\n");
cx->std |= V4L2_STD_NTSC_M;
}
}
static v4l2_std_id cx18_parse_std(struct cx18 *cx)
{
switch (pal[0]) {
case '6':
return V4L2_STD_PAL_60;
case 'b':
case 'B':
case 'g':
case 'G':
return V4L2_STD_PAL_BG;
case 'h':
case 'H':
return V4L2_STD_PAL_H;
case 'n':
case 'N':
if (pal[1] == 'c' || pal[1] == 'C')
return V4L2_STD_PAL_Nc;
return V4L2_STD_PAL_N;
case 'i':
case 'I':
return V4L2_STD_PAL_I;
case 'd':
case 'D':
case 'k':
case 'K':
return V4L2_STD_PAL_DK;
case 'M':
case 'm':
return V4L2_STD_PAL_M;
case '-':
break;
default:
CX18_WARN("pal= argument not recognised\n");
return 0;
}
switch (secam[0]) {
case 'b':
case 'B':
case 'g':
case 'G':
case 'h':
case 'H':
return V4L2_STD_SECAM_B | V4L2_STD_SECAM_G | V4L2_STD_SECAM_H;
case 'd':
case 'D':
case 'k':
case 'K':
return V4L2_STD_SECAM_DK;
case 'l':
case 'L':
if (secam[1] == 'C' || secam[1] == 'c')
return V4L2_STD_SECAM_LC;
return V4L2_STD_SECAM_L;
case '-':
break;
default:
CX18_WARN("secam= argument not recognised\n");
return 0;
}
switch (ntsc[0]) {
case 'm':
case 'M':
return V4L2_STD_NTSC_M;
case 'j':
case 'J':
return V4L2_STD_NTSC_M_JP;
case 'k':
case 'K':
return V4L2_STD_NTSC_M_KR;
case '-':
break;
default:
CX18_WARN("ntsc= argument not recognised\n");
return 0;
}
return 0;
}
static void cx18_process_options(struct cx18 *cx)
{
int i, j;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_TS] = enc_ts_buffers;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_MPG] = enc_mpg_buffers;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_IDX] = enc_idx_buffers;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_YUV] = enc_yuv_buffers;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_VBI] = enc_vbi_buffers;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_PCM] = enc_pcm_buffers;
cx->options.megabytes[CX18_ENC_STREAM_TYPE_RAD] = 0;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_TS] = enc_ts_bufs;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_MPG] = enc_mpg_bufs;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_IDX] = enc_idx_bufs;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_YUV] = enc_yuv_bufs;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_VBI] = enc_vbi_bufs;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_PCM] = enc_pcm_bufs;
cx->stream_buffers[CX18_ENC_STREAM_TYPE_RAD] = 0;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_TS] = enc_ts_bufsize;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_MPG] = enc_mpg_bufsize;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_IDX] = enc_idx_bufsize;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_YUV] = enc_yuv_bufsize;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_VBI] = vbi_active_samples * 36;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_PCM] = enc_pcm_bufsize;
cx->stream_buf_size[CX18_ENC_STREAM_TYPE_RAD] = 0;
for (i = 0; i < CX18_MAX_STREAMS; i++) {
if (cx->stream_buffers[i] == 0 ||
cx->options.megabytes[i] <= 0 ||
cx->stream_buf_size[i] <= 0) {
cx->options.megabytes[i] = 0;
cx->stream_buffers[i] = 0;
cx->stream_buf_size[i] = 0;
continue;
}
if (i == CX18_ENC_STREAM_TYPE_YUV) {
cx->stream_buf_size[i] *= 1024;
cx->stream_buf_size[i] -=
(cx->stream_buf_size[i] % CX18_UNIT_ENC_YUV_BUFSIZE);
if (cx->stream_buf_size[i] < CX18_UNIT_ENC_YUV_BUFSIZE)
cx->stream_buf_size[i] =
CX18_UNIT_ENC_YUV_BUFSIZE;
} else if (i == CX18_ENC_STREAM_TYPE_IDX) {
cx->stream_buf_size[i] *= 1024;
cx->stream_buf_size[i] -=
(cx->stream_buf_size[i] % CX18_UNIT_ENC_IDX_BUFSIZE);
if (cx->stream_buf_size[i] < CX18_UNIT_ENC_IDX_BUFSIZE)
cx->stream_buf_size[i] =
CX18_UNIT_ENC_IDX_BUFSIZE;
}
if (i == CX18_ENC_STREAM_TYPE_VBI ||
i == CX18_ENC_STREAM_TYPE_YUV ||
i == CX18_ENC_STREAM_TYPE_IDX) {
if (cx->stream_buffers[i] < 0) {
cx->stream_buffers[i] =
cx->options.megabytes[i] * 1024 * 1024
/ cx->stream_buf_size[i];
} else {
cx->options.megabytes[i] =
cx->stream_buffers[i]
* cx->stream_buf_size[i]/(1024 * 1024);
}
} else {
if (cx->stream_buffers[i] < 0) {
cx->stream_buffers[i] =
cx->options.megabytes[i] * 1024
/ cx->stream_buf_size[i];
} else {
cx->options.megabytes[i] =
cx->stream_buffers[i]
* cx->stream_buf_size[i] / 1024;
}
cx->stream_buf_size[i] *= 1024;
}
CX18_DEBUG_INFO("Stream type %d options: %d MB, %d buffers, "
"%d bytes\n", i, cx->options.megabytes[i],
cx->stream_buffers[i], cx->stream_buf_size[i]);
}
cx->options.cardtype = cardtype[cx->instance];
cx->options.tuner = tuner[cx->instance];
cx->options.radio = radio[cx->instance];
cx->std = cx18_parse_std(cx);
if (cx->options.cardtype == -1) {
CX18_INFO("Ignore card\n");
return;
}
cx->card = cx18_get_card(cx->options.cardtype - 1);
if (cx->card)
CX18_INFO("User specified %s card\n", cx->card->name);
else if (cx->options.cardtype != 0)
CX18_ERR("Unknown user specified type, trying to autodetect card\n");
if (cx->card == NULL) {
if (cx->pci_dev->subsystem_vendor == CX18_PCI_ID_HAUPPAUGE) {
cx->card = cx18_get_card(CX18_CARD_HVR_1600_ESMT);
CX18_INFO("Autodetected Hauppauge card\n");
}
}
if (cx->card == NULL) {
for (i = 0; (cx->card = cx18_get_card(i)); i++) {
if (cx->card->pci_list == NULL)
continue;
for (j = 0; cx->card->pci_list[j].device; j++) {
if (cx->pci_dev->device !=
cx->card->pci_list[j].device)
continue;
if (cx->pci_dev->subsystem_vendor !=
cx->card->pci_list[j].subsystem_vendor)
continue;
if (cx->pci_dev->subsystem_device !=
cx->card->pci_list[j].subsystem_device)
continue;
CX18_INFO("Autodetected %s card\n", cx->card->name);
goto done;
}
}
}
done:
if (cx->card == NULL) {
cx->card = cx18_get_card(CX18_CARD_HVR_1600_ESMT);
CX18_ERR("Unknown card: vendor/device: [%04x:%04x]\n",
cx->pci_dev->vendor, cx->pci_dev->device);
CX18_ERR(" subsystem vendor/device: [%04x:%04x]\n",
cx->pci_dev->subsystem_vendor,
cx->pci_dev->subsystem_device);
CX18_ERR("Defaulting to %s card\n", cx->card->name);
CX18_ERR("Please mail the vendor/device and subsystem vendor/device IDs and what kind of\n");
CX18_ERR("card you have to the ivtv-devel mailinglist (www.ivtvdriver.org)\n");
CX18_ERR("Prefix your subject line with [UNKNOWN CX18 CARD].\n");
}
cx->v4l2_cap = cx->card->v4l2_capabilities;
cx->card_name = cx->card->name;
cx->card_i2c = cx->card->i2c;
}
static int cx18_create_in_workq(struct cx18 *cx)
{
snprintf(cx->in_workq_name, sizeof(cx->in_workq_name), "%s-in",
cx->v4l2_dev.name);
cx->in_work_queue = alloc_ordered_workqueue("%s", 0, cx->in_workq_name);
if (cx->in_work_queue == NULL) {
CX18_ERR("Unable to create incoming mailbox handler thread\n");
return -ENOMEM;
}
return 0;
}
static void cx18_init_in_work_orders(struct cx18 *cx)
{
int i;
for (i = 0; i < CX18_MAX_IN_WORK_ORDERS; i++) {
cx->in_work_order[i].cx = cx;
cx->in_work_order[i].str = cx->epu_debug_str;
INIT_WORK(&cx->in_work_order[i].work, cx18_in_work_handler);
}
}
static int cx18_init_struct1(struct cx18 *cx)
{
int ret;
cx->base_addr = pci_resource_start(cx->pci_dev, 0);
mutex_init(&cx->serialize_lock);
mutex_init(&cx->gpio_lock);
mutex_init(&cx->epu2apu_mb_lock);
mutex_init(&cx->epu2cpu_mb_lock);
ret = cx18_create_in_workq(cx);
if (ret)
return ret;
cx18_init_in_work_orders(cx);
cx->open_id = 1;
cx->cxhdl.port = CX2341X_PORT_MEMORY;
cx->cxhdl.capabilities = CX2341X_CAP_HAS_TS | CX2341X_CAP_HAS_SLICED_VBI;
cx->cxhdl.ops = &cx18_cxhdl_ops;
cx->cxhdl.func = cx18_api_func;
cx->cxhdl.priv = &cx->streams[CX18_ENC_STREAM_TYPE_MPG];
ret = cx2341x_handler_init(&cx->cxhdl, 50);
if (ret)
return ret;
cx->v4l2_dev.ctrl_handler = &cx->cxhdl.hdl;
cx->temporal_strength = cx->cxhdl.video_temporal_filter->cur.val;
cx->spatial_strength = cx->cxhdl.video_spatial_filter->cur.val;
cx->filter_mode = cx->cxhdl.video_spatial_filter_mode->cur.val |
(cx->cxhdl.video_temporal_filter_mode->cur.val << 1) |
(cx->cxhdl.video_median_filter_type->cur.val << 2);
init_waitqueue_head(&cx->cap_w);
init_waitqueue_head(&cx->mb_apu_waitq);
init_waitqueue_head(&cx->mb_cpu_waitq);
init_waitqueue_head(&cx->dma_waitq);
cx->vbi.in.type = V4L2_BUF_TYPE_VBI_CAPTURE;
cx->vbi.sliced_in = &cx->vbi.in.fmt.sliced;
INIT_LIST_HEAD(&cx->vbi.sliced_mpeg_buf.list);
INIT_LIST_HEAD(&cx->vbi.sliced_mpeg_mdl.list);
INIT_LIST_HEAD(&cx->vbi.sliced_mpeg_mdl.buf_list);
list_add(&cx->vbi.sliced_mpeg_buf.list,
&cx->vbi.sliced_mpeg_mdl.buf_list);
return 0;
}
static void cx18_init_struct2(struct cx18 *cx)
{
int i;
for (i = 0; i < CX18_CARD_MAX_VIDEO_INPUTS - 1; i++)
if (cx->card->video_inputs[i].video_type == 0)
break;
cx->nof_inputs = i;
for (i = 0; i < CX18_CARD_MAX_AUDIO_INPUTS - 1; i++)
if (cx->card->audio_inputs[i].audio_type == 0)
break;
cx->nof_audio_inputs = i;
for (i = 0; i < cx->nof_inputs; i++) {
if (cx->card->video_inputs[i].video_type ==
CX18_CARD_INPUT_VID_TUNER)
break;
}
if (i == cx->nof_inputs)
i = 0;
cx->active_input = i;
cx->audio_input = cx->card->video_inputs[i].audio_index;
}
static int cx18_setup_pci(struct cx18 *cx, struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
u16 cmd;
unsigned char pci_latency;
CX18_DEBUG_INFO("Enabling pci device\n");
if (pci_enable_device(pci_dev)) {
CX18_ERR("Can't enable device %d!\n", cx->instance);
return -EIO;
}
if (pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32))) {
CX18_ERR("No suitable DMA available, card %d\n", cx->instance);
return -EIO;
}
if (!request_mem_region(cx->base_addr, CX18_MEM_SIZE, "cx18 encoder")) {
CX18_ERR("Cannot request encoder memory region, card %d\n",
cx->instance);
return -EIO;
}
pci_read_config_word(pci_dev, PCI_COMMAND, &cmd);
cmd |= PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER;
pci_write_config_word(pci_dev, PCI_COMMAND, cmd);
cx->card_rev = pci_dev->revision;
pci_read_config_byte(pci_dev, PCI_LATENCY_TIMER, &pci_latency);
if (pci_latency < 64 && cx18_pci_latency) {
CX18_INFO("Unreasonably low latency timer, "
"setting to 64 (was %d)\n", pci_latency);
pci_write_config_byte(pci_dev, PCI_LATENCY_TIMER, 64);
pci_read_config_byte(pci_dev, PCI_LATENCY_TIMER, &pci_latency);
}
CX18_DEBUG_INFO("cx%d (rev %d) at %02x:%02x.%x, "
"irq: %d, latency: %d, memory: 0x%llx\n",
cx->pci_dev->device, cx->card_rev, pci_dev->bus->number,
PCI_SLOT(pci_dev->devfn), PCI_FUNC(pci_dev->devfn),
cx->pci_dev->irq, pci_latency, (u64)cx->base_addr);
return 0;
}
static void cx18_init_subdevs(struct cx18 *cx)
{
u32 hw = cx->card->hw_all;
u32 device;
int i;
for (i = 0, device = 1; i < 32; i++, device <<= 1) {
if (!(device & hw))
continue;
switch (device) {
case CX18_HW_DVB:
case CX18_HW_TVEEPROM:
cx->hw_flags |= device;
break;
case CX18_HW_418_AV:
cx->hw_flags |= device;
break;
case CX18_HW_GPIO_RESET_CTRL:
break;
case CX18_HW_GPIO_MUX:
if (cx18_gpio_register(cx, device) == 0)
cx->hw_flags |= device;
break;
default:
if (cx18_i2c_register(cx, i) == 0)
cx->hw_flags |= device;
break;
}
}
if (cx->hw_flags & CX18_HW_418_AV)
cx->sd_av = cx18_find_hw(cx, CX18_HW_418_AV);
if (cx->card->hw_muxer != 0)
cx->sd_extmux = cx18_find_hw(cx, cx->card->hw_muxer);
}
static int cx18_probe(struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
int retval = 0;
int i;
u32 devtype;
struct cx18 *cx;
i = atomic_inc_return(&cx18_instance) - 1;
if (i >= CX18_MAX_CARDS) {
printk(KERN_ERR "cx18: cannot manage card %d, driver has a "
"limit of 0 - %d\n", i, CX18_MAX_CARDS - 1);
return -ENOMEM;
}
cx = kzalloc(sizeof(struct cx18), GFP_ATOMIC);
if (cx == NULL) {
printk(KERN_ERR "cx18: cannot manage card %d, out of memory\n",
i);
return -ENOMEM;
}
cx->pci_dev = pci_dev;
cx->instance = i;
retval = v4l2_device_register(&pci_dev->dev, &cx->v4l2_dev);
if (retval) {
printk(KERN_ERR "cx18: v4l2_device_register of card %d failed"
"\n", cx->instance);
kfree(cx);
return retval;
}
snprintf(cx->v4l2_dev.name, sizeof(cx->v4l2_dev.name), "cx18-%d",
cx->instance);
CX18_INFO("Initializing card %d\n", cx->instance);
cx18_process_options(cx);
if (cx->options.cardtype == -1) {
retval = -ENODEV;
goto err;
}
retval = cx18_init_struct1(cx);
if (retval)
goto err;
CX18_DEBUG_INFO("base addr: 0x%llx\n", (u64)cx->base_addr);
retval = cx18_setup_pci(cx, pci_dev, pci_id);
if (retval != 0)
goto free_workqueues;
CX18_DEBUG_INFO("attempting ioremap at 0x%llx len 0x%08x\n",
(u64)cx->base_addr + CX18_MEM_OFFSET, CX18_MEM_SIZE);
cx->enc_mem = ioremap_nocache(cx->base_addr + CX18_MEM_OFFSET,
CX18_MEM_SIZE);
if (!cx->enc_mem) {
CX18_ERR("ioremap failed. Can't get a window into CX23418 "
"memory and register space\n");
CX18_ERR("Each capture card with a CX23418 needs 64 MB of "
"vmalloc address space for the window\n");
CX18_ERR("Check the output of 'grep Vmalloc /proc/meminfo'\n");
CX18_ERR("Use the vmalloc= kernel command line option to set "
"VmallocTotal to a larger value\n");
retval = -ENOMEM;
goto free_mem;
}
cx->reg_mem = cx->enc_mem + CX18_REG_OFFSET;
devtype = cx18_read_reg(cx, 0xC72028);
switch (devtype & 0xff000000) {
case 0xff000000:
CX18_INFO("cx23418 revision %08x (A)\n", devtype);
break;
case 0x01000000:
CX18_INFO("cx23418 revision %08x (B)\n", devtype);
break;
default:
CX18_INFO("cx23418 revision %08x (Unknown)\n", devtype);
break;
}
cx18_init_power(cx, 1);
cx18_init_memory(cx);
cx->scb = (struct cx18_scb __iomem *)(cx->enc_mem + SCB_OFFSET);
cx18_init_scb(cx);
cx18_gpio_init(cx);
retval = cx18_av_probe(cx);
if (retval) {
CX18_ERR("Could not register A/V decoder subdevice\n");
goto free_map;
}
if (cx->card->hw_all & CX18_HW_GPIO_RESET_CTRL) {
if (cx18_gpio_register(cx, CX18_HW_GPIO_RESET_CTRL) != 0)
CX18_WARN("Could not register GPIO reset controller"
"subdevice; proceeding anyway.\n");
else
cx->hw_flags |= CX18_HW_GPIO_RESET_CTRL;
}
CX18_DEBUG_INFO("activating i2c...\n");
retval = init_cx18_i2c(cx);
if (retval) {
CX18_ERR("Could not initialize i2c\n");
goto free_map;
}
if (cx->card->hw_all & CX18_HW_TVEEPROM) {
const struct cx18_card *orig_card = cx->card;
cx18_process_eeprom(cx);
if (cx->card != orig_card) {
cx18_gpio_init(cx);
cx18_call_hw(cx, CX18_HW_GPIO_RESET_CTRL,
core, reset, (u32) CX18_GPIO_RESET_I2C);
}
}
if (cx->card->comment)
CX18_INFO("%s", cx->card->comment);
if (cx->card->v4l2_capabilities == 0) {
retval = -ENODEV;
goto free_i2c;
}
cx18_init_memory(cx);
cx18_init_scb(cx);
retval = request_irq(cx->pci_dev->irq, cx18_irq_handler,
IRQF_SHARED, cx->v4l2_dev.name, (void *)cx);
if (retval) {
CX18_ERR("Failed to register irq %d\n", retval);
goto free_i2c;
}
if (cx->std == 0)
cx->std = V4L2_STD_NTSC_M;
if (cx->options.tuner == -1) {
for (i = 0; i < CX18_CARD_MAX_TUNERS; i++) {
if ((cx->std & cx->card->tuners[i].std) == 0)
continue;
cx->options.tuner = cx->card->tuners[i].tuner;
break;
}
}
if (cx->options.tuner == -1 && cx->card->tuners[0].std) {
cx->std = cx->card->tuners[0].std;
if (cx->std & V4L2_STD_PAL)
cx->std = V4L2_STD_PAL_BG | V4L2_STD_PAL_H;
else if (cx->std & V4L2_STD_NTSC)
cx->std = V4L2_STD_NTSC_M;
else if (cx->std & V4L2_STD_SECAM)
cx->std = V4L2_STD_SECAM_L;
cx->options.tuner = cx->card->tuners[0].tuner;
}
if (cx->options.radio == -1)
cx->options.radio = (cx->card->radio_input.audio_type != 0);
cx18_init_struct2(cx);
cx18_init_subdevs(cx);
if (cx->std & V4L2_STD_525_60)
cx->is_60hz = 1;
else
cx->is_50hz = 1;
cx2341x_handler_set_50hz(&cx->cxhdl, !cx->is_60hz);
if (cx->options.radio > 0)
cx->v4l2_cap |= V4L2_CAP_RADIO;
if (cx->options.tuner > -1) {
struct tuner_setup setup;
setup.addr = ADDR_UNSET;
setup.type = cx->options.tuner;
setup.mode_mask = T_ANALOG_TV;
setup.config = NULL;
if (cx->options.radio > 0)
setup.mode_mask |= T_RADIO;
setup.tuner_callback = (setup.type == TUNER_XC2028) ?
cx18_reset_tuner_gpio : NULL;
cx18_call_all(cx, tuner, s_type_addr, &setup);
if (setup.type == TUNER_XC2028) {
static struct xc2028_ctrl ctrl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
};
struct v4l2_priv_tun_config cfg = {
.tuner = cx->options.tuner,
.priv = &ctrl,
};
cx18_call_all(cx, tuner, s_config, &cfg);
}
}
cx->tuner_std = cx->std;
if (cx->std == V4L2_STD_ALL)
cx->std = V4L2_STD_NTSC_M;
retval = cx18_streams_setup(cx);
if (retval) {
CX18_ERR("Error %d setting up streams\n", retval);
goto free_irq;
}
retval = cx18_streams_register(cx);
if (retval) {
CX18_ERR("Error %d registering devices\n", retval);
goto free_streams;
}
CX18_INFO("Initialized card: %s\n", cx->card_name);
request_modules(cx);
return 0;
free_streams:
cx18_streams_cleanup(cx, 1);
free_irq:
free_irq(cx->pci_dev->irq, (void *)cx);
free_i2c:
exit_cx18_i2c(cx);
free_map:
cx18_iounmap(cx);
free_mem:
release_mem_region(cx->base_addr, CX18_MEM_SIZE);
free_workqueues:
destroy_workqueue(cx->in_work_queue);
err:
if (retval == 0)
retval = -ENODEV;
CX18_ERR("Error %d on initialization\n", retval);
v4l2_device_unregister(&cx->v4l2_dev);
kfree(cx);
return retval;
}
int cx18_init_on_first_open(struct cx18 *cx)
{
int video_input;
int fw_retry_count = 3;
struct v4l2_frequency vf;
struct cx18_open_id fh;
v4l2_std_id std;
fh.cx = cx;
if (test_bit(CX18_F_I_FAILED, &cx->i_flags))
return -ENXIO;
if (test_and_set_bit(CX18_F_I_INITED, &cx->i_flags))
return 0;
while (--fw_retry_count > 0) {
if (cx18_firmware_init(cx) == 0)
break;
if (fw_retry_count > 1)
CX18_WARN("Retry loading firmware\n");
}
if (fw_retry_count == 0) {
set_bit(CX18_F_I_FAILED, &cx->i_flags);
return -ENXIO;
}
set_bit(CX18_F_I_LOADED_FW, &cx->i_flags);
cx18_vapi(cx, CX18_APU_START, 2, CX18_APU_ENCODING_METHOD_MPEG|0xb9, 0);
cx18_vapi(cx, CX18_APU_RESETAI, 0);
cx18_vapi(cx, CX18_APU_STOP, 1, CX18_APU_ENCODING_METHOD_MPEG);
fw_retry_count = 3;
while (--fw_retry_count > 0) {
if (cx18_firmware_init(cx) == 0)
break;
if (fw_retry_count > 1)
CX18_WARN("Retry loading firmware\n");
}
if (fw_retry_count == 0) {
set_bit(CX18_F_I_FAILED, &cx->i_flags);
return -ENXIO;
}
cx18_vapi(cx, CX18_APU_START, 2, CX18_APU_ENCODING_METHOD_MPEG|0xb9, 0);
cx18_vapi(cx, CX18_APU_RESETAI, 0);
cx18_vapi(cx, CX18_APU_STOP, 1, CX18_APU_ENCODING_METHOD_MPEG);
v4l2_subdev_call(cx->sd_av, core, load_fw);
vf.tuner = 0;
vf.type = V4L2_TUNER_ANALOG_TV;
vf.frequency = 6400;
if (cx->std == V4L2_STD_NTSC_M_JP)
vf.frequency = 1460;
else if (cx->std & V4L2_STD_NTSC_M)
vf.frequency = 1076;
video_input = cx->active_input;
cx->active_input++;
cx18_s_input(NULL, &fh, video_input);
cx->std++;
std = (cx->tuner_std == V4L2_STD_ALL) ? V4L2_STD_NTSC_M : cx->tuner_std;
cx18_s_std(NULL, &fh, std);
cx18_s_frequency(NULL, &fh, &vf);
return 0;
}
static void cx18_cancel_in_work_orders(struct cx18 *cx)
{
int i;
for (i = 0; i < CX18_MAX_IN_WORK_ORDERS; i++)
cancel_work_sync(&cx->in_work_order[i].work);
}
static void cx18_cancel_out_work_orders(struct cx18 *cx)
{
int i;
for (i = 0; i < CX18_MAX_STREAMS; i++)
if (&cx->streams[i].video_dev != NULL)
cancel_work_sync(&cx->streams[i].out_work_order);
}
static void cx18_remove(struct pci_dev *pci_dev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct cx18 *cx = to_cx18(v4l2_dev);
int i;
CX18_DEBUG_INFO("Removing Card\n");
flush_request_modules(cx);
CX18_DEBUG_INFO("Stopping all streams\n");
if (atomic_read(&cx->tot_capturing) > 0)
cx18_stop_all_captures(cx);
cx18_sw1_irq_disable(cx, IRQ_CPU_TO_EPU | IRQ_APU_TO_EPU);
cx18_cancel_in_work_orders(cx);
cx18_cancel_out_work_orders(cx);
cx18_sw2_irq_disable(cx, IRQ_CPU_TO_EPU_ACK | IRQ_APU_TO_EPU_ACK);
cx18_halt_firmware(cx);
destroy_workqueue(cx->in_work_queue);
cx18_streams_cleanup(cx, 1);
exit_cx18_i2c(cx);
free_irq(cx->pci_dev->irq, (void *)cx);
cx18_iounmap(cx);
release_mem_region(cx->base_addr, CX18_MEM_SIZE);
pci_disable_device(cx->pci_dev);
if (cx->vbi.sliced_mpeg_data[0] != NULL)
for (i = 0; i < CX18_VBI_FRAMES; i++)
kfree(cx->vbi.sliced_mpeg_data[i]);
v4l2_ctrl_handler_free(&cx->av_state.hdl);
CX18_INFO("Removed %s\n", cx->card_name);
v4l2_device_unregister(v4l2_dev);
kfree(cx);
}
static int __init module_start(void)
{
printk(KERN_INFO "cx18: Start initialization, version %s\n",
CX18_VERSION);
if (cx18_first_minor < 0 || cx18_first_minor >= CX18_MAX_CARDS) {
printk(KERN_ERR "cx18: Exiting, cx18_first_minor must be between 0 and %d\n",
CX18_MAX_CARDS - 1);
return -1;
}
if (cx18_debug < 0 || cx18_debug > 511) {
cx18_debug = 0;
printk(KERN_INFO "cx18: Debug value must be >= 0 and <= 511!\n");
}
if (pci_register_driver(&cx18_pci_driver)) {
printk(KERN_ERR "cx18: Error detecting PCI card\n");
return -ENODEV;
}
printk(KERN_INFO "cx18: End initialization\n");
return 0;
}
static void __exit module_cleanup(void)
{
pci_unregister_driver(&cx18_pci_driver);
}
