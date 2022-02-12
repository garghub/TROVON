static void zlib_stateful_free_ex_data(void *obj, void *item,
CRYPTO_EX_DATA *ad, int ind,long argl, void *argp)
{
struct zlib_state *state = (struct zlib_state *)item;
inflateEnd(&state->istream);
deflateEnd(&state->ostream);
OPENSSL_free(state);
}
static int zlib_stateful_init(COMP_CTX *ctx)
{
int err;
struct zlib_state *state =
(struct zlib_state *)OPENSSL_malloc(sizeof(struct zlib_state));
if (state == NULL)
goto err;
state->istream.zalloc = Z_NULL;
state->istream.zfree = Z_NULL;
state->istream.opaque = Z_NULL;
state->istream.next_in = Z_NULL;
state->istream.next_out = Z_NULL;
state->istream.avail_in = 0;
state->istream.avail_out = 0;
err = inflateInit_(&state->istream,
ZLIB_VERSION, sizeof(z_stream));
if (err != Z_OK)
goto err;
state->ostream.zalloc = Z_NULL;
state->ostream.zfree = Z_NULL;
state->ostream.opaque = Z_NULL;
state->ostream.next_in = Z_NULL;
state->ostream.next_out = Z_NULL;
state->ostream.avail_in = 0;
state->ostream.avail_out = 0;
err = deflateInit_(&state->ostream,Z_DEFAULT_COMPRESSION,
ZLIB_VERSION, sizeof(z_stream));
if (err != Z_OK)
goto err;
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_COMP,ctx,&ctx->ex_data);
if (zlib_stateful_ex_idx == -1)
{
CRYPTO_w_lock(CRYPTO_LOCK_COMP);
if (zlib_stateful_ex_idx == -1)
zlib_stateful_ex_idx =
CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_COMP,
0,NULL,NULL,NULL,zlib_stateful_free_ex_data);
CRYPTO_w_unlock(CRYPTO_LOCK_COMP);
if (zlib_stateful_ex_idx == -1)
goto err;
}
CRYPTO_set_ex_data(&ctx->ex_data,zlib_stateful_ex_idx,state);
return 1;
err:
if (state) OPENSSL_free(state);
return 0;
}
static void zlib_stateful_finish(COMP_CTX *ctx)
{
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_COMP,ctx,&ctx->ex_data);
}
static int zlib_stateful_compress_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in, unsigned int ilen)
{
int err = Z_OK;
struct zlib_state *state =
(struct zlib_state *)CRYPTO_get_ex_data(&ctx->ex_data,
zlib_stateful_ex_idx);
if (state == NULL)
return -1;
state->ostream.next_in = in;
state->ostream.avail_in = ilen;
state->ostream.next_out = out;
state->ostream.avail_out = olen;
if (ilen > 0)
err = deflate(&state->ostream, Z_SYNC_FLUSH);
if (err != Z_OK)
return -1;
#ifdef DEBUG_ZLIB
fprintf(stderr,"compress(%4d)->%4d %s\n",
ilen,olen - state->ostream.avail_out,
(ilen != olen - state->ostream.avail_out)?"zlib":"clear");
#endif
return olen - state->ostream.avail_out;
}
static int zlib_stateful_expand_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in, unsigned int ilen)
{
int err = Z_OK;
struct zlib_state *state =
(struct zlib_state *)CRYPTO_get_ex_data(&ctx->ex_data,
zlib_stateful_ex_idx);
if (state == NULL)
return 0;
state->istream.next_in = in;
state->istream.avail_in = ilen;
state->istream.next_out = out;
state->istream.avail_out = olen;
if (ilen > 0)
err = inflate(&state->istream, Z_SYNC_FLUSH);
if (err != Z_OK)
return -1;
#ifdef DEBUG_ZLIB
fprintf(stderr,"expand(%4d)->%4d %s\n",
ilen,olen - state->istream.avail_out,
(ilen != olen - state->istream.avail_out)?"zlib":"clear");
#endif
return olen - state->istream.avail_out;
}
COMP_METHOD *COMP_zlib(void)
{
COMP_METHOD *meth = &zlib_method_nozlib;
#ifdef ZLIB_SHARED
if (!zlib_loaded)
{
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)
zlib_dso = DSO_load(NULL, "ZLIB1", NULL, 0);
if (!zlib_dso)
{
zlib_dso = DSO_load(NULL, "ZLIB", NULL, 0);
if (zlib_dso)
{
ERR_clear_error();
}
}
#else
zlib_dso = DSO_load(NULL, "z", NULL, 0);
#endif
if (zlib_dso != NULL)
{
p_compress
= (compress_ft) DSO_bind_func(zlib_dso,
"compress");
p_inflateEnd
= (inflateEnd_ft) DSO_bind_func(zlib_dso,
"inflateEnd");
p_inflate
= (inflate_ft) DSO_bind_func(zlib_dso,
"inflate");
p_inflateInit_
= (inflateInit__ft) DSO_bind_func(zlib_dso,
"inflateInit_");
p_deflateEnd
= (deflateEnd_ft) DSO_bind_func(zlib_dso,
"deflateEnd");
p_deflate
= (deflate_ft) DSO_bind_func(zlib_dso,
"deflate");
p_deflateInit_
= (deflateInit__ft) DSO_bind_func(zlib_dso,
"deflateInit_");
zlib_loaded++;
}
}
#endif
#if defined(ZLIB) || defined(ZLIB_SHARED)
meth = &zlib_stateful_method;
#endif
return(meth);
}
static int
stub_inflateEnd(z_streamp strm)
{
if ( p_inflateEnd )
return(p_inflateEnd(strm));
else
return(Z_MEM_ERROR);
}
static int
stub_inflate(z_streamp strm, int flush)
{
if ( p_inflate )
return(p_inflate(strm,flush));
else
return(Z_MEM_ERROR);
}
static int
stub_inflateInit_(z_streamp strm, const char * version, int stream_size)
{
if ( p_inflateInit_ )
return(p_inflateInit_(strm,version,stream_size));
else
return(Z_MEM_ERROR);
}
static int
stub_deflateEnd(z_streamp strm)
{
if ( p_deflateEnd )
return(p_deflateEnd(strm));
else
return(Z_MEM_ERROR);
}
static int
stub_deflate(z_streamp strm, int flush)
{
if ( p_deflate )
return(p_deflate(strm,flush));
else
return(Z_MEM_ERROR);
}
static int
stub_deflateInit_(z_streamp strm, int level,
const char * version, int stream_size)
{
if ( p_deflateInit_ )
return(p_deflateInit_(strm,level,version,stream_size));
else
return(Z_MEM_ERROR);
}
