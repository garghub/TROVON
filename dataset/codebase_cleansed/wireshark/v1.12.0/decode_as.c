void register_decode_as(decode_as_t* reg)
{
DISSECTOR_ASSERT(reg->populate_list);
DISSECTOR_ASSERT(reg->reset_value);
DISSECTOR_ASSERT(reg->change_value);
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
gboolean decode_as_default_reset(const char *name, const gpointer pattern)
{
dissector_reset_uint(name, GPOINTER_TO_UINT(pattern));
return TRUE;
}
gboolean decode_as_default_change(const char *name, const gpointer pattern, gpointer handle, gchar* list_name _U_)
{
dissector_handle_t* dissector = (dissector_handle_t*)handle;
if (dissector != NULL)
dissector_change_uint(name, GPOINTER_TO_UINT(pattern), *dissector);
return TRUE;
}
