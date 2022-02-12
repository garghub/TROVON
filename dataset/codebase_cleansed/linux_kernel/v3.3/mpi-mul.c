int mpi_mul_ui(MPI prod, MPI mult, unsigned long small_mult)
{
mpi_size_t size, prod_size;
mpi_ptr_t prod_ptr;
mpi_limb_t cy;
int sign;
size = mult->nlimbs;
sign = mult->sign;
if (!size || !small_mult) {
prod->nlimbs = 0;
prod->sign = 0;
return 0;
}
prod_size = size + 1;
if (prod->alloced < prod_size)
if (mpi_resize(prod, prod_size) < 0)
return -ENOMEM;
prod_ptr = prod->d;
cy = mpihelp_mul_1(prod_ptr, mult->d, size, (mpi_limb_t) small_mult);
if (cy)
prod_ptr[size++] = cy;
prod->nlimbs = size;
prod->sign = sign;
return 0;
}
int mpi_mul_2exp(MPI w, MPI u, unsigned long cnt)
{
mpi_size_t usize, wsize, limb_cnt;
mpi_ptr_t wp;
mpi_limb_t wlimb;
int usign, wsign;
usize = u->nlimbs;
usign = u->sign;
if (!usize) {
w->nlimbs = 0;
w->sign = 0;
return 0;
}
limb_cnt = cnt / BITS_PER_MPI_LIMB;
wsize = usize + limb_cnt + 1;
if (w->alloced < wsize)
if (mpi_resize(w, wsize) < 0)
return -ENOMEM;
wp = w->d;
wsize = usize + limb_cnt;
wsign = usign;
cnt %= BITS_PER_MPI_LIMB;
if (cnt) {
wlimb = mpihelp_lshift(wp + limb_cnt, u->d, usize, cnt);
if (wlimb) {
wp[wsize] = wlimb;
wsize++;
}
} else {
MPN_COPY_DECR(wp + limb_cnt, u->d, usize);
}
MPN_ZERO(wp, limb_cnt);
w->nlimbs = wsize;
w->sign = wsign;
return 0;
}
int mpi_mul(MPI w, MPI u, MPI v)
{
int rc = -ENOMEM;
mpi_size_t usize, vsize, wsize;
mpi_ptr_t up, vp, wp;
mpi_limb_t cy;
int usign, vsign, sign_product;
int assign_wp = 0;
mpi_ptr_t tmp_limb = NULL;
if (u->nlimbs < v->nlimbs) {
usize = v->nlimbs;
usign = v->sign;
up = v->d;
vsize = u->nlimbs;
vsign = u->sign;
vp = u->d;
} else {
usize = u->nlimbs;
usign = u->sign;
up = u->d;
vsize = v->nlimbs;
vsign = v->sign;
vp = v->d;
}
sign_product = usign ^ vsign;
wp = w->d;
wsize = usize + vsize;
if (w->alloced < (size_t) wsize) {
if (wp == up || wp == vp) {
wp = mpi_alloc_limb_space(wsize);
if (!wp)
goto nomem;
assign_wp = 1;
} else {
if (mpi_resize(w, wsize) < 0)
goto nomem;
wp = w->d;
}
} else {
if (wp == up) {
up = tmp_limb = mpi_alloc_limb_space(usize);
if (!up)
goto nomem;
if (wp == vp)
vp = up;
MPN_COPY(up, wp, usize);
} else if (wp == vp) {
vp = tmp_limb = mpi_alloc_limb_space(vsize);
if (!vp)
goto nomem;
MPN_COPY(vp, wp, vsize);
}
}
if (!vsize)
wsize = 0;
else {
if (mpihelp_mul(wp, up, usize, vp, vsize, &cy) < 0)
goto nomem;
wsize -= cy ? 0 : 1;
}
if (assign_wp)
mpi_assign_limb_space(w, wp, wsize);
w->nlimbs = wsize;
w->sign = sign_product;
rc = 0;
nomem:
if (tmp_limb)
mpi_free_limb_space(tmp_limb);
return rc;
}
int mpi_mulm(MPI w, MPI u, MPI v, MPI m)
{
if (mpi_mul(w, u, v) < 0)
return -ENOMEM;
return mpi_fdiv_r(w, w, m);
}
