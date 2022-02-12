void
capture_radiotap(const guchar * pd, int offset, int len, packet_counts * ld)
{
guint16 it_len;
guint32 present, xpresent;
guint8 rflags;
struct ieee80211_radiotap_header *hdr;
if (!BYTES_ARE_IN_FRAME(offset, len,
sizeof(struct ieee80211_radiotap_header))) {
ld->other++;
return;
}
hdr = (void *)pd;
it_len = pletohs(&hdr->it_len);
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
present = pletohl(&hdr->it_present);
offset += sizeof(struct ieee80211_radiotap_header);
it_len -= sizeof(struct ieee80211_radiotap_header);
xpresent = present;
while (xpresent & BIT(IEEE80211_RADIOTAP_EXT)) {
if (!BYTES_ARE_IN_FRAME(offset, 4, it_len)) {
ld->other++;
return;
}
xpresent = pletohl(pd + offset);
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
void proto_register_radiotap(void)
{
static const value_string phy_type[] = {
{0, "Unknown"},
{IEEE80211_CHAN_A, "802.11a"},
{IEEE80211_CHAN_A | IEEE80211_CHAN_HT20, "802.11a (ht20)"},
{IEEE80211_CHAN_A | IEEE80211_CHAN_HT40U, "802.11a (ht40+)"},
{IEEE80211_CHAN_A | IEEE80211_CHAN_HT40D, "802.11a (ht40-)"},
{IEEE80211_CHAN_B, "802.11b"},
{IEEE80211_CHAN_PUREG, "802.11g (pure-g)"},
{IEEE80211_CHAN_G, "802.11g"},
{IEEE80211_CHAN_G | IEEE80211_CHAN_HT20, "802.11g (ht20)"},
{IEEE80211_CHAN_G | IEEE80211_CHAN_HT40U, "802.11g (ht40+)"},
{IEEE80211_CHAN_G | IEEE80211_CHAN_HT40D, "802.11g (ht40-)"},
{IEEE80211_CHAN_T, "802.11a (turbo)"},
{IEEE80211_CHAN_108PUREG, "802.11g (pure-g, turbo)"},
{IEEE80211_CHAN_108G, "802.11g (turbo)"},
{IEEE80211_CHAN_FHSS, "FHSS"},
{0, NULL}
};
static const value_string mcs_bandwidth[] = {
{ IEEE80211_RADIOTAP_MCS_BW_20, "20 MHz" },
{ IEEE80211_RADIOTAP_MCS_BW_40, "40 MHz" },
{ IEEE80211_RADIOTAP_MCS_BW_20L, "20 MHz lower" },
{ IEEE80211_RADIOTAP_MCS_BW_20U, "20 MHz upper" },
{0, NULL}
};
static const value_string mcs_format[] = {
{ 0, "mixed" },
{ 1, "greenfield" },
{0, NULL},
};
static const value_string mcs_fec[] = {
{ 0, "BCC" },
{ 1, "LDPC" },
{0, NULL}
};
static const value_string mcs_gi[] = {
{ 0, "long" },
{ 1, "short" },
{0, NULL}
};
static const true_false_string preamble_type = {
"Short",
"Long",
};
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
"Length of header including version, pad, length and data fields",
HFILL}},
{&hf_radiotap_present,
{"Present flags", "radiotap.present",
FT_NONE, BASE_NONE, NULL, 0x0,
"Bitmask indicating which fields are present", HFILL}},
#define RADIOTAP_MASK(name) BIT(IEEE80211_RADIOTAP_ ##name)
{&hf_radiotap_present_tsft,
{"TSFT", "radiotap.present.tsft",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(TSFT),
"Specifies if the Time Synchronization Function Timer field is present",
HFILL}},
{&hf_radiotap_present_flags,
{"Flags", "radiotap.present.flags",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(FLAGS),
"Specifies if the channel flags field is present", HFILL}},
{&hf_radiotap_present_rate,
{"Rate", "radiotap.present.rate",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(RATE),
"Specifies if the transmit/receive rate field is present",
HFILL}},
{&hf_radiotap_present_channel,
{"Channel", "radiotap.present.channel",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(CHANNEL),
"Specifies if the transmit/receive frequency field is present",
HFILL}},
{&hf_radiotap_present_fhss,
{"FHSS", "radiotap.present.fhss",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(FHSS),
"Specifies if the hop set and pattern is present for frequency hopping radios",
HFILL}},
{&hf_radiotap_present_dbm_antsignal,
{"dBm Antenna Signal", "radiotap.present.dbm_antsignal",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(DBM_ANTSIGNAL),
"Specifies if the antenna signal strength in dBm is present",
HFILL}},
{&hf_radiotap_present_dbm_antnoise,
{"dBm Antenna Noise", "radiotap.present.dbm_antnoise",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(DBM_ANTNOISE),
"Specifies if the RF noise power at antenna field is present",
HFILL}},
{&hf_radiotap_present_lock_quality,
{"Lock Quality", "radiotap.present.lock_quality",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(LOCK_QUALITY),
"Specifies if the signal quality field is present", HFILL}},
{&hf_radiotap_present_tx_attenuation,
{"TX Attenuation", "radiotap.present.tx_attenuation",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(TX_ATTENUATION),
"Specifies if the transmit power distance from max power field is present",
HFILL}},
{&hf_radiotap_present_db_tx_attenuation,
{"dB TX Attenuation", "radiotap.present.db_tx_attenuation",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(DB_TX_ATTENUATION),
"Specifies if the transmit power distance from max power (in dB) field is present",
HFILL}},
{&hf_radiotap_present_dbm_tx_power,
{"dBm TX Power", "radiotap.present.dbm_tx_power",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(DBM_TX_POWER),
"Specifies if the transmit power (in dBm) field is present",
HFILL}},
{&hf_radiotap_present_antenna,
{"Antenna", "radiotap.present.antenna",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(ANTENNA),
"Specifies if the antenna number field is present", HFILL}},
{&hf_radiotap_present_db_antsignal,
{"dB Antenna Signal", "radiotap.present.db_antsignal",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(DB_ANTSIGNAL),
"Specifies if the RF signal power at antenna in dB field is present",
HFILL}},
{&hf_radiotap_present_db_antnoise,
{"dB Antenna Noise", "radiotap.present.db_antnoise",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(DB_ANTNOISE),
"Specifies if the RF signal power at antenna in dBm field is present",
HFILL}},
{&hf_radiotap_present_rxflags,
{"RX flags", "radiotap.present.rxflags",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(RX_FLAGS),
"Specifies if the RX flags field is present", HFILL}},
{&hf_radiotap_present_hdrfcs,
{"FCS in header", "radiotap.present.fcs",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(RX_FLAGS),
"Specifies if the FCS field is present", HFILL}},
{&hf_radiotap_present_xchannel,
{"Channel+", "radiotap.present.xchannel",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(XCHANNEL),
"Specifies if the extended channel info field is present",
HFILL}},
{&hf_radiotap_present_mcs,
{"HT information", "radiotap.present.mcs",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(MCS),
"Specifies if the HT field is present", HFILL}},
{&hf_radiotap_present_rtap_ns,
{"Radiotap NS next", "radiotap.present.rtap_ns",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(RADIOTAP_NAMESPACE),
"Specifies a reset to the radiotap namespace", HFILL}},
{&hf_radiotap_present_vendor_ns,
{"Vendor NS next", "radiotap.present.vendor_ns",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(VENDOR_NAMESPACE),
"Specifies that the next bitmap is in a vendor namespace",
HFILL}},
{&hf_radiotap_present_ext,
{"Ext", "radiotap.present.ext",
FT_BOOLEAN, 32, NULL, RADIOTAP_MASK(EXT),
"Specifies if there are any extensions to the header present",
HFILL}},
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
"Frame has padding between 802.11 header and payload",
HFILL}},
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
"Value in microseconds of the MAC's Time Synchronization Function timer when the first bit of the MPDU arrived at the MAC.",
HFILL}},
{&hf_radiotap_quality,
{"Signal Quality", "radiotap.quality",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Signal quality (unitless measure)", HFILL}},
{&hf_radiotap_fcs,
{"802.11 FCS", "radiotap.fcs",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Frame check sequence of this frame", HFILL}},
{&hf_radiotap_channel,
{"Channel", "radiotap.channel",
FT_UINT32, BASE_DEC, NULL, 0x0,
"802.11 channel number that this frame was sent/received on",
HFILL}},
{&hf_radiotap_channel_frequency,
{"Channel frequency", "radiotap.channel.freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Channel frequency in megahertz that this frame was sent/received on",
HFILL}},
{&hf_radiotap_channel_flags,
{"Channel type", "radiotap.channel.type",
FT_UINT16, BASE_HEX, VALS(phy_type), 0x0,
NULL, HFILL}},
{&hf_radiotap_channel_flags_turbo,
{"Turbo", "radiotap.channel.type.turbo",
FT_BOOLEAN, 16, NULL, 0x0010, "Channel Type Turbo", HFILL}},
{&hf_radiotap_channel_flags_cck,
{"Complementary Code Keying (CCK)",
"radiotap.channel.type.cck",
FT_BOOLEAN, 16, NULL, 0x0020,
"Channel Type Complementary Code Keying (CCK) Modulation",
HFILL}},
{&hf_radiotap_channel_flags_ofdm,
{"Orthogonal Frequency-Division Multiplexing (OFDM)",
"radiotap.channel.type.ofdm",
FT_BOOLEAN, 16, NULL, 0x0040,
"Channel Type Orthogonal Frequency-Division Multiplexing (OFDM)",
HFILL}},
{&hf_radiotap_channel_flags_2ghz,
{"2 GHz spectrum", "radiotap.channel.type.2ghz",
FT_BOOLEAN, 16, NULL, 0x0080, "Channel Type 2 GHz spectrum",
HFILL}},
{&hf_radiotap_channel_flags_5ghz,
{"5 GHz spectrum", "radiotap.channel.type.5ghz",
FT_BOOLEAN, 16, NULL, 0x0100, "Channel Type 5 GHz spectrum",
HFILL}},
{&hf_radiotap_channel_flags_passive,
{"Passive", "radiotap.channel.type.passive",
FT_BOOLEAN, 16, NULL, 0x0200, "Channel Type Passive", HFILL}},
{&hf_radiotap_channel_flags_dynamic,
{"Dynamic CCK-OFDM", "radiotap.channel.type.dynamic",
FT_BOOLEAN, 16, NULL, 0x0400,
"Channel Type Dynamic CCK-OFDM Channel", HFILL}},
{&hf_radiotap_channel_flags_gfsk,
{"Gaussian Frequency Shift Keying (GFSK)",
"radiotap.channel.type.gfsk",
FT_BOOLEAN, 16, NULL, 0x0800,
"Channel Type Gaussian Frequency Shift Keying (GFSK) Modulation",
HFILL}},
{&hf_radiotap_channel_flags_gsm,
{"GSM (900MHz)", "radiotap.channel.type.gsm",
FT_BOOLEAN, 16, NULL, 0x1000, "Channel Type GSM", HFILL}},
{&hf_radiotap_channel_flags_sturbo,
{"Static Turbo", "radiotap.channel.type.sturbo",
FT_BOOLEAN, 16, NULL, 0x2000, "Channel Type Status Turbo",
HFILL}},
{&hf_radiotap_channel_flags_half,
{"Half Rate Channel (10MHz Channel Width)",
"radiotap.channel.type.half",
FT_BOOLEAN, 16, NULL, 0x4000, "Channel Type Half Rate",
HFILL}},
{&hf_radiotap_channel_flags_quarter,
{"Quarter Rate Channel (5MHz Channel Width)",
"radiotap.channel.type.quarter",
FT_BOOLEAN, 16, NULL, 0x8000, "Channel Type Quarter Rate",
HFILL}},
{&hf_radiotap_rxflags,
{"RX flags", "radiotap.rxflags",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{&hf_radiotap_rxflags_badplcp,
{"Bad PLCP", "radiotap.rxflags.badplcp",
FT_BOOLEAN, 24, NULL, IEEE80211_RADIOTAP_F_RX_BADPLCP,
"Frame with bad PLCP", HFILL}},
{&hf_radiotap_xchannel,
{"Channel number", "radiotap.xchannel",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_radiotap_xchannel_frequency,
{"Channel frequency", "radiotap.xchannel.freq",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_radiotap_xchannel_flags,
{"Channel type", "radiotap.xchannel.flags",
FT_UINT32, BASE_HEX, VALS(phy_type), 0x0, NULL, HFILL}},
{&hf_radiotap_xchannel_flags_turbo,
{"Turbo", "radiotap.xchannel.type.turbo",
FT_BOOLEAN, 24, NULL, 0x0010, "Channel Type Turbo", HFILL}},
{&hf_radiotap_xchannel_flags_cck,
{"Complementary Code Keying (CCK)",
"radiotap.xchannel.type.cck",
FT_BOOLEAN, 24, NULL, 0x0020,
"Channel Type Complementary Code Keying (CCK) Modulation",
HFILL}},
{&hf_radiotap_xchannel_flags_ofdm,
{"Orthogonal Frequency-Division Multiplexing (OFDM)",
"radiotap.xchannel.type.ofdm",
FT_BOOLEAN, 24, NULL, 0x0040,
"Channel Type Orthogonal Frequency-Division Multiplexing (OFDM)",
HFILL}},
{&hf_radiotap_xchannel_flags_2ghz,
{"2 GHz spectrum", "radiotap.xchannel.type.2ghz",
FT_BOOLEAN, 24, NULL, 0x0080, "Channel Type 2 GHz spectrum",
HFILL}},
{&hf_radiotap_xchannel_flags_5ghz,
{"5 GHz spectrum", "radiotap.xchannel.type.5ghz",
FT_BOOLEAN, 24, NULL, 0x0100, "Channel Type 5 GHz spectrum",
HFILL}},
{&hf_radiotap_xchannel_flags_passive,
{"Passive", "radiotap.channel.xtype.passive",
FT_BOOLEAN, 24, NULL, 0x0200, "Channel Type Passive", HFILL}},
{&hf_radiotap_xchannel_flags_dynamic,
{"Dynamic CCK-OFDM", "radiotap.xchannel.type.dynamic",
FT_BOOLEAN, 24, NULL, 0x0400,
"Channel Type Dynamic CCK-OFDM Channel", HFILL}},
{&hf_radiotap_xchannel_flags_gfsk,
{"Gaussian Frequency Shift Keying (GFSK)",
"radiotap.xchannel.type.gfsk",
FT_BOOLEAN, 24, NULL, 0x0800,
"Channel Type Gaussian Frequency Shift Keying (GFSK) Modulation",
HFILL}},
{&hf_radiotap_xchannel_flags_gsm,
{"GSM (900MHz)", "radiotap.xchannel.type.gsm",
FT_BOOLEAN, 24, NULL, 0x1000, "Channel Type GSM", HFILL}},
{&hf_radiotap_xchannel_flags_sturbo,
{"Static Turbo", "radiotap.xchannel.type.sturbo",
FT_BOOLEAN, 24, NULL, 0x2000, "Channel Type Status Turbo",
HFILL}},
{&hf_radiotap_xchannel_flags_half,
{"Half Rate Channel (10MHz Channel Width)",
"radiotap.xchannel.type.half",
FT_BOOLEAN, 24, NULL, 0x4000, "Channel Type Half Rate",
HFILL}},
{&hf_radiotap_xchannel_flags_quarter,
{"Quarter Rate Channel (5MHz Channel Width)",
"radiotap.xchannel.type.quarter",
FT_BOOLEAN, 24, NULL, 0x8000, "Channel Type Quarter Rate",
HFILL}},
{&hf_radiotap_xchannel_flags_ht20,
{"HT Channel (20MHz Channel Width)",
"radiotap.xchannel.type.ht20",
FT_BOOLEAN, 24, NULL, 0x10000, "Channel Type HT/20", HFILL}},
{&hf_radiotap_xchannel_flags_ht40u,
{"HT Channel (40MHz Channel Width with Extension channel above)", "radiotap.xchannel.type.ht40u",
FT_BOOLEAN, 24, NULL, 0x20000, "Channel Type HT/40+", HFILL}},
{&hf_radiotap_xchannel_flags_ht40d,
{"HT Channel (40MHz Channel Width with Extension channel below)", "radiotap.xchannel.type.ht40d",
FT_BOOLEAN, 24, NULL, 0x40000, "Channel Type HT/40-", HFILL}},
#if 0
{&hf_radiotap_xchannel_maxpower,
{"Max transmit power", "radiotap.xchannel.maxpower",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
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
"Antenna number this frame was sent/received over (starting at 0)",
HFILL}},
{&hf_radiotap_dbm_antsignal,
{"SSI Signal (dBm)", "radiotap.dbm_antsignal",
FT_INT32, BASE_DEC, NULL, 0x0,
"RF signal power at the antenna from a fixed, arbitrary value in decibels from one milliwatt",
HFILL}},
{&hf_radiotap_db_antsignal,
{"SSI Signal (dB)", "radiotap.db_antsignal",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RF signal power at the antenna from a fixed, arbitrary value in decibels",
HFILL}},
{&hf_radiotap_dbm_antnoise,
{"SSI Noise (dBm)", "radiotap.dbm_antnoise",
FT_INT32, BASE_DEC, NULL, 0x0,
"RF noise power at the antenna from a fixed, arbitrary value in decibels per one milliwatt",
HFILL}},
{&hf_radiotap_db_antnoise,
{"SSI Noise (dB)", "radiotap.db_antnoise",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RF noise power at the antenna from a fixed, arbitrary value in decibels",
HFILL}},
{&hf_radiotap_tx_attenuation,
{"Transmit attenuation", "radiotap.txattenuation",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Transmit power expressed as unitless distance from max power set at factory (0 is max power)",
HFILL}},
{&hf_radiotap_db_tx_attenuation,
{"Transmit attenuation (dB)", "radiotap.db_txattenuation",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Transmit power expressed as decibels from max power set at factory (0 is max power)",
HFILL}},
{&hf_radiotap_txpower,
{"Transmit power", "radiotap.txpower",
FT_INT32, BASE_DEC, NULL, 0x0,
"Transmit power in decibels per one milliwatt (dBm)", HFILL}},
{&hf_radiotap_mcs,
{"MCS information", "radiotap.mcs",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_radiotap_mcs_known,
{"Known MCS information", "radiotap.mcs.known",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Bit mask indicating what MCS information is present", HFILL}},
{&hf_radiotap_mcs_have_bw,
{"Bandwidth", "radiotap.mcs.have_bw",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_MCS_HAVE_BW,
"Bandwidth information present", HFILL}},
{&hf_radiotap_mcs_have_gi,
{"Guard interval", "radiotap.mcs.have_gi",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_MCS_HAVE_GI,
"Sent/Received guard interval information present", HFILL}},
{&hf_radiotap_mcs_have_format,
{"Format", "radiotap.mcs.have_format",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_MCS_HAVE_FMT,
"Format information present", HFILL}},
{&hf_radiotap_mcs_have_fec,
{"FEC", "radiotap.mcs.have_fec",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_MCS_HAVE_FEC,
"Forward error correction information present", HFILL}},
{&hf_radiotap_mcs_have_stbc,
{"STBC", "radiotap.mcs.have_stbc",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_MCS_HAVE_STBC,
"Space Time Block Coding information present", HFILL}},
{&hf_radiotap_mcs_have_index,
{"MCS index", "radiotap.mcs.have_index",
FT_BOOLEAN, 8, NULL, IEEE80211_RADIOTAP_MCS_HAVE_MCS,
"MCS index information present", HFILL}},
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
{"FEC", "radiotap.mcs.fec",
FT_UINT8, BASE_DEC, VALS(mcs_fec), IEEE80211_RADIOTAP_MCS_FEC_LDPC,
"forward error correction", HFILL}},
{&hf_radiotap_mcs_stbc,
{"STBC", "radiotap.mcs.stbc",
FT_BOOLEAN, 8, TFS(&tfs_on_off), IEEE80211_RADIOTAP_MCS_STBC,
"Space Time Block Code", HFILL}},
{&hf_radiotap_mcs_index,
{"MCS index", "radiotap.mcs.index",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
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
"Specifies if this frame has a bad frame check sequence",
HFILL}},
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
};
module_t *radiotap_module;
proto_radiotap =
proto_register_protocol("IEEE 802.11 Radiotap Capture header",
"802.11 Radiotap", "radiotap");
proto_register_field_array(proto_radiotap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
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
static void
dissect_radiotap(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_tree *radiotap_tree = NULL;
proto_tree *pt, *present_tree = NULL;
proto_tree *ft;
proto_item *ti = NULL;
proto_item *hidden_item;
int offset;
tvbuff_t *next_tvb;
guint8 version;
guint length;
guint32 rate, freq, flags;
proto_item *rate_ti;
gint8 dbm, db;
guint8 rflags = 0;
proto_item *hdr_fcs_ti = NULL;
int hdr_fcs_offset = 0;
guint32 sent_fcs = 0;
guint32 calc_fcs;
gint err;
struct ieee80211_radiotap_iterator iter;
void *data;
struct _radiotap_info *radiotap_info;
static struct _radiotap_info rtp_info_arr;
static struct radiotap_override overrides[] = {
{IEEE80211_RADIOTAP_XCHANNEL, 4, 8},
{14, 4, 4},
};
guint n_overrides = array_length(overrides);
if (!radiotap_bit14_fcs)
n_overrides--;
radiotap_info = &rtp_info_arr;
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
data = ep_tvb_memdup(tvb, 0, length);
if (!data)
return;
if (ieee80211_radiotap_iterator_init(&iter, data, length, NULL)) {
if (tree)
proto_item_append_text(ti, " (invalid)");
goto hand_off_to_80211;
}
iter.overrides = overrides;
iter.n_overrides = n_overrides;
if (tree) {
guchar *bmap_start = (guchar *) data + 4;
guint n_bitmaps = (guint)(iter.this_arg - bmap_start) / 4;
guint i;
gboolean rtap_ns, rtap_ns_next = TRUE;
guint rtap_ns_offset, rtap_ns_offset_next = 0;
pt = proto_tree_add_item(radiotap_tree, hf_radiotap_present,
tvb, 4, n_bitmaps * 4,
ENC_NA);
for (i = 0; i < n_bitmaps; i++) {
guint32 bmap = pletohl(bmap_start + 4 * i);
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
BIT(IEEE80211_RADIOTAP_VENDOR_NAMESPACE)))
goto malformed;
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
vt = proto_tree_add_bytes_format(radiotap_tree,
hf_radiotap_vendor_ns,
tvb, offset,
iter.this_arg_size,
NULL,
"Vendor namespace: %s-%d",
manuf_name, subns);
ven_tree = proto_item_add_subtree(vt, ett_radiotap_vendor);
proto_tree_add_bytes_format(ven_tree,
hf_radiotap_ven_oui, tvb,
offset, 3, NULL,
"Vendor: %s", manuf_name);
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
if (tree) {
proto_tree_add_uint64(radiotap_tree,
hf_radiotap_mactime, tvb,
offset, 8,
radiotap_info->tsft);
}
break;
case IEEE80211_RADIOTAP_FLAGS: {
proto_tree *flags_tree;
rflags = tvb_get_guint8(tvb, offset);
if (tree) {
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
case IEEE80211_RADIOTAP_RATE:
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
}
break;
case IEEE80211_RADIOTAP_CHANNEL: {
proto_item *it;
proto_tree *flags_tree;
gchar *chan_str;
if (tree) {
freq = tvb_get_letohs(tvb, offset);
flags = tvb_get_letohs(tvb, offset + 2);
chan_str = ieee80211_mhz_to_str(freq);
col_add_fstr(pinfo->cinfo,
COL_FREQ_CHAN, "%s", chan_str);
proto_tree_add_uint_format(radiotap_tree,
hf_radiotap_channel_frequency,
tvb, offset, 2, freq,
"Channel frequency: %s",
chan_str);
g_free(chan_str);
it = proto_tree_add_uint(radiotap_tree,
hf_radiotap_channel_flags,
tvb, offset + 2, 2, flags);
flags_tree =
proto_item_add_subtree(it,
ett_radiotap_channel_flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_turbo,
tvb, offset + 2, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_cck,
tvb, offset + 2, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_ofdm,
tvb, offset + 2, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_2ghz,
tvb, offset + 2, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_5ghz,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_passive,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_dynamic,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_gfsk,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_gsm,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_sturbo,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_half,
tvb, offset + 3, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_channel_flags_quarter,
tvb, offset + 3, 1, flags);
radiotap_info->freq = freq;
radiotap_info->flags = flags;
}
break;
}
case IEEE80211_RADIOTAP_FHSS:
proto_tree_add_item(radiotap_tree,
hf_radiotap_fhss_hopset, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(radiotap_tree,
hf_radiotap_fhss_pattern, tvb,
offset, 1, ENC_BIG_ENDIAN);
break;
case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
dbm = (gint8) tvb_get_guint8(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d dBm", dbm);
if (tree) {
proto_tree_add_int_format(radiotap_tree,
hf_radiotap_dbm_antsignal,
tvb, offset, 1, dbm,
"SSI Signal: %d dBm",
dbm);
}
radiotap_info->dbm_antsignal = dbm;
break;
case IEEE80211_RADIOTAP_DBM_ANTNOISE:
dbm = (gint8) tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_int_format(radiotap_tree,
hf_radiotap_dbm_antnoise,
tvb, offset, 1, dbm,
"SSI Noise: %d dBm",
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
proto_tree_add_uint_format(radiotap_tree,
hf_radiotap_db_antsignal,
tvb, offset, 1, db,
"SSI Signal: %u dB",
db);
}
break;
case IEEE80211_RADIOTAP_DB_ANTNOISE:
db = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint_format(radiotap_tree,
hf_radiotap_db_antnoise,
tvb, offset, 1, db,
"SSI Noise: %u dB",
db);
}
break;
case IEEE80211_RADIOTAP_RX_FLAGS: {
proto_tree *flags_tree;
if (radiotap_bit14_fcs) {
if (tree) {
sent_fcs = tvb_get_ntohl(tvb, offset);
hdr_fcs_ti = proto_tree_add_uint(radiotap_tree,
hf_radiotap_fcs, tvb,
offset, 4, sent_fcs);
hdr_fcs_offset = offset;
}
} else {
proto_item *it;
if (tree) {
flags = tvb_get_letohs(tvb, offset);
it = proto_tree_add_uint(radiotap_tree,
hf_radiotap_rxflags,
tvb, offset, 2, flags);
flags_tree =
proto_item_add_subtree(it,
ett_radiotap_rxflags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_rxflags_badplcp,
tvb, offset, 1, flags);
}
}
break;
}
case IEEE80211_RADIOTAP_XCHANNEL: {
proto_item *it;
proto_tree *flags_tree;
if (tree) {
int channel;
flags = tvb_get_letohl(tvb, offset);
freq = tvb_get_letohs(tvb, offset + 4);
channel = tvb_get_guint8(tvb, offset + 6);
proto_tree_add_uint(radiotap_tree,
hf_radiotap_xchannel,
tvb, offset + 6, 1,
(guint32) channel);
proto_tree_add_uint(radiotap_tree,
hf_radiotap_xchannel_frequency,
tvb, offset + 4, 2, freq);
it = proto_tree_add_uint(radiotap_tree,
hf_radiotap_xchannel_flags,
tvb, offset + 0, 4, flags);
flags_tree =
proto_item_add_subtree(it, ett_radiotap_xchannel_flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_turbo,
tvb, offset + 0, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_cck,
tvb, offset + 0, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_ofdm,
tvb, offset + 0, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_2ghz,
tvb, offset + 0, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_5ghz,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_passive,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_dynamic,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_gfsk,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_gsm,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_sturbo,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_half,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_quarter,
tvb, offset + 1, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_ht20,
tvb, offset + 2, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_ht40u,
tvb, offset + 2, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_radiotap_xchannel_flags_ht40d,
tvb, offset + 2, 1, flags);
#if 0
proto_tree_add_uint(radiotap_tree,
hf_radiotap_xchannel_maxpower,
tvb, offset + 7, 1, maxpower);
#endif
}
break;
}
case IEEE80211_RADIOTAP_MCS: {
proto_item *it;
proto_tree *mcs_tree = NULL, *mcs_known_tree;
guint8 mcs_known, mcs_flags;
guint8 mcs;
guint bandwidth;
guint gi_length;
gboolean can_calculate_rate;
can_calculate_rate = TRUE;
mcs_known = tvb_get_guint8(tvb, offset);
mcs_flags = tvb_get_guint8(tvb, offset + 1);
mcs = tvb_get_guint8(tvb, offset + 2);
if (tree) {
it = proto_tree_add_item(radiotap_tree, hf_radiotap_mcs,
tvb, offset, 3, ENC_NA);
mcs_tree = proto_item_add_subtree(it, ett_radiotap_mcs);
it = proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_known,
tvb, offset, 1, mcs_known);
mcs_known_tree = proto_item_add_subtree(it, ett_radiotap_mcs_known);
proto_tree_add_item(mcs_known_tree, hf_radiotap_mcs_have_bw,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_known_tree, hf_radiotap_mcs_have_index,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_known_tree, hf_radiotap_mcs_have_gi,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_known_tree, hf_radiotap_mcs_have_format,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_known_tree, hf_radiotap_mcs_have_fec,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcs_known_tree, hf_radiotap_mcs_have_stbc,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_BW) {
bandwidth = ((mcs_flags & IEEE80211_RADIOTAP_MCS_BW_MASK) == IEEE80211_RADIOTAP_MCS_BW_40) ?
1 : 0;
if (mcs_tree)
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_bw,
tvb, offset + 1, 1, mcs_flags);
} else {
bandwidth = 0;
can_calculate_rate = FALSE;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_GI) {
gi_length = (mcs_flags & IEEE80211_RADIOTAP_MCS_SGI) ?
1 : 0;
if (mcs_tree)
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_gi,
tvb, offset + 1, 1, mcs_flags);
} else {
gi_length = 0;
can_calculate_rate = FALSE;
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_FMT) {
if (mcs_tree)
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_format,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_FEC) {
if (mcs_tree)
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_fec,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_STBC) {
if (mcs_tree)
proto_tree_add_boolean(mcs_tree, hf_radiotap_mcs_stbc,
tvb, offset + 1, 1, mcs_flags);
}
if (mcs_known & IEEE80211_RADIOTAP_MCS_HAVE_MCS) {
if (mcs_tree)
proto_tree_add_uint(mcs_tree, hf_radiotap_mcs_index,
tvb, offset + 2, 1, mcs);
} else
can_calculate_rate = FALSE;
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
}
}
if (err != -ENOENT && tree) {
malformed:
proto_item_append_text(ti, " (malformed)");
}
if (rflags & IEEE80211_RADIOTAP_F_FCS)
pinfo->pseudo_header->ieee_802_11.fcs_len = 4;
else
pinfo->pseudo_header->ieee_802_11.fcs_len = 0;
hand_off_to_80211:
next_tvb = tvb_new_subset_remaining(tvb, length);
if (hdr_fcs_ti) {
if (tvb_length(next_tvb) >
(unsigned int)pinfo->pseudo_header->ieee_802_11.fcs_len) {
calc_fcs =
crc32_802_tvb(next_tvb,
tvb_length(next_tvb) -
pinfo->pseudo_header->ieee_802_11.fcs_len);
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
call_dissector((rflags & IEEE80211_RADIOTAP_F_DATAPAD) ?
ieee80211_datapad_handle : ieee80211_handle,
next_tvb, pinfo, tree);
tap_queue_packet(radiotap_tap, pinfo, radiotap_info);
}
void proto_reg_handoff_radiotap(void)
{
dissector_handle_t radiotap_handle;
ieee80211_handle = find_dissector("wlan");
ieee80211_datapad_handle = find_dissector("wlan_datapad");
radiotap_handle = find_dissector("radiotap");
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_RADIOTAP,
radiotap_handle);
}
