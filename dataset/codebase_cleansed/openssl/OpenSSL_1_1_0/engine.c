static int append_buf(char **buf, int *size, const char *s)
{
if (*buf == NULL) {
*size = 256;
*buf = app_malloc(*size, "engine buffer");
**buf = '\0';
}
if (strlen(*buf) + strlen(s) >= (unsigned int)*size) {
char *tmp;
*size += 256;
tmp = OPENSSL_realloc(*buf, *size);
if (tmp == NULL) {
OPENSSL_free(*buf);
*buf = NULL;
return 0;
}
*buf = tmp;
}
if (**buf != '\0')
OPENSSL_strlcat(*buf, ", ", *size);
OPENSSL_strlcat(*buf, s, *size);
return 1;
}
static int util_flags(BIO *out, unsigned int flags, const char *indent)
{
int started = 0, err = 0;
BIO_printf(out, "%s%s(input flags): ", indent, indent);
if (flags == 0) {
BIO_printf(out, "<no flags>\n");
return 1;
}
if (flags & ENGINE_CMD_FLAG_INTERNAL) {
BIO_printf(out, "[Internal] ");
}
if (flags & ENGINE_CMD_FLAG_NUMERIC) {
BIO_printf(out, "NUMERIC");
started = 1;
}
if (flags & ENGINE_CMD_FLAG_STRING) {
if (started) {
BIO_printf(out, "|");
err = 1;
}
BIO_printf(out, "STRING");
started = 1;
}
if (flags & ENGINE_CMD_FLAG_NO_INPUT) {
if (started) {
BIO_printf(out, "|");
err = 1;
}
BIO_printf(out, "NO_INPUT");
started = 1;
}
flags = flags & ~ENGINE_CMD_FLAG_NUMERIC &
~ENGINE_CMD_FLAG_STRING &
~ENGINE_CMD_FLAG_NO_INPUT & ~ENGINE_CMD_FLAG_INTERNAL;
if (flags) {
if (started)
BIO_printf(out, "|");
BIO_printf(out, "<0x%04X>", flags);
}
if (err)
BIO_printf(out, " <illegal flags!>");
BIO_printf(out, "\n");
return 1;
}
static int util_verbose(ENGINE *e, int verbose, BIO *out, const char *indent)
{
static const int line_wrap = 78;
int num;
int ret = 0;
char *name = NULL;
char *desc = NULL;
int flags;
int xpos = 0;
STACK_OF(OPENSSL_STRING) *cmds = NULL;
if (!ENGINE_ctrl(e, ENGINE_CTRL_HAS_CTRL_FUNCTION, 0, NULL, NULL) ||
((num = ENGINE_ctrl(e, ENGINE_CTRL_GET_FIRST_CMD_TYPE,
0, NULL, NULL)) <= 0)) {
return 1;
}
cmds = sk_OPENSSL_STRING_new_null();
if (!cmds)
goto err;
do {
int len;
if ((flags = ENGINE_ctrl(e, ENGINE_CTRL_GET_CMD_FLAGS, num,
NULL, NULL)) < 0)
goto err;
if (!(flags & ENGINE_CMD_FLAG_INTERNAL) || verbose >= 4) {
if ((len = ENGINE_ctrl(e, ENGINE_CTRL_GET_NAME_LEN_FROM_CMD, num,
NULL, NULL)) <= 0)
goto err;
name = app_malloc(len + 1, "name buffer");
if (ENGINE_ctrl(e, ENGINE_CTRL_GET_NAME_FROM_CMD, num, name,
NULL) <= 0)
goto err;
if ((len = ENGINE_ctrl(e, ENGINE_CTRL_GET_DESC_LEN_FROM_CMD, num,
NULL, NULL)) < 0)
goto err;
if (len > 0) {
desc = app_malloc(len + 1, "description buffer");
if (ENGINE_ctrl(e, ENGINE_CTRL_GET_DESC_FROM_CMD, num, desc,
NULL) <= 0)
goto err;
}
if (xpos == 0)
xpos = BIO_puts(out, indent);
else
xpos += BIO_printf(out, ", ");
if (verbose == 1) {
if ((xpos > (int)strlen(indent)) &&
(xpos + (int)strlen(name) > line_wrap)) {
BIO_printf(out, "\n");
xpos = BIO_puts(out, indent);
}
xpos += BIO_printf(out, "%s", name);
} else {
BIO_printf(out, "%s: %s\n", name,
(desc == NULL) ? "<no description>" : desc);
if ((verbose >= 3) && !util_flags(out, flags, indent))
goto err;
xpos = 0;
}
}
OPENSSL_free(name);
name = NULL;
OPENSSL_free(desc);
desc = NULL;
num = ENGINE_ctrl(e, ENGINE_CTRL_GET_NEXT_CMD_TYPE, num, NULL, NULL);
} while (num > 0);
if (xpos > 0)
BIO_printf(out, "\n");
ret = 1;
err:
sk_OPENSSL_STRING_free(cmds);
OPENSSL_free(name);
OPENSSL_free(desc);
return ret;
}
int engine_main(int argc, char **argv)
{
int ret = 1, i;
int verbose = 0, list_cap = 0, test_avail = 0, test_avail_noise = 0;
ENGINE *e;
STACK_OF(OPENSSL_CSTRING) *engines = sk_OPENSSL_CSTRING_new_null();
STACK_OF(OPENSSL_STRING) *pre_cmds = sk_OPENSSL_STRING_new_null();
STACK_OF(OPENSSL_STRING) *post_cmds = sk_OPENSSL_STRING_new_null();
BIO *out;
const char *indent = " ";
OPTION_CHOICE o;
char *prog;
char *argv1;
out = dup_bio_out(FORMAT_TEXT);
if (engines == NULL || pre_cmds == NULL || post_cmds == NULL)
goto end;
prog = argv[0];
while ((argv1 = argv[1]) != NULL && *argv1 != '-') {
sk_OPENSSL_CSTRING_push(engines, argv1);
argc--;
argv++;
}
argv[0] = prog;
opt_init(argc, argv, engine_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(engine_options);
ret = 0;
goto end;
case OPT_VVVV:
case OPT_VVV:
case OPT_VV:
case OPT_V:
i = (int)(o - OPT_V) + 1;
if (verbose < i)
verbose = i;
break;
case OPT_C:
list_cap = 1;
break;
case OPT_TT:
test_avail_noise++;
case OPT_T:
test_avail++;
break;
case OPT_PRE:
sk_OPENSSL_STRING_push(pre_cmds, opt_arg());
break;
case OPT_POST:
sk_OPENSSL_STRING_push(post_cmds, opt_arg());
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
for ( ; *argv; argv++) {
if (**argv == '-') {
BIO_printf(bio_err, "%s: Cannot mix flags and engine names.\n",
prog);
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
}
sk_OPENSSL_CSTRING_push(engines, *argv);
}
if (sk_OPENSSL_CSTRING_num(engines) == 0) {
for (e = ENGINE_get_first(); e != NULL; e = ENGINE_get_next(e)) {
sk_OPENSSL_CSTRING_push(engines, ENGINE_get_id(e));
}
}
ret = 0;
for (i = 0; i < sk_OPENSSL_CSTRING_num(engines); i++) {
const char *id = sk_OPENSSL_CSTRING_value(engines, i);
if ((e = ENGINE_by_id(id)) != NULL) {
const char *name = ENGINE_get_name(e);
BIO_printf(out, "(%s) %s\n", id, name);
util_do_cmds(e, pre_cmds, out, indent);
if (strcmp(ENGINE_get_id(e), id) != 0) {
BIO_printf(out, "Loaded: (%s) %s\n",
ENGINE_get_id(e), ENGINE_get_name(e));
}
if (list_cap) {
int cap_size = 256;
char *cap_buf = NULL;
int k, n;
const int *nids;
ENGINE_CIPHERS_PTR fn_c;
ENGINE_DIGESTS_PTR fn_d;
ENGINE_PKEY_METHS_PTR fn_pk;
if (ENGINE_get_RSA(e) != NULL
&& !append_buf(&cap_buf, &cap_size, "RSA"))
goto end;
if (ENGINE_get_DSA(e) != NULL
&& !append_buf(&cap_buf, &cap_size, "DSA"))
goto end;
if (ENGINE_get_DH(e) != NULL
&& !append_buf(&cap_buf, &cap_size, "DH"))
goto end;
if (ENGINE_get_RAND(e) != NULL
&& !append_buf(&cap_buf, &cap_size, "RAND"))
goto end;
fn_c = ENGINE_get_ciphers(e);
if (!fn_c)
goto skip_ciphers;
n = fn_c(e, NULL, &nids, 0);
for (k = 0; k < n; ++k)
if (!append_buf(&cap_buf, &cap_size, OBJ_nid2sn(nids[k])))
goto end;
skip_ciphers:
fn_d = ENGINE_get_digests(e);
if (!fn_d)
goto skip_digests;
n = fn_d(e, NULL, &nids, 0);
for (k = 0; k < n; ++k)
if (!append_buf(&cap_buf, &cap_size, OBJ_nid2sn(nids[k])))
goto end;
skip_digests:
fn_pk = ENGINE_get_pkey_meths(e);
if (!fn_pk)
goto skip_pmeths;
n = fn_pk(e, NULL, &nids, 0);
for (k = 0; k < n; ++k)
if (!append_buf(&cap_buf, &cap_size, OBJ_nid2sn(nids[k])))
goto end;
skip_pmeths:
if (cap_buf && (*cap_buf != '\0'))
BIO_printf(out, " [%s]\n", cap_buf);
OPENSSL_free(cap_buf);
}
if (test_avail) {
BIO_printf(out, "%s", indent);
if (ENGINE_init(e)) {
BIO_printf(out, "[ available ]\n");
util_do_cmds(e, post_cmds, out, indent);
ENGINE_finish(e);
} else {
BIO_printf(out, "[ unavailable ]\n");
if (test_avail_noise)
ERR_print_errors_fp(stdout);
ERR_clear_error();
}
}
if ((verbose > 0) && !util_verbose(e, verbose, out, indent))
goto end;
ENGINE_free(e);
} else {
ERR_print_errors(bio_err);
if (++ret > 127)
ret = 127;
}
}
end:
ERR_print_errors(bio_err);
sk_OPENSSL_CSTRING_free(engines);
sk_OPENSSL_STRING_free(pre_cmds);
sk_OPENSSL_STRING_free(post_cmds);
BIO_free_all(out);
return (ret);
}
