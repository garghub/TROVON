void uvc_set_trace_param(unsigned int trace)
{
uvc_gadget_trace_param = trace;
}
static void
uvc_function_ep0_complete(struct usb_ep *ep, struct usb_request *req)
{
struct uvc_device *uvc = req->context;
struct v4l2_event v4l2_event;
struct uvc_event *uvc_event = (void *)&v4l2_event.u.data;
if (uvc->event_setup_out) {
uvc->event_setup_out = 0;
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_DATA;
uvc_event->data.length = req->actual;
memcpy(&uvc_event->data.data, req->buf, req->actual);
v4l2_event_queue(uvc->vdev, &v4l2_event);
}
}
static int
uvc_function_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl)
{
struct uvc_device *uvc = to_uvc(f);
struct v4l2_event v4l2_event;
struct uvc_event *uvc_event = (void *)&v4l2_event.u.data;
if ((ctrl->bRequestType & USB_TYPE_MASK) != USB_TYPE_CLASS) {
INFO(f->config->cdev, "invalid request type\n");
return -EINVAL;
}
if (le16_to_cpu(ctrl->wLength) > UVC_MAX_REQUEST_SIZE)
return -EINVAL;
uvc->event_setup_out = !(ctrl->bRequestType & USB_DIR_IN);
uvc->event_length = le16_to_cpu(ctrl->wLength);
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_SETUP;
memcpy(&uvc_event->req, ctrl, sizeof(uvc_event->req));
v4l2_event_queue(uvc->vdev, &v4l2_event);
return 0;
}
void uvc_function_setup_continue(struct uvc_device *uvc)
{
struct usb_composite_dev *cdev = uvc->func.config->cdev;
usb_composite_setup_continue(cdev);
}
static int
uvc_function_get_alt(struct usb_function *f, unsigned interface)
{
struct uvc_device *uvc = to_uvc(f);
INFO(f->config->cdev, "uvc_function_get_alt(%u)\n", interface);
if (interface == uvc->control_intf)
return 0;
else if (interface != uvc->streaming_intf)
return -EINVAL;
else
return uvc->video.ep->driver_data ? 1 : 0;
}
static int
uvc_function_set_alt(struct usb_function *f, unsigned interface, unsigned alt)
{
struct uvc_device *uvc = to_uvc(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct v4l2_event v4l2_event;
struct uvc_event *uvc_event = (void *)&v4l2_event.u.data;
int ret;
INFO(cdev, "uvc_function_set_alt(%u, %u)\n", interface, alt);
if (interface == uvc->control_intf) {
if (alt)
return -EINVAL;
if (uvc->control_ep->driver_data) {
INFO(cdev, "reset UVC Control\n");
usb_ep_disable(uvc->control_ep);
uvc->control_ep->driver_data = NULL;
}
if (!uvc->control_ep->desc)
if (config_ep_by_speed(cdev->gadget, f, uvc->control_ep))
return -EINVAL;
usb_ep_enable(uvc->control_ep);
uvc->control_ep->driver_data = uvc;
if (uvc->state == UVC_STATE_DISCONNECTED) {
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_CONNECT;
uvc_event->speed = cdev->gadget->speed;
v4l2_event_queue(uvc->vdev, &v4l2_event);
uvc->state = UVC_STATE_CONNECTED;
}
return 0;
}
if (interface != uvc->streaming_intf)
return -EINVAL;
switch (alt) {
case 0:
if (uvc->state != UVC_STATE_STREAMING)
return 0;
if (uvc->video.ep) {
usb_ep_disable(uvc->video.ep);
uvc->video.ep->driver_data = NULL;
}
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_STREAMOFF;
v4l2_event_queue(uvc->vdev, &v4l2_event);
uvc->state = UVC_STATE_CONNECTED;
return 0;
case 1:
if (uvc->state != UVC_STATE_CONNECTED)
return 0;
if (!uvc->video.ep)
return -EINVAL;
if (uvc->video.ep->driver_data) {
INFO(cdev, "reset UVC\n");
usb_ep_disable(uvc->video.ep);
uvc->video.ep->driver_data = NULL;
}
ret = config_ep_by_speed(f->config->cdev->gadget,
&(uvc->func), uvc->video.ep);
if (ret)
return ret;
usb_ep_enable(uvc->video.ep);
uvc->video.ep->driver_data = uvc;
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_STREAMON;
v4l2_event_queue(uvc->vdev, &v4l2_event);
return USB_GADGET_DELAYED_STATUS;
default:
return -EINVAL;
}
}
static void
uvc_function_disable(struct usb_function *f)
{
struct uvc_device *uvc = to_uvc(f);
struct v4l2_event v4l2_event;
INFO(f->config->cdev, "uvc_function_disable\n");
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_DISCONNECT;
v4l2_event_queue(uvc->vdev, &v4l2_event);
uvc->state = UVC_STATE_DISCONNECTED;
if (uvc->video.ep->driver_data) {
usb_ep_disable(uvc->video.ep);
uvc->video.ep->driver_data = NULL;
}
if (uvc->control_ep->driver_data) {
usb_ep_disable(uvc->control_ep);
uvc->control_ep->driver_data = NULL;
}
}
void
uvc_function_connect(struct uvc_device *uvc)
{
struct usb_composite_dev *cdev = uvc->func.config->cdev;
int ret;
if ((ret = usb_function_activate(&uvc->func)) < 0)
INFO(cdev, "UVC connect failed with %d\n", ret);
}
void
uvc_function_disconnect(struct uvc_device *uvc)
{
struct usb_composite_dev *cdev = uvc->func.config->cdev;
int ret;
if ((ret = usb_function_deactivate(&uvc->func)) < 0)
INFO(cdev, "UVC disconnect failed with %d\n", ret);
}
static int
uvc_register_video(struct uvc_device *uvc)
{
struct usb_composite_dev *cdev = uvc->func.config->cdev;
struct video_device *video;
video = video_device_alloc();
if (video == NULL)
return -ENOMEM;
video->v4l2_dev = &uvc->v4l2_dev;
video->fops = &uvc_v4l2_fops;
video->ioctl_ops = &uvc_v4l2_ioctl_ops;
video->release = video_device_release;
video->vfl_dir = VFL_DIR_TX;
strlcpy(video->name, cdev->gadget->name, sizeof(video->name));
uvc->vdev = video;
video_set_drvdata(video, uvc);
return video_register_device(video, VFL_TYPE_GRABBER, -1);
}
static struct usb_descriptor_header **
uvc_copy_descriptors(struct uvc_device *uvc, enum usb_device_speed speed)
{
struct uvc_input_header_descriptor *uvc_streaming_header;
struct uvc_header_descriptor *uvc_control_header;
const struct uvc_descriptor_header * const *uvc_control_desc;
const struct uvc_descriptor_header * const *uvc_streaming_cls;
const struct usb_descriptor_header * const *uvc_streaming_std;
const struct usb_descriptor_header * const *src;
struct usb_descriptor_header **dst;
struct usb_descriptor_header **hdr;
unsigned int control_size;
unsigned int streaming_size;
unsigned int n_desc;
unsigned int bytes;
void *mem;
switch (speed) {
case USB_SPEED_SUPER:
uvc_control_desc = uvc->desc.ss_control;
uvc_streaming_cls = uvc->desc.ss_streaming;
uvc_streaming_std = uvc_ss_streaming;
break;
case USB_SPEED_HIGH:
uvc_control_desc = uvc->desc.fs_control;
uvc_streaming_cls = uvc->desc.hs_streaming;
uvc_streaming_std = uvc_hs_streaming;
break;
case USB_SPEED_FULL:
default:
uvc_control_desc = uvc->desc.fs_control;
uvc_streaming_cls = uvc->desc.fs_streaming;
uvc_streaming_std = uvc_fs_streaming;
break;
}
control_size = 0;
streaming_size = 0;
bytes = uvc_iad.bLength + uvc_control_intf.bLength
+ uvc_control_ep.bLength + uvc_control_cs_ep.bLength
+ uvc_streaming_intf_alt0.bLength;
if (speed == USB_SPEED_SUPER) {
bytes += uvc_ss_control_comp.bLength;
n_desc = 6;
} else {
n_desc = 5;
}
for (src = (const struct usb_descriptor_header **)uvc_control_desc;
*src; ++src) {
control_size += (*src)->bLength;
bytes += (*src)->bLength;
n_desc++;
}
for (src = (const struct usb_descriptor_header **)uvc_streaming_cls;
*src; ++src) {
streaming_size += (*src)->bLength;
bytes += (*src)->bLength;
n_desc++;
}
for (src = uvc_streaming_std; *src; ++src) {
bytes += (*src)->bLength;
n_desc++;
}
mem = kmalloc((n_desc + 1) * sizeof(*src) + bytes, GFP_KERNEL);
if (mem == NULL)
return NULL;
hdr = mem;
dst = mem;
mem += (n_desc + 1) * sizeof(*src);
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_iad);
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_control_intf);
uvc_control_header = mem;
UVC_COPY_DESCRIPTORS(mem, dst,
(const struct usb_descriptor_header **)uvc_control_desc);
uvc_control_header->wTotalLength = cpu_to_le16(control_size);
uvc_control_header->bInCollection = 1;
uvc_control_header->baInterfaceNr[0] = uvc->streaming_intf;
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_control_ep);
if (speed == USB_SPEED_SUPER)
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_ss_control_comp);
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_control_cs_ep);
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_streaming_intf_alt0);
uvc_streaming_header = mem;
UVC_COPY_DESCRIPTORS(mem, dst,
(const struct usb_descriptor_header**)uvc_streaming_cls);
uvc_streaming_header->wTotalLength = cpu_to_le16(streaming_size);
uvc_streaming_header->bEndpointAddress = uvc->video.ep->address;
UVC_COPY_DESCRIPTORS(mem, dst, uvc_streaming_std);
*dst = NULL;
return hdr;
}
static int
uvc_function_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct uvc_device *uvc = to_uvc(f);
struct usb_string *us;
unsigned int max_packet_mult;
unsigned int max_packet_size;
struct usb_ep *ep;
struct f_uvc_opts *opts;
int ret = -EINVAL;
INFO(cdev, "uvc_function_bind\n");
opts = to_f_uvc_opts(f->fi);
opts->streaming_interval = clamp(opts->streaming_interval, 1U, 16U);
opts->streaming_maxpacket = clamp(opts->streaming_maxpacket, 1U, 3072U);
opts->streaming_maxburst = min(opts->streaming_maxburst, 15U);
if (opts->streaming_maxpacket <= 1024) {
max_packet_mult = 1;
max_packet_size = opts->streaming_maxpacket;
} else if (opts->streaming_maxpacket <= 2048) {
max_packet_mult = 2;
max_packet_size = opts->streaming_maxpacket / 2;
} else {
max_packet_mult = 3;
max_packet_size = opts->streaming_maxpacket / 3;
}
uvc_fs_streaming_ep.wMaxPacketSize =
cpu_to_le16(min(opts->streaming_maxpacket, 1023U));
uvc_fs_streaming_ep.bInterval = opts->streaming_interval;
uvc_hs_streaming_ep.wMaxPacketSize =
cpu_to_le16(max_packet_size | ((max_packet_mult - 1) << 11));
uvc_hs_streaming_ep.bInterval = opts->streaming_interval;
uvc_ss_streaming_ep.wMaxPacketSize = cpu_to_le16(max_packet_size);
uvc_ss_streaming_ep.bInterval = opts->streaming_interval;
uvc_ss_streaming_comp.bmAttributes = max_packet_mult - 1;
uvc_ss_streaming_comp.bMaxBurst = opts->streaming_maxburst;
uvc_ss_streaming_comp.wBytesPerInterval =
cpu_to_le16(max_packet_size * max_packet_mult *
opts->streaming_maxburst);
ep = usb_ep_autoconfig(cdev->gadget, &uvc_control_ep);
if (!ep) {
INFO(cdev, "Unable to allocate control EP\n");
goto error;
}
uvc->control_ep = ep;
ep->driver_data = uvc;
if (gadget_is_superspeed(c->cdev->gadget))
ep = usb_ep_autoconfig_ss(cdev->gadget, &uvc_ss_streaming_ep,
&uvc_ss_streaming_comp);
else if (gadget_is_dualspeed(cdev->gadget))
ep = usb_ep_autoconfig(cdev->gadget, &uvc_hs_streaming_ep);
else
ep = usb_ep_autoconfig(cdev->gadget, &uvc_fs_streaming_ep);
if (!ep) {
INFO(cdev, "Unable to allocate streaming EP\n");
goto error;
}
uvc->video.ep = ep;
ep->driver_data = uvc;
uvc_fs_streaming_ep.bEndpointAddress = uvc->video.ep->address;
uvc_hs_streaming_ep.bEndpointAddress = uvc->video.ep->address;
uvc_ss_streaming_ep.bEndpointAddress = uvc->video.ep->address;
us = usb_gstrings_attach(cdev, uvc_function_strings,
ARRAY_SIZE(uvc_en_us_strings));
if (IS_ERR(us)) {
ret = PTR_ERR(us);
goto error;
}
uvc_iad.iFunction = us[UVC_STRING_CONTROL_IDX].id;
uvc_control_intf.iInterface = us[UVC_STRING_CONTROL_IDX].id;
ret = us[UVC_STRING_STREAMING_IDX].id;
uvc_streaming_intf_alt0.iInterface = ret;
uvc_streaming_intf_alt1.iInterface = ret;
if ((ret = usb_interface_id(c, f)) < 0)
goto error;
uvc_iad.bFirstInterface = ret;
uvc_control_intf.bInterfaceNumber = ret;
uvc->control_intf = ret;
if ((ret = usb_interface_id(c, f)) < 0)
goto error;
uvc_streaming_intf_alt0.bInterfaceNumber = ret;
uvc_streaming_intf_alt1.bInterfaceNumber = ret;
uvc->streaming_intf = ret;
f->fs_descriptors = uvc_copy_descriptors(uvc, USB_SPEED_FULL);
if (gadget_is_dualspeed(cdev->gadget))
f->hs_descriptors = uvc_copy_descriptors(uvc, USB_SPEED_HIGH);
if (gadget_is_superspeed(c->cdev->gadget))
f->ss_descriptors = uvc_copy_descriptors(uvc, USB_SPEED_SUPER);
uvc->control_req = usb_ep_alloc_request(cdev->gadget->ep0, GFP_KERNEL);
uvc->control_buf = kmalloc(UVC_MAX_REQUEST_SIZE, GFP_KERNEL);
if (uvc->control_req == NULL || uvc->control_buf == NULL) {
ret = -ENOMEM;
goto error;
}
uvc->control_req->buf = uvc->control_buf;
uvc->control_req->complete = uvc_function_ep0_complete;
uvc->control_req->context = uvc;
if ((ret = usb_function_deactivate(f)) < 0)
goto error;
if (v4l2_device_register(&cdev->gadget->dev, &uvc->v4l2_dev)) {
printk(KERN_INFO "v4l2_device_register failed\n");
goto error;
}
ret = uvcg_video_init(&uvc->video);
if (ret < 0)
goto error;
ret = uvc_register_video(uvc);
if (ret < 0) {
printk(KERN_INFO "Unable to register video device\n");
goto error;
}
return 0;
error:
v4l2_device_unregister(&uvc->v4l2_dev);
if (uvc->vdev)
video_device_release(uvc->vdev);
if (uvc->control_ep)
uvc->control_ep->driver_data = NULL;
if (uvc->video.ep)
uvc->video.ep->driver_data = NULL;
if (uvc->control_req)
usb_ep_free_request(cdev->gadget->ep0, uvc->control_req);
kfree(uvc->control_buf);
usb_free_all_descriptors(f);
return ret;
}
static void uvc_free_inst(struct usb_function_instance *f)
{
struct f_uvc_opts *opts = to_f_uvc_opts(f);
kfree(opts);
}
static struct usb_function_instance *uvc_alloc_inst(void)
{
struct f_uvc_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
opts->func_inst.free_func_inst = uvc_free_inst;
return &opts->func_inst;
}
static void uvc_free(struct usb_function *f)
{
struct uvc_device *uvc = to_uvc(f);
kfree(uvc);
}
static void uvc_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct uvc_device *uvc = to_uvc(f);
INFO(cdev, "%s\n", __func__);
video_unregister_device(uvc->vdev);
v4l2_device_unregister(&uvc->v4l2_dev);
uvc->control_ep->driver_data = NULL;
uvc->video.ep->driver_data = NULL;
usb_ep_free_request(cdev->gadget->ep0, uvc->control_req);
kfree(uvc->control_buf);
usb_free_all_descriptors(f);
}
static struct usb_function *uvc_alloc(struct usb_function_instance *fi)
{
struct uvc_device *uvc;
struct f_uvc_opts *opts;
uvc = kzalloc(sizeof(*uvc), GFP_KERNEL);
if (uvc == NULL)
return ERR_PTR(-ENOMEM);
uvc->state = UVC_STATE_DISCONNECTED;
opts = to_f_uvc_opts(fi);
uvc->desc.fs_control = opts->fs_control;
uvc->desc.ss_control = opts->ss_control;
uvc->desc.fs_streaming = opts->fs_streaming;
uvc->desc.hs_streaming = opts->hs_streaming;
uvc->desc.ss_streaming = opts->ss_streaming;
uvc->func.name = "uvc";
uvc->func.bind = uvc_function_bind;
uvc->func.unbind = uvc_unbind;
uvc->func.get_alt = uvc_function_get_alt;
uvc->func.set_alt = uvc_function_set_alt;
uvc->func.disable = uvc_function_disable;
uvc->func.setup = uvc_function_setup;
uvc->func.free_func = uvc_free;
return &uvc->func;
}
