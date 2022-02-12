static int __init aoe_iflist_setup(char *str)
{
strncpy(aoe_iflist, str, IFLISTSZ);
aoe_iflist[IFLISTSZ - 1] = '\0';
return 1;
}
static int
tx(int id) __must_hold(&txlock
int
is_aoe_netif(struct net_device *ifp)
{
register char *p, *q;
register int len;
if (aoe_iflist[0] == '\0')
return 1;
p = aoe_iflist + strspn(aoe_iflist, WHITESPACE);
for (; *p; p = q + strspn(q, WHITESPACE)) {
q = p + strcspn(p, WHITESPACE);
if (q != p)
len = q - p;
else
len = strlen(p);
if (strlen(ifp->name) == len && !strncmp(ifp->name, p, len))
return 1;
if (q == p)
break;
}
return 0;
}
int
set_aoe_iflist(const char __user *user_str, size_t size)
{
if (size >= IFLISTSZ)
return -EINVAL;
if (copy_from_user(aoe_iflist, user_str, size)) {
printk(KERN_INFO "aoe: copy from user failed\n");
return -EFAULT;
}
aoe_iflist[size] = 0x00;
return 0;
}
void
aoenet_xmit(struct sk_buff_head *queue)
{
struct sk_buff *skb, *tmp;
ulong flags;
skb_queue_walk_safe(queue, skb, tmp) {
__skb_unlink(skb, queue);
spin_lock_irqsave(&txlock, flags);
skb_queue_tail(&skbtxq, skb);
spin_unlock_irqrestore(&txlock, flags);
wake_up(&txwq);
}
}
static int
aoenet_rcv(struct sk_buff *skb, struct net_device *ifp, struct packet_type *pt, struct net_device *orig_dev)
{
struct aoe_hdr *h;
struct aoe_atahdr *ah;
u32 n;
int sn;
if (dev_net(ifp) != &init_net)
goto exit;
skb = skb_share_check(skb, GFP_ATOMIC);
if (skb == NULL)
return 0;
if (!is_aoe_netif(ifp))
goto exit;
skb_push(skb, ETH_HLEN);
sn = sizeof(*h) + sizeof(*ah);
if (skb->len >= sn) {
sn -= skb_headlen(skb);
if (sn > 0 && !__pskb_pull_tail(skb, sn))
goto exit;
}
h = (struct aoe_hdr *) skb->data;
n = get_unaligned_be32(&h->tag);
if ((h->verfl & AOEFL_RSP) == 0 || (n & 1<<31))
goto exit;
if (h->verfl & AOEFL_ERR) {
n = h->err;
if (n > NECODES)
n = 0;
if (net_ratelimit())
printk(KERN_ERR
"%s%d.%d@%s; ecode=%d '%s'\n",
"aoe: error packet from ",
get_unaligned_be16(&h->major),
h->minor, skb->dev->name,
h->err, aoe_errlist[n]);
goto exit;
}
switch (h->cmd) {
case AOECMD_ATA:
skb = aoecmd_ata_rsp(skb);
break;
case AOECMD_CFG:
aoecmd_cfg_rsp(skb);
break;
default:
if (h->cmd >= AOECMD_VEND_MIN)
break;
pr_info("aoe: unknown AoE command type 0x%02x\n", h->cmd);
break;
}
if (!skb)
return 0;
exit:
dev_kfree_skb(skb);
return 0;
}
int __init
aoenet_init(void)
{
skb_queue_head_init(&skbtxq);
init_waitqueue_head(&txwq);
spin_lock_init(&txlock);
kts.lock = &txlock;
kts.fn = tx;
kts.waitq = &txwq;
kts.id = 0;
snprintf(kts.name, sizeof(kts.name), "aoe_tx%d", kts.id);
if (aoe_ktstart(&kts))
return -EAGAIN;
dev_add_pack(&aoe_pt);
return 0;
}
void
aoenet_exit(void)
{
aoe_ktstop(&kts);
skb_queue_purge(&skbtxq);
dev_remove_pack(&aoe_pt);
}
