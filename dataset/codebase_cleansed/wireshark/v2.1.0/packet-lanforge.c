static gboolean dissect_lanforge(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_item *tmp;
proto_tree *lanforge_tree;
guint32 offset = 0;
nstime_t tstamp;
guint32 tss;
guint32 tmpi;
guint32 pld_len, magic;
if(tvb_captured_length(tvb) < 28) {
return FALSE;
}
magic = tvb_get_ntohl(tvb,0);
if(magic != LANFORGE_MAGIC){
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LANforge");
col_add_fstr(pinfo->cinfo, COL_INFO, "Seq: %u", tvb_get_ntohl(tvb, 16));
if(tree) {
ti = proto_tree_add_item(tree, proto_lanforge, tvb, 0, -1, ENC_NA);
lanforge_tree = proto_item_add_subtree(ti, ett_lanforge);
proto_tree_add_item(lanforge_tree, hf_lanforge_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(lanforge_tree, hf_lanforge_magic, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(lanforge_tree, hf_lanforge_src_session, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(lanforge_tree, hf_lanforge_dst_session, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
pld_len = tvb_get_ntohs(tvb, offset);
tmp = proto_tree_add_item(lanforge_tree, hf_lanforge_pld_len_l, tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(tmp);
offset+=2;
tmpi = tvb_get_guint8(tvb, offset);
tmp = proto_tree_add_item(lanforge_tree, hf_lanforge_pld_len_h, tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(tmp);
offset+=1;
pld_len |= (tmpi << 16);
proto_tree_add_uint(lanforge_tree, hf_lanforge_pld_len, tvb, offset-3, 3, pld_len);
proto_tree_add_item(lanforge_tree, hf_lanforge_pld_pattern, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(lanforge_tree, hf_lanforge_seq, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
tss = tvb_get_ntohl(tvb, offset);
tstamp.secs = tss;
tmp = proto_tree_add_item(lanforge_tree, hf_lanforge_tx_time_s, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(tmp);
offset+=4;
tss = tvb_get_ntohl(tvb, offset);
tstamp.nsecs = tss;
tmp = proto_tree_add_item(lanforge_tree, hf_lanforge_tx_time_ns, tvb, offset, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(tmp);
offset+=4;
proto_tree_add_time(lanforge_tree, hf_lanforge_timestamp, tvb, offset - 8, 8, &tstamp);
if(tvb_reported_length_remaining(tvb, offset) > 0)
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo,
lanforge_tree);
}
return TRUE;
}
void proto_register_lanforge(void)
{
static hf_register_info hf[] = {
{ &hf_lanforge_crc,
{
"CRC", "lanforge.CRC",
FT_UINT32, BASE_HEX, NULL, 0x0,
"The LANforge CRC number", HFILL
}
},
{ &hf_lanforge_magic,
{
"Magic number", "lanforge.magic",
FT_UINT32, BASE_HEX, NULL, 0x0,
"The LANforge magic number", HFILL
}
},
{ &hf_lanforge_src_session,
{
"Source session ID", "lanforge.source-session-id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The LANforge source session ID", HFILL
}
},
{ &hf_lanforge_dst_session,
{
"Dest session ID", "lanforge.dest-session-id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The LANforge dest session ID", HFILL
}
},
{ &hf_lanforge_pld_len_l,
{
"Payload Length(L)", "lanforge.pld-len-L",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The LANforge payload length (low bytes)", HFILL
}
},
{ &hf_lanforge_pld_len_h,
{
"Payload Length(H)", "lanforge.pld-len-H",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The LANforge payload length (high byte)", HFILL
}
},
{ &hf_lanforge_pld_len,
{
"Payload Length", "lanforge.pld-length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The LANforge payload length", HFILL
}
},
{ &hf_lanforge_pld_pattern,
{
"Payload Pattern", "lanforge.pld-pattern",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The LANforge payload pattern", HFILL
}
},
{ &hf_lanforge_seq,
{
"Sequence Number", "lanforge.seqno",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The LANforge Sequence Number", HFILL
}
},
{ &hf_lanforge_tx_time_s,
{
"Timestamp Secs", "lanforge.ts-secs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lanforge_tx_time_ns,
{
"Timestamp nsecs", "lanforge.ts-nsecs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lanforge_timestamp,
{
"Timestamp", "lanforge.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_lanforge
};
proto_lanforge = proto_register_protocol("LANforge Traffic Generator", "LANforge", "lanforge");
proto_register_field_array(proto_lanforge, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_lanforge(void)
{
heur_dissector_add("udp", dissect_lanforge, "LANforge over UDP", "lanforge_udp", proto_lanforge, HEURISTIC_ENABLE);
heur_dissector_add("tcp", dissect_lanforge, "LANforge over TCP", "lanforge_tcp", proto_lanforge, HEURISTIC_ENABLE);
}
