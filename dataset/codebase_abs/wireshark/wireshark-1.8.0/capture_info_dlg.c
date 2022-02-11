static void
F_1 ( T_1 * V_1 )
{
#ifdef F_2
F_3 ( V_2 ) ;
#endif
F_4 ( V_1 ) ;
}
static T_2
F_5 ( T_3 * T_4 V_3 , T_5 * T_6 V_3 , T_7 V_4 ) {
F_1 ( V_4 ) ;
return TRUE ;
}
static void
F_6 ( T_8 * T_4 V_3 , T_7 V_4 ) {
F_1 ( V_4 ) ;
}
static T_2
F_7 ( T_7 V_4 )
{
T_9 * V_5 = V_4 ;
T_10 * V_6 = V_5 -> V_7 ;
if ( ! V_6 )
return TRUE ;
V_5 -> V_8 = time ( NULL ) - V_6 -> V_9 ;
F_8 ( V_5 ) ;
return TRUE ;
}
void F_8 (
T_9 * V_5 )
{
unsigned int V_10 ;
T_11 V_11 [ 64 ] ;
T_10 * V_6 = V_5 -> V_7 ;
if ( ! V_6 )
return;
F_9 ( V_11 , sizeof( V_11 ) , L_1 ,
( long ) ( V_5 -> V_8 / 3600 ) , ( long ) ( ( V_5 -> V_8 % 3600 ) / 60 ) ,
( long ) ( V_5 -> V_8 % 60 ) ) ;
F_10 ( F_11 ( V_6 -> V_12 ) , V_11 ) ;
if ( V_5 -> V_13 ) {
float V_14 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
F_9 ( V_11 , sizeof( V_11 ) , L_2 , * V_6 -> V_16 [ V_10 ] . V_17 ) ;
F_10 ( F_11 ( V_6 -> V_16 [ V_10 ] . V_18 ) , V_11 ) ;
V_14 = ( * V_6 -> V_16 [ 0 ] . V_17 != 0 ) ?
( ( float ) * V_6 -> V_16 [ V_10 ] . V_17 / * V_6 -> V_16 [ 0 ] . V_17 ) : 0.0f ;
if ( V_10 != 0 ) {
F_12 ( F_13 ( V_6 -> V_16 [ V_10 ] . V_19 ) , V_14 ) ;
F_9 ( V_11 , sizeof( V_11 ) , L_3 , V_14 * 100.0 ) ;
F_10 ( F_11 ( V_6 -> V_16 [ V_10 ] . V_20 ) , V_11 ) ;
}
}
}
}
void F_14 (
T_9 * V_5 )
{
T_10 * V_6 = V_5 -> V_7 ;
if ( ! V_6 )
return;
F_15 ( V_6 -> V_21 ) ;
F_16 ( F_17 ( V_6 -> V_22 ) ) ;
F_18 ( F_17 ( V_6 -> V_22 ) ) ;
F_19 ( V_6 ) ;
V_5 -> V_7 = NULL ;
}
