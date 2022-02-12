static int pcspkr_event(struct input_dev *dev, unsigned int type, unsigned int code, int value)
{
unsigned int count = 0;
unsigned long flags;
if (type != EV_SND)
return -1;
switch (code) {
case SND_BELL: if (value) value = 1000;
case SND_TONE: break;
default: return -1;
}
if (value > 20 && value < 32767)
count = PIT_TICK_RATE / value;
raw_spin_lock_irqsave(&i8253_lock, flags);
if (count) {
outb_p(0xB6, 0x43);
outb_p(count & 0xff, 0x42);
outb((count >> 8) & 0xff, 0x42);
outb_p(inb_p(0x61) | 3, 0x61);
} else {
outb(inb_p(0x61) & 0xFC, 0x61);
}
raw_spin_unlock_irqrestore(&i8253_lock, flags);
return 0;
}
static int __devinit pcspkr_probe(struct platform_device *dev)
{
struct input_dev *pcspkr_dev;
int err;
pcspkr_dev = input_allocate_device();
if (!pcspkr_dev)
return -ENOMEM;
pcspkr_dev->name = "PC Speaker";
pcspkr_dev->phys = "isa0061/input0";
pcspkr_dev->id.bustype = BUS_ISA;
pcspkr_dev->id.vendor = 0x001f;
pcspkr_dev->id.product = 0x0001;
pcspkr_dev->id.version = 0x0100;
pcspkr_dev->dev.parent = &dev->dev;
pcspkr_dev->evbit[0] = BIT_MASK(EV_SND);
pcspkr_dev->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
pcspkr_dev->event = pcspkr_event;
err = input_register_device(pcspkr_dev);
if (err) {
input_free_device(pcspkr_dev);
return err;
}
platform_set_drvdata(dev, pcspkr_dev);
return 0;
}
static int __devexit pcspkr_remove(struct platform_device *dev)
{
struct input_dev *pcspkr_dev = platform_get_drvdata(dev);
input_unregister_device(pcspkr_dev);
platform_set_drvdata(dev, NULL);
pcspkr_event(NULL, EV_SND, SND_BELL, 0);
return 0;
}
static int pcspkr_suspend(struct device *dev)
{
pcspkr_event(NULL, EV_SND, SND_BELL, 0);
return 0;
}
static void pcspkr_shutdown(struct platform_device *dev)
{
pcspkr_event(NULL, EV_SND, SND_BELL, 0);
}
static int __init pcspkr_init(void)
{
return platform_driver_register(&pcspkr_platform_driver);
}
static void __exit pcspkr_exit(void)
{
platform_driver_unregister(&pcspkr_platform_driver);
}
