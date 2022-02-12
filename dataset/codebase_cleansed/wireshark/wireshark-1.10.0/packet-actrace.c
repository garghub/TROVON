static int dissect_actrace(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *actrace_tree;
proto_item *ti;
int actrace_protocol;
actrace_tree = NULL;
actrace_protocol = is_actrace(tvb, 0);
if (actrace_protocol != NOT_ACTRACE)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AC_TRACE");
col_clear(pinfo->cinfo, COL_INFO);
if (tree)
{
ti = proto_tree_add_item(tree,proto_actrace,tvb,0,-1, ENC_NA);
actrace_tree = proto_item_add_subtree(ti, ett_actrace);
}
switch (actrace_protocol)
{
case ACTRACE_CAS:
dissect_actrace_cas(tvb, pinfo, actrace_tree);
break;
case ACTRACE_ISDN:
dissect_actrace_isdn(tvb, pinfo, tree, actrace_tree);
break;
}
return tvb_length(tvb);
}
return 0;
}
static void dissect_actrace_cas(tvbuff_t *tvb, packet_info *pinfo, proto_tree *actrace_tree)
{
gint32 value, function, trunk, bchannel, source, event, curr_state, next_state;
gint32 par0, par1, par2;
const gchar *frame_label = NULL;
int direction = 0;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AC_CAS");
value = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_time, tvb, offset, 4, value);
offset += 4;
source = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_source, tvb, offset, 4, source);
offset += 4;
curr_state = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_current_state, tvb, offset, 4, curr_state);
offset += 4;
event = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_event, tvb, offset, 4, event);
offset += 4;
next_state = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_next_state, tvb, offset, 4, next_state);
offset += 4;
function = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_function, tvb, offset, 4, function);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s|%d|%s|%d|%s|",
val_to_str_const(source, actrace_cas_source_vals_short, "ukn"),
curr_state,
val_to_str_ext(event, &actrace_cas_event_vals_ext, "%d"),
next_state,
val_to_str_ext(function, &actrace_cas_function_vals_ext, "%d"));
par0 = tvb_get_ntohl(tvb, offset);
switch (function)
{
case SEND_EVENT:
proto_tree_add_text(actrace_tree, tvb, offset, 4,
"Parameter 0: %s", val_to_str_ext(par0,
&actrace_cas_pstn_event_vals_ext, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s|",
val_to_str_ext(par0, &actrace_cas_pstn_event_vals_ext, "%d"));
break;
case CHANGE_COLLECT_TYPE:
proto_tree_add_text(actrace_tree, tvb, offset, 4,
"Parameter 0: %s", val_to_str(par0,
actrace_cas_collect_type_vals, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s|",
val_to_str(par0, actrace_cas_collect_type_vals, "%d"));
break;
case SEND_MF:
case SEND_DEST_NUM:
proto_tree_add_text(actrace_tree, tvb, offset, 4,
"Parameter 0: %s", val_to_str(par0,
actrace_cas_send_type_vals, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s|",
val_to_str(par0, actrace_cas_send_type_vals, "%d"));
break;
default:
proto_tree_add_int(actrace_tree, hf_actrace_cas_par0, tvb, offset, 4, par0);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d|", par0);
}
offset += 4;
par1 = tvb_get_ntohl(tvb, offset);
if (function == SEND_EVENT) {
proto_tree_add_text(actrace_tree, tvb, offset, 4,
"Parameter 1: %s", val_to_str_ext(par1, &actrace_cas_cause_vals_ext, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s|",
val_to_str_ext(par1, &actrace_cas_cause_vals_ext, "%d"));
} else {
proto_tree_add_int(actrace_tree, hf_actrace_cas_par1, tvb, offset, 4, par1);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d|", par1);
}
offset += 4;
par2 = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_par2, tvb, offset, 4, par2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d|", par2);
offset += 4;
trunk = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_trunk, tvb, offset, 4, trunk);
offset += 4;
bchannel = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_bchannel, tvb, offset, 4, bchannel);
offset += 4;
col_prepend_fstr(pinfo->cinfo, COL_INFO, "t%db%d|", trunk, bchannel);
value = tvb_get_ntohl(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_cas_connection_id, tvb, offset, 4, value);
if (source == ACTRACE_CAS_SOURCE_DSP) {
direction = 1;
if ( (event >= ACTRACE_CAS_EV_11) && (event <= ACTRACE_CAS_EV_00 ) ) {
frame_label = ep_strdup_printf("AB: %s", val_to_str_const(event, actrace_cas_event_ab_vals, "ERROR") );
} else if ( (event >= 32) && (event <= 46 ) ) {
frame_label = ep_strdup_printf("MF: %s", val_to_str_ext_const(event, &actrace_cas_mf_vals_ext, "ERROR") );
} else if ( (event == ACTRACE_CAS_EV_DTMF ) || (event == ACTRACE_CAS_EV_FIRST_DIGIT ) ) {
frame_label = ep_strdup_printf("DTMF: %u", par0 );
}
} else if (source == ACTRACE_CAS_SOURCE_TABLE) {
direction = 0;
if (function == SEND_MF) {
if (par0 == SEND_TYPE_SPECIFIC ) {
frame_label = ep_strdup_printf("MF: %u", par1);
} else if (par0 == SEND_TYPE_ADDRESS ) {
frame_label = ep_strdup("MF: DNIS digit");
} else if (par0 == SEND_TYPE_ANI ) {
frame_label = ep_strdup("MF: ANI digit");
} else if (par0 == SEND_TYPE_SOURCE_CATEGORY ) {
frame_label = ep_strdup("MF: src_category");
} else if (par0 == SEND_TYPE_TRANSFER_CAPABILITY ) {
frame_label = ep_strdup("MF: trf_capability");
} else if (par0 == SEND_TYPE_INTER_EXCHANGE_SWITCH ) {
frame_label = ep_strdup("MF: inter_exch_sw");
}
} else if (function == SEND_CAS) {
frame_label = ep_strdup_printf("AB: %s", val_to_str_const(ACTRACE_CAS_EV_00-par0, actrace_cas_event_ab_vals, "ERROR"));
} else if (function == SEND_DEST_NUM) {
if (par0 == SEND_TYPE_ADDRESS ) {
frame_label = ep_strdup("DTMF/MF: sending DNIS");
} else if (par0 == SEND_TYPE_ANI ) {
frame_label = ep_strdup("DTMF/MF: sending ANI");
}
}
}
if (frame_label != NULL) {
actrace_pi = ep_new(actrace_info_t);
actrace_pi->type = ACTRACE_CAS;
actrace_pi->direction = direction;
actrace_pi->trunk = trunk;
actrace_pi->cas_bchannel = bchannel;
actrace_pi->cas_frame_label = frame_label;
tap_queue_packet(actrace_tap, pinfo, actrace_pi);
}
}
static void dissect_actrace_isdn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *actrace_tree)
{
gint len;
gint32 value, trunk;
tvbuff_t *next_tvb;
int offset = 0;
len = tvb_get_ntohs(tvb, 44);
value = tvb_get_ntohl(tvb, offset+4);
proto_tree_add_int(actrace_tree, hf_actrace_isdn_direction, tvb, offset+4, 4, value);
offset += 8;
trunk = tvb_get_ntohs(tvb, offset);
proto_tree_add_int(actrace_tree, hf_actrace_isdn_trunk, tvb, offset, 2, trunk);
offset = 44;
proto_tree_add_int(actrace_tree, hf_actrace_isdn_length, tvb, offset, 2, len);
if (len > 4) {
actrace_pi = ep_new(actrace_info_t);
actrace_pi->type = ACTRACE_ISDN;
actrace_pi->direction = (value==PSTN_TO_BLADE?1:0);
actrace_pi->trunk = trunk;
tap_queue_packet(actrace_tap, pinfo, actrace_pi);
}
offset += 2 ;
next_tvb = tvb_new_subset(tvb, offset, len, len);
call_dissector(lapd_handle, next_tvb, pinfo, tree);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AC_ISDN");
col_prepend_fstr(pinfo->cinfo, COL_INFO, "Trunk:%d Blade %s PSTN "
, trunk, value==PSTN_TO_BLADE?"<--":"-->");
}
static int is_actrace(tvbuff_t *tvb, gint offset)
{
gint tvb_len;
gint32 source, isdn_header;
tvb_len = tvb_reported_length(tvb);
source = tvb_get_ntohl(tvb, offset+4);
if ( (tvb_len == 48) && ((source > -1) && (source <3)) )
return ACTRACE_CAS;
isdn_header = tvb_get_ntohl(tvb, offset+4);
if ( (tvb_len >= 50) && ( (isdn_header == PSTN_TO_BLADE) || (isdn_header == BLADE_TO_PSTN)) )
return ACTRACE_ISDN;
return NOT_ACTRACE;
}
void proto_register_actrace(void)
{
static hf_register_info hf[] =
{
{ &hf_actrace_cas_time,
{ "Time", "actrace.cas.time", FT_INT32, BASE_DEC, NULL, 0x0,
"Capture Time", HFILL }},
{ &hf_actrace_cas_source,
{ "Source", "actrace.cas.source", FT_INT32, BASE_DEC, VALS(actrace_cas_source_vals), 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_current_state,
{ "Current State", "actrace.cas.curr_state", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_event,
{ "Event", "actrace.cas.event", FT_INT32, BASE_DEC|BASE_EXT_STRING, &actrace_cas_event_vals_ext, 0x0,
"New Event", HFILL }},
{ &hf_actrace_cas_next_state,
{ "Next State", "actrace.cas.next_state", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_function,
{ "Function", "actrace.cas.function", FT_INT32, BASE_DEC|BASE_EXT_STRING, &actrace_cas_function_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_par0,
{ "Parameter 0", "actrace.cas.par0", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_par1,
{ "Parameter 1", "actrace.cas.par1", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_par2,
{ "Parameter 2", "actrace.cas.par2", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_trunk,
{ "Trunk Number", "actrace.cas.trunk", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_bchannel,
{ "BChannel", "actrace.cas.bchannel", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_cas_connection_id,
{ "Connection ID", "actrace.cas.conn_id", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_isdn_trunk,
{ "Trunk Number", "actrace.isdn.trunk", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_actrace_isdn_direction,
{ "Direction", "actrace.isdn.dir", FT_INT32, BASE_DEC, VALS(actrace_isdn_direction_vals), 0x0,
NULL, HFILL }},
{ &hf_actrace_isdn_length,
{ "Length", "actrace.isdn.length", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] =
{
&ett_actrace,
};
module_t *actrace_module;
proto_actrace = proto_register_protocol("AudioCodes Trunk Trace", "ACtrace", "actrace");
proto_register_field_array(proto_actrace, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
actrace_module = prefs_register_protocol(proto_actrace, proto_reg_handoff_actrace);
prefs_register_uint_preference(actrace_module, "udp_port",
"AudioCodes Trunk Trace UDP port",
"Set the UDP port for AudioCodes Trunk Traces."
"Use http://x.x.x.x/TrunkTraces to enable the traces in the Blade",
10, &global_actrace_udp_port);
prefs_register_obsolete_preference(actrace_module, "display_dissect_tree");
actrace_tap = register_tap("actrace");
}
void proto_reg_handoff_actrace(void)
{
static gboolean actrace_prefs_initialized = FALSE;
static dissector_handle_t actrace_handle;
static guint actrace_udp_port;
if (!actrace_prefs_initialized)
{
actrace_handle = new_create_dissector_handle(dissect_actrace, proto_actrace);
lapd_handle = find_dissector("lapd");
actrace_prefs_initialized = TRUE;
}
else
{
dissector_delete_uint("udp.port", actrace_udp_port, actrace_handle);
}
actrace_udp_port = global_actrace_udp_port;
dissector_add_uint("udp.port", global_actrace_udp_port, actrace_handle);
}
