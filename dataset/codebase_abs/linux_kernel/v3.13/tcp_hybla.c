static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_3 ( V_6 , F_4 ( V_2 ) -> V_7 / F_5 ( V_8 ) , 8 ) ;
V_4 -> V_9 = V_4 -> V_5 >> 3 ;
V_4 -> V_10 = ( V_4 -> V_5 * V_4 -> V_5 ) << 1 ;
V_4 -> V_11 = V_4 -> V_10 >> 7 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_11 = 0 ;
V_4 -> V_5 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_14 = 0 ;
V_4 -> V_15 = true ;
V_13 -> V_16 = 2 ;
V_13 -> V_17 = 65535 ;
F_1 ( V_2 ) ;
V_4 -> V_18 = V_13 -> V_7 ;
V_13 -> V_16 = V_4 -> V_9 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_15 = ( V_19 == V_20 ) ;
}
static inline V_6 F_8 ( V_6 V_21 )
{
static const V_6 V_22 [] = {
128 , 139 , 152 , 165 , 181 , 197 , 215 , 234 ,
} ;
return ( V_21 < F_9 ( V_22 ) ) ? V_22 [ V_21 ] : 128 ;
}
static void F_10 ( struct V_1 * V_2 , V_6 V_23 , V_6 V_24 ,
V_6 V_25 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_6 V_26 , V_27 , V_28 ;
int V_29 = 0 ;
if ( V_13 -> V_7 < V_4 -> V_18 ) {
F_1 ( V_2 ) ;
V_4 -> V_18 = V_13 -> V_7 ;
}
if ( ! F_11 ( V_2 , V_25 ) )
return;
if ( ! V_4 -> V_15 ) {
F_12 ( V_2 , V_23 , V_24 , V_25 ) ;
return;
}
if ( V_4 -> V_9 == 0 )
F_1 ( V_2 ) ;
V_28 = V_4 -> V_5 - ( V_4 -> V_9 << 3 ) ;
if ( V_13 -> V_16 < V_13 -> V_30 ) {
V_29 = 1 ;
V_26 = ( ( 1 << F_13 ( V_4 -> V_9 , 16U ) ) *
F_8 ( V_28 ) ) - 128 ;
} else {
V_26 = V_4 -> V_10 / V_13 -> V_16 ;
if ( V_26 < 128 )
V_13 -> V_31 ++ ;
}
V_27 = V_26 % 128 ;
V_13 -> V_16 += V_26 >> 7 ;
V_4 -> V_14 += V_27 ;
while ( V_4 -> V_14 >= 128 ) {
V_13 -> V_16 ++ ;
V_4 -> V_14 -= 128 ;
V_13 -> V_31 = 0 ;
}
if ( V_26 == 0 && V_27 == 0 && V_13 -> V_31 >= V_13 -> V_16 ) {
V_13 -> V_16 ++ ;
V_13 -> V_31 = 0 ;
}
if ( V_29 )
V_13 -> V_16 = F_13 ( V_13 -> V_16 , V_13 -> V_30 ) ;
V_13 -> V_16 = F_14 ( V_6 , V_13 -> V_16 , V_13 -> V_17 ) ;
}
static int T_2 F_15 ( void )
{
F_16 ( sizeof( struct V_3 ) > V_32 ) ;
return F_17 ( & V_33 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_33 ) ;
}
