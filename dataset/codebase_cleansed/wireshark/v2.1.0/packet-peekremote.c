static int
dissect_peekremote_extflags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *extflags_tree;
proto_item *ti_extflags;
ti_extflags = proto_tree_add_item(tree, &hfi_peekremote_extflags, tvb, offset, 4, ENC_BIG_ENDIAN);
extflags_tree = proto_item_add_subtree(ti_extflags, ett_peekremote_extflags);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_20mhz_lower, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_20mhz_upper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_40mhz, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_half_gi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_full_gi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_ampdu, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_amsdu, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_11ac, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_future_use, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(extflags_tree, &hfi_peekremote_extflags_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
return 4;
}
static int
dissect_peekremote_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *flags_tree;
proto_item *ti_flags;
ti_flags = proto_tree_add_item(tree, &hfi_peekremote_flags, tvb, offset, 1, ENC_NA);
flags_tree = proto_item_add_subtree(ti_flags, ett_peekremote_flags);
proto_tree_add_item(flags_tree, &hfi_peekremote_flags_control_frame, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, &hfi_peekremote_flags_crc_error, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, &hfi_peekremote_flags_frame_error, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, &hfi_peekremote_flags_reserved, tvb, offset, 1, ENC_NA);
return 1;
}
static int
dissect_peekremote_status(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *status_tree;
proto_item *ti_status;
ti_status = proto_tree_add_item(tree, &hfi_peekremote_status, tvb, offset, 1, ENC_NA);
status_tree = proto_item_add_subtree(ti_status, ett_peekremote_status);
proto_tree_add_item(status_tree, &hfi_peekremote_status_protected, tvb, offset, 1, ENC_NA);
proto_tree_add_item(status_tree, &hfi_peekremote_status_with_decrypt_error, tvb, offset, 1, ENC_NA);
proto_tree_add_item(status_tree, &hfi_peekremote_status_with_short_preamble, tvb, offset, 1, ENC_NA);
proto_tree_add_item(status_tree, &hfi_peekremote_status_reserved, tvb, offset, 1, ENC_NA);
return 1;
}
static gboolean
dissect_peekremote_new(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *u _U_)
{
static const guint8 magic[4] = { 0x00, 0xFF, 0xAB, 0xCD };
int offset = 0;
proto_tree *peekremote_tree = NULL;
proto_item *ti = NULL;
proto_item *ti_header_version, *ti_header_size;
guint8 header_version;
guint header_size;
struct ieee_802_11_phdr phdr;
guint32 extflags;
guint16 frequency;
guint16 mcs_index;
tvbuff_t *next_tvb;
if (tvb_memeql(tvb, 0, magic, 4) == -1) {
return FALSE;
}
memset(&phdr, 0, sizeof(phdr));
phdr.fcs_len = 4;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PEEKREMOTE");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, hfi_peekremote, tvb, 0, -1, ENC_NA);
peekremote_tree = proto_item_add_subtree(ti, ett_peekremote);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_magic_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
header_version = tvb_get_guint8(tvb, offset);
ti_header_version = proto_tree_add_uint(peekremote_tree, &hfi_peekremote_header_version, tvb, offset, 1, header_version);
offset += 1;
header_size = tvb_get_ntohl(tvb, offset);
ti_header_size = proto_tree_add_uint(peekremote_tree, &hfi_peekremote_header_size, tvb, offset, 4, header_size);
offset += 4;
switch (header_version) {
case 2:
if (header_size != 55) {
expert_add_info(pinfo, ti_header_size, &ei_peekremote_invalid_header_size);
if (header_size > 9)
offset += (header_size - 9);
} else {
proto_tree_add_item(peekremote_tree, &hfi_peekremote_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
mcs_index = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_mcs_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
phdr.has_channel = TRUE;
phdr.channel = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_channel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
frequency = tvb_get_ntohl(tvb, offset);
if (frequency != 0) {
phdr.has_frequency = TRUE;
phdr.frequency = frequency;
}
proto_tree_add_item(peekremote_tree, &hfi_peekremote_frequency, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_band, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
extflags = tvb_get_ntohl(tvb, offset);
if (extflags & EXT_FLAG_802_11ac) {
guint i;
phdr.phy = PHDR_802_11_PHY_11AC;
for (i = 0; i < 4; i++) {
phdr.phy_info.info_11ac.nss[i] = 0;
}
} else {
phdr.phy = PHDR_802_11_PHY_11N;
phdr.phy_info.info_11n.has_mcs_index = TRUE;
phdr.phy_info.info_11n.mcs_index = mcs_index;
}
offset += dissect_peekremote_extflags(tvb, pinfo, peekremote_tree, offset);
phdr.has_signal_percent = TRUE;
phdr.signal_percent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_percent, tvb, offset, 1, ENC_NA);
offset += 1;
phdr.has_noise_percent = TRUE;
phdr.noise_percent = tvb_get_guint8(tvb, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_percent, tvb, offset, 1, ENC_NA);
offset += 1;
phdr.has_signal_dbm = TRUE;
phdr.signal_dbm = tvb_get_guint8(tvb, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
phdr.has_noise_dbm = TRUE;
phdr.noise_dbm = tvb_get_guint8(tvb, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_1_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_2_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_3_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_4_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_1_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_2_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_3_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_4_dbm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_packetlength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(peekremote_tree, &hfi_peekremote_slicelength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += dissect_peekremote_flags(tvb, pinfo, peekremote_tree, offset);
offset += dissect_peekremote_status(tvb, pinfo, peekremote_tree, offset);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_timestamp, tvb, offset, 8, ENC_BIG_ENDIAN);
phdr.has_tsf_timestamp = TRUE;
phdr.tsf_timestamp = tvb_get_ntoh64(tvb, offset);
offset += 8;
}
break;
default:
expert_add_info(pinfo, ti_header_version, &ei_peekremote_unknown_header_version);
if (header_size > 9)
offset += (header_size - 9);
break;
}
proto_item_set_end(ti, tvb, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(wlan_radio_handle, next_tvb, pinfo, tree, &phdr);
return TRUE;
}
static int
dissect_peekremote_legacy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tvbuff_t *next_tvb;
proto_tree *peekremote_tree = NULL;
proto_item *ti = NULL;
struct ieee_802_11_phdr phdr;
guint8 signal_percent;
memset(&phdr, 0, sizeof(phdr));
if (dissect_peekremote_new(tvb, pinfo, tree, data)) {
return tvb_reported_length(tvb);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PEEKREMOTE");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, hfi_peekremote, tvb, 0, -1, ENC_NA);
peekremote_tree = proto_item_add_subtree(ti, ett_peekremote);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_dbm, tvb, 0, 1, ENC_NA);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_dbm, tvb, 1, 1, ENC_NA);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_packetlength, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_slicelength, tvb, 4, 2, ENC_BIG_ENDIAN);
dissect_peekremote_flags(tvb, pinfo, peekremote_tree, 6);
dissect_peekremote_status(tvb, pinfo, peekremote_tree, 7);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_timestamp, tvb, 8, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_speed, tvb, 16, 1, ENC_NA);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_channel, tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_signal_percent, tvb, 18, 1, ENC_NA);
proto_tree_add_item(peekremote_tree, &hfi_peekremote_noise_percent, tvb, 19, 1, ENC_NA);
}
signal_percent = tvb_get_guint8(tvb, 18);
proto_item_set_end(ti, tvb, 20);
next_tvb = tvb_new_subset_remaining(tvb, 20);
if (GPOINTER_TO_INT(data) == IS_ARUBA && signal_percent == 100) {
phdr.fcs_len = 0;
} else {
phdr.fcs_len = 4;
}
phdr.decrypted = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.has_channel = TRUE;
phdr.channel = tvb_get_guint8(tvb, 17);
phdr.has_data_rate = TRUE;
phdr.data_rate = tvb_get_guint8(tvb, 16);
phdr.has_signal_percent = TRUE;
phdr.signal_percent = tvb_get_guint8(tvb, 18);
phdr.has_noise_percent = TRUE;
phdr.noise_percent = tvb_get_guint8(tvb, 18);
phdr.has_signal_dbm = TRUE;
phdr.signal_dbm = tvb_get_guint8(tvb, 0);
phdr.has_noise_dbm = TRUE;
phdr.noise_dbm = tvb_get_guint8(tvb, 1);
phdr.has_tsf_timestamp = TRUE;
phdr.tsf_timestamp = tvb_get_ntoh64(tvb, 8);
return 20 + call_dissector_with_data(wlan_radio_handle, next_tvb, pinfo, tree, &phdr);
}
void
proto_register_peekremote(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_peekremote_signal_dbm,
&hfi_peekremote_noise_dbm,
&hfi_peekremote_packetlength,
&hfi_peekremote_slicelength,
&hfi_peekremote_flags,
&hfi_peekremote_flags_control_frame,
&hfi_peekremote_flags_crc_error,
&hfi_peekremote_flags_frame_error,
&hfi_peekremote_flags_reserved,
&hfi_peekremote_status,
&hfi_peekremote_status_protected,
&hfi_peekremote_status_with_decrypt_error,
&hfi_peekremote_status_with_short_preamble,
&hfi_peekremote_status_reserved,
&hfi_peekremote_timestamp,
&hfi_peekremote_speed,
&hfi_peekremote_channel,
&hfi_peekremote_magic_number,
&hfi_peekremote_header_version,
&hfi_peekremote_header_size,
&hfi_peekremote_type,
&hfi_peekremote_mcs_index,
&hfi_peekremote_signal_percent,
&hfi_peekremote_noise_percent,
&hfi_peekremote_frequency,
&hfi_peekremote_band,
&hfi_peekremote_extflags,
&hfi_peekremote_extflags_20mhz_lower,
&hfi_peekremote_extflags_20mhz_upper,
&hfi_peekremote_extflags_40mhz,
&hfi_peekremote_extflags_half_gi,
&hfi_peekremote_extflags_full_gi,
&hfi_peekremote_extflags_ampdu,
&hfi_peekremote_extflags_amsdu,
&hfi_peekremote_extflags_11ac,
&hfi_peekremote_extflags_future_use,
&hfi_peekremote_extflags_reserved,
&hfi_peekremote_signal_1_dbm,
&hfi_peekremote_signal_2_dbm,
&hfi_peekremote_signal_3_dbm,
&hfi_peekremote_signal_4_dbm,
&hfi_peekremote_noise_1_dbm,
&hfi_peekremote_noise_2_dbm,
&hfi_peekremote_noise_3_dbm,
&hfi_peekremote_noise_4_dbm,
};
#endif
static gint *ett[] = {
&ett_peekremote,
&ett_peekremote_flags,
&ett_peekremote_status,
&ett_peekremote_extflags
};
static ei_register_info ei[] = {
{ &ei_peekremote_unknown_header_version, { "peekremote.unknown_header_version", PI_UNDECODED, PI_ERROR, "Unknown header version", EXPFILL }},
{ &ei_peekremote_invalid_header_size, { "peekremote.invalid_header_size", PI_UNDECODED, PI_ERROR, "Invalid header size for that header version", EXPFILL }},
};
expert_module_t *expert_peekremote;
proto_peekremote = proto_register_protocol(
"AiroPeek/OmniPeek encapsulated IEEE 802.11", "PEEKREMOTE", "peekremote");
hfi_peekremote = proto_registrar_get_nth(proto_peekremote);
proto_register_fields(proto_peekremote, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
expert_peekremote = expert_register_protocol(proto_peekremote);
expert_register_field_array(expert_peekremote, ei, array_length(ei));
peekremote_handle = register_dissector("peekremote", dissect_peekremote_legacy, proto_peekremote);
}
void
proto_reg_handoff_peekremote(void)
{
wlan_radio_handle = find_dissector_add_dependency("wlan_radio", proto_peekremote);
dissector_add_uint("udp.port", 5000, peekremote_handle);
heur_dissector_add("udp", dissect_peekremote_new, "OmniPeek Remote over UDP", "peekremote_udp", proto_peekremote, HEURISTIC_ENABLE);
}
