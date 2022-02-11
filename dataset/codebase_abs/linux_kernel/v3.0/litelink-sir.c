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
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , TRUE , TRUE ) ;
V_5 -> V_7 . V_8 &= V_9 | V_10 | V_11 | V_12 | V_13 ;
V_5 -> V_14 . V_8 = 0x7f ;
F_8 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_15 )
{
int V_16 ;
F_6 ( 2 , L_1 , V_6 ) ;
for ( V_16 = 0 ; V_17 [ V_16 ] != V_15 ; V_16 ++ ) {
if ( V_17 [ V_16 ] == 9600 )
break;
F_7 ( V_3 , FALSE , TRUE ) ;
F_11 ( V_18 ) ;
F_7 ( V_3 , TRUE , TRUE ) ;
F_11 ( V_18 ) ;
}
V_3 -> V_15 = V_17 [ V_16 ] ;
return ( V_3 -> V_15 == V_15 ) ? 0 : - V_19 ;
}
static int F_12 ( struct V_2 * V_3 )
{
F_6 ( 2 , L_1 , V_6 ) ;
F_7 ( V_3 , TRUE , TRUE ) ;
F_11 ( V_18 ) ;
F_7 ( V_3 , TRUE , FALSE ) ;
F_11 ( V_18 ) ;
F_7 ( V_3 , TRUE , TRUE ) ;
F_11 ( V_18 ) ;
V_3 -> V_15 = 115200 ;
return 0 ;
}
