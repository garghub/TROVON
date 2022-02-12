int MAIN(int argc, char **argv)
{
int i, r, ret = 1;
int badopt;
char *outfile = NULL;
char *inrand = NULL;
int base64 = 0;
int hex = 0;
BIO *out = NULL;
int num = -1;
#ifndef OPENSSL_NO_ENGINE
char *engine=NULL;
#endif
apps_startup();
if (bio_err == NULL)
if ((bio_err = BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err, stderr, BIO_NOCLOSE|BIO_FP_TEXT);
if (!load_config(bio_err, NULL))
goto err;
badopt = 0;
i = 0;
while (!badopt && argv[++i] != NULL)
{
if (strcmp(argv[i], "-out") == 0)
{
if ((argv[i+1] != NULL) && (outfile == NULL))
outfile = argv[++i];
else
badopt = 1;
}
#ifndef OPENSSL_NO_ENGINE
else if (strcmp(argv[i], "-engine") == 0)
{
if ((argv[i+1] != NULL) && (engine == NULL))
engine = argv[++i];
else
badopt = 1;
}
#endif
else if (strcmp(argv[i], "-rand") == 0)
{
if ((argv[i+1] != NULL) && (inrand == NULL))
inrand = argv[++i];
else
badopt = 1;
}
else if (strcmp(argv[i], "-base64") == 0)
{
if (!base64)
base64 = 1;
else
badopt = 1;
}
else if (strcmp(argv[i], "-hex") == 0)
{
if (!hex)
hex = 1;
else
badopt = 1;
}
else if (isdigit((unsigned char)argv[i][0]))
{
if (num < 0)
{
r = sscanf(argv[i], "%d", &num);
if (r == 0 || num < 0)
badopt = 1;
}
else
badopt = 1;
}
else
badopt = 1;
}
if (hex && base64)
badopt = 1;
if (num < 0)
badopt = 1;
if (badopt)
{
BIO_printf(bio_err, "Usage: rand [options] num\n");
BIO_printf(bio_err, "where options are\n");
BIO_printf(bio_err, "-out file - write to file\n");
#ifndef OPENSSL_NO_ENGINE
BIO_printf(bio_err, "-engine e - use engine e, possibly a hardware device.\n");
#endif
BIO_printf(bio_err, "-rand file%cfile%c... - seed PRNG from files\n", LIST_SEPARATOR_CHAR, LIST_SEPARATOR_CHAR);
BIO_printf(bio_err, "-base64 - base64 encode output\n");
BIO_printf(bio_err, "-hex - hex encode output\n");
goto err;
}
#ifndef OPENSSL_NO_ENGINE
setup_engine(bio_err, engine, 0);
#endif
app_RAND_load_file(NULL, bio_err, (inrand != NULL));
if (inrand != NULL)
BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
app_RAND_load_files(inrand));
out = BIO_new(BIO_s_file());
if (out == NULL)
goto err;
if (outfile != NULL)
r = BIO_write_filename(out, outfile);
else
{
r = BIO_set_fp(out, stdout, BIO_NOCLOSE | BIO_FP_TEXT);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
}
if (r <= 0)
goto err;
if (base64)
{
BIO *b64 = BIO_new(BIO_f_base64());
if (b64 == NULL)
goto err;
out = BIO_push(b64, out);
}
while (num > 0)
{
unsigned char buf[4096];
int chunk;
chunk = num;
if (chunk > (int)sizeof(buf))
chunk = sizeof buf;
r = RAND_bytes(buf, chunk);
if (r <= 0)
goto err;
if (!hex)
BIO_write(out, buf, chunk);
else
{
for (i = 0; i < chunk; i++)
BIO_printf(out, "%02x", buf[i]);
}
num -= chunk;
}
if (hex)
BIO_puts(out, "\n");
(void)BIO_flush(out);
app_RAND_write_file(NULL, bio_err);
ret = 0;
err:
ERR_print_errors(bio_err);
if (out)
BIO_free_all(out);
apps_shutdown();
OPENSSL_EXIT(ret);
}
