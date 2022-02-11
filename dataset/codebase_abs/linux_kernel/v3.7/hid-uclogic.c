static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
T_1 V_9 = V_6 -> V_10 -> V_11 . V_12 ;
switch ( V_2 -> V_13 ) {
case V_14 :
if ( * V_4 == V_15 ) {
V_3 = V_16 ;
* V_4 = sizeof( V_16 ) ;
}
break;
case V_17 :
if ( * V_4 == V_18 ) {
V_3 = V_19 ;
* V_4 = sizeof( V_19 ) ;
}
break;
case V_20 :
if ( * V_4 == V_18 ) {
V_3 = V_21 ;
* V_4 = sizeof( V_21 ) ;
}
break;
case V_22 :
if ( * V_4 == V_18 ) {
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
case V_27 :
switch ( V_9 ) {
case 0 :
if ( * V_4 == V_28 ) {
V_3 = V_29 ;
* V_4 = sizeof( V_29 ) ;
}
break;
case 1 :
if ( * V_4 == V_30 ) {
V_3 = V_31 ;
* V_4 = sizeof( V_31 ) ;
}
break;
case 2 :
if ( * V_4 == V_32 ) {
V_3 = V_33 ;
* V_4 = sizeof( V_33 ) ;
}
break;
}
break;
case V_34 :
switch ( V_9 ) {
case 0 :
if ( * V_4 == V_35 ) {
V_3 = V_36 ;
* V_4 = sizeof( V_36 ) ;
}
break;
case 1 :
if ( * V_4 == V_37 ) {
V_3 = V_38 ;
* V_4 = sizeof( V_38 ) ;
}
break;
}
break;
}
return V_3 ;
}
static int T_2 F_3 ( void )
{
return F_4 ( & V_39 ) ;
}
static void T_3 F_5 ( void )
{
F_6 ( & V_39 ) ;
}
