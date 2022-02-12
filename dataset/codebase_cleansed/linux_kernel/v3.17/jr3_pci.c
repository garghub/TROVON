static struct jr3_pci_poll_delay poll_delay_min_max(int min, int max)
{
struct jr3_pci_poll_delay result;
result.min = min;
result.max = max;
return result;
}
static int is_complete(struct jr3_channel __iomem *channel)
{
return get_s16(&channel->command_word0) == 0;
}
static void set_transforms(struct jr3_channel __iomem *channel,
struct jr3_pci_transform transf, short num)
{
int i;
num &= 0x000f;
for (i = 0; i < 8; i++) {
set_u16(&channel->transforms[num].link[i].link_type,
transf.link[i].link_type);
udelay(1);
set_s16(&channel->transforms[num].link[i].link_amount,
transf.link[i].link_amount);
udelay(1);
if (transf.link[i].link_type == end_x_form)
break;
}
}
static void use_transform(struct jr3_channel __iomem *channel,
short transf_num)
{
set_s16(&channel->command_word0, 0x0500 + (transf_num & 0x000f));
}
static void use_offset(struct jr3_channel __iomem *channel, short offset_num)
{
set_s16(&channel->command_word0, 0x0600 + (offset_num & 0x000f));
}
static void set_offset(struct jr3_channel __iomem *channel)
{
set_s16(&channel->command_word0, 0x0700);
}
static void set_full_scales(struct jr3_channel __iomem *channel,
struct six_axis_t full_scale)
{
set_s16(&channel->full_scale.fx, full_scale.fx);
set_s16(&channel->full_scale.fy, full_scale.fy);
set_s16(&channel->full_scale.fz, full_scale.fz);
set_s16(&channel->full_scale.mx, full_scale.mx);
set_s16(&channel->full_scale.my, full_scale.my);
set_s16(&channel->full_scale.mz, full_scale.mz);
set_s16(&channel->command_word0, 0x0a00);
}
static struct six_axis_t get_min_full_scales(struct jr3_channel __iomem
*channel)
{
struct six_axis_t result;
result.fx = get_s16(&channel->min_full_scale.fx);
result.fy = get_s16(&channel->min_full_scale.fy);
result.fz = get_s16(&channel->min_full_scale.fz);
result.mx = get_s16(&channel->min_full_scale.mx);
result.my = get_s16(&channel->min_full_scale.my);
result.mz = get_s16(&channel->min_full_scale.mz);
return result;
}
static struct six_axis_t get_max_full_scales(struct jr3_channel __iomem
*channel)
{
struct six_axis_t result;
result.fx = get_s16(&channel->max_full_scale.fx);
result.fy = get_s16(&channel->max_full_scale.fy);
result.fz = get_s16(&channel->max_full_scale.fz);
result.mx = get_s16(&channel->max_full_scale.mx);
result.my = get_s16(&channel->max_full_scale.my);
result.mz = get_s16(&channel->max_full_scale.mz);
return result;
}
static unsigned int jr3_pci_ai_read_chan(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chan)
{
struct jr3_pci_subdev_private *spriv = s->private;
unsigned int val = 0;
if (spriv->state != state_jr3_done)
return 0;
if (chan < 56) {
unsigned int axis = chan % 8;
unsigned filter = chan / 8;
switch (axis) {
case 0:
val = get_s16(&spriv->channel->filter[filter].fx);
break;
case 1:
val = get_s16(&spriv->channel->filter[filter].fy);
break;
case 2:
val = get_s16(&spriv->channel->filter[filter].fz);
break;
case 3:
val = get_s16(&spriv->channel->filter[filter].mx);
break;
case 4:
val = get_s16(&spriv->channel->filter[filter].my);
break;
case 5:
val = get_s16(&spriv->channel->filter[filter].mz);
break;
case 6:
val = get_s16(&spriv->channel->filter[filter].v1);
break;
case 7:
val = get_s16(&spriv->channel->filter[filter].v2);
break;
}
val += 0x4000;
} else if (chan == 56) {
val = get_u16(&spriv->channel->model_no);
} else if (chan == 57) {
val = get_u16(&spriv->channel->serial_no);
}
return val;
}
static int jr3_pci_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct jr3_pci_subdev_private *spriv = s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
u16 errors;
int i;
if (!spriv)
return -EINVAL;
errors = get_u16(&spriv->channel->errors);
if (spriv->state != state_jr3_done ||
(errors & (watch_dog | watch_dog2 | sensor_change))) {
if (spriv->state == state_jr3_done) {
spriv->state = state_jr3_poll;
}
return -EAGAIN;
}
for (i = 0; i < insn->n; i++)
data[i] = jr3_pci_ai_read_chan(dev, s, chan);
return insn->n;
}
static int jr3_pci_open(struct comedi_device *dev)
{
struct jr3_pci_subdev_private *spriv;
struct comedi_subdevice *s;
int i;
dev_dbg(dev->class_dev, "jr3_pci_open\n");
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
spriv = s->private;
if (spriv)
dev_dbg(dev->class_dev, "serial: %p %d (%d)\n",
spriv, spriv->serial_no, s->index);
}
return 0;
}
static int read_idm_word(const u8 *data, size_t size, int *pos,
unsigned int *val)
{
int result = 0;
int value;
if (pos && val) {
for (; *pos < size && !isxdigit(data[*pos]); (*pos)++)
;
*val = 0;
for (; *pos < size; (*pos)++) {
value = hex_to_bin(data[*pos]);
if (value >= 0) {
result = 1;
*val = (*val << 4) + value;
} else {
break;
}
}
}
return result;
}
static int jr3_check_firmware(struct comedi_device *dev,
const u8 *data, size_t size)
{
int more = 1;
int pos = 0;
while (more) {
unsigned int count = 0;
unsigned int addr = 0;
more = more && read_idm_word(data, size, &pos, &count);
if (more && count == 0xffff)
return 0;
more = more && read_idm_word(data, size, &pos, &addr);
while (more && count > 0) {
unsigned int dummy = 0;
more = more && read_idm_word(data, size, &pos, &dummy);
count--;
}
}
return -ENODATA;
}
static void jr3_write_firmware(struct comedi_device *dev,
int subdev, const u8 *data, size_t size)
{
struct jr3_pci_dev_private *devpriv = dev->private;
struct jr3_t __iomem *iobase = devpriv->iobase;
u32 __iomem *lo;
u32 __iomem *hi;
int more = 1;
int pos = 0;
while (more) {
unsigned int count = 0;
unsigned int addr = 0;
more = more && read_idm_word(data, size, &pos, &count);
if (more && count == 0xffff)
return;
more = more && read_idm_word(data, size, &pos, &addr);
dev_dbg(dev->class_dev, "Loading#%d %4.4x bytes at %4.4x\n",
subdev, count, addr);
while (more && count > 0) {
if (addr & 0x4000) {
unsigned int data1 = 0;
more = more &&
read_idm_word(data, size, &pos, &data1);
count--;
} else {
unsigned int data1 = 0;
unsigned int data2 = 0;
lo = &iobase->channel[subdev].program_lo[addr];
hi = &iobase->channel[subdev].program_hi[addr];
more = more &&
read_idm_word(data, size, &pos, &data1);
more = more &&
read_idm_word(data, size, &pos, &data2);
count -= 2;
if (more) {
set_u16(lo, data1);
udelay(1);
set_u16(hi, data2);
udelay(1);
}
}
addr++;
}
}
}
static int jr3_download_firmware(struct comedi_device *dev,
const u8 *data, size_t size,
unsigned long context)
{
int subdev;
int ret;
ret = jr3_check_firmware(dev, data, size);
if (ret)
return ret;
for (subdev = 0; subdev < dev->n_subdevices; subdev++)
jr3_write_firmware(dev, subdev, data, size);
return 0;
}
static struct jr3_pci_poll_delay jr3_pci_poll_subdevice(struct comedi_subdevice *s)
{
struct jr3_pci_subdev_private *spriv = s->private;
struct jr3_pci_poll_delay result = poll_delay_min_max(1000, 2000);
struct jr3_channel __iomem *channel;
u16 model_no;
u16 serial_no;
int errors;
int i;
if (!spriv)
return result;
channel = spriv->channel;
errors = get_u16(&channel->errors);
if (errors != spriv->errors)
spriv->errors = errors;
if (errors & (watch_dog | watch_dog2 | sensor_change))
spriv->state = state_jr3_poll;
switch (spriv->state) {
case state_jr3_poll:
model_no = get_u16(&channel->model_no);
serial_no = get_u16(&channel->serial_no);
if ((errors & (watch_dog | watch_dog2)) ||
model_no == 0 || serial_no == 0) {
} else {
spriv->retries = 0;
spriv->state = state_jr3_init_wait_for_offset;
}
break;
case state_jr3_init_wait_for_offset:
spriv->retries++;
if (spriv->retries < 10) {
} else {
struct jr3_pci_transform transf;
spriv->model_no = get_u16(&channel->model_no);
spriv->serial_no = get_u16(&channel->serial_no);
for (i = 0; i < ARRAY_SIZE(transf.link); i++) {
transf.link[i].link_type = (enum link_types)0;
transf.link[i].link_amount = 0;
}
set_transforms(channel, transf, 0);
use_transform(channel, 0);
spriv->state = state_jr3_init_transform_complete;
result = poll_delay_min_max(20, 100);
}
break;
case state_jr3_init_transform_complete:
if (!is_complete(channel)) {
result = poll_delay_min_max(20, 100);
} else {
struct six_axis_t min_full_scale;
struct six_axis_t max_full_scale;
min_full_scale = get_min_full_scales(channel);
max_full_scale = get_max_full_scales(channel);
set_full_scales(channel, max_full_scale);
spriv->state = state_jr3_init_set_full_scale_complete;
result = poll_delay_min_max(20, 100);
}
break;
case state_jr3_init_set_full_scale_complete:
if (!is_complete(channel)) {
result = poll_delay_min_max(20, 100);
} else {
struct force_array __iomem *fs = &channel->full_scale;
spriv->range[0].range.min = -get_s16(&fs->fx) * 1000;
spriv->range[0].range.max = get_s16(&fs->fx) * 1000;
spriv->range[1].range.min = -get_s16(&fs->fy) * 1000;
spriv->range[1].range.max = get_s16(&fs->fy) * 1000;
spriv->range[2].range.min = -get_s16(&fs->fz) * 1000;
spriv->range[2].range.max = get_s16(&fs->fz) * 1000;
spriv->range[3].range.min = -get_s16(&fs->mx) * 100;
spriv->range[3].range.max = get_s16(&fs->mx) * 100;
spriv->range[4].range.min = -get_s16(&fs->my) * 100;
spriv->range[4].range.max = get_s16(&fs->my) * 100;
spriv->range[5].range.min = -get_s16(&fs->mz) * 100;
spriv->range[5].range.max = get_s16(&fs->mz) * 100;
spriv->range[6].range.min = -get_s16(&fs->v1) * 100;
spriv->range[6].range.max = get_s16(&fs->v1) * 100;
spriv->range[7].range.min = -get_s16(&fs->v2) * 100;
spriv->range[7].range.max = get_s16(&fs->v2) * 100;
spriv->range[8].range.min = 0;
spriv->range[8].range.max = 65535;
use_offset(channel, 0);
spriv->state = state_jr3_init_use_offset_complete;
result = poll_delay_min_max(40, 100);
}
break;
case state_jr3_init_use_offset_complete:
if (!is_complete(channel)) {
result = poll_delay_min_max(20, 100);
} else {
set_s16(&channel->offsets.fx, 0);
set_s16(&channel->offsets.fy, 0);
set_s16(&channel->offsets.fz, 0);
set_s16(&channel->offsets.mx, 0);
set_s16(&channel->offsets.my, 0);
set_s16(&channel->offsets.mz, 0);
set_offset(channel);
spriv->state = state_jr3_done;
}
break;
case state_jr3_done:
result = poll_delay_min_max(10000, 20000);
break;
default:
break;
}
return result;
}
static void jr3_pci_poll_dev(unsigned long data)
{
struct comedi_device *dev = (struct comedi_device *)data;
struct jr3_pci_dev_private *devpriv = dev->private;
struct jr3_pci_subdev_private *spriv;
struct comedi_subdevice *s;
unsigned long flags;
unsigned long now;
int delay;
int i;
spin_lock_irqsave(&dev->spinlock, flags);
delay = 1000;
now = jiffies;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
spriv = s->private;
if (now > spriv->next_time_min) {
struct jr3_pci_poll_delay sub_delay;
sub_delay = jr3_pci_poll_subdevice(s);
spriv->next_time_min = jiffies +
msecs_to_jiffies(sub_delay.min);
spriv->next_time_max = jiffies +
msecs_to_jiffies(sub_delay.max);
if (sub_delay.max && sub_delay.max < delay)
delay = sub_delay.max;
}
}
spin_unlock_irqrestore(&dev->spinlock, flags);
devpriv->timer.expires = jiffies + msecs_to_jiffies(delay);
add_timer(&devpriv->timer);
}
static struct jr3_pci_subdev_private *
jr3_pci_alloc_spriv(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct jr3_pci_dev_private *devpriv = dev->private;
struct jr3_pci_subdev_private *spriv;
int j;
int k;
spriv = comedi_alloc_spriv(s, sizeof(*spriv));
if (!spriv)
return NULL;
spriv->channel = &devpriv->iobase->channel[s->index].data;
for (j = 0; j < 8; j++) {
spriv->range[j].length = 1;
spriv->range[j].range.min = -1000000;
spriv->range[j].range.max = 1000000;
for (k = 0; k < 7; k++) {
spriv->range_table_list[j + k * 8] =
(struct comedi_lrange *)&spriv->range[j];
spriv->maxdata_list[j + k * 8] = 0x7fff;
}
}
spriv->range[8].length = 1;
spriv->range[8].range.min = 0;
spriv->range[8].range.max = 65536;
spriv->range_table_list[56] = (struct comedi_lrange *)&spriv->range[8];
spriv->range_table_list[57] = (struct comedi_lrange *)&spriv->range[8];
spriv->maxdata_list[56] = 0xffff;
spriv->maxdata_list[57] = 0xffff;
dev_dbg(dev->class_dev, "p->channel %p %p (%tx)\n",
spriv->channel, devpriv->iobase,
((char __iomem *)spriv->channel -
(char __iomem *)devpriv->iobase));
return spriv;
}
static int jr3_pci_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
static const struct jr3_pci_board *board = NULL;
struct jr3_pci_dev_private *devpriv;
struct jr3_pci_subdev_private *spriv;
struct comedi_subdevice *s;
int ret;
int i;
if (sizeof(struct jr3_channel) != 0xc00) {
dev_err(dev->class_dev,
"sizeof(struct jr3_channel) = %x [expected %x]\n",
(unsigned)sizeof(struct jr3_channel), 0xc00);
return -EINVAL;
}
if (context < ARRAY_SIZE(jr3_pci_boards))
board = &jr3_pci_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
init_timer(&devpriv->timer);
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->iobase = pci_ioremap_bar(pcidev, 0);
if (!devpriv->iobase)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, board->n_subdevs);
if (ret)
return ret;
dev->open = jr3_pci_open;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8 * 7 + 2;
s->insn_read = jr3_pci_ai_insn_read;
spriv = jr3_pci_alloc_spriv(dev, s);
if (spriv) {
s->range_table_list = spriv->range_table_list;
s->maxdata_list = spriv->maxdata_list;
}
}
writel(0, &devpriv->iobase->channel[0].reset);
ret = comedi_load_firmware(dev, &comedi_to_pci_dev(dev)->dev,
"comedi/jr3pci.idm",
jr3_download_firmware, 0);
dev_dbg(dev->class_dev, "Firmare load %d\n", ret);
if (ret < 0)
return ret;
msleep_interruptible(25);
for (i = 0; i < 0x18; i++) {
dev_dbg(dev->class_dev, "%c\n",
get_u16(&devpriv->iobase->channel[0].
data.copyright[i]) >> 8);
}
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
spriv = s->private;
spriv->next_time_min = jiffies + msecs_to_jiffies(500);
spriv->next_time_max = jiffies + msecs_to_jiffies(2000);
}
devpriv->timer.data = (unsigned long)dev;
devpriv->timer.function = jr3_pci_poll_dev;
devpriv->timer.expires = jiffies + msecs_to_jiffies(1000);
add_timer(&devpriv->timer);
return 0;
}
static void jr3_pci_detach(struct comedi_device *dev)
{
struct jr3_pci_dev_private *devpriv = dev->private;
if (devpriv) {
del_timer_sync(&devpriv->timer);
if (devpriv->iobase)
iounmap(devpriv->iobase);
}
comedi_pci_disable(dev);
}
static int jr3_pci_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &jr3_pci_driver, id->driver_data);
}
