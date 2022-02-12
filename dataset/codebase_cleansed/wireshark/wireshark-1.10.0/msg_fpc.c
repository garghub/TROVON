void dissect_mac_mgmt_msg_fpc_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
guint i;
guint number_stations;
guint tvb_len, payload_type;
proto_item *fpc_item = NULL;
proto_tree *fpc_tree = NULL;
gint8 value;
gfloat power_change;
payload_type = tvb_get_guint8(tvb, 0);
if(payload_type != MAC_MGMT_MSG_FPC)
{
return;
}
if (tree)
{
tvb_len = tvb_reported_length(tvb);
fpc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_fpc_decoder, tvb, 0, tvb_len, "MAC Management Message, FPC (38)");
fpc_tree = proto_item_add_subtree(fpc_item, ett_mac_mgmt_msg_fpc_decoder);
proto_tree_add_item(fpc_tree, hf_fpc_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(fpc_tree, hf_fpc_number_of_stations, tvb, offset, 1, ENC_BIG_ENDIAN);
number_stations = tvb_get_guint8(tvb, offset);
offset++;
for (i = 0; i < number_stations; i++ ) {
proto_tree_add_item(fpc_tree, hf_fpc_basic_cid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
value = (gint8)tvb_get_guint8(tvb, offset);
power_change = (float)0.25 * value;
proto_tree_add_float_format_value(fpc_tree, hf_fpc_power_adjust, tvb, offset, 1, power_change, " %.2f dB", power_change);
offset++;
proto_tree_add_item(fpc_tree, hf_fpc_power_measurement_frame, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if ( offset >= tvb_len ) {
break;
}
}
}
}
void proto_register_mac_mgmt_msg_fpc(void)
{
static hf_register_info hf[] =
{
{
&hf_fpc_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.fpc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
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
