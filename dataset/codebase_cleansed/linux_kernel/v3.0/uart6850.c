static int uart6850_status(void)
{
return inb(STATPORT);
}
static void uart6850_cmd(unsigned char cmd)
{
outb(cmd, COMDPORT);
}
static int uart6850_read(void)
{
return inb(DATAPORT);
}
static void uart6850_write(unsigned char byte)
{
outb(byte, DATAPORT);
}
static void uart6850_input_loop(void)
{
int count = 10;
while (count)
{
if (input_avail())
{
unsigned char c = uart6850_read();
count = 100;
if (uart6850_opened & OPEN_READ)
midi_input_intr(my_dev, c);
}
else
{
while (!input_avail() && count)
count--;
}
}
}
static irqreturn_t m6850intr(int irq, void *dev_id)
{
if (input_avail())
uart6850_input_loop();
return IRQ_HANDLED;
}
static void poll_uart6850(unsigned long dummy)
{
unsigned long flags;
if (!(uart6850_opened & OPEN_READ))
return;
spin_lock_irqsave(&lock,flags);
if (input_avail())
uart6850_input_loop();
uart6850_timer.expires = 1 + jiffies;
add_timer(&uart6850_timer);
spin_unlock_irqrestore(&lock,flags);
}
static int uart6850_open(int dev, int mode,
void (*input) (int dev, unsigned char data),
void (*output) (int dev)
)
{
if (uart6850_opened)
{
return -EBUSY;
};
uart6850_cmd(UART_RESET);
uart6850_input_loop();
midi_input_intr = input;
uart6850_opened = mode;
poll_uart6850(0);
return 0;
}
static void uart6850_close(int dev)
{
uart6850_cmd(UART_MODE_ON);
del_timer(&uart6850_timer);
uart6850_opened = 0;
}
static int uart6850_out(int dev, unsigned char midi_byte)
{
int timeout;
unsigned long flags;
spin_lock_irqsave(&lock,flags);
if (input_avail())
uart6850_input_loop();
spin_unlock_irqrestore(&lock,flags);
for (timeout = 30000; timeout > 0 && !output_ready(); timeout--);
if (!output_ready())
{
printk(KERN_WARNING "Midi6850: Timeout\n");
return 0;
}
uart6850_write(midi_byte);
return 1;
}
static inline int uart6850_command(int dev, unsigned char *midi_byte)
{
return 1;
}
static inline int uart6850_start_read(int dev)
{
return 0;
}
static inline int uart6850_end_read(int dev)
{
return 0;
}
static inline void uart6850_kick(int dev)
{
}
static inline int uart6850_buffer_status(int dev)
{
return 0;
}
static void __init attach_uart6850(struct address_info *hw_config)
{
int ok, timeout;
unsigned long flags;
if (!uart6850_detected)
return;
if ((my_dev = sound_alloc_mididev()) == -1)
{
printk(KERN_INFO "uart6850: Too many midi devices detected\n");
return;
}
uart6850_base = hw_config->io_base;
uart6850_osp = hw_config->osp;
uart6850_irq = hw_config->irq;
spin_lock_irqsave(&lock,flags);
for (timeout = 30000; timeout > 0 && !output_ready(); timeout--);
uart6850_cmd(UART_MODE_ON);
ok = 1;
spin_unlock_irqrestore(&lock,flags);
conf_printf("6850 Midi Interface", hw_config);
std_midi_synth.midi_dev = my_dev;
hw_config->slots[4] = my_dev;
midi_devs[my_dev] = &uart6850_operations;
sequencer_init();
}
static inline int reset_uart6850(void)
{
uart6850_read();
return 1;
}
static int __init probe_uart6850(struct address_info *hw_config)
{
int ok;
uart6850_osp = hw_config->osp;
uart6850_base = hw_config->io_base;
uart6850_irq = hw_config->irq;
if (request_irq(uart6850_irq, m6850intr, 0, "MIDI6850", NULL) < 0)
return 0;
ok = reset_uart6850();
uart6850_detected = ok;
return ok;
}
static void __exit unload_uart6850(struct address_info *hw_config)
{
free_irq(hw_config->irq, NULL);
sound_unload_mididev(hw_config->slots[4]);
}
static int __init init_uart6850(void)
{
cfg_mpu.io_base = io;
cfg_mpu.irq = irq;
if (cfg_mpu.io_base == -1 || cfg_mpu.irq == -1) {
printk(KERN_INFO "uart6850: irq and io must be set.\n");
return -EINVAL;
}
if (probe_uart6850(&cfg_mpu))
return -ENODEV;
attach_uart6850(&cfg_mpu);
return 0;
}
static void __exit cleanup_uart6850(void)
{
unload_uart6850(&cfg_mpu);
}
static int __init setup_uart6850(char *str)
{
int ints[3];
str = get_options(str, ARRAY_SIZE(ints), ints);
io = ints[1];
irq = ints[2];
return 1;
}
