const aim_subtype
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
const aim_family
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
int
aim_get_buddyname( guint8 **name, tvbuff_t *tvb, int offset)
{
guint8 buddyname_length;
buddyname_length = tvb_get_guint8(tvb, offset);
*name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, buddyname_length, ENC_UTF_8|ENC_NA);
return buddyname_length;
}
void
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
void
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
int
dissect_aim_snac_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *aim_tree)
{
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tvb_get_ntohs(tvb, 0), aim_snac_errors, "Unknown SNAC error 0x%02x"));
proto_tree_add_item (aim_tree, hf_aim_snac_error, tvb, 0, 2, ENC_BIG_ENDIAN);
return dissect_aim_tlv_sequence(tvb, pinfo, 2, aim_tree, aim_client_tlvs);
}
int
dissect_aim_ssi_result(tvbuff_t *tvb, packet_info *pinfo, proto_tree *aim_tree)
{
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tvb_get_ntohs(tvb, 0), aim_ssi_result_codes, "Unknown SSI result code 0x%02x"));
proto_tree_add_item (aim_tree, hf_aim_ssi_result_code, tvb, 0, 2, ENC_BIG_ENDIAN);
return 2;
}
int
dissect_aim_userinfo(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_aim_buddyname(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_aim_userinfo_warninglevel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return dissect_aim_tlv_list(tvb, pinfo, offset, tree, aim_onlinebuddy_tlvs);
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
dissect_aim_close_conn(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Close Connection");
dissect_aim_tlv_sequence(tvb, pinfo, offset, tree, aim_client_tlvs);
}
static void
dissect_aim_unknown_channel(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Unknown Channel");
if (tvb_reported_length_remaining(tvb, offset) > 0)
proto_tree_add_item(tree, hf_aim_data, tvb, offset, -1, ENC_NA);
}
int
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
int
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
int
dissect_aim_tlv_value_client_capabilities(proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
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
dissect_aim_tlv_value_client_short_capabilities(proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
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
int
dissect_aim_tlv_value_time(proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
return tvb_reported_length(tvb);
}
int
dissect_aim_userclass(tvbuff_t *tvb, int offset, int len, proto_item *ti, guint32 flags)
{
proto_tree *entry;
entry = proto_item_add_subtree(ti, ett_aim_userclass);
proto_tree_add_boolean(entry, hf_aim_userclass_unconfirmed, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_administrator, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_aol, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_commercial, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_aim, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_away, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_icq, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_wireless, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown100, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_imf, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_bot, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown800, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_one_way_wireless, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown2000, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown4000, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown8000, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown10000, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_unknown20000, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_no_knock_knock, tvb, offset, len, flags);
proto_tree_add_boolean(entry, hf_aim_userclass_forward_mobile, tvb, offset, len, flags);
return offset+len;
}
int
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
int
dissect_aim_tlv_value_string (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint8 *buf;
gint string_len;
string_len = tvb_reported_length(tvb);
buf = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, string_len, ENC_UTF_8|ENC_NA);
proto_item_set_text(ti, "Value: %s", format_text(buf, string_len));
return string_len;
}
int
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
int
dissect_aim_tlv_value_bytes (proto_item *ti _U_, guint16 valueid _U_, tvbuff_t *tvb _U_, packet_info *pinfo _U_)
{
return tvb_reported_length(tvb);
}
int
dissect_aim_tlv_value_uint8 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint8 value8 = tvb_get_guint8(tvb, 0);
proto_item_set_text(ti, "Value: %d", value8);
return 1;
}
int
dissect_aim_tlv_value_uint16 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint16 value16 = tvb_get_ntohs(tvb, 0);
proto_item_set_text(ti, "Value: %d", value16);
return 2;
}
int
dissect_aim_tlv_value_ipv4 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
proto_item_set_text(ti, "Value: %s", tvb_ip_to_str(tvb, 0));
return 4;
}
int
dissect_aim_tlv_value_uint32 (proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
guint32 value32 = tvb_get_ntohl(tvb, 0);
proto_item_set_text(ti, "Value: %d", value32);
return 4;
}
int
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
format_text(buf, blocklen - 4));
proto_tree_add_item(entry, hf_aim_messageblock_message, tvb,
offset, blocklen-4, ENC_ASCII|ENC_NA);
offset += blocklen-4;
}
return offset;
}
int
dissect_aim_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, int offset,
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
int
dissect_aim_tlv_sequence(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree, const aim_tlv *tlv_table)
{
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_tlv(tvb, pinfo, offset, tree, tlv_table);
}
return offset;
}
int
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
#if 0
{ &hf_aim_signon_challenge_len,
{ "Signon challenge length", "aim.signon.challengelen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_aim_signon_challenge,
{ "Signon challenge", "aim.signon.challenge", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
#endif
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
#if 0
{ &hf_aim_infotype,
{ "Infotype", "aim.infotype", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
#endif
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
&ett_aim_string08_array
};
static ei_register_info ei[] = {
{ &ei_aim_messageblock_len, { "aim.messageblock.length.invalid", PI_PROTOCOL, PI_WARN, "Invalid block length", EXPFILL }},
};
module_t *aim_module;
expert_module_t *expert_aim;
proto_aim = proto_register_protocol("AOL Instant Messenger", "AIM", "aim");
proto_register_field_array(proto_aim, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_aim = expert_register_protocol(proto_aim);
expert_register_field_array(expert_aim, ei, array_length(ei));
aim_module = prefs_register_protocol(proto_aim, NULL);
prefs_register_bool_preference(aim_module, "desegment",
"Reassemble AIM messages spanning multiple TCP segments",
"Whether the AIM dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&aim_desegment);
}
void
proto_reg_handoff_aim(void)
{
dissector_handle_t aim_handle;
aim_handle = new_create_dissector_handle(dissect_aim, proto_aim);
dissector_add_uint("tcp.port", TCP_PORT_AIM, aim_handle);
}
