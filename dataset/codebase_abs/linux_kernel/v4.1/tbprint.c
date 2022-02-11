static void F_1 ( char * string , T_1 V_1 )
{
while ( V_1 && * string ) {
if ( ! F_2 ( * string ) ) {
* string = '?' ;
}
string ++ ;
V_1 -- ;
}
}
static void
F_3 ( struct V_2 * V_3 ,
struct V_2 * V_4 )
{
F_4 ( V_3 , V_4 , sizeof( struct V_2 ) ) ;
F_1 ( V_3 -> V_5 , V_6 ) ;
F_1 ( V_3 -> V_7 , V_8 ) ;
F_1 ( V_3 -> V_9 , V_10 ) ;
F_1 ( V_3 -> V_11 , V_6 ) ;
}
void
F_5 ( T_2 V_12 ,
struct V_2 * V_4 )
{
struct V_2 V_13 ;
if ( F_6 ( V_4 -> V_5 , V_14 ) ) {
F_7 ( ( V_15 , L_1 ,
V_4 -> V_5 , F_8 ( V_12 ) ,
V_4 -> V_1 ) ) ;
} else if ( F_9 ( V_4 -> V_5 ) ) {
F_4 ( V_13 . V_7 ,
F_10 ( struct V_16 ,
V_4 ) -> V_7 , V_8 ) ;
F_1 ( V_13 . V_7 , V_8 ) ;
F_7 ( ( V_15 , L_2 ,
F_8 ( V_12 ) ,
( F_10 ( struct V_16 , V_4 ) ->
V_17 >
0 ) ? F_10 ( struct V_16 ,
V_4 ) -> V_1 : 20 ,
F_10 ( struct V_16 ,
V_4 ) -> V_17 ,
V_13 . V_7 ) ) ;
} else {
F_3 ( & V_13 , V_4 ) ;
F_7 ( ( V_15 ,
L_3
L_4 ,
V_13 . V_5 , F_8 ( V_12 ) ,
V_13 . V_1 , V_13 . V_17 ,
V_13 . V_7 , V_13 . V_9 ,
V_13 . V_18 ,
V_13 . V_11 ,
V_13 . V_19 ) ) ;
}
}
T_3 F_11 ( struct V_2 * V_20 , T_4 V_1 )
{
T_5 V_21 ;
if ( F_6 ( V_20 -> V_5 , V_22 ) ||
F_6 ( V_20 -> V_5 , V_14 ) ) {
return ( V_23 ) ;
}
V_21 = F_12 ( F_10 ( T_5 , V_20 ) , V_1 ) ;
if ( V_21 ) {
F_13 ( ( V_15 ,
L_5
L_6 ,
V_20 -> V_5 , V_20 -> V_21 ,
( T_5 ) ( V_20 -> V_21 - V_21 ) ) ) ;
#if ( V_24 )
return ( V_25 ) ;
#endif
}
return ( V_23 ) ;
}
T_5 F_12 ( T_5 * V_26 , T_4 V_1 )
{
T_5 V_27 = 0 ;
T_5 * V_28 = V_26 + V_1 ;
while ( V_26 < V_28 ) {
V_27 = ( T_5 ) ( V_27 + * ( V_26 ++ ) ) ;
}
return ( V_27 ) ;
}
