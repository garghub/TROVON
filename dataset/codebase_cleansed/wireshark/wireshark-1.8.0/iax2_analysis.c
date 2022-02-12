static void enable_graph(dialog_graph_graph_t *dgg)
{
dgg->display=TRUE;
}
static void
iax2_reset(void *user_data_arg)
{
user_data_t *user_data = user_data_arg;
user_data->forward.statinfo.first_packet = TRUE;
user_data->reversed.statinfo.first_packet = TRUE;
user_data->forward.statinfo.max_delta = 0;
user_data->reversed.statinfo.max_delta = 0;
user_data->forward.statinfo.max_jitter = 0;
user_data->reversed.statinfo.max_jitter = 0;
user_data->forward.statinfo.mean_jitter = 0;
user_data->reversed.statinfo.mean_jitter = 0;
user_data->forward.statinfo.delta = 0;
user_data->reversed.statinfo.delta = 0;
user_data->forward.statinfo.diff = 0;
user_data->reversed.statinfo.diff = 0;
user_data->forward.statinfo.jitter = 0;
user_data->reversed.statinfo.jitter = 0;
user_data->forward.statinfo.bandwidth = 0;
user_data->reversed.statinfo.bandwidth = 0;
user_data->forward.statinfo.total_bytes = 0;
user_data->reversed.statinfo.total_bytes = 0;
user_data->forward.statinfo.bw_start_index = 0;
user_data->reversed.statinfo.bw_start_index = 0;
user_data->forward.statinfo.bw_index = 0;
user_data->reversed.statinfo.bw_index = 0;
user_data->forward.statinfo.timestamp = 0;
user_data->reversed.statinfo.timestamp = 0;
user_data->forward.statinfo.max_nr = 0;
user_data->reversed.statinfo.max_nr = 0;
user_data->forward.statinfo.total_nr = 0;
user_data->reversed.statinfo.total_nr = 0;
user_data->forward.statinfo.sequence = 0;
user_data->reversed.statinfo.sequence = 0;
user_data->forward.statinfo.start_seq_nr = 0;
user_data->reversed.statinfo.start_seq_nr = 1;
user_data->forward.statinfo.stop_seq_nr = 0;
user_data->reversed.statinfo.stop_seq_nr = 0;
user_data->forward.statinfo.cycles = 0;
user_data->reversed.statinfo.cycles = 0;
user_data->forward.statinfo.under = FALSE;
user_data->reversed.statinfo.under = FALSE;
user_data->forward.statinfo.start_time = 0;
user_data->reversed.statinfo.start_time = 0;
user_data->forward.statinfo.time = 0;
user_data->reversed.statinfo.time = 0;
user_data->forward.statinfo.reg_pt = PT_UNDEFINED;
user_data->reversed.statinfo.reg_pt = PT_UNDEFINED;
user_data->forward.saveinfo.count = 0;
user_data->reversed.saveinfo.count = 0;
user_data->forward.saveinfo.saved = FALSE;
user_data->reversed.saveinfo.saved = FALSE;
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(user_data->dlg.list_fwd))));
gtk_list_store_clear(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(user_data->dlg.list_rev))));
dialog_graph_reset(user_data);
if (user_data->forward.saveinfo.fp != NULL)
fclose(user_data->forward.saveinfo.fp);
if (user_data->reversed.saveinfo.fp != NULL)
fclose(user_data->reversed.saveinfo.fp);
user_data->forward.saveinfo.fp = ws_fopen(user_data->f_tempname, "wb");
if (user_data->forward.saveinfo.fp == NULL)
user_data->forward.saveinfo.error_type = TAP_RTP_FILE_OPEN_ERROR;
user_data->reversed.saveinfo.fp = ws_fopen(user_data->r_tempname, "wb");
if (user_data->reversed.saveinfo.fp == NULL)
user_data->reversed.saveinfo.error_type = TAP_RTP_FILE_OPEN_ERROR;
return;
}
static gboolean iax2_packet_add_graph(dialog_graph_graph_t *dgg, tap_iax2_stat_t *statinfo, packet_info *pinfo, guint32 value)
{
dialog_graph_graph_item_t *it;
guint32 idx;
double rtp_time;
if(!dgg->display){
return FALSE;
}
dgg->ud->dlg.dialog_graph.needs_redraw=TRUE;
if (dgg->ud->dlg.dialog_graph.start_time == -1){
dgg->ud->dlg.dialog_graph.start_time = statinfo->start_time;
}
rtp_time = nstime_to_msec(&pinfo->fd->rel_ts) - dgg->ud->dlg.dialog_graph.start_time;
if(rtp_time<0){
return FALSE;
}
idx = (guint32)(rtp_time)/dgg->ud->dlg.dialog_graph.interval;
if(idx>=NUM_GRAPH_ITEMS){
return FALSE;
}
if(idx > dgg->ud->dlg.dialog_graph.num_items){
dgg->ud->dlg.dialog_graph.num_items=idx;
dgg->ud->dlg.dialog_graph.max_interval=idx*dgg->ud->dlg.dialog_graph.interval;
}
it=&dgg->items[idx];
if (value > it->value) {
it->value=value;
}
it->flags = it->flags | statinfo->flags;
return TRUE;
}
static void iax2_draw(void *prs _U_)
{
return;
}
static gboolean iax2_packet(void *user_data_arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *iax2info_arg)
{
user_data_t *user_data = user_data_arg;
const struct _iax2_info_t *iax2info = iax2info_arg;
if (pinfo->fd->flags.passed_dfilter == 0)
return FALSE;
if (iax2info->payload_len == 0)
return FALSE;
else if (CMP_ADDRESS(&(user_data->ip_src_fwd), &(pinfo->net_src)) == 0
&& user_data->port_src_fwd == pinfo->srcport
&& CMP_ADDRESS(&(user_data->ip_dst_fwd), &(pinfo->net_dst)) == 0
&& user_data->port_dst_fwd == pinfo->destport) {
iax2_packet_analyse(&(user_data->forward.statinfo), pinfo, iax2info);
iax2_packet_add_graph(&(user_data->dlg.dialog_graph.graph[GRAPH_FWD_JITTER]),
&(user_data->forward.statinfo),
pinfo,
(guint32)(user_data->forward.statinfo.jitter*1000000));
iax2_packet_add_graph(&(user_data->dlg.dialog_graph.graph[GRAPH_FWD_DIFF]),
&(user_data->forward.statinfo),
pinfo,
(guint32)(user_data->forward.statinfo.diff*1000000));
iax2_packet_add_info(user_data->dlg.list_fwd, user_data,
&(user_data->forward.statinfo), pinfo, iax2info);
iax2_packet_save_payload(&(user_data->forward.saveinfo),
&(user_data->forward.statinfo), pinfo, iax2info);
}
else if (CMP_ADDRESS(&(user_data->ip_src_rev), &(pinfo->net_src)) == 0
&& user_data->port_src_rev == pinfo->srcport
&& CMP_ADDRESS(&(user_data->ip_dst_rev), &(pinfo->net_dst)) == 0
&& user_data->port_dst_rev == pinfo->destport) {
iax2_packet_analyse(&(user_data->reversed.statinfo), pinfo, iax2info);
iax2_packet_add_graph(&(user_data->dlg.dialog_graph.graph[GRAPH_REV_JITTER]),
&(user_data->reversed.statinfo),
pinfo,
(guint32)(user_data->reversed.statinfo.jitter*1000000));
iax2_packet_add_graph(&(user_data->dlg.dialog_graph.graph[GRAPH_REV_DIFF]),
&(user_data->reversed.statinfo),
pinfo,
(guint32)(user_data->reversed.statinfo.diff*1000000));
iax2_packet_add_info(user_data->dlg.list_rev, user_data,
&(user_data->reversed.statinfo), pinfo, iax2info);
iax2_packet_save_payload(&(user_data->reversed.saveinfo),
&(user_data->reversed.statinfo), pinfo, iax2info);
}
return FALSE;
}
int iax2_packet_analyse(tap_iax2_stat_t *statinfo,
packet_info *pinfo,
const struct _iax2_info_t *iax2info)
{
double current_time;
double current_jitter;
double current_diff;
statinfo->flags = 0;
if (iax2info->ftype == AST_FRAME_VOICE) {
if (iax2info->csub != statinfo->pt)
statinfo->flags |= STAT_FLAG_PT_CHANGE;
statinfo->pt = iax2info->csub;
}
current_time = nstime_to_sec(&pinfo->fd->rel_ts);
current_diff = fabs (current_time - statinfo->time - (((double)iax2info->timestamp - (double)statinfo->timestamp)/1000));
current_jitter = statinfo->jitter + ( current_diff - statinfo->jitter)/16;
statinfo->delta = current_time-(statinfo->time);
statinfo->jitter = current_jitter;
statinfo->diff = current_diff;
statinfo->bw_history[statinfo->bw_index].bytes = iax2info->payload_len + 24;
statinfo->bw_history[statinfo->bw_index].time = current_time;
while ((statinfo->bw_history[statinfo->bw_start_index].time+1)<current_time){
statinfo->total_bytes -= statinfo->bw_history[statinfo->bw_start_index].bytes;
statinfo->bw_start_index++;
if (statinfo->bw_start_index == BUFF_BW) statinfo->bw_start_index=0;
};
statinfo->total_bytes += iax2info->payload_len + 24;
statinfo->bandwidth = (double)(statinfo->total_bytes*8)/1000;
statinfo->bw_index++;
if (statinfo->bw_index == BUFF_BW) statinfo->bw_index = 0;
if (statinfo->first_packet) {
statinfo->start_seq_nr = 0;
statinfo->start_time = current_time;
statinfo->delta = 0;
statinfo->jitter = 0;
statinfo->diff = 0;
statinfo->flags |= STAT_FLAG_FIRST;
statinfo->first_packet = FALSE;
}
if (!(statinfo->flags & STAT_FLAG_FIRST)
&& !(statinfo->flags & STAT_FLAG_MARKER)
&& !(statinfo->flags & STAT_FLAG_PT_CN)
&& !(statinfo->flags & STAT_FLAG_WRONG_TIMESTAMP)
&& !(statinfo->flags & STAT_FLAG_FOLLOW_PT_CN)) {
if (statinfo->delta > statinfo->max_delta) {
statinfo->max_delta = statinfo->delta;
statinfo->max_nr = pinfo->fd->num;
}
if (statinfo->jitter > statinfo->max_jitter) {
statinfo->max_jitter = statinfo->jitter;
}
statinfo->mean_jitter = (statinfo->mean_jitter*statinfo->total_nr + current_diff) / (statinfo->total_nr+1);
}
if (!(statinfo->flags & STAT_FLAG_FIRST)
&& !(statinfo->flags & STAT_FLAG_PT_CN)) {
if ((statinfo->pt != statinfo->reg_pt)
&& (statinfo->reg_pt != PT_UNDEFINED)) {
statinfo->flags |= STAT_FLAG_REG_PT_CHANGE;
}
}
if (!(statinfo->flags & STAT_FLAG_PT_CN)) {
statinfo->reg_pt = statinfo->pt;
}
statinfo->time = current_time;
statinfo->timestamp = iax2info->timestamp;
statinfo->stop_seq_nr = 0;
statinfo->total_nr++;
return 0;
}
static int iax2_packet_add_info(GtkWidget *list, user_data_t * user_data,
tap_iax2_stat_t *statinfo, packet_info *pinfo,
const struct _iax2_info_t *iax2info _U_)
{
guint16 msecs;
gchar timeStr[32];
struct tm *tm_tmp;
time_t then;
gchar status[40];
gchar color_str[14];
then = pinfo->fd->abs_ts.secs;
msecs = (guint16)(pinfo->fd->abs_ts.nsecs/1000000);
tm_tmp = localtime(&then);
g_snprintf(timeStr,sizeof(timeStr),"%02d/%02d/%04d %02d:%02d:%02d.%03d",
tm_tmp->tm_mon + 1,
tm_tmp->tm_mday,
tm_tmp->tm_year + 1900,
tm_tmp->tm_hour,
tm_tmp->tm_min,
tm_tmp->tm_sec,
msecs);
g_snprintf(color_str,sizeof(color_str),"#ffffffffffff");
if (statinfo->flags & STAT_FLAG_WRONG_SEQ) {
g_snprintf(status,sizeof(status),"Wrong sequence nr.");
g_snprintf(color_str,sizeof(color_str),"#ffffbfffbfff");
}
else if (statinfo->flags & STAT_FLAG_REG_PT_CHANGE) {
g_snprintf(status,sizeof(status),"Payload changed to PT=%u", statinfo->pt);
g_snprintf(color_str,sizeof(color_str),"#ffffdfffbfff");
}
else if (statinfo->flags & STAT_FLAG_WRONG_TIMESTAMP) {
g_snprintf(status,sizeof(status),"Incorrect timestamp");
g_snprintf(color_str,sizeof(color_str),"#ffffdfffbfff");
}
else if ((statinfo->flags & STAT_FLAG_PT_CHANGE)
&& !(statinfo->flags & STAT_FLAG_FIRST)
&& !(statinfo->flags & STAT_FLAG_PT_CN)
&& (statinfo->flags & STAT_FLAG_FOLLOW_PT_CN)
&& !(statinfo->flags & STAT_FLAG_MARKER)) {
g_snprintf(status,sizeof(status),"Marker missing?");
g_snprintf(color_str,sizeof(color_str),"#ffffdfffbfff");
}
else {
if (statinfo->flags & STAT_FLAG_MARKER) {
g_snprintf(color_str,sizeof(color_str),"#ffffdfffbfff");
}
g_snprintf(status,sizeof(status),OK_TEXT);
}
if (statinfo->flags & STAT_FLAG_FIRST) {
add_to_list(list, user_data,
pinfo->fd->num,
0,
0,
statinfo->bandwidth,
status,
timeStr, pinfo->fd->pkt_len,
color_str,
statinfo->flags);
}
else {
add_to_list(list, user_data,
pinfo->fd->num,
statinfo->delta*1000,
statinfo->jitter*1000,
statinfo->bandwidth,
status,
timeStr, pinfo->fd->pkt_len,
color_str,
statinfo->flags);
}
return 0;
}
static void iax2_packet_save_payload(tap_iax2_save_info_t *saveinfo,
tap_iax2_stat_t *statinfo,
packet_info *pinfo,
const struct _iax2_info_t *iax2info)
{
const guint8 *data;
size_t nchars;
if (statinfo->flags & STAT_FLAG_FIRST) {
if (saveinfo->fp == NULL) {
saveinfo->saved = FALSE;
saveinfo->error_type = TAP_RTP_FILE_OPEN_ERROR;
}
else
saveinfo->saved = TRUE;
}
if (saveinfo->saved == FALSE)
return;
if (pinfo->fd->pkt_len != pinfo->fd->cap_len) {
saveinfo->saved = FALSE;
saveinfo->error_type = TAP_RTP_WRONG_LENGTH;
return;
}
if (iax2info->payload_len > 0) {
data = iax2info->payload_data;
nchars = fwrite(data, sizeof(unsigned char), iax2info->payload_len, saveinfo->fp);
if (nchars != iax2info->payload_len) {
saveinfo->saved = FALSE;
saveinfo->error_type = TAP_RTP_FILE_WRITE_ERROR;
return;
}
saveinfo->count+=iax2info->payload_len;
if (fflush(saveinfo->fp) == EOF) {
saveinfo->saved = FALSE;
saveinfo->error_type = TAP_RTP_FILE_WRITE_ERROR;
return;
}
saveinfo->saved = TRUE;
return;
}
return;
}
static void on_iax2_window_destroy(GtkWidget *win _U_, gpointer data)
{
user_data_t *user_data = data;
protect_thread_critical_region();
remove_tap_listener(user_data);
unprotect_thread_critical_region();
if (user_data->forward.saveinfo.fp != NULL)
fclose(user_data->forward.saveinfo.fp);
if (user_data->reversed.saveinfo.fp != NULL)
fclose(user_data->reversed.saveinfo.fp);
ws_remove(user_data->f_tempname);
ws_remove(user_data->r_tempname);
#if 0
if (user_data->dlg.save_csv_as_w != NULL)
window_destroy(user_data->dlg.save_csv_as_w);
if (user_data->dlg.save_voice_as_w != NULL)
window_destroy(user_data->dlg.save_voice_as_w);
#endif
if (user_data->dlg.dialog_graph.window != NULL)
window_destroy(user_data->dlg.dialog_graph.window);
g_signal_handler_disconnect(user_data->dlg.notebook, user_data->dlg.notebook_signal_id);
g_free(user_data->f_tempname);
g_free(user_data->r_tempname);
g_free(user_data);
}
static void on_notebook_switch_page(GtkNotebook *notebook _U_,
gpointer *page _U_,
gint page_num,
gpointer data)
{
user_data_t *user_data = data;
user_data->dlg.selected_list =
(page_num==0) ? user_data->dlg.list_fwd : user_data->dlg.list_rev ;
user_data->dlg.selected_list_row = 0;
}
static void on_list_select_row(GtkTreeSelection *selection,
gpointer data)
{
user_data_t *user_data = data;
user_data->dlg.selected_list_sel = selection;
}
static void dialog_graph_set_title(user_data_t* user_data)
{
char *title;
if (!user_data->dlg.dialog_graph.window){
return;
}
title = g_strdup_printf("IAX2 Graph Analysis Forward: %s:%u to %s:%u Reverse: %s:%u to %s:%u",
get_addr_name(&(user_data->ip_src_fwd)),
user_data->port_src_fwd,
get_addr_name(&(user_data->ip_dst_fwd)),
user_data->port_dst_fwd,
get_addr_name(&(user_data->ip_src_rev)),
user_data->port_src_rev,
get_addr_name(&(user_data->ip_dst_rev)),
user_data->port_dst_rev);
gtk_window_set_title(GTK_WINDOW(user_data->dlg.dialog_graph.window), title);
g_free(title);
}
static void dialog_graph_reset(user_data_t* user_data)
{
int i, j;
user_data->dlg.dialog_graph.needs_redraw=TRUE;
for(i=0;i<MAX_GRAPHS;i++){
for(j=0;j<NUM_GRAPH_ITEMS;j++){
dialog_graph_graph_item_t *dggi;
dggi=&user_data->dlg.dialog_graph.graph[i].items[j];
dggi->value=0;
dggi->flags=0;
}
}
user_data->dlg.dialog_graph.last_interval=0xffffffff;
user_data->dlg.dialog_graph.max_interval=0;
user_data->dlg.dialog_graph.num_items=0;
for(i=0;i<MAX_GRAPHS;i++){
if (i<2){
g_snprintf(user_data->dlg.dialog_graph.graph[i].title,
sizeof (user_data->dlg.dialog_graph.graph[0].title),
"%s: %s:%u to %s:%u",
graph_descr[i],
get_addr_name(&(user_data->ip_src_fwd)),
user_data->port_src_fwd,
get_addr_name(&(user_data->ip_dst_fwd)),
user_data->port_dst_fwd);
} else {
g_snprintf(user_data->dlg.dialog_graph.graph[i].title,
sizeof(user_data->dlg.dialog_graph.graph[0].title),
"%s: %s:%u to %s:%u",
graph_descr[i],
get_addr_name(&(user_data->ip_src_rev)),
user_data->port_src_rev,
get_addr_name(&(user_data->ip_dst_rev)),
user_data->port_dst_rev);
}
}
dialog_graph_set_title(user_data);
}
static guint32 get_it_value(dialog_graph_graph_t *dgg, int idx)
{
dialog_graph_graph_item_t *it;
it=&dgg->items[idx];
return it->value;
}
static void print_time_scale_string(char *buf, int buf_len, guint32 t)
{
if(t>=10000000){
g_snprintf(buf, buf_len, "%ds",t/1000000);
} else if(t>=1000000){
g_snprintf(buf, buf_len, "%d.%03ds",t/1000000,(t%1000000)/1000);
} else if(t>=10000){
g_snprintf(buf, buf_len, "%dms",t/1000);
} else if(t>=1000){
g_snprintf(buf, buf_len, "%d.%03dms",t/1000,t%1000);
} else {
g_snprintf(buf, buf_len, "%dus",t);
}
}
static void dialog_graph_draw(user_data_t* user_data)
{
int i, lwidth;
guint32 last_interval, first_interval, interval_delta, delta_multiplier;
gint32 current_interval;
guint32 left_x_border;
guint32 right_x_border;
guint32 top_y_border;
guint32 bottom_y_border;
PangoLayout *layout;
int label_width, label_height;
int label_width_mid, label_height_mid;
guint32 draw_width, draw_height;
char label_string[15];
GtkAllocation widget_alloc;
cairo_t *cr;
guint32 num_time_intervals;
guint32 max_value;
guint32 max_y;
if(!user_data->dlg.dialog_graph.needs_redraw){
return;
}
user_data->dlg.dialog_graph.needs_redraw=FALSE;
num_time_intervals=user_data->dlg.dialog_graph.num_items;
if(num_time_intervals==0){
return;
}
num_time_intervals+=1;
if(num_time_intervals>NUM_GRAPH_ITEMS){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "IAX2 Graph error. There are too many entries, bailing out");
return;
}
max_value=0;
for(i=0;i<MAX_GRAPHS;i++){
int idx;
if(!user_data->dlg.dialog_graph.graph[i].display){
continue;
}
for(idx=0;(guint32) (idx) < num_time_intervals;idx++){
guint32 val;
val=get_it_value(&user_data->dlg.dialog_graph.graph[i], idx);
if(val>max_value){
max_value=val;
}
}
}
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_set_source_rgb (cr, 1, 1, 1);
gtk_widget_get_allocation(user_data->dlg.dialog_graph.draw_area, &widget_alloc);
cairo_rectangle (cr,
0,
0,
widget_alloc.width,
widget_alloc.height);
cairo_fill (cr);
cairo_destroy (cr);
if(user_data->dlg.dialog_graph.max_y_units==AUTO_MAX_YSCALE){
max_y=yscale_max[MAX_YSCALE-1];
for(i=MAX_YSCALE-1;i>0;i--){
if(max_value<yscale_max[i]){
max_y=yscale_max[i];
}
}
} else {
max_y=user_data->dlg.dialog_graph.max_y_units;
}
print_time_scale_string(label_string, sizeof(label_string), max_y);
layout = gtk_widget_create_pango_layout(user_data->dlg.dialog_graph.draw_area, label_string);
pango_layout_get_pixel_size(layout, &label_width, &label_height);
print_time_scale_string(label_string, sizeof(label_string), max_y*5/10);
layout = gtk_widget_create_pango_layout(user_data->dlg.dialog_graph.draw_area, label_string);
pango_layout_get_pixel_size(layout, &label_width_mid, &label_height_mid);
if (label_width_mid > label_width) {
label_width = label_width_mid;
label_height = label_height_mid;
}
left_x_border=10;
right_x_border=label_width+20;
top_y_border=10;
bottom_y_border=label_height+20;
draw_width=user_data->dlg.dialog_graph.surface_width-right_x_border-left_x_border;
draw_height=user_data->dlg.dialog_graph.surface_height-top_y_border-bottom_y_border;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, user_data->dlg.dialog_graph.surface_width-right_x_border+1.5, top_y_border+0.5);
cairo_line_to(cr, user_data->dlg.dialog_graph.surface_width-right_x_border+1.5, user_data->dlg.dialog_graph.surface_height-bottom_y_border+0.5);
cairo_stroke(cr);
cairo_destroy(cr);
for(i=0;i<=10;i++){
int xwidth;
xwidth=5;
if(!(i%5)){
xwidth=10;
}
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+1.5,
user_data->dlg.dialog_graph.surface_height-bottom_y_border-draw_height*i/10+0.5);
cairo_line_to(cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+1.5+xwidth,
user_data->dlg.dialog_graph.surface_height-bottom_y_border-draw_height*i/10+0.5);
cairo_stroke(cr);
cairo_destroy(cr);
if(i==0){
print_time_scale_string(label_string, sizeof(label_string), (max_y*i/10));
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+15+label_width-lwidth,
user_data->dlg.dialog_graph.surface_height-bottom_y_border-draw_height*i/10-label_height/2);
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
}
if(i==5){
print_time_scale_string(label_string, sizeof(label_string), (max_y*i/10));
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+15+label_width-lwidth,
user_data->dlg.dialog_graph.surface_height-bottom_y_border-draw_height*i/10-label_height/2);
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
}
if(i==10){
print_time_scale_string(label_string, sizeof(label_string), (max_y*i/10));
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+15+label_width-lwidth,
user_data->dlg.dialog_graph.surface_height-bottom_y_border-draw_height*i/10-label_height/2);
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
}
}
if(user_data->dlg.dialog_graph.last_interval==0xffffffff){
last_interval=user_data->dlg.dialog_graph.max_interval;
} else {
last_interval=user_data->dlg.dialog_graph.last_interval;
}
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, left_x_border+0.5, user_data->dlg.dialog_graph.surface_height-bottom_y_border+1.5);
cairo_line_to(cr, user_data->dlg.dialog_graph.surface_width-right_x_border+1.5,user_data->dlg.dialog_graph.surface_height-bottom_y_border+1.5);
cairo_stroke(cr);
cairo_destroy(cr);
if((last_interval/user_data->dlg.dialog_graph.interval)>draw_width/user_data->dlg.dialog_graph.pixels_per_tick+1){
first_interval=(last_interval/user_data->dlg.dialog_graph.interval)-draw_width/user_data->dlg.dialog_graph.pixels_per_tick+1;
first_interval*=user_data->dlg.dialog_graph.interval;
} else {
first_interval=0;
}
interval_delta=1;
delta_multiplier=5;
while(interval_delta<((last_interval-first_interval)/10)){
interval_delta*=delta_multiplier;
if(delta_multiplier==5){
delta_multiplier=2;
} else {
delta_multiplier=5;
}
}
for(current_interval=last_interval;current_interval>(gint32)first_interval;current_interval=current_interval-user_data->dlg.dialog_graph.interval){
int x, xlen;
if((user_data->dlg.dialog_graph.pixels_per_tick<10) && (current_interval%(10*user_data->dlg.dialog_graph.interval))){
continue;
}
if(current_interval%interval_delta){
xlen=5;
} else {
xlen=17;
}
x=draw_width+left_x_border-((last_interval-current_interval)/user_data->dlg.dialog_graph.interval)*user_data->dlg.dialog_graph.pixels_per_tick;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, x-1-user_data->dlg.dialog_graph.pixels_per_tick/2+0.5, user_data->dlg.dialog_graph.surface_height-bottom_y_border+1.5);
cairo_line_to(cr, x-1-user_data->dlg.dialog_graph.pixels_per_tick/2+0.5, user_data->dlg.dialog_graph.surface_height-bottom_y_border+xlen+1.5);
cairo_stroke(cr);
cairo_destroy(cr);
if(xlen==17){
if(user_data->dlg.dialog_graph.interval>=1000){
g_snprintf(label_string, sizeof(label_string), "%ds", current_interval/1000);
} else if(user_data->dlg.dialog_graph.interval>=100){
g_snprintf(label_string, sizeof(label_string),
"%d.%1ds", current_interval/1000,(current_interval/100)%10);
} else if(user_data->dlg.dialog_graph.interval>=10){
g_snprintf(label_string, sizeof(label_string),
"%d.%2ds", current_interval/1000,(current_interval/10)%100);
} else {
g_snprintf(label_string, sizeof(label_string),
"%d.%3ds", current_interval/1000,current_interval%1000);
}
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
x-1-user_data->dlg.dialog_graph.pixels_per_tick/2-lwidth/2,
user_data->dlg.dialog_graph.surface_height-bottom_y_border+20);
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
}
}
g_strlcpy(label_string, UTF8_LEFTWARDS_ARROW "Fwd",sizeof(label_string));
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+33-lwidth,
user_data->dlg.dialog_graph.surface_height-bottom_y_border+3);
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
g_strlcpy(label_string, UTF8_LEFTWARDS_ARROW "Rev",sizeof(label_string));
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
user_data->dlg.dialog_graph.surface_width-right_x_border+33-lwidth,
user_data->dlg.dialog_graph.surface_height-bottom_y_border+3+9);
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
for(i=MAX_GRAPHS-1;i>=0;i--){
guint32 interval;
guint32 x_pos;
if (!user_data->dlg.dialog_graph.graph[i].display){
continue;
}
for(interval=first_interval+user_data->dlg.dialog_graph.interval;interval<=last_interval;interval+=user_data->dlg.dialog_graph.interval){
x_pos=draw_width-1-user_data->dlg.dialog_graph.pixels_per_tick*((last_interval-interval)/user_data->dlg.dialog_graph.interval+1)+left_x_border;
if(user_data->dlg.dialog_graph.graph[i].items[interval/user_data->dlg.dialog_graph.interval].flags & (STAT_FLAG_WRONG_SEQ|STAT_FLAG_MARKER)){
if (user_data->dlg.dialog_graph.graph[i].items[interval/user_data->dlg.dialog_graph.interval].flags & STAT_FLAG_WRONG_SEQ){
g_strlcpy(label_string, "x", sizeof(label_string));
} else {
g_strlcpy(label_string, "m", sizeof(label_string));
}
pango_layout_set_text(layout, label_string, -1);
pango_layout_get_pixel_size(layout, &lwidth, NULL);
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_move_to (cr,
x_pos-1-lwidth/2,
user_data->dlg.dialog_graph.surface_height-bottom_y_border+3+7*(i/2));
pango_cairo_show_layout (cr, layout);
cairo_destroy (cr);
cr = NULL;
}
}
}
g_object_unref(G_OBJECT(layout));
for(i=MAX_GRAPHS-1;i>=0;i--){
guint32 interval;
guint32 x_pos, y_pos, prev_y_pos;
if (!user_data->dlg.dialog_graph.graph[i].display){
continue;
}
prev_y_pos=draw_height-1+top_y_border;
for(interval=first_interval+user_data->dlg.dialog_graph.interval;interval<=last_interval;interval+=user_data->dlg.dialog_graph.interval){
guint32 val;
x_pos=draw_width-1-user_data->dlg.dialog_graph.pixels_per_tick*((last_interval-interval)/user_data->dlg.dialog_graph.interval+1)+left_x_border;
val=get_it_value(&user_data->dlg.dialog_graph.graph[i], interval/user_data->dlg.dialog_graph.interval);
if(val>max_y){
y_pos=0;
} else {
y_pos=draw_height-1-(val*draw_height)/max_y+top_y_border;
}
if( (prev_y_pos==0) && (y_pos==0) ){
prev_y_pos=y_pos;
continue;
}
if(val){
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
gdk_cairo_set_source_color (cr, &user_data->dlg.dialog_graph.graph[i].color);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, x_pos+0.5, draw_height-1+top_y_border+0.5);
cairo_line_to(cr, x_pos+0.5, y_pos+0.5);
cairo_stroke(cr);
cairo_destroy(cr);
}
prev_y_pos=y_pos;
}
}
cr = gdk_cairo_create (gtk_widget_get_window(user_data->dlg.dialog_graph.draw_area));
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface (cr, user_data->dlg.dialog_graph.surface, 0, 0);
#else
gdk_cairo_set_source_pixmap (cr, user_data->dlg.dialog_graph.pixmap, 0, 0);
#endif
cairo_rectangle (cr, 0, 0, user_data->dlg.dialog_graph.surface_width, user_data->dlg.dialog_graph.surface_height);
cairo_fill (cr);
cairo_destroy (cr);
gtk_adjustment_set_upper(user_data->dlg.dialog_graph.scrollbar_adjustment, (gfloat) user_data->dlg.dialog_graph.max_interval);
gtk_adjustment_set_step_increment(user_data->dlg.dialog_graph.scrollbar_adjustment, (gfloat) ((last_interval-first_interval)/10));
gtk_adjustment_set_page_increment(user_data->dlg.dialog_graph.scrollbar_adjustment, (gfloat) (last_interval-first_interval));
if((last_interval-first_interval)*100 < user_data->dlg.dialog_graph.max_interval){
gtk_adjustment_set_page_size(user_data->dlg.dialog_graph.scrollbar_adjustment, (gfloat) (user_data->dlg.dialog_graph.max_interval/100));
} else {
gtk_adjustment_set_page_size(user_data->dlg.dialog_graph.scrollbar_adjustment, (gfloat) (last_interval-first_interval));
}
gtk_adjustment_set_value(user_data->dlg.dialog_graph.scrollbar_adjustment, last_interval - gtk_adjustment_get_page_size(user_data->dlg.dialog_graph.scrollbar_adjustment));
gtk_adjustment_changed(user_data->dlg.dialog_graph.scrollbar_adjustment);
gtk_adjustment_value_changed(user_data->dlg.dialog_graph.scrollbar_adjustment);
}
static void dialog_graph_redraw(user_data_t* user_data)
{
user_data->dlg.dialog_graph.needs_redraw=TRUE;
dialog_graph_draw(user_data);
}
static void draw_area_destroy_cb(GtkWidget *widget _U_, gpointer data)
{
user_data_t *user_data = data;
user_data->dlg.dialog_graph.window = NULL;
}
static gboolean draw_area_draw(GtkWidget *widget, cairo_t *cr, gpointer data)
{
user_data_t *user_data = data;
GtkAllocation allocation;
gtk_widget_get_allocation (widget, &allocation);
cairo_set_source_surface (cr, user_data->dlg.dialog_graph.surface, 0, 0);
cairo_rectangle (cr, 0, 0, allocation.width, allocation.height);
cairo_fill (cr);
return FALSE;
}
static gboolean draw_area_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
user_data_t *user_data = data;
cairo_t *cr = gdk_cairo_create (gtk_widget_get_window(widget));
#if GTK_CHECK_VERSION(2,22,0)
cairo_set_source_surface (cr, user_data->dlg.dialog_graph.surface, 0, 0);
#else
gdk_cairo_set_source_pixmap (cr, user_data->dlg.dialog_graph.pixmap, 0, 0);
#endif
cairo_rectangle (cr, event->area.x, event->area.y, event->area.width, event->area.height);
cairo_fill (cr);
cairo_destroy (cr);
return FALSE;
}
static gboolean draw_area_configure_event(GtkWidget *widget, GdkEventConfigure *event _U_, gpointer data)
{
user_data_t *user_data = data;
GtkAllocation widget_alloc;
cairo_t *cr;
#if GTK_CHECK_VERSION(2,22,0)
if(user_data->dlg.dialog_graph.surface){
g_object_unref(user_data->dlg.dialog_graph.surface);
user_data->dlg.dialog_graph.surface=NULL;
}
gtk_widget_get_allocation(widget, &widget_alloc);
user_data->dlg.dialog_graph.surface = gdk_window_create_similar_surface (gtk_widget_get_window(widget),
CAIRO_CONTENT_COLOR,
widget_alloc.width,
widget_alloc.height);
#else
if(user_data->dlg.dialog_graph.pixmap){
g_object_unref(user_data->dlg.dialog_graph.pixmap);
user_data->dlg.dialog_graph.pixmap=NULL;
}
gtk_widget_get_allocation(widget, &widget_alloc);
user_data->dlg.dialog_graph.pixmap=gdk_pixmap_new(gtk_widget_get_window(widget),
widget_alloc.width,
widget_alloc.height,
-1);
#endif
user_data->dlg.dialog_graph.surface_width=widget_alloc.width;
user_data->dlg.dialog_graph.surface_height=widget_alloc.height;
#if GTK_CHECK_VERSION(2,22,0)
cr = cairo_create (user_data->dlg.dialog_graph.surface);
#else
cr = gdk_cairo_create (user_data->dlg.dialog_graph.pixmap);
#endif
cairo_rectangle (cr, 0, 0, widget_alloc.width, widget_alloc.height);
cairo_set_source_rgb (cr, 1, 1, 1);
cairo_fill (cr);
cairo_destroy (cr);
dialog_graph_redraw(user_data);
return TRUE;
}
static void scrollbar_changed(GtkWidget *widget _U_, gpointer data)
{
user_data_t *user_data = data;
guint32 mi;
mi=(guint32) (gtk_adjustment_get_value(user_data->dlg.dialog_graph.scrollbar_adjustment) + gtk_adjustment_get_page_size(user_data->dlg.dialog_graph.scrollbar_adjustment));
if(user_data->dlg.dialog_graph.last_interval==mi){
return;
}
if( (user_data->dlg.dialog_graph.last_interval==0xffffffff)
&& (mi==user_data->dlg.dialog_graph.max_interval) ){
return;
}
user_data->dlg.dialog_graph.last_interval=(mi/user_data->dlg.dialog_graph.interval)*user_data->dlg.dialog_graph.interval;
dialog_graph_redraw(user_data);
return;
}
static void create_draw_area(user_data_t* user_data, GtkWidget *box)
{
user_data->dlg.dialog_graph.draw_area=gtk_drawing_area_new();
g_signal_connect(user_data->dlg.dialog_graph.draw_area, "destroy", G_CALLBACK(draw_area_destroy_cb), user_data);
gtk_widget_set_size_request(user_data->dlg.dialog_graph.draw_area, user_data->dlg.dialog_graph.surface_width, user_data->dlg.dialog_graph.surface_height);
#if GTK_CHECK_VERSION(3,0,0)
g_signal_connect(user_data->dlg.dialog_graph.draw_area, "draw", G_CALLBACK(draw_area_draw), user_data);
#else
g_signal_connect(user_data->dlg.dialog_graph.draw_area, "expose_event", G_CALLBACK(draw_area_expose_event), user_data);
#endif
g_signal_connect(user_data->dlg.dialog_graph.draw_area, "configure_event", G_CALLBACK(draw_area_configure_event), user_data);
gtk_widget_show(user_data->dlg.dialog_graph.draw_area);
gtk_box_pack_start(GTK_BOX(box), user_data->dlg.dialog_graph.draw_area, TRUE, TRUE, 0);
user_data->dlg.dialog_graph.scrollbar_adjustment=(GtkAdjustment *)gtk_adjustment_new(0,0,0,0,0,0);
user_data->dlg.dialog_graph.scrollbar=gtk_scrollbar_new(GTK_ORIENTATION_HORIZONTAL,user_data->dlg.dialog_graph.scrollbar_adjustment);
gtk_widget_show(user_data->dlg.dialog_graph.scrollbar);
gtk_box_pack_start(GTK_BOX(box), user_data->dlg.dialog_graph.scrollbar, FALSE, FALSE, 0);
g_signal_connect(user_data->dlg.dialog_graph.scrollbar_adjustment, "value_changed", G_CALLBACK(scrollbar_changed), user_data);
}
static void disable_graph(dialog_graph_graph_t *dgg)
{
if (dgg->display) {
dgg->display=FALSE;
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dgg->display_button),
FALSE);
}
}
static void filter_box_display_button_cb(GtkWidget *widget _U_, gpointer data)
{
dialog_graph_graph_t *dgg = data;
if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(dgg->display_button))){
disable_graph(dgg);
dialog_graph_redraw(dgg->ud);
return;
}
enable_graph(dgg);
cf_retap_packets(&cfile);
dialog_graph_redraw(dgg->ud);
return;
}
static void create_filter_box(dialog_graph_graph_t *dgg, GtkWidget *box, int num)
{
GtkWidget *hbox;
GtkWidget *label;
char str[256];
hbox=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(box), hbox);
gtk_box_set_child_packing(GTK_BOX(box), hbox, FALSE, FALSE, 0, GTK_PACK_START);
gtk_widget_show(hbox);
g_snprintf(str, sizeof(str), "Graph %d", num);
dgg->display_button=gtk_toggle_button_new_with_label(str);
gtk_box_pack_start(GTK_BOX(hbox), dgg->display_button, FALSE, FALSE, 0);
gtk_widget_show(dgg->display_button);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dgg->display_button), dgg->display);
g_signal_connect(dgg->display_button, "toggled", G_CALLBACK(filter_box_display_button_cb), dgg);
label=gtk_label_new(dgg->title);
gtk_widget_show(label);
gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_color(label, GTK_STATE_NORMAL, &dgg->rgba_color);
gtk_widget_override_color(label, GTK_STATE_ACTIVE, &dgg->rgba_color);
gtk_widget_override_color(label, GTK_STATE_PRELIGHT, &dgg->rgba_color);
gtk_widget_override_color(label, GTK_STATE_SELECTED, &dgg->rgba_color);
gtk_widget_override_color(label, GTK_STATE_INSENSITIVE, &dgg->rgba_color);
#else
gtk_widget_modify_fg(label, GTK_STATE_NORMAL, &dgg->color);
gtk_widget_modify_fg(label, GTK_STATE_ACTIVE, &dgg->color);
gtk_widget_modify_fg(label, GTK_STATE_PRELIGHT, &dgg->color);
gtk_widget_modify_fg(label, GTK_STATE_SELECTED, &dgg->color);
gtk_widget_modify_fg(label, GTK_STATE_INSENSITIVE, &dgg->color);
#endif
return;
}
static void create_filter_area(user_data_t* user_data, GtkWidget *box)
{
GtkWidget *frame;
GtkWidget *vbox;
int i;
GtkWidget *label;
frame=gtk_frame_new("Graphs");
gtk_container_add(GTK_CONTAINER(box), frame);
gtk_widget_show(frame);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
gtk_container_add(GTK_CONTAINER(frame), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 3);
gtk_box_set_child_packing(GTK_BOX(box), vbox, FALSE, FALSE, 0, GTK_PACK_START);
gtk_widget_show(vbox);
for(i=0;i<MAX_GRAPHS;i++){
create_filter_box(&user_data->dlg.dialog_graph.graph[i], vbox, i+1);
}
label=gtk_label_new("Label: x = Wrong Seq. number m = Mark set");
gtk_widget_show(label);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
return;
}
static void yscale_select(GtkWidget *item, gpointer data)
{
user_data_t *user_data = data;
int i;
i = gtk_combo_box_get_active (GTK_COMBO_BOX(item));
user_data->dlg.dialog_graph.max_y_units_index=i;
user_data->dlg.dialog_graph.max_y_units=yscale_max[i];
dialog_graph_redraw(user_data);
}
static void pixels_per_tick_select(GtkWidget *item, gpointer data)
{
user_data_t *user_data = data;
int i;
i = gtk_combo_box_get_active (GTK_COMBO_BOX(item));
user_data->dlg.dialog_graph.pixels_per_tick_index=i;
user_data->dlg.dialog_graph.pixels_per_tick=pixels_per_tick[i];
dialog_graph_redraw(user_data);
}
static void tick_interval_select(GtkWidget *item, gpointer data)
{
user_data_t *user_data = data;
int i;
i = gtk_combo_box_get_active (GTK_COMBO_BOX(item));
user_data->dlg.dialog_graph.interval_index=i;
user_data->dlg.dialog_graph.interval=tick_interval_values[i];
cf_retap_packets(&cfile);
dialog_graph_redraw(user_data);
}
static GtkWidget *
create_yscale_max_menu_items(user_data_t* user_data)
{
char str[15];
GtkWidget *combo_box;
int i;
combo_box = gtk_combo_box_text_new();
for(i=0;i<MAX_YSCALE;i++){
if(yscale_max[i]==AUTO_MAX_YSCALE){
g_strlcpy(str,"Auto",sizeof(str));
} else if (yscale_max[i] < 1000000) {
g_snprintf(str, sizeof(str), "%u ms", yscale_max[i]/1000);
} else {
g_snprintf(str, sizeof(str), "%u s", yscale_max[i]/1000000);
}
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box), str);
}
gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), user_data->dlg.dialog_graph.max_y_units_index);
g_signal_connect(combo_box, "changed", G_CALLBACK(yscale_select), user_data);
return combo_box;
}
static GtkWidget *
create_pixels_per_tick_menu_items(user_data_t *user_data)
{
char str[5];
GtkWidget *combo_box;
int i;
combo_box = gtk_combo_box_text_new();
for(i=0;i<MAX_PIXELS_PER_TICK;i++){
g_snprintf(str, sizeof(str), "%u", pixels_per_tick[i]);
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box), str);
}
gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), user_data->dlg.dialog_graph.pixels_per_tick_index);
g_signal_connect(combo_box, "changed", G_CALLBACK(pixels_per_tick_select), user_data);
return combo_box;
}
static GtkWidget *
create_tick_interval_menu_items(user_data_t *user_data)
{
GtkWidget *combo_box;
char str[15];
int i;
combo_box = gtk_combo_box_text_new();
for(i=0;i<MAX_TICK_VALUES;i++){
if(tick_interval_values[i]>=1000){
g_snprintf(str, sizeof(str), "%u sec", tick_interval_values[i]/1000);
} else if(tick_interval_values[i]>=100){
g_snprintf(str, sizeof(str), "0.%1u sec", (tick_interval_values[i]/100)%10);
} else if(tick_interval_values[i]>=10){
g_snprintf(str, sizeof(str), "0.%02u sec", (tick_interval_values[i]/10)%10);
} else {
g_snprintf(str, sizeof(str), "0.%03u sec", (tick_interval_values[i])%10);
}
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box), str);
}
gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), user_data->dlg.dialog_graph.interval_index);
g_signal_connect(combo_box, "changed", G_CALLBACK(tick_interval_select), user_data);
return combo_box;
}
static void create_ctrl_menu(user_data_t* user_data, GtkWidget *box, const char *name, GtkWidget *(*func)(user_data_t* user_data))
{
GtkWidget *hbox;
GtkWidget *label;
GtkWidget *combo_box;
hbox=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(box), hbox);
gtk_box_set_child_packing(GTK_BOX(box), hbox, FALSE, FALSE, 0, GTK_PACK_START);
gtk_widget_show(hbox);
label=gtk_label_new(name);
gtk_widget_show(label);
gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
combo_box = (*func)(user_data);
gtk_box_pack_end(GTK_BOX(hbox), combo_box, FALSE, FALSE, 0);
gtk_widget_show(combo_box);
}
static void create_ctrl_area(user_data_t* user_data, GtkWidget *box)
{
GtkWidget *frame_vbox;
GtkWidget *frame;
GtkWidget *vbox;
frame_vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(box), frame_vbox);
gtk_widget_show(frame_vbox);
frame = gtk_frame_new("X Axis");
gtk_container_add(GTK_CONTAINER(frame_vbox), frame);
gtk_widget_show(frame);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(frame), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 3);
gtk_box_set_child_packing(GTK_BOX(box), vbox, FALSE, FALSE, 0, GTK_PACK_END);
gtk_widget_show(vbox);
create_ctrl_menu(user_data, vbox, "Tick interval:", create_tick_interval_menu_items);
create_ctrl_menu(user_data, vbox, "Pixels per tick:", create_pixels_per_tick_menu_items);
frame = gtk_frame_new("Y Axis");
gtk_container_add(GTK_CONTAINER(frame_vbox), frame);
gtk_widget_show(frame);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(frame), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 3);
gtk_box_set_child_packing(GTK_BOX(box), vbox, FALSE, FALSE, 0, GTK_PACK_END);
gtk_widget_show(vbox);
create_ctrl_menu(user_data, vbox, "Scale:", create_yscale_max_menu_items);
return;
}
static void dialog_graph_init_window(user_data_t* user_data)
{
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *bt_close;
user_data->dlg.dialog_graph.window=dlg_window_new("I/O Graphs");
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(user_data->dlg.dialog_graph.window), vbox);
gtk_widget_show(vbox);
create_draw_area(user_data, vbox);
hbox=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_end(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
gtk_container_set_border_width(GTK_CONTAINER(hbox), 3);
gtk_box_set_child_packing(GTK_BOX(vbox), hbox, FALSE, FALSE, 0, GTK_PACK_START);
gtk_widget_show(hbox);
create_filter_area(user_data, hbox);
create_ctrl_area(user_data, hbox);
dialog_graph_set_title(user_data);
hbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
gtk_widget_show(hbox);
bt_close = g_object_get_data(G_OBJECT(hbox), GTK_STOCK_CLOSE);
window_set_cancel_button(user_data->dlg.dialog_graph.window, bt_close, window_cancel_button_cb);
g_signal_connect(user_data->dlg.dialog_graph.window, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show(user_data->dlg.dialog_graph.window);
window_present(user_data->dlg.dialog_graph.window);
}
static void on_graph_bt_clicked(GtkWidget *bt _U_, gpointer data)
{
user_data_t *user_data = data;
if (user_data->dlg.dialog_graph.window != NULL) {
reactivate_window(user_data->dlg.dialog_graph.window);
return;
}
dialog_graph_init_window(user_data);
}
static void on_goto_bt_clicked(GtkWidget *bt _U_, gpointer data)
{
user_data_t *user_data = data;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *selection;
guint fnumber;
selection = user_data->dlg.selected_list_sel;
if (selection==NULL)
return;
if (gtk_tree_selection_get_selected (selection, &model, &iter)){
gtk_tree_model_get (model, &iter, PACKET_COLUMN, &fnumber, -1);
cf_goto_frame(&cfile, fnumber);
}
}
static void on_refresh_bt_clicked(GtkWidget *bt _U_, gpointer data)
{
user_data_t *user_data = data;
GString *error_string;
protect_thread_critical_region();
remove_tap_listener(user_data);
unprotect_thread_critical_region();
error_string = register_tap_listener("IAX2", user_data, NULL, 0,
iax2_reset, iax2_packet, iax2_draw);
if (error_string != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
return;
}
cf_retap_packets(&cfile);
draw_stat(user_data);
}
static void on_next_bt_clicked(GtkWidget *bt _U_, gpointer data)
{
user_data_t *user_data = data;
GtkTreeIter iter;
GtkTreeModel *model;
gchar *text;
GtkTreeSelection *selection;
GtkTreePath *path;
selection = user_data->dlg.selected_list_sel;
if (selection==NULL)
return;
try_again:
if (gtk_tree_selection_get_selected (selection, &model, &iter)){
while (gtk_tree_model_iter_next (model,&iter)) {
gtk_tree_model_get (model, &iter, STATUS_COLUMN, &text, -1);
if (strcmp(text, OK_TEXT) != 0) {
gtk_tree_selection_select_iter (selection, &iter);
path = gtk_tree_model_get_path(model, &iter);
gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW( user_data->dlg.selected_list),
path,
NULL, FALSE, 0, 0);
gtk_tree_path_free(path);
g_free (text);
return;
}
g_free (text);
}
if (user_data->dlg.number_of_nok>1){
gtk_tree_model_get_iter_first(model, &iter);
gtk_tree_selection_select_iter (selection, &iter);
goto try_again;
}
}
}
static gboolean save_csv_as_ok_cb(GtkWidget *w _U_, gpointer fc )
{
gchar *g_dest;
GtkWidget *rev, *forw, *both;
user_data_t *user_data;
GtkListStore *store;
GtkTreeIter iter;
GtkTreeModel *model;
gboolean more_items = TRUE;
guint packet;
gfloat delta;
gfloat jitter;
gfloat ipbw;
char *status_str;
char *date_str;
guint length;
FILE *fp;
int j;
g_dest = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc));
if (test_for_directory(g_dest) == EISDIR) {
set_last_open_dir(g_dest);
file_selection_set_current_folder(fc, get_last_open_dir());
gtk_file_chooser_set_current_name(fc, "");
g_free(g_dest);
return FALSE;
}
rev = (GtkWidget*)g_object_get_data(G_OBJECT(fc), "reversed_rb");
forw = (GtkWidget*)g_object_get_data(G_OBJECT(fc), "forward_rb");
both = (GtkWidget*)g_object_get_data(G_OBJECT(fc), "both_rb");
user_data = (user_data_t*)g_object_get_data(G_OBJECT(fc), "user_data");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(forw)) || gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(both))) {
fp = ws_fopen(g_dest, "w");
if (fp == NULL) {
open_failure_alert_box(g_dest, errno, TRUE);
g_free(g_dest);
return TRUE;
}
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(both))) {
fprintf(fp, "Forward\n");
if (ferror(fp)) {
write_failure_alert_box(g_dest, errno);
fclose(fp);
g_free(g_dest);
return TRUE;
}
}
for(j = 0; j < NUM_COLS; j++) {
if (j == 0) {
fprintf(fp,"\"%s\"",titles[j]);
} else {
fprintf(fp,",\"%s\"",titles[j]);
}
}
fprintf(fp,"\n");
if (ferror(fp)) {
write_failure_alert_box(g_dest, errno);
fclose(fp);
g_free(g_dest);
return TRUE;
}
model = gtk_tree_view_get_model(GTK_TREE_VIEW(user_data->dlg.list_fwd));
store = GTK_LIST_STORE(model);
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
while (more_items) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
0, &packet,
1, &delta,
2, &jitter,
3, &ipbw,
4, &status_str,
5, &date_str,
6, &length,
-1);
fprintf(fp, "\"%u\"",packet);
fprintf(fp, ",\"%.2f\"", delta);
fprintf(fp, ",\"%.2f\"", jitter);
fprintf(fp, ",\"%.2f\"", ipbw);
fprintf(fp, ",\"%s\"", status_str);
fprintf(fp, ",\"%s\"", date_str);
fprintf(fp, ",\"%u\"", length);
fprintf(fp,"\n");
g_free(status_str);
g_free(date_str);
if (ferror(fp)) {
write_failure_alert_box(g_dest, errno);
fclose(fp);
g_free(g_dest);
return TRUE;
}
more_items = gtk_tree_model_iter_next (model,&iter);
}
}
if (fclose(fp) == EOF) {
write_failure_alert_box(g_dest, errno);
g_free(g_dest);
return TRUE;
}
}
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rev)) || gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(both))) {
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(both))) {
fp = ws_fopen(g_dest, "a");
if (fp == NULL) {
open_failure_alert_box(g_dest, errno, TRUE);
g_free(g_dest);
return TRUE;
}
fprintf(fp, "\nReverse\n");
if (ferror(fp)) {
write_failure_alert_box(g_dest, errno);
fclose(fp);
g_free(g_dest);
return TRUE;
}
} else {
fp = ws_fopen(g_dest, "w");
if (fp == NULL) {
open_failure_alert_box(g_dest, errno, TRUE);
g_free(g_dest);
return TRUE;
}
}
for(j = 0; j < NUM_COLS; j++) {
if (j == 0) {
fprintf(fp,"\"%s\"",titles[j]);
} else {
fprintf(fp,",\"%s\"",titles[j]);
}
}
fprintf(fp,"\n");
if (ferror(fp)) {
write_failure_alert_box(g_dest, errno);
fclose(fp);
g_free(g_dest);
return TRUE;
}
model = gtk_tree_view_get_model(GTK_TREE_VIEW(user_data->dlg.list_rev));
store = GTK_LIST_STORE(model);
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
more_items = TRUE;
while (more_items) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
0, &packet,
1, &delta,
2, &jitter,
3, &ipbw,
4, &status_str,
5, &date_str,
6, &length,
-1);
fprintf(fp, "\"%u\"",packet);
fprintf(fp, ",\"%.2f\"", delta);
fprintf(fp, ",\"%.2f\"", jitter);
fprintf(fp, ",\"%.2f\"", ipbw);
fprintf(fp, ",\"%s\"", status_str);
fprintf(fp, ",\"%s\"", date_str);
fprintf(fp, ",\"%u\"", length);
fprintf(fp,"\n");
g_free(status_str);
g_free(date_str);
if (ferror(fp)) {
write_failure_alert_box(g_dest, errno);
fclose(fp);
g_free(g_dest);
return TRUE;
}
more_items = gtk_tree_model_iter_next (model,&iter);
}
}
if (fclose(fp) == EOF) {
write_failure_alert_box(g_dest, errno);
g_free(g_dest);
return TRUE;
}
}
g_free(g_dest);
return TRUE;
}
static void save_csv_as_destroy_cb(GtkWidget *win _U_, gpointer data)
{
user_data_t *user_data = data;
user_data->dlg.save_csv_as_w = NULL;
}
static void save_csv_as_cb(GtkWidget *bt _U_, gpointer data)
{
user_data_t *user_data = data;
GtkWidget *vertb;
GtkWidget *table1;
GtkWidget *label_format;
GtkWidget *channels_label;
GtkWidget *forward_rb;
GtkWidget *reversed_rb;
GtkWidget *both_rb;
#if 0
if (user_data->dlg.save_csv_as_w != NULL) {
reactivate_window(user_data->dlg.save_csv_as_w);
return;
}
#endif
user_data->dlg.save_csv_as_w =
gtk_file_chooser_dialog_new("Wireshark: Save Data As CSV",
GTK_WINDOW(user_data->dlg.notebook),
GTK_FILE_CHOOSER_ACTION_SAVE,
GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
NULL);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(user_data->dlg.save_csv_as_w), TRUE);
gtk_window_set_transient_for(GTK_WINDOW(user_data->dlg.save_csv_as_w),GTK_WINDOW(user_data->dlg.window));
vertb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(vertb), 5);
gtk_file_chooser_set_extra_widget(GTK_FILE_CHOOSER(user_data->dlg.save_csv_as_w), vertb);
gtk_widget_show (vertb);
table1 = gtk_table_new (2, 4, FALSE);
gtk_widget_show (table1);
gtk_box_pack_start (GTK_BOX (vertb), table1, FALSE, FALSE, 0);
gtk_container_set_border_width (GTK_CONTAINER (table1), 10);
gtk_table_set_row_spacings (GTK_TABLE (table1), 20);
label_format = gtk_label_new ("Format: Comma Separated Values");
gtk_widget_show (label_format);
gtk_table_attach (GTK_TABLE (table1), label_format, 0, 3, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
gtk_misc_set_alignment (GTK_MISC (label_format), 0, 0.5f);
channels_label = gtk_label_new ("Channels: ");
gtk_widget_show (channels_label);
gtk_table_attach (GTK_TABLE (table1), channels_label, 0, 1, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
gtk_misc_set_alignment (GTK_MISC (channels_label), 0, 0.5f);
forward_rb = gtk_radio_button_new_with_label (NULL, "forward ");
gtk_widget_show (forward_rb);
gtk_table_attach (GTK_TABLE (table1), forward_rb, 1, 2, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
reversed_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(forward_rb), "reversed ");
gtk_widget_show (reversed_rb);
gtk_table_attach (GTK_TABLE (table1), reversed_rb, 2, 3, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
both_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(forward_rb), "both");
gtk_widget_show (both_rb);
gtk_table_attach (GTK_TABLE (table1), both_rb, 3, 4, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(both_rb), TRUE);
g_object_set_data(G_OBJECT(user_data->dlg.save_csv_as_w), "forward_rb", forward_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_csv_as_w), "reversed_rb", reversed_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_csv_as_w), "both_rb", both_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_csv_as_w), "user_data", user_data);
g_signal_connect(user_data->dlg.save_csv_as_w, "delete_event",
G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(user_data->dlg.save_csv_as_w, "destroy",
G_CALLBACK(save_csv_as_destroy_cb), user_data);
gtk_widget_show(user_data->dlg.save_csv_as_w);
window_present(user_data->dlg.save_csv_as_w);
while (gtk_dialog_run(GTK_DIALOG(user_data->dlg.save_csv_as_w)) == GTK_RESPONSE_ACCEPT) {
if (save_csv_as_ok_cb(NULL, user_data->dlg.save_csv_as_w)) {
break;
}
}
window_destroy(user_data->dlg.save_csv_as_w);
}
static void save_voice_as_destroy_cb(GtkWidget *win _U_, gpointer data)
{
user_data_t *user_data = data;
user_data->dlg.save_voice_as_w = NULL;
}
static gboolean copy_file(gchar *dest, gint channels, gint format, user_data_t *user_data)
{
int to_fd, forw_fd, rev_fd, fread_cnt = 0, rread = 0, fwritten, rwritten;
gchar f_pd[1] = {0};
gchar r_pd[1] = {0};
gint16 sample;
gchar pd[4];
guint32 f_write_silence = 0;
guint32 r_write_silence = 0;
progdlg_t *progbar;
guint32 progbar_count, progbar_quantum, progbar_nextstep = 0, count = 0;
gboolean stop_flag = FALSE;
forw_fd = ws_open(user_data->f_tempname, O_RDONLY | O_BINARY, 0000 );
if (forw_fd < 0)
return FALSE;
rev_fd = ws_open(user_data->r_tempname, O_RDONLY | O_BINARY, 0000 );
if (rev_fd < 0) {
ws_close(forw_fd);
return FALSE;
}
to_fd = ws_open(dest, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
if (to_fd < 0) {
ws_close(forw_fd);
ws_close(rev_fd);
return FALSE;
}
progbar = create_progress_dlg("Saving voice in a file", dest, TRUE, &stop_flag);
if (format == SAVE_AU_FORMAT)
{
phtonl(pd, 0x2e736e64);
fwritten = ws_write(to_fd, pd, 4);
if ((fwritten < 4) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
phtonl(pd, 24);
fwritten = ws_write(to_fd, pd, 4);
if ((fwritten < 4) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
phtonl(pd, -1);
fwritten = ws_write(to_fd, pd, 4);
if ((fwritten < 4) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
phtonl(pd, 3);
fwritten = ws_write(to_fd, pd, 4);
if ((fwritten < 4) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
phtonl(pd, 8000);
fwritten = ws_write(to_fd, pd, 4);
if ((fwritten < 4) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
phtonl(pd, 1);
fwritten = ws_write(to_fd, pd, 4);
if ((fwritten < 4) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
switch (channels) {
case SAVE_FORWARD_DIRECTION_MASK: {
progbar_count = user_data->forward.saveinfo.count;
progbar_quantum = user_data->forward.saveinfo.count/100;
while ((fread_cnt = read(forw_fd, f_pd, 1)) > 0) {
if(stop_flag)
break;
if((count > progbar_nextstep) && (count <= progbar_count)) {
update_progress_dlg(progbar,
(gfloat) count/progbar_count, "Saving");
progbar_nextstep = progbar_nextstep + progbar_quantum;
}
count++;
if (user_data->forward.statinfo.pt == AST_FORMAT_ULAW){
sample = ulaw2linear(*f_pd);
phtons(pd, sample);
}
else if(user_data->forward.statinfo.pt == AST_FORMAT_ALAW){
sample = alaw2linear(*f_pd);
phtons(pd, sample);
}
else{
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
fwritten = ws_write(to_fd, pd, 2);
if ((fwritten < 2) || (fwritten < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
}
break;
}
case SAVE_REVERSE_DIRECTION_MASK: {
progbar_count = user_data->reversed.saveinfo.count;
progbar_quantum = user_data->reversed.saveinfo.count/100;
while ((rread = read(rev_fd, r_pd, 1)) > 0) {
if(stop_flag)
break;
if((count > progbar_nextstep) && (count <= progbar_count)) {
update_progress_dlg(progbar,
(gfloat) count/progbar_count, "Saving");
progbar_nextstep = progbar_nextstep + progbar_quantum;
}
count++;
if (user_data->reversed.statinfo.pt == AST_FORMAT_ULAW){
sample = ulaw2linear(*r_pd);
phtons(pd, sample);
}
else if(user_data->reversed.statinfo.pt == AST_FORMAT_ALAW){
sample = alaw2linear(*r_pd);
phtons(pd, sample);
}
else{
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
rwritten = ws_write(to_fd, pd, 2);
if ((rwritten < 2) || (rwritten < 0) || (rread < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
}
break;
}
case SAVE_BOTH_DIRECTION_MASK: {
(user_data->forward.saveinfo.count > user_data->reversed.saveinfo.count) ?
(progbar_count = user_data->forward.saveinfo.count) :
(progbar_count = user_data->reversed.saveinfo.count);
progbar_quantum = progbar_count/100;
if (user_data->forward.statinfo.start_time > user_data->reversed.statinfo.start_time) {
f_write_silence = (guint32)
((user_data->forward.statinfo.start_time-user_data->reversed.statinfo.start_time)*8000);
}
else if (user_data->forward.statinfo.start_time < user_data->reversed.statinfo.start_time) {
r_write_silence = (guint32)
((user_data->reversed.statinfo.start_time-user_data->forward.statinfo.start_time)*8000);
}
for(;;) {
if(stop_flag)
break;
if((count > progbar_nextstep) && (count <= progbar_count)) {
update_progress_dlg(progbar,
(gfloat) count/progbar_count, "Saving");
progbar_nextstep = progbar_nextstep + progbar_quantum;
}
count++;
if(f_write_silence > 0) {
rread = read(rev_fd, r_pd, 1);
switch (user_data->forward.statinfo.reg_pt) {
case AST_FORMAT_ULAW:
*f_pd = SILENCE_PCMU;
break;
case AST_FORMAT_ALAW:
*f_pd = SILENCE_PCMA;
break;
}
fread_cnt = 1;
f_write_silence--;
}
else if(r_write_silence > 0) {
fread_cnt = read(forw_fd, f_pd, 1);
switch (user_data->reversed.statinfo.reg_pt) {
case AST_FORMAT_ULAW:
*r_pd = SILENCE_PCMU;
break;
case AST_FORMAT_ALAW:
*r_pd = SILENCE_PCMA;
break;
}
rread = 1;
r_write_silence--;
}
else {
fread_cnt = read(forw_fd, f_pd, 1);
rread = read(rev_fd, r_pd, 1);
}
if ((rread == 0) && (fread_cnt == 0))
break;
if ((user_data->forward.statinfo.pt == AST_FORMAT_ULAW) && (user_data->reversed.statinfo.pt == AST_FORMAT_ULAW)){
sample = (ulaw2linear(*r_pd) + ulaw2linear(*f_pd)) / 2;
phtons(pd, sample);
}
else if((user_data->forward.statinfo.pt == AST_FORMAT_ALAW) && (user_data->reversed.statinfo.pt == AST_FORMAT_ALAW)){
sample = (alaw2linear(*r_pd) + alaw2linear(*f_pd)) / 2;
phtons(pd, sample);
}
else
{
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
rwritten = ws_write(to_fd, pd, 2);
if ((rwritten < 2) || (rread < 0) || (fread_cnt < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
}
}
}
}
else if (format == SAVE_RAW_FORMAT)
{
int fd;
switch (channels) {
case SAVE_FORWARD_DIRECTION_MASK: {
progbar_count = user_data->forward.saveinfo.count;
progbar_quantum = user_data->forward.saveinfo.count/100;
fd = forw_fd;
break;
}
case SAVE_REVERSE_DIRECTION_MASK: {
progbar_count = user_data->reversed.saveinfo.count;
progbar_quantum = user_data->reversed.saveinfo.count/100;
fd = rev_fd;
break;
}
default: {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
}
while ((rread = read(fd, pd, 1)) > 0) {
if(stop_flag)
break;
if((count > progbar_nextstep) && (count <= progbar_count)) {
update_progress_dlg(progbar,
(gfloat) count/progbar_count, "Saving");
progbar_nextstep = progbar_nextstep + progbar_quantum;
}
count++;
rwritten = ws_write(to_fd, pd, 1);
if ((rwritten < rread) || (rwritten < 0) || (rread < 0)) {
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
destroy_progress_dlg(progbar);
return FALSE;
}
}
}
destroy_progress_dlg(progbar);
ws_close(forw_fd);
ws_close(rev_fd);
ws_close(to_fd);
return TRUE;
}
static gboolean save_voice_as_ok_cb(GtkWidget *w _U_, gpointer fc)
{
gchar *g_dest;
GtkWidget *au, *raw;
GtkWidget *rev, *forw, *both;
user_data_t *user_data;
gint channels , format;
g_dest = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc));
if (test_for_directory(g_dest) == EISDIR) {
set_last_open_dir(g_dest);
file_selection_set_current_folder(fc, get_last_open_dir());
gtk_file_chooser_set_current_name(fc, "");
g_free(g_dest);
return FALSE;
}
#if 0
wav = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "wav_rb");
sw = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "sw_rb");
#endif
au = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "au_rb");
raw = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "raw_rb");
rev = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "reversed_rb");
forw = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "forward_rb");
both = (GtkWidget *)g_object_get_data(G_OBJECT(fc), "both_rb");
user_data = (user_data_t *)g_object_get_data(G_OBJECT(fc), "user_data");
if ((user_data->forward.saveinfo.saved == FALSE) && (user_data->reversed.saveinfo.saved == FALSE) && (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (both)))) {
if ((user_data->forward.saveinfo.error_type == TAP_RTP_WRONG_CODEC) ||
(user_data->reversed.saveinfo.error_type == TAP_RTP_WRONG_CODEC))
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: Unsupported codec!");
else if ((user_data->forward.saveinfo.error_type == TAP_RTP_WRONG_LENGTH) ||
(user_data->reversed.saveinfo.error_type == TAP_RTP_WRONG_LENGTH))
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: Wrong length of captured packets!");
else if ((user_data->forward.saveinfo.error_type == TAP_RTP_SHORT_FRAME) ||
(user_data->reversed.saveinfo.error_type == TAP_RTP_SHORT_FRAME))
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: Not all data in all packets was captured!");
else
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: File I/O problem!");
g_free(g_dest);
return TRUE;
}
else if ((user_data->forward.saveinfo.saved == FALSE) && ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (forw))) ||
(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (both))))) {
if (user_data->forward.saveinfo.error_type == TAP_RTP_WRONG_CODEC)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save forward direction in a file: Unsupported codec!");
else if (user_data->forward.saveinfo.error_type == TAP_RTP_WRONG_LENGTH)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save forward direction in a file: Wrong length of captured packets!");
else if (user_data->forward.saveinfo.error_type == TAP_RTP_SHORT_FRAME)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save forward direction in a file: Not all data in all packets was captured!");
else
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save forward direction in a file: File I/O problem!");
g_free(g_dest);
return TRUE;
}
else if ((user_data->reversed.saveinfo.saved == FALSE) && ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (rev))) ||
(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (both))))) {
if (user_data->reversed.saveinfo.error_type == TAP_RTP_WRONG_CODEC)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save reversed direction in a file: Unsupported codec!");
else if (user_data->reversed.saveinfo.error_type == TAP_RTP_WRONG_LENGTH)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save reversed direction in a file: Wrong length of captured packets!");
else if (user_data->reversed.saveinfo.error_type == TAP_RTP_SHORT_FRAME)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save reversed direction in a file: Not all data in all packets was captured!");
else if (user_data->reversed.saveinfo.error_type == TAP_RTP_NO_DATA)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save reversed direction in a file: No IAX2 data!");
else
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save reversed direction in a file: File I/O problem!");
g_free(g_dest);
return TRUE;
}
#if 0
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (wav)))
format = SAVE_WAV_FORMAT;
else
#endif
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (au)))
format = SAVE_AU_FORMAT;
#if 0
else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (sw)))
format = SAVE_SW_FORMAT;
#endif
else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (raw)))
format = SAVE_RAW_FORMAT;
else
format = SAVE_NONE_FORMAT;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (rev)))
channels = SAVE_REVERSE_DIRECTION_MASK;
else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (both)))
channels = SAVE_BOTH_DIRECTION_MASK;
else
channels = SAVE_FORWARD_DIRECTION_MASK;
if (format == SAVE_AU_FORMAT)
{
if ((channels & SAVE_FORWARD_DIRECTION_MASK) && (user_data->forward.statinfo.pt != AST_FORMAT_ALAW) && (user_data->forward.statinfo.pt != AST_FORMAT_ULAW)){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: saving in au format supported only for alaw/ulaw streams");
g_free(g_dest);
return TRUE;
}
if ((channels & SAVE_REVERSE_DIRECTION_MASK) && (user_data->reversed.statinfo.pt != AST_FORMAT_ALAW) && (user_data->reversed.statinfo.pt != AST_FORMAT_ULAW)){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: saving in au format supported only for alaw/ulaw streams");
g_free(g_dest);
return TRUE;
}
if ((channels == SAVE_BOTH_DIRECTION_MASK) && (user_data->forward.statinfo.pt != user_data->reversed.statinfo.pt)){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: Forward and reverse direction differ in type");
g_free(g_dest);
return TRUE;
}
}
else if (format == SAVE_RAW_FORMAT)
{
if (channels == SAVE_BOTH_DIRECTION_MASK){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: Unable to save raw data in both directions");
g_free(g_dest);
return TRUE;
}
}
else
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't save in a file: Invalid save format");
g_free(g_dest);
return TRUE;
}
if(!copy_file(g_dest, channels, format, user_data)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"An error occurred while saving voice in a file!");
g_free(g_dest);
return TRUE;
}
g_free(g_dest);
return TRUE;
}
static void save_voice_as_cb(GtkWidget *bt _U_, gpointer data)
{
user_data_t *user_data = data;
GtkWidget *vertb;
GtkWidget *table1;
GtkWidget *label_format;
GtkWidget *channels_label;
GtkWidget *forward_rb;
GtkWidget *reversed_rb;
GtkWidget *both_rb;
GtkWidget *au_rb;
GtkWidget *raw_rb;
#if 0
if (user_data->dlg.save_voice_as_w != NULL) {
reactivate_window(user_data->dlg.save_voice_as_w);
return;
}
#endif
user_data->dlg.save_voice_as_w =
gtk_file_chooser_dialog_new("Wireshark: Save Payload As ...",
GTK_WINDOW(user_data->dlg.notebook),
GTK_FILE_CHOOSER_ACTION_SAVE,
GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
NULL);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(user_data->dlg.save_voice_as_w), TRUE);
gtk_window_set_transient_for(GTK_WINDOW(user_data->dlg.save_voice_as_w),GTK_WINDOW(user_data->dlg.window));
vertb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(vertb), 5);
gtk_file_chooser_set_extra_widget(GTK_FILE_CHOOSER(user_data->dlg.save_voice_as_w), vertb);
gtk_widget_show (vertb);
table1 = gtk_table_new (2, 4, FALSE);
gtk_widget_show (table1);
gtk_box_pack_start (GTK_BOX (vertb), table1, FALSE, FALSE, 0);
gtk_container_set_border_width (GTK_CONTAINER (table1), 10);
gtk_table_set_row_spacings (GTK_TABLE (table1), 20);
#if 0
label_format = gtk_label_new ("Format: .au (ulaw, 8 bit, 8000 Hz, mono) ");
gtk_widget_show (label_format);
gtk_table_attach (GTK_TABLE (table1), label_format, 0, 3, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
#endif
label_format = gtk_label_new ("Format: ");
gtk_widget_show (label_format);
gtk_table_attach (GTK_TABLE (table1), label_format, 0, 3, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
gtk_misc_set_alignment (GTK_MISC (label_format), 0, 0.5f);
raw_rb = gtk_radio_button_new_with_label (NULL, ".raw");
gtk_widget_show (raw_rb);
gtk_table_attach (GTK_TABLE (table1), raw_rb, 1, 2, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
au_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(raw_rb), ".au");
gtk_widget_show (au_rb);
gtk_table_attach (GTK_TABLE (table1), au_rb, 3, 4, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
#if 0
wav_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(raw_rb), ".wav");
gtk_widget_show (wav_rb);
gtk_table_attach (GTK_TABLE (table1), wav_rb, 1, 2, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
sw_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(raw_rb), "8 kHz, 16 bit ");
gtk_widget_show (sw_rb);
gtk_table_attach (GTK_TABLE (table1), sw_rb, 2, 3, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
au_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(raw_rb), ".au");
gtk_widget_show (au_rb);
gtk_table_attach (GTK_TABLE (table1), au_rb, 3, 4, 0, 1,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
#endif
channels_label = gtk_label_new ("Channels: ");
gtk_widget_show (channels_label);
gtk_table_attach (GTK_TABLE (table1), channels_label, 0, 1, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
gtk_misc_set_alignment (GTK_MISC (channels_label), 0, 0.5f);
forward_rb = gtk_radio_button_new_with_label (NULL, "forward ");
gtk_widget_show (forward_rb);
gtk_table_attach (GTK_TABLE (table1), forward_rb, 1, 2, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
reversed_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(forward_rb), "reversed ");
gtk_widget_show (reversed_rb);
gtk_table_attach (GTK_TABLE (table1), reversed_rb, 2, 3, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
both_rb = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(forward_rb), "both");
gtk_widget_show (both_rb);
gtk_table_attach (GTK_TABLE (table1), both_rb, 3, 4, 1, 2,
(GtkAttachOptions) (GTK_FILL),
(GtkAttachOptions) (0), 0, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(forward_rb), TRUE);
#if 0
if (user_data->forward.saved == FALSE) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(reversed_rb), TRUE);
gtk_widget_set_sensitive(forward_rb, FALSE);
gtk_widget_set_sensitive(both_rb, FALSE);
}
else if (user_data->reversed.saved == FALSE) {
gtk_widget_set_sensitive(reversed_rb, FALSE);
gtk_widget_set_sensitive(both_rb, FALSE);
}
#endif
g_object_set_data(G_OBJECT(user_data->dlg.save_voice_as_w), "au_rb", au_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_voice_as_w), "raw_rb", raw_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_voice_as_w), "forward_rb", forward_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_voice_as_w), "reversed_rb", reversed_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_voice_as_w), "both_rb", both_rb);
g_object_set_data(G_OBJECT(user_data->dlg.save_voice_as_w), "user_data", user_data);
g_signal_connect(user_data->dlg.save_voice_as_w, "delete_event",
G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(user_data->dlg.save_voice_as_w, "destroy",
G_CALLBACK(save_voice_as_destroy_cb), user_data);
gtk_widget_show(user_data->dlg.save_voice_as_w);
window_present(user_data->dlg.save_voice_as_w);
while (gtk_dialog_run(GTK_DIALOG(user_data->dlg.save_voice_as_w)) == GTK_RESPONSE_ACCEPT) {
if (save_voice_as_ok_cb(NULL, user_data->dlg.save_voice_as_w)) {
break;
}
}
window_destroy(user_data->dlg.save_voice_as_w);
}
static void draw_stat(user_data_t *user_data)
{
gchar label_max[200];
g_snprintf(label_max, sizeof(label_max), "Total IAX2 packets = %u Max delta = %f sec at packet no. %u",
user_data->forward.statinfo.total_nr,
user_data->forward.statinfo.max_delta, user_data->forward.statinfo.max_nr);
gtk_label_set_text(GTK_LABEL(user_data->dlg.label_stats_fwd), label_max);
g_snprintf(label_max, sizeof(label_max), "Total IAX2 packets = %u Max delta = %f sec at packet no. %u",
user_data->reversed.statinfo.total_nr,
user_data->reversed.statinfo.max_delta, user_data->reversed.statinfo.max_nr);
gtk_label_set_text(GTK_LABEL(user_data->dlg.label_stats_rev), label_max);
return ;
}
static void add_to_list(GtkWidget *list, user_data_t * user_data, guint32 number,
double delta, double jitter, double bandwidth, gchar *status,
gchar *timeStr, guint32 pkt_len, gchar *color_str, guint32 flags)
{
GtkListStore *list_store;
if (strcmp(status, OK_TEXT) != 0) {
user_data->dlg.number_of_nok++;
}
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (list)));
gtk_list_store_insert_with_values( list_store , &user_data->dlg.iter, G_MAXINT,
PACKET_COLUMN, number,
DELTA_COLUMN, delta,
JITTER_COLUMN, jitter,
IPBW_COLUMN, bandwidth,
STATUS_COLUMN, (char *)status,
DATE_COLUMN, (char *)timeStr,
LENGTH_COLUMN, pkt_len,
FOREGROUND_COLOR_COL, NULL,
BACKGROUND_COLOR_COL, (char *)color_str,
-1);
if(flags & STAT_FLAG_FIRST){
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)), &user_data->dlg.iter);
}
}
static void
iax2_float_data_func (GtkTreeViewColumn *column _U_,
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
savelocale = setlocale(LC_NUMERIC, NULL);
setlocale(LC_NUMERIC, "C");
g_snprintf(buf, sizeof(buf), "%.2f", float_val);
setlocale(LC_NUMERIC, savelocale);
g_object_set(renderer, "text", buf, NULL);
}
static
GtkWidget* create_list(user_data_t* user_data)
{
GtkListStore *list_store;
GtkWidget *list;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeView *list_view;
GtkTreeSelection *selection;
list_store = gtk_list_store_new(N_COLUMN,
G_TYPE_UINT,
G_TYPE_FLOAT,
G_TYPE_FLOAT,
G_TYPE_FLOAT,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_STRING);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, PACKET_COLUMN, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Packet", renderer,
"text", PACKET_COLUMN,
"foreground", FOREGROUND_COLOR_COL,
"background", BACKGROUND_COLOR_COL,
NULL);
gtk_tree_view_column_set_sort_column_id(column, PACKET_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Delta(ms)", renderer,
"text", DELTA_COLUMN,
"foreground", FOREGROUND_COLOR_COL,
"background", BACKGROUND_COLOR_COL,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, iax2_float_data_func,
GINT_TO_POINTER(DELTA_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, DELTA_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Jitter(ms)", renderer,
"text", JITTER_COLUMN,
"foreground", FOREGROUND_COLOR_COL,
"background", BACKGROUND_COLOR_COL,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, iax2_float_data_func,
GINT_TO_POINTER(JITTER_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, JITTER_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("IP BW(kbps)", renderer,
"text", IPBW_COLUMN,
"foreground", FOREGROUND_COLOR_COL,
"background", BACKGROUND_COLOR_COL,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, iax2_float_data_func,
GINT_TO_POINTER(IPBW_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, IPBW_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ( "Status", renderer,
"text", STATUS_COLUMN,
"foreground", FOREGROUND_COLOR_COL,
"background", BACKGROUND_COLOR_COL,
NULL);
gtk_tree_view_column_set_sort_column_id(column, STATUS_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Length", renderer,
"text", LENGTH_COLUMN,
"foreground", FOREGROUND_COLOR_COL,
"background", BACKGROUND_COLOR_COL,
NULL);
gtk_tree_view_column_set_sort_column_id(column, LENGTH_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(list_view), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(list_view), TRUE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
g_signal_connect (G_OBJECT (selection), "changed",
G_CALLBACK (on_list_select_row),
user_data);
return list;
}
static void create_iax2_dialog(user_data_t* user_data)
{
GtkWidget *window = NULL;
GtkWidget *list_fwd;
GtkWidget *list_rev;
GtkWidget *label_stats_fwd;
GtkWidget *label_stats_rev;
GtkWidget *notebook;
GtkWidget *main_vb, *page, *page_r;
GtkWidget *label;
GtkWidget *scrolled_window, *scrolled_window_r;
GtkWidget *box4, *voice_bt, *refresh_bt, *goto_bt, *close_bt, *csv_bt, *next_bt;
GtkWidget *graph_bt;
gchar label_forward[150];
gchar label_reverse[150];
gchar str_ip_src[16];
gchar str_ip_dst[16];
window = dlg_window_new("Wireshark: IAX2 Stream Analysis");
gtk_window_set_default_size(GTK_WINDOW(window), 700, 400);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 2, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 2);
gtk_container_add(GTK_CONTAINER(window), main_vb);
gtk_widget_show(main_vb);
g_strlcpy(str_ip_src, get_addr_name(&(user_data->ip_src_fwd)), 16);
g_strlcpy(str_ip_dst, get_addr_name(&(user_data->ip_dst_fwd)), 16);
g_snprintf(label_forward, sizeof(label_forward),
"Analysing stream from %s port %u to %s port %u ",
str_ip_src, user_data->port_src_fwd, str_ip_dst, user_data->port_dst_fwd);
g_strlcpy(str_ip_src, get_addr_name(&(user_data->ip_src_rev)), 16);
g_strlcpy(str_ip_dst, get_addr_name(&(user_data->ip_dst_rev)), 16);
g_snprintf(label_reverse, sizeof(label_reverse),
"Analysing stream from %s port %u to %s port %u ",
str_ip_src, user_data->port_src_rev, str_ip_dst, user_data->port_dst_rev);
notebook = gtk_notebook_new();
gtk_container_add(GTK_CONTAINER(main_vb), notebook);
g_object_set_data(G_OBJECT(window), "notebook", notebook);
user_data->dlg.notebook_signal_id =
g_signal_connect(notebook, "switch_page", G_CALLBACK(on_notebook_switch_page), user_data);
page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 8, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(page), 8);
label = gtk_label_new(label_forward);
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
label_stats_fwd = gtk_label_new("\n");
gtk_box_pack_end(GTK_BOX(page), label_stats_fwd, FALSE, FALSE, 0);
scrolled_window = scrolled_window_new(NULL, NULL);
list_fwd = create_list(user_data);
gtk_widget_show(list_fwd);
gtk_container_add(GTK_CONTAINER(scrolled_window), list_fwd);
gtk_box_pack_start(GTK_BOX(page), scrolled_window, TRUE, TRUE, 0);
gtk_widget_show(scrolled_window);
label = gtk_label_new(" Forward Direction ");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
page_r = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 8, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(page_r), 8);
label = gtk_label_new(label_reverse);
gtk_box_pack_start(GTK_BOX(page_r), label, FALSE, FALSE, 0);
label_stats_rev = gtk_label_new("\n");
gtk_box_pack_end(GTK_BOX(page_r), label_stats_rev, FALSE, FALSE, 0);
scrolled_window_r = scrolled_window_new(NULL, NULL);
list_rev = create_list(user_data);
gtk_widget_show(list_rev);
gtk_container_add(GTK_CONTAINER(scrolled_window_r), list_rev);
gtk_box_pack_start(GTK_BOX(page_r), scrolled_window_r, TRUE, TRUE, 0);
gtk_widget_show(scrolled_window_r);
label = gtk_label_new(" Reversed Direction ");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_r, label);
#if 0
page_help = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
label = gtk_label_new(" Future ");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_help, label);
frame = gtk_frame_new("");
text = gtk_label_new("\n\nMaybe some more statistics: delta and jitter distribution,...");
gtk_label_set_justify(GTK_LABEL(text), GTK_JUSTIFY_LEFT);
gtk_container_add(GTK_CONTAINER(frame), text);
gtk_container_set_border_width(GTK_CONTAINER(frame), 20);
gtk_box_pack_start(GTK_BOX(page_help), frame, TRUE, TRUE, 0);
#endif
gtk_widget_show_all(notebook);
box4 = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(main_vb), box4, FALSE, FALSE, 0);
gtk_container_set_border_width(GTK_CONTAINER(box4), 10);
gtk_button_box_set_layout(GTK_BUTTON_BOX (box4), GTK_BUTTONBOX_EDGE);
gtk_box_set_spacing(GTK_BOX (box4), 0);
gtk_widget_show(box4);
voice_bt = gtk_button_new_with_label("Save payload...");
gtk_container_add(GTK_CONTAINER(box4), voice_bt);
gtk_widget_show(voice_bt);
g_signal_connect(voice_bt, "clicked", G_CALLBACK(save_voice_as_cb), user_data);
csv_bt = gtk_button_new_with_label("Save as CSV...");
gtk_container_add(GTK_CONTAINER(box4), csv_bt);
gtk_widget_show(csv_bt);
g_signal_connect(csv_bt, "clicked", G_CALLBACK(save_csv_as_cb), user_data);
refresh_bt = gtk_button_new_from_stock(GTK_STOCK_REFRESH);
gtk_container_add(GTK_CONTAINER(box4), refresh_bt);
gtk_widget_show(refresh_bt);
g_signal_connect(refresh_bt, "clicked", G_CALLBACK(on_refresh_bt_clicked), user_data);
goto_bt = gtk_button_new_from_stock(GTK_STOCK_JUMP_TO);
gtk_container_add(GTK_CONTAINER(box4), goto_bt);
gtk_widget_show(goto_bt);
g_signal_connect(goto_bt, "clicked", G_CALLBACK(on_goto_bt_clicked), user_data);
graph_bt = gtk_button_new_with_label("Graph");
gtk_container_add(GTK_CONTAINER(box4), graph_bt);
gtk_widget_show(graph_bt);
g_signal_connect(graph_bt, "clicked", G_CALLBACK(on_graph_bt_clicked), user_data);
next_bt = gtk_button_new_with_label("Next non-Ok");
gtk_container_add(GTK_CONTAINER(box4), next_bt);
gtk_widget_show(next_bt);
g_signal_connect(next_bt, "clicked", G_CALLBACK(on_next_bt_clicked), user_data);
close_bt = gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_container_add(GTK_CONTAINER(box4), close_bt);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(close_bt, TRUE);
#else
GTK_WIDGET_SET_FLAGS(close_bt, GTK_CAN_DEFAULT);
#endif
gtk_widget_show(close_bt);
window_set_cancel_button(window, close_bt, window_cancel_button_cb);
g_signal_connect(window, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(window, "destroy", G_CALLBACK(on_iax2_window_destroy), user_data);
gtk_widget_show(window);
window_present(window);
user_data->dlg.window = window;
user_data->dlg.list_fwd = list_fwd;
user_data->dlg.list_rev = list_rev;
user_data->dlg.label_stats_fwd = label_stats_fwd;
user_data->dlg.label_stats_rev = label_stats_rev;
user_data->dlg.notebook = notebook;
user_data->dlg.selected_list = list_fwd;
user_data->dlg.number_of_nok = 0;
gtk_widget_grab_focus(list_fwd);
}
void iax2_analysis(
address *ip_src_fwd,
guint16 port_src_fwd,
address *ip_dst_fwd,
guint16 port_dst_fwd,
address *ip_src_rev,
guint16 port_src_rev,
address *ip_dst_rev,
guint16 port_dst_rev
)
{
user_data_t *user_data;
int fd;
int i;
static GdkColor col[MAX_GRAPHS] = {
{0, 0x0000, 0x0000, 0x0000},
{0, 0xffff, 0x0000, 0x0000},
{0, 0x0000, 0xffff, 0x0000},
{0, 0x0000, 0x0000, 0xffff}
};
#if GTK_CHECK_VERSION(3,0,0)
static GdkRGBA rgba_col[MAX_GRAPHS] = {
{0.0, 0.0, 0.0, 1.0},
{1.0, 0.0, 0.1, 1.0},
{0.0, 1.0, 0.0, 1.0},
{0.0, 0.0, 1.0, 1.0},
};
#endif
char *tempname;
user_data = g_malloc(sizeof(user_data_t));
COPY_ADDRESS(&(user_data->ip_src_fwd), ip_src_fwd);
user_data->port_src_fwd = port_src_fwd;
COPY_ADDRESS(&(user_data->ip_dst_fwd), ip_dst_fwd);
user_data->port_dst_fwd = port_dst_fwd;
COPY_ADDRESS(&(user_data->ip_src_rev), ip_src_rev);
user_data->port_src_rev = port_src_rev;
COPY_ADDRESS(&(user_data->ip_dst_rev), ip_dst_rev);
user_data->port_dst_rev = port_dst_rev;
fd = create_tempfile(&tempname, "wireshark_iax2_f");
if (fd < 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create temporary file for IAX2 analysis:\n%s.",
g_strerror(errno));
g_free(user_data);
return;
}
user_data->f_tempname = g_strdup(tempname);
ws_close(fd);
fd = create_tempfile(&tempname, "wireshark_iax2_r");
if (fd < 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create temporary file for IAX2 analysis:\n%s.",
g_strerror(errno));
g_free(user_data->f_tempname);
g_free(user_data);
return;
}
user_data->r_tempname = g_strdup(tempname);
ws_close(fd);
user_data->forward.saveinfo.fp = NULL;
user_data->reversed.saveinfo.fp = NULL;
user_data->dlg.save_voice_as_w = NULL;
user_data->dlg.save_csv_as_w = NULL;
user_data->dlg.dialog_graph.window = NULL;
user_data->dlg.dialog_graph.needs_redraw=TRUE;
user_data->dlg.dialog_graph.interval_index=DEFAULT_TICK_INTERVAL_VALUES_INDEX;
user_data->dlg.dialog_graph.interval=tick_interval_values[DEFAULT_TICK_INTERVAL_VALUES_INDEX];
user_data->dlg.dialog_graph.draw_area=NULL;
#if GTK_CHECK_VERSION(2,22,0)
user_data->dlg.dialog_graph.surface=NULL;
#else
user_data->dlg.dialog_graph.pixmap=NULL;
#endif
user_data->dlg.dialog_graph.scrollbar=NULL;
user_data->dlg.dialog_graph.scrollbar_adjustment=NULL;
user_data->dlg.dialog_graph.surface_width=500;
user_data->dlg.dialog_graph.surface_height=200;
user_data->dlg.dialog_graph.pixels_per_tick_index=DEFAULT_PIXELS_PER_TICK_INDEX;
user_data->dlg.dialog_graph.pixels_per_tick=pixels_per_tick[DEFAULT_PIXELS_PER_TICK_INDEX];
user_data->dlg.dialog_graph.max_y_units_index=AUTO_MAX_YSCALE_INDEX;
user_data->dlg.dialog_graph.max_y_units=AUTO_MAX_YSCALE;
user_data->dlg.dialog_graph.last_interval=0xffffffff;
user_data->dlg.dialog_graph.max_interval=0;
user_data->dlg.dialog_graph.num_items=0;
user_data->dlg.dialog_graph.start_time = -1;
for(i=0;i<MAX_GRAPHS;i++){
user_data->dlg.dialog_graph.graph[i].color.pixel=0;
user_data->dlg.dialog_graph.graph[i].color.red=col[i].red;
user_data->dlg.dialog_graph.graph[i].color.green=col[i].green;
user_data->dlg.dialog_graph.graph[i].color.blue=col[i].blue;
#if GTK_CHECK_VERSION(3,0,0)
user_data->dlg.dialog_graph.graph[i].rgba_color.red=rgba_col[i].red;
user_data->dlg.dialog_graph.graph[i].rgba_color.green=rgba_col[i].green;
user_data->dlg.dialog_graph.graph[i].rgba_color.blue=rgba_col[i].blue;
user_data->dlg.dialog_graph.graph[i].rgba_color.alpha=rgba_col[i].alpha;
#endif
user_data->dlg.dialog_graph.graph[i].display=TRUE;
user_data->dlg.dialog_graph.graph[i].display_button=NULL;
user_data->dlg.dialog_graph.graph[i].ud=user_data;
}
create_iax2_dialog(user_data);
on_refresh_bt_clicked(NULL, user_data);
}
void iax2_analysis_cb(GtkAction *action _U_, gpointer user_data _U_)
{
address ip_src_fwd;
guint16 port_src_fwd;
address ip_dst_fwd;
guint16 port_dst_fwd;
address ip_src_rev;
guint16 port_src_rev;
address ip_dst_rev;
guint16 port_dst_rev;
gchar filter_text[256];
dfilter_t *sfcode;
capture_file *cf;
epan_dissect_t edt;
gboolean frame_matched;
frame_data *fdata;
GList *strinfo_list;
GList *filtered_list = NULL;
rtp_stream_info_t *strinfo;
guint nfound;
g_strlcpy(filter_text,"iax2 && (ip || ipv6)",256);
if (!dfilter_compile(filter_text, &sfcode)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", dfilter_error_msg);
return;
}
cf = &cfile;
fdata = cf->current_frame;
if (fdata == NULL)
return;
if (!cf_read_frame(cf, fdata))
return;
epan_dissect_init(&edt, TRUE, FALSE);
epan_dissect_prime_dfilter(&edt, sfcode);
epan_dissect_run(&edt, &cf->pseudo_header, cf->pd, fdata, NULL);
frame_matched = dfilter_apply_edt(sfcode, &edt);
if (frame_matched != 1) {
epan_dissect_cleanup(&edt);
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"You didn't choose a IAX2 packet!");
return;
}
if (edt.pi.circuit_id == 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Please select a Call packet!");
return;
}
COPY_ADDRESS(&(ip_src_fwd), &(edt.pi.src))
COPY_ADDRESS(&(ip_dst_fwd), &(edt.pi.dst))
port_src_fwd = edt.pi.srcport;
port_dst_fwd = edt.pi.destport;
COPY_ADDRESS(&(ip_src_rev), &(edt.pi.dst))
COPY_ADDRESS(&(ip_dst_rev), &(edt.pi.src))
port_src_rev = edt.pi.destport;
port_dst_rev = edt.pi.srcport;
rtpstream_scan();
nfound = 0;
strinfo_list = g_list_first(rtpstream_get_info()->strinfo_list);
while (strinfo_list)
{
strinfo = (rtp_stream_info_t*)(strinfo_list->data);
if (ADDRESSES_EQUAL(&(strinfo->src_addr),&(ip_src_fwd))
&& strinfo->src_port==port_src_fwd
&& ADDRESSES_EQUAL(&(strinfo->dest_addr),&(ip_dst_fwd))
&& strinfo->dest_port==port_dst_fwd)
{
filtered_list = g_list_prepend(filtered_list, strinfo);
}
if (ADDRESSES_EQUAL(&(strinfo->src_addr),&(ip_src_rev))
&& strinfo->src_port==port_src_rev
&& ADDRESSES_EQUAL(&(strinfo->dest_addr),&(ip_dst_rev))
&& strinfo->dest_port==port_dst_rev)
{
++nfound;
filtered_list = g_list_append(filtered_list, strinfo);
}
strinfo_list = g_list_next(strinfo_list);
}
if (nfound>1) {
rtpstream_dlg_show(filtered_list);
return;
}
else {
iax2_analysis(
&ip_src_fwd,
port_src_fwd,
&ip_dst_fwd,
port_dst_fwd,
&ip_src_rev,
port_src_rev,
&ip_dst_rev,
port_dst_rev
);
}
}
static void
iax2_analysis_init(const char *dummy _U_,void* userdata _U_)
{
iax2_analysis_cb(NULL, NULL);
}
void
register_tap_listener_iax2_analysis(void)
{
register_stat_cmd_arg("IAX2", iax2_analysis_init,NULL);
}
