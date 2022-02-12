int passwd_main(int argc, char **argv)
{
BIO *in = NULL;
char *infile = NULL, *salt = NULL, *passwd = NULL, **passwds = NULL;
char *salt_malloc = NULL, *passwd_malloc = NULL, *prog;
OPTION_CHOICE o;
int in_stdin = 0, pw_source_defined = 0;
#ifndef OPENSSL_NO_UI
int in_noverify = 0;
#endif
int passed_salt = 0, quiet = 0, table = 0, reverse = 0;
int ret = 1, usecrypt = 0, use1 = 0, useapr1 = 0;
size_t passwd_malloc_size = 0, pw_maxlen = 256;
prog = opt_init(argc, argv, passwd_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(passwd_options);
ret = 0;
goto end;
case OPT_IN:
if (pw_source_defined)
goto opthelp;
infile = opt_arg();
pw_source_defined = 1;
break;
case OPT_NOVERIFY:
#ifndef OPENSSL_NO_UI
in_noverify = 1;
#endif
break;
case OPT_QUIET:
quiet = 1;
break;
case OPT_TABLE:
table = 1;
break;
case OPT_REVERSE:
reverse = 1;
break;
case OPT_1:
use1 = 1;
break;
case OPT_APR1:
useapr1 = 1;
break;
case OPT_CRYPT:
usecrypt = 1;
break;
case OPT_SALT:
passed_salt = 1;
salt = opt_arg();
break;
case OPT_STDIN:
if (pw_source_defined)
goto opthelp;
in_stdin = 1;
pw_source_defined = 1;
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
if (*argv) {
if (pw_source_defined)
goto opthelp;
pw_source_defined = 1;
passwds = argv;
}
if (!usecrypt && !use1 && !useapr1) {
usecrypt = 1;
}
if (usecrypt + use1 + useapr1 > 1) {
goto opthelp;
}
# ifdef OPENSSL_NO_DES
if (usecrypt)
goto opthelp;
# endif
# ifdef NO_MD5CRYPT_1
if (use1 || useapr1)
goto opthelp;
# endif
if (infile != NULL && in_stdin) {
BIO_printf(bio_err, "%s: Can't combine -in and -stdin\n", prog);
goto end;
}
if (infile != NULL || in_stdin) {
in = bio_open_default(infile, 'r', FORMAT_TEXT);
if (in == NULL)
goto end;
}
if (usecrypt)
pw_maxlen = 8;
else if (use1 || useapr1)
pw_maxlen = 256;
if (passwds == NULL) {
passwd_malloc_size = pw_maxlen + 2;
passwd = passwd_malloc =
app_malloc(passwd_malloc_size, "password buffer");
}
if ((in == NULL) && (passwds == NULL)) {
if (1) {
#ifndef OPENSSL_NO_UI
static char *passwds_static[2] = { NULL, NULL };
passwds = passwds_static;
if (in == NULL)
if (EVP_read_pw_string
(passwd_malloc, passwd_malloc_size, "Password: ",
!(passed_salt || in_noverify)) != 0)
goto end;
passwds[0] = passwd_malloc;
} else {
#endif
BIO_printf(bio_err, "password required\n");
goto end;
}
}
if (in == NULL) {
assert(passwds != NULL);
assert(*passwds != NULL);
do {
passwd = *passwds++;
if (!do_passwd(passed_salt, &salt, &salt_malloc, passwd, bio_out,
quiet, table, reverse, pw_maxlen, usecrypt, use1,
useapr1))
goto end;
}
while (*passwds != NULL);
} else
{
int done;
assert(passwd != NULL);
do {
int r = BIO_gets(in, passwd, pw_maxlen + 1);
if (r > 0) {
char *c = (strchr(passwd, '\n'));
if (c != NULL)
*c = 0;
else {
char trash[BUFSIZ];
do
r = BIO_gets(in, trash, sizeof trash);
while ((r > 0) && (!strchr(trash, '\n')));
}
if (!do_passwd
(passed_salt, &salt, &salt_malloc, passwd, bio_out, quiet,
table, reverse, pw_maxlen, usecrypt, use1, useapr1))
goto end;
}
done = (r <= 0);
}
while (!done);
}
ret = 0;
end:
ERR_print_errors(bio_err);
OPENSSL_free(salt_malloc);
OPENSSL_free(passwd_malloc);
BIO_free(in);
return (ret);
}
static char *md5crypt(const char *passwd, const char *magic, const char *salt)
{
static char out_buf[6 + 9 + 24 + 2];
unsigned char buf[MD5_DIGEST_LENGTH];
char *salt_out;
int n;
unsigned int i;
EVP_MD_CTX *md = NULL, *md2 = NULL;
size_t passwd_len, salt_len, magic_len;
passwd_len = strlen(passwd);
out_buf[0] = '$';
out_buf[1] = 0;
magic_len = strlen(magic);
if (magic_len > 4)
return NULL;
OPENSSL_strlcat(out_buf, magic, sizeof out_buf);
OPENSSL_strlcat(out_buf, "$", sizeof out_buf);
OPENSSL_strlcat(out_buf, salt, sizeof out_buf);
if (strlen(out_buf) > 6 + 8)
return NULL;
salt_out = out_buf + 2 + magic_len;
salt_len = strlen(salt_out);
if (salt_len > 8)
return NULL;
md = EVP_MD_CTX_new();
if (md == NULL
|| !EVP_DigestInit_ex(md, EVP_md5(), NULL)
|| !EVP_DigestUpdate(md, passwd, passwd_len)
|| !EVP_DigestUpdate(md, "$", 1)
|| !EVP_DigestUpdate(md, magic, magic_len)
|| !EVP_DigestUpdate(md, "$", 1)
|| !EVP_DigestUpdate(md, salt_out, salt_len))
md2 = EVP_MD_CTX_new();
if (md2 == NULL
|| !EVP_DigestInit_ex(md2, EVP_md5(), NULL)
|| !EVP_DigestUpdate(md2, passwd, passwd_len)
|| !EVP_DigestUpdate(md2, salt_out, salt_len)
|| !EVP_DigestUpdate(md2, passwd, passwd_len)
|| !EVP_DigestFinal_ex(md2, buf, NULL))
goto err;
for (i = passwd_len; i > sizeof buf; i -= sizeof buf) {
if (!EVP_DigestUpdate(md, buf, sizeof buf))
goto err;
}
if (!EVP_DigestUpdate(md, buf, i))
goto err;
n = passwd_len;
while (n) {
if (!EVP_DigestUpdate(md, (n & 1) ? "\0" : passwd, 1))
goto err;
n >>= 1;
}
if (!EVP_DigestFinal_ex(md, buf, NULL))
return NULL;
for (i = 0; i < 1000; i++) {
if (!EVP_DigestInit_ex(md2, EVP_md5(), NULL))
goto err;
if (!EVP_DigestUpdate(md2,
(i & 1) ? (unsigned const char *)passwd : buf,
(i & 1) ? passwd_len : sizeof buf))
goto err;
if (i % 3) {
if (!EVP_DigestUpdate(md2, salt_out, salt_len))
goto err;
}
if (i % 7) {
if (!EVP_DigestUpdate(md2, passwd, passwd_len))
goto err;
}
if (!EVP_DigestUpdate(md2,
(i & 1) ? buf : (unsigned const char *)passwd,
(i & 1) ? sizeof buf : passwd_len))
goto err;
if (!EVP_DigestFinal_ex(md2, buf, NULL))
goto err;
}
EVP_MD_CTX_free(md2);
EVP_MD_CTX_free(md);
md2 = NULL;
md = NULL;
{
unsigned char buf_perm[sizeof buf];
int dest, source;
char *output;
for (dest = 0, source = 0; dest < 14;
dest++, source = (source + 6) % 17)
buf_perm[dest] = buf[source];
buf_perm[14] = buf[5];
buf_perm[15] = buf[11];
# ifndef PEDANTIC
assert(16 == sizeof buf_perm);
# endif
output = salt_out + salt_len;
assert(output == out_buf + strlen(out_buf));
*output++ = '$';
for (i = 0; i < 15; i += 3) {
*output++ = cov_2char[buf_perm[i + 2] & 0x3f];
*output++ = cov_2char[((buf_perm[i + 1] & 0xf) << 2) |
(buf_perm[i + 2] >> 6)];
*output++ = cov_2char[((buf_perm[i] & 3) << 4) |
(buf_perm[i + 1] >> 4)];
*output++ = cov_2char[buf_perm[i] >> 2];
}
assert(i == 15);
*output++ = cov_2char[buf_perm[i] & 0x3f];
*output++ = cov_2char[buf_perm[i] >> 6];
*output = 0;
assert(strlen(out_buf) < sizeof(out_buf));
}
return out_buf;
err:
EVP_MD_CTX_free(md2);
EVP_MD_CTX_free(md);
return NULL;
}
static int do_passwd(int passed_salt, char **salt_p, char **salt_malloc_p,
char *passwd, BIO *out, int quiet, int table,
int reverse, size_t pw_maxlen, int usecrypt, int use1,
int useapr1)
{
char *hash = NULL;
assert(salt_p != NULL);
assert(salt_malloc_p != NULL);
if (!passed_salt) {
# ifndef OPENSSL_NO_DES
if (usecrypt) {
if (*salt_malloc_p == NULL) {
*salt_p = *salt_malloc_p = app_malloc(3, "salt buffer");
}
if (RAND_bytes((unsigned char *)*salt_p, 2) <= 0)
goto end;
(*salt_p)[0] = cov_2char[(*salt_p)[0] & 0x3f];
(*salt_p)[1] = cov_2char[(*salt_p)[1] & 0x3f];
(*salt_p)[2] = 0;
# ifdef CHARSET_EBCDIC
ascii2ebcdic(*salt_p, *salt_p, 2);
# endif
}
# endif
# ifndef NO_MD5CRYPT_1
if (use1 || useapr1) {
int i;
if (*salt_malloc_p == NULL) {
*salt_p = *salt_malloc_p = app_malloc(9, "salt buffer");
}
if (RAND_bytes((unsigned char *)*salt_p, 8) <= 0)
goto end;
for (i = 0; i < 8; i++)
(*salt_p)[i] = cov_2char[(*salt_p)[i] & 0x3f];
(*salt_p)[8] = 0;
}
# endif
}
assert(*salt_p != NULL);
if ((strlen(passwd) > pw_maxlen)) {
if (!quiet)
BIO_printf(bio_err,
"Warning: truncating password to %u characters\n",
(unsigned)pw_maxlen);
passwd[pw_maxlen] = 0;
}
assert(strlen(passwd) <= pw_maxlen);
# ifndef OPENSSL_NO_DES
if (usecrypt)
hash = DES_crypt(passwd, *salt_p);
# endif
# ifndef NO_MD5CRYPT_1
if (use1 || useapr1)
hash = md5crypt(passwd, (use1 ? "1" : "apr1"), *salt_p);
# endif
assert(hash != NULL);
if (table && !reverse)
BIO_printf(out, "%s\t%s\n", passwd, hash);
else if (table && reverse)
BIO_printf(out, "%s\t%s\n", hash, passwd);
else
BIO_printf(out, "%s\n", hash);
return 1;
end:
return 0;
}
int passwd_main(int argc, char **argv)
{
BIO_printf(bio_err, "Program not available.\n");
return (1);
}
