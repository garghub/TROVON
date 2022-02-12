void
firewall_rule_cb(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *rule_w, *vbox, *txt_scrollw, *text;
GtkWidget *label, *product_combo_box;
GtkWidget *hbox, *button_hbox, *button;
rule_info_t *rule_info;
packet_info *pinfo = &cfile.edt->pi;
guint i;
rule_info = g_new0(rule_info_t, 1);
COPY_ADDRESS(&(rule_info->dl_src), &(pinfo->dl_src));
COPY_ADDRESS(&(rule_info->dl_dst), &(pinfo->dl_dst));
COPY_ADDRESS(&(rule_info->net_src), &(pinfo->net_src));
COPY_ADDRESS(&(rule_info->net_dst), &(pinfo->net_dst));
rule_info->ptype = pinfo->ptype;
rule_info->srcport = pinfo->srcport;
rule_info->destport = pinfo->destport;
rule_info->inbound = TRUE;
rule_info->deny = TRUE;
rule_info->product = 0;
rule_w = dlg_window_new("Firewall ACL Rules");
gtk_widget_set_name(rule_w, "Firewall ACL rule window");
gtk_container_set_border_width(GTK_CONTAINER(rule_w), 6);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
gtk_container_add(GTK_CONTAINER(rule_w), vbox);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1, FALSE);
gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
label = gtk_label_new("Product");
gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
product_combo_box = gtk_combo_box_text_new();
for (i = 0; i < NUM_PRODS; i++) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(product_combo_box), products[i].name);
}
g_object_set_data(G_OBJECT(product_combo_box), WS_RULE_INFO_KEY, rule_info);
g_signal_connect(product_combo_box, "changed", G_CALLBACK(select_product), NULL);
gtk_box_pack_start(GTK_BOX(hbox), product_combo_box, FALSE, FALSE, 5);
label = gtk_label_new("Filter");
gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 10);
rule_info->filter_combo_box = ws_combo_box_new_text_and_pointer();
g_object_set_data(G_OBJECT(rule_info->filter_combo_box), WS_RULE_INFO_KEY, rule_info); \
g_signal_connect(rule_info->filter_combo_box, "changed", G_CALLBACK(select_filter), NULL);
gtk_box_pack_start(GTK_BOX(hbox), rule_info->filter_combo_box, FALSE, FALSE, 5);
rule_info->inbound_cb = gtk_check_button_new_with_label("Inbound");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rule_info->inbound_cb),
rule_info->inbound);
gtk_box_pack_start(GTK_BOX(hbox), rule_info->inbound_cb, FALSE, FALSE, 10);
g_signal_connect(rule_info->inbound_cb, "toggled", G_CALLBACK(toggle_inbound), rule_info);
rule_info->deny_cb = gtk_check_button_new_with_label("Deny");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rule_info->deny_cb),
rule_info->deny);
gtk_box_pack_start(GTK_BOX(hbox), rule_info->deny_cb, FALSE, FALSE, 10);
g_signal_connect(rule_info->deny_cb, "toggled", G_CALLBACK(toggle_deny), rule_info);
txt_scrollw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(txt_scrollw),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(vbox), txt_scrollw, TRUE, TRUE, 0);
text = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(text), FALSE);
gtk_container_add(GTK_CONTAINER(txt_scrollw), text);
rule_info->text = text;
button_hbox = dlg_button_row_new(GTK_STOCK_HELP, GTK_STOCK_COPY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(vbox), button_hbox, FALSE, FALSE, 0);
button = g_object_get_data(G_OBJECT(button_hbox), GTK_STOCK_COPY);
g_signal_connect(button, "clicked", G_CALLBACK(firewall_copy_cmd_cb), rule_info);
gtk_widget_set_tooltip_text(button, "Copy rule to clipboard");
button = g_object_get_data(G_OBJECT(button_hbox), GTK_STOCK_SAVE);
g_signal_connect(button, "clicked", G_CALLBACK(firewall_save_as_cmd_cb), rule_info);
gtk_widget_set_tooltip_text(button, "Save the rule as currently displayed");
button = g_object_get_data(G_OBJECT(button_hbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(button, "Cancel the dialog");
window_set_cancel_button(rule_w, button, window_cancel_button_cb);
button = g_object_get_data(G_OBJECT(button_hbox), GTK_STOCK_HELP);
g_signal_connect(button, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_FIREWALL_DIALOG);
g_object_set_data(G_OBJECT(rule_w), WS_RULE_INFO_KEY, rule_info);
g_signal_connect(rule_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rule_w, "destroy", G_CALLBACK(firewall_destroy_cb), NULL);
gtk_combo_box_set_active(GTK_COMBO_BOX(product_combo_box), 0);
gtk_widget_show_all(rule_w);
window_present(rule_w);
}
static void
select_product(GtkWidget *w, gpointer data _U_)
{
guint prod = gtk_combo_box_get_active(GTK_COMBO_BOX(w));
rule_info_t *rule_info;
gchar name[MAX_RULE_LEN], addr_str[MAX_RULE_LEN];
address *addr;
rule_type_t rule_type = RT_NONE;
gboolean sensitive = FALSE;
rule_info = g_object_get_data(G_OBJECT(w), WS_RULE_INFO_KEY);
if (prod >= NUM_PRODS || !rule_info)
return;
rule_info->product = prod;
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(rule_info->filter_combo_box));
if (products[prod].mac_func && rule_info->dl_src.type == AT_ETHER) {
addr = &(rule_info->dl_src);
address_to_str_buf(addr, name, MAX_RULE_LEN);
ADD_TO_FILTER_MENU(RT_MAC_SRC);
addr = &(rule_info->dl_dst);
address_to_str_buf(addr, name, MAX_RULE_LEN);
ADD_TO_FILTER_MENU(RT_MAC_DST);
}
if (products[prod].ipv4_func && rule_info->net_src.type == AT_IPv4) {
addr = &(rule_info->net_src);
address_to_str_buf(addr, name, MAX_RULE_LEN);
ADD_TO_FILTER_MENU(RT_IPv4_SRC);
addr = &(rule_info->net_dst);
address_to_str_buf(addr, name, MAX_RULE_LEN);
ADD_TO_FILTER_MENU(RT_IPv4_DST);
}
if (products[prod].port_func && (rule_info->ptype == PT_TCP || rule_info->ptype == PT_UDP)) {
g_snprintf(name, MAX_RULE_LEN, "%s port %u", NAME_TCP_UDP,
rule_info->srcport);
ADD_TO_FILTER_MENU(RT_PORT_SRC);
if (rule_info->srcport != rule_info->destport) {
g_snprintf(name, MAX_RULE_LEN, "%s port %u", NAME_TCP_UDP,
rule_info->destport);
ADD_TO_FILTER_MENU(RT_PORT_DST);
}
}
if (products[prod].ipv4_port_func && rule_info->net_src.type == AT_IPv4 &&
(rule_info->ptype == PT_TCP || rule_info->ptype == PT_UDP)) {
addr = &(rule_info->net_src);
address_to_str_buf(addr, addr_str, MAX_RULE_LEN);
g_snprintf(name, MAX_RULE_LEN, "%s + %s port %u", addr_str,
NAME_TCP_UDP, rule_info->srcport);
ADD_TO_FILTER_MENU(RT_IPv4_PORT_SRC);
addr = &(rule_info->net_dst);
address_to_str_buf(addr, addr_str, MAX_RULE_LEN);
g_snprintf(name, MAX_RULE_LEN, "%s + %s port %u", addr_str,
NAME_TCP_UDP, rule_info->destport);
ADD_TO_FILTER_MENU(RT_IPv4_PORT_DST);
}
if (rule_type != RT_NONE) {
gtk_combo_box_set_active(GTK_COMBO_BOX(rule_info->filter_combo_box), 0);
sensitive = TRUE;
} else {
select_filter(rule_info->filter_combo_box, NULL);
}
gtk_widget_set_sensitive(rule_info->filter_combo_box, sensitive);
gtk_widget_set_sensitive(rule_info->inbound_cb, products[prod].does_inbound && sensitive);
gtk_widget_set_sensitive(rule_info->deny_cb, sensitive);
}
static void
select_filter(GtkWidget *w, gpointer data _U_)
{
rule_type_t cur_type;
rule_info_t *rule_info;
gpointer ptr;
rule_info = g_object_get_data(G_OBJECT(w), WS_RULE_INFO_KEY);
if (!rule_info)
return;
if (ws_combo_box_get_active_pointer(GTK_COMBO_BOX(w), &ptr))
cur_type = GPOINTER_TO_UINT(ptr);
else
cur_type = RT_NONE;
if (cur_type >= NUM_RULE_TYPES)
return;
rule_info->rule_type = cur_type;
set_rule_text(rule_info);
}
static void
toggle_inbound(GtkToggleButton *t, gpointer data)
{
rule_info_t *rule_info = (rule_info_t *) data;
rule_info->inbound = gtk_toggle_button_get_active(t);
set_rule_text(rule_info);
}
static void
toggle_deny(GtkToggleButton *t, gpointer data)
{
rule_info_t *rule_info = (rule_info_t *) data;
rule_info->deny = gtk_toggle_button_get_active(t);
set_rule_text(rule_info);
}
static void
set_rule_text(rule_info_t *rule_info) {
GString *rtxt = g_string_new("");
gchar addr_str[MAX_RULE_LEN];
rule_type_t rt = rule_info->rule_type;
guint prod = rule_info->product;
address *addr = NULL;
guint32 port = 0;
syntax_func rt_func = NULL;
GtkTextBuffer *buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(rule_info->text));
if (prod < NUM_PRODS) {
g_string_printf(rtxt, "%s %s\n", products[prod].comment_pfx, products[prod].name);
switch(rt) {
case RT_NONE:
g_string_append_printf(rtxt, "%s Not supported", products[prod].comment_pfx);
rt_func = sf_dummy;
break;
case RT_MAC_SRC:
case RT_MAC_DST:
addr = DL_ADDR;
address_to_str_buf(addr, addr_str, MAX_RULE_LEN);
rt_func = products[prod].mac_func;
break;
case RT_IPv4_SRC:
case RT_IPv4_DST:
addr = NET_ADDR;
address_to_str_buf(addr, addr_str, MAX_RULE_LEN);
rt_func = products[prod].ipv4_func;
break;
case RT_PORT_SRC:
case RT_PORT_DST:
port = NET_PORT;
rt_func = products[prod].port_func;
break;
case RT_IPv4_PORT_SRC:
case RT_IPv4_PORT_DST:
addr = NET_ADDR;
address_to_str_buf(addr, addr_str, MAX_RULE_LEN);
port = NET_PORT;
rt_func = products[prod].ipv4_port_func;
break;
default:
break;
}
}
if (rt_func) {
rt_func(rtxt, addr_str, port, rule_info->ptype, rule_info->inbound, rule_info->deny);
} else {
g_string_append_printf(rtxt, "ERROR: Unable to create rule");
}
gtk_text_buffer_set_text(buf, rtxt->str, (gint) rtxt->len);
g_string_free(rtxt, TRUE);
}
static void sf_dummy(GString *rtxt _U_, gchar *addr _U_, guint32 port _U_, port_type ptype _U_, gboolean inbound _U_, gboolean deny _U_) {
}
static void sf_ipfw_mac(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s MAC %s any %s",
IPFW_DENY, addr, IPFW_IN);
}
static void sf_netfilter_mac(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables -A %s --mac-source %s -j %s",
NF_INPUT, addr, NF_DROP);
}
static void sf_ios_std_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "access-list NUMBER %s host %s", IOS_DENY, addr);
}
static void sf_ios_ext_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
if (inbound)
g_string_append_printf(rtxt, "access-list NUMBER %s ip host %s any", IOS_DENY, addr);
else
g_string_append_printf(rtxt, "access-list NUMBER %s ip any host %s", IOS_DENY, addr);
}
static void sf_ipfilter_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s on le0 from %s to any",
IPFILTER_DENY, IPFILTER_IN, addr);
}
static void sf_ipfw_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s ip from %s to any %s",
IPFW_DENY, addr, IPFW_IN);
}
static void sf_netfilter_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables -A %s -i eth0 -d %s/32 -j %s",
NF_INPUT, addr, NF_DROP);
}
static void sf_pf_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s quick on $ext_if from %s to any",
PF_DENY, PF_IN, addr);
}
static void sf_ios_ext_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "access-list NUMBER %s %s any any eq %u",
IOS_DENY, RT_TCP_UDP, port);
}
static void sf_ipfilter_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s on le0 proto %s from any to any port = %u",
IPFILTER_DENY, IPFILTER_IN, RT_TCP_UDP, port);
}
static void sf_ipfw_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s %s from any to any %u %s",
IPFW_DENY, RT_TCP_UDP, port, IPFW_IN);
}
static void sf_netfilter_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables -A %s -p %s --destination-port %u -j %s",
NF_INPUT, RT_TCP_UDP, port, NF_DROP);
}
static void sf_pf_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s quick on $ext_if proto %s from any to any port %u",
PF_DENY, PF_IN, RT_TCP_UDP, port);
}
static void sf_netsh_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "add portopening %s %u Wireshark %s",
RT_TCP_UDP, port, NETSH_DENY);
}
static void sf_ios_ext_ipv4_port(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
if (inbound)
g_string_append_printf(rtxt, "access-list NUMBER %s %s host %s any eq %u", IOS_DENY, RT_TCP_UDP, addr, port);
else
g_string_append_printf(rtxt, "access-list NUMBER %s %s any host %s eq %u", IOS_DENY, RT_TCP_UDP, addr, port);
}
static void sf_ipfilter_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
if (inbound)
g_string_append_printf(rtxt, "%s %s on le0 proto %s from %s to any port = %u",
IPFILTER_DENY, IPFILTER_IN, RT_TCP_UDP, addr, port);
else
g_string_append_printf(rtxt, "%s %s on le0 proto %s from any to %s port = %u",
IPFILTER_DENY, IPFILTER_IN, RT_TCP_UDP, addr, port);
}
static void sf_ipfw_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s %s from %s to any %u %s",
IPFW_DENY, RT_TCP_UDP, addr, port, IPFW_IN);
}
static void sf_pf_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s quick on $ext_if proto %s from %s to any port %u",
PF_DENY, PF_IN, RT_TCP_UDP, addr, port);
}
static void sf_netfilter_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables -A %s -p %s -d %s/32 --destination-port %u -j %s",
NF_INPUT, RT_TCP_UDP, addr, port, NF_DROP);
}
static void sf_netsh_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "add portopening %s %u Wireshark %s %s",
RT_TCP_UDP, port, NETSH_DENY, addr);
}
static void
firewall_destroy_cb(GtkWidget *w, gpointer data _U_)
{
rule_info_t *rule_info;
rule_info = g_object_get_data(G_OBJECT(w), WS_RULE_INFO_KEY);
#if 0
forget_rule_info(rule_info);
#endif
g_free(rule_info);
gtk_widget_destroy(w);
}
static void
firewall_copy_cmd_cb(GtkWidget *w _U_, gpointer data)
{
rule_info_t *rule_info = data;
GtkTextIter start, end;
GtkTextBuffer *buf;
buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(rule_info->text));
gtk_text_buffer_get_start_iter(buf, &start);
gtk_text_buffer_get_end_iter(buf, &end);
gtk_text_buffer_select_range(buf, &start, &end);
gtk_text_buffer_copy_clipboard(buf, gtk_clipboard_get(GDK_SELECTION_CLIPBOARD));
}
static void
firewall_save_as_cmd_cb(GtkWidget *w _U_, gpointer data)
{
GtkWidget *new_win;
rule_info_t *rule_info = data;
#if 0
if (rule_info->firewall_save_as_w != NULL) {
reactivate_window(rule_info->firewall_save_as_w);
return;
}
#endif
new_win = file_selection_new("Wireshark: Save Firewall ACL Rule",
FILE_SELECTION_SAVE);
rule_info->firewall_save_as_w = new_win;
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(new_win), TRUE);
g_object_set_data(G_OBJECT(new_win), WS_RULE_INFO_KEY, rule_info);
g_signal_connect(new_win, "destroy", G_CALLBACK(firewall_save_as_destroy_cb), rule_info);
#if 0
if (gtk_dialog_run(GTK_DIALOG(new_win)) == GTK_RESPONSE_ACCEPT)
{
firewall_save_as_ok_cb(new_win, new_win);
} else {
window_destroy(new_win);
}
#else
while (gtk_dialog_run(GTK_DIALOG(new_win)) == GTK_RESPONSE_ACCEPT) {
if (firewall_save_as_ok_cb(NULL, new_win)) {
break;
}
}
window_destroy(new_win);
#endif
}
static gboolean
firewall_save_as_ok_cb(GtkWidget * w _U_, gpointer fs)
{
gchar *to_name, *rule;
rule_info_t *rule_info;
FILE *fh;
gchar *dirname;
GtkTextIter start, end;
GtkTextBuffer *buf;
to_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
if (test_for_directory(to_name) == EISDIR) {
set_last_open_dir(to_name);
g_free(to_name);
file_selection_set_current_folder(fs, get_last_open_dir());
gtk_file_chooser_set_current_name(fs, "");
return FALSE;
}
rule_info = g_object_get_data(G_OBJECT(fs), WS_RULE_INFO_KEY);
fh = ws_fopen(to_name, "w");
if (fh == NULL) {
open_failure_alert_box(to_name, errno, TRUE);
g_free(to_name);
return TRUE;
}
buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(rule_info->text));
gtk_text_buffer_get_start_iter(buf, &start);
gtk_text_buffer_get_end_iter(buf, &end);
rule = gtk_text_buffer_get_text(buf, &start, &end, FALSE);
fputs(rule, fh);
fclose(fh);
#if 0
gtk_widget_hide(GTK_WIDGET(fs));
window_destroy(GTK_WIDGET(fs));
#endif
dirname = get_dirname(to_name);
set_last_open_dir(dirname);
g_free(to_name);
return TRUE;
}
static void
firewall_save_as_destroy_cb(GtkWidget * win _U_, gpointer data)
{
rule_info_t *rule_info = data;
rule_info->firewall_save_as_w = NULL;
}
