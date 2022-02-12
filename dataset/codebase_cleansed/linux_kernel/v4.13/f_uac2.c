static inline struct f_uac2 *func_to_uac2(struct usb_function *f)
{
return container_of(f, struct f_uac2, g_audio.func);
}
static inline
struct f_uac2_opts *g_audio_to_uac2_opts(struct g_audio *agdev)
{
return container_of(agdev->func.fi, struct f_uac2_opts, func_inst);
}
static void set_ep_max_packet_size(const struct f_uac2_opts *uac2_opts,
struct usb_endpoint_descriptor *ep_desc,
unsigned int factor, bool is_playback)
{
int chmask, srate, ssize;
u16 max_packet_size;
if (is_playback) {
chmask = uac2_opts->p_chmask;
srate = uac2_opts->p_srate;
ssize = uac2_opts->p_ssize;
} else {
chmask = uac2_opts->c_chmask;
srate = uac2_opts->c_srate;
ssize = uac2_opts->c_ssize;
}
max_packet_size = num_channels(chmask) * ssize *
DIV_ROUND_UP(srate, factor / (1 << (ep_desc->bInterval - 1)));
ep_desc->wMaxPacketSize = cpu_to_le16(min_t(u16, max_packet_size,
le16_to_cpu(ep_desc->wMaxPacketSize)));
}
static int
afunc_bind(struct usb_configuration *cfg, struct usb_function *fn)
{
struct f_uac2 *uac2 = func_to_uac2(fn);
struct g_audio *agdev = func_to_g_audio(fn);
struct usb_composite_dev *cdev = cfg->cdev;
struct usb_gadget *gadget = cdev->gadget;
struct device *dev = &gadget->dev;
struct f_uac2_opts *uac2_opts;
struct usb_string *us;
int ret;
uac2_opts = container_of(fn->fi, struct f_uac2_opts, func_inst);
us = usb_gstrings_attach(cdev, fn_strings, ARRAY_SIZE(strings_fn));
if (IS_ERR(us))
return PTR_ERR(us);
iad_desc.iFunction = us[STR_ASSOC].id;
std_ac_if_desc.iInterface = us[STR_IF_CTRL].id;
in_clk_src_desc.iClockSource = us[STR_CLKSRC_IN].id;
out_clk_src_desc.iClockSource = us[STR_CLKSRC_OUT].id;
usb_out_it_desc.iTerminal = us[STR_USB_IT].id;
io_in_it_desc.iTerminal = us[STR_IO_IT].id;
usb_in_ot_desc.iTerminal = us[STR_USB_OT].id;
io_out_ot_desc.iTerminal = us[STR_IO_OT].id;
std_as_out_if0_desc.iInterface = us[STR_AS_OUT_ALT0].id;
std_as_out_if1_desc.iInterface = us[STR_AS_OUT_ALT1].id;
std_as_in_if0_desc.iInterface = us[STR_AS_IN_ALT0].id;
std_as_in_if1_desc.iInterface = us[STR_AS_IN_ALT1].id;
usb_out_it_desc.bNrChannels = num_channels(uac2_opts->c_chmask);
usb_out_it_desc.bmChannelConfig = cpu_to_le32(uac2_opts->c_chmask);
io_in_it_desc.bNrChannels = num_channels(uac2_opts->p_chmask);
io_in_it_desc.bmChannelConfig = cpu_to_le32(uac2_opts->p_chmask);
as_out_hdr_desc.bNrChannels = num_channels(uac2_opts->c_chmask);
as_out_hdr_desc.bmChannelConfig = cpu_to_le32(uac2_opts->c_chmask);
as_in_hdr_desc.bNrChannels = num_channels(uac2_opts->p_chmask);
as_in_hdr_desc.bmChannelConfig = cpu_to_le32(uac2_opts->p_chmask);
as_out_fmt1_desc.bSubslotSize = uac2_opts->c_ssize;
as_out_fmt1_desc.bBitResolution = uac2_opts->c_ssize * 8;
as_in_fmt1_desc.bSubslotSize = uac2_opts->p_ssize;
as_in_fmt1_desc.bBitResolution = uac2_opts->p_ssize * 8;
snprintf(clksrc_in, sizeof(clksrc_in), "%uHz", uac2_opts->p_srate);
snprintf(clksrc_out, sizeof(clksrc_out), "%uHz", uac2_opts->c_srate);
ret = usb_interface_id(cfg, fn);
if (ret < 0) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return ret;
}
std_ac_if_desc.bInterfaceNumber = ret;
uac2->ac_intf = ret;
uac2->ac_alt = 0;
ret = usb_interface_id(cfg, fn);
if (ret < 0) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return ret;
}
std_as_out_if0_desc.bInterfaceNumber = ret;
std_as_out_if1_desc.bInterfaceNumber = ret;
uac2->as_out_intf = ret;
uac2->as_out_alt = 0;
ret = usb_interface_id(cfg, fn);
if (ret < 0) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return ret;
}
std_as_in_if0_desc.bInterfaceNumber = ret;
std_as_in_if1_desc.bInterfaceNumber = ret;
uac2->as_in_intf = ret;
uac2->as_in_alt = 0;
set_ep_max_packet_size(uac2_opts, &fs_epin_desc, 1000, true);
set_ep_max_packet_size(uac2_opts, &fs_epout_desc, 1000, false);
set_ep_max_packet_size(uac2_opts, &hs_epin_desc, 8000, true);
set_ep_max_packet_size(uac2_opts, &hs_epout_desc, 8000, false);
agdev->out_ep = usb_ep_autoconfig(gadget, &fs_epout_desc);
if (!agdev->out_ep) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return ret;
}
agdev->in_ep = usb_ep_autoconfig(gadget, &fs_epin_desc);
if (!agdev->in_ep) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return ret;
}
agdev->in_ep_maxpsize = max_t(u16,
le16_to_cpu(fs_epin_desc.wMaxPacketSize),
le16_to_cpu(hs_epin_desc.wMaxPacketSize));
agdev->out_ep_maxpsize = max_t(u16,
le16_to_cpu(fs_epout_desc.wMaxPacketSize),
le16_to_cpu(hs_epout_desc.wMaxPacketSize));
hs_epout_desc.bEndpointAddress = fs_epout_desc.bEndpointAddress;
hs_epin_desc.bEndpointAddress = fs_epin_desc.bEndpointAddress;
ret = usb_assign_descriptors(fn, fs_audio_desc, hs_audio_desc, NULL,
NULL);
if (ret)
return ret;
agdev->gadget = gadget;
agdev->params.p_chmask = uac2_opts->p_chmask;
agdev->params.p_srate = uac2_opts->p_srate;
agdev->params.p_ssize = uac2_opts->p_ssize;
agdev->params.c_chmask = uac2_opts->c_chmask;
agdev->params.c_srate = uac2_opts->c_srate;
agdev->params.c_ssize = uac2_opts->c_ssize;
agdev->params.req_number = uac2_opts->req_number;
ret = g_audio_setup(agdev, "UAC2 PCM", "UAC2_Gadget");
if (ret)
goto err_free_descs;
return 0;
err_free_descs:
usb_free_all_descriptors(fn);
agdev->gadget = NULL;
return ret;
}
static int
afunc_set_alt(struct usb_function *fn, unsigned intf, unsigned alt)
{
struct usb_composite_dev *cdev = fn->config->cdev;
struct f_uac2 *uac2 = func_to_uac2(fn);
struct usb_gadget *gadget = cdev->gadget;
struct device *dev = &gadget->dev;
int ret = 0;
if (alt > 1) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
if (intf == uac2->ac_intf) {
if (alt) {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
return 0;
}
if (intf == uac2->as_out_intf) {
uac2->as_out_alt = alt;
if (alt)
ret = u_audio_start_capture(&uac2->g_audio);
else
u_audio_stop_capture(&uac2->g_audio);
} else if (intf == uac2->as_in_intf) {
uac2->as_in_alt = alt;
if (alt)
ret = u_audio_start_playback(&uac2->g_audio);
else
u_audio_stop_playback(&uac2->g_audio);
} else {
dev_err(dev, "%s:%d Error!\n", __func__, __LINE__);
return -EINVAL;
}
return ret;
}
static int
afunc_get_alt(struct usb_function *fn, unsigned intf)
{
struct f_uac2 *uac2 = func_to_uac2(fn);
struct g_audio *agdev = func_to_g_audio(fn);
if (intf == uac2->ac_intf)
return uac2->ac_alt;
else if (intf == uac2->as_out_intf)
return uac2->as_out_alt;
else if (intf == uac2->as_in_intf)
return uac2->as_in_alt;
else
dev_err(&agdev->gadget->dev,
"%s:%d Invalid Interface %d!\n",
__func__, __LINE__, intf);
return -EINVAL;
}
static void
afunc_disable(struct usb_function *fn)
{
struct f_uac2 *uac2 = func_to_uac2(fn);
uac2->as_in_alt = 0;
uac2->as_out_alt = 0;
u_audio_stop_capture(&uac2->g_audio);
u_audio_stop_playback(&uac2->g_audio);
}
static int
in_rq_cur(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
struct usb_request *req = fn->config->cdev->req;
struct g_audio *agdev = func_to_g_audio(fn);
struct f_uac2_opts *opts;
u16 w_length = le16_to_cpu(cr->wLength);
u16 w_index = le16_to_cpu(cr->wIndex);
u16 w_value = le16_to_cpu(cr->wValue);
u8 entity_id = (w_index >> 8) & 0xff;
u8 control_selector = w_value >> 8;
int value = -EOPNOTSUPP;
int p_srate, c_srate;
opts = g_audio_to_uac2_opts(agdev);
p_srate = opts->p_srate;
c_srate = opts->c_srate;
if (control_selector == UAC2_CS_CONTROL_SAM_FREQ) {
struct cntrl_cur_lay3 c;
memset(&c, 0, sizeof(struct cntrl_cur_lay3));
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
dev_err(&agdev->gadget->dev,
"%s:%d control_selector=%d TODO!\n",
__func__, __LINE__, control_selector);
}
return value;
}
static int
in_rq_range(struct usb_function *fn, const struct usb_ctrlrequest *cr)
{
struct usb_request *req = fn->config->cdev->req;
struct g_audio *agdev = func_to_g_audio(fn);
struct f_uac2_opts *opts;
u16 w_length = le16_to_cpu(cr->wLength);
u16 w_index = le16_to_cpu(cr->wIndex);
u16 w_value = le16_to_cpu(cr->wValue);
u8 entity_id = (w_index >> 8) & 0xff;
u8 control_selector = w_value >> 8;
struct cntrl_range_lay3 r;
int value = -EOPNOTSUPP;
int p_srate, c_srate;
opts = g_audio_to_uac2_opts(agdev);
p_srate = opts->p_srate;
c_srate = opts->c_srate;
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
dev_err(&agdev->gadget->dev,
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
struct f_uac2 *uac2 = func_to_uac2(fn);
struct g_audio *agdev = func_to_g_audio(fn);
u16 w_index = le16_to_cpu(cr->wIndex);
u8 intf = w_index & 0xff;
if (intf != uac2->ac_intf) {
dev_err(&agdev->gadget->dev,
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
struct g_audio *agdev = func_to_g_audio(fn);
struct usb_request *req = cdev->req;
u16 w_length = le16_to_cpu(cr->wLength);
int value = -EOPNOTSUPP;
if ((cr->bRequestType & USB_TYPE_MASK) != USB_TYPE_CLASS)
return -EOPNOTSUPP;
if ((cr->bRequestType & USB_RECIP_MASK) == USB_RECIP_INTERFACE)
value = setup_rq_inf(fn, cr);
else
dev_err(&agdev->gadget->dev, "%s:%d Error!\n",
__func__, __LINE__);
if (value >= 0) {
req->length = value;
req->zero = value < w_length;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0) {
dev_err(&agdev->gadget->dev,
"%s:%d Error!\n", __func__, __LINE__);
req->status = 0;
}
}
return value;
}
static inline struct f_uac2_opts *to_f_uac2_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_uac2_opts,
func_inst.group);
}
static void f_uac2_attr_release(struct config_item *item)
{
struct f_uac2_opts *opts = to_f_uac2_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static void afunc_free_inst(struct usb_function_instance *f)
{
struct f_uac2_opts *opts;
opts = container_of(f, struct f_uac2_opts, func_inst);
kfree(opts);
}
static struct usb_function_instance *afunc_alloc_inst(void)
{
struct f_uac2_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
mutex_init(&opts->lock);
opts->func_inst.free_func_inst = afunc_free_inst;
config_group_init_type_name(&opts->func_inst.group, "",
&f_uac2_func_type);
opts->p_chmask = UAC2_DEF_PCHMASK;
opts->p_srate = UAC2_DEF_PSRATE;
opts->p_ssize = UAC2_DEF_PSSIZE;
opts->c_chmask = UAC2_DEF_CCHMASK;
opts->c_srate = UAC2_DEF_CSRATE;
opts->c_ssize = UAC2_DEF_CSSIZE;
opts->req_number = UAC2_DEF_REQ_NUM;
return &opts->func_inst;
}
static void afunc_free(struct usb_function *f)
{
struct g_audio *agdev;
struct f_uac2_opts *opts;
agdev = func_to_g_audio(f);
opts = container_of(f->fi, struct f_uac2_opts, func_inst);
kfree(agdev);
mutex_lock(&opts->lock);
--opts->refcnt;
mutex_unlock(&opts->lock);
}
static void afunc_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct g_audio *agdev = func_to_g_audio(f);
g_audio_cleanup(agdev);
usb_free_all_descriptors(f);
agdev->gadget = NULL;
}
static struct usb_function *afunc_alloc(struct usb_function_instance *fi)
{
struct f_uac2 *uac2;
struct f_uac2_opts *opts;
uac2 = kzalloc(sizeof(*uac2), GFP_KERNEL);
if (uac2 == NULL)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_uac2_opts, func_inst);
mutex_lock(&opts->lock);
++opts->refcnt;
mutex_unlock(&opts->lock);
uac2->g_audio.func.name = "uac2_func";
uac2->g_audio.func.bind = afunc_bind;
uac2->g_audio.func.unbind = afunc_unbind;
uac2->g_audio.func.set_alt = afunc_set_alt;
uac2->g_audio.func.get_alt = afunc_get_alt;
uac2->g_audio.func.disable = afunc_disable;
uac2->g_audio.func.setup = afunc_setup;
uac2->g_audio.func.free_func = afunc_free;
return &uac2->g_audio.func;
}
