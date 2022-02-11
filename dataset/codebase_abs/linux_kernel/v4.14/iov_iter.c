static int F_1 ( void T_1 * V_1 , const void * V_2 , T_2 V_3 )
{
if ( F_2 ( V_4 , V_1 , V_3 ) ) {
F_3 ( V_2 , V_3 ) ;
V_3 = F_4 ( V_1 , V_2 , V_3 ) ;
}
return V_3 ;
}
static int F_5 ( void * V_1 , const void T_1 * V_2 , T_2 V_3 )
{
if ( F_2 ( V_5 , V_2 , V_3 ) ) {
F_6 ( V_1 , V_3 ) ;
V_3 = F_7 ( V_1 , V_2 , V_3 ) ;
}
return V_3 ;
}
static T_2 F_8 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 , V_12 , V_13 , V_14 ;
const struct V_15 * V_16 ;
char T_1 * V_17 ;
void * V_18 , * V_2 ;
if ( F_9 ( V_8 > V_10 -> V_19 ) )
V_8 = V_10 -> V_19 ;
if ( F_9 ( ! V_8 ) )
return 0 ;
F_10 () ;
V_14 = V_8 ;
V_16 = V_10 -> V_16 ;
V_11 = V_10 -> V_20 ;
V_17 = V_16 -> V_21 + V_11 ;
V_12 = F_11 ( V_8 , V_16 -> V_22 - V_11 ) ;
if ( F_12 ( V_23 ) && ! F_13 ( V_17 , V_12 ) ) {
V_18 = F_14 ( V_6 ) ;
V_2 = V_18 + V_7 ;
V_13 = F_1 ( V_17 , V_2 , V_12 ) ;
V_12 -= V_13 ;
V_11 += V_12 ;
V_2 += V_12 ;
V_8 -= V_12 ;
while ( F_9 ( ! V_13 && V_8 ) ) {
V_16 ++ ;
V_17 = V_16 -> V_21 ;
V_12 = F_11 ( V_8 , V_16 -> V_22 ) ;
V_13 = F_1 ( V_17 , V_2 , V_12 ) ;
V_12 -= V_13 ;
V_11 = V_12 ;
V_2 += V_12 ;
V_8 -= V_12 ;
}
if ( F_15 ( ! V_8 ) ) {
F_16 ( V_18 ) ;
goto V_24;
}
V_7 = V_2 - V_18 ;
V_17 += V_12 ;
F_16 ( V_18 ) ;
V_12 = F_11 ( V_8 , V_16 -> V_22 - V_11 ) ;
}
V_18 = F_17 ( V_6 ) ;
V_2 = V_18 + V_7 ;
V_13 = F_1 ( V_17 , V_2 , V_12 ) ;
V_12 -= V_13 ;
V_11 += V_12 ;
V_2 += V_12 ;
V_8 -= V_12 ;
while ( F_9 ( ! V_13 && V_8 ) ) {
V_16 ++ ;
V_17 = V_16 -> V_21 ;
V_12 = F_11 ( V_8 , V_16 -> V_22 ) ;
V_13 = F_1 ( V_17 , V_2 , V_12 ) ;
V_12 -= V_13 ;
V_11 = V_12 ;
V_2 += V_12 ;
V_8 -= V_12 ;
}
F_18 ( V_6 ) ;
V_24:
if ( V_11 == V_16 -> V_22 ) {
V_16 ++ ;
V_11 = 0 ;
}
V_10 -> V_19 -= V_14 - V_8 ;
V_10 -> V_25 -= V_16 - V_10 -> V_16 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_20 = V_11 ;
return V_14 - V_8 ;
}
static T_2 F_19 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 , V_12 , V_13 , V_14 ;
const struct V_15 * V_16 ;
char T_1 * V_17 ;
void * V_18 , * V_1 ;
if ( F_9 ( V_8 > V_10 -> V_19 ) )
V_8 = V_10 -> V_19 ;
if ( F_9 ( ! V_8 ) )
return 0 ;
F_10 () ;
V_14 = V_8 ;
V_16 = V_10 -> V_16 ;
V_11 = V_10 -> V_20 ;
V_17 = V_16 -> V_21 + V_11 ;
V_12 = F_11 ( V_8 , V_16 -> V_22 - V_11 ) ;
if ( F_12 ( V_23 ) && ! F_20 ( V_17 , V_12 ) ) {
V_18 = F_14 ( V_6 ) ;
V_1 = V_18 + V_7 ;
V_13 = F_5 ( V_1 , V_17 , V_12 ) ;
V_12 -= V_13 ;
V_11 += V_12 ;
V_1 += V_12 ;
V_8 -= V_12 ;
while ( F_9 ( ! V_13 && V_8 ) ) {
V_16 ++ ;
V_17 = V_16 -> V_21 ;
V_12 = F_11 ( V_8 , V_16 -> V_22 ) ;
V_13 = F_5 ( V_1 , V_17 , V_12 ) ;
V_12 -= V_13 ;
V_11 = V_12 ;
V_1 += V_12 ;
V_8 -= V_12 ;
}
if ( F_15 ( ! V_8 ) ) {
F_16 ( V_18 ) ;
goto V_24;
}
V_7 = V_1 - V_18 ;
V_17 += V_12 ;
F_16 ( V_18 ) ;
V_12 = F_11 ( V_8 , V_16 -> V_22 - V_11 ) ;
}
V_18 = F_17 ( V_6 ) ;
V_1 = V_18 + V_7 ;
V_13 = F_5 ( V_1 , V_17 , V_12 ) ;
V_12 -= V_13 ;
V_11 += V_12 ;
V_1 += V_12 ;
V_8 -= V_12 ;
while ( F_9 ( ! V_13 && V_8 ) ) {
V_16 ++ ;
V_17 = V_16 -> V_21 ;
V_12 = F_11 ( V_8 , V_16 -> V_22 ) ;
V_13 = F_5 ( V_1 , V_17 , V_12 ) ;
V_12 -= V_13 ;
V_11 = V_12 ;
V_1 += V_12 ;
V_8 -= V_12 ;
}
F_18 ( V_6 ) ;
V_24:
if ( V_11 == V_16 -> V_22 ) {
V_16 ++ ;
V_11 = 0 ;
}
V_10 -> V_19 -= V_14 - V_8 ;
V_10 -> V_25 -= V_16 - V_10 -> V_16 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_20 = V_11 ;
return V_14 - V_8 ;
}
static bool F_21 ( const struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
int V_28 = V_10 -> V_28 ;
int V_29 = V_27 -> V_30 + V_27 -> V_31 ;
if ( V_10 -> V_20 ) {
struct V_32 * V_33 ;
if ( F_9 ( ! V_27 -> V_31 ) )
goto V_34;
if ( F_9 ( V_28 != ( ( V_29 - 1 ) & ( V_27 -> V_35 - 1 ) ) ) )
goto V_34;
V_33 = & V_27 -> V_36 [ V_28 ] ;
if ( F_9 ( V_33 -> V_7 + V_33 -> V_37 != V_10 -> V_20 ) )
goto V_34;
} else {
if ( V_28 != ( V_29 & ( V_27 -> V_35 - 1 ) ) )
goto V_34;
}
return true ;
V_34:
F_22 ( V_38 L_1 , V_10 -> V_28 , V_10 -> V_20 ) ;
F_22 ( V_38 L_2 ,
V_27 -> V_30 , V_27 -> V_31 , V_27 -> V_35 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_35 ; V_28 ++ )
F_22 ( V_38 L_3 ,
V_27 -> V_36 [ V_28 ] . V_39 ,
V_27 -> V_36 [ V_28 ] . V_6 ,
V_27 -> V_36 [ V_28 ] . V_7 ,
V_27 -> V_36 [ V_28 ] . V_37 ) ;
F_23 ( 1 ) ;
return false ;
}
static inline int F_24 ( int V_28 , struct V_26 * V_27 )
{
return ( V_28 + 1 ) & ( V_27 -> V_35 - 1 ) ;
}
static T_2 F_25 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
struct V_32 * V_17 ;
T_2 V_40 ;
int V_28 ;
if ( F_9 ( V_8 > V_10 -> V_19 ) )
V_8 = V_10 -> V_19 ;
if ( F_9 ( ! V_8 ) )
return 0 ;
if ( ! F_21 ( V_10 ) )
return 0 ;
V_40 = V_10 -> V_20 ;
V_28 = V_10 -> V_28 ;
V_17 = & V_27 -> V_36 [ V_28 ] ;
if ( V_40 ) {
if ( V_7 == V_40 && V_17 -> V_6 == V_6 ) {
V_17 -> V_37 += V_8 ;
V_10 -> V_20 += V_8 ;
goto V_41;
}
V_28 = F_24 ( V_28 , V_27 ) ;
V_17 = & V_27 -> V_36 [ V_28 ] ;
}
if ( V_28 == V_27 -> V_30 && V_27 -> V_31 )
return 0 ;
V_27 -> V_31 ++ ;
V_17 -> V_39 = & V_42 ;
F_26 ( V_17 -> V_6 = V_6 ) ;
V_17 -> V_7 = V_7 ;
V_17 -> V_37 = V_8 ;
V_10 -> V_20 = V_7 + V_8 ;
V_10 -> V_28 = V_28 ;
V_41:
V_10 -> V_19 -= V_8 ;
return V_8 ;
}
int F_27 ( struct V_9 * V_10 , T_2 V_8 )
{
T_2 V_11 = V_10 -> V_20 ;
const struct V_15 * V_16 ;
int V_43 ;
struct V_15 V_44 ;
if ( ! ( V_10 -> type & ( V_45 | V_46 ) ) ) {
F_28 (i, bytes, v, iov, skip, ({
err = fault_in_pages_readable(v.iov_base, v.iov_len);
if (unlikely(err))
return err;
0;}))
}
return 0 ;
}
void F_29 ( struct V_9 * V_10 , int V_47 ,
const struct V_15 * V_16 , unsigned long V_25 ,
T_2 V_19 )
{
if ( F_30 () ) {
V_47 |= V_46 ;
V_10 -> type = V_47 ;
V_10 -> V_48 = (struct V_48 * ) V_16 ;
} else {
V_10 -> type = V_47 ;
V_10 -> V_16 = V_16 ;
}
V_10 -> V_25 = V_25 ;
V_10 -> V_20 = 0 ;
V_10 -> V_19 = V_19 ;
}
static void F_31 ( char * V_1 , struct V_6 * V_6 , T_2 V_7 , T_2 V_37 )
{
char * V_2 = F_14 ( V_6 ) ;
memcpy ( V_1 , V_2 + V_7 , V_37 ) ;
F_16 ( V_2 ) ;
}
static void F_32 ( struct V_6 * V_6 , T_2 V_7 , const char * V_2 , T_2 V_37 )
{
char * V_1 = F_14 ( V_6 ) ;
memcpy ( V_1 + V_7 , V_2 , V_37 ) ;
F_16 ( V_1 ) ;
}
static void F_33 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_37 )
{
char * V_49 = F_14 ( V_6 ) ;
memset ( V_49 + V_7 , 0 , V_37 ) ;
F_16 ( V_49 ) ;
}
static inline bool F_34 ( struct V_32 * V_17 )
{
return V_17 -> V_39 == & V_50 ;
}
static inline void F_35 ( const struct V_9 * V_10 , int * V_51 , T_2 * V_52 )
{
T_2 V_40 = V_10 -> V_20 ;
int V_28 = V_10 -> V_28 ;
if ( V_40 && ( ! F_34 ( & V_10 -> V_27 -> V_36 [ V_28 ] ) || V_40 == V_53 ) ) {
V_28 = F_24 ( V_28 , V_10 -> V_27 ) ;
V_40 = 0 ;
}
* V_51 = V_28 ;
* V_52 = V_40 ;
}
static T_2 F_36 ( struct V_9 * V_10 , T_2 V_54 ,
int * V_51 , T_2 * V_52 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
T_2 V_40 ;
int V_28 ;
T_3 V_13 ;
if ( F_9 ( V_54 > V_10 -> V_19 ) )
V_54 = V_10 -> V_19 ;
if ( F_9 ( ! V_54 ) )
return 0 ;
V_13 = V_54 ;
F_35 ( V_10 , & V_28 , & V_40 ) ;
* V_51 = V_28 ;
* V_52 = V_40 ;
if ( V_40 ) {
V_13 -= V_53 - V_40 ;
if ( V_13 <= 0 ) {
V_27 -> V_36 [ V_28 ] . V_37 += V_54 ;
return V_54 ;
}
V_27 -> V_36 [ V_28 ] . V_37 = V_53 ;
V_28 = F_24 ( V_28 , V_27 ) ;
}
while ( V_28 != V_27 -> V_30 || ! V_27 -> V_31 ) {
struct V_6 * V_6 = F_37 ( V_55 ) ;
if ( ! V_6 )
break;
V_27 -> V_31 ++ ;
V_27 -> V_36 [ V_28 ] . V_39 = & V_50 ;
V_27 -> V_36 [ V_28 ] . V_6 = V_6 ;
V_27 -> V_36 [ V_28 ] . V_7 = 0 ;
if ( V_13 <= V_53 ) {
V_27 -> V_36 [ V_28 ] . V_37 = V_13 ;
return V_54 ;
}
V_27 -> V_36 [ V_28 ] . V_37 = V_53 ;
V_13 -= V_53 ;
V_28 = F_24 ( V_28 , V_27 ) ;
}
return V_54 - V_13 ;
}
static T_2 F_38 ( const void * V_49 , T_2 V_8 ,
struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
T_2 V_3 , V_40 ;
int V_28 ;
if ( ! F_21 ( V_10 ) )
return 0 ;
V_8 = V_3 = F_36 ( V_10 , V_8 , & V_28 , & V_40 ) ;
if ( F_9 ( ! V_3 ) )
return 0 ;
for ( ; V_3 ; V_28 = F_24 ( V_28 , V_27 ) , V_40 = 0 ) {
T_2 V_56 = F_39 ( T_2 , V_3 , V_53 - V_40 ) ;
F_32 ( V_27 -> V_36 [ V_28 ] . V_6 , V_40 , V_49 , V_56 ) ;
V_10 -> V_28 = V_28 ;
V_10 -> V_20 = V_40 + V_56 ;
V_3 -= V_56 ;
V_49 += V_56 ;
}
V_10 -> V_19 -= V_8 ;
return V_8 ;
}
T_2 F_40 ( const void * V_49 , T_2 V_8 , struct V_9 * V_10 )
{
const char * V_2 = V_49 ;
if ( F_9 ( V_10 -> type & V_57 ) )
return F_38 ( V_49 , V_8 , V_10 ) ;
if ( F_41 ( V_10 ) )
F_10 () ;
F_42 (i, bytes, v,
copyout(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len),
memcpy_to_page(v.bv_page, v.bv_offset,
(from += v.bv_len) - v.bv_len, v.bv_len),
memcpy(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len)
)
return V_8 ;
}
T_2 F_43 ( void * V_49 , T_2 V_8 , struct V_9 * V_10 )
{
char * V_1 = V_49 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return 0 ;
}
if ( F_41 ( V_10 ) )
F_10 () ;
F_42 (i, bytes, v,
copyin((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_8 ;
}
bool F_44 ( void * V_49 , T_2 V_8 , struct V_9 * V_10 )
{
char * V_1 = V_49 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return false ;
}
if ( F_9 ( V_10 -> V_19 < V_8 ) )
return false ;
if ( F_41 ( V_10 ) )
F_10 () ;
F_45 (i, bytes, v, ({
if (copyin((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len))
return false;
0;}),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_46 ( V_10 , V_8 ) ;
return true ;
}
T_2 F_47 ( void * V_49 , T_2 V_8 , struct V_9 * V_10 )
{
char * V_1 = V_49 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return 0 ;
}
F_42 (i, bytes, v,
__copy_from_user_inatomic_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return V_8 ;
}
T_2 F_48 ( void * V_49 , T_2 V_8 , struct V_9 * V_10 )
{
char * V_1 = V_49 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return 0 ;
}
F_42 (i, bytes, v,
__copy_from_user_flushcache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_page_flushcache((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy_flushcache((to += v.iov_len) - v.iov_len, v.iov_base,
v.iov_len)
)
return V_8 ;
}
bool F_49 ( void * V_49 , T_2 V_8 , struct V_9 * V_10 )
{
char * V_1 = V_49 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return false ;
}
if ( F_9 ( V_10 -> V_19 < V_8 ) )
return false ;
F_45 (i, bytes, v, ({
if (__copy_from_user_inatomic_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len))
return false;
0;}),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_46 ( V_10 , V_8 ) ;
return true ;
}
static inline bool F_50 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_3 )
{
struct V_6 * V_58 = F_51 ( V_6 ) ;
T_2 V_44 = V_3 + V_7 + F_52 ( V_6 ) - F_52 ( V_58 ) ;
if ( F_15 ( V_3 <= V_44 && V_44 <= ( V_53 << F_53 ( V_58 ) ) ) )
return true ;
F_23 ( 1 ) ;
return false ;
}
T_2 F_54 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
if ( F_9 ( ! F_50 ( V_6 , V_7 , V_8 ) ) )
return 0 ;
if ( V_10 -> type & ( V_45 | V_46 ) ) {
void * V_18 = F_14 ( V_6 ) ;
T_2 V_14 = F_55 ( V_18 + V_7 , V_8 , V_10 ) ;
F_16 ( V_18 ) ;
return V_14 ;
} else if ( F_15 ( ! ( V_10 -> type & V_57 ) ) )
return F_8 ( V_6 , V_7 , V_8 , V_10 ) ;
else
return F_25 ( V_6 , V_7 , V_8 , V_10 ) ;
}
T_2 F_56 ( struct V_6 * V_6 , T_2 V_7 , T_2 V_8 ,
struct V_9 * V_10 )
{
if ( F_9 ( ! F_50 ( V_6 , V_7 , V_8 ) ) )
return 0 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return 0 ;
}
if ( V_10 -> type & ( V_45 | V_46 ) ) {
void * V_18 = F_14 ( V_6 ) ;
T_2 V_14 = F_43 ( V_18 + V_7 , V_8 , V_10 ) ;
F_16 ( V_18 ) ;
return V_14 ;
} else
return F_19 ( V_6 , V_7 , V_8 , V_10 ) ;
}
static T_2 F_57 ( T_2 V_8 , struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
T_2 V_3 , V_40 ;
int V_28 ;
if ( ! F_21 ( V_10 ) )
return 0 ;
V_8 = V_3 = F_36 ( V_10 , V_8 , & V_28 , & V_40 ) ;
if ( F_9 ( ! V_3 ) )
return 0 ;
for ( ; V_3 ; V_28 = F_24 ( V_28 , V_27 ) , V_40 = 0 ) {
T_2 V_56 = F_39 ( T_2 , V_3 , V_53 - V_40 ) ;
F_33 ( V_27 -> V_36 [ V_28 ] . V_6 , V_40 , V_56 ) ;
V_10 -> V_28 = V_28 ;
V_10 -> V_20 = V_40 + V_56 ;
V_3 -= V_56 ;
}
V_10 -> V_19 -= V_8 ;
return V_8 ;
}
T_2 F_58 ( T_2 V_8 , struct V_9 * V_10 )
{
if ( F_9 ( V_10 -> type & V_57 ) )
return F_57 ( V_8 , V_10 ) ;
F_42 (i, bytes, v,
clear_user(v.iov_base, v.iov_len),
memzero_page(v.bv_page, v.bv_offset, v.bv_len),
memset(v.iov_base, 0, v.iov_len)
)
return V_8 ;
}
T_2 F_59 ( struct V_6 * V_6 ,
struct V_9 * V_10 , unsigned long V_7 , T_2 V_8 )
{
char * V_18 = F_14 ( V_6 ) , * V_33 = V_18 + V_7 ;
if ( F_9 ( ! F_50 ( V_6 , V_7 , V_8 ) ) ) {
F_16 ( V_18 ) ;
return 0 ;
}
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_16 ( V_18 ) ;
F_23 ( 1 ) ;
return 0 ;
}
F_45 (i, bytes, v,
copyin((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len),
memcpy_from_page((p += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
F_16 ( V_18 ) ;
return V_8 ;
}
static inline void F_60 ( struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
if ( V_27 -> V_31 ) {
T_2 V_40 = V_10 -> V_20 ;
int V_28 = V_10 -> V_28 ;
int V_31 = ( V_28 - V_27 -> V_30 ) & ( V_27 -> V_35 - 1 ) ;
if ( V_40 ) {
V_27 -> V_36 [ V_28 ] . V_37 = V_40 - V_27 -> V_36 [ V_28 ] . V_7 ;
V_28 = F_24 ( V_28 , V_27 ) ;
V_31 ++ ;
}
while ( V_27 -> V_31 > V_31 ) {
F_61 ( V_27 , & V_27 -> V_36 [ V_28 ] ) ;
V_28 = F_24 ( V_28 , V_27 ) ;
V_27 -> V_31 -- ;
}
}
}
static void F_62 ( struct V_9 * V_10 , T_2 V_54 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
if ( F_9 ( V_10 -> V_19 < V_54 ) )
V_54 = V_10 -> V_19 ;
if ( V_54 ) {
struct V_32 * V_17 ;
T_2 V_40 = V_10 -> V_20 , V_13 = V_54 ;
int V_28 = V_10 -> V_28 ;
if ( V_40 )
V_13 += V_40 - V_27 -> V_36 [ V_28 ] . V_7 ;
while ( 1 ) {
V_17 = & V_27 -> V_36 [ V_28 ] ;
if ( V_13 <= V_17 -> V_37 )
break;
V_13 -= V_17 -> V_37 ;
V_28 = F_24 ( V_28 , V_27 ) ;
}
V_10 -> V_28 = V_28 ;
V_10 -> V_20 = V_17 -> V_7 + V_13 ;
}
V_10 -> V_19 -= V_54 ;
F_60 ( V_10 ) ;
}
void F_46 ( struct V_9 * V_10 , T_2 V_54 )
{
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_62 ( V_10 , V_54 ) ;
return;
}
F_42 (i, size, v, 0 , 0 , 0 )
}
void F_63 ( struct V_9 * V_10 , T_2 V_59 )
{
if ( ! V_59 )
return;
if ( F_23 ( V_59 > V_60 ) )
return;
V_10 -> V_19 += V_59 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
struct V_26 * V_27 = V_10 -> V_27 ;
int V_28 = V_10 -> V_28 ;
T_2 V_40 = V_10 -> V_20 ;
while ( 1 ) {
T_2 V_3 = V_40 - V_27 -> V_36 [ V_28 ] . V_7 ;
if ( V_59 < V_3 ) {
V_40 -= V_59 ;
break;
}
V_59 -= V_3 ;
if ( ! V_59 && V_28 == V_10 -> V_61 ) {
V_40 = 0 ;
break;
}
if ( ! V_28 -- )
V_28 = V_27 -> V_35 - 1 ;
V_40 = V_27 -> V_36 [ V_28 ] . V_7 + V_27 -> V_36 [ V_28 ] . V_37 ;
}
V_10 -> V_20 = V_40 ;
V_10 -> V_28 = V_28 ;
F_60 ( V_10 ) ;
return;
}
if ( V_59 <= V_10 -> V_20 ) {
V_10 -> V_20 -= V_59 ;
return;
}
V_59 -= V_10 -> V_20 ;
if ( V_10 -> type & V_45 ) {
const struct V_62 * V_63 = V_10 -> V_63 ;
while ( 1 ) {
T_2 V_3 = ( -- V_63 ) -> V_64 ;
V_10 -> V_25 ++ ;
if ( V_59 <= V_3 ) {
V_10 -> V_63 = V_63 ;
V_10 -> V_20 = V_3 - V_59 ;
return;
}
V_59 -= V_3 ;
}
} else {
const struct V_15 * V_16 = V_10 -> V_16 ;
while ( 1 ) {
T_2 V_3 = ( -- V_16 ) -> V_22 ;
V_10 -> V_25 ++ ;
if ( V_59 <= V_3 ) {
V_10 -> V_16 = V_16 ;
V_10 -> V_20 = V_3 - V_59 ;
return;
}
V_59 -= V_3 ;
}
}
}
T_2 F_64 ( const struct V_9 * V_10 )
{
if ( F_9 ( V_10 -> type & V_57 ) )
return V_10 -> V_19 ;
if ( V_10 -> V_25 == 1 )
return V_10 -> V_19 ;
else if ( V_10 -> type & V_45 )
return F_11 ( V_10 -> V_19 , V_10 -> V_63 -> V_64 - V_10 -> V_20 ) ;
else
return F_11 ( V_10 -> V_19 , V_10 -> V_16 -> V_22 - V_10 -> V_20 ) ;
}
void F_65 ( struct V_9 * V_10 , int V_47 ,
const struct V_48 * V_48 , unsigned long V_25 ,
T_2 V_19 )
{
F_66 ( ! ( V_47 & V_46 ) ) ;
V_10 -> type = V_47 ;
V_10 -> V_48 = V_48 ;
V_10 -> V_25 = V_25 ;
V_10 -> V_20 = 0 ;
V_10 -> V_19 = V_19 ;
}
void F_67 ( struct V_9 * V_10 , int V_47 ,
const struct V_62 * V_63 , unsigned long V_25 ,
T_2 V_19 )
{
F_66 ( ! ( V_47 & V_45 ) ) ;
V_10 -> type = V_47 ;
V_10 -> V_63 = V_63 ;
V_10 -> V_25 = V_25 ;
V_10 -> V_20 = 0 ;
V_10 -> V_19 = V_19 ;
}
void F_68 ( struct V_9 * V_10 , int V_47 ,
struct V_26 * V_27 ,
T_2 V_19 )
{
F_66 ( V_47 != V_57 ) ;
F_23 ( V_27 -> V_31 == V_27 -> V_35 ) ;
V_10 -> type = V_47 ;
V_10 -> V_27 = V_27 ;
V_10 -> V_28 = ( V_27 -> V_30 + V_27 -> V_31 ) & ( V_27 -> V_35 - 1 ) ;
V_10 -> V_20 = 0 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_61 = V_10 -> V_28 ;
}
unsigned long F_69 ( const struct V_9 * V_10 )
{
unsigned long V_65 = 0 ;
T_2 V_54 = V_10 -> V_19 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
if ( V_54 && V_10 -> V_20 && F_34 ( & V_10 -> V_27 -> V_36 [ V_10 -> V_28 ] ) )
return V_54 | V_10 -> V_20 ;
return V_54 ;
}
F_45 (i, size, v,
(res |= (unsigned long)v.iov_base | v.iov_len, 0),
res |= v.bv_offset | v.bv_len,
res |= (unsigned long)v.iov_base | v.iov_len
)
return V_65 ;
}
unsigned long F_70 ( const struct V_9 * V_10 )
{
unsigned long V_65 = 0 ;
T_2 V_54 = V_10 -> V_19 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return ~ 0U ;
}
F_45 ( V_10 , V_54 , V_44 ,
( V_65 |= ( ! V_65 ? 0 : ( unsigned long ) V_44 . V_21 ) |
( V_54 != V_44 . V_22 ? V_54 : 0 ) , 0 ) ,
( V_65 |= ( ! V_65 ? 0 : ( unsigned long ) V_44 . V_66 ) |
( V_54 != V_44 . V_64 ? V_54 : 0 ) ) ,
( V_65 |= ( ! V_65 ? 0 : ( unsigned long ) V_44 . V_21 ) |
( V_54 != V_44 . V_22 ? V_54 : 0 ) )
) ;
return V_65 ;
}
static inline T_2 F_71 ( struct V_9 * V_10 ,
T_2 V_67 ,
struct V_6 * * V_68 ,
int V_28 ,
T_2 * V_69 )
{
struct V_26 * V_27 = V_10 -> V_27 ;
T_3 V_3 = F_36 ( V_10 , V_67 , & V_28 , V_69 ) ;
if ( ! V_3 )
return - V_70 ;
V_67 = V_3 ;
V_3 += * V_69 ;
while ( V_3 > 0 ) {
F_26 ( * V_68 ++ = V_27 -> V_36 [ V_28 ] . V_6 ) ;
V_28 = F_24 ( V_28 , V_27 ) ;
V_3 -= V_53 ;
}
return V_67 ;
}
static T_3 F_72 ( struct V_9 * V_10 ,
struct V_6 * * V_68 , T_2 V_67 , unsigned V_71 ,
T_2 * V_69 )
{
unsigned V_72 ;
T_2 V_73 ;
int V_28 ;
if ( ! V_67 )
return 0 ;
if ( ! F_21 ( V_10 ) )
return - V_70 ;
F_35 ( V_10 , & V_28 , V_69 ) ;
V_72 = ( ( V_10 -> V_27 -> V_30 - V_28 - 1 ) & ( V_10 -> V_27 -> V_35 - 1 ) ) + 1 ;
V_73 = F_11 ( V_72 , V_71 ) * V_53 - * V_69 ;
return F_71 ( V_10 , F_11 ( V_67 , V_73 ) , V_68 , V_28 , V_69 ) ;
}
T_3 F_73 ( struct V_9 * V_10 ,
struct V_6 * * V_68 , T_2 V_67 , unsigned V_71 ,
T_2 * V_69 )
{
if ( V_67 > V_10 -> V_19 )
V_67 = V_10 -> V_19 ;
if ( F_9 ( V_10 -> type & V_57 ) )
return F_72 ( V_10 , V_68 , V_67 , V_71 , V_69 ) ;
F_45 (i, maxsize, v, ({
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
static struct V_6 * * F_74 ( T_2 V_3 )
{
return F_75 ( V_3 , sizeof( struct V_6 * ) , V_74 ) ;
}
static T_3 F_76 ( struct V_9 * V_10 ,
struct V_6 * * * V_68 , T_2 V_67 ,
T_2 * V_69 )
{
struct V_6 * * V_33 ;
T_2 V_3 ;
int V_28 ;
int V_72 ;
if ( ! V_67 )
return 0 ;
if ( ! F_21 ( V_10 ) )
return - V_70 ;
F_35 ( V_10 , & V_28 , V_69 ) ;
V_72 = ( ( V_10 -> V_27 -> V_30 - V_28 - 1 ) & ( V_10 -> V_27 -> V_35 - 1 ) ) + 1 ;
V_3 = V_72 * V_53 - * V_69 ;
if ( V_67 > V_3 )
V_67 = V_3 ;
else
V_72 = F_77 ( V_67 + * V_69 , V_53 ) ;
V_33 = F_74 ( V_72 ) ;
if ( ! V_33 )
return - V_75 ;
V_3 = F_71 ( V_10 , V_67 , V_33 , V_28 , V_69 ) ;
if ( V_3 > 0 )
* V_68 = V_33 ;
else
F_78 ( V_33 ) ;
return V_3 ;
}
T_3 F_79 ( struct V_9 * V_10 ,
struct V_6 * * * V_68 , T_2 V_67 ,
T_2 * V_69 )
{
struct V_6 * * V_33 ;
if ( V_67 > V_10 -> V_19 )
V_67 = V_10 -> V_19 ;
if ( F_9 ( V_10 -> type & V_57 ) )
return F_76 ( V_10 , V_68 , V_67 , V_69 ) ;
F_45 (i, maxsize, v, ({
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
T_2 F_80 ( void * V_49 , T_2 V_8 , T_4 * V_76 ,
struct V_9 * V_10 )
{
char * V_1 = V_49 ;
T_4 V_77 , V_29 ;
T_2 V_40 = 0 ;
V_77 = * V_76 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return 0 ;
}
F_42 (i, bytes, v, ({
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
* V_76 = V_77 ;
return V_8 ;
}
bool F_81 ( void * V_49 , T_2 V_8 , T_4 * V_76 ,
struct V_9 * V_10 )
{
char * V_1 = V_49 ;
T_4 V_77 , V_29 ;
T_2 V_40 = 0 ;
V_77 = * V_76 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return false ;
}
if ( F_9 ( V_10 -> V_19 < V_8 ) )
return false ;
F_45 (i, bytes, v, ({
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
* V_76 = V_77 ;
F_46 ( V_10 , V_8 ) ;
return true ;
}
T_2 F_82 ( const void * V_49 , T_2 V_8 , T_4 * V_76 ,
struct V_9 * V_10 )
{
const char * V_2 = V_49 ;
T_4 V_77 , V_29 ;
T_2 V_40 = 0 ;
V_77 = * V_76 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return 0 ;
}
F_42 (i, bytes, v, ({
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
* V_76 = V_77 ;
return V_8 ;
}
int F_83 ( const struct V_9 * V_10 , int V_71 )
{
T_2 V_54 = V_10 -> V_19 ;
int V_72 = 0 ;
if ( ! V_54 )
return 0 ;
if ( F_9 ( V_10 -> type & V_57 ) ) {
struct V_26 * V_27 = V_10 -> V_27 ;
T_2 V_40 ;
int V_28 ;
if ( ! F_21 ( V_10 ) )
return 0 ;
F_35 ( V_10 , & V_28 , & V_40 ) ;
V_72 = ( ( V_27 -> V_30 - V_28 - 1 ) & ( V_27 -> V_35 - 1 ) ) + 1 ;
if ( V_72 >= V_71 )
return V_71 ;
} else F_45 (i, size, v, ({
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
return V_72 ;
}
const void * F_84 ( struct V_9 * V_78 , struct V_9 * V_79 , T_5 V_80 )
{
* V_78 = * V_79 ;
if ( F_9 ( V_78 -> type & V_57 ) ) {
F_23 ( 1 ) ;
return NULL ;
}
if ( V_78 -> type & V_45 )
return V_78 -> V_63 = F_85 ( V_78 -> V_63 ,
V_78 -> V_25 * sizeof( struct V_62 ) ,
V_80 ) ;
else
return V_78 -> V_16 = F_85 ( V_78 -> V_16 ,
V_78 -> V_25 * sizeof( struct V_15 ) ,
V_80 ) ;
}
int F_86 ( int type , const struct V_15 T_1 * V_81 ,
unsigned V_25 , unsigned V_82 ,
struct V_15 * * V_16 , struct V_9 * V_10 )
{
T_3 V_3 ;
struct V_15 * V_33 ;
V_3 = F_87 ( type , V_81 , V_25 , V_82 ,
* V_16 , & V_33 ) ;
if ( V_3 < 0 ) {
if ( V_33 != * V_16 )
F_88 ( V_33 ) ;
* V_16 = NULL ;
return V_3 ;
}
F_29 ( V_10 , type , V_33 , V_25 , V_3 ) ;
* V_16 = V_33 == * V_16 ? NULL : V_33 ;
return 0 ;
}
int F_89 ( int type , const struct V_83 T_1 * V_81 ,
unsigned V_25 , unsigned V_82 ,
struct V_15 * * V_16 , struct V_9 * V_10 )
{
T_3 V_3 ;
struct V_15 * V_33 ;
V_3 = F_90 ( type , V_81 , V_25 , V_82 ,
* V_16 , & V_33 ) ;
if ( V_3 < 0 ) {
if ( V_33 != * V_16 )
F_88 ( V_33 ) ;
* V_16 = NULL ;
return V_3 ;
}
F_29 ( V_10 , type , V_33 , V_25 , V_3 ) ;
* V_16 = V_33 == * V_16 ? NULL : V_33 ;
return 0 ;
}
int F_91 ( int V_84 , void T_1 * V_17 , T_2 V_37 ,
struct V_15 * V_16 , struct V_9 * V_10 )
{
if ( V_37 > V_60 )
V_37 = V_60 ;
if ( F_9 ( ! F_2 ( ! V_84 , V_17 , V_37 ) ) )
return - V_70 ;
V_16 -> V_21 = V_17 ;
V_16 -> V_22 = V_37 ;
F_29 ( V_10 , V_84 , V_16 , 1 , V_37 ) ;
return 0 ;
}
