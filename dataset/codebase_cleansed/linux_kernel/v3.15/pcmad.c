static int pcmad_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + PCMAD_STATUS);
if ((status & 0x3) == 0x3)
return 0;
return -EBUSY;
}
static int pcmad_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int ret;
int i;
for (i = 0; i < insn->n; i++) {
outb(chan, dev->iobase + PCMAD_CONVERT);
ret = comedi_timeout(dev, s, insn, pcmad_ai_eoc, 0);
if (ret)
return ret;
val = inb(dev->iobase + PCMAD_LSB) |
(inb(dev->iobase + PCMAD_MSB) << 8);
if (s->maxdata == 0x0fff)
val >>= 4;
if (comedi_range_is_bipolar(s, range)) {
val ^= ((s->maxdata + 1) >> 1);
}
data[i] = val;
}
return insn->n;
}
static int pcmad_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcmad_board_struct *board = comedi_board(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x04);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
if (it->options[1]) {
s->subdev_flags = SDF_READABLE | AREF_DIFF;
s->n_chan = 8;
} else {
s->subdev_flags = SDF_READABLE | AREF_GROUND;
s->n_chan = 16;
}
s->len_chanlist = 1;
s->maxdata = board->ai_maxdata;
s->range_table = it->options[2] ? &range_bipolar10 : &range_unipolar5;
s->insn_read = pcmad_ai_insn_read;
return 0;
}
