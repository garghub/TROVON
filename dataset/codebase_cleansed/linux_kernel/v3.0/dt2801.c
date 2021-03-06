static int __init driver_dt2801_init_module(void)
{
return comedi_driver_register(&driver_dt2801);
}
static void __exit driver_dt2801_cleanup_module(void)
{
comedi_driver_unregister(&driver_dt2801);
}
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
int lb, hb;
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
#if 0
if (stat & DT_S_READY) {
printk
("dt2801: ready flag set (bad!) in dt2801_writedata()\n");
return -EIO;
}
#endif
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
printk
("dt2801: composite-error in dt2801_writecmd(), ignoring\n");
}
if (!(stat & DT_S_READY))
printk("dt2801: !ready in dt2801_writecmd(), ignoring\n");
outb_p(command, dev->iobase + DT2801_CMD);
return 0;
}
static int dt2801_reset(struct comedi_device *dev)
{
int board_code = 0;
unsigned int stat;
int timeout;
DPRINTK("dt2801: resetting board...\n");
DPRINTK("fingerprint: 0x%02x 0x%02x\n", inb_p(dev->iobase),
inb_p(dev->iobase + 1));
inb_p(dev->iobase + DT2801_DATA);
inb_p(dev->iobase + DT2801_DATA);
inb_p(dev->iobase + DT2801_DATA);
inb_p(dev->iobase + DT2801_DATA);
DPRINTK("dt2801: stop\n");
outb_p(DT_C_STOP, dev->iobase + DT2801_CMD);
udelay(100);
timeout = 10000;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_READY)
break;
} while (timeout--);
if (!timeout)
printk("dt2801: timeout 1 status=0x%02x\n", stat);
DPRINTK("dt2801: reset\n");
outb_p(DT_C_RESET, dev->iobase + DT2801_CMD);
udelay(100);
timeout = 10000;
do {
stat = inb_p(dev->iobase + DT2801_STATUS);
if (stat & DT_S_READY)
break;
} while (timeout--);
if (!timeout)
printk("dt2801: timeout 2 status=0x%02x\n", stat);
DPRINTK("dt2801: reading code\n");
dt2801_readdata(dev, &board_code);
DPRINTK("dt2801: ok. code=0x%02x\n", board_code);
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
static int dt2801_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase;
int board_code, type;
int ret = 0;
int n_ai_chans;
iobase = it->options[0];
if (!request_region(iobase, DT2801_IOSIZE, "dt2801")) {
comedi_error(dev, "I/O port conflict");
return -EIO;
}
dev->iobase = iobase;
board_code = dt2801_reset(dev);
if (!board_code)
board_code = dt2801_reset(dev);
for (type = 0; type < ARRAY_SIZE(boardtypes); type++) {
if (boardtypes[type].boardcode == board_code)
goto havetype;
}
printk("dt2801: unrecognized board code=0x%02x, contact author\n",
board_code);
type = 0;
havetype:
dev->board_ptr = boardtypes + type;
printk("dt2801: %s at port 0x%lx", boardtype.name, iobase);
n_ai_chans = probe_number_of_ai_chans(dev);
printk(" (ai channels = %d)", n_ai_chans);
ret = alloc_subdevices(dev, 4);
if (ret < 0)
goto out;
ret = alloc_private(dev, sizeof(struct dt2801_private));
if (ret < 0)
goto out;
dev->board_name = boardtype.name;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
#if 1
s->n_chan = n_ai_chans;
#else
if (it->options[2])
s->n_chan = boardtype.ad_chan;
else
s->n_chan = boardtype.ad_chan / 2;
#endif
s->maxdata = (1 << boardtype.adbits) - 1;
s->range_table = ai_range_lkup(boardtype.adrangetype, it->options[3]);
s->insn_read = dt2801_ai_insn_read;
s++;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = (1 << boardtype.dabits) - 1;
s->range_table_list = devpriv->dac_range_types;
devpriv->dac_range_types[0] = dac_range_lkup(it->options[4]);
devpriv->dac_range_types[1] = dac_range_lkup(it->options[5]);
s->insn_read = dt2801_ao_insn_read;
s->insn_write = dt2801_ao_insn_write;
s++;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt2801_dio_insn_bits;
s->insn_config = dt2801_dio_insn_config;
s++;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt2801_dio_insn_bits;
s->insn_config = dt2801_dio_insn_config;
ret = 0;
out:
printk("\n");
return ret;
}
static int dt2801_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, DT2801_IOSIZE);
return 0;
}
static int dt2801_error(struct comedi_device *dev, int stat)
{
if (stat < 0) {
if (stat == -ETIME)
printk("dt2801: timeout\n");
else
printk("dt2801: error %d\n", stat);
return stat;
}
printk("dt2801: error status 0x%02x, resetting...\n", stat);
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
data[0] = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
return 1;
}
static int dt2801_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
dt2801_writecmd(dev, DT_C_WRITE_DAIM);
dt2801_writedata(dev, CR_CHAN(insn->chanspec));
dt2801_writedata2(dev, data[0]);
devpriv->ao_readback[CR_CHAN(insn->chanspec)] = data[0];
return 1;
}
static int dt2801_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int which = 0;
if (s == dev->subdevices + 4)
which = 1;
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
dt2801_writecmd(dev, DT_C_WRITE_DIG);
dt2801_writedata(dev, which);
dt2801_writedata(dev, s->state);
}
dt2801_writecmd(dev, DT_C_READ_DIG);
dt2801_writedata(dev, which);
dt2801_readdata(dev, data + 1);
return 2;
}
static int dt2801_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int which = 0;
if (s == dev->subdevices + 4)
which = 1;
if (data[0]) {
s->io_bits = 0xff;
dt2801_writecmd(dev, DT_C_SET_DIGOUT);
} else {
s->io_bits = 0;
dt2801_writecmd(dev, DT_C_SET_DIGIN);
}
dt2801_writedata(dev, which);
return 1;
}
