static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_4 * V_2 -> V_5 , V_6 + V_7 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_2 ( & V_3 ) ;
F_3 ( V_4 * V_2 -> V_5 , V_6 + V_7 ) ;
V_8 = F_6 ( V_9 ) ;
V_8 &= ~ V_10 ;
F_3 ( V_8 , V_9 ) ;
V_8 = F_6 ( V_6 + V_11 ) ;
V_8 |= V_12 ;
F_3 ( V_8 , V_6 + V_11 ) ;
V_8 = F_6 ( V_13 ) ;
V_8 |= V_14 ;
F_3 ( V_8 , V_13 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_2 ( & V_3 ) ;
V_8 = F_6 ( V_13 ) ;
V_8 &= ~ V_14 ;
F_3 ( V_8 , V_13 ) ;
V_8 = F_6 ( V_6 + V_11 ) ;
V_8 &= ~ V_12 ;
F_3 ( V_8 , V_6 + V_11 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
F_2 ( & V_3 ) ;
V_15 = F_6 ( V_6 + V_7 ) / V_4 ;
F_4 ( & V_3 ) ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
V_2 -> V_5 = V_5 ;
return 0 ;
}
static int T_2 F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
V_21 = F_11 ( & V_17 -> V_22 , NULL ) ;
if ( F_12 ( V_21 ) ) {
F_13 ( & V_17 -> V_22 , L_1 ) ;
return - V_23 ;
}
F_14 ( V_21 ) ;
V_4 = F_15 ( V_21 ) ;
V_19 = F_16 ( V_17 , V_24 , 0 ) ;
V_6 = F_17 ( & V_17 -> V_22 , V_19 -> V_25 , F_18 ( V_19 ) ) ;
if ( ! V_6 )
return - V_26 ;
V_27 = V_28 / V_4 ;
if ( ( V_29 < 1 ) || ( V_29 > V_27 ) )
V_29 = V_27 ;
V_30 . V_5 = V_29 ;
V_30 . V_31 = 1 ;
V_30 . V_32 = V_27 ;
F_19 ( & V_30 , V_33 ) ;
V_20 = F_20 ( & V_30 ) ;
if ( V_20 ) {
F_21 ( V_21 ) ;
return V_20 ;
}
F_22 ( L_2 ,
V_29 , V_33 ? L_3 : L_4 ) ;
return 0 ;
}
static int T_3 F_23 ( struct V_16 * V_17 )
{
F_24 ( & V_30 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
static void F_25 ( struct V_16 * V_17 )
{
F_7 ( & V_30 ) ;
}
