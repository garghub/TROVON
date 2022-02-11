static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_3 ( V_6 ,
F_4 ( V_2 ) -> V_7 / ( V_8 * V_9 ) ,
8U ) ;
V_4 -> V_10 = V_4 -> V_5 >> 3 ;
V_4 -> V_11 = ( V_4 -> V_5 * V_4 -> V_5 ) << 1 ;
V_4 -> V_12 = V_4 -> V_11 >> 7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_4 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_12 = 0 ;
V_4 -> V_5 = 0 ;
V_4 -> V_11 = 0 ;
V_4 -> V_15 = 0 ;
V_4 -> V_16 = true ;
V_14 -> V_17 = 2 ;
V_14 -> V_18 = 65535 ;
F_1 ( V_2 ) ;
V_4 -> V_19 = V_14 -> V_7 ;
V_14 -> V_17 = V_4 -> V_10 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_16 = ( V_20 == V_21 ) ;
}
static inline V_6 F_7 ( V_6 V_22 )
{
static const V_6 V_23 [] = {
128 , 139 , 152 , 165 , 181 , 197 , 215 , 234 ,
} ;
return ( V_22 < F_8 ( V_23 ) ) ? V_23 [ V_22 ] : 128 ;
}
static void F_9 ( struct V_1 * V_2 , V_6 V_24 , V_6 V_25 )
{
struct V_13 * V_14 = F_4 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_6 V_26 , V_27 , V_28 ;
int V_29 = 0 ;
if ( V_14 -> V_7 < V_4 -> V_19 ) {
F_1 ( V_2 ) ;
V_4 -> V_19 = V_14 -> V_7 ;
}
if ( ! F_10 ( V_2 ) )
return;
if ( ! V_4 -> V_16 ) {
F_11 ( V_2 , V_24 , V_25 ) ;
return;
}
if ( V_4 -> V_10 == 0 )
F_1 ( V_2 ) ;
V_28 = V_4 -> V_5 - ( V_4 -> V_10 << 3 ) ;
if ( V_14 -> V_17 < V_14 -> V_30 ) {
V_29 = 1 ;
V_26 = ( ( 1 << F_12 ( V_4 -> V_10 , 16U ) ) *
F_7 ( V_28 ) ) - 128 ;
} else {
V_26 = V_4 -> V_11 / V_14 -> V_17 ;
if ( V_26 < 128 )
V_14 -> V_31 ++ ;
}
V_27 = V_26 % 128 ;
V_14 -> V_17 += V_26 >> 7 ;
V_4 -> V_15 += V_27 ;
while ( V_4 -> V_15 >= 128 ) {
V_14 -> V_17 ++ ;
V_4 -> V_15 -= 128 ;
V_14 -> V_31 = 0 ;
}
if ( V_26 == 0 && V_27 == 0 && V_14 -> V_31 >= V_14 -> V_17 ) {
V_14 -> V_17 ++ ;
V_14 -> V_31 = 0 ;
}
if ( V_29 )
V_14 -> V_17 = F_12 ( V_14 -> V_17 , V_14 -> V_30 ) ;
V_14 -> V_17 = F_13 ( V_6 , V_14 -> V_17 , V_14 -> V_18 ) ;
}
static int T_2 F_14 ( void )
{
F_15 ( sizeof( struct V_3 ) > V_32 ) ;
return F_16 ( & V_33 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_33 ) ;
}
