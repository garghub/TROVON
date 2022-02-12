static inline struct f_uac1 *func_to_uac1(struct usb_function *f)
{
return container_of(f, struct f_uac1, g_audio.func);
}
static int audio_set_endpoint_req(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct usb_composite_dev *cdev = f->config->cdev;
int value = -EOPNOTSUPP;
u16 ep = le16_to_cpu(ctrl->wIndex);
u16 len = le16_to_cpu(ctrl->wLength);
u16 w_value = le16_to_cpu(ctrl->wValue);
DBG(cdev, "bRequest 0x%x, w_value 0x%04x, len %d, endpoint %d\n",
ctrl->bRequest, w_value, len, ep);
switch (ctrl->bRequest) {
case UAC_SET_CUR:
value = len;
break;
case UAC_SET_MIN:
break;
case UAC_SET_MAX:
break;
case UAC_SET_RES:
break;
case UAC_SET_MEM:
break;
default:
break;
}
return value;
}
static int audio_get_endpoint_req(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct usb_composite_dev *cdev = f->config->cdev;
int value = -EOPNOTSUPP;
u8 ep = ((le16_to_cpu(ctrl->wIndex) >> 8) & 0xFF);
u16 len = le16_to_cpu(ctrl->wLength);
u16 w_value = le16_to_cpu(ctrl->wValue);
DBG(cdev, "bRequest 0x%x, w_value 0x%04x, len %d, endpoint %d\n",
ctrl->bRequest, w_value, len, ep);
switch (ctrl->bRequest) {
case UAC_GET_CUR:
case UAC_GET_MIN:
case UAC_GET_MAX:
case UAC_GET_RES:
value = len;
break;
case UAC_GET_MEM:
break;
default:
break;
}
return value;
}
static int
f_audio_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl)
{
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
switch (ctrl->bRequestType) {
case USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_ENDPOINT:
value = audio_set_endpoint_req(f, ctrl);
break;
case USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_ENDPOINT:
value = audio_get_endpoint_req(f, ctrl);
break;
default:
ERROR(cdev, "invalid control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
DBG(cdev, "audio req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
req->zero = 0;
req->length = value;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0)
ERROR(cdev, "audio response on err %d\n", value);
}
return value;
}
static int f_audio_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_gadget *gadget = cdev->gadget;
struct device *dev = &gadget->dev;
struct f_uac1 *uac1 = func_to_uac1(f);
int ret = 0;
if (alt > 1) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
if (intf == uac1->ac_intf) {
if (alt) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
return 0;
}
if (intf == uac1->as_out_intf) {
uac1->as_out_alt = alt;
if (alt)
ret = u_audio_start_capture(&uac1->g_audio);
else
u_audio_stop_capture(&uac1->g_audio);
} else if (intf == uac1->as_in_intf) {
uac1->as_in_alt = alt;
if (alt)
ret = u_audio_start_playback(&uac1->g_audio);
else
u_audio_stop_playback(&uac1->g_audio);
} else {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
return ret;
}
static int f_audio_get_alt(struct usb_function *f, unsigned intf)
{
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_gadget *gadget = cdev->gadget;
struct device *dev = &gadget->dev;
struct f_uac1 *uac1 = func_to_uac1(f);
if (intf == uac1->ac_intf)
return uac1->ac_alt;
else if (intf == uac1->as_out_intf)
return uac1->as_out_alt;
else if (intf == uac1->as_in_intf)
return uac1->as_in_alt;
else
dev_err(dev, "%s:%d Invalid Interface %d!\n",
__func__, __LINE__, intf);
return -EINVAL;
}
static void f_audio_disable(struct usb_function *f)
{
struct f_uac1 *uac1 = func_to_uac1(f);
uac1->as_out_alt = 0;
uac1->as_in_alt = 0;
u_audio_stop_capture(&uac1->g_audio);
}
static int f_audio_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct usb_gadget *gadget = cdev->gadget;
struct f_uac1 *uac1 = func_to_uac1(f);
struct g_audio *audio = func_to_g_audio(f);
struct f_uac1_opts *audio_opts;
struct usb_ep *ep = NULL;
struct usb_string *us;
u8 *sam_freq;
int rate;
int status;
audio_opts = container_of(f->fi, struct f_uac1_opts, func_inst);
us = usb_gstrings_attach(cdev, uac1_strings, ARRAY_SIZE(strings_uac1));
if (IS_ERR(us))
return PTR_ERR(us);
ac_interface_desc.iInterface = us[STR_AC_IF].id;
usb_out_it_desc.iTerminal = us[STR_USB_OUT_IT].id;
usb_out_it_desc.iChannelNames = us[STR_USB_OUT_IT_CH_NAMES].id;
io_out_ot_desc.iTerminal = us[STR_IO_OUT_OT].id;
as_out_interface_alt_0_desc.iInterface = us[STR_AS_OUT_IF_ALT0].id;
as_out_interface_alt_1_desc.iInterface = us[STR_AS_OUT_IF_ALT1].id;
io_in_it_desc.iTerminal = us[STR_IO_IN_IT].id;
io_in_it_desc.iChannelNames = us[STR_IO_IN_IT_CH_NAMES].id;
usb_in_ot_desc.iTerminal = us[STR_USB_IN_OT].id;
as_in_interface_alt_0_desc.iInterface = us[STR_AS_IN_IF_ALT0].id;
as_in_interface_alt_1_desc.iInterface = us[STR_AS_IN_IF_ALT1].id;
usb_out_it_desc.bNrChannels = num_channels(audio_opts->c_chmask);
usb_out_it_desc.wChannelConfig = cpu_to_le16(audio_opts->c_chmask);
as_out_type_i_desc.bNrChannels = num_channels(audio_opts->c_chmask);
as_out_type_i_desc.bSubframeSize = audio_opts->c_ssize;
as_out_type_i_desc.bBitResolution = audio_opts->c_ssize * 8;
io_in_it_desc.bNrChannels = num_channels(audio_opts->p_chmask);
io_in_it_desc.wChannelConfig = cpu_to_le16(audio_opts->p_chmask);
as_in_type_i_desc.bNrChannels = num_channels(audio_opts->p_chmask);
as_in_type_i_desc.bSubframeSize = audio_opts->p_ssize;
as_in_type_i_desc.bBitResolution = audio_opts->p_ssize * 8;
rate = audio_opts->c_srate;
sam_freq = as_out_type_i_desc.tSamFreq[0];
memcpy(sam_freq, &rate, 3);
rate = audio_opts->p_srate;
sam_freq = as_in_type_i_desc.tSamFreq[0];
memcpy(sam_freq, &rate, 3);
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
ac_interface_desc.bInterfaceNumber = status;
uac1->ac_intf = status;
uac1->ac_alt = 0;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
as_out_interface_alt_0_desc.bInterfaceNumber = status;
as_out_interface_alt_1_desc.bInterfaceNumber = status;
uac1->as_out_intf = status;
uac1->as_out_alt = 0;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
as_in_interface_alt_0_desc.bInterfaceNumber = status;
as_in_interface_alt_1_desc.bInterfaceNumber = status;
uac1->as_in_intf = status;
uac1->as_in_alt = 0;
audio->gadget = gadget;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &as_out_ep_desc);
if (!ep)
goto fail;
audio->out_ep = ep;
audio->out_ep->desc = &as_out_ep_desc;
ep = usb_ep_autoconfig(cdev->gadget, &as_in_ep_desc);
if (!ep)
goto fail;
audio->in_ep = ep;
audio->in_ep->desc = &as_in_ep_desc;
status = usb_assign_descriptors(f, f_audio_desc, f_audio_desc, NULL,
NULL);
if (status)
goto fail;
audio->out_ep_maxpsize = le16_to_cpu(as_out_ep_desc.wMaxPacketSize);
audio->in_ep_maxpsize = le16_to_cpu(as_in_ep_desc.wMaxPacketSize);
audio->params.c_chmask = audio_opts->c_chmask;
audio->params.c_srate = audio_opts->c_srate;
audio->params.c_ssize = audio_opts->c_ssize;
audio->params.p_chmask = audio_opts->p_chmask;
audio->params.p_srate = audio_opts->p_srate;
audio->params.p_ssize = audio_opts->p_ssize;
audio->params.req_number = audio_opts->req_number;
status = g_audio_setup(audio, "UAC1_PCM", "UAC1_Gadget");
if (status)
goto err_card_register;
return 0;
err_card_register:
usb_free_all_descriptors(f);
fail:
return status;
}
static inline struct f_uac1_opts *to_f_uac1_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_uac1_opts,
func_inst.group);
}
static void f_uac1_attr_release(struct config_item *item)
{
struct f_uac1_opts *opts = to_f_uac1_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static void f_audio_free_inst(struct usb_function_instance *f)
{
struct f_uac1_opts *opts;
opts = container_of(f, struct f_uac1_opts, func_inst);
kfree(opts);
}
static struct usb_function_instance *f_audio_alloc_inst(void)
{
struct f_uac1_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
mutex_init(&opts->lock);
opts->func_inst.free_func_inst = f_audio_free_inst;
config_group_init_type_name(&opts->func_inst.group, "",
&f_uac1_func_type);
opts->c_chmask = UAC1_DEF_CCHMASK;
opts->c_srate = UAC1_DEF_CSRATE;
opts->c_ssize = UAC1_DEF_CSSIZE;
opts->p_chmask = UAC1_DEF_PCHMASK;
opts->p_srate = UAC1_DEF_PSRATE;
opts->p_ssize = UAC1_DEF_PSSIZE;
opts->req_number = UAC1_DEF_REQ_NUM;
return &opts->func_inst;
}
static void f_audio_free(struct usb_function *f)
{
struct g_audio *audio;
struct f_uac1_opts *opts;
audio = func_to_g_audio(f);
opts = container_of(f->fi, struct f_uac1_opts, func_inst);
kfree(audio);
mutex_lock(&opts->lock);
--opts->refcnt;
mutex_unlock(&opts->lock);
}
static void f_audio_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct g_audio *audio = func_to_g_audio(f);
g_audio_cleanup(audio);
usb_free_all_descriptors(f);
audio->gadget = NULL;
}
static struct usb_function *f_audio_alloc(struct usb_function_instance *fi)
{
struct f_uac1 *uac1;
struct f_uac1_opts *opts;
uac1 = kzalloc(sizeof(*uac1), GFP_KERNEL);
if (!uac1)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_uac1_opts, func_inst);
mutex_lock(&opts->lock);
++opts->refcnt;
mutex_unlock(&opts->lock);
uac1->g_audio.func.name = "uac1_func";
uac1->g_audio.func.bind = f_audio_bind;
uac1->g_audio.func.unbind = f_audio_unbind;
uac1->g_audio.func.set_alt = f_audio_set_alt;
uac1->g_audio.func.get_alt = f_audio_get_alt;
uac1->g_audio.func.setup = f_audio_setup;
uac1->g_audio.func.disable = f_audio_disable;
uac1->g_audio.func.free_func = f_audio_free;
return &uac1->g_audio.func;
}
