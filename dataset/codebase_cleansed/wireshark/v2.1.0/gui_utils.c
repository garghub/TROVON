static void
window_icon_realize_cb(GtkWidget *win,
gpointer data _U_)
{
#ifndef _WIN32
GList *ws_icon_list = NULL;
GdkPixbuf *icon16, *icon32, *icon48, *icon64;
#ifdef HAVE_GDK_GRESOURCE
icon16 = ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon16.png");
icon32 = ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon32.png");
icon48 = ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon48.png");
icon64 = ws_gdk_pixbuf_new_from_resource("/org/wireshark/image/wsicon64.png");
#else
icon16 = gdk_pixbuf_new_from_inline(-1, wsicon_16_pb_data, FALSE, NULL);
icon32 = gdk_pixbuf_new_from_inline(-1, wsicon_32_pb_data, FALSE, NULL);
icon48 = gdk_pixbuf_new_from_inline(-1, wsicon_48_pb_data, FALSE, NULL);
icon64 = gdk_pixbuf_new_from_inline(-1, wsicon_64_pb_data, FALSE, NULL);
#endif
ws_icon_list = g_list_append(ws_icon_list, icon16);
ws_icon_list = g_list_append(ws_icon_list, icon32);
ws_icon_list = g_list_append(ws_icon_list, icon48);
ws_icon_list = g_list_append(ws_icon_list, icon64);
gtk_window_set_icon_list(GTK_WINDOW(win), ws_icon_list);
g_list_foreach(ws_icon_list, (GFunc)g_object_unref, NULL);
g_list_free(ws_icon_list);
gtk_window_set_icon_name(GTK_WINDOW(win), "wireshark");
#endif
}
GtkWidget *
window_new(GtkWindowType type,
const gchar *title)
{
GtkWidget *win;
win = gtk_window_new(type);
if (title != NULL)
gtk_window_set_title(GTK_WINDOW(win), title);
g_signal_connect(win, "realize", G_CALLBACK(window_icon_realize_cb), NULL);
gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_NONE);
if (top_level) {
GdkScreen *default_screen;
gint x, y, n;
default_screen = gdk_screen_get_default();
n = gdk_screen_get_n_monitors(default_screen);
if (n > 1) {
gtk_window_get_position(GTK_WINDOW(top_level), &x, &y);
n = gdk_screen_get_monitor_at_point(default_screen, x, y);
if (n > 0)
gtk_window_move(GTK_WINDOW(win), x + 40, y + 30);
}
}
return win;
}
GtkWidget *
window_new_with_geom(GtkWindowType type,
const gchar *title,
const gchar *geom_name,
GtkWindowPosition pos)
{
window_geometry_t geom;
GtkWidget *win = window_new(type, title);
g_object_set_data(G_OBJECT(win), WINDOW_GEOM_KEY, (gpointer)g_strdup(geom_name));
if(geom_name) {
if(window_geom_load(geom_name, &geom)) {
geom.set_pos = TRUE;
geom.set_size = TRUE;
geom.set_maximized = FALSE;
window_set_geometry(win, &geom);
} else if (pos != GTK_WIN_POS_NONE) {
#ifdef _WIN32
if (pos == GTK_WIN_POS_CENTER_ON_PARENT)
pos = GTK_WIN_POS_CENTER;
#endif
gtk_window_set_position(GTK_WINDOW(win), pos);
}
}
return win;
}
GtkWidget *
splash_window_new(void)
{
GtkWidget *win;
win = window_new(GTK_WINDOW_TOPLEVEL, "Wireshark");
gtk_window_set_decorated(GTK_WINDOW(win), FALSE);
gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
return win;
}
void
window_present(GtkWidget *win)
{
window_geometry_t geom;
const gchar *name;
gtk_window_present(GTK_WINDOW(win));
name = (const gchar *)g_object_get_data(G_OBJECT(win), WINDOW_GEOM_KEY);
if(name) {
if(window_geom_load(name, &geom)) {
geom.set_pos = TRUE;
geom.set_size = TRUE;
geom.set_maximized = TRUE;
window_set_geometry(win, &geom);
}
}
}
static gboolean
window_key_press_cb(GtkWidget *widget,
GdkEventKey *event,
gpointer cancel_button)
{
g_return_val_if_fail(widget != NULL, FALSE);
g_return_val_if_fail(event != NULL, FALSE);
if (event->keyval == GDK_Escape) {
gtk_widget_activate(GTK_WIDGET(cancel_button));
return TRUE;
}
return FALSE;
}
static void
window_set_cancel(GtkWidget *widget,
GtkWidget *cancel_button)
{
g_signal_connect(widget, "key_press_event", G_CALLBACK(window_key_press_cb), cancel_button);
}
void
window_set_cancel_button(GtkWidget *win,
GtkWidget *bt,
window_cancel_button_fct cb)
{
if(cb)
g_signal_connect(bt, "clicked", G_CALLBACK(cb), win);
gtk_widget_grab_default(bt);
window_set_cancel(win, bt);
}
void
window_cancel_button_cb(GtkWidget *w _U_,
gpointer data)
{
window_destroy(GTK_WIDGET(data));
}
gboolean
window_delete_event_cb(GtkWidget *win,
GdkEvent *event _U_,
gpointer user_data _U_)
{
window_destroy(win);
return TRUE;
}
void
window_get_geometry(GtkWidget *widget,
window_geometry_t *geom)
{
GdkWindowState state;
GdkWindow *widget_window;
memset(geom, 0, sizeof(window_geometry_t));
widget_window = gtk_widget_get_window(widget);
gdk_window_get_root_origin(widget_window,
&geom->x,
&geom->y);
#if GTK_CHECK_VERSION(2,24,0)
geom->width = gdk_window_get_width(widget_window);
geom->height = gdk_window_get_height(widget_window);
#else
gdk_drawable_get_size(widget_window,
&geom->width,
&geom->height);
#endif
state = gdk_window_get_state(widget_window);
geom->maximized = ((state & GDK_WINDOW_STATE_MAXIMIZED) != 0);
}
static void
window_adjust_if_obscured(window_geometry_t *geom)
{
MONITORINFO MonitorInfo;
HMONITOR hMonitor;
POINT pt, vs;
DWORD dwFlags = MONITOR_DEFAULTTONEAREST;
vs.x = GetSystemMetrics(SM_XVIRTUALSCREEN);
vs.y = GetSystemMetrics(SM_YVIRTUALSCREEN);
pt.x = geom->x + vs.x;
pt.y = geom->y + vs.y;
MonitorInfo.cbSize = sizeof(MONITORINFO);
hMonitor = MonitorFromPoint(pt, dwFlags);
if (GetMonitorInfo(hMonitor, &MonitorInfo)) {
if (pt.x < MonitorInfo.rcWork.left)
geom->x += MonitorInfo.rcWork.left - pt.x;
if (pt.y < MonitorInfo.rcWork.top)
geom->y += MonitorInfo.rcWork.top - pt.y;
}
}
void
window_set_geometry(GtkWidget *widget,
window_geometry_t *geom)
{
GdkScreen *default_screen;
GdkRectangle viewable_area;
gint monitor_num;
if (geom->set_pos && geom->x != -32000 && geom->y != -32000) {
default_screen = gdk_screen_get_default();
monitor_num = gdk_screen_get_monitor_at_point(default_screen,
geom->x, geom->y);
gdk_screen_get_monitor_geometry(default_screen, monitor_num,
&viewable_area);
if(geom->x < viewable_area.x || geom->x > (viewable_area.x + viewable_area.width))
geom->x = viewable_area.x;
if(geom->y < viewable_area.y || geom->y > (viewable_area.y + viewable_area.height))
geom->y = viewable_area.y;
#ifdef _WIN32
window_adjust_if_obscured(geom);
#endif
gtk_window_move(GTK_WINDOW(widget),
geom->x,
geom->y);
}
if (geom->set_size) {
gtk_window_resize(GTK_WINDOW(widget),
geom->width,
geom->height);
}
if(geom->set_maximized) {
if (geom->maximized) {
gdk_window_maximize(gtk_widget_get_window(widget));
} else {
gdk_window_unmaximize(gtk_widget_get_window(widget));
}
}
}
void
window_destroy(GtkWidget *win)
{
window_geometry_t geom;
const gchar *name;
if (!win)
return;
if(gtk_widget_get_has_window(win) && gtk_widget_get_visible(win)) {
window_get_geometry(win, &geom);
name = (const gchar *)g_object_get_data(G_OBJECT(win), WINDOW_GEOM_KEY);
if(name) {
window_geom_save(name, &geom);
g_free((gpointer)name);
}
}
gtk_widget_destroy(win);
}
static GtkWidget *
_gtk_image_new_from_pixbuf_unref(GdkPixbuf *pixbuf) {
GtkWidget *widget;
widget = gtk_image_new_from_pixbuf(pixbuf);
g_object_unref(pixbuf);
return widget;
}
GtkWidget *
xpm_to_widget(const char **xpm) {
GdkPixbuf *pixbuf;
pixbuf = gdk_pixbuf_new_from_xpm_data(xpm);
return _gtk_image_new_from_pixbuf_unref(pixbuf);
}
void
bad_dfilter_alert_box(GtkWidget *parent,
const char *dftext,
gchar *err_msg)
{
GtkWidget *msg_dialog;
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_ERROR,
GTK_BUTTONS_OK,
"The filter expression \"%s\" isn't a valid display filter. (%s)",
dftext, err_msg);
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"See the help for a description of the display filter syntax.");
gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
}
void
main_window_update(void)
{
while (gtk_events_pending())
gtk_main_iteration();
}
void
main_window_nested_quit(void)
{
if (gtk_main_level() > 0)
gtk_main_quit();
}
void
main_window_quit(void)
{
gtk_main_quit();
}
static gboolean
pipe_timer_cb(gpointer data)
{
HANDLE handle;
DWORD avail = 0;
gboolean result;
DWORD childstatus;
pipe_input_t *pipe_input = data;
gint iterations = 0;
while(iterations < 5) {
handle = (HANDLE)_get_osfhandle(pipe_input->source);
result = PeekNamedPipe(handle, NULL, 0, NULL, &avail, NULL);
GetExitCodeProcess((HANDLE)*(pipe_input->child_process), &childstatus);
if (!result || avail > 0 || childstatus != STILL_ACTIVE) {
if(pipe_input->pipe_input_id != 0) {
g_source_remove(pipe_input->pipe_input_id);
pipe_input->pipe_input_id = 0;
}
if (!pipe_input->input_cb(pipe_input->source, pipe_input->user_data)) {
g_log(NULL, G_LOG_LEVEL_DEBUG, "pipe_timer_cb: input pipe closed, iterations: %u", iterations);
return FALSE;
}
}
else {
break;
}
iterations++;
}
if(pipe_input->pipe_input_id == 0) {
pipe_input->pipe_input_id = g_timeout_add(200, pipe_timer_cb, data);
return FALSE;
} else {
return TRUE;
}
}
static gboolean
pipe_input_cb(GIOChannel *source _U_,
GIOCondition condition _U_,
gpointer data)
{
pipe_input_t *pipe_input = (pipe_input_t *)data;
g_source_remove(pipe_input->pipe_input_id);
if (pipe_input->input_cb(pipe_input->source, pipe_input->user_data)) {
pipe_input->pipe_input_id = g_io_add_watch_full(pipe_input->channel,
G_PRIORITY_HIGH,
(GIOCondition)(G_IO_IN|G_IO_ERR|G_IO_HUP),
pipe_input_cb,
pipe_input,
NULL);
}
return TRUE;
}
void
pipe_input_set_handler(gint source,
gpointer user_data,
ws_process_id *child_process,
pipe_input_cb_t input_cb)
{
static pipe_input_t pipe_input;
pipe_input.source = source;
pipe_input.child_process = child_process;
pipe_input.user_data = user_data;
pipe_input.input_cb = input_cb;
#ifdef _WIN32
pipe_input.pipe_input_id = g_timeout_add(200, pipe_timer_cb, &pipe_input);
#else
pipe_input.channel = g_io_channel_unix_new(source);
g_io_channel_set_encoding(pipe_input.channel, NULL, NULL);
pipe_input.pipe_input_id = g_io_add_watch_full(pipe_input.channel,
G_PRIORITY_HIGH,
(GIOCondition)(G_IO_IN|G_IO_ERR|G_IO_HUP),
pipe_input_cb,
&pipe_input,
NULL);
#endif
}
void
reactivate_window(GtkWidget *win)
{
GdkWindow *win_window;
win_window = gtk_widget_get_window(win);
gdk_window_show(win_window);
gdk_window_raise(win_window);
}
GtkWidget *
scrolled_window_new(GtkAdjustment *hadjustment,
GtkAdjustment *vadjustment)
{
GtkWidget *scrollw;
scrollw = gtk_scrolled_window_new(hadjustment, vadjustment);
setup_scrolled_window(scrollw);
return scrollw;
}
static void
setup_scrolled_window(GtkWidget *scrollw)
{
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollw),
GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
#if GTK_CHECK_VERSION(3,16,0)
gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrollw), FALSE);
#endif
scrolled_windows = g_list_append(scrolled_windows, scrollw);
g_signal_connect(scrollw, "destroy", G_CALLBACK(forget_scrolled_window), NULL);
}
static void
forget_scrolled_window(GtkWidget *scrollw,
gpointer data _U_)
{
scrolled_windows = g_list_remove(scrolled_windows, scrollw);
}
GtkWidget *
tree_view_new(GtkTreeModel *model)
{
GtkWidget *tree;
tree = gtk_tree_view_new_with_model(model);
setup_tree(tree);
return tree;
}
static void
setup_tree(GtkWidget *tree)
{
set_tree_styles(tree);
trees = g_list_append(trees, tree);
g_signal_connect(tree, "destroy", G_CALLBACK(forget_tree), NULL);
g_signal_connect(tree, "key-press-event", G_CALLBACK(tree_view_key_pressed_cb), NULL );
}
static void
forget_tree(GtkWidget *tree,
gpointer data _U_)
{
trees = g_list_remove(trees, tree);
}
static void
set_tree_styles(GtkWidget *tree)
{
g_assert(prefs.gui_altern_colors >= 0 && prefs.gui_altern_colors <= 1);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(tree),
prefs.gui_altern_colors);
}
static void
set_tree_styles_cb(gpointer data,
gpointer user_data _U_)
{
set_tree_styles((GtkWidget *)data);
}
void
set_tree_styles_all(void)
{
g_list_foreach(trees, set_tree_styles_cb, NULL);
}
gboolean
tree_view_list_store_move_selection(GtkTreeView *tree,
gboolean move_up)
{
GtkTreeIter from, to;
GtkTreeModel *model;
GtkTreeSelection *sel;
GtkTreePath *path_from, *path_to;
sel = gtk_tree_view_get_selection(tree);
if (!gtk_tree_selection_get_selected(sel, &model, &from)) {
return FALSE;
}
path_from = gtk_tree_model_get_path(model, &from);
if (!path_from) {
return FALSE;
}
path_to = gtk_tree_path_copy(path_from);
if (move_up) {
gtk_tree_path_prev(path_to);
} else {
gtk_tree_path_next(path_to);
}
if (gtk_tree_path_compare(path_from, path_to) == 0) {
gtk_tree_path_free(path_from);
gtk_tree_path_free(path_to);
return FALSE;
}
gtk_tree_model_get_iter(model, &to, path_to);
gtk_list_store_swap(GTK_LIST_STORE(model), &from, &to);
gtk_tree_path_free(path_from);
gtk_tree_path_free(path_to);
return TRUE;
}
gint
tree_view_list_store_get_selected_row(GtkTreeView *tree) {
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
GtkTreePath *path;
gchar *path_str;
gint row;
sel = gtk_tree_view_get_selection(tree);
if (!gtk_tree_selection_get_selected(sel, &model, &iter)) {
return -1;
}
path = gtk_tree_model_get_path(model, &iter);
if (!path) {
return FALSE;
}
path_str = gtk_tree_path_to_string(path);
gtk_tree_path_free(path);
row = (gint)strtol(path_str, NULL, 10);
g_free(path_str);
return row;
}
void
simple_list_append(GtkWidget *list,
...)
{
va_list ap;
GtkTreeIter iter;
GtkListStore *store;
va_start(ap, list);
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
gtk_list_store_append(store, &iter);
gtk_list_store_set_valist(store, &iter, ap);
va_end(ap);
}
GtkWidget *
simple_list_new(gint cols,
const gchar **titles) {
GtkWidget *plugins_list;
int i;
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
g_assert(cols <= 10);
store = gtk_list_store_new(cols,
G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
plugins_list = tree_view_new(GTK_TREE_MODEL(store));
g_object_unref(G_OBJECT(store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(plugins_list), (titles != NULL));
for(i=0; i<cols; i++) {
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(titles ? titles[i] : "", renderer,
"text", i, NULL);
gtk_tree_view_column_set_sort_column_id(column, i);
gtk_tree_view_append_column(GTK_TREE_VIEW(plugins_list), column);
}
return plugins_list;
}
void
render_as_url(GtkCellRenderer *cell)
{
g_object_set(cell, "foreground", "blue", NULL);
g_object_set(cell, "foreground-set", TRUE, NULL);
g_object_set(cell, "underline", PANGO_UNDERLINE_SINGLE, NULL);
g_object_set(cell, "underline-set", TRUE, NULL);
}
void
simple_list_url_col(GtkWidget *list,
gint col)
{
GtkTreeViewColumn *ul_column;
GList *renderers_list;
GtkCellRenderer *ul_renderer;
ul_column = gtk_tree_view_get_column(GTK_TREE_VIEW(list), col);
renderers_list = gtk_cell_layout_get_cells(GTK_CELL_LAYOUT(ul_column));
if(renderers_list != NULL) {
ul_renderer = (GtkCellRenderer*)renderers_list->data;
render_as_url(ul_renderer);
g_list_free(renderers_list);
}
}
void
copy_to_clipboard(GString *str)
{
GtkClipboard *cb;
cb = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
gtk_clipboard_set_text(cb, str->str, -1);
}
static copy_binary_t *
create_copy_binary_t(const guint8 *data,
int len)
{
copy_binary_t* copy_data;
g_assert(len > 0);
copy_data = g_new(copy_binary_t,1);
copy_data->data = g_new(guint8,len);
copy_data->len = len;
memcpy(copy_data->data,data,len * sizeof(guint8));
return copy_data;
}
static void
destroy_copy_binary_t(copy_binary_t *copy_data) {
g_free(copy_data->data);
g_free(copy_data);
}
static void
copy_binary_free_cb(GtkClipboard *clipboard _U_,
gpointer user_data_or_owner)
{
destroy_copy_binary_t((copy_binary_t*)user_data_or_owner);
}
static void
copy_binary_get_cb(GtkClipboard *clipboard _U_,
GtkSelectionData *selection_data,
guint info _U_,
gpointer user_data_or_owner)
{
copy_binary_t* copy_data;
copy_data = (copy_binary_t*)user_data_or_owner;
gtk_selection_data_set(selection_data, GDK_NONE, 8, copy_data->data, copy_data->len);
}
void
copy_binary_to_clipboard(const guint8 *data_p,
int len)
{
static GtkTargetEntry target_entry[] = {
{"application/octet-stream", 0, 0}};
GtkClipboard *cb;
copy_binary_t *copy_data;
gboolean ret;
if(len <= 0) {
return;
}
cb = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
copy_data = create_copy_binary_t(data_p,len);
ret = gtk_clipboard_set_with_data(cb,target_entry,1,
copy_binary_get_cb, copy_binary_free_cb,copy_data);
if(!ret) {
destroy_copy_binary_t(copy_data);
}
}
gchar *
create_user_window_title(const gchar *caption)
{
if (caption == NULL)
return g_strdup("");
if ((prefs.gui_window_title == NULL) || (*prefs.gui_window_title == '\0'))
return g_strdup(caption);
return g_strdup_printf("%s [%s]", caption, prefs.gui_window_title);
}
void
set_window_title(GtkWidget *win,
const gchar *caption)
{
char *title;
char *display_name;
display_name = cf_get_display_name(&cfile);
title = g_strdup_printf("%s: %s", caption, display_name);
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(win), title);
g_free(title);
}
static void
tree_collapse_row_with_children(GtkTreeView *tree_view, GtkTreeModel *model, GtkTreePath *path,
GtkTreeIter *iter)
{
GtkTreeIter child;
if (gtk_tree_view_row_expanded(tree_view, path)) {
if (gtk_tree_model_iter_children(model, &child, iter)) {
gtk_tree_path_down(path);
do {
if (gtk_tree_view_row_expanded(tree_view, path)) {
tree_collapse_row_with_children(tree_view, model, path, &child);
}
gtk_tree_path_next(path);
} while (gtk_tree_model_iter_next(model, &child));
gtk_tree_path_up(path);
gtk_tree_view_collapse_row(tree_view, path);
}
}
}
void
tree_collapse_path_all(GtkTreeView *tree_view, GtkTreePath *path)
{
GtkTreeIter iter;
GtkTreeModel *model;
model = gtk_tree_view_get_model(tree_view);
gtk_tree_model_get_iter(model, &iter, path);
tree_collapse_row_with_children(tree_view, model, path, &iter);
}
static gboolean
tree_view_key_pressed_cb(GtkWidget *tree,
GdkEventKey *event,
gpointer user_data _U_)
{
GtkTreeSelection *selection;
GtkTreeIter iter;
GtkTreeIter parent;
GtkTreeModel *model;
GtkTreePath *path;
gboolean expanded, expandable;
int rc = FALSE;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
if(!selection) {
return FALSE;
}
if(!gtk_tree_selection_get_selected(selection, &model, &iter)) {
return FALSE;
}
path = gtk_tree_model_get_path(model, &iter);
if(!path) {
return FALSE;
}
expanded = gtk_tree_view_row_expanded(GTK_TREE_VIEW(tree), path);
expandable = gtk_tree_model_iter_has_child(model, &iter);
switch (event->keyval) {
case GDK_Left:
if(expanded) {
if (event->state & GDK_SHIFT_MASK)
{
tree_collapse_row_with_children(GTK_TREE_VIEW(tree), model, path, &iter);
}
else
gtk_tree_view_collapse_row(GTK_TREE_VIEW(tree), path);
rc = TRUE;
break;
}
case GDK_BackSpace:
if (!expanded) {
if(! gtk_tree_model_iter_parent(model, &parent, &iter)) {
rc = FALSE;
break;
}
gtk_tree_path_free(path);
path = gtk_tree_model_get_path(model, &parent);
if(!path) {
return FALSE;
}
gtk_tree_view_set_cursor(GTK_TREE_VIEW(tree), path,
NULL ,
FALSE );
rc = TRUE;
break;
}
break;
case GDK_Right:
if (expandable) {
gtk_tree_view_expand_row(GTK_TREE_VIEW(tree), path, FALSE );
rc = TRUE;
break;
} else {
rc = FALSE;
break;
}
case GDK_Return:
case GDK_KP_Enter:
if (expanded)
gtk_tree_view_collapse_row(GTK_TREE_VIEW(tree), path);
else
gtk_tree_view_expand_row(GTK_TREE_VIEW(tree), path, FALSE );
rc = TRUE;
break;
}
if(path) {
gtk_tree_path_free(path);
}
return rc;
}
void
switch_to_fixed_col(GtkTreeView *view)
{
gint size;
GtkTreeViewColumn *column;
GList *columns, *list;
columns = gtk_tree_view_get_columns(GTK_TREE_VIEW(view));
list = columns;
while(columns) {
column = (GtkTreeViewColumn *)columns->data;
size = gtk_tree_view_column_get_width(column);
gtk_tree_view_column_set_sizing(column,GTK_TREE_VIEW_COLUMN_FIXED);
if (size > gtk_tree_view_column_get_fixed_width(column))
gtk_tree_view_column_set_fixed_width(column, size);
columns = g_list_next(columns);
}
g_list_free(list);
gtk_tree_view_set_fixed_height_mode(view, TRUE);
}
gint
get_default_col_size(GtkWidget *view,
const gchar *str)
{
PangoLayout *layout;
gint col_width;
layout = gtk_widget_create_pango_layout(view, str);
pango_layout_get_pixel_size(layout,
&col_width,
NULL);
g_object_unref(G_OBJECT(layout));
return col_width + (pango_font_description_get_size(user_font_get_regular()) / PANGO_SCALE);
}
void
float_data_func(GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
gfloat float_val;
gchar buf[20];
char *savelocale;
gint float_col = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, float_col, &float_val, -1);
savelocale = g_strdup(setlocale(LC_NUMERIC, NULL));
setlocale(LC_NUMERIC, "C");
g_snprintf(buf, sizeof(buf), "%.2f", float_val);
setlocale(LC_NUMERIC, savelocale);
g_free(savelocale);
g_object_set(renderer, "text", buf, NULL);
}
void
present_as_hex_func(GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
guint val;
gchar buf[35];
gint col = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, col, &val, -1);
g_snprintf(buf, sizeof(buf), "0x%02x", val);
g_object_set(renderer, "text", buf, NULL);
}
void
u64_data_func(GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
guint64 val;
int i = 0;
gchar *bp;
gchar buf[35];
gint col = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, col, &val, -1);
bp = &buf[34];
*bp = 0;
do {
*--bp = (gchar)(val % 10) +'0';
if (!(++i % 3)) {
*--bp = ' ';
}
} while ((val /= 10) != 0 && bp > buf);
g_object_set(renderer, "text", bp, NULL);
}
void
str_ptr_data_func(GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
const gchar *str = NULL;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, data_column, &str, -1);
g_object_set(renderer, "text", str, NULL);
}
gint
str_ptr_sort_func(GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
const gchar *str_a = NULL;
const gchar *str_b = NULL;
gint ret = 0;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, a, data_column, &str_a, -1);
gtk_tree_model_get(model, b, data_column, &str_b, -1);
if (str_a == str_b) {
return 0;
}
else if (str_a == NULL || str_b == NULL) {
ret = (str_a == NULL) ? -1 : 1;
}
else {
ret = g_ascii_strcasecmp(str_a,str_b);
}
return ret;
}
GtkWidget *
ws_combo_box_new_text_and_pointer_full(GtkCellRenderer **cell_p) {
GtkWidget *combo_box;
GtkCellRenderer *cell;
GtkTreeStore *store;
store = gtk_tree_store_new(3, G_TYPE_STRING, G_TYPE_POINTER, G_TYPE_BOOLEAN);
combo_box = gtk_combo_box_new_with_model(GTK_TREE_MODEL(store));
g_object_unref(store);
cell = gtk_cell_renderer_text_new();
gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo_box), cell, TRUE);
gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combo_box), cell,
"text", 0, "sensitive", 2,
NULL);
if (cell_p != NULL) {
*cell_p = cell;
}
return combo_box;
}
GtkWidget *
ws_combo_box_new_text_and_pointer(void) {
return ws_combo_box_new_text_and_pointer_full(NULL);
}
void
ws_combo_box_clear_text_and_pointer(GtkComboBox *combo_box)
{
gtk_tree_store_clear(GTK_TREE_STORE(gtk_combo_box_get_model(combo_box)));
}
GtkTreeIter
ws_combo_box_append_text_and_pointer_full(GtkComboBox *combo_box,
GtkTreeIter *parent_iter,
const gchar *text,
gconstpointer ptr,
gboolean sensitive)
{
GtkTreeIter iter;
GtkTreeStore *store;
store = GTK_TREE_STORE(gtk_combo_box_get_model(combo_box));
gtk_tree_store_append(store, &iter, parent_iter);
gtk_tree_store_set(store, &iter, 0, text, 1, ptr, 2, sensitive, -1);
return iter;
}
GtkTreeIter
ws_combo_box_append_text_and_pointer(GtkComboBox *combo_box,
const gchar *text,
gconstpointer ptr)
{
return ws_combo_box_append_text_and_pointer_full(combo_box, NULL, text, ptr, TRUE);
}
gboolean
ws_combo_box_get_active_pointer(GtkComboBox *combo_box,
gpointer *ptr)
{
GtkTreeStore *store;
GtkTreeIter iter;
*ptr = NULL;
if (gtk_combo_box_get_active_iter(combo_box, &iter)) {
store = GTK_TREE_STORE(gtk_combo_box_get_model(combo_box));
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
1, ptr, -1);
return TRUE;
}
return FALSE;
}
gint
ws_combo_box_get_active(GtkComboBox *combo_box)
{
return gtk_combo_box_get_active(combo_box);
}
void
ws_combo_box_set_active(GtkComboBox *combo_box,
gint idx)
{
gtk_combo_box_set_active(combo_box, idx);
}
void
ws_combo_box_set_active_iter(GtkComboBox *combo_box, GtkTreeIter *iter)
{
gtk_combo_box_set_active_iter(combo_box, iter);
}
static cairo_format_t
gdk_cairo_format_for_content(cairo_content_t content)
{
switch (content)
{
case CAIRO_CONTENT_COLOR:
return CAIRO_FORMAT_RGB24;
case CAIRO_CONTENT_ALPHA:
return CAIRO_FORMAT_A8;
case CAIRO_CONTENT_COLOR_ALPHA:
default:
return CAIRO_FORMAT_ARGB32;
}
}
static cairo_surface_t *
gdk_cairo_surface_coerce_to_image(cairo_surface_t *surface,
cairo_content_t content,
int src_x,
int src_y,
int width,
int height)
{
cairo_surface_t *copy;
cairo_t *cr;
copy = cairo_image_surface_create(gdk_cairo_format_for_content(content),
width,
height);
cr = cairo_create(copy);
cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
cairo_set_source_surface(cr, surface, -src_x, -src_y);
cairo_paint(cr);
cairo_destroy(cr);
return copy;
}
static void
convert_alpha(guchar *dest_data,
int dest_stride,
guchar *src_data,
int src_stride,
int src_x,
int src_y,
int width,
int height)
{
int x, y;
src_data += src_stride * src_y + src_x * 4;
for (y = 0; y < height; y++) {
guint32 *src = (guint32 *)src_data;
for (x = 0; x < width; x++) {
guint alpha = src[x] >> 24;
if (alpha == 0)
{
dest_data[x * 4 + 0] = 0;
dest_data[x * 4 + 1] = 0;
dest_data[x * 4 + 2] = 0;
}
else
{
dest_data[x * 4 + 0] = (((src[x] & 0xff0000) >> 16) * 255 + alpha / 2) / alpha;
dest_data[x * 4 + 1] = (((src[x] & 0x00ff00) >> 8) * 255 + alpha / 2) / alpha;
dest_data[x * 4 + 2] = (((src[x] & 0x0000ff) >> 0) * 255 + alpha / 2) / alpha;
}
dest_data[x * 4 + 3] = alpha;
}
src_data += src_stride;
dest_data += dest_stride;
}
}
static void
convert_no_alpha(guchar *dest_data,
int dest_stride,
guchar *src_data,
int src_stride,
int src_x,
int src_y,
int width,
int height)
{
int x, y;
src_data += src_stride * src_y + src_x * 4;
for (y = 0; y < height; y++) {
guint32 *src = (guint32 *)src_data;
for (x = 0; x < width; x++) {
dest_data[x * 3 + 0] = src[x] >> 16;
dest_data[x * 3 + 1] = src[x] >> 8;
dest_data[x * 3 + 2] = src[x];
}
src_data += src_stride;
dest_data += dest_stride;
}
}
GdkPixbuf *
gdk_pixbuf_get_from_surface(cairo_surface_t *surface,
gint src_x,
gint src_y,
gint width,
gint height)
{
cairo_content_t content;
GdkPixbuf *dest;
g_return_val_if_fail(surface != NULL, NULL);
g_return_val_if_fail(width > 0 && height > 0, NULL);
content = (cairo_content_t)(cairo_surface_get_content(surface) | CAIRO_CONTENT_COLOR);
dest = gdk_pixbuf_new(GDK_COLORSPACE_RGB,
!!(content & CAIRO_CONTENT_ALPHA),
8,
width, height);
surface = gdk_cairo_surface_coerce_to_image(surface, content,
src_x, src_y,
width, height);
cairo_surface_flush(surface);
if (cairo_surface_status(surface) || dest == NULL)
{
cairo_surface_destroy(surface);
return NULL;
}
if (gdk_pixbuf_get_has_alpha(dest))
convert_alpha(gdk_pixbuf_get_pixels(dest),
gdk_pixbuf_get_rowstride(dest),
cairo_image_surface_get_data(surface),
cairo_image_surface_get_stride(surface),
0, 0,
width, height);
else
convert_no_alpha(gdk_pixbuf_get_pixels(dest),
gdk_pixbuf_get_rowstride(dest),
cairo_image_surface_get_data(surface),
cairo_image_surface_get_stride(surface),
0, 0,
width, height);
cairo_surface_destroy(surface);
return dest;
}
GtkWidget *
ws_gtk_box_new(GtkOrientation orientation,
gint spacing,
gboolean homogeneous)
{
#if !GTK_CHECK_VERSION(3,0,0)
if (orientation == GTK_ORIENTATION_HORIZONTAL)
return gtk_hbox_new(homogeneous, spacing);
else
return gtk_vbox_new(homogeneous, spacing);
#else
GtkWidget *widget;
widget = gtk_box_new(orientation, spacing);
gtk_box_set_homogeneous(GTK_BOX(widget), homogeneous);
return widget;
#endif
}
GtkWidget *
gtk_button_box_new(GtkOrientation orientation)
{
if (orientation == GTK_ORIENTATION_HORIZONTAL) {
return gtk_hbutton_box_new();
} else {
return gtk_vbutton_box_new();
}
}
GtkWidget *
gtk_scrollbar_new(GtkOrientation orientation,
GtkAdjustment *adjustment)
{
if (orientation == GTK_ORIENTATION_HORIZONTAL) {
return gtk_hscrollbar_new(adjustment);
} else {
return gtk_vscrollbar_new(adjustment);
}
}
GtkWidget *
gtk_paned_new(GtkOrientation orientation)
{
if(orientation == GTK_ORIENTATION_HORIZONTAL) {
return gtk_hpaned_new();
} else {
return gtk_vpaned_new();
}
}
GtkWidget *
gtk_separator_new(GtkOrientation orientation)
{
if (orientation == GTK_ORIENTATION_HORIZONTAL) {
return gtk_hseparator_new();
} else {
return gtk_vseparator_new();
}
}
GtkWidget *
frame_new(const gchar *title) {
GtkWidget *frame, *frame_lb;
GString *mu_title = g_string_new("");
frame = gtk_frame_new(NULL);
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_NONE);
if (title) {
#if defined(_WIN32) || defined(__APPLE__)
g_string_printf(mu_title, "%s", title);
#else
g_string_printf(mu_title, "<b>%s</b>", title);
#endif
frame_lb = gtk_label_new(NULL);
gtk_label_set_markup(GTK_LABEL(frame_lb), mu_title->str);
gtk_frame_set_label_widget(GTK_FRAME(frame), frame_lb);
}
g_string_free(mu_title, TRUE);
return frame;
}
void
ws_gtk_grid_attach_defaults(GtkGrid *grid, GtkWidget *child, gint left, gint top, gint width, gint height)
{
ws_gtk_grid_attach_extended(grid, child, left, top, width, height,
(GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), 0, 0);
}
void
ws_gtk_grid_attach_extended(GtkGrid *grid, GtkWidget *child,
gint left, gint top, gint width, gint height,
GtkAttachOptions xoptions, GtkAttachOptions yoptions,
guint xpadding, guint ypadding)
{
gtk_grid_attach(grid, child, left, top, width, height);
if (xoptions & GTK_EXPAND)
gtk_widget_set_hexpand(child, TRUE);
if (yoptions & GTK_EXPAND)
gtk_widget_set_vexpand(child, TRUE);
gtk_widget_set_halign(child, (xoptions & GTK_FILL) ? GTK_ALIGN_FILL : GTK_ALIGN_CENTER);
gtk_widget_set_valign(child, (yoptions & GTK_FILL) ? GTK_ALIGN_FILL : GTK_ALIGN_CENTER);
if (xpadding != 0) {
gtk_widget_set_margin_left(child, xpadding);
gtk_widget_set_margin_right(child, xpadding);
}
if (ypadding != 0) {
gtk_widget_set_margin_top(child, ypadding);
gtk_widget_set_margin_bottom(child, ypadding);
}
}
void
ws_gtk_grid_set_homogeneous(GtkGrid *grid, gboolean homogeneous)
{
gtk_grid_set_row_homogeneous(grid, homogeneous);
gtk_grid_set_column_homogeneous(grid, homogeneous);
}
void
gdk_cairo_set_source_rgba(cairo_t *cr, const GdkRGBA *rgba)
{
GdkColor color;
gdkRGBAcolor_to_GdkColor(&color, rgba);
gdk_cairo_set_source_color(cr, &color);
}
GdkPixbuf *
ws_gdk_pixbuf_new_from_resource(const char *path)
{
GdkPixbuf *pixbuf;
GError *err = NULL;
pixbuf = gdk_pixbuf_new_from_resource(path, &err);
g_assert_no_error(err);
return pixbuf;
}
