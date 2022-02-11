static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_2 -> V_3 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_7 , V_8 ) ;
return ( V_6 < 0 ) ? V_6 : ( V_6 & V_9 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_11 == V_12 ) {
V_10 = F_5 ( V_2 , V_7 , 0xd401 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 , V_13 , 0xff00 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 , V_13 , 0xff01 , 0x1001 ) ;
} else {
V_10 = F_5 ( V_2 , V_7 , 0xd401 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 , V_13 , 0xff00 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 , V_13 , 0xff01 , 0 ) ;
}
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_7 , 0xcc01 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_7 , V_8 ) ;
V_6 = F_3 ( V_2 , V_7 , V_8 ) ;
if ( V_6 & V_14 )
V_2 -> V_15 = 1 ;
else
V_2 -> V_15 = 0 ;
V_6 = F_3 ( V_2 , V_7 , 0xc800 ) ;
F_8 ( 10 ) ;
V_6 = F_3 ( V_2 , V_7 , 0xc800 ) ;
switch ( V_6 ) {
case 0x9 :
V_2 -> V_16 = V_17 ;
break;
case 0x5 :
V_2 -> V_16 = V_18 ;
break;
case 0x3 :
V_2 -> V_16 = V_19 ;
break;
case 0x7 :
default:
V_2 -> V_16 = V_20 ;
break;
}
V_2 -> V_21 = V_22 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( V_23 ,
F_11 ( V_23 ) ) ;
}
static void T_2 F_12 ( void )
{
return F_13 ( V_23 ,
F_11 ( V_23 ) ) ;
}
