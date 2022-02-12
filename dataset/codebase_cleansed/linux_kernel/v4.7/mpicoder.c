MPI mpi_read_raw_data(const void *xbuffer, size_t nbytes)
{
const uint8_t *buffer = xbuffer;
int i, j;
unsigned nbits, nlimbs;
mpi_limb_t a;
MPI val = NULL;
while (nbytes > 0 && buffer[0] == 0) {
buffer++;
nbytes--;
}
nbits = nbytes * 8;
if (nbits > MAX_EXTERN_MPI_BITS) {
pr_info("MPI: mpi too large (%u bits)\n", nbits);
return NULL;
}
if (nbytes > 0)
nbits -= count_leading_zeros(buffer[0]);
else
nbits = 0;
nlimbs = DIV_ROUND_UP(nbytes, BYTES_PER_MPI_LIMB);
val = mpi_alloc(nlimbs);
if (!val)
return NULL;
val->nbits = nbits;
val->sign = 0;
val->nlimbs = nlimbs;
if (nbytes > 0) {
i = BYTES_PER_MPI_LIMB - nbytes % BYTES_PER_MPI_LIMB;
i %= BYTES_PER_MPI_LIMB;
for (j = nlimbs; j > 0; j--) {
a = 0;
for (; i < BYTES_PER_MPI_LIMB; i++) {
a <<= 8;
a |= *buffer++;
}
i = 0;
val->d[j - 1] = a;
}
}
return val;
}
MPI mpi_read_from_buffer(const void *xbuffer, unsigned *ret_nread)
{
const uint8_t *buffer = xbuffer;
int i, j;
unsigned nbits, nbytes, nlimbs, nread = 0;
mpi_limb_t a;
MPI val = NULL;
if (*ret_nread < 2)
goto leave;
nbits = buffer[0] << 8 | buffer[1];
if (nbits > MAX_EXTERN_MPI_BITS) {
pr_info("MPI: mpi too large (%u bits)\n", nbits);
goto leave;
}
buffer += 2;
nread = 2;
nbytes = DIV_ROUND_UP(nbits, 8);
nlimbs = DIV_ROUND_UP(nbytes, BYTES_PER_MPI_LIMB);
val = mpi_alloc(nlimbs);
if (!val)
return NULL;
i = BYTES_PER_MPI_LIMB - nbytes % BYTES_PER_MPI_LIMB;
i %= BYTES_PER_MPI_LIMB;
val->nbits = nbits;
j = val->nlimbs = nlimbs;
val->sign = 0;
for (; j > 0; j--) {
a = 0;
for (; i < BYTES_PER_MPI_LIMB; i++) {
if (++nread > *ret_nread) {
printk
("MPI: mpi larger than buffer nread=%d ret_nread=%d\n",
nread, *ret_nread);
goto leave;
}
a <<= 8;
a |= *buffer++;
}
i = 0;
val->d[j - 1] = a;
}
leave:
*ret_nread = nread;
return val;
}
static int count_lzeros(MPI a)
{
mpi_limb_t alimb;
int i, lzeros = 0;
for (i = a->nlimbs - 1; i >= 0; i--) {
alimb = a->d[i];
if (alimb == 0) {
lzeros += sizeof(mpi_limb_t);
} else {
lzeros += count_leading_zeros(alimb) / 8;
break;
}
}
return lzeros;
}
int mpi_read_buffer(MPI a, uint8_t *buf, unsigned buf_len, unsigned *nbytes,
int *sign)
{
uint8_t *p;
#if BYTES_PER_MPI_LIMB == 4
__be32 alimb;
#elif BYTES_PER_MPI_LIMB == 8
__be64 alimb;
#else
#error please implement for this limb size.
#endif
unsigned int n = mpi_get_size(a);
int i, lzeros;
if (!buf || !nbytes)
return -EINVAL;
if (sign)
*sign = a->sign;
lzeros = count_lzeros(a);
if (buf_len < n - lzeros) {
*nbytes = n - lzeros;
return -EOVERFLOW;
}
p = buf;
*nbytes = n - lzeros;
for (i = a->nlimbs - 1 - lzeros / BYTES_PER_MPI_LIMB,
lzeros %= BYTES_PER_MPI_LIMB;
i >= 0; i--) {
#if BYTES_PER_MPI_LIMB == 4
alimb = cpu_to_be32(a->d[i]);
#elif BYTES_PER_MPI_LIMB == 8
alimb = cpu_to_be64(a->d[i]);
#else
#error please implement for this limb size.
#endif
memcpy(p, (u8 *)&alimb + lzeros, BYTES_PER_MPI_LIMB - lzeros);
p += BYTES_PER_MPI_LIMB - lzeros;
lzeros = 0;
}
return 0;
}
void *mpi_get_buffer(MPI a, unsigned *nbytes, int *sign)
{
uint8_t *buf;
unsigned int n;
int ret;
if (!nbytes)
return NULL;
n = mpi_get_size(a);
if (!n)
n++;
buf = kmalloc(n, GFP_KERNEL);
if (!buf)
return NULL;
ret = mpi_read_buffer(a, buf, n, nbytes, sign);
if (ret) {
kfree(buf);
return NULL;
}
return buf;
}
int mpi_set_buffer(MPI a, const void *xbuffer, unsigned nbytes, int sign)
{
const uint8_t *buffer = xbuffer, *p;
mpi_limb_t alimb;
int nlimbs;
int i;
nlimbs = DIV_ROUND_UP(nbytes, BYTES_PER_MPI_LIMB);
if (RESIZE_IF_NEEDED(a, nlimbs) < 0)
return -ENOMEM;
a->sign = sign;
for (i = 0, p = buffer + nbytes - 1; p >= buffer + BYTES_PER_MPI_LIMB;) {
#if BYTES_PER_MPI_LIMB == 4
alimb = (mpi_limb_t) *p--;
alimb |= (mpi_limb_t) *p-- << 8;
alimb |= (mpi_limb_t) *p-- << 16;
alimb |= (mpi_limb_t) *p-- << 24;
#elif BYTES_PER_MPI_LIMB == 8
alimb = (mpi_limb_t) *p--;
alimb |= (mpi_limb_t) *p-- << 8;
alimb |= (mpi_limb_t) *p-- << 16;
alimb |= (mpi_limb_t) *p-- << 24;
alimb |= (mpi_limb_t) *p-- << 32;
alimb |= (mpi_limb_t) *p-- << 40;
alimb |= (mpi_limb_t) *p-- << 48;
alimb |= (mpi_limb_t) *p-- << 56;
#else
#error please implement for this limb size.
#endif
a->d[i++] = alimb;
}
if (p >= buffer) {
#if BYTES_PER_MPI_LIMB == 4
alimb = *p--;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 8;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 16;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 24;
#elif BYTES_PER_MPI_LIMB == 8
alimb = (mpi_limb_t) *p--;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 8;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 16;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 24;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 32;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 40;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 48;
if (p >= buffer)
alimb |= (mpi_limb_t) *p-- << 56;
#else
#error please implement for this limb size.
#endif
a->d[i++] = alimb;
}
a->nlimbs = i;
if (i != nlimbs) {
pr_emerg("MPI: mpi_set_buffer: Assertion failed (%d != %d)", i,
nlimbs);
BUG();
}
return 0;
}
int mpi_write_to_sgl(MPI a, struct scatterlist *sgl, unsigned *nbytes,
int *sign)
{
u8 *p, *p2;
#if BYTES_PER_MPI_LIMB == 4
__be32 alimb;
#elif BYTES_PER_MPI_LIMB == 8
__be64 alimb;
#else
#error please implement for this limb size.
#endif
unsigned int n = mpi_get_size(a);
int i, x, y = 0, lzeros, buf_len;
if (!nbytes)
return -EINVAL;
if (sign)
*sign = a->sign;
lzeros = count_lzeros(a);
if (*nbytes < n - lzeros) {
*nbytes = n - lzeros;
return -EOVERFLOW;
}
*nbytes = n - lzeros;
buf_len = sgl->length;
p2 = sg_virt(sgl);
for (i = a->nlimbs - 1 - lzeros / BYTES_PER_MPI_LIMB,
lzeros %= BYTES_PER_MPI_LIMB;
i >= 0; i--) {
#if BYTES_PER_MPI_LIMB == 4
alimb = cpu_to_be32(a->d[i]);
#elif BYTES_PER_MPI_LIMB == 8
alimb = cpu_to_be64(a->d[i]);
#else
#error please implement for this limb size.
#endif
if (lzeros) {
y = lzeros;
lzeros = 0;
}
p = (u8 *)&alimb + y;
for (x = 0; x < sizeof(alimb) - y; x++) {
if (!buf_len) {
sgl = sg_next(sgl);
if (!sgl)
return -EINVAL;
buf_len = sgl->length;
p2 = sg_virt(sgl);
}
*p2++ = *p++;
buf_len--;
}
y = 0;
}
return 0;
}
MPI mpi_read_raw_from_sgl(struct scatterlist *sgl, unsigned int nbytes)
{
struct scatterlist *sg;
int x, i, j, z, lzeros, ents;
unsigned int nbits, nlimbs;
mpi_limb_t a;
MPI val = NULL;
lzeros = 0;
ents = sg_nents(sgl);
for_each_sg(sgl, sg, ents, i) {
const u8 *buff = sg_virt(sg);
int len = sg->length;
while (len && !*buff) {
lzeros++;
len--;
buff++;
}
if (len && *buff)
break;
ents--;
nbytes -= lzeros;
lzeros = 0;
}
sgl = sg;
nbytes -= lzeros;
nbits = nbytes * 8;
if (nbits > MAX_EXTERN_MPI_BITS) {
pr_info("MPI: mpi too large (%u bits)\n", nbits);
return NULL;
}
if (nbytes > 0)
nbits -= count_leading_zeros(*(u8 *)(sg_virt(sgl) + lzeros)) -
(BITS_PER_LONG - 8);
nlimbs = DIV_ROUND_UP(nbytes, BYTES_PER_MPI_LIMB);
val = mpi_alloc(nlimbs);
if (!val)
return NULL;
val->nbits = nbits;
val->sign = 0;
val->nlimbs = nlimbs;
if (nbytes == 0)
return val;
j = nlimbs - 1;
a = 0;
z = BYTES_PER_MPI_LIMB - nbytes % BYTES_PER_MPI_LIMB;
z %= BYTES_PER_MPI_LIMB;
for_each_sg(sgl, sg, ents, i) {
const u8 *buffer = sg_virt(sg) + lzeros;
int len = sg->length - lzeros;
for (x = 0; x < len; x++) {
a <<= 8;
a |= *buffer++;
if (((z + x + 1) % BYTES_PER_MPI_LIMB) == 0) {
val->d[j--] = a;
a = 0;
}
}
z += x;
lzeros = 0;
}
return val;
}
