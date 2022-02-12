void
time_shift_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *main_vb, *main_hb, *label,
*types_frame, *types_vb,
*timeshift_offset_hb,
*timeshift_offset_text_box,
*settime_time_hb,
*settime_packetnumber_text_box,
*settime_time_text_box,
*adjtime_offset_hb,
*adjtime_packetnumber1_text_box,
*adjtime_packetnumber2_text_box,
*adjtime_time1_text_box,
*adjtime_time2_text_box,
*undo_offset_hb,
*undo_type_hb,
*timeshift_rb, *settime_rb,
*adjtime_rb, *undo_rb,
*bbox, *apply_bt, *close_bt, *help_bt;
if (time_shift_frame_w != NULL) {
reactivate_window(time_shift_frame_w);
return;
}
time_shift_frame_w = dlg_window_new("Wireshark: Time Shift");
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(time_shift_frame_w), main_vb);
gtk_widget_show(main_vb);
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), main_hb);
gtk_widget_show(main_hb);
types_frame = gtk_frame_new(NULL);
gtk_box_pack_start(GTK_BOX(main_hb), types_frame, TRUE, TRUE, 0);
gtk_widget_show(types_frame);
types_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(types_vb), 3);
gtk_container_add(GTK_CONTAINER(types_frame), types_vb);
gtk_widget_show(types_vb);
timeshift_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), timeshift_offset_hb, FALSE, FALSE, 0);
gtk_widget_show(timeshift_offset_hb);
timeshift_rb = gtk_radio_button_new_with_label (NULL, "Shift all packets");
gtk_box_pack_start(GTK_BOX(timeshift_offset_hb), timeshift_rb, TRUE, TRUE, 0);
gtk_widget_show(timeshift_rb);
gtk_widget_set_tooltip_text(timeshift_rb, "Shift the time on the frames.");
timeshift_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), timeshift_offset_hb, FALSE, FALSE, 0);
gtk_widget_show(timeshift_offset_hb);
label = gtk_label_new("Time offset in the format [+-][[hh:]mm:]ss[.ddd]");
gtk_box_pack_start(GTK_BOX(timeshift_offset_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
timeshift_offset_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(timeshift_offset_hb), timeshift_offset_text_box,
TRUE, TRUE, 0);
gtk_widget_show(timeshift_offset_text_box);
gtk_widget_set_tooltip_text(timeshift_offset_text_box,
"Enter the time to shift here. The format is "
"[+-][[hh:]mm:]ss.[.ddddddddd].");
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), main_hb);
gtk_widget_show(main_hb);
types_frame = gtk_frame_new(NULL);
gtk_box_pack_start(GTK_BOX(main_hb), types_frame, TRUE, TRUE, 0);
gtk_widget_show(types_frame);
types_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(types_vb), 3);
gtk_container_add(GTK_CONTAINER(types_frame), types_vb);
gtk_widget_show(types_vb);
settime_time_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), settime_time_hb, FALSE,
FALSE, 0);
gtk_widget_show(settime_time_hb);
settime_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(
GTK_RADIO_BUTTON(timeshift_rb)), "Set packet to time");
gtk_box_pack_start(GTK_BOX(settime_time_hb), settime_rb, TRUE, TRUE, 0);
gtk_widget_show(settime_rb);
gtk_widget_set_tooltip_text(settime_rb,
"Set the time of a certain frame and adjust the rest of the frames "
"automatically.");
settime_time_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), settime_time_hb, FALSE,
FALSE, 0);
gtk_widget_show(settime_time_hb);
label = gtk_label_new("Packet number");
gtk_box_pack_start(GTK_BOX(settime_time_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
settime_packetnumber_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(settime_time_hb), settime_packetnumber_text_box,
TRUE, TRUE, 0);
gtk_entry_set_text(GTK_ENTRY(settime_packetnumber_text_box), "");
gtk_widget_show(settime_packetnumber_text_box);
gtk_widget_set_tooltip_text(settime_packetnumber_text_box,
"The frame which will be set to the time.");
settime_time_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), settime_time_hb, FALSE, FALSE,
0);
gtk_widget_show(settime_time_hb);
label = gtk_label_new("Set packet to time [YYYY-MM-DD] hh:mm:ss[.ddd]");
gtk_box_pack_start(GTK_BOX(settime_time_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
settime_time_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(settime_time_hb), settime_time_text_box, TRUE,
TRUE, 0);
gtk_widget_show(settime_time_text_box);
gtk_widget_set_tooltip_text(settime_time_text_box,
"The time for the frame in the format of [YYYY-MM-DD] "
"hh:mm:ss[.ddddddddd]");
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), main_hb);
gtk_widget_show(main_hb);
types_frame = gtk_frame_new(NULL);
gtk_box_pack_start(GTK_BOX(main_hb), types_frame, TRUE, TRUE, 0);
gtk_widget_show(types_frame);
types_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(types_vb), 3);
gtk_container_add(GTK_CONTAINER(types_frame), types_vb);
gtk_widget_show(types_vb);
adjtime_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), adjtime_offset_hb, FALSE, FALSE, 0);
gtk_widget_show(adjtime_offset_hb);
adjtime_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(
GTK_RADIO_BUTTON(timeshift_rb)), "Set packets to time and extrapolate");
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), adjtime_rb, TRUE, TRUE, 0);
gtk_widget_show(adjtime_rb);
gtk_widget_set_tooltip_text(adjtime_rb,
"Set the time of two frames and adjust the rest of the frames "
"automatically.");
adjtime_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), adjtime_offset_hb, FALSE, FALSE, 0);
gtk_widget_show(adjtime_offset_hb);
label = gtk_label_new("Packet number");
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
adjtime_packetnumber1_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), adjtime_packetnumber1_text_box,
TRUE, TRUE, 0);
gtk_entry_set_text(GTK_ENTRY(adjtime_packetnumber1_text_box), "");
gtk_widget_show(adjtime_packetnumber1_text_box);
gtk_widget_set_tooltip_text(adjtime_packetnumber1_text_box,
"The frame which will be set to the time.");
adjtime_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), adjtime_offset_hb, FALSE, FALSE,
0);
gtk_widget_show(adjtime_offset_hb);
label = gtk_label_new("Set packet to time [YYYY-MM-DD] hh:mm:ss[.ddd]");
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
adjtime_time1_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), adjtime_time1_text_box, TRUE,
TRUE, 0);
gtk_entry_set_text(GTK_ENTRY(adjtime_time1_text_box), "");
gtk_widget_show(adjtime_time1_text_box);
gtk_widget_set_tooltip_text(adjtime_time1_text_box,
"The time for the frame in the format of [YYYY-MM-DD] "
"hh:mm:ss[.ddddddddd]");
adjtime_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), adjtime_offset_hb, FALSE,
FALSE, 0);
gtk_widget_show(adjtime_offset_hb);
label = gtk_label_new("Packet number");
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
adjtime_packetnumber2_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), adjtime_packetnumber2_text_box,
TRUE, TRUE, 0);
gtk_entry_set_text(GTK_ENTRY(adjtime_packetnumber2_text_box), "");
gtk_widget_show(adjtime_packetnumber2_text_box);
gtk_widget_set_tooltip_text(adjtime_packetnumber2_text_box,
"The frame which will be set to the time.");
adjtime_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), adjtime_offset_hb, FALSE, FALSE,
0);
gtk_widget_show(adjtime_offset_hb);
label = gtk_label_new("Set packet to time [YYYY-MM-DD] hh:mm:ss[.ddd]");
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), label, FALSE, FALSE, 0);
gtk_widget_show(label);
adjtime_time2_text_box = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(adjtime_offset_hb), adjtime_time2_text_box, TRUE,
TRUE, 0);
gtk_entry_set_text(GTK_ENTRY(adjtime_time2_text_box), "");
gtk_widget_show(adjtime_time2_text_box);
gtk_widget_set_tooltip_text(adjtime_time2_text_box,
"The time for the frame in the format of [YYYY-MM-DD] "
"hh:mm:ss[.ddddddddd]");
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(main_vb), main_hb);
gtk_widget_show(main_hb);
types_frame = gtk_frame_new(NULL);
gtk_box_pack_start(GTK_BOX(main_hb), types_frame, TRUE, TRUE, 0);
gtk_widget_show(types_frame);
types_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(types_vb), 3);
gtk_container_add(GTK_CONTAINER(types_frame), types_vb);
gtk_widget_show(types_vb);
undo_type_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(types_vb), undo_type_hb);
gtk_widget_show(undo_type_hb);
undo_offset_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(types_vb), undo_offset_hb, FALSE,
FALSE, 0);
gtk_widget_show(undo_offset_hb);
undo_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(
GTK_RADIO_BUTTON(timeshift_rb)), "Undo all shifts");
gtk_box_pack_start(GTK_BOX(undo_offset_hb), undo_rb, TRUE, TRUE, 0);
gtk_widget_show(undo_rb);
gtk_widget_set_tooltip_text(undo_rb,
"Undo all the Time Shift offsets on the frames.");
bbox = dlg_button_row_new(GTK_STOCK_APPLY, GTK_STOCK_CLOSE, GTK_STOCK_HELP,
NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
apply_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(time_shift_apply_cb),
time_shift_frame_w);
gtk_widget_set_tooltip_text(apply_bt,
"Apply the Time Shift options to the frame data.");
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
g_signal_connect(close_bt, "clicked", G_CALLBACK(time_shift_close_cb),
time_shift_frame_w);
gtk_widget_set_tooltip_text(close_bt, "Close this dialogbox.");
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb),
(gpointer)HELP_TIME_SHIFT_DIALOG);
gtk_widget_set_tooltip_text(help_bt,
"Help on how the Time Shift feature works.");
g_object_set_data(G_OBJECT(time_shift_frame_w), E_TIMESHIFT_SELECT,
timeshift_rb);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_TIMESHIFT_OFFSET_KEY,
timeshift_offset_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_SETTIME_SELECT, settime_rb);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_SETTIME_TIME_KEY,
settime_time_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_SETTIME_PACKETNUMBER_KEY,
settime_packetnumber_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_ADJTIME_SELECT, adjtime_rb);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_ADJTIME_TIME1_KEY,
adjtime_time1_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_ADJTIME_PACKETNUMBER1_KEY,
adjtime_packetnumber1_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_ADJTIME_TIME2_KEY,
adjtime_time2_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_ADJTIME_PACKETNUMBER2_KEY,
adjtime_packetnumber2_text_box);
g_object_set_data(G_OBJECT(time_shift_frame_w), E_UNDO_SELECT, undo_rb);
dlg_set_activate(timeshift_offset_text_box, apply_bt);
gtk_widget_grab_focus(timeshift_offset_text_box);
g_signal_connect(time_shift_frame_w, "delete_event",
G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(time_shift_frame_w, "destroy",
G_CALLBACK(time_shift_frame_destroy_cb), NULL);
gtk_widget_show(time_shift_frame_w);
window_present(time_shift_frame_w);
}
static void
error_message(const gchar *msg)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", msg);
}
static void
time_shift_apply_cb(GtkWidget *ok_bt _U_, GtkWindow *parent_w)
{
GtkWidget *flag_rb;
if (cfile.state == FILE_CLOSED) {
return;
}
if (cfile.state == FILE_READ_IN_PROGRESS) {
error_message("The Time Shift functions are not available on live captures.");
return;
}
flag_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_TIMESHIFT_SELECT);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(flag_rb)) == TRUE) {
action_timeshift(parent_w);
return;
}
flag_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_SETTIME_SELECT);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(flag_rb)) == TRUE) {
action_settime(parent_w);
return;
}
flag_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_ADJTIME_SELECT);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(flag_rb)) == TRUE) {
action_adjtime(parent_w);
return;
}
flag_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_UNDO_SELECT);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(flag_rb)) == TRUE) {
action_undo(parent_w);
return;
}
}
static int
action_timeshift(GtkWindow *parent_w)
{
GtkWidget *offset_te;
const gchar *offset_text;
gchar *poffset_text;
nstime_t offset;
long double offset_float = 0;
guint32 i;
frame_data *fd;
int neg;
int h, m;
long double f;
offset_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_TIMESHIFT_OFFSET_KEY);
offset_text = gtk_entry_get_text(GTK_ENTRY(offset_te));
poffset_text = (gchar *)offset_text;
while (isspace(poffset_text[0]))
++poffset_text;
neg = FALSE;
if (poffset_text[0] == '-') {
neg = TRUE;
poffset_text++;
}
if (poffset_text[0] == '\0')
return(1);
h = m = 0;
f = 0.0;
if (sscanf(poffset_text, "%d:%d:%Lf", &h, &m, &f) == 3) {
CHECK_HOUR(h);
CHECK_MINUTE(m);
CHECK_SEC_DEC(f);
} else if (sscanf(poffset_text, "%d:%Lf", &m, &f) == 2) {
CHECK_MINUTE(m);
CHECK_SEC_DEC(f);
} else if (sscanf(poffset_text, "%Lf", &f) == 1) {
CHECK_SEC_DEC(f);
} else {
error_message("Could not parse the time: Expected ((hh:)mm:)ss.(dec).");
return(1);
}
if (offset_float == 0)
return(1);
nstime_set_zero(&offset);
offset.secs = (time_t)floorl(offset_float);
offset_float -= offset.secs;
offset.nsecs = (int)(offset_float * 1000000000);
if ((fd = frame_data_sequence_find(cfile.frames, 1)) == NULL)
return(1);
modify_time_init(fd);
for (i = 1; i <= cfile.count; i++) {
if ((fd = frame_data_sequence_find(cfile.frames, i)) == NULL)
continue;
modify_time_perform(fd, neg, &offset, SHIFT_KEEPOFFSET);
}
new_packet_list_queue_draw();
return(0);
}
static int
timestring2nstime(const gchar *ts, nstime_t *packettime, nstime_t *nstime)
{
gchar *pts;
int h, m, Y, M, D;
long double f;
struct tm tm, *tmptm;
time_t tt;
long double offset_float = 0;
pts = (gchar *)ts;
while (isspace(pts[0]))
++pts;
if (pts[0] == '\0')
return(1);
if (sscanf(pts, "%d-%d-%d %d:%d:%Lf", &Y, &M, &D, &h, &m, &f) == 6) {
CHECK_YEARS(Y);
CHECK_MONTHS(M);
CHECK_DAYS(D);
CHECK_HOURS(h);
CHECK_MINUTE(m);
CHECK_SEC_DEC(f);
} else if (sscanf(pts, "%d:%d:%Lf", &h, &m, &f) == 3) {
Y = M = D = 0;
CHECK_HOUR(h);
CHECK_MINUTE(m);
CHECK_SEC_DEC(f);
} else {
error_message("Could not parse the time: Expected (YYYY-MM-DD) "
"hh:mm:ss(.dec)");
return(1);
}
tmptm = localtime(&(packettime->secs));
if (tmptm) {
tm = *tmptm;
} else {
memset (&tm, 0, sizeof (tm));
}
if (Y != 0) {
tm.tm_year = Y - 1900;
tm.tm_mon = M - 1;
tm.tm_mday = D;
}
tm.tm_hour = h;
tm.tm_min = m;
tm.tm_sec = (int)floorl(f);
tt = mktime(&tm);
if (tt == -1) {
error_message("mktime went wrong. Was the time invalid?");
return(1);
}
nstime->secs = tt;
f -= tm.tm_sec;
nstime->nsecs = (int)(f * 1000000000);
return(0);
}
static void
action_settime(GtkWindow *parent_w)
{
GtkWidget *packetnumber_te;
const gchar *packetnumber_text;
long packetnumber;
GtkWidget *time_te;
const gchar *time_text;
nstime_t settime, difftime, packettime;
frame_data *fd, *packetfd;
guint32 i;
packetnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_SETTIME_PACKETNUMBER_KEY);
packetnumber_text = gtk_entry_get_text(GTK_ENTRY(packetnumber_te));
packetnumber = strtol((char *)packetnumber_text, NULL, 10);
time_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_SETTIME_TIME_KEY);
time_text = gtk_entry_get_text(GTK_ENTRY(time_te));
if ((packetfd = frame_data_sequence_find(cfile.frames, packetnumber)) == NULL)
return;
nstime_delta(&packettime, &(packetfd->abs_ts), &(packetfd->shift_offset));
if (timestring2nstime(time_text, &packettime, &settime) != 0)
return;
nstime_delta(&difftime, &settime, &packettime);
if ((fd = frame_data_sequence_find(cfile.frames, 1)) == NULL)
return;
modify_time_init(fd);
for (i = 1; i <= cfile.count; i++) {
if ((fd = frame_data_sequence_find(cfile.frames, i)) == NULL)
continue;
modify_time_perform(fd, SHIFT_POS, &difftime, SHIFT_SETTOZERO);
}
new_packet_list_queue_draw();
}
static void
calcNT3(nstime_t *OT1, nstime_t *OT3, nstime_t *NT1, nstime_t *NT3,
nstime_t *deltaOT, nstime_t *deltaNT)
{
long double fnt, fot, f, secs, nsecs;
fnt = (long double)deltaNT->secs + (deltaNT->nsecs / 1000000000.0L);
fot = (long double)deltaOT->secs + (deltaOT->nsecs / 1000000000.0L);
f = fnt / fot;
nstime_copy(NT3, OT3);
nstime_subtract(NT3, OT1);
secs = f * (long double)NT3->secs;
nsecs = f * (long double)NT3->nsecs;
nsecs += (secs - floorl(secs)) * 1000000000.0L;
while (nsecs > 1000000000L) {
secs += 1;
nsecs -= 1000000000L;
}
while (nsecs < 0) {
secs -= 1;
nsecs += 1000000000L;
}
NT3->secs = (time_t)secs;
NT3->nsecs = (int)nsecs;
nstime_add(NT3, NT1);
}
static void
action_adjtime(GtkWindow *parent_w _U_)
{
GtkWidget *packetnumber_te;
const gchar *packetnumber_text;
long packetnumber1, packetnumber2;
GtkWidget *time_te;
const gchar *time1_text, *time2_text;
nstime_t nt1, nt2, ot1, ot2, nt3;
nstime_t dnt, dot, d3t;
frame_data *fd, *packet1fd, *packet2fd;
guint32 i;
packetnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_ADJTIME_PACKETNUMBER1_KEY);
packetnumber_text = gtk_entry_get_text(GTK_ENTRY(packetnumber_te));
packetnumber1 = strtol((char *)packetnumber_text, NULL, 10);
packetnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_ADJTIME_PACKETNUMBER2_KEY);
packetnumber_text = gtk_entry_get_text(GTK_ENTRY(packetnumber_te));
packetnumber2 = strtol((char *)packetnumber_text, NULL, 10);
time_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_ADJTIME_TIME1_KEY);
time1_text = gtk_entry_get_text(GTK_ENTRY(time_te));
time_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_ADJTIME_TIME2_KEY);
time2_text = gtk_entry_get_text(GTK_ENTRY(time_te));
if ((packet1fd = frame_data_sequence_find(cfile.frames, packetnumber1)) == NULL)
return;
nstime_copy(&ot1, &(packet1fd->abs_ts));
nstime_subtract(&ot1, &(packet1fd->shift_offset));
if (timestring2nstime(time1_text, &ot1, &nt1) != 0)
return;
if ((packet2fd = frame_data_sequence_find(cfile.frames, packetnumber2)) == NULL)
return;
nstime_copy(&ot2, &(packet2fd->abs_ts));
nstime_subtract(&ot2, &(packet2fd->shift_offset));
if (timestring2nstime(time2_text, &ot2, &nt2) != 0)
return;
nstime_copy(&dot, &ot2);
nstime_subtract(&dot, &ot1);
nstime_copy(&dnt, &nt2);
nstime_subtract(&dnt, &nt1);
if ((fd = frame_data_sequence_find(cfile.frames, 1)) == NULL)
return;
modify_time_init(fd);
for (i = 1; i <= cfile.count; i++) {
if ((fd = frame_data_sequence_find(cfile.frames, i)) == NULL)
continue;
nstime_subtract(&(fd->abs_ts), &(fd->shift_offset));
nstime_set_zero(&(fd->shift_offset));
calcNT3(&ot1, &(fd->abs_ts), &nt1, &nt3, &dot, &dnt);
nstime_copy(&d3t, &nt3);
nstime_subtract(&d3t, &(fd->abs_ts));
modify_time_perform(fd, SHIFT_POS, &d3t, SHIFT_SETTOZERO);
}
new_packet_list_queue_draw();
}
static void
action_undo(GtkWindow *parent_w _U_)
{
guint32 i;
frame_data *fd;
nstime_t nulltime;
nulltime.secs = nulltime.nsecs = 0;
if ((fd = frame_data_sequence_find(cfile.frames, 1)) == NULL)
return;
modify_time_init(fd);
for (i = 1; i <= cfile.count; i++) {
if ((fd = frame_data_sequence_find(cfile.frames, i)) == NULL)
continue;
modify_time_perform(fd, SHIFT_NEG, &nulltime, SHIFT_SETTOZERO);
}
new_packet_list_queue_draw();
}
static void
time_shift_close_cb(GtkWidget *close_bt _U_, gpointer parent_w _U_)
{
gtk_grab_remove(GTK_WIDGET(parent_w));
window_destroy(GTK_WIDGET(parent_w));
}
static void
time_shift_frame_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
time_shift_frame_w = NULL;
}
static void
modify_time_init(frame_data *fd)
{
modify_time_perform(fd, SHIFT_NEG, NULL, SHIFT_KEEPOFFSET);
}
static void
modify_time_perform(frame_data *fd, int neg, nstime_t *offset, int settozero)
{
static frame_data *first_packet = NULL;
static frame_data *lastdisplayed_packet = NULL;
static frame_data *prevcaptured_packet = NULL;
static nstime_t nulltime;
if (offset == NULL) {
first_packet = fd;
lastdisplayed_packet = NULL;
prevcaptured_packet = NULL;
nulltime.secs = nulltime.nsecs = 0;
return;
}
if (first_packet == NULL) {
fprintf(stderr, "modify_time_perform: not initialized?\n");
return;
}
if (settozero == SHIFT_SETTOZERO) {
nstime_subtract(&(fd->abs_ts), &(fd->shift_offset));
nstime_copy(&(fd->shift_offset), &nulltime);
}
if (neg == SHIFT_POS) {
nstime_add(&(fd->abs_ts), offset);
nstime_add(&(fd->shift_offset), offset);
} else if (neg == SHIFT_NEG) {
nstime_subtract(&(fd->abs_ts), offset);
nstime_subtract(&(fd->shift_offset), offset);
} else {
fprintf(stderr, "modify_time_perform: neg = %d?\n", neg);
}
if (first_packet != NULL) {
nstime_copy(&(fd->rel_ts), &(fd->abs_ts));
nstime_subtract(&(fd->rel_ts), &(first_packet->abs_ts));
} else
nstime_copy(&(fd->rel_ts), &nulltime);
if (prevcaptured_packet != NULL) {
nstime_copy(&(fd->del_cap_ts), &(fd->abs_ts));
nstime_subtract(&(fd->del_cap_ts), &(prevcaptured_packet->abs_ts));
} else
nstime_copy(&(fd->del_cap_ts), &nulltime);
if (lastdisplayed_packet != NULL) {
nstime_copy(&(fd->del_dis_ts), &(fd->abs_ts));
nstime_subtract(&(fd->del_dis_ts), &(lastdisplayed_packet->abs_ts));
} else
nstime_copy(&(fd->del_dis_ts), &nulltime);
prevcaptured_packet = fd;
if (fd->flags.passed_dfilter)
lastdisplayed_packet = fd;
}
