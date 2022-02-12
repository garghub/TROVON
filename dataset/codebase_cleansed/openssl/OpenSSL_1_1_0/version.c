int version_main(int argc, char **argv)
{
int ret = 1, dirty = 0;
int cflags = 0, version = 0, date = 0, options = 0, platform = 0, dir = 0;
int engdir = 0;
char *prog;
OPTION_CHOICE o;
prog = opt_init(argc, argv, version_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(version_options);
ret = 0;
goto end;
case OPT_B:
dirty = date = 1;
break;
case OPT_D:
dirty = dir = 1;
break;
case OPT_E:
dirty = engdir = 1;
break;
case OPT_F:
dirty = cflags = 1;
break;
case OPT_O:
dirty = options = 1;
break;
case OPT_P:
dirty = platform = 1;
break;
case OPT_V:
dirty = version = 1;
break;
case OPT_A:
cflags = version = date = platform = dir = engdir = 1;
break;
}
}
if (!dirty)
version = 1;
if (version) {
if (OpenSSL_version_num() == OPENSSL_VERSION_NUMBER) {
printf("%s\n", OpenSSL_version(OPENSSL_VERSION));
} else {
printf("%s (Library: %s)\n",
OPENSSL_VERSION_TEXT, OpenSSL_version(OPENSSL_VERSION));
}
}
if (date)
printf("%s\n", OpenSSL_version(OPENSSL_BUILT_ON));
if (platform)
printf("%s\n", OpenSSL_version(OPENSSL_PLATFORM));
if (options) {
printf("options: ");
printf("%s ", BN_options());
#ifndef OPENSSL_NO_MD2
printf("%s ", MD2_options());
#endif
#ifndef OPENSSL_NO_RC4
printf("%s ", RC4_options());
#endif
#ifndef OPENSSL_NO_DES
printf("%s ", DES_options());
#endif
#ifndef OPENSSL_NO_IDEA
printf("%s ", IDEA_options());
#endif
#ifndef OPENSSL_NO_BF
printf("%s ", BF_options());
#endif
printf("\n");
}
if (cflags)
printf("%s\n", OpenSSL_version(OPENSSL_CFLAGS));
if (dir)
printf("%s\n", OpenSSL_version(OPENSSL_DIR));
if (engdir)
printf("%s\n", OpenSSL_version(OPENSSL_ENGINES_DIR));
ret = 0;
end:
return (ret);
}
