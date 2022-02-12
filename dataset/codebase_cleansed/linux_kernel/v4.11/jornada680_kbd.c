static void jornada_parse_kbd(struct jornadakbd *jornadakbd)
{
struct input_dev *input_dev = jornadakbd->poll_dev->input;
unsigned short *keymap = jornadakbd->keymap;
unsigned int sync_me = 0;
unsigned int i, j;
for (i = 0; i < JORNADA_SCAN_SIZE; i++) {
unsigned char new = jornadakbd->new_scan[i];
unsigned char old = jornadakbd->old_scan[i];
unsigned int xor = new ^ old;
if (xor == 0)
continue;
for (j = 0; j < 8; j++) {
unsigned int bit = 1 << j;
if (xor & bit) {
unsigned int scancode = (i << 3) + j;
input_event(input_dev,
EV_MSC, MSC_SCAN, scancode);
input_report_key(input_dev,
keymap[scancode],
!(new & bit));
sync_me = 1;
}
}
}
if (sync_me)
input_sync(input_dev);
}
static void jornada_scan_keyb(unsigned char *s)
{
int i;
unsigned short ec_static, dc_static;
unsigned char matrix_switch[] = {
0xfd, 0xff,
0xdf, 0xff,
0x7f, 0xff,
0xff, 0xfe,
0xff, 0xfd,
0xff, 0xf7,
0xff, 0xbf,
0xff, 0x7f,
}, *t = matrix_switch;
unsigned short matrix_PDE[] = {
0xcc04, 0xf0cf,
0xc40c, 0xf0cf,
0x4c0c, 0xf0cf,
0xcc0c, 0xf0cd,
0xcc0c, 0xf0c7,
0xcc0c, 0xf04f,
0xcc0c, 0xd0cf,
0xcc0c, 0x70cf,
}, *y = matrix_PDE;
dc_static = (__raw_readw(PDCR) & (~0xcc0c));
ec_static = (__raw_readw(PECR) & (~0xf0cf));
for (i = 0; i < 8; i++) {
__raw_writew((dc_static | *y++), PDCR);
__raw_writew((ec_static | *y++), PECR);
udelay(5);
__raw_writeb(*t++, PDDR);
__raw_writeb(*t++, PEDR);
udelay(50);
*s++ = __raw_readb(PCDR);
*s++ = __raw_readb(PFDR);
}
__raw_writeb(0xff, PDDR);
__raw_writeb(0xff, PEDR);
__raw_writew((dc_static | (0x5555 & 0xcc0c)),PDCR);
__raw_writew((ec_static | (0x5555 & 0xf0cf)),PECR);
*s++ = __raw_readb(PGDR);
*s++ = __raw_readb(PHDR);
}
static void jornadakbd680_poll(struct input_polled_dev *dev)
{
struct jornadakbd *jornadakbd = dev->private;
jornada_scan_keyb(jornadakbd->new_scan);
jornada_parse_kbd(jornadakbd);
memcpy(jornadakbd->old_scan, jornadakbd->new_scan, JORNADA_SCAN_SIZE);
}
static int jornada680kbd_probe(struct platform_device *pdev)
{
struct jornadakbd *jornadakbd;
struct input_polled_dev *poll_dev;
struct input_dev *input_dev;
int i, error;
jornadakbd = devm_kzalloc(&pdev->dev, sizeof(struct jornadakbd),
GFP_KERNEL);
if (!jornadakbd)
return -ENOMEM;
poll_dev = devm_input_allocate_polled_device(&pdev->dev);
if (!poll_dev) {
dev_err(&pdev->dev, "failed to allocate polled input device\n");
return -ENOMEM;
}
jornadakbd->poll_dev = poll_dev;
memcpy(jornadakbd->keymap, jornada_scancodes,
sizeof(jornadakbd->keymap));
poll_dev->private = jornadakbd;
poll_dev->poll = jornadakbd680_poll;
poll_dev->poll_interval = 50;
input_dev = poll_dev->input;
input_dev->evbit[0] = BIT(EV_KEY) | BIT(EV_REP);
input_dev->name = "HP Jornada 680 keyboard";
input_dev->phys = "jornadakbd/input0";
input_dev->keycode = jornadakbd->keymap;
input_dev->keycodesize = sizeof(unsigned short);
input_dev->keycodemax = ARRAY_SIZE(jornada_scancodes);
input_dev->dev.parent = &pdev->dev;
input_dev->id.bustype = BUS_HOST;
for (i = 0; i < 128; i++)
if (jornadakbd->keymap[i])
__set_bit(jornadakbd->keymap[i], input_dev->keybit);
__clear_bit(KEY_RESERVED, input_dev->keybit);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
error = input_register_polled_device(jornadakbd->poll_dev);
if (error) {
dev_err(&pdev->dev, "failed to register polled input device\n");
return error;
}
return 0;
}
