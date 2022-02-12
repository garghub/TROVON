static struct radio_isa_card *rtrack_alloc(void)
{
struct rtrack *rt = kzalloc(sizeof(struct rtrack), GFP_KERNEL);
if (rt)
rt->curvol = 0xff;
return rt ? &rt->isa : NULL;
}
static void rtrack_set_pins(void *handle, u8 pins)
{
struct radio_isa_card *isa = handle;
struct rtrack *rt = container_of(isa, struct rtrack, isa);
u8 bits = AIMS_BIT_VOL_DN | AIMS_BIT_VOL_UP | AIMS_BIT_TUN_STRQ;
if (!v4l2_ctrl_g_ctrl(rt->isa.mute))
bits |= AIMS_BIT_VOL_CE;
if (pins & LM7000_DATA)
bits |= AIMS_BIT_TUN_DATA;
if (pins & LM7000_CLK)
bits |= AIMS_BIT_TUN_CLK;
if (pins & LM7000_CE)
bits |= AIMS_BIT_TUN_CE;
outb_p(bits, rt->isa.io);
}
static int rtrack_s_frequency(struct radio_isa_card *isa, u32 freq)
{
lm7000_set_freq(freq, isa, rtrack_set_pins);
return 0;
}
static u32 rtrack_g_signal(struct radio_isa_card *isa)
{
return 0xffff * !(inb(isa->io) & 2);
}
static int rtrack_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
struct rtrack *rt = container_of(isa, struct rtrack, isa);
int curvol = rt->curvol;
if (mute) {
outb(0xd0, isa->io);
return 0;
}
if (vol == 0) {
outb(0x48, isa->io);
msleep(curvol * 3);
} else if (curvol < vol) {
outb(0x98, isa->io);
for (; curvol < vol; curvol++)
udelay(3000);
} else if (curvol > vol) {
outb(0x58, isa->io);
for (; curvol > vol; curvol--)
udelay(3000);
}
outb(0xd8, isa->io);
rt->curvol = vol;
return 0;
}
static int rtrack_initialize(struct radio_isa_card *isa)
{
outb(0x90, isa->io);
msleep(3000);
outb(0xc0, isa->io);
return 0;
}
static int __init rtrack_init(void)
{
return isa_register_driver(&rtrack_driver.driver, RTRACK_MAX);
}
static void __exit rtrack_exit(void)
{
isa_unregister_driver(&rtrack_driver.driver);
}
