void ERR_print_errors_cb(int (*cb)(const char *str, size_t len, void *u),
void *u)
{
unsigned long l;
char buf[256];
char buf2[4096];
const char *file,*data;
int line,flags;
unsigned long es;
es=CRYPTO_thread_id();
while ((l=ERR_get_error_line_data(&file,&line,&data,&flags)) != 0)
{
ERR_error_string_n(l, buf, sizeof buf);
BIO_snprintf(buf2, sizeof(buf2), "%lu:%s:%s:%d:%s\n", es, buf,
file, line, (flags & ERR_TXT_STRING) ? data : "");
cb(buf2, strlen(buf2), u);
}
}
static int print_fp(const char *str, size_t len, void *fp)
{
BIO bio;
BIO_set(&bio,BIO_s_file());
BIO_set_fp(&bio,fp,BIO_NOCLOSE);
return BIO_printf(&bio, "%s", str);
}
void ERR_print_errors_fp(FILE *fp)
{
ERR_print_errors_cb(print_fp, fp);
}
static int print_bio(const char *str, size_t len, void *bp)
{
return BIO_write((BIO *)bp, str, len);
}
void ERR_print_errors(BIO *bp)
{
ERR_print_errors_cb(print_bio, bp);
}
