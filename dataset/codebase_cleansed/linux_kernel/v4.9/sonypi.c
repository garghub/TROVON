static int sonypi_ec_write(u8 addr, u8 value)
{
#ifdef CONFIG_ACPI
if (SONYPI_ACPI_ACTIVE)
return ec_write(addr, value);
#endif
wait_on_command(1, inb_p(SONYPI_CST_IOPORT) & 3, ITERATIONS_LONG);
outb_p(0x81, SONYPI_CST_IOPORT);
wait_on_command(0, inb_p(SONYPI_CST_IOPORT) & 2, ITERATIONS_LONG);
outb_p(addr, SONYPI_DATA_IOPORT);
wait_on_command(0, inb_p(SONYPI_CST_IOPORT) & 2, ITERATIONS_LONG);
outb_p(value, SONYPI_DATA_IOPORT);
wait_on_command(0, inb_p(SONYPI_CST_IOPORT) & 2, ITERATIONS_LONG);
return 0;
}
static int sonypi_ec_read(u8 addr, u8 *value)
{
#ifdef CONFIG_ACPI
if (SONYPI_ACPI_ACTIVE)
return ec_read(addr, value);
#endif
wait_on_command(1, inb_p(SONYPI_CST_IOPORT) & 3, ITERATIONS_LONG);
outb_p(0x80, SONYPI_CST_IOPORT);
wait_on_command(0, inb_p(SONYPI_CST_IOPORT) & 2, ITERATIONS_LONG);
outb_p(addr, SONYPI_DATA_IOPORT);
wait_on_command(0, inb_p(SONYPI_CST_IOPORT) & 2, ITERATIONS_LONG);
*value = inb_p(SONYPI_DATA_IOPORT);
return 0;
}
static int ec_read16(u8 addr, u16 *value)
{
u8 val_lb, val_hb;
if (sonypi_ec_read(addr, &val_lb))
return -1;
if (sonypi_ec_read(addr + 1, &val_hb))
return -1;
*value = val_lb | (val_hb << 8);
return 0;
}
static void sonypi_type1_srs(void)
{
u32 v;
pci_read_config_dword(sonypi_device.dev, SONYPI_G10A, &v);
v = (v & 0xFFFF0000) | ((u32) sonypi_device.ioport1);
pci_write_config_dword(sonypi_device.dev, SONYPI_G10A, v);
pci_read_config_dword(sonypi_device.dev, SONYPI_G10A, &v);
v = (v & 0xFFF0FFFF) |
(((u32) sonypi_device.ioport1 ^ sonypi_device.ioport2) << 16);
pci_write_config_dword(sonypi_device.dev, SONYPI_G10A, v);
v = inl(SONYPI_IRQ_PORT);
v &= ~(((u32) 0x3) << SONYPI_IRQ_SHIFT);
v |= (((u32) sonypi_device.bits) << SONYPI_IRQ_SHIFT);
outl(v, SONYPI_IRQ_PORT);
pci_read_config_dword(sonypi_device.dev, SONYPI_G10A, &v);
v = (v & 0xFF1FFFFF) | 0x00C00000;
pci_write_config_dword(sonypi_device.dev, SONYPI_G10A, v);
}
static void sonypi_type2_srs(void)
{
if (sonypi_ec_write(SONYPI_SHIB, (sonypi_device.ioport1 & 0xFF00) >> 8))
printk(KERN_WARNING "ec_write failed\n");
if (sonypi_ec_write(SONYPI_SLOB, sonypi_device.ioport1 & 0x00FF))
printk(KERN_WARNING "ec_write failed\n");
if (sonypi_ec_write(SONYPI_SIRQ, sonypi_device.bits))
printk(KERN_WARNING "ec_write failed\n");
udelay(10);
}
static void sonypi_type3_srs(void)
{
u16 v16;
u8 v8;
sonypi_type2_srs();
v16 = (sonypi_device.ioport1 & 0xFFF0) | 0x01;
pci_write_config_word(sonypi_device.dev, SONYPI_TYPE3_GID2, v16);
pci_read_config_byte(sonypi_device.dev, SONYPI_TYPE3_MISC, &v8);
v8 = (v8 & 0xCF) | 0x10;
pci_write_config_byte(sonypi_device.dev, SONYPI_TYPE3_MISC, v8);
}
static void sonypi_type1_dis(void)
{
u32 v;
pci_read_config_dword(sonypi_device.dev, SONYPI_G10A, &v);
v = v & 0xFF3FFFFF;
pci_write_config_dword(sonypi_device.dev, SONYPI_G10A, v);
v = inl(SONYPI_IRQ_PORT);
v |= (0x3 << SONYPI_IRQ_SHIFT);
outl(v, SONYPI_IRQ_PORT);
}
static void sonypi_type2_dis(void)
{
if (sonypi_ec_write(SONYPI_SHIB, 0))
printk(KERN_WARNING "ec_write failed\n");
if (sonypi_ec_write(SONYPI_SLOB, 0))
printk(KERN_WARNING "ec_write failed\n");
if (sonypi_ec_write(SONYPI_SIRQ, 0))
printk(KERN_WARNING "ec_write failed\n");
}
static void sonypi_type3_dis(void)
{
sonypi_type2_dis();
udelay(10);
pci_write_config_word(sonypi_device.dev, SONYPI_TYPE3_GID2, 0);
}
static u8 sonypi_call1(u8 dev)
{
u8 v1, v2;
wait_on_command(0, inb_p(sonypi_device.ioport2) & 2, ITERATIONS_LONG);
outb(dev, sonypi_device.ioport2);
v1 = inb_p(sonypi_device.ioport2);
v2 = inb_p(sonypi_device.ioport1);
return v2;
}
static u8 sonypi_call2(u8 dev, u8 fn)
{
u8 v1;
wait_on_command(0, inb_p(sonypi_device.ioport2) & 2, ITERATIONS_LONG);
outb(dev, sonypi_device.ioport2);
wait_on_command(0, inb_p(sonypi_device.ioport2) & 2, ITERATIONS_LONG);
outb(fn, sonypi_device.ioport1);
v1 = inb_p(sonypi_device.ioport1);
return v1;
}
static u8 sonypi_call3(u8 dev, u8 fn, u8 v)
{
u8 v1;
wait_on_command(0, inb_p(sonypi_device.ioport2) & 2, ITERATIONS_LONG);
outb(dev, sonypi_device.ioport2);
wait_on_command(0, inb_p(sonypi_device.ioport2) & 2, ITERATIONS_LONG);
outb(fn, sonypi_device.ioport1);
wait_on_command(0, inb_p(sonypi_device.ioport2) & 2, ITERATIONS_LONG);
outb(v, sonypi_device.ioport1);
v1 = inb_p(sonypi_device.ioport1);
return v1;
}
static void sonypi_set(u8 fn, u8 v)
{
wait_on_command(0, sonypi_call3(0x90, fn, v), ITERATIONS_SHORT);
}
static int sonypi_camera_ready(void)
{
u8 v;
v = sonypi_call2(0x8f, SONYPI_CAMERA_STATUS);
return (v != 0xff && (v & SONYPI_CAMERA_STATUS_READY));
}
static void sonypi_camera_off(void)
{
sonypi_set(SONYPI_CAMERA_PICTURE, SONYPI_CAMERA_MUTE_MASK);
if (!sonypi_device.camera_power)
return;
sonypi_call2(0x91, 0);
sonypi_device.camera_power = 0;
}
static void sonypi_camera_on(void)
{
int i, j;
if (sonypi_device.camera_power)
return;
for (j = 5; j > 0; j--) {
while (sonypi_call2(0x91, 0x1))
msleep(10);
sonypi_call1(0x93);
for (i = 400; i > 0; i--) {
if (sonypi_camera_ready())
break;
msleep(10);
}
if (i)
break;
}
if (j == 0) {
printk(KERN_WARNING "sonypi: failed to power on camera\n");
return;
}
sonypi_set(0x10, 0x5a);
sonypi_device.camera_power = 1;
}
static void sonypi_setbluetoothpower(u8 state)
{
state = !!state;
if (sonypi_device.bluetooth_power == state)
return;
sonypi_call2(0x96, state);
sonypi_call1(0x82);
sonypi_device.bluetooth_power = state;
}
static void input_keyrelease(struct work_struct *work)
{
struct sonypi_keypress kp;
while (kfifo_out_locked(&sonypi_device.input_fifo, (unsigned char *)&kp,
sizeof(kp), &sonypi_device.input_fifo_lock)
== sizeof(kp)) {
msleep(10);
input_report_key(kp.dev, kp.key, 0);
input_sync(kp.dev);
}
}
static void sonypi_report_input_event(u8 event)
{
struct input_dev *jog_dev = sonypi_device.input_jog_dev;
struct input_dev *key_dev = sonypi_device.input_key_dev;
struct sonypi_keypress kp = { NULL };
int i;
switch (event) {
case SONYPI_EVENT_JOGDIAL_UP:
case SONYPI_EVENT_JOGDIAL_UP_PRESSED:
input_report_rel(jog_dev, REL_WHEEL, 1);
input_sync(jog_dev);
break;
case SONYPI_EVENT_JOGDIAL_DOWN:
case SONYPI_EVENT_JOGDIAL_DOWN_PRESSED:
input_report_rel(jog_dev, REL_WHEEL, -1);
input_sync(jog_dev);
break;
case SONYPI_EVENT_JOGDIAL_PRESSED:
kp.key = BTN_MIDDLE;
kp.dev = jog_dev;
break;
case SONYPI_EVENT_FNKEY_RELEASED:
break;
default:
for (i = 0; sonypi_inputkeys[i].sonypiev; i++)
if (event == sonypi_inputkeys[i].sonypiev) {
kp.dev = key_dev;
kp.key = sonypi_inputkeys[i].inputev;
break;
}
break;
}
if (kp.dev) {
input_report_key(kp.dev, kp.key, 1);
input_sync(kp.dev);
kfifo_in_locked(&sonypi_device.input_fifo,
(unsigned char *)&kp, sizeof(kp),
&sonypi_device.input_fifo_lock);
schedule_work(&sonypi_device.input_work);
}
}
static irqreturn_t sonypi_irq(int irq, void *dev_id)
{
u8 v1, v2, event = 0;
int i, j;
v1 = inb_p(sonypi_device.ioport1);
v2 = inb_p(sonypi_device.ioport1 + sonypi_device.evtype_offset);
for (i = 0; sonypi_eventtypes[i].model; i++) {
if (sonypi_device.model != sonypi_eventtypes[i].model)
continue;
if ((v2 & sonypi_eventtypes[i].data) !=
sonypi_eventtypes[i].data)
continue;
if (!(mask & sonypi_eventtypes[i].mask))
continue;
for (j = 0; sonypi_eventtypes[i].events[j].event; j++) {
if (v1 == sonypi_eventtypes[i].events[j].data) {
event = sonypi_eventtypes[i].events[j].event;
goto found;
}
}
}
if (verbose)
printk(KERN_WARNING
"sonypi: unknown event port1=0x%02x,port2=0x%02x\n",
v1, v2);
return IRQ_HANDLED;
found:
if (verbose > 1)
printk(KERN_INFO
"sonypi: event port1=0x%02x,port2=0x%02x\n", v1, v2);
if (useinput)
sonypi_report_input_event(event);
kfifo_in_locked(&sonypi_device.fifo, (unsigned char *)&event,
sizeof(event), &sonypi_device.fifo_lock);
kill_fasync(&sonypi_device.fifo_async, SIGIO, POLL_IN);
wake_up_interruptible(&sonypi_device.fifo_proc_list);
return IRQ_HANDLED;
}
static int sonypi_misc_fasync(int fd, struct file *filp, int on)
{
return fasync_helper(fd, filp, on, &sonypi_device.fifo_async);
}
static int sonypi_misc_release(struct inode *inode, struct file *file)
{
mutex_lock(&sonypi_device.lock);
sonypi_device.open_count--;
mutex_unlock(&sonypi_device.lock);
return 0;
}
static int sonypi_misc_open(struct inode *inode, struct file *file)
{
mutex_lock(&sonypi_device.lock);
if (!sonypi_device.open_count)
kfifo_reset(&sonypi_device.fifo);
sonypi_device.open_count++;
mutex_unlock(&sonypi_device.lock);
return 0;
}
static ssize_t sonypi_misc_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
ssize_t ret;
unsigned char c;
if ((kfifo_len(&sonypi_device.fifo) == 0) &&
(file->f_flags & O_NONBLOCK))
return -EAGAIN;
ret = wait_event_interruptible(sonypi_device.fifo_proc_list,
kfifo_len(&sonypi_device.fifo) != 0);
if (ret)
return ret;
while (ret < count &&
(kfifo_out_locked(&sonypi_device.fifo, &c, sizeof(c),
&sonypi_device.fifo_lock) == sizeof(c))) {
if (put_user(c, buf++))
return -EFAULT;
ret++;
}
if (ret > 0) {
struct inode *inode = file_inode(file);
inode->i_atime = current_time(inode);
}
return ret;
}
static unsigned int sonypi_misc_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &sonypi_device.fifo_proc_list, wait);
if (kfifo_len(&sonypi_device.fifo))
return POLLIN | POLLRDNORM;
return 0;
}
static long sonypi_misc_ioctl(struct file *fp,
unsigned int cmd, unsigned long arg)
{
long ret = 0;
void __user *argp = (void __user *)arg;
u8 val8;
u16 val16;
mutex_lock(&sonypi_device.lock);
switch (cmd) {
case SONYPI_IOCGBRT:
if (sonypi_ec_read(SONYPI_LCD_LIGHT, &val8)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCSBRT:
if (copy_from_user(&val8, argp, sizeof(val8))) {
ret = -EFAULT;
break;
}
if (sonypi_ec_write(SONYPI_LCD_LIGHT, val8))
ret = -EIO;
break;
case SONYPI_IOCGBAT1CAP:
if (ec_read16(SONYPI_BAT1_FULL, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBAT1REM:
if (ec_read16(SONYPI_BAT1_LEFT, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBAT2CAP:
if (ec_read16(SONYPI_BAT2_FULL, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBAT2REM:
if (ec_read16(SONYPI_BAT2_LEFT, &val16)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val16, sizeof(val16)))
ret = -EFAULT;
break;
case SONYPI_IOCGBATFLAGS:
if (sonypi_ec_read(SONYPI_BAT_FLAGS, &val8)) {
ret = -EIO;
break;
}
val8 &= 0x07;
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCGBLUE:
val8 = sonypi_device.bluetooth_power;
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCSBLUE:
if (copy_from_user(&val8, argp, sizeof(val8))) {
ret = -EFAULT;
break;
}
sonypi_setbluetoothpower(val8);
break;
case SONYPI_IOCGFAN:
if (sonypi_ec_read(SONYPI_FAN0_STATUS, &val8)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
case SONYPI_IOCSFAN:
if (copy_from_user(&val8, argp, sizeof(val8))) {
ret = -EFAULT;
break;
}
if (sonypi_ec_write(SONYPI_FAN0_STATUS, val8))
ret = -EIO;
break;
case SONYPI_IOCGTEMP:
if (sonypi_ec_read(SONYPI_TEMP_STATUS, &val8)) {
ret = -EIO;
break;
}
if (copy_to_user(argp, &val8, sizeof(val8)))
ret = -EFAULT;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&sonypi_device.lock);
return ret;
}
static void sonypi_enable(unsigned int camera_on)
{
switch (sonypi_device.model) {
case SONYPI_DEVICE_MODEL_TYPE1:
sonypi_type1_srs();
break;
case SONYPI_DEVICE_MODEL_TYPE2:
sonypi_type2_srs();
break;
case SONYPI_DEVICE_MODEL_TYPE3:
sonypi_type3_srs();
break;
}
sonypi_call1(0x82);
sonypi_call2(0x81, 0xff);
sonypi_call1(compat ? 0x92 : 0x82);
if (!SONYPI_ACPI_ACTIVE && fnkeyinit)
outb(0xf0, 0xb2);
if (camera && camera_on)
sonypi_camera_on();
}
static int sonypi_disable(void)
{
sonypi_call2(0x81, 0);
if (camera)
sonypi_camera_off();
if (!SONYPI_ACPI_ACTIVE && fnkeyinit)
outb(0xf1, 0xb2);
switch (sonypi_device.model) {
case SONYPI_DEVICE_MODEL_TYPE1:
sonypi_type1_dis();
break;
case SONYPI_DEVICE_MODEL_TYPE2:
sonypi_type2_dis();
break;
case SONYPI_DEVICE_MODEL_TYPE3:
sonypi_type3_dis();
break;
}
return 0;
}
static int sonypi_acpi_add(struct acpi_device *device)
{
sonypi_acpi_device = device;
strcpy(acpi_device_name(device), "Sony laptop hotkeys");
strcpy(acpi_device_class(device), "sony/hotkey");
return 0;
}
static int sonypi_acpi_remove(struct acpi_device *device)
{
sonypi_acpi_device = NULL;
return 0;
}
static int sonypi_create_input_devices(struct platform_device *pdev)
{
struct input_dev *jog_dev;
struct input_dev *key_dev;
int i;
int error;
sonypi_device.input_jog_dev = jog_dev = input_allocate_device();
if (!jog_dev)
return -ENOMEM;
jog_dev->name = "Sony Vaio Jogdial";
jog_dev->id.bustype = BUS_ISA;
jog_dev->id.vendor = PCI_VENDOR_ID_SONY;
jog_dev->dev.parent = &pdev->dev;
jog_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
jog_dev->keybit[BIT_WORD(BTN_MOUSE)] = BIT_MASK(BTN_MIDDLE);
jog_dev->relbit[0] = BIT_MASK(REL_WHEEL);
sonypi_device.input_key_dev = key_dev = input_allocate_device();
if (!key_dev) {
error = -ENOMEM;
goto err_free_jogdev;
}
key_dev->name = "Sony Vaio Keys";
key_dev->id.bustype = BUS_ISA;
key_dev->id.vendor = PCI_VENDOR_ID_SONY;
key_dev->dev.parent = &pdev->dev;
key_dev->evbit[0] = BIT_MASK(EV_KEY);
for (i = 0; sonypi_inputkeys[i].sonypiev; i++)
if (sonypi_inputkeys[i].inputev)
set_bit(sonypi_inputkeys[i].inputev, key_dev->keybit);
error = input_register_device(jog_dev);
if (error)
goto err_free_keydev;
error = input_register_device(key_dev);
if (error)
goto err_unregister_jogdev;
return 0;
err_unregister_jogdev:
input_unregister_device(jog_dev);
jog_dev = NULL;
err_free_keydev:
input_free_device(key_dev);
sonypi_device.input_key_dev = NULL;
err_free_jogdev:
input_free_device(jog_dev);
sonypi_device.input_jog_dev = NULL;
return error;
}
static int sonypi_setup_ioports(struct sonypi_device *dev,
const struct sonypi_ioport_list *ioport_list)
{
const struct sonypi_ioport_list *check = ioport_list;
while (check_ioport && check->port1) {
if (!request_region(check->port1,
sonypi_device.region_size,
"Sony Programmable I/O Device Check")) {
printk(KERN_ERR "sonypi: ioport 0x%.4x busy, using sony-laptop? "
"if not use check_ioport=0\n",
check->port1);
return -EBUSY;
}
release_region(check->port1, sonypi_device.region_size);
check++;
}
while (ioport_list->port1) {
if (request_region(ioport_list->port1,
sonypi_device.region_size,
"Sony Programmable I/O Device")) {
dev->ioport1 = ioport_list->port1;
dev->ioport2 = ioport_list->port2;
return 0;
}
ioport_list++;
}
return -EBUSY;
}
static int sonypi_setup_irq(struct sonypi_device *dev,
const struct sonypi_irq_list *irq_list)
{
while (irq_list->irq) {
if (!request_irq(irq_list->irq, sonypi_irq,
IRQF_SHARED, "sonypi", sonypi_irq)) {
dev->irq = irq_list->irq;
dev->bits = irq_list->bits;
return 0;
}
irq_list++;
}
return -EBUSY;
}
static void sonypi_display_info(void)
{
printk(KERN_INFO "sonypi: detected type%d model, "
"verbose = %d, fnkeyinit = %s, camera = %s, "
"compat = %s, mask = 0x%08lx, useinput = %s, acpi = %s\n",
sonypi_device.model,
verbose,
fnkeyinit ? "on" : "off",
camera ? "on" : "off",
compat ? "on" : "off",
mask,
useinput ? "on" : "off",
SONYPI_ACPI_ACTIVE ? "on" : "off");
printk(KERN_INFO "sonypi: enabled at irq=%d, port1=0x%x, port2=0x%x\n",
sonypi_device.irq,
sonypi_device.ioport1, sonypi_device.ioport2);
if (minor == -1)
printk(KERN_INFO "sonypi: device allocated minor is %d\n",
sonypi_misc_device.minor);
}
static int sonypi_probe(struct platform_device *dev)
{
const struct sonypi_ioport_list *ioport_list;
const struct sonypi_irq_list *irq_list;
struct pci_dev *pcidev;
int error;
printk(KERN_WARNING "sonypi: please try the sony-laptop module instead "
"and report failures, see also "
"http://www.linux.it/~malattia/wiki/index.php/Sony_drivers\n");
spin_lock_init(&sonypi_device.fifo_lock);
error = kfifo_alloc(&sonypi_device.fifo, SONYPI_BUF_SIZE, GFP_KERNEL);
if (error) {
printk(KERN_ERR "sonypi: kfifo_alloc failed\n");
return error;
}
init_waitqueue_head(&sonypi_device.fifo_proc_list);
mutex_init(&sonypi_device.lock);
sonypi_device.bluetooth_power = -1;
if ((pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_3, NULL)))
sonypi_device.model = SONYPI_DEVICE_MODEL_TYPE1;
else if ((pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_ICH6_1, NULL)))
sonypi_device.model = SONYPI_DEVICE_MODEL_TYPE3;
else if ((pcidev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_ICH7_1, NULL)))
sonypi_device.model = SONYPI_DEVICE_MODEL_TYPE3;
else
sonypi_device.model = SONYPI_DEVICE_MODEL_TYPE2;
if (pcidev && pci_enable_device(pcidev)) {
printk(KERN_ERR "sonypi: pci_enable_device failed\n");
error = -EIO;
goto err_put_pcidev;
}
sonypi_device.dev = pcidev;
if (sonypi_device.model == SONYPI_DEVICE_MODEL_TYPE1) {
ioport_list = sonypi_type1_ioport_list;
sonypi_device.region_size = SONYPI_TYPE1_REGION_SIZE;
sonypi_device.evtype_offset = SONYPI_TYPE1_EVTYPE_OFFSET;
irq_list = sonypi_type1_irq_list;
} else if (sonypi_device.model == SONYPI_DEVICE_MODEL_TYPE2) {
ioport_list = sonypi_type2_ioport_list;
sonypi_device.region_size = SONYPI_TYPE2_REGION_SIZE;
sonypi_device.evtype_offset = SONYPI_TYPE2_EVTYPE_OFFSET;
irq_list = sonypi_type2_irq_list;
} else {
ioport_list = sonypi_type3_ioport_list;
sonypi_device.region_size = SONYPI_TYPE3_REGION_SIZE;
sonypi_device.evtype_offset = SONYPI_TYPE3_EVTYPE_OFFSET;
irq_list = sonypi_type3_irq_list;
}
error = sonypi_setup_ioports(&sonypi_device, ioport_list);
if (error) {
printk(KERN_ERR "sonypi: failed to request ioports\n");
goto err_disable_pcidev;
}
error = sonypi_setup_irq(&sonypi_device, irq_list);
if (error) {
printk(KERN_ERR "sonypi: request_irq failed\n");
goto err_free_ioports;
}
if (minor != -1)
sonypi_misc_device.minor = minor;
error = misc_register(&sonypi_misc_device);
if (error) {
printk(KERN_ERR "sonypi: misc_register failed\n");
goto err_free_irq;
}
sonypi_display_info();
if (useinput) {
error = sonypi_create_input_devices(dev);
if (error) {
printk(KERN_ERR
"sonypi: failed to create input devices\n");
goto err_miscdev_unregister;
}
spin_lock_init(&sonypi_device.input_fifo_lock);
error = kfifo_alloc(&sonypi_device.input_fifo, SONYPI_BUF_SIZE,
GFP_KERNEL);
if (error) {
printk(KERN_ERR "sonypi: kfifo_alloc failed\n");
goto err_inpdev_unregister;
}
INIT_WORK(&sonypi_device.input_work, input_keyrelease);
}
sonypi_enable(0);
return 0;
err_inpdev_unregister:
input_unregister_device(sonypi_device.input_key_dev);
input_unregister_device(sonypi_device.input_jog_dev);
err_miscdev_unregister:
misc_deregister(&sonypi_misc_device);
err_free_irq:
free_irq(sonypi_device.irq, sonypi_irq);
err_free_ioports:
release_region(sonypi_device.ioport1, sonypi_device.region_size);
err_disable_pcidev:
if (pcidev)
pci_disable_device(pcidev);
err_put_pcidev:
pci_dev_put(pcidev);
kfifo_free(&sonypi_device.fifo);
return error;
}
static int sonypi_remove(struct platform_device *dev)
{
sonypi_disable();
synchronize_irq(sonypi_device.irq);
flush_work(&sonypi_device.input_work);
if (useinput) {
input_unregister_device(sonypi_device.input_key_dev);
input_unregister_device(sonypi_device.input_jog_dev);
kfifo_free(&sonypi_device.input_fifo);
}
misc_deregister(&sonypi_misc_device);
free_irq(sonypi_device.irq, sonypi_irq);
release_region(sonypi_device.ioport1, sonypi_device.region_size);
if (sonypi_device.dev) {
pci_disable_device(sonypi_device.dev);
pci_dev_put(sonypi_device.dev);
}
kfifo_free(&sonypi_device.fifo);
return 0;
}
static int sonypi_suspend(struct device *dev)
{
old_camera_power = sonypi_device.camera_power;
sonypi_disable();
return 0;
}
static int sonypi_resume(struct device *dev)
{
sonypi_enable(old_camera_power);
return 0;
}
static void sonypi_shutdown(struct platform_device *dev)
{
sonypi_disable();
}
static int __init sonypi_init(void)
{
int error;
printk(KERN_INFO
"sonypi: Sony Programmable I/O Controller Driver v%s.\n",
SONYPI_DRIVER_VERSION);
if (!dmi_check_system(sonypi_dmi_table))
return -ENODEV;
error = platform_driver_register(&sonypi_driver);
if (error)
return error;
sonypi_platform_device = platform_device_alloc("sonypi", -1);
if (!sonypi_platform_device) {
error = -ENOMEM;
goto err_driver_unregister;
}
error = platform_device_add(sonypi_platform_device);
if (error)
goto err_free_device;
#ifdef CONFIG_ACPI
if (acpi_bus_register_driver(&sonypi_acpi_driver) >= 0)
acpi_driver_registered = 1;
#endif
return 0;
err_free_device:
platform_device_put(sonypi_platform_device);
err_driver_unregister:
platform_driver_unregister(&sonypi_driver);
return error;
}
static void __exit sonypi_exit(void)
{
#ifdef CONFIG_ACPI
if (acpi_driver_registered)
acpi_bus_unregister_driver(&sonypi_acpi_driver);
#endif
platform_device_unregister(sonypi_platform_device);
platform_driver_unregister(&sonypi_driver);
printk(KERN_INFO "sonypi: removed.\n");
}
