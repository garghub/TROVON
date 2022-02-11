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
struct V_58 * V_59 = V_10 -> V_60 ;
if ( V_8 -> clock > V_61 ) {
F_7 ( V_59 -> V_62 ) ;
V_57 = F_8 ( V_8 -> V_1 ) ;
}
return V_57 ;
}
static void F_13 ( struct V_7 * V_8 ,
unsigned int V_63 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = V_10 -> V_60 ;
T_3 V_64 = F_14 ( V_8 , V_65 ) ;
int V_57 = 0 ;
V_64 &= ~ V_66 ;
switch ( V_63 ) {
case V_67 :
F_1 ( V_59 -> V_62 ) ;
V_64 |= V_68 | V_69 ;
break;
case V_70 :
F_1 ( V_59 -> V_62 ) ;
V_64 |= V_71 | V_69 ;
break;
case V_72 :
F_1 ( V_59 -> V_62 ) ;
V_64 |= V_73 | V_69 ;
V_57 = F_12 ( V_8 ) ;
break;
case V_74 :
case V_75 :
F_1 ( V_59 -> V_62 ) ;
V_64 |= V_76 | V_69 ;
V_57 = F_12 ( V_8 ) ;
break;
case V_77 :
case V_78 :
F_1 ( V_59 -> V_62 ) ;
V_64 |= V_79 | V_69 ;
break;
}
if ( V_57 )
F_15 ( F_16 ( V_8 -> V_13 ) , L_2
L_3 , V_63 ) ;
F_17 ( F_16 ( V_8 -> V_13 ) , L_4 , V_63 , V_64 ) ;
F_18 ( V_8 , V_64 , V_65 ) ;
}
static T_2 F_19 ( struct V_7 * V_8 , int V_80 )
{
T_2 V_57 ;
switch ( V_80 ) {
case V_81 :
V_57 = F_20 ( V_8 -> V_1 + V_80 ) ;
V_57 &= ~ V_82 ;
break;
default:
V_57 = F_20 ( V_8 -> V_1 + V_80 ) ;
}
return V_57 ;
}
static int F_21 ( struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_85 . V_86 ;
struct V_7 * V_8 ;
struct V_58 * V_59 ;
struct V_9 * V_10 ;
struct V_25 * V_25 ;
int V_57 = 0 ;
T_3 V_87 ;
struct V_88 * V_89 ;
V_59 = F_22 ( & V_84 -> V_85 , sizeof( * V_59 ) , V_90 ) ;
if ( ! V_59 )
return - V_91 ;
V_25 = F_23 ( & V_84 -> V_85 , L_5 ) ;
if ( F_24 ( V_25 ) ) {
F_25 ( & V_84 -> V_85 , L_6 ) ;
return F_26 ( V_25 ) ;
}
V_59 -> V_92 = F_27 ( & V_84 -> V_85 , NULL ) ;
if ( F_24 ( V_59 -> V_92 ) )
V_59 -> V_92 = NULL ;
else
F_28 ( V_59 -> V_92 ) ;
V_8 = F_29 ( V_84 , & V_93 , 0 ) ;
if ( F_24 ( V_8 ) ) {
F_25 ( & V_84 -> V_85 , L_7 ) ;
V_57 = F_26 ( V_8 ) ;
goto V_94;
}
V_57 = F_30 ( V_8 -> V_13 ) ;
if ( V_57 ) {
F_25 ( & V_84 -> V_85 , L_8 ) ;
goto V_95;
}
F_31 ( V_25 ) ;
V_89 = F_32 ( V_84 , V_96 ,
L_9 ) ;
V_59 -> V_62 = F_33 ( & V_84 -> V_85 , V_89 ) ;
if ( F_24 ( V_59 -> V_62 ) ) {
F_15 ( & V_84 -> V_85 , L_10 ) ;
V_59 -> V_62 = NULL ;
}
V_10 = F_4 ( V_8 ) ;
V_10 -> V_60 = V_59 ;
V_10 -> V_25 = V_25 ;
F_3 ( V_6 , V_8 ) ;
V_57 = F_34 ( V_8 ) ;
if ( V_57 ) {
F_25 ( & V_84 -> V_85 , L_11 ) ;
goto V_97;
}
F_35 ( V_84 , V_8 ) ;
V_87 = F_36 ( ( V_8 -> V_1 + V_98 ) ) ;
F_37 ( & V_84 -> V_85 , L_12 ,
( ( V_87 & V_99 ) >> V_100 ) ,
( ( V_87 & V_101 ) >>
V_102 ) ) ;
return 0 ;
V_97:
F_38 ( V_25 ) ;
V_95:
F_39 ( V_84 ) ;
V_94:
if ( V_59 -> V_92 )
F_40 ( V_59 -> V_92 ) ;
return V_57 ;
}
static int F_41 ( struct V_83 * V_84 )
{
struct V_7 * V_8 = F_42 ( V_84 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = V_10 -> V_60 ;
int V_57 ;
V_57 = F_43 ( V_84 ) ;
if ( V_59 -> V_92 )
F_40 ( V_59 -> V_92 ) ;
return V_57 ;
}
static int F_44 ( struct V_103 * V_85 )
{
struct V_7 * V_8 = F_45 ( V_85 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = V_10 -> V_60 ;
int V_57 = F_46 ( V_8 ) ;
if ( V_57 )
goto V_104;
if ( V_59 -> V_92 )
F_40 ( V_59 -> V_92 ) ;
F_38 ( V_10 -> V_25 ) ;
V_104:
return V_57 ;
}
static int F_47 ( struct V_103 * V_85 )
{
struct V_7 * V_8 = F_45 ( V_85 ) ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
struct V_58 * V_59 = V_10 -> V_60 ;
struct V_5 * V_6 = V_85 -> V_86 ;
F_31 ( V_10 -> V_25 ) ;
if ( V_59 -> V_92 )
F_28 ( V_59 -> V_92 ) ;
F_3 ( V_6 , V_8 ) ;
return F_48 ( V_8 ) ;
}
