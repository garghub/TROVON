static int dissect_edonkey_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree,
int listnum_length, const char* listdesc,
int (*item_dissector)(tvbuff_t *, packet_info *, int, proto_tree *))
{
guint32 listnum, i;
proto_tree *subtree;
proto_item* ti;
proto_item* list_ti;
int list_start_offset;
list_start_offset = offset;
switch (listnum_length) {
case -1:
case 1:
listnum = tvb_get_guint8(tvb, offset);
break;
case -2:
listnum = tvb_get_ntohs(tvb, offset);
break;
case 2:
listnum = tvb_get_letohs(tvb, offset);
break;
case 4:
listnum = tvb_get_letohl(tvb, offset);
break;
case -4:
listnum = tvb_get_ntohl(tvb, offset);
break;
default:
return offset;
}
if (listnum_length < 0)
listnum_length = -listnum_length;
list_ti = proto_tree_add_text(tree, tvb, offset, listnum_length, "%s List Size: %u", listdesc, listnum);
offset+= listnum_length;
for (i=0; i<listnum; i++)
{
int item_start_offset;
item_start_offset = offset;
ti = proto_tree_add_text( tree, tvb, item_start_offset, 1, "%s[%u/%u]", listdesc, i+1, listnum);
subtree = proto_item_add_subtree(ti, ett_edonkey_listitem );
offset = (*item_dissector)(tvb, pinfo, offset, subtree);
proto_item_set_len( ti, offset - item_start_offset );
}
proto_item_set_len(list_ti, offset - list_start_offset );
return offset;
}
static gint lookup_str_index(gchar* str, gint length, const value_string *vs)
{
gint i = 0;
if (str == NULL) return -1;
while (vs[i].strptr) {
if (g_ascii_strncasecmp(str, vs[i].strptr, length) == 0)
return i;
i++;
}
return -1;
}
static guint8 edonkey_metatag_name_get_type(tvbuff_t *tvb, gint start, gint length, guint8 special_tagtype)
{
guint8 *tag_name;
if (match_strval(special_tagtype, edonkey_special_tags) == NULL) {
gint idx;
tag_name = tvb_get_ephemeral_string(tvb, start, length);
idx = lookup_str_index(tag_name, length, edonkey_special_tags);
if (idx < 0)
return EDONKEY_STAG_UNKNOWN;
else return edonkey_special_tags[idx].value;
}
else return special_tagtype;
}
static proto_item* edonkey_tree_add_metatag_name(proto_tree *tree, tvbuff_t *tvb,
gint start, gint length, guint8 special_tagtype)
{
const gchar *tag_name;
tag_name = match_strval(special_tagtype, edonkey_special_tags);
if (tag_name == NULL) {
return proto_tree_add_item(tree, hf_edonkey_metatag_name, tvb, start, length, ENC_ASCII|ENC_NA);
}
else {
return proto_tree_add_uint_format(tree, hf_edonkey_metatag_id, tvb, start, length,
special_tagtype, "Meta Tag Name: %s (0x%02x)",
tag_name, special_tagtype);
}
}
static int dissect_kademlia_search_condition_argument_uint64(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf_kademlia_search_condition_argument_uint64, tvb, offset, 8, ENC_LITTLE_ENDIAN );
return offset + 8;
}
static int dissect_kademlia_search_condition_argument_uint32(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf_kademlia_search_condition_argument_uint32, tvb, offset, 4, ENC_LITTLE_ENDIAN );
return offset + 4;
}
static int dissect_kademlia_search_condition(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree )
{
proto_item * ti;
guint16 value = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item( tree, hf_kademlia_search_condition, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_item_append_text(ti, " [%s]", val_to_str( value, kademlia_search_conds, "Unknown") );
return offset + 1;
}
static int dissect_edonkey_metatag(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *metatag_tree;
guint8 real_tag_type, tag_type, special_tagtype, trans_tagtype, tag_value_guint8;
guint16 tag_name_size, string_length, array_length, tag_value_guint16;
guint32 tag_length, blob_length, tag_value_guint32;
int tag_offset;
real_tag_type = tag_type = tvb_get_guint8(tvb, offset);
if (tag_type & EDONKEY_MTAG_SHORTNAME) {
real_tag_type &= ~EDONKEY_MTAG_SHORTNAME;
tag_name_size = 1;
special_tagtype = tvb_get_guint8(tvb, offset+1);
tag_length = 2;
} else {
tag_name_size = tvb_get_letohs(tvb, offset+1);
special_tagtype = tvb_get_guint8(tvb, offset+3);
tag_length = 3 + tag_name_size;
}
tag_offset = offset + tag_length;
switch (real_tag_type)
{
case EDONKEY_MTAG_HASH:
tag_length += 16;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_item(metatag_tree, hf_edonkey_hash, tvb, tag_offset, 16, ENC_NA);
break;
case EDONKEY_MTAG_STRING:
string_length = tvb_get_letohs(tvb, tag_offset);
tag_length += 2+string_length;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_uint(metatag_tree, hf_edonkey_string_length, tvb, tag_offset, 2, string_length);
proto_tree_add_item(metatag_tree, hf_edonkey_string, tvb, tag_offset+2, string_length, ENC_ASCII|ENC_NA);
break;
case EDONKEY_MTAG_DWORD:
tag_length += 4;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
trans_tagtype = edonkey_metatag_name_get_type(tvb, offset+3, tag_name_size, special_tagtype);
if (trans_tagtype == EDONKEY_STAG_IP) {
proto_tree_add_item(metatag_tree, hf_edonkey_ip, tvb, tag_offset, 4, ENC_BIG_ENDIAN);
}
else if (trans_tagtype == EMULE_STAG_SERVER_VERSION) {
guint16 maj, min;
min = tvb_get_letohs(tvb, tag_offset);
maj = tvb_get_letohs(tvb, tag_offset+2);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 4, "Meta Tag Value: %u.%u", maj, min);
}
else {
tag_value_guint32 = tvb_get_letohl(tvb, tag_offset);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 4, "Meta Tag Value: %u", tag_value_guint32);
}
break;
case EDONKEY_MTAG_FLOAT:
tag_length += 4;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
break;
case EDONKEY_MTAG_WORD:
tag_length += 2;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
{
tag_value_guint16 = tvb_get_letohs(tvb, tag_offset);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 2, "Meta Tag Value: %u", tag_value_guint16);
}
break;
case EDONKEY_MTAG_BYTE:
tag_length += 1;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
{
tag_value_guint8 = tvb_get_guint8(tvb, tag_offset);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 1, "Meta Tag Value: %u", tag_value_guint8);
}
break;
case EDONKEY_MTAG_BOOL:
tag_length += 1;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
{
tag_value_guint8 = tvb_get_guint8(tvb, tag_offset);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 1, "Meta Tag Value: %u", tag_value_guint8);
}
break;
case EDONKEY_MTAG_BOOL_ARRAY:
array_length = tvb_get_letohs(tvb, tag_offset);
tag_length += 2+(array_length/8)+1;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 2, "Boolean Array Length: %u", array_length);
break;
case EDONKEY_MTAG_BLOB:
blob_length = tvb_get_letohl(tvb, tag_offset);
tag_length += 4+blob_length;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_text(metatag_tree, tvb, tag_offset, 2, "BLOB Length: %u", blob_length);
break;
case EDONKEY_MTAG_BSOB:
case EDONKEY_MTAG_UNKNOWN:
default:
if (real_tag_type>=EDONKEY_MTAG_STR1 && real_tag_type<=EDONKEY_MTAG_STR16) {
string_length = real_tag_type-EDONKEY_MTAG_STR1+1;
tag_length += string_length;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (real_tag_type==tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_item(metatag_tree, hf_edonkey_string, tvb, tag_offset, string_length, ENC_ASCII|ENC_NA);
} else {
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_text(metatag_tree, tvb, offset, 1, "Unknown Meta Tag Type (0x%02x)", tag_type);
if (real_tag_type==tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
}
break;
}
return offset + tag_length;
}
static int dissect_edonkey_address(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_edonkey_port, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
return offset+6;
}
static int dissect_kademlia_udp_port(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_kademlia_udp_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return offset +2;
}
static int dissect_kademlia_tcp_port(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_kademlia_tcp_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return offset +2;
}
static int dissect_kademlia_ip_address(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_kademlia_ip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return offset + 4;
}
static int dissect_kademlia_address(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_ip_address( tvb, pinfo, offset, tree );
offset = dissect_kademlia_udp_port( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tcp_port( tvb, pinfo, offset, tree );
return offset;
}
static int dissect_kademlia_tagname(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree, const gchar** outputTagName, const gchar** outputExtendedTagName)
{
const gchar * tagname;
const gchar * tag_full_name = NULL;
guint8 tagname_value;
proto_item *ti, *hidden_item;
guint16 string_length = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_kademlia_tag_name_length, tvb, offset, 2, string_length);
hidden_item = proto_tree_add_uint(tree, hf_edonkey_string_length, tvb, offset, 2, string_length);
PROTO_ITEM_SET_HIDDEN(hidden_item);
tagname = tvb_get_ephemeral_string( tvb, offset + 2, string_length );
tag_full_name = "UnknownTagName";
if ( tagname && string_length == 1 ) {
tagname_value = *(guint8*)tagname;
tag_full_name = val_to_str( tagname_value, kademlia_tags, tag_full_name );
}
ti = proto_tree_add_item(tree, hf_kademlia_tag_name, tvb, offset+2, string_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " [%s]", tag_full_name);
if (outputTagName)
*outputTagName = tagname;
if (outputExtendedTagName)
*outputExtendedTagName = tag_full_name;
return offset+2+string_length;
}
static int dissect_kademlia_string(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
const gchar * string_value;
guint16 string_length;
string_length = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_edonkey_string_length, tvb, offset, 2, string_length);
string_value = tvb_get_ephemeral_string( tvb, offset + 2, string_length );
proto_tree_add_text(tree, tvb, offset+2, string_length, "String: %s", string_value);
return offset+2+string_length;
}
static int dissect_edonkey_address_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Address", dissect_edonkey_address);
}
static int dissect_edonkey_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_hash, tvb, offset, 16, ENC_NA);
return offset+16;
}
static int dissect_edonkey_file_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_file_hash, tvb, offset, 16, ENC_NA);
return offset+16;
}
static int dissect_edonkey_public_key(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint8 length = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Public key length: %u", length);
offset++;
proto_tree_add_item(tree, hf_emule_public_key, tvb, offset, length, ENC_NA);
return offset + length;
}
static int dissect_edonkey_signature(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint8 length = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Signature length: %u", length);
offset++;
proto_tree_add_item(tree, hf_emule_signature, tvb, offset, length, ENC_NA);
return offset + length;
}
static const char *kademlia_hash(tvbuff_t *tvb, int offset) {
guint32 hash[4];
int i;
for (i = 0; i < 4; i++)
hash[i] = tvb_get_letohl(tvb, offset + i*4);
return ep_strdup_printf("%08X%08X%08X%08X", hash[0], hash[1], hash[2], hash[3]);
}
static int dissect_kademlia_hash_hidden(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree) {
proto_item *hidden_item;
const char *hash;
hash = kademlia_hash(tvb, offset);
hidden_item = proto_tree_add_string_format_value(tree, hf_kademlia_hash, tvb, offset, 16, hash, "%s", hash);
PROTO_ITEM_SET_HIDDEN(hidden_item);
return offset+16;
}
static int dissect_kademlia_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree, int *value_ptr) {
const char *hash;
hash = kademlia_hash(tvb, offset);
proto_tree_add_string_format_value(tree, *value_ptr, tvb, offset, 16, hash, "%s", hash);
return dissect_kademlia_hash_hidden(tvb, pinfo, offset, tree);
}
static int dissect_kademlia_tag_hash_hidden(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree) {
proto_item *hidden_item;
const char *hash;
hash = kademlia_hash(tvb, offset);
hidden_item = proto_tree_add_string_format_value(tree, hf_kademlia_tag_hash, tvb, offset, 16, hash, "%s", hash);
PROTO_ITEM_SET_HIDDEN(hidden_item);
return offset+16;
}
static int dissect_kademlia_tag_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree) {
const char *hash;
hash = kademlia_hash(tvb, offset);
proto_tree_add_string_format_value(tree, hf_kademlia_hash, tvb, offset, 16, hash, "%s", hash);
return dissect_kademlia_tag_hash_hidden( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_tag_bsob(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree, const gchar** string_value )
{
guint16 bsob_length;
bsob_length = tvb_get_guint8(tvb, offset);
*string_value = tvb_bytes_to_str( tvb, offset + 1, bsob_length );
proto_tree_add_item(tree, hf_kademlia_tag_bsob, tvb, offset + 1, bsob_length, ENC_NA);
return offset + 1 + bsob_length;
}
static int dissect_kademlia_tag_string(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree, const gchar** string_value)
{
proto_item *hidden_item;
guint16 string_length = tvb_get_letohs(tvb, offset);
hidden_item = proto_tree_add_uint(tree, hf_edonkey_string_length, tvb, offset, 2, string_length);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_item(tree, hf_edonkey_string, tvb, offset+2, string_length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
*string_value = tvb_get_ephemeral_string(tvb, offset + 2, string_length);
proto_tree_add_item(tree, hf_kademlia_tag_string, tvb, offset + 2, string_length, ENC_ASCII|ENC_NA);
return offset + 2 + string_length;
}
static int dissect_edonkey_hash_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Hash", dissect_edonkey_hash);
}
static int dissect_edonkey_metatag_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 4, "Meta Tag", dissect_edonkey_metatag);
}
static int dissect_edonkey_string(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint16 string_length = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_edonkey_string_length, tvb, offset, 2, string_length);
proto_tree_add_item(tree, hf_edonkey_string, tvb, offset+2, string_length, ENC_ASCII|ENC_NA);
return offset+2+string_length;
}
static int dissect_edonkey_directory(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint16 string_length = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_edonkey_string_length, tvb, offset, 2, string_length);
proto_tree_add_item(tree, hf_edonkey_directory, tvb, offset+2, string_length, ENC_ASCII|ENC_NA);
return offset+2+string_length;
}
static int dissect_edonkey_file_name(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_string(tvb, pinfo, offset, tree);
}
static int dissect_edonkey_file_status(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint16 partcount, arrlen;
partcount = tvb_get_letohs(tvb, offset);
arrlen = (partcount+7)/8;
proto_tree_add_uint(tree, hf_edonkey_part_count, tvb, offset, 2, partcount);
if (partcount>0) {
proto_tree_add_item(tree, hf_edonkey_file_status, tvb, offset+2, arrlen, ENC_NA);
}
return offset+2+arrlen;
}
static int dissect_edonkey_directory_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 4, "Directory", dissect_edonkey_directory);
}
static int dissect_edonkey_server_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_server_hash, tvb, offset, 16, ENC_NA);
return offset+16;
}
static int dissect_edonkey_client_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_client_hash, tvb, offset, 16, ENC_NA);
return offset+16;
}
static int dissect_emule_sourceOBFU(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *sourceOBFU_tree;
guint8 settings = tvb_get_guint8(tvb, offset+6);
ti = proto_tree_add_item(tree, hf_emule_sourceOBFU, tvb, offset, 7 + ((settings & 0x80) ? 16 : 0), ENC_NA);
sourceOBFU_tree = proto_item_add_subtree(ti, ett_emule_sourceOBFU);
proto_tree_add_item(sourceOBFU_tree, hf_edonkey_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sourceOBFU_tree, hf_edonkey_port, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_text(sourceOBFU_tree, tvb, offset+6, 1, "Obfuscation Settings: %u", settings);
offset += 7;
if (settings & 0x80)
offset = dissect_edonkey_client_hash(tvb, pinfo, offset, sourceOBFU_tree);
return offset;
}
static int dissect_emule_sourceOBFU_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Sources Obfuscation", dissect_emule_sourceOBFU);
}
static int dissect_edonkey_client_id(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree, gboolean fileinfo)
{
proto_item *ti;
ti = proto_tree_add_item(tree, hf_edonkey_client_id, tvb, offset, 4, ENC_BIG_ENDIAN);
if (fileinfo) {
guint32 ip = tvb_get_letohl(tvb, offset);
guint16 port = tvb_get_letohs(tvb, offset+4);
if (ip==0xfcfcfcfc && port==0xfcfc) {
proto_item_append_text(ti, " (myself, incomplete file)");
} else if (ip==0xfbfbfbfb && port==0xfbfb) {
proto_item_append_text(ti, " (myself, complete file)");
}
}
return offset+4;
}
static int dissect_edonkey_port(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return offset+2;
}
static int dissect_edonkey_start_offset(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint32 start = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Start Offset: %u", start);
return offset+4;
}
static int dissect_edonkey_start_offset_64(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint64 start = tvb_get_letoh64(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "Start Offset: %" G_GINT64_MODIFIER "u", start);
return offset+8;
}
static int dissect_edonkey_end_offset(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint32 end = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "End Offset: %u", end);
return offset+4;
}
static int dissect_edonkey_end_offset_64(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint64 end = tvb_get_letoh64(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "End Offset: %" G_GINT64_MODIFIER "u", end);
return offset+8;
}
static int dissect_edonkey_client_info(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *clientinfo_tree;
ti = proto_tree_add_item(tree, hf_edonkey_clientinfo, tvb, offset, 0, ENC_NA);
clientinfo_tree = proto_item_add_subtree(ti, ett_edonkey_clientinfo);
offset = dissect_edonkey_client_hash(tvb, pinfo, offset, clientinfo_tree);
offset = dissect_edonkey_client_id(tvb, pinfo, offset, clientinfo_tree, FALSE);
offset = dissect_edonkey_port(tvb, pinfo, offset, clientinfo_tree);
offset = dissect_edonkey_metatag_list(tvb, pinfo, offset, clientinfo_tree);
return offset;
}
static int dissect_edonkey_client_info_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 4, "Client Info", dissect_edonkey_client_info);
}
static int dissect_edonkey_server_info(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *serverinfo_tree;
ti = proto_tree_add_item(tree, hf_edonkey_serverinfo, tvb, offset, 0, ENC_NA);
serverinfo_tree = proto_item_add_subtree(ti, ett_edonkey_serverinfo);
offset = dissect_edonkey_server_hash(tvb, pinfo, offset, serverinfo_tree);
offset = dissect_edonkey_address(tvb, pinfo, offset, serverinfo_tree);
offset = dissect_edonkey_metatag_list(tvb, pinfo, offset, serverinfo_tree);
return offset;
}
static int dissect_edonkey_file_info(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *fileinfo_tree;
int startoff;
ti = proto_tree_add_item(tree, hf_edonkey_fileinfo, tvb, offset, 0, ENC_NA);
startoff = offset;
fileinfo_tree = proto_item_add_subtree(ti, ett_edonkey_fileinfo);
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, fileinfo_tree);
offset = dissect_edonkey_client_id(tvb, pinfo, offset, fileinfo_tree, TRUE);
offset = dissect_edonkey_port(tvb, pinfo, offset, fileinfo_tree);
offset = dissect_edonkey_metatag_list(tvb, pinfo, offset, fileinfo_tree);
proto_item_set_len(ti, offset-startoff);
return offset;
}
static int dissect_edonkey_file_info_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 4, "File Info", dissect_edonkey_file_info);
}
static int dissect_emule_address_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Address", dissect_edonkey_address);
}
static int dissect_emule_aich_root_hash(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_emule_aich_root_hash, tvb, offset, 20, ENC_NA);
return offset + 20;
}
static int dissect_emule_aich_hash_list_entry(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint16 hashid;
proto_item *ti;
proto_tree *aichhash_tree;
ti = proto_tree_add_item(tree, hf_emule_aich_hash_entry, tvb, offset, 22, ENC_NA);
aichhash_tree = proto_item_add_subtree(ti, ett_emule_aichhash);
hashid = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(aichhash_tree, hf_emule_aich_hash_id, tvb, offset, 2, hashid);
proto_tree_add_item(aichhash_tree, hf_emule_aich_hash, tvb, offset+2, 20, ENC_NA);
return offset + 22;
}
static int dissect_emule_aich_hash_list(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "AICH Hash", dissect_emule_aich_hash_list_entry);
}
static int dissect_emule_multipacket(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int eoffset, proto_tree *tree, int isext)
{
guint8 opcode, nextop;
guint16 namelen, partcount, arrlen, oplen;
guint32 sourcecount;
proto_item *ti;
proto_tree *mp_tree;
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
if (isext) {
guint64 filelen = tvb_get_letoh64(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "File Length: %" G_GINT64_MODIFIER "u", filelen);
offset += 8;
}
while (offset<eoffset) {
opcode = tvb_get_guint8(tvb, offset);
switch (opcode) {
case EDONKEY_MSG_FILE_STATUS_REQUEST:
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, 1, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "File Status Request (0x%02x)", opcode);
offset += 1;
break;
case EDONKEY_MSG_FILE_REQUEST:
partcount = 443;
sourcecount = 65536;
arrlen = 0;
oplen = 1;
if (offset+2<eoffset) {
nextop = tvb_get_guint8(tvb, offset+1);
if (nextop!=EDONKEY_MSG_FILE_STATUS_REQUEST &&
nextop!=EMULE_MSG_SOURCES_REQUEST &&
nextop!=EMULE_MSG_AICHFILEHASH_REQUEST) {
partcount = tvb_get_letohs(tvb, offset+1);
if (partcount<=442) {
arrlen = (partcount+7)/8;
oplen += 2+arrlen;
if (offset+2+arrlen+2<eoffset) {
nextop = tvb_get_guint8(tvb, offset+2+arrlen+1);
if (nextop!=EDONKEY_MSG_FILE_STATUS_REQUEST &&
nextop!=EMULE_MSG_SOURCES_REQUEST &&
nextop!=EMULE_MSG_AICHFILEHASH_REQUEST) {
sourcecount = tvb_get_letohs(tvb, offset+2+arrlen+1);
oplen += 2;
}
}
}
}
}
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, oplen, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "File Name Request (0x%02x)", opcode);
if (partcount<=442) {
dissect_edonkey_file_status(tvb, pinfo, offset+1, mp_tree);
if (sourcecount<65536) {
proto_tree_add_uint(mp_tree, hf_emule_source_count, tvb, offset+3+arrlen, 2, sourcecount);
}
}
offset += oplen;
break;
case EMULE_MSG_SOURCES_REQUEST:
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, 1, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "Sources Request (0x%02x)", opcode);
offset += 1;
break;
case EMULE_MSG_AICHFILEHASH_REQUEST:
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, 1, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "AICH Root Hash Request (0x%02x)", opcode);
offset += 1;
break;
case EDONKEY_MSG_FILE_STATUS:
partcount = tvb_get_letohs(tvb, offset+1);
arrlen = (partcount+7)/8;
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, 3+arrlen, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "File Status (0x%02x)", opcode);
offset = dissect_edonkey_file_status(tvb, pinfo, offset+1, mp_tree);
break;
case EDONKEY_MSG_FILE_REQUEST_ANSWER:
namelen = tvb_get_letohs(tvb, offset+1);
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, 3+namelen, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "File Name (0x%02x)", opcode);
offset = dissect_edonkey_file_name(tvb, pinfo, offset+1, mp_tree);
break;
case EMULE_MSG_AICHFILEHASH_ANSWER:
ti = proto_tree_add_item(tree, hf_emule_multipacket_entry, tvb, offset, 21, ENC_NA);
mp_tree = proto_item_add_subtree(ti, ett_emule_multipacket);
proto_tree_add_uint_format(mp_tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "AICH Root Hash (0x%02x)", opcode);
proto_tree_add_item(mp_tree, hf_emule_aich_root_hash, tvb, offset+1, 20, ENC_NA);
offset += 21;
break;
default:
proto_tree_add_uint_format(tree, hf_emule_multipacket_opcode, tvb, offset, 1,
opcode, "Unknown MultiPacket opcode (0x%02x)", opcode);
return offset+1;
}
}
return offset;
}
static int dissect_overnet_peertype(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint8 peertype = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Peer Type: %u", peertype);
return offset+1;
}
static int dissect_overnet_peer(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *peer_tree;
ti = proto_tree_add_item(tree, hf_overnet_peer, tvb, offset, 16 + 6 + 1, ENC_NA);
peer_tree = proto_item_add_subtree(ti, ett_overnet_peer);
offset = dissect_edonkey_hash(tvb, pinfo, offset, peer_tree);
offset = dissect_edonkey_address(tvb, pinfo, offset, peer_tree);
offset = dissect_overnet_peertype(tvb, pinfo, offset, peer_tree);
return offset;
}
static int dissect_kademlia_peertype(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf_kademlia_peertype, tvb, offset, 1, ENC_BIG_ENDIAN );
return offset + 1;
}
static int dissect_kademlia_peer(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *peer_tree;
int kad_version;
ti = proto_tree_add_item(tree, hf_kademlia_peer, tvb, offset, 16 + 4 + 4 + 1, ENC_NA);
peer_tree = proto_item_add_subtree(ti, ett_overnet_peer);
offset = dissect_kademlia_hash(tvb, pinfo, offset, peer_tree, &hf_kademlia_peer_id);
offset = dissect_kademlia_address(tvb, pinfo, offset, peer_tree);
kad_version = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(peer_tree, hf_kademlia_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s", val_to_str(kad_version, kademlia_versions, " Unknown"));
return offset + 1;
}
static int dissect_kademlia2_peer(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *peer_tree;
ti = proto_tree_add_item(tree, hf_kademlia_peer, tvb, offset, 16 + 4 + 4 + 1, ENC_NA);
peer_tree = proto_item_add_subtree(ti, ett_overnet_peer);
offset = dissect_kademlia_hash(tvb, pinfo, offset, peer_tree, &hf_kademlia_peer_id);
offset = dissect_kademlia_address(tvb, pinfo, offset, peer_tree);
offset = dissect_kademlia_peertype(tvb, pinfo, offset, peer_tree);
return offset;
}
static int dissect_edonkey_search_query(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *search_tree;
guint8 search_type, operator, special_tagtype, limit_type;
guint16 tag_name_size, string_length;
guint32 search_length, limit;
int string_offset, tag_name_offset;
search_type = tvb_get_guint8(tvb, offset);
search_length = 1;
switch (search_type)
{
case EDONKEY_SEARCH_BOOL:
search_length += 1;
operator = tvb_get_guint8(tvb, offset+1);
ti = proto_tree_add_item(tree, hf_edonkey_search, tvb, offset, search_length, ENC_NA);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_text(search_tree, tvb, offset, 2, "Boolean search (0x%02x): %s (0x%02x)",
search_type, val_to_str(operator, edonkey_search_ops, "Unknown"), operator);
offset+=2;
offset = dissect_edonkey_search_query(tvb, pinfo, offset, search_tree);
offset = dissect_edonkey_search_query(tvb, pinfo, offset, search_tree);
break;
case EDONKEY_SEARCH_NAME:
string_offset = offset + search_length;
string_length = tvb_get_letohs(tvb, string_offset);
search_length += 2+string_length;
ti = proto_tree_add_item(tree, hf_edonkey_search, tvb, offset, search_length, ENC_NA);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_text(search_tree, tvb, offset, 1, "Search by name (0x%02x)", search_type);
proto_tree_add_uint(search_tree, hf_edonkey_string_length, tvb, string_offset, 2, string_length);
proto_tree_add_item(search_tree, hf_edonkey_string, tvb, string_offset+2, string_length, ENC_ASCII|ENC_NA);
offset += search_length;
break;
case EDONKEY_SEARCH_META:
string_offset = offset + search_length;
string_length = tvb_get_letohs(tvb, offset+1);
search_length += 2+string_length;
tag_name_offset = offset + search_length;
tag_name_size = tvb_get_letohs(tvb, tag_name_offset);
special_tagtype = tvb_get_guint8(tvb, tag_name_offset+2);
search_length += 2 + tag_name_size;
ti = proto_tree_add_item(tree, hf_edonkey_search, tvb, offset, search_length, ENC_NA);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_text(search_tree, tvb, offset, 1, "Search by metadata (0x%02x)", search_type);
proto_tree_add_uint(search_tree, hf_edonkey_string_length, tvb, string_offset, 2, string_length);
proto_tree_add_item(search_tree, hf_edonkey_string, tvb, string_offset+2, string_length, ENC_ASCII|ENC_NA);
proto_tree_add_uint(search_tree, hf_edonkey_metatag_namesize, tvb, tag_name_offset, 2, tag_name_size);
edonkey_tree_add_metatag_name(search_tree, tvb, tag_name_offset+2, tag_name_size, special_tagtype);
offset += search_length;
break;
case EDONKEY_SEARCH_LIMIT:
search_length += 5;
limit = tvb_get_letohl(tvb, offset+1);
limit_type = tvb_get_guint8(tvb, offset+5);
tag_name_offset = offset + search_length;
tag_name_size = tvb_get_letohs(tvb, tag_name_offset);
special_tagtype = tvb_get_guint8(tvb, tag_name_offset+2);
search_length += 2 + tag_name_size;
ti = proto_tree_add_item(tree, hf_edonkey_search, tvb, offset, search_length, ENC_NA);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_text(search_tree, tvb, offset, 6, "Search by limit (0x%02x): %s %u",
search_type, val_to_str(limit_type, edonkey_search_conds, "Unknown"), limit);
proto_tree_add_uint(search_tree, hf_edonkey_metatag_namesize, tvb, tag_name_offset, 2, tag_name_size);
edonkey_tree_add_metatag_name(search_tree, tvb, tag_name_offset+2, tag_name_size, special_tagtype);
offset += search_length;
break;
default:
ti = proto_tree_add_item(tree, hf_edonkey_search, tvb, offset, search_length, ENC_NA);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_text(search_tree, tvb, offset, search_length, "Unknown Search (0x%02x)", search_type);
offset += search_length;
break;
}
return offset;
}
static void dissect_edonkey_tcp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint8 helloClient, more;
guint32 nusers, nfiles;
if (tree == NULL) return;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return;
msg_end = offset + length;
switch (msg_type) {
case EDONKEY_MSG_HELLO:
helloClient = (tvb_get_guint8(tvb, offset) == 0x10 && tvb_get_guint8(tvb, offset + 6) == 0x0E && tvb_get_guint8(tvb, offset + 15) == 0x6F);
if (helloClient) {
proto_tree_add_text(tree, tvb, offset, 1, "User hash length: 16");
offset += 1;
}
offset = dissect_edonkey_client_info(tvb, pinfo, offset, tree);
if (helloClient)
offset = dissect_edonkey_address(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_HELLO_ANSWER:
offset = dissect_edonkey_client_info(tvb, pinfo, offset, tree);
offset = dissect_edonkey_address(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SERVER_CB_REQ:
offset = dissect_edonkey_address(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SERVER_INFO_DATA:
offset = dissect_edonkey_server_info(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SERVER_LIST:
offset = dissect_edonkey_address_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_OFFER_FILES:
case EDONKEY_MSG_VIEW_FILES_ANSWER:
offset = dissect_edonkey_file_info_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SEARCH_FILE_RESULTS:
offset = dissect_edonkey_file_info_list(tvb, pinfo, offset, tree);
more = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "More: %s (0x%02x)", (more) ? "TRUE" : "FALSE", more);
break;
case EDONKEY_MSG_SEARCH_FILES:
case EDONKEY_MSG_SEARCH_USER:
offset = dissect_edonkey_search_query(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_GET_SOURCES:
case EDONKEY_MSG_GET_SOURCES_OBFU:
{
guint32 fileSize;
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
fileSize = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "File size: %u %s", fileSize, (fileSize == 0) ? "(64bit file size used)" : "");
offset += 4;
if (fileSize == 0) {
guint64 fileSize64 = tvb_get_letoh64(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "Large file size : %" G_GINT64_MODIFIER "u", fileSize64);
}
}
break;
case EDONKEY_MSG_NO_SUCH_FILE:
case EDONKEY_MSG_END_OF_DOWNLOAD:
case EDONKEY_MSG_FILE_STATUS_REQUEST:
case EDONKEY_MSG_HASHSET_REQUEST:
case EDONKEY_MSG_SLOT_REQUEST:
case EDONKEY_MSG_FILE_REQUEST:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_FOUND_SOURCES_OBFU:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_emule_sourceOBFU_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_FOUND_SOURCES:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_address_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_CLIENT_CB_REQ:
case EDONKEY_MSG_CALLBACK_FAIL:
case EDONKEY_MSG_ID_CHANGE:
offset = dissect_edonkey_client_id(tvb, pinfo, offset, tree, FALSE);
break;
case EDONKEY_MSG_NEW_CLIENT_ID:
offset = dissect_edonkey_client_id(tvb, pinfo, offset, tree, FALSE);
offset = dissect_edonkey_client_id(tvb, pinfo, offset, tree, FALSE);
break;
case EDONKEY_MSG_SERVER_MESSAGE:
case EDONKEY_MSG_CLIENT_MESSAGE:
offset = dissect_edonkey_string(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SERVER_STATUS:
nusers = tvb_get_letohl(tvb, offset);
nfiles = tvb_get_letohl(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset, 4, "Number of Users: %u", nusers);
proto_tree_add_text(tree, tvb, offset+4, 4, "Number of Files: %u", nfiles);
break;
case EDONKEY_MSG_FILE_STATUS:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_file_status(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_FILE_REQUEST_ANSWER:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_file_name(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_REQUEST_PARTS:
{
int pairs, count;
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
pairs = (msg_end - offset) / 8;
for (count=0; count < pairs; count++)
{
offset = dissect_edonkey_start_offset(tvb, pinfo, offset, tree);
}
for (count=0; count < pairs; count++)
{
offset = dissect_edonkey_end_offset(tvb, pinfo, offset, tree);
}
}
break;
case EDONKEY_MSG_SENDING_PART:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset(tvb, pinfo, offset, tree);
offset = dissect_edonkey_end_offset(tvb, pinfo, offset, tree);
if (msg_end > offset) {
bytes_remaining = msg_end - offset;
proto_tree_add_text(tree, tvb, offset, bytes_remaining, "Message Data (%d bytes)", bytes_remaining);
}
break;
case EDONKEY_MSG_SEARCH_USER_RESULTS:
offset = dissect_edonkey_client_info_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_GET_SHARED_FILES:
offset = dissect_edonkey_directory(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SHARED_DIRS:
offset = dissect_edonkey_directory_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_SHARED_FILES:
offset = dissect_edonkey_directory(tvb, pinfo, offset, tree);
offset = dissect_edonkey_file_info_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_HASHSET_ANSWER:
offset = dissect_edonkey_hash_list(tvb, pinfo, offset, tree);
break;
default:
proto_tree_add_text(tree, tvb, offset, length, "Message Data (%d bytes)", length);
break;
}
if (offset < msg_end) {
int extra_bytes = msg_end - offset;
proto_tree_add_uint_format(tree, hf_edonkey_unparsed_data_length, tvb, offset, extra_bytes, extra_bytes,
"Trailing/Undecoded data: %d bytes", extra_bytes );
}
return;
}
static void dissect_emule_tcp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint32 packed_length;
guint16 version, rank, partnum;
if (tree == NULL) return;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return;
msg_end = offset + length;
switch (msg_type) {
case EMULE_MSG_HELLO:
case EMULE_MSG_HELLO_ANSWER:
version = tvb_get_letohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Version: %u", version);
dissect_edonkey_metatag_list(tvb, pinfo, offset+2, tree);
break;
case EMULE_MSG_QUEUE_RANKING:
rank = tvb_get_letohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Queue Ranking: %u", rank);
break;
case EMULE_MSG_SOURCES_REQUEST:
dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SOURCES_ANSWER:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
dissect_emule_address_list(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SEC_IDENT_STATE: {
guint32 rndchallenge;
guint8 state = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "State: %u (%s needed)", state, (state == 0) ? "nothing is" : (state == 1) ? "signature is" : "public key and signature are");
offset++;
rndchallenge = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Rndchallenge: %u", rndchallenge);
break;
}
case EMULE_MSG_PUBLIC_KEY:
dissect_edonkey_public_key(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SIGNATURE:
offset = dissect_edonkey_signature(tvb, pinfo, offset, tree);
if (msg_end != offset) {
guint8 sigIPused = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Sig IP Used: %u", sigIPused);
}
break;
case EMULE_MSG_DATA_COMPRESSED:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset(tvb, pinfo, offset, tree);
packed_length = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Packed Length: %u", packed_length);
offset += 4;
if (msg_end > offset) {
bytes_remaining = msg_end - offset;
proto_tree_add_text(tree, tvb, offset, bytes_remaining,
"Compressed Message Data (%d bytes)", bytes_remaining);
}
break;
case EMULE_MSG_DATA_COMPRESSED_64:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset_64(tvb, pinfo, offset, tree);
packed_length = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Packed Length: %u", packed_length);
offset += 4;
if (msg_end > offset) {
bytes_remaining = msg_end - offset;
proto_tree_add_text(tree, tvb, offset, bytes_remaining,
"Compressed Message Data (%d bytes)", bytes_remaining);
}
break;
case EMULE_MSG_REQUEST_PARTS_64:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset_64(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset_64(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset_64(tvb, pinfo, offset, tree);
offset = dissect_edonkey_end_offset_64(tvb, pinfo, offset, tree);
offset = dissect_edonkey_end_offset_64(tvb, pinfo, offset, tree);
dissect_edonkey_end_offset_64(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SENDING_PART_64:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset_64(tvb, pinfo, offset, tree);
offset = dissect_edonkey_end_offset_64(tvb, pinfo, offset, tree);
if (msg_end > offset) {
bytes_remaining = msg_end - offset;
proto_tree_add_text(tree, tvb, offset, bytes_remaining, "Message Data (%d bytes)", bytes_remaining);
}
break;
case EMULE_MSG_CALLBACK:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_AICH_REQUEST:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
partnum = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_emule_aich_partnum, tvb, offset, 2, partnum);
offset += 2;
dissect_emule_aich_root_hash(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_AICH_ANSWER:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
partnum = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_emule_aich_partnum, tvb, offset, 2, partnum);
offset += 2;
offset = dissect_emule_aich_root_hash(tvb, pinfo, offset, tree);
dissect_emule_aich_hash_list(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_MULTIPACKET:
case EMULE_MSG_MULTIPACKET_ANSWER:
case EMULE_MSG_MULTIPACKET_EXT:
dissect_emule_multipacket(tvb, pinfo, offset, offset+length, tree, msg_type==EMULE_MSG_MULTIPACKET_EXT);
break;
default:
dissect_edonkey_tcp_message(msg_type, tvb, pinfo, offset, length, tree);
break;
}
return;
}
static int dissect_edonkey_udp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint8 type;
guint16 min, max;
guint16 ischal;
guint32 chal;
guint32 nusers, nfiles;
if (tree == NULL) return offset;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return offset;
msg_end = offset + length;
switch (msg_type) {
case EDONKEY_MSG_UDP_CALLBACK_REQUEST:
offset = dissect_edonkey_address(tvb, pinfo, offset, tree);
offset = dissect_edonkey_client_id(tvb, pinfo, offset, tree, FALSE);
break;
case EDONKEY_MSG_UDP_CALLBACK_FAIL:
offset = dissect_edonkey_client_id(tvb, pinfo, offset, tree, FALSE);
break;
case EDONKEY_MSG_UDP_GET_SERVER_INFO:
if (length>=2) {
ischal = tvb_get_letohs(tvb, offset);
if (ischal==0xf0ff) {
chal = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Challenge: 0x%08x", chal);
offset += 4;
} else {
offset = dissect_edonkey_string(tvb, pinfo, offset, tree);
}
}
break;
case EDONKEY_MSG_UDP_SERVER_INFO:
ischal = tvb_get_letohs(tvb, offset);
if (ischal==0xf0ff) {
chal = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Challenge: 0x%08x", chal);
offset = dissect_edonkey_metatag_list(tvb, pinfo, offset+4, tree);
} else {
offset = dissect_edonkey_string(tvb, pinfo, offset, tree);
offset = dissect_edonkey_string(tvb, pinfo, offset, tree);
}
break;
case EDONKEY_MSG_UDP_SERVER_LIST:
offset = dissect_edonkey_address_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_UDP_SEARCH_FILE_RESULTS:
offset = dissect_edonkey_file_info(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_UDP_SEARCH_FILE:
offset = dissect_edonkey_search_query(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_UDP_GET_SOURCES:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_UDP_FOUND_SOURCES:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_address_list(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_UDP_SERVER_STATUS_REQUEST:
chal = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Challenge: 0x%08x", chal);
offset += 4;
break;
case EDONKEY_MSG_UDP_SERVER_STATUS:
chal = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Challenge: 0x%08x", chal);
offset += 4;
nusers = tvb_get_letohl(tvb, offset);
nfiles = tvb_get_letohl(tvb, offset+4);
proto_tree_add_text(tree, tvb, offset, 4, "Number of Users: %u", nusers);
proto_tree_add_text(tree, tvb, offset+4, 4, "Number of Files: %u", nfiles);
offset += 8;
if (offset < msg_end) {
nusers = tvb_get_letohl(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "Max number of Users: %u", nusers);
offset += 4;
}
break;
case OVERNET_MSG_UDP_CONNECT:
case OVERNET_MSG_UDP_PUBLICIZE:
offset = dissect_overnet_peer(tvb, pinfo, offset, tree);
break;
case OVERNET_MSG_UDP_CONNECT_REPLY:
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Overnet Peer", dissect_overnet_peer);
break;
case OVERNET_MSG_UDP_SEARCH:
type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Search Type: %u", type);
offset = dissect_edonkey_hash(tvb, pinfo, offset+1, tree);
break;
case OVERNET_MSG_UDP_SEARCH_INFO:
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
type = tvb_get_guint8(tvb, offset);
min = tvb_get_letohs(tvb, offset+1);
max = tvb_get_letohs(tvb, offset+3);
proto_tree_add_text(tree, tvb, offset, 1, "Search Type: %u", type);
proto_tree_add_text(tree, tvb, offset+1, 4, "Search Range: Min=%u Max=%u", min, max);
break;
case OVERNET_MSG_UDP_SEARCH_NEXT:
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Overnet Peer", dissect_overnet_peer);
break;
case OVERNET_MSG_UDP_SEARCH_RESULT:
case OVERNET_MSG_UDP_PUBLISH:
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_metatag_list(tvb, pinfo, offset, tree);
break;
case OVERNET_MSG_UDP_SEARCH_END:
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
break;
case OVERNET_MSG_UDP_PUBLISH_ACK:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
break;
case OVERNET_MSG_UDP_IP_QUERY:
proto_tree_add_item(tree, hf_edonkey_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case OVERNET_MSG_UDP_IP_QUERY_ANSWER:
offset = dissect_edonkey_client_id(tvb, pinfo, offset, tree, FALSE);
break;
case OVERNET_MSG_UDP_IDENTIFY_REPLY:
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_address(tvb, pinfo, offset, tree);
break;
case OVERNET_MSG_UDP_IDENTIFY_ACK:
proto_tree_add_item(tree, hf_edonkey_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case OVERNET_MSG_UDP_FIREWALL_CONNECTION:
offset = dissect_edonkey_client_hash(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_edonkey_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case OVERNET_MSG_UDP_FIREWALL_CONNECTION_ACK:
case OVERNET_MSG_UDP_FIREWALL_CONNECTION_NACK:
offset = dissect_edonkey_client_hash(tvb, pinfo, offset, tree);
break;
default:
proto_tree_add_text(tree, tvb, offset, length, "Message Data (%d bytes)", length);
offset+=length;
break;
}
return offset;
}
static int dissect_emule_udp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint16 rank;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return offset;
msg_end = offset + length;
switch (msg_type) {
case EMULE_MSG_UDP_REASKFILEPING:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
if ( offset + 2 < msg_end ) {
offset = dissect_edonkey_file_status( tvb, pinfo, offset, tree );
}
if ( msg_end == offset + 2 ) {
proto_tree_add_item( tree, hf_emule_source_count, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
}
break;
case EMULE_MSG_UDP_REASKACK:
if ( offset + 2 < msg_end ) {
offset = dissect_edonkey_file_status( tvb, pinfo, offset, tree );
}
rank = tvb_get_letohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Queue Ranking: %u", rank);
offset += 2;
break;
default:
offset = dissect_edonkey_udp_message(msg_type, tvb, pinfo, offset, length,tree);
break;
}
return offset;
}
static int dissect_kademlia_peer_list_2byte(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Peer", dissect_kademlia_peer );
}
static int dissect_kademlia_peer_list_1byte(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Peer", dissect_kademlia_peer );
}
static int dissect_kademlia2_peer_list_2byte(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Peer", dissect_kademlia2_peer );
}
static int dissect_kademlia2_peer_list_1byte(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Peer", dissect_kademlia2_peer );
}
static int dissect_kademlia_tag(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint8 type;
guint8 tag_type;
const gchar *str_type;
proto_item *ti;
proto_item* tag_node;
proto_tree *subtree;
int item_start_offset;
item_start_offset = offset;
tag_node = proto_tree_add_text( tree, tvb, offset, 1, "Tag " );
subtree = proto_item_add_subtree( tag_node, ett_kademlia_tag );
type = tvb_get_guint8( tvb, offset );
str_type = val_to_str(type, kademlia_tag_types, "Unknown" );
{
proto_item * ti_tagtype;
ti_tagtype = proto_tree_add_item( subtree, hf_kademlia_tag_type, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( ti_tagtype, " [%s]", str_type );
}
offset += 1;
{
const gchar *tagname_string;
const gchar *tagname_extended_string;
tag_type = tvb_get_guint8( tvb, offset+2 );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, subtree, &tagname_string, &tagname_extended_string );
if ( strlen( tagname_string ) == 1 ) {
const guint8 tagname_guint = *(guint8*)tagname_string;
proto_item_append_text( tag_node, " 0x%02X [%s] = ", tagname_guint, tagname_extended_string );
}
else
proto_item_append_text( tag_node, " \"%s\" [%s] = ", tagname_string, tagname_extended_string );
}
switch( type )
{
case KADEMLIA_TAGTYPE_HASH:
proto_item_append_text( tag_node, "%s", tvb_bytes_to_str( tvb, offset, 16 ));
offset = dissect_kademlia_tag_hash( tvb, pinfo, offset, subtree );
break;
case KADEMLIA_TAGTYPE_STRING:
{
const gchar* value;
offset = dissect_kademlia_tag_string( tvb, pinfo, offset, subtree, &value );
proto_item_append_text( tag_node, "\"%s\"", value );
}
break;
case KADEMLIA_TAGTYPE_UINT8:
{
guint8 value;
ti = proto_tree_add_item( subtree, hf_kademlia_tag_uint8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
value = tvb_get_guint8( tvb, offset );
proto_item_append_text( tag_node, "%u (0x%02X)", value, value );
switch (tag_type) {
case KADEMLIA_TAG_SOURCETYPE:
{
proto_item_append_text(ti," (%s)", val_to_str(value, kademlia_tag_sourcetype, "Unknown"));
}
break;
case KADEMLIA_TAG_ENCRYPTION:
proto_item_append_text(ti, " (%s)", val_to_str(value, kademlia_tag_encryption, "Unknown"));
break;
}
offset += 1;
}
break;
case KADEMLIA_TAGTYPE_UINT16:
{
guint16 value;
proto_tree_add_item( subtree, hf_kademlia_tag_uint16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
value = tvb_get_letohs( tvb, offset );
proto_item_append_text( tag_node, "%u (0x%04X)", value, value );
offset += 2;
}
break;
case KADEMLIA_TAGTYPE_UINT64:
{
guint64 value;
proto_tree_add_item( subtree, hf_kademlia_tag_uint64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
value = tvb_get_letoh64( tvb, offset );
proto_item_append_text( tag_node, "%" G_GINT64_MODIFIER "u (0x%08" G_GINT64_MODIFIER "X)", value, value );
offset += 8;
}
break;
case KADEMLIA_TAGTYPE_UINT32:
{
guint32 value;
switch( tag_type) {
case KADEMLIA_TAG_SERVERIP:
case KADEMLIA_TAG_SOURCEIP:
{
int ipa = 0, ipb = 0, ipc = 0, ipd = 0;
proto_tree_add_item( subtree, hf_kademlia_tag_ipv4, tvb, offset, 4, ENC_LITTLE_ENDIAN);
value = tvb_get_letohl( tvb, offset );
ipa = (value / (256*256*256)) % 256;
ipb = (value / (256*256)) % 256;
ipc = (value / 256) % 256;
ipd = value % 256;
proto_item_append_text( tag_node, "%u.%u.%u.%u (0x%02X) ", ipa, ipb, ipc, ipd, value );
}
break;
default:
proto_tree_add_item( subtree, hf_kademlia_tag_uint32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
value = tvb_get_letohl( tvb, offset );
proto_item_append_text( tag_node, "%u (0x%02X) ", value, value );
}
offset += 4;
}
break;
case KADEMLIA_TAGTYPE_FLOAT32:
{
float value;
proto_tree_add_item( subtree, hf_kademlia_tag_float, tvb, offset, 4, ENC_LITTLE_ENDIAN);
value = tvb_get_letohieee_float( tvb, offset );
proto_item_append_text( tag_node, "%f", value );
offset += 4;
}
break;
case KADEMLIA_TAGTYPE_BSOB:
{
const gchar* value;
offset = dissect_kademlia_tag_bsob( tvb, pinfo, offset, subtree, &value );
proto_item_append_text( tag_node, "%s", value );
}
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Tag value not decoded for type: 0x%02X", type );
}
proto_item_append_text( tag_node, " (Type: %s)", str_type );
proto_item_set_len( tag_node, offset - item_start_offset );
return offset;
}
static int dissect_kademlia_taglist(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Tag", dissect_kademlia_tag );
}
static int dissect_kademlia_publish_req_entry_file(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_file_id);
return dissect_kademlia_taglist( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_publish_req_entry_peer(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_peer_id);
return dissect_kademlia_taglist( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_search_result(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_hash);
return dissect_kademlia_taglist( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_search_expression_tree(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
int op, item_start_offset;
proto_item* ti;
item_start_offset = offset;
op = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(tree, tvb, offset, 1, "SearchExp type: %x ", op);
++offset;
tree = proto_item_add_subtree( ti, ett_kademlia_search_expression );
switch( op ) {
case 0:
{
int boolop;
const char* bool_op_label;
proto_item_append_text( ti, "[BoolOp]" );
boolop = tvb_get_guint8(tvb, offset);
switch( boolop ) {
case 0:
bool_op_label = "AND";
break;
case 1:
bool_op_label = "OR";
break;
case 2:
bool_op_label = "NAND";
break;
default:
bool_op_label = "Unknown";
};
proto_tree_add_text(tree, tvb, offset, 1, "Bool op: %x [%s]", boolop, bool_op_label );
++offset;
offset = dissect_kademlia_search_expression_tree( tvb, pinfo, offset, tree );
offset = dissect_kademlia_search_expression_tree( tvb, pinfo, offset, tree );
break;
}
case 1:
proto_item_append_text( ti, "[String]" );
offset = dissect_kademlia_string( tvb, pinfo, offset, tree );
break;
case 2:
proto_item_append_text( ti, "[MetaTag]" );
offset = dissect_edonkey_string( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, tree, NULL, NULL );
break;
case 3:
proto_item_append_text( ti, "[32bitOp]" );
offset = dissect_kademlia_search_condition_argument_uint32( tvb, pinfo, offset, tree );
offset = dissect_kademlia_search_condition( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, tree, NULL, NULL );
break;
case 8:
proto_item_append_text( ti, "[64bitOp]" );
offset = dissect_kademlia_search_condition_argument_uint64( tvb, pinfo, offset, tree );
offset = dissect_kademlia_search_condition( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, tree, NULL, NULL );
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "NOT DECODED op %x", op );
}
proto_item_set_len( ti, offset - item_start_offset );
return offset;
}
static int dissect_kademlia2_prolog( tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
int kad_version;
proto_item* ti;
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_peer_id);
offset = dissect_kademlia_tcp_port(tvb, pinfo, offset, tree);
kad_version = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(tree, hf_kademlia_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, "%s", val_to_str(kad_version, kademlia_versions, " Unknown"));
offset++;
return offset;
}
static int dissect_kademlia_uload( tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
int uLoad;
uLoad = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "uLoad: %d", uLoad );
return offset +1;
}
static int dissect_kademlia_udp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
proto_item *hidden_item;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return offset;
hidden_item = proto_tree_add_item(tree, hf_kademlia, tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
msg_end = offset + length;
switch (msg_type) {
case KADEMLIA_BOOTSTRAP_REQ:
case KADEMLIA_HELLO_REQ:
case KADEMLIA_HELLO_RES:
offset = dissect_kademlia_peer(tvb, pinfo, offset, tree);
break;
case KADEMLIA2_BOOTSTRAP_REQ:
offset = dissect_kademlia2_prolog( tvb, pinfo, offset, tree );
break;
case KADEMLIA2_HELLO_REQ:
case KADEMLIA2_HELLO_RES:
offset = dissect_kademlia2_prolog( tvb, pinfo, offset, tree );
offset = dissect_kademlia_taglist( tvb, pinfo, offset, tree );
break;
case KADEMLIA_BOOTSTRAP_RES:
offset = dissect_kademlia_peer_list_2byte( tvb, pinfo, offset, tree );
break;
case KADEMLIA2_BOOTSTRAP_RES:
offset = dissect_kademlia2_prolog( tvb, pinfo, offset, tree );
offset = dissect_kademlia2_peer_list_2byte( tvb, pinfo, offset, tree );
break;
case KADEMLIA2_SEARCH_SOURCE_REQ:
{
guint16 startPos;
guint64 filesize;
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
startPos = tvb_get_letohs( tvb, offset );
proto_tree_add_text(tree, tvb, offset, 2, "Start position: %d", startPos );
offset +=2;
filesize = tvb_get_letoh64( tvb, offset );
proto_tree_add_text(tree, tvb, offset, 8, "Filesize: %" G_GINT64_MODIFIER "u", filesize );
offset +=8;
}
break;
case KADEMLIA_SEARCH_NOTES_REQ:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_hash);
break;
case KADEMLIA2_SEARCH_KEY_REQ:
{
guint16 startPos;
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
startPos = tvb_get_letohs( tvb, offset );
proto_tree_add_text(tree, tvb, offset, 2, "Start position: %d", startPos );
offset += 2;
}
break;
case KADEMLIA2_SEARCH_NOTES_REQ:
case KADEMLIA_PUBLISH_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
if (offset<msg_end) {
offset = dissect_kademlia_uload( tvb, pinfo, offset, tree );
}
break;
case KADEMLIA2_PUBLISH_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
offset = dissect_kademlia_uload( tvb, pinfo, offset, tree );
break;
case KADEMLIA_REQ:
case KADEMLIA2_REQ:
{
int type;
guint8 target_id[16];
guint8 recipients_id[16];
proto_item *ti;
int i, j, k, l;
char binarray[129];
type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint_format_value(tree, hf_kademlia_request_type, tvb, offset, 1, type, "0x%02x", type );
proto_item_append_text(ti, "%s", val_to_str(type, kademlia_parameter, " Unknown"));
offset +=1;
for (i=0; i<4; i++) {
for (j=3; j>=0; j--) {
l = (j+4*i);
target_id[l] = tvb_get_guint8(tvb, offset + abs(8*i-(l-3)));
}
}
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
for (i=0; i<4; i++) {
for (j=3; j>=0; j--) {
l = (j+4*i);
recipients_id[l] = tvb_get_guint8(tvb, offset + abs(8*i-(l-3)));
}
}
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_recipients_id);
for (i=0; i<16; i++) {
k = 128;
l = target_id[i]^recipients_id[i];
for(j=8*i; j<8*i+8; j++) {
if (l >= k) {
binarray[j] = '1';
l = l-k;
}
else
binarray[j] = '0';
k = k/2;
}
}
binarray[128] = '\0';
proto_tree_add_string_format_value(tree, hf_kademlia_distance, tvb, offset, 0, binarray, "%s", binarray);
}
break;
case KADEMLIA_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
offset = dissect_kademlia_peer_list_1byte( tvb, pinfo, offset, tree );
break;
case KADEMLIA2_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
offset = dissect_kademlia2_peer_list_1byte( tvb, pinfo, offset, tree );
break;
case KADEMLIA_FIREWALLED_RES:
offset = dissect_kademlia_ip_address( tvb, pinfo, offset, tree );
break;
case KADEMLIA_FIREWALLED_REQ:
offset = dissect_kademlia_tcp_port( tvb, pinfo, offset, tree );
break;
case KADEMLIA_CALLBACK_REQ:
case KADEMLIA_FINDBUDDY_REQ:
case KADEMLIA_FINDBUDDY_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_hash);
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_hash);
offset = dissect_kademlia_tcp_port( tvb, pinfo, offset, tree );
break;
case KADEMLIA2_PUBLISH_SOURCE_REQ:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_file_id);
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_peer_id);
offset = dissect_kademlia_taglist( tvb, pinfo, offset, tree );
break;
case KADEMLIA_SEARCH_REQ:
{
int restrictive;
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
restrictive = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Restrictive: %x", restrictive );
offset +=1;
if ( offset < msg_end && restrictive )
offset = dissect_kademlia_search_expression_tree( tvb, pinfo, offset, tree );
}
break;
case KADEMLIA_SEARCH_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Result", dissect_kademlia_search_result );
break;
case KADEMLIA2_SEARCH_RES:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_sender_id);
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Result", dissect_kademlia_search_result );
break;
case KADEMLIA2_PUBLISH_KEY_REQ:
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_keyword_hash);
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "StuffToPublish", dissect_kademlia_publish_req_entry_file );
break;
}
case KADEMLIA_PUBLISH_REQ:
{
guint8 tagname_value=0, taglist_size, type;
int i=1, j=34;
taglist_size = tvb_get_guint8(tvb, offset + j);
j++;
while(i <= taglist_size) {
type = tvb_get_guint8(tvb, offset + j);
j +=3;
tagname_value = tvb_get_guint8(tvb, offset + j);
if (tagname_value == 0xff)
i = taglist_size;
j++;
switch(type) {
case KADEMLIA_TAGTYPE_HASH:
j += 16;
break;
case KADEMLIA_TAGTYPE_STRING:
{
guint16 string_length = tvb_get_letohs(tvb, offset+j);
j += 2 + string_length;
break;
}
case KADEMLIA_TAGTYPE_UINT8:
j += 1;
break;
case KADEMLIA_TAGTYPE_UINT16:
j += 2;
break;
case KADEMLIA_TAGTYPE_UINT32:
case KADEMLIA_TAGTYPE_FLOAT32:
j += 4;
break;
case KADEMLIA_TAGTYPE_UINT64:
j += 8;
break;
case KADEMLIA_TAGTYPE_BSOB:
{
guint16 bsob_length = tvb_get_guint8(tvb, offset);
j += 1 + bsob_length;
break;
}
}
i++;
}
switch (tagname_value) {
case KADEMLIA_TAG_SOURCETYPE:
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_file_id);
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "StuffToPublish", dissect_kademlia_publish_req_entry_peer);
}
break;
default:
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_keyword_hash);
offset = dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "StuffToPublish", dissect_kademlia_publish_req_entry_file);
}
}
}
}
return offset;
}
static int dissect_kademlia_udp_compressed_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, int length, proto_tree *tree)
{
tvbuff_t *tvbraw = NULL;
tvbraw = tvb_child_uncompress(tvb, tvb, offset, length);
if (tvbraw) {
guint32 raw_length;
raw_length = tvb_length( tvbraw );
add_new_data_source(pinfo, tvbraw, "Decompressed Data");
dissect_kademlia_udp_message( msg_type, tvbraw, pinfo, 0, raw_length, tree );
offset += length;
} else {
proto_tree_add_text( tree, tvb, offset, length, "Broken Compressed data (%d bytes)", length);
}
return offset;
}
static guint get_edonkey_tcp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 msg_len;
msg_len = tvb_get_letohl(tvb, offset+1);
return msg_len + EDONKEY_TCP_HEADER_LENGTH;
}
static void dissect_edonkey_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *edonkey_tree = NULL, *edonkey_msg_tree = NULL, *emule_zlib_tree = NULL;
int offset, bytes;
guint8 protocol, msg_type;
guint32 msg_len;
const gchar *protocol_name, *message_name;
void (*dissector)(guint8, tvbuff_t*, packet_info*, int, int, proto_tree*);
tvbuff_t *tvbraw = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "eDonkey");
if (tree) {
ti = proto_tree_add_item(tree, proto_edonkey, tvb, 0, -1, ENC_NA);
edonkey_tree = proto_item_add_subtree(ti, ett_edonkey);
}
offset = 0;
protocol = tvb_get_guint8(tvb, offset);
msg_len = tvb_get_letohl(tvb, offset+1);
protocol_name = match_strval(protocol, edonkey_protocols);
if (protocol_name == NULL) {
col_set_str(pinfo->cinfo, COL_INFO, "eDonkey Continuation");
if (edonkey_tree) {
bytes = tvb_length_remaining(tvb, offset);
proto_tree_add_text(edonkey_tree, tvb, 0, -1, "Continuation data (%d bytes)", bytes);
}
return;
}
if (edonkey_tree) {
ti = proto_tree_add_item(edonkey_tree, hf_edonkey_message, tvb,
offset, EDONKEY_TCP_HEADER_LENGTH + msg_len, ENC_NA);
edonkey_msg_tree = proto_item_add_subtree(ti, ett_edonkey_message);
proto_tree_add_uint_format(edonkey_msg_tree, hf_edonkey_protocol, tvb, offset, 1, protocol,
"Protocol: %s (0x%02x)", protocol_name, protocol);
proto_tree_add_uint(edonkey_msg_tree, hf_edonkey_message_length, tvb, offset+1, 4, msg_len);
}
offset += EDONKEY_TCP_HEADER_LENGTH;
if(tvb_reported_length_remaining(tvb, offset) <= 0) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s TCP Message Fragment", protocol_name);
}
return;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ", "%s TCP", protocol_name);
}
msg_type = tvb_get_guint8(tvb, offset);
switch (protocol) {
case EDONKEY_PROTO_EDONKEY:
message_name = val_to_str(msg_type, edonkey_tcp_msgs, "Unknown");
dissector = dissect_edonkey_tcp_message;
break;
case EDONKEY_PROTO_EMULE_EXT:
message_name = val_to_str(msg_type, emule_tcp_msgs,
val_to_str(msg_type, edonkey_tcp_msgs, "Unknown"));
dissector = dissect_emule_tcp_message;
break;
case EDONKEY_PROTO_EMULE_COMP:
message_name = val_to_str(msg_type, edonkey_tcp_msgs, "Unknown");
tvbraw = tvb_child_uncompress(tvb, tvb, offset+1, msg_len-1);
if (tvbraw) {
dissector = dissect_edonkey_tcp_message;
break;
}
default:
message_name = "Unknown";
dissector = NULL;
break;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", message_name);
}
if (edonkey_msg_tree) {
proto_tree_add_uint_format(edonkey_msg_tree, hf_edonkey_message_type, tvb, offset, 1, msg_type,
"Message Type: %s (0x%02x)", message_name, msg_type);
if (dissector && (msg_len > 1)) {
if (!tvbraw) {
(*dissector)(msg_type, tvb, pinfo, offset+1, msg_len-1, edonkey_msg_tree);
} else {
ti = proto_tree_add_item(edonkey_msg_tree, hf_emule_zlib, tvb,
offset+1, msg_len-1, ENC_NA);
emule_zlib_tree = proto_item_add_subtree(ti, ett_emule_zlib);
add_new_data_source(pinfo, tvbraw, "Decompressed Data");
(*dissector)(msg_type, tvbraw, pinfo, 0, tvb_length(tvbraw), emule_zlib_tree);
}
}
}
}
static void dissect_edonkey_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, edonkey_desegment,
EDONKEY_TCP_HEADER_LENGTH, get_edonkey_tcp_pdu_len,
dissect_edonkey_tcp_pdu);
}
static void dissect_edonkey_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *edonkey_tree = NULL, *edonkey_msg_tree = NULL;
int offset;
guint8 protocol, msg_type;
const gchar *protocol_name, *message_name;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "eDonkey");
col_set_str(pinfo->cinfo, COL_INFO, "eDonkey UDP Message");
if (tree) {
ti = proto_tree_add_item(tree, proto_edonkey, tvb, 0, -1, ENC_NA);
edonkey_tree = proto_item_add_subtree(ti, ett_edonkey);
}
offset = 0;
if (tvb_length_remaining(tvb, offset) >= EDONKEY_UDP_HEADER_LENGTH) {
protocol = tvb_get_guint8(tvb, offset);
msg_type = tvb_get_guint8(tvb, offset+1);
protocol_name = val_to_str(protocol, edonkey_protocols, "Unknown");
if (protocol == EDONKEY_PROTO_KADEMLIA || protocol == EDONKEY_PROTO_KADEMLIA_COMP
|| protocol == EDONKEY_PROTO_ADU_KADEMLIA || protocol == EDONKEY_PROTO_ADU_KADEMLIA_COMP)
message_name = val_to_str( msg_type, kademlia_msgs, "Unknown");
else
message_name = val_to_str(msg_type, edonkey_udp_msgs, "Unknown");
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s UDP: %s", protocol_name, message_name);
}
if (edonkey_tree) {
int remainingLength, extraBytes;
ti = proto_tree_add_item(edonkey_tree, hf_edonkey_message, tvb, offset, -1, ENC_NA);
edonkey_msg_tree = proto_item_add_subtree(ti, ett_edonkey_message);
proto_tree_add_uint_format(edonkey_msg_tree, hf_edonkey_protocol, tvb, offset, 1, protocol,
"Protocol: %s (0x%02x)", protocol_name, protocol);
proto_tree_add_uint_format(edonkey_msg_tree, hf_edonkey_message_type, tvb, offset+1, 1, msg_type,
"Message Type: %s (0x%02x)", message_name, msg_type);
offset += EDONKEY_UDP_HEADER_LENGTH;
remainingLength = tvb_length_remaining( tvb, offset );
switch (protocol) {
case EDONKEY_PROTO_EDONKEY:
offset = dissect_edonkey_udp_message(msg_type, tvb, pinfo, offset, remainingLength, edonkey_msg_tree);
break;
case EDONKEY_PROTO_EMULE_EXT:
offset = dissect_emule_udp_message(msg_type, tvb, pinfo, offset, remainingLength, edonkey_msg_tree);
break;
case EDONKEY_PROTO_ADU_KADEMLIA:
case EDONKEY_PROTO_KADEMLIA:
offset = dissect_kademlia_udp_message(msg_type, tvb, pinfo, offset, remainingLength, edonkey_msg_tree);
break;
case EDONKEY_PROTO_ADU_KADEMLIA_COMP:
case EDONKEY_PROTO_KADEMLIA_COMP:
offset = dissect_kademlia_udp_compressed_message(msg_type, tvb, pinfo, offset, remainingLength, edonkey_msg_tree);
break;
default:
break;
}
extraBytes = tvb_length_remaining( tvb, offset );
if ( extraBytes > 0 ) {
proto_tree_add_uint_format(tree, hf_edonkey_unparsed_data_length, tvb, offset, extraBytes, extraBytes,
"Trailing/Undecoded data: %d bytes", extraBytes );
}
}
}
}
void proto_register_edonkey(void) {
static hf_register_info hf[] = {
{ &hf_edonkey_message,
{ "eDonkey Message", "edonkey.message",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_edonkey_protocol,
{ "Protocol", "edonkey.protocol",
FT_UINT8, BASE_HEX, VALS(edonkey_protocols), 0, "eDonkey Protocol", HFILL } },
{ &hf_edonkey_message_length,
{ "Message Length", "edonkey.message.length",
FT_UINT32, BASE_DEC, NULL, 0, "eDonkey Message Length", HFILL } },
{ &hf_edonkey_message_type,
{ "Message Type", "edonkey.message.type",
FT_UINT8, BASE_HEX, NULL, 0, "eDonkey Message Type", HFILL } },
{ &hf_edonkey_client_hash,
{ "Client Hash", "edonkey.client_hash",
FT_BYTES, BASE_NONE, NULL, 0, "eDonkey Client Hash", HFILL } },
{ &hf_edonkey_server_hash,
{ "Server Hash", "edonkey.server_hash",
FT_BYTES, BASE_NONE, NULL, 0, "eDonkey Server Hash", HFILL } },
{ &hf_edonkey_file_hash,
{ "File Hash", "edonkey.file_hash",
FT_BYTES, BASE_NONE, NULL, 0, "eDonkey File Hash", HFILL } },
{ &hf_edonkey_client_id,
{ "Client ID", "edonkey.clientid",
FT_IPv4, BASE_NONE, NULL, 0, "eDonkey Client ID", HFILL } },
{ &hf_edonkey_ip,
{ "IP", "edonkey.ip",
FT_IPv4, BASE_NONE, NULL, 0, "eDonkey IP", HFILL } },
{ &hf_edonkey_port,
{ "Port", "edonkey.port",
FT_UINT16, BASE_DEC, NULL, 0, "eDonkey Port", HFILL } },
{ &hf_edonkey_metatag,
{ "eDonkey Meta Tag", "edonkey.metatag",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_edonkey_metatag_type,
{ "Meta Tag Type", "edonkey.metatag.type",
FT_UINT8, BASE_HEX, NULL, 0, "eDonkey Meta Tag Type", HFILL } },
{ &hf_edonkey_metatag_id,
{ "Meta Tag ID", "edonkey.metatag.id",
FT_UINT8, BASE_HEX, NULL, 0, "eDonkey Meta Tag ID", HFILL } },
{ &hf_edonkey_metatag_name,
{ "Meta Tag Name", "edonkey.metatag.name",
FT_STRING, BASE_NONE, NULL, 0, "eDonkey Meta Tag Name", HFILL } },
{ &hf_edonkey_metatag_namesize,
{ "Meta Tag Name Size", "edonkey.metatag.namesize",
FT_UINT16, BASE_DEC, NULL, 0, "eDonkey Meta Tag Name Size", HFILL } },
{ &hf_edonkey_search,
{ "eDonkey Search", "edonkey.search",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_edonkey_hash,
{ "Hash", "edonkey.hash",
FT_BYTES, BASE_NONE, NULL, 0, "eDonkey Hash", HFILL } },
{ &hf_edonkey_string,
{ "String", "edonkey.string",
FT_STRING, BASE_NONE, NULL, 0, "eDonkey String", HFILL } },
{ &hf_edonkey_string_length,
{ "String Length", "edonkey.string_length",
FT_UINT16, BASE_DEC, NULL, 0, "eDonkey String Length", HFILL } },
{ &hf_edonkey_part_count,
{ "Part Count", "edonkey.part_count",
FT_UINT16, BASE_DEC, NULL, 0, "eDonkey Part Count", HFILL } },
{ &hf_edonkey_file_status,
{ "File Status", "edonkey.file_status",
FT_BYTES, BASE_NONE, NULL, 0, "eDonkey File Status", HFILL } },
{ &hf_edonkey_directory,
{ "Directory", "edonkey.directory",
FT_STRING, BASE_NONE, NULL, 0, "eDonkey Directory", HFILL } },
{ &hf_edonkey_fileinfo,
{ "eDonkey File Info", "edonkey.fileinfo",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_edonkey_serverinfo,
{ "eDonkey Server Info", "edonkey.serverinfo",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_edonkey_clientinfo,
{ "eDonkey Client Info", "edonkey.clientinfo",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_emule_public_key,
{ "Public Key", "edonkey.emule.public_key",
FT_BYTES, BASE_NONE, NULL, 0, "eMule Public Key", HFILL } },
{ &hf_emule_signature,
{ "Signature", "edonkey.emule.signature",
FT_BYTES, BASE_NONE, NULL, 0, "eMule Signature", HFILL } },
{ &hf_emule_aich_partnum,
{ "Part Number", "edonkey.emule.aich_partnum",
FT_UINT16, BASE_DEC, NULL, 0, "eMule AICH Part Number", HFILL } },
{ &hf_emule_aich_root_hash,
{ "AICH Root Hash", "edonkey.emule.aich_root_hash",
FT_BYTES, BASE_NONE, NULL, 0, "eMule AICH Root Hash", HFILL } },
{ &hf_emule_aich_hash_entry,
{ "AICH Hash Entry", "edonkey.emule.aich_hash_entry",
FT_NONE, BASE_NONE, NULL, 0, "eMule AICH Hash Entry", HFILL } },
{ &hf_emule_aich_hash_id,
{ "AICH Hash ID", "edonkey.emule.aich_hash_id",
FT_UINT16, BASE_HEX, NULL, 0, "eMule AICH Hash ID", HFILL } },
{ &hf_emule_aich_hash,
{ "AICH Hash", "edonkey.emule.aich_hash",
FT_BYTES, BASE_NONE, NULL, 0, "eMule AICH Hash", HFILL } },
{ &hf_emule_multipacket_entry,
{ "eMule MultiPacket Entry", "edonkey.emule.multipacket_entry",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_emule_multipacket_opcode,
{ "MultiPacket Opcode", "edonkey.emule.multipacket_opcode",
FT_UINT8, BASE_HEX, NULL, 0, "eMule MultiPacket Opcode", HFILL } },
{ &hf_emule_sourceOBFU,
{"Source", "edonkey.source",
FT_NONE, BASE_NONE, NULL, 0, "eDonkey File Source", HFILL } },
{ &hf_emule_source_count,
{ "Completed Sources Count", "edonkey.emule.source_count",
FT_UINT16, BASE_DEC, NULL, 0, "eMule Completed Sources Count", HFILL } },
{ &hf_emule_zlib,
{ "Compressed Data", "edonkey.emule.zlib",
FT_NONE, BASE_NONE, NULL, 0, "eMule Compressed Data", HFILL } },
{ &hf_overnet_peer,
{ "Overnet Peer", "edonkey.overnet.peer",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_kademlia,
{ "Kademlia Packet", "edonkey.kademlia",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Packet Type", HFILL } },
{ &hf_kademlia_peertype,
{ "Peer Type", "edonkey.kademlia.peer.type",
FT_UINT8, BASE_DEC_HEX, NULL, 0, "Kademlia Peer Type", HFILL } },
{ &hf_kademlia_peer,
{ "Kademlia Peer", "edonkey.kademlia.peer",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_kademlia_peer_id,
{ "Peer ID", "edonkey.kademlia.peer.id",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia Peer ID", HFILL } },
{ &hf_kademlia_hash,
{ "Kademlia Hash", "edonkey.kademlia.hash",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_kademlia_file_id,
{ "File ID", "edonkey.kademlia.file.id",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia File ID", HFILL } },
{ &hf_kademlia_keyword_hash,
{ "Keyword Hash", "edonkey.kademlia.keyword.hash",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia Keyword Hash", HFILL } },
{ &hf_kademlia_recipients_id,
{ "Recipient's ID", "edonkey.kademlia.recipients.id",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia Recipient's ID", HFILL } },
{ &hf_kademlia_sender_id,
{ "Sender ID", "edonkey.kademlia.sender.id",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia Sender ID", HFILL } },
{ &hf_kademlia_target_id,
{ "Target ID", "edonkey.kademlia.target.id",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia Target ID", HFILL } },
{ &hf_kademlia_distance,
{ "XOR Distance", "edonkey.kademlia.distance",
FT_STRING, BASE_NONE, NULL, 0, "Kademlia XOR Distance", HFILL } },
{ &hf_kademlia_version,
{ "Kad Version", "edonkey.kademlia.version",
FT_UINT8, BASE_DEC_HEX, NULL, 0, NULL, HFILL } },
{ &hf_kademlia_tag_float,
{ "Tag Value (Float)", "edonkey.kademlia.tag.value.float",
FT_FLOAT, BASE_NONE, NULL, 0, "Float Tag Value", HFILL } },
{ &hf_kademlia_tag_uint64,
{ "Tag Value (UINT64)", "edonkey.kademlia.tag.value.uint64",
FT_UINT64, BASE_DEC_HEX, NULL, 0, "UINT64 Tag Value", HFILL } },
{ &hf_kademlia_tag_uint32,
{ "Tag Value (UINT32)", "edonkey.kademlia.tag.value.uint32",
FT_UINT32, BASE_DEC_HEX, NULL, 0, "UINT32 Tag Value", HFILL } },
{ &hf_kademlia_tag_ipv4,
{ "Tag Value (IPv4)", "edonkey.kademlia.tag.value.ipv4",
FT_IPv4, BASE_NONE, NULL, 0, "UINT32 Tag Value (IPv4)", HFILL } },
{ &hf_kademlia_tag_uint16,
{ "Tag Value (UINT16)", "edonkey.kademlia.tag.value.uint16",
FT_UINT16, BASE_DEC_HEX, NULL, 0, "UINT16 Tag Value", HFILL } },
{ &hf_kademlia_tag_uint8,
{ "Tag Value (UINT8)", "edonkey.kademlia.tag.value.uint8",
FT_UINT8, BASE_DEC_HEX, NULL, 0, "UINT8 Tag Value", HFILL } },
{ &hf_kademlia_tag_hash,
{ "Tag Value (HASH)", "edonkey.kademlia.tag.value.hash",
FT_BYTES, BASE_NONE, NULL, 0, "HASH Tag Value", HFILL } },
{ &hf_kademlia_tag_string,
{ "Tag Value (String)", "edonkey.kademlia.tag.value.string",
FT_STRING, BASE_NONE, NULL, 0, "String Tag Value", HFILL } },
{ &hf_kademlia_tag_bsob,
{ "Tag Value (BSOB)", "edonkey.kademlia.tag.value.bsob",
FT_BYTES, BASE_NONE, NULL, 0, "BSOB Tag Value", HFILL } },
{ &hf_kademlia_udp_port,
{ "UDP Port", "edonkey.kademlia.udp_port",
FT_UINT16, BASE_DEC, NULL, 0, "Kademlia UDP Port", HFILL } },
{ &hf_kademlia_ip,
{ "IP", "edonkey.kademlia.ip",
FT_IPv4, BASE_NONE, NULL, 0, "eDonkey IP", HFILL } },
{ &hf_kademlia_tcp_port,
{ "TCP Port", "edonkey.kademlia.tcp_port",
FT_UINT16, BASE_DEC, NULL, 0, "Kademlia TCP Port", HFILL } },
{ &hf_kademlia_unparsed_data_length,
{ "Kademlia unparsed data length", "edonkey.kademlia.unparsed",
FT_UINT16, BASE_DEC, NULL, 0, "Kademlia trailing data length", HFILL } },
{ &hf_kademlia_tag_name,
{ "Tag Name", "edonkey.kademlia.tag.name",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Tag Name String", HFILL } },
{ &hf_kademlia_tag_name_length,
{ "Tag Name Length", "edonkey.kademlia.tag.name.length",
FT_UINT16, BASE_DEC, NULL, 0, "Kademlia Tag Name String Length", HFILL } },
{ &hf_kademlia_tag_type,
{ "Tag Type", "edonkey.kademlia.tag.type",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Tag Type", HFILL } },
{ &hf_kademlia_request_type,
{ "Request Type", "edonkey.kademlia.request.type",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Request Type", HFILL } },
{ &hf_kademlia_search_condition,
{ "Search Condition", "edonkey.kademlia.search.condition",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Search Condition", HFILL } },
{ &hf_kademlia_search_condition_argument_uint32,
{ "32bit Argument", "edonkey.kademlia.search.condition.argument.uint32",
FT_UINT32, BASE_DEC_HEX, NULL, 0, "Kademlia Search Condition Argument 32bit Value", HFILL } },
{ &hf_kademlia_search_condition_argument_uint64,
{ "64bit Argument", "edonkey.kademlia.search.condition.argument.uint64",
FT_UINT64, BASE_DEC_HEX, NULL, 0, "Kademlia Search Condition Argument 64bit Value", HFILL } },
{ &hf_edonkey_unparsed_data_length,
{ "eDonkey unparsed data length", "edonkey.unparsed",
FT_UINT32, BASE_DEC_HEX, NULL, 0, "eDonkey trailing or unparsed data length", HFILL } },
};
static gint *ett[] = {
&ett_edonkey,
&ett_edonkey_message,
&ett_edonkey_metatag,
&ett_edonkey_search,
&ett_edonkey_fileinfo,
&ett_edonkey_serverinfo,
&ett_edonkey_clientinfo,
&ett_emule_aichhash,
&ett_emule_multipacket,
&ett_emule_zlib,
&ett_overnet_peer,
&ett_emule_sourceOBFU,
&ett_edonkey_listitem,
&ett_kademlia_search_expression,
&ett_kademlia_tag
};
module_t *edonkey_module;
proto_edonkey = proto_register_protocol("eDonkey Protocol", "EDONKEY", "edonkey");
proto_register_field_array(proto_edonkey, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("edonkey.tcp", dissect_edonkey_tcp, proto_edonkey);
register_dissector("edonkey.udp", dissect_edonkey_udp, proto_edonkey);
edonkey_module = prefs_register_protocol(proto_edonkey, NULL);
prefs_register_bool_preference(edonkey_module, "desegment",
"Reassemble eDonkey messages spanning multiple TCP segments",
"Whether the eDonkey dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&edonkey_desegment);
}
void proto_reg_handoff_edonkey(void) {
dissector_handle_t edonkey_tcp_handle;
dissector_handle_t edonkey_udp_handle;
edonkey_tcp_handle = find_dissector("edonkey.tcp");
edonkey_udp_handle = find_dissector("edonkey.udp");
dissector_add_uint("tcp.port", 4661, edonkey_tcp_handle);
dissector_add_uint("tcp.port", 4662, edonkey_tcp_handle);
dissector_add_uint("tcp.port", 4663, edonkey_tcp_handle);
dissector_add_uint("udp.port", 4665, edonkey_udp_handle);
dissector_add_uint("udp.port", 4672, edonkey_udp_handle);
}
