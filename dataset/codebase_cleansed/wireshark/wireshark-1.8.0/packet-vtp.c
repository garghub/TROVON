static void
set_vtp_info_col(tvbuff_t *tvb, packet_info *pinfo)
{
switch (tvb_get_guint8(tvb, 1)) {
case SUMMARY_ADVERT:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Summary Advertisement, Revision: %u", tvb_get_ntohl(tvb, 36));
if (tvb_get_guint8(tvb, 2) > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO,
", Followers: %u", tvb_get_guint8(tvb, 2));
}
break;
case SUBSET_ADVERT:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Subset Advertisement, Revision: %u, Seq: %u",
tvb_get_ntohl(tvb, 36), tvb_get_guint8(tvb, 2));
break;
case ADVERT_REQUEST:
col_set_str(pinfo->cinfo, COL_INFO, "Advertisement Request");
break;
case JOIN_MSG:
col_set_str(pinfo->cinfo, COL_INFO, "Join");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unrecognized VTP message");
break;
}
}
static void
dissect_vtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *vtp_tree = NULL, *vtp_pruning_tree = NULL;
int offset = 0;
guint8 code;
guint8 md_len;
const guint8 *upd_timestamp;
int vlan_info_len;
int pruning_vlan_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VTP");
set_vtp_info_col(tvb, pinfo);
if (tree) {
ti = proto_tree_add_item(tree, proto_vtp, tvb, offset, -1,
ENC_NA);
vtp_tree = proto_item_add_subtree(ti, ett_vtp);
proto_tree_add_item(vtp_tree, hf_vtp_version, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
code = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vtp_tree, hf_vtp_code, tvb, offset, 1,
code);
offset += 1;
switch (code) {
case SUMMARY_ADVERT:
proto_tree_add_item(vtp_tree, hf_vtp_followers, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
md_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vtp_tree, hf_vtp_md_len, tvb, offset,
1, md_len);
offset += 1;
proto_tree_add_item(vtp_tree, hf_vtp_md, tvb, offset,
32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(vtp_tree, hf_vtp_conf_rev_num, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(vtp_tree, hf_vtp_upd_id, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
upd_timestamp = tvb_get_ptr(tvb, offset, 12);
proto_tree_add_string_format(vtp_tree, hf_vtp_upd_ts, tvb,
offset, 12, (gchar*)upd_timestamp,
"Update Timestamp: %.2s-%.2s-%.2s %.2s:%.2s:%.2s",
&upd_timestamp[0], &upd_timestamp[2], &upd_timestamp[4],
&upd_timestamp[6], &upd_timestamp[8], &upd_timestamp[10]);
offset += 12;
proto_tree_add_item(vtp_tree, hf_vtp_md5_digest, tvb,
offset, 16, ENC_NA);
break;
case SUBSET_ADVERT:
proto_tree_add_item(vtp_tree, hf_vtp_seq_num, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
md_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vtp_tree, hf_vtp_md_len, tvb, offset,
1, md_len);
offset += 1;
proto_tree_add_item(vtp_tree, hf_vtp_md, tvb, offset,
32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(vtp_tree, hf_vtp_conf_rev_num, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
vlan_info_len =
dissect_vlan_info(tvb, offset, vtp_tree);
if (vlan_info_len < 0)
break;
offset += vlan_info_len;
}
break;
case ADVERT_REQUEST:
offset += 1;
md_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vtp_tree, hf_vtp_md_len, tvb, offset,
1, md_len);
offset += 1;
proto_tree_add_item(vtp_tree, hf_vtp_md, tvb, offset,
32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(vtp_tree, hf_vtp_start_value, tvb,
offset, 2, ENC_BIG_ENDIAN);
break;
case JOIN_MSG:
offset += 1;
md_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vtp_tree, hf_vtp_md_len, tvb, offset,
1, md_len);
offset += 1;
proto_tree_add_item(vtp_tree, hf_vtp_md, tvb, offset,
32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(vtp_tree, hf_vtp_pruning_first_vid, tvb, offset,
2, ENC_BIG_ENDIAN);
pruning_vlan_id = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(vtp_tree, hf_vtp_pruning_last_vid, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_text (vtp_tree, tvb, offset, -1,
"Advertised active (i.e. not pruned) VLANs");
vtp_pruning_tree = proto_item_add_subtree(ti, ett_vtp_pruning);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 vlan_usage_bitmap;
int shift;
vlan_usage_bitmap = tvb_get_guint8(tvb, offset);
for (shift = 0; shift < 8; shift++) {
if (vlan_usage_bitmap & (1<<7)) {
proto_tree_add_uint(vtp_pruning_tree, hf_vtp_pruning_active_vid,
tvb, offset, 1, pruning_vlan_id);
}
pruning_vlan_id += 1;
vlan_usage_bitmap <<= 1;
}
offset += 1;
}
break;
}
}
}
static int
dissect_vlan_info(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *vlan_info_tree;
proto_tree *status_tree;
guint8 vlan_info_len;
int vlan_info_left;
guint8 status;
guint8 vlan_name_len;
guint8 type;
int length;
proto_tree *tlv_tree;
vlan_info_len = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(tree, tvb, offset, vlan_info_len,
"VLAN Information");
vlan_info_tree = proto_item_add_subtree(ti, ett_vtp_vlan_info);
vlan_info_left = vlan_info_len;
proto_tree_add_uint(vlan_info_tree, hf_vtp_vlan_info_len, tvb, offset, 1,
vlan_info_len);
offset += 1;
vlan_info_left -= 1;
if (vlan_info_left < 1)
return -1;
status = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(vlan_info_tree, tvb, offset, 1,
"Status: 0x%02x%s", status,
(status & VLAN_SUSPENDED) ? "(VLAN suspended)" : "");
status_tree = proto_item_add_subtree(ti, ett_vtp_vlan_status);
proto_tree_add_boolean(status_tree, hf_vtp_vlan_status_vlan_susp, tvb, offset, 1,
status);
offset += 1;
vlan_info_left -= 1;
if (vlan_info_left < 1)
return -1;
proto_tree_add_item(vlan_info_tree, hf_vtp_vlan_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
vlan_info_left -= 1;
if (vlan_info_left < 1)
return -1;
vlan_name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(vlan_info_tree, hf_vtp_vlan_name_len, tvb, offset, 1,
vlan_name_len);
offset += 1;
vlan_info_left -= 1;
if (vlan_info_left < 2)
return -1;
proto_tree_add_item(vlan_info_tree, hf_vtp_isl_vlan_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
vlan_info_left -= 2;
if (vlan_info_left < 2)
return -1;
proto_tree_add_item(vlan_info_tree, hf_vtp_mtu_size, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
vlan_info_left -= 2;
if (vlan_info_left < 4)
return -1;
proto_tree_add_item(vlan_info_tree, hf_vtp_802_10_index, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
vlan_info_left -= 4;
vlan_name_len = 4*((vlan_name_len + 3)/4);
if (vlan_info_left < vlan_name_len)
return -1;
proto_tree_add_item(vlan_info_tree, hf_vtp_vlan_name, tvb, offset,
vlan_name_len, ENC_ASCII|ENC_NA);
offset += vlan_name_len;
vlan_info_left -= vlan_name_len;
while (vlan_info_left > 0) {
type = tvb_get_guint8(tvb, offset + 0);
length = tvb_get_guint8(tvb, offset + 1);
ti = proto_tree_add_text(vlan_info_tree, tvb, offset,
2 + length*2, "%s",
val_to_str(type, vlan_tlv_type_vals,
"Unknown TLV type: 0x%02x"));
tlv_tree = proto_item_add_subtree(ti, ett_vtp_tlv);
proto_tree_add_uint(tlv_tree, hf_vtp_vlan_tlvtype, tvb, offset,
1, type);
proto_tree_add_uint(tlv_tree, hf_vtp_vlan_tlvlength, tvb, offset+1,
1, length);
offset += 2;
vlan_info_left -= 2;
if (length > 0) {
dissect_vlan_info_tlv(tvb, offset, length*2, tlv_tree,
ti, type);
}
offset += length*2;
vlan_info_left -= length*2;
}
return vlan_info_len;
}
static void
dissect_vlan_info_tlv(tvbuff_t *tvb, int offset, int length,
proto_tree *tree, proto_item *ti, guint8 type)
{
switch (type) {
case SR_RING_NUM:
if (length == 2) {
proto_item_set_text(ti,
"Source-Routing Ring Number: 0x%04x",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(tree, tvb, offset, 2,
"Source-Routing Ring Number: 0x%04x",
tvb_get_ntohs(tvb, offset));
} else {
proto_item_set_text(ti,
"Source-Routing Ring Number: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Source-Routing Ring Number: Bad length %u",
length);
}
break;
case SR_BRIDGE_NUM:
if (length == 2) {
proto_item_set_text(ti,
"Source-Routing Bridge Number: 0x%04x",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(tree, tvb, offset, 2,
"Source-Routing Bridge Number: 0x%04x",
tvb_get_ntohs(tvb, offset));
} else {
proto_item_set_text(ti,
"Source-Routing Bridge Number: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Source-Routing Bridge Number: Bad length %u",
length);
}
break;
case STP_TYPE:
if (length == 2) {
proto_item_set_text(ti,
"Spanning-Tree Protocol Type: %s",
val_to_str(tvb_get_ntohs(tvb, offset), stp_type_vals,
"Unknown (0x%04x)"));
proto_tree_add_text(tree, tvb, offset, 2,
"Spanning-Tree Protocol Type: %s",
val_to_str(tvb_get_ntohs(tvb, offset), stp_type_vals,
"Unknown (0x%04x)"));
} else {
proto_item_set_text(ti,
"Spanning-Tree Protocol Type: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Spanning-Tree Protocol Type: Bad length %u",
length);
}
break;
case PARENT_VLAN:
if (length == 2) {
proto_item_set_text(ti,
"Parent VLAN: 0x%04x",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(tree, tvb, offset, 2,
"Parent VLAN: 0x%04x",
tvb_get_ntohs(tvb, offset));
} else {
proto_item_set_text(ti,
"Parent VLAN: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Parent VLAN: Bad length %u",
length);
}
break;
case TR_BRIDGED_VLANS:
if (length == 2) {
proto_item_set_text(ti,
"Translationally Bridged VLANs: 0x%04x",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(tree, tvb, offset, 2,
"Translationally Bridged VLANs: 0x%04x",
tvb_get_ntohs(tvb, offset));
} else {
proto_item_set_text(ti,
"Translationally Bridged VLANs: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Translationally Bridged VLANs: Bad length %u",
length);
}
break;
case PRUNING:
if (length == 2) {
proto_item_set_text(ti,
"Pruning: %s",
val_to_str(tvb_get_ntohs(tvb, offset), pruning_vals,
"Unknown (0x%04x)"));
proto_tree_add_text(tree, tvb, offset, 2,
"Pruning: %s",
val_to_str(tvb_get_ntohs(tvb, offset), pruning_vals,
"Unknown (0x%04x)"));
} else {
proto_item_set_text(ti,
"Pruning: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Pruning: Bad length %u",
length);
}
break;
case BRIDGE_TYPE:
if (length == 2) {
proto_item_set_text(ti,
"Bridge Type: %s",
val_to_str(tvb_get_ntohs(tvb, offset), bridge_type_vals,
"Unknown (0x%04x)"));
proto_tree_add_text(tree, tvb, offset, 2,
"Bridge Type: %s",
val_to_str(tvb_get_ntohs(tvb, offset), bridge_type_vals,
"Unknown (0x%04x)"));
} else {
proto_item_set_text(ti,
"Bridge Type: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Bridge Type: Bad length %u",
length);
}
break;
case MAX_ARE_HOP_CNT:
if (length == 2) {
proto_item_set_text(ti,
"Max ARE Hop Count: %u",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(tree, tvb, offset, 2,
"Max ARE Hop Count: %u",
tvb_get_ntohs(tvb, offset));
} else {
proto_item_set_text(ti,
"Max ARE Hop Count: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Max ARE Hop Count: Bad length %u",
length);
}
break;
case MAX_STE_HOP_CNT:
if (length == 2) {
proto_item_set_text(ti,
"Max STE Hop Count: %u",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(tree, tvb, offset, 2,
"Max STE Hop Count: %u",
tvb_get_ntohs(tvb, offset));
} else {
proto_item_set_text(ti,
"Max STE Hop Count: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Max STE Hop Count: Bad length %u",
length);
}
break;
case BACKUP_CRF_MODE:
if (length == 2) {
proto_item_set_text(ti,
"Backup CRF Mode: %s",
val_to_str(tvb_get_ntohs(tvb, offset), backup_crf_mode_vals,
"Unknown (0x%04x)"));
proto_tree_add_text(tree, tvb, offset, 2,
"Backup CRF Mode: %s",
val_to_str(tvb_get_ntohs(tvb, offset), backup_crf_mode_vals,
"Unknown (0x%04x)"));
} else {
proto_item_set_text(ti,
"Backup CRF Mode: Bad length %u",
length);
proto_tree_add_text(tree, tvb, offset, length,
"Backup CRF Mode: Bad length %u",
length);
}
break;
default:
proto_tree_add_text(tree, tvb, offset, length, "Data");
break;
}
}
void
proto_register_vtp(void)
{
static hf_register_info hf[] = {
{ &hf_vtp_version,
{ "Version", "vtp.version", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_vtp_code,
{ "Code", "vtp.code", FT_UINT8, BASE_HEX, VALS(type_vals), 0x0,
NULL, HFILL }},
{ &hf_vtp_followers,
{ "Followers", "vtp.followers", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of following Subset-Advert messages", HFILL }},
{ &hf_vtp_md_len,
{ "Management Domain Length", "vtp.md_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of management domain string", HFILL }},
{ &hf_vtp_md,
{ "Management Domain", "vtp.md", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_vtp_conf_rev_num,
{ "Configuration Revision Number", "vtp.conf_rev_num", FT_UINT32, BASE_DEC, NULL, 0x0,
"Revision number of the configuration information", HFILL }},
{ &hf_vtp_upd_id,
{ "Updater Identity", "vtp.upd_id", FT_IPv4, BASE_NONE, NULL, 0x0,
"IP address of the updater", HFILL }},
{ &hf_vtp_upd_ts,
{ "Update Timestamp", "vtp.upd_ts", FT_STRING, BASE_NONE, NULL, 0,
"Time stamp of the current configuration revision", HFILL }},
{ &hf_vtp_md5_digest,
{ "MD5 Digest", "vtp.md5_digest", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_vtp_seq_num,
{ "Sequence Number", "vtp.seq_num", FT_UINT8, BASE_DEC, NULL, 0x0,
"Order of this frame in the sequence of Subset-Advert frames", HFILL }},
{ &hf_vtp_start_value,
{ "Start Value", "vtp.start_value", FT_UINT16, BASE_HEX, NULL, 0x0,
"Virtual LAN ID of first VLAN for which information is requested", HFILL }},
{ &hf_vtp_vlan_info_len,
{ "VLAN Information Length", "vtp.vlan_info.len", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of the VLAN information field", HFILL }},
{ &hf_vtp_vlan_status_vlan_susp,
{ "VLAN suspended", "vtp.vlan_info.status.vlan_susp", FT_BOOLEAN, 8, NULL, VLAN_SUSPENDED,
NULL, HFILL }},
{ &hf_vtp_vlan_type,
{ "VLAN Type", "vtp.vlan_info.vlan_type", FT_UINT8, BASE_HEX, VALS(vlan_type_vals), 0x0,
"Type of VLAN", HFILL }},
{ &hf_vtp_vlan_name_len,
{ "VLAN Name Length", "vtp.vlan_info.vlan_name_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of VLAN name string", HFILL }},
{ &hf_vtp_isl_vlan_id,
{ "ISL VLAN ID", "vtp.vlan_info.isl_vlan_id", FT_UINT16, BASE_HEX, NULL, 0x0,
"ID of this VLAN on ISL trunks", HFILL }},
{ &hf_vtp_mtu_size,
{ "MTU Size", "vtp.vlan_info.mtu_size", FT_UINT16, BASE_DEC, NULL, 0x0,
"MTU for this VLAN", HFILL }},
{ &hf_vtp_802_10_index,
{ "802.10 Index", "vtp.vlan_info.802_10_index", FT_UINT32, BASE_HEX, NULL, 0x0,
"IEEE 802.10 security association identifier for this VLAN", HFILL }},
{ &hf_vtp_vlan_name,
{ "VLAN Name", "vtp.vlan_info.vlan_name", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_vtp_vlan_tlvtype,
{ "Type", "vtp.vlan_info.tlv_type", FT_UINT8, BASE_HEX, VALS(vlan_tlv_type_vals), 0x0,
NULL, HFILL }},
{ &hf_vtp_vlan_tlvlength,
{ "Length", "vtp.vlan_info.tlv_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_vtp_pruning_first_vid,
{ "First VLAN ID", "vtp.pruning.first", FT_UINT16, BASE_DEC, NULL, 0x0,
"First VLAN ID for which pruning information is present", HFILL }},
{ &hf_vtp_pruning_last_vid,
{ "Last VLAN ID", "vtp.pruning.last", FT_UINT16, BASE_DEC, NULL, 0x0,
"Last VLAN ID for which pruning information is present", HFILL }},
{ &hf_vtp_pruning_active_vid,
{ "VLAN", "vtp.pruning.active", FT_UINT16, BASE_DEC, NULL, 0x0,
"Active advertised VLAN ID", HFILL }},
};
static gint *ett[] = {
&ett_vtp,
&ett_vtp_vlan_info,
&ett_vtp_vlan_status,
&ett_vtp_tlv,
&ett_vtp_pruning,
};
proto_vtp = proto_register_protocol("VLAN Trunking Protocol",
"VTP", "vtp");
proto_register_field_array(proto_vtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_vtp(void)
{
dissector_handle_t vtp_handle;
vtp_handle = create_dissector_handle(dissect_vtp, proto_vtp);
dissector_add_uint("llc.cisco_pid", 0x2003, vtp_handle);
}
