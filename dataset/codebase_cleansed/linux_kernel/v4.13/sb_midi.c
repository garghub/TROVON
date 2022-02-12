static int sb_midi_open(int dev, int mode,
void (*input) (int dev, unsigned char data),
void (*output) (int dev)
)
{
sb_devc *devc = midi_devs[dev]->devc;
unsigned long flags;
if (devc == NULL)
return -ENXIO;
spin_lock_irqsave(&devc->lock, flags);
if (devc->opened)
{
spin_unlock_irqrestore(&devc->lock, flags);
return -EBUSY;
}
devc->opened = 1;
spin_unlock_irqrestore(&devc->lock, flags);
devc->irq_mode = IMODE_MIDI;
devc->midi_broken = 0;
sb_dsp_reset(devc);
if (!sb_dsp_command(devc, 0x35))
{
devc->opened = 0;
return -EIO;
}
devc->intr_active = 1;
if (mode & OPEN_READ)
{
devc->input_opened = 1;
devc->midi_input_intr = input;
}
return 0;
}
static void sb_midi_close(int dev)
{
sb_devc *devc = midi_devs[dev]->devc;
unsigned long flags;
if (devc == NULL)
return;
spin_lock_irqsave(&devc->lock, flags);
sb_dsp_reset(devc);
devc->intr_active = 0;
devc->input_opened = 0;
devc->opened = 0;
spin_unlock_irqrestore(&devc->lock, flags);
}
static int sb_midi_out(int dev, unsigned char midi_byte)
{
sb_devc *devc = midi_devs[dev]->devc;
if (devc == NULL)
return 1;
if (devc->midi_broken)
return 1;
if (!sb_dsp_command(devc, midi_byte))
{
devc->midi_broken = 1;
return 1;
}
return 1;
}
static int sb_midi_start_read(int dev)
{
return 0;
}
static int sb_midi_end_read(int dev)
{
sb_devc *devc = midi_devs[dev]->devc;
if (devc == NULL)
return -ENXIO;
sb_dsp_reset(devc);
devc->intr_active = 0;
return 0;
}
static int sb_midi_ioctl(int dev, unsigned cmd, void __user *arg)
{
return -EINVAL;
}
void sb_midi_interrupt(sb_devc * devc)
{
unsigned long flags;
unsigned char data;
if (devc == NULL)
return;
spin_lock_irqsave(&devc->lock, flags);
data = inb(DSP_READ);
if (devc->input_opened)
devc->midi_input_intr(devc->my_mididev, data);
spin_unlock_irqrestore(&devc->lock, flags);
}
void sb_dsp_midi_init(sb_devc * devc, struct module *owner)
{
int dev;
if (devc->model < 2)
return;
dev = sound_alloc_mididev();
if (dev == -1)
{
printk(KERN_ERR "sb_midi: too many MIDI devices detected\n");
return;
}
std_midi_synth.midi_dev = devc->my_mididev = dev;
midi_devs[dev] = kmalloc(sizeof(struct midi_operations), GFP_KERNEL);
if (midi_devs[dev] == NULL)
{
printk(KERN_WARNING "Sound Blaster: failed to allocate MIDI memory.\n");
sound_unload_mididev(dev);
return;
}
memcpy((char *) midi_devs[dev], (char *) &sb_midi_operations,
sizeof(struct midi_operations));
if (owner)
midi_devs[dev]->owner = owner;
midi_devs[dev]->devc = devc;
midi_devs[dev]->converter = kmalloc(sizeof(struct synth_operations), GFP_KERNEL);
if (midi_devs[dev]->converter == NULL)
{
printk(KERN_WARNING "Sound Blaster: failed to allocate MIDI memory.\n");
kfree(midi_devs[dev]);
sound_unload_mididev(dev);
return;
}
memcpy((char *) midi_devs[dev]->converter, (char *) &std_midi_synth,
sizeof(struct synth_operations));
midi_devs[dev]->converter->id = "SBMIDI";
sequencer_init();
}
