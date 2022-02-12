static void aztech_set_pins(void *handle, u8 pins)
{
struct radio_isa_card *isa = handle;
struct aztech *az = container_of(isa, struct aztech, isa);
u8 bits = az->curvol;
if (pins & LM7000_DATA)
bits |= AZTECH_BIT_TUN_DATA;
if (pins & LM7000_CLK)
bits |= AZTECH_BIT_TUN_CLK;
if (pins & LM7000_CE)
bits |= AZTECH_BIT_TUN_CE;
outb_p(bits, az->isa.io);
}
static struct radio_isa_card *aztech_alloc(void)
{
struct aztech *az = kzalloc(sizeof(*az), GFP_KERNEL);
return az ? &az->isa : NULL;
}
static int aztech_s_frequency(struct radio_isa_card *isa, u32 freq)
{
lm7000_set_freq(freq, isa, aztech_set_pins);
return 0;
}
static u32 aztech_g_rxsubchans(struct radio_isa_card *isa)
{
if (inb(isa->io) & AZTECH_BIT_MONO)
return V4L2_TUNER_SUB_MONO;
return V4L2_TUNER_SUB_STEREO;
}
static u32 aztech_g_signal(struct radio_isa_card *isa)
{
return (inb(isa->io) & AZTECH_BIT_NOT_TUNED) ? 0 : 0xffff;
}
static int aztech_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
struct aztech *az = container_of(isa, struct aztech, isa);
if (mute)
vol = 0;
az->curvol = (vol & 1) + ((vol & 2) << 1);
outb(az->curvol, isa->io);
return 0;
}
static int __init aztech_init(void)
{
return isa_register_driver(&aztech_driver.driver, AZTECH_MAX);
}
static void __exit aztech_exit(void)
{
isa_unregister_driver(&aztech_driver.driver);
}
