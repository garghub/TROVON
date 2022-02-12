static int pas_midi_open(int dev, int mode,
void (*input) (int dev, unsigned char data),
void (*output) (int dev)
)
{
int err;
unsigned long flags;
unsigned char ctrl;
if (midi_busy)
return -EBUSY;
pas_write(0x20 | 0x40,
0x178b);
spin_lock_irqsave(&pas_lock, flags);
if ((err = pas_set_intr(0x10)) < 0)
{
spin_unlock_irqrestore(&pas_lock, flags);
return err;
}
ctrl = 0;
input_opened = 0;
midi_input_intr = input;
if (mode == OPEN_READ || mode == OPEN_READWRITE)
{
ctrl |= 0x04;
input_opened = 1;
}
if (mode == OPEN_WRITE || mode == OPEN_READWRITE)
{
ctrl |= 0x08 | 0x10;
}
pas_write(ctrl, 0x178b);
pas_write(0xff, 0x1B88);
spin_unlock_irqrestore(&pas_lock, flags);
midi_busy = 1;
qlen = qhead = qtail = 0;
return 0;
}
static void pas_midi_close(int dev)
{
pas_write(0x20 | 0x40, 0x178b);
pas_remove_intr(0x10);
midi_busy = 0;
}
static int dump_to_midi(unsigned char midi_byte)
{
int fifo_space, x;
fifo_space = ((x = pas_read(0x1B89)) >> 4) & 0x0f;
if (fifo_space < 2 && fifo_space != 0)
return 0;
pas_write(midi_byte, 0x178A);
return 1;
}
static int pas_midi_out(int dev, unsigned char midi_byte)
{
unsigned long flags;
spin_lock_irqsave(&pas_lock, flags);
while (qlen && dump_to_midi(tmp_queue[qhead]))
{
qlen--;
qhead++;
}
spin_unlock_irqrestore(&pas_lock, flags);
if (!qlen)
if (dump_to_midi(midi_byte))
return 1;
if (qlen >= 256)
return 0;
spin_lock_irqsave(&pas_lock, flags);
tmp_queue[qtail] = midi_byte;
qlen++;
qtail++;
spin_unlock_irqrestore(&pas_lock, flags);
return 1;
}
static int pas_midi_start_read(int dev)
{
return 0;
}
static int pas_midi_end_read(int dev)
{
return 0;
}
static void pas_midi_kick(int dev)
{
}
static int pas_buffer_status(int dev)
{
return qlen;
}
void __init pas_midi_init(void)
{
int dev = sound_alloc_mididev();
if (dev == -1)
{
printk(KERN_WARNING "pas_midi_init: Too many midi devices detected\n");
return;
}
std_midi_synth.midi_dev = my_dev = dev;
midi_devs[dev] = &pas_midi_operations;
pas2_mididev = dev;
sequencer_init();
}
void pas_midi_interrupt(void)
{
unsigned char stat;
int i, incount;
stat = pas_read(0x1B88);
if (stat & 0x04)
{
incount = pas_read(0x1B89) & 0x0f;
if (!incount)
incount = 16;
for (i = 0; i < incount; i++)
if (input_opened)
{
midi_input_intr(my_dev, pas_read(0x178A));
} else
pas_read(0x178A);
}
if (stat & (0x08 | 0x10))
{
spin_lock(&pas_lock);
while (qlen && dump_to_midi(tmp_queue[qhead]))
{
qlen--;
qhead++;
}
spin_unlock(&pas_lock);
}
if (stat & 0x40)
{
printk(KERN_WARNING "MIDI output overrun %x,%x\n", pas_read(0x1B89), stat);
}
pas_write(stat, 0x1B88);
}
