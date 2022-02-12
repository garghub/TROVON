int
ResolveWin32UUID(e_guid_t if_id, char *uuid_name, int uuid_name_max_len)
{
TCHAR *reg_uuid_name;
HKEY hKey = NULL;
DWORD uuid_max_size = MAX_PATH;
TCHAR *reg_uuid_str;
reg_uuid_name=ep_alloc(MAX_PATH*sizeof(TCHAR));
reg_uuid_str=ep_alloc(MAX_PATH*sizeof(TCHAR));
if(uuid_name_max_len < 2){
return 0;
}
reg_uuid_name[0] = '\0';
_snwprintf(reg_uuid_str, MAX_PATH, _T("SOFTWARE\\Classes\\Interface\\{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}"),
if_id.data1, if_id.data2, if_id.data3,
if_id.data4[0], if_id.data4[1],
if_id.data4[2], if_id.data4[3],
if_id.data4[4], if_id.data4[5],
if_id.data4[6], if_id.data4[7]);
if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, reg_uuid_str, 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS) {
if (RegQueryValueEx(hKey, NULL, NULL, NULL, (LPBYTE)reg_uuid_name, &uuid_max_size) == ERROR_SUCCESS && uuid_max_size <= MAX_PATH) {
g_snprintf(uuid_name, uuid_name_max_len, "%s", utf_16to8(reg_uuid_name));
RegCloseKey(hKey);
return (int) strlen(uuid_name);
}
RegCloseKey(hKey);
}
return 0;
}
void
guids_add_guid(e_guid_t *guid, const gchar *name)
{
emem_tree_key_t guidkey[2];
guint32 g[4];
g[0]=guid->data1;
g[1]=guid->data2;
g[1]<<=16;
g[1]|=guid->data3;
g[2]=guid->data4[0];
g[2]<<=8;
g[2]|=guid->data4[1];
g[2]<<=8;
g[2]|=guid->data4[2];
g[2]<<=8;
g[2]|=guid->data4[3];
g[3]=guid->data4[4];
g[3]<<=8;
g[3]|=guid->data4[5];
g[3]<<=8;
g[3]|=guid->data4[6];
g[3]<<=8;
g[3]|=guid->data4[7];
guidkey[0].key=g;
guidkey[0].length=4;
guidkey[1].length=0;
pe_tree_insert32_array(guid_to_name_tree, &guidkey[0], (gchar *) name);
}
const gchar *
guids_get_guid_name(e_guid_t *guid)
{
emem_tree_key_t guidkey[2];
guint32 g[4];
char *name;
#ifdef _WIN32
static char *uuid_name;
#endif
g[0]=guid->data1;
g[1]=guid->data2;
g[1]<<=16;
g[1]|=guid->data3;
g[2]=guid->data4[0];
g[2]<<=8;
g[2]|=guid->data4[1];
g[2]<<=8;
g[2]|=guid->data4[2];
g[2]<<=8;
g[2]|=guid->data4[3];
g[3]=guid->data4[4];
g[3]<<=8;
g[3]|=guid->data4[5];
g[3]<<=8;
g[3]|=guid->data4[6];
g[3]<<=8;
g[3]|=guid->data4[7];
guidkey[0].key=g;
guidkey[0].length=4;
guidkey[1].length=0;
if((name = pe_tree_lookup32_array(guid_to_name_tree, &guidkey[0]))){
return name;
}
#ifdef _WIN32
uuid_name=ep_alloc(128);
if(ResolveWin32UUID(*guid, uuid_name, 128)) {
return uuid_name;
}
#endif
return NULL;
}
void
guids_init(void)
{
guid_to_name_tree=pe_tree_create(EMEM_TREE_TYPE_RED_BLACK, "guid_to_name");
}
const gchar *
guids_resolve_guid_to_str(e_guid_t *guid)
{
const gchar *name;
name=guids_get_guid_name(guid);
if(name){
return name;
}
return ep_strdup_printf("%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
guid->data1, guid->data2, guid->data3,
guid->data4[0], guid->data4[1],
guid->data4[2], guid->data4[3],
guid->data4[4], guid->data4[5],
guid->data4[6], guid->data4[7]);
}
