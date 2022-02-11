static T_1 T_2 F_1 ( void T_3 * V_1 )
{
return 200000000 ;
}
static T_1 T_2 F_2 ( void T_3 * V_1 )
{
T_1 V_2 = 0 ;
T_4 V_3 = 0 ;
V_3 = ( ( F_3 ( V_1 ) >> V_4 ) &
V_5 ) ;
if ( F_4 ( L_1 ) )
V_2 = V_6 [ V_3 ] ;
else if ( F_4 ( L_2 ) )
V_2 = V_7 [ V_3 ] ;
if ( ! V_2 )
F_5 ( L_3 , V_3 ) ;
return V_2 ;
}
static void T_2 F_6 (
void T_3 * V_1 , int V_8 , int * V_9 , int * div )
{
T_1 V_10 = ( ( F_3 ( V_1 ) >> V_4 ) &
V_5 ) ;
switch ( V_8 ) {
case V_11 :
if ( F_4 ( L_1 ) ) {
* V_9 = V_12 [ V_10 ] [ 0 ] ;
* div = V_12 [ V_10 ] [ 1 ] ;
} else if ( F_4 ( L_2 ) ) {
* V_9 = V_13 [ V_10 ] [ 0 ] ;
* div = V_13 [ V_10 ] [ 1 ] ;
}
break;
case V_14 :
if ( F_4 ( L_1 ) ) {
* V_9 = V_15 [ V_10 ] [ 0 ] ;
* div = V_15 [ V_10 ] [ 1 ] ;
} else if ( F_4 ( L_2 ) ) {
* V_9 = V_16 [ V_10 ] [ 0 ] ;
* div = V_16 [ V_10 ] [ 1 ] ;
}
break;
}
}
static void T_2 F_7 ( struct V_17 * V_18 )
{
struct V_17 * V_19 =
F_8 ( NULL , NULL , L_4 ) ;
F_9 ( V_18 , & V_20 ) ;
if ( V_19 )
F_10 ( V_19 , V_21 ) ;
}
