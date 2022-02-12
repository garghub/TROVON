static struct radio_isa_card *rtrack_alloc(void)
{
struct rtrack *rt = kzalloc(sizeof(struct rtrack), GFP_KERNEL);
if (rt)
rt->curvol = 0xff;
return rt ? &rt->isa : NULL;
}
static void send_0_byte(struct radio_isa_card *isa, int on)
{
outb_p(128+64+16+on+1, isa->io);
outb_p(128+64+16+on+2+1, isa->io);
msleep(1);
}
static void send_1_byte(struct radio_isa_card *isa, int on)
{
outb_p(128+64+16+on+4+1, isa->io);
outb_p(128+64+16+on+4+2+1, isa->io);
msleep(1);
}
static int rtrack_s_frequency(struct radio_isa_card *isa, u32 freq)
{
int on = v4l2_ctrl_g_ctrl(isa->mute) ? 0 : 8;
int i;
freq += 171200;
freq /= 800;
send_0_byte(isa, on);
for (i = 0; i < 13; i++)
if (freq & (1 << i))
send_1_byte(isa, on);
else
send_0_byte(isa, on);
send_0_byte(isa, on);
send_0_byte(isa, on);
send_0_byte(isa, on);
send_0_byte(isa, on);
send_0_byte(isa, on);
send_0_byte(isa, on);
send_0_byte(isa, on);
send_1_byte(isa, on);
send_0_byte(isa, on);
send_1_byte(isa, on);
outb(0xd0 + on, isa->io);
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
