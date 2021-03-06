static inline u16 q922_to_dlci(u8 *hdr)
{
return ((hdr[0] & 0xFC) << 2) | ((hdr[1] & 0xF0) >> 4);
}
static inline void dlci_to_q922(u8 *hdr, u16 dlci)
{
hdr[0] = (dlci >> 2) & 0xFC;
hdr[1] = ((dlci << 4) & 0xF0) | 0x01;
}
static inline struct frad_state* state(hdlc_device *hdlc)
{
return(struct frad_state *)(hdlc->state);
}
static inline struct pvc_device *find_pvc(hdlc_device *hdlc, u16 dlci)
{
struct pvc_device *pvc = state(hdlc)->first_pvc;
while (pvc) {
if (pvc->dlci == dlci)
return pvc;
if (pvc->dlci > dlci)
return NULL;
pvc = pvc->next;
}
return NULL;
}
static struct pvc_device *add_pvc(struct net_device *dev, u16 dlci)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
struct pvc_device *pvc, **pvc_p = &state(hdlc)->first_pvc;
while (*pvc_p) {
if ((*pvc_p)->dlci == dlci)
return *pvc_p;
if ((*pvc_p)->dlci > dlci)
break;
pvc_p = &(*pvc_p)->next;
}
pvc = kzalloc(sizeof(*pvc), GFP_ATOMIC);
#ifdef DEBUG_PVC
printk(KERN_DEBUG "add_pvc: allocated pvc %p, frad %p\n", pvc, dev);
#endif
if (!pvc)
return NULL;
pvc->dlci = dlci;
pvc->frad = dev;
pvc->next = *pvc_p;
*pvc_p = pvc;
return pvc;
}
static inline int pvc_is_used(struct pvc_device *pvc)
{
return pvc->main || pvc->ether;
}
static inline void pvc_carrier(int on, struct pvc_device *pvc)
{
if (on) {
if (pvc->main)
if (!netif_carrier_ok(pvc->main))
netif_carrier_on(pvc->main);
if (pvc->ether)
if (!netif_carrier_ok(pvc->ether))
netif_carrier_on(pvc->ether);
} else {
if (pvc->main)
if (netif_carrier_ok(pvc->main))
netif_carrier_off(pvc->main);
if (pvc->ether)
if (netif_carrier_ok(pvc->ether))
netif_carrier_off(pvc->ether);
}
}
static inline void delete_unused_pvcs(hdlc_device *hdlc)
{
struct pvc_device **pvc_p = &state(hdlc)->first_pvc;
while (*pvc_p) {
if (!pvc_is_used(*pvc_p)) {
struct pvc_device *pvc = *pvc_p;
#ifdef DEBUG_PVC
printk(KERN_DEBUG "freeing unused pvc: %p\n", pvc);
#endif
*pvc_p = pvc->next;
kfree(pvc);
continue;
}
pvc_p = &(*pvc_p)->next;
}
}
static inline struct net_device **get_dev_p(struct pvc_device *pvc,
int type)
{
if (type == ARPHRD_ETHER)
return &pvc->ether;
else
return &pvc->main;
}
static int fr_hard_header(struct sk_buff **skb_p, u16 dlci)
{
u16 head_len;
struct sk_buff *skb = *skb_p;
switch (skb->protocol) {
case cpu_to_be16(NLPID_CCITT_ANSI_LMI):
head_len = 4;
skb_push(skb, head_len);
skb->data[3] = NLPID_CCITT_ANSI_LMI;
break;
case cpu_to_be16(NLPID_CISCO_LMI):
head_len = 4;
skb_push(skb, head_len);
skb->data[3] = NLPID_CISCO_LMI;
break;
case cpu_to_be16(ETH_P_IP):
head_len = 4;
skb_push(skb, head_len);
skb->data[3] = NLPID_IP;
break;
case cpu_to_be16(ETH_P_IPV6):
head_len = 4;
skb_push(skb, head_len);
skb->data[3] = NLPID_IPV6;
break;
case cpu_to_be16(ETH_P_802_3):
head_len = 10;
if (skb_headroom(skb) < head_len) {
struct sk_buff *skb2 = skb_realloc_headroom(skb,
head_len);
if (!skb2)
return -ENOBUFS;
dev_kfree_skb(skb);
skb = *skb_p = skb2;
}
skb_push(skb, head_len);
skb->data[3] = FR_PAD;
skb->data[4] = NLPID_SNAP;
skb->data[5] = FR_PAD;
skb->data[6] = 0x80;
skb->data[7] = 0xC2;
skb->data[8] = 0x00;
skb->data[9] = 0x07;
break;
default:
head_len = 10;
skb_push(skb, head_len);
skb->data[3] = FR_PAD;
skb->data[4] = NLPID_SNAP;
skb->data[5] = FR_PAD;
skb->data[6] = FR_PAD;
skb->data[7] = FR_PAD;
*(__be16*)(skb->data + 8) = skb->protocol;
}
dlci_to_q922(skb->data, dlci);
skb->data[2] = FR_UI;
return 0;
}
static int pvc_open(struct net_device *dev)
{
struct pvc_device *pvc = dev->ml_priv;
if ((pvc->frad->flags & IFF_UP) == 0)
return -EIO;
if (pvc->open_count++ == 0) {
hdlc_device *hdlc = dev_to_hdlc(pvc->frad);
if (state(hdlc)->settings.lmi == LMI_NONE)
pvc->state.active = netif_carrier_ok(pvc->frad);
pvc_carrier(pvc->state.active, pvc);
state(hdlc)->dce_changed = 1;
}
return 0;
}
static int pvc_close(struct net_device *dev)
{
struct pvc_device *pvc = dev->ml_priv;
if (--pvc->open_count == 0) {
hdlc_device *hdlc = dev_to_hdlc(pvc->frad);
if (state(hdlc)->settings.lmi == LMI_NONE)
pvc->state.active = 0;
if (state(hdlc)->settings.dce) {
state(hdlc)->dce_changed = 1;
pvc->state.active = 0;
}
}
return 0;
}
static int pvc_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct pvc_device *pvc = dev->ml_priv;
fr_proto_pvc_info info;
if (ifr->ifr_settings.type == IF_GET_PROTO) {
if (dev->type == ARPHRD_ETHER)
ifr->ifr_settings.type = IF_PROTO_FR_ETH_PVC;
else
ifr->ifr_settings.type = IF_PROTO_FR_PVC;
if (ifr->ifr_settings.size < sizeof(info)) {
ifr->ifr_settings.size = sizeof(info);
return -ENOBUFS;
}
info.dlci = pvc->dlci;
memcpy(info.master, pvc->frad->name, IFNAMSIZ);
if (copy_to_user(ifr->ifr_settings.ifs_ifsu.fr_pvc_info,
&info, sizeof(info)))
return -EFAULT;
return 0;
}
return -EINVAL;
}
static netdev_tx_t pvc_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct pvc_device *pvc = dev->ml_priv;
if (pvc->state.active) {
if (dev->type == ARPHRD_ETHER) {
int pad = ETH_ZLEN - skb->len;
if (pad > 0) {
int len = skb->len;
if (skb_tailroom(skb) < pad)
if (pskb_expand_head(skb, 0, pad,
GFP_ATOMIC)) {
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
skb_put(skb, pad);
memset(skb->data + len, 0, pad);
}
skb->protocol = cpu_to_be16(ETH_P_802_3);
}
if (!fr_hard_header(&skb, pvc->dlci)) {
dev->stats.tx_bytes += skb->len;
dev->stats.tx_packets++;
if (pvc->state.fecn)
dev->stats.tx_compressed++;
skb->dev = pvc->frad;
dev_queue_xmit(skb);
return NETDEV_TX_OK;
}
}
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static inline void fr_log_dlci_active(struct pvc_device *pvc)
{
netdev_info(pvc->frad, "DLCI %d [%s%s%s]%s %s\n",
pvc->dlci,
pvc->main ? pvc->main->name : "",
pvc->main && pvc->ether ? " " : "",
pvc->ether ? pvc->ether->name : "",
pvc->state.new ? " new" : "",
!pvc->state.exist ? "deleted" :
pvc->state.active ? "active" : "inactive");
}
static inline u8 fr_lmi_nextseq(u8 x)
{
x++;
return x ? x : 1;
}
static void fr_lmi_send(struct net_device *dev, int fullrep)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
struct sk_buff *skb;
struct pvc_device *pvc = state(hdlc)->first_pvc;
int lmi = state(hdlc)->settings.lmi;
int dce = state(hdlc)->settings.dce;
int len = lmi == LMI_ANSI ? LMI_ANSI_LENGTH : LMI_CCITT_CISCO_LENGTH;
int stat_len = (lmi == LMI_CISCO) ? 6 : 3;
u8 *data;
int i = 0;
if (dce && fullrep) {
len += state(hdlc)->dce_pvc_count * (2 + stat_len);
if (len > HDLC_MAX_MRU) {
netdev_warn(dev, "Too many PVCs while sending LMI full report\n");
return;
}
}
skb = dev_alloc_skb(len);
if (!skb) {
netdev_warn(dev, "Memory squeeze on fr_lmi_send()\n");
return;
}
memset(skb->data, 0, len);
skb_reserve(skb, 4);
if (lmi == LMI_CISCO) {
skb->protocol = cpu_to_be16(NLPID_CISCO_LMI);
fr_hard_header(&skb, LMI_CISCO_DLCI);
} else {
skb->protocol = cpu_to_be16(NLPID_CCITT_ANSI_LMI);
fr_hard_header(&skb, LMI_CCITT_ANSI_DLCI);
}
data = skb_tail_pointer(skb);
data[i++] = LMI_CALLREF;
data[i++] = dce ? LMI_STATUS : LMI_STATUS_ENQUIRY;
if (lmi == LMI_ANSI)
data[i++] = LMI_ANSI_LOCKSHIFT;
data[i++] = lmi == LMI_CCITT ? LMI_CCITT_REPTYPE :
LMI_ANSI_CISCO_REPTYPE;
data[i++] = LMI_REPT_LEN;
data[i++] = fullrep ? LMI_FULLREP : LMI_INTEGRITY;
data[i++] = lmi == LMI_CCITT ? LMI_CCITT_ALIVE : LMI_ANSI_CISCO_ALIVE;
data[i++] = LMI_INTEG_LEN;
data[i++] = state(hdlc)->txseq =
fr_lmi_nextseq(state(hdlc)->txseq);
data[i++] = state(hdlc)->rxseq;
if (dce && fullrep) {
while (pvc) {
data[i++] = lmi == LMI_CCITT ? LMI_CCITT_PVCSTAT :
LMI_ANSI_CISCO_PVCSTAT;
data[i++] = stat_len;
if (state(hdlc)->reliable && !pvc->state.exist) {
pvc->state.exist = pvc->state.new = 1;
fr_log_dlci_active(pvc);
}
if (pvc->open_count && !pvc->state.active &&
pvc->state.exist && !pvc->state.new) {
pvc_carrier(1, pvc);
pvc->state.active = 1;
fr_log_dlci_active(pvc);
}
if (lmi == LMI_CISCO) {
data[i] = pvc->dlci >> 8;
data[i + 1] = pvc->dlci & 0xFF;
} else {
data[i] = (pvc->dlci >> 4) & 0x3F;
data[i + 1] = ((pvc->dlci << 3) & 0x78) | 0x80;
data[i + 2] = 0x80;
}
if (pvc->state.new)
data[i + 2] |= 0x08;
else if (pvc->state.active)
data[i + 2] |= 0x02;
i += stat_len;
pvc = pvc->next;
}
}
skb_put(skb, i);
skb->priority = TC_PRIO_CONTROL;
skb->dev = dev;
skb_reset_network_header(skb);
dev_queue_xmit(skb);
}
static void fr_set_link_state(int reliable, struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
struct pvc_device *pvc = state(hdlc)->first_pvc;
state(hdlc)->reliable = reliable;
if (reliable) {
netif_dormant_off(dev);
state(hdlc)->n391cnt = 0;
state(hdlc)->dce_changed = 1;
if (state(hdlc)->settings.lmi == LMI_NONE) {
while (pvc) {
pvc_carrier(1, pvc);
pvc->state.exist = pvc->state.active = 1;
pvc->state.new = 0;
pvc = pvc->next;
}
}
} else {
netif_dormant_on(dev);
while (pvc) {
pvc_carrier(0, pvc);
pvc->state.exist = pvc->state.active = 0;
pvc->state.new = 0;
if (!state(hdlc)->settings.dce)
pvc->state.bandwidth = 0;
pvc = pvc->next;
}
}
}
static void fr_timer(unsigned long arg)
{
struct net_device *dev = (struct net_device *)arg;
hdlc_device *hdlc = dev_to_hdlc(dev);
int i, cnt = 0, reliable;
u32 list;
if (state(hdlc)->settings.dce) {
reliable = state(hdlc)->request &&
time_before(jiffies, state(hdlc)->last_poll +
state(hdlc)->settings.t392 * HZ);
state(hdlc)->request = 0;
} else {
state(hdlc)->last_errors <<= 1;
if (state(hdlc)->request) {
if (state(hdlc)->reliable)
netdev_info(dev, "No LMI status reply received\n");
state(hdlc)->last_errors |= 1;
}
list = state(hdlc)->last_errors;
for (i = 0; i < state(hdlc)->settings.n393; i++, list >>= 1)
cnt += (list & 1);
reliable = (cnt < state(hdlc)->settings.n392);
}
if (state(hdlc)->reliable != reliable) {
netdev_info(dev, "Link %sreliable\n", reliable ? "" : "un");
fr_set_link_state(reliable, dev);
}
if (state(hdlc)->settings.dce)
state(hdlc)->timer.expires = jiffies +
state(hdlc)->settings.t392 * HZ;
else {
if (state(hdlc)->n391cnt)
state(hdlc)->n391cnt--;
fr_lmi_send(dev, state(hdlc)->n391cnt == 0);
state(hdlc)->last_poll = jiffies;
state(hdlc)->request = 1;
state(hdlc)->timer.expires = jiffies +
state(hdlc)->settings.t391 * HZ;
}
state(hdlc)->timer.function = fr_timer;
state(hdlc)->timer.data = arg;
add_timer(&state(hdlc)->timer);
}
static int fr_lmi_recv(struct net_device *dev, struct sk_buff *skb)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
struct pvc_device *pvc;
u8 rxseq, txseq;
int lmi = state(hdlc)->settings.lmi;
int dce = state(hdlc)->settings.dce;
int stat_len = (lmi == LMI_CISCO) ? 6 : 3, reptype, error, no_ram, i;
if (skb->len < (lmi == LMI_ANSI ? LMI_ANSI_LENGTH :
LMI_CCITT_CISCO_LENGTH)) {
netdev_info(dev, "Short LMI frame\n");
return 1;
}
if (skb->data[3] != (lmi == LMI_CISCO ? NLPID_CISCO_LMI :
NLPID_CCITT_ANSI_LMI)) {
netdev_info(dev, "Received non-LMI frame with LMI DLCI\n");
return 1;
}
if (skb->data[4] != LMI_CALLREF) {
netdev_info(dev, "Invalid LMI Call reference (0x%02X)\n",
skb->data[4]);
return 1;
}
if (skb->data[5] != (dce ? LMI_STATUS_ENQUIRY : LMI_STATUS)) {
netdev_info(dev, "Invalid LMI Message type (0x%02X)\n",
skb->data[5]);
return 1;
}
if (lmi == LMI_ANSI) {
if (skb->data[6] != LMI_ANSI_LOCKSHIFT) {
netdev_info(dev, "Not ANSI locking shift in LMI message (0x%02X)\n",
skb->data[6]);
return 1;
}
i = 7;
} else
i = 6;
if (skb->data[i] != (lmi == LMI_CCITT ? LMI_CCITT_REPTYPE :
LMI_ANSI_CISCO_REPTYPE)) {
netdev_info(dev, "Not an LMI Report type IE (0x%02X)\n",
skb->data[i]);
return 1;
}
if (skb->data[++i] != LMI_REPT_LEN) {
netdev_info(dev, "Invalid LMI Report type IE length (%u)\n",
skb->data[i]);
return 1;
}
reptype = skb->data[++i];
if (reptype != LMI_INTEGRITY && reptype != LMI_FULLREP) {
netdev_info(dev, "Unsupported LMI Report type (0x%02X)\n",
reptype);
return 1;
}
if (skb->data[++i] != (lmi == LMI_CCITT ? LMI_CCITT_ALIVE :
LMI_ANSI_CISCO_ALIVE)) {
netdev_info(dev, "Not an LMI Link integrity verification IE (0x%02X)\n",
skb->data[i]);
return 1;
}
if (skb->data[++i] != LMI_INTEG_LEN) {
netdev_info(dev, "Invalid LMI Link integrity verification IE length (%u)\n",
skb->data[i]);
return 1;
}
i++;
state(hdlc)->rxseq = skb->data[i++];
rxseq = skb->data[i++];
txseq = state(hdlc)->txseq;
if (dce)
state(hdlc)->last_poll = jiffies;
error = 0;
if (!state(hdlc)->reliable)
error = 1;
if (rxseq == 0 || rxseq != txseq) {
state(hdlc)->n391cnt = 0;
error = 1;
}
if (dce) {
if (state(hdlc)->fullrep_sent && !error) {
state(hdlc)->fullrep_sent = 0;
pvc = state(hdlc)->first_pvc;
while (pvc) {
if (pvc->state.new) {
pvc->state.new = 0;
state(hdlc)->dce_changed = 1;
}
pvc = pvc->next;
}
}
if (state(hdlc)->dce_changed) {
reptype = LMI_FULLREP;
state(hdlc)->fullrep_sent = 1;
state(hdlc)->dce_changed = 0;
}
state(hdlc)->request = 1;
fr_lmi_send(dev, reptype == LMI_FULLREP ? 1 : 0);
return 0;
}
state(hdlc)->request = 0;
if (error)
return 0;
if (reptype != LMI_FULLREP)
return 0;
pvc = state(hdlc)->first_pvc;
while (pvc) {
pvc->state.deleted = 1;
pvc = pvc->next;
}
no_ram = 0;
while (skb->len >= i + 2 + stat_len) {
u16 dlci;
u32 bw;
unsigned int active, new;
if (skb->data[i] != (lmi == LMI_CCITT ? LMI_CCITT_PVCSTAT :
LMI_ANSI_CISCO_PVCSTAT)) {
netdev_info(dev, "Not an LMI PVC status IE (0x%02X)\n",
skb->data[i]);
return 1;
}
if (skb->data[++i] != stat_len) {
netdev_info(dev, "Invalid LMI PVC status IE length (%u)\n",
skb->data[i]);
return 1;
}
i++;
new = !! (skb->data[i + 2] & 0x08);
active = !! (skb->data[i + 2] & 0x02);
if (lmi == LMI_CISCO) {
dlci = (skb->data[i] << 8) | skb->data[i + 1];
bw = (skb->data[i + 3] << 16) |
(skb->data[i + 4] << 8) |
(skb->data[i + 5]);
} else {
dlci = ((skb->data[i] & 0x3F) << 4) |
((skb->data[i + 1] & 0x78) >> 3);
bw = 0;
}
pvc = add_pvc(dev, dlci);
if (!pvc && !no_ram) {
netdev_warn(dev, "Memory squeeze on fr_lmi_recv()\n");
no_ram = 1;
}
if (pvc) {
pvc->state.exist = 1;
pvc->state.deleted = 0;
if (active != pvc->state.active ||
new != pvc->state.new ||
bw != pvc->state.bandwidth ||
!pvc->state.exist) {
pvc->state.new = new;
pvc->state.active = active;
pvc->state.bandwidth = bw;
pvc_carrier(active, pvc);
fr_log_dlci_active(pvc);
}
}
i += stat_len;
}
pvc = state(hdlc)->first_pvc;
while (pvc) {
if (pvc->state.deleted && pvc->state.exist) {
pvc_carrier(0, pvc);
pvc->state.active = pvc->state.new = 0;
pvc->state.exist = 0;
pvc->state.bandwidth = 0;
fr_log_dlci_active(pvc);
}
pvc = pvc->next;
}
state(hdlc)->n391cnt = state(hdlc)->settings.n391;
return 0;
}
static int fr_rx(struct sk_buff *skb)
{
struct net_device *frad = skb->dev;
hdlc_device *hdlc = dev_to_hdlc(frad);
struct fr_hdr *fh = (struct fr_hdr *)skb->data;
u8 *data = skb->data;
u16 dlci;
struct pvc_device *pvc;
struct net_device *dev = NULL;
if (skb->len <= 4 || fh->ea1 || data[2] != FR_UI)
goto rx_error;
dlci = q922_to_dlci(skb->data);
if ((dlci == LMI_CCITT_ANSI_DLCI &&
(state(hdlc)->settings.lmi == LMI_ANSI ||
state(hdlc)->settings.lmi == LMI_CCITT)) ||
(dlci == LMI_CISCO_DLCI &&
state(hdlc)->settings.lmi == LMI_CISCO)) {
if (fr_lmi_recv(frad, skb))
goto rx_error;
dev_kfree_skb_any(skb);
return NET_RX_SUCCESS;
}
pvc = find_pvc(hdlc, dlci);
if (!pvc) {
#ifdef DEBUG_PKT
netdev_info(frad, "No PVC for received frame's DLCI %d\n",
dlci);
#endif
dev_kfree_skb_any(skb);
return NET_RX_DROP;
}
if (pvc->state.fecn != fh->fecn) {
#ifdef DEBUG_ECN
printk(KERN_DEBUG "%s: DLCI %d FECN O%s\n", frad->name,
dlci, fh->fecn ? "N" : "FF");
#endif
pvc->state.fecn ^= 1;
}
if (pvc->state.becn != fh->becn) {
#ifdef DEBUG_ECN
printk(KERN_DEBUG "%s: DLCI %d BECN O%s\n", frad->name,
dlci, fh->becn ? "N" : "FF");
#endif
pvc->state.becn ^= 1;
}
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL) {
frad->stats.rx_dropped++;
return NET_RX_DROP;
}
if (data[3] == NLPID_IP) {
skb_pull(skb, 4);
dev = pvc->main;
skb->protocol = htons(ETH_P_IP);
} else if (data[3] == NLPID_IPV6) {
skb_pull(skb, 4);
dev = pvc->main;
skb->protocol = htons(ETH_P_IPV6);
} else if (skb->len > 10 && data[3] == FR_PAD &&
data[4] == NLPID_SNAP && data[5] == FR_PAD) {
u16 oui = ntohs(*(__be16*)(data + 6));
u16 pid = ntohs(*(__be16*)(data + 8));
skb_pull(skb, 10);
switch ((((u32)oui) << 16) | pid) {
case ETH_P_ARP:
case ETH_P_IPX:
case ETH_P_IP:
case ETH_P_IPV6:
dev = pvc->main;
skb->protocol = htons(pid);
break;
case 0x80C20007:
if ((dev = pvc->ether) != NULL)
skb->protocol = eth_type_trans(skb, dev);
break;
default:
netdev_info(frad, "Unsupported protocol, OUI=%x PID=%x\n",
oui, pid);
dev_kfree_skb_any(skb);
return NET_RX_DROP;
}
} else {
netdev_info(frad, "Unsupported protocol, NLPID=%x length=%i\n",
data[3], skb->len);
dev_kfree_skb_any(skb);
return NET_RX_DROP;
}
if (dev) {
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
if (pvc->state.becn)
dev->stats.rx_compressed++;
skb->dev = dev;
netif_rx(skb);
return NET_RX_SUCCESS;
} else {
dev_kfree_skb_any(skb);
return NET_RX_DROP;
}
rx_error:
frad->stats.rx_errors++;
dev_kfree_skb_any(skb);
return NET_RX_DROP;
}
static void fr_start(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
#ifdef DEBUG_LINK
printk(KERN_DEBUG "fr_start\n");
#endif
if (state(hdlc)->settings.lmi != LMI_NONE) {
state(hdlc)->reliable = 0;
state(hdlc)->dce_changed = 1;
state(hdlc)->request = 0;
state(hdlc)->fullrep_sent = 0;
state(hdlc)->last_errors = 0xFFFFFFFF;
state(hdlc)->n391cnt = 0;
state(hdlc)->txseq = state(hdlc)->rxseq = 0;
init_timer(&state(hdlc)->timer);
state(hdlc)->timer.expires = jiffies + HZ;
state(hdlc)->timer.function = fr_timer;
state(hdlc)->timer.data = (unsigned long)dev;
add_timer(&state(hdlc)->timer);
} else
fr_set_link_state(1, dev);
}
static void fr_stop(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
#ifdef DEBUG_LINK
printk(KERN_DEBUG "fr_stop\n");
#endif
if (state(hdlc)->settings.lmi != LMI_NONE)
del_timer_sync(&state(hdlc)->timer);
fr_set_link_state(0, dev);
}
static void fr_close(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
struct pvc_device *pvc = state(hdlc)->first_pvc;
while (pvc) {
if (pvc->main)
dev_close(pvc->main);
if (pvc->ether)
dev_close(pvc->ether);
pvc = pvc->next;
}
}
static void pvc_setup(struct net_device *dev)
{
dev->type = ARPHRD_DLCI;
dev->flags = IFF_POINTOPOINT;
dev->hard_header_len = 10;
dev->addr_len = 2;
netif_keep_dst(dev);
}
static int fr_add_pvc(struct net_device *frad, unsigned int dlci, int type)
{
hdlc_device *hdlc = dev_to_hdlc(frad);
struct pvc_device *pvc;
struct net_device *dev;
int used;
if ((pvc = add_pvc(frad, dlci)) == NULL) {
netdev_warn(frad, "Memory squeeze on fr_add_pvc()\n");
return -ENOBUFS;
}
if (*get_dev_p(pvc, type))
return -EEXIST;
used = pvc_is_used(pvc);
if (type == ARPHRD_ETHER) {
dev = alloc_netdev(0, "pvceth%d", NET_NAME_UNKNOWN,
ether_setup);
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
} else
dev = alloc_netdev(0, "pvc%d", NET_NAME_UNKNOWN, pvc_setup);
if (!dev) {
netdev_warn(frad, "Memory squeeze on fr_pvc()\n");
delete_unused_pvcs(hdlc);
return -ENOBUFS;
}
if (type == ARPHRD_ETHER)
eth_hw_addr_random(dev);
else {
*(__be16*)dev->dev_addr = htons(dlci);
dlci_to_q922(dev->broadcast, dlci);
}
dev->netdev_ops = &pvc_ops;
dev->mtu = HDLC_MAX_MTU;
dev->tx_queue_len = 0;
dev->ml_priv = pvc;
if (register_netdevice(dev) != 0) {
free_netdev(dev);
delete_unused_pvcs(hdlc);
return -EIO;
}
dev->destructor = free_netdev;
*get_dev_p(pvc, type) = dev;
if (!used) {
state(hdlc)->dce_changed = 1;
state(hdlc)->dce_pvc_count++;
}
return 0;
}
static int fr_del_pvc(hdlc_device *hdlc, unsigned int dlci, int type)
{
struct pvc_device *pvc;
struct net_device *dev;
if ((pvc = find_pvc(hdlc, dlci)) == NULL)
return -ENOENT;
if ((dev = *get_dev_p(pvc, type)) == NULL)
return -ENOENT;
if (dev->flags & IFF_UP)
return -EBUSY;
unregister_netdevice(dev);
*get_dev_p(pvc, type) = NULL;
if (!pvc_is_used(pvc)) {
state(hdlc)->dce_pvc_count--;
state(hdlc)->dce_changed = 1;
}
delete_unused_pvcs(hdlc);
return 0;
}
static void fr_destroy(struct net_device *frad)
{
hdlc_device *hdlc = dev_to_hdlc(frad);
struct pvc_device *pvc = state(hdlc)->first_pvc;
state(hdlc)->first_pvc = NULL;
state(hdlc)->dce_pvc_count = 0;
state(hdlc)->dce_changed = 1;
while (pvc) {
struct pvc_device *next = pvc->next;
if (pvc->main)
unregister_netdevice(pvc->main);
if (pvc->ether)
unregister_netdevice(pvc->ether);
kfree(pvc);
pvc = next;
}
}
static int fr_ioctl(struct net_device *dev, struct ifreq *ifr)
{
fr_proto __user *fr_s = ifr->ifr_settings.ifs_ifsu.fr;
const size_t size = sizeof(fr_proto);
fr_proto new_settings;
hdlc_device *hdlc = dev_to_hdlc(dev);
fr_proto_pvc pvc;
int result;
switch (ifr->ifr_settings.type) {
case IF_GET_PROTO:
if (dev_to_hdlc(dev)->proto != &proto)
return -EINVAL;
ifr->ifr_settings.type = IF_PROTO_FR;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
if (copy_to_user(fr_s, &state(hdlc)->settings, size))
return -EFAULT;
return 0;
case IF_PROTO_FR:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (dev->flags & IFF_UP)
return -EBUSY;
if (copy_from_user(&new_settings, fr_s, size))
return -EFAULT;
if (new_settings.lmi == LMI_DEFAULT)
new_settings.lmi = LMI_ANSI;
if ((new_settings.lmi != LMI_NONE &&
new_settings.lmi != LMI_ANSI &&
new_settings.lmi != LMI_CCITT &&
new_settings.lmi != LMI_CISCO) ||
new_settings.t391 < 1 ||
new_settings.t392 < 2 ||
new_settings.n391 < 1 ||
new_settings.n392 < 1 ||
new_settings.n393 < new_settings.n392 ||
new_settings.n393 > 32 ||
(new_settings.dce != 0 &&
new_settings.dce != 1))
return -EINVAL;
result=hdlc->attach(dev, ENCODING_NRZ,PARITY_CRC16_PR1_CCITT);
if (result)
return result;
if (dev_to_hdlc(dev)->proto != &proto) {
result = attach_hdlc_protocol(dev, &proto,
sizeof(struct frad_state));
if (result)
return result;
state(hdlc)->first_pvc = NULL;
state(hdlc)->dce_pvc_count = 0;
}
memcpy(&state(hdlc)->settings, &new_settings, size);
dev->type = ARPHRD_FRAD;
return 0;
case IF_PROTO_FR_ADD_PVC:
case IF_PROTO_FR_DEL_PVC:
case IF_PROTO_FR_ADD_ETH_PVC:
case IF_PROTO_FR_DEL_ETH_PVC:
if (dev_to_hdlc(dev)->proto != &proto)
return -EINVAL;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user(&pvc, ifr->ifr_settings.ifs_ifsu.fr_pvc,
sizeof(fr_proto_pvc)))
return -EFAULT;
if (pvc.dlci <= 0 || pvc.dlci >= 1024)
return -EINVAL;
if (ifr->ifr_settings.type == IF_PROTO_FR_ADD_ETH_PVC ||
ifr->ifr_settings.type == IF_PROTO_FR_DEL_ETH_PVC)
result = ARPHRD_ETHER;
else
result = ARPHRD_DLCI;
if (ifr->ifr_settings.type == IF_PROTO_FR_ADD_PVC ||
ifr->ifr_settings.type == IF_PROTO_FR_ADD_ETH_PVC)
return fr_add_pvc(dev, pvc.dlci, result);
else
return fr_del_pvc(hdlc, pvc.dlci, result);
}
return -EINVAL;
}
static int __init mod_init(void)
{
register_hdlc_protocol(&proto);
return 0;
}
static void __exit mod_exit(void)
{
unregister_hdlc_protocol(&proto);
}
