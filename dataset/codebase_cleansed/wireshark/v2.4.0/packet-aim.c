static const aim_subtype
*aim_get_subtype( guint16 famnum, guint16 subtype )
{
GList *gl = families;
while(gl) {
aim_family *fam = (aim_family *)gl->data;
if(fam->family == famnum) {
int i;
for(i = 0; fam->subtypes[i].name; i++) {
if(fam->subtypes[i].id == subtype) return &(fam->subtypes[i]);
}
}
gl = gl->next;
}
return NULL;
}
static const aim_family
*aim_get_family( guint16 famnum )
{
GList *gl = families;
while(gl) {
aim_family *fam = (aim_family *)gl->data;
if(fam->family == famnum) return fam;
gl = gl->next;
}
return NULL;
}
static int
aim_get_buddyname( guint8 **name, tvbuff_t *tvb, int offset)
{
guint8 buddyname_length;
buddyname_length = tvb_get_guint8(tvb, offset);
*name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, buddyname_length, ENC_UTF_8|ENC_NA);
return buddyname_length;
}
static void
aim_get_message( guchar *msg, tvbuff_t *tvb, int msg_offset, int msg_length)
{
int i,j,c;
int bracket = FALSE;
int max, tagchars = 0;
int new_offset = msg_offset;
int new_length = msg_length;
if( msg_length > 999 ) return;
memset( msg, '\0', 1000);
i = 0;
c = 0;
while( (tagchars < 6) && (new_length > 5) )
{
j = tvb_get_guint8(tvb, new_offset);
if( ( (j == '<') && (tagchars == 0) ) ||
( (j == 'h') && (tagchars == 1) ) ||
( (j == 'H') && (tagchars == 1) ) ||
( (j == 't') && (tagchars == 2) ) ||
( (j == 'T') && (tagchars == 2) ) ||
( (j == 'm') && (tagchars == 3) ) ||
( (j == 'M') && (tagchars == 3) ) ||
( (j == 'l') && (tagchars == 4) ) ||
( (j == 'L') && (tagchars == 4) ) ||
( (j == '>') && (tagchars == 5) ) ) tagchars++;
new_offset++;
new_length--;
}
msg_offset = new_offset;
msg_length = new_length;
max = msg_length - 1;
tagchars = 0;
while( (c < max) && (tagchars < 7) )
{
j = tvb_get_guint8(tvb, msg_offset+c);
if( ( (j == '<') && (tagchars == 0) ) ||
( (j == '/') && (tagchars == 1) ) ||
( (j == 'h') && (tagchars == 2) ) ||
( (j == 'H') && (tagchars == 2) ) ||
( (j == 't') && (tagchars == 3) ) ||
( (j == 'T') && (tagchars == 3) ) ||
( (j == 'm') && (tagchars == 4) ) ||
( (j == 'M') && (tagchars == 4) ) ||
( (j == 'l') && (tagchars == 5) ) ||
( (j == 'L') && (tagchars == 5) ) ||
( (j == '>') && (tagchars == 6) ) ) tagchars++;
#ifdef STRIP_TAGS
if( j == '<' ) bracket = TRUE;
if( j == '>' ) bracket = FALSE;
if( (g_ascii_isprint(j) ) && (bracket == FALSE) && (j != '>'))
#else
if( g_ascii_isprint(j) )
#endif
{
msg[i] = j;
i++;
}
c++;
}
}
static void
aim_init_family(int proto, int ett, guint16 family, const aim_subtype *subtypes)
{
aim_family *fam = g_new(aim_family, 1);
fam->proto = find_protocol_by_id(proto);
fam->name = proto_get_protocol_short_name(fam->proto);
fam->family = family;
fam->subtypes = subtypes;
families = g_list_append(families, fam);
fam->proto_id = proto;
fam->ett = ett;
}
static int
dissect_aim_ssi_result(tvbuff_t *tvb, packet_info *pinfo, proto_tree *aim_tree)
{
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tvb_get_ntohs(tvb, 0), aim_ssi_result_codes, "Unknown SSI result code 0x%02x"));
proto_tree_add_item (aim_tree, hf_aim_ssi_result_code, tvb, 0, 2, ENC_BIG_ENDIAN);
return 2;
}
static void
dissect_aim_snac(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *aim_tree, proto_tree *root_tree)
{
guint16 family_id;
guint16 subtype_id;
guint16 flags;
guint32 id;
proto_tree *aim_tree_fnac = NULL;
tvbuff_t *subtvb;
int orig_offset;
const aim_subtype *subtype;
proto_tree *family_tree = NULL;
const aim_family *family;
orig_offset = offset;
family_id = tvb_get_ntohs(tvb, offset);
family = aim_get_family(family_id);
offset += 2;
subtype_id = tvb_get_ntohs(tvb, offset);
subtype = aim_get_subtype(family_id, subtype_id);
offset += 2;
flags = tvb_get_ntohs(tvb, offset);
offset += 2;
id = tvb_get_ntohl(tvb, offset);
offset += 4;
if( aim_tree && subtype != NULL )
{
static const int * fnac_flags[] = {
&hf_aim_fnac_flag_next_is_related,
&hf_aim_fnac_flag_contains_version,
NULL
};
offset = orig_offset;
aim_tree_fnac = proto_tree_add_subtree_format(aim_tree, tvb, 6, 10, ett_aim_fnac, NULL,
"FNAC: Family: %s (0x%04x), Subtype: %s (0x%04x)",
family ? family->name : "Unknown", family_id,
(subtype && subtype->name) ? subtype->name : "Unknown", subtype_id);
proto_tree_add_uint_format_value (aim_tree_fnac, hf_aim_fnac_family,
tvb, offset, 2, family_id, "%s (0x%04x)",
family ? family->name : "Unknown", family_id);
offset += 2;
proto_tree_add_uint_format_value (aim_tree_fnac, hf_aim_fnac_subtype,
tvb, offset, 2, subtype_id, "%s (0x%04x)",
(subtype && subtype->name) ? subtype->name : "Unknown", subtype_id);
offset += 2;
proto_tree_add_bitmask(aim_tree_fnac, tvb, offset, hf_aim_fnac_flags,
ett_aim_fnac_flags, fnac_flags, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(aim_tree_fnac, hf_aim_fnac_id, tvb, offset,
4, id);
offset += 4;
}
if(flags & FNAC_FLAG_CONTAINS_VERSION)
{
guint16 len = tvb_get_ntohs(tvb, offset);
int oldoffset;
offset+=2;
oldoffset = offset;
while(offset < oldoffset + len) {
offset = dissect_aim_tlv(tvb, pinfo, offset, aim_tree, aim_fnac_tlvs);
}
}
subtvb = tvb_new_subset_remaining(tvb, offset);
if (family)
col_set_str(pinfo->cinfo, COL_PROTOCOL, family->name);
if(subtype != NULL && family != NULL)
{
col_set_str(pinfo->cinfo, COL_INFO, family->name);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", subtype->name);
} else {
col_set_str(pinfo->cinfo, COL_INFO, "SNAC data");
if(family)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", family->name);
else
col_append_fstr(pinfo->cinfo, COL_INFO, ", Family: 0x%04x", family_id);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Subtype: 0x%04x", subtype_id);
}
if(aim_tree && family != NULL)
{
proto_item *ti = proto_tree_add_item(root_tree, family->proto_id, subtvb, 0, -1, ENC_NA);
family_tree = proto_item_add_subtree(ti, family->ett);
if(subtype)
proto_item_append_text(ti, ", %s", subtype->name);
}
if((tvb_reported_length_remaining(tvb, offset) > 0) && (subtype != NULL) && subtype->dissector)
{
subtype->dissector(subtvb, pinfo, family_tree);
}
}
static void
dissect_aim_flap_err(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "FLAP error");
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_aim_data, tvb, offset, -1, ENC_NA);
}
static void
dissect_aim_keep_alive(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Keep Alive");
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_aim_data, tvb, offset, -1, ENC_NA);
}
static void
dissect_aim_unknown_channel(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Unknown Channel");
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_aim_data, tvb, offset, -1, ENC_NA);
}
static int
dissect_aim_buddyname(tvbuff_t *tvb, packet_info *pinfo _U_, int offset,
proto_tree *tree)
{
guint8 buddyname_length = 0;
proto_tree *buddy_tree;
buddyname_length = tvb_get_guint8(tvb, offset);
offset++;
if(tree)
{
buddy_tree = proto_tree_add_subtree_format(tree, tvb, offset-1, 1+buddyname_length,
ett_aim_buddyname, NULL, "Buddy: %s",
tvb_format_text(tvb, offset, buddyname_length));
proto_tree_add_item(buddy_tree, hf_aim_buddyname_len, tvb, offset-1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(buddy_tree, hf_aim_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
}
return offset+buddyname_length;
}
static const aim_client_capability *
aim_find_capability (e_guid_t clsid)
{
int i;
for(i = 0; known_client_caps[i].name; i++)
{
const aim_client_capability *caps = &(known_client_caps[i]);
if(memcmp(&(caps->clsid), &clsid, sizeof(e_guid_t)) == 0)
return caps;
}
return NULL;
}
static const aim_client_capability *
aim_find_short_capability(guint16 shortid)
{
e_guid_t clsid = {0x09460000, 0x4c7f, 0x11d1, {0x82, 0x22, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00}};
clsid.data1 |= shortid;
return aim_find_capability(clsid);
}
static int
dissect_aim_capability(proto_tree *entry, tvbuff_t *tvb, int offset)
{
const aim_client_capability *caps;
e_guid_t clsid;
tvb_get_ntohguid(tvb, offset, &clsid);
caps = aim_find_capability(clsid);
proto_tree_add_guid_format(entry, hf_aim_nickinfo_caps, tvb, offset, 16,
&clsid,
"%s {%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
caps?caps->name:"Unknown", clsid.data1, clsid.data2,
clsid.data3, clsid.data4[0], clsid.data4[1], clsid.data4[2],
clsid.data4[3], clsid.data4[4], clsid.data4[5], clsid.data4[6],
clsid.data4[7]
);
return offset+16;
}
static int
dissect_aim_short_capability(proto_tree *entry, tvbuff_t *tvb, int offset)
{
const aim_client_capability *caps;
guint16 shortid;
shortid = tvb_get_ntohs(tvb, offset);
caps = aim_find_short_capability(shortid);
proto_tree_add_uint_format(entry, hf_aim_nickinfo_short_caps, tvb, offset, 2,
shortid,
"%s (0x%04x)",
caps?caps->name:"Unknown", shortid
);
return offset+2;
}
static int
dissect_aim_tlv_value_client_capabilities(proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
proto_tree *entry;
proto_item_set_text(ti, "Client Capabilities List");
entry = proto_item_add_subtree(ti, ett_aim_nickinfo_caps);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_capability(entry, tvb, offset);
}
return tvb_reported_length(tvb);
}
static int
dissect_aim_tlv_value_client_short_capabilities(proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
proto_tree *entry;
proto_item_set_text(ti, "Short Client Capabilities List");
entry = proto_item_add_subtree(ti, ett_aim_nickinfo_short_caps);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_short_capability(entry, tvb, offset);
}
return tvb_reported_length(tvb);
}
static int
dissect_aim_tlv_value_time(proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
return tvb_reported_length(tvb);
}
static int
dissect_aim_userclass(tvbuff_t *tvb, int offset, int len, proto_item *ti, guint32 value)
{
proto_tree *entry;
static const int * flags[] = {
&hf_aim_userclass_unconfirmed,
&hf_aim_userclass_administrator,
&hf_aim_userclass_aol,
&hf_aim_userclass_commercial,
&hf_aim_userclass_aim,
&hf_aim_userclass_away,
&hf_aim_userclass_icq,
&hf_aim_userclass_wireless,
&hf_aim_userclass_unknown100,
&hf_aim_userclass_imf,
&hf_aim_userclass_bot,
&hf_aim_userclass_unknown800,
&hf_aim_userclass_one_way_wireless,
&hf_aim_userclass_unknown2000,
&hf_aim_userclass_unknown4000,
&hf_aim_userclass_unknown8000,
&hf_aim_userclass_unknown10000,
&hf_aim_userclass_unknown20000,
&hf_aim_userclass_no_knock_knock,
&hf_aim_userclass_forward_mobile,
NULL
};
entry = proto_item_add_subtree(ti, ett_aim_userclass);
proto_tree_add_bitmask_list_value(entry, tvb, offset, len, flags, value);
return offset+len;
}
static int
dissect_aim_tlv_value_userclass(proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint16 value16 = tvb_get_ntohs(tvb, 0);
proto_item_set_text(ti, "Value: 0x%04x", value16);
return dissect_aim_userclass(tvb, 0, 2, ti, value16);
}
static int
dissect_aim_tlv_value_userstatus(proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
return tvb_reported_length(tvb);
}
static int
dissect_aim_tlv_value_dcinfo(proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
proto_tree *dctree = proto_item_add_subtree(ti, ett_aim_dcinfo);
proto_tree_add_item(dctree, hf_aim_dcinfo_ip , tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_tcpport, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset+=1;
proto_tree_add_item(dctree, hf_aim_dcinfo_proto_version, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(dctree, hf_aim_dcinfo_auth_cookie, tvb, offset, 4, ENC_NA); offset+=2;
proto_tree_add_item(dctree, hf_aim_dcinfo_webport, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_client_future, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_last_info_update, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_last_ext_info_update, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_last_ext_status_update, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(dctree, hf_aim_dcinfo_unknown, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return offset;
}
static int
dissect_aim_tlv_value_string (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint8 *buf;
gint string_len;
string_len = tvb_reported_length(tvb);
buf = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, string_len, ENC_UTF_8|ENC_NA);
proto_item_set_text(ti, "Value: %s", format_text(wmem_packet_scope(), buf, string_len));
return string_len;
}
static int
dissect_aim_tlv_value_string08_array (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
proto_tree *entry;
gint offset=0;
entry = proto_item_add_subtree(ti, ett_aim_string08_array);
while (tvb_reported_length_remaining(tvb, offset) > 1)
{
guint8 string_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(entry, hf_aim_string08, tvb, offset, 1, ENC_UTF_8|ENC_NA);
offset += (string_len+1);
}
return offset;
}
static int
dissect_aim_tlv_value_bytes (proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
return tvb_reported_length(tvb);
}
static int
dissect_aim_tlv_value_uint8 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint8 value8 = tvb_get_guint8(tvb, 0);
proto_item_set_text(ti, "Value: %d", value8);
return 1;
}
static int
dissect_aim_tlv_value_uint16 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint16 value16 = tvb_get_ntohs(tvb, 0);
proto_item_set_text(ti, "Value: %d", value16);
return 2;
}
static int
dissect_aim_tlv_value_ipv4 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
proto_item_set_text(ti, "Value: %s", tvb_ip_to_str(tvb, 0));
return 4;
}
static int
dissect_aim_tlv_value_uint32 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint32 value32 = tvb_get_ntohl(tvb, 0);
proto_item_set_text(ti, "Value: %d", value32);
return 4;
}
static int
dissect_aim_tlv_value_messageblock (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo)
{
proto_tree *entry;
guint8 *buf;
guint16 featurelen;
guint32 blocklen;
proto_item* len_item;
int offset=0;
entry = proto_item_add_subtree(ti, ett_aim_messageblock);
proto_tree_add_item(entry, hf_aim_messageblock_featuresdes, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
featurelen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(entry, hf_aim_messageblock_featureslen, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(entry, hf_aim_messageblock_features, tvb, offset,
featurelen, ENC_NA);
offset += featurelen;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(entry, hf_aim_messageblock_info, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len_item = proto_tree_add_item_ret_uint(entry, hf_aim_messageblock_len, tvb, offset,
2, ENC_BIG_ENDIAN, &blocklen);
if (blocklen <= 4)
{
expert_add_info(pinfo, len_item, &ei_aim_messageblock_len);
break;
}
offset += 2;
proto_tree_add_item(entry, hf_aim_messageblock_charset, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(entry, hf_aim_messageblock_charsubset, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
buf = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, blocklen - 4, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, "Message: %s ",
format_text(wmem_packet_scope(), buf, blocklen - 4));
proto_tree_add_item(entry, hf_aim_messageblock_message, tvb,
offset, blocklen-4, ENC_ASCII|ENC_NA);
offset += blocklen-4;
}
return offset;
}
static int
dissect_aim_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, const aim_tlv *tlv)
{
guint16 valueid;
guint16 length;
int i = 0;
const aim_tlv *tmp;
const char *desc;
proto_item *ti1;
proto_tree *tlv_tree;
valueid = tvb_get_ntohs(tvb, offset);
tmp = tlv;
while (tmp[i].valueid) {
if (tmp[i].valueid == valueid) {
break;
}
i++;
}
length = tvb_get_ntohs(tvb, offset+2);
if (tmp[i].desc != NULL)
desc = tmp[i].desc;
else
desc = "Unknown";
tlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, length + 4,
ett_aim_tlv, NULL, "TLV: %s", desc);
proto_tree_add_uint_format_value(tlv_tree, hf_aim_tlv_value_id, tvb, offset, 2,
valueid, "%s (0x%04x)", desc, valueid);
offset += 2;
proto_tree_add_uint(tlv_tree, hf_aim_tlv_length, tvb, offset, 2, length);
offset += 2;
proto_tree_add_subtree(tlv_tree, tvb, offset, length, ett_aim_tlv_value, &ti1, "Value");
if (tmp[i].dissector) {
tmp[i].dissector(ti1, valueid, tvb_new_subset_length(tvb, offset, length), pinfo);
}
offset += length;
return offset;
}
static int
dissect_aim_tlv_sequence(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, const aim_tlv *tlv_table)
{
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, tlv_table);
}
return offset;
}
static int
dissect_aim_tlv_list(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, const aim_tlv *tlv_table)
{
guint16 i, tlv_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_tlvcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(i = 0; i < tlv_count; i++) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, tlv_table);
}
return offset;
}
static void
dissect_aim_close_conn(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Close Connection");
dissect_aim_tlv_sequence(tvb, pinfo, offset, tree, aim_client_tlvs);
}
static void
dissect_aim_newconn(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "New Connection");
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_aim_version, tvb, offset, 4, ENC_NA);
offset+=4;
offset = dissect_aim_tlv_sequence(tvb, pinfo, offset, tree, aim_client_tlvs);
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_aim_data, tvb, offset, -1, ENC_NA);
}
static int
dissect_aim_snac_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *aim_tree)
{
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tvb_get_ntohs(tvb, 0), aim_snac_errors, "Unknown SNAC error 0x%02x"));
proto_tree_add_item (aim_tree, hf_aim_snac_error, tvb, 0, 2, ENC_BIG_ENDIAN);
return dissect_aim_tlv_sequence(tvb, pinfo, 2, aim_tree, aim_client_tlvs);
}
static guint
get_aim_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset + 4);
return plen + 6;
}
static int
dissect_aim_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
unsigned char hdr_channel;
unsigned short hdr_sequence_no;
unsigned short hdr_data_field_length;
int offset=0;
proto_item *ti;
proto_tree *aim_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AIM");
col_set_str(pinfo->cinfo, COL_INFO, "AOL Instant Messenger");
offset += 1;
hdr_channel = tvb_get_guint8(tvb, offset);
offset += 1;
hdr_sequence_no = tvb_get_ntohs(tvb, offset);
offset += 2;
hdr_data_field_length = tvb_get_ntohs(tvb, offset);
offset += 2;
if (tree) {
ti = proto_tree_add_item(tree, proto_aim, tvb, 0, -1, ENC_NA);
aim_tree = proto_item_add_subtree(ti, ett_aim);
proto_tree_add_uint(aim_tree, hf_aim_cmd_start, tvb, 0, 1, '*');
proto_tree_add_item(aim_tree, hf_aim_channel, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(aim_tree, hf_aim_seqno, tvb, 2, 2, hdr_sequence_no);
proto_tree_add_uint(aim_tree, hf_aim_data_len, tvb, 4, 2, hdr_data_field_length);
}
switch(hdr_channel)
{
case CHANNEL_NEW_CONN:
dissect_aim_newconn(tvb, pinfo, offset, aim_tree);
break;
case CHANNEL_SNAC_DATA:
dissect_aim_snac(tvb, pinfo, offset, aim_tree, tree);
break;
case CHANNEL_FLAP_ERR:
dissect_aim_flap_err(tvb, pinfo, offset, aim_tree);
break;
case CHANNEL_CLOSE_CONN:
dissect_aim_close_conn(tvb, pinfo, offset, aim_tree);
break;
case CHANNEL_KEEP_ALIVE:
dissect_aim_keep_alive(tvb, pinfo, offset, aim_tree);
break;
default:
dissect_aim_unknown_channel(tvb, pinfo, offset, aim_tree);
break;
}
return tvb_reported_length(tvb);
}
static int
dissect_aim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if(tvb_reported_length(tvb) >= 1 && tvb_get_guint8(tvb, 0) != 0x2a)
{
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, aim_desegment, 6, get_aim_pdu_len,
dissect_aim_pdu, data);
return tvb_reported_length(tvb);
}
static int
dissect_aim_ssl_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
dissector_handle_t *app_handle = (dissector_handle_t *) data;
if (tvb_reported_length(tvb) < 1 || tvb_get_guint8(tvb, 0) != 0x2a) {
return FALSE;
}
dissect_aim(tvb, pinfo, tree, NULL);
*app_handle = aim_handle;
return TRUE;
}
static int dissect_aim_admin_accnt_info_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *admin_tree)
{
proto_tree_add_item(admin_tree, hf_admin_acctinfo_code, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(admin_tree, hf_admin_acctinfo_unknown, tvb, 2, 2, ENC_BIG_ENDIAN);
return 4;
}
static int dissect_aim_admin_accnt_info_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *admin_tree)
{
int offset = 0;
proto_tree_add_item(admin_tree, hf_admin_acctinfo_permissions, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
return dissect_aim_tlv_list(tvb, pinfo, offset, admin_tree, aim_client_tlvs);
}
static int dissect_aim_admin_info_change_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *admin_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, admin_tree, aim_client_tlvs);
}
static int dissect_aim_admin_cfrm_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *admin_tree)
{
int offset = 0;
proto_tree_add_item(admin_tree, hf_admin_confirm_status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
return dissect_aim_tlv_sequence(tvb, pinfo, offset, admin_tree, aim_client_tlvs);
}
static int dissect_aim_bos_set_group_perm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bos_tree)
{
int offset = 0;
guint32 userclass = tvb_get_ntohl(tvb, offset);
proto_item *ti = proto_tree_add_uint(bos_tree, hf_aim_bos_class, tvb, offset, 4, userclass);
return dissect_aim_userclass(tvb, offset, 4, ti, userclass);
}
static int dissect_aim_bos_rights(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bos_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, bos_tree, aim_privacy_tlvs);
}
static int dissect_aim_bos_buddyname(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bos_tree)
{
int offset = 0;
while(tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_buddyname(tvb, pinfo, offset, bos_tree);
}
return offset;
}
static int
dissect_aim_userinfo(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_aim_buddyname(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_aim_userinfo_warninglevel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return dissect_aim_tlv_list(tvb, pinfo, offset, tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_buddylist_buddylist(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_buddyname( tvb, pinfo, offset, buddy_tree);
}
return offset;
}
static int dissect_aim_buddylist_rights_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, buddy_tree, aim_buddylist_tlvs);
}
static int dissect_aim_buddylist_reject(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
return dissect_aim_buddyname(tvb, pinfo, 0, buddy_tree);
}
static int dissect_aim_buddylist_oncoming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
guint8 *buddyname;
int offset = 0;
int buddyname_length = aim_get_buddyname( &buddyname, tvb, offset );
col_set_str(pinfo->cinfo, COL_INFO, "Oncoming Buddy");
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
format_text(wmem_packet_scope(), buddyname, buddyname_length));
offset += dissect_aim_buddyname(tvb, pinfo, offset, buddy_tree);
proto_tree_add_item(buddy_tree, hf_aim_buddylist_userinfo_warninglevel, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_aim_tlv_list(tvb, pinfo, offset, buddy_tree, aim_onlinebuddy_tlvs);
return offset;
}
static int dissect_aim_buddylist_offgoing(tvbuff_t *tvb, packet_info *pinfo, proto_tree *buddy_tree)
{
guint8 *buddyname;
int offset = 0;
int buddyname_length = aim_get_buddyname( &buddyname, tvb, offset );
col_set_str(pinfo->cinfo, COL_INFO, "Offgoing Buddy");
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
format_text(wmem_packet_scope(), buddyname, buddyname_length));
offset += dissect_aim_buddyname(tvb, pinfo, offset, buddy_tree);
proto_tree_add_item(buddy_tree, hf_aim_buddylist_userinfo_warninglevel, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
return dissect_aim_tlv_list(tvb, pinfo, offset, buddy_tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_chat_userinfo_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *chat_tree)
{
int offset = 0;
while(tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_userinfo(tvb, pinfo, offset, chat_tree);
}
return offset;
}
static int dissect_aim_chat_outgoing_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *chat_tree _U_)
{
guint8 *buddyname;
guchar *msg;
int buddyname_length;
msg=(guchar *)wmem_alloc(wmem_packet_scope(), 1000);
buddyname_length = aim_get_buddyname( &buddyname, tvb, 30 );
aim_get_message( msg, tvb, 40 + buddyname_length, tvb_reported_length(tvb)
- 40 - buddyname_length );
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s", msg);
return tvb_reported_length(tvb);
}
static int dissect_aim_chat_incoming_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *chat_tree)
{
guint8 *buddyname;
guchar *msg;
int buddyname_length;
msg=(guchar *)wmem_alloc(wmem_packet_scope(), 1000);
buddyname_length = aim_get_buddyname( &buddyname, tvb, 30 );
aim_get_message( msg, tvb, 36 + buddyname_length, tvb_reported_length(tvb)
- 36 - buddyname_length );
col_append_fstr(pinfo->cinfo, COL_INFO, "from: %s", buddyname);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s", msg);
proto_tree_add_string(chat_tree, hf_aim_chat_screen_name, tvb, 31, buddyname_length, buddyname);
return tvb_reported_length(tvb);
}
static int dissect_aim_directory_user_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, aim_client_tlvs);
}
return offset;
}
static int dissect_rate_class(tvbuff_t *tvb, packet_info *pinfo _U_, int offset, proto_tree *class_tree)
{
proto_tree_add_item(class_tree, hf_generic_rateinfo_classid, tvb, offset, 2, ENC_BIG_ENDIAN);offset+=2;
proto_tree_add_item(class_tree, hf_generic_rateinfo_windowsize, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_clearlevel, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_alertlevel, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_limitlevel, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_disconnectlevel, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_currentlevel, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_maxlevel, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_lasttime, tvb, offset, 4, ENC_BIG_ENDIAN);offset+=4;
proto_tree_add_item(class_tree, hf_generic_rateinfo_curstate, tvb, offset, 1, ENC_BIG_ENDIAN);offset+=1;
return offset;
}
static int dissect_generic_rateinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint16 i;
guint16 numclasses = tvb_get_ntohs(tvb, 0);
proto_tree *classes_tree = NULL, *groups_tree, *group_tree;
proto_tree_add_uint(tree, hf_generic_rateinfo_numclasses, tvb, 0, 2, numclasses );
offset+=2;
if(tree) {
classes_tree = proto_tree_add_subtree(tree, tvb, offset, 35 * numclasses,
ett_generic_rateinfo_classes, NULL, "Available Rate Classes");
}
for(i = 0; i < numclasses; i++) {
guint16 myid = tvb_get_ntohs(tvb, offset);
proto_tree *class_tree = proto_tree_add_subtree_format(classes_tree, tvb, offset, 35,
ett_generic_rateinfo_class, NULL, "Rate Class 0x%02x", myid);
offset = dissect_rate_class(tvb, pinfo, offset, class_tree);
}
groups_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_generic_rateinfo_groups, NULL, "Rate Groups");
for(i = 0; i < numclasses; i++) {
guint16 j;
guint16 myid = tvb_get_ntohs(tvb, offset);
guint16 numpairs = tvb_get_ntohs(tvb, offset + 2);
group_tree = proto_tree_add_subtree_format(groups_tree, tvb, offset, 4 + 4 * numpairs,
ett_generic_rateinfo_group, NULL, "Rate Group 0x%02x", myid);
proto_tree_add_uint(group_tree, hf_generic_rateinfo_classid, tvb, offset, 2, myid);offset+=2;
proto_tree_add_uint(group_tree, hf_generic_rateinfo_numpairs, tvb, offset, 2, numpairs); offset+=2;
for(j = 0; j < numpairs; j++) {
guint16 family_id;
guint16 subtype_id;
const aim_family *family;
const aim_subtype *subtype;
family_id = tvb_get_ntohs(tvb, offset);
subtype_id = tvb_get_ntohs(tvb, offset+2);
family = aim_get_family(family_id);
subtype = aim_get_subtype(family_id, subtype_id);
proto_tree_add_uint_format_value(group_tree, hf_generic_family, tvb, offset, 4, family_id,
"%s (0x%04x), Subtype: %s (0x%04x)", family?family->name:"Unknown", family_id, subtype?subtype->name:"Unknown", subtype_id);
offset+=4;
}
}
return offset;
}
static int dissect_aim_generic_clientready(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_tree *entry = proto_tree_add_subtree(gen_tree, tvb, 0, -1, ett_generic_clientready, NULL, "Supported services");
while(tvb_reported_length_remaining(tvb, offset) > 0) {
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(entry, hf_generic_family, tvb, offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(ti, ett_generic_clientready_item);
offset+=2;
proto_tree_add_item(subtree, hf_generic_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_generic_dll_version, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_len(ti, 8);
}
return offset;
}
static int dissect_aim_generic_serverready(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_tree *entry = proto_tree_add_subtree(gen_tree, tvb, offset, -1, ett_generic_clientready, NULL, "Supported services");
while(tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(entry, hf_generic_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
return offset;
}
static int dissect_aim_generic_service_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
const aim_family *family = aim_get_family( tvb_get_ntohs(tvb, offset) );
proto_tree_add_uint_format(gen_tree, hf_generic_servicereq_service, tvb, offset, 2, tvb_get_ntohs(tvb, offset), "%s (0x%04x)", family?family->name:"Unknown", tvb_get_ntohs(tvb, offset) );
offset+=2;
return offset;
}
static int dissect_aim_generic_redirect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, gen_tree, aim_client_tlvs);
}
static int dissect_aim_generic_capabilities(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_tree *entry = proto_tree_add_subtree(gen_tree, tvb, offset, -1, ett_generic_clientready, NULL, "Requested services");
while(tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(entry, hf_generic_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(entry, hf_generic_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
return offset;
}
static int dissect_aim_generic_capack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_tree *entry = proto_tree_add_subtree(gen_tree, tvb, offset, -1, ett_generic_clientready, NULL, "Accepted requested services");
while(tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(entry, hf_generic_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(entry, hf_generic_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
return offset;
}
static int dissect_aim_generic_motd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_motd_motdtype, tvb, offset,
2, tvb_get_ntohs(tvb, offset));
offset+=2;
return dissect_aim_tlv_sequence(tvb, pinfo, offset, gen_tree, aim_motd_tlvs);
}
static int dissect_aim_generic_rateinfoack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
while(tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(gen_tree, hf_generic_rateinfoack_group, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
return offset;
}
static int dissect_aim_generic_ratechange(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_ratechange_msg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_rate_class(tvb, pinfo, offset, gen_tree);
return offset;
}
static int dissect_aim_generic_clientpauseack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
while(tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(gen_tree, hf_generic_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return offset;
}
static int dissect_aim_generic_migration_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
guint32 n, i;
proto_tree *entry;
n = tvb_get_ntohs(tvb, offset);offset+=2;
proto_tree_add_uint(gen_tree, hf_generic_migration_numfams, tvb, offset, 2, n);
entry = proto_tree_add_subtree(gen_tree, tvb, offset, 2 * n,
ett_generic_migratefamilies, NULL, "Families to migrate");
for(i = 0; i < n; i++) {
proto_tree_add_item(entry, hf_generic_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return dissect_aim_tlv_sequence(tvb, pinfo, offset, gen_tree, aim_client_tlvs);
}
static int dissect_aim_generic_setprivflags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
static const int * flags[] = {
&hf_generic_allow_idle_see,
&hf_generic_allow_member_see,
NULL
};
proto_tree_add_bitmask(gen_tree, tvb, 0, hf_generic_priv_flags, ett_generic_priv_flags, flags, ENC_BIG_ENDIAN);
return 4;
}
static int dissect_aim_generic_selfinfo_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = dissect_aim_buddyname(tvb, pinfo, 0, gen_tree);
proto_tree_add_item(gen_tree, hf_generic_selfinfo_warninglevel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return dissect_aim_tlv_list(tvb, pinfo, offset, gen_tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_generic_evil(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_evil_new_warn_level, tvb, offset, 2, ENC_BIG_ENDIAN);
while(tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_userinfo(tvb, pinfo, offset, gen_tree);
}
return offset;
}
static int dissect_aim_generic_setidle(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
proto_tree_add_item(gen_tree, hf_generic_idle_time, tvb, 0, 2, ENC_BIG_ENDIAN);
return 2;
}
static int dissect_aim_generic_ext_status_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, gen_tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_generic_clientver_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_client_ver_req_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(gen_tree, hf_generic_client_ver_req_length, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset+4;
}
static int dissect_aim_generic_clientver_repl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
proto_tree_add_item(gen_tree, hf_generic_client_ver_req_hash, tvb, 0, 16, ENC_NA);
return 16;
}
static int dissect_aim_generic_ext_status_repl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
guint8 length;
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_ext_status_type, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(gen_tree, hf_generic_ext_status_flags, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(gen_tree, hf_generic_ext_status_length, tvb, offset, 1, ENC_BIG_ENDIAN); length = tvb_get_guint8(tvb, offset); offset += 1;
proto_tree_add_item(gen_tree, hf_generic_ext_status_data, tvb, offset, length, ENC_NA); offset += 1;
return offset;
}
static void
aim_generic_family( gchar *result, guint32 famnum )
{
const aim_family *family = aim_get_family(famnum);
g_snprintf( result, ITEM_LABEL_LENGTH, "%s (0x%x)", family?family->name:"Unknown", famnum);
}
static int dissect_aim_tlv_value_icq(proto_item *ti, guint16 subtype _U_, tvbuff_t *tvb, packet_info *pinfo)
{
int offset = 0;
int i;
proto_item *subtype_item;
guint16 req_type, req_subtype;
proto_tree *t = proto_item_add_subtree(ti, ett_aim_icq_tlv);
proto_tree_add_item(t, hf_icq_tlv_data_chunk_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(t, hf_icq_tlv_request_owner_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(t, hf_icq_tlv_request_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
req_type = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(t, hf_icq_tlv_request_seq_num, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
switch (req_type) {
case ICQ_CLI_OFFLINE_MESSAGE_REQ: return offset;
case ICQ_CLI_DELETE_OFFLINE_MSGS: return offset;
case ICQ_SRV_OFFLINE_MSGS:
break;
case ICQ_SRV_END_OF_OFFLINE_MSGS:
proto_tree_add_item(t, hf_icq_dropped_msg_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return offset+1;
case ICQ_CLI_META_INFO_REQ:
case ICQ_SRV_META_INFO_REPL:
req_subtype = tvb_get_letohs(tvb, offset);
subtype_item = proto_tree_add_item(t, hf_icq_meta_subtype, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset+=2;
for (i = 0; icq_calls[i].name; i++) {
if (icq_calls[i].subtype == req_subtype) break;
}
col_set_str(pinfo->cinfo, COL_INFO, icq_calls[i].name?icq_calls[i].name:"Unknown ICQ Meta Call");
proto_item_append_text(subtype_item, " (%s)", icq_calls[i].name?icq_calls[i].name:"Unknown");
if (icq_calls[i].dissector)
return icq_calls[i].dissector(tvb_new_subset_remaining(tvb, offset), pinfo, t);
default:
break;
}
return offset;
}
static int dissect_aim_icq_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return dissect_aim_tlv(tvb, pinfo, 0, tree, icq_tlv);
}
static int dissect_aim_invitation_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *invite_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, invite_tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_location_rightsinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, loc_tree, aim_location_rights_tlvs);
}
static int dissect_aim_location_setuserinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, loc_tree, aim_locate_tags_tlvs);
}
static int dissect_aim_location_watcher_notification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_buddyname(tvb, pinfo, offset, loc_tree);
}
return offset;
}
static int dissect_aim_location_user_info_query(tvbuff_t *tvb, packet_info *pinfo, proto_tree *loc_tree)
{
return dissect_aim_buddyname(tvb, pinfo, 4, loc_tree);
}
static int dissect_aim_snac_location_request_user_information(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 buddyname_length = 0;
proto_tree_add_item(tree, hf_aim_snac_location_request_user_info_infotype,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_location_buddyname_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_aim_location_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
return offset;
}
static int dissect_aim_snac_location_user_information(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 buddyname_length = 0;
buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_location_buddyname_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_aim_location_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
proto_tree_add_item(tree, hf_aim_location_userinfo_warninglevel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_aim_tlv_list(tvb, pinfo, offset, tree, aim_onlinebuddy_tlvs);
return dissect_aim_tlv_sequence(tvb, pinfo, offset, tree, aim_locate_tags_tlvs);
}
static int
dissect_aim_tlv_value_rendezvous(proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo)
{
int offset = 0;
proto_tree *entry = proto_item_add_subtree(ti, ett_aim_rendezvous_data);
proto_tree_add_item(entry, hf_aim_rendezvous_msg_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(entry, hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA);
offset += 8;
offset = dissect_aim_capability(entry, tvb, offset);
return dissect_aim_tlv_sequence(tvb, pinfo, offset, entry,
aim_rendezvous_tlvs);
}
static int
dissect_aim_msg_outgoing(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
const aim_tlv *aim_ch_tlvs = NULL;
guint16 channel_id;
guint8 *buddyname;
int buddyname_length;
proto_tree_add_item(msg_tree, hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA);
offset += 8;
channel_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(msg_tree, hf_aim_message_channel_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
buddyname_length = aim_get_buddyname(&buddyname, tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " to: %s",
format_text(wmem_packet_scope(), buddyname, buddyname_length));
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
switch(channel_id) {
case ICBM_CHANNEL_IM: aim_ch_tlvs = aim_messaging_incoming_ch1_tlvs; break;
case ICBM_CHANNEL_RENDEZVOUS: aim_ch_tlvs = aim_messaging_incoming_ch2_tlvs; break;
default: return offset;
}
return dissect_aim_tlv_sequence(tvb, pinfo, offset, msg_tree, aim_ch_tlvs);
}
static int
dissect_aim_msg_incoming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
const aim_tlv *aim_ch_tlvs;
guint16 channel_id;
proto_tree_add_item(msg_tree, hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(msg_tree, hf_aim_message_channel_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
channel_id = tvb_get_ntohs(tvb, offset);
offset += 2;
offset = dissect_aim_userinfo(tvb, pinfo, offset, msg_tree);
switch(channel_id) {
case ICBM_CHANNEL_IM: aim_ch_tlvs = aim_messaging_incoming_ch1_tlvs; break;
case ICBM_CHANNEL_RENDEZVOUS: aim_ch_tlvs = aim_messaging_incoming_ch2_tlvs; break;
default: return offset;
}
return dissect_aim_tlv_sequence(tvb, pinfo, offset, msg_tree, aim_ch_tlvs);
}
static int
dissect_aim_msg_params(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree, hf_aim_icbm_channel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_msg_flags, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(msg_tree, hf_aim_icbm_max_snac_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_max_sender_warnlevel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_max_receiver_warnlevel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_min_msg_interval, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
return offset;
}
static int
dissect_aim_msg_evil_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree, hf_aim_icbm_evil, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
}
static int
dissect_aim_msg_evil_repl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree, hf_aim_evil_warn_level, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_evil_new_warn_level, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return offset;
}
static int
dissect_aim_msg_minityping(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree,hf_aim_icbm_notification_cookie, tvb, offset, 8, ENC_NA); offset+=8;
proto_tree_add_item(msg_tree,hf_aim_icbm_notification_channel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
proto_tree_add_item(msg_tree,hf_aim_icbm_notification_type, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return offset;
}
static const
aim_client_plugin *aim_find_plugin ( e_guid_t uuid)
{
int i;
for(i = 0; known_client_plugins[i].name; i++)
{
const aim_client_plugin *plugin = &(known_client_plugins[i]);
if(memcmp(&(plugin->uuid), &uuid, sizeof(e_guid_t)) == 0)
return plugin;
}
return NULL;
}
static int
dissect_aim_plugin(proto_tree *entry, tvbuff_t *tvb, int offset, e_guid_t* out_plugin_uuid)
{
const aim_client_plugin *plugin = NULL;
e_guid_t uuid;
proto_item* ti;
uuid.data1 = tvb_get_ntohl(tvb, offset);
uuid.data2 = tvb_get_ntohs(tvb, offset+4);
uuid.data3 = tvb_get_ntohs(tvb, offset+6);
tvb_memcpy(tvb, uuid.data4, offset+8, 8);
if (out_plugin_uuid)
*out_plugin_uuid = uuid;
plugin = aim_find_plugin(uuid);
ti = proto_tree_add_item(entry, hf_aim_messaging_plugin, tvb, offset, 16, ENC_NA);
proto_item_append_text(ti, " (%s)", plugin ? plugin->name:"Unknown");
return offset+16;
}
static int
dissect_aim_rendezvous_extended_message(tvbuff_t *tvb, proto_tree *msg_tree)
{
int offset = 0;
guint32 text_length;
static const int * flags[] = {
&hf_aim_rendezvous_extended_data_message_flags_normal,
&hf_aim_rendezvous_extended_data_message_flags_auto,
&hf_aim_rendezvous_extended_data_message_flags_multi,
NULL
};
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset+=1;
proto_tree_add_bitmask(msg_tree, tvb, offset, hf_aim_rendezvous_extended_data_message_flags,
ett_aim_extended_data_message_flags, flags, ENC_NA);
offset+=1;
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_status_code, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_priority_code, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
text_length = tvb_get_letohs(tvb, offset);
proto_tree_add_item_ret_uint(msg_tree, hf_aim_rendezvous_extended_data_message_text_length, tvb, offset, 2, ENC_BIG_ENDIAN, &text_length); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_text, tvb, offset, text_length, ENC_ASCII|ENC_NA);
offset = tvb_reported_length(tvb);
return offset;
}
static int
is_uuid_null(e_guid_t uuid)
{
return (uuid.data1 == 0) &&
(uuid.data2 == 0) &&
(uuid.data3 == 0) &&
(uuid.data4[0] == 0) &&
(uuid.data4[1] == 0) &&
(uuid.data4[2] == 0) &&
(uuid.data4[3] == 0) &&
(uuid.data4[4] == 0) &&
(uuid.data4[5] == 0) &&
(uuid.data4[6] == 0) &&
(uuid.data4[7] == 0);
}
static int
dissect_aim_tlv_value_extended_data(proto_tree *entry, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
guint16 length;
int start_offset;
e_guid_t plugin_uuid;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(entry, hf_aim_icbm_client_err_length, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset+=2;
start_offset = offset;
proto_tree_add_item(entry, hf_aim_icbm_client_err_protocol_version, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
offset = dissect_aim_plugin(entry, tvb, offset, &plugin_uuid);
proto_tree_add_item(entry, hf_aim_messaging_unknown, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(entry, hf_aim_icbm_client_err_client_caps_flags, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(entry, hf_aim_messaging_unknown, tvb, offset, 1, ENC_NA); offset += 1;
proto_tree_add_item(entry, hf_aim_icbm_client_err_downcounter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset = start_offset + length;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(entry, hf_aim_icbm_client_err_length, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset+=2;
start_offset = offset;
proto_tree_add_item(entry, hf_aim_icbm_client_err_downcounter, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(entry, hf_aim_messaging_unknown_data, tvb, offset, length-2, ENC_NA);
offset = start_offset + length;
if (is_uuid_null(plugin_uuid))
{
tvbuff_t *subtvb = tvb_new_subset_remaining(tvb, offset);
dissect_aim_rendezvous_extended_message(subtvb, entry);
}
else
{
proto_tree_add_item(entry, hf_aim_messaging_plugin_specific_data, tvb, offset, -1, ENC_NA);
}
offset = tvb_reported_length(tvb);
return offset;
}
static int
dissect_aim_msg_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree,hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA); offset+=8;
proto_tree_add_item(msg_tree, hf_aim_message_channel_id, tvb, offset, 2,
ENC_BIG_ENDIAN); offset += 2;
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
return offset;
}
static int
dissect_aim_msg_client_err(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
guint16 channel, reason;
proto_tree_add_item(msg_tree,hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA); offset+=8;
channel = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(msg_tree,hf_aim_icbm_channel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
reason = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(msg_tree, hf_aim_icbm_client_err_reason, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
if (reason == CLIENT_ERR__REASON_CHANNEL_SPECIFIC && tvb_reported_length_remaining(tvb, offset) > 0)
{
switch (channel)
{
case ICBM_CHANNEL_RENDEZVOUS:
proto_tree_add_item(msg_tree, hf_aim_icbm_rendezvous_nak_length, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_rendezvous_nak, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
break;
default:
{
tvbuff_t *subtvb = tvb_new_subset_remaining(tvb, offset);
proto_tree *extended_tree = proto_tree_add_subtree(msg_tree, tvb, offset, -1, ett_aim_extended_data, NULL, "Extended Data");
dissect_aim_tlv_value_extended_data(extended_tree, 0, subtvb, pinfo);
break;
}
}
}
return offset;
}
static int dissect_aim_popup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *popup_tree)
{
return dissect_aim_tlv(tvb, pinfo, 0, popup_tree, aim_popup_tlvs);
}
static int dissect_aim_snac_signon_logon(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, aim_client_tlvs);
}
return offset;
}
static int dissect_aim_snac_signon_logon_reply(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree)
{
int offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, aim_client_tlvs);
}
return offset;
}
static int dissect_aim_snac_signon_signon(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
guint8 buddyname_length = 0;
int offset = 0;
guint8 *buddyname;
proto_tree_add_item(tree, hf_aim_infotype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 1;
buddyname_length = aim_get_buddyname( &buddyname, tvb, offset );
col_append_fstr(pinfo->cinfo, COL_INFO, " Username: %s",
format_text(wmem_packet_scope(), buddyname, buddyname_length));
if(tree) {
offset+=dissect_aim_buddyname(tvb, pinfo, offset, tree);
}
return offset;
}
static int dissect_aim_snac_signon_signon_reply(tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree)
{
int offset = 0;
guint16 challenge_length = 0;
challenge_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_signon_challenge_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_aim_signon_challenge, tvb, offset, challenge_length, ENC_UTF_8|ENC_NA);
offset += challenge_length;
return offset;
}
static int dissect_aim_tlv_value_registration(proto_item *ti _U_, guint16 value_id _U_, tvbuff_t *tvb _U_, packet_info *pinfo _U_)
{
return 0;
}
static int dissect_aim_snac_register (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return dissect_aim_tlv(tvb, pinfo, 0, tree, aim_registration_tlvs);
}
static int calc_ssi_entry_size(tvbuff_t *tvb, int offset)
{
gint ssi_entry_size = 2 + tvb_get_ntohs(tvb, offset) + 2 * 3;
ssi_entry_size += tvb_get_ntohs(tvb, offset + ssi_entry_size) + 2;
return ssi_entry_size;
}
static int dissect_ssi_item(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *ssi_entry)
{
guint16 buddyname_length = 0;
int endoffset;
guint16 tlv_len = 0;
buddyname_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_buddyname_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (buddyname_length > 0) {
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
}
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_gid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_bid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tlv_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssi_entry, hf_aim_fnac_subtype_ssi_tlvlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
endoffset = offset;
while(endoffset < offset+tlv_len) {
endoffset = dissect_aim_tlv(tvb, pinfo, endoffset, ssi_entry, aim_client_tlvs);
}
return endoffset;
}
static int dissect_ssi_ssi_item(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ssi_entry)
{
return dissect_ssi_item(tvb, pinfo, 0, ssi_entry);
}
static int dissect_ssi_ssi_items(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
gint ssi_entry_size;
proto_tree *ssi_entry = NULL;
int size = tvb_reported_length(tvb);
while (size > offset)
{
ssi_entry_size = calc_ssi_entry_size(tvb, offset);
ssi_entry = proto_tree_add_subtree(tree, tvb, offset, ssi_entry_size, ett_aim_ssi, NULL, "SSI Entry");
offset = dissect_ssi_item(tvb, pinfo, offset, ssi_entry);
}
return offset;
}
static int dissect_aim_ssi_rightsinfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ssi_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, ssi_tree, aim_ssi_rightsinfo_tlvs);
}
static int dissect_aim_ssi_was_added(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ssi_tree)
{
return dissect_aim_buddyname(tvb, pinfo, 0, ssi_tree);
}
static int dissect_aim_snac_ssi_time_and_items_num(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
nstime_t tmptime;
tmptime.secs = tvb_get_ntohl(tvb, offset);
tmptime.nsecs = 0;
proto_tree_add_time(tree, hf_aim_fnac_subtype_ssi_last_change_time, tvb, offset, 4, &tmptime);
offset += 4;
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_numitems, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_aim_snac_ssi_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_tree *ssi_entry = NULL;
guint16 num_items, i;
nstime_t tmptime;
gint ssi_entry_size;
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_numitems, tvb, offset, 2, ENC_BIG_ENDIAN);
num_items = tvb_get_ntohs(tvb, offset);
offset += 2;
for(i = 0; i < num_items; i++) {
ssi_entry_size = calc_ssi_entry_size(tvb, offset);
ssi_entry = proto_tree_add_subtree_format(tree, tvb, offset, ssi_entry_size,
ett_aim_ssi, NULL, "SSI Entry %u", i);
offset = dissect_ssi_item(tvb, pinfo, offset, ssi_entry);
}
tmptime.secs = tvb_get_ntohl(tvb, offset);
tmptime.nsecs = 0;
proto_tree_add_time(tree, hf_aim_fnac_subtype_ssi_last_change_time, tvb, offset, 4, &tmptime);
return offset;
}
static int dissect_aim_snac_ssi_auth_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 reason_length;
guint8 buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname_len8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (buddyname_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
}
reason_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (reason_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str, tvb, offset, reason_length, ENC_UTF_8|ENC_NA);
offset += reason_length;
}
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_grant_auth_unkn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_aim_snac_ssi_auth_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 reason_length;
guint8 buddyname_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname_len8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (buddyname_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_buddyname, tvb, offset, buddyname_length, ENC_UTF_8|ENC_NA);
offset += buddyname_length;
}
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_allow_auth, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
reason_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (reason_length > 0) {
proto_tree_add_item(tree, hf_aim_fnac_subtype_ssi_reason_str, tvb, offset, reason_length, ENC_UTF_8|ENC_NA);
offset += reason_length;
}
return offset;
}
static int dissect_aim_sst_buddy_down_req (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = dissect_aim_buddyname(tvb, pinfo, 0, tree);
guint8 md5_size;
proto_tree_add_item(tree, hf_aim_sst_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_aim_sst_md5_hash_size, tvb, offset, 1, ENC_BIG_ENDIAN);
md5_size = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_aim_sst_md5_hash, tvb, offset, md5_size, ENC_NA);
offset+=md5_size;
return offset;
}
static int dissect_aim_sst_buddy_down_repl (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = dissect_aim_buddyname(tvb, pinfo, 0, tree);
guint8 md5_size;
guint16 icon_size;
proto_tree_add_item(tree, hf_aim_sst_unknown, tvb, offset, 3, ENC_NA);
offset+=3;
proto_tree_add_item(tree, hf_aim_sst_md5_hash_size, tvb, offset, 1, ENC_BIG_ENDIAN);
md5_size = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_aim_sst_md5_hash, tvb, offset, md5_size, ENC_NA);
offset+=md5_size;
proto_tree_add_item(tree, hf_aim_sst_icon_size, tvb, offset, 2, ENC_BIG_ENDIAN);
icon_size = tvb_get_ntohs(tvb, offset);
offset+=2;
if (icon_size)
{
proto_tree_add_item(tree, hf_aim_sst_icon, tvb, offset, icon_size, ENC_NA);
}
offset+=icon_size;
return offset;
}
static int dissect_aim_sst_buddy_up_repl (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 md5_size;
proto_tree_add_item(tree, hf_aim_sst_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_aim_sst_md5_hash_size, tvb, offset, 1, ENC_BIG_ENDIAN);
md5_size = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_aim_sst_md5_hash, tvb, offset, md5_size, ENC_NA);
offset+=md5_size;
return offset;
}
static int dissect_aim_sst_buddy_up_req (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 icon_size;
proto_tree_add_item(tree, hf_aim_sst_ref_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_aim_sst_icon_size, tvb, offset, 2, ENC_BIG_ENDIAN);
icon_size = tvb_get_ntohs(tvb, offset);
offset+=2;
if (icon_size)
{
proto_tree_add_item(tree, hf_aim_sst_icon, tvb, offset, icon_size, ENC_NA);
}
offset+=icon_size;
return offset;
}
static int dissect_aim_userlookup_search(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *lookup_tree)
{
proto_tree_add_item(lookup_tree, hf_aim_userlookup_email, tvb, 0, tvb_reported_length(tvb), ENC_UTF_8|ENC_NA);
return tvb_reported_length(tvb);
}
static int dissect_aim_userlookup_result(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lookup_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, lookup_tree, aim_client_tlvs);
}
static void
family_free(gpointer p, gpointer user_data _U_)
{
g_free(p);
}
static void
aim_shutdown(void)
{
g_list_foreach(families, family_free, NULL);
g_list_free(families);
}
void
proto_register_aim(void)
{
static hf_register_info hf[] = {
{ &hf_aim_cmd_start,
{ "Command Start", "aim.cmd_start", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_channel,
{ "Channel ID", "aim.channel", FT_UINT8, BASE_HEX, VALS(aim_flap_channels), 0x0, NULL, HFILL }
},
{ &hf_aim_seqno,
{ "Sequence Number", "aim.seqno", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_version,
{ "Protocol Version", "aim.version", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_data_len,
{ "Data Field Length", "aim.datalen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_tlv_length,
{ "Length", "aim.tlv.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_tlv_value_id,
{ "Value ID", "aim.tlv.value_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_data,
{ "Data", "aim.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_family,
{ "FNAC Family ID", "aim.fnac.family", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype,
{ "FNAC Subtype ID", "aim.fnac.subtype", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_flags,
{ "FNAC Flags", "aim.fnac.flags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_id,
{ "FNAC ID", "aim.fnac.id", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_buddyname_len,
{ "Buddyname len", "aim.buddynamelen", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_buddyname,
{ "Buddy Name", "aim.buddyname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_tlvcount,
{ "TLV Count", "aim.tlvcount", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_snac_error,
{ "SNAC Error", "aim.snac.error", FT_UINT16, BASE_HEX, VALS(aim_snac_errors), 0x0, NULL, HFILL },
},
{ &hf_aim_userclass_unconfirmed,
{ "AOL Unconfirmed account flag", "aim.userclass.unconfirmed", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNCONFIRMED, NULL, HFILL },
},
{ &hf_aim_userclass_administrator,
{ "AOL Administrator flag", "aim.userclass.administrator", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_ADMINISTRATOR, NULL, HFILL },
},
{ &hf_aim_userclass_aol,
{ "AOL Staff User Flag", "aim.userclass.staff", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_AOL, NULL, HFILL },
},
{ &hf_aim_userclass_commercial,
{ "AOL commercial account flag", "aim.userclass.commercial", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_COMMERCIAL, NULL, HFILL },
},
{ &hf_aim_userclass_aim,
{ "AIM user flag", "aim.userclass.free", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_AIM, NULL, HFILL },
},
{ &hf_aim_userclass_away,
{ "AOL away status flag", "aim.userclass.away", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_AWAY, NULL, HFILL },
},
{ &hf_aim_userclass_icq,
{ "ICQ user sign", "aim.userclass.icq", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_ICQ, NULL, HFILL },
},
{ &hf_aim_userclass_wireless,
{ "AOL wireless user", "aim.userclass.wireless", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_WIRELESS, NULL, HFILL },
},
{ &hf_aim_userclass_unknown100,
{ "Unknown bit", "aim.userclass.unknown100", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN100, NULL, HFILL },
},
{ &hf_aim_userclass_imf,
{ "Using IM Forwarding", "aim.userclass.imf", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_IMF, NULL, HFILL },
},
{ &hf_aim_userclass_bot,
{ "Bot User", "aim.userclass.bot", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_BOT, NULL, HFILL },
},
{ &hf_aim_userclass_unknown800,
{ "Unknown bit", "aim.userclass.unknown800", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN800, NULL, HFILL },
},
{ &hf_aim_userclass_one_way_wireless,
{ "One Way Wireless Device", "aim.userclass.one_way_wireless", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_ONE_WAY_WIRELESS, NULL, HFILL },
},
{ &hf_aim_userclass_unknown2000,
{ "Unknown bit", "aim.userclass.unknown2000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN2000, NULL, HFILL },
},
{ &hf_aim_userclass_unknown4000,
{ "Unknown bit", "aim.userclass.unknown4000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN4000, NULL, HFILL },
},
{ &hf_aim_userclass_unknown8000,
{ "Unknown bit", "aim.userclass.unknown8000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN8000, NULL, HFILL },
},
{ &hf_aim_userclass_unknown10000,
{ "Unknown bit", "aim.userclass.unknown10000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN10000, NULL, HFILL },
},
{ &hf_aim_userclass_unknown20000,
{ "Unknown bit", "aim.userclass.unknown20000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_UNKNOWN20000, NULL, HFILL },
},
{ &hf_aim_userclass_no_knock_knock,
{ "Do not display the 'not on Buddy List' knock-knock", "aim.userclass.no_knock_knock", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_NO_KNOCK_KNOCK, NULL, HFILL },
},
{ &hf_aim_userclass_forward_mobile,
{ "Forward to mobile if not active", "aim.userclass.forward_mobile", FT_BOOLEAN, 32, TFS(&tfs_set_notset), CLASS_FORWARD_MOBILE, NULL, HFILL },
},
{ &hf_aim_nickinfo_caps,
{ "Client capabilities", "aim.nickinfo.caps", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_nickinfo_short_caps,
{ "Short client capabilities", "aim.nickinfo.short_caps", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_fnac_flag_next_is_related,
{ "Followed By SNAC with related information", "aim.fnac.flags.next_is_related", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FNAC_FLAG_NEXT_IS_RELATED, NULL, HFILL },
},
{ &hf_aim_fnac_flag_contains_version,
{ "Contains Version of Family this SNAC is in", "aim.fnac.flags.contains_version", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FNAC_FLAG_CONTAINS_VERSION, NULL, HFILL },
},
{ &hf_aim_userinfo_warninglevel,
{ "Warning Level", "aim.userinfo.warninglevel", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_featuresdes,
{ "Features", "aim.messageblock.featuresdes", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_featureslen,
{ "Features Length", "aim.messageblock.featureslen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_features,
{ "Features", "aim.messageblock.features", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_info,
{ "Block info", "aim.messageblock.info", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_len,
{ "Block length", "aim.messageblock.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_charset,
{ "Block Character set", "aim.messageblock.charset", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_charsubset,
{ "Block Character subset", "aim.messageblock.charsubset", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_messageblock_message,
{ "Message", "aim.messageblock.message", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_ip,
{ "Internal IP address", "aim.dcinfo.addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_tcpport,
{ "TCP Port", "aim.dcinfo.tcpport", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_type,
{ "Type", "aim.dcinfo.type", FT_UINT8, BASE_HEX, VALS(dc_types), 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_proto_version,
{ "Protocol Version", "aim.dcinfo.proto_version", FT_UINT16, BASE_DEC, VALS(protocol_versions), 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_auth_cookie,
{ "Authorization Cookie", "aim.dcinfo.auth_cookie", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_webport,
{ "Web Front Port", "aim.dcinfo.webport", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_client_future,
{ "Client Futures", "aim.dcinfo.client_futures", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_last_info_update,
{ "Last Info Update", "aim.dcinfo.last_info_update", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_last_ext_info_update,
{ "Last Extended Info Update", "aim.dcinfo.last_ext_info_update", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_last_ext_status_update,
{ "Last Extended Status Update", "aim.dcinfo.last_ext_status_update", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_dcinfo_unknown,
{ "Unknown", "aim.dcinfo.unknown", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_ssi_result_code,
{ "Last SSI operation result code", "aim.ssi.code", FT_UINT16, BASE_HEX, VALS(aim_ssi_result_codes), 0x0, NULL, HFILL },
},
{ &hf_aim_string08,
{ "Address/Port List", "aim.string08", FT_UINT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
};
static hf_register_info hf_admin[] = {
{ &hf_admin_acctinfo_code,
{ "Account Information Request Code", "aim_admin.acctinfo.code", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_admin_acctinfo_unknown,
{ "Unknown", "aim_admin.acctinfo.unknown", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_admin_acctinfo_permissions,
{ "Account Permissions", "aim_admin.acctinfo.permissions", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_admin_confirm_status,
{ "Confirmation status", "aim_admin.confirm_status", FT_UINT16, BASE_HEX, VALS(confirm_statusses), 0x0, NULL, HFILL },
},
};
static hf_register_info hf_bos[] = {
#if 0
{ &hf_aim_bos_data,
{ "Data", "aim_bos.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_aim_bos_class,
{ "User class", "aim_bos.userclass", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
};
static hf_register_info hf_buddylist[] = {
{ &hf_aim_buddylist_userinfo_warninglevel,
{ "Warning Level", "aim_buddylist.userinfo.warninglevel", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
};
static hf_register_info hf_chat[] = {
{ &hf_aim_chat_screen_name,
{ "Screen Name", "aim_chat.screen_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
};
static hf_register_info hf_generic[] = {
{ &hf_generic_servicereq_service,
{ "Requested Service", "aim_generic.servicereq.service", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_motd_motdtype,
{ "MOTD Type", "aim_generic.motd.motdtype", FT_UINT16, BASE_HEX, VALS(aim_snac_generic_motd_motdtypes), 0x0, NULL, HFILL },
},
{ &hf_generic_family,
{ "Family", "aim_generic.family", FT_UINT16, BASE_CUSTOM, CF_FUNC(aim_generic_family), 0x0, NULL, HFILL },
},
{ &hf_generic_version,
{ "Version", "aim_generic.version", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_dll_version,
{ "DLL Version", "aim_generic.dll_version", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_numclasses,
{ "Number of Rateinfo Classes", "aim_generic.rateinfo.numclasses", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_windowsize,
{ "Window Size", "aim_generic.rateinfo.class.window_size", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_clearlevel,
{ "Clear Level", "aim_generic.rateinfo.class.clearlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_alertlevel,
{ "Alert Level", "aim_generic.rateinfo.class.alertlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_limitlevel,
{ "Limit Level", "aim_generic.rateinfo.class.limitlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_disconnectlevel,
{ "Disconnect Level", "aim_generic.rateinfo.class.disconnectlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_currentlevel,
{ "Current Level", "aim_generic.rateinfo.class.currentlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_maxlevel,
{ "Max Level", "aim_generic.rateinfo.class.maxlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_lasttime,
{ "Last Time", "aim_generic.rateinfo.class.lasttime", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_curstate,
{ "Current State", "aim_generic.rateinfo.class.curstate", FT_UINT8, BASE_HEX, VALS(rateinfo_states), 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_classid,
{ "Class ID", "aim_generic.rateinfo.class.id", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_numpairs,
{ "Number of Family/Subtype pairs", "aim_generic.rateinfo.class.numpairs", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfoack_group,
{ "Acknowledged Rate Class", "aim_generic.rateinfoack.class", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_ratechange_msg,
{ "Rate Change Message", "aim_generic.ratechange.msg", FT_UINT16, BASE_HEX, VALS(ratechange_msgs), 0x0, NULL, HFILL },
},
{ &hf_generic_migration_numfams,
{ "Number of families to migrate", "aim_generic.migrate.numfams", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_priv_flags,
{ "Privilege flags", "aim_generic.privilege_flags", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_allow_idle_see,
{ "Allow other users to see idle time", "aim_generic.privilege_flags.allow_idle", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x0001, NULL, HFILL },
},
{ &hf_generic_allow_member_see,
{ "Allow other users to see how long account has been a member", "aim_generic.privilege_flags.allow_member", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x0002, NULL, HFILL },
},
{ &hf_generic_selfinfo_warninglevel,
{ "Warning level", "aim_generic.selfinfo.warn_level", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_evil_new_warn_level,
{ "New warning level", "aim_generic.evil.new_warn_level", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_idle_time,
{ "Idle time (seconds)", "aim_generic.idle_time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_client_ver_req_offset,
{ "Client Verification Request Offset", "aim_generic.client_verification.offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_client_ver_req_length,
{ "Client Verification Request Length", "aim_generic.client_verification.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_client_ver_req_hash,
{ "Client Verification MD5 Hash", "aim_generic.client_verification.hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_ext_status_type,
{ "Extended Status Type", "aim_generic.ext_status.type", FT_UINT16, BASE_DEC, VALS(ext_status_types), 0x0, NULL, HFILL },
},
{ &hf_generic_ext_status_flags,
{ "Extended Status Flags", "aim_generic.ext_status.flags", FT_UINT8, BASE_HEX, VALS(ext_status_flags), 0x0, NULL, HFILL },
},
{ &hf_generic_ext_status_length,
{ "Extended Status Length", "aim_generic.ext_status.length", FT_UINT8, BASE_HEX, NULL, 0x0, NULL , HFILL },
},
{ &hf_generic_ext_status_data,
{ "Extended Status Data", "aim_generic.ext_status.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL , HFILL },
},
};
static hf_register_info hf_icq[] = {
{ &hf_icq_tlv_data_chunk_size,
{ "Data chunk size", "aim_icq.chunk_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_icq_tlv_request_owner_uid,
{ "Owner UID", "aim_icq.owner_uid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL},
},
{ &hf_icq_tlv_request_type,
{"Request Type", "aim_icq.request_type", FT_UINT16, BASE_DEC, VALS(aim_icq_data_types), 0x0, NULL, HFILL},
},
{ &hf_icq_tlv_request_seq_num,
{"Request Sequence Number", "aim_icq.request_seq_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL},
},
{ &hf_icq_dropped_msg_flag,
{"Dropped messages flag", "aim_icq.offline_msgs.dropped_flag", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_icq_meta_subtype,
{"Meta Request Subtype", "aim_icq.subtype", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
};
static hf_register_info hf_location[] = {
{ &hf_aim_location_buddyname_len,
{ "Buddyname len", "aim_location.buddynamelen", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_location_buddyname,
{ "Buddy Name", "aim_location.buddyname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_location_userinfo_warninglevel,
{ "Warning Level", "aim_location.userinfo.warninglevel", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_snac_location_request_user_info_infotype,
{ "Infotype", "aim_location.snac.request_user_info.infotype", FT_UINT16, BASE_HEX, VALS(aim_snac_location_request_user_info_infotypes), 0x0, NULL, HFILL }
},
};
static hf_register_info hf_messaging[] = {
{ &hf_aim_icbm_channel,
{ "Channel", "aim_messaging.icbm.channel",
FT_UINT16, BASE_HEX, VALS(icbm_channel_types), 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_msg_flags,
{ "Message Flags", "aim_messaging.icbm.flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_max_snac_size,
{ "Max SNAC Size", "aim_messaging.icbm.max_snac",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_max_sender_warnlevel,
{ "Max sender warn level", "aim_messaging.icbm.max_sender_warn-level",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_max_receiver_warnlevel,
{ "max receiver warn level", "aim_messaging.icbm.max_receiver_warnlevel",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_min_msg_interval,
{ "Minimum message interval (milliseconds)", "aim_messaging.icbm.min_msg_interval",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_cookie,
{ "ICBM Cookie", "aim_messaging.icbmcookie",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_message_channel_id,
{ "Message Channel ID", "aim_messaging.channelid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_evil,
{ "Send Evil Bit As", "aim_messaging.evilreq.origin",
FT_UINT16, BASE_DEC, VALS(evil_origins), 0x0, NULL, HFILL }
},
{ &hf_aim_evil_warn_level,
{ "Old warning level", "aim_messaging.evil.warn_level",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_evil_new_warn_level,
{ "New warning level", "aim_messaging.evil.new_warn_level",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_notification_cookie,
{ "Notification Cookie", "aim_messaging.notification.cookie",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_notification_channel,
{ "Notification Channel", "aim_messaging.notification.channel",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_notification_type,
{ "Notification Type", "aim_messaging.notification.type",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_rendezvous_nak,
{ "Rendezvous NAK reason", "aim_messaging.rendezvous_nak",
FT_UINT16, BASE_HEX, VALS(rendezvous_nak_reason_types), 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_rendezvous_nak_length,
{ "Rendezvous NAK reason length", "aim_messaging.rendezvous_nak_length",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_msg_type,
{ "Message Type", "aim_messaging.rendezvous.msg_type",
FT_UINT16, BASE_HEX, VALS(rendezvous_msg_types), 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_client_err_reason,
{ "Reason", "aim_messaging.clienterr.reason",
FT_UINT16, BASE_DEC, VALS(client_err_reason_types), 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_client_err_protocol_version,
{ "Version", "aim_messaging.clienterr.protocol_version",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_icbm_client_err_client_caps_flags,
{ "Client Capabilities Flags", "aim_messaging.clienterr.client_caps_flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_type,
{ "Message Type", "aim_messaging.icbm.extended_data.message.type",
FT_UINT8, BASE_HEX, VALS(extended_data_message_types), 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags,
{ "Message Flags", "aim_messaging.icbm.extended_data.message.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags_normal,
{ "Normal Message", "aim_messaging.icbm.extended_data.message.flags.normal",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EXTENDED_DATA_MFLAG_NORMAL, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags_auto,
{ "Auto Message", "aim_messaging.icbm.extended_data.message.flags.auto",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EXTENDED_DATA_MFLAG_AUTO, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags_multi,
{ "Multiple Recipients Message", "aim_messaging.icbm.rendezvous.extended_data.message.flags.multi",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EXTENDED_DATA_MFLAG_MULTI, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_status_code,
{ "Status Code", "aim_messaging.icbm.extended_data.message.status_code",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_priority_code,
{ "Priority Code", "aim_messaging.icbm.extended_data.message.priority_code",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_text_length,
{ "Text Length", "aim_messaging.icbm.extended_data.message.text_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_text,
{ "Text", "aim_messaging.icbm.extended_data.message.text",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_messaging_plugin, { "Plugin", "aim_messaging.plugin", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_icbm_client_err_length, { "Length", "aim_messaging.clienterr.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_messaging_unknown, { "Unknown", "aim_messaging.unknown", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_icbm_client_err_downcounter, { "Downcounter?", "aim_messaging.clienterr.downcounter", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_messaging_unknown_data, { "Unknown", "aim_messaging.unknown_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_messaging_plugin_specific_data, { "Plugin-specific data", "aim_messaging.plugin_specific_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static hf_register_info hf_signon[] = {
{ &hf_aim_infotype,
{ "Infotype", "aim_signon.infotype", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_signon_challenge_len,
{ "Signon challenge length", "aim_signon.challengelen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_signon_challenge,
{ "Signon challenge", "aim_signon.challenge", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static hf_register_info hf_ssi[] = {
{ &hf_aim_fnac_subtype_ssi_version,
{ "SSI Version", "aim_ssi.fnac.version", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_numitems,
{ "SSI Object count", "aim_ssi.fnac.numitems", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_last_change_time,
{ "SSI Last Change Time", "aim_ssi.fnac.last_change_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_buddyname_len,
{ "SSI Buddy Name length", "aim_ssi.fnac.buddyname_len", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_buddyname,
{ "Buddy Name", "aim_ssi.fnac.buddyname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_gid,
{ "SSI Buddy Group ID", "aim_ssi.fnac.gid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_bid,
{ "SSI Buddy ID", "aim_ssi.fnac.bid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_type,
{ "SSI Buddy type", "aim_ssi.fnac.type", FT_UINT16, BASE_HEX, VALS(aim_fnac_family_ssi_types), 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_tlvlen,
{ "SSI TLV Len", "aim_ssi.fnac.tlvlen", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
#if 0
{ &hf_aim_fnac_subtype_ssi_data,
{ "SSI Buddy Data", "aim_ssi.fnac.data", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
#endif
{ &hf_aim_fnac_subtype_ssi_buddyname_len8,
{ "SSI Buddy Name length", "aim_ssi.fnac.buddyname_len8", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_reason_str_len,
{ "Reason Message length", "aim_ssi.fnac.reason_len", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_reason_str,
{ "Reason Message", "aim_ssi.fnac.reason", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_grant_auth_unkn,
{ "Unknown", "aim_ssi.fnac.auth_unkn", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_fnac_subtype_ssi_allow_auth,
{ "Allow flag", "aim_ssi.fnac.allow_auth_flag", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
static hf_register_info hf_sst[] = {
{ &hf_aim_sst_md5_hash,
{ "MD5 Hash", "aim_sst.md5", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_md5_hash_size,
{ "MD5 Hash Size", "aim_sst.md5.size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_unknown,
{ "Unknown Data", "aim_sst.unknown", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_ref_num,
{ "Reference Number", "aim_sst.ref_num", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_icon_size,
{ "Icon Size", "aim_sst.icon_size", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_aim_sst_icon,
{ "Icon", "aim_sst.icon", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
};
static hf_register_info hf_userlookup[] = {
{ &hf_aim_userlookup_email,
{ "Email address looked for", "aim_lookup.email", FT_STRING, BASE_NONE, NULL, 0, "Email address", HFILL }
},
};
static gint *ett[] = {
&ett_aim,
&ett_aim_dcinfo,
&ett_aim_fnac,
&ett_aim_fnac_flags,
&ett_aim_tlv,
&ett_aim_tlv_value,
&ett_aim_buddyname,
&ett_aim_userclass,
&ett_aim_messageblock,
&ett_aim_nickinfo_caps,
&ett_aim_nickinfo_short_caps,
&ett_aim_string08_array,
&ett_aim_admin,
&ett_aim_adverts,
&ett_aim_bos,
&ett_aim_buddylist,
&ett_aim_chat,
&ett_aim_chatnav,
&ett_aim_directory,
&ett_aim_email,
&ett_generic_clientready,
&ett_generic_migratefamilies,
&ett_generic_clientready_item,
&ett_generic_serverready,
&ett_generic,
&ett_generic_priv_flags,
&ett_generic_rateinfo_class,
&ett_generic_rateinfo_classes,
&ett_generic_rateinfo_groups,
&ett_generic_rateinfo_group,
&ett_aim_icq,
&ett_aim_icq_tlv,
&ett_aim_invitation,
&ett_aim_location,
&ett_aim_messaging,
&ett_aim_rendezvous_data,
&ett_aim_extended_data,
&ett_aim_extended_data_message_flags,
&ett_aim_popup,
&ett_aim_signon,
&ett_aim_ssi,
&ett_ssi,
&ett_aim_sst,
&ett_aim_stats,
&ett_aim_translate,
&ett_aim_userlookup,
};
static ei_register_info ei[] = {
{ &ei_aim_messageblock_len, { "aim.messageblock.length.invalid", PI_PROTOCOL, PI_WARN, "Invalid block length", EXPFILL }},
};
module_t *aim_module;
expert_module_t *expert_aim;
proto_aim = proto_register_protocol("AOL Instant Messenger", "AIM", "aim");
proto_aim_admin = proto_register_protocol("AIM Administrative", "AIM Administration", "aim_admin");
proto_aim_adverts = proto_register_protocol("AIM Advertisements", "AIM Advertisements", "aim_adverts");
proto_aim_bos = proto_register_protocol("AIM Privacy Management Service", "AIM BOS", "aim_bos");
proto_aim_buddylist = proto_register_protocol("AIM Buddylist Service", "AIM Buddylist", "aim_buddylist");
proto_aim_chat = proto_register_protocol("AIM Chat Service", "AIM Chat", "aim_chat");
proto_aim_chatnav = proto_register_protocol("AIM Chat Navigation", "AIM ChatNav", "aim_chatnav");
proto_aim_directory = proto_register_protocol("AIM Directory Search", "AIM Directory", "aim_dir");
proto_aim_email = proto_register_protocol("AIM E-mail", "AIM Email", "aim_email");
proto_aim_generic = proto_register_protocol("AIM Generic Service", "AIM Generic", "aim_generic");
proto_aim_icq = proto_register_protocol("AIM ICQ", "AIM ICQ", "aim_icq");
proto_aim_invitation = proto_register_protocol("AIM Invitation Service", "AIM Invitation", "aim_invitation");
proto_aim_location = proto_register_protocol("AIM Location", "AIM Location", "aim_location");
proto_aim_messaging = proto_register_protocol("AIM Messaging", "AIM Messaging", "aim_messaging");
proto_aim_popup = proto_register_protocol("AIM Popup", "AIM Popup", "aim_popup");
proto_aim_signon = proto_register_protocol("AIM Signon", "AIM Signon", "aim_signon");
proto_aim_ssi = proto_register_protocol("AIM Server Side Info", "AIM SSI", "aim_ssi");
proto_aim_sst = proto_register_protocol("AIM Server Side Themes", "AIM SST", "aim_sst");
proto_aim_stats = proto_register_protocol("AIM Statistics", "AIM Stats", "aim_stats");
proto_aim_translate = proto_register_protocol("AIM Translate", "AIM Translate", "aim_translate");
proto_aim_userlookup = proto_register_protocol("AIM User Lookup", "AIM User Lookup", "aim_lookup");
proto_register_field_array(proto_aim, hf, array_length(hf));
proto_register_field_array(proto_aim_admin, hf_admin, array_length(hf_admin));
proto_register_field_array(proto_aim_bos, hf_bos, array_length(hf_bos));
proto_register_field_array(proto_aim_buddylist, hf_buddylist, array_length(hf_buddylist));
proto_register_field_array(proto_aim_chat, hf_chat, array_length(hf_chat));
proto_register_field_array(proto_aim_generic, hf_generic, array_length(hf_generic));
proto_register_field_array(proto_aim_icq, hf_icq, array_length(hf_icq));
proto_register_field_array(proto_aim_location, hf_location, array_length(hf_location));
proto_register_field_array(proto_aim_messaging, hf_messaging, array_length(hf_messaging));
proto_register_field_array(proto_aim_signon, hf_signon, array_length(hf_signon));
proto_register_field_array(proto_aim_ssi, hf_ssi, array_length(hf_ssi));
proto_register_field_array(proto_aim_sst, hf_sst, array_length(hf_sst));
proto_register_field_array(proto_aim_userlookup, hf_userlookup, array_length(hf_userlookup));
proto_register_subtree_array(ett, array_length(ett));
expert_aim = expert_register_protocol(proto_aim);
expert_register_field_array(expert_aim, ei, array_length(ei));
aim_handle = register_dissector("aim", dissect_aim, proto_aim);
aim_module = prefs_register_protocol(proto_aim, NULL);
prefs_register_bool_preference(aim_module, "desegment",
"Reassemble AIM messages spanning multiple TCP segments",
"Whether the AIM dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&aim_desegment);
register_shutdown_routine(aim_shutdown);
}
void
proto_reg_handoff_aim(void)
{
dissector_add_uint_range_with_preference("tcp.port", TCP_PORTS_AIM_DEFAULT, aim_handle);
ssl_dissector_add(0, aim_handle);
heur_dissector_add("ssl", dissect_aim_ssl_heur, "AIM over SSL", "aim_ssl", proto_aim, HEURISTIC_DISABLE);
aim_init_family(proto_aim_admin, ett_aim_admin, FAMILY_ADMIN, aim_fnac_family_admin);
aim_init_family(proto_aim_adverts, ett_aim_adverts, FAMILY_ADVERTS, aim_fnac_family_adverts);
aim_init_family(proto_aim_bos, ett_aim_bos, FAMILY_BOS, aim_fnac_family_bos);
aim_init_family(proto_aim_buddylist, ett_aim_buddylist, FAMILY_BUDDYLIST, aim_fnac_family_buddylist);
aim_init_family(proto_aim_chat, ett_aim_chat, FAMILY_CHAT, aim_fnac_family_chat);
aim_init_family(proto_aim_chatnav, ett_aim_chatnav, FAMILY_CHAT_NAV, aim_fnac_family_chatnav);
aim_init_family(proto_aim_directory, ett_aim_directory, FAMILY_DIRECTORY, aim_fnac_family_directory);
aim_init_family(proto_aim_email, ett_aim_email, FAMILY_EMAIL, aim_fnac_family_email);
aim_init_family(proto_aim_generic, ett_generic, FAMILY_GENERIC, aim_fnac_family_generic);
aim_init_family(proto_aim_icq, ett_aim_icq, FAMILY_ICQ, aim_fnac_family_icq);
aim_init_family(proto_aim_invitation, ett_aim_invitation, FAMILY_INVITATION, aim_fnac_family_invitation);
aim_init_family(proto_aim_location, ett_aim_location, FAMILY_LOCATION, aim_fnac_family_location);
aim_init_family(proto_aim_messaging, ett_aim_messaging, FAMILY_MESSAGING, aim_fnac_family_messaging);
aim_init_family(proto_aim_popup, ett_aim_popup, FAMILY_POPUP, aim_fnac_family_popup);
aim_init_family(proto_aim_signon, ett_aim_signon, FAMILY_SIGNON, aim_fnac_family_signon);
aim_init_family(proto_aim_ssi, ett_aim_ssi, FAMILY_SSI, aim_fnac_family_ssi);
aim_init_family(proto_aim_sst, ett_aim_sst, FAMILY_SST, aim_fnac_family_sst);
aim_init_family(proto_aim_stats, ett_aim_stats, FAMILY_STATS, aim_fnac_family_stats);
aim_init_family(proto_aim_translate, ett_aim_translate, FAMILY_TRANSLATE, aim_fnac_family_translate);
aim_init_family(proto_aim_userlookup, ett_aim_userlookup, FAMILY_USERLOOKUP, aim_fnac_family_userlookup);
}
