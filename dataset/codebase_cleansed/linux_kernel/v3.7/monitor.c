int
uf_start_sniff(unifi_priv_t *priv)
{
ul_client_t *pcli = priv->wext_client;
CSR_SIGNAL signal;
CSR_MLME_SNIFFJOIN_REQUEST *req = &signal.u.MlmeSniffjoinRequest;
int timeout = 1000;
int r;
req->Ifindex = priv->if_index;
req->Channel = priv->wext_conf.channel;
req->ChannelStartingFactor = 0;
signal.SignalPrimitiveHeader.SignalId = CSR_MLME_SNIFFJOIN_REQUEST_ID;
r = unifi_mlme_blocking_request(priv, pcli, &signal, NULL, timeout);
if (r < 0) {
unifi_error(priv, "failed to send SNIFFJOIN request, error %d\n", r);
return r;
}
r = pcli->reply_signal->u.MlmeSniffjoinConfirm.Resultcode;
if (r) {
unifi_notice(priv, "SNIFFJOIN request was rejected with result 0x%X (%s)\n",
r, lookup_result_code(r));
return -EIO;
}
return 0;
}
static void
netrx_radiotap(unifi_priv_t *priv,
const CSR_MA_SNIFFDATA_INDICATION *ind,
struct sk_buff *skb_orig)
{
struct net_device *dev = priv->netdev;
struct sk_buff *skb = NULL;
unsigned char *ptr;
unsigned char *base;
int ind_data_len = skb_orig->len - 2 - ETH_HLEN;
struct unifi_rx_radiotap_header {
struct ieee80211_radiotap_header rt_hdr;
u64 rt_tsft;
u8 rt_flags;
u8 rt_rate;
u16 rt_chan;
u16 rt_chan_flags;
u8 rt_dbm_antsignal;
u8 rt_dbm_antnoise;
u8 rt_antenna;
u8 pad[3];
} __attribute__((__packed__));
struct unifi_rx_radiotap_header *unifi_rt;
int signal, noise, snr;
func_enter();
if (ind_data_len <= 0) {
unifi_error(priv, "Invalid length in CSR_MA_SNIFFDATA_INDICATION.\n");
return;
}
skb = dev_alloc_skb(ind_data_len + sizeof(struct unifi_rx_radiotap_header) + 4);
if (! skb) {
unifi_error(priv, "alloc_skb failed.\n");
priv->stats.rx_errors++;
return;
}
base = skb->data;
unifi_rt = (struct unifi_rx_radiotap_header *)
skb_put(skb, sizeof(struct unifi_rx_radiotap_header));
ptr = skb_put(skb, ind_data_len);
memcpy(ptr, skb_orig->data, ind_data_len);
unifi_rt->rt_hdr.it_version = PKTHDR_RADIOTAP_VERSION;
unifi_rt->rt_hdr.it_pad = 0;
unifi_rt->rt_hdr.it_len = sizeof(struct unifi_rx_radiotap_header);
unifi_rt->rt_hdr.it_present = 0
| (1 << IEEE80211_RADIOTAP_TSFT)
| (1 << IEEE80211_RADIOTAP_FLAGS)
| (1 << IEEE80211_RADIOTAP_RATE)
| (1 << IEEE80211_RADIOTAP_CHANNEL)
| (1 << IEEE80211_RADIOTAP_DBM_ANTSIGNAL)
| (1 << IEEE80211_RADIOTAP_DBM_ANTNOISE)
| (1 << IEEE80211_RADIOTAP_ANTENNA)
;
unifi_rt->rt_tsft = (((u64)ind->Timestamp.x[7]) | (((u64)ind->Timestamp.x[6]) << 8) |
(((u64)ind->Timestamp.x[5]) << 16) | (((u64)ind->Timestamp.x[4]) << 24) |
(((u64)ind->Timestamp.x[3]) << 32) | (((u64)ind->Timestamp.x[2]) << 40) |
(((u64)ind->Timestamp.x[1]) << 48) | (((u64)ind->Timestamp.x[0]) << 56));
unifi_rt->rt_flags = 0;
unifi_rt->rt_rate = ind->Rate;
unifi_rt->rt_chan = cpu_to_le16(ieee80211chan2mhz(priv->wext_conf.channel));
unifi_rt->rt_chan_flags = 0;
signal = (s16)unifi2host_16(ind->Rssi);
snr = (s16)unifi2host_16(ind->Snr);
noise = signal - snr;
unifi_rt->rt_dbm_antsignal = signal;
unifi_rt->rt_dbm_antnoise = noise;
unifi_rt->rt_antenna = ind->AntennaId;
skb->dev = dev;
skb->mac_header = skb->data;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = __constant_htons(ETH_P_80211_RAW);
memset(skb->cb, 0, sizeof(skb->cb));
netif_rx_ni(skb);
dev->last_rx = jiffies;
priv->stats.rx_packets++;
priv->stats.rx_bytes += ind_data_len;
func_exit();
}
static void
netrx_prism(unifi_priv_t *priv,
const CSR_MA_SNIFFDATA_INDICATION *ind,
struct sk_buff *skb_orig)
{
struct net_device *dev = priv->netdev;
struct sk_buff *skb = NULL;
unsigned char *ptr;
unsigned char *base;
int ind_data_len = skb_orig->len - 2 - ETH_HLEN;
#define WLANCAP_MAGIC_COOKIE_V1 0x80211001
struct avs_header_v1 {
uint32 version;
uint32 length;
uint64 mactime;
uint64 hosttime;
uint32 phytype;
uint32 channel;
uint32 datarate;
uint32 antenna;
uint32 priority;
uint32 ssi_type;
int32 ssi_signal;
int32 ssi_noise;
uint32 preamble;
uint32 encoding;
} *avs;
int signal, noise, snr;
func_enter();
if (ind_data_len <= 0) {
unifi_error(priv, "Invalid length in CSR_MA_SNIFFDATA_INDICATION.\n");
return;
}
skb = dev_alloc_skb(ind_data_len + sizeof(struct avs_header_v1) + 4);
if (! skb) {
unifi_error(priv, "alloc_skb failed.\n");
priv->stats.rx_errors++;
return;
}
base = skb->data;
avs = (struct avs_header_v1 *)skb_put(skb, sizeof(struct avs_header_v1));
ptr = skb_put(skb, ind_data_len);
memcpy(ptr, skb_orig->data, ind_data_len);
signal = 0x10000 - ((s16)unifi2host_16(ind->Rssi));
snr = (s16)unifi2host_16(ind->Snr);
noise = signal - snr;
avs->version = htonl(WLANCAP_MAGIC_COOKIE_V1);
avs->length = htonl(sizeof(struct avs_header_v1));
avs->mactime = __cpu_to_be64(ind->Timestamp);
avs->hosttime = __cpu_to_be64(jiffies);
avs->phytype = htonl(9);
avs->channel = htonl(priv->wext_conf.channel);
avs->datarate = htonl(ind->Rate * 5);
avs->antenna = htonl(ind->Antenna);
avs->priority = htonl(0);
avs->ssi_type = htonl(2);
avs->ssi_signal = htonl(signal);
avs->ssi_noise = htonl(noise);
avs->preamble = htonl(0);
avs->encoding = htonl(0);
skb->dev = dev;
skb->mac.raw = skb->data;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = __constant_htons(ETH_P_80211_RAW);
memset(skb->cb, 0, sizeof(skb->cb));
netif_rx_ni(skb);
dev->last_rx = jiffies;
priv->stats.rx_packets++;
priv->stats.rx_bytes += ind_data_len;
func_exit();
}
void
ma_sniffdata_ind(void *ospriv,
const CSR_MA_SNIFFDATA_INDICATION *ind,
const bulk_data_param_t *bulkdata)
{
unifi_priv_t *priv = ospriv;
struct net_device *dev = priv->netdev;
struct sk_buff *skb = (struct sk_buff*)bulkdata->d[0].os_net_buf_ptr;
func_enter();
if (bulkdata->d[0].data_length == 0) {
unifi_warning(priv, "rx: MA-SNIFFDATA indication with zero bulk data\n");
func_exit();
return;
}
skb->len = bulkdata->d[0].data_length;
if (unlikely(!netif_running(dev))) {
priv->stats.rx_dropped++;
priv->wext_conf.wireless_stats.discard.misc++;
dev_kfree_skb(skb);
return;
}
if (ind->ReceptionStatus) {
priv->stats.rx_dropped++;
priv->wext_conf.wireless_stats.discard.misc++;
printk(KERN_INFO "unifi: Dropping corrupt sniff packet\n");
dev_kfree_skb(skb);
return;
}
#if (UNIFI_SNIFF_ARPHRD == ARPHRD_IEEE80211_PRISM)
netrx_prism(priv, ind, skb);
#endif
#if (UNIFI_SNIFF_ARPHRD == ARPHRD_IEEE80211_RADIOTAP)
netrx_radiotap(priv, ind, skb);
#endif
dev_kfree_skb(skb);
}
