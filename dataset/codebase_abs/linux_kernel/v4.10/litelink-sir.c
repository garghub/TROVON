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
V_5 -> V_6 . V_7 &= V_8 | V_9 | V_10 | V_11 | V_12 ;
V_5 -> V_13 . V_7 = 0x7f ;
F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_6 ( V_3 , FALSE , FALSE ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_16 [ V_15 ] != V_14 ; V_15 ++ ) {
if ( V_16 [ V_15 ] == 9600 )
break;
F_6 ( V_3 , FALSE , TRUE ) ;
F_10 ( V_17 ) ;
F_6 ( V_3 , TRUE , TRUE ) ;
F_10 ( V_17 ) ;
}
V_3 -> V_14 = V_16 [ V_15 ] ;
return ( V_3 -> V_14 == V_14 ) ? 0 : - V_18 ;
}
static int F_11 ( struct V_2 * V_3 )
{
F_6 ( V_3 , TRUE , TRUE ) ;
F_10 ( V_17 ) ;
F_6 ( V_3 , TRUE , FALSE ) ;
F_10 ( V_17 ) ;
F_6 ( V_3 , TRUE , TRUE ) ;
F_10 ( V_17 ) ;
V_3 -> V_14 = 115200 ;
return 0 ;
}
