static void pti_write_to_aperture(struct pti_masterchannel *mc,
u8 *buf,
int len)
{
int dwordcnt;
int final;
int i;
u32 ptiword;
u32 __iomem *aperture;
u8 *p = buf;
aperture = drv_data->pti_ioaddr + (mc->master << 15)
+ (mc->channel << 8);
dwordcnt = len >> 2;
final = len - (dwordcnt << 2);
if (final == 0 && dwordcnt != 0) {
final += 4;
dwordcnt--;
}
for (i = 0; i < dwordcnt; i++) {
ptiword = be32_to_cpu(*(u32 *)p);
p += 4;
iowrite32(ptiword, aperture);
}
aperture += PTI_LASTDWORD_DTS;
ptiword = 0;
for (i = 0; i < final; i++)
ptiword |= *p++ << (24-(8*i));
iowrite32(ptiword, aperture);
return;
}
static void pti_control_frame_built_and_sent(struct pti_masterchannel *mc,
const char *thread_name)
{
char comm[TASK_COMM_LEN];
struct pti_masterchannel mccontrol = {.master = CONTROL_ID,
.channel = 0};
const char *thread_name_p;
const char *control_format = "%3d %3d %s";
u8 control_frame[CONTROL_FRAME_LEN];
if (!thread_name) {
if (!in_interrupt())
get_task_comm(comm, current);
else
strncpy(comm, "Interrupt", TASK_COMM_LEN);
comm[TASK_COMM_LEN-1] = 0;
thread_name_p = comm;
} else {
thread_name_p = thread_name;
}
mccontrol.channel = pti_control_channel;
pti_control_channel = (pti_control_channel + 1) & 0x7f;
snprintf(control_frame, CONTROL_FRAME_LEN, control_format, mc->master,
mc->channel, thread_name_p);
pti_write_to_aperture(&mccontrol, control_frame, strlen(control_frame));
}
static void pti_write_full_frame_to_aperture(struct pti_masterchannel *mc,
const unsigned char *buf,
int len)
{
pti_control_frame_built_and_sent(mc, NULL);
pti_write_to_aperture(mc, (u8 *)buf, len);
}
static struct pti_masterchannel *get_id(u8 *id_array,
int max_ids,
int base_id,
const char *thread_name)
{
struct pti_masterchannel *mc;
int i, j, mask;
mc = kmalloc(sizeof(struct pti_masterchannel), GFP_KERNEL);
if (mc == NULL)
return NULL;
for (i = 0; i < max_ids; i++)
if (id_array[i] != 0xff)
break;
if (i == max_ids) {
kfree(mc);
return NULL;
}
mask = 0x80;
for (j = 0; j < 8; j++) {
if ((id_array[i] & mask) == 0)
break;
mask >>= 1;
}
id_array[i] |= mask;
mc->master = base_id;
mc->channel = ((i & 0xf)<<3) + j;
pti_control_frame_built_and_sent(mc, thread_name);
return mc;
}
struct pti_masterchannel *pti_request_masterchannel(u8 type,
const char *thread_name)
{
struct pti_masterchannel *mc;
mutex_lock(&alloclock);
switch (type) {
case 0:
mc = get_id(drv_data->ia_app, MAX_APP_IDS,
APP_BASE_ID, thread_name);
break;
case 1:
mc = get_id(drv_data->ia_os, MAX_OS_IDS,
OS_BASE_ID, thread_name);
break;
case 2:
mc = get_id(drv_data->ia_modem, MAX_MODEM_IDS,
MODEM_BASE_ID, thread_name);
break;
default:
mc = NULL;
}
mutex_unlock(&alloclock);
return mc;
}
void pti_release_masterchannel(struct pti_masterchannel *mc)
{
u8 master, channel, i;
mutex_lock(&alloclock);
if (mc) {
master = mc->master;
channel = mc->channel;
if (master == APP_BASE_ID) {
i = channel >> 3;
drv_data->ia_app[i] &= ~(0x80>>(channel & 0x7));
} else if (master == OS_BASE_ID) {
i = channel >> 3;
drv_data->ia_os[i] &= ~(0x80>>(channel & 0x7));
} else {
i = channel >> 3;
drv_data->ia_modem[i] &= ~(0x80>>(channel & 0x7));
}
kfree(mc);
}
mutex_unlock(&alloclock);
}
void pti_writedata(struct pti_masterchannel *mc, u8 *buf, int count)
{
if ((mc != NULL) && (buf != NULL) && (count > 0))
pti_write_to_aperture(mc, buf, count);
return;
}
static int pti_tty_driver_open(struct tty_struct *tty, struct file *filp)
{
return tty_port_open(tty->port, tty, filp);
}
static void pti_tty_driver_close(struct tty_struct *tty, struct file *filp)
{
tty_port_close(tty->port, tty, filp);
}
static int pti_tty_install(struct tty_driver *driver, struct tty_struct *tty)
{
int idx = tty->index;
struct pti_tty *pti_tty_data;
int ret = tty_standard_install(driver, tty);
if (ret == 0) {
pti_tty_data = kmalloc(sizeof(struct pti_tty), GFP_KERNEL);
if (pti_tty_data == NULL)
return -ENOMEM;
if (idx == PTITTY_MINOR_START)
pti_tty_data->mc = pti_request_masterchannel(0, NULL);
else
pti_tty_data->mc = pti_request_masterchannel(2, NULL);
if (pti_tty_data->mc == NULL) {
kfree(pti_tty_data);
return -ENXIO;
}
tty->driver_data = pti_tty_data;
}
return ret;
}
static void pti_tty_cleanup(struct tty_struct *tty)
{
struct pti_tty *pti_tty_data = tty->driver_data;
if (pti_tty_data == NULL)
return;
pti_release_masterchannel(pti_tty_data->mc);
kfree(pti_tty_data);
tty->driver_data = NULL;
}
static int pti_tty_driver_write(struct tty_struct *tty,
const unsigned char *buf, int len)
{
struct pti_tty *pti_tty_data = tty->driver_data;
if ((pti_tty_data != NULL) && (pti_tty_data->mc != NULL)) {
pti_write_to_aperture(pti_tty_data->mc, (u8 *)buf, len);
return len;
}
else
return -EFAULT;
}
static int pti_tty_write_room(struct tty_struct *tty)
{
return 2048;
}
static int pti_char_open(struct inode *inode, struct file *filp)
{
struct pti_masterchannel *mc;
mc = pti_request_masterchannel(0, NULL);
if (mc == NULL)
return -ENOMEM;
filp->private_data = mc;
return 0;
}
static int pti_char_release(struct inode *inode, struct file *filp)
{
pti_release_masterchannel(filp->private_data);
filp->private_data = NULL;
return 0;
}
static ssize_t pti_char_write(struct file *filp, const char __user *data,
size_t len, loff_t *ppose)
{
struct pti_masterchannel *mc;
void *kbuf;
const char __user *tmp;
size_t size = USER_COPY_SIZE;
size_t n = 0;
tmp = data;
mc = filp->private_data;
kbuf = kmalloc(size, GFP_KERNEL);
if (kbuf == NULL) {
pr_err("%s(%d): buf allocation failed\n",
__func__, __LINE__);
return -ENOMEM;
}
do {
if (len - n > USER_COPY_SIZE)
size = USER_COPY_SIZE;
else
size = len - n;
if (copy_from_user(kbuf, tmp, size)) {
kfree(kbuf);
return n ? n : -EFAULT;
}
pti_write_to_aperture(mc, kbuf, size);
n += size;
tmp += size;
} while (len > n);
kfree(kbuf);
return len;
}
static void pti_console_write(struct console *c, const char *buf, unsigned len)
{
static struct pti_masterchannel mc = {.master = CONSOLE_ID,
.channel = 0};
mc.channel = pti_console_channel;
pti_console_channel = (pti_console_channel + 1) & 0x7f;
pti_write_full_frame_to_aperture(&mc, buf, len);
}
static struct tty_driver *pti_console_device(struct console *c, int *index)
{
*index = c->index;
return pti_tty_driver;
}
static int pti_console_setup(struct console *c, char *opts)
{
pti_console_channel = 0;
pti_control_channel = 0;
return 0;
}
static int pti_port_activate(struct tty_port *port, struct tty_struct *tty)
{
if (port->tty->index == PTITTY_MINOR_START)
console_start(&pti_console);
return 0;
}
static void pti_port_shutdown(struct tty_port *port)
{
if (port->tty->index == PTITTY_MINOR_START)
console_stop(&pti_console);
}
static int __devinit pti_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned int a;
int retval = -EINVAL;
int pci_bar = 1;
dev_dbg(&pdev->dev, "%s %s(%d): PTI PCI ID %04x:%04x\n", __FILE__,
__func__, __LINE__, pdev->vendor, pdev->device);
retval = misc_register(&pti_char_driver);
if (retval) {
pr_err("%s(%d): CHAR registration failed of pti driver\n",
__func__, __LINE__);
pr_err("%s(%d): Error value returned: %d\n",
__func__, __LINE__, retval);
goto err;
}
retval = pci_enable_device(pdev);
if (retval != 0) {
dev_err(&pdev->dev,
"%s: pci_enable_device() returned error %d\n",
__func__, retval);
goto err_unreg_misc;
}
drv_data = kzalloc(sizeof(*drv_data), GFP_KERNEL);
if (drv_data == NULL) {
retval = -ENOMEM;
dev_err(&pdev->dev,
"%s(%d): kmalloc() returned NULL memory.\n",
__func__, __LINE__);
goto err_disable_pci;
}
drv_data->pti_addr = pci_resource_start(pdev, pci_bar);
retval = pci_request_region(pdev, pci_bar, dev_name(&pdev->dev));
if (retval != 0) {
dev_err(&pdev->dev,
"%s(%d): pci_request_region() returned error %d\n",
__func__, __LINE__, retval);
goto err_free_dd;
}
drv_data->aperture_base = drv_data->pti_addr+APERTURE_14;
drv_data->pti_ioaddr =
ioremap_nocache((u32)drv_data->aperture_base,
APERTURE_LEN);
if (!drv_data->pti_ioaddr) {
retval = -ENOMEM;
goto err_rel_reg;
}
pci_set_drvdata(pdev, drv_data);
for (a = 0; a < PTITTY_MINOR_NUM; a++) {
struct tty_port *port = &drv_data->port[a];
tty_port_init(port);
port->ops = &tty_port_ops;
tty_port_register_device(port, pti_tty_driver, a, &pdev->dev);
}
register_console(&pti_console);
return 0;
err_rel_reg:
pci_release_region(pdev, pci_bar);
err_free_dd:
kfree(drv_data);
err_disable_pci:
pci_disable_device(pdev);
err_unreg_misc:
misc_deregister(&pti_char_driver);
err:
return retval;
}
static void __devexit pti_pci_remove(struct pci_dev *pdev)
{
struct pti_dev *drv_data = pci_get_drvdata(pdev);
unregister_console(&pti_console);
tty_unregister_device(pti_tty_driver, 0);
tty_unregister_device(pti_tty_driver, 1);
iounmap(drv_data->pti_ioaddr);
pci_set_drvdata(pdev, NULL);
kfree(drv_data);
pci_release_region(pdev, 1);
pci_disable_device(pdev);
misc_deregister(&pti_char_driver);
}
static int __init pti_init(void)
{
int retval = -EINVAL;
pti_tty_driver = alloc_tty_driver(PTITTY_MINOR_NUM);
if (pti_tty_driver == NULL) {
pr_err("%s(%d): Memory allocation failed for ptiTTY driver\n",
__func__, __LINE__);
return -ENOMEM;
}
pti_tty_driver->driver_name = DRIVERNAME;
pti_tty_driver->name = TTYNAME;
pti_tty_driver->major = 0;
pti_tty_driver->minor_start = PTITTY_MINOR_START;
pti_tty_driver->type = TTY_DRIVER_TYPE_SYSTEM;
pti_tty_driver->subtype = SYSTEM_TYPE_SYSCONS;
pti_tty_driver->flags = TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV;
pti_tty_driver->init_termios = tty_std_termios;
tty_set_operations(pti_tty_driver, &pti_tty_driver_ops);
retval = tty_register_driver(pti_tty_driver);
if (retval) {
pr_err("%s(%d): TTY registration failed of pti driver\n",
__func__, __LINE__);
pr_err("%s(%d): Error value returned: %d\n",
__func__, __LINE__, retval);
goto put_tty;
}
retval = pci_register_driver(&pti_pci_driver);
if (retval) {
pr_err("%s(%d): PCI registration failed of pti driver\n",
__func__, __LINE__);
pr_err("%s(%d): Error value returned: %d\n",
__func__, __LINE__, retval);
goto unreg_tty;
}
return 0;
unreg_tty:
tty_unregister_driver(pti_tty_driver);
put_tty:
put_tty_driver(pti_tty_driver);
pti_tty_driver = NULL;
return retval;
}
static void __exit pti_exit(void)
{
tty_unregister_driver(pti_tty_driver);
pci_unregister_driver(&pti_pci_driver);
put_tty_driver(pti_tty_driver);
}
