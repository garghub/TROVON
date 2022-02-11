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
F_6 ( V_3 , FALSE , TRUE ) ;
V_5 -> V_6 . V_7 &= V_8 | V_9 | V_10 ;
V_5 -> V_11 . V_7 = 0x01 ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_6 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_12 )
{
int V_13 = 0 ;
int V_14 , V_15 ;
switch ( V_12 ) {
case 19200 :
V_14 = TRUE ;
V_15 = FALSE ;
break;
case 115200 :
V_14 = V_15 = TRUE ;
break;
default:
V_13 = - V_16 ;
V_12 = 9600 ;
case 9600 :
V_14 = FALSE ;
V_15 = TRUE ;
break;
}
F_6 ( V_3 , V_14 , V_15 ) ;
V_3 -> V_12 = V_12 ;
return V_13 ;
}
static int F_10 ( struct V_2 * V_3 )
{
F_6 ( V_3 , FALSE , FALSE ) ;
F_6 ( V_3 , FALSE , TRUE ) ;
V_3 -> V_12 = 9600 ;
return 0 ;
}
