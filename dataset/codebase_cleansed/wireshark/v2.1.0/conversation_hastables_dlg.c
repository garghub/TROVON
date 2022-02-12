static guint
conversation_hash_exact(gconstpointer v)
{
const conversation_key *key = (const conversation_key *)v;
guint hash_val;
int i;
const guint8 *add_address_to_hash_data;
hash_val = 0;
#if 0
hash_val = add_address_to_hash(hash_val, &key->addr1);
hash_val += key->port1;
hash_val = add_address_to_hash(hash_val, &key->addr2);
hash_val += key->port2;
return hash_val;
#endif
for ( i = 0; i < key->addr1.len; i++ ) {
add_address_to_hash_data = (const guint8 *)((&key->addr1)->data);
hash_val += add_address_to_hash_data[i];
hash_val += ( hash_val << 10 );
hash_val ^= ( hash_val >> 6 );
}
for ( i = 0; i < 4; i++ ) {
add_address_to_hash_data = (const guint8 *)(&key->port1);
hash_val += add_address_to_hash_data[i];
hash_val += ( hash_val << 10 );
hash_val ^= ( hash_val >> 6 );
}
for ( i = 0; i < key->addr2.len; i++ ) {
add_address_to_hash_data = (const guint8 *)((&key->addr2)->data);
hash_val += add_address_to_hash_data[i];
hash_val += ( hash_val << 10 );
hash_val ^= ( hash_val >> 6 );
}
for ( i = 0; i < 4; i++ ) {
add_address_to_hash_data = (const guint8 *)(&key->port2);
hash_val += add_address_to_hash_data[i];
hash_val += ( hash_val << 10 );
hash_val ^= ( hash_val >> 6 );
}
hash_val += ( hash_val << 3 );
hash_val ^= ( hash_val >> 11 );
hash_val += ( hash_val << 15 );
return hash_val;
}
static guint
conversation_hash_exact_old(gconstpointer v)
{
const conversation_key *key = (const conversation_key *)v;
guint hash_val;
hash_val = 0;
hash_val = add_address_to_hash(hash_val, &key->addr1);
hash_val += key->port1;
hash_val = add_address_to_hash(hash_val, &key->addr2);
hash_val += key->port2;
return hash_val;
}
static void
conversation_hashtable_exact_to_texbuff(gpointer key, gpointer value _U_, gpointer user_data)
{
gchar string_buff[CONV_STR_BUF_MAX];
GtkTextBuffer *buffer = (GtkTextBuffer*)user_data;
conversation_key *conv_key = (conversation_key*)key;
g_snprintf(string_buff, CONV_STR_BUF_MAX, "Key:0x%x old key:0x%x\n",conversation_hash_exact(conv_key),conversation_hash_exact_old(conv_key));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
static void
conversation_info_to_texbuff(GtkTextBuffer *buffer)
{
gchar string_buff[CONV_STR_BUF_MAX];
GHashTable *conversation_hashtable_exact;
GHashTable *conversation_hashtable_no_addr2;
GHashTable *conversation_hashtable_no_port2;
GHashTable *conversation_hashtable_no_addr2_or_port2;
g_snprintf(string_buff, CONV_STR_BUF_MAX, "Conversation hastables info:\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
conversation_hashtable_exact = get_conversation_hashtable_exact();
if(conversation_hashtable_exact){
g_snprintf(string_buff, CONV_STR_BUF_MAX, "conversation_hashtable_exact %i entries\n#\n",
g_hash_table_size(conversation_hashtable_exact));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_hash_table_foreach( conversation_hashtable_exact, conversation_hashtable_exact_to_texbuff, buffer);
}
conversation_hashtable_no_addr2 = get_conversation_hashtable_no_addr2();
if(conversation_hashtable_no_addr2){
g_snprintf(string_buff, CONV_STR_BUF_MAX, "conversation_hashtable_no_addr2 %i entries\n#\n",
g_hash_table_size(conversation_hashtable_no_addr2));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
conversation_hashtable_no_port2 = get_conversation_hashtable_no_port2();
if(conversation_hashtable_no_port2){
g_snprintf(string_buff, CONV_STR_BUF_MAX, "conversation_hashtable_no_port2 %i entries\n#\n",
g_hash_table_size(conversation_hashtable_no_port2));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
conversation_hashtable_no_addr2_or_port2 = get_conversation_hashtable_no_addr2_or_port2();
if(conversation_hashtable_no_addr2_or_port2){
g_snprintf(string_buff, CONV_STR_BUF_MAX, "conversation_hashtable_no_addr2_or_port2 %i entries\n#\n",
g_hash_table_size(conversation_hashtable_no_addr2_or_port2));
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
}
void
conversation_hastables_dlg (GtkAction *action _U_, gpointer data _U_)
{
GtkWidget *vbox;
GtkWidget *view;
GtkWidget *scroll;
GtkWidget *bbox;
GtkWidget *ok_bt, *cancel_bt, *help_bt;
GtkTextBuffer *buffer;
conversation_hastables_dlg_w = dlg_window_new ("Conversation hastables");
gtk_widget_set_size_request (conversation_hastables_dlg_w, 750, 350);
gtk_window_set_resizable (GTK_WINDOW (conversation_hastables_dlg_w), TRUE);
gtk_container_set_border_width (GTK_CONTAINER (conversation_hastables_dlg_w), DLG_OUTER_MARGIN);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_add (GTK_CONTAINER (conversation_hastables_dlg_w), vbox);
gtk_widget_show (vbox);
view = gtk_text_view_new ();
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(view), GTK_WRAP_WORD);
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
#if GTK_CHECK_VERSION(3, 0, 0)
gtk_widget_override_font(view, user_font_get_regular());
#else
gtk_widget_modify_font(view, user_font_get_regular());
#endif
gtk_widget_show (view);
scroll = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(scroll), view);
gtk_widget_show(scroll);
gtk_box_pack_start(GTK_BOX (vbox), scroll, TRUE, TRUE, 0);
conversation_info_to_texbuff(buffer);
bbox = dlg_button_row_new (GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_end (GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_set_sensitive (ok_bt, TRUE);
cancel_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button (conversation_hastables_dlg_w, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_HELP);
#if 0
g_signal_connect (help_bt, "clicked",NULL, NULL);
#endif
gtk_widget_set_sensitive (help_bt, FALSE);
gtk_widget_grab_default (ok_bt);
gtk_widget_show (conversation_hastables_dlg_w);
}
