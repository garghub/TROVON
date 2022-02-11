static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_6 + V_7 ;
T_2 V_8 = F_2 ( V_5 ) ;
if ( V_8 & V_9 ) {
F_3 ( V_9 , V_5 ) ;
return true ;
}
return false ;
}
static void F_4 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_11 + V_12 ;
T_2 V_8 ;
unsigned long V_13 ;
F_5 ( & V_4 -> V_14 , V_13 ) ;
V_8 = F_2 ( V_5 ) ;
if ( V_10 )
V_8 |= V_15 ;
else
V_8 &= ~ V_15 ;
F_3 ( V_8 , V_5 ) ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 , bool V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_11 + V_12 ;
T_2 V_8 ;
unsigned long V_13 ;
F_5 ( & V_4 -> V_14 , V_13 ) ;
V_8 = F_2 ( V_5 ) ;
if ( V_16 )
V_8 |= V_17 ;
else
V_8 &= ~ V_17 ;
F_3 ( V_8 , V_5 ) ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
V_2 = F_9 ( V_21 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_4 = F_9 ( V_21 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
F_10 ( & V_4 -> V_14 ) ;
V_23 = F_11 ( V_19 , V_26 , L_1 ) ;
V_4 -> V_11 = F_12 ( V_21 , V_23 ) ;
if ( F_13 ( V_4 -> V_11 ) )
return F_14 ( V_4 -> V_11 ) ;
V_23 = F_11 ( V_19 , V_26 , L_2 ) ;
V_4 -> V_6 = F_12 ( V_21 , V_23 ) ;
if ( F_13 ( V_4 -> V_6 ) )
return F_14 ( V_4 -> V_6 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_27 = F_1 ;
V_2 -> V_28 = F_4 ;
V_2 -> V_29 = F_7 ;
return F_15 ( V_19 , V_2 ) ;
}
