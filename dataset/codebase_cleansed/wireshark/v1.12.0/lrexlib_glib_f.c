int Gregex_get_compile_flags (lua_State *L) {
const flag_pair* fps[] = { gregex_compile_flags, NULL };
return get_flags (L, fps);
}
int Gregex_get_match_flags (lua_State *L) {
const flag_pair* fps[] = { gregex_match_flags, NULL };
return get_flags (L, fps);
}
int Gregex_get_flags (lua_State *L) {
const flag_pair* fps[] = { gregex_compile_flags, gregex_match_flags, gregex_error_flags, NULL };
return get_flags (L, fps);
}
