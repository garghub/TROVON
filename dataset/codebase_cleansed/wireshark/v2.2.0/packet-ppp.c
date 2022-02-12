static guint16
fcs16(tvbuff_t *tvbuff)
{
guint len = tvb_reported_length(tvbuff) - 2;
if (len == 0)
return (0x0000);
return crc16_ccitt_tvb(tvbuff, len);
}
static guint32
fcs32(tvbuff_t *tvbuff)
{
guint len = tvb_reported_length(tvbuff) - 4;
if (len == 0)
return (0x00000000);
return crc32_ccitt_tvb(tvbuff, len);
}
tvbuff_t *
decode_fcs(tvbuff_t *tvb, proto_tree *fh_tree, int fcs_decode, int proto_offset)
{
tvbuff_t *next_tvb;
gint len, reported_len;
switch (fcs_decode) {
case NO_FCS:
next_tvb = tvb_new_subset_remaining(tvb, proto_offset);
break;
case FCS_16:
len = tvb_captured_length_remaining(tvb, proto_offset);
reported_len = tvb_reported_length_remaining(tvb, proto_offset);
if (reported_len < 2 || len < 0) {
next_tvb = tvb_new_subset_remaining(tvb, proto_offset);
} else if (len < reported_len) {
reported_len -= 2;
if (len > reported_len)
len = reported_len;
next_tvb = tvb_new_subset(tvb, proto_offset, len, reported_len);
} else {
len -= 2;
reported_len -= 2;
next_tvb = tvb_new_subset(tvb, proto_offset, len, reported_len);
proto_tree_add_checksum(fh_tree, tvb, proto_offset + len, hf_ppp_fcs_16, -1, NULL, NULL, fcs16(tvb),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
break;
case FCS_32:
len = tvb_captured_length_remaining(tvb, proto_offset);
reported_len = tvb_reported_length_remaining(tvb, proto_offset);
if (reported_len < 4) {
next_tvb = tvb_new_subset_remaining(tvb, proto_offset);
} else if (len < reported_len) {
reported_len -= 4;
if (len > reported_len)
len = reported_len;
next_tvb = tvb_new_subset(tvb, proto_offset, len, reported_len);
} else {
len -= 4;
reported_len -= 4;
next_tvb = tvb_new_subset(tvb, proto_offset, len, reported_len);
proto_tree_add_checksum(fh_tree, tvb, proto_offset + len, hf_ppp_fcs_32, -1, NULL, NULL, fcs32(tvb),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
next_tvb = NULL;
break;
}
return next_tvb;
}
gboolean
capture_ppp_hdlc(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
if (!BYTES_ARE_IN_FRAME(offset, len, 2))
return FALSE;
if (pd[0] == CHDLC_ADDR_UNICAST || pd[0] == CHDLC_ADDR_MULTICAST)
return capture_chdlc(pd, offset, len, cpinfo, pseudo_header);
if (!BYTES_ARE_IN_FRAME(offset, len, 4))
return FALSE;
return try_capture_dissector("ppp_hdlc", pntoh16(&pd[offset + 2]), pd, offset + 4, len, cpinfo, pseudo_header);
}
static void
dissect_lcp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_lcp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_lcp_opt_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_lcp_vendor_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_item *ti;
guint32 oui;
const gchar *manuf;
oui = tvb_get_ntoh24(tvb, offset + 2);
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
ti = proto_tree_add_uint_format_value(field_tree, hf_lcp_opt_oui, tvb,
offset + 2, 3, oui, "%02x:%02x:%02x",
(oui >> 16) & 0xff, (oui >> 8) & 0xff, oui & 0xff);
manuf = uint_get_manuf_name_if_known(oui);
if (manuf)
proto_item_append_text(ti, "(%s)", manuf);
proto_tree_add_item(field_tree, hf_lcp_opt_kind, tvb, offset + 5, 1,
ENC_BIG_ENDIAN);
if (length > 6) {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset + 6,
length - 6, ENC_NA);
}
}
static void
dissect_lcp_mru_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %u", optp->name,
tvb_get_ntohs(tvb, offset + 2));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_mru, tvb, offset + 2, 2,
ENC_BIG_ENDIAN);
}
static void
dissect_lcp_async_map_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_item *tf, *ti;
static const int *asyncmap_fields[] = {
&hf_lcp_opt_asyncmap_us, &hf_lcp_opt_asyncmap_rs,
&hf_lcp_opt_asyncmap_gs, &hf_lcp_opt_asyncmap_fs,
&hf_lcp_opt_asyncmap_esc, &hf_lcp_opt_asyncmap_sub,
&hf_lcp_opt_asyncmap_em, &hf_lcp_opt_asyncmap_can,
&hf_lcp_opt_asyncmap_etb, &hf_lcp_opt_asyncmap_syn,
&hf_lcp_opt_asyncmap_nak, &hf_lcp_opt_asyncmap_dc4,
&hf_lcp_opt_asyncmap_dc3, &hf_lcp_opt_asyncmap_dc2,
&hf_lcp_opt_asyncmap_dc1, &hf_lcp_opt_asyncmap_dle,
&hf_lcp_opt_asyncmap_si, &hf_lcp_opt_asyncmap_so,
&hf_lcp_opt_asyncmap_cr, &hf_lcp_opt_asyncmap_ff,
&hf_lcp_opt_asyncmap_vt, &hf_lcp_opt_asyncmap_lf,
&hf_lcp_opt_asyncmap_ht, &hf_lcp_opt_asyncmap_bs,
&hf_lcp_opt_asyncmap_bel, &hf_lcp_opt_asyncmap_ack,
&hf_lcp_opt_asyncmap_enq, &hf_lcp_opt_asyncmap_eot,
&hf_lcp_opt_asyncmap_etx, &hf_lcp_opt_asyncmap_stx,
&hf_lcp_opt_asyncmap_soh, &hf_lcp_opt_asyncmap_nul,
NULL
};
static const char *ctrlchars[32] = {
"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
"BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI",
"DLE", "DC1 (XON)", "DC2", "DC3 (XOFF)", "DC4", "NAK", "SYN", "ETB",
"CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"
};
gboolean anyctrlchars;
guint32 map;
int i;
map = tvb_get_ntohl(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, *optp->subtree_index, &tf, "%s: 0x%08x (",
optp->name, map);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
ti = proto_tree_add_bitmask(field_tree, tvb, offset + 2,
hf_lcp_opt_asyncmap, *optp->subtree_index, asyncmap_fields,
ENC_BIG_ENDIAN);
if (map == 0x00000000) {
proto_item_append_text(tf, "None)");
proto_item_append_text(ti, " (None)");
} else if (map == 0xffffffff) {
proto_item_append_text(tf, "All)");
proto_item_append_text(ti, " (All)");
} else {
for (anyctrlchars = FALSE, i = 31; i >= 0; i--) {
if (map & (1 << i)) {
if (anyctrlchars)
proto_item_append_text(tf, ", %s", ctrlchars[i]);
else {
anyctrlchars = TRUE;
proto_item_append_text(tf, "%s", ctrlchars[i]);
}
}
}
proto_item_append_text(tf, ")");
}
}
static void
dissect_lcp_authprot_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint16 protocol;
protocol = tvb_get_ntohs(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, *optp->subtree_index, NULL,
"%s: %s (0x%02x)", optp->name, val_to_str_ext_const(protocol, &ppp_vals_ext, "Unknown"),
protocol);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_auth_protocol, tvb, offset + 2,
2, ENC_BIG_ENDIAN);
if (length > 4) {
offset += 4;
length -= 4;
if (protocol == PPP_CHAP) {
proto_tree_add_item(field_tree, hf_lcp_opt_algorithm, tvb, offset,
1, ENC_BIG_ENDIAN);
if (length > 1) {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb,
offset + 1, length - 1, ENC_NA);
}
} else {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset,
length, ENC_NA);
}
}
}
static void
dissect_lcp_qualprot_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint16 protocol;
protocol = tvb_get_ntohs(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, *optp->subtree_index, NULL, "%s: %s (0x%02x)",
optp->name, val_to_str_ext_const(protocol, &ppp_vals_ext, "Unknown"),
protocol);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_quality_protocol, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
if (length > 4) {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset + 4,
length + 4, ENC_NA);
}
}
static void
dissect_lcp_magicnumber_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, *optp->subtree_index, NULL, "%s: 0x%08x",
optp->name, tvb_get_ntohl(tvb, offset + 2));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_magic_number, tvb, offset + 2,
4, ENC_BIG_ENDIAN);
}
static void
dissect_lcp_linkqualmon_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint32 reportingperiod;
reportingperiod = tvb_get_ntohl(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %u microsecond%s%s", optp->name, reportingperiod,
plurality(reportingperiod, "", "s"),
reportingperiod ? "" : " [illegal]");
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_uint_format_value(field_tree, hf_lcp_opt_reportingperiod,
tvb, offset + 2, 4, reportingperiod, "%u microsecond%s%s",
reportingperiod, plurality(reportingperiod, "", "s"),
reportingperiod ? "" : "[illegal]");
}
static void
dissect_lcp_simple_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
}
static void
dissect_lcp_fcs_alternatives_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree,
void *data _U_)
{
proto_tree *field_tree;
static const int *fcs_alternatives_fields[] = {
&hf_lcp_opt_fcs_alternatives_ccitt32,
&hf_lcp_opt_fcs_alternatives_ccitt16,
&hf_lcp_opt_fcs_alternatives_null,
NULL
};
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: 0x%02x",
optp->name, tvb_get_guint8(tvb, offset + 2));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_bitmask(field_tree, tvb, offset + 2,
hf_lcp_opt_fcs_alternatives, *optp->subtree_index,
fcs_alternatives_fields, ENC_NA);
}
static void
dissect_lcp_self_describing_pad_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree,
void *data _U_)
{
proto_tree *field_tree;
guint8 maximum;
maximum = tvb_get_guint8(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %u octet%s%s",
optp->name, maximum, plurality(maximum, "", "s"),
maximum ? "" : " [invalid]");
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_uint_format_value(field_tree, hf_lcp_opt_maximum, tvb,
offset + 2, 1, maximum, "%u octet%s%s", maximum,
plurality(maximum, "", "s"), maximum ? "" : " [invalid]");
}
static void
dissect_lcp_numbered_mode_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree,
void *data _U_)
{
proto_tree *field_tree;
guint8 window;
window = tvb_get_guint8(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %u frame%s%s",
optp->name, window, plurality(window, "", "s"),
(window == 0 || window > 127) ? " [invalid]" : "");
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_uint_format_value(field_tree, hf_lcp_opt_window, tvb,
offset + 2, 1, window, "%u frame%s%s", window,
plurality(window, "", "s"),
(window == 0 || window > 127) ? " [invalid]" : "");
if (length > 3) {
proto_tree_add_item(field_tree, hf_lcp_opt_hdlc_address, tvb,
offset + 3, length - 3, ENC_NA);
}
}
static void
dissect_lcp_callback_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 operation;
operation = tvb_get_guint8(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
val_to_str_const(operation, callback_op_vals, "Unknown"));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_operation, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
if (length > 3) {
proto_tree_add_item(field_tree, hf_lcp_opt_message, tvb, offset + 3,
length - 3, ENC_NA);
}
}
static void
dissect_lcp_multilink_mrru_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree,
void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %u", optp->name,
tvb_get_ntohs(tvb, offset + 2));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_mrru, tvb, offset + 2, 2,
ENC_BIG_ENDIAN);
}
static void
dissect_lcp_multilink_ep_disc_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree,
void *data _U_)
{
proto_tree *field_tree;
proto_tree *magic_tree;
proto_item *tm;
guint8 ep_disc_class;
ep_disc_class = tvb_get_guint8(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: Class: %s",
optp->name, val_to_str_const(ep_disc_class,
multilink_ep_disc_class_vals, "Unknown"));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_ep_disc_class, tvb, offset + 2,
1, ENC_BIG_ENDIAN);
if (length <= 3)
return;
length -= 3;
offset += 3;
switch (ep_disc_class) {
case CLASS_NULL:
break;
case CLASS_LOCAL:
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset,
length <= 20 ? length : 20, ENC_NA);
break;
case CLASS_IP:
if (length >= 4) {
proto_tree_add_item(field_tree, hf_lcp_opt_ip_address, tvb, offset,
4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset,
length, ENC_NA);
}
break;
case CLASS_IEEE_802_1:
if (length >= 6) {
proto_tree_add_item(field_tree, hf_lcp_opt_802_1_address, tvb,
offset, 6, ENC_NA);
} else {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset,
length, ENC_NA);
}
break;
case CLASS_PPP_MAGIC_NUMBER:
if (length % 4) {
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset,
length, ENC_NA);
} else {
tm = proto_tree_add_item(field_tree, hf_lcp_opt_magic_block, tvb,
offset, length <= 20 ? length : 20, ENC_NA);
magic_tree = proto_item_add_subtree(tm, ett_lcp_magic_block);
for ( ; length >= 4; length -= 4, offset += 4) {
proto_tree_add_item(magic_tree, hf_lcp_opt_magic_number, tvb,
offset, 4, ENC_BIG_ENDIAN);
}
}
break;
case CLASS_PSDN_DIRECTORY_NUMBER:
proto_tree_add_item(field_tree, hf_lcp_opt_psndn, tvb, offset,
length > 15 ? 15 : length, ENC_NA);
break;
default:
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset, length,
ENC_NA);
break;
}
}
static void
dissect_lcp_dce_identifier_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 mode;
mode = tvb_get_guint8(tvb, offset + 2);
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
val_to_str_const(mode, dce_id_mode_vals, "Unknown"));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_mode, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_lcp_multilink_pp_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_unused, tvb, offset + 2, 2,
ENC_NA);
}
static void
dissect_lcp_bacp_link_discriminator_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %u (0x%04x)",
optp->name, tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 2));
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_link_discrim, tvb, offset + 2,
2, ENC_BIG_ENDIAN);
}
static void
dissect_lcp_auth_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 id_len;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_id, tvb, offset + 2, 1, ENC_NA);
if (length > 3) {
id_len = tvb_get_guint8(tvb, offset + 2);
length -= 3;
offset += 3;
if (id_len < length) {
length -= id_len;
offset += id_len;
proto_tree_add_item(field_tree, hf_lcp_opt_data, tvb, offset,
length, ENC_NA);
}
}
}
static void
dissect_lcp_cobs_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
static const int *cobs_flags_fields[] = {
&hf_lcp_opt_cobs_flags_res,
&hf_lcp_opt_cobs_flags_pre,
&hf_lcp_opt_cobs_flags_zxe,
NULL
};
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_bitmask(field_tree, tvb, offset + 2, hf_lcp_opt_cobs_flags,
*optp->subtree_index, cobs_flags_fields, ENC_NA);
}
static void
dissect_lcp_prefix_elision_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 pre_len;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
if (length > 2) {
length -= 2;
offset += 2;
while (length >= 2) {
proto_tree_add_item(field_tree, hf_lcp_opt_class, tvb, offset, 1,
ENC_BIG_ENDIAN);
pre_len = tvb_get_guint8(tvb, offset + 1);
if ((guint)(pre_len + 2) <= length) {
proto_tree_add_item(field_tree, hf_lcp_opt_prefix, tvb,
offset + 2, 1, ENC_NA);
length -= (2 + pre_len);
} else {
length = 0;
}
}
}
}
static void
dissect_lcp_multilink_hdr_fmt_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_code, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_lcp_opt_max_susp_classes, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
}
static void
dissect_lcp_internationalization_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_lcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_lcp_opt_MIBenum, tvb, offset + 2, 4,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_lcp_opt_language_tag, tvb, offset + 6,
length - 6, ENC_ASCII|ENC_NA);
}
static void
dissect_ipcp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_ipcp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_ipcp_opt_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_addrs_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: Src: %s, Dst: %s",
optp->name, tvb_ip_to_str(tvb, offset + 2),
tvb_ip_to_str(tvb, offset + 6));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_src_address, tvb, offset + 2,
4, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ipcp_opt_dst_address, tvb, offset + 6,
4, ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_compress_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint16 us;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
val_to_str_const(tvb_get_ntohs(tvb, offset + 2),
ipcp_compress_proto_vals, "Unknown"));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_compress_proto, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
us = tvb_get_ntohs(tvb, offset + 2);
switch (us) {
case IPCP_ROHC:
proto_tree_add_item(field_tree, hf_ipcp_opt_max_cid, tvb, offset + 4,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ipcp_opt_mrru, tvb, offset + 6, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ipcp_opt_max_header, tvb,
offset + 8, 2, ENC_BIG_ENDIAN);
if (length > 10) {
proto_tree *subopt_tree;
offset += 10;
length -= 10;
subopt_tree = proto_tree_add_subtree_format(field_tree, tvb, offset, length,
*optp->subtree_index, NULL, "Suboptions: (%u byte%s)", length, plurality(length, "", "s"));
dissect_ip_tcp_options(tvb, offset, length, ipcp_rohc_subopts,
N_IPCP_ROHC_SUBOPTS, -1, &PPP_OPT_TYPES, &ei_ppp_opt_len_invalid, pinfo, subopt_tree, NULL, NULL);
}
break;
case IPCP_COMPRESS_VJ_1172:
case IPCP_COMPRESS_VJ:
proto_tree_add_item(field_tree, hf_ipcp_opt_max_slot_id, tvb,
offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ipcp_opt_comp_slot_id, tvb,
offset + 5, 1, ENC_NA);
break;
case IPCP_COMPRESS_IPHC:
proto_tree_add_item(field_tree, hf_ipcp_opt_tcp_space, tvb, offset + 4,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ipcp_opt_non_tcp_space, tvb,
offset + 6, 2, ENC_BIG_ENDIAN);
us = tvb_get_ntohs(tvb, offset + 8);
proto_tree_add_uint_format_value(field_tree, hf_ipcp_opt_f_max_period,
tvb, offset + 8, 2, us, "%u%s", us,
(us == 0) ? " (infinity)" : "");
us = tvb_get_ntohs(tvb, offset + 10);
proto_tree_add_uint_format_value(field_tree, hf_ipcp_opt_f_max_time,
tvb, offset + 10, 2, us, "%u%s", us,
(us == 0) ? " (infinity)" : "");
proto_tree_add_item(field_tree, hf_ipcp_opt_max_header, tvb,
offset + 12, 2, ENC_BIG_ENDIAN);
if ( length > 14 ) {
proto_tree *subopt_tree;
offset += 14;
length -= 14;
subopt_tree = proto_tree_add_subtree_format(field_tree, tvb, offset, length,
*optp->subtree_index, NULL, "Suboptions: (%u byte%s)", length, plurality(length, "", "s"));
dissect_ip_tcp_options(tvb, offset, length, ipcp_iphc_subopts,
N_IPCP_IPHC_SUBOPTS, -1, &PPP_OPT_TYPES, &ei_ppp_opt_len_invalid, pinfo, subopt_tree, NULL, NULL);
}
break;
default:
if (length > 4) {
proto_tree_add_item(field_tree, hf_ipcp_data, tvb, offset + 4,
length - 4, ENC_NA);
}
break;
}
}
static void
dissect_ipcp_opt_rohc_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_ipcp_opt_rohc_type, tvb, offset,
1, type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_ipcp_opt_rohc_length, tvb, offset + 1, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_rohc_profiles_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ipcp_opt_rohc_type_len(tvb, offset, field_tree, optp->name);
if (length <= 2)
return;
for (offset += 2, length -= 2; length >= 2; length -= 2, offset += 2) {
proto_tree_add_item(field_tree, hf_ipcp_opt_rohc_profile, tvb,
offset, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_ipcp_opt_iphc_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_ipcp_opt_iphc_type, tvb, offset,
1, type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_ipcp_opt_iphc_length, tvb, offset + 1, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_iphc_simple_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ipcp_opt_iphc_type_len(tvb, offset, field_tree, optp->name);
}
static void
dissect_ipcp_iphc_neghdrcomp_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ipcp_opt_iphc_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_iphc_param, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_addr_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_ip_address, tvb, offset + 2, 4,
ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_mobileipv4_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_mobilenodehomeaddr, tvb,
offset + 2, 4, ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_pri_dns_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_pri_dns_address, tvb,
offset + 2, 4, ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_pri_nbns_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_pri_nbns_address, tvb,
offset + 2, 4, ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_sec_dns_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_sec_dns_address, tvb,
offset + 2, 4, ENC_BIG_ENDIAN);
}
static void
dissect_ipcp_sec_nbns_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
dissect_ipcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ipcp_opt_sec_nbns_address, tvb,
offset + 2, 4, ENC_BIG_ENDIAN);
}
static int
dissect_bcp_ncp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_bcp_ncp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
offset++;
proto_tree_add_item(tree, hf_bcp_ncp_opt_length, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_bcp_ncp_bridge_id(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_bcp_ncp_lan_seg_no, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_bcp_ncp_bridge_no, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_bcp_ncp_line_id(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(tree, hf_bcp_ncp_lan_seg_no, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bcp_ncp_bridge_no, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_bcp_ncp_mac_sup(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(tree, hf_bcp_bpdu_mac_type, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_bcp_ncp_tinygram_comp(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(tree, hf_bcp_ncp_tinygram_comp, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_bcp_ncp_lan_id(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
}
static void
dissect_bcp_ncp_mac_addr(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(tree, hf_bcp_ncp_mac, tvb, offset, 6, ENC_NA);
proto_tree_add_item(tree, hf_bcp_ncp_mac_l, tvb, offset, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bcp_ncp_mac_m, tvb, offset, 6, ENC_BIG_ENDIAN);
}
static void
dissect_bcp_ncp_stp(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
length = length - 2;
while (length != 0) {
proto_tree_add_item(tree, hf_bcp_ncp_stp_prot, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
}
}
static void
dissect_bcp_ncp_ieee_802_tagged_frame(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
offset = dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(tree, hf_bcp_ncp_ieee_802_tagged_frame, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_bcp_ncp_management_inline(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
}
static void
dissect_bcp_ncp_bcp_ncp_bcp_ind(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s",
optp->name);
dissect_bcp_ncp_opt_type_len(tvb, offset, field_tree, optp->name);
}
static void
dissect_osinlcp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_osinlcp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_osinlcp_opt_length, tvb, offset + 1, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_osinlcp_align_npdu_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
*optp->subtree_index, NULL, "%s: Alignment: %u",
optp->name, tvb_get_guint8(tvb, offset + 2));
dissect_osinlcp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_osinlcp_opt_alignment, tvb, offset + 2,
1, ENC_BIG_ENDIAN);
}
static void
dissect_pppmuxcp_def_pid_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
pppmux_def_prot_id = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(tree, hf_pppmux_def_prot_id, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
static void
dissect_ccp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_ccp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_ccp_opt_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void dissect_ccp_oui_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_item *ti;
guint32 oui;
const gchar *manuf;
oui = tvb_get_ntoh24(tvb, offset + 2);
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
ti = proto_tree_add_uint_format_value(field_tree, hf_ccp_opt_oui, tvb,
offset + 2, 3, oui, "%02x:%02x:%02x",
(oui >> 16) & 0xff, (oui >> 8) & 0xff, oui & 0xff);
manuf = uint_get_manuf_name_if_known(oui);
if (manuf)
proto_item_append_text(ti, "(%s)", manuf);
proto_tree_add_item(field_tree, hf_ccp_opt_subtype, tvb, offset + 5, 1,
ENC_BIG_ENDIAN);
if (length > 6) {
proto_tree_add_item(field_tree, hf_ccp_opt_data, tvb, offset + 6,
length - 6, ENC_NA);
}
}
static void dissect_ccp_other_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
if (length > 2) {
proto_tree_add_item(field_tree, hf_ccp_opt_data, tvb, offset + 2,
length - 2, ENC_NA);
}
}
static void
dissect_ccp_stac_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
const char *stac_ascend = "Stac Electronics LZS (Ascend Proprietary version)";
static const int *check_mode_fields[] = {
&hf_ccp_opt_cm_reserved,
&hf_ccp_opt_cm_check_mode,
NULL
};
if (length == 6) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, stac_ascend);
dissect_ccp_opt_type_len(tvb, offset, field_tree, stac_ascend);
proto_tree_add_item(field_tree, hf_ccp_opt_data, tvb, offset + 2,
length - 2, ENC_NA);
} else {
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_history_count, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(field_tree, tvb, offset + 4, hf_ccp_opt_cm,
ett_ccp_stac_opt_check_mode, check_mode_fields, ENC_NA);
}
}
static void
dissect_ccp_mppe_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
static const int *supported_bits_fields[] = {
&hf_ccp_opt_supported_bits_h,
&hf_ccp_opt_supported_bits_m,
&hf_ccp_opt_supported_bits_s,
&hf_ccp_opt_supported_bits_l,
&hf_ccp_opt_supported_bits_d,
&hf_ccp_opt_supported_bits_c,
NULL
};
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_bitmask(field_tree, tvb, offset + 2,
hf_ccp_opt_supported_bits, ett_ccp_mppe_opt_supp_bits,
supported_bits_fields, ENC_BIG_ENDIAN);
}
static void dissect_ccp_gfza_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_history, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
if (length > 3) {
proto_tree_add_item(field_tree, hf_ccp_opt_version, tvb, offset + 3,
length - 3, ENC_NA);
}
}
static void
dissect_ccp_bsdcomp_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
static const int *vd_fields[] = {
&hf_ccp_opt_vd_vers,
&hf_ccp_opt_vd_dict,
NULL
};
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_bitmask(field_tree, tvb, offset + 2, hf_ccp_opt_vd,
*optp->subtree_index, vd_fields, ENC_BIG_ENDIAN);
}
static void
dissect_ccp_lzsdcp_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_history_count, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ccp_opt_check_mode, tvb, offset + 4, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ccp_opt_process_mode, tvb, offset + 5,
1, ENC_BIG_ENDIAN);
}
static void
dissect_ccp_mvrca_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_fe, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ccp_opt_p, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_History, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ccp_opt_contexts, tvb, offset + 3, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_ccp_dce_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_mode, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
}
static void
dissect_ccp_deflate_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 window;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
window = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_uint_format_value(field_tree, hf_ccp_opt_window, tvb,
offset + 2, 1, window, "%u", 1 << (hi_nibble(window) + 8));
proto_tree_add_item(field_tree, hf_ccp_opt_method, tvb, offset + 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ccp_opt_mbz, tvb, offset + 3, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ccp_opt_chk, tvb, offset + 3, 1,
ENC_BIG_ENDIAN);
}
static void dissect_ccp_v44lzjh_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_mode_dictcount, tvb, offset + 2,
2, ENC_BIG_ENDIAN);
if (length > 4) {
proto_tree_add_item(field_tree, hf_ccp_opt_dict_size, tvb, offset + 4,
2, ENC_BIG_ENDIAN);
if (length > 6) {
proto_tree_add_item(field_tree, hf_ccp_opt_history_length, tvb,
offset + 6, 2, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_cbcp_no_callback_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_cbcp_no_callback, tvb, offset, length, ENC_NA);
}
static void
dissect_cbcp_callback_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_tree *addr_tree;
proto_item *ti;
guint8 addr_type;
guint addr_len;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_cbcp_callback_delay, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
offset += 3;
length -= 3;
while (length > 0) {
addr_tree = proto_tree_add_subtree(field_tree, tvb, offset, length,
ett_cbcp_callback_opt_addr, NULL, "Callback Address");
addr_type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint_format_value(addr_tree, hf_cbcp_address_type, tvb, offset, 1, addr_type,
"%s (%u)", ((addr_type == 1) ? "PSTN/ISDN" : "Other"), addr_type);
offset++;
length--;
addr_len = tvb_strsize(tvb, offset);
if (addr_len > length) {
expert_add_info(pinfo, ti, &ei_cbcp_address);
break;
}
proto_tree_add_item(addr_tree, hf_cbcp_address, tvb, offset, addr_len, ENC_NA|ENC_ASCII);
offset += addr_len;
length -= addr_len;
}
}
static void
dissect_bacp_favored_peer_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_bacp_magic_number, tvb, offset + 2, 4, ENC_BIG_ENDIAN);
}
static void
dissect_bap_link_type_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint16 link_speed;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
link_speed = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_uint_format_value(field_tree, hf_bacp_link_speed, tvb, offset + 2, 2, link_speed, "%u kbps", link_speed);
proto_tree_add_item(field_tree, hf_bacp_link_type, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
}
static void
dissect_bap_phone_delta_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_tree *suboption_tree;
proto_item *ti;
guint8 subopt_type;
guint8 subopt_len;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
offset += 2;
length -= 2;
while (length > 0) {
subopt_type = tvb_get_guint8(tvb, offset);
subopt_len = tvb_get_guint8(tvb, offset + 1);
suboption_tree = proto_tree_add_subtree_format(field_tree, tvb, offset, subopt_len,
ett_bap_phone_delta_subopt, NULL, "Sub-Option (%u byte%s)", subopt_len,
plurality(subopt_len, "", "s"));
proto_tree_add_item(suboption_tree, hf_bap_sub_option_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(suboption_tree, hf_bap_sub_option_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
if (subopt_len < 2) {
expert_add_info_format(pinfo, ti, &ei_bap_sub_option_length,
"Sub-Option Length invalid, must be >= 2");
return;
}
if (subopt_len > length) {
expert_add_info_format(pinfo, ti, &ei_bap_sub_option_length,
"Sub-Option Length invalid, must be <= length remaining in option %u)", length);
return;
}
switch (subopt_type) {
case BAP_PHONE_DELTA_SUBOPT_UNIQ_DIGIT:
if (subopt_len == 3) {
proto_tree_add_item(suboption_tree, hf_bap_unique_digit, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_bap_sub_option_length,
"Invalid suboption length: %u (must be == 3)", subopt_len);
}
break;
case BAP_PHONE_DELTA_SUBOPT_SUBSC_NUM:
if (subopt_len > 2) {
proto_tree_add_item(suboption_tree, hf_bap_subscriber_number, tvb, offset + 2, subopt_len - 2, ENC_NA|ENC_ASCII);
} else {
expert_add_info_format(pinfo, ti, &ei_bap_sub_option_length,
"Invalid suboption length: %u (must be > 2)", subopt_len);
}
break;
case BAP_PHONE_DELTA_SUBOPT_PHONENUM_SUBADDR:
if (subopt_len > 2) {
proto_tree_add_item(suboption_tree, hf_bap_phone_number_sub_address, tvb, offset + 2, subopt_len - 2, ENC_NA|ENC_ASCII);
} else {
expert_add_info_format(pinfo, ti, &ei_bap_sub_option_length,
"Invalid suboption length: %u (must be > 2)", subopt_len);
}
break;
default:
if (subopt_len > 2) {
proto_tree_add_item(suboption_tree, hf_bap_unknown_option_data, tvb, offset + 2, subopt_len - 2, ENC_NA);
} else {
expert_add_info_format(pinfo, ti, &ei_bap_sub_option_length,
"Invalid suboption length: %u (must be > 2)", subopt_len);
}
break;
}
offset += subopt_len;
length -= subopt_len;
}
}
static void
dissect_bap_reason_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
if (length > 2) {
proto_tree_add_item(tree, hf_bap_reason, tvb, offset+2, length-2, ENC_NA|ENC_ASCII);
}
}
static void
dissect_bap_link_disc_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_bap_link_descriminator, tvb, offset+2, 2, ENC_BIG_ENDIAN);
}
static void
dissect_bap_call_status_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
proto_tree_add_item(field_tree, hf_bap_call_status, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_bap_call_action, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_pdnid_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_vsncp_pdn_identifier, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_attachtype_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_vsncp_attach_type, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_pdntype_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_vsncp_pdn_type, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_errorcode_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_vsncp_error_code, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_pdnaddress_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
guint8 pdnaddtype;
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
pdnaddtype = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_item(field_tree, hf_vsncp_pdn_type, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
switch (pdnaddtype) {
case 1:
proto_tree_add_ipv4_format(field_tree, hf_vsncp_pdn_ipv4, tvb, offset + 3, 4,
tvb_get_ntohl(tvb, offset + 3), "%s: %s",
val_to_str_const(pdnaddtype, vsncp_pdntype_vals, "Unknown"),
tvb_ip_to_str(tvb, offset + 3));
break;
case 2:
{
struct e_in6_addr *ad = wmem_new0(wmem_packet_scope(),struct e_in6_addr);
address addr;
tvb_memcpy(tvb, &ad->bytes[8], offset + 3, 8);
set_address(&addr, AT_IPv6, 16, ad->bytes);
proto_tree_add_ipv6_format(field_tree, hf_vsncp_pdn_ipv6, tvb, offset + 3, length - 3, ad,
"%s: %s", val_to_str_const(pdnaddtype, vsncp_pdntype_vals, "Unknown"),
address_to_str(wmem_packet_scope(), &addr));
break;
}
case 3:
{
struct e_in6_addr *ad = wmem_new0(wmem_packet_scope(), struct e_in6_addr);
address addr;
tvb_memcpy(tvb, &ad->bytes[8], offset + 3, 8);
set_address(&addr, AT_IPv6, 16, ad->bytes);
proto_tree_add_ipv6_format(field_tree, hf_vsncp_pdn_ipv6, tvb, offset + 3, length - 3, ad,
"%s: %s", val_to_str_const(pdnaddtype, vsncp_pdntype_vals, "Unknown"),
address_to_str(wmem_packet_scope(), &addr));
proto_tree_add_ipv4_format(field_tree, hf_vsncp_pdn_ipv4, tvb, offset + 11, length - 11,
tvb_get_ntohl(tvb, offset + 11), "%s: %s", val_to_str_const(pdnaddtype, vsncp_pdntype_vals, "Unknown"),
tvb_ip_to_str(tvb, offset + 11));
break;
}
default:
break;
}
}
static void
dissect_vsncp_ipv4address_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_vsncp_default_router_address, tvb, offset+2, 4, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_apname_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
if (length > 2) {
guint8 i = 0;
guint8 j = 1;
guint8 lengthofapn;
int off = offset + 2;
while (i < (length - 2)) {
lengthofapn = tvb_get_guint8(tvb, off++);
proto_tree_add_string_format(field_tree, hf_vsncp_access_point_name, tvb, off, lengthofapn,
tvb_get_string_enc(wmem_packet_scope(), tvb, off, lengthofapn, ENC_ASCII),
"Label%d (%d byte%s): %s", j++, lengthofapn,
plurality(lengthofapn, "", "s"),
tvb_format_text(tvb, off, lengthofapn));
off += lengthofapn;
i += lengthofapn + 1;
}
}
}
static void
dissect_vsncp_addressalloc_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_vsncp_address_allocation_cause, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
static void
dissect_vsncp_apn_ambr_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
if (tree) {
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
proto_tree_add_item(field_tree, hf_vsncp_ambr_data, tvb, offset, length, ENC_NA);
}
}
static void
dissect_vsncp_ipv6_hsgw_lla_iid_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
if (tree) {
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
proto_tree_add_item(field_tree, hf_vsncp_ipv6_interface_identifier, tvb, offset, length, ENC_NA);
}
}
static void
dissect_vsncp_pco_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int off = offset + 3;
guint8 i = 0;
guint8 len;
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
while (i < (length - 3)) {
len = tvb_get_guint8(tvb, (off + 2));
proto_tree_add_item(field_tree, hf_vsncp_protocol, tvb, off, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_vsncp_protocol_configuration_length, tvb, off + 2, 1, ENC_BIG_ENDIAN);
if (len > 0) {
proto_tree_add_item(field_tree, hf_vsncp_protocol_configuration_data, tvb, off + 3, len, ENC_NA);
}
off += 3 + len;
i += 3 + len;
}
}
static void
dissect_cp(tvbuff_t *tvb, int proto_id, int proto_subtree_index,
const value_string *proto_vals, int options_subtree_index,
const ip_tcp_opt *opts, int nopts, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
guint8 code;
int length, offset;
code = tvb_get_guint8(tvb, 0);
length = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_PROTOCOL,
proto_get_protocol_short_name(find_protocol_by_id(proto_id)));
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(code, proto_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_id, tvb, 0, length, ENC_NA);
fh_tree = proto_item_add_subtree(ti, proto_subtree_index);
proto_tree_add_uint_format_value(fh_tree, hf_ppp_code, tvb, 0, 1, code,
"%s (%u)", val_to_str_const(code, proto_vals, "Unknown"), code);
proto_tree_add_item(fh_tree, hf_ppp_identifier, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_ppp_length, tvb, 2, 2, ENC_BIG_ENDIAN);
}
offset = 4;
length -= 4;
switch (code) {
case VNDRSPCFC:
if (tree) {
guint32 oui;
const gchar *manuf;
proto_tree_add_item(fh_tree, hf_ppp_magic_number, tvb, offset, 4,
ENC_BIG_ENDIAN);
oui = tvb_get_ntoh24(tvb, offset + 4);
ti = proto_tree_add_uint_format_value(fh_tree, hf_ppp_oui, tvb,
offset + 4, 3, oui, "%02x:%02x:%02x", (oui >> 16) & 0xff,
(oui >> 8) & 0xff, oui & 0xff);
manuf = uint_get_manuf_name_if_known(oui);
if (manuf){
proto_item_append_text(ti, "(%s)", manuf);
}else{
manuf = try_val_to_str(oui,oui_vals);
if (manuf){
proto_item_append_text(ti, "(%s)", manuf);
}
}
proto_tree_add_item(fh_tree, hf_ppp_kind, tvb, offset + 7, 1,
ENC_BIG_ENDIAN);
if (length > 8) {
proto_tree_add_item(fh_tree, hf_ppp_data, tvb, offset + 8,
length - 8, ENC_NA);
}
}
break;
case CONFREQ:
case CONFACK:
case CONFNAK:
case CONFREJ:
if (length > 0) {
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(fh_tree, tvb, offset, length,
options_subtree_index, NULL, "Options: (%d byte%s)", length, plurality(length, "", "s"));
dissect_ip_tcp_options(tvb, offset, length, opts, nopts, -1, &PPP_OPT_TYPES,
&ei_ppp_opt_len_invalid, pinfo, field_tree, NULL, NULL);
}
break;
case CODEREJ:
if (tree && (length > 0)) {
proto_tree_add_bytes_format(fh_tree, hf_ppp_data, tvb, offset,
length, NULL, "Rejected Packet (%d byte%s): %s", length,
plurality(length, "", "s"),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, length));
}
break;
case PROTREJ:
if (tree) {
proto_tree_add_item(fh_tree, hf_lcp_rej_proto, tvb, offset, 2,
ENC_BIG_ENDIAN);
}
if (length > 2) {
gboolean save_in_error_pkt;
tvbuff_t *next_tvb;
guint16 protocol;
protocol = tvb_get_ntohs(tvb, offset);
offset += 2;
length -= 2;
save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
next_tvb = tvb_new_subset_length(tvb, offset, length);
if (!dissector_try_uint(ppp_subdissector_table, protocol, next_tvb,
pinfo, fh_tree)) {
call_data_dissector(next_tvb, pinfo, fh_tree);
}
pinfo->flags.in_error_pkt = save_in_error_pkt;
}
break;
case ECHOREQ:
case ECHOREP:
case DISCREQ:
if (tree) {
proto_tree_add_item(fh_tree, hf_lcp_magic_number, tvb, offset, 4,
ENC_BIG_ENDIAN);
if (length > 4) {
proto_tree_add_item(fh_tree, hf_lcp_data, tvb, offset + 4,
length - 4, ENC_NA);
}
}
break;
case IDENT:
if (tree) {
proto_tree_add_item(fh_tree, hf_lcp_magic_number, tvb, offset, 4,
ENC_BIG_ENDIAN);
if (length > 4) {
proto_tree_add_item(fh_tree, hf_lcp_message, tvb, offset + 4,
length - 4, ENC_ASCII|ENC_NA);
}
}
break;
case TIMEREMAIN:
if (tree) {
guint32 secs_remaining;
proto_tree_add_item(fh_tree, hf_lcp_magic_number, tvb, offset, 4,
ENC_BIG_ENDIAN);
secs_remaining = tvb_get_ntohl(tvb, offset + 4);
proto_tree_add_uint_format_value(fh_tree, hf_lcp_secs_remaining,
tvb, offset + 4, 4, secs_remaining, "%u %s", secs_remaining,
(secs_remaining == 0xffffffff) ? "(forever)" : "seconds");
if (length > 8) {
proto_tree_add_item(fh_tree, hf_lcp_message, tvb, offset + 8,
length - 8, ENC_ASCII|ENC_NA);
}
}
break;
case TERMREQ:
case TERMACK:
case RESETREQ:
case RESETACK:
default:
if (tree && (length > 0)) {
proto_tree_add_item(fh_tree, hf_ppp_data, tvb, offset, length,
ENC_NA);
}
break;
}
}
static void
dissect_ppp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *fh_tree, proto_item *ti, int proto_offset)
{
guint16 ppp_prot;
int proto_len;
tvbuff_t *next_tvb;
if (tree &&
(pinfo->p2p_dir == P2P_DIR_RECV || pinfo->p2p_dir == P2P_DIR_SENT)) {
proto_item *direction_ti = proto_tree_add_uint(tree, hf_ppp_direction,
tvb, 0, 0, pinfo->p2p_dir);
PROTO_ITEM_SET_GENERATED(direction_ti);
}
ppp_prot = tvb_get_guint8(tvb, 0);
if (ppp_prot & PFC_BIT) {
proto_len = 1;
} else {
ppp_prot = tvb_get_ntohs(tvb, 0);
proto_len = 2;
}
if (ti != NULL)
proto_item_set_len(ti, proto_offset + proto_len);
if (tree) {
proto_tree_add_uint(fh_tree, hf_ppp_protocol, tvb, 0, proto_len,
ppp_prot);
}
next_tvb = tvb_new_subset_remaining(tvb, proto_len);
if (!dissector_try_uint(ppp_subdissector_table, ppp_prot, next_tvb, pinfo,
tree)) {
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "0x%04x", ppp_prot);
col_add_fstr(pinfo->cinfo, COL_INFO, "PPP %s (0x%04x)",
val_to_str_ext_const(ppp_prot, &ppp_vals_ext, "Unknown"),
ppp_prot);
call_data_dissector(next_tvb, pinfo, tree);
}
}
static int
dissect_lcp_options(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_ip_tcp_options(tvb, 0, tvb_reported_length(tvb), lcp_opts,
N_LCP_OPTS, -1, &PPP_OPT_TYPES, &ei_ppp_opt_len_invalid, pinfo, tree, NULL, NULL);
return tvb_captured_length(tvb);
}
static int
dissect_lcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_lcp, ett_lcp, lcp_vals, ett_lcp_options, lcp_opts,
N_LCP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_vsncp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
proto_tree *field_tree;
guint8 code;
int length, offset;
code = tvb_get_guint8(tvb, 0);
length = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VSNCP");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(code, cp_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_vsncp, tvb, 0, length, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_vsncp);
proto_tree_add_item(fh_tree, hf_vsncp_code, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_vsncp_identifier, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_vsncp_length, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_ppp_oui, tvb, 4, 3, ENC_BIG_ENDIAN);
}
offset = 7;
length -= 7;
switch (code) {
case CONFREQ:
case CONFACK:
case CONFNAK:
case CONFREJ:
case TERMREQ:
case TERMACK:
if (length > 0) {
field_tree = proto_tree_add_subtree_format(fh_tree, tvb, offset, length,
ett_vsncp_options, NULL, "Options: (%d byte%s)", length,
plurality(length, "", "s"));
dissect_ip_tcp_options(tvb, offset, length, vsncp_opts, N_VSNCP_OPTS, -1, &PPP_OPT_TYPES,
&ei_ppp_opt_len_invalid, pinfo, field_tree, NULL, NULL);
}
break;
default:
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_vsnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *vsnp_item = NULL;
proto_tree *vsnp_tree = NULL;
guint32 offset = 0;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VSNP");
if (tree) {
vsnp_item = proto_tree_add_item(tree, proto_vsnp, tvb, 0, -1, ENC_NA);
vsnp_tree = proto_item_add_subtree(vsnp_item, ett_vsnp);
proto_tree_add_item(vsnp_tree, hf_vsnp_pdnid, tvb, offset, 1,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, 1);
if (!dissector_try_uint(ppp_subdissector_table, PPP_IP, next_tvb, pinfo,
tree)) {
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "0x%04x", PPP_IP);
col_add_fstr(pinfo->cinfo, COL_INFO, "PPP %s (0x%04x)",
val_to_str_ext_const(PPP_IP, &ppp_vals_ext, "Unknown"), PPP_IP);
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_ipcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_ipcp, ett_ipcp, cp_vals, ett_ipcp_options, ipcp_opts,
N_IPCP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_bcp_bpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *bcp_bpdu_tree;
int offset = 0;
guint8 flags;
guint8 mac_type;
gint captured_length, reported_length, pad_length;
tvbuff_t *next_tvb;
static const int * bcp_bpdu_flags[] = {
&hf_bcp_bpdu_fcs_present,
&hf_bcp_bpdu_zeropad,
&hf_bcp_bpdu_bcontrol,
&hf_bcp_bpdu_pads,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP BCP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_bcp_bpdu, tvb, 0, -1, ENC_NA);
bcp_bpdu_tree = proto_item_add_subtree(ti, ett_bcp_bpdu);
flags = tvb_get_guint8(tvb, offset);
if (flags & BCP_IS_BCONTROL) {
col_set_str(pinfo->cinfo, COL_INFO, "Bridge control");
}
proto_tree_add_bitmask(bcp_bpdu_tree, tvb, offset, hf_bcp_bpdu_flags, ett_bcp_bpdu_flags, bcp_bpdu_flags, ENC_NA);
offset++;
mac_type = tvb_get_guint8(tvb, offset);
if (!(flags & BCP_IS_BCONTROL)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(mac_type, bcp_bpdu_mac_type_vals,
"Unknown MAC type %u"));
}
proto_tree_add_uint(bcp_bpdu_tree, hf_bcp_bpdu_mac_type, tvb, offset, 1, mac_type);
offset++;
switch (mac_type) {
case BCP_MACT_802_4:
case BCP_MACT_802_5_NONCANON:
case BCP_MACT_FDDI_NONCANON:
case BCP_MACT_802_5_CANON:
case BCP_MACT_FDDI_CANON:
proto_tree_add_item(bcp_bpdu_tree, hf_bcp_bpdu_pad, tvb, offset, 1, ENC_NA);
offset++;
break;
default:
break;
}
if (!(flags & BCP_IS_BCONTROL)) {
captured_length = tvb_captured_length_remaining(tvb, offset);
reported_length = tvb_reported_length_remaining(tvb, offset);
pad_length = flags & BCP_PADS_MASK;
if (reported_length >= pad_length) {
reported_length -= pad_length;
if (captured_length > reported_length)
captured_length = reported_length;
next_tvb = tvb_new_subset(tvb, offset, captured_length,
reported_length);
switch (mac_type) {
case BCP_MACT_ETHERNET:
if (flags & BCP_FCS_PRESENT) {
call_dissector(eth_withfcs_handle, next_tvb, pinfo, tree);
} else {
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo,
tree);
}
break;
case BCP_MACT_802_4:
case BCP_MACT_802_5_NONCANON:
case BCP_MACT_FDDI_NONCANON:
case BCP_MACT_802_5_CANON:
case BCP_MACT_FDDI_CANON:
break;
default:
call_data_dissector(next_tvb, pinfo, tree);
break;
}
}
}
return tvb_captured_length(tvb);
}
static int
dissect_bcp_ncp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_bcp_ncp, ett_bcp_ncp, lcp_vals, ett_bcp_ncp_options,
bcp_ncp_opts, N_BCPLCP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_osinlcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_osinlcp, ett_osinlcp, cp_vals, ett_osinlcp_options,
osinlcp_opts, N_OSINLCP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_ccp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_ccp, ett_ccp, ccp_vals, ett_ccp_options, ccp_opts,
N_CCP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_cbcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_cbcp, ett_cbcp, cbcp_vals, ett_cbcp_options,
cbcp_opts, N_CBCP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_bacp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_bacp, ett_bacp, cp_vals, ett_bacp_options, bacp_opts,
N_BACP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_bap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
proto_tree *field_tree;
guint8 type;
int length, offset;
type = tvb_get_guint8(tvb, 0);
length = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP BAP");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(type, bap_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_bap, tvb, 0, length, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_bap_options);
proto_tree_add_item(fh_tree, hf_bap_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_bap_identifier, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_bap_length, tvb, 2, 2, ENC_BIG_ENDIAN);
}
offset = 4;
length -= 4;
if (type == BAP_CRES || type == BAP_CBRES ||
type == BAP_LDQRES || type == BAP_CSRES) {
proto_tree_add_item(fh_tree, hf_bap_response_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
if (length > 0) {
field_tree = proto_tree_add_subtree_format(fh_tree, tvb, offset, length,
ett_bap_options, NULL, "Data (%d byte%s)", length, plurality(length, "", "s"));
dissect_ip_tcp_options(tvb, offset, length, bap_opts, N_BAP_OPTS, -1, &PPP_OPT_TYPES,
&ei_ppp_opt_len_invalid, pinfo, field_tree, NULL, NULL);
}
return tvb_captured_length(tvb);
}
static int
dissect_comp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP Comp");
col_set_str(pinfo->cinfo, COL_INFO, "Compressed data");
proto_tree_add_item(tree, proto_comp_data, tvb, 0, -1, ENC_NA);
return tvb_captured_length(tvb);
}
static int
dissect_pppmuxcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_pppmuxcp, ett_pppmuxcp, pppmuxcp_vals,
ett_pppmuxcp_options, pppmuxcp_opts, N_PPPMUXCP_OPTS,pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_pppmux(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *mux_tree, *hdr_tree, *sub_tree;
proto_tree *info_tree;
proto_item *ti = NULL;
guint8 flags, byte;
guint16 length;
static guint16 pid;
tvbuff_t *next_tvb;
int offset = 0, length_remaining;
int length_field = 0, pid_field = 0, hdr_length = 0;
static const int * subframe_flags[] = {
&hf_pppmux_flags_pid,
&hf_pppmux_flags_field_length,
NULL
};
col_set_str(pinfo->cinfo,COL_PROTOCOL, "PPP PPPMux");
col_set_str(pinfo->cinfo, COL_INFO, "PPP Multiplexing");
length_remaining = tvb_reported_length(tvb);
ti = proto_tree_add_item(tree, proto_pppmux, tvb, 0, -1, ENC_NA);
mux_tree = proto_item_add_subtree(ti, ett_pppmux);
while (length_remaining > 0) {
flags = tvb_get_guint8(tvb,offset) & PPPMUX_FLAGS_MASK;
if (flags & PPPMUX_LXT_BIT_SET) {
length = tvb_get_ntohs(tvb,offset) & 0x3fff;
length_field = 2;
} else {
length = tvb_get_guint8(tvb,offset) & 0x3f;
length_field = 1;
}
if (flags & PPPMUX_PFF_BIT_SET) {
byte = tvb_get_guint8(tvb,offset + length_field);
if (byte & PFC_BIT) {
pid = byte;
pid_field = 1;
} else {
pid = tvb_get_ntohs(tvb,offset + length_field);
pid_field = 2;
}
} else {
pid_field = 0;
if (!pid) {
if (pppmux_def_prot_id)
pid = pppmux_def_prot_id;
}
}
hdr_length = length_field + pid_field;
sub_tree = proto_tree_add_subtree(mux_tree, tvb, offset, length + length_field,
ett_pppmux_subframe, NULL, "PPPMux Sub-frame");
hdr_tree = proto_tree_add_subtree(sub_tree, tvb, offset, hdr_length,
ett_pppmux_subframe_hdr, NULL, "Header field");
proto_tree_add_bitmask(tree, tvb, offset, hf_pppmux_flags, ett_pppmux_subframe_flags, subframe_flags, ENC_BIG_ENDIAN);
proto_tree_add_uint(hdr_tree, hf_pppmux_sub_frame_length, tvb,offset, length_field, length);
ti = proto_tree_add_uint(hdr_tree, hf_pppmux_protocol, tvb,
offset + length_field, pid_field, pid);
if (!(flags & PPPMUX_PFF_BIT_SET)) {
PROTO_ITEM_SET_GENERATED(ti);
}
offset += hdr_length;
length_remaining -= hdr_length;
length -= pid_field;
tvb_ensure_bytes_exist (tvb, offset, length);
info_tree = proto_tree_add_subtree(sub_tree, tvb,offset, length,
ett_pppmux_subframe_info, NULL, "Information Field");
next_tvb = tvb_new_subset_length(tvb, offset, length);
if (!dissector_try_uint(ppp_subdissector_table, pid, next_tvb, pinfo,
info_tree)) {
call_data_dissector(next_tvb, pinfo, info_tree);
}
offset += length;
length_remaining -= length;
}
return tvb_captured_length(tvb);
}
static int
dissect_iphc_crtp_fh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *fh_tree = NULL, *info_tree;
proto_item *ti = NULL;
guint ip_hdr_len, flags, seq;
guint length;
guint hdr_len;
tvbuff_t *next_tvb;
int offset_seq;
int offset_cid;
guint8 ip_version;
guint8 next_protocol;
guchar *ip_packet;
length = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo,COL_PROTOCOL, "CRTP");
col_set_str(pinfo->cinfo, COL_INFO, "Full Header");
ip_version = tvb_get_guint8(tvb, 0) >> 4;
flags = (tvb_get_guint8(tvb, 2) & IPHC_CRTP_FH_FLAG_MASK);
next_protocol = tvb_get_guint8(tvb, 9);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_iphc_crtp, tvb, 0, -1,
"%s", val_to_str_ext_const(PPP_RTP_FH, &ppp_vals_ext, "Unknown"));
fh_tree = proto_item_add_subtree(ti, ett_iphc_crtp);
proto_tree_add_bitmask_with_flags(fh_tree, tvb, 2, hf_iphc_crtp_fh_flags,
ett_iphc_crtp_fh_flags, iphc_crtp_fh_flags_fields, ENC_BIG_ENDIAN,
BMT_NO_FLAGS);
proto_tree_add_item(fh_tree, hf_iphc_crtp_gen, tvb, 2, 1,
ENC_BIG_ENDIAN);
}
ip_hdr_len = (tvb_get_guint8(tvb, 0) & 0x0f) * 4;
hdr_len = ip_hdr_len + 8;
if (ip_version != 4) {
proto_tree_add_expert_format(fh_tree, pinfo, &ei_iphc_crtp_ip_version, tvb, 3, -1,
"IP version is %u: the only supported version is 4",
ip_version);
return 1;
}
if (next_protocol != IP_PROTO_UDP) {
proto_tree_add_expert_format(fh_tree, pinfo, &ei_iphc_crtp_next_protocol, tvb, 3, -1,
"Next protocol is %s (%u): the only supported protocol is UDP",
ipprotostr(next_protocol), next_protocol);
return 1;
}
if (flags & IPHC_CRTP_FH_CIDLEN_FLAG) {
offset_seq = 3;
offset_cid = ip_hdr_len + 4;
if (flags & IPHC_CRTP_FH_DATA_FLAG) {
proto_tree_add_item(fh_tree, hf_iphc_crtp_seq, tvb, offset_seq, 1,
ENC_BIG_ENDIAN);
} else {
seq = tvb_get_guint8(tvb, offset_seq);
if (seq != 0) {
ti = proto_tree_add_item(fh_tree, hf_iphc_crtp_seq, tvb, offset_seq,
1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, ti, &ei_iphc_crtp_seq_nonzero);
}
}
proto_tree_add_item(fh_tree, hf_iphc_crtp_cid16, tvb, offset_cid,
2, ENC_BIG_ENDIAN);
} else {
offset_cid = 3;
offset_seq = ip_hdr_len + 5;
proto_tree_add_item(fh_tree, hf_iphc_crtp_cid8, tvb, offset_cid, 1,
ENC_BIG_ENDIAN);
if (flags & IPHC_CRTP_FH_DATA_FLAG) {
proto_tree_add_item(fh_tree, hf_iphc_crtp_seq, tvb, offset_seq, 1,
ENC_BIG_ENDIAN);
} else {
seq = tvb_get_guint8(tvb, offset_seq);
if (seq != 0) {
ti = proto_tree_add_item(fh_tree, hf_iphc_crtp_seq, tvb, offset_seq,
1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, ti, &ei_iphc_crtp_seq_nonzero);
}
}
}
info_tree = proto_tree_add_subtree(fh_tree, tvb, 0, length, ett_iphc_crtp_info, NULL, "Information Field");
tvb_ensure_bytes_exist (tvb, 0, hdr_len);
ip_packet = (guchar *)tvb_memdup(pinfo->pool, tvb, 0, length);
ip_packet[2] = length >> 8;
ip_packet[3] = length;
ip_packet[ip_hdr_len + 4] = (length - ip_hdr_len) >> 8;
ip_packet[ip_hdr_len + 5] = (length - ip_hdr_len);
next_tvb = tvb_new_child_real_data(tvb, ip_packet, length, length);
add_new_data_source(pinfo, next_tvb, "Decompressed Data");
if (!dissector_try_uint(ppp_subdissector_table, PPP_IP, next_tvb, pinfo,
info_tree)) {
call_data_dissector(next_tvb, pinfo, info_tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_iphc_crtp_cudp16(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *cudp_tree;
proto_item *ti = NULL;
guint length;
guint hdr_length;
int offset = 0;
col_set_str(pinfo->cinfo,COL_PROTOCOL, "CRTP");
col_set_str(pinfo->cinfo, COL_INFO, "Compressed UDP 16");
length = tvb_reported_length(tvb);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_iphc_crtp, tvb, 0, -1,
"%s",
val_to_str_ext_const(PPP_RTP_CUDP16, &ppp_vals_ext, "Unknown"));
cudp_tree = proto_item_add_subtree(ti, ett_iphc_crtp);
hdr_length = 3;
proto_tree_add_item(cudp_tree, hf_iphc_crtp_cid16, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(cudp_tree, hf_iphc_crtp_seq, tvb, 2, 1,
ENC_BIG_ENDIAN);
offset += hdr_length;
length -= hdr_length;
proto_tree_add_item(cudp_tree, hf_iphc_crtp_data, tvb, offset, length, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_iphc_crtp_cudp8(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *cudp_tree;
proto_item *ti = NULL;
guint length;
guint hdr_length;
int offset = 0;
col_set_str(pinfo->cinfo,COL_PROTOCOL, "CRTP");
col_set_str(pinfo->cinfo, COL_INFO, "Compressed UDP 8");
length = tvb_reported_length(tvb);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_iphc_crtp, tvb, 0, -1,
"%s",
val_to_str_ext_const(PPP_RTP_CUDP8, &ppp_vals_ext, "Unknown"));
cudp_tree = proto_item_add_subtree(ti, ett_iphc_crtp);
hdr_length = 2;
proto_tree_add_item(cudp_tree, hf_iphc_crtp_cid8, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(cudp_tree, hf_iphc_crtp_seq, tvb, 1, 1,
ENC_BIG_ENDIAN);
offset += hdr_length;
length -= hdr_length;
proto_tree_add_item(cudp_tree, hf_iphc_crtp_data, tvb, offset, length, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_iphc_crtp_cs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *cs_tree;
proto_item *ti = NULL;
guint8 flags, cnt;
guint length, cid_size;
guint offset = 2, hf;
col_set_str(pinfo->cinfo,COL_PROTOCOL, "CRTP");
col_set_str(pinfo->cinfo, COL_INFO, "Context State");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_iphc_crtp, tvb, 0, -1,
"%s", val_to_str_ext_const(PPP_RTP_CS, &ppp_vals_ext, "Unknown"));
cs_tree = proto_item_add_subtree(ti, ett_iphc_crtp);
proto_tree_add_item(cs_tree, hf_iphc_crtp_cs_flags, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(cs_tree, hf_iphc_crtp_cs_cnt, tvb, 1, 1,
ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, 0);
cnt = tvb_get_guint8(tvb, 1);
if (flags == IPHC_CRTP_CS_CID8) {
hf = hf_iphc_crtp_cid8;
cid_size = 1;
length = 3 * cnt;
} else {
hf = hf_iphc_crtp_cid16;
cid_size = 2;
length = 4 * cnt;
}
while (offset < length) {
proto_tree_add_item(cs_tree, hf, tvb, offset, cid_size,
ENC_BIG_ENDIAN);
offset += cid_size;
proto_tree_add_item(cs_tree, hf_iphc_crtp_cs_invalid, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(cs_tree, hf_iphc_crtp_seq, tvb, offset, 1,
ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(cs_tree, hf_iphc_crtp_gen, tvb, offset, 1,
ENC_BIG_ENDIAN);
++offset;
}
}
return tvb_captured_length(tvb);
}
static int
dissect_iphc_crtp_cntcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *cntcp_tree;
proto_item *ti = NULL;
guint length, flags;
guint hdr_length;
int offset = 0;
col_set_str(pinfo->cinfo,COL_PROTOCOL, "CRTP");
col_set_str(pinfo->cinfo, COL_INFO, "Compressed Non TCP");
length = tvb_reported_length(tvb);
flags = (tvb_get_guint8(tvb, 1) & IPHC_CRTP_FH_FLAG_MASK);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_iphc_crtp, tvb, 0, -1,
"%s",
val_to_str_ext_const(PPP_RTP_CNTCP, &ppp_vals_ext, "Unknown"));
cntcp_tree = proto_item_add_subtree(ti, ett_iphc_crtp);
if (flags & IPHC_CRTP_FH_CIDLEN_FLAG) {
hdr_length = 3;
proto_tree_add_split_bits_item_ret_val(cntcp_tree, hf_iphc_crtp_cid16, tvb, 0,
iphc_crtp_cntcp_cid16_crumbs, NULL);
} else {
hdr_length = 2;
proto_tree_add_item(cntcp_tree, hf_iphc_crtp_cid8, tvb, 0, 1,
ENC_BIG_ENDIAN);
}
proto_tree_add_bitmask_with_flags(cntcp_tree, tvb, 1, hf_iphc_crtp_fh_flags,
ett_iphc_crtp_fh_flags, iphc_crtp_fh_flags_fields, ENC_BIG_ENDIAN,
BMT_NO_FLAGS);
proto_tree_add_item(cntcp_tree, hf_iphc_crtp_gen, tvb, 1, 1,
ENC_BIG_ENDIAN);
if (flags & IPHC_CRTP_FH_DATA_FLAG) {
proto_tree_add_item(cntcp_tree, hf_iphc_crtp_seq, tvb, hdr_length++,
1, ENC_BIG_ENDIAN);
}
offset += hdr_length;
length -= hdr_length;
proto_tree_add_item(cntcp_tree, hf_iphc_crtp_ip_id, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(cntcp_tree, hf_iphc_crtp_data, tvb, offset, length, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_mplscp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_mplscp, ett_mplscp, cp_vals, ett_mplscp_options,
NULL, 0, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_cdpcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_cdpcp, ett_cdpcp, cp_vals, ett_cdpcp_options, NULL,
0, pinfo, tree);
return tvb_captured_length(tvb);
}
static int
dissect_mp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *mp_tree;
proto_item *ti;
gint hdrlen;
tvbuff_t *next_tvb;
static const int * mp_flags[] = {
&hf_mp_frag_first,
&hf_mp_frag_last,
&hf_mp_sequence_num_reserved,
NULL
};
static const int * mp_short_flags[] = {
&hf_mp_frag_first,
&hf_mp_frag_last,
&hf_mp_short_sequence_num_reserved,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP MP");
col_set_str(pinfo->cinfo, COL_INFO, "PPP Multilink");
ti = proto_tree_add_item(tree, proto_mp, tvb, 0,
mp_short_seqno ? 2 : 4, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_mp);
if (mp_short_seqno) {
proto_tree_add_bitmask(mp_tree, tvb, 0, hf_mp_frag, ett_mp_flags, mp_short_flags, ENC_NA);
proto_tree_add_item(mp_tree, hf_mp_short_sequence_num, tvb, 0, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_bitmask(mp_tree, tvb, 0, hf_mp_frag, ett_mp_flags, mp_flags, ENC_NA);
proto_tree_add_item(mp_tree, hf_mp_sequence_num, tvb, 1, 3,
ENC_BIG_ENDIAN);
}
hdrlen = mp_short_seqno ? 2 : 4;
if (tvb_reported_length_remaining(tvb, hdrlen) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, hdrlen);
dissect_ppp(next_tvb, pinfo, tree, NULL);
}
return tvb_captured_length(tvb);
}
static int
dissect_ppp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *fh_tree;
ti = proto_tree_add_item(tree, proto_ppp, tvb, 0, -1, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_ppp);
dissect_ppp_common(tvb, pinfo, tree, fh_tree, ti, 0);
return tvb_captured_length(tvb);
}
static void
dissect_ppp_hdlc_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *fh_tree = NULL;
guint8 byte0;
int proto_offset;
tvbuff_t *next_tvb;
byte0 = tvb_get_guint8(tvb, 0);
if (byte0 == 0xff)
proto_offset = 2;
else {
proto_offset = 0;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ppp, tvb, 0, -1, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_ppp);
if (byte0 == 0xff) {
proto_tree_add_item(fh_tree, hf_ppp_address, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_ppp_control, tvb, 1, 1,
ENC_BIG_ENDIAN);
}
}
next_tvb = decode_fcs(tvb, fh_tree, ppp_fcs_decode, proto_offset);
dissect_ppp_common(next_tvb, pinfo, tree, fh_tree, ti, proto_offset);
}
static int
dissect_ppp_hdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 byte0;
byte0 = tvb_get_guint8(tvb, 0);
if (byte0 == CHDLC_ADDR_UNICAST || byte0 == CHDLC_ADDR_MULTICAST) {
return call_dissector(chdlc_handle, tvb, pinfo, tree);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DTE");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DCE");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DCE");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DTE");
break;
default:
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
break;
}
dissect_ppp_hdlc_common(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static tvbuff_t*
remove_escape_chars(tvbuff_t *tvb, packet_info *pinfo, int offset, int length)
{
guint8 *buff;
int i;
int scanned_len = 0;
guint8 octet;
tvbuff_t *next_tvb;
buff = (guint8 *)wmem_alloc(pinfo->pool, length);
i = 0;
while (scanned_len < length) {
octet = tvb_get_guint8(tvb, offset);
if (octet == 0x7d) {
offset++;
scanned_len++;
if (scanned_len >= length)
break;
octet = tvb_get_guint8(tvb, offset);
buff[i] = octet ^ 0x20;
} else {
buff[i] = octet;
}
offset++;
scanned_len++;
i++;
}
if (i == 0) {
return NULL;
}
next_tvb = tvb_new_child_real_data(tvb, buff, i, i);
return next_tvb;
}
static int
dissect_ppp_raw_hdlc( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ )
{
proto_item *ti;
proto_tree *bs_tree = NULL;
gint offset, end_offset, data_offset;
int length, data_length;
tvbuff_t *ppp_tvb;
gboolean first = TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP");
if (tree) {
ti = proto_tree_add_item(tree, proto_ppp_hdlc, tvb, 0, -1, ENC_NA);
bs_tree = proto_item_add_subtree(ti, ett_ppp_hdlc_data);
}
offset = tvb_find_guint8(tvb, 0, -1, 0x7e);
if (offset == -1) {
col_set_str(pinfo->cinfo, COL_INFO, "PPP Fragment");
proto_tree_add_item(bs_tree, hf_ppp_hdlc_fragment, tvb, offset, -1, ENC_NA);
offset++;
length = tvb_captured_length_remaining(tvb,offset);
ppp_tvb = remove_escape_chars(tvb, pinfo, offset,length);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Fragment");
call_data_dissector(ppp_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
if (offset != 0) {
col_set_str(pinfo->cinfo, COL_INFO, "PPP Fragment");
length = offset;
proto_tree_add_item(bs_tree, hf_ppp_hdlc_fragment, tvb, 0, length, ENC_NA);
if (length != 0) {
ppp_tvb = remove_escape_chars(tvb, pinfo, 0, length - 1);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Fragment");
call_data_dissector(ppp_tvb, pinfo, tree);
}
}
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
end_offset = tvb_find_guint8(tvb, offset + 1, -1, 0x7e);
if (end_offset == -1) {
if (first)
col_set_str(pinfo->cinfo, COL_INFO, "PPP Fragment");
proto_tree_add_item(bs_tree, hf_ppp_hdlc_fragment, tvb, offset, -1, ENC_NA);
offset++;
length = tvb_captured_length_remaining(tvb, offset);
ppp_tvb = remove_escape_chars(tvb, pinfo, offset, length);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Fragment");
call_data_dissector(ppp_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
data_offset = offset + 1;
data_length = end_offset - data_offset;
if (tvb_offset_exists(tvb, end_offset + 1) &&
tvb_get_guint8(tvb, end_offset+1) == 0x7e) {
end_offset++;
}
length = end_offset - offset;
proto_tree_add_item(bs_tree, hf_ppp_hdlc_data, tvb, offset, length, ENC_NA);
if (length > 1) {
ppp_tvb = remove_escape_chars(tvb, pinfo, data_offset, data_length);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Message");
dissect_ppp_hdlc_common(ppp_tvb, pinfo, tree);
first = FALSE;
}
}
offset = end_offset;
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_ppp_usb( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
const guchar buf1[3] = {0x7e, 0xff, 0x03};
const guchar buf2[4] = {0x7e, 0xff, 0x7d, 0x23};
tvbuff_t *next_tvb;
if ((tvb_memeql(tvb, 0, buf2, sizeof(buf2)) == 0) ||
(tvb_memeql(tvb, 0, buf1, sizeof(buf1)) == 0)) {
dissect_ppp_raw_hdlc(tvb, pinfo, tree, data);
} else if ((tvb_memeql(tvb, 0, &buf1[1], sizeof(buf1) - 1) == 0) ||
(tvb_memeql(tvb, 0, &buf2[1], sizeof(buf2) - 1) == 0)) {
if (tvb_get_guint8(tvb, 1) == 0x03)
next_tvb = tvb_new_subset_remaining(tvb, 2);
else
next_tvb = tvb_new_subset_remaining(tvb, 3);
dissect_ppp(next_tvb, pinfo, tree, data);
} else if (tvb_get_guint8(tvb, 0) == 0x7e) {
next_tvb = tvb_new_subset_remaining(tvb, 1);
dissect_ppp_hdlc_common(next_tvb, pinfo, tree);
} else
return (FALSE);
return (TRUE);
}
void
proto_register_ppp_raw_hdlc(void)
{
static hf_register_info hf[] = {
{ &hf_ppp_hdlc_fragment, { "PPP Fragment", "ppp_hdlc.fragment", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_hdlc_data, { "PPP Data", "ppp_hdlc.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ppp_hdlc_data
};
proto_ppp_hdlc = proto_register_protocol("PPP In HDLC-Like Framing",
"PPP-HDLC", "ppp_hdlc");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_ppp_hdlc, hf, array_length(hf));
register_capture_dissector_table("ppp_hdlc", "PPP-HDLC");
}
void
proto_reg_handoff_ppp_raw_hdlc(void)
{
dissector_handle_t ppp_raw_hdlc_handle;
ppp_raw_hdlc_handle = create_dissector_handle(dissect_ppp_raw_hdlc, proto_ppp);
dissector_add_uint("gre.proto", ETHERTYPE_CDMA2000_A10_UBS, ppp_raw_hdlc_handle);
dissector_add_uint("gre.proto", ETHERTYPE_3GPP2, ppp_raw_hdlc_handle);
heur_dissector_add("usb.bulk", dissect_ppp_usb, "PPP USB bulk endpoint", "ppp_usb_bulk", proto_ppp, HEURISTIC_ENABLE);
register_capture_dissector("wtap_encap", WTAP_ENCAP_PPP, capture_ppp_hdlc, proto_ppp_hdlc);
register_capture_dissector("sll.ltype", LINUX_SLL_P_PPPHDLC, capture_ppp_hdlc, proto_ppp_hdlc);
}
static int
dissect_pap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *data_ti;
proto_tree *fh_tree, *data_tree = NULL;
guint8 code;
gchar *peer_id, *password, *message;
guint8 peer_id_length, password_length, message_length;
int offset = 0;
code = tvb_get_guint8(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP PAP");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(code, pap_vals, "Unknown"));
ti = proto_tree_add_item(tree, proto_pap, tvb, 0, -1, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_pap);
proto_tree_add_item(fh_tree, hf_pap_code, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(fh_tree, hf_pap_identifier, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(fh_tree, hf_pap_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
data_ti = proto_tree_add_item(fh_tree, hf_pap_data, tvb, offset, -1,
ENC_NA);
data_tree = proto_item_add_subtree(data_ti, ett_pap_data);
switch (code) {
case CONFREQ:
proto_tree_add_item(data_tree, hf_pap_peer_id_length, tvb, offset,
1, ENC_BIG_ENDIAN);
peer_id_length = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(data_tree, hf_pap_peer_id, tvb, offset,
peer_id_length, ENC_ASCII|ENC_NA);
peer_id = tvb_format_text(tvb, offset, peer_id_length);
offset += peer_id_length;
proto_tree_add_item(data_tree, hf_pap_password_length, tvb, offset,
1, ENC_BIG_ENDIAN);
password_length = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(data_tree, hf_pap_password, tvb, offset,
password_length, ENC_ASCII|ENC_NA);
password = tvb_format_text(tvb, offset, password_length);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Peer-ID='%s', Password='%s')", peer_id, password);
break;
case CONFACK:
case CONFNAK:
proto_tree_add_item(data_tree, hf_pap_message_length, tvb, offset,
1, ENC_BIG_ENDIAN);
message_length = tvb_get_guint8(tvb, offset);
offset +=1;
proto_tree_add_item(data_tree, hf_pap_message, tvb, offset,
message_length, ENC_ASCII|ENC_NA);
message = tvb_format_text(tvb, offset, message_length);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Message='%s')",
message);
break;
default:
proto_tree_add_item(data_tree, hf_pap_stuff, tvb, offset, -1,
ENC_NA);
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_chap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti = NULL;
proto_tree *fh_tree = NULL;
proto_item *tf;
proto_tree *field_tree;
guint8 code, value_size;
guint32 length;
int offset;
code = tvb_get_guint8(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP CHAP");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(code, chap_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_chap, tvb, 0, -1, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_chap);
proto_tree_add_item(fh_tree, hf_chap_code, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_chap_identifier, tvb, 1, 1,
ENC_BIG_ENDIAN);
}
length = tvb_get_ntohs(tvb, 2);
if (length < 4) {
proto_tree_add_uint_format_value(fh_tree, hf_chap_length, tvb, 2, 2,
length, "%u (invalid, must be >= 4)", length);
return 4;
}
proto_item_set_len(ti, length);
if (tree) {
proto_tree_add_item(fh_tree, hf_chap_length, tvb, 2, 2,
ENC_BIG_ENDIAN);
}
offset = 4;
length -= 4;
switch (code) {
case CHAP_CHAL:
case CHAP_RESP:
if (length > 0) {
guint value_offset = 0;
guint name_offset = 0, name_size = 0;
tf = proto_tree_add_item(fh_tree, hf_chap_data, tvb, offset,
length, ENC_NA);
field_tree = proto_item_add_subtree(tf, ett_chap_data);
length--;
value_size = tvb_get_guint8(tvb, offset);
if (value_size > length) {
proto_tree_add_uint_format_value(field_tree, hf_chap_value_size, tvb, offset, 1,
value_size, "%d byte%s (invalid, must be <= %u)",
value_size, plurality(value_size, "", "s"), length);
return offset;
}
proto_tree_add_item(field_tree, hf_chap_value_size, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
if (length > 0) {
value_offset = offset;
proto_tree_add_item(field_tree, hf_chap_value, tvb, offset,
value_size, ENC_NA);
offset += value_size;
length -= value_size;
if (length > 0) {
proto_tree_add_item(field_tree, hf_chap_name, tvb,
offset, length, ENC_ASCII|ENC_NA);
name_offset = offset;
name_size = length;
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" (NAME='%s%s', VALUE=0x%s)",
tvb_format_text(tvb, name_offset,
(name_size > 20) ? 20 : name_size),
(name_size > 20) ? "..." : "",
tvb_bytes_to_str(wmem_packet_scope(), tvb, value_offset, value_size));
}
}
break;
case CHAP_SUCC:
case CHAP_FAIL:
if (tree) {
if (length > 0) {
proto_tree_add_item(fh_tree, hf_chap_message, tvb, offset,
length, ENC_ASCII|ENC_NA);
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (MESSAGE='%s')",
tvb_format_text(tvb, offset, length));
break;
default:
if (length > 0)
proto_tree_add_item(fh_tree, hf_chap_stuff, tvb, offset, length, ENC_NA);
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_ipv6cp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_cp(tvb, proto_ipv6cp, ett_ipv6cp, cp_vals, ett_ipv6cp_options,
ipv6cp_opts, N_IPV6CP_OPTS, pinfo, tree);
return tvb_captured_length(tvb);
}
static void
dissect_ipv6cp_if_id_opt(const ip_tcp_opt *optp _U_, tvbuff_t *tvb, int offset,
guint length _U_, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_item(tree, hf_ipv6cp_interface_identifier, tvb, offset+2, 8, ENC_NA);
}
void
proto_register_ppp(void)
{
static hf_register_info hf[] = {
{ &hf_ppp_direction,
{ "Direction", "ppp.direction", FT_UINT8, BASE_DEC,
VALS(ppp_direction_vals), 0x0, "PPP direction", HFILL }},
{ &hf_ppp_address,
{ "Address", "ppp.address", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_control,
{ "Control", "ppp.control", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_protocol,
{ "Protocol", "ppp.protocol", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&ppp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_ppp_code,
{ "Code", "ppp.code", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_identifier,
{ "Identifier", "ppp.identifier", FT_UINT8, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_length,
{ "Length", "ppp.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_magic_number,
{ "Magic Number", "ppp.magic_number", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_oui,
{ "OUI", "ppp.oui", FT_UINT24, BASE_HEX,
VALS(oui_vals), 0x0, NULL, HFILL }},
{ &hf_ppp_kind,
{ "Kind", "ppp.kind", FT_UINT8, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_data,
{ "Data", "ppp.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_opt_type,
{ "Type", "ppp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_ppp_opt_type_copy,
{ "Copy on fragmentation", "ppp.opt.type.copy", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), IPOPT_COPY_MASK, NULL, HFILL}},
{ &hf_ppp_opt_type_class,
{ "Class", "ppp.opt.type.class", FT_UINT8, BASE_DEC,
VALS(ipopt_type_class_vals), IPOPT_CLASS_MASK, NULL, HFILL}},
{ &hf_ppp_opt_type_number,
{ "Number", "ppp.opt.type.number", FT_UINT8, BASE_DEC,
VALS(ipopt_type_number_vals), IPOPT_NUMBER_MASK, NULL, HFILL}},
{ &hf_ppp_fcs_16, { "FCS 16", "ppp.fcs_16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ppp_fcs_32, { "FCS 32", "ppp.fcs_32", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ppp,
&ett_ppp_opt_type
};
static ei_register_info ei[] = {
{ &ei_ppp_opt_len_invalid, { "ppp.opt.len.invalid", PI_PROTOCOL, PI_WARN, "Invalid length for option", EXPFILL }},
};
module_t *ppp_module;
expert_module_t* expert_ppp;
proto_ppp = proto_register_protocol("Point-to-Point Protocol", "PPP",
"ppp");
proto_register_field_array(proto_ppp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ppp = expert_register_protocol(proto_ppp);
expert_register_field_array(expert_ppp, ei, array_length(ei));
ppp_subdissector_table = register_dissector_table("ppp.protocol",
"PPP protocol", proto_ppp, FT_UINT16, BASE_HEX);
register_dissector("ppp_hdlc", dissect_ppp_hdlc, proto_ppp);
register_dissector("ppp_lcp_options", dissect_lcp_options, proto_ppp);
register_dissector("ppp", dissect_ppp, proto_ppp);
ppp_module = prefs_register_protocol(proto_ppp, NULL);
prefs_register_enum_preference(ppp_module, "fcs_type",
"PPP Frame Checksum Type",
"The type of PPP frame checksum (none, 16-bit, 32-bit)",
&ppp_fcs_decode, fcs_options, FALSE);
prefs_register_obsolete_preference(ppp_module, "decompress_vj");
prefs_register_uint_preference(ppp_module, "default_proto_id",
"PPPMuxCP Default PID (in hex)",
"Default Protocol ID to be used for PPPMuxCP",
16, &pppmux_def_prot_id);
}
void
proto_reg_handoff_ppp(void)
{
dissector_handle_t ppp_hdlc_handle, ppp_handle;
chdlc_handle = find_dissector_add_dependency("chdlc", proto_ppp);
ppp_handle = find_dissector("ppp");
dissector_add_uint("fr.nlpid", NLPID_PPP, ppp_handle);
ppp_hdlc_handle = find_dissector("ppp_hdlc");
dissector_add_uint("wtap_encap", WTAP_ENCAP_PPP, ppp_hdlc_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_PPP_WITH_PHDR,
ppp_hdlc_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_PPPHDLC, ppp_hdlc_handle);
dissector_add_uint("osinl.excl", NLPID_PPP, ppp_handle);
dissector_add_uint("gre.proto", ETHERTYPE_PPP, ppp_hdlc_handle);
dissector_add_uint("juniper.proto", JUNIPER_PROTO_PPP, ppp_handle);
dissector_add_uint("sflow_245.header_protocol", SFLOW_245_HEADER_PPP, ppp_hdlc_handle);
dissector_add_uint("l2tp.pw_type", L2TPv3_PROTOCOL_PPP, ppp_hdlc_handle);
}
void
proto_register_mp(void)
{
static hf_register_info hf[] = {
{ &hf_mp_frag,
{ "Fragment", "mp.frag", FT_UINT8, BASE_HEX,
VALS(mp_frag_vals), MP_FRAG_MASK, NULL, HFILL }},
{ &hf_mp_frag_first,
{ "First fragment", "mp.first", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), MP_FRAG_FIRST, NULL, HFILL }},
{ &hf_mp_frag_last,
{ "Last fragment", "mp.last", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), MP_FRAG_LAST, NULL, HFILL }},
{ &hf_mp_sequence_num,
{ "Sequence number", "mp.seq", FT_UINT24, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_mp_sequence_num_reserved,
{ "Reserved", "mp.sequence_num_reserved", FT_BOOLEAN, 8,
NULL, MP_FRAG_RESERVED, NULL, HFILL }},
{ &hf_mp_short_sequence_num,
{ "Short Sequence number", "mp.sseq", FT_UINT16, BASE_DEC,
NULL, 0x0FFF, NULL, HFILL }},
{ &hf_mp_short_sequence_num_reserved,
{ "Reserved", "mp.short_sequence_num_reserved", FT_BOOLEAN, 8,
NULL, MP_FRAG_RESERVED_SHORT, NULL, HFILL }},
};
static gint *ett[] = {
&ett_mp,
&ett_mp_flags
};
module_t *mp_module;
proto_mp = proto_register_protocol("PPP Multilink Protocol", "PPP MP",
"mp");
proto_register_field_array(proto_mp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mp_module = prefs_register_protocol(proto_mp, NULL);
prefs_register_bool_preference(mp_module, "short_seqno",
"Short sequence numbers",
"Whether PPP Multilink frames use 12-bit sequence numbers",
&mp_short_seqno);
}
void
proto_reg_handoff_mp(void)
{
dissector_handle_t mp_handle;
mp_handle = create_dissector_handle(dissect_mp, proto_mp);
dissector_add_uint("ppp.protocol", PPP_MP, mp_handle);
}
void
proto_register_lcp(void)
{
static hf_register_info hf[] = {
{ &hf_lcp_magic_number,
{ "Magic Number", "lcp.magic_number", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_data,
{ "Data", "lcp.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_message,
{ "Message", "lcp.message", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_secs_remaining,
{ "Seconds Remaining", "lcp.secs_remaining", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_rej_proto,
{ "Rejected Protocol", "lcp.rej_proto", FT_UINT16,
BASE_HEX | BASE_EXT_STRING, &ppp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_type,
{ "Type", "lcp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_length,
{ "Length", "lcp.opt.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_oui,
{ "OUI", "lcp.opt.oui", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_kind,
{ "Kind", "lcp.opt.kind", FT_UINT8, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_data,
{ "Data", "lcp.opt.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_mru,
{ "Maximum Receive Unit", "lcp.opt.mru", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap,
{ "Async Control Character Map", "lcp.opt.asyncmap", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_nul,
{ "NUL", "lcp.opt.asyncmap.nul", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_soh,
{ "SOH", "lcp.opt.asyncmap.soh", FT_BOOLEAN, 32,
NULL, 0x00000002, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_stx,
{ "STX", "lcp.opt.asyncmap.stx", FT_BOOLEAN, 32,
NULL, 0x00000004, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_etx,
{ "ETX", "lcp.opt.asyncmap.etx", FT_BOOLEAN, 32,
NULL, 0x00000008, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_eot,
{ "EOT", "lcp.opt.asyncmap.eot", FT_BOOLEAN, 32,
NULL, 0x00000010, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_enq,
{ "ENQ", "lcp.opt.asyncmap.enq", FT_BOOLEAN, 32,
NULL, 0x00000020, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_ack,
{ "ACK", "lcp.opt.asyncmap.ack", FT_BOOLEAN, 32,
NULL, 0x00000040, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_bel,
{ "BEL", "lcp.opt.asyncmap.bel", FT_BOOLEAN, 32,
NULL, 0x00000080, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_bs,
{ "BS", "lcp.opt.asyncmap.bs", FT_BOOLEAN, 32,
NULL, 0x00000100, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_ht,
{ "HT", "lcp.opt.asyncmap.ht", FT_BOOLEAN, 32,
NULL, 0x00000200, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_lf,
{ "LF", "lcp.opt.asyncmap.lf", FT_BOOLEAN, 32,
NULL, 0x00000400, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_vt,
{ "VT", "lcp.opt.asyncmap.vt", FT_BOOLEAN, 32,
NULL, 0x00000800, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_ff,
{ "FF", "lcp.opt.asyncmap.ff", FT_BOOLEAN, 32,
NULL, 0x00001000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_cr,
{ "CR", "lcp.opt.asyncmap.cr", FT_BOOLEAN, 32,
NULL, 0x00002000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_so,
{ "SO", "lcp.opt.asyncmap.so", FT_BOOLEAN, 32,
NULL, 0x00004000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_si,
{ "SI", "lcp.opt.asyncmap.si", FT_BOOLEAN, 32,
NULL, 0x00008000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_dle,
{ "DLE", "lcp.opt.asyncmap.dle", FT_BOOLEAN, 32,
NULL, 0x00010000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_dc1,
{ "DC1 (XON)", "lcp.opt.asyncmap.dc1", FT_BOOLEAN, 32,
NULL, 0x00020000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_dc2,
{ "DC2", "lcp.opt.asyncmap.dc2", FT_BOOLEAN, 32,
NULL, 0x00040000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_dc3,
{ "DC3 (XOFF)", "lcp.opt.asyncmap.dc3", FT_BOOLEAN, 32,
NULL, 0x00080000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_dc4,
{ "DC4", "lcp.opt.asyncmap.dc4", FT_BOOLEAN, 32,
NULL, 0x00100000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_nak,
{ "NAK", "lcp.opt.asyncmap.nak", FT_BOOLEAN, 32,
NULL, 0x00200000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_syn,
{ "SYN", "lcp.opt.asyncmap.syn", FT_BOOLEAN, 32,
NULL, 0x00400000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_etb,
{ "ETB", "lcp.opt.asyncmap.etb", FT_BOOLEAN, 32,
NULL, 0x00800000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_can,
{ "CAN", "lcp.opt.asyncmap.can", FT_BOOLEAN, 32,
NULL, 0x01000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_em,
{ "EM", "lcp.opt.asyncmap.em", FT_BOOLEAN, 32,
NULL, 0x02000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_sub,
{ "SUB", "lcp.opt.asyncmap.sub", FT_BOOLEAN, 32,
NULL, 0x04000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_esc,
{ "ESC", "lcp.opt.asyncmap.esc", FT_BOOLEAN, 32,
NULL, 0x08000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_fs,
{ "FS", "lcp.opt.asyncmap.fs", FT_BOOLEAN, 32,
NULL, 0x10000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_gs,
{ "GS", "lcp.opt.asyncmap.gs", FT_BOOLEAN, 32,
NULL, 0x20000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_rs,
{ "RS", "lcp.opt.asyncmap.rs", FT_BOOLEAN, 32,
NULL, 0x40000000, NULL, HFILL }},
{ &hf_lcp_opt_asyncmap_us,
{ "US", "lcp.opt.asyncmap.us", FT_BOOLEAN, 32,
NULL, 0x80000000, NULL, HFILL }},
{ &hf_lcp_opt_auth_protocol,
{ "Authentication Protocol", "lcp.opt.auth_protocol", FT_UINT16,
BASE_HEX | BASE_EXT_STRING, &ppp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_algorithm,
{ "Algorithm", "lcp.opt.algorithm", FT_UINT8,
BASE_DEC | BASE_RANGE_STRING, &chap_alg_rvals,
0x0, NULL, HFILL }},
{ &hf_lcp_opt_quality_protocol,
{ "Quality Protocol", "lcp.opt.quality_protocol", FT_UINT16,
BASE_HEX | BASE_EXT_STRING, &ppp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_magic_number,
{ "Magic Number", "lcp.opt.magic_number", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_reportingperiod,
{ "Reporting Period", "lcp.opt.reporting_period", FT_UINT32,
BASE_DEC, NULL, 0x0,
"Maximum time in micro-seconds that the remote end should "
"wait between transmission of LCP Link-Quality-Report packets",
HFILL }},
{ &hf_lcp_opt_fcs_alternatives,
{ "FCS Alternatives", "lcp.opt.fcs_alternatives", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_fcs_alternatives_null,
{ "NULL FCS", "lcp.opt.fcs_alternatives.null", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL }},
{ &hf_lcp_opt_fcs_alternatives_ccitt16,
{ "CCITT 16-bit", "lcp.opt.fcs_alternatives.ccitt16", FT_BOOLEAN,
8, NULL, 0x02, NULL, HFILL }},
{ &hf_lcp_opt_fcs_alternatives_ccitt32,
{ "CCITT 32-bit", "lcp.opt.fcs_alternatives.ccitt32", FT_BOOLEAN,
8, NULL, 0x04, NULL, HFILL }},
{ &hf_lcp_opt_maximum,
{ "Maximum", "lcp.opt.maximum", FT_UINT8, BASE_DEC, NULL, 0x0,
"The largest number of padding octets which may be added "
"to the frame.", HFILL }},
{ &hf_lcp_opt_window,
{ "Window", "lcp.opt.window", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of frames the receiver will buffer.", HFILL }},
{ &hf_lcp_opt_hdlc_address,
{ "Address", "lcp.opt.hdlc_address", FT_BYTES, BASE_NONE, NULL,
0x0, "An HDLC Address as specified in ISO 3309.", HFILL }},
{ &hf_lcp_opt_operation,
{ "Operation", "lcp.opt.operation", FT_UINT8, BASE_DEC,
VALS(callback_op_vals), 0x0, NULL, HFILL }},
{ &hf_lcp_opt_message,
{ "Message", "lcp.opt.message", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_mrru,
{ "MRRU", "lcp.opt.mrru", FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum Receive Reconstructed Unit", HFILL }},
{ &hf_lcp_opt_ep_disc_class,
{ "Class", "lcp.opt.ep_disc_class", FT_UINT8, BASE_DEC,
VALS(multilink_ep_disc_class_vals), 0x0, NULL, HFILL }},
{ &hf_lcp_opt_ip_address,
{ "IP Address", "lcp.opt.ip_address", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_802_1_address,
{ "IEEE 802.1 Address", "lcp.opt.802_1_address", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_magic_block,
{ "PPP Magic-Number Block", "lcp.opt.magic_block", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_psndn,
{ "Public Switched Network Directory Number", "lcp.opt.psndn",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_mode,
{ "Mode", "lcp.opt.mode", FT_UINT8, BASE_DEC,
VALS(dce_id_mode_vals), 0x0, NULL, HFILL }},
{ &hf_lcp_opt_unused,
{ "Unused", "lcp.opt.unused", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_link_discrim,
{ "Link Discriminator", "lcp.opt.link_discrim", FT_UINT16,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_id,
{ "Identification", "lcp.opt.id", FT_UINT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_cobs_flags,
{ "Flags", "lcp.opt.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_cobs_flags_res,
{ "Reserved", "lcp.opt.flags.reserved", FT_UINT8, BASE_HEX,
NULL, 0xFC, NULL, HFILL }},
{ &hf_lcp_opt_cobs_flags_pre,
{ "PRE", "lcp.opt.flags.pre", FT_BOOLEAN, 8,
NULL, 0x02, "Preemption", HFILL }},
{ &hf_lcp_opt_cobs_flags_zxe,
{ "ZXE", "lcp.opt.flags.zxe", FT_BOOLEAN, 8,
NULL, 0x01, "Zero pair/run elimination", HFILL }},
{ &hf_lcp_opt_class,
{ "Class", "lcp.opt.class", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_prefix,
{ "Prefix", "lcp.opt.prefix", FT_UINT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_code,
{ "Code", "lcp.opt.code", FT_UINT8, BASE_DEC,
VALS(ml_hdr_fmt_code_vals), 0x0, NULL, HFILL }},
{ &hf_lcp_opt_max_susp_classes,
{ "Max suspendable classes", "lcp.opt.max_susp_classes",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lcp_opt_MIBenum,
{ "MIBenum", "lcp.opt.MIBenum", FT_UINT32,
BASE_DEC | BASE_EXT_STRING, &charset_vals_ext, 0x0,
"A unique integer value identifying a charset", HFILL }},
{ &hf_lcp_opt_language_tag,
{ "Language-Tag", "lcp.opt.language_tag", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_lcp,
&ett_lcp_options,
&ett_lcp_vendor_opt,
&ett_lcp_mru_opt,
&ett_lcp_asyncmap_opt,
&ett_lcp_authprot_opt,
&ett_lcp_qualprot_opt,
&ett_lcp_magicnumber_opt,
&ett_lcp_linkqualmon_opt,
&ett_lcp_pcomp_opt,
&ett_lcp_acccomp_opt,
&ett_lcp_fcs_alternatives_opt,
&ett_lcp_self_desc_pad_opt,
&ett_lcp_numbered_mode_opt,
&ett_lcp_callback_opt,
&ett_lcp_compound_frames_opt,
&ett_lcp_nomdataencap_opt,
&ett_lcp_multilink_mrru_opt,
&ett_lcp_multilink_ssnh_opt,
&ett_lcp_multilink_ep_disc_opt,
&ett_lcp_magic_block,
&ett_lcp_dce_identifier_opt,
&ett_lcp_multilink_pp_opt,
&ett_lcp_bacp_link_discrim_opt,
&ett_lcp_auth_opt,
&ett_lcp_cobs_opt,
&ett_lcp_prefix_elision_opt,
&ett_multilink_hdr_fmt_opt,
&ett_lcp_internationalization_opt,
&ett_lcp_simple_opt
};
proto_lcp = proto_register_protocol("PPP Link Control Protocol", "PPP LCP",
"lcp");
proto_register_field_array(proto_lcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lcp(void)
{
dissector_handle_t lcp_handle;
lcp_handle = create_dissector_handle(dissect_lcp, proto_lcp);
dissector_add_uint("ppp.protocol", PPP_LCP, lcp_handle);
dissector_add_uint("ethertype", PPP_LCP, lcp_handle);
dissector_add_uint("sm_pco.protocol", PPP_LCP, lcp_handle);
}
void
proto_register_vsncp(void)
{
static hf_register_info hf[] = {
{ &hf_vsncp_pdn_identifier, { "PDN Identifier", "vsncp.pdn_identifier", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_attach_type, { "Attach Type", "vsncp.attach_type", FT_UINT8, BASE_HEX, VALS(vsncp_attach_vals), 0x0, NULL, HFILL }},
{ &hf_vsncp_pdn_type, { "PDN Type", "vsncp.pdn_type", FT_UINT8, BASE_HEX, VALS(vsncp_pdntype_vals), 0x0, NULL, HFILL }},
{ &hf_vsncp_error_code, { "Error Code", "vsncp.error_code", FT_UINT8, BASE_HEX, VALS(vsncp_errorcode_vals), 0x0, NULL, HFILL }},
{ &hf_vsncp_pdn_ipv4, { "PDN IPv4", "vsncp.pdn_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_pdn_ipv6, { "PDN IPv6", "vsncp.pdn_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_default_router_address, { "IPv4 Default Router Address", "vsncp.default_router_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_access_point_name, { "Access Point Name Label", "vsncp.access_point_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_address_allocation_cause, { "Address Allocation Cause", "vsncp.address_allocation_cause", FT_UINT8, BASE_HEX, VALS(vsncp_alloc_vals), 0x0, NULL, HFILL }},
{ &hf_vsncp_ambr_data, { "AMBR Data", "vsncp.ambr_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_ipv6_interface_identifier, { "IPv6 interface identifier", "vsncp.ipv6_interface_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_protocol, { "Protocol", "vsncp.protocol", FT_UINT16, BASE_HEX, VALS(vsncp_pco_vals), 0x0, NULL, HFILL }},
{ &hf_vsncp_protocol_configuration_length, { "Length", "vsncp.protocol_configuration_length", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_protocol_configuration_data, { "Data", "vsncp.protocol_configuration_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_code, { "Code", "vsncp.code", FT_UINT8, BASE_HEX, VALS(cp_vals), 0x0, NULL, HFILL }},
{ &hf_vsncp_identifier, { "Identifier", "vsncp.identifier", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_vsncp_length, { "Length", "vsncp.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_vsncp,
&ett_vsncp_options
};
proto_vsncp = proto_register_protocol("Vendor Specific Control Protocol",
"VSNCP", "vsncp");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_vsncp, hf, array_length(hf));
}
void
proto_reg_handoff_vsncp(void)
{
dissector_handle_t vsncp_handle;
vsncp_handle = create_dissector_handle(dissect_vsncp, proto_vsncp);
dissector_add_uint("ppp.protocol", PPP_VSNCP, vsncp_handle);
}
void
proto_register_vsnp(void)
{
static gint *ett[] = {
&ett_vsnp
};
static hf_register_info hf[] = {
{ &hf_vsnp_pdnid,
{ "PDN ID", "vsnp.pdnid", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }}
};
proto_vsnp = proto_register_protocol("Vendor Specific Network Protocol",
"PPP VSNP", "vsnp");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_vsnp, hf, array_length(hf));
}
void
proto_reg_handoff_vsnp(void)
{
dissector_handle_t vsnp_handle;
vsnp_handle = create_dissector_handle(dissect_vsnp, proto_vsnp);
dissector_add_uint("ppp.protocol", PPP_VSNP, vsnp_handle);
}
void
proto_register_ipcp(void)
{
static hf_register_info hf[] = {
{ &hf_ipcp_opt_type,
{ "Type", "ipcp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_length,
{ "Length", "ipcp.opt.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_src_address,
{ "Source IP Address", "ipcp.opt.src_address", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_dst_address,
{ "Destination IP Address", "ipcp.opt.dst_address", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_compress_proto,
{ "IP Compression Protocol", "ipcp.opt.compress_proto", FT_UINT16,
BASE_HEX, VALS(ipcp_compress_proto_vals), 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_max_cid,
{ "Max CID", "ipcp.opt.max_cid", FT_UINT16, BASE_DEC,
NULL, 0x0, "Maximum value of a context identifier", HFILL }},
{ &hf_ipcp_opt_mrru,
{ "MRRU", "ipcp.opt.mrru", FT_UINT16, BASE_DEC,
NULL, 0x0, "Maximum Reconstructed Reception Unit", HFILL }},
{ &hf_ipcp_opt_max_slot_id,
{ "Max Slot ID", "ipcp.opt.max_slot_id", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_comp_slot_id,
{ "Comp Slot ID", "ipcp.opt.comp_slot_id", FT_BOOLEAN, 8,
TFS(&tfs_comp_slot_id), 0x01, NULL, HFILL }},
{ &hf_ipcp_opt_tcp_space,
{ "TCP Space", "ipcp.opt.tcp_space", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_non_tcp_space,
{ "Non TCP Space", "ipcp.opt.non_tcp_space", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_f_max_period,
{ "F Max Period", "ipcp.opt.f_max_period", FT_UINT16, BASE_DEC,
NULL, 0x0, "Maximum interval between full headers", HFILL }},
{ &hf_ipcp_opt_f_max_time,
{ "F Max Time", "ipcp.opt.f_max_time", FT_UINT16, BASE_DEC, NULL,
0x0, "Maximum time interval between full headers", HFILL }},
{ &hf_ipcp_opt_max_header,
{ "Max Header", "ipcp.opt.max_header", FT_UINT16, BASE_DEC, NULL,
0x0,
"The largest header size in octets that may be compressed",
HFILL }},
{ &hf_ipcp_data,
{ "Data", "ipcp.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_ip_address,
{ "IP Address", "ipcp.opt.ip_address", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_mobilenodehomeaddr,
{ "Mobile Node's Home Address", "ipcp.opt.mobilenodehomeaddress",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_pri_dns_address,
{ "Primary DNS Address", "ipcp.opt.pri_dns_address",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_pri_nbns_address,
{ "Primary NBNS Address", "ipcp.opt.pri_nbns_address",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_sec_dns_address,
{ "Secondary DNS Address", "ipcp.opt.sec_dns_address",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_sec_nbns_address,
{ "Secondary NBNS Address", "ipcp.opt.sec_nbns_address",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_rohc_type,
{ "Type", "ipcp.opt.rohc.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_rohc_length,
{ "Length", "ipcp.opt.rohc.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_rohc_profile,
{ "Profile", "ipcp.opt.rohc.profile", FT_UINT16, BASE_HEX,
VALS(ipcp_rohc_profile_vals), 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_iphc_type,
{ "Type", "ipcp.opt.iphc.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_iphc_length,
{ "Length", "ipcp.opt.iphc.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ipcp_opt_iphc_param,
{ "Parameter", "ipcp.opt.iphc.param", FT_UINT8, BASE_DEC,
VALS(ipcp_iphc_parameter_vals), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ipcp,
&ett_ipcp_options,
&ett_ipcp_ipaddrs_opt,
&ett_ipcp_compress_opt,
&ett_ipcp_ipaddr_opt,
&ett_ipcp_mobileipv4_opt,
&ett_ipcp_pridns_opt,
&ett_ipcp_secdns_opt,
&ett_ipcp_prinbns_opt,
&ett_ipcp_secnbns_opt,
&ett_ipcp_iphc_rtp_compress_opt,
&ett_ipcp_iphc_enhanced_rtp_compress_opt,
&ett_ipcp_iphc_neghdrcomp_opt,
&ett_ipcp_rohc_profiles_opt
};
proto_ipcp = proto_register_protocol("PPP IP Control Protocol", "PPP IPCP",
"ipcp");
proto_register_field_array(proto_ipcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipcp(void)
{
dissector_handle_t ipcp_handle;
ipcp_handle = create_dissector_handle(dissect_ipcp, proto_ipcp);
dissector_add_uint("ppp.protocol", PPP_IPCP, ipcp_handle);
dissector_add_uint("ethertype", PPP_IPCP, ipcp_handle);
dissector_add_uint("sm_pco.protocol", PPP_IPCP, ipcp_handle);
}
void
proto_register_bcp_bpdu(void)
{
static hf_register_info hf[] = {
{ &hf_bcp_bpdu_flags,
{ "Flags", "bcp_bpdu.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bcp_bpdu_fcs_present,
{ "LAN FCS present", "bcp_bpdu.flags.fcs_present", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), BCP_FCS_PRESENT, NULL, HFILL }},
{ &hf_bcp_bpdu_zeropad,
{ "802.3 pad zero-filled", "bcp_bpdu.flags.zeropad", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), BCP_ZEROPAD, NULL, HFILL }},
{ &hf_bcp_bpdu_bcontrol,
{ "Bridge control", "bcp_bpdu.flags.bcontrol", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), BCP_IS_BCONTROL, NULL, HFILL }},
{ &hf_bcp_bpdu_pads,
{ "Pads", "bcp_bpdu.pads", FT_UINT8, BASE_DEC,
NULL, BCP_PADS_MASK, NULL, HFILL }},
{ &hf_bcp_bpdu_mac_type,
{ "MAC Type", "bcp_bpdu.mac_type", FT_UINT8, BASE_DEC,
VALS(bcp_bpdu_mac_type_vals), 0x0, NULL, HFILL }},
{ &hf_bcp_bpdu_pad,
{ "Pad", "bcp_bpdu.pad", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_bcp_bpdu,
&ett_bcp_bpdu_flags,
};
proto_bcp_bpdu = proto_register_protocol("PPP Bridging Control Protocol Bridged PDU",
"PPP BCP BPDU", "bcp_bpdu");
proto_register_field_array(proto_bcp_bpdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bcp_bpdu(void)
{
dissector_handle_t bcp_bpdu_handle;
eth_withfcs_handle = find_dissector_add_dependency("eth_withfcs", proto_bcp_bpdu);
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_bcp_bpdu);
bcp_bpdu_handle = create_dissector_handle(dissect_bcp_bpdu, proto_bcp_bpdu);
dissector_add_uint("ppp.protocol", PPP_BCP_BPDU, bcp_bpdu_handle);
}
void
proto_register_bcp_ncp(void)
{
static hf_register_info hf[] = {
{ &hf_bcp_ncp_opt_type,
{ "Type", "bcp_ncp.lcp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_bcp_ncp_opt_length,
{ "Length", "bcp_ncp.lcp.opt.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_bcp_ncp_lan_seg_no,
{ "LAN Segment Number", "bcp_ncp.lcp.lan_seg_no", FT_UINT16, BASE_DEC,
NULL, 0xfff0, NULL, HFILL } },
{ &hf_bcp_ncp_bridge_no,
{ "Bridge Number", "bcp_ncp.lcp.bridge_no", FT_UINT16, BASE_DEC,
NULL, 0x000f, NULL, HFILL } },
{ &hf_bcp_ncp_tinygram_comp,
{ "Tinygram-Compression", "bcp_ncp.lcp.tinygram_comp", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x0, NULL, HFILL } },
{ &hf_bcp_ncp_mac,
{ "MAC Address", "bcp_ncp.lcp.mac_addres", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_bcp_ncp_mac_l,
{ "L bit", "bcp_ncp.lcp.mac_l", FT_UINT48, BASE_HEX,
NULL, G_GUINT64_CONSTANT(0x0200000000), NULL, HFILL } },
{ &hf_bcp_ncp_mac_m,
{ "M bit", "bcp_ncp.lcp.mac_addre", FT_UINT48, BASE_HEX,
NULL, G_GUINT64_CONSTANT(0x0100000000), NULL, HFILL } },
{ &hf_bcp_ncp_stp_prot,
{ "Protocol", "bcp_ncp.lcp.stp_protocol", FT_UINT8, BASE_DEC,
VALS(bcp_ncp_stp_prot_vals), 0x0, NULL, HFILL } },
{ &hf_bcp_ncp_ieee_802_tagged_frame,
{ "IEEE-802-Tagged-Frame", "bcp_ncp.ieee_802_tagged_frame", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_bcp_ncp,
&ett_bcp_ncp_options,
&ett_bcp_ncp_ieee_802_tagged_frame_opt,
&ett_bcp_ncp_management_inline_opt,
&ett_bcp_ncp_bcp_ind_opt,
&ett_bcp_ncp_bridge_id_opt,
&ett_bcp_ncp_line_id_opt,
&ett_bcp_ncp_mac_sup_opt,
&ett_bcp_ncp_tinygram_comp_opt,
&ett_bcp_ncp_lan_id_opt,
&ett_bcp_ncp_mac_addr_opt,
&ett_bcp_ncp_stp_opt
};
proto_bcp_ncp = proto_register_protocol("PPP Bridging Control Protocol Network Control Protocol",
"PPP BCP NCP", "bcp_ncp");
proto_register_field_array(proto_bcp_ncp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bcp_ncp(void)
{
dissector_handle_t bcp_ncp_handle;
bcp_ncp_handle = create_dissector_handle(dissect_bcp_ncp, proto_bcp_ncp);
dissector_add_uint("ppp.protocol", PPP_BCP_NCP, bcp_ncp_handle);
}
void
proto_register_osinlcp(void)
{
static hf_register_info hf[] = {
{ &hf_osinlcp_opt_type,
{ "Type", "osinlcp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_osinlcp_opt_length,
{ "Length", "osinlcp.opt.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_osinlcp_opt_alignment,
{ "Alignment", "osinlcp.opt.alignment", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_osinlcp,
&ett_osinlcp_options,
&ett_osinlcp_align_npdu_opt
};
proto_osinlcp = proto_register_protocol(
"PPP OSI Network Layer Control Protocol", "PPP OSINLCP", "osinlcp");
proto_register_field_array(proto_osinlcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_osinlcp(void)
{
dissector_handle_t osinlcp_handle;
osinlcp_handle = create_dissector_handle(dissect_osinlcp, proto_osinlcp);
dissector_add_uint("ppp.protocol", PPP_OSINLCP, osinlcp_handle);
dissector_add_uint("ethertype", PPP_OSINLCP, osinlcp_handle);
}
void
proto_register_ccp(void)
{
static hf_register_info hf[] = {
{ &hf_ccp_opt_type,
{ "Type", "ccp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_length,
{ "Length", "ccp.opt.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_oui,
{ "OUI", "ccp.opt.oui", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_subtype,
{ "Subtype", "ccp.opt.subtype", FT_UINT8, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_history_count,
{ "History Count", "ccp.opt.history_count", FT_UINT16, BASE_DEC,
NULL, 0x0, "The maximum number of compression histories",
HFILL }},
{ &hf_ccp_opt_cm,
{ "Check Mode Field", "ccp.opt.cm", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_cm_reserved,
{ "Reserved", "ccp.opt.cm.reserved", FT_UINT8, BASE_DEC,
NULL, 0xF8, NULL, HFILL }},
{ &hf_ccp_opt_cm_check_mode,
{ "Check Mode", "ccp.opt.cm.check_mode", FT_UINT8, BASE_DEC,
VALS(stac_checkmode_vals), 0x07, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits,
{ "Supported Bits", "ccp.opt.supported_bits", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits_h,
{ "H", "ccp.opt.supported_bits.h", FT_BOOLEAN, 32,
TFS(&ccp_mppe_h_tfs), MPPE_SUPPORTED_BITS_H, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits_m,
{ "M", "ccp.opt.supported_bits.m", FT_BOOLEAN, 32,
TFS(&ccp_mppe_m_tfs), MPPE_SUPPORTED_BITS_M, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits_s,
{ "S", "ccp.opt.supported_bits.s", FT_BOOLEAN, 32,
TFS(&ccp_mppe_s_tfs), MPPE_SUPPORTED_BITS_S, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits_l,
{ "L", "ccp.opt.supported_bits.l", FT_BOOLEAN, 32,
TFS(&ccp_mppe_l_tfs), MPPE_SUPPORTED_BITS_L, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits_d,
{ "D", "ccp.opt.supported_bits.d", FT_BOOLEAN, 32,
TFS(&ccp_mppe_d_tfs), MPPE_SUPPORTED_BITS_D, NULL, HFILL }},
{ &hf_ccp_opt_supported_bits_c,
{ "C", "ccp.opt.supported_bits.c", FT_BOOLEAN, 32,
TFS(&ccp_mppe_c_tfs), MPPC_SUPPORTED_BITS_C, NULL, HFILL }},
{ &hf_ccp_opt_history,
{ "History", "ccp.opt.history", FT_UINT8, BASE_DEC, NULL, 0x0,
"Maximum size of the compression history in powers of 2",
HFILL }},
{ &hf_ccp_opt_version,
{ "Version", "ccp.opt.version", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_vd,
{ "Vers/Dict", "ccp.opt.vd", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_vd_vers,
{ "Vers", "ccp.opt.vd.vers", FT_UINT8, BASE_DEC,
NULL, 0xE0, NULL, HFILL }},
{ &hf_ccp_opt_vd_dict,
{ "Dict", "ccp.opt.vd.dict", FT_UINT8, BASE_DEC, NULL,
0x1F, "The size in bits of the largest code used", HFILL }},
{ &hf_ccp_opt_check_mode,
{ "Check Mode", "ccp.opt.check_mode", FT_UINT8, BASE_DEC,
VALS(lzsdcp_checkmode_vals), 0x0, NULL, HFILL }},
{ &hf_ccp_opt_process_mode,
{ "Process Mode", "ccp.opt.process_mode", FT_UINT8, BASE_DEC,
VALS(lzsdcp_processmode_vals), 0x0, NULL, HFILL }},
{ &hf_ccp_opt_fe,
{ "Features", "ccp.opt.fe", FT_UINT8, BASE_DEC,
NULL, 0xC0, NULL, HFILL }},
{ &hf_ccp_opt_p,
{ "Packet by Packet flag", "ccp.opt.p", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ccp_opt_History,
{ "History", "ccp.opt.History", FT_UINT8, BASE_DEC,
NULL, 0x1F, NULL, HFILL }},
{ &hf_ccp_opt_contexts,
{ "# Contexts", "ccp.opt.contexts", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_mode,
{ "Mode", "ccp.opt.mode", FT_UINT8, BASE_DEC,
VALS(dce_mode_vals), 0x0, NULL, HFILL }},
{ &hf_ccp_opt_window,
{ "Window", "ccp.opt.window", FT_UINT8, BASE_DEC,
NULL, 0xF0, NULL, HFILL }},
{ &hf_ccp_opt_method,
{ "Method", "ccp.opt.method", FT_UINT8, BASE_DEC,
VALS(deflate_method_vals), 0x0F, NULL, HFILL }},
{ &hf_ccp_opt_mbz,
{ "MBZ", "ccp.opt.mbz", FT_UINT8, BASE_DEC,
NULL, 0xFC, NULL, HFILL }},
{ &hf_ccp_opt_chk,
{ "Chk", "ccp.opt.chk", FT_UINT8, BASE_DEC,
VALS(deflate_chk_vals), 0x03, NULL, HFILL }},
{ &hf_ccp_opt_mode_dictcount,
{ "Mode/Dictionary Count", "ccp.opt.mode_dictcount", FT_UINT16,
BASE_DEC | BASE_RANGE_STRING, RVALS(v44lzjh_mode_dict_rvals),
0x0, NULL, HFILL }},
{ &hf_ccp_opt_dict_size,
{ "Dictionary Size", "ccp.opt.dict_size", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_history_length,
{ "History Length", "ccp.opt.history_length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ccp_opt_data,
{ "Data", "ccp.opt.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ccp,
&ett_ccp_options,
&ett_ccp_oui_opt,
&ett_ccp_predict1_opt,
&ett_ccp_predict2_opt,
&ett_ccp_puddle_opt,
&ett_ccp_hpppc_opt,
&ett_ccp_stac_opt,
&ett_ccp_stac_opt_check_mode,
&ett_ccp_mppe_opt,
&ett_ccp_mppe_opt_supp_bits,
&ett_ccp_gfza_opt,
&ett_ccp_v42bis_opt,
&ett_ccp_bsdcomp_opt,
&ett_ccp_lzsdcp_opt,
&ett_ccp_mvrca_opt,
&ett_ccp_dce_opt,
&ett_ccp_deflate_opt,
&ett_ccp_v44lzjh_opt
};
proto_ccp = proto_register_protocol("PPP Compression Control Protocol",
"PPP CCP", "ccp");
proto_register_field_array(proto_ccp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ccp(void)
{
dissector_handle_t ccp_handle;
ccp_handle = create_dissector_handle(dissect_ccp, proto_ccp);
dissector_add_uint("ppp.protocol", PPP_CCP, ccp_handle);
dissector_add_uint("ethertype", PPP_CCP, ccp_handle);
}
void
proto_register_cbcp(void)
{
static hf_register_info hf[] = {
{ &hf_cbcp_callback_delay, { "Callback delay", "cbcp.callback_delay", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cbcp_address_type, { "Address Type", "cbcp.address_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_cbcp_address, { "Address", "cbcp.address", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cbcp_no_callback, { "No callback", "cbcp.no_callback", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_cbcp,
&ett_cbcp_options,
&ett_cbcp_callback_opt,
&ett_cbcp_callback_opt_addr
};
static ei_register_info ei[] = {
{ &ei_cbcp_address, { "cbcp.address.malformed", PI_MALFORMED, PI_ERROR, "Address runs past end of option", EXPFILL }},
};
expert_module_t* expert_cbcp;
proto_cbcp = proto_register_protocol("PPP Callback Control Protocol",
"PPP CBCP", "cbcp");
proto_register_field_array(proto_cbcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cbcp = expert_register_protocol(proto_cbcp);
expert_register_field_array(expert_cbcp, ei, array_length(ei));
}
void
proto_reg_handoff_cbcp(void)
{
dissector_handle_t cbcp_handle;
cbcp_handle = create_dissector_handle(dissect_cbcp, proto_cbcp);
dissector_add_uint("ppp.protocol", PPP_CBCP, cbcp_handle);
dissector_add_uint("ethertype", PPP_CBCP, cbcp_handle);
}
void
proto_register_bacp(void)
{
static hf_register_info hf[] = {
{ &hf_bacp_magic_number, { "Magic number", "bacp.magic_number", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_bacp_link_speed, { "Link Speed", "bacp.link_speed", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bacp_link_type, { "Link Type", "bacp.link_type", FT_UINT8, BASE_DEC, VALS(bap_link_type_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_bacp,
&ett_bacp_options,
&ett_bacp_favored_peer_opt
};
proto_bacp = proto_register_protocol(
"PPP Bandwidth Allocation Control Protocol", "PPP BACP", "bacp");
proto_register_field_array(proto_bacp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bacp(void)
{
dissector_handle_t bacp_handle;
bacp_handle = create_dissector_handle(dissect_bacp, proto_bacp);
dissector_add_uint("ppp.protocol", PPP_BACP, bacp_handle);
dissector_add_uint("ethertype", PPP_BACP, bacp_handle);
}
void
proto_register_bap(void)
{
static hf_register_info hf[] = {
{ &hf_bap_sub_option_type, { "Sub-Option Type", "bap.sub_option_type", FT_UINT8, BASE_DEC, VALS(bap_phone_delta_subopt_vals), 0x0, NULL, HFILL }},
{ &hf_bap_sub_option_length, { "Sub-Option Length", "bap.sub_option_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_unique_digit, { "Unique Digit", "bap.unique_digit", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_subscriber_number, { "Subscriber Number", "bap.subscriber_number", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_phone_number_sub_address, { "Phone Number Sub Address", "bap.phone_number_sub_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_unknown_option_data, { "Unknown", "bap.unknown_option_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_reason, { "Reason", "bap.reason", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_link_descriminator, { "Link Discriminator", "bap.link_descriminator", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_call_status, { "Status", "bap.call_status", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_cause_code_vals_ext, 0x0, NULL, HFILL }},
{ &hf_bap_call_action, { "Action", "bap.call_action", FT_UINT8, BASE_HEX, VALS(bap_call_status_opt_action_vals), 0x0, NULL, HFILL }},
{ &hf_bap_type, { "Type", "bap.type", FT_UINT8, BASE_HEX, VALS(bap_vals), 0x0, NULL, HFILL }},
{ &hf_bap_identifier, { "Identifier", "bap.identifier", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_length, { "Length", "bap.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_bap_response_code, { "Response Code", "bap.response_code", FT_UINT8, BASE_HEX, VALS(bap_resp_code_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_bap,
&ett_bap_options,
&ett_bap_link_type_opt,
&ett_bap_phone_delta_opt,
&ett_bap_phone_delta_subopt,
&ett_bap_call_status_opt
};
static ei_register_info ei[] = {
{ &ei_bap_sub_option_length, { "bap.sub_option_length.invalid", PI_PROTOCOL, PI_WARN, "Invalid length", EXPFILL }},
};
expert_module_t* expert_bap;
proto_bap = proto_register_protocol("PPP Bandwidth Allocation Protocol", "PPP BAP", "bap");
proto_register_field_array(proto_bap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bap = expert_register_protocol(proto_bap);
expert_register_field_array(expert_bap, ei, array_length(ei));
}
void
proto_reg_handoff_bap(void)
{
dissector_handle_t bap_handle;
bap_handle = create_dissector_handle(dissect_bap, proto_bap);
dissector_add_uint("ppp.protocol", PPP_BAP, bap_handle);
dissector_add_uint("ethertype", PPP_BAP, bap_handle);
}
void
proto_register_comp_data(void)
{
#if 0
static gint *ett[] = {
&ett_comp_data
};
#endif
proto_comp_data = proto_register_protocol("PPP Compressed Datagram",
"PPP Comp", "comp_data");
#if 0
proto_register_subtree_array(ett, array_length(ett));
#endif
}
void
proto_reg_handoff_comp_data(void)
{
dissector_handle_t comp_data_handle;
comp_data_handle = create_dissector_handle(dissect_comp_data,
proto_comp_data);
dissector_add_uint("ppp.protocol", PPP_COMP, comp_data_handle);
dissector_add_uint("ethertype", PPP_COMP, comp_data_handle);
}
void
proto_register_pap(void)
{
static gint *ett[] = {
&ett_pap,
&ett_pap_data
};
static hf_register_info hf[] = {
{ &hf_pap_code,
{ "Code", "pap.code", FT_UINT8, BASE_DEC, VALS(pap_vals), 0x0,
"The Code field is one octet and identifies the type of PAP "
"packet", HFILL }},
{ &hf_pap_identifier,
{ "Identifier", "pap.identifier", FT_UINT8, BASE_DEC, NULL, 0x0,
"The Identifier field is one octet and aids in matching "
"requests and replies.", HFILL }},
{ &hf_pap_length,
{ "Length", "pap.length", FT_UINT16, BASE_DEC, NULL, 0x0,
"The Length field is two octets and indicates the length of "
"the PAP packet", HFILL }},
{ &hf_pap_data,
{ "Data", "pap.data", FT_NONE, BASE_NONE, NULL, 0x0,
"The format of the Data field is determined by the Code field",
HFILL }},
{ &hf_pap_peer_id_length,
{ "Peer-ID-Length", "pap.peer_id.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The Peer-ID-Length field is one octet and indicates the "
"length of the Peer-ID field", HFILL }},
{ &hf_pap_peer_id,
{ "Peer-ID", "pap.peer_id", FT_STRING, BASE_NONE, NULL, 0x0,
"The Peer-ID field is zero or more octets and indicates the "
"name of the peer to be authenticated", HFILL }},
{ &hf_pap_password_length,
{ "Password-Length", "pap.password.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The Password-Length field is one octet and indicates the "
"length of the Password field", HFILL }},
{ &hf_pap_password,
{ "Password", "pap.password", FT_STRING, BASE_NONE, NULL, 0x0,
"The Password field is zero or more octets and indicates the "
"password to be used for authentication", HFILL }},
{ &hf_pap_message_length,
{ "Message-Length", "pap.message.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The Message-Length field is one octet and indicates the "
"length of the Message field", HFILL }},
{ &hf_pap_message,
{ "Message", "pap.message", FT_STRING, BASE_NONE, NULL, 0x0,
"The Message field is zero or more octets, and its contents "
"are implementation dependent.", HFILL }},
{ &hf_pap_stuff,
{ "stuff", "pap.stuff", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }}
};
proto_pap = proto_register_protocol("PPP Password Authentication Protocol",
"PPP PAP", "pap");
proto_register_field_array(proto_pap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pap(void)
{
dissector_handle_t pap_handle;
pap_handle = create_dissector_handle(dissect_pap, proto_pap);
dissector_add_uint("ppp.protocol", PPP_PAP, pap_handle);
dissector_add_uint("ethertype", PPP_PAP, pap_handle);
dissector_add_uint("sm_pco.protocol", PPP_PAP, pap_handle);
}
void
proto_register_chap(void)
{
static gint *ett[] = {
&ett_chap,
&ett_chap_data
};
static hf_register_info hf[] = {
{ &hf_chap_code,
{ "Code", "chap.code", FT_UINT8, BASE_DEC, VALS(chap_vals), 0x0,
"CHAP code", HFILL }},
{ &hf_chap_identifier,
{ "Identifier", "chap.identifier", FT_UINT8, BASE_DEC, NULL, 0x0,
"CHAP identifier", HFILL }},
{ &hf_chap_length,
{ "Length", "chap.length", FT_UINT16, BASE_DEC, NULL, 0x0,
"CHAP length", HFILL }},
{ &hf_chap_data,
{ "Data", "chap.data", FT_NONE, BASE_NONE, NULL, 0x0,
"CHAP Data", HFILL }},
{ &hf_chap_value_size,
{ "Value Size", "chap.value_size", FT_UINT8, BASE_DEC, NULL, 0x0,
"CHAP value size", HFILL }},
{ &hf_chap_value,
{ "Value", "chap.value", FT_BYTES, BASE_NONE, NULL, 0x0,
"CHAP value data", HFILL }},
{ &hf_chap_name,
{ "Name", "chap.name", FT_STRING, BASE_NONE, NULL, 0x0,
"CHAP name", HFILL }},
{ &hf_chap_message,
{ "Message", "chap.message", FT_STRING, BASE_NONE, NULL, 0x0,
"CHAP message", HFILL }},
{ &hf_chap_stuff,
{ "Stuff", "chap.stuff", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_chap = proto_register_protocol(
"PPP Challenge Handshake Authentication Protocol", "PPP CHAP", "chap");
proto_register_field_array(proto_chap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_chap(void)
{
dissector_handle_t chap_handle = create_dissector_handle(dissect_chap,
proto_chap);
dissector_add_uint("ppp.protocol", PPP_CHAP, chap_handle);
dissector_add_uint("ethertype", PPP_CHAP, chap_handle);
dissector_add_uint("sm_pco.protocol", PPP_CHAP, chap_handle);
}
void
proto_register_pppmuxcp(void)
{
static hf_register_info hf[] = {
{ &hf_pppmux_flags_pid,
{ "PID", "pppmuxcp.flags.pid", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x80,
NULL, HFILL }},
{ &hf_pppmux_flags_field_length,
{ "Length field", "pppmuxcp.flags.field_length", FT_BOOLEAN, 8, TFS(&tfs_pppmux_length_field), 0x40,
NULL, HFILL }},
{ &hf_pppmux_flags, { "PFF/LXT", "pppmuxcp.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_pppmux_sub_frame_length, { "Sub-frame Length", "pppmuxcp.sub_frame_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pppmux_def_prot_id, { "Default Protocol ID", "pppmuxcp.def_prot_id", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ppp_vals_ext, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_pppmuxcp,
&ett_pppmuxcp_options
};
proto_pppmuxcp = proto_register_protocol("PPPMux Control Protocol",
"PPP PPPMuxCP", "pppmuxcp");
proto_register_field_array(proto_pppmuxcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pppmuxcp(void)
{
dissector_handle_t muxcp_handle;
muxcp_handle = create_dissector_handle(dissect_pppmuxcp, proto_pppmuxcp);
dissector_add_uint("ppp.protocol", PPP_MUXCP, muxcp_handle);
dissector_add_uint("ethertype", PPP_MUXCP, muxcp_handle);
}
void
proto_register_pppmux(void)
{
static hf_register_info hf[] = {
{ &hf_pppmux_protocol,
{ "Protocol", "pppmux.protocol", FT_UINT16,
BASE_HEX|BASE_EXT_STRING, &ppp_vals_ext, 0x0,
"The protocol of the sub-frame.", HFILL }}
};
static gint *ett[] = {
&ett_pppmux,
&ett_pppmux_subframe,
&ett_pppmux_subframe_hdr,
&ett_pppmux_subframe_flags,
&ett_pppmux_subframe_info
};
proto_pppmux = proto_register_protocol("PPP Multiplexing", "PPP PPPMux",
"pppmux");
proto_register_field_array(proto_pppmux, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pppmux(void)
{
dissector_handle_t pppmux_handle;
pppmux_handle = create_dissector_handle(dissect_pppmux, proto_pppmux);
dissector_add_uint("ppp.protocol", PPP_MUX, pppmux_handle);
dissector_add_uint("ethertype", PPP_MUX, pppmux_handle);
}
void
proto_register_mplscp(void)
{
static gint *ett[] = {
&ett_mplscp,
&ett_mplscp_options
};
proto_mplscp = proto_register_protocol("PPP MPLS Control Protocol",
"PPP MPLSCP", "mplscp");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mplscp(void)
{
dissector_handle_t mplscp_handle;
mplscp_handle = create_dissector_handle(dissect_mplscp, proto_mplscp);
dissector_add_uint("ppp.protocol", PPP_MPLSCP, mplscp_handle);
dissector_add_uint("ethertype", PPP_MPLSCP, mplscp_handle);
}
void
proto_register_cdpcp(void)
{
static gint *ett[] = {
&ett_cdpcp,
&ett_cdpcp_options
};
proto_cdpcp = proto_register_protocol("PPP CDP Control Protocol",
"PPP CDPCP", "cdpcp");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cdpcp(void)
{
dissector_handle_t cdpcp_handle;
cdpcp_handle = create_dissector_handle(dissect_cdpcp, proto_cdpcp);
dissector_add_uint("ppp.protocol", PPP_CDPCP, cdpcp_handle);
dissector_add_uint("ethertype", PPP_CDPCP, cdpcp_handle);
}
void
proto_register_ipv6cp(void)
{
static hf_register_info hf[] = {
{ &hf_ipv6cp_interface_identifier, { "Interface Identifier", "ipv6cp.interface_identifier", FT_BYTES, SEP_COLON, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipv6cp,
&ett_ipv6cp_options,
&ett_ipv6cp_if_id_opt,
&ett_ipv6cp_compress_opt
};
proto_ipv6cp = proto_register_protocol("PPP IPv6 Control Protocol",
"PPP IPV6CP", "ipv6cp");
proto_register_field_array(proto_ipv6cp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipv6cp(void)
{
dissector_handle_t ipv6cp_handle;
ipv6cp_handle = create_dissector_handle(dissect_ipv6cp, proto_ipv6cp);
dissector_add_uint("ppp.protocol", PPP_IPV6CP, ipv6cp_handle);
dissector_add_uint("ethertype", PPP_IPV6CP, ipv6cp_handle);
dissector_add_uint("sm_pco.protocol", PPP_IPV6CP, ipv6cp_handle);
}
void
proto_register_iphc_crtp(void)
{
static hf_register_info hf[] = {
{ &hf_iphc_crtp_cid16,
{ "Context Id", "crtp.cid", FT_UINT16, BASE_DEC, NULL, 0x0,
"The context identifier of the compressed packet.", HFILL }},
{ &hf_iphc_crtp_cid8,
{ "Context Id", "crtp.cid", FT_UINT8, BASE_DEC, NULL, 0x0,
"The context identifier of the compressed packet.", HFILL }},
{ &hf_iphc_crtp_gen,
{ "Generation", "crtp.gen", FT_UINT8, BASE_DEC, NULL, 0x3f,
"The generation of the compressed packet.", HFILL }},
{ &hf_iphc_crtp_seq,
{ "Sequence (Data)", "crtp.seq", FT_UINT8, BASE_DEC, NULL, 0x0f,
"The sequence of the compressed packet.", HFILL }},
{ &hf_iphc_crtp_fh_flags,
{ "Flags", "crtp.fh_flags", FT_UINT8, BASE_HEX, NULL,
IPHC_CRTP_FH_FLAG_MASK,
"The flags of the full header packet.", HFILL }},
{ &hf_iphc_crtp_fh_cidlenflag,
{ "CID Length", "crtp.fh_flags.cidlen", FT_BOOLEAN, 8, TFS(&iphc_crtp_fh_cidlenflag),
IPHC_CRTP_FH_CIDLEN_FLAG, "A flag which is not set for 8-bit Context Ids and set for 16-bit Context Ids.", HFILL }},
{ &hf_iphc_crtp_fh_dataflag,
{ "Sequence (Data)", "crtp.fh_flags.data", FT_BOOLEAN, 8,
TFS(&tfs_present_absent), IPHC_CRTP_FH_DATA_FLAG,
"This indicates the presence of a nonzero data field, usually meaning the low nibble is a sequence number.", HFILL }},
{ &hf_iphc_crtp_cs_flags,
{ "Flags", "crtp.cs_flags", FT_UINT8, BASE_DEC, VALS(iphc_crtp_cs_flags),
0x0, "The flags of the context state packet.", HFILL }},
{ &hf_iphc_crtp_cs_cnt,
{ "Count", "crtp.cnt", FT_UINT8, BASE_DEC, NULL, 0x0,
"The count of the context state packet.", HFILL }},
{ &hf_iphc_crtp_cs_invalid,
{ "Invalid", "crtp.invalid", FT_BOOLEAN, 8, NULL, 0x80,
"The invalid bit of the context state packet.", HFILL }},
{ &hf_iphc_crtp_ip_id,
{ "IP-ID", "crtp.ip-id", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
"The IPv4 Identification Field is RANDOM and thus included in a compressed Non TCP packet (RFC 2507 6a), 7.13a). Only IPv4 is supported in this dissector.", HFILL }},
{ &hf_iphc_crtp_data,
{ "Data", "crtp.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_iphc_crtp,
&ett_iphc_crtp_hdr,
&ett_iphc_crtp_info,
&ett_iphc_crtp_fh_flags
};
static ei_register_info ei[] = {
{ &ei_iphc_crtp_ip_version, { "crtp.ip_version_unsupported", PI_PROTOCOL, PI_WARN, "IP version is unsupported", EXPFILL }},
{ &ei_iphc_crtp_next_protocol, { "crtp.next_protocol_unsupported", PI_PROTOCOL, PI_WARN, "Next protocol is unsupported", EXPFILL }},
{ &ei_iphc_crtp_seq_nonzero, { "crtp.seq_nonzero", PI_PROTOCOL, PI_WARN, "Sequence (Data) field is nonzero despite D bit not set", EXPFILL }}
};
expert_module_t* expert_iphc_crtp;
proto_iphc_crtp = proto_register_protocol("CRTP", "CRTP", "crtp");
proto_iphc_crtp_cudp16 = proto_register_protocol("CRTP (CUDP 16)", "CRTP (CUDP 16)", "crtp_cudp16");
proto_iphc_crtp_cudp8 = proto_register_protocol("CRTP (CUDP 8)", "CRTP (CUDP 8)", "crtp_cudp8");
proto_iphc_crtp_cs = proto_register_protocol("CRTP (CS)", "CRTP (CS)", "crtp_cs");
proto_iphc_crtp_cntcp = proto_register_protocol("CRTP (CNTCP)", "CRTP (CNTCP)", "crtp_cntcp");
proto_register_field_array(proto_iphc_crtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_iphc_crtp = expert_register_protocol(proto_iphc_crtp);
expert_register_field_array(expert_iphc_crtp, ei, array_length(ei));
}
void
proto_reg_handoff_iphc_crtp(void)
{
dissector_handle_t fh_handle;
dissector_handle_t cudp16_handle;
dissector_handle_t cudp8_handle;
dissector_handle_t cs_handle;
dissector_handle_t cntcp_handle;
fh_handle = create_dissector_handle(dissect_iphc_crtp_fh, proto_iphc_crtp);
dissector_add_uint("ppp.protocol", PPP_RTP_FH, fh_handle);
cudp16_handle = create_dissector_handle(dissect_iphc_crtp_cudp16, proto_iphc_crtp_cudp16);
dissector_add_uint("ppp.protocol", PPP_RTP_CUDP16, cudp16_handle);
cudp8_handle = create_dissector_handle(dissect_iphc_crtp_cudp8, proto_iphc_crtp_cudp8);
dissector_add_uint("ppp.protocol", PPP_RTP_CUDP8, cudp8_handle);
cs_handle = create_dissector_handle(dissect_iphc_crtp_cs, proto_iphc_crtp_cs);
dissector_add_uint("ppp.protocol", PPP_RTP_CS, cs_handle);
cntcp_handle = create_dissector_handle(dissect_iphc_crtp_cntcp, proto_iphc_crtp_cntcp);
dissector_add_uint("ppp.protocol", PPP_RTP_CNTCP, cntcp_handle);
dissector_add_uint("ethertype", PPP_RTP_FH, fh_handle);
dissector_add_uint("ethertype", PPP_RTP_CUDP16, cudp16_handle);
dissector_add_uint("ethertype", PPP_RTP_CUDP8, cudp8_handle);
dissector_add_uint("ethertype", PPP_RTP_CS, cs_handle);
dissector_add_uint("ethertype", PPP_RTP_CNTCP, cntcp_handle);
}
