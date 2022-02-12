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
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_SETUP;
memcpy(&uvc_event->req, ctrl, sizeof(uvc_event->req));
v4l2_event_queue(uvc->vdev, &v4l2_event);
return 0;
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
return uvc->state == UVC_STATE_STREAMING ? 1 : 0;
}
static int
uvc_function_set_alt(struct usb_function *f, unsigned interface, unsigned alt)
{
struct uvc_device *uvc = to_uvc(f);
struct v4l2_event v4l2_event;
struct uvc_event *uvc_event = (void *)&v4l2_event.u.data;
int ret;
INFO(f->config->cdev, "uvc_function_set_alt(%u, %u)\n", interface, alt);
if (interface == uvc->control_intf) {
if (alt)
return -EINVAL;
if (uvc->state == UVC_STATE_DISCONNECTED) {
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_CONNECT;
uvc_event->speed = f->config->cdev->gadget->speed;
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
if (uvc->video.ep)
usb_ep_disable(uvc->video.ep);
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_STREAMOFF;
v4l2_event_queue(uvc->vdev, &v4l2_event);
uvc->state = UVC_STATE_CONNECTED;
break;
case 1:
if (uvc->state != UVC_STATE_CONNECTED)
return 0;
if (uvc->video.ep) {
ret = config_ep_by_speed(f->config->cdev->gadget,
&(uvc->func), uvc->video.ep);
if (ret)
return ret;
usb_ep_enable(uvc->video.ep);
}
memset(&v4l2_event, 0, sizeof(v4l2_event));
v4l2_event.type = UVC_EVENT_STREAMON;
v4l2_event_queue(uvc->vdev, &v4l2_event);
uvc->state = UVC_STATE_STREAMING;
break;
default:
return -EINVAL;
}
return 0;
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
video->parent = &cdev->gadget->dev;
video->fops = &uvc_v4l2_fops;
video->release = video_device_release;
strncpy(video->name, cdev->gadget->name, sizeof(video->name));
uvc->vdev = video;
video_set_drvdata(video, uvc);
return video_register_device(video, VFL_TYPE_GRABBER, -1);
}
static struct usb_descriptor_header ** __init
uvc_copy_descriptors(struct uvc_device *uvc, enum usb_device_speed speed)
{
struct uvc_input_header_descriptor *uvc_streaming_header;
struct uvc_header_descriptor *uvc_control_header;
const struct uvc_descriptor_header * const *uvc_control_desc;
const struct uvc_descriptor_header * const *uvc_streaming_cls;
const struct usb_descriptor_header * const *uvc_streaming_std;
const struct usb_descriptor_header * const *src;
static struct usb_endpoint_descriptor *uvc_control_ep;
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
uvc_control_ep = &uvc_ss_control_ep;
break;
case USB_SPEED_HIGH:
uvc_control_desc = uvc->desc.fs_control;
uvc_streaming_cls = uvc->desc.hs_streaming;
uvc_streaming_std = uvc_hs_streaming;
uvc_control_ep = &uvc_fs_control_ep;
break;
case USB_SPEED_FULL:
default:
uvc_control_desc = uvc->desc.fs_control;
uvc_streaming_cls = uvc->desc.fs_streaming;
uvc_streaming_std = uvc_fs_streaming;
uvc_control_ep = &uvc_fs_control_ep;
break;
}
control_size = 0;
streaming_size = 0;
bytes = uvc_iad.bLength + uvc_control_intf.bLength
+ uvc_control_ep->bLength + uvc_control_cs_ep.bLength
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
UVC_COPY_DESCRIPTOR(mem, dst, uvc_control_ep);
if (speed == USB_SPEED_SUPER)
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_ss_control_comp);
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_control_cs_ep);
UVC_COPY_DESCRIPTOR(mem, dst, &uvc_streaming_intf_alt0);
uvc_streaming_header = mem;
UVC_COPY_DESCRIPTORS(mem, dst,
(const struct usb_descriptor_header**)uvc_streaming_cls);
uvc_streaming_header->wTotalLength = cpu_to_le16(streaming_size);
uvc_streaming_header->bEndpointAddress =
uvc_fs_streaming_ep.bEndpointAddress;
UVC_COPY_DESCRIPTORS(mem, dst, uvc_streaming_std);
*dst = NULL;
return hdr;
}
static void
uvc_function_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct uvc_device *uvc = to_uvc(f);
INFO(cdev, "uvc_function_unbind\n");
video_unregister_device(uvc->vdev);
uvc->control_ep->driver_data = NULL;
uvc->video.ep->driver_data = NULL;
uvc_en_us_strings[UVC_STRING_ASSOCIATION_IDX].id = 0;
usb_ep_free_request(cdev->gadget->ep0, uvc->control_req);
kfree(uvc->control_buf);
usb_free_all_descriptors(f);
kfree(uvc);
}
static int __init
uvc_function_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct uvc_device *uvc = to_uvc(f);
struct usb_ep *ep;
int ret = -EINVAL;
INFO(cdev, "uvc_function_bind\n");
if (streaming_interval < 1)
streaming_interval = 1;
if (streaming_interval > 16)
streaming_interval = 16;
if (streaming_mult > 2)
streaming_mult = 2;
if (streaming_maxburst > 15)
streaming_maxburst = 15;
uvc_fs_streaming_ep.wMaxPacketSize = streaming_maxpacket > 1023 ?
1023 : streaming_maxpacket;
uvc_fs_streaming_ep.bInterval = streaming_interval;
ep = usb_ep_autoconfig(cdev->gadget, &uvc_fs_control_ep);
if (!ep) {
INFO(cdev, "Unable to allocate control EP\n");
goto error;
}
uvc->control_ep = ep;
ep->driver_data = uvc;
ep = usb_ep_autoconfig(cdev->gadget, &uvc_fs_streaming_ep);
if (!ep) {
INFO(cdev, "Unable to allocate streaming EP\n");
goto error;
}
uvc->video.ep = ep;
ep->driver_data = uvc;
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
if (streaming_maxpacket > 1024)
streaming_maxpacket = 1024;
uvc_hs_streaming_ep.wMaxPacketSize = streaming_maxpacket;
uvc_hs_streaming_ep.wMaxPacketSize |= streaming_mult << 11;
uvc_hs_streaming_ep.bInterval = streaming_interval;
uvc_hs_streaming_ep.bEndpointAddress =
uvc_fs_streaming_ep.bEndpointAddress;
uvc_ss_streaming_ep.wMaxPacketSize = streaming_maxpacket;
uvc_ss_streaming_ep.bInterval = streaming_interval;
uvc_ss_streaming_comp.bmAttributes = streaming_mult;
uvc_ss_streaming_comp.bMaxBurst = streaming_maxburst;
uvc_ss_streaming_comp.wBytesPerInterval =
streaming_maxpacket * (streaming_mult + 1) *
(streaming_maxburst + 1);
uvc_ss_streaming_ep.bEndpointAddress =
uvc_fs_streaming_ep.bEndpointAddress;
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
ret = uvc_video_init(&uvc->video);
if (ret < 0)
goto error;
ret = uvc_register_video(uvc);
if (ret < 0) {
printk(KERN_INFO "Unable to register video device\n");
goto error;
}
return 0;
error:
if (uvc->vdev)
video_device_release(uvc->vdev);
if (uvc->control_ep)
uvc->control_ep->driver_data = NULL;
if (uvc->video.ep)
uvc->video.ep->driver_data = NULL;
if (uvc->control_req) {
usb_ep_free_request(cdev->gadget->ep0, uvc->control_req);
kfree(uvc->control_buf);
}
usb_free_all_descriptors(f);
return ret;
}
int __init
uvc_bind_config(struct usb_configuration *c,
const struct uvc_descriptor_header * const *fs_control,
const struct uvc_descriptor_header * const *ss_control,
const struct uvc_descriptor_header * const *fs_streaming,
const struct uvc_descriptor_header * const *hs_streaming,
const struct uvc_descriptor_header * const *ss_streaming)
{
struct uvc_device *uvc;
int ret = 0;
if (!gadget_is_dualspeed(c->cdev->gadget))
return -EINVAL;
uvc = kzalloc(sizeof(*uvc), GFP_KERNEL);
if (uvc == NULL)
return -ENOMEM;
uvc->state = UVC_STATE_DISCONNECTED;
if (fs_control == NULL || fs_control[0] == NULL ||
fs_control[0]->bDescriptorSubType != UVC_VC_HEADER)
goto error;
if (ss_control == NULL || ss_control[0] == NULL ||
ss_control[0]->bDescriptorSubType != UVC_VC_HEADER)
goto error;
if (fs_streaming == NULL || fs_streaming[0] == NULL ||
fs_streaming[0]->bDescriptorSubType != UVC_VS_INPUT_HEADER)
goto error;
if (hs_streaming == NULL || hs_streaming[0] == NULL ||
hs_streaming[0]->bDescriptorSubType != UVC_VS_INPUT_HEADER)
goto error;
if (ss_streaming == NULL || ss_streaming[0] == NULL ||
ss_streaming[0]->bDescriptorSubType != UVC_VS_INPUT_HEADER)
goto error;
uvc->desc.fs_control = fs_control;
uvc->desc.ss_control = ss_control;
uvc->desc.fs_streaming = fs_streaming;
uvc->desc.hs_streaming = hs_streaming;
uvc->desc.ss_streaming = ss_streaming;
if (uvc_en_us_strings[UVC_STRING_ASSOCIATION_IDX].id == 0) {
ret = usb_string_ids_tab(c->cdev, uvc_en_us_strings);
if (ret)
goto error;
uvc_iad.iFunction =
uvc_en_us_strings[UVC_STRING_ASSOCIATION_IDX].id;
uvc_control_intf.iInterface =
uvc_en_us_strings[UVC_STRING_CONTROL_IDX].id;
ret = uvc_en_us_strings[UVC_STRING_STREAMING_IDX].id;
uvc_streaming_intf_alt0.iInterface = ret;
uvc_streaming_intf_alt1.iInterface = ret;
}
uvc->func.name = "uvc";
uvc->func.strings = uvc_function_strings;
uvc->func.bind = uvc_function_bind;
uvc->func.unbind = uvc_function_unbind;
uvc->func.get_alt = uvc_function_get_alt;
uvc->func.set_alt = uvc_function_set_alt;
uvc->func.disable = uvc_function_disable;
uvc->func.setup = uvc_function_setup;
ret = usb_add_function(c, &uvc->func);
if (ret)
kfree(uvc);
return ret;
error:
kfree(uvc);
return ret;
}
