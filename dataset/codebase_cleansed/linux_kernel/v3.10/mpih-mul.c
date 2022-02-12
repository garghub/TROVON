static mpi_limb_t
mul_n_basecase(mpi_ptr_t prodp, mpi_ptr_t up, mpi_ptr_t vp, mpi_size_t size)
{
mpi_size_t i;
mpi_limb_t cy;
mpi_limb_t v_limb;
v_limb = vp[0];
if (v_limb <= 1) {
if (v_limb == 1)
MPN_COPY(prodp, up, size);
else
MPN_ZERO(prodp, size);
cy = 0;
} else
cy = mpihelp_mul_1(prodp, up, size, v_limb);
prodp[size] = cy;
prodp++;
for (i = 1; i < size; i++) {
v_limb = vp[i];
if (v_limb <= 1) {
cy = 0;
if (v_limb == 1)
cy = mpihelp_add_n(prodp, prodp, up, size);
} else
cy = mpihelp_addmul_1(prodp, up, size, v_limb);
prodp[size] = cy;
prodp++;
}
return cy;
}
static void
mul_n(mpi_ptr_t prodp, mpi_ptr_t up, mpi_ptr_t vp,
mpi_size_t size, mpi_ptr_t tspace)
{
if (size & 1) {
mpi_size_t esize = size - 1;
mpi_limb_t cy_limb;
MPN_MUL_N_RECURSE(prodp, up, vp, esize, tspace);
cy_limb = mpihelp_addmul_1(prodp + esize, up, esize, vp[esize]);
prodp[esize + esize] = cy_limb;
cy_limb = mpihelp_addmul_1(prodp + esize, vp, size, up[esize]);
prodp[esize + size] = cy_limb;
} else {
mpi_size_t hsize = size >> 1;
mpi_limb_t cy;
int negflg;
MPN_MUL_N_RECURSE(prodp + size, up + hsize, vp + hsize, hsize,
tspace);
if (mpihelp_cmp(up + hsize, up, hsize) >= 0) {
mpihelp_sub_n(prodp, up + hsize, up, hsize);
negflg = 0;
} else {
mpihelp_sub_n(prodp, up, up + hsize, hsize);
negflg = 1;
}
if (mpihelp_cmp(vp + hsize, vp, hsize) >= 0) {
mpihelp_sub_n(prodp + hsize, vp + hsize, vp, hsize);
negflg ^= 1;
} else {
mpihelp_sub_n(prodp + hsize, vp, vp + hsize, hsize);
}
MPN_MUL_N_RECURSE(tspace, prodp, prodp + hsize, hsize,
tspace + size);
MPN_COPY(prodp + hsize, prodp + size, hsize);
cy = mpihelp_add_n(prodp + size, prodp + size,
prodp + size + hsize, hsize);
if (negflg)
cy -=
mpihelp_sub_n(prodp + hsize, prodp + hsize, tspace,
size);
else
cy +=
mpihelp_add_n(prodp + hsize, prodp + hsize, tspace,
size);
MPN_MUL_N_RECURSE(tspace, up, vp, hsize, tspace + size);
cy += mpihelp_add_n(prodp + hsize, prodp + hsize, tspace, size);
if (cy)
mpihelp_add_1(prodp + hsize + size,
prodp + hsize + size, hsize, cy);
MPN_COPY(prodp, tspace, hsize);
cy = mpihelp_add_n(prodp + hsize, prodp + hsize, tspace + hsize,
hsize);
if (cy)
mpihelp_add_1(prodp + size, prodp + size, size, 1);
}
}
void mpih_sqr_n_basecase(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t size)
{
mpi_size_t i;
mpi_limb_t cy_limb;
mpi_limb_t v_limb;
v_limb = up[0];
if (v_limb <= 1) {
if (v_limb == 1)
MPN_COPY(prodp, up, size);
else
MPN_ZERO(prodp, size);
cy_limb = 0;
} else
cy_limb = mpihelp_mul_1(prodp, up, size, v_limb);
prodp[size] = cy_limb;
prodp++;
for (i = 1; i < size; i++) {
v_limb = up[i];
if (v_limb <= 1) {
cy_limb = 0;
if (v_limb == 1)
cy_limb = mpihelp_add_n(prodp, prodp, up, size);
} else
cy_limb = mpihelp_addmul_1(prodp, up, size, v_limb);
prodp[size] = cy_limb;
prodp++;
}
}
void
mpih_sqr_n(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t size, mpi_ptr_t tspace)
{
if (size & 1) {
mpi_size_t esize = size - 1;
mpi_limb_t cy_limb;
MPN_SQR_N_RECURSE(prodp, up, esize, tspace);
cy_limb = mpihelp_addmul_1(prodp + esize, up, esize, up[esize]);
prodp[esize + esize] = cy_limb;
cy_limb = mpihelp_addmul_1(prodp + esize, up, size, up[esize]);
prodp[esize + size] = cy_limb;
} else {
mpi_size_t hsize = size >> 1;
mpi_limb_t cy;
MPN_SQR_N_RECURSE(prodp + size, up + hsize, hsize, tspace);
if (mpihelp_cmp(up + hsize, up, hsize) >= 0)
mpihelp_sub_n(prodp, up + hsize, up, hsize);
else
mpihelp_sub_n(prodp, up, up + hsize, hsize);
MPN_SQR_N_RECURSE(tspace, prodp, hsize, tspace + size);
MPN_COPY(prodp + hsize, prodp + size, hsize);
cy = mpihelp_add_n(prodp + size, prodp + size,
prodp + size + hsize, hsize);
cy -= mpihelp_sub_n(prodp + hsize, prodp + hsize, tspace, size);
MPN_SQR_N_RECURSE(tspace, up, hsize, tspace + size);
cy += mpihelp_add_n(prodp + hsize, prodp + hsize, tspace, size);
if (cy)
mpihelp_add_1(prodp + hsize + size,
prodp + hsize + size, hsize, cy);
MPN_COPY(prodp, tspace, hsize);
cy = mpihelp_add_n(prodp + hsize, prodp + hsize, tspace + hsize,
hsize);
if (cy)
mpihelp_add_1(prodp + size, prodp + size, size, 1);
}
}
int
mpihelp_mul_karatsuba_case(mpi_ptr_t prodp,
mpi_ptr_t up, mpi_size_t usize,
mpi_ptr_t vp, mpi_size_t vsize,
struct karatsuba_ctx *ctx)
{
mpi_limb_t cy;
if (!ctx->tspace || ctx->tspace_size < vsize) {
if (ctx->tspace)
mpi_free_limb_space(ctx->tspace);
ctx->tspace = mpi_alloc_limb_space(2 * vsize);
if (!ctx->tspace)
return -ENOMEM;
ctx->tspace_size = vsize;
}
MPN_MUL_N_RECURSE(prodp, up, vp, vsize, ctx->tspace);
prodp += vsize;
up += vsize;
usize -= vsize;
if (usize >= vsize) {
if (!ctx->tp || ctx->tp_size < vsize) {
if (ctx->tp)
mpi_free_limb_space(ctx->tp);
ctx->tp = mpi_alloc_limb_space(2 * vsize);
if (!ctx->tp) {
if (ctx->tspace)
mpi_free_limb_space(ctx->tspace);
ctx->tspace = NULL;
return -ENOMEM;
}
ctx->tp_size = vsize;
}
do {
MPN_MUL_N_RECURSE(ctx->tp, up, vp, vsize, ctx->tspace);
cy = mpihelp_add_n(prodp, prodp, ctx->tp, vsize);
mpihelp_add_1(prodp + vsize, ctx->tp + vsize, vsize,
cy);
prodp += vsize;
up += vsize;
usize -= vsize;
} while (usize >= vsize);
}
if (usize) {
if (usize < KARATSUBA_THRESHOLD) {
mpi_limb_t tmp;
if (mpihelp_mul(ctx->tspace, vp, vsize, up, usize, &tmp)
< 0)
return -ENOMEM;
} else {
if (!ctx->next) {
ctx->next = kzalloc(sizeof *ctx, GFP_KERNEL);
if (!ctx->next)
return -ENOMEM;
}
if (mpihelp_mul_karatsuba_case(ctx->tspace,
vp, vsize,
up, usize,
ctx->next) < 0)
return -ENOMEM;
}
cy = mpihelp_add_n(prodp, prodp, ctx->tspace, vsize);
mpihelp_add_1(prodp + vsize, ctx->tspace + vsize, usize, cy);
}
return 0;
}
void mpihelp_release_karatsuba_ctx(struct karatsuba_ctx *ctx)
{
struct karatsuba_ctx *ctx2;
if (ctx->tp)
mpi_free_limb_space(ctx->tp);
if (ctx->tspace)
mpi_free_limb_space(ctx->tspace);
for (ctx = ctx->next; ctx; ctx = ctx2) {
ctx2 = ctx->next;
if (ctx->tp)
mpi_free_limb_space(ctx->tp);
if (ctx->tspace)
mpi_free_limb_space(ctx->tspace);
kfree(ctx);
}
}
int
mpihelp_mul(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t usize,
mpi_ptr_t vp, mpi_size_t vsize, mpi_limb_t *_result)
{
mpi_ptr_t prod_endp = prodp + usize + vsize - 1;
mpi_limb_t cy;
struct karatsuba_ctx ctx;
if (vsize < KARATSUBA_THRESHOLD) {
mpi_size_t i;
mpi_limb_t v_limb;
if (!vsize) {
*_result = 0;
return 0;
}
v_limb = vp[0];
if (v_limb <= 1) {
if (v_limb == 1)
MPN_COPY(prodp, up, usize);
else
MPN_ZERO(prodp, usize);
cy = 0;
} else
cy = mpihelp_mul_1(prodp, up, usize, v_limb);
prodp[usize] = cy;
prodp++;
for (i = 1; i < vsize; i++) {
v_limb = vp[i];
if (v_limb <= 1) {
cy = 0;
if (v_limb == 1)
cy = mpihelp_add_n(prodp, prodp, up,
usize);
} else
cy = mpihelp_addmul_1(prodp, up, usize, v_limb);
prodp[usize] = cy;
prodp++;
}
*_result = cy;
return 0;
}
memset(&ctx, 0, sizeof ctx);
if (mpihelp_mul_karatsuba_case(prodp, up, usize, vp, vsize, &ctx) < 0)
return -ENOMEM;
mpihelp_release_karatsuba_ctx(&ctx);
*_result = *prod_endp;
return 0;
}
