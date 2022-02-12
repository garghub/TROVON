static FILE *
open_print_dest(gboolean to_file, const char *dest)
{
FILE *fh;
if (to_file)
fh = ws_fopen(dest, "w");
else
fh = popen(dest, "w");
return fh;
}
static gboolean
close_print_dest(gboolean to_file, FILE *fh)
{
if (to_file)
return (fclose(fh) == 0);
else
return (pclose(fh) == 0);
}
gboolean
proto_tree_print(print_args_t *print_args, epan_dissect_t *edt,
print_stream_t *stream)
{
print_data data;
data.level = 0;
data.stream = stream;
data.success = TRUE;
data.src_list = edt->pi.data_src;
data.encoding = (packet_char_enc)edt->pi.fd->flags.encoding;
data.print_dissections = print_args->print_dissections;
data.print_hex_for_data = !print_args->print_hex;
data.edt = edt;
proto_tree_children_foreach(edt->tree, proto_tree_print_node, &data);
return data.success;
}
static void
proto_tree_print_node(proto_node *node, gpointer data)
{
field_info *fi = PNODE_FINFO(node);
print_data *pdata = (print_data*) data;
const guint8 *pd;
gchar label_str[ITEM_LABEL_LENGTH];
gchar *label_ptr;
g_assert(fi);
if (PROTO_ITEM_IS_HIDDEN(node))
return;
if (!pdata->success)
return;
if (fi->rep) {
label_ptr = fi->rep->representation;
}
else {
label_ptr = label_str;
proto_item_fill_label(fi, label_str);
}
if (PROTO_ITEM_IS_GENERATED(node))
label_ptr = g_strconcat("[", label_ptr, "]", NULL);
pdata->success = print_line(pdata->stream, pdata->level, label_ptr);
if (PROTO_ITEM_IS_GENERATED(node))
g_free(label_ptr);
if (!pdata->success)
return;
if ((output_only_tables != NULL) && (pdata->level == 0)
&& (g_hash_table_lookup(output_only_tables, fi->hfinfo->abbrev) == NULL)) {
return;
}
if ((fi->hfinfo->id == proto_data) && (pdata->print_hex_for_data)) {
pd = get_field_data(pdata->src_list, fi);
if (pd) {
if (!print_line(pdata->stream, 0, "")) {
pdata->success = FALSE;
return;
}
if (!print_hex_data_buffer(pdata->stream, pd,
fi->length, pdata->encoding)) {
pdata->success = FALSE;
return;
}
}
}
g_assert((fi->tree_type >= -1) && (fi->tree_type < num_tree_types));
if ((pdata->print_dissections == print_dissections_expanded) ||
((pdata->print_dissections == print_dissections_as_displayed) &&
(fi->tree_type >= 0) && tree_expanded(fi->tree_type))) {
if (node->first_child != NULL) {
pdata->level++;
proto_tree_children_foreach(node,
proto_tree_print_node, pdata);
pdata->level--;
if (!pdata->success)
return;
}
}
}
void
write_pdml_preamble(FILE *fh, const gchar *filename)
{
time_t t = time(NULL);
char *ts = asctime(localtime(&t));
ts[strlen(ts)-1] = 0;
fputs("<?xml version=\"1.0\"?>\n", fh);
fputs("<?xml-stylesheet type=\"text/xsl\" href=\"" PDML2HTML_XSL "\"?>\n", fh);
fprintf(fh, "<!-- You can find " PDML2HTML_XSL " in %s or at http://anonsvn.wireshark.org/trunk/wireshark/" PDML2HTML_XSL ". -->\n", get_datafile_dir());
fputs("<pdml version=\"" PDML_VERSION "\" ", fh);
fprintf(fh, "creator=\"%s/%s\" time=\"%s\" capture_file=\"%s\">\n", PACKAGE, VERSION, ts, filename ? filename : "");
}
void
proto_tree_write_pdml(epan_dissect_t *edt, FILE *fh)
{
write_pdml_data data;
data.level = 0;
data.fh = fh;
data.src_list = edt->pi.data_src;
data.edt = edt;
fprintf(fh, "<packet>\n");
print_pdml_geninfo(edt->tree, fh);
proto_tree_children_foreach(edt->tree, proto_tree_write_node_pdml,
&data);
fprintf(fh, "</packet>\n\n");
}
static void
proto_tree_write_node_pdml(proto_node *node, gpointer data)
{
field_info *fi = PNODE_FINFO(node);
write_pdml_data *pdata = (write_pdml_data*) data;
const gchar *label_ptr;
gchar label_str[ITEM_LABEL_LENGTH];
char *dfilter_string;
int i;
gboolean wrap_in_fake_protocol;
g_assert(fi);
wrap_in_fake_protocol =
(((fi->hfinfo->type != FT_PROTOCOL) ||
(fi->hfinfo->id == proto_data)) &&
(pdata->level == 0));
for (i = -1; i < pdata->level; i++) {
fputs(" ", pdata->fh);
}
if (wrap_in_fake_protocol) {
fputs("<proto name=\"fake-field-wrapper\">\n", pdata->fh);
pdata->level++;
for (i = -1; i < pdata->level; i++) {
fputs(" ", pdata->fh);
}
}
if (fi->hfinfo->id == hf_text_only) {
if (fi->rep) {
label_ptr = fi->rep->representation;
}
else {
label_ptr = "";
}
fputs("<field name=\"", pdata->fh);
fputs("\" show=\"", pdata->fh);
print_escaped_xml(pdata->fh, label_ptr);
fprintf(pdata->fh, "\" size=\"%d", fi->length);
if (node->parent && node->parent->finfo && (fi->start < node->parent->finfo->start)) {
fprintf(pdata->fh, "\" pos=\"%d", node->parent->finfo->start + fi->start);
} else {
fprintf(pdata->fh, "\" pos=\"%d", fi->start);
}
fputs("\" value=\"", pdata->fh);
write_pdml_field_hex_value(pdata, fi);
if (node->first_child != NULL) {
fputs("\">\n", pdata->fh);
}
else {
fputs("\"/>\n", pdata->fh);
}
}
else if (fi->hfinfo->id == proto_data) {
fputs("<field name=\"data\" value=\"", pdata->fh);
write_pdml_field_hex_value(pdata, fi);
fputs("\">\n", pdata->fh);
}
else {
if ((fi->hfinfo->type == FT_PROTOCOL) && (fi->hfinfo->id != proto_expert)) {
fputs("<proto name=\"", pdata->fh);
}
else {
fputs("<field name=\"", pdata->fh);
}
print_escaped_xml(pdata->fh, fi->hfinfo->abbrev);
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if (fi->rep) {
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->rep->representation);
}
else {
label_ptr = label_str;
proto_item_fill_label(fi, label_str);
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, label_ptr);
}
if (PROTO_ITEM_IS_HIDDEN(node))
fprintf(pdata->fh, "\" hide=\"yes");
fprintf(pdata->fh, "\" size=\"%d", fi->length);
if (node->parent && node->parent->finfo && (fi->start < node->parent->finfo->start)) {
fprintf(pdata->fh, "\" pos=\"%d", node->parent->finfo->start + fi->start);
} else {
fprintf(pdata->fh, "\" pos=\"%d", fi->start);
}
switch (fi->hfinfo->type)
{
case FT_PROTOCOL:
break;
case FT_NONE:
fputs("\" show=\"\" value=\"", pdata->fh);
break;
default:
dfilter_string = fvalue_to_string_repr(&fi->value, FTREPR_DISPLAY, NULL);
if (dfilter_string != NULL) {
fputs("\" show=\"", pdata->fh);
print_escaped_xml(pdata->fh, dfilter_string);
}
g_free(dfilter_string);
if (fi->length > 0) {
fputs("\" value=\"", pdata->fh);
if (fi->hfinfo->bitmask!=0) {
switch (fi->value.ftype->ftype) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
fprintf(pdata->fh, "%X", (guint) fvalue_get_sinteger(&fi->value));
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_BOOLEAN:
fprintf(pdata->fh, "%X", fvalue_get_uinteger(&fi->value));
break;
case FT_INT64:
case FT_UINT64:
fprintf(pdata->fh, "%" G_GINT64_MODIFIER "X",
fvalue_get_integer64(&fi->value));
break;
default:
g_assert_not_reached();
}
fputs("\" unmaskedvalue=\"", pdata->fh);
write_pdml_field_hex_value(pdata, fi);
}
else {
write_pdml_field_hex_value(pdata, fi);
}
}
}
if (node->first_child != NULL) {
fputs("\">\n", pdata->fh);
}
else if (fi->hfinfo->id == proto_data) {
fputs("\">\n", pdata->fh);
}
else {
fputs("\"/>\n", pdata->fh);
}
}
if (node->first_child != NULL) {
pdata->level++;
proto_tree_children_foreach(node,
proto_tree_write_node_pdml, pdata);
pdata->level--;
}
if (wrap_in_fake_protocol) {
pdata->level--;
}
if (node->first_child != NULL) {
for (i = -1; i < pdata->level; i++) {
fputs(" ", pdata->fh);
}
if ((fi->hfinfo->id != proto_data) && (fi->hfinfo->id != proto_expert)) {
if (fi->hfinfo->type == FT_PROTOCOL) {
fputs("</proto>\n", pdata->fh);
}
else {
fputs("</field>\n", pdata->fh);
}
} else {
fputs("</field>\n", pdata->fh);
}
}
if (wrap_in_fake_protocol) {
fputs("</proto>\n", pdata->fh);
}
}
static void
print_pdml_geninfo(proto_tree *tree, FILE *fh)
{
guint32 num, len, caplen;
nstime_t *timestamp;
GPtrArray *finfo_array;
field_info *frame_finfo;
gchar *tmp;
finfo_array = proto_find_finfo(tree, proto_frame);
if (g_ptr_array_len(finfo_array) < 1) {
return;
}
frame_finfo = (field_info *)finfo_array->pdata[0];
g_ptr_array_free(finfo_array, TRUE);
finfo_array = proto_find_finfo(tree, hf_frame_number);
if (g_ptr_array_len(finfo_array) < 1) {
return;
}
num = fvalue_get_uinteger(&((field_info*)finfo_array->pdata[0])->value);
g_ptr_array_free(finfo_array, TRUE);
finfo_array = proto_find_finfo(tree, hf_frame_len);
if (g_ptr_array_len(finfo_array) < 1) {
return;
}
len = fvalue_get_uinteger(&((field_info*)finfo_array->pdata[0])->value);
g_ptr_array_free(finfo_array, TRUE);
finfo_array = proto_find_finfo(tree, hf_frame_capture_len);
if (g_ptr_array_len(finfo_array) < 1) {
return;
}
caplen = fvalue_get_uinteger(&((field_info*)finfo_array->pdata[0])->value);
g_ptr_array_free(finfo_array, TRUE);
finfo_array = proto_find_finfo(tree, hf_frame_arrival_time);
if (g_ptr_array_len(finfo_array) < 1) {
return;
}
timestamp = (nstime_t *)fvalue_get(&((field_info*)finfo_array->pdata[0])->value);
g_ptr_array_free(finfo_array, TRUE);
fprintf(fh,
" <proto name=\"geninfo\" pos=\"0\" showname=\"General information\" size=\"%u\">\n",
frame_finfo->length);
fprintf(fh,
" <field name=\"num\" pos=\"0\" show=\"%u\" showname=\"Number\" value=\"%x\" size=\"%u\"/>\n",
num, num, frame_finfo->length);
fprintf(fh,
" <field name=\"len\" pos=\"0\" show=\"%u\" showname=\"Frame Length\" value=\"%x\" size=\"%u\"/>\n",
len, len, frame_finfo->length);
fprintf(fh,
" <field name=\"caplen\" pos=\"0\" show=\"%u\" showname=\"Captured Length\" value=\"%x\" size=\"%u\"/>\n",
caplen, caplen, frame_finfo->length);
tmp = abs_time_to_str(NULL, timestamp, ABSOLUTE_TIME_LOCAL, TRUE);
fprintf(fh,
" <field name=\"timestamp\" pos=\"0\" show=\"%s\" showname=\"Captured Time\" value=\"%d.%09d\" size=\"%u\"/>\n",
tmp, (int) timestamp->secs, timestamp->nsecs, frame_finfo->length);
wmem_free(NULL, tmp);
fprintf(fh,
" </proto>\n");
}
void
write_pdml_finale(FILE *fh)
{
fputs("</pdml>\n", fh);
}
void
write_psml_preamble(FILE *fh)
{
fputs("<?xml version=\"1.0\"?>\n", fh);
fputs("<psml version=\"" PSML_VERSION "\" ", fh);
fprintf(fh, "creator=\"%s/%s\">\n", PACKAGE, VERSION);
write_headers = TRUE;
}
void
proto_tree_write_psml(epan_dissect_t *edt, FILE *fh)
{
gint i;
if (write_headers) {
fprintf(fh, "<structure>\n");
for (i = 0; i < edt->pi.cinfo->num_cols; i++) {
fprintf(fh, "<section>");
print_escaped_xml(fh, edt->pi.cinfo->col_title[i]);
fprintf(fh, "</section>\n");
}
fprintf(fh, "</structure>\n\n");
write_headers = FALSE;
}
fprintf(fh, "<packet>\n");
for (i = 0; i < edt->pi.cinfo->num_cols; i++) {
fprintf(fh, "<section>");
print_escaped_xml(fh, edt->pi.cinfo->col_data[i]);
fprintf(fh, "</section>\n");
}
fprintf(fh, "</packet>\n\n");
}
void
write_psml_finale(FILE *fh)
{
fputs("</psml>\n", fh);
}
void
write_csv_preamble(FILE *fh _U_)
{
write_headers = TRUE;
}
static gchar *csv_massage_str(const gchar *source, const gchar *exceptions)
{
gchar *csv_str;
gchar *tmp_str;
csv_str = g_strescape(source, exceptions);
tmp_str = csv_str;
while ( (tmp_str = strstr(tmp_str, "\xe2\x86\x92")) != NULL ) {
tmp_str[0] = ' ';
tmp_str[1] = '>';
tmp_str[2] = ' ';
}
tmp_str = csv_str;
while ( (tmp_str = strstr(tmp_str, "\\\"")) != NULL )
*tmp_str = '\"';
return csv_str;
}
static void csv_write_str(const char *str, char sep, FILE *fh)
{
gchar *csv_str;
csv_str = csv_massage_str(str, "\xe2\x86\x92");
fprintf(fh, "\"%s\"%c", csv_str, sep);
g_free(csv_str);
}
void
proto_tree_write_csv(epan_dissect_t *edt, FILE *fh)
{
gint i;
if (write_headers) {
for (i = 0; i < edt->pi.cinfo->num_cols - 1; i++)
csv_write_str(edt->pi.cinfo->col_title[i], ',', fh);
csv_write_str(edt->pi.cinfo->col_title[i], '\n', fh);
write_headers = FALSE;
}
for (i = 0; i < edt->pi.cinfo->num_cols - 1; i++)
csv_write_str(edt->pi.cinfo->col_data[i], ',', fh);
csv_write_str(edt->pi.cinfo->col_data[i], '\n', fh);
}
void
write_csv_finale(FILE *fh _U_)
{
}
void
write_carrays_preamble(FILE *fh _U_)
{
}
void
proto_tree_write_carrays(guint32 num, FILE *fh, epan_dissect_t *edt)
{
guint32 i = 0, src_num = 0;
GSList *src_le;
tvbuff_t *tvb;
const char *name;
const guchar *cp;
guint length;
char ascii[9];
struct data_source *src;
for (src_le = edt->pi.data_src; src_le != NULL; src_le = src_le->next) {
memset(ascii, 0, sizeof(ascii));
src = (struct data_source *)src_le->data;
tvb = get_data_source_tvb(src);
length = tvb_length(tvb);
if (length == 0)
continue;
cp = tvb_get_ptr(tvb, 0, length);
name = get_data_source_name(src);
if (name)
fprintf(fh, "/* %s */\n", name);
if (src_num) {
fprintf(fh, "static const unsigned char pkt%u_%u[%u] = {\n",
num, src_num, length);
} else {
fprintf(fh, "static const unsigned char pkt%u[%u] = {\n",
num, length);
}
src_num++;
for (i = 0; i < length; i++) {
fprintf(fh, "0x%02x", *(cp + i));
ascii[i % 8] = g_ascii_isprint(*(cp + i)) ? *(cp + i) : '.';
if (i == (length - 1)) {
guint rem;
rem = length % 8;
if (rem) {
guint j;
for ( j = 0; j < 8 - rem; j++ )
fprintf(fh, " ");
}
fprintf(fh, " /* %s */\n};\n\n", ascii);
break;
}
if (!((i + 1) % 8)) {
fprintf(fh, ", /* %s */\n", ascii);
memset(ascii, 0, sizeof(ascii));
}
else {
fprintf(fh, ", ");
}
}
}
}
void
write_carrays_finale(FILE *fh _U_)
{
}
static const guint8 *
get_field_data(GSList *src_list, field_info *fi)
{
GSList *src_le;
tvbuff_t *src_tvb;
gint length, tvbuff_length;
struct data_source *src;
for (src_le = src_list; src_le != NULL; src_le = src_le->next) {
src = (struct data_source *)src_le->data;
src_tvb = get_data_source_tvb(src);
if (fi->ds_tvb == src_tvb) {
tvbuff_length = tvb_length_remaining(src_tvb,
fi->start);
if (tvbuff_length < 0) {
return NULL;
}
length = fi->length;
if (length > tvbuff_length)
length = tvbuff_length;
return tvb_get_ptr(src_tvb, fi->start, length);
}
}
g_assert_not_reached();
return NULL;
}
static void
print_escaped_xml(FILE *fh, const char *unescaped_string)
{
const char *p;
char temp_str[8];
for (p = unescaped_string; *p != '\0'; p++) {
switch (*p) {
case '&':
fputs("&amp;", fh);
break;
case '<':
fputs("&lt;", fh);
break;
case '>':
fputs("&gt;", fh);
break;
case '"':
fputs("&quot;", fh);
break;
case '\'':
fputs("&#x27;", fh);
break;
default:
if (g_ascii_isprint(*p))
fputc(*p, fh);
else {
g_snprintf(temp_str, sizeof(temp_str), "\\x%x", (guint8)*p);
fputs(temp_str, fh);
}
}
}
}
static void
write_pdml_field_hex_value(write_pdml_data *pdata, field_info *fi)
{
int i;
const guint8 *pd;
if (!fi->ds_tvb)
return;
if (fi->length > tvb_length_remaining(fi->ds_tvb, fi->start)) {
fprintf(pdata->fh, "field length invalid!");
return;
}
pd = get_field_data(pdata->src_list, fi);
if (pd) {
for (i = 0 ; i < fi->length; i++) {
fprintf(pdata->fh, "%02x", pd[i]);
}
}
}
gboolean
print_hex_data(print_stream_t *stream, epan_dissect_t *edt)
{
gboolean multiple_sources;
GSList *src_le;
tvbuff_t *tvb;
const char *name;
char *line;
const guchar *cp;
guint length;
struct data_source *src;
multiple_sources = (edt->pi.data_src->next != NULL);
for (src_le = edt->pi.data_src; src_le != NULL;
src_le = src_le->next) {
src = (struct data_source *)src_le->data;
tvb = get_data_source_tvb(src);
if (multiple_sources) {
name = get_data_source_name(src);
line = g_strdup_printf("%s:", name);
print_line(stream, 0, line);
g_free(line);
}
length = tvb_length(tvb);
if (length == 0)
return TRUE;
cp = tvb_get_ptr(tvb, 0, length);
if (!print_hex_data_buffer(stream, cp, length,
(packet_char_enc)edt->pi.fd->flags.encoding))
return FALSE;
}
return TRUE;
}
static gboolean
print_hex_data_buffer(print_stream_t *stream, const guchar *cp,
guint length, packet_char_enc encoding)
{
register unsigned int ad, i, j, k, l;
guchar c;
gchar line[MAX_LINE_LEN + 1];
unsigned int use_digits;
static gchar binhex[16] = {
'0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
if (((length - 1) & 0xF0000000) != 0)
use_digits = 8;
else if (((length - 1) & 0x0F000000) != 0)
use_digits = 7;
else if (((length - 1) & 0x00F00000) != 0)
use_digits = 6;
else if (((length - 1) & 0x000F0000) != 0)
use_digits = 5;
else
use_digits = 4;
ad = 0;
i = 0;
j = 0;
k = 0;
while (i < length) {
if ((i & 15) == 0) {
j = 0;
l = use_digits;
do {
l--;
c = (ad >> (l*4)) & 0xF;
line[j++] = binhex[c];
} while (l != 0);
line[j++] = ' ';
line[j++] = ' ';
memset(line+j, ' ', DATA_DUMP_LEN);
k = j + HEX_DUMP_LEN + 2;
}
c = *cp++;
line[j++] = binhex[c>>4];
line[j++] = binhex[c&0xf];
j++;
if (encoding == PACKET_CHAR_ENC_CHAR_EBCDIC) {
c = EBCDIC_to_ASCII1(c);
}
line[k++] = ((c >= ' ') && (c < 0x7f)) ? c : '.';
i++;
if (((i & 15) == 0) || (i == length)) {
line[k] = '\0';
if (!print_line(stream, 0, line))
return FALSE;
ad += 16;
}
}
return TRUE;
}
static
void ps_clean_string(char *out, const char *in, int outbuf_size)
{
int rd, wr;
char c;
if (in == NULL) {
out[0] = '\0';
return;
}
for (rd = 0, wr = 0 ; wr < outbuf_size; rd++, wr++ ) {
c = in[rd];
switch (c) {
case '(':
case ')':
case '\\':
out[wr] = '\\';
out[++wr] = c;
break;
default:
out[wr] = c;
break;
}
if (c == 0) {
break;
}
}
}
gboolean
print_preamble(print_stream_t *self, gchar *filename, const char *version_string)
{
return self->ops->print_preamble ? (self->ops->print_preamble)(self, filename, version_string) : TRUE;
}
gboolean
print_line(print_stream_t *self, int indent, const char *line)
{
return (self->ops->print_line)(self, indent, line);
}
gboolean
print_bookmark(print_stream_t *self, const gchar *name, const gchar *title)
{
return self->ops->print_bookmark ? (self->ops->print_bookmark)(self, name, title) : TRUE;
}
gboolean
new_page(print_stream_t *self)
{
return self->ops->new_page ? (self->ops->new_page)(self) : TRUE;
}
gboolean
print_finale(print_stream_t *self)
{
return self->ops->print_finale ? (self->ops->print_finale)(self) : TRUE;
}
gboolean
destroy_print_stream(print_stream_t *self)
{
return self->ops->destroy ? (self->ops->destroy)(self) : TRUE;
}
static gboolean
print_line_text(print_stream_t *self, int indent, const char *line)
{
static char spaces[MAX_INDENT];
size_t ret;
output_text *output = (output_text *)self->data;
unsigned int num_spaces;
if (!spaces[0]) {
int i;
for (i = 0; i < MAX_INDENT; i++)
spaces[i] = ' ';
}
num_spaces = indent * 4;
if (num_spaces > MAX_INDENT)
num_spaces = MAX_INDENT;
ret = fwrite(spaces, 1, num_spaces, output->fh);
if (ret == num_spaces) {
fputs(line, output->fh);
putc('\n', output->fh);
}
return !ferror(output->fh);
}
static gboolean
new_page_text(print_stream_t *self)
{
output_text *output = (output_text *)self->data;
fputs("\f", output->fh);
return !ferror(output->fh);
}
static gboolean
destroy_text(print_stream_t *self)
{
output_text *output = (output_text *)self->data;
gboolean ret;
ret = close_print_dest(output->to_file, output->fh);
g_free(output);
g_free(self);
return ret;
}
static print_stream_t *
print_stream_text_alloc(gboolean to_file, FILE *fh)
{
print_stream_t *stream;
output_text *output;
output = (output_text *)g_malloc(sizeof *output);
output->to_file = to_file;
output->fh = fh;
stream = (print_stream_t *)g_malloc(sizeof (print_stream_t));
stream->ops = &print_text_ops;
stream->data = output;
return stream;
}
print_stream_t *
print_stream_text_new(gboolean to_file, const char *dest)
{
FILE *fh;
fh = open_print_dest(to_file, dest);
if (fh == NULL)
return NULL;
return print_stream_text_alloc(to_file, fh);
}
print_stream_t *
print_stream_text_stdio_new(FILE *fh)
{
return print_stream_text_alloc(TRUE, fh);
}
static gboolean
print_preamble_ps(print_stream_t *self, gchar *filename, const char *version_string)
{
output_ps *output = (output_ps *)self->data;
char psbuffer[MAX_PS_LINE_LENGTH];
print_ps_preamble(output->fh);
fputs("%% the page title\n", output->fh);
ps_clean_string(psbuffer, filename, MAX_PS_LINE_LENGTH);
fprintf(output->fh, "/ws_pagetitle (%s - Wireshark %s) def\n", psbuffer, version_string);
fputs("\n", output->fh);
return !ferror(output->fh);
}
static gboolean
print_line_ps(print_stream_t *self, int indent, const char *line)
{
output_ps *output = (output_ps *)self->data;
char psbuffer[MAX_PS_LINE_LENGTH];
ps_clean_string(psbuffer, line, MAX_PS_LINE_LENGTH);
fprintf(output->fh, "%d (%s) putline\n", indent, psbuffer);
return !ferror(output->fh);
}
static gboolean
print_bookmark_ps(print_stream_t *self, const gchar *name, const gchar *title)
{
output_ps *output = (output_ps *)self->data;
char psbuffer[MAX_PS_LINE_LENGTH];
ps_clean_string(psbuffer, title, MAX_PS_LINE_LENGTH);
fprintf(output->fh, "[/Dest /%s /Title (%s) /OUT pdfmark\n", name,
psbuffer);
fputs("[/View [/XYZ -4 currentpoint matrix currentmatrix matrix defaultmatrix\n",
output->fh);
fputs("matrix invertmatrix matrix concatmatrix transform exch pop 20 add null]\n",
output->fh);
fprintf(output->fh, "/Dest /%s /DEST pdfmark\n", name);
return !ferror(output->fh);
}
static gboolean
new_page_ps(print_stream_t *self)
{
output_ps *output = (output_ps *)self->data;
fputs("formfeed\n", output->fh);
return !ferror(output->fh);
}
static gboolean
print_finale_ps(print_stream_t *self)
{
output_ps *output = (output_ps *)self->data;
print_ps_finale(output->fh);
return !ferror(output->fh);
}
static gboolean
destroy_ps(print_stream_t *self)
{
output_ps *output = (output_ps *)self->data;
gboolean ret;
ret = close_print_dest(output->to_file, output->fh);
g_free(output);
g_free(self);
return ret;
}
static print_stream_t *
print_stream_ps_alloc(gboolean to_file, FILE *fh)
{
print_stream_t *stream;
output_ps *output;
output = (output_ps *)g_malloc(sizeof *output);
output->to_file = to_file;
output->fh = fh;
stream = (print_stream_t *)g_malloc(sizeof (print_stream_t));
stream->ops = &print_ps_ops;
stream->data = output;
return stream;
}
print_stream_t *
print_stream_ps_new(gboolean to_file, const char *dest)
{
FILE *fh;
fh = open_print_dest(to_file, dest);
if (fh == NULL)
return NULL;
return print_stream_ps_alloc(to_file, fh);
}
print_stream_t *
print_stream_ps_stdio_new(FILE *fh)
{
return print_stream_ps_alloc(TRUE, fh);
}
output_fields_t* output_fields_new(void)
{
output_fields_t* fields = g_new(output_fields_t, 1);
fields->print_header = FALSE;
fields->separator = '\t';
fields->occurrence = 'a';
fields->aggregator = ',';
fields->fields = NULL;
fields->field_indicies = NULL;
fields->field_values = NULL;
fields->quote ='\0';
fields->includes_col_fields = FALSE;
return fields;
}
gsize output_fields_num_fields(output_fields_t* fields)
{
g_assert(fields);
if (NULL == fields->fields) {
return 0;
} else {
return fields->fields->len;
}
}
void output_fields_free(output_fields_t* fields)
{
g_assert(fields);
if (NULL != fields->fields) {
gsize i;
if (NULL != fields->field_indicies) {
g_hash_table_destroy(fields->field_indicies);
}
if (NULL != fields->field_values) {
g_free(fields->field_values);
}
for(i = 0; i < fields->fields->len; ++i) {
gchar* field = (gchar *)g_ptr_array_index(fields->fields,i);
g_free(field);
}
g_ptr_array_free(fields->fields, TRUE);
}
g_free(fields);
}
void output_fields_add(output_fields_t *fields, const gchar *field)
{
gchar *field_copy;
g_assert(fields);
g_assert(field);
if (NULL == fields->fields) {
fields->fields = g_ptr_array_new();
}
field_copy = g_strdup(field);
g_ptr_array_add(fields->fields, field_copy);
if (!strncmp(field, COLUMN_FIELD_FILTER, strlen(COLUMN_FIELD_FILTER)))
fields->includes_col_fields = TRUE;
}
static void
output_field_check(void *data, void *user_data)
{
gchar *field = (gchar *)data;
gboolean *all_valid = (gboolean *)user_data;
if (!strncmp(field, COLUMN_FIELD_FILTER, strlen(COLUMN_FIELD_FILTER)))
return;
if (!proto_registrar_get_byname(field)) {
g_warning("'%s' isn't a valid field!", field);
*all_valid = FALSE;
}
}
gboolean
output_fields_valid(output_fields_t *fields)
{
gboolean all_valid = TRUE;
if (fields->fields == NULL) {
return TRUE;
}
g_ptr_array_foreach(fields->fields, output_field_check, &all_valid);
return all_valid;
}
gboolean output_fields_set_option(output_fields_t *info, gchar *option)
{
const gchar *option_name;
const gchar *option_value;
g_assert(info);
g_assert(option);
if ('\0' == *option) {
return FALSE;
}
option_name = strtok(option, "=");
if (!option_name) {
return FALSE;
}
option_value = option + strlen(option_name) + 1;
if (0 == strcmp(option_name, "header")) {
switch (NULL == option_value ? '\0' : *option_value) {
case 'n':
info->print_header = FALSE;
break;
case 'y':
info->print_header = TRUE;
break;
default:
return FALSE;
}
return TRUE;
}
if (0 == strcmp(option_name, "separator")) {
switch (NULL == option_value ? '\0' : *option_value) {
case '\0':
return FALSE;
case '/':
switch (*++option_value) {
case 't':
info->separator = '\t';
break;
case 's':
info->separator = ' ';
break;
default:
info->separator = '\\';
}
break;
default:
info->separator = *option_value;
break;
}
return TRUE;
}
if (0 == strcmp(option_name, "occurrence")) {
switch (NULL == option_value ? '\0' : *option_value) {
case 'f':
case 'l':
case 'a':
info->occurrence = *option_value;
break;
default:
return FALSE;
}
return TRUE;
}
if (0 == strcmp(option_name, "aggregator")) {
switch (NULL == option_value ? '\0' : *option_value) {
case '\0':
return FALSE;
case '/':
switch (*++option_value) {
case 's':
info->aggregator = ' ';
break;
default:
info->aggregator = '\\';
}
break;
default:
info->aggregator = *option_value;
break;
}
return TRUE;
}
if (0 == strcmp(option_name, "quote")) {
switch (NULL == option_value ? '\0' : *option_value) {
default:
case '\0':
info->quote = '\0';
return FALSE;
case 'd':
info->quote = '"';
break;
case 's':
info->quote = '\'';
break;
case 'n':
info->quote = '\0';
break;
}
return TRUE;
}
return FALSE;
}
void output_fields_list_options(FILE *fh)
{
fprintf(fh, "TShark: The available options for field output \"E\" are:\n");
fputs("header=y|n Print field abbreviations as first line of output (def: N: no)\n", fh);
fputs("separator=/t|/s|<character> Set the separator to use;\n \"/t\" = tab, \"/s\" = space (def: /t: tab)\n", fh);
fputs("occurrence=f|l|a Select the occurrence of a field to use;\n \"f\" = first, \"l\" = last, \"a\" = all (def: a: all)\n", fh);
fputs("aggregator=,|/s|<character> Set the aggregator to use;\n \",\" = comma, \"/s\" = space (def: ,: comma)\n", fh);
fputs("quote=d|s|n Print either d: double-quotes, s: single quotes or \n n: no quotes around field values (def: n: none)\n", fh);
}
gboolean output_fields_has_cols(output_fields_t* fields)
{
g_assert(fields);
return fields->includes_col_fields;
}
void write_fields_preamble(output_fields_t* fields, FILE *fh)
{
gsize i;
g_assert(fields);
g_assert(fh);
g_assert(fields->fields);
if (!fields->print_header) {
return;
}
for(i = 0; i < fields->fields->len; ++i) {
const gchar* field = (const gchar *)g_ptr_array_index(fields->fields,i);
if (i != 0 ) {
fputc(fields->separator, fh);
}
fputs(field, fh);
}
fputc('\n', fh);
}
static void format_field_values(output_fields_t* fields, gpointer field_index, const gchar* value)
{
guint indx;
GPtrArray* fv_p;
if ((NULL == value) || ('\0' == *value))
return;
indx = GPOINTER_TO_UINT(field_index) - 1;
if (fields->field_values[indx] == NULL) {
fields->field_values[indx] = g_ptr_array_new();
}
fv_p = fields->field_values[indx];
switch (fields->occurrence) {
case 'f':
if (g_ptr_array_len(fv_p) != 0)
return;
break;
case 'l':
g_ptr_array_set_size(fv_p, 0);
break;
case 'a':
if (g_ptr_array_len(fv_p) > 0) {
g_ptr_array_add(fv_p, (gpointer)g_strdup_printf("%c", fields->aggregator));
}
break;
default:
g_assert_not_reached();
break;
}
g_ptr_array_add(fv_p, (gpointer)value);
}
static void proto_tree_get_node_field_values(proto_node *node, gpointer data)
{
write_field_data_t *call_data;
field_info *fi;
gpointer field_index;
call_data = (write_field_data_t *)data;
fi = PNODE_FINFO(node);
g_assert(fi);
field_index = g_hash_table_lookup(call_data->fields->field_indicies, fi->hfinfo->abbrev);
if (NULL != field_index) {
format_field_values(call_data->fields, field_index,
get_node_field_value(fi, call_data->edt)
);
}
if (node->first_child != NULL) {
proto_tree_children_foreach(node, proto_tree_get_node_field_values,
call_data);
}
}
void proto_tree_write_fields(output_fields_t *fields, epan_dissect_t *edt, column_info *cinfo, FILE *fh)
{
gsize i;
gint col;
gchar *col_name;
gpointer field_index;
write_field_data_t data;
g_assert(fields);
g_assert(fields->fields);
g_assert(edt);
g_assert(fh);
data.fields = fields;
data.edt = edt;
if (NULL == fields->field_indicies) {
fields->field_indicies = g_hash_table_new(g_str_hash, g_str_equal);
i = 0;
while (i < fields->fields->len) {
gchar *field = (gchar *)g_ptr_array_index(fields->fields, i);
++i;
g_hash_table_insert(fields->field_indicies, field, GUINT_TO_POINTER(i));
}
}
if (NULL == fields->field_values)
fields->field_values = g_new0(GPtrArray*, fields->fields->len);
proto_tree_children_foreach(edt->tree, proto_tree_get_node_field_values,
&data);
if (fields->includes_col_fields) {
for (col = 0; col < cinfo->num_cols; col++) {
col_name = ep_strdup_printf("%s%s", COLUMN_FIELD_FILTER, cinfo->col_title[col]);
field_index = g_hash_table_lookup(fields->field_indicies, col_name);
if (NULL != field_index) {
format_field_values(fields, field_index, g_strdup(cinfo->col_data[col]));
}
}
}
for(i = 0; i < fields->fields->len; ++i) {
if (0 != i) {
fputc(fields->separator, fh);
}
if (NULL != fields->field_values[i]) {
GPtrArray *fv_p;
gchar * str;
gsize j;
fv_p = fields->field_values[i];
if (fields->quote != '\0') {
fputc(fields->quote, fh);
}
for (j = 0; j < g_ptr_array_len(fv_p); j++ ) {
str = (gchar *)g_ptr_array_index(fv_p, j);
fputs(str, fh);
g_free(str);
}
if (fields->quote != '\0') {
fputc(fields->quote, fh);
}
g_ptr_array_free(fv_p, TRUE);
fields->field_values[i] = NULL;
}
}
}
void write_fields_finale(output_fields_t* fields _U_ , FILE *fh _U_)
{
}
gchar* get_node_field_value(field_info* fi, epan_dissect_t* edt)
{
if (fi->hfinfo->id == hf_text_only) {
if (fi->rep) {
return g_strdup(fi->rep->representation);
}
else {
return get_field_hex_value(edt->pi.data_src, fi);
}
}
else if (fi->hfinfo->id == proto_data) {
return get_field_hex_value(edt->pi.data_src, fi);
}
else {
gchar *dfilter_string;
switch (fi->hfinfo->type)
{
case FT_PROTOCOL:
if (fi->rep) {
return g_strdup(fi->rep->representation);
} else {
return g_strdup(fi->hfinfo->abbrev);
}
case FT_NONE:
return g_strdup("1");
default:
dfilter_string = fvalue_to_string_repr(&fi->value, FTREPR_DISPLAY, NULL);
if (dfilter_string != NULL) {
return dfilter_string;
} else {
return get_field_hex_value(edt->pi.data_src, fi);
}
}
}
}
static gchar*
get_field_hex_value(GSList *src_list, field_info *fi)
{
const guint8 *pd;
if (!fi->ds_tvb)
return NULL;
if (fi->length > tvb_length_remaining(fi->ds_tvb, fi->start)) {
return g_strdup("field length invalid!");
}
pd = get_field_data(src_list, fi);
if (pd) {
int i;
gchar *buffer;
gchar *p;
int len;
const int chars_per_byte = 2;
len = chars_per_byte * fi->length;
buffer = (gchar *)g_malloc(sizeof(gchar)*(len + 1));
buffer[len] = '\0';
p = buffer;
for (i = 0 ; i < fi->length; i++) {
g_snprintf(p, chars_per_byte+1, "%02x", pd[i]);
p += chars_per_byte;
}
return buffer;
} else {
return NULL;
}
}
