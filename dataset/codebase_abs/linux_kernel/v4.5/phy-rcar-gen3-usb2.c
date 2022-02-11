static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 . V_6 ;
T_2 V_7 = F_2 ( V_4 + V_8 ) ;
F_3 ( & V_2 -> V_9 -> V_10 , L_1 , V_11 , V_7 , V_3 ) ;
if ( V_3 )
V_7 &= ~ V_12 ;
else
V_7 |= V_12 ;
F_4 ( V_7 , V_4 + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_13 , int V_14 )
{
void T_1 * V_4 = V_2 -> V_5 . V_6 ;
T_2 V_7 = F_2 ( V_4 + V_15 ) ;
F_3 ( & V_2 -> V_9 -> V_10 , L_2 , V_11 , V_7 , V_13 , V_14 ) ;
V_7 &= ~ ( V_16 | V_17 ) ;
if ( V_13 )
V_7 |= V_16 ;
if ( V_14 )
V_7 |= V_17 ;
F_4 ( V_7 , V_4 + V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_18 )
{
void T_1 * V_4 = V_2 -> V_5 . V_6 ;
T_2 V_7 = F_2 ( V_4 + V_19 ) ;
F_3 ( & V_2 -> V_9 -> V_10 , L_1 , V_11 , V_7 , V_18 ) ;
if ( V_18 )
V_7 |= V_20 ;
else
V_7 &= ~ V_20 ;
F_4 ( V_7 , V_4 + V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 1 , 1 ) ;
F_1 ( V_2 , 1 ) ;
F_6 ( V_2 , 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , 1 ) ;
F_1 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_5 . V_6 + V_19 ) &
V_21 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_5 . V_6 + V_19 ) & V_22 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
bool V_23 = true ;
if ( F_10 ( V_2 ) && F_9 ( V_2 ) )
V_23 = false ;
if ( V_23 )
F_7 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 . V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_4 + V_24 ) ;
F_4 ( V_7 | V_25 , V_4 + V_24 ) ;
F_4 ( V_26 , V_4 + V_27 ) ;
V_7 = F_2 ( V_4 + V_28 ) ;
F_4 ( V_7 | V_26 , V_4 + V_28 ) ;
V_7 = F_2 ( V_4 + V_19 ) ;
F_4 ( V_7 | V_29 , V_4 + V_19 ) ;
V_7 = F_2 ( V_4 + V_15 ) ;
F_5 ( V_2 , 0 , 0 ) ;
F_4 ( V_7 | V_30 | V_31 ,
V_4 + V_15 ) ;
F_11 ( V_2 ) ;
}
static int F_13 ( struct V_9 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
void T_1 * V_4 = V_33 -> V_5 . V_6 ;
void T_1 * V_34 = V_33 -> V_35 . V_6 ;
T_2 V_7 ;
F_4 ( V_36 , V_4 + V_37 ) ;
F_4 ( V_38 , V_4 + V_39 ) ;
F_4 ( V_40 , V_4 + V_41 ) ;
if ( V_34 ) {
V_7 = F_2 ( V_34 + V_42 ) ;
V_7 = ( V_7 & ~ V_43 ) |
V_44 ;
F_4 ( V_7 & V_45 , V_34 + V_42 ) ;
F_12 ( V_33 ) ;
}
return 0 ;
}
static int F_15 ( struct V_9 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
F_4 ( 0 , V_33 -> V_5 . V_6 + V_37 ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
void T_1 * V_4 = V_33 -> V_5 . V_6 ;
void T_1 * V_34 = V_33 -> V_35 . V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_4 + V_46 ) ;
V_7 |= V_47 ;
F_4 ( V_7 , V_4 + V_46 ) ;
V_7 &= ~ V_47 ;
F_4 ( V_7 , V_4 + V_46 ) ;
if ( V_34 ) {
V_7 = F_17 ( V_34 + V_48 ) ;
V_7 |= V_49 ;
F_18 ( V_7 , V_34 + V_48 ) ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
void T_1 * V_34 = V_33 -> V_35 . V_6 ;
T_2 V_7 ;
if ( V_34 ) {
V_7 = F_17 ( V_34 + V_48 ) ;
V_7 &= ~ V_49 ;
F_18 ( V_7 , V_34 + V_48 ) ;
}
return 0 ;
}
static T_3 F_20 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
void T_1 * V_4 = V_2 -> V_5 . V_6 ;
T_2 V_52 = F_2 ( V_4 + V_27 ) ;
T_3 V_53 = V_54 ;
if ( V_52 & V_26 ) {
F_3 ( & V_2 -> V_9 -> V_10 , L_3 , V_11 , V_52 ) ;
F_4 ( V_26 , V_4 + V_27 ) ;
F_11 ( V_2 ) ;
V_53 = V_55 ;
}
return V_53 ;
}
static int F_21 ( struct V_56 * V_57 )
{
struct V_58 * V_10 = & V_57 -> V_10 ;
struct V_1 * V_33 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
if ( ! V_10 -> V_63 ) {
F_22 ( V_10 , L_4 ) ;
return - V_64 ;
}
V_33 = F_23 ( V_10 , sizeof( * V_33 ) , V_65 ) ;
if ( ! V_33 )
return - V_66 ;
V_62 = F_24 ( V_57 , V_67 , L_5 ) ;
V_33 -> V_5 . V_6 = F_25 ( V_10 , V_62 ) ;
if ( F_26 ( V_33 -> V_5 . V_6 ) )
return F_27 ( V_33 -> V_5 . V_6 ) ;
V_62 = F_24 ( V_57 , V_67 , L_6 ) ;
if ( V_62 ) {
int V_50 ;
V_33 -> V_35 . V_6 = F_25 ( V_10 , V_62 ) ;
if ( F_26 ( V_33 -> V_35 . V_6 ) )
V_33 -> V_35 . V_6 = NULL ;
V_50 = F_28 ( V_57 , 0 ) ;
if ( V_50 >= 0 )
V_50 = F_29 ( V_10 , V_50 , F_20 ,
V_68 , F_30 ( V_10 ) ,
V_33 ) ;
if ( V_50 < 0 )
F_22 ( V_10 , L_7 , V_50 ) ;
}
V_33 -> V_9 = F_31 ( V_10 , NULL , & V_69 ) ;
if ( F_26 ( V_33 -> V_9 ) ) {
F_22 ( V_10 , L_8 ) ;
return F_27 ( V_33 -> V_9 ) ;
}
F_32 ( V_33 -> V_9 , V_33 ) ;
V_60 = F_33 ( V_10 , V_70 ) ;
if ( F_26 ( V_60 ) )
F_22 ( V_10 , L_9 ) ;
return F_34 ( V_60 ) ;
}
