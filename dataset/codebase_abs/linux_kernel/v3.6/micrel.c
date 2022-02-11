static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = ( V_6 == V_2 -> V_7 ) ?
V_8 : 0 ;
return F_4 ( V_2 , V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_5 , V_3 ;
V_5 = F_2 ( V_2 , V_9 ) ;
V_5 &= ~ V_10 ;
F_4 ( V_2 , V_9 , V_5 ) ;
V_3 = F_3 ( V_2 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_5 , V_3 ;
V_5 = F_2 ( V_2 , V_9 ) ;
V_5 &= ~ V_11 ;
F_4 ( V_2 , V_9 , V_5 ) ;
V_3 = F_3 ( V_2 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 , V_3 ;
V_5 = F_2 ( V_2 , V_9 ) ;
V_5 &= ~ V_12 ;
F_4 ( V_2 , V_9 , V_5 ) ;
V_3 = F_3 ( V_2 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
const T_1 V_13 = V_14 | V_15 ;
F_4 ( V_2 , V_16 , V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_17 ;
if ( V_2 -> V_18 & V_19 ) {
V_17 = F_2 ( V_2 , V_9 ) ;
V_17 |= V_20 ;
F_4 ( V_2 , V_9 , V_17 ) ;
}
return 0 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( V_21 ,
F_13 ( V_21 ) ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( V_21 ,
F_13 ( V_21 ) ) ;
}
