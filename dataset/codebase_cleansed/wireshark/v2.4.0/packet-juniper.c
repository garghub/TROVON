static int
juniper_ext_get_tlv_value(tvbuff_t *tvb, guint tlv_type, guint tlv_len, guint offset) {
int tlv_value;
if (tlv_type < 128) {
switch (tlv_len) {
case 1:
tlv_value = tvb_get_guint8(tvb, offset);
break;
case 2:
tlv_value = tvb_get_letohs(tvb, offset);
break;
case 3:
tlv_value = tvb_get_letoh24(tvb, offset);
break;
case 4:
tlv_value = tvb_get_letohl(tvb, offset);
break;
default:
tlv_value = -1;
break;
}
} else {
switch (tlv_len) {
case 1:
tlv_value = tvb_get_guint8(tvb, offset);
break;
case 2:
tlv_value = tvb_get_ntohs(tvb, offset);
break;
case 3:
tlv_value = tvb_get_ntoh24(tvb, offset);
break;
case 4:
tlv_value = tvb_get_ntohl(tvb, offset);
break;
default:
tlv_value = -1;
break;
}
}
return tlv_value;
}
static int
dissect_juniper_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *juniper_subtree, guint8 *flags)
{
proto_item *tisub, *magic_item;
guint8 l2hdr_presence,proto,ext_type,ext_len;
guint16 ext_total_len,ext_offset=6,hdr_len;
guint32 magic_number,ext_val;
proto_tree *juniper_ext_subtree = NULL, *juniper_ext_subtree_item = NULL;
magic_number = tvb_get_ntoh24(tvb, 0);
*flags = tvb_get_guint8(tvb, 3);
l2hdr_presence = *flags & JUNIPER_FLAG_NO_L2;
magic_item = proto_tree_add_item(juniper_subtree, hf_juniper_magic, tvb, 0, 3, ENC_BIG_ENDIAN);
if (magic_number != JUNIPER_PCAP_MAGIC) {
expert_add_info(pinfo, magic_item, &ei_juniper_no_magic);
return 0;
}
proto_tree_add_item(juniper_subtree, hf_juniper_direction, tvb, 3, 1, ENC_NA);
proto_tree_add_uint(juniper_subtree, hf_juniper_l2hdr_presence, tvb, 3, 1, l2hdr_presence);
if ((*flags & JUNIPER_FLAG_EXT) == JUNIPER_FLAG_EXT) {
ext_total_len = tvb_get_ntohs(tvb,4);
hdr_len = 6 + ext_total_len;
tisub = proto_tree_add_uint (juniper_subtree, hf_juniper_ext_total_len, tvb, 4, 2, ext_total_len);
juniper_ext_subtree = proto_item_add_subtree(tisub, ett_juniper);
while (ext_total_len > EXT_TLV_HEADER_SIZE) {
ext_type = tvb_get_guint8(tvb, ext_offset);
ext_len = tvb_get_guint8(tvb, ext_offset+1);
if (ext_len == 0 || ext_len > (ext_total_len - EXT_TLV_HEADER_SIZE))
break;
juniper_ext_subtree_item = proto_tree_add_subtree_format(juniper_ext_subtree, tvb, ext_offset, EXT_TLV_HEADER_SIZE + ext_len,
ett_juniper, &tisub, "%s Extension TLV #%u, length: %u",
val_to_str_const(ext_type, ext_tlv_vals, "Unknown"),
ext_type,
ext_len);
ext_val = juniper_ext_get_tlv_value(tvb, ext_type, ext_len, ext_offset+EXT_TLV_HEADER_SIZE);
switch (ext_type) {
case EXT_TLV_IFD_MEDIATYPE:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_ifmt,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_TTP_IFD_MEDIATYPE:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_ttp_ifmt,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_IFL_ENCAPS:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_ifle,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_TTP_IFL_ENCAPS:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_ttp_ifle,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_IFL_IDX:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_ifl,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_IFL_UNIT:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_unit,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_IFD_IDX:
proto_tree_add_uint(juniper_ext_subtree_item, hf_juniper_ext_ifd,
tvb, ext_offset+EXT_TLV_HEADER_SIZE, ext_len, ext_val);
break;
case EXT_TLV_IFD_NAME:
default:
proto_item_append_text(tisub, "Unknown");
break;
}
ext_offset += EXT_TLV_HEADER_SIZE + ext_len;
ext_total_len -= EXT_TLV_HEADER_SIZE + ext_len;
}
} else
hdr_len = 4;
if ((*flags & JUNIPER_FLAG_NO_L2) == JUNIPER_FLAG_NO_L2) {
proto = tvb_get_letohl(tvb,hdr_len);
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, proto, hdr_len + 4);
return -1;
}
return hdr_len;
}
static int
dissect_juniper_payload_proto(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *juniper_subtree, guint proto, guint offset)
{
proto_item *ti;
tvbuff_t *next_tvb;
ti = proto_tree_add_uint(juniper_subtree, hf_juniper_payload_type, tvb, offset, 0, proto);
PROTO_ITEM_SET_GENERATED(ti);
if (proto == 0xa248)
{
proto_tree_add_item(juniper_subtree, hf_juniper_unknown_data, tvb, offset, 4, ENC_NA);
next_tvb = tvb_new_subset_remaining(tvb, offset+4);
call_dissector(ipv4_handle, next_tvb, pinfo, tree);
}
else
{
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint(payload_table, proto, next_tvb, pinfo, tree))
{
call_data_dissector(next_tvb, pinfo, tree);
}
}
return 0;
}
static int
dissect_juniper_mlfr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree* juniper_subtree;
guint offset;
int bytes_processed;
guint8 flags;
guint64 aspic_cookie;
guint32 lspic_cookie;
guint16 mlpic_cookie;
guint proto,cookie_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper MLFR");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper Multi-Link Frame-Relay (FRF.15)");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
aspic_cookie = tvb_get_ntoh64(tvb,offset);
proto = juniper_svc_cookie_proto(aspic_cookie, JUNIPER_PIC_MLFR, flags);
cookie_len = juniper_svc_cookie_len(aspic_cookie);
if (cookie_len == AS_PIC_COOKIE_LEN)
proto_tree_add_uint64(juniper_subtree, hf_juniper_aspic_cookie,
tvb, offset, AS_PIC_COOKIE_LEN, aspic_cookie);
if (cookie_len == LS_PIC_COOKIE_LEN) {
lspic_cookie = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(juniper_subtree, hf_juniper_lspic_cookie,
tvb, offset, LS_PIC_COOKIE_LEN, lspic_cookie);
}
offset += cookie_len;
mlpic_cookie = tvb_get_ntohs(tvb, offset);
if (cookie_len == AS_PIC_COOKIE_LEN &&
proto == JUNIPER_PROTO_UNKNOWN &&
tvb_get_guint8(tvb,offset) == JUNIPER_HDR_LLC_UI) {
offset += 1;
proto = JUNIPER_PROTO_ISO;
}
if (cookie_len == LS_PIC_COOKIE_LEN) {
if ( tvb_get_ntohs(tvb,offset) == JUNIPER_HDR_LLC_UI ||
tvb_get_ntohs(tvb,offset) == (JUNIPER_HDR_LLC_UI<<8)) {
offset += 2;
}
}
if (cookie_len == LS_PIC_COOKIE_LEN && tvb_get_guint8(tvb,offset) == JUNIPER_HDR_LLC_UI) {
offset += 1;
}
if (cookie_len == 0 && tvb_get_ntohs(tvb,offset+ML_PIC_COOKIE_LEN) ==
(JUNIPER_HDR_LLC_UI<<8 | NLPID_Q_933)) {
cookie_len = ML_PIC_COOKIE_LEN;
proto_tree_add_uint(juniper_subtree, hf_juniper_mlpic_cookie,
tvb, offset, ML_PIC_COOKIE_LEN, mlpic_cookie);
offset += 3;
proto = JUNIPER_PROTO_Q933;
}
if (cookie_len == 0) {
if (tvb_get_ntohs(tvb,offset+ML_PIC_COOKIE_LEN) == JUNIPER_HDR_LLC_UI ||
tvb_get_ntohs(tvb,offset+ML_PIC_COOKIE_LEN) == (JUNIPER_HDR_LLC_UI<<8)) {
cookie_len = ML_PIC_COOKIE_LEN;
proto_tree_add_uint(juniper_subtree, hf_juniper_mlpic_cookie,
tvb, offset, ML_PIC_COOKIE_LEN, mlpic_cookie);
offset += 4;
proto = JUNIPER_PROTO_ISO;
}
}
if (cookie_len == 0 && tvb_get_guint8(tvb,offset+ML_PIC_COOKIE_LEN) == JUNIPER_HDR_LLC_UI) {
cookie_len = ML_PIC_COOKIE_LEN;
proto_tree_add_uint(juniper_subtree, hf_juniper_mlpic_cookie,
tvb, offset, ML_PIC_COOKIE_LEN, mlpic_cookie);
offset += 3;
proto = JUNIPER_PROTO_ISO;
}
ti = proto_tree_add_uint(juniper_subtree, hf_juniper_cookie_len, tvb, offset, 0, cookie_len);
PROTO_ITEM_SET_GENERATED(ti);
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, proto, offset);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_mlppp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree* juniper_subtree;
guint offset;
int bytes_processed;
guint8 flags;
guint64 aspic_cookie;
guint32 lspic_cookie;
guint16 mlpic_cookie;
guint proto,cookie_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper MLPPP");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper MLPPP");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
aspic_cookie = tvb_get_ntoh64(tvb,offset);
proto = juniper_svc_cookie_proto(aspic_cookie, JUNIPER_PIC_MLPPP, flags);
cookie_len = juniper_svc_cookie_len(aspic_cookie);
if (cookie_len == AS_PIC_COOKIE_LEN)
proto_tree_add_uint64(juniper_subtree, hf_juniper_aspic_cookie,
tvb, offset, AS_PIC_COOKIE_LEN, aspic_cookie);
if (cookie_len == LS_PIC_COOKIE_LEN) {
lspic_cookie = tvb_get_ntohl(tvb,offset);
proto_tree_add_uint(juniper_subtree, hf_juniper_lspic_cookie,
tvb, offset, LS_PIC_COOKIE_LEN, lspic_cookie);
}
if (cookie_len == 0 && tvb_get_ntohs(tvb, offset) == JUNIPER_HDR_PPP) {
proto = JUNIPER_PROTO_PPP;
offset += 2;
}
if (cookie_len == 0 && ppp_heuristic_guess(tvb_get_ntohs(tvb, offset+2))) {
proto = JUNIPER_PROTO_PPP;
cookie_len = 2;
mlpic_cookie = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(juniper_subtree, hf_juniper_mlpic_cookie,
tvb, offset, ML_PIC_COOKIE_LEN, mlpic_cookie);
}
if (cookie_len == 0 && ppp_heuristic_guess(tvb_get_ntohs(tvb, offset))) {
proto = JUNIPER_PROTO_PPP;
}
ti = proto_tree_add_uint(juniper_subtree, hf_juniper_cookie_len, tvb, offset, 0, cookie_len);
PROTO_ITEM_SET_GENERATED(ti);
offset += cookie_len;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, proto, offset);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_pppoe(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree* juniper_subtree;
guint offset;
int bytes_processed;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper PPPoE");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper PPPoE PIC");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_ETHER, offset);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_ether(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree* juniper_subtree;
guint offset;
int bytes_processed;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper Ethernet");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper Ethernet");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_ETHER, offset);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_ppp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree* juniper_subtree;
guint offset;
int bytes_processed;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper PPP");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper PPP");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_PPP, offset+2);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_frelay(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree* juniper_subtree;
guint offset;
int bytes_processed;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper Frame-Relay");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper Frame-Relay");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_FRELAY, offset);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_chdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree* juniper_subtree;
guint offset = 0;
int bytes_processed;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper C-HDLC");
col_clear(pinfo->cinfo, COL_INFO);
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper C-HDLC");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_CHDLC, offset);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_atm1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_juniper_atm(tvb,pinfo,tree, JUNIPER_PIC_ATM1);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_atm2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_juniper_atm(tvb,pinfo,tree, JUNIPER_PIC_ATM2);
return tvb_captured_length(tvb);
}
static void
dissect_juniper_atm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 atm_pictype)
{
proto_item *ti;
proto_tree* juniper_subtree;
guint8 next_proto = JUNIPER_PROTO_UNKNOWN,atm1_header_len,atm2_header_len,flags;
guint32 cookie1, proto;
guint64 cookie2;
guint offset = 0;
int bytes_processed;
tvbuff_t *next_tvb;
col_clear(pinfo->cinfo, COL_INFO);
switch (atm_pictype) {
case JUNIPER_PIC_ATM1:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper ATM1");
juniper_subtree = proto_tree_add_subtree(tree, tvb, 0, 0 , ett_juniper, NULL, "Juniper ATM1 PIC");
break;
case JUNIPER_PIC_ATM2:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper ATM2");
juniper_subtree = proto_tree_add_subtree(tree, tvb, 0, 0 , ett_juniper, NULL, "Juniper ATM2 PIC");
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper ATM unknown");
proto_tree_add_subtree(tree, tvb, 0, 0 , ett_juniper, NULL, "Juniper unknown ATM PIC");
return;
}
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return;
else
offset+=bytes_processed;
if ((flags & JUNIPER_FLAG_NO_L2) == JUNIPER_FLAG_NO_L2) {
atm1_header_len = 4;
atm2_header_len = 4;
}
else {
atm1_header_len = 4;
atm2_header_len = 8;
}
cookie1 = tvb_get_ntohl(tvb, offset);
cookie2 = tvb_get_ntoh64(tvb, offset);
if (atm_pictype == JUNIPER_PIC_ATM1) {
proto_tree_add_uint(juniper_subtree, hf_juniper_atm1_cookie, tvb, offset, 4, cookie1);
offset += atm1_header_len;
if ((cookie1 >> 24) == 0x80)
next_proto = JUNIPER_PROTO_OAM;
}
else {
proto_tree_add_uint64(juniper_subtree, hf_juniper_atm2_cookie, tvb, offset, 8, cookie2);
offset += atm2_header_len;
if (cookie2 & 0x70)
next_proto = JUNIPER_PROTO_OAM;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (next_proto == JUNIPER_PROTO_OAM) {
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_OAM, offset);
return;
}
proto = tvb_get_ntoh24(tvb, offset);
if (proto == JUNIPER_HDR_NLPID) {
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_LLC, offset);
return;
}
if (proto == JUNIPER_HDR_SNAP) {
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_LLC_SNAP, offset);
return;
}
if ((flags & JUNIPER_FLAG_PKT_IN) != JUNIPER_FLAG_PKT_IN &&
(cookie1 & JUNIPER_ATM2_GAP_COUNT_MASK) &&
atm_pictype != JUNIPER_PIC_ATM1) {
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_ETHER, offset);
return;
}
proto = tvb_get_ntohs(tvb, offset);
if ( ppp_heuristic_guess( (guint16) proto) &&
atm_pictype != JUNIPER_PIC_ATM1) {
proto_tree_add_uint_format_value(juniper_subtree, hf_juniper_encap_type, tvb, offset, 0, 0, "VC-MUX");
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_PPP, offset);
return;
}
proto = tvb_get_guint8(tvb, offset);
if ( proto == JUNIPER_HDR_LLC_UI ) {
proto_tree_add_uint_format_value(juniper_subtree, hf_juniper_encap_type, tvb, offset, 1, 1, "Cisco NLPID");
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_ISO, offset+1);
return;
}
next_proto = ip_heuristic_guess( (guint8) proto);
if (next_proto != JUNIPER_PROTO_UNKNOWN) {
proto_tree_add_uint_format_value(juniper_subtree, hf_juniper_encap_type, tvb, offset, 0, 2, "VC-MUX");
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, next_proto, offset);
return;
}
ti = proto_tree_add_uint_format_value(juniper_subtree, hf_juniper_payload_type, tvb, offset, 0, 0xFFFF, "Unknown");
proto_item_set_len(ti, tvb_reported_length_remaining(tvb, offset));
call_data_dissector(next_tvb, pinfo, tree);
}
static int dissect_juniper_ggsn(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_) {
proto_tree* juniper_subtree;
guint offset = 0;
int bytes_processed;
guint8 flags;
guint16 proto;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper GGSN");
col_clear(pinfo->cinfo, COL_INFO);
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper GGSN");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
proto = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(juniper_subtree, hf_juniper_proto, tvb, offset, 2, proto);
proto_tree_add_item(juniper_subtree, hf_juniper_vlan, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
offset += 4;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, proto, offset);
return tvb_captured_length(tvb);
}
static int dissect_juniper_vp(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_) {
proto_tree* juniper_subtree;
guint offset = 0;
int bytes_processed;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper Voice PIC");
col_clear(pinfo->cinfo, COL_INFO);
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper Voice PIC");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if(bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_IP, offset+18);
return tvb_captured_length(tvb);
}
static int
dissect_juniper_svcs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree* juniper_subtree;
guint offset = 0;
int bytes_processed = 0;
guint8 flags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Juniper Services");
col_clear(pinfo->cinfo, COL_INFO);
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_juniper, NULL, "Juniper Services cookie");
bytes_processed = dissect_juniper_header(tvb, pinfo, tree, juniper_subtree, &flags);
if (bytes_processed == -1)
return 4;
else
offset+=bytes_processed;
if (flags & JUNIPER_FLAG_PKT_IN) {
proto_tree_add_uint(juniper_subtree, hf_juniper_proto, tvb, offset, 2, JUNIPER_PROTO_IP);
offset += 16;
} else {
offset += 12;
}
dissect_juniper_payload_proto(tvb, pinfo, tree, juniper_subtree, JUNIPER_PROTO_IP, offset);
return tvb_captured_length(tvb);
}
static int dissect_juniper_vn(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_)
{
proto_item *ti;
proto_tree* juniper_subtree;
guint offset = 0;
guint32 tlv_type, tlv_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL,
"Juniper Virtual Network Information");
col_clear(pinfo->cinfo, COL_INFO);
juniper_subtree = proto_tree_add_subtree(tree, tvb, offset, 20,
ett_juniper, &ti, "Juniper Virtual Network Information");
tlv_type = tvb_get_guint8(tvb, offset);
tlv_len = tvb_get_guint8(tvb, (offset + 1));
offset += VN_TLV_HDR_SIZE;
while (tlv_type != 255) {
switch (tlv_type) {
case VN_TLV_HOST_IP:
proto_tree_add_item(juniper_subtree, hf_juniper_vn_host_ip, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
case VN_TLV_FLAGS:
proto_tree_add_bitmask(juniper_subtree, tvb, offset, hf_juniper_vn_flags, ett_juniper_vn_flags, vn_flags, ENC_BIG_ENDIAN);
break;
case VN_TLV_SRC_VN:
proto_tree_add_item(juniper_subtree, hf_juniper_vn_src, tvb, offset, tlv_len, ENC_NA|ENC_ASCII);
break;
case VN_TLV_DST_VN:
proto_tree_add_item(juniper_subtree, hf_juniper_vn_dst, tvb, offset, tlv_len, ENC_NA|ENC_ASCII);
break;
default:
proto_tree_add_expert(juniper_subtree, pinfo, &ei_juniper_vn_incorrect_format, tvb, 0, 0);
return offset;
}
offset += tlv_len;
tlv_type = tvb_get_guint8(tvb, offset);
tlv_len = tvb_get_guint8(tvb, (offset + 1));
offset += VN_TLV_HDR_SIZE;
}
offset+=tlv_len;
dissect_juniper_payload_proto(tvb, pinfo, tree, ti, JUNIPER_PROTO_ETHER, offset);
return tvb_captured_length(tvb);
}
static gboolean
ppp_heuristic_guess(guint16 proto) {
switch(proto) {
case PPP_IP :
case PPP_OSI :
case PPP_MPLS_UNI :
case PPP_MPLS_MULTI :
case PPP_IPCP :
case PPP_OSINLCP :
case PPP_MPLSCP :
case PPP_LCP :
case PPP_PAP :
case PPP_CHAP :
case PPP_MP :
case PPP_IPV6 :
case PPP_IPV6CP :
return TRUE;
default:
return FALSE;
}
}
static guint
ip_heuristic_guess(guint8 ip_header_byte) {
switch(ip_header_byte) {
case 0x45:
case 0x46:
case 0x47:
case 0x48:
case 0x49:
case 0x4a:
case 0x4b:
case 0x4c:
case 0x4d:
case 0x4e:
case 0x4f:
return JUNIPER_PROTO_IP;
case 0x60:
case 0x61:
case 0x62:
case 0x63:
case 0x64:
case 0x65:
case 0x66:
case 0x67:
case 0x68:
case 0x69:
case 0x6a:
case 0x6b:
case 0x6c:
case 0x6d:
case 0x6e:
case 0x6f:
return JUNIPER_PROTO_IP6;
default:
return JUNIPER_PROTO_UNKNOWN;
}
}
static
guint juniper_svc_cookie_len (guint64 cookie) {
guint8 svc_cookie_id;
svc_cookie_id = (guint8)(cookie >> 56) & 0xff;
switch(svc_cookie_id) {
case 0x54:
return LS_PIC_COOKIE_LEN;
case GSP_SVC_REQ_APOLLO:
case GSP_SVC_REQ_LSQ:
return AS_PIC_COOKIE_LEN;
default:
return 0;
}
}
static guint
juniper_svc_cookie_proto (guint64 cookie, guint16 pictype, guint8 flags) {
guint8 svc_cookie_id;
guint16 lsq_proto;
guint8 lsq_dir;
svc_cookie_id = (guint8)(cookie >> 56) & 0xff;
lsq_proto = (guint16)((cookie >> 16) & LSQ_L3_PROTO_MASK);
lsq_dir = (guint8)(cookie >> 24) & 0x3;
switch (svc_cookie_id) {
case 0x54:
switch (pictype) {
case JUNIPER_PIC_MLPPP:
return JUNIPER_PROTO_PPP;
case JUNIPER_PIC_MLFR:
return JUNIPER_PROTO_ISO;
default:
return JUNIPER_PROTO_UNKNOWN;
}
case GSP_SVC_REQ_APOLLO:
case GSP_SVC_REQ_LSQ:
switch(lsq_proto) {
case LSQ_L3_PROTO_IPV4:
switch(pictype) {
case JUNIPER_PIC_MLPPP:
if ((flags & JUNIPER_FLAG_PKT_IN) == JUNIPER_FLAG_PKT_IN &&
lsq_dir != (LSQ_COOKIE_RE|LSQ_COOKIE_DIR))
return JUNIPER_PROTO_PPP;
else
return JUNIPER_PROTO_IP;
case JUNIPER_PIC_MLFR:
if (lsq_dir == (LSQ_COOKIE_RE|LSQ_COOKIE_DIR))
return JUNIPER_PROTO_UNKNOWN;
else
return JUNIPER_PROTO_IP;
default:
return JUNIPER_PROTO_UNKNOWN;
}
case LSQ_L3_PROTO_IPV6:
return JUNIPER_PROTO_IP6;
case LSQ_L3_PROTO_MPLS:
return JUNIPER_PROTO_MPLS;
case LSQ_L3_PROTO_ISO:
return JUNIPER_PROTO_ISO;
default:
return JUNIPER_PROTO_UNKNOWN;
}
default:
return JUNIPER_PROTO_UNKNOWN;
}
}
void
proto_register_juniper(void)
{
static hf_register_info hf[] = {
{ &hf_juniper_magic,
{ "Magic Number", "juniper.magic-number", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_direction,
{ "Direction", "juniper.direction", FT_UINT8, BASE_HEX,
VALS(juniper_direction_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_l2hdr_presence,
{ "L2 header presence", "juniper.l2hdr", FT_UINT8, BASE_HEX,
VALS(juniper_l2hdr_presence_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_ext_total_len,
{ "Extension(s) Total length", "juniper.ext_total_len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_cookie_len,
{ "Cookie length", "juniper.cookie_len", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_atm2_cookie,
{ "Cookie", "juniper.atm2.cookie", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_atm1_cookie,
{ "Cookie", "juniper.atm1.cookie", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_mlpic_cookie,
{ "Cookie", "juniper.mlpic.cookie", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_lspic_cookie,
{ "Cookie", "juniper.lspic.cookie", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_aspic_cookie,
{ "Cookie", "juniper.aspic.cookie", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_vlan,
{ "VLan ID", "juniper.vlan", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_proto,
{ "Protocol", "juniper.proto", FT_UINT16, BASE_DEC,
VALS(juniper_proto_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_payload_type,
{ "Payload Type", "juniper.payload_type", FT_UINT16, BASE_DEC,
VALS(juniper_proto_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_encap_type,
{ "Encapsulation Type", "juniper.encap_type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_ext_ifd,
{ "Device Interface Index", "juniper.ext.ifd", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_ext_ifl,
{ "Logical Interface Index", "juniper.ext.ifl", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_ext_unit,
{ "Logical Unit Number", "juniper.ext.unit", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_ext_ifmt,
{ "Device Media Type", "juniper.ext.ifmt", FT_UINT16, BASE_DEC,
VALS(juniper_ifmt_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_ext_ifle,
{ "Logical Interface Encapsulation", "juniper.ext.ifle", FT_UINT16, BASE_DEC,
VALS(juniper_ifle_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_ext_ttp_ifmt,
{ "TTP derived Device Media Type", "juniper.ext.ttp_ifmt", FT_UINT16, BASE_DEC,
VALS(juniper_ifmt_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_ext_ttp_ifle,
{ "TTP derived Logical Interface Encapsulation", "juniper.ext.ttp_ifle", FT_UINT16, BASE_DEC,
VALS(juniper_ifle_vals), 0x0, NULL, HFILL }},
{ &hf_juniper_unknown_data,
{ "Unknown data", "juniper.unknown_data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_vn_host_ip,
{ "Host IP", "juniper.vn.host_ip", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_vn_src,
{ "Src VN", "juniper.vn.src", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_vn_dst,
{ "Dst VN", "juniper.vn.dst", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_juniper_vn_flags,
{ "Flags", "juniper.vn.flags", FT_UINT32, BASE_HEX, NULL, VN_FLAG_MASK,
NULL, HFILL }},
{ &hf_juniper_vn_flag_alert,
{ "Action Alert", "juniper.vn.flags.alert", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_ALERT, NULL, HFILL }},
{ &hf_juniper_vn_flag_drop,
{ "Action Drop", "juniper.vn.flags.drop", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_DROP, NULL, HFILL }},
{ &hf_juniper_vn_flag_deny,
{ "Action Deny", "juniper.vn.flags.deny", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_DENY, NULL, HFILL }},
{ &hf_juniper_vn_flag_log,
{ "Action Log", "juniper.vn.flags.log", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_LOG, NULL, HFILL }},
{ &hf_juniper_vn_flag_pass,
{ "Action Pass", "juniper.vn.flags.pass", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_PASS, NULL, HFILL }},
{ &hf_juniper_vn_flag_reject,
{ "Action Reject", "juniper.vn.flags.reject", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_REJECT, NULL, HFILL }},
{ &hf_juniper_vn_flag_mirror,
{ "Action Mirror", "juniper.vn.flags.mirror", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_MIRROR, NULL, HFILL }},
{ &hf_juniper_vn_flag_direction,
{ "Direction Ingress", "juniper.vn.flags.direction", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), VN_FLAG_DIRECTION, NULL, HFILL }},
};
static gint *ett[] = {
&ett_juniper,
&ett_juniper_vn_flags,
};
static ei_register_info ei[] = {
{ &ei_juniper_no_magic, { "juniper.magic-number.none", PI_PROTOCOL, PI_WARN, "No Magic-Number found!", EXPFILL }},
{ &ei_juniper_vn_incorrect_format, { "juniper.vn.incorrect_format", PI_PROTOCOL, PI_WARN, "Incorrect format", EXPFILL }},
};
expert_module_t* expert_juniper;
proto_juniper = proto_register_protocol("Juniper", "Juniper", "juniper");
proto_register_field_array(proto_juniper, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_juniper = expert_register_protocol(proto_juniper);
expert_register_field_array(expert_juniper, ei, array_length(ei));
payload_table = register_dissector_table("juniper.proto", "Juniper payload dissectors", proto_juniper, FT_UINT32, BASE_HEX);
}
void
proto_reg_handoff_juniper(void)
{
dissector_handle_t juniper_atm1_handle;
dissector_handle_t juniper_atm2_handle;
dissector_handle_t juniper_pppoe_handle;
dissector_handle_t juniper_mlppp_handle;
dissector_handle_t juniper_mlfr_handle;
dissector_handle_t juniper_ether_handle;
dissector_handle_t juniper_ppp_handle;
dissector_handle_t juniper_frelay_handle;
dissector_handle_t juniper_chdlc_handle;
dissector_handle_t juniper_ggsn_handle;
dissector_handle_t juniper_vp_handle;
dissector_handle_t juniper_svcs_handle;
dissector_handle_t juniper_vn_handle;
ipv4_handle = find_dissector_add_dependency("ip", proto_juniper);
juniper_atm2_handle = create_dissector_handle(dissect_juniper_atm2, proto_juniper);
juniper_atm1_handle = create_dissector_handle(dissect_juniper_atm1, proto_juniper);
juniper_pppoe_handle = create_dissector_handle(dissect_juniper_pppoe, proto_juniper);
juniper_mlppp_handle = create_dissector_handle(dissect_juniper_mlppp, proto_juniper);
juniper_mlfr_handle = create_dissector_handle(dissect_juniper_mlfr, proto_juniper);
juniper_ether_handle = create_dissector_handle(dissect_juniper_ether, proto_juniper);
juniper_ppp_handle = create_dissector_handle(dissect_juniper_ppp, proto_juniper);
juniper_frelay_handle = create_dissector_handle(dissect_juniper_frelay, proto_juniper);
juniper_chdlc_handle = create_dissector_handle(dissect_juniper_chdlc, proto_juniper);
juniper_ggsn_handle = create_dissector_handle(dissect_juniper_ggsn, proto_juniper);
juniper_vp_handle = create_dissector_handle(dissect_juniper_vp, proto_juniper);
juniper_svcs_handle = create_dissector_handle(dissect_juniper_svcs, proto_juniper);
juniper_vn_handle = create_dissector_handle(dissect_juniper_vn, proto_juniper);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_ATM2, juniper_atm2_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_ATM1, juniper_atm1_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_PPPOE, juniper_pppoe_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_MLPPP, juniper_mlppp_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_MLFR, juniper_mlfr_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_ETHER, juniper_ether_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_PPP, juniper_ppp_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_FRELAY, juniper_frelay_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_CHDLC, juniper_chdlc_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_GGSN, juniper_ggsn_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_VP, juniper_vp_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_SVCS, juniper_svcs_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JUNIPER_VN, juniper_vn_handle);
dissector_add_for_decode_as_with_preference("udp.port", juniper_vn_handle);
}
