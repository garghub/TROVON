int skb_ether_to_p80211(struct wlandevice *wlandev, u32 ethconv,
struct sk_buff *skb, union p80211_hdr *p80211_hdr,
struct p80211_metawep *p80211_wep)
{
__le16 fc;
u16 proto;
struct wlan_ethhdr e_hdr;
struct wlan_llc *e_llc;
struct wlan_snap *e_snap;
int foo;
memcpy(&e_hdr, skb->data, sizeof(e_hdr));
if (skb->len <= 0) {
pr_debug("zero-length skb!\n");
return 1;
}
if (ethconv == WLAN_ETHCONV_ENCAP) {
pr_debug("ENCAP len: %d\n", skb->len);
} else {
proto = ntohs(e_hdr.type);
if (proto <= ETH_DATA_LEN) {
pr_debug("802.3 len: %d\n", skb->len);
skb_pull(skb, ETH_HLEN);
skb_trim(skb, proto);
} else {
pr_debug("DIXII len: %d\n", skb->len);
skb_pull(skb, ETH_HLEN);
e_snap =
(struct wlan_snap *)skb_push(skb,
sizeof(struct wlan_snap));
e_snap->type = htons(proto);
if (ethconv == WLAN_ETHCONV_8021h &&
p80211_stt_findproto(proto)) {
memcpy(e_snap->oui, oui_8021h,
WLAN_IEEE_OUI_LEN);
} else {
memcpy(e_snap->oui, oui_rfc1042,
WLAN_IEEE_OUI_LEN);
}
e_llc =
(struct wlan_llc *)skb_push(skb,
sizeof(struct wlan_llc));
e_llc->dsap = 0xAA;
e_llc->ssap = 0xAA;
e_llc->ctl = 0x03;
}
}
fc = cpu_to_le16(WLAN_SET_FC_FTYPE(WLAN_FTYPE_DATA) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_DATAONLY));
switch (wlandev->macmode) {
case WLAN_MACMODE_IBSS_STA:
memcpy(p80211_hdr->a3.a1, &e_hdr.daddr, ETH_ALEN);
memcpy(p80211_hdr->a3.a2, wlandev->netdev->dev_addr, ETH_ALEN);
memcpy(p80211_hdr->a3.a3, wlandev->bssid, ETH_ALEN);
break;
case WLAN_MACMODE_ESS_STA:
fc |= cpu_to_le16(WLAN_SET_FC_TODS(1));
memcpy(p80211_hdr->a3.a1, wlandev->bssid, ETH_ALEN);
memcpy(p80211_hdr->a3.a2, wlandev->netdev->dev_addr, ETH_ALEN);
memcpy(p80211_hdr->a3.a3, &e_hdr.daddr, ETH_ALEN);
break;
case WLAN_MACMODE_ESS_AP:
fc |= cpu_to_le16(WLAN_SET_FC_FROMDS(1));
memcpy(p80211_hdr->a3.a1, &e_hdr.daddr, ETH_ALEN);
memcpy(p80211_hdr->a3.a2, wlandev->bssid, ETH_ALEN);
memcpy(p80211_hdr->a3.a3, &e_hdr.saddr, ETH_ALEN);
break;
default:
netdev_err(wlandev->netdev,
"Error: Converting eth to wlan in unknown mode.\n");
return 1;
}
p80211_wep->data = NULL;
if ((wlandev->hostwep & HOSTWEP_PRIVACYINVOKED) &&
(wlandev->hostwep & HOSTWEP_ENCRYPT)) {
p80211_wep->data = kmalloc(skb->len, GFP_ATOMIC);
if (!p80211_wep->data)
return -ENOMEM;
foo = wep_encrypt(wlandev, skb->data, p80211_wep->data,
skb->len,
(wlandev->hostwep & HOSTWEP_DEFAULTKEY_MASK),
p80211_wep->iv, p80211_wep->icv);
if (foo) {
netdev_warn(wlandev->netdev,
"Host en-WEP failed, dropping frame (%d).\n",
foo);
return 2;
}
fc |= cpu_to_le16(WLAN_SET_FC_ISWEP(1));
}
p80211_hdr->a3.fc = fc;
p80211_hdr->a3.dur = 0;
p80211_hdr->a3.seq = 0;
return 0;
}
static void orinoco_spy_gather(struct wlandevice *wlandev, char *mac,
struct p80211_rxmeta *rxmeta)
{
int i;
for (i = 0; i < wlandev->spy_number; i++) {
if (!memcmp(wlandev->spy_address[i], mac, ETH_ALEN)) {
wlandev->spy_stat[i].level = rxmeta->signal;
wlandev->spy_stat[i].noise = rxmeta->noise;
wlandev->spy_stat[i].qual =
(rxmeta->signal >
rxmeta->noise) ? (rxmeta->signal -
rxmeta->noise) : 0;
wlandev->spy_stat[i].updated = 0x7;
}
}
}
int skb_p80211_to_ether(struct wlandevice *wlandev, u32 ethconv,
struct sk_buff *skb)
{
struct net_device *netdev = wlandev->netdev;
u16 fc;
unsigned int payload_length;
unsigned int payload_offset;
u8 daddr[ETH_ALEN];
u8 saddr[ETH_ALEN];
union p80211_hdr *w_hdr;
struct wlan_ethhdr *e_hdr;
struct wlan_llc *e_llc;
struct wlan_snap *e_snap;
int foo;
payload_length = skb->len - WLAN_HDR_A3_LEN - WLAN_CRC_LEN;
payload_offset = WLAN_HDR_A3_LEN;
w_hdr = (union p80211_hdr *)skb->data;
fc = le16_to_cpu(w_hdr->a3.fc);
if ((WLAN_GET_FC_TODS(fc) == 0) && (WLAN_GET_FC_FROMDS(fc) == 0)) {
ether_addr_copy(daddr, w_hdr->a3.a1);
ether_addr_copy(saddr, w_hdr->a3.a2);
} else if ((WLAN_GET_FC_TODS(fc) == 0) &&
(WLAN_GET_FC_FROMDS(fc) == 1)) {
ether_addr_copy(daddr, w_hdr->a3.a1);
ether_addr_copy(saddr, w_hdr->a3.a3);
} else if ((WLAN_GET_FC_TODS(fc) == 1) &&
(WLAN_GET_FC_FROMDS(fc) == 0)) {
ether_addr_copy(daddr, w_hdr->a3.a3);
ether_addr_copy(saddr, w_hdr->a3.a2);
} else {
payload_offset = WLAN_HDR_A4_LEN;
if (payload_length < WLAN_HDR_A4_LEN - WLAN_HDR_A3_LEN) {
netdev_err(netdev, "A4 frame too short!\n");
return 1;
}
payload_length -= (WLAN_HDR_A4_LEN - WLAN_HDR_A3_LEN);
ether_addr_copy(daddr, w_hdr->a4.a3);
ether_addr_copy(saddr, w_hdr->a4.a4);
}
if ((wlandev->hostwep & HOSTWEP_PRIVACYINVOKED) &&
WLAN_GET_FC_ISWEP(fc) &&
(wlandev->hostwep & HOSTWEP_DECRYPT)) {
if (payload_length <= 8) {
netdev_err(netdev,
"WEP frame too short (%u).\n", skb->len);
return 1;
}
foo = wep_decrypt(wlandev, skb->data + payload_offset + 4,
payload_length - 8, -1,
skb->data + payload_offset,
skb->data + payload_offset +
payload_length - 4);
if (foo) {
pr_debug("Host de-WEP failed, dropping frame (%d).\n",
foo);
wlandev->rx.decrypt_err++;
return 2;
}
payload_length -= 8;
skb_pull(skb, 4);
skb_trim(skb, skb->len - 4);
wlandev->rx.decrypt++;
}
e_hdr = (struct wlan_ethhdr *)(skb->data + payload_offset);
e_llc = (struct wlan_llc *)(skb->data + payload_offset);
e_snap =
(struct wlan_snap *)(skb->data + payload_offset +
sizeof(struct wlan_llc));
if ((payload_length >= sizeof(struct wlan_ethhdr)) &&
(e_llc->dsap != 0xaa || e_llc->ssap != 0xaa) &&
((!ether_addr_equal_unaligned(daddr, e_hdr->daddr)) ||
(!ether_addr_equal_unaligned(saddr, e_hdr->saddr)))) {
pr_debug("802.3 ENCAP len: %d\n", payload_length);
if (payload_length > (netdev->mtu + ETH_HLEN)) {
netdev_err(netdev, "ENCAP frame too large (%d > %d)\n",
payload_length, netdev->mtu + ETH_HLEN);
return 1;
}
skb_pull(skb, payload_offset);
skb_trim(skb, skb->len - WLAN_CRC_LEN);
} else if ((payload_length >= sizeof(struct wlan_llc) +
sizeof(struct wlan_snap)) &&
(e_llc->dsap == 0xaa) &&
(e_llc->ssap == 0xaa) &&
(e_llc->ctl == 0x03) &&
(((memcmp(e_snap->oui, oui_rfc1042,
WLAN_IEEE_OUI_LEN) == 0) &&
(ethconv == WLAN_ETHCONV_8021h) &&
(p80211_stt_findproto(be16_to_cpu(e_snap->type)))) ||
(memcmp(e_snap->oui, oui_rfc1042, WLAN_IEEE_OUI_LEN) !=
0))) {
pr_debug("SNAP+RFC1042 len: %d\n", payload_length);
if (payload_length > netdev->mtu) {
netdev_err(netdev, "SNAP frame too large (%d > %d)\n",
payload_length, netdev->mtu);
return 1;
}
skb_pull(skb, payload_offset);
e_hdr = (struct wlan_ethhdr *)skb_push(skb, ETH_HLEN);
ether_addr_copy(e_hdr->daddr, daddr);
ether_addr_copy(e_hdr->saddr, saddr);
e_hdr->type = htons(payload_length);
skb_trim(skb, skb->len - WLAN_CRC_LEN);
} else if ((payload_length >= sizeof(struct wlan_llc) +
sizeof(struct wlan_snap)) &&
(e_llc->dsap == 0xaa) &&
(e_llc->ssap == 0xaa) &&
(e_llc->ctl == 0x03)) {
pr_debug("802.1h/RFC1042 len: %d\n", payload_length);
if ((payload_length - sizeof(struct wlan_llc) -
sizeof(struct wlan_snap))
> netdev->mtu) {
netdev_err(netdev, "DIXII frame too large (%ld > %d)\n",
(long int)(payload_length -
sizeof(struct wlan_llc) -
sizeof(struct wlan_snap)), netdev->mtu);
return 1;
}
skb_pull(skb, payload_offset);
skb_pull(skb, sizeof(struct wlan_llc));
skb_pull(skb, sizeof(struct wlan_snap));
e_hdr = (struct wlan_ethhdr *)skb_push(skb, ETH_HLEN);
e_hdr->type = e_snap->type;
ether_addr_copy(e_hdr->daddr, daddr);
ether_addr_copy(e_hdr->saddr, saddr);
skb_trim(skb, skb->len - WLAN_CRC_LEN);
} else {
pr_debug("NON-ENCAP len: %d\n", payload_length);
if (payload_length > netdev->mtu) {
netdev_err(netdev, "OTHER frame too large (%d > %d)\n",
payload_length, netdev->mtu);
return 1;
}
skb_pull(skb, payload_offset);
e_hdr = (struct wlan_ethhdr *)skb_push(skb, ETH_HLEN);
ether_addr_copy(e_hdr->daddr, daddr);
ether_addr_copy(e_hdr->saddr, saddr);
e_hdr->type = htons(payload_length);
skb_trim(skb, skb->len - WLAN_CRC_LEN);
}
skb->protocol = eth_type_trans(skb, netdev);
if (wlandev->spy_number)
orinoco_spy_gather(wlandev, eth_hdr(skb)->h_source,
P80211SKB_RXMETA(skb));
p80211skb_rxmeta_detach(skb);
return 0;
}
int p80211_stt_findproto(u16 proto)
{
if (proto == ETH_P_AARP)
return 1;
return 0;
}
void p80211skb_rxmeta_detach(struct sk_buff *skb)
{
struct p80211_rxmeta *rxmeta;
struct p80211_frmmeta *frmmeta;
if (!skb) {
pr_debug("Called w/ null skb.\n");
return;
}
frmmeta = P80211SKB_FRMMETA(skb);
if (!frmmeta) {
pr_debug("Called w/ bad frmmeta magic.\n");
return;
}
rxmeta = frmmeta->rx;
if (!rxmeta) {
pr_debug("Called w/ bad rxmeta ptr.\n");
return;
}
kfree(rxmeta);
memset(skb->cb, 0, sizeof(skb->cb));
}
int p80211skb_rxmeta_attach(struct wlandevice *wlandev, struct sk_buff *skb)
{
int result = 0;
struct p80211_rxmeta *rxmeta;
struct p80211_frmmeta *frmmeta;
if (P80211SKB_RXMETA(skb)) {
netdev_err(wlandev->netdev,
"%s: RXmeta already attached!\n", wlandev->name);
result = 0;
goto exit;
}
rxmeta = kzalloc(sizeof(*rxmeta), GFP_ATOMIC);
if (!rxmeta) {
result = 1;
goto exit;
}
rxmeta->wlandev = wlandev;
rxmeta->hosttime = jiffies;
memset(skb->cb, 0, sizeof(struct p80211_frmmeta));
frmmeta = (struct p80211_frmmeta *)(skb->cb);
frmmeta->magic = P80211_FRMMETA_MAGIC;
frmmeta->rx = rxmeta;
exit:
return result;
}
void p80211skb_free(struct wlandevice *wlandev, struct sk_buff *skb)
{
struct p80211_frmmeta *meta;
meta = P80211SKB_FRMMETA(skb);
if (meta && meta->rx)
p80211skb_rxmeta_detach(skb);
else
netdev_err(wlandev->netdev,
"Freeing an skb (%p) w/ no frmmeta.\n", skb);
dev_kfree_skb(skb);
}
