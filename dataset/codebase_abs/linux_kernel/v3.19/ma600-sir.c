static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
F_6 ( V_3 , TRUE , TRUE ) ;
V_5 -> V_6 . V_7 &= V_8 | V_9 | V_10 | V_11
| V_12 | V_13 ;
V_5 -> V_14 . V_7 = 0x01 ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_6 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static T_3 F_9 ( T_4 V_15 )
{
T_3 V_16 ;
switch ( V_15 ) {
default:
case 115200 :
V_16 = V_17 ;
break;
case 57600 :
V_16 = V_18 ;
break;
case 38400 :
V_16 = V_19 ;
break;
case 19200 :
V_16 = V_20 ;
break;
case 9600 :
V_16 = V_21 ;
break;
case 2400 :
V_16 = V_22 ;
break;
}
return V_16 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_15 )
{
T_5 V_16 ;
F_11 ( L_1 , V_23 ,
V_15 , V_3 -> V_15 ) ;
F_6 ( V_3 , TRUE , FALSE ) ;
F_12 ( 1 ) ;
V_16 = F_9 ( V_15 ) ;
F_13 ( V_3 , & V_16 , sizeof( V_16 ) ) ;
F_14 ( 15 ) ;
#if 1
F_15 ( V_3 , & V_16 , sizeof( V_16 ) ) ;
if ( V_16 != F_9 ( V_15 ) ) {
F_16 ( L_2 ,
V_23 , ( unsigned ) V_16 ,
( unsigned ) F_9 ( V_15 ) ) ;
return - 1 ;
}
else
F_11 ( L_3 , V_23 ) ;
#endif
F_6 ( V_3 , TRUE , TRUE ) ;
F_14 ( 10 ) ;
V_3 -> V_15 = V_15 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
F_6 ( V_3 , FALSE , TRUE ) ;
F_14 ( 10 ) ;
F_6 ( V_3 , TRUE , TRUE ) ;
F_14 ( 10 ) ;
V_3 -> V_15 = 9600 ;
return 0 ;
}
