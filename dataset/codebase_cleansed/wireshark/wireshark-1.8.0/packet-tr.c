static
int check_for_old_linux_tvb(tvbuff_t *tvb)
{
const guint8 *data;
int x, bytes;
bytes = tvb_length(tvb);
if (bytes > 19) {
bytes = 19;
}
data = tvb_get_ptr(tvb, 0, bytes);
for(x = 1; x <= bytes-1 ;x++)
{
if (memcmp(&data[0], &data[x], x) == 0)
{
return x;
}
}
return 0;
}
static
int check_for_old_linux(const guchar * pd)
{
int x;
for(x=1;x<=18;x++)
{
if (memcmp(&pd[0],&pd[x],x) == 0)
{
return x;
}
}
return 0;
}
void
capture_tr(const guchar *pd, int offset, int len, packet_counts *ld) {
int source_routed = 0;
int frame_type;
int x;
guint8 trn_rif_bytes;
guint8 actual_rif_bytes;
guint16 first2_sr;
guint8 trn_fc;
const guint8 *trn_shost;
if (!BYTES_ARE_IN_FRAME(offset, len, TR_MIN_HEADER_LEN)) {
ld->other++;
return;
}
if ((x = check_for_old_linux(pd)))
{
offset+=x;
}
trn_fc = pd[offset + 1];
trn_shost = &pd[offset + 8];
frame_type = (trn_fc & 192) >> 6;
source_routed = trn_shost[0] & 128;
trn_rif_bytes = pd[offset + 14] & 31;
if (fix_linux_botches) {
if (!source_routed && trn_rif_bytes > 0) {
if (pd[offset + 0x0e] != pd[offset + 0x0f]) {
first2_sr = pntohs(&pd[offset + 0xe0 + trn_rif_bytes]);
if (
(first2_sr == 0xaaaa &&
pd[offset + 0x10 + trn_rif_bytes] == 0x03) ||
first2_sr == 0xe0e0 ||
first2_sr == 0xe0aa ) {
source_routed = 1;
}
}
}
}
if (source_routed) {
actual_rif_bytes = trn_rif_bytes;
}
else {
trn_rif_bytes = 0;
actual_rif_bytes = 0;
}
if (fix_linux_botches) {
if ((source_routed && trn_rif_bytes == 2 && frame_type == 1) ||
(!source_routed && frame_type == 1)) {
if ( (pd[offset + 0x20] == 0xaa && pd[offset + 0x21] == 0xaa && pd[offset + 0x22] == 03) ||
(pd[offset + 0x20] == 0xe0 && pd[offset + 0x21] == 0xe0) ) {
actual_rif_bytes = 18;
} else if (
pd[offset + 0x23] == 0 &&
pd[offset + 0x24] == 0 &&
pd[offset + 0x25] == 0 &&
pd[offset + 0x26] == 0x00 &&
pd[offset + 0x27] == 0x11) {
actual_rif_bytes = 18;
offset += 8;
}
}
}
offset += actual_rif_bytes + TR_MIN_HEADER_LEN;
switch (frame_type) {
case 0:
ld->other++;
break;
case 1:
capture_llc(pd, offset, len, ld);
break;
default:
ld->other++;
break;
}
}
static void
dissect_tr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *tr_tree, *bf_tree;
proto_item *ti, *hidden_item;
guint8 rcf1, rcf2;
tvbuff_t *next_tvb;
volatile int frame_type;
volatile int fixoffset = 0;
volatile int source_routed = 0;
volatile guint8 trn_rif_bytes;
volatile guint8 actual_rif_bytes;
volatile guint8 c1_nonsr;
volatile guint8 c2_nonsr;
volatile guint16 first2_sr;
tvbuff_t *volatile tr_tvb;
static tr_hdr trh_arr[4];
static int trh_current=0;
tr_hdr *volatile trh;
static guint8 trn_shost_nonsr[6];
int x;
const char *fc[] = { "MAC", "LLC", "Reserved", "Unknown" };
trh_current++;
if(trh_current==4){
trh_current=0;
}
trh=&trh_arr[trh_current];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TR");
if (fix_linux_botches)
x = check_for_old_linux_tvb((tvbuff_t*) tvb);
else
x = 0;
if (x != 0) {
tr_tvb = tvb_new_subset_remaining((tvbuff_t*) tvb, x);
}
else {
tr_tvb = tvb;
}
trh->fc = tvb_get_guint8(tr_tvb, 1);
SET_ADDRESS(&trh->src, AT_ETHER, 6, tvb_get_ptr(tr_tvb, 8, 6));
SET_ADDRESS(&trh->dst, AT_ETHER, 6, tvb_get_ptr(tr_tvb, 2, 6));
memcpy(trn_shost_nonsr, trh->src.data, 6);
source_routed = trn_shost_nonsr[0] & 128;
trn_shost_nonsr[0] &= 127;
frame_type = (trh->fc & 192) >> 6;
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Token-Ring %s", fc[frame_type]);
trn_rif_bytes = tvb_get_guint8(tr_tvb, 14) & 31;
if (fix_linux_botches) {
if (frame_type == 1 && !source_routed && trn_rif_bytes > 0) {
TRY {
c1_nonsr = tvb_get_guint8(tr_tvb, 14);
c2_nonsr = tvb_get_guint8(tr_tvb, 15);
if (c1_nonsr != c2_nonsr) {
first2_sr = tvb_get_ntohs(tr_tvb, trn_rif_bytes + 0x0e);
if ( ( first2_sr == 0xaaaa &&
tvb_get_guint8(tr_tvb, trn_rif_bytes + 0x10) == 0x03) ||
first2_sr == 0xe0e0 ||
first2_sr == 0xe0aa ) {
source_routed = 1;
}
}
}
CATCH(BoundsError) {
;
}
ENDTRY;
}
}
if (source_routed) {
actual_rif_bytes = trn_rif_bytes;
}
else {
trn_rif_bytes = 0;
actual_rif_bytes = 0;
}
if (fix_linux_botches) {
TRY {
if (frame_type == 1 && ( (source_routed && trn_rif_bytes == 2) ||
!source_routed) ) {
if (
(tvb_get_ntohs(tr_tvb, 0x20) == 0xaaaa &&
tvb_get_guint8(tr_tvb, 0x22) == 0x03)
||
tvb_get_ntohs(tr_tvb, 0x20) == 0xe0e0 ) {
actual_rif_bytes = 18;
}
else if (
tvb_get_ntohl(tr_tvb, 0x23) == 0 &&
tvb_get_guint8(tr_tvb, 0x27) == 0x11) {
actual_rif_bytes = 18;
fixoffset += 8;
}
}
}
CATCH(BoundsError) {
;
}
ENDTRY;
}
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, trn_shost_nonsr);
SET_ADDRESS(&pinfo->src, AT_ETHER, 6, trn_shost_nonsr);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, trh->dst.data);
SET_ADDRESS(&pinfo->dst, AT_ETHER, 6, trh->dst.data);
if (tree) {
ti = proto_tree_add_item(tree, proto_tr, tr_tvb, 0, TR_MIN_HEADER_LEN + actual_rif_bytes, ENC_NA);
tr_tree = proto_item_add_subtree(ti, ett_token_ring);
trh->ac = tvb_get_guint8(tr_tvb, 0);
ti = proto_tree_add_uint(tr_tree, hf_tr_ac, tr_tvb, 0, 1, trh->ac);
bf_tree = proto_item_add_subtree(ti, ett_token_ring_ac);
proto_tree_add_uint(bf_tree, hf_tr_priority, tr_tvb, 0, 1, trh->ac);
proto_tree_add_boolean(bf_tree, hf_tr_frame, tr_tvb, 0, 1, trh->ac);
proto_tree_add_uint(bf_tree, hf_tr_monitor_cnt, tr_tvb, 0, 1, trh->ac);
proto_tree_add_uint(bf_tree, hf_tr_priority_reservation, tr_tvb, 0, 1, trh->ac);
ti = proto_tree_add_uint(tr_tree, hf_tr_fc, tr_tvb, 1, 1, trh->fc);
bf_tree = proto_item_add_subtree(ti, ett_token_ring_fc);
proto_tree_add_uint(bf_tree, hf_tr_fc_type, tr_tvb, 1, 1, trh->fc);
proto_tree_add_uint(bf_tree, hf_tr_fc_pcf, tr_tvb, 1, 1, trh->fc);
proto_tree_add_ether(tr_tree, hf_tr_dst, tr_tvb, 2, 6, trh->dst.data);
proto_tree_add_ether(tr_tree, hf_tr_src, tr_tvb, 8, 6, trh->src.data);
hidden_item = proto_tree_add_ether(tr_tree, hf_tr_addr, tr_tvb, 2, 6, trh->dst.data);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_ether(tr_tree, hf_tr_addr, tr_tvb, 8, 6, trh->src.data);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_boolean(tr_tree, hf_tr_sr, tr_tvb, 8, 1, source_routed);
hidden_item = proto_tree_add_ether(tr_tree, hf_tr_src, tr_tvb, 8, 6, trn_shost_nonsr);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (source_routed) {
rcf1 = tvb_get_guint8(tr_tvb, 14);
proto_tree_add_uint(tr_tree, hf_tr_rif_bytes, tr_tvb, 14, 1, trn_rif_bytes);
proto_tree_add_uint(tr_tree, hf_tr_broadcast, tr_tvb, 14, 1, rcf1 & 224);
rcf2 = tvb_get_guint8(tr_tvb, 15);
proto_tree_add_uint(tr_tree, hf_tr_max_frame_size, tr_tvb, 15, 1, rcf2 & 112);
proto_tree_add_uint(tr_tree, hf_tr_direction, tr_tvb, 15, 1, rcf2 & 128);
if (trn_rif_bytes > 2) {
add_ring_bridge_pairs(trn_rif_bytes, tr_tvb, tr_tree);
}
}
if (actual_rif_bytes > trn_rif_bytes) {
proto_tree_add_text(tr_tree, tr_tvb, TR_MIN_HEADER_LEN + trn_rif_bytes, actual_rif_bytes - trn_rif_bytes,
"Empty RIF from Linux 2.0.x driver. The sniffing NIC "
"is also running a protocol stack.");
}
if (fixoffset) {
proto_tree_add_text(tr_tree, tr_tvb, TR_MIN_HEADER_LEN + 18,8,"Linux 2.0.x fake LLC and SNAP header");
}
}
next_tvb = tvb_new_subset_remaining(tr_tvb, TR_MIN_HEADER_LEN + actual_rif_bytes + fixoffset);
switch (frame_type) {
case 0:
call_dissector(trmac_handle, next_tvb, pinfo, tree);
break;
case 1:
call_dissector(llc_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle,next_tvb, pinfo, tree);
break;
}
tap_queue_packet(tr_tap, pinfo, trh);
}
static void
add_ring_bridge_pairs(int rcf_len, tvbuff_t *tvb, proto_tree *tree)
{
proto_item *hidden_item;
int j, size;
int segment, brdgnmb, unprocessed_rif;
int buff_offset=0;
#define RIF_OFFSET 16
#define RIF_BYTES_TO_PROCESS 30
char *buffer;
#define MAX_BUF_LEN 3 + (RIF_BYTES_TO_PROCESS / 2) * 6 + 1
buffer=ep_alloc(MAX_BUF_LEN);
unprocessed_rif = rcf_len - RIF_BYTES_TO_PROCESS;
rcf_len = MIN(rcf_len, RIF_BYTES_TO_PROCESS);
rcf_len -= 2;
for(j = 1; j < rcf_len - 1; j += 2) {
if (j==1) {
segment = tvb_get_ntohs(tvb, RIF_OFFSET) >> 4;
size = g_snprintf(buffer, MAX_BUF_LEN, "%03X",segment);
size = MIN(size, MAX_BUF_LEN - 1);
hidden_item = proto_tree_add_uint(tree, hf_tr_rif_ring, tvb, TR_MIN_HEADER_LEN + 2, 2, segment);
PROTO_ITEM_SET_HIDDEN(hidden_item);
buff_offset += size;
}
segment = tvb_get_ntohs(tvb, RIF_OFFSET + 1 + j) >> 4;
brdgnmb = tvb_get_guint8(tvb, RIF_OFFSET + j) & 0x0f;
size = g_snprintf(buffer+buff_offset, MAX_BUF_LEN-buff_offset, "-%01X-%03X",brdgnmb,segment);
size = MIN(size, MAX_BUF_LEN-buff_offset-1);
hidden_item = proto_tree_add_uint(tree, hf_tr_rif_ring, tvb, TR_MIN_HEADER_LEN + 3 + j, 2, segment);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(tree, hf_tr_rif_bridge, tvb, TR_MIN_HEADER_LEN + 2 + j, 1, brdgnmb);
PROTO_ITEM_SET_HIDDEN(hidden_item);
buff_offset += size;
}
proto_tree_add_string(tree, hf_tr_rif, tvb, TR_MIN_HEADER_LEN + 2, rcf_len, buffer);
if (unprocessed_rif > 0) {
proto_tree_add_text(tree, tvb, TR_MIN_HEADER_LEN + RIF_BYTES_TO_PROCESS, unprocessed_rif,
"Extra RIF bytes beyond spec: %d", unprocessed_rif);
}
}
void
proto_register_tr(void)
{
static hf_register_info hf[] = {
{ &hf_tr_ac,
{ "Access Control", "tr.ac", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tr_priority,
{ "Priority", "tr.priority", FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }},
{ &hf_tr_frame,
{ "Frame", "tr.frame", FT_BOOLEAN, 8, TFS(&ac_truth), 0x10,
NULL, HFILL }},
{ &hf_tr_monitor_cnt,
{ "Monitor Count", "tr.monitor_cnt", FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }},
{ &hf_tr_priority_reservation,
{ "Priority Reservation","tr.priority_reservation", FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{ &hf_tr_fc,
{ "Frame Control", "tr.fc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tr_fc_type,
{ "Frame Type", "tr.frame_type", FT_UINT8, BASE_DEC, VALS(frame_vals), 0xc0,
NULL, HFILL }},
{ &hf_tr_fc_pcf,
{ "Frame PCF", "tr.frame_pcf", FT_UINT8, BASE_DEC, VALS(pcf_vals), 0x0f,
NULL, HFILL }},
{ &hf_tr_dst,
{ "Destination", "tr.dst", FT_ETHER, BASE_NONE, NULL, 0x0,
"Destination Hardware Address", HFILL }},
{ &hf_tr_src,
{ "Source", "tr.src", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source Hardware Address", HFILL }},
{ &hf_tr_addr,
{ "Source or Destination Address", "tr.addr", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source or Destination Hardware Address", HFILL }},
{ &hf_tr_sr,
{ "Source Routed", "tr.sr", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tr_rif_bytes,
{ "RIF Bytes", "tr.rif_bytes", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of bytes in Routing Information Fields, including the two bytes of Routing Control Field", HFILL }},
{ &hf_tr_broadcast,
{ "Broadcast Type", "tr.broadcast", FT_UINT8, BASE_DEC, VALS(broadcast_vals), 0x0,
"Type of Token-Ring Broadcast", HFILL }},
{ &hf_tr_max_frame_size,
{ "Maximum Frame Size", "tr.max_frame_size", FT_UINT8, BASE_DEC, VALS(max_frame_size_vals),
0x0,
NULL, HFILL }},
{ &hf_tr_direction,
{ "Direction", "tr.direction", FT_UINT8, BASE_DEC, VALS(direction_vals), 0x0,
"Direction of RIF", HFILL }},
{ &hf_tr_rif,
{ "Ring-Bridge Pairs", "tr.rif", FT_STRING, BASE_NONE, NULL, 0x0,
"String representing Ring-Bridge Pairs", HFILL }},
{ &hf_tr_rif_ring,
{ "RIF Ring", "tr.rif.ring", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tr_rif_bridge,
{ "RIF Bridge", "tr.rif.bridge", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_token_ring,
&ett_token_ring_ac,
&ett_token_ring_fc,
};
module_t *tr_module;
proto_tr = proto_register_protocol("Token-Ring", "Token-Ring", "tr");
proto_register_field_array(proto_tr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tr_module = prefs_register_protocol(proto_tr, NULL);
prefs_register_bool_preference(tr_module, "fix_linux_botches",
"Attempt to compensate for Linux mangling of the link-layer header",
"Whether Linux mangling of the link-layer header should be checked for and worked around",
&fix_linux_botches);
register_dissector("tr", dissect_tr, proto_tr);
tr_tap=register_tap("tr");
}
void
proto_reg_handoff_tr(void)
{
dissector_handle_t tr_handle;
trmac_handle = find_dissector("trmac");
llc_handle = find_dissector("llc");
data_handle = find_dissector("data");
tr_handle = find_dissector("tr");
dissector_add_uint("wtap_encap", WTAP_ENCAP_TOKEN_RING, tr_handle);
}
