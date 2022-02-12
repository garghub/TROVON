int app_RAND_load_file(const char *file, int dont_warn)
{
int consider_randfile = (file == NULL);
char buffer[200];
if (file == NULL)
file = RAND_file_name(buffer, sizeof buffer);
#ifndef OPENSSL_NO_EGD
else if (RAND_egd(file) > 0) {
egdsocket = 1;
return 1;
}
#endif
if (file == NULL || !RAND_load_file(file, -1)) {
if (RAND_status() == 0) {
if (!dont_warn) {
BIO_printf(bio_err, "unable to load 'random state'\n");
BIO_printf(bio_err,
"This means that the random number generator has not been seeded\n");
BIO_printf(bio_err, "with much random data.\n");
if (consider_randfile) {
BIO_printf(bio_err,
"Consider setting the RANDFILE environment variable to point at a file that\n");
BIO_printf(bio_err,
"'random' data can be kept in (the file will be overwritten).\n");
}
}
return 0;
}
}
seeded = 1;
return 1;
}
long app_RAND_load_files(char *name)
{
char *p, *n;
int last;
long tot = 0;
#ifndef OPENSSL_NO_EGD
int egd;
#endif
for (;;) {
last = 0;
for (p = name; ((*p != '\0') && (*p != LIST_SEPARATOR_CHAR)); p++) ;
if (*p == '\0')
last = 1;
*p = '\0';
n = name;
name = p + 1;
if (*n == '\0')
break;
#ifndef OPENSSL_NO_EGD
egd = RAND_egd(n);
if (egd > 0)
tot += egd;
else
#endif
tot += RAND_load_file(n, -1);
if (last)
break;
}
if (tot > 512)
app_RAND_allow_write_file();
return (tot);
}
int app_RAND_write_file(const char *file)
{
char buffer[200];
if (egdsocket || !seeded)
return 0;
if (file == NULL)
file = RAND_file_name(buffer, sizeof buffer);
if (file == NULL || !RAND_write_file(file)) {
BIO_printf(bio_err, "unable to write 'random state'\n");
return 0;
}
return 1;
}
void app_RAND_allow_write_file(void)
{
seeded = 1;
}
