static inline int tcp_probe_used(void)
{
return (tcp_probe.head - tcp_probe.tail) & (bufsize - 1);
}
static inline int tcp_probe_avail(void)
{
return bufsize - tcp_probe_used() - 1;
}
static int jtcp_rcv_established(struct sock *sk, struct sk_buff *skb,
struct tcphdr *th, unsigned len)
{
const struct tcp_sock *tp = tcp_sk(sk);
const struct inet_sock *inet = inet_sk(sk);
if ((port == 0 || ntohs(inet->inet_dport) == port ||
ntohs(inet->inet_sport) == port) &&
(full || tp->snd_cwnd != tcp_probe.lastcwnd)) {
spin_lock(&tcp_probe.lock);
if (tcp_probe_avail() > 1) {
struct tcp_log *p = tcp_probe.log + tcp_probe.head;
p->tstamp = ktime_get();
p->saddr = inet->inet_saddr;
p->sport = inet->inet_sport;
p->daddr = inet->inet_daddr;
p->dport = inet->inet_dport;
p->length = skb->len;
p->snd_nxt = tp->snd_nxt;
p->snd_una = tp->snd_una;
p->snd_cwnd = tp->snd_cwnd;
p->snd_wnd = tp->snd_wnd;
p->ssthresh = tcp_current_ssthresh(sk);
p->srtt = tp->srtt >> 3;
tcp_probe.head = (tcp_probe.head + 1) & (bufsize - 1);
}
tcp_probe.lastcwnd = tp->snd_cwnd;
spin_unlock(&tcp_probe.lock);
wake_up(&tcp_probe.wait);
}
jprobe_return();
return 0;
}
static int tcpprobe_open(struct inode * inode, struct file * file)
{
spin_lock_bh(&tcp_probe.lock);
tcp_probe.head = tcp_probe.tail = 0;
tcp_probe.start = ktime_get();
spin_unlock_bh(&tcp_probe.lock);
return 0;
}
static int tcpprobe_sprint(char *tbuf, int n)
{
const struct tcp_log *p
= tcp_probe.log + tcp_probe.tail;
struct timespec tv
= ktime_to_timespec(ktime_sub(p->tstamp, tcp_probe.start));
return scnprintf(tbuf, n,
"%lu.%09lu %pI4:%u %pI4:%u %d %#x %#x %u %u %u %u\n",
(unsigned long) tv.tv_sec,
(unsigned long) tv.tv_nsec,
&p->saddr, ntohs(p->sport),
&p->daddr, ntohs(p->dport),
p->length, p->snd_nxt, p->snd_una,
p->snd_cwnd, p->ssthresh, p->snd_wnd, p->srtt);
}
static ssize_t tcpprobe_read(struct file *file, char __user *buf,
size_t len, loff_t *ppos)
{
int error = 0;
size_t cnt = 0;
if (!buf)
return -EINVAL;
while (cnt < len) {
char tbuf[164];
int width;
error = wait_event_interruptible(tcp_probe.wait,
tcp_probe_used() > 0);
if (error)
break;
spin_lock_bh(&tcp_probe.lock);
if (tcp_probe.head == tcp_probe.tail) {
spin_unlock_bh(&tcp_probe.lock);
continue;
}
width = tcpprobe_sprint(tbuf, sizeof(tbuf));
if (cnt + width < len)
tcp_probe.tail = (tcp_probe.tail + 1) & (bufsize - 1);
spin_unlock_bh(&tcp_probe.lock);
if (cnt + width >= len)
break;
if (copy_to_user(buf + cnt, tbuf, width))
return -EFAULT;
cnt += width;
}
return cnt == 0 ? error : cnt;
}
static __init int tcpprobe_init(void)
{
int ret = -ENOMEM;
init_waitqueue_head(&tcp_probe.wait);
spin_lock_init(&tcp_probe.lock);
if (bufsize == 0)
return -EINVAL;
bufsize = roundup_pow_of_two(bufsize);
tcp_probe.log = kcalloc(bufsize, sizeof(struct tcp_log), GFP_KERNEL);
if (!tcp_probe.log)
goto err0;
if (!proc_net_fops_create(&init_net, procname, S_IRUSR, &tcpprobe_fops))
goto err0;
ret = register_jprobe(&tcp_jprobe);
if (ret)
goto err1;
pr_info("probe registered (port=%d) bufsize=%u\n", port, bufsize);
return 0;
err1:
proc_net_remove(&init_net, procname);
err0:
kfree(tcp_probe.log);
return ret;
}
static __exit void tcpprobe_exit(void)
{
proc_net_remove(&init_net, procname);
unregister_jprobe(&tcp_jprobe);
kfree(tcp_probe.log);
}
