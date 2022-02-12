static void increment_scan_progress(struct comedi_subdevice *subd,
unsigned int num_bytes)
{
struct comedi_async *async = subd->async;
unsigned int scan_length = cfc_bytes_per_scan(subd);
async->scan_progress += num_bytes;
if (async->scan_progress >= scan_length) {
async->scan_progress %= scan_length;
async->events |= COMEDI_CB_EOS;
}
}
unsigned int cfc_write_array_to_buffer(struct comedi_subdevice *subd,
void *data, unsigned int num_bytes)
{
struct comedi_async *async = subd->async;
unsigned int retval;
if (num_bytes == 0)
return 0;
retval = comedi_buf_write_alloc(async, num_bytes);
if (retval != num_bytes) {
dev_warn(subd->device->class_dev, "comedi: buffer overrun\n");
async->events |= COMEDI_CB_OVERFLOW;
return 0;
}
comedi_buf_memcpy_to(async, 0, data, num_bytes);
comedi_buf_write_free(async, num_bytes);
increment_scan_progress(subd, num_bytes);
async->events |= COMEDI_CB_BLOCK;
return num_bytes;
}
unsigned int cfc_read_array_from_buffer(struct comedi_subdevice *subd,
void *data, unsigned int num_bytes)
{
struct comedi_async *async = subd->async;
if (num_bytes == 0)
return 0;
num_bytes = comedi_buf_read_alloc(async, num_bytes);
comedi_buf_memcpy_from(async, 0, data, num_bytes);
comedi_buf_read_free(async, num_bytes);
increment_scan_progress(subd, num_bytes);
async->events |= COMEDI_CB_BLOCK;
return num_bytes;
}
unsigned int cfc_handle_events(struct comedi_device *dev,
struct comedi_subdevice *subd)
{
unsigned int events = subd->async->events;
if (events == 0)
return events;
if (events & (COMEDI_CB_EOA | COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW))
subd->cancel(dev, subd);
comedi_event(dev, subd);
return events;
}
static int __init comedi_fc_init_module(void)
{
return 0;
}
static void __exit comedi_fc_cleanup_module(void)
{
}
