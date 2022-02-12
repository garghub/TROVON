static void bit_set(unsigned char *set, unsigned int bit)
{
set[bit >> 3] |= 1 << (bit & 0x7);
}
static int bit_isset(unsigned char *set, unsigned int bit)
{
return set[bit >> 3] & (1 << (bit & 0x7));
}
static int add_entry(enum Type type, unsigned int hash, const char *filename,
const unsigned char *digest, int need_symlink,
unsigned short old_id)
{
static BUCKET nilbucket;
static HENTRY nilhentry;
BUCKET *bp;
HENTRY *ep, *found = NULL;
unsigned int ndx = (type + hash) % OSSL_NELEM(hash_table);
for (bp = hash_table[ndx]; bp; bp = bp->next)
if (bp->type == type && bp->hash == hash)
break;
if (bp == NULL) {
bp = app_malloc(sizeof(*bp), "hash bucket");
*bp = nilbucket;
bp->next = hash_table[ndx];
bp->type = type;
bp->hash = hash;
hash_table[ndx] = bp;
}
for (ep = bp->first_entry; ep; ep = ep->next) {
if (digest && memcmp(digest, ep->digest, evpmdsize) == 0) {
BIO_printf(bio_err,
"%s: skipping duplicate %s in %s\n", opt_getprog(),
type == TYPE_CERT ? "certificate" : "CRL", filename);
return 1;
}
if (strcmp(filename, ep->filename) == 0) {
found = ep;
if (digest == NULL)
break;
}
}
ep = found;
if (ep == NULL) {
if (bp->num_needed >= MAX_COLLISIONS) {
BIO_printf(bio_err,
"%s: hash table overflow for %s\n",
opt_getprog(), filename);
return 1;
}
ep = app_malloc(sizeof(*ep), "collision bucket");
*ep = nilhentry;
ep->old_id = ~0;
ep->filename = OPENSSL_strdup(filename);
if (bp->last_entry)
bp->last_entry->next = ep;
if (bp->first_entry == NULL)
bp->first_entry = ep;
bp->last_entry = ep;
}
if (old_id < ep->old_id)
ep->old_id = old_id;
if (need_symlink && !ep->need_symlink) {
ep->need_symlink = 1;
bp->num_needed++;
memcpy(ep->digest, digest, evpmdsize);
}
return 0;
}
static int handle_symlink(const char *filename, const char *fullpath)
{
unsigned int hash = 0;
int i, type, id;
unsigned char ch;
char linktarget[PATH_MAX], *endptr;
ossl_ssize_t n;
for (i = 0; i < 8; i++) {
ch = filename[i];
if (!isxdigit(ch))
return -1;
hash <<= 4;
hash += OPENSSL_hexchar2int(ch);
}
if (filename[i++] != '.')
return -1;
for (type = OSSL_NELEM(suffixes) - 1; type > 0; type--) {
const char *suffix = suffixes[type];
if (strncasecmp(suffix, &filename[i], strlen(suffix)) == 0)
break;
}
i += strlen(suffixes[type]);
id = strtoul(&filename[i], &endptr, 10);
if (*endptr != '\0')
return -1;
n = readlink(fullpath, linktarget, sizeof(linktarget));
if (n < 0 || n >= (int)sizeof(linktarget))
return -1;
linktarget[n] = 0;
return add_entry(type, hash, linktarget, NULL, 0, id);
}
static int do_file(const char *filename, const char *fullpath, enum Hash h)
{
STACK_OF (X509_INFO) *inf = NULL;
X509_INFO *x;
X509_NAME *name = NULL;
BIO *b;
const char *ext;
unsigned char digest[EVP_MAX_MD_SIZE];
int type, errs = 0;
size_t i;
if ((ext = strrchr(filename, '.')) == NULL)
goto end;
for (i = 0; i < OSSL_NELEM(extensions); i++) {
if (strcasecmp(extensions[i], ext + 1) == 0)
break;
}
if (i >= OSSL_NELEM(extensions))
goto end;
if ((b = BIO_new_file(fullpath, "r")) == NULL) {
BIO_printf(bio_err, "%s: skipping %s, cannot open file\n",
opt_getprog(), filename);
errs++;
goto end;
}
inf = PEM_X509_INFO_read_bio(b, NULL, NULL, NULL);
BIO_free(b);
if (inf == NULL)
goto end;
if (sk_X509_INFO_num(inf) != 1) {
BIO_printf(bio_err,
"%s: skipping %s,"
"it does not contain exactly one certificate or CRL\n",
opt_getprog(), filename);
goto end;
}
x = sk_X509_INFO_value(inf, 0);
if (x->x509) {
type = TYPE_CERT;
name = X509_get_subject_name(x->x509);
X509_digest(x->x509, evpmd, digest, NULL);
} else if (x->crl) {
type = TYPE_CRL;
name = X509_CRL_get_issuer(x->crl);
X509_CRL_digest(x->crl, evpmd, digest, NULL);
} else {
++errs;
goto end;
}
if (name) {
if ((h == HASH_NEW) || (h == HASH_BOTH))
errs += add_entry(type, X509_NAME_hash(name), filename, digest, 1, ~0);
if ((h == HASH_OLD) || (h == HASH_BOTH))
errs += add_entry(type, X509_NAME_hash_old(name), filename, digest, 1, ~0);
}
end:
sk_X509_INFO_pop_free(inf, X509_INFO_free);
return errs;
}
static void str_free(char *s)
{
OPENSSL_free(s);
}
static int do_dir(const char *dirname, enum Hash h)
{
BUCKET *bp, *nextbp;
HENTRY *ep, *nextep;
OPENSSL_DIR_CTX *d = NULL;
struct stat st;
unsigned char idmask[MAX_COLLISIONS / 8];
int n, numfiles, nextid, buflen, errs = 0;
size_t i;
const char *pathsep;
const char *filename;
char *buf, *copy;
STACK_OF(OPENSSL_STRING) *files = NULL;
if (app_access(dirname, W_OK) < 0) {
BIO_printf(bio_err, "Skipping %s, can't write\n", dirname);
return 1;
}
buflen = strlen(dirname);
pathsep = (buflen && dirname[buflen - 1] == '/') ? "" : "/";
buflen += NAME_MAX + 1 + 1;
buf = app_malloc(buflen, "filename buffer");
if (verbose)
BIO_printf(bio_out, "Doing %s\n", dirname);
if ((files = sk_OPENSSL_STRING_new_null()) == NULL) {
BIO_printf(bio_err, "Skipping %s, out of memory\n", dirname);
exit(1);
}
while ((filename = OPENSSL_DIR_read(&d, dirname)) != NULL) {
if ((copy = strdup(filename)) == NULL
|| sk_OPENSSL_STRING_push(files, copy) == 0) {
BIO_puts(bio_err, "out of memory\n");
exit(1);
}
}
OPENSSL_DIR_end(&d);
sk_OPENSSL_STRING_sort(files);
numfiles = sk_OPENSSL_STRING_num(files);
for (n = 0; n < numfiles; ++n) {
filename = sk_OPENSSL_STRING_value(files, n);
if (snprintf(buf, buflen, "%s%s%s",
dirname, pathsep, filename) >= buflen)
continue;
if (lstat(buf, &st) < 0)
continue;
if (S_ISLNK(st.st_mode) && handle_symlink(filename, buf) == 0)
continue;
errs += do_file(filename, buf, h);
}
sk_OPENSSL_STRING_pop_free(files, str_free);
for (i = 0; i < OSSL_NELEM(hash_table); i++) {
for (bp = hash_table[i]; bp; bp = nextbp) {
nextbp = bp->next;
nextid = 0;
memset(idmask, 0, (bp->num_needed + 7) / 8);
for (ep = bp->first_entry; ep; ep = ep->next)
if (ep->old_id < bp->num_needed)
bit_set(idmask, ep->old_id);
for (ep = bp->first_entry; ep; ep = nextep) {
nextep = ep->next;
if (ep->old_id < bp->num_needed) {
snprintf(buf, buflen, "%08x.%s%d", bp->hash,
suffixes[bp->type], ep->old_id);
if (verbose)
BIO_printf(bio_out, "link %s -> %s\n",
ep->filename, buf);
} else if (ep->need_symlink) {
while (bit_isset(idmask, nextid))
nextid++;
snprintf(buf, buflen, "%s%s%n%08x.%s%d",
dirname, pathsep, &n, bp->hash,
suffixes[bp->type], nextid);
if (verbose)
BIO_printf(bio_out, "link %s -> %s\n",
ep->filename, &buf[n]);
if (unlink(buf) < 0 && errno != ENOENT) {
BIO_printf(bio_err,
"%s: Can't unlink %s, %s\n",
opt_getprog(), buf, strerror(errno));
errs++;
}
if (symlink(ep->filename, buf) < 0) {
BIO_printf(bio_err,
"%s: Can't symlink %s, %s\n",
opt_getprog(), ep->filename,
strerror(errno));
errs++;
}
bit_set(idmask, nextid);
} else if (remove_links) {
snprintf(buf, buflen, "%s%s%n%08x.%s%d",
dirname, pathsep, &n, bp->hash,
suffixes[bp->type], ep->old_id);
if (verbose)
BIO_printf(bio_out, "unlink %s\n",
&buf[n]);
if (unlink(buf) < 0 && errno != ENOENT) {
BIO_printf(bio_err,
"%s: Can't unlink %s, %s\n",
opt_getprog(), buf, strerror(errno));
errs++;
}
}
OPENSSL_free(ep->filename);
OPENSSL_free(ep);
}
OPENSSL_free(bp);
}
hash_table[i] = NULL;
}
OPENSSL_free(buf);
return errs;
}
int rehash_main(int argc, char **argv)
{
const char *env, *prog;
char *e, *m;
int errs = 0;
OPTION_CHOICE o;
enum Hash h = HASH_NEW;
prog = opt_init(argc, argv, rehash_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(rehash_options);
goto end;
case OPT_COMPAT:
h = HASH_BOTH;
break;
case OPT_OLD:
h = HASH_OLD;
break;
case OPT_N:
remove_links = 0;
break;
case OPT_VERBOSE:
verbose = 1;
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
evpmd = EVP_sha1();
evpmdsize = EVP_MD_size(evpmd);
if (*argv) {
while (*argv)
errs += do_dir(*argv++, h);
} else if ((env = getenv("SSL_CERT_DIR")) != NULL) {
m = OPENSSL_strdup(env);
for (e = strtok(m, ":"); e != NULL; e = strtok(NULL, ":"))
errs += do_dir(e, h);
OPENSSL_free(m);
} else {
errs += do_dir("/etc/ssl/certs", h);
}
end:
return errs;
}
int rehash_main(int argc, char **argv)
{
BIO_printf(bio_err, "Not available; use c_rehash script\n");
return (1);
}
