void supported_cb(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *main_vb, *bbox, *supported_nb, *ok_bt, *label, *txt_scrollw,
*proto_vb,
*dfilter_vb;
if (supported_w != NULL) {
reactivate_window(supported_w);
return;
}
supported_w = window_new(GTK_WINDOW_TOPLEVEL, "Wireshark: Supported Protocols");
gtk_window_set_default_size(GTK_WINDOW(supported_w), DEF_WIDTH * 2/3, DEF_HEIGHT * 2/3);
gtk_container_set_border_width(GTK_CONTAINER(supported_w), 2);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 1);
gtk_container_add(GTK_CONTAINER(supported_w), main_vb);
gtk_widget_show(main_vb);
supported_nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(main_vb), supported_nb, TRUE, TRUE, 0);
proto_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(proto_vb), 1);
txt_scrollw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(proto_vb), txt_scrollw, TRUE, TRUE, 0);
proto_text = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(proto_text), FALSE);
set_supported_text(proto_text, PROTOCOL_SUPPORTED);
gtk_container_add(GTK_CONTAINER(txt_scrollw), proto_text);
gtk_widget_show(txt_scrollw);
gtk_widget_show(proto_text);
gtk_widget_show(proto_vb);
label = gtk_label_new("Protocols");
gtk_notebook_append_page(GTK_NOTEBOOK(supported_nb), proto_vb, label);
dfilter_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(dfilter_vb), 1);
txt_scrollw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(dfilter_vb), txt_scrollw, TRUE, TRUE, 0);
dfilter_text = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(dfilter_text), FALSE);
set_supported_text(dfilter_text, DFILTER_SUPPORTED);
gtk_container_add(GTK_CONTAINER(txt_scrollw), dfilter_text);
gtk_widget_show(txt_scrollw);
gtk_widget_show(dfilter_text);
gtk_widget_show(dfilter_vb);
label = gtk_label_new("Display Filter Fields");
gtk_notebook_append_page(GTK_NOTEBOOK(supported_nb), dfilter_vb, label);
gtk_widget_show(supported_nb);
bbox = dlg_button_row_new(GTK_STOCK_OK, NULL);
gtk_box_pack_end(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
window_set_cancel_button(supported_w, ok_bt, window_cancel_button_cb);
g_signal_connect(supported_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(supported_w, "destroy", G_CALLBACK(supported_destroy_cb), NULL);
gtk_widget_show(supported_w);
window_present(supported_w);
}
static void supported_destroy_cb(GtkWidget *w _U_, gpointer data _U_)
{
supported_w = NULL;
}
static void insert_text(GtkWidget *w, const char *buffer, int nchars)
{
GtkTextBuffer *buf= gtk_text_view_get_buffer(GTK_TEXT_VIEW(w));
GtkTextIter iter;
gtk_text_buffer_get_end_iter(buf, &iter);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_font(w, user_font_get_regular());
#else
gtk_widget_modify_font(w, user_font_get_regular());
#endif
if (!g_utf8_validate(buffer, -1, NULL))
printf("Invalid utf8 encoding: %s\n", buffer);
gtk_text_buffer_insert(buf, &iter, buffer, nchars);
}
static void set_supported_text(GtkWidget *w, supported_type_t type)
{
#define BUFF_LEN 4096
#define B_LEN 256
char buffer[BUFF_LEN];
header_field_info *hfinfo;
int i, len, maxlen = 0, maxlen2 = 0, maxlen4 = 0;
const char *type_name;
void *cookie, *cookie2;
protocol_t *protocol;
const char *name, *short_name, *filter_name;
int namel = 0, short_namel = 0, filter_namel = 0;
int count, fcount;
switch(type) {
case PROTOCOL_SUPPORTED :
count = 0;
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
count++;
protocol = find_protocol_by_id(i);
name = proto_get_protocol_name(i);
short_name = proto_get_protocol_short_name(protocol);
filter_name = proto_get_protocol_filter_name(i);
if ((len = (int) strlen(name)) > namel)
namel = len;
if ((len = (int) strlen(short_name)) > short_namel)
short_namel = len;
if ((len = (int) strlen(filter_name)) > filter_namel)
filter_namel = len;
}
len = g_snprintf(buffer, BUFF_LEN, proto_supported, count);
insert_text(w, buffer, len);
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
protocol = find_protocol_by_id(i);
name = proto_get_protocol_name(i);
short_name = proto_get_protocol_short_name(protocol);
filter_name = proto_get_protocol_filter_name(i);
len = g_snprintf(buffer, BUFF_LEN, "%*s %*s %*s\n",
-short_namel, short_name,
-namel, name,
-filter_namel, filter_name);
insert_text(w, buffer, len);
}
break;
case DFILTER_SUPPORTED :
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
for (hfinfo = proto_get_first_protocol_field(i, &cookie2); hfinfo != NULL;
hfinfo = proto_get_next_protocol_field(&cookie2)) {
if (hfinfo->same_name_prev_id != -1)
continue;
if ((len = (int) strlen(hfinfo->abbrev)) > maxlen)
maxlen = len;
if ((len = (int) strlen(hfinfo->name)) > maxlen2)
maxlen2 = len;
if (hfinfo->blurb != NULL) {
if ((len = (int) strlen(hfinfo->blurb)) > maxlen4)
maxlen4 = len;
}
}
}
insert_text(w, dfilter_supported, (int) strlen(dfilter_supported));
fcount = 0;
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
protocol = find_protocol_by_id(i);
name = proto_get_protocol_name(i);
short_name = proto_get_protocol_short_name(protocol);
filter_name = proto_get_protocol_filter_name(i);
count = 0;
for (hfinfo = proto_get_first_protocol_field(i, &cookie2); hfinfo != NULL;
hfinfo = proto_get_next_protocol_field(&cookie2)) {
if (hfinfo->same_name_prev_id != -1)
continue;
count++;
}
fcount += count;
len = g_snprintf(buffer, BUFF_LEN, "\n%s - %s (%s) [%d fields]:\n",
short_name, name, filter_name, count);
insert_text(w, buffer, len);
for (hfinfo = proto_get_first_protocol_field(i, &cookie2); hfinfo != NULL;
hfinfo = proto_get_next_protocol_field(&cookie2)) {
if (hfinfo->same_name_prev_id != -1)
continue;
type_name = ftype_pretty_name(hfinfo->type);
if (hfinfo->blurb != NULL && hfinfo->blurb[0] != '\0') {
len = g_snprintf(buffer, BUFF_LEN, "%*s %*s %*s (%s)\n",
-maxlen, hfinfo->abbrev,
-maxlen2, hfinfo->name,
-maxlen4, hfinfo->blurb,
type_name);
} else {
len = g_snprintf(buffer, BUFF_LEN, "%*s %*s (%s)\n",
-maxlen, hfinfo->abbrev,
-maxlen2, hfinfo->name,
type_name);
}
insert_text(w, buffer, len);
}
}
len = g_snprintf(buffer, BUFF_LEN, "\n-- Total %d fields\n", fcount);
insert_text(w, buffer, len);
break;
default :
g_assert_not_reached();
break;
}
}
static void clear_supported_text(GtkWidget *w)
{
GtkTextBuffer *buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w));
gtk_text_buffer_set_text(buf, "", 0);
}
void supported_redraw(void)
{
if (supported_w != NULL) {
clear_supported_text(proto_text);
set_supported_text(proto_text, PROTOCOL_SUPPORTED);
clear_supported_text(dfilter_text);
set_supported_text(dfilter_text, DFILTER_SUPPORTED);
}
}
