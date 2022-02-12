void pio_copy(struct hfi1_devdata *dd, struct pio_buf *pbuf, u64 pbc,
const void *from, size_t count)
{
void __iomem *dest = pbuf->start + SOP_DISTANCE;
void __iomem *send = dest + PIO_BLOCK_SIZE;
void __iomem *dend;
writeq(pbc, dest);
dest += sizeof(u64);
dend = dest + ((count >> 1) * sizeof(u64));
if (dend < send) {
while (dest < dend) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
} else {
while (dest < send) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= SOP_DISTANCE;
dend -= SOP_DISTANCE;
if (pbuf->end <= dend) {
while (dest < pbuf->end) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= pbuf->size;
dend -= pbuf->size;
}
while (dest < dend) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
}
if (count & 1) {
union mix val;
val.val64 = 0;
val.val32[0] = *(u32 *)from;
writeq(val.val64, dest);
dest += sizeof(u64);
}
while (((unsigned long)dest & PIO_BLOCK_MASK) != 0) {
writeq(0, dest);
dest += sizeof(u64);
}
this_cpu_dec(*pbuf->sc->buffers_allocated);
preempt_enable();
}
static inline void read_low_bytes(struct pio_buf *pbuf, const void *from,
unsigned int nbytes)
{
unsigned long off;
if (nbytes == 0) {
pbuf->carry.val64 = 0;
} else {
off = (unsigned long)from & 0x7;
from = (void *)((unsigned long)from & ~0x7l);
pbuf->carry.val64 = ((*(u64 *)from)
<< zshift(nbytes + off))
>> zshift(nbytes);
}
pbuf->carry_bytes = nbytes;
}
static inline void read_extra_bytes(struct pio_buf *pbuf,
const void *from, unsigned int nbytes)
{
unsigned long off = (unsigned long)from & 0x7;
unsigned int room, xbytes;
from = (void *)((unsigned long)from & ~0x7l);
while (nbytes) {
room = 8 - off;
xbytes = min(room, nbytes);
pbuf->carry.val64 |= (((*(u64 *)from)
>> mshift(off))
<< zshift(xbytes))
>> zshift(xbytes + pbuf->carry_bytes);
off = 0;
pbuf->carry_bytes += xbytes;
nbytes -= xbytes;
from += sizeof(u64);
}
}
static inline void zero_extra_bytes(struct pio_buf *pbuf, unsigned int zbytes)
{
unsigned int remaining;
if (zbytes == 0)
return;
remaining = pbuf->carry_bytes - zbytes;
if (remaining)
pbuf->carry.val64 = (pbuf->carry.val64 << zshift(remaining))
>> zshift(remaining);
else
pbuf->carry.val64 = 0;
pbuf->carry_bytes = remaining;
}
static inline void merge_write8(
struct pio_buf *pbuf,
void __iomem *dest,
const void *src)
{
u64 new, temp;
new = *(u64 *)src;
temp = pbuf->carry.val64 | (new << mshift(pbuf->carry_bytes));
writeq(temp, dest);
pbuf->carry.val64 = new >> zshift(pbuf->carry_bytes);
}
static inline void carry8_write8(union mix carry, void __iomem *dest)
{
writeq(carry.val64, dest);
}
static inline int carry_write8(struct pio_buf *pbuf, void __iomem *dest)
{
if (pbuf->carry_bytes) {
writeq(pbuf->carry.val64, dest);
return 1;
}
return 0;
}
static inline void jcopy(u8 *dest, const u8 *src, u32 n)
{
switch (n) {
case 7:
*dest++ = *src++;
case 6:
*dest++ = *src++;
case 5:
*dest++ = *src++;
case 4:
*dest++ = *src++;
case 3:
*dest++ = *src++;
case 2:
*dest++ = *src++;
case 1:
*dest++ = *src++;
}
}
static inline void read_low_bytes(struct pio_buf *pbuf, const void *from,
unsigned int nbytes)
{
jcopy(&pbuf->carry.val8[0], from, nbytes);
pbuf->carry_bytes = nbytes;
}
static inline void read_extra_bytes(struct pio_buf *pbuf,
const void *from, unsigned int nbytes)
{
jcopy(&pbuf->carry.val8[pbuf->carry_bytes], from, nbytes);
pbuf->carry_bytes += nbytes;
}
static inline void zero_extra_bytes(struct pio_buf *pbuf, unsigned int zbytes)
{
pbuf->carry_bytes -= zbytes;
}
static inline void merge_write8(
struct pio_buf *pbuf,
void *dest,
const void *src)
{
u32 remainder = 8 - pbuf->carry_bytes;
jcopy(&pbuf->carry.val8[pbuf->carry_bytes], src, remainder);
writeq(pbuf->carry.val64, dest);
jcopy(&pbuf->carry.val8[0], src + remainder, pbuf->carry_bytes);
}
static inline void carry8_write8(union mix carry, void *dest)
{
writeq(carry.val64, dest);
}
static inline int carry_write8(struct pio_buf *pbuf, void *dest)
{
if (pbuf->carry_bytes) {
u64 zero = 0;
jcopy(&pbuf->carry.val8[pbuf->carry_bytes], (u8 *)&zero,
8 - pbuf->carry_bytes);
writeq(pbuf->carry.val64, dest);
return 1;
}
return 0;
}
void seg_pio_copy_start(struct pio_buf *pbuf, u64 pbc,
const void *from, size_t nbytes)
{
void __iomem *dest = pbuf->start + SOP_DISTANCE;
void __iomem *send = dest + PIO_BLOCK_SIZE;
void __iomem *dend;
writeq(pbc, dest);
dest += sizeof(u64);
dend = dest + ((nbytes >> 3) * sizeof(u64));
if (dend < send) {
while (dest < dend) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
} else {
while (dest < send) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= SOP_DISTANCE;
dend -= SOP_DISTANCE;
if (pbuf->end <= dend) {
while (dest < pbuf->end) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= pbuf->size;
dend -= pbuf->size;
}
while (dest < dend) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
}
read_low_bytes(pbuf, from, nbytes & 0x7);
pbuf->qw_written = 1 + (nbytes >> 3);
}
static void mid_copy_mix(struct pio_buf *pbuf, const void *from, size_t nbytes)
{
void __iomem *dest = pbuf->start + (pbuf->qw_written * sizeof(u64));
void __iomem *dend;
unsigned long qw_to_write = (pbuf->carry_bytes + nbytes) >> 3;
unsigned long bytes_left = (pbuf->carry_bytes + nbytes) & 0x7;
dend = dest + (qw_to_write * sizeof(u64));
if (pbuf->qw_written < PIO_BLOCK_QWS) {
void __iomem *send;
void __iomem *xend;
send = pbuf->start + PIO_BLOCK_SIZE;
xend = min(send, dend);
dest += SOP_DISTANCE;
xend += SOP_DISTANCE;
while (dest < xend) {
merge_write8(pbuf, dest, from);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= SOP_DISTANCE;
}
if (pbuf->end <= dend) {
while (dest < pbuf->end) {
merge_write8(pbuf, dest, from);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= pbuf->size;
dend -= pbuf->size;
}
while (dest < dend) {
merge_write8(pbuf, dest, from);
from += sizeof(u64);
dest += sizeof(u64);
}
if (pbuf->carry_bytes < bytes_left) {
read_extra_bytes(pbuf, from, bytes_left - pbuf->carry_bytes);
} else {
zero_extra_bytes(pbuf, pbuf->carry_bytes - bytes_left);
}
pbuf->qw_written += qw_to_write;
}
static void mid_copy_straight(struct pio_buf *pbuf,
const void *from, size_t nbytes)
{
void __iomem *dest = pbuf->start + (pbuf->qw_written * sizeof(u64));
void __iomem *dend;
dend = dest + ((nbytes >> 3) * sizeof(u64));
if (pbuf->qw_written < PIO_BLOCK_QWS) {
void __iomem *send;
void __iomem *xend;
send = pbuf->start + PIO_BLOCK_SIZE;
xend = min(send, dend);
dest += SOP_DISTANCE;
xend += SOP_DISTANCE;
while (dest < xend) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= SOP_DISTANCE;
}
if (pbuf->end <= dend) {
while (dest < pbuf->end) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
dest -= pbuf->size;
dend -= pbuf->size;
}
while (dest < dend) {
writeq(*(u64 *)from, dest);
from += sizeof(u64);
dest += sizeof(u64);
}
read_low_bytes(pbuf, from, nbytes & 0x7);
pbuf->qw_written += nbytes >> 3;
}
void seg_pio_copy_mid(struct pio_buf *pbuf, const void *from, size_t nbytes)
{
unsigned long from_align = (unsigned long)from & 0x7;
if (pbuf->carry_bytes + nbytes < 8) {
read_extra_bytes(pbuf, from, nbytes);
return;
}
if (from_align) {
unsigned long to_align;
to_align = 8 - from_align;
if (pbuf->carry_bytes + to_align < 8) {
read_extra_bytes(pbuf, from, to_align);
from += to_align;
nbytes -= to_align;
} else {
unsigned long to_fill = 8 - pbuf->carry_bytes;
unsigned long extra = to_align - to_fill;
void __iomem *dest;
read_extra_bytes(pbuf, from, to_fill);
from += to_fill;
nbytes -= to_fill;
dest = pbuf->start + (pbuf->qw_written * sizeof(u64));
if (dest >= pbuf->end)
dest -= pbuf->size;
else if (pbuf->qw_written < PIO_BLOCK_QWS)
dest += SOP_DISTANCE;
carry8_write8(pbuf->carry, dest);
pbuf->qw_written++;
read_low_bytes(pbuf, from, extra);
from += extra;
nbytes -= extra;
}
}
if (pbuf->carry_bytes)
mid_copy_mix(pbuf, from, nbytes);
else
mid_copy_straight(pbuf, from, nbytes);
}
void seg_pio_copy_end(struct pio_buf *pbuf)
{
void __iomem *dest = pbuf->start + (pbuf->qw_written * sizeof(u64));
if (dest >= pbuf->end)
dest -= pbuf->size;
else if (pbuf->qw_written < PIO_BLOCK_QWS)
dest += SOP_DISTANCE;
if (carry_write8(pbuf, dest)) {
dest += sizeof(u64);
}
while (((unsigned long)dest & PIO_BLOCK_MASK) != 0) {
writeq(0, dest);
dest += sizeof(u64);
}
this_cpu_dec(*pbuf->sc->buffers_allocated);
preempt_enable();
}
