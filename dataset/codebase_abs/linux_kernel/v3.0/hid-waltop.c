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
}
return V_3 ;
}
static int T_2 F_2 ( void )
{
return F_3 ( & V_18 ) ;
}
static void T_3 F_4 ( void )
{
F_5 ( & V_18 ) ;
}
