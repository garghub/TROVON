int MAIN(int argc, char **argv)
{
int i,ret=1;
int purpose = -1;
char *CApath=NULL,*CAfile=NULL;
char *untfile = NULL;
STACK_OF(X509) *untrusted = NULL;
X509_STORE *cert_ctx=NULL;
X509_LOOKUP *lookup=NULL;
cert_ctx=X509_STORE_new();
if (cert_ctx == NULL) goto end;
X509_STORE_set_verify_cb_func(cert_ctx,cb);
ERR_load_crypto_strings();
apps_startup();
if (bio_err == NULL)
if ((bio_err=BIO_new(BIO_s_file())) != NULL)
BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
argc--;
argv++;
for (;;)
{
if (argc >= 1)
{
if (strcmp(*argv,"-CApath") == 0)
{
if (argc-- < 1) goto end;
CApath= *(++argv);
}
else if (strcmp(*argv,"-CAfile") == 0)
{
if (argc-- < 1) goto end;
CAfile= *(++argv);
}
else if (strcmp(*argv,"-purpose") == 0)
{
X509_PURPOSE *xptmp;
if (argc-- < 1) goto end;
i = X509_PURPOSE_get_by_sname(*(++argv));
if(i < 0)
{
BIO_printf(bio_err, "unrecognized purpose\n");
goto end;
}
xptmp = X509_PURPOSE_get0(i);
purpose = X509_PURPOSE_get_id(xptmp);
}
else if (strcmp(*argv,"-untrusted") == 0)
{
if (argc-- < 1) goto end;
untfile= *(++argv);
}
else if (strcmp(*argv,"-help") == 0)
goto end;
else if (strcmp(*argv,"-verbose") == 0)
v_verbose=1;
else if (argv[0][0] == '-')
goto end;
else
break;
argc--;
argv++;
}
else
break;
}
lookup=X509_STORE_add_lookup(cert_ctx,X509_LOOKUP_file());
if (lookup == NULL) abort();
if (CAfile) {
i=X509_LOOKUP_load_file(lookup,CAfile,X509_FILETYPE_PEM);
if(!i) {
BIO_printf(bio_err, "Error loading file %s\n", CAfile);
ERR_print_errors(bio_err);
goto end;
}
} else X509_LOOKUP_load_file(lookup,NULL,X509_FILETYPE_DEFAULT);
lookup=X509_STORE_add_lookup(cert_ctx,X509_LOOKUP_hash_dir());
if (lookup == NULL) abort();
if (CApath) {
i=X509_LOOKUP_add_dir(lookup,CApath,X509_FILETYPE_PEM);
if(!i) {
BIO_printf(bio_err, "Error loading directory %s\n", CApath);
ERR_print_errors(bio_err);
goto end;
}
} else X509_LOOKUP_add_dir(lookup,NULL,X509_FILETYPE_DEFAULT);
ERR_clear_error();
if(untfile) {
if(!(untrusted = load_untrusted(untfile))) {
BIO_printf(bio_err, "Error loading untrusted file %s\n", untfile);
ERR_print_errors(bio_err);
goto end;
}
}
if (argc < 1) check(cert_ctx, NULL, untrusted, purpose);
else
for (i=0; i<argc; i++)
check(cert_ctx,argv[i], untrusted, purpose);
ret=0;
end:
if (ret == 1) {
BIO_printf(bio_err,"usage: verify [-verbose] [-CApath path] [-CAfile file] cert1 cert2 ...\n");
BIO_printf(bio_err,"recognized usages:\n");
for(i = 0; i < X509_PURPOSE_get_count(); i++) {
X509_PURPOSE *ptmp;
ptmp = X509_PURPOSE_get0(i);
BIO_printf(bio_err, "\t%-10s\t%s\n", X509_PURPOSE_get0_sname(ptmp),
X509_PURPOSE_get0_name(ptmp));
}
}
if (cert_ctx != NULL) X509_STORE_free(cert_ctx);
sk_X509_pop_free(untrusted, X509_free);
EXIT(ret);
}
int MS_CALLBACK cb(int ok, X509_STORE_CTX *ctx)
{
char buf[256];
if (!ok)
{
X509_NAME_oneline(
X509_get_subject_name(ctx->current_cert),buf,256);
printf("%s\n",buf);
printf("error %d at %d depth lookup:%s\n",ctx->error,
ctx->error_depth,
X509_verify_cert_error_string(ctx->error));
if (ctx->error == X509_V_ERR_CERT_HAS_EXPIRED) ok=1;
if (ctx->error == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT) ok=1;
if (ctx->error == X509_V_ERR_INVALID_CA) ok=1;
if (ctx->error == X509_V_ERR_PATH_LENGTH_EXCEEDED) ok=1;
if (ctx->error == X509_V_ERR_INVALID_PURPOSE) ok=1;
if (ctx->error == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT) ok=1;
}
if (!v_verbose)
ERR_clear_error();
return(ok);
}
