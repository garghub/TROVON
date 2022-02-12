WSLUA_METAMETHOD FieldInfo__len(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushnumber(L,fi->length);
return 1;
}
WSLUA_METAMETHOD FieldInfo__unm(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushnumber(L,fi->start);
return 1;
}
WSLUA_METAMETHOD FieldInfo__call(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
switch(fi->hfinfo->type) {
case FT_BOOLEAN:
lua_pushboolean(L,(int)fvalue_get_uinteger(&(fi->value)));
return 1;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
lua_pushnumber(L,(lua_Number)fvalue_get_uinteger(&(fi->value)));
return 1;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
lua_pushnumber(L,(lua_Number)fvalue_get_sinteger(&(fi->value)));
return 1;
case FT_FLOAT:
case FT_DOUBLE:
lua_pushnumber(L,(lua_Number)fvalue_get_floating(&(fi->value)));
return 1;
case FT_INT64: {
Int64 num = (Int64)g_malloc(sizeof(gint64));
*num = fvalue_get_integer64(&(fi->value));
pushInt64(L,num);
return 1;
}
case FT_UINT64: {
UInt64 num = (UInt64)g_malloc(sizeof(guint64));
*num = fvalue_get_integer64(&(fi->value));
pushUInt64(L,num);
return 1;
}
case FT_ETHER: {
Address eth = (Address)g_malloc(sizeof(address));
eth->type = AT_ETHER;
eth->len = fi->length;
eth->data = tvb_memdup(NULL,fi->ds_tvb,fi->start,fi->length);
pushAddress(L,eth);
return 1;
}
case FT_IPv4:{
Address ipv4 = (Address)g_malloc(sizeof(address));
ipv4->type = AT_IPv4;
ipv4->len = fi->length;
ipv4->data = tvb_memdup(NULL,fi->ds_tvb,fi->start,fi->length);
pushAddress(L,ipv4);
return 1;
}
case FT_IPv6: {
Address ipv6 = (Address)g_malloc(sizeof(address));
ipv6->type = AT_IPv6;
ipv6->len = fi->length;
ipv6->data = tvb_memdup(NULL,fi->ds_tvb,fi->start,fi->length);
pushAddress(L,ipv6);
return 1;
}
case FT_IPXNET:{
Address ipx = (Address)g_malloc(sizeof(address));
ipx->type = AT_IPX;
ipx->len = fi->length;
ipx->data = tvb_memdup(NULL,fi->ds_tvb,fi->start,fi->length);
pushAddress(L,ipx);
return 1;
}
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME: {
NSTime nstime = (NSTime)g_malloc(sizeof(nstime_t));
*nstime = *(NSTime)fvalue_get(&(fi->value));
pushNSTime(L,nstime);
return 1;
}
case FT_STRING:
case FT_STRINGZ: {
gchar* repr = fvalue_to_string_repr(&fi->value,FTREPR_DISPLAY,NULL);
if (repr)
lua_pushstring(L,repr);
else
luaL_error(L,"field cannot be represented as string because it may contain invalid characters");
return 1;
}
case FT_NONE:
if (fi->length == 0) {
lua_pushnil(L);
return 1;
}
case FT_BYTES:
case FT_UINT_BYTES:
case FT_GUID:
case FT_PROTOCOL:
case FT_REL_OID:
case FT_OID: {
ByteArray ba = g_byte_array_new();
g_byte_array_append(ba, (const guint8 *)tvb_memdup(wmem_packet_scope(),fi->ds_tvb,fi->start,fi->length),fi->length);
pushByteArray(L,ba);
return 1;
}
default:
luaL_error(L,"FT_ not yet supported");
return 1;
}
}
WSLUA_METAMETHOD FieldInfo__tostring(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
if (!fi) {
return luaL_error(L,"Missing FieldInfo object");
}
if (fi->value.ftype->val_to_string_repr) {
gchar* repr = fvalue_to_string_repr(&fi->value,FTREPR_DISPLAY,NULL);
if (repr) {
lua_pushstring(L,repr);
}
else {
lua_pushstring(L,"(unknown)");
}
}
else if (fi->hfinfo->type == FT_NONE) {
lua_pushstring(L, "(none)");
}
else {
lua_pushstring(L,"(n/a)");
}
return 1;
}
static int FieldInfo_display(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
gchar label_str[ITEM_LABEL_LENGTH+1];
gchar *label_ptr;
gchar *value_ptr;
if (!fi) return 0;
if (!fi->rep) {
label_ptr = label_str;
proto_item_fill_label(fi, label_str);
} else
label_ptr = fi->rep->representation;
if (!label_ptr) return 0;
value_ptr = strstr(label_ptr, ": ");
if (!value_ptr) {
lua_pushstring(L, label_ptr);
} else {
value_ptr += 2;
lua_pushstring(L, value_ptr);
}
return 1;
}
static int FieldInfo_get_range(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
TvbRange r = ep_new(struct _wslua_tvbrange);
r->tvb = ep_new(struct _wslua_tvb);
r->tvb->ws_tvb = fi->ds_tvb;
r->tvb->expired = FALSE;
r->tvb->need_free = FALSE;
r->offset = fi->start;
r->len = fi->length;
pushTvbRange(L,r);
return 1;
}
static int FieldInfo_get_generated(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushboolean(L,FI_GET_FLAG(fi, FI_GENERATED));
return 1;
}
static int FieldInfo_get_name(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushstring(L,fi->hfinfo->abbrev);
return 1;
}
static int FieldInfo__index(lua_State* L) {
const gchar* idx = luaL_checkstring(L,2);
const luaL_Reg* r;
checkFieldInfo(L,1);
for (r = FieldInfo_get; r->name; r++) {
if (g_str_equal(r->name, idx)) {
return r->func(L);
}
}
return 0;
}
WSLUA_METAMETHOD FieldInfo__eq(lua_State* L) {
FieldInfo l = checkFieldInfo(L,1);
FieldInfo r = checkFieldInfo(L,2);
if (l->ds_tvb != r->ds_tvb)
WSLUA_ERROR(FieldInfo__eq,"Data source must be the same for both fields");
if (l->start <= r->start && r->start + r->length <= l->start + r->length) {
lua_pushboolean(L,1);
return 1;
} else {
return 0;
}
}
WSLUA_METAMETHOD FieldInfo__le(lua_State* L) {
FieldInfo l = checkFieldInfo(L,1);
FieldInfo r = checkFieldInfo(L,2);
if (l->ds_tvb != r->ds_tvb)
WSLUA_ERROR(FieldInfo__le,"Data source must be the same for both fields");
if (r->start + r->length <= l->start + r->length) {
lua_pushboolean(L,1);
return 1;
} else {
return 0;
}
}
WSLUA_METAMETHOD FieldInfo__lt(lua_State* L) {
FieldInfo l = checkFieldInfo(L,1);
FieldInfo r = checkFieldInfo(L,2);
if (l->ds_tvb != r->ds_tvb)
WSLUA_ERROR(FieldInfo__lt,"Data source must be the same for both fields");
if ( r->start + r->length < l->start ) {
lua_pushboolean(L,1);
return 1;
} else {
return 0;
}
}
static int FieldInfo__gc(lua_State* L _U_) {
return 0;
}
int FieldInfo_register(lua_State* L) {
WSLUA_REGISTER_META(FieldInfo);
return 1;
}
WSLUA_FUNCTION wslua_all_field_infos(lua_State* L) {
GPtrArray* found;
int items_found = 0;
guint i;
if (! lua_tree || ! lua_tree->tree ) {
WSLUA_ERROR(wslua_all_field_infos,"Cannot be called outside a listener or dissector");
}
found = proto_all_finfos(lua_tree->tree);
if (found) {
for (i=0; i<found->len; i++) {
pushFieldInfo(L,(FieldInfo)g_ptr_array_index(found,i));
items_found++;
}
g_ptr_array_free(found,TRUE);
}
return items_found;
}
void wslua_prime_dfilter(epan_dissect_t *edt) {
if (wslua_dfilter && edt && edt->tree) {
dfilter_prime_proto_tree(wslua_dfilter, edt->tree);
}
}
void lua_prime_all_fields(proto_tree* tree _U_) {
GString* fake_tap_filter = g_string_new("frame");
guint i;
static gboolean fake_tap = FALSE;
for(i=0; i < wanted_fields->len; i++) {
Field f = (Field)g_ptr_array_index(wanted_fields,i);
gchar* name = *((gchar**)f);
*f = proto_registrar_get_byname(name);
if (!*f) {
report_failure("Could not find field `%s'",name);
*f = NULL;
g_free(name);
continue;
}
g_free(name);
g_string_append_printf(fake_tap_filter," || %s",(*f)->abbrev);
fake_tap = TRUE;
}
g_ptr_array_free(wanted_fields,TRUE);
wanted_fields = NULL;
if (fake_tap) {
GString* error = register_tap_listener("frame",
&fake_tap,
fake_tap_filter->str,
0,
NULL, NULL, NULL);
if (error) {
report_failure("while registering lua_fake_tap:\n%s",error->str);
g_string_free(error,TRUE);
}
else if (!dfilter_compile(fake_tap_filter->str, &wslua_dfilter)) {
report_failure("while compiling dfilter for wslua: '%s'", fake_tap_filter->str);
}
}
}
WSLUA_CONSTRUCTOR Field_new(lua_State *L) {
#define WSLUA_ARG_Field_new_FIELDNAME 1
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Field_new_FIELDNAME);
Field f;
if (!name) return 0;
if (!proto_registrar_get_byname(name))
WSLUA_ARG_ERROR(Field_new,FIELDNAME,"a field with this name must exist");
if (!wanted_fields)
WSLUA_ERROR(Field_new,"A Field extractor must be defined before Taps or Dissectors get called");
f = (Field)g_malloc(sizeof(void*));
*f = (header_field_info*)g_strdup(name);
g_ptr_array_add(wanted_fields,f);
pushField(L,f);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Field__call (lua_State* L) {
Field f = checkField(L,1);
header_field_info* in = *f;
int items_found = 0;
if (! in) {
luaL_error(L,"invalid field");
return 0;
}
if (! lua_pinfo ) {
WSLUA_ERROR(Field__call,"Fields cannot be used outside dissectors or taps");
}
while (in) {
GPtrArray* found = proto_get_finfo_ptr_array(lua_tree->tree, in->id);
guint i;
if (found) {
for (i=0; i<found->len; i++) {
pushFieldInfo(L,(FieldInfo)g_ptr_array_index(found,i));
items_found++;
}
}
in = (in->same_name_prev_id != -1) ? proto_registrar_get_nth(in->same_name_prev_id) : NULL;
}
WSLUA_RETURN(items_found);
}
WSLUA_METAMETHOD Field__tostring(lua_State* L) {
Field f = checkField(L,1);
if ( !(f && *f) ) {
luaL_error(L,"invalid Field");
return 0;
}
if (wanted_fields) {
lua_pushstring(L,*((gchar**)f));
} else {
lua_pushstring(L,(*f)->abbrev);
}
return 1;
}
static int Field__gc(lua_State* L _U_) {
return 0;
}
int Field_register(lua_State* L) {
wanted_fields = g_ptr_array_new();
WSLUA_REGISTER_CLASS(Field);
return 1;
}
