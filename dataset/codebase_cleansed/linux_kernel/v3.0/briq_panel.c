static void update_vfd(void)
{
int i;
outb(0x02, BRIQ_PANEL_VFD_IOPORT);
for (i=0; i<20; i++)
outb(vfd[i], BRIQ_PANEL_VFD_IOPORT + 1);
outb(0xc0, BRIQ_PANEL_VFD_IOPORT);
for (i=20; i<40; i++)
outb(vfd[i], BRIQ_PANEL_VFD_IOPORT + 1);
}
static void set_led(char state)
{
if (state == 'R')
led = 0x01;
else if (state == 'G')
led = 0x02;
else if (state == 'Y')
led = 0x03;
else if (state == 'X')
led = 0x00;
outb(led, BRIQ_PANEL_LED_IOPORT);
}
static int briq_panel_open(struct inode *ino, struct file *filep)
{
tty_lock();
if (vfd_is_open) {
tty_unlock();
return -EBUSY;
}
vfd_is_open = 1;
tty_unlock();
return 0;
}
static int briq_panel_release(struct inode *ino, struct file *filep)
{
if (!vfd_is_open)
return -ENODEV;
vfd_is_open = 0;
return 0;
}
static ssize_t briq_panel_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
unsigned short c;
unsigned char cp;
if (!vfd_is_open)
return -ENODEV;
c = (inb(BRIQ_PANEL_LED_IOPORT) & 0x000c) | (ledpb & 0x0003);
set_led(' ');
if ((!(ledpb & 0x0004)) && (c & 0x0004)) {
cp = ' ';
ledpb = c;
if (copy_to_user(buf, &cp, 1))
return -EFAULT;
return 1;
}
else if ((!(ledpb & 0x0008)) && (c & 0x0008)) {
cp = '\r';
ledpb = c;
if (copy_to_user(buf, &cp, 1))
return -EFAULT;
return 1;
} else {
ledpb = c;
return 0;
}
}
static void scroll_vfd( void )
{
int i;
for (i=0; i<20; i++) {
vfd[i] = vfd[i+20];
vfd[i+20] = ' ';
}
vfd_cursor = 20;
}
static ssize_t briq_panel_write(struct file *file, const char __user *buf, size_t len,
loff_t *ppos)
{
size_t indx = len;
int i, esc = 0;
if (!vfd_is_open)
return -EBUSY;
for (;;) {
char c;
if (!indx)
break;
if (get_user(c, buf))
return -EFAULT;
if (esc) {
set_led(c);
esc = 0;
} else if (c == 27) {
esc = 1;
} else if (c == 12) {
for (i=0; i<40; i++)
vfd[i] = ' ';
vfd_cursor = 0;
} else if (c == 10) {
if (vfd_cursor < 20)
vfd_cursor = 20;
else if (vfd_cursor < 40)
vfd_cursor = 40;
else if (vfd_cursor < 60)
vfd_cursor = 60;
if (vfd_cursor > 59)
scroll_vfd();
} else {
if (vfd_cursor > 39)
scroll_vfd();
vfd[vfd_cursor++] = c;
}
indx--;
buf++;
}
update_vfd();
return len;
}
static int __init briq_panel_init(void)
{
struct device_node *root = of_find_node_by_path("/");
const char *machine;
int i;
machine = of_get_property(root, "model", NULL);
if (!machine || strncmp(machine, "TotalImpact,BRIQ-1", 18) != 0) {
of_node_put(root);
return -ENODEV;
}
of_node_put(root);
printk(KERN_INFO
"briq_panel: v%s Dr. Karsten Jeppesen (kj@totalimpact.com)\n",
BRIQ_PANEL_VER);
if (!request_region(BRIQ_PANEL_VFD_IOPORT, 4, "BRIQ Front Panel"))
return -EBUSY;
if (!request_region(BRIQ_PANEL_LED_IOPORT, 2, "BRIQ Front Panel")) {
release_region(BRIQ_PANEL_VFD_IOPORT, 4);
return -EBUSY;
}
ledpb = inb(BRIQ_PANEL_LED_IOPORT) & 0x000c;
if (misc_register(&briq_panel_miscdev) < 0) {
release_region(BRIQ_PANEL_VFD_IOPORT, 4);
release_region(BRIQ_PANEL_LED_IOPORT, 2);
return -EBUSY;
}
outb(0x38, BRIQ_PANEL_VFD_IOPORT);
outb(0x01, BRIQ_PANEL_VFD_IOPORT);
outb(0x0c, BRIQ_PANEL_VFD_IOPORT);
outb(0x06, BRIQ_PANEL_VFD_IOPORT);
for (i=0; i<40; i++)
vfd[i]=' ';
#ifndef MODULE
vfd[0] = 'L';
vfd[1] = 'o';
vfd[2] = 'a';
vfd[3] = 'd';
vfd[4] = 'i';
vfd[5] = 'n';
vfd[6] = 'g';
vfd[7] = ' ';
vfd[8] = '.';
vfd[9] = '.';
vfd[10] = '.';
#endif
update_vfd();
return 0;
}
static void __exit briq_panel_exit(void)
{
misc_deregister(&briq_panel_miscdev);
release_region(BRIQ_PANEL_VFD_IOPORT, 4);
release_region(BRIQ_PANEL_LED_IOPORT, 2);
}
