struct pci_ops *pci_bus_set_ops(struct pci_bus *bus, struct pci_ops *ops)
{
struct pci_ops *old_ops;
unsigned long flags;
raw_spin_lock_irqsave(&pci_lock, flags);
old_ops = bus->ops;
bus->ops = ops;
raw_spin_unlock_irqrestore(&pci_lock, flags);
return old_ops;
}
ssize_t pci_read_vpd(struct pci_dev *dev, loff_t pos, size_t count, void *buf)
{
if (!dev->vpd || !dev->vpd->ops)
return -ENODEV;
return dev->vpd->ops->read(dev, pos, count, buf);
}
ssize_t pci_write_vpd(struct pci_dev *dev, loff_t pos, size_t count, const void *buf)
{
if (!dev->vpd || !dev->vpd->ops)
return -ENODEV;
return dev->vpd->ops->write(dev, pos, count, buf);
}
static noinline void pci_wait_ucfg(struct pci_dev *dev)
{
DECLARE_WAITQUEUE(wait, current);
__add_wait_queue(&pci_ucfg_wait, &wait);
do {
set_current_state(TASK_UNINTERRUPTIBLE);
raw_spin_unlock_irq(&pci_lock);
schedule();
raw_spin_lock_irq(&pci_lock);
} while (dev->block_ucfg_access);
__remove_wait_queue(&pci_ucfg_wait, &wait);
}
static int pci_vpd_pci22_wait(struct pci_dev *dev)
{
struct pci_vpd_pci22 *vpd =
container_of(dev->vpd, struct pci_vpd_pci22, base);
unsigned long timeout = jiffies + HZ/20 + 2;
u16 status;
int ret;
if (!vpd->busy)
return 0;
for (;;) {
ret = pci_user_read_config_word(dev, vpd->cap + PCI_VPD_ADDR,
&status);
if (ret < 0)
return ret;
if ((status & PCI_VPD_ADDR_F) == vpd->flag) {
vpd->busy = false;
return 0;
}
if (time_after(jiffies, timeout)) {
dev_printk(KERN_DEBUG, &dev->dev,
"vpd r/w failed. This is likely a firmware "
"bug on this device. Contact the card "
"vendor for a firmware update.");
return -ETIMEDOUT;
}
if (fatal_signal_pending(current))
return -EINTR;
if (!cond_resched())
udelay(10);
}
}
static ssize_t pci_vpd_pci22_read(struct pci_dev *dev, loff_t pos, size_t count,
void *arg)
{
struct pci_vpd_pci22 *vpd =
container_of(dev->vpd, struct pci_vpd_pci22, base);
int ret;
loff_t end = pos + count;
u8 *buf = arg;
if (pos < 0 || pos > vpd->base.len || end > vpd->base.len)
return -EINVAL;
if (mutex_lock_killable(&vpd->lock))
return -EINTR;
ret = pci_vpd_pci22_wait(dev);
if (ret < 0)
goto out;
while (pos < end) {
u32 val;
unsigned int i, skip;
ret = pci_user_write_config_word(dev, vpd->cap + PCI_VPD_ADDR,
pos & ~3);
if (ret < 0)
break;
vpd->busy = true;
vpd->flag = PCI_VPD_ADDR_F;
ret = pci_vpd_pci22_wait(dev);
if (ret < 0)
break;
ret = pci_user_read_config_dword(dev, vpd->cap + PCI_VPD_DATA, &val);
if (ret < 0)
break;
skip = pos & 3;
for (i = 0; i < sizeof(u32); i++) {
if (i >= skip) {
*buf++ = val;
if (++pos == end)
break;
}
val >>= 8;
}
}
out:
mutex_unlock(&vpd->lock);
return ret ? ret : count;
}
static ssize_t pci_vpd_pci22_write(struct pci_dev *dev, loff_t pos, size_t count,
const void *arg)
{
struct pci_vpd_pci22 *vpd =
container_of(dev->vpd, struct pci_vpd_pci22, base);
const u8 *buf = arg;
loff_t end = pos + count;
int ret = 0;
if (pos < 0 || (pos & 3) || (count & 3) || end > vpd->base.len)
return -EINVAL;
if (mutex_lock_killable(&vpd->lock))
return -EINTR;
ret = pci_vpd_pci22_wait(dev);
if (ret < 0)
goto out;
while (pos < end) {
u32 val;
val = *buf++;
val |= *buf++ << 8;
val |= *buf++ << 16;
val |= *buf++ << 24;
ret = pci_user_write_config_dword(dev, vpd->cap + PCI_VPD_DATA, val);
if (ret < 0)
break;
ret = pci_user_write_config_word(dev, vpd->cap + PCI_VPD_ADDR,
pos | PCI_VPD_ADDR_F);
if (ret < 0)
break;
vpd->busy = true;
vpd->flag = 0;
ret = pci_vpd_pci22_wait(dev);
if (ret < 0)
break;
pos += sizeof(u32);
}
out:
mutex_unlock(&vpd->lock);
return ret ? ret : count;
}
static void pci_vpd_pci22_release(struct pci_dev *dev)
{
kfree(container_of(dev->vpd, struct pci_vpd_pci22, base));
}
int pci_vpd_pci22_init(struct pci_dev *dev)
{
struct pci_vpd_pci22 *vpd;
u8 cap;
cap = pci_find_capability(dev, PCI_CAP_ID_VPD);
if (!cap)
return -ENODEV;
vpd = kzalloc(sizeof(*vpd), GFP_ATOMIC);
if (!vpd)
return -ENOMEM;
vpd->base.len = PCI_VPD_PCI22_SIZE;
vpd->base.ops = &pci_vpd_pci22_ops;
mutex_init(&vpd->lock);
vpd->cap = cap;
vpd->busy = false;
dev->vpd = &vpd->base;
return 0;
}
int pci_vpd_truncate(struct pci_dev *dev, size_t size)
{
if (!dev->vpd)
return -EINVAL;
if (size > dev->vpd->len)
return -EINVAL;
dev->vpd->len = size;
if (dev->vpd->attr)
dev->vpd->attr->size = size;
return 0;
}
void pci_block_user_cfg_access(struct pci_dev *dev)
{
unsigned long flags;
int was_blocked;
raw_spin_lock_irqsave(&pci_lock, flags);
was_blocked = dev->block_ucfg_access;
dev->block_ucfg_access = 1;
raw_spin_unlock_irqrestore(&pci_lock, flags);
BUG_ON(was_blocked);
}
void pci_unblock_user_cfg_access(struct pci_dev *dev)
{
unsigned long flags;
raw_spin_lock_irqsave(&pci_lock, flags);
WARN_ON(!dev->block_ucfg_access);
dev->block_ucfg_access = 0;
wake_up_all(&pci_ucfg_wait);
raw_spin_unlock_irqrestore(&pci_lock, flags);
}
