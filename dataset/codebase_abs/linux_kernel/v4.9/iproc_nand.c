static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 + V_7 ;
T_2 V_8 = F_3 ( V_5 ) ;
if ( V_8 & V_9 ) {
F_4 ( V_9 , V_5 ) ;
return true ;
}
return false ;
}
static void F_5 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_1 * V_5 = V_4 -> V_11 + V_12 ;
T_2 V_8 ;
unsigned long V_13 ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
V_8 = F_3 ( V_5 ) ;
if ( V_10 )
V_8 |= V_15 ;
else
V_8 &= ~ V_15 ;
F_4 ( V_8 , V_5 ) ;
F_7 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_16 ,
bool V_17 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_1 * V_5 = V_4 -> V_11 + V_12 ;
T_2 V_8 ;
unsigned long V_13 ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
V_8 = F_3 ( V_5 ) ;
if ( F_9 ( V_18 ) || ! V_17 ) {
if ( V_16 )
V_8 |= V_19 ;
else
V_8 &= ~ V_19 ;
} else {
V_8 &= ~ V_19 ;
}
F_4 ( V_8 , V_5 ) ;
F_7 ( & V_4 -> V_14 , V_13 ) ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
V_4 = F_11 ( V_23 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_2 = & V_4 -> V_2 ;
F_12 ( & V_4 -> V_14 ) ;
V_25 = F_13 ( V_21 , V_28 , L_1 ) ;
V_4 -> V_11 = F_14 ( V_23 , V_25 ) ;
if ( F_15 ( V_4 -> V_11 ) )
return F_16 ( V_4 -> V_11 ) ;
V_25 = F_13 ( V_21 , V_28 , L_2 ) ;
V_4 -> V_6 = F_14 ( V_23 , V_25 ) ;
if ( F_15 ( V_4 -> V_6 ) )
return F_16 ( V_4 -> V_6 ) ;
V_2 -> V_29 = F_1 ;
V_2 -> V_30 = F_5 ;
V_2 -> V_31 = F_8 ;
return F_17 ( V_21 , V_2 ) ;
}
