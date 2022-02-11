static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = F_2 ( V_4 ) ;
T_1 V_12 , V_13 ;
int V_14 ;
switch ( V_11 ) {
case 96000 :
V_13 = 256 * V_11 ;
break;
default:
V_13 = 512 * V_11 ;
break;
}
if ( V_13 < 8000000 || V_13 > 27000000 )
return - V_15 ;
V_14 = F_3 ( V_9 , V_16 , V_13 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_3 ( V_10 , V_17 , V_13 , 0 ) ;
if ( V_14 )
return V_14 ;
V_12 = V_18 | V_19 |
V_20 ;
V_14 = F_4 ( V_9 , V_12 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_10 , V_12 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int T_2 F_5 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_25 ;
int V_14 ;
V_14 = F_6 ( 0 , 44100 * 256 , 44100 ) ;
if ( V_14 )
return V_14 ;
V_24 -> V_26 = & V_22 -> V_26 ;
F_7 ( V_22 , V_24 ) ;
V_14 = F_8 ( V_24 ) ;
if ( V_14 ) {
F_9 ( & V_22 -> V_26 , L_1 ,
V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int T_3 F_10 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_11 ( V_22 ) ;
F_12 ( 0 ) ;
F_13 ( V_24 ) ;
return 0 ;
}
static int T_4 F_14 ( void )
{
return F_15 ( & V_27 ) ;
}
static void T_5 F_16 ( void )
{
F_17 ( & V_27 ) ;
}
