static gboolean
cfilter_combo_add(gchar *s) {
GList *li;
GList *fl = g_object_get_data(G_OBJECT(top_level), E_CFILTER_FL_KEY);
li = g_list_first(fl);
while (li) {
if (li->data && strcmp(s, li->data) == 0) {
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
GList *cfilter_list = g_object_get_data(G_OBJECT(top_level), E_CFILTER_FL_KEY);
GList *li;
guint max_count = 0;
li = g_list_first(cfilter_list);
while (li && (max_count++ <= cfilter_combo_max_recent) ) {
if (li->data && strlen(li->data)) {
fprintf (rf, RECENT_KEY_CAPTURE_FILTER ": %s\n", (char *)li->data);
}
li = li->next;
}
}
gboolean
cfilter_combo_add_recent(gchar *s) {
gchar *dup;
if (s) {
dup = g_strdup(s);
if (!cfilter_combo_add(dup)) {
g_free(dup);
return FALSE;
}
}
return TRUE;
}
