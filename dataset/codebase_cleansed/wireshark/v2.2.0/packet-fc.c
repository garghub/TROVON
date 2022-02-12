static gint
fcseq_equal(gconstpointer v, gconstpointer w)
{
const fcseq_conv_key_t *v1 = (const fcseq_conv_key_t *)v;
const fcseq_conv_key_t *v2 = (const fcseq_conv_key_t *)w;
return (v1->conv_idx == v2->conv_idx);
}
static guint
fcseq_hash (gconstpointer v)
{
const fcseq_conv_key_t *key = (const fcseq_conv_key_t *)v;
guint val;
val = key->conv_idx;
return val;
}
static void
fc_exchange_init_protocol(void)
{
reassembly_table_init(&fc_reassembly_table,
&addresses_reassembly_table_functions);
fcseq_req_hash = g_hash_table_new(fcseq_hash, fcseq_equal);
}
static void
fc_exchange_cleanup_protocol(void)
{
reassembly_table_destroy(&fc_reassembly_table);
g_hash_table_destroy(fcseq_req_hash);
}
static const char* fc_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if ((filter == CONV_FT_SRC_ADDRESS) && (conv->src_address.type == AT_FC))
return "fc.s_id";
if ((filter == CONV_FT_DST_ADDRESS) && (conv->dst_address.type == AT_FC))
return "fc.d_id";
if ((filter == CONV_FT_ANY_ADDRESS) && (conv->src_address.type == AT_FC))
return "fc.id";
return CONV_FILTER_INVALID;
}
static int
fc_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pct;
const fc_hdr *fchdr=(const fc_hdr *)vip;
add_conversation_table_data(hash, &fchdr->s_id, &fchdr->d_id, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts, &fc_ct_dissector_info, PT_NONE);
return 1;
}
static const char* fc_host_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == AT_FC))
return "fc.id";
return CONV_FILTER_INVALID;
}
static int
fc_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pit;
const fc_hdr *fchdr=(const fc_hdr *)vip;
add_hostlist_table_data(hash, &fchdr->s_id, 0, TRUE, 1, pinfo->fd->pkt_len, &fc_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &fchdr->d_id, 0, FALSE, 1, pinfo->fd->pkt_len, &fc_host_dissector_info, PT_NONE);
return 1;
}
static void
fcstat_init(struct register_srt* srt _U_, GArray* srt_array, srt_gui_init_cb gui_callback, void* gui_data)
{
srt_stat_table *fc_srt_table;
guint32 i;
fc_srt_table = init_srt_table("Fibre Channel Types", NULL, srt_array, FC_NUM_PROCEDURES, NULL, NULL, gui_callback, gui_data, NULL);
for (i = 0; i < FC_NUM_PROCEDURES; i++)
{
gchar* tmp_str = val_to_str_wmem(NULL, i, fc_fc4_val, "Unknown(0x%02x)");
init_srt_table_row(fc_srt_table, i, tmp_str);
wmem_free(NULL, tmp_str);
}
}
static int
fcstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
guint i = 0;
srt_stat_table *fc_srt_table;
srt_data_t *data = (srt_data_t *)pss;
const fc_hdr *fc=(const fc_hdr *)prv;
if(!(fc->fctl&FC_FCTL_EXCHANGE_RESPONDER)){
return 0;
}
if ( (!fc->fc_ex) || (fc->fc_ex->first_exchange_frame==0) ){
return 0;
}
fc_srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
add_srt_table_data(fc_srt_table, fc->type, &fc->fc_ex->fc_time, pinfo);
return 1;
}
static void
dissect_fc_ba_acc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *acc_tree;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BLS");
col_set_str(pinfo->cinfo, COL_INFO, "BA_ACC");
if (tree) {
acc_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_fcbls, NULL, "Basic Link Svc");
proto_tree_add_item (acc_tree, hf_fc_bls_seqid_vld, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (acc_tree, hf_fc_bls_lastvld_seqid, tvb, offset++, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item (acc_tree, hf_fc_bls_oxid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item (acc_tree, hf_fc_bls_rxid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item (acc_tree, hf_fc_bls_lowseqcnt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item (acc_tree, hf_fc_bls_hiseqcnt, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_fc_ba_rjt (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *rjt_tree;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BLS");
col_set_str(pinfo->cinfo, COL_INFO, "BA_RJT");
if (tree) {
rjt_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_fcbls, NULL, "Basic Link Svc");
proto_tree_add_item (rjt_tree, hf_fc_bls_rjtcode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rjt_tree, hf_fc_bls_rjtdetail, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rjt_tree, hf_fc_bls_vendor, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
}
static guint8
fc_get_ftype (guint8 r_ctl, guint8 type)
{
switch (r_ctl & 0xF0) {
case FC_RCTL_DEV_DATA:
switch (type) {
case FC_TYPE_SWILS:
if ((r_ctl == 0x2) || (r_ctl == 0x3))
return FC_FTYPE_SWILS;
else
return FC_FTYPE_UNDEF;
case FC_TYPE_IP:
return FC_FTYPE_IP;
case FC_TYPE_SCSI:
return FC_FTYPE_SCSI;
case FC_TYPE_FCCT:
return FC_FTYPE_FCCT;
case FC_TYPE_SB_FROM_CU:
case FC_TYPE_SB_TO_CU:
return FC_FTYPE_SBCCS;
case FC_TYPE_VENDOR:
return FC_FTYPE_OHMS;
default:
return FC_FTYPE_UNDEF;
}
case FC_RCTL_ELS:
if (((r_ctl & 0x0F) == 0x2) || ((r_ctl & 0x0F) == 0x3))
return FC_FTYPE_ELS;
else if (type == FC_TYPE_ELS)
return FC_FTYPE_OHMS;
else
return FC_FTYPE_UNDEF;
case FC_RCTL_LINK_DATA:
switch (type) {
case FC_TYPE_SCSI:
return FC_FTYPE_SCSI;
default:
return FC_FTYPE_LINKDATA;
}
case FC_RCTL_VIDEO:
return FC_FTYPE_VDO;
case FC_RCTL_BLS:
if (type == 0)
return FC_FTYPE_BLS;
else
return FC_FTYPE_UNDEF;
case FC_RCTL_LINK_CTL:
return FC_FTYPE_LINKCTL;
default:
return FC_FTYPE_UNDEF;
}
}
static void
dissect_fc_vft(proto_tree *parent_tree,
tvbuff_t *tvb, int offset)
{
proto_item *item;
proto_tree *tree;
guint8 rctl;
guint8 ver;
guint8 type;
guint8 pri;
guint16 vf_id;
guint8 hop_ct;
rctl = tvb_get_guint8(tvb, offset);
type = tvb_get_guint8(tvb, offset + 1);
ver = (type >> 6) & 3;
type = (type >> 2) & 0xf;
vf_id = tvb_get_ntohs(tvb, offset + 2);
pri = (vf_id >> 13) & 7;
vf_id = (vf_id >> 1) & 0xfff;
hop_ct = tvb_get_guint8(tvb, offset + 4);
item = proto_tree_add_uint_format_value(parent_tree, hf_fc_vft, tvb, offset,
8, vf_id, "VF_ID %d Pri %d Hop Count %d",
vf_id, pri, hop_ct);
tree = proto_item_add_subtree(item, ett_fc_vft);
proto_tree_add_uint(tree, hf_fc_vft_rctl, tvb, offset, 1, rctl);
proto_tree_add_uint(tree, hf_fc_vft_ver, tvb, offset + 1, 1, ver);
proto_tree_add_uint(tree, hf_fc_vft_type, tvb, offset + 1, 1, type);
proto_tree_add_uint(tree, hf_fc_vft_pri, tvb, offset + 2, 1, pri);
proto_tree_add_uint(tree, hf_fc_vft_vf_id, tvb, offset + 2, 2, vf_id);
proto_tree_add_uint(tree, hf_fc_vft_hop_ct, tvb, offset + 4, 1, hop_ct);
}
static void
dissect_fc_fctl(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_fc_fctl_exchange_responder,
&hf_fc_fctl_seq_recipient,
&hf_fc_fctl_exchange_first,
&hf_fc_fctl_exchange_last,
&hf_fc_fctl_seq_last,
&hf_fc_fctl_priority,
&hf_fc_fctl_transfer_seq_initiative,
&hf_fc_fctl_last_data_frame,
&hf_fc_fctl_ack_0_1,
&hf_fc_fctl_rexmitted_seq,
&hf_fc_fctl_abts_ack,
&hf_fc_fctl_rel_offset,
NULL
};
proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_fc_fctl,
ett_fctl, flags, ENC_BIG_ENDIAN, BMT_NO_INT);
}
static void
dissect_fc_helper (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_ifcp, fc_data_t* fc_data)
{
proto_item *ti, *hidden_item;
proto_tree *fc_tree;
tvbuff_t *next_tvb;
int offset = 0, next_offset;
int vft_offset = -1;
gboolean is_lastframe_inseq, is_1frame_inseq, is_exchg_resp = 0;
fragment_head *fcfrag_head;
guint32 frag_id, frag_size;
guint8 df_ctl, seq_id;
guint32 f_ctl;
address addr;
guint32 param, exchange_key;
guint16 real_seqcnt;
guint8 ftype;
fc_hdr* fchdr = wmem_new(wmem_packet_scope(), fc_hdr);
fc_exchange_t *fc_ex;
fc_conv_data_t *fc_conv_data=NULL;
conversation_t *conversation;
fcseq_conv_data_t *cdata;
fcseq_conv_key_t ckey, *req_key;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FC");
fchdr->r_ctl = tvb_get_guint8 (tvb, offset);
fchdr->fc_ex = NULL;
if (fchdr->r_ctl == FC_RCTL_VFT) {
vft_offset = offset;
offset += 8;
fchdr->r_ctl = tvb_get_guint8 (tvb, offset);
}
if(!is_ifcp){
set_address_tvb (&pinfo->dst, AT_FC, 3, tvb, offset+1);
set_address_tvb (&pinfo->src, AT_FC, 3, tvb, offset+5);
pinfo->srcport=0;
pinfo->destport=0;
}
set_address(&fchdr->d_id, pinfo->dst.type, pinfo->dst.len, pinfo->dst.data);
set_address(&fchdr->s_id, pinfo->src.type, pinfo->src.len, pinfo->src.data);
fchdr->cs_ctl = tvb_get_guint8 (tvb, offset+4);
fchdr->type = tvb_get_guint8 (tvb, offset+8);
fchdr->fctl=tvb_get_ntoh24(tvb,offset+9);
fchdr->seqcnt = tvb_get_ntohs (tvb, offset+14);
fchdr->oxid=tvb_get_ntohs(tvb,offset+16);
fchdr->rxid=tvb_get_ntohs(tvb,offset+18);
fchdr->relative_offset=0;
param = tvb_get_ntohl (tvb, offset+20);
seq_id = tvb_get_guint8 (tvb, offset+12);
pinfo->ptype = PT_EXCHG;
conversation=find_or_create_conversation(pinfo);
fc_conv_data=(fc_conv_data_t *)conversation_get_proto_data(conversation, proto_fc);
if(!fc_conv_data){
fc_conv_data=wmem_new(wmem_file_scope(), fc_conv_data_t);
fc_conv_data->exchanges=wmem_tree_new(wmem_file_scope());
fc_conv_data->luns=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_fc, fc_conv_data);
}
fchdr->lun = 0xFFFF;
if (!pinfo->fd->flags.visited) {
fchdr->lun = (guint16)GPOINTER_TO_UINT(wmem_tree_lookup32(fc_conv_data->luns, fchdr->oxid));
}
ti = proto_tree_add_protocol_format (tree, proto_fc, tvb, offset, FC_HEADER_SIZE, "Fibre Channel");
fc_tree = proto_item_add_subtree (ti, ett_fc);
is_1frame_inseq = (((fc_data->sof_eof & FC_DATA_SOF_FIRST_FRAME) == FC_DATA_SOF_FIRST_FRAME) ||
(((fc_data->sof_eof & FC_DATA_SOF_SOFF) == FC_DATA_SOF_SOFF) &&
(fchdr->seqcnt == 0)));
is_lastframe_inseq = ((fc_data->sof_eof & FC_DATA_EOF_LAST_FRAME) == FC_DATA_EOF_LAST_FRAME);
is_lastframe_inseq |= fchdr->fctl & FC_FCTL_SEQ_LAST;
ftype = fc_get_ftype (fchdr->r_ctl, fchdr->type);
col_add_str (pinfo->cinfo, COL_INFO, val_to_str (ftype, fc_ftype_vals,
"Unknown Type (0x%x)"));
if (ftype == FC_FTYPE_LINKCTL)
col_append_fstr (pinfo->cinfo, COL_INFO, ", %s",
val_to_str ((fchdr->r_ctl & 0x0F),
fc_lctl_proto_val,
"LCTL 0x%x"));
if (vft_offset >= 0) {
dissect_fc_vft(fc_tree, tvb, vft_offset);
}
switch (fchdr->r_ctl & 0xF0) {
case FC_RCTL_DEV_DATA:
case FC_RCTL_LINK_DATA:
case FC_RCTL_VIDEO:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/%s)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
val_to_str ((fchdr->r_ctl & 0x0F),
fc_iu_val, "0x%x"));
break;
case FC_RCTL_LINK_CTL:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/%s)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
val_to_str ((fchdr->r_ctl & 0x0F),
fc_lctl_proto_val, "0x%x"));
break;
case FC_RCTL_BLS:
switch (fchdr->type) {
case 0x00:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/%s)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
val_to_str ((fchdr->r_ctl & 0x0F),
fc_bls_proto_val, "0x%x"));
break;
default:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/0x%x)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
fchdr->r_ctl & 0x0F);
break;
}
break;
case FC_RCTL_ELS:
switch (fchdr->type) {
case 0x01:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/%s)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
val_to_str ((fchdr->r_ctl & 0x0F),
fc_els_proto_val, "0x%x"));
break;
default:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/0x%x)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
fchdr->r_ctl & 0x0F);
break;
}
break;
default:
proto_tree_add_uint_format_value(fc_tree, hf_fc_rctl, tvb, offset,
FC_RCTL_SIZE, fchdr->r_ctl,
"0x%x(%s/0x%x)",
fchdr->r_ctl,
val_to_str ((fchdr->r_ctl & 0xF0),
fc_routing_val, "0x%x"),
fchdr->r_ctl & 0x0F);
break;
}
hidden_item = proto_tree_add_uint (fc_tree, hf_fc_ftype, tvb, offset, 1,
ftype);
PROTO_ITEM_SET_HIDDEN(hidden_item);
set_address(&addr, AT_FC, 3, fchdr->d_id.data);
proto_tree_add_item(fc_tree, hf_fc_did, tvb, offset+1, 3, ENC_NA);
hidden_item = proto_tree_add_item (fc_tree, hf_fc_id, tvb, offset+1, 3, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint (fc_tree, hf_fc_csctl, tvb, offset+4, 1, fchdr->cs_ctl);
set_address(&addr, AT_FC, 3, fchdr->s_id.data);
proto_tree_add_item(fc_tree, hf_fc_sid, tvb, offset+5, 3, ENC_NA);
hidden_item = proto_tree_add_item (fc_tree, hf_fc_id, tvb, offset+5, 3, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (ftype == FC_FTYPE_LINKCTL) {
if (((fchdr->r_ctl & 0x0F) == FC_LCTL_FBSYB) ||
((fchdr->r_ctl & 0x0F) == FC_LCTL_FBSYL)) {
proto_tree_add_uint_format_value(fc_tree, hf_fc_type, tvb,
offset+8, FC_TYPE_SIZE,
fchdr->type,"0x%x(%s)", fchdr->type,
fclctl_get_typestr ((guint8) (fchdr->r_ctl & 0x0F),
fchdr->type));
} else {
proto_tree_add_item (fc_tree, hf_fc_type, tvb, offset+8, 1, ENC_BIG_ENDIAN);
}
} else {
proto_tree_add_item (fc_tree, hf_fc_type, tvb, offset+8, 1, ENC_BIG_ENDIAN);
}
dissect_fc_fctl(pinfo, fc_tree, tvb, offset+9);
f_ctl = tvb_get_ntoh24(tvb, offset+9);
proto_tree_add_item (fc_tree, hf_fc_seqid, tvb, offset+12, 1, ENC_BIG_ENDIAN);
df_ctl = tvb_get_guint8(tvb, offset+13);
proto_tree_add_uint (fc_tree, hf_fc_dfctl, tvb, offset+13, 1, df_ctl);
proto_tree_add_uint (fc_tree, hf_fc_seqcnt, tvb, offset+14, 2, fchdr->seqcnt);
proto_tree_add_uint (fc_tree, hf_fc_oxid, tvb, offset+16, 2, fchdr->oxid);
proto_tree_add_uint (fc_tree, hf_fc_rxid, tvb, offset+18, 2, fchdr->rxid);
if (ftype == FC_FTYPE_LINKCTL) {
if (((fchdr->r_ctl & 0x0F) == FC_LCTL_FRJT) ||
((fchdr->r_ctl & 0x0F) == FC_LCTL_PRJT) ||
((fchdr->r_ctl & 0x0F) == FC_LCTL_PBSY)) {
proto_tree_add_uint_format_value(fc_tree, hf_fc_param, tvb,
offset+20, 4, param,
"0x%x(%s)", param,
fclctl_get_paramstr ((fchdr->r_ctl & 0x0F),
param));
} else {
proto_tree_add_item (fc_tree, hf_fc_param, tvb, offset+20, 4, ENC_BIG_ENDIAN);
}
} else if (ftype == FC_FTYPE_BLS) {
if ((fchdr->r_ctl & 0x0F) == FC_BLS_ABTS) {
proto_tree_add_uint_format_value(fc_tree, hf_fc_param, tvb,
offset+20, 4, param,
"0x%x(%s)", param,
((param & 0x0F) == 1 ? "Abort Sequence" :
"Abort Exchange"));
} else {
proto_tree_add_item (fc_tree, hf_fc_param, tvb, offset+20,
4, ENC_BIG_ENDIAN);
}
} else if (ftype == FC_FTYPE_SCSI ) {
if (f_ctl&FC_FCTL_REL_OFFSET){
proto_tree_add_item (fc_tree, hf_fc_relative_offset, tvb, offset+20, 4, ENC_BIG_ENDIAN);
fchdr->relative_offset=tvb_get_ntohl(tvb, offset+20);
} else {
proto_tree_add_item (fc_tree, hf_fc_param, tvb, offset+20, 4, ENC_BIG_ENDIAN);
}
} else {
proto_tree_add_item (fc_tree, hf_fc_param, tvb, offset+20, 4, ENC_BIG_ENDIAN);
}
next_offset = offset + FC_HEADER_SIZE;
if (df_ctl & FC_DFCTL_NH) {
proto_tree_add_item(fc_tree, hf_fc_nh_da, tvb, next_offset, 8, ENC_NA);
proto_tree_add_item(fc_tree, hf_fc_nh_sa, tvb, next_offset+8, 8, ENC_NA);
next_offset += 16;
}
if (ftype == FC_FTYPE_LINKCTL) {
is_lastframe_inseq = TRUE;
} else {
is_exchg_resp = (f_ctl & FC_FCTL_EXCHANGE_RESPONDER) != 0;
}
if (tvb_reported_length (tvb) < FC_HEADER_SIZE) {
proto_tree_add_expert(fc_tree, pinfo, &ei_short_hdr,
tvb, 0, tvb_reported_length(tvb));
return;
}
frag_size = tvb_reported_length (tvb)-FC_HEADER_SIZE;
if ((fc_data->ethertype == ETHERTYPE_UNK) || (fc_data->ethertype == ETHERTYPE_FCFT)) {
if ((frag_size < MDSHDR_TRAILER_SIZE) ||
((frag_size == MDSHDR_TRAILER_SIZE) && (ftype != FC_FTYPE_LINKCTL) &&
(ftype != FC_FTYPE_BLS) && (ftype != FC_FTYPE_OHMS))) {
proto_tree_add_expert(fc_tree, pinfo, &ei_short_hdr,
tvb, FC_HEADER_SIZE, frag_size);
return;
}
frag_size -= MDSHDR_TRAILER_SIZE;
} else if (fc_data->ethertype == ETHERTYPE_BRDWALK) {
if (frag_size <= 8) {
proto_tree_add_expert(fc_tree, pinfo, &ei_short_hdr,
tvb, FC_HEADER_SIZE, frag_size);
return;
}
frag_size -= 8;
}
if (!is_lastframe_inseq) {
col_append_str (pinfo->cinfo, COL_INFO, " (Fragmented)");
}
if ((ftype != FC_FTYPE_LINKCTL) && (ftype != FC_FTYPE_BLS) &&
(ftype != FC_FTYPE_OHMS) &&
(!is_lastframe_inseq || !is_1frame_inseq) && fc_reassemble &&
tvb_bytes_exist(tvb, FC_HEADER_SIZE, frag_size) && tree) {
ckey.conv_idx = conversation->conv_index;
cdata = (fcseq_conv_data_t *)g_hash_table_lookup (fcseq_req_hash,
&ckey);
if (is_1frame_inseq) {
if (cdata) {
cdata->seq_cnt = fchdr->seqcnt;
}
else {
req_key = wmem_new(wmem_file_scope(), fcseq_conv_key_t);
req_key->conv_idx = conversation->conv_index;
cdata = wmem_new(wmem_file_scope(), fcseq_conv_data_t);
cdata->seq_cnt = fchdr->seqcnt;
g_hash_table_insert (fcseq_req_hash, req_key, cdata);
}
real_seqcnt = 0;
}
else if (cdata != NULL) {
real_seqcnt = fchdr->seqcnt - cdata->seq_cnt ;
}
else {
real_seqcnt = fchdr->seqcnt;
}
if (is_lastframe_inseq && !is_1frame_inseq && !real_seqcnt) {
next_tvb = tvb_new_subset_remaining (tvb, next_offset);
col_append_str (pinfo->cinfo, COL_INFO, " (Bogus Fragment)");
} else {
frag_id = ((fchdr->oxid << 16) ^ seq_id) | is_exchg_resp ;
fcfrag_head = fragment_add (&fc_reassembly_table,
tvb, FC_HEADER_SIZE,
pinfo, frag_id, NULL,
real_seqcnt * fc_max_frame_size,
frag_size,
!is_lastframe_inseq);
if (fcfrag_head) {
next_tvb = tvb_new_chain(tvb, fcfrag_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled FC");
hidden_item = proto_tree_add_boolean (fc_tree, hf_fc_reassembled,
tvb, offset+9, 1, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
else {
hidden_item = proto_tree_add_boolean (fc_tree, hf_fc_reassembled,
tvb, offset+9, 1, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
next_tvb = tvb_new_subset_remaining (tvb, next_offset);
call_data_dissector(next_tvb, pinfo, tree);
return;
}
}
} else {
hidden_item = proto_tree_add_boolean (fc_tree, hf_fc_reassembled,
tvb, offset+9, 1, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
next_tvb = tvb_new_subset_remaining (tvb, next_offset);
}
if ((ftype != FC_FTYPE_LINKCTL) && (ftype != FC_FTYPE_BLS)) {
if( (fchdr->fctl&FC_FCTL_REL_OFFSET) && param ){
call_data_dissector(next_tvb, pinfo, tree);
} else {
if (!dissector_try_uint_new (fcftype_dissector_table, ftype,
next_tvb, pinfo, tree, FALSE, fchdr)) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
} else if (ftype == FC_FTYPE_BLS) {
if ((fchdr->r_ctl & 0x0F) == FC_BLS_BAACC) {
dissect_fc_ba_acc (next_tvb, pinfo, tree);
} else if ((fchdr->r_ctl & 0x0F) == FC_BLS_BARJT) {
dissect_fc_ba_rjt (next_tvb, pinfo, tree);
} else if ((fchdr->r_ctl & 0x0F) == FC_BLS_ABTS) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BLS");
col_set_str(pinfo->cinfo, COL_INFO, "ABTS");
}
}
if (!pinfo->fd->flags.visited) {
wmem_tree_insert32(fc_conv_data->luns, fchdr->oxid, GUINT_TO_POINTER((guint)fchdr->lun));
}
exchange_key = ((fchdr->oxid & 0xFFFF) | ((fchdr->lun << 16) & 0xFFFF0000));
fc_ex=(fc_exchange_t*)wmem_tree_lookup32(fc_conv_data->exchanges, exchange_key);
if(!fc_ex){
fc_ex=wmem_new(wmem_file_scope(), fc_exchange_t);
fc_ex->first_exchange_frame=0;
fc_ex->last_exchange_frame=0;
fc_ex->fc_time=pinfo->abs_ts;
wmem_tree_insert32(fc_conv_data->exchanges, exchange_key, fc_ex);
}
fchdr->fc_ex = fc_ex;
if(!pinfo->fd->flags.visited){
if(fchdr->fctl&FC_FCTL_EXCHANGE_FIRST){
fc_ex->first_exchange_frame=pinfo->num;
fc_ex->fc_time = pinfo->abs_ts;
}
if(fchdr->fctl&FC_FCTL_EXCHANGE_LAST){
fc_ex->last_exchange_frame=pinfo->num;
}
}
if(!(fchdr->fctl&FC_FCTL_EXCHANGE_FIRST)){
proto_item *it;
it=proto_tree_add_uint(fc_tree, hf_fc_exchange_first_frame, tvb, 0, 0, fc_ex->first_exchange_frame);
PROTO_ITEM_SET_GENERATED(it);
if(fchdr->fctl&FC_FCTL_EXCHANGE_LAST){
nstime_t delta_ts;
nstime_delta(&delta_ts, &pinfo->abs_ts, &fc_ex->fc_time);
it=proto_tree_add_time(ti, hf_fc_time, tvb, 0, 0, &delta_ts);
PROTO_ITEM_SET_GENERATED(it);
}
}
if(!(fchdr->fctl&FC_FCTL_EXCHANGE_LAST)){
proto_item *it;
it=proto_tree_add_uint(fc_tree, hf_fc_exchange_last_frame, tvb, 0, 0, fc_ex->last_exchange_frame);
PROTO_ITEM_SET_GENERATED(it);
}
tap_queue_packet(fc_tap, pinfo, fchdr);
}
static int
dissect_fc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
fc_data_t* fc_data = (fc_data_t*)data;
if (!fc_data)
return 0;
dissect_fc_helper (tvb, pinfo, tree, FALSE, fc_data);
return tvb_captured_length(tvb);
}
static int
dissect_fc_wtap (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
fc_data_t fc_data;
fc_data.ethertype = ETHERTYPE_UNK;
fc_data.sof_eof = 0;
dissect_fc_helper (tvb, pinfo, tree, FALSE, &fc_data);
return tvb_captured_length(tvb);
}
static int
dissect_fc_ifcp (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
fc_data_t* fc_data = (fc_data_t*)data;
if (!fc_data)
return 0;
dissect_fc_helper (tvb, pinfo, tree, TRUE, fc_data);
return tvb_captured_length(tvb);
}
static int
dissect_fcsof(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
proto_item *it;
proto_tree *fcsof_tree;
tvbuff_t *next_tvb;
guint32 sof;
guint32 crc_computed;
guint32 eof;
const gint FCSOF_TRAILER_LEN = 8;
const gint FCSOF_HEADER_LEN = 4;
gint crc_offset = tvb_reported_length(tvb) - FCSOF_TRAILER_LEN;
gint eof_offset = crc_offset + 4;
gint sof_offset = 0;
gint frame_len_for_checksum;
fc_data_t fc_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FC");
sof = tvb_get_ntohl(tvb, 0);
frame_len_for_checksum = crc_offset - FCSOF_HEADER_LEN;
crc_computed = crc32_802_tvb(tvb_new_subset_length(tvb, 4, frame_len_for_checksum), frame_len_for_checksum);
eof = tvb_get_ntohl(tvb, eof_offset);
it = proto_tree_add_protocol_format(tree, proto_fcsof, tvb, 0,
4, "Fibre Channel Delimiter: SOF: %s EOF: %s",
val_to_str(sof, fc_sof_vals, "0x%x"),
val_to_str(eof, fc_eof_vals, "0x%x"));
fcsof_tree = proto_item_add_subtree(it, ett_fcsof);
proto_tree_add_uint(fcsof_tree, hf_fcsof, tvb, sof_offset, 4, sof);
proto_tree_add_checksum(fcsof_tree, tvb, crc_offset, hf_fccrc, -1, &ei_fccrc, pinfo, crc_computed, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
proto_tree_add_uint(fcsof_tree, hf_fceof, tvb, eof_offset, 4, eof);
next_tvb = tvb_new_subset_remaining(tvb, 4);
fc_data.ethertype = 0;
fc_data.sof_eof = 0;
if (sof == FC_SOFI2 || sof == FC_SOFI3) {
fc_data.sof_eof = FC_DATA_SOF_FIRST_FRAME;
} else if (sof == FC_SOFF) {
fc_data.sof_eof = FC_DATA_SOF_SOFF;
}
if (eof == EOFT_POS || eof == EOFT_NEG) {
fc_data.sof_eof |= FC_DATA_EOF_LAST_FRAME;
} else if (eof == EOFDTI_NEG || eof == EOFDTI_POS) {
fc_data.sof_eof |= FC_DATA_EOF_INVALID;
}
call_dissector_with_data(fc_handle, next_tvb, pinfo, tree, &fc_data);
return tvb_captured_length(tvb);
}
void
proto_register_fc(void)
{
static hf_register_info hf[] = {
{ &hf_fc_rctl,
{ "R_CTL", "fc.r_ctl", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_fc_ftype,
{"Frame type", "fc.ftype", FT_UINT8, BASE_HEX, VALS(fc_ftype_vals),
0x0, "Derived Type", HFILL}},
{ &hf_fc_did,
{ "Dest Addr", "fc.d_id", FT_BYTES, SEP_DOT, NULL, 0x0,
"Destination Address", HFILL}},
{ &hf_fc_csctl,
{"CS_CTL", "fc.cs_ctl", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fc_sid,
{"Src Addr", "fc.s_id", FT_BYTES, SEP_DOT, NULL, 0x0,
"Source Address", HFILL}},
{ &hf_fc_id,
{"Addr", "fc.id", FT_BYTES, SEP_DOT, NULL, 0x0,
"Source or Destination Address", HFILL}},
{ &hf_fc_type,
{"Type", "fc.type", FT_UINT8, BASE_HEX, VALS (fc_fc4_val), 0x0,
NULL, HFILL}},
{ &hf_fc_fctl,
{"F_CTL", "fc.f_ctl", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fc_seqid,
{"SEQ_ID", "fc.seq_id", FT_UINT8, BASE_HEX, NULL, 0x0,
"Sequence ID", HFILL}},
{ &hf_fc_dfctl,
{"DF_CTL", "fc.df_ctl", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fc_seqcnt,
{"SEQ_CNT", "fc.seq_cnt", FT_UINT16, BASE_DEC, NULL, 0x0,
"Sequence Count", HFILL}},
{ &hf_fc_oxid,
{"OX_ID", "fc.ox_id", FT_UINT16, BASE_HEX, NULL, 0x0, "Originator ID",
HFILL}},
{ &hf_fc_rxid,
{"RX_ID", "fc.rx_id", FT_UINT16, BASE_HEX, NULL, 0x0, "Receiver ID",
HFILL}},
{ &hf_fc_param,
{"Parameter", "fc.parameter", FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fc_reassembled,
{"Reassembled Frame", "fc.reassembled", FT_BOOLEAN, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_fc_nh_da,
{"Network DA", "fc.nethdr.da", FT_FCWWN, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_fc_nh_sa,
{"Network SA", "fc.nethdr.sa", FT_FCWWN, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_fc_bls_seqid_vld,
{"SEQID Valid", "fc.bls_seqidvld", FT_UINT8, BASE_HEX,
VALS (fc_bls_seqid_val), 0x0, NULL, HFILL}},
{ &hf_fc_bls_lastvld_seqid,
{"Last Valid SEQID", "fc.bls_lastseqid", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fc_bls_oxid,
{"OXID", "fc.bls_oxid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fc_bls_rxid,
{"RXID", "fc.bls_rxid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fc_bls_lowseqcnt,
{"Low SEQCNT", "fc.bls_lseqcnt", FT_UINT16, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fc_bls_hiseqcnt,
{"High SEQCNT", "fc.bls_hseqcnt", FT_UINT16, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fc_bls_rjtcode,
{"Reason", "fc.bls_reason", FT_UINT8, BASE_HEX, VALS(fc_bls_barjt_val),
0x0, NULL, HFILL}},
{ &hf_fc_bls_rjtdetail,
{"Reason Explanation", "fc.bls_rjtdetail", FT_UINT8, BASE_HEX,
VALS (fc_bls_barjt_det_val), 0x0, NULL, HFILL}},
{ &hf_fc_bls_vendor,
{"Vendor Unique Reason", "fc.bls_vnduniq", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fc_fctl_exchange_responder,
{"ExgRpd", "fc.fctl.exchange_responder", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_exchange_responder),
FC_FCTL_EXCHANGE_RESPONDER, "Exchange Responder?", HFILL}},
{ &hf_fc_fctl_seq_recipient,
{"SeqRec", "fc.fctl.seq_recipient", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_seq_recipient),
FC_FCTL_SEQ_RECIPIENT, "Seq Recipient?", HFILL}},
{ &hf_fc_fctl_exchange_first,
{"ExgFst", "fc.fctl.exchange_first", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_exchange_first),
FC_FCTL_EXCHANGE_FIRST, "First Exchange?", HFILL}},
{ &hf_fc_fctl_exchange_last,
{"ExgLst", "fc.fctl.exchange_last", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_exchange_last),
FC_FCTL_EXCHANGE_LAST, "Last Exchange?", HFILL}},
{ &hf_fc_fctl_seq_last,
{"SeqLst", "fc.fctl.seq_last", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_seq_last),
FC_FCTL_SEQ_LAST, "Last Sequence?", HFILL}},
{ &hf_fc_fctl_priority,
{"Pri", "fc.fctl.priority", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_priority),
FC_FCTL_PRIORITY, "Priority", HFILL}},
{ &hf_fc_fctl_transfer_seq_initiative,
{"TSI", "fc.fctl.transfer_seq_initiative", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_transfer_seq_initiative),
FC_FCTL_TRANSFER_SEQ_INITIATIVE, "Transfer Seq Initiative", HFILL}},
{ &hf_fc_fctl_rexmitted_seq,
{"RetSeq", "fc.fctl.rexmitted_seq", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_rexmitted_seq),
FC_FCTL_REXMITTED_SEQ, "Retransmitted Sequence", HFILL}},
{ &hf_fc_fctl_rel_offset,
{"RelOff", "fc.fctl.rel_offset", FT_BOOLEAN, 24, TFS(&tfs_fc_fctl_rel_offset),
FC_FCTL_REL_OFFSET, "rel offset", HFILL}},
{ &hf_fc_fctl_last_data_frame,
{"LDF", "fc.fctl.last_data_frame", FT_UINT24, BASE_HEX, VALS(last_data_frame_vals),
FC_FCTL_LAST_DATA_FRAME_MASK, "Last Data Frame?", HFILL}},
{ &hf_fc_fctl_ack_0_1,
{"A01", "fc.fctl.ack_0_1", FT_UINT24, BASE_HEX, VALS(ack_0_1_vals),
FC_FCTL_ACK_0_1_MASK, "Ack 0/1 value", HFILL}},
{ &hf_fc_fctl_abts_ack,
{"AA", "fc.fctl.abts_ack", FT_UINT24, BASE_HEX, VALS(abts_ack_vals),
FC_FCTL_ABTS_MASK, "ABTS ACK values", HFILL}},
#if 0
{ &hf_fc_fctl_abts_not_ack,
{"AnA", "fc.fctl.abts_not_ack", FT_UINT24, BASE_HEX, VALS(abts_not_ack_vals),
FC_FCTL_ABTS_MASK, "ABTS not ACK vals", HFILL}},
#endif
{ &hf_fc_exchange_first_frame,
{ "Exchange First In", "fc.exchange_first_frame", FT_FRAMENUM, BASE_NONE, NULL,
0, "The first frame of this exchange is in this frame", HFILL }},
{ &hf_fc_exchange_last_frame,
{ "Exchange Last In", "fc.exchange_last_frame", FT_FRAMENUM, BASE_NONE, NULL,
0, "The last frame of this exchange is in this frame", HFILL }},
{ &hf_fc_time,
{ "Time from Exchange First", "fc.time", FT_RELATIVE_TIME, BASE_NONE, NULL,
0, "Time since the first frame of the Exchange", HFILL }},
{ &hf_fc_relative_offset,
{"Relative Offset", "fc.relative_offset", FT_UINT32, BASE_DEC, NULL,
0, "Relative offset of data", HFILL}},
{ &hf_fc_vft,
{"VFT Header", "fc.vft", FT_UINT16, BASE_DEC, NULL,
0, NULL, HFILL}},
{ &hf_fc_vft_rctl,
{"R_CTL", "fc.vft.rctl", FT_UINT8, BASE_HEX, NULL,
0, NULL, HFILL}},
{ &hf_fc_vft_ver,
{"Version", "fc.vft.ver", FT_UINT8, BASE_DEC, NULL,
0, "Version of VFT header", HFILL}},
{ &hf_fc_vft_type,
{"Type", "fc.vft.type", FT_UINT8, BASE_DEC, NULL,
0, "Type of tagged frame", HFILL}},
{ &hf_fc_vft_pri,
{"Priority", "fc.vft.type", FT_UINT8, BASE_DEC, NULL,
0, "QoS Priority", HFILL}},
{ &hf_fc_vft_vf_id,
{"VF_ID", "fc.vft.vf_id", FT_UINT16, BASE_DEC, NULL,
0, "Virtual Fabric ID", HFILL}},
{ &hf_fc_vft_hop_ct,
{"HopCT", "fc.vft.hop_ct", FT_UINT8, BASE_DEC, NULL,
0, "Hop Count", HFILL}},
};
static gint *ett[] = {
&ett_fc,
&ett_fcbls,
&ett_fc_vft,
&ett_fctl
};
static ei_register_info ei[] = {
{ &ei_fccrc,
{ "fc.crc.bad", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_short_hdr,
{ "fc.short_hdr", PI_MALFORMED, PI_ERROR,
"Packet length is shorter than the required header", EXPFILL }},
#if 0
{ &ei_frag_size,
{ "fc.frag_size", PI_MALFORMED, PI_ERROR,
"Invalid fragment size", EXPFILL }}
#endif
};
module_t *fc_module;
expert_module_t* expert_fc;
static hf_register_info sof_hf[] = {
{ &hf_fcsof,
{ "SOF", "fc.sof", FT_UINT32, BASE_HEX, VALS(fc_sof_vals), 0,
NULL, HFILL }},
{ &hf_fceof,
{ "EOF", "fc.eof", FT_UINT32, BASE_HEX, VALS(fc_eof_vals), 0,
NULL, HFILL }},
{ &hf_fccrc,
{ "CRC", "fc.crc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
};
static gint *sof_ett[] = {
&ett_fcsof,
&ett_fceof,
&ett_fccrc
};
proto_fc = proto_register_protocol ("Fibre Channel", "FC", "fc");
fc_handle = register_dissector ("fc", dissect_fc, proto_fc);
register_dissector ("fc_ifcp", dissect_fc_ifcp, proto_fc);
fc_tap = register_tap("fc");
proto_register_field_array(proto_fc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_fc = expert_register_protocol(proto_fc);
expert_register_field_array(expert_fc, ei, array_length(ei));
fcftype_dissector_table = register_dissector_table ("fc.ftype",
"FC Frame Type",
proto_fc, FT_UINT8, BASE_HEX);
fc_module = prefs_register_protocol (proto_fc, NULL);
prefs_register_bool_preference (fc_module,
"reassemble",
"Reassemble multi-frame sequences",
"If enabled, reassembly of multi-frame "
"sequences is done",
&fc_reassemble);
prefs_register_uint_preference (fc_module,
"max_frame_size", "Max FC Frame Size",
"This is the size of non-last frames in a "
"multi-frame sequence", 10,
&fc_max_frame_size);
register_init_routine (fc_exchange_init_protocol);
register_cleanup_routine (fc_exchange_cleanup_protocol);
proto_fcsof = proto_register_protocol("Fibre Channel Delimiters", "FCSoF", "fcsof");
proto_register_field_array(proto_fcsof, sof_hf, array_length(sof_hf));
proto_register_subtree_array(sof_ett, array_length(sof_ett));
fcsof_handle = register_dissector("fcsof", dissect_fcsof, proto_fcsof);
register_conversation_table(proto_fc, TRUE, fc_conversation_packet, fc_hostlist_packet);
register_srt_table(proto_fc, NULL, 1, fcstat_packet, fcstat_init, NULL);
}
void
proto_reg_handoff_fc (void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_FIBRE_CHANNEL_FC2,
create_dissector_handle(dissect_fc_wtap, proto_fc));
dissector_add_uint("wtap_encap", WTAP_ENCAP_FIBRE_CHANNEL_FC2_WITH_FRAME_DELIMS, fcsof_handle);
}
