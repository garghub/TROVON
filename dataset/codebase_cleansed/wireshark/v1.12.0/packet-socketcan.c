static void
dissect_socketcan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *can_tree;
proto_item *ti;
guint8 frame_type;
gint frame_len;
struct can_identifier can_id;
tvbuff_t* next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CAN");
col_clear(pinfo->cinfo,COL_INFO);
frame_len = tvb_get_guint8( tvb, CAN_LEN_OFFSET);
can_id.id = tvb_get_ntohl(tvb, 0);
if (can_id.id & CAN_RTR_FLAG)
{
frame_type = LINUX_CAN_RTR;
}
else if (can_id.id & CAN_ERR_FLAG)
{
frame_type = LINUX_CAN_ERR;
}
else if (can_id.id & CAN_EFF_FLAG)
{
frame_type = LINUX_CAN_EXT;
}
else
{
frame_type = LINUX_CAN_STD;
}
can_id.id &= CAN_EFF_MASK;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: 0x%08x",
val_to_str(frame_type, frame_type_vals, "Unknown (0x%02x)"), can_id.id);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_ep_str_punct(tvb, CAN_DATA_OFFSET, frame_len, ' '));
ti = proto_tree_add_item(tree, proto_can, tvb, 0, -1, ENC_NA);
can_tree = proto_item_add_subtree(ti, ett_can);
proto_tree_add_item(can_tree, hf_can_ident, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_extflag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_rtrflag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_errflag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_len, tvb, CAN_LEN_OFFSET, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_length(tvb, CAN_DATA_OFFSET, frame_len);
switch (can_high_level_protocol_dissector)
{
case CAN_DATA_DISSECTOR:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
case CAN_CANOPEN_DISSECTOR:
call_dissector_with_data(canopen_handle, next_tvb, pinfo, tree, &can_id);
break;
case CAN_DEVICENET_DISSECTOR:
can_id.id = GUINT32_SWAP_LE_BE(can_id.id);
call_dissector_with_data(devicenet_handle, next_tvb, pinfo, tree, &can_id);
break;
case CAN_J1939_DISSECTOR:
call_dissector_with_data(j1939_handle, next_tvb, pinfo, tree, &can_id);
break;
}
}
void
proto_register_socketcan(void)
{
static hf_register_info hf[] = {
{
&hf_can_ident,
{
"Identifier", "can.id",
FT_UINT32, BASE_HEX,
NULL, CAN_EFF_MASK,
NULL, HFILL
}
},
{
&hf_can_extflag,
{
"Extended Flag", "can.flags.xtd",
FT_BOOLEAN, 32,
NULL, CAN_EFF_FLAG,
NULL, HFILL
}
},
{
&hf_can_rtrflag,
{
"Remote Transmission Request Flag", "can.flags.rtr",
FT_BOOLEAN, 32,
NULL, CAN_RTR_FLAG,
NULL, HFILL
}
},
{
&hf_can_errflag,
{
"Error Flag", "can.flags.err",
FT_BOOLEAN, 32,
NULL, CAN_ERR_FLAG,
NULL, HFILL
}
},
{
&hf_can_len,
{
"Frame-Length", "can.len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_can
};
module_t *can_module;
proto_can = proto_register_protocol(
"Controller Area Network",
"CAN",
"can"
);
proto_register_field_array(proto_can, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
can_module = prefs_register_protocol(proto_can, NULL);
prefs_register_enum_preference(
can_module,
"protocol",
"Next level protocol",
"Next level protocol like CANopen etc.",
(gint *)&can_high_level_protocol_dissector,
can_high_level_protocol_dissector_options,
FALSE
);
}
void
proto_reg_handoff_socketcan(void)
{
dissector_handle_t can_handle;
can_handle = create_dissector_handle(dissect_socketcan, proto_can);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SOCKETCAN, can_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_CAN, can_handle);
canopen_handle = find_dissector("canopen");
devicenet_handle = find_dissector("devicenet");
j1939_handle = find_dissector("j1939");
data_handle = find_dissector("data");
}
