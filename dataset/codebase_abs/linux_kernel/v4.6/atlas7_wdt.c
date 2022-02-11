static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_6 , V_7 ;
V_5 = F_3 ( V_4 -> V_8 + V_9 ) ;
V_6 = F_3 ( V_4 -> V_8 + V_10 ) ;
V_7 = V_6 - V_5 ;
return V_7 / V_4 -> V_11 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_6 , V_7 ;
V_5 = F_3 ( V_4 -> V_8 + V_9 ) ;
V_7 = V_2 -> V_12 * V_4 -> V_11 ;
V_6 = V_5 + V_7 ;
F_5 ( V_6 , V_4 -> V_8 + V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( F_3 ( V_4 -> V_8 + V_13 ) | V_14 ,
V_4 -> V_8 + V_13 ) ;
F_5 ( 1 , V_4 -> V_8 + V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( 0 , V_4 -> V_8 + V_15 ) ;
F_5 ( F_3 ( V_4 -> V_8 + V_13 ) & ~ V_14 ,
V_4 -> V_8 + V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_16 )
{
V_2 -> V_12 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 . V_22 ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
struct V_25 * V_25 ;
int V_26 ;
V_4 = F_10 ( & V_18 -> V_21 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_24 = F_11 ( V_18 , V_29 , 0 ) ;
V_4 -> V_8 = F_12 ( & V_18 -> V_21 , V_24 ) ;
if ( F_13 ( V_4 -> V_8 ) )
return F_14 ( V_4 -> V_8 ) ;
V_25 = F_15 ( V_20 , 0 ) ;
if ( F_13 ( V_25 ) )
return F_14 ( V_25 ) ;
V_26 = F_16 ( V_25 ) ;
if ( V_26 ) {
F_17 ( & V_18 -> V_21 , L_1 ) ;
goto V_30;
}
F_5 ( 0 , V_4 -> V_8 + V_13 ) ;
V_4 -> V_11 = F_18 ( V_25 ) ;
if ( ! V_4 -> V_11 ) {
V_26 = - V_31 ;
goto V_32;
}
V_4 -> V_25 = V_25 ;
V_33 . V_34 = 1 ;
V_33 . V_35 = V_36 / V_4 -> V_11 ;
F_19 ( & V_33 , 0 , & V_18 -> V_21 ) ;
F_20 ( & V_33 , V_37 ) ;
F_21 ( & V_33 , V_4 ) ;
F_22 ( V_18 , & V_33 ) ;
V_26 = F_23 ( & V_33 ) ;
if ( V_26 )
goto V_32;
return 0 ;
V_32:
F_24 ( V_25 ) ;
V_30:
F_25 ( V_25 ) ;
return V_26 ;
}
static void F_26 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_27 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_2 ) ;
F_24 ( V_4 -> V_25 ) ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_27 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_26 ( V_18 ) ;
F_25 ( V_4 -> V_25 ) ;
return 0 ;
}
static int T_2 F_29 ( struct V_38 * V_21 )
{
return 0 ;
}
static int T_2 F_30 ( struct V_38 * V_21 )
{
struct V_1 * V_2 = F_31 ( V_21 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
