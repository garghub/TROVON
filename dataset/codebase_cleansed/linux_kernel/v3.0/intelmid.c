static int snd_intelmad_pcm_trigger(struct snd_pcm_substream *substream,
int cmd)
{
int ret_val = 0, str_id;
struct snd_intelmad *intelmaddata;
struct mad_stream_pvt *stream;
struct intel_sst_pcm_control *sst_ops;
WARN_ON(!substream);
intelmaddata = snd_pcm_substream_chip(substream);
stream = substream->runtime->private_data;
WARN_ON(!intelmaddata->sstdrv_ops);
WARN_ON(!intelmaddata->sstdrv_ops->scard_ops);
sst_ops = intelmaddata->sstdrv_ops->pcm_control;
str_id = stream->stream_info.str_id;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
pr_debug("Trigger Start\n");
ret_val = sst_ops->device_control(SST_SND_START, &str_id);
if (ret_val)
return ret_val;
stream->stream_status = RUNNING;
stream->substream = substream;
break;
case SNDRV_PCM_TRIGGER_STOP:
pr_debug("in stop\n");
ret_val = sst_ops->device_control(SST_SND_DROP, &str_id);
if (ret_val)
return ret_val;
stream->stream_status = DROPPED;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
pr_debug("in pause\n");
ret_val = sst_ops->device_control(SST_SND_PAUSE, &str_id);
if (ret_val)
return ret_val;
stream->stream_status = PAUSED;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
pr_debug("in pause release\n");
ret_val = sst_ops->device_control(SST_SND_RESUME, &str_id);
if (ret_val)
return ret_val;
stream->stream_status = RUNNING;
break;
default:
return -EINVAL;
}
return ret_val;
}
static int snd_intelmad_pcm_prepare(struct snd_pcm_substream *substream)
{
struct mad_stream_pvt *stream;
int ret_val = 0;
struct snd_intelmad *intelmaddata;
pr_debug("pcm_prepare called\n");
WARN_ON(!substream);
stream = substream->runtime->private_data;
intelmaddata = snd_pcm_substream_chip(substream);
pr_debug("pb cnt = %d cap cnt = %d\n",\
intelmaddata->playback_cnt,
intelmaddata->capture_cnt);
if (stream->stream_info.str_id) {
pr_debug("Prepare called for already set stream\n");
ret_val = intelmaddata->sstdrv_ops->pcm_control->device_control(
SST_SND_DROP, &stream->stream_info.str_id);
return ret_val;
}
ret_val = snd_intelmad_alloc_stream(substream);
if (ret_val < 0)
return ret_val;
stream->dbg_cum_bytes = 0;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
intelmaddata->playback_cnt++;
else
intelmaddata->capture_cnt++;
snprintf(substream->pcm->id, sizeof(substream->pcm->id),
"%d", stream->stream_info.str_id);
pr_debug("stream id to user = %s\n",
substream->pcm->id);
ret_val = snd_intelmad_init_stream(substream);
if (ret_val)
return ret_val;
substream->runtime->hw.info = SNDRV_PCM_INFO_BLOCK_TRANSFER;
return ret_val;
}
static int snd_intelmad_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int ret_val;
pr_debug("snd_intelmad_hw_params called\n");
ret_val = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
memset(substream->runtime->dma_area, 0,
params_buffer_bytes(hw_params));
return ret_val;
}
static int snd_intelmad_hw_free(struct snd_pcm_substream *substream)
{
pr_debug("snd_intelmad_hw_free called\n");
return snd_pcm_lib_free_pages(substream);
}
static snd_pcm_uframes_t snd_intelmad_pcm_pointer
(struct snd_pcm_substream *substream)
{
struct mad_stream_pvt *stream;
struct snd_intelmad *intelmaddata;
int ret_val;
WARN_ON(!substream);
intelmaddata = snd_pcm_substream_chip(substream);
stream = substream->runtime->private_data;
if (stream->stream_status == INIT)
return 0;
ret_val = intelmaddata->sstdrv_ops->pcm_control->device_control(
SST_SND_BUFFER_POINTER, &stream->stream_info);
if (ret_val) {
pr_err("error code = 0x%x\n", ret_val);
return ret_val;
}
pr_debug("samples reported out 0x%llx\n",
stream->stream_info.buffer_ptr);
pr_debug("Frame bits:: %d period_count :: %d\n",
(int)substream->runtime->frame_bits,
(int)substream->runtime->period_size);
return stream->stream_info.buffer_ptr;
}
static int snd_intelmad_close(struct snd_pcm_substream *substream)
{
struct snd_intelmad *intelmaddata;
struct mad_stream_pvt *stream;
int ret_val = 0, str_id;
WARN_ON(!substream);
stream = substream->runtime->private_data;
str_id = stream->stream_info.str_id;
pr_debug("sst: snd_intelmad_close called for %d\n", str_id);
intelmaddata = snd_pcm_substream_chip(substream);
pr_debug("str id = %d\n", stream->stream_info.str_id);
if (stream->stream_info.str_id) {
ret_val = intelmaddata->sstdrv_ops->pcm_control->close(str_id);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
intelmaddata->playback_cnt--;
else
intelmaddata->capture_cnt--;
}
pr_debug("snd_intelmad_close : pb cnt = %d cap cnt = %d\n",
intelmaddata->playback_cnt, intelmaddata->capture_cnt);
kfree(substream->runtime->private_data);
return ret_val;
}
static int snd_intelmad_open(struct snd_pcm_substream *substream,
enum snd_sst_audio_device_type type)
{
struct snd_intelmad *intelmaddata;
struct snd_pcm_runtime *runtime;
struct mad_stream_pvt *stream;
WARN_ON(!substream);
pr_debug("snd_intelmad_open called\n");
intelmaddata = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
runtime->hw = snd_intelmad_stream;
if (intelmaddata->cpu_id == CPU_CHIP_LINCROFT) {
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
runtime->hw.formats = (SNDRV_PCM_FMTBIT_S16 |
SNDRV_PCM_FMTBIT_U16);
runtime->hw.channels_max = 1;
}
}
if (intelmaddata->cpu_id == CPU_CHIP_PENWELL) {
runtime->hw = snd_intelmad_stream;
runtime->hw.rates = SNDRV_PCM_RATE_48000;
runtime->hw.rate_min = MAX_RATE;
runtime->hw.formats = (SNDRV_PCM_FMTBIT_S24 |
SNDRV_PCM_FMTBIT_U24);
if (intelmaddata->sstdrv_ops->scard_ops->input_dev_id == AMIC)
runtime->hw.channels_max = MAX_CHANNEL_AMIC;
else
runtime->hw.channels_max = MAX_CHANNEL_DMIC;
}
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (!stream)
return -ENOMEM;
stream->stream_info.str_id = 0;
stream->device = type;
stream->stream_status = INIT;
runtime->private_data = stream;
return snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
}
static int snd_intelmad_headset_open(struct snd_pcm_substream *substream)
{
return snd_intelmad_open(substream, SND_SST_DEVICE_HEADSET);
}
static int snd_intelmad_ihf_open(struct snd_pcm_substream *substream)
{
return snd_intelmad_open(substream, SND_SST_DEVICE_IHF);
}
static int snd_intelmad_vibra_open(struct snd_pcm_substream *substream)
{
return snd_intelmad_open(substream, SND_SST_DEVICE_VIBRA);
}
static int snd_intelmad_haptic_open(struct snd_pcm_substream *substream)
{
return snd_intelmad_open(substream, SND_SST_DEVICE_HAPTIC);
}
int intelmad_get_mic_bias(void)
{
struct snd_pmic_ops *pmic_ops;
if (!intelmad_drv || !intelmad_drv->sstdrv_ops)
return -ENODEV;
pmic_ops = intelmad_drv->sstdrv_ops->scard_ops;
if (pmic_ops && pmic_ops->pmic_get_mic_bias)
return pmic_ops->pmic_get_mic_bias(intelmad_drv);
else
return -ENODEV;
}
int intelmad_set_headset_state(int state)
{
struct snd_pmic_ops *pmic_ops;
if (!intelmad_drv || !intelmad_drv->sstdrv_ops)
return -ENODEV;
pmic_ops = intelmad_drv->sstdrv_ops->scard_ops;
if (pmic_ops && pmic_ops->pmic_set_headset_state)
return pmic_ops->pmic_set_headset_state(state);
else
return -ENODEV;
}
void sst_process_mad_jack_detection(struct work_struct *work)
{
u8 interrupt_status;
struct mad_jack_msg_wq *mad_jack_detect =
container_of(work, struct mad_jack_msg_wq, wq);
struct snd_intelmad *intelmaddata =
mad_jack_detect->intelmaddata;
if (!intelmaddata)
return;
interrupt_status = mad_jack_detect->intsts;
if (intelmaddata->sstdrv_ops && intelmaddata->sstdrv_ops->scard_ops
&& intelmaddata->sstdrv_ops->scard_ops->pmic_irq_cb) {
intelmaddata->sstdrv_ops->scard_ops->pmic_irq_cb(
(void *)intelmaddata, interrupt_status);
intelmaddata->sstdrv_ops->scard_ops->pmic_jack_enable();
}
kfree(mad_jack_detect);
}
static irqreturn_t snd_intelmad_intr_handler(int irq, void *dev)
{
struct snd_intelmad *intelmaddata =
(struct snd_intelmad *)dev;
u8 interrupt_status;
struct mad_jack_msg_wq *mad_jack_msg;
memcpy_fromio(&interrupt_status,
((void *)(intelmaddata->int_base)),
sizeof(u8));
mad_jack_msg = kzalloc(sizeof(*mad_jack_msg), GFP_ATOMIC);
mad_jack_msg->intsts = interrupt_status;
mad_jack_msg->intelmaddata = intelmaddata;
INIT_WORK(&mad_jack_msg->wq, sst_process_mad_jack_detection);
queue_work(intelmaddata->mad_jack_wq, &mad_jack_msg->wq);
return IRQ_HANDLED;
}
void sst_mad_send_jack_report(struct snd_jack *jack,
int buttonpressevent , int status)
{
if (!jack) {
pr_debug("MAD error jack empty\n");
} else {
snd_jack_report(jack, status);
if (buttonpressevent)
snd_jack_report(jack, 0);
pr_debug("MAD sending jack report Done !!!\n");
}
}
static int __devinit snd_intelmad_register_irq(
struct snd_intelmad *intelmaddata, unsigned int regbase,
unsigned int regsize)
{
int ret_val;
char *drv_name;
pr_debug("irq reg regbase 0x%x, regsize 0x%x\n",
regbase, regsize);
intelmaddata->int_base = ioremap_nocache(regbase, regsize);
if (!intelmaddata->int_base)
pr_err("Mapping of cache failed\n");
pr_debug("irq = 0x%x\n", intelmaddata->irq);
if (intelmaddata->cpu_id == CPU_CHIP_PENWELL)
drv_name = DRIVER_NAME_MFLD;
else
drv_name = DRIVER_NAME_MRST;
ret_val = request_irq(intelmaddata->irq,
snd_intelmad_intr_handler,
IRQF_SHARED, drv_name,
intelmaddata);
if (ret_val)
pr_err("cannot register IRQ\n");
return ret_val;
}
static int __devinit snd_intelmad_sst_register(
struct snd_intelmad *intelmaddata)
{
int ret_val = 0;
struct snd_pmic_ops *intelmad_vendor_ops[MAX_VENDORS] = {
&snd_pmic_ops_fs,
&snd_pmic_ops_mx,
&snd_pmic_ops_nc,
&snd_msic_ops
};
struct sc_reg_access vendor_addr = {0x00, 0x00, 0x00};
if (intelmaddata->cpu_id == CPU_CHIP_LINCROFT) {
ret_val = sst_sc_reg_access(&vendor_addr, PMIC_READ, 1);
if (ret_val)
return ret_val;
sst_card_vendor_id = (vendor_addr.value & (MASK2|MASK1|MASK0));
pr_debug("original n extrated vendor id = 0x%x %d\n",
vendor_addr.value, sst_card_vendor_id);
if (sst_card_vendor_id < 0 || sst_card_vendor_id > 2) {
pr_err("vendor card not supported!!\n");
return -EIO;
}
} else
sst_card_vendor_id = 0x3;
intelmaddata->sstdrv_ops->module_name = SST_CARD_NAMES;
intelmaddata->sstdrv_ops->vendor_id = sst_card_vendor_id;
BUG_ON(!intelmad_vendor_ops[sst_card_vendor_id]);
intelmaddata->sstdrv_ops->scard_ops =
intelmad_vendor_ops[sst_card_vendor_id];
if (intelmaddata->cpu_id == CPU_CHIP_PENWELL) {
intelmaddata->sstdrv_ops->scard_ops->pb_on = 0;
intelmaddata->sstdrv_ops->scard_ops->cap_on = 0;
intelmaddata->sstdrv_ops->scard_ops->input_dev_id = DMIC;
intelmaddata->sstdrv_ops->scard_ops->output_dev_id =
STEREO_HEADPHONE;
intelmaddata->sstdrv_ops->scard_ops->lineout_dev_id = NONE;
}
ret_val = register_sst_card(intelmaddata->sstdrv_ops);
if (ret_val) {
pr_err("sst card registration failed\n");
return ret_val;
}
sst_card_vendor_id = intelmaddata->sstdrv_ops->vendor_id;
intelmaddata->pmic_status = PMIC_UNINIT;
return ret_val;
}
static void snd_intelmad_page_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int __devinit snd_intelmad_pcm_new(struct snd_card *card,
struct snd_intelmad *intelmaddata,
unsigned int pb, unsigned int cap, unsigned int index)
{
int ret_val = 0;
struct snd_pcm *pcm;
char name[32] = INTEL_MAD;
struct snd_pcm_ops *pb_ops = NULL, *cap_ops = NULL;
pr_debug("called for pb %d, cp %d, idx %d\n", pb, cap, index);
ret_val = snd_pcm_new(card, name, index, pb, cap, &pcm);
if (ret_val)
return ret_val;
switch (index) {
case 0:
pb_ops = &snd_intelmad_headset_ops;
cap_ops = &snd_intelmad_capture_ops;
break;
case 1:
pb_ops = &snd_intelmad_ihf_ops;
cap_ops = &snd_intelmad_capture_ops;
break;
case 2:
pb_ops = &snd_intelmad_vibra_ops;
cap_ops = &snd_intelmad_capture_ops;
break;
case 3:
pb_ops = &snd_intelmad_haptic_ops;
cap_ops = &snd_intelmad_capture_ops;
break;
}
if (pb)
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, pb_ops);
if (cap)
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, cap_ops);
pcm->private_data = intelmaddata;
pcm->private_free = snd_intelmad_page_free;
pcm->info_flags = 0;
strncpy(pcm->name, card->shortname, strlen(card->shortname));
snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
MIN_BUFFER, MAX_BUFFER);
return ret_val;
}
static int __devinit snd_intelmad_pcm(struct snd_card *card,
struct snd_intelmad *intelmaddata)
{
int ret_val = 0;
WARN_ON(!card);
WARN_ON(!intelmaddata);
pr_debug("snd_intelmad_pcm called\n");
ret_val = snd_intelmad_pcm_new(card, intelmaddata, 1, 1, 0);
if (intelmaddata->cpu_id == CPU_CHIP_LINCROFT)
return ret_val;
ret_val = snd_intelmad_pcm_new(card, intelmaddata, 1, 0, 1);
if (ret_val)
return ret_val;
ret_val = snd_intelmad_pcm_new(card, intelmaddata, 1, 0, 2);
if (ret_val)
return ret_val;
return snd_intelmad_pcm_new(card, intelmaddata, 1, 0, 3);
}
static int snd_intelmad_jack(struct snd_intelmad *intelmaddata)
{
struct snd_jack *jack;
int retval;
pr_debug("snd_intelmad_jack called\n");
jack = &intelmaddata->jack[0].jack;
snd_jack_set_key(jack, SND_JACK_BTN_0, KEY_PHONE);
retval = snd_jack_new(intelmaddata->card, "Intel(R) MID Audio Jack",
SND_JACK_HEADPHONE | SND_JACK_HEADSET |
SW_JACK_PHYSICAL_INSERT | SND_JACK_BTN_0
| SND_JACK_BTN_1, &jack);
pr_debug("snd_intelmad_jack called\n");
if (retval < 0)
return retval;
snd_jack_report(jack, 0);
jack->private_data = jack;
intelmaddata->jack[0].jack = *jack;
return retval;
}
static int __devinit snd_intelmad_mixer(struct snd_intelmad *intelmaddata)
{
struct snd_card *card;
unsigned int idx;
int ret_val = 0, max_controls = 0;
char *mixername = "IntelMAD Controls";
struct snd_kcontrol_new *controls;
WARN_ON(!intelmaddata);
card = intelmaddata->card;
strncpy(card->mixername, mixername, sizeof(card->mixername)-1);
if (intelmaddata->cpu_id == CPU_CHIP_PENWELL) {
max_controls = MAX_CTRL_MFLD;
controls = snd_intelmad_controls_mfld;
} else {
max_controls = MAX_CTRL_MRST;
controls = snd_intelmad_controls_mrst;
}
for (idx = 0; idx < max_controls; idx++) {
ret_val = snd_ctl_add(card,
snd_ctl_new1(&controls[idx],
intelmaddata));
pr_debug("mixer[idx]=%d added\n", idx);
if (ret_val) {
pr_err("in adding of control index = %d\n", idx);
break;
}
}
return ret_val;
}
static int snd_intelmad_dev_free(struct snd_device *device)
{
struct snd_intelmad *intelmaddata;
WARN_ON(!device);
intelmaddata = device->device_data;
pr_debug("snd_intelmad_dev_free called\n");
unregister_sst_card(intelmaddata->sstdrv_ops);
destroy_workqueue(intelmaddata->mad_jack_wq);
device->device_data = NULL;
kfree(intelmaddata->sstdrv_ops);
kfree(intelmaddata);
return 0;
}
static int __devinit snd_intelmad_create(
struct snd_intelmad *intelmaddata,
struct snd_card *card)
{
int ret_val;
static struct snd_device_ops ops = {
.dev_free = snd_intelmad_dev_free,
};
WARN_ON(!intelmaddata);
WARN_ON(!card);
ret_val = snd_device_new(card, SNDRV_DEV_LOWLEVEL, intelmaddata, &ops);
return ret_val;
}
int __devinit snd_intelmad_probe(struct platform_device *pdev)
{
struct snd_card *card;
int ret_val;
struct snd_intelmad *intelmaddata;
const struct platform_device_id *id = platform_get_device_id(pdev);
struct snd_intelmad_probe_info *info = (void *)id->driver_data;
pr_debug("probe for %s cpu_id %d\n", pdev->name, info->cpu_id);
pr_debug("rq_chache %x of size %x\n", info->irq_cache, info->size);
if (!strcmp(pdev->name, DRIVER_NAME_MRST))
pr_debug("detected MRST\n");
else if (!strcmp(pdev->name, DRIVER_NAME_MFLD))
pr_debug("detected MFLD\n");
else {
pr_err("detected unknown device abort!!\n");
return -EIO;
}
if ((info->cpu_id < CPU_CHIP_LINCROFT) ||
(info->cpu_id > CPU_CHIP_PENWELL)) {
pr_err("detected unknown cpu_id abort!!\n");
return -EIO;
}
intelmaddata = kzalloc(sizeof(*intelmaddata), GFP_KERNEL);
if (!intelmaddata) {
pr_debug("mem alloctn fail\n");
return -ENOMEM;
}
intelmad_drv = intelmaddata;
intelmaddata->sstdrv_ops = kzalloc(sizeof(struct intel_sst_card_ops),
GFP_KERNEL);
if (!intelmaddata->sstdrv_ops) {
pr_err("mem allocation for ops fail\n");
kfree(intelmaddata);
return -ENOMEM;
}
intelmaddata->cpu_id = info->cpu_id;
ret_val = snd_card_create(card_index, card_id, THIS_MODULE, 0, &card);
if (ret_val) {
pr_err("snd_card_create fail\n");
goto free_allocs;
}
intelmaddata->pdev = pdev;
intelmaddata->irq = platform_get_irq(pdev, 0);
platform_set_drvdata(pdev, intelmaddata);
intelmaddata->card = card;
intelmaddata->card_id = card_id;
intelmaddata->card_index = card_index;
intelmaddata->master_mute = UNMUTE;
intelmaddata->playback_cnt = intelmaddata->capture_cnt = 0;
strncpy(card->driver, INTEL_MAD, strlen(INTEL_MAD));
strncpy(card->shortname, INTEL_MAD, strlen(INTEL_MAD));
intelmaddata->sstdrv_ops->module_name = SST_CARD_NAMES;
ret_val = snd_intelmad_sst_register(intelmaddata);
if (ret_val) {
pr_err("snd_intelmad_sst_register failed\n");
goto set_null_data;
}
intelmaddata->pmic_status = PMIC_INIT;
ret_val = snd_intelmad_pcm(card, intelmaddata);
if (ret_val) {
pr_err("snd_intelmad_pcm failed\n");
goto free_sst;
}
ret_val = snd_intelmad_mixer(intelmaddata);
if (ret_val) {
pr_err("snd_intelmad_mixer failed\n");
goto free_card;
}
ret_val = snd_intelmad_jack(intelmaddata);
if (ret_val) {
pr_err("snd_intelmad_jack failed\n");
goto free_card;
}
intelmaddata->adc_address = mid_initialize_adc();
INIT_WORK(&intelmaddata->mad_jack_msg.wq,
sst_process_mad_jack_detection);
intelmaddata->mad_jack_wq = create_workqueue("sst_mad_jack_wq");
if (!intelmaddata->mad_jack_wq)
goto free_card;
ret_val = snd_intelmad_register_irq(intelmaddata,
info->irq_cache, info->size);
if (ret_val) {
pr_err("snd_intelmad_register_irq fail\n");
goto free_mad_jack_wq;
}
ret_val = snd_intelmad_create(intelmaddata, card);
if (ret_val) {
pr_err("snd_intelmad_create failed\n");
goto set_pvt_data;
}
card->private_data = &intelmaddata;
snd_card_set_dev(card, &pdev->dev);
ret_val = snd_card_register(card);
if (ret_val) {
pr_err("snd_card_register failed\n");
goto set_pvt_data;
}
if (pdev->dev.platform_data) {
int gpio_amp = *(int *)pdev->dev.platform_data;
if (gpio_request_one(gpio_amp, GPIOF_OUT_INIT_LOW, "amp power"))
gpio_amp = 0;
intelmaddata->sstdrv_ops->scard_ops->gpio_amp = gpio_amp;
}
pr_debug("snd_intelmad_probe complete\n");
return ret_val;
set_pvt_data:
card->private_data = NULL;
free_mad_jack_wq:
destroy_workqueue(intelmaddata->mad_jack_wq);
free_card:
snd_card_free(intelmaddata->card);
free_sst:
unregister_sst_card(intelmaddata->sstdrv_ops);
set_null_data:
platform_set_drvdata(pdev, NULL);
free_allocs:
pr_err("probe failed\n");
snd_card_free(card);
kfree(intelmaddata->sstdrv_ops);
kfree(intelmaddata);
return ret_val;
}
static int snd_intelmad_remove(struct platform_device *pdev)
{
struct snd_intelmad *intelmaddata = platform_get_drvdata(pdev);
if (intelmaddata) {
if (intelmaddata->sstdrv_ops->scard_ops->gpio_amp)
gpio_free(intelmaddata->sstdrv_ops->scard_ops->gpio_amp);
free_irq(intelmaddata->irq, intelmaddata);
snd_card_free(intelmaddata->card);
}
intelmad_drv = NULL;
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init alsa_card_intelmad_init(void)
{
pr_debug("mad_init called\n");
return platform_driver_register(&snd_intelmad_driver);
}
static void __exit alsa_card_intelmad_exit(void)
{
pr_debug("mad_exit called\n");
return platform_driver_unregister(&snd_intelmad_driver);
}
