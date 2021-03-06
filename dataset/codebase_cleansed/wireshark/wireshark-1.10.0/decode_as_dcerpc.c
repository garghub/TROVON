static void
decode_dcerpc_inject_binding(gpointer data, gpointer user_data _U_)
{
dcerpc_add_conv_to_bind_table((decode_dcerpc_bind_values_t *) data);
}
static void
decode_dcerpc_inject_bindings(gpointer data _U_) {
g_slist_foreach(decode_dcerpc_bindings, decode_dcerpc_inject_binding, NULL );
}
void
decode_dcerpc_init(void) {
GHook* hook_init_proto;
hook_init_proto = g_hook_alloc(&dcerpc_hooks_init_protos);
hook_init_proto->func = decode_dcerpc_inject_bindings;
g_hook_prepend(&dcerpc_hooks_init_protos, hook_init_proto);
}
static decode_dcerpc_bind_values_t *
decode_dcerpc_binding_clone(decode_dcerpc_bind_values_t *binding_in)
{
decode_dcerpc_bind_values_t *stored_binding;
stored_binding = g_new(decode_dcerpc_bind_values_t,1);
*stored_binding = *binding_in;
COPY_ADDRESS(&stored_binding->addr_a, &binding_in->addr_a);
COPY_ADDRESS(&stored_binding->addr_b, &binding_in->addr_b);
stored_binding->ifname = g_string_new(binding_in->ifname->str);
return stored_binding;
}
void
decode_dcerpc_binding_free(void *binding_in)
{
decode_dcerpc_bind_values_t *binding = (decode_dcerpc_bind_values_t *)binding_in;
g_free((void *) binding->addr_a.data);
g_free((void *) binding->addr_b.data);
if(binding->ifname)
g_string_free(binding->ifname, TRUE);
g_free(binding);
}
static gint
decode_dcerpc_binding_cmp(gconstpointer a, gconstpointer b)
{
const decode_dcerpc_bind_values_t *binding_a = (const decode_dcerpc_bind_values_t *)a;
const decode_dcerpc_bind_values_t *binding_b = (const decode_dcerpc_bind_values_t *)b;
if(
ADDRESSES_EQUAL(&binding_a->addr_a, &binding_b->addr_a) &&
ADDRESSES_EQUAL(&binding_a->addr_b, &binding_b->addr_b) &&
binding_a->ptype == binding_b->ptype &&
binding_a->port_a == binding_b->port_a &&
binding_a->port_b == binding_b->port_b &&
binding_a->ctx_id == binding_b->ctx_id &&
binding_a->smb_fid == binding_b->smb_fid)
{
return 0;
}
return 1;
}
static void
decode_dcerpc_add_show_list_single(gpointer data, gpointer user_data)
{
gchar string1[20];
decode_dcerpc_bind_values_t *binding = (decode_dcerpc_bind_values_t *)data;
g_snprintf(string1, sizeof(string1), "ctx_id: %u", binding->ctx_id);
decode_add_to_show_list (
user_data,
"DCE-RPC",
string1,
"-",
binding->ifname->str);
}
void
decode_dcerpc_add_show_list(gpointer user_data)
{
g_slist_foreach(decode_dcerpc_bindings, decode_dcerpc_add_show_list_single, user_data);
}
void
decode_dcerpc_reset_all(void)
{
decode_dcerpc_bind_values_t *binding;
while(decode_dcerpc_bindings) {
binding = (decode_dcerpc_bind_values_t *)decode_dcerpc_bindings->data;
decode_dcerpc_binding_free(binding);
decode_dcerpc_bindings = g_slist_remove(
decode_dcerpc_bindings,
decode_dcerpc_bindings->data);
}
}
static void
decode_dcerpc_binding_reset(
const gchar *table_name _U_,
decode_dcerpc_bind_values_t *binding)
{
GSList *le;
decode_dcerpc_bind_values_t *old_binding;
le = g_slist_find_custom(decode_dcerpc_bindings,
binding,
decode_dcerpc_binding_cmp);
if(le == NULL)
return;
old_binding = (decode_dcerpc_bind_values_t *)le->data;
decode_dcerpc_bindings = g_slist_remove(decode_dcerpc_bindings, le->data);
g_free((void *) old_binding->addr_a.data);
g_free((void *) old_binding->addr_b.data);
g_string_free(old_binding->ifname, TRUE);
g_free(old_binding);
}
static void
decode_dcerpc_binding_change(
const gchar *table_name,
decode_dcerpc_bind_values_t *binding)
{
decode_dcerpc_bind_values_t *stored_binding;
decode_dcerpc_binding_reset(table_name, binding);
stored_binding = decode_dcerpc_binding_clone(binding);
decode_dcerpc_bindings = g_slist_append (decode_dcerpc_bindings, stored_binding);
}
static void
decode_change_one_dcerpc_binding(const gchar *table_name, decode_dcerpc_bind_values_t *binding, GtkWidget *list)
{
dcerpc_uuid_key *key;
gchar *abbrev;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
if (gtk_tree_selection_get_selected(selection, &model, &iter) == FALSE)
{
abbrev = NULL;
key = NULL;
} else {
gtk_tree_model_get(model, &iter, E_LIST_S_PROTO_NAME, &abbrev,
E_LIST_S_TABLE+1, &key, -1);
}
if (key == NULL || (abbrev != NULL && strcmp(abbrev, "(default)") == 0) ) {
decode_dcerpc_binding_reset(table_name, binding);
} else {
binding->ifname = g_string_new(abbrev);
binding->uuid = key->uuid;
binding->ver = key->ver;
decode_dcerpc_binding_change(table_name, binding);
}
g_free(abbrev);
}
static void
decode_dcerpc(GtkWidget *notebook_pg)
{
GtkWidget *list;
const gchar *table_name;
decode_dcerpc_bind_values_t *binding;
list = (GtkWidget *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_LIST);
if (requested_action == E_DECODE_NO)
gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)));
binding = (decode_dcerpc_bind_values_t *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_BINDING);
table_name = "DCE-RPC";
decode_change_one_dcerpc_binding(table_name, binding, list);
}
static void
decode_dcerpc_add_to_list(gpointer key, gpointer value, gpointer user_data)
{
dcerpc_uuid_value *v = (dcerpc_uuid_value *)value;
if(strcmp(v->name, "(none)"))
decode_add_to_list("DCE-RPC", v->name, key, user_data);
}
static GtkWidget *
decode_add_dcerpc_menu (GtkWidget *page, const gchar *table_name _U_)
{
GtkWidget *scrolled_window;
GtkWidget *list;
decode_list_menu_start(page, &list, &scrolled_window);
g_hash_table_foreach(dcerpc_uuids, decode_dcerpc_add_to_list, list);
decode_list_menu_finish(list);
return(scrolled_window);
}
GtkWidget *
decode_dcerpc_add_page (packet_info *pinfo)
{
GtkWidget *page_hb, *info_vb, *label, *scrolled_window;
GString *gs = g_string_new("");
GString *gs2 = g_string_new("");
decode_dcerpc_bind_values_t *binding;
binding = g_new(decode_dcerpc_bind_values_t,1);
COPY_ADDRESS(&binding->addr_a, &pinfo->src);
COPY_ADDRESS(&binding->addr_b, &pinfo->dst);
binding->ptype = pinfo->ptype;
binding->port_a = pinfo->srcport;
binding->port_b = pinfo->destport;
binding->ctx_id = pinfo->dcectxid;
binding->smb_fid = dcerpc_get_transport_salt(pinfo);
binding->ifname = NULL;
binding->ver = 0;
page_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
g_object_set_data(G_OBJECT(page_hb), E_PAGE_ACTION, decode_dcerpc);
g_object_set_data(G_OBJECT(page_hb), E_PAGE_TABLE, (gpointer)"DCE-RPC");
g_object_set_data(G_OBJECT(page_hb), E_PAGE_TITLE, (gpointer)"DCE-RPC");
g_object_set_data(G_OBJECT(page_hb), E_PAGE_BINDING, binding);
info_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_box_pack_start(GTK_BOX(page_hb), info_vb, TRUE, TRUE, 0);
label = gtk_label_new("Replace binding between:");
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
switch(binding->ptype) {
case(PT_TCP):
g_string_printf(gs2, "TCP port");
break;
case(PT_UDP):
g_string_printf(gs2, "UDP port");
break;
default:
g_string_printf(gs2, "Unknown port type");
}
g_string_printf(gs, "Address: ToBeDone %s: %u", gs2->str, binding->port_a);
label = gtk_label_new(gs->str);
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
label = gtk_label_new("&");
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
g_string_printf(gs, "Address: ToBeDone %s: %u", gs2->str, binding->port_b);
label = gtk_label_new(gs->str);
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
label = gtk_label_new("&");
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
g_string_printf(gs, "Context ID: %u", binding->ctx_id);
label = gtk_label_new(gs->str);
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
label = gtk_label_new("&");
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
gtk_widget_set_sensitive(label, binding->smb_fid);
g_string_printf(gs, "SMB FID: %u", binding->smb_fid);
label = gtk_label_new(gs->str);
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
gtk_widget_set_sensitive(label, binding->smb_fid);
label = gtk_label_new("with:");
gtk_box_pack_start(GTK_BOX(info_vb), label, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, label);
scrolled_window = decode_add_dcerpc_menu(page_hb, "dcerpc" );
gtk_box_pack_start(GTK_BOX(page_hb), scrolled_window, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, scrolled_window);
g_string_free(gs, TRUE);
return(page_hb);
}
