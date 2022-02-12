static void perf_gtk__signal(int sig)
{
perf_gtk__exit(false);
psignal(sig, "perf");
}
static void perf_gtk__resize_window(GtkWidget *window)
{
GdkRectangle rect;
GdkScreen *screen;
int monitor;
int height;
int width;
screen = gtk_widget_get_screen(window);
monitor = gdk_screen_get_monitor_at_window(screen, window->window);
gdk_screen_get_monitor_geometry(screen, monitor, &rect);
width = rect.width * 3 / 4;
height = rect.height * 3 / 4;
gtk_window_resize(GTK_WINDOW(window), width, height);
}
static void perf_gtk__show_hists(GtkWidget *window, struct hists *hists)
{
GType col_types[MAX_COLUMNS];
GtkCellRenderer *renderer;
struct sort_entry *se;
GtkListStore *store;
struct rb_node *nd;
u64 total_period;
GtkWidget *view;
int col_idx;
int nr_cols;
nr_cols = 0;
col_types[nr_cols++] = G_TYPE_STRING;
list_for_each_entry(se, &hist_entry__sort_list, list) {
if (se->elide)
continue;
col_types[nr_cols++] = G_TYPE_STRING;
}
store = gtk_list_store_newv(nr_cols, col_types);
view = gtk_tree_view_new();
renderer = gtk_cell_renderer_text_new();
col_idx = 0;
gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
-1, "Overhead (%)",
renderer, "text",
col_idx++, NULL);
list_for_each_entry(se, &hist_entry__sort_list, list) {
if (se->elide)
continue;
gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
-1, se->se_header,
renderer, "text",
col_idx++, NULL);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(view), GTK_TREE_MODEL(store));
g_object_unref(GTK_TREE_MODEL(store));
total_period = hists->stats.total_period;
for (nd = rb_first(&hists->entries); nd; nd = rb_next(nd)) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
GtkTreeIter iter;
double percent;
char s[512];
if (h->filtered)
continue;
gtk_list_store_append(store, &iter);
col_idx = 0;
percent = (h->period * 100.0) / total_period;
snprintf(s, ARRAY_SIZE(s), "%.2f", percent);
gtk_list_store_set(store, &iter, col_idx++, s, -1);
list_for_each_entry(se, &hist_entry__sort_list, list) {
if (se->elide)
continue;
se->se_snprintf(h, s, ARRAY_SIZE(s),
hists__col_len(hists, se->se_width_idx));
gtk_list_store_set(store, &iter, col_idx++, s, -1);
}
}
gtk_container_add(GTK_CONTAINER(window), view);
}
static GtkWidget *perf_gtk__setup_info_bar(void)
{
GtkWidget *info_bar;
GtkWidget *label;
GtkWidget *content_area;
info_bar = gtk_info_bar_new();
gtk_widget_set_no_show_all(info_bar, TRUE);
label = gtk_label_new("");
gtk_widget_show(label);
content_area = gtk_info_bar_get_content_area(GTK_INFO_BAR(info_bar));
gtk_container_add(GTK_CONTAINER(content_area), label);
gtk_info_bar_add_button(GTK_INFO_BAR(info_bar), GTK_STOCK_OK,
GTK_RESPONSE_OK);
g_signal_connect(info_bar, "response",
G_CALLBACK(gtk_widget_hide), NULL);
pgctx->info_bar = info_bar;
pgctx->message_label = label;
return info_bar;
}
static GtkWidget *perf_gtk__setup_statusbar(void)
{
GtkWidget *stbar;
unsigned ctxid;
stbar = gtk_statusbar_new();
ctxid = gtk_statusbar_get_context_id(GTK_STATUSBAR(stbar),
"perf report");
pgctx->statbar = stbar;
pgctx->statbar_ctx_id = ctxid;
return stbar;
}
