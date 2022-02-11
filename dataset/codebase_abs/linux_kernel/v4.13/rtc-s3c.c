static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 = 0 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
if ( V_2 -> V_6 ) {
V_4 = F_3 ( V_2 -> V_7 ) ;
if ( V_4 )
goto V_8;
if ( V_2 -> V_9 -> V_10 ) {
V_4 = F_3 ( V_2 -> V_11 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_7 ) ;
goto V_8;
}
}
V_2 -> V_6 = false ;
}
V_8:
F_5 ( & V_2 -> V_5 , V_3 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
if ( ! V_2 -> V_6 ) {
if ( V_2 -> V_9 -> V_10 )
F_4 ( V_2 -> V_11 ) ;
F_4 ( V_2 -> V_7 ) ;
V_2 -> V_6 = true ;
}
F_5 ( & V_2 -> V_5 , V_3 ) ;
}
static T_1 F_7 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
if ( V_2 -> V_9 -> V_14 )
V_2 -> V_9 -> V_14 ( V_2 , V_15 ) ;
return V_16 ;
}
static T_1 F_8 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
if ( V_2 -> V_9 -> V_14 )
V_2 -> V_9 -> V_14 ( V_2 , V_17 ) ;
return V_16 ;
}
static int F_9 ( struct V_18 * V_19 , unsigned int V_20 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned int V_21 ;
int V_4 ;
F_11 ( V_2 -> V_19 , L_1 , V_22 , V_20 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_21 = F_12 ( V_2 -> V_23 + V_24 ) & ~ V_25 ;
if ( V_20 )
V_21 |= V_25 ;
F_13 ( V_21 , V_2 -> V_23 + V_24 ) ;
F_6 ( V_2 ) ;
if ( V_20 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
} else {
F_6 ( V_2 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_26 )
{
int V_4 ;
if ( ! F_15 ( V_26 ) )
return - V_27 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_9 -> V_29 )
V_2 -> V_9 -> V_29 ( V_2 , V_26 ) ;
F_17 ( & V_2 -> V_28 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , struct V_30 * V_31 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned int V_32 = 0 ;
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_33:
V_31 -> V_34 = F_12 ( V_2 -> V_23 + V_35 ) ;
V_31 -> V_36 = F_12 ( V_2 -> V_23 + V_37 ) ;
V_31 -> V_38 = F_12 ( V_2 -> V_23 + V_39 ) ;
V_31 -> V_40 = F_12 ( V_2 -> V_23 + V_41 ) ;
V_31 -> V_42 = F_12 ( V_2 -> V_23 + V_43 ) ;
V_31 -> V_44 = F_12 ( V_2 -> V_23 + V_45 ) ;
if ( V_31 -> V_44 == 0 && ! V_32 ) {
V_32 = 1 ;
goto V_33;
}
V_31 -> V_44 = F_19 ( V_31 -> V_44 ) ;
V_31 -> V_34 = F_19 ( V_31 -> V_34 ) ;
V_31 -> V_36 = F_19 ( V_31 -> V_36 ) ;
V_31 -> V_38 = F_19 ( V_31 -> V_38 ) ;
V_31 -> V_40 = F_19 ( V_31 -> V_40 ) ;
V_31 -> V_42 = F_19 ( V_31 -> V_42 ) ;
F_6 ( V_2 ) ;
V_31 -> V_42 += 100 ;
F_11 ( V_19 , L_2 ,
1900 + V_31 -> V_42 , V_31 -> V_40 , V_31 -> V_38 ,
V_31 -> V_36 , V_31 -> V_34 , V_31 -> V_44 ) ;
V_31 -> V_40 -= 1 ;
return F_20 ( V_31 ) ;
}
static int F_21 ( struct V_18 * V_19 , struct V_30 * V_46 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_47 = V_46 -> V_42 - 100 ;
int V_4 ;
F_11 ( V_19 , L_3 ,
1900 + V_46 -> V_42 , V_46 -> V_40 , V_46 -> V_38 ,
V_46 -> V_36 , V_46 -> V_34 , V_46 -> V_44 ) ;
if ( V_47 < 0 || V_47 >= 100 ) {
F_22 ( V_19 , L_4 ) ;
return - V_27 ;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_13 ( F_23 ( V_46 -> V_44 ) , V_2 -> V_23 + V_45 ) ;
F_13 ( F_23 ( V_46 -> V_34 ) , V_2 -> V_23 + V_35 ) ;
F_13 ( F_23 ( V_46 -> V_36 ) , V_2 -> V_23 + V_37 ) ;
F_13 ( F_23 ( V_46 -> V_38 ) , V_2 -> V_23 + V_39 ) ;
F_13 ( F_23 ( V_46 -> V_40 + 1 ) , V_2 -> V_23 + V_41 ) ;
F_13 ( F_23 ( V_47 ) , V_2 -> V_23 + V_43 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 , struct V_48 * V_49 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
struct V_30 * V_50 = & V_49 -> time ;
unsigned int V_51 ;
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_50 -> V_44 = F_12 ( V_2 -> V_23 + V_52 ) ;
V_50 -> V_34 = F_12 ( V_2 -> V_23 + V_53 ) ;
V_50 -> V_36 = F_12 ( V_2 -> V_23 + V_54 ) ;
V_50 -> V_40 = F_12 ( V_2 -> V_23 + V_55 ) ;
V_50 -> V_38 = F_12 ( V_2 -> V_23 + V_56 ) ;
V_50 -> V_42 = F_12 ( V_2 -> V_23 + V_57 ) ;
V_51 = F_12 ( V_2 -> V_23 + V_24 ) ;
F_6 ( V_2 ) ;
V_49 -> V_20 = ( V_51 & V_25 ) ? 1 : 0 ;
F_11 ( V_19 , L_5 ,
V_51 ,
1900 + V_50 -> V_42 , V_50 -> V_40 , V_50 -> V_38 ,
V_50 -> V_36 , V_50 -> V_34 , V_50 -> V_44 ) ;
if ( V_51 & V_58 )
V_50 -> V_44 = F_19 ( V_50 -> V_44 ) ;
if ( V_51 & V_59 )
V_50 -> V_34 = F_19 ( V_50 -> V_34 ) ;
if ( V_51 & V_60 )
V_50 -> V_36 = F_19 ( V_50 -> V_36 ) ;
if ( V_51 & V_61 )
V_50 -> V_38 = F_19 ( V_50 -> V_38 ) ;
if ( V_51 & V_62 ) {
V_50 -> V_40 = F_19 ( V_50 -> V_40 ) ;
V_50 -> V_40 -= 1 ;
}
if ( V_51 & V_63 )
V_50 -> V_42 = F_19 ( V_50 -> V_42 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , struct V_48 * V_49 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
struct V_30 * V_46 = & V_49 -> time ;
unsigned int V_64 ;
int V_4 ;
int V_47 = V_46 -> V_42 - 100 ;
F_11 ( V_19 , L_6 ,
V_49 -> V_20 ,
1900 + V_46 -> V_42 , V_46 -> V_40 + 1 , V_46 -> V_38 ,
V_46 -> V_36 , V_46 -> V_34 , V_46 -> V_44 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_64 = F_12 ( V_2 -> V_23 + V_24 ) & V_25 ;
F_13 ( 0x00 , V_2 -> V_23 + V_24 ) ;
if ( V_46 -> V_44 < 60 && V_46 -> V_44 >= 0 ) {
V_64 |= V_58 ;
F_13 ( F_23 ( V_46 -> V_44 ) , V_2 -> V_23 + V_52 ) ;
}
if ( V_46 -> V_34 < 60 && V_46 -> V_34 >= 0 ) {
V_64 |= V_59 ;
F_13 ( F_23 ( V_46 -> V_34 ) , V_2 -> V_23 + V_53 ) ;
}
if ( V_46 -> V_36 < 24 && V_46 -> V_36 >= 0 ) {
V_64 |= V_60 ;
F_13 ( F_23 ( V_46 -> V_36 ) , V_2 -> V_23 + V_54 ) ;
}
if ( V_47 < 100 && V_47 >= 0 ) {
V_64 |= V_63 ;
F_13 ( F_23 ( V_47 ) , V_2 -> V_23 + V_57 ) ;
}
if ( V_46 -> V_40 < 12 && V_46 -> V_40 >= 0 ) {
V_64 |= V_62 ;
F_13 ( F_23 ( V_46 -> V_40 + 1 ) , V_2 -> V_23 + V_55 ) ;
}
if ( V_46 -> V_38 <= 31 && V_46 -> V_38 >= 1 ) {
V_64 |= V_61 ;
F_13 ( F_23 ( V_46 -> V_38 ) , V_2 -> V_23 + V_56 ) ;
}
F_11 ( V_19 , L_7 , V_64 ) ;
F_13 ( V_64 , V_2 -> V_23 + V_24 ) ;
F_6 ( V_2 ) ;
F_9 ( V_19 , V_49 -> V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , struct V_65 * V_66 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_9 -> V_67 )
V_2 -> V_9 -> V_67 ( V_2 , V_66 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned int V_68 , V_21 ;
V_68 = F_28 ( V_2 -> V_23 + V_69 ) ;
if ( ( V_68 & V_70 ) == 0 ) {
F_29 ( V_2 -> V_19 , L_8 ) ;
V_21 = F_28 ( V_2 -> V_23 + V_69 ) ;
F_30 ( V_21 | V_70 , V_2 -> V_23 + V_69 ) ;
}
if ( V_68 & V_71 ) {
F_29 ( V_2 -> V_19 , L_9 ) ;
V_21 = F_28 ( V_2 -> V_23 + V_69 ) ;
F_30 ( V_21 & ~ V_71 ,
V_2 -> V_23 + V_69 ) ;
}
if ( V_68 & V_72 ) {
F_29 ( V_2 -> V_19 , L_10 ) ;
V_21 = F_28 ( V_2 -> V_23 + V_69 ) ;
F_30 ( V_21 & ~ V_72 ,
V_2 -> V_23 + V_69 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_68 ;
V_68 = F_28 ( V_2 -> V_23 + V_69 ) ;
V_68 &= ~ V_70 ;
F_30 ( V_68 , V_2 -> V_23 + V_69 ) ;
V_68 = F_12 ( V_2 -> V_23 + V_73 ) ;
V_68 &= ~ V_74 ;
F_13 ( V_68 , V_2 -> V_23 + V_73 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned int V_68 ;
V_68 = F_28 ( V_2 -> V_23 + V_69 ) ;
V_68 &= ~ V_75 ;
V_68 &= ~ V_70 ;
F_30 ( V_68 , V_2 -> V_23 + V_69 ) ;
}
static int F_33 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_34 ( V_77 ) ;
F_9 ( V_2 -> V_19 , 0 ) ;
if ( V_2 -> V_9 -> V_10 )
F_35 ( V_2 -> V_11 ) ;
F_35 ( V_2 -> V_7 ) ;
return 0 ;
}
static const struct V_78 * F_36 ( struct V_76 * V_77 )
{
const struct V_79 * V_80 ;
V_80 = F_37 ( V_81 , V_77 -> V_19 . V_82 ) ;
return V_80 -> V_9 ;
}
static int F_38 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = NULL ;
struct V_30 V_31 ;
struct V_83 * V_84 ;
int V_4 ;
V_2 = F_39 ( & V_77 -> V_19 , sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
V_2 -> V_87 = F_40 ( V_77 , 1 ) ;
if ( V_2 -> V_87 < 0 ) {
F_22 ( & V_77 -> V_19 , L_11 ) ;
return V_2 -> V_87 ;
}
V_2 -> V_19 = & V_77 -> V_19 ;
V_2 -> V_9 = F_36 ( V_77 ) ;
if ( ! V_2 -> V_9 ) {
F_22 ( & V_77 -> V_19 , L_12 ) ;
return - V_27 ;
}
F_41 ( & V_2 -> V_28 ) ;
F_41 ( & V_2 -> V_5 ) ;
F_42 ( V_77 , V_2 ) ;
V_2 -> V_88 = F_40 ( V_77 , 0 ) ;
if ( V_2 -> V_88 < 0 ) {
F_22 ( & V_77 -> V_19 , L_13 ) ;
return V_2 -> V_88 ;
}
F_11 ( & V_77 -> V_19 , L_14 ,
V_2 -> V_87 , V_2 -> V_88 ) ;
V_84 = F_43 ( V_77 , V_89 , 0 ) ;
V_2 -> V_23 = F_44 ( & V_77 -> V_19 , V_84 ) ;
if ( F_45 ( V_2 -> V_23 ) )
return F_46 ( V_2 -> V_23 ) ;
V_2 -> V_7 = F_47 ( & V_77 -> V_19 , L_15 ) ;
if ( F_45 ( V_2 -> V_7 ) ) {
V_4 = F_46 ( V_2 -> V_7 ) ;
if ( V_4 != - V_90 )
F_22 ( & V_77 -> V_19 , L_16 ) ;
else
F_11 ( & V_77 -> V_19 , L_17 ) ;
return V_4 ;
}
V_4 = F_48 ( V_2 -> V_7 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_9 -> V_10 ) {
V_2 -> V_11 = F_47 ( & V_77 -> V_19 , L_18 ) ;
if ( F_45 ( V_2 -> V_11 ) ) {
V_4 = F_46 ( V_2 -> V_11 ) ;
if ( V_4 != - V_90 )
F_22 ( & V_77 -> V_19 ,
L_19 ) ;
else
F_11 ( & V_77 -> V_19 ,
L_20 ) ;
goto V_91;
}
V_4 = F_48 ( V_2 -> V_11 ) ;
if ( V_4 )
goto V_91;
}
if ( V_2 -> V_9 -> V_92 )
V_2 -> V_9 -> V_92 ( V_2 ) ;
F_11 ( & V_77 -> V_19 , L_21 ,
F_28 ( V_2 -> V_23 + V_69 ) ) ;
F_49 ( & V_77 -> V_19 , 1 ) ;
if ( F_18 ( & V_77 -> V_19 , & V_31 ) ) {
V_31 . V_42 = 100 ;
V_31 . V_40 = 0 ;
V_31 . V_38 = 1 ;
V_31 . V_36 = 0 ;
V_31 . V_34 = 0 ;
V_31 . V_44 = 0 ;
F_21 ( & V_77 -> V_19 , & V_31 ) ;
F_50 ( & V_77 -> V_19 , L_22 ) ;
}
V_2 -> V_93 = F_51 ( & V_77 -> V_19 , L_23 , & V_94 ,
V_95 ) ;
if ( F_45 ( V_2 -> V_93 ) ) {
F_22 ( & V_77 -> V_19 , L_24 ) ;
V_4 = F_46 ( V_2 -> V_93 ) ;
goto V_96;
}
V_4 = F_52 ( & V_77 -> V_19 , V_2 -> V_88 , F_8 ,
0 , L_25 , V_2 ) ;
if ( V_4 ) {
F_22 ( & V_77 -> V_19 , L_26 , V_2 -> V_88 , V_4 ) ;
goto V_96;
}
V_4 = F_52 ( & V_77 -> V_19 , V_2 -> V_87 , F_7 ,
0 , L_27 , V_2 ) ;
if ( V_4 ) {
F_22 ( & V_77 -> V_19 , L_26 , V_2 -> V_87 , V_4 ) ;
goto V_96;
}
if ( V_2 -> V_9 -> V_97 )
V_2 -> V_9 -> V_97 ( V_2 ) ;
F_14 ( V_2 , 1 ) ;
return 0 ;
V_96:
if ( V_2 -> V_9 -> V_98 )
V_2 -> V_9 -> V_98 ( V_2 ) ;
if ( V_2 -> V_9 -> V_10 )
F_53 ( V_2 -> V_11 ) ;
V_91:
F_53 ( V_2 -> V_7 ) ;
return V_4 ;
}
static int F_54 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_9 -> V_99 )
V_2 -> V_9 -> V_99 ( V_2 ) ;
if ( V_2 -> V_9 -> V_98 )
V_2 -> V_9 -> V_98 ( V_2 ) ;
if ( F_55 ( V_19 ) && ! V_2 -> V_100 ) {
if ( F_56 ( V_2 -> V_88 ) == 0 )
V_2 -> V_100 = true ;
else
F_22 ( V_19 , L_28 ) ;
}
return 0 ;
}
static int F_57 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( V_2 -> V_9 -> V_92 )
V_2 -> V_9 -> V_92 ( V_2 ) ;
if ( V_2 -> V_9 -> V_101 )
V_2 -> V_9 -> V_101 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( F_55 ( V_19 ) && V_2 -> V_100 ) {
F_58 ( V_2 -> V_88 ) ;
V_2 -> V_100 = false ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , int V_102 )
{
F_60 ( V_2 -> V_93 , 1 , V_103 | V_104 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_102 )
{
F_60 ( V_2 -> V_93 , 1 , V_103 | V_104 ) ;
F_13 ( V_102 , V_2 -> V_23 + V_105 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_26 )
{
unsigned int V_21 = 0 ;
int V_106 ;
V_21 = F_12 ( V_2 -> V_23 + V_73 ) ;
V_21 &= V_74 ;
V_106 = ( V_2 -> V_93 -> V_107 / V_26 ) - 1 ;
V_21 |= V_106 ;
F_63 ( V_21 , V_2 -> V_23 + V_73 ) ;
}
static void F_64 ( struct V_1 * V_2 , int V_26 )
{
unsigned int V_21 = 0 ;
int V_106 ;
V_21 = F_12 ( V_2 -> V_23 + V_73 ) ;
V_21 &= V_74 ;
V_106 = ( V_2 -> V_93 -> V_107 / V_26 ) - 1 ;
V_21 |= F_65 ( V_106 ) ;
F_63 ( F_66 ( V_106 ) , V_2 -> V_23 + V_108 ) ;
F_63 ( F_67 ( V_106 ) , V_2 -> V_23 + V_109 ) ;
F_63 ( V_21 , V_2 -> V_23 + V_73 ) ;
}
static void F_68 ( struct V_1 * V_2 , int V_26 )
{
unsigned int V_21 = 0 ;
int V_106 ;
V_21 = F_12 ( V_2 -> V_23 + V_73 ) ;
V_21 &= V_74 ;
V_106 = ( V_2 -> V_93 -> V_107 / V_26 ) - 1 ;
V_21 |= F_65 ( V_106 ) ;
F_63 ( F_66 ( V_106 ) , V_2 -> V_23 + V_108 ) ;
F_63 ( V_21 , V_2 -> V_23 + V_73 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_26 )
{
int V_106 ;
V_106 = ( V_2 -> V_93 -> V_107 / V_26 ) - 1 ;
F_63 ( V_106 , V_2 -> V_23 + V_73 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
unsigned int V_110 ;
V_110 = F_12 ( V_2 -> V_23 + V_73 ) ;
V_110 &= V_74 ;
F_71 ( V_66 , L_29 , V_110 ? L_30 : L_31 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned int V_68 ;
V_68 = F_28 ( V_2 -> V_23 + V_69 ) ;
V_68 |= V_111 ;
F_30 ( V_68 , V_2 -> V_23 + V_69 ) ;
}
static void F_73 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
unsigned int V_110 ;
V_110 = F_28 ( V_2 -> V_23 + V_69 ) ;
V_110 &= V_75 ;
F_71 ( V_66 , L_29 , V_110 ? L_30 : L_31 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
V_2 -> V_112 = F_12 ( V_2 -> V_23 + V_73 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_112 , V_2 -> V_23 + V_73 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_2 -> V_113 = F_28 ( V_2 -> V_23 + V_69 ) ;
V_2 -> V_113 &= V_75 ;
V_2 -> V_112 = F_77 ( V_2 -> V_23 + V_73 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
unsigned int V_68 ;
F_63 ( V_2 -> V_112 , V_2 -> V_23 + V_73 ) ;
if ( V_2 -> V_113 ) {
V_68 = F_28 ( V_2 -> V_23 + V_69 ) ;
F_30 ( V_68 | V_2 -> V_113 , V_2 -> V_23 + V_69 ) ;
}
}
