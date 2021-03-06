void dhd_common_init(void)
{
dhd_msg_level = DHD_ERROR_VAL;
#ifdef CONFIG_BCM4329_FW_PATH
strncpy(fw_path, CONFIG_BCM4329_FW_PATH, MOD_PARAM_PATHLEN - 1);
#else
fw_path[0] = '\0';
#endif
#ifdef CONFIG_BCM4329_NVRAM_PATH
strncpy(nv_path, CONFIG_BCM4329_NVRAM_PATH, MOD_PARAM_PATHLEN - 1);
#else
nv_path[0] = '\0';
#endif
}
static int dhd_dump(dhd_pub_t *dhdp, char *buf, int buflen)
{
struct bcmstrbuf b;
struct bcmstrbuf *strbuf = &b;
bcm_binit(strbuf, buf, buflen);
bcm_bprintf(strbuf, "%s\n", dhd_version);
bcm_bprintf(strbuf, "\n");
bcm_bprintf(strbuf, "pub.up %d pub.txoff %d pub.busstate %d\n",
dhdp->up, dhdp->txoff, dhdp->busstate);
bcm_bprintf(strbuf, "pub.hdrlen %d pub.maxctl %d pub.rxsz %d\n",
dhdp->hdrlen, dhdp->maxctl, dhdp->rxsz);
bcm_bprintf(strbuf, "pub.iswl %d pub.drv_version %ld pub.mac %pM\n",
dhdp->iswl, dhdp->drv_version, &dhdp->mac);
bcm_bprintf(strbuf, "pub.bcmerror %d tickcnt %d\n", dhdp->bcmerror,
dhdp->tickcnt);
bcm_bprintf(strbuf, "dongle stats:\n");
bcm_bprintf(strbuf,
"tx_packets %ld tx_bytes %ld tx_errors %ld tx_dropped %ld\n",
dhdp->dstats.tx_packets, dhdp->dstats.tx_bytes,
dhdp->dstats.tx_errors, dhdp->dstats.tx_dropped);
bcm_bprintf(strbuf,
"rx_packets %ld rx_bytes %ld rx_errors %ld rx_dropped %ld\n",
dhdp->dstats.rx_packets, dhdp->dstats.rx_bytes,
dhdp->dstats.rx_errors, dhdp->dstats.rx_dropped);
bcm_bprintf(strbuf, "multicast %ld\n", dhdp->dstats.multicast);
bcm_bprintf(strbuf, "bus stats:\n");
bcm_bprintf(strbuf, "tx_packets %ld tx_multicast %ld tx_errors %ld\n",
dhdp->tx_packets, dhdp->tx_multicast, dhdp->tx_errors);
bcm_bprintf(strbuf, "tx_ctlpkts %ld tx_ctlerrs %ld\n",
dhdp->tx_ctlpkts, dhdp->tx_ctlerrs);
bcm_bprintf(strbuf, "rx_packets %ld rx_multicast %ld rx_errors %ld\n",
dhdp->rx_packets, dhdp->rx_multicast, dhdp->rx_errors);
bcm_bprintf(strbuf,
"rx_ctlpkts %ld rx_ctlerrs %ld rx_dropped %ld rx_flushed %ld\n",
dhdp->rx_ctlpkts, dhdp->rx_ctlerrs, dhdp->rx_dropped,
dhdp->rx_flushed);
bcm_bprintf(strbuf,
"rx_readahead_cnt %ld tx_realloc %ld fc_packets %ld\n",
dhdp->rx_readahead_cnt, dhdp->tx_realloc, dhdp->fc_packets);
bcm_bprintf(strbuf, "wd_dpc_sched %ld\n", dhdp->wd_dpc_sched);
bcm_bprintf(strbuf, "\n");
dhd_prot_dump(dhdp, strbuf);
bcm_bprintf(strbuf, "\n");
dhd_bus_dump(dhdp, strbuf);
return !strbuf->size ? -EOVERFLOW : 0;
}
static int
dhd_doiovar(dhd_pub_t *dhd_pub, const bcm_iovar_t *vi, u32 actionid,
const char *name, void *params, int plen, void *arg, int len,
int val_size)
{
int bcmerror = 0;
s32 int_val = 0;
DHD_TRACE(("%s: Enter\n", __func__));
bcmerror = bcm_iovar_lencheck(vi, arg, len, IOV_ISSET(actionid));
if (bcmerror != 0)
goto exit;
if (plen >= (int)sizeof(int_val))
memcpy(&int_val, params, sizeof(int_val));
switch (actionid) {
case IOV_GVAL(IOV_VERSION):
strncpy((char *)arg, dhd_version, len);
break;
case IOV_GVAL(IOV_MSGLEVEL):
int_val = (s32) dhd_msg_level;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_MSGLEVEL):
dhd_msg_level = int_val;
break;
case IOV_GVAL(IOV_BCMERRORSTR):
strncpy((char *)arg, "bcm_error",
BCME_STRLEN);
((char *)arg)[BCME_STRLEN - 1] = 0x00;
break;
case IOV_GVAL(IOV_BCMERROR):
int_val = (s32) dhd_pub->bcmerror;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_WDTICK):
int_val = (s32) dhd_watchdog_ms;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_WDTICK):
if (!dhd_pub->up) {
bcmerror = -ENOLINK;
break;
}
dhd_os_wd_timer(dhd_pub, (uint) int_val);
break;
case IOV_GVAL(IOV_DUMP):
bcmerror = dhd_dump(dhd_pub, arg, len);
break;
#ifdef DHD_DEBUG
case IOV_GVAL(IOV_DCONSOLE_POLL):
int_val = (s32) dhd_console_ms;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_DCONSOLE_POLL):
dhd_console_ms = (uint) int_val;
break;
case IOV_SVAL(IOV_CONS):
if (len > 0)
bcmerror = dhd_bus_console_in(dhd_pub, arg, len - 1);
break;
#endif
case IOV_SVAL(IOV_CLEARCOUNTS):
dhd_pub->tx_packets = dhd_pub->rx_packets = 0;
dhd_pub->tx_errors = dhd_pub->rx_errors = 0;
dhd_pub->tx_ctlpkts = dhd_pub->rx_ctlpkts = 0;
dhd_pub->tx_ctlerrs = dhd_pub->rx_ctlerrs = 0;
dhd_pub->rx_dropped = 0;
dhd_pub->rx_readahead_cnt = 0;
dhd_pub->tx_realloc = 0;
dhd_pub->wd_dpc_sched = 0;
memset(&dhd_pub->dstats, 0, sizeof(dhd_pub->dstats));
dhd_bus_clearcounts(dhd_pub);
break;
case IOV_GVAL(IOV_IOCTLTIMEOUT):{
int_val = (s32) dhd_os_get_ioctl_resp_timeout();
memcpy(arg, &int_val, sizeof(int_val));
break;
}
case IOV_SVAL(IOV_IOCTLTIMEOUT):{
if (int_val <= 0)
bcmerror = -EINVAL;
else
dhd_os_set_ioctl_resp_timeout((unsigned int)
int_val);
break;
}
default:
bcmerror = -ENOTSUPP;
break;
}
exit:
return bcmerror;
}
bool dhd_prec_enq(dhd_pub_t *dhdp, struct pktq *q, struct sk_buff *pkt,
int prec)
{
struct sk_buff *p;
int eprec = -1;
bool discard_oldest;
if (!pktq_pfull(q, prec) && !pktq_full(q)) {
bcm_pktq_penq(q, prec, pkt);
return true;
}
if (pktq_pfull(q, prec))
eprec = prec;
else if (pktq_full(q)) {
p = bcm_pktq_peek_tail(q, &eprec);
ASSERT(p);
if (eprec > prec)
return false;
}
if (eprec >= 0) {
ASSERT(!pktq_pempty(q, eprec));
discard_oldest = AC_BITMAP_TST(dhdp->wme_dp, eprec);
if (eprec == prec && !discard_oldest)
return false;
p = discard_oldest ? bcm_pktq_pdeq(q, eprec) :
bcm_pktq_pdeq_tail(q, eprec);
if (p == NULL) {
DHD_ERROR(("%s: bcm_pktq_penq() failed, oldest %d.",
__func__, discard_oldest));
ASSERT(p);
}
bcm_pkt_buf_free_skb(p);
}
p = bcm_pktq_penq(q, prec, pkt);
if (p == NULL) {
DHD_ERROR(("%s: bcm_pktq_penq() failed.", __func__));
ASSERT(p);
}
return true;
}
static int
dhd_iovar_op(dhd_pub_t *dhd_pub, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
int bcmerror = 0;
int val_size;
const bcm_iovar_t *vi = NULL;
u32 actionid;
DHD_TRACE(("%s: Enter\n", __func__));
ASSERT(name);
ASSERT(len >= 0);
ASSERT(set || (arg && len));
ASSERT(!set || (!params && !plen));
vi = bcm_iovar_lookup(dhd_iovars, name);
if (vi == NULL) {
bcmerror = -ENOTSUPP;
goto exit;
}
DHD_CTL(("%s: %s %s, len %d plen %d\n", __func__,
name, (set ? "set" : "get"), len, plen));
if (params == NULL) {
params = arg;
plen = len;
}
if (vi->type == IOVT_VOID)
val_size = 0;
else if (vi->type == IOVT_BUFFER)
val_size = len;
else
val_size = sizeof(int);
actionid = set ? IOV_SVAL(vi->varid) : IOV_GVAL(vi->varid);
bcmerror =
dhd_doiovar(dhd_pub, vi, actionid, name, params, plen, arg, len,
val_size);
exit:
return bcmerror;
}
int dhd_ioctl(dhd_pub_t *dhd_pub, dhd_ioctl_t *ioc, void *buf, uint buflen)
{
int bcmerror = 0;
DHD_TRACE(("%s: Enter\n", __func__));
if (!buf)
return -EINVAL;
switch (ioc->cmd) {
case DHD_GET_MAGIC:
if (buflen < sizeof(int))
bcmerror = -EOVERFLOW;
else
*(int *)buf = DHD_IOCTL_MAGIC;
break;
case DHD_GET_VERSION:
if (buflen < sizeof(int))
bcmerror = -EOVERFLOW;
else
*(int *)buf = DHD_IOCTL_VERSION;
break;
case DHD_GET_VAR:
case DHD_SET_VAR:{
char *arg;
uint arglen;
for (arg = buf, arglen = buflen; *arg && arglen;
arg++, arglen--)
;
if (*arg) {
bcmerror = -EOVERFLOW;
break;
}
arg++, arglen--;
if (ioc->cmd == DHD_GET_VAR)
bcmerror =
dhd_iovar_op(dhd_pub, buf, arg, arglen, buf,
buflen, IOV_GET);
else
bcmerror =
dhd_iovar_op(dhd_pub, buf, NULL, 0, arg,
arglen, IOV_SET);
if (bcmerror != -ENOTSUPP)
break;
if (ioc->cmd == DHD_GET_VAR)
bcmerror = dhd_prot_iovar_op(dhd_pub, buf, arg,
arglen, buf,
buflen, IOV_GET);
else
bcmerror = dhd_prot_iovar_op(dhd_pub, buf,
NULL, 0, arg,
arglen, IOV_SET);
if (bcmerror != -ENOTSUPP)
break;
if (ioc->cmd == DHD_GET_VAR)
bcmerror = dhd_bus_iovar_op(dhd_pub, buf,
arg, arglen, buf,
buflen, IOV_GET);
else
bcmerror = dhd_bus_iovar_op(dhd_pub, buf,
NULL, 0, arg,
arglen, IOV_SET);
break;
}
default:
bcmerror = -ENOTSUPP;
}
return bcmerror;
}
static void wl_show_host_event(wl_event_msg_t *event, void *event_data)
{
uint i, status, reason;
bool group = false, flush_txq = false, link = false;
char *auth_str, *event_name;
unsigned char *buf;
char err_msg[256], eabuf[ETHER_ADDR_STR_LEN];
static struct {
uint event;
char *event_name;
} event_names[] = {
{
WLC_E_SET_SSID, "SET_SSID"}, {
WLC_E_JOIN, "JOIN"}, {
WLC_E_START, "START"}, {
WLC_E_AUTH, "AUTH"}, {
WLC_E_AUTH_IND, "AUTH_IND"}, {
WLC_E_DEAUTH, "DEAUTH"}, {
WLC_E_DEAUTH_IND, "DEAUTH_IND"}, {
WLC_E_ASSOC, "ASSOC"}, {
WLC_E_ASSOC_IND, "ASSOC_IND"}, {
WLC_E_REASSOC, "REASSOC"}, {
WLC_E_REASSOC_IND, "REASSOC_IND"}, {
WLC_E_DISASSOC, "DISASSOC"}, {
WLC_E_DISASSOC_IND, "DISASSOC_IND"}, {
WLC_E_QUIET_START, "START_QUIET"}, {
WLC_E_QUIET_END, "END_QUIET"}, {
WLC_E_BEACON_RX, "BEACON_RX"}, {
WLC_E_LINK, "LINK"}, {
WLC_E_MIC_ERROR, "MIC_ERROR"}, {
WLC_E_NDIS_LINK, "NDIS_LINK"}, {
WLC_E_ROAM, "ROAM"}, {
WLC_E_TXFAIL, "TXFAIL"}, {
WLC_E_PMKID_CACHE, "PMKID_CACHE"}, {
WLC_E_RETROGRADE_TSF, "RETROGRADE_TSF"}, {
WLC_E_PRUNE, "PRUNE"}, {
WLC_E_AUTOAUTH, "AUTOAUTH"}, {
WLC_E_EAPOL_MSG, "EAPOL_MSG"}, {
WLC_E_SCAN_COMPLETE, "SCAN_COMPLETE"}, {
WLC_E_ADDTS_IND, "ADDTS_IND"}, {
WLC_E_DELTS_IND, "DELTS_IND"}, {
WLC_E_BCNSENT_IND, "BCNSENT_IND"}, {
WLC_E_BCNRX_MSG, "BCNRX_MSG"}, {
WLC_E_BCNLOST_MSG, "BCNLOST_MSG"}, {
WLC_E_ROAM_PREP, "ROAM_PREP"}, {
WLC_E_PFN_NET_FOUND, "PNO_NET_FOUND"}, {
WLC_E_PFN_NET_LOST, "PNO_NET_LOST"}, {
WLC_E_RESET_COMPLETE, "RESET_COMPLETE"}, {
WLC_E_JOIN_START, "JOIN_START"}, {
WLC_E_ROAM_START, "ROAM_START"}, {
WLC_E_ASSOC_START, "ASSOC_START"}, {
WLC_E_IBSS_ASSOC, "IBSS_ASSOC"}, {
WLC_E_RADIO, "RADIO"}, {
WLC_E_PSM_WATCHDOG, "PSM_WATCHDOG"}, {
WLC_E_PROBREQ_MSG, "PROBREQ_MSG"}, {
WLC_E_SCAN_CONFIRM_IND, "SCAN_CONFIRM_IND"}, {
WLC_E_PSK_SUP, "PSK_SUP"}, {
WLC_E_COUNTRY_CODE_CHANGED, "COUNTRY_CODE_CHANGED"}, {
WLC_E_EXCEEDED_MEDIUM_TIME, "EXCEEDED_MEDIUM_TIME"}, {
WLC_E_ICV_ERROR, "ICV_ERROR"}, {
WLC_E_UNICAST_DECODE_ERROR, "UNICAST_DECODE_ERROR"}, {
WLC_E_MULTICAST_DECODE_ERROR, "MULTICAST_DECODE_ERROR"}, {
WLC_E_TRACE, "TRACE"}, {
WLC_E_ACTION_FRAME, "ACTION FRAME"}, {
WLC_E_ACTION_FRAME_COMPLETE, "ACTION FRAME TX COMPLETE"}, {
WLC_E_IF, "IF"}, {
WLC_E_RSSI, "RSSI"}, {
WLC_E_PFN_SCAN_COMPLETE, "SCAN_COMPLETE"}
};
uint event_type, flags, auth_type, datalen;
event_type = be32_to_cpu(event->event_type);
flags = be16_to_cpu(event->flags);
status = be32_to_cpu(event->status);
reason = be32_to_cpu(event->reason);
auth_type = be32_to_cpu(event->auth_type);
datalen = be32_to_cpu(event->datalen);
sprintf(eabuf, "%pM", event->addr);
event_name = "UNKNOWN";
for (i = 0; i < ARRAY_SIZE(event_names); i++) {
if (event_names[i].event == event_type)
event_name = event_names[i].event_name;
}
DHD_EVENT(("EVENT: %s, event ID = %d\n", event_name, event_type));
DHD_EVENT(("flags 0x%04x, status %d, reason %d, auth_type %d MAC %s\n",
flags, status, reason, auth_type, eabuf));
if (flags & WLC_EVENT_MSG_LINK)
link = true;
if (flags & WLC_EVENT_MSG_GROUP)
group = true;
if (flags & WLC_EVENT_MSG_FLUSHTXQ)
flush_txq = true;
switch (event_type) {
case WLC_E_START:
case WLC_E_DEAUTH:
case WLC_E_DISASSOC:
DHD_EVENT(("MACEVENT: %s, MAC %s\n", event_name, eabuf));
break;
case WLC_E_ASSOC_IND:
case WLC_E_REASSOC_IND:
DHD_EVENT(("MACEVENT: %s, MAC %s\n", event_name, eabuf));
break;
case WLC_E_ASSOC:
case WLC_E_REASSOC:
if (status == WLC_E_STATUS_SUCCESS) {
DHD_EVENT(("MACEVENT: %s, MAC %s, SUCCESS\n",
event_name, eabuf));
} else if (status == WLC_E_STATUS_TIMEOUT) {
DHD_EVENT(("MACEVENT: %s, MAC %s, TIMEOUT\n",
event_name, eabuf));
} else if (status == WLC_E_STATUS_FAIL) {
DHD_EVENT(("MACEVENT: %s, MAC %s, FAILURE, reason %d\n",
event_name, eabuf, (int)reason));
} else {
DHD_EVENT(("MACEVENT: %s, MAC %s, unexpected status "
"%d\n", event_name, eabuf, (int)status));
}
break;
case WLC_E_DEAUTH_IND:
case WLC_E_DISASSOC_IND:
DHD_EVENT(("MACEVENT: %s, MAC %s, reason %d\n", event_name,
eabuf, (int)reason));
break;
case WLC_E_AUTH:
case WLC_E_AUTH_IND:
if (auth_type == WLAN_AUTH_OPEN)
auth_str = "Open System";
else if (auth_type == WLAN_AUTH_SHARED_KEY)
auth_str = "Shared Key";
else {
sprintf(err_msg, "AUTH unknown: %d", (int)auth_type);
auth_str = err_msg;
}
if (event_type == WLC_E_AUTH_IND) {
DHD_EVENT(("MACEVENT: %s, MAC %s, %s\n", event_name,
eabuf, auth_str));
} else if (status == WLC_E_STATUS_SUCCESS) {
DHD_EVENT(("MACEVENT: %s, MAC %s, %s, SUCCESS\n",
event_name, eabuf, auth_str));
} else if (status == WLC_E_STATUS_TIMEOUT) {
DHD_EVENT(("MACEVENT: %s, MAC %s, %s, TIMEOUT\n",
event_name, eabuf, auth_str));
} else if (status == WLC_E_STATUS_FAIL) {
DHD_EVENT(("MACEVENT: %s, MAC %s, %s, FAILURE, "
"reason %d\n",
event_name, eabuf, auth_str, (int)reason));
}
break;
case WLC_E_JOIN:
case WLC_E_ROAM:
case WLC_E_SET_SSID:
if (status == WLC_E_STATUS_SUCCESS) {
DHD_EVENT(("MACEVENT: %s, MAC %s\n", event_name,
eabuf));
} else if (status == WLC_E_STATUS_FAIL) {
DHD_EVENT(("MACEVENT: %s, failed\n", event_name));
} else if (status == WLC_E_STATUS_NO_NETWORKS) {
DHD_EVENT(("MACEVENT: %s, no networks found\n",
event_name));
} else {
DHD_EVENT(("MACEVENT: %s, unexpected status %d\n",
event_name, (int)status));
}
break;
case WLC_E_BEACON_RX:
if (status == WLC_E_STATUS_SUCCESS) {
DHD_EVENT(("MACEVENT: %s, SUCCESS\n", event_name));
} else if (status == WLC_E_STATUS_FAIL) {
DHD_EVENT(("MACEVENT: %s, FAIL\n", event_name));
} else {
DHD_EVENT(("MACEVENT: %s, status %d\n", event_name,
status));
}
break;
case WLC_E_LINK:
DHD_EVENT(("MACEVENT: %s %s\n", event_name,
link ? "UP" : "DOWN"));
break;
case WLC_E_MIC_ERROR:
DHD_EVENT(("MACEVENT: %s, MAC %s, Group %d, Flush %d\n",
event_name, eabuf, group, flush_txq));
break;
case WLC_E_ICV_ERROR:
case WLC_E_UNICAST_DECODE_ERROR:
case WLC_E_MULTICAST_DECODE_ERROR:
DHD_EVENT(("MACEVENT: %s, MAC %s\n", event_name, eabuf));
break;
case WLC_E_TXFAIL:
DHD_EVENT(("MACEVENT: %s, RA %s\n", event_name, eabuf));
break;
case WLC_E_SCAN_COMPLETE:
case WLC_E_PMKID_CACHE:
DHD_EVENT(("MACEVENT: %s\n", event_name));
break;
case WLC_E_PFN_NET_FOUND:
case WLC_E_PFN_NET_LOST:
case WLC_E_PFN_SCAN_COMPLETE:
DHD_EVENT(("PNOEVENT: %s\n", event_name));
break;
case WLC_E_PSK_SUP:
case WLC_E_PRUNE:
DHD_EVENT(("MACEVENT: %s, status %d, reason %d\n",
event_name, (int)status, (int)reason));
break;
case WLC_E_TRACE:
{
static u32 seqnum_prev;
msgtrace_hdr_t hdr;
u32 nblost;
char *s, *p;
buf = (unsigned char *) event_data;
memcpy(&hdr, buf, MSGTRACE_HDRLEN);
if (hdr.version != MSGTRACE_VERSION) {
DHD_ERROR(
("\nMACEVENT: %s [unsupported version --> "
"dhd version:%d dongle version:%d]\n",
event_name, MSGTRACE_VERSION, hdr.version)
);
datalen = 0;
break;
}
buf[MSGTRACE_HDRLEN + be16_to_cpu(hdr.len)] = '\0';
if (be32_to_cpu(hdr.discarded_bytes)
|| be32_to_cpu(hdr.discarded_printf)) {
DHD_ERROR(
("\nWLC_E_TRACE: [Discarded traces in dongle -->"
"discarded_bytes %d discarded_printf %d]\n",
be32_to_cpu(hdr.discarded_bytes),
be32_to_cpu(hdr.discarded_printf)));
}
nblost = be32_to_cpu(hdr.seqnum) - seqnum_prev - 1;
if (nblost > 0) {
DHD_ERROR(
("\nWLC_E_TRACE: [Event lost --> seqnum %d nblost %d\n",
be32_to_cpu(hdr.seqnum), nblost));
}
seqnum_prev = be32_to_cpu(hdr.seqnum);
p = (char *)&buf[MSGTRACE_HDRLEN];
while ((s = strstr(p, "\n")) != NULL) {
*s = '\0';
printk(KERN_DEBUG"%s\n", p);
p = s + 1;
}
printk(KERN_DEBUG "%s\n", p);
datalen = 0;
}
break;
case WLC_E_RSSI:
DHD_EVENT(("MACEVENT: %s %d\n", event_name,
be32_to_cpu(*((int *)event_data))));
break;
default:
DHD_EVENT(("MACEVENT: %s %d, MAC %s, status %d, reason %d, "
"auth %d\n", event_name, event_type, eabuf,
(int)status, (int)reason, (int)auth_type));
break;
}
if (datalen) {
buf = (unsigned char *) event_data;
DHD_EVENT((" data (%d) : ", datalen));
for (i = 0; i < datalen; i++)
DHD_EVENT((" 0x%02x ", *buf++));
DHD_EVENT(("\n"));
}
}
int
wl_host_event(struct dhd_info *dhd, int *ifidx, void *pktdata,
wl_event_msg_t *event, void **data_ptr)
{
bcm_event_t *pvt_data = (bcm_event_t *) pktdata;
char *event_data;
u32 type, status;
u16 flags;
int evlen;
if (memcmp(BRCM_OUI, &pvt_data->bcm_hdr.oui[0], DOT11_OUI_LEN)) {
DHD_ERROR(("%s: mismatched OUI, bailing\n", __func__));
return -EBADE;
}
if (get_unaligned_be16(&pvt_data->bcm_hdr.usr_subtype) !=
BCMILCP_BCM_SUBTYPE_EVENT) {
DHD_ERROR(("%s: mismatched subtype, bailing\n", __func__));
return -EBADE;
}
*data_ptr = &pvt_data[1];
event_data = *data_ptr;
memcpy(event, &pvt_data->event, sizeof(wl_event_msg_t));
type = get_unaligned_be32(&event->event_type);
flags = get_unaligned_be16(&event->flags);
status = get_unaligned_be32(&event->status);
evlen = get_unaligned_be32(&event->datalen) + sizeof(bcm_event_t);
switch (type) {
case WLC_E_IF:
{
dhd_if_event_t *ifevent = (dhd_if_event_t *) event_data;
DHD_TRACE(("%s: if event\n", __func__));
if (ifevent->ifidx > 0 &&
ifevent->ifidx < DHD_MAX_IFS) {
if (ifevent->action == WLC_E_IF_ADD)
dhd_add_if(dhd, ifevent->ifidx,
NULL, event->ifname,
pvt_data->eth.h_dest,
ifevent->flags,
ifevent->bssidx);
else
dhd_del_if(dhd, ifevent->ifidx);
} else {
DHD_ERROR(("%s: Invalid ifidx %d for %s\n",
__func__, ifevent->ifidx,
event->ifname));
}
}
*ifidx = dhd_ifname2idx(dhd, event->ifname);
dhd_event(dhd, (char *)pvt_data, evlen, *ifidx);
break;
#ifdef P2P
case WLC_E_NDIS_LINK:
break;
#endif
case WLC_E_LINK:
case WLC_E_ASSOC_IND:
case WLC_E_REASSOC_IND:
case WLC_E_DISASSOC_IND:
case WLC_E_MIC_ERROR:
default:
*ifidx = dhd_ifname2idx(dhd, event->ifname);
dhd_event(dhd, (char *)pvt_data, evlen, *ifidx);
DHD_TRACE(("%s: MAC event %d, flags %x, status %x\n",
__func__, type, flags, status));
if (type == WLC_E_NDIS_LINK) {
u32 temp;
temp = get_unaligned_be32(&event->event_type);
DHD_TRACE(("Converted to WLC_E_LINK type %d\n", temp));
temp = be32_to_cpu(WLC_E_NDIS_LINK);
memcpy((void *)(&pvt_data->event.event_type), &temp,
sizeof(pvt_data->event.event_type));
}
break;
}
#ifdef SHOW_EVENTS
wl_show_host_event(event, event_data);
#endif
return 0;
}
static int wl_pattern_atoh(char *src, char *dst)
{
int i;
if (strncmp(src, "0x", 2) != 0 && strncmp(src, "0X", 2) != 0) {
DHD_ERROR(("Mask invalid format. Needs to start with 0x\n"));
return -1;
}
src = src + 2;
if (strlen(src) % 2 != 0) {
DHD_ERROR(("Mask invalid format. Length must be even.\n"));
return -1;
}
for (i = 0; *src != '\0'; i++) {
char num[3];
strncpy(num, src, 2);
num[2] = '\0';
dst[i] = (u8) simple_strtoul(num, NULL, 16);
src += 2;
}
return i;
}
void
dhd_pktfilter_offload_enable(dhd_pub_t *dhd, char *arg, int enable,
int master_mode)
{
char *argv[8];
int i = 0;
const char *str;
int buf_len;
int str_len;
char *arg_save = 0, *arg_org = 0;
int rc;
char buf[128];
wl_pkt_filter_enable_t enable_parm;
wl_pkt_filter_enable_t *pkt_filterp;
arg_save = kmalloc(strlen(arg) + 1, GFP_ATOMIC);
if (!arg_save) {
DHD_ERROR(("%s: kmalloc failed\n", __func__));
goto fail;
}
arg_org = arg_save;
memcpy(arg_save, arg, strlen(arg) + 1);
argv[i] = strsep(&arg_save, " ");
i = 0;
if (NULL == argv[i]) {
DHD_ERROR(("No args provided\n"));
goto fail;
}
str = "pkt_filter_enable";
str_len = strlen(str);
strncpy(buf, str, str_len);
buf[str_len] = '\0';
buf_len = str_len + 1;
pkt_filterp = (wl_pkt_filter_enable_t *) (buf + str_len + 1);
enable_parm.id = simple_strtoul(argv[i], NULL, 0);
enable_parm.enable = enable;
buf_len += sizeof(enable_parm);
memcpy((char *)pkt_filterp, &enable_parm, sizeof(enable_parm));
rc = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, buf, buf_len);
rc = rc >= 0 ? 0 : rc;
if (rc)
DHD_TRACE(("%s: failed to add pktfilter %s, retcode = %d\n",
__func__, arg, rc));
else
DHD_TRACE(("%s: successfully added pktfilter %s\n",
__func__, arg));
bcm_mkiovar("pkt_filter_mode", (char *)&master_mode, 4, buf,
sizeof(buf));
rc = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, buf, sizeof(buf));
rc = rc >= 0 ? 0 : rc;
if (rc)
DHD_TRACE(("%s: failed to add pktfilter %s, retcode = %d\n",
__func__, arg, rc));
fail:
kfree(arg_org);
}
void dhd_pktfilter_offload_set(dhd_pub_t *dhd, char *arg)
{
const char *str;
wl_pkt_filter_t pkt_filter;
wl_pkt_filter_t *pkt_filterp;
int buf_len;
int str_len;
int rc;
u32 mask_size;
u32 pattern_size;
char *argv[8], *buf = 0;
int i = 0;
char *arg_save = 0, *arg_org = 0;
#define BUF_SIZE 2048
arg_save = kmalloc(strlen(arg) + 1, GFP_ATOMIC);
if (!arg_save) {
DHD_ERROR(("%s: kmalloc failed\n", __func__));
goto fail;
}
arg_org = arg_save;
buf = kmalloc(BUF_SIZE, GFP_ATOMIC);
if (!buf) {
DHD_ERROR(("%s: kmalloc failed\n", __func__));
goto fail;
}
memcpy(arg_save, arg, strlen(arg) + 1);
if (strlen(arg) > BUF_SIZE) {
DHD_ERROR(("Not enough buffer %d < %d\n", (int)strlen(arg),
(int)sizeof(buf)));
goto fail;
}
argv[i] = strsep(&arg_save, " ");
while (argv[i++])
argv[i] = strsep(&arg_save, " ");
i = 0;
if (NULL == argv[i]) {
DHD_ERROR(("No args provided\n"));
goto fail;
}
str = "pkt_filter_add";
str_len = strlen(str);
strncpy(buf, str, str_len);
buf[str_len] = '\0';
buf_len = str_len + 1;
pkt_filterp = (wl_pkt_filter_t *) (buf + str_len + 1);
pkt_filter.id = simple_strtoul(argv[i], NULL, 0);
if (NULL == argv[++i]) {
DHD_ERROR(("Polarity not provided\n"));
goto fail;
}
pkt_filter.negate_match = simple_strtoul(argv[i], NULL, 0);
if (NULL == argv[++i]) {
DHD_ERROR(("Filter type not provided\n"));
goto fail;
}
pkt_filter.type = simple_strtoul(argv[i], NULL, 0);
if (NULL == argv[++i]) {
DHD_ERROR(("Offset not provided\n"));
goto fail;
}
pkt_filter.u.pattern.offset = simple_strtoul(argv[i], NULL, 0);
if (NULL == argv[++i]) {
DHD_ERROR(("Bitmask not provided\n"));
goto fail;
}
mask_size =
wl_pattern_atoh
(argv[i], (char *)pkt_filterp->u.pattern.mask_and_pattern);
if (NULL == argv[++i]) {
DHD_ERROR(("Pattern not provided\n"));
goto fail;
}
pattern_size =
wl_pattern_atoh(argv[i],
(char *)&pkt_filterp->u.pattern.
mask_and_pattern[mask_size]);
if (mask_size != pattern_size) {
DHD_ERROR(("Mask and pattern not the same size\n"));
goto fail;
}
pkt_filter.u.pattern.size_bytes = mask_size;
buf_len += WL_PKT_FILTER_FIXED_LEN;
buf_len += (WL_PKT_FILTER_PATTERN_FIXED_LEN + 2 * mask_size);
memcpy((char *)pkt_filterp,
&pkt_filter,
WL_PKT_FILTER_FIXED_LEN + WL_PKT_FILTER_PATTERN_FIXED_LEN);
rc = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, buf, buf_len);
rc = rc >= 0 ? 0 : rc;
if (rc)
DHD_TRACE(("%s: failed to add pktfilter %s, retcode = %d\n",
__func__, arg, rc));
else
DHD_TRACE(("%s: successfully added pktfilter %s\n",
__func__, arg));
fail:
kfree(arg_org);
kfree(buf);
}
void dhd_arp_offload_set(dhd_pub_t *dhd, int arp_mode)
{
char iovbuf[32];
int retcode;
bcm_mkiovar("arp_ol", (char *)&arp_mode, 4, iovbuf, sizeof(iovbuf));
retcode = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
retcode = retcode >= 0 ? 0 : retcode;
if (retcode)
DHD_TRACE(("%s: failed to set ARP offload mode to 0x%x, "
"retcode = %d\n", __func__, arp_mode, retcode));
else
DHD_TRACE(("%s: successfully set ARP offload mode to 0x%x\n",
__func__, arp_mode));
}
void dhd_arp_offload_enable(dhd_pub_t *dhd, int arp_enable)
{
char iovbuf[32];
int retcode;
bcm_mkiovar("arpoe", (char *)&arp_enable, 4, iovbuf, sizeof(iovbuf));
retcode = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
retcode = retcode >= 0 ? 0 : retcode;
if (retcode)
DHD_TRACE(("%s: failed to enabe ARP offload to %d, "
"retcode = %d\n", __func__, arp_enable, retcode));
else
DHD_TRACE(("%s: successfully enabed ARP offload to %d\n",
__func__, arp_enable));
}
int dhd_preinit_ioctls(dhd_pub_t *dhd)
{
char iovbuf[WL_EVENTING_MASK_LEN + 12];
uint up = 0;
char buf[128], *ptr;
uint power_mode = PM_FAST;
u32 dongle_align = DHD_SDALIGN;
u32 glom = 0;
uint bcn_timeout = 3;
int scan_assoc_time = 40;
int scan_unassoc_time = 40;
#ifdef GET_CUSTOM_MAC_ENABLE
int ret = 0;
u8 ea_addr[ETH_ALEN];
#endif
dhd_os_proto_block(dhd);
#ifdef GET_CUSTOM_MAC_ENABLE
ret = dhd_custom_get_mac_address(ea_addr);
if (!ret) {
bcm_mkiovar("cur_etheraddr", (void *)ea_addr, ETH_ALEN,
buf, sizeof(buf));
ret = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, buf, sizeof(buf));
if (ret < 0) {
DHD_ERROR(("%s: can't set MAC address , error=%d\n",
__func__, ret));
} else
memcpy(dhd->mac.octet, (void *)&ea_addr,
ETH_ALEN);
}
#endif
if (dhd->country_code[0] != 0) {
if (dhdcdc_set_ioctl(dhd, 0, WLC_SET_COUNTRY,
dhd->country_code,
sizeof(dhd->country_code)) < 0) {
DHD_ERROR(("%s: country code setting failed\n",
__func__));
}
}
memset(buf, 0, sizeof(buf));
ptr = buf;
bcm_mkiovar("ver", 0, 0, buf, sizeof(buf));
dhdcdc_query_ioctl(dhd, 0, WLC_GET_VAR, buf, sizeof(buf));
strsep(&ptr, "\n");
DHD_ERROR(("Firmware version = %s\n", buf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_PM, (char *)&power_mode,
sizeof(power_mode));
bcm_mkiovar("bus:txglomalign", (char *)&dongle_align, 4, iovbuf,
sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
bcm_mkiovar("bus:txglom", (char *)&glom, 4, iovbuf, sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
bcm_mkiovar("bcn_timeout", (char *)&bcn_timeout, 4, iovbuf,
sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
bcm_mkiovar("roam_off", (char *)&dhd_roam, 4, iovbuf, sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (dhd_radio_up)
dhdcdc_set_ioctl(dhd, 0, WLC_UP, (char *)&up, sizeof(up));
bcm_mkiovar("event_msgs", dhd->eventmask, WL_EVENTING_MASK_LEN, iovbuf,
sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_SCAN_CHANNEL_TIME,
(char *)&scan_assoc_time, sizeof(scan_assoc_time));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_SCAN_UNASSOC_TIME,
(char *)&scan_unassoc_time, sizeof(scan_unassoc_time));
#ifdef ARP_OFFLOAD_SUPPORT
if (dhd_arp_enable)
dhd_arp_offload_set(dhd, dhd_arp_mode);
dhd_arp_offload_enable(dhd, dhd_arp_enable);
#endif
#ifdef PKT_FILTER_SUPPORT
{
int i;
if (dhd_pkt_filter_enable) {
for (i = 0; i < dhd->pktfilter_count; i++) {
dhd_pktfilter_offload_set(dhd,
dhd->pktfilter[i]);
dhd_pktfilter_offload_enable(dhd,
dhd->pktfilter[i],
dhd_pkt_filter_init,
dhd_master_mode);
}
}
}
#endif
dhd_os_proto_unblock(dhd);
return 0;
}
iscan_buf_t *dhd_iscan_allocate_buf(dhd_pub_t *dhd, iscan_buf_t **iscanbuf)
{
iscan_buf_t *iscanbuf_alloc = 0;
iscan_buf_t *iscanbuf_head;
dhd_iscan_lock();
iscanbuf_alloc = kmalloc(sizeof(iscan_buf_t), GFP_ATOMIC);
if (iscanbuf_alloc == NULL)
goto fail;
iscanbuf_alloc->next = NULL;
iscanbuf_head = *iscanbuf;
DHD_ISCAN(("%s: addr of allocated node = 0x%X"
"addr of iscanbuf_head = 0x%X dhd = 0x%X\n",
__func__, iscanbuf_alloc, iscanbuf_head, dhd));
if (iscanbuf_head == NULL) {
*iscanbuf = iscanbuf_alloc;
DHD_ISCAN(("%s: Head is allocated\n", __func__));
goto fail;
}
while (iscanbuf_head->next)
iscanbuf_head = iscanbuf_head->next;
iscanbuf_head->next = iscanbuf_alloc;
fail:
dhd_iscan_unlock();
return iscanbuf_alloc;
}
void dhd_iscan_free_buf(void *dhdp, iscan_buf_t *iscan_delete)
{
iscan_buf_t *iscanbuf_free = 0;
iscan_buf_t *iscanbuf_prv = 0;
iscan_buf_t *iscanbuf_cur = iscan_chain;
dhd_pub_t *dhd = dhd_bus_pub(dhdp);
dhd_iscan_lock();
if (!iscan_delete) {
while (iscanbuf_cur) {
iscanbuf_free = iscanbuf_cur;
iscanbuf_cur = iscanbuf_cur->next;
iscanbuf_free->next = 0;
kfree(iscanbuf_free);
}
iscan_chain = 0;
} else {
while (iscanbuf_cur) {
if (iscanbuf_cur == iscan_delete)
break;
iscanbuf_prv = iscanbuf_cur;
iscanbuf_cur = iscanbuf_cur->next;
}
if (iscanbuf_prv)
iscanbuf_prv->next = iscan_delete->next;
iscan_delete->next = 0;
kfree(iscan_delete);
if (!iscanbuf_prv)
iscan_chain = 0;
}
dhd_iscan_unlock();
}
iscan_buf_t *dhd_iscan_result_buf(void)
{
return iscan_chain;
}
int dhd_iscan_print_cache(iscan_buf_t *iscan_skip)
{
int i = 0, l = 0;
iscan_buf_t *iscan_cur;
wl_iscan_results_t *list;
wl_scan_results_t *results;
wl_bss_info_t UNALIGNED *bi;
dhd_iscan_lock();
iscan_cur = dhd_iscan_result_buf();
while (iscan_cur) {
list = (wl_iscan_results_t *)iscan_cur->iscan_buf;
if (!list)
break;
results = (wl_scan_results_t *)&list->results;
if (!results)
break;
if (results->version != WL_BSS_INFO_VERSION) {
DHD_ISCAN(("%s: results->version %d != "
"WL_BSS_INFO_VERSION\n",
__func__, results->version));
goto done;
}
bi = results->bss_info;
for (i = 0; i < results->count; i++) {
if (!bi)
break;
DHD_ISCAN(("%s[%2.2d:%2.2d] %X:%X:%X:%X:%X:%X\n",
iscan_cur != iscan_skip ? "BSS" : "bss", l,
i, bi->BSSID.octet[0], bi->BSSID.octet[1],
bi->BSSID.octet[2], bi->BSSID.octet[3],
bi->BSSID.octet[4], bi->BSSID.octet[5]));
bi = (wl_bss_info_t *)((unsigned long)bi + bi->length);
}
iscan_cur = iscan_cur->next;
l++;
}
done:
dhd_iscan_unlock();
return 0;
}
int dhd_iscan_delete_bss(void *dhdp, void *addr, iscan_buf_t *iscan_skip)
{
int i = 0, j = 0, l = 0;
iscan_buf_t *iscan_cur;
wl_iscan_results_t *list;
wl_scan_results_t *results;
wl_bss_info_t UNALIGNED *bi, *bi_new, *bi_next;
unsigned char *s_addr = addr;
dhd_iscan_lock();
DHD_ISCAN(("%s: BSS to remove %X:%X:%X:%X:%X:%X\n",
__func__, s_addr[0], s_addr[1], s_addr[2],
s_addr[3], s_addr[4], s_addr[5]));
iscan_cur = dhd_iscan_result_buf();
while (iscan_cur) {
if (iscan_cur != iscan_skip) {
list = (wl_iscan_results_t *)iscan_cur->iscan_buf;
if (!list)
break;
results = (wl_scan_results_t *)&list->results;
if (!results)
break;
if (results->version != WL_BSS_INFO_VERSION) {
DHD_ERROR(("%s: results->version %d != "
"WL_BSS_INFO_VERSION\n",
__func__, results->version));
goto done;
}
bi = results->bss_info;
for (i = 0; i < results->count; i++) {
if (!bi)
break;
if (!memcmp
(bi->BSSID.octet, addr, ETH_ALEN)) {
DHD_ISCAN(("%s: Del BSS[%2.2d:%2.2d] "
"%X:%X:%X:%X:%X:%X\n",
__func__, l, i, bi->BSSID.octet[0],
bi->BSSID.octet[1], bi->BSSID.octet[2],
bi->BSSID.octet[3], bi->BSSID.octet[4],
bi->BSSID.octet[5]));
bi_new = bi;
bi = (wl_bss_info_t *)((unsigned long)
bi + bi->length);
results->buflen -= bi_new->length;
results->count--;
for (j = i; j < results->count; j++) {
if (bi && bi_new) {
DHD_ISCAN(("%s: Moved up BSS[%2.2d:%2.2d]" "%X:%X:%X:%X:%X:%X\n",
__func__, l, j,
bi->BSSID.octet[0],
bi->BSSID.octet[1],
bi->BSSID.octet[2],
bi->BSSID.octet[3],
bi->BSSID.octet[4],
bi->BSSID.octet[5]));
bi_next =
(wl_bss_info_t *)((unsigned long)bi +
bi->length);
memcpy(bi_new, bi,
bi->length);
bi_new =
(wl_bss_info_t *)((unsigned long)bi_new +
bi_new->
length);
bi = bi_next;
}
}
if (results->count == 0) {
dhd_iscan_free_buf(dhdp,
iscan_cur);
goto done;
}
break;
}
bi = (wl_bss_info_t *)((unsigned long)bi +
bi->length);
}
}
iscan_cur = iscan_cur->next;
l++;
}
done:
dhd_iscan_unlock();
return 0;
}
int dhd_iscan_remove_duplicates(void *dhdp, iscan_buf_t *iscan_cur)
{
int i = 0;
wl_iscan_results_t *list;
wl_scan_results_t *results;
wl_bss_info_t UNALIGNED *bi, *bi_new, *bi_next;
dhd_iscan_lock();
DHD_ISCAN(("%s: Scan cache before delete\n", __func__));
dhd_iscan_print_cache(iscan_cur);
if (!iscan_cur)
goto done;
list = (wl_iscan_results_t *)iscan_cur->iscan_buf;
if (!list)
goto done;
results = (wl_scan_results_t *)&list->results;
if (!results)
goto done;
if (results->version != WL_BSS_INFO_VERSION) {
DHD_ERROR(("%s: results->version %d != WL_BSS_INFO_VERSION\n",
__func__, results->version));
goto done;
}
bi = results->bss_info;
for (i = 0; i < results->count; i++) {
if (!bi)
break;
DHD_ISCAN(("%s: Find dups for BSS[%2.2d] %X:%X:%X:%X:%X:%X\n",
__func__, i, bi->BSSID.octet[0],
bi->BSSID.octet[1], bi->BSSID.octet[2],
bi->BSSID.octet[3], bi->BSSID.octet[4],
bi->BSSID.octet[5]));
dhd_iscan_delete_bss(dhdp, bi->BSSID.octet, iscan_cur);
bi = (wl_bss_info_t *)((unsigned long)bi + bi->length);
}
done:
DHD_ISCAN(("%s: Scan cache after delete\n", __func__));
dhd_iscan_print_cache(iscan_cur);
dhd_iscan_unlock();
return 0;
}
void dhd_iscan_ind_scan_confirm(void *dhdp, bool status)
{
dhd_ind_scan_confirm(dhdp, status);
}
int dhd_iscan_request(void *dhdp, u16 action)
{
int rc;
wl_iscan_params_t params;
dhd_pub_t *dhd = dhd_bus_pub(dhdp);
char buf[WLC_IOCTL_SMLEN];
memset(&params, 0, sizeof(wl_iscan_params_t));
memcpy(&params.params.bssid, &ether_bcast, ETH_ALEN);
params.params.bss_type = DOT11_BSSTYPE_ANY;
params.params.scan_type = DOT11_SCANTYPE_ACTIVE;
params.params.nprobes = -1;
params.params.active_time = -1;
params.params.passive_time = -1;
params.params.home_time = -1;
params.params.channel_num = 0;
params.version = ISCAN_REQ_VERSION;
params.action = action;
params.scan_duration = 0;
bcm_mkiovar("iscan", (char *)&params, sizeof(wl_iscan_params_t), buf,
WLC_IOCTL_SMLEN);
rc = dhd_wl_ioctl(dhdp, WLC_SET_VAR, buf, WLC_IOCTL_SMLEN);
return rc;
}
static int dhd_iscan_get_partial_result(void *dhdp, uint *scan_count)
{
wl_iscan_results_t *list_buf;
wl_iscan_results_t list;
wl_scan_results_t *results;
iscan_buf_t *iscan_cur;
int status = -1;
dhd_pub_t *dhd = dhd_bus_pub(dhdp);
int rc;
iscan_cur = dhd_iscan_allocate_buf(dhd, &iscan_chain);
if (!iscan_cur) {
DHD_ERROR(("%s: Failed to allocate node\n", __func__));
dhd_iscan_free_buf(dhdp, 0);
dhd_iscan_request(dhdp, WL_SCAN_ACTION_ABORT);
goto fail;
}
dhd_iscan_lock();
memset(iscan_cur->iscan_buf, 0, WLC_IW_ISCAN_MAXLEN);
list_buf = (wl_iscan_results_t *) iscan_cur->iscan_buf;
results = &list_buf->results;
results->buflen = WL_ISCAN_RESULTS_FIXED_SIZE;
results->version = 0;
results->count = 0;
memset(&list, 0, sizeof(list));
list.results.buflen = WLC_IW_ISCAN_MAXLEN;
bcm_mkiovar("iscanresults", (char *)&list, WL_ISCAN_RESULTS_FIXED_SIZE,
iscan_cur->iscan_buf, WLC_IW_ISCAN_MAXLEN);
rc = dhd_wl_ioctl(dhdp, WLC_GET_VAR, iscan_cur->iscan_buf,
WLC_IW_ISCAN_MAXLEN);
results->buflen = results->buflen;
results->version = results->version;
*scan_count = results->count = results->count;
status = list_buf->status;
dhd_iscan_unlock();
if (!(*scan_count))
dhd_iscan_free_buf(dhdp, iscan_cur);
else
dhd_iscan_remove_duplicates(dhdp, iscan_cur);
fail:
return status;
}
int dhd_pno_clean(dhd_pub_t *dhd)
{
char iovbuf[128];
int pfn_enabled = 0;
int iov_len = 0;
int ret;
iov_len =
bcm_mkiovar("pfn", (char *)&pfn_enabled, 4, iovbuf, sizeof(iovbuf));
ret = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (ret >= 0) {
iov_len = bcm_mkiovar("pfnclear", 0, 0, iovbuf, sizeof(iovbuf));
if (iov_len) {
ret = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
iov_len);
if (ret < 0) {
DHD_ERROR(("%s failed code %d\n", __func__,
ret));
}
} else {
ret = -1;
DHD_ERROR(("%s failed code %d\n", __func__, iov_len));
}
} else
DHD_ERROR(("%s failed code %d\n", __func__, ret));
return ret;
}
int dhd_pno_enable(dhd_pub_t *dhd, int pfn_enabled)
{
char iovbuf[128];
int ret = -1;
if ((!dhd) && ((pfn_enabled != 0) || (pfn_enabled != 1))) {
DHD_ERROR(("%s error exit\n", __func__));
return ret;
}
ret = bcm_mkiovar("pfn", (char *)&pfn_enabled, 4, iovbuf,
sizeof(iovbuf));
if (ret > 0) {
ret = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
sizeof(iovbuf));
if (ret < 0) {
DHD_ERROR(("%s failed for error=%d\n", __func__, ret));
return ret;
} else {
dhd->pno_enable = pfn_enabled;
DHD_TRACE(("%s set pno as %d\n", __func__,
dhd->pno_enable));
}
} else
DHD_ERROR(("%s failed err=%d\n", __func__, ret));
return ret;
}
int
dhd_pno_set(dhd_pub_t *dhd, wlc_ssid_t *ssids_local, int nssid, unsigned char scan_fr)
{
int err = -1;
char iovbuf[128];
int k, i;
wl_pfn_param_t pfn_param;
wl_pfn_t pfn_element;
DHD_TRACE(("%s nssid=%d nchan=%d\n", __func__, nssid, scan_fr));
if ((!dhd) && (!ssids_local)) {
DHD_ERROR(("%s error exit\n", __func__));
err = -1;
}
for (k = 0; k < nssid; k++) {
if (!ssids_local[k].SSID_len) {
DHD_ERROR(("%d: Broadcast SSID is ilegal for PNO "
"setting\n", k));
return err;
}
}
#ifdef PNO_DUMP
{
int j;
for (j = 0; j < nssid; j++) {
DHD_ERROR(("%d: scan for %s size =%d\n", j,
ssids_local[j].SSID,
ssids_local[j].SSID_len));
}
}
#endif
err = dhd_pno_clean(dhd);
if (err < 0) {
DHD_ERROR(("%s failed error=%d\n", __func__, err));
return err;
}
memset(&pfn_param, 0, sizeof(pfn_param));
memset(&pfn_element, 0, sizeof(pfn_element));
pfn_param.version = PFN_VERSION;
pfn_param.flags = (PFN_LIST_ORDER << SORT_CRITERIA_BIT);
if (scan_fr != 0)
pfn_param.scan_freq = scan_fr;
bcm_mkiovar("pfn_set", (char *)&pfn_param, sizeof(pfn_param), iovbuf,
sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
for (i = 0; i < nssid; i++) {
pfn_element.bss_type = DOT11_BSSTYPE_INFRASTRUCTURE;
pfn_element.auth = WLAN_AUTH_OPEN;
pfn_element.wpa_auth = WPA_AUTH_PFN_ANY;
pfn_element.wsec = 0;
pfn_element.infra = 1;
memcpy((char *)pfn_element.ssid.SSID, ssids_local[i].SSID,
ssids_local[i].SSID_len);
pfn_element.ssid.SSID_len = ssids_local[i].SSID_len;
err = bcm_mkiovar("pfn_add", (char *)&pfn_element,
sizeof(pfn_element), iovbuf, sizeof(iovbuf));
if (err > 0) {
err = dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
sizeof(iovbuf));
if (err < 0) {
DHD_ERROR(("%s failed for i=%d error=%d\n",
__func__, i, err));
return err;
}
} else
DHD_ERROR(("%s failed err=%d\n", __func__, err));
}
return err;
}
int dhd_pno_get_status(dhd_pub_t *dhd)
{
int ret = -1;
if (!dhd)
return ret;
else
return dhd->pno_enable;
}
