static void
ppp_print_hex (register __u8 * out, const __u8 * in, int count)
{
register __u8 next_ch;
static const char hex[] = "0123456789ABCDEF";
while (count-- > 0) {
next_ch = *in++;
*out++ = hex[(next_ch >> 4) & 0x0F];
*out++ = hex[next_ch & 0x0F];
++out;
}
}
static void
ppp_print_char (register __u8 * out, const __u8 * in, int count)
{
register __u8 next_ch;
while (count-- > 0) {
next_ch = *in++;
if (next_ch < 0x20 || next_ch > 0x7e)
*out++ = '.';
else {
*out++ = next_ch;
if (next_ch == '%')
*out++ = '%';
}
}
*out = '\0';
}
static void
ppp_print_buffer (const char *name, const __u8 *buf, int count)
{
__u8 line[44];
if (name != NULL)
printk(KERN_DEBUG "ppp_synctty: %s, count = %d\n", name, count);
while (count > 8) {
memset (line, 32, 44);
ppp_print_hex (line, buf, 8);
ppp_print_char (&line[8 * 3], buf, 8);
printk(KERN_DEBUG "%s\n", line);
count -= 8;
buf += 8;
}
if (count > 0) {
memset (line, 32, 44);
ppp_print_hex (line, buf, count);
ppp_print_char (&line[8 * 3], buf, count);
printk(KERN_DEBUG "%s\n", line);
}
}
static struct syncppp *sp_get(struct tty_struct *tty)
{
struct syncppp *ap;
read_lock(&disc_data_lock);
ap = tty->disc_data;
if (ap != NULL)
atomic_inc(&ap->refcnt);
read_unlock(&disc_data_lock);
return ap;
}
static void sp_put(struct syncppp *ap)
{
if (atomic_dec_and_test(&ap->refcnt))
complete(&ap->dead_cmp);
}
static int
ppp_sync_open(struct tty_struct *tty)
{
struct syncppp *ap;
int err;
int speed;
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
ap = kzalloc(sizeof(*ap), GFP_KERNEL);
err = -ENOMEM;
if (!ap)
goto out;
ap->tty = tty;
ap->mru = PPP_MRU;
spin_lock_init(&ap->xmit_lock);
spin_lock_init(&ap->recv_lock);
ap->xaccm[0] = ~0U;
ap->xaccm[3] = 0x60000000U;
ap->raccm = ~0U;
skb_queue_head_init(&ap->rqueue);
tasklet_init(&ap->tsk, ppp_sync_process, (unsigned long) ap);
atomic_set(&ap->refcnt, 1);
init_completion(&ap->dead_cmp);
ap->chan.private = ap;
ap->chan.ops = &sync_ops;
ap->chan.mtu = PPP_MRU;
ap->chan.hdrlen = 2;
speed = tty_get_baud_rate(tty);
ap->chan.speed = speed;
err = ppp_register_channel(&ap->chan);
if (err)
goto out_free;
tty->disc_data = ap;
tty->receive_room = 65536;
return 0;
out_free:
kfree(ap);
out:
return err;
}
static void
ppp_sync_close(struct tty_struct *tty)
{
struct syncppp *ap;
write_lock_irq(&disc_data_lock);
ap = tty->disc_data;
tty->disc_data = NULL;
write_unlock_irq(&disc_data_lock);
if (!ap)
return;
if (!atomic_dec_and_test(&ap->refcnt))
wait_for_completion(&ap->dead_cmp);
tasklet_kill(&ap->tsk);
ppp_unregister_channel(&ap->chan);
skb_queue_purge(&ap->rqueue);
kfree_skb(ap->tpkt);
kfree(ap);
}
static int ppp_sync_hangup(struct tty_struct *tty)
{
ppp_sync_close(tty);
return 0;
}
static ssize_t
ppp_sync_read(struct tty_struct *tty, struct file *file,
unsigned char __user *buf, size_t count)
{
return -EAGAIN;
}
static ssize_t
ppp_sync_write(struct tty_struct *tty, struct file *file,
const unsigned char *buf, size_t count)
{
return -EAGAIN;
}
static int
ppp_synctty_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct syncppp *ap = sp_get(tty);
int __user *p = (int __user *)arg;
int err, val;
if (!ap)
return -ENXIO;
err = -EFAULT;
switch (cmd) {
case PPPIOCGCHAN:
err = -EFAULT;
if (put_user(ppp_channel_index(&ap->chan), p))
break;
err = 0;
break;
case PPPIOCGUNIT:
err = -EFAULT;
if (put_user(ppp_unit_number(&ap->chan), p))
break;
err = 0;
break;
case TCFLSH:
if (arg == TCIOFLUSH || arg == TCOFLUSH)
ppp_sync_flush_output(ap);
err = tty_perform_flush(tty, arg);
break;
case FIONREAD:
val = 0;
if (put_user(val, p))
break;
err = 0;
break;
default:
err = tty_mode_ioctl(tty, file, cmd, arg);
break;
}
sp_put(ap);
return err;
}
static unsigned int
ppp_sync_poll(struct tty_struct *tty, struct file *file, poll_table *wait)
{
return 0;
}
static void
ppp_sync_receive(struct tty_struct *tty, const unsigned char *buf,
char *cflags, int count)
{
struct syncppp *ap = sp_get(tty);
unsigned long flags;
if (!ap)
return;
spin_lock_irqsave(&ap->recv_lock, flags);
ppp_sync_input(ap, buf, cflags, count);
spin_unlock_irqrestore(&ap->recv_lock, flags);
if (!skb_queue_empty(&ap->rqueue))
tasklet_schedule(&ap->tsk);
sp_put(ap);
tty_unthrottle(tty);
}
static void
ppp_sync_wakeup(struct tty_struct *tty)
{
struct syncppp *ap = sp_get(tty);
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
if (!ap)
return;
set_bit(XMIT_WAKEUP, &ap->xmit_flags);
tasklet_schedule(&ap->tsk);
sp_put(ap);
}
static int __init
ppp_sync_init(void)
{
int err;
err = tty_register_ldisc(N_SYNC_PPP, &ppp_sync_ldisc);
if (err != 0)
printk(KERN_ERR "PPP_sync: error %d registering line disc.\n",
err);
return err;
}
static int
ppp_sync_ioctl(struct ppp_channel *chan, unsigned int cmd, unsigned long arg)
{
struct syncppp *ap = chan->private;
int err, val;
u32 accm[8];
void __user *argp = (void __user *)arg;
u32 __user *p = argp;
err = -EFAULT;
switch (cmd) {
case PPPIOCGFLAGS:
val = ap->flags | ap->rbits;
if (put_user(val, (int __user *) argp))
break;
err = 0;
break;
case PPPIOCSFLAGS:
if (get_user(val, (int __user *) argp))
break;
ap->flags = val & ~SC_RCV_BITS;
spin_lock_irq(&ap->recv_lock);
ap->rbits = val & SC_RCV_BITS;
spin_unlock_irq(&ap->recv_lock);
err = 0;
break;
case PPPIOCGASYNCMAP:
if (put_user(ap->xaccm[0], p))
break;
err = 0;
break;
case PPPIOCSASYNCMAP:
if (get_user(ap->xaccm[0], p))
break;
err = 0;
break;
case PPPIOCGRASYNCMAP:
if (put_user(ap->raccm, p))
break;
err = 0;
break;
case PPPIOCSRASYNCMAP:
if (get_user(ap->raccm, p))
break;
err = 0;
break;
case PPPIOCGXASYNCMAP:
if (copy_to_user(argp, ap->xaccm, sizeof(ap->xaccm)))
break;
err = 0;
break;
case PPPIOCSXASYNCMAP:
if (copy_from_user(accm, argp, sizeof(accm)))
break;
accm[2] &= ~0x40000000U;
accm[3] |= 0x60000000U;
memcpy(ap->xaccm, accm, sizeof(ap->xaccm));
err = 0;
break;
case PPPIOCGMRU:
if (put_user(ap->mru, (int __user *) argp))
break;
err = 0;
break;
case PPPIOCSMRU:
if (get_user(val, (int __user *) argp))
break;
if (val < PPP_MRU)
val = PPP_MRU;
ap->mru = val;
err = 0;
break;
default:
err = -ENOTTY;
}
return err;
}
static void ppp_sync_process(unsigned long arg)
{
struct syncppp *ap = (struct syncppp *) arg;
struct sk_buff *skb;
while ((skb = skb_dequeue(&ap->rqueue)) != NULL) {
if (skb->len == 0) {
ppp_input_error(&ap->chan, 0);
kfree_skb(skb);
}
else
ppp_input(&ap->chan, skb);
}
if (test_bit(XMIT_WAKEUP, &ap->xmit_flags) && ppp_sync_push(ap))
ppp_output_wakeup(&ap->chan);
}
static struct sk_buff*
ppp_sync_txmunge(struct syncppp *ap, struct sk_buff *skb)
{
int proto;
unsigned char *data;
int islcp;
data = skb->data;
proto = get_unaligned_be16(data);
islcp = proto == PPP_LCP && 1 <= data[2] && data[2] <= 7;
if (data[0] == 0 && (ap->flags & SC_COMP_PROT) && !islcp)
skb_pull(skb,1);
if ((ap->flags & SC_COMP_AC) == 0 || islcp) {
if (skb_headroom(skb) < 2) {
struct sk_buff *npkt = dev_alloc_skb(skb->len + 2);
if (npkt == NULL) {
kfree_skb(skb);
return NULL;
}
skb_reserve(npkt,2);
skb_copy_from_linear_data(skb,
skb_put(npkt, skb->len), skb->len);
kfree_skb(skb);
skb = npkt;
}
skb_push(skb,2);
skb->data[0] = PPP_ALLSTATIONS;
skb->data[1] = PPP_UI;
}
ap->last_xmit = jiffies;
if (skb && ap->flags & SC_LOG_OUTPKT)
ppp_print_buffer ("send buffer", skb->data, skb->len);
return skb;
}
static int
ppp_sync_send(struct ppp_channel *chan, struct sk_buff *skb)
{
struct syncppp *ap = chan->private;
ppp_sync_push(ap);
if (test_and_set_bit(XMIT_FULL, &ap->xmit_flags))
return 0;
skb = ppp_sync_txmunge(ap, skb);
if (skb != NULL)
ap->tpkt = skb;
else
clear_bit(XMIT_FULL, &ap->xmit_flags);
ppp_sync_push(ap);
return 1;
}
static int
ppp_sync_push(struct syncppp *ap)
{
int sent, done = 0;
struct tty_struct *tty = ap->tty;
int tty_stuffed = 0;
if (!spin_trylock_bh(&ap->xmit_lock))
return 0;
for (;;) {
if (test_and_clear_bit(XMIT_WAKEUP, &ap->xmit_flags))
tty_stuffed = 0;
if (!tty_stuffed && ap->tpkt) {
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
sent = tty->ops->write(tty, ap->tpkt->data, ap->tpkt->len);
if (sent < 0)
goto flush;
if (sent < ap->tpkt->len) {
tty_stuffed = 1;
} else {
kfree_skb(ap->tpkt);
ap->tpkt = NULL;
clear_bit(XMIT_FULL, &ap->xmit_flags);
done = 1;
}
continue;
}
spin_unlock_bh(&ap->xmit_lock);
if (!(test_bit(XMIT_WAKEUP, &ap->xmit_flags) ||
(!tty_stuffed && ap->tpkt)))
break;
if (!spin_trylock_bh(&ap->xmit_lock))
break;
}
return done;
flush:
if (ap->tpkt) {
kfree_skb(ap->tpkt);
ap->tpkt = NULL;
clear_bit(XMIT_FULL, &ap->xmit_flags);
done = 1;
}
spin_unlock_bh(&ap->xmit_lock);
return done;
}
static void
ppp_sync_flush_output(struct syncppp *ap)
{
int done = 0;
spin_lock_bh(&ap->xmit_lock);
if (ap->tpkt != NULL) {
kfree_skb(ap->tpkt);
ap->tpkt = NULL;
clear_bit(XMIT_FULL, &ap->xmit_flags);
done = 1;
}
spin_unlock_bh(&ap->xmit_lock);
if (done)
ppp_output_wakeup(&ap->chan);
}
static void
ppp_sync_input(struct syncppp *ap, const unsigned char *buf,
char *flags, int count)
{
struct sk_buff *skb;
unsigned char *p;
if (count == 0)
return;
if (ap->flags & SC_LOG_INPKT)
ppp_print_buffer ("receive buffer", buf, count);
skb = dev_alloc_skb(ap->mru + PPP_HDRLEN + 2);
if (!skb) {
printk(KERN_ERR "PPPsync: no memory (input pkt)\n");
goto err;
}
if (buf[0] != PPP_ALLSTATIONS)
skb_reserve(skb, 2 + (buf[0] & 1));
if (flags && *flags) {
goto err;
} else if (count > skb_tailroom(skb)) {
goto err;
}
p = skb_put(skb, count);
memcpy(p, buf, count);
p = skb->data;
if (p[0] == PPP_ALLSTATIONS && p[1] == PPP_UI) {
if (skb->len < 3)
goto err;
p = skb_pull(skb, 2);
}
if (p[0] & 1) {
skb_push(skb, 1)[0] = 0;
} else if (skb->len < 2)
goto err;
skb_queue_tail(&ap->rqueue, skb);
return;
err:
if (skb || (skb = dev_alloc_skb(0))) {
skb_trim(skb, 0);
skb_queue_tail(&ap->rqueue, skb);
}
}
static void __exit
ppp_sync_cleanup(void)
{
if (tty_unregister_ldisc(N_SYNC_PPP) != 0)
printk(KERN_ERR "failed to unregister Sync PPP line discipline\n");
}
