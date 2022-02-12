int
ssl_session_key_count(void)
{
return g_hash_table_size(ssl_session_hash) +
g_hash_table_size(ssl_crandom_hash);
}
static void
ssl_export_sessions_func(gpointer key, gpointer value, gpointer user_data)
{
guint i;
StringInfo *sslid = (StringInfo *)key;
StringInfo *master_secret = (StringInfo *)value;
GString *keylist = (GString *)user_data;
g_string_append(keylist, "RSA Session-ID:");
for (i = 0; i < sslid->data_len; i++) {
g_string_append_printf(keylist, "%.2x", sslid->data[i]);
}
g_string_append(keylist, " Master-Key:");
for (i = 0; i < master_secret->data_len; i++) {
g_string_append_printf(keylist, "%.2x", master_secret->data[i]);
}
g_string_append_c(keylist, '\n');
}
static void
ssl_export_client_randoms_func(gpointer key, gpointer value, gpointer user_data)
{
guint i;
StringInfo *client_random = (StringInfo *)key;
StringInfo *master_secret = (StringInfo *)value;
GString *keylist = (GString *)user_data;
g_string_append(keylist, "CLIENT_RANDOM ");
for (i = 0; i < client_random->data_len; i++) {
g_string_append_printf(keylist, "%.2x", client_random->data[i]);
}
g_string_append_c(keylist, ' ');
for (i = 0; i < master_secret->data_len; i++) {
g_string_append_printf(keylist, "%.2x", master_secret->data[i]);
}
g_string_append_c(keylist, '\n');
}
gchar*
ssl_export_sessions(void)
{
gsize len = 189 * g_hash_table_size(ssl_session_hash) +
177 * g_hash_table_size(ssl_crandom_hash);
GString *keylist = g_string_sized_new(len);
g_hash_table_foreach(ssl_session_hash, ssl_export_sessions_func, (gpointer)keylist);
g_hash_table_foreach(ssl_crandom_hash, ssl_export_client_randoms_func, (gpointer)keylist);
return g_string_free(keylist, FALSE);
}
