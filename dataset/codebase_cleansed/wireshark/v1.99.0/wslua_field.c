WSLUA_METAMETHOD FieldInfo__len(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushnumber(L,fi->ws_fi->length);
return 1;
}
WSLUA_METAMETHOD FieldInfo__unm(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushnumber(L,fi->ws_fi->start);
return 1;
}
WSLUA_METAMETHOD FieldInfo__call(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
switch(fi->ws_fi->hfinfo->type) {
case FT_BOOLEAN:
lua_pushboolean(L,(int)fvalue_get_uinteger(&(fi->ws_fi->value)));
return 1;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_FRAMENUM:
lua_pushnumber(L,(lua_Number)(fvalue_get_uinteger(&(fi->ws_fi->value))));
return 1;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
lua_pushnumber(L,(lua_Number)(fvalue_get_sinteger(&(fi->ws_fi->value))));
return 1;
case FT_FLOAT:
case FT_DOUBLE:
lua_pushnumber(L,(lua_Number)(fvalue_get_floating(&(fi->ws_fi->value))));
return 1;
case FT_INT64: {
pushInt64(L,(Int64)(fvalue_get_integer64(&(fi->ws_fi->value))));
return 1;
}
case FT_UINT64: {
pushUInt64(L,fvalue_get_integer64(&(fi->ws_fi->value)));
return 1;
}
case FT_ETHER: {
Address eth = (Address)g_malloc(sizeof(address));
eth->type = AT_ETHER;
eth->len = fi->ws_fi->length;
eth->data = tvb_memdup(NULL,fi->ws_fi->ds_tvb,fi->ws_fi->start,fi->ws_fi->length);
pushAddress(L,eth);
return 1;
}
case FT_IPv4:{
Address ipv4 = (Address)g_malloc(sizeof(address));
ipv4->type = AT_IPv4;
ipv4->len = fi->ws_fi->length;
ipv4->data = tvb_memdup(NULL,fi->ws_fi->ds_tvb,fi->ws_fi->start,fi->ws_fi->length);
pushAddress(L,ipv4);
return 1;
}
case FT_IPv6: {
Address ipv6 = (Address)g_malloc(sizeof(address));
ipv6->type = AT_IPv6;
ipv6->len = fi->ws_fi->length;
ipv6->data = tvb_memdup(NULL,fi->ws_fi->ds_tvb,fi->ws_fi->start,fi->ws_fi->length);
pushAddress(L,ipv6);
return 1;
}
case FT_IPXNET:{
Address ipx = (Address)g_malloc(sizeof(address));
ipx->type = AT_IPX;
ipx->len = fi->ws_fi->length;
ipx->data = tvb_memdup(NULL,fi->ws_fi->ds_tvb,fi->ws_fi->start,fi->ws_fi->length);
pushAddress(L,ipx);
return 1;
}
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME: {
NSTime nstime = (NSTime)g_malloc(sizeof(nstime_t));
*nstime = *(NSTime)fvalue_get(&(fi->ws_fi->value));
pushNSTime(L,nstime);
return 1;
}
case FT_STRING:
case FT_STRINGZ: {
gchar* repr = fvalue_to_string_repr(&fi->ws_fi->value,FTREPR_DISPLAY,NULL);
if (repr)
lua_pushstring(L,repr);
else
luaL_error(L,"field cannot be represented as string because it may contain invalid characters");
return 1;
}
case FT_NONE:
if (fi->ws_fi->length == 0) {
lua_pushnil(L);
return 1;
}
case FT_BYTES:
case FT_UINT_BYTES:
case FT_PROTOCOL:
case FT_REL_OID:
case FT_SYSTEM_ID:
case FT_OID:
{
ByteArray ba = g_byte_array_new();
g_byte_array_append(ba, (const guint8 *) fvalue_get(&fi->ws_fi->value),
fvalue_length(&fi->ws_fi->value));
pushByteArray(L,ba);
return 1;
}
case FT_GUID:
default:
luaL_error(L,"FT_ not yet supported");
return 1;
}
}
WSLUA_METAMETHOD FieldInfo__tostring(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
if (fi->ws_fi->value.ftype->val_to_string_repr) {
gchar* repr = fvalue_to_string_repr(&fi->ws_fi->value,FTREPR_DISPLAY,NULL);
if (repr) {
lua_pushstring(L,repr);
}
else {
lua_pushstring(L,"(unknown)");
}
}
else if (fi->ws_fi->hfinfo->type == FT_NONE) {
lua_pushstring(L, "(none)");
}
else {
lua_pushstring(L,"(n/a)");
}
return 1;
}
static int FieldInfo_get_display(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
gchar label_str[ITEM_LABEL_LENGTH+1];
gchar *label_ptr;
gchar *value_ptr;
if (!fi->ws_fi->rep) {
label_ptr = label_str;
proto_item_fill_label(fi->ws_fi, label_str);
} else
label_ptr = fi->ws_fi->rep->representation;
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
if (push_TvbRange (L, fi->ws_fi->ds_tvb, fi->ws_fi->start, fi->ws_fi->length)) {
return 1;
}
return 0;
}
static int FieldInfo_get_generated(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushboolean(L,FI_GET_FLAG(fi->ws_fi, FI_GENERATED));
return 1;
}
static int FieldInfo_get_name(lua_State* L) {
FieldInfo fi = checkFieldInfo(L,1);
lua_pushstring(L,fi->ws_fi->hfinfo->abbrev);
return 1;
}
WSLUA_METAMETHOD FieldInfo__eq(lua_State* L) {
FieldInfo l = checkFieldInfo(L,1);
FieldInfo r = checkFieldInfo(L,2);
if (l->ws_fi->ds_tvb != r->ws_fi->ds_tvb) {
WSLUA_ERROR(FieldInfo__eq,"Data source must be the same for both fields");
return 0;
}
if (l->ws_fi->start <= r->ws_fi->start && r->ws_fi->start + r->ws_fi->length <= l->ws_fi->start + r->ws_fi->length) {
lua_pushboolean(L,1);
return 1;
} else {
return 0;
}
}
WSLUA_METAMETHOD FieldInfo__le(lua_State* L) {
FieldInfo l = checkFieldInfo(L,1);
FieldInfo r = checkFieldInfo(L,2);
if (l->ws_fi->ds_tvb != r->ws_fi->ds_tvb)
WSLUA_ERROR(FieldInfo__le,"Data source must be the same for both fields");
if (r->ws_fi->start + r->ws_fi->length <= l->ws_fi->start + r->ws_fi->length) {
lua_pushboolean(L,1);
return 1;
} else {
return 0;
}
}
WSLUA_METAMETHOD FieldInfo__lt(lua_State* L) {
FieldInfo l = checkFieldInfo(L,1);
FieldInfo r = checkFieldInfo(L,2);
if (l->ws_fi->ds_tvb != r->ws_fi->ds_tvb) {
WSLUA_ERROR(FieldInfo__lt,"Data source must be the same for both fields");
return 0;
}
if (r->ws_fi->start + r->ws_fi->length < l->ws_fi->start) {
lua_pushboolean(L,1);
return 1;
} else {
return 0;
}
}
static int FieldInfo__gc(lua_State* L _U_) {
FieldInfo fi = toFieldInfo(L,1);
if (!fi) return 0;
if (!fi->expired)
fi->expired = TRUE;
else
g_free(fi);
return 0;
}
int FieldInfo_register(lua_State* L) {
WSLUA_REGISTER_META(FieldInfo);
WSLUA_REGISTER_ATTRIBUTES(FieldInfo);
return 0;
}
WSLUA_FUNCTION wslua_all_field_infos(lua_State* L) {
GPtrArray* found;
int items_found = 0;
guint i;
if (! lua_tree || ! lua_tree->tree ) {
WSLUA_ERROR(wslua_all_field_infos,"Cannot be called outside a listener or dissector");
return 0;
}
found = proto_all_finfos(lua_tree->tree);
if (found) {
for (i=0; i<found->len; i++) {
FieldInfo fi = (FieldInfo)g_malloc(sizeof(struct _wslua_field_info));
fi->ws_fi = (field_info *)g_ptr_array_index(found,i);
fi->expired = FALSE;
PUSH_FIELDINFO(L,fi);
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
if (!proto_registrar_get_byname(name) && !wslua_is_field_available(L, name)) {
WSLUA_ARG_ERROR(Field_new,FIELDNAME,"a field with this name must exist");
return 0;
}
if (!wanted_fields) {
WSLUA_ERROR(Field_new,"A Field extractor must be defined before Taps or Dissectors get called");
return 0;
}
f = (Field)g_malloc(sizeof(void*));
*f = (header_field_info*)(void*)g_strdup(name);
g_ptr_array_add(wanted_fields,f);
pushField(L,f);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR Field_list(lua_State *L) {
void *cookie, *cookie2;
int i = -1;
int count = 0;
header_field_info *hfinfo = NULL;
lua_newtable(L);
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
for (hfinfo = proto_get_first_protocol_field(i, &cookie2); hfinfo != NULL;
hfinfo = proto_get_next_protocol_field(i, &cookie2)) {
if (hfinfo->same_name_prev_id != -1)
continue;
count++;
lua_pushstring(L,hfinfo->abbrev);
lua_rawseti(L,1,count);
}
}
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
return 0;
}
while (in) {
GPtrArray* found = proto_get_finfo_ptr_array(lua_tree->tree, in->id);
guint i;
if (found) {
for (i=0; i<found->len; i++) {
FieldInfo fi = (FieldInfo)g_malloc(sizeof(struct _wslua_field_info));
fi->ws_fi = (field_info *)g_ptr_array_index(found,i);
fi->expired = FALSE;
PUSH_FIELDINFO(L,fi);
items_found++;
}
}
in = (in->same_name_prev_id != -1) ? proto_registrar_get_nth(in->same_name_prev_id) : NULL;
}
WSLUA_RETURN(items_found);
}
WSLUA_METAMETHOD Field__tostring(lua_State* L) {
Field f = checkField(L,1);
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
outstanding_FieldInfo = g_ptr_array_new();
return 0;
}
