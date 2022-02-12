static void can_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Next level protocol as");
}
static gpointer can_value(packet_info *pinfo _U_)
{
return 0;
}
static int
dissect_socketcan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, CAN_DATA_OFFSET, frame_len, ' '));
ti = proto_tree_add_item(tree, proto_can, tvb, 0, -1, ENC_NA);
can_tree = proto_item_add_subtree(ti, ett_can);
proto_tree_add_item(can_tree, hf_can_ident, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_extflag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_rtrflag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_errflag, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(can_tree, hf_can_len, tvb, CAN_LEN_OFFSET, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_length(tvb, CAN_DATA_OFFSET, frame_len);
if (!dissector_try_uint_new(subdissector_table, 0, next_tvb, pinfo, tree, FALSE, &can_id))
{
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
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
static build_valid_func can_da_build_value[1] = {can_value};
static decode_as_value_t can_da_values = {can_prompt, 1, can_da_build_value};
static decode_as_t can_da = {"can", "Network", "can.subdissector", 1, 0, &can_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_can = proto_register_protocol(
"Controller Area Network",
"CAN",
"can"
);
register_dissector("can", dissect_socketcan, proto_can);
proto_register_field_array(proto_can, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
subdissector_table = register_dissector_table("can.subdissector",
"CAN next level dissector", proto_can, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
can_module = prefs_register_protocol(proto_can, NULL);
prefs_register_obsolete_preference(can_module, "protocol");
register_decode_as(&can_da);
}
void
proto_reg_handoff_socketcan(void)
{
dissector_handle_t can_handle;
can_handle = create_dissector_handle(dissect_socketcan, proto_can);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SOCKETCAN, can_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_CAN, can_handle);
}
