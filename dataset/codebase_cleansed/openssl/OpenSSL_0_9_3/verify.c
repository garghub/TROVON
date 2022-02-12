int MAIN(int argc, char **argv)
{
int i,ret=1;
char *CApath=NULL,*CAfile=NULL;
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
if (!X509_LOOKUP_load_file(lookup,CAfile,X509_FILETYPE_PEM))
X509_LOOKUP_load_file(lookup,NULL,X509_FILETYPE_DEFAULT);
lookup=X509_STORE_add_lookup(cert_ctx,X509_LOOKUP_hash_dir());
if (lookup == NULL) abort();
if (!X509_LOOKUP_add_dir(lookup,CApath,X509_FILETYPE_PEM))
X509_LOOKUP_add_dir(lookup,NULL,X509_FILETYPE_DEFAULT);
ERR_clear_error();
if (argc < 1) check(cert_ctx,NULL);
else
for (i=0; i<argc; i++)
check(cert_ctx,argv[i]);
ret=0;
end:
if (ret == 1)
BIO_printf(bio_err,"usage: verify [-verbose] [-CApath path] [-CAfile file] cert1 cert2 ...\n");
if (cert_ctx != NULL) X509_STORE_free(cert_ctx);
EXIT(ret);
}
static int check(X509_STORE *ctx, char *file)
{
X509 *x=NULL;
BIO *in=NULL;
int i=0,ret=0;
X509_STORE_CTX csc;
in=BIO_new(BIO_s_file());
if (in == NULL)
{
ERR_print_errors(bio_err);
goto end;
}
if (file == NULL)
BIO_set_fp(in,stdin,BIO_NOCLOSE);
else
{
if (BIO_read_filename(in,file) <= 0)
{
perror(file);
goto end;
}
}
x=PEM_read_bio_X509(in,NULL,NULL);
if (x == NULL)
{
fprintf(stdout,"%s: unable to load certificate file\n",
(file == NULL)?"stdin":file);
ERR_print_errors(bio_err);
goto end;
}
fprintf(stdout,"%s: ",(file == NULL)?"stdin":file);
X509_STORE_CTX_init(&csc,ctx,x,NULL);
i=X509_verify_cert(&csc);
X509_STORE_CTX_cleanup(&csc);
ret=0;
end:
if (i)
{
fprintf(stdout,"OK\n");
ret=1;
}
else
ERR_print_errors(bio_err);
if (x != NULL) X509_free(x);
if (in != NULL) BIO_free(in);
return(ret);
}
static int MS_CALLBACK cb(int ok, X509_STORE_CTX *ctx)
{
char buf[256];
if (!ok)
{
if (ctx->error == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT)
ok=1;
else
{
X509_NAME_oneline(
X509_get_subject_name(ctx->current_cert),buf,256);
printf("%s\n",buf);
printf("error %d at %d depth lookup:%s\n",ctx->error,
ctx->error_depth,
X509_verify_cert_error_string(ctx->error));
if (ctx->error == X509_V_ERR_CERT_HAS_EXPIRED)
ok=1;
}
}
if (!v_verbose)
ERR_clear_error();
return(ok);
}
