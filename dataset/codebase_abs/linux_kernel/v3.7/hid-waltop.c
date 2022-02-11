static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
if ( * V_4 == V_7 ) {
V_3 = V_8 ;
* V_4 = sizeof( V_8 ) ;
}
break;
case V_9 :
if ( * V_4 == V_10 ) {
V_3 = V_11 ;
* V_4 = sizeof( V_11 ) ;
}
break;
case V_12 :
if ( * V_4 == V_13 ) {
V_3 = V_14 ;
* V_4 = sizeof( V_14 ) ;
}
break;
case V_15 :
if ( * V_4 == V_16 ) {
V_3 = V_17 ;
* V_4 = sizeof( V_17 ) ;
}
break;
case V_18 :
if ( * V_4 == V_19 ) {
V_3 = V_20 ;
* V_4 = sizeof( V_20 ) ;
}
break;
case V_21 :
if ( * V_4 == V_22 ) {
V_3 = V_23 ;
* V_4 = sizeof( V_23 ) ;
}
break;
case V_24 :
if ( * V_4 == V_25 ) {
V_3 = V_26 ;
* V_4 = sizeof( V_26 ) ;
}
break;
}
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_27 * V_28 ,
T_2 * V_29 , int V_30 )
{
if ( V_28 -> type == V_31 && V_28 -> V_32 == 16 && V_30 >= 8 ) {
if ( ( V_29 [ 1 ] & 0xF ) > 1 ) {
V_29 [ 6 ] = 0 ;
V_29 [ 7 ] = 0 ;
}
}
if ( V_2 -> V_5 == V_24 &&
V_28 -> type == V_31 &&
V_28 -> V_32 == 16 &&
V_30 == 10 ) {
static const T_3 V_33 [] = {
0 , 5 , 10 , 14 , 19 , 24 , 29 , 34 , 40 , 45 ,
50 , 56 , 62 , 68 , 74 , 81 , 88 , 96 , 105
} ;
T_3 V_34 = ( T_3 ) V_29 [ 8 ] ;
T_3 V_35 = ( T_3 ) V_29 [ 9 ] ;
T_3 V_36 = V_34 >= 0 ? 1 : - 1 ;
T_3 V_37 = V_35 >= 0 ? 1 : - 1 ;
V_34 *= V_36 ;
V_35 *= V_37 ;
V_37 *= - 1 ;
if ( V_34 > F_3 ( V_33 ) - 1 )
V_34 = F_3 ( V_33 ) - 1 ;
if ( V_35 > F_3 ( V_33 ) - 1 )
V_35 = F_3 ( V_33 ) - 1 ;
V_29 [ 8 ] = V_33 [ V_34 ] * V_36 ;
V_29 [ 9 ] = V_33 [ V_35 ] * V_37 ;
}
return 0 ;
}
static int T_4 F_4 ( void )
{
return F_5 ( & V_38 ) ;
}
static void T_5 F_6 ( void )
{
F_7 ( & V_38 ) ;
}
