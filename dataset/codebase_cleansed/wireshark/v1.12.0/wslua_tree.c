TreeItem* push_TreeItem(lua_State*L, TreeItem t) {
g_ptr_array_add(outstanding_TreeItem,t);
return pushTreeItem(L,t);
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
tvbr = ep_new(struct _wslua_tvbrange);
tvbr->tvb = ep_new(struct _wslua_tvb);
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
tree_item = (TreeItem)g_malloc(sizeof(struct _wslua_treeitem));
tree_item->item = item;
tree_item->tree = proto_item_add_subtree(item,ett > 0 ? ett : wslua_ett);
tree_item->expired = FALSE;
PUSH_TREEITEM(L,tree_item);
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
tvbr = ep_new(struct _wslua_tvbrange);
tvbr->tvb = ep_new(struct _wslua_tvb);
tvbr->tvb->ws_tvb = lua_tvb;
tvbr->offset = 0;
tvbr->len = 0;
}
if (hfid > 0 ) {
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
item = proto_tree_add_string(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvbr->len,luaL_checkstring(L,1));
break;
case FT_STRINGZ:
item = proto_tree_add_string(tree_item->tree,hfid,tvbr->tvb->ws_tvb,tvbr->offset,tvb_strsize (tvbr->tvb->ws_tvb, tvbr->offset),luaL_checkstring(L,1));
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
default:
luaL_error(L,"FT_ not yet supported");
return 0;
}
lua_remove(L,1);
} else {
if (type == FT_STRINGZ) tvbr->len = tvb_strsize (tvbr->tvb->ws_tvb, tvbr->offset);
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
item = proto_tree_add_text(tree_item->tree, tvbr->tvb->ws_tvb, tvbr->offset, tvbr->len,"%s",s);
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
tree_item = (TreeItem)g_malloc(sizeof(struct _wslua_treeitem));
tree_item->item = item;
tree_item->tree = proto_item_add_subtree(item,ett > 0 ? ett : wslua_ett);
tree_item->expired = FALSE;
PUSH_TREEITEM(L,tree_item);
return 1;
}
WSLUA_METHOD TreeItem_add(lua_State *L) {
#define WSLUA_ARG_TreeItem_add_PROTOFIELD 2
#define WSLUA_OPTARG_TreeItem_add_TVBRANGE 3
#define WSLUA_OPTARG_TreeItem_add_VALUE 4
#define WSLUA_OPTARG_TreeItem_add_LABEL 5
WSLUA_RETURN(TreeItem_add_item_any(L,FALSE));
}
WSLUA_METHOD TreeItem_add_le(lua_State *L) {
#define WSLUA_ARG_TreeItem_add_le_PROTOFIELD 2
#define WSLUA_OPTARG_TreeItem_add_le_TVBRANGE 3
#define WSLUA_OPTARG_TreeItem_add_le_VALUE 4
#define WSLUA_OPTARG_TreeItem_add_le_LABEL 5
WSLUA_RETURN(TreeItem_add_item_any(L,TRUE));
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
int group = luaL_optint(L,WSLUA_OPTARG_TreeItem_add_expert_info_GROUP,PI_DEBUG);
int severity = luaL_optint(L,WSLUA_OPTARG_TreeItem_add_expert_info_SEVERITY,PI_CHAT);
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
tvbr = ep_new(struct _wslua_tvbrange);
tvbr->tvb = shiftTvb(L,WSLUA_ARG_TreeItem_add_tvb_expert_info_TVB);
if (!tvbr->tvb) {
tvbr->tvb = ep_new(struct _wslua_tvb);
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
WSLUA_METHOD TreeItem_set_generated(lua_State *L) {
TreeItem ti = checkTreeItem(L,1);
PROTO_ITEM_SET_GENERATED(ti->item);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_set_hidden(lua_State *L) {
TreeItem ti = checkTreeItem(L,1);
PROTO_ITEM_SET_HIDDEN(ti->item);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
}
WSLUA_METHOD TreeItem_set_len(lua_State *L) {
#define WSLUA_ARG_TreeItem_set_len_LEN 2
TreeItem ti = checkTreeItem(L,1);
gint len = luaL_checkint(L,WSLUA_ARG_TreeItem_set_len_LEN);
proto_item_set_len(ti->item, len);
lua_pushvalue(L, 1);
WSLUA_RETURN(1);
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
WSLUA_REGISTER_CLASS(TreeItem);
outstanding_TreeItem = g_ptr_array_new();
proto_register_subtree_array(etts,1);
return 0;
}
