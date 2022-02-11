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
void F_17 ( struct V_4 * V_5 , int V_24 ,
const struct V_10 * V_11 , unsigned long V_20 ,
T_1 V_15 )
{
if ( F_18 ( F_19 () , V_25 ) ) {
V_24 |= V_23 ;
V_5 -> type = V_24 ;
V_5 -> V_26 = (struct V_26 * ) V_11 ;
} else {
V_5 -> type = V_24 ;
V_5 -> V_11 = V_11 ;
}
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
static void F_20 ( char * V_21 , struct V_1 * V_1 , T_1 V_2 , T_1 V_27 )
{
char * V_14 = F_5 ( V_1 ) ;
memcpy ( V_21 , V_14 + V_2 , V_27 ) ;
F_8 ( V_14 ) ;
}
static void F_21 ( struct V_1 * V_1 , T_1 V_2 , char * V_14 , T_1 V_27 )
{
char * V_21 = F_5 ( V_1 ) ;
memcpy ( V_21 + V_2 , V_14 , V_27 ) ;
F_8 ( V_21 ) ;
}
static void F_22 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_27 )
{
char * V_28 = F_5 ( V_1 ) ;
memset ( V_28 + V_2 , 0 , V_27 ) ;
F_8 ( V_28 ) ;
}
T_1 F_23 ( void * V_28 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_14 = V_28 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_24 (i, bytes, v,
__copy_to_user(v.iov_base, (from += v.iov_len) - v.iov_len,
v.iov_len),
memcpy_to_page(v.bv_page, v.bv_offset,
(from += v.bv_len) - v.bv_len, v.bv_len),
memcpy(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len)
)
return V_3 ;
}
T_1 F_25 ( void * V_28 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_21 = V_28 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_24 (i, bytes, v,
__copy_from_user((to += v.iov_len) - v.iov_len, v.iov_base,
v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
T_1 F_26 ( void * V_28 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_21 = V_28 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_24 (i, bytes, v,
__copy_from_user_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
T_1 F_27 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & ( V_22 | V_23 ) ) {
void * V_13 = F_5 ( V_1 ) ;
T_1 V_9 = F_23 ( V_13 + V_2 , V_3 , V_5 ) ;
F_8 ( V_13 ) ;
return V_9 ;
} else
return F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_28 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & ( V_22 | V_23 ) ) {
void * V_13 = F_5 ( V_1 ) ;
T_1 V_9 = F_25 ( V_13 + V_2 , V_3 , V_5 ) ;
F_8 ( V_13 ) ;
return V_9 ;
} else
return F_12 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_29 ( T_1 V_3 , struct V_4 * V_5 )
{
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
F_24 (i, bytes, v,
__clear_user(v.iov_base, v.iov_len),
memzero_page(v.bv_page, v.bv_offset, v.bv_len),
memset(v.iov_base, 0, v.iov_len)
)
return V_3 ;
}
T_1 F_30 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 = F_5 ( V_1 ) , * V_29 = V_13 + V_2 ;
F_31 (i, bytes, v,
__copy_from_user_inatomic((p += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((p += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_8 ( V_13 ) ;
return V_3 ;
}
void F_32 ( struct V_4 * V_5 , T_1 V_30 )
{
F_24 (i, size, v, 0 , 0 , 0 )
}
T_1 F_33 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_20 == 1 )
return V_5 -> V_15 ;
else if ( V_5 -> type & V_22 )
return F_3 ( V_5 -> V_15 , V_5 -> V_31 -> V_32 - V_5 -> V_16 ) ;
else
return F_3 ( V_5 -> V_15 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
}
void F_34 ( struct V_4 * V_5 , int V_24 ,
const struct V_26 * V_26 , unsigned long V_20 ,
T_1 V_15 )
{
F_35 ( ! ( V_24 & V_23 ) ) ;
V_5 -> type = V_24 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
void F_36 ( struct V_4 * V_5 , int V_24 ,
const struct V_33 * V_31 , unsigned long V_20 ,
T_1 V_15 )
{
F_35 ( ! ( V_24 & V_22 ) ) ;
V_5 -> type = V_24 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
unsigned long F_37 ( const struct V_4 * V_5 )
{
unsigned long V_34 = 0 ;
T_1 V_30 = V_5 -> V_15 ;
if ( ! V_30 )
return 0 ;
F_31 (i, size, v,
(res |= (unsigned long)v.iov_base | v.iov_len, 0),
res |= v.bv_offset | v.bv_len,
res |= (unsigned long)v.iov_base | v.iov_len
)
return V_34 ;
}
T_3 F_38 ( struct V_4 * V_5 ,
struct V_1 * * V_35 , T_1 V_36 , unsigned V_37 ,
T_1 * V_38 )
{
if ( V_36 > V_5 -> V_15 )
V_36 = V_5 -> V_15 ;
if ( ! V_36 )
return 0 ;
F_31 (i, maxsize, v, ({
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
static struct V_1 * * F_39 ( T_1 V_39 )
{
struct V_1 * * V_29 = F_40 ( V_39 * sizeof( struct V_1 * ) , V_40 ) ;
if ( ! V_29 )
V_29 = F_41 ( V_39 * sizeof( struct V_1 * ) ) ;
return V_29 ;
}
T_3 F_42 ( struct V_4 * V_5 ,
struct V_1 * * * V_35 , T_1 V_36 ,
T_1 * V_38 )
{
struct V_1 * * V_29 ;
if ( V_36 > V_5 -> V_15 )
V_36 = V_5 -> V_15 ;
if ( ! V_36 )
return 0 ;
F_31 (i, maxsize, v, ({
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
T_1 F_43 ( void * V_28 , T_1 V_3 , T_4 * V_41 ,
struct V_4 * V_5 )
{
char * V_21 = V_28 ;
T_4 V_42 , V_43 ;
T_1 V_44 = 0 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_42 = * V_41 ;
F_24 (i, bytes, v, ({
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
* V_41 = V_42 ;
return V_3 ;
}
T_1 F_44 ( void * V_28 , T_1 V_3 , T_4 * V_41 ,
struct V_4 * V_5 )
{
char * V_14 = V_28 ;
T_4 V_42 , V_43 ;
T_1 V_44 = 0 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_42 = * V_41 ;
F_24 (i, bytes, v, ({
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
* V_41 = V_42 ;
return V_3 ;
}
int F_45 ( const struct V_4 * V_5 , int V_37 )
{
T_1 V_30 = V_5 -> V_15 ;
int V_45 = 0 ;
if ( ! V_30 )
return 0 ;
F_31 (i, size, v, ({
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
return V_45 ;
}
const void * F_46 ( struct V_4 * V_46 , struct V_4 * V_47 , T_5 V_48 )
{
* V_46 = * V_47 ;
if ( V_46 -> type & V_22 )
return V_46 -> V_31 = F_47 ( V_46 -> V_31 ,
V_46 -> V_20 * sizeof( struct V_33 ) ,
V_48 ) ;
else
return V_46 -> V_11 = F_47 ( V_46 -> V_11 ,
V_46 -> V_20 * sizeof( struct V_10 ) ,
V_48 ) ;
}
