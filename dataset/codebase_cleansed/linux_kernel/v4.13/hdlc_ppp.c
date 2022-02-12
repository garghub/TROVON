static inline struct ppp* get_ppp(struct net_device *dev)
{
return (struct ppp *)dev_to_hdlc(dev)->state;
}
static inline struct proto* get_proto(struct net_device *dev, u16 pid)
{
struct ppp *ppp = get_ppp(dev);
switch (pid) {
case PID_LCP:
return &ppp->protos[IDX_LCP];
case PID_IPCP:
return &ppp->protos[IDX_IPCP];
case PID_IPV6CP:
return &ppp->protos[IDX_IPV6CP];
default:
return NULL;
}
}
static inline const char* proto_name(u16 pid)
{
switch (pid) {
case PID_LCP:
return "LCP";
case PID_IPCP:
return "IPCP";
case PID_IPV6CP:
return "IPV6CP";
default:
return NULL;
}
}
static __be16 ppp_type_trans(struct sk_buff *skb, struct net_device *dev)
{
struct hdlc_header *data = (struct hdlc_header*)skb->data;
if (skb->len < sizeof(struct hdlc_header))
return htons(ETH_P_HDLC);
if (data->address != HDLC_ADDR_ALLSTATIONS ||
data->control != HDLC_CTRL_UI)
return htons(ETH_P_HDLC);
switch (data->protocol) {
case cpu_to_be16(PID_IP):
skb_pull(skb, sizeof(struct hdlc_header));
return htons(ETH_P_IP);
case cpu_to_be16(PID_IPV6):
skb_pull(skb, sizeof(struct hdlc_header));
return htons(ETH_P_IPV6);
default:
return htons(ETH_P_HDLC);
}
}
static int ppp_hard_header(struct sk_buff *skb, struct net_device *dev,
u16 type, const void *daddr, const void *saddr,
unsigned int len)
{
struct hdlc_header *data;
#if DEBUG_HARD_HEADER
printk(KERN_DEBUG "%s: ppp_hard_header() called\n", dev->name);
#endif
skb_push(skb, sizeof(struct hdlc_header));
data = (struct hdlc_header*)skb->data;
data->address = HDLC_ADDR_ALLSTATIONS;
data->control = HDLC_CTRL_UI;
switch (type) {
case ETH_P_IP:
data->protocol = htons(PID_IP);
break;
case ETH_P_IPV6:
data->protocol = htons(PID_IPV6);
break;
case PID_LCP:
case PID_IPCP:
case PID_IPV6CP:
data->protocol = htons(type);
break;
default:
data->protocol = 0;
}
return sizeof(struct hdlc_header);
}
static void ppp_tx_flush(void)
{
struct sk_buff *skb;
while ((skb = skb_dequeue(&tx_queue)) != NULL)
dev_queue_xmit(skb);
}
static void ppp_tx_cp(struct net_device *dev, u16 pid, u8 code,
u8 id, unsigned int len, const void *data)
{
struct sk_buff *skb;
struct cp_header *cp;
unsigned int magic_len = 0;
static u32 magic;
#if DEBUG_CP
int i;
char *ptr;
#endif
if (pid == PID_LCP && (code == LCP_ECHO_REQ || code == LCP_ECHO_REPLY))
magic_len = sizeof(magic);
skb = dev_alloc_skb(sizeof(struct hdlc_header) +
sizeof(struct cp_header) + magic_len + len);
if (!skb) {
netdev_warn(dev, "out of memory in ppp_tx_cp()\n");
return;
}
skb_reserve(skb, sizeof(struct hdlc_header));
cp = skb_put(skb, sizeof(struct cp_header));
cp->code = code;
cp->id = id;
cp->len = htons(sizeof(struct cp_header) + magic_len + len);
if (magic_len)
skb_put_data(skb, &magic, magic_len);
if (len)
skb_put_data(skb, data, len);
#if DEBUG_CP
BUG_ON(code >= CP_CODES);
ptr = debug_buffer;
*ptr = '\x0';
for (i = 0; i < min_t(unsigned int, magic_len + len, DEBUG_CP); i++) {
sprintf(ptr, " %02X", skb->data[sizeof(struct cp_header) + i]);
ptr += strlen(ptr);
}
printk(KERN_DEBUG "%s: TX %s [%s id 0x%X]%s\n", dev->name,
proto_name(pid), code_names[code], id, debug_buffer);
#endif
ppp_hard_header(skb, dev, pid, NULL, NULL, 0);
skb->priority = TC_PRIO_CONTROL;
skb->dev = dev;
skb_reset_network_header(skb);
skb_queue_tail(&tx_queue, skb);
}
static void ppp_cp_event(struct net_device *dev, u16 pid, u16 event, u8 code,
u8 id, unsigned int len, const void *data)
{
int old_state, action;
struct ppp *ppp = get_ppp(dev);
struct proto *proto = get_proto(dev, pid);
old_state = proto->state;
BUG_ON(old_state >= STATES);
BUG_ON(event >= EVENTS);
#if DEBUG_STATE
printk(KERN_DEBUG "%s: %s ppp_cp_event(%s) %s ...\n", dev->name,
proto_name(pid), event_names[event], state_names[proto->state]);
#endif
action = cp_table[event][old_state];
proto->state = action & STATE_MASK;
if (action & (SCR | STR))
mod_timer(&proto->timer, proto->timeout =
jiffies + ppp->req_timeout * HZ);
if (action & ZRC)
proto->restart_counter = 0;
if (action & IRC)
proto->restart_counter = (proto->state == STOPPING) ?
ppp->term_retries : ppp->cr_retries;
if (action & SCR)
ppp_tx_cp(dev, pid, CP_CONF_REQ, proto->cr_id = ++ppp->seq,
0, NULL);
if (action & SCA)
ppp_tx_cp(dev, pid, CP_CONF_ACK, id, len, data);
if (action & SCN)
ppp_tx_cp(dev, pid, code, id, len, data);
if (action & STR)
ppp_tx_cp(dev, pid, CP_TERM_REQ, ++ppp->seq, 0, NULL);
if (action & STA)
ppp_tx_cp(dev, pid, CP_TERM_ACK, id, 0, NULL);
if (action & SCJ)
ppp_tx_cp(dev, pid, CP_CODE_REJ, ++ppp->seq, len, data);
if (old_state != OPENED && proto->state == OPENED) {
netdev_info(dev, "%s up\n", proto_name(pid));
if (pid == PID_LCP) {
netif_dormant_off(dev);
ppp_cp_event(dev, PID_IPCP, START, 0, 0, 0, NULL);
ppp_cp_event(dev, PID_IPV6CP, START, 0, 0, 0, NULL);
ppp->last_pong = jiffies;
mod_timer(&proto->timer, proto->timeout =
jiffies + ppp->keepalive_interval * HZ);
}
}
if (old_state == OPENED && proto->state != OPENED) {
netdev_info(dev, "%s down\n", proto_name(pid));
if (pid == PID_LCP) {
netif_dormant_on(dev);
ppp_cp_event(dev, PID_IPCP, STOP, 0, 0, 0, NULL);
ppp_cp_event(dev, PID_IPV6CP, STOP, 0, 0, 0, NULL);
}
}
if (old_state != CLOSED && proto->state == CLOSED)
del_timer(&proto->timer);
#if DEBUG_STATE
printk(KERN_DEBUG "%s: %s ppp_cp_event(%s) ... %s\n", dev->name,
proto_name(pid), event_names[event], state_names[proto->state]);
#endif
}
static void ppp_cp_parse_cr(struct net_device *dev, u16 pid, u8 id,
unsigned int req_len, const u8 *data)
{
static u8 const valid_accm[6] = { LCP_OPTION_ACCM, 6, 0, 0, 0, 0 };
const u8 *opt;
u8 *out;
unsigned int len = req_len, nak_len = 0, rej_len = 0;
if (!(out = kmalloc(len, GFP_ATOMIC))) {
dev->stats.rx_dropped++;
return;
}
for (opt = data; len; len -= opt[1], opt += opt[1]) {
if (len < 2 || len < opt[1]) {
dev->stats.rx_errors++;
kfree(out);
return;
}
if (pid == PID_LCP)
switch (opt[0]) {
case LCP_OPTION_MRU:
continue;
case LCP_OPTION_ACCM:
if (!memcmp(opt, valid_accm,
sizeof(valid_accm)))
continue;
if (!rej_len) {
memcpy(out + nak_len, valid_accm,
sizeof(valid_accm));
nak_len += sizeof(valid_accm);
continue;
}
break;
case LCP_OPTION_MAGIC:
if (opt[1] != 6 || (!opt[2] && !opt[3] &&
!opt[4] && !opt[5]))
break;
continue;
}
memcpy(out + rej_len, opt, opt[1]);
rej_len += opt[1];
}
if (rej_len)
ppp_cp_event(dev, pid, RCR_BAD, CP_CONF_REJ, id, rej_len, out);
else if (nak_len)
ppp_cp_event(dev, pid, RCR_BAD, CP_CONF_NAK, id, nak_len, out);
else
ppp_cp_event(dev, pid, RCR_GOOD, CP_CONF_ACK, id, req_len, data);
kfree(out);
}
static int ppp_rx(struct sk_buff *skb)
{
struct hdlc_header *hdr = (struct hdlc_header*)skb->data;
struct net_device *dev = skb->dev;
struct ppp *ppp = get_ppp(dev);
struct proto *proto;
struct cp_header *cp;
unsigned long flags;
unsigned int len;
u16 pid;
#if DEBUG_CP
int i;
char *ptr;
#endif
spin_lock_irqsave(&ppp->lock, flags);
if (skb->len < sizeof(struct hdlc_header))
goto rx_error;
cp = skb_pull(skb, sizeof(struct hdlc_header));
if (hdr->address != HDLC_ADDR_ALLSTATIONS ||
hdr->control != HDLC_CTRL_UI)
goto rx_error;
pid = ntohs(hdr->protocol);
proto = get_proto(dev, pid);
if (!proto) {
if (ppp->protos[IDX_LCP].state == OPENED)
ppp_tx_cp(dev, PID_LCP, LCP_PROTO_REJ,
++ppp->seq, skb->len + 2, &hdr->protocol);
goto rx_error;
}
len = ntohs(cp->len);
if (len < sizeof(struct cp_header) ||
skb->len < len )
goto rx_error;
skb_pull(skb, sizeof(struct cp_header));
len -= sizeof(struct cp_header);
#if DEBUG_CP
if (cp->code < CP_CODES)
sprintf(debug_buffer, "[%s id 0x%X]", code_names[cp->code],
cp->id);
else
sprintf(debug_buffer, "[code %u id 0x%X]", cp->code, cp->id);
ptr = debug_buffer + strlen(debug_buffer);
for (i = 0; i < min_t(unsigned int, len, DEBUG_CP); i++) {
sprintf(ptr, " %02X", skb->data[i]);
ptr += strlen(ptr);
}
printk(KERN_DEBUG "%s: RX %s %s\n", dev->name, proto_name(pid),
debug_buffer);
#endif
if (pid == PID_LCP)
switch (cp->code) {
case LCP_PROTO_REJ:
pid = ntohs(*(__be16*)skb->data);
if (pid == PID_LCP || pid == PID_IPCP ||
pid == PID_IPV6CP)
ppp_cp_event(dev, pid, RXJ_BAD, 0, 0,
0, NULL);
goto out;
case LCP_ECHO_REQ:
if (len >= 4 && proto->state == OPENED)
ppp_tx_cp(dev, PID_LCP, LCP_ECHO_REPLY,
cp->id, len - 4, skb->data + 4);
goto out;
case LCP_ECHO_REPLY:
if (cp->id == ppp->echo_id)
ppp->last_pong = jiffies;
goto out;
case LCP_DISC_REQ:
goto out;
}
switch (cp->code) {
case CP_CONF_REQ:
ppp_cp_parse_cr(dev, pid, cp->id, len, skb->data);
break;
case CP_CONF_ACK:
if (cp->id == proto->cr_id)
ppp_cp_event(dev, pid, RCA, 0, 0, 0, NULL);
break;
case CP_CONF_REJ:
case CP_CONF_NAK:
if (cp->id == proto->cr_id)
ppp_cp_event(dev, pid, RCN, 0, 0, 0, NULL);
break;
case CP_TERM_REQ:
ppp_cp_event(dev, pid, RTR, 0, cp->id, 0, NULL);
break;
case CP_TERM_ACK:
ppp_cp_event(dev, pid, RTA, 0, 0, 0, NULL);
break;
case CP_CODE_REJ:
ppp_cp_event(dev, pid, RXJ_BAD, 0, 0, 0, NULL);
break;
default:
len += sizeof(struct cp_header);
if (len > dev->mtu)
len = dev->mtu;
ppp_cp_event(dev, pid, RUC, 0, 0, len, cp);
break;
}
goto out;
rx_error:
dev->stats.rx_errors++;
out:
spin_unlock_irqrestore(&ppp->lock, flags);
dev_kfree_skb_any(skb);
ppp_tx_flush();
return NET_RX_DROP;
}
static void ppp_timer(unsigned long arg)
{
struct proto *proto = (struct proto *)arg;
struct ppp *ppp = get_ppp(proto->dev);
unsigned long flags;
spin_lock_irqsave(&ppp->lock, flags);
switch (proto->state) {
case STOPPING:
case REQ_SENT:
case ACK_RECV:
case ACK_SENT:
if (proto->restart_counter) {
ppp_cp_event(proto->dev, proto->pid, TO_GOOD, 0, 0,
0, NULL);
proto->restart_counter--;
} else
ppp_cp_event(proto->dev, proto->pid, TO_BAD, 0, 0,
0, NULL);
break;
case OPENED:
if (proto->pid != PID_LCP)
break;
if (time_after(jiffies, ppp->last_pong +
ppp->keepalive_timeout * HZ)) {
netdev_info(proto->dev, "Link down\n");
ppp_cp_event(proto->dev, PID_LCP, STOP, 0, 0, 0, NULL);
ppp_cp_event(proto->dev, PID_LCP, START, 0, 0, 0, NULL);
} else {
ppp->echo_id = ++ppp->seq;
ppp_tx_cp(proto->dev, PID_LCP, LCP_ECHO_REQ,
ppp->echo_id, 0, NULL);
proto->timer.expires = jiffies +
ppp->keepalive_interval * HZ;
add_timer(&proto->timer);
}
break;
}
spin_unlock_irqrestore(&ppp->lock, flags);
ppp_tx_flush();
}
static void ppp_start(struct net_device *dev)
{
struct ppp *ppp = get_ppp(dev);
int i;
for (i = 0; i < IDX_COUNT; i++) {
struct proto *proto = &ppp->protos[i];
proto->dev = dev;
init_timer(&proto->timer);
proto->timer.function = ppp_timer;
proto->timer.data = (unsigned long)proto;
proto->state = CLOSED;
}
ppp->protos[IDX_LCP].pid = PID_LCP;
ppp->protos[IDX_IPCP].pid = PID_IPCP;
ppp->protos[IDX_IPV6CP].pid = PID_IPV6CP;
ppp_cp_event(dev, PID_LCP, START, 0, 0, 0, NULL);
}
static void ppp_stop(struct net_device *dev)
{
ppp_cp_event(dev, PID_LCP, STOP, 0, 0, 0, NULL);
}
static void ppp_close(struct net_device *dev)
{
ppp_tx_flush();
}
static int ppp_ioctl(struct net_device *dev, struct ifreq *ifr)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
struct ppp *ppp;
int result;
switch (ifr->ifr_settings.type) {
case IF_GET_PROTO:
if (dev_to_hdlc(dev)->proto != &proto)
return -EINVAL;
ifr->ifr_settings.type = IF_PROTO_PPP;
return 0;
case IF_PROTO_PPP:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (dev->flags & IFF_UP)
return -EBUSY;
result = hdlc->attach(dev, ENCODING_NRZ,PARITY_CRC16_PR1_CCITT);
if (result)
return result;
result = attach_hdlc_protocol(dev, &proto, sizeof(struct ppp));
if (result)
return result;
ppp = get_ppp(dev);
spin_lock_init(&ppp->lock);
ppp->req_timeout = 2;
ppp->cr_retries = 10;
ppp->term_retries = 2;
ppp->keepalive_interval = 10;
ppp->keepalive_timeout = 60;
dev->hard_header_len = sizeof(struct hdlc_header);
dev->header_ops = &ppp_header_ops;
dev->type = ARPHRD_PPP;
call_netdevice_notifiers(NETDEV_POST_TYPE_CHANGE, dev);
netif_dormant_on(dev);
return 0;
}
return -EINVAL;
}
static int __init mod_init(void)
{
skb_queue_head_init(&tx_queue);
register_hdlc_protocol(&proto);
return 0;
}
static void __exit mod_exit(void)
{
unregister_hdlc_protocol(&proto);
}
