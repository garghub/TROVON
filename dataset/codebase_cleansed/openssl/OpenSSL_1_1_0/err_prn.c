void ERR_print_errors_cb(int (*cb) (const char *str, size_t len, void *u),
void *u)
{
unsigned long l;
char buf[256];
char buf2[4096];
const char *file, *data;
int line, flags;
union {
CRYPTO_THREAD_ID tid;
unsigned long ltid;
} tid;
tid.ltid = 0;
tid.tid = CRYPTO_THREAD_get_current_id();
while ((l = ERR_get_error_line_data(&file, &line, &data, &flags)) != 0) {
ERR_error_string_n(l, buf, sizeof buf);
BIO_snprintf(buf2, sizeof(buf2), "%lu:%s:%s:%d:%s\n", tid.ltid, buf,
file, line, (flags & ERR_TXT_STRING) ? data : "");
if (cb(buf2, strlen(buf2), u) <= 0)
break;
}
}
static int print_bio(const char *str, size_t len, void *bp)
{
return BIO_write((BIO *)bp, str, len);
}
void ERR_print_errors(BIO *bp)
{
ERR_print_errors_cb(print_bio, bp);
}
void ERR_print_errors_fp(FILE *fp)
{
BIO *bio = BIO_new_fp(fp, BIO_NOCLOSE);
if (bio == NULL)
return;
ERR_print_errors_cb(print_bio, bio);
BIO_free(bio);
}
