static long tty_ioctl(struct file *f, unsigned op, unsigned long param)
{
if (f->f_op->unlocked_ioctl)
return f->f_op->unlocked_ioctl(f, op, param);
return -ENOSYS;
}
static int tty_write(struct file *f, unsigned char *buf, int count)
{
int result;
mm_segment_t oldfs;
oldfs = get_fs();
set_fs(KERNEL_DS);
f->f_pos = 0;
result = f->f_op->write(f, buf, count, &f->f_pos);
set_fs(oldfs);
return result;
}
static int tty_read(struct file *f, int timeout)
{
int result;
result = -1;
if (!IS_ERR(f)) {
mm_segment_t oldfs;
oldfs = get_fs();
set_fs(KERNEL_DS);
if (f->f_op->poll) {
struct poll_wqueues table;
struct timeval start, now;
do_gettimeofday(&start);
poll_initwait(&table);
while (1) {
long elapsed;
int mask;
mask = f->f_op->poll(f, &table.pt);
if (mask & (POLLRDNORM | POLLRDBAND | POLLIN |
POLLHUP | POLLERR)) {
break;
}
do_gettimeofday(&now);
elapsed =
(1000000 * (now.tv_sec - start.tv_sec) +
now.tv_usec - start.tv_usec);
if (elapsed > timeout)
break;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(((timeout -
elapsed) * HZ) / 10000);
}
poll_freewait(&table);
{
unsigned char ch;
f->f_pos = 0;
if (f->f_op->read(f, &ch, 1, &f->f_pos) == 1)
result = ch;
}
} else {
int retries = 0;
while (1) {
unsigned char ch;
retries++;
if (retries >= timeout)
break;
f->f_pos = 0;
if (f->f_op->read(f, &ch, 1, &f->f_pos) == 1) {
result = ch;
break;
}
udelay(100);
}
}
set_fs(oldfs);
}
return result;
}
static void tty_setspeed(struct file *f, int speed)
{
mm_segment_t oldfs;
oldfs = get_fs();
set_fs(KERNEL_DS);
{
struct termios settings;
tty_ioctl(f, TCGETS, (unsigned long)&settings);
settings.c_iflag = 0;
settings.c_oflag = 0;
settings.c_lflag = 0;
settings.c_cflag = CLOCAL | CS8 | CREAD;
settings.c_cc[VMIN] = 0;
settings.c_cc[VTIME] = 0;
switch (speed) {
case 2400:{
settings.c_cflag |= B2400;
}
break;
case 4800:{
settings.c_cflag |= B4800;
}
break;
case 9600:{
settings.c_cflag |= B9600;
}
break;
case 19200:{
settings.c_cflag |= B19200;
}
break;
case 38400:{
settings.c_cflag |= B38400;
}
break;
case 57600:{
settings.c_cflag |= B57600;
}
break;
case 115200:{
settings.c_cflag |= B115200;
}
break;
default:{
settings.c_cflag |= B9600;
}
break;
}
tty_ioctl(f, TCSETS, (unsigned long)&settings);
}
{
struct serial_struct settings;
tty_ioctl(f, TIOCGSERIAL, (unsigned long)&settings);
settings.flags |= ASYNC_LOW_LATENCY;
tty_ioctl(f, TIOCSSERIAL, (unsigned long)&settings);
}
set_fs(oldfs);
}
static void poll_digital(struct file *f, int channel)
{
char cmd;
cmd = 0x40 | (channel & 0x1f);
tty_write(f, &cmd, 1);
}
static void poll_channel(struct file *f, int channel)
{
char cmd;
cmd = 0x60 | (channel & 0x1f);
tty_write(f, &cmd, 1);
}
static struct serial_data serial_read(struct file *f, int timeout)
{
struct serial_data result;
int length;
result.kind = is_invalid;
result.index = 0;
result.value = 0;
length = 0;
while (1) {
int data = tty_read(f, timeout);
length++;
if (data < 0) {
printk(KERN_ERR "serial2002 error\n");
break;
} else if (data & 0x80) {
result.value = (result.value << 7) | (data & 0x7f);
} else {
if (length == 1) {
switch ((data >> 5) & 0x03) {
case 0:{
result.value = 0;
result.kind = is_digital;
}
break;
case 1:{
result.value = 1;
result.kind = is_digital;
}
break;
}
} else {
result.value =
(result.value << 2) | ((data & 0x60) >> 5);
result.kind = is_channel;
}
result.index = data & 0x1f;
break;
}
}
return result;
}
static void serial_write(struct file *f, struct serial_data data)
{
if (data.kind == is_digital) {
unsigned char ch =
((data.value << 5) & 0x20) | (data.index & 0x1f);
tty_write(f, &ch, 1);
} else {
unsigned char ch[6];
int i = 0;
if (data.value >= (1L << 30)) {
ch[i] = 0x80 | ((data.value >> 30) & 0x03);
i++;
}
if (data.value >= (1L << 23)) {
ch[i] = 0x80 | ((data.value >> 23) & 0x7f);
i++;
}
if (data.value >= (1L << 16)) {
ch[i] = 0x80 | ((data.value >> 16) & 0x7f);
i++;
}
if (data.value >= (1L << 9)) {
ch[i] = 0x80 | ((data.value >> 9) & 0x7f);
i++;
}
ch[i] = 0x80 | ((data.value >> 2) & 0x7f);
i++;
ch[i] = ((data.value << 5) & 0x60) | (data.index & 0x1f);
i++;
tty_write(f, ch, i);
}
}
static int serial_2002_open(struct comedi_device *dev)
{
int result;
char port[20];
sprintf(port, "/dev/ttyS%d", devpriv->port);
devpriv->tty = filp_open(port, O_RDWR, 0);
if (IS_ERR(devpriv->tty)) {
result = (int)PTR_ERR(devpriv->tty);
printk(KERN_ERR "serial_2002: file open error = %d\n", result);
} else {
struct config_t {
short int kind;
short int bits;
int min;
int max;
};
struct config_t *dig_in_config;
struct config_t *dig_out_config;
struct config_t *chan_in_config;
struct config_t *chan_out_config;
int i;
result = 0;
dig_in_config = kcalloc(32, sizeof(struct config_t),
GFP_KERNEL);
dig_out_config = kcalloc(32, sizeof(struct config_t),
GFP_KERNEL);
chan_in_config = kcalloc(32, sizeof(struct config_t),
GFP_KERNEL);
chan_out_config = kcalloc(32, sizeof(struct config_t),
GFP_KERNEL);
if (!dig_in_config || !dig_out_config
|| !chan_in_config || !chan_out_config) {
result = -ENOMEM;
goto err_alloc_configs;
}
tty_setspeed(devpriv->tty, devpriv->speed);
poll_channel(devpriv->tty, 31);
while (1) {
struct serial_data data;
data = serial_read(devpriv->tty, 1000);
if (data.kind != is_channel || data.index != 31
|| !(data.value & 0xe0)) {
break;
} else {
int command, channel, kind;
struct config_t *cur_config = NULL;
channel = data.value & 0x1f;
kind = (data.value >> 5) & 0x7;
command = (data.value >> 8) & 0x3;
switch (kind) {
case 1:{
cur_config = dig_in_config;
}
break;
case 2:{
cur_config = dig_out_config;
}
break;
case 3:{
cur_config = chan_in_config;
}
break;
case 4:{
cur_config = chan_out_config;
}
break;
case 5:{
cur_config = chan_in_config;
}
break;
}
if (cur_config) {
cur_config[channel].kind = kind;
switch (command) {
case 0:{
cur_config[channel].bits
=
(data.value >> 10) &
0x3f;
}
break;
case 1:{
int unit, sign, min;
unit =
(data.value >> 10) &
0x7;
sign =
(data.value >> 13) &
0x1;
min =
(data.value >> 14) &
0xfffff;
switch (unit) {
case 0:{
min =
min
*
1000000;
}
break;
case 1:{
min =
min
*
1000;
}
break;
case 2:{
min =
min
* 1;
}
break;
}
if (sign)
min = -min;
cur_config[channel].min
= min;
}
break;
case 2:{
int unit, sign, max;
unit =
(data.value >> 10) &
0x7;
sign =
(data.value >> 13) &
0x1;
max =
(data.value >> 14) &
0xfffff;
switch (unit) {
case 0:{
max =
max
*
1000000;
}
break;
case 1:{
max =
max
*
1000;
}
break;
case 2:{
max =
max
* 1;
}
break;
}
if (sign)
max = -max;
cur_config[channel].max
= max;
}
break;
}
}
}
}
for (i = 0; i <= 4; i++) {
struct config_t *c;
unsigned char *mapping = NULL;
struct serial2002_range_table_t *range = NULL;
int kind = 0;
switch (i) {
case 0:{
c = dig_in_config;
mapping = devpriv->digital_in_mapping;
kind = 1;
}
break;
case 1:{
c = dig_out_config;
mapping = devpriv->digital_out_mapping;
kind = 2;
}
break;
case 2:{
c = chan_in_config;
mapping = devpriv->analog_in_mapping;
range = devpriv->in_range;
kind = 3;
}
break;
case 3:{
c = chan_out_config;
mapping = devpriv->analog_out_mapping;
range = devpriv->out_range;
kind = 4;
}
break;
case 4:{
c = chan_in_config;
mapping = devpriv->encoder_in_mapping;
range = devpriv->in_range;
kind = 5;
}
break;
default:{
c = NULL;
}
break;
}
if (c) {
struct comedi_subdevice *s;
const struct comedi_lrange **range_table_list =
NULL;
unsigned int *maxdata_list;
int j, chan;
for (chan = 0, j = 0; j < 32; j++) {
if (c[j].kind == kind)
chan++;
}
s = &dev->subdevices[i];
s->n_chan = chan;
s->maxdata = 0;
kfree(s->maxdata_list);
s->maxdata_list = maxdata_list =
kmalloc(sizeof(unsigned int) * s->n_chan,
GFP_KERNEL);
if (!s->maxdata_list)
break;
kfree(s->range_table_list);
s->range_table = NULL;
s->range_table_list = NULL;
if (range) {
s->range_table_list = range_table_list =
kmalloc(sizeof
(struct
serial2002_range_table_t) *
s->n_chan, GFP_KERNEL);
if (!s->range_table_list)
break;
}
for (chan = 0, j = 0; j < 32; j++) {
if (c[j].kind == kind) {
if (mapping)
mapping[chan] = j;
if (range) {
range[j].length = 1;
range[j].range.min =
c[j].min;
range[j].range.max =
c[j].max;
range_table_list[chan] =
(const struct
comedi_lrange *)
&range[j];
}
maxdata_list[chan] =
((long long)1 << c[j].bits)
- 1;
chan++;
}
}
}
}
if (i <= 4) {
result = -ENOMEM;
for (i = 0; i <= 4; i++) {
struct comedi_subdevice *s;
s = &dev->subdevices[i];
kfree(s->maxdata_list);
s->maxdata_list = NULL;
kfree(s->range_table_list);
s->range_table_list = NULL;
}
}
err_alloc_configs:
kfree(dig_in_config);
kfree(dig_out_config);
kfree(chan_in_config);
kfree(chan_out_config);
if (result) {
if (devpriv->tty) {
filp_close(devpriv->tty, NULL);
devpriv->tty = NULL;
}
}
}
return result;
}
static void serial_2002_close(struct comedi_device *dev)
{
if (!IS_ERR(devpriv->tty) && devpriv->tty)
filp_close(devpriv->tty, NULL);
}
static int serial2002_di_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan;
chan = devpriv->digital_in_mapping[CR_CHAN(insn->chanspec)];
for (n = 0; n < insn->n; n++) {
struct serial_data read;
poll_digital(devpriv->tty, chan);
while (1) {
read = serial_read(devpriv->tty, 1000);
if (read.kind != is_digital || read.index == chan)
break;
}
data[n] = read.value;
}
return n;
}
static int serial2002_do_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan;
chan = devpriv->digital_out_mapping[CR_CHAN(insn->chanspec)];
for (n = 0; n < insn->n; n++) {
struct serial_data write;
write.kind = is_digital;
write.index = chan;
write.value = data[n];
serial_write(devpriv->tty, write);
}
return n;
}
static int serial2002_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan;
chan = devpriv->analog_in_mapping[CR_CHAN(insn->chanspec)];
for (n = 0; n < insn->n; n++) {
struct serial_data read;
poll_channel(devpriv->tty, chan);
while (1) {
read = serial_read(devpriv->tty, 1000);
if (read.kind != is_channel || read.index == chan)
break;
}
data[n] = read.value;
}
return n;
}
static int serial2002_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan;
chan = devpriv->analog_out_mapping[CR_CHAN(insn->chanspec)];
for (n = 0; n < insn->n; n++) {
struct serial_data write;
write.kind = is_channel;
write.index = chan;
write.value = data[n];
serial_write(devpriv->tty, write);
devpriv->ao_readback[chan] = data[n];
}
return n;
}
static int serial2002_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_readback[chan];
return n;
}
static int serial2002_ei_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan;
chan = devpriv->encoder_in_mapping[CR_CHAN(insn->chanspec)];
for (n = 0; n < insn->n; n++) {
struct serial_data read;
poll_channel(devpriv->tty, chan);
while (1) {
read = serial_read(devpriv->tty, 1000);
if (read.kind != is_channel || read.index == chan)
break;
}
data[n] = read.value;
}
return n;
}
static int serial2002_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct serial2002_board *board = comedi_board(dev);
struct comedi_subdevice *s;
int ret;
dev_dbg(dev->class_dev, "serial2002: attach\n");
dev->board_name = board->name;
if (alloc_private(dev, sizeof(struct serial2002_private)) < 0)
return -ENOMEM;
dev->open = serial_2002_open;
dev->close = serial_2002_close;
devpriv->port = it->options[0];
devpriv->speed = it->options[1];
dev_dbg(dev->class_dev, "/dev/ttyS%d @ %d\n", devpriv->port,
devpriv->speed);
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_read = &serial2002_di_rinsn;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_write = &serial2002_do_winsn;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = NULL;
s->insn_read = &serial2002_ai_rinsn;
s = dev->subdevices + 3;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = NULL;
s->insn_write = &serial2002_ao_winsn;
s->insn_read = &serial2002_ao_rinsn;
s = dev->subdevices + 4;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_LSAMPL;
s->n_chan = 0;
s->maxdata = 1;
s->range_table = NULL;
s->insn_read = &serial2002_ei_rinsn;
return 1;
}
static void serial2002_detach(struct comedi_device *dev)
{
struct comedi_subdevice *s;
int i;
for (i = 0; i < 5; i++) {
s = &dev->subdevices[i];
kfree(s->maxdata_list);
kfree(s->range_table_list);
}
}
