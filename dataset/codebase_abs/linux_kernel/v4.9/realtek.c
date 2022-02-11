static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
F_4 ( V_2 , V_5 , 0xa43 ) ;
V_3 = F_2 ( V_2 , V_6 ) ;
F_4 ( V_2 , V_5 , 0x0 ) ;
return ( V_3 < 0 ) ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_7 == V_8 )
V_3 = F_4 ( V_2 , V_9 ,
V_10 ) ;
else
V_3 = F_4 ( V_2 , V_9 , 0 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_7 == V_8 )
V_3 = F_4 ( V_2 , V_9 ,
V_11 ) ;
else
V_3 = F_4 ( V_2 , V_9 , 0 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_7 == V_8 )
V_3 = F_4 ( V_2 , V_9 ,
V_12 ) ;
else
V_3 = F_4 ( V_2 , V_9 , 0 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_14 ;
V_13 = F_9 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_4 ( V_2 , V_5 , 0xd08 ) ;
V_14 = F_2 ( V_2 , 0x11 ) ;
if ( V_2 -> V_15 == V_16 ||
V_2 -> V_15 == V_17 )
V_14 |= V_18 ;
else
V_14 &= ~ V_18 ;
F_4 ( V_2 , 0x11 , V_14 ) ;
F_4 ( V_2 , V_5 , 0x0 ) ;
return 0 ;
}
