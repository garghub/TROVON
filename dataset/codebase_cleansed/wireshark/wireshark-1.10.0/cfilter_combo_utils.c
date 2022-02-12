static gboolean
cfilter_combo_add(gchar *s) {
GList *li;
GList *fl = (GList*)g_object_get_data(G_OBJECT(top_level), E_CFILTER_FL_KEY);
li = g_list_first(fl);
while (li) {
if (li->data && strcmp(s, (char *)li->data) == 0) {
fl = g_list_remove(fl, li->data);
break;
}
li = li->next;
}
fl = g_list_append(fl, s);
g_object_set_data(G_OBJECT(top_level), E_CFILTER_FL_KEY, fl);
return TRUE;
}
void
cfilter_combo_recent_write_all(FILE *rf) {
GList *cfilter_list = (GList*)g_object_get_data(G_OBJECT(top_level), E_CFILTER_FL_KEY);
GList *li;
guint max_count = 0;
li = g_list_first(cfilter_list);
while (li && (max_count++ <= cfilter_combo_max_recent) ) {
if (li->data && strlen((const char *)li->data)) {
fprintf (rf, RECENT_KEY_CAPTURE_FILTER ": %s\n", (char *)li->data);
}
li = li->next;
}
}
gboolean
cfilter_combo_add_recent(const gchar *s) {
gchar *dupstr;
if (s) {
dupstr = g_strdup(s);
if (!cfilter_combo_add(dupstr)) {
g_free(dupstr);
return FALSE;
}
}
return TRUE;
}
