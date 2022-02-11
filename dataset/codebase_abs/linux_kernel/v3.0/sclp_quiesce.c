static void F_1 ( void )
{
T_1 V_1 ;
F_2 () ;
V_1 . V_2 = V_3 | V_4 ;
V_1 . V_5 = 0xfff ;
F_3 ( V_1 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
if ( V_8 != ( void * ) F_1 ) {
V_9 = V_8 ;
V_10 = V_11 ;
V_12 = V_13 ;
V_8 = ( void * ) F_1 ;
V_11 = F_1 ;
V_13 = F_1 ;
}
F_5 () ;
}
static void F_6 ( struct V_14 * V_15 ,
enum V_16 V_16 )
{
switch ( V_16 ) {
case V_17 :
if ( V_9 ) {
V_8 = V_9 ;
V_11 = V_10 ;
V_13 = V_12 ;
V_9 = NULL ;
V_10 = NULL ;
V_12 = NULL ;
}
break;
case V_18 :
case V_19 :
break;
}
}
static int T_2 F_7 ( void )
{
return V_14 ( & V_20 ) ;
}
