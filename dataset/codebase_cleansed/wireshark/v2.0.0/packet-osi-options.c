static void
dissect_option_qos(const guint8 qos, proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *ti;
proto_tree *osi_qos_tree;
ti = proto_tree_add_item(tree, hf_osi_options_qos_maintenance, tvb, offset, 1, ENC_BIG_ENDIAN);
osi_qos_tree = proto_item_add_subtree(ti, ott_osi_qos);
if ( ((qos & OSI_OPT_QOS_MASK) >> 6) == OSI_OPT_QOS_GLOBAL_UNIQUE) {
proto_tree_add_item(osi_qos_tree, hf_osi_options_qos_reserved, tvb, offset, 1, ENC_NA);
proto_tree_add_item(osi_qos_tree, hf_osi_options_qos_sequencing_vs_transit_delay, tvb, offset, 1, ENC_NA);
proto_tree_add_item(osi_qos_tree, hf_osi_options_congestion_experienced, tvb, offset, 1, ENC_NA);
proto_tree_add_item(osi_qos_tree, hf_osi_options_transit_delay_vs_cost, tvb, offset, 1, ENC_NA);
proto_tree_add_item(osi_qos_tree, hf_osi_options_residual_error_prob_vs_transit_delay, tvb, offset, 1, ENC_NA);
proto_tree_add_item(osi_qos_tree, hf_osi_options_residual_error_prob_vs_cost, tvb, offset, 1, ENC_NA);
}
}
static void
dissect_option_route(guchar parm_type, int offset, guchar parm_len,
tvbuff_t *tvb, proto_tree *tree )
{
guchar next_hop = 0;
guint16 this_hop = 0;
guchar netl = 0;
guchar last_hop = 0;
guchar cnt_hops = 0;
guchar crr = 0;
gchar* str;
proto_tree *osi_route_tree = NULL;
if ( parm_type == OSI_OPT_SOURCE_ROUTING ) {
next_hop = tvb_get_guint8(tvb, offset + 1);
netl = tvb_get_guint8(tvb, next_hop + 2);
this_hop = offset + 2;
proto_tree_add_uint_format_value(tree, hf_osi_options_source_routing, tvb, offset + next_hop, netl,
tvb_get_guint8(tvb, offset), "%s ( Next Hop Highlighted In Data Buffer )",
(tvb_get_guint8(tvb, offset) == 0) ? "Partial Source Routing" :
"Complete Source Routing");
}
else if ( parm_type == OSI_OPT_RECORD_OF_ROUTE ) {
crr = tvb_get_guint8(tvb, offset);
last_hop = tvb_get_guint8(tvb, offset + 1);
osi_route_tree = proto_tree_add_subtree(tree, tvb, offset, parm_len, ott_osi_route, NULL,
(crr == 0) ? "Partial Route Recording" : "Complete Route Recording");
proto_tree_add_uint_format_value(tree, hf_osi_options_route_recording, tvb, offset, 1, crr, "%s ",
(crr == 0) ? "Partial Route Recording" :
"Complete Route Recording");
if ( last_hop == 0x03 )
proto_tree_add_uint_format(osi_route_tree, hf_osi_options_last_hop, tvb, offset + 1, 1, last_hop,
"No Network Entity Titles Recorded Yet");
if ( last_hop == 0xFF )
proto_tree_add_uint_format(osi_route_tree, hf_osi_options_last_hop, tvb, offset + 1, 1, last_hop,
"Recording Terminated : No more space !");
if ( last_hop == 255 || last_hop == 0x03 )
this_hop = parm_len + 1;
else
this_hop = offset + 2;
}
while ( this_hop < offset + last_hop -2 ) {
netl = tvb_get_guint8(tvb, this_hop);
str = print_nsap_net(tvb, this_hop + 1, netl);
proto_tree_add_string_format(osi_route_tree, hf_osi_options_route, tvb, this_hop, netl + 1, str,
"Hop #%3u NETL: %2u, NET: %s", cnt_hops++, netl, str);
this_hop += 1 + netl;
}
}
static void
dissect_option_rfd(const guchar error, const guchar field, int offset,
guchar len _U_, tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo )
{
proto_item *ti;
ti = proto_tree_add_item(tree, hf_osi_options_rfd_error_class, tvb, offset + field, 1, ENC_BIG_ENDIAN);
switch ((error & OSI_OPT_RFD_MASK) >> 4)
{
case OSI_OPT_RFD_GENERAL:
proto_tree_add_item(tree, hf_osi_options_rtd_general, tvb, offset + field, 1, ENC_BIG_ENDIAN);
break;
case OSI_OPT_RFD_ADDRESS:
proto_tree_add_item(tree, hf_osi_options_rtd_address, tvb, offset + field, 1, ENC_BIG_ENDIAN);
break;
case OSI_OPT_RFD_SOURCE_ROUTING:
proto_tree_add_item(tree, hf_osi_options_rtd_source_routing, tvb, offset + field, 1, ENC_BIG_ENDIAN);
break;
case OSI_OPT_RFD_LIFETIME:
proto_tree_add_item(tree, hf_osi_options_rtd_lifetime, tvb, offset + field, 1, ENC_BIG_ENDIAN);
break;
case OSI_OPT_RFD_PDU_DISCARDED:
proto_tree_add_item(tree, hf_osi_options_rtd_pdu_discarded, tvb, offset + field, 1, ENC_BIG_ENDIAN);
break;
case OSI_OPT_RFD_REASSEMBLY:
proto_tree_add_item(tree, hf_osi_options_rtd_reassembly, tvb, offset + field, 1, ENC_BIG_ENDIAN);
break;
default:
expert_add_info(pinfo, ti, &ei_osi_options_rfd_error_class);
}
proto_tree_add_item(tree, hf_osi_options_rfd_field, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_option_atn_security_label(const guchar sub_type, guchar length,
tvbuff_t *tvb, guint offset,
proto_tree *tree)
{
proto_tree *atn_sl_tree;
guchar len = 0;
guint8 tag_name = 0;
guint security_info_end = 0;
if ( OSI_OPT_SECURITY_ATN_SR != sub_type )
return;
len = tvb_get_guint8(tvb, ++offset);
if ( OSI_OPT_SECURITY_ATN_SR_LEN != len )
return;
if ( tvb_memeql(tvb, ++offset , atn_security_registration_val, OSI_OPT_SECURITY_ATN_SR_LEN) )
return;
atn_sl_tree = proto_tree_add_subtree(tree, tvb, offset, length, ott_osi_qos, NULL,
val_to_str(sub_type, osi_opt_sec_atn_sr_vals, "Unknown (0x%x)"));
offset += OSI_OPT_SECURITY_ATN_SR_LEN;
len = tvb_get_guint8(tvb, offset);
if ( OSI_OPT_SECURITY_ATN_SI_MAX_LEN < len )
return;
offset++;
security_info_end = offset + len;
while ( offset < security_info_end ) {
len = tvb_get_guint8(tvb, offset);
if ( len != 1 )
return;
offset++;
tag_name = tvb_get_guint8(tvb, offset);
offset++;
switch(tag_name) {
case OSI_OPT_SECURITY_ATN_TT:
len = tvb_get_guint8(tvb, offset);
if ( len != OSI_OPT_SECURITY_ATN_TT_LEN )
return;
offset++;
proto_tree_add_uint_format(atn_sl_tree, hf_clnp_atntt, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "%s: %s",
val_to_str(OSI_OPT_SECURITY_ATN_TT, osi_opt_sec_atn_si_vals, "Unknown (0x%x)"),
val_to_str(tvb_get_guint8(tvb, offset ), osi_opt_sec_atn_tt_vals, "Unknown (0x%x)"));
offset += len;
break;
case OSI_OPT_SECURITY_ATN_SC:
len = tvb_get_guint8(tvb, offset);
if ( len != OSI_OPT_SECURITY_ATN_SC_LEN )
return;
offset++;
proto_tree_add_uint_format(atn_sl_tree, hf_clnp_atnsc, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "%s: %s",
val_to_str(OSI_OPT_SECURITY_ATN_SC, osi_opt_sec_atn_si_vals, "Unknown (0x%x)"),
val_to_str(tvb_get_guint8(tvb, offset ), osi_opt_sec_atn_sc_vals, "Unknown (0x%x)"));
offset += len;
break;
default:
return;
}
}
}
void
dissect_osi_options(guchar opt_len, tvbuff_t *tvb, int offset, proto_tree *tree, packet_info *pinfo)
{
proto_item *ti;
proto_tree *osi_option_tree = NULL;
guchar parm_len = 0;
guchar parm_type = 0;
guint8 octet;
osi_option_tree = proto_tree_add_subtree(tree, tvb, offset, opt_len,
ott_osi_options, &ti, "### Option Section ###");
if ( 0 == opt_len ) {
expert_add_info(pinfo, ti, &ei_osi_options_none);
return;
}
while ( 0 < opt_len ) {
parm_type = tvb_get_guint8(tvb, offset++);
parm_len = tvb_get_guint8(tvb, offset++);
switch ( parm_type ) {
case OSI_OPT_QOS_MAINTANANCE:
octet = tvb_get_guint8(tvb, offset);
dissect_option_qos(octet, osi_option_tree, tvb, offset);
break;
case OSI_OPT_SECURITY:
octet = tvb_get_guint8(tvb, offset);
if ( clnp_decode_atn_options ) {
dissect_option_atn_security_label(octet,parm_len,tvb, offset,
osi_option_tree);
} else {
ti = proto_tree_add_item(osi_option_tree, hf_osi_options_security_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_len(ti, parm_len);
}
break;
case OSI_OPT_PRIORITY:
octet = tvb_get_guint8(tvb, offset);
if ( OSI_OPT_MAX_PRIORITY >= octet ) {
ti = proto_tree_add_item(osi_option_tree, hf_osi_options_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_uint_format_value(osi_option_tree, hf_osi_options_priority, tvb, offset, 1,
octet, "%u ( Invalid )", octet);
}
proto_item_set_len(ti, parm_len);
break;
case OSI_OPT_ADDRESS_MASK:
proto_tree_add_bytes_format_value(osi_option_tree, hf_osi_options_address_mask, tvb, offset, parm_len,
NULL, "%s",
print_area(tvb, offset, parm_len));
break;
case OSI_OPT_SNPA_MASK:
proto_tree_add_item(osi_option_tree, hf_osi_options_snpa_mask, tvb, offset, parm_len, ENC_NA);
break;
case OSI_OPT_ES_CONFIG_TIMER:
ti = proto_tree_add_item(osi_option_tree, hf_osi_options_esct, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_set_len(ti, parm_len); break;
case OSI_OPT_PADDING:
proto_tree_add_item(osi_option_tree, hf_osi_options_padding, tvb, offset, parm_len, ENC_NA);
break;
case OSI_OPT_SOURCE_ROUTING:
case OSI_OPT_RECORD_OF_ROUTE:
dissect_option_route(parm_type, offset, parm_len, tvb,
osi_option_tree);
break;
case OSI_OPT_REASON_OF_DISCARD:
dissect_option_rfd(tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1), offset, parm_len,
tvb, osi_option_tree, pinfo);
break;
}
opt_len -= parm_len + 2;
offset += parm_len;
}
}
void
proto_register_osi_options(void) {
static hf_register_info hf[] =
{
{ &hf_osi_options_qos_maintenance, { "Quality of service maintenance", "osi.options.qos.maintenance", FT_UINT8, BASE_DEC, VALS(osi_opt_qos_vals), OSI_OPT_QOS_MASK, NULL, HFILL }},
{ &hf_osi_options_qos_reserved, { "Reserved", "osi.options.qos.reserved", FT_BOOLEAN, 8, NULL, OSI_OPT_QOS_SUB_RSVD, NULL, HFILL }},
{ &hf_osi_options_qos_sequencing_vs_transit_delay, { "Sequencing versus transit delay", "osi.options.qos.seq_vs_trs", FT_BOOLEAN, 8, NULL, OSI_OPT_QOS_SUB_SEQ_VS_TRS, NULL, HFILL }},
{ &hf_osi_options_congestion_experienced, { "Congestion experienced", "osi.options.qos.cong_exped", FT_BOOLEAN, 8, NULL, OSI_OPT_QOS_SUB_CONG_EXPED, NULL, HFILL }},
{ &hf_osi_options_transit_delay_vs_cost, { "Transit delay versus cost", "osi.options.qos.tsd_vs_cost", FT_BOOLEAN, 8, NULL, OSI_OPT_QOS_SUB_TSD_VS_COST, NULL, HFILL }},
{ &hf_osi_options_residual_error_prob_vs_transit_delay, { "Residual error probability versus transit delay", "osi.options.qos.reserror_trs", FT_BOOLEAN, 8, NULL, OSI_OPT_QOS_SUB_RESERR_TRS, NULL, HFILL }},
{ &hf_osi_options_residual_error_prob_vs_cost, { "Residual error probability versus cost", "osi.options.qos.reserror_cost", FT_BOOLEAN, 8, NULL, OSI_OPT_QOS_SUB_RESERR_COST, NULL, HFILL }},
{ &hf_osi_options_source_routing, { "Source Routing", "osi.options.source_routing", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_route_recording, { "Route Recording", "osi.options.route_recording", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_last_hop, { "Last Hop", "osi.options.last_hop", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_route, { "Route", "osi.options.route", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_rfd_error_class, { "Error Class", "osi.options.rfd.error_class", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_error_class), OSI_OPT_RFD_MASK, NULL, HFILL }},
{ &hf_osi_options_rtd_general, { "Reason for discard {General}", "osi.options.rtd_general", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_general), OSI_OPT_RFD_SUB_MASK, NULL, HFILL }},
{ &hf_osi_options_rtd_address, { "Reason for discard {Address}", "osi.options.rtd_address", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_address), OSI_OPT_RFD_SUB_MASK, NULL, HFILL }},
{ &hf_osi_options_rtd_source_routing, { "Reason for discard {Source Routing}", "osi.options.rtd_source_routing", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_src_route), OSI_OPT_RFD_SUB_MASK, NULL, HFILL }},
{ &hf_osi_options_rtd_lifetime, { "Reason for discard {Lifetime}", "osi.options.rtd_lifetime", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_lifetime), OSI_OPT_RFD_SUB_MASK, NULL, HFILL }},
{ &hf_osi_options_rtd_pdu_discarded, { "Reason for discard {PDU discarded}", "osi.options.rtd_pdu_discarded", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_discarded), OSI_OPT_RFD_SUB_MASK, NULL, HFILL }},
{ &hf_osi_options_rtd_reassembly, { "Reason for discard {Reassembly}", "osi.options.rtd_reassembly", FT_UINT8, BASE_DEC, VALS(osi_opt_rfd_reassembly), OSI_OPT_RFD_SUB_MASK, NULL, HFILL }},
{ &hf_osi_options_rfd_field, { "Field", "osi.options.rfd.field", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_security_type, { "Security type", "osi.options.security_type", FT_UINT8, BASE_DEC, VALS(osi_opt_sec_vals), OSI_OPT_SEC_MASK, NULL, HFILL }},
{ &hf_osi_options_priority, { "Priority", "osi.options.priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_address_mask, { "Address Mask", "osi.options.address_mask", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_snpa_mask, { "SNPA Mask", "osi.options.snpa_mask", FT_SYSTEM_ID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_esct, { "ESCT (seconds)", "osi.options.esct", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_osi_options_padding, { "Padding", "osi.options.padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ott[] = {
&ott_osi_options,
&ott_osi_qos,
&ott_osi_route,
&ott_osi_redirect
};
static ei_register_info ei[] = {
{ &ei_osi_options_none, { "osi.options.none", PI_PROTOCOL, PI_NOTE, "No Options for this PDU", EXPFILL }},
{ &ei_osi_options_rfd_error_class, { "osi.options.rfd.error_class.unknown", PI_PROTOCOL, PI_WARN, "UNKNOWN Error Class", EXPFILL }},
};
expert_module_t *expert_osi_options;
proto_register_field_array(proto_osi, hf, array_length(hf));
proto_register_subtree_array(ott, array_length(ott));
expert_osi_options = expert_register_protocol(proto_osi);
expert_register_field_array(expert_osi_options, ei, array_length(ei));
}
