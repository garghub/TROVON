static void
dissect_slow_protocols(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 subtype;
proto_tree *pdu_tree;
proto_item *pdu_item;
subtype = tvb_get_guint8(tvb, 0);
switch (subtype)
{
case LACP_SUBTYPE:
dissect_lacp_pdu(tvb, pinfo, tree);
break;
case MARKER_SUBTYPE:
dissect_marker_pdu(tvb, pinfo, tree);
break;
case OAM_SUBTYPE:
dissect_oampdu(tvb, pinfo, tree);
break;
case OSSP_SUBTYPE:
dissect_ossp_pdu(tvb, pinfo, tree);
break;
default:
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Slow Protocols");
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown Subtype = %u.", subtype);
if (tree)
{
pdu_item = proto_tree_add_item(tree, proto_slow, tvb,
0, -1, ENC_NA);
pdu_tree = proto_item_add_subtree(pdu_item, ett_pdu);
proto_tree_add_item(pdu_tree, hf_slow_subtype, tvb,
0, 1, ENC_BIG_ENDIAN);
}
break;
}
}
}
static void
dissect_lacp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 raw_word;
guint8 raw_octet;
guint8 flags;
proto_tree *lacpdu_tree;
proto_item *lacpdu_item;
proto_tree *actor_flags_tree;
proto_item *actor_flags_item;
proto_tree *partner_flags_tree;
proto_item *partner_flags_item;
const char *sep;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LACP");
col_set_str(pinfo->cinfo, COL_INFO, "Link Aggregation Control Protocol");
if (tree)
{
lacpdu_item = proto_tree_add_protocol_format(tree, proto_slow, tvb,
0, -1, "Link Aggregation Control Protocol");
lacpdu_tree = proto_item_add_subtree(lacpdu_item, ett_lacpdu);
proto_tree_add_item(lacpdu_tree, hf_slow_subtype, tvb,
0, 1, ENC_BIG_ENDIAN);
raw_octet = tvb_get_guint8(tvb, LACPDU_VERSION_NUMBER);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_version_number, tvb,
LACPDU_VERSION_NUMBER, 1, raw_octet);
col_append_fstr(pinfo->cinfo, COL_INFO, "Version %d. ", raw_octet);
raw_octet = tvb_get_guint8(tvb, LACPDU_ACTOR_TYPE);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_type, tvb,
LACPDU_ACTOR_TYPE, 1, raw_octet);
raw_octet = tvb_get_guint8(tvb, LACPDU_ACTOR_INFO_LEN);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_info_len, tvb,
LACPDU_ACTOR_INFO_LEN, 1, raw_octet);
raw_word = tvb_get_ntohs(tvb, LACPDU_ACTOR_SYS_PRIORITY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_sys_priority, tvb,
LACPDU_ACTOR_SYS_PRIORITY, 2, raw_word);
proto_tree_add_item(lacpdu_tree, hf_lacpdu_actor_sys, tvb,
LACPDU_ACTOR_SYSTEM, 6, ENC_NA);
raw_word = tvb_get_ntohs(tvb, LACPDU_ACTOR_KEY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_key, tvb,
LACPDU_ACTOR_KEY, 2, raw_word);
raw_word = tvb_get_ntohs(tvb, LACPDU_ACTOR_PORT_PRIORITY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_port_priority, tvb,
LACPDU_ACTOR_PORT_PRIORITY, 2, raw_word);
raw_word = tvb_get_ntohs(tvb, LACPDU_ACTOR_PORT);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_port, tvb,
LACPDU_ACTOR_PORT, 2, raw_word);
col_append_fstr(pinfo->cinfo, COL_INFO, "Actor Port = %d ", raw_word);
flags = tvb_get_guint8(tvb, LACPDU_ACTOR_STATE);
actor_flags_item = proto_tree_add_uint(lacpdu_tree, hf_lacpdu_actor_state, tvb,
LACPDU_ACTOR_STATE, 1, flags);
actor_flags_tree = proto_item_add_subtree(actor_flags_item, ett_lacpdu_a_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_ACTIVITY, actor_flags_item,
"%sActivity");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_activity, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_TIMEOUT, actor_flags_item,
"%sTimeout");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_timeout, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_AGGREGATION, actor_flags_item,
"%sAggregation");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_aggregation, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_SYNC, actor_flags_item,
"%sSynchronization");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_sync, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_COLLECTING, actor_flags_item,
"%sCollecting");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_collecting, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DISTRIB, actor_flags_item,
"%sDistributing");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_distrib, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DEFAULTED, actor_flags_item,
"%sDefaulted");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_defaulted, tvb,
LACPDU_ACTOR_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_EXPIRED, actor_flags_item,
"%sExpired");
proto_tree_add_boolean(actor_flags_tree, hf_lacpdu_flags_a_expired, tvb,
LACPDU_ACTOR_STATE, 1, flags);
if (sep != initial_sep)
{
proto_item_append_text(actor_flags_item, ")");
}
proto_tree_add_item(lacpdu_tree, hf_lacpdu_actor_reserved, tvb,
LACPDU_ACTOR_RESERVED, 3, ENC_NA);
raw_octet = tvb_get_guint8(tvb, LACPDU_PARTNER_TYPE);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_type, tvb,
LACPDU_PARTNER_TYPE, 1, raw_octet);
raw_octet = tvb_get_guint8(tvb, LACPDU_PARTNER_INFO_LEN);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_info_len, tvb,
LACPDU_PARTNER_INFO_LEN, 1, raw_octet);
raw_word = tvb_get_ntohs(tvb, LACPDU_PARTNER_SYS_PRIORITY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_sys_priority, tvb,
LACPDU_PARTNER_SYS_PRIORITY, 2, raw_word);
proto_tree_add_item(lacpdu_tree, hf_lacpdu_partner_sys, tvb,
LACPDU_PARTNER_SYSTEM, 6, ENC_NA);
raw_word = tvb_get_ntohs(tvb, LACPDU_PARTNER_KEY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_key, tvb,
LACPDU_PARTNER_KEY, 2, raw_word);
raw_word = tvb_get_ntohs(tvb, LACPDU_PARTNER_PORT_PRIORITY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_port_priority, tvb,
LACPDU_PARTNER_PORT_PRIORITY, 2, raw_word);
raw_word = tvb_get_ntohs(tvb, LACPDU_PARTNER_PORT);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_port, tvb,
LACPDU_PARTNER_PORT, 2, raw_word);
col_append_fstr(pinfo->cinfo, COL_INFO, "Partner Port = %d ", raw_word);
flags = tvb_get_guint8(tvb, LACPDU_PARTNER_STATE);
partner_flags_item = proto_tree_add_uint(lacpdu_tree, hf_lacpdu_partner_state, tvb,
LACPDU_PARTNER_STATE, 1, flags);
partner_flags_tree = proto_item_add_subtree(partner_flags_item, ett_lacpdu_p_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_ACTIVITY, partner_flags_item,
"%sActivity");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_activity, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_TIMEOUT, partner_flags_item,
"%sTimeout");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_timeout, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_AGGREGATION, partner_flags_item,
"%sAggregation");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_aggregation, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_SYNC, partner_flags_item,
"%sSynchronization");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_sync, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_COLLECTING, partner_flags_item,
"%sCollecting");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_collecting, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DISTRIB, partner_flags_item,
"%sDistributing");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_distrib, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_DEFAULTED, partner_flags_item,
"%sDefaulted");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_defaulted, tvb,
LACPDU_PARTNER_STATE, 1, flags);
APPEND_BOOLEAN_FLAG(flags & LACPDU_FLAGS_EXPIRED, partner_flags_item,
"%sExpired");
proto_tree_add_boolean(partner_flags_tree, hf_lacpdu_flags_p_expired, tvb,
LACPDU_PARTNER_STATE, 1, flags);
if (sep != initial_sep)
{
proto_item_append_text(partner_flags_item, ")");
}
proto_tree_add_item(lacpdu_tree, hf_lacpdu_partner_reserved, tvb,
LACPDU_PARTNER_RESERVED, 3, ENC_NA);
raw_octet = tvb_get_guint8(tvb, LACPDU_COLL_TYPE);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_coll_type, tvb,
LACPDU_COLL_TYPE, 1, raw_octet);
raw_octet = tvb_get_guint8(tvb, LACPDU_COLL_INFO_LEN);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_coll_info_len, tvb,
LACPDU_COLL_INFO_LEN, 1, raw_octet);
raw_word = tvb_get_ntohs(tvb, LACPDU_COLL_MAX_DELAY);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_coll_max_delay, tvb,
LACPDU_COLL_MAX_DELAY, 2, raw_word);
proto_tree_add_item(lacpdu_tree, hf_lacpdu_coll_reserved, tvb,
LACPDU_COLL_RESERVED, 12, ENC_NA);
raw_octet = tvb_get_guint8(tvb, LACPDU_TERM_TYPE);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_term_type, tvb,
LACPDU_TERM_TYPE, 1, raw_octet);
raw_octet = tvb_get_guint8(tvb, LACPDU_TERM_LEN);
proto_tree_add_uint(lacpdu_tree, hf_lacpdu_term_len, tvb,
LACPDU_TERM_LEN, 1, raw_octet);
proto_tree_add_item(lacpdu_tree, hf_lacpdu_term_reserved, tvb,
LACPDU_TERM_RESERVED, 50, ENC_NA);
}
}
static void
dissect_marker_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 raw_octet;
guint16 raw_word;
guint32 dword;
guint32 offset;
proto_tree *marker_tree;
proto_item *marker_item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MARKER");
col_set_str(pinfo->cinfo, COL_INFO, "Marker Protocol");
if (tree)
{
marker_item = proto_tree_add_protocol_format(tree, proto_slow, tvb,
0, -1, "Marker Protocol");
marker_tree = proto_item_add_subtree(marker_item, ett_marker);
proto_tree_add_item(marker_tree, hf_slow_subtype, tvb,
0, 1, ENC_BIG_ENDIAN);
offset = 1;
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(marker_tree, hf_marker_version_number, tvb,
offset, 1, raw_octet);
offset += 1;
while (1)
{
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet==0) break;
proto_tree_add_uint(marker_tree, hf_marker_tlv_type, tvb,
offset, 1, raw_octet);
offset += 1;
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(marker_tree, hf_marker_tlv_length, tvb,
offset, 1, raw_octet);
offset += 1;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(marker_tree, hf_marker_req_port, tvb,
offset, 2, raw_word);
offset += 2;
proto_tree_add_item(marker_tree, hf_marker_req_system, tvb,
offset, 6, ENC_NA);
offset += 6;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(marker_tree, hf_marker_req_trans_id, tvb,
offset, 4, dword);
offset += 2;
offset += 2;
}
}
}
static void
dissect_ossp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
const gchar *str;
proto_item *oui_item, *ossp_item;
proto_tree *ossp_tree;
tvbuff_t *ossp_tvb;
const guint8 itu_oui[] = {ITU_OUI_0, ITU_OUI_1, ITU_OUI_2};
str = tvb_get_manuf_name(tvb, offset+1);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OSSP");
col_add_fstr(pinfo->cinfo, COL_INFO, "OUI: %s", str);
ossp_item = proto_tree_add_protocol_format(tree, proto_slow, tvb, 0, -1,
"Organization Specific Slow Protocol");
ossp_tree = proto_item_add_subtree(ossp_item, ett_ossppdu);
proto_tree_add_item(ossp_tree, hf_slow_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oui_item = proto_tree_add_item(ossp_tree, hf_ossp_oui,
tvb, offset, OUI_SIZE, ENC_NA);
proto_item_append_text(oui_item, " (%s)", str);
offset += 3;
ossp_tvb = tvb_new_subset_remaining(tvb, offset);
if (tvb_memeql(tvb, 1, itu_oui, OUI_SIZE) == 0)
{
dissect_itu_ossp(ossp_tvb, pinfo, ossp_tree);
}
#if 0
else if (tvb_memeql(tvb, 1, xxx_oui, OUI_SIZE) == 0)
{
dissect_xxx_ossp(ossp_tvb, pinfo, ossp_tree);
}
else if (tvb_memeql(tvb, 1, yyy_oui, OUI_SIZE) == 0)
{
dissect_yyy_ossp(ossp_tvb, pinfo, ossp_tree);
}
#endif
else
{
proto_item_append_text(oui_item, " (Unknown OSSP organization)");
}
}
static void
dissect_itu_ossp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 subtype;
proto_tree *itu_ossp_tree, *ti;
subtype = tvb_get_ntohs(tvb, 0);
ti = proto_tree_add_item(tree, hf_itu_subtype, tvb, 0, 2, ENC_BIG_ENDIAN);
itu_ossp_tree = proto_item_add_subtree(ti, ett_itu_ossp);
switch (subtype)
{
case ESMC_ITU_SUBTYPE:
dissect_esmc_pdu(tvb, pinfo, itu_ossp_tree);
break;
#if 0
case XXXX_ITU_SUBTYPE:
dissect_xxxx_pdu(tvb, pinfo, itu_ossp_tree);
break;
#endif
default:
proto_item_append_text(itu_ossp_tree, " (Unknown)");
}
}
static void
dissect_esmc_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *treex)
{
gint offset = 2;
gboolean event_flag;
gboolean malformed = FALSE;
gint ql = -1;
gboolean timestamp_valid_flag = FALSE;
gint32 timestamp = -1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESMC");
proto_item_append_text(treex, ": ESMC");
{
proto_tree *tree_a;
tree_a = proto_item_add_subtree(treex, ett_esmc);
{
proto_item *item_b;
item_b = proto_tree_add_item(tree_a, hf_esmc_version, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, offset) >> 4) != ESMC_VERSION_1)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_b, &ei_esmc_version_compliance, "Version must be 0x%.1x claim compliance with Version 1 of this protocol", ESMC_VERSION_1);
}
}
{
event_flag = ((tvb_get_guint8(tvb, offset) & 0x08) != 0);
proto_tree_add_item(tree_a, hf_esmc_event_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if (pref_decode_esmc_timestamp)
{
timestamp_valid_flag = ((tvb_get_guint8(tvb, offset) & 0x04) != 0);
proto_tree_add_item(tree_a, hf_esmc_timestamp_valid_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
{
proto_item *item_b;
guint32 reserved;
reserved = tvb_get_ntohl(tvb, offset)
& (pref_decode_esmc_timestamp ? 0x3ffffff : 0x7ffffff);
item_b = proto_tree_add_uint_format_value(tree_a, hf_esmc_reserved_32, tvb, offset, 4
, reserved, "0x%.7x", reserved);
if (reserved != 0x0)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_b, &ei_esmc_reserved_not_zero, "Reserved bits must be set to all zero on transmitter");
}
offset += 4;
}
proto_item_append_text(treex, ", Event:%s", event_flag ?
"Time-critical" : "Information");
{
proto_item *item_b;
guint8 type;
item_b = proto_tree_add_item(tree_a, hf_esmc_tlv, tvb, offset, 4, ENC_NA);
{
proto_tree *tree_b;
tree_b = proto_item_add_subtree(item_b, ett_esmc);
{
proto_item *item_c;
guint16 length;
guint8 unused;
type = tvb_get_guint8(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (type != ESMC_QL_TLV_TYPE)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_ql_type_not_first, "TLV Type must be == 0x%.2x (QL) because QL TLV must be first in the ESMC PDU", ESMC_QL_TLV_TYPE);
expert_add_info(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_ql_type);
}
offset += 1;
length = tvb_get_ntohs(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length != ESMC_QL_TLV_LENGTH)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_length_bad, "QL TLV Length must be == 0x%.4x", ESMC_QL_TLV_LENGTH);
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_ql_type, "Let's decode this TLV as if Length has valid value");
}
offset += 2;
unused = tvb_get_guint8(tvb, offset);
ql = unused & 0x0f;
unused &= 0xf0;
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_ql_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
if (unused != 0x00)
{
malformed = TRUE;
expert_add_info(pinfo, item_c, &ei_esmc_tlv_ql_unused_not_zero);
}
if (NULL != try_val_to_str(ql, esmc_quality_level_opt_1_vals))
{
proto_tree_add_item(tree_b, hf_esmc_quality_level_opt_1, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
item_c = proto_tree_add_item(tree_b, hf_esmc_quality_level_invalid, tvb, offset, 1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, item_c, &ei_esmc_quality_level_invalid);
}
offset += 1;
}
}
proto_item_append_text(item_b, ", %s"
, val_to_str(ql, esmc_quality_level_opt_1_vals_short, "QL-INV%d"));
}
proto_item_append_text(treex, ", %s"
, val_to_str(ql, esmc_quality_level_opt_1_vals_short, "QL-INV%d"));
if (pref_decode_esmc_timestamp)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
if (timestamp_valid_flag || type == ESMC_TIMESTAMP_TLV_TYPE)
{
proto_item *item_b;
item_b = proto_tree_add_item(tree_a, hf_esmc_tlv, tvb, offset, 8, ENC_NA);
{
proto_tree *tree_b;
tree_b = proto_item_add_subtree(item_b, ett_esmc);
{
proto_item *item_c;
guint16 length;
guint8 reserved;
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (type != ESMC_TIMESTAMP_TLV_TYPE)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_not_timestamp, "TLV Type must be == 0x%.2x (Timestamp) because Timestamp Valid Flag is set", ESMC_TIMESTAMP_TLV_TYPE);
expert_add_info(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_timestamp);
}
offset += 1;
length = tvb_get_ntohs(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length != ESMC_TIMESTAMP_TLV_LENGTH)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_length_bad, "Timestamp TLV Length must be == 0x%.4x", ESMC_TIMESTAMP_TLV_LENGTH);
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_timestamp, "Let's decode this TLV as if Length has valid value");
}
offset += 2;
timestamp = (gint32)tvb_get_ntohl(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
if (!timestamp_valid_flag) proto_item_append_text(item_c, " [invalid]");
offset += 4;
reserved = tvb_get_guint8(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_ts_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
if (reserved != 0x0)
{
expert_add_info(pinfo, item_c, &ei_esmc_reserved_not_zero);
}
offset += 1;
}
}
proto_item_append_text(item_b, ", Timestamp: %d ns", timestamp);
if (!timestamp_valid_flag) proto_item_append_text(item_b, " [invalid]");
}
}
if (timestamp_valid_flag)
{
proto_item_append_text(treex, ", Timestamp:%d", timestamp);
}
}
{
gint padding_size;
padding_size = tvb_length_remaining(tvb, offset);
if (0 != padding_size)
{
proto_tree* tree_a;
tree_a = proto_item_add_subtree(treex, ett_esmc);
{
proto_item* item_b;
tvbuff_t* tvb_next;
tvb_next = tvb_new_subset(tvb, offset, padding_size, -1);
item_b = proto_tree_add_item(tree_a, hf_esmc_padding, tvb_next, 0, -1, ENC_NA);
proto_item_append_text(item_b, ", %d %s%s", padding_size
, "octet", plurality(padding_size,"","s"));
{
proto_tree* tree_b;
tree_b = proto_item_add_subtree(item_b, ett_esmc);
call_dissector(dh_data, tvb_next, pinfo, tree_b);
}
}
}
}
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "Event:%s", event_flag ?
"Time-critical" : "Information");
if (ql >= 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s"
, val_to_str(ql, esmc_quality_level_opt_1_vals_short, "QL-INVALID-%d"));
}
if (timestamp_valid_flag)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", TS:%d", timestamp);
}
if (malformed)
{
col_append_str(pinfo->cinfo, COL_INFO, ", Malformed PDU");
}
}
static void
dissect_oampdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 oampdu_code;
guint16 flags,state;
guint32 i;
proto_tree *oampdu_tree;
proto_item *oampdu_item;
proto_tree *flags_tree;
proto_item *flags_item;
const char *sep = initial_sep;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OAM");
oampdu_code = tvb_get_guint8(tvb, OAMPDU_CODE);
switch (oampdu_code)
{
case OAMPDU_INFORMATION:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU: Information");
break;
case OAMPDU_EVENT_NOTIFICATION:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU: Event Notification");
break;
case OAMPDU_VAR_REQUEST:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU: Variable Request");
break;
case OAMPDU_VAR_RESPONSE:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU: Variable Response");
break;
case OAMPDU_LOOPBACK_CTRL:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU: Loopback Control");
break;
case OAMPDU_VENDOR_SPECIFIC:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU: Organization Specific");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "OAMPDU reserved");
break;
}
if (tree)
{
oampdu_item = proto_tree_add_protocol_format(tree, proto_slow, tvb,
0, -1, "OAM Protocol");
oampdu_tree = proto_item_add_subtree(oampdu_item, ett_oampdu);
proto_tree_add_item(oampdu_tree, hf_slow_subtype, tvb,
0, 1, ENC_BIG_ENDIAN);
flags = tvb_get_ntohs(tvb, OAMPDU_FLAGS);
flags_item = proto_tree_add_uint(oampdu_tree, hf_oampdu_flags, tvb,
OAMPDU_FLAGS, 2, flags);
flags_tree = proto_item_add_subtree(flags_item, ett_oampdu_flags);
APPEND_BOOLEAN_FLAG(flags & OAMPDU_FLAGS_LINK_FAULT, flags_item,
"%sLink Fault");
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_link_fault,
tvb, OAMPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & OAMPDU_FLAGS_DYING_GASP, flags_item,
"%sDying Gasp");
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_dying_gasp,
tvb, OAMPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & OAMPDU_FLAGS_CRITICAL_EVENT, flags_item,
"%sCriticalEvent");
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_critical_event,
tvb, OAMPDU_FLAGS, 1, flags);
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_local_evaluating,
tvb, OAMPDU_FLAGS, 1, flags);
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_local_stable,
tvb, OAMPDU_FLAGS, 1, flags);
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_remote_evaluating,
tvb, OAMPDU_FLAGS, 1, flags);
proto_tree_add_boolean(flags_tree, hf_oampdu_flags_remote_stable,
tvb, OAMPDU_FLAGS, 1, flags);
if (sep != cont_sep)
proto_item_append_text(flags_item, " (");
else
proto_item_append_text(flags_item, ", ");
for(i=0;i<2;i++)
{
if (i==0)
{
proto_item_append_text(flags_item, "local: ");
state = (flags&(OAMPDU_FLAGS_LOCAL_EVAL|OAMPDU_FLAGS_LOCAL_STABLE));
state = state>>3;
}
else
{
proto_item_append_text(flags_item, "remote: ");
state = (flags&(OAMPDU_FLAGS_REMOTE_EVAL|OAMPDU_FLAGS_REMOTE_STABLE));
state = state>>5;
}
switch (state)
{
case 0:
proto_item_append_text(flags_item, "Unsatisfied");
break;
case 1:
proto_item_append_text(flags_item, "Discovery in process");
break;
case 2:
proto_item_append_text(flags_item, "Discovery complete");
break;
default:
proto_item_append_text(flags_item, "Reserved");
break;
}
if (i==0)
proto_item_append_text(flags_item, ", ");
}
proto_item_append_text(flags_item, ")");
oampdu_code = tvb_get_guint8(tvb, OAMPDU_CODE);
proto_tree_add_uint(oampdu_tree, hf_oampdu_code, tvb,
OAMPDU_CODE, 1, oampdu_code);
switch (oampdu_code)
{
case OAMPDU_INFORMATION:
dissect_oampdu_information(tvb, oampdu_tree);
break;
case OAMPDU_EVENT_NOTIFICATION:
dissect_oampdu_event_notification(tvb, pinfo, oampdu_tree);
break;
case OAMPDU_VAR_REQUEST:
dissect_oampdu_variable_request(tvb, oampdu_tree);
break;
case OAMPDU_VAR_RESPONSE:
dissect_oampdu_variable_response(tvb, oampdu_tree);
break;
case OAMPDU_LOOPBACK_CTRL:
dissect_oampdu_loopback_control(tvb, oampdu_tree);
break;
case OAMPDU_VENDOR_SPECIFIC:
dissect_oampdu_vendor_specific(tvb, oampdu_tree);
default:
break;
}
}
}
static void
dissect_oampdu_information(tvbuff_t *tvb, proto_tree *tree)
{
guint16 raw_word;
guint8 raw_octet;
guint8 info_type;
guint32 offset;
guint16 bytes;
const guint8 *ptr;
proto_tree *info_tree;
proto_item *info_item;
proto_tree *state_tree;
proto_item *state_item;
proto_tree *cfg_tree;
proto_item *cfg_item;
proto_item *oui_item;
proto_item *item;
offset = OAMPDU_HEADER_SIZE;
while (1)
{
bytes = tvb_length_remaining(tvb, offset);
if (bytes < 1) break;
info_type = tvb_get_guint8(tvb, offset);
if (info_type == OAMPDU_INFO_TYPE_ENDMARKER) break;
info_item = proto_tree_add_uint(tree, hf_oampdu_info_type, tvb,
offset, 1, info_type);
switch (info_type)
{
case OAMPDU_INFO_TYPE_LOCAL:
info_tree = proto_item_add_subtree(info_item, ett_oampdu_local_info);
break;
case OAMPDU_INFO_TYPE_REMOTE:
info_tree = proto_item_add_subtree(info_item, ett_oampdu_remote_info);
break;
case OAMPDU_INFO_TYPE_ORG:
info_tree = proto_item_add_subtree(info_item, ett_oampdu_org_info);
break;
default:
info_tree = NULL;
break;
}
offset += OAMPDU_INFO_TYPE_SZ;
if ((info_type==OAMPDU_INFO_TYPE_LOCAL)||(info_type==OAMPDU_INFO_TYPE_REMOTE))
{
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(info_tree, hf_oampdu_info_len,
tvb, offset, 1, raw_octet);
offset += OAMPDU_INFO_LENGTH_SZ;
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(info_tree, hf_oampdu_info_version,
tvb, offset, 1, raw_octet);
offset += OAMPDU_INFO_VERSION_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(info_tree, hf_oampdu_info_revision,
tvb, offset, 2, raw_word);
offset += OAMPDU_INFO_REVISION_SZ;
raw_octet = tvb_get_guint8(tvb, offset);
state_item = proto_tree_add_uint(info_tree, hf_oampdu_info_state,
tvb, offset, 1, raw_octet);
if (raw_octet == OAMPDU_INFO_TYPE_LOCAL)
state_tree = proto_item_add_subtree(state_item, ett_oampdu_local_info_state);
else
state_tree = proto_item_add_subtree(state_item, ett_oampdu_remote_info_state);
proto_tree_add_uint(state_tree, hf_oampdu_info_state_parser,
tvb, offset, 1, raw_octet);
proto_tree_add_boolean(state_tree, hf_oampdu_info_state_mux,
tvb, offset, 1, raw_octet);
offset += OAMPDU_INFO_STATE_SZ;
raw_octet = tvb_get_guint8(tvb, offset);
cfg_item = proto_tree_add_uint(info_tree, hf_oampdu_info_oamConfig,
tvb, offset, 1, raw_octet);
if (raw_octet == OAMPDU_INFO_TYPE_LOCAL)
cfg_tree = proto_item_add_subtree(cfg_item, ett_oampdu_local_info_config);
else
cfg_tree = proto_item_add_subtree(cfg_item, ett_oampdu_remote_info_config);
proto_tree_add_boolean(cfg_tree, hf_oampdu_info_oamConfig_mode,
tvb, offset, 1, raw_octet);
proto_tree_add_boolean(cfg_tree, hf_oampdu_info_oamConfig_uni,
tvb, offset, 1, raw_octet);
proto_tree_add_boolean(cfg_tree, hf_oampdu_info_oamConfig_lpbk,
tvb, offset, 1, raw_octet);
proto_tree_add_boolean(cfg_tree, hf_oampdu_info_oamConfig_event,
tvb, offset, 1, raw_octet);
proto_tree_add_boolean(cfg_tree, hf_oampdu_info_oamConfig_var,
tvb, offset, 1, raw_octet);
offset += OAMPDU_INFO_OAM_CONFIG_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
item = proto_tree_add_uint(info_tree, hf_oampdu_info_oampduConfig,
tvb, offset, 2, raw_word);
proto_item_append_text(item, " (bytes)");
offset += OAMPDU_INFO_OAMPDU_CONFIG_SZ;
oui_item = proto_tree_add_item(info_tree, hf_oampdu_info_oui,
tvb, offset, 3, ENC_NA);
APPEND_OUI_NAME(oui_item, ptr, tvb, offset);
offset += OAMPDU_INFO_OUI_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_vendor,
tvb, offset, 4, ENC_NA);
offset += OAMPDU_INFO_VENDOR_SPECIFIC_SZ;
}
else if (info_type == OAMPDU_INFO_TYPE_ORG)
{
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(info_tree, hf_oampdu_info_len,
tvb, offset, 1, raw_octet);
offset += OAMPDU_INFO_LENGTH_SZ;
oui_item = proto_tree_add_item(info_tree, hf_oampdu_info_oui,
tvb, offset, 3, ENC_NA);
APPEND_OUI_NAME(oui_item, ptr, tvb, offset);
offset += OAMPDU_INFO_OUI_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_vendor,
tvb, offset, raw_octet-5, ENC_NA);
offset += raw_octet-5;
}
else
{
raw_octet = tvb_get_guint8(tvb, offset);
offset += raw_octet;
}
}
}
static void
dissect_oampdu_event_notification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 raw_octet;
guint16 raw_word;
guint32 dword;
guint64 big;
guint8 event_type;
guint32 offset;
guint16 bytes;
proto_tree *event_tree;
proto_item *event_item;
offset = OAMPDU_HEADER_SIZE;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_event_sequence,
tvb, offset, 2, raw_word);
offset += OAMPDU_EVENT_SEQUENCE_SZ;
while (1)
{
bytes = tvb_length_remaining(tvb, offset);
if (bytes < 1) break;
event_type = tvb_get_guint8(tvb, offset);
if (event_type == OAMPDU_EVENT_TYPE_END) break;
event_item = proto_tree_add_uint(tree, hf_oampdu_event_type,
tvb, offset, 1, event_type);
offset += OAMPDU_EVENT_TYPE_SZ;
switch (event_type)
{
case OAMPDU_EVENT_TYPE_ESPE:
{
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_espe);
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_length,
tvb, offset, 1, raw_octet);
offset += OAMPDU_EVENT_LENGTH_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, raw_word);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
big = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(event_tree, hf_oampdu_event_espeWindow,
tvb, offset, 8, big);
offset += OAMPDU_ESPE_WINDOW_SZ;
big = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(event_tree, hf_oampdu_event_espeThreshold,
tvb, offset, 8, big);
offset += OAMPDU_ESPE_THRESHOLD_SZ;
big = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(event_tree, hf_oampdu_event_espeErrors,
tvb, offset, 8, big);
offset += OAMPDU_ESPE_ERRORS_SZ;
big = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(event_tree, hf_oampdu_event_espeTotalErrors,
tvb, offset, 8, big);
offset += OAMPDU_ESPE_ERR_TOTAL_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_espeTotalEvents,
tvb, offset, 4, dword);
offset += OAMPDU_ESPE_TOTAL_SZ;
break;
}
case OAMPDU_EVENT_TYPE_EFE:
{
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_efe);
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_length,
tvb, offset, 1, raw_octet);
offset += OAMPDU_EVENT_LENGTH_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, raw_word);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efeWindow,
tvb, offset, 2, raw_word);
offset += OAMPDU_EFE_WINDOW_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efeThreshold,
tvb, offset, 4, dword);
offset += OAMPDU_EFE_THRESHOLD_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efeErrors,
tvb, offset, 4, dword);
offset += OAMPDU_EFE_ERRORS_SZ;
big = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(event_tree, hf_oampdu_event_efeTotalErrors,
tvb, offset, 8, big);
offset += OAMPDU_EFE_ERR_TOTAL_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efeTotalEvents,
tvb, offset, 4, dword);
offset += OAMPDU_EFE_TOTAL_SZ;
break;
}
case OAMPDU_EVENT_TYPE_EFPE:
{
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_efpe);
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_length,
tvb, offset, 1, raw_octet);
offset += OAMPDU_EVENT_LENGTH_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, raw_word);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efpeWindow,
tvb, offset, 4, dword);
offset += OAMPDU_EFPE_WINDOW_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efpeThreshold,
tvb, offset, 4, dword);
offset += OAMPDU_EFPE_THRESHOLD_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efpeErrors,
tvb, offset, 4, dword);
offset += OAMPDU_EFPE_ERRORS_SZ;
big = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(event_tree, hf_oampdu_event_efpeTotalErrors,
tvb, offset, 8, big);
offset += OAMPDU_EFPE_ERR_TOTAL_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efpeTotalEvents,
tvb, offset, 4, dword);
offset += OAMPDU_EFPE_TOTAL_SZ;
break;
}
case OAMPDU_EVENT_TYPE_EFSSE:
{
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_efsse);
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_length,
tvb, offset, 1, raw_octet);
offset += OAMPDU_EVENT_LENGTH_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, raw_word);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efsseWindow,
tvb, offset, 2, raw_word);
offset += OAMPDU_EFSSE_WINDOW_SZ;
dword = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efsseThreshold,
tvb, offset, 2, dword);
offset += OAMPDU_EFSSE_THRESHOLD_SZ;
dword = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efsseErrors,
tvb, offset, 2, dword);
offset += OAMPDU_EFSSE_ERRORS_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efsseTotalErrors,
tvb, offset, 4, dword);
offset += OAMPDU_EFSSE_ERR_TOTAL_SZ;
dword = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(event_tree, hf_oampdu_event_efsseTotalEvents,
tvb, offset, 4, dword);
offset += OAMPDU_EFSSE_TOTAL_SZ;
break;
}
case OAMPDU_EVENT_TYPE_OSE:
{
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_ose);
raw_octet = tvb_get_guint8(tvb, offset);
event_item = proto_tree_add_uint(event_tree, hf_oampdu_event_length,
tvb, offset, 1, raw_octet);
offset += OAMPDU_EVENT_LENGTH_SZ;
if (raw_octet < 2)
{
expert_add_info_format(pinfo, event_item, &ei_oampdu_event_length_bad, "Event length should be at least 2");
}
else
{
offset += (raw_octet-2);
}
break;
}
default:
break;
}
}
}
static void
dissect_oampdu_variable_request(tvbuff_t *tvb, proto_tree *tree)
{
guint16 raw_word;
guint8 raw_octet;
guint32 offset;
offset = OAMPDU_HEADER_SIZE;
while (1)
{
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet == 0) break;
proto_tree_add_uint(tree, hf_oampdu_variable_branch,
tvb,offset, 1, raw_octet);
offset+=1;
switch (raw_octet)
{
case OAMPDU_VARS_OBJECT:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_object,
tvb, offset, 2, raw_word);
break;
}
case OAMPDU_VARS_PACKAGE:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_package,
tvb, offset, 2, raw_word);
break;
}
case OAMPDU_VARS_BINDING:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_binding,
tvb, offset, 2, raw_word);
break;
}
case OAMPDU_VARS_ATTRIBUTE:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_attribute,
tvb, offset, 2, raw_word);
break;
}
default:
break;
}
offset+=2;
}
}
static void
dissect_oampdu_variable_response(tvbuff_t *tvb, proto_tree *tree)
{
guint16 raw_word;
guint8 raw_octet;
guint32 offset;
offset = OAMPDU_HEADER_SIZE;
while (1)
{
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet == 0) break;
proto_tree_add_uint(tree, hf_oampdu_variable_branch,
tvb,offset, 1, raw_octet);
offset+=1;
switch (raw_octet)
{
case OAMPDU_VARS_OBJECT:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_object,
tvb, offset, 2, raw_word);
break;
}
case OAMPDU_VARS_PACKAGE:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_package,
tvb, offset, 2, raw_word);
break;
}
case OAMPDU_VARS_BINDING:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_binding,
tvb, offset, 2, raw_word);
break;
}
case OAMPDU_VARS_ATTRIBUTE:
{
raw_word = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_oampdu_variable_attribute,
tvb, offset, 2, raw_word);
break;
}
default:
break;
}
offset+=2;
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet >= 0x80)
{
proto_tree_add_uint(tree, hf_oampdu_variable_indication,
tvb,offset, 1, (raw_octet&0x7F));
offset+=1;
}
else
{
if (raw_octet == 0) raw_octet = 128;
proto_tree_add_uint(tree, hf_oampdu_variable_width,
tvb,offset, 1, raw_octet);
offset+=1;
proto_tree_add_item(tree, hf_oampdu_variable_value,
tvb, offset, raw_octet, ENC_NA);
offset+=raw_octet;
}
}
}
static void
dissect_oampdu_loopback_control(tvbuff_t *tvb, proto_tree *tree)
{
guint8 ctrl;
guint32 offset;
guint16 bytes;
proto_tree *ctrl_tree;
proto_item *ctrl_item;
const char *sep;
offset = OAMPDU_HEADER_SIZE;
bytes = tvb_length_remaining(tvb, offset);
if (bytes >= 1)
{
ctrl = tvb_get_guint8(tvb, offset);
ctrl_item = proto_tree_add_uint(tree, hf_oampdu_lpbk,
tvb, offset, 1, ctrl);
ctrl_tree = proto_item_add_subtree(ctrl_item, ett_oampdu_lpbk_ctrl);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(ctrl & OAMPDU_LPBK_ENABLE, ctrl_item,
"%sEnable Remote Loopack");
proto_tree_add_boolean(ctrl_tree, hf_oampdu_lpbk_enable,
tvb, offset, 1, ctrl);
APPEND_BOOLEAN_FLAG(ctrl & OAMPDU_LPBK_DISABLE, ctrl_item,
"%sDisable Remote Loopback");
proto_tree_add_boolean(ctrl_tree, hf_oampdu_lpbk_disable,
tvb, offset, 1, ctrl);
if (sep != initial_sep)
proto_item_append_text(ctrl_item, ")");
}
}
static void
dissect_oampdu_vendor_specific(tvbuff_t *tvb, proto_tree *tree)
{
guint32 offset;
guint16 bytes;
const guint8 *ptr;
proto_item *oui_item;
offset = OAMPDU_HEADER_SIZE;
bytes = tvb_length_remaining(tvb, offset);
if (bytes >= 3)
{
oui_item = proto_tree_add_item(tree, hf_oampdu_info_oui,
tvb, offset, 3, ENC_NA);
APPEND_OUI_NAME(oui_item, ptr, tvb, offset);
}
}
void
proto_register_slow_protocols(void)
{
static hf_register_info hf[] = {
{ &hf_slow_subtype,
{ "Slow Protocols subtype", "slow.subtype",
FT_UINT8, BASE_HEX, VALS(subtype_vals), 0x0,
"Identifies the LACP version", HFILL }},
{ &hf_lacpdu_version_number,
{ "LACP Version Number", "slow.lacp.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Identifies the LACP version", HFILL }},
{ &hf_lacpdu_actor_type,
{ "Actor Information", "slow.lacp.actorInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Actor", HFILL }},
{ &hf_lacpdu_actor_info_len,
{ "Actor Information Length", "slow.lacp.actorInfoLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Actor TLV", HFILL }},
{ &hf_lacpdu_actor_sys_priority,
{ "Actor System Priority", "slow.lacp.actorSysPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to this System by management or admin", HFILL }},
{ &hf_lacpdu_actor_sys,
{ "Actor System", "slow.lacp.actorSystem",
FT_ETHER, BASE_NONE, NULL, 0x0,
"The Actor's System ID encoded as a MAC address", HFILL }},
{ &hf_lacpdu_actor_key,
{ "Actor Key", "slow.lacp.actorKey",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The operational Key value assigned to the port by the Actor", HFILL }},
{ &hf_lacpdu_actor_port_priority,
{ "Actor Port Priority", "slow.lacp.actorPortPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to the port by the Actor (via Management or Admin)", HFILL }},
{ &hf_lacpdu_actor_port,
{ "Actor Port", "slow.lacp.actorPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The port number assigned to the port by the Actor (via Management or Admin)", HFILL }},
{ &hf_lacpdu_actor_state,
{ "Actor State", "slow.lacp.actorState",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The Actor's state variables for the port, encoded as bits within a single octet", HFILL }},
{ &hf_lacpdu_flags_a_activity,
{ "LACP Activity", "slow.lacp.actorState.activity",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_ACTIVITY,
"Activity control value for this link. Active = 1, Passive = 0", HFILL }},
{ &hf_lacpdu_flags_a_timeout,
{ "LACP Timeout", "slow.lacp.actorState.timeout",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_TIMEOUT,
"Timeout control value for this link. Short Timeout = 1, Long Timeout = 0", HFILL }},
{ &hf_lacpdu_flags_a_aggregation,
{ "Aggregation", "slow.lacp.actorState.aggregation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_AGGREGATION,
"Aggregatable = 1, Individual = 0", HFILL }},
{ &hf_lacpdu_flags_a_sync,
{ "Synchronization", "slow.lacp.actorState.synchronization",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_SYNC,
"In Sync = 1, Out of Sync = 0", HFILL }},
{ &hf_lacpdu_flags_a_collecting,
{ "Collecting", "slow.lacp.actorState.collecting",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_COLLECTING,
"Collection of incoming frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacpdu_flags_a_distrib,
{ "Distributing", "slow.lacp.actorState.distributing",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DISTRIB,
"Distribution of outgoing frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacpdu_flags_a_defaulted,
{ "Defaulted", "slow.lacp.actorState.defaulted",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DEFAULTED,
"1 = Actor Rx machine is using DEFAULT Partner info, 0 = using info in Rx'd LACPDU", HFILL }},
{ &hf_lacpdu_flags_a_expired,
{ "Expired", "slow.lacp.actorState.expired",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_EXPIRED,
"1 = Actor Rx machine is EXPIRED, 0 = is NOT EXPIRED", HFILL }},
{ &hf_lacpdu_actor_reserved,
{ "Reserved", "slow.lacp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lacpdu_partner_type,
{ "Partner Information", "slow.lacp.partnerInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Partner", HFILL }},
{ &hf_lacpdu_partner_info_len,
{ "Partner Information Length", "slow.lacp.partnerInfoLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Partner TLV", HFILL }},
{ &hf_lacpdu_partner_sys_priority,
{ "Partner System Priority", "slow.lacp.partnerSysPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to the Partner System by management or admin", HFILL }},
{ &hf_lacpdu_partner_sys,
{ "Partner System", "slow.lacp.partnerSystem",
FT_ETHER, BASE_NONE, NULL, 0x0,
"The Partner's System ID encoded as a MAC address", HFILL }},
{ &hf_lacpdu_partner_key,
{ "Partner Key", "slow.lacp.partnerKey",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The operational Key value assigned to the port associated with this link by the Partner", HFILL }},
{ &hf_lacpdu_partner_port_priority,
{ "Partner Port Priority", "slow.lacp.partnerPortPriority",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The priority assigned to the port by the Partner (via Management or Admin)", HFILL }},
{ &hf_lacpdu_partner_port,
{ "Partner Port", "slow.lacp.partnerPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The port number associated with this link assigned to the port by the Partner (via Management or Admin)", HFILL }},
{ &hf_lacpdu_partner_state,
{ "Partner State", "slow.lacp.partnerState",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The Partner's state variables for the port, encoded as bits within a single octet", HFILL }},
{ &hf_lacpdu_flags_p_activity,
{ "LACP Activity", "slow.lacp.partnerState.activity",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_ACTIVITY,
"Activity control value for this link. Active = 1, Passive = 0", HFILL }},
{ &hf_lacpdu_flags_p_timeout,
{ "LACP Timeout", "slow.lacp.partnerState.timeout",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_TIMEOUT,
"Timeout control value for this link. Short Timeout = 1, Long Timeout = 0", HFILL }},
{ &hf_lacpdu_flags_p_aggregation,
{ "Aggregation", "slow.lacp.partnerState.aggregation",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_AGGREGATION,
"Aggregatable = 1, Individual = 0", HFILL }},
{ &hf_lacpdu_flags_p_sync,
{ "Synchronization", "slow.lacp.partnerState.synchronization",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_SYNC,
"In Sync = 1, Out of Sync = 0", HFILL }},
{ &hf_lacpdu_flags_p_collecting,
{ "Collecting", "slow.lacp.partnerState.collecting",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_COLLECTING,
"Collection of incoming frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacpdu_flags_p_distrib,
{ "Distributing", "slow.lacp.partnerState.distributing",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DISTRIB,
"Distribution of outgoing frames is: Enabled = 1, Disabled = 0", HFILL }},
{ &hf_lacpdu_flags_p_defaulted,
{ "Defaulted", "slow.lacp.partnerState.defaulted",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_DEFAULTED,
"1 = Actor Rx machine is using DEFAULT Partner info, 0 = using info in Rx'd LACPDU", HFILL }},
{ &hf_lacpdu_flags_p_expired,
{ "Expired", "slow.lacp.partnerState.expired",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), LACPDU_FLAGS_EXPIRED,
"1 = Actor Rx machine is EXPIRED, 0 = is NOT EXPIRED", HFILL }},
{ &hf_lacpdu_partner_reserved,
{ "Reserved", "slow.lacp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lacpdu_coll_type,
{ "Collector Information", "slow.lacp.collectorInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Collector", HFILL }},
{ &hf_lacpdu_coll_info_len,
{ "Collector Information Length", "slow.lacp.collectorInfoLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Collector TLV", HFILL }},
{ &hf_lacpdu_coll_max_delay,
{ "Collector Max Delay", "slow.lacp.collectorMaxDelay",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The max delay of the station tx'ing the LACPDU (in tens of usecs)", HFILL }},
{ &hf_lacpdu_coll_reserved,
{ "Reserved", "slow.lacp.coll_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lacpdu_term_type,
{ "Terminator Information", "slow.lacp.termInfo",
FT_UINT8, BASE_HEX, NULL, 0x0,
"TLV type = Terminator", HFILL }},
{ &hf_lacpdu_term_len,
{ "Terminator Length", "slow.lacp.termLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Terminator TLV", HFILL }},
{ &hf_lacpdu_term_reserved,
{ "Reserved", "slow.lacp.term_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_marker_version_number,
{ "Version Number", "slow.marker.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Identifies the Marker version", HFILL }},
{ &hf_marker_tlv_type,
{ "TLV Type", "slow.marker.tlvType",
FT_UINT8, BASE_HEX, VALS(marker_vals), 0x0,
"Marker TLV type", HFILL }},
{ &hf_marker_tlv_length,
{ "TLV Length", "slow.marker.tlvLen",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The length of the Actor TLV", HFILL }},
{ &hf_marker_req_port,
{ "Requester Port", "slow.marker.requesterPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The Requester Port", HFILL }},
{ &hf_marker_req_system,
{ "Requester System", "slow.marker.requesterSystem",
FT_ETHER, BASE_NONE, NULL, 0x0,
"The Requester System ID encoded as a MAC address", HFILL }},
{ &hf_marker_req_trans_id,
{ "Requester Transaction ID", "slow.marker.requesterTransId",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The Requester Transaction ID", HFILL }},
{ &hf_ossp_oui,
{ "OUI", "slow.ossp.oui",
FT_BYTES, BASE_NONE, NULL, 0,
"IEEE assigned Organizationally Unique Identifier", HFILL }},
{ &hf_itu_subtype,
{ "ITU-T OSSP Subtype", "slow.ossp.itu.subtype",
FT_UINT16, BASE_HEX, NULL, 0,
"Subtype assigned by the ITU-T", HFILL }},
{ &hf_esmc_version,
{ "Version", "slow.esmc.version",
FT_UINT8, BASE_HEX, NULL, 0xf0,
"This field indicates the version of ITU-T SG15 Q13 OSSP frame format", HFILL }},
{ &hf_esmc_event_flag,
{ "Event Flag", "slow.esmc.event_flag",
FT_UINT8, BASE_HEX, VALS(esmc_event_flag_vals), 0x08,
"This bit distinguishes the critical, time sensitive behaviour of the"
" ESMC Event PDU from the ESMC Information PDU", HFILL }},
{ &hf_esmc_timestamp_valid_flag,
{ "Timestamp Valid Flag", "slow.esmc.timestamp_valid_flag",
FT_UINT8, BASE_HEX, VALS(esmc_timestamp_valid_flag_vals), 0x04,
"Indicates validity (i.e. presence) of the Timestamp TLV", HFILL }},
{ &hf_esmc_reserved_32,
{ "Reserved", "slow.esmc.reserved",
FT_UINT32, BASE_HEX, NULL, 0,
"Reserved. Set to all zero at the transmitter and ignored by the receiver", HFILL }},
{ &hf_esmc_tlv,
{ "ESMC TLV", "slow.esmc.tlv",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_esmc_tlv_type,
{ "TLV Type", "slow.esmc.tlv_type",
FT_UINT8, BASE_HEX, VALS(esmc_tlv_type_vals), 0,
NULL, HFILL }},
{ &hf_esmc_tlv_length,
{ "TLV Length", "slow.esmc.tlv_length",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_esmc_tlv_ql_unused,
{ "Unused", "slow.esmc.tlv_ql_unused",
FT_UINT8, BASE_HEX, NULL, 0xf0,
"This field is not used in QL TLV", HFILL }},
{ &hf_esmc_quality_level_opt_1,
{ "SSM Code", "slow.esmc.ql",
FT_UINT8, BASE_HEX, VALS(esmc_quality_level_opt_1_vals), 0x0f,
"Quality Level information", HFILL }},
#if 0
{ &hf_esmc_quality_level_opt_2,
{ "SSM Code", "slow.esmc.ql",
FT_UINT8, BASE_HEX, VALS(esmc_quality_level_opt_2_vals), 0x0f,
"Quality Level information", HFILL }},
#endif
{ &hf_esmc_quality_level_invalid,
{ "SSM Code", "slow.esmc.ql",
FT_UINT8, BASE_HEX, VALS(esmc_quality_level_invalid_vals), 0x0f,
"Quality Level information", HFILL }},
{ &hf_esmc_timestamp,
{ "Timestamp (ns)", "slow.esmc.timestamp",
FT_INT32, BASE_DEC, NULL, 0,
"Timestamp according to the \"whole nanoseconds\" part of the IEEE 1588 originTimestamp", HFILL }},
{ &hf_esmc_tlv_ts_reserved,
{ "Reserved", "slow.esmc.tlv_ts_reserved",
FT_UINT8, BASE_HEX, NULL, 0,
"Reserved. Set to all zero at the transmitter and ignored by the receiver", HFILL }},
{ &hf_esmc_padding,
{ "Padding", "slow.esmc.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"This field contains necessary padding to achieve the minimum frame size of 64 bytes at least", HFILL }},
{ &hf_oampdu_flags,
{ "Flags", "slow.oam.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The Flags Field", HFILL }},
{ &hf_oampdu_flags_link_fault,
{ "Link Fault", "slow.oam.flags.linkFault",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_LINK_FAULT,
"The PHY detected a fault in the receive direction. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_dying_gasp,
{ "Dying Gasp", "slow.oam.flags.dyingGasp",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_DYING_GASP,
"An unrecoverable local failure occurred. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_critical_event,
{ "Critical Event", "slow.oam.flags.criticalEvent",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_CRITICAL_EVENT,
"A critical event has occurred. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_local_evaluating,
{ "Local Evaluating", "slow.oam.flags.localEvaluating",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_LOCAL_EVAL,
"Local DTE Discovery process in progress. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_local_stable,
{ "Local Stable", "slow.oam.flags.localStable",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_LOCAL_STABLE,
"Local DTE is Stable. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_remote_evaluating,
{ "Remote Evaluating", "slow.oam.flags.remoteEvaluating",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_REMOTE_EVAL,
"Remote DTE Discovery process in progress. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_remote_stable,
{ "Remote Stable", "slow.oam.flags.remoteStable",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_REMOTE_STABLE,
"Remote DTE is Stable. True = 1, False = 0", HFILL }},
{ &hf_oampdu_code,
{ "OAMPDU code", "slow.oam.code",
FT_UINT8, BASE_HEX, VALS(code_vals), 0x0,
"Identifies the TLVs code", HFILL }},
{ &hf_oampdu_info_type,
{ "Type", "slow.oam.info.type",
FT_UINT8, BASE_HEX, VALS(info_type_vals), 0x0,
"Identifies the TLV type", HFILL }},
{ &hf_oampdu_info_len,
{ "TLV Length", "slow.oam.info.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the TLVs type", HFILL }},
{ &hf_oampdu_info_version,
{ "TLV Version", "slow.oam.info.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Identifies the TLVs version", HFILL }},
{ &hf_oampdu_info_revision,
{ "TLV Revision", "slow.oam.info.revision",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the TLVs revision", HFILL }},
{ &hf_oampdu_info_state,
{ "OAM DTE States", "slow.oam.info.state",
FT_UINT8, BASE_HEX, NULL, 0x0,
"OAM DTE State of the Mux and the Parser", HFILL }},
{ &hf_oampdu_info_state_parser,
{ "Parser Action", "slow.oam.info.state.parser",
FT_UINT8, BASE_HEX, VALS(parser_vals), 0x03,
NULL, HFILL }},
{ &hf_oampdu_info_state_mux,
{ "Muxiplexer Action", "slow.oam.info.state.muxiplexer",
FT_BOOLEAN, 8, TFS(&mux), 0x04,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig,
{ "OAM Configuration", "slow.oam.info.oamConfig",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_mode,
{ "OAM Mode", "slow.oam.info.oamConfig.mode",
FT_BOOLEAN, 8, TFS(&oam_mode), OAMPDU_INFO_CONFIG_MODE,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_uni,
{ "Unidirectional support", "slow.oam.flags.dyingGasp",
FT_BOOLEAN, 8, TFS(&oam_uni), OAMPDU_INFO_CONFIG_UNI,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_lpbk,
{ "Loopback support", "slow.oam.flags.criticalEvent",
FT_BOOLEAN, 8, TFS(&oam_lpbk), OAMPDU_INFO_CONFIG_LPBK,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_event,
{ "Link Events support", "slow.oam.flags.localEvaluating",
FT_BOOLEAN, 8, TFS(&oam_event), OAMPDU_INFO_CONFIG_EVENT,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_var,
{ "Variable Retrieval", "slow.oam.flags.localStable",
FT_BOOLEAN, 8, TFS(&oam_var), OAMPDU_INFO_CONFIG_VAR,
"Variable Retrieval support", HFILL }},
{ &hf_oampdu_info_oampduConfig,
{ "Max OAMPDU Size", "slow.oam.info.oampduConfig",
FT_UINT16, BASE_DEC, NULL, 0x0,
"OAMPDU Configuration", HFILL }},
{ &hf_oampdu_info_oui,
{ "Organizationally Unique Identifier", "slow.oam.info.oui",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_oampdu_info_vendor,
{ "Vendor Specific Information", "slow.oam.info.vendor",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_oampdu_event_sequence,
{ "Sequence Number", "slow.oam.event.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the Event Notification TLVs", HFILL }},
{ &hf_oampdu_event_type,
{ "Event Type", "slow.oam.event.type",
FT_UINT8, BASE_HEX, VALS(event_type_vals), 0x0,
"Identifies the TLV type", HFILL }},
{ &hf_oampdu_event_length,
{ "Event Length", "slow.oam.event.length",
FT_UINT8, BASE_HEX, NULL, 0x0,
"This field indicates the length in octets of the TLV-tuple", HFILL }},
{ &hf_oampdu_event_timeStamp,
{ "Event Timestamp (100ms)", "slow.oam.event.timestamp",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Event Time Stamp in term of 100 ms intervals", HFILL }},
{ &hf_oampdu_event_espeWindow,
{ "Errored Symbol Window", "slow.oam.event.espeWindow",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols in the period", HFILL }},
{ &hf_oampdu_event_espeThreshold,
{ "Errored Symbol Threshold", "slow.oam.event.espeThreshold",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols required to generate the Event", HFILL }},
{ &hf_oampdu_event_espeErrors,
{ "Errored Symbols", "slow.oam.event.espeErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_espeTotalErrors,
{ "Error Running Total", "slow.oam.event.espeTotalErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_espeTotalEvents,
{ "Event Running Total", "slow.oam.event.espeTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efeWindow,
{ "Errored Frame Window", "slow.oam.event.efeWindow",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of symbols in the period", HFILL }},
{ &hf_oampdu_event_efeThreshold,
{ "Errored Frame Threshold", "slow.oam.event.efeThreshold",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frames required to generate the Event", HFILL }},
{ &hf_oampdu_event_efeErrors,
{ "Errored Frames", "slow.oam.event.efeErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_efeTotalErrors,
{ "Error Running Total", "slow.oam.event.efeTotalErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of frames in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efeTotalEvents,
{ "Event Running Total", "slow.oam.event.efeTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efpeWindow,
{ "Errored Frame Window", "slow.oam.event.efpeWindow",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frame in error during the period", HFILL }},
{ &hf_oampdu_event_efpeThreshold,
{ "Errored Frame Threshold", "slow.oam.event.efpeThreshold",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frames required to generate the Event", HFILL }},
{ &hf_oampdu_event_efpeErrors,
{ "Errored Frames", "slow.oam.event.efeErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_efpeTotalErrors,
{ "Error Running Total", "slow.oam.event.efpeTotalErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of frames in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efpeTotalEvents,
{ "Event Running Total", "slow.oam.event.efpeTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efsseWindow,
{ "Errored Frame Window", "slow.oam.event.efsseWindow",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of frame in error during the period", HFILL }},
{ &hf_oampdu_event_efsseThreshold,
{ "Errored Frame Threshold", "slow.oam.event.efsseThreshold",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of frames required to generate the Event", HFILL }},
{ &hf_oampdu_event_efsseErrors,
{ "Errored Frames", "slow.oam.event.efeErrors",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_efsseTotalErrors,
{ "Error Running Total", "slow.oam.event.efsseTotalErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frames in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efsseTotalEvents,
{ "Event Running Total", "slow.oam.event.efsseTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_variable_branch,
{ "Branch", "slow.oam.variable.branch",
FT_UINT8, BASE_HEX, VALS(branch_vals), 0x0,
"Variable Branch, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_object,
{ "Leaf", "slow.oam.variable.object",
FT_UINT16, BASE_HEX, VALS(object_vals), 0x0,
"Object, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_package,
{ "Leaf", "slow.oam.variable.package",
FT_UINT16, BASE_HEX, VALS(package_vals), 0x0,
"Package, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_binding,
{ "Leaf", "slow.oam.variable.binding",
FT_UINT16, BASE_HEX, VALS(binding_vals), 0x0,
"Binding, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_attribute,
{ "Leaf", "slow.oam.variable.attribute",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &attribute_vals_ext, 0x0,
"Attribute, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_width,
{ "Variable Width", "slow.oam.variable.width",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Width", HFILL }},
{ &hf_oampdu_variable_indication,
{ "Variable indication", "slow.oam.variable.indication",
FT_UINT8, BASE_HEX, VALS(indication_vals), 0x0,
NULL, HFILL }},
{ &hf_oampdu_variable_value,
{ "Variable Value", "slow.oam.variable.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Value", HFILL }},
{ &hf_oampdu_lpbk,
{ "Commands", "slow.oam.lpbk.commands",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The List of Loopback Commands", HFILL }},
{ &hf_oampdu_lpbk_enable,
{ "Enable Remote Loopback", "slow.oam.lpbk.commands.enable",
FT_BOOLEAN, 8, NULL, OAMPDU_LPBK_ENABLE,
"Enable Remote Loopback Command", HFILL }},
{ &hf_oampdu_lpbk_disable,
{ "Disable Remote Loopback", "slow.oam.lpbk.commands.disable",
FT_BOOLEAN, 8, NULL, OAMPDU_LPBK_DISABLE,
"Disable Remote Loopback Command", HFILL }}
};
static gint *ett[] = {
&ett_pdu,
&ett_lacpdu,
&ett_lacpdu_a_flags,
&ett_lacpdu_p_flags,
&ett_marker,
&ett_esmc,
&ett_oampdu,
&ett_oampdu_flags,
&ett_oampdu_local_info,
&ett_oampdu_local_info_state,
&ett_oampdu_local_info_config,
&ett_oampdu_remote_info,
&ett_oampdu_remote_info_state,
&ett_oampdu_remote_info_config,
&ett_oampdu_org_info,
&ett_oampdu_event_espe,
&ett_oampdu_event_efe,
&ett_oampdu_event_efpe,
&ett_oampdu_event_efsse,
&ett_oampdu_event_ose,
&ett_oampdu_lpbk_ctrl,
&ett_ossppdu,
&ett_itu_ossp
};
static ei_register_info ei[] = {
{ &ei_esmc_version_compliance, { "slow.esmc.version.compliance", PI_MALFORMED, PI_ERROR, "Version must claim compliance with Version 1 of this protocol", EXPFILL }},
{ &ei_esmc_tlv_type_ql_type_not_first, { "slow.esmc.tlv_type.ql_type_not_first", PI_MALFORMED, PI_ERROR, "TLV Type must be QL because QL TLV must be first in the ESMC PDU", EXPFILL }},
{ &ei_esmc_tlv_type_decoded_as_ql_type, { "slow.esmc.tlv_type.decoded_as_ql_type", PI_UNDECODED, PI_NOTE, "Let's decode as if this is QL TLV", EXPFILL }},
{ &ei_esmc_tlv_length_bad, { "slow.esmc.tlv_length.bad", PI_MALFORMED, PI_ERROR, "QL TLV Length must be X", EXPFILL }},
{ &ei_esmc_tlv_ql_unused_not_zero, { "slow.esmc.tlv_ql_unused.not_zero", PI_MALFORMED, PI_WARN, "Unused bits of TLV must be all zeroes", EXPFILL }},
{ &ei_esmc_quality_level_invalid, { "slow.esmc.ql.invalid", PI_UNDECODED, PI_WARN, "Invalid SSM message, unknown QL code", EXPFILL }},
{ &ei_esmc_tlv_type_not_timestamp, { "slow.esmc.tlv_type.not_timestamp", PI_MALFORMED, PI_ERROR, "TLV Type must be == Timestamp because Timestamp Valid Flag is set", EXPFILL }},
{ &ei_esmc_tlv_type_decoded_as_timestamp, { "slow.esmc.tlv_type.decoded_as_timestamp", PI_UNDECODED, PI_NOTE, "Let's decode as if this is Timestamp TLV", EXPFILL }},
{ &ei_esmc_reserved_not_zero, { "slow.reserved_bits_must_be_set_to_all_zero", PI_PROTOCOL, PI_WARN, "Reserved bits must be set to all zero", EXPFILL }},
{ &ei_oampdu_event_length_bad, { "slow.oam.event.length.bad", PI_MALFORMED, PI_ERROR, "Event length should be at least 2", EXPFILL }},
};
expert_module_t* expert_slow;
proto_slow = proto_register_protocol("Slow Protocols", "802.3 Slow protocols", "slow");
proto_register_field_array(proto_slow, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_slow = expert_register_protocol(proto_slow);
expert_register_field_array(expert_slow, ei, array_length(ei));
}
void
proto_reg_handoff_slow_protocols(void)
{
dissector_handle_t slow_protocols_handle;
slow_protocols_handle = create_dissector_handle(dissect_slow_protocols, proto_slow);
dissector_add_uint("ethertype", ETHERTYPE_SLOW_PROTOCOLS, slow_protocols_handle);
dh_data = find_dissector("data");
}
