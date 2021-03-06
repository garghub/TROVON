STATIC void
xfs_btree_trace_ptr(
struct xfs_btree_cur *cur,
union xfs_btree_ptr ptr,
__psunsigned_t *high,
__psunsigned_t *low)
{
if (cur->bc_flags & XFS_BTREE_LONG_PTRS) {
__u64 val = be64_to_cpu(ptr.l);
*high = val >> 32;
*low = (int)val;
} else {
*high = 0;
*low = be32_to_cpu(ptr.s);
}
}
void
xfs_btree_trace_argbi(
const char *func,
struct xfs_btree_cur *cur,
struct xfs_buf *b,
int i,
int line)
{
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGBI,
line, (__psunsigned_t)b, i, 0, 0, 0, 0, 0,
0, 0, 0, 0);
}
void
xfs_btree_trace_argbii(
const char *func,
struct xfs_btree_cur *cur,
struct xfs_buf *b,
int i0,
int i1,
int line)
{
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGBII,
line, (__psunsigned_t)b, i0, i1, 0, 0, 0, 0,
0, 0, 0, 0);
}
void
xfs_btree_trace_argfffi(
const char *func,
struct xfs_btree_cur *cur,
xfs_dfiloff_t o,
xfs_dfsbno_t b,
xfs_dfilblks_t i,
int j,
int line)
{
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGFFFI,
line,
o >> 32, (int)o,
b >> 32, (int)b,
i >> 32, (int)i,
(int)j, 0, 0, 0, 0);
}
void
xfs_btree_trace_argi(
const char *func,
struct xfs_btree_cur *cur,
int i,
int line)
{
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGI,
line, i, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}
void
xfs_btree_trace_argipk(
const char *func,
struct xfs_btree_cur *cur,
int i,
union xfs_btree_ptr ptr,
union xfs_btree_key *key,
int line)
{
__psunsigned_t high, low;
__uint64_t l0, l1;
xfs_btree_trace_ptr(cur, ptr, &high, &low);
cur->bc_ops->trace_key(cur, key, &l0, &l1);
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGIPK,
line, i, high, low,
l0 >> 32, (int)l0,
l1 >> 32, (int)l1,
0, 0, 0, 0);
}
void
xfs_btree_trace_argipr(
const char *func,
struct xfs_btree_cur *cur,
int i,
union xfs_btree_ptr ptr,
union xfs_btree_rec *rec,
int line)
{
__psunsigned_t high, low;
__uint64_t l0, l1, l2;
xfs_btree_trace_ptr(cur, ptr, &high, &low);
cur->bc_ops->trace_record(cur, rec, &l0, &l1, &l2);
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGIPR,
line, i,
high, low,
l0 >> 32, (int)l0,
l1 >> 32, (int)l1,
l2 >> 32, (int)l2,
0, 0);
}
void
xfs_btree_trace_argik(
const char *func,
struct xfs_btree_cur *cur,
int i,
union xfs_btree_key *key,
int line)
{
__uint64_t l0, l1;
cur->bc_ops->trace_key(cur, key, &l0, &l1);
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGIK,
line, i,
l0 >> 32, (int)l0,
l1 >> 32, (int)l1,
0, 0, 0, 0, 0, 0);
}
void
xfs_btree_trace_argr(
const char *func,
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec,
int line)
{
__uint64_t l0, l1, l2;
cur->bc_ops->trace_record(cur, rec, &l0, &l1, &l2);
cur->bc_ops->trace_enter(cur, func, XBT_ARGS, XFS_BTREE_KTRACE_ARGR,
line,
l0 >> 32, (int)l0,
l1 >> 32, (int)l1,
l2 >> 32, (int)l2,
0, 0, 0, 0, 0);
}
void
xfs_btree_trace_cursor(
const char *func,
struct xfs_btree_cur *cur,
int type,
int line)
{
__uint32_t s0;
__uint64_t l0, l1;
char *s;
switch (type) {
case XBT_ARGS:
s = "args";
break;
case XBT_ENTRY:
s = "entry";
break;
case XBT_ERROR:
s = "error";
break;
case XBT_EXIT:
s = "exit";
break;
default:
s = "unknown";
break;
}
cur->bc_ops->trace_cursor(cur, &s0, &l0, &l1);
cur->bc_ops->trace_enter(cur, func, s, XFS_BTREE_KTRACE_CUR, line,
s0,
l0 >> 32, (int)l0,
l1 >> 32, (int)l1,
(__psunsigned_t)cur->bc_bufs[0],
(__psunsigned_t)cur->bc_bufs[1],
(__psunsigned_t)cur->bc_bufs[2],
(__psunsigned_t)cur->bc_bufs[3],
(cur->bc_ptrs[0] << 16) | cur->bc_ptrs[1],
(cur->bc_ptrs[2] << 16) | cur->bc_ptrs[3]);
}
