u64 lov_stripe_size(struct lov_stripe_md *lsm, u64 ost_size,
int stripeno)
{
unsigned long ssize = lsm->lsm_stripe_size;
unsigned long stripe_size;
u64 swidth;
u64 lov_size;
int magic = lsm->lsm_magic;
if (ost_size == 0)
return 0;
LASSERT(lsm_op_find(magic) != NULL);
lsm_op_find(magic)->lsm_stripe_by_index(lsm, &stripeno, NULL, &swidth);
stripe_size = lov_do_div64(ost_size, ssize);
if (stripe_size)
lov_size = ost_size * swidth + stripeno * ssize + stripe_size;
else
lov_size = (ost_size - 1) * swidth + (stripeno + 1) * ssize;
return lov_size;
}
int lov_stripe_offset(struct lov_stripe_md *lsm, u64 lov_off,
int stripeno, u64 *obdoff)
{
unsigned long ssize = lsm->lsm_stripe_size;
u64 stripe_off, this_stripe, swidth;
int magic = lsm->lsm_magic;
int ret = 0;
if (lov_off == OBD_OBJECT_EOF) {
*obdoff = OBD_OBJECT_EOF;
return 0;
}
LASSERT(lsm_op_find(magic) != NULL);
lsm_op_find(magic)->lsm_stripe_by_index(lsm, &stripeno, &lov_off,
&swidth);
stripe_off = lov_do_div64(lov_off, swidth);
this_stripe = (u64)stripeno * ssize;
if (stripe_off < this_stripe) {
stripe_off = 0;
ret = -1;
} else {
stripe_off -= this_stripe;
if (stripe_off >= ssize) {
stripe_off = ssize;
ret = 1;
}
}
*obdoff = lov_off * ssize + stripe_off;
return ret;
}
u64 lov_size_to_stripe(struct lov_stripe_md *lsm, u64 file_size,
int stripeno)
{
unsigned long ssize = lsm->lsm_stripe_size;
u64 stripe_off, this_stripe, swidth;
int magic = lsm->lsm_magic;
if (file_size == OBD_OBJECT_EOF)
return OBD_OBJECT_EOF;
LASSERT(lsm_op_find(magic) != NULL);
lsm_op_find(magic)->lsm_stripe_by_index(lsm, &stripeno, &file_size,
&swidth);
stripe_off = lov_do_div64(file_size, swidth);
this_stripe = (u64)stripeno * ssize;
if (stripe_off < this_stripe) {
if (file_size > 0) {
file_size--;
stripe_off = ssize;
} else {
stripe_off = 0;
}
} else {
stripe_off -= this_stripe;
if (stripe_off >= ssize) {
stripe_off = ssize;
}
}
return (file_size * ssize + stripe_off);
}
int lov_stripe_intersects(struct lov_stripe_md *lsm, int stripeno,
u64 start, u64 end, u64 *obd_start, u64 *obd_end)
{
int start_side, end_side;
start_side = lov_stripe_offset(lsm, start, stripeno, obd_start);
end_side = lov_stripe_offset(lsm, end, stripeno, obd_end);
CDEBUG(D_INODE, "[%llu->%llu] -> [(%d) %llu->%llu (%d)]\n",
start, end, start_side, *obd_start, *obd_end, end_side);
if (start_side != 0 && end_side != 0 && *obd_start == *obd_end)
return 0;
if (end_side != 0)
(*obd_end)--;
return 1;
}
int lov_stripe_number(struct lov_stripe_md *lsm, u64 lov_off)
{
unsigned long ssize = lsm->lsm_stripe_size;
u64 stripe_off, swidth;
int magic = lsm->lsm_magic;
LASSERT(lsm_op_find(magic) != NULL);
lsm_op_find(magic)->lsm_stripe_by_offset(lsm, NULL, &lov_off, &swidth);
stripe_off = lov_do_div64(lov_off, swidth);
lov_do_div64(stripe_off, ssize);
return stripe_off;
}
