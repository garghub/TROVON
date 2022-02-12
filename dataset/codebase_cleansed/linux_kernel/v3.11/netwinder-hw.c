static inline void wb977_open(void)
{
outb(0x87, 0x370);
outb(0x87, 0x370);
}
static inline void wb977_close(void)
{
outb(0xaa, 0x370);
}
static inline void wb977_wb(int reg, int val)
{
outb(reg, 0x370);
outb(val, 0x371);
}
static inline void wb977_ww(int reg, int val)
{
outb(reg, 0x370);
outb(val >> 8, 0x371);
outb(reg + 1, 0x370);
outb(val & 255, 0x371);
}
void nw_gpio_modify_op(unsigned int mask, unsigned int set)
{
unsigned int new_gpio, changed;
new_gpio = (current_gpio_op & ~mask) | set;
changed = new_gpio ^ current_gpio_op;
current_gpio_op = new_gpio;
if (changed & 0xff)
outb(new_gpio, GP1_IO_BASE);
if (changed & 0xff00)
outb(new_gpio >> 8, GP2_IO_BASE);
}
static inline void __gpio_modify_io(int mask, int in)
{
unsigned int new_gpio, changed;
int port;
new_gpio = (current_gpio_io & ~mask) | in;
changed = new_gpio ^ current_gpio_io;
current_gpio_io = new_gpio;
changed >>= 1;
new_gpio >>= 1;
wb977_device_select(7);
for (port = 0xe1; changed && port < 0xe8; changed >>= 1) {
wb977_wb(port, new_gpio & 1);
port += 1;
new_gpio >>= 1;
}
wb977_device_select(8);
for (port = 0xe8; changed && port < 0xec; changed >>= 1) {
wb977_wb(port, new_gpio & 1);
port += 1;
new_gpio >>= 1;
}
}
void nw_gpio_modify_io(unsigned int mask, unsigned int in)
{
wb977_open();
__gpio_modify_io(mask, in);
wb977_close();
}
unsigned int nw_gpio_read(void)
{
return inb(GP1_IO_BASE) | inb(GP2_IO_BASE) << 8;
}
static inline void wb977_init_global(void)
{
wb977_wb(0x26, 0x40);
wb977_wb(0x22, 0xfe);
wb977_wb(0x2a, 0xc1);
wb977_wb(0x2b, 0x6b);
wb977_wb(0x2c, 0x55);
}
static inline void wb977_init_printer(void)
{
wb977_device_select(1);
wb977_wb(0xf0, 0x01);
}
static inline void wb977_init_keyboard(void)
{
wb977_device_select(5);
wb977_ww(0x60, 0x0060);
wb977_ww(0x62, 0x0064);
wb977_wb(0x70, 1);
wb977_wb(0x71, 0x02);
wb977_wb(0x72, 5);
wb977_wb(0x73, 0x02);
wb977_wb(0xf0, 0x40);
wb977_device_enable();
}
static inline void wb977_init_irda(void)
{
wb977_device_select(6);
wb977_ww(0x60, IRDA_IO_BASE);
wb977_wb(0x70, 6);
wb977_wb(0x71, 0x02);
wb977_wb(0x74, 0x00);
wb977_wb(0x75, 0x04);
wb977_wb(0xf0, 0x03);
wb977_device_enable();
}
static inline void wb977_init_gpio(void)
{
unsigned long flags;
current_gpio_io = -1;
__gpio_modify_io(-1, GPIO_DONE | GPIO_WDTIMER);
wb977_device_select(7);
wb977_ww(0x60, GP1_IO_BASE);
wb977_ww(0x62, 0);
wb977_ww(0x64, 0);
wb977_wb(0x70, 10);
wb977_wb(0x71, 0x02);
wb977_wb(0xe0, 0x19);
wb977_device_enable();
wb977_device_select(8);
wb977_ww(0x60, GP2_IO_BASE);
wb977_wb(0xf2, 0x00);
wb977_wb(0xf3, 0x00);
wb977_wb(0xf4, 0x00);
wb977_device_enable();
raw_spin_lock_irqsave(&nw_gpio_lock, flags);
nw_gpio_modify_op(-1, GPIO_RED_LED | GPIO_FAN);
raw_spin_unlock_irqrestore(&nw_gpio_lock, flags);
}
static void __init wb977_init(void)
{
request_region(0x370, 2, "W83977AF configuration");
wb977_open();
wb977_init_global();
wb977_init_printer();
wb977_init_keyboard();
wb977_init_irda();
wb977_init_gpio();
wb977_close();
}
void nw_cpld_modify(unsigned int mask, unsigned int set)
{
int msk;
current_cpld = (current_cpld & ~mask) | set;
nw_gpio_modify_io(GPIO_DATA | GPIO_IOCLK | GPIO_IOLOAD, 0);
nw_gpio_modify_op(GPIO_IOLOAD, 0);
for (msk = 8; msk; msk >>= 1) {
int bit = current_cpld & msk;
nw_gpio_modify_op(GPIO_DATA | GPIO_IOCLK, bit ? GPIO_DATA : 0);
nw_gpio_modify_op(GPIO_IOCLK, GPIO_IOCLK);
}
nw_gpio_modify_op(GPIO_IOCLK|GPIO_DATA, 0);
nw_gpio_modify_op(GPIO_IOLOAD|GPIO_DSCLK, GPIO_IOLOAD|GPIO_DSCLK);
nw_gpio_modify_op(GPIO_IOLOAD, 0);
}
static void __init cpld_init(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&nw_gpio_lock, flags);
nw_cpld_modify(-1, CPLD_UNMUTE | CPLD_7111_DISABLE);
raw_spin_unlock_irqrestore(&nw_gpio_lock, flags);
}
static inline void rwa010_unlock(void)
{
int i;
WRITE_RWA(2, 2);
mdelay(10);
for (i = 0; i < sizeof(rwa_unlock); i++) {
outb(rwa_unlock[i], 0x279);
udelay(10);
}
}
static inline void rwa010_read_ident(void)
{
unsigned char si[9];
int i, j;
WRITE_RWA(3, 0);
WRITE_RWA(0, 128);
outb(1, 0x279);
mdelay(1);
dprintk("Identifier: ");
for (i = 0; i < 9; i++) {
si[i] = 0;
for (j = 0; j < 8; j++) {
int bit;
udelay(250);
inb(0x203);
udelay(250);
bit = inb(0x203);
dprintk("%02X ", bit);
bit = (bit == 0xaa) ? 1 : 0;
si[i] |= bit << j;
}
dprintk("(%02X) ", si[i]);
}
dprintk("\n");
}
static inline void rwa010_global_init(void)
{
WRITE_RWA(6, 2);
dprintk("Card no = %d\n", inb(0x203));
WRITE_RWA(7, 3);
WRITE_RWA(0x30, 0);
WRITE_RWA(7, 4);
WRITE_RWA(0x30, 0);
WRITE_RWA(7, 2);
WRITE_RWA(0x30, 0);
}
static inline void rwa010_game_port_init(void)
{
int i;
WRITE_RWA(7, 5);
dprintk("Slider base: ");
WRITE_RWA(0x61, 1);
i = inb(0x203);
WRITE_RWA(0x60, 2);
dprintk("%02X%02X (201)\n", inb(0x203), i);
WRITE_RWA(0x30, 1);
}
static inline void rwa010_waveartist_init(int base, int irq, int dma)
{
int i;
WRITE_RWA(7, 0);
dprintk("WaveArtist base: ");
WRITE_RWA(0x61, base & 255);
i = inb(0x203);
WRITE_RWA(0x60, base >> 8);
dprintk("%02X%02X (%X),", inb(0x203), i, base);
WRITE_RWA(0x70, irq);
dprintk(" irq: %d (%d),", inb(0x203), irq);
WRITE_RWA(0x74, dma);
dprintk(" dma: %d (%d)\n", inb(0x203), dma);
WRITE_RWA(0x30, 1);
}
static inline void rwa010_soundblaster_init(int sb_base, int al_base, int irq, int dma)
{
int i;
WRITE_RWA(7, 1);
dprintk("SoundBlaster base: ");
WRITE_RWA(0x61, sb_base & 255);
i = inb(0x203);
WRITE_RWA(0x60, sb_base >> 8);
dprintk("%02X%02X (%X),", inb(0x203), i, sb_base);
dprintk(" irq: ");
WRITE_RWA(0x70, irq);
dprintk("%d (%d),", inb(0x203), irq);
dprintk(" 8-bit DMA: ");
WRITE_RWA(0x74, dma);
dprintk("%d (%d)\n", inb(0x203), dma);
dprintk("AdLib base: ");
WRITE_RWA(0x63, al_base & 255);
i = inb(0x203);
WRITE_RWA(0x62, al_base >> 8);
dprintk("%02X%02X (%X)\n", inb(0x203), i, al_base);
WRITE_RWA(0x30, 1);
}
static void rwa010_soundblaster_reset(void)
{
int i;
outb(1, 0x226);
udelay(3);
outb(0, 0x226);
for (i = 0; i < 5; i++) {
if (inb(0x22e) & 0x80)
break;
mdelay(1);
}
if (i == 5)
printk("SoundBlaster: DSP reset failed\n");
dprintk("SoundBlaster DSP reset: %02X (AA)\n", inb(0x22a));
for (i = 0; i < 5; i++) {
if ((inb(0x22c) & 0x80) == 0)
break;
mdelay(1);
}
if (i == 5)
printk("SoundBlaster: DSP not ready\n");
else {
outb(0xe1, 0x22c);
dprintk("SoundBlaster DSP id: ");
i = inb(0x22a);
udelay(1);
i |= inb(0x22a) << 8;
dprintk("%04X\n", i);
for (i = 0; i < 5; i++) {
if ((inb(0x22c) & 0x80) == 0)
break;
mdelay(1);
}
if (i == 5)
printk("SoundBlaster: could not turn speaker off\n");
outb(0xd3, 0x22c);
}
outb(5, 0x38a);
outb(1, 0x38b);
}
static void __init rwa010_init(void)
{
rwa010_unlock();
rwa010_read_ident();
rwa010_global_init();
rwa010_game_port_init();
rwa010_waveartist_init(0x250, 3, 7);
rwa010_soundblaster_init(0x220, 0x388, 3, 1);
rwa010_soundblaster_reset();
}
static int __init nw_hw_init(void)
{
if (machine_is_netwinder()) {
wb977_init();
cpld_init();
rwa010_init();
}
return 0;
}
static void __init
fixup_netwinder(struct tag *tags, char **cmdline, struct meminfo *mi)
{
#ifdef CONFIG_ISAPNP
extern int isapnp_disable;
isapnp_disable = 1;
#endif
}
static void netwinder_restart(enum reboot_mode mode, const char *cmd)
{
if (mode == REBOOT_SOFT) {
soft_restart(0x41000000);
} else {
local_irq_disable();
local_fiq_disable();
outb(0x87, 0x370);
outb(0x87, 0x370);
outb(0x07, 0x370);
outb(0x07, 0x371);
outb(0xe6, 0x370);
outb(0x00, 0x371);
outb(0xc4, 0x338);
}
}
static void netwinder_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct netwinder_led *led = container_of(cdev,
struct netwinder_led, cdev);
unsigned long flags;
u32 reg;
spin_lock_irqsave(&nw_gpio_lock, flags);
reg = nw_gpio_read();
if (b != LED_OFF)
reg &= ~led->mask;
else
reg |= led->mask;
nw_gpio_modify_op(led->mask, reg);
spin_unlock_irqrestore(&nw_gpio_lock, flags);
}
static enum led_brightness netwinder_led_get(struct led_classdev *cdev)
{
struct netwinder_led *led = container_of(cdev,
struct netwinder_led, cdev);
unsigned long flags;
u32 reg;
spin_lock_irqsave(&nw_gpio_lock, flags);
reg = nw_gpio_read();
spin_unlock_irqrestore(&nw_gpio_lock, flags);
return (reg & led->mask) ? LED_OFF : LED_FULL;
}
static int __init netwinder_leds_init(void)
{
int i;
if (!machine_is_netwinder())
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(netwinder_leds); i++) {
struct netwinder_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->cdev.name = netwinder_leds[i].name;
led->cdev.brightness_set = netwinder_led_set;
led->cdev.brightness_get = netwinder_led_get;
led->cdev.default_trigger = netwinder_leds[i].trigger;
if (i == 0)
led->mask = GPIO_GREEN_LED;
else
led->mask = GPIO_RED_LED;
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
