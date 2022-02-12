static int
dissect_aruba_erm_pcap(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *aruba_erm_tree, gint offset)
{
nstime_t ts;
ts.secs = tvb_get_ntohl(tvb, 0);
ts.nsecs = tvb_get_ntohl(tvb,4)*1000;
proto_tree_add_time(aruba_erm_tree, hf_aruba_erm_time, tvb, offset, 8,&ts);
offset +=8;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_incl_len, tvb, 8, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_orig_len, tvb, 12, 4, ENC_BIG_ENDIAN);
offset +=4;
return offset;
}
static proto_tree *
dissect_aruba_erm_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset _U_)
{
proto_item *ti;
proto_tree *aruba_erm_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_set_str(pinfo->cinfo, COL_INFO, PROTO_SHORT_NAME);
ti = proto_tree_add_item(tree, proto_aruba_erm, tvb, 0, 0, ENC_NA);
aruba_erm_tree = proto_item_add_subtree(ti, ett_aruba_erm);
return aruba_erm_tree;
}
static int
dissect_aruba_erm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
if (!dissector_try_uint(aruba_erm_subdissector_table, 0, tvb, pinfo, tree)) {
dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
proto_tree_add_expert(tree, pinfo, &ei_aruba_erm_decode, tvb, offset, -1);
call_data_dissector(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_aruba_erm_type0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t * next_tvb;
int offset = 0;
proto_tree *aruba_erm_tree;
aruba_erm_tree = dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
offset = dissect_aruba_erm_pcap(tvb, pinfo, aruba_erm_tree, offset);
proto_item_set_len(aruba_erm_tree, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(wlan_withfcs_handle, next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_aruba_erm_type1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
call_dissector_with_data(peek_handle, tvb, pinfo, tree, GUINT_TO_POINTER(IS_ARUBA));
return tvb_captured_length(tvb);
}
static int
dissect_aruba_erm_type2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
proto_tree_add_expert(tree, pinfo, &ei_aruba_erm_airmagnet, tvb, offset, -1);
call_data_dissector(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_aruba_erm_type3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t * next_tvb;
int offset = 0;
proto_tree *aruba_erm_tree;
struct ieee_802_11_phdr phdr;
guint32 signal_strength;
proto_item *ti_data_rate;
guint16 data_rate;
guint channel;
aruba_erm_tree = dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
offset = dissect_aruba_erm_pcap(tvb, pinfo, aruba_erm_tree, offset);
memset(&phdr, 0, sizeof(phdr));
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
phdr.has_data_rate = TRUE;
data_rate = tvb_get_ntohs(tvb, offset);
phdr.data_rate = data_rate;
proto_tree_add_item(aruba_erm_tree, hf_aruba_erm_data_rate, tvb, offset, 2, ENC_BIG_ENDIAN);
ti_data_rate = proto_tree_add_float_format(aruba_erm_tree, hf_aruba_erm_data_rate_gen,
tvb, 16, 2,
(float)data_rate / 2,
"Data Rate: %.1f Mb/s",
(float)data_rate / 2);
PROTO_ITEM_SET_GENERATED(ti_data_rate);
offset += 2;
proto_tree_add_item_ret_uint(aruba_erm_tree, hf_aruba_erm_channel, tvb, offset, 1, ENC_BIG_ENDIAN, &channel);
phdr.has_channel = TRUE;
phdr.channel = channel;
offset += 1;
proto_tree_add_item_ret_uint(aruba_erm_tree, hf_aruba_erm_signal_strength, tvb, offset, 1, ENC_BIG_ENDIAN, &signal_strength);
phdr.has_signal_percent = TRUE;
phdr.signal_percent = signal_strength;
offset += 1;
proto_item_set_len(aruba_erm_tree, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if(signal_strength == 100){
phdr.fcs_len = 0;
} else {
phdr.fcs_len = 4;
}
call_dissector_with_data(wlan_radio_handle, next_tvb, pinfo, tree, &phdr);
return tvb_captured_length(tvb);
}
static int
dissect_aruba_erm_type4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
call_dissector(ppi_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_aruba_erm_type5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
dissect_aruba_erm_common(tvb, pinfo, tree, &offset);
call_dissector_with_data(peek_handle, tvb, pinfo, tree, GUINT_TO_POINTER(IS_ARUBA));
return tvb_captured_length(tvb);
}
static void
aruba_erm_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Aruba ERM payload as");
}
static gpointer
aruba_erm_value(packet_info *pinfo _U_)
{
return NULL;
}
void
proto_register_aruba_erm(void)
{
static hf_register_info hf[] = {
{ &hf_aruba_erm_time,
{ "Packet Capture Timestamp", "aruba_erm.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL,
0x00, NULL, HFILL }},
{ &hf_aruba_erm_incl_len,
{ "Packet Captured Length", "aruba_erm.incl_len", FT_UINT32, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_aruba_erm_orig_len,
{ "Packet Length", "aruba_erm.orig_len", FT_UINT32, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_aruba_erm_data_rate,
{ "Data Rate", "aruba_erm.data_rate", FT_UINT16, BASE_DEC, NULL,
0x00, "Data rate (1/2 Mb/s)", HFILL }},
{ &hf_aruba_erm_data_rate_gen,
{ "Data Rate", "aruba_erm.data_rate_gen", FT_FLOAT, BASE_NONE, NULL,
0x00, "Data rate (1/2 Mb/s)", HFILL }},
{ &hf_aruba_erm_channel,
{ "Channel", "aruba_erm.channel", FT_UINT8, BASE_DEC, NULL,
0x00, "802.11 channel number that this frame was sent/received on", HFILL }},
{ &hf_aruba_erm_signal_strength,
{ "Signal Strength [percent]", "aruba_erm.signal_strength", FT_UINT8, BASE_DEC, NULL,
0x00, "Signal strength (Percentage)", HFILL }},
};
static gint *ett[] = {
&ett_aruba_erm,
};
static ei_register_info ei[] = {
{ &ei_aruba_erm_airmagnet, { "aruba_erm.airmagnet", PI_UNDECODED, PI_ERROR, "Airmagnet (type 2) is no yet supported (Please use other type)", EXPFILL }},
{ &ei_aruba_erm_decode, { "aruba_erm.decode", PI_UNDECODED, PI_NOTE, "Use Decode AS (Aruba ERM Type) for decoding payload", EXPFILL }}
};
#if 0
static const enum_val_t aruba_erm_types[] = {
{ "pcap_type_0", "pcap (type 0)", TYPE_PCAP},
{ "peek_type_1", "peek (type 1)", TYPE_PEEK},
{ "airmagnet_type_2", "Airmagnet (type 2)", TYPE_AIRMAGNET},
{ "pcapplusradio_type_3", "pcap + radio header (type 3)", TYPE_PCAPPLUSRADIO},
{ "ppi_type_4", "PPI (type 4)", TYPE_PPI},
{ NULL, NULL, -1}
};
#endif
module_t *aruba_erm_module;
static build_valid_func aruba_erm_payload_da_build_value[1] = {aruba_erm_value};
static decode_as_value_t aruba_erm_payload_da_values = {aruba_erm_prompt, 1, aruba_erm_payload_da_build_value};
static decode_as_t aruba_erm_payload_da = {
"aruba_erm", "Aruba ERM Type", "aruba_erm.type", 1, 0,
&aruba_erm_payload_da_values, NULL, NULL,
decode_as_default_populate_list,
decode_as_default_reset,
decode_as_default_change,
NULL,
};
expert_module_t* expert_aruba_erm;
proto_aruba_erm = proto_register_protocol(PROTO_LONG_NAME, "ARUBA_ERM" , "aruba_erm");
proto_aruba_erm_type0 = proto_register_protocol("Aruba Networks encapsulated remote mirroring - PCAP (Type 0)", "ARUBA ERM PCAP (Type 0)", "aruba_erm_type0");
proto_aruba_erm_type1 = proto_register_protocol("Aruba Networks encapsulated remote mirroring - PEEK (Type 1)", "ARUBA ERM PEEK (type 1)", "aruba_erm_type1");
proto_aruba_erm_type2 = proto_register_protocol("Aruba Networks encapsulated remote mirroring - AIRMAGNET (Type 2)", "ARUBA ERM AIRMAGNET (Type 2)", "aruba_erm_type2");
proto_aruba_erm_type3 = proto_register_protocol("Aruba Networks encapsulated remote mirroring - PCAP+RADIO (Type 3)", "ARUBA ERM PCAP+RADIO (Type 3)", "aruba_erm_type3");
proto_aruba_erm_type4 = proto_register_protocol("Aruba Networks encapsulated remote mirroring - PPI (Type 4)", "ARUBA ERM PPI (Type 4)", "aruba_erm_type4");
proto_aruba_erm_type5 = proto_register_protocol("Aruba Networks encapsulated remote mirroring - PEEK (Type 5)", "ARUBA ERM PEEK-NG (type 5)", "aruba_erm_type5");
range_convert_str (&global_aruba_erm_port_range, "0", MAX_UDP_PORT);
aruba_erm_module = prefs_register_protocol(proto_aruba_erm, proto_reg_handoff_aruba_erm);
prefs_register_range_preference(aruba_erm_module, "udp.ports", "ARUBA_ERM UDP Port numbers",
"Set the UDP port numbers (typically the range 5555 to 5560) used for Aruba Networks"
" encapsulated remote mirroring frames;\n"
"0 (default) means that the ARUBA_ERM dissector is not active\n",
&global_aruba_erm_port_range, MAX_UDP_PORT);
#if 0
prefs_register_enum_preference(aruba_erm_module, "type.captured",
"Type of formats for captured packets",
"Type of formats for captured packets",
&aruba_erm_type, aruba_erm_types, FALSE);
#endif
prefs_register_obsolete_preference(aruba_erm_module, "type.captured");
proto_register_field_array(proto_aruba_erm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_aruba_erm = expert_register_protocol(proto_aruba_erm);
expert_register_field_array(expert_aruba_erm, ei, array_length(ei));
aruba_erm_subdissector_table = register_dissector_table(
"aruba_erm.type", "Aruba ERM Type", proto_aruba_erm,
FT_UINT32, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
register_decode_as(&aruba_erm_payload_da);
}
void
proto_reg_handoff_aruba_erm(void)
{
static range_t *aruba_erm_port_range;
static range_t *aruba_erm_radio_port_range;
static gboolean initialized = FALSE;
if (!initialized) {
wlan_radio_handle = find_dissector_add_dependency("wlan_radio", proto_aruba_erm);
wlan_withfcs_handle = find_dissector_add_dependency("wlan_withfcs", proto_aruba_erm);
ppi_handle = find_dissector_add_dependency("ppi", proto_aruba_erm);
peek_handle = find_dissector_add_dependency("peekremote", proto_aruba_erm);
aruba_erm_handle = create_dissector_handle(dissect_aruba_erm, proto_aruba_erm);
aruba_erm_handle_type0 = create_dissector_handle(dissect_aruba_erm_type0, proto_aruba_erm_type0);
aruba_erm_handle_type1 = create_dissector_handle(dissect_aruba_erm_type1, proto_aruba_erm_type1);
aruba_erm_handle_type2 = create_dissector_handle(dissect_aruba_erm_type2, proto_aruba_erm_type2);
aruba_erm_handle_type3 = create_dissector_handle(dissect_aruba_erm_type3, proto_aruba_erm_type3);
aruba_erm_handle_type4 = create_dissector_handle(dissect_aruba_erm_type4, proto_aruba_erm_type4);
aruba_erm_handle_type5 = create_dissector_handle(dissect_aruba_erm_type5, proto_aruba_erm_type5);
initialized = TRUE;
} else {
dissector_delete_uint_range("udp.port", aruba_erm_port_range, aruba_erm_handle);
g_free(aruba_erm_port_range);
g_free(aruba_erm_radio_port_range);
}
aruba_erm_port_range = range_copy(global_aruba_erm_port_range);
dissector_add_uint_range("udp.port", aruba_erm_port_range, aruba_erm_handle);
dissector_add_for_decode_as("aruba_erm.type", aruba_erm_handle_type0);
dissector_add_for_decode_as("aruba_erm.type", aruba_erm_handle_type1);
dissector_add_for_decode_as("aruba_erm.type", aruba_erm_handle_type2);
dissector_add_for_decode_as("aruba_erm.type", aruba_erm_handle_type3);
dissector_add_for_decode_as("aruba_erm.type", aruba_erm_handle_type4);
dissector_add_for_decode_as("aruba_erm.type", aruba_erm_handle_type5);
}
