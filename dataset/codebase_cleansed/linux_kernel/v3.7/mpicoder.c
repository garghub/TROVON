MPI mpi_read_raw_data(const void *xbuffer, size_t nbytes)
{
const uint8_t *buffer = xbuffer;
int i, j;
unsigned nbits, nlimbs;
mpi_limb_t a;
MPI val = NULL;
while (nbytes >= 0 && buffer[0] == 0) {
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
nlimbs = (nbytes + BYTES_PER_MPI_LIMB - 1) / BYTES_PER_MPI_LIMB;
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
nbytes = (nbits + 7) / 8;
nlimbs = (nbytes + BYTES_PER_MPI_LIMB - 1) / BYTES_PER_MPI_LIMB;
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
void *mpi_get_buffer(MPI a, unsigned *nbytes, int *sign)
{
uint8_t *p, *buffer;
mpi_limb_t alimb;
int i;
unsigned int n;
if (sign)
*sign = a->sign;
*nbytes = n = a->nlimbs * BYTES_PER_MPI_LIMB;
if (!n)
n++;
p = buffer = kmalloc(n, GFP_KERNEL);
if (!p)
return NULL;
for (i = a->nlimbs - 1; i >= 0; i--) {
alimb = a->d[i];
#if BYTES_PER_MPI_LIMB == 4
*p++ = alimb >> 24;
*p++ = alimb >> 16;
*p++ = alimb >> 8;
*p++ = alimb;
#elif BYTES_PER_MPI_LIMB == 8
*p++ = alimb >> 56;
*p++ = alimb >> 48;
*p++ = alimb >> 40;
*p++ = alimb >> 32;
*p++ = alimb >> 24;
*p++ = alimb >> 16;
*p++ = alimb >> 8;
*p++ = alimb;
#else
#error please implement for this limb size.
#endif
}
for (p = buffer; !*p && *nbytes; p++, --*nbytes)
;
if (p != buffer)
memmove(buffer, p, *nbytes);
return buffer;
}
int mpi_set_buffer(MPI a, const void *xbuffer, unsigned nbytes, int sign)
{
const uint8_t *buffer = xbuffer, *p;
mpi_limb_t alimb;
int nlimbs;
int i;
nlimbs = (nbytes + BYTES_PER_MPI_LIMB - 1) / BYTES_PER_MPI_LIMB;
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
