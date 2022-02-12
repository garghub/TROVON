static const char *vga_iostate_to_str(unsigned int iostate)
{
iostate &= VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM;
switch (iostate) {
case VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM:
return "io+mem";
case VGA_RSRC_LEGACY_IO:
return "io";
case VGA_RSRC_LEGACY_MEM:
return "mem";
}
return "none";
}
static int vga_str_to_iostate(char *buf, int str_size, int *io_state)
{
if (strncmp(buf, "none", 4) == 0) {
*io_state = VGA_RSRC_NONE;
return 1;
}
if (strncmp(buf, "io+mem", 6) == 0)
goto both;
else if (strncmp(buf, "io", 2) == 0)
goto both;
else if (strncmp(buf, "mem", 3) == 0)
goto both;
return 0;
both:
*io_state = VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM;
return 1;
}
static struct vga_device *vgadev_find(struct pci_dev *pdev)
{
struct vga_device *vgadev;
list_for_each_entry(vgadev, &vga_list, list)
if (pdev == vgadev->pdev)
return vgadev;
return NULL;
}
struct pci_dev *vga_default_device(void)
{
return vga_default;
}
void vga_set_default_device(struct pci_dev *pdev)
{
if (vga_default == pdev)
return;
pci_dev_put(vga_default);
vga_default = pci_dev_get(pdev);
}
static inline void vga_irq_set_state(struct vga_device *vgadev, bool state)
{
if (vgadev->irq_set_state)
vgadev->irq_set_state(vgadev->cookie, state);
}
static void vga_check_first_use(void)
{
if (!vga_arbiter_used) {
vga_arbiter_used = true;
vga_arbiter_notify_clients();
}
}
static struct vga_device *__vga_tryget(struct vga_device *vgadev,
unsigned int rsrc)
{
unsigned int wants, legacy_wants, match;
struct vga_device *conflict;
unsigned int pci_bits;
u32 flags = 0;
if ((rsrc & VGA_RSRC_NORMAL_IO) &&
(vgadev->decodes & VGA_RSRC_LEGACY_IO))
rsrc |= VGA_RSRC_LEGACY_IO;
if ((rsrc & VGA_RSRC_NORMAL_MEM) &&
(vgadev->decodes & VGA_RSRC_LEGACY_MEM))
rsrc |= VGA_RSRC_LEGACY_MEM;
pr_debug("%s: %d\n", __func__, rsrc);
pr_debug("%s: owns: %d\n", __func__, vgadev->owns);
wants = rsrc & ~vgadev->owns;
if (wants == 0)
goto lock_them;
legacy_wants = wants & VGA_RSRC_LEGACY_MASK;
if (legacy_wants == 0)
goto enable_them;
list_for_each_entry(conflict, &vga_list, list) {
unsigned int lwants = legacy_wants;
unsigned int change_bridge = 0;
if (vgadev == conflict)
continue;
if (!vga_conflicts(vgadev->pdev, conflict->pdev))
continue;
if (vgadev->pdev->bus != conflict->pdev->bus) {
change_bridge = 1;
lwants = VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM;
}
if (conflict->locks & lwants)
return conflict;
WARN_ON(conflict->owns & ~conflict->decodes);
match = lwants & conflict->owns;
if (!match)
continue;
flags = 0;
pci_bits = 0;
if (!conflict->bridge_has_one_vga) {
vga_irq_set_state(conflict, false);
flags |= PCI_VGA_STATE_CHANGE_DECODES;
if (match & (VGA_RSRC_LEGACY_MEM|VGA_RSRC_NORMAL_MEM))
pci_bits |= PCI_COMMAND_MEMORY;
if (match & (VGA_RSRC_LEGACY_IO|VGA_RSRC_NORMAL_IO))
pci_bits |= PCI_COMMAND_IO;
}
if (change_bridge)
flags |= PCI_VGA_STATE_CHANGE_BRIDGE;
pci_set_vga_state(conflict->pdev, false, pci_bits, flags);
conflict->owns &= ~match;
if (match & VGA_RSRC_LEGACY_MEM)
conflict->owns &= ~VGA_RSRC_NORMAL_MEM;
if (match & VGA_RSRC_LEGACY_IO)
conflict->owns &= ~VGA_RSRC_NORMAL_IO;
}
enable_them:
flags = 0;
pci_bits = 0;
if (!vgadev->bridge_has_one_vga) {
flags |= PCI_VGA_STATE_CHANGE_DECODES;
if (wants & (VGA_RSRC_LEGACY_MEM|VGA_RSRC_NORMAL_MEM))
pci_bits |= PCI_COMMAND_MEMORY;
if (wants & (VGA_RSRC_LEGACY_IO|VGA_RSRC_NORMAL_IO))
pci_bits |= PCI_COMMAND_IO;
}
if (!!(wants & VGA_RSRC_LEGACY_MASK))
flags |= PCI_VGA_STATE_CHANGE_BRIDGE;
pci_set_vga_state(vgadev->pdev, true, pci_bits, flags);
if (!vgadev->bridge_has_one_vga) {
vga_irq_set_state(vgadev, true);
}
vgadev->owns |= (wants & vgadev->decodes);
lock_them:
vgadev->locks |= (rsrc & VGA_RSRC_LEGACY_MASK);
if (rsrc & VGA_RSRC_LEGACY_IO)
vgadev->io_lock_cnt++;
if (rsrc & VGA_RSRC_LEGACY_MEM)
vgadev->mem_lock_cnt++;
if (rsrc & VGA_RSRC_NORMAL_IO)
vgadev->io_norm_cnt++;
if (rsrc & VGA_RSRC_NORMAL_MEM)
vgadev->mem_norm_cnt++;
return NULL;
}
static void __vga_put(struct vga_device *vgadev, unsigned int rsrc)
{
unsigned int old_locks = vgadev->locks;
pr_debug("%s\n", __func__);
if ((rsrc & VGA_RSRC_NORMAL_IO) && vgadev->io_norm_cnt > 0) {
vgadev->io_norm_cnt--;
if (vgadev->decodes & VGA_RSRC_LEGACY_IO)
rsrc |= VGA_RSRC_LEGACY_IO;
}
if ((rsrc & VGA_RSRC_NORMAL_MEM) && vgadev->mem_norm_cnt > 0) {
vgadev->mem_norm_cnt--;
if (vgadev->decodes & VGA_RSRC_LEGACY_MEM)
rsrc |= VGA_RSRC_LEGACY_MEM;
}
if ((rsrc & VGA_RSRC_LEGACY_IO) && vgadev->io_lock_cnt > 0)
vgadev->io_lock_cnt--;
if ((rsrc & VGA_RSRC_LEGACY_MEM) && vgadev->mem_lock_cnt > 0)
vgadev->mem_lock_cnt--;
if (vgadev->io_lock_cnt == 0)
vgadev->locks &= ~VGA_RSRC_LEGACY_IO;
if (vgadev->mem_lock_cnt == 0)
vgadev->locks &= ~VGA_RSRC_LEGACY_MEM;
if (old_locks != vgadev->locks)
wake_up_all(&vga_wait_queue);
}
int vga_get(struct pci_dev *pdev, unsigned int rsrc, int interruptible)
{
struct vga_device *vgadev, *conflict;
unsigned long flags;
wait_queue_t wait;
int rc = 0;
vga_check_first_use();
if (pdev == NULL)
pdev = vga_default_device();
if (pdev == NULL)
return 0;
for (;;) {
spin_lock_irqsave(&vga_lock, flags);
vgadev = vgadev_find(pdev);
if (vgadev == NULL) {
spin_unlock_irqrestore(&vga_lock, flags);
rc = -ENODEV;
break;
}
conflict = __vga_tryget(vgadev, rsrc);
spin_unlock_irqrestore(&vga_lock, flags);
if (conflict == NULL)
break;
init_waitqueue_entry(&wait, current);
add_wait_queue(&vga_wait_queue, &wait);
set_current_state(interruptible ?
TASK_INTERRUPTIBLE :
TASK_UNINTERRUPTIBLE);
if (signal_pending(current)) {
rc = -EINTR;
break;
}
schedule();
remove_wait_queue(&vga_wait_queue, &wait);
set_current_state(TASK_RUNNING);
}
return rc;
}
int vga_tryget(struct pci_dev *pdev, unsigned int rsrc)
{
struct vga_device *vgadev;
unsigned long flags;
int rc = 0;
vga_check_first_use();
if (pdev == NULL)
pdev = vga_default_device();
if (pdev == NULL)
return 0;
spin_lock_irqsave(&vga_lock, flags);
vgadev = vgadev_find(pdev);
if (vgadev == NULL) {
rc = -ENODEV;
goto bail;
}
if (__vga_tryget(vgadev, rsrc))
rc = -EBUSY;
bail:
spin_unlock_irqrestore(&vga_lock, flags);
return rc;
}
void vga_put(struct pci_dev *pdev, unsigned int rsrc)
{
struct vga_device *vgadev;
unsigned long flags;
if (pdev == NULL)
pdev = vga_default_device();
if (pdev == NULL)
return;
spin_lock_irqsave(&vga_lock, flags);
vgadev = vgadev_find(pdev);
if (vgadev == NULL)
goto bail;
__vga_put(vgadev, rsrc);
bail:
spin_unlock_irqrestore(&vga_lock, flags);
}
static void vga_arbiter_check_bridge_sharing(struct vga_device *vgadev)
{
struct vga_device *same_bridge_vgadev;
struct pci_bus *new_bus, *bus;
struct pci_dev *new_bridge, *bridge;
vgadev->bridge_has_one_vga = true;
if (list_empty(&vga_list))
return;
new_bus = vgadev->pdev->bus;
while (new_bus) {
new_bridge = new_bus->self;
list_for_each_entry(same_bridge_vgadev, &vga_list, list) {
bus = same_bridge_vgadev->pdev->bus;
bridge = bus->self;
if (new_bridge == bridge) {
same_bridge_vgadev->bridge_has_one_vga = false;
}
while (bus) {
bridge = bus->self;
if (bridge) {
if (bridge == vgadev->pdev->bus->self)
vgadev->bridge_has_one_vga = false;
}
bus = bus->parent;
}
}
new_bus = new_bus->parent;
}
}
static bool vga_arbiter_add_pci_device(struct pci_dev *pdev)
{
struct vga_device *vgadev;
unsigned long flags;
struct pci_bus *bus;
struct pci_dev *bridge;
u16 cmd;
if ((pdev->class >> 8) != PCI_CLASS_DISPLAY_VGA)
return false;
vgadev = kmalloc(sizeof(struct vga_device), GFP_KERNEL);
if (vgadev == NULL) {
pr_err("vgaarb: failed to allocate pci device\n");
return false;
}
memset(vgadev, 0, sizeof(*vgadev));
spin_lock_irqsave(&vga_lock, flags);
if (vgadev_find(pdev) != NULL) {
BUG_ON(1);
goto fail;
}
vgadev->pdev = pdev;
vgadev->decodes = VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM |
VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
vga_decode_count++;
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if (cmd & PCI_COMMAND_IO)
vgadev->owns |= VGA_RSRC_LEGACY_IO;
if (cmd & PCI_COMMAND_MEMORY)
vgadev->owns |= VGA_RSRC_LEGACY_MEM;
bus = pdev->bus;
while (bus) {
bridge = bus->self;
if (bridge) {
u16 l;
pci_read_config_word(bridge, PCI_BRIDGE_CONTROL,
&l);
if (!(l & PCI_BRIDGE_CTL_VGA)) {
vgadev->owns = 0;
break;
}
}
bus = bus->parent;
}
#ifndef __ARCH_HAS_VGA_DEFAULT_DEVICE
if (vga_default == NULL &&
((vgadev->owns & VGA_RSRC_LEGACY_MASK) == VGA_RSRC_LEGACY_MASK))
vga_set_default_device(pdev);
#endif
vga_arbiter_check_bridge_sharing(vgadev);
list_add(&vgadev->list, &vga_list);
vga_count++;
pr_info("vgaarb: device added: PCI:%s,decodes=%s,owns=%s,locks=%s\n",
pci_name(pdev),
vga_iostate_to_str(vgadev->decodes),
vga_iostate_to_str(vgadev->owns),
vga_iostate_to_str(vgadev->locks));
spin_unlock_irqrestore(&vga_lock, flags);
return true;
fail:
spin_unlock_irqrestore(&vga_lock, flags);
kfree(vgadev);
return false;
}
static bool vga_arbiter_del_pci_device(struct pci_dev *pdev)
{
struct vga_device *vgadev;
unsigned long flags;
bool ret = true;
spin_lock_irqsave(&vga_lock, flags);
vgadev = vgadev_find(pdev);
if (vgadev == NULL) {
ret = false;
goto bail;
}
#ifndef __ARCH_HAS_VGA_DEFAULT_DEVICE
if (vga_default == pdev)
vga_set_default_device(NULL);
#endif
if (vgadev->decodes & (VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM))
vga_decode_count--;
list_del(&vgadev->list);
vga_count--;
vga_arb_device_card_gone(pdev);
wake_up_all(&vga_wait_queue);
bail:
spin_unlock_irqrestore(&vga_lock, flags);
kfree(vgadev);
return ret;
}
static inline void vga_update_device_decodes(struct vga_device *vgadev,
int new_decodes)
{
int old_decodes, decodes_removed, decodes_unlocked;
old_decodes = vgadev->decodes;
decodes_removed = ~new_decodes & old_decodes;
decodes_unlocked = vgadev->locks & decodes_removed;
vgadev->owns &= ~decodes_removed;
vgadev->decodes = new_decodes;
pr_info("vgaarb: device changed decodes: PCI:%s,olddecodes=%s,decodes=%s:owns=%s\n",
pci_name(vgadev->pdev),
vga_iostate_to_str(old_decodes),
vga_iostate_to_str(vgadev->decodes),
vga_iostate_to_str(vgadev->owns));
if (decodes_unlocked) {
if (decodes_unlocked & VGA_RSRC_LEGACY_IO)
vgadev->io_lock_cnt = 0;
if (decodes_unlocked & VGA_RSRC_LEGACY_MEM)
vgadev->mem_lock_cnt = 0;
__vga_put(vgadev, decodes_unlocked);
}
if (old_decodes & VGA_RSRC_LEGACY_MASK &&
!(new_decodes & VGA_RSRC_LEGACY_MASK))
vga_decode_count--;
if (!(old_decodes & VGA_RSRC_LEGACY_MASK) &&
new_decodes & VGA_RSRC_LEGACY_MASK)
vga_decode_count++;
pr_debug("vgaarb: decoding count now is: %d\n", vga_decode_count);
}
static void __vga_set_legacy_decoding(struct pci_dev *pdev, unsigned int decodes, bool userspace)
{
struct vga_device *vgadev;
unsigned long flags;
decodes &= VGA_RSRC_LEGACY_MASK;
spin_lock_irqsave(&vga_lock, flags);
vgadev = vgadev_find(pdev);
if (vgadev == NULL)
goto bail;
if (userspace && vgadev->set_vga_decode)
goto bail;
vga_update_device_decodes(vgadev, decodes);
bail:
spin_unlock_irqrestore(&vga_lock, flags);
}
void vga_set_legacy_decoding(struct pci_dev *pdev, unsigned int decodes)
{
__vga_set_legacy_decoding(pdev, decodes, false);
}
static int vga_pci_str_to_vars(char *buf, int count, unsigned int *domain,
unsigned int *bus, unsigned int *devfn)
{
int n;
unsigned int slot, func;
n = sscanf(buf, "PCI:%x:%x:%x.%x", domain, bus, &slot, &func);
if (n != 4)
return 0;
*devfn = PCI_DEVFN(slot, func);
return 1;
}
static ssize_t vga_arb_read(struct file *file, char __user * buf,
size_t count, loff_t *ppos)
{
struct vga_arb_private *priv = file->private_data;
struct vga_device *vgadev;
struct pci_dev *pdev;
unsigned long flags;
size_t len;
int rc;
char *lbuf;
lbuf = kmalloc(1024, GFP_KERNEL);
if (lbuf == NULL)
return -ENOMEM;
spin_lock_irqsave(&vga_lock, flags);
pdev = priv->target;
if (pdev == NULL || pdev == PCI_INVALID_CARD) {
spin_unlock_irqrestore(&vga_lock, flags);
len = sprintf(lbuf, "invalid");
goto done;
}
vgadev = vgadev_find(pdev);
if (vgadev == NULL) {
if (pdev == priv->target)
vga_arb_device_card_gone(pdev);
spin_unlock_irqrestore(&vga_lock, flags);
len = sprintf(lbuf, "invalid");
goto done;
}
len = snprintf(lbuf, 1024,
"count:%d,PCI:%s,decodes=%s,owns=%s,locks=%s(%d:%d)\n",
vga_decode_count, pci_name(pdev),
vga_iostate_to_str(vgadev->decodes),
vga_iostate_to_str(vgadev->owns),
vga_iostate_to_str(vgadev->locks),
vgadev->io_lock_cnt, vgadev->mem_lock_cnt);
spin_unlock_irqrestore(&vga_lock, flags);
done:
if (len > count)
len = count;
rc = copy_to_user(buf, lbuf, len);
kfree(lbuf);
if (rc)
return -EFAULT;
return len;
}
static ssize_t vga_arb_write(struct file *file, const char __user * buf,
size_t count, loff_t *ppos)
{
struct vga_arb_private *priv = file->private_data;
struct vga_arb_user_card *uc = NULL;
struct pci_dev *pdev;
unsigned int io_state;
char *kbuf, *curr_pos;
size_t remaining = count;
int ret_val;
int i;
kbuf = kmalloc(count + 1, GFP_KERNEL);
if (!kbuf)
return -ENOMEM;
if (copy_from_user(kbuf, buf, count)) {
kfree(kbuf);
return -EFAULT;
}
curr_pos = kbuf;
kbuf[count] = '\0';
if (strncmp(curr_pos, "lock ", 5) == 0) {
curr_pos += 5;
remaining -= 5;
pr_debug("client 0x%p called 'lock'\n", priv);
if (!vga_str_to_iostate(curr_pos, remaining, &io_state)) {
ret_val = -EPROTO;
goto done;
}
if (io_state == VGA_RSRC_NONE) {
ret_val = -EPROTO;
goto done;
}
pdev = priv->target;
if (priv->target == NULL) {
ret_val = -ENODEV;
goto done;
}
vga_get_uninterruptible(pdev, io_state);
for (i = 0; i < MAX_USER_CARDS; i++) {
if (priv->cards[i].pdev == pdev) {
if (io_state & VGA_RSRC_LEGACY_IO)
priv->cards[i].io_cnt++;
if (io_state & VGA_RSRC_LEGACY_MEM)
priv->cards[i].mem_cnt++;
break;
}
}
ret_val = count;
goto done;
} else if (strncmp(curr_pos, "unlock ", 7) == 0) {
curr_pos += 7;
remaining -= 7;
pr_debug("client 0x%p called 'unlock'\n", priv);
if (strncmp(curr_pos, "all", 3) == 0)
io_state = VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM;
else {
if (!vga_str_to_iostate
(curr_pos, remaining, &io_state)) {
ret_val = -EPROTO;
goto done;
}
}
pdev = priv->target;
if (priv->target == NULL) {
ret_val = -ENODEV;
goto done;
}
for (i = 0; i < MAX_USER_CARDS; i++) {
if (priv->cards[i].pdev == pdev)
uc = &priv->cards[i];
}
if (!uc) {
ret_val = -EINVAL;
goto done;
}
if (io_state & VGA_RSRC_LEGACY_IO && uc->io_cnt == 0) {
ret_val = -EINVAL;
goto done;
}
if (io_state & VGA_RSRC_LEGACY_MEM && uc->mem_cnt == 0) {
ret_val = -EINVAL;
goto done;
}
vga_put(pdev, io_state);
if (io_state & VGA_RSRC_LEGACY_IO)
uc->io_cnt--;
if (io_state & VGA_RSRC_LEGACY_MEM)
uc->mem_cnt--;
ret_val = count;
goto done;
} else if (strncmp(curr_pos, "trylock ", 8) == 0) {
curr_pos += 8;
remaining -= 8;
pr_debug("client 0x%p called 'trylock'\n", priv);
if (!vga_str_to_iostate(curr_pos, remaining, &io_state)) {
ret_val = -EPROTO;
goto done;
}
pdev = priv->target;
if (priv->target == NULL) {
ret_val = -ENODEV;
goto done;
}
if (vga_tryget(pdev, io_state)) {
for (i = 0; i < MAX_USER_CARDS; i++) {
if (priv->cards[i].pdev == pdev) {
if (io_state & VGA_RSRC_LEGACY_IO)
priv->cards[i].io_cnt++;
if (io_state & VGA_RSRC_LEGACY_MEM)
priv->cards[i].mem_cnt++;
break;
}
}
ret_val = count;
goto done;
} else {
ret_val = -EBUSY;
goto done;
}
} else if (strncmp(curr_pos, "target ", 7) == 0) {
unsigned int domain, bus, devfn;
struct vga_device *vgadev;
curr_pos += 7;
remaining -= 7;
pr_debug("client 0x%p called 'target'\n", priv);
if (!strncmp(curr_pos, "default", 7))
pdev = pci_dev_get(vga_default_device());
else {
if (!vga_pci_str_to_vars(curr_pos, remaining,
&domain, &bus, &devfn)) {
ret_val = -EPROTO;
goto done;
}
pr_debug("vgaarb: %s ==> %x:%x:%x.%x\n", curr_pos,
domain, bus, PCI_SLOT(devfn), PCI_FUNC(devfn));
pdev = pci_get_domain_bus_and_slot(domain, bus, devfn);
pr_debug("vgaarb: pdev %p\n", pdev);
if (!pdev) {
pr_err("vgaarb: invalid PCI address %x:%x:%x\n",
domain, bus, devfn);
ret_val = -ENODEV;
goto done;
}
}
vgadev = vgadev_find(pdev);
pr_debug("vgaarb: vgadev %p\n", vgadev);
if (vgadev == NULL) {
pr_err("vgaarb: this pci device is not a vga device\n");
pci_dev_put(pdev);
ret_val = -ENODEV;
goto done;
}
priv->target = pdev;
for (i = 0; i < MAX_USER_CARDS; i++) {
if (priv->cards[i].pdev == pdev)
break;
if (priv->cards[i].pdev == NULL) {
priv->cards[i].pdev = pdev;
priv->cards[i].io_cnt = 0;
priv->cards[i].mem_cnt = 0;
break;
}
}
if (i == MAX_USER_CARDS) {
pr_err("vgaarb: maximum user cards (%d) number reached!\n",
MAX_USER_CARDS);
pci_dev_put(pdev);
ret_val = -ENOMEM;
goto done;
}
ret_val = count;
pci_dev_put(pdev);
goto done;
} else if (strncmp(curr_pos, "decodes ", 8) == 0) {
curr_pos += 8;
remaining -= 8;
pr_debug("vgaarb: client 0x%p called 'decodes'\n", priv);
if (!vga_str_to_iostate(curr_pos, remaining, &io_state)) {
ret_val = -EPROTO;
goto done;
}
pdev = priv->target;
if (priv->target == NULL) {
ret_val = -ENODEV;
goto done;
}
__vga_set_legacy_decoding(pdev, io_state, true);
ret_val = count;
goto done;
}
kfree(kbuf);
return -EPROTO;
done:
kfree(kbuf);
return ret_val;
}
static unsigned int vga_arb_fpoll(struct file *file, poll_table * wait)
{
struct vga_arb_private *priv = file->private_data;
pr_debug("%s\n", __func__);
if (priv == NULL)
return -ENODEV;
poll_wait(file, &vga_wait_queue, wait);
return POLLIN;
}
static int vga_arb_open(struct inode *inode, struct file *file)
{
struct vga_arb_private *priv;
unsigned long flags;
pr_debug("%s\n", __func__);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
spin_lock_init(&priv->lock);
file->private_data = priv;
spin_lock_irqsave(&vga_user_lock, flags);
list_add(&priv->list, &vga_user_list);
spin_unlock_irqrestore(&vga_user_lock, flags);
priv->target = vga_default_device();
priv->cards[0].pdev = priv->target;
priv->cards[0].io_cnt = 0;
priv->cards[0].mem_cnt = 0;
return 0;
}
static int vga_arb_release(struct inode *inode, struct file *file)
{
struct vga_arb_private *priv = file->private_data;
struct vga_arb_user_card *uc;
unsigned long flags;
int i;
pr_debug("%s\n", __func__);
if (priv == NULL)
return -ENODEV;
spin_lock_irqsave(&vga_user_lock, flags);
list_del(&priv->list);
for (i = 0; i < MAX_USER_CARDS; i++) {
uc = &priv->cards[i];
if (uc->pdev == NULL)
continue;
pr_debug("uc->io_cnt == %d, uc->mem_cnt == %d\n",
uc->io_cnt, uc->mem_cnt);
while (uc->io_cnt--)
vga_put(uc->pdev, VGA_RSRC_LEGACY_IO);
while (uc->mem_cnt--)
vga_put(uc->pdev, VGA_RSRC_LEGACY_MEM);
}
spin_unlock_irqrestore(&vga_user_lock, flags);
kfree(priv);
return 0;
}
static void vga_arb_device_card_gone(struct pci_dev *pdev)
{
}
static void vga_arbiter_notify_clients(void)
{
struct vga_device *vgadev;
unsigned long flags;
uint32_t new_decodes;
bool new_state;
if (!vga_arbiter_used)
return;
spin_lock_irqsave(&vga_lock, flags);
list_for_each_entry(vgadev, &vga_list, list) {
if (vga_count > 1)
new_state = false;
else
new_state = true;
if (vgadev->set_vga_decode) {
new_decodes = vgadev->set_vga_decode(vgadev->cookie, new_state);
vga_update_device_decodes(vgadev, new_decodes);
}
}
spin_unlock_irqrestore(&vga_lock, flags);
}
static int pci_notify(struct notifier_block *nb, unsigned long action,
void *data)
{
struct device *dev = data;
struct pci_dev *pdev = to_pci_dev(dev);
bool notify = false;
pr_debug("%s\n", __func__);
if (action == BUS_NOTIFY_ADD_DEVICE)
notify = vga_arbiter_add_pci_device(pdev);
else if (action == BUS_NOTIFY_DEL_DEVICE)
notify = vga_arbiter_del_pci_device(pdev);
if (notify)
vga_arbiter_notify_clients();
return 0;
}
static int __init vga_arb_device_init(void)
{
int rc;
struct pci_dev *pdev;
struct vga_device *vgadev;
rc = misc_register(&vga_arb_device);
if (rc < 0)
pr_err("vgaarb: error %d registering device\n", rc);
bus_register_notifier(&pci_bus_type, &pci_notifier);
pdev = NULL;
while ((pdev =
pci_get_subsys(PCI_ANY_ID, PCI_ANY_ID, PCI_ANY_ID,
PCI_ANY_ID, pdev)) != NULL)
vga_arbiter_add_pci_device(pdev);
pr_info("vgaarb: loaded\n");
list_for_each_entry(vgadev, &vga_list, list) {
if (vgadev->bridge_has_one_vga)
pr_info("vgaarb: bridge control possible %s\n", pci_name(vgadev->pdev));
else
pr_info("vgaarb: no bridge control possible %s\n", pci_name(vgadev->pdev));
}
return rc;
}
