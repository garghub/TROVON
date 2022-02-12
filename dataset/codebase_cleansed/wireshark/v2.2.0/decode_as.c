void register_decode_as(decode_as_t* reg)
{
dissector_table_t decode_table;
DISSECTOR_ASSERT(reg->populate_list);
DISSECTOR_ASSERT(reg->reset_value);
DISSECTOR_ASSERT(reg->change_value);
decode_table = find_dissector_table(reg->table_name);
if (decode_table != NULL)
{
dissector_table_allow_decode_as(decode_table);
}
decode_as_list = g_list_append(decode_as_list, reg);
}
static void
decode_proto_add_to_list (const gchar *table_name, gpointer value, gpointer user_data)
{
struct decode_as_default_populate* populate = (struct decode_as_default_populate*)user_data;
const gchar *proto_name;
gint i;
dissector_handle_t handle;
handle = (dissector_handle_t)value;
proto_name = dissector_handle_get_short_name(handle);
i = dissector_handle_get_protocol_index(handle);
if (i >= 0 && !proto_is_protocol_enabled(find_protocol_by_id(i)))
return;
populate->add_to_list(table_name, proto_name, value, populate->ui_element);
}
void decode_as_default_populate_list(const gchar *table_name, decode_as_add_to_list_func add_to_list, gpointer ui_element)
{
struct decode_as_default_populate populate;
populate.add_to_list = add_to_list;
populate.ui_element = ui_element;
dissector_table_foreach_handle(table_name, decode_proto_add_to_list, &populate);
}
gboolean decode_as_default_reset(const gchar *name, gconstpointer pattern)
{
switch (get_dissector_table_selector_type(name)) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
dissector_reset_uint(name, GPOINTER_TO_UINT(pattern));
return TRUE;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
dissector_reset_string(name, (!pattern)?"":(gchar *) pattern);
return TRUE;
default:
return FALSE;
};
return TRUE;
}
gboolean decode_as_default_change(const gchar *name, gconstpointer pattern, gpointer handle, gchar *list_name _U_)
{
dissector_handle_t* dissector = (dissector_handle_t*)handle;
if (dissector != NULL) {
switch (get_dissector_table_selector_type(name)) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
dissector_change_uint(name, GPOINTER_TO_UINT(pattern), *dissector);
return TRUE;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
dissector_change_string(name, (!pattern)?"":(gchar *) pattern, *dissector);
return TRUE;
default:
return FALSE;
};
return FALSE;
}
return TRUE;
}
