void register_dissector_filter(const char *name, is_filter_valid_func is_filter_valid, build_filter_string_func build_filter_string) {
dissector_filter_t *entry;
entry = (dissector_filter_t *)g_malloc(sizeof(dissector_filter_t));
entry->name = name;
entry->is_filter_valid = is_filter_valid;
entry->build_filter_string = build_filter_string;
dissector_filter_list = g_list_append(dissector_filter_list, entry);
}
