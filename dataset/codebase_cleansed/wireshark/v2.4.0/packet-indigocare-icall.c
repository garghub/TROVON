static int
dissect_icall(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_)
{
proto_item *ti;
proto_item *header_item;
proto_tree *icall_tree;
proto_tree *icall_header_tree;
gint32 current_offset = 0, header_offset, identifier_start, identifier_offset, data_start, data_offset, ett;
gint32 header;
gint32 record_identifier;
const guint8 * record_data;
if ( tvb_get_guint8(tvb, 0) != INDIGOCARE_ICALL_SOH )
return 0;
if ((pinfo->phdr->caplen == pinfo->phdr->len) && ( tvb_get_guint8(tvb, tvb_reported_length(tvb) - 1) != INDIGOCARE_ICALL_EOT ))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "iCall");
col_clear(pinfo->cinfo,COL_INFO);
ti = proto_tree_add_item(tree, proto_icall, tvb, 0, -1, ENC_NA);
icall_tree = proto_item_add_subtree(ti, ett_icall);
current_offset++;
header_offset = tvb_find_guint8(tvb, current_offset, -1, INDIGOCARE_ICALL_STX);
ws_strtoi32(tvb_get_string_enc(wmem_packet_scope(), tvb, current_offset, header_offset - current_offset, ENC_NA), NULL, &header);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s:", val_to_str(header, icall_headertypenames, "Unknown (%d)"));
switch(header) {
case INDIGOCARE_ICALL_CALL:
ett = ett_icall_call;
break;
default:
proto_tree_add_expert_format(icall_tree, pinfo, &ei_icall_unexpected_header, tvb, current_offset, header_offset - current_offset, "Unexpected header %d", header);
return 0;
break;
}
header_item = proto_tree_add_uint_format(icall_tree, hf_icall_header_type, tvb, current_offset, header_offset - current_offset, header, "%s", val_to_str(header, icall_headertypenames, "Unknown (%d)"));
icall_header_tree = proto_item_add_subtree(header_item, ett);
current_offset = header_offset + 1;
while (tvb_get_guint8(tvb, current_offset) != INDIGOCARE_ICALL_ETX) {
identifier_start = current_offset;
identifier_offset = tvb_find_guint8(tvb, current_offset, -1, INDIGOCARE_ICALL_US);
ws_strtoi32(tvb_get_string_enc(wmem_packet_scope(), tvb, current_offset, identifier_offset - current_offset, ENC_NA), NULL, &record_identifier);
current_offset = identifier_offset + 1;
data_start = current_offset;
data_offset = tvb_find_guint8(tvb, data_start, -1, INDIGOCARE_ICALL_RS);
record_data = tvb_get_string_enc(wmem_packet_scope(), tvb, current_offset, data_offset - data_start, ENC_NA);
current_offset = data_offset + 1;
switch (header) {
case INDIGOCARE_ICALL_CALL:
switch (record_identifier) {
case INDIGOCARE_ICALL_CALL_ROOM:
proto_tree_add_item_ret_string(icall_header_tree, hf_icall_call_room_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA, wmem_packet_scope(), &record_data);
col_append_fstr(pinfo->cinfo, COL_INFO, " Room=%s", record_data);
break;
case INDIGOCARE_ICALL_CALL_TYPE:
proto_tree_add_item_ret_string(icall_header_tree, hf_icall_call_type_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA, wmem_packet_scope(), &record_data);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type=%s", record_data);
break;
case INDIGOCARE_ICALL_CALL_ADDITION:
proto_tree_add_item(icall_header_tree, hf_icall_call_addition_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA);
break;
case INDIGOCARE_ICALL_CALL_ID:
proto_tree_add_item(icall_header_tree, hf_icall_call_id_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA);
break;
case INDIGOCARE_ICALL_CALL_TASK:
proto_tree_add_item(icall_header_tree, hf_icall_call_task_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA);
break;
case INDIGOCARE_ICALL_CALL_LOCATION:
proto_tree_add_item_ret_string(icall_header_tree, hf_icall_call_location_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA, wmem_packet_scope(), &record_data);
col_append_fstr(pinfo->cinfo, COL_INFO, " Location=%s", record_data);
break;
case INDIGOCARE_ICALL_CALL_NAME1:
proto_tree_add_item_ret_string(icall_header_tree, hf_icall_call_name1_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA, wmem_packet_scope(), &record_data);
col_append_fstr(pinfo->cinfo, COL_INFO, " Name 1=%s", record_data);
break;
case INDIGOCARE_ICALL_CALL_NAME2:
proto_tree_add_item_ret_string(icall_header_tree, hf_icall_call_name2_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA, wmem_packet_scope(), &record_data);
col_append_fstr(pinfo->cinfo, COL_INFO, " Name 2=%s", record_data);
break;
case INDIGOCARE_ICALL_CALL_TYPE_NUMERICAL:
proto_tree_add_item(icall_header_tree, hf_icall_call_numerical_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA);
break;
case INDIGOCARE_ICALL_CALL_NURSE:
proto_tree_add_item(icall_header_tree, hf_icall_call_nurse_type, tvb, data_start, data_offset - data_start, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_expert_format(icall_header_tree, pinfo, &ei_icall_unexpected_record, tvb, identifier_start, data_offset - identifier_start, "Unexpected record %d with value %s", record_identifier, record_data);
break;
}
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_icall(void)
{
dissector_handle_t icall_handle;
icall_handle = create_dissector_handle(dissect_icall, proto_icall);
dissector_add_for_decode_as("udp.port", icall_handle);
dissector_add_for_decode_as("tcp.port", icall_handle);
}
void
proto_register_icall(void)
{
static hf_register_info hf[] = {
{ &hf_icall_header_type,
{ "Header Type", "icall.header",
FT_UINT32, BASE_DEC,
VALS(icall_headertypenames), 0x0,
NULL, HFILL }
},
{ &hf_icall_call_room_type,
{ "Room", "icall.call.room",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_type_type,
{ "Type", "icall.call.type",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_addition_type,
{ "Addition", "icall.call.addition",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_id_type,
{ "ID", "icall.call.id",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_task_type,
{ "Task", "icall.call.task",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_location_type,
{ "Location", "icall.call.location",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_name1_type,
{ "Name 1", "icall.call.name1",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_name2_type,
{ "Name 2", "icall.call.name2",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_numerical_type,
{ "Type Numerical", "icall.call.type_numerical",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_icall_call_nurse_type,
{ "Nurse", "icall.call.nurse",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_icall_unexpected_header, { "icall.unexpected.header", PI_MALFORMED, PI_WARN, "Unexpected header", EXPFILL }},
{ &ei_icall_unexpected_record, { "icall.unexpected.record", PI_MALFORMED, PI_WARN, "Unexpected record", EXPFILL }}
};
expert_module_t* expert_icall;
static gint *ett[] = {
&ett_icall,
&ett_icall_call,
&ett_icall_unknown
};
proto_icall = proto_register_protocol (
"iCall Communication Protocol",
"iCall",
"icall"
);
proto_register_field_array(proto_icall, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_icall = expert_register_protocol(proto_icall);
expert_register_field_array(expert_icall, ei, array_length(ei));
}
