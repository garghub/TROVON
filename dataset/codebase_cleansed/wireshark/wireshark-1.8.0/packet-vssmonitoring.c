static int
dissect_vssmonitoring(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ti = NULL;
proto_tree *vssmonitoring_tree = NULL;
guint offset = 0;
guint trailer_len;
nstime_t vssmonitoring_time;
guint8 vssmonitoring_clksrc = 0;
guint16 vssmonitoring_srcport = 0;
struct tm *tmp;
trailer_len = tvb_reported_length(tvb);
if ( trailer_len > 14 )
return 0;
if ( (trailer_len & 3) == 3 )
return 0;
if ( (trailer_len & 3) == 0 && trailer_len < 8 )
return 0;
if ( trailer_len >= 8 ) {
vssmonitoring_time.secs = tvb_get_ntohl(tvb, offset);
vssmonitoring_time.nsecs = tvb_get_ntohl(tvb, offset + 4);
vssmonitoring_clksrc = (guint8)(((guint32)vssmonitoring_time.nsecs) >> CLKSRC_SHIFT);
vssmonitoring_time.nsecs &= VSS_NS_MASK;
if ( vssmonitoring_use_heuristics ) {
if (vssmonitoring_time.secs > 3600) {
if ( vssmonitoring_time.secs > pinfo->fd->abs_ts.secs ) {
if ( vssmonitoring_time.secs - pinfo->fd->abs_ts.secs > 2592000 )
return 0;
} else {
if ( pinfo->fd->abs_ts.secs - vssmonitoring_time.secs > 2592000 )
return 0;
}
}
if ( vssmonitoring_time.nsecs >= 1000000000 )
return 0;
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_vssmonitoring,
tvb, 0, (trailer_len & 0xb), ENC_NA);
vssmonitoring_tree = proto_item_add_subtree(ti, ett_vssmonitoring);
}
if ( trailer_len >= 8 ) {
if (tree) {
proto_tree_add_time(vssmonitoring_tree, hf_vssmonitoring_time, tvb, offset, 8, &vssmonitoring_time);
proto_tree_add_uint(vssmonitoring_tree, hf_vssmonitoring_clksrc, tvb, offset + 4, 1, vssmonitoring_clksrc);
tmp = localtime(&vssmonitoring_time.secs);
proto_item_append_text(ti, ", Timestamp: %02d:%02d:%02d.%09ld",
tmp->tm_hour, tmp->tm_min, tmp->tm_sec,(long)vssmonitoring_time.nsecs);
}
offset += 8;
}
if ( trailer_len & 3) {
if ( trailer_len & 1) {
vssmonitoring_srcport = (guint16)tvb_get_guint8(tvb, offset);
if (tree)
proto_tree_add_item(vssmonitoring_tree, hf_vssmonitoring_srcport, tvb, offset, 1, ENC_NA);
offset++;
} else if ( trailer_len & 2) {
vssmonitoring_srcport = tvb_get_ntohs(tvb, offset);
if (tree)
proto_tree_add_item(vssmonitoring_tree, hf_vssmonitoring_srcport, tvb, offset, 2, ENC_NA);
offset += 2;
}
if (tree)
proto_item_append_text(ti, ", Source Port: %d", vssmonitoring_srcport);
}
return offset;
}
void
proto_register_vssmonitoring(void)
{
static hf_register_info hf[] = {
{ &hf_vssmonitoring_time, {
"Time Stamp", "vssmonitoring.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"VSS-Monitoring Time Stamp", HFILL }},
{ &hf_vssmonitoring_clksrc, {
"Clock Source", "vssmonitoring.clksrc",
FT_UINT8, BASE_DEC, VALS(clksrc_vals), 0x0,
"VSS-Monitoring Clock Source", HFILL }},
{ &hf_vssmonitoring_srcport, {
"Src Port", "vssmonitoring.srcport",
FT_UINT8, BASE_DEC, NULL, 0x0,
"VSS-Monitoring Source Port", HFILL }}
};
static gint *ett[] = {
&ett_vssmonitoring
};
module_t *vssmonitoring_module;
proto_vssmonitoring = proto_register_protocol("VSS-Monitoring ethernet trailer", "VSS-Monitoring", "vssmonitoring");
proto_register_field_array(proto_vssmonitoring, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
vssmonitoring_module = prefs_register_protocol(proto_vssmonitoring, NULL);
prefs_register_bool_preference(vssmonitoring_module, "use_heuristics",
"Use heuristics to verify if trailer contains VSS-Monitoring data",
"When enabled, Wireshark will do a check on the trailer data to verify"
"whether it contains VSS-Monitoring time- and port-stamps.",
&vssmonitoring_use_heuristics);
}
void
proto_reg_handoff_vssmonitoring(void)
{
heur_dissector_add("eth.trailer", dissect_vssmonitoring, proto_vssmonitoring);
}
