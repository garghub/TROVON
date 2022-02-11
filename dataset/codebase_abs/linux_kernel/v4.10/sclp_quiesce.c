static void F_1 ( void )
{
T_1 V_1 ;
F_2 () ;
V_1 . V_2 =
V_3 | V_4 | V_5 | V_6 ;
V_1 . V_7 = 0xfff ;
F_3 ( V_1 ) ;
}
static void F_4 ( struct V_8 * V_9 )
{
if ( V_10 != ( void * ) F_1 ) {
V_11 = V_10 ;
V_12 = V_13 ;
V_14 = V_15 ;
V_10 = ( void * ) F_1 ;
V_13 = F_1 ;
V_15 = F_1 ;
}
F_5 () ;
}
static void F_6 ( struct V_16 * V_17 ,
enum V_18 V_18 )
{
switch ( V_18 ) {
case V_19 :
if ( V_11 ) {
V_10 = V_11 ;
V_13 = V_12 ;
V_15 = V_14 ;
V_11 = NULL ;
V_12 = NULL ;
V_14 = NULL ;
}
break;
case V_20 :
case V_21 :
break;
}
}
static int T_2 F_7 ( void )
{
return V_16 ( & V_22 ) ;
}
