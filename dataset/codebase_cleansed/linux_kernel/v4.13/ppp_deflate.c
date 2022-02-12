static void z_comp_free(void *arg)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
if (state) {
zlib_deflateEnd(&state->strm);
vfree(state->strm.workspace);
kfree(state);
}
}
static void *z_comp_alloc(unsigned char *options, int opt_len)
{
struct ppp_deflate_state *state;
int w_size;
if (opt_len != CILEN_DEFLATE ||
(options[0] != CI_DEFLATE && options[0] != CI_DEFLATE_DRAFT) ||
options[1] != CILEN_DEFLATE ||
DEFLATE_METHOD(options[2]) != DEFLATE_METHOD_VAL ||
options[3] != DEFLATE_CHK_SEQUENCE)
return NULL;
w_size = DEFLATE_SIZE(options[2]);
if (w_size < DEFLATE_MIN_SIZE || w_size > DEFLATE_MAX_SIZE)
return NULL;
state = kzalloc(sizeof(*state),
GFP_KERNEL);
if (state == NULL)
return NULL;
state->strm.next_in = NULL;
state->w_size = w_size;
state->strm.workspace = vmalloc(zlib_deflate_workspacesize(-w_size, 8));
if (state->strm.workspace == NULL)
goto out_free;
if (zlib_deflateInit2(&state->strm, Z_DEFAULT_COMPRESSION,
DEFLATE_METHOD_VAL, -w_size, 8, Z_DEFAULT_STRATEGY)
!= Z_OK)
goto out_free;
return (void *) state;
out_free:
z_comp_free(state);
return NULL;
}
static int z_comp_init(void *arg, unsigned char *options, int opt_len,
int unit, int hdrlen, int debug)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
if (opt_len < CILEN_DEFLATE ||
(options[0] != CI_DEFLATE && options[0] != CI_DEFLATE_DRAFT) ||
options[1] != CILEN_DEFLATE ||
DEFLATE_METHOD(options[2]) != DEFLATE_METHOD_VAL ||
DEFLATE_SIZE(options[2]) != state->w_size ||
options[3] != DEFLATE_CHK_SEQUENCE)
return 0;
state->seqno = 0;
state->unit = unit;
state->debug = debug;
zlib_deflateReset(&state->strm);
return 1;
}
static void z_comp_reset(void *arg)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
state->seqno = 0;
zlib_deflateReset(&state->strm);
}
static int z_compress(void *arg, unsigned char *rptr, unsigned char *obuf,
int isize, int osize)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
int r, proto, off, olen, oavail;
unsigned char *wptr;
proto = PPP_PROTOCOL(rptr);
if (proto > 0x3fff || proto == 0xfd || proto == 0xfb)
return 0;
if (osize > isize)
osize = isize;
wptr = obuf;
wptr[0] = PPP_ADDRESS(rptr);
wptr[1] = PPP_CONTROL(rptr);
put_unaligned_be16(PPP_COMP, wptr + 2);
wptr += PPP_HDRLEN;
put_unaligned_be16(state->seqno, wptr);
wptr += DEFLATE_OVHD;
olen = PPP_HDRLEN + DEFLATE_OVHD;
state->strm.next_out = wptr;
state->strm.avail_out = oavail = osize - olen;
++state->seqno;
off = (proto > 0xff) ? 2 : 3;
rptr += off;
state->strm.next_in = rptr;
state->strm.avail_in = (isize - off);
for (;;) {
r = zlib_deflate(&state->strm, Z_PACKET_FLUSH);
if (r != Z_OK) {
if (state->debug)
printk(KERN_ERR
"z_compress: deflate returned %d\n", r);
break;
}
if (state->strm.avail_out == 0) {
olen += oavail;
state->strm.next_out = NULL;
state->strm.avail_out = oavail = 1000000;
} else {
break;
}
}
olen += oavail - state->strm.avail_out;
if (olen < isize && olen <= osize) {
state->stats.comp_bytes += olen;
state->stats.comp_packets++;
} else {
state->stats.inc_bytes += isize;
state->stats.inc_packets++;
olen = 0;
}
state->stats.unc_bytes += isize;
state->stats.unc_packets++;
return olen;
}
static void z_comp_stats(void *arg, struct compstat *stats)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
*stats = state->stats;
}
static void z_decomp_free(void *arg)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
if (state) {
zlib_inflateEnd(&state->strm);
vfree(state->strm.workspace);
kfree(state);
}
}
static void *z_decomp_alloc(unsigned char *options, int opt_len)
{
struct ppp_deflate_state *state;
int w_size;
if (opt_len != CILEN_DEFLATE ||
(options[0] != CI_DEFLATE && options[0] != CI_DEFLATE_DRAFT) ||
options[1] != CILEN_DEFLATE ||
DEFLATE_METHOD(options[2]) != DEFLATE_METHOD_VAL ||
options[3] != DEFLATE_CHK_SEQUENCE)
return NULL;
w_size = DEFLATE_SIZE(options[2]);
if (w_size < DEFLATE_MIN_SIZE || w_size > DEFLATE_MAX_SIZE)
return NULL;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->w_size = w_size;
state->strm.next_out = NULL;
state->strm.workspace = vmalloc(zlib_inflate_workspacesize());
if (state->strm.workspace == NULL)
goto out_free;
if (zlib_inflateInit2(&state->strm, -w_size) != Z_OK)
goto out_free;
return (void *) state;
out_free:
z_decomp_free(state);
return NULL;
}
static int z_decomp_init(void *arg, unsigned char *options, int opt_len,
int unit, int hdrlen, int mru, int debug)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
if (opt_len < CILEN_DEFLATE ||
(options[0] != CI_DEFLATE && options[0] != CI_DEFLATE_DRAFT) ||
options[1] != CILEN_DEFLATE ||
DEFLATE_METHOD(options[2]) != DEFLATE_METHOD_VAL ||
DEFLATE_SIZE(options[2]) != state->w_size ||
options[3] != DEFLATE_CHK_SEQUENCE)
return 0;
state->seqno = 0;
state->unit = unit;
state->debug = debug;
state->mru = mru;
zlib_inflateReset(&state->strm);
return 1;
}
static void z_decomp_reset(void *arg)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
state->seqno = 0;
zlib_inflateReset(&state->strm);
}
static int z_decompress(void *arg, unsigned char *ibuf, int isize,
unsigned char *obuf, int osize)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
int olen, seq, r;
int decode_proto, overflow;
unsigned char overflow_buf[1];
if (isize <= PPP_HDRLEN + DEFLATE_OVHD) {
if (state->debug)
printk(KERN_DEBUG "z_decompress%d: short pkt (%d)\n",
state->unit, isize);
return DECOMP_ERROR;
}
seq = get_unaligned_be16(ibuf + PPP_HDRLEN);
if (seq != (state->seqno & 0xffff)) {
if (state->debug)
printk(KERN_DEBUG "z_decompress%d: bad seq # %d, expected %d\n",
state->unit, seq, state->seqno & 0xffff);
return DECOMP_ERROR;
}
++state->seqno;
obuf[0] = PPP_ADDRESS(ibuf);
obuf[1] = PPP_CONTROL(ibuf);
obuf[2] = 0;
state->strm.next_in = ibuf + PPP_HDRLEN + DEFLATE_OVHD;
state->strm.avail_in = isize - (PPP_HDRLEN + DEFLATE_OVHD);
state->strm.next_out = obuf + 3;
state->strm.avail_out = 1;
decode_proto = 1;
overflow = 0;
for (;;) {
r = zlib_inflate(&state->strm, Z_PACKET_FLUSH);
if (r != Z_OK) {
if (state->debug)
printk(KERN_DEBUG "z_decompress%d: inflate returned %d (%s)\n",
state->unit, r, (state->strm.msg? state->strm.msg: ""));
return DECOMP_FATALERROR;
}
if (state->strm.avail_out != 0)
break;
if (decode_proto) {
state->strm.avail_out = osize - PPP_HDRLEN;
if ((obuf[3] & 1) == 0) {
obuf[2] = obuf[3];
--state->strm.next_out;
++state->strm.avail_out;
}
decode_proto = 0;
} else if (!overflow) {
state->strm.next_out = overflow_buf;
state->strm.avail_out = 1;
overflow = 1;
} else {
if (state->debug)
printk(KERN_DEBUG "z_decompress%d: ran out of mru\n",
state->unit);
return DECOMP_FATALERROR;
}
}
if (decode_proto) {
if (state->debug)
printk(KERN_DEBUG "z_decompress%d: didn't get proto\n",
state->unit);
return DECOMP_ERROR;
}
olen = osize + overflow - state->strm.avail_out;
state->stats.unc_bytes += olen;
state->stats.unc_packets++;
state->stats.comp_bytes += isize;
state->stats.comp_packets++;
return olen;
}
static void z_incomp(void *arg, unsigned char *ibuf, int icnt)
{
struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;
int proto, r;
proto = PPP_PROTOCOL(ibuf);
if (proto > 0x3fff || proto == 0xfd || proto == 0xfb)
return;
++state->seqno;
state->strm.next_in = ibuf + 3;
state->strm.avail_in = icnt - 3;
if (proto > 0xff) {
--state->strm.next_in;
++state->strm.avail_in;
}
r = zlib_inflateIncomp(&state->strm);
if (r != Z_OK) {
if (state->debug) {
printk(KERN_DEBUG "z_incomp%d: inflateIncomp returned %d (%s)\n",
state->unit, r, (state->strm.msg? state->strm.msg: ""));
}
return;
}
state->stats.inc_bytes += icnt;
state->stats.inc_packets++;
state->stats.unc_bytes += icnt;
state->stats.unc_packets++;
}
static int __init deflate_init(void)
{
int answer = ppp_register_compressor(&ppp_deflate);
if (answer == 0)
printk(KERN_INFO
"PPP Deflate Compression module registered\n");
ppp_register_compressor(&ppp_deflate_draft);
return answer;
}
static void __exit deflate_cleanup(void)
{
ppp_unregister_compressor(&ppp_deflate);
ppp_unregister_compressor(&ppp_deflate_draft);
}
