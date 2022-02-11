static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & V_5 ) {
V_3 = F_2 ( V_2 , V_6 ) ;
V_3 |= V_7 ;
return F_3 ( V_2 , V_6 , V_3 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_2 ( V_2 , V_9 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = ( V_11 == V_2 -> V_12 ) ?
V_13 : 0 ;
return F_3 ( V_2 , V_9 , V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 , V_8 ;
V_10 = F_2 ( V_2 , V_6 ) ;
V_10 &= ~ V_14 ;
F_3 ( V_2 , V_6 , V_10 ) ;
V_8 = F_5 ( V_2 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_10 , V_8 ;
V_10 = F_2 ( V_2 , V_6 ) ;
V_10 &= ~ V_15 ;
F_3 ( V_2 , V_6 , V_10 ) ;
V_8 = F_5 ( V_2 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_10 , V_8 ;
V_10 = F_2 ( V_2 , V_6 ) ;
V_10 &= ~ V_16 ;
F_3 ( V_2 , V_6 , V_10 ) ;
V_8 = F_5 ( V_2 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_8 ;
const T_1 V_17 = V_18 | V_19 ;
F_3 ( V_2 , V_20 , V_17 ) ;
V_8 = F_1 ( V_2 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_1 ( V_2 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_21 ) ;
V_3 = F_2 ( V_2 , V_21 ) ;
if ( V_3 & V_22 )
V_2 -> V_23 = V_24 ;
else
V_2 -> V_23 = V_25 ;
if ( V_3 & V_26 )
V_2 -> V_27 = V_28 ;
else
V_2 -> V_27 = V_29 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = V_2 -> V_32 = 0 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( V_33 ,
F_16 ( V_33 ) ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( V_33 ,
F_16 ( V_33 ) ) ;
}
