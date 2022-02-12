void create_wth_priv(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*)g_malloc(sizeof(file_priv_t));
if (wth->priv != NULL) {
luaL_error(L, "Cannot create wtap private data because there already is private data");
return;
}
priv->table_ref = LUA_NOREF;
wth->priv = (void*) priv;
}
int get_wth_priv_table_ref(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*) wth->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap private data: it is null");
return LUA_NOREF;
}
lua_rawgeti(L, LUA_REGISTRYINDEX, priv->table_ref);
return 1;
}
int set_wth_priv_table_ref(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*) wth->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap private data: it is null");
return 0;
}
if (lua_isnil(L, -1)){
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
priv->table_ref = LUA_NOREF;
return 0;
}
if (!lua_istable(L, -1)) {
luaL_error(L, "The private_table member can only be set to a table or nil");
return 0;
}
if (priv->table_ref != LUA_NOREF) {
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
}
priv->table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
return 0;
}
void remove_wth_priv(lua_State* L, wtap *wth) {
file_priv_t *priv = (file_priv_t*) wth->priv;
if (!priv) {
luaL_error(L, "Cannot remove wtap private data: it is null");
return;
}
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
g_free(wth->priv);
wth->priv = NULL;
}
void create_wdh_priv(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*)g_malloc(sizeof(file_priv_t));
if (wdh->priv != NULL) {
luaL_error(L, "Cannot create wtap_dumper private data because there already is private data");
return;
}
priv->table_ref = LUA_NOREF;
wdh->priv = (void*) priv;
}
int get_wdh_priv_table_ref(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*) wdh->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap_dumper private data: it is null");
return LUA_NOREF;
}
lua_rawgeti(L, LUA_REGISTRYINDEX, priv->table_ref);
return 1;
}
int set_wdh_priv_table_ref(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*) wdh->priv;
if (!priv) {
luaL_error(L, "Cannot get wtap private data: it is null");
return 0;
}
if (lua_isnil(L, -1)){
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
priv->table_ref = LUA_NOREF;
return 0;
}
if (!lua_istable(L, -1)) {
luaL_error(L, "The private_table member can only be set to a table or nil");
return 0;
}
if (priv->table_ref != LUA_NOREF) {
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
}
priv->table_ref = luaL_ref(L, LUA_REGISTRYINDEX);
return 0;
}
void remove_wdh_priv(lua_State* L, wtap_dumper *wdh) {
file_priv_t *priv = (file_priv_t*) wdh->priv;
if (!priv) {
luaL_error(L, "Cannot remove wtap_dumper private data: it is null");
return;
}
luaL_unref(L, LUA_REGISTRYINDEX, priv->table_ref);
}
