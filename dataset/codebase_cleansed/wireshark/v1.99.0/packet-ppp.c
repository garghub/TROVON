static guint16
fcs16(tvbuff_t *tvbuff)
{
guint len = tvb_length(tvbuff) - 2;
if (len == 0)
return (0x0000);
return crc16_ccitt_tvb(tvbuff, len);
}
static guint32
fcs32(tvbuff_t *tvbuff)
{
guint len = tvb_length(tvbuff) - 4;
if (len == 0)
return (0x00000000);
return crc32_ccitt_tvb(tvbuff, len);
}
tvbuff_t *
decode_fcs(tvbuff_t *tvb, proto_tree *fh_tree, int fcs_decode, int proto_offset)
{
tvbuff_t *next_tvb;
gint len, reported_len;
int rx_fcs_offset;
guint32 rx_fcs_exp;
guint32 rx_fcs_got;
switch (fcs_decode) {
case NO_FCS:
next_tvb = tvb_new_subset_remaining(tvb, proto_offset);
break;
case FCS_16:
len = tvb_length_remaining(tvb, proto_offset);
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
rx_fcs_offset = proto_offset + len;
rx_fcs_exp = fcs16(tvb);
rx_fcs_got = tvb_get_letohs(tvb, rx_fcs_offset);
if (rx_fcs_got != rx_fcs_exp) {
proto_tree_add_text(fh_tree, tvb, rx_fcs_offset, 2,
"FCS 16: 0x%04x [incorrect, should be 0x%04x]",
rx_fcs_got, rx_fcs_exp);
} else {
proto_tree_add_text(fh_tree, tvb, rx_fcs_offset, 2,
"FCS 16: 0x%04x [correct]", rx_fcs_got);
}
}
break;
case FCS_32:
len = tvb_length_remaining(tvb, proto_offset);
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
rx_fcs_offset = proto_offset + len;
rx_fcs_exp = fcs32(tvb);
rx_fcs_got = tvb_get_letohl(tvb, rx_fcs_offset);
if (rx_fcs_got != rx_fcs_exp) {
proto_tree_add_text(fh_tree, tvb, rx_fcs_offset, 4,
"FCS 32: 0x%08x [incorrect, should be 0x%08x]",
rx_fcs_got, rx_fcs_exp);
} else {
proto_tree_add_text(fh_tree, tvb, rx_fcs_offset, 4,
"FCS 32: 0x%08x [correct]", rx_fcs_got);
}
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
next_tvb = NULL;
break;
}
return next_tvb;
}
void
capture_ppp_hdlc(const guchar *pd, int offset, int len, packet_counts *ld)
{
if (!BYTES_ARE_IN_FRAME(offset, len, 2)) {
ld->other++;
return;
}
if (pd[0] == CHDLC_ADDR_UNICAST || pd[0] == CHDLC_ADDR_MULTICAST) {
capture_chdlc(pd, offset, len, ld);
return;
}
if (!BYTES_ARE_IN_FRAME(offset, len, 4)) {
ld->other++;
return;
}
switch (pntoh16(&pd[offset + 2])) {
case PPP_IP:
capture_ip(pd, offset + 4, len, ld);
break;
case PPP_IPX:
capture_ipx(ld);
break;
case PPP_VINES:
capture_vines(ld);
break;
default:
ld->other++;
break;
}
}
static void
dissect_lcp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_lcp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_lcp_opt_length, tvb, offset + 1, 1, ENC_NA);
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
ENC_NA);
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
1, ENC_NA);
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
ENC_NA);
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
1, ENC_NA);
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
ENC_NA);
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
ENC_NA);
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
ENC_NA);
proto_tree_add_item(field_tree, hf_lcp_opt_max_susp_classes, tvb,
offset + 3, 1, ENC_NA);
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
proto_tree_add_item(tree, hf_ipcp_opt_length, tvb, offset + 1, 1, ENC_NA);
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
offset + 4, 1, ENC_NA);
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
ENC_NA);
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
ENC_NA);
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
ENC_NA);
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
static void
dissect_osinlcp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_osinlcp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_osinlcp_opt_length, tvb, offset + 1, 1,
ENC_NA);
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
1, ENC_NA);
}
static void
dissect_pppmuxcp_def_pid_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
pppmux_def_prot_id = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_text(tree, tvb, offset + 2, length - 2, "%s: %s (0x%02x)",
optp->name,
val_to_str_ext_const(pppmux_def_prot_id, &ppp_vals_ext, "Unknown"),
pppmux_def_prot_id);
}
static void
dissect_ccp_opt_type_len(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_ccp_opt_type, tvb, offset, 1,
type, "%s (%u)", name, type);
proto_tree_add_item(tree, hf_ccp_opt_length, tvb, offset + 1, 1, ENC_NA);
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
ENC_NA);
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
ENC_NA);
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
ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_process_mode, tvb, offset + 5,
1, ENC_NA);
}
static void
dissect_ccp_mvrca_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_fe, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_p, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_History, tvb, offset + 2, 1,
ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_contexts, tvb, offset + 3, 1,
ENC_NA);
}
static void
dissect_ccp_dce_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
dissect_ccp_opt_type_len(tvb, offset, field_tree, optp->name);
proto_tree_add_item(field_tree, hf_ccp_opt_mode, tvb, offset + 2, 1,
ENC_NA);
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
ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_mbz, tvb, offset + 3, 1,
ENC_NA);
proto_tree_add_item(field_tree, hf_ccp_opt_chk, tvb, offset + 3, 1,
ENC_NA);
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
dissect_cbcp_no_callback_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_text(tree, tvb, offset, length, "%s", optp->name);
}
static void
dissect_cbcp_callback_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_tree *addr_tree;
guint8 addr_type;
guint addr_len;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
proto_tree_add_text(field_tree, tvb, offset + 2, 1, "Callback delay: %u",
tvb_get_guint8(tvb, offset + 2));
offset += 3;
length -= 3;
while (length > 0) {
addr_tree = proto_tree_add_subtree(field_tree, tvb, offset, length,
ett_cbcp_callback_opt_addr, NULL, "Callback Address");
addr_type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(addr_tree, tvb, offset, 1, "Address Type: %s (%u)",
((addr_type == 1) ? "PSTN/ISDN" : "Other"), addr_type);
offset++;
length--;
addr_len = tvb_strsize(tvb, offset);
if (addr_len > length) {
proto_tree_add_text(addr_tree, tvb, offset, length,
"Address: (runs past end of option)");
break;
}
proto_tree_add_text(addr_tree, tvb, offset, addr_len, "Address: %s",
tvb_format_text(tvb, offset, addr_len - 1));
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
proto_tree_add_text(field_tree, tvb, offset + 2, 4, "Magic number: 0x%08x",
tvb_get_ntohl(tvb, offset + 2));
}
static void
dissect_bap_link_type_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 link_type;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
proto_tree_add_text(field_tree, tvb, offset + 2, 2, "Link Speed: %u kbps",
tvb_get_ntohs(tvb, offset + 2));
link_type = tvb_get_guint8(tvb, offset + 4);
proto_tree_add_text(field_tree, tvb, offset + 4, 1, "Link Type: %s (%u)",
val_to_str_const(link_type, bap_link_type_vals, "Unknown"), link_type);
}
static void
dissect_bap_phone_delta_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
proto_tree *suboption_tree;
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
proto_tree_add_text(suboption_tree, tvb, offset, 1,
"Sub-Option Type: %s (%u)", val_to_str_const(subopt_type,
bap_phone_delta_subopt_vals, "Unknown"), subopt_type);
if (subopt_len < 2) {
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Sub-Option Length: %u (invalid, must be >= 2)", subopt_len);
return;
}
if (subopt_len > length) {
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Sub-Option Length: %u (invalid, must be <= length remaining "
"in option %u)", subopt_len, length);
return;
}
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Sub-Option Length: %u", subopt_len);
switch (subopt_type) {
case BAP_PHONE_DELTA_SUBOPT_UNIQ_DIGIT:
if (subopt_len == 3) {
proto_tree_add_text(suboption_tree, tvb, offset + 2, 1,
"Unique Digit: %u", tvb_get_guint8(tvb, offset + 2));
} else {
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Invalid suboption length: %u (must be == 3)", subopt_len);
}
break;
case BAP_PHONE_DELTA_SUBOPT_SUBSC_NUM:
if (subopt_len > 2) {
proto_tree_add_text(suboption_tree, tvb, offset + 2,
subopt_len - 2, "Subscriber Number: %s",
tvb_format_text(tvb, offset + 2, subopt_len - 2));
} else {
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Invalid suboption length: %u (must be > 2)", subopt_len);
}
break;
case BAP_PHONE_DELTA_SUBOPT_PHONENUM_SUBADDR:
if (subopt_len > 2) {
proto_tree_add_text(suboption_tree, tvb, offset + 2,
subopt_len - 2, "Phone Number Sub Address: %s",
tvb_format_text(tvb, offset + 2, subopt_len - 2));
} else {
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Invalid suboption length: %u (must be > 2)", subopt_len);
}
break;
default:
if (subopt_len > 2) {
proto_tree_add_text(suboption_tree, tvb, offset + 2,
subopt_len - 2, "Unknown");
} else {
proto_tree_add_text(suboption_tree, tvb, offset + 1, 1,
"Invalid suboption length: %u (must be > 2)", subopt_len);
}
break;
}
offset += subopt_len;
length -= subopt_len;
}
}
static void
dissect_bap_reason_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
if (length > 2) {
proto_tree_add_text(tree, tvb, offset, length, "%s: %s", optp->name,
tvb_format_text(tvb, offset + 2, length - 2));
}
}
static void
dissect_bap_link_disc_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_text(tree, tvb, offset, length, "%s: 0x%04x", optp->name,
tvb_get_ntohs(tvb, offset + 2));
}
static void
dissect_bap_call_status_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *field_tree;
guint8 status, action;
field_tree = proto_tree_add_subtree(tree, tvb, offset, length, *optp->subtree_index, NULL, optp->name);
status = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(field_tree, tvb, offset + 2, 1, "Status: %s (0x%02x)",
val_to_str_ext_const(status, &q931_cause_code_vals_ext, "Unknown"),
status);
action = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_text(field_tree, tvb, offset + 3, 1, "Action: %s (0x%02x)",
val_to_str_const(action, bap_call_status_opt_action_vals, "Unknown"),
action);
}
static void
dissect_vsncp_pdnid_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
guint8 PDNID;
PDNID = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(tree, tvb, offset, length, "%s: 0x%02x", optp->name,
PDNID);
}
static void
dissect_vsncp_attachtype_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const value_string attach_vals[] = {
{1, "Initial Attach"},
{3, "Handover Attach"},
{0, NULL}
};
guint8 attach;
if (tree) {
attach = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(tree, tvb, offset, length, "%s: %s (0x%02x)",
optp->name, val_to_str_const(attach , attach_vals, "Unknown"),
attach);
}
}
static void
dissect_vsncp_pdntype_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const value_string pdntype_vals[] = {
{1, "IPv4"},
{2, "IPv6"},
{3, "IPv6/IPv4"},
{0, NULL}
};
guint8 pdntype;
if (tree) {
pdntype = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(tree, tvb, offset, length, "%s: %s (0x%02x)",
optp->name, val_to_str_const(pdntype, pdntype_vals, "Unknown"),
pdntype);
}
}
static void
dissect_vsncp_errorcode_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const value_string errorcode_vals[] = {
{0, "General Eror"},
{1, "Unauthorized APN"},
{2, "PDN Limit Exceeded"},
{3, "NO PG-W Available"},
{4, "P-GW Unreachable"},
{5, "P-GW Reject"},
{6, "Insufficient Parameters"},
{7, "Resource Unavailable"},
{8, "Admin Prohibited"},
{9, "PDN-ID Already in Use"},
{10, "Subscription Limitation"},
{11, "PDN connection already exists for APN"},
{12, "Emergency services not supported"},
{13, "Reconnect to this APN not allowed"},
{14, "APN congested"},
{0, NULL}
};
guint8 pdntype;
if (tree) {
pdntype = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(tree, tvb, offset, length, "%s: %s (0x%02x)",
optp->name, val_to_str_const(pdntype, errorcode_vals, "Unknown"),
pdntype);
}
}
static void
dissect_vsncp_pdnaddress_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
guint8 pdnaddtype;
static const value_string pdntype_vals[] = {
{0, "Initial Request by UE"},
{1, "IPv4 Address"},
{2, "IPv6 Address"},
{3, "IPv6/IPv4 Address"},
{0, NULL}
};
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
pdnaddtype = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(field_tree, tvb, offset + 2, 1,
"PDN Type (%s): 0x%02x",
val_to_str_const(pdnaddtype, pdntype_vals, "Unknown"), pdnaddtype);
switch (pdnaddtype) {
case 1:
proto_tree_add_text(field_tree, tvb, offset + 3, length - 3, "%s: %s",
val_to_str_const(pdnaddtype, pdntype_vals, "Unknown"),
tvb_ip_to_str(tvb, offset + 3));
break;
case 2:
{
struct e_in6_addr *ad = wmem_new0(wmem_packet_scope(),struct e_in6_addr);
tvb_memcpy(tvb, &ad->bytes[8], offset + 3, 8);
proto_tree_add_text(field_tree, tvb, offset + 3, length - 3, "%s: %s",
val_to_str_const(pdnaddtype, pdntype_vals, "Unknown"),
ip6_to_str(ad));
break;
}
case 3:
{
struct e_in6_addr *ad = wmem_new0(wmem_packet_scope(), struct e_in6_addr);
tvb_memcpy(tvb, &ad->bytes[8], offset + 3, 8);
proto_tree_add_text(field_tree, tvb, offset + 3, length - 3, "%s: %s",
val_to_str_const(pdnaddtype, pdntype_vals, "Unknown"),
ip6_to_str(ad));
proto_tree_add_text(field_tree, tvb, offset + 11, length - 11,
"%s: %s", val_to_str_const(pdnaddtype, pdntype_vals, "Unknown"),
tvb_ip_to_str(tvb, offset + 11));
break;
}
default:
break;
}
}
static void
dissect_vsncp_ipv4address_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_text(tree, tvb, offset, length, "%s: %s", optp->name,
tvb_ip_to_str(tvb, offset + 2));
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
proto_tree_add_text(field_tree, tvb, off, lengthofapn,
"Label%d (%d byte%s): %s", j++, lengthofapn,
plurality(lengthofapn, "", "s"),
tvb_format_text(tvb, off, lengthofapn));
off += lengthofapn;
i += lengthofapn + 1;
}
}
}
static void
dissect_vsncp_addressalloc_opt(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const value_string alloc_vals[] = {
{0, "Null Value (Attach or Handover)"},
{18, "New PDN type due to network preference"},
{255, "Success"},
{0, NULL}
};
guint8 alloc;
if (tree) {
alloc = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_text(tree, tvb, offset, length, "%s: %s (0x%02x)",
optp->name, val_to_str_const(alloc, alloc_vals, "Unknown"), alloc);
}
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
proto_tree_add_text(field_tree, tvb, offset, length, "AMBR Data");
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
proto_tree_add_text(field_tree, tvb, offset, length, "IPv6 interface identifier");
}
}
static void
dissect_vsncp_pco_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
static const value_string pco_vals[] = {
{0x8021, "IPCP (DNS Address Request)"},
{0x0001, "P-CSCF Address Request (IPv6)"},
{0x0005, "MS Support of Network Requested Bearer Control indicator"},
{0x0003, "DNS Server Address (IPv6)"},
{0x000A, "IP address allocation via NAS signalling"},
{0x000B, "IPv4 address allocation via DHCPv4"},
{0x000D, "DNS Server IPv4 Address Request"},
{0, NULL}
};
int off = offset + 3;
guint8 i = 0;
guint16 pcotype;
guint8 len;
proto_tree *field_tree;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, length,
ett_lcp_options, NULL, "%s: (%d byte%s)",
optp->name, length, plurality(length, "", "s"));
while (i < (length - 3)) {
pcotype = tvb_get_ntohs(tvb, off);
len = tvb_get_guint8(tvb, (off + 2));
proto_tree_add_text(field_tree, tvb, off, 2, "Protocol: %s (0x%02x)",
val_to_str_const(pcotype, pco_vals, "Unknown"), pcotype);
proto_tree_add_text(field_tree, tvb, off + 2, 1, "Length:(0x%02x)",
len);
if (len > 0) {
proto_tree_add_text(field_tree, tvb, off + 3, len,
"Data (%d byte%s)", len, plurality(len, "", "s"));
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
proto_tree_add_item(fh_tree, hf_ppp_identifier, tvb, 1, 1, ENC_NA);
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
ENC_NA);
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
tvb_bytes_to_ep_str(tvb, offset, length));
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
call_dissector(data_handle, next_tvb, pinfo, fh_tree);
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
call_dissector(data_handle,next_tvb, pinfo, tree);
}
}
static void
dissect_lcp_options(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ip_tcp_options(tvb, 0, tvb_reported_length(tvb), lcp_opts,
N_LCP_OPTS, -1, &PPP_OPT_TYPES, &ei_ppp_opt_len_invalid, pinfo, tree, NULL, NULL);
}
static void
dissect_lcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_lcp, ett_lcp, lcp_vals, ett_lcp_options, lcp_opts,
N_LCP_OPTS, pinfo, tree);
}
static void
dissect_vsncp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
proto_tree *field_tree;
guint8 code;
guint8 id;
int length, offset;
code = tvb_get_guint8(tvb, 0);
id = tvb_get_guint8(tvb, 1);
length = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VSNCP");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(code, cp_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_vsncp, tvb, 0, length, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_vsncp);
proto_tree_add_text(fh_tree, tvb, 0, 1, "Code: %s (0x%02x)",
val_to_str_const(code, cp_vals, "Unknown"), code);
proto_tree_add_text(fh_tree, tvb, 1, 1, "Identifier: 0x%02x", id);
proto_tree_add_text(fh_tree, tvb, 2, 2, "Length: %u", length);
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
}
static void
dissect_vsnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
static void
dissect_ipcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_ipcp, ett_ipcp, cp_vals, ett_ipcp_options, ipcp_opts,
N_IPCP_OPTS, pinfo, tree);
}
static void
dissect_bcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *flags_item;
proto_tree *bcp_tree, *flags_tree;
int offset = 0;
guint8 flags;
guint8 mac_type;
gint captured_length, reported_length, pad_length;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP BCP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_bcp, tvb, 0, -1, ENC_NA);
bcp_tree = proto_item_add_subtree(ti, ett_bcp);
flags = tvb_get_guint8(tvb, offset);
if (flags & BCP_IS_BCONTROL) {
col_set_str(pinfo->cinfo, COL_INFO, "Bridge control");
}
if (tree) {
flags_item = proto_tree_add_uint(bcp_tree, hf_bcp_flags, tvb, offset,
1, flags);
flags_tree = proto_item_add_subtree(flags_item, ett_bcp_flags);
proto_tree_add_boolean(flags_tree, hf_bcp_fcs_present, tvb, offset,
1, flags);
proto_tree_add_boolean(flags_tree, hf_bcp_zeropad, tvb, offset, 1,
flags);
proto_tree_add_boolean(flags_tree, hf_bcp_bcontrol, tvb, offset, 1,
flags);
proto_tree_add_uint(flags_tree, hf_bcp_pads, tvb, offset, 1, flags);
}
offset++;
mac_type = tvb_get_guint8(tvb, offset);
if (!(flags & BCP_IS_BCONTROL)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(mac_type, bcp_mac_type_vals,
"Unknown MAC type %u"));
}
if (tree) {
proto_tree_add_uint(bcp_tree, hf_bcp_mac_type, tvb, offset, 1,
mac_type);
}
offset++;
switch (mac_type) {
case BCP_MACT_802_4:
case BCP_MACT_802_5_NONCANON:
case BCP_MACT_FDDI_NONCANON:
case BCP_MACT_802_5_CANON:
case BCP_MACT_FDDI_CANON:
if (tree)
proto_tree_add_text(bcp_tree, tvb, offset, 1, "Pad");
offset++;
break;
default:
break;
}
if (!(flags & BCP_IS_BCONTROL)) {
captured_length = tvb_length_remaining(tvb, offset);
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
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
}
}
}
static void
dissect_osinlcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_osinlcp, ett_osinlcp, cp_vals, ett_osinlcp_options,
osinlcp_opts, N_OSINLCP_OPTS, pinfo, tree);
}
static void
dissect_ccp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_ccp, ett_ccp, ccp_vals, ett_ccp_options, ccp_opts,
N_CCP_OPTS, pinfo, tree);
}
static void
dissect_cbcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_cbcp, ett_cbcp, cbcp_vals, ett_cbcp_options,
cbcp_opts, N_CBCP_OPTS, pinfo, tree);
}
static void
dissect_bacp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_bacp, ett_bacp, cp_vals, ett_bacp_options, bacp_opts,
N_BACP_OPTS, pinfo, tree);
}
static void
dissect_bap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
proto_tree *field_tree;
guint8 type;
guint8 id;
int length, offset;
guint8 resp_code;
type = tvb_get_guint8(tvb, 0);
id = tvb_get_guint8(tvb, 1);
length = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP BAP");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(type, bap_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_bap, tvb, 0, length, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_bap_options);
proto_tree_add_text(fh_tree, tvb, 0, 1, "Type: %s (0x%02x)",
val_to_str_const(type, bap_vals, "Unknown"), type);
proto_tree_add_text(fh_tree, tvb, 1, 1, "Identifier: 0x%02x", id);
proto_tree_add_text(fh_tree, tvb, 2, 2, "Length: %u", length);
}
offset = 4;
length -= 4;
if (type == BAP_CRES || type == BAP_CBRES ||
type == BAP_LDQRES || type == BAP_CSRES) {
resp_code = tvb_get_guint8(tvb, offset);
proto_tree_add_text(fh_tree, tvb, offset, 1,
"Response Code: %s (0x%02x)",
val_to_str_const(resp_code, bap_resp_code_vals, "Unknown"),
resp_code);
offset++;
length--;
}
if (length > 0) {
field_tree = proto_tree_add_subtree_format(fh_tree, tvb, offset, length,
ett_bap_options, NULL, "Data (%d byte%s)", length, plurality(length, "", "s"));
dissect_ip_tcp_options(tvb, offset, length, bap_opts, N_BAP_OPTS, -1, &PPP_OPT_TYPES,
&ei_ppp_opt_len_invalid, pinfo, field_tree, NULL, NULL);
}
}
static void
dissect_comp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP Comp");
col_set_str(pinfo->cinfo, COL_INFO, "Compressed data");
proto_tree_add_item(tree, proto_comp_data, tvb, 0, -1, ENC_NA);
}
static void
dissect_pppmuxcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_pppmuxcp, ett_pppmuxcp, pppmuxcp_vals,
ett_pppmuxcp_options, pppmuxcp_opts, N_PPPMUXCP_OPTS,pinfo, tree);
}
static void
dissect_pppmux(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mux_tree, *hdr_tree, *sub_tree, *flag_tree;
proto_tree *info_tree;
proto_item *ti = NULL;
guint8 flags, byte;
guint16 length;
static guint16 pid;
tvbuff_t *next_tvb;
int offset = 0, length_remaining;
int length_field = 0, pid_field = 0, hdr_length = 0;
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
ti = proto_tree_add_text(hdr_tree, tvb, offset, length_field,
"PFF/LXT: 0x%02X", flags);
flag_tree = proto_item_add_subtree(ti, ett_pppmux_subframe_flags);
proto_tree_add_item(flag_tree, hf_pppmux_flags_pid, tvb, offset, length_field,
ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_pppmux_flags_field_length, tvb, offset, length_field,
ENC_BIG_ENDIAN);
proto_tree_add_text(hdr_tree, tvb,offset, length_field,
"Sub-frame Length = %u", length);
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
call_dissector(data_handle, next_tvb, pinfo, info_tree);
}
offset += length;
length_remaining -= length;
}
}
static void
dissect_iphc_crtp_fh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree = NULL, *info_tree;
proto_item *ti = NULL;
guint ip_hdr_len, flags;
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
flags = (tvb_get_guint8(tvb, 2) & IPHC_CRTP_FH_FLAG_MASK) >>
IPHC_CRTP_FH_FLAG_POS;
next_protocol = tvb_get_guint8(tvb, 9);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_iphc_crtp, tvb, 0, -1,
"%s", val_to_str_ext_const(PPP_RTP_FH, &ppp_vals_ext, "Unknown"));
fh_tree = proto_item_add_subtree(ti, ett_iphc_crtp);
proto_tree_add_item(fh_tree, hf_iphc_crtp_fh_flags, tvb, 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_iphc_crtp_gen, tvb, 2, 1,
ENC_BIG_ENDIAN);
}
ip_hdr_len = (tvb_get_guint8(tvb, 0) & 0x0f) * 4;
hdr_len = ip_hdr_len + 8;
if (ip_version != 4) {
proto_tree_add_text(fh_tree, tvb, 3, -1,
"IP version is %u: the only supported version is 4",
ip_version);
return;
}
if (next_protocol != IP_PROTO_UDP) {
proto_tree_add_text(fh_tree, tvb, 3, -1,
"Next protocol is %s (%u): the only supported protocol is UDP",
ipprotostr(next_protocol), next_protocol);
return;
}
switch (flags) {
case IPHC_CRTP_FH_CID8:
offset_cid = 3;
offset_seq = ip_hdr_len + 5;
proto_tree_add_item(fh_tree, hf_iphc_crtp_cid8, tvb, offset_cid, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_iphc_crtp_seq, tvb, offset_seq, 1,
ENC_BIG_ENDIAN);
break;
case IPHC_CRTP_FH_CID16:
offset_seq = 3;
offset_cid = ip_hdr_len + 4;
proto_tree_add_item(fh_tree, hf_iphc_crtp_seq, tvb, offset_seq, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_iphc_crtp_cid16, tvb, offset_cid,
2, ENC_BIG_ENDIAN);
break;
default:
break;
}
info_tree = proto_tree_add_subtree(fh_tree, tvb, 0, length, ett_iphc_crtp_info, NULL, "Information Field");
tvb_ensure_bytes_exist (tvb, 0, hdr_len);
ip_packet = (guchar *)tvb_memdup(NULL, tvb, 0, length);
ip_packet[2] = length >> 8;
ip_packet[3] = length;
ip_packet[ip_hdr_len + 4] = (length - ip_hdr_len) >> 8;
ip_packet[ip_hdr_len + 5] = (length - ip_hdr_len);
next_tvb = tvb_new_child_real_data(tvb, ip_packet, length, length);
add_new_data_source(pinfo, next_tvb, "Decompressed Data");
tvb_set_free_cb(next_tvb, g_free);
if (!dissector_try_uint(ppp_subdissector_table, PPP_IP, next_tvb, pinfo,
info_tree)) {
call_dissector_only(data_handle, next_tvb, pinfo, info_tree, NULL);
}
}
static void
dissect_iphc_crtp_cudp16(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
proto_tree_add_text(cudp_tree, tvb, offset, length, "Data (%d bytes)",
length);
}
}
static void
dissect_iphc_crtp_cudp8(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
proto_tree_add_text(cudp_tree, tvb, offset, length, "Data (%d bytes)",
length);
}
}
static void
dissect_iphc_crtp_cs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
tvb_ensure_bytes_exist(tvb, offset, length);
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
}
static void
dissect_mplscp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_mplscp, ett_mplscp, cp_vals, ett_mplscp_options,
NULL, 0, pinfo, tree);
}
static void
dissect_cdpcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_cdpcp, ett_cdpcp, cp_vals, ett_cdpcp_options, NULL,
0, pinfo, tree);
}
static void
dissect_mp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mp_tree = NULL, *hdr_tree;
proto_item *ti = NULL;
guint8 flags;
const gchar *flag_str;
gint hdrlen;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP MP");
col_set_str(pinfo->cinfo, COL_INFO, "PPP Multilink");
if (tree) {
ti = proto_tree_add_item(tree, proto_mp, tvb, 0,
mp_short_seqno ? 2 : 4, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_mp);
}
flags = tvb_get_guint8(tvb, 0);
if (tree) {
switch (MP_FRAG(flags)) {
case MP_FRAG_FIRST:
flag_str = "First";
break;
case MP_FRAG_LAST:
flag_str = "Last";
break;
case MP_FRAG_FIRST|MP_FRAG_LAST:
flag_str = "First, Last";
break;
default:
flag_str = "Unknown";
break;
}
ti = proto_tree_add_text(mp_tree, tvb, 0, 1, "Fragment: 0x%2X (%s)",
MP_FRAG(flags), flag_str);
hdr_tree = proto_item_add_subtree(ti, ett_mp_flags);
proto_tree_add_boolean(hdr_tree, hf_mp_frag_first, tvb, 0, 1, flags);
proto_tree_add_boolean(hdr_tree, hf_mp_frag_last, tvb, 0, 1, flags);
if (mp_short_seqno) {
proto_tree_add_item(hdr_tree, hf_mp_short_sequence_num_reserved, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(mp_tree, hf_mp_short_sequence_num, tvb, 0, 2,
ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(hdr_tree, hf_mp_sequence_num_reserved, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(mp_tree, hf_mp_sequence_num, tvb, 1, 3,
ENC_BIG_ENDIAN);
}
}
hdrlen = mp_short_seqno ? 2 : 4;
if (tvb_reported_length_remaining(tvb, hdrlen) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, hdrlen);
dissect_ppp(next_tvb, pinfo, tree);
}
}
static void
dissect_ppp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *fh_tree = NULL;
if (tree) {
ti = proto_tree_add_item(tree, proto_ppp, tvb, 0, -1, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_ppp);
}
dissect_ppp_common(tvb, pinfo, tree, fh_tree, ti, 0);
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
static void
dissect_ppp_hdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 byte0;
byte0 = tvb_get_guint8(tvb, 0);
if (byte0 == CHDLC_ADDR_UNICAST || byte0 == CHDLC_ADDR_MULTICAST) {
call_dissector(chdlc_handle, tvb, pinfo, tree);
return;
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
static void
dissect_ppp_raw_hdlc( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
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
if (tree)
proto_tree_add_text(bs_tree, tvb, offset, -1, "PPP Fragment");
offset++;
length = tvb_length_remaining(tvb,offset);
ppp_tvb = remove_escape_chars(tvb, pinfo, offset,length);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Fragment");
call_dissector(data_handle, ppp_tvb, pinfo, tree);
}
return;
}
if (offset != 0) {
col_set_str(pinfo->cinfo, COL_INFO, "PPP Fragment");
length = offset;
if (tree)
proto_tree_add_text(bs_tree, tvb, 0, length, "PPP Fragment");
if (length != 0) {
ppp_tvb = remove_escape_chars(tvb, pinfo, 0, length - 1);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Fragment");
call_dissector(data_handle, ppp_tvb, pinfo, tree);
}
}
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
end_offset = tvb_find_guint8(tvb, offset + 1, -1, 0x7e);
if (end_offset == -1) {
if (first)
col_set_str(pinfo->cinfo, COL_INFO, "PPP Fragment");
if (tree)
proto_tree_add_text(bs_tree, tvb, offset, -1, "PPP Fragment");
offset++;
length = tvb_length_remaining(tvb, offset);
ppp_tvb = remove_escape_chars(tvb, pinfo, offset, length);
if (ppp_tvb != NULL) {
add_new_data_source(pinfo, ppp_tvb, "PPP Fragment");
call_dissector(data_handle, ppp_tvb, pinfo, tree);
}
return;
}
data_offset = offset + 1;
data_length = end_offset - data_offset;
if (tvb_offset_exists(tvb, end_offset + 1) &&
tvb_get_guint8(tvb, end_offset+1) == 0x7e) {
end_offset++;
}
length = end_offset - offset;
if (tree)
proto_tree_add_text(bs_tree, tvb, offset, length, "PPP Data");
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
}
static gboolean
dissect_ppp_usb( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
const guchar buf1[3] = {0x7e, 0xff, 0x03};
const guchar buf2[4] = {0x7e, 0xff, 0x7d, 0x23};
tvbuff_t *next_tvb;
if ((tvb_memeql(tvb, 0, buf2, sizeof(buf2)) == 0) ||
(tvb_memeql(tvb, 0, buf1, sizeof(buf1)) == 0)) {
dissect_ppp_raw_hdlc(tvb, pinfo, tree);
} else if ((tvb_memeql(tvb, 0, &buf1[1], sizeof(buf1) - 1) == 0) ||
(tvb_memeql(tvb, 0, &buf2[1], sizeof(buf2) - 1) == 0)) {
if (tvb_get_guint8(tvb, 1) == 0x03)
next_tvb = tvb_new_subset_remaining(tvb, 2);
else
next_tvb = tvb_new_subset_remaining(tvb, 3);
dissect_ppp(next_tvb, pinfo, tree);
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
static gint *ett[] = {
&ett_ppp_hdlc_data
};
proto_ppp_hdlc = proto_register_protocol("PPP In HDLC-Like Framing",
"PPP-HDLC", "ppp_hdlc");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ppp_raw_hdlc(void)
{
dissector_handle_t ppp_raw_hdlc_handle;
ppp_raw_hdlc_handle = create_dissector_handle(dissect_ppp_raw_hdlc,
proto_ppp);
dissector_add_uint("gre.proto", ETHERTYPE_CDMA2000_A10_UBS,
ppp_raw_hdlc_handle);
dissector_add_uint("gre.proto", ETHERTYPE_3GPP2, ppp_raw_hdlc_handle);
heur_dissector_add("usb.bulk", dissect_ppp_usb, proto_ppp);
}
static void
dissect_pap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
}
static void
dissect_chap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
return;
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
proto_tree_add_text(field_tree, tvb, offset, 1,
"Value Size: %d byte%s (invalid, must be <= %u)",
value_size, plurality(value_size, "", "s"), length);
return;
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
tvb_ensure_bytes_exist(tvb, offset, length);
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
tvb_bytes_to_ep_str(tvb, value_offset, value_size));
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
proto_tree_add_text(fh_tree, tvb, offset, length,
"Stuff (%u byte%s)", length, plurality(length, "", "s"));
break;
}
}
static void
dissect_ipv6cp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_cp(tvb, proto_ipv6cp, ett_ipv6cp, cp_vals, ett_ipv6cp_options,
ipv6cp_opts, N_IPV6CP_OPTS, pinfo, tree);
}
static void
dissect_ipv6cp_if_id_opt(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint length, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree_add_text(tree, tvb, offset, length,
"%s: %02x%02x:%02x%02x:%02x%x:%02x%02x", optp->name,
tvb_get_guint8(tvb, offset + 2), tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + 4), tvb_get_guint8(tvb, offset + 5),
tvb_get_guint8(tvb, offset + 6), tvb_get_guint8(tvb, offset + 7),
tvb_get_guint8(tvb, offset + 8), tvb_get_guint8(tvb, offset + 9));
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
"PPP protocol", FT_UINT16, BASE_HEX);
register_dissector("ppp_hdlc", dissect_ppp_hdlc, proto_ppp);
register_dissector("ppp_lcp_options", dissect_lcp_options, proto_ppp);
register_dissector("ppp", dissect_ppp, proto_ppp);
ppp_module = prefs_register_protocol(proto_ppp, NULL);
prefs_register_enum_preference(ppp_module, "fcs_type",
"PPP Frame Checksum Type",
"The type of PPP frame checksum (none, 16-bit, 32-bit)",
&ppp_fcs_decode, fcs_options, FALSE);
prefs_register_bool_preference(ppp_module, "decompress_vj",
"Decompress Van Jacobson-compressed frames",
"Whether Van Jacobson-compressed PPP frames should be decompressed",
&ppp_vj_decomp);
prefs_register_uint_preference(ppp_module, "default_proto_id",
"PPPMuxCP Default PID (in hex)",
"Default Protocol ID to be used for PPPMuxCP",
16, &pppmux_def_prot_id);
}
void
proto_reg_handoff_ppp(void)
{
dissector_handle_t ppp_hdlc_handle, ppp_handle;
chdlc_handle = find_dissector("chdlc");
data_handle = find_dissector("data");
ppp_handle = find_dissector("ppp");
dissector_add_uint("fr.nlpid", NLPID_PPP, ppp_handle);
ppp_hdlc_handle = find_dissector("ppp_hdlc");
dissector_add_uint("wtap_encap", WTAP_ENCAP_PPP, ppp_hdlc_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_PPP_WITH_PHDR,
ppp_hdlc_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_PPPHDLC, ppp_hdlc_handle);
dissector_add_uint("osinl.excl", NLPID_PPP, ppp_handle);
dissector_add_uint("gre.proto", ETHERTYPE_PPP, ppp_hdlc_handle);
}
void
proto_register_mp(void)
{
static hf_register_info hf[] = {
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
static gint *ett[] = {
&ett_vsncp,
&ett_vsncp_options
};
proto_vsncp = proto_register_protocol("Vendor Specific Control Protocol",
"VSNCP", "vsncp");
proto_register_subtree_array(ett, array_length(ett));
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
proto_register_bcp(void)
{
static hf_register_info hf[] = {
{ &hf_bcp_flags,
{ "Flags", "bcp.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bcp_fcs_present,
{ "LAN FCS present", "bcp.flags.fcs_present", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), BCP_FCS_PRESENT, NULL, HFILL }},
{ &hf_bcp_zeropad,
{ "802.3 pad zero-filled", "bcp.flags.zeropad", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), BCP_ZEROPAD, NULL, HFILL }},
{ &hf_bcp_bcontrol,
{ "Bridge control", "bcp.flags.bcontrol", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), BCP_IS_BCONTROL, NULL, HFILL }},
{ &hf_bcp_pads,
{ "Pads", "bcp.pads", FT_UINT8, BASE_DEC,
NULL, BCP_PADS_MASK, NULL, HFILL }},
{ &hf_bcp_mac_type,
{ "MAC Type", "bcp.mac_type", FT_UINT8, BASE_DEC,
VALS(bcp_mac_type_vals), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_bcp,
&ett_bcp_flags
};
proto_bcp = proto_register_protocol("PPP Bridging Control Protocol",
"PPP BCP", "bcp");
proto_register_field_array(proto_bcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_register_osinlcp(void)
{
static hf_register_info hf[] = {
{ &hf_osinlcp_opt_type,
{ "Type", "osinlcp.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_osinlcp_opt_length,
{ "Length", "osinlcp.opt.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_osinlcp_opt_alignment,
{ "Alignment", "osinlcp.opt.alignment", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
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
proto_reg_handoff_bcp(void)
{
dissector_handle_t bcp_handle;
eth_withfcs_handle = find_dissector("eth_withfcs");
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
bcp_handle = create_dissector_handle(dissect_bcp, proto_bcp);
dissector_add_uint("ppp.protocol", PPP_BCP, bcp_handle);
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
static gint *ett[] = {
&ett_cbcp,
&ett_cbcp_options,
&ett_cbcp_callback_opt,
&ett_cbcp_callback_opt_addr
};
proto_cbcp = proto_register_protocol("PPP Callback Control Protocol",
"PPP CBCP", "cbcp");
proto_register_subtree_array(ett, array_length(ett));
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
static gint *ett[] = {
&ett_bacp,
&ett_bacp_options,
&ett_bacp_favored_peer_opt
};
proto_bacp = proto_register_protocol(
"PPP Bandwidth Allocation Control Protocol", "PPP BACP", "bacp");
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
static gint *ett[] = {
&ett_bap,
&ett_bap_options,
&ett_bap_link_type_opt,
&ett_bap_phone_delta_opt,
&ett_bap_phone_delta_subopt,
&ett_bap_call_status_opt
};
proto_bap = proto_register_protocol("PPP Bandwidth Allocation Protocol",
"PPP BAP", "bap");
proto_register_subtree_array(ett, array_length(ett));
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
"CHAP message", HFILL }}
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
static gint *ett[] = {
&ett_ipv6cp,
&ett_ipv6cp_options,
&ett_ipv6cp_if_id_opt,
&ett_ipv6cp_compress_opt
};
proto_ipv6cp = proto_register_protocol("PPP IPv6 Control Protocol",
"PPP IPV6CP", "ipv6cp");
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
{ "Sequence", "crtp.seq", FT_UINT8, BASE_DEC, NULL, 0x0f,
"The sequence of the compressed packet.", HFILL }},
{ &hf_iphc_crtp_fh_flags,
{ "Flags", "crtp.fh_flags", FT_UINT8, BASE_HEX, VALS(iphc_crtp_fh_flags),
0xc0, "The flags of the full header packet.", HFILL }},
{ &hf_iphc_crtp_cs_flags,
{ "Flags", "crtp.cs_flags", FT_UINT8, BASE_DEC, VALS(iphc_crtp_cs_flags),
0x0, "The flags of the context state packet.", HFILL }},
{ &hf_iphc_crtp_cs_cnt,
{ "Count", "crtp.cnt", FT_UINT8, BASE_DEC, NULL, 0x0,
"The count of the context state packet.", HFILL }},
{ &hf_iphc_crtp_cs_invalid,
{ "Invalid", "crtp.invalid", FT_BOOLEAN, 8, NULL, 0x80,
"The invalid bit of the context state packet.", HFILL }}
};
static gint *ett[] = {
&ett_iphc_crtp,
&ett_iphc_crtp_hdr,
&ett_iphc_crtp_info
};
proto_iphc_crtp = proto_register_protocol("CRTP", "CRTP", "crtp");
proto_register_field_array(proto_iphc_crtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_iphc_crtp(void)
{
dissector_handle_t fh_handle;
dissector_handle_t cudp16_handle;
dissector_handle_t cudp8_handle;
dissector_handle_t cs_handle;
fh_handle = create_dissector_handle(dissect_iphc_crtp_fh, proto_iphc_crtp);
dissector_add_uint("ppp.protocol", PPP_RTP_FH, fh_handle);
cudp16_handle = create_dissector_handle(dissect_iphc_crtp_cudp16,
proto_iphc_crtp);
dissector_add_uint("ppp.protocol", PPP_RTP_CUDP16, cudp16_handle);
cudp8_handle = create_dissector_handle(dissect_iphc_crtp_cudp8,
proto_iphc_crtp);
dissector_add_uint("ppp.protocol", PPP_RTP_CUDP8, cudp8_handle);
cs_handle = create_dissector_handle(dissect_iphc_crtp_cs, proto_iphc_crtp);
dissector_add_uint("ppp.protocol", PPP_RTP_CS, cs_handle);
dissector_add_uint("ethertype", PPP_RTP_FH, fh_handle);
dissector_add_uint("ethertype", PPP_RTP_CUDP16, cudp16_handle);
dissector_add_uint("ethertype", PPP_RTP_CUDP8, cudp16_handle);
dissector_add_uint("ethertype", PPP_RTP_CS, cs_handle);
}
