void gigaset_isowbuf_init(struct isowbuf_t *iwb, unsigned char idle)
{
iwb->read = 0;
iwb->nextread = 0;
iwb->write = 0;
atomic_set(&iwb->writesem, 1);
iwb->wbits = 0;
iwb->idle = idle;
memset(iwb->data + BAS_OUTBUFSIZE, idle, BAS_OUTBUFPAD);
}
static inline int isowbuf_freebytes(struct isowbuf_t *iwb)
{
int read, write, freebytes;
read = iwb->read;
write = iwb->write;
freebytes = read - write;
if (freebytes > 0) {
return freebytes - BAS_OUTBUFPAD;
} else if (read < BAS_OUTBUFPAD) {
return BAS_OUTBUFSIZE - write;
} else {
return freebytes + BAS_OUTBUFSIZE - BAS_OUTBUFPAD;
}
}
static inline int isowbuf_startwrite(struct isowbuf_t *iwb)
{
if (!atomic_dec_and_test(&iwb->writesem)) {
atomic_inc(&iwb->writesem);
gig_dbg(DEBUG_ISO, "%s: couldn't acquire iso write semaphore",
__func__);
return -EBUSY;
}
gig_dbg(DEBUG_ISO,
"%s: acquired iso write semaphore, data[write]=%02x, nbits=%d",
__func__, iwb->data[iwb->write], iwb->wbits);
return 0;
}
static inline int isowbuf_donewrite(struct isowbuf_t *iwb)
{
int write = iwb->write;
atomic_inc(&iwb->writesem);
return write;
}
static inline void isowbuf_putbits(struct isowbuf_t *iwb, u32 data, int nbits)
{
int write = iwb->write;
data <<= iwb->wbits;
data |= iwb->data[write];
nbits += iwb->wbits;
while (nbits >= 8) {
iwb->data[write++] = data & 0xff;
write %= BAS_OUTBUFSIZE;
data >>= 8;
nbits -= 8;
}
iwb->wbits = nbits;
iwb->data[write] = data & 0xff;
iwb->write = write;
}
static inline void isowbuf_putflag(struct isowbuf_t *iwb)
{
int write;
isowbuf_putbits(iwb, 0x7e7e, 8);
write = iwb->write;
iwb->idle = iwb->data[write];
gig_dbg(DEBUG_ISO, "idle fill byte %02x", iwb->idle);
iwb->data[write] &= (1 << iwb->wbits) - 1;
}
int gigaset_isowbuf_getbytes(struct isowbuf_t *iwb, int size)
{
int read, write, limit, src, dst;
unsigned char pbyte;
read = iwb->nextread;
write = iwb->write;
if (likely(read == write)) {
return read < BAS_OUTBUFPAD ?
BAS_OUTBUFSIZE : read - BAS_OUTBUFPAD;
}
limit = read + size;
gig_dbg(DEBUG_STREAM, "%s: read=%d write=%d limit=%d",
__func__, read, write, limit);
#ifdef CONFIG_GIGASET_DEBUG
if (unlikely(size < 0 || size > BAS_OUTBUFPAD)) {
pr_err("invalid size %d\n", size);
return -EINVAL;
}
#endif
if (read < write) {
if (limit >= write) {
if (isowbuf_startwrite(iwb) < 0)
return -EBUSY;
write = iwb->write;
if (limit >= write) {
pbyte = iwb->data[write];
limit = write + BAS_OUTBUFPAD;
gig_dbg(DEBUG_STREAM,
"%s: filling %d->%d with %02x",
__func__, write, limit, iwb->idle);
if (write + BAS_OUTBUFPAD < BAS_OUTBUFSIZE)
memset(iwb->data + write, iwb->idle,
BAS_OUTBUFPAD);
else {
memset(iwb->data + write, iwb->idle,
BAS_OUTBUFSIZE + BAS_OUTBUFPAD
- write);
limit = 0;
}
gig_dbg(DEBUG_STREAM,
"%s: restoring %02x at %d",
__func__, pbyte, limit);
iwb->data[limit] = pbyte;
iwb->write = limit;
}
isowbuf_donewrite(iwb);
}
} else {
if (limit >= BAS_OUTBUFSIZE) {
src = 0;
dst = BAS_OUTBUFSIZE;
while (dst < limit && src < write)
iwb->data[dst++] = iwb->data[src++];
if (dst <= limit) {
memset(iwb->data + dst, iwb->idle,
BAS_OUTBUFSIZE + BAS_OUTBUFPAD - dst);
}
limit = src;
}
}
iwb->nextread = limit;
return read;
}
static inline void dump_bytes(enum debuglevel level, const char *tag,
unsigned char *bytes, int count)
{
#ifdef CONFIG_GIGASET_DEBUG
unsigned char c;
static char dbgline[3 * 32 + 1];
int i = 0;
if (!(gigaset_debuglevel & level))
return;
while (count-- > 0) {
if (i > sizeof(dbgline) - 4) {
dbgline[i] = '\0';
gig_dbg(level, "%s:%s", tag, dbgline);
i = 0;
}
c = *bytes++;
dbgline[i] = (i && !(i % 12)) ? '-' : ' ';
i++;
dbgline[i++] = hex_asc_hi(c);
dbgline[i++] = hex_asc_lo(c);
}
dbgline[i] = '\0';
gig_dbg(level, "%s:%s", tag, dbgline);
#endif
}
static inline int hdlc_bitstuff_byte(struct isowbuf_t *iwb, unsigned char cin,
int ones)
{
u16 stuff;
int shiftinc, newones;
stuff = stufftab[256 * ones + cin];
shiftinc = (stuff >> 13) & 3;
newones = (stuff >> 10) & 7;
stuff &= 0x3ff;
isowbuf_putbits(iwb, stuff, 8 + shiftinc);
return newones;
}
static inline int hdlc_buildframe(struct isowbuf_t *iwb,
unsigned char *in, int count)
{
int ones;
u16 fcs;
int end;
unsigned char c;
if (isowbuf_freebytes(iwb) < count + count / 5 + 6 ||
isowbuf_startwrite(iwb) < 0) {
gig_dbg(DEBUG_ISO, "%s: %d bytes free -> -EAGAIN",
__func__, isowbuf_freebytes(iwb));
return -EAGAIN;
}
dump_bytes(DEBUG_STREAM_DUMP, "snd data", in, count);
fcs = PPP_INITFCS;
ones = 0;
while (count-- > 0) {
c = *in++;
ones = hdlc_bitstuff_byte(iwb, c, ones);
fcs = crc_ccitt_byte(fcs, c);
}
fcs ^= 0xffff;
ones = hdlc_bitstuff_byte(iwb, fcs & 0x00ff, ones);
ones = hdlc_bitstuff_byte(iwb, (fcs >> 8) & 0x00ff, ones);
isowbuf_putflag(iwb);
end = isowbuf_donewrite(iwb);
return end;
}
static inline int trans_buildframe(struct isowbuf_t *iwb,
unsigned char *in, int count)
{
int write;
unsigned char c;
if (unlikely(count <= 0))
return iwb->write;
if (isowbuf_freebytes(iwb) < count ||
isowbuf_startwrite(iwb) < 0) {
gig_dbg(DEBUG_ISO, "can't put %d bytes", count);
return -EAGAIN;
}
gig_dbg(DEBUG_STREAM, "put %d bytes", count);
dump_bytes(DEBUG_STREAM_DUMP, "snd data", in, count);
write = iwb->write;
do {
c = bitrev8(*in++);
iwb->data[write++] = c;
write %= BAS_OUTBUFSIZE;
} while (--count > 0);
iwb->write = write;
iwb->idle = c;
return isowbuf_donewrite(iwb);
}
int gigaset_isoc_buildframe(struct bc_state *bcs, unsigned char *in, int len)
{
int result;
switch (bcs->proto2) {
case L2_HDLC:
result = hdlc_buildframe(bcs->hw.bas->isooutbuf, in, len);
gig_dbg(DEBUG_ISO, "%s: %d bytes HDLC -> %d",
__func__, len, result);
break;
default:
result = trans_buildframe(bcs->hw.bas->isooutbuf, in, len);
gig_dbg(DEBUG_ISO, "%s: %d bytes trans -> %d",
__func__, len, result);
}
return result;
}
static inline void hdlc_putbyte(unsigned char c, struct bc_state *bcs)
{
bcs->rx_fcs = crc_ccitt_byte(bcs->rx_fcs, c);
if (bcs->rx_skb == NULL)
return;
if (bcs->rx_skb->len >= bcs->rx_bufsize) {
dev_warn(bcs->cs->dev, "received oversized packet discarded\n");
bcs->hw.bas->giants++;
dev_kfree_skb_any(bcs->rx_skb);
bcs->rx_skb = NULL;
return;
}
__skb_put_u8(bcs->rx_skb, c);
}
static inline void hdlc_flush(struct bc_state *bcs)
{
if (bcs->rx_skb != NULL)
skb_trim(bcs->rx_skb, 0);
else
gigaset_new_rx_skb(bcs);
bcs->rx_fcs = PPP_INITFCS;
}
static inline void hdlc_done(struct bc_state *bcs)
{
struct cardstate *cs = bcs->cs;
struct sk_buff *procskb;
unsigned int len;
if (unlikely(bcs->ignore)) {
bcs->ignore--;
hdlc_flush(bcs);
return;
}
procskb = bcs->rx_skb;
if (procskb == NULL) {
gig_dbg(DEBUG_ISO, "%s: skb=NULL", __func__);
gigaset_isdn_rcv_err(bcs);
} else if (procskb->len < 2) {
dev_notice(cs->dev, "received short frame (%d octets)\n",
procskb->len);
bcs->hw.bas->runts++;
dev_kfree_skb_any(procskb);
gigaset_isdn_rcv_err(bcs);
} else if (bcs->rx_fcs != PPP_GOODFCS) {
dev_notice(cs->dev, "frame check error\n");
bcs->hw.bas->fcserrs++;
dev_kfree_skb_any(procskb);
gigaset_isdn_rcv_err(bcs);
} else {
len = procskb->len;
__skb_trim(procskb, len -= 2);
gig_dbg(DEBUG_ISO, "%s: good frame (%d octets)", __func__, len);
dump_bytes(DEBUG_STREAM_DUMP,
"rcv data", procskb->data, len);
bcs->hw.bas->goodbytes += len;
gigaset_skb_rcvd(bcs, procskb);
}
gigaset_new_rx_skb(bcs);
bcs->rx_fcs = PPP_INITFCS;
}
static inline void hdlc_frag(struct bc_state *bcs, unsigned inbits)
{
if (unlikely(bcs->ignore)) {
bcs->ignore--;
hdlc_flush(bcs);
return;
}
dev_notice(bcs->cs->dev, "received partial byte (%d bits)\n", inbits);
bcs->hw.bas->alignerrs++;
gigaset_isdn_rcv_err(bcs);
__skb_trim(bcs->rx_skb, 0);
bcs->rx_fcs = PPP_INITFCS;
}
static inline void hdlc_unpack(unsigned char *src, unsigned count,
struct bc_state *bcs)
{
struct bas_bc_state *ubc = bcs->hw.bas;
int inputstate;
unsigned seqlen, inbyte, inbits;
inputstate = bcs->inputstate;
seqlen = ubc->seqlen;
inbyte = ubc->inbyte;
inbits = ubc->inbits;
while (count--) {
unsigned char c = *src++;
unsigned char tabentry = bitcounts[c];
unsigned lead1 = tabentry & 0x0f;
unsigned trail1 = (tabentry >> 4) & 0x0f;
seqlen += lead1;
if (unlikely(inputstate & INS_flag_hunt)) {
if (c == PPP_FLAG) {
inputstate &= ~(INS_flag_hunt | INS_have_data);
inbyte = 0;
inbits = 0;
} else if (seqlen == 6 && trail1 != 7) {
inputstate &= ~(INS_flag_hunt | INS_have_data);
inbyte = c >> (lead1 + 1);
inbits = 7 - lead1;
if (trail1 >= 8) {
inbits--;
switch (c) {
case 0xbe:
inbyte = 0x3f;
break;
}
}
}
} else if (likely(seqlen < 5 && trail1 < 7)) {
inbyte |= c << inbits;
hdlc_putbyte(inbyte & 0xff, bcs);
inputstate |= INS_have_data;
inbyte >>= 8;
} else if (likely(seqlen == 6 && inbits == 7 - lead1 &&
trail1 + 1 == inbits &&
!(inputstate & INS_have_data))) {
} else if (unlikely(seqlen > 6)) {
ubc->aborts++;
hdlc_flush(bcs);
inputstate |= INS_flag_hunt;
} else if (seqlen == 6) {
if (inbits > 7 - lead1) {
hdlc_frag(bcs, inbits + lead1 - 7);
inputstate &= ~INS_have_data;
} else {
if (inbits < 7 - lead1)
ubc->stolen0s++;
if (inputstate & INS_have_data) {
hdlc_done(bcs);
inputstate &= ~INS_have_data;
}
}
if (c == PPP_FLAG) {
ubc->shared0s++;
inbits = 0;
inbyte = 0;
} else if (trail1 != 7) {
inbyte = c >> (lead1 + 1);
inbits = 7 - lead1;
if (trail1 >= 8) {
inbits--;
switch (c) {
case 0xbe:
inbyte = 0x3f;
break;
}
}
} else {
ubc->aborts++;
inputstate |= INS_flag_hunt;
}
} else {
if (c == PPP_FLAG) {
if (seqlen == 5)
ubc->stolen0s++;
if (inbits) {
hdlc_frag(bcs, inbits);
inbits = 0;
inbyte = 0;
} else if (inputstate & INS_have_data)
hdlc_done(bcs);
inputstate &= ~INS_have_data;
} else if (trail1 == 7) {
ubc->aborts++;
hdlc_flush(bcs);
inputstate |= INS_flag_hunt;
} else {
if (trail1 < 7) {
unsigned char mask = (1 << lead1) - 1;
c = (c & mask) | ((c & ~mask) >> 1);
inbyte |= c << inbits;
inbits += 7;
} else if (seqlen < 5) {
switch (c) {
case 0xbe:
c = 0x7e;
break;
}
inbyte |= c << inbits;
inbits += 7;
} else {
switch (c) {
case 0x7d:
c = 0x3f;
break;
case 0xbe:
c = 0x3f;
break;
case 0x3e:
c = 0x1f;
break;
case 0x7c:
c = 0x3e;
break;
}
inbyte |= c << inbits;
inbits += 6;
}
if (inbits >= 8) {
inbits -= 8;
hdlc_putbyte(inbyte & 0xff, bcs);
inputstate |= INS_have_data;
inbyte >>= 8;
}
}
}
seqlen = trail1 & 7;
}
bcs->inputstate = inputstate;
ubc->seqlen = seqlen;
ubc->inbyte = inbyte;
ubc->inbits = inbits;
}
static inline void trans_receive(unsigned char *src, unsigned count,
struct bc_state *bcs)
{
struct sk_buff *skb;
int dobytes;
unsigned char *dst;
if (unlikely(bcs->ignore)) {
bcs->ignore--;
return;
}
skb = bcs->rx_skb;
if (skb == NULL) {
skb = gigaset_new_rx_skb(bcs);
if (skb == NULL)
return;
}
dobytes = bcs->rx_bufsize - skb->len;
while (count > 0) {
dst = skb_put(skb, count < dobytes ? count : dobytes);
while (count > 0 && dobytes > 0) {
*dst++ = bitrev8(*src++);
count--;
dobytes--;
}
if (dobytes == 0) {
dump_bytes(DEBUG_STREAM_DUMP,
"rcv data", skb->data, skb->len);
bcs->hw.bas->goodbytes += skb->len;
gigaset_skb_rcvd(bcs, skb);
skb = gigaset_new_rx_skb(bcs);
if (skb == NULL)
return;
dobytes = bcs->rx_bufsize;
}
}
}
void gigaset_isoc_receive(unsigned char *src, unsigned count,
struct bc_state *bcs)
{
switch (bcs->proto2) {
case L2_HDLC:
hdlc_unpack(src, count, bcs);
break;
default:
trans_receive(src, count, bcs);
}
}
static void cmd_loop(unsigned char *src, int numbytes, struct inbuf_t *inbuf)
{
struct cardstate *cs = inbuf->cs;
unsigned cbytes = cs->cbytes;
unsigned char c;
while (numbytes--) {
c = *src++;
switch (c) {
case '\n':
if (cbytes == 0 && cs->respdata[0] == '\r') {
cs->respdata[0] = 0;
break;
}
case '\r':
if (cbytes >= MAX_RESP_SIZE) {
dev_warn(cs->dev, "response too large (%d)\n",
cbytes);
cbytes = MAX_RESP_SIZE;
}
cs->cbytes = cbytes;
gigaset_dbg_buffer(DEBUG_TRANSCMD, "received response",
cbytes, cs->respdata);
gigaset_handle_modem_response(cs);
cbytes = 0;
cs->respdata[0] = c;
break;
default:
if (cbytes < MAX_RESP_SIZE)
cs->respdata[cbytes] = c;
cbytes++;
}
}
cs->cbytes = cbytes;
}
void gigaset_isoc_input(struct inbuf_t *inbuf)
{
struct cardstate *cs = inbuf->cs;
unsigned tail, head, numbytes;
unsigned char *src;
head = inbuf->head;
while (head != (tail = inbuf->tail)) {
gig_dbg(DEBUG_INTR, "buffer state: %u -> %u", head, tail);
if (head > tail)
tail = RBUFSIZE;
src = inbuf->data + head;
numbytes = tail - head;
gig_dbg(DEBUG_INTR, "processing %u bytes", numbytes);
if (cs->mstate == MS_LOCKED) {
gigaset_dbg_buffer(DEBUG_LOCKCMD, "received response",
numbytes, src);
gigaset_if_receive(inbuf->cs, src, numbytes);
} else {
cmd_loop(src, numbytes, inbuf);
}
head += numbytes;
if (head == RBUFSIZE)
head = 0;
gig_dbg(DEBUG_INTR, "setting head to %u", head);
inbuf->head = head;
}
}
int gigaset_isoc_send_skb(struct bc_state *bcs, struct sk_buff *skb)
{
int len = skb->len;
unsigned long flags;
spin_lock_irqsave(&bcs->cs->lock, flags);
if (!bcs->cs->connected) {
spin_unlock_irqrestore(&bcs->cs->lock, flags);
return -ENODEV;
}
skb_queue_tail(&bcs->squeue, skb);
gig_dbg(DEBUG_ISO, "%s: skb queued, qlen=%d",
__func__, skb_queue_len(&bcs->squeue));
tasklet_schedule(&bcs->hw.bas->sent_tasklet);
spin_unlock_irqrestore(&bcs->cs->lock, flags);
return len;
}
