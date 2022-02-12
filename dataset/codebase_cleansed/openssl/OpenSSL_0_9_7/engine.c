static void identity(void *ptr)
{
return;
}
static int append_buf(char **buf, const char *s, int *size, int step)
{
int l = strlen(s);
if (*buf == NULL)
{
*size = step;
*buf = OPENSSL_malloc(*size);
if (*buf == NULL)
return 0;
**buf = '\0';
}
if (**buf != '\0')
l += 2;
if (strlen(*buf) + strlen(s) >= (unsigned int)*size)
{
*size += step;
*buf = OPENSSL_realloc(*buf, *size);
}
if (*buf == NULL)
return 0;
if (**buf != '\0')
strcat(*buf, ", ");
strcat(*buf, s);
return 1;
}
static int util_flags(BIO *bio_out, unsigned int flags, const char *indent)
{
int started = 0, err = 0;
BIO_printf(bio_out, "%s%s(input flags): ", indent, indent);
if(flags == 0)
{
BIO_printf(bio_out, "<no flags>\n");
return 1;
}
if(flags & ENGINE_CMD_FLAG_INTERNAL)
{
BIO_printf(bio_out, "[Internal] ");
}
if(flags & ENGINE_CMD_FLAG_NUMERIC)
{
if(started)
{
BIO_printf(bio_out, "|");
err = 1;
}
BIO_printf(bio_out, "NUMERIC");
started = 1;
}
if(flags & ENGINE_CMD_FLAG_STRING)
{
if(started)
{
BIO_printf(bio_out, "|");
err = 1;
}
BIO_printf(bio_out, "STRING");
started = 1;
}
if(flags & ENGINE_CMD_FLAG_NO_INPUT)
{
if(started)
{
BIO_printf(bio_out, "|");
err = 1;
}
BIO_printf(bio_out, "NO_INPUT");
started = 1;
}
flags = flags & ~ENGINE_CMD_FLAG_NUMERIC &
~ENGINE_CMD_FLAG_STRING &
~ENGINE_CMD_FLAG_NO_INPUT &
~ENGINE_CMD_FLAG_INTERNAL;
if(flags)
{
if(started) BIO_printf(bio_out, "|");
BIO_printf(bio_out, "<0x%04X>", flags);
}
if(err)
BIO_printf(bio_out, " <illegal flags!>");
BIO_printf(bio_out, "\n");
return 1;
}
static int util_verbose(ENGINE *e, int verbose, BIO *bio_out, const char *indent)
{
static const int line_wrap = 78;
int num;
int ret = 0;
char *name = NULL;
char *desc = NULL;
int flags;
int xpos = 0;
STACK *cmds = NULL;
if(!ENGINE_ctrl(e, ENGINE_CTRL_HAS_CTRL_FUNCTION, 0, NULL, NULL) ||
((num = ENGINE_ctrl(e, ENGINE_CTRL_GET_FIRST_CMD_TYPE,
0, NULL, NULL)) <= 0))
{
#if 0
BIO_printf(bio_out, "%s<no control commands>\n", indent);
#endif
return 1;
}
cmds = sk_new_null();
if(!cmds)
goto err;
do {
int len;
if((flags = ENGINE_ctrl(e, ENGINE_CTRL_GET_CMD_FLAGS, num,
NULL, NULL)) < 0)
goto err;
if (!(flags & ENGINE_CMD_FLAG_INTERNAL) || verbose >= 4)
{
if((len = ENGINE_ctrl(e, ENGINE_CTRL_GET_NAME_LEN_FROM_CMD, num,
NULL, NULL)) <= 0)
goto err;
if((name = OPENSSL_malloc(len + 1)) == NULL)
goto err;
if(ENGINE_ctrl(e, ENGINE_CTRL_GET_NAME_FROM_CMD, num, name,
NULL) <= 0)
goto err;
if((len = ENGINE_ctrl(e, ENGINE_CTRL_GET_DESC_LEN_FROM_CMD, num,
NULL, NULL)) < 0)
goto err;
if(len > 0)
{
if((desc = OPENSSL_malloc(len + 1)) == NULL)
goto err;
if(ENGINE_ctrl(e, ENGINE_CTRL_GET_DESC_FROM_CMD, num, desc,
NULL) <= 0)
goto err;
}
if(xpos == 0)
xpos = BIO_printf(bio_out, indent);
else
xpos += BIO_printf(bio_out, ", ");
if(verbose == 1)
{
if((xpos > (int)strlen(indent)) &&
(xpos + (int)strlen(name) > line_wrap))
{
BIO_printf(bio_out, "\n");
xpos = BIO_printf(bio_out, indent);
}
xpos += BIO_printf(bio_out, "%s", name);
}
else
{
BIO_printf(bio_out, "%s: %s\n", name,
(desc == NULL) ? "<no description>" : desc);
if((verbose >= 3) && !util_flags(bio_out, flags,
indent))
goto err;
xpos = 0;
}
}
OPENSSL_free(name); name = NULL;
if(desc) { OPENSSL_free(desc); desc = NULL; }
num = ENGINE_ctrl(e, ENGINE_CTRL_GET_NEXT_CMD_TYPE,
num, NULL, NULL);
} while(num > 0);
if(xpos > 0)
BIO_printf(bio_out, "\n");
ret = 1;
err:
if(cmds) sk_pop_free(cmds, identity);
if(name) OPENSSL_free(name);
if(desc) OPENSSL_free(desc);
return ret;
}
static void util_do_cmds(ENGINE *e, STACK *cmds, BIO *bio_out, const char *indent)
{
int loop, res, num = sk_num(cmds);
if(num < 0)
{
BIO_printf(bio_out, "[Error]: internal stack error\n");
return;
}
for(loop = 0; loop < num; loop++)
{
char buf[256];
const char *cmd, *arg;
cmd = sk_value(cmds, loop);
res = 1;
if((arg = strstr(cmd, ":")) == NULL)
{
if(!ENGINE_ctrl_cmd_string(e, cmd, NULL, 0))
res = 0;
}
else
{
if((int)(arg - cmd) > 254)
{
BIO_printf(bio_out,"[Error]: command name too long\n");
return;
}
memcpy(buf, cmd, (int)(arg - cmd));
buf[arg-cmd] = '\0';
arg++;
if(!ENGINE_ctrl_cmd_string(e, buf, arg, 0))
res = 0;
}
if(res)
BIO_printf(bio_out, "[Success]: %s\n", cmd);
else
{
BIO_printf(bio_out, "[Failure]: %s\n", cmd);
ERR_print_errors(bio_out);
}
}
}
int MAIN(int argc, char **argv)
{
int ret=1,i;
char **pp;
int verbose=0, list_cap=0, test_avail=0;
ENGINE *e;
STACK *engines = sk_new_null();
STACK *pre_cmds = sk_new_null();
STACK *post_cmds = sk_new_null();
int badops=1;
BIO *bio_out=NULL;
const char *indent = " ";
apps_startup();
SSL_load_error_strings();
if (bio_err == NULL)
bio_err=BIO_new_fp(stderr,BIO_NOCLOSE);
if (!load_config(bio_err, NULL))
goto end;
bio_out=BIO_new_fp(stdout,BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
bio_out = BIO_push(tmpbio, bio_out);
}
#endif
argc--;
argv++;
while (argc >= 1)
{
if (strncmp(*argv,"-v",2) == 0)
{
if(strspn(*argv + 1, "v") < strlen(*argv + 1))
goto skip_arg_loop;
if((verbose=strlen(*argv + 1)) > 4)
goto skip_arg_loop;
}
else if (strcmp(*argv,"-c") == 0)
list_cap=1;
else if (strcmp(*argv,"-t") == 0)
test_avail=1;
else if (strcmp(*argv,"-pre") == 0)
{
argc--; argv++;
sk_push(pre_cmds,*argv);
}
else if (strcmp(*argv,"-post") == 0)
{
argc--; argv++;
sk_push(post_cmds,*argv);
}
else if ((strncmp(*argv,"-h",2) == 0) ||
(strcmp(*argv,"-?") == 0))
goto skip_arg_loop;
else
sk_push(engines,*argv);
argc--;
argv++;
}
badops = 0;
skip_arg_loop:
if (badops)
{
for (pp=engine_usage; (*pp != NULL); pp++)
BIO_printf(bio_err,"%s",*pp);
goto end;
}
if (sk_num(engines) == 0)
{
for(e = ENGINE_get_first(); e != NULL; e = ENGINE_get_next(e))
{
sk_push(engines,(char *)ENGINE_get_id(e));
}
}
for (i=0; i<sk_num(engines); i++)
{
const char *id = sk_value(engines,i);
if ((e = ENGINE_by_id(id)) != NULL)
{
const char *name = ENGINE_get_name(e);
BIO_printf(bio_out, "(%s) %s\n", id, name);
util_do_cmds(e, pre_cmds, bio_out, indent);
if (strcmp(ENGINE_get_id(e), id) != 0)
{
BIO_printf(bio_out, "Loaded: (%s) %s\n",
ENGINE_get_id(e), ENGINE_get_name(e));
}
if (list_cap)
{
int cap_size = 256;
char *cap_buf = NULL;
int k,n;
const int *nids;
ENGINE_CIPHERS_PTR fn_c;
ENGINE_DIGESTS_PTR fn_d;
if (ENGINE_get_RSA(e) != NULL
&& !append_buf(&cap_buf, "RSA",
&cap_size, 256))
goto end;
if (ENGINE_get_DSA(e) != NULL
&& !append_buf(&cap_buf, "DSA",
&cap_size, 256))
goto end;
if (ENGINE_get_DH(e) != NULL
&& !append_buf(&cap_buf, "DH",
&cap_size, 256))
goto end;
if (ENGINE_get_RAND(e) != NULL
&& !append_buf(&cap_buf, "RAND",
&cap_size, 256))
goto end;
fn_c = ENGINE_get_ciphers(e);
if(!fn_c) goto skip_ciphers;
n = fn_c(e, NULL, &nids, 0);
for(k=0 ; k < n ; ++k)
if(!append_buf(&cap_buf,
OBJ_nid2sn(nids[k]),
&cap_size, 256))
goto end;
skip_ciphers:
fn_d = ENGINE_get_digests(e);
if(!fn_d) goto skip_digests;
n = fn_d(e, NULL, &nids, 0);
for(k=0 ; k < n ; ++k)
if(!append_buf(&cap_buf,
OBJ_nid2sn(nids[k]),
&cap_size, 256))
goto end;
skip_digests:
if (cap_buf && (*cap_buf != '\0'))
BIO_printf(bio_out, " [%s]\n", cap_buf);
OPENSSL_free(cap_buf);
}
if(test_avail)
{
BIO_printf(bio_out, "%s", indent);
if (ENGINE_init(e))
{
BIO_printf(bio_out, "[ available ]\n");
util_do_cmds(e, post_cmds, bio_out, indent);
ENGINE_finish(e);
}
else
{
BIO_printf(bio_out, "[ unavailable ]\n");
ERR_print_errors_fp(stdout);
ERR_clear_error();
}
}
if((verbose > 0) && !util_verbose(e, verbose, bio_out, indent))
goto end;
ENGINE_free(e);
}
else
ERR_print_errors(bio_err);
}
ret=0;
end:
ERR_print_errors(bio_err);
sk_pop_free(engines, identity);
sk_pop_free(pre_cmds, identity);
sk_pop_free(post_cmds, identity);
if (bio_out != NULL) BIO_free_all(bio_out);
apps_shutdown();
OPENSSL_EXIT(ret);
}
