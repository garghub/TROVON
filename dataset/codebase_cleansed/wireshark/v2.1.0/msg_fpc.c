static int dissect_mac_mgmt_msg_fpc_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint i;
guint number_stations;
guint tvb_len;
proto_item *fpc_item;
proto_tree *fpc_tree;
gint8 value;
gfloat power_change;
{
tvb_len = tvb_reported_length(tvb);
fpc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_fpc_decoder, tvb, 0, -1, "MAC Management Message, FPC");
fpc_tree = proto_item_add_subtree(fpc_item, ett_mac_mgmt_msg_fpc_decoder);
proto_tree_add_item(fpc_tree, hf_fpc_number_of_stations, tvb, offset, 1, ENC_BIG_ENDIAN);
number_stations = tvb_get_guint8(tvb, offset);
offset++;
for (i = 0; ((i < number_stations) && (offset >= tvb_len)); i++ ) {
proto_tree_add_item(fpc_tree, hf_fpc_basic_cid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
value = (gint8)tvb_get_guint8(tvb, offset);
power_change = (float)0.25 * value;
proto_tree_add_float_format_value(fpc_tree, hf_fpc_power_adjust, tvb, offset, 1, power_change, " %.2f dB", power_change);
offset++;
proto_tree_add_item(fpc_tree, hf_fpc_power_measurement_frame, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_fpc(void)
{
static hf_register_info hf[] =
{
{
&hf_fpc_basic_cid,
{
"Basic CID", "wmx.fpc.basic_cid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#if 0
{
&hf_fpc_invalid_tlv,
{
"Invalid TLV", "wmx.fpc.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
#endif
{
&hf_fpc_number_of_stations,
{
"Number of stations", "wmx.fpc.number_stations",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_fpc_power_adjust,
{
"Power Adjust", "wmx.fpc.power_adjust",
FT_FLOAT, BASE_NONE, NULL, 0x0, "Signed change in power level (incr of 0.25dB) that the SS shall apply to its current power setting", HFILL
}
},
{
&hf_fpc_power_measurement_frame,
{
"Power measurement frame", "wmx.fpc.power_measurement_frame",
FT_INT8, BASE_DEC, NULL, 0x0, "The 8 LSB of the frame number in which the BS measured the power corrections referred to in the message", HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_fpc_decoder,
};
proto_mac_mgmt_msg_fpc_decoder = proto_register_protocol (
"WiMax FPC Message",
"WiMax FPC (fpc)",
"wmx.fpc"
);
proto_register_field_array(proto_mac_mgmt_msg_fpc_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mac_mgmt_msg_fpc(void)
{
dissector_handle_t fpc_handle;
fpc_handle = create_dissector_handle(dissect_mac_mgmt_msg_fpc_decoder, proto_mac_mgmt_msg_fpc_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_FPC, fpc_handle);
}
