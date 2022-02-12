static void send_0_byte(struct aztech *az)
{
udelay(radio_wait_time);
outb_p(2 + az->curvol, az->isa.io);
outb_p(64 + 2 + az->curvol, az->isa.io);
}
static void send_1_byte(struct aztech *az)
{
udelay(radio_wait_time);
outb_p(128 + 2 + az->curvol, az->isa.io);
outb_p(128 + 64 + 2 + az->curvol, az->isa.io);
}
static struct radio_isa_card *aztech_alloc(void)
{
struct aztech *az = kzalloc(sizeof(*az), GFP_KERNEL);
return az ? &az->isa : NULL;
}
static int aztech_s_frequency(struct radio_isa_card *isa, u32 freq)
{
struct aztech *az = container_of(isa, struct aztech, isa);
int i;
freq += 171200;
freq /= 800;
send_0_byte(az);
for (i = 0; i < 13; i++)
if (freq & (1 << i))
send_1_byte(az);
else
send_0_byte(az);
send_0_byte(az);
send_0_byte(az);
send_0_byte(az);
if (isa->stereo)
send_1_byte(az);
else
send_0_byte(az);
send_1_byte(az);
send_0_byte(az);
send_0_byte(az);
send_1_byte(az);
send_0_byte(az);
send_1_byte(az);
udelay(radio_wait_time);
outb_p(128 + 64 + az->curvol, az->isa.io);
return 0;
}
static u32 aztech_g_rxsubchans(struct radio_isa_card *isa)
{
if (inb(isa->io) & 1)
return V4L2_TUNER_SUB_MONO;
return V4L2_TUNER_SUB_STEREO;
}
static int aztech_s_stereo(struct radio_isa_card *isa, bool stereo)
{
return aztech_s_frequency(isa, isa->freq);
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
