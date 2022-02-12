static struct radio_isa_card *rtrack2_alloc(void)
{
return kzalloc(sizeof(struct radio_isa_card), GFP_KERNEL);
}
static void zero(struct radio_isa_card *isa)
{
outb_p(1, isa->io);
outb_p(3, isa->io);
outb_p(1, isa->io);
}
static void one(struct radio_isa_card *isa)
{
outb_p(5, isa->io);
outb_p(7, isa->io);
outb_p(5, isa->io);
}
static int rtrack2_s_frequency(struct radio_isa_card *isa, u32 freq)
{
int i;
freq = freq / 200 + 856;
outb_p(0xc8, isa->io);
outb_p(0xc9, isa->io);
outb_p(0xc9, isa->io);
for (i = 0; i < 10; i++)
zero(isa);
for (i = 14; i >= 0; i--)
if (freq & (1 << i))
one(isa);
else
zero(isa);
outb_p(0xc8, isa->io);
outb_p(v4l2_ctrl_g_ctrl(isa->mute), isa->io);
return 0;
}
static u32 rtrack2_g_signal(struct radio_isa_card *isa)
{
return (inb(isa->io) & 2) ? 0 : 0xffff;
}
static int rtrack2_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
outb(mute, isa->io);
return 0;
}
static int __init rtrack2_init(void)
{
return isa_register_driver(&rtrack2_driver.driver, RTRACK2_MAX);
}
static void __exit rtrack2_exit(void)
{
isa_unregister_driver(&rtrack2_driver.driver);
}
