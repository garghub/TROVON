int main(int argc, char **argv)
{
X509 *cert;
FILE *inf;
int i, count;
X509_EXTENSION *ext;
X509V3_add_standard_extensions();
ERR_load_crypto_strings();
if (!argv[1]) {
fprintf(stderr, "Usage v3prin cert.pem\n");
exit(1);
}
if ((inf = fopen(argv[1], "r")) == NULL) {
fprintf(stderr, "Can't open %s\n", argv[1]);
exit(1);
}
if ((cert = PEM_read_X509(inf, NULL, NULL)) == NULL) {
fprintf(stderr, "Can't read certificate %s\n", argv[1]);
ERR_print_errors_fp(stderr);
exit(1);
}
fclose(inf);
count = X509_get_ext_count(cert);
printf("%d extensions\n", count);
for (i = 0; i < count; i++) {
ext = X509_get_ext(cert, i);
printf("%s\n", OBJ_nid2ln(OBJ_obj2nid(ext->object)));
if (!X509V3_EXT_print_fp(stdout, ext, 0, 0))
ERR_print_errors_fp(stderr);
printf("\n");
}
return 0;
}
