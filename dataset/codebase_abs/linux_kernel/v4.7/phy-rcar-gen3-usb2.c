static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
F_3 ( & V_2 -> V_8 -> V_9 , L_1 , V_10 , V_6 , V_3 ) ;
if ( V_3 )
V_6 &= ~ V_11 ;
else
V_6 |= V_11 ;
F_4 ( V_6 , V_4 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_12 , int V_13 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_14 ) ;
F_3 ( & V_2 -> V_8 -> V_9 , L_2 , V_10 , V_6 , V_12 , V_13 ) ;
V_6 &= ~ ( V_15 | V_16 ) ;
if ( V_12 )
V_6 |= V_15 ;
if ( V_13 )
V_6 |= V_16 ;
F_4 ( V_6 , V_4 + V_14 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_17 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_18 ) ;
F_3 ( & V_2 -> V_8 -> V_9 , L_1 , V_10 , V_6 , V_17 ) ;
if ( V_17 )
V_6 |= V_19 ;
else
V_6 &= ~ V_19 ;
F_4 ( V_6 , V_4 + V_18 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 1 , 1 ) ;
F_1 ( V_2 , 1 ) ;
F_6 ( V_2 , 1 ) ;
F_8 ( V_2 -> V_20 , V_21 , true ) ;
F_8 ( V_2 -> V_20 , V_22 , false ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , 1 ) ;
F_1 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_8 ( V_2 -> V_20 , V_21 , false ) ;
F_8 ( V_2 -> V_20 , V_22 , true ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_5 + V_18 ) & V_23 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( ! F_10 ( V_2 ) )
F_7 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_24 ) ;
F_4 ( V_6 | V_25 , V_4 + V_24 ) ;
F_4 ( V_26 , V_4 + V_27 ) ;
V_6 = F_2 ( V_4 + V_28 ) ;
F_4 ( V_6 | V_26 , V_4 + V_28 ) ;
V_6 = F_2 ( V_4 + V_18 ) ;
F_4 ( V_6 | V_29 , V_4 + V_18 ) ;
V_6 = F_2 ( V_4 + V_14 ) ;
F_5 ( V_2 , 0 , 0 ) ;
F_4 ( V_6 | V_30 | V_31 ,
V_4 + V_14 ) ;
F_11 ( V_2 ) ;
}
static int F_13 ( struct V_8 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
void T_1 * V_4 = V_33 -> V_5 ;
F_4 ( V_34 , V_4 + V_35 ) ;
F_4 ( V_36 , V_4 + V_37 ) ;
F_4 ( V_38 , V_4 + V_39 ) ;
if ( V_33 -> V_40 )
F_12 ( V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
F_4 ( 0 , V_33 -> V_5 + V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
void T_1 * V_4 = V_33 -> V_5 ;
T_2 V_6 ;
int V_41 ;
if ( V_33 -> V_17 ) {
V_41 = F_17 ( V_33 -> V_17 ) ;
if ( V_41 )
return V_41 ;
}
V_6 = F_2 ( V_4 + V_42 ) ;
V_6 |= V_43 ;
F_4 ( V_6 , V_4 + V_42 ) ;
V_6 &= ~ V_43 ;
F_4 ( V_6 , V_4 + V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_8 * V_32 )
{
struct V_1 * V_33 = F_14 ( V_32 ) ;
int V_41 = 0 ;
if ( V_33 -> V_17 )
V_41 = F_19 ( V_33 -> V_17 ) ;
return V_41 ;
}
static T_3 F_20 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_46 = F_2 ( V_4 + V_27 ) ;
T_3 V_41 = V_47 ;
if ( V_46 & V_26 ) {
F_3 ( & V_2 -> V_8 -> V_9 , L_3 , V_10 , V_46 ) ;
F_4 ( V_26 , V_4 + V_27 ) ;
F_11 ( V_2 ) ;
V_41 = V_48 ;
}
return V_41 ;
}
static int F_21 ( struct V_49 * V_50 )
{
struct V_51 * V_9 = & V_50 -> V_9 ;
struct V_1 * V_33 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_44 ;
if ( ! V_9 -> V_56 ) {
F_22 ( V_9 , L_4 ) ;
return - V_57 ;
}
V_33 = F_23 ( V_9 , sizeof( * V_33 ) , V_58 ) ;
if ( ! V_33 )
return - V_59 ;
V_55 = F_24 ( V_50 , V_60 , 0 ) ;
V_33 -> V_5 = F_25 ( V_9 , V_55 ) ;
if ( F_26 ( V_33 -> V_5 ) )
return F_27 ( V_33 -> V_5 ) ;
V_44 = F_28 ( V_50 , 0 ) ;
if ( V_44 >= 0 ) {
int V_41 ;
V_44 = F_29 ( V_9 , V_44 , F_20 ,
V_61 , F_30 ( V_9 ) , V_33 ) ;
if ( V_44 < 0 )
F_22 ( V_9 , L_5 , V_44 ) ;
V_33 -> V_40 = true ;
V_33 -> V_20 = F_31 ( V_9 ,
V_62 ) ;
if ( F_26 ( V_33 -> V_20 ) )
return F_27 ( V_33 -> V_20 ) ;
V_41 = F_32 ( V_9 , V_33 -> V_20 ) ;
if ( V_41 < 0 ) {
F_22 ( V_9 , L_6 ) ;
return V_41 ;
}
}
V_33 -> V_8 = F_33 ( V_9 , NULL , & V_63 ) ;
if ( F_26 ( V_33 -> V_8 ) ) {
F_22 ( V_9 , L_7 ) ;
return F_27 ( V_33 -> V_8 ) ;
}
V_33 -> V_17 = F_34 ( V_9 , L_8 ) ;
if ( F_26 ( V_33 -> V_17 ) ) {
if ( F_27 ( V_33 -> V_17 ) == - V_64 )
return F_27 ( V_33 -> V_17 ) ;
V_33 -> V_17 = NULL ;
}
F_35 ( V_33 -> V_8 , V_33 ) ;
V_53 = F_36 ( V_9 , V_65 ) ;
if ( F_26 ( V_53 ) )
F_22 ( V_9 , L_9 ) ;
return F_37 ( V_53 ) ;
}
