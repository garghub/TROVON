TreeItem push_TreeItem(lua_State *L, proto_tree *tree, proto_item *item) {
TreeItem ti = (struct _wslua_treeitem *)g_malloc(sizeof(struct _wslua_treeitem));
ti->tree = tree;
ti->item = item;
ti->expired = FALSE;
g_ptr_array_add(outstanding_TreeItem, ti);
return *(pushTreeItem(L,ti));
}
TreeItem create_TreeItem(proto_tree* tree, proto_item* item)
{
TreeItem tree_item = (TreeItem)g_malloc(sizeof(struct _wslua_treeitem));
tree_item->tree = tree;
tree_item->item = item;
tree_item->expired = FALSE;
return tree_item;
}
static proto_item *
try_add_packet_field(lua_State *L, TreeItem tree_item, TvbRange tvbr, const int hfid,
const ftenum_t type, const guint encoding, gint *ret_err)
{
gint err = 0;
proto_item* item = NULL;
gint endoff = 0;
switch(type) {
case FT_BYTES:
case FT_UINT_BYTES:
case FT_OID:
case FT_REL_OID:
case FT_SYSTEM_ID:
{
GByteArray *gba = g_byte_array_new();
item = proto_tree_add_bytes_item(tree_item->tree, hfid, tvbr->tvb->ws_tvb,
tvbr->offset, tvbr->len, encoding,
gba, &endoff, &err);
if (err == 0) {
pushByteArray(L, gba);
lua_pushinteger(L, endoff);
}
}
break;
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
{
nstime_t *nstime = (nstime_t *) g_malloc0(sizeof(nstime_t));
item = proto_tree_add_time_item(tree_item->tree, hfid, tvbr->tvb->ws_tvb,
tvbr->offset, tvbr->len, encoding,
nstime, &endoff, &err);
if (err == 0) {
pushNSTime(L,nstime);
lua_pushinteger(L, endoff);
}
}
break;
case FT_NONE:
case FT_PROTOCOL:
default:
item = proto_tree_add_item(tree_item->tree, hfid, tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len, encoding);
lua_pushnil(L);
lua_pushnil(L);
break;
}
if (ret_err) *ret_err = err;
return item;
}
WSLUA_METHOD TreeItem_add_packet_field(lua_State *L) {
#define WSLUA_ARG_TreeItem_add_packet_field_PROTOFIELD 2
#define WSLUA_OPTARG_TreeItem_add_packet_field_TVBRANGE 3
#define WSLUA_ARG_TreeItem_add_packet_field_ENCODING 4
#define WSLUA_OPTARG_TreeItem_add_packet_field_LABEL 5
volatile TvbRange tvbr;
ProtoField field;
int hfid;
volatile int ett;
ftenum_t type;
TreeItem tree_item = shiftTreeItem(L,1);
guint encoding;
proto_item* item = NULL;
volatile int nargs;
volatile gint err = 0;
const char *volatile error = NULL;
if (!tree_item) {
return luaL_error(L,"not a TreeItem!");
}
if (tree_item->expired) {
luaL_error(L,"expired TreeItem");
return 0;
}
if (! ( field = shiftProtoField(L,1) ) ) {
luaL_error(L,"TreeField:add_packet_field not passed a ProtoField");
return 0;
}
hfid = field->hfid;
type = field->type;
ett = field->ett;
tvbr = shiftTvbRange(L,1);
if (!tvbr) {
tvbr = wmem_new(wmem_packet_scope(), struct _wslua_tvbrange);
tvbr->tvb = wmem_new(wmem_packet_scope(), struct _wslua_tvb);
tvbr->tvb->ws_tvb = lua_tvb;
tvbr->offset = 0;
tvbr->len = 0;
}
encoding = wslua_checkguint(L,1);
lua_remove(L,1);
nargs = lua_gettop(L);
if (type == FT_STRINGZ) {
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_UTF_16:
case ENC_UCS_2:
tvbr->len = tvb_unicode_strsize (tvbr->tvb->ws_tvb, tvbr->offset);
break;
default:
if (tvb_find_guint8 (tvbr->tvb->ws_tvb, tvbr->offset, -1, 0) == -1) {
luaL_error(L,"out of bounds");
return 0;
}
tvbr->len = tvb_strsize (tvbr->tvb->ws_tvb, tvbr->offset);
break;
}
}
TRY {
gint errx = 0;
item = try_add_packet_field(L, tree_item, tvbr, hfid, type, encoding, &errx);
err = errx;
} CATCH_ALL {
show_exception(tvbr->tvb->ws_tvb, lua_pinfo, tree_item->tree, EXCEPT_CODE, GET_MESSAGE);
error = "Lua programming error";
} ENDTRY;
if (error) { WSLUA_ERROR(TreeItem_add_packet_field,error); }
if (err != 0) {
lua_pushnil(L);
lua_pushnil(L);
}
while(nargs) {
const gchar* s;
s = lua_tostring(L,1);
if (s) proto_item_append_text(item, " %s", s);
lua_remove(L,1);
nargs--;
}
push_TreeItem(L, proto_item_add_subtree(item,ett > 0 ? ett : wslua_ett), item);
lua_insert(L, 1);
WSLUA_RETURN(3);
}
static int TreeItem_add_item_any(lua_State *L, gboolean little_endian) {
TvbRange tvbr;
Proto proto;
ProtoField field;
int hfid = -1;
int ett = -1;
ftenum_t type = FT_NONE;
TreeItem tree_item = shiftTreeItem(L,1);
proto_item* item = NULL;
if (!tree_item) {
return luaL_error(L,"not a TreeItem!");
}
if (tree_item->expired) {
luaL_error(L,"expired TreeItem");
return 0;
}
if (! ( field = shiftProtoField(L,1) ) ) {
if (( proto = shiftProto(L,1) )) {
hfid = proto->hfid;
type = FT_PROTOCOL;
ett = proto->ett;
}
} else {
hfid = field->hfid;
type = field->type;
ett = field->ett;
}
tvbr = shiftTvbRange(L,1);
if (!tvbr) {
tvbr = wmem_new(wmem_packet_scope(), struct _wslua_tvbrange);
tvbr->tvb = wmem_new(wmem_packet_scope(), struct _wslua_tvb);
tvbr->tvb->ws_tvb = lua_tvb;
tvbr->offset = 0;
tvbr->len = 0;
}
if (hfid > 0 ) {
if (type == FT_STRINGZ) {
if (tvb_find_guint8 (tvbr->tvb->ws_tvb, tvbr->offset, -1, 0) == -1) {
luaL_error(L,"out of bounds");
return 0;
}
tvbr->len = tvb_strsize (tvbr->tvb->ws_tvb, tvbr->offset);
}
if (lua_gettop(L)) {
switch(type) {
case FT_PROTOCOL:
item = proto_tree_add_item(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,ENC_NA);
lua_pushnumber(L,0);
lua_insert(L,1);
break;
case FT_BOOLEAN:
{
guint32 val = (guint32) (wslua_tointeger(L,1));
item = proto_tree_add_boolean(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,val);
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
item = proto_tree_add_uint(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,wslua_checkguint32(L,1));
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
item = proto_tree_add_int(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,wslua_checkguint32(L,1));
break;
case FT_FLOAT:
item = proto_tree_add_float(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,(float)luaL_checknumber(L,1));
break;
case FT_DOUBLE:
item = proto_tree_add_double(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,(double)luaL_checknumber(L,1));
break;
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
item = proto_tree_add_time(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,checkNSTime(L,1));
break;
case FT_STRING:
case FT_STRINGZ:
item = proto_tree_add_string(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,luaL_checkstring(L,1));
break;
case FT_BYTES:
item = proto_tree_add_bytes(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len, (const guint8*) luaL_checkstring(L,1));
break;
case FT_UINT64:
item = proto_tree_add_uint64(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,checkUInt64(L,1));
break;
case FT_INT64:
item = proto_tree_add_int64(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,checkInt64(L,1));
break;
case FT_IPv4:
item = proto_tree_add_ipv4(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,*((const guint32*)(checkAddress(L,1)->data)));
break;
case FT_ETHER:
case FT_UINT_BYTES:
case FT_IPv6:
case FT_IPXNET:
case FT_GUID:
case FT_OID:
case FT_REL_OID:
case FT_SYSTEM_ID:
case FT_VINES:
case FT_FCWWN:
default:
luaL_error(L,"FT_ not yet supported");
return 0;
}
lua_remove(L,1);
} else {
if (type == FT_FRAMENUM) {
luaL_error(L, "ProtoField FRAMENUM cannot fetch value from Tvb");
return 0;
}
item = proto_tree_add_item(tree_item->tree, hfid, tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
}
if ( lua_gettop(L) ) {
const gchar* s = lua_tostring(L,1);
if (s) proto_item_set_text(item,"%s",s);
lua_remove(L,1);
}
} else {
if (lua_gettop(L)) {
const gchar* s = lua_tostring(L,1);
const int hf = get_hf_wslua_text();
if (hf > -1) {
item = proto_tree_add_item(tree_item->tree, hf, tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len, ENC_NA);
proto_item_set_text(item, "%s", s);
} else {
luaL_error(L,"Internal error: hf_wslua_text not registered");
}
lua_remove(L,1);
} else {
luaL_error(L,"Tree item ProtoField/Protocol handle is invalid (ProtoField/Proto not registered?)");
}
}
while(lua_gettop(L)) {
const gchar* s = lua_tostring(L,1);
if (s) proto_item_append_text(item, " %s", s);
lua_remove(L,1);
}
push_TreeItem(L, proto_item_add_subtree(item,ett > 0 ? ett : wslua_ett), item);
return 1;
}
WSLUA_METHOD TreeItem_add(lua_State *L) {
#define WSLUA_OPTARG_TreeItem_add_PROTOFIELD 2
#define WSLUA_OPTARG_TreeItem_add_TVBRANGE 3
#define WSLUA_OPTARG_TreeItem_add_VALUE 4
#define WSLUA_OPTARG_TreeItem_add_LABEL 5
WSLUA_RETURN(TreeItem_add_item_any(L,FALSE));
}
WSLUA_METHOD TreeItem_add_le(lua_State *L) {
#define WSLUA_OPTARG_TreeItem_add_le_PROTOFIELD 2
#define WSLUA_OPTARG_TreeItem_add_le_TVBRANGE 3
#define WSLUA_OPTARG_TreeItem_add_le_VALUE 4
#define WSLUA_OPTARG_TreeItem_add_le_LABEL 5
WSLUA_RETURN(TreeItem_add_item_any(L,TRUE));
}
static int TreeItem_get_text(lua_State* L) {
TreeItem ti = checkTreeItem(L,1);
gchar label_str[ITEM_LABEL_LENGTH+1];
gchar *label_ptr;
field_info *fi = PITEM_FINFO(ti->item);
if(fi) {
if (!fi->rep) {
label_ptr = label_str;
proto_item_fill_label(fi, label_str);
} else
label_ptr = fi->rep->representation;
if (label_ptr) {
lua_pushstring(L, label_ptr);
} else {
lua_pushnil(L);
}
} else {
lua_pushnil(L);
}
return 1;
}
WSLUA_METHOD TreeItem_set_text(lua_State *L) {
#define WSLUA_ARG_TreeItem_set_text_TEXT 2
TreeItem ti = checkTreeItem(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_TreeItem_set_text_TEXT);
proto_item_set_text(ti->item,"%s",s);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_append_text(lua_State *L) {
#define WSLUA_ARG_TreeItem_append_text_TEXT 2
TreeItem ti = checkTreeItem(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_TreeItem_append_text_TEXT);
proto_item_append_text(ti->item,"%s",s);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_prepend_text(lua_State *L) {
#define WSLUA_ARG_TreeItem_prepend_text_TEXT 2
TreeItem ti = checkTreeItem(L,1);
const gchar* s = luaL_checkstring(L,WSLUA_ARG_TreeItem_prepend_text_TEXT);
proto_item_prepend_text(ti->item,"%s",s);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_add_expert_info(lua_State *L) {
#define WSLUA_OPTARG_TreeItem_add_expert_info_GROUP 2
#define WSLUA_OPTARG_TreeItem_add_expert_info_SEVERITY 3
#define WSLUA_OPTARG_TreeItem_add_expert_info_TEXT 4
TreeItem ti = checkTreeItem(L,1);
int group = (int)luaL_optinteger(L,WSLUA_OPTARG_TreeItem_add_expert_info_GROUP,PI_DEBUG);
int severity = (int)luaL_optinteger(L,WSLUA_OPTARG_TreeItem_add_expert_info_SEVERITY,PI_CHAT);
expert_field* ei_info = wslua_get_expert_field(group, severity);
const gchar* str;
if (lua_gettop(L) >= WSLUA_OPTARG_TreeItem_add_expert_info_TEXT) {
str = wslua_checkstring_only(L, WSLUA_OPTARG_TreeItem_add_expert_info_TEXT);
expert_add_info_format(lua_pinfo, ti->item, ei_info, "%s", str);
} else {
expert_add_info(lua_pinfo, ti->item, ei_info);
}
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_add_proto_expert_info(lua_State *L) {
#define WSLUA_ARG_TreeItem_add_proto_expert_info_EXPERT 2
#define WSLUA_OPTARG_TreeItem_add_proto_expert_info_TEXT 3
TreeItem ti = checkTreeItem(L,1);
ProtoExpert expert = checkProtoExpert(L,WSLUA_ARG_TreeItem_add_proto_expert_info_EXPERT);
const gchar* str;
if (expert->ids.ei == EI_INIT_EI || expert->ids.hf == EI_INIT_HF) {
luaL_error(L, "ProtoExpert is not registered");
return 0;
}
if (lua_gettop(L) >= WSLUA_OPTARG_TreeItem_add_proto_expert_info_TEXT) {
str = wslua_checkstring_only(L, WSLUA_OPTARG_TreeItem_add_proto_expert_info_TEXT);
expert_add_info_format(lua_pinfo, ti->item, &expert->ids, "%s", str);
} else {
expert_add_info(lua_pinfo, ti->item, &expert->ids);
}
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_add_tvb_expert_info(lua_State *L) {
#define WSLUA_ARG_TreeItem_add_tvb_expert_info_EXPERT 2
#define WSLUA_ARG_TreeItem_add_tvb_expert_info_TVB 3
#define WSLUA_OPTARG_TreeItem_add_tvb_expert_info_TEXT 4
TreeItem ti = checkTreeItem(L,1);
ProtoExpert expert = checkProtoExpert(L,WSLUA_ARG_TreeItem_add_proto_expert_info_EXPERT);
TvbRange tvbr;
const gchar* str;
if (expert->ids.ei == EI_INIT_EI || expert->ids.hf == EI_INIT_HF) {
luaL_error(L, "ProtoExpert is not registered");
return 0;
}
tvbr = shiftTvbRange(L,WSLUA_ARG_TreeItem_add_tvb_expert_info_TVB);
if (!tvbr) {
tvbr = wmem_new(wmem_packet_scope(), struct _wslua_tvbrange);
tvbr->tvb = shiftTvb(L,WSLUA_ARG_TreeItem_add_tvb_expert_info_TVB);
if (!tvbr->tvb) {
tvbr->tvb = wmem_new(wmem_packet_scope(), struct _wslua_tvb);
}
tvbr->tvb->ws_tvb = lua_tvb;
tvbr->offset = 0;
tvbr->len = 0;
}
if (lua_gettop(L) >= WSLUA_OPTARG_TreeItem_add_proto_expert_info_TEXT) {
str = wslua_checkstring_only(L, WSLUA_OPTARG_TreeItem_add_proto_expert_info_TEXT);
proto_tree_add_expert_format(ti->tree, lua_pinfo, &expert->ids,
tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len,
"%s", str);
} else {
proto_tree_add_expert(ti->tree, lua_pinfo, &expert->ids,
tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len);
}
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
static int TreeItem_get_visible(lua_State* L) {
TreeItem ti = checkTreeItem(L,1);
if (ti->tree) {
lua_pushboolean(L, PTREE_DATA(ti->tree)->visible);
}
else {
lua_pushboolean(L, FALSE);
}
return 1;
}
static int TreeItem_get_generated(lua_State* L) {
TreeItem ti = checkTreeItem(L,1);
lua_pushboolean(L, PROTO_ITEM_IS_GENERATED(ti->item));
return 1;
}
WSLUA_METHOD TreeItem_set_generated(lua_State *L) {
#define WSLUA_OPTARG_TreeItem_set_generated_BOOL 2
TreeItem ti = checkTreeItem(L,1);
gboolean set = wslua_optbool(L, WSLUA_OPTARG_TreeItem_set_generated_BOOL, TRUE);
if (set) {
PROTO_ITEM_SET_GENERATED(ti->item);
} else {
if (ti->item)
FI_RESET_FLAG(PITEM_FINFO(ti->item), FI_GENERATED);
}
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
static int TreeItem_get_hidden(lua_State* L) {
TreeItem ti = checkTreeItem(L,1);
lua_pushboolean(L, PROTO_ITEM_IS_HIDDEN(ti->item));
return 1;
}
WSLUA_METHOD TreeItem_set_hidden(lua_State *L) {
#define WSLUA_OPTARG_TreeItem_set_hidden_BOOL 2
TreeItem ti = checkTreeItem(L,1);
gboolean set = wslua_optbool(L, WSLUA_OPTARG_TreeItem_set_hidden_BOOL, TRUE);
if (set) {
PROTO_ITEM_SET_HIDDEN(ti->item);
} else {
PROTO_ITEM_SET_VISIBLE(ti->item);
}
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
static int TreeItem_get_len(lua_State* L) {
TreeItem ti = checkTreeItem(L,1);
int len = 0;
len = proto_item_get_len(ti->item);
lua_pushinteger(L, len > 0 ? len : 0);
return 1;
}
WSLUA_METHOD TreeItem_set_len(lua_State *L) {
#define WSLUA_ARG_TreeItem_set_len_LEN 2
TreeItem ti = checkTreeItem(L,1);
gint len = (int)luaL_checkinteger(L,WSLUA_ARG_TreeItem_set_len_LEN);
proto_item_set_len(ti->item, len);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD TreeItem__tostring(lua_State* L) {
TreeItem ti = toTreeItem(L,1);
if (ti) {
lua_pushfstring(L,
"TreeItem: expired=%s, has item=%s, has subtree=%s, they are %sthe same",
ti->expired ? "true" : "false",
ti->item ? "true" : "false",
ti->tree ? "true" : "false",
(ti->tree == ti->item) ? "" : "not ");
}
else {
lua_pushstring(L, "No TreeItem object!");
}
return 1;
}
static int TreeItem__gc(lua_State* L) {
TreeItem ti = toTreeItem(L,1);
if (!ti) return 0;
if (!ti->expired)
ti->expired = TRUE;
else
g_free(ti);
return 0;
}
int TreeItem_register(lua_State *L) {
gint* etts[] = { &wslua_ett };
wslua_ett = -1;
WSLUA_REGISTER_CLASS(TreeItem);
WSLUA_REGISTER_ATTRIBUTES(TreeItem);
outstanding_TreeItem = g_ptr_array_new();
proto_register_subtree_array(etts,1);
return 0;
}
