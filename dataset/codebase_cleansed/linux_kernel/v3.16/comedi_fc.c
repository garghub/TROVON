unsigned int cfc_bytes_per_scan(struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int num_samples;
unsigned int bits_per_sample;
switch (s->type) {
case COMEDI_SUBD_DI:
case COMEDI_SUBD_DO:
case COMEDI_SUBD_DIO:
bits_per_sample = 8 * bytes_per_sample(s);
num_samples = (cmd->chanlist_len + bits_per_sample - 1) /
bits_per_sample;
break;
default:
num_samples = cmd->chanlist_len;
break;
}
return num_samples * bytes_per_sample(s);
}
void cfc_inc_scan_progress(struct comedi_subdevice *s, unsigned int num_bytes)
{
struct comedi_async *async = s->async;
unsigned int scan_length = cfc_bytes_per_scan(s);
async->scan_progress += num_bytes;
if (async->scan_progress >= scan_length) {
async->scan_progress %= scan_length;
async->events |= COMEDI_CB_EOS;
}
}
unsigned int cfc_write_array_to_buffer(struct comedi_subdevice *s,
void *data, unsigned int num_bytes)
{
struct comedi_async *async = s->async;
unsigned int retval;
if (num_bytes == 0)
return 0;
retval = comedi_buf_write_alloc(s, num_bytes);
if (retval != num_bytes) {
dev_warn(s->device->class_dev, "buffer overrun\n");
async->events |= COMEDI_CB_OVERFLOW;
return 0;
}
comedi_buf_memcpy_to(s, 0, data, num_bytes);
comedi_buf_write_free(s, num_bytes);
cfc_inc_scan_progress(s, num_bytes);
async->events |= COMEDI_CB_BLOCK;
return num_bytes;
}
unsigned int cfc_read_array_from_buffer(struct comedi_subdevice *s,
void *data, unsigned int num_bytes)
{
if (num_bytes == 0)
return 0;
num_bytes = comedi_buf_read_alloc(s, num_bytes);
comedi_buf_memcpy_from(s, 0, data, num_bytes);
comedi_buf_read_free(s, num_bytes);
cfc_inc_scan_progress(s, num_bytes);
s->async->events |= COMEDI_CB_BLOCK;
return num_bytes;
}
unsigned int cfc_handle_events(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int events = s->async->events;
if (events == 0)
return events;
if (events & (COMEDI_CB_EOA | COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW))
s->cancel(dev, s);
comedi_event(dev, s);
return events;
}
static int __init comedi_fc_init_module(void)
{
return 0;
}
static void __exit comedi_fc_cleanup_module(void)
{
}
