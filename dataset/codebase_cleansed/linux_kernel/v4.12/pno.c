static int brcmf_pno_channel_config(struct brcmf_if *ifp,
struct brcmf_pno_config_le *cfg)
{
cfg->reporttype = 0;
cfg->flags = 0;
return brcmf_fil_iovar_data_set(ifp, "pfn_cfg", cfg, sizeof(*cfg));
}
static int brcmf_pno_config(struct brcmf_if *ifp, u32 scan_freq,
u32 mscan, u32 bestn)
{
struct brcmf_pno_param_le pfn_param;
u16 flags;
u32 pfnmem;
s32 err;
memset(&pfn_param, 0, sizeof(pfn_param));
pfn_param.version = cpu_to_le32(BRCMF_PNO_VERSION);
flags = BIT(BRCMF_PNO_IMMEDIATE_SCAN_BIT) |
BIT(BRCMF_PNO_REPORT_SEPARATELY_BIT) |
BIT(BRCMF_PNO_ENABLE_ADAPTSCAN_BIT);
pfn_param.repeat = BRCMF_PNO_REPEAT;
pfn_param.exp = BRCMF_PNO_FREQ_EXPO_MAX;
if (scan_freq < BRCMF_PNO_SCHED_SCAN_MIN_PERIOD) {
brcmf_dbg(SCAN, "scan period too small, using minimum\n");
scan_freq = BRCMF_PNO_SCHED_SCAN_MIN_PERIOD;
}
pfn_param.scan_freq = cpu_to_le32(scan_freq);
if (mscan) {
pfnmem = bestn;
err = brcmf_fil_iovar_int_set(ifp, "pfnmem", pfnmem);
if (err < 0) {
brcmf_err("failed to set pfnmem\n");
goto exit;
}
err = brcmf_fil_iovar_int_get(ifp, "pfnmem", &pfnmem);
if (err < 0) {
brcmf_err("failed to get pfnmem\n");
goto exit;
}
mscan = min_t(u32, mscan, pfnmem);
pfn_param.mscan = mscan;
pfn_param.bestn = bestn;
flags |= BIT(BRCMF_PNO_ENABLE_BD_SCAN_BIT);
brcmf_dbg(INFO, "mscan=%d, bestn=%d\n", mscan, bestn);
}
pfn_param.flags = cpu_to_le16(flags);
err = brcmf_fil_iovar_data_set(ifp, "pfn_set", &pfn_param,
sizeof(pfn_param));
if (err)
brcmf_err("pfn_set failed, err=%d\n", err);
exit:
return err;
}
static int brcmf_pno_set_random(struct brcmf_if *ifp, u8 *mac_addr,
u8 *mac_mask)
{
struct brcmf_pno_macaddr_le pfn_mac;
int err, i;
pfn_mac.version = BRCMF_PFN_MACADDR_CFG_VER;
pfn_mac.flags = BRCMF_PFN_MAC_OUI_ONLY | BRCMF_PFN_SET_MAC_UNASSOC;
memcpy(pfn_mac.mac, mac_addr, ETH_ALEN);
for (i = 0; i < ETH_ALEN; i++) {
pfn_mac.mac[i] &= mac_mask[i];
pfn_mac.mac[i] |= get_random_int() & ~(mac_mask[i]);
}
pfn_mac.mac[0] &= 0xFE;
pfn_mac.mac[0] |= 0x02;
err = brcmf_fil_iovar_data_set(ifp, "pfn_macaddr", &pfn_mac,
sizeof(pfn_mac));
if (err)
brcmf_err("pfn_macaddr failed, err=%d\n", err);
return err;
}
static int brcmf_pno_add_ssid(struct brcmf_if *ifp, struct cfg80211_ssid *ssid,
bool active)
{
struct brcmf_pno_net_param_le pfn;
pfn.auth = cpu_to_le32(WLAN_AUTH_OPEN);
pfn.wpa_auth = cpu_to_le32(BRCMF_PNO_WPA_AUTH_ANY);
pfn.wsec = cpu_to_le32(0);
pfn.infra = cpu_to_le32(1);
pfn.flags = 0;
if (active)
pfn.flags = cpu_to_le32(1 << BRCMF_PNO_HIDDEN_BIT);
pfn.ssid.SSID_len = cpu_to_le32(ssid->ssid_len);
memcpy(pfn.ssid.SSID, ssid->ssid, ssid->ssid_len);
return brcmf_fil_iovar_data_set(ifp, "pfn_add", &pfn, sizeof(pfn));
}
static bool brcmf_is_ssid_active(struct cfg80211_ssid *ssid,
struct cfg80211_sched_scan_request *req)
{
int i;
if (!ssid || !req->ssids || !req->n_ssids)
return false;
for (i = 0; i < req->n_ssids; i++) {
if (ssid->ssid_len == req->ssids[i].ssid_len) {
if (!strncmp(ssid->ssid, req->ssids[i].ssid,
ssid->ssid_len))
return true;
}
}
return false;
}
int brcmf_pno_clean(struct brcmf_if *ifp)
{
int ret;
ret = brcmf_fil_iovar_int_set(ifp, "pfn", 0);
if (ret == 0) {
ret = brcmf_fil_iovar_data_set(ifp, "pfnclear", NULL, 0);
}
if (ret < 0)
brcmf_err("failed code %d\n", ret);
return ret;
}
int brcmf_pno_start_sched_scan(struct brcmf_if *ifp,
struct cfg80211_sched_scan_request *req)
{
struct brcmf_pno_config_le pno_cfg;
struct cfg80211_ssid *ssid;
u16 chan;
int i, ret;
ret = brcmf_pno_clean(ifp);
if (ret < 0) {
brcmf_err("failed error=%d\n", ret);
return ret;
}
ret = brcmf_pno_config(ifp, req->scan_plans[0].interval, 0, 0);
if (ret < 0)
return ret;
if (req->flags & NL80211_SCAN_FLAG_RANDOM_ADDR) {
ret = brcmf_pno_set_random(ifp, req->mac_addr,
req->mac_addr_mask);
if (ret < 0)
return ret;
}
for (i = 0; i < req->n_channels; i++) {
chan = req->channels[i]->hw_value;
pno_cfg.channel_list[i] = cpu_to_le16(chan);
}
if (req->n_channels) {
pno_cfg.channel_num = cpu_to_le32(req->n_channels);
brcmf_pno_channel_config(ifp, &pno_cfg);
}
for (i = 0; i < req->n_match_sets; i++) {
ssid = &req->match_sets[i].ssid;
if (!ssid->ssid_len) {
brcmf_err("skip broadcast ssid\n");
continue;
}
ret = brcmf_pno_add_ssid(ifp, ssid,
brcmf_is_ssid_active(ssid, req));
if (ret < 0)
brcmf_dbg(SCAN, ">>> PNO filter %s for ssid (%s)\n",
ret == 0 ? "set" : "failed", ssid->ssid);
}
ret = brcmf_fil_iovar_int_set(ifp, "pfn", 1);
if (ret < 0)
brcmf_err("PNO enable failed!! ret=%d\n", ret);
return ret;
}
