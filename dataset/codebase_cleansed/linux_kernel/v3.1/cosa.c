static inline struct channel_data* dev_to_chan(struct net_device *dev)
{
return (struct channel_data *)dev_to_hdlc(dev)->priv;
}
static int __init cosa_init(void)
{
int i, err = 0;
if (cosa_major > 0) {
if (register_chrdev(cosa_major, "cosa", &cosa_fops)) {
pr_warn("unable to get major %d\n", cosa_major);
err = -EIO;
goto out;
}
} else {
if (!(cosa_major=register_chrdev(0, "cosa", &cosa_fops))) {
pr_warn("unable to register chardev\n");
err = -EIO;
goto out;
}
}
for (i=0; i<MAX_CARDS; i++)
cosa_cards[i].num = -1;
for (i=0; io[i] != 0 && i < MAX_CARDS; i++)
cosa_probe(io[i], irq[i], dma[i]);
if (!nr_cards) {
pr_warn("no devices found\n");
unregister_chrdev(cosa_major, "cosa");
err = -ENODEV;
goto out;
}
cosa_class = class_create(THIS_MODULE, "cosa");
if (IS_ERR(cosa_class)) {
err = PTR_ERR(cosa_class);
goto out_chrdev;
}
for (i = 0; i < nr_cards; i++)
device_create(cosa_class, NULL, MKDEV(cosa_major, i), NULL,
"cosa%d", i);
err = 0;
goto out;
out_chrdev:
unregister_chrdev(cosa_major, "cosa");
out:
return err;
}
static void __exit cosa_exit(void)
{
struct cosa_data *cosa;
int i;
for (i = 0; i < nr_cards; i++)
device_destroy(cosa_class, MKDEV(cosa_major, i));
class_destroy(cosa_class);
for (cosa = cosa_cards; nr_cards--; cosa++) {
for (i = 0; i < cosa->nchannels; i++) {
unregister_hdlc_device(cosa->chan[i].netdev);
free_netdev(cosa->chan[i].netdev);
}
kfree(cosa->chan);
kfree(cosa->bouncebuf);
free_irq(cosa->irq, cosa);
free_dma(cosa->dma);
release_region(cosa->datareg, is_8bit(cosa) ? 2 : 4);
}
unregister_chrdev(cosa_major, "cosa");
}
static int cosa_probe(int base, int irq, int dma)
{
struct cosa_data *cosa = cosa_cards+nr_cards;
int i, err = 0;
memset(cosa, 0, sizeof(struct cosa_data));
if ((irq >= 0 && irq < 2) || irq > 15 || (irq < 10 && irq > 7)) {
pr_info("invalid IRQ %d\n", irq);
return -1;
}
if (base < 0x100 || base > 0x3ff || base & 0x7) {
pr_info("invalid I/O address 0x%x\n", base);
return -1;
}
if (dma < 0 || dma == 4 || dma > 7) {
pr_info("invalid DMA %d\n", dma);
return -1;
}
if (((base & 0x8) && dma < 4) || (!(base & 0x8) && dma > 3)) {
pr_info("8/16 bit base and DMA mismatch (base=0x%x, dma=%d)\n",
base, dma);
return -1;
}
cosa->dma = dma;
cosa->datareg = base;
cosa->statusreg = is_8bit(cosa)?base+1:base+2;
spin_lock_init(&cosa->lock);
if (!request_region(base, is_8bit(cosa)?2:4,"cosa"))
return -1;
if (cosa_reset_and_read_id(cosa, cosa->id_string) < 0) {
printk(KERN_DEBUG "probe at 0x%x failed.\n", base);
err = -1;
goto err_out;
}
if (!strncmp(cosa->id_string, "SRP", 3))
cosa->type = "srp";
else if (!strncmp(cosa->id_string, "COSA", 4))
cosa->type = is_8bit(cosa)? "cosa8": "cosa16";
else {
#ifndef COSA_ISA_AUTOPROBE
pr_info("valid signature not found at 0x%x\n", base);
#endif
err = -1;
goto err_out;
}
release_region(base, is_8bit(cosa)?2:4);
if (!request_region(base, is_8bit(cosa)?2:4, cosa->type)) {
printk(KERN_DEBUG "changing name at 0x%x failed.\n", base);
return -1;
}
if (irq < 0) {
unsigned long irqs;
irqs = probe_irq_on();
set_current_state(TASK_INTERRUPTIBLE);
cosa_putstatus(cosa, SR_TX_INT_ENA);
schedule_timeout(30);
irq = probe_irq_off(irqs);
cosa_putstatus(cosa, 0);
cosa_getdata8(cosa);
if (irq < 0) {
pr_info("multiple interrupts obtained (%d, board at 0x%x)\n",
irq, cosa->datareg);
err = -1;
goto err_out;
}
if (irq == 0) {
pr_info("no interrupt obtained (board at 0x%x)\n",
cosa->datareg);
}
}
cosa->irq = irq;
cosa->num = nr_cards;
cosa->usage = 0;
cosa->nchannels = 2;
if (request_irq(cosa->irq, cosa_interrupt, 0, cosa->type, cosa)) {
err = -1;
goto err_out;
}
if (request_dma(cosa->dma, cosa->type)) {
err = -1;
goto err_out1;
}
cosa->bouncebuf = kmalloc(COSA_MTU, GFP_KERNEL|GFP_DMA);
if (!cosa->bouncebuf) {
err = -ENOMEM;
goto err_out2;
}
sprintf(cosa->name, "cosa%d", cosa->num);
cosa->chan = kcalloc(cosa->nchannels, sizeof(struct channel_data), GFP_KERNEL);
if (!cosa->chan) {
err = -ENOMEM;
goto err_out3;
}
for (i = 0; i < cosa->nchannels; i++) {
struct channel_data *chan = &cosa->chan[i];
chan->cosa = cosa;
chan->num = i;
sprintf(chan->name, "cosa%dc%d", chan->cosa->num, i);
mutex_init(&chan->rlock);
sema_init(&chan->wsem, 1);
if (!(chan->netdev = alloc_hdlcdev(chan))) {
pr_warn("%s: alloc_hdlcdev failed\n", chan->name);
goto err_hdlcdev;
}
dev_to_hdlc(chan->netdev)->attach = cosa_net_attach;
dev_to_hdlc(chan->netdev)->xmit = cosa_net_tx;
chan->netdev->netdev_ops = &cosa_ops;
chan->netdev->watchdog_timeo = TX_TIMEOUT;
chan->netdev->base_addr = chan->cosa->datareg;
chan->netdev->irq = chan->cosa->irq;
chan->netdev->dma = chan->cosa->dma;
if (register_hdlc_device(chan->netdev)) {
netdev_warn(chan->netdev,
"register_hdlc_device() failed\n");
free_netdev(chan->netdev);
goto err_hdlcdev;
}
}
pr_info("cosa%d: %s (%s at 0x%x irq %d dma %d), %d channels\n",
cosa->num, cosa->id_string, cosa->type,
cosa->datareg, cosa->irq, cosa->dma, cosa->nchannels);
return nr_cards++;
err_hdlcdev:
while (i-- > 0) {
unregister_hdlc_device(cosa->chan[i].netdev);
free_netdev(cosa->chan[i].netdev);
}
kfree(cosa->chan);
err_out3:
kfree(cosa->bouncebuf);
err_out2:
free_dma(cosa->dma);
err_out1:
free_irq(cosa->irq, cosa);
err_out:
release_region(cosa->datareg,is_8bit(cosa)?2:4);
pr_notice("cosa%d: allocating resources failed\n", cosa->num);
return err;
}
static int cosa_net_attach(struct net_device *dev, unsigned short encoding,
unsigned short parity)
{
if (encoding == ENCODING_NRZ && parity == PARITY_CRC16_PR1_CCITT)
return 0;
return -EINVAL;
}
static int cosa_net_open(struct net_device *dev)
{
struct channel_data *chan = dev_to_chan(dev);
int err;
unsigned long flags;
if (!(chan->cosa->firmware_status & COSA_FW_START)) {
pr_notice("%s: start the firmware first (status %d)\n",
chan->cosa->name, chan->cosa->firmware_status);
return -EPERM;
}
spin_lock_irqsave(&chan->cosa->lock, flags);
if (chan->usage != 0) {
pr_warn("%s: cosa_net_open called with usage count %d\n",
chan->name, chan->usage);
spin_unlock_irqrestore(&chan->cosa->lock, flags);
return -EBUSY;
}
chan->setup_rx = cosa_net_setup_rx;
chan->tx_done = cosa_net_tx_done;
chan->rx_done = cosa_net_rx_done;
chan->usage = -1;
chan->cosa->usage++;
spin_unlock_irqrestore(&chan->cosa->lock, flags);
err = hdlc_open(dev);
if (err) {
spin_lock_irqsave(&chan->cosa->lock, flags);
chan->usage = 0;
chan->cosa->usage--;
spin_unlock_irqrestore(&chan->cosa->lock, flags);
return err;
}
netif_start_queue(dev);
cosa_enable_rx(chan);
return 0;
}
static netdev_tx_t cosa_net_tx(struct sk_buff *skb,
struct net_device *dev)
{
struct channel_data *chan = dev_to_chan(dev);
netif_stop_queue(dev);
chan->tx_skb = skb;
cosa_start_tx(chan, skb->data, skb->len);
return NETDEV_TX_OK;
}
static void cosa_net_timeout(struct net_device *dev)
{
struct channel_data *chan = dev_to_chan(dev);
if (test_bit(RXBIT, &chan->cosa->rxtx)) {
chan->netdev->stats.rx_errors++;
chan->netdev->stats.rx_missed_errors++;
} else {
chan->netdev->stats.tx_errors++;
chan->netdev->stats.tx_aborted_errors++;
}
cosa_kick(chan->cosa);
if (chan->tx_skb) {
dev_kfree_skb(chan->tx_skb);
chan->tx_skb = NULL;
}
netif_wake_queue(dev);
}
static int cosa_net_close(struct net_device *dev)
{
struct channel_data *chan = dev_to_chan(dev);
unsigned long flags;
netif_stop_queue(dev);
hdlc_close(dev);
cosa_disable_rx(chan);
spin_lock_irqsave(&chan->cosa->lock, flags);
if (chan->rx_skb) {
kfree_skb(chan->rx_skb);
chan->rx_skb = NULL;
}
if (chan->tx_skb) {
kfree_skb(chan->tx_skb);
chan->tx_skb = NULL;
}
chan->usage = 0;
chan->cosa->usage--;
spin_unlock_irqrestore(&chan->cosa->lock, flags);
return 0;
}
static char *cosa_net_setup_rx(struct channel_data *chan, int size)
{
kfree_skb(chan->rx_skb);
chan->rx_skb = dev_alloc_skb(size);
if (chan->rx_skb == NULL) {
pr_notice("%s: Memory squeeze, dropping packet\n", chan->name);
chan->netdev->stats.rx_dropped++;
return NULL;
}
chan->netdev->trans_start = jiffies;
return skb_put(chan->rx_skb, size);
}
static int cosa_net_rx_done(struct channel_data *chan)
{
if (!chan->rx_skb) {
pr_warn("%s: rx_done with empty skb!\n", chan->name);
chan->netdev->stats.rx_errors++;
chan->netdev->stats.rx_frame_errors++;
return 0;
}
chan->rx_skb->protocol = hdlc_type_trans(chan->rx_skb, chan->netdev);
chan->rx_skb->dev = chan->netdev;
skb_reset_mac_header(chan->rx_skb);
chan->netdev->stats.rx_packets++;
chan->netdev->stats.rx_bytes += chan->cosa->rxsize;
netif_rx(chan->rx_skb);
chan->rx_skb = NULL;
return 0;
}
static int cosa_net_tx_done(struct channel_data *chan, int size)
{
if (!chan->tx_skb) {
pr_warn("%s: tx_done with empty skb!\n", chan->name);
chan->netdev->stats.tx_errors++;
chan->netdev->stats.tx_aborted_errors++;
return 1;
}
dev_kfree_skb_irq(chan->tx_skb);
chan->tx_skb = NULL;
chan->netdev->stats.tx_packets++;
chan->netdev->stats.tx_bytes += size;
netif_wake_queue(chan->netdev);
return 1;
}
static ssize_t cosa_read(struct file *file,
char __user *buf, size_t count, loff_t *ppos)
{
DECLARE_WAITQUEUE(wait, current);
unsigned long flags;
struct channel_data *chan = file->private_data;
struct cosa_data *cosa = chan->cosa;
char *kbuf;
if (!(cosa->firmware_status & COSA_FW_START)) {
pr_notice("%s: start the firmware first (status %d)\n",
cosa->name, cosa->firmware_status);
return -EPERM;
}
if (mutex_lock_interruptible(&chan->rlock))
return -ERESTARTSYS;
if ((chan->rxdata = kmalloc(COSA_MTU, GFP_DMA|GFP_KERNEL)) == NULL) {
pr_info("%s: cosa_read() - OOM\n", cosa->name);
mutex_unlock(&chan->rlock);
return -ENOMEM;
}
chan->rx_status = 0;
cosa_enable_rx(chan);
spin_lock_irqsave(&cosa->lock, flags);
add_wait_queue(&chan->rxwaitq, &wait);
while (!chan->rx_status) {
current->state = TASK_INTERRUPTIBLE;
spin_unlock_irqrestore(&cosa->lock, flags);
schedule();
spin_lock_irqsave(&cosa->lock, flags);
if (signal_pending(current) && chan->rx_status == 0) {
chan->rx_status = 1;
remove_wait_queue(&chan->rxwaitq, &wait);
current->state = TASK_RUNNING;
spin_unlock_irqrestore(&cosa->lock, flags);
mutex_unlock(&chan->rlock);
return -ERESTARTSYS;
}
}
remove_wait_queue(&chan->rxwaitq, &wait);
current->state = TASK_RUNNING;
kbuf = chan->rxdata;
count = chan->rxsize;
spin_unlock_irqrestore(&cosa->lock, flags);
mutex_unlock(&chan->rlock);
if (copy_to_user(buf, kbuf, count)) {
kfree(kbuf);
return -EFAULT;
}
kfree(kbuf);
return count;
}
static char *chrdev_setup_rx(struct channel_data *chan, int size)
{
chan->rxsize = size;
return chan->rxdata;
}
static int chrdev_rx_done(struct channel_data *chan)
{
if (chan->rx_status) {
kfree(chan->rxdata);
up(&chan->wsem);
}
chan->rx_status = 1;
wake_up_interruptible(&chan->rxwaitq);
return 1;
}
static ssize_t cosa_write(struct file *file,
const char __user *buf, size_t count, loff_t *ppos)
{
DECLARE_WAITQUEUE(wait, current);
struct channel_data *chan = file->private_data;
struct cosa_data *cosa = chan->cosa;
unsigned long flags;
char *kbuf;
if (!(cosa->firmware_status & COSA_FW_START)) {
pr_notice("%s: start the firmware first (status %d)\n",
cosa->name, cosa->firmware_status);
return -EPERM;
}
if (down_interruptible(&chan->wsem))
return -ERESTARTSYS;
if (count > COSA_MTU)
count = COSA_MTU;
if ((kbuf = kmalloc(count, GFP_KERNEL|GFP_DMA)) == NULL) {
pr_notice("%s: cosa_write() OOM - dropping packet\n",
cosa->name);
up(&chan->wsem);
return -ENOMEM;
}
if (copy_from_user(kbuf, buf, count)) {
up(&chan->wsem);
kfree(kbuf);
return -EFAULT;
}
chan->tx_status=0;
cosa_start_tx(chan, kbuf, count);
spin_lock_irqsave(&cosa->lock, flags);
add_wait_queue(&chan->txwaitq, &wait);
while (!chan->tx_status) {
current->state = TASK_INTERRUPTIBLE;
spin_unlock_irqrestore(&cosa->lock, flags);
schedule();
spin_lock_irqsave(&cosa->lock, flags);
if (signal_pending(current) && chan->tx_status == 0) {
chan->tx_status = 1;
remove_wait_queue(&chan->txwaitq, &wait);
current->state = TASK_RUNNING;
chan->tx_status = 1;
spin_unlock_irqrestore(&cosa->lock, flags);
up(&chan->wsem);
return -ERESTARTSYS;
}
}
remove_wait_queue(&chan->txwaitq, &wait);
current->state = TASK_RUNNING;
up(&chan->wsem);
spin_unlock_irqrestore(&cosa->lock, flags);
kfree(kbuf);
return count;
}
static int chrdev_tx_done(struct channel_data *chan, int size)
{
if (chan->tx_status) {
kfree(chan->txbuf);
up(&chan->wsem);
}
chan->tx_status = 1;
wake_up_interruptible(&chan->txwaitq);
return 1;
}
static unsigned int cosa_poll(struct file *file, poll_table *poll)
{
pr_info("cosa_poll is here\n");
return 0;
}
static int cosa_open(struct inode *inode, struct file *file)
{
struct cosa_data *cosa;
struct channel_data *chan;
unsigned long flags;
int n;
int ret = 0;
mutex_lock(&cosa_chardev_mutex);
if ((n=iminor(file->f_path.dentry->d_inode)>>CARD_MINOR_BITS)
>= nr_cards) {
ret = -ENODEV;
goto out;
}
cosa = cosa_cards+n;
if ((n=iminor(file->f_path.dentry->d_inode)
& ((1<<CARD_MINOR_BITS)-1)) >= cosa->nchannels) {
ret = -ENODEV;
goto out;
}
chan = cosa->chan + n;
file->private_data = chan;
spin_lock_irqsave(&cosa->lock, flags);
if (chan->usage < 0) {
spin_unlock_irqrestore(&cosa->lock, flags);
ret = -EBUSY;
goto out;
}
cosa->usage++;
chan->usage++;
chan->tx_done = chrdev_tx_done;
chan->setup_rx = chrdev_setup_rx;
chan->rx_done = chrdev_rx_done;
spin_unlock_irqrestore(&cosa->lock, flags);
out:
mutex_unlock(&cosa_chardev_mutex);
return ret;
}
static int cosa_release(struct inode *inode, struct file *file)
{
struct channel_data *channel = file->private_data;
struct cosa_data *cosa;
unsigned long flags;
cosa = channel->cosa;
spin_lock_irqsave(&cosa->lock, flags);
cosa->usage--;
channel->usage--;
spin_unlock_irqrestore(&cosa->lock, flags);
return 0;
}
static int cosa_fasync(struct inode *inode, struct file *file, int on)
{
int port = iminor(inode);
return fasync_helper(inode, file, on, &fasync[port]);
}
static inline int cosa_reset(struct cosa_data *cosa)
{
char idstring[COSA_MAX_ID_STRING];
if (cosa->usage > 1)
pr_info("cosa%d: WARNING: reset requested with cosa->usage > 1 (%d). Odd things may happen.\n",
cosa->num, cosa->usage);
cosa->firmware_status &= ~(COSA_FW_RESET|COSA_FW_START);
if (cosa_reset_and_read_id(cosa, idstring) < 0) {
pr_notice("cosa%d: reset failed\n", cosa->num);
return -EIO;
}
pr_info("cosa%d: resetting device: %s\n", cosa->num, idstring);
cosa->firmware_status |= COSA_FW_RESET;
return 0;
}
static inline int cosa_download(struct cosa_data *cosa, void __user *arg)
{
struct cosa_download d;
int i;
if (cosa->usage > 1)
pr_info("%s: WARNING: download of microcode requested with cosa->usage > 1 (%d). Odd things may happen.\n",
cosa->name, cosa->usage);
if (!(cosa->firmware_status & COSA_FW_RESET)) {
pr_notice("%s: reset the card first (status %d)\n",
cosa->name, cosa->firmware_status);
return -EPERM;
}
if (copy_from_user(&d, arg, sizeof(d)))
return -EFAULT;
if (d.addr < 0 || d.addr > COSA_MAX_FIRMWARE_SIZE)
return -EINVAL;
if (d.len < 0 || d.len > COSA_MAX_FIRMWARE_SIZE)
return -EINVAL;
cosa->firmware_status &= ~(COSA_FW_RESET|COSA_FW_DOWNLOAD);
i = download(cosa, d.code, d.len, d.addr);
if (i < 0) {
pr_notice("cosa%d: microcode download failed: %d\n",
cosa->num, i);
return -EIO;
}
pr_info("cosa%d: downloading microcode - 0x%04x bytes at 0x%04x\n",
cosa->num, d.len, d.addr);
cosa->firmware_status |= COSA_FW_RESET|COSA_FW_DOWNLOAD;
return 0;
}
static inline int cosa_readmem(struct cosa_data *cosa, void __user *arg)
{
struct cosa_download d;
int i;
if (cosa->usage > 1)
pr_info("cosa%d: WARNING: readmem requested with cosa->usage > 1 (%d). Odd things may happen.\n",
cosa->num, cosa->usage);
if (!(cosa->firmware_status & COSA_FW_RESET)) {
pr_notice("%s: reset the card first (status %d)\n",
cosa->name, cosa->firmware_status);
return -EPERM;
}
if (copy_from_user(&d, arg, sizeof(d)))
return -EFAULT;
cosa->firmware_status &= ~COSA_FW_RESET;
i = readmem(cosa, d.code, d.len, d.addr);
if (i < 0) {
pr_notice("cosa%d: reading memory failed: %d\n", cosa->num, i);
return -EIO;
}
pr_info("cosa%d: reading card memory - 0x%04x bytes at 0x%04x\n",
cosa->num, d.len, d.addr);
cosa->firmware_status |= COSA_FW_RESET;
return 0;
}
static inline int cosa_start(struct cosa_data *cosa, int address)
{
int i;
if (cosa->usage > 1)
pr_info("cosa%d: WARNING: start microcode requested with cosa->usage > 1 (%d). Odd things may happen.\n",
cosa->num, cosa->usage);
if ((cosa->firmware_status & (COSA_FW_RESET|COSA_FW_DOWNLOAD))
!= (COSA_FW_RESET|COSA_FW_DOWNLOAD)) {
pr_notice("%s: download the microcode and/or reset the card first (status %d)\n",
cosa->name, cosa->firmware_status);
return -EPERM;
}
cosa->firmware_status &= ~COSA_FW_RESET;
if ((i=startmicrocode(cosa, address)) < 0) {
pr_notice("cosa%d: start microcode at 0x%04x failed: %d\n",
cosa->num, address, i);
return -EIO;
}
pr_info("cosa%d: starting microcode at 0x%04x\n", cosa->num, address);
cosa->startaddr = address;
cosa->firmware_status |= COSA_FW_START;
return 0;
}
static inline int cosa_getidstr(struct cosa_data *cosa, char __user *string)
{
int l = strlen(cosa->id_string)+1;
if (copy_to_user(string, cosa->id_string, l))
return -EFAULT;
return l;
}
static inline int cosa_gettype(struct cosa_data *cosa, char __user *string)
{
int l = strlen(cosa->type)+1;
if (copy_to_user(string, cosa->type, l))
return -EFAULT;
return l;
}
static int cosa_ioctl_common(struct cosa_data *cosa,
struct channel_data *channel, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
switch (cmd) {
case COSAIORSET:
if (!capable(CAP_NET_ADMIN))
return -EACCES;
return cosa_reset(cosa);
case COSAIOSTRT:
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
return cosa_start(cosa, arg);
case COSAIODOWNLD:
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
return cosa_download(cosa, argp);
case COSAIORMEM:
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
return cosa_readmem(cosa, argp);
case COSAIORTYPE:
return cosa_gettype(cosa, argp);
case COSAIORIDSTR:
return cosa_getidstr(cosa, argp);
case COSAIONRCARDS:
return nr_cards;
case COSAIONRCHANS:
return cosa->nchannels;
case COSAIOBMSET:
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
if (is_8bit(cosa))
return -EINVAL;
if (arg != COSA_BM_OFF && arg != COSA_BM_ON)
return -EINVAL;
cosa->busmaster = arg;
return 0;
case COSAIOBMGET:
return cosa->busmaster;
}
return -ENOIOCTLCMD;
}
static int cosa_net_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
int rv;
struct channel_data *chan = dev_to_chan(dev);
rv = cosa_ioctl_common(chan->cosa, chan, cmd,
(unsigned long)ifr->ifr_data);
if (rv != -ENOIOCTLCMD)
return rv;
return hdlc_ioctl(dev, ifr, cmd);
}
static long cosa_chardev_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct channel_data *channel = file->private_data;
struct cosa_data *cosa;
long ret;
mutex_lock(&cosa_chardev_mutex);
cosa = channel->cosa;
ret = cosa_ioctl_common(cosa, channel, cmd, arg);
mutex_unlock(&cosa_chardev_mutex);
return ret;
}
static void cosa_enable_rx(struct channel_data *chan)
{
struct cosa_data *cosa = chan->cosa;
if (!test_and_set_bit(chan->num, &cosa->rxbitmap))
put_driver_status(cosa);
}
static void cosa_disable_rx(struct channel_data *chan)
{
struct cosa_data *cosa = chan->cosa;
if (test_and_clear_bit(chan->num, &cosa->rxbitmap))
put_driver_status(cosa);
}
static int cosa_start_tx(struct channel_data *chan, char *buf, int len)
{
struct cosa_data *cosa = chan->cosa;
unsigned long flags;
#ifdef DEBUG_DATA
int i;
pr_info("cosa%dc%d: starting tx(0x%x)",
chan->cosa->num, chan->num, len);
for (i=0; i<len; i++)
pr_cont(" %02x", buf[i]&0xff);
pr_cont("\n");
#endif
spin_lock_irqsave(&cosa->lock, flags);
chan->txbuf = buf;
chan->txsize = len;
if (len > COSA_MTU)
chan->txsize = COSA_MTU;
spin_unlock_irqrestore(&cosa->lock, flags);
set_bit(chan->num, &cosa->txbitmap);
put_driver_status(cosa);
return 0;
}
static void put_driver_status(struct cosa_data *cosa)
{
unsigned long flags;
int status;
spin_lock_irqsave(&cosa->lock, flags);
status = (cosa->rxbitmap ? DRIVER_RX_READY : 0)
| (cosa->txbitmap ? DRIVER_TX_READY : 0)
| (cosa->txbitmap? ~(cosa->txbitmap<<DRIVER_TXMAP_SHIFT)
&DRIVER_TXMAP_MASK : 0);
if (!cosa->rxtx) {
if (cosa->rxbitmap|cosa->txbitmap) {
if (!cosa->enabled) {
cosa_putstatus(cosa, SR_RX_INT_ENA);
#ifdef DEBUG_IO
debug_status_out(cosa, SR_RX_INT_ENA);
#endif
cosa->enabled = 1;
}
} else if (cosa->enabled) {
cosa->enabled = 0;
cosa_putstatus(cosa, 0);
#ifdef DEBUG_IO
debug_status_out(cosa, 0);
#endif
}
cosa_putdata8(cosa, status);
#ifdef DEBUG_IO
debug_data_cmd(cosa, status);
#endif
}
spin_unlock_irqrestore(&cosa->lock, flags);
}
static void put_driver_status_nolock(struct cosa_data *cosa)
{
int status;
status = (cosa->rxbitmap ? DRIVER_RX_READY : 0)
| (cosa->txbitmap ? DRIVER_TX_READY : 0)
| (cosa->txbitmap? ~(cosa->txbitmap<<DRIVER_TXMAP_SHIFT)
&DRIVER_TXMAP_MASK : 0);
if (cosa->rxbitmap|cosa->txbitmap) {
cosa_putstatus(cosa, SR_RX_INT_ENA);
#ifdef DEBUG_IO
debug_status_out(cosa, SR_RX_INT_ENA);
#endif
cosa->enabled = 1;
} else {
cosa_putstatus(cosa, 0);
#ifdef DEBUG_IO
debug_status_out(cosa, 0);
#endif
cosa->enabled = 0;
}
cosa_putdata8(cosa, status);
#ifdef DEBUG_IO
debug_data_cmd(cosa, status);
#endif
}
static void cosa_kick(struct cosa_data *cosa)
{
unsigned long flags, flags1;
char *s = "(probably) IRQ";
if (test_bit(RXBIT, &cosa->rxtx))
s = "RX DMA";
if (test_bit(TXBIT, &cosa->rxtx))
s = "TX DMA";
pr_info("%s: %s timeout - restarting\n", cosa->name, s);
spin_lock_irqsave(&cosa->lock, flags);
cosa->rxtx = 0;
flags1 = claim_dma_lock();
disable_dma(cosa->dma);
clear_dma_ff(cosa->dma);
release_dma_lock(flags1);
udelay(100);
cosa_putstatus(cosa, 0);
udelay(100);
(void) cosa_getdata8(cosa);
udelay(100);
cosa_putdata8(cosa, 0);
udelay(100);
put_driver_status_nolock(cosa);
spin_unlock_irqrestore(&cosa->lock, flags);
}
static int cosa_dma_able(struct channel_data *chan, char *buf, int len)
{
static int count;
unsigned long b = (unsigned long)buf;
if (b+len >= MAX_DMA_ADDRESS)
return 0;
if ((b^ (b+len)) & 0x10000) {
if (count++ < 5)
pr_info("%s: packet spanning a 64k boundary\n",
chan->name);
return 0;
}
return 1;
}
static int download(struct cosa_data *cosa, const char __user *microcode, int length, int address)
{
int i;
if (put_wait_data(cosa, 'w') == -1) return -1;
if ((i=get_wait_data(cosa)) != 'w') { printk("dnld: 0x%04x\n",i); return -2;}
if (get_wait_data(cosa) != '=') return -3;
if (puthexnumber(cosa, address) < 0) return -4;
if (put_wait_data(cosa, ' ') == -1) return -10;
if (get_wait_data(cosa) != ' ') return -11;
if (get_wait_data(cosa) != '=') return -12;
if (puthexnumber(cosa, address+length-1) < 0) return -13;
if (put_wait_data(cosa, ' ') == -1) return -18;
if (get_wait_data(cosa) != ' ') return -19;
while (length--) {
char c;
#ifndef SRP_DOWNLOAD_AT_BOOT
if (get_user(c, microcode))
return -23;
#else
c = *microcode;
#endif
if (put_wait_data(cosa, c) == -1)
return -20;
microcode++;
}
if (get_wait_data(cosa) != '\r') return -21;
if (get_wait_data(cosa) != '\n') return -22;
if (get_wait_data(cosa) != '.') return -23;
#if 0
printk(KERN_DEBUG "cosa%d: download completed.\n", cosa->num);
#endif
return 0;
}
static int startmicrocode(struct cosa_data *cosa, int address)
{
if (put_wait_data(cosa, 'g') == -1) return -1;
if (get_wait_data(cosa) != 'g') return -2;
if (get_wait_data(cosa) != '=') return -3;
if (puthexnumber(cosa, address) < 0) return -4;
if (put_wait_data(cosa, '\r') == -1) return -5;
if (get_wait_data(cosa) != '\r') return -6;
if (get_wait_data(cosa) != '\r') return -7;
if (get_wait_data(cosa) != '\n') return -8;
if (get_wait_data(cosa) != '\r') return -9;
if (get_wait_data(cosa) != '\n') return -10;
#if 0
printk(KERN_DEBUG "cosa%d: microcode started\n", cosa->num);
#endif
return 0;
}
static int readmem(struct cosa_data *cosa, char __user *microcode, int length, int address)
{
if (put_wait_data(cosa, 'r') == -1) return -1;
if ((get_wait_data(cosa)) != 'r') return -2;
if ((get_wait_data(cosa)) != '=') return -3;
if (puthexnumber(cosa, address) < 0) return -4;
if (put_wait_data(cosa, ' ') == -1) return -5;
if (get_wait_data(cosa) != ' ') return -6;
if (get_wait_data(cosa) != '=') return -7;
if (puthexnumber(cosa, address+length-1) < 0) return -8;
if (put_wait_data(cosa, ' ') == -1) return -9;
if (get_wait_data(cosa) != ' ') return -10;
while (length--) {
char c;
int i;
if ((i=get_wait_data(cosa)) == -1) {
pr_info("0x%04x bytes remaining\n", length);
return -11;
}
c=i;
#if 1
if (put_user(c, microcode))
return -23;
#else
*microcode = c;
#endif
microcode++;
}
if (get_wait_data(cosa) != '\r') return -21;
if (get_wait_data(cosa) != '\n') return -22;
if (get_wait_data(cosa) != '.') return -23;
#if 0
printk(KERN_DEBUG "cosa%d: readmem completed.\n", cosa->num);
#endif
return 0;
}
static int cosa_reset_and_read_id(struct cosa_data *cosa, char *idstring)
{
int i=0, id=0, prev=0, curr=0;
cosa_putstatus(cosa, 0);
cosa_getdata8(cosa);
cosa_putstatus(cosa, SR_RST);
#ifdef MODULE
msleep(500);
#else
udelay(5*100000);
#endif
cosa_putstatus(cosa, 0);
for (i=0; i<COSA_MAX_ID_STRING-1; i++, prev=curr) {
if ((curr = get_wait_data(cosa)) == -1) {
return -1;
}
curr &= 0xff;
if (curr != '\r' && curr != '\n' && curr != 0x2e)
idstring[id++] = curr;
if (curr == 0x2e && prev == '\n')
break;
}
idstring[id] = '\0';
return id;
}
static int get_wait_data(struct cosa_data *cosa)
{
int retries = 1000;
while (--retries) {
if (cosa_getstatus(cosa) & SR_RX_RDY) {
short r;
r = cosa_getdata8(cosa);
#if 0
pr_info("get_wait_data returning after %d retries\n",
999-retries);
#endif
return r;
}
schedule_timeout_interruptible(1);
}
pr_info("timeout in get_wait_data (status 0x%x)\n",
cosa_getstatus(cosa));
return -1;
}
static int put_wait_data(struct cosa_data *cosa, int data)
{
int retries = 1000;
while (--retries) {
if (cosa_getstatus(cosa) & SR_TX_RDY) {
cosa_putdata8(cosa, data);
#if 0
pr_info("Putdata: %d retries\n", 999-retries);
#endif
return 0;
}
#if 0
schedule_timeout_interruptible(1);
#endif
}
pr_info("cosa%d: timeout in put_wait_data (status 0x%x)\n",
cosa->num, cosa_getstatus(cosa));
return -1;
}
static int puthexnumber(struct cosa_data *cosa, int number)
{
char temp[5];
int i;
sprintf(temp, "%04X", number);
for (i=0; i<4; i++) {
if (put_wait_data(cosa, temp[i]) == -1) {
pr_notice("cosa%d: puthexnumber failed to write byte %d\n",
cosa->num, i);
return -1-2*i;
}
if (get_wait_data(cosa) != temp[i]) {
pr_notice("cosa%d: puthexhumber failed to read echo of byte %d\n",
cosa->num, i);
return -2-2*i;
}
}
return 0;
}
static inline void tx_interrupt(struct cosa_data *cosa, int status)
{
unsigned long flags, flags1;
#ifdef DEBUG_IRQS
pr_info("cosa%d: SR_DOWN_REQUEST status=0x%04x\n", cosa->num, status);
#endif
spin_lock_irqsave(&cosa->lock, flags);
set_bit(TXBIT, &cosa->rxtx);
if (!test_bit(IRQBIT, &cosa->rxtx)) {
int i=0;
if (!cosa->txbitmap) {
pr_warn("%s: No channel wants data in TX IRQ. Expect DMA timeout.\n",
cosa->name);
put_driver_status_nolock(cosa);
clear_bit(TXBIT, &cosa->rxtx);
spin_unlock_irqrestore(&cosa->lock, flags);
return;
}
while (1) {
cosa->txchan++;
i++;
if (cosa->txchan >= cosa->nchannels)
cosa->txchan = 0;
if (!(cosa->txbitmap & (1<<cosa->txchan)))
continue;
if (~status & (1 << (cosa->txchan+DRIVER_TXMAP_SHIFT)))
break;
if (i > cosa->nchannels) {
#ifdef DEBUG_IRQS
printk(KERN_DEBUG "%s: Forcing TX "
"to not-ready channel %d\n",
cosa->name, cosa->txchan);
#endif
break;
}
}
cosa->txsize = cosa->chan[cosa->txchan].txsize;
if (cosa_dma_able(cosa->chan+cosa->txchan,
cosa->chan[cosa->txchan].txbuf, cosa->txsize)) {
cosa->txbuf = cosa->chan[cosa->txchan].txbuf;
} else {
memcpy(cosa->bouncebuf, cosa->chan[cosa->txchan].txbuf,
cosa->txsize);
cosa->txbuf = cosa->bouncebuf;
}
}
if (is_8bit(cosa)) {
if (!test_bit(IRQBIT, &cosa->rxtx)) {
cosa_putstatus(cosa, SR_TX_INT_ENA);
cosa_putdata8(cosa, ((cosa->txchan << 5) & 0xe0)|
((cosa->txsize >> 8) & 0x1f));
#ifdef DEBUG_IO
debug_status_out(cosa, SR_TX_INT_ENA);
debug_data_out(cosa, ((cosa->txchan << 5) & 0xe0)|
((cosa->txsize >> 8) & 0x1f));
debug_data_in(cosa, cosa_getdata8(cosa));
#else
cosa_getdata8(cosa);
#endif
set_bit(IRQBIT, &cosa->rxtx);
spin_unlock_irqrestore(&cosa->lock, flags);
return;
} else {
clear_bit(IRQBIT, &cosa->rxtx);
cosa_putstatus(cosa, 0);
cosa_putdata8(cosa, cosa->txsize&0xff);
#ifdef DEBUG_IO
debug_status_out(cosa, 0);
debug_data_out(cosa, cosa->txsize&0xff);
#endif
}
} else {
cosa_putstatus(cosa, SR_TX_INT_ENA);
cosa_putdata16(cosa, ((cosa->txchan<<13) & 0xe000)
| (cosa->txsize & 0x1fff));
#ifdef DEBUG_IO
debug_status_out(cosa, SR_TX_INT_ENA);
debug_data_out(cosa, ((cosa->txchan<<13) & 0xe000)
| (cosa->txsize & 0x1fff));
debug_data_in(cosa, cosa_getdata8(cosa));
debug_status_out(cosa, 0);
#else
cosa_getdata8(cosa);
#endif
cosa_putstatus(cosa, 0);
}
if (cosa->busmaster) {
unsigned long addr = virt_to_bus(cosa->txbuf);
int count=0;
pr_info("busmaster IRQ\n");
while (!(cosa_getstatus(cosa)&SR_TX_RDY)) {
count++;
udelay(10);
if (count > 1000) break;
}
pr_info("status %x\n", cosa_getstatus(cosa));
pr_info("ready after %d loops\n", count);
cosa_putdata16(cosa, (addr >> 16)&0xffff);
count = 0;
while (!(cosa_getstatus(cosa)&SR_TX_RDY)) {
count++;
if (count > 1000) break;
udelay(10);
}
pr_info("ready after %d loops\n", count);
cosa_putdata16(cosa, addr &0xffff);
flags1 = claim_dma_lock();
set_dma_mode(cosa->dma, DMA_MODE_CASCADE);
enable_dma(cosa->dma);
release_dma_lock(flags1);
} else {
flags1 = claim_dma_lock();
disable_dma(cosa->dma);
clear_dma_ff(cosa->dma);
set_dma_mode(cosa->dma, DMA_MODE_WRITE);
set_dma_addr(cosa->dma, virt_to_bus(cosa->txbuf));
set_dma_count(cosa->dma, cosa->txsize);
enable_dma(cosa->dma);
release_dma_lock(flags1);
}
cosa_putstatus(cosa, SR_TX_DMA_ENA|SR_USR_INT_ENA);
#ifdef DEBUG_IO
debug_status_out(cosa, SR_TX_DMA_ENA|SR_USR_INT_ENA);
#endif
spin_unlock_irqrestore(&cosa->lock, flags);
}
static inline void rx_interrupt(struct cosa_data *cosa, int status)
{
unsigned long flags;
#ifdef DEBUG_IRQS
pr_info("cosa%d: SR_UP_REQUEST\n", cosa->num);
#endif
spin_lock_irqsave(&cosa->lock, flags);
set_bit(RXBIT, &cosa->rxtx);
if (is_8bit(cosa)) {
if (!test_bit(IRQBIT, &cosa->rxtx)) {
set_bit(IRQBIT, &cosa->rxtx);
put_driver_status_nolock(cosa);
cosa->rxsize = cosa_getdata8(cosa) <<8;
#ifdef DEBUG_IO
debug_data_in(cosa, cosa->rxsize >> 8);
#endif
spin_unlock_irqrestore(&cosa->lock, flags);
return;
} else {
clear_bit(IRQBIT, &cosa->rxtx);
cosa->rxsize |= cosa_getdata8(cosa) & 0xff;
#ifdef DEBUG_IO
debug_data_in(cosa, cosa->rxsize & 0xff);
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
} else {
cosa->rxsize = cosa_getdata16(cosa);
#ifdef DEBUG_IO
debug_data_in(cosa, cosa->rxsize);
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
if (((cosa->rxsize & 0xe000) >> 13) >= cosa->nchannels) {
pr_warn("%s: rx for unknown channel (0x%04x)\n",
cosa->name, cosa->rxsize);
spin_unlock_irqrestore(&cosa->lock, flags);
goto reject;
}
cosa->rxchan = cosa->chan + ((cosa->rxsize & 0xe000) >> 13);
cosa->rxsize &= 0x1fff;
spin_unlock_irqrestore(&cosa->lock, flags);
cosa->rxbuf = NULL;
if (cosa->rxchan->setup_rx)
cosa->rxbuf = cosa->rxchan->setup_rx(cosa->rxchan, cosa->rxsize);
if (!cosa->rxbuf) {
reject:
pr_info("cosa%d: rejecting packet on channel %d\n",
cosa->num, cosa->rxchan->num);
cosa->rxbuf = cosa->bouncebuf;
}
flags = claim_dma_lock();
disable_dma(cosa->dma);
clear_dma_ff(cosa->dma);
set_dma_mode(cosa->dma, DMA_MODE_READ);
if (cosa_dma_able(cosa->rxchan, cosa->rxbuf, cosa->rxsize & 0x1fff)) {
set_dma_addr(cosa->dma, virt_to_bus(cosa->rxbuf));
} else {
set_dma_addr(cosa->dma, virt_to_bus(cosa->bouncebuf));
}
set_dma_count(cosa->dma, (cosa->rxsize&0x1fff));
enable_dma(cosa->dma);
release_dma_lock(flags);
spin_lock_irqsave(&cosa->lock, flags);
cosa_putstatus(cosa, SR_RX_DMA_ENA|SR_USR_INT_ENA);
if (!is_8bit(cosa) && (status & SR_TX_RDY))
cosa_putdata8(cosa, DRIVER_RX_READY);
#ifdef DEBUG_IO
debug_status_out(cosa, SR_RX_DMA_ENA|SR_USR_INT_ENA);
if (!is_8bit(cosa) && (status & SR_TX_RDY))
debug_data_cmd(cosa, DRIVER_RX_READY);
#endif
spin_unlock_irqrestore(&cosa->lock, flags);
}
static inline void eot_interrupt(struct cosa_data *cosa, int status)
{
unsigned long flags, flags1;
spin_lock_irqsave(&cosa->lock, flags);
flags1 = claim_dma_lock();
disable_dma(cosa->dma);
clear_dma_ff(cosa->dma);
release_dma_lock(flags1);
if (test_bit(TXBIT, &cosa->rxtx)) {
struct channel_data *chan = cosa->chan+cosa->txchan;
if (chan->tx_done)
if (chan->tx_done(chan, cosa->txsize))
clear_bit(chan->num, &cosa->txbitmap);
} else if (test_bit(RXBIT, &cosa->rxtx)) {
#ifdef DEBUG_DATA
{
int i;
pr_info("cosa%dc%d: done rx(0x%x)",
cosa->num, cosa->rxchan->num, cosa->rxsize);
for (i=0; i<cosa->rxsize; i++)
pr_cont(" %02x", cosa->rxbuf[i]&0xff);
pr_cont("\n");
}
#endif
if (cosa->rxbuf == cosa->bouncebuf)
goto out;
if (!cosa_dma_able(cosa->rxchan, cosa->rxbuf, cosa->rxsize))
memcpy(cosa->rxbuf, cosa->bouncebuf, cosa->rxsize);
if (cosa->rxchan->rx_done)
if (cosa->rxchan->rx_done(cosa->rxchan))
clear_bit(cosa->rxchan->num, &cosa->rxbitmap);
} else {
pr_notice("cosa%d: unexpected EOT interrupt\n", cosa->num);
}
out:
cosa->rxtx = 0;
put_driver_status_nolock(cosa);
spin_unlock_irqrestore(&cosa->lock, flags);
}
static irqreturn_t cosa_interrupt(int irq, void *cosa_)
{
unsigned status;
int count = 0;
struct cosa_data *cosa = cosa_;
again:
status = cosa_getstatus(cosa);
#ifdef DEBUG_IRQS
pr_info("cosa%d: got IRQ, status 0x%02x\n", cosa->num, status & 0xff);
#endif
#ifdef DEBUG_IO
debug_status_in(cosa, status);
#endif
switch (status & SR_CMD_FROM_SRP_MASK) {
case SR_DOWN_REQUEST:
tx_interrupt(cosa, status);
break;
case SR_UP_REQUEST:
rx_interrupt(cosa, status);
break;
case SR_END_OF_TRANSFER:
eot_interrupt(cosa, status);
break;
default:
if (count++ < 100) {
udelay(100);
goto again;
}
pr_info("cosa%d: unknown status 0x%02x in IRQ after %d retries\n",
cosa->num, status & 0xff, count);
}
#ifdef DEBUG_IRQS
if (count)
pr_info("%s: %d-times got unknown status in IRQ\n",
cosa->name, count);
else
pr_info("%s: returning from IRQ\n", cosa->name);
#endif
return IRQ_HANDLED;
}
static void debug_status_in(struct cosa_data *cosa, int status)
{
char *s;
switch (status & SR_CMD_FROM_SRP_MASK) {
case SR_UP_REQUEST:
s = "RX_REQ";
break;
case SR_DOWN_REQUEST:
s = "TX_REQ";
break;
case SR_END_OF_TRANSFER:
s = "ET_REQ";
break;
default:
s = "NO_REQ";
break;
}
pr_info("%s: IO: status -> 0x%02x (%s%s%s%s)\n",
cosa->name,
status,
status & SR_USR_RQ ? "USR_RQ|" : "",
status & SR_TX_RDY ? "TX_RDY|" : "",
status & SR_RX_RDY ? "RX_RDY|" : "",
s);
}
static void debug_status_out(struct cosa_data *cosa, int status)
{
pr_info("%s: IO: status <- 0x%02x (%s%s%s%s%s%s)\n",
cosa->name,
status,
status & SR_RX_DMA_ENA ? "RXDMA|" : "!rxdma|",
status & SR_TX_DMA_ENA ? "TXDMA|" : "!txdma|",
status & SR_RST ? "RESET|" : "",
status & SR_USR_INT_ENA ? "USRINT|" : "!usrint|",
status & SR_TX_INT_ENA ? "TXINT|" : "!txint|",
status & SR_RX_INT_ENA ? "RXINT" : "!rxint");
}
static void debug_data_in(struct cosa_data *cosa, int data)
{
pr_info("%s: IO: data -> 0x%04x\n", cosa->name, data);
}
static void debug_data_out(struct cosa_data *cosa, int data)
{
pr_info("%s: IO: data <- 0x%04x\n", cosa->name, data);
}
static void debug_data_cmd(struct cosa_data *cosa, int data)
{
pr_info("%s: IO: data <- 0x%04x (%s|%s)\n",
cosa->name, data,
data & SR_RDY_RCV ? "RX_RDY" : "!rx_rdy",
data & SR_RDY_SND ? "TX_RDY" : "!tx_rdy");
}
