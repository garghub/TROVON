static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_1 ) ;
goto V_6;
}
V_5 = F_4 ( V_2 , V_7 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_2 ) ;
goto V_6;
}
return 0 ;
V_6:
return V_5 ;
}
static T_1 * F_5 ( struct V_1 * V_2 , T_1 * V_8 ,
unsigned int * V_9 )
{
switch ( V_2 -> V_10 ) {
case V_11 :
if ( * V_9 == V_12 ) {
V_8 = V_13 ;
* V_9 = sizeof( V_13 ) ;
}
break;
case V_14 :
if ( * V_9 == V_15 ) {
V_8 = V_16 ;
* V_9 = sizeof( V_16 ) ;
}
break;
case V_17 :
if ( * V_9 == V_18 ) {
V_8 = V_19 ;
* V_9 = sizeof( V_19 ) ;
}
break;
case V_20 :
if ( * V_9 == V_21 ) {
V_8 = V_22 ;
* V_9 = sizeof( V_22 ) ;
}
break;
case V_23 :
if ( * V_9 == V_24 ) {
V_8 = V_25 ;
* V_9 = sizeof( V_25 ) ;
}
break;
case V_26 :
if ( * V_9 == V_27 ) {
V_8 = V_28 ;
* V_9 = sizeof( V_28 ) ;
}
break;
case V_29 :
if ( * V_9 == V_30 ) {
V_8 = V_31 ;
* V_9 = sizeof( V_31 ) ;
}
break;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_2 * V_34 , int V_35 )
{
if ( V_33 -> type == V_36 && V_33 -> V_4 == 16 && V_35 >= 8 ) {
if ( ( V_34 [ 1 ] & 0xF ) > 1 ) {
V_34 [ 6 ] = 0 ;
V_34 [ 7 ] = 0 ;
}
}
if ( V_2 -> V_10 == V_29 &&
V_33 -> type == V_36 &&
V_33 -> V_4 == 16 &&
V_35 == 10 ) {
static const T_3 V_37 [] = {
0 , 5 , 10 , 14 , 19 , 24 , 29 , 34 , 40 , 45 ,
50 , 56 , 62 , 68 , 74 , 81 , 88 , 96 , 105
} ;
T_3 V_38 = ( T_3 ) V_34 [ 8 ] ;
T_3 V_39 = ( T_3 ) V_34 [ 9 ] ;
T_3 V_40 = V_38 >= 0 ? 1 : - 1 ;
T_3 V_41 = V_39 >= 0 ? 1 : - 1 ;
V_38 *= V_40 ;
V_39 *= V_41 ;
V_41 *= - 1 ;
if ( V_38 > F_7 ( V_37 ) - 1 )
V_38 = F_7 ( V_37 ) - 1 ;
if ( V_39 > F_7 ( V_37 ) - 1 )
V_39 = F_7 ( V_37 ) - 1 ;
V_34 [ 8 ] = V_37 [ V_38 ] * V_40 ;
V_34 [ 9 ] = V_37 [ V_39 ] * V_41 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
static int T_4 F_10 ( void )
{
return F_11 ( & V_42 ) ;
}
static void T_5 F_12 ( void )
{
F_13 ( & V_42 ) ;
}
