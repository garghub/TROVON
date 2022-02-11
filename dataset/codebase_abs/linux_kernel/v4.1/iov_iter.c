static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
const struct V_10 * V_11 ;
char T_2 * V_12 ;
void * V_13 , * V_14 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_11 = V_5 -> V_11 ;
V_6 = V_5 -> V_16 ;
V_12 = V_11 -> V_17 + V_6 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
if ( ! F_4 ( V_12 , V_7 ) ) {
V_13 = F_5 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_6 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_6 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
if ( F_7 ( ! V_3 ) ) {
F_8 ( V_13 ) ;
goto V_19;
}
V_2 = V_14 - V_13 ;
V_12 += V_7 ;
F_8 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_9 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_10 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_10 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
F_11 ( V_1 ) ;
V_19:
if ( V_6 == V_11 -> V_18 ) {
V_11 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_20 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
static T_1 F_12 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
const struct V_10 * V_11 ;
char T_2 * V_12 ;
void * V_13 , * V_21 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_11 = V_5 -> V_11 ;
V_6 = V_5 -> V_16 ;
V_12 = V_11 -> V_17 + V_6 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
if ( ! F_13 ( V_12 , V_7 ) ) {
V_13 = F_5 ( V_1 ) ;
V_21 = V_13 + V_2 ;
V_8 = F_14 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_14 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
}
if ( F_7 ( ! V_3 ) ) {
F_8 ( V_13 ) ;
goto V_19;
}
V_2 = V_21 - V_13 ;
V_12 += V_7 ;
F_8 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_9 ( V_1 ) ;
V_21 = V_13 + V_2 ;
V_8 = F_15 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_15 ( V_21 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_21 += V_7 ;
V_3 -= V_7 ;
}
F_11 ( V_1 ) ;
V_19:
if ( V_6 == V_11 -> V_18 ) {
V_11 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_20 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
int F_16 ( struct V_4 * V_5 , T_1 V_3 )
{
if ( ! ( V_5 -> type & ( V_22 | V_23 ) ) ) {
char T_2 * V_12 = V_5 -> V_11 -> V_17 + V_5 -> V_16 ;
V_3 = F_3 ( V_3 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
return F_13 ( V_12 , V_3 ) ;
}
return 0 ;
}
int F_17 ( struct V_4 * V_5 , T_1 V_3 )
{
T_1 V_6 = V_5 -> V_16 ;
const struct V_10 * V_11 ;
int V_24 ;
struct V_10 V_25 ;
if ( ! ( V_5 -> type & ( V_22 | V_23 ) ) ) {
F_18 (i, bytes, v, iov, skip, ({
err = fault_in_multipages_readable(v.iov_base,
v.iov_len);
if (unlikely(err))
return err;
0;}))
}
return 0 ;
}
void F_19 ( struct V_4 * V_5 , int V_26 ,
const struct V_10 * V_11 , unsigned long V_20 ,
T_1 V_15 )
{
if ( F_20 ( F_21 () , V_27 ) ) {
V_26 |= V_23 ;
V_5 -> type = V_26 ;
V_5 -> V_28 = (struct V_28 * ) V_11 ;
} else {
V_5 -> type = V_26 ;
V_5 -> V_11 = V_11 ;
}
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
static void F_22 ( char * V_21 , struct V_1 * V_1 , T_1 V_2 , T_1 V_29 )
{
char * V_14 = F_5 ( V_1 ) ;
memcpy ( V_21 , V_14 + V_2 , V_29 ) ;
F_8 ( V_14 ) ;
}
static void F_23 ( struct V_1 * V_1 , T_1 V_2 , char * V_14 , T_1 V_29 )
{
char * V_21 = F_5 ( V_1 ) ;
memcpy ( V_21 + V_2 , V_14 , V_29 ) ;
F_8 ( V_21 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_29 )
{
char * V_30 = F_5 ( V_1 ) ;
memset ( V_30 + V_2 , 0 , V_29 ) ;
F_8 ( V_30 ) ;
}
T_1 F_25 ( void * V_30 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_14 = V_30 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_26 (i, bytes, v,
__copy_to_user(v.iov_base, (from += v.iov_len) - v.iov_len,
v.iov_len),
memcpy_to_page(v.bv_page, v.bv_offset,
(from += v.bv_len) - v.bv_len, v.bv_len),
memcpy(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len)
)
return V_3 ;
}
T_1 F_27 ( void * V_30 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_21 = V_30 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_26 (i, bytes, v,
__copy_from_user((to += v.iov_len) - v.iov_len, v.iov_base,
v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
T_1 F_28 ( void * V_30 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_21 = V_30 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_26 (i, bytes, v,
__copy_from_user_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
T_1 F_29 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & ( V_22 | V_23 ) ) {
void * V_13 = F_5 ( V_1 ) ;
T_1 V_9 = F_25 ( V_13 + V_2 , V_3 , V_5 ) ;
F_8 ( V_13 ) ;
return V_9 ;
} else
return F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_30 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & ( V_22 | V_23 ) ) {
void * V_13 = F_5 ( V_1 ) ;
T_1 V_9 = F_27 ( V_13 + V_2 , V_3 , V_5 ) ;
F_8 ( V_13 ) ;
return V_9 ;
} else
return F_12 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_31 ( T_1 V_3 , struct V_4 * V_5 )
{
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_26 (i, bytes, v,
__clear_user(v.iov_base, v.iov_len),
memzero_page(v.bv_page, v.bv_offset, v.bv_len),
memset(v.iov_base, 0, v.iov_len)
)
return V_3 ;
}
T_1 F_32 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 = F_5 ( V_1 ) , * V_31 = V_13 + V_2 ;
F_33 (i, bytes, v,
__copy_from_user_inatomic((p += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((p += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_8 ( V_13 ) ;
return V_3 ;
}
void F_34 ( struct V_4 * V_5 , T_1 V_32 )
{
F_26 (i, size, v, 0 , 0 , 0 )
}
T_1 F_35 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_20 == 1 )
return V_5 -> V_15 ;
else if ( V_5 -> type & V_22 )
return F_3 ( V_5 -> V_15 , V_5 -> V_33 -> V_34 - V_5 -> V_16 ) ;
else
return F_3 ( V_5 -> V_15 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
}
void F_36 ( struct V_4 * V_5 , int V_26 ,
const struct V_28 * V_28 , unsigned long V_20 ,
T_1 V_15 )
{
F_37 ( ! ( V_26 & V_23 ) ) ;
V_5 -> type = V_26 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
void F_38 ( struct V_4 * V_5 , int V_26 ,
const struct V_35 * V_33 , unsigned long V_20 ,
T_1 V_15 )
{
F_37 ( ! ( V_26 & V_22 ) ) ;
V_5 -> type = V_26 ;
V_5 -> V_33 = V_33 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
unsigned long F_39 ( const struct V_4 * V_5 )
{
unsigned long V_36 = 0 ;
T_1 V_32 = V_5 -> V_15 ;
if ( ! V_32 )
return 0 ;
F_33 (i, size, v,
(res |= (unsigned long)v.iov_base | v.iov_len, 0),
res |= v.bv_offset | v.bv_len,
res |= (unsigned long)v.iov_base | v.iov_len
)
return V_36 ;
}
T_3 F_40 ( struct V_4 * V_5 ,
struct V_1 * * V_37 , T_1 V_38 , unsigned V_39 ,
T_1 * V_40 )
{
if ( V_38 > V_5 -> V_15 )
V_38 = V_5 -> V_15 ;
if ( ! V_38 )
return 0 ;
F_33 (i, maxsize, v, ({
unsigned long addr = (unsigned long)v.iov_base;
size_t len = v.iov_len + (*start = addr & (PAGE_SIZE - 1));
int n;
int res;
if (len > maxpages * PAGE_SIZE)
len = maxpages * PAGE_SIZE;
addr &= ~(PAGE_SIZE - 1);
n = DIV_ROUND_UP(len, PAGE_SIZE);
res = get_user_pages_fast(addr, n, (i->type & WRITE) != WRITE, pages);
if (unlikely(res < 0))
return res;
return (res == n ? len : res * PAGE_SIZE) - *start;
0;}),({
*start = v.bv_offset;
get_page(*pages = v.bv_page);
return v.bv_len;
}),({
return -EFAULT;
})
)
return 0 ;
}
static struct V_1 * * F_41 ( T_1 V_41 )
{
struct V_1 * * V_31 = F_42 ( V_41 * sizeof( struct V_1 * ) , V_42 ) ;
if ( ! V_31 )
V_31 = F_43 ( V_41 * sizeof( struct V_1 * ) ) ;
return V_31 ;
}
T_3 F_44 ( struct V_4 * V_5 ,
struct V_1 * * * V_37 , T_1 V_38 ,
T_1 * V_40 )
{
struct V_1 * * V_31 ;
if ( V_38 > V_5 -> V_15 )
V_38 = V_5 -> V_15 ;
if ( ! V_38 )
return 0 ;
F_33 (i, maxsize, v, ({
unsigned long addr = (unsigned long)v.iov_base;
size_t len = v.iov_len + (*start = addr & (PAGE_SIZE - 1));
int n;
int res;
addr &= ~(PAGE_SIZE - 1);
n = DIV_ROUND_UP(len, PAGE_SIZE);
p = get_pages_array(n);
if (!p)
return -ENOMEM;
res = get_user_pages_fast(addr, n, (i->type & WRITE) != WRITE, p);
if (unlikely(res < 0)) {
kvfree(p);
return res;
}
*pages = p;
return (res == n ? len : res * PAGE_SIZE) - *start;
0;}),({
*start = v.bv_offset;
*pages = p = get_pages_array(1);
if (!p)
return -ENOMEM;
get_page(*p = v.bv_page);
return v.bv_len;
}),({
return -EFAULT;
})
)
return 0 ;
}
T_1 F_45 ( void * V_30 , T_1 V_3 , T_4 * V_43 ,
struct V_4 * V_5 )
{
char * V_21 = V_30 ;
T_4 V_44 , V_45 ;
T_1 V_46 = 0 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_44 = * V_43 ;
F_26 (i, bytes, v, ({
int err = 0;
next = csum_and_copy_from_user(v.iov_base,
(to += v.iov_len) - v.iov_len,
v.iov_len, 0, &err);
if (!err) {
sum = csum_block_add(sum, next, off);
off += v.iov_len;
}
err ? v.iov_len : 0;
}), ({
char *p = kmap_atomic(v.bv_page);
next = csum_partial_copy_nocheck(p + v.bv_offset,
(to += v.bv_len) - v.bv_len,
v.bv_len, 0);
kunmap_atomic(p);
sum = csum_block_add(sum, next, off);
off += v.bv_len;
}),({
next = csum_partial_copy_nocheck(v.iov_base,
(to += v.iov_len) - v.iov_len,
v.iov_len, 0);
sum = csum_block_add(sum, next, off);
off += v.iov_len;
})
)
* V_43 = V_44 ;
return V_3 ;
}
T_1 F_46 ( void * V_30 , T_1 V_3 , T_4 * V_43 ,
struct V_4 * V_5 )
{
char * V_14 = V_30 ;
T_4 V_44 , V_45 ;
T_1 V_46 = 0 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_44 = * V_43 ;
F_26 (i, bytes, v, ({
int err = 0;
next = csum_and_copy_to_user((from += v.iov_len) - v.iov_len,
v.iov_base,
v.iov_len, 0, &err);
if (!err) {
sum = csum_block_add(sum, next, off);
off += v.iov_len;
}
err ? v.iov_len : 0;
}), ({
char *p = kmap_atomic(v.bv_page);
next = csum_partial_copy_nocheck((from += v.bv_len) - v.bv_len,
p + v.bv_offset,
v.bv_len, 0);
kunmap_atomic(p);
sum = csum_block_add(sum, next, off);
off += v.bv_len;
}),({
next = csum_partial_copy_nocheck((from += v.iov_len) - v.iov_len,
v.iov_base,
v.iov_len, 0);
sum = csum_block_add(sum, next, off);
off += v.iov_len;
})
)
* V_43 = V_44 ;
return V_3 ;
}
int F_47 ( const struct V_4 * V_5 , int V_39 )
{
T_1 V_32 = V_5 -> V_15 ;
int V_47 = 0 ;
if ( ! V_32 )
return 0 ;
F_33 (i, size, v, ({
unsigned long p = (unsigned long)v.iov_base;
npages += DIV_ROUND_UP(p + v.iov_len, PAGE_SIZE)
- p / PAGE_SIZE;
if (npages >= maxpages)
return maxpages;
0;}),({
npages++;
if (npages >= maxpages)
return maxpages;
}),({
unsigned long p = (unsigned long)v.iov_base;
npages += DIV_ROUND_UP(p + v.iov_len, PAGE_SIZE)
- p / PAGE_SIZE;
if (npages >= maxpages)
return maxpages;
})
)
return V_47 ;
}
const void * F_48 ( struct V_4 * V_48 , struct V_4 * V_49 , T_5 V_50 )
{
* V_48 = * V_49 ;
if ( V_48 -> type & V_22 )
return V_48 -> V_33 = F_49 ( V_48 -> V_33 ,
V_48 -> V_20 * sizeof( struct V_35 ) ,
V_50 ) ;
else
return V_48 -> V_11 = F_49 ( V_48 -> V_11 ,
V_48 -> V_20 * sizeof( struct V_10 ) ,
V_50 ) ;
}
int F_50 ( int type , const struct V_10 T_2 * V_51 ,
unsigned V_20 , unsigned V_52 ,
struct V_10 * * V_11 , struct V_4 * V_5 )
{
T_3 V_41 ;
struct V_10 * V_31 ;
V_41 = F_51 ( type , V_51 , V_20 , V_52 ,
* V_11 , & V_31 ) ;
if ( V_41 < 0 ) {
if ( V_31 != * V_11 )
F_52 ( V_31 ) ;
* V_11 = NULL ;
return V_41 ;
}
F_19 ( V_5 , type , V_31 , V_20 , V_41 ) ;
* V_11 = V_31 == * V_11 ? NULL : V_31 ;
return 0 ;
}
int F_53 ( int type , const struct V_53 T_2 * V_51 ,
unsigned V_20 , unsigned V_52 ,
struct V_10 * * V_11 , struct V_4 * V_5 )
{
T_3 V_41 ;
struct V_10 * V_31 ;
V_41 = F_54 ( type , V_51 , V_20 , V_52 ,
* V_11 , & V_31 ) ;
if ( V_41 < 0 ) {
if ( V_31 != * V_11 )
F_52 ( V_31 ) ;
* V_11 = NULL ;
return V_41 ;
}
F_19 ( V_5 , type , V_31 , V_20 , V_41 ) ;
* V_11 = V_31 == * V_11 ? NULL : V_31 ;
return 0 ;
}
int F_55 ( int V_54 , void T_2 * V_12 , T_1 V_29 ,
struct V_10 * V_11 , struct V_4 * V_5 )
{
if ( V_29 > V_55 )
V_29 = V_55 ;
if ( F_2 ( ! F_56 ( ! V_54 , V_12 , V_29 ) ) )
return - V_56 ;
V_11 -> V_17 = V_12 ;
V_11 -> V_18 = V_29 ;
F_19 ( V_5 , V_54 , V_11 , 1 , V_29 ) ;
return 0 ;
}
