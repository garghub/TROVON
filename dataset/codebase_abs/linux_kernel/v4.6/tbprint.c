static void F_1 ( char * string , T_1 V_1 )
{
while ( V_1 && * string ) {
if ( ! isprint ( ( int ) * string ) ) {
* string = '?' ;
}
string ++ ;
V_1 -- ;
}
}
static void
F_2 ( struct V_2 * V_3 ,
struct V_2 * V_4 )
{
memcpy ( V_3 , V_4 , sizeof( struct V_2 ) ) ;
F_1 ( V_3 -> V_5 , V_6 ) ;
F_1 ( V_3 -> V_7 , V_8 ) ;
F_1 ( V_3 -> V_9 , V_10 ) ;
F_1 ( V_3 -> V_11 , V_6 ) ;
}
void
F_3 ( T_2 V_12 ,
struct V_2 * V_4 )
{
struct V_2 V_13 ;
if ( F_4 ( V_4 -> V_5 , V_14 ) ) {
F_5 ( ( L_1 ,
V_4 -> V_5 , F_6 ( V_12 ) ,
V_4 -> V_1 ) ) ;
} else if ( F_7 ( V_4 -> V_5 ) ) {
memcpy ( V_13 . V_7 ,
F_8 ( struct V_15 , V_4 ) -> V_7 ,
V_8 ) ;
F_1 ( V_13 . V_7 , V_8 ) ;
F_5 ( ( L_2 ,
F_6 ( V_12 ) ,
( F_8 ( struct V_15 , V_4 ) ->
V_16 >
0 ) ? F_8 ( struct V_15 ,
V_4 ) -> V_1 : 20 ,
F_8 ( struct V_15 ,
V_4 ) -> V_16 ,
V_13 . V_7 ) ) ;
} else {
F_2 ( & V_13 , V_4 ) ;
F_5 ( ( L_3
L_4 ,
V_13 . V_5 , F_6 ( V_12 ) ,
V_13 . V_1 , V_13 . V_16 ,
V_13 . V_7 , V_13 . V_9 ,
V_13 . V_17 ,
V_13 . V_11 ,
V_13 . V_18 ) ) ;
}
}
T_3 F_9 ( struct V_2 * V_19 , T_4 V_1 )
{
T_5 V_20 ;
if ( F_4 ( V_19 -> V_5 , V_21 ) ||
F_4 ( V_19 -> V_5 , V_14 ) ) {
return ( V_22 ) ;
}
V_20 = F_10 ( F_8 ( T_5 , V_19 ) , V_1 ) ;
if ( V_20 ) {
F_11 ( ( V_23 ,
L_5
L_6 ,
V_19 -> V_5 , V_19 -> V_20 ,
( T_5 ) ( V_19 -> V_20 - V_20 ) ) ) ;
#if ( V_24 )
return ( V_25 ) ;
#endif
}
return ( V_22 ) ;
}
T_5 F_10 ( T_5 * V_26 , T_4 V_1 )
{
T_5 V_27 = 0 ;
T_5 * V_28 = V_26 + V_1 ;
while ( V_26 < V_28 ) {
V_27 = ( T_5 ) ( V_27 + * ( V_26 ++ ) ) ;
}
return ( V_27 ) ;
}
