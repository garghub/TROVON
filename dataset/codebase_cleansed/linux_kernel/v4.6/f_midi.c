static inline struct f_midi *func_to_midi(struct usb_function *f)
{
return container_of(f, struct f_midi, func);
}
static inline struct usb_request *midi_alloc_ep_req(struct usb_ep *ep,
unsigned length)
{
return alloc_ep_req(ep, length, length);
}
static void f_midi_read_data(struct usb_ep *ep, int cable,
uint8_t *data, int length)
{
struct f_midi *midi = ep->driver_data;
struct snd_rawmidi_substream *substream = midi->out_substream[cable];
if (!substream)
return;
if (!test_bit(cable, &midi->out_triggered))
return;
snd_rawmidi_receive(substream, data, length);
}
static void f_midi_handle_out_data(struct usb_ep *ep, struct usb_request *req)
{
unsigned int i;
u8 *buf = req->buf;
for (i = 0; i + 3 < req->actual; i += 4)
if (buf[i] != 0) {
int cable = buf[i] >> 4;
int length = f_midi_cin_length[buf[i] & 0x0f];
f_midi_read_data(ep, cable, &buf[i + 1], length);
}
}
static void
f_midi_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_midi *midi = ep->driver_data;
struct usb_composite_dev *cdev = midi->func.config->cdev;
int status = req->status;
switch (status) {
case 0:
if (ep == midi->out_ep) {
f_midi_handle_out_data(ep, req);
} else if (ep == midi->in_ep) {
req->length = 0;
f_midi_transmit(midi);
return;
}
break;
case -ECONNABORTED:
case -ECONNRESET:
case -ESHUTDOWN:
VDBG(cdev, "%s gone (%d), %d/%d\n", ep->name, status,
req->actual, req->length);
if (ep == midi->out_ep) {
f_midi_handle_out_data(ep, req);
free_ep_req(ep, req);
}
return;
case -EOVERFLOW:
default:
DBG(cdev, "%s complete --> %d, %d/%d\n", ep->name,
status, req->actual, req->length);
break;
case -EREMOTEIO:
break;
}
status = usb_ep_queue(ep, req, GFP_ATOMIC);
if (status) {
ERROR(cdev, "kill %s: resubmit %d bytes --> %d\n",
ep->name, req->length, status);
usb_ep_set_halt(ep);
}
}
static int f_midi_start_ep(struct f_midi *midi,
struct usb_function *f,
struct usb_ep *ep)
{
int err;
struct usb_composite_dev *cdev = f->config->cdev;
usb_ep_disable(ep);
err = config_ep_by_speed(midi->gadget, f, ep);
if (err) {
ERROR(cdev, "can't configure %s: %d\n", ep->name, err);
return err;
}
err = usb_ep_enable(ep);
if (err) {
ERROR(cdev, "can't start %s: %d\n", ep->name, err);
return err;
}
ep->driver_data = midi;
return 0;
}
static int f_midi_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_midi *midi = func_to_midi(f);
unsigned i;
int err;
if (intf != midi->ms_id)
return 0;
err = f_midi_start_ep(midi, f, midi->in_ep);
if (err)
return err;
err = f_midi_start_ep(midi, f, midi->out_ep);
if (err)
return err;
while (kfifo_avail(&midi->in_req_fifo)) {
struct usb_request *req =
midi_alloc_ep_req(midi->in_ep, midi->buflen);
if (req == NULL)
return -ENOMEM;
req->length = 0;
req->complete = f_midi_complete;
kfifo_put(&midi->in_req_fifo, req);
}
for (i = 0; i < midi->qlen && err == 0; i++) {
struct usb_request *req =
midi_alloc_ep_req(midi->out_ep,
max_t(unsigned, midi->buflen,
bulk_out_desc.wMaxPacketSize));
if (req == NULL)
return -ENOMEM;
req->complete = f_midi_complete;
err = usb_ep_queue(midi->out_ep, req, GFP_ATOMIC);
if (err) {
ERROR(midi, "%s: couldn't enqueue request: %d\n",
midi->out_ep->name, err);
free_ep_req(midi->out_ep, req);
return err;
}
}
return 0;
}
static void f_midi_disable(struct usb_function *f)
{
struct f_midi *midi = func_to_midi(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = NULL;
DBG(cdev, "disable\n");
usb_ep_disable(midi->in_ep);
usb_ep_disable(midi->out_ep);
while (kfifo_get(&midi->in_req_fifo, &req))
free_ep_req(midi->in_ep, req);
}
static int f_midi_snd_free(struct snd_device *device)
{
return 0;
}
static void f_midi_transmit_packet(struct usb_request *req, uint8_t p0,
uint8_t p1, uint8_t p2, uint8_t p3)
{
unsigned length = req->length;
u8 *buf = (u8 *)req->buf + length;
buf[0] = p0;
buf[1] = p1;
buf[2] = p2;
buf[3] = p3;
req->length = length + 4;
}
static void f_midi_transmit_byte(struct usb_request *req,
struct gmidi_in_port *port, uint8_t b)
{
uint8_t p0 = port->cable << 4;
if (b >= 0xf8) {
f_midi_transmit_packet(req, p0 | 0x0f, b, 0, 0);
} else if (b >= 0xf0) {
switch (b) {
case 0xf0:
port->data[0] = b;
port->state = STATE_SYSEX_1;
break;
case 0xf1:
case 0xf3:
port->data[0] = b;
port->state = STATE_1PARAM;
break;
case 0xf2:
port->data[0] = b;
port->state = STATE_2PARAM_1;
break;
case 0xf4:
case 0xf5:
port->state = STATE_UNKNOWN;
break;
case 0xf6:
f_midi_transmit_packet(req, p0 | 0x05, 0xf6, 0, 0);
port->state = STATE_UNKNOWN;
break;
case 0xf7:
switch (port->state) {
case STATE_SYSEX_0:
f_midi_transmit_packet(req,
p0 | 0x05, 0xf7, 0, 0);
break;
case STATE_SYSEX_1:
f_midi_transmit_packet(req,
p0 | 0x06, port->data[0], 0xf7, 0);
break;
case STATE_SYSEX_2:
f_midi_transmit_packet(req,
p0 | 0x07, port->data[0],
port->data[1], 0xf7);
break;
}
port->state = STATE_UNKNOWN;
break;
}
} else if (b >= 0x80) {
port->data[0] = b;
if (b >= 0xc0 && b <= 0xdf)
port->state = STATE_1PARAM;
else
port->state = STATE_2PARAM_1;
} else {
switch (port->state) {
case STATE_1PARAM:
if (port->data[0] < 0xf0) {
p0 |= port->data[0] >> 4;
} else {
p0 |= 0x02;
port->state = STATE_UNKNOWN;
}
f_midi_transmit_packet(req, p0, port->data[0], b, 0);
break;
case STATE_2PARAM_1:
port->data[1] = b;
port->state = STATE_2PARAM_2;
break;
case STATE_2PARAM_2:
if (port->data[0] < 0xf0) {
p0 |= port->data[0] >> 4;
port->state = STATE_2PARAM_1;
} else {
p0 |= 0x03;
port->state = STATE_UNKNOWN;
}
f_midi_transmit_packet(req,
p0, port->data[0], port->data[1], b);
break;
case STATE_SYSEX_0:
port->data[0] = b;
port->state = STATE_SYSEX_1;
break;
case STATE_SYSEX_1:
port->data[1] = b;
port->state = STATE_SYSEX_2;
break;
case STATE_SYSEX_2:
f_midi_transmit_packet(req,
p0 | 0x04, port->data[0], port->data[1], b);
port->state = STATE_SYSEX_0;
break;
}
}
}
static void f_midi_drop_out_substreams(struct f_midi *midi)
{
unsigned int i;
for (i = 0; i < midi->in_ports; i++) {
struct gmidi_in_port *port = midi->in_ports_array + i;
struct snd_rawmidi_substream *substream = port->substream;
if (port->active && substream)
snd_rawmidi_drop_output(substream);
}
}
static int f_midi_do_transmit(struct f_midi *midi, struct usb_ep *ep)
{
struct usb_request *req = NULL;
unsigned int len, i;
bool active = false;
int err;
len = kfifo_peek(&midi->in_req_fifo, &req);
if (len != 1) {
ERROR(midi, "%s: Couldn't get usb request\n", __func__);
return -1;
}
if (req->length > 0)
return 0;
for (i = midi->in_last_port; i < midi->in_ports; ++i) {
struct gmidi_in_port *port = midi->in_ports_array + i;
struct snd_rawmidi_substream *substream = port->substream;
if (!port->active || !substream)
continue;
while (req->length + 3 < midi->buflen) {
uint8_t b;
if (snd_rawmidi_transmit(substream, &b, 1) != 1) {
port->active = 0;
break;
}
f_midi_transmit_byte(req, port, b);
}
active = !!port->active;
if (active)
break;
}
midi->in_last_port = active ? i : 0;
if (req->length <= 0)
goto done;
err = usb_ep_queue(ep, req, GFP_ATOMIC);
if (err < 0) {
ERROR(midi, "%s failed to queue req: %d\n",
midi->in_ep->name, err);
req->length = 0;
} else {
kfifo_skip(&midi->in_req_fifo);
kfifo_put(&midi->in_req_fifo, req);
}
done:
return active;
}
static void f_midi_transmit(struct f_midi *midi)
{
struct usb_ep *ep = midi->in_ep;
int ret;
unsigned long flags;
if (!ep || !ep->enabled)
goto drop_out;
spin_lock_irqsave(&midi->transmit_lock, flags);
do {
ret = f_midi_do_transmit(midi, ep);
if (ret < 0) {
spin_unlock_irqrestore(&midi->transmit_lock, flags);
goto drop_out;
}
} while (ret);
spin_unlock_irqrestore(&midi->transmit_lock, flags);
return;
drop_out:
f_midi_drop_out_substreams(midi);
}
static void f_midi_in_tasklet(unsigned long data)
{
struct f_midi *midi = (struct f_midi *) data;
f_midi_transmit(midi);
}
static int f_midi_in_open(struct snd_rawmidi_substream *substream)
{
struct f_midi *midi = substream->rmidi->private_data;
struct gmidi_in_port *port;
if (substream->number >= midi->in_ports)
return -EINVAL;
VDBG(midi, "%s()\n", __func__);
port = midi->in_ports_array + substream->number;
port->substream = substream;
port->state = STATE_UNKNOWN;
return 0;
}
static int f_midi_in_close(struct snd_rawmidi_substream *substream)
{
struct f_midi *midi = substream->rmidi->private_data;
VDBG(midi, "%s()\n", __func__);
return 0;
}
static void f_midi_in_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct f_midi *midi = substream->rmidi->private_data;
if (substream->number >= midi->in_ports)
return;
VDBG(midi, "%s() %d\n", __func__, up);
midi->in_ports_array[substream->number].active = up;
if (up)
tasklet_hi_schedule(&midi->tasklet);
}
static int f_midi_out_open(struct snd_rawmidi_substream *substream)
{
struct f_midi *midi = substream->rmidi->private_data;
if (substream->number >= MAX_PORTS)
return -EINVAL;
VDBG(midi, "%s()\n", __func__);
midi->out_substream[substream->number] = substream;
return 0;
}
static int f_midi_out_close(struct snd_rawmidi_substream *substream)
{
struct f_midi *midi = substream->rmidi->private_data;
VDBG(midi, "%s()\n", __func__);
return 0;
}
static void f_midi_out_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct f_midi *midi = substream->rmidi->private_data;
VDBG(midi, "%s()\n", __func__);
if (up)
set_bit(substream->number, &midi->out_triggered);
else
clear_bit(substream->number, &midi->out_triggered);
}
static inline void f_midi_unregister_card(struct f_midi *midi)
{
if (midi->card) {
snd_card_free(midi->card);
midi->card = NULL;
}
}
static int f_midi_register_card(struct f_midi *midi)
{
struct snd_card *card;
struct snd_rawmidi *rmidi;
int err;
static struct snd_device_ops ops = {
.dev_free = f_midi_snd_free,
};
err = snd_card_new(&midi->gadget->dev, midi->index, midi->id,
THIS_MODULE, 0, &card);
if (err < 0) {
ERROR(midi, "snd_card_new() failed\n");
goto fail;
}
midi->card = card;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, midi, &ops);
if (err < 0) {
ERROR(midi, "snd_device_new() failed: error %d\n", err);
goto fail;
}
strcpy(card->driver, f_midi_longname);
strcpy(card->longname, f_midi_longname);
strcpy(card->shortname, f_midi_shortname);
snd_component_add(card, "MIDI");
err = snd_rawmidi_new(card, card->longname, 0,
midi->out_ports, midi->in_ports, &rmidi);
if (err < 0) {
ERROR(midi, "snd_rawmidi_new() failed: error %d\n", err);
goto fail;
}
midi->rmidi = rmidi;
midi->in_last_port = 0;
strcpy(rmidi->name, card->shortname);
rmidi->info_flags = SNDRV_RAWMIDI_INFO_OUTPUT |
SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
rmidi->private_data = midi;
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &gmidi_in_ops);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &gmidi_out_ops);
err = snd_card_register(card);
if (err < 0) {
ERROR(midi, "snd_card_register() failed\n");
goto fail;
}
VDBG(midi, "%s() finished ok\n", __func__);
return 0;
fail:
f_midi_unregister_card(midi);
return err;
}
static int f_midi_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_descriptor_header **midi_function;
struct usb_midi_in_jack_descriptor jack_in_ext_desc[MAX_PORTS];
struct usb_midi_in_jack_descriptor jack_in_emb_desc[MAX_PORTS];
struct usb_midi_out_jack_descriptor_1 jack_out_ext_desc[MAX_PORTS];
struct usb_midi_out_jack_descriptor_1 jack_out_emb_desc[MAX_PORTS];
struct usb_composite_dev *cdev = c->cdev;
struct f_midi *midi = func_to_midi(f);
struct usb_string *us;
int status, n, jack = 1, i = 0;
midi->gadget = cdev->gadget;
tasklet_init(&midi->tasklet, f_midi_in_tasklet, (unsigned long) midi);
status = f_midi_register_card(midi);
if (status < 0)
goto fail_register;
us = usb_gstrings_attach(c->cdev, midi_strings,
ARRAY_SIZE(midi_string_defs));
if (IS_ERR(us)) {
status = PTR_ERR(us);
goto fail;
}
ac_interface_desc.iInterface = us[STRING_FUNC_IDX].id;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
ac_interface_desc.bInterfaceNumber = status;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
ms_interface_desc.bInterfaceNumber = status;
ac_header_desc.baInterfaceNr[0] = status;
midi->ms_id = status;
status = -ENODEV;
midi->in_ep = usb_ep_autoconfig(cdev->gadget, &bulk_in_desc);
if (!midi->in_ep)
goto fail;
midi->out_ep = usb_ep_autoconfig(cdev->gadget, &bulk_out_desc);
if (!midi->out_ep)
goto fail;
midi_function = kcalloc((MAX_PORTS * 4) + 9, sizeof(*midi_function),
GFP_KERNEL);
if (!midi_function) {
status = -ENOMEM;
goto fail;
}
midi_function[i++] = (struct usb_descriptor_header *) &ac_interface_desc;
midi_function[i++] = (struct usb_descriptor_header *) &ac_header_desc;
midi_function[i++] = (struct usb_descriptor_header *) &ms_interface_desc;
n = USB_DT_MS_HEADER_SIZE
+ (midi->in_ports + midi->out_ports) *
(USB_DT_MIDI_IN_SIZE + USB_DT_MIDI_OUT_SIZE(1));
ms_header_desc.wTotalLength = cpu_to_le16(n);
midi_function[i++] = (struct usb_descriptor_header *) &ms_header_desc;
for (n = 0; n < midi->in_ports; n++) {
struct usb_midi_in_jack_descriptor *in_ext = &jack_in_ext_desc[n];
struct usb_midi_out_jack_descriptor_1 *out_emb = &jack_out_emb_desc[n];
in_ext->bLength = USB_DT_MIDI_IN_SIZE;
in_ext->bDescriptorType = USB_DT_CS_INTERFACE;
in_ext->bDescriptorSubtype = USB_MS_MIDI_IN_JACK;
in_ext->bJackType = USB_MS_EXTERNAL;
in_ext->bJackID = jack++;
in_ext->iJack = 0;
midi_function[i++] = (struct usb_descriptor_header *) in_ext;
out_emb->bLength = USB_DT_MIDI_OUT_SIZE(1);
out_emb->bDescriptorType = USB_DT_CS_INTERFACE;
out_emb->bDescriptorSubtype = USB_MS_MIDI_OUT_JACK;
out_emb->bJackType = USB_MS_EMBEDDED;
out_emb->bJackID = jack++;
out_emb->bNrInputPins = 1;
out_emb->pins[0].baSourcePin = 1;
out_emb->pins[0].baSourceID = in_ext->bJackID;
out_emb->iJack = 0;
midi_function[i++] = (struct usb_descriptor_header *) out_emb;
ms_in_desc.baAssocJackID[n] = out_emb->bJackID;
}
for (n = 0; n < midi->out_ports; n++) {
struct usb_midi_in_jack_descriptor *in_emb = &jack_in_emb_desc[n];
struct usb_midi_out_jack_descriptor_1 *out_ext = &jack_out_ext_desc[n];
in_emb->bLength = USB_DT_MIDI_IN_SIZE;
in_emb->bDescriptorType = USB_DT_CS_INTERFACE;
in_emb->bDescriptorSubtype = USB_MS_MIDI_IN_JACK;
in_emb->bJackType = USB_MS_EMBEDDED;
in_emb->bJackID = jack++;
in_emb->iJack = 0;
midi_function[i++] = (struct usb_descriptor_header *) in_emb;
out_ext->bLength = USB_DT_MIDI_OUT_SIZE(1);
out_ext->bDescriptorType = USB_DT_CS_INTERFACE;
out_ext->bDescriptorSubtype = USB_MS_MIDI_OUT_JACK;
out_ext->bJackType = USB_MS_EXTERNAL;
out_ext->bJackID = jack++;
out_ext->bNrInputPins = 1;
out_ext->iJack = 0;
out_ext->pins[0].baSourceID = in_emb->bJackID;
out_ext->pins[0].baSourcePin = 1;
midi_function[i++] = (struct usb_descriptor_header *) out_ext;
ms_out_desc.baAssocJackID[n] = in_emb->bJackID;
}
ms_out_desc.bLength = USB_DT_MS_ENDPOINT_SIZE(midi->in_ports);
ms_out_desc.bNumEmbMIDIJack = midi->in_ports;
ms_in_desc.bLength = USB_DT_MS_ENDPOINT_SIZE(midi->out_ports);
ms_in_desc.bNumEmbMIDIJack = midi->out_ports;
midi_function[i++] = (struct usb_descriptor_header *) &bulk_out_desc;
midi_function[i++] = (struct usb_descriptor_header *) &ms_out_desc;
midi_function[i++] = (struct usb_descriptor_header *) &bulk_in_desc;
midi_function[i++] = (struct usb_descriptor_header *) &ms_in_desc;
midi_function[i++] = NULL;
f->fs_descriptors = usb_copy_descriptors(midi_function);
if (!f->fs_descriptors)
goto fail_f_midi;
if (gadget_is_dualspeed(c->cdev->gadget)) {
bulk_in_desc.wMaxPacketSize = cpu_to_le16(512);
bulk_out_desc.wMaxPacketSize = cpu_to_le16(512);
f->hs_descriptors = usb_copy_descriptors(midi_function);
if (!f->hs_descriptors)
goto fail_f_midi;
}
kfree(midi_function);
return 0;
fail_f_midi:
kfree(midi_function);
usb_free_descriptors(f->hs_descriptors);
fail:
f_midi_unregister_card(midi);
fail_register:
ERROR(cdev, "%s: can't bind, err %d\n", f->name, status);
return status;
}
static inline struct f_midi_opts *to_f_midi_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_midi_opts,
func_inst.group);
}
static void midi_attr_release(struct config_item *item)
{
struct f_midi_opts *opts = to_f_midi_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static ssize_t f_midi_opts_id_show(struct config_item *item, char *page)
{
struct f_midi_opts *opts = to_f_midi_opts(item);
int result;
mutex_lock(&opts->lock);
if (opts->id) {
result = strlcpy(page, opts->id, PAGE_SIZE);
} else {
page[0] = 0;
result = 0;
}
mutex_unlock(&opts->lock);
return result;
}
static ssize_t f_midi_opts_id_store(struct config_item *item,
const char *page, size_t len)
{
struct f_midi_opts *opts = to_f_midi_opts(item);
int ret;
char *c;
mutex_lock(&opts->lock);
if (opts->refcnt) {
ret = -EBUSY;
goto end;
}
c = kstrndup(page, len, GFP_KERNEL);
if (!c) {
ret = -ENOMEM;
goto end;
}
if (opts->id_allocated)
kfree(opts->id);
opts->id = c;
opts->id_allocated = true;
ret = len;
end:
mutex_unlock(&opts->lock);
return ret;
}
static void f_midi_free_inst(struct usb_function_instance *f)
{
struct f_midi_opts *opts;
opts = container_of(f, struct f_midi_opts, func_inst);
if (opts->id_allocated)
kfree(opts->id);
kfree(opts);
}
static struct usb_function_instance *f_midi_alloc_inst(void)
{
struct f_midi_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
mutex_init(&opts->lock);
opts->func_inst.free_func_inst = f_midi_free_inst;
opts->index = SNDRV_DEFAULT_IDX1;
opts->id = SNDRV_DEFAULT_STR1;
opts->buflen = 256;
opts->qlen = 32;
opts->in_ports = 1;
opts->out_ports = 1;
config_group_init_type_name(&opts->func_inst.group, "",
&midi_func_type);
return &opts->func_inst;
}
static void f_midi_free(struct usb_function *f)
{
struct f_midi *midi;
struct f_midi_opts *opts;
midi = func_to_midi(f);
opts = container_of(f->fi, struct f_midi_opts, func_inst);
kfree(midi->id);
mutex_lock(&opts->lock);
kfifo_free(&midi->in_req_fifo);
kfree(midi);
--opts->refcnt;
mutex_unlock(&opts->lock);
}
static void f_midi_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = f->config->cdev;
struct f_midi *midi = func_to_midi(f);
struct snd_card *card;
DBG(cdev, "unbind\n");
f_midi_disable(f);
card = midi->card;
midi->card = NULL;
if (card)
snd_card_free(card);
usb_free_all_descriptors(f);
}
static struct usb_function *f_midi_alloc(struct usb_function_instance *fi)
{
struct f_midi *midi = NULL;
struct f_midi_opts *opts;
int status, i;
opts = container_of(fi, struct f_midi_opts, func_inst);
mutex_lock(&opts->lock);
if (opts->in_ports > MAX_PORTS || opts->out_ports > MAX_PORTS) {
status = -EINVAL;
goto setup_fail;
}
midi = kzalloc(
sizeof(*midi) + opts->in_ports * sizeof(*midi->in_ports_array),
GFP_KERNEL);
if (!midi) {
status = -ENOMEM;
goto setup_fail;
}
for (i = 0; i < opts->in_ports; i++)
midi->in_ports_array[i].cable = i;
midi->id = kstrdup(opts->id, GFP_KERNEL);
if (opts->id && !midi->id) {
status = -ENOMEM;
goto setup_fail;
}
midi->in_ports = opts->in_ports;
midi->out_ports = opts->out_ports;
midi->index = opts->index;
midi->buflen = opts->buflen;
midi->qlen = opts->qlen;
midi->in_last_port = 0;
status = kfifo_alloc(&midi->in_req_fifo, midi->qlen, GFP_KERNEL);
if (status)
goto setup_fail;
spin_lock_init(&midi->transmit_lock);
++opts->refcnt;
mutex_unlock(&opts->lock);
midi->func.name = "gmidi function";
midi->func.bind = f_midi_bind;
midi->func.unbind = f_midi_unbind;
midi->func.set_alt = f_midi_set_alt;
midi->func.disable = f_midi_disable;
midi->func.free_func = f_midi_free;
return &midi->func;
setup_fail:
mutex_unlock(&opts->lock);
kfree(midi);
return ERR_PTR(status);
}
