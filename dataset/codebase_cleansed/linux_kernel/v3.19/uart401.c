static int uart401_status(struct uart401_devc *devc)
{
return inb(STATPORT);
}
static void uart401_cmd(struct uart401_devc *devc, unsigned char cmd)
{
outb((cmd), COMDPORT);
}
static int uart401_read(struct uart401_devc *devc)
{
return inb(DATAPORT);
}
static void uart401_write(struct uart401_devc *devc, unsigned char byte)
{
outb((byte), DATAPORT);
}
static void uart401_input_loop(struct uart401_devc *devc)
{
int work_limit=30000;
while (input_avail(devc) && --work_limit)
{
unsigned char c = uart401_read(devc);
if (c == MPU_ACK)
devc->input_byte = c;
else if (devc->opened & OPEN_READ && devc->midi_input_intr)
devc->midi_input_intr(devc->my_dev, c);
}
if(work_limit==0)
printk(KERN_WARNING "Too much work in interrupt on uart401 (0x%X). UART jabbering ??\n", devc->base);
}
irqreturn_t uart401intr(int irq, void *dev_id)
{
struct uart401_devc *devc = dev_id;
if (devc == NULL)
{
printk(KERN_ERR "uart401: bad devc\n");
return IRQ_NONE;
}
if (input_avail(devc))
uart401_input_loop(devc);
return IRQ_HANDLED;
}
static int
uart401_open(int dev, int mode,
void (*input) (int dev, unsigned char data),
void (*output) (int dev)
)
{
struct uart401_devc *devc = (struct uart401_devc *)
midi_devs[dev]->devc;
if (devc->opened)
return -EBUSY;
while (input_avail(devc))
uart401_read(devc);
devc->midi_input_intr = input;
devc->opened = mode;
enter_uart_mode(devc);
devc->disabled = 0;
return 0;
}
static void uart401_close(int dev)
{
struct uart401_devc *devc = (struct uart401_devc *)
midi_devs[dev]->devc;
reset_uart401(devc);
devc->opened = 0;
}
static int uart401_out(int dev, unsigned char midi_byte)
{
int timeout;
unsigned long flags;
struct uart401_devc *devc = (struct uart401_devc *)
midi_devs[dev]->devc;
if (devc->disabled)
return 1;
spin_lock_irqsave(&devc->lock,flags);
if (input_avail(devc))
uart401_input_loop(devc);
spin_unlock_irqrestore(&devc->lock,flags);
for (timeout = 30000; timeout > 0 && !output_ready(devc); timeout--);
if (!output_ready(devc))
{
printk(KERN_WARNING "uart401: Timeout - Device not responding\n");
devc->disabled = 1;
reset_uart401(devc);
enter_uart_mode(devc);
return 1;
}
uart401_write(devc, midi_byte);
return 1;
}
static inline int uart401_start_read(int dev)
{
return 0;
}
static inline int uart401_end_read(int dev)
{
return 0;
}
static inline void uart401_kick(int dev)
{
}
static inline int uart401_buffer_status(int dev)
{
return 0;
}
static void enter_uart_mode(struct uart401_devc *devc)
{
int ok, timeout;
unsigned long flags;
spin_lock_irqsave(&devc->lock,flags);
for (timeout = 30000; timeout > 0 && !output_ready(devc); timeout--);
devc->input_byte = 0;
uart401_cmd(devc, UART_MODE_ON);
ok = 0;
for (timeout = 50000; timeout > 0 && !ok; timeout--)
if (devc->input_byte == MPU_ACK)
ok = 1;
else if (input_avail(devc))
if (uart401_read(devc) == MPU_ACK)
ok = 1;
spin_unlock_irqrestore(&devc->lock,flags);
}
static int reset_uart401(struct uart401_devc *devc)
{
int ok, timeout, n;
ok = 0;
for (n = 0; n < 2 && !ok; n++)
{
for (timeout = 30000; timeout > 0 && !output_ready(devc); timeout--);
devc->input_byte = 0;
uart401_cmd(devc, MPU_RESET);
for (timeout = 50000; timeout > 0 && !ok; timeout--)
{
if (devc->input_byte == MPU_ACK)
ok = 1;
else if (input_avail(devc))
{
if (uart401_read(devc) == MPU_ACK)
ok = 1;
}
}
}
if (ok)
uart401_input_loop(devc);
else
DDB(printk("Reset UART401 failed - No hardware detected.\n"));
return ok;
}
int probe_uart401(struct address_info *hw_config, struct module *owner)
{
struct uart401_devc *devc;
char *name = "MPU-401 (UART) MIDI";
int ok = 0;
unsigned long flags;
DDB(printk("Entered probe_uart401()\n"));
hw_config->slots[4] = -1;
if (!request_region(hw_config->io_base, 4, "MPU-401 UART")) {
printk(KERN_INFO "uart401: could not request_region(%d, 4)\n", hw_config->io_base);
return 0;
}
devc = kmalloc(sizeof(struct uart401_devc), GFP_KERNEL);
if (!devc) {
printk(KERN_WARNING "uart401: Can't allocate memory\n");
goto cleanup_region;
}
devc->base = hw_config->io_base;
devc->irq = hw_config->irq;
devc->osp = hw_config->osp;
devc->midi_input_intr = NULL;
devc->opened = 0;
devc->input_byte = 0;
devc->my_dev = 0;
devc->share_irq = 0;
spin_lock_init(&devc->lock);
spin_lock_irqsave(&devc->lock,flags);
ok = reset_uart401(devc);
spin_unlock_irqrestore(&devc->lock,flags);
if (!ok)
goto cleanup_devc;
if (hw_config->name)
name = hw_config->name;
if (devc->irq < 0) {
devc->share_irq = 1;
devc->irq *= -1;
} else
devc->share_irq = 0;
if (!devc->share_irq)
if (request_irq(devc->irq, uart401intr, 0, "MPU-401 UART", devc) < 0) {
printk(KERN_WARNING "uart401: Failed to allocate IRQ%d\n", devc->irq);
devc->share_irq = 1;
}
devc->my_dev = sound_alloc_mididev();
enter_uart_mode(devc);
if (devc->my_dev == -1) {
printk(KERN_INFO "uart401: Too many midi devices detected\n");
goto cleanup_irq;
}
conf_printf(name, hw_config);
midi_devs[devc->my_dev] = kmemdup(&uart401_operations,
sizeof(struct midi_operations),
GFP_KERNEL);
if (!midi_devs[devc->my_dev]) {
printk(KERN_ERR "uart401: Failed to allocate memory\n");
goto cleanup_unload_mididev;
}
if (owner)
midi_devs[devc->my_dev]->owner = owner;
midi_devs[devc->my_dev]->devc = devc;
midi_devs[devc->my_dev]->converter = kmemdup(&std_midi_synth,
sizeof(struct synth_operations),
GFP_KERNEL);
if (!midi_devs[devc->my_dev]->converter) {
printk(KERN_WARNING "uart401: Failed to allocate memory\n");
goto cleanup_midi_devs;
}
strcpy(midi_devs[devc->my_dev]->info.name, name);
midi_devs[devc->my_dev]->converter->id = "UART401";
midi_devs[devc->my_dev]->converter->midi_dev = devc->my_dev;
if (owner)
midi_devs[devc->my_dev]->converter->owner = owner;
hw_config->slots[4] = devc->my_dev;
sequencer_init();
devc->opened = 0;
return 1;
cleanup_midi_devs:
kfree(midi_devs[devc->my_dev]);
cleanup_unload_mididev:
sound_unload_mididev(devc->my_dev);
cleanup_irq:
if (!devc->share_irq)
free_irq(devc->irq, devc);
cleanup_devc:
kfree(devc);
cleanup_region:
release_region(hw_config->io_base, 4);
return 0;
}
void unload_uart401(struct address_info *hw_config)
{
struct uart401_devc *devc;
int n=hw_config->slots[4];
if(n==-1 || midi_devs[n]==NULL)
return;
devc = midi_devs[hw_config->slots[4]]->devc;
if (devc == NULL)
return;
reset_uart401(devc);
release_region(hw_config->io_base, 4);
if (!devc->share_irq)
free_irq(devc->irq, devc);
kfree(midi_devs[devc->my_dev]->converter);
kfree(midi_devs[devc->my_dev]);
kfree(devc);
sound_unload_mididev(hw_config->slots[4]);
}
static int __init init_uart401(void)
{
cfg_mpu.irq = irq;
cfg_mpu.io_base = io;
if (cfg_mpu.io_base != -1 && cfg_mpu.irq != -1) {
printk(KERN_INFO "MPU-401 UART driver Copyright (C) Hannu Savolainen 1993-1997");
if (!probe_uart401(&cfg_mpu, THIS_MODULE))
return -ENODEV;
}
return 0;
}
static void __exit cleanup_uart401(void)
{
if (cfg_mpu.io_base != -1 && cfg_mpu.irq != -1)
unload_uart401(&cfg_mpu);
}
static int __init setup_uart401(char *str)
{
int ints[3];
str = get_options(str, ARRAY_SIZE(ints), ints);
io = ints[1];
irq = ints[2];
return 1;
}
