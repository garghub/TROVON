static void adjust_menus(void) {
if(history_current) {
main_set_for_packet_history(
(g_list_previous(history_current) != NULL),
(g_list_next(history_current) != NULL));
} else {
main_set_for_packet_history(FALSE, FALSE);
}
}
static void clear_list(GList *current) {
GList *next_packet;
while(current) {
next_packet = g_list_next(current);
history_list = g_list_remove(history_list, current->data);
current = next_packet;
}
}
void packet_history_add(gint row) {
if(row < 1) {
return;
}
if(ignore_jump) {
return;
}
if (history_current) {
clear_list(g_list_next(history_current));
if(GPOINTER_TO_INT(history_current->data) == row) {
adjust_menus();
return;
}
}
history_list = g_list_append(history_list, GINT_TO_POINTER(row));
history_current = g_list_last(history_list);
adjust_menus();
}
void packet_history_clear(void) {
clear_list(history_list);
history_current = NULL;
packet_history_add(0);
adjust_menus();
}
static void packet_history_back(void) {
GList *previous;
if(history_current) {
previous = g_list_previous(history_current);
if(previous) {
history_current = previous;
ignore_jump = TRUE;
cf_goto_frame(&cfile, GPOINTER_TO_INT(previous->data));
ignore_jump = FALSE;
}
}
adjust_menus();
}
static void packet_history_forward(void) {
GList *next;
if(history_current) {
next = g_list_next(history_current);
if(next) {
history_current = next;
ignore_jump = TRUE;
cf_goto_frame(&cfile, GPOINTER_TO_INT(next->data));
ignore_jump = FALSE;
}
}
adjust_menus();
}
void history_forward_cb(GtkWidget *widget _U_, gpointer data _U_) {
packet_history_forward();
}
void history_back_cb(GtkWidget *widget _U_, gpointer data _U_) {
packet_history_back();
}
