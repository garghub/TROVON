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
static noinline void pci_wait_cfg(struct pci_dev *dev)
{
DECLARE_WAITQUEUE(wait, current);
__add_wait_queue(&pci_cfg_wait, &wait);
do {
set_current_state(TASK_UNINTERRUPTIBLE);
raw_spin_unlock_irq(&pci_lock);
schedule();
raw_spin_lock_irq(&pci_lock);
} while (dev->block_cfg_access);
__remove_wait_queue(&pci_cfg_wait, &wait);
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
dev_printk(KERN_DEBUG, &dev->dev, "vpd r/w failed. This is likely a firmware bug on this device. Contact the card vendor for a firmware update\n");
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
void pci_cfg_access_lock(struct pci_dev *dev)
{
might_sleep();
raw_spin_lock_irq(&pci_lock);
if (dev->block_cfg_access)
pci_wait_cfg(dev);
dev->block_cfg_access = 1;
raw_spin_unlock_irq(&pci_lock);
}
bool pci_cfg_access_trylock(struct pci_dev *dev)
{
unsigned long flags;
bool locked = true;
raw_spin_lock_irqsave(&pci_lock, flags);
if (dev->block_cfg_access)
locked = false;
else
dev->block_cfg_access = 1;
raw_spin_unlock_irqrestore(&pci_lock, flags);
return locked;
}
void pci_cfg_access_unlock(struct pci_dev *dev)
{
unsigned long flags;
raw_spin_lock_irqsave(&pci_lock, flags);
WARN_ON(!dev->block_cfg_access);
dev->block_cfg_access = 0;
wake_up_all(&pci_cfg_wait);
raw_spin_unlock_irqrestore(&pci_lock, flags);
}
static inline int pcie_cap_version(const struct pci_dev *dev)
{
return pcie_caps_reg(dev) & PCI_EXP_FLAGS_VERS;
}
static inline bool pcie_cap_has_lnkctl(const struct pci_dev *dev)
{
int type = pci_pcie_type(dev);
return type == PCI_EXP_TYPE_ENDPOINT ||
type == PCI_EXP_TYPE_LEG_END ||
type == PCI_EXP_TYPE_ROOT_PORT ||
type == PCI_EXP_TYPE_UPSTREAM ||
type == PCI_EXP_TYPE_DOWNSTREAM ||
type == PCI_EXP_TYPE_PCI_BRIDGE ||
type == PCI_EXP_TYPE_PCIE_BRIDGE;
}
static inline bool pcie_cap_has_sltctl(const struct pci_dev *dev)
{
int type = pci_pcie_type(dev);
return (type == PCI_EXP_TYPE_ROOT_PORT ||
type == PCI_EXP_TYPE_DOWNSTREAM) &&
pcie_caps_reg(dev) & PCI_EXP_FLAGS_SLOT;
}
static inline bool pcie_cap_has_rtctl(const struct pci_dev *dev)
{
int type = pci_pcie_type(dev);
return type == PCI_EXP_TYPE_ROOT_PORT ||
type == PCI_EXP_TYPE_RC_EC;
}
static bool pcie_capability_reg_implemented(struct pci_dev *dev, int pos)
{
if (!pci_is_pcie(dev))
return false;
switch (pos) {
case PCI_EXP_FLAGS:
return true;
case PCI_EXP_DEVCAP:
case PCI_EXP_DEVCTL:
case PCI_EXP_DEVSTA:
return true;
case PCI_EXP_LNKCAP:
case PCI_EXP_LNKCTL:
case PCI_EXP_LNKSTA:
return pcie_cap_has_lnkctl(dev);
case PCI_EXP_SLTCAP:
case PCI_EXP_SLTCTL:
case PCI_EXP_SLTSTA:
return pcie_cap_has_sltctl(dev);
case PCI_EXP_RTCTL:
case PCI_EXP_RTCAP:
case PCI_EXP_RTSTA:
return pcie_cap_has_rtctl(dev);
case PCI_EXP_DEVCAP2:
case PCI_EXP_DEVCTL2:
case PCI_EXP_LNKCAP2:
case PCI_EXP_LNKCTL2:
case PCI_EXP_LNKSTA2:
return pcie_cap_version(dev) > 1;
default:
return false;
}
}
int pcie_capability_read_word(struct pci_dev *dev, int pos, u16 *val)
{
int ret;
*val = 0;
if (pos & 1)
return -EINVAL;
if (pcie_capability_reg_implemented(dev, pos)) {
ret = pci_read_config_word(dev, pci_pcie_cap(dev) + pos, val);
if (ret)
*val = 0;
return ret;
}
if (pci_is_pcie(dev) && pos == PCI_EXP_SLTSTA &&
pci_pcie_type(dev) == PCI_EXP_TYPE_DOWNSTREAM) {
*val = PCI_EXP_SLTSTA_PDS;
}
return 0;
}
int pcie_capability_read_dword(struct pci_dev *dev, int pos, u32 *val)
{
int ret;
*val = 0;
if (pos & 3)
return -EINVAL;
if (pcie_capability_reg_implemented(dev, pos)) {
ret = pci_read_config_dword(dev, pci_pcie_cap(dev) + pos, val);
if (ret)
*val = 0;
return ret;
}
if (pci_is_pcie(dev) && pos == PCI_EXP_SLTCTL &&
pci_pcie_type(dev) == PCI_EXP_TYPE_DOWNSTREAM) {
*val = PCI_EXP_SLTSTA_PDS;
}
return 0;
}
int pcie_capability_write_word(struct pci_dev *dev, int pos, u16 val)
{
if (pos & 1)
return -EINVAL;
if (!pcie_capability_reg_implemented(dev, pos))
return 0;
return pci_write_config_word(dev, pci_pcie_cap(dev) + pos, val);
}
int pcie_capability_write_dword(struct pci_dev *dev, int pos, u32 val)
{
if (pos & 3)
return -EINVAL;
if (!pcie_capability_reg_implemented(dev, pos))
return 0;
return pci_write_config_dword(dev, pci_pcie_cap(dev) + pos, val);
}
int pcie_capability_clear_and_set_word(struct pci_dev *dev, int pos,
u16 clear, u16 set)
{
int ret;
u16 val;
ret = pcie_capability_read_word(dev, pos, &val);
if (!ret) {
val &= ~clear;
val |= set;
ret = pcie_capability_write_word(dev, pos, val);
}
return ret;
}
int pcie_capability_clear_and_set_dword(struct pci_dev *dev, int pos,
u32 clear, u32 set)
{
int ret;
u32 val;
ret = pcie_capability_read_dword(dev, pos, &val);
if (!ret) {
val &= ~clear;
val |= set;
ret = pcie_capability_write_dword(dev, pos, val);
}
return ret;
}
