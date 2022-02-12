int zlib_inflate_workspacesize(void)
{
return sizeof(struct inflate_workspace);
}
int zlib_inflateReset(z_streamp strm)
{
struct inflate_state *state;
if (strm == NULL || strm->state == NULL) return Z_STREAM_ERROR;
state = (struct inflate_state *)strm->state;
strm->total_in = strm->total_out = state->total = 0;
strm->msg = NULL;
strm->adler = 1;
state->mode = HEAD;
state->last = 0;
state->havedict = 0;
state->dmax = 32768U;
state->hold = 0;
state->bits = 0;
state->lencode = state->distcode = state->next = state->codes;
state->wsize = 1U << state->wbits;
state->write = 0;
state->whave = 0;
return Z_OK;
}
int zlib_inflateInit2(z_streamp strm, int windowBits)
{
struct inflate_state *state;
if (strm == NULL) return Z_STREAM_ERROR;
strm->msg = NULL;
state = &WS(strm)->inflate_state;
strm->state = (struct internal_state *)state;
if (windowBits < 0) {
state->wrap = 0;
windowBits = -windowBits;
}
else {
state->wrap = (windowBits >> 4) + 1;
}
if (windowBits < 8 || windowBits > 15) {
return Z_STREAM_ERROR;
}
state->wbits = (unsigned)windowBits;
state->window = &WS(strm)->working_window[0];
return zlib_inflateReset(strm);
}
static void zlib_fixedtables(struct inflate_state *state)
{
# include "inffixed.h"
state->lencode = lenfix;
state->lenbits = 9;
state->distcode = distfix;
state->distbits = 5;
}
static void zlib_updatewindow(z_streamp strm, unsigned out)
{
struct inflate_state *state;
unsigned copy, dist;
state = (struct inflate_state *)strm->state;
copy = out - strm->avail_out;
if (copy >= state->wsize) {
memcpy(state->window, strm->next_out - state->wsize, state->wsize);
state->write = 0;
state->whave = state->wsize;
}
else {
dist = state->wsize - state->write;
if (dist > copy) dist = copy;
memcpy(state->window + state->write, strm->next_out - copy, dist);
copy -= dist;
if (copy) {
memcpy(state->window, strm->next_out - copy, copy);
state->write = copy;
state->whave = state->wsize;
}
else {
state->write += dist;
if (state->write == state->wsize) state->write = 0;
if (state->whave < state->wsize) state->whave += dist;
}
}
}
static int zlib_inflateSyncPacket(z_streamp strm)
{
struct inflate_state *state;
if (strm == NULL || strm->state == NULL) return Z_STREAM_ERROR;
state = (struct inflate_state *)strm->state;
if (state->mode == STORED && state->bits == 0) {
state->mode = TYPE;
return Z_OK;
}
return Z_DATA_ERROR;
}
int zlib_inflate(z_streamp strm, int flush)
{
struct inflate_state *state;
const unsigned char *next;
unsigned char *put;
unsigned have, left;
unsigned long hold;
unsigned bits;
unsigned in, out;
unsigned copy;
unsigned char *from;
code this;
code last;
unsigned len;
int ret;
static const unsigned short order[19] =
{16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
if (strm == NULL || strm->state == NULL ||
(strm->next_in == NULL && strm->avail_in != 0))
return Z_STREAM_ERROR;
state = (struct inflate_state *)strm->state;
if (state->mode == TYPE) state->mode = TYPEDO;
LOAD();
in = have;
out = left;
ret = Z_OK;
for (;;)
switch (state->mode) {
case HEAD:
if (state->wrap == 0) {
state->mode = TYPEDO;
break;
}
NEEDBITS(16);
if (
((BITS(8) << 8) + (hold >> 8)) % 31) {
strm->msg = (char *)"incorrect header check";
state->mode = BAD;
break;
}
if (BITS(4) != Z_DEFLATED) {
strm->msg = (char *)"unknown compression method";
state->mode = BAD;
break;
}
DROPBITS(4);
len = BITS(4) + 8;
if (len > state->wbits) {
strm->msg = (char *)"invalid window size";
state->mode = BAD;
break;
}
state->dmax = 1U << len;
strm->adler = state->check = zlib_adler32(0L, NULL, 0);
state->mode = hold & 0x200 ? DICTID : TYPE;
INITBITS();
break;
case DICTID:
NEEDBITS(32);
strm->adler = state->check = REVERSE(hold);
INITBITS();
state->mode = DICT;
case DICT:
if (state->havedict == 0) {
RESTORE();
return Z_NEED_DICT;
}
strm->adler = state->check = zlib_adler32(0L, NULL, 0);
state->mode = TYPE;
case TYPE:
if (flush == Z_BLOCK) goto inf_leave;
case TYPEDO:
if (state->last) {
BYTEBITS();
state->mode = CHECK;
break;
}
NEEDBITS(3);
state->last = BITS(1);
DROPBITS(1);
switch (BITS(2)) {
case 0:
state->mode = STORED;
break;
case 1:
zlib_fixedtables(state);
state->mode = LEN;
break;
case 2:
state->mode = TABLE;
break;
case 3:
strm->msg = (char *)"invalid block type";
state->mode = BAD;
}
DROPBITS(2);
break;
case STORED:
BYTEBITS();
NEEDBITS(32);
if ((hold & 0xffff) != ((hold >> 16) ^ 0xffff)) {
strm->msg = (char *)"invalid stored block lengths";
state->mode = BAD;
break;
}
state->length = (unsigned)hold & 0xffff;
INITBITS();
state->mode = COPY;
case COPY:
copy = state->length;
if (copy) {
if (copy > have) copy = have;
if (copy > left) copy = left;
if (copy == 0) goto inf_leave;
memcpy(put, next, copy);
have -= copy;
next += copy;
left -= copy;
put += copy;
state->length -= copy;
break;
}
state->mode = TYPE;
break;
case TABLE:
NEEDBITS(14);
state->nlen = BITS(5) + 257;
DROPBITS(5);
state->ndist = BITS(5) + 1;
DROPBITS(5);
state->ncode = BITS(4) + 4;
DROPBITS(4);
#ifndef PKZIP_BUG_WORKAROUND
if (state->nlen > 286 || state->ndist > 30) {
strm->msg = (char *)"too many length or distance symbols";
state->mode = BAD;
break;
}
#endif
state->have = 0;
state->mode = LENLENS;
case LENLENS:
while (state->have < state->ncode) {
NEEDBITS(3);
state->lens[order[state->have++]] = (unsigned short)BITS(3);
DROPBITS(3);
}
while (state->have < 19)
state->lens[order[state->have++]] = 0;
state->next = state->codes;
state->lencode = (code const *)(state->next);
state->lenbits = 7;
ret = zlib_inflate_table(CODES, state->lens, 19, &(state->next),
&(state->lenbits), state->work);
if (ret) {
strm->msg = (char *)"invalid code lengths set";
state->mode = BAD;
break;
}
state->have = 0;
state->mode = CODELENS;
case CODELENS:
while (state->have < state->nlen + state->ndist) {
for (;;) {
this = state->lencode[BITS(state->lenbits)];
if ((unsigned)(this.bits) <= bits) break;
PULLBYTE();
}
if (this.val < 16) {
NEEDBITS(this.bits);
DROPBITS(this.bits);
state->lens[state->have++] = this.val;
}
else {
if (this.val == 16) {
NEEDBITS(this.bits + 2);
DROPBITS(this.bits);
if (state->have == 0) {
strm->msg = (char *)"invalid bit length repeat";
state->mode = BAD;
break;
}
len = state->lens[state->have - 1];
copy = 3 + BITS(2);
DROPBITS(2);
}
else if (this.val == 17) {
NEEDBITS(this.bits + 3);
DROPBITS(this.bits);
len = 0;
copy = 3 + BITS(3);
DROPBITS(3);
}
else {
NEEDBITS(this.bits + 7);
DROPBITS(this.bits);
len = 0;
copy = 11 + BITS(7);
DROPBITS(7);
}
if (state->have + copy > state->nlen + state->ndist) {
strm->msg = (char *)"invalid bit length repeat";
state->mode = BAD;
break;
}
while (copy--)
state->lens[state->have++] = (unsigned short)len;
}
}
if (state->mode == BAD) break;
state->next = state->codes;
state->lencode = (code const *)(state->next);
state->lenbits = 9;
ret = zlib_inflate_table(LENS, state->lens, state->nlen, &(state->next),
&(state->lenbits), state->work);
if (ret) {
strm->msg = (char *)"invalid literal/lengths set";
state->mode = BAD;
break;
}
state->distcode = (code const *)(state->next);
state->distbits = 6;
ret = zlib_inflate_table(DISTS, state->lens + state->nlen, state->ndist,
&(state->next), &(state->distbits), state->work);
if (ret) {
strm->msg = (char *)"invalid distances set";
state->mode = BAD;
break;
}
state->mode = LEN;
case LEN:
if (have >= 6 && left >= 258) {
RESTORE();
inflate_fast(strm, out);
LOAD();
break;
}
for (;;) {
this = state->lencode[BITS(state->lenbits)];
if ((unsigned)(this.bits) <= bits) break;
PULLBYTE();
}
if (this.op && (this.op & 0xf0) == 0) {
last = this;
for (;;) {
this = state->lencode[last.val +
(BITS(last.bits + last.op) >> last.bits)];
if ((unsigned)(last.bits + this.bits) <= bits) break;
PULLBYTE();
}
DROPBITS(last.bits);
}
DROPBITS(this.bits);
state->length = (unsigned)this.val;
if ((int)(this.op) == 0) {
state->mode = LIT;
break;
}
if (this.op & 32) {
state->mode = TYPE;
break;
}
if (this.op & 64) {
strm->msg = (char *)"invalid literal/length code";
state->mode = BAD;
break;
}
state->extra = (unsigned)(this.op) & 15;
state->mode = LENEXT;
case LENEXT:
if (state->extra) {
NEEDBITS(state->extra);
state->length += BITS(state->extra);
DROPBITS(state->extra);
}
state->mode = DIST;
case DIST:
for (;;) {
this = state->distcode[BITS(state->distbits)];
if ((unsigned)(this.bits) <= bits) break;
PULLBYTE();
}
if ((this.op & 0xf0) == 0) {
last = this;
for (;;) {
this = state->distcode[last.val +
(BITS(last.bits + last.op) >> last.bits)];
if ((unsigned)(last.bits + this.bits) <= bits) break;
PULLBYTE();
}
DROPBITS(last.bits);
}
DROPBITS(this.bits);
if (this.op & 64) {
strm->msg = (char *)"invalid distance code";
state->mode = BAD;
break;
}
state->offset = (unsigned)this.val;
state->extra = (unsigned)(this.op) & 15;
state->mode = DISTEXT;
case DISTEXT:
if (state->extra) {
NEEDBITS(state->extra);
state->offset += BITS(state->extra);
DROPBITS(state->extra);
}
#ifdef INFLATE_STRICT
if (state->offset > state->dmax) {
strm->msg = (char *)"invalid distance too far back";
state->mode = BAD;
break;
}
#endif
if (state->offset > state->whave + out - left) {
strm->msg = (char *)"invalid distance too far back";
state->mode = BAD;
break;
}
state->mode = MATCH;
case MATCH:
if (left == 0) goto inf_leave;
copy = out - left;
if (state->offset > copy) {
copy = state->offset - copy;
if (copy > state->write) {
copy -= state->write;
from = state->window + (state->wsize - copy);
}
else
from = state->window + (state->write - copy);
if (copy > state->length) copy = state->length;
}
else {
from = put - state->offset;
copy = state->length;
}
if (copy > left) copy = left;
left -= copy;
state->length -= copy;
do {
*put++ = *from++;
} while (--copy);
if (state->length == 0) state->mode = LEN;
break;
case LIT:
if (left == 0) goto inf_leave;
*put++ = (unsigned char)(state->length);
left--;
state->mode = LEN;
break;
case CHECK:
if (state->wrap) {
NEEDBITS(32);
out -= left;
strm->total_out += out;
state->total += out;
if (out)
strm->adler = state->check =
UPDATE(state->check, put - out, out);
out = left;
if ((
REVERSE(hold)) != state->check) {
strm->msg = (char *)"incorrect data check";
state->mode = BAD;
break;
}
INITBITS();
}
state->mode = DONE;
case DONE:
ret = Z_STREAM_END;
goto inf_leave;
case BAD:
ret = Z_DATA_ERROR;
goto inf_leave;
case MEM:
return Z_MEM_ERROR;
case SYNC:
default:
return Z_STREAM_ERROR;
}
inf_leave:
RESTORE();
if (state->wsize || (state->mode < CHECK && out != strm->avail_out))
zlib_updatewindow(strm, out);
in -= strm->avail_in;
out -= strm->avail_out;
strm->total_in += in;
strm->total_out += out;
state->total += out;
if (state->wrap && out)
strm->adler = state->check =
UPDATE(state->check, strm->next_out - out, out);
strm->data_type = state->bits + (state->last ? 64 : 0) +
(state->mode == TYPE ? 128 : 0);
if (flush == Z_PACKET_FLUSH && ret == Z_OK &&
strm->avail_out != 0 && strm->avail_in == 0)
return zlib_inflateSyncPacket(strm);
if (((in == 0 && out == 0) || flush == Z_FINISH) && ret == Z_OK)
ret = Z_BUF_ERROR;
return ret;
}
int zlib_inflateEnd(z_streamp strm)
{
if (strm == NULL || strm->state == NULL)
return Z_STREAM_ERROR;
return Z_OK;
}
int zlib_inflateIncomp(z_stream *z)
{
struct inflate_state *state = (struct inflate_state *)z->state;
Byte *saved_no = z->next_out;
uInt saved_ao = z->avail_out;
if (state->mode != TYPE && state->mode != HEAD)
return Z_DATA_ERROR;
z->avail_out = 0;
z->next_out = (unsigned char*)z->next_in + z->avail_in;
zlib_updatewindow(z, z->avail_in);
z->avail_out = saved_ao;
z->next_out = saved_no;
z->adler = state->check =
UPDATE(state->check, z->next_in, z->avail_in);
z->total_out += z->avail_in;
z->total_in += z->avail_in;
z->next_in += z->avail_in;
state->total += z->avail_in;
z->avail_in = 0;
return Z_OK;
}
