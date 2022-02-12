static struct f_audio_buf *f_audio_buffer_alloc(int buf_size)
{
struct f_audio_buf *copy_buf;
copy_buf = kzalloc(sizeof *copy_buf, GFP_ATOMIC);
if (!copy_buf)
return ERR_PTR(-ENOMEM);
copy_buf->buf = kzalloc(buf_size, GFP_ATOMIC);
if (!copy_buf->buf) {
kfree(copy_buf);
return ERR_PTR(-ENOMEM);
}
return copy_buf;
}
static void f_audio_buffer_free(struct f_audio_buf *audio_buf)
{
kfree(audio_buf->buf);
kfree(audio_buf);
}
static inline struct f_audio *func_to_audio(struct usb_function *f)
{
return container_of(f, struct f_audio, card.func);
}
static void f_audio_playback_work(struct work_struct *data)
{
struct f_audio *audio = container_of(data, struct f_audio,
playback_work);
struct f_audio_buf *play_buf;
spin_lock_irq(&audio->lock);
if (list_empty(&audio->play_queue)) {
spin_unlock_irq(&audio->lock);
return;
}
play_buf = list_first_entry(&audio->play_queue,
struct f_audio_buf, list);
list_del(&play_buf->list);
spin_unlock_irq(&audio->lock);
u_audio_playback(&audio->card, play_buf->buf, play_buf->actual);
f_audio_buffer_free(play_buf);
}
static int f_audio_out_ep_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_audio *audio = req->context;
struct usb_composite_dev *cdev = audio->card.func.config->cdev;
struct f_audio_buf *copy_buf = audio->copy_buf;
int err;
if (!copy_buf)
return -EINVAL;
if (audio_buf_size - copy_buf->actual < req->actual) {
list_add_tail(&copy_buf->list, &audio->play_queue);
schedule_work(&audio->playback_work);
copy_buf = f_audio_buffer_alloc(audio_buf_size);
if (IS_ERR(copy_buf))
return -ENOMEM;
}
memcpy(copy_buf->buf + copy_buf->actual, req->buf, req->actual);
copy_buf->actual += req->actual;
audio->copy_buf = copy_buf;
err = usb_ep_queue(ep, req, GFP_ATOMIC);
if (err)
ERROR(cdev, "%s queue req: %d\n", ep->name, err);
return 0;
}
static void f_audio_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_audio *audio = req->context;
int status = req->status;
u32 data = 0;
struct usb_ep *out_ep = audio->out_ep;
switch (status) {
case 0:
if (ep == out_ep)
f_audio_out_ep_complete(ep, req);
else if (audio->set_con) {
memcpy(&data, req->buf, req->length);
audio->set_con->set(audio->set_con, audio->set_cmd,
le16_to_cpu(data));
audio->set_con = NULL;
}
break;
default:
break;
}
}
static int audio_set_intf_req(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct f_audio *audio = func_to_audio(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
u8 id = ((le16_to_cpu(ctrl->wIndex) >> 8) & 0xFF);
u16 len = le16_to_cpu(ctrl->wLength);
u16 w_value = le16_to_cpu(ctrl->wValue);
u8 con_sel = (w_value >> 8) & 0xFF;
u8 cmd = (ctrl->bRequest & 0x0F);
struct usb_audio_control_selector *cs;
struct usb_audio_control *con;
DBG(cdev, "bRequest 0x%x, w_value 0x%04x, len %d, entity %d\n",
ctrl->bRequest, w_value, len, id);
list_for_each_entry(cs, &audio->cs, list) {
if (cs->id == id) {
list_for_each_entry(con, &cs->control, list) {
if (con->type == con_sel) {
audio->set_con = con;
break;
}
}
break;
}
}
audio->set_cmd = cmd;
req->context = audio;
req->complete = f_audio_complete;
return len;
}
static int audio_get_intf_req(struct usb_function *f,
const struct usb_ctrlrequest *ctrl)
{
struct f_audio *audio = func_to_audio(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u8 id = ((le16_to_cpu(ctrl->wIndex) >> 8) & 0xFF);
u16 len = le16_to_cpu(ctrl->wLength);
u16 w_value = le16_to_cpu(ctrl->wValue);
u8 con_sel = (w_value >> 8) & 0xFF;
u8 cmd = (ctrl->bRequest & 0x0F);
struct usb_audio_control_selector *cs;
struct usb_audio_control *con;
DBG(cdev, "bRequest 0x%x, w_value 0x%04x, len %d, entity %d\n",
ctrl->bRequest, w_value, len, id);
list_for_each_entry(cs, &audio->cs, list) {
if (cs->id == id) {
list_for_each_entry(con, &cs->control, list) {
if (con->type == con_sel && con->get) {
value = con->get(con, cmd);
break;
}
}
break;
}
}
req->context = audio;
req->complete = f_audio_complete;
len = min_t(size_t, sizeof(value), len);
memcpy(req->buf, &value, len);
return len;
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
case USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE:
value = audio_set_intf_req(f, ctrl);
break;
case USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE:
value = audio_get_intf_req(f, ctrl);
break;
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
struct f_audio *audio = func_to_audio(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_ep *out_ep = audio->out_ep;
struct usb_request *req;
int i = 0, err = 0;
DBG(cdev, "intf %d, alt %d\n", intf, alt);
if (intf == 1) {
if (alt == 1) {
usb_ep_enable(out_ep);
out_ep->driver_data = audio;
audio->copy_buf = f_audio_buffer_alloc(audio_buf_size);
if (IS_ERR(audio->copy_buf))
return -ENOMEM;
for (i = 0; i < req_count && err == 0; i++) {
req = usb_ep_alloc_request(out_ep, GFP_ATOMIC);
if (req) {
req->buf = kzalloc(req_buf_size,
GFP_ATOMIC);
if (req->buf) {
req->length = req_buf_size;
req->context = audio;
req->complete =
f_audio_complete;
err = usb_ep_queue(out_ep,
req, GFP_ATOMIC);
if (err)
ERROR(cdev,
"%s queue req: %d\n",
out_ep->name, err);
} else
err = -ENOMEM;
} else
err = -ENOMEM;
}
} else {
struct f_audio_buf *copy_buf = audio->copy_buf;
if (copy_buf) {
list_add_tail(&copy_buf->list,
&audio->play_queue);
schedule_work(&audio->playback_work);
}
}
}
return err;
}
static void f_audio_disable(struct usb_function *f)
{
return;
}
static void f_audio_build_desc(struct f_audio *audio)
{
struct gaudio *card = &audio->card;
u8 *sam_freq;
int rate;
input_terminal_desc.bNrChannels = u_audio_get_playback_channels(card);
as_type_i_desc.bNrChannels = u_audio_get_playback_channels(card);
rate = u_audio_get_playback_rate(card);
sam_freq = as_type_i_desc.tSamFreq[0];
memcpy(sam_freq, &rate, 3);
return;
}
static int __init
f_audio_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_audio *audio = func_to_audio(f);
int status;
struct usb_ep *ep = NULL;
f_audio_build_desc(audio);
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
ac_interface_desc.bInterfaceNumber = status;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
as_interface_alt_0_desc.bInterfaceNumber = status;
as_interface_alt_1_desc.bInterfaceNumber = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &as_out_ep_desc);
if (!ep)
goto fail;
audio->out_ep = ep;
audio->out_ep->desc = &as_out_ep_desc;
ep->driver_data = cdev;
status = -ENOMEM;
status = usb_assign_descriptors(f, f_audio_desc, f_audio_desc, NULL);
if (status)
goto fail;
return 0;
fail:
if (ep)
ep->driver_data = NULL;
return status;
}
static void
f_audio_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_audio *audio = func_to_audio(f);
usb_free_all_descriptors(f);
kfree(audio);
}
static int generic_set_cmd(struct usb_audio_control *con, u8 cmd, int value)
{
con->data[cmd] = value;
return 0;
}
static int generic_get_cmd(struct usb_audio_control *con, u8 cmd)
{
return con->data[cmd];
}
static int __init control_selector_init(struct f_audio *audio)
{
INIT_LIST_HEAD(&audio->cs);
list_add(&feature_unit.list, &audio->cs);
INIT_LIST_HEAD(&feature_unit.control);
list_add(&mute_control.list, &feature_unit.control);
list_add(&volume_control.list, &feature_unit.control);
volume_control.data[UAC__CUR] = 0xffc0;
volume_control.data[UAC__MIN] = 0xe3a0;
volume_control.data[UAC__MAX] = 0xfff0;
volume_control.data[UAC__RES] = 0x0030;
return 0;
}
static int __init audio_bind_config(struct usb_configuration *c)
{
struct f_audio *audio;
int status;
audio = kzalloc(sizeof *audio, GFP_KERNEL);
if (!audio)
return -ENOMEM;
audio->card.func.name = "g_audio";
audio->card.gadget = c->cdev->gadget;
INIT_LIST_HEAD(&audio->play_queue);
spin_lock_init(&audio->lock);
status = gaudio_setup(&audio->card);
if (status < 0)
goto setup_fail;
audio->card.func.strings = audio_strings;
audio->card.func.bind = f_audio_bind;
audio->card.func.unbind = f_audio_unbind;
audio->card.func.set_alt = f_audio_set_alt;
audio->card.func.setup = f_audio_setup;
audio->card.func.disable = f_audio_disable;
control_selector_init(audio);
INIT_WORK(&audio->playback_work, f_audio_playback_work);
status = usb_add_function(c, &audio->card.func);
if (status)
goto add_fail;
INFO(c->cdev, "audio_buf_size %d, req_buf_size %d, req_count %d\n",
audio_buf_size, req_buf_size, req_count);
return status;
add_fail:
gaudio_cleanup();
setup_fail:
kfree(audio);
return status;
}
