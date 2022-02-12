void
apply_selected_filter (guint callback_action, const char *filter)
{
int action, type;
char *str = NULL;
const char *current_filter;
action = FILTER_ACTION(callback_action);
type = FILTER_ACTYPE(callback_action);
current_filter = gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
switch(type){
case ACTYPE_SELECTED:
str = g_strdup_printf("%s", filter);
break;
case ACTYPE_NOT_SELECTED:
str = g_strdup_printf("!(%s)", filter);
break;
case ACTYPE_AND_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
str = g_strdup_printf("%s", filter);
else
str = g_strdup_printf("(%s) && (%s)", current_filter, filter);
break;
case ACTYPE_OR_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
str = g_strdup_printf("%s", filter);
else
str = g_strdup_printf("(%s) || (%s)", current_filter, filter);
break;
case ACTYPE_AND_NOT_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
str = g_strdup_printf("!(%s)", filter);
else
str = g_strdup_printf("(%s) && !(%s)", current_filter, filter);
break;
case ACTYPE_OR_NOT_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
str = g_strdup_printf("!(%s)", filter);
else
str = g_strdup_printf("(%s) || !(%s)", current_filter, filter);
break;
}
switch(action){
case ACTION_MATCH:
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), str);
main_filter_packets(&cfile, str, FALSE);
gdk_window_raise(gtk_widget_get_window(top_level));
break;
case ACTION_PREPARE:
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), str);
break;
case ACTION_FIND_FRAME:
find_frame_with_filter(str);
break;
case ACTION_FIND_NEXT:
cf_find_packet_dfilter_string(&cfile, str, SD_FORWARD);
break;
case ACTION_FIND_PREVIOUS:
cf_find_packet_dfilter_string(&cfile, str, SD_BACKWARD);
break;
case ACTION_COLORIZE:
color_display_with_filter(str);
break;
}
g_free (str);
}
