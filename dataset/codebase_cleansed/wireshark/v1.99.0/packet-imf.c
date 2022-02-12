static void
header_fields_update_cb(void *r, const char **err)
{
header_field_t *rec = (header_field_t *)r;
char c;
if (rec->header_name == NULL) {
*err = g_strdup("Header name can't be empty");
return;
}
g_strstrip(rec->header_name);
if (rec->header_name[0] == 0) {
*err = g_strdup("Header name can't be empty");
return;
}
c = proto_check_field_name(rec->header_name);
if (c) {
*err = g_strdup_printf("Header name can't contain '%c'", c);
return;
}
*err = NULL;
}
static void *
header_fields_copy_cb(void *n, const void *o, size_t siz _U_)
{
header_field_t *new_rec = (header_field_t *)n;
const header_field_t *old_rec = (const header_field_t *)o;
new_rec->header_name = g_strdup(old_rec->header_name);
new_rec->description = g_strdup(old_rec->description);
new_rec->header_format = old_rec->header_format;
new_rec->add_to_col_info = old_rec->add_to_col_info;
return new_rec;
}
static void
header_fields_free_cb(void *r)
{
header_field_t *rec = (header_field_t *)r;
g_free(rec->header_name);
g_free(rec->description);
}
static void
dissect_imf_address(tvbuff_t *tvb, int offset, int length, proto_item *item, packet_info *pinfo)
{
proto_tree *group_tree;
proto_item *group_item;
int addr_pos;
if((addr_pos = tvb_find_guint8(tvb, offset, length, ':')) == -1) {
dissect_imf_mailbox(tvb, offset, length, item, pinfo);
} else {
group_tree = proto_item_add_subtree(item, ett_imf_group);
group_item = proto_tree_add_item(group_tree, hf_imf_display_name, tvb, offset, addr_pos - offset - 1, ENC_ASCII|ENC_NA);
for(addr_pos++ ;addr_pos < (offset + length); addr_pos++) {
if(!isspace(tvb_get_guint8(tvb, addr_pos))) {
break;
}
}
if(tvb_get_guint8(tvb, addr_pos) != ';') {
dissect_imf_mailbox_list(tvb, addr_pos, length - (addr_pos - offset), group_item, pinfo);
}
}
}
static void
dissect_imf_mailbox(tvbuff_t *tvb, int offset, int length, proto_item *item, packet_info *pinfo _U_)
{
proto_tree *mbox_tree;
int addr_pos, end_pos;
mbox_tree = proto_item_add_subtree(item, ett_imf_mailbox);
if((addr_pos = tvb_find_guint8(tvb, offset, length, '<')) == -1) {
(void) proto_tree_add_item(mbox_tree, hf_imf_address, tvb, offset, length, ENC_ASCII|ENC_NA);
} else {
for(; offset < addr_pos; offset++) {
if(!isspace(tvb_get_guint8(tvb, offset))) {
break;
}
}
if(offset != addr_pos) {
(void) proto_tree_add_item(mbox_tree, hf_imf_display_name, tvb, offset, addr_pos - offset - 1, ENC_ASCII|ENC_NA);
}
end_pos = tvb_find_guint8(tvb, addr_pos + 1, length - (addr_pos + 1 - offset), '>');
if(end_pos != -1) {
(void) proto_tree_add_item(mbox_tree, hf_imf_address, tvb, addr_pos + 1, end_pos - addr_pos - 1, ENC_ASCII|ENC_NA);
}
}
}
static void
dissect_imf_address_list(tvbuff_t *tvb, int offset, int length, proto_item *item, packet_info *pinfo)
{
proto_item *addr_item = NULL;
proto_tree *tree = NULL;
int count = 0;
int item_offset;
int end_offset;
int item_length;
tree = proto_item_add_subtree(item, ett_imf_address_list);
item_offset = offset;
do {
end_offset = tvb_find_guint8(tvb, item_offset, length - (item_offset - offset), ',');
count++;
if(end_offset == -1) {
item_length = length - (item_offset - offset);
} else {
item_length = end_offset - item_offset;
}
addr_item = proto_tree_add_item(tree, hf_imf_address_list_item, tvb, item_offset, item_length, ENC_ASCII|ENC_NA);
dissect_imf_address(tvb, item_offset, item_length, addr_item, pinfo);
if(end_offset != -1) {
item_offset = end_offset + 1;
}
} while(end_offset != -1);
proto_item_append_text(item, ", %d item%s", count, plurality(count, "", "s"));
}
static void
dissect_imf_mailbox_list(tvbuff_t *tvb, int offset, int length, proto_item *item, packet_info *pinfo)
{
proto_item *mbox_item = NULL;
proto_tree *tree = NULL;
int count = 0;
int item_offset;
int end_offset;
int item_length;
tree = proto_item_add_subtree(item, ett_imf_mailbox_list);
item_offset = offset;
do {
end_offset = tvb_find_guint8(tvb, item_offset, length - (item_offset - offset), ',');
count++;
if(end_offset == -1) {
item_length = length - (item_offset - offset);
} else {
item_length = end_offset - item_offset;
}
mbox_item = proto_tree_add_item(tree, hf_imf_mailbox_list_item, tvb, item_offset, item_length, ENC_ASCII|ENC_NA);
dissect_imf_mailbox(tvb, item_offset, item_length, mbox_item, pinfo);
if(end_offset != -1) {
item_offset = end_offset + 1;
}
} while(end_offset != -1);
proto_item_append_text(item, ", %d item%s", count, plurality(count, "", "s"));
}
static void
dissect_imf_siolabel(tvbuff_t *tvb, int offset, int length, proto_item *item, packet_info *pinfo)
{
proto_tree *tree = NULL;
proto_item *sub_item = NULL;
int item_offset, item_length;
int value_offset, value_length;
int end_offset;
tvbuff_t *label_tvb;
gchar *type = NULL;
wmem_strbuf_t *label_string = wmem_strbuf_new(wmem_packet_scope(), "");
tree = proto_item_add_subtree(item, ett_imf_siolabel);
item_offset = offset;
do {
end_offset = tvb_find_guint8(tvb, item_offset, length - (item_offset - offset), ';');
while (isspace(tvb_get_guint8(tvb, item_offset))) {
item_offset++;
}
if (end_offset == -1) {
item_length = tvb_find_line_end(tvb, item_offset, length - (item_offset - offset), NULL, FALSE);
} else {
item_length = end_offset - item_offset;
}
value_offset = tvb_find_guint8(tvb, item_offset, length - (item_offset - offset), '=') + 1;
while (isspace(tvb_get_guint8(tvb, value_offset))) {
value_offset++;
}
value_length = item_length - (value_offset - item_offset);
while (isspace(tvb_get_guint8(tvb, value_offset + value_length - 1))) {
value_length--;
}
if (tvb_strneql(tvb, item_offset, "marking", 7) == 0) {
proto_item_append_text(item, ": %s", tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset, value_length, ENC_ASCII));
proto_tree_add_item(tree, hf_imf_siolabel_marking, tvb, value_offset, value_length, ENC_ASCII|ENC_NA);
} else if (tvb_strneql(tvb, item_offset, "fgcolor", 7) == 0) {
proto_tree_add_item(tree, hf_imf_siolabel_fgcolor, tvb, value_offset, value_length, ENC_ASCII|ENC_NA);
} else if (tvb_strneql(tvb, item_offset, "bgcolor", 7) == 0) {
proto_tree_add_item(tree, hf_imf_siolabel_bgcolor, tvb, value_offset, value_length, ENC_ASCII|ENC_NA);
} else if (tvb_strneql(tvb, item_offset, "type", 4) == 0) {
type = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset + 1, value_length - 2, ENC_ASCII);
proto_tree_add_item(tree, hf_imf_siolabel_type, tvb, value_offset, value_length, ENC_ASCII|ENC_NA);
} else if (tvb_strneql(tvb, item_offset, "label", 5) == 0) {
gchar *label = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset + 1, value_length - 2, ENC_ASCII);
wmem_strbuf_append(label_string, label);
if (tvb_get_guint8(tvb, item_offset + 5) == '*') {
int num = (int)strtol(tvb_get_string_enc(wmem_packet_scope(), tvb, item_offset + 6, value_offset - item_offset + 6, ENC_ASCII), NULL, 10);
proto_tree_add_string_format(tree, hf_imf_siolabel_label, tvb, value_offset, value_length,
label, "Label[%d]: \"%s\"", num, label);
} else {
proto_tree_add_item(tree, hf_imf_siolabel_label, tvb, value_offset, value_length, ENC_ASCII|ENC_NA);
}
} else {
sub_item = proto_tree_add_item(tree, hf_imf_siolabel_unknown, tvb, item_offset, item_length, ENC_ASCII|ENC_NA);
expert_add_info(pinfo, sub_item, &ei_imf_unknown_param);
}
if (end_offset != -1) {
item_offset = end_offset + 1;
}
} while (end_offset != -1);
if (type && wmem_strbuf_get_len(label_string) > 0) {
if (strcmp (type, ":ess") == 0) {
label_tvb = base64_to_tvb(tvb, wmem_strbuf_get_str(label_string));
add_new_data_source(pinfo, label_tvb, "ESS Security Label");
dissect_ess_ESSSecurityLabel_PDU(label_tvb, pinfo, tree);
} else if (strcmp (type, ":x411") == 0) {
label_tvb = base64_to_tvb(tvb, wmem_strbuf_get_str(label_string));
add_new_data_source(pinfo, label_tvb, "X.411 Security Label");
dissect_p1_MessageSecurityLabel_PDU(label_tvb, pinfo, tree);
}
}
}
static void
dissect_imf_content_type(tvbuff_t *tvb, int offset, int length, proto_item *item,
char **type, char **parameters)
{
int first_colon;
int end_offset;
int len;
int i;
proto_tree *ct_tree;
for(i = 0; i < length; i++) {
if(!isspace(tvb_get_guint8(tvb, offset + i))) {
offset += i;
break;
}
}
first_colon = tvb_find_guint8(tvb, offset, length, ';');
if(first_colon != -1) {
ct_tree = proto_item_add_subtree(item, ett_imf_content_type);
len = first_colon - offset;
proto_tree_add_item(ct_tree, hf_imf_content_type_type, tvb, offset, len, ENC_ASCII|ENC_NA);
if(type) {
(*type) = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII);
}
end_offset = imf_find_field_end (tvb, first_colon + 1, offset + length, NULL);
if (end_offset == -1) {
return;
}
len = end_offset - (first_colon + 1) - 2;
proto_tree_add_item(ct_tree, hf_imf_content_type_parameters, tvb, first_colon + 1, len, ENC_ASCII|ENC_NA);
if(parameters) {
(*parameters) = tvb_get_string_enc(wmem_packet_scope(), tvb, first_colon + 1, len, ENC_ASCII);
}
}
}
int
imf_find_field_end(tvbuff_t *tvb, int offset, gint max_length, gboolean *last_field)
{
while(offset < max_length) {
offset = tvb_find_guint8(tvb, offset, max_length - offset, '\r');
if(offset != -1) {
if(tvb_get_guint8(tvb, ++offset) == '\n') {
switch(tvb_get_guint8(tvb, ++offset)) {
case '\r':
if(tvb_get_guint8(tvb, ++offset) == '\n') {
offset++;
}
if(last_field) {
*last_field = TRUE;
}
return offset;
case ' ':
case '\t':
break;
default:
return offset;
}
}
} else {
return offset;
}
}
return -1;
}
static void
dissect_imf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *unknown_tree, *text_tree;
char *content_type_str = NULL;
char *parameters = NULL;
int hf_id;
gint start_offset = 0;
gint value_offset = 0;
gint unknown_offset = 0;
gint end_offset = 0;
gint max_length;
guint8 *key;
gboolean last_field = FALSE;
tvbuff_t *next_tvb;
struct imf_field *f_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(tree, proto_imf, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_imf);
max_length = tvb_length(tvb);
while(!last_field) {
end_offset = tvb_find_guint8(tvb, start_offset, max_length - start_offset, ':');
if(end_offset == -1) {
break;
} else {
key = tvb_get_string_enc(wmem_packet_scope(), tvb, start_offset, end_offset - start_offset, ENC_ASCII);
ascii_strdown_inplace (key);
f_info = (struct imf_field *)g_hash_table_lookup(imf_field_table, key);
if(f_info == NULL && custom_field_table) {
f_info = (struct imf_field *)g_hash_table_lookup(custom_field_table, key);
}
if(f_info == NULL) {
f_info = imf_fields;
unknown_offset = start_offset;
}
hf_id = *(f_info->hf_id);
start_offset = end_offset+1;
end_offset = imf_find_field_end(tvb, start_offset, max_length, &last_field);
if(end_offset == -1) {
break;
}
for(value_offset = start_offset; value_offset < end_offset; value_offset++)
if(!isspace(tvb_get_guint8(tvb, value_offset))) {
break;
}
if(value_offset == end_offset) {
value_offset = start_offset;
}
if(hf_id == hf_imf_extension_type) {
item = proto_tree_add_item(tree, hf_imf_extension, tvb, unknown_offset, end_offset - unknown_offset - 2, ENC_ASCII|ENC_NA);
proto_item_append_text(item, " (Contact Wireshark developers if you want this supported.)");
unknown_tree = proto_item_add_subtree(item, ett_imf_extension);
proto_tree_add_item(unknown_tree, hf_imf_extension_type, tvb, unknown_offset, start_offset - 1 - unknown_offset, ENC_ASCII|ENC_NA);
item = proto_tree_add_item(unknown_tree, hf_imf_extension_value, tvb, value_offset, end_offset - value_offset - 2, ENC_ASCII|ENC_NA);
} else {
item = proto_tree_add_item(tree, hf_id, tvb, value_offset, end_offset - value_offset - 2, ENC_ASCII|ENC_NA);
}
if(f_info->add_to_col_info) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s: %s, ", f_info->name,
tvb_format_text(tvb, value_offset, end_offset - value_offset - 2));
}
if(hf_id == hf_imf_content_type) {
dissect_imf_content_type(tvb, start_offset, end_offset - start_offset, item,
&content_type_str, &parameters);
} else if(f_info->subdissector) {
f_info->subdissector(tvb, value_offset, end_offset - value_offset, item, pinfo);
}
}
start_offset = end_offset;
}
if (end_offset == -1) {
end_offset = 0;
}
if(content_type_str && media_type_dissector_table) {
void* pd_save;
pd_save = pinfo->private_data;
pinfo->private_data = parameters;
next_tvb = tvb_new_subset_remaining(tvb, end_offset);
dissector_try_string(media_type_dissector_table, content_type_str, next_tvb, pinfo, tree, NULL);
pinfo->private_data = pd_save;
} else {
item = proto_tree_add_item(tree, hf_imf_message_text, tvb, end_offset, -1 , ENC_NA);
text_tree = proto_item_add_subtree(item, ett_imf_message_text);
start_offset = end_offset;
while (tvb_offset_exists(tvb, start_offset)) {
tvb_find_line_end(tvb, start_offset, -1, &end_offset, FALSE);
proto_tree_add_format_wsp_text(text_tree, tvb, start_offset, end_offset - start_offset);
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ",
tvb_format_text_wsp(tvb, start_offset, end_offset - start_offset));
start_offset = end_offset;
}
}
}
static void
free_imf_field (gpointer data)
{
struct imf_field *imffield = (struct imf_field *) data;
g_free ((char *) imffield->name);
g_free (imffield);
}
static void
header_fields_initialize_cb (void)
{
static hf_register_info *hf;
gint *hf_id;
struct imf_field *imffield;
guint i;
gchar *header_name;
if (custom_field_table && hf) {
guint hf_size = g_hash_table_size (custom_field_table);
for (i = 0; i < hf_size; i++) {
proto_unregister_field (proto_imf, *(hf[i].p_id));
g_free (hf[i].p_id);
g_free ((char *) hf[i].hfinfo.name);
g_free ((char *) hf[i].hfinfo.abbrev);
g_free ((char *) hf[i].hfinfo.blurb);
}
g_hash_table_destroy (custom_field_table);
g_free (hf);
custom_field_table = NULL;
}
if (num_header_fields) {
custom_field_table = g_hash_table_new_full (g_str_hash, g_str_equal, NULL, free_imf_field);
hf = (hf_register_info *)g_malloc0 (sizeof (hf_register_info) * num_header_fields);
for (i = 0; i < num_header_fields; i++) {
hf_id = (gint *)g_malloc (sizeof (gint));
*hf_id = -1;
header_name = g_strdup (header_fields[i].header_name);
hf[i].p_id = hf_id;
hf[i].hfinfo.name = header_name;
hf[i].hfinfo.abbrev = g_strdup_printf ("imf.header.%s", header_name);
hf[i].hfinfo.type = FT_STRING;
hf[i].hfinfo.display = BASE_NONE;
hf[i].hfinfo.strings = NULL;
hf[i].hfinfo.blurb = g_strdup (header_fields[i].description);
hf[i].hfinfo.same_name_prev_id = -1;
hf[i].hfinfo.same_name_next = NULL;
imffield = (struct imf_field *)g_malloc (sizeof (struct imf_field));
imffield->hf_id = hf_id;
imffield->name = ascii_strdown_inplace (g_strdup (header_name));
switch (header_fields[i].header_format) {
case FORMAT_UNSTRUCTURED:
imffield->subdissector = NO_SUBDISSECTION;
break;
case FORMAT_MAILBOX:
imffield->subdissector = dissect_imf_mailbox;
break;
case FORMAT_ADDRESS:
imffield->subdissector = dissect_imf_address;
break;
case FORMAT_MAILBOX_LIST:
imffield->subdissector = dissect_imf_mailbox_list;
break;
case FORMAT_ADDRESS_LIST:
imffield->subdissector = dissect_imf_address_list;
break;
case FORMAT_SIO_LABEL:
hf[i].hfinfo.type = FT_NONE;
imffield->subdissector = dissect_imf_siolabel;
break;
default:
imffield->subdissector = NO_SUBDISSECTION;
break;
}
imffield->add_to_col_info = header_fields[i].add_to_col_info;
g_hash_table_insert (custom_field_table, (gpointer)imffield->name, (gpointer)imffield);
}
proto_register_field_array (proto_imf, hf, num_header_fields);
}
}
void
proto_register_imf(void)
{
static hf_register_info hf[] = {
{ &hf_imf_date,
{ "Date", "imf.date", FT_STRING, BASE_NONE, NULL, 0x0,
"DateTime", HFILL }},
{ &hf_imf_from,
{ "From", "imf.from", FT_STRING, BASE_NONE, NULL, 0x0,
"MailboxList", HFILL }},
{ &hf_imf_sender,
{ "Sender", "imf.sender", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_reply_to,
{ "Reply-To", "imf.reply_to", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_to,
{ "To", "imf.to", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_cc,
{ "Cc", "imf.cc", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_bcc,
{ "Bcc", "imf.bcc", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_message_id,
{ "Message-ID", "imf.message_id", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_in_reply_to,
{ "In-Reply-To", "imf.in_reply_to", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_references,
{ "References", "imf.references", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_subject,
{ "Subject", "imf.subject", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_comments,
{ "Comments", "imf.comments", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_user_agent,
{ "User-Agent", "imf.user_agent", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_keywords,
{ "Keywords", "imf.keywords", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_date,
{ "Resent-Date", "imf.resent.date", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_from,
{ "Resent-From", "imf.resent.from", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_sender,
{ "Resent-Sender", "imf.resent.sender", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_to,
{ "Resent-To", "imf.resent.to", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_cc,
{ "Resent-Cc", "imf.resent.cc", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_bcc,
{ "Resent-Bcc", "imf.resent.bcc", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_resent_message_id,
{ "Resent-Message-ID", "imf.resent.message_id", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_return_path,
{ "Return-Path", "imf.return_path", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_received,
{ "Received", "imf.received", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_type,
{ "Content-Type", "imf.content.type", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_type_type,
{ "Type", "imf.content.type.type", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_type_parameters,
{ "Parameters", "imf.content.type.parameters", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_description,
{ "Content-Description", "imf.content.description", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_id,
{ "Content-ID", "imf.content.id", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_transfer_encoding,
{ "Content-Transfer-Encoding", "imf.content.transfer_encoding", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_mime_version,
{ "MIME-Version", "imf.mime_version", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_autoforwarded,
{ "Autoforwarded", "imf.autoforwarded", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_autosubmitted,
{ "Autosubmitted", "imf.autosubmitted", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_x400_content_identifier,
{ "X400-Content-Identifier", "imf.x400_content_identifier", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_content_language,
{ "Content-Language", "imf.content_language", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_conversion,
{ "Conversion", "imf.conversion", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_conversion_with_loss,
{ "Conversion-With-Loss", "imf.conversion_with_loss", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_delivery_date,
{ "Delivery-Date", "imf.delivery_date", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_discarded_x400_ipms_extensions,
{ "Discarded-X400-IPMS-Extensions", "imf.discarded_x400_ipms_extensions", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_discarded_x400_mts_extensions,
{ "Discarded-X400-MTS-Extensions", "imf.discarded_x400_mts_extensions", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_dl_expansion_history,
{ "DL-Expansion-History", "imf.dl_expansion_history", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_deferred_delivery,
{ "Deferred-Delivery", "imf.deferred_delivery", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_expires,
{ "Expires", "imf.expires", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_importance,
{ "Importance", "imf.importance", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_incomplete_copy,
{ "Incomplete-Copy", "imf.incomplete_copy", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_latest_delivery_time,
{ "Latest-Delivery-Time", "imf.latest_delivery_time", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_message_type,
{ "Message-Type", "imf.message_type", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_original_encoded_information_types,
{ "Original-Encoded-Information-Types", "imf.original_encoded_information_types", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_originator_return_address,
{ "Originator-Return-Address", "imf.originator_return_address", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_priority,
{ "Priority", "imf.priority", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_reply_by,
{ "Reply-By", "imf.reply_by", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_sensitivity,
{ "Sensitivity", "imf.sensitivity", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_supersedes,
{ "Supersedes", "imf.supersedes", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_x400_content_type,
{ "X400-Content-Type", "imf.x400_content_type", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_x400_mts_identifier,
{ "X400-MTS-Identifier", "imf.x400_mts_identifier", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_x400_originator,
{ "X400-Originator", "imf.x400_originator", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_x400_received,
{ "X400-Received", "imf.x400_received", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_x400_recipients,
{ "X400-Recipients", "imf.x400_recipients", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_delivered_to,
{ "Delivered-To", "imf.delivered_to", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_ext_mailer,
{ "X-Mailer", "imf.ext.mailer", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_ext_mimeole,
{ "X-MimeOLE", "imf.ext.mimeole", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_ext_expiry_date,
{ "Expiry-Date", "imf.ext.expiry-date", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_ext_tnef_correlator,
{ "X-MS-TNEF-Correlator", "imf.ext.tnef-correlator", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_ext_uidl,
{ "X-UIDL", "imf.ext.uidl", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_ext_authentication_warning,
{ "X-Authentication-Warning", "imf.ext.authentication_warning", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_imf_ext_virus_scanned,
{ "X-Virus-Scanned", "imf.ext.virus_scanned", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_thread_index,
{ "Thread-Index", "imf.thread-index", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_extension,
{ "Unknown-Extension", "imf.extension", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_extension_type,
{ "Type", "imf.extension.type", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_extension_value,
{ "Value", "imf.extension.value", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_display_name,
{ "Display-Name", "imf.display_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_address,
{ "Address", "imf.address", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_imf_address_list,
{ "Address List", "imf.address_list", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_imf_address_list_item,
{ "Item", "imf.address_list.item", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_imf_mailbox_list,
{ "Mailbox List", "imf.mailbox_list", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_imf_mailbox_list_item,
{ "Item", "imf.mailbox_list.item", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel,
{ "SIO-Label", "imf.siolabel", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel_marking,
{ "Marking", "imf.siolabel.marking", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel_fgcolor,
{ "Foreground Color", "imf.siolabel.fgcolor", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel_bgcolor,
{ "Background Color", "imf.siolabel.bgcolor", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel_type,
{ "Type", "imf.siolabel.type", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel_label,
{ "Label", "imf.siolabel.label", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_siolabel_unknown,
{ "Unknown parameter", "imf.siolabel.unknown", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_imf_message_text,
{ "Message-Text", "imf.message_text", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_imf,
&ett_imf_content_type,
&ett_imf_group,
&ett_imf_mailbox,
&ett_imf_mailbox_list,
&ett_imf_address_list,
&ett_imf_siolabel,
&ett_imf_extension,
&ett_imf_message_text,
};
static ei_register_info ei[] = {
{ &ei_imf_unknown_param, { "imf.unknown_param", PI_PROTOCOL, PI_WARN, "Unknown parameter", EXPFILL }},
};
static uat_field_t attributes_flds[] = {
UAT_FLD_CSTRING(header_fields, header_name, "Header name", "IMF header name"),
UAT_FLD_CSTRING(header_fields, description, "Description", "Description of the value contained in the header"),
UAT_FLD_VS(header_fields, header_format, "Format", header_format, 0),
UAT_FLD_VS(header_fields, add_to_col_info, "Add to Info column", add_to_col_info, 0),
UAT_END_FIELDS
};
uat_t *headers_uat = uat_new("Custom IMF headers",
sizeof(header_field_t),
"imf_header_fields",
TRUE,
&header_fields,
&num_header_fields,
UAT_AFFECTS_DISSECTION|UAT_AFFECTS_FIELDS,
NULL,
header_fields_copy_cb,
header_fields_update_cb,
header_fields_free_cb,
header_fields_initialize_cb,
attributes_flds);
module_t *imf_module;
expert_module_t* expert_imf;
struct imf_field *f;
proto_imf = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_imf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_imf = expert_register_protocol(proto_imf);
expert_register_field_array(expert_imf, ei, array_length(ei));
imf_handle = register_dissector(PFNAME, dissect_imf, proto_imf);
imf_module = prefs_register_protocol(proto_imf, NULL);
prefs_register_uat_preference(imf_module, "custom_header_fields", "Custom IMF headers",
"A table to define custom IMF headers for which fields can be "
"setup and used for filtering/data extraction etc.",
headers_uat);
imf_field_table=g_hash_table_new(g_str_hash, g_str_equal);
for(f = imf_fields; f->name; f++)
g_hash_table_insert(imf_field_table, (gpointer)f->name, (gpointer)f);
}
void
proto_reg_handoff_imf(void)
{
dissector_add_string("media_type",
"message/rfc822", imf_handle);
register_ber_oid_dissector_handle("1.2.840.113549.1.7.1", imf_handle, proto_imf, "id-data");
media_type_dissector_table = find_dissector_table("media_type");
}
