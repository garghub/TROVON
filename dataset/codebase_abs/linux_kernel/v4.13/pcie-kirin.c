static inline void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 -> V_4 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_4 ( V_1 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 -> V_5 + V_3 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_4 ( V_1 -> V_5 + V_3 ) ;
}
static long F_7 ( struct V_1 * V_1 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
V_1 -> V_10 = F_8 ( V_9 , L_1 ) ;
if ( F_9 ( V_1 -> V_10 ) )
return F_10 ( V_1 -> V_10 ) ;
V_1 -> V_11 = F_8 ( V_9 , L_2 ) ;
if ( F_9 ( V_1 -> V_11 ) )
return F_10 ( V_1 -> V_11 ) ;
V_1 -> V_12 = F_8 ( V_9 , L_3 ) ;
if ( F_9 ( V_1 -> V_12 ) )
return F_10 ( V_1 -> V_12 ) ;
V_1 -> V_13 = F_8 ( V_9 , L_4 ) ;
if ( F_9 ( V_1 -> V_13 ) )
return F_10 ( V_1 -> V_13 ) ;
V_1 -> V_14 = F_8 ( V_9 , L_5 ) ;
if ( F_9 ( V_1 -> V_14 ) )
return F_10 ( V_1 -> V_14 ) ;
return 0 ;
}
static long F_11 ( struct V_1 * V_1 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_15 * V_16 ;
struct V_15 * V_17 ;
struct V_15 * V_18 ;
V_16 = F_12 ( V_7 , V_19 , L_6 ) ;
V_1 -> V_4 = F_13 ( V_9 , V_16 ) ;
if ( F_9 ( V_1 -> V_4 ) )
return F_10 ( V_1 -> V_4 ) ;
V_17 = F_12 ( V_7 , V_19 , L_7 ) ;
V_1 -> V_5 = F_13 ( V_9 , V_17 ) ;
if ( F_9 ( V_1 -> V_5 ) )
return F_10 ( V_1 -> V_5 ) ;
V_18 = F_12 ( V_7 , V_19 , L_8 ) ;
V_1 -> V_20 -> V_21 = F_13 ( V_9 , V_18 ) ;
if ( F_9 ( V_1 -> V_20 -> V_21 ) )
return F_10 ( V_1 -> V_20 -> V_21 ) ;
V_1 -> V_22 =
F_14 ( L_9 ) ;
if ( F_9 ( V_1 -> V_22 ) )
return F_10 ( V_1 -> V_22 ) ;
V_1 -> V_23 =
F_14 ( L_10 ) ;
if ( F_9 ( V_1 -> V_23 ) )
return F_10 ( V_1 -> V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_20 -> V_9 ;
T_1 V_24 ;
V_24 = F_6 ( V_1 , V_25 ) ;
V_24 &= ~ V_26 ;
F_5 ( V_1 , V_24 , V_25 ) ;
V_24 = F_6 ( V_1 , V_27 ) ;
V_24 &= ~ V_28 ;
F_5 ( V_1 , V_24 , V_27 ) ;
F_16 ( V_29 , V_30 ) ;
V_24 = F_6 ( V_1 , V_25 ) ;
V_24 &= ~ V_31 ;
F_5 ( V_1 , V_24 , V_25 ) ;
F_16 ( V_32 , V_33 ) ;
V_24 = F_6 ( V_1 , V_34 ) ;
if ( V_24 & V_35 ) {
F_17 ( V_9 , L_11 ) ;
return - V_36 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 V_2 ;
F_19 ( V_1 -> V_23 , V_37 , & V_2 ) ;
V_2 |= V_38 ;
V_2 &= ~ V_39 ;
F_20 ( V_1 -> V_23 , V_37 , V_2 ) ;
}
static int F_21 ( struct V_1 * V_1 , bool V_40 )
{
int V_41 = 0 ;
if ( ! V_40 )
goto V_42;
V_41 = F_22 ( V_1 -> V_10 , V_43 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_23 ( V_1 -> V_10 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_23 ( V_1 -> V_13 ) ;
if ( V_41 )
goto V_44;
V_41 = F_23 ( V_1 -> V_12 ) ;
if ( V_41 )
goto V_45;
V_41 = F_23 ( V_1 -> V_14 ) ;
if ( V_41 )
goto V_46;
V_41 = F_23 ( V_1 -> V_11 ) ;
if ( V_41 )
goto V_47;
return 0 ;
V_42:
F_24 ( V_1 -> V_11 ) ;
V_47:
F_24 ( V_1 -> V_14 ) ;
V_46:
F_24 ( V_1 -> V_12 ) ;
V_45:
F_24 ( V_1 -> V_13 ) ;
V_44:
F_24 ( V_1 -> V_10 ) ;
return V_41 ;
}
static int F_25 ( struct V_1 * V_1 )
{
int V_41 ;
F_20 ( V_1 -> V_23 ,
V_48 , V_49 ) ;
F_16 ( V_50 , V_51 ) ;
F_18 ( V_1 ) ;
V_41 = F_21 ( V_1 , true ) ;
if ( V_41 )
return V_41 ;
F_20 ( V_1 -> V_23 ,
V_52 , V_53 ) ;
F_20 ( V_1 -> V_22 ,
V_54 , V_55 ) ;
F_20 ( V_1 -> V_23 ,
V_56 , V_57 ) ;
V_41 = F_15 ( V_1 ) ;
if ( V_41 )
goto V_42;
if ( ! F_26 ( V_1 -> V_58 , L_12 ) ) {
F_16 ( V_59 , V_60 ) ;
V_41 = F_27 ( V_1 -> V_58 , 1 ) ;
if ( V_41 )
goto V_42;
F_16 ( V_61 , V_62 ) ;
return 0 ;
}
V_42:
F_21 ( V_1 , false ) ;
return V_41 ;
}
static void F_28 ( struct V_1 * V_1 ,
bool V_63 )
{
T_1 V_2 ;
V_2 = F_3 ( V_1 , V_64 ) ;
if ( V_63 )
V_2 = V_2 | V_65 ;
else
V_2 = V_2 & ~ V_65 ;
F_1 ( V_1 , V_2 , V_64 ) ;
}
static void F_29 ( struct V_1 * V_1 ,
bool V_63 )
{
T_1 V_2 ;
V_2 = F_3 ( V_1 , V_66 ) ;
if ( V_63 )
V_2 = V_2 | V_65 ;
else
V_2 = V_2 & ~ V_65 ;
F_1 ( V_1 , V_2 , V_66 ) ;
}
static int F_30 ( struct V_67 * V_68 ,
int V_69 , int V_70 , T_1 * V_2 )
{
struct V_71 * V_20 = F_31 ( V_68 ) ;
struct V_1 * V_1 = F_32 ( V_20 ) ;
int V_41 ;
F_29 ( V_1 , true ) ;
V_41 = F_33 ( V_20 -> V_21 + V_69 , V_70 , V_2 ) ;
F_29 ( V_1 , false ) ;
return V_41 ;
}
static int F_34 ( struct V_67 * V_68 ,
int V_69 , int V_70 , T_1 V_2 )
{
struct V_71 * V_20 = F_31 ( V_68 ) ;
struct V_1 * V_1 = F_32 ( V_20 ) ;
int V_41 ;
F_28 ( V_1 , true ) ;
V_41 = F_35 ( V_20 -> V_21 + V_69 , V_70 , V_2 ) ;
F_28 ( V_1 , false ) ;
return V_41 ;
}
static T_1 F_36 ( struct V_71 * V_20 , void T_2 * V_72 ,
T_1 V_3 , T_3 V_70 )
{
struct V_1 * V_1 = F_32 ( V_20 ) ;
T_1 V_41 ;
F_29 ( V_1 , true ) ;
F_33 ( V_72 + V_3 , V_70 , & V_41 ) ;
F_29 ( V_1 , false ) ;
return V_41 ;
}
static void F_37 ( struct V_71 * V_20 , void T_2 * V_72 ,
T_1 V_3 , T_3 V_70 , T_1 V_2 )
{
struct V_1 * V_1 = F_32 ( V_20 ) ;
F_28 ( V_1 , true ) ;
F_35 ( V_72 + V_3 , V_70 , V_2 ) ;
F_28 ( V_1 , false ) ;
}
static int F_38 ( struct V_71 * V_20 )
{
struct V_1 * V_1 = F_32 ( V_20 ) ;
T_1 V_2 = F_3 ( V_1 , V_34 ) ;
if ( ( V_2 & V_73 ) == V_73 )
return 1 ;
return 0 ;
}
static int F_39 ( struct V_67 * V_68 )
{
struct V_71 * V_20 = F_31 ( V_68 ) ;
struct V_1 * V_1 = F_32 ( V_20 ) ;
struct V_8 * V_9 = V_1 -> V_20 -> V_9 ;
int V_74 = 0 ;
if ( F_38 ( V_20 ) )
return 0 ;
F_40 ( V_68 ) ;
F_1 ( V_1 , V_75 ,
V_76 ) ;
while ( ! F_38 ( V_20 ) ) {
F_16 ( V_77 , V_78 ) ;
V_74 ++ ;
if ( V_74 == 1000 ) {
F_17 ( V_9 , L_13 ) ;
return - V_36 ;
}
}
return 0 ;
}
static void F_41 ( struct V_67 * V_68 )
{
F_39 ( V_68 ) ;
}
static int T_4 F_42 ( struct V_71 * V_20 ,
struct V_6 * V_7 )
{
V_20 -> V_68 . V_79 = & V_80 ;
return F_43 ( & V_20 -> V_68 ) ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_1 * V_1 ;
struct V_71 * V_20 ;
int V_41 ;
if ( ! V_9 -> V_81 ) {
F_17 ( V_9 , L_14 ) ;
return - V_36 ;
}
V_1 = F_45 ( V_9 , sizeof( struct V_1 ) , V_82 ) ;
if ( ! V_1 )
return - V_83 ;
V_20 = F_45 ( V_9 , sizeof( * V_20 ) , V_82 ) ;
if ( ! V_20 )
return - V_83 ;
V_20 -> V_9 = V_9 ;
V_20 -> V_79 = & V_84 ;
V_1 -> V_20 = V_20 ;
V_41 = F_7 ( V_1 , V_7 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_11 ( V_1 , V_7 ) ;
if ( V_41 )
return V_41 ;
V_1 -> V_58 = F_46 ( V_9 -> V_81 ,
L_15 , 0 ) ;
if ( V_1 -> V_58 < 0 )
return - V_85 ;
V_41 = F_25 ( V_1 ) ;
if ( V_41 )
return V_41 ;
F_47 ( V_7 , V_1 ) ;
return F_42 ( V_20 , V_7 ) ;
}
