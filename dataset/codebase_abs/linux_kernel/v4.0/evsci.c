T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 ;
T_1 V_4 = V_5 ;
F_2 ( V_6 ) ;
if ( ! V_7 ) {
return ( V_4 ) ;
}
V_3 = F_3 ( V_8 ) ;
V_2 = V_7 ;
while ( V_2 ) {
V_4 |= V_2 -> V_9 ( V_2 -> V_10 ) ;
V_2 = V_2 -> V_11 ;
}
F_4 ( V_8 , V_3 ) ;
return ( V_4 ) ;
}
static T_1 T_3 F_5 ( void * V_10 )
{
struct V_12 * V_13 = V_10 ;
T_1 V_14 = V_5 ;
F_6 ( V_15 ) ;
V_14 |= F_7 () ;
V_14 |= F_8 ( V_13 ) ;
V_14 |= F_1 () ;
V_16 ++ ;
F_9 ( V_14 ) ;
}
T_1 T_3 F_10 ( void * V_10 )
{
struct V_12 * V_13 = V_10 ;
T_1 V_14 = V_5 ;
F_6 ( V_17 ) ;
V_14 |= F_8 ( V_13 ) ;
F_9 ( V_14 ) ;
}
T_1 F_11 ( void )
{
T_1 V_18 = V_19 ;
F_6 ( V_20 ) ;
V_18 =
F_12 ( ( T_1 ) V_21 . V_22 ,
F_5 ,
V_23 ) ;
F_13 ( V_18 ) ;
}
T_4 F_14 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 ;
T_4 V_18 ;
F_6 ( V_24 ) ;
V_18 =
F_15 ( ( T_1 ) V_21 . V_22 ,
F_5 ) ;
if ( ! V_7 ) {
return ( V_18 ) ;
}
V_3 = F_3 ( V_8 ) ;
while ( V_7 ) {
V_2 = V_7 ;
V_7 = V_2 -> V_11 ;
F_16 ( V_2 ) ;
}
F_4 ( V_8 , V_3 ) ;
F_13 ( V_18 ) ;
}
