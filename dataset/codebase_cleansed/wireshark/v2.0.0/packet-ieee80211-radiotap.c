void
capture_radiotap(const guchar * pd, int offset, int len, packet_counts * ld)
{
guint16 it_len;
guint32 present, xpresent;
guint8 rflags;
const struct ieee80211_radiotap_header *hdr;
if (!BYTES_ARE_IN_FRAME(offset, len,
sizeof(struct ieee80211_radiotap_header))) {
ld->other++;
return;
}
hdr = (const struct ieee80211_radiotap_header *)pd;
it_len = pletoh16(&hdr->it_len);
if (!BYTES_ARE_IN_FRAME(offset, len, it_len)) {
ld->other++;
return;
}
if (it_len > len) {
ld->other++;
return;
}
if (it_len < sizeof(struct ieee80211_radiotap_header)) {
ld->other++;
return;
}
present = pletoh32(&hdr->it_present);
offset += (int)sizeof(struct ieee80211_radiotap_header);
it_len -= (int)sizeof(struct ieee80211_radiotap_header);
xpresent = present;
while (xpresent & BIT(IEEE80211_RADIOTAP_EXT)) {
if (!BYTES_ARE_IN_FRAME(offset, 4, it_len)) {
ld->other++;
return;
}
xpresent = pletoh32(pd + offset);
offset += 4;
it_len -= 4;
}
rflags = 0;
if (present & BIT(IEEE80211_RADIOTAP_TSFT)) {
if (offset & 7) {
int pad = 8 - (offset & 7);
offset += pad;
it_len -= pad;
}
if (it_len < 8) {
ld->other++;
return;
}
offset += 8;
it_len -= 8;
}
if (present & BIT(IEEE80211_RADIOTAP_FLAGS)) {
if (it_len < 1) {
ld->other++;
return;
}
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
rflags = pd[offset];
}
if (rflags & IEEE80211_RADIOTAP_F_DATAPAD)
capture_ieee80211_datapad(pd, offset + it_len, len, ld);
else
capture_ieee80211(pd, offset + it_len, len, ld);
}
static void
dissect_radiotap(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_tree *radiotap_tree = NULL;
proto_tree *pt = NULL, *present_tree = NULL;
proto_tree *ft;
proto_item *ti = NULL;
proto_item *hidden_item;
int offset;
tvbuff_t *next_tvb;
guint8 version;
guint length;
guint16 cflags;
guint32 freq;
proto_item *rate_ti;
gint8 dbm, db;
gboolean have_rflags = FALSE;
guint8 rflags = 0;
guint32 xcflags;
proto_item *hdr_fcs_ti = NULL;
int hdr_fcs_offset = 0;
guint32 sent_fcs = 0;
guint32 calc_fcs;
gint err = -ENOENT;
void *data;
struct _radiotap_info *radiotap_info;
static struct _radiotap_info rtp_info_arr;
struct ieee80211_radiotap_iterator iter;
struct ieee_802_11_phdr phdr;
static struct radiotap_override overrides[] = {
{IEEE80211_RADIOTAP_XCHANNEL, 4, 8},
{14, 4, 4},
};
guint n_overrides = array_length(overrides);
if (!radiotap_bit14_fcs)
n_overrides--;
radiotap_info = &rtp_info_arr;
phdr.fcs_len = -1;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.presence_flags = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WLAN");
col_clear(pinfo->cinfo, COL_INFO);
version = tvb_get_guint8(tvb, 0);
length = tvb_get_letohs(tvb, 2);
radiotap_info->radiotap_length = length;
col_add_fstr(pinfo->cinfo, COL_INFO, "Radiotap Capture v%u, Length %u",
version, length);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_radiotap,
tvb, 0, length,
"Radiotap Header v%u, Length %u",
version, length);
radiotap_tree = proto_item_add_subtree(ti, ett_radiotap);
proto_tree_add_uint(radiotap_tree, hf_radiotap_version,
tvb, 0, 1, version);
proto_tree_add_item(radiotap_tree, hf_radiotap_pad,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(radiotap_tree, hf_radiotap_length,
tvb, 2, 2, length);
}
data = tvb_memdup(wmem_packet_scope(), tvb, 0, length);
if (!data)
return;
if (ieee80211_radiotap_iterator_init(&iter, (struct ieee80211_radiotap_header *)data, length, NULL)) {
if (tree)
proto_item_append_text(ti, " (invalid)");
goto hand_off_to_80211;
}
iter.overrides = overrides;
iter.n_overrides = n_overrides;
if (tree) {
guchar *bmap_start = (guchar *)data + 4;
guint n_bitmaps = (guint)(iter.this_arg - bmap_start) / 4;
guint i;
gboolean rtap_ns;
gboolean rtap_ns_next = TRUE;
guint rtap_ns_offset;
guint rtap_ns_offset_next = 0;
pt = proto_tree_add_item(radiotap_tree, hf_radiotap_present,
tvb, 4, n_bitmaps * 4,
ENC_NA);
for (i = 0; i < n_bitmaps; i++) {
guint32 bmap = pletoh32(bmap_start + 4 * i);
rtap_ns_offset = rtap_ns_offset_next;
rtap_ns_offset_next += 32;
present_tree =
proto_item_add_subtree(pt, ett_radiotap_present);
offset = 4 * i;
rtap_ns = rtap_ns_next;
if (bmap & BIT(IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE)) {
rtap_ns_next = TRUE;
rtap_ns_offset_next = 0;
}
if (bmap & BIT(IEEE80211_RADIOTAP_VENDOR_NAMESPACE))
rtap_ns_next = FALSE;
if ((bmap & (BIT(IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE) |
BIT(IEEE80211_RADIOTAP_VENDOR_NAMESPACE)))
== (BIT(IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE) |
BIT(IEEE80211_RADIOTAP_VENDOR_NAMESPACE))) {
expert_add_info_format(pinfo, pt, &ei_radiotap_present,
"Both radiotap and vendor namespace specified in bitmask word %u",
i);
goto malformed;
}
if (!rtap_ns)
goto always_bits;
if (rtap_ns_offset)
goto always_bits;
proto_tree_add_item(present_tree,
hf_radiotap_present_tsft, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_flags, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_rate, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_channel, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_fhss, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_dbm_antsignal,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_dbm_antnoise,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_lock_quality,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_tx_attenuation,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_db_tx_attenuation,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_dbm_tx_power,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_antenna, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_db_antsignal,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_db_antnoise,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
if (radiotap_bit14_fcs) {
proto_tree_add_item(present_tree,
hf_radiotap_present_hdrfcs,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(present_tree,
hf_radiotap_present_rxflags,
tvb, offset + 4, 4, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(present_tree,
hf_radiotap_present_xchannel, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_mcs, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_ampdu, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_vht, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(present_tree,
hf_radiotap_present_reserved, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
if(bmap & IEEE80211_RADIOTAP_NOTDEFINED)
{
expert_add_info(pinfo, pt, &ei_radiotap_present_reserved);
}
always_bits:
proto_tree_add_item(present_tree,
hf_radiotap_present_rtap_ns, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_vendor_ns, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree,
hf_radiotap_present_ext, tvb,
offset + 4, 4, ENC_LITTLE_ENDIAN);
}
}
while (!(err = ieee80211_radiotap_iterator_next(&iter))) {
offset = (int)((guchar *) iter.this_arg - (guchar *) data);
if (iter.this_arg_index == IEEE80211_RADIOTAP_VENDOR_NAMESPACE
&& tree) {
proto_tree *vt, *ven_tree = NULL;
const gchar *manuf_name;
guint8 subns;
manuf_name = tvb_get_manuf_name(tvb, offset);
subns = tvb_get_guint8(tvb, offset+3);
vt = proto_tree_add_bytes_format_value(radiotap_tree,
hf_radiotap_vendor_ns,
tvb, offset,
iter.this_arg_size,
NULL,
"%s-%d",
manuf_name, subns);
ven_tree = proto_item_add_subtree(vt, ett_radiotap_vendor);
proto_tree_add_bytes_format_value(ven_tree,
hf_radiotap_ven_oui, tvb,
offset, 3, NULL,
"%s", manuf_name);
proto_tree_add_item(ven_tree, hf_radiotap_ven_subns,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ven_tree, hf_radiotap_ven_skip, tvb,
offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ven_tree, hf_radiotap_ven_data, tvb,
offset + 6, iter.this_arg_size - 6,
ENC_NA);
}
if (!iter.is_radiotap_ns)
continue;
switch (iter.this_arg_index) {
case IEEE80211_RADIOTAP_TSFT:
radiotap_info->tsft = tvb_get_letoh64(tvb, offset);
phdr.tsf_timestamp = radiotap_info->tsft;
phdr.presence_flags |= PHDR_802_11_HAS_TSF_TIMESTAMP;
if (tree) {
proto_tree_add_uint64(radiotap_tree,
hf_radiotap_mactime, tvb,
offset, 8,
radiotap_info->tsft);
}
break;
case IEEE80211_RADIOTAP_FLAGS: {
rflags = tvb_get_guint8(tvb, offset);
have_rflags = TRUE;
if (rflags & IEEE80211_RADIOTAP_F_DATAPAD)
phdr.datapad = TRUE;
if (rflags & IEEE80211_RADIOTAP_F_FCS)
phdr.fcs_len = 4;
else
phdr.fcs_len = 0;
if (tree) {
proto_tree *flags_tree;
ft = proto_tree_add_item(radiotap_tree,
hf_radiotap_flags,
tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree =
proto_item_add_subtree(ft,
ett_radiotap_flags);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_cfp,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_preamble,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_wep,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_frag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_fcs,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_datapad,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_badfcs,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree,
hf_radiotap_flags_shortgi,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
}
case IEEE80211_RADIOTAP_RATE: {
guint32 rate;
rate = tvb_get_guint8(tvb, offset);
if (rate >= 0x80 && rate <= 0x8f) {
if (tree) {
proto_tree_add_uint(radiotap_tree,
hf_radiotap_mcs_index,
tvb, offset, 1,
rate & 0x7f);
}
} else {
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%d.%d",
rate / 2, rate & 1 ? 5 : 0);
if (tree) {
proto_tree_add_float_format(radiotap_tree,
hf_radiotap_datarate,
tvb, offset, 1,
(float)rate / 2,
"Data Rate: %.1f Mb/s",
(float)rate / 2);
}
radiotap_info->rate = rate;
phdr.presence_flags |= PHDR_802_11_HAS_DATA_RATE;
phdr.data_rate = rate;
}
break;
}
case IEEE80211_RADIOTAP_CHANNEL: {
freq = tvb_get_letohs(tvb, offset);
if (freq != 0) {
gint calc_channel;
phdr.presence_flags |= PHDR_802_11_HAS_FREQUENCY;
phdr.frequency = freq;
calc_channel = ieee80211_mhz_to_chan(freq);
if (calc_channel != -1) {
phdr.presence_flags |= PHDR_802_11_HAS_CHANNEL;
phdr.channel = calc_channel;
}
}
cflags = tvb_get_letohs(tvb, offset + 2);
switch (cflags & IEEE80211_CHAN_ALLTURBO) {
case IEEE80211_CHAN_FHSS:
phdr.phy = PHDR_802_11_PHY_11_FHSS;
phdr.phy_info.info_11_fhss.presence_flags = 0;
break;
case IEEE80211_CHAN_DSSS:
phdr.phy = PHDR_802_11_PHY_11_DSSS;
break;
case IEEE80211_CHAN_A:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = PHDR_802_11A_HAS_TURBO_TYPE;
phdr.phy_info.info_11a.turbo_type = PHDR_802_11A_TURBO_TYPE_NORMAL;
break;
case IEEE80211_CHAN_B:
phdr.phy = PHDR_802_11_PHY_11B;
phdr.phy_info.info_11b.presence_flags = 0;
if (have_rflags) {
phdr.phy_info.info_11b.presence_flags |= PHDR_802_11B_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11b.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_PUREG:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = PHDR_802_11G_HAS_MODE;
phdr.phy_info.info_11g.mode = PHDR_802_11G_MODE_NORMAL;
if (have_rflags) {
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_G:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = PHDR_802_11G_HAS_MODE;
phdr.phy_info.info_11g.mode = PHDR_802_11G_MODE_NORMAL;
if (have_rflags) {
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_108A:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = PHDR_802_11A_HAS_TURBO_TYPE;
phdr.phy_info.info_11a.turbo_type = PHDR_802_11A_TURBO_TYPE_DYNAMIC_TURBO;
break;
case IEEE80211_CHAN_108PUREG:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = PHDR_802_11G_HAS_MODE;
phdr.phy_info.info_11g.mode = PHDR_802_11G_MODE_SUPER_G;
if (have_rflags) {
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
}
if (tree) {
gchar *chan_str;
static const int * channel_flags[] = {
&hf_radiotap_channel_flags_turbo,
&hf_radiotap_channel_flags_cck,
&hf_radiotap_channel_flags_ofdm,
&hf_radiotap_channel_flags_2ghz,
&hf_radiotap_channel_flags_5ghz,
&hf_radiotap_channel_flags_passive,
&hf_radiotap_channel_flags_dynamic,
&hf_radiotap_channel_flags_gfsk,
&hf_radiotap_channel_flags_gsm,
&hf_radiotap_channel_flags_sturbo,
&hf_radiotap_channel_flags_half,
&hf_radiotap_channel_flags_quarter,
NULL
};
chan_str = ieee80211_mhz_to_str(freq);
col_add_fstr(pinfo->cinfo,
COL_FREQ_CHAN, "%s", chan_str);
proto_tree_add_uint_format_value(radiotap_tree,
hf_radiotap_channel_frequency,
tvb, offset, 2, freq,
"%s",
chan_str);
g_free(chan_str);
proto_tree_add_bitmask(radiotap_tree, tvb, offset + 2, hf_radiotap_channel_flags, ett_radiotap_channel_flags, channel_flags, ENC_LITTLE_ENDIAN);
radiotap_info->freq = freq;
radiotap_info->flags = cflags;
}
break;
}
case IEEE80211_RADIOTAP_FHSS:
phdr.phy = PHDR_802_11_PHY_11_FHSS;
phdr.phy_info.info_11_fhss.presence_flags =
PHDR_802_11_FHSS_HAS_HOP_SET |
PHDR_802_11_FHSS_HAS_HOP_PATTERN;
phdr.phy_info.info_11_fhss.hop_set = tvb_get_guint8(tvb, offset);
phdr.phy_info.info_11_fhss.hop_pattern = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_item(radiotap_tree,
hf_radiotap_fhss_hopset, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(radiotap_tree,
hf_radiotap_fhss_pattern, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
break;
case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
dbm = (gint8)tvb_get_guint8(tvb, offset);
phdr.presence_flags |= PHDR_802_11_HAS_SIGNAL_DBM;
phdr.signal_dbm = dbm;
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d dBm", dbm);
proto_tree_add_int_format_value(radiotap_tree,
hf_radiotap_dbm_antsignal,
tvb, offset, 1, dbm,
"%d dBm",
dbm);
radiotap_info->dbm_antsignal = dbm;
break;
case IEEE80211_RADIOTAP_DBM_ANTNOISE:
dbm = (gint8) tvb_get_guint8(tvb, offset);
phdr.presence_flags |= PHDR_802_11_HAS_NOISE_DBM;
phdr.noise_dbm = dbm;
if (tree) {
proto_tree_add_int_format_value(radiotap_tree,
hf_radiotap_dbm_antnoise,
tvb, offset, 1, dbm,
"%d dBm",
dbm);
}
radiotap_info->dbm_antnoise = dbm;
break;
case IEEE80211_RADIOTAP_LOCK_QUALITY:
if (tree) {
proto_tree_add_uint(radiotap_tree,
hf_radiotap_quality, tvb,
offset, 2,
tvb_get_letohs(tvb,
offset));
}
break;
case IEEE80211_RADIOTAP_TX_ATTENUATION:
proto_tree_add_item(radiotap_tree,
hf_radiotap_tx_attenuation, tvb,
offset, 2, ENC_BIG_ENDIAN);
break;
case IEEE80211_RADIOTAP_DB_TX_ATTENUATION:
proto_tree_add_item(radiotap_tree,
hf_radiotap_db_tx_attenuation, tvb,
offset, 2, ENC_BIG_ENDIAN);
break;
case IEEE80211_RADIOTAP_DBM_TX_POWER:
if (tree) {
proto_tree_add_int(radiotap_tree,
hf_radiotap_txpower, tvb,
offset, 1,
tvb_get_guint8(tvb, offset));
}
break;
case IEEE80211_RADIOTAP_ANTENNA:
if (tree) {
proto_tree_add_uint(radiotap_tree,
hf_radiotap_antenna, tvb,
offset, 1,
tvb_get_guint8(tvb,
offset));
}
break;
case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
db = tvb_get_guint8(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_RSSI, "%u dB", db);
if (tree) {
proto_tree_add_uint_format_value(radiotap_tree,
hf_radiotap_db_antsignal,
tvb, offset, 1, db,
"%u dB",
db);
}
break;
case IEEE80211_RADIOTAP_DB_ANTNOISE:
db = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint_format_value(radiotap_tree,
hf_radiotap_db_antnoise,
tvb, offset, 1, db,
"%u dB",
db);
}
break;
case IEEE80211_RADIOTAP_RX_FLAGS: {
if (radiotap_bit14_fcs) {
if (tree) {
sent_fcs = tvb_get_ntohl(tvb, offset);
hdr_fcs_ti = proto_tree_add_uint(radiotap_tree,
hf_radiotap_fcs, tvb,
offset, 4, sent_fcs);
hdr_fcs_offset = offset;
}
} else {
static const int * rxflags[] = {
&hf_radiotap_rxflags_badplcp,
NULL
};
proto_tree_add_bitmask(radiotap_tree, tvb, offset, hf_radiotap_rxflags, ett_radiotap_rxflags, rxflags, ENC_LITTLE_ENDIAN);
}
break;
}
case IEEE80211_RADIOTAP_XCHANNEL: {
xcflags = tvb_get_letohl(tvb, offset);
switch (xcflags & IEEE80211_CHAN_ALLTURBO) {
case IEEE80211_CHAN_FHSS:
if (phdr.phy != PHDR_802_11_PHY_11_FHSS) {
phdr.phy = PHDR_802_11_PHY_11_FHSS;
phdr.phy_info.info_11_fhss.presence_flags = 0;
}
break;
case IEEE80211_CHAN_DSSS:
phdr.phy = PHDR_802_11_PHY_11_DSSS;
break;
case IEEE80211_CHAN_A:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = PHDR_802_11A_HAS_TURBO_TYPE;
phdr.phy_info.info_11a.turbo_type = PHDR_802_11A_TURBO_TYPE_NORMAL;
break;
case IEEE80211_CHAN_B:
phdr.phy = PHDR_802_11_PHY_11B;
phdr.phy_info.info_11b.presence_flags = 0;
if (have_rflags) {
phdr.phy_info.info_11b.presence_flags |= PHDR_802_11B_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11b.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_PUREG:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = PHDR_802_11G_HAS_MODE;
phdr.phy_info.info_11g.mode = PHDR_802_11G_MODE_NORMAL;
if (have_rflags) {
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_G:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = PHDR_802_11G_HAS_MODE;
phdr.phy_info.info_11g.mode = PHDR_802_11G_MODE_NORMAL;
if (have_rflags) {
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_108A:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = PHDR_802_11A_HAS_TURBO_TYPE;
phdr.phy_info.info_11a.turbo_type = PHDR_802_11A_TURBO_TYPE_DYNAMIC_TURBO;
break;
case IEEE80211_CHAN_108PUREG:
phdr.phy = PHDR_802_11_PHY_11G;
phdr.phy_info.info_11g.presence_flags = PHDR_802_11G_HAS_MODE;
phdr.phy_info.info_11g.mode = PHDR_802_11G_MODE_SUPER_G;
if (have_rflags) {
phdr.phy_info.info_11g.presence_flags |= PHDR_802_11G_HAS_SHORT_PREAMBLE;
phdr.phy_info.info_11g.short_preamble = (rflags & IEEE80211_RADIOTAP_F_SHORTPRE) != 0;
}
break;
case IEEE80211_CHAN_ST:
phdr.phy = PHDR_802_11_PHY_11A;
phdr.phy_info.info_11a.presence_flags = PHDR_802_11A_HAS_TURBO_TYPE;
phdr.phy_info.info_11a.turbo_type = PHDR_802_11A_TURBO_TYPE_STATIC_TURBO;
break;
case IEEE80211_CHAN_A|IEEE80211_CHAN_HT20:
case IEEE80211_CHAN_A|IEEE80211_CHAN_HT40D:
case IEEE80211_CHAN_A|IEEE80211_CHAN_HT40U:
case IEEE80211_CHAN_G|IEEE80211_CHAN_HT20:
case IEEE80211_CHAN_G|IEEE80211_CHAN_HT40U:
case IEEE80211_CHAN_G|IEEE80211_CHAN_HT40D:
phdr.phy = PHDR_802_11_PHY_11N;
phdr.phy_info.info_11n.presence_flags = 0;
if (have_rflags) {
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_SHORT_GI;
if (rflags & 0x80)
phdr.phy_info.info_11n.short_gi = 1;
else
phdr.phy_info.info_11n.short_gi = 0;
}
break;
}
freq = tvb_get_letohs(tvb, offset + 4);
if (freq != 0) {
phdr.presence_flags |= PHDR_802_11_HAS_FREQUENCY;
phdr.frequency = freq;
}
phdr.presence_flags |= PHDR_802_11_HAS_CHANNEL;
phdr.channel = tvb_get_guint8(tvb, offset + 6);
if (tree) {
static const int * xchannel_flags[] = {
&hf_radiotap_xchannel_flags_turbo,
&hf_radiotap_xchannel_flags_cck,
&hf_radiotap_xchannel_flags_ofdm,
&hf_radiotap_xchannel_flags_2ghz,
&hf_radiotap_xchannel_flags_5ghz,
&hf_radiotap_xchannel_flags_passive,
&hf_radiotap_xchannel_flags_dynamic,
&hf_radiotap_xchannel_flags_gfsk,
&hf_radiotap_xchannel_flags_gsm,
&hf_radiotap_xchannel_flags_sturbo,
&hf_radiotap_xchannel_flags_half,
&hf_radiotap_xchannel_flags_quarter,
&hf_radiotap_xchannel_flags_ht20,
&hf_radiotap_xchannel_flags_ht40u,
&hf_radiotap_xchannel_flags_ht40d,
NULL
};
proto_tree_add_item(radiotap_tree,
hf_radiotap_xchannel_channel,
tvb, offset + 6, 1,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(radiotap_tree,
hf_radiotap_xchannel_frequency,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(radiotap_tree, tvb, offset, hf_radiotap_xchannel_flags, ett_radiotap_xchannel_flags, xchannel_flags, ENC_LITTLE_ENDIAN);
#if 0
proto_tree_add_uint(radiotap_tree,
hf_radiotap_xchannel_maxpower,
tvb, offset + 7, 1, maxpower);
#endif
}
break;
}
case IEEE80211_RADIOTAP_MCS: {
proto_tree *mcs_tree = NULL;
guint8 mcs_known, mcs_flags;
guint8 mcs;
guint bandwidth;
guint gi_length;
gboolean can_calculate_rate;
can_calculate_rate = TRUE;
mcs_known = tvb_get_guint8(tvb, offset);
if (mcs_known != 0) {
phdr.phy = PHDR_802_11_PHY_11N;
phdr.phy_info.info_11n.presence_flags = 0;
}
mcs_flags = tvb_get_guint8(tvb, offset + 1);
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_MCS) {
mcs = tvb_get_guint8(tvb, offset + 2);
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_MCS_INDEX;
phdr.phy_info.info_11n.mcs_index = mcs;
} else {
mcs = 0;
can_calculate_rate = FALSE;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_BW) {
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_BANDWIDTH;
phdr.phy_info.info_11n.bandwidth = (mcs_flags & IEEE80211_RADIOTAP_MCS_BW_MASK);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_GI) {
gi_length = (mcs_flags & IEEE80211_RADIOTAP_MCS_SGI) ?
1 : 0;
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_SHORT_GI;
phdr.phy_info.info_11n.short_gi = (gi_length == 0);
} else {
gi_length = 0;
can_calculate_rate = FALSE;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_FMT) {
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_GREENFIELD;
phdr.phy_info.info_11n.greenfield = (mcs_flags & IEEE80211_RADIOTAP_MCS_FMT_GF) != 0;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_FEC) {
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_FEC;
phdr.phy_info.info_11n.fec = (mcs_flags & IEEE80211_RADIOTAP_MCS_FEC_LDPC) ? 1 : 0;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_STBC) {
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_STBC_STREAMS;
phdr.phy_info.info_11n.stbc_streams = (mcs_flags & IEEE80211_RADIOTAP_MCS_STBC_MASK) >> IEEE80211_RADIOTAP_MCS_STBC_SHIFT;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_NESS) {
phdr.phy_info.info_11n.presence_flags |= PHDR_802_11N_HAS_NESS;
phdr.phy_info.info_11n.ness =
((mcs_known & IEEE80211_RADIOTAP_MCS_NESS_BIT1) >> 6) |
((mcs_flags & IEEE80211_RADIOTAP_MCS_NESS_BIT0) >> 7);
}
if (tree) {
proto_item *it;
static const int * mcs_haves_with_ness_bit1[] = {
&hf_radiotap_mcs_have_bw,
&hf_radiotap_mcs_have_index,
&hf_radiotap_mcs_have_gi,
&hf_radiotap_mcs_have_format,
&hf_radiotap_mcs_have_fec,
&hf_radiotap_mcs_have_stbc,
&hf_radiotap_mcs_have_ness,
&hf_radiotap_mcs_ness_bit1,
NULL
};
static const int * mcs_haves_without_ness_bit1[] = {
&hf_radiotap_mcs_have_bw,
&hf_radiotap_mcs_have_index,
&hf_radiotap_mcs_have_gi,
&hf_radiotap_mcs_have_format,
&hf_radiotap_mcs_have_fec,
&hf_radiotap_mcs_have_stbc,
&hf_radiotap_mcs_have_ness,
NULL
};
it = proto_tree_add_item(radiotap_tree, hf_radiotap_mcs,
tvb, offset, 3, ENC_NA);
mcs_tree = proto_item_add_subtree(it, ett_radiotap_mcs);
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_NESS)
proto_tree_add_bitmask(mcs_tree, tvb, offset, hf_radiotap_mcs_known, ett_radiotap_mcs_known, mcs_haves_with_ness_bit1, ENC_LITTLE_ENDIAN);
else
proto_tree_add_bitmask(mcs_tree, tvb, offset, hf_radiotap_mcs_known, ett_radiotap_mcs_known, mcs_haves_without_ness_bit1, ENC_LITTLE_ENDIAN);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_BW) {
bandwidth = ((mcs_flags & IEEE80211_RADIOTAP_MCS_BW_MASK) == IEEE80211_RADIOTAP_MCS_BW_40) ?
1 : 0;
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_bw,
tvb, offset + 1, 1, mcs_flags);
} else {
bandwidth = 0;
can_calculate_rate = FALSE;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_GI) {
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_gi,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_FMT) {
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_format,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_FEC) {
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_fec,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_STBC) {
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_stbc,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_NESS) {
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_ness_bit0,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_MCS) {
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_index,
tvb, offset + 2, 1, mcs);
}
if (can_calculate_rate && mcs <= MAX_MCS_INDEX
&& ieee80211_float_htrates[mcs][bandwidth][gi_length] != 0.0) {
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%.1f",
ieee80211_float_htrates[mcs][bandwidth][gi_length]);
if (tree) {
rate_ti = proto_tree_add_float_format(radiotap_tree,
hf_radiotap_datarate,
tvb, offset, 3,
ieee80211_float_htrates[mcs][bandwidth][gi_length],
"Data Rate: %.1f Mb/s",
ieee80211_float_htrates[mcs][bandwidth][gi_length]);
PROTO_ITEM_SET_GENERATED(rate_ti);
}
}
break;
}
case IEEE80211_RADIOTAP_AMPDU_STATUS: {
proto_item *it;
proto_tree *ampdu_tree = NULL, *ampdu_flags_tree;
guint16 ampdu_flags;
ampdu_flags = tvb_get_letohs(tvb, offset + 4);
if (tree) {
it = proto_tree_add_item(radiotap_tree, hf_radiotap_ampdu,
tvb, offset, 8, ENC_NA);
ampdu_tree = proto_item_add_subtree(it, ett_radiotap_ampdu);
proto_tree_add_item(ampdu_tree, hf_radiotap_ampdu_ref,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
it = proto_tree_add_item(ampdu_tree, hf_radiotap_ampdu_flags,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
ampdu_flags_tree = proto_item_add_subtree(it, ett_radiotap_ampdu_flags);
proto_tree_add_item(ampdu_flags_tree, hf_radiotap_ampdu_flags_report_zerolen,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ampdu_flags_tree, hf_radiotap_ampdu_flags_is_zerolen,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ampdu_flags_tree, hf_radiotap_ampdu_flags_last_known,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ampdu_flags_tree, hf_radiotap_ampdu_flags_is_last,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ampdu_flags_tree, hf_radiotap_ampdu_flags_delim_crc_error,
tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
}
if (ampdu_flags & IEEE80211_RADIOTAP_AMPDU_DELIM_CRC_KNOWN) {
if (ampdu_tree)
proto_tree_add_item(ampdu_tree, hf_radiotap_ampdu_delim_crc,
tvb, offset + 6, 1, ENC_NA);
}
break;
}
case IEEE80211_RADIOTAP_VHT: {
proto_item *it, *it_root = NULL;
proto_tree *vht_tree = NULL, *vht_known_tree = NULL, *user_tree = NULL;
guint16 known;
guint8 vht_flags, bw, mcs_nss;
guint bandwidth = 0;
guint gi_length = 0;
guint nss = 0;
guint mcs = 0;
gboolean can_calculate_rate;
guint i;
can_calculate_rate = TRUE;
known = tvb_get_letohs(tvb, offset);
if (known != 0) {
phdr.phy = PHDR_802_11_PHY_11AC;
phdr.phy_info.info_11ac.presence_flags = 0;
}
vht_flags = tvb_get_guint8(tvb, offset + 2);
if (tree) {
it_root = proto_tree_add_item(radiotap_tree, hf_radiotap_vht,
tvb, offset, 12, ENC_NA);
vht_tree = proto_item_add_subtree(it_root, ett_radiotap_vht);
it = proto_tree_add_item(vht_tree, hf_radiotap_vht_known,
tvb, offset, 2, known);
vht_known_tree = proto_item_add_subtree(it, ett_radiotap_vht_known);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_stbc,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_txop_ps,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_gi,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_sgi_nsym_da,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_ldpc_extra,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_bf,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_bw,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_gid,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(vht_known_tree, hf_radiotap_vht_have_p_aid,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_STBC) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_STBC;
phdr.phy_info.info_11ac.stbc = (vht_flags & IEEE80211_RADIOTAP_VHT_STBC) != 0;
if (vht_tree)
proto_tree_add_item(vht_tree, hf_radiotap_vht_stbc,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_TXOP_PS) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_TXOP_PS_NOT_ALLOWED;
phdr.phy_info.info_11ac.txop_ps_not_allowed = (vht_flags & IEEE80211_RADIOTAP_VHT_TXOP_PS) != 0;
if (vht_tree)
proto_tree_add_item(vht_tree, hf_radiotap_vht_txop_ps,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_GI) {
gi_length = (vht_flags & IEEE80211_RADIOTAP_VHT_SGI) ? 1 : 0;
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_SHORT_GI;
phdr.phy_info.info_11ac.short_gi = gi_length;
if (vht_tree) {
proto_tree_add_item(vht_tree, hf_radiotap_vht_gi,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
} else {
can_calculate_rate = FALSE;
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_SGI_NSYM_DA) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_SHORT_GI_NSYM_DISAMBIG;
phdr.phy_info.info_11ac.short_gi_nsym_disambig = (vht_flags & IEEE80211_RADIOTAP_VHT_SGI_NSYM_DA) != 0;
if (vht_tree) {
it = proto_tree_add_item(vht_tree, hf_radiotap_vht_sgi_nsym_da,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
if ((vht_flags & IEEE80211_RADIOTAP_VHT_SGI_NSYM_DA) &&
(known & IEEE80211_RADIOTAP_VHT_HAVE_GI) &&
!(vht_flags & IEEE80211_RADIOTAP_VHT_SGI))
proto_item_append_text(it, " (invalid)");
}
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_LDPC_EXTRA) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_LDPC_EXTRA_OFDM_SYMBOL;
phdr.phy_info.info_11ac.ldpc_extra_ofdm_symbol = (vht_flags & IEEE80211_RADIOTAP_VHT_LDPC_EXTRA) != 0;
if (vht_tree) {
proto_tree_add_item(vht_tree, hf_radiotap_vht_ldpc_extra,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_BF) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_BEAMFORMED;
phdr.phy_info.info_11ac.beamformed = (vht_flags & IEEE80211_RADIOTAP_VHT_BF) != 0;
if (vht_tree)
proto_tree_add_item(vht_tree, hf_radiotap_vht_bf,
tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_BW) {
bw = tvb_get_guint8(tvb, offset + 3) & IEEE80211_RADIOTAP_VHT_BW_MASK;
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_BANDWIDTH;
phdr.phy_info.info_11ac.bandwidth = bw;
if (bw < sizeof(ieee80211_vht_bw2rate_index)/sizeof(ieee80211_vht_bw2rate_index[0]))
bandwidth = ieee80211_vht_bw2rate_index[bw];
else
can_calculate_rate = FALSE;
if (vht_tree)
proto_tree_add_item(vht_tree, hf_radiotap_vht_bw,
tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
} else {
can_calculate_rate = FALSE;
}
for(i=0; i<4; i++) {
mcs_nss = tvb_get_guint8(tvb, offset + 4 + i);
nss = (mcs_nss & IEEE80211_RADIOTAP_VHT_NSS);
mcs = (mcs_nss & IEEE80211_RADIOTAP_VHT_MCS) >> 4;
phdr.phy_info.info_11ac.mcs[i] = mcs;
phdr.phy_info.info_11ac.nss[i] = nss;
if (nss) {
if (phdr.phy != PHDR_802_11_PHY_11AC) {
phdr.phy = PHDR_802_11_PHY_11AC;
phdr.phy_info.info_11ac.presence_flags = 0;
}
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_FEC;
if (vht_tree) {
it = proto_tree_add_item(vht_tree, hf_radiotap_vht_user,
tvb, offset + 4, 5, ENC_NA);
proto_item_append_text(it, " %d: MCS %u", i, mcs);
user_tree = proto_item_add_subtree(it, ett_radiotap_vht_user);
it = proto_tree_add_item(user_tree, hf_radiotap_vht_mcs[i],
tvb, offset + 4 + i, 1,
ENC_LITTLE_ENDIAN);
if (mcs > MAX_MCS_VHT_INDEX) {
proto_item_append_text(it, " (invalid)");
} else {
proto_item_append_text(it, " (%s %s)",
ieee80211_vhtinfo[mcs].modulation,
ieee80211_vhtinfo[mcs].coding_rate);
}
proto_tree_add_item(user_tree, hf_radiotap_vht_nss[i],
tvb, offset + 4 + i, 1, ENC_LITTLE_ENDIAN);
if (known & IEEE80211_RADIOTAP_VHT_HAVE_STBC) {
guint nsts;
proto_item *nsts_ti;
if (vht_flags & IEEE80211_RADIOTAP_VHT_STBC)
nsts = 2 * nss;
else
nsts = nss;
nsts_ti = proto_tree_add_uint(user_tree, hf_radiotap_vht_nsts[i],
tvb, offset + 4 + i, 1, nsts);
PROTO_ITEM_SET_GENERATED(nsts_ti);
}
proto_tree_add_item(user_tree, hf_radiotap_vht_coding[i],
tvb, offset + 8, 1,ENC_LITTLE_ENDIAN);
}
if (can_calculate_rate && mcs <= MAX_MCS_VHT_INDEX) {
float rate = ieee80211_vhtinfo[mcs].rates[bandwidth][gi_length] * nss;
if (rate != 0.0f && user_tree) {
rate_ti = proto_tree_add_float_format(user_tree,
hf_radiotap_vht_datarate[i],
tvb, offset, 12, rate,
"Data Rate: %.1f Mb/s", rate);
PROTO_ITEM_SET_GENERATED(rate_ti);
}
}
}
}
phdr.phy_info.info_11ac.fec = tvb_get_guint8(tvb, offset + 8);
if (known & IEEE80211_RADIOTAP_VHT_HAVE_GID) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_GROUP_ID;
phdr.phy_info.info_11ac.group_id = tvb_get_guint8(tvb, offset + 9);
if (vht_tree)
proto_tree_add_item(vht_tree, hf_radiotap_vht_gid,
tvb, offset+9, 1, ENC_LITTLE_ENDIAN);
}
if (known & IEEE80211_RADIOTAP_VHT_HAVE_PAID) {
phdr.phy_info.info_11ac.presence_flags |= PHDR_802_11AC_HAS_PARTIAL_AID;
phdr.phy_info.info_11ac.partial_aid = tvb_get_letohs(tvb, offset + 10);
if (vht_tree) {
proto_tree_add_item(vht_tree, hf_radiotap_vht_p_aid,
tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
}
}
break;
}
}
}
if (err != -ENOENT && tree) {
expert_add_info(pinfo, pt, &ei_radiotap_data_past_header);
malformed:
proto_item_append_text(ti, " (malformed)");
}
hand_off_to_80211:
next_tvb = tvb_new_subset_remaining(tvb, length);
if (hdr_fcs_ti) {
guint captured_length = tvb_captured_length(next_tvb);
guint reported_length = tvb_reported_length(next_tvb);
guint fcs_len = (phdr.fcs_len > 0) ? phdr.fcs_len : 0;
if (captured_length >= reported_length &&
captured_length > fcs_len) {
calc_fcs =
crc32_802_tvb(next_tvb, tvb_captured_length(next_tvb) - fcs_len);
if (calc_fcs == sent_fcs) {
proto_item_append_text(hdr_fcs_ti,
" [correct]");
} else {
proto_item_append_text(hdr_fcs_ti,
" [incorrect, should be 0x%08x]",
calc_fcs);
hidden_item =
proto_tree_add_boolean(radiotap_tree,
hf_radiotap_fcs_bad,
tvb, hdr_fcs_offset,
4, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
} else {
proto_item_append_text(hdr_fcs_ti,
" [cannot verify - not enough data]");
}
}
call_dissector_with_data(ieee80211_radio_handle, next_tvb, pinfo,
tree, &phdr);
tap_queue_packet(radiotap_tap, pinfo, radiotap_info);
}
void proto_register_radiotap(void)
{
static hf_register_info hf[] = {
{&hf_radiotap_version,
{"Header revision", "radiotap.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Version of radiotap header format", HFILL}},
{&hf_radiotap_pad,
{"Header pad", "radiotap.pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Padding", HFILL}},
{&hf_radiotap_length,
{"Header length", "radiotap.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of header including version, pad, length and data fields", HFILL}},
{&hf_radiotap_present,
{"Present flags", "radiotap.present",
FT_NONE, BASE_NONE, NULL, 0x0,
"Bitmask indicating which fields are present", HFILL}},
#define RADIOTAP_MASK(name) BIT(IEEE80211_RADIOTAP_ ##name)
{&hf_radiotap_present_tsft,
{"TSFT", "radiotap.present.tsft",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(TSFT),
"Specifies if the Time Synchronization Function Timer field is present", HFILL}},
{&hf_radiotap_present_flags,
{"Flags", "radiotap.present.flags",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(FLAGS),
"Specifies if the channel flags field is present", HFILL}},
{&hf_radiotap_present_rate,
{"Rate", "radiotap.present.rate",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(RATE),
"Specifies if the transmit/receive rate field is present", HFILL}},
{&hf_radiotap_present_channel,
{"Channel", "radiotap.present.channel",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(CHANNEL),
"Specifies if the transmit/receive frequency field is present", HFILL}},
{&hf_radiotap_present_fhss,
{"FHSS", "radiotap.present.fhss",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(FHSS),
"Specifies if the hop set and pattern is present for frequency hopping radios", HFILL}},
{&hf_radiotap_present_dbm_antsignal,
{"dBm Antenna Signal", "radiotap.present.dbm_antsignal",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(DBM_ANTSIGNAL),
"Specifies if the antenna signal strength in dBm is present", HFILL}},
{&hf_radiotap_present_dbm_antnoise,
{"dBm Antenna Noise", "radiotap.present.dbm_antnoise",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(DBM_ANTNOISE),
"Specifies if the RF noise power at antenna field is present", HFILL}},
{&hf_radiotap_present_lock_quality,
{"Lock Quality", "radiotap.present.lock_quality",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(LOCK_QUALITY),
"Specifies if the signal quality field is present", HFILL}},
{&hf_radiotap_present_tx_attenuation,
{"TX Attenuation", "radiotap.present.tx_attenuation",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(TX_ATTENUATION),
"Specifies if the transmit power distance from max power field is present", HFILL}},
{&hf_radiotap_present_db_tx_attenuation,
{"dB TX Attenuation", "radiotap.present.db_tx_attenuation",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(DB_TX_ATTENUATION),
"Specifies if the transmit power distance from max power (in dB) field is present", HFILL}},
{&hf_radiotap_present_dbm_tx_power,
{"dBm TX Power", "radiotap.present.dbm_tx_power",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(DBM_TX_POWER),
"Specifies if the transmit power (in dBm) field is present", HFILL}},
{&hf_radiotap_present_antenna,
{"Antenna", "radiotap.present.antenna",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(ANTENNA),
"Specifies if the antenna number field is present", HFILL}},
{&hf_radiotap_present_db_antsignal,
{"dB Antenna Signal", "radiotap.present.db_antsignal",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(DB_ANTSIGNAL),
"Specifies if the RF signal power at antenna in dB field is present", HFILL}},
{&hf_radiotap_present_db_antnoise,
{"dB Antenna Noise", "radiotap.present.db_antnoise",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(DB_ANTNOISE),
"Specifies if the RF signal power at antenna in dBm field is present", HFILL}},
{&hf_radiotap_present_rxflags,
{"RX flags", "radiotap.present.rxflags",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(RX_FLAGS),
"Specifies if the RX flags field is present", HFILL}},
{&hf_radiotap_present_hdrfcs,
{"FCS in header", "radiotap.present.fcs",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(RX_FLAGS),
"Specifies if the FCS field is present", HFILL}},
{&hf_radiotap_present_xchannel,
{"Channel+", "radiotap.present.xchannel",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(XCHANNEL),
"Specifies if the extended channel info field is present", HFILL}},
{&hf_radiotap_present_mcs,
{"MCS information", "radiotap.present.mcs",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(MCS),
"Specifies if the MCS field is present", HFILL}},
{&hf_radiotap_present_ampdu,
{"A-MPDU Status", "radiotap.present.ampdu",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(AMPDU_STATUS),
"Specifies if the A-MPDU status field is present", HFILL}},
{&hf_radiotap_present_vht,
{"VHT information", "radiotap.present.vht",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(VHT),
"Specifies if the VHT field is present", HFILL}},
{&hf_radiotap_present_reserved,
{"Reserved", "radiotap.present.reserved",
FT_UINT32, BASE_HEX, NULL, IEEE80211_RADIOTAP_NOTDEFINED,
"Not (yet) defined present flags (Must be zero)", HFILL}},
{&hf_radiotap_present_rtap_ns,
{"Radiotap NS next", "radiotap.present.rtap_ns",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(RADIOTAP_NAMESPACE),
"Specifies a reset to the radiotap namespace", HFILL}},
{&hf_radiotap_present_vendor_ns,
{"Vendor NS next", "radiotap.present.vendor_ns",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(VENDOR_NAMESPACE),
"Specifies that the next bitmap is in a vendor namespace", HFILL}},
{&hf_radiotap_present_ext,
{"Ext", "radiotap.present.ext",
FT_BOOLEAN, 32, TFS(&tfs_present_absent), RADIOTAP_MASK(EXT),
"Specifies if there are any extensions to the header present", HFILL}},
{&hf_radiotap_flags,
{"Flags", "radiotap.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{&hf_radiotap_flags_cfp,
{"CFP", "radiotap.flags.cfp",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_CFP,
"Sent/Received during CFP", HFILL}},
{&hf_radiotap_flags_preamble,
{"Preamble", "radiotap.flags.preamble",
FT_BOOLEAN, 8, TFS(&preamble_type),
IEEE80211_RADIOTAP_F_SHORTPRE,
"Sent/Received with short preamble", HFILL}},
{&hf_radiotap_flags_wep,
{"WEP", "radiotap.flags.wep",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_WEP,
"Sent/Received with WEP encryption", HFILL}},
{&hf_radiotap_flags_frag,
{"Fragmentation", "radiotap.flags.frag",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_FRAG,
"Sent/Received with fragmentation", HFILL}},
{&hf_radiotap_flags_fcs,
{"FCS at end", "radiotap.flags.fcs",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_FCS,
"Frame includes FCS at end", HFILL}},
{&hf_radiotap_flags_datapad,
{"Data Pad", "radiotap.flags.datapad",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_DATAPAD,
"Frame has padding between 802.11 header and payload", HFILL}},
{&hf_radiotap_flags_badfcs,
{"Bad FCS", "radiotap.flags.badfcs",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_BADFCS,
"Frame received with bad FCS", HFILL}},
{&hf_radiotap_flags_shortgi,
{"Short GI", "radiotap.flags.shortgi",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_F_SHORTGI,
"Frame Sent/Received with HT short Guard Interval", HFILL}},
{&hf_radiotap_mactime,
{"MAC timestamp", "radiotap.mactime",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Value in microseconds of the MAC's Time Synchronization Function timer"
" when the first bit of the MPDU arrived at the MAC.",
HFILL}},
{&hf_radiotap_quality,
{"Signal Quality", "radiotap.quality",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Signal quality (unitless measure)", HFILL}},
{&hf_radiotap_fcs,
{"802.11 FCS", "radiotap.fcs",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Frame check sequence of this frame", HFILL}},
#if 0
{&hf_radiotap_channel,
{"Channel", "radiotap.channel",
FT_UINT32, BASE_DEC, NULL, 0x0,
"802.11 channel number that this frame was sent/received on", HFILL}},
#endif
{&hf_radiotap_channel_frequency,
{"Channel frequency", "radiotap.channel.freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Channel frequency in megahertz that this frame was sent/received on", HFILL}},
{&hf_radiotap_channel_flags,
{"Channel flags", "radiotap.channel.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_channel_flags_turbo,
{"Turbo", "radiotap.channel.flags.turbo",
FT_BOOLEAN, 16, NULL, 0x0010, "Channel Flags Turbo", HFILL}},
{&hf_radiotap_channel_flags_cck,
{"Complementary Code Keying (CCK)", "radiotap.channel.flags.cck",
FT_BOOLEAN, 16, NULL, 0x0020,
"Channel Flags Complementary Code Keying (CCK) Modulation", HFILL}},
{&hf_radiotap_channel_flags_ofdm,
{"Orthogonal Frequency-Division Multiplexing (OFDM)", "radiotap.channel.flags.ofdm",
FT_BOOLEAN, 16, NULL, 0x0040,
"Channel Flags Orthogonal Frequency-Division Multiplexing (OFDM)", HFILL}},
{&hf_radiotap_channel_flags_2ghz,
{"2 GHz spectrum", "radiotap.channel.flags.2ghz",
FT_BOOLEAN, 16, NULL, 0x0080, "Channel Flags 2 GHz spectrum", HFILL}},
{&hf_radiotap_channel_flags_5ghz,
{"5 GHz spectrum", "radiotap.channel.flags.5ghz",
FT_BOOLEAN, 16, NULL, 0x0100, "Channel Flags 5 GHz spectrum", HFILL}},
{&hf_radiotap_channel_flags_passive,
{"Passive", "radiotap.channel.flags.passive",
FT_BOOLEAN, 16, NULL, 0x0200,
"Channel Flags Passive", HFILL}},
{&hf_radiotap_channel_flags_dynamic,
{"Dynamic CCK-OFDM", "radiotap.channel.flags.dynamic",
FT_BOOLEAN, 16, NULL, 0x0400,
"Channel Flags Dynamic CCK-OFDM Channel", HFILL}},
{&hf_radiotap_channel_flags_gfsk,
{"Gaussian Frequency Shift Keying (GFSK)", "radiotap.channel.flags.gfsk",
FT_BOOLEAN, 16, NULL, 0x0800,
"Channel Flags Gaussian Frequency Shift Keying (GFSK) Modulation", HFILL}},
{&hf_radiotap_channel_flags_gsm,
{"GSM (900MHz)", "radiotap.channel.flags.gsm",
FT_BOOLEAN, 16, NULL, 0x1000,
"Channel Flags GSM", HFILL}},
{&hf_radiotap_channel_flags_sturbo,
{"Static Turbo", "radiotap.channel.flags.sturbo",
FT_BOOLEAN, 16, NULL, 0x2000,
"Channel Flags Status Turbo", HFILL}},
{&hf_radiotap_channel_flags_half,
{"Half Rate Channel (10MHz Channel Width)", "radiotap.channel.flags.half",
FT_BOOLEAN, 16, NULL, 0x4000,
"Channel Flags Half Rate", HFILL}},
{&hf_radiotap_channel_flags_quarter,
{"Quarter Rate Channel (5MHz Channel Width)", "radiotap.channel.flags.quarter",
FT_BOOLEAN, 16, NULL, 0x8000,
"Channel Flags Quarter Rate", HFILL}},
{&hf_radiotap_rxflags,
{"RX flags", "radiotap.rxflags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_rxflags_badplcp,
{"Bad PLCP", "radiotap.rxflags.badplcp",
FT_BOOLEAN, 24, NULL, IEEE80211_RADIOTAP_F_RX_BADPLCP,
"Frame with bad PLCP", HFILL}},
{&hf_radiotap_xchannel_channel,
{"Channel number", "radiotap.xchannel.channel",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_xchannel_frequency,
{"Channel frequency", "radiotap.xchannel.freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_xchannel_flags,
{"Channel flags", "radiotap.xchannel.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_xchannel_flags_turbo,
{"Turbo", "radiotap.xchannel.flags.turbo",
FT_BOOLEAN, 24, NULL, 0x0010,
"Channel Flags Turbo", HFILL}},
{&hf_radiotap_xchannel_flags_cck,
{"Complementary Code Keying (CCK)", "radiotap.xchannel.flags.cck",
FT_BOOLEAN, 24, NULL, 0x0020,
"Channel Flags Complementary Code Keying (CCK) Modulation", HFILL}},
{&hf_radiotap_xchannel_flags_ofdm,
{"Orthogonal Frequency-Division Multiplexing (OFDM)", "radiotap.xchannel.flags.ofdm",
FT_BOOLEAN, 24, NULL, 0x0040,
"Channel Flags Orthogonal Frequency-Division Multiplexing (OFDM)", HFILL}},
{&hf_radiotap_xchannel_flags_2ghz,
{"2 GHz spectrum", "radiotap.xchannel.flags.2ghz",
FT_BOOLEAN, 24, NULL, 0x0080,
"Channel Flags 2 GHz spectrum", HFILL}},
{&hf_radiotap_xchannel_flags_5ghz,
{"5 GHz spectrum", "radiotap.xchannel.flags.5ghz",
FT_BOOLEAN, 24, NULL, 0x0100,
"Channel Flags 5 GHz spectrum", HFILL}},
{&hf_radiotap_xchannel_flags_passive,
{"Passive", "radiotap.channel.xtype.passive",
FT_BOOLEAN, 24, NULL, 0x0200,
"Channel Flags Passive", HFILL}},
{&hf_radiotap_xchannel_flags_dynamic,
{"Dynamic CCK-OFDM", "radiotap.xchannel.flags.dynamic",
FT_BOOLEAN, 24, NULL, 0x0400,
"Channel Flags Dynamic CCK-OFDM Channel", HFILL}},
{&hf_radiotap_xchannel_flags_gfsk,
{"Gaussian Frequency Shift Keying (GFSK)",
"radiotap.xchannel.flags.gfsk",
FT_BOOLEAN, 24, NULL, 0x0800,
"Channel Flags Gaussian Frequency Shift Keying (GFSK) Modulation",
HFILL}},
{&hf_radiotap_xchannel_flags_gsm,
{"GSM (900MHz)", "radiotap.xchannel.flags.gsm",
FT_BOOLEAN, 24, NULL, 0x1000,
"Channel Flags GSM", HFILL}},
{&hf_radiotap_xchannel_flags_sturbo,
{"Static Turbo", "radiotap.xchannel.flags.sturbo",
FT_BOOLEAN, 24, NULL, 0x2000,
"Channel Flags Status Turbo", HFILL}},
{&hf_radiotap_xchannel_flags_half,
{"Half Rate Channel (10MHz Channel Width)", "radiotap.xchannel.flags.half",
FT_BOOLEAN, 24, NULL, 0x4000,
"Channel Flags Half Rate", HFILL}},
{&hf_radiotap_xchannel_flags_quarter,
{"Quarter Rate Channel (5MHz Channel Width)", "radiotap.xchannel.flags.quarter",
FT_BOOLEAN, 24, NULL, 0x8000,
"Channel Flags Quarter Rate", HFILL}},
{&hf_radiotap_xchannel_flags_ht20,
{"HT Channel (20MHz Channel Width)", "radiotap.xchannel.flags.ht20",
FT_BOOLEAN, 24, NULL, 0x10000,
"Channel Flags HT/20", HFILL}},
{&hf_radiotap_xchannel_flags_ht40u,
{"HT Channel (40MHz Channel Width with Extension channel above)", "radiotap.xchannel.flags.ht40u",
FT_BOOLEAN, 24, NULL, 0x20000,
"Channel Flags HT/40+", HFILL}},
{&hf_radiotap_xchannel_flags_ht40d,
{"HT Channel (40MHz Channel Width with Extension channel below)", "radiotap.xchannel.flags.ht40d",
FT_BOOLEAN, 24, NULL, 0x40000,
"Channel Flags HT/40-", HFILL}},
#if 0
{&hf_radiotap_xchannel_maxpower,
{"Max transmit power", "radiotap.xchannel.maxpower",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#endif
{&hf_radiotap_fhss_hopset,
{"FHSS Hop Set", "radiotap.fhss.hopset",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Frequency Hopping Spread Spectrum hopset", HFILL}},
{&hf_radiotap_fhss_pattern,
{"FHSS Pattern", "radiotap.fhss.pattern",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Frequency Hopping Spread Spectrum hop pattern", HFILL}},
{&hf_radiotap_datarate,
{"Data rate (Mb/s)", "radiotap.datarate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Speed this frame was sent/received at", HFILL}},
{&hf_radiotap_antenna,
{"Antenna", "radiotap.antenna",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Antenna number this frame was sent/received over (starting at 0)", HFILL}},
{&hf_radiotap_dbm_antsignal,
{"SSI Signal", "radiotap.dbm_antsignal",
FT_INT32, BASE_DEC, NULL, 0x0,
"RF signal power at the antenna from a fixed,"
" arbitrary value in decibels from one milliwatt", HFILL}},
{&hf_radiotap_db_antsignal,
{"SSI Signal", "radiotap.db_antsignal",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RF signal power at the antenna from a fixed, arbitrary value in decibels", HFILL}},
{&hf_radiotap_dbm_antnoise,
{"SSI Noise", "radiotap.dbm_antnoise",
FT_INT32, BASE_DEC, NULL, 0x0,
"RF noise power at the antenna from a fixed, arbitrary value"
" in decibels per one milliwatt", HFILL}},
{&hf_radiotap_db_antnoise,
{"SSI Noise", "radiotap.db_antnoise",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RF noise power at the antenna from a fixed, arbitrary value"
" in decibels", HFILL}},
{&hf_radiotap_tx_attenuation,
{"Transmit attenuation", "radiotap.txattenuation",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Transmit power expressed as unitless distance from max power"
" set at factory (0 is max power)", HFILL}},
{&hf_radiotap_db_tx_attenuation,
{"Transmit attenuation (dB)", "radiotap.db_txattenuation",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Transmit power expressed as decibels from max power"
" set at factory (0 is max power)", HFILL}},
{&hf_radiotap_txpower,
{"Transmit power", "radiotap.txpower",
FT_INT32, BASE_DEC, NULL, 0x0,
"Transmit power in decibels per one milliwatt (dBm)", HFILL}},
{&hf_radiotap_mcs,
{"MCS information", "radiotap.mcs",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_mcs_known,
{"Known MCS information", "radiotap.mcs.known",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Bit mask indicating what MCS information is present", HFILL}},
{&hf_radiotap_mcs_have_bw,
{"Bandwidth", "radiotap.mcs.have_bw",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_BW,
"Bandwidth information present", HFILL}},
{&hf_radiotap_mcs_have_index,
{"MCS index", "radiotap.mcs.have_index",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_MCS,
"MCS index information present", HFILL}},
{&hf_radiotap_mcs_have_gi,
{"Guard interval", "radiotap.mcs.have_gi",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_GI,
"Sent/Received guard interval information present", HFILL}},
{&hf_radiotap_mcs_have_format,
{"Format", "radiotap.mcs.have_format",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_FMT,
"Format information present", HFILL}},
{&hf_radiotap_mcs_have_fec,
{"FEC type", "radiotap.mcs.have_fec",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_FEC,
"Forward error correction type information present", HFILL}},
{&hf_radiotap_mcs_have_stbc,
{"STBC streams", "radiotap.mcs.have_stbc",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_STBC,
"Space Time Block Coding streams information present", HFILL}},
{&hf_radiotap_mcs_have_ness,
{"Number of extension spatial streams", "radiotap.mcs.have_ness",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_MCS_HAVE_NESS,
"Number of extension spatial streams information present", HFILL}},
{&hf_radiotap_mcs_ness_bit1,
{"Number of extension spatial streams bit 1", "radiotap.mcs.ness_bit1",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_MCS_NESS_BIT1,
"Bit 1 of number of extension spatial streams information", HFILL}},
{&hf_radiotap_mcs_bw,
{"Bandwidth", "radiotap.mcs.bw",
FT_UINT8, BASE_DEC, VALS(mcs_bandwidth),
IEEE80211_RADIOTAP_MCS_BW_MASK, NULL, HFILL}},
{&hf_radiotap_mcs_gi,
{"Guard interval", "radiotap.mcs.gi",
FT_UINT8, BASE_DEC, VALS(mcs_gi), IEEE80211_RADIOTAP_MCS_SGI,
"Sent/Received guard interval", HFILL}},
{&hf_radiotap_mcs_format,
{"Format", "radiotap.mcs.format",
FT_UINT8, BASE_DEC, VALS(mcs_format), IEEE80211_RADIOTAP_MCS_FMT_GF,
NULL, HFILL}},
{&hf_radiotap_mcs_fec,
{"FEC type", "radiotap.mcs.fec",
FT_UINT8, BASE_DEC, VALS(mcs_fec), IEEE80211_RADIOTAP_MCS_FEC_LDPC,
"Forward error correction type", HFILL}},
{&hf_radiotap_mcs_stbc,
{"STBC streams", "radiotap.mcs.stbc",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_MCS_STBC_MASK,
"Number of Space Time Block Code streams", HFILL}},
{&hf_radiotap_mcs_ness_bit0,
{"Number of extension spatial streams bit 0", "radiotap.mcs.ness_bit1",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_MCS_NESS_BIT1,
"Bit 0 of number of extension spatial streams information", HFILL}},
{&hf_radiotap_mcs_index,
{"MCS index", "radiotap.mcs.index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_ampdu,
{"A-MPDU status", "radiotap.ampdu",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_ampdu_ref,
{"A-MPDU reference number", "radiotap.ampdu.reference",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_ampdu_flags,
{"A-MPDU flags", "radiotap.ampdu.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"A-MPDU status flags", HFILL}},
{&hf_radiotap_ampdu_flags_report_zerolen,
{"Driver reports 0-length subframes in this A-MPDU", "radiotap.ampdu.flags.report_zerolen",
FT_BOOLEAN, 16, NULL, IEEE80211_RADIOTAP_AMPDU_REPORT_ZEROLEN,
NULL, HFILL}},
{&hf_radiotap_ampdu_flags_is_zerolen,
{"This is a 0-length subframe", "radiotap.ampdu.flags.is_zerolen",
FT_BOOLEAN, 16, NULL, IEEE80211_RADIOTAP_AMPDU_IS_ZEROLEN,
NULL, HFILL}},
{&hf_radiotap_ampdu_flags_last_known,
{"Last subframe of this A-MPDU is known", "radiotap.ampdu.flags.lastknown",
FT_BOOLEAN, 16, NULL, IEEE80211_RADIOTAP_AMPDU_LAST_KNOWN,
NULL, HFILL}},
{&hf_radiotap_ampdu_flags_is_last,
{"This is the last subframe of this A-MPDU", "radiotap.ampdu.flags.last",
FT_BOOLEAN, 16, NULL, IEEE80211_RADIOTAP_AMPDU_IS_LAST,
NULL, HFILL}},
{&hf_radiotap_ampdu_flags_delim_crc_error,
{"Delimiter CRC error on this subframe", "radiotap.ampdu.flags.delim_crc_error",
FT_BOOLEAN, 16, NULL, IEEE80211_RADIOTAP_AMPDU_DELIM_CRC_ERR,
NULL, HFILL}},
{&hf_radiotap_ampdu_delim_crc,
{"A-MPDU subframe delimiter CRC", "radiotap.ampdu.delim_crc",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_vht,
{"VHT information", "radiotap.vht",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_vht_known,
{"Known VHT information", "radiotap.vht.known",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Bit mask indicating what VHT information is present", HFILL}},
{&hf_radiotap_vht_user,
{"User", "radiotap.vht.user",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_vht_have_stbc,
{"STBC", "radiotap.vht.have_stbc",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_STBC,
"Space Time Block Coding information present", HFILL}},
{&hf_radiotap_vht_have_txop_ps,
{"TXOP_PS_NOT_ALLOWED", "radiotap.vht.have_txop_ps",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_TXOP_PS,
"TXOP_PS_NOT_ALLOWED information present", HFILL}},
{&hf_radiotap_vht_have_gi,
{"Guard interval", "radiotap.vht.have_gi",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_GI,
"Short/Long guard interval information present", HFILL}},
{&hf_radiotap_vht_have_sgi_nsym_da,
{"SGI Nsym disambiguation", "radiotap.vht.have_sgi_nsym_da",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_SGI_NSYM_DA,
"Short guard interval Nsym disambiguation information present", HFILL}},
{&hf_radiotap_vht_have_ldpc_extra,
{"LDPC extra OFDM symbol", "radiotap.vht.ldpc_extra",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_LDPC_EXTRA,
NULL, HFILL}},
{&hf_radiotap_vht_have_bf,
{"Beamformed", "radiotap.vht.have_beamformed",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_BF,
NULL, HFILL}},
{&hf_radiotap_vht_have_bw,
{"Bandwidth", "radiotap.mcs.have_bw",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_BW,
NULL, HFILL}},
{&hf_radiotap_vht_have_gid,
{"Group ID", "radiotap.mcs.have_gid",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_GID,
NULL, HFILL}},
{&hf_radiotap_vht_have_p_aid,
{"Partial AID", "radiotap.mcs.have_paid",
FT_BOOLEAN, 16, TFS(&tfs_present_absent), IEEE80211_RADIOTAP_VHT_HAVE_PAID,
NULL, HFILL}},
{&hf_radiotap_vht_stbc,
{"STBC", "radiotap.vht.stbc",
FT_BOOLEAN, 8, TFS(&tfs_on_off), IEEE80211_RADIOTAP_VHT_STBC,
"Space Time Block Coding flag", HFILL}},
{&hf_radiotap_vht_txop_ps,
{"TXOP_PS_NOT_ALLOWED", "radiotap.vht.txop_ps",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_VHT_TXOP_PS,
"Flag indicating whether STAs may doze during TXOP", HFILL}},
{&hf_radiotap_vht_gi,
{"Guard interval", "radiotap.vht.gi",
FT_UINT8, BASE_DEC, VALS(mcs_gi), IEEE80211_RADIOTAP_VHT_SGI,
"Short/Long guard interval", HFILL}},
{&hf_radiotap_vht_sgi_nsym_da,
{"SGI Nsym disambiguation", "radiotap.vht.sgi_nsym_da",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_VHT_SGI_NSYM_DA,
"Short Guard Interval Nsym disambiguation", HFILL}},
{&hf_radiotap_vht_ldpc_extra,
{"LDPC extra OFDM symbol", "radiotap.vht.ldpc_extra",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_VHT_LDPC_EXTRA,
NULL, HFILL}},
{&hf_radiotap_vht_bf,
{"Beamformed", "radiotap.vht.beamformed",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_VHT_BF,
NULL, HFILL}},
{&hf_radiotap_vht_bw,
{"Bandwidth", "radiotap.vht.bw",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &vht_bandwidth_ext, 0x0,
NULL, HFILL}},
{&hf_radiotap_vht_nsts[0],
{"Space-time streams 0", "radiotap.vht.nsts.0",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Space-time streams", HFILL}},
{&hf_radiotap_vht_nsts[1],
{"Space-time streams 1", "radiotap.vht.nsts.1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Space-time streams", HFILL}},
{&hf_radiotap_vht_nsts[2],
{"Space-time streams 2", "radiotap.vht.nsts.2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Space-time streams", HFILL}},
{&hf_radiotap_vht_nsts[3],
{"Space-time streams 3", "radiotap.vht.nsts.3",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Space-time streams", HFILL}},
{&hf_radiotap_vht_mcs[0],
{"MCS index 0", "radiotap.vht.mcs.0",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_MCS,
"MCS index", HFILL}},
{&hf_radiotap_vht_mcs[1],
{"MCS index 1", "radiotap.vht.mcs.1",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_MCS,
"MCS index", HFILL}},
{&hf_radiotap_vht_mcs[2],
{"MCS index 2", "radiotap.vht.mcs.2",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_MCS,
"MCS index", HFILL}},
{&hf_radiotap_vht_mcs[3],
{"MCS index 3", "radiotap.vht.mcs.3",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_MCS,
"MCS index", HFILL}},
{&hf_radiotap_vht_nss[0],
{"Spatial streams 0", "radiotap.vht.nss.0",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_NSS,
"Number of spatial streams", HFILL}},
{&hf_radiotap_vht_nss[1],
{"Spatial streams 1", "radiotap.vht.nss.1",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_NSS,
"Number of spatial streams", HFILL}},
{&hf_radiotap_vht_nss[2],
{"Spatial streams 2", "radiotap.vht.nss.2",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_NSS,
"Number of spatial streams", HFILL}},
{&hf_radiotap_vht_nss[3],
{"Spatial streams 3", "radiotap.vht.nss.3",
FT_UINT8, BASE_DEC, NULL, IEEE80211_RADIOTAP_VHT_NSS,
"Number of spatial streams", HFILL}},
{&hf_radiotap_vht_coding[0],
{"Coding 0", "radiotap.vht.coding.0",
FT_UINT8, BASE_DEC, VALS(mcs_fec), 0x0,
"Coding", HFILL}},
{&hf_radiotap_vht_coding[1],
{"Coding 1", "radiotap.vht.coding.1",
FT_UINT8, BASE_DEC, VALS(mcs_fec), 0x0,
"Coding", HFILL}},
{&hf_radiotap_vht_coding[2],
{"Coding 2", "radiotap.vht.coding.2",
FT_UINT8, BASE_DEC, VALS(mcs_fec), 0x0,
"Coding", HFILL}},
{&hf_radiotap_vht_coding[3],
{"Coding 3", "radiotap.vht.coding.3",
FT_UINT8, BASE_DEC, VALS(mcs_fec), 0x0,
"Coding", HFILL}},
{&hf_radiotap_vht_datarate[0],
{"Data rate (Mb/s) 0", "radiotap.vht.datarate.0",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Speed this frame was sent/received at", HFILL}},
{&hf_radiotap_vht_datarate[1],
{"Data rate (Mb/s) 1", "radiotap.vht.datarate.1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Speed this frame was sent/received at", HFILL}},
{&hf_radiotap_vht_datarate[2],
{"Data rate (Mb/s) 2", "radiotap.vht.datarate.2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Speed this frame was sent/received at", HFILL}},
{&hf_radiotap_vht_datarate[3],
{"Data rate (Mb/s) 3", "radiotap.vht.datarate.3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Speed this frame was sent/received at", HFILL}},
{&hf_radiotap_vht_gid,
{"Group Id", "radiotap.vht.gid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_vht_p_aid,
{"Partial AID", "radiotap.vht.paid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_vendor_ns,
{"Vendor namespace", "radiotap.vendor_namespace",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_ven_oui,
{"Vendor OUI", "radiotap.vendor_oui",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_radiotap_ven_subns,
{"Vendor sub namespace", "radiotap.vendor_subns",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Vendor-specified sub namespace", HFILL}},
{&hf_radiotap_ven_skip,
{"Vendor data length", "radiotap.vendor_data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of vendor-specified data", HFILL}},
{&hf_radiotap_ven_data,
{"Vendor data", "radiotap.vendor_data",
FT_NONE, BASE_NONE, NULL, 0x0,
"Vendor-specified data", HFILL}},
{&hf_radiotap_fcs_bad,
{"Bad FCS", "radiotap.fcs_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Specifies if this frame has a bad frame check sequence", HFILL}},
};
static gint *ett[] = {
&ett_radiotap,
&ett_radiotap_present,
&ett_radiotap_flags,
&ett_radiotap_rxflags,
&ett_radiotap_channel_flags,
&ett_radiotap_xchannel_flags,
&ett_radiotap_vendor,
&ett_radiotap_mcs,
&ett_radiotap_mcs_known,
&ett_radiotap_ampdu,
&ett_radiotap_ampdu_flags,
&ett_radiotap_vht,
&ett_radiotap_vht_known,
&ett_radiotap_vht_user
};
static ei_register_info ei[] = {
{ &ei_radiotap_present, { "radiotap.present.radiotap_and_vendor", PI_MALFORMED, PI_ERROR, "Both radiotap and vendor namespace specified in bitmask word", EXPFILL }},
{ &ei_radiotap_present_reserved, { "radiotap.present.reserved.unknown", PI_UNDECODED, PI_NOTE, "Unknown Radiotap fields, code not implemented, Please check radiotap documentation, Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_radiotap_data_past_header, { "radiotap.data_past_header", PI_MALFORMED, PI_ERROR, "Radiotap data goes past the end of the radiotap header", EXPFILL }},
};
module_t *radiotap_module;
expert_module_t* expert_radiotap;
proto_radiotap =
proto_register_protocol("IEEE 802.11 Radiotap Capture header", "802.11 Radiotap", "radiotap");
proto_register_field_array(proto_radiotap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_radiotap = expert_register_protocol(proto_radiotap);
expert_register_field_array(expert_radiotap, ei, array_length(ei));
register_dissector("radiotap", dissect_radiotap, proto_radiotap);
radiotap_tap = register_tap("radiotap");
radiotap_module = prefs_register_protocol(proto_radiotap, NULL);
prefs_register_bool_preference(radiotap_module, "bit14_fcs_in_header",
"Assume bit 14 means FCS in header",
"Radiotap has a bit to indicate whether the FCS is still on the frame or not. "
"Some generators (e.g. AirPcap) use a non-standard radiotap flag 14 to put "
"the FCS into the header.",
&radiotap_bit14_fcs);
}
void proto_reg_handoff_radiotap(void)
{
dissector_handle_t radiotap_handle;
ieee80211_radio_handle = find_dissector("wlan_radio");
radiotap_handle = find_dissector("radiotap");
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_RADIOTAP,
radiotap_handle);
}
