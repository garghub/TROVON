static void
dissect_path_data_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_item *ti, *flag_item;
guint length_TLV, IDcount, i;
guint16 type, flag;
proto_tree *tlv_tree, *path_data_tree, *flag_tree;
while (tvb_reported_length_remaining(tvb, offset) >= TLV_TL_LENGTH)
{
ti = proto_tree_add_text(tree, tvb, offset, TLV_TL_LENGTH, "TLV");
tlv_tree = proto_item_add_subtree(ti, ett_forces_path_data_tlv);
type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tlv_tree, hf_forces_lfbselect_tlv_type_operation_path_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
length_TLV = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_item(tlv_tree, hf_forces_lfbselect_tlv_type_operation_path_length,
tvb, offset+2, 2, ENC_BIG_ENDIAN);
if (length_TLV < TLV_TL_LENGTH)
{
expert_add_info_format(pinfo, ti, &ei_forces_lfbselect_tlv_type_operation_path_length, "Bogus TLV length: %u", length_TLV);
break;
}
proto_item_set_len(ti, length_TLV);
if (type == PATH_DATA_TLV)
{
ti = proto_tree_add_text(tree, tvb, offset+TLV_TL_LENGTH, length_TLV-TLV_TL_LENGTH, "Path Data TLV");
path_data_tree = proto_item_add_subtree(ti, ett_forces_path_data_tlv);
flag = tvb_get_ntohs(tvb, offset+TLV_TL_LENGTH);
flag_item = proto_tree_add_item(path_data_tree, hf_forces_lfbselect_tlv_type_operation_path_flags,
tvb, offset+TLV_TL_LENGTH, 2, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(flag_item, ett_forces_path_data_tlv_flags);
proto_tree_add_item(flag_tree, hf_forces_lfbselect_tlv_type_operation_path_flags_selector,
tvb, offset+TLV_TL_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_forces_lfbselect_tlv_type_operation_path_flags_reserved,
tvb, offset+TLV_TL_LENGTH, 2, ENC_BIG_ENDIAN);
IDcount = tvb_get_ntohs(tvb, offset + TLV_TL_LENGTH + 2);
proto_tree_add_item(path_data_tree, hf_forces_lfbselect_tlv_type_operation_path_IDcount,
tvb, offset+TLV_TL_LENGTH+2, 2, ENC_BIG_ENDIAN);
for (i = 0; i < IDcount; i++)
proto_tree_add_item(path_data_tree, hf_forces_lfbselect_tlv_type_operation_path_IDs,
tvb, offset+TLV_TL_LENGTH+2+(i*4), 4, ENC_BIG_ENDIAN);
}
else
{
flag = 0;
proto_tree_add_item(tree, hf_forces_lfbselect_tlv_type_operation_path_data,
tvb, offset+TLV_TL_LENGTH, length_TLV-TLV_TL_LENGTH, ENC_NA);
}
if ((flag & FLAG_SELECTOR) == 0)
break;
offset += length_TLV;
}
}
static void
dissect_operation_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gint length_count)
{
proto_item *ti;
proto_tree *oper_tree;
guint type, length;
while (tvb_reported_length_remaining(tvb, offset) >= TLV_TL_LENGTH)
{
ti = proto_tree_add_text(tree, tvb, offset, length_count, "Operation TLV");
oper_tree = proto_item_add_subtree(ti, ett_forces_lfbselect_tlv_type_operation);
type = tvb_get_ntohs(tvb,offset);
ti = proto_tree_add_item(oper_tree, hf_forces_lfbselect_tlv_type_operation_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
if (try_val_to_str(type, operation_type_vals) == NULL)
expert_add_info_format(pinfo, ti, &ei_forces_lfbselect_tlv_type_operation_type,
"Bogus: ForCES Operation TLV (Type:0x%04x) is not supported", type);
length = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_uint_format_value(oper_tree, hf_forces_lfbselect_tlv_type_operation_length,
tvb, offset+2, 2, length, "%u Bytes", length);
dissect_path_data_tlv(tvb, pinfo, oper_tree, offset+TLV_TL_LENGTH);
if (length == 0)
break;
offset += length;
}
}
static void
dissect_lfbselecttlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gint length_count)
{
guint tlv_length;
proto_tree_add_item(tree, hf_forces_lfbselect_tlv_type_lfb_classid, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_forces_lfbselect_tlv_type_lfb_instanceid, tvb, offset+4, 4, ENC_BIG_ENDIAN);
offset += 8;
while ((tvb_reported_length_remaining(tvb, offset) > TLV_TL_LENGTH) && (length_count > 12))
{
tlv_length = tvb_get_ntohs(tvb, offset+2);
dissect_operation_tlv(tvb, pinfo, tree, offset, tlv_length);
if (tlv_length == 0)
break;
offset += tlv_length;
}
}
static void
dissect_redirecttlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *meta_data_tree, *meta_data_ilv_tree, *redirect_data_tree;
gint start_offset;
gint length_meta, length_ilv, length_redirect;
proto_item *ti;
address src_addr = pinfo->src,
src_net_addr = pinfo->net_src,
dst_addr = pinfo->dst,
dst_net_addr = pinfo->net_dst;
ti = proto_tree_add_text(tree, tvb, offset, TLV_TL_LENGTH, "Meta Data TLV");
meta_data_tree = proto_item_add_subtree(ti, ett_forces_redirect_tlv_meta_data_tlv);
proto_tree_add_item(meta_data_tree, hf_forces_redirect_tlv_meta_data_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
length_meta = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_uint_format_value(meta_data_tree, hf_forces_redirect_tlv_meta_data_tlv_length, tvb, offset+2, 2,
length_meta, "%u Bytes", length_meta);
proto_item_set_len(ti, length_meta);
start_offset = offset;
while ((tvb_reported_length_remaining(tvb, offset) >= 8) && (start_offset+length_meta > offset))
{
ti = proto_tree_add_text(tree, tvb, offset, TLV_TL_LENGTH, "Meta Data ILV");
meta_data_ilv_tree = proto_item_add_subtree(ti, ett_forces_redirect_tlv_meta_data_tlv_meta_data_ilv);
proto_tree_add_item(meta_data_ilv_tree, hf_forces_redirect_tlv_meta_data_tlv_meta_data_ilv_id,
tvb, offset+8, 4, ENC_BIG_ENDIAN);
length_ilv = tvb_get_ntohl(tvb, offset+12);
proto_tree_add_uint_format_value(meta_data_ilv_tree, hf_forces_redirect_tlv_meta_data_tlv_meta_data_ilv_length,
tvb, offset+12, 4, length_ilv, "%u Bytes", length_ilv);
if (length_ilv > 0)
proto_tree_add_item(meta_data_ilv_tree, hf_forces_redirect_tlv_meta_data_tlv_meta_data_ilv,
tvb, offset+8, length_ilv, ENC_NA);
proto_item_set_len(ti, length_ilv + 8);
offset += length_ilv + 8;
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
ti = proto_tree_add_text(tree, tvb, offset, TLV_TL_LENGTH, "Redirect Data TLV");
redirect_data_tree = proto_item_add_subtree(ti, ett_forces_redirect_tlv_redirect_data_tlv);
proto_tree_add_item(redirect_data_tree, hf_forces_redirect_tlv_redirect_data_tlv_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
length_redirect = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_uint_format_value(redirect_data_tree, hf_forces_redirect_tlv_redirect_data_tlv_length,
tvb, offset+2, 2, length_redirect, "%u Bytes", length_redirect);
if (tvb_reported_length_remaining(tvb, offset) < length_redirect)
{
expert_add_info_format(pinfo, ti, &ei_forces_redirect_tlv_redirect_data_tlv_length, "Bogus: Redirect Data TLV length (%u bytes) is wrong", length_redirect);
}
else if (length_redirect < TLV_TL_LENGTH + MIN_IP_HEADER_LENGTH)
{
expert_add_info_format(pinfo, ti, &ei_forces_redirect_tlv_redirect_data_tlv_length, "Bogus: Redirect Data TLV length (%u bytes) not big enough for IP layer", length_redirect);
}
else
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset(tvb, offset+4, length_redirect-TLV_TL_LENGTH, length_redirect-TLV_TL_LENGTH);
call_dissector(ip_handle, next_tvb, pinfo, redirect_data_tree);
memcpy(&(pinfo->src), &src_addr, sizeof(address));
memcpy(&(pinfo->net_src), &src_net_addr, sizeof(address));
memcpy(&(pinfo->dst), &dst_addr, sizeof(address));
memcpy(&(pinfo->net_dst), &dst_net_addr, sizeof(address));
}
}
}
static void
dissect_forces(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
proto_item *ti, *tlv_item;
proto_tree *forces_tree, *forces_flags_tree;
proto_tree *forces_main_header_tree, *forces_tlv_tree, *tlv_tree;
gint length_count;
guint8 message_type;
guint16 tlv_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ForCES");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_forces, tvb, 0, -1, ENC_NA);
forces_tree = proto_item_add_subtree(ti, ett_forces);
ti = proto_tree_add_text(forces_tree, tvb, 0, ForCES_HEADER_LENGTH, "Common Header");
forces_main_header_tree = proto_item_add_subtree(ti, ett_forces_main_header);
proto_tree_add_item(forces_main_header_tree, hf_forces_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_main_header_tree, hf_forces_rsvd, tvb, 0, 1, ENC_BIG_ENDIAN);
message_type = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item( forces_main_header_tree, hf_forces_messagetype, tvb, offset+1, 1, ENC_BIG_ENDIAN);
length_count = tvb_get_ntohs(tvb, offset+2) * 4;
ti = proto_tree_add_uint_format( forces_main_header_tree, hf_forces_length,
tvb, offset+2, 2, length_count, "Length: %u Bytes", length_count);
if (length_count != tvb_reported_length_remaining(tvb, offset))
expert_add_info_format(pinfo, ti, &ei_forces_length, "Bogus: ForCES Header length (%u bytes) is wrong),should be (%u bytes)",
length_count, tvb_reported_length_remaining(tvb, offset));
if (length_count < 24)
expert_add_info_format(pinfo, ti, &ei_forces_length, "Bogus: ForCES Header length (%u bytes) is less than 24bytes)", length_count);
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %s, Total Length: %u Bytes",
val_to_str(message_type, message_type_vals, "Unknown messagetype 0x%x"), length_count);
proto_tree_add_item( forces_main_header_tree, hf_forces_sid, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( forces_main_header_tree, hf_forces_did, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( forces_main_header_tree, hf_forces_correlator, tvb, offset+12, 8, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(forces_main_header_tree, hf_forces_flags, tvb, offset+20, 4, ENC_BIG_ENDIAN);
forces_flags_tree = proto_item_add_subtree(ti, ett_forces_flags);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_ack, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_at, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_em, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_pri, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_reserved, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_rsrvd, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(forces_flags_tree, hf_forces_flags_tp, tvb, offset+20, 4, ENC_BIG_ENDIAN);
offset += 24;
while (tvb_reported_length_remaining(tvb, offset) >= TLV_TL_LENGTH)
{
ti = proto_tree_add_text(forces_tree, tvb, offset, TLV_TL_LENGTH, "TLV");
forces_tlv_tree = proto_item_add_subtree(ti, ett_forces_tlv);
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_item = proto_tree_add_item(forces_tlv_tree, hf_forces_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
length_count = tvb_get_ntohs(tvb, offset+2) * 4;
proto_item_set_len(ti, length_count);
ti = proto_tree_add_uint_format_value(forces_tlv_tree, hf_forces_tlv_length,
tvb, offset+2, 2, length_count, "%u Bytes", length_count);
if (tvb_reported_length_remaining(tvb, offset) < length_count)
expert_add_info_format(pinfo, ti, &ei_forces_tlv_length, "Bogus: Main TLV length (%u bytes) is wrong", length_count);
if (length_count < TLV_TL_LENGTH)
{
expert_add_info_format(pinfo, ti, &ei_forces_tlv_length, "Bogus TLV length: %u", length_count);
break;
}
offset += TLV_TL_LENGTH;
length_count -= TLV_TL_LENGTH;
switch(tlv_type)
{
case LFBselect_TLV:
ti = proto_tree_add_text(forces_tlv_tree, tvb, offset, length_count, "LFB select TLV");
tlv_tree = proto_item_add_subtree(ti, ett_forces_lfbselect_tlv_type);
dissect_lfbselecttlv(tvb, pinfo, tlv_tree, offset, length_count);
break;
case REDIRECT_TLV:
ti = proto_tree_add_text(forces_tlv_tree, tvb, offset, length_count, "Redirect TLV");
tlv_tree = proto_item_add_subtree(ti, ett_forces_redirect_tlv_type);
dissect_redirecttlv(tvb, pinfo, tlv_tree, offset);
break;
case ASResult_TLV:
ti = proto_tree_add_text(forces_tlv_tree, tvb, offset, length_count, "ASResult TLV");
tlv_tree = proto_item_add_subtree(ti, ett_forces_asresult_tlv);
proto_tree_add_item(tlv_tree, hf_forces_asresult_association_setup_result, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case ASTreason_TLV:
ti = proto_tree_add_text(forces_tlv_tree, tvb, offset, length_count, "ASTreason TLV");
tlv_tree = proto_item_add_subtree(ti, ett_forces_astreason_tlv);
proto_tree_add_item(tlv_tree, hf_forces_astreason_tlv_teardown_reason, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
expert_add_info(pinfo, tlv_item, &ei_forces_tlv_type);
ti = proto_tree_add_text(forces_tlv_tree, tvb, offset, length_count, "Unknown TLV");
tlv_tree = proto_item_add_subtree(ti, ett_forces_unknown_tlv);
proto_tree_add_item(tlv_tree, hf_forces_unknown_tlv, tvb, offset, length_count, ENC_NA);
break;
}
offset += length_count;
}
}
static void
dissect_forces_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_forces(tvb, pinfo, tree, TCP_UDP_TML_FOCES_MESSAGE_OFFSET_TCP);
}
static void
dissect_forces_not_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_forces(tvb, pinfo, tree, 0);
}
void
proto_register_forces(void)
{
module_t *forces_module;
expert_module_t* expert_forces;
static hf_register_info hf[] = {
{ &hf_forces_version,
{ "Version", "forces.flags.version",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_forces_rsvd,
{ "Rsvd", "forces.flags.rsvd",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_forces_messagetype,
{ "Message Type", "forces.messagetype",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_length,
{ "Header Length", "forces.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_sid,
{ "Source ID", "forces.sid",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_did,
{ "Destination ID", "forces.did",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_correlator,
{ "Correlator", "forces.correlator",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_tlv_type,
{ "Type", "forces.tlv.type",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_tlv_length,
{ "Length", "forces.tlv.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_flags,
{ "Flags", "forces.Flags",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_flags_ack,
{ "ACK indicator", "forces.flags.ack",
FT_UINT32, BASE_DEC, VALS(main_header_flags_ack_vals), 0xC0000000, NULL, HFILL }
},
{ &hf_forces_flags_pri,
{ "Priority", "forces.flags.pri",
FT_UINT32, BASE_DEC, NULL, 0x38000000, NULL, HFILL }
},
{ &hf_forces_flags_rsrvd,
{ "Rsrvd", "forces.Flags",
FT_UINT32, BASE_DEC,NULL, 0x07000000, NULL, HFILL }
},
{ &hf_forces_flags_em,
{ "Execution mode", "forces.flags.em",
FT_UINT32, BASE_DEC, VALS(main_header_flags_em_vals), 0x00C00000, NULL, HFILL }
},
{ &hf_forces_flags_at,
{ "Atomic Transaction", "forces.flags.at",
FT_UINT32, BASE_DEC, VALS(main_header_flags_at_vals), 0x00200000, NULL, HFILL }
},
{ &hf_forces_flags_tp,
{ "Transaction phase", "forces.flags.tp",
FT_UINT32, BASE_DEC, VALS(main_header_flags_tp_vals), 0x00180000, NULL, HFILL }
},
{ &hf_forces_flags_reserved,
{ "Reserved", "forces.flags.reserved",
FT_UINT32, BASE_DEC,NULL, 0x0007ffff, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_lfb_classid,
{ "Class ID", "forces.lfbselect.tlv.type.lfb.classid",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_lfb_instanceid,
{ "Instance ID", "forces.fbselect.tlv.type.lfb.instanceid",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_type,
{ "Type", "forces.lfbselect.tlv.type.operation.type",
FT_UINT16, BASE_DEC, VALS(operation_type_vals), 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_length,
{ "Length", "forces.lfbselect.tlv.type.operation.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_type,
{ "Type", "forces.lfbselect.tlv.type.operation.path.type",
FT_UINT16, BASE_DEC, VALS(tlv_type_vals), 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_length,
{ "Length", "forces.lfbselect.tlv.type.operation.path.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_data,
{ "Data", "forces.lfbselect.tlv.type.operation.path.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_flags,
{"Path Data Flags", "forces.lfbselect.tlv.type.operation.path.data.flags",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_flags_selector,
{"Selector", "forces.lfbselect.tlv.type.operation.path.data.flags.selector",
FT_UINT16, BASE_HEX, NULL, 0x80, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_flags_reserved,
{"Reserved", "forces.lfbselect.tlv.type.operation.path.data.flags.reserved",
FT_UINT16, BASE_HEX, NULL, 0x7F, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_IDcount,
{ "Path Data IDcount", "forces.lfbselect.tlv.type.operation.path.data.IDcount",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_lfbselect_tlv_type_operation_path_IDs,
{ "Path Data IDs", "forces.lfbselect.tlv.type.operation.path.data.IDs",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{&hf_forces_redirect_tlv_meta_data_tlv_type,
{ "Type", "forces.redirect.tlv.meta.data.tlv.type",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_redirect_tlv_meta_data_tlv_length,
{ "Length", "forces.redirect.tlv.meta.data.tlv.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_redirect_tlv_meta_data_tlv_meta_data_ilv,
{ "Meta Data ILV", "forces.redirect.tlv.meta.data.tlv.meta.data.ilv",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_redirect_tlv_meta_data_tlv_meta_data_ilv_id,
{ "ID", "forces.redirect.tlv.meta.data.tlv.meta.data.ilv.id",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_redirect_tlv_meta_data_tlv_meta_data_ilv_length,
{ "Length", "forces.redirect.tlv.meta.data.tlv.meta.data.ilv.length",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_redirect_tlv_redirect_data_tlv_type,
{ "Type", "forces.redirect.tlv.redirect.data.tlv.type",
FT_UINT16, BASE_DEC, VALS(tlv_type_vals), 0x0, NULL, HFILL }
},
{ &hf_forces_redirect_tlv_redirect_data_tlv_length,
{ "Length", "forces.redirect.tlv.redirect.data.tlv.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_forces_asresult_association_setup_result,
{ "Association Setup Result", "forces.teardown.reason",
FT_UINT32, BASE_DEC, VALS(association_setup_result_at_vals), 0x0, NULL, HFILL }
},
{ &hf_forces_astreason_tlv_teardown_reason,
{ "AStreason TLV TearDonw Reason", "forces.astreason.tlv.teardonw.reason",
FT_UINT32, BASE_DEC, VALS(teardown_reason_at_vals), 0x0, NULL, HFILL }
},
{ &hf_forces_unknown_tlv,
{ "Data", "forces.unknown.tlv",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_forces,
&ett_forces_main_header,
&ett_forces_flags,
&ett_forces_tlv,
&ett_forces_lfbselect_tlv_type,
&ett_forces_lfbselect_tlv_type_operation,
&ett_forces_lfbselect_tlv_type_operation_path,
&ett_forces_lfbselect_tlv_type_operation_path_data,
&ett_forces_lfbselect_tlv_type_operation_path_data_path,
&ett_forces_lfbselect_tlv_type_operation_path_selector,
&ett_forces_path_data_tlv,
&ett_forces_path_data_tlv_flags,
&ett_forces_redirect_tlv_type,
&ett_forces_redirect_tlv_meta_data_tlv,
&ett_forces_redirect_tlv_redirect_data_tlv,
&ett_forces_redirect_tlv_meta_data_tlv_meta_data_ilv,
&ett_forces_asresult_tlv,
&ett_forces_astreason_tlv,
&ett_forces_unknown_tlv
};
static ei_register_info ei[] = {
{ &ei_forces_length, { "forces.length.bad", PI_PROTOCOL, PI_WARN, "ForCES Header length is wrong", EXPFILL }},
{ &ei_forces_tlv_type, { "forces.tlv.type.unknown", PI_PROTOCOL, PI_WARN, "Bogus: The Main_TLV type is unknown", EXPFILL }},
{ &ei_forces_tlv_length, { "forces.tlv.length.bad", PI_PROTOCOL, PI_WARN, "Bogus TLV length", EXPFILL }},
{ &ei_forces_lfbselect_tlv_type_operation_path_length, { "forces.lfbselect.tlv.type.operation.path.length.bad", PI_PROTOCOL, PI_WARN, "Bogus TLV length", EXPFILL }},
{ &ei_forces_lfbselect_tlv_type_operation_type, { "forces.lfbselect.tlv.type.operation.type.unsupported", PI_PROTOCOL, PI_WARN, "ForCES Operation TLV is not supported", EXPFILL }},
{ &ei_forces_redirect_tlv_redirect_data_tlv_length, { "forces.redirect.tlv.redirect.data.tlv.length.bad", PI_PROTOCOL, PI_WARN, "Redirect Data TLV length is wrong", EXPFILL }},
};
proto_forces = proto_register_protocol("Forwarding and Control Element Separation Protocol", "ForCES", "forces");
proto_register_field_array(proto_forces, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_forces = expert_register_protocol(proto_forces);
expert_register_field_array(expert_forces, ei, array_length(ei));
forces_module = prefs_register_protocol(proto_forces,proto_reg_handoff_forces);
prefs_register_uint_preference(forces_module, "tcp_alternate_port",
"TCP port",
"Decode packets on this TCP port as ForCES",
10, &forces_alternate_tcp_port);
prefs_register_uint_preference(forces_module, "udp_alternate_port",
"UDP port",
"Decode packets on this UDP port as ForCES",
10, &forces_alternate_udp_port);
prefs_register_uint_preference(forces_module, "sctp_high_prio_port",
"SCTP High Priority channel port",
"Decode packets on this sctp port as ForCES",
10, &forces_alternate_sctp_high_prio_channel_port);
prefs_register_uint_preference(forces_module, "sctp_med_prio_port",
"SCTP Meidium Priority channel port",
"Decode packets on this sctp port as ForCES",
10, &forces_alternate_sctp_med_prio_channel_port);
prefs_register_uint_preference(forces_module, "sctp_low_prio_port",
"SCTP Low Priority channel port",
"Decode packets on this sctp port as ForCES",
10, &forces_alternate_sctp_low_prio_channel_port);
}
void
proto_reg_handoff_forces(void)
{
static gboolean inited = FALSE;
static guint alternate_tcp_port = 0;
static guint alternate_udp_port = 0;
static guint alternate_sctp_high_prio_channel_port = 0;
static guint alternate_sctp_med_prio_channel_port = 0;
static guint alternate_sctp_low_prio_channel_port = 0;
static dissector_handle_t forces_handle_tcp, forces_handle;
if (!inited) {
forces_handle_tcp = create_dissector_handle(dissect_forces_tcp, proto_forces);
forces_handle = create_dissector_handle(dissect_forces_not_tcp, proto_forces);
ip_handle = find_dissector("ip");
inited = TRUE;
}
if ((alternate_tcp_port != 0) && (alternate_tcp_port != forces_alternate_tcp_port))
dissector_delete_uint("tcp.port", alternate_tcp_port, forces_handle_tcp);
if ((forces_alternate_tcp_port != 0) && (alternate_tcp_port != forces_alternate_tcp_port))
dissector_add_uint("tcp.port", forces_alternate_tcp_port, forces_handle_tcp);
alternate_tcp_port = forces_alternate_tcp_port;
if ((alternate_udp_port != 0) && (alternate_udp_port != forces_alternate_udp_port))
dissector_delete_uint("udp.port", alternate_udp_port, forces_handle);
if ((forces_alternate_udp_port != 0) && (alternate_udp_port != forces_alternate_udp_port))
dissector_add_uint("udp.port", forces_alternate_udp_port, forces_handle);
alternate_udp_port = forces_alternate_udp_port;
if ((alternate_sctp_high_prio_channel_port != 0) &&
(alternate_sctp_high_prio_channel_port != forces_alternate_sctp_high_prio_channel_port))
dissector_delete_uint("sctp.port", alternate_sctp_high_prio_channel_port, forces_handle);
if ((forces_alternate_sctp_high_prio_channel_port != 0) &&
(alternate_sctp_high_prio_channel_port != forces_alternate_sctp_high_prio_channel_port))
dissector_add_uint("sctp.port", forces_alternate_sctp_high_prio_channel_port, forces_handle);
alternate_sctp_high_prio_channel_port = forces_alternate_sctp_high_prio_channel_port;
if ((alternate_sctp_med_prio_channel_port != 0) &&
(alternate_sctp_med_prio_channel_port != forces_alternate_sctp_med_prio_channel_port))
dissector_delete_uint("udp.port", alternate_sctp_med_prio_channel_port, forces_handle);
if ((forces_alternate_sctp_med_prio_channel_port != 0) &&
(alternate_sctp_med_prio_channel_port != forces_alternate_sctp_med_prio_channel_port))
dissector_add_uint("udp.port", forces_alternate_sctp_med_prio_channel_port, forces_handle);
alternate_sctp_med_prio_channel_port = forces_alternate_sctp_med_prio_channel_port;
if ((alternate_sctp_low_prio_channel_port != 0) &&
(alternate_sctp_low_prio_channel_port != forces_alternate_sctp_low_prio_channel_port))
dissector_delete_uint("udp.port", alternate_sctp_low_prio_channel_port, forces_handle);
if ((forces_alternate_sctp_low_prio_channel_port != 0) &&
(alternate_sctp_low_prio_channel_port != forces_alternate_sctp_low_prio_channel_port))
dissector_add_uint("udp.port", forces_alternate_sctp_low_prio_channel_port, forces_handle);
alternate_sctp_low_prio_channel_port = forces_alternate_sctp_low_prio_channel_port;
}
