static void gemtek_bu2614_transmit(struct gemtek *gt)
{
struct radio_isa_card *isa = &gt->isa;
int i, bit, q, mute;
mute = gt->muted ? GEMTEK_MT : 0x00;
outb_p(mute | GEMTEK_CE | GEMTEK_DA | GEMTEK_CK, isa->io);
udelay(LONG_DELAY);
for (i = 0, q = gt->bu2614data; i < 32; i++, q >>= 1) {
bit = (q & 1) ? GEMTEK_DA : 0;
outb_p(mute | GEMTEK_CE | bit, isa->io);
udelay(SHORT_DELAY);
outb_p(mute | GEMTEK_CE | bit | GEMTEK_CK, isa->io);
udelay(SHORT_DELAY);
}
outb_p(mute | GEMTEK_DA | GEMTEK_CK, isa->io);
udelay(SHORT_DELAY);
}
static unsigned long gemtek_convfreq(unsigned long freq)
{
return ((freq << FSCALE) + IF_OFFSET + REF_FREQ / 2) / REF_FREQ;
}
static struct radio_isa_card *gemtek_alloc(void)
{
struct gemtek *gt = kzalloc(sizeof(*gt), GFP_KERNEL);
if (gt)
gt->muted = true;
return gt ? &gt->isa : NULL;
}
static int gemtek_s_frequency(struct radio_isa_card *isa, u32 freq)
{
struct gemtek *gt = container_of(isa, struct gemtek, isa);
if (hardmute && gt->muted)
return 0;
gemtek_bu2614_set(gt, BU2614_PORT, 0);
gemtek_bu2614_set(gt, BU2614_FMES, 0);
gemtek_bu2614_set(gt, BU2614_SWIN, 0);
gemtek_bu2614_set(gt, BU2614_SWAL, 0);
gemtek_bu2614_set(gt, BU2614_FMUN, 1);
gemtek_bu2614_set(gt, BU2614_TEST, 0);
gemtek_bu2614_set(gt, BU2614_STDF, GEMTEK_STDF_3_125_KHZ);
gemtek_bu2614_set(gt, BU2614_FREQ, gemtek_convfreq(freq));
gemtek_bu2614_transmit(gt);
return 0;
}
static int gemtek_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
struct gemtek *gt = container_of(isa, struct gemtek, isa);
int i;
gt->muted = mute;
if (hardmute) {
if (!mute)
return gemtek_s_frequency(isa, isa->freq);
gemtek_bu2614_set(gt, BU2614_PORT, 0);
gemtek_bu2614_set(gt, BU2614_FMES, 0);
gemtek_bu2614_set(gt, BU2614_SWIN, 0);
gemtek_bu2614_set(gt, BU2614_SWAL, 0);
gemtek_bu2614_set(gt, BU2614_FMUN, 0);
gemtek_bu2614_set(gt, BU2614_TEST, 0);
gemtek_bu2614_set(gt, BU2614_STDF, GEMTEK_PLL_OFF);
gemtek_bu2614_set(gt, BU2614_FREQ, 0);
gemtek_bu2614_transmit(gt);
return 0;
}
i = inb_p(isa->io);
outb_p((i >> 5) | (mute ? GEMTEK_MT : 0), isa->io);
udelay(SHORT_DELAY);
return 0;
}
static u32 gemtek_g_rxsubchans(struct radio_isa_card *isa)
{
if (inb_p(isa->io) & GEMTEK_NS)
return V4L2_TUNER_SUB_MONO;
return V4L2_TUNER_SUB_STEREO;
}
static bool gemtek_probe(struct radio_isa_card *isa, int io)
{
int i, q;
q = inb_p(io);
for (i = 0; i < 3; ++i) {
outb_p(1 << i, io);
udelay(SHORT_DELAY);
if ((inb_p(io) & ~GEMTEK_NS) != (0x17 | (1 << (i + 5))))
return false;
}
outb_p(q >> 5, io);
udelay(SHORT_DELAY);
return true;
}
static int __init gemtek_init(void)
{
gemtek_driver.probe = probe;
#ifdef CONFIG_PNP
pnp_register_driver(&gemtek_driver.pnp_driver);
#endif
return isa_register_driver(&gemtek_driver.driver, GEMTEK_MAX);
}
static void __exit gemtek_exit(void)
{
hardmute = true;
#ifdef CONFIG_PNP
pnp_unregister_driver(&gemtek_driver.pnp_driver);
#endif
isa_unregister_driver(&gemtek_driver.driver);
}
