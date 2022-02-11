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
static bool F_17 ( const struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
int V_25 = V_5 -> V_25 ;
int V_26 = V_24 -> V_27 + V_24 -> V_28 ;
if ( V_5 -> V_16 ) {
struct V_29 * V_30 ;
if ( F_2 ( ! V_24 -> V_28 ) )
goto V_31;
if ( F_2 ( V_25 != ( ( V_26 - 1 ) & ( V_24 -> V_32 - 1 ) ) ) )
goto V_31;
V_30 = & V_24 -> V_33 [ V_25 ] ;
if ( F_2 ( V_30 -> V_2 + V_30 -> V_34 != V_5 -> V_16 ) )
goto V_31;
} else {
if ( V_25 != ( V_26 & ( V_24 -> V_32 - 1 ) ) )
goto V_31;
}
return true ;
V_31:
F_18 ( V_35 L_1 , V_5 -> V_25 , V_5 -> V_16 ) ;
F_18 ( V_35 L_2 ,
V_24 -> V_27 , V_24 -> V_28 , V_24 -> V_32 ) ;
for ( V_25 = 0 ; V_25 < V_24 -> V_32 ; V_25 ++ )
F_18 ( V_35 L_3 ,
V_24 -> V_33 [ V_25 ] . V_36 ,
V_24 -> V_33 [ V_25 ] . V_1 ,
V_24 -> V_33 [ V_25 ] . V_2 ,
V_24 -> V_33 [ V_25 ] . V_34 ) ;
F_19 ( 1 ) ;
return false ;
}
static inline int F_20 ( int V_25 , struct V_23 * V_24 )
{
return ( V_25 + 1 ) & ( V_24 -> V_32 - 1 ) ;
}
static T_1 F_21 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
struct V_29 * V_12 ;
T_1 V_37 ;
int V_25 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
if ( ! F_17 ( V_5 ) )
return 0 ;
V_37 = V_5 -> V_16 ;
V_25 = V_5 -> V_25 ;
V_12 = & V_24 -> V_33 [ V_25 ] ;
if ( V_37 ) {
if ( V_2 == V_37 && V_12 -> V_1 == V_1 ) {
V_12 -> V_34 += V_3 ;
V_5 -> V_16 += V_3 ;
goto V_38;
}
V_25 = F_20 ( V_25 , V_24 ) ;
V_12 = & V_24 -> V_33 [ V_25 ] ;
}
if ( V_25 == V_24 -> V_27 && V_24 -> V_28 )
return 0 ;
V_24 -> V_28 ++ ;
V_12 -> V_36 = & V_39 ;
F_22 ( V_12 -> V_1 = V_1 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_34 = V_3 ;
V_5 -> V_16 = V_2 + V_3 ;
V_5 -> V_25 = V_25 ;
V_38:
V_5 -> V_15 -= V_3 ;
return V_3 ;
}
int F_23 ( struct V_4 * V_5 , T_1 V_3 )
{
T_1 V_6 = V_5 -> V_16 ;
const struct V_10 * V_11 ;
int V_40 ;
struct V_10 V_41 ;
if ( ! ( V_5 -> type & ( V_42 | V_43 ) ) ) {
F_24 (i, bytes, v, iov, skip, ({
err = fault_in_pages_readable(v.iov_base, v.iov_len);
if (unlikely(err))
return err;
0;}))
}
return 0 ;
}
void F_25 ( struct V_4 * V_5 , int V_44 ,
const struct V_10 * V_11 , unsigned long V_21 ,
T_1 V_15 )
{
if ( F_26 () ) {
V_44 |= V_43 ;
V_5 -> type = V_44 ;
V_5 -> V_45 = (struct V_45 * ) V_11 ;
} else {
V_5 -> type = V_44 ;
V_5 -> V_11 = V_11 ;
}
V_5 -> V_21 = V_21 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
static void F_27 ( char * V_22 , struct V_1 * V_1 , T_1 V_2 , T_1 V_34 )
{
char * V_14 = F_6 ( V_1 ) ;
memcpy ( V_22 , V_14 + V_2 , V_34 ) ;
F_9 ( V_14 ) ;
}
static void F_28 ( struct V_1 * V_1 , T_1 V_2 , const char * V_14 , T_1 V_34 )
{
char * V_22 = F_6 ( V_1 ) ;
memcpy ( V_22 + V_2 , V_14 , V_34 ) ;
F_9 ( V_22 ) ;
}
static void F_29 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_34 )
{
char * V_46 = F_6 ( V_1 ) ;
memset ( V_46 + V_2 , 0 , V_34 ) ;
F_9 ( V_46 ) ;
}
static inline bool F_30 ( struct V_29 * V_12 )
{
return V_12 -> V_36 == & V_47 ;
}
static inline void F_31 ( const struct V_4 * V_5 , int * V_48 , T_1 * V_49 )
{
T_1 V_37 = V_5 -> V_16 ;
int V_25 = V_5 -> V_25 ;
if ( V_37 && ( ! F_30 ( & V_5 -> V_24 -> V_33 [ V_25 ] ) || V_37 == V_50 ) ) {
V_25 = F_20 ( V_25 , V_5 -> V_24 ) ;
V_37 = 0 ;
}
* V_48 = V_25 ;
* V_49 = V_37 ;
}
static T_1 F_32 ( struct V_4 * V_5 , T_1 V_51 ,
int * V_48 , T_1 * V_49 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
T_1 V_37 ;
int V_25 ;
T_3 V_8 ;
if ( F_2 ( V_51 > V_5 -> V_15 ) )
V_51 = V_5 -> V_15 ;
if ( F_2 ( ! V_51 ) )
return 0 ;
V_8 = V_51 ;
F_31 ( V_5 , & V_25 , & V_37 ) ;
* V_48 = V_25 ;
* V_49 = V_37 ;
if ( V_37 ) {
V_8 -= V_50 - V_37 ;
if ( V_8 <= 0 ) {
V_24 -> V_33 [ V_25 ] . V_34 += V_51 ;
return V_51 ;
}
V_24 -> V_33 [ V_25 ] . V_34 = V_50 ;
V_25 = F_20 ( V_25 , V_24 ) ;
}
while ( V_25 != V_24 -> V_27 || ! V_24 -> V_28 ) {
struct V_1 * V_1 = F_33 ( V_52 ) ;
if ( ! V_1 )
break;
V_24 -> V_28 ++ ;
V_24 -> V_33 [ V_25 ] . V_36 = & V_47 ;
V_24 -> V_33 [ V_25 ] . V_1 = V_1 ;
V_24 -> V_33 [ V_25 ] . V_2 = 0 ;
if ( V_8 <= V_50 ) {
V_24 -> V_33 [ V_25 ] . V_34 = V_8 ;
return V_51 ;
}
V_24 -> V_33 [ V_25 ] . V_34 = V_50 ;
V_8 -= V_50 ;
V_25 = F_20 ( V_25 , V_24 ) ;
}
return V_51 - V_8 ;
}
static T_1 F_34 ( const void * V_46 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
T_1 V_53 , V_37 ;
int V_25 ;
if ( ! F_17 ( V_5 ) )
return 0 ;
V_3 = V_53 = F_32 ( V_5 , V_3 , & V_25 , & V_37 ) ;
if ( F_2 ( ! V_53 ) )
return 0 ;
for ( ; V_53 ; V_25 = F_20 ( V_25 , V_24 ) , V_37 = 0 ) {
T_1 V_54 = F_35 ( T_1 , V_53 , V_50 - V_37 ) ;
F_28 ( V_24 -> V_33 [ V_25 ] . V_1 , V_37 , V_46 , V_54 ) ;
V_5 -> V_25 = V_25 ;
V_5 -> V_16 = V_37 + V_54 ;
V_53 -= V_54 ;
V_46 += V_54 ;
}
V_5 -> V_15 -= V_3 ;
return V_3 ;
}
T_1 F_36 ( const void * V_46 , T_1 V_3 , struct V_4 * V_5 )
{
const char * V_14 = V_46 ;
if ( F_2 ( V_5 -> type & V_55 ) )
return F_34 ( V_46 , V_3 , V_5 ) ;
F_37 (i, bytes, v,
__copy_to_user(v.iov_base, (from += v.iov_len) - v.iov_len,
v.iov_len),
memcpy_to_page(v.bv_page, v.bv_offset,
(from += v.bv_len) - v.bv_len, v.bv_len),
memcpy(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len)
)
return V_3 ;
}
T_1 F_38 ( void * V_46 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_22 = V_46 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return 0 ;
}
F_37 (i, bytes, v,
__copy_from_user((to += v.iov_len) - v.iov_len, v.iov_base,
v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
bool F_39 ( void * V_46 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_22 = V_46 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return false ;
}
if ( F_2 ( V_5 -> V_15 < V_3 ) )
return false ;
F_40 (i, bytes, v, ({
if (__copy_from_user((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len))
return false;
0;}),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_41 ( V_5 , V_3 ) ;
return true ;
}
T_1 F_42 ( void * V_46 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_22 = V_46 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return 0 ;
}
F_37 (i, bytes, v,
__copy_from_user_inatomic_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_3 ;
}
bool F_43 ( void * V_46 , T_1 V_3 , struct V_4 * V_5 )
{
char * V_22 = V_46 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return false ;
}
if ( F_2 ( V_5 -> V_15 < V_3 ) )
return false ;
F_40 (i, bytes, v, ({
if (__copy_from_user_inatomic_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len))
return false;
0;}),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_41 ( V_5 , V_3 ) ;
return true ;
}
T_1 F_44 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 -> type & ( V_42 | V_43 ) ) {
void * V_13 = F_6 ( V_1 ) ;
T_1 V_9 = F_36 ( V_13 + V_2 , V_3 , V_5 ) ;
F_9 ( V_13 ) ;
return V_9 ;
} else if ( F_8 ( ! ( V_5 -> type & V_55 ) ) )
return F_1 ( V_1 , V_2 , V_3 , V_5 ) ;
else
return F_21 ( V_1 , V_2 , V_3 , V_5 ) ;
}
T_1 F_45 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return 0 ;
}
if ( V_5 -> type & ( V_42 | V_43 ) ) {
void * V_13 = F_6 ( V_1 ) ;
T_1 V_9 = F_38 ( V_13 + V_2 , V_3 , V_5 ) ;
F_9 ( V_13 ) ;
return V_9 ;
} else
return F_13 ( V_1 , V_2 , V_3 , V_5 ) ;
}
static T_1 F_46 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
T_1 V_53 , V_37 ;
int V_25 ;
if ( ! F_17 ( V_5 ) )
return 0 ;
V_3 = V_53 = F_32 ( V_5 , V_3 , & V_25 , & V_37 ) ;
if ( F_2 ( ! V_53 ) )
return 0 ;
for ( ; V_53 ; V_25 = F_20 ( V_25 , V_24 ) , V_37 = 0 ) {
T_1 V_54 = F_35 ( T_1 , V_53 , V_50 - V_37 ) ;
F_29 ( V_24 -> V_33 [ V_25 ] . V_1 , V_37 , V_54 ) ;
V_5 -> V_25 = V_25 ;
V_5 -> V_16 = V_37 + V_54 ;
V_53 -= V_54 ;
}
V_5 -> V_15 -= V_3 ;
return V_3 ;
}
T_1 F_47 ( T_1 V_3 , struct V_4 * V_5 )
{
if ( F_2 ( V_5 -> type & V_55 ) )
return F_46 ( V_3 , V_5 ) ;
F_37 (i, bytes, v,
__clear_user(v.iov_base, v.iov_len),
memzero_page(v.bv_page, v.bv_offset, v.bv_len),
memset(v.iov_base, 0, v.iov_len)
)
return V_3 ;
}
T_1 F_48 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 = F_6 ( V_1 ) , * V_30 = V_13 + V_2 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_9 ( V_13 ) ;
F_19 ( 1 ) ;
return 0 ;
}
F_40 (i, bytes, v,
__copy_from_user_inatomic((p += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((p += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_9 ( V_13 ) ;
return V_3 ;
}
static inline void F_49 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
if ( V_24 -> V_28 ) {
T_1 V_37 = V_5 -> V_16 ;
int V_25 = V_5 -> V_25 ;
int V_28 = ( V_25 - V_24 -> V_27 ) & ( V_24 -> V_32 - 1 ) ;
if ( V_37 ) {
V_24 -> V_33 [ V_25 ] . V_34 = V_37 - V_24 -> V_33 [ V_25 ] . V_2 ;
V_25 = F_20 ( V_25 , V_24 ) ;
V_28 ++ ;
}
while ( V_24 -> V_28 > V_28 ) {
F_50 ( V_24 , & V_24 -> V_33 [ V_25 ] ) ;
V_25 = F_20 ( V_25 , V_24 ) ;
V_24 -> V_28 -- ;
}
}
}
static void F_51 ( struct V_4 * V_5 , T_1 V_51 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
if ( F_2 ( V_5 -> V_15 < V_51 ) )
V_51 = V_5 -> V_15 ;
if ( V_51 ) {
struct V_29 * V_12 ;
T_1 V_37 = V_5 -> V_16 , V_8 = V_51 ;
int V_25 = V_5 -> V_25 ;
if ( V_37 )
V_8 += V_37 - V_24 -> V_33 [ V_25 ] . V_2 ;
while ( 1 ) {
V_12 = & V_24 -> V_33 [ V_25 ] ;
if ( V_8 <= V_12 -> V_34 )
break;
V_8 -= V_12 -> V_34 ;
V_25 = F_20 ( V_25 , V_24 ) ;
}
V_5 -> V_25 = V_25 ;
V_5 -> V_16 = V_12 -> V_2 + V_8 ;
}
V_5 -> V_15 -= V_51 ;
F_49 ( V_5 ) ;
}
void F_41 ( struct V_4 * V_5 , T_1 V_51 )
{
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_51 ( V_5 , V_51 ) ;
return;
}
F_37 (i, size, v, 0 , 0 , 0 )
}
void F_52 ( struct V_4 * V_5 , T_1 V_56 )
{
if ( ! V_56 )
return;
if ( F_19 ( V_56 > V_57 ) )
return;
V_5 -> V_15 += V_56 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
struct V_23 * V_24 = V_5 -> V_24 ;
int V_25 = V_5 -> V_25 ;
T_1 V_37 = V_5 -> V_16 ;
while ( 1 ) {
T_1 V_53 = V_37 - V_24 -> V_33 [ V_25 ] . V_2 ;
if ( V_56 < V_53 ) {
V_37 -= V_56 ;
break;
}
V_56 -= V_53 ;
if ( ! V_56 && V_25 == V_5 -> V_58 ) {
V_37 = 0 ;
break;
}
if ( ! V_25 -- )
V_25 = V_24 -> V_32 - 1 ;
V_37 = V_24 -> V_33 [ V_25 ] . V_2 + V_24 -> V_33 [ V_25 ] . V_34 ;
}
V_5 -> V_16 = V_37 ;
V_5 -> V_25 = V_25 ;
F_49 ( V_5 ) ;
return;
}
if ( V_56 <= V_5 -> V_16 ) {
V_5 -> V_16 -= V_56 ;
return;
}
V_56 -= V_5 -> V_16 ;
if ( V_5 -> type & V_42 ) {
const struct V_59 * V_60 = V_5 -> V_60 ;
while ( 1 ) {
T_1 V_53 = ( -- V_60 ) -> V_61 ;
V_5 -> V_21 ++ ;
if ( V_56 <= V_53 ) {
V_5 -> V_60 = V_60 ;
V_5 -> V_16 = V_53 - V_56 ;
return;
}
V_56 -= V_53 ;
}
} else {
const struct V_10 * V_11 = V_5 -> V_11 ;
while ( 1 ) {
T_1 V_53 = ( -- V_11 ) -> V_18 ;
V_5 -> V_21 ++ ;
if ( V_56 <= V_53 ) {
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_53 - V_56 ;
return;
}
V_56 -= V_53 ;
}
}
}
T_1 F_53 ( const struct V_4 * V_5 )
{
if ( F_2 ( V_5 -> type & V_55 ) )
return V_5 -> V_15 ;
if ( V_5 -> V_21 == 1 )
return V_5 -> V_15 ;
else if ( V_5 -> type & V_42 )
return F_3 ( V_5 -> V_15 , V_5 -> V_60 -> V_61 - V_5 -> V_16 ) ;
else
return F_3 ( V_5 -> V_15 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
}
void F_54 ( struct V_4 * V_5 , int V_44 ,
const struct V_45 * V_45 , unsigned long V_21 ,
T_1 V_15 )
{
F_55 ( ! ( V_44 & V_43 ) ) ;
V_5 -> type = V_44 ;
V_5 -> V_45 = V_45 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
void F_56 ( struct V_4 * V_5 , int V_44 ,
const struct V_59 * V_60 , unsigned long V_21 ,
T_1 V_15 )
{
F_55 ( ! ( V_44 & V_42 ) ) ;
V_5 -> type = V_44 ;
V_5 -> V_60 = V_60 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
}
void F_57 ( struct V_4 * V_5 , int V_44 ,
struct V_23 * V_24 ,
T_1 V_15 )
{
F_55 ( V_44 != V_55 ) ;
F_19 ( V_24 -> V_28 == V_24 -> V_32 ) ;
V_5 -> type = V_44 ;
V_5 -> V_24 = V_24 ;
V_5 -> V_25 = ( V_24 -> V_27 + V_24 -> V_28 ) & ( V_24 -> V_32 - 1 ) ;
V_5 -> V_16 = 0 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_58 = V_5 -> V_25 ;
}
unsigned long F_58 ( const struct V_4 * V_5 )
{
unsigned long V_62 = 0 ;
T_1 V_51 = V_5 -> V_15 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
if ( V_51 && V_5 -> V_16 && F_30 ( & V_5 -> V_24 -> V_33 [ V_5 -> V_25 ] ) )
return V_51 | V_5 -> V_16 ;
return V_51 ;
}
F_40 (i, size, v,
(res |= (unsigned long)v.iov_base | v.iov_len, 0),
res |= v.bv_offset | v.bv_len,
res |= (unsigned long)v.iov_base | v.iov_len
)
return V_62 ;
}
unsigned long F_59 ( const struct V_4 * V_5 )
{
unsigned long V_62 = 0 ;
T_1 V_51 = V_5 -> V_15 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return ~ 0U ;
}
F_40 ( V_5 , V_51 , V_41 ,
( V_62 |= ( ! V_62 ? 0 : ( unsigned long ) V_41 . V_17 ) |
( V_51 != V_41 . V_18 ? V_51 : 0 ) , 0 ) ,
( V_62 |= ( ! V_62 ? 0 : ( unsigned long ) V_41 . V_63 ) |
( V_51 != V_41 . V_61 ? V_51 : 0 ) ) ,
( V_62 |= ( ! V_62 ? 0 : ( unsigned long ) V_41 . V_17 ) |
( V_51 != V_41 . V_18 ? V_51 : 0 ) )
) ;
return V_62 ;
}
static inline T_1 F_60 ( struct V_4 * V_5 ,
T_1 V_64 ,
struct V_1 * * V_65 ,
int V_25 ,
T_1 * V_66 )
{
struct V_23 * V_24 = V_5 -> V_24 ;
T_3 V_53 = F_32 ( V_5 , V_64 , & V_25 , V_66 ) ;
if ( ! V_53 )
return - V_67 ;
V_64 = V_53 ;
V_53 += * V_66 ;
while ( V_53 > 0 ) {
F_22 ( * V_65 ++ = V_24 -> V_33 [ V_25 ] . V_1 ) ;
V_25 = F_20 ( V_25 , V_24 ) ;
V_53 -= V_50 ;
}
return V_64 ;
}
static T_3 F_61 ( struct V_4 * V_5 ,
struct V_1 * * V_65 , T_1 V_64 , unsigned V_68 ,
T_1 * V_66 )
{
unsigned V_69 ;
T_1 V_70 ;
int V_25 ;
if ( ! V_64 )
return 0 ;
if ( ! F_17 ( V_5 ) )
return - V_67 ;
F_31 ( V_5 , & V_25 , V_66 ) ;
V_69 = ( ( V_5 -> V_24 -> V_27 - V_25 - 1 ) & ( V_5 -> V_24 -> V_32 - 1 ) ) + 1 ;
V_70 = F_3 ( V_69 , V_68 ) * V_50 - * V_66 ;
return F_60 ( V_5 , F_3 ( V_64 , V_70 ) , V_65 , V_25 , V_66 ) ;
}
T_3 F_62 ( struct V_4 * V_5 ,
struct V_1 * * V_65 , T_1 V_64 , unsigned V_68 ,
T_1 * V_66 )
{
if ( V_64 > V_5 -> V_15 )
V_64 = V_5 -> V_15 ;
if ( F_2 ( V_5 -> type & V_55 ) )
return F_61 ( V_5 , V_65 , V_64 , V_68 , V_66 ) ;
F_40 (i, maxsize, v, ({
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
static struct V_1 * * F_63 ( T_1 V_53 )
{
return F_64 ( V_53 , sizeof( struct V_1 * ) , V_71 ) ;
}
static T_3 F_65 ( struct V_4 * V_5 ,
struct V_1 * * * V_65 , T_1 V_64 ,
T_1 * V_66 )
{
struct V_1 * * V_30 ;
T_1 V_53 ;
int V_25 ;
int V_69 ;
if ( ! V_64 )
return 0 ;
if ( ! F_17 ( V_5 ) )
return - V_67 ;
F_31 ( V_5 , & V_25 , V_66 ) ;
V_69 = ( ( V_5 -> V_24 -> V_27 - V_25 - 1 ) & ( V_5 -> V_24 -> V_32 - 1 ) ) + 1 ;
V_53 = V_69 * V_50 - * V_66 ;
if ( V_64 > V_53 )
V_64 = V_53 ;
else
V_69 = F_66 ( V_64 + * V_66 , V_50 ) ;
V_30 = F_63 ( V_69 ) ;
if ( ! V_30 )
return - V_72 ;
V_53 = F_60 ( V_5 , V_64 , V_30 , V_25 , V_66 ) ;
if ( V_53 > 0 )
* V_65 = V_30 ;
else
F_67 ( V_30 ) ;
return V_53 ;
}
T_3 F_68 ( struct V_4 * V_5 ,
struct V_1 * * * V_65 , T_1 V_64 ,
T_1 * V_66 )
{
struct V_1 * * V_30 ;
if ( V_64 > V_5 -> V_15 )
V_64 = V_5 -> V_15 ;
if ( F_2 ( V_5 -> type & V_55 ) )
return F_65 ( V_5 , V_65 , V_64 , V_66 ) ;
F_40 (i, maxsize, v, ({
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
T_1 F_69 ( void * V_46 , T_1 V_3 , T_4 * V_73 ,
struct V_4 * V_5 )
{
char * V_22 = V_46 ;
T_4 V_74 , V_26 ;
T_1 V_37 = 0 ;
V_74 = * V_73 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return 0 ;
}
F_37 (i, bytes, v, ({
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
* V_73 = V_74 ;
return V_3 ;
}
bool F_70 ( void * V_46 , T_1 V_3 , T_4 * V_73 ,
struct V_4 * V_5 )
{
char * V_22 = V_46 ;
T_4 V_74 , V_26 ;
T_1 V_37 = 0 ;
V_74 = * V_73 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return false ;
}
if ( F_2 ( V_5 -> V_15 < V_3 ) )
return false ;
F_40 (i, bytes, v, ({
int err = 0;
next = csum_and_copy_from_user(v.iov_base,
(to += v.iov_len) - v.iov_len,
v.iov_len, 0, &err);
if (err)
return false;
sum = csum_block_add(sum, next, off);
off += v.iov_len;
0;
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
* V_73 = V_74 ;
F_41 ( V_5 , V_3 ) ;
return true ;
}
T_1 F_71 ( const void * V_46 , T_1 V_3 , T_4 * V_73 ,
struct V_4 * V_5 )
{
const char * V_14 = V_46 ;
T_4 V_74 , V_26 ;
T_1 V_37 = 0 ;
V_74 = * V_73 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return 0 ;
}
F_37 (i, bytes, v, ({
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
* V_73 = V_74 ;
return V_3 ;
}
int F_72 ( const struct V_4 * V_5 , int V_68 )
{
T_1 V_51 = V_5 -> V_15 ;
int V_69 = 0 ;
if ( ! V_51 )
return 0 ;
if ( F_2 ( V_5 -> type & V_55 ) ) {
struct V_23 * V_24 = V_5 -> V_24 ;
T_1 V_37 ;
int V_25 ;
if ( ! F_17 ( V_5 ) )
return 0 ;
F_31 ( V_5 , & V_25 , & V_37 ) ;
V_69 = ( ( V_24 -> V_27 - V_25 - 1 ) & ( V_24 -> V_32 - 1 ) ) + 1 ;
if ( V_69 >= V_68 )
return V_68 ;
} else F_40 (i, size, v, ({
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
return V_69 ;
}
const void * F_73 ( struct V_4 * V_75 , struct V_4 * V_76 , T_5 V_77 )
{
* V_75 = * V_76 ;
if ( F_2 ( V_75 -> type & V_55 ) ) {
F_19 ( 1 ) ;
return NULL ;
}
if ( V_75 -> type & V_42 )
return V_75 -> V_60 = F_74 ( V_75 -> V_60 ,
V_75 -> V_21 * sizeof( struct V_59 ) ,
V_77 ) ;
else
return V_75 -> V_11 = F_74 ( V_75 -> V_11 ,
V_75 -> V_21 * sizeof( struct V_10 ) ,
V_77 ) ;
}
int F_75 ( int type , const struct V_10 T_2 * V_78 ,
unsigned V_21 , unsigned V_79 ,
struct V_10 * * V_11 , struct V_4 * V_5 )
{
T_3 V_53 ;
struct V_10 * V_30 ;
V_53 = F_76 ( type , V_78 , V_21 , V_79 ,
* V_11 , & V_30 ) ;
if ( V_53 < 0 ) {
if ( V_30 != * V_11 )
F_77 ( V_30 ) ;
* V_11 = NULL ;
return V_53 ;
}
F_25 ( V_5 , type , V_30 , V_21 , V_53 ) ;
* V_11 = V_30 == * V_11 ? NULL : V_30 ;
return 0 ;
}
int F_78 ( int type , const struct V_80 T_2 * V_78 ,
unsigned V_21 , unsigned V_79 ,
struct V_10 * * V_11 , struct V_4 * V_5 )
{
T_3 V_53 ;
struct V_10 * V_30 ;
V_53 = F_79 ( type , V_78 , V_21 , V_79 ,
* V_11 , & V_30 ) ;
if ( V_53 < 0 ) {
if ( V_30 != * V_11 )
F_77 ( V_30 ) ;
* V_11 = NULL ;
return V_53 ;
}
F_25 ( V_5 , type , V_30 , V_21 , V_53 ) ;
* V_11 = V_30 == * V_11 ? NULL : V_30 ;
return 0 ;
}
int F_80 ( int V_81 , void T_2 * V_12 , T_1 V_34 ,
struct V_10 * V_11 , struct V_4 * V_5 )
{
if ( V_34 > V_57 )
V_34 = V_57 ;
if ( F_2 ( ! F_81 ( ! V_81 , V_12 , V_34 ) ) )
return - V_67 ;
V_11 -> V_17 = V_12 ;
V_11 -> V_18 = V_34 ;
F_25 ( V_5 , V_81 , V_11 , 1 , V_34 ) ;
return 0 ;
}
