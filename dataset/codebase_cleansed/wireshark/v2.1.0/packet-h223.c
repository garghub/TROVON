static gint
circuit_chain_equal(gconstpointer v, gconstpointer w)
{
const circuit_chain_key *v1 = (const circuit_chain_key *)v;
const circuit_chain_key *v2 = (const circuit_chain_key *)w;
gint result;
result = ( v1->call == v2->call &&
v1->vc == v2 -> vc );
return result;
}
static guint
circuit_chain_hash (gconstpointer v)
{
const circuit_chain_key *key = (const circuit_chain_key *)v;
guint hash_val = (GPOINTER_TO_UINT(key->call)) ^ (((guint32)key->vc) << 16);
return hash_val;
}
static guint32
circuit_chain_lookup(const h223_call_info* call_info, guint32 child_vc)
{
circuit_chain_key key, *new_key;
guint32 circuit_id;
key.call = call_info;
key.vc = child_vc;
circuit_id = GPOINTER_TO_UINT(g_hash_table_lookup( circuit_chain_hashtable, &key ));
if( circuit_id == 0 ) {
new_key = wmem_new(wmem_file_scope(), circuit_chain_key);
*new_key = key;
circuit_id = ++circuit_chain_count;
g_hash_table_insert(circuit_chain_hashtable, new_key, GUINT_TO_POINTER(circuit_id));
}
return circuit_id;
}
static void
circuit_chain_init(void)
{
circuit_chain_hashtable = g_hash_table_new(circuit_chain_hash, circuit_chain_equal);
circuit_chain_count = 1;
}
static void
circuit_chain_destroy(void)
{
g_hash_table_destroy(circuit_chain_hashtable);
}
static void
add_h223_mux_element(h223_call_direction_data *direct, guint8 mc, h223_mux_element *me, guint32 framenum)
{
h223_mux_element_listitem *li;
h223_mux_element_listitem **old_li_ptr;
h223_mux_element_listitem *old_li;
DISSECTOR_ASSERT(mc < 16);
li = wmem_new(wmem_file_scope(), h223_mux_element_listitem);
old_li_ptr = &(direct->mux_table[mc]);
old_li = *old_li_ptr;
if( !old_li ) {
direct->mux_table[mc] = li;
} else {
while( old_li->next ) {
old_li_ptr = &(old_li->next);
old_li = *old_li_ptr;
}
if( framenum < old_li->first_frame || (framenum == old_li->first_frame && pdu_offset < old_li->pdu_offset) )
return;
else if ( framenum == old_li->first_frame && pdu_offset == old_li->pdu_offset )
*old_li_ptr = li;
else
old_li->next = li;
}
li->first_frame = framenum;
li->pdu_offset = pdu_offset;
li->next = 0;
li->me = me;
}
static h223_mux_element*
find_h223_mux_element(h223_call_direction_data* direct, guint8 mc, guint32 framenum, guint32 pkt_offset)
{
h223_mux_element_listitem* li;
DISSECTOR_ASSERT(mc < 16);
li = direct->mux_table[mc];
while( li && li->next && li->next->first_frame < framenum )
li = li->next;
while( li && li->next && li->next->first_frame == framenum && li->next->pdu_offset < pkt_offset )
li = li->next;
if( li ) {
return li->me;
} else {
return NULL;
}
}
static void
add_h223_lc_params(h223_vc_info* vc_info, int direction, h223_lc_params *lc_params, guint32 framenum )
{
h223_lc_params_listitem *li = wmem_new(wmem_file_scope(), h223_lc_params_listitem);
h223_lc_params_listitem **old_li_ptr = &(vc_info->lc_params[direction ? 0 : 1]);
h223_lc_params_listitem *old_li = *old_li_ptr;
if( !old_li ) {
vc_info->lc_params[direction ? 0 : 1] = li;
} else {
while( old_li->next ) {
old_li_ptr = &(old_li->next);
old_li = *old_li_ptr;
}
if( framenum < old_li->first_frame )
return;
else if( framenum == old_li->first_frame )
*old_li_ptr = li;
else {
old_li->next = li;
old_li->last_frame = framenum - 1;
}
}
li->first_frame = framenum;
li->last_frame = 0;
li->next = 0;
li->lc_params = lc_params;
}
static h223_lc_params*
find_h223_lc_params(h223_vc_info* vc_info, int direction, guint32 framenum)
{
h223_lc_params_listitem* li = vc_info->lc_params[direction? 0 : 1];
while( li && li->next && li->next->first_frame <= framenum )
li = li->next;
if( li )
return li->lc_params;
else
return NULL;
}
static void
init_direction_data(h223_call_direction_data *direct)
{
int i;
h223_mux_element *mc0_element;
for ( i = 0; i < 16; ++i )
direct->mux_table[i] = NULL;
mc0_element = wmem_new(wmem_file_scope(), h223_mux_element);
add_h223_mux_element( direct, 0, mc0_element, 0 );
mc0_element->sublist = NULL;
mc0_element->vc = 0;
mc0_element->repeat_count = 0;
mc0_element->next = NULL;
}
static h223_vc_info*
h223_vc_info_new( h223_call_info* call_info )
{
h223_vc_info *vc_info = wmem_new(wmem_file_scope(), h223_vc_info);
vc_info->lc_params[0] = vc_info->lc_params[1] = NULL;
vc_info->call_info = call_info;
return vc_info;
}
static void
init_logical_channel( guint32 start_frame, h223_call_info* call_info, int vc, int direction, h223_lc_params* params )
{
guint32 circuit_id = circuit_chain_lookup(call_info, vc);
circuit_t *subcircuit;
h223_vc_info *vc_info;
subcircuit = find_circuit( CT_H223, circuit_id, start_frame );
if( subcircuit == NULL ) {
subcircuit = circuit_new( CT_H223, circuit_id, start_frame );
#ifdef DEBUG_H223
g_debug("%d: Created new circuit %d for call %p VC %d", start_frame, circuit_id, call_info, vc);
#endif
vc_info = h223_vc_info_new( call_info );
circuit_add_proto_data( subcircuit, proto_h223, vc_info );
} else {
vc_info = (h223_vc_info *)circuit_get_proto_data( subcircuit, proto_h223 );
}
add_h223_lc_params( vc_info, direction, params, start_frame );
}
static h223_call_info *
create_call_info( guint32 start_frame )
{
h223_call_info *datax;
h223_lc_params *vc0_params;
datax = wmem_new(wmem_file_scope(), h223_call_info);
init_direction_data(&datax -> direction_data[0]);
init_direction_data(&datax -> direction_data[1]);
datax -> h223_level = 2;
vc0_params = wmem_new(wmem_file_scope(), h223_lc_params);
vc0_params->al_type = al1Framed;
vc0_params->al_params = NULL;
vc0_params->segmentable = TRUE;
vc0_params->subdissector = srp_handle;
init_logical_channel( start_frame, datax, 0, P2P_DIR_SENT, vc0_params );
init_logical_channel( start_frame, datax, 0, P2P_DIR_RECV, vc0_params );
return datax;
}
static h223_call_info *
find_or_create_call_info_circ(packet_info * pinfo, circuit_type ctype, guint32 circuit_id)
{
h223_call_info *datax;
circuit_t *circ = NULL;
if(ctype != CT_NONE)
circ = find_circuit( ctype, circuit_id, pinfo->num );
if(circ == NULL)
return NULL;
datax = (h223_call_info *)circuit_get_proto_data(circ, proto_h223);
if( datax == NULL ) {
datax = create_call_info(pinfo->num);
#ifdef DEBUG_H223
g_debug("%u: Created new call %p for circuit %p ctype %d, id %u",
pinfo->num, datax, circ, type, circuit_id);
#endif
circuit_add_proto_data(circ, proto_h223, datax);
}
if( pinfo->p2p_dir < 0 || pinfo->p2p_dir > 1)
pinfo->p2p_dir = P2P_DIR_SENT;
return datax;
}
static h223_call_info *
find_or_create_call_info_conv(packet_info * pinfo)
{
h223_call_info *datax;
conversation_t *conv;
conv = find_conversation( pinfo->num,
&pinfo->src,&pinfo->dst,
pinfo->ptype,
pinfo->srcport,pinfo->destport, 0 );
DISSECTOR_ASSERT(conv);
datax = (h223_call_info *)conversation_get_proto_data(conv, proto_h223);
if(datax == NULL && pinfo->ptype == PT_UDP ) {
conversation_t *conv2;
conv2 = find_conversation( pinfo->num,
&pinfo->dst,&pinfo->src,
pinfo->ptype,
pinfo->destport,pinfo->srcport, 0 );
if(conv2 != NULL)
datax = (h223_call_info *)conversation_get_proto_data(conv2, proto_h223);
if(datax != NULL) {
#ifdef DEBUG_H223
g_debug("%u: Identified conv %p as reverse of conv %p with call %p and type=%u src=%u.%u.%u.%u:%u dst=%u.%u.%u.%u:%u",
pinfo->num, conv, conv2, datax, pinfo->ptype,
pinfo->dst.data[0], pinfo->dst.data[1], pinfo->dst.data[2], pinfo->dst.data[3],
pinfo->destport,
pinfo->src.data[0], pinfo->src.data[1], pinfo->src.data[2], pinfo->src.data[3],
pinfo->srcport);
#endif
conversation_add_proto_data(conv, proto_h223, datax);
}
}
if(datax == NULL) {
datax = create_call_info(pinfo->num);
#ifdef DEBUG_H223
g_debug("%u: Created new call %p for conv %p type=%u src=%u.%u.%u.%u:%u dst=%u.%u.%u.%u:%u",
pinfo->num, datax, conv, pinfo->ptype,
pinfo->src.data[0], pinfo->src.data[1], pinfo->src.data[2], pinfo->src.data[3],
pinfo->srcport,
pinfo->dst.data[0], pinfo->dst.data[1], pinfo->dst.data[2], pinfo->dst.data[3],
pinfo->destport);
#endif
conversation_add_proto_data(conv, proto_h223, datax);
copy_address(&(datax -> srcaddress), &(pinfo->src));
datax -> srcport = pinfo->srcport;
}
if( addresses_equal( &(pinfo->src), &(datax->srcaddress))
&& pinfo->srcport == datax->srcport )
pinfo->p2p_dir = P2P_DIR_SENT;
else
pinfo->p2p_dir = P2P_DIR_RECV;
return datax;
}
static h223_call_info *
find_or_create_call_info ( packet_info * pinfo, circuit_type ctype, guint32 circuit_id )
{
h223_call_info *datax;
datax = find_or_create_call_info_circ(pinfo, ctype, circuit_id);
if(datax == NULL)
datax = find_or_create_call_info_conv(pinfo);
return datax;
}
static void
h223_set_mc( packet_info* pinfo, guint8 mc, h223_mux_element* me, circuit_type ctype, guint32 circuit_id )
{
circuit_t *circ = find_circuit( ctype, circuit_id, pinfo->num );
h223_vc_info* vc_info;
if(circ) {
vc_info = (h223_vc_info *)circuit_get_proto_data(circ, proto_h223);
add_h223_mux_element( &(vc_info->call_info->direction_data[pinfo->p2p_dir ? 0 : 1]), mc, me, pinfo->num );
}
}
static void
h223_add_lc( packet_info* pinfo, guint16 lc, h223_lc_params* params, circuit_type ctype, guint32 circuit_id )
{
circuit_t *circ = find_circuit( ctype, circuit_id, pinfo->num );
h223_vc_info* vc_info;
if(circ) {
vc_info = (h223_vc_info *)circuit_get_proto_data(circ, proto_h223);
init_logical_channel( pinfo->num, vc_info->call_info, lc, pinfo->p2p_dir, params );
}
}
static guint8 h223_al2_crc8bit( tvbuff_t *tvb ) {
guint32 len = tvb_reported_length(tvb) - 1;
const guint8* datax = tvb_get_ptr( tvb, 0, len );
unsigned char crc = 0;
guint32 pos = 0;
DISSECTOR_ASSERT(tvb_reported_length(tvb) >= 1);
while ( len-- )
crc = crctable[crc^datax[pos++]];
return crc;
}
static void
dissect_mux_al_pdu( tvbuff_t *tvb, packet_info *pinfo, proto_tree *vc_tree,
h223_lc_params* lc_params )
{
proto_tree *al_tree = NULL;
proto_item *al_item, *hidden_item;
proto_tree *al_subtree;
proto_item *al_subitem = NULL;
proto_item *tmp_item;
tvbuff_t *next_tvb = NULL;
dissector_handle_t subdissector = lc_params->subdissector;
guint32 len = tvb_reported_length(tvb);
guint8 calc_checksum;
guint8 real_checksum;
gboolean al2_sequenced = FALSE;
int data_start;
switch( lc_params->al_type ) {
case al1Framed:
case al1NotFramed:
al_item = proto_tree_add_none_format(vc_tree, hf_h223_al1, tvb, 0, -1, "H.223 AL1 (%sframed)",
(lc_params->al_type==al1Framed)?"":"not ");
al_tree = proto_item_add_subtree (al_item, ett_h223_al1);
if(lc_params->al_type == al1Framed) {
hidden_item = proto_tree_add_boolean(al_tree, hf_h223_al1_framed, tvb, 0, 1, TRUE );
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
next_tvb = tvb;
al_subitem = proto_tree_add_item(al_tree, hf_h223_al_payload, next_tvb, 0, -1, ENC_NA);
break;
case al2WithSequenceNumbers:
al2_sequenced = TRUE;
case al2WithoutSequenceNumbers:
tmp_item = proto_tree_add_boolean(vc_tree, hf_h223_al2, tvb, 0, 0, TRUE );
al_item = proto_tree_add_item(vc_tree,
al2_sequenced?hf_h223_al2_sequenced:hf_h223_al2_unsequenced,
tvb, 0, -1, ENC_NA);
al_tree = proto_item_add_subtree (al_item, ett_h223_al2);
PROTO_ITEM_SET_GENERATED(tmp_item);
if(len < (al2_sequenced?2U:1U))
THROW(BoundsError);
data_start = 0;
if( al2_sequenced ) {
proto_tree_add_item(al_tree, hf_h223_al2_seqno, tvb, 0, 1, ENC_LITTLE_ENDIAN);
data_start++;
}
next_tvb = tvb_new_subset_length( tvb, data_start, len-1-data_start);
al_subitem = proto_tree_add_item(al_tree, hf_h223_al_payload, next_tvb, 0, -1, ENC_NA);
calc_checksum = h223_al2_crc8bit(tvb);
real_checksum = tvb_get_guint8(tvb, len - 1);
if( calc_checksum == real_checksum ) {
proto_tree_add_uint_format_value(al_tree, hf_h223_al2_crc, tvb, len - 1, 1, real_checksum,
"0x%02x (correct)", real_checksum );
} else {
proto_tree_add_uint_format_value(al_tree, hf_h223_al2_crc, tvb, len - 1, 1, real_checksum,
"0x%02x (incorrect, should be 0x%02x)", real_checksum, calc_checksum );
tmp_item = proto_tree_add_boolean( al_tree, hf_h223_al2_crc_bad, tvb, len - 1, 1, TRUE );
PROTO_ITEM_SET_GENERATED(tmp_item);
subdissector = data_handle;
}
break;
default:
call_dissector(data_handle, tvb, pinfo, vc_tree);
return;
}
if (!subdissector)
subdissector = data_handle;
al_subtree = proto_item_add_subtree(al_subitem, ett_h223_al_payload);
call_dissector(subdissector, next_tvb, pinfo, al_subtree);
}
static void
dissect_mux_sdu_fragment(tvbuff_t *volatile next_tvb, packet_info *pinfo,
guint32 pkt_offset, proto_tree *pdu_tree,
h223_call_info* call_info, guint16 vc,
gboolean end_of_mux_sdu, circuit_type orig_ctype, guint32 orig_circuit)
{
circuit_type ctype = CT_H223;
pinfo->circuit_id = circuit_chain_lookup(call_info, vc);
pinfo->ctype = ctype;
TRY {
guint32 circuit_id = pinfo->circuit_id;
circuit_t *subcircuit=find_circuit(ctype,circuit_id,pinfo->num);
proto_tree *vc_tree = NULL;
proto_item *vc_item;
h223_vc_info *vc_info = NULL;
h223_lc_params *lc_params = NULL;
if(pdu_tree) {
vc_item = proto_tree_add_uint(pdu_tree, hf_h223_mux_vc, next_tvb, 0, tvb_reported_length(next_tvb), vc);
vc_tree = proto_item_add_subtree (vc_item, ett_h223_mux_vc);
}
if( subcircuit == NULL ) {
g_message( "Frame %d: Subcircuit id %d not found for call %p VC %d", pinfo->num,
circuit_id, (void *)call_info, vc );
} else {
vc_info = (h223_vc_info *)circuit_get_proto_data(subcircuit, proto_h223);
if( vc_info != NULL ) {
lc_params = find_h223_lc_params( vc_info, pinfo->p2p_dir, pinfo->num );
}
}
if( lc_params != NULL ) {
if( lc_params->segmentable && lc_params->al_type != al1NotFramed ) {
stream_t *substream;
stream_pdu_fragment_t *frag;
substream = find_stream_circ(subcircuit,pinfo->p2p_dir);
if(substream == NULL )
substream = stream_new_circ(subcircuit,pinfo->p2p_dir);
frag = stream_find_frag(substream,pinfo->num,pkt_offset);
if(frag == NULL ) {
#ifdef DEBUG_H223
g_debug("%d: New H.223 VC fragment: Parent circuit %d; subcircuit %d; offset %d; len %d, end %d",
pinfo->num, orig_circuit, circuit_id, pkt_offset, tvb_reported_length(next_tvb), end_of_mux_sdu);
#endif
frag = stream_add_frag(substream,pinfo->num,pkt_offset,
next_tvb,pinfo,!end_of_mux_sdu);
} else {
#ifdef DEBUG_H223
g_debug("%d: Found H.223 VC fragment: Parent circuit %d; subcircuit %d; offset %d; len %d, end %d",
pinfo->num, orig_circuit, circuit_id, pkt_offset, tvb_reported_length(next_tvb), end_of_mux_sdu);
#endif
}
next_tvb = stream_process_reassembled(
next_tvb, 0, pinfo,
"Reassembled H.223 AL-PDU",
frag, &h223_al_frag_items,
NULL, vc_tree);
}
if(next_tvb) {
pdu_offset = pkt_offset;
dissect_mux_al_pdu(next_tvb, pinfo, vc_tree, lc_params );
}
} else {
call_dissector(data_handle,next_tvb,pinfo,vc_tree);
}
}
FINALLY {
pinfo->ctype=orig_ctype;
pinfo->circuit_id=orig_circuit;
}
ENDTRY;
}
static guint32
mux_element_sublist_size( h223_mux_element* me )
{
h223_mux_element *current_me = me->next;
guint32 length = 0;
while ( current_me ) {
if ( current_me->sublist )
length += current_me->repeat_count * mux_element_sublist_size( current_me->sublist );
else
length += current_me->repeat_count;
current_me = current_me->next;
}
DISSECTOR_ASSERT(length != 0);
return length;
}
static guint32
dissect_mux_payload_by_me_list( tvbuff_t *tvb, packet_info *pinfo,
guint32 pkt_offset, proto_tree *pdu_tree,
h223_call_info* call_info,
h223_mux_element *me, guint32 offset,
gboolean endOfMuxSdu, circuit_type ctype, guint32 circuit_id)
{
guint32 len = tvb_reported_length(tvb);
guint32 frag_len;
guint32 sublist_len;
int i;
while ( me ) {
if ( me->sublist ) {
if ( me->repeat_count == 0 ) {
for(sublist_len = mux_element_sublist_size( me->sublist );
offset + sublist_len <= len;
offset = dissect_mux_payload_by_me_list( tvb, pinfo, pkt_offset, pdu_tree,
call_info, me->sublist, offset, endOfMuxSdu,
ctype, circuit_id) );
} else {
for(i = 0; i < me->repeat_count; ++i)
offset = dissect_mux_payload_by_me_list( tvb, pinfo, pkt_offset, pdu_tree,
call_info, me->sublist, offset, endOfMuxSdu,
ctype, circuit_id);
}
} else {
if ( me->repeat_count == 0 )
frag_len = len - offset;
else
frag_len = me->repeat_count;
if(frag_len > 0) {
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_length(tvb, offset, frag_len);
dissect_mux_sdu_fragment( next_tvb, pinfo, pkt_offset + offset, pdu_tree,
call_info, me->vc, (offset+frag_len==len) && endOfMuxSdu,
ctype, circuit_id);
offset += frag_len;
}
}
me = me->next;
}
return offset;
}
static void
dissect_mux_payload( tvbuff_t *tvb, packet_info *pinfo, guint32 pkt_offset,
proto_tree *pdu_tree, h223_call_info *call_info,
guint8 mc, gboolean endOfMuxSdu, circuit_type ctype, guint32 circuit_id )
{
guint32 len = tvb_reported_length(tvb);
h223_mux_element* me = find_h223_mux_element( &(call_info->direction_data[pinfo->p2p_dir ? 0 : 1]), mc, pinfo->num, pkt_offset );
if( me ) {
dissect_mux_payload_by_me_list( tvb, pinfo, pkt_offset, pdu_tree, call_info, me, 0, endOfMuxSdu, ctype, circuit_id );
} else {
proto_tree *vc_tree = NULL;
if(pdu_tree) {
proto_item *vc_item = proto_tree_add_item(pdu_tree, hf_h223_mux_deact, tvb, 0, len, ENC_NA);
vc_tree = proto_item_add_subtree(vc_item, ett_h223_mux_deact);
}
call_dissector(data_handle,tvb,pinfo,vc_tree);
}
}
static void
dissect_mux_pdu( tvbuff_t *tvb, packet_info *pinfo, guint32 pkt_offset,
proto_tree *h223_tree, h223_call_info *call_info, circuit_type ctype, guint32 circuit_id)
{
guint32 offset = 0;
guint32 len;
guint32 raw_hdr = 0, correct_hdr = 0;
gint32 errors = 0;
guint16 closing_flag = 0;
guint8 mc = 0;
guint8 mpl = 0;
gboolean end_of_mux_sdu = FALSE;
tvbuff_t *pdu_tvb;
proto_item *pdu_item = NULL;
proto_tree *pdu_tree = NULL;
#ifdef DEBUG_H223_FRAGMENTATION
g_debug("%u: dissecting complete H.223 MUX-PDU, pkt_offset %u, len %u",
pinfo->num, pkt_offset, tvb_reported_length(tvb));
#endif
switch(call_info->h223_level) {
case 0: case 1:
raw_hdr = tvb_get_guint8(tvb,0);
mc = (guint8)((raw_hdr>>1) & 0xf);
end_of_mux_sdu = raw_hdr & 1;
offset++;
len = mpl = tvb_reported_length_remaining(tvb, offset)-(call_info->h223_level+1);
break;
case 2:
raw_hdr = tvb_get_letoh24(tvb,0);
errors = golay_errors(raw_hdr);
offset += 3;
len = tvb_reported_length_remaining(tvb,offset)-2;
if(errors != -1) {
correct_hdr = raw_hdr ^ (guint32)errors;
mc = (guint8)(correct_hdr & 0xf);
mpl = (guint8)((correct_hdr >> 4) & 0xff);
DISSECTOR_ASSERT(len >= mpl);
closing_flag = tvb_get_ntohs(tvb,offset+len);
end_of_mux_sdu = (closing_flag==(0xE14D ^ 0xFFFF));
} else {
mc = 0;
mpl = len;
}
break;
case 3:
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if( h223_tree ) {
if( mpl == 0 ) {
pdu_item = proto_tree_add_item (h223_tree, hf_h223_mux_stuffing_pdu, tvb, 0, -1, ENC_NA);
pdu_tree = proto_item_add_subtree (pdu_item, ett_h223_mux_stuffing_pdu);
} else {
pdu_item = proto_tree_add_item (h223_tree, hf_h223_mux_pdu, tvb, 0, -1, ENC_NA);
pdu_tree = proto_item_add_subtree (pdu_item, ett_h223_mux_pdu);
}
}
if( pdu_tree ) {
proto_item *item = proto_tree_add_item (pdu_tree, hf_h223_mux_header, tvb, 0, offset, ENC_NA);
proto_tree *hdr_tree = proto_item_add_subtree (item, ett_h223_mux_header);
switch(call_info->h223_level) {
case 0: case 1:
proto_tree_add_uint(hdr_tree,hf_h223_mux_mc,tvb,0,1,mc);
break;
case 2:
if( errors == -1 ) {
proto_tree_add_uint_format_value(hdr_tree, hf_h223_mux_rawhdr, tvb,
0, 3, raw_hdr,
"0x%06x (uncorrectable errors)", raw_hdr );
} else {
if( errors == 0 ) {
proto_tree_add_uint_format_value(hdr_tree, hf_h223_mux_rawhdr, tvb,
0, 3, raw_hdr,
"0x%06x (correct)", raw_hdr );
} else {
proto_tree_add_uint_format_value(hdr_tree, hf_h223_mux_rawhdr, tvb,
0, 3, raw_hdr,
"0x%06x (errors are 0x%06x)", raw_hdr, errors );
}
item = proto_tree_add_uint(hdr_tree,hf_h223_mux_correctedhdr,tvb,0,3,
correct_hdr);
PROTO_ITEM_SET_GENERATED(item);
proto_tree_add_uint(hdr_tree,hf_h223_mux_mc,tvb,0,1,mc);
proto_tree_add_uint(hdr_tree,hf_h223_mux_mpl,tvb,0,2,mpl);
}
break;
case 3:
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
}
if(mpl > 0) {
pdu_tvb = tvb_new_subset(tvb, offset, len, mpl);
if(errors != -1) {
dissect_mux_payload(pdu_tvb,pinfo,pkt_offset+offset,pdu_tree,call_info,mc,end_of_mux_sdu, ctype, circuit_id);
} else {
call_dissector(data_handle,pdu_tvb,pinfo,pdu_tree);
}
offset += mpl;
}
len -= mpl;
if( len > 0 ) {
tvbuff_t *next_tvb = tvb_new_subset_length(tvb, offset, len);
proto_tree *vc_tree = NULL;
if( pdu_tree ) {
proto_item *vc_item = proto_tree_add_item(pdu_tree, hf_h223_mux_extra, next_tvb, 0, len, ENC_NA);
vc_tree = proto_item_add_subtree(vc_item, ett_h223_mux_deact);
}
call_dissector(data_handle,next_tvb,pinfo,vc_tree);
offset += len;
}
if( pdu_tree )
proto_tree_add_item(pdu_tree,hf_h223_mux_hdlc2,tvb,offset,2,ENC_BIG_ENDIAN);
}
static gboolean
attempt_mux_level0_header_parse(guint32 nbytes _U_, guint32 hdr _U_, guint32 *minlen _U_)
{
DISSECTOR_ASSERT_NOT_REACHED();
return FALSE;
}
static gboolean
attempt_mux_level1_header_parse(guint32 nbytes, guint32 hdr, guint32 *minlen )
{
if(nbytes < 2)
return FALSE;
hdr &= 0xffff;
if(hdr == 0xE14D)
return FALSE;
*minlen = (guint8)((hdr >> 12) & 0xff) + 3;
return TRUE;
}
static gboolean
attempt_mux_level2_3_header_parse(guint32 nbytes, guint32 hdr, guint32 *minlen)
{
gint32 errors;
if(nbytes < 3)
return FALSE;
*minlen = 5;
hdr =
((hdr & 0xFF0000) >> 16) |
(hdr & 0x00FF00) |
((hdr & 0x0000FF) << 16);
errors = golay_errors(hdr);
if(errors != -1) {
hdr ^= errors;
*minlen += ((hdr >> 4) & 0xff);
}
return TRUE;
}
static gboolean
h223_mux_check_hdlc(int h223_level, guint32 nbytes, guint32 tail_buf)
{
guint32 masked;
switch(h223_level) {
case 0:
DISSECTOR_ASSERT_NOT_REACHED();
return FALSE;
case 1:
masked = tail_buf & 0xffff;
return nbytes >= 2 && masked == 0xE14D;
case 2: case 3:
masked = tail_buf & 0xffff;
return nbytes >= 2 && (masked == 0xE14D || masked == (0xE14D ^ 0xFFFF));
default:
DISSECTOR_ASSERT_NOT_REACHED();
return FALSE;
}
}
static gint
dissect_mux_pdu_fragment( tvbuff_t *tvb, guint32 start_offset,
packet_info *pinfo, proto_tree *h223_tree,
h223_call_info *call_info, circuit_type ctype, guint32 circuit_id)
{
tvbuff_t *volatile next_tvb;
volatile guint32 offset = start_offset;
gboolean more_frags = TRUE;
gboolean header_parsed = FALSE;
guint32 header_buf = 0, tail_buf = 0;
guint32 pdu_minlen = 0;
#ifdef DEBUG_H223_FRAGMENTATION
g_debug("%d: dissecting H.223 PDU, start_offset %u, %u bytes left",
pinfo->num,start_offset, tvb_reported_length_remaining( tvb, start_offset ));
#endif
while( more_frags && offset < tvb_reported_length( tvb )) {
guint8 byte = tvb_get_guint8(tvb, offset++);
if((offset-start_offset) <= 4) {
header_buf <<= 8;
header_buf |= byte;
}
tail_buf <<= 8;
tail_buf |= byte;
if(!header_parsed)
header_parsed = (attempt_mux_header_parse[call_info->h223_level])
(offset-start_offset,header_buf,&pdu_minlen);
if(header_parsed && (offset-start_offset) >= pdu_minlen) {
if(h223_mux_check_hdlc(call_info->h223_level,offset-start_offset,tail_buf)) {
more_frags = FALSE;
}
}
}
if( more_frags ) {
if(pdu_minlen <= (offset-start_offset)) {
#ifdef DEBUG_H223_FRAGMENTATION
g_debug("\tBailing, requesting more bytes");
#endif
return 0;
} else {
guint32 needed = pdu_minlen-(offset-start_offset);
#ifdef DEBUG_H223_FRAGMENTATION
g_debug("\tBailing, requesting %i-%i=%u more bytes", pdu_minlen,(offset-start_offset),needed);
#endif
return - (gint) needed;
}
}
next_tvb = tvb_new_subset_length(tvb, start_offset, offset-start_offset);
TRY {
dissect_mux_pdu( next_tvb, pinfo, start_offset, h223_tree, call_info, ctype, circuit_id);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, h223_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
return (offset-start_offset);
}
static void
dissect_h223_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, circuit_type ctype, guint32 circuit_id)
{
proto_tree *h223_tree = NULL;
proto_item *h223_item = NULL;
h223_call_info *call_info = NULL;
guint32 offset = 0;
col_set_str (pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_H223);
col_clear(pinfo->cinfo, COL_INFO);
call_info = find_or_create_call_info(pinfo, ctype, circuit_id);
if (tree) {
h223_item = proto_tree_add_item (tree, proto_h223, tvb, 0, -1, ENC_NA);
h223_tree = proto_item_add_subtree (h223_item, ett_h223);
}
while( offset < tvb_reported_length( tvb )) {
int res = dissect_mux_pdu_fragment( tvb, offset, pinfo,
h223_tree, call_info, ctype, circuit_id);
if(res <= 0) {
pinfo->desegment_offset = offset;
pinfo -> desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
if(h223_item) {
proto_item_set_len(h223_item,offset);
}
if(offset == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "(No complete PDUs)");
}
return;
}
offset += res;
}
}
static int
dissect_h223_circuit_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
iax2_dissector_info_t circuit_info;
if (data != NULL)
{
circuit_info = *((iax2_dissector_info_t*)data);
}
else
{
circuit_info.ctype = (circuit_type)pinfo->ctype;
circuit_info.circuit_id = pinfo->circuit_id;
}
dissect_h223_common(tvb, pinfo, tree, circuit_info.ctype, circuit_info.circuit_id);
return tvb_captured_length(tvb);
}
static int
dissect_h223(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_h223_common(tvb, pinfo, tree, CT_NONE, 0);
return tvb_captured_length(tvb);
}
static void
dissect_h223_bitswapped_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, circuit_type ctype, guint32 circuit_id)
{
tvbuff_t *reversed_tvb;
guint8 *datax;
guint len;
len = tvb_reported_length(tvb);
datax = (guint8 *) tvb_memdup(pinfo->pool, tvb, 0, len);
bitswap_buf_inplace(datax, len);
reversed_tvb = tvb_new_child_real_data(tvb, datax,len,tvb_reported_length(tvb));
add_new_data_source(pinfo, reversed_tvb, "Bit-swapped H.223 frame" );
dissect_h223_common(reversed_tvb,pinfo,tree,ctype,circuit_id);
}
static int
dissect_h223_bitswapped_circuit_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
iax2_dissector_info_t circuit_info;
if (data != NULL)
{
circuit_info = *((iax2_dissector_info_t*)data);
}
else
{
circuit_info.ctype = (circuit_type)pinfo->ctype;
circuit_info.circuit_id = pinfo->circuit_id;
}
dissect_h223_bitswapped_common(tvb, pinfo, tree, circuit_info.ctype, circuit_info.circuit_id);
return tvb_captured_length(tvb);
}
static int
dissect_h223_bitswapped(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_h223_bitswapped_common(tvb, pinfo, tree, CT_NONE, 0);
return tvb_captured_length(tvb);
}
void proto_register_h223 (void)
{
static hf_register_info hf[] = {
#if 0
{ &hf_h223_non_h223_data,
{ "Non-H.223 data", "h223.non-h223", FT_NONE, BASE_NONE, NULL, 0x0,
"Initial data in stream, not a PDU", HFILL }},
#endif
{ &hf_h223_mux_stuffing_pdu,
{ "H.223 stuffing PDU", "h223.mux.stuffing", FT_NONE, BASE_NONE, NULL, 0x0,
"Empty PDU used for stuffing when no data available", HFILL }},
{ &hf_h223_mux_pdu,
{ "H.223 MUX-PDU", "h223.mux", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_mux_header,
{ "Header", "h223.mux.header", FT_NONE, BASE_NONE, NULL, 0x0,
"H.223 MUX header", HFILL }},
{ &hf_h223_mux_rawhdr,
{ "Raw value", "h223.mux.rawhdr", FT_UINT24, BASE_HEX, NULL, 0x0,
"Raw header bytes", HFILL }},
{ &hf_h223_mux_correctedhdr,
{ "Corrected value", "h223.mux.correctedhdr", FT_UINT24, BASE_HEX, NULL, 0x0,
"Corrected header bytes", HFILL }},
{ &hf_h223_mux_mc,
{ "Multiplex Code", "h223.mux.mc", FT_UINT8, BASE_DEC, NULL, 0x0,
"H.223 MUX multiplex code", HFILL }},
{ &hf_h223_mux_mpl,
{ "Multiplex Payload Length", "h223.mux.mpl", FT_UINT8, BASE_DEC, NULL, 0x0,
"H.223 MUX multiplex Payload Length", HFILL }},
{ &hf_h223_mux_deact,
{ "Deactivated multiplex table entry", "h223.mux.deactivated", FT_NONE, BASE_NONE, NULL, 0x0,
"mpl refers to an entry in the multiplex table which is not active", HFILL }},
{ &hf_h223_mux_vc,
{ "H.223 virtual circuit", "h223.mux.vc", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_mux_extra,
{ "Extraneous data", "h223.mux.extra", FT_NONE, BASE_NONE, NULL, 0x0,
"data beyond mpl", HFILL }},
{ &hf_h223_mux_hdlc2,
{ "HDLC flag", "h223.mux.hdlc", FT_UINT16, BASE_HEX, NULL, 0x0,
"framing flag", HFILL }},
{ &hf_h223_mux_fragment_overlap,
{ "Fragment overlap", "h223.mux.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_h223_mux_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "h223.mux.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_h223_mux_fragment_multiple_tails,
{ "Multiple tail fragments found", "h223.mux.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_h223_mux_fragment_too_long_fragment,
{ "Fragment too long", "h223.mux.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_h223_mux_fragment_error,
{ "Defragmentation error", "h223.mux.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_h223_mux_fragment_count,
{ "Fragment count", "h223.mux.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_mux_fragment,
{ "H.223 MUX-PDU Fragment", "h223.mux.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_mux_fragments,
{ "H.223 MUX-PDU Fragments", "h223.mux.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_mux_reassembled_in,
{ "MUX-PDU fragment, reassembled in frame", "h223.mux.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This H.223 MUX-PDU packet is reassembled in this frame", HFILL }},
{ &hf_h223_mux_reassembled_length,
{ "Reassembled H.223 MUX-PDU length", "h223.mux.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_h223_al_fragment_overlap,
{ "Fragment overlap", "h223.al.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_h223_al_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "h223.al.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_h223_al_fragment_multiple_tails,
{ "Multiple tail fragments found", "h223.al.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_h223_al_fragment_too_long_fragment,
{ "Fragment too long", "h223.al.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_h223_al_fragment_error,
{ "Defragmentation error", "h223.al.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_h223_al_fragment_count,
{ "Fragment count", "h223.al.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_al_fragment,
{ "H.223 AL-PDU Fragment", "h223.al.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_al_fragments,
{ "H.223 AL-PDU Fragments", "h223.al.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_al_reassembled_in,
{ "AL-PDU fragment, reassembled in frame", "h223.al.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This H.223 AL-PDU packet is reassembled in this frame", HFILL }},
{ &hf_h223_al_reassembled_length,
{ "Reassembled H.223 AL-PDU length", "h223.al.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_h223_al1,
{ "H.223 AL1", "h223.al1", FT_NONE, BASE_NONE, NULL, 0x0,
"H.223 AL-PDU using AL1", HFILL }},
{ &hf_h223_al1_framed,
{ "H.223 AL1 framing", "h223.al1.framed", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_al2,
{ "H.223 AL2", "h223.al2", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"H.223 AL-PDU using AL2", HFILL }},
{ &hf_h223_al2_sequenced,
{ "H.223 sequenced AL2", "h223.sequenced_al2", FT_NONE, BASE_NONE, NULL, 0x0,
"H.223 AL-PDU using AL2 with sequence numbers", HFILL }},
{ &hf_h223_al2_unsequenced,
{ "H.223 unsequenced AL2", "h223.unsequenced_al2", FT_NONE, BASE_NONE, NULL, 0x0,
"H.223 AL-PDU using AL2 without sequence numbers", HFILL }},
{ &hf_h223_al2_seqno,
{ "Sequence Number", "h223.al2.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
"H.223 AL2 sequence number", HFILL }},
{ &hf_h223_al2_crc,
{ "CRC", "h223.al2.crc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_al2_crc_bad,
{ "Bad CRC","h223.al2.crc_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_h223_al_payload,
{ "H.223 AL Payload", "h223.al.payload", FT_NONE, BASE_NONE, NULL, 0x0,
"H.223 AL-PDU Payload", HFILL }},
};
static gint *ett[] = {
&ett_h223,
&ett_h223_non_h223_data,
&ett_h223_mux_stuffing_pdu,
&ett_h223_mux_pdu,
&ett_h223_mux_header,
&ett_h223_mux_deact,
&ett_h223_mux_vc,
&ett_h223_mux_extra,
&ett_h223_mux_fragments,
&ett_h223_mux_fragment,
&ett_h223_al_fragments,
&ett_h223_al_fragment,
&ett_h223_al1,
&ett_h223_al2,
&ett_h223_al_payload
};
proto_h223 =
proto_register_protocol ("ITU-T Recommendation H.223", "H.223", "h223");
proto_h223_bitswapped =
proto_register_protocol ("ITU-T Recommendation H.223 (Bitswapped)", "H.223 (Bitswapped)", "h223_bitswapped");
proto_register_field_array (proto_h223, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("h223", dissect_h223_circuit_data, proto_h223);
register_dissector("h223_bitswapped", dissect_h223_bitswapped, proto_h223_bitswapped);
register_init_routine(&circuit_chain_init);
register_cleanup_routine(&circuit_chain_destroy);
h245_set_h223_set_mc_handle( &h223_set_mc );
h245_set_h223_add_lc_handle( &h223_add_lc );
}
void proto_reg_handoff_h223(void)
{
dissector_handle_t h223_bitswapped = find_dissector("h223_bitswapped");
data_handle = find_dissector("data");
srp_handle = find_dissector("srp");
dissector_add_for_decode_as("tcp.port", create_dissector_handle( dissect_h223, proto_h223));
dissector_add_for_decode_as("tcp.port", h223_bitswapped);
dissector_add_string("rtp_dyn_payload_type","CLEARMODE", h223_bitswapped);
dissector_add_uint("iax2.dataformat", AST_DATAFORMAT_H223_H245, create_dissector_handle(dissect_h223_bitswapped_circuit_data, proto_h223_bitswapped));
}
