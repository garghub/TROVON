static void fmr2_tea575x_set_pins(struct snd_tea575x *tea, u8 pins)
{
struct fmr2 *fmr2 = tea->private_data;
u8 bits = 0;
bits |= (pins & TEA575X_DATA) ? STR_DATA : 0;
bits |= (pins & TEA575X_CLK) ? STR_CLK : 0;
bits |= (pins & TEA575X_WREN) ? 0 : STR_WREN | STR_DATA;
outb(bits, fmr2->io);
}
static u8 fmr2_tea575x_get_pins(struct snd_tea575x *tea)
{
struct fmr2 *fmr2 = tea->private_data;
u8 bits = inb(fmr2->io);
return (bits & STR_DATA) ? TEA575X_DATA : 0 |
(bits & STR_MOST) ? TEA575X_MOST : 0;
}
static void fmr2_tea575x_set_direction(struct snd_tea575x *tea, bool output)
{
}
static void tc9154a_set_pins(struct fmr2 *fmr2, u8 pins)
{
if (!fmr2->tea.mute)
pins |= STR_WREN;
outb(pins, fmr2->io);
}
static void tc9154a_set_attenuation(struct fmr2 *fmr2, int att, u32 channel)
{
int i;
u32 reg;
u8 bit;
reg = TC9154A_ATT_MAJ(att / 10) | TC9154A_ATT_MIN((att % 10) / 2);
reg |= channel;
for (i = 0; i < 18; i++) {
bit = reg & (1 << i) ? PT_DATA : 0;
tc9154a_set_pins(fmr2, bit);
udelay(5);
tc9154a_set_pins(fmr2, bit | PT_CK);
udelay(5);
tc9154a_set_pins(fmr2, bit);
}
udelay(5);
tc9154a_set_pins(fmr2, PT_ST);
udelay(5);
tc9154a_set_pins(fmr2, 0);
}
static int fmr2_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct snd_tea575x *tea = container_of(ctrl->handler, struct snd_tea575x, ctrl_handler);
struct fmr2 *fmr2 = tea->private_data;
int volume, balance, left, right;
switch (ctrl->id) {
case V4L2_CID_AUDIO_VOLUME:
volume = ctrl->val;
balance = fmr2->balance->cur.val;
break;
case V4L2_CID_AUDIO_BALANCE:
balance = ctrl->val;
volume = fmr2->volume->cur.val;
break;
default:
return -EINVAL;
}
left = right = volume;
if (balance < 0)
right = max(0, right + balance);
if (balance > 0)
left = max(0, left - balance);
tc9154a_set_attenuation(fmr2, abs(left - 68), TC9154A_CHANNEL_LEFT);
tc9154a_set_attenuation(fmr2, abs(right - 68), TC9154A_CHANNEL_RIGHT);
return 0;
}
static int fmr2_tea_ext_init(struct snd_tea575x *tea)
{
struct fmr2 *fmr2 = tea->private_data;
if (inb(fmr2->io) & FMR2_HASVOL) {
fmr2->volume = v4l2_ctrl_new_std(&tea->ctrl_handler, &fmr2_ctrl_ops, V4L2_CID_AUDIO_VOLUME, 0, 68, 2, 56);
fmr2->balance = v4l2_ctrl_new_std(&tea->ctrl_handler, &fmr2_ctrl_ops, V4L2_CID_AUDIO_BALANCE, -68, 68, 2, 0);
if (tea->ctrl_handler.error) {
printk(KERN_ERR "radio-sf16fmr2: can't initialize contrls\n");
return tea->ctrl_handler.error;
}
}
return 0;
}
static int __init fmr2_init(void)
{
struct fmr2 *fmr2 = &fmr2_card;
fmr2->io = FMR2_PORT;
if (!request_region(fmr2->io, 2, "SF16-FMR2")) {
printk(KERN_ERR "radio-sf16fmr2: I/O port 0x%x already in use\n", fmr2->io);
return -EBUSY;
}
fmr2->tea.private_data = fmr2;
fmr2->tea.ops = &fmr2_tea_ops;
fmr2->tea.ext_init = fmr2_tea_ext_init;
strlcpy(fmr2->tea.card, "SF16-FMR2", sizeof(fmr2->tea.card));
strcpy(fmr2->tea.bus_info, "ISA");
if (snd_tea575x_init(&fmr2->tea)) {
printk(KERN_ERR "radio-sf16fmr2: Unable to detect TEA575x tuner\n");
release_region(fmr2->io, 2);
return -ENODEV;
}
printk(KERN_INFO "radio-sf16fmr2: SF16-FMR2 radio card at 0x%x.\n", fmr2->io);
return 0;
}
static void __exit fmr2_exit(void)
{
struct fmr2 *fmr2 = &fmr2_card;
snd_tea575x_exit(&fmr2->tea);
release_region(fmr2->io, 2);
}
