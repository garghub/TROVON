static guint16 skip_item(proto_tree *meta_tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint16 offs)
{
guint16 id;
guint8 type;
guint16 len, aligned_len, total_len;
proto_tree *item_tree;
proto_item *subti;
id = tvb_get_letohs(tvb, offs); offs += 2;
type = tvb_get_guint8(tvb, offs); offs++;
len = tvb_get_guint8(tvb, offs); offs++;
aligned_len = (len + 3) & 0xfffc;
total_len = aligned_len + 4;
subti = proto_tree_add_item(meta_tree, hf_meta_item, tvb, offs - 4,
aligned_len + 4, ENC_NA);
item_tree = proto_item_add_subtree(subti, ett_meta_item);
proto_tree_add_uint(item_tree, hf_meta_item_id, tvb, offs - 4, 2, id);
proto_tree_add_uint(item_tree, hf_meta_item_type, tvb, offs - 2, 1, type);
proto_tree_add_uint(item_tree, hf_meta_item_len,
tvb, offs - 1, 1, len);
if (len > 0)
proto_tree_add_item(item_tree, hf_meta_item_data,
tvb, offs, len, ENC_NA);
return total_len;
}
static guint16 evaluate_meta_item_pcap(proto_tree *meta_tree, tvbuff_t *tvb, packet_info *pinfo, guint16 offs)
{
guint16 id;
guint8 type;
guint16 len, aligned_len, total_len;
proto_tree *item_tree;
proto_item *subti;
guint8 dir;
guint64 ts;
id = tvb_get_letohs(tvb, offs); offs += 2;
type = tvb_get_guint8(tvb, offs); offs++;
len = tvb_get_guint8(tvb, offs); offs++;
aligned_len = (len + 3) & 0xfffc;
total_len = aligned_len + 4;
switch (id) {
case META_ID_DIRECTION:
dir = tvb_get_guint8(tvb, offs);
pinfo->p2p_dir = dir == META_DIR_UP ? P2P_DIR_RECV : P2P_DIR_SENT;
proto_tree_add_uint(meta_tree, hf_meta_item_direction, tvb, offs, 1, dir);
break;
case META_ID_TIMESTAMP64:
ts = tvb_get_letoh64(tvb, offs);
proto_tree_add_uint64(meta_tree, hf_meta_item_ts, tvb, offs, 8, ts);
break;
case META_ID_SIGNALING:
proto_tree_add_boolean(meta_tree, hf_meta_item_signaling, tvb,
offs, 0, 1);
break;
case META_ID_INCOMPLETE:
proto_tree_add_boolean(meta_tree, hf_meta_item_incomplete, tvb,
offs, 0, 1);
break;
default:
subti = proto_tree_add_item(meta_tree, hf_meta_item, tvb, offs - 4,
aligned_len + 4, ENC_NA);
item_tree = proto_item_add_subtree(subti, ett_meta_item);
proto_tree_add_uint(item_tree, hf_meta_item_id, tvb, offs - 4, 2, id);
proto_tree_add_uint(item_tree, hf_meta_item_type, tvb, offs - 2, 1, type);
proto_tree_add_uint(item_tree, hf_meta_item_len,
tvb, offs - 1, 1, len);
if (len > 0)
proto_tree_add_item(item_tree, hf_meta_item_data,
tvb, offs, len, ENC_NA);
}
return total_len;
}
static guint16 evaluate_meta_item_dxt(proto_tree *meta_tree, tvbuff_t *tvb, packet_info *pinfo, guint16 offs, struct atm_phdr *atm_info)
{
guint16 id;
guint8 type;
guint16 len, aligned_len, total_len;
proto_tree *item_tree;
proto_item *subti;
guint8 dir, nsapi, rat, aal5proto;
guint16 phylinkid, localdevid, remotedevid, tapgroupid;
guint32 tlli;
guint64 ts, imsi, imei, cell;
sscop_payload_info *p_sscop_info;
const gchar *imsi_str, *imei_str;
proto_item *cell_item, *imsi_item, *imei_item;
proto_tree *cell_tree, *imsi_tree, *imei_tree;
id = tvb_get_letohs(tvb, offs); offs += 2;
type = tvb_get_guint8(tvb, offs); offs++;
len = tvb_get_guint8(tvb, offs); offs++;
aligned_len = (len + 3) & 0xfffc;
total_len = aligned_len + 4;
switch (id) {
case META_ID_DIRECTION:
dir = tvb_get_guint8(tvb, offs);
pinfo->p2p_dir = (dir == META_DIR_UP ? P2P_DIR_RECV : P2P_DIR_SENT);
proto_tree_add_uint(meta_tree, hf_meta_item_direction, tvb, offs, 1, dir);
break;
case META_ID_TIMESTAMP64:
ts = tvb_get_letoh64(tvb, offs);
proto_tree_add_uint64(meta_tree, hf_meta_item_ts, tvb, offs, 8, ts);
break;
case META_ID_PHYLINKID:
phylinkid = tvb_get_letohs(tvb, offs);
pinfo->link_number = phylinkid;
proto_tree_add_uint(meta_tree, hf_meta_item_phylinkid, tvb,
offs, 2, phylinkid);
break;
case META_ID_NSAPI:
nsapi = tvb_get_guint8(tvb, offs);
proto_tree_add_uint(meta_tree, hf_meta_item_nsapi, tvb,
offs, 1, nsapi);
break;
case META_ID_IMSI:
imsi = tvb_get_letoh64(tvb, offs);
imsi_str = tvb_bcd_dig_to_wmem_packet_str(tvb, offs, 8, NULL, FALSE);
imsi_item = proto_tree_add_string(meta_tree, hf_meta_item_imsi_digits, tvb,
offs, 8, imsi_str);
imsi_tree = proto_item_add_subtree(imsi_item, ett_meta_imsi);
proto_tree_add_uint64(imsi_tree, hf_meta_item_imsi_value,
tvb, offs, 8, imsi);
break;
case META_ID_IMEI:
imei = tvb_get_letoh64(tvb, offs);
imei_str = tvb_bcd_dig_to_wmem_packet_str(tvb, offs, 8, NULL, FALSE);
imei_item = proto_tree_add_string(meta_tree, hf_meta_item_imei_digits, tvb,
offs, 8, imei_str);
imei_tree = proto_item_add_subtree(imei_item, ett_meta_imei);
proto_tree_add_uint64(imei_tree, hf_meta_item_imei_value,
tvb, offs, 8, imei);
break;
case META_ID_APN:
proto_tree_add_item(meta_tree, hf_meta_item_apn, tvb,
offs, len, ENC_ASCII|ENC_NA);
break;
case META_ID_RAT:
rat = tvb_get_guint8(tvb, offs);
proto_tree_add_uint(meta_tree, hf_meta_item_rat, tvb,
offs, 1, rat);
break;
case META_ID_CELL:
cell = tvb_get_ntoh64(tvb, offs);
cell_item = proto_tree_add_uint64_format(meta_tree, hf_meta_item_cell,
tvb, offs, 8, cell, "Mobile Cell");
cell_tree = proto_item_add_subtree(cell_item, ett_meta_cell);
de_gmm_rai(tvb, cell_tree, pinfo, offs, 8, NULL, 0);
de_cell_id(tvb, cell_tree, pinfo, offs + 6, 2, NULL, 0);
break;
case META_ID_SIGNALING:
proto_tree_add_boolean(meta_tree, hf_meta_item_signaling, tvb,
offs, 0, 1);
break;
case META_ID_INCOMPLETE:
proto_tree_add_boolean(meta_tree, hf_meta_item_incomplete, tvb,
offs, 0, 1);
break;
case META_ID_DECIPHERED:
proto_tree_add_boolean(meta_tree, hf_meta_item_deciphered, tvb,
offs, 0, 1);
break;
case META_ID_AAL5PROTO:
aal5proto = tvb_get_guint8(tvb, offs);
p_sscop_info = (sscop_payload_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_sscop, 0);
if (!p_sscop_info) {
p_sscop_info = wmem_new0(wmem_file_scope(), sscop_payload_info);
p_add_proto_data(wmem_file_scope(), pinfo, proto_sscop, 0, p_sscop_info);
}
switch (aal5proto) {
case META_AAL5PROTO_MTP3:
p_sscop_info->subdissector = sscf_nni_handle;
memset(atm_info, 0, sizeof(*atm_info));
atm_info->type = TRAF_SSCOP;
break;
case META_AAL5PROTO_ALCAP:
p_sscop_info->subdissector = alcap_handle;
break;
case META_AAL5PROTO_NBAP:
p_sscop_info->subdissector = nbap_handle;
break;
case META_AAL5PROTO_NS:
memset(atm_info, 0, sizeof(*atm_info));
atm_info->type = TRAF_GPRS_NS;
break;
default:
p_remove_proto_data(wmem_file_scope(), pinfo, proto_sscop, 0);
}
proto_tree_add_uint(meta_tree, hf_meta_item_aal5proto, tvb,
offs, 1, aal5proto);
break;
case META_ID_LOCALDEVID:
localdevid = tvb_get_letohs(tvb, offs);
proto_tree_add_uint(meta_tree, hf_meta_item_localdevid, tvb,
offs, 2, localdevid);
break;
case META_ID_REMOTEDEVID:
remotedevid = tvb_get_letohs(tvb, offs);
proto_tree_add_uint(meta_tree, hf_meta_item_remotedevid, tvb,
offs, 2, remotedevid);
break;
case META_ID_TAPGROUPID:
tapgroupid = tvb_get_letohs(tvb, offs);
proto_tree_add_uint(meta_tree, hf_meta_item_tapgroupid, tvb,
offs, 2, tapgroupid);
break;
case META_ID_TLLI:
tlli = tvb_get_letohs(tvb, offs);
proto_tree_add_uint(meta_tree, hf_meta_item_tlli, tvb,
offs, 4, tlli);
break;
case META_ID_CALLING:
proto_tree_add_item(meta_tree, hf_meta_item_calling, tvb,
offs, len, ENC_ASCII|ENC_NA);
break;
case META_ID_CALLED:
proto_tree_add_item(meta_tree, hf_meta_item_called, tvb,
offs, len, ENC_ASCII|ENC_NA);
break;
default:
subti = proto_tree_add_item(meta_tree, hf_meta_item, tvb, offs - 4,
aligned_len + 4, ENC_NA);
item_tree = proto_item_add_subtree(subti, ett_meta_item);
proto_tree_add_uint(item_tree, hf_meta_item_id, tvb, offs - 4, 2, id);
proto_tree_add_uint(item_tree, hf_meta_item_type, tvb, offs - 2, 1, type);
proto_tree_add_uint(item_tree, hf_meta_item_len,
tvb, offs - 1, 1, len);
if (len > 0)
proto_tree_add_item(item_tree, hf_meta_item_data,
tvb, offs, len, ENC_NA);
}
return total_len;
}
static gint32 evaluate_meta_items(guint16 schema, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *meta_tree, guint16 offs, gint32 header_length,
struct atm_phdr *atm_info)
{
gint16 item_len;
gint32 total_len = 0;
while (total_len < header_length) {
switch (schema) {
case META_SCHEMA_DXT:
item_len = evaluate_meta_item_dxt(meta_tree, tvb, pinfo, offs + total_len, atm_info);
break;
case META_SCHEMA_PCAP:
item_len = evaluate_meta_item_pcap(meta_tree, tvb, pinfo, offs + total_len);
break;
default:
item_len = skip_item(meta_tree, tvb, pinfo, offs + total_len);
}
if (item_len < 4) {
expert_add_info_format(pinfo, meta_tree, &ei_meta_malformed,
"Malformed Packet %s (wrong item encoding)", pinfo->current_proto);
return -1;
}
total_len += item_len;
}
return total_len;
}
static int
dissect_meta(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
#define META_HEADER_SIZE 8
guint16 schema, proto, hdrlen, reserved;
gint32 item_len;
guint32 aal2_ext, atm_hdr;
proto_tree *meta_tree = NULL;
proto_item *ti = NULL;
tvbuff_t *next_tvb = NULL;
dissector_handle_t next_dissector = data_handle;
void *next_dissector_data = NULL;
struct atm_phdr atm_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "META");
schema = tvb_get_letohs(tvb, 0);
hdrlen = tvb_get_letohs(tvb, 2);
proto = tvb_get_letohs(tvb, 4);
reserved = tvb_get_letohs(tvb, 6);
if (tree) {
ti = proto_tree_add_item(tree, proto_meta, tvb, 0, hdrlen + 4, ENC_NA);
meta_tree = proto_item_add_subtree(ti, ett_meta);
proto_tree_add_uint(meta_tree, hf_meta_schema, tvb, 0, 2, schema);
proto_tree_add_uint(meta_tree, hf_meta_hdrlen, tvb, 2, 2, hdrlen);
proto_tree_add_uint(meta_tree, hf_meta_proto, tvb, 4, 2, proto);
proto_tree_add_uint(meta_tree, hf_meta_reserved, tvb, 6, 2, reserved);
}
item_len = evaluate_meta_items(schema, tvb, pinfo, meta_tree, META_HEADER_SIZE, hdrlen, &atm_info);
if (item_len < 0) {
return META_HEADER_SIZE;
}
if (hdrlen != item_len) {
expert_add_info(pinfo, ti, &ei_meta_invalid_header);
return META_HEADER_SIZE;
}
switch (schema) {
case META_SCHEMA_PCAP:
break;
case META_SCHEMA_DXT:
switch (proto) {
case META_PROTO_DXT_ETHERNET:
next_dissector = ethwithoutfcs_handle;
break;
case META_PROTO_DXT_ETHERNET_CRC:
next_dissector = ethwithfcs_handle;
break;
case META_PROTO_DXT_FP_HINT:
next_dissector = fphint_handle;
break;
case META_PROTO_DXT_ATM:
memset(&atm_info, 0, sizeof atm_info);
atm_info.aal = AAL_OAMCELL;
atm_info.type = TRAF_UNKNOWN;
next_dissector = atm_untrunc_handle;
next_dissector_data = &atm_info;
break;
case META_PROTO_DXT_ATM_AAL2:
aal2_ext = tvb_get_ntohl(tvb, item_len + META_HEADER_SIZE); item_len += 4;
atm_hdr = tvb_get_ntohl(tvb, item_len + META_HEADER_SIZE); item_len += 4;
memset(&atm_info, 0, sizeof(atm_info));
atm_info.aal = AAL_2;
atm_info.vpi = ((atm_hdr & 0x0ff00000) >> 20);
atm_info.vci = ((atm_hdr & 0x000ffff0) >> 4);
atm_info.aal2_cid = aal2_ext & 0x000000ff;
atm_info.type = TRAF_UMTS_FP;
next_dissector = atm_untrunc_handle;
next_dissector_data = &atm_info;
break;
case META_PROTO_DXT_ERF_AAL5:
atm_hdr = tvb_get_ntohl(tvb, item_len + META_HEADER_SIZE); item_len += 4;
atm_info.vpi = ((atm_hdr & 0x0ff00000) >> 20);
atm_info.vci = ((atm_hdr & 0x000ffff0) >> 4);
atm_info.aal = AAL_5;
next_dissector = atm_untrunc_handle;
next_dissector_data = &atm_info;
break;
case META_PROTO_DXT_HDLC:
next_dissector = mtp2_handle;
next_tvb = tvb_new_subset(tvb, item_len + META_HEADER_SIZE,
tvb_reported_length(tvb)-item_len-META_HEADER_SIZE-2, -1);
break;
default:
next_dissector =
dissector_get_uint_handle(meta_dissector_table, proto);
}
}
if (!next_tvb)
next_tvb = tvb_new_subset_remaining(tvb, item_len + META_HEADER_SIZE);
call_dissector_with_data(next_dissector, next_tvb, pinfo, tree,
next_dissector_data);
return tvb_captured_length(tvb);
}
void
proto_register_meta(void)
{
static hf_register_info hf[] = {
{ &hf_meta_schema,
{ "Schema", "meta.schema",
FT_UINT16, BASE_DEC, VALS(meta_schema_vals), 0,
NULL, HFILL }
},
{ &hf_meta_hdrlen,
{ "Header Length", "meta.hdrlen",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_proto,
{ "Protocol", "meta.proto",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &meta_proto_vals_ext, 0,
NULL, HFILL }
},
{ &hf_meta_reserved,
{ "Reserved", "meta.reserved",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item,
{ "Unknown Item", "meta.item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_id,
{ "Item ID", "meta.item.id",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &meta_id_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_meta_item_type,
{ "Item Type", "meta.item.type",
FT_UINT8, BASE_HEX, VALS(meta_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_meta_item_len,
{ "Item Length", "meta.item.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_data,
{ "Item Data", "meta.item.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_meta_item_direction,
{ "Direction", "meta.direction",
FT_UINT8, BASE_DEC, VALS(meta_direction_vals), 0,
NULL, HFILL }
},
{ &hf_meta_item_ts,
{ "Timestamp", "meta.timestamp",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_phylinkid,
{ "Physical Link ID", "meta.phylinkid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_nsapi,
{ "NSAPI", "meta.nsapi",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_imsi_digits,
{ "IMSI digits", "meta.imsi_digits",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_imsi_value,
{ "IMSI value", "meta.imsi_value",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_imei_digits,
{ "IMEI digits", "meta.imei_digits",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_imei_value,
{ "IMEI value", "meta.imei_value",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_signaling,
{ "Signaling", "meta.signaling",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_incomplete,
{ "Incomplete", "meta.incomplete",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_deciphered,
{ "Deciphered", "meta.deciphered",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_apn,
{ "APN", "meta.apn",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_rat,
{ "RAT", "meta.rat",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_aal5proto,
{ "AAL5 Protocol Type", "meta.aal5proto",
FT_UINT8, BASE_DEC, VALS(meta_aal5proto_vals), 0,
NULL, HFILL }
},
{ &hf_meta_item_cell,
{ "Mobile Cell", "meta.cell",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_localdevid,
{ "Local Device ID", "meta.localdevid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_remotedevid,
{ "Remote Device ID", "meta.remotedevid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_tapgroupid,
{ "Tap Group ID", "meta.tapgroupid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_tlli,
{ "TLLI", "meta.tlli",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_calling,
{ "Calling Station ID", "meta.calling",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_meta_item_called,
{ "Called Station ID", "meta.called",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_meta,
&ett_meta_item,
&ett_meta_cell,
&ett_meta_imsi,
&ett_meta_imei
};
static ei_register_info ei[] = {
{ &ei_meta_malformed, { "meta.malformed", PI_MALFORMED, PI_ERROR, "Malformed data", EXPFILL }},
{ &ei_meta_invalid_header, { "meta.invalid_header_length", PI_MALFORMED, PI_ERROR, "Invalid Header Length", EXPFILL }},
};
expert_module_t* expert_meta;
proto_meta = proto_register_protocol("Metadata", "META", "meta");
register_dissector("meta", dissect_meta, proto_meta);
proto_register_field_array(proto_meta, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_meta = expert_register_protocol(proto_meta);
expert_register_field_array(expert_meta, ei, array_length(ei));
meta_dissector_table = register_dissector_table("meta.proto",
"META protocol", proto_meta, FT_UINT16, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_meta(void)
{
#if 0
dissector_handle_t meta_handle;
meta_handle = find_dissector("meta");
dissector_add_uint("wtap_encap", WTAP_ENCAP_META, meta_handle);
#endif
data_handle = find_dissector("data");
alcap_handle = find_dissector_add_dependency("alcap", proto_meta);
atm_untrunc_handle = find_dissector_add_dependency("atm_untruncated", proto_meta);
nbap_handle = find_dissector_add_dependency("nbap", proto_meta);
sscf_nni_handle = find_dissector_add_dependency("sscf-nni", proto_meta);
ethwithfcs_handle = find_dissector_add_dependency("eth_withfcs", proto_meta);
ethwithoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_meta);
fphint_handle = find_dissector_add_dependency("fp_hint", proto_meta);
mtp2_handle = find_dissector_add_dependency("mtp2", proto_meta);
}
