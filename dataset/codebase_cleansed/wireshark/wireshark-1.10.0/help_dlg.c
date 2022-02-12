void help_redraw(void)
{
GSList *help_page_ent;
help_page_t *help_page;
if (help_w != NULL) {
for (help_page_ent = help_text_pages; help_page_ent != NULL;
help_page_ent = g_slist_next(help_page_ent))
{
help_page = (help_page_t *)help_page_ent->data;
text_page_redraw(help_page->page, help_page->pathname);
}
}
}
void
topic_action(topic_action_e action)
{
char *url;
url = topic_action_url(action);
if(url != NULL) {
browser_open_url(url);
g_free(url);
}
}
void
topic_cb(GtkWidget *w _U_, topic_action_e action)
{
topic_action(action);
}
gboolean
topic_menu_cb(GtkWidget *w _U_, GdkEventButton *event _U_, gpointer user_data)
{
topic_action((topic_action_e)GPOINTER_TO_INT(user_data));
return TRUE;
}
