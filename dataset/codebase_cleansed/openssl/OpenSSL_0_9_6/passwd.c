int MAIN(int argc, char **argv)
{
int ret = 1;
char *infile = NULL;
int in_stdin = 0;
char *salt = NULL, *passwd = NULL, **passwds = NULL;
char *salt_malloc = NULL, *passwd_malloc = NULL;
size_t passwd_malloc_size = 0;
int pw_source_defined = 0;
BIO *in = NULL, *out = NULL;
int i, badopt, opt_done;
int passed_salt = 0, quiet = 0, table = 0, reverse = 0;
int usecrypt = 0, use1 = 0, useapr1 = 0;
size_t pw_maxlen = 0;
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
out = BIO_new(BIO_s_file());
if (out == NULL)
goto err;
BIO_set_fp(out, stdout, BIO_NOCLOSE | BIO_FP_TEXT);
#ifdef VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
out = BIO_push(tmpbio, out);
}
#endif
badopt = 0, opt_done = 0;
i = 0;
while (!badopt && !opt_done && argv[++i] != NULL)
{
if (strcmp(argv[i], "-crypt") == 0)
usecrypt = 1;
else if (strcmp(argv[i], "-1") == 0)
use1 = 1;
else if (strcmp(argv[i], "-apr1") == 0)
useapr1 = 1;
else if (strcmp(argv[i], "-salt") == 0)
{
if ((argv[i+1] != NULL) && (salt == NULL))
{
passed_salt = 1;
salt = argv[++i];
}
else
badopt = 1;
}
else if (strcmp(argv[i], "-in") == 0)
{
if ((argv[i+1] != NULL) && !pw_source_defined)
{
pw_source_defined = 1;
infile = argv[++i];
}
else
badopt = 1;
}
else if (strcmp(argv[i], "-stdin") == 0)
{
if (!pw_source_defined)
{
pw_source_defined = 1;
in_stdin = 1;
}
else
badopt = 1;
}
else if (strcmp(argv[i], "-quiet") == 0)
quiet = 1;
else if (strcmp(argv[i], "-table") == 0)
table = 1;
else if (strcmp(argv[i], "-reverse") == 0)
reverse = 1;
else if (argv[i][0] == '-')
badopt = 1;
else if (!pw_source_defined)
{
pw_source_defined = 1;
passwds = &argv[i];
opt_done = 1;
}
else
badopt = 1;
}
if (!usecrypt && !use1 && !useapr1)
usecrypt = 1;
if (usecrypt + use1 + useapr1 > 1)
badopt = 1;
#ifdef NO_DES
if (usecrypt) badopt = 1;
#endif
#ifdef NO_MD5CRYPT_1
if (use1 || useapr1) badopt = 1;
#endif
if (badopt)
{
BIO_printf(bio_err, "Usage: passwd [options] [passwords]\n");
BIO_printf(bio_err, "where options are\n");
#ifndef NO_DES
BIO_printf(bio_err, "-crypt standard Unix password algorithm (default)\n");
#endif
#ifndef NO_MD5CRYPT_1
BIO_printf(bio_err, "-1 MD5-based password algorithm\n");
BIO_printf(bio_err, "-apr1 MD5-based password algorithm, Apache variant\n");
#endif
BIO_printf(bio_err, "-salt string use provided salt\n");
BIO_printf(bio_err, "-in file read passwords from file\n");
BIO_printf(bio_err, "-stdin read passwords from stdin\n");
BIO_printf(bio_err, "-quiet no warnings\n");
BIO_printf(bio_err, "-table format output as table\n");
BIO_printf(bio_err, "-reverse switch table columns\n");
goto err;
}
if ((infile != NULL) || in_stdin)
{
in = BIO_new(BIO_s_file());
if (in == NULL)
goto err;
if (infile != NULL)
{
assert(in_stdin == 0);
if (BIO_read_filename(in, infile) <= 0)
goto err;
}
else
{
assert(in_stdin);
BIO_set_fp(in, stdin, BIO_NOCLOSE);
}
}
if (usecrypt)
pw_maxlen = 8;
else if (use1 || useapr1)
pw_maxlen = 256;
if (passwds == NULL)
{
passwd_malloc_size = pw_maxlen + 2;
passwd = passwd_malloc = OPENSSL_malloc(passwd_malloc_size);
if (passwd_malloc == NULL)
goto err;
}
if ((in == NULL) && (passwds == NULL))
{
static char *passwds_static[2] = {NULL, NULL};
passwds = passwds_static;
if (in == NULL)
if (EVP_read_pw_string(passwd_malloc, passwd_malloc_size, "Password: ", 0) != 0)
goto err;
passwds[0] = passwd_malloc;
}
if (in == NULL)
{
assert(passwds != NULL);
assert(*passwds != NULL);
do
{
passwd = *passwds++;
if (!do_passwd(passed_salt, &salt, &salt_malloc, passwd, out,
quiet, table, reverse, pw_maxlen, usecrypt, use1, useapr1))
goto err;
}
while (*passwds != NULL);
}
else
{
int done;
assert (passwd != NULL);
do
{
int r = BIO_gets(in, passwd, pw_maxlen + 1);
if (r > 0)
{
char *c = (strchr(passwd, '\n')) ;
if (c != NULL)
*c = 0;
else
{
char trash[BUFSIZ];
do
r = BIO_gets(in, trash, sizeof trash);
while ((r > 0) && (!strchr(trash, '\n')));
}
if (!do_passwd(passed_salt, &salt, &salt_malloc, passwd, out,
quiet, table, reverse, pw_maxlen, usecrypt, use1, useapr1))
goto err;
}
done = (r <= 0);
}
while (!done);
}
err:
ERR_print_errors(bio_err);
if (salt_malloc)
OPENSSL_free(salt_malloc);
if (passwd_malloc)
OPENSSL_free(passwd_malloc);
if (in)
BIO_free(in);
if (out)
BIO_free_all(out);
EXIT(ret);
}
static char *md5crypt(const char *passwd, const char *magic, const char *salt)
{
static char out_buf[6 + 9 + 24 + 2];
unsigned char buf[MD5_DIGEST_LENGTH];
char *salt_out;
int n, i;
MD5_CTX md;
size_t passwd_len, salt_len;
passwd_len = strlen(passwd);
out_buf[0] = '$';
out_buf[1] = 0;
assert(strlen(magic) <= 4);
strncat(out_buf, magic, 4);
strncat(out_buf, "$", 1);
strncat(out_buf, salt, 8);
assert(strlen(out_buf) <= 6 + 8);
salt_out = out_buf + 6;
salt_len = strlen(salt_out);
assert(salt_len <= 8);
MD5_Init(&md);
MD5_Update(&md, passwd, passwd_len);
MD5_Update(&md, "$", 1);
MD5_Update(&md, magic, strlen(magic));
MD5_Update(&md, "$", 1);
MD5_Update(&md, salt_out, salt_len);
{
MD5_CTX md2;
MD5_Init(&md2);
MD5_Update(&md2, passwd, passwd_len);
MD5_Update(&md2, salt_out, salt_len);
MD5_Update(&md2, passwd, passwd_len);
MD5_Final(buf, &md2);
}
for (i = passwd_len; i > sizeof buf; i -= sizeof buf)
MD5_Update(&md, buf, sizeof buf);
MD5_Update(&md, buf, i);
n = passwd_len;
while (n)
{
MD5_Update(&md, (n & 1) ? "\0" : passwd, 1);
n >>= 1;
}
MD5_Final(buf, &md);
for (i = 0; i < 1000; i++)
{
MD5_CTX md2;
MD5_Init(&md2);
MD5_Update(&md2, (i & 1) ? (unsigned char *) passwd : buf,
(i & 1) ? passwd_len : sizeof buf);
if (i % 3)
MD5_Update(&md2, salt_out, salt_len);
if (i % 7)
MD5_Update(&md2, passwd, passwd_len);
MD5_Update(&md2, (i & 1) ? buf : (unsigned char *) passwd,
(i & 1) ? sizeof buf : passwd_len);
MD5_Final(buf, &md2);
}
{
unsigned char buf_perm[sizeof buf];
int dest, source;
char *output;
for (dest = 0, source = 0; dest < 14; dest++, source = (source + 6) % 17)
buf_perm[dest] = buf[source];
buf_perm[14] = buf[5];
buf_perm[15] = buf[11];
#ifndef PEDANTIC
assert(16 == sizeof buf_perm);
#endif
output = salt_out + salt_len;
assert(output == out_buf + strlen(out_buf));
*output++ = '$';
for (i = 0; i < 15; i += 3)
{
*output++ = cov_2char[buf_perm[i+2] & 0x3f];
*output++ = cov_2char[((buf_perm[i+1] & 0xf) << 2) |
(buf_perm[i+2] >> 6)];
*output++ = cov_2char[((buf_perm[i] & 3) << 4) |
(buf_perm[i+1] >> 4)];
*output++ = cov_2char[buf_perm[i] >> 2];
}
assert(i == 15);
*output++ = cov_2char[buf_perm[i] & 0x3f];
*output++ = cov_2char[buf_perm[i] >> 6];
*output = 0;
assert(strlen(out_buf) < sizeof(out_buf));
}
return out_buf;
}
static int do_passwd(int passed_salt, char **salt_p, char **salt_malloc_p,
char *passwd, BIO *out, int quiet, int table, int reverse,
size_t pw_maxlen, int usecrypt, int use1, int useapr1)
{
char *hash = NULL;
assert(salt_p != NULL);
assert(salt_malloc_p != NULL);
if (!passed_salt)
{
#ifndef NO_DES
if (usecrypt)
{
if (*salt_malloc_p == NULL)
{
*salt_p = *salt_malloc_p = OPENSSL_malloc(3);
if (*salt_malloc_p == NULL)
goto err;
}
if (RAND_pseudo_bytes((unsigned char *)*salt_p, 2) < 0)
goto err;
(*salt_p)[0] = cov_2char[(*salt_p)[0] & 0x3f];
(*salt_p)[1] = cov_2char[(*salt_p)[1] & 0x3f];
(*salt_p)[2] = 0;
#ifdef CHARSET_EBCDIC
ascii2ebcdic(*salt_p, *salt_p, 2);
#endif
}
#endif
#ifndef NO_MD5CRYPT_1
if (use1 || useapr1)
{
int i;
if (*salt_malloc_p == NULL)
{
*salt_p = *salt_malloc_p = OPENSSL_malloc(9);
if (*salt_malloc_p == NULL)
goto err;
}
if (RAND_pseudo_bytes((unsigned char *)*salt_p, 8) < 0)
goto err;
for (i = 0; i < 8; i++)
(*salt_p)[i] = cov_2char[(*salt_p)[i] & 0x3f];
(*salt_p)[8] = 0;
}
#endif
}
assert(*salt_p != NULL);
if ((strlen(passwd) > pw_maxlen))
{
if (!quiet)
BIO_printf(bio_err, "Warning: truncating password to %u characters\n", pw_maxlen);
passwd[pw_maxlen] = 0;
}
assert(strlen(passwd) <= pw_maxlen);
#ifndef NO_DES
if (usecrypt)
hash = des_crypt(passwd, *salt_p);
#endif
#ifndef NO_MD5CRYPT_1
if (use1 || useapr1)
hash = md5crypt(passwd, (use1 ? "1" : "apr1"), *salt_p);
#endif
assert(hash != NULL);
if (table && !reverse)
BIO_printf(out, "%s\t%s\n", passwd, hash);
else if (table && reverse)
BIO_printf(out, "%s\t%s\n", hash, passwd);
else
BIO_printf(out, "%s\n", hash);
return 1;
err:
return 0;
}
int MAIN(int argc, char **argv)
{
fputs("Program not available.\n", stderr)
EXIT(1);
}
