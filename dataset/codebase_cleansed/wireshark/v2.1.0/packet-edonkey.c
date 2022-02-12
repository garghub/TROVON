static int dissect_edonkey_list(tvbuff_t *tvb, packet_info *pinfo,
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
list_ti = proto_tree_add_uint_format(tree, hf_edonkey_list_size, tvb, offset, listnum_length, listnum, "%s List Size: %u", listdesc, listnum);
offset+= listnum_length;
for (i=0; i<listnum; i++)
{
int item_start_offset;
item_start_offset = offset;
subtree = proto_tree_add_subtree_format( tree, tvb, item_start_offset, 1, ett_edonkey_listitem, &ti,
"%s[%u/%u]", listdesc, i+1, listnum);
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
if (try_val_to_str(special_tagtype, edonkey_special_tags) == NULL) {
gint idx;
tag_name = tvb_get_string_enc(wmem_packet_scope(), tvb, start, length, ENC_ASCII|ENC_NA);
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
tag_name = try_val_to_str(special_tagtype, edonkey_special_tags);
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
proto_item_append_text(ti, " [%s]", val_to_str_const( value, kademlia_search_conds, "Unknown") );
return offset + 1;
}
static int dissect_edonkey_metatag(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *metatag_tree;
guint8 real_tag_type, tag_type, special_tagtype, trans_tagtype;
guint16 tag_name_size, string_length, array_length;
guint32 tag_length, blob_length;
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
proto_tree_add_item(metatag_tree, hf_edonkey_meta_tag_value_revision, tvb, tag_offset, 4, ENC_LITTLE_ENDIAN);
}
else {
proto_tree_add_item(metatag_tree, hf_edonkey_meta_tag_value_uint, tvb, tag_offset, 4, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(metatag_tree, hf_edonkey_meta_tag_value_uint, tvb, tag_offset, 2, ENC_LITTLE_ENDIAN);
break;
case EDONKEY_MTAG_BYTE:
tag_length += 1;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_item(metatag_tree, hf_edonkey_meta_tag_value_uint, tvb, tag_offset, 1, ENC_NA);
break;
case EDONKEY_MTAG_BOOL:
tag_length += 1;
ti = proto_tree_add_item(tree, hf_edonkey_metatag, tvb, offset, tag_length, ENC_NA);
metatag_tree = proto_item_add_subtree(ti, ett_edonkey_metatag);
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type);
if (tag_type==real_tag_type)
proto_tree_add_uint(metatag_tree, hf_edonkey_metatag_namesize, tvb, offset+1, 2, tag_name_size);
edonkey_tree_add_metatag_name(metatag_tree, tvb, tag_offset-tag_name_size, tag_name_size, special_tagtype);
proto_tree_add_item(metatag_tree, hf_edonkey_meta_tag_value_uint, tvb, tag_offset, 1, ENC_NA);
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
proto_tree_add_item(metatag_tree, hf_edonkey_boolean_array_length, tvb, tag_offset, 2, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(metatag_tree, hf_edonkey_blob_length, tvb, tag_offset, 2, ENC_LITTLE_ENDIAN);
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
proto_tree_add_uint_format(metatag_tree, hf_edonkey_metatag_type, tvb, offset, 1, tag_type, "Unknown Meta Tag Type (0x%02x)", tag_type);
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
static int dissect_kademlia_address(tvbuff_t *tvb, packet_info *pinfo,
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
tagname = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, string_length, ENC_ASCII|ENC_NA);
tag_full_name = "UnknownTagName";
if ( tagname && string_length == 1 ) {
tagname_value = *(const guint8*)tagname;
tag_full_name = val_to_str_const( tagname_value, kademlia_tags, tag_full_name );
}
ti = proto_tree_add_item(tree, hf_kademlia_tag_name, tvb, offset + 2, string_length, ENC_BIG_ENDIAN);
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
guint16 string_length = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_edonkey_string_length, tvb, offset, 2, string_length);
proto_tree_add_item(tree, hf_edonkey_kademlia_string, tvb, offset+2, string_length, ENC_ASCII|ENC_NA);
return offset+2+string_length;
}
static int dissect_edonkey_address_list(tvbuff_t *tvb, packet_info *pinfo,
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
proto_tree_add_item(tree, hf_emule_public_key_length, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_emule_public_key, tvb, offset, length, ENC_NA);
return offset + length;
}
static int dissect_edonkey_signature(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
guint8 length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_emule_signature_length, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_emule_signature, tvb, offset, length, ENC_NA);
return offset + length;
}
static const char *kademlia_hash(tvbuff_t *tvb, int offset) {
guint32 hash[4];
int i;
for (i = 0; i < 4; i++)
hash[i] = tvb_get_letohl(tvb, offset + i*4);
return wmem_strdup_printf(wmem_packet_scope(),
"%08X%08X%08X%08X", hash[0], hash[1], hash[2], hash[3]);
}
static int dissect_kademlia_hash_hidden(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree) {
proto_item *hidden_item;
const char *hash;
hash = kademlia_hash(tvb, offset);
hidden_item = proto_tree_add_string(tree, hf_kademlia_hash, tvb, offset, 16, hash);
PROTO_ITEM_SET_HIDDEN(hidden_item);
return offset+16;
}
static int dissect_kademlia_hash(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree, int *value_ptr) {
const char *hash;
hash = kademlia_hash(tvb, offset);
proto_tree_add_string(tree, *value_ptr, tvb, offset, 16, hash);
return dissect_kademlia_hash_hidden(tvb, pinfo, offset, tree);
}
static int dissect_kademlia_tag_hash_hidden(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree) {
proto_item *hidden_item;
const char *hash;
hash = kademlia_hash(tvb, offset);
hidden_item = proto_tree_add_string(tree, hf_kademlia_tag_hash, tvb, offset, 16, hash);
PROTO_ITEM_SET_HIDDEN(hidden_item);
return offset+16;
}
static int dissect_kademlia_tag_hash(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree) {
const char *hash;
hash = kademlia_hash(tvb, offset);
proto_tree_add_string(tree, hf_kademlia_hash, tvb, offset, 16, hash);
return dissect_kademlia_tag_hash_hidden( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_tag_bsob(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree, const gchar** string_value )
{
guint16 bsob_length;
bsob_length = tvb_get_guint8(tvb, offset);
*string_value = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset + 1, bsob_length );
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
hidden_item = proto_tree_add_item(tree, hf_edonkey_string, tvb, offset + 2, string_length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
*string_value = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, string_length, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_kademlia_tag_string, tvb, offset + 2, string_length, ENC_ASCII|ENC_NA);
return offset + 2 + string_length;
}
static int dissect_edonkey_hash_list(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Hash", dissect_edonkey_hash);
}
static int dissect_edonkey_metatag_list(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_edonkey_file_name(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_edonkey_directory_list(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_emule_sourceOBFU(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *sourceOBFU_tree;
guint8 settings = tvb_get_guint8(tvb, offset+6);
ti = proto_tree_add_item(tree, hf_emule_sourceOBFU, tvb, offset, 7 + ((settings & 0x80) ? 16 : 0), ENC_NA);
sourceOBFU_tree = proto_item_add_subtree(ti, ett_emule_sourceOBFU);
proto_tree_add_item(sourceOBFU_tree, hf_edonkey_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sourceOBFU_tree, hf_edonkey_port, tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sourceOBFU_tree, hf_edonkey_obfuscation_settings, tvb, offset+6, 1, ENC_NA);
offset += 7;
if (settings & 0x80)
offset = dissect_edonkey_client_hash(tvb, pinfo, offset, sourceOBFU_tree);
return offset;
}
static int dissect_emule_sourceOBFU_list(tvbuff_t *tvb, packet_info *pinfo,
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
proto_tree_add_item(tree, hf_edonkey_start_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return offset+4;
}
static int dissect_edonkey_start_offset_64(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_start_offset_64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
return offset+8;
}
static int dissect_edonkey_end_offset(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_end_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
return offset+4;
}
static int dissect_edonkey_end_offset_64(tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_end_offset_64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
return offset+8;
}
static int dissect_edonkey_client_info(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_edonkey_client_info_list(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 4, "Client Info", dissect_edonkey_client_info);
}
static int dissect_edonkey_server_info(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_edonkey_file_info(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_edonkey_file_info_list(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 4, "File Info", dissect_edonkey_file_info);
}
static int dissect_emule_address_list(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_emule_aich_hash_list(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "AICH Hash", dissect_emule_aich_hash_list_entry);
}
static int dissect_emule_multipacket(tvbuff_t *tvb, packet_info *pinfo,
int offset, int eoffset, proto_tree *tree, int isext)
{
guint8 opcode, nextop;
guint16 namelen, partcount, arrlen, oplen;
guint32 sourcecount;
proto_item *ti;
proto_tree *mp_tree;
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
if (isext) {
proto_tree_add_item(tree, hf_edonkey_emule_file_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_edonkey_overnet_peer_type, tvb, offset, 1, ENC_NA);
return offset+1;
}
static int dissect_overnet_peer(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_kademlia_peer(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *peer_tree;
ti = proto_tree_add_item(tree, hf_kademlia_peer, tvb, offset, 16 + 4 + 4 + 1, ENC_NA);
peer_tree = proto_item_add_subtree(ti, ett_overnet_peer);
offset = dissect_kademlia_hash(tvb, pinfo, offset, peer_tree, &hf_kademlia_peer_id);
offset = dissect_kademlia_address(tvb, pinfo, offset, peer_tree);
proto_tree_add_item(peer_tree, hf_kademlia_version, tvb, offset, 1, ENC_BIG_ENDIAN);
return offset + 1;
}
static int dissect_kademlia2_peer(tvbuff_t *tvb, packet_info *pinfo,
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
static int dissect_edonkey_search_query(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *search_tree;
guint8 search_type, special_tagtype;
guint16 tag_name_size, string_length;
guint32 search_length;
int string_offset, tag_name_offset;
search_type = tvb_get_guint8(tvb, offset);
search_length = 1;
ti = proto_tree_add_uint(tree, hf_edonkey_search_type, tvb, offset, 1, search_type);
switch (search_type)
{
case EDONKEY_SEARCH_BOOL:
search_length += 1;
proto_item_set_len(ti, search_length);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_item(search_tree, hf_edonkey_search_ops, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset+=2;
offset = dissect_edonkey_search_query(tvb, pinfo, offset, search_tree);
offset = dissect_edonkey_search_query(tvb, pinfo, offset, search_tree);
break;
case EDONKEY_SEARCH_NAME:
string_offset = offset + search_length;
string_length = tvb_get_letohs(tvb, string_offset);
search_length += 2+string_length;
proto_item_set_len(ti, search_length);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
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
proto_item_set_len(ti, search_length);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_uint(search_tree, hf_edonkey_string_length, tvb, string_offset, 2, string_length);
proto_tree_add_item(search_tree, hf_edonkey_string, tvb, string_offset+2, string_length, ENC_ASCII|ENC_NA);
proto_tree_add_uint(search_tree, hf_edonkey_metatag_namesize, tvb, tag_name_offset, 2, tag_name_size);
edonkey_tree_add_metatag_name(search_tree, tvb, tag_name_offset+2, tag_name_size, special_tagtype);
offset += search_length;
break;
case EDONKEY_SEARCH_LIMIT:
search_length += 5;
tag_name_offset = offset + search_length;
tag_name_size = tvb_get_letohs(tvb, tag_name_offset);
special_tagtype = tvb_get_guint8(tvb, tag_name_offset+2);
search_length += 2 + tag_name_size;
proto_item_set_len(ti, search_length);
search_tree = proto_item_add_subtree(ti, ett_edonkey_search);
proto_tree_add_item(search_tree, hf_edonkey_search_limit, tvb, offset+1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(search_tree, hf_edonkey_search_limit_type, tvb, offset+5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint(search_tree, hf_edonkey_metatag_namesize, tvb, tag_name_offset, 2, tag_name_size);
edonkey_tree_add_metatag_name(search_tree, tvb, tag_name_offset+2, tag_name_size, special_tagtype);
offset += search_length;
break;
default:
proto_item_set_len(ti, search_length);
offset += search_length;
break;
}
return offset;
}
static void dissect_edonkey_tcp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint8 helloClient;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return;
msg_end = offset + length;
switch (msg_type) {
case EDONKEY_MSG_HELLO:
helloClient = (tvb_get_guint8(tvb, offset) == 0x10 && tvb_get_guint8(tvb, offset + 6) == 0x0E && tvb_get_guint8(tvb, offset + 15) == 0x6F);
if (helloClient) {
proto_tree_add_uint(tree, hf_edonkey_user_hash_length, tvb, offset, 1, 16);
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
proto_tree_add_item(tree, hf_edonkey_more_search_file_results, tvb, offset, 1, ENC_NA);
break;
case EDONKEY_MSG_SEARCH_FILES:
case EDONKEY_MSG_SEARCH_USER:
offset = dissect_edonkey_search_query(tvb, pinfo, offset, tree);
break;
case EDONKEY_MSG_GET_SOURCES:
case EDONKEY_MSG_GET_SOURCES_OBFU:
{
guint32 fileSize;
proto_item* ti;
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
fileSize = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_uint(tree, hf_edonkey_file_size, tvb, offset, 4, fileSize);
offset += 4;
if (fileSize == 0) {
proto_item_append_text(ti, " (64bit file size used)");
proto_tree_add_item(tree, hf_edonkey_large_file_size, tvb, offset, 8, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_edonkey_number_of_users, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_edonkey_number_of_files, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_edonkey_message_data, tvb, offset, bytes_remaining, ENC_NA);
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
proto_tree_add_item(tree, hf_edonkey_message_data, tvb, offset, length, ENC_NA);
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
tvbuff_t *tvb, packet_info *pinfo,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint16 partnum;
bytes_remaining = tvb_reported_length_remaining(tvb, offset);
if ((length < 0) || (length > bytes_remaining)) length = bytes_remaining;
if (length <= 0) return;
msg_end = offset + length;
switch (msg_type) {
case EMULE_MSG_HELLO:
case EMULE_MSG_HELLO_ANSWER:
proto_tree_add_item(tree, hf_edonkey_emule_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
dissect_edonkey_metatag_list(tvb, pinfo, offset+2, tree);
break;
case EMULE_MSG_QUEUE_RANKING:
proto_tree_add_item(tree, hf_edonkey_emule_queue_ranking, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case EMULE_MSG_SOURCES_REQUEST:
dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SOURCES_ANSWER:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
dissect_emule_address_list(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SEC_IDENT_STATE:
proto_tree_add_item(tree, hf_edonkey_emule_ident_state, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_edonkey_emule_rndchallenge, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case EMULE_MSG_PUBLIC_KEY:
dissect_edonkey_public_key(tvb, pinfo, offset, tree);
break;
case EMULE_MSG_SIGNATURE:
offset = dissect_edonkey_signature(tvb, pinfo, offset, tree);
if (msg_end != offset) {
proto_tree_add_item(tree, hf_edonkey_emule_sig_ip_used, tvb, offset, 1, ENC_NA);
}
break;
case EMULE_MSG_DATA_COMPRESSED:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_edonkey_packed_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (msg_end > offset) {
bytes_remaining = msg_end - offset;
proto_tree_add_item(tree, hf_edonkey_compressed_message_data, tvb, offset, bytes_remaining, ENC_NA);
}
break;
case EMULE_MSG_DATA_COMPRESSED_64:
offset = dissect_edonkey_file_hash(tvb, pinfo, offset, tree);
offset = dissect_edonkey_start_offset_64(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_edonkey_packed_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (msg_end > offset) {
bytes_remaining = msg_end - offset;
proto_tree_add_item(tree, hf_edonkey_compressed_message_data, tvb, offset, bytes_remaining, ENC_NA);
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
proto_tree_add_item(tree, hf_edonkey_message_data, tvb, offset, bytes_remaining, ENC_NA);
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
tvbuff_t *tvb, packet_info *pinfo,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
guint16 ischal;
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
proto_tree_add_item(tree, hf_edonkey_challenge, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
}
break;
case EDONKEY_MSG_UDP_SERVER_INFO:
ischal = tvb_get_letohs(tvb, offset);
if (ischal==0xf0ff) {
proto_tree_add_item(tree, hf_edonkey_challenge, tvb, offset, 4, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_edonkey_challenge, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case EDONKEY_MSG_UDP_SERVER_STATUS:
proto_tree_add_item(tree, hf_edonkey_challenge, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_edonkey_number_of_users, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_edonkey_number_of_files, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
offset += 8;
if (offset < msg_end) {
proto_tree_add_item(tree, hf_edonkey_max_number_of_users, tvb, offset, 4, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_edonkey_search_type, tvb, offset, 1, ENC_NA);
offset = dissect_edonkey_hash(tvb, pinfo, offset+1, tree);
break;
case OVERNET_MSG_UDP_SEARCH_INFO:
offset = dissect_edonkey_hash(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_edonkey_search_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_edonkey_search_range_min, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_edonkey_search_range_max, tvb, offset+3, 2, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(tree, hf_edonkey_message_data, tvb, offset, length, ENC_NA);
offset+=length;
break;
}
return offset;
}
static int dissect_emule_udp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo,
int offset, int length, proto_tree *tree)
{
int msg_end, bytes_remaining;
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
proto_tree_add_item(tree, hf_edonkey_emule_queue_ranking, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
default:
offset = dissect_edonkey_udp_message(msg_type, tvb, pinfo, offset, length,tree);
break;
}
return offset;
}
static int dissect_kademlia_peer_list_2byte(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Peer", dissect_kademlia_peer );
}
static int dissect_kademlia_peer_list_1byte(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Peer", dissect_kademlia_peer );
}
static int dissect_kademlia2_peer_list_2byte(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 2, "Peer", dissect_kademlia2_peer );
}
static int dissect_kademlia2_peer_list_1byte(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Peer", dissect_kademlia2_peer );
}
static int dissect_kademlia_tag(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
guint8 type;
guint8 tag_type;
const gchar *str_type;
proto_item *ti;
proto_item* tag_node;
proto_tree *subtree;
int item_start_offset;
proto_item * ti_tagtype;
item_start_offset = offset;
subtree = proto_tree_add_subtree( tree, tvb, offset, 1, ett_kademlia_tag, &tag_node, "Tag " );
type = tvb_get_guint8( tvb, offset );
str_type = val_to_str_const(type, kademlia_tag_types, "Unknown" );
ti_tagtype = proto_tree_add_item( subtree, hf_kademlia_tag_type, tvb, offset, 1, ENC_LITTLE_ENDIAN );
offset += 1;
{
const gchar *tagname_string;
const gchar *tagname_extended_string;
tag_type = tvb_get_guint8( tvb, offset+2 );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, subtree, &tagname_string, &tagname_extended_string );
if ( strlen( tagname_string ) == 1 ) {
const guint8 tagname_guint = *(const guint8*)tagname_string;
proto_item_append_text( tag_node, " 0x%02X [%s] = ", tagname_guint, tagname_extended_string );
}
else
proto_item_append_text( tag_node, " \"%s\" [%s] = ", tagname_string, tagname_extended_string );
}
switch( type )
{
case KADEMLIA_TAGTYPE_HASH:
proto_item_append_text( tag_node, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, 16 ));
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
proto_item_append_text(ti," (%s)", val_to_str_const(value, kademlia_tag_sourcetype, "Unknown"));
}
break;
case KADEMLIA_TAG_ENCRYPTION:
proto_item_append_text(ti, " (%s)", val_to_str_const(value, kademlia_tag_encryption, "Unknown"));
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
expert_add_info_format(pinfo, ti_tagtype, &ei_kademlia_tag_type, "Tag value not decoded for type: 0x%02X", type );
}
proto_item_append_text( tag_node, " (Type: %s)", str_type );
proto_item_set_len( tag_node, offset - item_start_offset );
return offset;
}
static int dissect_kademlia_taglist(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
return dissect_edonkey_list(tvb, pinfo, offset, tree, 1, "Tag", dissect_kademlia_tag );
}
static int dissect_kademlia_publish_req_entry_file(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_file_id);
return dissect_kademlia_taglist( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_publish_req_entry_peer(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_peer_id);
return dissect_kademlia_taglist( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_search_result(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_hash);
return dissect_kademlia_taglist( tvb, pinfo, offset, tree );
}
static int dissect_kademlia_search_expression_tree(tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
int op, item_start_offset;
proto_item* ti;
item_start_offset = offset;
op = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint(tree, hf_kademlia_search_expression_type, tvb, offset, 1, op);
tree = proto_item_add_subtree( ti, ett_kademlia_search_expression );
++offset;
switch( op ) {
case 0:
proto_tree_add_item(tree, hf_kademlia_search_bool_op, tvb, offset, 1, ENC_NA );
++offset;
offset = dissect_kademlia_search_expression_tree( tvb, pinfo, offset, tree );
offset = dissect_kademlia_search_expression_tree( tvb, pinfo, offset, tree );
break;
case 1:
offset = dissect_kademlia_string( tvb, pinfo, offset, tree );
break;
case 2:
offset = dissect_edonkey_string( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, tree, NULL, NULL );
break;
case 3:
offset = dissect_kademlia_search_condition_argument_uint32( tvb, pinfo, offset, tree );
offset = dissect_kademlia_search_condition( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, tree, NULL, NULL );
break;
case 8:
offset = dissect_kademlia_search_condition_argument_uint64( tvb, pinfo, offset, tree );
offset = dissect_kademlia_search_condition( tvb, pinfo, offset, tree );
offset = dissect_kademlia_tagname( tvb, pinfo, offset, tree, NULL, NULL );
break;
default:
expert_add_info_format(pinfo, ti, &ei_kademlia_search_expression_type, "NOT DECODED op %x", op );
}
proto_item_set_len( ti, offset - item_start_offset );
return offset;
}
static int dissect_kademlia2_prolog( tvbuff_t *tvb, packet_info *pinfo,
int offset, proto_tree *tree)
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_peer_id);
offset = dissect_kademlia_tcp_port(tvb, pinfo, offset, tree);
proto_tree_add_item(tree, hf_kademlia_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int dissect_kademlia_uload( tvbuff_t *tvb, packet_info *pinfo _U_,
int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_edonkey_kademlia_uload, tvb, offset, 1, ENC_NA);
return offset +1;
}
static int dissect_kademlia_udp_message(guint8 msg_type,
tvbuff_t *tvb, packet_info *pinfo,
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
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
proto_tree_add_item(tree, hf_edonkey_kademlia_start_position, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_edonkey_kademlia_filesize, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset +=8;
}
break;
case KADEMLIA_SEARCH_NOTES_REQ:
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_hash);
break;
case KADEMLIA2_SEARCH_KEY_REQ:
{
offset = dissect_kademlia_hash(tvb, pinfo, offset, tree, &hf_kademlia_target_id);
proto_tree_add_item(tree, hf_edonkey_kademlia_start_position, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
proto_item_append_text(ti, "%s", val_to_str_const(type, kademlia_parameter, " Unknown"));
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
proto_tree_add_string(tree, hf_kademlia_distance, tvb, offset, 0, binarray);
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
proto_tree_add_item(tree, hf_edonkey_kademlia_restrictive, tvb, offset, 1, ENC_NA);
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
tvbuff_t *tvb, packet_info *pinfo,
int offset, int length, proto_tree *tree)
{
tvbuff_t *tvbraw = NULL;
tvbraw = tvb_child_uncompress(tvb, tvb, offset, length);
if (tvbraw) {
guint32 raw_length;
raw_length = tvb_captured_length( tvbraw );
add_new_data_source(pinfo, tvbraw, "Decompressed Data");
dissect_kademlia_udp_message( msg_type, tvbraw, pinfo, 0, raw_length, tree );
offset += length;
} else {
proto_tree_add_item(tree, hf_edonkey_broken_compressed_data, tvb, offset, length, ENC_NA);
}
return offset;
}
static guint get_edonkey_tcp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 msg_len;
msg_len = tvb_get_letohl(tvb, offset+1);
return msg_len + EDONKEY_TCP_HEADER_LENGTH;
}
static int dissect_edonkey_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *edonkey_tree, *edonkey_msg_tree = NULL, *emule_zlib_tree = NULL;
int offset;
guint8 protocol, msg_type;
guint32 msg_len;
const gchar *protocol_name, *message_name;
void (*dissector)(guint8, tvbuff_t*, packet_info*, int, int, proto_tree*);
tvbuff_t *tvbraw = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "eDonkey");
ti = proto_tree_add_item(tree, proto_edonkey, tvb, 0, -1, ENC_NA);
edonkey_tree = proto_item_add_subtree(ti, ett_edonkey);
offset = 0;
protocol = tvb_get_guint8(tvb, offset);
msg_len = tvb_get_letohl(tvb, offset+1);
protocol_name = val_to_str_const(protocol, edonkey_protocols, "Unknown");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ", "%s TCP", protocol_name);
if (edonkey_tree) {
ti = proto_tree_add_item(edonkey_tree, hf_edonkey_message, tvb,
offset, EDONKEY_TCP_HEADER_LENGTH + msg_len, ENC_NA);
edonkey_msg_tree = proto_item_add_subtree(ti, ett_edonkey_message);
proto_tree_add_uint(edonkey_msg_tree, hf_edonkey_protocol, tvb, offset, 1, protocol);
proto_tree_add_uint(edonkey_msg_tree, hf_edonkey_message_length, tvb, offset+1, 4, msg_len);
}
offset += EDONKEY_TCP_HEADER_LENGTH;
msg_type = tvb_get_guint8(tvb, offset);
switch (protocol) {
case EDONKEY_PROTO_EDONKEY:
message_name = val_to_str_const(msg_type, edonkey_tcp_msgs, "Unknown");
dissector = dissect_edonkey_tcp_message;
break;
case EDONKEY_PROTO_EMULE_EXT:
message_name = val_to_str_const(msg_type, emule_tcp_msgs,
val_to_str_const(msg_type, edonkey_tcp_msgs, "Unknown"));
dissector = dissect_emule_tcp_message;
break;
case EDONKEY_PROTO_EMULE_COMP:
message_name = val_to_str_const(msg_type, edonkey_tcp_msgs, "Unknown");
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
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", message_name);
if (edonkey_msg_tree) {
proto_tree_add_uint_format_value(edonkey_msg_tree, hf_edonkey_message_type, tvb, offset, 1, msg_type,
"%s (0x%02x)", message_name, msg_type);
if (dissector && (msg_len > 1)) {
if (!tvbraw) {
(*dissector)(msg_type, tvb, pinfo, offset+1, msg_len-1, edonkey_msg_tree);
} else {
ti = proto_tree_add_item(edonkey_msg_tree, hf_emule_zlib, tvb,
offset+1, msg_len-1, ENC_NA);
emule_zlib_tree = proto_item_add_subtree(ti, ett_emule_zlib);
add_new_data_source(pinfo, tvbraw, "Decompressed Data");
(*dissector)(msg_type, tvbraw, pinfo, 0, tvb_captured_length(tvbraw), emule_zlib_tree);
}
}
}
return tvb_captured_length(tvb);
}
static int dissect_edonkey_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint8 protocol;
if (!tvb_bytes_exist(tvb, 0, EDONKEY_TCP_HEADER_LENGTH))
return 0;
protocol = tvb_get_guint8(tvb, 0);
if (try_val_to_str(protocol, edonkey_protocols) == NULL)
return 0;
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, edonkey_desegment,
EDONKEY_TCP_HEADER_LENGTH, get_edonkey_tcp_pdu_len,
dissect_edonkey_tcp_pdu, data);
return tvb_reported_length(tvb);
}
static int dissect_edonkey_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *edonkey_tree = NULL, *edonkey_msg_tree = NULL;
int offset = 0;
guint8 protocol, msg_type;
const gchar *protocol_name, *message_name;
if (!tvb_bytes_exist(tvb, 0, EDONKEY_UDP_HEADER_LENGTH))
return 0;
protocol = tvb_get_guint8(tvb, offset);
if (try_val_to_str(protocol, edonkey_protocols) == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "eDonkey");
if (tree) {
ti = proto_tree_add_item(tree, proto_edonkey, tvb, 0, -1, ENC_NA);
edonkey_tree = proto_item_add_subtree(ti, ett_edonkey);
}
offset = 0;
msg_type = tvb_get_guint8(tvb, offset+1);
protocol_name = val_to_str_const(protocol, edonkey_protocols, "Unknown");
if (protocol == EDONKEY_PROTO_KADEMLIA || protocol == EDONKEY_PROTO_KADEMLIA_COMP
|| protocol == EDONKEY_PROTO_ADU_KADEMLIA || protocol == EDONKEY_PROTO_ADU_KADEMLIA_COMP)
message_name = val_to_str_const( msg_type, kademlia_msgs, "Unknown");
else
message_name = val_to_str_const(msg_type, edonkey_udp_msgs, "Unknown");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s UDP: %s", protocol_name, message_name);
if (edonkey_tree) {
int remainingLength, extraBytes;
ti = proto_tree_add_item(edonkey_tree, hf_edonkey_message, tvb, offset, -1, ENC_NA);
edonkey_msg_tree = proto_item_add_subtree(ti, ett_edonkey_message);
proto_tree_add_uint(edonkey_msg_tree, hf_edonkey_protocol, tvb, offset, 1, protocol);
proto_tree_add_uint_format_value(edonkey_msg_tree, hf_edonkey_message_type, tvb, offset+1, 1, msg_type,
"%s (0x%02x)", message_name, msg_type);
offset += EDONKEY_UDP_HEADER_LENGTH;
remainingLength = tvb_captured_length_remaining( tvb, offset );
if (remainingLength > 0) {
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
}
extraBytes = tvb_reported_length_remaining( tvb, offset );
if ( extraBytes > 0 ) {
proto_tree_add_uint_format(tree, hf_edonkey_unparsed_data_length, tvb, offset, extraBytes, extraBytes,
"Trailing/Undecoded data: %d bytes", extraBytes );
}
}
return tvb_reported_length(tvb);
}
static void
edonkey_fmt_revision(gchar *result, guint32 revision )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%u.%u", (guint16)(revision & 0xFFFF), (guint16)(( revision & 0xFFFF0000 ) >> 16) );
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
FT_STRING, STR_ASCII, NULL, 0, "eDonkey Meta Tag Name", HFILL } },
{ &hf_edonkey_metatag_namesize,
{ "Meta Tag Name Size", "edonkey.metatag.namesize",
FT_UINT16, BASE_DEC, NULL, 0, "eDonkey Meta Tag Name Size", HFILL } },
{ &hf_edonkey_hash,
{ "Hash", "edonkey.hash",
FT_BYTES, BASE_NONE, NULL, 0, "eDonkey Hash", HFILL } },
{ &hf_edonkey_string,
{ "String", "edonkey.string",
FT_STRING, STR_ASCII, NULL, 0, "eDonkey String", HFILL } },
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
FT_STRING, STR_ASCII, NULL, 0, "eDonkey Directory", HFILL } },
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
FT_STRING, STR_ASCII, NULL, 0, "Kademlia Peer ID", HFILL } },
{ &hf_kademlia_hash,
{ "Kademlia Hash", "edonkey.kademlia.hash",
FT_STRING, STR_ASCII, NULL, 0, NULL, HFILL } },
{ &hf_kademlia_file_id,
{ "File ID", "edonkey.kademlia.file.id",
FT_STRING, STR_ASCII, NULL, 0, "Kademlia File ID", HFILL } },
{ &hf_kademlia_keyword_hash,
{ "Keyword Hash", "edonkey.kademlia.keyword.hash",
FT_STRING, STR_ASCII, NULL, 0, "Kademlia Keyword Hash", HFILL } },
{ &hf_kademlia_recipients_id,
{ "Recipient's ID", "edonkey.kademlia.recipients.id",
FT_STRING, STR_ASCII, NULL, 0, "Kademlia Recipient's ID", HFILL } },
{ &hf_kademlia_sender_id,
{ "Sender ID", "edonkey.kademlia.sender.id",
FT_STRING, STR_ASCII, NULL, 0, "Kademlia Sender ID", HFILL } },
{ &hf_kademlia_target_id,
{ "Target ID", "edonkey.kademlia.target.id",
FT_STRING, STR_ASCII, NULL, 0, "Kademlia Target ID", HFILL } },
{ &hf_kademlia_distance,
{ "XOR Distance", "edonkey.kademlia.distance",
FT_STRING, STR_ASCII, NULL, 0, "Kademlia XOR Distance", HFILL } },
{ &hf_kademlia_version,
{ "Kad Version", "edonkey.kademlia.version",
FT_UINT8, BASE_DEC_HEX, VALS(kademlia_versions), 0, NULL, HFILL } },
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
FT_STRING, STR_ASCII, NULL, 0, "String Tag Value", HFILL } },
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
#if 0
{ &hf_kademlia_unparsed_data_length,
{ "Kademlia unparsed data length", "edonkey.kademlia.unparsed",
FT_UINT16, BASE_DEC, NULL, 0, "Kademlia trailing data length", HFILL } },
#endif
{ &hf_kademlia_tag_name,
{ "Tag Name", "edonkey.kademlia.tag.name",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Tag Name String", HFILL } },
{ &hf_kademlia_tag_name_length,
{ "Tag Name Length", "edonkey.kademlia.tag.name.length",
FT_UINT16, BASE_DEC, NULL, 0, "Kademlia Tag Name String Length", HFILL } },
{ &hf_kademlia_tag_type,
{ "Tag Type", "edonkey.kademlia.tag.type",
FT_UINT8, BASE_HEX, VALS(kademlia_tag_types), 0, "Kademlia Tag Type", HFILL } },
{ &hf_kademlia_request_type,
{ "Request Type", "edonkey.kademlia.request.type",
FT_UINT8, BASE_HEX, NULL, 0, "Kademlia Request Type", HFILL } },
{ &hf_kademlia_search_expression_type,
{ "SearchExp Type", "edonkey.kademlia.search_expression.type",
FT_UINT8, BASE_HEX, VALS(edonkey_search_ext_type_vals), 0, NULL, HFILL } },
{ &hf_kademlia_search_bool_op,
{ "Bool op", "edonkey.kademlia.search.bool_op",
FT_UINT8, BASE_HEX, VALS(edonkey_search_ops), 0, NULL, HFILL } },
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
{ &hf_edonkey_list_size, { "List Size", "edonkey.list_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_meta_tag_value_revision, { "Meta Tag Value", "edonkey.meta_tag_value.revision", FT_UINT32, BASE_CUSTOM, CF_FUNC(edonkey_fmt_revision), 0x0, NULL, HFILL }},
{ &hf_edonkey_meta_tag_value_uint, { "Meta Tag Value", "edonkey.meta_tag_value.uint", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_boolean_array_length, { "Boolean Array Length", "edonkey.boolean_array_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_blob_length, { "BLOB Length", "edonkey.blob_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_kademlia_string, { "String", "edonkey.kademlia_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_emule_public_key_length, { "Public key length", "edonkey.emule.public_key_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_emule_signature_length, { "Signature length", "edonkey.emule.signature_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_obfuscation_settings, { "Obfuscation Settings", "edonkey.obfuscation_settings", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_start_offset, { "Start Offset", "edonkey.start_offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_start_offset_64, { "Start Offset", "edonkey.start_offset64", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_end_offset, { "End Offset", "edonkey.end_offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_end_offset_64, { "End Offset", "edonkey.end_offset64", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_emule_file_length, { "File Length", "edonkey.emule.file_length", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_overnet_peer_type, { "Peer Type", "edonkey.overnet_peer_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_more_search_file_results, { "More", "edonkey.more_search_file_results", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x0, NULL, HFILL }},
{ &hf_edonkey_file_size, { "File size", "edonkey.file_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_large_file_size, { "Large file size", "edonkey.large_file_size", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_number_of_users, { "Number of Users", "edonkey.number_of_users", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_number_of_files, { "Number of Files", "edonkey.number_of_files", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_message_data, { "Message Data", "edonkey.message_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_emule_version, { "Version", "edonkey.emule.version", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_emule_queue_ranking, { "Queue Ranking", "edonkey.emule.queue_ranking", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_emule_ident_state, { "State", "edonkey.emule.state", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(emule_ident_state_rvals), 0x0, NULL, HFILL }},
{ &hf_edonkey_emule_rndchallenge, { "Rndchallenge", "edonkey.emule.rndchallenge", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_emule_sig_ip_used, { "Sig IP Used", "edonkey.emule.sig_ip_used", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_packed_length, { "Packed Length", "edonkey.emule.packed_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_compressed_message_data, { "Compressed Message Data", "edonkey.emule.compressed_message_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_challenge, { "Challenge", "edonkey.challenge", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_max_number_of_users, { "Max number of Users", "edonkey.max_number_of_users", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_search_type, { "Search Type", "edonkey.search_type", FT_UINT8, BASE_DEC, VALS(edonkey_search_type_vals), 0x0, NULL, HFILL }},
{ &hf_edonkey_search_range_min, { "Search Range Min", "edonkey.search_range.min", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_search_range_max, { "Search Range Max", "edonkey.search_range.max", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_kademlia_uload, { "uLoad", "edonkey.kademlia_uload", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_kademlia_start_position, { "Start position", "edonkey.kademlia_start_position", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_kademlia_filesize, { "Filesize", "edonkey.kademlia_filesize", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_kademlia_restrictive, { "Restrictive", "edonkey.kademlia_restrictive", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_broken_compressed_data, { "Broken Compressed data", "edonkey.broken_compressed_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_search_limit, { "Search Limit", "edonkey.search_limit", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_edonkey_search_limit_type, { "Limit Type", "edonkey.search_limit_type", FT_UINT8, BASE_DEC, VALS(edonkey_search_conds), 0x0, NULL, HFILL }},
{ &hf_edonkey_search_ops, { "Search Operator", "edonkey.search_ops", FT_UINT8, BASE_HEX, VALS(edonkey_search_ops), 0x0, NULL, HFILL }},
{ &hf_edonkey_user_hash_length, { "User hash length", "edonkey.user_hash_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
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
static ei_register_info ei[] = {
{ &ei_kademlia_tag_type, { "edonkey.kademlia.tag.type.undecoded", PI_PROTOCOL, PI_WARN, "Tag value not decoded", EXPFILL }},
{ &ei_kademlia_search_expression_type, { "edonkey.kademlia.search_expression.type.undecoded", PI_UNDECODED, PI_WARN, "NOT DECODED op", EXPFILL }},
};
module_t *edonkey_module;
expert_module_t* expert_edonkey;
proto_edonkey = proto_register_protocol("eDonkey Protocol", "EDONKEY", "edonkey");
proto_register_field_array(proto_edonkey, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_edonkey = expert_register_protocol(proto_edonkey);
expert_register_field_array(expert_edonkey, ei, array_length(ei));
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
edonkey_tcp_handle = create_dissector_handle(dissect_edonkey_tcp, proto_edonkey);
edonkey_udp_handle = create_dissector_handle(dissect_edonkey_udp, proto_edonkey);
dissector_add_uint("tcp.port", 4661, edonkey_tcp_handle);
dissector_add_uint("tcp.port", 4662, edonkey_tcp_handle);
dissector_add_uint("tcp.port", 4663, edonkey_tcp_handle);
dissector_add_uint("udp.port", 4665, edonkey_udp_handle);
dissector_add_uint("udp.port", 4672, edonkey_udp_handle);
}
