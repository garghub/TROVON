static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
return F_3 ( V_2 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_8 == V_9 )
V_7 = F_2 ( V_2 , V_10 ,
V_11 ) ;
else
V_7 = F_2 ( V_2 , V_10 , 0 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_12 = F_3 ( V_2 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_2 ( V_2 , V_14 , V_12 & ~ 0x7 ) ;
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 , int V_15 )
{
int V_16 = F_3 ( V_2 , V_17 ) ;
F_2 ( V_2 , V_17 , ( V_16 | V_18 ) ) ;
F_2 ( V_2 , V_19 , 0 ) ;
F_2 ( V_2 , V_4 , 0x1C0 ) ;
F_2 ( V_2 , V_5 , 0x0008 ) ;
F_2 ( V_2 , V_17 , ( V_16 & ~ V_18 ) ) ;
F_2 ( V_2 , V_20 , V_15 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_21 )
{
if ( V_21 )
F_4 ( V_2 , 0x1c0 , F_1 ( V_2 , 0x1c0 ) | 1 ) ;
else
F_4 ( V_2 , 0x1c0 ,
F_1 ( V_2 , 0x1c0 ) & 0xfffe ) ;
F_9 ( L_1 ,
( F_1 ( V_2 , 0x1c0 ) & 0x0001 ) ? L_2 : L_3 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_22 ) ;
F_8 ( V_2 , V_23 ) ;
return F_6 ( V_2 ) ;
}
