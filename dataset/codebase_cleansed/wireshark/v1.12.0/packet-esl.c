static guint16 flags_to_port(guint16 flagsValue) {
if ( (flagsValue & esl_port0_bitmask) != 0 )
return 0;
else if ( (flagsValue & esl_port1_bitmask) != 0 )
return 1;
else if ( (flagsValue & esl_port2_bitmask) != 0 )
return 2;
else if ( (flagsValue & esl_port3_bitmask) != 0 )
return 3;
else if ( (flagsValue & esl_port4_bitmask) != 0 )
return 4;
else if ( (flagsValue & esl_port5_bitmask) != 0 )
return 5;
else if ( (flagsValue & esl_port6_bitmask) != 0 )
return 6;
else if ( (flagsValue & esl_port7_bitmask) != 0 )
return 7;
else if ( (flagsValue & esl_port8_bitmask) != 0 )
return 8;
else if ( (flagsValue & esl_port9_bitmask) != 0 )
return 9;
else if ( (flagsValue & esl_port10_bitmask) != 0 )
return 10;
else if ( (flagsValue & esl_port11_bitmask) != 0 )
return 11;
return -1;
}
static void
dissect_esl_header(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree) {
proto_item *ti = NULL;
proto_tree *esl_header_tree;
gint offset = 0;
guint esl_length = tvb_reported_length(tvb);
if ( esl_length >= SIZEOF_ESLHEADER )
{
if (tree)
{
guint16 flags;
ti = proto_tree_add_item(tree, proto_esl, tvb, 0, SIZEOF_ESLHEADER, ENC_NA);
esl_header_tree = proto_item_add_subtree(ti, ett_esl);
offset+=6;
flags = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(esl_header_tree, hf_esl_port, tvb, offset, 2, flags_to_port(flags));
proto_tree_add_item(esl_header_tree, hf_esl_crcerror, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(esl_header_tree, hf_esl_alignerror, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(esl_header_tree, hf_esl_timestamp, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
}
}
static gboolean is_esl_header(tvbuff_t *tvb, gint offset)
{
return tvb_get_guint8(tvb, offset) == 0x01 &&
tvb_get_guint8(tvb, offset+1) == 0x01 &&
tvb_get_guint8(tvb, offset+2) == 0x05 &&
(tvb_get_guint8(tvb, offset+3) == 0x10 ||tvb_get_guint8(tvb, offset+3) == 0x11)&&
tvb_get_guint8(tvb, offset+4) == 0x00 &&
tvb_get_guint8(tvb, offset+5) == 0x00;
}
static void modify_times(tvbuff_t *tvb, gint offset, packet_info *pinfo)
{
if ( ref_time_frame.fd == NULL )
{
ref_time_frame.esl_ts = tvb_get_letoh64(tvb, offset+8);
ref_time_frame.fd = pinfo->fd;
ref_time_frame.num = pinfo->fd->num;
ref_time_frame.abs_ts = pinfo->fd->abs_ts;
}
else if ( !pinfo->fd->flags.visited )
{
guint64 nsecs = tvb_get_letoh64(tvb, offset+8) - ref_time_frame.esl_ts;
guint64 secs = nsecs/1000000000;
nstime_t ts;
nstime_t ts_delta;
ts.nsecs = ref_time_frame.abs_ts.nsecs + (int)(nsecs-(secs*1000000000));
if ( ts.nsecs > 1000000000 )
{
ts.nsecs-=1000000000;
secs++;
}
ts.secs = ref_time_frame.abs_ts.secs+(int)secs;
nstime_delta(&ts_delta, &ts, &pinfo->fd->abs_ts);
pinfo->fd->abs_ts = ts;
nstime_add(&pinfo->rel_ts, &ts_delta);
}
}
static gboolean
dissect_esl_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
static gboolean in_heur = FALSE;
gboolean result;
tvbuff_t *next_tvb;
guint esl_length = tvb_length(tvb);
if ( in_heur )
return FALSE;
in_heur = TRUE;
{
if ( ref_time_frame.fd != NULL && !pinfo->fd->flags.visited && pinfo->fd->num <= ref_time_frame.num )
ref_time_frame.fd = NULL;
if ( tvb_length(tvb) < SIZEOF_ESLHEADER )
return FALSE;
if ( is_esl_header(tvb, 0) )
{
dissect_esl_header(tvb, pinfo, tree);
if ( eth_withoutfcs_handle != NULL )
{
next_tvb = tvb_new_subset_remaining(tvb, SIZEOF_ESLHEADER);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
}
modify_times(tvb, 0, pinfo);
result = TRUE;
}
else if ( is_esl_header(tvb, esl_length-SIZEOF_ESLHEADER) )
{
if ( eth_withoutfcs_handle != NULL )
{
next_tvb = tvb_new_subset(tvb, 0, esl_length-SIZEOF_ESLHEADER, esl_length-SIZEOF_ESLHEADER);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
}
next_tvb = tvb_new_subset(tvb, esl_length-SIZEOF_ESLHEADER, SIZEOF_ESLHEADER, SIZEOF_ESLHEADER);
dissect_esl_header(next_tvb, pinfo, tree);
modify_times(tvb, esl_length-SIZEOF_ESLHEADER, pinfo);
result = TRUE;
}
else
{
result = FALSE;
}
}
in_heur = FALSE;
return result;
}
void
proto_register_esl(void) {
static hf_register_info hf[] = {
{ &hf_esl_port,
{ "Port", "esl.port",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_esl_crcerror,
{ "Crc Error", "esl.crcerror",
FT_BOOLEAN, 16, TFS(&flags_yes_no), esl_crcError_bitmask,
NULL, HFILL }
},
{ &hf_esl_alignerror,
{ "Alignment Error", "esl.alignerror",
FT_BOOLEAN, 16, TFS(&flags_yes_no), esl_alignError_bitmask,
NULL, HFILL }
},
{ &hf_esl_timestamp,
{ "timestamp", "esl.timestamp",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_esl,
};
module_t *esl_module;
proto_esl = proto_register_protocol("EtherCAT Switch Link",
"ESL","esl");
esl_module = prefs_register_protocol(proto_esl, proto_reg_handoff_esl);
prefs_register_bool_preference(esl_module, "enable", "Enable dissector",
"Enable this dissector (default is false)",
&esl_enable_dissector);
proto_register_field_array(proto_esl,hf,array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
register_dissector("esl", dissect_esl_header, proto_esl);
}
void
proto_reg_handoff_esl(void) {
static gboolean initialized = FALSE;
if (!initialized) {
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
heur_dissector_add("eth", dissect_esl_heur, proto_esl);
initialized = TRUE;
}
proto_set_decoding(proto_esl, esl_enable_dissector);
}
