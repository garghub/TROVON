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
if (!fmr2->is_fmd2 && inb(fmr2->io) & FMR2_HASVOL) {
fmr2->volume = v4l2_ctrl_new_std(&tea->ctrl_handler, &fmr2_ctrl_ops, V4L2_CID_AUDIO_VOLUME, 0, 68, 2, 56);
fmr2->balance = v4l2_ctrl_new_std(&tea->ctrl_handler, &fmr2_ctrl_ops, V4L2_CID_AUDIO_BALANCE, -68, 68, 2, 0);
if (tea->ctrl_handler.error) {
printk(KERN_ERR "radio-sf16fmr2: can't initialize controls\n");
return tea->ctrl_handler.error;
}
}
return 0;
}
static int __devinit fmr2_probe(struct fmr2 *fmr2, struct device *pdev, int io)
{
int err, i;
char *card_name = fmr2->is_fmd2 ? "SF16-FMD2" : "SF16-FMR2";
for (i = 0; i < num_fmr2_cards; i++)
if (io == fmr2_cards[i]->io)
return -EBUSY;
strlcpy(fmr2->v4l2_dev.name, "radio-sf16fmr2",
sizeof(fmr2->v4l2_dev.name)),
fmr2->io = io;
if (!request_region(fmr2->io, 2, fmr2->v4l2_dev.name)) {
printk(KERN_ERR "radio-sf16fmr2: I/O port 0x%x already in use\n", fmr2->io);
return -EBUSY;
}
dev_set_drvdata(pdev, fmr2);
err = v4l2_device_register(pdev, &fmr2->v4l2_dev);
if (err < 0) {
v4l2_err(&fmr2->v4l2_dev, "Could not register v4l2_device\n");
release_region(fmr2->io, 2);
return err;
}
fmr2->tea.v4l2_dev = &fmr2->v4l2_dev;
fmr2->tea.private_data = fmr2;
fmr2->tea.radio_nr = radio_nr[num_fmr2_cards];
fmr2->tea.ops = &fmr2_tea_ops;
fmr2->tea.ext_init = fmr2_tea_ext_init;
strlcpy(fmr2->tea.card, card_name, sizeof(fmr2->tea.card));
snprintf(fmr2->tea.bus_info, sizeof(fmr2->tea.bus_info), "%s:%s",
fmr2->is_fmd2 ? "PnP" : "ISA", dev_name(pdev));
if (snd_tea575x_init(&fmr2->tea, THIS_MODULE)) {
printk(KERN_ERR "radio-sf16fmr2: Unable to detect TEA575x tuner\n");
release_region(fmr2->io, 2);
return -ENODEV;
}
printk(KERN_INFO "radio-sf16fmr2: %s radio card at 0x%x.\n",
card_name, fmr2->io);
return 0;
}
static int __devinit fmr2_isa_match(struct device *pdev, unsigned int ndev)
{
struct fmr2 *fmr2 = kzalloc(sizeof(*fmr2), GFP_KERNEL);
if (!fmr2)
return 0;
if (fmr2_probe(fmr2, pdev, FMR2_PORT)) {
kfree(fmr2);
return 0;
}
dev_set_drvdata(pdev, fmr2);
fmr2_cards[num_fmr2_cards++] = fmr2;
return 1;
}
static int __devinit fmr2_pnp_probe(struct pnp_dev *pdev,
const struct pnp_device_id *id)
{
int ret;
struct fmr2 *fmr2 = kzalloc(sizeof(*fmr2), GFP_KERNEL);
if (!fmr2)
return -ENOMEM;
fmr2->is_fmd2 = true;
ret = fmr2_probe(fmr2, &pdev->dev, pnp_port_start(pdev, 0));
if (ret) {
kfree(fmr2);
return ret;
}
pnp_set_drvdata(pdev, fmr2);
fmr2_cards[num_fmr2_cards++] = fmr2;
return 0;
}
static void __devexit fmr2_remove(struct fmr2 *fmr2)
{
snd_tea575x_exit(&fmr2->tea);
release_region(fmr2->io, 2);
v4l2_device_unregister(&fmr2->v4l2_dev);
kfree(fmr2);
}
static int __devexit fmr2_isa_remove(struct device *pdev, unsigned int ndev)
{
fmr2_remove(dev_get_drvdata(pdev));
dev_set_drvdata(pdev, NULL);
return 0;
}
static void __devexit fmr2_pnp_remove(struct pnp_dev *pdev)
{
fmr2_remove(pnp_get_drvdata(pdev));
pnp_set_drvdata(pdev, NULL);
}
static int __init fmr2_init(void)
{
int ret;
ret = pnp_register_driver(&fmr2_pnp_driver);
if (!ret)
pnp_registered = true;
ret = isa_register_driver(&fmr2_isa_driver, 1);
if (!ret)
isa_registered = true;
return (pnp_registered || isa_registered) ? 0 : ret;
}
static void __exit fmr2_exit(void)
{
if (pnp_registered)
pnp_unregister_driver(&fmr2_pnp_driver);
if (isa_registered)
isa_unregister_driver(&fmr2_isa_driver);
}
