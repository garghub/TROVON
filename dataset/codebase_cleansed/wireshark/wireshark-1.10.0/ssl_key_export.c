int
ssl_session_key_count(void)
{
return g_hash_table_size(ssl_session_hash);
}
static void
ssl_export_sessions_func(gpointer key, gpointer value, gpointer user_data)
{
guint i;
StringInfo* sslid = (StringInfo*)key;
StringInfo* mastersecret = (StringInfo*)value;
GString* keylist = (GString*)user_data;
g_string_append(keylist, "RSA Session-ID:");
for( i=0; i<sslid->data_len; i++) {
g_string_append_printf(keylist, "%.2x", sslid->data[i]&255);
}
g_string_append(keylist, " Master-Key:");
for( i=0; i<mastersecret->data_len; i++) {
g_string_append_printf(keylist, "%.2x", mastersecret->data[i]&255);
}
g_string_append_c(keylist, '\n');
}
gchar*
ssl_export_sessions(void)
{
GString* keylist = g_string_new("");
gchar *session_keys;
g_hash_table_foreach(ssl_session_hash, ssl_export_sessions_func, (gpointer)keylist);
session_keys = keylist->str;
g_string_free(keylist, FALSE);
return session_keys;
}
