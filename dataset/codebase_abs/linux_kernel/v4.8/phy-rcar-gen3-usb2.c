static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 ) ;
if ( V_4 -> V_5 ) {
F_3 ( V_4 -> V_6 , V_7 , true ) ;
F_3 ( V_4 -> V_6 , V_8 , false ) ;
} else {
F_3 ( V_4 -> V_6 , V_7 , false ) ;
F_3 ( V_4 -> V_6 , V_8 , true ) ;
}
}
static void F_4 ( struct V_3 * V_4 , int V_9 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 = F_5 ( V_10 + V_13 ) ;
F_6 ( & V_4 -> V_14 -> V_15 , L_1 , V_16 , V_12 , V_9 ) ;
if ( V_9 )
V_12 &= ~ V_17 ;
else
V_12 |= V_17 ;
F_7 ( V_12 , V_10 + V_13 ) ;
}
static void F_8 ( struct V_3 * V_4 , int V_18 , int V_19 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 = F_5 ( V_10 + V_20 ) ;
F_6 ( & V_4 -> V_14 -> V_15 , L_2 , V_16 , V_12 , V_18 , V_19 ) ;
V_12 &= ~ ( V_21 | V_22 ) ;
if ( V_18 )
V_12 |= V_21 ;
if ( V_19 )
V_12 |= V_22 ;
F_7 ( V_12 , V_10 + V_20 ) ;
}
static void F_9 ( struct V_3 * V_4 , int V_23 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 = F_5 ( V_10 + V_24 ) ;
F_6 ( & V_4 -> V_14 -> V_15 , L_1 , V_16 , V_12 , V_23 ) ;
if ( V_23 )
V_12 |= V_25 ;
else
V_12 &= ~ V_25 ;
F_7 ( V_12 , V_10 + V_24 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_8 ( V_4 , 1 , 1 ) ;
F_4 ( V_4 , 1 ) ;
F_9 ( V_4 , 1 ) ;
V_4 -> V_5 = true ;
F_11 ( & V_4 -> V_2 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_8 ( V_4 , 0 , 1 ) ;
F_4 ( V_4 , 0 ) ;
F_9 ( V_4 , 0 ) ;
V_4 -> V_5 = false ;
F_11 ( & V_4 -> V_2 ) ;
}
static bool F_13 ( struct V_3 * V_4 )
{
return ! ! ( F_5 ( V_4 -> V_11 + V_24 ) & V_26 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
if ( ! F_13 ( V_4 ) )
F_10 ( V_4 ) ;
else
F_12 ( V_4 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_12 ;
V_12 = F_5 ( V_10 + V_27 ) ;
F_7 ( V_12 | V_28 , V_10 + V_27 ) ;
F_7 ( V_29 , V_10 + V_30 ) ;
V_12 = F_5 ( V_10 + V_31 ) ;
F_7 ( V_12 | V_29 , V_10 + V_31 ) ;
V_12 = F_5 ( V_10 + V_24 ) ;
F_7 ( V_12 | V_32 , V_10 + V_24 ) ;
V_12 = F_5 ( V_10 + V_20 ) ;
F_8 ( V_4 , 0 , 0 ) ;
F_7 ( V_12 | V_33 | V_34 ,
V_10 + V_20 ) ;
F_14 ( V_4 ) ;
}
static int F_16 ( struct V_14 * V_35 )
{
struct V_3 * V_36 = F_17 ( V_35 ) ;
void T_1 * V_10 = V_36 -> V_11 ;
F_7 ( V_37 , V_10 + V_38 ) ;
F_7 ( V_39 , V_10 + V_40 ) ;
F_7 ( V_41 , V_10 + V_42 ) ;
if ( V_36 -> V_43 )
F_15 ( V_36 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_35 )
{
struct V_3 * V_36 = F_17 ( V_35 ) ;
F_7 ( 0 , V_36 -> V_11 + V_38 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_35 )
{
struct V_3 * V_36 = F_17 ( V_35 ) ;
void T_1 * V_10 = V_36 -> V_11 ;
T_2 V_12 ;
int V_44 ;
if ( V_36 -> V_23 ) {
V_44 = F_20 ( V_36 -> V_23 ) ;
if ( V_44 )
return V_44 ;
}
V_12 = F_5 ( V_10 + V_45 ) ;
V_12 |= V_46 ;
F_7 ( V_12 , V_10 + V_45 ) ;
V_12 &= ~ V_46 ;
F_7 ( V_12 , V_10 + V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_14 * V_35 )
{
struct V_3 * V_36 = F_17 ( V_35 ) ;
int V_44 = 0 ;
if ( V_36 -> V_23 )
V_44 = F_22 ( V_36 -> V_23 ) ;
return V_44 ;
}
static T_3 F_23 ( int V_47 , void * V_48 )
{
struct V_3 * V_4 = V_48 ;
void T_1 * V_10 = V_4 -> V_11 ;
T_2 V_49 = F_5 ( V_10 + V_30 ) ;
T_3 V_44 = V_50 ;
if ( V_49 & V_29 ) {
F_6 ( & V_4 -> V_14 -> V_15 , L_3 , V_16 , V_49 ) ;
F_7 ( V_29 , V_10 + V_30 ) ;
F_14 ( V_4 ) ;
V_44 = V_51 ;
}
return V_44 ;
}
static int F_24 ( struct V_52 * V_53 )
{
struct V_54 * V_15 = & V_53 -> V_15 ;
struct V_3 * V_36 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_47 ;
if ( ! V_15 -> V_59 ) {
F_25 ( V_15 , L_4 ) ;
return - V_60 ;
}
V_36 = F_26 ( V_15 , sizeof( * V_36 ) , V_61 ) ;
if ( ! V_36 )
return - V_62 ;
V_58 = F_27 ( V_53 , V_63 , 0 ) ;
V_36 -> V_11 = F_28 ( V_15 , V_58 ) ;
if ( F_29 ( V_36 -> V_11 ) )
return F_30 ( V_36 -> V_11 ) ;
V_47 = F_31 ( V_53 , 0 ) ;
if ( V_47 >= 0 ) {
int V_44 ;
F_32 ( & V_36 -> V_2 , F_1 ) ;
V_47 = F_33 ( V_15 , V_47 , F_23 ,
V_64 , F_34 ( V_15 ) , V_36 ) ;
if ( V_47 < 0 )
F_25 ( V_15 , L_5 , V_47 ) ;
V_36 -> V_43 = true ;
V_36 -> V_6 = F_35 ( V_15 ,
V_65 ) ;
if ( F_29 ( V_36 -> V_6 ) )
return F_30 ( V_36 -> V_6 ) ;
V_44 = F_36 ( V_15 , V_36 -> V_6 ) ;
if ( V_44 < 0 ) {
F_25 ( V_15 , L_6 ) ;
return V_44 ;
}
}
V_36 -> V_14 = F_37 ( V_15 , NULL , & V_66 ) ;
if ( F_29 ( V_36 -> V_14 ) ) {
F_25 ( V_15 , L_7 ) ;
return F_30 ( V_36 -> V_14 ) ;
}
V_36 -> V_23 = F_38 ( V_15 , L_8 ) ;
if ( F_29 ( V_36 -> V_23 ) ) {
if ( F_30 ( V_36 -> V_23 ) == - V_67 )
return F_30 ( V_36 -> V_23 ) ;
V_36 -> V_23 = NULL ;
}
F_39 ( V_36 -> V_14 , V_36 ) ;
V_56 = F_40 ( V_15 , V_68 ) ;
if ( F_29 ( V_56 ) )
F_25 ( V_15 , L_9 ) ;
return F_41 ( V_56 ) ;
}
