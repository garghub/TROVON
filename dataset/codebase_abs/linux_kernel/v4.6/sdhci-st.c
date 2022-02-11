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
if ( V_12 -> V_30 & V_31 )
V_15 |= V_32 ;
else
F_2 ( V_33 ,
V_8 -> V_1 + V_34 ) ;
if ( V_12 -> V_30 & V_35 ) {
V_15 |= V_36 ;
V_16 |= V_37 ;
V_17 |= V_38 ;
V_17 |= V_39 ;
}
if ( V_12 -> V_30 & V_40 ) {
V_15 |= V_36 ;
V_16 |= V_41 ;
V_17 |= V_39 ;
}
if ( V_12 -> V_30 & V_42 )
V_16 |= V_43 ;
F_2 ( V_15 , V_8 -> V_1 + V_44 ) ;
F_2 ( V_16 , V_8 -> V_1 + V_45 ) ;
F_2 ( V_17 , V_8 -> V_1 + V_46 ) ;
}
static inline void F_7 ( void T_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( V_47 , V_1 + V_2 ) ;
F_2 ( V_48 ,
V_1 + V_49 ) ;
}
static int F_8 ( void T_1 * V_1 )
{
unsigned long V_50 , V_51 ;
unsigned long V_52 = V_53 + V_54 ;
do {
V_50 = V_53 ;
V_51 = F_9 ( V_1 + V_55 ) ;
if ( V_51 & 0x1 )
return 0 ;
F_10 () ;
} while ( ! F_11 ( V_50 , V_52 ) );
return - V_56 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_57 = 0 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = F_13 ( V_10 ) ;
if ( V_8 -> clock > V_60 ) {
F_7 ( V_59 -> V_61 ) ;
V_57 = F_8 ( V_8 -> V_1 ) ;
}
return V_57 ;
}
static void F_14 ( struct V_7 * V_8 ,
unsigned int V_62 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = F_13 ( V_10 ) ;
T_3 V_63 = F_15 ( V_8 , V_64 ) ;
int V_57 = 0 ;
V_63 &= ~ V_65 ;
switch ( V_62 ) {
case V_66 :
F_1 ( V_59 -> V_61 ) ;
V_63 |= V_67 | V_68 ;
break;
case V_69 :
F_1 ( V_59 -> V_61 ) ;
V_63 |= V_70 | V_68 ;
break;
case V_71 :
F_1 ( V_59 -> V_61 ) ;
V_63 |= V_72 | V_68 ;
V_57 = F_12 ( V_8 ) ;
break;
case V_73 :
case V_74 :
F_1 ( V_59 -> V_61 ) ;
V_63 |= V_75 | V_68 ;
V_57 = F_12 ( V_8 ) ;
break;
case V_76 :
case V_77 :
F_1 ( V_59 -> V_61 ) ;
V_63 |= V_78 | V_68 ;
break;
}
if ( V_57 )
F_16 ( F_17 ( V_8 -> V_13 ) , L_2
L_3 , V_62 ) ;
F_18 ( F_17 ( V_8 -> V_13 ) , L_4 , V_62 , V_63 ) ;
F_19 ( V_8 , V_63 , V_64 ) ;
}
static T_2 F_20 ( struct V_7 * V_8 , int V_79 )
{
T_2 V_57 ;
switch ( V_79 ) {
case V_80 :
V_57 = F_21 ( V_8 -> V_1 + V_79 ) ;
V_57 &= ~ V_81 ;
break;
default:
V_57 = F_21 ( V_8 -> V_1 + V_79 ) ;
}
return V_57 ;
}
static int F_22 ( struct V_82 * V_83 )
{
struct V_5 * V_6 = V_83 -> V_84 . V_85 ;
struct V_7 * V_8 ;
struct V_58 * V_59 ;
struct V_9 * V_10 ;
struct V_25 * V_25 ;
int V_57 = 0 ;
T_3 V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
V_25 = F_23 ( & V_83 -> V_84 , L_5 ) ;
if ( F_24 ( V_25 ) ) {
F_25 ( & V_83 -> V_84 , L_6 ) ;
return F_26 ( V_25 ) ;
}
V_90 = F_27 ( & V_83 -> V_84 , NULL ) ;
if ( F_24 ( V_90 ) )
V_90 = NULL ;
else
F_28 ( V_90 ) ;
V_8 = F_29 ( V_83 , & V_91 , sizeof( * V_59 ) ) ;
if ( F_24 ( V_8 ) ) {
F_25 ( & V_83 -> V_84 , L_7 ) ;
V_57 = F_26 ( V_8 ) ;
goto V_92;
}
V_10 = F_4 ( V_8 ) ;
V_59 = F_13 ( V_10 ) ;
V_59 -> V_90 = V_90 ;
V_57 = F_30 ( V_8 -> V_13 ) ;
if ( V_57 ) {
F_25 ( & V_83 -> V_84 , L_8 ) ;
goto V_93;
}
F_31 ( V_25 ) ;
V_88 = F_32 ( V_83 , V_94 ,
L_9 ) ;
V_59 -> V_61 = F_33 ( & V_83 -> V_84 , V_88 ) ;
if ( F_24 ( V_59 -> V_61 ) ) {
F_16 ( & V_83 -> V_84 , L_10 ) ;
V_59 -> V_61 = NULL ;
}
V_10 -> V_25 = V_25 ;
F_3 ( V_6 , V_8 ) ;
V_57 = F_34 ( V_8 ) ;
if ( V_57 ) {
F_25 ( & V_83 -> V_84 , L_11 ) ;
goto V_95;
}
F_35 ( V_83 , V_8 ) ;
V_86 = F_36 ( ( V_8 -> V_1 + V_96 ) ) ;
F_37 ( & V_83 -> V_84 , L_12 ,
( ( V_86 & V_97 ) >> V_98 ) ,
( ( V_86 & V_99 ) >>
V_100 ) ) ;
return 0 ;
V_95:
F_38 ( V_25 ) ;
V_93:
F_39 ( V_83 ) ;
V_92:
if ( V_90 )
F_40 ( V_90 ) ;
return V_57 ;
}
static int F_41 ( struct V_82 * V_83 )
{
struct V_7 * V_8 = F_42 ( V_83 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = F_13 ( V_10 ) ;
struct V_89 * V_90 = V_59 -> V_90 ;
int V_57 ;
V_57 = F_43 ( V_83 ) ;
if ( V_90 )
F_40 ( V_90 ) ;
return V_57 ;
}
static int F_44 ( struct V_101 * V_84 )
{
struct V_7 * V_8 = F_45 ( V_84 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = F_13 ( V_10 ) ;
int V_57 = F_46 ( V_8 ) ;
if ( V_57 )
goto V_102;
if ( V_59 -> V_90 )
F_40 ( V_59 -> V_90 ) ;
F_38 ( V_10 -> V_25 ) ;
V_102:
return V_57 ;
}
static int F_47 ( struct V_101 * V_84 )
{
struct V_7 * V_8 = F_45 ( V_84 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = F_13 ( V_10 ) ;
struct V_5 * V_6 = V_84 -> V_85 ;
F_31 ( V_10 -> V_25 ) ;
if ( V_59 -> V_90 )
F_28 ( V_59 -> V_90 ) ;
F_3 ( V_6 , V_8 ) ;
return F_48 ( V_8 ) ;
}
