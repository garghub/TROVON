void register_conversation_filter(const char *proto_name, const char *display_name,
is_filter_valid_func is_filter_valid, build_filter_string_func build_filter_string) {
conversation_filter_t *entry;
entry = (conversation_filter_t *)g_malloc(sizeof(conversation_filter_t));
entry->proto_name = proto_name;
entry->display_name = display_name;
entry->is_filter_valid = is_filter_valid;
entry->build_filter_string = build_filter_string;
conv_filter_list = g_list_append(conv_filter_list, entry);
}
struct conversation_filter_s* find_conversation_filter(const char *name)
{
GList *list_entry = conv_filter_list;
conversation_filter_t* filter;
while (list_entry != NULL) {
filter = (conversation_filter_t*)list_entry->data;
if (!strcmp(filter->proto_name, name))
return filter;
list_entry = g_list_next(list_entry);
}
return NULL;
}
