static inline
struct audio_dev *func_to_agdev(struct usb_function *f)
{
return container_of(f, struct audio_dev, func);
}
static inline
struct audio_dev *uac2_to_agdev(struct snd_uac2_chip *u)
{
return container_of(u, struct audio_dev, uac2);
}
static inline
struct snd_uac2_chip *pdev_to_uac2(struct platform_device *p)
{
return container_of(p, struct snd_uac2_chip, pdev);
}
static inline
struct snd_uac2_chip *prm_to_uac2(struct uac2_rtd_params *r)
{
struct snd_uac2_chip *uac2 = container_of(r,
struct snd_uac2_chip, c_prm);
if (&uac2->c_prm != r)
uac2 = container_of(r, struct snd_uac2_chip, p_prm);
return uac2;
}
static inline
uint num_channels(uint chanmask)
{
uint num = 0;
while (chanmask) {
num += (chanmask & 1);
chanmask >>= 1;
}
return num;
}
static void
agdev_iso_complete(struct usb_ep *ep, struct usb_request *req)
{
unsigned pending;
unsigned long flags;
bool update_alsa = false;
unsigned char *src, *dst;
int status = req->status;
struct uac2_req *ur = req->context;
struct snd_pcm_substream *substream;
struct uac2_rtd_params *prm = ur->pp;
struct snd_uac2_chip *uac2 = prm_to_uac2(prm);
if (!prm->ep_enabled)
return;
if (status)
pr_debug("%s: iso_complete status(%d) %d/%d\n",
__func__, status, req->actual, req->length);
substream = prm->ss;
if (!substream)
goto exit;
spin_lock_irqsave(&prm->lock, flags);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
src = prm->dma_area + prm->hw_ptr;
req->actual = req->length;
dst = req->buf;
} else {
dst = prm->dma_area + prm->hw_ptr;
src = req->buf;
}
pending = prm->hw_ptr % prm->period_size;
pending += req->actual;
if (pending >= prm->period_size)
update_alsa = true;
prm->hw_ptr = (prm->hw_ptr + req->actual) % prm->dma_bytes;
spin_unlock_irqrestore(&prm->lock, flags);
memcpy(dst, src, req->actual);
exit:
if (usb_ep_queue(ep, req, GFP_ATOMIC))
dev_err(&uac2->pdev.dev, "%d Error!\n", __LINE__);
if (update_alsa)
snd_pcm_period_elapsed(substream);
return;
}
static int
uac2_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_uac2_chip *uac2 = snd_pcm_substream_chip(substream);
struct uac2_rtd_params *prm;
unsigned long flags;
int err = 0;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac2->p_prm;
else
prm = &uac2->c_prm;
spin_lock_irqsave(&prm->lock, flags);
prm->hw_ptr = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
prm->ss = substream;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
prm->ss = NULL;
break;
default:
err = -EINVAL;
}
spin_unlock_irqrestore(&prm->lock, flags);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK && !prm->ss)
memset(prm->rbuf, 0, prm->max_psize * USB_XFERS);
return err;
}
static snd_pcm_uframes_t uac2_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_uac2_chip *uac2 = snd_pcm_substream_chip(substream);
struct uac2_rtd_params *prm;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac2->p_prm;
else
prm = &uac2->c_prm;
return bytes_to_frames(substream->runtime, prm->hw_ptr);
}
static int uac2_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_uac2_chip *uac2 = snd_pcm_substream_chip(substream);
struct uac2_rtd_params *prm;
int err;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac2->p_prm;
else
prm = &uac2->c_prm;
err = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (err >= 0) {
prm->dma_bytes = substream->runtime->dma_bytes;
prm->dma_area = substream->runtime->dma_area;
prm->period_size = params_period_bytes(hw_params);
}
return err;
}
static int uac2_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_uac2_chip *uac2 = snd_pcm_substream_chip(substream);
struct uac2_rtd_params *prm;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac2->p_prm;
else
prm = &uac2->c_prm;
prm->dma_area = NULL;
prm->dma_bytes = 0;
prm->period_size = 0;
return snd_pcm_lib_free_pages(substream);
}
static int uac2_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_uac2_chip *uac2 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
runtime->hw = uac2_pcm_hardware;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
spin_lock_init(&uac2->p_prm.lock);
runtime->hw.rate_min = p_srate;
runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
runtime->hw.channels_min = num_channels(p_chmask);
runtime->hw.period_bytes_min = 2 * uac2->p_prm.max_psize
/ runtime->hw.periods_min;
} else {
spin_lock_init(&uac2->c_prm.lock);
runtime->hw.rate_min = c_srate;
runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
runtime->hw.channels_min = num_channels(c_chmask);
runtime->hw.period_bytes_min = 2 * uac2->c_prm.max_psize
/ runtime->hw.periods_min;
}
runtime->hw.rate_max = runtime->hw.rate_min;
runtime->hw.channels_max = runtime->hw.channels_min;
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
return 0;
}
static int uac2_pcm_null(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_uac2_probe(struct platform_device *pdev)
{
struct snd_uac2_chip *uac2 = pdev_to_uac2(pdev);
struct snd_card *card;
struct snd_pcm *pcm;
int err;
err = snd_card_create(-1, NULL, THIS_MODULE, 0, &card);
if (err < 0)
return err;
uac2->card = card;
err = snd_pcm_new(uac2->card, "UAC2 PCM", 0,
p_chmask ? 1 : 0, c_chmask ? 1 : 0, &pcm);
if (err < 0)
goto snd_fail;
strcpy(pcm->name, "UAC2 PCM");
pcm->private_data = uac2;
uac2->pcm = pcm;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &uac2_pcm_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &uac2_pcm_ops);
strcpy(card->driver, "UAC2_Gadget");
strcpy(card->shortname, "UAC2_Gadget");
sprintf(card->longname, "UAC2_Gadget %i", pdev->id);
snd_card_set_dev(card, &pdev->dev);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL), 0, BUFF_SIZE_MAX);
err = snd_card_register(card);
if (!err) {
platform_set_drvdata(pdev, card);
return 0;
}
snd_fail:
snd_card_free(card);
uac2->pcm = NULL;
uac2->card = NULL;
return err;
}
static int snd_uac2_remove(struct platform_device *pdev)
{
struct snd_card *card = platform_get_drvdata(pdev);
if (card)
return snd_card_free(card);
return 0;
}
static int alsa_uac2_init(struct audio_dev *agdev)
{
struct snd_uac2_chip *uac2 = &agdev->uac2;
int err;
uac2->pdrv.probe = snd_uac2_probe;
uac2->pdrv.remove = snd_uac2_remove;
uac2->pdrv.driver.name = uac2_name;
uac2->pdev.id = 0;
uac2->pdev.name = uac2_name;
err = platform_driver_register(&uac2->pdrv);
if (err)
return err;
err = platform_device_register(&uac2->pdev);
if (err)
platform_driver_unregister(&uac2->pdrv);
return err;
}
static void alsa_uac2_exit(struct audio_dev *agdev)
{
struct snd_uac2_chip *uac2 = &agdev->uac2;
platform_driver_unregister(&uac2->pdrv);
platform_device_unregister(&uac2->pdev);
}
static inline void
free_ep(struct uac2_rtd_params *prm, struct usb_ep *ep)
{
struct snd_uac2_chip *uac2 = prm_to_uac2(prm);
int i;
prm->ep_enabled = false;
for (i = 0; i < USB_XFERS; i++) {
if (prm->ureq[i].req) {
usb_ep_dequeue(ep, prm->ureq[i].req);
usb_ep_free_request(ep, prm->ureq[i].req);
prm->ureq[i].req = NULL;
}
}
if (usb_ep_disable(ep))
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
}
static int __init
afunc_bind(struct usb_configuration *cfg, struct usb_function *fn)
{
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
struct usb_composite_dev *cdev = cfg->cdev;
struct usb_gadget *gadget = cdev->gadget;
struct uac2_rtd_params *prm;
int ret;
ret = usb_interface_id(cfg, fn);
if (ret < 0) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return ret;
}
std_ac_if_desc.bInterfaceNumber = ret;
agdev->ac_intf = ret;
agdev->ac_alt = 0;
ret = usb_interface_id(cfg, fn);
if (ret < 0) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return ret;
}
std_as_out_if0_desc.bInterfaceNumber = ret;
std_as_out_if1_desc.bInterfaceNumber = ret;
agdev->as_out_intf = ret;
agdev->as_out_alt = 0;
ret = usb_interface_id(cfg, fn);
if (ret < 0) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return ret;
}
std_as_in_if0_desc.bInterfaceNumber = ret;
std_as_in_if1_desc.bInterfaceNumber = ret;
agdev->as_in_intf = ret;
agdev->as_in_alt = 0;
agdev->out_ep = usb_ep_autoconfig(gadget, &fs_epout_desc);
if (!agdev->out_ep) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
goto err;
}
agdev->out_ep->driver_data = agdev;
agdev->in_ep = usb_ep_autoconfig(gadget, &fs_epin_desc);
if (!agdev->in_ep) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
goto err;
}
agdev->in_ep->driver_data = agdev;
hs_epout_desc.bEndpointAddress = fs_epout_desc.bEndpointAddress;
hs_epout_desc.wMaxPacketSize = fs_epout_desc.wMaxPacketSize;
hs_epin_desc.bEndpointAddress = fs_epin_desc.bEndpointAddress;
hs_epin_desc.wMaxPacketSize = fs_epin_desc.wMaxPacketSize;
ret = usb_assign_descriptors(fn, fs_audio_desc, hs_audio_desc, NULL);
if (ret)
goto err;
prm = &agdev->uac2.c_prm;
prm->max_psize = hs_epout_desc.wMaxPacketSize;
prm->rbuf = kzalloc(prm->max_psize * USB_XFERS, GFP_KERNEL);
if (!prm->rbuf) {
prm->max_psize = 0;
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
goto err;
}
prm = &agdev->uac2.p_prm;
prm->max_psize = hs_epin_desc.wMaxPacketSize;
prm->rbuf = kzalloc(prm->max_psize * USB_XFERS, GFP_KERNEL);
if (!prm->rbuf) {
prm->max_psize = 0;
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
goto err;
}
ret = alsa_uac2_init(agdev);
if (ret)
goto err;
return 0;
err:
kfree(agdev->uac2.p_prm.rbuf);
kfree(agdev->uac2.c_prm.rbuf);
usb_free_all_descriptors(fn);
if (agdev->in_ep)
agdev->in_ep->driver_data = NULL;
if (agdev->out_ep)
agdev->out_ep->driver_data = NULL;
return -EINVAL;
}
static void
afunc_unbind(struct usb_configuration *cfg, struct usb_function *fn)
{
struct audio_dev *agdev = func_to_agdev(fn);
struct uac2_rtd_params *prm;
alsa_uac2_exit(agdev);
prm = &agdev->uac2.p_prm;
kfree(prm->rbuf);
prm = &agdev->uac2.c_prm;
kfree(prm->rbuf);
usb_free_all_descriptors(fn);
if (agdev->in_ep)
agdev->in_ep->driver_data = NULL;
if (agdev->out_ep)
agdev->out_ep->driver_data = NULL;
}
static int
afunc_set_alt(struct usb_function *fn, unsigned intf, unsigned alt)
{
struct usb_composite_dev *cdev = fn->config->cdev;
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
struct usb_gadget *gadget = cdev->gadget;
struct usb_request *req;
struct usb_ep *ep;
struct uac2_rtd_params *prm;
int i;
if (alt > 1) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
if (intf == agdev->ac_intf) {
if (alt) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
return 0;
}
if (intf == agdev->as_out_intf) {
ep = agdev->out_ep;
prm = &uac2->c_prm;
config_ep_by_speed(gadget, fn, ep);
agdev->as_out_alt = alt;
} else if (intf == agdev->as_in_intf) {
ep = agdev->in_ep;
prm = &uac2->p_prm;
config_ep_by_speed(gadget, fn, ep);
agdev->as_in_alt = alt;
} else {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
if (alt == 0) {
free_ep(prm, ep);
return 0;
}
prm->ep_enabled = true;
usb_ep_enable(ep);
for (i = 0; i < USB_XFERS; i++) {
if (prm->ureq[i].req) {
if (usb_ep_queue(ep, prm->ureq[i].req, GFP_ATOMIC))
dev_err(&uac2->pdev.dev, "%d Error!\n",
__LINE__);
continue;
}
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req == NULL) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
prm->ureq[i].req = req;
prm->ureq[i].pp = prm;
req->zero = 0;
req->context = &prm->ureq[i];
req->length = prm->max_psize;
req->complete = agdev_iso_complete;
req->buf = prm->rbuf + i * req->length;
if (usb_ep_queue(ep, req, GFP_ATOMIC))
dev_err(&uac2->pdev.dev, "%d Error!\n", __LINE__);
}
return 0;
}
static int
afunc_get_alt(struct usb_function *fn, unsigned intf)
{
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
if (intf == agdev->ac_intf)
return agdev->ac_alt;
else if (intf == agdev->as_out_intf)
return agdev->as_out_alt;
else if (intf == agdev->as_in_intf)
return agdev->as_in_alt;
else
dev_err(&uac2->pdev.dev,
"%s:%d Invalid Interface %d!\n",
__func__, __LINE__, intf);
return -EINVAL;
}
static void
afunc_disable(struct usb_function *fn)
{
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
free_ep(&uac2->p_prm, agdev->in_ep);
agdev->as_in_alt = 0;
free_ep(&uac2->c_prm, agdev->out_ep);
agdev->as_out_alt = 0;
}
static int
in_rq_cur(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
struct usb_request *req = fn->config->cdev->req;
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
u16 w_length = le16_to_cpu(cr->wLength);
u16 w_index = le16_to_cpu(cr->wIndex);
u16 w_value = le16_to_cpu(cr->wValue);
u8 entity_id = (w_index >> 8) & 0xff;
u8 control_selector = w_value >> 8;
int value = -EOPNOTSUPP;
if (control_selector == UAC2_CS_CONTROL_SAM_FREQ) {
struct cntrl_cur_lay3 c;
if (entity_id == USB_IN_CLK_ID)
c.dCUR = p_srate;
else if (entity_id == USB_OUT_CLK_ID)
c.dCUR = c_srate;
value = min_t(unsigned, w_length, sizeof c);
memcpy(req->buf, &c, value);
} else if (control_selector == UAC2_CS_CONTROL_CLOCK_VALID) {
*(u8 *)req->buf = 1;
value = min_t(unsigned, w_length, 1);
} else {
dev_err(&uac2->pdev.dev,
"%s:%d control_selector=%d TODO!\n",
__func__, __LINE__, control_selector);
}
return value;
}
static int
in_rq_range(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
struct usb_request *req = fn->config->cdev->req;
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
u16 w_length = le16_to_cpu(cr->wLength);
u16 w_index = le16_to_cpu(cr->wIndex);
u16 w_value = le16_to_cpu(cr->wValue);
u8 entity_id = (w_index >> 8) & 0xff;
u8 control_selector = w_value >> 8;
struct cntrl_range_lay3 r;
int value = -EOPNOTSUPP;
if (control_selector == UAC2_CS_CONTROL_SAM_FREQ) {
if (entity_id == USB_IN_CLK_ID)
r.dMIN = p_srate;
else if (entity_id == USB_OUT_CLK_ID)
r.dMIN = c_srate;
else
return -EOPNOTSUPP;
r.dMAX = r.dMIN;
r.dRES = 0;
r.wNumSubRanges = 1;
value = min_t(unsigned, w_length, sizeof r);
memcpy(req->buf, &r, value);
} else {
dev_err(&uac2->pdev.dev,
"%s:%d control_selector=%d TODO!\n",
__func__, __LINE__, control_selector);
}
return value;
}
static int
ac_rq_in(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
if (cr->bRequest == UAC2_CS_CUR)
return in_rq_cur(fn, cr);
else if (cr->bRequest == UAC2_CS_RANGE)
return in_rq_range(fn, cr);
else
return -EOPNOTSUPP;
}
static int
out_rq_cur(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
u16 w_length = le16_to_cpu(cr->wLength);
u16 w_value = le16_to_cpu(cr->wValue);
u8 control_selector = w_value >> 8;
if (control_selector == UAC2_CS_CONTROL_SAM_FREQ)
return w_length;
return -EOPNOTSUPP;
}
static int
setup_rq_inf(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
u16 w_index = le16_to_cpu(cr->wIndex);
u8 intf = w_index & 0xff;
if (intf != agdev->ac_intf) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
return -EOPNOTSUPP;
}
if (cr->bRequestType & USB_DIR_IN)
return ac_rq_in(fn, cr);
else if (cr->bRequest == UAC2_CS_CUR)
return out_rq_cur(fn, cr);
return -EOPNOTSUPP;
}
static int
afunc_setup(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
struct usb_composite_dev *cdev = fn->config->cdev;
struct audio_dev *agdev = func_to_agdev(fn);
struct snd_uac2_chip *uac2 = &agdev->uac2;
struct usb_request *req = cdev->req;
u16 w_length = le16_to_cpu(cr->wLength);
int value = -EOPNOTSUPP;
if ((cr->bRequestType & USB_TYPE_MASK) != USB_TYPE_CLASS)
return -EOPNOTSUPP;
if ((cr->bRequestType & USB_RECIP_MASK) == USB_RECIP_INTERFACE)
value = setup_rq_inf(fn, cr);
else
dev_err(&uac2->pdev.dev, "%s:%d Error!\n", __func__, __LINE__);
if (value >= 0) {
req->length = value;
req->zero = value < w_length;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0) {
dev_err(&uac2->pdev.dev,
"%s:%d Error!\n", __func__, __LINE__);
req->status = 0;
}
}
return value;
}
static int audio_bind_config(struct usb_configuration *cfg)
{
int res;
agdev_g = kzalloc(sizeof *agdev_g, GFP_KERNEL);
if (agdev_g == NULL) {
printk(KERN_ERR "Unable to allocate audio gadget\n");
return -ENOMEM;
}
res = usb_string_ids_tab(cfg->cdev, strings_fn);
if (res)
return res;
iad_desc.iFunction = strings_fn[STR_ASSOC].id;
std_ac_if_desc.iInterface = strings_fn[STR_IF_CTRL].id;
in_clk_src_desc.iClockSource = strings_fn[STR_CLKSRC_IN].id;
out_clk_src_desc.iClockSource = strings_fn[STR_CLKSRC_OUT].id;
usb_out_it_desc.iTerminal = strings_fn[STR_USB_IT].id;
io_in_it_desc.iTerminal = strings_fn[STR_IO_IT].id;
usb_in_ot_desc.iTerminal = strings_fn[STR_USB_OT].id;
io_out_ot_desc.iTerminal = strings_fn[STR_IO_OT].id;
std_as_out_if0_desc.iInterface = strings_fn[STR_AS_OUT_ALT0].id;
std_as_out_if1_desc.iInterface = strings_fn[STR_AS_OUT_ALT1].id;
std_as_in_if0_desc.iInterface = strings_fn[STR_AS_IN_ALT0].id;
std_as_in_if1_desc.iInterface = strings_fn[STR_AS_IN_ALT1].id;
agdev_g->func.name = "uac2_func";
agdev_g->func.strings = fn_strings;
agdev_g->func.bind = afunc_bind;
agdev_g->func.unbind = afunc_unbind;
agdev_g->func.set_alt = afunc_set_alt;
agdev_g->func.get_alt = afunc_get_alt;
agdev_g->func.disable = afunc_disable;
agdev_g->func.setup = afunc_setup;
usb_out_it_desc.bNrChannels = num_channels(c_chmask);
usb_out_it_desc.bmChannelConfig = cpu_to_le32(c_chmask);
io_in_it_desc.bNrChannels = num_channels(p_chmask);
io_in_it_desc.bmChannelConfig = cpu_to_le32(p_chmask);
as_out_hdr_desc.bNrChannels = num_channels(c_chmask);
as_out_hdr_desc.bmChannelConfig = cpu_to_le32(c_chmask);
as_in_hdr_desc.bNrChannels = num_channels(p_chmask);
as_in_hdr_desc.bmChannelConfig = cpu_to_le32(p_chmask);
as_out_fmt1_desc.bSubslotSize = c_ssize;
as_out_fmt1_desc.bBitResolution = c_ssize * 8;
as_in_fmt1_desc.bSubslotSize = p_ssize;
as_in_fmt1_desc.bBitResolution = p_ssize * 8;
snprintf(clksrc_in, sizeof(clksrc_in), "%uHz", p_srate);
snprintf(clksrc_out, sizeof(clksrc_out), "%uHz", c_srate);
res = usb_add_function(cfg, &agdev_g->func);
if (res < 0)
kfree(agdev_g);
return res;
}
static void
uac2_unbind_config(struct usb_configuration *cfg)
{
kfree(agdev_g);
agdev_g = NULL;
}
