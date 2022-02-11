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
if ( F_4 ( V_19 ) && ! F_5 ( V_12 , V_7 ) ) {
V_13 = F_6 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_7 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_7 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
if ( F_8 ( ! V_3 ) ) {
F_9 ( V_13 ) ;
goto V_20;
}
V_2 = V_14 - V_13 ;
V_12 += V_7 ;
F_9 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_10 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_11 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_11 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
F_12 ( V_1 ) ;
V_20:
if ( V_6 == V_11 -> V_18 ) {
V_11 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_21 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
static T_1 F_13 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
const struct V_10 * V_11 ;
char T_2 * V_12 ;
void * V_13 , * V_22 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_11 = V_5 -> V_11 ;
V_6 = V_5 -> V_16 ;
V_12 = V_11 -> V_17 + V_6 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
if ( F_4 ( V_19 ) && ! F_14 ( V_12 , V_7 ) ) {
V_13 = F_6 ( V_1 ) ;
V_22 = V_13 + V_2 ;
V_8 = F_15 ( V_22 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_22 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_15 ( V_22 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_22 += V_7 ;
V_3 -= V_7 ;
}
if ( F_8 ( ! V_3 ) ) {
F_9 ( V_13 ) ;
goto V_20;
}
V_2 = V_22 - V_13 ;
V_12 += V_7 ;
F_9 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_10 ( V_1 ) ;
V_22 = V_13 + V_2 ;
V_8 = F_16 ( V_22 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_22 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_16 ( V_22 , V_12 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_22 += V_7 ;
V_3 -= V_7 ;
}
F_12 ( V_1 ) ;
V_20:
if ( V_6 == V_11 -> V_18 ) {
V_11 ++ ;
V_6 = 0 ;
}
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_21 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
int F_17 ( struct V_4 * V_5 , T_1 V_3 )
{
T_1 V_6 = V_5 -> V_16 ;
const struct V_10 * V_11 ;
int V_23 ;
struct V_10 V_24 ;
if ( ! ( V_5 -> type & ( V_25 | V_26 ) ) ) {
F_18 (i, bytes, v, iov, skip, ({
err = fault_in_multipages_readable(v.iov_base,
v.iov_len);
if (unlikely(err))
return err;
0;}))
}
return 0 ;
}
void F_19 ( struct V_4 * V_5 , int V_27 ,
const struct V_10 * V_11 , unsigned long V_21 ,
T_1 V_15 )
{
if ( F_20 ( F_21 () , V_28 ) ) {
V_27 |= V_26 ;
V_5 -> type = V_27 ;
V_5 -> V_29 = (struct V_29 * ) V_11 ;
} else {
V_5 -> type = V_27 ;
V_5 -> V_11 = V_11 ;
}
V_5 -> V_21 = V_21 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
static void F_22 ( char * V_22 , struct V_1 * V_1 , T_1 V_2 , T_1 V_30 )
{
char * V_14 = F_6 ( V_1 ) ;
memcpy ( V_22 , V_14 + V_2 , V_30 ) ;
F_9 ( V_14 ) ;
}
static void F_23 ( struct V_1 * V_1 , T_1 V_2 , const char * V_14 , T_1 V_30 )
{
char * V_22 = F_6 ( V_1 ) ;
memcpy ( V_22 + V_2 , V_14 , V_30 ) ;
F_9 ( V_22 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_30 )
{
char * V_31 = F_6 ( V_1 ) ;
memset ( V_31 + V_2 , 0 , V_30 ) ;
F_9 ( V_31 ) ;
}
T_1 F_25 ( const void * V_31 , T_1 V_3 , struct V_4 * V_5 )
{
const char * V_14 = V_31 ;
F_26 (i, bytes, v,
__copy_to_user(v.iov_base, (from += v.iov_len) - v.iov_len,
v.iov_len),
memcpy_to_page(v.bv_page, v.bv_offset,
(from += v.bv_len) - v.bv_len, v.bv_len),
memcpy(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len)
)
return V_3 ;
}
T_1 F_27 ( void * V_31 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_22 = V_31 ;
F_26 (i, bytes, v,
__copy_from_user((to += v.iov_len) - v.iov_len, v.iov_base,
v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
T_1 F_28 ( void * V_31 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_22 = V_31 ;
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
if ( V_5 -> type & ( V_25 | V_26 ) ) {
void * V_13 = F_6 ( V_1 ) ;
T_1 V_9 = F_25 ( V_13 + V_2 , V_3 , V_5 ) ;
F_9 ( V_13 ) ;
return V_9 ;
} else
return F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_30 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & ( V_25 | V_26 ) ) {
void * V_13 = F_6 ( V_1 ) ;
T_1 V_9 = F_27 ( V_13 + V_2 , V_3 , V_5 ) ;
F_9 ( V_13 ) ;
return V_9 ;
} else
return F_13 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_31 ( T_1 V_3 , struct V_4 * V_5 )
{
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
char * V_13 = F_6 ( V_1 ) , * V_32 = V_13 + V_2 ;
F_33 (i, bytes, v,
__copy_from_user_inatomic((p += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((p += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_9 ( V_13 ) ;
return V_3 ;
}
void F_34 ( struct V_4 * V_5 , T_1 V_33 )
{
F_26 (i, size, v, 0 , 0 , 0 )
}
T_1 F_35 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_21 == 1 )
return V_5 -> V_15 ;
else if ( V_5 -> type & V_25 )
return F_3 ( V_5 -> V_15 , V_5 -> V_34 -> V_35 - V_5 -> V_16 ) ;
else
return F_3 ( V_5 -> V_15 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
}
void F_36 ( struct V_4 * V_5 , int V_27 ,
const struct V_29 * V_29 , unsigned long V_21 ,
T_1 V_15 )
{
F_37 ( ! ( V_27 & V_26 ) ) ;
V_5 -> type = V_27 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
void F_38 ( struct V_4 * V_5 , int V_27 ,
const struct V_36 * V_34 , unsigned long V_21 ,
T_1 V_15 )
{
F_37 ( ! ( V_27 & V_25 ) ) ;
V_5 -> type = V_27 ;
V_5 -> V_34 = V_34 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
unsigned long F_39 ( const struct V_4 * V_5 )
{
unsigned long V_37 = 0 ;
T_1 V_33 = V_5 -> V_15 ;
if ( ! V_33 )
return 0 ;
F_33 (i, size, v,
(res |= (unsigned long)v.iov_base | v.iov_len, 0),
res |= v.bv_offset | v.bv_len,
res |= (unsigned long)v.iov_base | v.iov_len
)
return V_37 ;
}
unsigned long F_40 ( const struct V_4 * V_5 )
{
unsigned long V_37 = 0 ;
T_1 V_33 = V_5 -> V_15 ;
if ( ! V_33 )
return 0 ;
F_33 ( V_5 , V_33 , V_24 ,
( V_37 |= ( ! V_37 ? 0 : ( unsigned long ) V_24 . V_17 ) |
( V_33 != V_24 . V_18 ? V_33 : 0 ) , 0 ) ,
( V_37 |= ( ! V_37 ? 0 : ( unsigned long ) V_24 . V_38 ) |
( V_33 != V_24 . V_35 ? V_33 : 0 ) ) ,
( V_37 |= ( ! V_37 ? 0 : ( unsigned long ) V_24 . V_17 ) |
( V_33 != V_24 . V_18 ? V_33 : 0 ) )
) ;
return V_37 ;
}
T_3 F_41 ( struct V_4 * V_5 ,
struct V_1 * * V_39 , T_1 V_40 , unsigned V_41 ,
T_1 * V_42 )
{
if ( V_40 > V_5 -> V_15 )
V_40 = V_5 -> V_15 ;
if ( ! V_40 )
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
static struct V_1 * * F_42 ( T_1 V_43 )
{
struct V_1 * * V_32 = F_43 ( V_43 * sizeof( struct V_1 * ) , V_44 ) ;
if ( ! V_32 )
V_32 = F_44 ( V_43 * sizeof( struct V_1 * ) ) ;
return V_32 ;
}
T_3 F_45 ( struct V_4 * V_5 ,
struct V_1 * * * V_39 , T_1 V_40 ,
T_1 * V_42 )
{
struct V_1 * * V_32 ;
if ( V_40 > V_5 -> V_15 )
V_40 = V_5 -> V_15 ;
if ( ! V_40 )
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
T_1 F_46 ( void * V_31 , T_1 V_3 , T_4 * V_45 ,
struct V_4 * V_5 )
{
char * V_22 = V_31 ;
T_4 V_46 , V_47 ;
T_1 V_48 = 0 ;
V_46 = * V_45 ;
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
* V_45 = V_46 ;
return V_3 ;
}
T_1 F_47 ( const void * V_31 , T_1 V_3 , T_4 * V_45 ,
struct V_4 * V_5 )
{
const char * V_14 = V_31 ;
T_4 V_46 , V_47 ;
T_1 V_48 = 0 ;
V_46 = * V_45 ;
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
* V_45 = V_46 ;
return V_3 ;
}
int F_48 ( const struct V_4 * V_5 , int V_41 )
{
T_1 V_33 = V_5 -> V_15 ;
int V_49 = 0 ;
if ( ! V_33 )
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
return V_49 ;
}
const void * F_49 ( struct V_4 * V_50 , struct V_4 * V_51 , T_5 V_52 )
{
* V_50 = * V_51 ;
if ( V_50 -> type & V_25 )
return V_50 -> V_34 = F_50 ( V_50 -> V_34 ,
V_50 -> V_21 * sizeof( struct V_36 ) ,
V_52 ) ;
else
return V_50 -> V_11 = F_50 ( V_50 -> V_11 ,
V_50 -> V_21 * sizeof( struct V_10 ) ,
V_52 ) ;
}
int F_51 ( int type , const struct V_10 T_2 * V_53 ,
unsigned V_21 , unsigned V_54 ,
struct V_10 * * V_11 , struct V_4 * V_5 )
{
T_3 V_43 ;
struct V_10 * V_32 ;
V_43 = F_52 ( type , V_53 , V_21 , V_54 ,
* V_11 , & V_32 ) ;
if ( V_43 < 0 ) {
if ( V_32 != * V_11 )
F_53 ( V_32 ) ;
* V_11 = NULL ;
return V_43 ;
}
F_19 ( V_5 , type , V_32 , V_21 , V_43 ) ;
* V_11 = V_32 == * V_11 ? NULL : V_32 ;
return 0 ;
}
int F_54 ( int type , const struct V_55 T_2 * V_53 ,
unsigned V_21 , unsigned V_54 ,
struct V_10 * * V_11 , struct V_4 * V_5 )
{
T_3 V_43 ;
struct V_10 * V_32 ;
V_43 = F_55 ( type , V_53 , V_21 , V_54 ,
* V_11 , & V_32 ) ;
if ( V_43 < 0 ) {
if ( V_32 != * V_11 )
F_53 ( V_32 ) ;
* V_11 = NULL ;
return V_43 ;
}
F_19 ( V_5 , type , V_32 , V_21 , V_43 ) ;
* V_11 = V_32 == * V_11 ? NULL : V_32 ;
return 0 ;
}
int F_56 ( int V_56 , void T_2 * V_12 , T_1 V_30 ,
struct V_10 * V_11 , struct V_4 * V_5 )
{
if ( V_30 > V_57 )
V_30 = V_57 ;
if ( F_2 ( ! F_57 ( ! V_56 , V_12 , V_30 ) ) )
return - V_58 ;
V_11 -> V_17 = V_12 ;
V_11 -> V_18 = V_30 ;
F_19 ( V_5 , V_56 , V_11 , 1 , V_30 ) ;
return 0 ;
}
