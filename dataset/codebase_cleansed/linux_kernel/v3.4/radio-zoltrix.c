static struct radio_isa_card *zoltrix_alloc(void)
{
struct zoltrix *zol = kzalloc(sizeof(*zol), GFP_KERNEL);
return zol ? &zol->isa : NULL;
}
static int zoltrix_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
struct zoltrix *zol = container_of(isa, struct zoltrix, isa);
zol->curvol = vol;
zol->muted = mute;
if (mute || vol == 0) {
outb(0, isa->io);
outb(0, isa->io);
inb(isa->io + 3);
return 0;
}
outb(vol - 1, isa->io);
msleep(10);
inb(isa->io + 2);
return 0;
}
static int zoltrix_s_frequency(struct radio_isa_card *isa, u32 freq)
{
struct zoltrix *zol = container_of(isa, struct zoltrix, isa);
struct v4l2_device *v4l2_dev = &isa->v4l2_dev;
unsigned long long bitmask, f, m;
bool stereo = isa->stereo;
int i;
if (freq == 0) {
v4l2_warn(v4l2_dev, "cannot set a frequency of 0.\n");
return -EINVAL;
}
m = (freq / 160 - 8800) * 2;
f = (unsigned long long)m + 0x4d1c;
bitmask = 0xc480402c10080000ull;
i = 45;
outb(0, isa->io);
outb(0, isa->io);
inb(isa->io + 3);
outb(0x40, isa->io);
outb(0xc0, isa->io);
bitmask = (bitmask ^ ((f & 0xff) << 47) ^ ((f & 0xff00) << 30) ^ (stereo << 31));
while (i--) {
if ((bitmask & 0x8000000000000000ull) != 0) {
outb(0x80, isa->io);
udelay(50);
outb(0x00, isa->io);
udelay(50);
outb(0x80, isa->io);
udelay(50);
} else {
outb(0xc0, isa->io);
udelay(50);
outb(0x40, isa->io);
udelay(50);
outb(0xc0, isa->io);
udelay(50);
}
bitmask *= 2;
}
outb(0x80, isa->io);
outb(0xc0, isa->io);
outb(0x40, isa->io);
udelay(1000);
inb(isa->io + 2);
udelay(1000);
return zoltrix_s_mute_volume(isa, zol->muted, zol->curvol);
}
static u32 zoltrix_g_rxsubchans(struct radio_isa_card *isa)
{
struct zoltrix *zol = container_of(isa, struct zoltrix, isa);
int a, b;
outb(0x00, isa->io);
outb(zol->curvol, isa->io);
msleep(20);
a = inb(isa->io);
msleep(10);
b = inb(isa->io);
return (a == b && a == 0xcf) ?
V4L2_TUNER_SUB_STEREO : V4L2_TUNER_SUB_MONO;
}
static u32 zoltrix_g_signal(struct radio_isa_card *isa)
{
struct zoltrix *zol = container_of(isa, struct zoltrix, isa);
int a, b;
outb(0x00, isa->io);
outb(zol->curvol, isa->io);
msleep(20);
a = inb(isa->io);
msleep(10);
b = inb(isa->io);
if (a != b)
return 0;
return (a == 0xcf || a == 0xdf || a == 0xef) ? 0xffff : 0;
}
static int zoltrix_s_stereo(struct radio_isa_card *isa, bool stereo)
{
return zoltrix_s_frequency(isa, isa->freq);
}
static int __init zoltrix_init(void)
{
return isa_register_driver(&zoltrix_driver.driver, ZOLTRIX_MAX);
}
static void __exit zoltrix_exit(void)
{
isa_unregister_driver(&zoltrix_driver.driver);
}
