PangoFontDescription *user_font_get_regular(void)
{
return m_r_font;
}
PangoFontDescription *user_font_get_bold(void)
{
return m_b_font;
}
static void
set_fonts(PangoFontDescription *regular, PangoFontDescription *bold)
{
g_assert(m_r_font && m_b_font);
m_r_font = regular;
m_b_font = bold;
}
void
view_zoom_in_cb(GtkWidget *w _U_, gpointer d _U_)
{
gint save_gui_zoom_level;
save_gui_zoom_level = recent.gui_zoom_level;
recent.gui_zoom_level++;
switch (user_font_apply()) {
case FA_SUCCESS:
break;
case FA_FONT_NOT_RESIZEABLE:
recent.gui_zoom_level = save_gui_zoom_level;
break;
case FA_FONT_NOT_AVAILABLE:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Your current font isn't available in the next larger size.\n");
recent.gui_zoom_level = save_gui_zoom_level;
break;
}
}
void
view_zoom_out_cb(GtkWidget *w _U_, gpointer d _U_)
{
gint save_gui_zoom_level;
save_gui_zoom_level = recent.gui_zoom_level;
recent.gui_zoom_level--;
switch (user_font_apply()) {
case FA_SUCCESS:
break;
case FA_FONT_NOT_RESIZEABLE:
recent.gui_zoom_level = save_gui_zoom_level;
break;
case FA_FONT_NOT_AVAILABLE:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Your current font isn't available in the next smaller size.\n");
recent.gui_zoom_level = save_gui_zoom_level;
break;
}
}
void
view_zoom_100_cb(GtkWidget *w _U_, gpointer d _U_)
{
gint save_gui_zoom_level;
save_gui_zoom_level = recent.gui_zoom_level;
recent.gui_zoom_level = 0;
switch (user_font_apply()) {
case FA_SUCCESS:
break;
case FA_FONT_NOT_RESIZEABLE:
recent.gui_zoom_level = save_gui_zoom_level;
break;
case FA_FONT_NOT_AVAILABLE:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Your current font couldn't be reloaded at the size you selected.\n");
recent.gui_zoom_level = save_gui_zoom_level;
break;
}
}
gboolean
user_font_test(gchar *font_name)
{
PangoFontDescription *new_r_font, *new_b_font;
new_r_font = pango_font_description_from_string(font_name);
if (new_r_font == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The font you selected can't be loaded.");
return FALSE;
}
new_b_font = pango_font_description_copy(new_r_font);
pango_font_description_set_weight(new_b_font, PANGO_WEIGHT_BOLD);
if (new_b_font == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The font you selected doesn't have a boldface version.");
pango_font_description_free(new_r_font);
return FALSE;
}
return TRUE;
}
static char *
font_zoom(char *gui_font_name)
{
char *new_font_name;
char *font_name_dup;
char *font_name_p;
long font_point_size_l;
if (recent.gui_zoom_level == 0) {
return g_strdup(gui_font_name);
}
font_name_dup = g_strdup(gui_font_name);
font_name_p = strrchr(font_name_dup, ' ');
*font_name_p = '\0';
font_name_p++;
font_point_size_l = strtol(font_name_p, NULL, 10);
font_point_size_l += recent.gui_zoom_level;
new_font_name = g_strdup_printf("%s %ld", font_name_dup, font_point_size_l);
g_free(font_name_dup);
return new_font_name;
}
fa_ret_t
user_font_apply(void) {
char *gui_font_name;
PangoFontDescription *new_r_font, *new_b_font;
PangoFontDescription *old_r_font = NULL, *old_b_font = NULL;
gui_font_name = font_zoom(prefs.gui_font_name);
if (gui_font_name == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Your current font isn't available in any other sizes.\n");
return FA_FONT_NOT_RESIZEABLE;
}
new_r_font = pango_font_description_from_string(gui_font_name);
new_b_font = pango_font_description_copy(new_r_font);
pango_font_description_set_weight(new_b_font, PANGO_WEIGHT_BOLD);
if (new_r_font == NULL || new_b_font == NULL) {
if (new_r_font != NULL)
pango_font_description_free(new_r_font);
if (new_b_font != NULL)
pango_font_description_free(new_b_font);
g_free(gui_font_name);
return FA_FONT_NOT_AVAILABLE;
}
new_packet_list_set_font(new_r_font);
set_ptree_font_all(new_r_font);
old_r_font = m_r_font;
old_b_font = m_b_font;
set_fonts(new_r_font, new_b_font);
redraw_packet_bytes_all();
follow_tcp_redraw_all();
if (old_r_font != NULL)
pango_font_description_free(old_r_font);
if (old_b_font != NULL)
pango_font_description_free(old_b_font);
g_free(gui_font_name);
return FA_SUCCESS;
}
static void
set_app_font_gtk2(const char *fontname)
{
GtkSettings *settings;
if (fontname != NULL && *fontname == 0) return;
settings = gtk_settings_get_default();
if (fontname == NULL) {
g_object_set(G_OBJECT(settings), "gtk-font-name", appfontname, NULL);
} else {
GtkWidget *w;
PangoFontDescription *pfd;
PangoContext *pc;
PangoFont *pfont;
w = gtk_label_new(NULL);
pfd = pango_font_description_from_string(fontname);
pc = gtk_widget_get_pango_context(w);
pfont = pango_context_load_font(pc, pfd);
if (pfont != NULL) {
g_strlcpy(appfontname, fontname, 128);
appfontname[127] = '\0';
g_object_set(G_OBJECT(settings), "gtk-font-name", appfontname, NULL);
}
gtk_widget_destroy(w);
pango_font_description_free(pfd);
}
}
static char *default_windows_menu_fontspec_gtk2(void)
{
gchar *fontspec = NULL;
NONCLIENTMETRICS ncm;
memset(&ncm, 0, sizeof ncm);
ncm.cbSize = sizeof ncm;
if (SystemParametersInfo(SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0)) {
HDC screen = GetDC(0);
double y_scale = 72.0 / GetDeviceCaps(screen, LOGPIXELSY);
int point_size = (int) (ncm.lfMenuFont.lfHeight * y_scale);
if (point_size < 0) point_size = -point_size;
fontspec = g_strdup_printf("%s %d", ncm.lfMenuFont.lfFaceName,
point_size);
ReleaseDC(0, screen);
}
return fontspec;
}
static void try_to_get_windows_font_gtk2(void)
{
gchar *fontspec;
fontspec = default_windows_menu_fontspec_gtk2();
if (fontspec != NULL) {
int match = 0;
PangoFontDescription *pfd;
PangoFont *pfont;
PangoContext *pc;
GtkWidget *w;
pfd = pango_font_description_from_string(fontspec);
w = gtk_label_new(NULL);
pc = gtk_widget_get_pango_context(w);
pfont = pango_context_load_font(pc, pfd);
match = (pfont != NULL);
pango_font_description_free(pfd);
g_object_unref(G_OBJECT(pc));
gtk_widget_destroy(w);
if (match) set_app_font_gtk2(fontspec);
g_free(fontspec);
}
}
void font_init(void)
{
#ifdef _WIN32
try_to_get_windows_font_gtk2();
#endif
m_r_font = pango_font_description_from_string(prefs.gui_font_name);
m_b_font = pango_font_description_copy(m_r_font);
pango_font_description_set_weight(m_b_font, PANGO_WEIGHT_BOLD);
if (m_r_font == NULL || m_b_font == NULL) {
if (m_r_font == NULL) {
fprintf(stderr, "wireshark: Warning: font %s not found - defaulting to Monospace 9\n",
prefs.gui_font_name);
} else {
pango_font_description_free(m_r_font);
}
if (m_b_font == NULL) {
fprintf(stderr, "wireshark: Warning: bold font %s not found - defaulting"
" to Monospace 9\n", prefs.gui_font_name);
} else {
pango_font_description_free(m_b_font);
}
if ((m_r_font = pango_font_description_from_string("Monospace 9")) == NULL)
{
fprintf(stderr, "wireshark: Error: font Monospace 9 not found\n");
exit(1);
}
if ((m_b_font = pango_font_description_copy(m_r_font)) == NULL) {
fprintf(stderr, "wireshark: Error: font Monospace 9 bold not found\n");
exit(1);
}
g_free(prefs.gui_font_name);
pango_font_description_set_weight(m_b_font, PANGO_WEIGHT_BOLD);
prefs.gui_font_name = g_strdup("Monospace 9");
}
set_fonts(m_r_font, m_b_font);
}
