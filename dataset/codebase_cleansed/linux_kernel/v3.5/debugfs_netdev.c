static ssize_t ieee80211_if_read(
struct ieee80211_sub_if_data *sdata,
char __user *userbuf,
size_t count, loff_t *ppos,
ssize_t (*format)(const struct ieee80211_sub_if_data *, char *, int))
{
char buf[70];
ssize_t ret = -EINVAL;
read_lock(&dev_base_lock);
if (sdata->dev->reg_state == NETREG_REGISTERED)
ret = (*format)(sdata, buf, sizeof(buf));
read_unlock(&dev_base_lock);
if (ret >= 0)
ret = simple_read_from_buffer(userbuf, count, ppos, buf, ret);
return ret;
}
static ssize_t ieee80211_if_write(
struct ieee80211_sub_if_data *sdata,
const char __user *userbuf,
size_t count, loff_t *ppos,
ssize_t (*write)(struct ieee80211_sub_if_data *, const char *, int))
{
char buf[64];
ssize_t ret;
if (count >= sizeof(buf))
return -E2BIG;
if (copy_from_user(buf, userbuf, count))
return -EFAULT;
buf[count] = '\0';
ret = -ENODEV;
rtnl_lock();
if (sdata->dev->reg_state == NETREG_REGISTERED)
ret = (*write)(sdata, buf, count);
rtnl_unlock();
return ret;
}
static int ieee80211_set_smps(struct ieee80211_sub_if_data *sdata,
enum ieee80211_smps_mode smps_mode)
{
struct ieee80211_local *local = sdata->local;
int err;
if (!(local->hw.flags & IEEE80211_HW_SUPPORTS_STATIC_SMPS) &&
smps_mode == IEEE80211_SMPS_STATIC)
return -EINVAL;
if (!(local->hw.flags & IEEE80211_HW_SUPPORTS_DYNAMIC_SMPS) &&
(smps_mode == IEEE80211_SMPS_DYNAMIC ||
smps_mode == IEEE80211_SMPS_AUTOMATIC))
return -EINVAL;
if (sdata->vif.type != NL80211_IFTYPE_STATION)
return -EOPNOTSUPP;
mutex_lock(&sdata->u.mgd.mtx);
err = __ieee80211_request_smps(sdata, smps_mode);
mutex_unlock(&sdata->u.mgd.mtx);
return err;
}
static ssize_t ieee80211_if_fmt_smps(const struct ieee80211_sub_if_data *sdata,
char *buf, int buflen)
{
if (sdata->vif.type != NL80211_IFTYPE_STATION)
return -EOPNOTSUPP;
return snprintf(buf, buflen, "request: %s\nused: %s\n",
smps_modes[sdata->u.mgd.req_smps],
smps_modes[sdata->u.mgd.ap_smps]);
}
static ssize_t ieee80211_if_parse_smps(struct ieee80211_sub_if_data *sdata,
const char *buf, int buflen)
{
enum ieee80211_smps_mode mode;
for (mode = 0; mode < IEEE80211_SMPS_NUM_MODES; mode++) {
if (strncmp(buf, smps_modes[mode], buflen) == 0) {
int err = ieee80211_set_smps(sdata, mode);
if (!err)
return buflen;
return err;
}
}
return -EINVAL;
}
static ssize_t ieee80211_if_fmt_tkip_mic_test(
const struct ieee80211_sub_if_data *sdata, char *buf, int buflen)
{
return -EOPNOTSUPP;
}
static int hwaddr_aton(const char *txt, u8 *addr)
{
int i;
for (i = 0; i < ETH_ALEN; i++) {
int a, b;
a = hex_to_bin(*txt++);
if (a < 0)
return -1;
b = hex_to_bin(*txt++);
if (b < 0)
return -1;
*addr++ = (a << 4) | b;
if (i < 5 && *txt++ != ':')
return -1;
}
return 0;
}
static ssize_t ieee80211_if_parse_tkip_mic_test(
struct ieee80211_sub_if_data *sdata, const char *buf, int buflen)
{
struct ieee80211_local *local = sdata->local;
u8 addr[ETH_ALEN];
struct sk_buff *skb;
struct ieee80211_hdr *hdr;
__le16 fc;
if (buflen < 3 * ETH_ALEN - 1)
return -EINVAL;
if (hwaddr_aton(buf, addr) < 0)
return -EINVAL;
if (!ieee80211_sdata_running(sdata))
return -ENOTCONN;
skb = dev_alloc_skb(local->hw.extra_tx_headroom + 24 + 100);
if (!skb)
return -ENOMEM;
skb_reserve(skb, local->hw.extra_tx_headroom);
hdr = (struct ieee80211_hdr *) skb_put(skb, 24);
memset(hdr, 0, 24);
fc = cpu_to_le16(IEEE80211_FTYPE_DATA | IEEE80211_STYPE_DATA);
switch (sdata->vif.type) {
case NL80211_IFTYPE_AP:
fc |= cpu_to_le16(IEEE80211_FCTL_FROMDS);
memcpy(hdr->addr1, addr, ETH_ALEN);
memcpy(hdr->addr2, sdata->vif.addr, ETH_ALEN);
memcpy(hdr->addr3, sdata->vif.addr, ETH_ALEN);
break;
case NL80211_IFTYPE_STATION:
fc |= cpu_to_le16(IEEE80211_FCTL_TODS);
if (sdata->vif.bss_conf.bssid == NULL) {
dev_kfree_skb(skb);
return -ENOTCONN;
}
memcpy(hdr->addr1, sdata->vif.bss_conf.bssid, ETH_ALEN);
memcpy(hdr->addr2, sdata->vif.addr, ETH_ALEN);
memcpy(hdr->addr3, addr, ETH_ALEN);
break;
default:
dev_kfree_skb(skb);
return -EOPNOTSUPP;
}
hdr->frame_control = fc;
memset(skb_put(skb, 50), 0, 50);
IEEE80211_SKB_CB(skb)->flags |= IEEE80211_TX_INTFL_TKIP_MIC_FAILURE;
ieee80211_tx_skb(sdata, skb);
return buflen;
}
static ssize_t ieee80211_if_fmt_uapsd_queues(
const struct ieee80211_sub_if_data *sdata, char *buf, int buflen)
{
const struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
return snprintf(buf, buflen, "0x%x\n", ifmgd->uapsd_queues);
}
static ssize_t ieee80211_if_parse_uapsd_queues(
struct ieee80211_sub_if_data *sdata, const char *buf, int buflen)
{
struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
u8 val;
int ret;
ret = kstrtou8(buf, 0, &val);
if (ret)
return ret;
if (val & ~IEEE80211_WMM_IE_STA_QOSINFO_AC_MASK)
return -ERANGE;
ifmgd->uapsd_queues = val;
return buflen;
}
static ssize_t ieee80211_if_fmt_uapsd_max_sp_len(
const struct ieee80211_sub_if_data *sdata, char *buf, int buflen)
{
const struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
return snprintf(buf, buflen, "0x%x\n", ifmgd->uapsd_max_sp_len);
}
static ssize_t ieee80211_if_parse_uapsd_max_sp_len(
struct ieee80211_sub_if_data *sdata, const char *buf, int buflen)
{
struct ieee80211_if_managed *ifmgd = &sdata->u.mgd;
unsigned long val;
int ret;
ret = kstrtoul(buf, 0, &val);
if (ret)
return -EINVAL;
if (val & ~IEEE80211_WMM_IE_STA_QOSINFO_SP_MASK)
return -ERANGE;
ifmgd->uapsd_max_sp_len = val;
return buflen;
}
static ssize_t ieee80211_if_fmt_num_buffered_multicast(
const struct ieee80211_sub_if_data *sdata, char *buf, int buflen)
{
return scnprintf(buf, buflen, "%u\n",
skb_queue_len(&sdata->u.ap.ps_bc_buf));
}
static ssize_t ieee80211_if_fmt_tsf(
const struct ieee80211_sub_if_data *sdata, char *buf, int buflen)
{
struct ieee80211_local *local = sdata->local;
u64 tsf;
tsf = drv_get_tsf(local, (struct ieee80211_sub_if_data *)sdata);
return scnprintf(buf, buflen, "0x%016llx\n", (unsigned long long) tsf);
}
static ssize_t ieee80211_if_parse_tsf(
struct ieee80211_sub_if_data *sdata, const char *buf, int buflen)
{
struct ieee80211_local *local = sdata->local;
unsigned long long tsf;
int ret;
int tsf_is_delta = 0;
if (strncmp(buf, "reset", 5) == 0) {
if (local->ops->reset_tsf) {
drv_reset_tsf(local, sdata);
wiphy_info(local->hw.wiphy, "debugfs reset TSF\n");
}
} else {
if (buflen > 10 && buf[1] == '=') {
if (buf[0] == '+')
tsf_is_delta = 1;
else if (buf[0] == '-')
tsf_is_delta = -1;
else
return -EINVAL;
buf += 2;
}
ret = kstrtoull(buf, 10, &tsf);
if (ret < 0)
return -EINVAL;
if (tsf_is_delta)
tsf = drv_get_tsf(local, sdata) + tsf_is_delta * tsf;
if (local->ops->set_tsf) {
drv_set_tsf(local, sdata, tsf);
wiphy_info(local->hw.wiphy,
"debugfs set TSF to %#018llx\n", tsf);
}
}
return buflen;
}
static void add_common_files(struct ieee80211_sub_if_data *sdata)
{
DEBUGFS_ADD(drop_unencrypted);
DEBUGFS_ADD(rc_rateidx_mask_2ghz);
DEBUGFS_ADD(rc_rateidx_mask_5ghz);
DEBUGFS_ADD(rc_rateidx_mcs_mask_2ghz);
DEBUGFS_ADD(rc_rateidx_mcs_mask_5ghz);
}
static void add_sta_files(struct ieee80211_sub_if_data *sdata)
{
DEBUGFS_ADD(bssid);
DEBUGFS_ADD(aid);
DEBUGFS_ADD(last_beacon);
DEBUGFS_ADD(ave_beacon);
DEBUGFS_ADD_MODE(smps, 0600);
DEBUGFS_ADD_MODE(tkip_mic_test, 0200);
DEBUGFS_ADD_MODE(uapsd_queues, 0600);
DEBUGFS_ADD_MODE(uapsd_max_sp_len, 0600);
}
static void add_ap_files(struct ieee80211_sub_if_data *sdata)
{
DEBUGFS_ADD(num_mcast_sta);
DEBUGFS_ADD(num_sta_ps);
DEBUGFS_ADD(dtim_count);
DEBUGFS_ADD(num_buffered_multicast);
DEBUGFS_ADD_MODE(tkip_mic_test, 0200);
}
static void add_ibss_files(struct ieee80211_sub_if_data *sdata)
{
DEBUGFS_ADD_MODE(tsf, 0600);
}
static void add_wds_files(struct ieee80211_sub_if_data *sdata)
{
DEBUGFS_ADD(peer);
}
static void add_mesh_files(struct ieee80211_sub_if_data *sdata)
{
DEBUGFS_ADD_MODE(tsf, 0600);
}
static void add_mesh_stats(struct ieee80211_sub_if_data *sdata)
{
struct dentry *dir = debugfs_create_dir("mesh_stats",
sdata->debugfs.dir);
#define MESHSTATS_ADD(name)\
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
MESHSTATS_ADD(fwded_mcast);
MESHSTATS_ADD(fwded_unicast);
MESHSTATS_ADD(fwded_frames);
MESHSTATS_ADD(dropped_frames_ttl);
MESHSTATS_ADD(dropped_frames_no_route);
MESHSTATS_ADD(dropped_frames_congestion);
MESHSTATS_ADD(estab_plinks);
#undef MESHSTATS_ADD
}
static void add_mesh_config(struct ieee80211_sub_if_data *sdata)
{
struct dentry *dir = debugfs_create_dir("mesh_config",
sdata->debugfs.dir);
#define MESHPARAMS_ADD(name) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
MESHPARAMS_ADD(dot11MeshMaxRetries);
MESHPARAMS_ADD(dot11MeshRetryTimeout);
MESHPARAMS_ADD(dot11MeshConfirmTimeout);
MESHPARAMS_ADD(dot11MeshHoldingTimeout);
MESHPARAMS_ADD(dot11MeshTTL);
MESHPARAMS_ADD(element_ttl);
MESHPARAMS_ADD(auto_open_plinks);
MESHPARAMS_ADD(dot11MeshMaxPeerLinks);
MESHPARAMS_ADD(dot11MeshHWMPactivePathTimeout);
MESHPARAMS_ADD(dot11MeshHWMPpreqMinInterval);
MESHPARAMS_ADD(dot11MeshHWMPperrMinInterval);
MESHPARAMS_ADD(dot11MeshHWMPnetDiameterTraversalTime);
MESHPARAMS_ADD(dot11MeshHWMPmaxPREQretries);
MESHPARAMS_ADD(path_refresh_time);
MESHPARAMS_ADD(min_discovery_timeout);
MESHPARAMS_ADD(dot11MeshHWMPRootMode);
MESHPARAMS_ADD(dot11MeshHWMPRannInterval);
MESHPARAMS_ADD(dot11MeshGateAnnouncementProtocol);
MESHPARAMS_ADD(rssi_threshold);
MESHPARAMS_ADD(ht_opmode);
#undef MESHPARAMS_ADD
}
static void add_files(struct ieee80211_sub_if_data *sdata)
{
if (!sdata->debugfs.dir)
return;
DEBUGFS_ADD(flags);
DEBUGFS_ADD(state);
DEBUGFS_ADD(channel_type);
if (sdata->vif.type != NL80211_IFTYPE_MONITOR)
add_common_files(sdata);
switch (sdata->vif.type) {
case NL80211_IFTYPE_MESH_POINT:
#ifdef CONFIG_MAC80211_MESH
add_mesh_files(sdata);
add_mesh_stats(sdata);
add_mesh_config(sdata);
#endif
break;
case NL80211_IFTYPE_STATION:
add_sta_files(sdata);
break;
case NL80211_IFTYPE_ADHOC:
add_ibss_files(sdata);
break;
case NL80211_IFTYPE_AP:
add_ap_files(sdata);
break;
case NL80211_IFTYPE_WDS:
add_wds_files(sdata);
break;
default:
break;
}
}
void ieee80211_debugfs_add_netdev(struct ieee80211_sub_if_data *sdata)
{
char buf[10+IFNAMSIZ];
sprintf(buf, "netdev:%s", sdata->name);
sdata->debugfs.dir = debugfs_create_dir(buf,
sdata->local->hw.wiphy->debugfsdir);
if (sdata->debugfs.dir)
sdata->debugfs.subdir_stations = debugfs_create_dir("stations",
sdata->debugfs.dir);
add_files(sdata);
}
void ieee80211_debugfs_remove_netdev(struct ieee80211_sub_if_data *sdata)
{
if (!sdata->debugfs.dir)
return;
debugfs_remove_recursive(sdata->debugfs.dir);
sdata->debugfs.dir = NULL;
}
void ieee80211_debugfs_rename_netdev(struct ieee80211_sub_if_data *sdata)
{
struct dentry *dir;
char buf[10 + IFNAMSIZ];
dir = sdata->debugfs.dir;
if (!dir)
return;
sprintf(buf, "netdev:%s", sdata->name);
if (!debugfs_rename(dir->d_parent, dir, dir->d_parent, buf))
printk(KERN_ERR "mac80211: debugfs: failed to rename debugfs "
"dir to %s\n", buf);
}
