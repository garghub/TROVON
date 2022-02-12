static int dissect_tdmop(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 dchannel_data[MAX_DCHANNEL_LEN];
guint dchannel_len;
guint8 flags;
gint offset;
proto_item *ti;
proto_tree *tdmop_tree;
guint32 dstch;
guint32 srcch;
flags = tvb_get_guint8(tvb, 4);
offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TDMoP");
col_clear(pinfo->cinfo, COL_INFO);
if (flags & TDMOP_FLAG_LOST_REQUEST)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Lost Request");
}
dstch = tvb_get_guint8(tvb, offset + 2);
srcch = tvb_get_guint8(tvb, offset + 3);
pinfo->destport = dstch;
pinfo->srcport = srcch;
pinfo->ptype = PT_TDMOP;
ti = proto_tree_add_item(tree, proto_tdmop, tvb, 0, -1, ENC_NA);
tdmop_tree = proto_item_add_subtree(ti, ett_tdmop);
proto_tree_add_item(tdmop_tree, hf_tdmop_TransferID, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tdmop_tree, hf_tdmop_DstCh, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tdmop_tree, hf_tdmop_SrcCh, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tdmop_tree, hf_tdmop_Flags, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tdmop_tree, hf_tdmop_Flags_no_data, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tdmop_tree, hf_tdmop_Flags_lost_request, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tdmop_tree, hf_tdmop_Flags_remote_no_data, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tdmop_tree, hf_tdmop_Flags_compressed, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tdmop_tree, hd_tdmop_SrcDst, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tdmop_tree, hd_tdmop_SeqNum, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tdmop_tree, hd_tdmop_LastRecv, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tdmop_tree, hd_tdmop_Delay, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tdmop_tree, hd_tdmop_Reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if ((flags & TDMOP_FLAG_NO_DATA)==0)
{
gint len;
gint blockid;
dchannel_len=0;
len=tvb_captured_length_remaining(tvb, 0);
proto_tree_add_item(tdmop_tree, hf_tdmop_payload, tvb, offset, -1, ENC_NA);
blockid=0;
while (offset<len)
{
proto_tree *currentblock = proto_tree_add_subtree_format(tdmop_tree, tvb, 0, 0, ett_tdmop_channel, 0, "Block %d", blockid);
guint32 mask;
gint i;
gint j;
blockid++;
mask = pref_tdmop_mask;
if (flags&TDMOP_FLAG_COMPRESSED)
{
mask = tvb_get_letohl(tvb,offset);
mask = ((mask >> 16) & 0xFFFF)|((mask & 0xFFFF) << 16);
proto_tree_add_uint_format_value(currentblock, hf_tdmop_Compression_mask, tvb, offset, 4, mask, "%08X", mask);
offset+=4;
}
for (i=0; i<32; i++)
{
if (mask & (1UL<<i))
{
proto_tree *subtree;
tvbuff_t *cdata;
subtree = proto_tree_add_subtree_format(currentblock, tvb, 0, 0, ett_tdmop_channel, 0, "Channel %d", i);
cdata = tvb_new_subset_length(tvb, offset, 4);
if (i==pref_tdmop_d_channel)
{
if (dchannel_len + 4 < MAX_DCHANNEL_LEN)
{
for (j = 0; j < 4; j++)
{
dchannel_data[dchannel_len+j]=reverse_map[tvb_get_guint8(cdata, j)];
}
dchannel_len += 4;
}
} else
{
call_data_dissector(cdata, pinfo, subtree);
}
offset += 4;
}
}
}
if (dchannel_len>0)
{
guint8 *buff = (guint8 *)g_memdup(dchannel_data, dchannel_len);
tvbuff_t *new_tvb;
new_tvb = tvb_new_child_real_data(tvb, buff, dchannel_len, dchannel_len);
tvb_set_free_cb(new_tvb, g_free);
call_dissector(lapd_handle, new_tvb, pinfo, tree);
}
}
return tvb_captured_length(tvb);
}
void proto_register_tdmop(void)
{
module_t *tdmop_module;
static hf_register_info hf[] =
{
{
&hf_tdmop_TransferID,
{ "TDMoP Transfer ID", "tdmop.transferid",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
},
{
&hf_tdmop_DstCh,
{ "TDMoP Dst Ch", "tdmop.dstch",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hf_tdmop_SrcCh,
{ "TDMoP Src Ch", "tdmop.srcch",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hf_tdmop_Flags,
{ "TDMoP Flags", "tdmop.flags",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hf_tdmop_Flags_lost_request,
{ "TDMoP Lost Request Flag", "tdmop.flags.lostrequest",
FT_BOOLEAN, 8,
NULL, TDMOP_FLAG_LOST_REQUEST,
NULL, HFILL}
},
{
&hf_tdmop_Flags_no_data,
{ "TDMoP No data flag", "tdmop.flags.nodata",
FT_BOOLEAN, 8,
NULL, TDMOP_FLAG_NO_DATA,
NULL, HFILL}
},
{
&hf_tdmop_Flags_remote_no_data,
{ "TDMoP No data received from remote side flag", "tdmop.flags.remotenodata",
FT_BOOLEAN, 8,
NULL, TDMOP_FLAG_REMOTE_NO_DATA,
NULL, HFILL}
},
{
&hf_tdmop_Flags_compressed,
{ "TDMoP compressed framed", "tdmop.flags.compressed",
FT_BOOLEAN, 8,
NULL, TDMOP_FLAG_COMPRESSED,
NULL, HFILL}
},
{
&hd_tdmop_SrcDst,
{ "TDMoP Short SrcDst", "tdmop.srcdst",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
},
{
&hd_tdmop_SeqNum,
{ "TDMoP Sequence number", "tdmop.seqnum",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hd_tdmop_LastRecv,
{ "TDMoP Last Received number", "tdmop.recvnumber",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hd_tdmop_Delay,
{ "TDMoP Delay", "tdmop.delay",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hd_tdmop_Reserved,
{ "TDMoP Reserved", "tdmop.reserved",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL}
},
{
&hf_tdmop_payload,
{ "TDMoP Payload", "tdmop.payload",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL}
},
{
&hf_tdmop_Compression_mask,
{ "TDMoP Compression mask", "tdmop.cmask",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
}
};
static gint *ett[] = {
&ett_tdmop,
&ett_tdmop_channel
};
proto_tdmop = proto_register_protocol (
"TDMoP protocol",
"TDMoP",
"tdmop"
);
proto_register_field_array(proto_tdmop, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tdmop_module = prefs_register_protocol(proto_tdmop, proto_reg_handoff_tdmop);
prefs_register_uint_preference(tdmop_module, "d_channel",
"TDMoP D-Channel",
"The TDMoD channel that contains the D-Channel.",
10, &pref_tdmop_d_channel);
prefs_register_uint_preference(tdmop_module, "ts_mask",
"TDMoP default timeslot mask",
"The bitmask of channels in uncompressed TDMoP frame",
16, &pref_tdmop_mask);
prefs_register_uint_preference(tdmop_module, "ethertype",
"Ethertype for TDMoP stream(Usually 0808)",
"The ethertype assigned to TDMoP (without IP/UDP) stream",
16, &pref_tdmop_ethertype);
prefs_register_uint_preference(tdmop_module, "udpport",
"UDP Port of TDMoP stream(Usually 41000)",
"The udp port assigned to TDMoP stream",
10, &pref_tdmop_udpport);
}
void proto_reg_handoff_tdmop(void)
{
static dissector_handle_t tdmop_handle;
static gboolean init = FALSE;
static guint32 current_tdmop_ethertype;
static guint32 current_tdmop_udpport;
if (!init)
{
tdmop_handle = create_dissector_handle(dissect_tdmop, proto_tdmop);
if (pref_tdmop_udpport) {
dissector_add_uint("udp.port", pref_tdmop_udpport, tdmop_handle);
}
if (pref_tdmop_ethertype) {
dissector_add_uint("ethertype", pref_tdmop_ethertype, tdmop_handle);
}
lapd_handle = find_dissector_add_dependency("lapd-bitstream", proto_tdmop);
current_tdmop_ethertype = pref_tdmop_ethertype;
current_tdmop_udpport = pref_tdmop_udpport;
init = TRUE;
}
if (current_tdmop_ethertype != pref_tdmop_ethertype)
{
dissector_delete_uint("ethertype", current_tdmop_ethertype, tdmop_handle);
if (pref_tdmop_ethertype) {
dissector_add_uint("ethertype", pref_tdmop_ethertype, tdmop_handle);
}
current_tdmop_ethertype = pref_tdmop_ethertype;
}
if (current_tdmop_udpport != pref_tdmop_udpport)
{
dissector_delete_uint("udp.port", current_tdmop_udpport, tdmop_handle);
if (pref_tdmop_udpport) {
dissector_add_uint("udp.port", pref_tdmop_udpport, tdmop_handle);
}
current_tdmop_udpport = pref_tdmop_udpport;
}
}
