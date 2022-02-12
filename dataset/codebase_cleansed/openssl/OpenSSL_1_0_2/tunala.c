static DH *get_dh512(void)
{
DH *dh = NULL;
if ((dh = DH_new()) == NULL)
return (NULL);
dh->p = BN_bin2bn(dh512_p, sizeof(dh512_p), NULL);
dh->g = BN_bin2bn(dh512_g, sizeof(dh512_g), NULL);
if ((dh->p == NULL) || (dh->g == NULL))
return (NULL);
return (dh);
}
static int usage(const char *errstr, int isunknownarg)
{
if (isunknownarg)
fprintf(stderr, "Error: unknown argument '%s'\n", errstr);
else
fprintf(stderr, "Error: %s\n", errstr);
fprintf(stderr, "%s\n", helpstring);
return 1;
}
static int err_str0(const char *str0)
{
fprintf(stderr, "%s\n", str0);
return 1;
}
static int err_str1(const char *fmt, const char *str1)
{
fprintf(stderr, fmt, str1);
fprintf(stderr, "\n");
return 1;
}
static int parse_max_tunnels(const char *s, unsigned int *maxtunnels)
{
unsigned long l;
if (!int_strtoul(s, &l) || (l < 1) || (l > 1024)) {
fprintf(stderr, "Error, '%s' is an invalid value for "
"maxtunnels\n", s);
return 0;
}
*maxtunnels = (unsigned int)l;
return 1;
}
static int parse_server_mode(const char *s, int *servermode)
{
unsigned long l;
if (!int_strtoul(s, &l) || (l > 1)) {
fprintf(stderr, "Error, '%s' is an invalid value for the "
"server mode\n", s);
return 0;
}
*servermode = (int)l;
return 1;
}
static int parse_dh_special(const char *s, const char **dh_special)
{
if ((strcmp(s, "NULL") == 0) || (strcmp(s, "generate") == 0) ||
(strcmp(s, "standard") == 0)) {
*dh_special = s;
return 1;
}
fprintf(stderr, "Error, '%s' is an invalid value for 'dh_special'\n", s);
return 0;
}
static int parse_verify_level(const char *s, unsigned int *verify_level)
{
unsigned long l;
if (!int_strtoul(s, &l) || (l > 3)) {
fprintf(stderr, "Error, '%s' is an invalid value for "
"out_verify\n", s);
return 0;
}
*verify_level = (unsigned int)l;
return 1;
}
static int parse_verify_depth(const char *s, unsigned int *verify_depth)
{
unsigned long l;
if (!int_strtoul(s, &l) || (l < 1) || (l > 50)) {
fprintf(stderr, "Error, '%s' is an invalid value for "
"verify_depth\n", s);
return 0;
}
*verify_depth = (unsigned int)l;
return 1;
}
int main(int argc, char *argv[])
{
unsigned int loop;
int newfd;
tunala_world_t world;
tunala_item_t *t_item;
const char *proxy_ip;
unsigned short proxy_port;
const char *proxyhost = def_proxyhost;
const char *listenhost = def_listenhost;
unsigned int max_tunnels = def_max_tunnels;
const char *cacert = def_cacert;
const char *cert = def_cert;
const char *key = def_key;
const char *dcert = def_dcert;
const char *dkey = def_dkey;
const char *engine_id = def_engine_id;
int server_mode = def_server_mode;
int flipped = def_flipped;
const char *cipher_list = def_cipher_list;
const char *dh_file = def_dh_file;
const char *dh_special = def_dh_special;
int tmp_rsa = def_tmp_rsa;
int ctx_options = def_ctx_options;
int verify_mode = def_verify_mode;
unsigned int verify_depth = def_verify_depth;
int out_state = def_out_state;
unsigned int out_verify = def_out_verify;
int out_totals = def_out_totals;
int out_conns = def_out_conns;
next_arg:
argc--;
argv++;
if (argc > 0) {
if (strcmp(*argv, "-listen") == 0) {
if (argc < 2)
return usage("-listen requires an argument", 0);
argc--;
argv++;
listenhost = *argv;
goto next_arg;
} else if (strcmp(*argv, "-proxy") == 0) {
if (argc < 2)
return usage("-proxy requires an argument", 0);
argc--;
argv++;
proxyhost = *argv;
goto next_arg;
} else if (strcmp(*argv, "-maxtunnels") == 0) {
if (argc < 2)
return usage("-maxtunnels requires an argument", 0);
argc--;
argv++;
if (!parse_max_tunnels(*argv, &max_tunnels))
return 1;
goto next_arg;
} else if (strcmp(*argv, "-cacert") == 0) {
if (argc < 2)
return usage("-cacert requires an argument", 0);
argc--;
argv++;
if (strcmp(*argv, "NULL") == 0)
cacert = NULL;
else
cacert = *argv;
goto next_arg;
} else if (strcmp(*argv, "-cert") == 0) {
if (argc < 2)
return usage("-cert requires an argument", 0);
argc--;
argv++;
if (strcmp(*argv, "NULL") == 0)
cert = NULL;
else
cert = *argv;
goto next_arg;
} else if (strcmp(*argv, "-key") == 0) {
if (argc < 2)
return usage("-key requires an argument", 0);
argc--;
argv++;
if (strcmp(*argv, "NULL") == 0)
key = NULL;
else
key = *argv;
goto next_arg;
} else if (strcmp(*argv, "-dcert") == 0) {
if (argc < 2)
return usage("-dcert requires an argument", 0);
argc--;
argv++;
if (strcmp(*argv, "NULL") == 0)
dcert = NULL;
else
dcert = *argv;
goto next_arg;
} else if (strcmp(*argv, "-dkey") == 0) {
if (argc < 2)
return usage("-dkey requires an argument", 0);
argc--;
argv++;
if (strcmp(*argv, "NULL") == 0)
dkey = NULL;
else
dkey = *argv;
goto next_arg;
} else if (strcmp(*argv, "-engine") == 0) {
if (argc < 2)
return usage("-engine requires an argument", 0);
argc--;
argv++;
engine_id = *argv;
goto next_arg;
} else if (strcmp(*argv, "-server") == 0) {
if (argc < 2)
return usage("-server requires an argument", 0);
argc--;
argv++;
if (!parse_server_mode(*argv, &server_mode))
return 1;
goto next_arg;
} else if (strcmp(*argv, "-flipped") == 0) {
if (argc < 2)
return usage("-flipped requires an argument", 0);
argc--;
argv++;
if (!parse_server_mode(*argv, &flipped))
return 1;
goto next_arg;
} else if (strcmp(*argv, "-cipher") == 0) {
if (argc < 2)
return usage("-cipher requires an argument", 0);
argc--;
argv++;
cipher_list = *argv;
goto next_arg;
} else if (strcmp(*argv, "-dh_file") == 0) {
if (argc < 2)
return usage("-dh_file requires an argument", 0);
if (dh_special)
return usage("cannot mix -dh_file with " "-dh_special", 0);
argc--;
argv++;
dh_file = *argv;
goto next_arg;
} else if (strcmp(*argv, "-dh_special") == 0) {
if (argc < 2)
return usage("-dh_special requires an argument", 0);
if (dh_file)
return usage("cannot mix -dh_file with " "-dh_special", 0);
argc--;
argv++;
if (!parse_dh_special(*argv, &dh_special))
return 1;
goto next_arg;
} else if (strcmp(*argv, "-no_tmp_rsa") == 0) {
tmp_rsa = 0;
goto next_arg;
} else if (strcmp(*argv, "-no_ssl2") == 0) {
ctx_options |= SSL_OP_NO_SSLv2;
goto next_arg;
} else if (strcmp(*argv, "-no_ssl3") == 0) {
ctx_options |= SSL_OP_NO_SSLv3;
goto next_arg;
} else if (strcmp(*argv, "-no_tls1") == 0) {
ctx_options |= SSL_OP_NO_TLSv1;
goto next_arg;
} else if (strcmp(*argv, "-v_peer") == 0) {
verify_mode |= SSL_VERIFY_PEER;
goto next_arg;
} else if (strcmp(*argv, "-v_strict") == 0) {
verify_mode |= SSL_VERIFY_FAIL_IF_NO_PEER_CERT;
goto next_arg;
} else if (strcmp(*argv, "-v_once") == 0) {
verify_mode |= SSL_VERIFY_CLIENT_ONCE;
goto next_arg;
} else if (strcmp(*argv, "-v_depth") == 0) {
if (argc < 2)
return usage("-v_depth requires an argument", 0);
argc--;
argv++;
if (!parse_verify_depth(*argv, &verify_depth))
return 1;
goto next_arg;
} else if (strcmp(*argv, "-out_state") == 0) {
out_state = 1;
goto next_arg;
} else if (strcmp(*argv, "-out_verify") == 0) {
if (argc < 2)
return usage("-out_verify requires an argument", 0);
argc--;
argv++;
if (!parse_verify_level(*argv, &out_verify))
return 1;
goto next_arg;
} else if (strcmp(*argv, "-out_totals") == 0) {
out_totals = 1;
goto next_arg;
} else if (strcmp(*argv, "-out_conns") == 0) {
out_conns = 1;
goto next_arg;
} else if ((strcmp(*argv, "-h") == 0) ||
(strcmp(*argv, "-help") == 0) ||
(strcmp(*argv, "-?") == 0)) {
fprintf(stderr, "%s\n", helpstring);
return 0;
} else
return usage(*argv, 1);
}
if (!cert && !dcert && server_mode)
fprintf(stderr, "WARNING: you are running an SSL server without "
"a certificate - this may not work!\n");
if (!ip_initialise())
return err_str0("ip_initialise failed");
if ((world.ssl_ctx = initialise_ssl_ctx(server_mode, engine_id,
cacert, cert, key, dcert, dkey,
cipher_list, dh_file, dh_special,
tmp_rsa, ctx_options, out_state,
out_verify, verify_mode,
verify_depth)) == NULL)
return err_str1("initialise_ssl_ctx(engine_id=%s) failed",
(engine_id == NULL) ? "NULL" : engine_id);
if (engine_id)
fprintf(stderr, "Info, engine '%s' initialised\n", engine_id);
if ((world.listen_fd = ip_create_listener(listenhost)) == -1)
return err_str1("ip_create_listener(%s) failed", listenhost);
fprintf(stderr, "Info, listening on '%s'\n", listenhost);
if (!ip_parse_address(proxyhost, &proxy_ip, &proxy_port, 0))
return err_str1("ip_parse_address(%s) failed", proxyhost);
fprintf(stderr, "Info, proxying to '%s' (%d.%d.%d.%d:%d)\n", proxyhost,
(int)proxy_ip[0], (int)proxy_ip[1],
(int)proxy_ip[2], (int)proxy_ip[3], (int)proxy_port);
fprintf(stderr, "Info, set maxtunnels to %d\n", (int)max_tunnels);
fprintf(stderr, "Info, set to operate as an SSL %s\n",
(server_mode ? "server" : "client"));
world.tunnels_used = world.tunnels_size = 0;
world.tunnels = NULL;
world.server_mode = server_mode;
selector_init(&world.selector);
main_loop:
if (world.tunnels_used < max_tunnels)
selector_add_listener(&world.selector, world.listen_fd);
for (loop = 0; loop < world.tunnels_used; loop++)
selector_add_tunala(&world.selector, world.tunnels + loop);
switch (selector_select(&world.selector)) {
case -1:
if (errno != EINTR) {
fprintf(stderr, "selector_select returned a " "badness error.\n");
goto shouldnt_happen;
}
fprintf(stderr, "Warn, selector interrupted by a signal\n");
goto main_loop;
case 0:
fprintf(stderr, "Warn, selector_select returned 0 - signal?" "?\n");
goto main_loop;
default:
break;
}
if ((world.tunnels_used < max_tunnels)
&& (selector_get_listener(&world.selector, world.listen_fd, &newfd) ==
1)) {
if (!tunala_world_new_item(&world, newfd, proxy_ip,
proxy_port, flipped))
fprintf(stderr, "tunala_world_new_item failed\n");
else if (out_conns)
fprintf(stderr, "Info, new tunnel opened, now up to "
"%d\n", world.tunnels_used);
}
loop = 0;
t_item = world.tunnels;
while (loop < world.tunnels_used) {
if (!tunala_item_io(&world.selector, t_item)) {
if (!out_totals)
goto skip_totals;
fprintf(stderr, "Tunnel closing, traffic stats follow\n");
fprintf(stderr, io_stats_dirty,
buffer_total_in(state_machine_get_buffer
(&t_item->sm, SM_DIRTY_IN)),
buffer_total_out(state_machine_get_buffer
(&t_item->sm, SM_DIRTY_OUT)));
fprintf(stderr, io_stats_clean,
buffer_total_out(state_machine_get_buffer
(&t_item->sm, SM_CLEAN_OUT)),
buffer_total_in(state_machine_get_buffer
(&t_item->sm, SM_CLEAN_IN)));
skip_totals:
tunala_world_del_item(&world, loop);
if (out_conns)
fprintf(stderr, "Info, tunnel closed, down to %d\n",
world.tunnels_used);
} else {
loop++;
t_item++;
}
}
goto main_loop;
shouldnt_happen:
abort();
return 1;
}
static int ctx_set_cert(SSL_CTX *ctx, const char *cert, const char *key)
{
FILE *fp = NULL;
X509 *x509 = NULL;
EVP_PKEY *pkey = NULL;
int toret = 0;
if (cert) {
if ((fp = fopen(cert, "r")) == NULL) {
fprintf(stderr, "Error opening cert file '%s'\n", cert);
goto err;
}
if (!PEM_read_X509(fp, &x509, NULL, NULL)) {
fprintf(stderr, "Error reading PEM cert from '%s'\n", cert);
goto err;
}
if (!SSL_CTX_use_certificate(ctx, x509)) {
fprintf(stderr, "Error, cert in '%s' can not be used\n", cert);
goto err;
}
fclose(fp);
fp = NULL;
fprintf(stderr, "Info, operating with cert in '%s'\n", cert);
if (!key)
key = cert;
} else {
if (key)
fprintf(stderr, "Error, can't specify a key without a "
"corresponding certificate\n");
else
fprintf(stderr, "Error, ctx_set_cert called with " "NULLs!\n");
goto err;
}
if (key) {
if ((fp = fopen(key, "r")) == NULL) {
fprintf(stderr, "Error opening key file '%s'\n", key);
goto err;
}
if (!PEM_read_PrivateKey(fp, &pkey, NULL, NULL)) {
fprintf(stderr, "Error reading PEM key from '%s'\n", key);
goto err;
}
if (!SSL_CTX_use_PrivateKey(ctx, pkey)) {
fprintf(stderr, "Error, key in '%s' can not be used\n", key);
goto err;
}
fprintf(stderr, "Info, operating with key in '%s'\n", key);
} else
fprintf(stderr, "Info, operating without a cert or key\n");
toret = 1;
err:
if (x509)
X509_free(x509);
if (pkey)
EVP_PKEY_free(pkey);
if (fp)
fclose(fp);
return toret;
}
static int ctx_set_dh(SSL_CTX *ctx, const char *dh_file,
const char *dh_special)
{
DH *dh = NULL;
FILE *fp = NULL;
if (dh_special) {
if (strcmp(dh_special, "NULL") == 0)
return 1;
if (strcmp(dh_special, "standard") == 0) {
if ((dh = get_dh512()) == NULL) {
fprintf(stderr, "Error, can't parse 'standard'"
" DH parameters\n");
return 0;
}
fprintf(stderr, "Info, using 'standard' DH parameters\n");
goto do_it;
}
if (strcmp(dh_special, "generate") != 0)
abort();
fprintf(stderr, "Info, generating DH parameters ... ");
fflush(stderr);
if (!(dh = DH_new()) || !DH_generate_parameters_ex(dh, 512,
DH_GENERATOR_5,
NULL)) {
fprintf(stderr, "error!\n");
if (dh)
DH_free(dh);
return 0;
}
fprintf(stderr, "complete\n");
goto do_it;
}
if ((fp = fopen(dh_file, "r")) == NULL) {
fprintf(stderr, "Error, couldn't open '%s' for DH parameters\n",
dh_file);
return 0;
}
dh = PEM_read_DHparams(fp, NULL, NULL, NULL);
fclose(fp);
if (dh == NULL) {
fprintf(stderr, "Error, could not parse DH parameters from '%s'\n",
dh_file);
return 0;
}
fprintf(stderr, "Info, using DH parameters from file '%s'\n", dh_file);
do_it:
SSL_CTX_set_tmp_dh(ctx, dh);
DH_free(dh);
return 1;
}
static SSL_CTX *initialise_ssl_ctx(int server_mode, const char *engine_id,
const char *CAfile, const char *cert,
const char *key, const char *dcert,
const char *dkey, const char *cipher_list,
const char *dh_file,
const char *dh_special, int tmp_rsa,
int ctx_options, int out_state,
int out_verify, int verify_mode,
unsigned int verify_depth)
{
SSL_CTX *ctx = NULL, *ret = NULL;
const SSL_METHOD *meth;
ENGINE *e = NULL;
OpenSSL_add_ssl_algorithms();
SSL_load_error_strings();
meth = (server_mode ? SSLv23_server_method() : SSLv23_client_method());
if (meth == NULL)
goto err;
if (engine_id) {
ENGINE_load_builtin_engines();
if ((e = ENGINE_by_id(engine_id)) == NULL) {
fprintf(stderr, "Error obtaining '%s' engine, openssl "
"errors follow\n", engine_id);
goto err;
}
if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
fprintf(stderr, "Error assigning '%s' engine, openssl "
"errors follow\n", engine_id);
goto err;
}
ENGINE_free(e);
}
if ((ctx = SSL_CTX_new(meth)) == NULL)
goto err;
if (CAfile) {
if (!X509_STORE_load_locations(SSL_CTX_get_cert_store(ctx),
CAfile, NULL)) {
fprintf(stderr, "Error loading CA cert(s) in '%s'\n", CAfile);
goto err;
}
fprintf(stderr, "Info, operating with CA cert(s) in '%s'\n", CAfile);
} else
fprintf(stderr, "Info, operating without a CA cert(-list)\n");
if (!SSL_CTX_set_default_verify_paths(ctx)) {
fprintf(stderr, "Error setting default verify paths\n");
goto err;
}
if ((cert || key) && !ctx_set_cert(ctx, cert, key))
goto err;
if ((dcert || dkey) && !ctx_set_cert(ctx, dcert, dkey))
goto err;
if (tmp_rsa)
SSL_CTX_set_tmp_rsa_callback(ctx, cb_generate_tmp_rsa);
if (cipher_list) {
if (!SSL_CTX_set_cipher_list(ctx, cipher_list)) {
fprintf(stderr, "Error setting cipher list '%s'\n", cipher_list);
goto err;
}
fprintf(stderr, "Info, set cipher list '%s'\n", cipher_list);
} else
fprintf(stderr, "Info, operating with default cipher list\n");
if ((dh_file || dh_special) && !ctx_set_dh(ctx, dh_file, dh_special))
goto err;
SSL_CTX_set_options(ctx, ctx_options);
if (out_state)
cb_ssl_info_set_output(stderr);
if (out_verify > 0) {
cb_ssl_verify_set_output(stderr);
cb_ssl_verify_set_level(out_verify);
}
cb_ssl_verify_set_depth(verify_depth);
SSL_CTX_set_info_callback(ctx, cb_ssl_info);
SSL_CTX_set_verify(ctx, verify_mode, cb_ssl_verify);
ret = ctx;
err:
if (!ret) {
ERR_print_errors_fp(stderr);
if (ctx)
SSL_CTX_free(ctx);
}
return ret;
}
static void selector_sets_init(select_sets_t * s)
{
s->max = 0;
FD_ZERO(&s->reads);
FD_ZERO(&s->sends);
FD_ZERO(&s->excepts);
}
static void selector_init(tunala_selector_t * selector)
{
selector_sets_init(&selector->last_selected);
selector_sets_init(&selector->next_select);
}
static void selector_add_raw_fd(tunala_selector_t * s, int fd, int flags)
{
FD_SET(fd, &s->next_select.excepts);
if (flags & SEL_READS)
FD_SET(fd, &s->next_select.reads);
if (flags & SEL_SENDS)
FD_SET(fd, &s->next_select.sends);
if (s->next_select.max < (fd + 1))
s->next_select.max = fd + 1;
}
static void selector_add_listener(tunala_selector_t * selector, int fd)
{
selector_add_raw_fd(selector, fd, SEL_READS);
}
static void selector_add_tunala(tunala_selector_t * s, tunala_item_t * t)
{
if (t->clean_read != -1) {
selector_add_raw_fd(s, t->clean_read,
(buffer_full(state_machine_get_buffer(&t->sm,
SM_CLEAN_IN))
? SEL_EXCEPTS : SEL_READS));
}
if (t->clean_send != -1) {
selector_add_raw_fd(s, t->clean_send,
(buffer_empty(state_machine_get_buffer(&t->sm,
SM_CLEAN_OUT))
? SEL_EXCEPTS : SEL_SENDS));
}
if (t->dirty_read != -1) {
selector_add_raw_fd(s, t->dirty_read,
(buffer_full(state_machine_get_buffer(&t->sm,
SM_DIRTY_IN))
? SEL_EXCEPTS : SEL_READS));
}
if (t->dirty_send != -1) {
selector_add_raw_fd(s, t->dirty_send,
(buffer_empty(state_machine_get_buffer(&t->sm,
SM_DIRTY_OUT))
? SEL_EXCEPTS : SEL_SENDS));
}
}
static int selector_select(tunala_selector_t * selector)
{
memcpy(&selector->last_selected, &selector->next_select,
sizeof(select_sets_t));
selector_sets_init(&selector->next_select);
return select(selector->last_selected.max,
&selector->last_selected.reads,
&selector->last_selected.sends,
&selector->last_selected.excepts, NULL);
}
static int selector_get_listener(tunala_selector_t * selector, int fd,
int *newfd)
{
if (FD_ISSET(fd, &selector->last_selected.excepts))
return -1;
if (!FD_ISSET(fd, &selector->last_selected.reads))
return 0;
if ((*newfd = ip_accept_connection(fd)) == -1)
return -1;
return 1;
}
static int tunala_world_make_room(tunala_world_t * world)
{
unsigned int newsize;
tunala_item_t *newarray;
if (world->tunnels_used < world->tunnels_size)
return 1;
newsize = (world->tunnels_size == 0 ? 16 :
((world->tunnels_size * 3) / 2));
if ((newarray = malloc(newsize * sizeof(tunala_item_t))) == NULL)
return 0;
memset(newarray, 0, newsize * sizeof(tunala_item_t));
if (world->tunnels_used > 0)
memcpy(newarray, world->tunnels,
world->tunnels_used * sizeof(tunala_item_t));
if (world->tunnels_size > 0)
free(world->tunnels);
world->tunnels = newarray;
world->tunnels_size = newsize;
return 1;
}
static int tunala_world_new_item(tunala_world_t * world, int fd,
const char *ip, unsigned short port,
int flipped)
{
tunala_item_t *item;
int newfd;
SSL *new_ssl = NULL;
if (!tunala_world_make_room(world))
return 0;
if ((new_ssl = SSL_new(world->ssl_ctx)) == NULL) {
fprintf(stderr, "Error creating new SSL\n");
ERR_print_errors_fp(stderr);
return 0;
}
item = world->tunnels + (world->tunnels_used++);
state_machine_init(&item->sm);
item->clean_read = item->clean_send =
item->dirty_read = item->dirty_send = -1;
if ((newfd = ip_create_connection_split(ip, port)) == -1)
goto err;
if ((world->server_mode && !flipped) || (!world->server_mode && flipped)) {
item->dirty_read = item->dirty_send = fd;
item->clean_read = item->clean_send = newfd;
} else {
item->clean_read = item->clean_send = fd;
item->dirty_read = item->dirty_send = newfd;
}
SSL_set_app_data(new_ssl, NULL);
if (!state_machine_set_SSL(&item->sm, new_ssl, world->server_mode))
goto err;
return 1;
err:
tunala_world_del_item(world, world->tunnels_used - 1);
return 0;
}
static void tunala_world_del_item(tunala_world_t * world, unsigned int idx)
{
tunala_item_t *item = world->tunnels + idx;
if (item->clean_read != -1)
close(item->clean_read);
if (item->clean_send != item->clean_read)
close(item->clean_send);
item->clean_read = item->clean_send = -1;
if (item->dirty_read != -1)
close(item->dirty_read);
if (item->dirty_send != item->dirty_read)
close(item->dirty_send);
item->dirty_read = item->dirty_send = -1;
state_machine_close(&item->sm);
if (idx + 1 < world->tunnels_used)
memmove(world->tunnels + idx,
world->tunnels + (idx + 1),
(world->tunnels_used - (idx + 1)) * sizeof(tunala_item_t));
world->tunnels_used--;
}
static int tunala_item_io(tunala_selector_t * selector, tunala_item_t * item)
{
int c_r, c_s, d_r, d_s;
if ((item->clean_read != -1) && FD_ISSET(item->clean_read,
&selector->
last_selected.excepts))
return 0;
if ((item->clean_send != -1) && FD_ISSET(item->clean_send,
&selector->
last_selected.excepts))
return 0;
if ((item->dirty_read != -1) && FD_ISSET(item->dirty_read,
&selector->
last_selected.excepts))
return 0;
if ((item->dirty_send != -1) && FD_ISSET(item->dirty_send,
&selector->
last_selected.excepts))
return 0;
c_r = c_s = d_r = d_s = 0;
if (item->clean_read != -1)
c_r = FD_ISSET(item->clean_read, &selector->last_selected.reads);
if (item->clean_send != -1)
c_s = FD_ISSET(item->clean_send, &selector->last_selected.sends);
if (item->dirty_read != -1)
d_r = FD_ISSET(item->dirty_read, &selector->last_selected.reads);
if (item->dirty_send != -1)
d_s = FD_ISSET(item->dirty_send, &selector->last_selected.sends);
if (!c_r && !c_s && !d_r && !d_s)
return 1;
if (c_r)
c_r = (buffer_from_fd(state_machine_get_buffer(&item->sm,
SM_CLEAN_IN),
item->clean_read) <= 0);
if (c_s)
c_s = (buffer_to_fd(state_machine_get_buffer(&item->sm,
SM_CLEAN_OUT),
item->clean_send) <= 0);
if (d_r)
d_r = (buffer_from_fd(state_machine_get_buffer(&item->sm,
SM_DIRTY_IN),
item->dirty_read) <= 0);
if (d_s)
d_s = (buffer_to_fd(state_machine_get_buffer(&item->sm,
SM_DIRTY_OUT),
item->dirty_send) <= 0);
if (c_r) {
close(item->clean_read);
if (item->clean_send == item->clean_read)
item->clean_send = -1;
item->clean_read = -1;
}
if (c_s && (item->clean_send != -1)) {
close(item->clean_send);
if (item->clean_send == item->clean_read)
item->clean_read = -1;
item->clean_send = -1;
}
if (d_r) {
close(item->dirty_read);
if (item->dirty_send == item->dirty_read)
item->dirty_send = -1;
item->dirty_read = -1;
}
if (d_s && (item->dirty_send != -1)) {
close(item->dirty_send);
if (item->dirty_send == item->dirty_read)
item->dirty_read = -1;
item->dirty_send = -1;
}
if (!state_machine_churn(&item->sm))
return 0;
if (((item->clean_read == -1) || (item->clean_send == -1)) &&
((item->dirty_read == -1) || (item->dirty_send == -1)))
return 0;
if ((item->clean_read == -1) || (item->clean_send == -1)) {
if (!state_machine_close_clean(&item->sm))
return 0;
}
if ((item->dirty_read == -1) || (item->dirty_send == -1)) {
if (!state_machine_close_dirty(&item->sm))
return 0;
}
return 1;
}
