static inline unsigned long rif_hash(const unsigned char *addr)
{
unsigned long x;
x = addr[0];
x = (x << 2) ^ addr[1];
x = (x << 2) ^ addr[2];
x = (x << 2) ^ addr[3];
x = (x << 2) ^ addr[4];
x = (x << 2) ^ addr[5];
x ^= x >> 8;
return x & (RIF_TABLE_SIZE - 1);
}
static int tr_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned len)
{
struct trh_hdr *trh;
int hdr_len;
if (type == ETH_P_IP || type == ETH_P_IPV6 || type == ETH_P_ARP)
{
struct trllc *trllc;
hdr_len = sizeof(struct trh_hdr) + sizeof(struct trllc);
trh = (struct trh_hdr *)skb_push(skb, hdr_len);
trllc = (struct trllc *)(trh+1);
trllc->dsap = trllc->ssap = EXTENDED_SAP;
trllc->llc = UI_CMD;
trllc->protid[0] = trllc->protid[1] = trllc->protid[2] = 0x00;
trllc->ethertype = htons(type);
}
else
{
hdr_len = sizeof(struct trh_hdr);
trh = (struct trh_hdr *)skb_push(skb, hdr_len);
}
trh->ac=AC;
trh->fc=LLC_FRAME;
if(saddr)
memcpy(trh->saddr,saddr,dev->addr_len);
else
memcpy(trh->saddr,dev->dev_addr,dev->addr_len);
if(daddr)
{
memcpy(trh->daddr,daddr,dev->addr_len);
tr_source_route(skb, trh, dev);
return hdr_len;
}
return -hdr_len;
}
static int tr_rebuild_header(struct sk_buff *skb)
{
struct trh_hdr *trh=(struct trh_hdr *)skb->data;
struct trllc *trllc=(struct trllc *)(skb->data+sizeof(struct trh_hdr));
struct net_device *dev = skb->dev;
if(trllc->ethertype != htons(ETH_P_IP)) {
printk("tr_rebuild_header: Don't know how to resolve type %04X addresses ?\n", ntohs(trllc->ethertype));
return 0;
}
#ifdef CONFIG_INET
if(arp_find(trh->daddr, skb)) {
return 1;
}
else
#endif
{
tr_source_route(skb,trh,dev);
return 0;
}
}
__be16 tr_type_trans(struct sk_buff *skb, struct net_device *dev)
{
struct trh_hdr *trh;
struct trllc *trllc;
unsigned riflen=0;
skb->dev = dev;
skb_reset_mac_header(skb);
trh = tr_hdr(skb);
if(trh->saddr[0] & TR_RII)
riflen = (ntohs(trh->rcf) & TR_RCF_LEN_MASK) >> 8;
trllc = (struct trllc *)(skb->data+sizeof(struct trh_hdr)-TR_MAXRIFLEN+riflen);
skb_pull(skb,sizeof(struct trh_hdr)-TR_MAXRIFLEN+riflen);
if(*trh->daddr & 0x80)
{
if(!memcmp(trh->daddr,dev->broadcast,TR_ALEN))
skb->pkt_type=PACKET_BROADCAST;
else
skb->pkt_type=PACKET_MULTICAST;
}
else if ( (trh->daddr[0] & 0x01) && (trh->daddr[1] & 0x00) && (trh->daddr[2] & 0x5E))
{
skb->pkt_type=PACKET_MULTICAST;
}
else if(dev->flags & IFF_PROMISC)
{
if(memcmp(trh->daddr, dev->dev_addr, TR_ALEN))
skb->pkt_type=PACKET_OTHERHOST;
}
if ((skb->pkt_type != PACKET_BROADCAST) &&
(skb->pkt_type != PACKET_MULTICAST))
tr_add_rif_info(trh,dev) ;
if (trllc->dsap == EXTENDED_SAP &&
(trllc->ethertype == htons(ETH_P_IP) ||
trllc->ethertype == htons(ETH_P_IPV6) ||
trllc->ethertype == htons(ETH_P_ARP)))
{
skb_pull(skb, sizeof(struct trllc));
return trllc->ethertype;
}
return htons(ETH_P_TR_802_2);
}
void tr_source_route(struct sk_buff *skb,struct trh_hdr *trh,
struct net_device *dev)
{
int slack;
unsigned int hash;
struct rif_cache *entry;
unsigned char *olddata;
unsigned long flags;
static const unsigned char mcast_func_addr[]
= {0xC0,0x00,0x00,0x04,0x00,0x00};
spin_lock_irqsave(&rif_lock, flags);
if( (!memcmp(&(trh->daddr[0]),&(dev->broadcast[0]),TR_ALEN)) ||
(!memcmp(&(trh->daddr[0]),&(mcast_func_addr[0]), TR_ALEN)) )
{
trh->rcf=htons((((sizeof(trh->rcf)) << 8) & TR_RCF_LEN_MASK)
| TR_RCF_FRAME2K | TR_RCF_LIMITED_BROADCAST);
trh->saddr[0]|=TR_RII;
}
else
{
hash = rif_hash(trh->daddr);
for(entry=rif_table[hash];entry && memcmp(&(entry->addr[0]),&(trh->daddr[0]),TR_ALEN);entry=entry->next);
if(entry)
{
#if TR_SR_DEBUG
printk("source routing for %pM\n", trh->daddr);
#endif
if(!entry->local_ring && (ntohs(entry->rcf) & TR_RCF_LEN_MASK) >> 8)
{
trh->rcf=entry->rcf;
memcpy(&trh->rseg[0],&entry->rseg[0],8*sizeof(unsigned short));
trh->rcf^=htons(TR_RCF_DIR_BIT);
trh->rcf&=htons(0x1fff);
trh->saddr[0]|=TR_RII;
#if TR_SR_DEBUG
printk("entry found with rcf %04x\n", entry->rcf);
}
else
{
printk("entry found but without rcf length, local=%02x\n", entry->local_ring);
#endif
}
entry->last_used=jiffies;
}
else
{
trh->rcf=htons((((sizeof(trh->rcf)) << 8) & TR_RCF_LEN_MASK)
| TR_RCF_FRAME2K | TR_RCF_LIMITED_BROADCAST);
trh->saddr[0]|=TR_RII;
#if TR_SR_DEBUG
printk("no entry in rif table found - broadcasting frame\n");
#endif
}
}
if (!(trh->saddr[0] & 0x80))
slack = 18;
else
slack = 18 - ((ntohs(trh->rcf) & TR_RCF_LEN_MASK)>>8);
olddata = skb->data;
spin_unlock_irqrestore(&rif_lock, flags);
skb_pull(skb, slack);
memmove(skb->data, olddata, sizeof(struct trh_hdr) - slack);
}
static void tr_add_rif_info(struct trh_hdr *trh, struct net_device *dev)
{
unsigned int hash, rii_p = 0;
unsigned long flags;
struct rif_cache *entry;
unsigned char saddr0;
spin_lock_irqsave(&rif_lock, flags);
saddr0 = trh->saddr[0];
if(trh->saddr[0] & TR_RII)
{
trh->saddr[0]&=0x7f;
if (((ntohs(trh->rcf) & TR_RCF_LEN_MASK) >> 8) > 2)
{
rii_p = 1;
}
}
hash = rif_hash(trh->saddr);
for(entry=rif_table[hash];entry && memcmp(&(entry->addr[0]),&(trh->saddr[0]),TR_ALEN);entry=entry->next);
if(entry==NULL)
{
#if TR_SR_DEBUG
printk("adding rif_entry: addr:%pM rcf:%04X\n",
trh->saddr, ntohs(trh->rcf));
#endif
entry=kmalloc(sizeof(struct rif_cache),GFP_ATOMIC);
if(!entry)
{
printk(KERN_DEBUG "tr.c: Couldn't malloc rif cache entry !\n");
spin_unlock_irqrestore(&rif_lock, flags);
return;
}
memcpy(&(entry->addr[0]),&(trh->saddr[0]),TR_ALEN);
entry->iface = dev->ifindex;
entry->next=rif_table[hash];
entry->last_used=jiffies;
rif_table[hash]=entry;
if (rii_p)
{
entry->rcf = trh->rcf & htons((unsigned short)~TR_RCF_BROADCAST_MASK);
memcpy(&(entry->rseg[0]),&(trh->rseg[0]),8*sizeof(unsigned short));
entry->local_ring = 0;
}
else
{
entry->local_ring = 1;
}
}
else
{
if (!entry->local_ring)
if (entry->rcf != (trh->rcf & htons((unsigned short)~TR_RCF_BROADCAST_MASK)) &&
!(trh->rcf & htons(TR_RCF_BROADCAST_MASK)))
{
#if TR_SR_DEBUG
printk("updating rif_entry: addr:%pM rcf:%04X\n",
trh->saddr, ntohs(trh->rcf));
#endif
entry->rcf = trh->rcf & htons((unsigned short)~TR_RCF_BROADCAST_MASK);
memcpy(&(entry->rseg[0]),&(trh->rseg[0]),8*sizeof(unsigned short));
}
entry->last_used=jiffies;
}
trh->saddr[0]=saddr0;
spin_unlock_irqrestore(&rif_lock, flags);
}
static void rif_check_expire(unsigned long dummy)
{
int i;
unsigned long flags, next_interval = jiffies + sysctl_tr_rif_timeout/2;
spin_lock_irqsave(&rif_lock, flags);
for(i =0; i < RIF_TABLE_SIZE; i++) {
struct rif_cache *entry, **pentry;
pentry = rif_table+i;
while((entry=*pentry) != NULL) {
unsigned long expires
= entry->last_used + sysctl_tr_rif_timeout;
if (time_before_eq(expires, jiffies)) {
*pentry = entry->next;
kfree(entry);
} else {
pentry = &entry->next;
if (time_before(expires, next_interval))
next_interval = expires;
}
}
}
spin_unlock_irqrestore(&rif_lock, flags);
mod_timer(&rif_timer, next_interval);
}
static struct rif_cache *rif_get_idx(loff_t pos)
{
int i;
struct rif_cache *entry;
loff_t off = 0;
for(i = 0; i < RIF_TABLE_SIZE; i++)
for(entry = rif_table[i]; entry; entry = entry->next) {
if (off == pos)
return entry;
++off;
}
return NULL;
}
static void *rif_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(&rif_lock
static void *rif_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
int i;
struct rif_cache *ent = v;
++*pos;
if (v == SEQ_START_TOKEN) {
i = -1;
goto scan;
}
if (ent->next)
return ent->next;
i = rif_hash(ent->addr);
scan:
while (++i < RIF_TABLE_SIZE) {
if ((ent = rif_table[i]) != NULL)
return ent;
}
return NULL;
}
static void rif_seq_stop(struct seq_file *seq, void *v)
__releases(&rif_lock
static int rif_seq_show(struct seq_file *seq, void *v)
{
int j, rcf_len, segment, brdgnmb;
struct rif_cache *entry = v;
if (v == SEQ_START_TOKEN)
seq_puts(seq,
"if TR address TTL rcf routing segments\n");
else {
struct net_device *dev = dev_get_by_index(&init_net, entry->iface);
long ttl = (long) (entry->last_used + sysctl_tr_rif_timeout)
- (long) jiffies;
seq_printf(seq, "%s %pM %7li ",
dev?dev->name:"?",
entry->addr,
ttl/HZ);
if (entry->local_ring)
seq_puts(seq, "local\n");
else {
seq_printf(seq, "%04X", ntohs(entry->rcf));
rcf_len = ((ntohs(entry->rcf) & TR_RCF_LEN_MASK)>>8)-2;
if (rcf_len)
rcf_len >>= 1;
for(j = 1; j < rcf_len; j++) {
if(j==1) {
segment=ntohs(entry->rseg[j-1])>>4;
seq_printf(seq," %03X",segment);
}
segment=ntohs(entry->rseg[j])>>4;
brdgnmb=ntohs(entry->rseg[j-1])&0x00f;
seq_printf(seq,"-%01X-%03X",brdgnmb,segment);
}
seq_putc(seq, '\n');
}
if (dev)
dev_put(dev);
}
return 0;
}
static int rif_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &rif_seq_ops);
}
static void tr_setup(struct net_device *dev)
{
dev->header_ops = &tr_header_ops;
dev->type = ARPHRD_IEEE802_TR;
dev->hard_header_len = TR_HLEN;
dev->mtu = 2000;
dev->addr_len = TR_ALEN;
dev->tx_queue_len = 100;
memset(dev->broadcast,0xFF, TR_ALEN);
dev->flags = IFF_BROADCAST | IFF_MULTICAST ;
}
struct net_device *alloc_trdev(int sizeof_priv)
{
return alloc_netdev(sizeof_priv, "tr%d", tr_setup);
}
static int __init rif_init(void)
{
rif_timer.expires = jiffies + sysctl_tr_rif_timeout;
setup_timer(&rif_timer, rif_check_expire, 0);
add_timer(&rif_timer);
#ifdef CONFIG_SYSCTL
register_sysctl_paths(tr_path, tr_table);
#endif
proc_net_fops_create(&init_net, "tr_rif", S_IRUGO, &rif_seq_fops);
return 0;
}
