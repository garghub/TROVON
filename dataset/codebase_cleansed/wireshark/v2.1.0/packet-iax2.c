static gchar *key_to_str( const iax_circuit_key *key )
{
static int i = 0;
static gchar str[3][80];
gchar *strp;
gchar *addrstr;
i++;
if (i >= 3) {
i = 0;
}
strp = str[i];
addrstr = address_to_str(NULL, &key->addr)
g_snprintf(strp, 80, "{%s:%i,%i}",
addrstr,
key->port,
key->callno);
wmem_free(NULL, addrstr);
return strp;
}
static gint iax_circuit_equal(gconstpointer v, gconstpointer w)
{
const iax_circuit_key *v1 = (const iax_circuit_key *)v;
const iax_circuit_key *v2 = (const iax_circuit_key *)w;
gint result;
result = (addresses_equal(&(v1->addr), &(v2->addr)) &&
v1->ptype == v2->ptype &&
v1->port == v2->port &&
v1->callno== v2->callno);
#ifdef DEBUG_HASHING
g_debug("+++ Comparing for equality: %s, %s: %u", key_to_str(v1), key_to_str(v2), result);
#endif
return result;
}
static guint iax_circuit_hash(gconstpointer v)
{
const iax_circuit_key *key = (const iax_circuit_key *)v;
guint hash_val;
hash_val = 0;
hash_val = add_address_to_hash(hash_val, &key->addr);
hash_val += (guint)(key->ptype);
hash_val += (guint)(key->port);
hash_val += (guint)(key->callno);
#ifdef DEBUG_HASHING
g_debug("+++ Hashing key: %s, result %#x", key_to_str(key), hash_val);
#endif
return (guint)hash_val;
}
static guint iax_circuit_lookup(const address *address_p,
port_type ptype,
guint32 port,
guint32 callno)
{
iax_circuit_key key;
guint32 *circuit_id_p;
key.addr = *address_p;
key.ptype = ptype;
key.port = port;
key.callno = callno;
circuit_id_p = (guint32 *)g_hash_table_lookup(iax_circuit_hashtab, &key);
if (! circuit_id_p) {
iax_circuit_key *new_key;
new_key = wmem_new(wmem_file_scope(), iax_circuit_key);
new_key->addr.type = address_p->type;
new_key->addr.len = MIN(address_p->len, MAX_ADDRESS);
new_key->addr.data = new_key->address_data;
memcpy(new_key->address_data, address_p->data, new_key->addr.len);
new_key->ptype = ptype;
new_key->port = port;
new_key->callno = callno;
circuit_id_p = (guint32 *)wmem_new(wmem_file_scope(), iax_circuit_key);
*circuit_id_p = ++circuitcount;
g_hash_table_insert(iax_circuit_hashtab, new_key, circuit_id_p);
#ifdef DEBUG_HASHING
g_debug("Created new circuit id %u for node %s", *circuit_id_p, key_to_str(new_key));
#endif
}
return *circuit_id_p;
}
static circuit_t *iax2_new_circuit_for_call(packet_info *pinfo, proto_item * item,
guint circuit_id, guint framenum,
iax_call_data *iax_call, gboolean reversed)
{
circuit_t *res;
if(!iax_call){
return NULL;
}
if ((reversed && iax_call->n_reverse_circuit_ids >= IAX_MAX_TRANSFERS) ||
(! reversed && iax_call->n_forward_circuit_ids >= IAX_MAX_TRANSFERS)) {
expert_add_info(pinfo, item, &ei_iax_too_many_transfers);
return NULL;
}
res = circuit_new(CT_IAX2,
circuit_id,
framenum);
circuit_add_proto_data(res, proto_iax2, iax_call);
if (reversed)
iax_call -> reverse_circuit_ids[iax_call->n_reverse_circuit_ids++] = circuit_id;
else
iax_call -> forward_circuit_ids[iax_call->n_forward_circuit_ids++] = circuit_id;
return res;
}
static gboolean is_forward_circuit(guint circuit_id,
const iax_call_data *iax_call)
{
guint i;
for(i=0; i<iax_call->n_forward_circuit_ids; i++) {
if (circuit_id == iax_call->forward_circuit_ids[i])
return TRUE;
}
return FALSE;
}
static gboolean is_reverse_circuit(guint circuit_id,
const iax_call_data *iax_call)
{
guint i;
for(i=0; i<iax_call->n_reverse_circuit_ids; i++){
if (circuit_id == iax_call->reverse_circuit_ids[i])
return TRUE;
}
return FALSE;
}
static iax_call_data *iax_lookup_call_from_dest(packet_info *pinfo, proto_item * item,
guint src_circuit_id,
guint dst_circuit_id,
guint framenum,
gboolean *reversed_p)
{
circuit_t *dst_circuit;
iax_call_data *iax_call;
gboolean reversed = FALSE;
dst_circuit = find_circuit(CT_IAX2,
dst_circuit_id,
framenum);
if (!dst_circuit) {
#ifdef DEBUG_HASHING
g_debug("++ destination circuit not found, must have missed NEW packet");
#endif
if (reversed_p)
*reversed_p = FALSE;
return NULL;
}
#ifdef DEBUG_HASHING
g_debug("++ found destination circuit");
#endif
iax_call = (iax_call_data *)circuit_get_proto_data(dst_circuit, proto_iax2);
DISSECTOR_ASSERT(iax_call);
if (is_forward_circuit(dst_circuit_id, iax_call)) {
#ifdef DEBUG_HASHING
g_debug("++ destination circuit matches forward_circuit_id of call, "
"therefore packet is reversed");
#endif
reversed = TRUE;
if (iax_call -> n_reverse_circuit_ids == 0) {
#ifdef DEBUG_HASHING
g_debug("++ reverse_circuit_id of call is zero, need to create a "
"new reverse circuit for this call");
#endif
iax2_new_circuit_for_call(pinfo, item, src_circuit_id, framenum, iax_call, TRUE);
#ifdef DEBUG_HASHING
g_debug("++ done");
#endif
} else if (!is_reverse_circuit(src_circuit_id, iax_call)) {
expert_add_info_format(pinfo, item, &ei_iax_circuit_id_conflict,
"IAX Packet %u from circuit ids %u->%u conflicts with earlier call with circuit ids %u->%u",
framenum,
src_circuit_id, dst_circuit_id,
iax_call->forward_circuit_ids[0],
iax_call->reverse_circuit_ids[0]);
return NULL;
}
} else if (is_reverse_circuit(dst_circuit_id, iax_call)) {
#ifdef DEBUG_HASHING
g_debug("++ destination circuit matches reverse_circuit_id of call, "
"therefore packet is forward");
#endif
reversed = FALSE;
if (!is_forward_circuit(src_circuit_id, iax_call)) {
expert_add_info_format(pinfo, item, &ei_iax_circuit_id_conflict,
"IAX Packet %u from circuit ids %u->%u conflicts with earlier call with circuit ids %u->%u",
framenum,
src_circuit_id, dst_circuit_id,
iax_call->forward_circuit_ids[0],
iax_call->reverse_circuit_ids[0]);
if (reversed_p)
*reversed_p = FALSE;
return NULL;
}
} else {
DISSECTOR_ASSERT_NOT_REACHED();
}
if (reversed_p)
*reversed_p = reversed;
return iax_call;
}
static iax_call_data *iax_lookup_call( packet_info *pinfo,
guint32 scallno,
guint32 dcallno,
gboolean *reversed_p)
{
gboolean reversed = FALSE;
iax_call_data *iax_call = NULL;
guint src_circuit_id;
#ifdef DEBUG_HASHING
gchar *srcstr, *dststr;
#endif
#ifdef DEBUG_HASHING
srcstr = address_to_str(NULL, &pinfo->src);
dststr = address_to_str(NULL, &pinfo->dst);
g_debug("++ iax_lookup_circuit_details: Looking up circuit for frame %u, "
"from {%s:%u:%u} to {%s:%u:%u}", pinfo->num,
srcstr, pinfo->srcport, scallno,
dststr, pinfo->destport, dcallno);
wmem_free(NULL, srcstr);
wmem_free(NULL, dststr);
#endif
src_circuit_id = iax_circuit_lookup(&pinfo->src, pinfo->ptype,
pinfo->srcport, scallno);
if (dcallno != 0) {
guint dst_circuit_id;
#ifdef DEBUG_HASHING
g_debug("++ dcallno non-zero, looking up destination circuit");
#endif
dst_circuit_id = iax_circuit_lookup(&pinfo->dst, pinfo->ptype,
pinfo->destport, dcallno);
iax_call = iax_lookup_call_from_dest(pinfo, NULL, src_circuit_id, dst_circuit_id,
pinfo->num, &reversed);
} else {
circuit_t *src_circuit;
src_circuit = find_circuit(CT_IAX2,
src_circuit_id,
pinfo->num);
if (src_circuit) {
iax_call = (iax_call_data *)circuit_get_proto_data(src_circuit, proto_iax2);
DISSECTOR_ASSERT(iax_call);
if (is_forward_circuit(src_circuit_id, iax_call))
reversed = FALSE;
else if (is_reverse_circuit(src_circuit_id, iax_call))
reversed = TRUE;
else {
DISSECTOR_ASSERT_NOT_REACHED();
}
}
}
if (reversed_p)
*reversed_p = reversed;
#ifdef DEBUG_HASHING
if (iax_call) {
g_debug("++ Found call for packet: id %u, reversed=%c", iax_call->forward_circuit_ids[0], reversed?'1':'0');
} else {
g_debug("++ Call not found. Must have missed the NEW packet?");
}
#endif
return iax_call;
}
static void init_dir_data(iax_call_dirdata *dirdata)
{
dirdata -> current_frag_bytes=0;
dirdata -> current_frag_minlen=0;
}
static iax_call_data *iax_new_call( packet_info *pinfo,
guint32 scallno)
{
iax_call_data *call;
guint circuit_id;
static const nstime_t millisecond = {0, 1000000};
#ifdef DEBUG_HASHING
g_debug("+ new_circuit: Handling NEW packet, frame %u", pinfo->num);
#endif
circuit_id = iax_circuit_lookup(&pinfo->src, pinfo->ptype,
pinfo->srcport, scallno);
call = wmem_new(wmem_file_scope(), iax_call_data);
call -> dataformat = AST_DATAFORMAT_NULL;
call -> src_codec = 0;
call -> dst_codec = 0;
call -> n_forward_circuit_ids = 0;
call -> n_reverse_circuit_ids = 0;
call -> subdissector = NULL;
call -> start_time = pinfo->abs_ts;
nstime_delta(&call -> start_time, &call -> start_time, &millisecond);
init_dir_data(&call->dirdata[0]);
init_dir_data(&call->dirdata[1]);
iax2_new_circuit_for_call(pinfo, NULL, circuit_id, pinfo->num, call, FALSE);
return call;
}
static iax_packet_data *iax_new_packet_data(iax_call_data *call, gboolean reversed)
{
iax_packet_data *p = wmem_new(wmem_file_scope(), iax_packet_data);
p->first_time = TRUE;
p->call_data = call;
p->codec = 0;
p->reversed = reversed;
p->abstime.secs = -1;
p->abstime.nsecs = -1;
return p;
}
static void iax2_populate_pinfo_from_packet_data(packet_info *pinfo, const iax_packet_data *p)
{
if (p->call_data != NULL) {
pinfo->p2p_dir = p->reversed?P2P_DIR_RECV:P2P_DIR_SENT;
col_set_str(pinfo->cinfo, COL_IF_DIR, p->reversed ? "rev" : "fwd");
}
}
static int
dissect_iax2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *iax2_item;
proto_tree *iax2_tree;
proto_tree *full_mini_subtree = NULL;
guint32 offset = 0, len;
guint16 scallno = 0;
guint16 stmp;
packet_type type;
proto_item *full_mini_base;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_IAX2);
col_clear(pinfo->cinfo, COL_INFO);
iax2_item = proto_tree_add_item(tree, proto_iax2, tvb, offset, -1, ENC_NA);
iax2_tree = proto_item_add_subtree(iax2_item, ett_iax2);
stmp = tvb_get_ntohs(tvb, offset);
if (stmp == 0) {
offset+=2;
stmp = tvb_get_ntohs(tvb, offset);
if (stmp & 0x8000) {
type = IAX2_MINI_VIDEO_PACKET;
scallno = stmp & 0x7FFF;
offset += 2;
}
else {
type = IAX2_TRUNK_PACKET;
}
} else {
scallno = tvb_get_ntohs(tvb, offset);
offset += 2;
if (scallno & 0x8000)
type = IAX2_FULL_PACKET;
else {
type = IAX2_MINI_VOICE_PACKET;
}
scallno &= 0x7FFF;
}
full_mini_base = proto_tree_add_uint(iax2_tree, hf_iax2_packet_type, tvb, 0, offset, type);
full_mini_subtree = proto_item_add_subtree(full_mini_base, ett_iax2_full_mini_subtree);
if (scallno != 0)
proto_tree_add_item(full_mini_subtree, hf_iax2_scallno, tvb, offset-2, 2, ENC_BIG_ENDIAN);
iax2_info->ptype = type;
iax2_info->scallno = 0;
iax2_info->dcallno = 0;
iax2_info->ftype = 0;
iax2_info->csub = 0;
iax2_info->payload_len = 0;
iax2_info->timestamp = 0;
iax2_info->callState = VOIP_NO_STATE;
iax2_info->messageName = NULL;
iax2_info->callingParty = NULL;
iax2_info->calledParty = NULL;
iax2_info->payload_data = NULL;
switch (type) {
case IAX2_FULL_PACKET:
len = dissect_fullpacket(tvb, offset, scallno, pinfo, full_mini_subtree, tree);
break;
case IAX2_MINI_VOICE_PACKET:
iax2_info->messageName = "MINI_VOICE_PACKET";
len = dissect_minipacket(tvb, offset, scallno, pinfo, full_mini_subtree, tree);
break;
case IAX2_MINI_VIDEO_PACKET:
iax2_info->messageName = "MINI_VIDEO_PACKET";
len = dissect_minivideopacket(tvb, offset, scallno, pinfo, full_mini_subtree, tree);
break;
case IAX2_TRUNK_PACKET:
iax2_info->messageName = "TRUNK_PACKET";
len = dissect_trunkpacket(tvb, offset, scallno, pinfo, full_mini_subtree, tree);
break;
default:
len = 0;
}
proto_item_set_len(iax2_item, len);
tap_queue_packet(iax2_tap, pinfo, iax2_info);
return tvb_captured_length(tvb);
}
static proto_item *dissect_datetime_ie(tvbuff_t *tvb, guint32 offset, proto_tree *ies_tree)
{
struct tm tm;
guint32 ie_val;
nstime_t datetime;
proto_tree_add_item(ies_tree, hf_iax2_ies[IAX_IE_DATETIME], tvb, offset + 2, 4, ENC_BIG_ENDIAN);
ie_val = tvb_get_ntohl(tvb, offset+2);
tm.tm_sec = (ie_val & 0x1f) << 1;
tm.tm_min = (ie_val>>5) & 0x3f;
tm.tm_hour = (ie_val>>11) & 0x1f;
tm.tm_mday = (ie_val>>16) & 0x1f;
tm.tm_mon = ((ie_val>>21) & 0x0f) - 1;
tm.tm_year = ((ie_val>>25) & 0x7f) + 100;
tm.tm_isdst= -1;
datetime.secs = mktime(&tm);
datetime.nsecs = 0;
return proto_tree_add_time(ies_tree, hf_iax2_ie_datetime, tvb, offset+2, 4, &datetime);
}
static guint32 dissect_ies(tvbuff_t *tvb, packet_info *pinfo, guint32 offset,
proto_tree *iax_tree, proto_item * iax_item,
iax2_ie_data *ie_data)
{
DISSECTOR_ASSERT(ie_data);
while (offset < tvb_reported_length(tvb)) {
int ies_type = tvb_get_guint8(tvb, offset);
int ies_len = tvb_get_guint8(tvb, offset + 1);
guint16 apparent_addr_family;
switch (ies_type) {
case IAX_IE_DATAFORMAT:
if (ies_len != 4) {
proto_tree_add_expert(iax_tree, pinfo, &ei_iax_invalid_len, tvb, offset+1, 1);
break;
}
ie_data -> dataformat = tvb_get_ntohl(tvb, offset+2);
break;
case IAX_IE_CALLED_NUMBER:
iax2_info->calledParty = wmem_strdup(wmem_packet_scope(), tvb_format_text(tvb, offset+2, ies_len));
break;
case IAX_IE_CALLING_NUMBER:
iax2_info->callingParty = wmem_strdup(wmem_packet_scope(), tvb_format_text(tvb, offset+2, ies_len));
break;
case IAX_IE_APPARENT_ADDR:
apparent_addr_family = tvb_get_letohs(tvb, offset+2);
switch (apparent_addr_family) {
case LINUX_AF_INET:
ie_data->peer_ptype = PT_UDP;
ie_data->peer_port = tvb_get_ntohs(tvb, offset+4);
set_address_tvb(&ie_data->peer_address, AT_IPv4, 4, tvb, offset+6);
break;
default:
expert_add_info_format(pinfo, iax_item, &ei_iax_peer_address_unsupported,
"Not supported in IAX dissector: peer address family of %u", apparent_addr_family);
break;
}
break;
}
if (iax_tree && ies_type < NUM_HF_IAX2_IES) {
proto_item *ti, *ie_item = NULL;
proto_tree *ies_tree;
int ie_hf = hf_iax2_ies[ies_type];
ies_tree = proto_tree_add_subtree(iax_tree, tvb, offset, ies_len+2, ett_iax2_ie, &ti, " ");
proto_tree_add_uint(ies_tree, hf_iax2_ie_id, tvb, offset, 1, ies_type);
proto_tree_add_uint(ies_tree, hf_iax2_length, tvb, offset + 1, 1, ies_len);
switch (ies_type) {
case IAX_IE_DATETIME:
ie_item = dissect_datetime_ie(tvb, offset, ies_tree);
break;
case IAX_IE_CAPABILITY:
{
proto_tree *codec_tree;
if (ies_len != 4) {
proto_tree_add_expert(ies_tree, pinfo, &ei_iax_invalid_len, tvb, offset+1, 1);
break;
}
ie_item =
proto_tree_add_item(ies_tree, ie_hf,
tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
codec_tree =
proto_item_add_subtree(ie_item, ett_iax2_codecs);
proto_tree_add_item(codec_tree, hf_iax2_cap_g723_1, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_gsm, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_ulaw, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_alaw, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_g726_aal2, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_adpcm, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_slinear, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_lpc10, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_g729a, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_speex, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_ilbc, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_g726, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_g722, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_siren7, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_siren14, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_slinear16, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_jpeg, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_png, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_h261, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_h263, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_h263_plus, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_h264, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
proto_tree_add_item(codec_tree, hf_iax2_cap_mpeg4, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
break;
}
case IAX_IE_APPARENT_ADDR:
{
proto_tree *sockaddr_tree;
sockaddr_tree = proto_tree_add_subtree(ies_tree, tvb, offset + 2, 16,
ett_iax2_ies_apparent_addr, &ie_item, "Apparent Address");
apparent_addr_family = tvb_get_letohs(tvb, offset+2);
proto_tree_add_uint(sockaddr_tree, hf_IAX_IE_APPARENTADDR_SINFAMILY, tvb, offset + 2, 2, apparent_addr_family);
if (apparent_addr_family == LINUX_AF_INET) {
guint32 addr;
proto_tree_add_uint(sockaddr_tree, hf_IAX_IE_APPARENTADDR_SINPORT, tvb, offset + 4, 2, ie_data->peer_port);
memcpy(&addr, ie_data->peer_address.data, 4);
proto_tree_add_ipv4(sockaddr_tree, hf_IAX_IE_APPARENTADDR_SINADDR, tvb, offset + 6, 4, addr);
}
break;
}
default:
if (ie_hf != -1) {
gint explen = proto_registrar_get_length(ie_hf);
if (explen != 0 && ies_len != explen) {
proto_tree_add_expert(ies_tree, pinfo, &ei_iax_invalid_len, tvb, offset+1, 1);
break;
}
switch (proto_registrar_get_ftype(ie_hf)) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_BOOLEAN:
case FT_IPv4:
ie_item = proto_tree_add_item(ies_tree, ie_hf, tvb, offset + 2, ies_len, ENC_BIG_ENDIAN);
break;
case FT_BYTES:
case FT_NONE:
ie_item = proto_tree_add_item(ies_tree, ie_hf, tvb, offset + 2, ies_len, ENC_NA);
break;
case FT_STRING:
case FT_STRINGZ:
ie_item = proto_tree_add_item(ies_tree, ie_hf, tvb, offset + 2, ies_len, ENC_UTF_8|ENC_NA);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
} else {
guint32 value;
const guint8 *ptr;
const gchar *ie_name = val_to_str_ext_const(ies_type, &iax_ies_type_ext, "Unknown");
switch (ies_len) {
case 1:
value = tvb_get_guint8(tvb, offset + 2);
ie_item =
proto_tree_add_uint_format(ies_tree, hf_IAX_IE_UNKNOWN_BYTE,
tvb, offset+2, 1, value,
"%s: %#02x", ie_name, value);
break;
case 2:
value = tvb_get_ntohs(tvb, offset + 2);
ie_item =
proto_tree_add_uint_format(ies_tree, hf_IAX_IE_UNKNOWN_I16,
tvb, offset+2, 2, value,
"%s: %#04x", ie_name, value);
break;
case 4:
value = tvb_get_ntohl(tvb, offset + 2);
ie_item =
proto_tree_add_uint_format(ies_tree, hf_IAX_IE_UNKNOWN_I32,
tvb, offset+2, 4, value,
"%s: %#08x", ie_name, value);
break;
default:
ptr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, ies_len, ENC_ASCII);
ie_item =
proto_tree_add_string_format(ies_tree, hf_IAX_IE_UNKNOWN_BYTES,
tvb, offset+2, ies_len, ptr,
"%s: %s", ie_name, ptr);
break;
}
}
break;
}
if (ie_item && !PROTO_ITEM_IS_HIDDEN(ti)) {
field_info *ie_finfo = PITEM_FINFO(ie_item);
if (ie_finfo && ie_finfo->rep != NULL)
proto_item_set_text(ti, "Information Element: %s",
ie_finfo->rep->representation);
else {
guint8 *ie_val = (guint8 *)wmem_alloc(wmem_packet_scope(), ITEM_LABEL_LENGTH);
proto_item_fill_label(ie_finfo, ie_val);
proto_item_set_text(ti, "Information Element: %s",
ie_val);
}
}
}
offset += ies_len + 2;
}
return offset;
}
static guint32 uncompress_subclass(guint8 csub)
{
if (csub & 0x80) {
if (csub == 0xff)
return (guint32)-1;
else
return 1 << (csub & 0x1F);
}
else
return (guint32)csub;
}
static guint32 dissect_iax2_command(tvbuff_t *tvb, guint32 offset,
packet_info *pinfo, proto_tree *tree,
iax_packet_data *iax_packet)
{
guint8 csub = tvb_get_guint8(tvb, offset);
guint8 address_data[MAX_ADDRESS];
proto_item* ti;
iax2_ie_data ie_data;
iax_call_data *iax_call;
ie_data.peer_address.type = AT_NONE;
ie_data.peer_address.len = 0;
ie_data.peer_address.data = address_data;
ie_data.peer_ptype = PT_NONE;
ie_data.peer_port = 0;
ie_data.peer_callno = 0;
ie_data.dataformat = (guint32)-1;
iax_call = iax_packet -> call_data;
ti = proto_tree_add_uint(tree, hf_iax2_iax_csub, tvb, offset, 1, csub);
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(csub, &iax_iax_subclasses_ext, "unknown (0x%02x)"));
if (offset >= tvb_reported_length(tvb))
return offset;
offset = dissect_ies(tvb, pinfo, offset, tree, ti, &ie_data);
if (iax_call && ie_data.dataformat != (guint32)-1 && iax_call -> subdissector == NULL) {
iax_call -> subdissector = dissector_get_uint_handle(iax2_dataformat_dissector_table, ie_data.dataformat);
iax_call -> dataformat = (iax_dataformat_t)ie_data.dataformat;
}
if (csub == IAX_COMMAND_TXREQ && iax_packet -> first_time) {
if (ie_data.peer_address.type != AT_NONE && ie_data.peer_callno != 0) {
guint tx_circuit = iax_circuit_lookup(&ie_data.peer_address,
ie_data.peer_ptype,
ie_data.peer_port,
ie_data.peer_callno);
iax2_new_circuit_for_call(pinfo, NULL, tx_circuit, pinfo->num, iax_call, iax_packet->reversed);
}
}
return offset;
}
static void iax2_add_ts_fields(packet_info *pinfo, proto_tree *iax2_tree, iax_packet_data *iax_packet, guint16 shortts)
{
guint32 longts =shortts;
nstime_t ts;
proto_item *item;
if (iax_packet->call_data == NULL) {
return;
}
if (iax_packet->abstime.secs == -1) {
time_t start_secs = iax_packet->call_data->start_time.secs;
time_t abs_secs = start_secs + longts/1000;
while(abs_secs < pinfo->abs_ts.secs - 16) {
longts += 32768;
abs_secs = start_secs + longts/1000;
}
iax_packet->abstime.secs=abs_secs;
iax_packet->abstime.nsecs=iax_packet->call_data->start_time.nsecs + (longts % 1000) * 1000000;
if (iax_packet->abstime.nsecs >= 1000000000) {
iax_packet->abstime.nsecs -= 1000000000;
iax_packet->abstime.secs ++;
}
}
iax2_info->timestamp = longts;
if (iax2_tree) {
item = proto_tree_add_time(iax2_tree, hf_iax2_absts, NULL, 0, 0, &iax_packet->abstime);
PROTO_ITEM_SET_GENERATED(item);
ts = pinfo->abs_ts;
nstime_delta(&ts, &ts, &iax_packet->abstime);
item = proto_tree_add_time(iax2_tree, hf_iax2_lateness, NULL, 0, 0, &ts);
PROTO_ITEM_SET_GENERATED(item);
}
}
static guint32
dissect_fullpacket(tvbuff_t *tvb, guint32 offset,
guint16 scallno,
packet_info *pinfo, proto_tree *iax2_tree,
proto_tree *main_tree)
{
guint16 dcallno;
guint32 ts;
guint8 type;
guint8 csub;
guint32 codec;
proto_tree *packet_type_tree = NULL;
iax_call_data *iax_call;
iax_packet_data *iax_packet;
gboolean reversed;
gboolean rtp_marker;
dcallno = tvb_get_ntohs(tvb, offset) & 0x7FFF;
ts = tvb_get_ntohl(tvb, offset + 2);
type = tvb_get_guint8(tvb, offset + 8);
csub = tvb_get_guint8(tvb, offset + 9);
iax2_info->ftype = type;
iax2_info->csub = csub;
iax2_info->scallno = scallno;
iax2_info->dcallno = dcallno;
iax_packet = (iax_packet_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_iax2, 0);
if (!iax_packet) {
if (type == AST_FRAME_IAX && csub == IAX_COMMAND_NEW) {
iax_call = iax_new_call(pinfo, scallno);
reversed = FALSE;
} else {
iax_call = iax_lookup_call(pinfo, scallno, dcallno,
&reversed);
}
iax_packet = iax_new_packet_data(iax_call, reversed);
p_add_proto_data(wmem_file_scope(), pinfo, proto_iax2, 0, iax_packet);
} else {
iax_call = iax_packet->call_data;
reversed = iax_packet->reversed;
}
iax2_populate_pinfo_from_packet_data(pinfo, iax_packet);
if (iax2_tree) {
proto_item *packet_type_base;
proto_tree_add_item(iax2_tree, hf_iax2_dcallno, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(iax2_tree, hf_iax2_retransmission, tvb, offset, 2, ENC_BIG_ENDIAN);
if (iax_call) {
proto_item *item =
proto_tree_add_uint(iax2_tree, hf_iax2_callno, tvb, 0, 4,
iax_call->forward_circuit_ids[0]);
PROTO_ITEM_SET_GENERATED(item);
}
proto_tree_add_uint(iax2_tree, hf_iax2_ts, tvb, offset+2, 4, ts);
iax2_add_ts_fields(pinfo, iax2_tree, iax_packet, (guint16)ts);
proto_tree_add_item(iax2_tree, hf_iax2_oseqno, tvb, offset+6, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(iax2_tree, hf_iax2_iseqno, tvb, offset+7, 1,
ENC_BIG_ENDIAN);
packet_type_base = proto_tree_add_uint(iax2_tree, hf_iax2_type, tvb,
offset+8, 1, type);
packet_type_tree = proto_item_add_subtree(packet_type_base, ett_iax2_type);
} else {
iax2_add_ts_fields(pinfo, iax2_tree, iax_packet, (guint16)ts);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, source call# %d, timestamp %ums",
val_to_str_ext(type, &iax_frame_types_ext, "Unknown (0x%02x)"),
scallno, ts);
iax2_info->messageName = val_to_str_ext(type, &iax_frame_types_ext, "Unknown (0x%02x)");
switch (type) {
case AST_FRAME_IAX:
offset=dissect_iax2_command(tvb, offset+9, pinfo, packet_type_tree, iax_packet);
iax2_info->messageName = val_to_str_ext(csub, &iax_iax_subclasses_ext, "unknown (0x%02x)");
if (csub < NUM_TAP_IAX_VOIP_STATES) iax2_info->callState = tap_iax_voip_state[csub];
break;
case AST_FRAME_DTMF_BEGIN:
case AST_FRAME_DTMF_END:
proto_tree_add_item(packet_type_tree, hf_iax2_dtmf_csub, tvb, offset+9, 1, ENC_ASCII|ENC_NA);
offset += 10;
col_append_fstr(pinfo->cinfo, COL_INFO, " digit %c", csub);
break;
case AST_FRAME_CONTROL:
proto_tree_add_uint(packet_type_tree, hf_iax2_cmd_csub, tvb,
offset+9, 1, csub);
offset += 10;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(csub, &iax_cmd_subclasses_ext, "unknown (0x%02x)"));
iax2_info->messageName = val_to_str_ext (csub, &iax_cmd_subclasses_ext, "unknown (0x%02x)");
if (csub < NUM_TAP_CMD_VOIP_STATES) iax2_info->callState = tap_cmd_voip_state[csub];
break;
case AST_FRAME_VOICE:
iax_packet -> codec = codec = uncompress_subclass(csub);
if (packet_type_tree) {
proto_item *item;
proto_tree_add_item(packet_type_tree, hf_iax2_voice_csub, tvb, offset+9, 1, ENC_BIG_ENDIAN);
item = proto_tree_add_uint(packet_type_tree, hf_iax2_voice_codec, tvb, offset+9, 1, codec);
PROTO_ITEM_SET_GENERATED(item);
}
offset += 10;
if (iax_call) {
if (reversed) {
iax_call->dst_codec = codec;
} else {
iax_call->src_codec = codec;
}
}
dissect_payload(tvb, offset, pinfo, iax2_tree, main_tree, ts, FALSE, iax_packet);
break;
case AST_FRAME_VIDEO:
rtp_marker = csub & 0x40 ? TRUE:FALSE;
iax_packet -> codec = codec = uncompress_subclass((guint8)(csub & ~40));
if (packet_type_tree) {
proto_item *item;
proto_tree_add_item(packet_type_tree, hf_iax2_video_csub, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(packet_type_tree, hf_iax2_marker, tvb, offset+9, 1, ENC_BIG_ENDIAN);
item = proto_tree_add_uint(packet_type_tree, hf_iax2_video_codec, tvb, offset+9, 1, codec);
PROTO_ITEM_SET_GENERATED(item);
}
offset += 10;
if (iax_call && iax_packet -> first_time) {
if (reversed) {
iax_call->dst_vformat = codec;
} else {
iax_call->src_vformat = codec;
}
}
if (rtp_marker)
col_append_str(pinfo->cinfo, COL_INFO, ", Mark");
dissect_payload(tvb, offset, pinfo, iax2_tree, main_tree, ts, TRUE, iax_packet);
break;
case AST_FRAME_MODEM:
proto_tree_add_item(packet_type_tree, hf_iax2_modem_csub, tvb, offset+9, 1, ENC_BIG_ENDIAN);
offset += 10;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(csub, iax_modem_subclasses, "unknown (0x%02x)"));
break;
case AST_FRAME_TEXT:
proto_tree_add_item(packet_type_tree, hf_iax2_text_csub, tvb, offset+9, 1, ENC_BIG_ENDIAN);
offset += 10;
{
int textlen = tvb_captured_length_remaining(tvb, offset);
if (textlen > 0)
{
proto_tree_add_item(packet_type_tree, hf_iax2_text_text, tvb, offset, textlen, ENC_UTF_8|ENC_NA);
offset += textlen;
}
}
break;
case AST_FRAME_HTML:
proto_tree_add_item(packet_type_tree, hf_iax2_html_csub, tvb, offset+9, 1, ENC_BIG_ENDIAN);
offset += 10;
if (csub == 0x01)
{
int urllen = tvb_captured_length_remaining(tvb, offset);
if (urllen > 0)
{
proto_item *pi = proto_tree_add_item(packet_type_tree, hf_iax2_html_url, tvb, offset, urllen, ENC_UTF_8|ENC_NA);
PROTO_ITEM_SET_URL(pi);
offset += urllen;
}
}
break;
case AST_FRAME_CNG:
default:
proto_tree_add_uint(packet_type_tree, hf_iax2_csub, tvb, offset+9,
1, csub);
offset += 10;
col_append_fstr(pinfo->cinfo, COL_INFO, " subclass %d", csub);
break;
}
iax_packet->first_time = FALSE;
return offset;
}
static iax_packet_data *iax2_get_packet_data_for_minipacket(packet_info *pinfo,
guint16 scallno,
gboolean video)
{
iax_packet_data *p = (iax_packet_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_iax2, 0);
if (!p) {
gboolean reversed;
iax_call_data *iax_call;
iax_call = iax_lookup_call(pinfo, scallno, 0, &reversed);
p = iax_new_packet_data(iax_call, reversed);
p_add_proto_data(wmem_file_scope(), pinfo, proto_iax2, 0, p);
if (iax_call) {
if (video)
p->codec = reversed ? iax_call -> dst_vformat : iax_call -> src_vformat;
else
p->codec = reversed ? iax_call -> dst_codec : iax_call -> src_codec;
}
}
iax2_populate_pinfo_from_packet_data(pinfo, p);
return p;
}
static guint32 dissect_minivideopacket(tvbuff_t *tvb, guint32 offset,
guint16 scallno, packet_info *pinfo,
proto_tree *iax2_tree, proto_tree *main_tree)
{
guint32 ts;
iax_packet_data *iax_packet;
gboolean rtp_marker;
proto_item *item;
ts = tvb_get_ntohs(tvb, offset);
rtp_marker = ts & 0x8000 ? TRUE:FALSE;
ts &= ~0x8000;
iax_packet = iax2_get_packet_data_for_minipacket(pinfo, scallno, TRUE);
if (iax2_tree) {
if (iax_packet->call_data) {
item =
proto_tree_add_uint(iax2_tree, hf_iax2_callno, tvb, 0, 4,
iax_packet->call_data->forward_circuit_ids[0]);
PROTO_ITEM_SET_GENERATED(item);
}
proto_tree_add_item(iax2_tree, hf_iax2_minividts, tvb, offset, 2, ENC_BIG_ENDIAN);
iax2_add_ts_fields(pinfo, iax2_tree, iax_packet, (guint16)ts);
proto_tree_add_item(iax2_tree, hf_iax2_minividmarker, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
iax2_add_ts_fields(pinfo, iax2_tree, iax_packet, (guint16)ts);
}
offset += 2;
col_add_fstr(pinfo->cinfo, COL_INFO,
"Mini video packet, source call# %d, timestamp %ums%s",
scallno, ts, rtp_marker?", Mark":"");
dissect_payload(tvb, offset, pinfo, iax2_tree, main_tree, ts, TRUE, iax_packet);
iax_packet->first_time = FALSE;
return offset;
}
static guint32 dissect_minipacket(tvbuff_t *tvb, guint32 offset, guint16 scallno,
packet_info *pinfo, proto_tree *iax2_tree,
proto_tree *main_tree)
{
guint32 ts;
iax_packet_data *iax_packet;
proto_item *item;
ts = tvb_get_ntohs(tvb, offset);
iax_packet = iax2_get_packet_data_for_minipacket(pinfo, scallno, FALSE);
if (iax2_tree) {
if (iax_packet->call_data) {
item = proto_tree_add_uint(iax2_tree, hf_iax2_callno, tvb, 0, 4,
iax_packet->call_data->forward_circuit_ids[0]);
PROTO_ITEM_SET_GENERATED(item);
}
proto_tree_add_uint(iax2_tree, hf_iax2_minits, tvb, offset, 2, ts);
iax2_add_ts_fields(pinfo, iax2_tree, iax_packet, (guint16)ts);
} else {
iax2_add_ts_fields(pinfo, iax2_tree, iax_packet, (guint16)ts);
}
offset += 2;
col_add_fstr(pinfo->cinfo, COL_INFO,
"Mini packet, source call# %d, timestamp %ums",
scallno, ts);
dissect_payload(tvb, offset, pinfo, iax2_tree, main_tree, ts, FALSE, iax_packet);
iax_packet->first_time = FALSE;
return offset;
}
static guint32 dissect_trunkcall_ts(tvbuff_t *tvb, guint32 offset, proto_tree *iax2_tree, guint16 *scallno)
{
proto_tree *call_tree;
guint16 datalen, rlen, ts;
datalen = tvb_get_ntohs(tvb, offset);
*scallno = tvb_get_ntohs(tvb, offset + 2);
ts = tvb_get_ntohs(tvb, offset + 4);
rlen = MIN(tvb_captured_length(tvb) - offset - 6, datalen);
if (iax2_tree) {
call_tree = proto_tree_add_subtree_format(iax2_tree, tvb, offset, rlen + 6,
ett_iax2_trunk_call, NULL, "Trunk call from %u, ts: %u", *scallno, ts);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_len, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_scallno, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_ts, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_data, tvb, offset + 6, rlen, ENC_NA);
}
offset += 6 + rlen;
return offset;
}
static guint32 dissect_trunkcall_nots(tvbuff_t *tvb, guint32 offset, proto_tree *iax2_tree, guint16 *scallno)
{
proto_tree *call_tree;
guint16 datalen, rlen;
*scallno = tvb_get_ntohs(tvb, offset);
datalen = tvb_get_ntohs(tvb, offset + 2);
rlen = MIN(tvb_captured_length(tvb) - offset - 4, datalen);
if (iax2_tree) {
call_tree = proto_tree_add_subtree_format(iax2_tree, tvb, offset, rlen + 6,
ett_iax2_trunk_call, NULL, "Trunk call from %u", *scallno);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_scallno, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_len, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(call_tree, hf_iax2_trunk_call_data, tvb, offset + 4, rlen, ENC_NA);
}
offset += 4 + rlen;
return offset;
}
static call_list *call_list_append(call_list *list, guint16 scallno)
{
call_list *node = wmem_new0(wmem_packet_scope(), call_list);
node->scallno = scallno;
if (list) {
call_list *cur = list;
while (cur->next) {
cur = cur->next;
}
cur->next = node;
return list;
} else {
return node;
}
}
static gboolean call_list_find(call_list *list, guint16 scallno)
{
for (; list; list = list->next) {
if (list->scallno == scallno) {
return TRUE;
}
}
return FALSE;
}
static guint call_list_length(call_list *list)
{
guint count = 0;
for (; list; list = list->next) {
count++;
}
return count;
}
static guint32 dissect_trunkpacket(tvbuff_t *tvb, guint32 offset,
guint16 scallno_param _U_, packet_info *pinfo,
proto_tree *iax2_tree, proto_tree *main_tree _U_)
{
guint8 cmddata, trunkts;
guint nframes = 0, ncalls = 0;
proto_item *cd, *nc = NULL;
proto_tree *field_tree = NULL;
call_list *calls = NULL;
cmddata = tvb_get_guint8(tvb, offset + 1);
trunkts = cmddata & IAX2_TRUNK_TS;
if (iax2_tree) {
proto_tree_add_item(iax2_tree, hf_iax2_trunk_metacmd, tvb, offset, 1, ENC_BIG_ENDIAN);
cd = proto_tree_add_uint(iax2_tree, hf_iax2_trunk_cmddata, tvb, offset + 1, 1, cmddata);
field_tree = proto_item_add_subtree(cd, ett_iax2_trunk_cmddata);
if (trunkts)
proto_item_append_text(cd, " (trunk timestamps)");
proto_tree_add_boolean(field_tree, hf_iax2_trunk_cmddata_ts, tvb, offset + 1, 1, cmddata);
proto_tree_add_item(iax2_tree, hf_iax2_trunk_ts, tvb, offset + 2, 4, ENC_BIG_ENDIAN);
}
offset += 6;
if (trunkts) {
while(tvb_captured_length_remaining(tvb, offset) >= 6) {
guint16 scallno;
offset = dissect_trunkcall_ts(tvb, offset, iax2_tree, &scallno);
if (!call_list_find(calls, scallno)) {
calls = call_list_append(calls, scallno);
}
nframes++;
}
}
else {
while(tvb_captured_length_remaining(tvb, offset) >= 4) {
guint16 scallno;
offset = dissect_trunkcall_nots(tvb, offset, iax2_tree, &scallno);
if (!call_list_find(calls, scallno)) {
calls = call_list_append(calls, scallno);
}
nframes++;
}
}
ncalls = call_list_length(calls);
if (iax2_tree) {
nc = proto_tree_add_uint(iax2_tree, hf_iax2_trunk_ncalls, NULL, 0, 0, ncalls);
PROTO_ITEM_SET_GENERATED(nc);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Trunk packet with %d media frame%s for %d call%s",
nframes, plurality(nframes, "", "s"),
ncalls, plurality(ncalls, "", "s"));
return offset;
}
static void process_iax_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean video, iax_packet_data *iax_packet)
{
guint32 codec = iax_packet -> codec;
iax_call_data *iax_call = iax_packet -> call_data;
#ifdef DEBUG_DESEGMENT
g_debug("calling process_iax_pdu; len = %u", tvb_reported_length(tvb));
#endif
if (!video && iax_call && iax_call->subdissector) {
iax2_dissector_info_t dissector_info;
if (iax_packet->call_data == NULL) {
memset(&dissector_info, 0, sizeof(dissector_info));
} else {
dissector_info.ctype = CT_IAX2;
dissector_info.circuit_id = (guint32)iax_packet->call_data->forward_circuit_ids[0];
}
call_dissector_with_data(iax_call->subdissector, tvb, pinfo, tree, &dissector_info);
} else if (codec != 0 && dissector_try_uint(iax2_codec_dissector_table, codec, tvb, pinfo, tree)) {
} else {
call_data_dissector(tvb, pinfo, tree);
}
#ifdef DEBUG_DESEGMENT
g_debug("called process_iax_pdu; pinfo->desegment_len=%u; pinfo->desegment_offset=%u",
pinfo->desegment_len, pinfo->desegment_offset);
#endif
}
static void desegment_iax(tvbuff_t *tvb, packet_info *pinfo, proto_tree *iax2_tree,
proto_tree *tree, gboolean video, iax_packet_data *iax_packet)
{
iax_call_data *iax_call = iax_packet -> call_data;
iax_call_dirdata *dirdata;
gpointer value = NULL;
guint32 frag_offset = 0;
fragment_head *fd_head;
gboolean must_desegment = FALSE;
DISSECTOR_ASSERT(iax_call);
pinfo->can_desegment = 2;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
#ifdef DEBUG_DESEGMENT
g_debug("dissecting packet %u", pinfo->num);
#endif
dirdata = &(iax_call->dirdata[!!(iax_packet->reversed)]);
if ((!pinfo->fd->flags.visited && (dirdata->current_frag_bytes > 0)) ||
((value = g_hash_table_lookup(iax_fid_table, GUINT_TO_POINTER(pinfo->num))) != NULL)) {
guint32 fid;
guint32 frag_len = tvb_reported_length(tvb);
gboolean complete;
#ifdef DEBUG_DESEGMENT
g_debug("visited: %i; c_f_b: %u; hash: %u->%u", pinfo->fd->flags.visited?1:0,
dirdata->current_frag_bytes, pinfo->num, dirdata->current_frag_id);
#endif
if (!pinfo->fd->flags.visited) {
guint32 tot_len;
fid = dirdata->current_frag_id;
tot_len = dirdata->current_frag_minlen;
DISSECTOR_ASSERT(g_hash_table_lookup(iax_fid_table, GUINT_TO_POINTER(pinfo->num)) == NULL);
g_hash_table_insert(iax_fid_table, GUINT_TO_POINTER(pinfo->num), GUINT_TO_POINTER(fid));
frag_offset = dirdata->current_frag_bytes;
dirdata->current_frag_bytes += frag_len;
complete = dirdata->current_frag_bytes > tot_len;
#ifdef DEBUG_DESEGMENT
g_debug("hash: %u->%u; frag_offset: %u; c_f_b: %u; totlen: %u",
pinfo->num, fid, frag_offset, dirdata->current_frag_bytes, tot_len);
#endif
} else {
fid = GPOINTER_TO_UINT(value);
dirdata->current_frag_bytes = 0;
complete = FALSE;
}
fd_head = fragment_add(&iax_reassembly_table, tvb, 0, pinfo, fid, NULL,
frag_offset,
frag_len, !complete);
if (fd_head && (pinfo->num == fd_head->reassembled_in)) {
gint32 old_len;
tvbuff_t *next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled IAX2");
process_iax_pdu(next_tvb, pinfo, tree, video, iax_packet);
old_len = (gint32)(tvb_reported_length(next_tvb) - frag_len);
if (pinfo->desegment_len &&
(pinfo->desegment_offset < old_len)) {
fragment_set_partial_reassembly(&iax_reassembly_table, pinfo, fid, NULL);
if (pinfo->desegment_len == DESEGMENT_ONE_MORE_SEGMENT) {
dirdata->current_frag_minlen = fd_head->datalen + 1;
} else {
dirdata->current_frag_minlen = fd_head->datalen + pinfo->desegment_len;
}
} else {
proto_item *iax_tree_item, *frag_tree_item;
show_fragment_tree(fd_head, &iax2_fragment_items, tree, pinfo, next_tvb, &frag_tree_item);
iax_tree_item = proto_item_get_parent(proto_tree_get_parent(iax2_tree));
if (frag_tree_item && iax_tree_item)
proto_tree_move_item(tree, iax_tree_item, frag_tree_item);
dirdata->current_frag_minlen = dirdata->current_frag_id = dirdata->current_frag_bytes = 0;
if (pinfo->desegment_len) {
must_desegment = TRUE;
pinfo->desegment_offset -= old_len;
}
fd_head = NULL;
}
}
} else {
process_iax_pdu(tvb, pinfo, tree, video, iax_packet);
if (pinfo->desegment_len) {
must_desegment = TRUE;
}
fd_head = NULL;
}
if (must_desegment) {
guint32 fid = pinfo->num;
guint32 deseg_offset = pinfo->desegment_offset;
guint32 frag_len = tvb_reported_length_remaining(tvb, deseg_offset);
dirdata->current_frag_id = fid;
dirdata->current_frag_bytes = frag_len;
if (pinfo->desegment_len == DESEGMENT_ONE_MORE_SEGMENT) {
dirdata->current_frag_minlen = frag_len + 1;
} else {
dirdata->current_frag_minlen = frag_len + pinfo->desegment_len;
}
fd_head = fragment_add(&iax_reassembly_table,
tvb, deseg_offset, pinfo, fid, NULL,
0, frag_len, TRUE);
#ifdef DEBUG_DESEGMENT
g_debug("Start offset of undissected bytes: %u; "
"Bytes remaining in this segment: %u; min required bytes: %u\n",
deseg_offset, frag_len, frag_len + pinfo->desegment_len);
#endif
}
if (fd_head != NULL) {
guint32 deseg_offset = pinfo->desegment_offset;
if (fd_head->reassembled_in != 0 &&
!(fd_head->flags & FD_PARTIAL_REASSEMBLY)) {
proto_item *iax_tree_item;
iax_tree_item = proto_tree_add_uint(tree, hf_iax2_reassembled_in,
tvb, deseg_offset, tvb_reported_length_remaining(tvb, deseg_offset),
fd_head->reassembled_in);
PROTO_ITEM_SET_GENERATED(iax_tree_item);
} else {
proto_tree_add_item(tree, hf_iax2_fragment_unfinished, tvb, deseg_offset, -1, ENC_NA);
}
if (pinfo->desegment_offset == 0) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IAX2");
col_set_str(pinfo->cinfo, COL_INFO, "[IAX2 segment of a reassembled PDU]");
}
}
pinfo->can_desegment = 0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
}
static void dissect_payload(tvbuff_t *tvb, guint32 offset,
packet_info *pinfo, proto_tree *iax2_tree,
proto_tree *tree, guint32 ts _U_, gboolean video,
iax_packet_data *iax_packet)
{
#if 0
gboolean out_of_order = FALSE;
#endif
tvbuff_t *sub_tvb;
guint32 codec = iax_packet -> codec;
guint32 nbytes;
iax_call_data *iax_call = iax_packet -> call_data;
if (offset >= tvb_reported_length(tvb)) {
col_append_str(pinfo->cinfo, COL_INFO, ", empty frame");
return;
}
sub_tvb = tvb_new_subset_remaining(tvb, offset);
if (!video && iax_call && iax_call -> dataformat != 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", data, format %s",
val_to_str(iax_call -> dataformat,
iax_dataformats, "unknown (0x%02x)"));
#if 0
if (out_of_order)
col_append_str(pinfo->cinfo, COL_INFO, " (out-of-order packet)");
#endif
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(codec, &codec_types_ext, "unknown (0x%02x)"));
}
nbytes = tvb_reported_length(sub_tvb);
proto_tree_add_item(iax2_tree, hf_iax2_payload_data, sub_tvb, 0, -1, ENC_NA);
iax2_info->payload_len = nbytes;
iax2_info->payload_data = tvb_get_ptr(sub_tvb, 0, -1);
if (iax_packet->call_data)
desegment_iax(sub_tvb, pinfo, iax2_tree, tree, video, iax_packet);
else
process_iax_pdu(sub_tvb, pinfo, tree, video, iax_packet);
}
static void
iax_init_protocol(void)
{
iax_circuit_hashtab = g_hash_table_new(iax_circuit_hash, iax_circuit_equal);
circuitcount = 0;
iax_fid_table = g_hash_table_new(g_direct_hash, g_direct_equal);
reassembly_table_init(&iax_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
iax_cleanup_protocol(void)
{
g_hash_table_destroy(iax_circuit_hashtab);
g_hash_table_destroy(iax_fid_table);
reassembly_table_destroy(&iax_reassembly_table);
}
void
proto_register_iax2(void)
{
static hf_register_info hf[] = {
{&hf_iax2_packet_type,
{"Packet type", "iax2.packet_type",
FT_UINT8, BASE_DEC, VALS(iax_packet_types), 0,
"Full/minivoice/minivideo/trunk packet",
HFILL}},
{&hf_iax2_callno,
{"Call identifier", "iax2.call",
FT_UINT32, BASE_DEC, NULL, 0,
"This is the identifier Wireshark assigns to identify this call."
" It does not correspond to any real field in the protocol",
HFILL }},
{&hf_iax2_scallno,
{"Source call", "iax2.src_call",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
"src_call holds the number of this call at the packet source pbx",
HFILL}},
{&hf_iax2_dcallno,
{"Destination call", "iax2.dst_call",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
"dst_call holds the number of this call at the packet destination",
HFILL}},
{&hf_iax2_retransmission,
{"Retransmission", "iax2.retransmission",
FT_BOOLEAN, 16, NULL, 0x8000,
"retransmission is set if this packet is a retransmission of an earlier failed packet",
HFILL}},
{&hf_iax2_ts,
{"Timestamp", "iax2.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"timestamp is the time, in ms after the start of this call, at which this packet was transmitted",
HFILL}},
{&hf_iax2_minits,
{"Timestamp", "iax2.timestamp",
FT_UINT16, BASE_DEC, NULL, 0x0,
"timestamp is the time, in ms after the start of this call, at which this packet was transmitted",
HFILL}},
{&hf_iax2_minividts,
{"Timestamp", "iax2.timestamp",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
"timestamp is the time, in ms after the start of this call, at which this packet was transmitted",
HFILL}},
{&hf_iax2_absts,
{"Absolute Time", "iax2.abstime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"The absolute time of this packet (calculated by adding the IAX timestamp to the start time of this call)",
HFILL}},
{&hf_iax2_lateness,
{"Lateness", "iax2.lateness",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The lateness of this packet compared to its timestamp",
HFILL}},
{&hf_iax2_minividmarker,
{"Marker", "iax2.video.mini_marker",
FT_UINT16, BASE_DEC, NULL, 0x8000,
"RTP end-of-frame marker",
HFILL}},
{&hf_iax2_oseqno,
{"Outbound seq.no.", "iax2.oseqno",
FT_UINT16, BASE_DEC, NULL, 0x0,
"oseqno is the sequence no of this packet. The first packet has oseqno==0,"
" and subsequent packets increment the oseqno by 1",
HFILL}},
{&hf_iax2_iseqno,
{"Inbound seq.no.", "iax2.iseqno",
FT_UINT16, BASE_DEC, NULL, 0x0,
"iseqno is the sequence no of the last successfully received packet",
HFILL}},
{&hf_iax2_type,
{"Type", "iax2.type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &iax_frame_types_ext, 0x0,
"For full IAX2 frames, type is the type of frame",
HFILL}},
{&hf_iax2_csub,
{"Unknown subclass", "iax2.subclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Subclass of unknown type of full IAX2 frame",
HFILL}},
{&hf_iax2_dtmf_csub,
{"DTMF subclass (digit)", "iax2.dtmf.subclass",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"DTMF subclass gives the DTMF digit",
HFILL}},
{&hf_iax2_cmd_csub,
{"Control subclass", "iax2.control.subclass",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &iax_cmd_subclasses_ext, 0x0,
"This gives the command number for a Control packet.",
HFILL}},
{&hf_iax2_iax_csub,
{"IAX subclass", "iax2.iax.subclass",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &iax_iax_subclasses_ext, 0x0,
"IAX subclass gives the command number for IAX signaling packets",
HFILL}},
{&hf_iax2_voice_csub,
{"Voice Subclass (compressed codec no)", "iax2.voice.subclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_voice_codec,
{"CODEC", "iax2.voice.codec",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &codec_types_ext, 0x0,
"CODEC gives the codec used to encode audio data",
HFILL}},
{&hf_iax2_video_csub,
{"Video Subclass (compressed codec no)", "iax2.video.subclass",
FT_UINT8, BASE_DEC, NULL, 0xBF,
NULL, HFILL}},
{&hf_iax2_marker,
{"Marker", "iax2.video.marker",
FT_BOOLEAN, 8, NULL, 0x40,
"RTP end-of-frame marker",
HFILL}},
{&hf_iax2_video_codec,
{"CODEC", "iax2.video.codec",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &codec_types_ext, 0,
"The codec used to encode video data",
HFILL}},
{&hf_iax2_modem_csub,
{"Modem subclass", "iax2.modem.subclass",
FT_UINT8, BASE_DEC, VALS(iax_modem_subclasses), 0x0,
"Modem subclass gives the type of modem",
HFILL}},
{&hf_iax2_text_csub,
{"Text subclass", "iax2.text.subclass",
FT_UINT8, BASE_DEC, VALS(iax_text_subclasses), 0x0,
NULL,
HFILL}},
{&hf_iax2_text_text,
{"Text", "iax2.text.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL}},
{&hf_iax2_html_csub,
{"HTML subclass", "iax2.html.subclass",
FT_UINT8, BASE_DEC, VALS(iax_html_subclasses), 0x0,
NULL,
HFILL}},
{&hf_iax2_html_url,
{"HTML URL", "iax2.html.url",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL}},
{&hf_iax2_trunk_ts,
{"Timestamp", "iax2.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"timestamp is the time, in ms after the start of Command data this call,"
" at which this trunk packet was transmitted",
HFILL}},
{&hf_iax2_trunk_metacmd,
{"Meta command", "iax2.trunk.metacmd",
FT_UINT8, BASE_DEC, NULL, 0x7F,
"Meta command indicates whether or not the Meta Frame is a trunk.",
HFILL}},
{&hf_iax2_trunk_cmddata,
{"Command data", "iax2.trunk.cmddata",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Flags for options that apply to a trunked call",
HFILL}},
{&hf_iax2_trunk_cmddata_ts,
{"Trunk timestamps", "iax2.trunk.cmddata.ts",
FT_BOOLEAN, 8, NULL, IAX2_TRUNK_TS,
"True: calls do each include their own timestamp",
HFILL}},
{&hf_iax2_trunk_call_len,
{"Data length", "iax2.trunk.call.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Trunk call data length in octets",
HFILL}},
{&hf_iax2_trunk_call_scallno,
{"Source call number", "iax2.trunk.call.scallno",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
"Trunk call source call number",
HFILL}},
{&hf_iax2_trunk_call_ts,
{"Timestamp", "iax2.trunk.call.ts",
FT_UINT16, BASE_DEC, NULL, 0x0,
"timestamp is the time, in ms after the start of this call, at which this packet was transmitted",
HFILL}},
{&hf_iax2_trunk_call_data,
{"Data", "iax2.trunk.call.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Payload carried by this trunked packet.",
HFILL}},
{&hf_iax2_trunk_ncalls,
{"Number of calls", "iax2.trunk.ncalls",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of calls in this trunk packet",
HFILL}},
{&hf_IAX_IE_APPARENTADDR_SINFAMILY,
{"Family", "iax2.iax.app_addr.sinfamily",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_IAX_IE_APPARENTADDR_SINPORT,
{"Port", "iax2.iax.app_addr.sinport",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{&hf_IAX_IE_APPARENTADDR_SINADDR,
{"Address", "iax2.iax.app_addr.sinaddr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{&hf_iax2_ies[IAX_IE_CALLED_NUMBER],
{"Number/extension being called", "iax2.iax.called_number",
FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLING_NUMBER],
{"Calling number", "iax2.iax.calling_number",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLING_ANI],
{"Calling number ANI for billing", "iax2.iax.calling_ani",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLING_NAME],
{"Name of caller", "iax2.iax.calling_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLED_CONTEXT],
{"Context for number", "iax2.iax.called_context",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_USERNAME],
{"Username (peer or user) for authentication", "iax2.iax.username",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_PASSWORD],
{"Password for authentication", "iax2.iax.password",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CAPABILITY],
{"Actual codec capability", "iax2.iax.capability",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_FORMAT],
{"Desired codec format", "iax2.iax.format",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &codec_types_ext, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_LANGUAGE],
{"Desired language", "iax2.iax.language",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_VERSION],
{"Protocol version", "iax2.iax.version",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_ADSICPE],
{"CPE ADSI capability", "iax2.iax.cpe_adsi",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_DNID],
{"Originally dialed DNID", "iax2.iax.dnid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_AUTHMETHODS],
{"Authentication method(s)", "iax2.iax.auth.methods",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CHALLENGE],
{"Challenge data for MD5/RSA", "iax2.iax.auth.challenge",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_MD5_RESULT],
{"MD5 challenge result", "iax2.iax.auth.md5",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RSA_RESULT],
{"RSA challenge result", "iax2.iax.auth.rsa",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_REFRESH],
{"When to refresh registration", "iax2.iax.refresh",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_DPSTATUS],
{"Dialplan status", "iax2.iax.dialplan_status",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLNO],
{"Call number of peer", "iax2.iax.call_no",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CAUSE],
{"Cause", "iax2.iax.cause",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_IAX_UNKNOWN],
{"Unknown IAX command", "iax2.iax.iax_unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_MSGCOUNT],
{"How many messages waiting", "iax2.iax.msg_count",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_AUTOANSWER],
{"Request auto-answering", "iax2.iax.autoanswer",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_MUSICONHOLD],
{"Request musiconhold with QUELCH", "iax2.iax.moh",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_TRANSFERID],
{"Transfer Request Identifier", "iax2.iax.transferid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RDNIS],
{"Referring DNIS", "iax2.iax.rdnis",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_PROVISIONING],
{"Provisioning info", "iax2.iax.provisioning",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_AESPROVISIONING],
{"AES Provisioning info", "iax2.iax.aesprovisioning",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_DATETIME],
{"Date/Time", "iax2.iax.datetime.raw",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ie_datetime,
{"Date/Time", "iax2.iax.datetime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL }},
{&hf_iax2_ies[IAX_IE_DEVICETYPE],
{"Device type", "iax2.iax.devicetype",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_SERVICEIDENT],
{"Service identifier", "iax2.iax.serviceident",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_FIRMWAREVER],
{"Firmware version", "iax2.iax.firmwarever",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_FWBLOCKDESC],
{"Firmware block description", "iax2.iax.fwblockdesc",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_FWBLOCKDATA],
{"Firmware block of data", "iax2.iax.fwblockdata",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_PROVVER],
{"Provisioning version", "iax2.iax.provver",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLINGPRES],
{"Calling presentation", "iax2.iax.callingpres",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLINGTON],
{"Calling type of number", "iax2.iax.callington",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CALLINGTNS],
{"Calling transit network select", "iax2.iax.callingtns",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_SAMPLINGRATE],
{"Supported sampling rates", "iax2.iax.samplingrate",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CAUSECODE],
{"Hangup cause", "iax2.iax.causecode",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &iax_causecodes_ext, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_ENCRYPTION],
{"Encryption format", "iax2.iax.encryption",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_ENCKEY],
{"Encryption key", "iax2.iax.enckey",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_CODEC_PREFS],
{"Codec negotiation", "iax2.iax.codecprefs",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RR_JITTER],
{"Received jitter (as in RFC1889)", "iax2.iax.rrjitter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RR_LOSS],
{"Received loss (high byte loss pct, low 24 bits loss count, as in rfc1889)", "iax2.iax.rrloss",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RR_PKTS],
{"Total frames received", "iax2.iax.rrpkts",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RR_DELAY],
{"Max playout delay in ms for received frames", "iax2.iax.rrdelay",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RR_DROPPED],
{"Dropped frames (presumably by jitterbuffer)", "iax2.iax.rrdropped",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_RR_OOO],
{"Frame received out of order", "iax2.iax.rrooo",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_ies[IAX_IE_DATAFORMAT],
{"Data call format", "iax2.iax.dataformat",
FT_UINT32, BASE_HEX, VALS(iax_dataformats), 0x0,
NULL, HFILL}},
{&hf_IAX_IE_UNKNOWN_BYTE,
{"Unknown", "iax2.iax.unknownbyte",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Raw data for unknown IEs", HFILL}},
{&hf_IAX_IE_UNKNOWN_I16,
{"Unknown", "iax2.iax.unknownshort",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Raw data for unknown IEs", HFILL}},
{&hf_IAX_IE_UNKNOWN_I32,
{"Unknown", "iax2.iax.unknownlong",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Raw data for unknown IEs", HFILL}},
{&hf_IAX_IE_UNKNOWN_BYTES,
{"Unknown", "iax2.iax.unknownstring",
FT_STRING, BASE_NONE, NULL, 0x0,
"Raw data for unknown IEs", HFILL}},
{&hf_iax2_ie_id,
{"IE id", "iax2.ie_id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &iax_ies_type_ext, 0x0,
NULL, HFILL}},
{&hf_iax2_length,
{"Length", "iax2.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_iax2_cap_g723_1,
{"G.723.1 compression", "iax2.cap.g723_1",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_G723_1,
NULL, HFILL }},
{&hf_iax2_cap_gsm,
{"GSM compression", "iax2.cap.gsm",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_GSM,
NULL, HFILL }},
{&hf_iax2_cap_ulaw,
{"Raw mu-law data (G.711)", "iax2.cap.ulaw",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_ULAW,
NULL, HFILL }},
{&hf_iax2_cap_alaw,
{"Raw A-law data (G.711)", "iax2.cap.alaw",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_ALAW,
NULL, HFILL } },
{&hf_iax2_cap_g726_aal2,
{"G.726 compression (AAL2 packing)", "iax2.cap.g726_aal2",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_G726_AAL2,
NULL, HFILL }},
{&hf_iax2_cap_adpcm,
{"ADPCM", "iax2.cap.adpcm",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_ADPCM,
NULL, HFILL }},
{&hf_iax2_cap_slinear,
{"Raw 16-bit Signed Linear (8000 Hz) PCM", "iax2.cap.slinear",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_SLINEAR,
NULL, HFILL }},
{&hf_iax2_cap_lpc10,
{"LPC10, 180 samples/frame",
"iax2.cap.lpc10", FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported),
AST_FORMAT_LPC10, NULL, HFILL }},
{&hf_iax2_cap_g729a,
{"G.729a Audio", "iax2.cap.g729a",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_G729A,
NULL, HFILL }},
{&hf_iax2_cap_speex,
{"SPEEX Audio", "iax2.cap.speex",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_SPEEX,
NULL, HFILL }},
{&hf_iax2_cap_ilbc,
{"iLBC Free compressed Audio", "iax2.cap.ilbc",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_ILBC,
NULL, HFILL }},
{&hf_iax2_cap_g726,
{"ADPCM (G.726, 32kbps, RFC3551 codeword packing)", "iax2.cap.g726",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_G726,
NULL, HFILL }},
{&hf_iax2_cap_g722,
{"G.722 wideband audio", "iax2.cap.g722",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_G722,
NULL, HFILL }},
{&hf_iax2_cap_siren7,
{"G.722.1 (also known as Siren7, 32kbps assumed)", "iax2.cap.siren7",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_SIREN7,
NULL, HFILL }},
{&hf_iax2_cap_siren14,
{"G.722.1 Annex C (also known as Siren14, 48kbps assumed)", "iax2.cap.siren14",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_SIREN14,
NULL, HFILL }},
{&hf_iax2_cap_slinear16,
{"Raw 16-bit Signed Linear (16000 Hz) PCM", "iax2.cap.slinear16",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_SLINEAR16,
NULL, HFILL }},
{&hf_iax2_cap_jpeg,
{"JPEG images", "iax2.cap.jpeg",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_JPEG,
NULL, HFILL }},
{&hf_iax2_cap_png,
{"PNG images", "iax2.cap.png",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_PNG,
NULL, HFILL }},
{&hf_iax2_cap_h261,
{"H.261 video", "iax2.cap.h261",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_H261,
NULL, HFILL }},
{&hf_iax2_cap_h263,
{"H.263 video", "iax2.cap.h263",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_H263,
NULL, HFILL }},
{&hf_iax2_cap_h263_plus,
{"H.263+ video", "iax2.cap.h263_plus",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_H263_PLUS,
NULL, HFILL }},
{&hf_iax2_cap_h264,
{"H.264 video", "iax2.cap.h264",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_H264,
NULL, HFILL }},
{&hf_iax2_cap_mpeg4,
{"MPEG4 video", "iax2.cap.mpeg4",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), AST_FORMAT_MP4_VIDEO,
NULL, HFILL }},
{&hf_iax2_fragment_unfinished,
{"IAX2 fragment, unfinished", "iax2.fragment_unfinished",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_iax2_payload_data,
{"IAX2 payload", "iax2.payload_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_iax2_fragments,
{"IAX2 Fragments", "iax2.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_iax2_fragment,
{"IAX2 Fragment data", "iax2.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_iax2_fragment_overlap,
{"Fragment overlap", "iax2.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{&hf_iax2_fragment_overlap_conflict,
{"Conflicting data in fragment overlap", "iax2.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{&hf_iax2_fragment_multiple_tails,
{"Multiple tail fragments found", "iax2.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{&hf_iax2_fragment_too_long_fragment,
{"Fragment too long", "iax2.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{&hf_iax2_fragment_error,
{"Defragmentation error", "iax2.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{&hf_iax2_fragment_count,
{"Fragment count", "iax2.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_iax2_reassembled_in,
{"IAX2 fragment, reassembled in frame", "iax2.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This IAX2 packet is reassembled in this frame", HFILL }},
{&hf_iax2_reassembled_length,
{"Reassembled IAX2 length", "iax2.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }}
};
static gint *ett[] = {
&ett_iax2,
&ett_iax2_full_mini_subtree,
&ett_iax2_type,
&ett_iax2_ie,
&ett_iax2_codecs,
&ett_iax2_ies_apparent_addr,
&ett_iax2_fragment,
&ett_iax2_fragments,
&ett_iax2_trunk_cmddata,
&ett_iax2_trunk_call
};
static ei_register_info ei[] = {
{ &ei_iax_too_many_transfers, { "iax2.too_many_transfers", PI_PROTOCOL, PI_WARN, "Too many transfers for iax_call", EXPFILL }},
{ &ei_iax_circuit_id_conflict, { "iax2.circuit_id_conflict", PI_PROTOCOL, PI_WARN, "Circuit ID conflict", EXPFILL }},
{ &ei_iax_peer_address_unsupported, { "iax2.peer_address_unsupported", PI_PROTOCOL, PI_WARN, "Peer address unsupported", EXPFILL }},
{ &ei_iax_invalid_len, { "iax2.invalid_len", PI_PROTOCOL, PI_WARN, "Invalid length", EXPFILL }}
};
expert_module_t* expert_iax;
memset(hf_iax2_ies, 0xff, sizeof(hf_iax2_ies));
proto_iax2 =
proto_register_protocol("Inter-Asterisk eXchange v2", "IAX2", "iax2");
proto_register_field_array(proto_iax2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_iax = expert_register_protocol(proto_iax2);
expert_register_field_array(expert_iax, ei, array_length(ei));
register_dissector("iax2", dissect_iax2, proto_iax2);
iax2_codec_dissector_table = register_dissector_table(
"iax2.codec", "IAX codec number", proto_iax2, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
iax2_dataformat_dissector_table = register_dissector_table(
"iax2.dataformat", "IAX dataformat number", proto_iax2, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
register_init_routine(&iax_init_protocol);
register_cleanup_routine(&iax_cleanup_protocol);
iax2_tap = register_tap("IAX2");
}
void
proto_reg_handoff_iax2(void)
{
dissector_handle_t v110_handle;
dissector_add_uint("udp.port", IAX2_PORT, find_dissector("iax2"));
v110_handle = find_dissector("v110");
if (v110_handle)
dissector_add_uint("iax2.dataformat", AST_DATAFORMAT_V110, v110_handle);
}
