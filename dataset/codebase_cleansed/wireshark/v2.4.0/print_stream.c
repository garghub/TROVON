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
return (self && self->ops && self->ops->destroy) ? (self->ops->destroy)(self) : TRUE;
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
gchar *tty_out = NULL;
if (self->isatty && self->to_codeset) {
tty_out = g_convert_with_fallback(line, -1, self->to_codeset, "UTF-8", "?", NULL, NULL, NULL);
}
if (tty_out) {
#ifdef _WIN32
DWORD out_len = (DWORD) wcslen((wchar_t *) tty_out);
WriteConsoleW((HANDLE)_get_osfhandle(_fileno(output->fh)), tty_out, out_len, &out_len, NULL);
#else
fputs(tty_out, output->fh);
#endif
g_free(tty_out);
} else {
fputs(line, output->fh);
}
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
#ifndef _WIN32
const gchar *charset;
gboolean is_utf8;
#endif
output = (output_text *)g_malloc(sizeof *output);
output->to_file = to_file;
output->fh = fh;
stream = (print_stream_t *)g_malloc0(sizeof (print_stream_t));
stream->ops = &print_text_ops;
stream->isatty = ws_isatty(ws_fileno(fh));
stream->data = output;
#ifndef _WIN32
is_utf8 = g_get_charset(&charset);
if (!is_utf8) {
stream->to_codeset = charset;
}
#else
stream->to_codeset = "UTF-16LE";
#endif
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
