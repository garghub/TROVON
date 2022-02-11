void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 =
F_2 ( V_4 -> V_7 , 16 , V_8 ) ;
V_2 -> V_9 =
F_2 ( V_4 -> V_10 , 16 , V_11 ) ;
V_2 -> V_12 =
F_2 ( V_4 -> V_13 , 16 , V_11 ) ;
}
void
F_3 (
const struct V_1 * V_14 ,
unsigned V_15 )
{
if ( ! V_14 ) return;
F_4 ( V_15 , L_1 ) ;
F_4 ( V_15 , L_2 ,
L_3 , V_14 -> V_6 ) ;
F_4 ( V_15 , L_2 ,
L_4 , V_14 -> V_9 ) ;
F_4 ( V_15 , L_2
L_5 , V_14 -> V_12 ) ;
}
void
F_5 (
const struct V_3 * V_16 ,
unsigned V_15 )
{
F_4 ( V_15 ,
L_6
L_7 ,
V_16 -> V_7 ,
V_16 -> V_10 , V_16 -> V_13 ) ;
}
void
F_6 (
const struct V_17 * V_18 ,
const struct V_19 * * V_20 )
{
struct V_21 V_16 ;
unsigned V_22 ;
#ifndef F_7
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ )
#else
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ )
#endif
V_16 . V_25 [ V_22 ] = V_20 [ V_22 ] ;
F_8 ( V_18 , & V_16 ) ;
}
void
F_9 (
struct V_26 * V_27 ,
T_1 V_5 )
{
( void ) V_5 ;
#ifndef F_7
assert ( V_23 >= 2 ) ;
#endif
assert ( sizeof( * V_27 ) == V_5 ) ;
V_27 -> V_28 = 0 ;
V_27 -> V_29 = 1 ;
}
