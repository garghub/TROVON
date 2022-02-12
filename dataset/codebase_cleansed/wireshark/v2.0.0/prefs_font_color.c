GtkWidget *
font_color_prefs_show(void)
{
GtkWidget *main_vb, *main_grid, *label, *combo_box;
GtkWidget *font_sample, *color_sample, *colorsel;
static const gchar *mt[] = {
"Marked packet foreground",
"Marked packet background",
"Ignored packet foreground",
"Ignored packet background",
"'Follow Stream' client foreground",
"'Follow Stream' client background",
"'Follow Stream' server foreground",
"'Follow Stream' server background",
"Valid filter text entry",
"Invalid filter text entry",
"Deprecated filter text entry"
};
int mcount = sizeof(mt) / sizeof (gchar *);
GtkTextBuffer *buf;
GtkTextIter iter;
GRand *rand_state = g_rand_new();
GString *preview_string = g_string_new("");
int i;
#define GRID_FONT_ROW 0
#define GRID_COLOR_ROW 1
#define GRID_COLOR_SEL_ROW 3
font_changed = FALSE;
color_t_to_gdkxxx(&tcolors[MFG_IDX], &prefs.gui_marked_fg);
color_t_to_gdkxxx(&tcolors[MBG_IDX], &prefs.gui_marked_bg);
color_t_to_gdkxxx(&tcolors[IFG_IDX], &prefs.gui_ignored_fg);
color_t_to_gdkxxx(&tcolors[IBG_IDX], &prefs.gui_ignored_bg);
color_t_to_gdkxxx(&tcolors[CFG_IDX], &prefs.st_client_fg);
color_t_to_gdkxxx(&tcolors[CBG_IDX], &prefs.st_client_bg);
color_t_to_gdkxxx(&tcolors[SFG_IDX], &prefs.st_server_fg);
color_t_to_gdkxxx(&tcolors[SBG_IDX], &prefs.st_server_bg);
color_t_to_gdkxxx(&tcolors[FTV_IDX], &prefs.gui_text_valid);
color_t_to_gdkxxx(&tcolors[FTI_IDX], &prefs.gui_text_invalid);
color_t_to_gdkxxx(&tcolors[FTD_IDX], &prefs.gui_text_deprecated);
color_t_to_gdkxxx(&filter_text_fg, &filter_text_fg_color);
#if ! GTK_CHECK_VERSION(3,4,0)
for (i=0; i<MAX_IDX; i++) {
tcolors_orig[i] = tcolors[i];
}
#endif
curcolor = &tcolors[CFG_IDX];
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
main_grid = ws_gtk_grid_new();
gtk_box_pack_start(GTK_BOX(main_vb), main_grid, FALSE, FALSE, 0);
ws_gtk_grid_set_row_spacing(GTK_GRID(main_grid), 40);
ws_gtk_grid_set_column_spacing(GTK_GRID(main_grid), 15);
gtk_widget_show(main_grid);
label = gtk_label_new("Main window font:");
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(main_grid), label,
0, GRID_FONT_ROW, 1, 1,
(GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_show(label);
font_button = gtk_font_button_new_with_font(prefs.gui_gtk2_font_name);
gtk_font_button_set_title(GTK_FONT_BUTTON(font_button), "Wireshark: Font");
ws_gtk_grid_attach(GTK_GRID(main_grid), font_button,
1, GRID_FONT_ROW, 1, 1);
gtk_widget_show(font_button);
g_string_printf(preview_string, " %s 0123456789",
font_pangrams[g_rand_int_range(rand_state, 0, NUM_FONT_PANGRAMS)]);
font_sample = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(font_sample), FALSE);
buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(font_sample));
gtk_text_buffer_get_start_iter(buf, &iter);
srand((unsigned int) time(NULL));
gtk_text_buffer_insert(buf, &iter, preview_string->str, -1);
ws_gtk_grid_attach_extended(GTK_GRID(main_grid), font_sample,
2, GRID_FONT_ROW, 1, 1,
(GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
g_signal_connect(font_button, "font-set", G_CALLBACK(select_font), NULL);
gtk_widget_show(font_sample);
g_string_free(preview_string, TRUE);
g_object_set_data(G_OBJECT(font_button), FONT_SAMPLE_KEY, font_sample);
label = gtk_label_new("Colors:");
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(main_grid), label,
0, GRID_COLOR_ROW, 1, 1,
(GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0,0);
gtk_widget_show(label);
#if GTK_CHECK_VERSION(3,4,0)
#endif
colorsel = gtk_color_xxx_new();
combo_box = gtk_combo_box_text_new();
for (i = 0; i < mcount; i++){
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box), mt[i]);
}
gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), CFG_IDX);
g_signal_connect(combo_box, "changed", G_CALLBACK(update_current_color), colorsel);
ws_gtk_grid_attach(GTK_GRID(main_grid), combo_box,
1, GRID_COLOR_ROW, 1, 1);
gtk_widget_show(combo_box);
color_sample = gtk_text_view_new();
update_font(user_font_get_regular(), font_sample, color_sample);
gtk_text_view_set_editable(GTK_TEXT_VIEW(color_sample), FALSE);
buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(color_sample));
gtk_text_buffer_get_start_iter(buf, &iter);
gtk_text_buffer_create_tag(buf, "marked",
TAG_PROP_FG_COLOR, &tcolors[MFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[MBG_IDX],
NULL);
gtk_text_buffer_create_tag(buf, "ignored",
TAG_PROP_FG_COLOR, &tcolors[IFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[IBG_IDX],
NULL);
gtk_text_buffer_create_tag(buf, "client",
TAG_PROP_FG_COLOR, &tcolors[CFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[CBG_IDX],
NULL);
gtk_text_buffer_create_tag(buf, "server",
TAG_PROP_FG_COLOR, &tcolors[SFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[SBG_IDX],
NULL);
gtk_text_buffer_create_tag(buf, "text_valid",
TAG_PROP_FG_COLOR, &filter_text_fg,
TAG_PROP_BG_COLOR, &tcolors[FTV_IDX],
NULL);
gtk_text_buffer_create_tag(buf, "text_invalid",
TAG_PROP_FG_COLOR, &filter_text_fg,
TAG_PROP_BG_COLOR, &tcolors[FTI_IDX],
NULL);
gtk_text_buffer_create_tag(buf, "text_deprecated",
TAG_PROP_FG_COLOR, &filter_text_fg,
TAG_PROP_BG_COLOR, &tcolors[FTD_IDX],
NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_MARKED_TEXT, -1,
"marked", NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_IGNORED_TEXT, -1,
"ignored", NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_CLIENT_TEXT, -1,
"client", NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_SERVER_TEXT, -1,
"server", NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_TEXT_VALID_TEXT, -1,
"text_valid", NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_TEXT_INVALID_TEXT, -1,
"text_invalid", NULL);
gtk_text_buffer_insert_with_tags_by_name(buf, &iter, SAMPLE_TEXT_DEPRECATED_TEXT, -1,
"text_deprecated", NULL);
ws_gtk_grid_attach_extended(GTK_GRID(main_grid), color_sample,
2, GRID_COLOR_ROW, 1, 2,
(GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_show(color_sample);
gtk_color_xxx_set_yyy(GTK_COLOR_XXX(colorsel), curcolor);
ws_gtk_grid_attach_extended(GTK_GRID(main_grid), colorsel,
1, GRID_COLOR_SEL_ROW, 2, 1,
(GtkAttachOptions)(GTK_FILL|GTK_EXPAND), (GtkAttachOptions)0, 0, 0);
g_object_set_data(G_OBJECT(combo_box), COLOR_SAMPLE_KEY, color_sample);
g_object_set_data(G_OBJECT(colorsel), COLOR_SAMPLE_KEY, color_sample);
g_signal_connect(colorsel, COLOR_CHANGED_SIGNAL, G_CALLBACK(update_text_color), NULL);
gtk_widget_show(colorsel);
g_rand_free(rand_state);
gtk_widget_show(main_vb);
return main_vb;
}
static void
update_font(PangoFontDescription *font, GtkWidget *font_sample _U_, GtkWidget *color_sample _U_) {
if (!font_sample || !color_sample)
return;
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_font(font_sample, font);
gtk_widget_override_font(color_sample, font);
#else
gtk_widget_modify_font(font_sample, font);
gtk_widget_modify_font(color_sample, font);
#endif
}
static gboolean
font_fetch(void)
{
gchar *font_name;
if (!font_button)
return FALSE;
font_name = g_strdup(gtk_font_button_get_font_name(
GTK_FONT_BUTTON(font_button)));
if (font_name == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"You have not selected a font.");
return FALSE;
}
if (!user_font_test(font_name)) {
g_free(font_name);
return FALSE;
}
new_font_name = font_name;
return TRUE;
}
static void
select_font(GtkWidget *w, gpointer data _U_)
{
GtkWidget *font_sample = (GtkWidget *)g_object_get_data(G_OBJECT(w), FONT_SAMPLE_KEY);
GtkWidget *color_sample = (GtkWidget *)g_object_get_data(G_OBJECT(w), COLOR_SAMPLE_KEY);
const gchar *font_name;
if (!font_sample || !color_sample)
return;
font_name = gtk_font_button_get_font_name(GTK_FONT_BUTTON(w));
if (font_name) {
PangoFontDescription *font = pango_font_description_from_string(font_name);
update_font(font, font_sample, color_sample);
}
}
static void
update_text_color(GObject *obj, GParamSpec *pspec _U_, gpointer data _U_) {
GtkTextView *sample = (GtkTextView *)g_object_get_data(G_OBJECT(obj), COLOR_SAMPLE_KEY);
GtkTextBuffer *buf;
GtkTextTag *tag;
gtk_color_xxx_get_yyy(GTK_COLOR_XXX(obj), curcolor);
buf = gtk_text_view_get_buffer(sample);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "marked");
g_object_set(tag,
TAG_PROP_FG_COLOR, &tcolors[MFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[MBG_IDX],
NULL);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "ignored");
g_object_set(tag,
TAG_PROP_FG_COLOR, &tcolors[IFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[IBG_IDX],
NULL);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "client");
g_object_set(tag,
TAG_PROP_FG_COLOR, &tcolors[CFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[CBG_IDX],
NULL);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "server");
g_object_set(tag,
TAG_PROP_FG_COLOR, &tcolors[SFG_IDX],
TAG_PROP_BG_COLOR, &tcolors[SBG_IDX],
NULL);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "text_valid");
g_object_set(tag,
TAG_PROP_FG_COLOR, &filter_text_fg,
TAG_PROP_BG_COLOR, &tcolors[FTV_IDX],
NULL);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "text_invalid");
g_object_set(tag,
TAG_PROP_FG_COLOR, &filter_text_fg,
TAG_PROP_BG_COLOR, &tcolors[FTI_IDX],
NULL);
tag = gtk_text_tag_table_lookup(gtk_text_buffer_get_tag_table(buf), "text_deprecated");
g_object_set(tag,
TAG_PROP_FG_COLOR, &filter_text_fg,
TAG_PROP_BG_COLOR, &tcolors[FTD_IDX],
NULL);
}
static void
update_current_color(GtkWidget *combo_box, gpointer data)
{
GtkWidget *colorsel = (GtkWidget *)data;
GtkTextView *color_sample = (GtkTextView *)g_object_get_data(G_OBJECT(combo_box), COLOR_SAMPLE_KEY);
int i;
GtkTextIter iter;
i = gtk_combo_box_get_active(GTK_COMBO_BOX(combo_box));
curcolor = &tcolors[i];
#if ! GTK_CHECK_VERSION(3,4,0)
gtk_color_selection_set_previous_color(GTK_COLOR_SELECTION(colorsel), &tcolors_orig[i]);
#endif
gtk_color_xxx_set_yyy(GTK_COLOR_XXX(colorsel), curcolor);
gtk_text_buffer_get_start_iter(gtk_text_view_get_buffer(color_sample), &iter);
gtk_text_iter_set_line(&iter, i/2);
gtk_text_view_scroll_to_iter(color_sample, &iter, 0.0, FALSE, 0, 0);
}
void
font_color_prefs_fetch(GtkWidget *w _U_)
{
gdkxxx_to_color_t(&prefs.gui_marked_fg, &tcolors[MFG_IDX]);
gdkxxx_to_color_t(&prefs.gui_marked_bg, &tcolors[MBG_IDX]);
gdkxxx_to_color_t(&prefs.gui_ignored_fg, &tcolors[IFG_IDX]);
gdkxxx_to_color_t(&prefs.gui_ignored_bg, &tcolors[IBG_IDX]);
gdkxxx_to_color_t(&prefs.st_client_fg, &tcolors[CFG_IDX]);
gdkxxx_to_color_t(&prefs.st_client_bg, &tcolors[CBG_IDX]);
gdkxxx_to_color_t(&prefs.st_server_fg, &tcolors[SFG_IDX]);
gdkxxx_to_color_t(&prefs.st_server_bg, &tcolors[SBG_IDX]);
gdkxxx_to_color_t(&prefs.gui_text_valid, &tcolors[FTV_IDX]);
gdkxxx_to_color_t(&prefs.gui_text_invalid, &tcolors[FTI_IDX]);
gdkxxx_to_color_t(&prefs.gui_text_deprecated, &tcolors[FTD_IDX]);
if (font_fetch()) {
if (strcmp(new_font_name, prefs.gui_gtk2_font_name) != 0) {
font_changed = TRUE;
g_free(prefs.gui_gtk2_font_name);
prefs.gui_gtk2_font_name = g_strdup(new_font_name);
}
}
}
void
font_color_prefs_apply(GtkWidget *w _U_, gboolean redissect)
{
if (font_changed) {
switch (user_font_apply()) {
case FA_SUCCESS:
break;
case FA_FONT_NOT_RESIZEABLE:
recent.gui_zoom_level = 0;
break;
case FA_FONT_NOT_AVAILABLE:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"That font isn't available at the specified zoom level;\n"
"turning zooming off.");
recent.gui_zoom_level = 0;
break;
}
} else if (!redissect) {
redraw_packet_bytes_all();
}
follow_tcp_redraw_all();
}
void
font_color_prefs_destroy(GtkWidget *w _U_)
{
if (new_font_name != NULL) {
g_free(new_font_name);
new_font_name = NULL;
}
font_button = NULL;
}
