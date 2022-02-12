static proto_item*
iuup_proto_tree_add_bits(proto_tree* tree, int hf, tvbuff_t* tvb, int offset, int bit_offset, guint bits, guint8** buf) {
static const guint8 masks[] = {0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe};
int len = (bits + bit_offset)/8 + (((bits + bit_offset)%8) ? 0 : 1);
guint8* shifted_buffer;
proto_item* pi;
int i;
DISSECTOR_ASSERT(bit_offset < 8);
shifted_buffer = (guint8 *)ep_tvb_memdup(tvb,offset,len+1);
for(i = 0; i < len; i++) {
shifted_buffer[i] <<= bit_offset;
shifted_buffer[i] |= (shifted_buffer[i+1] & masks[bit_offset]) >> (8 - bit_offset);
}
shifted_buffer[len] <<= bit_offset;
shifted_buffer[len] &= masks[(bits + bit_offset)%8];
if (buf)
*buf = shifted_buffer;
pi = proto_tree_add_bytes(tree, hf, tvb, offset, len + (((bits + bit_offset)%8) ? 1 : 0) , shifted_buffer);
proto_item_append_text(pi, " (%i Bits)", bits);
return pi;
}
static void dissect_iuup_payload(tvbuff_t* tvb, packet_info* pinfo _U_, proto_tree* tree, guint rfci_id _U_, int offset) {
iuup_circuit_t* iuup_circuit;
iuup_rfci_t *rfci;
int last_offset = tvb_length(tvb) - 1;
guint bit_offset = 0;
proto_item* pi;
pi = proto_tree_add_item(tree,hf_iuup_payload,tvb,offset,-1,ENC_NA);
if ( ! dissect_fields ) {
return;
} else if ( ! pinfo->circuit_id
|| ! ( iuup_circuit = (iuup_circuit_t *)g_hash_table_lookup(circuits,GUINT_TO_POINTER(pinfo->circuit_id)) ) ) {
proto_item_set_expert_flags(pi, PI_UNDECODED, PI_WARN);
return;
}
for(rfci = iuup_circuit->rfcis; rfci; rfci = rfci->next)
if ( rfci->id == rfci_id )
break;
if (!rfci) {
proto_item_set_expert_flags(pi, PI_UNDECODED, PI_WARN);
return;
}
tree = proto_item_add_subtree(pi,ett_payload);
do {
guint i;
guint subflows = rfci->num_of_subflows;
proto_tree* flow_tree;
pi = proto_tree_add_text(tree,tvb,offset,-1,"Payload Frame");
flow_tree = proto_item_add_subtree(pi,ett_payload_subflows);
bit_offset = 0;
for(i = 0; i < subflows; i++) {
if (! rfci->subflow[i].len)
continue;
iuup_proto_tree_add_bits(flow_tree, hf_iuup_rfci_subflow[rfci->id][i], tvb,
offset + (bit_offset/8),
bit_offset % 8,
rfci->subflow[i].len,
NULL);
bit_offset += rfci->subflow[i].len;
}
offset += (bit_offset / 8) + ((bit_offset % 8) ? 1 : 0);
} while (offset <= last_offset);
}
static guint dissect_rfcis(tvbuff_t* tvb, packet_info* pinfo _U_, proto_tree* tree, int* offset, iuup_circuit_t* iuup_circuit) {
proto_item* pi;
proto_tree* pt;
guint8 oct;
guint c = 0;
guint i;
do {
iuup_rfci_t *rfci = se_new0(iuup_rfci_t);
guint len = 0;
DISSECTOR_ASSERT(c < 64);
pi = proto_tree_add_item(tree,hf_iuup_init_rfci_ind,tvb,*offset,-1,ENC_NA);
pt = proto_item_add_subtree(pi,ett_rfci);
proto_tree_add_item(pt,hf_iuup_init_rfci_lri[c],tvb,*offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(pt,hf_iuup_init_rfci_li[c],tvb,*offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(pt,hf_iuup_init_rfci[c],tvb,*offset,1,ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb,*offset);
rfci->id = oct & 0x3f;
rfci->num_of_subflows = iuup_circuit->num_of_subflows;
len = (oct & 0x40) ? 2 : 1;
proto_item_set_text(pi,"RFCI %i Initialization",rfci->id);
proto_item_set_len(pi,(len*iuup_circuit->num_of_subflows)+1);
(*offset)++;
for(i = 0; i < iuup_circuit->num_of_subflows; i++) {
guint subflow_len;
if (len == 2) {
subflow_len = tvb_get_ntohs(tvb,*offset);
} else {
subflow_len = tvb_get_guint8(tvb,*offset);
}
rfci->subflow[i].len = subflow_len;
rfci->sum_len += subflow_len;
proto_tree_add_uint(pt,hf_iuup_init_rfci_flow_len[c][i],tvb,*offset,len,subflow_len);
(*offset) += len;
}
if (iuup_circuit->last_rfci) {
iuup_circuit->last_rfci = iuup_circuit->last_rfci->next = rfci;
} else {
iuup_circuit->last_rfci = iuup_circuit->rfcis = rfci;
}
c++;
} while ( ! (oct & 0x80) );
return c - 1;
}
static void dissect_iuup_init(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree) {
int offset = 4;
guint8 oct = tvb_get_guint8(tvb,offset);
guint n = (oct & 0x0e) >> 1;
gboolean ti = oct & 0x10;
guint i;
guint rfcis;
proto_item* pi;
proto_tree* support_tree = NULL;
proto_tree* iptis_tree;
iuup_circuit_t* iuup_circuit = NULL;
if (pinfo->circuit_id) {
iuup_circuit = (iuup_circuit_t *)g_hash_table_lookup(circuits,GUINT_TO_POINTER(pinfo->circuit_id));
if (iuup_circuit) {
g_hash_table_remove(circuits,GUINT_TO_POINTER(pinfo->circuit_id));
}
iuup_circuit = se_new0(iuup_circuit_t);
} else {
iuup_circuit = ep_new0(iuup_circuit_t);
}
iuup_circuit->id = pinfo->circuit_id;
iuup_circuit->num_of_subflows = n;
iuup_circuit->rfcis = NULL;
iuup_circuit->last_rfci = NULL;
if (pinfo->circuit_id) {
g_hash_table_insert(circuits,GUINT_TO_POINTER(iuup_circuit->id),iuup_circuit);
}
if (tree) {
proto_tree_add_item(tree,hf_iuup_spare_e0,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_iuup_init_ti,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_iuup_init_subflows_per_rfci,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_iuup_init_chain_ind,tvb,offset,1,ENC_BIG_ENDIAN);
}
offset++;
rfcis = dissect_rfcis(tvb, pinfo, tree, &offset, iuup_circuit);
if (!tree) return;
if (ti) {
pi = proto_tree_add_text(tree,tvb,offset,(rfcis/2)+(rfcis%2),"IPTIs");
iptis_tree = proto_item_add_subtree(pi,ett_ipti);
for (i = 0; i <= rfcis; i++) {
proto_tree_add_item(iptis_tree,hf_iuup_init_ipti[i],tvb,offset,1,ENC_BIG_ENDIAN);
if ((i%2)) {
offset++;
}
}
if ((i%2)) {
offset++;
}
}
if (tree) {
pi = proto_tree_add_item(tree,hf_iuup_mode_versions,tvb,offset,2,ENC_BIG_ENDIAN);
support_tree = proto_item_add_subtree(pi,ett_support);
for (i = 0; i < 16; i++) {
proto_tree_add_item(support_tree,hf_iuup_mode_versions_a[i],tvb,offset,2,ENC_BIG_ENDIAN);
}
}
offset += 2;
proto_tree_add_item(tree,hf_iuup_data_pdu_type,tvb,offset,1,ENC_BIG_ENDIAN);
}
static void dissect_iuup_ratectl(tvbuff_t* tvb, packet_info* pinfo _U_, proto_tree* tree) {
guint num = tvb_get_guint8(tvb,4) & 0x3f;
guint i;
proto_item* pi;
proto_tree* inds_tree;
int offset = 4;
pi = proto_tree_add_item(tree,hf_iuup_num_rfci_ind,tvb,4,1,ENC_BIG_ENDIAN);
inds_tree = proto_item_add_subtree(pi,ett_rfciinds);
for (i = 0; i < num; i++) {
if (! (i % 8) ) offset++;
proto_tree_add_item(inds_tree,hf_iuup_rfci_ratectl[i],tvb,offset,1,ENC_BIG_ENDIAN);
}
}
static void add_hdr_crc(tvbuff_t* tvb, packet_info* pinfo, proto_item* iuup_tree, guint16 crccheck)
{
proto_item *crc_item;
crc_item = proto_tree_add_item(iuup_tree,hf_iuup_hdr_crc,tvb,2,1,ENC_BIG_ENDIAN);
if (crccheck) {
proto_item_append_text(crc_item, "%s", " [incorrect]");
expert_add_info_format(pinfo, crc_item, PI_CHECKSUM, PI_ERROR, "Bad checksum");
}
}
static void add_payload_crc(tvbuff_t* tvb, packet_info* pinfo, proto_item* iuup_tree)
{
proto_item *crc_item;
int length = tvb_length(tvb);
guint16 crc10 = tvb_get_ntohs(tvb, 2) & 0x3FF;
guint16 crccheck = update_crc10_by_bytes(crc10, tvb_get_ptr(tvb, 4, length - 4), length - 4);
crc_item = proto_tree_add_item(iuup_tree,hf_iuup_payload_crc,tvb,2,2,ENC_BIG_ENDIAN);
if (crccheck) {
proto_item_append_text(crc_item, "%s", " [incorrect]");
expert_add_info_format(pinfo, crc_item, PI_CHECKSUM, PI_ERROR, "Bad checksum");
}
}
static void dissect_iuup(tvbuff_t* tvb_in, packet_info* pinfo, proto_tree* tree) {
proto_item* pi;
proto_item* iuup_item = NULL;
proto_item* pdutype_item = NULL;
proto_tree* iuup_tree = NULL;
proto_item* proc_item = NULL;
proto_item* ack_item = NULL;
guint8 first_octet;
guint8 second_octet;
guint8 pdutype;
guint phdr = 0;
guint16 hdrcrc6;
guint16 crccheck;
tvbuff_t* tvb = tvb_in;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IuUP");
if (two_byte_pseudoheader) {
int len = tvb_length(tvb_in) - 2;
phdr = tvb_get_ntohs(tvb,0);
proto_tree_add_item(tree,hf_iuup_direction,tvb,0,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_iuup_circuit_id,tvb,0,2,ENC_BIG_ENDIAN);
phdr &= 0x7fff;
pinfo->circuit_id = phdr;
tvb = tvb_new_subset(tvb_in,2,len,len);
}
first_octet = tvb_get_guint8(tvb,0);
second_octet = tvb_get_guint8(tvb,1);
hdrcrc6 = tvb_get_guint8(tvb, 2) >> 2;
crccheck = update_crc6_by_bytes(hdrcrc6, first_octet, second_octet);
pdutype = ( first_octet & PDUTYPE_MASK ) >> 4;
if (tree) {
iuup_item = proto_tree_add_item(tree,proto_iuup,tvb,0,-1,ENC_NA);
iuup_tree = proto_item_add_subtree(iuup_item,ett_iuup);
pdutype_item = proto_tree_add_item(iuup_tree,hf_iuup_pdu_type,tvb,0,1,ENC_BIG_ENDIAN);
}
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(pdutype, iuup_colinfo_pdu_types, "Unknown PDU Type(%u) "));
switch(pdutype) {
case PDUTYPE_DATA_WITH_CRC:
col_append_fstr(pinfo->cinfo, COL_INFO,"FN: %x RFCI: %u", (guint)(first_octet & 0x0f) ,(guint)(second_octet & 0x3f));
if (!tree) return;
proto_tree_add_item(iuup_tree,hf_iuup_frame_number,tvb,0,1,ENC_BIG_ENDIAN);
pi = proto_tree_add_item(iuup_tree,hf_iuup_fqc,tvb,1,1,ENC_BIG_ENDIAN);
if (first_octet & FQC_MASK) {
proto_item_set_expert_flags(pi, PI_RESPONSE_CODE, PI_WARN);
proto_item_set_expert_flags(iuup_item, PI_RESPONSE_CODE, PI_WARN);
}
proto_tree_add_item(iuup_tree,hf_iuup_rfci,tvb,1,1,ENC_BIG_ENDIAN);
add_hdr_crc(tvb, pinfo, iuup_tree, crccheck);
add_payload_crc(tvb, pinfo, iuup_tree);
dissect_iuup_payload(tvb,pinfo,iuup_tree,second_octet & 0x3f,4);
return;
case PDUTYPE_DATA_NO_CRC:
col_append_fstr(pinfo->cinfo, COL_INFO," RFCI %u", (guint)(second_octet & 0x3f));
if (!tree)
return;
proto_tree_add_item(iuup_tree,hf_iuup_frame_number,tvb,0,1,ENC_BIG_ENDIAN);
pi = proto_tree_add_item(iuup_tree,hf_iuup_fqc,tvb,1,1,ENC_BIG_ENDIAN);
if (first_octet & FQC_MASK) {
proto_item_set_expert_flags(pi, PI_RESPONSE_CODE, PI_WARN);
proto_item_set_expert_flags(iuup_item, PI_RESPONSE_CODE, PI_WARN);
}
proto_tree_add_item(iuup_tree,hf_iuup_rfci,tvb,1,1,ENC_BIG_ENDIAN);
add_hdr_crc(tvb, pinfo, iuup_tree, crccheck);
dissect_iuup_payload(tvb,pinfo,iuup_tree,second_octet & 0x3f,3);
return;
case PDUTYPE_DATA_CONTROL_PROC:
if (tree) {
ack_item = proto_tree_add_item(iuup_tree,hf_iuup_ack_nack,tvb,0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(iuup_tree,hf_iuup_frame_number_t14,tvb,0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(iuup_tree,hf_iuup_mode_version,tvb,1,1,ENC_BIG_ENDIAN);
proc_item = proto_tree_add_item(iuup_tree,hf_iuup_procedure_indicator,tvb,1,1,ENC_BIG_ENDIAN);
add_hdr_crc(tvb, pinfo, iuup_tree, crccheck);
}
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(first_octet & ACKNACK_MASK,
iuup_colinfo_acknack_vals, "[action:%u] "));
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(second_octet & PROCEDURE_MASK,
iuup_colinfo_procedures, "[proc:%u] "));
switch ( first_octet & ACKNACK_MASK ) {
case ACKNACK_ACK:
switch(second_octet & PROCEDURE_MASK) {
case PROC_INIT:
if (!tree) return;
proto_tree_add_item(iuup_tree,hf_iuup_spare_03,tvb,2,1,ENC_BIG_ENDIAN);
proto_tree_add_item(iuup_tree,hf_iuup_spare_ff,tvb,3,1,ENC_BIG_ENDIAN);
return;
case PROC_RATE:
if (!tree) return;
dissect_iuup_ratectl(tvb,pinfo,iuup_tree);
return;
case PROC_TIME:
case PROC_ERROR:
break;
default:
if (!tree) return;
proto_item_set_expert_flags(proc_item, PI_MALFORMED, PI_ERROR);
return;
}
break;
case ACKNACK_NACK:
if (!tree) return;
pi = proto_tree_add_item(iuup_tree,hf_iuup_error_cause_val,tvb,4,1,ENC_BIG_ENDIAN);
proto_item_set_expert_flags(pi, PI_RESPONSE_CODE, PI_ERROR);
return;
case ACKNACK_RESERVED:
if (!tree) return;
proto_item_set_expert_flags(ack_item, PI_MALFORMED, PI_ERROR);
return;
case ACKNACK_PROC:
break;
}
switch( second_octet & PROCEDURE_MASK ) {
case PROC_INIT:
if (tree) add_payload_crc(tvb, pinfo, iuup_tree);
dissect_iuup_init(tvb,pinfo,iuup_tree);
return;
case PROC_RATE:
if (!tree) return;
add_payload_crc(tvb, pinfo, iuup_tree);
dissect_iuup_ratectl(tvb,pinfo,iuup_tree);
return;
case PROC_TIME:
{
proto_tree* time_tree;
guint ta;
if (!tree) return;
ta = tvb_get_guint8(tvb,4);
pi = proto_tree_add_item(iuup_tree,hf_iuup_time_align,tvb,4,1,ENC_BIG_ENDIAN);
time_tree = proto_item_add_subtree(pi,ett_time);
if (ta >= 1 && ta <= 80) {
pi = proto_tree_add_uint(time_tree,hf_iuup_delay,tvb,4,1,ta * 500);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_float(time_tree,hf_iuup_delta,tvb,4,1,((gfloat)((gint)(ta) * 500))/(gfloat)1000000.0);
PROTO_ITEM_SET_GENERATED(pi);
} else if (ta >= 129 && ta <= 208) {
pi = proto_tree_add_uint(time_tree,hf_iuup_advance,tvb,4,1,(ta-128) * 500);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_float(time_tree,hf_iuup_delta,tvb,4,1,((gfloat)((gint)(-(((gint)ta)-128))) * 500)/(gfloat)1000000.0);
PROTO_ITEM_SET_GENERATED(pi);
} else {
proto_item_set_expert_flags(pi, PI_MALFORMED, PI_ERROR);
}
proto_tree_add_item(iuup_tree,hf_iuup_spare_bytes,tvb,5,-1,ENC_NA);
return;
}
case PROC_ERROR:
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(tvb_get_guint8(tvb,4) & 0x3f,iuup_error_causes,"Unknown (%u)"));
if (!tree)
return;
proto_tree_add_item(iuup_tree,hf_iuup_error_distance,tvb,4,1,ENC_BIG_ENDIAN);
pi = proto_tree_add_item(iuup_tree,hf_iuup_errorevt_cause_val,tvb,4,1,ENC_BIG_ENDIAN);
proto_item_set_expert_flags(pi, PI_RESPONSE_CODE, PI_ERROR);
proto_tree_add_item(iuup_tree,hf_iuup_spare_bytes,tvb,5,-1,ENC_NA);
return;
default:
if (!tree) return;
proto_item_set_expert_flags(proc_item, PI_MALFORMED, PI_ERROR);
return;
}
default:
if (!tree) return;
proto_item_set_expert_flags(pdutype_item, PI_MALFORMED, PI_ERROR);
return;
}
}
static gboolean dissect_iuup_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int len = tvb_length(tvb);
guint8 first_octet = tvb_get_guint8(tvb,0);
guint8 second_octet = tvb_get_guint8(tvb,1);
guint16 hdrcrc6 = tvb_get_guint8(tvb, 2) >> 2;
if (update_crc6_by_bytes(hdrcrc6, first_octet, second_octet)) return FALSE;
switch ( first_octet & 0xf0 ) {
case 0x00: {
if (len<7) return FALSE;
if (update_crc10_by_bytes((guint16)(tvb_get_ntohs(tvb, 4) & 0x3FF), tvb_get_ptr(tvb, 6, len-4), len-4) ) return FALSE;
break;
}
case 0x10:
if (len<5) return FALSE;
break;
case 0xe0:
if (len<5) return FALSE;
if( (second_octet & 0x0f) > 3) return FALSE;
break;
default:
return FALSE;
}
dissect_iuup(tvb, pinfo, tree);
return TRUE;
}
static void find_iuup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int len = tvb_length(tvb);
int offset = 0;
while (len > 3) {
if ( dissect_iuup_heur(tvb_new_subset_remaining(tvb,offset), pinfo, tree) )
return;
offset++;
len--;
}
call_dissector(data_handle, tvb, pinfo, tree);
}
static void init_iuup(void) {
if (circuits)
g_hash_table_destroy(circuits);
circuits = g_hash_table_new(g_direct_hash,g_direct_equal);
}
void proto_reg_handoff_iuup(void) {
static gboolean iuup_prefs_initialized = FALSE;
static dissector_handle_t iuup_handle;
static guint saved_dynamic_payload_type = 0;
if (!iuup_prefs_initialized) {
iuup_handle = find_dissector("iuup");
dissector_add_string("rtp_dyn_payload_type","VND.3GPP.IUFP", iuup_handle);
data_handle = find_dissector("data");
iuup_prefs_initialized = TRUE;
} else {
if ( saved_dynamic_payload_type > 95 ) {
dissector_delete_uint("rtp.pt", saved_dynamic_payload_type, iuup_handle);
}
}
saved_dynamic_payload_type = global_dynamic_payload_type;
if ( global_dynamic_payload_type > 95 ) {
dissector_add_uint("rtp.pt", global_dynamic_payload_type, iuup_handle);
}
}
void proto_register_iuup(void) {
static hf_register_info hf[] = {
{ &hf_iuup_direction, { "Frame Direction", "iuup.direction", FT_UINT16, BASE_DEC, NULL,0x8000,NULL,HFILL}},
{ &hf_iuup_circuit_id, { "Circuit ID", "iuup.circuit_id", FT_UINT16, BASE_DEC, NULL,0x7fff,NULL,HFILL}},
{ &hf_iuup_pdu_type, { "PDU Type", "iuup.pdu_type", FT_UINT8, BASE_DEC, VALS(iuup_pdu_types),0xf0,NULL,HFILL}},
{ &hf_iuup_frame_number, { "Frame Number", "iuup.framenum", FT_UINT8, BASE_DEC, NULL,0x0F,NULL,HFILL}},
{ &hf_iuup_fqc, { "FQC", "iuup.fqc", FT_UINT8, BASE_DEC, VALS(iuup_fqcs),0xc0,"Frame Quality Classification",HFILL}},
{ &hf_iuup_rfci, { "RFCI", "iuup.rfci", FT_UINT8, BASE_HEX, NULL, 0x3f, "RAB sub-Flow Combination Indicator",HFILL}},
{ &hf_iuup_hdr_crc, { "Header CRC", "iuup.header_crc", FT_UINT8, BASE_HEX, NULL,0xfc,NULL,HFILL}},
{ &hf_iuup_payload_crc, { "Payload CRC", "iuup.payload_crc", FT_UINT16, BASE_HEX, NULL,0x03FF,NULL,HFILL}},
{ &hf_iuup_ack_nack, { "Ack/Nack", "iuup.ack", FT_UINT8, BASE_DEC, VALS(iuup_acknack_vals),0x0c,NULL,HFILL}},
{ &hf_iuup_frame_number_t14, { "Frame Number", "iuup.framenum_t14", FT_UINT8, BASE_DEC, NULL,0x03,NULL,HFILL}},
{ &hf_iuup_mode_version, { "Mode Version", "iuup.mode", FT_UINT8, BASE_HEX, NULL,0xf0,NULL,HFILL}},
{ &hf_iuup_procedure_indicator, { "Procedure", "iuup.procedure", FT_UINT8, BASE_DEC, VALS(iuup_procedures),0x0f,NULL,HFILL}},
{ &hf_iuup_error_cause_val, { "Error Cause", "iuup.error_cause", FT_UINT8, BASE_DEC, VALS(iuup_error_causes),0xfc,NULL,HFILL}},
{ &hf_iuup_error_distance, { "Error DISTANCE", "iuup.error_distance", FT_UINT8, BASE_DEC, VALS(iuup_error_distances),0xc0,NULL,HFILL}},
{ &hf_iuup_errorevt_cause_val, { "Error Cause", "iuup.errorevt_cause", FT_UINT8, BASE_DEC, NULL,0x3f,NULL,HFILL}},
{ &hf_iuup_time_align, { "Time Align", "iuup.time_align", FT_UINT8, BASE_HEX, NULL,0x0,NULL,HFILL}},
{ &hf_iuup_data_pdu_type, { "RFCI Data Pdu Type", "iuup.data_pdu_type", FT_UINT8, BASE_HEX, VALS(iuup_payload_pdu_type),0xF0,NULL,HFILL}},
{ &hf_iuup_spare_03, { "Spare", "iuup.spare", FT_UINT8, BASE_HEX, NULL,0x03,NULL,HFILL}},
#if 0
{ &hf_iuup_spare_0f, { "Spare", "iuup.spare", FT_UINT8, BASE_HEX, NULL,0x0f,NULL,HFILL}},
#endif
#if 0
{ &hf_iuup_spare_c0, { "Spare", "iuup.spare", FT_UINT8, BASE_HEX, NULL,0xc0,NULL,HFILL}},
#endif
{ &hf_iuup_spare_e0, { "Spare", "iuup.spare", FT_UINT8, BASE_HEX, NULL,0xe0,NULL,HFILL}},
{ &hf_iuup_spare_ff, { "Spare", "iuup.spare", FT_UINT8, BASE_HEX, NULL,0xff,NULL,HFILL}},
{ &hf_iuup_spare_bytes, { "Spare", "iuup.spare_bytes", FT_BYTES, BASE_NONE, NULL,0x0,NULL,HFILL}},
{ &hf_iuup_delay, { "Delay", "iuup.delay", FT_UINT32, BASE_HEX, NULL,0x0,NULL,HFILL}},
{ &hf_iuup_advance, { "Advance", "iuup.advance", FT_UINT32, BASE_HEX, NULL,0x0,NULL,HFILL}},
{ &hf_iuup_delta, { "Delta Time", "iuup.delta", FT_FLOAT, BASE_NONE, NULL,0x0,NULL,HFILL}},
{ &hf_iuup_init_ti, { "TI", "iuup.ti", FT_UINT8, BASE_DEC, VALS(iuup_ti_vals),0x10,"Timing Information",HFILL}},
{ &hf_iuup_init_subflows_per_rfci, { "Subflows", "iuup.subflows", FT_UINT8, BASE_DEC, NULL,0x0e,"Number of Subflows",HFILL}},
{ &hf_iuup_init_chain_ind, { "Chain Indicator", "iuup.chain_ind", FT_UINT8, BASE_DEC, VALS(iuup_init_chain_ind_vals),0x01,NULL,HFILL}},
{ &hf_iuup_payload, { "Payload Data", "iuup.payload_data", FT_BYTES, BASE_NONE, NULL,0x00,NULL,HFILL}},
{ &hf_iuup_mode_versions, { "Iu UP Mode Versions Supported", "iuup.support_mode", FT_UINT16, BASE_HEX, NULL,0x0,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 0], { "Version 16", "iuup.support_mode.version16", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x8000,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 1], { "Version 15", "iuup.support_mode.version15", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x4000,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 2], { "Version 14", "iuup.support_mode.version14", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x2000,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 3], { "Version 13", "iuup.support_mode.version13", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x1000,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 4], { "Version 12", "iuup.support_mode.version12", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0800,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 5], { "Version 11", "iuup.support_mode.version11", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0400,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 6], { "Version 10", "iuup.support_mode.version10", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0200,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 7], { "Version 9", "iuup.support_mode.version9", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0100,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 8], { "Version 8", "iuup.support_mode.version8", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0080,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[ 9], { "Version 7", "iuup.support_mode.version7", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0040,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[10], { "Version 6", "iuup.support_mode.version6", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0020,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[11], { "Version 5", "iuup.support_mode.version5", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0010,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[12], { "Version 4", "iuup.support_mode.version4", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0008,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[13], { "Version 3", "iuup.support_mode.version3", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0004,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[14], { "Version 2", "iuup.support_mode.version2", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0002,NULL,HFILL}},
{ &hf_iuup_mode_versions_a[15], { "Version 1", "iuup.support_mode.version1", FT_UINT16, BASE_HEX, VALS(iuup_mode_version_support),0x0001,NULL,HFILL}},
{ &hf_iuup_num_rfci_ind, { "Number of RFCI Indicators", "iuup.p", FT_UINT8, BASE_HEX, NULL,0x3f,NULL,HFILL}},
{ &hf_iuup_init_rfci_ind, { "RFCI Initialization", "iuup.rfci.init", FT_BYTES, BASE_NONE, NULL,0x0,NULL,HFILL}},
HFS_RFCI(0),HFS_RFCI(1),HFS_RFCI(2),HFS_RFCI(3),HFS_RFCI(4),HFS_RFCI(5),HFS_RFCI(6),HFS_RFCI(7),
HFS_RFCI(8),HFS_RFCI(9),HFS_RFCI(10),HFS_RFCI(11),HFS_RFCI(12),HFS_RFCI(13),HFS_RFCI(14),HFS_RFCI(15),
HFS_RFCI(16),HFS_RFCI(17),HFS_RFCI(18),HFS_RFCI(19),HFS_RFCI(20),HFS_RFCI(21),HFS_RFCI(22),HFS_RFCI(23),
HFS_RFCI(24),HFS_RFCI(25),HFS_RFCI(26),HFS_RFCI(27),HFS_RFCI(28),HFS_RFCI(29),HFS_RFCI(30),HFS_RFCI(31),
HFS_RFCI(32),HFS_RFCI(33),HFS_RFCI(34),HFS_RFCI(35),HFS_RFCI(36),HFS_RFCI(37),HFS_RFCI(38),HFS_RFCI(39),
HFS_RFCI(40),HFS_RFCI(41),HFS_RFCI(42),HFS_RFCI(43),HFS_RFCI(44),HFS_RFCI(45),HFS_RFCI(46),HFS_RFCI(47),
HFS_RFCI(48),HFS_RFCI(49),HFS_RFCI(50),HFS_RFCI(51),HFS_RFCI(52),HFS_RFCI(53),HFS_RFCI(54),HFS_RFCI(55),
HFS_RFCI(56),HFS_RFCI(57),HFS_RFCI(58),HFS_RFCI(59),HFS_RFCI(60),HFS_RFCI(61),HFS_RFCI(62),HFS_RFCI(63)
};
gint* ett[] = {
&ett_iuup,
&ett_rfci,
&ett_ipti,
&ett_support,
&ett_time,
&ett_rfciinds,
&ett_payload,
&ett_payload_subflows
};
module_t* iuup_module;
proto_iuup = proto_register_protocol("IuUP", "IuUP", "iuup");
proto_register_field_array(proto_iuup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("iuup", dissect_iuup, proto_iuup);
register_dissector("find_iuup", find_iuup, proto_iuup);
register_init_routine(&init_iuup);
iuup_module = prefs_register_protocol(proto_iuup, proto_reg_handoff_iuup);
prefs_register_bool_preference(iuup_module, "dissect_payload",
"Dissect IuUP Payload bits",
"Whether IuUP Payload bits should be dissected",
&dissect_fields);
prefs_register_bool_preference(iuup_module, "two_byte_pseudoheader",
"Two byte pseudoheader",
"The payload contains a two byte pseudoheader indicating direction and circuit_id",
&two_byte_pseudoheader);
prefs_register_uint_preference(iuup_module, "dynamic.payload.type",
"IuUP dynamic payload type",
"The dynamic payload type which will be interpreted as IuUP",
10,
&global_dynamic_payload_type);
}
