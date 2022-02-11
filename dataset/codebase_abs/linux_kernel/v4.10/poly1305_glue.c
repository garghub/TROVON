static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = false ;
#ifdef F_3
V_4 -> V_6 = false ;
#endif
return F_4 ( V_2 ) ;
}
static void F_5 ( T_1 * V_7 , const T_1 * V_8 )
{
T_2 V_9 [ V_10 ] ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_7 [ 4 ] -= 1 << 24 ;
F_6 ( V_7 , V_9 , V_8 , 1 ) ;
}
static unsigned int F_7 ( struct V_11 * V_12 ,
const T_2 * V_13 , unsigned int V_14 )
{
struct V_3 * V_4 ;
unsigned int V_15 , V_16 ;
F_8 ( F_9 ( struct V_3 , V_17 ) ) ;
V_4 = F_10 ( V_12 , struct V_3 , V_17 ) ;
if ( F_11 ( ! V_12 -> V_18 ) ) {
V_16 = F_12 ( V_12 , V_13 , V_14 ) ;
V_13 += V_14 - V_16 ;
V_14 = V_16 ;
}
#ifdef F_3
if ( V_19 && V_14 >= V_10 * 4 ) {
if ( F_11 ( ! V_4 -> V_6 ) ) {
if ( ! V_4 -> V_5 ) {
memcpy ( V_4 -> V_20 , V_12 -> V_21 , sizeof( V_4 -> V_20 ) ) ;
F_5 ( V_4 -> V_20 , V_12 -> V_21 ) ;
V_4 -> V_5 = true ;
}
memcpy ( V_4 -> V_20 + 5 , V_4 -> V_20 , sizeof( V_4 -> V_20 ) ) ;
F_5 ( V_4 -> V_20 + 5 , V_12 -> V_21 ) ;
memcpy ( V_4 -> V_20 + 10 , V_4 -> V_20 + 5 , sizeof( V_4 -> V_20 ) ) ;
F_5 ( V_4 -> V_20 + 10 , V_12 -> V_21 ) ;
V_4 -> V_6 = true ;
}
V_15 = V_14 / ( V_10 * 4 ) ;
F_13 ( V_12 -> V_22 , V_13 , V_12 -> V_21 , V_15 , V_4 -> V_20 ) ;
V_13 += V_10 * 4 * V_15 ;
V_14 -= V_10 * 4 * V_15 ;
}
#endif
if ( F_14 ( V_14 >= V_10 * 2 ) ) {
if ( F_11 ( ! V_4 -> V_5 ) ) {
memcpy ( V_4 -> V_20 , V_12 -> V_21 , sizeof( V_4 -> V_20 ) ) ;
F_5 ( V_4 -> V_20 , V_12 -> V_21 ) ;
V_4 -> V_5 = true ;
}
V_15 = V_14 / ( V_10 * 2 ) ;
F_15 ( V_12 -> V_22 , V_13 , V_12 -> V_21 , V_15 , V_4 -> V_20 ) ;
V_13 += V_10 * 2 * V_15 ;
V_14 -= V_10 * 2 * V_15 ;
}
if ( V_14 >= V_10 ) {
F_6 ( V_12 -> V_22 , V_13 , V_12 -> V_21 , 1 ) ;
V_14 -= V_10 ;
}
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 ,
const T_2 * V_13 , unsigned int V_14 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
unsigned int V_23 ;
if ( V_14 <= 288 || ! F_17 () )
return F_18 ( V_2 , V_13 , V_14 ) ;
F_19 () ;
if ( F_11 ( V_12 -> V_24 ) ) {
V_23 = F_20 ( V_14 , V_10 - V_12 -> V_24 ) ;
memcpy ( V_12 -> V_25 + V_12 -> V_24 , V_13 , V_23 ) ;
V_13 += V_23 ;
V_14 -= V_23 ;
V_12 -> V_24 += V_23 ;
if ( V_12 -> V_24 == V_10 ) {
F_7 ( V_12 , V_12 -> V_25 ,
V_10 ) ;
V_12 -> V_24 = 0 ;
}
}
if ( F_14 ( V_14 >= V_10 ) ) {
V_23 = F_7 ( V_12 , V_13 , V_14 ) ;
V_13 += V_14 - V_23 ;
V_14 = V_23 ;
}
F_21 () ;
if ( F_11 ( V_14 ) ) {
V_12 -> V_24 = V_14 ;
memcpy ( V_12 -> V_25 , V_13 , V_14 ) ;
}
return 0 ;
}
static int T_3 F_22 ( void )
{
if ( ! F_23 ( V_26 ) )
return - V_27 ;
#ifdef F_3
V_19 = F_23 ( V_28 ) &&
F_23 ( V_29 ) &&
F_24 ( V_30 | V_31 , NULL ) ;
V_32 . V_33 = sizeof( struct V_3 ) ;
if ( V_19 )
V_32 . V_33 += 10 * sizeof( T_1 ) ;
#endif
return F_25 ( & V_32 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_32 ) ;
}
