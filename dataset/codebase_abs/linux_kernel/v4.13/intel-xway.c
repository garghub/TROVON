static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_3 = F_2 ( V_2 , V_6 , 0 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_2 , V_7 ) ;
F_4 ( V_2 , V_8 , V_9 ,
V_10 |
V_11 |
V_12 ) ;
F_4 ( V_2 , V_8 , V_13 ,
V_14 |
V_15 ) ;
V_4 = V_16 | V_17 ;
V_5 = V_18 | V_19 |
V_20 ;
F_4 ( V_2 , V_8 , V_21 , V_4 ) ;
F_4 ( V_2 , V_8 , V_22 , V_5 ) ;
F_4 ( V_2 , V_8 , V_23 , V_4 ) ;
F_4 ( V_2 , V_8 , V_24 , V_5 ) ;
F_4 ( V_2 , V_8 , V_25 , V_4 ) ;
F_4 ( V_2 , V_8 , V_26 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_27 , V_3 ;
V_27 = F_3 ( V_2 , V_28 ) ;
V_27 |= V_29 ;
V_3 = F_2 ( V_2 , V_28 , V_27 ) ;
if ( V_3 )
return V_3 ;
return F_6 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_3 ( V_2 , V_7 ) ;
return ( V_27 < 0 ) ? V_27 : 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_3 ( V_2 , V_7 ) ;
return V_27 & V_30 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_31 = 0 ;
if ( V_2 -> V_32 == V_33 )
V_31 = V_30 ;
return F_2 ( V_2 , V_6 , V_31 ) ;
}
