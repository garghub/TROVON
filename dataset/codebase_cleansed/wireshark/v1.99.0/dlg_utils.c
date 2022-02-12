static GtkWidget *
dlg_button_new(GtkWidget *hbox, GtkWidget *button_hbox, const gchar *stock_id)
{
GtkWidget *button;
button = ws_gtk_button_new_from_stock(stock_id);
gtk_widget_set_can_default(button, TRUE);
g_object_set_data(G_OBJECT(hbox), stock_id, button);
gtk_box_pack_end(GTK_BOX(button_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
return button;
}
void
dlg_button_focus_nth(GtkWidget *hbox, gint focus_item) {
GtkWidget *button_hbox, *button;
GList *children;
gint cur_item = 0;
if (!hbox)
return;
button_hbox = (GtkWidget *)g_object_get_data(G_OBJECT(hbox), BUTTON_HBOX_KEY);
children = gtk_container_get_children(GTK_CONTAINER(button_hbox));
while (children) {
if (cur_item == focus_item) {
button = (GtkWidget *)children->data;
gtk_widget_grab_focus(button);
gtk_widget_grab_default(button);
break;
}
children = g_list_next(children);
cur_item++;
}
g_list_free(children);
}
GtkWidget *
dlg_button_row_new(const gchar *stock_id_first, ...)
{
gint buttons = 0;
va_list stock_id_list;
const gchar *stock_id = stock_id_first;
GtkWidget *hbox;
GtkWidget *button_hbox;
GtkWidget *help_hbox;
GtkWidget *button;
const gchar *apply = NULL;
const gchar *cancel = NULL;
const gchar *cap_start = NULL;
const gchar *cap_stop = NULL;
const gchar *cap_options = NULL;
#ifdef _WIN32
const gchar *cap_details = NULL;
#endif
const gchar *clear = NULL;
const gchar *closex = NULL;
const gchar *copy = NULL;
const gchar *create_stat = NULL;
const gchar *delete_id = NULL;
const gchar *dont_save = NULL;
const gchar *filter_stream = NULL;
const gchar *find = NULL;
const gchar *help = NULL;
const gchar *jump = NULL;
const gchar *no = NULL;
const gchar *ok = NULL;
const gchar *print = NULL;
const gchar *save = NULL;
const gchar *save_as = NULL;
const gchar *save_all = NULL;
const gchar *stop = NULL;
const gchar *yes = NULL;
const gchar *refresh = NULL;
const gchar *add = NULL;
#ifdef HAVE_GEOIP
const gchar *map = NULL;
#endif
const gchar *follow_stream = NULL;
const gchar *graph_a_b = NULL;
const gchar *graph_b_a = NULL;
va_start(stock_id_list, stock_id_first);
while(stock_id != NULL) {
if (strcmp(stock_id, GTK_STOCK_OK) == 0) {
ok = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_CREATE_STAT) == 0) {
create_stat = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_APPLY) == 0) {
apply = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_SAVE) == 0) {
save = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_SAVE_AS) == 0) {
save_as = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_SAVE_ALL) == 0) {
save_all = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_DONT_SAVE) == 0) {
dont_save = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_QUIT_DONT_SAVE) == 0) {
dont_save = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_CANCEL) == 0) {
cancel = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_CLOSE) == 0) {
closex = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_CLEAR) == 0) {
clear = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_REFRESH) == 0) {
refresh = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_ADD) == 0) {
add = stock_id;
#ifdef HAVE_LIBPCAP
} else if (strcmp(stock_id, WIRESHARK_STOCK_CAPTURE_START) == 0) {
cap_start = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_CAPTURE_STOP) == 0) {
cap_stop = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_CAPTURE_OPTIONS) == 0) {
cap_options = stock_id;
#ifdef _WIN32
} else if (strcmp(stock_id, WIRESHARK_STOCK_CAPTURE_DETAILS) == 0) {
cap_details = stock_id;
#endif
#endif
#ifdef HAVE_GEOIP
} else if (strcmp(stock_id, WIRESHARK_STOCK_MAP) == 0) {
map = stock_id;
#endif
} else if (strcmp(stock_id, WIRESHARK_STOCK_FOLLOW_STREAM) == 0) {
follow_stream = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_STOP) == 0) {
stop = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_HELP) == 0) {
help = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_PRINT) == 0) {
print = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_FIND) == 0) {
find = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_JUMP_TO) == 0) {
jump = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_YES) == 0) {
yes = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_NO) == 0) {
no = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_FILTER_OUT_STREAM) == 0) {
filter_stream = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_DELETE) == 0) {
delete_id = stock_id;
} else if (strcmp(stock_id, GTK_STOCK_COPY) == 0) {
copy = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_GRAPH_A_B) == 0) {
graph_a_b = stock_id;
} else if (strcmp(stock_id, WIRESHARK_STOCK_GRAPH_B_A) == 0) {
graph_b_a = stock_id;
} else {
g_assert_not_reached();
}
buttons++;
stock_id = va_arg(stock_id_list, gchar *);
}
va_end(stock_id_list);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, DLG_BUTTON_SPACING, FALSE);
gtk_widget_show(hbox);
button_hbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_end(GTK_BOX(hbox), button_hbox, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(hbox), BUTTON_HBOX_KEY, button_hbox);
gtk_widget_show(button_hbox);
gtk_box_set_spacing(GTK_BOX(button_hbox), DLG_BUTTON_SPACING);
help_hbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_end(GTK_BOX(hbox), help_hbox, FALSE, FALSE, 0);
gtk_widget_show(help_hbox);
gtk_box_set_spacing(GTK_BOX(help_hbox), DLG_BUTTON_SPACING);
if (buttons == 0) {
return hbox;
}
if (buttons == 1) {
dlg_button_new(hbox, button_hbox, stock_id_first);
return hbox;
}
if (help) {
button = ws_gtk_button_new_from_stock(help);
gtk_widget_set_can_default(button, TRUE);
g_object_set_data(G_OBJECT(hbox), help, button);
gtk_box_pack_start(GTK_BOX(help_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
buttons--;
}
if (copy) {
button = ws_gtk_button_new_from_stock(copy);
gtk_widget_set_can_default(button, TRUE);
g_object_set_data(G_OBJECT(hbox), copy, button);
gtk_box_pack_start(GTK_BOX(help_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
buttons--;
}
if (refresh) {
button = ws_gtk_button_new_from_stock(refresh);
g_object_set_data(G_OBJECT(hbox), refresh, button);
gtk_box_pack_start(GTK_BOX(help_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
buttons--;
}
if (add) {
button = ws_gtk_button_new_from_stock(add);
g_object_set_data(G_OBJECT(hbox), add, button);
gtk_box_pack_start(GTK_BOX(help_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
buttons--;
}
#ifdef HAVE_GEOIP
if (map) {
button = ws_gtk_button_new_from_stock(map);
gtk_widget_set_can_default(button, TRUE);
g_object_set_data(G_OBJECT(hbox), map, button);
gtk_box_pack_start(GTK_BOX(help_hbox), button, FALSE, FALSE, 0);
gtk_widget_show(button);
buttons--;
}
#endif
gtk_button_box_set_layout (GTK_BUTTON_BOX(button_hbox), GTK_BUTTONBOX_END);
#if !defined(_WIN32)
if (buttons == 2) {
if (ok && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, ok);
return hbox;
}
if (print && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, print);
return hbox;
}
if (find && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, find);
return hbox;
}
if (jump && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, jump);
return hbox;
}
if (save && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, save);
return hbox;
}
if (ok && clear) {
dlg_button_new(hbox, button_hbox, clear);
dlg_button_new(hbox, button_hbox, ok);
return hbox;
}
if (save && closex) {
dlg_button_new(hbox, button_hbox, closex);
dlg_button_new(hbox, button_hbox, save);
return hbox;
}
if (create_stat && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, create_stat);
return hbox;
}
if (cap_start && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, cap_start);
return hbox;
}
if (cap_stop && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, cap_stop);
return hbox;
}
if (delete_id && cancel) {
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, delete_id);
return hbox;
}
}
if (buttons == 3) {
if (ok && save && closex) {
dlg_button_new(hbox, button_hbox, save);
dlg_button_new(hbox, button_hbox, closex);
dlg_button_new(hbox, button_hbox, ok);
return hbox;
}
if (ok && apply && cancel) {
dlg_button_new(hbox, button_hbox, apply);
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, ok);
return hbox;
}
if (apply && save && closex) {
dlg_button_new(hbox, button_hbox, save);
dlg_button_new(hbox, button_hbox, closex);
dlg_button_new(hbox, button_hbox, apply);
return hbox;
}
if (yes && no && cancel) {
dlg_button_new(hbox, button_hbox, no);
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, yes);
return hbox;
}
if (save && dont_save && cancel) {
dlg_button_new(hbox, button_hbox, dont_save);
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, save);
return hbox;
}
}
if (buttons == 4) {
if (ok && apply && save && cancel) {
dlg_button_new(hbox, button_hbox, save);
dlg_button_new(hbox, button_hbox, apply);
dlg_button_new(hbox, button_hbox, cancel);
dlg_button_new(hbox, button_hbox, ok);
return hbox;
}
if (ok && apply && save && closex) {
dlg_button_new(hbox, button_hbox, save);
dlg_button_new(hbox, button_hbox, apply);
dlg_button_new(hbox, button_hbox, closex);
dlg_button_new(hbox, button_hbox, ok);
return hbox;
}
}
#endif
if (ok != NULL) dlg_button_new(hbox, button_hbox, ok);
if (delete_id != NULL) dlg_button_new(hbox, button_hbox, delete_id);
if (jump != NULL) dlg_button_new(hbox, button_hbox, jump);
if (find != NULL) dlg_button_new(hbox, button_hbox, find);
if (print != NULL) dlg_button_new(hbox, button_hbox, print);
if (create_stat != NULL) dlg_button_new(hbox, button_hbox, create_stat);
if (apply != NULL) dlg_button_new(hbox, button_hbox, apply);
if (yes != NULL) dlg_button_new(hbox, button_hbox, yes);
if (no != NULL) dlg_button_new(hbox, button_hbox, no);
if (save != NULL) dlg_button_new(hbox, button_hbox, save);
if (save_as != NULL) dlg_button_new(hbox, button_hbox, save_as);
if (save_all != NULL) dlg_button_new(hbox, button_hbox, save_all);
if (dont_save != NULL) dlg_button_new(hbox, button_hbox, dont_save);
if (cap_start != NULL) dlg_button_new(hbox, button_hbox, cap_start);
if (cap_stop != NULL) dlg_button_new(hbox, button_hbox, cap_stop);
if (cap_options != NULL) dlg_button_new(hbox, button_hbox, cap_options);
#ifdef _WIN32
if (cap_details != NULL) dlg_button_new(hbox, button_hbox, cap_details);
#endif
if (stop != NULL) dlg_button_new(hbox, button_hbox, stop);
if (clear != NULL) dlg_button_new(hbox, button_hbox, clear);
if (filter_stream != NULL) dlg_button_new(hbox, button_hbox, filter_stream);
if (follow_stream != NULL) dlg_button_new(hbox, button_hbox, follow_stream);
if (graph_a_b != NULL) dlg_button_new(hbox, button_hbox, graph_a_b);
if (graph_b_a != NULL) dlg_button_new(hbox, button_hbox, graph_b_a);
if (closex != NULL) dlg_button_new(hbox, button_hbox, closex);
if (cancel != NULL) dlg_button_new(hbox, button_hbox, cancel);
return hbox;
}
GtkWidget *
dlg_window_new(const gchar *title)
{
GtkWidget *win;
win = window_new(GTK_WINDOW_TOPLEVEL, title);
#ifndef _WIN32
if (top_level) {
gtk_window_set_transient_for(GTK_WINDOW(win), GTK_WINDOW(top_level));
}
#endif
return win;
}
GtkWidget *
dlg_window_new_with_geom(const gchar *title, const gchar *geom_name, GtkWindowPosition pos)
{
GtkWidget *win;
win = window_new_with_geom(GTK_WINDOW_TOPLEVEL, title, geom_name ? geom_name : title, pos);
#ifndef _WIN32
if (top_level) {
gtk_window_set_transient_for(GTK_WINDOW(win), GTK_WINDOW(top_level));
}
#endif
return win;
}
GtkWidget *
dlg_conf_window_new(const gchar *title)
{
const char *profile_name;
gchar *win_name;
GtkWidget *win;
profile_name = get_profile_name();
win_name = g_strdup_printf("%s - Profile: %s", title, profile_name);
win = dlg_window_new(win_name);
g_free(win_name);
return win;
}
void
dlg_set_activate(GtkWidget *widget, GtkWidget *ok_button)
{
g_signal_connect(widget, "activate", G_CALLBACK(dlg_activate), ok_button);
}
static void
dlg_activate (GtkWidget *widget _U_, gpointer ok_button)
{
gtk_widget_activate(GTK_WIDGET(ok_button));
}
