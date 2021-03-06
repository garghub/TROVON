static void
dcp_init_protocol(void)
{
fragment_table_init (&dcp_fragment_table);
reassembled_table_init (&dcp_reassembled_table);
}
static gboolean
dissect_dcp_etsi (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint8 *sync;
proto_tree *dcp_tree = NULL;
if(tvb_length(tvb) < 11)
return FALSE;
sync = tvb_get_ephemeral_string (tvb, 0, 2);
if((sync[0]!='A' && sync[0]!='P') || sync[1]!='F')
return FALSE;
pinfo->current_proto = "DCP (ETSI)";
col_clear(pinfo->cinfo, COL_INFO);
col_set_str (pinfo->cinfo, COL_PROTOCOL, "DCP (ETSI)");
if(tree) {
proto_item *ti = NULL;
ti = proto_tree_add_item (tree, proto_dcp_etsi, tvb, 0, -1, ENC_NA);
dcp_tree = proto_item_add_subtree (ti, ett_edcp);
}
dissector_try_string(dcp_dissector_table, (char*)sync, tvb, pinfo, dcp_tree);
return TRUE;
}
static
void rs_deinterleave(const guint8 *input, guint8 *output, guint16 plen, guint32 fcount)
{
guint fidx;
for(fidx=0; fidx<fcount; fidx++)
{
int r;
for (r=0; r<plen; r++)
{
output[fidx+r*fcount] = input[fidx*plen+r];
}
}
}
static
gboolean rs_correct_data(guint8 *deinterleaved, guint8 *output,
guint32 c_max, guint16 rsk, guint16 rsz _U_)
{
guint32 i, index_coded = 0, index_out = 0;
int err_corr;
for (i=0; i<c_max; i++)
{
memcpy(output+index_out, deinterleaved+index_coded, rsk);
index_coded += rsk;
memcpy(output+index_out+PFT_RS_N_MAX, deinterleaved+index_coded, PFT_RS_P);
index_coded += PFT_RS_P;
err_corr = eras_dec_rs(output+index_out, NULL, 0);
if (err_corr<0) {
return FALSE;
}
index_out += rsk;
}
return TRUE;
}
static tvbuff_t *
dissect_pft_fec_detailed(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
guint32 findex _U_,
guint32 fcount,
guint16 seq,
gint offset,
guint16 plen,
gboolean fec _U_,
guint16 rsk,
guint16 rsz,
fragment_data *fdx
)
{
guint16 decoded_size;
guint32 c_max;
guint32 rx_min;
tvbuff_t *new_tvb=NULL;
if (fcount > MAX_FRAGMENTS) {
if (tree)
proto_tree_add_text(tree, tvb , 0, -1, "[Reassembly of %d fragments not attempted]", fcount);
return NULL;
}
decoded_size = fcount*plen;
c_max = fcount*plen/(rsk+PFT_RS_P);
rx_min = c_max*rsk/plen;
if(rx_min*plen<c_max*rsk)
rx_min++;
if (fdx)
new_tvb = process_reassembled_data (tvb, offset, pinfo,
"Reassembled DCP (ETSI)",
fdx, &dcp_frag_items,
NULL, tree);
else {
guint fragments=0;
guint32 *got;
fragment_data *fd;
fragment_data *fd_head;
if(tree)
proto_tree_add_text (tree, tvb, 0, -1, "want %d, got %d need %d",
fcount, fragments, rx_min
);
got = ep_alloc(fcount*sizeof(guint32));
fd = fragment_get(pinfo, seq, dcp_fragment_table);
for (fd_head = fd; fd_head != NULL; fd_head = fd_head->next) {
if(fd_head->data) {
got[fragments++] = fd_head->offset;
}
}
got[fragments++] = fcount;
if(fragments>=rx_min) {
guint i,current_findex;
fragment_data *frag=NULL;
guint8 *dummy_data = (guint8*) ep_alloc0 (plen);
tvbuff_t *dummytvb = tvb_new_real_data(dummy_data, plen, plen);
if(tree)
proto_tree_add_text (tree, tvb, 0, -1, "want %d, got %d need %d",
fcount, fragments, rx_min
);
current_findex = 0;
for(i=0; i<fragments; i++) {
guint next_fragment_we_have = got[i];
if (next_fragment_we_have > MAX_FRAGMENTS) {
if (tree)
proto_tree_add_text(tree, tvb , 0, -1, "[Reassembly of %d fragments not attempted]", next_fragment_we_have);
return NULL;
}
for(; current_findex<next_fragment_we_have; current_findex++) {
frag = fragment_add_seq_check (dummytvb, 0, pinfo, seq,
dcp_fragment_table, dcp_reassembled_table,
current_findex, plen, (current_findex+1!=fcount));
}
current_findex++;
}
tvb_free(dummytvb);
if(frag)
new_tvb = process_reassembled_data (tvb, offset, pinfo,
"Reassembled DCP (ETSI)",
frag, &dcp_frag_items,
NULL, tree);
}
}
if(new_tvb) {
gboolean decoded = TRUE;
tvbuff_t *dtvb = NULL;
const guint8 *input = tvb_get_ptr(new_tvb, 0, -1);
guint16 reassembled_size = tvb_length(new_tvb);
guint8 *deinterleaved = (guint8*) g_malloc (reassembled_size);
guint8 *output = (guint8*) g_malloc (decoded_size);
rs_deinterleave(input, deinterleaved, plen, fcount);
dtvb = tvb_new_child_real_data(tvb, deinterleaved, reassembled_size, reassembled_size);
add_new_data_source(pinfo, dtvb, "Deinterleaved");
tvb_set_free_cb(dtvb, g_free);
decoded = rs_correct_data(deinterleaved, output, c_max, rsk, rsz);
if(tree)
proto_tree_add_boolean (tree, hf_edcp_rs_ok, tvb, offset, 2, decoded);
new_tvb = tvb_new_child_real_data(dtvb, output, decoded_size, decoded_size);
add_new_data_source(pinfo, new_tvb, "RS Error Corrected Data");
tvb_set_free_cb(new_tvb, g_free);
}
return new_tvb;
}
static tvbuff_t *
dissect_pft_fragmented(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree,
guint32 findex,
guint32 fcount,
guint16 seq,
gint offset,
guint16 plen,
gboolean fec,
guint16 rsk,
guint16 rsz
)
{
gboolean first, last;
tvbuff_t *new_tvb=NULL;
fragment_data *frag_edcp = NULL;
pinfo->fragmented = TRUE;
first = findex == 0;
last = fcount == (findex+1);
frag_edcp = fragment_add_seq_check (
tvb, offset, pinfo,
seq,
dcp_fragment_table, dcp_reassembled_table,
findex,
plen,
!last);
if(fec) {
new_tvb = dissect_pft_fec_detailed(
tvb, pinfo, tree, findex, fcount, seq, offset, plen, fec, rsk, rsz, frag_edcp
);
} else {
new_tvb = process_reassembled_data (tvb, offset, pinfo,
"Reassembled DCP (ETSI)",
frag_edcp, &dcp_frag_items,
NULL, tree);
}
if(new_tvb) {
col_append_str (pinfo->cinfo, COL_INFO, " (Message Reassembled)");
} else {
if(last) {
col_append_str (pinfo->cinfo, COL_INFO, " (Message Reassembly failure)");
} else {
col_append_fstr (pinfo->cinfo, COL_INFO, " (Message fragment %u)", findex);
}
}
if(first)
col_append_str (pinfo->cinfo, COL_INFO, " (first)");
if(last)
col_append_str (pinfo->cinfo, COL_INFO, " (last)");
return new_tvb;
}
static void
dissect_pft(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint16 plen;
gint offset = 0;
guint16 seq, payload_len;
guint32 findex, fcount;
proto_tree *pft_tree = NULL;
proto_item *ti = NULL, *li = NULL;
tvbuff_t *next_tvb = NULL;
gboolean fec = FALSE;
guint16 rsk=0, rsz=0;
pinfo->current_proto = "DCP-PFT";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCP-PFT");
if (tree) {
ti = proto_tree_add_item (tree, proto_pft, tvb, 0, -1, ENC_NA);
pft_tree = proto_item_add_subtree (ti, ett_pft);
proto_tree_add_item (pft_tree, hf_edcp_sync, tvb, offset, 2, ENC_ASCII|ENC_NA);
}
offset += 2;
seq = tvb_get_ntohs (tvb, offset);
if (tree) {
proto_tree_add_item (pft_tree, hf_edcp_pseq, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
findex = tvb_get_ntoh24 (tvb, offset);
if (tree) {
proto_tree_add_item (pft_tree, hf_edcp_findex, tvb, offset, 3, ENC_BIG_ENDIAN);
}
offset += 3;
fcount = tvb_get_ntoh24 (tvb, offset);
if (tree) {
proto_tree_add_item (pft_tree, hf_edcp_fcount, tvb, offset, 3, ENC_BIG_ENDIAN);
}
offset += 3;
plen = tvb_get_ntohs (tvb, offset);
payload_len = plen & 0x3fff;
if (tree) {
proto_tree_add_item (pft_tree, hf_edcp_fecflag, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (pft_tree, hf_edcp_addrflag, tvb, offset, 2, ENC_BIG_ENDIAN);
li = proto_tree_add_item (pft_tree, hf_edcp_plen, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (plen & 0x8000) {
fec = TRUE;
rsk = tvb_get_guint8 (tvb, offset);
if (tree)
proto_tree_add_item (pft_tree, hf_edcp_rsk, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
rsz = tvb_get_guint8 (tvb, offset);
if (tree)
proto_tree_add_item (pft_tree, hf_edcp_rsz, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (plen & 0x4000) {
if (tree)
proto_tree_add_item (pft_tree, hf_edcp_source, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tree)
proto_tree_add_item (pft_tree, hf_edcp_dest, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (tree) {
proto_item *ci = NULL;
guint header_len = offset+2;
const char *crc_buf = (const char *) tvb_get_ptr(tvb, 0, header_len);
unsigned long c = crc_drm(crc_buf, header_len, 16, 0x11021, 1);
ci = proto_tree_add_item (pft_tree, hf_edcp_hcrc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ci, " (%s)", (c==0xe2f0)?"Ok":"bad");
proto_tree_add_boolean(pft_tree, hf_edcp_hcrc_ok, tvb, offset, 2, c==0xe2f0);
}
offset += 2;
if (fcount > 1) {
gboolean save_fragmented = pinfo->fragmented;
guint16 real_len = tvb_length(tvb)-offset;
proto_tree_add_item (pft_tree, hf_edcp_pft_payload, tvb, offset, real_len, ENC_NA);
if(real_len != payload_len) {
if(li)
proto_item_append_text(li, " (length error (%d))", real_len);
}
next_tvb = dissect_pft_fragmented(tvb, pinfo, pft_tree,
findex, fcount, seq, offset, real_len,
fec, rsk, rsz
);
pinfo->fragmented = save_fragmented;
} else {
next_tvb = tvb_new_subset_remaining (tvb, offset);
}
if(next_tvb) {
dissect_af(next_tvb, pinfo, tree);
}
}
static void
dissect_af (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
gint offset = 0;
proto_item *ti = NULL;
proto_item *li = NULL;
proto_item *ci = NULL;
proto_tree *af_tree = NULL;
guint8 ver, pt;
guint32 payload_len;
tvbuff_t *next_tvb = NULL;
pinfo->current_proto = "DCP-AF";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCP-AF");
if (tree) {
ti = proto_tree_add_item (tree, proto_af, tvb, 0, -1, ENC_NA);
af_tree = proto_item_add_subtree (ti, ett_af);
proto_tree_add_item (af_tree, hf_edcp_sync, tvb, offset, 2, ENC_ASCII|ENC_NA);
}
offset += 2;
payload_len = tvb_get_ntohl(tvb, offset);
if (tree) {
guint32 real_payload_len = tvb_length(tvb)-12;
li = proto_tree_add_item (af_tree, hf_edcp_len, tvb, offset, 4, ENC_BIG_ENDIAN);
if(real_payload_len < payload_len) {
proto_item_append_text (li, " (wrong len claims %d is %d)",
payload_len, real_payload_len
);
} else if(real_payload_len > payload_len) {
proto_item_append_text (li, " (%d bytes in packet after end of AF frame)",
real_payload_len-payload_len
);
}
}
offset += 4;
if (tree)
proto_tree_add_item (af_tree, hf_edcp_seq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ver = tvb_get_guint8 (tvb, offset);
if (tree) {
proto_tree_add_item (af_tree, hf_edcp_crcflag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (af_tree, hf_edcp_maj, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (af_tree, hf_edcp_min, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
pt = tvb_get_guint8 (tvb, offset);
if (tree)
proto_tree_add_item (af_tree, hf_edcp_pt, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
next_tvb = tvb_new_subset (tvb, offset, payload_len, -1);
offset += payload_len;
if (tree)
ci = proto_tree_add_item (af_tree, hf_edcp_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
if (ver & 0x80) {
guint len = offset+2;
const char *crc_buf = (const char *) tvb_get_ptr(tvb, 0, len);
unsigned long c = crc_drm(crc_buf, len, 16, 0x11021, 1);
if (tree) {
proto_item_append_text(ci, " (%s)", (c==0xe2f0)?"Ok":"bad");
proto_tree_add_boolean(af_tree, hf_edcp_crc_ok, tvb, offset, 2, c==0xe2f0);
}
}
offset += 2;
dissector_try_uint(af_dissector_table, pt, next_tvb, pinfo, tree);
}
static void
dissect_tpl(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_tree *tpl_tree = NULL;
guint offset=0;
char *prot=NULL;
guint16 maj, min;
pinfo->current_proto = "DCP-TPL";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCP-TPL");
if(tree) {
proto_item *ti = NULL;
ti = proto_tree_add_item (tree, proto_tpl, tvb, 0, -1, ENC_NA);
tpl_tree = proto_item_add_subtree (ti, ett_tpl);
}
while(offset<tvb_length(tvb)) {
guint32 bits;
guint32 bytes;
char *tag = (char*)tvb_get_ephemeral_string (tvb, offset, 4); offset += 4;
bits = tvb_get_ntohl(tvb, offset); offset += 4;
bytes = bits / 8;
if(bits % 8)
bytes++;
if(tree) {
if(strcmp(tag, "*ptr")==0) {
prot = (char*)tvb_get_ephemeral_string (tvb, offset, 4);
maj = tvb_get_ntohs(tvb, offset+4);
min = tvb_get_ntohs(tvb, offset+6);
proto_tree_add_bytes_format(tpl_tree, hf_tpl_tlv, tvb,
offset-8, bytes+8, tvb_get_ptr(tvb, offset, bytes),
"%s %s rev %d.%d", tag, prot, maj, min);
} else {
proto_tree_add_bytes_format(tpl_tree, hf_tpl_tlv, tvb,
offset-8, bytes+8, tvb_get_ptr(tvb, offset, bytes),
"%s (%u bits)", tag, bits);
}
}
offset += bytes;
}
if(prot) {
dissector_try_string(tpl_dissector_table, prot, tvb, pinfo, tree->parent);
}
}
void
proto_reg_handoff_dcp_etsi (void)
{
dissector_handle_t af_handle;
dissector_handle_t pft_handle;
dissector_handle_t tpl_handle;
af_handle = create_dissector_handle(dissect_af, proto_af);
pft_handle = create_dissector_handle(dissect_pft, proto_pft);
tpl_handle = create_dissector_handle(dissect_tpl, proto_tpl);
heur_dissector_add("udp", dissect_dcp_etsi, proto_dcp_etsi);
dissector_add_string("dcp-etsi.sync", "AF", af_handle);
dissector_add_string("dcp-etsi.sync", "PF", pft_handle);
dissector_add_uint("dcp-af.pt", 'T', tpl_handle);
}
void
proto_register_dcp_etsi (void)
{
static hf_register_info hf_edcp[] = {
{&hf_edcp_sync,
{"sync", "dcp-etsi.sync",
FT_STRING, BASE_NONE, NULL, 0,
"AF or PF", HFILL}
}
};
static hf_register_info hf_af[] = {
{&hf_edcp_len,
{"length", "dcp-af.len",
FT_UINT32, BASE_DEC, NULL, 0,
"length in bytes of the payload", HFILL}
},
{&hf_edcp_seq,
{"frame count", "dcp-af.seq",
FT_UINT16, BASE_DEC, NULL, 0,
"Logical Frame Number", HFILL}
},
{&hf_edcp_crcflag,
{"crc flag", "dcp-af.crcflag",
FT_BOOLEAN, 8, NULL, 0x80,
"Frame is protected by CRC", HFILL}
},
{&hf_edcp_maj,
{"Major Revision", "dcp-af.maj",
FT_UINT8, BASE_DEC, NULL, 0x70,
"Major Protocol Revision", HFILL}
},
{&hf_edcp_min,
{"Minor Revision", "dcp-af.min",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"Minor Protocol Revision", HFILL}
},
{&hf_edcp_pt,
{"Payload Type", "dcp-af.pt",
FT_STRING, BASE_NONE, NULL, 0,
"T means Tag Packets, all other values reserved", HFILL}
},
{&hf_edcp_crc,
{"CRC", "dcp-af.crc",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{&hf_edcp_crc_ok,
{"CRC OK", "dcp-af.crc_ok",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"AF CRC OK", HFILL}
}
};
static hf_register_info hf_pft[] = {
{&hf_edcp_pft_pt,
{"Sub-protocol", "dcp-pft.pt",
FT_UINT8, BASE_DEC, NULL, 0,
"Always AF", HFILL}
},
{&hf_edcp_pseq,
{"Sequence No", "dcp-pft.seq",
FT_UINT16, BASE_DEC, NULL, 0,
"PFT Sequence No", HFILL}
},
{&hf_edcp_findex,
{"Fragment Index", "dcp-pft.findex",
FT_UINT24, BASE_DEC, NULL, 0,
"Index of the fragment within one AF Packet", HFILL}
},
{&hf_edcp_fcount,
{"Fragment Count", "dcp-pft.fcount",
FT_UINT24, BASE_DEC, NULL, 0,
"Number of fragments produced from this AF Packet", HFILL}
},
{&hf_edcp_fecflag,
{"FEC", "dcp-pft.fec",
FT_BOOLEAN, 16, NULL, 0x8000,
"When set the optional RS header is present", HFILL}
},
{&hf_edcp_addrflag,
{"Addr", "dcp-pft.addr",
FT_BOOLEAN, 16, NULL, 0x4000,
"When set the optional transport header is present", HFILL}
},
{&hf_edcp_plen,
{"fragment length", "dcp-pft.len",
FT_UINT16, BASE_DEC, NULL, 0x3fff,
"length in bytes of the payload of this fragment", HFILL}
},
{&hf_edcp_rsk,
{"RSk", "dcp-pft.rsk",
FT_UINT8, BASE_DEC, NULL, 0,
"The length of the Reed Solomon data word", HFILL}
},
{&hf_edcp_rsz,
{"RSz", "dcp-pft.rsz",
FT_UINT8, BASE_DEC, NULL, 0,
"The number of padding bytes in the last Reed Solomon block", HFILL}
},
{&hf_edcp_source,
{"source addr", "dcp-pft.source",
FT_UINT16, BASE_DEC, NULL, 0,
"PFT source identifier", HFILL}
},
{&hf_edcp_dest,
{"dest addr", "dcp-pft.dest",
FT_UINT16, BASE_DEC, NULL, 0,
"PFT destination identifier", HFILL}
},
{&hf_edcp_hcrc,
{"header CRC", "dcp-pft.crc",
FT_UINT16, BASE_HEX, NULL, 0,
"PFT Header CRC", HFILL}
},
{&hf_edcp_hcrc_ok,
{"PFT CRC OK", "dcp-pft.crc_ok",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"PFT Header CRC OK", HFILL}
},
{&hf_edcp_fragments,
{"Message fragments", "dcp-pft.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_edcp_fragment,
{"Message fragment", "dcp-pft.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_edcp_fragment_overlap,
{"Message fragment overlap", "dcp-pft.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_edcp_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"dcp-pft.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_edcp_fragment_multiple_tails,
{"Message has multiple tail fragments",
"dcp-pft.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_edcp_fragment_too_long_fragment,
{"Message fragment too long", "dcp-pft.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_edcp_fragment_error,
{"Message defragmentation error", "dcp-pft.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_edcp_fragment_count,
{"Message fragment count", "dcp-pft.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}},
{&hf_edcp_reassembled_in,
{"Reassembled in", "dcp-pft.reassembled.in",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}},
{&hf_edcp_reassembled_length,
{"Reassembled DCP (ETSI) length", "dcp-pft.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}},
{&hf_edcp_c_max,
{"C max", "dcp-pft.cmax",
FT_UINT16, BASE_DEC, NULL, 0,
"Maximum number of RS chunks sent", HFILL}
},
{&hf_edcp_rx_min,
{"Rx min", "dcp-pft.rxmin",
FT_UINT16, BASE_DEC, NULL, 0,
"Minimum number of fragments needed for RS decode", HFILL}
},
{&hf_edcp_rs_corrected,
{"RS Symbols Corrected", "dcp-pft.rs_corrected",
FT_INT16, BASE_DEC, NULL, 0,
"Number of symbols corrected by RS decode or -1 for failure", HFILL}
},
{&hf_edcp_rs_ok,
{"RS decode OK", "dcp-pft.rs_ok",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"successfully decoded RS blocks", HFILL}
},
{&hf_edcp_pft_payload,
{"payload", "dcp-pft.payload",
FT_BYTES, BASE_NONE, NULL, 0,
"PFT Payload", HFILL}
}
};
static hf_register_info hf_tpl[] = {
{&hf_tpl_tlv,
{"tag", "dcp-tpl.tlv",
FT_BYTES, BASE_NONE, NULL, 0,
"Tag Packet", HFILL}
},
{&hf_tpl_ptr,
{"Type", "dcp-tpl.ptr",
FT_STRING, BASE_NONE, NULL, 0,
"Protocol Type & Revision", HFILL}
}
};
static gint *ett[] = {
&ett_edcp,
&ett_af,
&ett_pft,
&ett_tpl,
&ett_edcp_fragment,
&ett_edcp_fragments
};
proto_dcp_etsi = proto_register_protocol ("ETSI Distribution & Communication Protocol (for DRM)",
"DCP (ETSI)",
"dcp-etsi"
);
proto_af = proto_register_protocol ("DCP Application Framing Layer", "DCP-AF", "dcp-af");
proto_pft = proto_register_protocol ("DCP Protection, Fragmentation & Transport Layer", "DCP-PFT", "dcp-pft");
proto_tpl = proto_register_protocol ("DCP Tag Packet Layer", "DCP-TPL", "dcp-tpl");
proto_register_field_array (proto_dcp_etsi, hf_edcp, array_length (hf_edcp));
proto_register_field_array (proto_af, hf_af, array_length (hf_af));
proto_register_field_array (proto_pft, hf_pft, array_length (hf_pft));
proto_register_field_array (proto_tpl, hf_tpl, array_length (hf_tpl));
proto_register_subtree_array (ett, array_length (ett));
dcp_dissector_table = register_dissector_table("dcp-etsi.sync",
"DCP Sync", FT_STRING, BASE_NONE);
af_dissector_table = register_dissector_table("dcp-af.pt",
"AF Payload Type", FT_UINT8, BASE_DEC);
tpl_dissector_table = register_dissector_table("dcp-tpl.ptr",
"AF Payload Type", FT_STRING, BASE_NONE);
register_init_routine(dcp_init_protocol);
}
