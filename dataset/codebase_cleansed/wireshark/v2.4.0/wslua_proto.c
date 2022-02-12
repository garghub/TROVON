void clear_outstanding_FuncSavers(void) {
while (outstanding_FuncSavers->len) {
func_saver_t* fs = (func_saver_t*)g_ptr_array_remove_index_fast(outstanding_FuncSavers,0);
if (fs->state) {
lua_State* L = fs->state;
if (fs->get_len_ref != LUA_NOREF) {
luaL_unref(L, LUA_REGISTRYINDEX, fs->get_len_ref);
}
if (fs->dissect_ref != LUA_NOREF) {
luaL_unref(L, LUA_REGISTRYINDEX, fs->dissect_ref);
}
}
g_free(fs);
}
}
WSLUA_CONSTRUCTOR Proto_new(lua_State* L) {
#define WSLUA_ARG_Proto_new_NAME 1
#define WSLUA_ARG_Proto_new_DESC 2
const gchar* name = luaL_checkstring(L,WSLUA_ARG_Proto_new_NAME);
const gchar* desc = luaL_checkstring(L,WSLUA_ARG_Proto_new_DESC);
Proto proto;
gchar *loname, *hiname;
if (!name[0]) {
WSLUA_ARG_ERROR(Proto_new,NAME,"must not be an empty string");
return 0;
}
if (!desc[0]) {
WSLUA_ARG_ERROR(Proto_new,DESC,"must not be an empty string");
return 0;
}
if (proto_name_already_registered(desc)) {
WSLUA_ARG_ERROR(Proto_new,DESC,"there cannot be two protocols with the same description");
return 0;
}
loname = g_ascii_strdown(name, -1);
if (proto_check_field_name(loname)) {
g_free(loname);
WSLUA_ARG_ERROR(Proto_new,NAME,"invalid character in name");
return 0;
}
hiname = g_ascii_strup(name, -1);
if ((proto_get_id_by_short_name(hiname) != -1) ||
(proto_get_id_by_filter_name(loname) != -1))
{
g_free(loname);
g_free(hiname);
WSLUA_ARG_ERROR(Proto_new,NAME,"there cannot be two protocols with the same name");
return 0;
}
proto = (wslua_proto_t *)g_malloc(sizeof(wslua_proto_t));
proto->name = hiname;
proto->loname = loname;
proto->desc = g_strdup(desc);
proto->hfid = proto_register_protocol(proto->desc,hiname,loname);
proto->ett = -1;
proto->is_postdissector = FALSE;
proto->expired = FALSE;
lua_newtable (L);
proto->fields = luaL_ref(L, LUA_REGISTRYINDEX);
lua_newtable (L);
proto->expert_info_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
proto->expert_module = expert_register_protocol(proto->hfid);
proto->prefs.name = NULL;
proto->prefs.label = NULL;
proto->prefs.desc = NULL;
proto->prefs.value.u = 0;
proto->prefs.next = NULL;
proto->prefs.proto = proto;
proto->prefs_module = NULL;
proto->handle = NULL;
lua_rawgeti(L, LUA_REGISTRYINDEX, protocols_table_ref);
lua_pushstring(L,loname);
pushProto(L,proto);
lua_settable(L, -3);
pushProto(L,proto);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD Proto__call(lua_State* L) {
#define WSLUA_ARG_Proto__call_NAME 1
#define WSLUA_ARG_Proto__call_DESC 2
lua_remove(L,1);
WSLUA_RETURN(Proto_new(L));
}
static int Proto__tostring(lua_State* L) {
Proto proto = checkProto(L,1);
lua_pushfstring(L, "Proto: %s", proto->name);
return 1;
}
WSLUA_FUNCTION wslua_register_postdissector(lua_State* L) {
#define WSLUA_ARG_register_postdissector_PROTO 1
#define WSLUA_OPTARG_register_postdissector_ALLFIELDS 2
Proto proto = checkProto(L,WSLUA_ARG_register_postdissector_PROTO);
const gboolean all_fields = wslua_optbool(L, WSLUA_OPTARG_register_postdissector_ALLFIELDS, FALSE);
if(!proto->is_postdissector) {
if (! proto->handle) {
proto->handle = register_dissector(proto->loname, dissect_lua, proto->hfid);
}
register_postdissector(proto->handle);
proto->is_postdissector = TRUE;
} else {
luaL_argerror(L,1,"this protocol is already registered as postdissector");
}
if (all_fields) {
epan_set_always_visible(TRUE);
}
return 0;
}
WSLUA_METHOD Proto_register_heuristic(lua_State* L) {
#define WSLUA_ARG_Proto_register_heuristic_LISTNAME 2
#define WSLUA_ARG_Proto_register_heuristic_FUNC 3
Proto proto = checkProto(L,1);
const gchar *listname = luaL_checkstring(L, WSLUA_ARG_Proto_register_heuristic_LISTNAME);
const gchar *proto_name = proto->name;
const int top = lua_gettop(L);
gchar *short_name;
if (!proto_name || proto->hfid == -1) {
luaL_error(L,"Proto_register_heuristic: got NULL proto name or invalid hfid");
return 0;
}
if (!has_heur_dissector_list(listname)) {
luaL_error(L, "there is no heuristic list for '%s'", listname);
return 0;
}
short_name = wmem_strconcat(NULL, proto->loname, "_", listname, NULL);
if (find_heur_dissector_by_unique_short_name(short_name)) {
wmem_free(NULL, short_name);
luaL_error(L, "'%s' is already registered as heuristic", proto->loname);
return 0;
}
wmem_free(NULL, short_name);
if (isDissector(L, WSLUA_ARG_Proto_register_heuristic_FUNC)) {
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_dissectors_table_ref);
lua_getfield(L, -1, proto_name);
if (!lua_isfunction(L,-1)) {
luaL_error(L,"Proto_register_heuristic: could not get lua function from lua_dissectors_table");
return 0;
}
lua_replace(L, WSLUA_ARG_Proto_register_heuristic_FUNC);
lua_pop(L, 1);
g_assert(top == lua_gettop(L));
}
if (lua_isfunction(L,WSLUA_ARG_Proto_register_heuristic_FUNC)) {
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_heur_dissectors_table_ref);
if (!lua_istable(L,-1)) {
luaL_error(L,"Proto_register_heuristic: could not get lua_heur_dissectors table from registry");
return 0;
}
if (!wslua_get_table(L,-1,listname)) {
lua_newtable(L);
lua_pushvalue(L,-1);
lua_setfield(L,-3,listname);
}
else if (wslua_get_field(L,-1,proto_name)) {
luaL_error(L,"A heuristic dissector for Proto '%s' is already registered for the '%s' list", proto_name, listname);
return 0;
}
lua_pushvalue(L,WSLUA_ARG_Proto_register_heuristic_FUNC);
lua_setfield(L,-2,proto_name);
lua_pop(L,2);
g_assert(top == lua_gettop(L));
short_name = wmem_strconcat(NULL, proto->loname, "_", listname, NULL);
heur_dissector_add(listname, heur_dissect_lua, proto_name, short_name, proto->hfid, HEURISTIC_ENABLE);
wmem_free(NULL, short_name);
} else {
luaL_argerror(L,3,"The heuristic dissector must be a function");
}
return 0;
}
static int Proto_get_dissector(lua_State* L) {
Proto proto = checkProto(L,1);
if (proto->handle) {
pushDissector(L,proto->handle);
return 1;
} else {
luaL_error(L,"The protocol hasn't been registered yet");
return 0;
}
}
static int Proto_set_dissector(lua_State* L) {
Proto proto = checkProto(L,1);
if (lua_isfunction(L,2)) {
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_dissectors_table_ref);
lua_replace(L, 1);
lua_pushstring(L,proto->name);
lua_insert(L, 2);
lua_settable(L,1);
if (! proto->handle) {
proto->handle = register_dissector(proto->loname, dissect_lua, proto->hfid);
}
} else {
luaL_argerror(L,2,"The dissector of a protocol must be a function");
}
return 0;
}
static int Proto_get_prefs(lua_State* L) {
Proto proto = checkProto(L,1);
pushPrefs(L,&proto->prefs);
return 1;
}
static int Proto_set_prefs_changed(lua_State* L) {
Proto proto = checkProto(L,1);
if (lua_isfunction(L,2)) {
lua_getglobal(L, WSLUA_PREFS_CHANGED);
lua_replace(L, 1);
lua_pushstring(L,proto->name);
lua_insert(L, 2);
lua_settable(L,1);
} else {
luaL_argerror(L,2,"The prefs of a protocol must be a function");
}
return 0;
}
static int Proto_set_init(lua_State* L) {
Proto proto = checkProto(L,1);
if (lua_isfunction(L,2)) {
lua_getglobal(L, WSLUA_INIT_ROUTINES);
lua_replace(L, 1);
lua_pushstring(L,proto->name);
lua_insert(L, 2);
lua_settable(L,1);
} else {
luaL_argerror(L,2,"The initializer of a protocol must be a function");
}
return 0;
}
static int Proto_get_fields(lua_State* L) {
Proto proto = checkProto(L,1);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
return 1;
}
static int Proto_set_fields(lua_State* L) {
Proto proto = checkProto(L,1);
#define FIELDS_TABLE 2
#define NEW_TABLE 3
#define NEW_FIELD 3
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
lua_insert(L,FIELDS_TABLE);
if( lua_istable(L,NEW_TABLE)) {
for (lua_pushnil(L); lua_next(L, NEW_TABLE); ) {
if (isProtoField(L,5)) {
luaL_ref(L,FIELDS_TABLE);
} else if (! lua_isnil(L,5) ) {
return luaL_error(L,"only ProtoFields should be in the table");
}
}
} else if (isProtoField(L,NEW_FIELD)){
lua_pushvalue(L, NEW_FIELD);
luaL_ref(L,FIELDS_TABLE);
} else {
return luaL_error(L,"either a ProtoField or an array of protofields");
}
lua_pushvalue(L, 3);
return 1;
}
static int Proto_get_experts(lua_State* L) {
Proto proto = checkProto(L,1);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->expert_info_table_ref);
return 1;
}
static int Proto_set_experts(lua_State* L) {
Proto proto = checkProto(L,1);
#define EI_TABLE 2
#define NEW_TABLE 3
#define NEW_FIELD 3
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->expert_info_table_ref);
lua_insert(L,EI_TABLE);
if( lua_istable(L,NEW_TABLE)) {
for (lua_pushnil(L); lua_next(L, NEW_TABLE); ) {
if (isProtoExpert(L,5)) {
luaL_ref(L,EI_TABLE);
} else if (! lua_isnil(L,5) ) {
return luaL_error(L,"only ProtoExperts should be in the table");
}
}
} else if (isProtoExpert(L,NEW_FIELD)){
lua_pushvalue(L, NEW_FIELD);
luaL_ref(L,EI_TABLE);
} else {
return luaL_error(L,"either a ProtoExpert or an array of ProtoExperts");
}
lua_pushvalue(L, 3);
return 1;
}
static int Proto__gc(lua_State* L) {
Proto proto = toProto(L,1);
if (!proto->expired) {
proto->expired = TRUE;
} else if (proto->hfid == -2) {
g_free(proto);
}
return 0;
}
int Proto_register(lua_State* L) {
WSLUA_REGISTER_CLASS(Proto);
WSLUA_REGISTER_ATTRIBUTES(Proto);
outstanding_FuncSavers = g_ptr_array_new();
lua_newtable(L);
protocols_table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
return 0;
}
ProtoField wslua_is_field_available(lua_State* L, const char* field_abbr) {
lua_rawgeti(L, LUA_REGISTRYINDEX, protocols_table_ref);
lua_pushnil(L);
while (lua_next(L, -2)) {
Proto proto;
proto = checkProto(L, -1);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
lua_pushnil(L);
while (lua_next(L, -2)) {
ProtoField f = checkProtoField(L, -1);
if (strcmp(field_abbr, f->abbrev) == 0) {
lua_pop(L, 6);
return f;
}
lua_pop(L, 1);
}
lua_pop(L, 2);
}
lua_pop(L, 1);
return NULL;
}
int wslua_deregister_heur_dissectors(lua_State* L) {
lua_rawgeti(L, LUA_REGISTRYINDEX, lua_heur_dissectors_table_ref);
for (lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1)) {
const gchar *listname = luaL_checkstring(L, -2);
for (lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1)) {
const gchar *proto_name = luaL_checkstring(L, -2);
int proto_id = proto_get_id_by_short_name(proto_name);
heur_dissector_delete(listname, heur_dissect_lua, proto_id);
}
}
lua_pop(L, 1);
return 0;
}
int wslua_deregister_protocols(lua_State* L) {
lua_rawgeti(L, LUA_REGISTRYINDEX, protocols_table_ref);
for (lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1)) {
Proto proto;
proto = checkProto(L, -1);
if (proto->handle) {
deregister_dissector(proto->loname);
}
if (proto->prefs_module) {
Pref pref;
prefs_deregister_protocol(proto->hfid);
for (pref = proto->prefs.next; pref; pref = pref->next) {
g_free(pref->name);
pref->name = NULL;
}
}
if (proto->expert_module) {
expert_deregister_protocol(proto->expert_module);
}
proto_deregister_protocol(proto->name);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
for (lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1)) {
ProtoField f = checkProtoField(L, -1);
f->hfid = -2;
}
lua_pop(L, 1);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->expert_info_table_ref);
for (lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1)) {
ProtoExpert pe = checkProtoExpert(L,-1);
pe->ids.hf = -2;
}
lua_pop(L, 1);
if (proto->hfa->len) {
proto_add_deregistered_data(g_array_free(proto->hfa,FALSE));
} else {
g_array_free(proto->hfa,TRUE);
}
if (proto->etta->len) {
proto_add_deregistered_data(g_array_free(proto->etta,FALSE));
} else {
g_array_free(proto->etta,TRUE);
}
if (proto->eia->len) {
proto_add_deregistered_data(g_array_free(proto->eia,FALSE));
} else {
g_array_free(proto->eia,TRUE);
}
proto->hfid = -2;
}
lua_pop(L, 1);
return 0;
}
int Proto_commit(lua_State* L) {
lua_settop(L,0);
lua_rawgeti(L, LUA_REGISTRYINDEX, protocols_table_ref);
for (lua_pushnil(L); lua_next(L, 1); lua_pop(L, 2)) {
Proto proto = checkProto(L,3);
gint* ettp = NULL;
proto->hfa = g_array_new(TRUE,TRUE,sizeof(hf_register_info));
proto->etta = g_array_new(TRUE,TRUE,sizeof(gint*));
proto->eia = g_array_new(TRUE,TRUE,sizeof(ei_register_info));
ettp = &(proto->ett);
g_array_append_val(proto->etta,ettp);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->fields);
for (lua_pushnil(L); lua_next(L, 4); lua_pop(L, 1)) {
ProtoField f = checkProtoField(L,6);
hf_register_info hfri = { NULL, { NULL, NULL, FT_NONE, 0, NULL, 0, NULL, HFILL } };
ettp = &(f->ett);
hfri.p_id = &(f->hfid);
hfri.hfinfo.name = f->name;
hfri.hfinfo.abbrev = f->abbrev;
hfri.hfinfo.type = f->type;
hfri.hfinfo.display = f->base;
hfri.hfinfo.strings = VALS(f->vs);
hfri.hfinfo.bitmask = f->mask;
hfri.hfinfo.blurb = f->blob;
if (f->hfid != -2) {
return luaL_error(L,"fields can be registered only once");
}
f->hfid = -1;
g_array_append_val(proto->hfa,hfri);
g_array_append_val(proto->etta,ettp);
}
proto_register_field_array(proto->hfid,(hf_register_info*)(void*)proto->hfa->data,proto->hfa->len);
proto_register_subtree_array((gint**)(void*)proto->etta->data,proto->etta->len);
lua_pop(L,1);
lua_rawgeti(L, LUA_REGISTRYINDEX, proto->expert_info_table_ref);
for (lua_pushnil(L); lua_next(L, 4); lua_pop(L, 1)) {
ProtoExpert e = checkProtoExpert(L,6);
ei_register_info eiri = { NULL, { NULL, 0, 0, NULL, EXPFILL } };
eiri.ids = &(e->ids);
eiri.eiinfo.name = e->abbrev;
eiri.eiinfo.group = e->group;
eiri.eiinfo.severity = e->severity;
eiri.eiinfo.summary = e->text;
eiri.eiinfo.hf_info.hfinfo.name = g_strdup(eiri.eiinfo.hf_info.hfinfo.name);
if (e->ids.ei != EI_INIT_EI || e->ids.hf != EI_INIT_HF) {
return luaL_error(L,"expert fields can be registered only once");
}
g_array_append_val(proto->eia,eiri);
}
expert_register_field_array(proto->expert_module, (ei_register_info*)(void*)proto->eia->data, proto->eia->len);
}
lua_pop(L,1);
return 0;
}
static guint
wslua_dissect_tcp_get_pdu_len(packet_info *pinfo, tvbuff_t *tvb,
int offset, void *data)
{
func_saver_t* fs = (func_saver_t*)data;
lua_State* L = fs->state;
int pdu_len = 0;
lua_settop(L, 0);
lua_rawgeti(L, LUA_REGISTRYINDEX, fs->get_len_ref);
if (lua_isfunction(L,1)) {
push_Tvb(L,tvb);
push_Pinfo(L,pinfo);
lua_pushinteger(L,offset);
if ( lua_pcall(L,3,1,0) ) {
THROW_LUA_ERROR("Lua Error in dissect_tcp_pdus get_len_func: %s", lua_tostring(L,-1));
} else {
if (lua_isnumber(L, -1)) {
pdu_len = wslua_togint(L, -1);
lua_pop(L, 1);
} else {
THROW_LUA_ERROR("Lua Error dissect_tcp_pdus: get_len_func did not return a Lua number of the PDU length");
}
}
} else {
REPORT_DISSECTOR_BUG("Lua Error in dissect_tcp_pdus: did not find the get_len_func dissector");
}
return pdu_len;
}
static int
wslua_dissect_tcp_dissector(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data)
{
func_saver_t* fs = (func_saver_t*)data;
lua_State* L = fs->state;
int consumed_bytes = 0;
lua_settop(L, 0);
lua_rawgeti(L, LUA_REGISTRYINDEX, fs->dissect_ref);
if (lua_isfunction(L,1)) {
push_Tvb(L,tvb);
push_Pinfo(L,pinfo);
push_TreeItem(L, tree, (proto_item*)tree);
if ( lua_pcall(L,3,1,0) ) {
THROW_LUA_ERROR("dissect_tcp_pdus dissect_func: %s", lua_tostring(L, -1));
} else {
if (lua_isnumber(L, -1)) {
consumed_bytes = wslua_togint(L, -1);
lua_pop(L, 1);
}
}
} else {
REPORT_DISSECTOR_BUG("dissect_tcp_pdus: did not find the dissect_func dissector");
}
return consumed_bytes;
}
WSLUA_FUNCTION wslua_dissect_tcp_pdus(lua_State* L) {
#define WSLUA_ARG_dissect_tcp_pdus_TVB 1
#define WSLUA_ARG_dissect_tcp_pdus_TREE 2
#define WSLUA_ARG_dissect_tcp_pdus_MIN_HEADER_SIZE 3
#define WSLUA_ARG_dissect_tcp_pdus_GET_LEN_FUNC 4
#define WSLUA_ARG_dissect_tcp_pdus_DISSECT_FUNC 5
#define WSLUA_OPTARG_dissect_tcp_pdus_DESEGMENT 6
Tvb tvb = checkTvb(L,WSLUA_ARG_dissect_tcp_pdus_TVB);
TreeItem ti = checkTreeItem(L,WSLUA_ARG_dissect_tcp_pdus_TREE);
guint fixed_len = (guint)luaL_checkinteger(L,WSLUA_ARG_dissect_tcp_pdus_MIN_HEADER_SIZE);
gboolean proto_desegment = wslua_optbool(L, WSLUA_OPTARG_dissect_tcp_pdus_DESEGMENT, TRUE);
if (!lua_pinfo) {
luaL_error(L,"dissect_tcp_pdus can only be invoked while in a dissect function");
return 0;
}
if (lua_isfunction(L,WSLUA_ARG_dissect_tcp_pdus_GET_LEN_FUNC) &&
lua_isfunction(L,WSLUA_ARG_dissect_tcp_pdus_DISSECT_FUNC))
{
func_saver_t* fs = g_new(func_saver_t, 1);
lua_settop(L, WSLUA_ARG_dissect_tcp_pdus_DISSECT_FUNC);
fs->state = L;
fs->dissect_ref = luaL_ref(L, LUA_REGISTRYINDEX);
fs->get_len_ref = luaL_ref(L, LUA_REGISTRYINDEX);
g_ptr_array_add(outstanding_FuncSavers, fs);
WRAP_NON_LUA_EXCEPTIONS(
tcp_dissect_pdus(tvb->ws_tvb, lua_pinfo, ti->tree, proto_desegment,
fixed_len, wslua_dissect_tcp_get_pdu_len,
wslua_dissect_tcp_dissector, (void*)fs);
)
} else {
luaL_error(L,"The third and fourth arguments need to be Lua functions");
}
return 0;
}
