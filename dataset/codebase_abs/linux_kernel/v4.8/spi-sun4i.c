static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_3 , V_7 ;
T_2 V_8 ;
V_3 = F_1 ( V_2 , V_9 ) ;
V_3 &= V_10 ;
V_7 = V_3 >> V_11 ;
if ( V_6 > V_7 )
V_6 = V_7 ;
while ( V_6 -- ) {
V_8 = F_6 ( V_2 -> V_4 + V_12 ) ;
if ( V_2 -> V_13 )
* V_2 -> V_13 ++ = V_8 ;
}
}
static inline void F_7 ( struct V_1 * V_2 , int V_6 )
{
T_2 V_8 ;
if ( V_6 > V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
while ( V_6 -- ) {
V_8 = V_2 -> V_14 ? * V_2 -> V_14 ++ : 0 ;
F_8 ( V_8 , V_2 -> V_4 + V_15 ) ;
V_2 -> V_6 -- ;
}
}
static void F_9 ( struct V_16 * V_17 , bool V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 -> V_19 ) ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_20 ) ;
V_3 &= ~ V_21 ;
V_3 |= F_11 ( V_17 -> V_22 ) ;
V_3 |= V_23 ;
if ( V_18 )
V_3 |= V_24 ;
else
V_3 &= ~ V_24 ;
if ( V_17 -> V_25 & V_26 )
V_3 &= ~ V_27 ;
else
V_3 |= V_27 ;
F_3 ( V_2 , V_20 , V_3 ) ;
}
static T_3 F_12 ( struct V_16 * V_17 )
{
return V_28 - 1 ;
}
static int F_13 ( struct V_29 * V_19 ,
struct V_16 * V_17 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned int V_32 , div , V_33 ;
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 = 0 ;
int V_38 = 0 ;
T_1 V_3 ;
if ( V_31 -> V_6 > V_28 )
return - V_39 ;
if ( V_31 -> V_14 && V_31 -> V_6 >= V_28 )
return - V_39 ;
F_14 ( & V_2 -> V_40 ) ;
V_2 -> V_14 = V_31 -> V_14 ;
V_2 -> V_13 = V_31 -> V_13 ;
V_2 -> V_6 = V_31 -> V_6 ;
F_3 ( V_2 , V_41 , ~ 0 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_20 ,
V_3 | V_42 | V_43 ) ;
if ( V_17 -> V_25 & V_44 )
V_3 |= V_45 ;
else
V_3 &= ~ V_45 ;
if ( V_17 -> V_25 & V_46 )
V_3 |= V_47 ;
else
V_3 &= ~ V_47 ;
if ( V_17 -> V_25 & V_48 )
V_3 |= V_49 ;
else
V_3 &= ~ V_49 ;
if ( V_2 -> V_13 )
V_3 &= ~ V_50 ;
else
V_3 |= V_50 ;
F_3 ( V_2 , V_20 , V_3 ) ;
V_32 = F_15 ( V_2 -> V_51 ) ;
if ( V_32 < ( 2 * V_31 -> V_52 ) ) {
F_16 ( V_2 -> V_51 , 2 * V_31 -> V_52 ) ;
V_32 = F_15 ( V_2 -> V_51 ) ;
}
div = V_32 / ( 2 * V_31 -> V_52 ) ;
if ( div <= ( V_53 + 1 ) ) {
if ( div > 0 )
div -- ;
V_3 = F_17 ( div ) | V_54 ;
} else {
div = F_18 ( V_32 ) - F_18 ( V_31 -> V_52 ) ;
V_3 = F_19 ( div ) ;
}
F_3 ( V_2 , V_55 , V_3 ) ;
if ( V_2 -> V_14 )
V_37 = V_31 -> V_6 ;
F_3 ( V_2 , V_56 , F_20 ( V_31 -> V_6 ) ) ;
F_3 ( V_2 , V_57 , F_21 ( V_37 ) ) ;
F_7 ( V_2 , V_28 - 1 ) ;
F_3 ( V_2 , V_58 , V_59 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_20 , V_3 | V_60 ) ;
V_36 = F_22 ( V_31 -> V_6 * 8 * 2 / ( V_31 -> V_52 / 1000 ) , 100U ) ;
V_34 = V_61 ;
V_33 = F_23 ( & V_2 -> V_40 ,
F_24 ( V_36 ) ) ;
V_35 = V_61 ;
if ( ! V_33 ) {
F_25 ( & V_19 -> V_62 ,
L_1 ,
F_26 ( & V_17 -> V_62 ) , V_31 -> V_6 , V_31 -> V_52 ,
F_27 ( V_35 - V_34 ) , V_36 ) ;
V_38 = - V_63 ;
goto V_64;
}
F_5 ( V_2 , V_28 ) ;
V_64:
F_3 ( V_2 , V_58 , 0 ) ;
return V_38 ;
}
static T_4 F_28 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
T_1 V_67 = F_1 ( V_2 , V_41 ) ;
if ( V_67 & V_59 ) {
F_3 ( V_2 , V_41 , V_59 ) ;
F_29 ( & V_2 -> V_40 ) ;
return V_68 ;
}
return V_69 ;
}
static int F_30 ( struct V_70 * V_62 )
{
struct V_29 * V_19 = F_31 ( V_62 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_38 ;
V_38 = F_32 ( V_2 -> V_71 ) ;
if ( V_38 ) {
F_33 ( V_62 , L_2 ) ;
goto V_64;
}
V_38 = F_32 ( V_2 -> V_51 ) ;
if ( V_38 ) {
F_33 ( V_62 , L_3 ) ;
goto V_72;
}
F_3 ( V_2 , V_20 ,
V_73 | V_74 | V_75 ) ;
return 0 ;
V_72:
F_34 ( V_2 -> V_71 ) ;
V_64:
return V_38 ;
}
static int F_35 ( struct V_70 * V_62 )
{
struct V_29 * V_19 = F_31 ( V_62 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_34 ( V_2 -> V_51 ) ;
F_34 ( V_2 -> V_71 ) ;
return 0 ;
}
static int F_36 ( struct V_76 * V_77 )
{
struct V_29 * V_19 ;
struct V_1 * V_2 ;
struct V_78 * V_79 ;
int V_38 = 0 , V_65 ;
V_19 = F_37 ( & V_77 -> V_62 , sizeof( struct V_1 ) ) ;
if ( ! V_19 ) {
F_33 ( & V_77 -> V_62 , L_4 ) ;
return - V_80 ;
}
F_38 ( V_77 , V_19 ) ;
V_2 = F_10 ( V_19 ) ;
V_79 = F_39 ( V_77 , V_81 , 0 ) ;
V_2 -> V_4 = F_40 ( & V_77 -> V_62 , V_79 ) ;
if ( F_41 ( V_2 -> V_4 ) ) {
V_38 = F_42 ( V_2 -> V_4 ) ;
goto V_82;
}
V_65 = F_43 ( V_77 , 0 ) ;
if ( V_65 < 0 ) {
F_33 ( & V_77 -> V_62 , L_5 ) ;
V_38 = - V_83 ;
goto V_82;
}
V_38 = F_44 ( & V_77 -> V_62 , V_65 , F_28 ,
0 , L_6 , V_2 ) ;
if ( V_38 ) {
F_33 ( & V_77 -> V_62 , L_7 ) ;
goto V_82;
}
V_2 -> V_19 = V_19 ;
V_19 -> V_84 = 100 * 1000 * 1000 ;
V_19 -> V_85 = 3 * 1000 ;
V_19 -> V_86 = F_9 ;
V_19 -> V_87 = F_13 ;
V_19 -> V_88 = 4 ;
V_19 -> V_89 = V_44 | V_46 | V_26 | V_48 ;
V_19 -> V_90 = F_45 ( 8 ) ;
V_19 -> V_62 . V_91 = V_77 -> V_62 . V_91 ;
V_19 -> V_92 = true ;
V_19 -> V_93 = F_12 ;
V_2 -> V_71 = F_46 ( & V_77 -> V_62 , L_8 ) ;
if ( F_41 ( V_2 -> V_71 ) ) {
F_33 ( & V_77 -> V_62 , L_9 ) ;
V_38 = F_42 ( V_2 -> V_71 ) ;
goto V_82;
}
V_2 -> V_51 = F_46 ( & V_77 -> V_62 , L_10 ) ;
if ( F_41 ( V_2 -> V_51 ) ) {
F_33 ( & V_77 -> V_62 , L_11 ) ;
V_38 = F_42 ( V_2 -> V_51 ) ;
goto V_82;
}
F_47 ( & V_2 -> V_40 ) ;
V_38 = F_30 ( & V_77 -> V_62 ) ;
if ( V_38 ) {
F_33 ( & V_77 -> V_62 , L_12 ) ;
goto V_82;
}
F_48 ( & V_77 -> V_62 ) ;
F_49 ( & V_77 -> V_62 ) ;
F_50 ( & V_77 -> V_62 ) ;
V_38 = F_51 ( & V_77 -> V_62 , V_19 ) ;
if ( V_38 ) {
F_33 ( & V_77 -> V_62 , L_13 ) ;
goto V_94;
}
return 0 ;
V_94:
F_52 ( & V_77 -> V_62 ) ;
F_35 ( & V_77 -> V_62 ) ;
V_82:
F_53 ( V_19 ) ;
return V_38 ;
}
static int F_54 ( struct V_76 * V_77 )
{
F_52 ( & V_77 -> V_62 ) ;
return 0 ;
}
