static struct radio_isa_card *terratec_alloc(void)
{
return kzalloc(sizeof(struct radio_isa_card), GFP_KERNEL);
}
static int terratec_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
int i;
if (mute)
vol = 0;
vol = vol + (vol * 32);
for (i = 0; i < 8; i++) {
if (vol & (0x80 >> i))
outb(0x80, isa->io + 1);
else
outb(0x00, isa->io + 1);
}
return 0;
}
static int terratec_s_frequency(struct radio_isa_card *isa, u32 freq)
{
int i;
int p;
int temp;
long rest;
unsigned char buffer[25];
freq = freq / 160;
memset(buffer, 0, sizeof(buffer));
rest = freq * 10 + 10700;
i = 13;
p = 10;
temp = 102400;
while (rest != 0) {
if (rest % temp == rest)
buffer[i] = 0;
else {
buffer[i] = 1;
rest = rest - temp;
}
i--;
p--;
temp = temp / 2;
}
for (i = 24; i > -1; i--) {
if (buffer[i] == 1) {
outb(WRT_EN | DATA, isa->io);
outb(WRT_EN | DATA | CLK_ON, isa->io);
outb(WRT_EN | DATA, isa->io);
} else {
outb(WRT_EN | 0x00, isa->io);
outb(WRT_EN | 0x00 | CLK_ON, isa->io);
}
}
outb(0x00, isa->io);
return 0;
}
static u32 terratec_g_signal(struct radio_isa_card *isa)
{
return (inb(isa->io) & 2) ? 0 : 0xffff;
}
static int __init terratec_init(void)
{
return isa_register_driver(&terratec_driver.driver, 1);
}
static void __exit terratec_exit(void)
{
isa_unregister_driver(&terratec_driver.driver);
}
