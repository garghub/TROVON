WSLUA_CONSTRUCTOR ProtoExpert_new(lua_State* L) {
#define WSLUA_ARG_ProtoExpert_new_ABBR 1
#define WSLUA_ARG_ProtoExpert_new_TEXT 2
#define WSLUA_ARG_ProtoExpert_new_GROUP 3
#define WSLUA_ARG_ProtoExpert_new_SEVERITY 4
ProtoExpert pe = NULL;
const gchar* abbr = wslua_checkstring_only(L,WSLUA_ARG_ProtoExpert_new_ABBR);
const gchar* text = wslua_checkstring_only(L,WSLUA_ARG_ProtoExpert_new_TEXT);
int group = (int)luaL_checkinteger(L, WSLUA_ARG_ProtoExpert_new_GROUP);
int severity = (int)luaL_checkinteger(L, WSLUA_ARG_ProtoExpert_new_SEVERITY);
if (!abbr[0]) {
luaL_argerror(L, WSLUA_ARG_ProtoExpert_new_ABBR, "Empty field name abbrev");
return 0;
}
if (proto_check_field_name(abbr)) {
luaL_argerror(L, WSLUA_ARG_ProtoExpert_new_ABBR, "Invalid char in abbrev");
return 0;
}
if (proto_registrar_get_byname(abbr)) {
luaL_argerror(L, WSLUA_ARG_ProtoExpert_new_ABBR, "This abbrev already exists");
return 0;
}
switch (group) {
case PI_CHECKSUM:
case PI_SEQUENCE:
case PI_RESPONSE_CODE:
case PI_REQUEST_CODE:
case PI_UNDECODED:
case PI_REASSEMBLE:
case PI_MALFORMED:
case PI_DEBUG:
case PI_PROTOCOL:
case PI_SECURITY:
case PI_COMMENTS_GROUP:
case PI_DECRYPTION:
case PI_DEPRECATED:
break;
default:
luaL_argerror(L, WSLUA_ARG_ProtoExpert_new_GROUP, "Group must be one of expert.group.*");
return 0;
}
switch (severity) {
case PI_COMMENT:
case PI_CHAT:
case PI_NOTE:
case PI_WARN:
case PI_ERROR:
break;
default:
luaL_argerror(L, WSLUA_ARG_ProtoExpert_new_SEVERITY, "Severity must be one of expert.severity.*");
return 0;
}
pe = g_new(wslua_expert_field_t,1);
pe->ids.ei = EI_INIT_EI;
pe->ids.hf = EI_INIT_HF;
pe->abbrev = g_strdup(abbr);
pe->text = g_strdup(text);
pe->group = group;
pe->severity = severity;
pushProtoExpert(L,pe);
WSLUA_RETURN(1);
}
WSLUA_METAMETHOD ProtoExpert__tostring(lua_State* L) {
ProtoExpert pe = toProtoExpert(L,1);
if (!pe) {
lua_pushstring(L,"ProtoExpert pointer is NULL!");
} else {
lua_pushfstring(L, "ProtoExpert: ei=%d, hf=%d, abbr=%s, text=%s, group=%d, severity=%d",
pe->ids.ei, pe->ids.hf, pe->abbrev, pe->text, pe->group, pe->severity);
}
return 1;
}
static int ProtoExpert__gc(lua_State* L) {
ProtoExpert pe = toProtoExpert(L,1);
if (pe->ids.hf == -2) {
g_free(pe);
}
return 0;
}
int ProtoExpert_register(lua_State* L) {
WSLUA_REGISTER_CLASS(ProtoExpert);
return 0;
}
