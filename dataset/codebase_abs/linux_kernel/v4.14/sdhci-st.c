static inline void F_1 ( void T_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( 0x0 , V_1 + V_2 ) ;
F_2 ( V_3 ,
V_1 + V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_11 * V_12 = V_8 -> V_13 ;
T_2 V_14 , V_15 , V_16 , V_17 ;
if ( ! F_5 ( V_6 , L_1 ) )
return;
V_14 = V_18 ;
V_15 = V_19 ;
V_16 = V_20 ;
V_17 = V_21 ;
F_2 ( V_22 ,
V_8 -> V_1 + V_23 ) ;
switch ( V_12 -> V_24 ) {
case 200000000 :
F_6 ( V_10 -> V_25 , V_12 -> V_24 ) ;
V_14 |= V_26 ;
break;
case 100000000 :
F_6 ( V_10 -> V_25 , V_12 -> V_24 ) ;
V_14 |= V_27 ;
break;
default:
F_6 ( V_10 -> V_25 , 50000000 ) ;
V_14 |= V_28 ;
}
F_2 ( V_14 , V_8 -> V_1 + V_29 ) ;
if ( ! F_7 ( V_12 ) )
V_15 |= V_30 ;
else
F_2 ( V_31 ,
V_8 -> V_1 + V_32 ) ;
if ( V_12 -> V_33 & V_34 ) {
V_15 |= V_35 ;
V_16 |= V_36 ;
V_17 |= V_37 ;
V_17 |= V_38 ;
}
if ( V_12 -> V_33 & V_39 ) {
V_15 |= V_35 ;
V_16 |= V_40 ;
V_17 |= V_38 ;
}
if ( V_12 -> V_33 & V_41 )
V_16 |= V_42 ;
F_2 ( V_15 , V_8 -> V_1 + V_43 ) ;
F_2 ( V_16 , V_8 -> V_1 + V_44 ) ;
F_2 ( V_17 , V_8 -> V_1 + V_45 ) ;
}
static inline void F_8 ( void T_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( V_46 , V_1 + V_2 ) ;
F_2 ( V_47 ,
V_1 + V_48 ) ;
}
static int F_9 ( void T_1 * V_1 )
{
unsigned long V_49 , V_50 ;
unsigned long V_51 = V_52 + V_53 ;
do {
V_49 = V_52 ;
V_50 = F_10 ( V_1 + V_54 ) ;
if ( V_50 & 0x1 )
return 0 ;
F_11 () ;
} while ( ! F_12 ( V_49 , V_51 ) );
return - V_55 ;
}
static int F_13 ( struct V_7 * V_8 )
{
int V_56 = 0 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_57 * V_58 = F_14 ( V_10 ) ;
if ( V_8 -> clock > V_59 ) {
F_8 ( V_58 -> V_60 ) ;
V_56 = F_9 ( V_8 -> V_1 ) ;
}
return V_56 ;
}
static void F_15 ( struct V_7 * V_8 ,
unsigned int V_61 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_57 * V_58 = F_14 ( V_10 ) ;
T_3 V_62 = F_16 ( V_8 , V_63 ) ;
int V_56 = 0 ;
V_62 &= ~ V_64 ;
switch ( V_61 ) {
case V_65 :
F_1 ( V_58 -> V_60 ) ;
V_62 |= V_66 | V_67 ;
break;
case V_68 :
F_1 ( V_58 -> V_60 ) ;
V_62 |= V_69 | V_67 ;
break;
case V_70 :
F_1 ( V_58 -> V_60 ) ;
V_62 |= V_71 | V_67 ;
V_56 = F_13 ( V_8 ) ;
break;
case V_72 :
case V_73 :
F_1 ( V_58 -> V_60 ) ;
V_62 |= V_74 | V_67 ;
V_56 = F_13 ( V_8 ) ;
break;
case V_75 :
case V_76 :
F_1 ( V_58 -> V_60 ) ;
V_62 |= V_77 | V_67 ;
break;
}
if ( V_56 )
F_17 ( F_18 ( V_8 -> V_13 ) , L_2
L_3 , V_61 ) ;
F_19 ( F_18 ( V_8 -> V_13 ) , L_4 , V_61 , V_62 ) ;
F_20 ( V_8 , V_62 , V_63 ) ;
}
static T_2 F_21 ( struct V_7 * V_8 , int V_78 )
{
T_2 V_56 ;
switch ( V_78 ) {
case V_79 :
V_56 = F_22 ( V_8 -> V_1 + V_78 ) ;
V_56 &= ~ V_80 ;
break;
default:
V_56 = F_22 ( V_8 -> V_1 + V_78 ) ;
}
return V_56 ;
}
static int F_23 ( struct V_81 * V_82 )
{
struct V_5 * V_6 = V_82 -> V_83 . V_84 ;
struct V_7 * V_8 ;
struct V_57 * V_58 ;
struct V_9 * V_10 ;
struct V_25 * V_25 , * V_85 ;
int V_56 = 0 ;
T_3 V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
V_25 = F_24 ( & V_82 -> V_83 , L_5 ) ;
if ( F_25 ( V_25 ) ) {
F_26 ( & V_82 -> V_83 , L_6 ) ;
return F_27 ( V_25 ) ;
}
V_85 = F_24 ( & V_82 -> V_83 , L_7 ) ;
if ( F_25 ( V_85 ) )
V_85 = NULL ;
V_90 = F_28 ( & V_82 -> V_83 , NULL ) ;
if ( F_25 ( V_90 ) )
V_90 = NULL ;
else
F_29 ( V_90 ) ;
V_8 = F_30 ( V_82 , & V_91 , sizeof( * V_58 ) ) ;
if ( F_25 ( V_8 ) ) {
F_26 ( & V_82 -> V_83 , L_8 ) ;
V_56 = F_27 ( V_8 ) ;
goto V_92;
}
V_10 = F_4 ( V_8 ) ;
V_58 = F_14 ( V_10 ) ;
V_58 -> V_90 = V_90 ;
V_56 = F_31 ( V_8 -> V_13 ) ;
if ( V_56 ) {
F_26 ( & V_82 -> V_83 , L_9 ) ;
goto V_93;
}
V_56 = F_32 ( V_25 ) ;
if ( V_56 ) {
F_26 ( & V_82 -> V_83 , L_10 ) ;
goto V_93;
}
V_56 = F_32 ( V_85 ) ;
if ( V_56 ) {
F_26 ( & V_82 -> V_83 , L_11 ) ;
goto V_94;
}
V_88 = F_33 ( V_82 , V_95 ,
L_12 ) ;
V_58 -> V_60 = F_34 ( & V_82 -> V_83 , V_88 ) ;
if ( F_25 ( V_58 -> V_60 ) ) {
F_17 ( & V_82 -> V_83 , L_13 ) ;
V_58 -> V_60 = NULL ;
}
V_10 -> V_25 = V_25 ;
V_58 -> V_85 = V_85 ;
F_3 ( V_6 , V_8 ) ;
V_56 = F_35 ( V_8 ) ;
if ( V_56 ) {
F_26 ( & V_82 -> V_83 , L_14 ) ;
goto V_96;
}
V_86 = F_36 ( ( V_8 -> V_1 + V_97 ) ) ;
F_37 ( & V_82 -> V_83 , L_15 ,
( ( V_86 & V_98 ) >> V_99 ) ,
( ( V_86 & V_100 ) >>
V_101 ) ) ;
return 0 ;
V_96:
F_38 ( V_85 ) ;
V_94:
F_38 ( V_25 ) ;
V_93:
F_39 ( V_82 ) ;
V_92:
if ( V_90 )
F_40 ( V_90 ) ;
return V_56 ;
}
static int F_41 ( struct V_81 * V_82 )
{
struct V_7 * V_8 = F_42 ( V_82 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_57 * V_58 = F_14 ( V_10 ) ;
struct V_89 * V_90 = V_58 -> V_90 ;
int V_56 ;
V_56 = F_43 ( V_82 ) ;
F_38 ( V_58 -> V_85 ) ;
if ( V_90 )
F_40 ( V_90 ) ;
return V_56 ;
}
static int F_44 ( struct V_102 * V_83 )
{
struct V_7 * V_8 = F_45 ( V_83 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_57 * V_58 = F_14 ( V_10 ) ;
int V_56 ;
if ( V_8 -> V_103 != V_104 )
F_46 ( V_8 -> V_13 ) ;
V_56 = F_47 ( V_8 ) ;
if ( V_56 )
goto V_105;
if ( V_58 -> V_90 )
F_40 ( V_58 -> V_90 ) ;
F_38 ( V_58 -> V_85 ) ;
F_38 ( V_10 -> V_25 ) ;
V_105:
return V_56 ;
}
static int F_48 ( struct V_102 * V_83 )
{
struct V_7 * V_8 = F_45 ( V_83 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_57 * V_58 = F_14 ( V_10 ) ;
struct V_5 * V_6 = V_83 -> V_84 ;
int V_56 ;
V_56 = F_32 ( V_10 -> V_25 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_32 ( V_58 -> V_85 ) ;
if ( V_56 ) {
F_38 ( V_10 -> V_25 ) ;
return V_56 ;
}
if ( V_58 -> V_90 )
F_29 ( V_58 -> V_90 ) ;
F_3 ( V_6 , V_8 ) ;
return F_49 ( V_8 ) ;
}
