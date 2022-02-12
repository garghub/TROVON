int verify_main(int argc, char **argv)
{
STACK_OF(X509) *untrusted = NULL, *trusted = NULL;
STACK_OF(X509_CRL) *crls = NULL;
X509_STORE *store = NULL;
X509_VERIFY_PARAM *vpm = NULL;
const char *prog, *CApath = NULL, *CAfile = NULL;
int noCApath = 0, noCAfile = 0;
int vpmtouched = 0, crl_download = 0, show_chain = 0, i = 0, ret = 1;
OPTION_CHOICE o;
if ((vpm = X509_VERIFY_PARAM_new()) == NULL)
goto end;
prog = opt_init(argc, argv, verify_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(verify_options);
BIO_printf(bio_err, "Recognized usages:\n");
for (i = 0; i < X509_PURPOSE_get_count(); i++) {
X509_PURPOSE *ptmp;
ptmp = X509_PURPOSE_get0(i);
BIO_printf(bio_err, "\t%-10s\t%s\n",
X509_PURPOSE_get0_sname(ptmp),
X509_PURPOSE_get0_name(ptmp));
}
BIO_printf(bio_err, "Recognized verify names:\n");
for (i = 0; i < X509_VERIFY_PARAM_get_count(); i++) {
const X509_VERIFY_PARAM *vptmp;
vptmp = X509_VERIFY_PARAM_get0(i);
BIO_printf(bio_err, "\t%-10s\n",
X509_VERIFY_PARAM_get0_name(vptmp));
}
ret = 0;
goto end;
case OPT_V_CASES:
if (!opt_verify(o, vpm))
goto end;
vpmtouched++;
break;
case OPT_CAPATH:
CApath = opt_arg();
break;
case OPT_CAFILE:
CAfile = opt_arg();
break;
case OPT_NOCAPATH:
noCApath = 1;
break;
case OPT_NOCAFILE:
noCAfile = 1;
break;
case OPT_UNTRUSTED:
if (!load_certs(opt_arg(), &untrusted, FORMAT_PEM, NULL,
"untrusted certificates"))
goto end;
break;
case OPT_TRUSTED:
noCAfile = 1;
noCApath = 1;
if (!load_certs(opt_arg(), &trusted, FORMAT_PEM, NULL,
"trusted certificates"))
goto end;
break;
case OPT_CRLFILE:
if (!load_crls(opt_arg(), &crls, FORMAT_PEM, NULL,
"other CRLs"))
goto end;
break;
case OPT_CRL_DOWNLOAD:
crl_download = 1;
break;
case OPT_ENGINE:
if (setup_engine(opt_arg(), 0) == NULL) {
goto end;
}
break;
case OPT_SHOW_CHAIN:
show_chain = 1;
break;
case OPT_VERBOSE:
v_verbose = 1;
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
if (trusted != NULL && (CAfile || CApath)) {
BIO_printf(bio_err,
"%s: Cannot use -trusted with -CAfile or -CApath\n",
prog);
goto end;
}
if ((store = setup_verify(CAfile, CApath, noCAfile, noCApath)) == NULL)
goto end;
X509_STORE_set_verify_cb(store, cb);
if (vpmtouched)
X509_STORE_set1_param(store, vpm);
ERR_clear_error();
if (crl_download)
store_setup_crl_download(store);
ret = 0;
if (argc < 1) {
if (check(store, NULL, untrusted, trusted, crls, show_chain) != 1)
ret = -1;
} else {
for (i = 0; i < argc; i++)
if (check(store, argv[i], untrusted, trusted, crls,
show_chain) != 1)
ret = -1;
}
end:
X509_VERIFY_PARAM_free(vpm);
X509_STORE_free(store);
sk_X509_pop_free(untrusted, X509_free);
sk_X509_pop_free(trusted, X509_free);
sk_X509_CRL_pop_free(crls, X509_CRL_free);
return (ret < 0 ? 2 : ret);
}
static int cb(int ok, X509_STORE_CTX *ctx)
{
int cert_error = X509_STORE_CTX_get_error(ctx);
X509 *current_cert = X509_STORE_CTX_get_current_cert(ctx);
if (!ok) {
if (current_cert) {
X509_NAME_print_ex(bio_err,
X509_get_subject_name(current_cert),
0, XN_FLAG_ONELINE);
BIO_printf(bio_err, "\n");
}
BIO_printf(bio_err, "%serror %d at %d depth lookup: %s\n",
X509_STORE_CTX_get0_parent_ctx(ctx) ? "[CRL path] " : "",
cert_error,
X509_STORE_CTX_get_error_depth(ctx),
X509_verify_cert_error_string(cert_error));
switch (cert_error) {
case X509_V_ERR_NO_EXPLICIT_POLICY:
policies_print(ctx);
case X509_V_ERR_CERT_HAS_EXPIRED:
case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
case X509_V_ERR_INVALID_CA:
case X509_V_ERR_INVALID_NON_CA:
case X509_V_ERR_PATH_LENGTH_EXCEEDED:
case X509_V_ERR_INVALID_PURPOSE:
case X509_V_ERR_CRL_HAS_EXPIRED:
case X509_V_ERR_CRL_NOT_YET_VALID:
case X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION:
ok = 1;
}
return ok;
}
if (cert_error == X509_V_OK && ok == 2)
policies_print(ctx);
if (!v_verbose)
ERR_clear_error();
return (ok);
}
