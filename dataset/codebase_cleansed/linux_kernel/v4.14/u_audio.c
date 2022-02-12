static void u_audio_iso_complete(struct usb_ep *ep, struct usb_request *req)
{
unsigned pending;
unsigned long flags;
unsigned int hw_ptr;
bool update_alsa = false;
int status = req->status;
struct uac_req *ur = req->context;
struct snd_pcm_substream *substream;
struct uac_rtd_params *prm = ur->pp;
struct snd_uac_chip *uac = prm->uac;
if (!prm->ep_enabled || req->status == -ESHUTDOWN)
return;
if (status)
pr_debug("%s: iso_complete status(%d) %d/%d\n",
__func__, status, req->actual, req->length);
substream = prm->ss;
if (!substream)
goto exit;
spin_lock_irqsave(&prm->lock, flags);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
req->length = uac->p_pktsize;
uac->p_residue += uac->p_pktsize_residue;
if (uac->p_residue / uac->p_interval >= uac->p_framesize) {
req->length += uac->p_framesize;
uac->p_residue -= uac->p_framesize *
uac->p_interval;
}
req->actual = req->length;
}
pending = prm->hw_ptr % prm->period_size;
pending += req->actual;
if (pending >= prm->period_size)
update_alsa = true;
hw_ptr = prm->hw_ptr;
prm->hw_ptr = (prm->hw_ptr + req->actual) % prm->dma_bytes;
spin_unlock_irqrestore(&prm->lock, flags);
pending = prm->dma_bytes - hw_ptr;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (unlikely(pending < req->actual)) {
memcpy(req->buf, prm->dma_area + hw_ptr, pending);
memcpy(req->buf + pending, prm->dma_area,
req->actual - pending);
} else {
memcpy(req->buf, prm->dma_area + hw_ptr, req->actual);
}
} else {
if (unlikely(pending < req->actual)) {
memcpy(prm->dma_area + hw_ptr, req->buf, pending);
memcpy(prm->dma_area, req->buf + pending,
req->actual - pending);
} else {
memcpy(prm->dma_area + hw_ptr, req->buf, req->actual);
}
}
exit:
if (usb_ep_queue(ep, req, GFP_ATOMIC))
dev_err(uac->card->dev, "%d Error!\n", __LINE__);
if (update_alsa)
snd_pcm_period_elapsed(substream);
}
static int uac_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_uac_chip *uac = snd_pcm_substream_chip(substream);
struct uac_rtd_params *prm;
struct g_audio *audio_dev;
struct uac_params *params;
unsigned long flags;
int err = 0;
audio_dev = uac->audio_dev;
params = &audio_dev->params;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac->p_prm;
else
prm = &uac->c_prm;
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
memset(prm->rbuf, 0, prm->max_psize * params->req_number);
return err;
}
static snd_pcm_uframes_t uac_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_uac_chip *uac = snd_pcm_substream_chip(substream);
struct uac_rtd_params *prm;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac->p_prm;
else
prm = &uac->c_prm;
return bytes_to_frames(substream->runtime, prm->hw_ptr);
}
static int uac_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_uac_chip *uac = snd_pcm_substream_chip(substream);
struct uac_rtd_params *prm;
int err;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac->p_prm;
else
prm = &uac->c_prm;
err = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (err >= 0) {
prm->dma_bytes = substream->runtime->dma_bytes;
prm->dma_area = substream->runtime->dma_area;
prm->period_size = params_period_bytes(hw_params);
}
return err;
}
static int uac_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_uac_chip *uac = snd_pcm_substream_chip(substream);
struct uac_rtd_params *prm;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
prm = &uac->p_prm;
else
prm = &uac->c_prm;
prm->dma_area = NULL;
prm->dma_bytes = 0;
prm->period_size = 0;
return snd_pcm_lib_free_pages(substream);
}
static int uac_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_uac_chip *uac = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct g_audio *audio_dev;
struct uac_params *params;
int p_ssize, c_ssize;
int p_srate, c_srate;
int p_chmask, c_chmask;
audio_dev = uac->audio_dev;
params = &audio_dev->params;
p_ssize = params->p_ssize;
c_ssize = params->c_ssize;
p_srate = params->p_srate;
c_srate = params->c_srate;
p_chmask = params->p_chmask;
c_chmask = params->c_chmask;
uac->p_residue = 0;
runtime->hw = uac_pcm_hardware;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
spin_lock_init(&uac->p_prm.lock);
runtime->hw.rate_min = p_srate;
switch (p_ssize) {
case 3:
runtime->hw.formats = SNDRV_PCM_FMTBIT_S24_3LE;
break;
case 4:
runtime->hw.formats = SNDRV_PCM_FMTBIT_S32_LE;
break;
default:
runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
break;
}
runtime->hw.channels_min = num_channels(p_chmask);
runtime->hw.period_bytes_min = 2 * uac->p_prm.max_psize
/ runtime->hw.periods_min;
} else {
spin_lock_init(&uac->c_prm.lock);
runtime->hw.rate_min = c_srate;
switch (c_ssize) {
case 3:
runtime->hw.formats = SNDRV_PCM_FMTBIT_S24_3LE;
break;
case 4:
runtime->hw.formats = SNDRV_PCM_FMTBIT_S32_LE;
break;
default:
runtime->hw.formats = SNDRV_PCM_FMTBIT_S16_LE;
break;
}
runtime->hw.channels_min = num_channels(c_chmask);
runtime->hw.period_bytes_min = 2 * uac->c_prm.max_psize
/ runtime->hw.periods_min;
}
runtime->hw.rate_max = runtime->hw.rate_min;
runtime->hw.channels_max = runtime->hw.channels_min;
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
return 0;
}
static int uac_pcm_null(struct snd_pcm_substream *substream)
{
return 0;
}
static inline void free_ep(struct uac_rtd_params *prm, struct usb_ep *ep)
{
struct snd_uac_chip *uac = prm->uac;
struct g_audio *audio_dev;
struct uac_params *params;
int i;
if (!prm->ep_enabled)
return;
prm->ep_enabled = false;
audio_dev = uac->audio_dev;
params = &audio_dev->params;
for (i = 0; i < params->req_number; i++) {
if (prm->ureq[i].req) {
usb_ep_dequeue(ep, prm->ureq[i].req);
usb_ep_free_request(ep, prm->ureq[i].req);
prm->ureq[i].req = NULL;
}
}
if (usb_ep_disable(ep))
dev_err(uac->card->dev, "%s:%d Error!\n", __func__, __LINE__);
}
int u_audio_start_capture(struct g_audio *audio_dev)
{
struct snd_uac_chip *uac = audio_dev->uac;
struct usb_gadget *gadget = audio_dev->gadget;
struct device *dev = &gadget->dev;
struct usb_request *req;
struct usb_ep *ep;
struct uac_rtd_params *prm;
struct uac_params *params = &audio_dev->params;
int req_len, i;
ep = audio_dev->out_ep;
prm = &uac->c_prm;
config_ep_by_speed(gadget, &audio_dev->func, ep);
req_len = prm->max_psize;
prm->ep_enabled = true;
usb_ep_enable(ep);
for (i = 0; i < params->req_number; i++) {
if (!prm->ureq[i].req) {
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req == NULL)
return -ENOMEM;
prm->ureq[i].req = req;
prm->ureq[i].pp = prm;
req->zero = 0;
req->context = &prm->ureq[i];
req->length = req_len;
req->complete = u_audio_iso_complete;
req->buf = prm->rbuf + i * prm->max_psize;
}
if (usb_ep_queue(ep, prm->ureq[i].req, GFP_ATOMIC))
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
}
return 0;
}
void u_audio_stop_capture(struct g_audio *audio_dev)
{
struct snd_uac_chip *uac = audio_dev->uac;
free_ep(&uac->c_prm, audio_dev->out_ep);
}
int u_audio_start_playback(struct g_audio *audio_dev)
{
struct snd_uac_chip *uac = audio_dev->uac;
struct usb_gadget *gadget = audio_dev->gadget;
struct device *dev = &gadget->dev;
struct usb_request *req;
struct usb_ep *ep;
struct uac_rtd_params *prm;
struct uac_params *params = &audio_dev->params;
unsigned int factor, rate;
const struct usb_endpoint_descriptor *ep_desc;
int req_len, i;
ep = audio_dev->in_ep;
prm = &uac->p_prm;
config_ep_by_speed(gadget, &audio_dev->func, ep);
ep_desc = ep->desc;
if (gadget->speed == USB_SPEED_FULL)
factor = 1000;
else
factor = 8000;
uac->p_framesize = params->p_ssize *
num_channels(params->p_chmask);
rate = params->p_srate * uac->p_framesize;
uac->p_interval = factor / (1 << (ep_desc->bInterval - 1));
uac->p_pktsize = min_t(unsigned int, rate / uac->p_interval,
prm->max_psize);
if (uac->p_pktsize < prm->max_psize)
uac->p_pktsize_residue = rate % uac->p_interval;
else
uac->p_pktsize_residue = 0;
req_len = uac->p_pktsize;
uac->p_residue = 0;
prm->ep_enabled = true;
usb_ep_enable(ep);
for (i = 0; i < params->req_number; i++) {
if (!prm->ureq[i].req) {
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req == NULL)
return -ENOMEM;
prm->ureq[i].req = req;
prm->ureq[i].pp = prm;
req->zero = 0;
req->context = &prm->ureq[i];
req->length = req_len;
req->complete = u_audio_iso_complete;
req->buf = prm->rbuf + i * prm->max_psize;
}
if (usb_ep_queue(ep, prm->ureq[i].req, GFP_ATOMIC))
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
}
return 0;
}
void u_audio_stop_playback(struct g_audio *audio_dev)
{
struct snd_uac_chip *uac = audio_dev->uac;
free_ep(&uac->p_prm, audio_dev->in_ep);
}
int g_audio_setup(struct g_audio *g_audio, const char *pcm_name,
const char *card_name)
{
struct snd_uac_chip *uac;
struct snd_card *card;
struct snd_pcm *pcm;
struct uac_params *params;
int p_chmask, c_chmask;
int err;
if (!g_audio)
return -EINVAL;
uac = kzalloc(sizeof(*uac), GFP_KERNEL);
if (!uac)
return -ENOMEM;
g_audio->uac = uac;
uac->audio_dev = g_audio;
params = &g_audio->params;
p_chmask = params->p_chmask;
c_chmask = params->c_chmask;
if (c_chmask) {
struct uac_rtd_params *prm = &uac->c_prm;
uac->c_prm.uac = uac;
prm->max_psize = g_audio->out_ep_maxpsize;
prm->ureq = kcalloc(params->req_number, sizeof(struct uac_req),
GFP_KERNEL);
if (!prm->ureq) {
err = -ENOMEM;
goto fail;
}
prm->rbuf = kcalloc(params->req_number, prm->max_psize,
GFP_KERNEL);
if (!prm->rbuf) {
prm->max_psize = 0;
err = -ENOMEM;
goto fail;
}
}
if (p_chmask) {
struct uac_rtd_params *prm = &uac->p_prm;
uac->p_prm.uac = uac;
prm->max_psize = g_audio->in_ep_maxpsize;
prm->ureq = kcalloc(params->req_number, sizeof(struct uac_req),
GFP_KERNEL);
if (!prm->ureq) {
err = -ENOMEM;
goto fail;
}
prm->rbuf = kcalloc(params->req_number, prm->max_psize,
GFP_KERNEL);
if (!prm->rbuf) {
prm->max_psize = 0;
err = -ENOMEM;
goto fail;
}
}
err = snd_card_new(&g_audio->gadget->dev,
-1, NULL, THIS_MODULE, 0, &card);
if (err < 0)
goto fail;
uac->card = card;
err = snd_pcm_new(uac->card, pcm_name, 0,
p_chmask ? 1 : 0, c_chmask ? 1 : 0, &pcm);
if (err < 0)
goto snd_fail;
strcpy(pcm->name, pcm_name);
pcm->private_data = uac;
uac->pcm = pcm;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &uac_pcm_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &uac_pcm_ops);
strcpy(card->driver, card_name);
strcpy(card->shortname, card_name);
sprintf(card->longname, "%s %i", card_name, card->dev->id);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL), 0, BUFF_SIZE_MAX);
err = snd_card_register(card);
if (!err)
return 0;
snd_fail:
snd_card_free(card);
fail:
kfree(uac->p_prm.ureq);
kfree(uac->c_prm.ureq);
kfree(uac->p_prm.rbuf);
kfree(uac->c_prm.rbuf);
kfree(uac);
return err;
}
void g_audio_cleanup(struct g_audio *g_audio)
{
struct snd_uac_chip *uac;
struct snd_card *card;
if (!g_audio || !g_audio->uac)
return;
uac = g_audio->uac;
card = uac->card;
if (card)
snd_card_free(card);
kfree(uac->p_prm.ureq);
kfree(uac->c_prm.ureq);
kfree(uac->p_prm.rbuf);
kfree(uac->c_prm.rbuf);
kfree(uac);
}
