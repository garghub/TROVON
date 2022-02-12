static ssize_t
spidev_sync(struct spidev_data *spidev, struct spi_message *message)
{
DECLARE_COMPLETION_ONSTACK(done);
int status;
struct spi_device *spi;
spin_lock_irq(&spidev->spi_lock);
spi = spidev->spi;
spin_unlock_irq(&spidev->spi_lock);
if (spi == NULL)
status = -ESHUTDOWN;
else
status = spi_sync(spi, message);
if (status == 0)
status = message->actual_length;
return status;
}
static inline ssize_t
spidev_sync_write(struct spidev_data *spidev, size_t len)
{
struct spi_transfer t = {
.tx_buf = spidev->tx_buffer,
.len = len,
.speed_hz = spidev->speed_hz,
};
struct spi_message m;
spi_message_init(&m);
spi_message_add_tail(&t, &m);
return spidev_sync(spidev, &m);
}
static inline ssize_t
spidev_sync_read(struct spidev_data *spidev, size_t len)
{
struct spi_transfer t = {
.rx_buf = spidev->rx_buffer,
.len = len,
.speed_hz = spidev->speed_hz,
};
struct spi_message m;
spi_message_init(&m);
spi_message_add_tail(&t, &m);
return spidev_sync(spidev, &m);
}
static ssize_t
spidev_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
struct spidev_data *spidev;
ssize_t status = 0;
if (count > bufsiz)
return -EMSGSIZE;
spidev = filp->private_data;
mutex_lock(&spidev->buf_lock);
status = spidev_sync_read(spidev, count);
if (status > 0) {
unsigned long missing;
missing = copy_to_user(buf, spidev->rx_buffer, status);
if (missing == status)
status = -EFAULT;
else
status = status - missing;
}
mutex_unlock(&spidev->buf_lock);
return status;
}
static ssize_t
spidev_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
struct spidev_data *spidev;
ssize_t status = 0;
unsigned long missing;
if (count > bufsiz)
return -EMSGSIZE;
spidev = filp->private_data;
mutex_lock(&spidev->buf_lock);
missing = copy_from_user(spidev->tx_buffer, buf, count);
if (missing == 0)
status = spidev_sync_write(spidev, count);
else
status = -EFAULT;
mutex_unlock(&spidev->buf_lock);
return status;
}
static int spidev_message(struct spidev_data *spidev,
struct spi_ioc_transfer *u_xfers, unsigned n_xfers)
{
struct spi_message msg;
struct spi_transfer *k_xfers;
struct spi_transfer *k_tmp;
struct spi_ioc_transfer *u_tmp;
unsigned n, total, tx_total, rx_total;
u8 *tx_buf, *rx_buf;
int status = -EFAULT;
spi_message_init(&msg);
k_xfers = kcalloc(n_xfers, sizeof(*k_tmp), GFP_KERNEL);
if (k_xfers == NULL)
return -ENOMEM;
tx_buf = spidev->tx_buffer;
rx_buf = spidev->rx_buffer;
total = 0;
tx_total = 0;
rx_total = 0;
for (n = n_xfers, k_tmp = k_xfers, u_tmp = u_xfers;
n;
n--, k_tmp++, u_tmp++) {
k_tmp->len = u_tmp->len;
total += k_tmp->len;
if (total > INT_MAX || k_tmp->len > INT_MAX) {
status = -EMSGSIZE;
goto done;
}
if (u_tmp->rx_buf) {
rx_total += k_tmp->len;
if (rx_total > bufsiz) {
status = -EMSGSIZE;
goto done;
}
k_tmp->rx_buf = rx_buf;
if (!access_ok(VERIFY_WRITE, (u8 __user *)
(uintptr_t) u_tmp->rx_buf,
u_tmp->len))
goto done;
rx_buf += k_tmp->len;
}
if (u_tmp->tx_buf) {
tx_total += k_tmp->len;
if (tx_total > bufsiz) {
status = -EMSGSIZE;
goto done;
}
k_tmp->tx_buf = tx_buf;
if (copy_from_user(tx_buf, (const u8 __user *)
(uintptr_t) u_tmp->tx_buf,
u_tmp->len))
goto done;
tx_buf += k_tmp->len;
}
k_tmp->cs_change = !!u_tmp->cs_change;
k_tmp->tx_nbits = u_tmp->tx_nbits;
k_tmp->rx_nbits = u_tmp->rx_nbits;
k_tmp->bits_per_word = u_tmp->bits_per_word;
k_tmp->delay_usecs = u_tmp->delay_usecs;
k_tmp->speed_hz = u_tmp->speed_hz;
if (!k_tmp->speed_hz)
k_tmp->speed_hz = spidev->speed_hz;
#ifdef VERBOSE
dev_dbg(&spidev->spi->dev,
" xfer len %u %s%s%s%dbits %u usec %uHz\n",
u_tmp->len,
u_tmp->rx_buf ? "rx " : "",
u_tmp->tx_buf ? "tx " : "",
u_tmp->cs_change ? "cs " : "",
u_tmp->bits_per_word ? : spidev->spi->bits_per_word,
u_tmp->delay_usecs,
u_tmp->speed_hz ? : spidev->spi->max_speed_hz);
#endif
spi_message_add_tail(k_tmp, &msg);
}
status = spidev_sync(spidev, &msg);
if (status < 0)
goto done;
rx_buf = spidev->rx_buffer;
for (n = n_xfers, u_tmp = u_xfers; n; n--, u_tmp++) {
if (u_tmp->rx_buf) {
if (__copy_to_user((u8 __user *)
(uintptr_t) u_tmp->rx_buf, rx_buf,
u_tmp->len)) {
status = -EFAULT;
goto done;
}
rx_buf += u_tmp->len;
}
}
status = total;
done:
kfree(k_xfers);
return status;
}
static struct spi_ioc_transfer *
spidev_get_ioc_message(unsigned int cmd, struct spi_ioc_transfer __user *u_ioc,
unsigned *n_ioc)
{
struct spi_ioc_transfer *ioc;
u32 tmp;
if (_IOC_TYPE(cmd) != SPI_IOC_MAGIC
|| _IOC_NR(cmd) != _IOC_NR(SPI_IOC_MESSAGE(0))
|| _IOC_DIR(cmd) != _IOC_WRITE)
return ERR_PTR(-ENOTTY);
tmp = _IOC_SIZE(cmd);
if ((tmp % sizeof(struct spi_ioc_transfer)) != 0)
return ERR_PTR(-EINVAL);
*n_ioc = tmp / sizeof(struct spi_ioc_transfer);
if (*n_ioc == 0)
return NULL;
ioc = kmalloc(tmp, GFP_KERNEL);
if (!ioc)
return ERR_PTR(-ENOMEM);
if (__copy_from_user(ioc, u_ioc, tmp)) {
kfree(ioc);
return ERR_PTR(-EFAULT);
}
return ioc;
}
static long
spidev_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
int err = 0;
int retval = 0;
struct spidev_data *spidev;
struct spi_device *spi;
u32 tmp;
unsigned n_ioc;
struct spi_ioc_transfer *ioc;
if (_IOC_TYPE(cmd) != SPI_IOC_MAGIC)
return -ENOTTY;
if (_IOC_DIR(cmd) & _IOC_READ)
err = !access_ok(VERIFY_WRITE,
(void __user *)arg, _IOC_SIZE(cmd));
if (err == 0 && _IOC_DIR(cmd) & _IOC_WRITE)
err = !access_ok(VERIFY_READ,
(void __user *)arg, _IOC_SIZE(cmd));
if (err)
return -EFAULT;
spidev = filp->private_data;
spin_lock_irq(&spidev->spi_lock);
spi = spi_dev_get(spidev->spi);
spin_unlock_irq(&spidev->spi_lock);
if (spi == NULL)
return -ESHUTDOWN;
mutex_lock(&spidev->buf_lock);
switch (cmd) {
case SPI_IOC_RD_MODE:
retval = __put_user(spi->mode & SPI_MODE_MASK,
(__u8 __user *)arg);
break;
case SPI_IOC_RD_MODE32:
retval = __put_user(spi->mode & SPI_MODE_MASK,
(__u32 __user *)arg);
break;
case SPI_IOC_RD_LSB_FIRST:
retval = __put_user((spi->mode & SPI_LSB_FIRST) ? 1 : 0,
(__u8 __user *)arg);
break;
case SPI_IOC_RD_BITS_PER_WORD:
retval = __put_user(spi->bits_per_word, (__u8 __user *)arg);
break;
case SPI_IOC_RD_MAX_SPEED_HZ:
retval = __put_user(spidev->speed_hz, (__u32 __user *)arg);
break;
case SPI_IOC_WR_MODE:
case SPI_IOC_WR_MODE32:
if (cmd == SPI_IOC_WR_MODE)
retval = __get_user(tmp, (u8 __user *)arg);
else
retval = __get_user(tmp, (u32 __user *)arg);
if (retval == 0) {
u32 save = spi->mode;
if (tmp & ~SPI_MODE_MASK) {
retval = -EINVAL;
break;
}
tmp |= spi->mode & ~SPI_MODE_MASK;
spi->mode = (u16)tmp;
retval = spi_setup(spi);
if (retval < 0)
spi->mode = save;
else
dev_dbg(&spi->dev, "spi mode %x\n", tmp);
}
break;
case SPI_IOC_WR_LSB_FIRST:
retval = __get_user(tmp, (__u8 __user *)arg);
if (retval == 0) {
u32 save = spi->mode;
if (tmp)
spi->mode |= SPI_LSB_FIRST;
else
spi->mode &= ~SPI_LSB_FIRST;
retval = spi_setup(spi);
if (retval < 0)
spi->mode = save;
else
dev_dbg(&spi->dev, "%csb first\n",
tmp ? 'l' : 'm');
}
break;
case SPI_IOC_WR_BITS_PER_WORD:
retval = __get_user(tmp, (__u8 __user *)arg);
if (retval == 0) {
u8 save = spi->bits_per_word;
spi->bits_per_word = tmp;
retval = spi_setup(spi);
if (retval < 0)
spi->bits_per_word = save;
else
dev_dbg(&spi->dev, "%d bits per word\n", tmp);
}
break;
case SPI_IOC_WR_MAX_SPEED_HZ:
retval = __get_user(tmp, (__u32 __user *)arg);
if (retval == 0) {
u32 save = spi->max_speed_hz;
spi->max_speed_hz = tmp;
retval = spi_setup(spi);
if (retval >= 0)
spidev->speed_hz = tmp;
else
dev_dbg(&spi->dev, "%d Hz (max)\n", tmp);
spi->max_speed_hz = save;
}
break;
default:
ioc = spidev_get_ioc_message(cmd,
(struct spi_ioc_transfer __user *)arg, &n_ioc);
if (IS_ERR(ioc)) {
retval = PTR_ERR(ioc);
break;
}
if (!ioc)
break;
retval = spidev_message(spidev, ioc, n_ioc);
kfree(ioc);
break;
}
mutex_unlock(&spidev->buf_lock);
spi_dev_put(spi);
return retval;
}
static long
spidev_compat_ioc_message(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct spi_ioc_transfer __user *u_ioc;
int retval = 0;
struct spidev_data *spidev;
struct spi_device *spi;
unsigned n_ioc, n;
struct spi_ioc_transfer *ioc;
u_ioc = (struct spi_ioc_transfer __user *) compat_ptr(arg);
if (!access_ok(VERIFY_READ, u_ioc, _IOC_SIZE(cmd)))
return -EFAULT;
spidev = filp->private_data;
spin_lock_irq(&spidev->spi_lock);
spi = spi_dev_get(spidev->spi);
spin_unlock_irq(&spidev->spi_lock);
if (spi == NULL)
return -ESHUTDOWN;
mutex_lock(&spidev->buf_lock);
ioc = spidev_get_ioc_message(cmd, u_ioc, &n_ioc);
if (IS_ERR(ioc)) {
retval = PTR_ERR(ioc);
goto done;
}
if (!ioc)
goto done;
for (n = 0; n < n_ioc; n++) {
ioc[n].rx_buf = (uintptr_t) compat_ptr(ioc[n].rx_buf);
ioc[n].tx_buf = (uintptr_t) compat_ptr(ioc[n].tx_buf);
}
retval = spidev_message(spidev, ioc, n_ioc);
kfree(ioc);
done:
mutex_unlock(&spidev->buf_lock);
spi_dev_put(spi);
return retval;
}
static long
spidev_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
if (_IOC_TYPE(cmd) == SPI_IOC_MAGIC
&& _IOC_NR(cmd) == _IOC_NR(SPI_IOC_MESSAGE(0))
&& _IOC_DIR(cmd) == _IOC_WRITE)
return spidev_compat_ioc_message(filp, cmd, arg);
return spidev_ioctl(filp, cmd, (unsigned long)compat_ptr(arg));
}
static int spidev_open(struct inode *inode, struct file *filp)
{
struct spidev_data *spidev;
int status = -ENXIO;
mutex_lock(&device_list_lock);
list_for_each_entry(spidev, &device_list, device_entry) {
if (spidev->devt == inode->i_rdev) {
status = 0;
break;
}
}
if (status) {
pr_debug("spidev: nothing for minor %d\n", iminor(inode));
goto err_find_dev;
}
if (!spidev->tx_buffer) {
spidev->tx_buffer = kmalloc(bufsiz, GFP_KERNEL);
if (!spidev->tx_buffer) {
dev_dbg(&spidev->spi->dev, "open/ENOMEM\n");
status = -ENOMEM;
goto err_find_dev;
}
}
if (!spidev->rx_buffer) {
spidev->rx_buffer = kmalloc(bufsiz, GFP_KERNEL);
if (!spidev->rx_buffer) {
dev_dbg(&spidev->spi->dev, "open/ENOMEM\n");
status = -ENOMEM;
goto err_alloc_rx_buf;
}
}
spidev->users++;
filp->private_data = spidev;
nonseekable_open(inode, filp);
mutex_unlock(&device_list_lock);
return 0;
err_alloc_rx_buf:
kfree(spidev->tx_buffer);
spidev->tx_buffer = NULL;
err_find_dev:
mutex_unlock(&device_list_lock);
return status;
}
static int spidev_release(struct inode *inode, struct file *filp)
{
struct spidev_data *spidev;
mutex_lock(&device_list_lock);
spidev = filp->private_data;
filp->private_data = NULL;
spidev->users--;
if (!spidev->users) {
int dofree;
kfree(spidev->tx_buffer);
spidev->tx_buffer = NULL;
kfree(spidev->rx_buffer);
spidev->rx_buffer = NULL;
spin_lock_irq(&spidev->spi_lock);
if (spidev->spi)
spidev->speed_hz = spidev->spi->max_speed_hz;
dofree = (spidev->spi == NULL);
spin_unlock_irq(&spidev->spi_lock);
if (dofree)
kfree(spidev);
}
mutex_unlock(&device_list_lock);
return 0;
}
static void spidev_probe_acpi(struct spi_device *spi)
{
const struct acpi_device_id *id;
if (!has_acpi_companion(&spi->dev))
return;
id = acpi_match_device(spidev_acpi_ids, &spi->dev);
if (WARN_ON(!id))
return;
if (id->driver_data == SPIDEV_ACPI_DUMMY)
dev_warn(&spi->dev, "do not use this driver in production systems!\n");
}
static inline void spidev_probe_acpi(struct spi_device *spi) {}
static int spidev_probe(struct spi_device *spi)
{
struct spidev_data *spidev;
int status;
unsigned long minor;
if (spi->dev.of_node && !of_match_device(spidev_dt_ids, &spi->dev)) {
dev_err(&spi->dev, "buggy DT: spidev listed directly in DT\n");
WARN_ON(spi->dev.of_node &&
!of_match_device(spidev_dt_ids, &spi->dev));
}
spidev_probe_acpi(spi);
spidev = kzalloc(sizeof(*spidev), GFP_KERNEL);
if (!spidev)
return -ENOMEM;
spidev->spi = spi;
spin_lock_init(&spidev->spi_lock);
mutex_init(&spidev->buf_lock);
INIT_LIST_HEAD(&spidev->device_entry);
mutex_lock(&device_list_lock);
minor = find_first_zero_bit(minors, N_SPI_MINORS);
if (minor < N_SPI_MINORS) {
struct device *dev;
spidev->devt = MKDEV(SPIDEV_MAJOR, minor);
dev = device_create(spidev_class, &spi->dev, spidev->devt,
spidev, "spidev%d.%d",
spi->master->bus_num, spi->chip_select);
status = PTR_ERR_OR_ZERO(dev);
} else {
dev_dbg(&spi->dev, "no minor number available!\n");
status = -ENODEV;
}
if (status == 0) {
set_bit(minor, minors);
list_add(&spidev->device_entry, &device_list);
}
mutex_unlock(&device_list_lock);
spidev->speed_hz = spi->max_speed_hz;
if (status == 0)
spi_set_drvdata(spi, spidev);
else
kfree(spidev);
return status;
}
static int spidev_remove(struct spi_device *spi)
{
struct spidev_data *spidev = spi_get_drvdata(spi);
spin_lock_irq(&spidev->spi_lock);
spidev->spi = NULL;
spin_unlock_irq(&spidev->spi_lock);
mutex_lock(&device_list_lock);
list_del(&spidev->device_entry);
device_destroy(spidev_class, spidev->devt);
clear_bit(MINOR(spidev->devt), minors);
if (spidev->users == 0)
kfree(spidev);
mutex_unlock(&device_list_lock);
return 0;
}
static int __init spidev_init(void)
{
int status;
BUILD_BUG_ON(N_SPI_MINORS > 256);
status = register_chrdev(SPIDEV_MAJOR, "spi", &spidev_fops);
if (status < 0)
return status;
spidev_class = class_create(THIS_MODULE, "spidev");
if (IS_ERR(spidev_class)) {
unregister_chrdev(SPIDEV_MAJOR, spidev_spi_driver.driver.name);
return PTR_ERR(spidev_class);
}
status = spi_register_driver(&spidev_spi_driver);
if (status < 0) {
class_destroy(spidev_class);
unregister_chrdev(SPIDEV_MAJOR, spidev_spi_driver.driver.name);
}
return status;
}
static void __exit spidev_exit(void)
{
spi_unregister_driver(&spidev_spi_driver);
class_destroy(spidev_class);
unregister_chrdev(SPIDEV_MAJOR, spidev_spi_driver.driver.name);
}
