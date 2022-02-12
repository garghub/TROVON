static struct radio_isa_card *typhoon_alloc(void)
{
struct typhoon *ty = kzalloc(sizeof(*ty), GFP_KERNEL);
return ty ? &ty->isa : NULL;
}
static int typhoon_s_frequency(struct radio_isa_card *isa, u32 freq)
{
unsigned long outval;
unsigned long x;
x = freq / 160;
outval = (x * x + 2500) / 5000;
outval = (outval * x + 5000) / 10000;
outval -= (10 * x * x + 10433) / 20866;
outval += 4 * x - 11505;
outb_p((outval >> 8) & 0x01, isa->io + 4);
outb_p(outval >> 9, isa->io + 6);
outb_p(outval & 0xff, isa->io + 8);
return 0;
}
static int typhoon_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
struct typhoon *ty = container_of(isa, struct typhoon, isa);
if (mute)
vol = 0;
vol >>= 14;
vol &= 3;
outb_p(vol / 2, isa->io);
outb_p(vol % 2, isa->io + 2);
if (vol == 0 && !ty->muted) {
ty->muted = true;
return typhoon_s_frequency(isa, mutefreq << 4);
}
if (vol && ty->muted) {
ty->muted = false;
return typhoon_s_frequency(isa, isa->freq);
}
return 0;
}
static int __init typhoon_init(void)
{
if (mutefreq < 87000 || mutefreq > 108000) {
printk(KERN_ERR "%s: You must set a frequency (in kHz) used when muting the card,\n",
typhoon_driver.driver.driver.name);
printk(KERN_ERR "%s: e.g. with \"mutefreq=87500\" (87000 <= mutefreq <= 108000)\n",
typhoon_driver.driver.driver.name);
return -ENODEV;
}
return isa_register_driver(&typhoon_driver.driver, TYPHOON_MAX);
}
static void __exit typhoon_exit(void)
{
isa_unregister_driver(&typhoon_driver.driver);
}
