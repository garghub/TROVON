static void set_busy_cursor(GdkWindow *w)
{
GdkCursor* cursor = gdk_cursor_new(GDK_WATCH);
gdk_window_set_cursor(w, cursor);
gdk_flush();
#if GTK_CHECK_VERSION(3,0,0)
g_object_unref(cursor);
#else
gdk_cursor_unref(cursor);
#endif
}
static void unset_busy_cursor(GdkWindow *w)
{
gdk_window_set_cursor(w, NULL);
gdk_flush();
}
void rlc_lte_graph_cb(GtkAction *action _U_, gpointer user_data _U_)
{
struct rlc_segment current;
struct gtk_rlc_graph *g;
gchar *err_msg = NULL;
gboolean free_err_msg = FALSE;
debug(DBS_FENTRY) puts("rlc_lte_graph_cb()");
if (!select_rlc_lte_session(&cfile, &current, &err_msg, &free_err_msg)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
if (free_err_msg) {
g_free(err_msg);
}
return;
}
if (!(g = graph_new())) {
return;
}
refnum++;
graph_initialize_values(g);
rlc_graph_segment_list_get(&cfile, &(g->graph), FALSE, &err_msg, &free_err_msg);
create_gui(g);
graph_init_sequence(g);
}
void rlc_lte_graph_known_channel_launch(guint16 ueid, guint8 rlcMode,
guint16 channelType, guint16 channelId,
guint8 direction)
{
struct gtk_rlc_graph *g;
gchar *err_msg = NULL;
gboolean free_err_msg = FALSE;
debug(DBS_FENTRY) puts("rlc_lte_graph_known_channel_launch()");
if (!(g = graph_new())) {
return;
}
refnum++;
graph_initialize_values(g);
g->graph.ueid = ueid;
g->graph.rlcMode = rlcMode;
g->graph.channelType = channelType;
g->graph.channelId = channelId;
g->graph.direction = direction;
g->graph.channelSet = TRUE;
rlc_graph_segment_list_get(&cfile, &(g->graph), TRUE, &err_msg, &free_err_msg);
create_gui(g);
graph_init_sequence(g);
}
static void create_gui(struct gtk_rlc_graph *g)
{
debug(DBS_FENTRY) puts("create_gui()");
create_drawing_area(g);
}
static void create_drawing_area(struct gtk_rlc_graph *g)
{
#if GTK_CHECK_VERSION(3,0,0)
GtkStyleContext *context;
#endif
char *display_name;
char window_title[WINDOW_TITLE_LENGTH];
GtkAllocation widget_alloc;
debug(DBS_FENTRY) puts("create_drawing_area()");
display_name = cf_get_display_name(&cfile);
g_snprintf(window_title, WINDOW_TITLE_LENGTH, "LTE RLC Graph %d: %s (UE-%u, chan=%s%u %s - %s)",
refnum, display_name,
g->graph.ueid, (g->graph.channelType == CHANNEL_TYPE_SRB) ? "SRB" : "DRB",
g->graph.channelId,
(g->graph.direction == DIRECTION_UPLINK) ? "UL" : "DL",
(g->graph.rlcMode == RLC_UM_MODE) ? "UM" : "AM");
g_free(display_name);
g->toplevel = dlg_window_new("RLC Graph");
gtk_window_set_title(GTK_WINDOW(g->toplevel), window_title);
gtk_widget_set_name(g->toplevel, "Test Graph");
g->drawing_area = gtk_drawing_area_new();
g->x_axis->drawing_area = g->y_axis->drawing_area = g->drawing_area;
gtk_widget_set_size_request(g->drawing_area,
g->wp.width + g->wp.x + RMARGIN_WIDTH,
g->wp.height + g->wp.y + g->x_axis->s.height);
gtk_widget_show(g->drawing_area);
#if GTK_CHECK_VERSION(3,0,0)
g_signal_connect(g->drawing_area, "draw", G_CALLBACK(draw_event), g);
#else
g_signal_connect(g->drawing_area, "expose_event", G_CALLBACK(expose_event), g);
#endif
g_signal_connect(g->drawing_area, "button_press_event",
G_CALLBACK(button_press_event), g);
g_signal_connect(g->drawing_area, "button_release_event",
G_CALLBACK(button_release_event), g);
g_signal_connect(g->toplevel, "destroy", G_CALLBACK(callback_toplevel_destroy), g);
g_signal_connect(g->drawing_area, "motion_notify_event",
G_CALLBACK(motion_notify_event), g);
g_signal_connect(g->toplevel, "key_press_event", G_CALLBACK(key_press_event), g);
gtk_widget_set_events(g->toplevel,
GDK_KEY_PRESS_MASK|GDK_KEY_RELEASE_MASK);
gtk_widget_set_events(g->drawing_area,
GDK_EXPOSURE_MASK
| GDK_LEAVE_NOTIFY_MASK
| GDK_ENTER_NOTIFY_MASK
| GDK_BUTTON_PRESS_MASK
| GDK_BUTTON_RELEASE_MASK
| GDK_POINTER_MOTION_MASK
| GDK_POINTER_MOTION_HINT_MASK);
gtk_container_add(GTK_CONTAINER(g->toplevel), g->drawing_area);
gtk_widget_show(g->toplevel);
gtk_widget_get_allocation(GTK_WIDGET(g->drawing_area), &widget_alloc);
g->wp.width = widget_alloc.width - g->wp.x - RMARGIN_WIDTH;
g->wp.height = widget_alloc.height - g->wp.y - g->x_axis->s.height;
#if GTK_CHECK_VERSION(3,0,0)
context = gtk_widget_get_style_context(g->drawing_area);
gtk_style_context_get(context, GTK_STATE_FLAG_NORMAL,
GTK_STYLE_PROPERTY_FONT, &g->font,
NULL);
#else
g->font = gtk_widget_get_style(g->drawing_area)->font_desc;
#endif
g_signal_connect(g->drawing_area, "configure_event", G_CALLBACK(configure_event), g);
}
static void callback_toplevel_destroy(GtkWidget *widget _U_, gpointer data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph * )data;
if (!(g->flags & GRAPH_DESTROYED)) {
g->flags |= GRAPH_DESTROYED;
graph_destroy((struct gtk_rlc_graph * )data);
}
}
static void callback_create_help(GtkWidget *widget _U_, gpointer data _U_)
{
GtkWidget *toplevel, *vbox, *text, *scroll, *bbox, *close_bt;
GtkTextBuffer *buf;
toplevel = dlg_window_new("Help for LTE RLC graphing");
gtk_window_set_default_size(GTK_WINDOW(toplevel), 540, 540);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
gtk_container_add(GTK_CONTAINER(toplevel), vbox);
scroll = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scroll),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(vbox), scroll, TRUE, TRUE, 0);
text = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(text), FALSE);
buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));
gtk_text_buffer_set_text(buf, helptext, -1);
gtk_container_add(GTK_CONTAINER(scroll), text);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(toplevel, close_bt, window_cancel_button_cb);
g_signal_connect(toplevel, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show_all(toplevel);
window_present(toplevel);
}
static void get_mouse_position(GtkWidget *widget, int *pointer_x, int *pointer_y, GdkModifierType *mask)
{
#if GTK_CHECK_VERSION(3,0,0)
gdk_window_get_device_position (gtk_widget_get_window(widget),
gdk_device_manager_get_client_pointer(
gdk_display_get_device_manager(
gtk_widget_get_display(GTK_WIDGET(widget)))),
pointer_x, pointer_y, mask);
#else
gdk_window_get_pointer (gtk_widget_get_window(widget), pointer_x, pointer_y, mask);
#endif
}
static struct gtk_rlc_graph *graph_new(void)
{
struct gtk_rlc_graph *g;
g = (struct gtk_rlc_graph * )g_malloc0(sizeof(struct gtk_rlc_graph));
graph_element_lists_initialize(g);
g->x_axis = (struct axis * )g_malloc0(sizeof(struct axis));
g->y_axis = (struct axis * )g_malloc0(sizeof(struct axis));
g->x_axis->g = g;
g->x_axis->is_horizontal_axis = TRUE;
g->x_axis->s.x = g->x_axis->s.y = 0;
g->x_axis->s.height = HAXIS_INIT_HEIGHT;
g->x_axis->p.x = VAXIS_INIT_WIDTH;
g->x_axis->p.height = HAXIS_INIT_HEIGHT;
g->y_axis->g = g;
g->y_axis->is_horizontal_axis = FALSE;
g->y_axis->p.x = g->y_axis->p.y = 0;
g->y_axis->p.width = VAXIS_INIT_WIDTH;
g->y_axis->s.x = 0;
g->y_axis->s.y = TITLEBAR_HEIGHT;
g->y_axis->s.width = VAXIS_INIT_WIDTH;
return g;
}
static void graph_initialize_values(struct gtk_rlc_graph *g)
{
g->geom.width = g->wp.width = 750;
g->geom.height = g->wp.height = 550;
g->geom.x = g->wp.x = VAXIS_INIT_WIDTH;
g->geom.y = g->wp.y = TITLEBAR_HEIGHT;
g->flags = 0;
g->zoom.x = g->zoom.y = 1.0;
g->zoom.step_x = g->zoom.step_y = 1.15;
g->zoom.flags = 0;
g->cross.draw = g->cross.erase_needed = FALSE;
g->zoomrect_erase_needed = FALSE;
g->grab.grabbed = 0;
}
static void graph_init_sequence(struct gtk_rlc_graph *g)
{
debug(DBS_FENTRY) puts("graph_init_sequence()");
graph_initialize(g);
g->zoom.initial.x = g->zoom.x;
g->zoom.initial.y = g->zoom.y;
graph_element_lists_make(g);
g->x_axis->s.width = g->wp.width;
g->x_axis->p.width = g->x_axis->s.width + RMARGIN_WIDTH;
g->x_axis->p.y = TITLEBAR_HEIGHT + g->wp.height;
g->x_axis->s.height = g->x_axis->p.height = HAXIS_INIT_HEIGHT;
g->y_axis->s.height = g->wp.height;
g->y_axis->p.height = g->wp.height + TITLEBAR_HEIGHT;
graph_pixmaps_create(g);
axis_pixmaps_create(g->y_axis);
axis_pixmaps_create(g->x_axis);
graph_title_pixmap_create(g);
graph_title_pixmap_draw(g);
graph_title_pixmap_display(g);
graph_display(g);
axis_display(g->y_axis);
axis_display(g->x_axis);
}
static void graph_initialize(struct gtk_rlc_graph *g)
{
debug(DBS_FENTRY) puts("graph_initialize()");
graph_get_bounds(g);
g->x_axis->min = g->bounds.x0;
g->y_axis->min = 0;
graph_read_config(g);
}
static void graph_destroy(struct gtk_rlc_graph *g)
{
debug(DBS_FENTRY) puts("graph_destroy()");
axis_destroy(g->x_axis);
axis_destroy(g->y_axis);
window_destroy(g->toplevel);
#if GTK_CHECK_VERSION(2,22,0)
if (g->title_surface){
cairo_surface_destroy(g->title_surface);
}
if (g->surface[0]){
cairo_surface_destroy(g->surface[0]);
}
if (g->surface[1]){
cairo_surface_destroy(g->surface[1]);
}
#else
g_object_unref(g->pixmap[0]);
g_object_unref(g->pixmap[1]);
#endif
g_free(g->x_axis);
g_free(g->y_axis);
rlc_graph_segment_list_free(&g->graph);
graph_element_lists_free(g);
g_free(g);
}
static void graph_element_lists_initialize(struct gtk_rlc_graph *g)
{
g->graph.elists = (struct element_list *)g_malloc0(sizeof(struct element_list));
g->graph.elists->elements = NULL;
g->graph.elists->next = NULL;
}
static void graph_element_lists_make(struct gtk_rlc_graph *g)
{
debug(DBS_FENTRY) puts("graph_element_lists_make()");
rlc_lte_make_elmtlist(g);
}
static void graph_element_lists_free(struct gtk_rlc_graph *g)
{
struct element_list *list, *next_list;
for (list=g->graph.elists; list; list=next_list) {
g_free(list->elements);
next_list = list->next;
g_free(list);
}
g->graph.elists = NULL;
}
static void graph_title_pixmap_create(struct gtk_rlc_graph *g)
{
#if GTK_CHECK_VERSION(2,22,0)
if (g->title_surface){
cairo_surface_destroy(g->title_surface);
g->title_surface = NULL;
}
g->title_surface = gdk_window_create_similar_surface(gtk_widget_get_window(g->drawing_area),
CAIRO_CONTENT_COLOR,
g->x_axis->p.width,
g->wp.y);
#else
if (g->title_pixmap)
g_object_unref(g->title_pixmap);
g->title_pixmap = gdk_pixmap_new(gtk_widget_get_window(g->drawing_area),
g->x_axis->p.width, g->wp.y, -1);
#endif
}
static void graph_title_pixmap_draw(struct gtk_rlc_graph *g)
{
gint w, h;
PangoLayout *layout;
cairo_t *cr;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create(g->title_surface);
#else
cr = gdk_cairo_create(g->title_pixmap);
#endif
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, 0, 0, g->x_axis->p.width, g->wp.y);
cairo_fill(cr);
layout = gtk_widget_create_pango_layout(g->drawing_area, "");
pango_layout_get_pixel_size(layout, &w, &h);
cairo_move_to(cr, g->wp.width/2 - w/2, 20);
pango_cairo_show_layout(cr, layout);
g_object_unref(G_OBJECT(layout));
cairo_destroy(cr);
}
static void graph_title_pixmap_display(struct gtk_rlc_graph *g)
{
cairo_t *cr;
cr = gdk_cairo_create(gtk_widget_get_window(g->drawing_area));
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface(cr, g->title_surface, g->wp.x, 0);
#else
gdk_cairo_set_source_pixmap(cr, g->title_pixmap, g->wp.x, 0);
#endif
cairo_rectangle(cr, g->wp.x, 0, g->x_axis->p.width, g->wp.y);
cairo_fill(cr);
cairo_destroy(cr);
}
static void graph_pixmaps_create(struct gtk_rlc_graph *g)
{
debug(DBS_FENTRY) puts("graph_pixmaps_create()");
#if GTK_CHECK_VERSION(2,22,0)
if (g->surface[0]){
cairo_surface_destroy(g->surface[0]);
g->surface[0] = NULL;
}
if (g->surface[1]){
cairo_surface_destroy(g->surface[1]);
g->surface[1] = NULL;
}
g->surface[0] = gdk_window_create_similar_surface(gtk_widget_get_window(g->drawing_area),
CAIRO_CONTENT_COLOR,
g->wp.width,
g->wp.height);
g->surface[1] = gdk_window_create_similar_surface(gtk_widget_get_window(g->drawing_area),
CAIRO_CONTENT_COLOR,
g->wp.width,
g->wp.height);
g->displayed = 0;
#else
if (g->pixmap[0])
g_object_unref(g->pixmap[0]);
if (g->pixmap[1])
g_object_unref(g->pixmap[1]);
g->pixmap[0] = gdk_pixmap_new(gtk_widget_get_window(g->drawing_area),
g->wp.width, g->wp.height, -1);
g->pixmap[1] = gdk_pixmap_new(gtk_widget_get_window(g->drawing_area),
g->wp.width, g->wp.height, -1);
g->displayed = 0;
#endif
}
static void graph_display(struct gtk_rlc_graph *g)
{
set_busy_cursor(gtk_widget_get_window(g->drawing_area));
graph_pixmap_draw(g);
unset_busy_cursor(gtk_widget_get_window(g->drawing_area));
graph_pixmaps_switch(g);
graph_pixmap_display(g);
}
static void graph_pixmap_display(struct gtk_rlc_graph *g)
{
cairo_t *cr;
cr = gdk_cairo_create(gtk_widget_get_window(g->drawing_area));
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface(cr, g->surface[g->displayed], g->wp.x, g->wp.y);
#else
gdk_cairo_set_source_pixmap(cr, g->pixmap[g->displayed], g->wp.x, g->wp.y);
#endif
cairo_rectangle(cr, g->wp.x, g->wp.y, g->wp.width, g->wp.height);
cairo_fill(cr);
cairo_destroy(cr);
}
static void graph_pixmaps_switch(struct gtk_rlc_graph *g)
{
g->displayed = 1 ^ g->displayed;
}
static void graph_pixmap_draw(struct gtk_rlc_graph *g)
{
struct element_list *list;
struct element *e;
int not_disp;
cairo_t *cr;
cairo_t *cr_elements;
GdkRGBA *current_color = NULL;
GdkRGBA *color_to_set = NULL;
gboolean line_stroked = TRUE;
debug(DBS_FENTRY) puts("graph_display()");
not_disp = 1 ^ g->displayed;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create(g->surface[not_disp]);
#else
cr = gdk_cairo_create(g->pixmap[not_disp]);
#endif
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, 0, 0, g->wp.width, g->wp.height);
cairo_fill(cr);
cairo_destroy(cr);
#if GTK_CHECK_VERSION(2,22,0)
cr_elements = cairo_create(g->surface[not_disp]);
#else
cr_elements = gdk_cairo_create(g->pixmap[not_disp]);
#endif
cairo_set_tolerance(cr_elements, 1.0);
cairo_set_line_width(cr_elements, 1.0);
for (list=g->graph.elists; list; list=list->next) {
for (e=list->elements; e->type != ELMT_NONE; e++) {
if (current_color == e->elment_color_p) {
color_to_set = NULL;
}
else {
current_color = color_to_set = e->elment_color_p;
cairo_stroke(cr_elements);
}
switch (e->type) {
case ELMT_LINE:
draw_element_line(g, e, cr_elements, color_to_set);
line_stroked = FALSE;
break;
case ELMT_ELLIPSE:
if (!line_stroked) {
cairo_stroke(cr_elements);
line_stroked = TRUE;
}
draw_element_ellipse(g, e, cr_elements, color_to_set);
break;
default:
break;
}
}
if (!line_stroked) {
cairo_stroke(cr_elements);
}
}
cairo_destroy(cr_elements);
}
static void draw_element_line(struct gtk_rlc_graph *g, struct element *e, cairo_t *cr,
GdkRGBA *new_color)
{
int xx1, xx2, yy1, yy2;
debug(DBS_GRAPH_DRAWING)
printf("\nline element: (%.2f,%.2f)->(%.2f,%.2f), seg %u ...\n",
e->p.line.dim.x1, e->p.line.dim.y1,
e->p.line.dim.x2, e->p.line.dim.y2, e->parent->num);
if (new_color != NULL) {
gdk_cairo_set_source_rgba(cr, new_color);
}
xx1 = (int)rint(e->p.line.dim.x1 + g->geom.x - g->wp.x);
xx2 = (int)rint(e->p.line.dim.x2 + g->geom.x - g->wp.x);
yy1 = (int)rint((g->geom.height-1-e->p.line.dim.y1) + g->geom.y-g->wp.y);
yy2 = (int)rint((g->geom.height-1-e->p.line.dim.y2) + g->geom.y-g->wp.y);
if (((xx1 < 0) && (xx2 < 0)) || ((xx1 >= g->wp.width) && (xx2 >= g->wp.width)) ||
((yy1 < 0) && (yy2 < 0)) || ((yy1 >= g->wp.height) && (yy2 >= g->wp.height))) {
debug(DBS_GRAPH_DRAWING) printf(" refusing: (%d,%d)->(%d,%d)\n", xx1, yy1, xx2, yy2);
return;
}
debug(DBS_GRAPH_DRAWING) printf("line: (%d,%d)->(%d,%d)\n", xx1, yy1, xx2, yy2);
cairo_move_to(cr, xx1+0.5, yy1+0.5);
cairo_line_to(cr, xx2+0.5, yy2+0.5);
}
static void draw_element_ellipse(struct gtk_rlc_graph *g, struct element *e, cairo_t *cr,
GdkRGBA *new_color)
{
gdouble w = e->p.ellipse.dim.width;
gdouble h = e->p.ellipse.dim.height;
gdouble x = e->p.ellipse.dim.x + g->geom.x - g->wp.x;
gdouble y = g->geom.height-1 - e->p.ellipse.dim.y + g->geom.y - g->wp.y;
debug(DBS_GRAPH_DRAWING) printf ("ellipse: (x, y) -> (w, h): (%f, %f) -> (%f, %f)\n", x, y, w, h);
if (new_color != NULL) {
gdk_cairo_set_source_rgba(cr, new_color);
}
cairo_save(cr);
cairo_translate(cr, x + w/2.0, y + h/2.0);
cairo_scale(cr, w/2.0, h/2.0);
cairo_arc(cr, 0.0, 0.0, 1.0, 0.0, 2*G_PI);
cairo_fill(cr);
cairo_restore(cr);
}
static void axis_pixmaps_create(struct axis *axis)
{
debug(DBS_FENTRY) puts("axis_pixmaps_create()");
#if GTK_CHECK_VERSION(2,22,0)
if (axis->surface[0]){
cairo_surface_destroy(axis->surface[0]);
axis->surface[0] = NULL;
}
if (axis->surface[1]){
cairo_surface_destroy(axis->surface[1]);
axis->surface[1] = NULL;
}
axis->surface[0] = gdk_window_create_similar_surface(gtk_widget_get_window(axis->drawing_area),
CAIRO_CONTENT_COLOR,
axis->p.width,
axis->p.height);
axis->surface[1] = gdk_window_create_similar_surface(gtk_widget_get_window(axis->drawing_area),
CAIRO_CONTENT_COLOR,
axis->p.width,
axis->p.height);
axis->displayed = 0;
#else
if (axis->pixmap[0])
g_object_unref(axis->pixmap[0]);
if (axis->pixmap[1])
g_object_unref(axis->pixmap[1]);
axis->pixmap[0] = gdk_pixmap_new(gtk_widget_get_window(axis->drawing_area),
axis->p.width, axis->p.height, -1);
axis->pixmap[1] = gdk_pixmap_new(gtk_widget_get_window(axis->drawing_area),
axis->p.width, axis->p.height, -1);
axis->displayed = 0;
#endif
}
static void axis_destroy(struct axis *axis)
{
#if GTK_CHECK_VERSION(2,22,0)
if (axis->surface[0]){
cairo_surface_destroy(axis->surface[0]);
axis->surface[0] = NULL;
}
if (axis->surface[1]){
cairo_surface_destroy(axis->surface[1]);
axis->surface[1] = NULL;
}
#else
g_object_unref(axis->pixmap[0]);
g_object_unref(axis->pixmap[1]);
#endif
g_free((gpointer)(axis->label) );
}
static void axis_display(struct axis *axis)
{
if (axis->is_horizontal_axis)
h_axis_pixmap_draw(axis);
else
v_axis_pixmap_draw(axis);
axis_pixmaps_switch(axis);
axis_pixmap_display(axis);
}
static void v_axis_pixmap_draw(struct axis *axis)
{
struct gtk_rlc_graph *g = axis->g;
int i;
double major_tick;
int not_disp, offset, imin, imax;
double bottom, top, fl, corr;
PangoLayout *layout;
cairo_t *cr;
debug(DBS_FENTRY) puts("v_axis_pixmap_draw()");
bottom = (g->geom.height - (g->wp.height + g->wp.y + (-g->geom.y))) /
(double )g->geom.height * g->bounds.height;
bottom += axis->min;
top = (g->geom.height - (g->wp.y + (-g->geom.y))) /
(double )g->geom.height * g->bounds.height;
top += axis->min;
axis_compute_ticks(axis, bottom, top, AXIS_VERTICAL);
not_disp = 1 ^ axis->displayed;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create(axis->surface[not_disp]);
#else
cr = gdk_cairo_create(axis->pixmap[not_disp]);
#endif
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, 0, 0, axis->p.width, axis->p.height);
cairo_fill(cr);
cairo_set_source_rgb(cr, 0, 0, 0);
cairo_set_line_width(cr, 1.0);
cairo_move_to(cr, axis->p.width - 1.5, (axis->p.height-axis->s.height)/2.0);
cairo_line_to(cr, axis->s.width - 1.5, axis->p.height);
offset = g->wp.y + (-g->geom.y);
fl = floor(axis->min / axis->major) * axis->major;
corr = rint((axis->min - fl) * g->zoom.y);
major_tick = axis->major * g->zoom.y;
imin = (int) ((g->geom.height - offset + corr - g->wp.height) / major_tick + 1);
imax = (int) ((g->geom.height - offset + corr) / major_tick);
for (i=imin; i <= imax; i++) {
gint w, h;
char desc[32];
int y = (int) (g->geom.height-1 - (int )rint(i * major_tick) -
offset + corr + axis->s.y);
debug(DBS_AXES_DRAWING) printf("%f @ %d\n",
i*axis->major + fl, y);
if ((y < 0) || (y > axis->p.height))
continue;
cairo_move_to(cr, axis->p.width - 15, y+0.5);
cairo_line_to(cr, axis->s.width - 1, y+0.5);
g_snprintf(desc, sizeof(desc), "%u", (unsigned int)(i*axis->major + fl));
layout = gtk_widget_create_pango_layout(g->drawing_area, desc);
pango_layout_get_pixel_size(layout, &w, &h);
cairo_move_to(cr, axis->s.width-14-4-w, y - h/2);
pango_cairo_show_layout(cr, layout);
g_object_unref(G_OBJECT(layout));
}
if (axis->minor) {
double minor_tick = axis->minor * g->zoom.y;
imin = (int) ((g->geom.height - offset + corr - g->wp.height)/minor_tick + 1);
imax = (int) ((g->geom.height - offset + corr) / minor_tick);
for (i=imin; i <= imax; i++) {
int y = (int) (g->geom.height-1 - (int )rint(i*minor_tick) -
offset + corr + axis->s.y);
if ((y > 0) && (y < axis->p.height)) {
cairo_set_line_width(cr, 1.0);
cairo_move_to(cr, axis->s.width - 8, y+0.5);
cairo_line_to(cr, axis->s.width - 1, y+0.5);
}
}
}
for (i=0; axis->label[i]; i++) {
gint w, h;
layout = gtk_widget_create_pango_layout(g->drawing_area,
axis->label[i]);
pango_layout_get_pixel_size(layout, &w, &h);
cairo_move_to(cr, (axis->p.width - w)/2, TITLEBAR_HEIGHT-10 - i*(h+3) - h);
pango_cairo_show_layout(cr, layout);
g_object_unref(G_OBJECT(layout));
}
cairo_stroke(cr);
cairo_destroy(cr);
}
static void h_axis_pixmap_draw(struct axis *axis)
{
struct gtk_rlc_graph *g = axis->g;
int i;
double major_tick, minor_tick;
int not_disp, rdigits, offset, imin, imax;
double left, right, j, fl, corr;
PangoLayout *layout;
cairo_t *cr;
debug(DBS_FENTRY) puts("h_axis_pixmap_draw()");
left = (g->wp.x-g->geom.x) / (double)g->geom.width * g->bounds.width;
left += axis->min;
right = (g->wp.x-g->geom.x+g->wp.width) / (double)g->geom.width * g->bounds.width;
right += axis->min;
axis_compute_ticks(axis, left, right, AXIS_HORIZONTAL);
j = axis->major - floor(axis->major);
for (rdigits=0; rdigits <= 6; rdigits++) {
j *= 10;
if (j <= 0.000001)
break;
j = j - floor(j);
}
not_disp = 1 ^ axis->displayed;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create(axis->surface[not_disp]);
#else
cr = gdk_cairo_create(axis->pixmap[not_disp]);
#endif
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, 0, 0, axis->p.width, axis->p.height);
cairo_fill(cr);
cairo_set_source_rgb(cr, 0, 0, 0);
cairo_set_line_width(cr, 1.0);
cairo_move_to(cr, 0, 0.5);
cairo_line_to(cr, axis->s.width + (axis->p.width-axis->s.width)/2.0, 0.5);
offset = g->wp.x - g->geom.x;
fl = floor(axis->min / axis->major) * axis->major;
corr = rint((axis->min - fl) * g->zoom.x);
major_tick = axis->major*g->zoom.x;
imin = (int) ((offset + corr) / major_tick + 1);
imax = (int) ((offset + corr + axis->s.width) / major_tick);
for (i=imin; i <= imax; i++) {
char desc[32];
int w, h;
int x = (int) (rint(i * major_tick) - offset - corr);
if ((x < 0) || (x > axis->s.width))
continue;
cairo_move_to(cr, x+0.5, 0);
cairo_line_to(cr, x+0.5, 15);
g_snprintf(desc, sizeof(desc), "%.*f", rdigits, i*axis->major + fl);
layout = gtk_widget_create_pango_layout(g->drawing_area, desc);
pango_layout_get_pixel_size(layout, &w, &h);
cairo_move_to(cr, x - w/2, 15+4);
pango_cairo_show_layout(cr, layout);
g_object_unref(G_OBJECT(layout));
}
if (axis->minor > 0) {
minor_tick = axis->minor*g->zoom.x;
imin = (int) ((offset + corr) / minor_tick + 1);
imax = (int) ((offset + corr + g->wp.width) / minor_tick);
for (i=imin; i <= imax; i++) {
int x = (int) (rint(i * minor_tick) - offset - corr);
if ((x > 0) && (x < axis->s.width)){
cairo_move_to(cr, x+0.5, 0);
cairo_line_to(cr, x+0.5, 8);
}
}
}
for (i=0; axis->label[i]; i++) {
gint w, h;
layout = gtk_widget_create_pango_layout(g->drawing_area,
axis->label[i]);
pango_layout_get_pixel_size(layout, &w, &h);
cairo_move_to(cr, axis->s.width - w - 50, 15+h+15 + i*(h+3));
pango_cairo_show_layout(cr, layout);
g_object_unref(G_OBJECT(layout));
}
cairo_stroke(cr);
cairo_destroy(cr);
}
static void axis_pixmaps_switch(struct axis *axis)
{
axis->displayed = 1 ^ axis->displayed;
}
static void axis_pixmap_display(struct axis *axis)
{
cairo_t *cr;
cr = gdk_cairo_create(gtk_widget_get_window(axis->drawing_area));
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface(cr, axis->surface[axis->displayed], axis->p.x, axis->p.y);
#else
gdk_cairo_set_source_pixmap(cr, axis->pixmap[axis->displayed], axis->p.x, axis->p.y);
#endif
cairo_rectangle(cr, axis->p.x, axis->p.y, axis->p.width, axis->p.height);
cairo_fill(cr);
cairo_destroy(cr);
}
static void axis_compute_ticks(struct axis *axis, double x0, double xmax, int dir)
{
int i, j, ii, jj, ms;
double zoom, x, steps[3] = { 0.1, 0.5 };
int dim, check_needed, diminished;
double majthresh[2] = {2.0, 3.0};
debug((DBS_FENTRY | DBS_AXES_TICKS)) puts("axis_compute_ticks()");
debug(DBS_AXES_TICKS)
printf("x0=%f xmax=%f dir=%s\n", x0,xmax, dir? "VERTICAL" : "HORIZONTAL");
zoom = axis_zoom_get(axis, dir);
x = xmax-x0;
for (i=-9; i <= 12; i++) {
if (x / pow(10, i) < 1)
break;
}
--i;
ms = (int )(x / pow(10, i));
if (ms > 5) {
j = 0;
++i;
} else if (ms > 2)
j = 1;
else
j = 0;
axis->major = steps[j] * pow(10, i);
if (dir == AXIS_VERTICAL) {
axis->major = MAX(axis->major, 1.0);
}
debug(DBS_AXES_TICKS) printf("zoom=%.1f, x=%f -> i=%d -> ms=%d -> j=%d ->"
" axis->major=%f\n", zoom, x, i, ms, j, axis->major);
jj = j;
ii = i;
axis_ticks_down(&ii, &jj);
if ((dir == AXIS_VERTICAL) && (axis->major <= 1)) {
axis->minor = 0;
}
else {
axis->minor = steps[jj] * pow(10, ii);
if (axis->minor*zoom < 10) {
debug(DBS_AXES_TICKS) printf("refusing axis->minor of %f: "
"axis->minor*zoom == %f\n",
axis->minor, axis->minor*zoom);
axis->minor = 0;
}
}
check_needed = TRUE;
diminished = FALSE;
while (check_needed) {
check_needed = FALSE;
dim = get_label_dim(axis, dir, xmax);
debug(DBS_AXES_TICKS) printf("axis->major==%.1f, axis->minor==%.1f =>"
" axis->major*zoom/dim==%f, axis->minor*zoom/dim==%f\n",
axis->major, axis->minor, axis->major*zoom/dim,
axis->minor*zoom/dim);
if (axis->major*zoom / dim < majthresh[dir]) {
axis_ticks_up(&ii, &jj);
axis->minor = axis->major;
axis_ticks_up(&i, &j);
axis->major = steps[j] * pow(10, i);
check_needed = TRUE;
debug(DBS_AXES_TICKS) printf("axis->major enlarged to %.1f\n",
axis->major);
}
if ((axis->minor*zoom / dim > majthresh[dir]) && !diminished) {
axis_ticks_down(&i, &j);
axis->major = axis->minor;
axis_ticks_down(&ii, &jj);
axis->minor = steps[jj] * pow(10, ii);
check_needed = TRUE;
diminished = TRUE;
debug(DBS_AXES_TICKS) printf("axis->minor diminished to %.1f\n",
axis->minor);
if (axis->minor*zoom < 10) {
debug(DBS_AXES_TICKS) printf("refusing axis->minor of %f: "
"axis->minor*zoom == %f\n", axis->minor, axis->minor*zoom);
axis->minor = 0;
}
}
}
debug(DBS_AXES_TICKS) printf("corrected: axis->major == %.1f -> "
"axis->minor == %.1f\n", axis->major, axis->minor);
}
static void axis_ticks_up(int *i, int *j)
{
(*j)++;
if (*j>1) {
(*i)++;
*j = 0;
}
}
static void axis_ticks_down(int *i, int *j)
{
(*j)--;
if (*j < 0) {
(*i)--;
*j = 1;
}
}
static int get_label_dim(struct axis *axis, int dir, double label)
{
double y;
char str[32];
int rdigits, dim;
PangoLayout *layout;
y = axis->major - floor(axis->major);
for (rdigits=0; rdigits <= 6; rdigits++) {
y *= 10;
if (y <= 0.000001)
break;
y = y - floor(y);
}
g_snprintf(str, sizeof(str), "%.*f", rdigits, label);
switch (dir) {
case AXIS_HORIZONTAL:
layout = gtk_widget_create_pango_layout(axis->g->drawing_area, str);
pango_layout_get_pixel_size(layout, &dim, NULL);
g_object_unref(G_OBJECT(layout));
break;
case AXIS_VERTICAL:
layout = gtk_widget_create_pango_layout(axis->g->drawing_area, str);
pango_layout_get_pixel_size(layout, NULL, &dim);
g_object_unref(G_OBJECT(layout));
break;
default:
puts("initialize axis: an axis must be either horizontal or vertical");
return -1;
}
return dim;
}
static double axis_zoom_get(struct axis *axis, int dir)
{
switch (dir) {
case AXIS_HORIZONTAL:
return axis->g->zoom.x;
case AXIS_VERTICAL:
return axis->g->zoom.y;
default:
return -1;
}
}
static void graph_select_segment(struct gtk_rlc_graph *g, int x, int y)
{
struct element_list *list;
struct element *e;
guint num = 0;
debug(DBS_FENTRY) puts("graph_select_segment()");
x -= g->geom.x;
y = g->geom.height-1 - (y - g->geom.y);
set_busy_cursor(gtk_widget_get_window(g->drawing_area));
for (list=g->graph.elists; list; list=list->next) {
for (e=list->elements; e->type != ELMT_NONE; e++) {
switch (e->type) {
case ELMT_LINE:
if (line_detect_collision(e, x, y)) {
num = e->parent->num;
}
break;
case ELMT_ELLIPSE:
if (ellipse_detect_collision(e, x, y)) {
num = e->parent->num;
}
break;
default:
break;
}
}
}
if (num) {
cf_goto_frame(&cfile, num);
}
}
static int line_detect_collision(struct element *e, int x, int y)
{
int xx1, yy1, xx2, yy2;
if (e->p.line.dim.x1 < e->p.line.dim.x2) {
xx1 = (int)rint(e->p.line.dim.x1);
xx2 = (int)rint(e->p.line.dim.x2);
} else {
xx1 = (int)rint(e->p.line.dim.x2);
xx2 = (int)rint(e->p.line.dim.x1);
}
if (e->p.line.dim.y1 < e->p.line.dim.y2) {
yy1 = (int)rint(e->p.line.dim.y1);
yy2 = (int)rint(e->p.line.dim.y2);
} else {
yy1 = (int)rint(e->p.line.dim.y2);
yy2 = (int)rint(e->p.line.dim.y1);
}
if (((xx1 == x) && (xx2 == x) && (yy1 <= y) && (y <= yy2) )|
((yy1 == y) && (yy2 == y) && (xx1 <= x) && (x <= xx2))) {
return TRUE;
}
else {
return FALSE;
}
}
static int ellipse_detect_collision(struct element *e, int x, int y)
{
int xx1, yy1, xx2, yy2;
xx1 = (int )rint (e->p.ellipse.dim.x);
xx2 = (int )rint (e->p.ellipse.dim.x + e->p.ellipse.dim.width);
yy1 = (int )rint (e->p.ellipse.dim.y - e->p.ellipse.dim.height);
yy2 = (int )rint (e->p.ellipse.dim.y);
if ((xx1 <= x) && (x <= xx2) && (yy1 <= y) && (y <= yy2)) {
return TRUE;
}
else {
return FALSE;
}
}
static gboolean configure_event(GtkWidget *widget _U_, GdkEventConfigure *event, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
struct zoom new_zoom;
int cur_g_width, cur_g_height;
int cur_wp_width, cur_wp_height;
debug(DBS_FENTRY) puts("configure_event()");
cur_wp_width = g->wp.width;
cur_wp_height = g->wp.height;
g->wp.width = event->width - g->y_axis->p.width - RMARGIN_WIDTH;
g->wp.height = event->height - g->x_axis->p.height - g->wp.y;
g->x_axis->s.width = g->wp.width;
g->x_axis->p.width = g->wp.width + RMARGIN_WIDTH;
g->y_axis->p.height = g->wp.height + g->wp.y;
g->y_axis->s.height = g->wp.height;
g->x_axis->p.y = g->y_axis->p.height;
new_zoom.x = (double)g->wp.width / cur_wp_width;
new_zoom.y = (double)g->wp.height / cur_wp_height;
cur_g_width = g->geom.width;
cur_g_height = g->geom.height;
g->geom.width = (int)rint(g->geom.width * new_zoom.x);
g->geom.height = (int)rint(g->geom.height * new_zoom.y);
g->zoom.x = (double)(g->geom.width - 1) / g->bounds.width;
g->zoom.y = (double)(g->geom.height -1) / g->bounds.height;
g->geom.x = (int)(g->wp.x - (double)g->geom.width/cur_g_width * (g->wp.x - g->geom.x));
g->geom.y = (int)(g->wp.y - (double)g->geom.height/cur_g_height * (g->wp.y - g->geom.y));
#if 0
printf("configure: graph: (%d,%d), (%d,%d); viewport: (%d,%d), (%d,%d); "
"zooms: (%f,%f)\n", g->geom.x, g->geom.y, g->geom.width,
g->geom.height, g->wp.x, g->wp.y, g->wp.width, g->wp.height,
g->zoom.x, g->zoom.y);
#endif
graph_element_lists_make(g);
graph_pixmaps_create(g);
graph_title_pixmap_create(g);
axis_pixmaps_create(g->y_axis);
axis_pixmaps_create(g->x_axis);
graph_pixmap_draw(g);
graph_pixmaps_switch(g);
graph_title_pixmap_draw(g);
h_axis_pixmap_draw(g->x_axis);
axis_pixmaps_switch(g->x_axis);
v_axis_pixmap_draw(g->y_axis);
axis_pixmaps_switch(g->y_axis);
return TRUE;
}
static gboolean
draw_event(GtkWidget *widget _U_, cairo_t *cr, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
debug(DBS_FENTRY) puts("draw_event()");
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, 0, g->wp.y + g->wp.height, g->y_axis->p.width, g->x_axis->p.height);
cairo_fill(cr);
cairo_rectangle(cr, g->wp.x + g->wp.width, g->wp.y, RMARGIN_WIDTH, g->wp.height);
cairo_fill(cr);
graph_pixmap_display(g);
graph_title_pixmap_display(g);
axis_pixmap_display(g->x_axis);
axis_pixmap_display(g->y_axis);
return TRUE;
}
static gboolean expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
cairo_t *cr;
debug(DBS_FENTRY) puts("expose_event()");
if (event->count)
return TRUE;
cr = gdk_cairo_create(gtk_widget_get_window(widget));
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, 0, g->wp.y + g->wp.height, g->y_axis->p.width, g->x_axis->p.height);
cairo_fill(cr);
cairo_destroy(cr);
cr = NULL;
cr = gdk_cairo_create(gtk_widget_get_window(widget));
cairo_set_source_rgb(cr, 1, 1, 1);
cairo_rectangle(cr, g->wp.x + g->wp.width, g->wp.y, RMARGIN_WIDTH, g->wp.height);
cairo_fill(cr);
cairo_destroy(cr);
cr = NULL;
graph_pixmap_display(g);
graph_title_pixmap_display(g);
axis_pixmap_display(g->x_axis);
axis_pixmap_display(g->y_axis);
return TRUE;
}
static void
perform_zoom(struct gtk_rlc_graph *g, struct zoomfactor *zf,
int origin_x, int origin_y)
{
int cur_width = g->geom.width, cur_height = g->geom.height;
g->geom.width = (int )rint(g->geom.width * zf->x);
g->geom.height = (int )rint(g->geom.height * zf->y);
if ((g->geom.width <= g->wp.width) &&
(g->geom.height <= g->wp.height)) {
return;
}
if (g->geom.width < g->wp.width) {
g->geom.width = g->wp.width;
}
if (g->geom.height < g->wp.height) {
g->geom.height = g->wp.height;
}
g->zoom.x = (g->geom.width - 1) / g->bounds.width;
g->zoom.y = (g->geom.height- 1) / g->bounds.height;
g->geom.x -= (int)rint((g->geom.width - cur_width) *
((origin_x - g->geom.x)/(double )cur_width));
g->geom.y -= (int)rint((g->geom.height - cur_height) *
((origin_y - g->geom.y)/(double )cur_height));
if (g->geom.x > g->wp.x)
g->geom.x = g->wp.x;
if (g->geom.y > g->wp.y)
g->geom.y = g->wp.y;
if (g->wp.x + g->wp.width > g->geom.x + g->geom.width)
g->geom.x = g->wp.width + g->wp.x - g->geom.width;
if (g->wp.y + g->wp.height > g->geom.y + g->geom.height)
g->geom.y = g->wp.height + g->wp.y - g->geom.height;
}
static void
do_zoom_rectangle(struct gtk_rlc_graph *g, struct irect lcl_zoomrect)
{
int cur_width = g->wp.width, cur_height = g->wp.height;
struct irect geom1 = g->geom;
struct zoomfactor factor;
if (lcl_zoomrect.x > g->wp.x + g->wp.width)
return;
if (lcl_zoomrect.x + lcl_zoomrect.width < g->wp.x)
return;
if (lcl_zoomrect.x < g->wp.x) {
int dx = g->wp.x - lcl_zoomrect.x;
lcl_zoomrect.x += dx;
lcl_zoomrect.width -= dx;
}
if (lcl_zoomrect.x + lcl_zoomrect.width > g->wp.x + g->wp.width) {
int dx = lcl_zoomrect.width + lcl_zoomrect.x - g->wp.x - g->wp.width;
lcl_zoomrect.width -= dx;
}
if (lcl_zoomrect.y > g->wp.y + g->wp.height)
return;
if (lcl_zoomrect.y + lcl_zoomrect.height < g->wp.y)
return;
if (lcl_zoomrect.y < g->wp.y) {
int dy = g->wp.y - lcl_zoomrect.y;
lcl_zoomrect.y += dy;
lcl_zoomrect.height -= dy;
}
if (lcl_zoomrect.y + lcl_zoomrect.height > g->wp.y + g->wp.height) {
int dy = lcl_zoomrect.height + lcl_zoomrect.y - g->wp.y - g->wp.height;
lcl_zoomrect.height -= dy;
}
factor.x = (double)cur_width / lcl_zoomrect.width;
factor.y = (double)cur_height / lcl_zoomrect.height;
perform_zoom(g, &factor,
lcl_zoomrect.x, lcl_zoomrect.y);
g->geom.x = (int)(geom1.x * (1 + factor.x) -
lcl_zoomrect.x * factor.x - (geom1.x - g->wp.x));
g->geom.y = (int)(geom1.y * (1 + factor.y) -
lcl_zoomrect.y * factor.y - (geom1.y - g->wp.y));
graph_element_lists_make(g);
g->cross.erase_needed = FALSE;
graph_display(g);
axis_display(g->y_axis);
axis_display(g->x_axis);
}
static void do_zoom_common(struct gtk_rlc_graph *g, GdkEventButton *event,
gboolean lock_vertical, gboolean lock_horizontal)
{
int cur_width = g->geom.width, cur_height = g->geom.height;
struct { double x, y; } factor;
int pointer_x, pointer_y;
if (event == NULL) {
get_mouse_position(g->drawing_area, &pointer_x, &pointer_y, NULL);
}
else {
pointer_x = (int)event->x;
pointer_y = (int)event->y;
}
if (g->zoom.flags & ZOOM_OUT) {
if ((g->geom.height <= g->wp.height) &&
(g->geom.width <= g->wp.width)) {
return;
}
if (lock_horizontal) {
factor.x = 1.0;
}
else {
factor.x = 1 / g->zoom.step_x;
}
if (lock_vertical) {
factor.y = 1.0;
}
else {
factor.y = 1 / g->zoom.step_y;
}
} else {
if ((lock_horizontal) || (g->geom.width >= (g->bounds.width * MAX_PIXELS_PER_SECOND))) {
factor.x = 1.0;
}
else {
factor.x = g->zoom.step_x;
}
if (lock_vertical || (g->geom.height >= (g->bounds.height * MAX_PIXELS_PER_SN))) {
factor.y = 1.0;
}
else {
factor.y = g->zoom.step_y;
}
}
g->geom.width = (int )rint(g->geom.width * factor.x);
g->geom.height = (int )rint(g->geom.height * factor.y);
if (g->geom.width < g->wp.width)
g->geom.width = g->wp.width;
if (g->geom.height < g->wp.height)
g->geom.height = g->wp.height;
g->zoom.x = (g->geom.width - 1) / g->bounds.width;
g->zoom.y = (g->geom.height- 1) / g->bounds.height;
g->geom.x -= (int )rint((g->geom.width - cur_width) *
((pointer_x - g->geom.x)/(double)cur_width));
g->geom.y -= (int )rint((g->geom.height - cur_height) *
((pointer_y - g->geom.y)/(double)cur_height));
if (g->geom.x > g->wp.x)
g->geom.x = g->wp.x;
if (g->geom.y > g->wp.y)
g->geom.y = g->wp.y;
if (g->wp.x + g->wp.width > g->geom.x + g->geom.width)
g->geom.x = g->wp.width + g->wp.x - g->geom.width;
if (g->wp.y + g->wp.height > g->geom.y + g->geom.height)
g->geom.y = g->wp.height + g->wp.y - g->geom.height;
#if 0
printf("%s press: graph: (%d,%d), (%d,%d); viewport: (%d,%d), "
"(%d,%d); zooms: (%f,%f)\n",
(event != NULL) ? "mouse" : "key", g->geom.x, g->geom.y,
g->geom.width, g->geom.height, g->wp.x, g->wp.y, g->wp.width,
g->wp.height, g->zoom.x, g->zoom.y);
#endif
graph_element_lists_make(g);
graph_display(g);
axis_display(g->y_axis);
axis_display(g->x_axis);
if (g->cross.draw) {
g->cross.erase_needed = FALSE;
cross_draw(g, pointer_x, pointer_y);
}
}
static void do_zoom_keyboard(struct gtk_rlc_graph *g,
gboolean lock_vertical,
gboolean lock_horizontal)
{
do_zoom_common(g, NULL, lock_vertical, lock_horizontal);
}
static void do_zoom_mouse(struct gtk_rlc_graph *g, GdkEventButton *event)
{
do_zoom_common(g, event,
event->state & GDK_SHIFT_MASK,
event->state & GDK_CONTROL_MASK);
}
static void do_zoom_in_keyboard(struct gtk_rlc_graph *g,
gboolean lock_vertical,
gboolean lock_horizontal)
{
g->zoom.flags &= ~ZOOM_OUT;
do_zoom_keyboard(g, lock_vertical, lock_horizontal);
}
static void do_zoom_out_keyboard(struct gtk_rlc_graph *g,
gboolean lock_vertical,
gboolean lock_horizontal)
{
g->zoom.flags |= ZOOM_OUT;
do_zoom_keyboard(g, lock_vertical, lock_horizontal);
}
static void do_key_motion(struct gtk_rlc_graph *g)
{
if (g->geom.x > g->wp.x) {
g->geom.x = g->wp.x;
}
if (g->geom.y > g->wp.y) {
g->geom.y = g->wp.y;
}
if ((g->wp.x + g->wp.width) > (g->geom.x + g->geom.width)) {
g->geom.x = g->wp.width + g->wp.x - g->geom.width;
}
if ((g->wp.y + g->wp.height) > (g->geom.y + g->geom.height)) {
g->geom.y = g->wp.height + g->wp.y - g->geom.height;
}
graph_display(g);
axis_display(g->y_axis);
axis_display(g->x_axis);
if (g->cross.draw) {
int pointer_x, pointer_y;
get_mouse_position(g->drawing_area, &pointer_x, &pointer_y, NULL);
g->cross.erase_needed = FALSE;
cross_draw (g, pointer_x, pointer_y);
}
}
static void do_key_motion_up(struct gtk_rlc_graph *g, int step)
{
g->geom.y += step;
do_key_motion(g);
}
static void do_key_motion_down(struct gtk_rlc_graph *g, int step)
{
g->geom.y -= step;
do_key_motion(g);
}
static void do_key_motion_left(struct gtk_rlc_graph *g, int step)
{
g->geom.x += step;
do_key_motion(g);
}
static void do_key_motion_right(struct gtk_rlc_graph *g, int step)
{
g->geom.x -= step;
do_key_motion(g);
}
static gboolean button_press_event(GtkWidget *widget _U_, GdkEventButton *event, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
debug(DBS_FENTRY) puts("button_press_event()");
if (event->button == MOUSE_BUTTON_RIGHT) {
g->grab.x = (int )rint (event->x) - g->geom.x;
g->grab.y = (int )rint (event->y) - g->geom.y;
g->grab.grabbed = TRUE;
} else if (event->button == MOUSE_BUTTON_MIDDLE) {
do_zoom_mouse(g, event);
} else if (event->button == MOUSE_BUTTON_LEFT) {
graph_select_segment(g, (int)event->x, (int)event->y);
zoomrect.x = (int)event->x;
zoomrect.y = (int)event->y;
}
unset_busy_cursor(gtk_widget_get_window(g->drawing_area));
return TRUE;
}
static gboolean button_release_event(GtkWidget *widget _U_, GdkEventButton *event _U_, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
if (event->button == MOUSE_BUTTON_RIGHT) {
g->grab.grabbed = FALSE;
}
else if (event->button == MOUSE_BUTTON_LEFT) {
int xx1 = zoomrect.x;
int xx2 = (int)event->x;
int yy1 = zoomrect.y;
int yy2 = (int)event->y;
zoomrect.x = MIN(xx1, xx2);
zoomrect.width = abs(xx1 - xx2);
zoomrect.y = MIN(yy1, yy2);
zoomrect.height = abs(yy1 - yy2);
if ((zoomrect.width > 3) && (zoomrect.height > 3)) {
int oldflags = g->zoom.flags;
debug(DBS_GRAPH_DRAWING) printf("Zoom in from (%d, %d) - (%d, %d)\n",
zoomrect.x, zoomrect.y,
zoomrect.width, zoomrect.height);
g->zoom.flags &= ~ZOOM_OUT;
do_zoom_rectangle(g, zoomrect);
g->zoom.flags = oldflags;
}
}
return TRUE;
}
static gboolean motion_notify_event(GtkWidget *widget _U_, GdkEventMotion *event, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
int x, y;
GdkModifierType state;
if (event->is_hint)
get_mouse_position(g->drawing_area, &x, &y, &state);
else {
x = (int) event->x;
y = (int) event->y;
state = (GdkModifierType)event->state;
}
if (state & GDK_BUTTON3_MASK) {
if (g->grab.grabbed) {
g->geom.x = x-g->grab.x;
g->geom.y = y-g->grab.y;
if (g->geom.x > g->wp.x)
g->geom.x = g->wp.x;
if (g->geom.y > g->wp.y)
g->geom.y = g->wp.y;
if (g->wp.x + g->wp.width > g->geom.x + g->geom.width)
g->geom.x = g->wp.width + g->wp.x - g->geom.width;
if (g->wp.y + g->wp.height > g->geom.y + g->geom.height)
g->geom.y = g->wp.height + g->wp.y - g->geom.height;
g->cross.erase_needed = 0;
graph_display(g);
axis_display(g->y_axis);
axis_display(g->x_axis);
if (g->cross.draw) {
cross_draw(g, x, y);
}
}
}
else if (state & GDK_BUTTON1_MASK) {
if (g->zoomrect_erase_needed) {
zoomrect_erase(g);
}
zoomrect_draw(g, x, y);
}
else {
if (g->cross.erase_needed)
cross_erase(g);
if (g->cross.draw) {
cross_draw(g, x, y);
}
}
return TRUE;
}
static gboolean key_press_event(GtkWidget *widget _U_, GdkEventKey *event, gpointer user_data)
{
struct gtk_rlc_graph *g = (struct gtk_rlc_graph *)user_data;
int step;
debug(DBS_FENTRY) puts("key_press_event()");
if ((event->state & GDK_CONTROL_MASK) && (event->state & GDK_SHIFT_MASK)) {
step = 0;
}
else if (event->state & GDK_CONTROL_MASK) {
step = 1;
}
else if (event->state & GDK_SHIFT_MASK) {
step = 10;
}
else {
step = 100;
}
switch (event->keyval) {
case ' ':
toggle_crosshairs(g);
break;
case 't':
toggle_time_origin(g);
break;
case 'r':
case GDK_Home:
restore_initial_graph_view(g);
break;
case 'i':
case 'I':
do_zoom_in_keyboard(g,
event->state & GDK_SHIFT_MASK,
event->state & GDK_CONTROL_MASK);
break;
case '+':
do_zoom_in_keyboard(g,
FALSE,
event->state & GDK_CONTROL_MASK);
break;
case 'o':
case 'O':
do_zoom_out_keyboard(g,
event->state & GDK_SHIFT_MASK,
event->state & GDK_CONTROL_MASK);
break;
case '-':
do_zoom_out_keyboard(g,
FALSE,
event->state & GDK_CONTROL_MASK);
case GDK_Left:
do_key_motion_left(g, step);
break;
case GDK_Up:
do_key_motion_up(g, step);
break;
case GDK_Right:
do_key_motion_right(g, step);
break;
case GDK_Down:
do_key_motion_down(g, step);
break;
case GDK_Page_Up:
do_key_motion_up(g, 2000);
break;
case GDK_Page_Down:
do_key_motion_down(g, 2000);
break;
case GDK_F1:
callback_create_help(NULL, NULL);
break;
default:
break;
}
return TRUE;
}
static void toggle_crosshairs(struct gtk_rlc_graph *g)
{
g->cross.draw ^= 1;
if (g->cross.draw) {
int x, y;
get_mouse_position(g->drawing_area, &x, &y, NULL);
cross_draw(g, x, y);
} else if (g->cross.erase_needed) {
cross_erase(g);
}
}
static void cross_draw(struct gtk_rlc_graph *g, int x, int y)
{
if (g->cross.erase_needed && (g->cross.x == x) && (g->cross.y == y)) {
return;
}
if ((x > g->wp.x) && (x < g->wp.x+g->wp.width) &&
(y > g->wp.y) && (y < g->wp.y+g->wp.height)) {
cairo_t *cr = gdk_cairo_create(gtk_widget_get_window(g->drawing_area));
gdk_cairo_set_source_rgba(cr, &g->style.seq_color);
cairo_set_line_width(cr, 1.0);
cairo_move_to(cr, g->wp.x, y);
cairo_line_to(cr, g->wp.x + g->wp.width, y);
cairo_move_to(cr, x, g->wp.y);
cairo_line_to(cr, x, g->wp.y + g->wp.height);
cairo_stroke(cr);
cairo_destroy(cr);
}
g->cross.x = x;
g->cross.y = y;
g->cross.erase_needed = TRUE;
}
static void cross_erase(struct gtk_rlc_graph *g)
{
int x = g->cross.x;
int y = g->cross.y;
if ((x > g->wp.x) && (x < g->wp.x+g->wp.width) &&
(y >= g->wp.y) && (y < g->wp.y+g->wp.height)) {
graph_pixmap_display(g);
}
g->cross.erase_needed = FALSE;
}
static void zoomrect_draw(struct gtk_rlc_graph *g, int x, int y)
{
if ((zoomrect.x > g->wp.x) && (zoomrect.x < g->wp.x + g->wp.width) &&
(zoomrect.y > g->wp.y) && (zoomrect.y < g->wp.y + g->wp.height) &&
(x > g->wp.x + 0.5) && (x < g->wp.x+g->wp.width) &&
(y > g->wp.y) && (y < g->wp.y+g->wp.height)) {
cairo_t *cr = gdk_cairo_create(gtk_widget_get_window(g->drawing_area));
gdk_cairo_set_source_rgba(cr, &g->style.seq_color);
cairo_set_line_width(cr, 1.0);
cairo_rectangle(cr, zoomrect.x, zoomrect.y, x-zoomrect.x, y-zoomrect.y);
cairo_stroke(cr);
cairo_destroy(cr);
}
g->zoomrect_erase_needed = TRUE;
}
static void zoomrect_erase(struct gtk_rlc_graph *g)
{
graph_pixmap_display(g);
g->zoomrect_erase_needed = FALSE;
}
static void toggle_time_origin(struct gtk_rlc_graph *g)
{
g->style.flags ^= TIME_ORIGIN;
if ((g->style.flags & TIME_ORIGIN) == TIME_ORIGIN_CAP) {
g->x_axis->min = g->bounds.x0;
}
else {
g->x_axis->min = 0;
}
axis_display(g->x_axis);
}
static void restore_initial_graph_view(struct gtk_rlc_graph *g)
{
g->geom.width = g->wp.width;
g->geom.height = g->wp.height;
g->geom.x = g->wp.x;
g->geom.y = g->wp.y;
graph_init_sequence(g);
g->zoom.flags &= ~ZOOM_OUT;
if (g->cross.draw) {
g->cross.erase_needed = FALSE;
}
}
static void get_data_control_counts(struct gtk_rlc_graph *g, int *data, int *acks, int *nacks)
{
struct rlc_segment *tmp;
*data = 0;
*acks = 0;
*nacks = 0;
for (tmp=g->graph.segments; tmp; tmp=tmp->next) {
if (tmp->isControlPDU) {
(*acks)++;
(*nacks) += tmp->noOfNACKs;
}
else {
(*data)++;
}
}
}
static void graph_get_bounds(struct gtk_rlc_graph *g)
{
struct rlc_segment *tmp;
double tim;
gboolean data_frame_seen = FALSE;
double data_tim_low = 0;
double data_tim_high = 0;
guint32 data_seq_cur;
guint32 data_seq_low = 0;
guint32 data_seq_high = 0;
gboolean ack_frame_seen = FALSE;
double ack_tim_low = 0;
double ack_tim_high = 0;
guint32 ack_seq_cur;
guint32 ack_seq_low = 0;
guint32 ack_seq_high = 0;
for (tmp=g->graph.segments; tmp; tmp=tmp->next) {
if (!tmp->isControlPDU) {
tim = tmp->rel_secs + tmp->rel_usecs / 1000000.0;
data_seq_cur = tmp->SN;
#define A_FEW_SUBFRAMES 0.005
if (!data_frame_seen) {
data_tim_low = tim;
data_tim_high = tim + A_FEW_SUBFRAMES;
data_seq_low = data_seq_cur;
data_seq_high = data_seq_cur+1;
data_frame_seen = TRUE;
}
if (tim < data_tim_low) data_tim_low = tim;
if (tim+0.02 > data_tim_high) data_tim_high = tim + A_FEW_SUBFRAMES;
if (data_seq_cur < data_seq_low) data_seq_low = data_seq_cur;
if (data_seq_cur+1 > data_seq_high) data_seq_high = data_seq_cur+1;
}
else {
int n;
guint32 nack_seq_cur;
tim = tmp->rel_secs + tmp->rel_usecs / 1000000.0;
ack_seq_cur = tmp->ACKNo;
if (!ack_frame_seen) {
ack_tim_low = ack_tim_high = tim;
ack_seq_low = ack_seq_cur;
ack_seq_high = ack_seq_cur;
ack_frame_seen = TRUE;
}
if (tim < ack_tim_low) ack_tim_low = tim;
if (tim > ack_tim_high) ack_tim_high = tim;
if (ack_seq_cur < ack_seq_low) ack_seq_low = ack_seq_cur;
if (ack_seq_cur > ack_seq_high) ack_seq_high = ack_seq_cur;
for (n=0; n < tmp->noOfNACKs; n++) {
nack_seq_cur = tmp->NACKs[n];
if (nack_seq_cur < ack_seq_low) ack_seq_low = nack_seq_cur;
if (nack_seq_cur > ack_seq_high) ack_seq_high = nack_seq_cur;
}
}
}
g->bounds.x0 = (((data_tim_low <= ack_tim_low) && data_frame_seen) || (!ack_frame_seen)) ? data_tim_low : ack_tim_low;
g->bounds.width = ((((data_tim_high >= ack_tim_high) && data_frame_seen) || (!ack_frame_seen)) ? data_tim_high : ack_tim_high) - g->bounds.x0;
g->bounds.y0 = 0;
g->bounds.height = (((data_seq_high >= ack_seq_high) && data_frame_seen) || (!ack_frame_seen)) ? data_seq_high : ack_seq_high;
g->zoom.x = (g->geom.width - 1) / g->bounds.width;
g->zoom.y = (g->geom.height -1) / g->bounds.height;
}
static void graph_read_config(struct gtk_rlc_graph *g)
{
g->style.seq_color.red = (double)0 / 65535.0;
g->style.seq_color.green = (double)0 / 65535.0;
g->style.seq_color.blue = (double)0 / 65535.0;
g->style.seq_color.alpha = 1.0;
g->style.seq_resegmented_color.red = (double)0x7777 / 65535.0;
g->style.seq_resegmented_color.green = (double)0x7777 / 65535.0;
g->style.seq_resegmented_color.blue = (double)0x7777 / 65535.0;
g->style.seq_resegmented_color.alpha = 1.0;
g->style.ack_color[0].red = (double)0x2222 / 65535.0;
g->style.ack_color[0].green = (double)0x2222 / 65535.0;
g->style.ack_color[0].blue = (double)0xaaaa / 65535.0;
g->style.ack_color[0].alpha = 1.0;
g->style.ack_color[1].red = (double)0xaaaa / 65535.0;
g->style.ack_color[1].green = (double)0x2222 / 65535.0;
g->style.ack_color[1].blue = (double)0x2222 / 65535.0;
g->style.ack_color[1].alpha = 1.0;
g->style.flags = TIME_ORIGIN_CAP;
g->y_axis->label = (const char ** )g_malloc(3 * sizeof(char * ));
g->y_axis->label[0] = "Number";
g->y_axis->label[1] = "Sequence";
g->y_axis->label[2] = NULL;
g->x_axis->label = (const char ** )g_malloc(2 * sizeof(char * ));
g->x_axis->label[0] = "Time[s]";
g->x_axis->label[1] = NULL;
}
static void rlc_lte_make_elmtlist(struct gtk_rlc_graph *g)
{
struct rlc_segment *tmp;
struct element *elements0, *e0;
struct element *elements1, *e1;
struct rlc_segment *last_status_segment = NULL;
double xx0, yy0;
gboolean ack_seen = FALSE;
guint32 seq_base;
guint32 seq_cur;
int n, data, acks, nacks;
double previous_status_x = 0.0, previous_status_y = 0.0;
debug(DBS_FENTRY) puts("rlc_lte_make_elmtlist()");
if (g->graph.elists->elements == NULL) {
get_data_control_counts(g, &data, &acks, &nacks);
n = data + 1;
e0 = elements0 = (struct element *)g_malloc(n*sizeof(struct element));
n = (2*acks) + (4*nacks) + 2;
e1 = elements1 = (struct element *)g_malloc(n*sizeof(struct element));
g->graph.elists->next = (struct element_list *)g_malloc0(sizeof(struct element_list));
} else {
e0 = elements0 = g->graph.elists->elements;
e1 = elements1 = g->graph.elists->next->elements;
}
xx0 = g->bounds.x0;
yy0 = g->bounds.y0;
seq_base = (guint32) yy0;
for (tmp=g->graph.segments; tmp; tmp=tmp->next) {
double secs;
double x, y;
secs = tmp->rel_secs + (tmp->rel_usecs / 1000000.0);
x = secs - xx0;
x *= g->zoom.x;
if (!tmp->isControlPDU) {
seq_cur = tmp->SN - seq_base;
#define DATA_BLOB_SIZE 4
y = (g->zoom.y * seq_cur);
e0->type = ELMT_ELLIPSE;
e0->parent = tmp;
if (!tmp->isResegmented) {
e0->elment_color_p = &g->style.seq_color;
}
else {
e0->elment_color_p = &g->style.seq_resegmented_color;
}
e0->p.ellipse.dim.width = DATA_BLOB_SIZE;
e0->p.ellipse.dim.height = DATA_BLOB_SIZE;
e0->p.ellipse.dim.x = x;
e0->p.ellipse.dim.y = y;
e0++;
} else {
last_status_segment = tmp;
seq_cur = tmp->ACKNo - seq_base - 1;
y = (g->zoom.y * seq_cur);
if (ack_seen) {
if (y > previous_status_y) {
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[0];
e1->p.line.dim.x1 = previous_status_x;
e1->p.line.dim.y1 = previous_status_y;
e1->p.line.dim.x2 = x;
e1->p.line.dim.y2 = previous_status_y;
e1++;
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[0];
e1->p.line.dim.x1 = x;
e1->p.line.dim.y1 = previous_status_y;
e1->p.line.dim.x2 = x;
e1->p.line.dim.y2 = y;
e1++;
}
else {
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[0];
e1->p.line.dim.x1 = previous_status_x;
e1->p.line.dim.y1 = previous_status_y;
e1->p.line.dim.x2 = previous_status_x;
e1->p.line.dim.y2 = y;
e1++;
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[0];
e1->p.line.dim.x1 = previous_status_x;
e1->p.line.dim.y1 = y;
e1->p.line.dim.x2 = x;
e1->p.line.dim.y2 = y;
e1++;
}
}
if (tmp->noOfNACKs > 0) {
for (n=0; n < tmp->noOfNACKs; n++) {
double nack_y = (g->zoom.y * tmp->NACKs[n]);
#define NACK_CROSS_SIZE 3
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[1];
e1->p.line.dim.x1 = x -NACK_CROSS_SIZE;
e1->p.line.dim.y1 = nack_y - NACK_CROSS_SIZE;
e1->p.line.dim.x2 = x + NACK_CROSS_SIZE;
e1->p.line.dim.y2 = nack_y + NACK_CROSS_SIZE;
e1++;
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[1];
e1->p.line.dim.x1 = x - NACK_CROSS_SIZE;
e1->p.line.dim.y1 = nack_y + NACK_CROSS_SIZE;
e1->p.line.dim.x2 = x + NACK_CROSS_SIZE;
e1->p.line.dim.y2 = nack_y - NACK_CROSS_SIZE;
e1++;
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[1];
e1->p.line.dim.x1 = x;
e1->p.line.dim.y1 = nack_y + NACK_CROSS_SIZE;
e1->p.line.dim.x2 = x;
e1->p.line.dim.y2 = nack_y - NACK_CROSS_SIZE;
e1++;
e1->type = ELMT_LINE;
e1->parent = tmp;
e1->elment_color_p = &g->style.ack_color[1];
e1->p.line.dim.x1 = x - NACK_CROSS_SIZE;
e1->p.line.dim.y1 = nack_y;
e1->p.line.dim.x2 = x + NACK_CROSS_SIZE;
e1->p.line.dim.y2 = nack_y;
e1++;
}
}
ack_seen = TRUE;
previous_status_x = x;
previous_status_y = y;
}
}
if (ack_seen) {
e1->type = ELMT_LINE;
e1->parent = last_status_segment;
e1->elment_color_p = &g->style.ack_color[0];
e1->p.line.dim.x1 = previous_status_x;
e1->p.line.dim.y1 = previous_status_y;
e1->p.line.dim.x2 = g->bounds.width * g->zoom.x;
e1->p.line.dim.y2 = previous_status_y;
e1++;
}
e0->type = ELMT_NONE;
e1->type = ELMT_NONE;
g->graph.elists->elements = elements0;
g->graph.elists->next->elements = elements1;
}
static int rint(double x)
{
char *buf;
int i,dec,sig;
buf = _fcvt(x, 0, &dec, &sig);
i = atoi(buf);
if (sig == 1) {
i = i * -1;
}
return i;
}
