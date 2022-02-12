int comedi_set_hw_dev(struct comedi_device *dev, struct device *hw_dev)
{
if (hw_dev == dev->hw_dev)
return 0;
if (dev->hw_dev != NULL)
return -EEXIST;
dev->hw_dev = get_device(hw_dev);
return 0;
}
static void comedi_clear_hw_dev(struct comedi_device *dev)
{
put_device(dev->hw_dev);
dev->hw_dev = NULL;
}
int comedi_alloc_subdevices(struct comedi_device *dev, int num_subdevices)
{
struct comedi_subdevice *s;
int i;
if (num_subdevices < 1)
return -EINVAL;
s = kcalloc(num_subdevices, sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
dev->subdevices = s;
dev->n_subdevices = num_subdevices;
for (i = 0; i < num_subdevices; ++i) {
s = &dev->subdevices[i];
s->device = dev;
s->index = i;
s->async_dma_dir = DMA_NONE;
spin_lock_init(&s->spin_lock);
s->minor = -1;
}
return 0;
}
static void cleanup_device(struct comedi_device *dev)
{
int i;
struct comedi_subdevice *s;
if (dev->subdevices) {
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
comedi_free_subdevice_minor(s);
if (s->async) {
comedi_buf_alloc(dev, s, 0);
kfree(s->async);
}
}
kfree(dev->subdevices);
dev->subdevices = NULL;
dev->n_subdevices = 0;
}
kfree(dev->private);
dev->private = NULL;
dev->driver = NULL;
dev->board_name = NULL;
dev->board_ptr = NULL;
dev->iobase = 0;
dev->irq = 0;
dev->read_subdev = NULL;
dev->write_subdev = NULL;
dev->open = NULL;
dev->close = NULL;
comedi_clear_hw_dev(dev);
}
static void __comedi_device_detach(struct comedi_device *dev)
{
dev->attached = 0;
if (dev->driver)
dev->driver->detach(dev);
else
dev_warn(dev->class_dev,
"BUG: dev->driver=NULL in comedi_device_detach()\n");
cleanup_device(dev);
}
void comedi_device_detach(struct comedi_device *dev)
{
if (!dev->attached)
return;
__comedi_device_detach(dev);
}
static int poll_invalid(struct comedi_device *dev, struct comedi_subdevice *s)
{
return -EINVAL;
}
int insn_inval(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
return -EINVAL;
}
static int insn_rw_emulate_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct comedi_insn new_insn;
int ret;
static const unsigned channels_per_bitfield = 32;
unsigned chan = CR_CHAN(insn->chanspec);
const unsigned base_bitfield_channel =
(chan < channels_per_bitfield) ? 0 : chan;
unsigned int new_data[2];
memset(new_data, 0, sizeof(new_data));
memset(&new_insn, 0, sizeof(new_insn));
new_insn.insn = INSN_BITS;
new_insn.chanspec = base_bitfield_channel;
new_insn.n = 2;
new_insn.subdev = insn->subdev;
if (insn->insn == INSN_WRITE) {
if (!(s->subdev_flags & SDF_WRITABLE))
return -EINVAL;
new_data[0] = 1 << (chan - base_bitfield_channel);
new_data[1] = data[0] ? (1 << (chan - base_bitfield_channel))
: 0;
}
ret = s->insn_bits(dev, s, &new_insn, new_data);
if (ret < 0)
return ret;
if (insn->insn == INSN_READ)
data[0] = (new_data[1] >> (chan - base_bitfield_channel)) & 1;
return 1;
}
static int __comedi_device_postconfig_async(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_async *async;
unsigned int buf_size;
int ret;
if ((s->subdev_flags & (SDF_CMD_READ | SDF_CMD_WRITE)) == 0) {
dev_warn(dev->class_dev,
"async subdevices must support SDF_CMD_READ or SDF_CMD_WRITE\n");
return -EINVAL;
}
if (!s->do_cmdtest) {
dev_warn(dev->class_dev,
"async subdevices must have a do_cmdtest() function\n");
return -EINVAL;
}
async = kzalloc(sizeof(*async), GFP_KERNEL);
if (!async)
return -ENOMEM;
init_waitqueue_head(&async->wait_head);
async->subdevice = s;
s->async = async;
async->max_bufsize = comedi_default_buf_maxsize_kb * 1024;
buf_size = comedi_default_buf_size_kb * 1024;
if (buf_size > async->max_bufsize)
buf_size = async->max_bufsize;
if (comedi_buf_alloc(dev, s, buf_size) < 0) {
dev_warn(dev->class_dev, "Buffer allocation failed\n");
return -ENOMEM;
}
if (s->buf_change) {
ret = s->buf_change(dev, s, buf_size);
if (ret < 0)
return ret;
}
comedi_alloc_subdevice_minor(s);
return 0;
}
static int __comedi_device_postconfig(struct comedi_device *dev)
{
struct comedi_subdevice *s;
int ret;
int i;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
if (s->type == COMEDI_SUBD_UNUSED)
continue;
if (s->len_chanlist == 0)
s->len_chanlist = 1;
if (s->do_cmd) {
ret = __comedi_device_postconfig_async(dev, s);
if (ret)
return ret;
}
if (!s->range_table && !s->range_table_list)
s->range_table = &range_unknown;
if (!s->insn_read && s->insn_bits)
s->insn_read = insn_rw_emulate_bits;
if (!s->insn_write && s->insn_bits)
s->insn_write = insn_rw_emulate_bits;
if (!s->insn_read)
s->insn_read = insn_inval;
if (!s->insn_write)
s->insn_write = insn_inval;
if (!s->insn_bits)
s->insn_bits = insn_inval;
if (!s->insn_config)
s->insn_config = insn_inval;
if (!s->poll)
s->poll = poll_invalid;
}
return 0;
}
static int comedi_device_postconfig(struct comedi_device *dev)
{
int ret = __comedi_device_postconfig(dev);
module_put(dev->driver->module);
if (ret < 0) {
__comedi_device_detach(dev);
return ret;
}
if (!dev->board_name) {
dev_warn(dev->class_dev, "BUG: dev->board_name=NULL\n");
dev->board_name = "BUG";
}
smp_wmb();
dev->attached = 1;
return 0;
}
static void *comedi_recognize(struct comedi_driver *driv, const char *name)
{
char **name_ptr = (char **)driv->board_name;
int i;
for (i = 0; i < driv->num_names; i++) {
if (strcmp(*name_ptr, name) == 0)
return name_ptr;
name_ptr = (void *)name_ptr + driv->offset;
}
return NULL;
}
static void comedi_report_boards(struct comedi_driver *driv)
{
unsigned int i;
const char *const *name_ptr;
pr_info("comedi: valid board names for %s driver are:\n",
driv->driver_name);
name_ptr = driv->board_name;
for (i = 0; i < driv->num_names; i++) {
pr_info(" %s\n", *name_ptr);
name_ptr = (const char **)((char *)name_ptr + driv->offset);
}
if (driv->num_names == 0)
pr_info(" %s\n", driv->driver_name);
}
int comedi_device_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_driver *driv;
int ret;
if (dev->attached)
return -EBUSY;
for (driv = comedi_drivers; driv; driv = driv->next) {
if (!try_module_get(driv->module))
continue;
if (driv->num_names) {
dev->board_ptr = comedi_recognize(driv, it->board_name);
if (dev->board_ptr)
break;
} else if (strcmp(driv->driver_name, it->board_name) == 0)
break;
module_put(driv->module);
}
if (driv == NULL) {
for (driv = comedi_drivers; driv; driv = driv->next) {
if (!try_module_get(driv->module))
continue;
comedi_report_boards(driv);
module_put(driv->module);
}
return -EIO;
}
if (driv->attach == NULL) {
dev_warn(dev->class_dev,
"driver '%s' does not support attach using comedi_config\n",
driv->driver_name);
module_put(driv->module);
return -ENOSYS;
}
dev->driver = driv;
ret = driv->attach(dev, it);
if (ret < 0) {
module_put(dev->driver->module);
__comedi_device_detach(dev);
return ret;
}
return comedi_device_postconfig(dev);
}
int comedi_auto_config(struct device *hardware_device,
struct comedi_driver *driver, unsigned long context)
{
int minor;
struct comedi_device *comedi_dev;
int ret;
if (!driver->auto_attach) {
dev_warn(hardware_device,
"BUG! comedi driver '%s' has no auto_attach handler\n",
driver->driver_name);
return -EINVAL;
}
minor = comedi_alloc_board_minor(hardware_device);
if (minor < 0)
return minor;
comedi_dev = comedi_dev_from_minor(minor);
mutex_lock(&comedi_dev->mutex);
if (comedi_dev->attached)
ret = -EBUSY;
else if (!try_module_get(driver->module))
ret = -EIO;
else {
comedi_set_hw_dev(comedi_dev, hardware_device);
comedi_dev->driver = driver;
ret = driver->auto_attach(comedi_dev, context);
if (ret < 0) {
module_put(driver->module);
__comedi_device_detach(comedi_dev);
} else {
ret = comedi_device_postconfig(comedi_dev);
}
}
mutex_unlock(&comedi_dev->mutex);
if (ret < 0)
comedi_free_board_minor(minor);
return ret;
}
void comedi_auto_unconfig(struct device *hardware_device)
{
int minor;
if (hardware_device == NULL)
return;
minor = comedi_find_board_minor(hardware_device);
if (minor < 0)
return;
comedi_free_board_minor(minor);
}
int comedi_driver_register(struct comedi_driver *driver)
{
driver->next = comedi_drivers;
comedi_drivers = driver;
return 0;
}
int comedi_driver_unregister(struct comedi_driver *driver)
{
struct comedi_driver *prev;
int i;
for (i = 0; i < COMEDI_NUM_BOARD_MINORS; i++) {
struct comedi_device *dev = comedi_dev_from_minor(i);
if (!dev)
continue;
mutex_lock(&dev->mutex);
if (dev->attached && dev->driver == driver) {
if (dev->use_count)
dev_warn(dev->class_dev,
"BUG! detaching device with use_count=%d\n",
dev->use_count);
comedi_device_detach(dev);
}
mutex_unlock(&dev->mutex);
}
if (comedi_drivers == driver) {
comedi_drivers = driver->next;
return 0;
}
for (prev = comedi_drivers; prev->next; prev = prev->next) {
if (prev->next == driver) {
prev->next = driver->next;
return 0;
}
}
return -EINVAL;
}
