static int dt2801_readdata(struct comedi_device *dev, int *data)
{
int stat = 0;
int timeout = DT2801_TIMEOUT;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & (DT_S_COMPOSITE_ERROR | DT_S_READY))
return stat;
if (stat & DT_S_DATA_OUT_READY) {
*data = inb_p(dev->iobase + DT2801_DATA);
return 0;
}
} while (--timeout > 0);
return -ETIME;
}
static int dt2801_readdata2(struct comedi_device *dev, int *data)
{
int lb = 0;
int hb = 0;
int ret;
ret = dt2801_readdata(dev, &lb);
if (ret)
return ret;
ret = dt2801_readdata(dev, &hb);
if (ret)
return ret;
*data = (hb << 8) + lb;
return 0;
}
static int dt2801_writedata(struct comedi_device *dev, unsigned int data)
{
int stat = 0;
int timeout = DT2801_TIMEOUT;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_COMPOSITE_ERROR)
return stat;
if (!(stat & DT_S_DATA_IN_FULL)) {
outb_p(data & 0xff, dev->iobase + DT2801_DATA);
return 0;
}
} while (--timeout > 0);
return -ETIME;
}
static int dt2801_writedata2(struct comedi_device *dev, unsigned int data)
{
int ret;
ret = dt2801_writedata(dev, data & 0xff);
if (ret < 0)
return ret;
ret = dt2801_writedata(dev, (data >> 8));
if (ret < 0)
return ret;
return 0;
}
static int dt2801_wait_for_ready(struct comedi_device *dev)
{
int timeout = DT2801_TIMEOUT;
int stat;
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_READY)
return 0;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_COMPOSITE_ERROR)
return stat;
if (stat & DT_S_READY)
return 0;
} while (--timeout > 0);
return -ETIME;
}
static int dt2801_writecmd(struct comedi_device *dev, int command)
{
int stat;
dt2801_wait_for_ready(dev);
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_COMPOSITE_ERROR) {
dev_dbg(dev->class_dev,
"composite-error in %s, ignoring\n", __func__);
}
if (!(stat & DT_S_READY))
dev_dbg(dev->class_dev, "!ready in %s, ignoring\n", __func__);
outb_p(command, dev->iobase + DT2801_CMD);
return 0;
}
static int dt2801_reset(struct comedi_device *dev)
{
int board_code = 0;
unsigned int stat;
int timeout;
inb_p(dev->iobase + DT2801_DATA);
inb_p(dev->iobase + DT2801_DATA);
inb_p(dev->iobase + DT2801_DATA);
inb_p(dev->iobase + DT2801_DATA);
outb_p(DT_C_STOP, dev->iobase + DT2801_CMD);
udelay(100);
timeout = 10000;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_READY)
break;
} while (timeout--);
if (!timeout)
dev_dbg(dev->class_dev, "timeout 1 status=0x%02x\n", stat);
outb_p(DT_C_RESET, dev->iobase + DT2801_CMD);
udelay(100);
timeout = 10000;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_READY)
break;
} while (timeout--);
if (!timeout)
dev_dbg(dev->class_dev, "timeout 2 status=0x%02x\n", stat);
dt2801_readdata(dev, &board_code);
return board_code;
}
static int probe_number_of_ai_chans(struct comedi_device *dev)
{
int n_chans;
int stat;
int data;
for (n_chans = 0; n_chans < 16; n_chans++) {
stat = dt2801_writecmd(dev, DT_C_READ_ADIM);
dt2801_writedata(dev, 0);
dt2801_writedata(dev, n_chans);
stat = dt2801_readdata2(dev, &data);
if (stat)
break;
}
dt2801_reset(dev);
dt2801_reset(dev);
return n_chans;
}
static const struct comedi_lrange *dac_range_lkup(int opt)
{
if (opt < 0 || opt >= 5)
return &range_unknown;
return dac_range_table[opt];
}
static const struct comedi_lrange *ai_range_lkup(int type, int opt)
{
switch (type) {
case 0:
return (opt) ?
&range_dt2801_ai_pgl_unipolar :
&range_dt2801_ai_pgl_bipolar;
case 1:
return (opt) ? &range_unipolar10 : &range_bipolar10;
case 2:
return &range_unipolar5;
}
return &range_unknown;
}
static int dt2801_error(struct comedi_device *dev, int stat)
{
if (stat < 0) {
if (stat == -ETIME)
dev_dbg(dev->class_dev, "timeout\n");
else
dev_dbg(dev->class_dev, "error %d\n", stat);
return stat;
}
dev_dbg(dev->class_dev, "error status 0x%02x, resetting...\n", stat);
dt2801_reset(dev);
dt2801_reset(dev);
return -EIO;
}
static int dt2801_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int d;
int stat;
int i;
for (i = 0; i < insn->n; i++) {
stat = dt2801_writecmd(dev, DT_C_READ_ADIM);
dt2801_writedata(dev, CR_RANGE(insn->chanspec));
dt2801_writedata(dev, CR_CHAN(insn->chanspec));
stat = dt2801_readdata2(dev, &d);
if (stat != 0)
return dt2801_error(dev, stat);
data[i] = d;
}
return i;
}
static int dt2801_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt2801_private *devpriv = dev->private;
data[0] = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
return 1;
}
static int dt2801_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt2801_private *devpriv = dev->private;
dt2801_writecmd(dev, DT_C_WRITE_DAIM);
dt2801_writedata(dev, CR_CHAN(insn->chanspec));
dt2801_writedata2(dev, data[0]);
devpriv->ao_readback[CR_CHAN(insn->chanspec)] = data[0];
return 1;
}
static int dt2801_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int which = (s == &dev->subdevices[3]) ? 1 : 0;
unsigned int val = 0;
if (comedi_dio_update_state(s, data)) {
dt2801_writecmd(dev, DT_C_WRITE_DIG);
dt2801_writedata(dev, which);
dt2801_writedata(dev, s->state);
}
dt2801_writecmd(dev, DT_C_READ_DIG);
dt2801_writedata(dev, which);
dt2801_readdata(dev, &val);
data[1] = val;
return insn->n;
}
static int dt2801_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0xff);
if (ret)
return ret;
dt2801_writecmd(dev, s->io_bits ? DT_C_SET_DIGOUT : DT_C_SET_DIGIN);
dt2801_writedata(dev, (s == &dev->subdevices[3]) ? 1 : 0);
return insn->n;
}
static int dt2801_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct dt2801_board *board = comedi_board(dev);
struct dt2801_private *devpriv;
struct comedi_subdevice *s;
int board_code, type;
int ret = 0;
int n_ai_chans;
ret = comedi_request_region(dev, it->options[0], DT2801_IOSIZE);
if (ret)
return ret;
board_code = dt2801_reset(dev);
if (!board_code)
board_code = dt2801_reset(dev);
for (type = 0; type < ARRAY_SIZE(boardtypes); type++) {
if (boardtypes[type].boardcode == board_code)
goto havetype;
}
dev_dbg(dev->class_dev,
"unrecognized board code=0x%02x, contact author\n", board_code);
type = 0;
havetype:
dev->board_ptr = boardtypes + type;
board = comedi_board(dev);
n_ai_chans = probe_number_of_ai_chans(dev);
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
goto out;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
dev->board_name = board->name;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
#if 1
s->n_chan = n_ai_chans;
#else
if (it->options[2])
s->n_chan = board->ad_chan;
else
s->n_chan = board->ad_chan / 2;
#endif
s->maxdata = (1 << board->adbits) - 1;
s->range_table = ai_range_lkup(board->adrangetype, it->options[3]);
s->insn_read = dt2801_ai_insn_read;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = (1 << board->dabits) - 1;
s->range_table_list = devpriv->dac_range_types;
devpriv->dac_range_types[0] = dac_range_lkup(it->options[4]);
devpriv->dac_range_types[1] = dac_range_lkup(it->options[5]);
s->insn_read = dt2801_ao_insn_read;
s->insn_write = dt2801_ao_insn_write;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt2801_dio_insn_bits;
s->insn_config = dt2801_dio_insn_config;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt2801_dio_insn_bits;
s->insn_config = dt2801_dio_insn_config;
ret = 0;
out:
return ret;
}
