static void
dissect_npmp_acknowledge_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
ADD_FIELD_UINT(message_tree, acknowledge_flowid);
ADD_FIELD_UINT(message_tree, acknowledge_measurementid);
ADD_FIELD_UINT(message_tree, acknowledge_streamid);
ADD_FIELD_UINT(message_tree, acknowledge_status);
}
static void
dissect_npmp_add_flow_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
guint32 retranstrials;
proto_item* onoffitem;
proto_tree* onofftree;
guint16 onoffevents;
guint32 onoffvalue;
unsigned int i;
ADD_FIELD_UINT(message_tree, addflow_flowid);
ADD_FIELD_UINT(message_tree, addflow_measurementid);
ADD_FIELD_UINT(message_tree, addflow_streamid);
ADD_FIELD_UINT(message_tree, addflow_protocol);
ADD_FIELD_UINT(message_tree, addflow_flags);
ADD_FIELD_STRING(message_tree, addflow_description);
proto_tree_add_double_format_value(message_tree, hf_addflow_ordered, message_tvb, offset_addflow_ordered, length_addflow_ordered,
100.0 * tvb_get_ntohl(message_tvb, offset_addflow_ordered) / (double)0xffffffff, "%1.3f%%",
100.0 * tvb_get_ntohl(message_tvb, offset_addflow_ordered) / (double)0xffffffff);
proto_tree_add_double_format_value(message_tree, hf_addflow_reliable, message_tvb, offset_addflow_reliable, length_addflow_reliable,
100.0 * tvb_get_ntohl(message_tvb, offset_addflow_reliable) / (double)0xffffffff, "%1.3f%%",
100.0 * tvb_get_ntohl(message_tvb, offset_addflow_reliable) / (double)0xffffffff);
retranstrials = tvb_get_ntohl(message_tvb, offset_addflow_retranstrials);
proto_tree_add_uint_format_value(message_tree, hf_addflow_retranstrials, message_tvb, offset_addflow_retranstrials, length_addflow_retranstrials,
retranstrials, (retranstrials & (1 << 31)) ? "%u ms" : "%u trials",
retranstrials &~ (1 << 31));
ADD_FIELD_UINT(message_tree, addflow_frameraterng);
ADD_FIELD_UINT(message_tree, addflow_framerate1);
ADD_FIELD_UINT(message_tree, addflow_framerate2);
ADD_FIELD_UINT(message_tree, addflow_framerate3);
ADD_FIELD_UINT(message_tree, addflow_framerate4);
ADD_FIELD_UINT(message_tree, addflow_framesizerng);
ADD_FIELD_UINT(message_tree, addflow_framesize1);
ADD_FIELD_UINT(message_tree, addflow_framesize2);
ADD_FIELD_UINT(message_tree, addflow_framesize3);
ADD_FIELD_UINT(message_tree, addflow_framesize4);
ADD_FIELD_UINT(message_tree, addflow_rcvbuffersize);
ADD_FIELD_UINT(message_tree, addflow_sndbuffersize);
ADD_FIELD_UINT(message_tree, addflow_maxmsgsize);
ADD_FIELD_UINT(message_tree, addflow_cmt);
ADD_FIELD_UINT(message_tree, addflow_ccid);
onoffitem = ADD_FIELD_UINT(message_tree, addflow_onoffevents);
onoffevents = tvb_get_ntohs(message_tvb, offset_addflow_onoffevents);
if (onoffevents > 0) {
onofftree = proto_item_add_subtree(onoffitem, ett_onoffarray);
for(i = 0;i < onoffevents;i++) {
onoffvalue = tvb_get_ntohl(message_tvb, offset_addflow_onoffeventarray + (int)(sizeof(guint32) * i));
proto_tree_add_uint_format(onofftree, hf_addflow_onoffeventarray, message_tvb,
offset_addflow_onoffeventarray + (int)(sizeof(guint32) * i), (int)sizeof(guint32),
onoffvalue, "%1.3f s: set to %s", onoffvalue / 1000.0, (i & 1) ? "OFF" : "ON");
}
}
}
static void
dissect_npmp_remove_flow_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
ADD_FIELD_UINT(message_tree, removeflow_flowid);
ADD_FIELD_UINT(message_tree, removeflow_measurementid);
ADD_FIELD_UINT(message_tree, removeflow_streamid);
}
static void
dissect_npmp_identify_flow_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
ADD_FIELD_UINT(message_tree, identifyflow_magicnumber);
ADD_FIELD_UINT(message_tree, identifyflow_flowid);
ADD_FIELD_UINT(message_tree, identifyflow_measurementid);
ADD_FIELD_UINT(message_tree, identifyflow_streamid);
}
static void
dissect_npmp_data_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
const guint16 message_length = tvb_get_ntohs(message_tvb, offset_message_length);
ADD_FIELD_UINT(message_tree, data_flowid);
ADD_FIELD_UINT(message_tree, data_measurementid);
ADD_FIELD_UINT(message_tree, data_streamid);
ADD_FIELD_UINT(message_tree, data_padding);
ADD_FIELD_UINT(message_tree, data_frameid);
ADD_FIELD_UINT(message_tree, data_packetseqnumber);
ADD_FIELD_UINT(message_tree, data_byteseqnumber);
ADD_FIELD_UINT(message_tree, data_timestamp);
if (message_length > offset_data_payload) {
proto_tree_add_item(message_tree, hf_data_payload, message_tvb, offset_data_payload, message_length - offset_data_payload, ENC_NA);
}
}
static void
dissect_npmp_start_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
ADD_FIELD_UINT(message_tree, start_measurementid);
}
static void
dissect_npmp_stop_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
ADD_FIELD_UINT(message_tree, stop_measurementid);
}
static void
dissect_npmp_results_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
const guint16 message_length = tvb_get_guint8(message_tvb, offset_message_length);
if (message_length > offset_results_data) {
proto_tree_add_item(message_tree, hf_results_data, message_tvb, offset_results_data, message_length - offset_results_data, ENC_NA);
}
}
static void
dissect_npmp_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *npmp_tree)
{
guint8 type;
type = tvb_get_guint8(message_tvb, offset_message_type);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(type, message_type_values, "Unknown NetPerfMeterProtocol type"));
}
ADD_FIELD_UINT(npmp_tree, message_type);
ADD_FIELD_UINT(npmp_tree, message_flags);
ADD_FIELD_UINT(npmp_tree, message_length);
switch (type) {
case NETPERFMETER_ACKNOWLEDGE:
dissect_npmp_acknowledge_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_ADD_FLOW:
dissect_npmp_add_flow_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_REMOVE_FLOW:
dissect_npmp_remove_flow_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_IDENTIFY_FLOW:
dissect_npmp_identify_flow_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_DATA:
dissect_npmp_data_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_START:
dissect_npmp_start_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_STOP:
dissect_npmp_stop_message(message_tvb, npmp_tree);
break;
case NETPERFMETER_RESULTS:
dissect_npmp_results_message(message_tvb, npmp_tree);
break;
}
}
static int
dissect_npmp(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *npmp_item;
proto_tree *npmp_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NetPerfMeterProtocol");
if (tree) {
npmp_item = proto_tree_add_item(tree, proto_npmp, message_tvb, 0, -1, ENC_NA);
npmp_tree = proto_item_add_subtree(npmp_item, ett_npmp);
} else {
npmp_tree = NULL;
};
dissect_npmp_message(message_tvb, pinfo, npmp_tree);
return(TRUE);
}
void
proto_register_npmp(void)
{
static gint *ett[] = {
&ett_npmp,
&ett_onoffarray
};
proto_npmp = proto_register_protocol("NetPerfMeter Protocol", "NetPerfMeterProtocol", "npmp");
proto_register_field_array(proto_npmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_npmp(void)
{
dissector_handle_t npmp_handle;
npmp_handle = new_create_dissector_handle(dissect_npmp, proto_npmp);
dissector_add_uint("sctp.ppi", PPID_NETPERFMETER_CONTROL_LEGACY, npmp_handle);
dissector_add_uint("sctp.ppi", PPID_NETPERFMETER_DATA_LEGACY, npmp_handle);
dissector_add_uint("sctp.ppi", NPMP_CTRL_PAYLOAD_PROTOCOL_ID, npmp_handle);
dissector_add_uint("sctp.ppi", NPMP_DATA_PAYLOAD_PROTOCOL_ID, npmp_handle);
}
