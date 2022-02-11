static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 &= ~ ( V_6 |
V_7 ) ;
V_4 |= ( V_8 |
V_9 ) ;
V_3 = F_3 ( V_2 , V_5 , V_4 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_3 ( V_2 , V_10 ,
V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_12 == V_13 )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_14 == V_15 )
V_3 = F_2 ( V_2 , V_16 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_14 == V_15 )
V_3 = F_3 ( V_2 , V_17 ,
V_2 -> V_18 -> V_19 == V_20 ?
V_21 :
V_22 ) ;
else {
V_3 = F_2 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 , V_17 , 0 ) ;
}
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_3 ( V_2 , V_10 ,
V_23 ) ;
return V_3 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( V_24 ,
F_10 ( V_24 ) ) ;
}
static void T_2 F_11 ( void )
{
return F_12 ( V_24 ,
F_10 ( V_24 ) ) ;
}
