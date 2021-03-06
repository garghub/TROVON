static bool __init ic_is_init_dev(struct net_device *dev)
{
if (dev->flags & IFF_LOOPBACK)
return false;
return user_dev_name[0] ? !strcmp(dev->name, user_dev_name) :
(!(dev->flags & IFF_LOOPBACK) &&
(dev->flags & (IFF_POINTOPOINT|IFF_BROADCAST)) &&
strncmp(dev->name, "dummy", 5));
}
static int __init ic_open_devs(void)
{
struct ic_device *d, **last;
struct net_device *dev;
unsigned short oflags;
unsigned long start;
last = &ic_first_dev;
rtnl_lock();
for_each_netdev(&init_net, dev) {
if (!(dev->flags & IFF_LOOPBACK))
continue;
if (dev_change_flags(dev, dev->flags | IFF_UP) < 0)
pr_err("IP-Config: Failed to open %s\n", dev->name);
}
for_each_netdev(&init_net, dev) {
if (ic_is_init_dev(dev)) {
int able = 0;
if (dev->mtu >= 364)
able |= IC_BOOTP;
else
pr_warn("DHCP/BOOTP: Ignoring device %s, MTU %d too small",
dev->name, dev->mtu);
if (!(dev->flags & IFF_NOARP))
able |= IC_RARP;
able &= ic_proto_enabled;
if (ic_proto_enabled && !able)
continue;
oflags = dev->flags;
if (dev_change_flags(dev, oflags | IFF_UP) < 0) {
pr_err("IP-Config: Failed to open %s\n",
dev->name);
continue;
}
if (!(d = kmalloc(sizeof(struct ic_device), GFP_KERNEL))) {
rtnl_unlock();
return -ENOMEM;
}
d->dev = dev;
*last = d;
last = &d->next;
d->flags = oflags;
d->able = able;
if (able & IC_BOOTP)
get_random_bytes(&d->xid, sizeof(__be32));
else
d->xid = 0;
ic_proto_have_if |= able;
DBG(("IP-Config: %s UP (able=%d, xid=%08x)\n",
dev->name, able, d->xid));
}
}
if (!ic_first_dev)
goto have_carrier;
start = jiffies;
while (jiffies - start < msecs_to_jiffies(CONF_CARRIER_TIMEOUT)) {
for_each_netdev(&init_net, dev)
if (ic_is_init_dev(dev) && netif_carrier_ok(dev))
goto have_carrier;
msleep(1);
}
have_carrier:
rtnl_unlock();
*last = NULL;
if (!ic_first_dev) {
if (user_dev_name[0])
pr_err("IP-Config: Device `%s' not found\n",
user_dev_name);
else
pr_err("IP-Config: No network devices available\n");
return -ENODEV;
}
return 0;
}
static void __init ic_close_devs(void)
{
struct ic_device *d, *next;
struct net_device *dev;
rtnl_lock();
next = ic_first_dev;
while ((d = next)) {
next = d->next;
dev = d->dev;
if (dev != ic_dev) {
DBG(("IP-Config: Downing %s\n", dev->name));
dev_change_flags(dev, d->flags);
}
kfree(d);
}
rtnl_unlock();
}
static inline void
set_sockaddr(struct sockaddr_in *sin, __be32 addr, __be16 port)
{
sin->sin_family = AF_INET;
sin->sin_addr.s_addr = addr;
sin->sin_port = port;
}
static int __init ic_devinet_ioctl(unsigned int cmd, struct ifreq *arg)
{
int res;
mm_segment_t oldfs = get_fs();
set_fs(get_ds());
res = devinet_ioctl(&init_net, cmd, (struct ifreq __user *) arg);
set_fs(oldfs);
return res;
}
static int __init ic_dev_ioctl(unsigned int cmd, struct ifreq *arg)
{
int res;
mm_segment_t oldfs = get_fs();
set_fs(get_ds());
res = dev_ioctl(&init_net, cmd, (struct ifreq __user *) arg);
set_fs(oldfs);
return res;
}
static int __init ic_route_ioctl(unsigned int cmd, struct rtentry *arg)
{
int res;
mm_segment_t oldfs = get_fs();
set_fs(get_ds());
res = ip_rt_ioctl(&init_net, cmd, (void __user *) arg);
set_fs(oldfs);
return res;
}
static int __init ic_setup_if(void)
{
struct ifreq ir;
struct sockaddr_in *sin = (void *) &ir.ifr_ifru.ifru_addr;
int err;
memset(&ir, 0, sizeof(ir));
strcpy(ir.ifr_ifrn.ifrn_name, ic_dev->name);
set_sockaddr(sin, ic_myaddr, 0);
if ((err = ic_devinet_ioctl(SIOCSIFADDR, &ir)) < 0) {
pr_err("IP-Config: Unable to set interface address (%d)\n",
err);
return -1;
}
set_sockaddr(sin, ic_netmask, 0);
if ((err = ic_devinet_ioctl(SIOCSIFNETMASK, &ir)) < 0) {
pr_err("IP-Config: Unable to set interface netmask (%d)\n",
err);
return -1;
}
set_sockaddr(sin, ic_myaddr | ~ic_netmask, 0);
if ((err = ic_devinet_ioctl(SIOCSIFBRDADDR, &ir)) < 0) {
pr_err("IP-Config: Unable to set interface broadcast address (%d)\n",
err);
return -1;
}
if (ic_dev_mtu != 0) {
strcpy(ir.ifr_name, ic_dev->name);
ir.ifr_mtu = ic_dev_mtu;
if ((err = ic_dev_ioctl(SIOCSIFMTU, &ir)) < 0)
pr_err("IP-Config: Unable to set interface mtu to %d (%d)\n",
ic_dev_mtu, err);
}
return 0;
}
static int __init ic_setup_routes(void)
{
if (ic_gateway != NONE) {
struct rtentry rm;
int err;
memset(&rm, 0, sizeof(rm));
if ((ic_gateway ^ ic_myaddr) & ic_netmask) {
pr_err("IP-Config: Gateway not on directly connected network\n");
return -1;
}
set_sockaddr((struct sockaddr_in *) &rm.rt_dst, 0, 0);
set_sockaddr((struct sockaddr_in *) &rm.rt_genmask, 0, 0);
set_sockaddr((struct sockaddr_in *) &rm.rt_gateway, ic_gateway, 0);
rm.rt_flags = RTF_UP | RTF_GATEWAY;
if ((err = ic_route_ioctl(SIOCADDRT, &rm)) < 0) {
pr_err("IP-Config: Cannot add default route (%d)\n",
err);
return -1;
}
}
return 0;
}
static int __init ic_defaults(void)
{
if (!ic_host_name_set)
sprintf(init_utsname()->nodename, "%pI4", &ic_myaddr);
if (root_server_addr == NONE)
root_server_addr = ic_servaddr;
if (ic_netmask == NONE) {
if (IN_CLASSA(ntohl(ic_myaddr)))
ic_netmask = htonl(IN_CLASSA_NET);
else if (IN_CLASSB(ntohl(ic_myaddr)))
ic_netmask = htonl(IN_CLASSB_NET);
else if (IN_CLASSC(ntohl(ic_myaddr)))
ic_netmask = htonl(IN_CLASSC_NET);
else {
pr_err("IP-Config: Unable to guess netmask for address %pI4\n",
&ic_myaddr);
return -1;
}
printk("IP-Config: Guessing netmask %pI4\n", &ic_netmask);
}
return 0;
}
static inline void __init ic_rarp_init(void)
{
dev_add_pack(&rarp_packet_type);
}
static inline void __init ic_rarp_cleanup(void)
{
dev_remove_pack(&rarp_packet_type);
}
static int __init
ic_rarp_recv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev)
{
struct arphdr *rarp;
unsigned char *rarp_ptr;
__be32 sip, tip;
unsigned char *sha, *tha;
struct ic_device *d;
if (!net_eq(dev_net(dev), &init_net))
goto drop;
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL)
return NET_RX_DROP;
if (!pskb_may_pull(skb, sizeof(struct arphdr)))
goto drop;
rarp = (struct arphdr *)skb_transport_header(skb);
if (rarp->ar_hln != dev->addr_len || dev->type != ntohs(rarp->ar_hrd))
goto drop;
if (rarp->ar_op != htons(ARPOP_RREPLY))
goto drop;
if (rarp->ar_pro != htons(ETH_P_IP))
goto drop;
if (!pskb_may_pull(skb, arp_hdr_len(dev)))
goto drop;
rarp = (struct arphdr *)skb_transport_header(skb);
rarp_ptr = (unsigned char *) (rarp + 1);
spin_lock(&ic_recv_lock);
if (ic_got_reply)
goto drop_unlock;
d = ic_first_dev;
while (d && d->dev != dev)
d = d->next;
if (!d)
goto drop_unlock;
sha = rarp_ptr;
rarp_ptr += dev->addr_len;
memcpy(&sip, rarp_ptr, 4);
rarp_ptr += 4;
tha = rarp_ptr;
rarp_ptr += dev->addr_len;
memcpy(&tip, rarp_ptr, 4);
if (memcmp(tha, dev->dev_addr, dev->addr_len))
goto drop_unlock;
if (ic_servaddr != NONE && ic_servaddr != sip)
goto drop_unlock;
ic_dev = dev;
if (ic_myaddr == NONE)
ic_myaddr = tip;
ic_servaddr = sip;
ic_got_reply = IC_RARP;
drop_unlock:
spin_unlock(&ic_recv_lock);
drop:
kfree_skb(skb);
return 0;
}
static void __init ic_rarp_send_if(struct ic_device *d)
{
struct net_device *dev = d->dev;
arp_send(ARPOP_RREQUEST, ETH_P_RARP, 0, dev, 0, NULL,
dev->dev_addr, dev->dev_addr);
}
static void __init
ic_dhcp_init_options(u8 *options)
{
u8 mt = ((ic_servaddr == NONE)
? DHCPDISCOVER : DHCPREQUEST);
u8 *e = options;
int len;
#ifdef IPCONFIG_DEBUG
printk("DHCP: Sending message type %d\n", mt);
#endif
memcpy(e, ic_bootp_cookie, 4);
e += 4;
*e++ = 53;
*e++ = 1;
*e++ = mt;
if (mt == DHCPREQUEST) {
*e++ = 54;
*e++ = 4;
memcpy(e, &ic_servaddr, 4);
e += 4;
*e++ = 50;
*e++ = 4;
memcpy(e, &ic_myaddr, 4);
e += 4;
}
{
static const u8 ic_req_params[] = {
1,
3,
6,
12,
15,
17,
26,
40,
};
*e++ = 55;
*e++ = sizeof(ic_req_params);
memcpy(e, ic_req_params, sizeof(ic_req_params));
e += sizeof(ic_req_params);
if (ic_host_name_set) {
*e++ = 12;
len = strlen(utsname()->nodename);
*e++ = len;
memcpy(e, utsname()->nodename, len);
e += len;
}
if (*vendor_class_identifier) {
pr_info("DHCP: sending class identifier \"%s\"\n",
vendor_class_identifier);
*e++ = 60;
len = strlen(vendor_class_identifier);
*e++ = len;
memcpy(e, vendor_class_identifier, len);
e += len;
}
}
*e++ = 255;
}
static void __init ic_bootp_init_ext(u8 *e)
{
memcpy(e, ic_bootp_cookie, 4);
e += 4;
*e++ = 1;
*e++ = 4;
e += 4;
*e++ = 3;
*e++ = 4;
e += 4;
*e++ = 5;
*e++ = 8;
e += 8;
*e++ = 12;
*e++ = 32;
e += 32;
*e++ = 40;
*e++ = 32;
e += 32;
*e++ = 17;
*e++ = 40;
e += 40;
*e++ = 57;
*e++ = 2;
*e++ = 1;
*e++ = 150;
*e++ = 255;
}
static inline void __init ic_bootp_init(void)
{
int i;
for (i = 0; i < CONF_NAMESERVERS_MAX; i++)
ic_nameservers[i] = NONE;
dev_add_pack(&bootp_packet_type);
}
static inline void __init ic_bootp_cleanup(void)
{
dev_remove_pack(&bootp_packet_type);
}
static void __init ic_bootp_send_if(struct ic_device *d, unsigned long jiffies_diff)
{
struct net_device *dev = d->dev;
struct sk_buff *skb;
struct bootp_pkt *b;
struct iphdr *h;
int hlen = LL_RESERVED_SPACE(dev);
int tlen = dev->needed_tailroom;
skb = alloc_skb(sizeof(struct bootp_pkt) + hlen + tlen + 15,
GFP_KERNEL);
if (!skb)
return;
skb_reserve(skb, hlen);
b = (struct bootp_pkt *) skb_put(skb, sizeof(struct bootp_pkt));
memset(b, 0, sizeof(struct bootp_pkt));
skb_reset_network_header(skb);
h = ip_hdr(skb);
h->version = 4;
h->ihl = 5;
h->tot_len = htons(sizeof(struct bootp_pkt));
h->frag_off = htons(IP_DF);
h->ttl = 64;
h->protocol = IPPROTO_UDP;
h->daddr = htonl(INADDR_BROADCAST);
h->check = ip_fast_csum((unsigned char *) h, h->ihl);
b->udph.source = htons(68);
b->udph.dest = htons(67);
b->udph.len = htons(sizeof(struct bootp_pkt) - sizeof(struct iphdr));
b->op = BOOTP_REQUEST;
if (dev->type < 256)
b->htype = dev->type;
else if (dev->type == ARPHRD_FDDI)
b->htype = ARPHRD_ETHER;
else {
printk("Unknown ARP type 0x%04x for device %s\n", dev->type, dev->name);
b->htype = dev->type;
}
b->hlen = dev->addr_len;
memcpy(b->hw_addr, dev->dev_addr, dev->addr_len);
b->secs = htons(jiffies_diff / HZ);
b->xid = d->xid;
#ifdef IPCONFIG_DHCP
if (ic_proto_enabled & IC_USE_DHCP)
ic_dhcp_init_options(b->exten);
else
#endif
ic_bootp_init_ext(b->exten);
skb->dev = dev;
skb->protocol = htons(ETH_P_IP);
if (dev_hard_header(skb, dev, ntohs(skb->protocol),
dev->broadcast, dev->dev_addr, skb->len) < 0) {
kfree_skb(skb);
printk("E");
return;
}
if (dev_queue_xmit(skb) < 0)
printk("E");
}
static int __init ic_bootp_string(char *dest, char *src, int len, int max)
{
if (!len)
return 0;
if (len > max-1)
len = max-1;
memcpy(dest, src, len);
dest[len] = '\0';
return 1;
}
static void __init ic_do_bootp_ext(u8 *ext)
{
u8 servers;
int i;
__be16 mtu;
#ifdef IPCONFIG_DEBUG
u8 *c;
printk("DHCP/BOOTP: Got extension %d:",*ext);
for (c=ext+2; c<ext+2+ext[1]; c++)
printk(" %02x", *c);
printk("\n");
#endif
switch (*ext++) {
case 1:
if (ic_netmask == NONE)
memcpy(&ic_netmask, ext+1, 4);
break;
case 3:
if (ic_gateway == NONE)
memcpy(&ic_gateway, ext+1, 4);
break;
case 6:
servers= *ext/4;
if (servers > CONF_NAMESERVERS_MAX)
servers = CONF_NAMESERVERS_MAX;
for (i = 0; i < servers; i++) {
if (ic_nameservers[i] == NONE)
memcpy(&ic_nameservers[i], ext+1+4*i, 4);
}
break;
case 12:
ic_bootp_string(utsname()->nodename, ext+1, *ext,
__NEW_UTS_LEN);
ic_host_name_set = 1;
break;
case 15:
ic_bootp_string(ic_domain, ext+1, *ext, sizeof(ic_domain));
break;
case 17:
if (!root_server_path[0])
ic_bootp_string(root_server_path, ext+1, *ext,
sizeof(root_server_path));
break;
case 26:
memcpy(&mtu, ext+1, sizeof(mtu));
ic_dev_mtu = ntohs(mtu);
break;
case 40:
ic_bootp_string(utsname()->domainname, ext+1, *ext,
__NEW_UTS_LEN);
break;
}
}
static int __init ic_bootp_recv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev)
{
struct bootp_pkt *b;
struct iphdr *h;
struct ic_device *d;
int len, ext_len;
if (!net_eq(dev_net(dev), &init_net))
goto drop;
if (skb->pkt_type == PACKET_OTHERHOST)
goto drop;
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL)
return NET_RX_DROP;
if (!pskb_may_pull(skb,
sizeof(struct iphdr) +
sizeof(struct udphdr)))
goto drop;
b = (struct bootp_pkt *)skb_network_header(skb);
h = &b->iph;
if (h->ihl != 5 || h->version != 4 || h->protocol != IPPROTO_UDP)
goto drop;
if (ip_is_fragment(h)) {
net_err_ratelimited("DHCP/BOOTP: Ignoring fragmented reply\n");
goto drop;
}
if (skb->len < ntohs(h->tot_len))
goto drop;
if (ip_fast_csum((char *) h, h->ihl))
goto drop;
if (b->udph.source != htons(67) || b->udph.dest != htons(68))
goto drop;
if (ntohs(h->tot_len) < ntohs(b->udph.len) + sizeof(struct iphdr))
goto drop;
len = ntohs(b->udph.len) - sizeof(struct udphdr);
ext_len = len - (sizeof(*b) -
sizeof(struct iphdr) -
sizeof(struct udphdr) -
sizeof(b->exten));
if (ext_len < 0)
goto drop;
if (!pskb_may_pull(skb, skb->len))
goto drop;
b = (struct bootp_pkt *)skb_network_header(skb);
h = &b->iph;
spin_lock(&ic_recv_lock);
if (ic_got_reply)
goto drop_unlock;
d = ic_first_dev;
while (d && d->dev != dev)
d = d->next;
if (!d)
goto drop_unlock;
if (b->op != BOOTP_REPLY ||
b->xid != d->xid) {
net_err_ratelimited("DHCP/BOOTP: Reply not for us, op[%x] xid[%x]\n",
b->op, b->xid);
goto drop_unlock;
}
if (b->xid != ic_dev_xid) {
net_err_ratelimited("DHCP/BOOTP: Ignoring delayed packet\n");
goto drop_unlock;
}
if (ext_len >= 4 &&
!memcmp(b->exten, ic_bootp_cookie, 4)) {
u8 *end = (u8 *) b + ntohs(b->iph.tot_len);
u8 *ext;
#ifdef IPCONFIG_DHCP
if (ic_proto_enabled & IC_USE_DHCP) {
__be32 server_id = NONE;
int mt = 0;
ext = &b->exten[4];
while (ext < end && *ext != 0xff) {
u8 *opt = ext++;
if (*opt == 0)
continue;
ext += *ext + 1;
if (ext >= end)
break;
switch (*opt) {
case 53:
if (opt[1])
mt = opt[2];
break;
case 54:
if (opt[1] >= 4)
memcpy(&server_id, opt + 2, 4);
break;
}
}
#ifdef IPCONFIG_DEBUG
printk("DHCP: Got message type %d\n", mt);
#endif
switch (mt) {
case DHCPOFFER:
if (ic_myaddr != NONE)
goto drop_unlock;
ic_myaddr = b->your_ip;
ic_servaddr = server_id;
#ifdef IPCONFIG_DEBUG
printk("DHCP: Offered address %pI4 by server %pI4\n",
&ic_myaddr, &ic_servaddr);
#endif
if ((server_id != NONE) &&
(b->server_ip != server_id))
b->server_ip = ic_servaddr;
break;
case DHCPACK:
if (memcmp(dev->dev_addr, b->hw_addr, dev->addr_len) != 0)
goto drop_unlock;
break;
default:
ic_myaddr = NONE;
ic_servaddr = NONE;
goto drop_unlock;
}
ic_dhcp_msgtype = mt;
}
#endif
ext = &b->exten[4];
while (ext < end && *ext != 0xff) {
u8 *opt = ext++;
if (*opt == 0)
continue;
ext += *ext + 1;
if (ext < end)
ic_do_bootp_ext(opt);
}
}
ic_dev = dev;
ic_myaddr = b->your_ip;
ic_servaddr = b->server_ip;
if (ic_gateway == NONE && b->relay_ip)
ic_gateway = b->relay_ip;
if (ic_nameservers[0] == NONE)
ic_nameservers[0] = ic_servaddr;
ic_got_reply = IC_BOOTP;
drop_unlock:
spin_unlock(&ic_recv_lock);
drop:
kfree_skb(skb);
return 0;
}
static int __init ic_dynamic(void)
{
int retries;
struct ic_device *d;
unsigned long start_jiffies, timeout, jiff;
int do_bootp = ic_proto_have_if & IC_BOOTP;
int do_rarp = ic_proto_have_if & IC_RARP;
if (!ic_proto_enabled) {
pr_err("IP-Config: Incomplete network configuration information\n");
return -1;
}
#ifdef IPCONFIG_BOOTP
if ((ic_proto_enabled ^ ic_proto_have_if) & IC_BOOTP)
pr_err("DHCP/BOOTP: No suitable device found\n");
#endif
#ifdef IPCONFIG_RARP
if ((ic_proto_enabled ^ ic_proto_have_if) & IC_RARP)
pr_err("RARP: No suitable device found\n");
#endif
if (!ic_proto_have_if)
return -1;
#ifdef IPCONFIG_BOOTP
if (do_bootp)
ic_bootp_init();
#endif
#ifdef IPCONFIG_RARP
if (do_rarp)
ic_rarp_init();
#endif
pr_notice("Sending %s%s%s requests .",
do_bootp
? ((ic_proto_enabled & IC_USE_DHCP) ? "DHCP" : "BOOTP") : "",
(do_bootp && do_rarp) ? " and " : "",
do_rarp ? "RARP" : "");
start_jiffies = jiffies;
d = ic_first_dev;
retries = CONF_SEND_RETRIES;
get_random_bytes(&timeout, sizeof(timeout));
timeout = CONF_BASE_TIMEOUT + (timeout % (unsigned int) CONF_TIMEOUT_RANDOM);
for (;;) {
ic_dev_xid = d->xid;
#ifdef IPCONFIG_BOOTP
if (do_bootp && (d->able & IC_BOOTP))
ic_bootp_send_if(d, jiffies - start_jiffies);
#endif
#ifdef IPCONFIG_RARP
if (do_rarp && (d->able & IC_RARP))
ic_rarp_send_if(d);
#endif
jiff = jiffies + (d->next ? CONF_INTER_TIMEOUT : timeout);
while (time_before(jiffies, jiff) && !ic_got_reply)
schedule_timeout_uninterruptible(1);
#ifdef IPCONFIG_DHCP
if ((ic_got_reply & IC_BOOTP) &&
(ic_proto_enabled & IC_USE_DHCP) &&
ic_dhcp_msgtype != DHCPACK) {
ic_got_reply = 0;
pr_cont(",");
continue;
}
#endif
if (ic_got_reply) {
pr_cont(" OK\n");
break;
}
if ((d = d->next))
continue;
if (! --retries) {
pr_cont(" timed out!\n");
break;
}
d = ic_first_dev;
timeout = timeout CONF_TIMEOUT_MULT;
if (timeout > CONF_TIMEOUT_MAX)
timeout = CONF_TIMEOUT_MAX;
pr_cont(".");
}
#ifdef IPCONFIG_BOOTP
if (do_bootp)
ic_bootp_cleanup();
#endif
#ifdef IPCONFIG_RARP
if (do_rarp)
ic_rarp_cleanup();
#endif
if (!ic_got_reply) {
ic_myaddr = NONE;
return -1;
}
printk("IP-Config: Got %s answer from %pI4, ",
((ic_got_reply & IC_RARP) ? "RARP"
: (ic_proto_enabled & IC_USE_DHCP) ? "DHCP" : "BOOTP"),
&ic_servaddr);
pr_cont("my address is %pI4\n", &ic_myaddr);
return 0;
}
static int pnp_seq_show(struct seq_file *seq, void *v)
{
int i;
if (ic_proto_used & IC_PROTO)
seq_printf(seq, "#PROTO: %s\n",
(ic_proto_used & IC_RARP) ? "RARP"
: (ic_proto_used & IC_USE_DHCP) ? "DHCP" : "BOOTP");
else
seq_puts(seq, "#MANUAL\n");
if (ic_domain[0])
seq_printf(seq,
"domain %s\n", ic_domain);
for (i = 0; i < CONF_NAMESERVERS_MAX; i++) {
if (ic_nameservers[i] != NONE)
seq_printf(seq, "nameserver %pI4\n",
&ic_nameservers[i]);
}
if (ic_servaddr != NONE)
seq_printf(seq, "bootserver %pI4\n",
&ic_servaddr);
return 0;
}
static int pnp_seq_open(struct inode *indoe, struct file *file)
{
return single_open(file, pnp_seq_show, NULL);
}
__be32 __init root_nfs_parse_addr(char *name)
{
__be32 addr;
int octets = 0;
char *cp, *cq;
cp = cq = name;
while (octets < 4) {
while (*cp >= '0' && *cp <= '9')
cp++;
if (cp == cq || cp - cq > 3)
break;
if (*cp == '.' || octets == 3)
octets++;
if (octets < 4)
cp++;
cq = cp;
}
if (octets == 4 && (*cp == ':' || *cp == '\0')) {
if (*cp == ':')
*cp++ = '\0';
addr = in_aton(name);
memmove(name, cp, strlen(cp) + 1);
} else
addr = NONE;
return addr;
}
static int __init wait_for_devices(void)
{
int i;
for (i = 0; i < DEVICE_WAIT_MAX; i++) {
struct net_device *dev;
int found = 0;
rtnl_lock();
for_each_netdev(&init_net, dev) {
if (ic_is_init_dev(dev)) {
found = 1;
break;
}
}
rtnl_unlock();
if (found)
return 0;
ssleep(1);
}
return -ENODEV;
}
static int __init ip_auto_config(void)
{
__be32 addr;
#ifdef IPCONFIG_DYNAMIC
int retries = CONF_OPEN_RETRIES;
#endif
int err;
#ifdef CONFIG_PROC_FS
proc_net_fops_create(&init_net, "pnp", S_IRUGO, &pnp_seq_fops);
#endif
if (!ic_enable)
return 0;
DBG(("IP-Config: Entered.\n"));
#ifdef IPCONFIG_DYNAMIC
try_try_again:
#endif
err = wait_for_devices();
if (err)
return err;
err = ic_open_devs();
if (err)
return err;
msleep(CONF_POST_OPEN);
if (ic_myaddr == NONE ||
#ifdef CONFIG_ROOT_NFS
(root_server_addr == NONE &&
ic_servaddr == NONE &&
ROOT_DEV == Root_NFS) ||
#endif
ic_first_dev->next) {
#ifdef IPCONFIG_DYNAMIC
if (ic_dynamic() < 0) {
ic_close_devs();
#ifdef CONFIG_ROOT_NFS
if (ROOT_DEV == Root_NFS) {
pr_err("IP-Config: Retrying forever (NFS root)...\n");
goto try_try_again;
}
#endif
if (--retries) {
pr_err("IP-Config: Reopening network devices...\n");
goto try_try_again;
}
pr_err("IP-Config: Auto-configuration of network failed\n");
return -1;
}
#else
pr_err("IP-Config: Incomplete network configuration information\n");
ic_close_devs();
return -1;
#endif
} else {
ic_dev = ic_first_dev->dev;
}
addr = root_nfs_parse_addr(root_server_path);
if (root_server_addr == NONE)
root_server_addr = addr;
if (ic_defaults() < 0)
return -1;
ic_close_devs();
if (ic_setup_if() < 0 || ic_setup_routes() < 0)
return -1;
#ifdef IPCONFIG_DYNAMIC
ic_proto_used = ic_got_reply | (ic_proto_enabled & IC_USE_DHCP);
#endif
#ifndef IPCONFIG_SILENT
pr_info("IP-Config: Complete:\n");
pr_info(" device=%s, addr=%pI4, mask=%pI4, gw=%pI4\n",
ic_dev->name, &ic_myaddr, &ic_netmask, &ic_gateway);
pr_info(" host=%s, domain=%s, nis-domain=%s\n",
utsname()->nodename, ic_domain, utsname()->domainname);
pr_info(" bootserver=%pI4, rootserver=%pI4, rootpath=%s",
&ic_servaddr, &root_server_addr, root_server_path);
if (ic_dev_mtu)
pr_cont(", mtu=%d", ic_dev_mtu);
pr_cont("\n");
#endif
return 0;
}
static int __init ic_proto_name(char *name)
{
if (!strcmp(name, "on") || !strcmp(name, "any")) {
return 1;
}
if (!strcmp(name, "off") || !strcmp(name, "none")) {
return 0;
}
#ifdef CONFIG_IP_PNP_DHCP
else if (!strcmp(name, "dhcp")) {
ic_proto_enabled &= ~IC_RARP;
return 1;
}
#endif
#ifdef CONFIG_IP_PNP_BOOTP
else if (!strcmp(name, "bootp")) {
ic_proto_enabled &= ~(IC_RARP | IC_USE_DHCP);
return 1;
}
#endif
#ifdef CONFIG_IP_PNP_RARP
else if (!strcmp(name, "rarp")) {
ic_proto_enabled &= ~(IC_BOOTP | IC_USE_DHCP);
return 1;
}
#endif
#ifdef IPCONFIG_DYNAMIC
else if (!strcmp(name, "both")) {
ic_proto_enabled &= ~IC_USE_DHCP;
return 1;
}
#endif
return 0;
}
static int __init ip_auto_config_setup(char *addrs)
{
char *cp, *ip, *dp;
int num = 0;
ic_set_manually = 1;
ic_enable = 1;
if (ic_proto_name(addrs))
return 1;
if (*addrs == 0 ||
strcmp(addrs, "off") == 0 ||
strcmp(addrs, "none") == 0) {
ic_enable = 0;
return 1;
}
ip = addrs;
while (ip && *ip) {
if ((cp = strchr(ip, ':')))
*cp++ = '\0';
if (strlen(ip) > 0) {
DBG(("IP-Config: Parameter #%d: `%s'\n", num, ip));
switch (num) {
case 0:
if ((ic_myaddr = in_aton(ip)) == ANY)
ic_myaddr = NONE;
break;
case 1:
if ((ic_servaddr = in_aton(ip)) == ANY)
ic_servaddr = NONE;
break;
case 2:
if ((ic_gateway = in_aton(ip)) == ANY)
ic_gateway = NONE;
break;
case 3:
if ((ic_netmask = in_aton(ip)) == ANY)
ic_netmask = NONE;
break;
case 4:
if ((dp = strchr(ip, '.'))) {
*dp++ = '\0';
strlcpy(utsname()->domainname, dp,
sizeof(utsname()->domainname));
}
strlcpy(utsname()->nodename, ip,
sizeof(utsname()->nodename));
ic_host_name_set = 1;
break;
case 5:
strlcpy(user_dev_name, ip, sizeof(user_dev_name));
break;
case 6:
if (ic_proto_name(ip) == 0 &&
ic_myaddr == NONE) {
ic_enable = 0;
}
break;
}
}
ip = cp;
num++;
}
return 1;
}
static int __init nfsaddrs_config_setup(char *addrs)
{
return ip_auto_config_setup(addrs);
}
static int __init vendor_class_identifier_setup(char *addrs)
{
if (strlcpy(vendor_class_identifier, addrs,
sizeof(vendor_class_identifier))
>= sizeof(vendor_class_identifier))
pr_warn("DHCP: vendorclass too long, truncated to \"%s\"",
vendor_class_identifier);
return 1;
}
