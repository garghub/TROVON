static struct radio_isa_card *trust_alloc(void)
{
struct trust *tr = kzalloc(sizeof(*tr), GFP_KERNEL);
return tr ? &tr->isa : NULL;
}
static void write_i2c(struct trust *tr, int n, ...)
{
unsigned char val, mask;
va_list args;
va_start(args, n);
TR_SET_SDA;
TR_SET_SCL;
TR_DELAY;
TR_CLR_SDA;
TR_CLR_SCL;
TR_DELAY;
for (; n; n--) {
val = va_arg(args, unsigned);
for (mask = 0x80; mask; mask >>= 1) {
if (val & mask)
TR_SET_SDA;
else
TR_CLR_SDA;
TR_SET_SCL;
TR_DELAY;
TR_CLR_SCL;
TR_DELAY;
}
TR_SET_SDA;
TR_SET_SCL;
TR_DELAY;
TR_CLR_SCL;
TR_DELAY;
}
TR_CLR_SDA;
TR_DELAY;
TR_SET_SCL;
TR_DELAY;
TR_SET_SDA;
TR_DELAY;
va_end(args);
}
static int trust_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
struct trust *tr = container_of(isa, struct trust, isa);
tr->ioval = (tr->ioval & 0xf7) | (mute << 3);
outb(tr->ioval, isa->io);
write_i2c(tr, 2, TDA7318_ADDR, vol ^ 0x1f);
return 0;
}
static int trust_s_stereo(struct radio_isa_card *isa, bool stereo)
{
struct trust *tr = container_of(isa, struct trust, isa);
tr->ioval = (tr->ioval & 0xfb) | (!stereo << 2);
outb(tr->ioval, isa->io);
return 0;
}
static u32 trust_g_signal(struct radio_isa_card *isa)
{
int i, v;
for (i = 0, v = 0; i < 100; i++)
v |= inb(isa->io);
return (v & 1) ? 0 : 0xffff;
}
static int trust_s_frequency(struct radio_isa_card *isa, u32 freq)
{
struct trust *tr = container_of(isa, struct trust, isa);
freq /= 160;
freq += 1070;
write_i2c(tr, 5, TSA6060T_ADDR, (freq << 1) | 1,
freq >> 7, 0x60 | ((freq >> 15) & 1), 0);
return 0;
}
static int trust_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct radio_isa_card *isa =
container_of(ctrl->handler, struct radio_isa_card, hdl);
struct trust *tr = container_of(isa, struct trust, isa);
switch (ctrl->id) {
case V4L2_CID_AUDIO_BASS:
write_i2c(tr, 2, TDA7318_ADDR, 0x60 | basstreble2chip[ctrl->val]);
return 0;
case V4L2_CID_AUDIO_TREBLE:
write_i2c(tr, 2, TDA7318_ADDR, 0x70 | basstreble2chip[ctrl->val]);
return 0;
}
return -EINVAL;
}
static int trust_initialize(struct radio_isa_card *isa)
{
struct trust *tr = container_of(isa, struct trust, isa);
tr->ioval = 0xf;
write_i2c(tr, 2, TDA7318_ADDR, 0x80);
write_i2c(tr, 2, TDA7318_ADDR, 0xa0);
write_i2c(tr, 2, TDA7318_ADDR, 0xc0);
write_i2c(tr, 2, TDA7318_ADDR, 0xe0);
write_i2c(tr, 2, TDA7318_ADDR, 0x40);
v4l2_ctrl_new_std(&isa->hdl, &trust_ctrl_ops,
V4L2_CID_AUDIO_BASS, 0, 15, 1, 8);
v4l2_ctrl_new_std(&isa->hdl, &trust_ctrl_ops,
V4L2_CID_AUDIO_TREBLE, 0, 15, 1, 8);
return isa->hdl.error;
}
static int __init trust_init(void)
{
return isa_register_driver(&trust_driver.driver, TRUST_MAX);
}
static void __exit trust_exit(void)
{
isa_unregister_driver(&trust_driver.driver);
}
