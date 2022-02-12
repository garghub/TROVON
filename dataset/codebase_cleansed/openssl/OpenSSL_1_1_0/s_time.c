static double tm_Time_F(int s)
{
return app_tminterval(s, 1);
}
int s_time_main(int argc, char **argv)
{
char buf[1024 * 8];
SSL *scon = NULL;
SSL_CTX *ctx = NULL;
const SSL_METHOD *meth = NULL;
char *CApath = NULL, *CAfile = NULL, *cipher = NULL, *www_path = NULL;
char *host = SSL_CONNECT_NAME, *certfile = NULL, *keyfile = NULL, *prog;
double totalTime = 0.0;
int noCApath = 0, noCAfile = 0;
int maxtime = SECONDS, nConn = 0, perform = 3, ret = 1, i, st_bugs = 0;
long bytes_read = 0, finishtime = 0;
OPTION_CHOICE o;
int max_version = 0, ver, buf_len;
size_t buf_size;
meth = TLS_client_method();
prog = opt_init(argc, argv, s_time_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(s_time_options);
ret = 0;
goto end;
case OPT_CONNECT:
host = opt_arg();
break;
case OPT_REUSE:
perform = 2;
break;
case OPT_NEW:
perform = 1;
break;
case OPT_VERIFY:
if (!opt_int(opt_arg(), &verify_args.depth))
goto opthelp;
BIO_printf(bio_err, "%s: verify depth is %d\n",
prog, verify_args.depth);
break;
case OPT_CERT:
certfile = opt_arg();
break;
case OPT_KEY:
keyfile = opt_arg();
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
case OPT_CIPHER:
cipher = opt_arg();
break;
case OPT_BUGS:
st_bugs = 1;
break;
case OPT_TIME:
if (!opt_int(opt_arg(), &maxtime))
goto opthelp;
break;
case OPT_WWW:
www_path = opt_arg();
buf_size = strlen(www_path) + sizeof(fmt_http_get_cmd) - 2;
if (buf_size > sizeof(buf)) {
BIO_printf(bio_err, "%s: -www option is too long\n", prog);
goto end;
}
break;
case OPT_SSL3:
max_version = SSL3_VERSION;
break;
}
}
argc = opt_num_rest();
if (argc != 0)
goto opthelp;
if (cipher == NULL)
cipher = getenv("SSL_CIPHER");
if (cipher == NULL) {
BIO_printf(bio_err, "No CIPHER specified\n");
goto end;
}
if ((ctx = SSL_CTX_new(meth)) == NULL)
goto end;
SSL_CTX_set_quiet_shutdown(ctx, 1);
if (SSL_CTX_set_max_proto_version(ctx, max_version) == 0)
goto end;
if (st_bugs)
SSL_CTX_set_options(ctx, SSL_OP_ALL);
if (!SSL_CTX_set_cipher_list(ctx, cipher))
goto end;
if (!set_cert_stuff(ctx, certfile, keyfile))
goto end;
if (!ctx_set_verify_locations(ctx, CAfile, CApath, noCAfile, noCApath)) {
ERR_print_errors(bio_err);
goto end;
}
if (!(perform & 1))
goto next;
printf("Collecting connection statistics for %d seconds\n", maxtime);
bytes_read = 0;
finishtime = (long)time(NULL) + maxtime;
tm_Time_F(START);
for (;;) {
if (finishtime < (long)time(NULL))
break;
if ((scon = doConnection(NULL, host, ctx)) == NULL)
goto end;
if (www_path != NULL) {
buf_len = BIO_snprintf(buf, sizeof buf,
fmt_http_get_cmd, www_path);
if (SSL_write(scon, buf, buf_len) <= 0)
goto end;
while ((i = SSL_read(scon, buf, sizeof(buf))) > 0)
bytes_read += i;
}
#ifdef NO_SHUTDOWN
SSL_set_shutdown(scon, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
#else
SSL_shutdown(scon);
#endif
BIO_closesocket(SSL_get_fd(scon));
nConn += 1;
if (SSL_session_reused(scon))
ver = 'r';
else {
ver = SSL_version(scon);
if (ver == TLS1_VERSION)
ver = 't';
else if (ver == SSL3_VERSION)
ver = '3';
else
ver = '*';
}
fputc(ver, stdout);
fflush(stdout);
SSL_free(scon);
scon = NULL;
}
totalTime += tm_Time_F(STOP);
i = (int)((long)time(NULL) - finishtime + maxtime);
printf
("\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
nConn, totalTime, ((double)nConn / totalTime), bytes_read);
printf
("%d connections in %ld real seconds, %ld bytes read per connection\n",
nConn, (long)time(NULL) - finishtime + maxtime, bytes_read / nConn);
next:
if (!(perform & 2))
goto end;
printf("\n\nNow timing with session id reuse.\n");
if ((scon = doConnection(NULL, host, ctx)) == NULL) {
BIO_printf(bio_err, "Unable to get connection\n");
goto end;
}
if (www_path != NULL) {
buf_len = BIO_snprintf(buf, sizeof buf,
fmt_http_get_cmd, www_path);
if (SSL_write(scon, buf, buf_len) <= 0)
goto end;
while (SSL_read(scon, buf, sizeof(buf)) > 0)
continue;
}
#ifdef NO_SHUTDOWN
SSL_set_shutdown(scon, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
#else
SSL_shutdown(scon);
#endif
BIO_closesocket(SSL_get_fd(scon));
nConn = 0;
totalTime = 0.0;
finishtime = (long)time(NULL) + maxtime;
printf("starting\n");
bytes_read = 0;
tm_Time_F(START);
for (;;) {
if (finishtime < (long)time(NULL))
break;
if ((doConnection(scon, host, ctx)) == NULL)
goto end;
if (www_path) {
BIO_snprintf(buf, sizeof buf, "GET %s HTTP/1.0\r\n\r\n",
www_path);
if (SSL_write(scon, buf, strlen(buf)) <= 0)
goto end;
while ((i = SSL_read(scon, buf, sizeof(buf))) > 0)
bytes_read += i;
}
#ifdef NO_SHUTDOWN
SSL_set_shutdown(scon, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
#else
SSL_shutdown(scon);
#endif
BIO_closesocket(SSL_get_fd(scon));
nConn += 1;
if (SSL_session_reused(scon))
ver = 'r';
else {
ver = SSL_version(scon);
if (ver == TLS1_VERSION)
ver = 't';
else if (ver == SSL3_VERSION)
ver = '3';
else
ver = '*';
}
fputc(ver, stdout);
fflush(stdout);
}
totalTime += tm_Time_F(STOP);
printf
("\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
nConn, totalTime, ((double)nConn / totalTime), bytes_read);
printf
("%d connections in %ld real seconds, %ld bytes read per connection\n",
nConn, (long)time(NULL) - finishtime + maxtime, bytes_read / nConn);
ret = 0;
end:
SSL_free(scon);
SSL_CTX_free(ctx);
return (ret);
}
static SSL *doConnection(SSL *scon, const char *host, SSL_CTX *ctx)
{
BIO *conn;
SSL *serverCon;
int width, i;
fd_set readfds;
if ((conn = BIO_new(BIO_s_connect())) == NULL)
return (NULL);
BIO_set_conn_hostname(conn, host);
if (scon == NULL)
serverCon = SSL_new(ctx);
else {
serverCon = scon;
SSL_set_connect_state(serverCon);
}
SSL_set_bio(serverCon, conn, conn);
for (;;) {
i = SSL_connect(serverCon);
if (BIO_sock_should_retry(i)) {
BIO_printf(bio_err, "DELAY\n");
i = SSL_get_fd(serverCon);
width = i + 1;
FD_ZERO(&readfds);
openssl_fdset(i, &readfds);
select(width, (void *)&readfds, NULL, NULL, NULL);
continue;
}
break;
}
if (i <= 0) {
BIO_printf(bio_err, "ERROR\n");
if (verify_args.error != X509_V_OK)
BIO_printf(bio_err, "verify error:%s\n",
X509_verify_cert_error_string(verify_args.error));
else
ERR_print_errors(bio_err);
if (scon == NULL)
SSL_free(serverCon);
return NULL;
}
return serverCon;
}
