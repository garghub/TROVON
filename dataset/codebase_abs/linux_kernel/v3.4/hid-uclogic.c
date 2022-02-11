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
if ( * V_4 == V_10 ) {
V_3 = V_13 ;
* V_4 = sizeof( V_13 ) ;
}
break;
case V_14 :
if ( * V_4 == V_10 ) {
V_3 = V_15 ;
* V_4 = sizeof( V_15 ) ;
}
break;
case V_16 :
if ( * V_4 == V_17 ) {
V_3 = V_18 ;
* V_4 = sizeof( V_18 ) ;
}
break;
}
return V_3 ;
}
static int T_2 F_2 ( void )
{
return F_3 ( & V_19 ) ;
}
static void T_3 F_4 ( void )
{
F_5 ( & V_19 ) ;
}
