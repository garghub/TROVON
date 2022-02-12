static int zlib_compress_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in, unsigned int ilen)
{
unsigned long l;
int i;
int clear=1;
if (ilen > 128)
{
out[0]=1;
l=olen-1;
i=compress(&(out[1]),&l,in,(unsigned long)ilen);
if (i != Z_OK)
return(-1);
if (ilen > l)
{
clear=0;
l++;
}
}
if (clear)
{
out[0]=0;
memcpy(&(out[1]),in,ilen);
l=ilen+1;
}
#ifdef DEBUG_ZLIB
fprintf(stderr,"compress(%4d)->%4d %s\n",
ilen,(int)l,(clear)?"clear":"zlib");
#endif
return((int)l);
}
static int zlib_expand_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in, unsigned int ilen)
{
unsigned long l;
int i;
if (in[0])
{
l=olen;
i=zz_uncompress(out,&l,&(in[1]),(unsigned long)ilen-1);
if (i != Z_OK)
return(-1);
}
else
{
memcpy(out,&(in[1]),ilen-1);
l=ilen-1;
}
#ifdef DEBUG_ZLIB
fprintf(stderr,"expand (%4d)->%4d %s\n",
ilen,(int)l,in[0]?"zlib":"clear");
#endif
return((int)l);
}
static int zz_uncompress (Bytef *dest, uLongf *destLen, const Bytef *source,
uLong sourceLen)
{
z_stream stream;
int err;
stream.next_in = (Bytef*)source;
stream.avail_in = (uInt)sourceLen;
if ((uLong)stream.avail_in != sourceLen) return Z_BUF_ERROR;
stream.next_out = dest;
stream.avail_out = (uInt)*destLen;
if ((uLong)stream.avail_out != *destLen) return Z_BUF_ERROR;
stream.zalloc = (alloc_func)0;
stream.zfree = (free_func)0;
err = inflateInit(&stream);
if (err != Z_OK) return err;
err = inflate(&stream, Z_FINISH);
if (err != Z_STREAM_END) {
inflateEnd(&stream);
return err;
}
*destLen = stream.total_out;
err = inflateEnd(&stream);
return err;
}
COMP_METHOD *COMP_zlib(void)
{
COMP_METHOD *meth = &zlib_method_nozlib;
#ifdef ZLIB_SHARED
if (!zlib_loaded)
{
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)
zlib_dso = DSO_load(NULL, "ZLIB", NULL, 0);
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
zlib_loaded++;
}
}
#endif
#if defined(ZLIB) || defined(ZLIB_SHARED)
meth = &zlib_method;
#endif
return(meth);
}
static int
stub_compress(Bytef *dest,uLongf *destLen,const Bytef *source, uLong sourceLen)
{
if (p_compress)
return(p_compress(dest,destLen,source,sourceLen));
else
return(Z_MEM_ERROR);
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
