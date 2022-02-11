static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_6 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_6 |= V_11 | V_12 ;
V_6 |= V_13 | V_14 ;
V_6 &= ~ V_15 ;
F_4 ( V_6 , V_2 -> V_9 + V_10 ) ;
V_3 |= V_16 ;
V_3 |= V_17 ;
F_4 ( V_3 , V_2 -> V_9 + V_18 ) ;
V_4 = F_3 ( V_2 -> V_9 + V_19 ) ;
V_4 |= V_20 ;
F_4 ( V_4 , V_2 -> V_9 + V_19 ) ;
V_7 = F_5
( & V_2 -> V_8 , V_21 ) ;
if ( V_7 == 0 ) {
F_6 ( V_2 -> V_22 , L_1 ) ;
return - V_23 ;
}
V_5 = F_3 ( V_2 -> V_9 + V_24 ) ;
if ( V_5 & V_25 ) {
F_6 ( V_2 -> V_22 , L_2 ) ;
return - V_26 ;
}
V_6 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_6 |= V_15 ;
F_4 ( V_6 , V_2 -> V_9 + V_10 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_27 , V_28 , V_29 , V_30 , V_31 ;
V_27 = V_32 ;
F_4 ( V_27 , V_2 -> V_9 + V_18 ) ;
V_28 = V_32 | V_33 ;
F_4 ( V_28 , V_2 -> V_9 + V_34 ) ;
V_29 = V_32 ;
F_4 ( V_29 , V_2 -> V_9 + V_35 ) ;
V_30 = V_32 | V_36 ;
F_4 ( V_30 , V_2 -> V_9 + V_37 ) ;
V_31 = V_32 ;
F_4 ( V_31 , V_2 -> V_9 + V_38 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_39 = 0 ;
int V_40 ;
V_39 |= V_2 -> V_41 << 8 ;
V_39 |= V_42 | V_43 ;
F_4 ( V_39 , V_2 -> V_44 + V_45 ) ;
F_4 ( V_46 , V_2 -> V_44 + V_47 ) ;
F_4 ( V_2 -> V_48 , V_2 -> V_44 + V_49 ) ;
F_4 ( V_50 , V_2 -> V_44 + V_51 ) ;
F_4 ( V_52 | V_53 ,
V_2 -> V_44 + V_54 ) ;
V_40 = F_3 ( V_2 -> V_44 + V_55 ) ;
V_40 |= V_56 ;
V_40 &= ~ V_57 ;
F_4 ( V_40 , V_2 -> V_44 + V_55 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_1 ( V_2 ) ;
if ( V_58 )
return V_58 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_59 ;
int V_6 ;
V_59 = F_3 ( V_2 -> V_44 + V_55 ) ;
V_59 |= V_57 ;
F_4 ( V_59 , V_2 -> V_44 + V_55 ) ;
V_6 = F_3 ( V_2 -> V_9 + V_18 ) ;
V_6 |= V_17 ;
F_4 ( V_6 , V_2 -> V_9 + V_18 ) ;
}
static bool F_11 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_60 + F_12 ( 2 ) ;
int V_61 ;
int V_62 ;
do {
if ( F_13 ( V_60 , V_7 ) )
return false ;
F_14 ( 200 , 400 ) ;
V_62 = F_3 ( V_2 -> V_44 + V_47 ) ;
V_61 = ( V_62 >> 20 ) & 0x7 ;
} while ( V_61 != V_63 );
F_14 ( 200 , 400 ) ;
return true ;
}
static T_1 F_15 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
int V_66 ;
int V_67 ;
int V_68 , V_69 ;
int V_40 ;
V_66 = F_3 ( V_2 -> V_44 + V_70 ) ;
F_4 ( V_71 | V_72 ,
V_2 -> V_44 + V_70 ) ;
V_40 = F_3 ( V_2 -> V_44 + V_55 ) ;
V_40 |= V_56 ;
F_4 ( V_40 , V_2 -> V_44 + V_55 ) ;
if ( V_66 & V_71 ) {
V_67 = F_3 ( V_2 -> V_44 + V_73 ) ;
V_68 = ( V_67 >> 16 ) & 0x0fff ;
V_69 = V_67 & 0x0fff ;
if ( ! F_11 ( V_2 ) ||
F_16 ( V_2 -> V_74 ) ) {
F_17 ( V_2 -> V_75 , V_76 , 1 ) ;
F_18 ( V_2 -> V_75 , V_77 , V_68 ) ;
F_18 ( V_2 -> V_75 , V_78 , V_69 ) ;
} else {
F_17 ( V_2 -> V_75 , V_76 , 0 ) ;
}
F_19 ( V_2 -> V_75 ) ;
}
return V_79 ;
}
static T_1 F_20 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
int V_80 ;
int V_67 ;
V_80 = F_3 ( V_2 -> V_9 + V_81 ) ;
if ( V_80 & 0x01 ) {
V_67 = F_3 ( V_2 -> V_9 + V_82 ) ;
F_21 ( & V_2 -> V_8 ) ;
}
return V_79 ;
}
static int F_22 ( struct V_83 * V_83 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
int V_58 ;
V_58 = F_24 ( V_2 -> V_84 ) ;
if ( V_58 ) {
F_6 ( V_2 -> V_22 ,
L_3 ,
V_58 ) ;
return V_58 ;
}
V_58 = F_24 ( V_2 -> V_85 ) ;
if ( V_58 ) {
F_6 ( V_2 -> V_22 ,
L_4 ,
V_58 ) ;
F_25 ( V_2 -> V_84 ) ;
return V_58 ;
}
return F_9 ( V_2 ) ;
}
static void F_26 ( struct V_83 * V_83 )
{
struct V_1 * V_2 = F_23 ( V_83 ) ;
F_10 ( V_2 ) ;
F_25 ( V_2 -> V_85 ) ;
F_25 ( V_2 -> V_84 ) ;
}
static int F_27 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_22 . V_90 ;
struct V_1 * V_2 ;
struct V_83 * V_83 ;
struct V_91 * V_92 ;
struct V_91 * V_93 ;
int V_58 ;
int V_94 ;
int V_95 ;
V_2 = F_28 ( & V_87 -> V_22 , sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
V_83 = F_29 ( & V_87 -> V_22 ) ;
if ( ! V_83 )
return - V_97 ;
V_83 -> V_98 = L_5 ;
V_83 -> V_99 . V_100 = V_101 ;
V_83 -> V_102 = F_22 ;
V_83 -> V_103 = F_26 ;
F_30 ( V_83 , V_104 , V_76 ) ;
F_31 ( V_83 , V_77 , 0 , 0xFFF , 0 , 0 ) ;
F_31 ( V_83 , V_78 , 0 , 0xFFF , 0 , 0 ) ;
F_32 ( V_83 , V_2 ) ;
V_2 -> V_22 = & V_87 -> V_22 ;
V_2 -> V_75 = V_83 ;
F_33 ( & V_2 -> V_8 ) ;
V_2 -> V_74 = F_34 ( & V_87 -> V_22 , L_6 , V_105 ) ;
if ( F_35 ( V_2 -> V_74 ) ) {
V_58 = F_36 ( V_2 -> V_74 ) ;
F_6 ( & V_87 -> V_22 ,
L_7 , V_58 ) ;
return V_58 ;
}
V_92 = F_37 ( V_87 , V_106 , 0 ) ;
V_2 -> V_44 = F_38 ( & V_87 -> V_22 , V_92 ) ;
if ( F_35 ( V_2 -> V_44 ) ) {
V_58 = F_36 ( V_2 -> V_44 ) ;
F_6 ( & V_87 -> V_22 , L_8 , V_58 ) ;
return V_58 ;
}
V_93 = F_37 ( V_87 , V_106 , 1 ) ;
V_2 -> V_9 = F_38 ( & V_87 -> V_22 , V_93 ) ;
if ( F_35 ( V_2 -> V_9 ) ) {
V_58 = F_36 ( V_2 -> V_9 ) ;
F_6 ( & V_87 -> V_22 , L_9 , V_58 ) ;
return V_58 ;
}
V_2 -> V_85 = F_39 ( & V_87 -> V_22 , L_10 ) ;
if ( F_35 ( V_2 -> V_85 ) ) {
V_58 = F_36 ( V_2 -> V_85 ) ;
F_6 ( & V_87 -> V_22 , L_11 , V_58 ) ;
return V_58 ;
}
V_2 -> V_84 = F_39 ( & V_87 -> V_22 , L_12 ) ;
if ( F_35 ( V_2 -> V_84 ) ) {
V_58 = F_36 ( V_2 -> V_84 ) ;
F_6 ( & V_87 -> V_22 , L_13 , V_58 ) ;
return V_58 ;
}
V_94 = F_40 ( V_87 , 0 ) ;
if ( V_94 < 0 ) {
F_6 ( & V_87 -> V_22 , L_14 ) ;
return V_94 ;
}
V_95 = F_40 ( V_87 , 1 ) ;
if ( V_95 < 0 ) {
F_6 ( & V_87 -> V_22 , L_15 ) ;
return V_95 ;
}
V_58 = F_41 ( V_2 -> V_22 , V_94 ,
NULL , F_15 , V_107 ,
F_42 ( & V_87 -> V_22 ) , V_2 ) ;
if ( V_58 ) {
F_6 ( & V_87 -> V_22 ,
L_16 ,
V_94 , V_58 ) ;
return V_58 ;
}
V_58 = F_43 ( V_2 -> V_22 , V_95 , F_20 , 0 ,
F_42 ( & V_87 -> V_22 ) , V_2 ) ;
if ( V_58 ) {
F_6 ( & V_87 -> V_22 ,
L_17 ,
V_95 , V_58 ) ;
return V_58 ;
}
V_58 = F_44 ( V_89 , L_18 ,
& V_2 -> V_41 ) ;
if ( V_58 )
V_2 -> V_41 = 0xffff ;
V_58 = F_44 ( V_89 , L_19 ,
& V_2 -> V_48 ) ;
if ( V_58 )
V_2 -> V_48 = 0xfff ;
V_58 = F_45 ( V_2 -> V_75 ) ;
if ( V_58 ) {
F_6 ( & V_87 -> V_22 ,
L_20 , V_58 ) ;
return V_58 ;
}
F_46 ( V_87 , V_2 ) ;
return 0 ;
}
static int T_2 F_47 ( struct V_108 * V_22 )
{
struct V_86 * V_87 = F_48 ( V_22 ) ;
struct V_1 * V_2 = F_49 ( V_87 ) ;
struct V_83 * V_83 = V_2 -> V_75 ;
F_50 ( & V_83 -> V_109 ) ;
if ( V_83 -> V_110 ) {
F_10 ( V_2 ) ;
F_25 ( V_2 -> V_85 ) ;
F_25 ( V_2 -> V_84 ) ;
}
F_51 ( & V_83 -> V_109 ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_108 * V_22 )
{
struct V_86 * V_87 = F_48 ( V_22 ) ;
struct V_1 * V_2 = F_49 ( V_87 ) ;
struct V_83 * V_83 = V_2 -> V_75 ;
int V_111 = 0 ;
F_50 ( & V_83 -> V_109 ) ;
if ( V_83 -> V_110 ) {
V_111 = F_24 ( V_2 -> V_84 ) ;
if ( V_111 )
goto V_112;
V_111 = F_24 ( V_2 -> V_85 ) ;
if ( V_111 ) {
F_25 ( V_2 -> V_84 ) ;
goto V_112;
}
V_111 = F_9 ( V_2 ) ;
}
V_112:
F_51 ( & V_83 -> V_109 ) ;
return V_111 ;
}
