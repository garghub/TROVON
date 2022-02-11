static int T_1 F_1 ( void )
{
F_2 ( 2 , L_1 , V_1 ) ;
return F_3 ( & V_2 ) ;
}
static void T_2 F_4 ( void )
{
F_2 ( 2 , L_1 , V_1 ) ;
F_5 ( & V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_7 ( V_4 , TRUE , TRUE ) ;
V_6 -> V_7 . V_8 &= V_9 | V_10 | V_11 | V_12
| V_13 | V_14 ;
V_6 -> V_15 . V_8 = 0x01 ;
F_8 ( V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
F_2 ( 2 , L_1 , V_1 ) ;
F_7 ( V_4 , FALSE , FALSE ) ;
return 0 ;
}
static T_3 F_10 ( T_4 V_16 )
{
T_3 V_17 ;
switch ( V_16 ) {
default:
case 115200 :
V_17 = V_18 ;
break;
case 57600 :
V_17 = V_19 ;
break;
case 38400 :
V_17 = V_20 ;
break;
case 19200 :
V_17 = V_21 ;
break;
case 9600 :
V_17 = V_22 ;
break;
case 2400 :
V_17 = V_23 ;
break;
}
return V_17 ;
}
static int F_11 ( struct V_3 * V_4 , unsigned V_16 )
{
T_5 V_17 ;
F_2 ( 2 , L_2 , V_1 ,
V_16 , V_4 -> V_16 ) ;
F_7 ( V_4 , TRUE , FALSE ) ;
F_12 ( 1 ) ;
V_17 = F_10 ( V_16 ) ;
F_13 ( V_4 , & V_17 , sizeof( V_17 ) ) ;
F_14 ( 15 ) ;
#if 1
F_15 ( V_4 , & V_17 , sizeof( V_17 ) ) ;
if ( V_17 != F_10 ( V_16 ) ) {
F_16 ( L_3 ,
V_1 , ( unsigned ) V_17 ,
( unsigned ) F_10 ( V_16 ) ) ;
return - 1 ;
}
else
F_2 ( 2 , L_4 , V_1 ) ;
#endif
F_7 ( V_4 , TRUE , TRUE ) ;
F_14 ( 10 ) ;
V_4 -> V_16 = V_16 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
F_2 ( 2 , L_1 , V_1 ) ;
F_7 ( V_4 , FALSE , TRUE ) ;
F_14 ( 10 ) ;
F_7 ( V_4 , TRUE , TRUE ) ;
F_14 ( 10 ) ;
V_4 -> V_16 = 9600 ;
return 0 ;
}
