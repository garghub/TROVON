unsigned char pas_read(int ioaddr)
{
return inb(ioaddr + pas_translate_code);
}
void pas_write(unsigned char data, int ioaddr)
{
outb((data), ioaddr + pas_translate_code);
}
static irqreturn_t pasintr(int irq, void *dev_id)
{
int status;
status = pas_read(0x0B89);
pas_write(status, 0x0B89);
if (status & 0x08)
{
pas_pcm_interrupt(status, 1);
status &= ~0x08;
}
if (status & 0x10)
{
pas_midi_interrupt();
status &= ~0x10;
}
return IRQ_HANDLED;
}
int pas_set_intr(int mask)
{
if (!mask)
return 0;
pas_intr_mask |= mask;
pas_write(pas_intr_mask, 0x0B8B);
return 0;
}
int pas_remove_intr(int mask)
{
if (!mask)
return 0;
pas_intr_mask &= ~mask;
pas_write(pas_intr_mask, 0x0B8B);
return 0;
}
static int __init config_pas_hw(struct address_info *hw_config)
{
char ok = 1;
unsigned int_ptrs;
pas_irq = hw_config->irq;
pas_write(0x00, 0x0B8B);
pas_write(0x36, 0x138B);
pas_write(0x36, 0x1388);
pas_write(0, 0x1388);
pas_write(0x74, 0x138B);
pas_write(0x74, 0x1389);
pas_write(0, 0x1389);
pas_write(0x80 | 0x40 | 0x20 | 1, 0x0B8A);
pas_write(0x80 | 0x20 | 0x10 | 0x08 | 0x01, 0xF8A);
pas_write(0x01 | 0x02 | 0x04 | 0x10 , 0xB88);
pas_write(0x80 | (joystick ? 0x40 : 0), 0xF388);
if (pas_irq < 0 || pas_irq > 15)
{
printk(KERN_ERR "PAS16: Invalid IRQ %d", pas_irq);
hw_config->irq=-1;
ok = 0;
}
else
{
int_ptrs = pas_read(0xF38A);
int_ptrs = (int_ptrs & 0xf0) | irq_bits[pas_irq];
pas_write(int_ptrs, 0xF38A);
if (!irq_bits[pas_irq])
{
printk(KERN_ERR "PAS16: Invalid IRQ %d", pas_irq);
hw_config->irq=-1;
ok = 0;
}
else
{
if (request_irq(pas_irq, pasintr, 0, "PAS16",hw_config) < 0) {
printk(KERN_ERR "PAS16: Cannot allocate IRQ %d\n",pas_irq);
hw_config->irq=-1;
ok = 0;
}
}
}
if (hw_config->dma < 0 || hw_config->dma > 7)
{
printk(KERN_ERR "PAS16: Invalid DMA selection %d", hw_config->dma);
hw_config->dma=-1;
ok = 0;
}
else
{
pas_write(dma_bits[hw_config->dma], 0xF389);
if (!dma_bits[hw_config->dma])
{
printk(KERN_ERR "PAS16: Invalid DMA selection %d", hw_config->dma);
hw_config->dma=-1;
ok = 0;
}
else
{
if (sound_alloc_dma(hw_config->dma, "PAS16"))
{
printk(KERN_ERR "pas2_card.c: Can't allocate DMA channel\n");
hw_config->dma=-1;
ok = 0;
}
}
}
if(symphony)
{
outb((0x05), 0xa8);
outb((0x60), 0xa9);
}
if(broken_bus_clock)
pas_write(0x01 | 0x10 | 0x20 | 0x04, 0x8388);
else
pas_write(0x01 | 0x10 | 0x20, 0x8388);
pas_write(0x18, 0x838A);
pas_write(0x20 | 0x01, 0x0B8A);
pas_write(8, 0xBF8A);
mix_write(0x80 | 5, 0x078B);
mix_write(5, 0x078B);
{
struct address_info *sb_config;
sb_config = &cfg2;
if (sb_config->io_base)
{
unsigned char irq_dma;
pas_write(0x02, 0xF788);
pas_write((sb_config->io_base >> 4) & 0x0f, 0xF789);
pas_sb_base = sb_config->io_base;
if (!sb_dma_bits[sb_config->dma])
printk(KERN_ERR "PAS16 Warning: Invalid SB DMA %d\n\n", sb_config->dma);
if (!sb_irq_bits[sb_config->irq])
printk(KERN_ERR "PAS16 Warning: Invalid SB IRQ %d\n\n", sb_config->irq);
irq_dma = sb_dma_bits[sb_config->dma] |
sb_irq_bits[sb_config->irq];
pas_write(irq_dma, 0xFB8A);
}
else
pas_write(0x00, 0xF788);
}
if (!ok)
printk(KERN_WARNING "PAS16: Driver not enabled\n");
return ok;
}
static int __init detect_pas_hw(struct address_info *hw_config)
{
unsigned char board_id, foo;
outb((0xBC), 0x9A01);
outb((hw_config->io_base >> 2), 0x9A01);
pas_translate_code = hw_config->io_base - 0x388;
pas_write(1, 0xBF88);
board_id = pas_read(0x0B8B);
if (board_id == 0xff)
return 0;
foo = board_id ^ 0xe0;
pas_write(foo, 0x0B8B);
foo = pas_read(0x0B8B);
pas_write(board_id, 0x0B8B);
if (board_id != foo)
return 0;
pas_model = pas_read(0xFF88);
return pas_model;
}
static void __init attach_pas_card(struct address_info *hw_config)
{
pas_irq = hw_config->irq;
if (detect_pas_hw(hw_config))
{
if ((pas_model = pas_read(0xFF88)))
{
char temp[100];
sprintf(temp,
"%s rev %d", pas_model_names[(int) pas_model],
pas_read(0x2789));
conf_printf(temp, hw_config);
}
if (config_pas_hw(hw_config))
{
pas_pcm_init(hw_config);
pas_midi_init();
pas_init_mixer();
}
}
}
static inline int __init probe_pas(struct address_info *hw_config)
{
return detect_pas_hw(hw_config);
}
static void __exit unload_pas(struct address_info *hw_config)
{
extern int pas_audiodev;
extern int pas2_mididev;
if (hw_config->dma>0)
sound_free_dma(hw_config->dma);
if (hw_config->irq>0)
free_irq(hw_config->irq, hw_config);
if(pas_audiodev!=-1)
sound_unload_mixerdev(audio_devs[pas_audiodev]->mixer_dev);
if(pas2_mididev!=-1)
sound_unload_mididev(pas2_mididev);
if(pas_audiodev!=-1)
sound_unload_audiodev(pas_audiodev);
}
static int __init init_pas2(void)
{
printk(KERN_INFO "Pro Audio Spectrum driver Copyright (C) by Hannu Savolainen 1993-1996\n");
cfg.io_base = io;
cfg.irq = irq;
cfg.dma = dma;
cfg.dma2 = dma16;
cfg2.io_base = sb_io;
cfg2.irq = sb_irq;
cfg2.dma = sb_dma;
cfg2.dma2 = sb_dma16;
if (cfg.io_base == -1 || cfg.dma == -1 || cfg.irq == -1) {
printk(KERN_INFO "I/O, IRQ, DMA and type are mandatory\n");
return -EINVAL;
}
if (!probe_pas(&cfg))
return -ENODEV;
attach_pas_card(&cfg);
return 0;
}
static void __exit cleanup_pas2(void)
{
unload_pas(&cfg);
}
static int __init setup_pas2(char *str)
{
int ints[9];
str = get_options(str, ARRAY_SIZE(ints), ints);
io = ints[1];
irq = ints[2];
dma = ints[3];
dma16 = ints[4];
sb_io = ints[5];
sb_irq = ints[6];
sb_dma = ints[7];
sb_dma16 = ints[8];
return 1;
}
