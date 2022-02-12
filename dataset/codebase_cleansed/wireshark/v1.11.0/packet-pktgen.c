static gboolean dissect_pktgen(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_item *tmp = NULL;
proto_tree *pktgen_tree = NULL;
guint32 offset = 0;
nstime_t tstamp;
guint32 magic;
if(tvb_length(tvb) < 16) {
return FALSE;
}
magic = tvb_get_ntohl(tvb,0);
if(magic != PKTGEN_MAGIC){
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PKTGEN");
col_add_fstr(pinfo->cinfo, COL_INFO, "Seq: %u", tvb_get_ntohl(tvb, 4));
if(tree) {
ti = proto_tree_add_item(tree, proto_pktgen, tvb, 0, -1, ENC_NA);
pktgen_tree = proto_item_add_subtree(ti, ett_pktgen);
proto_tree_add_item(pktgen_tree, hf_pktgen_magic, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(pktgen_tree, hf_pktgen_seqnum, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
tstamp.secs = tvb_get_ntohl(tvb, offset);
tmp = proto_tree_add_item(pktgen_tree, hf_pktgen_tvsec, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(tmp);
offset+=4;
tstamp.nsecs = tvb_get_ntohl(tvb, offset) * 1000;
tmp = proto_tree_add_item(pktgen_tree, hf_pktgen_tvusec, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(tmp);
offset+=4;
proto_tree_add_time(pktgen_tree, hf_pktgen_timestamp, tvb, offset - 8, 8, &tstamp);
#if 0
if(tvb_length_remaining(tvb, offset))
proto_tree_add_text(pktgen_tree, tvb, offset, -1, "Data (%u bytes)",
tvb_length_remaining(tvb, offset));
#else
if(tvb_length_remaining(tvb, offset))
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo,
pktgen_tree);
#endif
}
return TRUE;
}
void proto_register_pktgen(void)
{
static hf_register_info hf[] = {
{ &hf_pktgen_magic,
{
"Magic number", "pktgen.magic",
FT_UINT32, BASE_HEX, NULL, 0x0,
"The pktgen magic number", HFILL
}
},
{ &hf_pktgen_seqnum,
{
"Sequence number", "pktgen.seqnum",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pktgen_tvsec,
{
"Timestamp tvsec", "pktgen.tvsec",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Timestamp tvsec part", HFILL
}
},
{ &hf_pktgen_tvusec,
{
"Timestamp tvusec", "pktgen.tvusec",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Timestamp tvusec part", HFILL
}
},
{ &hf_pktgen_timestamp,
{
"Timestamp", "pktgen.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_pktgen
};
proto_pktgen = proto_register_protocol("Linux Kernel Packet Generator", "PKTGEN", "pktgen");
proto_register_field_array(proto_pktgen, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_pktgen(void)
{
heur_dissector_add("udp", dissect_pktgen, proto_pktgen);
data_handle = find_dissector("data");
}
